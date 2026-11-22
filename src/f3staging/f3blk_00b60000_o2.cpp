// src/f3staging/f3blk_00b60000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b72650 (community match, verified in this file)
struct StateGroup {
    void FUN_008905a0(unsigned state, unsigned value, bool enabled);
};
extern StateGroup* __cdecl FUN_00890750();
struct TextureStage {
    unsigned unk00, unk04;
    void* texture;
    unsigned textureEnabled;
    unsigned unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c;
    unsigned references;
    void FUN_0088fe30();
    __forceinline void release() { if (--references == 0) FUN_0088fe30(); }
    void FUN_0088f050(bool);
    void FUN_0088f0b0(bool);
};
struct StageArray {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    TextureStage* last;
};
struct RenderPass {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned stageCount;
    unsigned unk1c, unk20;
    StageArray* stages;
    unsigned unk28, unk2c;
    StateGroup* stateGroup;
    unsigned unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c, unk60;
    unsigned references;
    void FUN_00888c10();
    __forceinline void addRef() { ++references; }
    __forceinline void release() { if (--references == 0) FUN_00888c10(); }
    void FUN_00888d30(unsigned, TextureStage*);
    void FUN_008866f0(void*);
    void FUN_00886650(void*);
    __forceinline void setState(unsigned state, unsigned value, bool enabled) {
        if (!stateGroup) stateGroup = FUN_00890750();
        stateGroup->FUN_008905a0(state, value, enabled);
    }
    __forceinline void setFloatState(unsigned state, float value, bool enabled) {
        union { float f; unsigned u; } bits;
        bits.f = value;
        setState(state, bits.u, enabled);
    }
};
struct PassOwner {
    RenderPass* p;
    PassOwner():p(0) {}
    ~PassOwner() { if (p) p->release(); }
    __forceinline void assign(const PassOwner& q) {
        if (p != q.p) {
            if (p) p->release();
            p = q.p;
            if (p) p->addRef();
        }
    }
    __declspec(noinline) PassOwner& FUN_00888ea0(const PassOwner&);
};
struct StageOwner {
    TextureStage* p;
    StageOwner():p(0) {}
    ~StageOwner() { if (p) p->release(); }
};
extern void __cdecl FUN_0088ff50(StageOwner&);
extern void __cdecl FUN_00b62c70(TextureStage*,unsigned,unsigned,unsigned,bool);
extern void* DAT_0116f324;
extern unsigned DAT_0116efa0, DAT_0116f27c;
extern float DAT_011761d8;
struct ShaderPair { void* shader; void* alternate; };
extern ShaderPair DAT_01173ae8[];

PassOwner& PassOwner::FUN_00888ea0(const PassOwner& q) { assign(q); return *this; }

extern PassOwner DAT_01173fcc;
extern void* DAT_01173c0c;
extern void* DAT_011738cc;
extern unsigned DAT_01172c54;
extern unsigned DAT_01172074;
extern unsigned DAT_01171494;
extern unsigned DAT_011708b4;
extern PassOwner DAT_01173fd0;
extern void* DAT_011738d0;
extern unsigned DAT_01172c58;
extern unsigned DAT_01172078;
extern unsigned DAT_01171498;
extern unsigned DAT_011708b8;
extern PassOwner DAT_01173fd4;
extern void* DAT_011738d4;
extern unsigned DAT_01172c5c;
extern unsigned DAT_0117207c;
extern unsigned DAT_0117149c;
extern unsigned DAT_011708bc;
extern PassOwner DAT_01173fe4;
extern void* DAT_01173c10;
extern unsigned DAT_01172c6c;
extern unsigned DAT_0117208c;
extern unsigned DAT_011714ac;
extern unsigned DAT_011708cc;
extern PassOwner DAT_01173fe8;
extern unsigned DAT_01172c70;
extern unsigned DAT_01172090;
extern unsigned DAT_011714b0;
extern unsigned DAT_011708d0;
extern PassOwner DAT_01173fec;
extern unsigned DAT_01172c74;
extern unsigned DAT_01172094;
extern unsigned DAT_011714b4;
extern unsigned DAT_011708d4;
extern PassOwner DAT_01173ff8;
extern void* DAT_01173c14;
extern void* DAT_011738d8;
extern unsigned DAT_01172c80;
extern unsigned DAT_011720a0;
extern unsigned DAT_011714c0;
extern unsigned DAT_011708e0;
extern PassOwner DAT_01173ffc;
extern void* DAT_011738dc;
extern unsigned DAT_01172c84;
extern unsigned DAT_011720a4;
extern unsigned DAT_011714c4;
extern unsigned DAT_011708e4;
extern PassOwner DAT_01174000;
extern void* DAT_011738e0;
extern unsigned DAT_01172c88;
extern unsigned DAT_011720a8;
extern unsigned DAT_011714c8;
extern unsigned DAT_011708e8;
extern PassOwner DAT_01174010;
extern void* DAT_01173c18;
extern unsigned DAT_01172c98;
extern unsigned DAT_011720b8;
extern unsigned DAT_011714d8;
extern unsigned DAT_011708f8;
extern PassOwner DAT_01174014;
extern unsigned DAT_01172c9c;
extern unsigned DAT_011720bc;
extern unsigned DAT_011714dc;
extern unsigned DAT_011708fc;
extern PassOwner DAT_01174018;
extern unsigned DAT_01172ca0;
extern unsigned DAT_011720c0;
extern unsigned DAT_011714e0;
extern unsigned DAT_01170900;
extern PassOwner DAT_01174024;
extern void* DAT_01173c1c;
extern void* DAT_011738e4;
extern unsigned DAT_01172cac;
extern unsigned DAT_011720cc;
extern unsigned DAT_011714ec;
extern unsigned DAT_0117090c;
extern PassOwner DAT_01174028;
extern void* DAT_011738e8;
extern unsigned DAT_01172cb0;
extern unsigned DAT_011720d0;
extern unsigned DAT_011714f0;
extern unsigned DAT_01170910;
extern PassOwner DAT_0117402c;
extern void* DAT_011738ec;
extern unsigned DAT_01172cb4;
extern unsigned DAT_011720d4;
extern unsigned DAT_011714f4;
extern unsigned DAT_01170914;
extern PassOwner DAT_0117403c;
extern void* DAT_01173c20;
extern unsigned DAT_01172cc4;
extern unsigned DAT_011720e4;
extern unsigned DAT_01171504;
extern unsigned DAT_01170924;
extern PassOwner DAT_01174040;
extern unsigned DAT_01172cc8;
extern unsigned DAT_011720e8;
extern unsigned DAT_01171508;
extern unsigned DAT_01170928;
extern PassOwner DAT_01174044;
extern unsigned DAT_01172ccc;
extern unsigned DAT_011720ec;
extern unsigned DAT_0117150c;
extern unsigned DAT_0117092c;
extern PassOwner DAT_01174050;
extern void* DAT_01173c24;
extern void* DAT_011738f0;
extern unsigned DAT_01172cd8;
extern unsigned DAT_011720f8;
extern unsigned DAT_01171518;
extern unsigned DAT_01170938;
extern PassOwner DAT_01174054;
extern void* DAT_011738f4;
extern unsigned DAT_01172cdc;
extern unsigned DAT_011720fc;
extern unsigned DAT_0117151c;
extern unsigned DAT_0117093c;
extern PassOwner DAT_01174058;
extern void* DAT_011738f8;
extern unsigned DAT_01172ce0;
extern unsigned DAT_01172100;
extern unsigned DAT_01171520;
extern unsigned DAT_01170940;
extern PassOwner DAT_01174068;
extern void* DAT_01173c28;
extern unsigned DAT_01172cf0;
extern unsigned DAT_01172110;
extern unsigned DAT_01171530;
extern unsigned DAT_01170950;
extern PassOwner DAT_0117406c;
extern unsigned DAT_01172cf4;
extern unsigned DAT_01172114;
extern unsigned DAT_01171534;
extern unsigned DAT_01170954;
extern PassOwner DAT_01174070;
extern unsigned DAT_01172cf8;
extern unsigned DAT_01172118;
extern unsigned DAT_01171538;
extern unsigned DAT_01170958;
extern PassOwner DAT_01174084;
extern void* DAT_01173c2c;
extern void* DAT_011738fc;
extern unsigned DAT_01172d0c;
extern unsigned DAT_0117212c;
extern unsigned DAT_0117154c;
extern unsigned DAT_0117096c;
extern PassOwner DAT_01174088;
extern void* DAT_01173900;
extern unsigned DAT_01172d10;
extern unsigned DAT_01172130;
extern unsigned DAT_01171550;
extern unsigned DAT_01170970;
extern PassOwner DAT_01174090;
extern void* DAT_01173c30;
extern unsigned DAT_01172d18;
extern unsigned DAT_01172138;
extern unsigned DAT_01171558;
extern unsigned DAT_01170978;
extern PassOwner DAT_01174094;
extern unsigned DAT_01172d1c;
extern unsigned DAT_0117213c;
extern unsigned DAT_0117155c;
extern unsigned DAT_0117097c;
extern PassOwner DAT_0117409c;
extern void* DAT_01173c34;
extern void* DAT_01173904;
extern unsigned DAT_01172d24;
extern unsigned DAT_01172144;
extern unsigned DAT_01171564;
extern unsigned DAT_01170984;
extern PassOwner DAT_011740a0;
extern void* DAT_01173c38;
extern void* DAT_01173908;
extern unsigned DAT_01172d28;
extern unsigned DAT_01172148;
extern unsigned DAT_01171568;
extern unsigned DAT_01170988;
extern PassOwner DAT_011740a4;
extern void* DAT_0117390c;
extern unsigned DAT_01172d2c;
extern unsigned DAT_0117214c;
extern unsigned DAT_0117156c;
extern unsigned DAT_0117098c;
extern PassOwner DAT_011740ac;
extern void* DAT_01173c3c;
extern unsigned DAT_01172d34;
extern unsigned DAT_01172154;
extern unsigned DAT_01171574;
extern unsigned DAT_01170994;
extern PassOwner DAT_011740b0;
extern unsigned DAT_01172d38;
extern unsigned DAT_01172158;
extern unsigned DAT_01171578;
extern unsigned DAT_01170998;
extern PassOwner DAT_011740b8;
extern void* DAT_01173c40;
extern void* DAT_01173910;
extern unsigned DAT_01172d40;
extern unsigned DAT_01172160;
extern unsigned DAT_01171580;
extern unsigned DAT_011709a0;
extern PassOwner DAT_011740bc;
extern void* DAT_01173c44;
extern void* DAT_01173914;
extern unsigned DAT_01172d44;
extern unsigned DAT_01172164;
extern unsigned DAT_01171584;
extern unsigned DAT_011709a4;
extern PassOwner DAT_011740c0;
extern void* DAT_01173918;
extern unsigned DAT_01172d48;
extern unsigned DAT_01172168;
extern unsigned DAT_01171588;
extern unsigned DAT_011709a8;
extern PassOwner DAT_011740c8;
extern void* DAT_01173c48;
extern unsigned DAT_01172d50;
extern unsigned DAT_01172170;
extern unsigned DAT_01171590;
extern unsigned DAT_011709b0;
extern PassOwner DAT_011740cc;
extern unsigned DAT_01172d54;
extern unsigned DAT_01172174;
extern unsigned DAT_01171594;
extern unsigned DAT_011709b4;
extern PassOwner DAT_0117463c;
extern void* DAT_01173d40;
extern unsigned DAT_011732c4;
extern unsigned DAT_011726e4;
extern unsigned DAT_01171b04;
extern PassOwner DAT_01174640;
extern void* DAT_01173d44;
extern unsigned DAT_011732c8;
extern unsigned DAT_011726e8;
extern unsigned DAT_01171b08;
extern PassOwner DAT_01174644;
extern void* DAT_01173d48;
extern unsigned DAT_011732cc;
extern unsigned DAT_011726ec;
extern unsigned DAT_01171b0c;


// pdb: ShadowLightShader::PresetADTSPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void __cdecl FUN_00b72650() {
    PassOwner pass;
    StageOwner stage;
    // Pass configuration 0
    pass.assign(DAT_01173fcc);
    RenderPass* current0 = pass.p;
    unsigned initialCount = current0->stageCount;
    if (initialCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current0->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current0->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current0->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current0->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current0->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current0->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current0->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current0->FUN_00888d30(7, stage.p);
    }
    current0->FUN_008866f0(DAT_01173c0c);
    current0->FUN_00886650(DAT_011738cc);
    current0->setState(27, 0, true);
    current0->setState(15, 0, true);
    current0->setState(7, 1, true);
    current0->setState(23, 4, true);
    current0->setState(14, 1, true);
    DAT_01172c54 = 0x780;
    DAT_01172074 = 0x2c;
    DAT_01171494 = 0x300;
    DAT_011708b4 = 0x8;
    // Pass configuration 1
    pass.assign(DAT_01173fd0);
    RenderPass* current1 = pass.p;
    if (current1->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current1->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current1->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current1->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current1->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current1->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current1->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current1->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current1->FUN_00888d30(7, stage.p);
    }
    current1->FUN_008866f0(DAT_01173c0c);
    current1->FUN_00886650(DAT_011738d0);
    current1->setState(27, 0, true);
    current1->setState(15, 0, true);
    current1->setState(7, 1, true);
    current1->setState(23, 4, true);
    current1->setState(14, 1, true);
    DAT_01172c58 = 0x780;
    DAT_01172078 = 0x3c;
    DAT_01171498 = 0x300;
    DAT_011708b8 = 0xc;
    // Pass configuration 2
    pass.assign(DAT_01173fd4);
    RenderPass* current2 = pass.p;
    if (current2->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current2->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current2->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current2->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current2->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current2->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current2->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current2->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current2->FUN_00888d30(7, stage.p);
    }
    current2->FUN_008866f0(DAT_01173c0c);
    current2->FUN_00886650(DAT_011738d4);
    current2->setState(27, 0, true);
    current2->setState(15, 0, true);
    current2->setState(7, 1, true);
    current2->setState(23, 4, true);
    current2->setState(14, 1, true);
    DAT_01172c5c = 0x780;
    DAT_0117207c = 0x3c;
    DAT_0117149c = 0x300;
    DAT_011708bc = 0xc;
    // Pass configuration 3
    pass.assign(DAT_01173fe4);
    RenderPass* current3 = pass.p;
    if (current3->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current3->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current3->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current3->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current3->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current3->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current3->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current3->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current3->FUN_00888d30(7, stage.p);
    }
    current3->FUN_008866f0(DAT_01173c10);
    current3->FUN_00886650(DAT_011738cc);
    current3->setState(27, 0, true);
    current3->setState(15, 0, true);
    current3->setState(7, 1, true);
    current3->setState(23, 4, true);
    current3->setState(14, 1, true);
    DAT_01172c6c = 0xf80;
    DAT_0117208c = 0x2c;
    DAT_011714ac = 0x300;
    DAT_011708cc = 0x8;
    // Pass configuration 4
    pass.assign(DAT_01173fe8);
    RenderPass* current4 = pass.p;
    if (current4->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current4->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current4->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current4->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current4->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current4->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current4->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current4->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current4->FUN_00888d30(7, stage.p);
    }
    current4->FUN_008866f0(DAT_01173c10);
    current4->FUN_00886650(DAT_011738d0);
    current4->setState(27, 0, true);
    current4->setState(15, 0, true);
    current4->setState(7, 1, true);
    current4->setState(23, 4, true);
    current4->setState(14, 1, true);
    DAT_01172c70 = 0xf80;
    DAT_01172090 = 0x3c;
    DAT_011714b0 = 0x300;
    DAT_011708d0 = 0xc;
    // Pass configuration 5
    pass.assign(DAT_01173fec);
    RenderPass* current5 = pass.p;
    if (current5->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current5->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current5->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current5->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current5->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current5->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current5->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current5->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current5->FUN_00888d30(7, stage.p);
    }
    current5->FUN_008866f0(DAT_01173c10);
    current5->FUN_00886650(DAT_011738d4);
    current5->setState(27, 0, true);
    current5->setState(15, 0, true);
    current5->setState(7, 1, true);
    current5->setState(23, 4, true);
    current5->setState(14, 1, true);
    DAT_01172c74 = 0xf80;
    DAT_01172094 = 0x3c;
    DAT_011714b4 = 0x300;
    DAT_011708d4 = 0xc;
    // Pass configuration 6
    pass.assign(DAT_01173ff8);
    RenderPass* current6 = pass.p;
    if (current6->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current6->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current6->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current6->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current6->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current6->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current6->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current6->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current6->FUN_00888d30(7, stage.p);
    }
    current6->FUN_008866f0(DAT_01173c14);
    current6->FUN_00886650(DAT_011738d8);
    current6->setState(27, 0, true);
    current6->setState(15, 0, true);
    current6->setState(7, 1, true);
    current6->setState(23, 4, true);
    current6->setState(14, 1, true);
    DAT_01172c80 = 0x7f0;
    DAT_011720a0 = 0x2c;
    DAT_011714c0 = 0x360;
    DAT_011708e0 = 0x8;
    // Pass configuration 7
    pass.assign(DAT_01173ffc);
    RenderPass* current7 = pass.p;
    if (current7->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current7->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current7->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current7->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current7->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current7->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current7->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current7->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current7->FUN_00888d30(7, stage.p);
    }
    current7->FUN_008866f0(DAT_01173c14);
    current7->FUN_00886650(DAT_011738dc);
    current7->setState(27, 0, true);
    current7->setState(15, 0, true);
    current7->setState(7, 1, true);
    current7->setState(23, 4, true);
    current7->setState(14, 1, true);
    DAT_01172c84 = 0x7f0;
    DAT_011720a4 = 0x3c;
    DAT_011714c4 = 0x360;
    DAT_011708e4 = 0xc;
    // Pass configuration 8
    pass.assign(DAT_01174000);
    RenderPass* current8 = pass.p;
    if (current8->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current8->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current8->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current8->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current8->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current8->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current8->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current8->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current8->FUN_00888d30(7, stage.p);
    }
    current8->FUN_008866f0(DAT_01173c14);
    current8->FUN_00886650(DAT_011738e0);
    current8->setState(27, 0, true);
    current8->setState(15, 0, true);
    current8->setState(7, 1, true);
    current8->setState(23, 4, true);
    current8->setState(14, 1, true);
    DAT_01172c88 = 0x7f0;
    DAT_011720a8 = 0x3c;
    DAT_011714c8 = 0x360;
    DAT_011708e8 = 0xc;
    // Pass configuration 9
    pass.assign(DAT_01174010);
    RenderPass* current9 = pass.p;
    if (current9->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current9->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current9->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current9->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current9->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current9->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current9->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current9->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current9->FUN_00888d30(7, stage.p);
    }
    current9->FUN_008866f0(DAT_01173c18);
    current9->FUN_00886650(DAT_011738d8);
    current9->setState(27, 0, true);
    current9->setState(15, 0, true);
    current9->setState(7, 1, true);
    current9->setState(23, 4, true);
    current9->setState(14, 1, true);
    DAT_01172c98 = 0xff0;
    DAT_011720b8 = 0x2c;
    DAT_011714d8 = 0x360;
    DAT_011708f8 = 0x8;
    // Pass configuration 10
    pass.assign(DAT_01174014);
    RenderPass* current10 = pass.p;
    if (current10->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current10->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current10->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current10->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current10->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current10->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current10->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current10->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current10->FUN_00888d30(7, stage.p);
    }
    current10->FUN_008866f0(DAT_01173c18);
    current10->FUN_00886650(DAT_011738dc);
    current10->setState(27, 0, true);
    current10->setState(15, 0, true);
    current10->setState(7, 1, true);
    current10->setState(23, 4, true);
    current10->setState(14, 1, true);
    DAT_01172c9c = 0xff0;
    DAT_011720bc = 0x3c;
    DAT_011714dc = 0x360;
    DAT_011708fc = 0xc;
    // Pass configuration 11
    pass.assign(DAT_01174018);
    RenderPass* current11 = pass.p;
    if (current11->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current11->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current11->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current11->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current11->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current11->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current11->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current11->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current11->FUN_00888d30(7, stage.p);
    }
    current11->FUN_008866f0(DAT_01173c18);
    current11->FUN_00886650(DAT_011738e0);
    current11->setState(27, 0, true);
    current11->setState(15, 0, true);
    current11->setState(7, 1, true);
    current11->setState(23, 4, true);
    current11->setState(14, 1, true);
    DAT_01172ca0 = 0xff0;
    DAT_011720c0 = 0x3c;
    DAT_011714e0 = 0x360;
    DAT_01170900 = 0xc;
    // Pass configuration 12
    pass.assign(DAT_01174024);
    RenderPass* current12 = pass.p;
    if (current12->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current12->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current12->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current12->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current12->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current12->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current12->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current12->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current12->FUN_00888d30(7, stage.p);
    }
    current12->FUN_008866f0(DAT_01173c1c);
    current12->FUN_00886650(DAT_011738e4);
    current12->setState(27, 0, true);
    current12->setState(15, 0, true);
    current12->setState(7, 1, true);
    current12->setState(23, 4, true);
    current12->setState(14, 1, true);
    DAT_01172cac = 0x780;
    DAT_011720cc = 0x2c;
    DAT_011714ec = 0x300;
    DAT_0117090c = 0x0;
    // Pass configuration 13
    pass.assign(DAT_01174028);
    RenderPass* current13 = pass.p;
    if (current13->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current13->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current13->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current13->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current13->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current13->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current13->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current13->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current13->FUN_00888d30(7, stage.p);
    }
    current13->FUN_008866f0(DAT_01173c1c);
    current13->FUN_00886650(DAT_011738e8);
    current13->setState(27, 0, true);
    current13->setState(15, 0, true);
    current13->setState(7, 1, true);
    current13->setState(23, 4, true);
    current13->setState(14, 1, true);
    DAT_01172cb0 = 0x780;
    DAT_011720d0 = 0x3c;
    DAT_011714f0 = 0x300;
    DAT_01170910 = 0x4;
    // Pass configuration 14
    pass.assign(DAT_0117402c);
    RenderPass* current14 = pass.p;
    if (current14->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current14->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current14->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current14->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current14->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current14->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current14->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current14->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current14->FUN_00888d30(7, stage.p);
    }
    current14->FUN_008866f0(DAT_01173c1c);
    current14->FUN_00886650(DAT_011738ec);
    current14->setState(27, 0, true);
    current14->setState(15, 0, true);
    current14->setState(7, 1, true);
    current14->setState(23, 4, true);
    current14->setState(14, 1, true);
    DAT_01172cb4 = 0x780;
    DAT_011720d4 = 0x3c;
    DAT_011714f4 = 0x300;
    DAT_01170914 = 0x4;
    // Pass configuration 15
    pass.assign(DAT_0117403c);
    RenderPass* current15 = pass.p;
    if (current15->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current15->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current15->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current15->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current15->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current15->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current15->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current15->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current15->FUN_00888d30(7, stage.p);
    }
    current15->FUN_008866f0(DAT_01173c20);
    current15->FUN_00886650(DAT_011738e4);
    current15->setState(27, 0, true);
    current15->setState(15, 0, true);
    current15->setState(7, 1, true);
    current15->setState(23, 4, true);
    current15->setState(14, 1, true);
    DAT_01172cc4 = 0xf80;
    DAT_011720e4 = 0x2c;
    DAT_01171504 = 0x300;
    DAT_01170924 = 0x0;
    // Pass configuration 16
    pass.assign(DAT_01174040);
    RenderPass* current16 = pass.p;
    if (current16->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current16->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current16->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current16->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current16->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current16->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current16->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current16->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current16->FUN_00888d30(7, stage.p);
    }
    current16->FUN_008866f0(DAT_01173c20);
    current16->FUN_00886650(DAT_011738e8);
    current16->setState(27, 0, true);
    current16->setState(15, 0, true);
    current16->setState(7, 1, true);
    current16->setState(23, 4, true);
    current16->setState(14, 1, true);
    DAT_01172cc8 = 0xf80;
    DAT_011720e8 = 0x3c;
    DAT_01171508 = 0x300;
    DAT_01170928 = 0x4;
    // Pass configuration 17
    pass.assign(DAT_01174044);
    RenderPass* current17 = pass.p;
    if (current17->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current17->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current17->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current17->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current17->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current17->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current17->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current17->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current17->FUN_00888d30(7, stage.p);
    }
    current17->FUN_008866f0(DAT_01173c20);
    current17->FUN_00886650(DAT_011738ec);
    current17->setState(27, 0, true);
    current17->setState(15, 0, true);
    current17->setState(7, 1, true);
    current17->setState(23, 4, true);
    current17->setState(14, 1, true);
    DAT_01172ccc = 0xf80;
    DAT_011720ec = 0x3c;
    DAT_0117150c = 0x300;
    DAT_0117092c = 0x4;
    // Pass configuration 18
    pass.assign(DAT_01174050);
    RenderPass* current18 = pass.p;
    if (current18->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current18->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current18->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current18->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current18->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current18->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current18->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current18->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current18->FUN_00888d30(7, stage.p);
    }
    current18->FUN_008866f0(DAT_01173c24);
    current18->FUN_00886650(DAT_011738f0);
    current18->setState(27, 0, true);
    current18->setState(15, 0, true);
    current18->setState(7, 1, true);
    current18->setState(23, 4, true);
    current18->setState(14, 1, true);
    DAT_01172cd8 = 0x7f0;
    DAT_011720f8 = 0x2c;
    DAT_01171518 = 0x360;
    DAT_01170938 = 0x8;
    // Pass configuration 19
    pass.FUN_00888ea0(DAT_01174054);
    RenderPass* current19 = pass.p;
    if (current19->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current19->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current19->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current19->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current19->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current19->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current19->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current19->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current19->FUN_00888d30(7, stage.p);
    }
    current19->FUN_008866f0(DAT_01173c24);
    current19->FUN_00886650(DAT_011738f4);
    current19->setState(27, 0, true);
    current19->setState(15, 0, true);
    current19->setState(7, 1, true);
    current19->setState(23, 4, true);
    current19->setState(14, 1, true);
    DAT_01172cdc = 0x7f0;
    DAT_011720fc = 0x3c;
    DAT_0117151c = 0x360;
    DAT_0117093c = 0xc;
    // Pass configuration 20
    pass.FUN_00888ea0(DAT_01174058);
    RenderPass* current20 = pass.p;
    if (current20->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current20->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current20->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current20->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current20->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current20->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current20->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current20->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current20->FUN_00888d30(7, stage.p);
    }
    current20->FUN_008866f0(DAT_01173c24);
    current20->FUN_00886650(DAT_011738f8);
    current20->setState(27, 0, true);
    current20->setState(15, 0, true);
    current20->setState(7, 1, true);
    current20->setState(23, 4, true);
    current20->setState(14, 1, true);
    DAT_01172ce0 = 0x7f0;
    DAT_01172100 = 0x3c;
    DAT_01171520 = 0x360;
    DAT_01170940 = 0xc;
    // Pass configuration 21
    pass.FUN_00888ea0(DAT_01174068);
    RenderPass* current21 = pass.p;
    if (current21->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current21->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current21->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current21->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current21->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current21->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current21->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current21->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current21->FUN_00888d30(7, stage.p);
    }
    current21->FUN_008866f0(DAT_01173c28);
    current21->FUN_00886650(DAT_011738f0);
    current21->setState(27, 0, true);
    current21->setState(15, 0, true);
    current21->setState(7, 1, true);
    current21->setState(23, 4, true);
    current21->setState(14, 1, true);
    DAT_01172cf0 = 0xff0;
    DAT_01172110 = 0x2c;
    DAT_01171530 = 0x360;
    DAT_01170950 = 0x8;
    // Pass configuration 22
    pass.FUN_00888ea0(DAT_0117406c);
    RenderPass* current22 = pass.p;
    if (current22->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current22->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current22->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current22->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current22->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current22->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current22->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current22->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current22->FUN_00888d30(7, stage.p);
    }
    current22->FUN_008866f0(DAT_01173c28);
    current22->FUN_00886650(DAT_011738f4);
    current22->setState(27, 0, true);
    current22->setState(15, 0, true);
    current22->setState(7, 1, true);
    current22->setState(23, 4, true);
    current22->setState(14, 1, true);
    DAT_01172cf4 = 0xff0;
    DAT_01172114 = 0x3c;
    DAT_01171534 = 0x360;
    DAT_01170954 = 0xc;
    // Pass configuration 23
    pass.FUN_00888ea0(DAT_01174070);
    RenderPass* current23 = pass.p;
    if (current23->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current23->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current23->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current23->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current23->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current23->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current23->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current23->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current23->FUN_00888d30(7, stage.p);
    }
    current23->FUN_008866f0(DAT_01173c28);
    current23->FUN_00886650(DAT_011738f8);
    current23->setState(27, 0, true);
    current23->setState(15, 0, true);
    current23->setState(7, 1, true);
    current23->setState(23, 4, true);
    current23->setState(14, 1, true);
    DAT_01172cf8 = 0xff0;
    DAT_01172118 = 0x3c;
    DAT_01171538 = 0x360;
    DAT_01170958 = 0xc;
    // Pass configuration 24
    pass.FUN_00888ea0(DAT_01174084);
    RenderPass* current24 = pass.p;
    if (current24->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current24->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current24->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current24->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current24->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current24->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current24->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current24->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current24->FUN_00888d30(7, stage.p);
    }
    current24->FUN_008866f0(DAT_01173c2c);
    current24->FUN_00886650(DAT_011738fc);
    current24->setState(27, 0, true);
    current24->setState(15, 0, true);
    current24->setState(7, 1, true);
    current24->setState(23, 4, true);
    current24->setState(14, 1, true);
    DAT_01172d0c = 0x80380;
    DAT_0117212c = 0x13c;
    DAT_0117154c = 0x300;
    DAT_0117096c = 0x0;
    // Pass configuration 25
    pass.FUN_00888ea0(DAT_01174088);
    RenderPass* current25 = pass.p;
    if (current25->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current25->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current25->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current25->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current25->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current25->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current25->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current25->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current25->FUN_00888d30(7, stage.p);
    }
    current25->FUN_008866f0(DAT_01173c2c);
    current25->FUN_00886650(DAT_01173900);
    current25->setState(27, 0, true);
    current25->setState(15, 0, true);
    current25->setState(7, 1, true);
    current25->setState(23, 4, true);
    current25->setState(14, 1, true);
    DAT_01172d10 = 0x80380;
    DAT_01172130 = 0x13c;
    DAT_01171550 = 0x300;
    DAT_01170970 = 0x0;
    // Pass configuration 26
    pass.FUN_00888ea0(DAT_01174090);
    RenderPass* current26 = pass.p;
    if (current26->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current26->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current26->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current26->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current26->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current26->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current26->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current26->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current26->FUN_00888d30(7, stage.p);
    }
    current26->FUN_008866f0(DAT_01173c30);
    current26->FUN_00886650(DAT_011738fc);
    current26->setState(27, 0, true);
    current26->setState(15, 0, true);
    current26->setState(7, 1, true);
    current26->setState(23, 4, true);
    current26->setState(14, 1, true);
    DAT_01172d18 = 0x80b80;
    DAT_01172138 = 0x13c;
    DAT_01171558 = 0x300;
    DAT_01170978 = 0x0;
    // Pass configuration 27
    pass.FUN_00888ea0(DAT_01174094);
    RenderPass* current27 = pass.p;
    if (current27->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current27->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current27->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current27->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current27->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current27->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current27->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current27->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current27->FUN_00888d30(7, stage.p);
    }
    current27->FUN_008866f0(DAT_01173c30);
    current27->FUN_00886650(DAT_01173900);
    current27->setState(27, 0, true);
    current27->setState(15, 0, true);
    current27->setState(7, 1, true);
    current27->setState(23, 4, true);
    current27->setState(14, 1, true);
    DAT_01172d1c = 0x80b80;
    DAT_0117213c = 0x13c;
    DAT_0117155c = 0x300;
    DAT_0117097c = 0x0;
    // Pass configuration 28
    pass.FUN_00888ea0(DAT_0117409c);
    RenderPass* current28 = pass.p;
    if (current28->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current28->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current28->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current28->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current28->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current28->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current28->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current28->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current28->FUN_00888d30(7, stage.p);
    }
    current28->FUN_008866f0(DAT_01173c34);
    current28->FUN_00886650(DAT_01173904);
    current28->setState(27, 0, true);
    current28->setState(15, 0, true);
    current28->setState(7, 1, true);
    current28->setState(23, 4, true);
    current28->setState(14, 1, true);
    DAT_01172d24 = 0x80380;
    DAT_01172144 = 0x13c;
    DAT_01171564 = 0x300;
    DAT_01170984 = 0x0;
    // Pass configuration 29
    pass.FUN_00888ea0(DAT_011740a0);
    RenderPass* current29 = pass.p;
    if (current29->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current29->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current29->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current29->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current29->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current29->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current29->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current29->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current29->FUN_00888d30(7, stage.p);
    }
    current29->FUN_008866f0(DAT_01173c38);
    current29->FUN_00886650(DAT_01173908);
    DAT_01172d28 = 0x80380;
    DAT_01172148 = 0x13c;
    DAT_01171568 = 0x300;
    DAT_01170988 = 0x0;
    // Pass configuration 30
    pass.FUN_00888ea0(DAT_011740a4);
    RenderPass* current30 = pass.p;
    if (current30->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current30->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current30->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current30->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current30->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current30->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current30->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current30->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current30->FUN_00888d30(7, stage.p);
    }
    current30->FUN_008866f0(DAT_01173c34);
    current30->FUN_00886650(DAT_0117390c);
    current30->setState(27, 0, true);
    current30->setState(15, 0, true);
    current30->setState(7, 1, true);
    current30->setState(23, 4, true);
    current30->setState(14, 1, true);
    DAT_01172d2c = 0x80380;
    DAT_0117214c = 0x13c;
    DAT_0117156c = 0x300;
    DAT_0117098c = 0x0;
    // Pass configuration 31
    pass.FUN_00888ea0(DAT_011740ac);
    RenderPass* current31 = pass.p;
    if (current31->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current31->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current31->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current31->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current31->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current31->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current31->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current31->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current31->FUN_00888d30(7, stage.p);
    }
    current31->FUN_008866f0(DAT_01173c3c);
    current31->FUN_00886650(DAT_01173904);
    current31->setState(27, 0, true);
    current31->setState(15, 0, true);
    current31->setState(7, 1, true);
    current31->setState(23, 4, true);
    current31->setState(14, 1, true);
    DAT_01172d34 = 0x80b80;
    DAT_01172154 = 0x13c;
    DAT_01171574 = 0x300;
    DAT_01170994 = 0x0;
    // Pass configuration 32
    pass.FUN_00888ea0(DAT_011740b0);
    RenderPass* current32 = pass.p;
    if (current32->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current32->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current32->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current32->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current32->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current32->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current32->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current32->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current32->FUN_00888d30(7, stage.p);
    }
    current32->FUN_008866f0(DAT_01173c3c);
    current32->FUN_00886650(DAT_0117390c);
    current32->setState(27, 0, true);
    current32->setState(15, 0, true);
    current32->setState(7, 1, true);
    current32->setState(23, 4, true);
    current32->setState(14, 1, true);
    DAT_01172d38 = 0x80b80;
    DAT_01172158 = 0x13c;
    DAT_01171578 = 0x300;
    DAT_01170998 = 0x0;
    // Pass configuration 33
    pass.FUN_00888ea0(DAT_011740b8);
    RenderPass* current33 = pass.p;
    if (current33->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current33->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current33->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current33->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current33->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current33->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current33->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current33->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current33->FUN_00888d30(7, stage.p);
    }
    current33->FUN_008866f0(DAT_01173c40);
    current33->FUN_00886650(DAT_01173910);
    current33->setState(27, 0, true);
    current33->setState(15, 0, true);
    current33->setState(7, 1, true);
    current33->setState(23, 4, true);
    current33->setState(14, 1, true);
    DAT_01172d40 = 0x80780;
    DAT_01172160 = 0x13c;
    DAT_01171580 = 0x300;
    DAT_011709a0 = 0x0;
    // Pass configuration 34
    pass.FUN_00888ea0(DAT_011740bc);
    RenderPass* current34 = pass.p;
    if (current34->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current34->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current34->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current34->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current34->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current34->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current34->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current34->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current34->FUN_00888d30(7, stage.p);
    }
    current34->FUN_008866f0(DAT_01173c44);
    current34->FUN_00886650(DAT_01173914);
    DAT_01172d44 = 0x80780;
    DAT_01172164 = 0x13c;
    DAT_01171584 = 0x300;
    DAT_011709a4 = 0x0;
    // Pass configuration 35
    pass.FUN_00888ea0(DAT_011740c0);
    RenderPass* current35 = pass.p;
    if (current35->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current35->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current35->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current35->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current35->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current35->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current35->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current35->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current35->FUN_00888d30(7, stage.p);
    }
    current35->FUN_008866f0(DAT_01173c40);
    current35->FUN_00886650(DAT_01173918);
    current35->setState(27, 0, true);
    current35->setState(15, 0, true);
    current35->setState(7, 1, true);
    current35->setState(23, 4, true);
    current35->setState(14, 1, true);
    DAT_01172d48 = 0x80780;
    DAT_01172168 = 0x13c;
    DAT_01171588 = 0x300;
    DAT_011709a8 = 0x0;
    // Pass configuration 36
    pass.FUN_00888ea0(DAT_011740c8);
    RenderPass* current36 = pass.p;
    if (current36->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current36->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current36->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current36->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current36->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current36->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current36->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current36->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current36->FUN_00888d30(7, stage.p);
    }
    current36->FUN_008866f0(DAT_01173c48);
    current36->FUN_00886650(DAT_01173910);
    current36->setState(27, 0, true);
    current36->setState(15, 0, true);
    current36->setState(7, 1, true);
    current36->setState(23, 4, true);
    current36->setState(14, 1, true);
    DAT_01172d50 = 0x80f80;
    DAT_01172170 = 0x13c;
    DAT_01171590 = 0x300;
    DAT_011709b0 = 0x0;
    // Pass configuration 37
    pass.FUN_00888ea0(DAT_011740cc);
    RenderPass* current37 = pass.p;
    if (current37->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current37->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current37->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current37->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current37->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current37->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current37->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current37->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current37->FUN_00888d30(7, stage.p);
    }
    current37->FUN_008866f0(DAT_01173c48);
    current37->FUN_00886650(DAT_01173918);
    current37->setState(27, 0, true);
    current37->setState(15, 0, true);
    current37->setState(7, 1, true);
    current37->setState(23, 4, true);
    current37->setState(14, 1, true);
    DAT_01172d54 = 0x80f80;
    DAT_01172174 = 0x13c;
    DAT_01171594 = 0x300;
    DAT_011709b4 = 0x0;
    // Pass configuration 38
    pass.FUN_00888ea0(DAT_0117463c);
    RenderPass* current38 = pass.p;
    if (current38->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current38->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current38->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current38->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current38->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current38->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current38->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current38->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current38->FUN_00888d30(7, stage.p);
    }
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        current38->stages->last->FUN_0088f0b0(false);
    else
        current38->stages->last->FUN_0088f0b0(true);
    current38->FUN_008866f0(DAT_01173d40);
    if (DAT_0116efa0 == 3) {
        void* selected38Index = DAT_01173ae8[DAT_0116f27c].shader;
        current38->FUN_00886650(selected38Index);
    } else {
        void* selected38Base = DAT_01173ae8[0].shader;
        current38->FUN_00886650(selected38Base);
    }
    current38->setState(27, 1, true);
    current38->setState(19, 9, true);
    current38->setState(20, 1, true);
    current38->setState(14, 0, true);
    current38->setState(152, 63, true);
    current38->setFloatState(195, DAT_011761d8, true);
    DAT_011732c4 = 0x184;
    DAT_011726e4 = 0x8;
    DAT_01171b04 = 0x100;
    // Pass configuration 39
    pass.FUN_00888ea0(DAT_01174640);
    RenderPass* current39 = pass.p;
    if (current39->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current39->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current39->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current39->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current39->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current39->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current39->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        current39->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current39->FUN_00888d30(7, stage.p);
    }
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        current39->stages->last->FUN_0088f0b0(false);
    else
        current39->stages->last->FUN_0088f0b0(true);
    current39->FUN_008866f0(DAT_01173d44);
    if (DAT_0116efa0 == 3) {
        void* selected39Index = DAT_01173ae8[DAT_0116f27c].shader;
        current39->FUN_00886650(selected39Index);
    } else {
        void* selected39Base = DAT_01173ae8[0].shader;
        current39->FUN_00886650(selected39Base);
    }
    current39->setState(27, 1, true);
    current39->setState(19, 9, true);
    current39->setState(20, 1, true);
    current39->setState(14, 0, true);
    current39->setFloatState(195, DAT_011761d8, true);
    current39->setState(152, 63, true);
    DAT_011732c8 = 0x984;
    DAT_011726e8 = 0x8;
    DAT_01171b08 = 0x100;
    // Pass configuration 40
    pass.FUN_00888ea0(DAT_01174644);
    RenderPass* current40 = pass.p;
    if (current40->stageCount < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 0, 1, 2, true);
        current40->FUN_00888d30(0, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 1, 1, 2, true);
        current40->FUN_00888d30(1, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 2, 1, 2, true);
        current40->FUN_00888d30(2, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 3, 1, 2, true);
        current40->FUN_00888d30(3, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 4, 1, 2, true);
        current40->FUN_00888d30(4, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 5, 3, 0, true);
        stage.p->texture = DAT_0116f324;
        stage.p->textureEnabled = 1;
        current40->FUN_00888d30(5, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 6, 1, 2, true);
        stage.p->FUN_0088f050(false);
        current40->FUN_00888d30(6, stage.p);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage.p, 7, 3, 0, true);
        current40->FUN_00888d30(7, stage.p);
    }
    if (DAT_0116efa0 == 1 || DAT_0116efa0 == 2)
        current40->stages->last->FUN_0088f0b0(false);
    else
        current40->stages->last->FUN_0088f0b0(true);
    current40->FUN_008866f0(DAT_01173d48);
    if (DAT_0116efa0 == 3) {
        void* selected40Index = DAT_01173ae8[DAT_0116f27c].shader;
        current40->FUN_00886650(selected40Index);
    } else {
        void* selected40Base = DAT_01173ae8[0].shader;
        current40->FUN_00886650(selected40Base);
    }
    current40->setState(27, 1, true);
    current40->setState(19, 9, true);
    current40->setState(20, 1, true);
    current40->setState(14, 0, true);
    current40->setFloatState(195, DAT_011761d8, true);
    current40->setState(152, 63, true);
    DAT_011732cc = 0x184;
    DAT_011726ec = 0x8;
    DAT_01171b0c = 0x100;
}

// @f3 0x00b62f60 (community match, verified in this file)
#include <stdio.h>
#include <string.h>
extern "C" void _ReadWriteBarrier();
struct _FILETIME { unsigned low, high; };
struct _D3DXMACRO { const char* Name; const char* Definition; };
struct ShaderCodeBuffer_be1750 {
 virtual long __stdcall Query(void*,void**) = 0;
 virtual unsigned __stdcall AddRef()=0;
 virtual unsigned __stdcall Release()=0;
 virtual void* __stdcall GetBufferPointer()=0;
 virtual unsigned __stdcall GetBufferSize()=0;
};
typedef ShaderCodeBuffer_be1750 ID3DXBuffer;
struct ID3DXConstantTable;
struct ID3DXInclude;
extern "C" long __stdcall D3DXCompileShader(const char*,unsigned,_D3DXMACRO*,ID3DXInclude*,const char*,const char*,unsigned,ID3DXBuffer**,ID3DXBuffer**,ID3DXConstantTable**);
class VertexShaderFile {
public:
 virtual ~VertexShaderFile();
 virtual void Method1();
 virtual void Method2();
 virtual void Method3();
 virtual void Method4();
 virtual void Method5();
 virtual void Method6();
 virtual void Method7();
 virtual void Method8();
 virtual unsigned GetSize();
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 bool valid;
 void NiBinaryStream_Read(void*,unsigned);
 void ReadBytes(void* p,unsigned n) { NiBinaryStream_Read(p,n); }
};
struct ShaderBufferRecord {};
struct CacheEntryView {
 unsigned unk000;
 unsigned unk004;
 unsigned unk008;
 unsigned unk00c;
 unsigned unk010;
 unsigned unk014;
 unsigned unk018;
 unsigned unk01c;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02c;
 unsigned unk030;
 unsigned unk034;
 unsigned unk038;
 unsigned unk03c;
 unsigned unk040;
 unsigned unk044;
 unsigned unk048;
 unsigned unk04c;
 unsigned unk050;
 unsigned unk054;
 unsigned unk058;
 unsigned unk05c;
 unsigned unk060;
 unsigned unk064;
 unsigned unk068;
 unsigned unk06c;
 unsigned unk070;
 unsigned unk074;
 unsigned unk078;
 unsigned unk07c;
 unsigned unk080;
 unsigned unk084;
 unsigned unk088;
 unsigned unk08c;
 unsigned unk090;
 unsigned unk094;
 unsigned unk098;
 unsigned unk09c;
 unsigned unk0a0;
 unsigned unk0a4;
 unsigned unk0a8;
 unsigned unk0ac;
 unsigned unk0b0;
 unsigned unk0b4;
 unsigned unk0b8;
 unsigned unk0bc;
 unsigned unk0c0;
 unsigned unk0c4;
 unsigned unk0c8;
 unsigned unk0cc;
 unsigned unk0d0;
 unsigned unk0d4;
 unsigned unk0d8;
 unsigned unk0dc;
 unsigned unk0e0;
 unsigned unk0e4;
 unsigned unk0e8;
 unsigned unk0ec;
 unsigned unk0f0;
 unsigned unk0f4;
 unsigned unk0f8;
 unsigned unk0fc;
 unsigned unk100;
char data[1];
};
class ShaderBufferCollection {public: ShaderBufferRecord* Get(const char*); void FUN_00b02550(const char*,const char*,unsigned); void Add(const char* n,const char* d,unsigned z){ FUN_00b02550(n,d,z); } };
class Heap {public: void* Allocate(unsigned); void FUN_0086ba60(void*); void Deallocate(void* p){ FUN_0086ba60(p); }};
extern Heap DAT_01090a78;
struct VertexDevice {
 virtual void __stdcall Method0();
 virtual void __stdcall Method4();
 virtual void __stdcall Method8();
 virtual void __stdcall Method12();
 virtual void __stdcall Method16();
 virtual void __stdcall Method20();
 virtual void __stdcall Method24();
 virtual void __stdcall Method28();
 virtual void __stdcall Method32();
 virtual void __stdcall Method36();
 virtual void __stdcall Method40();
 virtual void __stdcall Method44();
 virtual void __stdcall Method48();
 virtual void __stdcall Method52();
 virtual void __stdcall Method56();
 virtual void __stdcall Method60();
 virtual void __stdcall Method64();
 virtual void __stdcall Method68();
 virtual void __stdcall Method72();
 virtual void __stdcall Method76();
 virtual void __stdcall Method80();
 virtual void __stdcall Method84();
 virtual void __stdcall Method88();
 virtual void __stdcall Method92();
 virtual void __stdcall Method96();
 virtual void __stdcall Method100();
 virtual void __stdcall Method104();
 virtual void __stdcall Method108();
 virtual void __stdcall Method112();
 virtual void __stdcall Method116();
 virtual void __stdcall Method120();
 virtual void __stdcall Method124();
 virtual void __stdcall Method128();
 virtual void __stdcall Method132();
 virtual void __stdcall Method136();
 virtual void __stdcall Method140();
 virtual void __stdcall Method144();
 virtual void __stdcall Method148();
 virtual void __stdcall Method152();
 virtual void __stdcall Method156();
 virtual void __stdcall Method160();
 virtual void __stdcall Method164();
 virtual void __stdcall Method168();
 virtual void __stdcall Method172();
 virtual void __stdcall Method176();
 virtual void __stdcall Method180();
 virtual void __stdcall Method184();
 virtual void __stdcall Method188();
 virtual void __stdcall Method192();
 virtual void __stdcall Method196();
 virtual void __stdcall Method200();
 virtual void __stdcall Method204();
 virtual void __stdcall Method208();
 virtual void __stdcall Method212();
 virtual void __stdcall Method216();
 virtual void __stdcall Method220();
 virtual void __stdcall Method224();
 virtual void __stdcall Method228();
 virtual void __stdcall Method232();
 virtual void __stdcall Method236();
 virtual void __stdcall Method240();
 virtual void __stdcall Method244();
 virtual void __stdcall Method248();
 virtual void __stdcall Method252();
 virtual void __stdcall Method256();
 virtual void __stdcall Method260();
 virtual void __stdcall Method264();
 virtual void __stdcall Method268();
 virtual void __stdcall Method272();
 virtual void __stdcall Method276();
 virtual void __stdcall Method280();
 virtual void __stdcall Method284();
 virtual void __stdcall Method288();
 virtual void __stdcall Method292();
 virtual void __stdcall Method296();
 virtual void __stdcall Method300();
 virtual void __stdcall Method304();
 virtual void __stdcall Method308();
 virtual void __stdcall Method312();
 virtual void __stdcall Method316();
 virtual void __stdcall Method320();
 virtual void __stdcall Method324();
 virtual void __stdcall Method328();
 virtual void __stdcall Method332();
 virtual void __stdcall Method336();
 virtual void __stdcall Method340();
 virtual void __stdcall Method344();
 virtual void __stdcall Method348();
 virtual void __stdcall Method352();
 virtual void __stdcall Method356();
 virtual void __stdcall Method360();
 virtual long __stdcall CreateVertexShader(const char*,void**)=0;
};
class GraphicsRenderer;
struct VertexRendererView {
 unsigned unk000;
 unsigned unk004;
 unsigned unk008;
 unsigned unk00c;
 unsigned unk010;
 unsigned unk014;
 unsigned unk018;
 unsigned unk01c;
 unsigned unk020;
 unsigned unk024;
 unsigned unk028;
 unsigned unk02c;
 unsigned unk030;
 unsigned unk034;
 unsigned unk038;
 unsigned unk03c;
 unsigned unk040;
 unsigned unk044;
 unsigned unk048;
 unsigned unk04c;
 unsigned unk050;
 unsigned unk054;
 unsigned unk058;
 unsigned unk05c;
 unsigned unk060;
 unsigned unk064;
 unsigned unk068;
 unsigned unk06c;
 unsigned unk070;
 unsigned unk074;
 unsigned unk078;
 unsigned unk07c;
 unsigned unk080;
 unsigned unk084;
 unsigned unk088;
 unsigned unk08c;
 unsigned unk090;
 unsigned unk094;
 unsigned unk098;
 unsigned unk09c;
 unsigned unk0a0;
 unsigned unk0a4;
 unsigned unk0a8;
 unsigned unk0ac;
 unsigned unk0b0;
 unsigned unk0b4;
 unsigned unk0b8;
 unsigned unk0bc;
 unsigned unk0c0;
 unsigned unk0c4;
 unsigned unk0c8;
 unsigned unk0cc;
 unsigned unk0d0;
 unsigned unk0d4;
 unsigned unk0d8;
 unsigned unk0dc;
 unsigned unk0e0;
 unsigned unk0e4;
 unsigned unk0e8;
 unsigned unk0ec;
 unsigned unk0f0;
 unsigned unk0f4;
 unsigned unk0f8;
 unsigned unk0fc;
 unsigned unk100;
 unsigned unk104;
 unsigned unk108;
 unsigned unk10c;
 unsigned unk110;
 unsigned unk114;
 unsigned unk118;
 unsigned unk11c;
 unsigned unk120;
 unsigned unk124;
 unsigned unk128;
 unsigned unk12c;
 unsigned unk130;
 unsigned unk134;
 unsigned unk138;
 unsigned unk13c;
 unsigned unk140;
 unsigned unk144;
 unsigned unk148;
 unsigned unk14c;
 unsigned unk150;
 unsigned unk154;
 unsigned unk158;
 unsigned unk15c;
 unsigned unk160;
 unsigned unk164;
 unsigned unk168;
 unsigned unk16c;
 unsigned unk170;
 unsigned unk174;
 unsigned unk178;
 unsigned unk17c;
 unsigned unk180;
 unsigned unk184;
 unsigned unk188;
 unsigned unk18c;
 unsigned unk190;
 unsigned unk194;
 unsigned unk198;
 unsigned unk19c;
 unsigned unk1a0;
 unsigned unk1a4;
 unsigned unk1a8;
 unsigned unk1ac;
 unsigned unk1b0;
 unsigned unk1b4;
 unsigned unk1b8;
 unsigned unk1bc;
 unsigned unk1c0;
 unsigned unk1c4;
 unsigned unk1c8;
 unsigned unk1cc;
 unsigned unk1d0;
 unsigned unk1d4;
 unsigned unk1d8;
 unsigned unk1dc;
 unsigned unk1e0;
 unsigned unk1e4;
 unsigned unk1e8;
 unsigned unk1ec;
 unsigned unk1f0;
 unsigned unk1f4;
 unsigned unk1f8;
 unsigned unk1fc;
 unsigned unk200;
 unsigned unk204;
 unsigned unk208;
 unsigned unk20c;
 unsigned unk210;
 unsigned unk214;
 unsigned unk218;
 unsigned unk21c;
 unsigned unk220;
 unsigned unk224;
 unsigned unk228;
 unsigned unk22c;
 unsigned unk230;
 unsigned unk234;
 unsigned unk238;
 unsigned unk23c;
 unsigned unk240;
 unsigned unk244;
 unsigned unk248;
 unsigned unk24c;
 unsigned unk250;
 unsigned unk254;
 unsigned unk258;
 unsigned unk25c;
 unsigned unk260;
 unsigned unk264;
 unsigned unk268;
 unsigned unk26c;
 unsigned unk270;
 unsigned unk274;
 unsigned unk278;
 unsigned unk27c;
 unsigned unk280;
 unsigned unk284;
VertexDevice* device;
 VertexDevice* GetDevice(){return device;}
};
class NiMemObject { public: static void* operator new(unsigned); static void operator delete(void*); };
class NiD3DVertexShader : public NiMemObject {
public:
 NiD3DVertexShader(GraphicsRenderer*);
 virtual ~NiD3DVertexShader();
 virtual void Method4();
 virtual void Method8();
 virtual void Method12();
 virtual void Method16();
 virtual void Method20();
 virtual void Method24();
 virtual void Method28();
 virtual void Method32();
 virtual void Method36();
 virtual void Method40();
 virtual void Method44();
 virtual void Method48();
 virtual void Method52();
 virtual void Method56();
 virtual void Method60();
 virtual void Method64();
 virtual void Method68();
 virtual void Method72();
 virtual void Method76();
 virtual void Method80();
 virtual void Method84();
 virtual void Method88();
 virtual void Method92();
 virtual void Method96();
 virtual void Method100();
 virtual void Method104();
 virtual void Method108();
 virtual void Method112();
 virtual void Method116();
 virtual void Method120();
 virtual void Method124();
 virtual void Method128();
 virtual void Method132();
 virtual void SetShader(void*);
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
};
extern GraphicsRenderer* g_pkRenderer;
extern ShaderBufferCollection* DAT_0116f288;
extern ShaderBufferCollection* DAT_0116f284;
extern bool DAT_01068970, DAT_0116f297, DAT_0116f20e;
extern char DAT_0116eff0[260];
extern const unsigned char DAT_00ea30e8[];
extern const char DAT_00db3438[];
extern const char DAT_00db3e08[];
extern const char DAT_00dfa7a0[];
extern const char DAT_00e2b564[];
extern const char DAT_00e2b8d0[];
extern const char DAT_00e2c500[];
extern const char DAT_00ea322c[];
extern const char DAT_00ea325c[];
extern const char DAT_00ea3290[];
extern const char DAT_00ea32bc[];
extern const char DAT_00ea32d4[];
extern const char DAT_00ea32e0[];
extern const char DAT_00ea32f8[];
extern const char DAT_00ea32fc[];
extern const char DAT_00ea3300[];
extern const char DAT_00ea3304[];
extern const char DAT_00ea3338[];
void __cdecl FUN_00b62d40(char*,const char*,const char*,const char*);
bool __cdecl FUN_00bc77c0(const char*,_FILETIME&,unsigned);
VertexShaderFile* __cdecl FUN_00bc7fc0(const char*,NiFile::OpenMode,unsigned,unsigned);
namespace FileFinder {
 inline bool GetFileTime(const char* p,_FILETIME& t,unsigned f){return FUN_00bc77c0(p,t,f);}
 inline VertexShaderFile* GetFile(const char* p,NiFile::OpenMode m,unsigned b,unsigned f){return FUN_00bc7fc0(p,m,b,f);}
}
inline bool StringsEqual(const char* a,const char* b) { if(a == b) return true; if(!a) return !b || !*b; if(!b) return !*a; return strcmp(a,b)==0; }
inline bool IsEmptyDirectory(const char* p){return StringsEqual(0,p);}
int __cdecl FUN_00403230(char*,unsigned,const char*,...);
void __cdecl FUN_00bcb0e0(const char*);
inline void Cat(char* d, unsigned n, const char* s) { strcat_s(d, n, s); }
// pdb: BSShader::CompileVertexShaderHLSL | BSShader.obj | fnv360_0822_retail, ustr, medium
// pdb params: apFilename, apMacro, apTarget, apCacheName
NiD3DVertexShader* __stdcall FUN_00b62f60(const char* source, _D3DXMACRO* macros, const char* profile,
                                     const char* shaderName)
{
    ShaderBufferRecord* pCacheEntry = 0;
    ShaderCodeBuffer_be1750* pCompiledShader = 0;
    ShaderCodeBuffer_be1750* pCompileErrors = 0;
    NiD3DVertexShader* result = 0;
    ID3DXConstantTable* constants = 0;
    unsigned int bytecodeSize = 0;
    void* d3dShader;
    char cachePath[260];
    char message[260];
    char defines[1300];
    char errorMessage[260];
    char commandLine[1300];
    char diagnostic[1300];
    FUN_00b62d40(cachePath, source, shaderName, (const char*)DAT_00e2b564);
    bool useCache = true;
    bool cacheExists = false;
    if (DAT_0116f288)
        pCacheEntry = DAT_0116f288->Get(shaderName);
    if (DAT_01068970 && !pCacheEntry)
    {
        _ReadWriteBarrier();
        _FILETIME ftSourceTime;
        _FILETIME ftCacheTime;
        memset(&ftSourceTime, 0, sizeof(ftSourceTime));
        memset(&ftCacheTime, 0, sizeof(ftCacheTime));
        cacheExists = FileFinder::GetFileTime(cachePath, ftCacheTime, 32);
        bool sourceExists = FileFinder::GetFileTime(source, ftSourceTime, 32);
        if (!cacheExists && DAT_0116f297)
        {
            if (IsEmptyDirectory(DAT_0116eff0))
            {
                strcpy_s(DAT_0116eff0, 260, (const char*)DAT_00ea3338);
                FUN_00b62d40(cachePath, source, shaderName, (const char*)DAT_00e2b564);
            }
            cacheExists = FileFinder::GetFileTime(cachePath, ftCacheTime, 32);
        }
        if (!sourceExists)
            FUN_00403230(message, 260, (const char*)DAT_00ea3304, source);
        if (!cacheExists)
            useCache = false;
    }
    bool owned = false;
    char* bytecode = 0;
    if (pCacheEntry)
    {
        bytecode = ((CacheEntryView*)pCacheEntry)->data;
    }
    else if (!useCache)
    {
        _D3DXMACRO* addedMacro = 0;
        if (DAT_0116f20e)
        {
            _D3DXMACRO* pMacro = macros;
            if (pMacro->Name)
            {
                _D3DXMACRO* next = macros + 1;
                do
                {
                    pMacro = next++;
                } while (pMacro->Name);
            }
            pMacro->Name = (const char*)DAT_00ea3300;
            pMacro->Definition = (const char*)DAT_00db3438;
            addedMacro = pMacro;
        }
        VertexShaderFile* pSourceFile = (VertexShaderFile*)FileFinder::GetFile(source, NiFile::READ_ONLY, 0x2800, 32);
        if (!pSourceFile || !pSourceFile->valid)
        {
            if (pSourceFile)
                delete pSourceFile;
            FUN_00403230(message, 260, (const char*)DAT_00ea3290, source);
            goto failure;
        }
        unsigned int sourceSize = pSourceFile->GetSize();
        char* sourceData = (char*)DAT_01090a78.Allocate(sourceSize);
        pSourceFile->ReadBytes(sourceData, sourceSize);
        struct IncludeHandler
        {
            const unsigned char* methods;
            const char* source;
        } include;
        include.methods = DAT_00ea30e8;
        include.source = source;
        defines[0] = 0;
        commandLine[0] = 0;
        for (int i = 0; i < 8; i++)
        {
            if (macros[i].Name)
            {
                Cat(defines, 1300, macros[i].Name);
                Cat(commandLine, 1300, (const char*)DAT_00ea32fc);
                Cat(commandLine, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_00dfa7a0);
                    Cat(defines, 1300, macros[i].Definition);
                    Cat(commandLine, 1300, (const char*)DAT_00dfa7a0);
                    Cat(commandLine, 1300, macros[i].Definition);
                }
                else
                {
                    Cat(commandLine, 1300, (const char*)DAT_00ea32f8);
                }
                Cat(defines, 1300, (const char*)DAT_00db3e08);
            }
        }
        FUN_00403230(diagnostic, 1300, (const char*)DAT_00ea32e0, source, profile, defines);
        long lCompileStatus =
            D3DXCompileShader(sourceData, sourceSize, macros, (ID3DXInclude*)&include, (const char*)DAT_00e2b8d0,
                              profile, 0, (ID3DXBuffer**)&pCompiledShader, (ID3DXBuffer**)&pCompileErrors, &constants);
        delete pSourceFile;
        DAT_01090a78.Deallocate(sourceData);
        if (pCompileErrors && !pCompiledShader)
        {
            defines[0] = 0;
            for (int i = 0; i < 8 && macros[i].Name; i++)
            {
                Cat(defines, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_00dfa7a0);
                    Cat(defines, 1300, macros[i].Definition);
                }
                Cat(defines, 1300, (const char*)DAT_00db3e08);
            }
            FUN_00403230(diagnostic, 1300, (const char*)DAT_00ea32d4, source, defines,
                         pCompileErrors->GetBufferPointer());
            pCompileErrors->Release();
            pCompileErrors = 0;
        }
        if (!lCompileStatus && pCompiledShader)
        {
            _iobuf* pOutputFile = fopen(cachePath, (const char*)DAT_00e2c500);
            if (pOutputFile)
            {
                bytecodeSize = pCompiledShader->GetBufferSize();
                fwrite(pCompiledShader->GetBufferPointer(), bytecodeSize, 1, pOutputFile);
                fclose(pOutputFile);
                FUN_00bcb0e0(cachePath);
            }
            else
            {
                FUN_00403230(message, 255, (const char*)DAT_00ea32bc, cachePath);
            }
            bytecode = (char*)pCompiledShader->GetBufferPointer();
        }
        else
        {
            if (!cacheExists)
                goto failure;
            VertexShaderFile* pCacheFile =
                (VertexShaderFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x2800, 32);
            if (!pCacheFile)
                goto failure;
            if (pCacheFile->valid)
            {
                bytecodeSize = pCacheFile->GetSize();
                bytecode = (char*)DAT_01090a78.Allocate(bytecodeSize);
                owned = true;
                pCacheFile->ReadBytes(bytecode, bytecodeSize);
            }
            delete pCacheFile;
            if (!bytecode)
                goto failure;
        }
        if (addedMacro)
        {
            addedMacro->Name = 0;
            addedMacro->Definition = 0;
        }
    }
    else
    {
        VertexShaderFile* pCacheFile = (VertexShaderFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x2800, 32);
        if (pCacheFile)
        {
            if (pCacheFile->valid)
            {
                
                bytecodeSize = pCacheFile->GetSize();
                bytecode = (char*)DAT_01090a78.Allocate(bytecodeSize);
                owned = true;
                pCacheFile->ReadBytes(bytecode, bytecodeSize);
            }
            delete pCacheFile;
        }
        else
        {
            FUN_00403230(errorMessage, 260, (const char*)DAT_00ea322c, cachePath);
            goto failure;
        }
    }
    if (bytecode)
    {
        if (DAT_0116f284)
            DAT_0116f284->Add(shaderName, bytecode, bytecodeSize);
        else
        {
            VertexDevice* device = ((VertexRendererView*)g_pkRenderer)->GetDevice();
            if (device->CreateVertexShader(bytecode, &d3dShader))
                goto deviceError;
            result = new NiD3DVertexShader(g_pkRenderer);
            result->SetShader(d3dShader);
        }
    }
    if (owned)
        DAT_01090a78.Deallocate(bytecode);
    return result;
deviceError:
    FUN_00403230(errorMessage, 260, (const char*)DAT_00ea325c, cachePath);
failure:
    _ReadWriteBarrier();
    return result;
}

// @f3 0x00b69ec0 (community match, verified in this file)
namespace f3_00b69ec0 {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void FUN_008905a0(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00890750();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    int references;
    void FUN_0088fe30();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            FUN_0088fe30();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void FUN_0088ff50(ShaderStagePointer*);
void FUN_00b62c70(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00888c10();
    void FUN_00888d30(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00890750();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00888c10();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00888c10();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern RefObject* DAT_011737d4;
extern RefObject* DAT_011737d8;
extern RefObject* DAT_011737dc;
extern RefObject* DAT_011737e0;
extern RefObject* DAT_01173b1c;
extern RefObject* DAT_01173b20;
extern RefObject* DAT_01173b24;
extern RefObject* DAT_01173b98;
extern RefObject* DAT_01173b9c;
extern RefObject* DAT_01173ba0;
extern ShaderPass* DAT_011742a0;
extern ShaderPass* DAT_011742a4;
extern ShaderPass* DAT_011742a8;
extern ShaderPass* DAT_011742ac;
extern ShaderPass* DAT_011742b0;
extern ShaderPass* DAT_011742b4;
extern ShaderPass* DAT_011742b8;
extern ShaderPass* DAT_011742c0;
extern unsigned int DAT_01172348;
extern unsigned int DAT_0117234c;
extern unsigned int DAT_01172350;
extern unsigned int DAT_01172354;
extern unsigned int DAT_01172358;
extern unsigned int DAT_0117235c;
extern unsigned int DAT_01172360;
extern unsigned int DAT_01172368;
extern unsigned int DAT_01172f28;
extern unsigned int DAT_01172f2c;
extern unsigned int DAT_01172f30;
extern unsigned int DAT_01172f34;
extern unsigned int DAT_01172f38;
extern unsigned int DAT_01172f3c;
extern unsigned int DAT_01172f40;
extern unsigned int DAT_01172f48;
// @fnv 0x00be7f40
void FUN_00b69ec0()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011742a0;
    if (pass->Count() < 1)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b1c;
    pass->pixelShader = DAT_011737d4;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f28 = 0;
    DAT_01172348 = 0;
    pass = DAT_011742a4;
    if (pass->Count() < 3)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 1, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 2, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b24;
    pass->pixelShader = DAT_011737dc;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f2c = 0;
    DAT_0117234c = 0;
    pass = DAT_011742a8;
    if (pass->Count() < 2)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 1, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b20;
    pass->pixelShader = DAT_011737e0;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f30 = 0;
    DAT_01172350 = 16;
    pass = DAT_011742ac;
    if (pass->Count() < 1)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b98;
    pass->pixelShader = DAT_011737d4;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f34 = 2048;
    DAT_01172354 = 0;
    pass = DAT_011742b0;
    if (pass->Count() < 1)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b20;
    pass->pixelShader = DAT_011737d8;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f38 = 0;
    DAT_01172358 = 0;
    pass = DAT_011742b4;
    if (pass->Count() < 1)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b9c;
    pass->pixelShader = DAT_011737d8;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f3c = 2048;
    DAT_0117235c = 0;
    pass = DAT_011742b8;
    if (pass->Count() < 3)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 1, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 2, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173ba0;
    pass->pixelShader = DAT_011737dc;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f40 = 2048;
    DAT_01172360 = 0;
    pass = DAT_011742c0;
    if (pass->Count() < 2)
    {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 0, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.object, 1, 1, 2, true);
        pass->FUN_00888d30(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_01173b9c;
    pass->pixelShader = DAT_011737e0;
    pass->GetState()->FUN_008905a0(19, 9, 1);
    pass->GetState()->FUN_008905a0(20, 1, 1);
    DAT_01172f48 = 2048;
    DAT_01172368 = 16;
}

}

// @f3 0x00b7de40 (community match, verified in this file)
namespace f3_0206 {
struct NiRefObject0206
{
    virtual ~NiRefObject0206();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
    void DecRefCount() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis(); }
};

struct StageReturn
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiUnk08;
    unsigned int m_uiUnk0c;
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
    unsigned int m_uiRefCount;
    void FUN_0088fe30();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            FUN_0088fe30();
    }
};
void FUN_0088ff50(StageReturn*& rpkStage);
void FUN_00b62c70(StageReturn* pkStage, unsigned int uiIndex, unsigned int ui, unsigned int uiB,
                        unsigned int uiC);

struct StagePtr_bfbf60
{
    StageReturn* m_pObject;
    StagePtr_bfbf60() : m_pObject(0)
    {}
    ~StagePtr_bfbf60()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct RenderStateGroup_bfbf60
{
    void FUN_008905a0(unsigned int uiState, unsigned int uiValue, bool bSave);
};
RenderStateGroup_bfbf60* FUN_00890750();

class ShaderProgram_bfbf60 : public NiRefObject0206
{
};

struct Pass_bfbf60
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    RenderStateGroup_bfbf60* m_pRenderStateGroup;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    NiPointer<ShaderProgram_bfbf60> m_spPixelShaderObject;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<ShaderProgram_bfbf60> m_spVertexShaderObject;
    unsigned int m_uiUnk60;
    unsigned int m_uiRefCount;

    void FUN_00888c10();
    void FUN_00888d30(unsigned int uiStage, StageReturn* pkStage);
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            FUN_00888c10();
    }
    RenderStateGroup_bfbf60* GetRenderStateGroup()
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = FUN_00890750();
        return m_pRenderStateGroup;
    }
};

extern NiPointer<Pass_bfbf60> DAT_01174698;
extern NiPointer<Pass_bfbf60> DAT_0117469c;
extern NiPointer<Pass_bfbf60> DAT_011746a0;
extern NiPointer<Pass_bfbf60> DAT_011746a4;
extern ShaderProgram_bfbf60* DAT_01173ca4;
extern ShaderProgram_bfbf60* DAT_01173ca8;
extern ShaderProgram_bfbf60* DAT_01173cac;
extern ShaderProgram_bfbf60* DAT_0117396c;
extern ShaderProgram_bfbf60* DAT_01173970;
extern ShaderProgram_bfbf60* DAT_01173974;
extern unsigned int DAT_01173320;
extern unsigned int DAT_01173324;
extern unsigned int DAT_01173328;
extern unsigned int DAT_0117332c;
extern unsigned int DAT_01172740;
extern unsigned int DAT_01172744;
extern unsigned int DAT_01172748;
extern unsigned int DAT_0117274c;
extern unsigned int DAT_0116f334;

// For each of four global passes, fills missing stages, assigns shader programs, sets render states and writes per-pass constants.
// @fnv 0x00bfbf60
// pdb: ShadowLightShader::PresetEnvMapPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void FUN_00b7de40()
{
    NiPointer<Pass_bfbf60> spRenderPass;
    StagePtr_bfbf60 spStage;

    spRenderPass = DAT_01174698;
    unsigned int uiStageCount = spRenderPass->m_uiNumberOfStages;
    if (uiStageCount < 4)
    {
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
    }
    spRenderPass->m_spVertexShaderObject = DAT_01173ca4;
    spRenderPass->m_spPixelShaderObject = DAT_0117396c;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 0, true);
    DAT_01173320 = 0x704;
    DAT_01172740 = 0x24;

    spRenderPass = DAT_0117469c;
    if (spRenderPass->m_uiNumberOfStages < 4)
    {
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
    }
    spRenderPass->m_spVertexShaderObject = DAT_01173ca8;
    spRenderPass->m_spPixelShaderObject = DAT_0117396c;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 0, true);
    DAT_01173324 = 0x2f00;
    DAT_01172744 = 0x24;

    spRenderPass = DAT_011746a0;
    if (spRenderPass->m_uiNumberOfStages < 4)
    {
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
    }
    spRenderPass->m_spVertexShaderObject = DAT_01173ca4;
    spRenderPass->m_spPixelShaderObject = DAT_01173970;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 0, true);
    DAT_01173328 = 0x704;
    DAT_01172748 = 0x24;

    spRenderPass = DAT_011746a4;
    if (spRenderPass->m_uiNumberOfStages < 2)
    {
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
        FUN_0088ff50(spStage.m_pObject);
        FUN_00b62c70(spStage.m_pObject, 1, 1, 2, 1);
        spStage.m_pObject->m_uiUnk08 = DAT_0116f334;
        spStage.m_pObject->m_uiUnk0c = 1;
        spRenderPass->FUN_00888d30(spRenderPass->m_uiStageMask, spStage.m_pObject);
    }
    spRenderPass->m_spVertexShaderObject = DAT_01173cac;
    spRenderPass->m_spPixelShaderObject = DAT_01173974;
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(7, 1, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->FUN_008905a0(0xe, 0, true);
    DAT_0117332c = 0x40704;
    DAT_0117274c = 0x2c;
}
}  // namespace fnv_00bfbf60

// @f3 0x00b60490 (community match, verified in this file)
namespace fo3_b60490 {
struct NiGeometry; struct ShadowSceneLight;
struct BSShaderProperty { struct ShaderPassList { void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*); }; };
struct SelectColor
{
    float r, g, b;
    bool FUN_00914730(const SelectColor&);
};
extern SelectColor DAT_0108f450;
extern bool DAT_01067b4d;
struct SelectMaterial
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
    SelectColor color;
    SelectColor* externalColor;
};
struct SelectLighting
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
    float alpha;
    float otherAlpha;
    bool FUN_00468ec0(int);
};
struct SelectGeometry
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
    SelectMaterial* material;
    SelectLighting* lighting;
};
struct SelectShader
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
    BSShaderProperty::ShaderPassList* passes;
    int FUN_00b60490(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type, bool* out,
                     bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i, bool j, bool k);
};
// @fnv 0x00bde1d0
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0721_beta, call_gap, low
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abFacegenBlend, abMultitexture, abProjShadow, abParallax, abModelSpaceNormals, abTreeBranch, abTreeBillboard, abHair, abAlphaTest
int SelectShader::FUN_00b60490(NiGeometry* geom, ShadowSceneLight* light, unsigned short* count, unsigned char type,
                               bool* out, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i,
                               bool j, bool k)
{
    if (!a)
    {
        if (b)
        {
            if (!c)
            {
                if (!f)
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 255, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 268, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 259, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 271, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 256, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 269, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (!f)
                {
                    if (!g)
                    {
                        if (!e)
                        {
                            if (!h && !i)
                            {
                                if (!j)
                                {
                                    if (type == 1)
                                    {
                                        SelectMaterial* mat = ((SelectGeometry*)geom)->material;
                                        SelectLighting* prop = ((SelectGeometry*)geom)->lighting;
                                        if (DAT_01067b4d &&
                                            (!mat || (mat->externalColor ? mat->externalColor : &mat->color)
                                                         ->FUN_00914730(DAT_0108f450)) &&
                                            !(prop->alpha < 1.0f) && prop->FUN_00468ec0(37))
                                        {
                                            passes->FUN_00b2c0b0(geom, (prop->FUN_00468ec0(34) ? 253 : 252), true, 1, light, 0,
                                                        0, 0);
                                        }
                                        else
                                        {
                                            passes->FUN_00b2c0b0(geom, 251, true, 1, light, 0, 0, 0);
                                        }
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->FUN_00b2c0b0(geom, 260, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                            else
                            {
                                if (i)
                                {
                                    if (type == 1)
                                    {
                                        passes->FUN_00b2c0b0(geom, 565, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->FUN_00b2c0b0(geom, 264, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (!h)
                            {
                                if (!j)
                                {
                                    if (type == 1)
                                    {
                                        passes->FUN_00b2c0b0(geom, 266, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                                else
                                {
                                    if (type == 1)
                                    {
                                        passes->FUN_00b2c0b0(geom, 272, true, 1, light, 0, 0, 0);
                                    }
                                    else
                                    {
                                        ++*count;
                                    }
                                }
                            }
                            else
                            {
                                if (type == 1)
                                {
                                    passes->FUN_00b2c0b0(geom, 276, true, 1, light, 0, 0, 0);
                                }
                                else
                                {
                                    ++*count;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (!e)
                        {
                            if (type == 1)
                            {
                                passes->FUN_00b2c0b0(geom, 254, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                        else
                        {
                            if (type == 1)
                            {
                                passes->FUN_00b2c0b0(geom, 267, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                ++*count;
                            }
                        }
                    }
                }
                else
                {
                    if (!e)
                    {
                        if (type == 1)
                        {
                            SelectMaterial* mat = ((SelectGeometry*)geom)->material;
                            SelectLighting* prop = ((SelectGeometry*)geom)->lighting;
                            if (DAT_01067b4d &&
                                (!mat ||
                                 (mat->externalColor ? mat->externalColor : &mat->color)->FUN_00914730(DAT_0108f450)) &&
                                prop->FUN_00468ec0(37) && !(prop->otherAlpha < 1.0f))
                            {
                                passes->FUN_00b2c0b0(geom, 258, true, 1, light, 0, 0, 0);
                            }
                            else
                            {
                                passes->FUN_00b2c0b0(geom, 257, true, 1, light, 0, 0, 0);
                            }
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 270, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (b)
        {
            if (!c && !f)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 262, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 274, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
        }
        else
        {
            if (c)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 263, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        passes->FUN_00b2c0b0(geom, 275, true, 1, light, 0, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else if (!f)
            {
                if (!e)
                {
                    if (!j)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 261, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 265, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
                else
                {
                    if (!j)
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 273, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                    else
                    {
                        if (type == 1)
                        {
                            passes->FUN_00b2c0b0(geom, 277, true, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            ++*count;
                        }
                    }
                }
            }
        }
    }
    *out = false;
    return 0;
}

}

// @f3 0x00b611d0 (community match, verified in this file)
namespace task0221 {
struct NiGeometry;
struct Vec98
{
    float x, y, z;
    bool Equal(const Vec98& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }
};
extern Vec98 DAT_0108f450;
struct Data98
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
    Vec98 color;
};
struct Light98
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
    bool special;
    unsigned char unkf5, unkf6, unkf7;
    Data98* data;
};
struct Passes98
{
    void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, Light98*, Light98*, Light98*, Light98*);
};
struct Shader98
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
    Passes98* passes;
    int FUN_00b611d0(NiGeometry*, Light98*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool);
};
// If the light's color differs from DAT_0108f450, picks a pass id from the flag combination and either runs FUN_00b2c0b0 or increments *count, then clears *out.
// Adapted from the compiled FNV compatibility overlay, recovery:9049.
// pdb: BSShaderPPLightingProperty::AddSpecularPass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apLight, asCount, abUpdateList, abFirst, abSkinned, abMultitexture, abProjShadow, abParallax, abTreeBranch, abHair
int Shader98::FUN_00b611d0(NiGeometry* geom, Light98* light, unsigned short* count, unsigned char mode, bool* out,
                           bool alternate, bool unused, bool flagA, bool flagB, bool flagC, bool flagD)
{
    bool special = light->special;
    if (!light->data->color.Equal(DAT_0108f450))
    {
        if (!alternate)
        {
            if (!special)
            {
                if (!flagB)
                {
                    if (!flagA)
                    {
                        if (!flagC)
                        {
                            if (!flagD)
                            {
                                if (mode == 1)
                                    passes->FUN_00b2c0b0(geom, 346, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (mode == 1)
                                    passes->FUN_00b2c0b0(geom, 347, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 351, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!flagC)
                        {
                            if (!flagD)
                            {
                                if (mode == 1)
                                    passes->FUN_00b2c0b0(geom, 352, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                            else
                            {
                                if (mode == 1)
                                    passes->FUN_00b2c0b0(geom, 353, *out, 1, light, 0, 0, 0);
                                else
                                    ++*count;
                            }
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 357, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
                else
                {
                    if (!flagA)
                    {
                        if (mode == 1)
                            passes->FUN_00b2c0b0(geom, 348, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00b2c0b0(geom, 354, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
            else
            {
                if (!flagB)
                {
                    if (!flagC)
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 358, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 359, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00b2c0b0(geom, 363, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
                else
                {
                    if (mode == 1)
                        passes->FUN_00b2c0b0(geom, 360, *out, 1, light, 0, 0, 0);
                    else
                        ++*count;
                }
            }
        }
        else
        {
            if (!special)
            {
                if (!flagB)
                {
                    if (!flagA)
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 349, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 350, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                    else
                    {
                        if (!flagD)
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 355, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                        else
                        {
                            if (mode == 1)
                                passes->FUN_00b2c0b0(geom, 356, *out, 1, light, 0, 0, 0);
                            else
                                ++*count;
                        }
                    }
                }
            }
            else
            {
                if (!flagB)
                {
                    if (!flagD)
                    {
                        if (mode == 1)
                            passes->FUN_00b2c0b0(geom, 361, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                    else
                    {
                        if (mode == 1)
                            passes->FUN_00b2c0b0(geom, 362, *out, 1, light, 0, 0, 0);
                        else
                            ++*count;
                    }
                }
            }
        }
        *out = false;
    }
    return 0;
}
}  // namespace task0221

// @f3 0x00b60c70 (community match, verified in this file)
namespace task0215 {
struct Vec91
{
    float x, y, z;
    bool FUN_00914730(const Vec91&);
    bool FUN_00914770(const Vec91&);
};
extern Vec91 DAT_0108f450;
extern bool DAT_01067b4d;
struct Color91
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
    Vec91 color;
    Vec91* external;
    Vec91& GetColor()
    {
        return external ? *external : color;
    }
};
struct Alpha91
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short flags;
    bool Enabled() const
    {
        return (flags >> 9) & 1;
    }
};
struct Flags91
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
    float alpha;
    float GetAlpha() const
    {
        return alpha;
    }
    bool FUN_00468ec0(int);
};
struct Geometry91
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
    Alpha91* alpha;
    int unka0;
    Color91* color;
    Flags91* shader;
};
struct LightData91
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
    Vec91 color;
};
struct Light91
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
    LightData91* data;
};
struct Pass91
{
    int unk00;
    unsigned short type;
    unsigned short unk06;
    unsigned char unk08, count, capacity, unk0b;
    Light91** lights;
    void FUN_00b2ae20();
    void FUN_00b2adf0(unsigned int);
};
struct Passes91
{
    int unk00;
    Pass91** entries;
    int unk08, unk0c;
    unsigned int size;
    void FUN_00b2c0b0(Geometry91*, unsigned short, bool, unsigned char, Light91*, Light91*, Light91*, Light91*);
};
struct Shader91
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
    Passes91* passes;
    unsigned char FUN_00af3490();
    Light91* FUN_00af32e0(void*&);
    Light91* FUN_00af33d0(void*&);
    bool FUN_00468ec0(int);
    Pass91* FUN_00b60c70(Geometry91*, Light91*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
};
// Builds a light pass from the shader's passes, fills its light list, and picks a pass type from the mode, light count and flags; returns the pass.
// @fnv 0x00bde9b0
// pdb: BSShaderPPLightingProperty::AddAmbDiffTexSpecular10Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abGlowMap, abSpecular, abFaceGenBlend, abExtraLight
Pass91* Shader91::FUN_00b60c70(Geometry91* geometry, Light91* light, unsigned short* count, unsigned char mode,
                               bool* out, bool alternate, bool special, bool flagA, bool flagB, bool extra)
{
    Pass91* pass = 0;
    if (mode)
    {
        passes->FUN_00b2c0b0(geometry, 0, true, 0, 0, 0, 0, 0);
        pass = passes->entries[passes->size - 1];
        pass->capacity = pass->count = FUN_00af3490() + 1;
        pass->FUN_00b2ae20();
        pass->FUN_00b2adf0(pass->count);
        pass->lights[0] = light;
        int lights = pass->count;
        int limit = extra ? 2 : 1;
        if (!flagA)
        {
            if (!flagB)
                limit += 5;
            else
                limit += 4;
            lights = lights < limit ? lights : limit;
        }
        else if (!flagB)
        {
            limit += 2;
            lights = lights < limit ? lights : limit;
        }
        pass->count = lights;
        void* position = 0;
        Light91* next = FUN_00af32e0(position);
        int i = 1;
        while (next && i < pass->count)
        {
            pass->lights[i++] = next;
            next = FUN_00af33d0(position);
        }
    }
    int lights = pass->count;
    if (!alternate)
    {
        if (special)
        {
            if (flagA)
            {
                if (mode == 1)
                    pass->type = 210;
                else
                    ++*count;
            }
            else if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 203;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 196;
                else
                    ++*count;
            }
        }
        else if (flagA)
        {
            if (flagB)
            {
                if (mode == 1)
                    pass->type = 211;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                {
                    Color91* color = geometry->color;
                    Flags91* shader = geometry->shader;
                    Alpha91* alpha = geometry->alpha;
                    if (DAT_01067b4d && (!color || color->GetColor().FUN_00914730(DAT_0108f450)) &&
                        !light->data->color.FUN_00914770(DAT_0108f450) && shader->FUN_00468ec0(37) &&
                        (!alpha || !alpha->Enabled() || !(shader->GetAlpha() < 1.0f)) && !FUN_00468ec0(7) &&
                        !FUN_00468ec0(21) && !FUN_00468ec0(17) && !shader->FUN_00468ec0(26) &&
                        !shader->FUN_00468ec0(27))
                        pass->type = 209;
                    else
                        pass->type = 208;
                }
                else
                    ++*count;
            }
        }
        else if (flagB)
        {
            if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 204;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 197;
                else
                    ++*count;
            }
        }
        else if (lights < 5)
        {
            if (mode == 1)
            {
                Color91* color = geometry->color;
                Flags91* shader = geometry->shader;
                if (DAT_01067b4d && (!color || color->GetColor().FUN_00914730(DAT_0108f450)) &&
                    !light->data->color.FUN_00914770(DAT_0108f450) && shader->FUN_00468ec0(37) &&
                    !(shader->GetAlpha() < 1.0f) && !FUN_00468ec0(7) && !FUN_00468ec0(21) && !FUN_00468ec0(17) &&
                    !shader->FUN_00468ec0(26) && !shader->FUN_00468ec0(27))
                    pass->type = 202;
                else
                    pass->type = 201;
            }
            else
                ++*count;
        }
        else
        {
            if (mode == 1)
                pass->type = 195;
            else
                ++*count;
        }
    }
    else
    {
        if (special)
        {
            if (flagA)
            {
                if (mode == 1)
                    pass->type = 213;
                else
                    ++*count;
            }
            else if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 206;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 199;
                else
                    ++*count;
            }
        }
        else if (flagA)
        {
            if (flagB)
            {
                if (mode == 1)
                    pass->type = 214;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 212;
                else
                    ++*count;
            }
        }
        else if (flagB)
        {
            if (lights < 5)
            {
                if (mode == 1)
                    pass->type = 207;
                else
                    ++*count;
            }
            else
            {
                if (mode == 1)
                    pass->type = 200;
                else
                    ++*count;
            }
        }
        else if (lights < 5)
        {
            if (mode == 1)
                pass->type = 205;
            else
                ++*count;
        }
        else
        {
            if (mode == 1)
                pass->type = 198;
            else
                ++*count;
        }
    }
    *out = false;
    return pass;
}
}  // namespace task0215

// @f3 0x00b600d0 (community match, verified in this file)
namespace f3m_00b600d0 {
namespace fo3_b600d0 {
struct NiGeometry; struct ShadowSceneLight;
struct PassArray { void FUN_00b2c0b0(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*); };
struct ShaderPassSelector {
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
PassArray* pPasses;
int FUN_00b600d0(NiGeometry*,ShadowSceneLight*,ShadowSceneLight*,unsigned short*,unsigned char,bool*,bool,bool,bool,bool);
};
// @fnv 0x00bdda20
// pdb: BSShaderPPLightingProperty::AddSpecularPt2Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeom, apLight, apLight2, asCount, abUpdateList, abFirst, abSkinned, abParallax, abTreeBranch, abHair
int ShaderPassSelector::FUN_00b600d0(NiGeometry* geom, ShadowSceneLight* light0, ShadowSceneLight* light1,
                                     unsigned short* count, unsigned char type, bool* out, bool a, bool b,
                                     bool d, bool e)
{
    if (!a)
    {
        if (!b)
        {
            if (!d)
            {
                if (!e)
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x16c, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
                else
                {
                    if (type == 1)
                    {
                        ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x16d, *out, 2, light0, light1, 0, 0);
                    }
                    else
                    {
                        ++*count;
                    }
                }
            }
            else
            {
                if (type == 1)
                {
                    ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x171, *out, 2, light0, light1, 0, 0);
                }
                else
                {
                    ++*count;
                }
            }
        }
        else
        {
            if (type == 1)
            {
                ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x16e, *out, 2, light0, light1, 0, 0);
            }
            else
            {
                ++*count;
            }
        }
    }
    else {
        if (!b) {
            if (!e) {
                if (type == 1) ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x16f, *out, 2, light0, light1, 0, 0);
                else ++*count;
            } else {
                if (type == 1) ((PassArray*)pPasses)->FUN_00b2c0b0(geom, 0x170, *out, 2, light0, light1, 0, 0);
                else ++*count;
            }
        }
    }
    *out = false;
    return 0;
}

}
}   // namespace f3m_00b600d0

// @f3 0x00b60270 (community match, verified in this file)
namespace f3m_00b60270 {
namespace fo3_b60270 {
struct NiGeometry;
struct ShadowSceneLight;
struct RPA
{
    void FUN_00b2c0b0(NiGeometry* geom, unsigned short pass, bool enabled, unsigned char numLights, ShadowSceneLight* l0,
             ShadowSceneLight* l1, ShadowSceneLight* l2, ShadowSceneLight* l3);
};
struct Shader_bddfb0
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
    RPA* pPasses;
    int FUN_00b60270(NiGeometry* geom, ShadowSceneLight* l0, ShadowSceneLight* l1, ShadowSceneLight* l2,
                     unsigned short* count, unsigned char type, bool* out, bool a, bool b, bool c, bool d);
};

// @fnv 0x00bddfb0
// pdb: BSShaderPPLightingProperty::AddSpecularPt3Pass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, call_gap, low
// pdb params: apGeom, apLight, apLight2, apLight3, asCount, abUpdateList, abFirst, abSkinned, abParallax, abTreeBranch, abHair
int Shader_bddfb0::FUN_00b60270(NiGeometry* geom, ShadowSceneLight* pLight0, ShadowSceneLight* pLight1,
                                ShadowSceneLight* pLight2, unsigned short* count, unsigned char type, bool* out, bool a,
                                bool b, bool c, bool d)
{
    if (!a)
    {
        if (!b)
        {
            if (!c)
            {
                if (!d)
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geom, 0x172, *out, 3, pLight0, pLight1, pLight2, 0);
                    else
                        ++*count;
                }
                else
                {
                    if (type == 1)
                        pPasses->FUN_00b2c0b0(geom, 0x173, *out, 3, pLight0, pLight1, pLight2, 0);
                    else
                        ++*count;
                }
            }
            else
            {
                if (type == 1)
                    pPasses->FUN_00b2c0b0(geom, 0x177, *out, 3, pLight0, pLight1, pLight2, 0);
                else
                    ++*count;
            }
        }
        else
        {
            if (type == 1)
                pPasses->FUN_00b2c0b0(geom, 0x174, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
    }
    else if (!b)
    {
        if (!d)
        {
            if (type == 1)
                pPasses->FUN_00b2c0b0(geom, 0x175, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
        else
        {
            if (type == 1)
                pPasses->FUN_00b2c0b0(geom, 0x176, *out, 3, pLight0, pLight1, pLight2, 0);
            else
                ++*count;
        }
    }
    *out = false;
    return 0;
}

}
}   // namespace f3m_00b60270

// @f3 0x00b7e740 (community match, verified in this file)
namespace f3m_00b7e740 {




struct ShaderObject {
    virtual void UnkVirtual00();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRefCount() { InterlockedIncrement(&refCount); }
    void DecRefCount() { if (!InterlockedDecrement(&refCount)) DeleteThis(); }
};
struct TextureStage {
    unsigned unk00;
    unsigned unk04;
    unsigned texture;
    unsigned textureEnabled;
    void SetTexture(unsigned value) {texture = value;}
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned refCount;
    void FUN_0088fe30();
    void FUN_0088f050(unsigned value);
    void IncRefCount() { ++refCount; }
    void DecRefCount() { --refCount; if (refCount == 0) FUN_0088fe30(); }
};
struct RenderStates {
    void FUN_008905a0(unsigned state, unsigned value, bool save);
};
extern RenderStates* __cdecl FUN_00890750();
struct ShaderPass {
    unsigned GetCount() const { return stageCount; }

    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned nextIndex;
    unsigned stageCount;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    RenderStates* states;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    NiPointer<ShaderObject> pixel;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    NiPointer<ShaderObject> vertex;
    unsigned unk60;
    unsigned refCount;
    void FUN_00888c10();
    void FUN_00888d30(unsigned index, TextureStage* stage);
    void FUN_008866f0(ShaderObject* shader);
    void FUN_00886650(ShaderObject* shader);
    void IncRefCount() { ++refCount; }
    void DecRefCount() { if (--refCount == 0) FUN_00888c10(); }
    void SetState(unsigned state, unsigned value, bool save) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(state, value, save);
    }
};
extern void __cdecl FUN_0088ff50(NiPointer<TextureStage>& stage);
extern void __cdecl FUN_00b62c70(TextureStage* stage, unsigned index, unsigned op, unsigned arg, bool enabled);
extern bool DAT_01067b4c;
extern unsigned DAT_0116f324;
extern unsigned DAT_0116f32c;
extern unsigned DAT_0116f330;
extern unsigned DAT_011708ac;
extern unsigned DAT_011708b0;
extern unsigned DAT_01170e1c;
extern unsigned DAT_01170e20;
extern unsigned DAT_01170e28;
extern unsigned DAT_01170e2c;
extern unsigned DAT_01170e34;
extern unsigned DAT_01170e38;
extern unsigned DAT_01170e3c;
extern unsigned DAT_01170e40;
extern unsigned DAT_01170e44;
extern unsigned DAT_01170e48;
extern unsigned DAT_01170e4c;
extern unsigned DAT_01170e50;
extern unsigned DAT_01170e54;
extern unsigned DAT_01170e58;
extern unsigned DAT_01170e5c;
extern unsigned DAT_01170e60;
extern unsigned DAT_01170e64;
extern unsigned DAT_01170e68;
extern unsigned DAT_01170e6c;
extern unsigned DAT_01170e70;
extern unsigned DAT_01170e74;
extern unsigned DAT_01170e78;
extern unsigned DAT_01170e7c;
extern unsigned DAT_01170e80;
extern unsigned DAT_01170e84;
extern unsigned DAT_01170e88;
extern unsigned DAT_01170e8c;
extern unsigned DAT_01170e90;
extern unsigned DAT_01170e94;
extern unsigned DAT_01170e98;
extern unsigned DAT_01170e9c;
extern unsigned DAT_01170ea0;
extern unsigned DAT_01170ea4;
extern unsigned DAT_01170ea8;
extern unsigned DAT_01170eac;
extern unsigned DAT_01170eb0;
extern unsigned DAT_01170eb4;
extern unsigned DAT_01170eb8;
extern unsigned DAT_01170ebc;
extern unsigned DAT_01170ec0;
extern unsigned DAT_01170ec4;
extern unsigned DAT_01170ec8;
extern unsigned DAT_01170ecc;
extern unsigned DAT_01170ed0;
extern unsigned DAT_01170ed4;
extern unsigned DAT_01170ed8;
extern unsigned DAT_01170edc;
extern unsigned DAT_01170ee0;
extern unsigned DAT_01170ee4;
extern unsigned DAT_01170ee8;
extern unsigned DAT_01170eec;
extern unsigned DAT_01170ef0;
extern unsigned DAT_01170ef4;
extern unsigned DAT_01170ef8;
extern unsigned DAT_01170efc;
extern unsigned DAT_01170f00;
extern unsigned DAT_01170f04;
extern unsigned DAT_01170f08;
extern unsigned DAT_01170f0c;
extern unsigned DAT_01170f10;
extern unsigned DAT_01170f14;
extern unsigned DAT_01170f18;
extern unsigned DAT_01170f1c;
extern unsigned DAT_01170f20;
extern unsigned DAT_0117148c;
extern unsigned DAT_01171490;
extern unsigned DAT_01171a08;
extern unsigned DAT_01171a0c;
extern unsigned DAT_01171a1c;
extern unsigned DAT_01171a20;
extern unsigned DAT_01171a24;
extern unsigned DAT_01171a28;
extern unsigned DAT_01171a2c;
extern unsigned DAT_01171a30;
extern unsigned DAT_01171a34;
extern unsigned DAT_01171a38;
extern unsigned DAT_01171a3c;
extern unsigned DAT_01171a40;
extern unsigned DAT_01171a44;
extern unsigned DAT_01171a48;
extern unsigned DAT_01171a4c;
extern unsigned DAT_01171a50;
extern unsigned DAT_01171a54;
extern unsigned DAT_01171a58;
extern unsigned DAT_01171a5c;
extern unsigned DAT_01171a60;
extern unsigned DAT_01171a64;
extern unsigned DAT_01171a68;
extern unsigned DAT_01171a6c;
extern unsigned DAT_01171a70;
extern unsigned DAT_01171a74;
extern unsigned DAT_01171a78;
extern unsigned DAT_01171a7c;
extern unsigned DAT_01171a80;
extern unsigned DAT_01171a84;
extern unsigned DAT_01171a88;
extern unsigned DAT_01171a8c;
extern unsigned DAT_01171a90;
extern unsigned DAT_01171a94;
extern unsigned DAT_01171a98;
extern unsigned DAT_01171a9c;
extern unsigned DAT_01171aa0;
extern unsigned DAT_01171aa4;
extern unsigned DAT_01171aa8;
extern unsigned DAT_01171aac;
extern unsigned DAT_01171ab0;
extern unsigned DAT_01171ab4;
extern unsigned DAT_01171ab8;
extern unsigned DAT_01171abc;
extern unsigned DAT_01171ac0;
extern unsigned DAT_01171ac4;
extern unsigned DAT_01171ac8;
extern unsigned DAT_01171acc;
extern unsigned DAT_01171ad0;
extern unsigned DAT_01171ad4;
extern unsigned DAT_01171ad8;
extern unsigned DAT_01171adc;
extern unsigned DAT_01171ae0;
extern unsigned DAT_01171ae4;
extern unsigned DAT_01171ae8;
extern unsigned DAT_01171aec;
extern unsigned DAT_01171af0;
extern unsigned DAT_01171af4;
extern unsigned DAT_01171af8;
extern unsigned DAT_01171afc;
extern unsigned DAT_01171b00;
extern unsigned DAT_0117206c;
extern unsigned DAT_01172070;
extern unsigned DAT_011725dc;
extern unsigned DAT_011725e0;
extern unsigned DAT_011725e4;
extern unsigned DAT_011725e8;
extern unsigned DAT_011725ec;
extern unsigned DAT_011725f0;
extern unsigned DAT_011725f4;
extern unsigned DAT_011725f8;
extern unsigned DAT_011725fc;
extern unsigned DAT_01172600;
extern unsigned DAT_01172604;
extern unsigned DAT_01172608;
extern unsigned DAT_0117260c;
extern unsigned DAT_01172610;
extern unsigned DAT_01172614;
extern unsigned DAT_01172618;
extern unsigned DAT_0117261c;
extern unsigned DAT_01172620;
extern unsigned DAT_01172624;
extern unsigned DAT_01172628;
extern unsigned DAT_0117262c;
extern unsigned DAT_01172630;
extern unsigned DAT_01172634;
extern unsigned DAT_01172638;
extern unsigned DAT_0117263c;
extern unsigned DAT_01172640;
extern unsigned DAT_01172644;
extern unsigned DAT_01172648;
extern unsigned DAT_0117264c;
extern unsigned DAT_01172650;
extern unsigned DAT_01172654;
extern unsigned DAT_01172658;
extern unsigned DAT_0117265c;
extern unsigned DAT_01172660;
extern unsigned DAT_01172664;
extern unsigned DAT_01172668;
extern unsigned DAT_0117266c;
extern unsigned DAT_01172670;
extern unsigned DAT_01172674;
extern unsigned DAT_01172678;
extern unsigned DAT_0117267c;
extern unsigned DAT_01172680;
extern unsigned DAT_01172684;
extern unsigned DAT_01172688;
extern unsigned DAT_0117268c;
extern unsigned DAT_01172690;
extern unsigned DAT_01172694;
extern unsigned DAT_01172698;
extern unsigned DAT_0117269c;
extern unsigned DAT_011726a0;
extern unsigned DAT_011726a4;
extern unsigned DAT_011726a8;
extern unsigned DAT_011726ac;
extern unsigned DAT_011726b0;
extern unsigned DAT_011726b4;
extern unsigned DAT_011726b8;
extern unsigned DAT_011726bc;
extern unsigned DAT_011726c0;
extern unsigned DAT_011726c4;
extern unsigned DAT_011726c8;
extern unsigned DAT_011726cc;
extern unsigned DAT_011726d0;
extern unsigned DAT_011726d4;
extern unsigned DAT_011726d8;
extern unsigned DAT_011726dc;
extern unsigned DAT_011726e0;
extern unsigned DAT_01172c4c;
extern unsigned DAT_01172c50;
extern unsigned DAT_011731bc;
extern unsigned DAT_011731c0;
extern unsigned DAT_011731c4;
extern unsigned DAT_011731c8;
extern unsigned DAT_011731cc;
extern unsigned DAT_011731d0;
extern unsigned DAT_011731d4;
extern unsigned DAT_011731d8;
extern unsigned DAT_011731dc;
extern unsigned DAT_011731e0;
extern unsigned DAT_011731e4;
extern unsigned DAT_011731e8;
extern unsigned DAT_011731ec;
extern unsigned DAT_011731f0;
extern unsigned DAT_011731f4;
extern unsigned DAT_011731f8;
extern unsigned DAT_011731fc;
extern unsigned DAT_01173200;
extern unsigned DAT_01173204;
extern unsigned DAT_01173208;
extern unsigned DAT_0117320c;
extern unsigned DAT_01173210;
extern unsigned DAT_01173214;
extern unsigned DAT_01173218;
extern unsigned DAT_0117321c;
extern unsigned DAT_01173220;
extern unsigned DAT_01173224;
extern unsigned DAT_01173228;
extern unsigned DAT_0117322c;
extern unsigned DAT_01173230;
extern unsigned DAT_01173234;
extern unsigned DAT_01173238;
extern unsigned DAT_0117323c;
extern unsigned DAT_01173240;
extern unsigned DAT_01173244;
extern unsigned DAT_01173248;
extern unsigned DAT_0117324c;
extern unsigned DAT_01173250;
extern unsigned DAT_01173254;
extern unsigned DAT_01173258;
extern unsigned DAT_0117325c;
extern unsigned DAT_01173260;
extern unsigned DAT_01173264;
extern unsigned DAT_01173268;
extern unsigned DAT_0117326c;
extern unsigned DAT_01173270;
extern unsigned DAT_01173274;
extern unsigned DAT_01173278;
extern unsigned DAT_0117327c;
extern unsigned DAT_01173280;
extern unsigned DAT_01173284;
extern unsigned DAT_01173288;
extern unsigned DAT_0117328c;
extern unsigned DAT_01173290;
extern unsigned DAT_01173294;
extern unsigned DAT_01173298;
extern unsigned DAT_0117329c;
extern unsigned DAT_011732a0;
extern unsigned DAT_011732a4;
extern unsigned DAT_011732a8;
extern unsigned DAT_011732ac;
extern unsigned DAT_011732b0;
extern unsigned DAT_011732b4;
extern unsigned DAT_011732b8;
extern unsigned DAT_011732bc;
extern unsigned DAT_011732c0;
extern ShaderObject* DAT_01173978;
extern ShaderObject* DAT_0117397c;
extern ShaderObject* DAT_01173980;
extern ShaderObject* DAT_0117398c;
extern ShaderObject* DAT_011739c8;
extern ShaderObject* DAT_011739cc;
extern ShaderObject* DAT_011739d0;
extern ShaderObject* DAT_011739d4;
extern ShaderObject* DAT_011739d8;
extern ShaderObject* DAT_011739dc;
extern ShaderObject* DAT_011739e0;
extern ShaderObject* DAT_011739f8;
extern ShaderObject* DAT_011739fc;
extern ShaderObject* DAT_01173a00;
extern ShaderObject* DAT_01173a04;
extern ShaderObject* DAT_01173a08;
extern ShaderObject* DAT_01173a0c;
extern ShaderObject* DAT_01173a10;
extern ShaderObject* DAT_01173a14;
extern ShaderObject* DAT_01173a18;
extern ShaderObject* DAT_01173a1c;
extern ShaderObject* DAT_01173a20;
extern ShaderObject* DAT_01173a24;
extern ShaderObject* DAT_01173a28;
extern ShaderObject* DAT_01173a2c;
extern ShaderObject* DAT_01173a30;
extern ShaderObject* DAT_01173a34;
extern ShaderObject* DAT_01173a38;
extern ShaderObject* DAT_01173a3c;
extern ShaderObject* DAT_01173a40;
extern ShaderObject* DAT_01173a44;
extern ShaderObject* DAT_01173a48;
extern ShaderObject* DAT_01173a4c;
extern ShaderObject* DAT_01173a50;
extern ShaderObject* DAT_01173a54;
extern ShaderObject* DAT_01173a58;
extern ShaderObject* DAT_01173a5c;
extern ShaderObject* DAT_01173a60;
extern ShaderObject* DAT_01173a64;
extern ShaderObject* DAT_01173a68;
extern ShaderObject* DAT_01173a6c;
extern ShaderObject* DAT_01173a70;
extern ShaderObject* DAT_01173a74;
extern ShaderObject* DAT_01173a78;
extern ShaderObject* DAT_01173a7c;
extern ShaderObject* DAT_01173a80;
extern ShaderObject* DAT_01173a84;
extern ShaderObject* DAT_01173a88;
extern ShaderObject* DAT_01173a8c;
extern ShaderObject* DAT_01173a90;
extern ShaderObject* DAT_01173a94;
extern ShaderObject* DAT_01173a98;
extern ShaderObject* DAT_01173a9c;
extern ShaderObject* DAT_01173aa0;
extern ShaderObject* DAT_01173aa4;
extern ShaderObject* DAT_01173aa8;
extern ShaderObject* DAT_01173aac;
extern ShaderObject* DAT_01173ab0;
extern ShaderObject* DAT_01173ab4;
extern ShaderObject* DAT_01173ab8;
extern ShaderObject* DAT_01173abc;
extern ShaderObject* DAT_01173ac0;
extern ShaderObject* DAT_01173ac4;
extern ShaderObject* DAT_01173ac8;
extern ShaderObject* DAT_01173acc;
extern ShaderObject* DAT_01173ad0;
extern ShaderObject* DAT_01173ad4;
extern ShaderObject* DAT_01173ad8;
extern ShaderObject* DAT_01173cb0;
extern ShaderObject* DAT_01173cb4;
extern ShaderObject* DAT_01173cb8;
extern ShaderObject* DAT_01173cc4;
extern ShaderObject* DAT_01173d14;
extern ShaderObject* DAT_01173d18;
extern ShaderObject* DAT_01173d1c;
extern ShaderObject* DAT_01173d20;
extern ShaderObject* DAT_01173d24;
extern ShaderObject* DAT_01173d28;
extern ShaderObject* DAT_01173d6c;
extern ShaderObject* DAT_01173d70;
extern NiPointer<ShaderPass> DAT_01173fc4;
extern NiPointer<ShaderPass> DAT_01173fc8;
extern NiPointer<ShaderPass> DAT_01174534;
extern NiPointer<ShaderPass> DAT_01174538;
extern NiPointer<ShaderPass> DAT_0117453c;
extern NiPointer<ShaderPass> DAT_01174540;
extern NiPointer<ShaderPass> DAT_01174544;
extern NiPointer<ShaderPass> DAT_01174548;
extern NiPointer<ShaderPass> DAT_0117454c;
extern NiPointer<ShaderPass> DAT_01174550;
extern NiPointer<ShaderPass> DAT_01174554;
extern NiPointer<ShaderPass> DAT_01174558;
extern NiPointer<ShaderPass> DAT_0117455c;
extern NiPointer<ShaderPass> DAT_01174560;
extern NiPointer<ShaderPass> DAT_01174564;
extern NiPointer<ShaderPass> DAT_01174568;
extern NiPointer<ShaderPass> DAT_0117456c;
extern NiPointer<ShaderPass> DAT_01174570;
extern NiPointer<ShaderPass> DAT_01174574;
extern NiPointer<ShaderPass> DAT_01174578;
extern NiPointer<ShaderPass> DAT_0117457c;
extern NiPointer<ShaderPass> DAT_01174580;
extern NiPointer<ShaderPass> DAT_01174584;
extern NiPointer<ShaderPass> DAT_01174588;
extern NiPointer<ShaderPass> DAT_0117458c;
extern NiPointer<ShaderPass> DAT_01174590;
extern NiPointer<ShaderPass> DAT_01174594;
extern NiPointer<ShaderPass> DAT_01174598;
extern NiPointer<ShaderPass> DAT_0117459c;
extern NiPointer<ShaderPass> DAT_011745a0;
extern NiPointer<ShaderPass> DAT_011745a4;
extern NiPointer<ShaderPass> DAT_011745a8;
extern NiPointer<ShaderPass> DAT_011745ac;
extern NiPointer<ShaderPass> DAT_011745b0;
extern NiPointer<ShaderPass> DAT_011745b4;
extern NiPointer<ShaderPass> DAT_011745b8;
extern NiPointer<ShaderPass> DAT_011745bc;
extern NiPointer<ShaderPass> DAT_011745c0;
extern NiPointer<ShaderPass> DAT_011745c4;
extern NiPointer<ShaderPass> DAT_011745c8;
extern NiPointer<ShaderPass> DAT_011745cc;
extern NiPointer<ShaderPass> DAT_011745d0;
extern NiPointer<ShaderPass> DAT_011745d4;
extern NiPointer<ShaderPass> DAT_011745d8;
extern NiPointer<ShaderPass> DAT_011745dc;
extern NiPointer<ShaderPass> DAT_011745e0;
extern NiPointer<ShaderPass> DAT_011745e4;
extern NiPointer<ShaderPass> DAT_011745e8;
extern NiPointer<ShaderPass> DAT_011745ec;
extern NiPointer<ShaderPass> DAT_011745f0;
extern NiPointer<ShaderPass> DAT_011745f4;
extern NiPointer<ShaderPass> DAT_011745f8;
extern NiPointer<ShaderPass> DAT_011745fc;
extern NiPointer<ShaderPass> DAT_01174600;
extern NiPointer<ShaderPass> DAT_01174604;
extern NiPointer<ShaderPass> DAT_01174608;
extern NiPointer<ShaderPass> DAT_0117460c;
extern NiPointer<ShaderPass> DAT_01174614;
extern NiPointer<ShaderPass> DAT_01174618;
extern NiPointer<ShaderPass> DAT_0117461c;
extern NiPointer<ShaderPass> DAT_01174620;
extern NiPointer<ShaderPass> DAT_01174624;
extern NiPointer<ShaderPass> DAT_01174628;
extern NiPointer<ShaderPass> DAT_0117462c;
extern NiPointer<ShaderPass> DAT_01174630;
extern NiPointer<ShaderPass> DAT_01174634;
extern NiPointer<ShaderPass> DAT_01174638;

// pdb: ShadowLightShader::PresetLandscape_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void __cdecl FUN_00b7e740() {
    NiPointer<ShaderPass> pass;
    NiPointer<TextureStage> stage;
    // pass DAT_01173fc4
    pass = DAT_01173fc4;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d14;
    pass->pixel = DAT_011739c8;
    pass->SetState(0x1b, 0, 1);
    pass->SetState(0xf, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 1, 1);
    DAT_01172c4c = 0x80;
    DAT_0117206c = 0xc;
    DAT_0117148c = 0x80;
    DAT_011708ac = 4;
    // pass DAT_01174540
    pass = DAT_01174540;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d18;
    pass->pixel = DAT_011739cc;
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 6, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731c8 = 0x80;
    DAT_011725e8 = 0xc;
    DAT_01171a08 = 0x80;
    DAT_01170e28 = 4;
    // pass DAT_01174638
    pass = DAT_01174638;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        stage->FUN_0088f050(0);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        stage->FUN_0088f050(0);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        stage->SetTexture(*(DAT_01067b4c ? &DAT_0116f32c : &DAT_0116f330));
        stage->textureEnabled = 1;
        stage->FUN_0088f050(3);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d1c;
    pass->pixel = DAT_011739d0;
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 6, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011732c0 = 0x400380;
    DAT_011726e0 = 0xc;
    DAT_01171b00 = 0x80;
    DAT_01170f20 = 0x304;
    // pass DAT_0117453c
    pass = DAT_0117453c;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d20;
    pass->pixel = DAT_011739d4;
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731c4 = 0;
    DAT_011725e4 = 8;
    // pass DAT_01174548
    pass = DAT_01174548;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d20;
    pass->pixel = DAT_011739d8;
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731d0 = 0;
    DAT_011725f0 = 8;
    // pass DAT_01174534
    pass = DAT_01174534;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d24;
    pass->pixel = DAT_011739dc;
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731bc = 0x80;
    DAT_011725dc = 8;
    DAT_01170e1c = 0;
    // pass DAT_0117454c
    pass = DAT_0117454c;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173d28;
    pass->pixel = DAT_011739e0;
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731d4 = 0x80;
    DAT_011725f4 = 0x1c;
    DAT_01170e34 = 0;
    // pass DAT_01173fc8
    pass = DAT_01173fc8;
    if (pass->GetCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 3, 0, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->vertex = DAT_01173cb0;
    pass->pixel = DAT_01173978;
    pass->SetState(0x1b, 0, 1);
    pass->SetState(0xf, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 1, 1);
    DAT_01172c50 = 0xf0;
    DAT_01172070 = 0xc;
    DAT_01171490 = 0xe0;
    DAT_011708b0 = 4;
    // pass DAT_01174554
    pass = DAT_01174554;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_011739f8;
    DAT_011731dc = 0x300;
    DAT_011725fc = 0xac;
    DAT_01171a1c = 0x300;
    DAT_01170e3c = 0x84;
    // pass DAT_0117455c
    pass = DAT_0117455c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a00;
    DAT_011731e4 = 0x300;
    DAT_01172604 = 0xac;
    DAT_01171a24 = 0x300;
    DAT_01170e44 = 0x84;
    // pass DAT_01174558
    pass = DAT_01174558;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_011739fc;
    DAT_011731e0 = 0x370;
    DAT_01172600 = 0xac;
    DAT_01171a20 = 0x360;
    DAT_01170e40 = 0x84;
    // pass DAT_01174560
    pass = DAT_01174560;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a04;
    DAT_011731e8 = 0x370;
    DAT_01172608 = 0xac;
    DAT_01171a28 = 0x360;
    DAT_01170e48 = 0x84;
    // pass DAT_01174564
    pass = DAT_01174564;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a08;
    DAT_011731ec = 0x300;
    DAT_0117260c = 0xfac;
    DAT_01171a2c = 0x300;
    DAT_01170e4c = 0x84;
    // pass DAT_0117456c
    pass = DAT_0117456c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a10;
    DAT_011731f4 = 0x300;
    DAT_01172614 = 0xfac;
    DAT_01171a34 = 0x300;
    DAT_01170e54 = 0x84;
    // pass DAT_01174568
    pass = DAT_01174568;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a0c;
    DAT_011731f0 = 0x370;
    DAT_01172610 = 0x7ac;
    DAT_01171a30 = 0x360;
    DAT_01170e50 = 0x84;
    // pass DAT_01174570
    pass = DAT_01174570;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a14;
    DAT_011731f8 = 0x370;
    DAT_01172618 = 0x7ac;
    DAT_01171a38 = 0x360;
    DAT_01170e58 = 0x84;
    // pass DAT_01174574
    pass = DAT_01174574;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a18;
    DAT_011731fc = 0x300;
    DAT_0117261c = 0xac;
    DAT_01171a3c = 0x300;
    DAT_01170e5c = 0x84;
    // pass DAT_0117457c
    pass = DAT_0117457c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a20;
    DAT_01173204 = 0x300;
    DAT_01172624 = 0xac;
    DAT_01171a44 = 0x300;
    DAT_01170e64 = 0x84;
    // pass DAT_01174578
    pass = DAT_01174578;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a1c;
    DAT_01173200 = 0x370;
    DAT_01172620 = 0xac;
    DAT_01171a40 = 0x360;
    DAT_01170e60 = 0x84;
    // pass DAT_01174580
    pass = DAT_01174580;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a24;
    DAT_01173208 = 0x370;
    DAT_01172628 = 0xac;
    DAT_01171a48 = 0x360;
    DAT_01170e68 = 0x84;
    // pass DAT_01174584
    pass = DAT_01174584;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a28;
    DAT_0117320c = 0x300;
    DAT_0117262c = 0xfac;
    DAT_01171a4c = 0x300;
    DAT_01170e6c = 0x84;
    // pass DAT_0117458c
    pass = DAT_0117458c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a30;
    DAT_01173214 = 0x300;
    DAT_01172634 = 0xfac;
    DAT_01171a54 = 0x300;
    DAT_01170e74 = 0x84;
    // pass DAT_01174588
    pass = DAT_01174588;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a2c;
    DAT_01173210 = 0x370;
    DAT_01172630 = 0x7ac;
    DAT_01171a50 = 0x360;
    DAT_01170e70 = 0x84;
    // pass DAT_01174590
    pass = DAT_01174590;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a34;
    DAT_01173218 = 0x370;
    DAT_01172638 = 0x7ac;
    DAT_01171a58 = 0x360;
    DAT_01170e78 = 0x84;
    // pass DAT_01174594
    pass = DAT_01174594;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a38;
    DAT_0117321c = 0x300;
    DAT_0117263c = 0xac;
    DAT_01171a5c = 0x300;
    DAT_01170e7c = 0x84;
    // pass DAT_0117459c
    pass = DAT_0117459c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a40;
    DAT_01173224 = 0x300;
    DAT_01172644 = 0xac;
    DAT_01171a64 = 0x300;
    DAT_01170e84 = 0x84;
    // pass DAT_01174598
    pass = DAT_01174598;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a3c;
    DAT_01173220 = 0x370;
    DAT_01172640 = 0xac;
    DAT_01171a60 = 0x360;
    DAT_01170e80 = 0x84;
    // pass DAT_011745a0
    pass = DAT_011745a0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a44;
    DAT_01173228 = 0x370;
    DAT_01172648 = 0xac;
    DAT_01171a68 = 0x360;
    DAT_01170e88 = 0x84;
    // pass DAT_011745a4
    pass = DAT_011745a4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a48;
    DAT_0117322c = 0x300;
    DAT_0117264c = 0xfac;
    DAT_01171a6c = 0x300;
    DAT_01170e8c = 0x84;
    // pass DAT_011745ac
    pass = DAT_011745ac;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a50;
    DAT_01173234 = 0x300;
    DAT_01172654 = 0xfac;
    DAT_01171a74 = 0x300;
    DAT_01170e94 = 0x84;
    // pass DAT_011745a8
    pass = DAT_011745a8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a4c;
    DAT_01173230 = 0x370;
    DAT_01172650 = 0x7ac;
    DAT_01171a70 = 0x360;
    DAT_01170e90 = 0x84;
    // pass DAT_011745b0
    pass = DAT_011745b0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->pixel = DAT_01173a54;
    DAT_01173238 = 0x370;
    DAT_01172658 = 0x7ac;
    DAT_01171a78 = 0x360;
    DAT_01170e98 = 0x84;
    // pass DAT_011745b4
    pass = DAT_011745b4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a58;
    DAT_0117323c = 0x300;
    DAT_0117265c = 0xac;
    DAT_01171a7c = 0x300;
    DAT_01170e9c = 0x84;
    // pass DAT_011745bc
    pass = DAT_011745bc;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d6c;
    pass->pixel = DAT_01173a60;
    DAT_01173244 = 0x300;
    DAT_01172664 = 0xac;
    DAT_01171a84 = 0x300;
    DAT_01170ea4 = 0x84;
    // pass DAT_011745b8
    pass = DAT_011745b8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->vertex = DAT_01173d70;
    pass->FUN_00886650(DAT_01173a5c);
    DAT_01173240 = 0x370;
    DAT_01172660 = 0xac;
    DAT_01171a80 = 0x360;
    DAT_01170ea0 = 0x84;
    // pass DAT_011745c0
    pass = DAT_011745c0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a64);
    DAT_01173248 = 0x370;
    DAT_01172668 = 0xac;
    DAT_01171a88 = 0x360;
    DAT_01170ea8 = 0x84;
    // pass DAT_011745c4
    pass = DAT_011745c4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a68);
    DAT_0117324c = 0x300;
    DAT_0117266c = 0xfac;
    DAT_01171a8c = 0x300;
    DAT_01170eac = 0x84;
    // pass DAT_011745cc
    pass = DAT_011745cc;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a70);
    DAT_01173254 = 0x300;
    DAT_01172674 = 0xfac;
    DAT_01171a94 = 0x300;
    DAT_01170eb4 = 0x84;
    // pass DAT_011745c8
    pass = DAT_011745c8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a6c);
    DAT_01173250 = 0x370;
    DAT_01172670 = 0x7ac;
    DAT_01171a90 = 0x360;
    DAT_01170eb0 = 0x84;
    // pass DAT_011745d0
    pass = DAT_011745d0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a74);
    DAT_01173258 = 0x370;
    DAT_01172678 = 0x7ac;
    DAT_01171a98 = 0x360;
    DAT_01170eb8 = 0x84;
    // pass DAT_011745d4
    pass = DAT_011745d4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a78);
    DAT_0117325c = 0x300;
    DAT_0117267c = 0xac;
    DAT_01171a9c = 0x300;
    DAT_01170ebc = 0x84;
    // pass DAT_011745dc
    pass = DAT_011745dc;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a80);
    DAT_01173264 = 0x300;
    DAT_01172684 = 0xac;
    DAT_01171aa4 = 0x300;
    DAT_01170ec4 = 0x84;
    // pass DAT_011745d8
    pass = DAT_011745d8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a7c);
    DAT_01173260 = 0x370;
    DAT_01172680 = 0xac;
    DAT_01171aa0 = 0x360;
    DAT_01170ec0 = 0x84;
    // pass DAT_011745e0
    pass = DAT_011745e0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a84);
    DAT_01173268 = 0x370;
    DAT_01172688 = 0xac;
    DAT_01171aa8 = 0x360;
    DAT_01170ec8 = 0x84;
    // pass DAT_011745e4
    pass = DAT_011745e4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a88);
    DAT_0117326c = 0x300;
    DAT_0117268c = 0xfac;
    DAT_01171aac = 0x300;
    DAT_01170ecc = 0x84;
    // pass DAT_011745ec
    pass = DAT_011745ec;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a90);
    DAT_01173274 = 0x300;
    DAT_01172694 = 0xfac;
    DAT_01171ab4 = 0x300;
    DAT_01170ed4 = 0x84;
    // pass DAT_011745e8
    pass = DAT_011745e8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a8c);
    DAT_01173270 = 0x370;
    DAT_01172690 = 0x7ac;
    DAT_01171ab0 = 0x360;
    DAT_01170ed0 = 0x84;
    // pass DAT_011745f0
    pass = DAT_011745f0;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a94);
    DAT_01173278 = 0x370;
    DAT_01172698 = 0x7ac;
    DAT_01171ab8 = 0x360;
    DAT_01170ed8 = 0x84;
    // pass DAT_011745f4
    pass = DAT_011745f4;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173a98);
    DAT_0117327c = 0x300;
    DAT_0117269c = 0xac;
    DAT_01171abc = 0x300;
    DAT_01170edc = 0x84;
    // pass DAT_011745fc
    pass = DAT_011745fc;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173aa0);
    DAT_01173284 = 0x300;
    DAT_011726a4 = 0xac;
    DAT_01171ac4 = 0x300;
    DAT_01170ee4 = 0x84;
    // pass DAT_011745f8
    pass = DAT_011745f8;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173a9c);
    DAT_01173280 = 0x370;
    DAT_011726a0 = 0xac;
    DAT_01171ac0 = 0x360;
    DAT_01170ee0 = 0x84;
    // pass DAT_01174600
    pass = DAT_01174600;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173aa4);
    DAT_01173288 = 0x370;
    DAT_011726a8 = 0xac;
    DAT_01171ac8 = 0x360;
    DAT_01170ee8 = 0x84;
    // pass DAT_01174604
    pass = DAT_01174604;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173aa8);
    DAT_0117328c = 0x300;
    DAT_011726ac = 0xfac;
    DAT_01171acc = 0x300;
    DAT_01170eec = 0x84;
    // pass DAT_0117460c
    pass = DAT_0117460c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ab0);
    DAT_01173294 = 0x300;
    DAT_011726b4 = 0xfac;
    DAT_01171ad4 = 0x300;
    DAT_01170ef4 = 0x84;
    // pass DAT_01174608
    pass = DAT_01174608;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173aac);
    DAT_01173290 = 0x370;
    DAT_011726b0 = 0x7ac;
    DAT_01171ad0 = 0x360;
    DAT_01170ef0 = 0x84;
    // pass DAT_01174608
    pass = DAT_01174608;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173ab4);
    DAT_01173298 = 0x370;
    DAT_011726b8 = 0x7ac;
    DAT_01171ad8 = 0x360;
    DAT_01170ef8 = 0x84;
    // pass DAT_01174614
    pass = DAT_01174614;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ab8);
    DAT_0117329c = 0x300;
    DAT_011726bc = 0xac;
    DAT_01171adc = 0x300;
    DAT_01170efc = 0x84;
    // pass DAT_0117461c
    pass = DAT_0117461c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ac0);
    DAT_011732a4 = 0x300;
    DAT_011726c4 = 0xac;
    DAT_01171ae4 = 0x300;
    DAT_01170f04 = 0x84;
    // pass DAT_01174618
    pass = DAT_01174618;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173abc);
    DAT_011732a0 = 0x370;
    DAT_011726c0 = 0xac;
    DAT_01171ae0 = 0x360;
    DAT_01170f00 = 0x84;
    // pass DAT_01174620
    pass = DAT_01174620;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173ac4);
    DAT_011732a8 = 0x370;
    DAT_011726c8 = 0xac;
    DAT_01171ae8 = 0x360;
    DAT_01170f08 = 0x84;
    // pass DAT_01174624
    pass = DAT_01174624;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ac8);
    DAT_011732ac = 0x300;
    DAT_011726cc = 0xfac;
    DAT_01171aec = 0x300;
    DAT_01170f0c = 0x84;
    // pass DAT_0117462c
    pass = DAT_0117462c;
    if (pass->GetCount() < 0xe) {
        for (int i = 0; i < 0xe; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ad0);
    DAT_011732b4 = 0x300;
    DAT_011726d4 = 0xfac;
    DAT_01171af4 = 0x300;
    DAT_01170f14 = 0x84;
    // pass DAT_01174628
    pass = DAT_01174628;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173acc);
    DAT_011732b0 = 0x370;
    DAT_011726d0 = 0x7ac;
    DAT_01171af0 = 0x360;
    DAT_01170f10 = 0x84;
    // pass DAT_01174630
    pass = DAT_01174630;
    if (pass->GetCount() < 0x10) {
        for (int i = 0; i < 0x10; ++i) {
            FUN_0088ff50(stage);
            FUN_00b62c70(stage, i, 1, 2, 1);
            pass->FUN_00888d30(pass->nextIndex, stage);
        }
    }
    pass->FUN_008866f0(DAT_01173d70);
    pass->FUN_00886650(DAT_01173ad4);
    DAT_011732b8 = 0x370;
    DAT_011726d8 = 0x7ac;
    DAT_01171af8 = 0x360;
    DAT_01170f18 = 0x84;
    // pass DAT_01174634
    pass = DAT_01174634;
    pass->FUN_008866f0(DAT_01173d6c);
    pass->FUN_00886650(DAT_01173ad8);
    pass->SetState(0x1b, 0, 1);
    pass->SetState(0xf, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 1, 1);
    DAT_011732bc = 0x300;
    DAT_011726dc = 4;
    DAT_01171afc = 0x300;
    DAT_01170f1c = 4;
    // pass DAT_01174544
    pass = DAT_01174544;
    if (pass->GetCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 3, 0, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173cb4);
    pass->FUN_00886650(DAT_0117397c);
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 6, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731cc = 0xf0;
    DAT_011725ec = 0xc;
    DAT_01171a0c = 0xe0;
    DAT_01170e2c = 4;
    // pass DAT_01174538
    pass = DAT_01174538;
    if (pass->GetCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureEnabled = 1;
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173cb8);
    pass->FUN_00886650(DAT_01173980);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731c0 = 0x80;
    DAT_011725e0 = 0xc;
    DAT_01170e20 = 4;
    // pass DAT_01174550
    pass = DAT_01174550;
    if (pass->GetCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(pass->nextIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureEnabled = 1;
        pass->FUN_00888d30(pass->nextIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173cc4);
    pass->FUN_00886650(DAT_0117398c);
    pass->SetState(0x1b, 1, 1);
    pass->SetState(0x13, 5, 1);
    pass->SetState(0x14, 2, 1);
    pass->SetState(0xf, 1, 1);
    pass->SetState(0x19, 5, 1);
    pass->SetState(0x18, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(0x17, 4, 1);
    pass->SetState(0xe, 0, 1);
    DAT_011731d8 = 0x80;
    DAT_011725f8 = 0x1c;
    DAT_01170e38 = 0;
}
}   // namespace f3m_00b7e740

// @f3 0x00b6a8f0 (community match, verified in this file)
namespace f3m_00b6a8f0 {
struct Property {
    virtual void unused();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct PropertyPtr {
    Property* p;
    PropertyPtr& operator=(Property* next) {
        Property* old = p;
        if (old != next) {
            if (old) old->DecRefCount();
            p = next;
            if (next) next->IncRefCount();
        }
        return *this;
    }
};
struct RenderState { void FUN_008905a0(int, int, int); };
RenderState* __cdecl FUN_00890750();
struct Stage {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    unsigned int refs;
    void FUN_0088fe30();
    void IncRefCount() { ++refs; }
    void DecRefCount() { --refs; if (refs == 0) FUN_0088fe30(); }
};
struct StagePtr {
    Stage* p;
    StagePtr() : p(0) {}
    ~StagePtr() { if (p) p->DecRefCount(); }
};
void __cdecl FUN_0088ff50(StagePtr*);
void __cdecl FUN_00b62c70(Stage*, int, int, int, int);
struct Pass {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int stageIndex;
    unsigned int stageCount;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    RenderState* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    PropertyPtr property;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    PropertyPtr program;
    unsigned int unk60;
    unsigned int refs;
    unsigned int GetStageCount() const { return stageCount; }
    void FUN_00888c10();
    void FUN_00888d30(unsigned int, Stage*);
    void IncRefCount() { ++refs; }
    void DecRefCount() { if (--refs == 0) FUN_00888c10(); }
    void SetState(int id, int value, int enable) {
        if (!state) state = FUN_00890750();
        state->FUN_008905a0(id,value,enable);
    }
};
struct PassPtr {
    Pass* p;
    PassPtr() : p(0) {}
    ~PassPtr() { if (p) p->DecRefCount(); }
    PassPtr& operator=(const PassPtr& next) {
        if (p != next.p) {
            if (p) p->DecRefCount();
            p = next.p;
            if (p) p->IncRefCount();
        }
        return *this;
    }
    Pass* operator->() const { return p; }
};
extern PassPtr DAT_011742c8, DAT_011742cc, DAT_011742d0, DAT_011742d4;
extern Property* DAT_01173b2c;
extern Property* DAT_01173b28;
extern Property* DAT_01173ba8;
extern Property* DAT_01173ba4;
extern Property* DAT_011737e8;
extern Property* DAT_011737e4;
extern unsigned int DAT_0116f324, DAT_0116f328, DAT_0116f2fc;
extern unsigned int DAT_01172f50, DAT_01172f54, DAT_01172f58, DAT_01172f5c;
extern unsigned int DAT_01172370, DAT_01172374, DAT_01172378, DAT_0117237c;
// pdb: ShadowLightShader::PresetTexturePasses_1x | ShadowLightShader_Preset_1x.obj | fnv360_0822_retail, objrun_prop, medium
void __cdecl FUN_00b6a8f0() {
    PassPtr pass;
    StagePtr stage;
    pass = DAT_011742c8;
    if (pass->GetStageCount() < 1) {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage.p);
    }
    pass->program = DAT_01173b2c;
    pass->property = DAT_011737e8;
    pass->SetState(0x13, 2, 1);
    pass->SetState(0x14, 2, 1);
    DAT_01172f50 = 0x480;
    DAT_01172370 = 8;
    pass = DAT_011742cc;
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 1, 3, 2, 1);
        stage.p->texture = DAT_0116f324;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 2, 3, 2, 1);
        stage.p->texture = DAT_0116f328;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 3, 1, 2, 1);
        stage.p->texture = DAT_0116f2fc;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
    }
    pass->program = DAT_01173b28;
    pass->property = DAT_011737e4;
    pass->SetState(0x13, 2, 1);
    pass->SetState(0x14, 2, 1);
    DAT_01172f54 = 0x480;
    DAT_01172374 = 8;
    pass = DAT_011742d0;
    if (pass->GetStageCount() < 1) {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage.p);
    }
    pass->program = DAT_01173ba8;
    pass->property = DAT_011737e8;
    pass->SetState(0x13, 2, 1);
    pass->SetState(0x14, 2, 1);
    DAT_01172f58 = 0xc80;
    DAT_01172378 = 8;
    pass = DAT_011742d4;
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 1, 3, 2, 1);
        stage.p->texture = DAT_0116f324;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 2, 3, 2, 1);
        stage.p->texture = DAT_0116f328;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
        FUN_0088ff50(&stage);
        FUN_00b62c70(stage.p, 3, 1, 2, 1);
        stage.p->texture = DAT_0116f2fc;
        pass->FUN_00888d30(pass->stageIndex, stage.p);
    }
    pass->program = DAT_01173ba4;
    pass->property = DAT_011737e4;
    pass->SetState(0x13, 2, 1);
    pass->SetState(0x14, 2, 1);
    DAT_01172f5c = 0xc80;
    DAT_0117237c = 8;
}
}   // namespace f3m_00b6a8f0

// @f3 0x00b7b590 (community match, verified in this file)
namespace f3m_00b7b590 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
class ShaderRef {
public:
    virtual void Reserved();
    virtual void Destroy();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (!InterlockedDecrement(&refs)) Destroy(); }
};
struct StageRef {
    unsigned unk00, unk04, texture, enabled;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned refs;
    void FUN_0088fe30();
    void IncRefCount() { ++refs; }
    void DecRefCount() { --refs; if (refs == 0) FUN_0088fe30(); }
};
struct RenderStates { void FUN_008905a0(unsigned, unsigned, bool); };
extern RenderStates* FUN_00890750();
struct PassRef {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned stageIndex;
    unsigned stageCount;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    RenderStates* states;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    NiPointer<ShaderRef> pixelShader;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    NiPointer<ShaderRef> vertexShader;
    unsigned unk60;
    unsigned refs;
    void FUN_00888c10();
    void FUN_00888d30(unsigned, StageRef*);
    void FUN_008866f0(ShaderRef*);
    void FUN_00886650(ShaderRef*);
    unsigned GetStageCount() const { return stageCount; }
    void IncRefCount() { ++refs; }
    void DecRefCount() { if (--refs == 0) FUN_00888c10(); }
    void SetState(unsigned state, unsigned value, bool save) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(state, value, save);
    }
};
extern void FUN_0088ff50(NiPointer<StageRef>&);
extern void FUN_00b62c70(StageRef*, unsigned, unsigned, unsigned, bool);
extern unsigned DAT_0116f324;
extern NiPointer<PassRef> DAT_011742e0;
extern NiPointer<PassRef> DAT_011742e4;
extern NiPointer<PassRef> DAT_011742ec;
extern NiPointer<PassRef> DAT_011742f0;
extern NiPointer<PassRef> DAT_011742f8;
extern NiPointer<PassRef> DAT_011742fc;
extern NiPointer<PassRef> DAT_01174304;
extern NiPointer<PassRef> DAT_01174308;
extern NiPointer<PassRef> DAT_01174310;
extern NiPointer<PassRef> DAT_01174314;
extern NiPointer<PassRef> DAT_0117431c;
extern NiPointer<PassRef> DAT_01174320;
extern NiPointer<PassRef> DAT_01174328;
extern NiPointer<PassRef> DAT_0117432c;
extern NiPointer<PassRef> DAT_01174334;
extern NiPointer<PassRef> DAT_01174338;
extern NiPointer<PassRef> DAT_01174340;
extern NiPointer<PassRef> DAT_01174344;
extern NiPointer<PassRef> DAT_0117434c;
extern NiPointer<PassRef> DAT_01174350;
extern ShaderRef* DAT_01173944;
extern ShaderRef* DAT_01173948;
extern ShaderRef* DAT_0117394c;
extern ShaderRef* DAT_01173950;
extern ShaderRef* DAT_01173954;
extern ShaderRef* DAT_01173958;
extern ShaderRef* DAT_0117395c;
extern ShaderRef* DAT_01173960;
extern ShaderRef* DAT_01173964;
extern ShaderRef* DAT_01173968;
extern ShaderRef* DAT_01173c7c;
extern ShaderRef* DAT_01173c80;
extern ShaderRef* DAT_01173c84;
extern ShaderRef* DAT_01173c88;
extern ShaderRef* DAT_01173c8c;
extern ShaderRef* DAT_01173c90;
extern ShaderRef* DAT_01173c94;
extern ShaderRef* DAT_01173c98;
extern ShaderRef* DAT_01173c9c;
extern ShaderRef* DAT_01173ca0;
extern unsigned DAT_011717c0;
extern unsigned DAT_011717cc;
extern unsigned DAT_01172388;
extern unsigned DAT_0117238c;
extern unsigned DAT_01172394;
extern unsigned DAT_01172398;
extern unsigned DAT_011723a0;
extern unsigned DAT_011723a4;
extern unsigned DAT_011723ac;
extern unsigned DAT_011723b0;
extern unsigned DAT_011723b8;
extern unsigned DAT_011723bc;
extern unsigned DAT_011723c4;
extern unsigned DAT_011723c8;
extern unsigned DAT_011723d0;
extern unsigned DAT_011723d4;
extern unsigned DAT_011723dc;
extern unsigned DAT_011723e0;
extern unsigned DAT_011723e8;
extern unsigned DAT_011723ec;
extern unsigned DAT_011723f4;
extern unsigned DAT_011723f8;
extern unsigned DAT_01172f68;
extern unsigned DAT_01172f6c;
extern unsigned DAT_01172f74;
extern unsigned DAT_01172f78;
extern unsigned DAT_01172f80;
extern unsigned DAT_01172f84;
extern unsigned DAT_01172f8c;
extern unsigned DAT_01172f90;
extern unsigned DAT_01172f98;
extern unsigned DAT_01172f9c;
extern unsigned DAT_01172fa4;
extern unsigned DAT_01172fa8;
extern unsigned DAT_01172fb0;
extern unsigned DAT_01172fb4;
extern unsigned DAT_01172fbc;
extern unsigned DAT_01172fc0;
extern unsigned DAT_01172fc8;
extern unsigned DAT_01172fcc;
extern unsigned DAT_01172fd4;
extern unsigned DAT_01172fd8;

// pdb: ShadowLightShader::PresetSpecularPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, objrun, medium
void FUN_00b7b590() {
    NiPointer<PassRef> pass;
    NiPointer<StageRef> stage;

    pass = DAT_011742e0;
    if (pass->GetStageCount() < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c7c;
    pass->pixelShader = DAT_01173944;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f68 = 1152;
    DAT_01172388 = 0x28;

    pass = DAT_011742e4;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c7c;
    pass->pixelShader = DAT_01173948;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f6c = 1152;
    DAT_0117238c = 0x28;

    pass = DAT_011742ec;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c80;
    pass->pixelShader = DAT_01173944;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f74 = 3200;
    DAT_01172394 = 0x28;

    pass = DAT_011742f0;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c80;
    pass->pixelShader = DAT_01173948;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f78 = 3200;
    DAT_01172398 = 0x28;

    pass = DAT_011742f8;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c84;
    pass->pixelShader = DAT_0117394c;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f80 = 0x4f0;
    DAT_011723a0 = 0x28;
    DAT_011717c0 = 96;

    pass = DAT_011742fc;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c84;
    pass->pixelShader = DAT_01173950;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f84 = 0x4f0;
    DAT_011723a4 = 0x28;
    DAT_011717c0 = 96;

    pass = DAT_01174304;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c88;
    pass->pixelShader = DAT_0117394c;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f8c = 3312;
    DAT_011723ac = 0x28;
    DAT_011717cc = 0x60;

    pass = DAT_01174308;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c88;
    pass->pixelShader = DAT_01173950;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f90 = 3312;
    DAT_011723b0 = 0x28;
    DAT_011717cc = 0x60;

    pass = DAT_01174310;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c8c;
    pass->pixelShader = DAT_01173954;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f98 = 0x480;
    DAT_011723b8 = 0x28;

    pass = DAT_01174314;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c8c;
    pass->pixelShader = DAT_01173958;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172f9c = 0x480;
    DAT_011723bc = 0x28;

    pass = DAT_0117431c;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c90;
    pass->pixelShader = DAT_01173954;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fa4 = 0xc80;
    DAT_011723c4 = 0x28;

    pass = DAT_01174320;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c90;
    pass->pixelShader = DAT_01173958;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fa8 = 0xc80;
    DAT_011723c8 = 0x28;

    pass = DAT_01174328;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c94;
    pass->pixelShader = DAT_0117395c;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fb0 = 0x480;
    DAT_011723d0 = 0x28;

    pass = DAT_0117432c;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c94;
    pass->pixelShader = DAT_01173960;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fb4 = 0x480;
    DAT_011723d4 = 0x28;

    pass = DAT_01174334;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c98;
    pass->pixelShader = DAT_0117395c;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fbc = 0xc80;
    DAT_011723dc = 0x28;

    pass = DAT_01174338;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c98;
    pass->pixelShader = DAT_01173960;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fc0 = 0xc80;
    DAT_011723e0 = 0x28;

    pass = DAT_01174340;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c9c;
    pass->pixelShader = DAT_01173964;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fc8 = 0x480;
    DAT_011723e8 = 0x28;

    pass = DAT_01174344;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173c9c;
    pass->pixelShader = DAT_01173968;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fcc = 0x480;
    DAT_011723ec = 0x28;

    pass = DAT_0117434c;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->vertexShader = DAT_01173ca0;
    pass->pixelShader = DAT_01173964;
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fd4 = 3200;
    DAT_011723f4 = 40;

    pass = DAT_01174350;
    if (pass->stageCount < 6) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageIndex, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        stage->texture = DAT_0116f324;
        stage->enabled = 1;
        FUN_00b62c70(stage, 3, 3, 0, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, true);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
    }
    pass->FUN_008866f0(DAT_01173ca0);
    pass->FUN_00886650(DAT_01173968);
    pass->SetState(19, 2, true);
    pass->SetState(20, 2, true);
    DAT_01172fd8 = 3200;
    DAT_011723f8 = 40;
}
}   // namespace f3m_00b7b590

// @f3 0x00b65960 (community match, verified in this file)
namespace f3m_00b65960 {
template<class T> class PoolPtr;
struct SetupPass;
struct ShaderRef;
extern PoolPtr<SetupPass> DAT_01173f08[];
inline unsigned int AtomicAddRef(unsigned int& count) { return InterlockedIncrement((long*)&count); }
inline unsigned int AtomicDropRef(unsigned int& count) { return InterlockedDecrement((long*)&count); }

struct ShaderRef {
    virtual void Slot0();
    virtual void DeleteThis();
    unsigned int references;
    void IncRefCount() { AtomicAddRef(references); }
    void DecRefCount() { if (!AtomicDropRef(references)) DeleteThis(); }
};

template<class T> class PoolPtr {
public:
    T* object;
    PoolPtr(T* p = 0) : object(p) { if (object) object->IncRefCount(); }
    PoolPtr(const PoolPtr& p) : object(p.object) { if (object) object->IncRefCount(); }
    ~PoolPtr() { if (object) object->DecRefCount(); }
    operator T*() const { return object; }
    T* operator->() const { return object; }
    PoolPtr& operator=(const PoolPtr& p) {
        if (object != p.object) {
            if (object) object->DecRefCount();
            object = p.object;
            if (object) object->IncRefCount();
        }
        return *this;
    }
    PoolPtr& operator=(T* p) {
        if (object != p) {
            if (object) object->DecRefCount();
            object = p;
            if (object) object->IncRefCount();
        }
        return *this;
    }
};

struct SetupStage {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
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
    unsigned int references;
    void FUN_0088fe30();
    void IncRefCount() { ++references; }
    void DecRefCount() { if (--references == 0) FUN_0088fe30(); }
};
struct SetupState {
    void FUN_008905a0(unsigned int, unsigned int, bool);
};
extern SetupState* FUN_00890750();

struct SetupPass {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int currentStage;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    SetupState* states;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    PoolPtr<ShaderRef> pixel;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    PoolPtr<ShaderRef> vertex;
    unsigned int unk60;
    unsigned int references;
    void FUN_00888c10();
    void IncRefCount() { ++references; }
    void DecRefCount() { if (--references == 0) FUN_00888c10(); }
    int FUN_00888d30(unsigned int, SetupStage*);
    int AppendStage(SetupStage* s) { return FUN_00888d30(currentStage, s); }
    void FUN_008866f0(ShaderRef* p);
    void FUN_00886650(ShaderRef* p);
    unsigned int GetCurrentStage() const { return currentStage; }
    unsigned int GetStageCount() const { return stageCount; }
    void SetState(unsigned int state, unsigned int value, bool save) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(state, value, save);
    }
};
extern void FUN_0088ff50(PoolPtr<SetupStage>&);
extern void FUN_00b62c70(SetupStage*, unsigned int, unsigned int, unsigned int, bool);

extern ShaderRef* DAT_01173b30;
extern ShaderRef* DAT_011737ec;
extern unsigned int DAT_01172b90;
extern unsigned int DAT_01171fb0;

extern ShaderRef* DAT_01173b38;
extern ShaderRef* DAT_011737fc;
extern unsigned int DAT_01172b94;
extern unsigned int DAT_01171fb4;

extern ShaderRef* DAT_01173b34;
extern ShaderRef* DAT_011737f0;
extern unsigned int DAT_01172bfc;
extern unsigned int DAT_0117201c;
extern unsigned int DAT_0117143c;

extern ShaderRef* DAT_01173b3c;
extern ShaderRef* DAT_01173800;
extern unsigned int DAT_01172c00;
extern unsigned int DAT_01172020;
extern unsigned int DAT_01171440;

extern ShaderRef* DAT_0117381c;
extern unsigned int DAT_01172b98;
extern unsigned int DAT_01171fb8;
extern unsigned int DAT_011707f8;

extern ShaderRef* DAT_0117382c;
extern unsigned int DAT_01172b9c;
extern unsigned int DAT_01171fbc;
extern unsigned int DAT_011707fc;

extern ShaderRef* DAT_01173820;
extern unsigned int DAT_01172c04;
extern unsigned int DAT_01172024;
extern unsigned int DAT_01171444;

extern ShaderRef* DAT_01173830;
extern unsigned int DAT_01172c08;
extern unsigned int DAT_01172028;
extern unsigned int DAT_01171448;

extern ShaderRef* DAT_01173b40;
extern ShaderRef* DAT_0117380c;
extern unsigned int DAT_01172ba0;
extern unsigned int DAT_01171fc0;

extern ShaderRef* DAT_011737f4;
extern unsigned int DAT_01172ba4;
extern unsigned int DAT_01171fc4;

extern ShaderRef* DAT_01173804;
extern unsigned int DAT_01172ba8;
extern unsigned int DAT_01171fc8;

extern ShaderRef* DAT_011737f8;
extern unsigned int DAT_01172c0c;
extern unsigned int DAT_0117202c;
extern unsigned int DAT_0117144c;

extern ShaderRef* DAT_01173808;
extern unsigned int DAT_01172c10;
extern unsigned int DAT_01172030;
extern unsigned int DAT_01171450;

extern ShaderRef* DAT_01173824;
extern unsigned int DAT_01172bac;
extern unsigned int DAT_01171fcc;
extern unsigned int DAT_0117080c;

extern ShaderRef* DAT_01173834;
extern unsigned int DAT_01172bb0;
extern unsigned int DAT_01171fd0;
extern unsigned int DAT_01170810;

extern ShaderRef* DAT_01173b44;
extern ShaderRef* DAT_01173810;
extern unsigned int DAT_01172c14;
extern unsigned int DAT_01172034;
extern unsigned int DAT_01171454;

extern ShaderRef* DAT_01173814;
extern unsigned int DAT_01172bb4;
extern unsigned int DAT_01171fd4;



extern ShaderRef* DAT_01173bac;
extern unsigned int DAT_01172bbc;
extern unsigned int DAT_01171fdc;

extern ShaderRef* DAT_01173bb0;
extern unsigned int DAT_01172bc0;
extern unsigned int DAT_01171fe0;

extern ShaderRef* DAT_01173bb4;
extern unsigned int DAT_01172c24;
extern unsigned int DAT_01172044;
extern unsigned int DAT_01171464;

extern ShaderRef* DAT_01173bb8;
extern unsigned int DAT_01172c28;
extern unsigned int DAT_01172048;
extern unsigned int DAT_01171468;

extern unsigned int DAT_01172bc4;
extern unsigned int DAT_01171fe4;
extern unsigned int DAT_01170824;

extern unsigned int DAT_01172c2c;
extern unsigned int DAT_0117204c;
extern unsigned int DAT_0117146c;
extern unsigned int DAT_0117088c;


extern ShaderRef* DAT_01173bbc;
extern unsigned int DAT_01172bcc;
extern unsigned int DAT_01171fec;

extern ShaderRef* DAT_01173bc0;
extern unsigned int DAT_01172c3c;
extern unsigned int DAT_0117205c;
extern unsigned int DAT_0117147c;

extern unsigned int DAT_01172bd0;
extern unsigned int DAT_01171ff0;

extern unsigned int DAT_01172bd4;
extern unsigned int DAT_01171ff4;

extern unsigned int DAT_01172c34;
extern unsigned int DAT_01172054;
extern unsigned int DAT_01171474;

extern unsigned int DAT_01172c38;
extern unsigned int DAT_01172058;
extern unsigned int DAT_01171478;

extern unsigned int DAT_01172bd8;
extern unsigned int DAT_01171ff8;
extern unsigned int DAT_01170838;

extern unsigned int DAT_01172bdc;
extern unsigned int DAT_01171ffc;
extern unsigned int DAT_0117083c;

extern unsigned int DAT_01172be0;
extern unsigned int DAT_01172000;
extern unsigned int DAT_01170840;

extern ShaderRef* DAT_01173828;
extern unsigned int DAT_01172c40;
extern unsigned int DAT_01172060;
extern unsigned int DAT_01171480;
extern unsigned int DAT_011708a0;

extern ShaderRef* DAT_01173838;
extern unsigned int DAT_011708a4;
extern unsigned int DAT_01172c44;
extern unsigned int DAT_01172064;
extern unsigned int DAT_01171484;



void FUN_00b65960()
{
    PoolPtr<SetupPass> pass;
    PoolPtr<SetupStage> stage;
    pass = DAT_01173f08[0];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b30;
    pass->pixel = DAT_011737ec;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172b90 = 128;
    DAT_01171fb0 = 12;

    pass = DAT_01173f08[1];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b38;
    pass->pixel = DAT_011737fc;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172b94 = 128;
    DAT_01171fb4 = 12;

    pass = DAT_01173f08[27];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b34;
    pass->pixel = DAT_011737f0;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bfc = 896;
    DAT_0117201c = 12;
    DAT_0117143c = 768;

    pass = DAT_01173f08[28];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b3c;
    pass->pixel = DAT_01173800;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c00 = 896;
    DAT_01172020 = 12;
    DAT_01171440 = 768;

    pass = DAT_01173f08[2];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b30;
    pass->pixel = DAT_0117381c;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172b98 = 128;
    DAT_01171fb8 = 28;
    DAT_011707f8 = 4;

    pass = DAT_01173f08[3];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b38;
    pass->pixel = DAT_0117382c;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172b9c = 128;
    DAT_01171fbc = 28;
    DAT_011707fc = 4;

    pass = DAT_01173f08[29];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b34;
    pass->pixel = DAT_01173820;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c04 = 896;
    DAT_01172024 = 12;
    DAT_01171444 = 768;

    pass = DAT_01173f08[30];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b3c;
    pass->pixel = DAT_01173830;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c08 = 896;
    DAT_01172028 = 12;
    DAT_01171448 = 768;

    pass = DAT_01173f08[4];
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b40;
    pass->pixel = DAT_0117380c;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172ba0 = 128;
    DAT_01171fc0 = 12;

    pass = DAT_01173f08[5];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b30;
    pass->pixel = DAT_011737f4;
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172ba4 = 128;
    DAT_01171fc4 = 12;

    pass = DAT_01173f08[6];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b38;
    pass->pixel = DAT_01173804;
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172ba8 = 128;
    DAT_01171fc8 = 12;

    pass = DAT_01173f08[31];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b34;
    pass->pixel = DAT_011737f8;
    pass->SetState(27, 0, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c0c = 896;
    DAT_0117202c = 12;
    DAT_0117144c = 768;

    pass = DAT_01173f08[32];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b3c;
    pass->pixel = DAT_01173808;
    pass->SetState(27, 0, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c10 = 896;
    DAT_01172030 = 12;
    DAT_01171450 = 768;

    pass = DAT_01173f08[7];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b30;
    pass->pixel = DAT_01173824;
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bac = 128;
    DAT_01171fcc = 28;
    DAT_0117080c = 4;

    pass = DAT_01173f08[8];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->vertex = DAT_01173b38;
    pass->FUN_00886650(DAT_01173834);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bb0 = 128;
    DAT_01171fd0 = 28;
    DAT_01170810 = 4;

    pass = DAT_01173f08[33];
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173b44);
    pass->FUN_00886650(DAT_01173810);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c14 = 896;
    DAT_01172034 = 12;
    DAT_01171454 = 768;

    pass = DAT_01173f08[9];
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173b40);
    pass->FUN_00886650(DAT_01173814);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bb4 = 128;
    DAT_01171fd4 = 12;
    DAT_01173f08[10] = (SetupPass*)0;
    DAT_01173f08[36] = (SetupPass*)0;

    pass = DAT_01173f08[11];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bac);
    pass->FUN_00886650(DAT_011737ec);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bbc = 2176;
    DAT_01171fdc = 12;

    pass = DAT_01173f08[12];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb0);
    pass->FUN_00886650(DAT_011737fc);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bc0 = 2176;
    DAT_01171fe0 = 12;

    pass = DAT_01173f08[37];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb4);
    pass->FUN_00886650(DAT_011737f0);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c24 = 2944;
    DAT_01172044 = 12;
    DAT_01171464 = 768;

    pass = DAT_01173f08[38];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb8);
    pass->FUN_00886650(DAT_01173800);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c28 = 2944;
    DAT_01172048 = 12;
    DAT_01171468 = 768;

    pass = DAT_01173f08[13];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bac);
    pass->FUN_00886650(DAT_0117381c);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bc4 = 2176;
    DAT_01171fe4 = 28;
    DAT_01170824 = 4;

    pass = DAT_01173f08[39];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb4);
    pass->FUN_00886650(DAT_01173820);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c2c = 2944;
    DAT_0117204c = 28;
    DAT_0117146c = 768;
    DAT_0117088c = 4;

    pass = DAT_01173f08[40];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb8);
    pass->FUN_00886650(DAT_01173830);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c2c = 2944;
    DAT_0117204c = 28;
    DAT_0117146c = 768;
    DAT_0117088c = 4;

    pass = DAT_01173f08[15];
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bbc);
    pass->FUN_00886650(DAT_0117380c);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bcc = 2176;
    DAT_01171fec = 12;

    pass = DAT_01173f08[43];
    if (pass->GetStageCount() < 4) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bc0);
    pass->FUN_00886650(DAT_01173810);
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c3c = 2944;
    DAT_0117205c = 12;
    DAT_0117147c = 768;

    pass = DAT_01173f08[16];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bac);
    pass->FUN_00886650(DAT_011737f4);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bd0 = 2176;
    DAT_01171ff0 = 12;

    pass = DAT_01173f08[17];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb0);
    pass->FUN_00886650(DAT_01173804);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bd4 = 2176;
    DAT_01171ff4 = 12;

    pass = DAT_01173f08[41];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb4);
    pass->FUN_00886650(DAT_011737f8);
    pass->SetState(27, 0, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c34 = 2944;
    DAT_01172054 = 12;
    DAT_01171474 = 768;

    pass = DAT_01173f08[42];
    if (pass->GetStageCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb8);
    pass->FUN_00886650(DAT_01173808);
    pass->SetState(27, 0, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c38 = 2944;
    DAT_01172058 = 12;
    DAT_01171478 = 768;

    pass = DAT_01173f08[18];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bac);
    pass->FUN_00886650(DAT_01173824);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bd8 = 2176;
    DAT_01171ff8 = 28;
    DAT_01170838 = 4;

    pass = DAT_01173f08[19];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb0);
    pass->FUN_00886650(DAT_01173834);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172bdc = 2176;
    DAT_01171ffc = 28;
    DAT_0117083c = 4;

    pass = DAT_01173f08[20];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bbc);
    pass->FUN_00886650(DAT_01173814);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172be0 = 2176;
    DAT_01172000 = 12;
    DAT_01170840 = 4;

    pass = DAT_01173f08[44];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb4);
    pass->FUN_00886650(DAT_01173828);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c40 = 2944;
    DAT_01172060 = 28;
    DAT_01171480 = 768;
    DAT_011708a0 = 4;

    pass = DAT_01173f08[45];
    if (pass->GetStageCount() < 3) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->AppendStage(stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->AppendStage(stage);
    }
    pass->FUN_008866f0(DAT_01173bb8);
    pass->FUN_00886650(DAT_01173838);
    pass->SetState(27, 1, true);
    pass->SetState(19, 5, true);
    pass->SetState(20, 6, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    DAT_01172c44 = 2944;
    DAT_01172064 = 28;
    DAT_01171484 = 768;
    DAT_011708a4 = 4;
    DAT_01173f08[21] = (SetupPass*)0;
    DAT_01173f08[46] = (SetupPass*)0;
}
}   // namespace f3m_00b65960

// @f3 0x00b6dcc0 (community match, verified in this file)
namespace f3m_00b6dcc0 {
struct ShaderConstantMap {
    virtual void Unused();
    virtual void DeleteThis();
    long refs;
    void IncRefCount();
    void DecRefCount();
};
typedef ShaderConstantMap ShaderProgram;
extern int (__stdcall *DAT_00fdf1c4)(void*);
extern int (__stdcall *DAT_00fdf1c0)(void*);
inline void ShaderConstantMap::IncRefCount() { InterlockedIncrement(&refs); }
inline void ShaderConstantMap::DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
struct TextureStage {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int textureFlags;
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
    unsigned int refs;
    void FUN_0088fe30();
    void FUN_0088f050(unsigned int mode);
    void IncRefCount() { ++refs; }
    void DecRefCount() { if (!--refs) FUN_0088fe30(); }
};
struct RenderStates {
    void FUN_008905a0(unsigned int key, unsigned int value, bool save);
};
extern "C" RenderStates* __cdecl FUN_00890750();
struct ShaderPass {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int stageIndex;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStates* states;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    NiPointer<ShaderConstantMap> pixelConstants;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<ShaderConstantMap> vertexConstants;
    unsigned int unk60;
    unsigned int refs;
    void FUN_00888d30(unsigned int index, TextureStage* stage);
    void FUN_008866f0(ShaderProgram* program);
    void FUN_00886650(ShaderProgram* program);
    void FUN_00888c10();
    void IncRefCount() { ++refs; }
    void DecRefCount() { if (!--refs) FUN_00888c10(); }
    unsigned int Count() const { return stageCount; }
    void SetState(unsigned int key, unsigned int value, bool save) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(key, value, save);
    }
};
extern "C" void __cdecl FUN_0088ff50(NiPointer<TextureStage>& stage);
extern "C" void __cdecl FUN_00b62c70(TextureStage* stage, unsigned int index, unsigned int color, unsigned int alpha, bool enabled);
struct PassPointer {
    ShaderPass* m_pObject;
    PassPointer(ShaderPass* object = 0) {
        m_pObject = object;
        if (m_pObject) m_pObject->IncRefCount();
    }
    PassPointer(const PassPointer& other) {
        m_pObject = other.m_pObject;
        if (m_pObject) m_pObject->IncRefCount();
    }
    ~PassPointer() { if (m_pObject) m_pObject->DecRefCount(); }
    ShaderPass* operator->() const { return m_pObject; }
    operator ShaderPass*() const { return m_pObject; }
    PassPointer& operator=(const PassPointer& other) {
        if (m_pObject != other.m_pObject) {
            if (m_pObject) m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject) m_pObject->IncRefCount();
        }
        return *this;
    }
    __declspec(noinline) PassPointer& FUN_00888ea0(const PassPointer& other) {
        return *this = other;
    }
};
extern unsigned int DAT_0106ab70;
extern unsigned int DAT_0116f324;
extern unsigned int DAT_01170a4c;
extern unsigned int DAT_01170a50;
extern unsigned int DAT_01170a54;
extern unsigned int DAT_01170a58;
extern unsigned int DAT_01170a5c;
extern unsigned int DAT_01170a70;
extern unsigned int DAT_01170a78;
extern unsigned int DAT_01170a84;
extern unsigned int DAT_01170a88;
extern unsigned int DAT_01170a8c;
extern unsigned int DAT_01170a90;
extern unsigned int DAT_01170aa0;
extern unsigned int DAT_01170aa4;
extern unsigned int DAT_01170aa8;
extern unsigned int DAT_01170ab4;
extern unsigned int DAT_01170ab8;
extern unsigned int DAT_01170abc;
extern unsigned int DAT_01170acc;
extern unsigned int DAT_01170ad0;
extern unsigned int DAT_01170ad4;
extern unsigned int DAT_01170ae0;
extern unsigned int DAT_01170ae4;
extern unsigned int DAT_01170ae8;
extern unsigned int DAT_01170af8;
extern unsigned int DAT_01170afc;
extern unsigned int DAT_01170b00;
extern unsigned int DAT_01170f34;
extern unsigned int DAT_0117162c;
extern unsigned int DAT_01171630;
extern unsigned int DAT_01171634;
extern unsigned int DAT_01171638;
extern unsigned int DAT_0117163c;
extern unsigned int DAT_01171650;
extern unsigned int DAT_01171654;
extern unsigned int DAT_01171658;
extern unsigned int DAT_01171664;
extern unsigned int DAT_01171668;
extern unsigned int DAT_0117166c;
extern unsigned int DAT_01171670;
extern unsigned int DAT_01171680;
extern unsigned int DAT_01171684;
extern unsigned int DAT_01171688;
extern unsigned int DAT_01171694;
extern unsigned int DAT_01171698;
extern unsigned int DAT_0117169c;
extern unsigned int DAT_011716ac;
extern unsigned int DAT_011716b0;
extern unsigned int DAT_011716b4;
extern unsigned int DAT_011716c0;
extern unsigned int DAT_011716c4;
extern unsigned int DAT_011716c8;
extern unsigned int DAT_011716d8;
extern unsigned int DAT_011716dc;
extern unsigned int DAT_011716e0;
extern unsigned int DAT_01171b14;
extern unsigned int DAT_01171e60;
extern unsigned int DAT_01171e64;
extern unsigned int DAT_01171e68;
extern unsigned int DAT_01171e6c;
extern unsigned int DAT_0117220c;
extern unsigned int DAT_01172210;
extern unsigned int DAT_01172214;
extern unsigned int DAT_01172218;
extern unsigned int DAT_0117221c;
extern unsigned int DAT_01172230;
extern unsigned int DAT_01172234;
extern unsigned int DAT_01172238;
extern unsigned int DAT_01172244;
extern unsigned int DAT_01172248;
extern unsigned int DAT_0117224c;
extern unsigned int DAT_01172250;
extern unsigned int DAT_01172260;
extern unsigned int DAT_01172264;
extern unsigned int DAT_01172268;
extern unsigned int DAT_01172274;
extern unsigned int DAT_01172278;
extern unsigned int DAT_0117227c;
extern unsigned int DAT_0117228c;
extern unsigned int DAT_01172290;
extern unsigned int DAT_01172294;
extern unsigned int DAT_011722a0;
extern unsigned int DAT_011722a4;
extern unsigned int DAT_011722a8;
extern unsigned int DAT_011722b8;
extern unsigned int DAT_011722bc;
extern unsigned int DAT_011722c0;
extern unsigned int DAT_011726f4;
extern unsigned int DAT_01172a40;
extern unsigned int DAT_01172a44;
extern unsigned int DAT_01172a48;
extern unsigned int DAT_01172a4c;
extern unsigned int DAT_01172dec;
extern unsigned int DAT_01172df0;
extern unsigned int DAT_01172df4;
extern unsigned int DAT_01172df8;
extern unsigned int DAT_01172dfc;
extern unsigned int DAT_01172e10;
extern unsigned int DAT_01172e14;
extern unsigned int DAT_01172e18;
extern unsigned int DAT_01172e24;
extern unsigned int DAT_01172e28;
extern unsigned int DAT_01172e2c;
extern unsigned int DAT_01172e30;
extern unsigned int DAT_01172e40;
extern unsigned int DAT_01172e44;
extern unsigned int DAT_01172e48;
extern unsigned int DAT_01172e54;
extern unsigned int DAT_01172e58;
extern unsigned int DAT_01172e5c;
extern unsigned int DAT_01172e6c;
extern unsigned int DAT_01172e70;
extern unsigned int DAT_01172e74;
extern unsigned int DAT_01172e80;
extern unsigned int DAT_01172e84;
extern unsigned int DAT_01172e88;
extern unsigned int DAT_01172e98;
extern unsigned int DAT_01172e9c;
extern unsigned int DAT_01172ea0;
extern unsigned int DAT_011732d4;
extern ShaderProgram* DAT_01173888;
extern ShaderConstantMap* DAT_0117388c;
extern ShaderConstantMap* DAT_01173890;
extern ShaderConstantMap* DAT_01173894;
extern ShaderProgram* DAT_01173898;
extern ShaderProgram* DAT_0117389c;
extern ShaderProgram* DAT_011738a0;
extern ShaderProgram* DAT_011738a4;
extern ShaderConstantMap* DAT_011738a8;
extern ShaderProgram* DAT_011738ac;
extern ShaderProgram* DAT_011738b0;
extern ShaderProgram* DAT_011738b4;
extern ShaderProgram* DAT_011738b8;
extern ShaderProgram* DAT_011738bc;
extern ShaderProgram* DAT_011738c0;
extern ShaderProgram* DAT_011738c4;
extern ShaderProgram* DAT_011738c8;
extern ShaderProgram* DAT_011739a0;
extern ShaderProgram* DAT_011739a4;
extern ShaderProgram* DAT_011739a8;
extern ShaderProgram* DAT_011739ac;
extern ShaderConstantMap* DAT_01173bdc;
extern ShaderConstantMap* DAT_01173be0;
extern ShaderConstantMap* DAT_01173be4;
extern ShaderProgram* DAT_01173be8;
extern ShaderProgram* DAT_01173bec;
extern ShaderProgram* DAT_01173bf0;
extern ShaderProgram* DAT_01173bf4;
extern ShaderConstantMap* DAT_01173bf8;
extern ShaderProgram* DAT_01173bfc;
extern ShaderProgram* DAT_01173c00;
extern ShaderProgram* DAT_01173c04;
extern ShaderProgram* DAT_01173c08;
extern ShaderProgram* DAT_01173cd8;
extern ShaderProgram* DAT_01173cdc;
extern ShaderProgram* DAT_01173ce0;
extern ShaderProgram* DAT_01173ce4;
extern PassPointer DAT_01173db8;
extern PassPointer DAT_01173dbc;
extern PassPointer DAT_01173dc0;
extern PassPointer DAT_01173dc4;
extern PassPointer DAT_01174164;
extern PassPointer DAT_01174168;
extern PassPointer DAT_0117416c;
extern PassPointer DAT_01174170;
extern PassPointer DAT_01174174;
extern PassPointer DAT_01174188;
extern PassPointer DAT_0117418c;
extern PassPointer DAT_01174190;
extern PassPointer DAT_0117419c;
extern PassPointer DAT_011741a0;
extern PassPointer DAT_011741a4;
extern PassPointer DAT_011741a8;
extern PassPointer DAT_011741b8;
extern PassPointer DAT_011741bc;
extern PassPointer DAT_011741c0;
extern PassPointer DAT_011741cc;
extern PassPointer DAT_011741d0;
extern PassPointer DAT_011741d4;
extern PassPointer DAT_011741e4;
extern PassPointer DAT_011741e8;
extern PassPointer DAT_011741ec;
extern PassPointer DAT_011741f8;
extern PassPointer DAT_011741fc;
extern PassPointer DAT_01174200;
extern PassPointer DAT_01174210;
extern PassPointer DAT_01174214;
extern PassPointer DAT_01174218;
extern PassPointer DAT_0117464c;

__forceinline void BuildFirst(ShaderPass* pass, NiPointer<TextureStage>& stage) {
    unsigned int count = pass->stageCount;
    if (count < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173bdc;
    pass->pixelConstants = DAT_01173888;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172dec = 896;
    DAT_0117220c = 44;
    DAT_0117162c = 768;
    DAT_01170a4c = 0;

}
// pdb: ShadowLightShader::PresetADTPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, uconst, low
void __cdecl FUN_00b6dcc0() {
    PassPointer pass;
    NiPointer<TextureStage> stage;
    pass = DAT_01174164;
    BuildFirst(pass, stage);
    pass = DAT_01174168;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173bdc;
    pass->pixelConstants = DAT_0117388c;
    DAT_01172df0 = 896;
    DAT_01172210 = 44;
    DAT_01171630 = 768;
    DAT_01170a50 = 36;
    pass = DAT_0117416c;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173be0;
    pass->pixelConstants = DAT_01173890;
    DAT_01172df4 = 896;
    DAT_01172214 = 44;
    DAT_01171634 = 768;
    DAT_01170a54 = 36;
    pass = DAT_0117464c;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 3, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 3, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173bf8;
    pass->pixelConstants = DAT_011738a8;
    pass->SetState(27, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_011732d4 = 896;
    DAT_011726f4 = 4194348;
    DAT_01171b14 = 768;
    DAT_01170f34 = 4194344;
    pass = DAT_01174170;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        stage->FUN_0088f050(0);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        stage->FUN_0088f050(0);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 1, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173be4;
    pass->pixelConstants = DAT_01173894;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172df8 = 4326276;
    DAT_01172218 = 2097196;
    DAT_01171638 = 131968;
    DAT_01170a58 = 44;
    pass = DAT_01174174;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173bdc;
    pass->pixelConstants = DAT_01173898;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172dfc = 896;
    DAT_0117221c = 60;
    DAT_0117163c = 768;
    DAT_01170a5c = 12;
    pass = DAT_01174188;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->vertexConstants = DAT_01173bdc;
    pass->pixelConstants = DAT_011738ac;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e10 = 896;
    DAT_01172230 = 60;
    DAT_01171650 = 768;
    DAT_01170a70 = 12;
    pass = DAT_0117418c;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173be8);
    pass->FUN_00886650(DAT_01173888);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e14 = 2944;
    DAT_01172234 = 44;
    DAT_01171654 = 776;
    pass = DAT_01174190;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173be8);
    pass->FUN_00886650(DAT_01173898);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e18 = 2944;
    DAT_01172238 = 60;
    DAT_01171658 = 768;
    DAT_01170a78 = 12;
    pass = DAT_0117419c;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173be8);
    pass->FUN_00886650(DAT_011738ac);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e24 = 2944;
    DAT_01172244 = 60;
    DAT_01171664 = 768;
    DAT_01170a84 = 12;
    pass = DAT_011741a0;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bec);
    pass->FUN_00886650(DAT_0117389c);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e28 = 1008;
    DAT_01172248 = 44;
    DAT_01171668 = 864;
    DAT_01170a88 = 8;
    pass = DAT_011741a4;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bf0);
    pass->FUN_00886650(DAT_011738a0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e2c = 4326384;
    DAT_0117224c = 44;
    DAT_0117166c = 131936;
    DAT_01170a8c = 8;
    pass = DAT_011741a8;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bec);
    pass->FUN_00886650(DAT_011738a4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e30 = 1008;
    DAT_01172250 = 60;
    DAT_01171670 = 864;
    DAT_01170a90 = 12;
    pass = DAT_011741b8;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bec);
    pass->FUN_00886650(DAT_011738b0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e40 = 1008;
    DAT_01172260 = 60;
    DAT_01171680 = 864;
    DAT_01170aa0 = 12;
    pass = DAT_011741bc;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bf4);
    pass->FUN_00886650(DAT_0117389c);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e44 = 3056;
    DAT_01172264 = 44;
    DAT_01171684 = 864;
    DAT_01170aa4 = 8;
    pass = DAT_011741c0;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bf4);
    pass->FUN_00886650(DAT_011738a4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e48 = 3056;
    DAT_01172268 = 60;
    DAT_01171688 = 864;
    DAT_01170aa8 = 12;
    pass = DAT_011741cc;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bf4);
    pass->FUN_00886650(DAT_011738b0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e54 = 3056;
    DAT_01172274 = 60;
    DAT_01171694 = 864;
    DAT_01170ab4 = 12;
    pass = DAT_011741d0;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bfc);
    pass->FUN_00886650(DAT_011738b4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e58 = 896;
    DAT_01172278 = 44;
    DAT_01171698 = 768;
    DAT_01170ab8 = 0;
    pass = DAT_011741d4;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bfc);
    pass->FUN_00886650(DAT_011738b8);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e5c = 896;
    DAT_0117227c = 60;
    DAT_0117169c = 768;
    DAT_01170abc = 4;
    pass = DAT_011741e4;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173bfc);
    pass->FUN_00886650(DAT_011738bc);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e6c = 896;
    DAT_0117228c = 60;
    DAT_011716ac = 768;
    DAT_01170acc = 4;
    pass = DAT_011741e8;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c00);
    pass->FUN_00886650(DAT_011738b4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e70 = 2944;
    DAT_01172290 = 44;
    DAT_011716b0 = 768;
    DAT_01170ad0 = 0;
    pass = DAT_011741ec;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c00);
    pass->FUN_00886650(DAT_011738b8);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e74 = 2944;
    DAT_01172294 = 60;
    DAT_011716b4 = 768;
    DAT_01170ad4 = 4;
    pass = DAT_011741f8;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c00);
    pass->FUN_00886650(DAT_011738bc);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e80 = 2944;
    DAT_011722a0 = 60;
    DAT_011716c0 = 768;
    DAT_01170ae0 = 4;
    pass = DAT_011741fc;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c04);
    pass->FUN_00886650(DAT_011738c0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e84 = 1008;
    DAT_011722a4 = 44;
    DAT_011716c4 = 864;
    DAT_01170ae4 = 0;
    pass = DAT_01174200;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c04);
    pass->FUN_00886650(DAT_011738c4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e88 = 1008;
    DAT_011722a8 = 60;
    DAT_011716c8 = 864;
    DAT_01170ae8 = 4;
    pass = DAT_01174210;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c04);
    pass->FUN_00886650(DAT_011738c8);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e98 = 1008;
    DAT_011722b8 = 60;
    DAT_011716d8 = 864;
    DAT_01170af8 = 4;
    pass = DAT_01174214;
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c08);
    pass->FUN_00886650(DAT_011738c0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172e9c = 3056;
    DAT_011722bc = 44;
    DAT_011716dc = 864;
    DAT_01170afc = 0;
    pass.FUN_00888ea0(DAT_01174218);
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c08);
    pass->FUN_00886650(DAT_011738c4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172ea0 = 3056;
    DAT_011722c0 = 60;
    DAT_011716e0 = 864;
    DAT_01170b00 = 4;
    pass.FUN_00888ea0(DAT_01174218);
    if (pass->Count() < 8) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, 1);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, 1);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, 1);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 1, 2, 1);
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 3, 0, 1);
        stage->texture = DAT_0116f324;
        stage->textureFlags = 1;
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 1, 2, 1);
        pass->FUN_00888d30(6, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 7, 3, 0, 1);
        pass->FUN_00888d30(7, stage);
    }
    pass->FUN_008866f0(DAT_01173c08);
    pass->FUN_00886650(DAT_011738c4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172ea0 = 3056;
    DAT_011722c0 = 60;
    DAT_011716e0 = 864;
    DAT_01170b00 = 4;
    pass.FUN_00888ea0(DAT_01173db8);
    if (pass->stageCount < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173cd8);
    pass->FUN_00886650(DAT_011739a0);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172a40 = 16512;
    DAT_01171e60 = 0;
    pass.FUN_00888ea0(DAT_01173dbc);
    if (pass->stageCount < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173cdc);
    pass->FUN_00886650(DAT_011739a4);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 1, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172a44 = 16512;
    DAT_01171e64 = 0;
    pass.FUN_00888ea0(DAT_01173dc0);
    if (pass->stageCount < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173ce0);
    pass->FUN_00886650(DAT_011739a8);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172a48 = 34944;
    DAT_01171e68 = 0;
    pass.FUN_00888ea0(DAT_01173dc4);
    if (pass->stageCount < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, 1);
        pass->FUN_00888d30(pass->stageIndex, stage);
    }
    pass->FUN_008866f0(DAT_01173ce4);
    pass->FUN_00886650(DAT_011739ac);
    pass->SetState(27, 0, 1);
    pass->SetState(15, 1, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172a4c = 34944;
    DAT_01171e6c = 0;
}
}   // namespace f3m_00b6dcc0

// @f3 0x00b78590 (community match, verified in this file)
namespace f3m_00b78590 {
struct Resource {
    virtual void unused();
    virtual void DeleteThis();
    int refs;
    void IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&refs)); }
    void DecRefCount() { if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&refs))) DeleteThis(); }
};
struct Stage {
    int unk00, unk04;
    int texture;
    int mode;
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
    int refs;
    void FUN_0088fe30();
    void IncRefCount() { ++refs; }
    void DecRefCount() { --refs; if (!refs) FUN_0088fe30(); }
};
struct States { void FUN_008905a0(unsigned int, int, int); };
extern States* FUN_00890750();
struct Pass {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int count;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    States* states;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    NiPointer<Resource> texture;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    NiPointer<Resource> shader;
    int unk60;
    int refs;
    void FUN_00888c10();
    void FUN_00888d30(unsigned int, Stage*);
    void IncRefCount() { ++refs; }
    void DecRefCount() { if (!--refs) FUN_00888c10(); }
    void SetState(unsigned int id, int value, int flag) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(id, value, flag);
    }
};
extern void FUN_0088ff50(NiPointer<Stage>&);
extern void FUN_00b62c70(Stage*, unsigned int, unsigned int, unsigned int, bool);
extern int DAT_0116f324;
extern NiPointer<Pass> DAT_011740d4;
extern Resource* DAT_01173c4c;
extern Resource* DAT_0117391c;
extern int DAT_01172d5c;
extern int DAT_0117217c;
extern int DAT_011709bc;
extern NiPointer<Pass> DAT_011740d8;
extern Resource* DAT_01173920;
extern int DAT_01172d60;
extern int DAT_01172180;
extern int DAT_011709c0;
extern NiPointer<Pass> DAT_011740e8;
extern Resource* DAT_01173c50;
extern int DAT_01172d70;
extern int DAT_01172190;
extern int DAT_011709d0;
extern NiPointer<Pass> DAT_011740ec;
extern int DAT_01172d74;
extern int DAT_01172194;
extern int DAT_011709d4;
extern NiPointer<Pass> DAT_011740f8;
extern Resource* DAT_01173c54;
extern Resource* DAT_01173924;
extern int DAT_01172d80;
extern int DAT_011721a0;
extern int DAT_011715c0;
extern int DAT_011709e0;
extern NiPointer<Pass> DAT_011740fc;
extern Resource* DAT_01173928;
extern int DAT_01172d84;
extern int DAT_011721a4;
extern int DAT_011715c4;
extern int DAT_011709e4;
extern NiPointer<Pass> DAT_0117410c;
extern Resource* DAT_01173c58;
extern int DAT_01172d94;
extern NiPointer<Pass> DAT_01174110;
extern int DAT_01172d98;
extern int DAT_011721b8;
extern int DAT_011715d8;
extern int DAT_011709f8;
extern NiPointer<Pass> DAT_0117411c;
extern Resource* DAT_01173c5c;
extern Resource* DAT_0117392c;
extern int DAT_01172da4;
extern int DAT_011721c4;
extern int DAT_01170a04;
extern NiPointer<Pass> DAT_01174120;
extern Resource* DAT_01173930;
extern int DAT_01172da8;
extern int DAT_011721c8;
extern int DAT_01170a08;
extern NiPointer<Pass> DAT_01174130;
extern Resource* DAT_01173c60;
extern int DAT_01172db8;
extern int DAT_011721d8;
extern int DAT_01170a18;
extern NiPointer<Pass> DAT_01174134;
extern int DAT_01172dbc;
extern int DAT_011721dc;
extern int DAT_01170a1c;
extern NiPointer<Pass> DAT_01174140;
extern Resource* DAT_01173c64;
extern Resource* DAT_01173934;
extern int DAT_01172dc8;
extern int DAT_011721e8;
extern int DAT_01171608;
extern int DAT_01170a28;
extern NiPointer<Pass> DAT_01174144;
extern Resource* DAT_01173938;
extern int DAT_01172dcc;
extern int DAT_011721ec;
extern int DAT_0117160c;
extern int DAT_01170a2c;
extern NiPointer<Pass> DAT_01174154;
extern Resource* DAT_01173c68;
extern int DAT_01172ddc;
extern int DAT_011721fc;
extern int DAT_0117161c;
extern int DAT_01170a3c;
extern NiPointer<Pass> DAT_01174158;
extern int DAT_01172de0;
extern int DAT_01172200;
extern int DAT_01171620;
extern int DAT_01170a40;

// pdb: ShadowLightShader::PresetADPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, objrun, medium
void FUN_00b78590() {
    NiPointer<Pass> pass;
    NiPointer<Stage> stage;
    // Pass 0
    pass = DAT_011740d4;
    unsigned int initialCount = pass->count;
    if (initialCount < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c4c;
    pass->texture = DAT_0117391c;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d5c = 0x480;
    DAT_0117217c = 0xc;
    DAT_011709bc = 0;
    // Pass 1
    pass = DAT_011740d8;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c4c;
    pass->texture = DAT_01173920;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d60 = 0x480;
    DAT_01172180 = 0x1c;
    DAT_011709c0 = 4;
    // Pass 2
    pass = DAT_011740e8;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c50;
    pass->texture = DAT_0117391c;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d70 = 0xc80;
    DAT_01172190 = 0xc;
    DAT_011709d0 = 0;
    // Pass 3
    pass = DAT_011740ec;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c50;
    pass->texture = DAT_01173920;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d74 = 0xc80;
    DAT_01172194 = 0x1c;
    DAT_011709d4 = 4;
    // Pass 4
    pass = DAT_011740f8;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c54;
    pass->texture = DAT_01173924;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d80 = 0x4f0;
    DAT_011721a0 = 0xc;
    DAT_011715c0 = 0x60;
    DAT_011709e0 = 0;
    // Pass 5
    pass = DAT_011740fc;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c54;
    pass->texture = DAT_01173928;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d84 = 0x4f0;
    DAT_011721a4 = 0x1c;
    DAT_011715c4 = 0x60;
    DAT_011709e4 = 4;
    // Pass 6
    pass = DAT_0117410c;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c58;
    pass->texture = DAT_01173924;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d94 = 0xcf0;
    DAT_011721a4 = 0xc;
    DAT_011715c4 = 0x60;
    DAT_011709e4 = 0;
    // Pass 7
    pass = DAT_01174110;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c58;
    pass->texture = DAT_01173928;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172d98 = 0xcf0;
    DAT_011721b8 = 0x1c;
    DAT_011715d8 = 0x60;
    DAT_011709f8 = 4;
    // Pass 8
    pass = DAT_0117411c;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c5c;
    pass->texture = DAT_0117392c;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172da4 = 0x480;
    DAT_011721c4 = 0xc;
    DAT_01170a04 = 0;
    // Pass 9
    pass = DAT_01174120;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c5c;
    pass->texture = DAT_01173930;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172da8 = 0x480;
    DAT_011721c8 = 0x1c;
    DAT_01170a08 = 4;
    // Pass 10
    pass = DAT_01174130;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c60;
    pass->texture = DAT_0117392c;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172db8 = 0xc80;
    DAT_011721d8 = 0xc;
    DAT_01170a18 = 0;
    // Pass 11
    pass = DAT_01174134;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c60;
    pass->texture = DAT_01173930;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172dbc = 0xc80;
    DAT_011721dc = 0x1c;
    DAT_01170a1c = 4;
    // Pass 12
    pass = DAT_01174140;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c64;
    pass->texture = DAT_01173934;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172dc8 = 0x4f0;
    DAT_011721e8 = 0xc;
    DAT_01171608 = 0x60;
    DAT_01170a28 = 0;
    // Pass 13
    pass = DAT_01174144;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c64;
    pass->texture = DAT_01173938;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172dcc = 0x4f0;
    DAT_011721ec = 0x1c;
    DAT_0117160c = 0x60;
    DAT_01170a2c = 4;
    // Pass 14
    pass = DAT_01174154;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c68;
    pass->texture = DAT_01173934;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172ddc = 0xcf0;
    DAT_011721fc = 0xc;
    DAT_0117161c = 0x60;
    DAT_01170a3c = 0;
    // Pass 15
    pass = DAT_01174158;
    if (pass->count < 7) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(0, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(1, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 2, 1, 2, true);
        pass->FUN_00888d30(2, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 3, 1, 2, true);
        pass->FUN_00888d30(3, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 4, 3, 0, true);
        stage->texture = DAT_0116f324;
        stage->mode = 1;
        pass->FUN_00888d30(4, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 5, 1, 2, true);
        pass->FUN_00888d30(5, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 6, 3, 0, true);
        pass->FUN_00888d30(6, stage);
    }
    pass->shader = DAT_01173c68;
    pass->texture = DAT_01173938;
    pass->SetState(27, 0, 1);
    pass->SetState(15, 0, 1);
    pass->SetState(7, 1, 1);
    pass->SetState(23, 4, 1);
    pass->SetState(14, 1, 1);
    DAT_01172de0 = 0xcf0;
    DAT_01172200 = 0x1c;
    DAT_01171620 = 0x60;
    DAT_01170a40 = 4;
}
}   // namespace f3m_00b78590

// @f3 0x00b64220 (community match, verified in this file)
namespace f3m_00b64220 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ProgramObject {
    virtual ~ProgramObject();
    virtual void DeleteThis();
    long refs;
    void IncRef() { InterlockedIncrement(&refs); }
    void DecRef() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
template<class T> struct ProgramPtr {
    T* p;
    ProgramPtr& operator=(T* q) {
        if (p != q) {
            if (p) p->DecRef();
            p = q;
            if (p) p->IncRef();
        }
        return *this;
    }
};
struct RenderStates { void FUN_008905a0(unsigned state, unsigned value, bool save); };
extern RenderStates* __cdecl FUN_00890750();
struct TextureStage {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned refs;
    void FUN_0088fe30();
    void IncRef() { ++refs; }
    void DecRef() { --refs; if (!refs) FUN_0088fe30(); }
};
struct ShaderPass {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    void* stageList;
    unsigned stageCount;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    RenderStates* states;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    ProgramPtr<ProgramObject> vertex;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    ProgramPtr<ProgramObject> pixel;
    unsigned unk60;
    unsigned refs;
    unsigned GetCount() const { return stageCount; }
    void FUN_00888c10();
    void FUN_00888d30(void* list, TextureStage* stage);
    void IncRef() { ++refs; }
    void DecRef() { if (!--refs) FUN_00888c10(); }
    void SetState(unsigned state, unsigned value, bool save) {
        if (!states) states = FUN_00890750();
        states->FUN_008905a0(state, value, save);
    }
};
template<class T> struct OwnerPtr {
    T* p;
    OwnerPtr() : p(0) {}
    ~OwnerPtr() { if (p) p->DecRef(); }
    OwnerPtr& operator=(T* const& q) {
        if (p != q) {
            if (p) p->DecRef();
            p = q;
            if (p) p->IncRef();
        }
        return *this;
    }
    T* operator->() { return p; }
    operator T*() { return p; }
};
extern void __cdecl FUN_0088ff50(OwnerPtr<TextureStage>& stage);
extern void __cdecl FUN_00b62c70(TextureStage*, unsigned, unsigned, unsigned, bool);
extern unsigned DAT_011706b0;
extern unsigned DAT_011706b4;
extern unsigned DAT_011707c4;
extern unsigned DAT_011707cc;
extern unsigned DAT_011707d4;
extern unsigned DAT_011707dc;
extern unsigned DAT_011711b8;
extern unsigned DAT_011711bc;
extern unsigned DAT_011713c4;
extern unsigned DAT_01171e44;
extern unsigned DAT_01171e70;
extern unsigned DAT_01171e74;
extern unsigned DAT_01171f80;
extern unsigned DAT_01171f84;
extern unsigned DAT_01171f88;
extern unsigned DAT_01171f8c;
extern unsigned DAT_01171f90;
extern unsigned DAT_01171f94;
extern unsigned DAT_01171f98;
extern unsigned DAT_01171f9c;
extern unsigned DAT_01171fa4;
extern unsigned DAT_01171fa8;
extern unsigned DAT_01171fac;
extern unsigned DAT_01172978;
extern unsigned DAT_0117297c;
extern unsigned DAT_01172a24;
extern unsigned DAT_01172a50;
extern unsigned DAT_01172a54;
extern unsigned DAT_01172b60;
extern unsigned DAT_01172b64;
extern unsigned DAT_01172b68;
extern unsigned DAT_01172b6c;
extern unsigned DAT_01172b70;
extern unsigned DAT_01172b74;
extern unsigned DAT_01172b78;
extern unsigned DAT_01172b7c;
extern unsigned DAT_01172b84;
extern unsigned DAT_01172b88;
extern unsigned DAT_01172b8c;
extern unsigned DAT_01173558;
extern unsigned DAT_0117355c;
extern ProgramObject* DAT_011737c8;
extern ProgramObject* DAT_01173858;
extern ProgramObject* DAT_0117385c;
extern ProgramObject* DAT_01173860;
extern ProgramObject* DAT_01173adc;
extern ProgramObject* DAT_01173ae0;
extern ProgramObject* DAT_01173ae4;
extern ProgramObject* DAT_01173b08;
extern ProgramObject* DAT_01173b4c;
extern ProgramObject* DAT_01173b68;
extern ProgramObject* DAT_01173b84;
extern ProgramObject* DAT_01173bd4;
extern ProgramObject* DAT_01173be4;
extern ProgramObject* DAT_01173d74;
extern ShaderPass* DAT_01173d9c;
extern ShaderPass* DAT_01173dc8;
extern ShaderPass* DAT_01173dcc;
extern ShaderPass* DAT_01173ed8;
extern ShaderPass* DAT_01173edc;
extern ShaderPass* DAT_01173ee0;
extern ShaderPass* DAT_01173ee4;
extern ShaderPass* DAT_01173ee8;
extern ShaderPass* DAT_01173eec;
extern ShaderPass* DAT_01173ef0;
extern ShaderPass* DAT_01173ef4;
extern ShaderPass* DAT_01173efc;
extern ShaderPass* DAT_01173f00;
extern ShaderPass* DAT_01173f04;
extern ShaderPass* DAT_011748d0;
extern ShaderPass* DAT_011748d4;

void __cdecl FUN_00b64220() {
    OwnerPtr<ShaderPass> pass;
    OwnerPtr<TextureStage> stage;
    // Pass 1
    pass = DAT_01173d9c;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b08;
    pass->vertex = DAT_011737c8;
    pass->SetState(27, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 2, true);
    pass->SetState(14, 0, true);
    pass->SetState(22, 1, true);
    // Pass 2
    DAT_01172a24 = 0x800;
    DAT_01171e44 = 4;
    pass = DAT_01173ed8;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b08;
    pass->vertex = DAT_011737c8;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 3
    DAT_01172b60 = 0;
    DAT_01171f80 = 4;
    pass = DAT_01173efc;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173be4;
    pass->vertex = DAT_01173adc;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 4
    DAT_01172b84 = 0x420304;
    DAT_01171fa4 = 4;
    DAT_011713c4 = 0x20304;
    pass = DAT_01173f00;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b4c;
    pass->vertex = DAT_01173ae0;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 5
    DAT_01172b88 = 0x300;
    DAT_01171fa8 = 4;
    pass = DAT_01173f04;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173d74;
    pass->vertex = DAT_01173ae4;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 6
    DAT_01172b8c = 0x300;
    DAT_01171fac = 4;
    pass = DAT_01173edc;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b68;
    pass->vertex = DAT_01173858;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 7
    DAT_01172b64 = 0;
    DAT_01171f84 = 0x14;
    DAT_011707c4 = 4;
    pass = DAT_01173ee0;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b08;
    pass->vertex = DAT_011737c8;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 8
    DAT_01172b68 = 0;
    DAT_01171f88 = 4;
    pass = DAT_01173ee4;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b68;
    pass->vertex = DAT_01173858;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 9
    DAT_01172b6c = 0;
    DAT_01171f8c = 0x14;
    DAT_011707cc = 4;
    pass = DAT_01173ee8;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b84;
    pass->vertex = DAT_011737c8;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 10
    DAT_01172b70 = 0x800;
    DAT_01171f90 = 4;
    pass = DAT_01173eec;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173bd4;
    pass->vertex = DAT_01173858;
    pass->SetState(27, 0, true);
    pass->SetState(15, 0, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 11
    DAT_01172b74 = 0x800;
    DAT_01171f94 = 0x14;
    DAT_011707d4 = 4;
    pass = DAT_01173ef0;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b84;
    pass->vertex = DAT_011737c8;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 12
    DAT_01172b78 = 0x800;
    DAT_01171f98 = 4;
    pass = DAT_01173ef4;
    if (pass->GetCount() < 2) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 1, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173bd4;
    pass->vertex = DAT_01173858;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 1, true);
    // Pass 13
    DAT_01172b7c = 0x800;
    DAT_01171f9c = 0x14;
    DAT_011707dc = 4;
    pass = DAT_011748d0;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173b68;
    pass->vertex = DAT_0117385c;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 0, true);
    // Pass 14
    DAT_01173558 = 0;
    DAT_01172978 = 0x14;
    DAT_011711b8 = 4;
    pass = DAT_011748d4;
    if (pass->GetCount() < 1) {
        FUN_0088ff50(stage);
        FUN_00b62c70(stage, 0, 1, 2, true);
        pass->FUN_00888d30(pass->stageList, stage);
    }
    pass->pixel = DAT_01173bd4;
    pass->vertex = DAT_0117385c;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 0, true);
    // Pass 15
    DAT_0117355c = 0x800;
    DAT_0117297c = 0x14;
    DAT_011711bc = 4;
    pass = DAT_01173dc8;
    pass->pixel = DAT_01173b68;
    pass->vertex = DAT_01173860;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 0, true);
    // Pass 16
    DAT_01172a50 = 0;
    DAT_01171e70 = 0x14;
    DAT_011706b0 = 4;
    pass = DAT_01173dcc;
    pass->pixel = DAT_01173bd4;
    pass->vertex = DAT_01173860;
    pass->SetState(27, 0, true);
    pass->SetState(15, 1, true);
    pass->SetState(7, 1, true);
    pass->SetState(23, 4, true);
    pass->SetState(14, 0, true);
    DAT_01172a54 = 0x800;
    DAT_01171e74 = 0x14;
    DAT_011706b4 = 4;
}
}   // namespace f3m_00b64220

// @f3 0x00b7ae40 (community match, verified in this file)
namespace f3m_00b7ae40 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void FUN_008905a0(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void FUN_00888d30(unsigned int device, unsigned int value);
    void FUN_00888c10();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            FUN_0088fe30();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00888c10();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};

extern GraphicsSystem* DAT_01174240;
extern unsigned int DAT_0116f324;
extern GraphicsResource* DAT_01173c6c;
extern GraphicsResource* DAT_0117393c;
extern GraphicsSystem* DAT_0117424c;
extern unsigned int DAT_01172ec8;
extern unsigned int DAT_011722e8;
extern GraphicsResource* DAT_01173c70;
extern GraphicsSystem* DAT_01174270;
extern unsigned int DAT_01172ed4;
extern unsigned int DAT_011722f4;
extern GraphicsResource* DAT_01173c74;
extern GraphicsResource* DAT_01173940;
extern GraphicsSystem* DAT_0117427c;
extern unsigned int DAT_01172ef8;
extern unsigned int DAT_01172318;
extern GraphicsResource* DAT_01173c78;
extern unsigned int DAT_01172f04;
extern unsigned int DAT_01172324;
extern "C" void __cdecl FUN_0088ff50(ScopedTemporary*);
extern "C" void __cdecl FUN_00b62c70(TemporaryResource*, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" GraphicsManager* __cdecl FUN_00890750();
struct GraphicsSetup { void FUN_00b7ae40(); };
// @fnv 0x00bf8f70
// pdb: ShadowLightShader::PresetDiffusePtPasses_2x | ShadowLightShader_Preset_2x.obj | fnv360_0822_retail, objrun, medium
void GraphicsSetup::FUN_00b7ae40()
{
    ScopedSystem system;
    ScopedTemporary temporary;
    system.resetFromGlobal(DAT_01174240);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(0, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(1, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(2, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        temporary.ptr->unk08 = DAT_0116f324;
        temporary.ptr->unk0c = 1;
        FUN_00b62c70(temporary.ptr, 3, 3, 0, 1);
        system->FUN_00888d30(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173c6c;
    system->material44 = DAT_0117393c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172ec8 = 128;
    DAT_011722e8 = 8;
    system.resetFromGlobal(DAT_0117424c);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(0, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(1, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(2, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        temporary.ptr->unk08 = DAT_0116f324;
        temporary.ptr->unk0c = 1;
        FUN_00b62c70(temporary.ptr, 3, 3, 0, 1);
        system->FUN_00888d30(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173c70;
    system->material44 = DAT_0117393c;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172ed4 = 2176;
    DAT_011722f4 = 8;
    system.resetFromGlobal(DAT_01174270);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(0, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(1, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(2, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        temporary.ptr->unk08 = DAT_0116f324;
        temporary.ptr->unk0c = 1;
        FUN_00b62c70(temporary.ptr, 3, 3, 0, 1);
        system->FUN_00888d30(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173c74;
    system->material44 = DAT_01173940;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172ef8 = 128;
    DAT_01172318 = 8;
    system.resetFromGlobal(DAT_0117427c);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(0, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 1, 1, 2, 1);
        system->FUN_00888d30(1, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        FUN_00b62c70(temporary.ptr, 2, 1, 2, 1);
        system->FUN_00888d30(2, reinterpret_cast<unsigned int>(temporary.ptr));
        FUN_0088ff50(&temporary);
        temporary.ptr->unk08 = DAT_0116f324;
        FUN_00b62c70(temporary.ptr, 3, 3, 0, 1);
        system->FUN_00888d30(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_01173c78;
    system->material44 = DAT_01173940;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172f04 = 2176;
    DAT_01172324 = 8;
}
}   // namespace f3m_00b7ae40

// @f3 0x00b69860 (community match, verified in this file)
namespace f3m_00b69860 {
struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void FUN_008905a0(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void FUN_00888d30(unsigned int device, unsigned int value);
    void FUN_00888c10();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void FUN_0088fe30();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            FUN_0088fe30();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00888c10();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00888c10();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};
extern "C" void __cdecl FUN_0088ff50(ScopedTemporary* out);
extern "C" void __cdecl FUN_00b62c70(TemporaryResource*, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" GraphicsManager* __cdecl FUN_00890750();
extern GraphicsSystem* DAT_01174228;
extern GraphicsSystem* DAT_01174230;
extern GraphicsSystem* DAT_0117422c;
extern GraphicsSystem* DAT_01174234;
extern GraphicsResource* DAT_01173b18;
extern GraphicsResource* DAT_01173b94;
extern GraphicsResource* DAT_01173b14;
extern GraphicsResource* DAT_01173b90;
extern GraphicsResource* DAT_011737d0;
extern GraphicsResource* DAT_011737cc;
extern unsigned int DAT_01172eb0;
extern unsigned int DAT_01172eb8;
extern unsigned int DAT_01172eb4;
extern unsigned int DAT_01172ebc;
extern unsigned int DAT_011722d0;
extern unsigned int DAT_011722d8;
extern unsigned int DAT_011722d4;
extern unsigned int DAT_011722dc;
extern unsigned int DAT_01170b10;
extern unsigned int DAT_01170b18;
extern unsigned int DAT_01170b14;
extern unsigned int DAT_01170b1c;
extern unsigned int DAT_0116f324;
extern unsigned int DAT_0116f328;
extern unsigned int DAT_0116f2fc;
// @fnv 0x00be78e0
// pdb: ShadowLightShader::PresetZOnlyPasses_1x | ShadowLightShader_Preset_1x.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void __cdecl FUN_00b69860()
{
    ScopedSystem system;
    ScopedTemporary temp;
    system.resetFromGlobal(DAT_01174228);
    if (system->GetVersion() < 1)
    {
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_01173b18;
    system->material44 = DAT_011737d0;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172eb0 = 128;
    DAT_011722d0 = 8;
    DAT_01170b10 = 8;
    system.resetFromGlobal(DAT_01174230);
    if (system->GetVersion() < 1)
    {
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_01173b94;
    system->material44 = DAT_011737d0;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172eb8 = 2176;
    DAT_011722d8 = 8;
    DAT_01170b18 = 8;
    system.resetFromGlobal(DAT_0117422c);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 1, 3, 2, 1);
        temp.ptr->unk08 = DAT_0116f324;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 2, 3, 2, 1);
        temp.ptr->unk08 = DAT_0116f328;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 3, 1, 2, 1);
        temp.ptr->unk08 = DAT_0116f2fc;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_01173b14;
    system->material44 = DAT_011737cc;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172eb4 = 128;
    DAT_011722d4 = 8;
    DAT_01170b14 = 8;
    system.resetFromGlobal(DAT_01174234);
    if (system->GetVersion() < 4)
    {
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 0, 1, 2, 1);
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 1, 3, 2, 1);
        temp.ptr->unk08 = DAT_0116f324;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 2, 3, 2, 1);
        temp.ptr->unk08 = DAT_0116f328;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
        FUN_0088ff50(&temp);
        FUN_00b62c70(temp.ptr, 3, 1, 2, 1);
        temp.ptr->unk08 = DAT_0116f2fc;
        system->FUN_00888d30(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_01173b90;
    system->material44 = DAT_011737cc;
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00890750();
    system->manager30->FUN_008905a0(20, 2, 1);
    DAT_01172ebc = 2176;
    DAT_011722dc = 8;
    DAT_01170b1c = 8;
}
}   // namespace f3m_00b69860

// @f3 0x00b61a20 (community match, verified in this file)
namespace nativeB61A20 {
struct RuntimeType {const char* name;const RuntimeType* parent;};
struct NiColor;
struct PGeom;
struct PLight;
struct PRenderer;
struct PSceneColors;
struct PNode;
struct NiColor
{
    float r, g, b;
    bool FUN_00914770(const NiColor&);
    bool FUN_00914730(const NiColor&);
};
extern NiColor DAT_0108f450;
struct PAlpha
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    unsigned short flags;
    unsigned short extra;
    unsigned char GetMode() const
    {
        return (flags >> 9) & 1;
    }
};
struct PData
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
    void* value;
    int unk02c;
};
struct PMaterial
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
    NiColor color;
    NiColor* alternate;
};
struct PGeom
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
    PAlpha* alpha;
    int unk0a0;
    PMaterial* material;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    PData* data;
    int unk0bc;
    PAlpha* FUN_00826590(unsigned int);
};
struct PLight
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
    bool special;
    char bED;
    short wEE;
    unsigned int unk0f0;
    unsigned char unk0f4;
    unsigned char unk0f5;
    unsigned short unk0f6;
    PSceneColors* colors;
};
struct PPass
{
    int unk000;
    unsigned short shader;
    unsigned char type;
    unsigned char extra;
    bool enabled;
    char b09;
    short w0A;
};
struct PArray
{
    int unk000;
    PPass** items;
    int unk008;
    int unk00c;
    unsigned int count;
    void FUN_00b2c0b0(PGeom*, unsigned short, bool, unsigned char, PLight*, PLight*, PLight*, PLight*);
};
struct PState
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
    PLight* scene;
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
    unsigned char mode;
    char b121;
    short w122;
};
struct PContext
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
    PState* state;
};
struct PSceneColors
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
    NiColor colorD4;
    NiColor colorE0;
};
struct PRenderer
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
    int mode;
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
    int extra;
};
struct PEffect
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
    void* value;
};
struct PShader
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    unsigned int flags;
    unsigned int flags2;
    float alpha;
    float opacity;
    int unk030;
    float intensity;
    int unk038;
    PArray* passes;
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
    int* value;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    PEffect* effect;
    virtual void virtual00();
    virtual void virtual01();
    virtual const RuntimeType* GetType() const;
    virtual void virtual03();
    virtual void virtual04();
    virtual void virtual05();
    virtual void virtual06();
    virtual void virtual07();
    virtual void virtual08();
    virtual void virtual09();
    virtual void virtual0a();
    virtual void virtual0b();
    virtual void virtual0c();
    virtual void virtual0d();
    virtual void virtual0e();
    virtual void virtual0f();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual1a();
    virtual void virtual1b();
    virtual void virtual1c();
    virtual void virtual1d();
    virtual void virtual1e();
    virtual void virtual1f();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual2a();
    virtual void virtual2b();
    virtual void virtual2c();
    virtual void virtual2d();
    virtual void virtual2e();
    virtual void virtual2f();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual3a();
    virtual void virtual3b();
    virtual void virtual3c();
    virtual void virtual3d();
    virtual void virtual3e();
    virtual void virtual3f();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();


    virtual void fallback(PGeom*, int, unsigned short*, int, PRenderer*, unsigned char);
    void BSShaderPPLightingProperty_GetRenderPasses_2x(PGeom*, int, unsigned short*, int, PRenderer*, unsigned char);
    bool IsKindOf(const RuntimeType* wanted) const {for(const RuntimeType* t=GetType();t;t=t->parent)if(t==wanted)return true;return false;}
PShader* CastTo(const RuntimeType* wanted){return IsKindOf(wanted)?this:0;}
    bool FUN_00468ec0(unsigned int);
    bool IsSpecial() const
    {
        return (flags2 & 0x800000) > 0;
    }
    unsigned short FUN_00af3490();
    PLight* FUN_00af32e0(PNode**);
    PLight* FUN_00af33d0(PNode**);
    PLight* FUN_00af3280(PNode**);
    PLight* FUN_00af3360(PNode**);
    void FUN_00b5c120(PGeom*, unsigned short*, unsigned char, bool*, bool, bool);
    void FUN_00b5c1b0(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5c080(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5bfc0(PGeom*, unsigned short*, unsigned char, bool*, bool, bool);
    void FUN_00b5f310(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool);
    void FUN_00b5f7e0(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool, bool);
    void FUN_00b60490(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool, bool, bool, bool);
    void FUN_00b5ed10(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool, bool);
    void FUN_00b60c70(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
    void FUN_00b5e380(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool,
                      bool, bool);
    void FUN_00b5e7e0(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool,
                       bool, bool, bool);
    void FUN_00b5b760(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b5ba60(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b5fce0(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool);
    void FUN_00b5fe80(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool,
                      bool);
    void FUN_00b60040(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool, bool,
                      bool);
    void FUN_00b611d0(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool, bool, bool);
    void FUN_00b60270(PGeom*, PLight*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b600d0(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool, bool);
    void FUN_00b5e210(PGeom*, PLight*, PLight*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    void FUN_00b61670(PGeom*, PLight*, unsigned short*, unsigned char, bool*, bool, bool);
    void FUN_00b5bde0(PGeom*, unsigned short*, unsigned char, bool*, bool, bool, bool);
    void FUN_00b5e2e0(PGeom*, unsigned short*, unsigned char, bool*, bool);
    void FUN_00b5d5b0(PGeom*, unsigned short*, unsigned char, bool, bool);
    void FUN_00b5c250(PGeom*, unsigned short*, unsigned char, bool);
};
struct BSShaderPPLightingProperty : PShader {};
struct SpeedTreeShaderPPLightingProperty : BSShaderPPLightingProperty {};
struct SpeedTreeBranchShaderProperty : SpeedTreeShaderPPLightingProperty {};
struct SpeedTreeShaderLightingProperty : PShader {};
struct SpeedTreeFrondShaderProperty : SpeedTreeShaderLightingProperty {};
struct SpeedTreeLeafShaderProperty : SpeedTreeShaderLightingProperty {};
template<class T> T* NiDynamicCast(const RuntimeType* wanted, PShader* object)
{
    if (!object) return 0;
    return object->IsKindOf(wanted) ? static_cast<T*>(object) : 0;
}
extern unsigned char DAT_0116f217;
extern int DAT_0116f3d4;
extern unsigned char DAT_0116efc8;
extern int DAT_0116efb0;
extern float DAT_01173610;
extern unsigned char DAT_0116ef97;
extern float DAT_0116f258, DAT_0116f250, DAT_0116f248;
extern unsigned int DAT_00e8ff6c;
extern char DAT_0116f212, DAT_01067b4d;
extern RuntimeType DAT_01176520, DAT_0117826c, DAT_01176508;
PContext* __cdecl FUN_00ad5a50();
bool __cdecl FUN_00530bb0();

// pdb: BSShaderPPLightingProperty::GetRenderPasses_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0721_beta, udata + bridge(caller_sim|caller_sim), high
void PShader::BSShaderPPLightingProperty_GetRenderPasses_2x(PGeom* geom, int renderFlags, unsigned short* count, int mode, PRenderer* renderer,
                           unsigned char passMode)
{
    bool diffusePass = (flags & 1) > 0;
    bool ambientPass = (flags & 0x80) > 0;
    bool projected = (flags & 0x20000) > 0;
    bool flag21 = (flags & 0x200000) > 0;
    bool skinned = (flags & 2) > 0;
    bool vertex = (flags & 0x20) > 0 || mode == 3;
    bool flag8 = (flags & 0x100) > 0;
    bool flag10 = (flags & 0x400) > 0;
    bool hasValue = (*value != 0) & !flag10;
    bool data = false;
    if (geom->data->value)
        data = true;
    data |= ((flags2 & 0x20) > 0);
    bool special = !DAT_0116f217 && DAT_0116f3d4 && (DAT_0116efc8 & 0x20) && DAT_0116efb0 >= 2 &&
                   !((flags & 0x2000) > 0) && (unsigned int)DAT_01173610 && FUN_00ad5a50()->state->mode != 1 &&
                   FUN_00ad5a50()->state->mode != 3;
    bool castA = NiDynamicCast<SpeedTreeBranchShaderProperty>(&DAT_01176520, this) != 0;
    bool castB = NiDynamicCast<SpeedTreeFrondShaderProperty>(&DAT_0117826c, this) != 0;
    bool castC = NiDynamicCast<SpeedTreeLeafShaderProperty>(&DAT_01176508, this) != 0;
    bool flag22 = (flags & 0x400000) > 0;
    bool flag11 = (flags & 0x800) > 0;
    bool flag12 = (flags & 0x1000) > 0;
    bool flag14 = (flags & 0x4000) > 0;
    bool flag15 = (flags & 0x8000) > 0;
    bool flag16 = (flags & 0x10000) > 0;
    bool flag9 = (flags & 0x200) > 0;
    bool enabled = !((flags & 0x100000) > 0) || DAT_0116ef97;
    bool flag18 = (flags & 0x40000) > 0;
    bool flag26 = (flags & 0x4000000) > 0 || (flags & 0x8000000) > 0;
    bool decal = !(geom->alpha->flags & 1) && (renderer->mode == 2 || (flags2 & 4) > 0 || (flags2 & 2) > 0);
    PAlpha** alphaPtr = &geom->alpha;
    PAlpha* alphaProp = geom->FUN_00826590(0);
    if (!alphaProp)
        alphaProp = alphaPtr ? *alphaPtr : 0;
    bool transparent = (alphaProp && (alphaProp->flags & 1)) || alpha < 1.0 || opacity < 1.0;
    bool alphaTest = alphaProp && (alphaProp->GetMode() != 0);
    if (alphaTest)
        flag8 = false;
    bool flag23 = false;
    if (!flag23)
    {
        if (projected != flag23)
        {
            if (DAT_0116f258 != 0.0 && intensity >= DAT_0116f258)
                ambientPass = false;
            else
                ambientPass = true;
            diffusePass = false;
        }
        else if (DAT_0116f250 != 0.0 && intensity >= DAT_0116f250)
            ambientPass = false;
        if (DAT_0116f248 != 0.0 && intensity >= DAT_0116f248)
            diffusePass = false;
    }
    PLight* sceneLight = FUN_00ad5a50()->state->scene;
    bool blackAmbient = diffusePass && sceneLight->colors->colorE0.FUN_00914770(DAT_0108f450);
    bool first = true;
    if (transparent)
    {
        bool transparentFirst = true;
        if ((flag9 || opacity < 1.0) && !(alphaProp && (alphaProp->flags & 1)) && !((flags & 0x8000) > 0) &&
            !((flags & 0x10000) > 0))
        {
            FUN_00b5c120(geom, count, passMode, &transparentFirst, skinned, alphaTest);
            if (opacity < 1.0 || alpha < 1.0)
                passes->items[passes->count - 1]->type = 14;
            diffusePass = false;
        }
        vertex = true;
    }
    bool firstPass = true;
    if (effect && effect->value)
    {
        FUN_00b5c1b0(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 14;
    }
    unsigned short lightCount = FUN_00af3490();
    bool doBase = (renderFlags & 1) > 0;
    bool doDiffuse = (renderFlags & 2) > 0;
    bool doSpecular = (renderFlags & 4) > 0;
    bool doAmbient = (renderFlags & 8) > 0 && diffusePass;
    bool doAmbientExtra = ambientPass && (renderFlags & 8) > 0;
    first = true;
    bool allFlags = (DAT_00e8ff6c & renderFlags) == DAT_00e8ff6c;
    int integerLightCount = lightCount;
    unsigned int remaining = lightCount; // Unsigned JA in the diffuse loop; ambient count is signed.
    if (flag15 || flag16)
    {
        FUN_00b5bfc0(geom, count, passMode, &firstPass, skinned, flag16);
        passes->items[passes->count - 1]->type = 6;
        return;
    }
    if ((flags2 & 0x40) > 0)
    {
        FUN_00b5c080(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 7;
    }
    if (castB || castC)
    {
        fallback(geom, renderFlags, count, renderer->extra, renderer, passMode);
        return;
    }
    PNode* lightPosition = 0;
    if (FUN_00530bb0() && !decal && !flag12)
    {
        PNode* activePosition = 0;
        PLight* light = FUN_00af3280(&activePosition);
        if (light)
        {
            do
            {
                if (light->special)
                {
                    passes->FUN_00b2c0b0(geom, 0, true, 1, light, 0, 0, 0);
                    PPass* pass = passes->items[passes->count - 1];
                    int shader;
                    if (skinned)
                        shader = 0x232;
                    else if (flag14)
                        shader = 0x233;
                    else
                        shader = castA ? 0x234 : 0x231;
                    pass->shader = shader;
                    pass->enabled = true;
                }
                light = FUN_00af3360(&activePosition);
            } while (light);
        }
    }
    if (!flag14)
    {
        if (enabled)
        {
            if (doBase)
            {
                if (!DAT_0116f212)
                {
                    if (!vertex && !transparent)
                    {
                        if (!doDiffuse)
                            goto baseOnly;
                        if (!doSpecular || flag8 || flag22)
                            goto standardBase;
                    }
                    if (lightCount <= 1 && blackAmbient && (lightCount == 0 || !special) && doAmbient && !flag10)
                        goto combinedAmbient;
                    if (!vertex || !(flag11 || flag18 || special || flag12 || castA || hasValue))
                        goto materialPass;
                    if (flag10)
                        goto combinedNormal;
                combinedAmbient:
                    if (doAmbient)
                    {
                        if (!lightCount)
                        {
                            FUN_00b5f310(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10,
                                         false, special, flag11, castA, flag18);
                        }
                        else
                        {
                            PLight* light = FUN_00af32e0(&lightPosition);
                            FUN_00b5f7e0(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA, flag18);
                        }
                        allFlags = false;
                        goto ambientExtra;
                    }
                combinedNormal:
                    if (lightCount == 0)
                    {
                        FUN_00b60490(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10, false,
                                     special, flag11, flag12, castA, flag22, flag18, alphaTest);
                    }
                    else
                    {
                        PLight* light = FUN_00af32e0(&lightPosition);
                        FUN_00b5ed10(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue, flag10,
                                     false, special, flag11, castA, flag18);
                    }
                    allFlags = false;
                    goto ambientExtra;
                materialPass:
                    int extraPass = 1;
                    PMaterial* material = geom->material;
                    if (!DAT_01067b4d ||
                        (material &&
                         !(material->alternate ? material->alternate : &material->color)->FUN_00914730(DAT_0108f450)) ||
                        sceneLight->colors->colorD4.FUN_00914770(DAT_0108f450) || !FUN_00468ec0(0x25) ||
                        (alphaProp && (alphaProp->GetMode() != 0) && opacity < 1.0) || FUN_00468ec0(0x1a) ||
                        FUN_00468ec0(0x1b) || FUN_00468ec0(7) || FUN_00468ec0(0x15) || FUN_00468ec0(0x11) ||
                        geom->unk0bc)
                        extraPass = 0;
                    if (vertex || (((integerLightCount <= extraPass + 5 && !doAmbient && !flag10) ||
                                    (integerLightCount <= extraPass + 4 && !doAmbient && flag10) ||
                                    (integerLightCount <= extraPass + 2 && doAmbient && !flag10)) &&
                                   (lightCount > 1 || diffusePass) && !flag11 && !flag18 && !special && !flag12 &&
                                   !castA && !hasValue))
                    {
                        FUN_00b60c70(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, doAmbient,
                                     flag10, extraPass != 0);
                        allFlags = false;
                        goto ambientExtra;
                    }
                }
            standardBase:
                if (doDiffuse)
                {
                    unsigned char globalMode = DAT_0116f217;
                    if (doSpecular && (!flag10 || !globalMode) && (lightCount <= 1 || vertex))
                    {
                        if (!lightCount)
                        {
                            FUN_00b60490(geom, sceneLight, count, passMode, &firstPass, skinned, hasValue, flag10,
                                         false, special, flag11, flag12, castA, flag22, flag18, alphaTest);
                        }
                        else
                        {
                            PLight* light = FUN_00af32e0(&lightPosition);
                            FUN_00b5ed10(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA, flag18);
                        }
                        if (doAmbient)
                            goto ambientLighting;
                        allFlags = false;
                        goto ambientExtra;
                    }
                    if (!flag10 || !globalMode)
                    {
                        if (lightCount <= 1)
                        {
                            PLight* light = FUN_00af32e0(&lightPosition);
                            FUN_00b5e380(geom, sceneLight, light, count, passMode, &firstPass, skinned, hasValue,
                                         flag10, false, special, flag11, castA);
                            remaining = 0;
                        }
                        else
                        {
                            PLight* light = FUN_00af32e0(&lightPosition);
                            PLight* light2 = FUN_00af33d0(&lightPosition);
                            FUN_00b5e7e0(geom, sceneLight, light, light2, count, passMode, &firstPass, skinned,
                                          hasValue, flag10, false, special, flag11, castA);
                            remaining -= 2;
                        }
                        first = false;
                        goto diffuseLighting;
                    }
                }
            baseOnly:
                FUN_00b5b760(geom, sceneLight, count, passMode, &firstPass, skinned, alphaTest, hasValue, castA);
            }
        diffuseLighting:
            if (doDiffuse)
            {
                PLight* light;
                if (first)
                {
                    FUN_00b5ba60(geom, sceneLight, count, passMode, &firstPass, skinned, false, false, castA);
                    light = FUN_00af32e0(&lightPosition);
                }
                else
                    light = FUN_00af33d0(&lightPosition);
                while (light)
                {
                    if (remaining <= 2)
                    {
                        PLight* light2 = FUN_00af33d0(&lightPosition);
                        FUN_00b5fce0(geom, light, light2, count, passMode, &firstPass, skinned, flag10, false, flag11,
                                     castA);
                        if (remaining <= 1)
                            remaining = 0;
                        else
                            remaining -= 2;
                    }
                    else
                    {
                        PLight* light2 = FUN_00af33d0(&lightPosition);
                        PLight* light3 = FUN_00af33d0(&lightPosition);
                        FUN_00b5fe80(geom, light, light2, light3, count, passMode, &firstPass, skinned, flag10, false,
                                     flag11, castA);
                        remaining -= 3;
                    }
                    light = FUN_00af33d0(&lightPosition);
                }
            }
            if (doSpecular)
                FUN_00b60040(geom, sceneLight, count, passMode, &firstPass, skinned, false, flag10, data, castA, false,
                             flag11, flag18);
            if (doAmbient)
            {
            ambientLighting:
                int ambientRemaining = integerLightCount;
                if (blackAmbient)
                    FUN_00b611d0(geom, sceneLight, count, passMode, &firstPass, skinned, false, special, flag11, castA,
                                 flag18);
                PLight* light = FUN_00af32e0(&lightPosition);
                while (light)
                {
                    if (ambientRemaining > 2)
                    {
                        PLight* light2 = FUN_00af33d0(&lightPosition);
                        PLight* light3 = FUN_00af33d0(&lightPosition);
                        FUN_00b60270(geom, light, light2, light3, count, passMode, &firstPass, skinned, flag11, castA,
                                     flag18);
                        ambientRemaining -= 3;
                    }
                    else if (ambientRemaining > 1)
                    {
                        PLight* light2 = FUN_00af33d0(&lightPosition);
                        FUN_00b600d0(geom, light, light2, count, passMode, &firstPass, skinned, flag11, castA, flag18);
                        ambientRemaining -= 2;
                    }
                    else if (ambientRemaining > 0)
                    {
                        FUN_00b611d0(geom, light, count, passMode, &firstPass, skinned, false, special, flag11, castA,
                                     flag18);
                        --ambientRemaining;
                    }
                    light = FUN_00af33d0(&lightPosition);
                }
            }
        ambientExtra:
            if (doAmbientExtra)
            {
                PLight* light = FUN_00af32e0(&lightPosition);
                FUN_00b5e210(geom, sceneLight, light, count, passMode, &firstPass, skinned, projected, flag21);
                goto extraPass;
            }
        }
    }
    else
    {
        FUN_00b61670(geom, sceneLight, count, passMode, &firstPass, diffusePass, special);
    }
afterLighting:
    if (!allFlags)
    {
        if (passes->count && !flag14)
        {
            PPass* pass = passes->items[passes->count - 1];
            if (pass->shader != 0x252 && pass->shader != 0x254)
                pass->enabled = true;
        }
    }
    else if (!flag14)
    {
    extraPass:
        FUN_00b5bde0(geom, count, passMode, &firstPass, skinned, castA, transparent);
    }
    if (effect)
    {
        FUN_00b5e2e0(geom, count, passMode, &firstPass, skinned);
        passes->items[passes->count - 1]->type = 1;
    }
    if (DAT_0116f212)
    {
        if (renderFlags & 1)
            FUN_00b5d5b0(geom, count, passMode, skinned, hasValue);
        if (!castA && !flag22 && !flag11 && !flag12 && !flag14 && !flag18)
            FUN_00b5c250(geom, count, passMode, skinned);
    }
    unsigned int passType = 0;
    if (decal)
        passType = 10;
    else if (flag26)
        passType = 4;
    else if (transparent)
        passType = opacity < 1.0 ? 14 : 1;
    if (passes)
    {
        for (unsigned int iPass = 0; iPass < passes->count; ++iPass)
            if (!passes->items[iPass]->type)
                passes->items[iPass]->type = passType;
    }
}
}

// @f3 0x00b60040 (community match, verified in this file)
namespace f3m_00b60040 {
namespace f3m_b60040 {
struct PassSink {
    void FUN_00b2c0b0(void* geom, unsigned short pass, unsigned char enabled, unsigned char lights, void* l0, void* l1, void* l2, void* l3);
};

struct Ownerb60040 {
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34, m_38;
    PassSink* m_3c;

    int FUN_00b5ce20(void* a1, int a2, unsigned short* a3, unsigned char a4, unsigned char* a5, bool a6, int a7, int a8, int a9, int a10, int a13);
    int FUN_00b60040(void* a1, int a2, unsigned short* a3, unsigned char a4, unsigned char* a5, bool a6, int a7, int a8, int a9, int a10, int a11, bool a12, int a13);
};

// pdb: BSShaderPPLightingProperty::AddTexturePass_2x | BSShaderPPLightingProperty_Passes_2x.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apGeom, apSunlight, asCount, abUpdateList, abFirst, abSkinned, abMultitexture, abFacegenBlend, abVertexColors, abTreeBranch, abProjShadow, abParallax, abHair
int Ownerb60040::FUN_00b60040(void* a1, int a2, unsigned short* a3, unsigned char a4, unsigned char* a5, bool a6, int a7, int a8, int a9, int a10, int a11, bool a12, int a13)
{
    if (a12) {
        if (!a6) {
            if (a4 == 1) {
                m_3c->FUN_00b2c0b0(a1, 0x153, *a5, 0, 0, 0, 0, 0);
                return 0;
            }
            ++*a3;
        }
        return 0;
    }
    return FUN_00b5ce20(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a13);
}
}
}   // namespace f3m_00b60040
