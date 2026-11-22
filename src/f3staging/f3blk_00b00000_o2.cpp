#include <windows.h>
// src/f3staging/f3blk_00b00000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b0fc40 (community match, verified in this file)
extern void* FUN_00e94aec[];
namespace f3m_00b0fc40 {
namespace f3m_00b0fc40 {

struct SimpleArray
{
    void** m_ppVirtualMethodTable;
    unsigned int pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    unsigned int unk10;

    SimpleArray() : m_ppVirtualMethodTable(FUN_00e94aec), pBuffer(0), iSize(0), iAllocSize(0) {}
    void FUN_00ae7440();
    void Reset()
    {
        unsigned int buffer = pBuffer;
        iAllocSize = buffer;
        pBuffer = 0;
        iSize = 0;
        unk10 = 0;
    }
};

struct FUN_00b0fc40
{
    unsigned char flag;
    unsigned char unk01;
    unsigned short count;
    void* owner;
    int unk08;
    SimpleArray items;

    FUN_00b0fc40(void* owner);
};

// pdb: BSBatchRenderer::GeometryGroup::GeometryGroup | BSBatchRenderer.obj | fnv360_0822_retail, call_gap, low
// pdb params: auiPassCount
FUN_00b0fc40::FUN_00b0fc40(void* owner)
{
    flag = 0;
    unk08 = 0;
    this->owner = owner;
    count = 0;
    items.FUN_00ae7440();
    items.Reset();
}
}
}   // namespace f3m_00b0fc40

// @f3 0x00b19570 (community match, verified in this file)
extern char DAT_011f6238;
namespace f3m_00b19570 {
class AllocationPool {
public:
    void* FUN_0086b930(unsigned int size);
};

class PoolEffect {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void SetPass(unsigned int);
    virtual void SetMode(unsigned int);
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
    static void* operator new(unsigned int n) {
        return reinterpret_cast<AllocationPool*>(&DAT_011f6238)->FUN_0086b930(n);
    }
    static void operator delete(void*, unsigned int);
};

class A42D00Interpolator {
public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

class ShaderPrimary : public A42D00Interpolator {
public:
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual void Slot0fc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Initialize();
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
};
class ShaderEffect : public ShaderPrimary, public PoolEffect {
public:
    using A42D00Interpolator::operator new;
    using A42D00Interpolator::operator delete;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
};

class FUN_00c05680 : public PoolEffect {
public:
    FUN_00c05680();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
};

class RefractionImageSpaceEffect : public PoolEffect {
public:
    RefractionImageSpaceEffect();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
};

class ImageSpaceEffectWithTwoTextures : public PoolEffect {
public:
    ImageSpaceEffectWithTwoTextures();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
};

class FUN_00bad500 : public PoolEffect {
public:
    FUN_00bad500();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};

class FUN_00c05420 : public PoolEffect {
public:
    FUN_00c05420();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
};

class FUN_00c04d20_class : public PoolEffect {
public:
    FUN_00c04d20_class();
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
};

class FUN_00b3a3f0 : public PoolEffect {
public:
    FUN_00b3a3f0();

};

class FUN_00bc0600 : public PoolEffect {
public:
    FUN_00bc0600();

};

class FUN_00b855f0 : public PoolEffect {
public:
    FUN_00b855f0();
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
};

class FUN_00c049c0 : public PoolEffect {
public:
    FUN_00c049c0();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
};

class FUN_00b23330 : public PoolEffect {
public:
    FUN_00b23330();
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
};

class FUN_00b5a590 : public PoolEffect {
public:
    FUN_00b5a590();
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
};

class FUN_00b5a410 : public PoolEffect {
public:
    FUN_00b5a410();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
};

class FUN_00b2c330 : public PoolEffect {
public:
    FUN_00b2c330();

};

class FUN_00c04600 : public PoolEffect {
public:
    FUN_00c04600();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
};

class FUN_00ba15e0 : public PoolEffect {
public:
    FUN_00ba15e0();
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
};

class FUN_00ba02f0 : public PoolEffect {
public:
    FUN_00ba02f0();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
};

class FUN_00b9b830 : public PoolEffect {
public:
    FUN_00b9b830();
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
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
};

class FUN_00b85e70 : public PoolEffect {
public:
    FUN_00b85e70();
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
};

class FUN_00bb9180_cls : public PoolEffect {
public:
    FUN_00bb9180_cls();

};

class FUN_00ba4640 : public PoolEffect {
public:
    FUN_00ba4640();
    unsigned int unk58;
    unsigned int unk5c;
};

class FUN_00b14030 : public ShaderEffect {
public:
    FUN_00b14030();

};

class FUN_00b140a0 : public ShaderEffect {
public:
    FUN_00b140a0();

};

class FUN_00b146f0 : public ShaderEffect {
public:
    FUN_00b146f0();

};

class FUN_00b8f520_class : public ShaderEffect {
public:
    FUN_00b8f520_class();

};

class FUN_00b14240 : public ShaderEffect {
public:
    FUN_00b14240();

};

class FUN_00b8f360_class : public ShaderEffect {
public:
    FUN_00b8f360_class();

};

class FUN_00b171d0 : public ShaderEffect {
public:
    FUN_00b171d0();

};

class FUN_00b8d330 : public ShaderEffect {
public:
    FUN_00b8d330();

};

class FUN_00b8d850 : public ShaderEffect {
public:
    FUN_00b8d850();

};

class FUN_00b14f30 : public ShaderEffect {
public:
    FUN_00b14f30();

};

class FUN_00b8d5b0 : public ShaderEffect {
public:
    FUN_00b8d5b0();

};

class FUN_00b12790 : public ShaderEffect {
public:
    FUN_00b12790();

};

class FUN_00b922d0 : public ShaderEffect {
public:
    FUN_00b922d0();
    unsigned int unkd0;
};

class FUN_00b13eb0 : public ShaderEffect {
public:
    FUN_00b13eb0();

};

class FUN_00b8f7e0 : public ShaderEffect {
public:
    FUN_00b8f7e0();

};

class FUN_00b14dd0 : public ShaderEffect {
public:
    FUN_00b14dd0();

};

class FUN_00b91a40 : public ShaderEffect {
public:
    FUN_00b91a40();

};

class FUN_00b16990 : public ShaderEffect {
public:
    FUN_00b16990();

};

class FUN_00b91b80 : public ShaderEffect {
public:
    FUN_00b91b80();

};

class FUN_00b149c0 : public ShaderEffect {
public:
    FUN_00b149c0();

};

class FUN_00b14b10 : public ShaderEffect {
public:
    FUN_00b14b10();

};

class ImageSpaceShaderHDRVariantFour : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantFour();

};

class FUN_00b11780 : public ShaderEffect {
public:
    FUN_00b11780();

};

class FUN_00b15080 : public ShaderEffect {
public:
    FUN_00b15080();

};

class ImageSpaceShaderHDRVariantTwo : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantTwo();

};

class ImageSpaceShaderHDRVariantThree : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantThree();

};

class ImageSpaceShaderHDRVariantFive : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantFive();

};

class ImageSpaceShaderHDRVariantSix : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantSix();

};

class HDRBaseImageSpaceShaderVariant4 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant4();

};

class HDRBaseImageSpaceShaderVariant1 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant1();

};

class HDRBaseImageSpaceShaderVariant6 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant6();

};

class HDRBaseImageSpaceShaderVariant2 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant2();

};

class ImageSpaceShaderHDRVariantEight : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantEight();

};

class ImageSpaceShaderHDRVariantSeven : public ShaderEffect {
public:
    ImageSpaceShaderHDRVariantSeven();

};

class FUN_00b16570 : public ShaderEffect {
public:
    FUN_00b16570();

};

class HDRBaseImageSpaceShaderVariant5 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant5();

};

class HDRBaseImageSpaceShaderVariant3 : public ShaderEffect {
public:
    HDRBaseImageSpaceShaderVariant3();

};

class FUN_00b16710 : public ShaderEffect {
public:
    FUN_00b16710();

};

class FUN_00b8bce0 : public ShaderEffect {
public:
    FUN_00b8bce0();

};

class FUN_00b17550 : public ShaderEffect {
public:
    FUN_00b17550();

};

class FUN_00b16ad0 : public ShaderEffect {
public:
    FUN_00b16ad0();

};

class FUN_00b12a20 : public ShaderEffect {
public:
    FUN_00b12a20();

};

class FUN_00b8dae0_class : public ShaderEffect {
public:
    FUN_00b8dae0_class();

};

class FUN_00b8dc30_class : public ShaderEffect {
public:
    FUN_00b8dc30_class();

};

class FUN_00b8dd80_Class : public ShaderEffect {
public:
    FUN_00b8dd80_Class();

};

class FUN_00b8ded0 : public ShaderEffect {
public:
    FUN_00b8ded0();

};

class FUN_00b130b0 : public ShaderEffect {
public:
    FUN_00b130b0();

};

class FUN_00b13200 : public ShaderEffect {
public:
    FUN_00b13200();

};

class FUN_00b13350 : public ShaderEffect {
public:
    FUN_00b13350();

};

class ImageSpaceShaderVariant4 : public ShaderEffect {
public:
    ImageSpaceShaderVariant4();

};

class ImageSpaceShaderVariant5 : public ShaderEffect {
public:
    ImageSpaceShaderVariant5();

};

class ImageSpaceShaderVariant6 : public ShaderEffect {
public:
    ImageSpaceShaderVariant6();

};

class ImageSpaceShaderVariant1 : public ShaderEffect {
public:
    ImageSpaceShaderVariant1();

};

class ImageSpaceShaderVariant2 : public ShaderEffect {
public:
    ImageSpaceShaderVariant2();

};

class ImageSpaceShaderVariant3 : public ShaderEffect {
public:
    ImageSpaceShaderVariant3();

};

class FUN_00b932d0_class : public ShaderEffect {
public:
    FUN_00b932d0_class();

};

class FUN_00b93600_class : public ShaderEffect {
public:
    FUN_00b93600_class();

};

class FUN_00b93950_class : public ShaderEffect {
public:
    FUN_00b93950_class();

};

class FUN_00b93aa0_class : public ShaderEffect {
public:
    FUN_00b93aa0_class();

};

class FUN_00b18860 : public ShaderEffect {
public:
    FUN_00b18860();

};

class FUN_00b18bb0 : public ShaderEffect {
public:
    FUN_00b18bb0();

};

class FUN_00b18ee0 : public ShaderEffect {
public:
    FUN_00b18ee0();

};

class FUN_00b19030 : public ShaderEffect {
public:
    FUN_00b19030();

};

class FUN_00b19180 : public ShaderEffect {
public:
    FUN_00b19180();

};

class FUN_00b192d0 : public ShaderEffect {
public:
    FUN_00b192d0();

};

class FUN_00b19420 : public ShaderEffect {
public:
    FUN_00b19420();

};

class FUN_00b176e0 : public ShaderEffect {
public:
    FUN_00b176e0();

};

class FUN_00b17830 : public ShaderEffect {
public:
    FUN_00b17830();

};

class FUN_00b17980 : public ShaderEffect {
public:
    FUN_00b17980();

};

class FUN_00b17ad0 : public ShaderEffect {
public:
    FUN_00b17ad0();

};

class FUN_00b17c20 : public ShaderEffect {
public:
    FUN_00b17c20();

};

class FUN_00b17de0 : public ShaderEffect {
public:
    FUN_00b17de0();

};

class FUN_00b17f30 : public ShaderEffect {
public:
    FUN_00b17f30();

};

class FUN_00b18080 : public ShaderEffect {
public:
    FUN_00b18080();

};

class FUN_00b181d0 : public ShaderEffect {
public:
    FUN_00b181d0();

};

class FUN_00b16d40 : public ShaderEffect {
public:
    FUN_00b16d40();

};

class FUN_00b17080 : public ShaderEffect {
public:
    FUN_00b17080();

};

class FUN_00b11950 : public ShaderEffect {
public:
    FUN_00b11950();

};

class EffectArray {
public:
    virtual void Slot00();
    PoolEffect** data;
    unsigned short capacity, size, count, growBy;
    PoolEffect* const& GetAt(unsigned int index) const { return data[index]; }
    __declspec(noinline) void FUN_005b3880(unsigned int index, PoolEffect* const& value) {
        if (index >= size) {
            size = static_cast<unsigned short>(index + 1);
            if (value != 0) ++count;
        } else if (value != 0) {
            if (data[index] == 0) ++count;
        } else if (data[index] != 0) {
            --count;
        }
        data[index] = value;
    }
    void SetAt(unsigned int index, PoolEffect* const& value) {
        if (index >= size) {
            size = static_cast<unsigned short>(index + 1);
            if (value != 0) ++count;
        } else if (value != 0) {
            if (data[index] == 0) ++count;
        } else if (data[index] != 0) {
            --count;
        }
        data[index] = value;
    }
};

class EffectManager {
public:
    unsigned int unk00;
    EffectArray effects;
    void FUN_00b19570();
};

// pdb: ImageSpaceManager::InitEffects | ImageSpaceManager.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void EffectManager::FUN_00b19570() {
    { PoolEffect* effect = new FUN_00c05680; effects.FUN_005b3880(13, effect); }
    { PoolEffect* effect = new RefractionImageSpaceEffect; effects.FUN_005b3880(2, effect); }
    { PoolEffect* effect = new ImageSpaceEffectWithTwoTextures; effects.FUN_005b3880(8, effect); }
    { PoolEffect* effect = new FUN_00bad500; effects.FUN_005b3880(1, effect); }
    { PoolEffect* effect = new FUN_00c05420; effects.FUN_005b3880(0, effect); }
    { PoolEffect* effect = new FUN_00c04d20_class; effects.FUN_005b3880(3, effect); }
    { PoolEffect* effect = new FUN_00b3a3f0; effects.FUN_005b3880(10, effect); }
    { PoolEffect* effect = new FUN_00bc0600; effects.FUN_005b3880(11, effect); }
    { PoolEffect* effect = new FUN_00b855f0; effects.FUN_005b3880(4, effect); }
    { PoolEffect* effect = new FUN_00c049c0; effects.FUN_005b3880(12, effect); }
    { PoolEffect* effect = new FUN_00b23330; effects.FUN_005b3880(7, effect); }
    { PoolEffect* effect = new FUN_00b5a590; effects.FUN_005b3880(5, effect); }
    { PoolEffect* effect = new FUN_00b5a410; effects.FUN_005b3880(6, effect); }
    { PoolEffect* effect = new FUN_00b2c330; effects.FUN_005b3880(14, effect); }
    { PoolEffect* effect = new FUN_00c04600; effects.FUN_005b3880(15, effect); }
    { PoolEffect* effect = new FUN_00ba15e0; effects.FUN_005b3880(31, effect); }
    { PoolEffect* effect = new FUN_00ba02f0; effects.FUN_005b3880(32, effect); }
    { PoolEffect* effect = new FUN_00b9b830; effects.FUN_005b3880(33, effect); }
    { PoolEffect* effect = new FUN_00b85e70; effects.FUN_005b3880(9, effect); }
    { PoolEffect* effect = new FUN_00bb9180_cls; effects.FUN_005b3880(30, effect); }
    for (int pass = 0; pass < 7; ++pass) {
        FUN_00ba4640* first = new FUN_00ba4640;
        first->SetPass(pass + 1);
        first->SetMode(0);
        effects.SetAt(pass + 16, first);
        FUN_00ba4640* second = new FUN_00ba4640;
        second->SetPass(pass + 1);
        second->SetMode(1);
        effects.SetAt(pass + 23, second);
    }
    effects.SetAt(34, new FUN_00b14030);
    effects.SetAt(35, new FUN_00b140a0);
    effects.SetAt(36, new FUN_00b146f0);
    effects.SetAt(37, new FUN_00b8f520_class);
    effects.SetAt(38, new FUN_00b14030);
    effects.SetAt(39, new FUN_00b14240);
    effects.SetAt(40, new FUN_00b8f360_class);
    effects.SetAt(41, new FUN_00b171d0);
    effects.SetAt(42, new FUN_00b8d330);
    effects.SetAt(43, new FUN_00b8d850);
    effects.SetAt(44, new FUN_00b14f30);
    effects.SetAt(45, new FUN_00b8d5b0);
    effects.SetAt(46, new FUN_00b12790);
    effects.SetAt(47, new FUN_00b922d0);
    effects.SetAt(50, new FUN_00b13eb0);
    effects.SetAt(51, new FUN_00b8f7e0);
    effects.SetAt(52, new FUN_00b14dd0);
    effects.SetAt(48, new FUN_00b91a40);
    effects.SetAt(49, new FUN_00b16990);
    effects.SetAt(53, new FUN_00b91b80);
    effects.SetAt(54, new FUN_00b149c0);
    effects.SetAt(55, new FUN_00b14b10);
    effects.SetAt(56, new ImageSpaceShaderHDRVariantFour);
    effects.SetAt(57, new FUN_00b11780);
    effects.SetAt(58, new FUN_00b15080);
    effects.SetAt(59, new ImageSpaceShaderHDRVariantTwo);
    effects.SetAt(60, new ImageSpaceShaderHDRVariantThree);
    effects.SetAt(61, new ImageSpaceShaderHDRVariantFive);
    effects.SetAt(62, new ImageSpaceShaderHDRVariantSix);
    effects.SetAt(63, new HDRBaseImageSpaceShaderVariant4);
    effects.SetAt(64, new HDRBaseImageSpaceShaderVariant1);
    effects.SetAt(65, new HDRBaseImageSpaceShaderVariant6);
    effects.SetAt(67, new HDRBaseImageSpaceShaderVariant2);
    effects.SetAt(66, new ImageSpaceShaderHDRVariantEight);
    effects.SetAt(69, new ImageSpaceShaderHDRVariantSeven);
    effects.SetAt(68, new FUN_00b16570);
    effects.SetAt(70, new HDRBaseImageSpaceShaderVariant5);
    effects.SetAt(71, new HDRBaseImageSpaceShaderVariant3);
    effects.SetAt(72, new FUN_00b16710);
    effects.SetAt(73, new FUN_00b8bce0);
    effects.SetAt(75, new FUN_00b17550);
    effects.SetAt(76, new FUN_00b16ad0);
    effects.SetAt(78, new FUN_00b12a20);
    effects.SetAt(79, new FUN_00b8dae0_class);
    effects.SetAt(80, new FUN_00b8dc30_class);
    effects.SetAt(81, new FUN_00b8dd80_Class);
    effects.SetAt(82, new FUN_00b8ded0);
    effects.SetAt(83, new FUN_00b130b0);
    effects.SetAt(84, new FUN_00b13200);
    effects.SetAt(85, new FUN_00b13350);
    effects.SetAt(86, new ImageSpaceShaderVariant4);
    effects.SetAt(87, new ImageSpaceShaderVariant5);
    effects.SetAt(88, new ImageSpaceShaderVariant6);
    effects.SetAt(89, new ImageSpaceShaderVariant1);
    effects.SetAt(90, new ImageSpaceShaderVariant2);
    effects.SetAt(91, new ImageSpaceShaderVariant3);
    effects.SetAt(93, new FUN_00b932d0_class);
    effects.SetAt(94, new FUN_00b93600_class);
    effects.SetAt(95, new FUN_00b93950_class);
    effects.SetAt(96, new FUN_00b93aa0_class);
    effects.SetAt(97, new FUN_00b18860);
    effects.SetAt(98, new FUN_00b18bb0);
    effects.SetAt(99, new FUN_00b18ee0);
    effects.SetAt(100, new FUN_00b19030);
    effects.SetAt(101, new FUN_00b19180);
    effects.SetAt(102, new FUN_00b192d0);
    effects.SetAt(103, new FUN_00b932d0_class);
    effects.SetAt(104, new FUN_00b19420);
    effects.SetAt(105, new FUN_00b176e0);
    effects.SetAt(106, new FUN_00b17830);
    effects.SetAt(107, new FUN_00b17980);
    effects.SetAt(108, new FUN_00b17ad0);
    effects.SetAt(109, new FUN_00b17c20);
    effects.SetAt(110, new FUN_00b17de0);
    effects.SetAt(111, new FUN_00b17f30);
    effects.SetAt(112, new FUN_00b18080);
    effects.SetAt(113, new FUN_00b181d0);
    { PoolEffect* effect = new FUN_00b16d40; effects.FUN_005b3880(114, effect); }
    { PoolEffect* effect = new FUN_00b17080; effects.FUN_005b3880(115, effect); }
    { PoolEffect* effect = new FUN_00b11950; effects.FUN_005b3880(77, effect); }
    for (unsigned int index = 34; index < 116; ++index) {
        if (effects.GetAt(index) != 0)
            static_cast<ShaderEffect*>(effects.GetAt(index))->Initialize();
    }
}
}   // namespace f3m_00b19570

// @f3 0x00b104b0 (community match, verified in this file)
extern bool DAT_0116f211;
extern int DAT_01175aac, DAT_01175a70, DAT_01175ab0;
namespace f3m_00b104b0 {
template <class K, class V> struct BatchMapItem
{
    BatchMapItem* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> struct BatchPassMap
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    BatchMapItem<K, V>** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(K key, V& result) const;
};
unsigned MapKeyToHashIndex(const void* map, unsigned key);
bool MapIsKeysEqual(const void* map, unsigned a, unsigned b);
template <class K, class V> bool BatchPassMap<K, V>::GetAt(K key, V& result) const
{
    unsigned index = MapKeyToHashIndex(this, key);
    BatchMapItem<K, V>* item = m_ppkHashTable[index];
    while (item)
    {
        if (MapIsKeysEqual(this, key, item->m_key))
        {
            result = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

struct BatchPass
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    bool kind;
};
struct BatchLink
{
    BatchLink* next;
    BatchLink* prev;
    BatchPass* pass;
};
struct BatchQueue
{
    int unk00;
    BatchLink* head;
    BatchLink* tail;
    BatchLink* freeHead;
    unsigned count;
    bool IsEmpty() const
    {
        return head == 0;
    }
    BatchPass* const& GetHead() const
    {
        return head->pass;
    }
    void RemoveHead()
    {
        if (head)
        {
            if (head == tail)
                tail = 0;
            BatchLink* next = 0;
            if (head->next)
            {
                next = head->next;
                next->prev = 0;
            }
            if (freeHead)
                freeHead->prev = head;
            head->next = freeHead;
            freeHead = head;
            --count;
            head = next;
        }
    }
};
struct BatchGroup
{
    BatchQueue queues[5];
    unsigned count;
};
void FUN_00b0e120(int, int);
void FUN_00b0db20(int, int);
int FUN_00b0e190(int, int);
void FUN_00b0f230(void*, unsigned int, bool, int, int);
struct BatchRenderer
{
    int unk00, unk04;
    BatchGroup* groups;
    BatchPassMap<unsigned int, unsigned int> map;
    bool BSBatchRenderer_PrepareNextRenderPass(unsigned&, int&, bool&);
    bool BSBatchRenderer_RenderNextRenderPass(unsigned&, int&, bool&, int);
};
// @fnv 0x00b9a120
// pdb: BSBatchRenderer::RenderNextRenderPass | BSBatchRenderer.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
bool BatchRenderer::BSBatchRenderer_RenderNextRenderPass(unsigned& key, int& bucket, bool& kind, int flags)
{
    unsigned index = 0;
    map.GetAt(key, index);
    bool first = groups[index].queues[bucket].head->pass->kind;
    bool alpha = false;

    if (bucket == 0)
    {
        FUN_00b0e120(1, 0);
        FUN_00b0db20(0, 1);
        FUN_00b0e190(0, 1);
    }
    if (bucket == 1)
    {
        FUN_00b0e120(3, 1);
        FUN_00b0db20(0, 1);
        FUN_00b0e190(0, 1);
    }
    if (bucket == 2)
    {
        FUN_00b0e120(3, 1);
        FUN_00b0db20(1, 1);
        alpha = true;
        if (DAT_0116f211)
            FUN_00b0e190(1, 1);
    }
    if (bucket == 3)
    {
        FUN_00b0e120(1, 1);
        FUN_00b0db20(1, 1);
        alpha = true;
        if (DAT_0116f211)
            FUN_00b0e190(1, 1);
    }
    if (bucket == 4)
    {
        FUN_00b0e120(1, 1);
        FUN_00b0db20(1, 1);
        alpha = true;
        if (DAT_0116f211)
            FUN_00b0e190(0, 1);
    }

    BatchPass* pass = groups[index].queues[bucket].GetHead();
    bool found = false;
    while (pass)
    {
        if (pass->kind != first)
        {
            kind = pass->kind;
            found = true;
            break;
        }
        FUN_00b0f230(pass, key, alpha, flags, 0);
        BatchGroup& group = groups[index];
        group.queues[bucket].RemoveHead();
        --group.count;
        BatchGroup& current = groups[index];
        if (current.queues[bucket].IsEmpty())
            break;
        pass = groups[index].queues[bucket].GetHead();
    }

    if (DAT_01175aac)
        --DAT_01175aac;
    if (DAT_01175a70)
        --DAT_01175a70;
    if (DAT_0116f211)
    {
        --DAT_01175ab0;
        FUN_00b0e190(0, 0);
    }
    FUN_00b0e190(0, 0);
    bool result = true;
    if (!found)
        result = BSBatchRenderer_PrepareNextRenderPass(key, bucket, kind);
    return result;
}
}   // namespace f3m_00b104b0

// @f3 0x00b0f700 (community match, verified in this file)
namespace fo3_b0f700 {
extern unsigned char DAT_0116f296;
extern unsigned char DAT_0116f211;
extern int DAT_01175ab0;
extern int DAT_01175aac;
extern int DAT_01175a70;

void FUN_00b3de90();
bool FUN_00ae6910(unsigned int);

struct RendererState
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
    bool bFlag164;
    bool bFlag165;
};
RendererState* FUN_00ad5a50();

void FUN_00b0e120(int, int);
void FUN_00b0db20(int, int);
int FUN_00b0e190(int, int);
void FUN_00b0f230(void*, unsigned short, bool, int, int);
void FUN_00b0e510();

struct BatchPassIndexMap : NiTPointerMap<unsigned int, unsigned int>
{
    __declspec(noalias) bool FUN_00bea7b0(unsigned int key, unsigned int& result) const;
};

struct PassNode
{
    PassNode* m_pkNext;
    PassNode* m_pkPrev;
    void* m_element;
};

struct PassBucket
{
    void** m_ppVirtualMethodTable;
    PassNode* m_pkHead;
    PassNode* m_pkTail;
    int m_uiCount;
    int unk10;
    bool IsEmpty() const
    {
        return m_pkHead == 0;
    }
    PassNode* GetHeadPos() const
    {
        return m_pkHead;
    }
    void* GetNext(PassNode*& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct RenderPassListCollection
{
    PassBucket buckets[5];
    int unk64;
    void FUN_00b0f540(bool);
};

struct ActivePass
{
    unsigned short m_item;
    ActivePass* m_pkNext;
    bool IsEmpty() const
    {
        return !m_pkNext && !m_item;
    }
    ActivePass* GetHead()
    {
        if (m_pkNext || m_item)
            return this;
        return 0;
    }
};

class BatchRendererQ
{
  public:
    void** m_ppVirtualMethodTable;
    int m_iObjectReferenceCount;
    RenderPassListCollection* m_pPassBucketEntries;
    BatchPassIndexMap m_kGroupIndexMap;
    unsigned int m_uiGroupCount;
    unsigned int m_uiPassCount;
    unsigned int m_uiBucketCount;
    void* m_pGeometryGroupAllocator;
    ActivePass m_kActivePassList;

    __forceinline void RenderGroup(unsigned int uiRenderPassIndex, unsigned int uiPass, int arg3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (m_pPassBucketEntries[uiRenderPassIndex].buckets[i].IsEmpty())
                continue;

            bool bAlpha = false;
            if (i == 0)
            {
                FUN_00b0e120(1, 0);
                FUN_00b0db20(0, 0);
                if (DAT_0116f211)
                    FUN_00b0e190(0, 1);
            }
            else if (i == 1)
            {
                FUN_00b0e120(3, 1);
                FUN_00b0db20(0, 0);
                if (DAT_0116f211)
                    FUN_00b0e190(0, 1);
            }
            else if (i == 2)
            {
                FUN_00b0e120(3, 1);
                FUN_00b0db20(1, 1);
                bAlpha = true;
                if (DAT_0116f211)
                    FUN_00b0e190(1, 1);
            }
            else if (i == 3)
            {
                FUN_00b0e120(1, 1);
                FUN_00b0db20(1, 1);
                bAlpha = true;
                if (DAT_0116f211)
                    FUN_00b0e190(1, 1);
            }
            else if (i == 4)
            {
                FUN_00b0e120(1, 1);
                FUN_00b0db20(1, 1);
                bAlpha = true;
                if (DAT_0116f211)
                    FUN_00b0e190(0, 1);
            }

            PassBucket& kBucket = m_pPassBucketEntries[uiRenderPassIndex].buckets[i];
            PassNode* kPos = kBucket.GetHeadPos();
            while (kPos)
            {
                void* pInfo = kBucket.GetNext(kPos);
                FUN_00b0f230(pInfo, (unsigned short)uiPass, bAlpha, arg3, 0);
            }

            if (DAT_0116f211)
            {
                DAT_01175ab0--;
                FUN_00b0e190(0, 0);
            }
            FUN_00b0e190(0, 0);
            if (DAT_01175aac)
                DAT_01175aac--;
            if (DAT_01175a70)
                DAT_01175a70--;
        }
        m_pPassBucketEntries[uiRenderPassIndex].FUN_00b0f540(false);
    }
    void FUN_00b0f700(unsigned int uiMinPass, unsigned int uiMaxPass, int arg3);
};

// Iterates active passes in range, renders matching groups via RenderGroup, then resets renderer state.
// @fnv 0x00b99e20
// pdb: BSBatchRenderer::RenderBatches | BSBatchRenderer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aePass, aePassEnd, abAlphaPass
void BatchRendererQ::FUN_00b0f700(unsigned int uiMinPass, unsigned int uiMaxPass, int arg3)
{
    unsigned int minPass = uiMinPass;
    unsigned int maxPass = uiMaxPass;
    if (uiMinPass == 0)
    {
        minPass = 1;
        maxPass = 753;
    }

    if (DAT_0116f296)
        FUN_00b3de90();

    if (!m_kActivePassList.IsEmpty())
    {
        ActivePass* pPass = &m_kActivePassList;
        while (pPass)
        {
            unsigned int item = pPass->m_item;
            if (item > maxPass || item < minPass)
            {
                pPass = pPass->m_pkNext;
                continue;
            }
            {
                unsigned int uiValue = 0;
                m_kGroupIndexMap.FUN_00bea7b0(item, uiValue);

                if (FUN_00ae6910(item) && (FUN_00ad5a50()->bFlag164 || FUN_00ad5a50()->bFlag165))
                {
                    m_pPassBucketEntries[uiValue].FUN_00b0f540(false);
                    pPass = pPass->m_pkNext;
                    continue;
                }
                RenderGroup(uiValue, item, arg3);
            }
            pPass = pPass->m_pkNext;
        }
    }

    FUN_00b0e120(1, 0);
    FUN_00b0db20(0, 0);
    FUN_00b0e510();
}
}

// @f3 0x00b0ee50 (community match, verified in this file)
namespace fo3_b0ee50 {
extern bool __cdecl FUN_00ae6910(unsigned int);
extern bool DAT_01067ee4;
struct DrawPartition
{
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
    unsigned int vertexData;
};
struct PartitionFlags
{
    unsigned char active, continuation, unk2, unk3;
};
struct SkinData
{
    unsigned int unk0, unk4, count;
    DrawPartition* partitions;
};
extern unsigned int DAT_0108f3cc;
struct SkinInstance
{
    virtual void v0();
    virtual void v1();
    virtual void* GetType();
    unsigned int unk4, unk8;
    SkinData* data;
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
    PartitionFlags* flags;
};
struct DrawShader;
struct DrawBound
{
    float x, y, z, radius;
};

extern DrawBound DAT_0108edc8;
struct DrawGeometry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    DrawBound* unk20;
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
    struct DrawData* data;
    SkinInstance* skin;
    DrawShader* shader;
    __declspec(noinline) const DrawBound& FUN_00424110() const { return unk20 ? *unk20 : DAT_0108edc8; }
};
struct DrawRenderer;
struct DrawData
{
    unsigned int unk0, unk4, unk8;
    unsigned short unkC, flags;
};
struct DrawShader
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
    virtual void Setup(DrawGeometry*, SkinInstance*, DrawPartition*, unsigned int, void*, unsigned int, void*,
                       const DrawBound&);
    virtual void v26();
    virtual void* Draw(DrawGeometry*, DrawPartition*, unsigned int, void*);
    virtual void v28();
    virtual void v29();
    virtual void Begin(void*);
    virtual void State(void*);
    virtual void Alpha(void*);
    virtual void Depth(void*);
    virtual void Blend(void*, bool);
    virtual void End(void*);
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
    virtual void Reset(void*);
};
struct DrawContext
{
    void FUN_0088b120(void*, DrawData*, SkinInstance*, unsigned int, unsigned int, unsigned int);
};
struct DrawRenderer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    void* current;
    unsigned int currentIndex;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk294;
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
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
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
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
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
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    void FUN_00872830(void*, DrawPartition*, DrawData*);
    DrawContext* context;
    void* driver;
    void SetProperties(void* properties)
    {
        current = properties;
        currentIndex = 0;
    }
};
extern DrawRenderer* DAT_0108f048;
extern unsigned int DAT_0108f3cc;
struct DrawPass
{
    DrawGeometry* geometry;
    unsigned short pass;
    unsigned char unk6;
    bool alpha;
};
inline bool S00b99110_IsExact(void* rtti, SkinInstance* obj)
{
    if (!obj)
        return false;
    return obj->GetType() == rtti;
}
// Sets up the renderer and shader, then iterates skin partitions to draw geometry with optional alpha, depth, and blend state handling.
// @fnv 0x00b99110
// pdb: BSBatchRenderer::RenderPassImmediately_Skinned | BSBatchRenderer.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apRenderPass, abAlphaTest, abAlphaPass, abGeometryRenderStates
void __cdecl FUN_00b0ee50(DrawPass* pass, bool depth, bool alpha, bool blend)
{
    unsigned int passId = pass->pass;
    DrawRenderer* renderer = DAT_0108f048;
    DrawGeometry* geometry = pass->geometry;
    SkinInstance* skin = geometry->skin;
    DrawData* data = geometry->data;
    DrawShader* shader = geometry->shader;
    SkinData* skinData = skin->data;
    unsigned int* properties = &geometry->unk9c;
    DrawPartition* partitions = skinData->partitions;
    renderer->SetProperties(properties);
    renderer->context->FUN_0088b120(renderer->driver, data, skin, 1, 0, 0);
    unsigned int count = skinData->count;
    PartitionFlags* flags = 0;
    if (S00b99110_IsExact(&DAT_0108f3cc, skin))
        flags = skin->flags;
    bool first = true;
    unsigned int i = 0;
    while (i < count)
    {
        if (!flags || flags[i].active)
        {
            DrawPartition* partition = &partitions[i];
            unsigned int vertexData = partition->vertexData;
            const DrawBound& geometryFlags = geometry->FUN_00424110();
            shader->Setup(geometry, skin, partition, vertexData, properties, 0, &geometry->unk68, geometryFlags);
            if (first)
            {
                shader->Begin(properties);
                shader->State(properties);
                if (pass->alpha && !FUN_00ae6910(passId))
                {
                    if (alpha)
                        shader->Alpha(properties);
                    if (depth && !(passId >= 4 && passId <= 5) && !(passId >= 14 && passId <= 15))
                        shader->Depth(properties);
                }
                else if (DAT_01067ee4)
                {
                    shader->Reset(properties);
                    DAT_01067ee4 = false;
                }
                if (blend)
                    shader->Blend(properties, pass->alpha);
                first = false;
            }
            void* draw = shader->Draw(geometry, partition, vertexData, properties);
            renderer->FUN_00872830(draw, partition, data);
            if (flags)
            {
                for (unsigned int next = i + 1; next < count && !flags[i + 1].continuation;)
                {
                    ++i;
                    ++next;
                    if (flags[i].active)
                    {
                        DrawPartition* p = &partitions[i];
                        unsigned int uiVertexData = p->vertexData;
                        draw = shader->Draw(geometry, p, uiVertexData, properties);
                        if (!draw)
                            return;
                        renderer->FUN_00872830(draw, p, data);
                    }
                }
            }
        }
        ++i;
    }
    geometry->data->flags &= 0xf000;
    shader->End(properties);
}
}

// @f3 0x00b00430 (community match, verified in this file)
namespace fo3_b00430 {
struct MatX
{
    float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44;
};
struct Flg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char f;
};
struct PropX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m20;
};
struct ArgX
{
    Flg* m0;
    int m4;
    int m8;
    PropX* mC;
    Flg* m10;
};
struct Sub
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
    int m34;
};
struct TransformX
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22, x, y, z, scale;
};
struct GeoX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m20;
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
    TransformX m68;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Sub* mB8;
    void* mBC;
};
struct StX
{
    GeoX* m0;
};
extern StX* DAT_0116efd0;
extern int DAT_0116efd4;
extern char DAT_0108edc8;
struct GX
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
    void* m44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* m5c;
};
extern GX* DAT_01091980;
class LstX
{
  public:
    virtual void a0(), a1(), a2(), a3(), a4(), a5(), a6(), a7(), a8(), a9(), a10(), a11(), a12(), a13(), a14(), a15(),
        a16(), a17(), a18(), a19(), a20(), a21(), a22(), a23(), a24(), a25(), a26(), a27(), a28(), a29();
    virtual void Fn(void* p, GeoX* g, void* q, int z0, int c, ArgX* a, int z1, void* t, void* n, int z2, int one);
};
class OutX
{
  public:
    virtual void b0(), b1(), b2(), b3(), b4(), b5(), b6(), b7(), b8();
    virtual void Fn(Flg* f);
};
void __cdecl FUN_00aabd50(void* t, void* p, MatX* out);
void __cdecl FUN_00b0da80(int a, int b);
void __cdecl FUN_00b0dfd0(int a, int b);
void __cdecl FUN_00afc280();
class RX
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    OutX* m1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    LstX* m30;
    LstX* m34;
    void FUN_00aff100(GeoX* g, void* t);
    void FUN_00aff810(GeoX* g, PropX* p, StX* s);
    void FUN_00afd670(GeoX* g, PropX* p, StX* s);
    void FUN_00afb610(PropX* p, StX* s, MatX m, void* t, int type, void* q);
    void FUN_00afe420(PropX* p, StX* s, GeoX* g, int c);
    void FUN_00afe0e0(StX* s, int type, void* q, void* t);
    void FUN_00afe2e0(ArgX* a, void* q, void* t);
    void FUN_00afba40(int type, void* t, MatX m);
    void FUN_00afbba0(void* q);
    void FUN_00afbc20(PropX* p);
    void FUN_00afbcd0(GeoX* g);
    void FUN_00afbc50(GeoX* g);
    void FUN_00afbd40(int type, PropX* p, GeoX* g);
    void FUN_00afbf60(int type, StX* s);
    void FUN_00afc100(int type, GeoX* g, PropX* p, int c, StX* s, Flg* f);
    void FUN_00afc240(PropX* p);
    void FUN_00afe7a0(int type);
    void FUN_00afc410(PropX* p);
    void FUN_00b00430(ArgX* a);
};
// @fnv 0x00b7dab0
// pdb: ShadowLightShader::SetupGeometryConstants | ShadowLightShader.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: apState
void RX::FUN_00b00430(ArgX* apArg)
{
    StX* s = DAT_0116efd0;
    GeoX* g = s->m0;
    int type = DAT_0116efd4;
    TransformX* t = &g->m68;
    void* n = g->m20;
    if (!n)
        n = &DAT_0108edc8;
    int c18 = g->mB8->m34;
    void* q = g->mBC;
    PropX* p = apArg->mC;
    int c = apArg->m8;
    Flg* f = apArg->m0;
    if ((type == 6 || type == 8) && (p->m20 & 0x40000) > 0 && (f->f & 1))
    {
        FUN_00b0da80(0, 1);
        FUN_00b0dfd0(0, 1);
    }
    MatX m;
    FUN_00aabd50(t, q, &m);
    if (!q)
        FUN_00aff100(g, t);
    if (type == 0x250 || type == 0x251)
    {
        FUN_00aff810(g, p, s);
    }
    else if (type == 4 || type == 5)
    {
        FUN_00afd670(g, p, s);
    }
    else
    {
        FUN_00afb610(p, s, m, t, type, q);
        FUN_00afe420(p, s, g, c);
        FUN_00afe0e0(s, type, q, t);
        FUN_00afe2e0(apArg, q, t);
        FUN_00afba40(type, t, m);
        FUN_00afbba0(q);
        FUN_00afbc20(p);
        FUN_00afbcd0(g);
        FUN_00afbc50(g);
        FUN_00afbd40(type, p, g);
        FUN_00afbf60(type, s);
        FUN_00afc100(type, g, p, c, s, f);
        FUN_00afc240(p);
        FUN_00afc280();
        FUN_00afe7a0(type);
        FUN_00afc410(p);
    }
    LstX* l30 = m30;
    if (l30)
    {
        void* d = DAT_01091980->m44;
        if (d)
            l30->Fn(d, g, q, 0, c18, apArg, 0, t, n, 0, 1);
    }
    LstX* l34 = m34;
    if (l34)
    {
        void* d = DAT_01091980->m5c;
        if (d)
            l34->Fn(d, g, q, 0, c18, apArg, 0, t, n, 0, 1);
    }
    if (apArg->m10 && (apArg->m10->f & 1))
        m1c->Fn(apArg->m10);
}
}

// @f3 0x00b0e8b0 (community match, verified in this file)
struct SortPt
{
    float x, y, z;
    float Dot(const SortPt& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
struct SortBound
{
    SortPt kTargetCenter;
    float fRadius;
};
extern SortBound DAT_0108edc8;
struct SortCamera
{
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
    unsigned int unk60;
    unsigned int unk64;
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    SortPt GetWorldTranslation() const
    {
        SortPt kPt;
        kPt.x = m00;
        kPt.y = m10;
        kPt.z = m20;
        return kPt;
    }
};
struct SortGeom
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    SortBound* pWorldBound;
    const SortBound& GetBoundingVolume() const
    {
        return pWorldBound ? *pWorldBound : DAT_0108edc8;
    }
};
struct SortPass
{
    SortGeom* pGeom;
};

struct SortPassNode { SortPassNode* m_pkNext; SortPassNode* m_pkPrev; SortPass* m_element; };
struct PassList { void* vtable; void* pHead; void* pTail; void* cache; unsigned int count; };
struct BSBatchRenderer__GeometryGroup {
    unsigned char entryType; unsigned char unk01; unsigned short m_usPassCountLocal;
    unsigned int key; void* renderer; PassList PassTextureSlotCollection; float m_fProjectionDepth;
};
struct AlphaNode { AlphaNode* next; AlphaNode* prev; BSBatchRenderer__GeometryGroup* m_element; };
struct AlphaList { AlphaNode* m_pkHead; AlphaNode* tail; struct Count { unsigned int m_uiCount; } m_kItemCount; };
extern float DAT_00db7260;
float __cdecl FUN_00401e20(float,float);
struct BSBatchRenderer_AlphaDepth {
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
    BSBatchRenderer__GeometryGroup* m_pGeometryGroups[13];
    BSBatchRenderer__GeometryGroup* m_pSecondaryGeometryGroups[2];
    AlphaList AlphaGeometryList[2];
    float FUN_00b0e8b0(int,SortCamera*,bool);
};
// @fnv 0x00b98c80
// pdb: BSBatchRenderer::GetNextAlphaDepth | BSBatchRenderer.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: aiIndex, apCamera, abGetSortByClosestPoint
float BSBatchRenderer_AlphaDepth::FUN_00b0e8b0(int iIndex, SortCamera* pkCamera, bool bUseRadius)
{
    SortPt kWorldPosition = pkCamera->GetWorldTranslation();
    BSBatchRenderer__GeometryGroup* pkGroup = m_pSecondaryGeometryGroups[iIndex];
    if (pkGroup->m_usPassCountLocal == 0 && AlphaGeometryList[iIndex].m_kItemCount.m_uiCount == 0)
        return DAT_00db7260;
    if (pkGroup->m_usPassCountLocal == 0)
        return AlphaGeometryList[iIndex].m_pkHead->m_element->m_fProjectionDepth;
    if (AlphaGeometryList[iIndex].m_kItemCount.m_uiCount == 0)
    {
        SortGeom* pkGeom = ((SortPassNode*)pkGroup->PassTextureSlotCollection.pHead)->m_element->pGeom;
        if (bUseRadius)
            return pkGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pkGeom->GetBoundingVolume().fRadius;
        return pkGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
    }
    float fListDepth = AlphaGeometryList[iIndex].m_pkHead->m_element->m_fProjectionDepth;
    SortGeom* pkGeom = ((SortPassNode*)pkGroup->PassTextureSlotCollection.pHead)->m_element->pGeom;
    if (bUseRadius)
    {
        const SortBound& kB1 = pkGeom->GetBoundingVolume();
        const SortBound& kB2 = pkGeom->GetBoundingVolume();
        return FUN_00401e20(fListDepth, kB1.kTargetCenter.Dot(kWorldPosition) - kB2.fRadius);
    }
    const SortPt& center = pkGeom->GetBoundingVolume().kTargetCenter;
    return FUN_00401e20(fListDepth, (float)(static_cast<const volatile float&>(kWorldPosition.x) * center.x +
                                            kWorldPosition.y * center.y + kWorldPosition.z * center.z));
}

// @f3 0x00b10160 (community match, verified in this file)
namespace fnv_00b9aa80 {
class MemoryManager { public: void FUN_0086ba60(void*); };
struct FUN_00825830 { virtual ~FUN_00825830(); int refCount; };
struct BSBatchRenderer { void FUN_00b0f640(int); };
struct FUN_00b0fa10 { ~FUN_00b0fa10(); };

// VC2005 compatibility: namespace-local primary for existing specialization.

extern MemoryManager DAT_01090a78;

class FUN_005fffa0
{
  public:
    ~FUN_005fffa0();
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_kItemCount;
};

class FUN_00b0f630
{
  public:
    ~FUN_00b0f630();
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
    static void operator delete[](void* p)
    {
        DAT_01090a78.FUN_0086ba60(p);
    }
};

class FUN_00496ac0
{
  public:
    ~FUN_00496ac0();
    int unk00, unk04, unk08;
};

struct FUN_00619130_Inst
{
    void FUN_00619130();
};

struct ActivePassList
{
    void* head;
    void* next;
    void FUN_00ae8980();
    ~ActivePassList()
    {
        FUN_00ae8980();
    }
};

struct FUN_00b10160 : FUN_00825830
{
    FUN_00b0f630* m_pPassBucketEntries;
    FUN_005fffa0 m_kGroupIndexMap;
    unsigned int m_uiGroupCount;
    unsigned int m_uiPassCount;
    unsigned int m_uiBucketCount;
    FUN_00619130_Inst* m_pGeometryGroupAllocator;
    ActivePassList m_kActivePassList;
    int m_iActiveGroupCount;
    bool m_bHasActiveGroups;
    FUN_00b0fa10* m_pGeometryGroups[13];
    FUN_00b0fa10* m_pSecondaryGeometryGroups[2];
    FUN_00496ac0 AlphaGeometryList[2];
    FUN_00b0fa10* m_pAlphaGeometryGroups[2];
    virtual ~FUN_00b10160();
};

// @fnv 0x00b9aa80
// pdb: BSBatchRenderer::~BSBatchRenderer | BSBatchRenderer.obj | fnv360_0822_debug, caller_sim, low
FUN_00b10160::~FUN_00b10160()
{
    ((BSBatchRenderer*)this)->FUN_00b0f640(0);
    delete[] m_pPassBucketEntries;
    FUN_00619130_Inst* pInstance = m_pGeometryGroupAllocator;
    m_uiGroupCount = 0;
    if (pInstance)
    {
        pInstance->FUN_00619130();
        DAT_01090a78.FUN_0086ba60(pInstance);
        m_pGeometryGroupAllocator = 0;
    }
    for (unsigned int i = 0; i < 13; i++)
    {
        FUN_00b0fa10* group = m_pGeometryGroups[i];
        if (group)
        {
            group->~FUN_00b0fa10();
            DAT_01090a78.FUN_0086ba60(group);
        }
    }
    FUN_00b0fa10* a = m_pSecondaryGeometryGroups[0];
    if (a)
    {
        a->~FUN_00b0fa10();
        DAT_01090a78.FUN_0086ba60(a);
    }
    a = m_pSecondaryGeometryGroups[1];
    if (a)
    {
        a->~FUN_00b0fa10();
        DAT_01090a78.FUN_0086ba60(a);
    }
}
}  // namespace fnv_00b9aa80

// @f3 0x00b0e750 (community match, verified in this file)
namespace f3_0259 {
struct SortPt
{
    float x, y, z;
    float Dot(const SortPt& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
struct SortBound
{
    SortPt kTargetCenter;
    float fRadius;
};
extern SortBound DAT_0108edc8;
extern char DAT_01175ebd;
extern int DAT_01175ec0;
struct SortCamera
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
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    SortPt GetWorldTranslation() const
    {
        SortPt kPt;
        kPt.x = m00;
        kPt.y = m10;
        kPt.z = m20;
        return kPt;
    }
};
struct SortGeom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SortBound* pWorldBound;
    const SortBound& GetBoundingVolume() const
    {
        return pWorldBound ? *pWorldBound : DAT_0108edc8;
    }
};
struct SortPass
{
    SortGeom* pGeom;
};
// @fnv 0x00b98b20
// pdb: RenderPassDepthSort | BSBatchRenderer.obj | fnv360_0822_retail, udata + bridge(udata|udata), high
int __cdecl RenderPassDepthSort(const void* apA, const void* apB)
{
    SortPass* pA = *(SortPass**)apA;
    SortPass* pB = *(SortPass**)apB;
    SortPt kWorldPosition = ((SortCamera*)DAT_01175ec0)->GetWorldTranslation();
    float fDepthB, fDepthA;
    if (DAT_01175ebd)
    {
        fDepthA =
            pA->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pA->pGeom->GetBoundingVolume().fRadius;
        fDepthB =
            pB->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pB->pGeom->GetBoundingVolume().fRadius;
    }
    else
    {
        fDepthA = pA->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
        fDepthB = pB->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
    }
    if (fDepthA == fDepthB)
        return 0;
    if (fDepthA < fDepthB)
        return 1;
    return -1;
}

}

// @f3 0x00b0ea50 (community match, verified in this file)
namespace f3m_00b0ea50 {
class BSBatchRenderer__PassList
{
  public:
    void* pHead;
    void* pTail;
    void* m_pCachedListItems;
    struct AllocatorData
    {
        unsigned int ItemUpdateArray;
    } Allocator;
    __declspec(nothrow) void FUN_00ae7440();
    __declspec(nothrow) virtual ~BSBatchRenderer__PassList()
    {
        FUN_00ae7440();
        m_pCachedListItems = pHead;
        pHead = 0;
        pTail = 0;
        Allocator.ItemUpdateArray = 0;
        FUN_00ae7440();
    }
};
struct Node
{
    Node* m_pkNext;
    Node* m_pkPrev;
    void* m_element;
};

struct FUN_00b99630_shell : public BSBatchRenderer__PassList
{
    void FUN_00b0ea50(int(__cdecl* cmp)(const void*, const void*));
};

// @fnv 0x00b99630
// pdb: BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::Sort | BSBatchRenderer.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apFunc
void FUN_00b99630_shell::FUN_00b0ea50(int(__cdecl* cmp)(const void*, const void*))
{
    FUN_00ae7440();

    if (!pHead)
        return;

    unsigned int uiRunSize = 1;
    unsigned int uiMergeCount;
    Node* tail;

    do
    {
        Node* p = (Node*)pHead;
        pHead = 0;
        tail = 0;
        uiMergeCount = 0;

        while (p)
        {
            uiMergeCount++;
            Node* pRight = p;
            int iLeftCount = 0;
            for (unsigned int i = 0; i < uiRunSize; i++)
            {
                iLeftCount++;
                pRight = pRight->m_pkNext;
                if (!pRight)
                    break;
            }

            int iRightCount = uiRunSize;

            while (iLeftCount > 0 || (iRightCount > 0 && pRight))
            {
                Node* pNode;
                if (iLeftCount == 0)
                {
                    pNode = pRight;
                    pRight = pRight->m_pkNext;
                    iRightCount--;
                }
                else if (iRightCount == 0 || !pRight)
                {
                    pNode = p;
                    p = p->m_pkNext;
                    iLeftCount--;
                }
                else if (cmp(&p->m_element, &pRight->m_element) <= 0)
                {
                    pNode = p;
                    p = p->m_pkNext;
                    iLeftCount--;
                }
                else
                {
                    pNode = pRight;
                    pRight = pRight->m_pkNext;
                    iRightCount--;
                }

                if (tail)
                {
                    tail->m_pkNext = pNode;
                }
                else
                {
                    pHead = pNode;
                }
                pNode->m_pkPrev = tail;
                tail = pNode;
            }

            p = pRight;
        }

        tail->m_pkNext = 0;
        uiRunSize *= 2;
    } while (uiMergeCount != 1);

    pTail = tail;
}
}   // namespace f3m_00b0ea50

// @f3 0x00b0f230 (community match, verified in this file)
namespace f3_0269 {
struct NiRenderer {};
extern NiRenderer* DAT_0108f048;
struct Shader_b994f0
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
    int iType;
    bool IsLit() const
    {
        return iType >= 1 && iType <= 5;
    }
    bool IsType11() const
    {
        return iType == 0x11;
    }
    void FUN_00afd570(unsigned int);
    void FUN_00b3bcb0(unsigned int);
};
struct Prop_b994f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short usFlags;
    bool GetFlag9() const
    {
        return (usFlags >> 9) & 1;
    }
};
struct Geom_b994f0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void* IsA12();
    virtual void* IsA13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void RenderImmediate55(NiRenderer*);
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
    Prop_b994f0* pProp;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    Shader_b994f0* pShader;
};
struct Pass_b994f0
{
    Geom_b994f0* pGeom;
    unsigned short m_usShaderPassType;
};

struct Handler_b994f0
{
    bool FUN_00877d60(Geom_b994f0*, int);
};
extern Handler_b994f0* DAT_0116f2f8;
extern Pass_b994f0* DAT_0116efd0;
extern unsigned int DAT_0116efd4;
extern bool DAT_0116f211;
extern Shader_b994f0* DAT_01175eb4;
extern unsigned int DAT_01175eb8;
int __cdecl FUN_00b0e190(int, int);
void __cdecl BSBatchRenderer_BeginPass(unsigned int, Shader_b994f0*);
void __cdecl FUN_00b0ee50(Pass_b994f0*, bool, bool, bool);
void __cdecl FUN_00b0ebc0(Pass_b994f0*, bool, bool, bool);

// @fnv 0x00b994f0
// pdb: BSBatchRenderer::RenderPassImmediately | BSBatchRenderer.obj | fnv360_0822_retail, call_gap, low
// pdb params: prenderpass, uicurrentPass, balphaTest, abAlphaPass, abGeometryRenderStates
void FUN_00b0f230(Pass_b994f0* prenderpass, unsigned int uiPassId, bool balphaTest, bool abAlphaPass,
                  bool abGeometryRenderStates)
{
    if (prenderpass->m_usShaderPassType != uiPassId)
        return;
    DAT_0116efd4 = uiPassId;
    DAT_0116efd0 = prenderpass;
    Shader_b994f0* pshader = prenderpass->pGeom->pShader;
    bool bfirstpass = false;
    if (DAT_01175eb8 != uiPassId || uiPassId == 0x2f6 || pshader != DAT_01175eb4)
    {
        bfirstpass = true;
        BSBatchRenderer_BeginPass(uiPassId, pshader);
    }
    if (DAT_0116f211)
    {
        Prop_b994f0* pProp = prenderpass->pGeom->pProp;
        if (pProp && pProp->GetFlag9())
            FUN_00b0e190(1, 0);
        else
            FUN_00b0e190(0, 0);
    }
    if (DAT_0116f2f8->FUN_00877d60(prenderpass->pGeom, 0))
    {
        FUN_00b0ee50(prenderpass, balphaTest, abAlphaPass, abGeometryRenderStates);
    }
    else if (prenderpass->pGeom->IsA12())
    {
        prenderpass->pGeom->RenderImmediate55(DAT_0108f048);
    }
    else if (prenderpass->pGeom->IsA13())
    {
        prenderpass->pGeom->RenderImmediate55(DAT_0108f048);
    }
    else
    {
        FUN_00b0ebc0(prenderpass, balphaTest, abAlphaPass, abGeometryRenderStates);
    }
    if (bfirstpass && DAT_01175eb4)
    {
        if (DAT_01175eb4->IsLit())
            DAT_01175eb4->FUN_00afd570(uiPassId);
        else if (DAT_01175eb4->IsType11())
            DAT_01175eb4->FUN_00b3bcb0(uiPassId);
    }
}
}  // namespace f3_0269

// @f3 0x00b0cf00 (community match, verified in this file)
#include <stdio.h>
namespace Task587 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};
extern Heap DAT_01090a78;
struct FUN_007240a0 {
    FUN_007240a0();
    virtual ~FUN_007240a0();
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
    void FUN_0086ce90(unsigned,const char*);
    void FUN_0078c030(unsigned);
    void FUN_0078c030(const char*);
    void FUN_0086ce30(int);
};
struct RenderTaskThread : FUN_007240a0 {
    void (__cdecl* task)();
    RenderTaskThread(void (__cdecl* f)()) {task=f;}
    virtual ~RenderTaskThread();
    static void* operator new(unsigned n) {return DAT_01090a78.FUN_0086b930(n);}
    static void operator delete(void* p) {DAT_01090a78.FUN_0086ba60(p);}
};
struct Owner {RenderTaskThread* threads[2];void MTRenderingSystem_AddThread(int,unsigned,void (__cdecl*)(),const char*,unsigned);};
// pdb: MTRenderingSystem::AddThread | MTRenderingSystem.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void Owner::MTRenderingSystem_AddThread(int index,unsigned affinity,void (__cdecl* task)(),const char* name,unsigned stackSize) {
    if(index<3 && index<2 && !threads[index]) {
        threads[index]=new RenderTaskThread(task);
        threads[index]->FUN_0086ce90(stackSize,name);
        threads[index]->FUN_0078c030(affinity);
        threads[index]->FUN_0086ce30(0);
        if(!name) {
            char buf[0x104];
            sprintf_s(buf,0x104,"Rendering Task Thread DEF %i",index);
            threads[index]->FUN_0078c030(buf);
        }
    }
}
}

// @f3 0x00b0c890 (community match, verified in this file)
extern float DAT_011756b4;
extern float DAT_011756b8;
extern float DAT_011756bc;
extern float DAT_011756c8;
extern float DAT_011756cc;
extern float DAT_011756d8;
extern float DAT_011756dc;
extern float DAT_011756e8;
extern float DAT_011756ec;
extern float DAT_011756f0;
extern float DAT_011756f8;
extern float DAT_011756fc;
extern float DAT_01175700;
namespace f3m_00b0c890 {
template<class T> struct PointerArrayB0 {
    virtual void Unknown00();
    T* data04;
    unsigned short capacity08;
    unsigned short size0a;
    unsigned short count0c;
    unsigned short growBy0e;
    __forceinline T& GetAt(unsigned int index) { return data04[index]; }
};
struct ConstantBufferB0 { void FUN_00b23bc0(int,float,float,float,float); };
struct BindingB0 { void FUN_006b8980(int); };
struct CacheB0 { void FUN_00b223d0(int); void FUN_00b22530(); };
struct ShaderInterfaceB0 {
    virtual void Unknown00();
    virtual void Submit04(void*,void*,ConstantBufferB0*,bool);
    void FUN_00b228d0(int,void*,int);
};
struct ShaderHeaderB0 {
    virtual void UnknownHeader00();
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
};
struct ShaderAdapterB0 : ShaderHeaderB0,ShaderInterfaceB0 {};
struct OwnerB0 {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual bool Refresh1c(void*);
    unsigned char unk04;
    bool dirty05;
    unsigned short unk06;
    PointerArrayB0<ShaderInterfaceB0*> shaders08;
    unsigned int unk18;
    ConstantBufferB0** buffers1c;
    unsigned int unk20,unk24,unk28;
    BindingB0** bindings2c;
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
    CacheB0 cache68;
    void FUN_00b0c890(void*,void*,void*,void*);
};
// pdb: ImageSpaceEffectNoise::Render | ImageSpaceEffectNoise.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apGeometry, apRenderer, apParam, abEndFrame
void OwnerB0::FUN_00b0c890(void* first,void* second,void* context,void* unused)
{
    if(dirty05) dirty05=Refresh1c(context);
    CacheB0* cache=&cache68;
    cache->FUN_00b223d0(0x31);
    ShaderAdapterB0* adapter=static_cast<ShaderAdapterB0*>(shaders08.GetAt(0));
    ShaderInterfaceB0* shader=adapter;
    ConstantBufferB0* buffer=buffers1c[0];
    buffer->FUN_00b23bc0(0,DAT_011756b8,DAT_011756bc,0.0f,0.0f);
    buffer->FUN_00b23bc0(1,DAT_011756c8,DAT_011756cc,0.0f,0.0f);
    buffer->FUN_00b23bc0(2,DAT_011756d8,DAT_011756dc,0.0f,0.0f);
    buffer->FUN_00b23bc0(3,DAT_011756b4,0.0f,0.0f,0.0f);
    buffer->FUN_00b23bc0(4,DAT_011756e8,DAT_011756ec,DAT_011756f0,0.0f);
    buffer->FUN_00b23bc0(5,DAT_011756f8,DAT_011756fc,DAT_01175700,0.0f);
    shader->FUN_00b228d0(0,cache,0);
    shader->FUN_00b228d0(1,bindings2c[1],1);
    bindings2c[0]->FUN_006b8980(3);
    bindings2c[1]->FUN_006b8980(3);
    shader->Submit04(first,second,buffer,true);
    adapter=static_cast<ShaderAdapterB0*>(shaders08.GetAt(1));
    shader=adapter;
    buffer=buffers1c[1];
    buffer->FUN_00b23bc0(0,DAT_011756b8,DAT_011756bc,0.0f,0.0f);
    buffer->FUN_00b23bc0(1,DAT_011756c8,DAT_011756cc,0.0f,0.0f);
    buffer->FUN_00b23bc0(2,DAT_011756d8,DAT_011756dc,0.0f,0.0f);
    buffer->FUN_00b23bc0(3,DAT_011756b4,0.0f,0.0f,0.0f);
    shader->FUN_00b228d0(0,bindings2c[0],0);
    shader->FUN_00b228d0(1,cache,0);
    bindings2c[0]->FUN_006b8980(3);
    bindings2c[1]->FUN_006b8980(3);
    shader->Submit04(first,second,buffer,true);
    cache->FUN_00b22530();
}
}   // namespace f3m_00b0c890

// @f3 0x00b10b50 (community match, verified in this file)
// IAT slot verified as kernel32!InterlockedCompareExchange in the local executable.

extern long (__stdcall* DAT_00d9b06c)(volatile long*,long,long);

namespace task0673 {
struct AtomicValues {long exchange;long comparand;};
inline void ReleaseOwner(volatile long* destination, AtomicValues values){DAT_00d9b06c(destination,values.exchange,values.comparand);}


struct Bound_af60

{

    float x;

    float y;

    float z;

    float radius;

};

extern Bound_af60 DAT_0108edc8;

struct Props_af60

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int m_1c;

    unsigned int m_20;

};

struct Geom_af60

{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    Bound_af60* m_20;

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

    Props_af60* m_a8;

    Bound_af60* GetBound()

    {

        return m_20 ? m_20 : &DAT_0108edc8;

    }

};

struct Item_af60

{

    Geom_af60* m_00;

    unsigned short m_04;

};

struct Node1_af60

{

    Node1_af60* m_next;

    Node1_af60* m_pSecondNode;

    Item_af60* m_data;

};

struct NodeList1_af60

{

    Node1_af60* m_pFirstNode;

    Node1_af60* m_pTail;

    Node1_af60* m_free;

    int m_uiItemCount;

    void RemoveHead()

    {

        Node1_af60* n = m_pFirstNode;

        if (n)

        {

            if (n == m_pTail)

            {

                m_pTail = 0;

            }

            Node1_af60* next = 0;

            if (m_pFirstNode->m_next)

            {

                next = n->m_next;

                next->m_pSecondNode = 0;

            }

            if (m_free)

            {

                m_free->m_pSecondNode = m_pFirstNode;

            }

            m_pFirstNode->m_next = m_free;

            m_uiItemCount--;

            m_free = m_pFirstNode;

            m_pFirstNode = next;

        }

    }

};

struct List1_af60

{

    unsigned short unk00;

    unsigned short m_02;

    int unk04;

    int unk08;

    int unk0c;

    NodeList1_af60 m_kNode;

};

struct Sub2c_af60

{

    void FUN_00ae8980();

};

struct Obj_af60

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

    virtual void SetState(int a, int b, int c);

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

    Sub2c_af60 m_2c;

};

struct Entry_af60

{

    unsigned char m_flags;

    unsigned char unk01;

    unsigned short m_02;

    int unk04;

    Obj_af60* m_08;

    int m_0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    float m_20;

    void FUN_00b0fa10();

};

struct Node2_af60

{

    Node2_af60* m_next;

    Node2_af60* m_pSecondNode;

    Entry_af60* m_data;

};

struct List2_af60

{

    Node2_af60* m_pFirstNode;

    Node2_af60* m_pTail;

    int m_uiItemCount;

    void RemoveHead();

};

struct Lock_af60

{

    long m_pOwnerObject;

    void FUN_00409a80(int a);

};

struct Mgr_af60

{

    void FUN_0086ba60(Entry_af60* e);

};

struct Point3_af60

{

    float x;

    float y;

    float z;

    Point3_af60(float ax, float ay, float az) : x(ax), y(ay), z(az)

    {}

};

struct Cam_af60

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

    float m_68;

    int unk6c;

    int unk70;

    float m_74;

    int unk78;

    int unk7c;

    float m_80;

};

extern Lock_af60 DAT_0106e5a0;

extern int DAT_0106e5a4;

extern Node2_af60* DAT_0106e588;

extern Mgr_af60 DAT_01090a78;

extern int DAT_0116efa8;

extern char DAT_01067b4f;

extern float DAT_011761d8;

extern int DAT_01175a64;

extern int DAT_01175a6c;



void __cdecl BSBatchRenderer_RenderPersistentPassList(int* p, int a);

void __cdecl FUN_00b0da80(int a, int b);

void __cdecl FUN_00b0df70(float f, int a);

void __cdecl FUN_00b0f230(Item_af60* item, unsigned int a, int b, int c, int d);

extern "C" int __cdecl _isnan(double);

struct Renderer_af60

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

    List1_af60* m_70[2];

    List2_af60 m_78[2];

    void BSBatchRenderer_RenderNextAlpha(int idx, Cam_af60* cam, bool flag, float maxDist);

};

inline void List2_af60::RemoveHead()

{

    Node2_af60* n = m_pFirstNode;

    m_pFirstNode = n->m_next;

    if (m_pFirstNode)

    {

        m_pFirstNode->m_pSecondNode = 0;

    }

    else

    {

        m_pTail = 0;

    }

    n->m_data = 0;

    DAT_0106e5a0.FUN_00409a80(0);

    n->m_pSecondNode = 0;

    n->m_next = DAT_0106e588;

    DAT_0106e5a4 -= 1;

    DAT_0106e588 = n;

    if (DAT_0106e5a4 == 0)

    {

        AtomicValues values = {0,DAT_0106e5a0.m_pOwnerObject};
        ReleaseOwner(&DAT_0106e5a0.m_pOwnerObject,values);

    }

    m_uiItemCount--;

}

static __forceinline float CalcDist(Item_af60* a, const Point3_af60& dir, bool flag)

{

    if (flag)

    {

        Bound_af60* b = a->m_00->GetBound();

        Bound_af60* b2 = a->m_00->GetBound();

        float d = b->x * dir.x + b->y * dir.y + b->z * dir.z;

        return d - b2->radius;

    }

    Bound_af60* b = a->m_00->GetBound();

    double yProduct = b->y * dir.y;
    return yProduct + b->x * dir.x + b->z * dir.z;

}

// @fnv 0x00b9af60

// pdb: BSBatchRenderer::RenderNextAlpha | BSBatchRenderer.obj | fnv360_0822_retail, udata + bridge(call_seq|caller_sim), high
void Renderer_af60::BSBatchRenderer_RenderNextAlpha(int idx, Cam_af60* cam, bool abUseRadius, float maxDist)

{

    Point3_af60 dir(cam->m_68, cam->m_74, cam->m_80);

    List1_af60* pList = m_70[idx];

    Node1_af60* n = pList->m_kNode.m_pFirstNode;

    Item_af60* a = n ? n->m_data : 0;

    float dist = 0.0f;

    if (a)

    {

        dist = CalcDist(a, dir, abUseRadius);

    }

    Entry_af60* e = m_78[idx].m_uiItemCount ? m_78[idx].m_pFirstNode->m_data : 0;

    maxDist -= 0.0010000000474974513;

    do

    {

        while (e && (e->m_20 > dist || !a) && e->m_20 >= maxDist)

        {

            if ((e->m_flags & 1) > 0)

            {

                BSBatchRenderer_RenderPersistentPassList(&e->m_0c, 1);

            }

            else if (e->m_08)

            {

                e->m_08->SetState(1, 0x2f1, 1);

            }

            if (e->m_08)

            {

                e->m_08->m_2c.FUN_00ae8980();

            }

            e->m_02 = 0;

            e->FUN_00b0fa10();

            DAT_01090a78.FUN_0086ba60(e);

            m_78[idx].RemoveHead();

            e = m_78[idx].m_uiItemCount ? m_78[idx].m_pFirstNode->m_data : 0;

        }

        if (a && dist >= maxDist)

        {

            Props_af60* p = a->m_00->m_a8;

            if (p && !(DAT_0116efa8 == 9 && (p->m_1c == 0x14 || p->m_1c == 0x10)))

            {

                bool restore;

                if ((p->m_20 & 0x4000000) > 0 || (p->m_20 & 0x8000000) > 0)

                {

                    float f = DAT_011761d8;

                    restore = true;

                    if (!DAT_01067b4f)

                    {

                        f = 0.0f;

                    }

                    FUN_00b0da80(0, 1);

                    FUN_00b0df70(f, 1);

                }

                else

                {

                    restore = false;

                }

                FUN_00b0f230(a, a->m_04, 1, 1, 1);

                if (restore)

                {

                    DAT_01175a64 -= 1;

                    FUN_00b0da80(1, 0);

                    DAT_01175a6c -= 1;

                    FUN_00b0df70(0.0f, 0);

                }

            }

            List1_af60* l = m_70[idx];

            if (l->m_kNode.m_pFirstNode)

            {

                l->m_02--;

                l->m_kNode.RemoveHead();

            }

            l = m_70[idx];

            Node1_af60* node = l->m_kNode.m_pFirstNode;

            a = node ? node->m_data : 0;

            if (a)

            {

                dist = CalcDist(a, dir, abUseRadius);

            }

        }

    } while (((a && dist >= maxDist) || (e && e->m_20 >= maxDist)));

}

}

// @f3 0x00b00c30 (community match, verified in this file)
class GraphicsRenderer;
struct NiMemObject {
    static void operator delete(void*, unsigned int);
};
struct ConstantReference : NiMemObject {
    virtual void UnknownVirtual00();
    virtual void DeleteThis();
    long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) DeleteThis(); }
};
template<class T> struct ConstantPointer {
    T* pointer;
    operator T*() const { return pointer; }
    T* operator->() const { return pointer; }
    ConstantPointer& operator=(T* value) {
        if (pointer != value) {
            if (pointer) pointer->DecRefCount();
            pointer = value;
            if (pointer) pointer->IncRefCount();
        }
        return *this;
    }
    ConstantPointer& operator=(const ConstantPointer& other) {
        if (pointer != other.pointer) {
            if (pointer) pointer->DecRefCount();
            pointer = other.pointer;
            if (pointer) pointer->IncRefCount();
        }
        return *this;
    }
};
struct NiD3DShaderConstantMap : ConstantReference {
    virtual bool AddConstant(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                             const char*, unsigned int, unsigned int, void*, void*);
    virtual void UnknownVirtual03();
    virtual void UnknownVirtual04();
    virtual void UnknownVirtual05();
    virtual void UnknownVirtual06();
    virtual void UnknownVirtual07();
    virtual void UnknownVirtual08();
    virtual void UnknownVirtual09();
    virtual void UnknownVirtual10();
    virtual void UnknownVirtual11();
    virtual void UnknownVirtual12();
    virtual void UnknownVirtual13();
    virtual void UnknownVirtual14();
    virtual void UnknownVirtual15();
    virtual void UnknownVirtual16();
    virtual void UnknownVirtual17();
    virtual void UnknownVirtual18();
    virtual void UnknownVirtual19();
    virtual void UnknownVirtual20();
    virtual void UnknownVirtual21();
    virtual void UnknownVirtual22();
    virtual void UnknownVirtual23();
    virtual void UnknownVirtual24();
    virtual void UnknownVirtual25();
    virtual bool AddNamedConstant(const char*, unsigned int, unsigned int, const char*, void*, void*, void*, void*);
    virtual void UnknownVirtual27();
    virtual ConstantReference* FindConstant(const char*);
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    static void* operator new(unsigned int);
    NiD3DShaderConstantMap(GraphicsRenderer*, unsigned int);
};
struct ShaderConstants1517 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    GraphicsRenderer* renderer18;
    unsigned int unk1C, unk20, unk24, unk28, unk2C;
    ConstantPointer<NiD3DShaderConstantMap> pixel30, vertex34;
    unsigned int unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64;
    unsigned int unk68, unk6C, unk70, unk74, unk78;
    ConstantPointer<NiD3DShaderConstantMap> pixel7C, vertex80, cachedPixel84, cachedVertex88;
    void FUN_00b00c30();
};
extern const char DAT_00db3438[]; // 
extern const char DAT_00ddeef8[]; // HairTint
extern const char DAT_00e26fec[]; // FogColor
extern const char DAT_00e27028[]; // SkinWorldTranspose
extern const char DAT_00e275bc[]; // BoneMatrix3
extern const char DAT_00e27630[]; // SkinWorldViewProjTranspose
extern const char DAT_00e276c8[]; // SkinWorldViewTranspose
extern const char DAT_00e27760[]; // WorldViewProjTranspose
extern const char DAT_00e277f0[]; // WorldViewTranspose
extern const char DAT_00e27818[]; // WorldTranspose
extern const char DAT_00e2e8dc[]; // Time
extern const char DAT_00e95f84[]; // fVars
extern const char DAT_00e95f8c[]; // Rim Color
extern const char DAT_00e95f98[]; // Fill Color
extern const char DAT_00e95fa4[]; // FogParam
extern const char DAT_00e95fb0[]; // Z scaler
extern const char DAT_00e95fbc[]; // V Offset
extern const char DAT_00e95fc8[]; // U Offset
extern const char DAT_00e95fd4[]; // FogPlane
extern const char DAT_00e95fe0[]; // FogParams
extern const char DAT_00e95fec[]; // RefractionParams
extern const char DAT_00e96000[]; // LODTEXPARAMS
extern const char DAT_00e96010[]; // STBBColorConstants
extern const char DAT_00e96024[]; // Toggles
extern const char DAT_00e9602c[]; // Emittance Color
extern const char DAT_00e9603c[]; // Light Position3
extern const char DAT_00e9604c[]; // Light Position2
extern const char DAT_00e9605c[]; // Light Position1
extern const char DAT_00e9606c[]; // Light Position0
extern const char DAT_00e9607c[]; // Light Direction
extern const char DAT_00e9608c[]; // LightColors
extern const char DAT_00e96098[]; // Ambient Color
extern const char DAT_00e960a8[]; // eye dir
extern const char DAT_00e960b0[]; // PrevBoneMatrix3
extern const char DAT_00e960c0[]; // PrevWorldViewT
extern const char DAT_00e960d0[]; // PrevWorldViewPT
extern const char DAT_00e960e0[]; // DepthData
extern const char DAT_00e960ec[]; // LODLandParams
extern const char DAT_00e960fc[]; // BoundCenter
extern const char DAT_00e96108[]; // EyePosition
extern const char DAT_00e96114[]; // FogColor | ShadowVolumeExtrudeDistance
extern const char DAT_00e9613c[]; // FogParam | ShadowVolumeFatness
extern const char DAT_00e9615c[]; // LightData
extern const char DAT_00e96168[]; // HighDetailRange
extern const char DAT_00e96178[]; // ShadowProjTransform
extern const char DAT_00e9618c[]; // ShadowProjData
extern const char DAT_00e9619c[]; // ShadowProj
extern float DAT_0116fe10;
extern float DAT_0116fe30;
extern float DAT_0116fe40;
extern float DAT_0116fe50;
extern float DAT_0116fff0;
extern float DAT_01170000;
extern float DAT_01170010;
extern float DAT_01170050;
extern float DAT_01170060;
extern float DAT_01170070;
extern float DAT_01170080;
extern float DAT_01170300;
extern float DAT_011735dc;
extern float DAT_011735e0;
extern float DAT_011735e4;
extern float DAT_011735e8;
extern float DAT_011735f4;
extern float DAT_01173604;
extern float DAT_01173614;
extern float DAT_01173624;
extern float DAT_01173634;
extern float DAT_01173644;
extern float DAT_01173654;
extern float DAT_01173664;
extern float DAT_01173674;
extern float DAT_01173684;
extern float DAT_01173694;
extern float DAT_011736a4;
extern float DAT_011736b4;
extern float DAT_011736c4;
extern float DAT_011736d4;
extern float DAT_011736e8;
extern float DAT_01173728;
extern float DAT_01173738;
extern float DAT_01173748;
extern float DAT_01173758;
extern float DAT_01173768;
extern float DAT_01174a08;
extern float DAT_01174a48;
extern float DAT_01174a88;
extern float DAT_01174ac8;
extern ConstantPointer<ConstantReference> DAT_01174958;
extern ConstantPointer<ConstantReference> DAT_0117495c;
extern ConstantPointer<ConstantReference> DAT_01174960;
extern ConstantPointer<ConstantReference> DAT_01174964;
extern ConstantPointer<ConstantReference> DAT_01174968;
extern ConstantPointer<ConstantReference> DAT_0117496c;
extern ConstantPointer<ConstantReference> DAT_01174970;
extern ConstantPointer<ConstantReference> DAT_01174974;
extern ConstantPointer<ConstantReference> DAT_01174978;
extern ConstantPointer<ConstantReference> DAT_0117497c;
extern ConstantPointer<ConstantReference> DAT_01174980;
extern ConstantPointer<ConstantReference> DAT_01174984;
extern ConstantPointer<ConstantReference> DAT_01174988;
extern ConstantPointer<ConstantReference> DAT_0117498c;
extern ConstantPointer<ConstantReference> DAT_01174990;
extern ConstantPointer<ConstantReference> DAT_01174994;
extern ConstantPointer<ConstantReference> DAT_01174998;
extern ConstantPointer<ConstantReference> DAT_0117499c;
extern ConstantPointer<ConstantReference> DAT_011749a0;
extern ConstantPointer<ConstantReference> DAT_011749a4;
extern ConstantPointer<ConstantReference> DAT_011749a8;
extern ConstantPointer<ConstantReference> DAT_011749ac;
extern ConstantPointer<ConstantReference> DAT_011749b0;
extern ConstantPointer<ConstantReference> DAT_011749b4;
extern ConstantPointer<ConstantReference> DAT_011749b8;
extern ConstantPointer<ConstantReference> DAT_011749bc;
extern ConstantPointer<ConstantReference> DAT_011749c0;
extern ConstantPointer<ConstantReference> DAT_011749c4;
extern ConstantPointer<ConstantReference> DAT_011749c8;
extern ConstantPointer<ConstantReference> DAT_011749cc;
extern ConstantPointer<ConstantReference> DAT_011749d0;
extern ConstantPointer<ConstantReference> DAT_011749d4;
extern ConstantPointer<ConstantReference> DAT_011749d8;
extern ConstantPointer<ConstantReference> DAT_011749ec;
extern ConstantPointer<ConstantReference> DAT_011749f0;
extern ConstantPointer<ConstantReference> DAT_011749f4;
extern ConstantPointer<ConstantReference> DAT_011749f8;
extern ConstantPointer<ConstantReference> DAT_011749fc;
extern ConstantPointer<ConstantReference> DAT_01174a00;
extern ConstantPointer<ConstantReference> DAT_01174a04;

// pdb: ShadowLightShader::CreateConstantMaps | ShadowLightShader.obj | fnv360_0822_retail, ustr, medium
void ShaderConstants1517::FUN_00b00c30()
{
    if (!vertex34.pointer) {
        vertex34 = new NiD3DShaderConstantMap(renderer18, 0);
        vertex34->AddNamedConstant(DAT_00e27760, 0x20000009, 0, DAT_00db3438, 0, 0, 0, 0); // WorldViewProjTranspose
        vertex34->AddNamedConstant(DAT_00e27630, 0x20000009, 1, DAT_00db3438, 0, 0, 0, 0); // SkinWorldViewProjTranspose
        vertex34->AddConstant(DAT_00e9619c, 0x10000009, 0, 18, 4, DAT_00db3438, 64, 4, &DAT_011736e8, 0); // ShadowProj
        vertex34->AddConstant(DAT_00e27028, 0x10000009, 0, 9, 4, DAT_00db3438, 64, 4, &DAT_01174a08, 0); // SkinWorldTranspose
        vertex34->AddConstant(DAT_00e27818, 0x10000009, 0, 8, 4, DAT_00db3438, 64, 4, &DAT_01174a48, 0); // WorldTranspose
        vertex34->AddConstant(DAT_00e9618c, 0x10000007, 0, 22, 1, DAT_00db3438, 16, 4, &DAT_011735f4, 0); // ShadowProjData
        vertex34->AddConstant(DAT_00e96178, 0x10000007, 0, 23, 1, DAT_00db3438, 16, 4, &DAT_01173604, 0); // ShadowProjTransform
        vertex34->AddConstant(DAT_00e96168, 0x10000007, 0, 12, 1, DAT_00db3438, 16, 4, &DAT_01170060, 0); // HighDetailRange
        vertex34->AddConstant(DAT_00e9615c, 0x10000009, 0, 25, 10, DAT_00db3438, 160, 4, &DAT_01173728, 0); // LightData
        vertex34->AddConstant(DAT_00e9613c, 0x10000007, 0, 14, 1, DAT_00db3438, 16, 4, &DAT_01170000, 0); // FogParam | ShadowVolumeFatness
        vertex34->AddConstant(DAT_00e96114, 0x10000007, 0, 15, 1, DAT_00db3438, 16, 4, &DAT_01170010, 0); // FogColor | ShadowVolumeExtrudeDistance
        vertex34->AddConstant(DAT_00e96108, 0x10000007, 0, 16, 1, DAT_00db3438, 16, 4, &DAT_01173614, 0); // EyePosition
        vertex34->AddConstant(DAT_00e960fc, 0x10000007, 0, 24, 1, DAT_00db3438, 16, 4, &DAT_01173634, 0); // BoundCenter
        vertex34->AddConstant(DAT_00e960ec, 0x10000007, 0, 19, 1, DAT_00db3438, 16, 4, &DAT_0116fe30, 0); // LODLandParams
        vertex34->AddConstant(DAT_00e960e0, 0x10000007, 0, 17, 1, DAT_00db3438, 16, 4, &DAT_011736d4, 0); // DepthData
        vertex34->AddConstant(DAT_00e960d0, 0x10000009, 0, 35, 4, DAT_00db3438, 64, 4, &DAT_01174a88, 0); // PrevWorldViewPT
        vertex34->AddConstant(DAT_00e960c0, 0x10000009, 0, 39, 4, DAT_00db3438, 64, 4, &DAT_01174ac8, 0); // PrevWorldViewT
        vertex34->AddConstant(DAT_00e275bc, 0x20000009, 0x120000, 44, 54, 0, 0, 0, 0, 0); // BoneMatrix3
        vertex34->AddNamedConstant(DAT_00e277f0, 0x20000009, 4, DAT_00db3438, 0, 0, 0, 0); // WorldViewTranspose
        vertex34->AddNamedConstant(DAT_00e276c8, 0x20000009, 5, DAT_00db3438, 0, 0, 0, 0); // SkinWorldViewTranspose
        vertex34->AddConstant(DAT_00e2e8dc, 0x10000004, 0, 13, 1, DAT_00db3438, 4, 4, &DAT_011735e8, 0); // Time
        vertex34->AddConstant(DAT_00e960b0, 0x10000009, 0, 98, 54, DAT_00db3438, 0x360, 4, &DAT_01170300, 0); // PrevBoneMatrix3
        DAT_01174958 = vertex34->FindConstant(DAT_00e27760); // WorldViewProjTranspose
        DAT_0117495c = vertex34->FindConstant(DAT_00e27818); // WorldTranspose
        DAT_01174988 = vertex34->FindConstant(DAT_00e27028); // SkinWorldTranspose
        DAT_01174960 = vertex34->FindConstant(DAT_00e27630); // SkinWorldViewProjTranspose
        DAT_01174964 = vertex34->FindConstant(DAT_00e9619c); // ShadowProj
        DAT_01174968 = vertex34->FindConstant(DAT_00e9618c); // ShadowProjData
        DAT_0117496c = vertex34->FindConstant(DAT_00e96178); // ShadowProjTransform
        DAT_01174998 = vertex34->FindConstant(DAT_00e96168); // HighDetailRange
        DAT_01174970 = vertex34->FindConstant(DAT_00e9615c); // LightData
        DAT_01174974 = vertex34->FindConstant(DAT_00e9613c); // FogParam | ShadowVolumeFatness
        DAT_01174978 = vertex34->FindConstant(DAT_00e96114); // FogColor | ShadowVolumeExtrudeDistance
        DAT_0117497c = vertex34->FindConstant(DAT_00e96108); // EyePosition
        DAT_01174980 = vertex34->FindConstant(DAT_00e275bc); // BoneMatrix3
        DAT_0117498c = vertex34->FindConstant(DAT_00e277f0); // WorldViewTranspose
        DAT_01174990 = vertex34->FindConstant(DAT_00e276c8); // SkinWorldViewTranspose
        DAT_01174994 = vertex34->FindConstant(DAT_00e2e8dc); // Time
        DAT_0117499c = vertex34->FindConstant(DAT_00e960fc); // BoundCenter
        DAT_011749ac = vertex34->FindConstant(DAT_00e960ec); // LODLandParams
        DAT_011749a0 = vertex34->FindConstant(DAT_00e960e0); // DepthData
        DAT_011749a4 = vertex34->FindConstant(DAT_00e960d0); // PrevWorldViewPT
        DAT_011749a8 = vertex34->FindConstant(DAT_00e960c0); // PrevWorldViewT
        DAT_01174984 = vertex34->FindConstant(DAT_00e960b0); // PrevBoneMatrix3
        cachedVertex88 = vertex34;
    }
    if (!pixel30.pointer) {
        pixel30 = new NiD3DShaderConstantMap(renderer18, 2);
        pixel30->AddConstant(DAT_00e960a8, 0x10000007, 0, 0, 1, DAT_00db3438, 16, 4, &DAT_01173624, 0); // eye dir
        pixel30->AddConstant(DAT_00e96098, 0x10000007, 0, 1, 1, DAT_00db3438, 16, 4, &DAT_0116fe40, 0); // Ambient Color
        pixel30->AddConstant(DAT_00e9608c, 0x10000009, 0, 3, 10, DAT_00db3438, 160, 4, &DAT_0116fe50, 0); // LightColors
        pixel30->AddConstant(DAT_00e9607c, 0x10000007, 0, 18, 1, DAT_00db3438, 16, 4, &DAT_01173728, 0); // Light Direction
        pixel30->AddConstant(DAT_00e9606c, 0x10000007, 0, 19, 1, DAT_00db3438, 16, 4, &DAT_01173738, 0); // Light Position0
        pixel30->AddConstant(DAT_00e9605c, 0x10000007, 0, 20, 1, DAT_00db3438, 16, 4, &DAT_01173748, 0); // Light Position1
        pixel30->AddConstant(DAT_00e9604c, 0x10000007, 0, 21, 1, DAT_00db3438, 16, 4, &DAT_01173758, 0); // Light Position2
        pixel30->AddConstant(DAT_00e9603c, 0x10000007, 0, 22, 1, DAT_00db3438, 16, 4, &DAT_01173768, 0); // Light Position3
        pixel30->AddConstant(DAT_00e9602c, 0x10000007, 0, 2, 1, DAT_00db3438, 16, 4, &DAT_0116fff0, 0); // Emittance Color
        pixel30->AddConstant(DAT_00e96108, 0x10000007, 0, 17, 1, DAT_00db3438, 16, 4, &DAT_01173614, 0); // EyePosition
        pixel30->AddConstant(DAT_00e96024, 0x10000007, 0, 27, 1, DAT_00db3438, 16, 4, &DAT_01170050, 0); // Toggles
        pixel30->AddConstant(DAT_00ddeef8, 0x10000007, 0, 28, 1, DAT_00db3438, 16, 4, &DAT_0116fe10, 0); // HairTint
        pixel30->AddConstant(DAT_00e96010, 0x10000007, 0, 30, 1, DAT_00db3438, 16, 4, &DAT_01170070, 0); // STBBColorConstants
        pixel30->AddConstant(DAT_00e96000, 0x10000007, 0, 31, 1, DAT_00db3438, 16, 4, &DAT_01170080, 0); // LODTEXPARAMS
        pixel30->AddConstant(DAT_00e95fec, 0x10000004, 0, 29, 1, DAT_00db3438, 4, 4, &DAT_011736c4, 0); // RefractionParams
        pixel30->AddConstant(DAT_00e95fe0, 0x10000004, 0, 14, 1, DAT_00db3438, 4, 4, &DAT_01173644, 0); // FogParams
        pixel30->AddConstant(DAT_00e26fec, 0x10000004, 0, 15, 1, DAT_00db3438, 4, 4, &DAT_01173654, 0); // FogColor
        pixel30->AddConstant(DAT_00e95fd4, 0x10000004, 0, 16, 1, DAT_00db3438, 4, 4, &DAT_01173664, 0); // FogPlane
        DAT_011749ec = pixel30->FindConstant(DAT_00ddeef8); // HairTint
        DAT_011749b0 = pixel30->FindConstant(DAT_00e960a8); // eye dir
        DAT_011749b4 = pixel30->FindConstant(DAT_00e96098); // Ambient Color
        DAT_011749b8 = pixel30->FindConstant(DAT_00e9608c); // LightColors
        DAT_011749c8 = pixel30->FindConstant(DAT_00e9607c); // Light Direction
        DAT_011749cc = pixel30->FindConstant(DAT_00e9606c); // Light Position0
        DAT_011749d0 = pixel30->FindConstant(DAT_00e9605c); // Light Position1
        DAT_011749d4 = pixel30->FindConstant(DAT_00e9604c); // Light Position2
        DAT_011749d8 = pixel30->FindConstant(DAT_00e9603c); // Light Position3
        DAT_011749bc = pixel30->FindConstant(DAT_00e9602c); // Emittance Color
        DAT_011749c4 = pixel30->FindConstant(DAT_00e96108); // EyePosition
        DAT_011749c0 = pixel30->FindConstant(DAT_00e96024); // Toggles
        DAT_011749f0 = pixel30->FindConstant(DAT_00e95fec); // RefractionParams
        DAT_011749f4 = pixel30->FindConstant(DAT_00e95fe0); // FogParams
        DAT_011749f8 = pixel30->FindConstant(DAT_00e26fec); // FogColor
        DAT_011749fc = pixel30->FindConstant(DAT_00e95fd4); // FogPlane
        DAT_01174a00 = pixel30->FindConstant(DAT_00e96000); // LODTEXPARAMS
        DAT_01174a04 = pixel30->FindConstant(DAT_00e96010); // STBBColorConstants
        cachedPixel84 = pixel30;
    }
    if (!vertex80.pointer) {
        vertex80 = new NiD3DShaderConstantMap(renderer18, 0);
        vertex80->AddNamedConstant(DAT_00e27760, 0x20000009, 0, DAT_00db3438, 0, 0, 0, 0); // WorldViewProjTranspose
        vertex80->AddNamedConstant(DAT_00e27630, 0x20000009, 4, DAT_00db3438, 0, 0, 0, 0); // SkinWorldViewProjTranspose
        vertex80->AddConstant(DAT_00e275bc, 0x20000009, 0x120000, 14, 54, 0, 0, 0, 0, 0); // BoneMatrix3
        vertex80->AddConstant(DAT_00e96108, 0x10000007, 0, 8, 1, DAT_00db3438, 16, 4, &DAT_01173614, 0); // EyePosition
        vertex80->AddConstant(DAT_00e95fc8, 0x10000004, 0, 9, 1, DAT_00db3438, 4, 4, &DAT_011735dc, 0); // U Offset
        vertex80->AddConstant(DAT_00e95fbc, 0x10000004, 0, 10, 1, DAT_00db3438, 4, 4, &DAT_011735e0, 0); // V Offset
        vertex80->AddConstant(DAT_00e95fb0, 0x10000004, 0, 11, 1, DAT_00db3438, 4, 4, &DAT_011735e4, 0); // Z scaler
        vertex80->AddConstant(DAT_00e95fa4, 0x10000007, 0, 12, 1, DAT_00db3438, 16, 4, &DAT_011736b4, 0); // FogParam
        vertex80->AddConstant(DAT_00e26fec, 0x10000007, 0, 13, 1, DAT_00db3438, 16, 4, &DAT_011736a4, 0); // FogColor
    }
    if (!pixel7C.pointer) {
        pixel7C = new NiD3DShaderConstantMap(renderer18, 2);
        pixel7C->AddConstant(DAT_00e95f98, 0x10000007, 0, 0, 1, DAT_00db3438, 16, 4, &DAT_01173674, 0); // Fill Color
        pixel7C->AddConstant(DAT_00e95f8c, 0x10000007, 0, 1, 1, DAT_00db3438, 16, 4, &DAT_01173684, 0); // Rim Color
        pixel7C->AddConstant(DAT_00e95f84, 0x10000007, 0, 2, 1, DAT_00db3438, 16, 4, &DAT_01173694, 0); // fVars
    }
}

// @f3 0x00b0fc90 (community match, verified in this file)
namespace f3m_00b0fc90 {

class MemoryManager { public: void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern MemoryManager DAT_01090a78;
class BSBatchRenderer;
class BSBatchRenderer__PassList
{
  public:
    void* pHead;
    void* pTail;
    void* m_pCachedListItems;
    struct AllocatorData
    {
        unsigned int ItemUpdateArray;
    } Allocator;
    __declspec(nothrow) void ResetPassList();
    __declspec(nothrow) virtual ~BSBatchRenderer__PassList()
    {
        ResetPassList();
        m_pCachedListItems = pHead;
        pHead = 0;
        pTail = 0;
        Allocator.ItemUpdateArray = 0;
        ResetPassList();
    }
};
class BSBatchRenderer__GeometryGroup
{
  public:
    unsigned char m_ucEntryType;
    unsigned char padding1;
    unsigned short m_usPassCountLocal;
    unsigned int auiGroupKey;
    BSBatchRenderer* m_pGroupRenderer;
    BSBatchRenderer__PassList PassTextureSlotCollection;
    float m_fProjectionDepth;
    void ClearPassTextureSlots();
    ~BSBatchRenderer__GeometryGroup();
};


extern void* __cdecl FUN_0089e810(unsigned int);
extern "C" void* __cdecl FUN_00c00610(void*, int, unsigned int);
extern "C" void _ReadWriteBarrier();
extern const void* DAT_00e96928[];
extern const void* DAT_00e022ec[];
extern const void* DAT_00e0230c[];

class FUN_00825800
{
  public:
    const void** vptr;
    unsigned int refCount;
    FUN_00825800();
    ~FUN_00825800();
};
struct MapBase
{
    const void** vptr;
    unsigned int hashSize;
    void** buckets;
    unsigned int count;
    MapBase() : vptr(DAT_00e022ec), hashSize(37), count(0)
    {
        buckets = (void**)FUN_0089e810(37 * sizeof(void*));
        struct S
        {
            unsigned int s;
        };
        S sz = {hashSize * sizeof(void*)};
        FUN_00c00610(buckets, 0, sz.s);
    }
    ~MapBase();
};
struct RenderMap : MapBase
{
    RenderMap(int)
    {
        vptr = DAT_00e0230c;
    }
    ~RenderMap();
};
struct ActiveList
{
    unsigned short item;
    ActiveList* next;
    ActiveList()
    {
        item = 0;
        next = 0;
    }
    ~ActiveList();
};
struct AlphaList
{
    void* head;
    void* tail;
    unsigned int count;
    __declspec(noinline) AlphaList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    __declspec(noinline) ~AlphaList()
    {
        FUN_00bd12d0();
    }
    void FUN_00bd12d0();
};
struct FUN_00b5b350
{
    int data;
    FUN_00b5b350();
    static void* operator new(size_t n)
    {
        return DAT_01090a78.FUN_0086b930(n);
    }
    static void operator delete(void* p)
    {
        DAT_01090a78.FUN_0086ba60(p);
    }
};
struct RenderPassListCollection
{
    BSBatchRenderer__PassList lists[5];
    unsigned int count;
    RenderPassListCollection();
    ~RenderPassListCollection();
    static void* operator new[](size_t n)
    {
        return DAT_01090a78.FUN_0086b930(n);
    }
    static void operator delete[](void* p)
    {
        DAT_01090a78.FUN_0086ba60(p);
    }
};
struct FUN_00b0fc40 : BSBatchRenderer__GeometryGroup
{
    FUN_00b0fc40(void*) throw();
    static void* operator new(size_t n)
    {
        return DAT_01090a78.FUN_0086b930(n);
    }
};

struct AudioTlsState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int context;
};
extern __declspec(thread) AudioTlsState g_taskMemoryTls;
struct MemGuard
{
    unsigned int oldContext;
    MemGuard(unsigned int value)
    {
        oldContext = g_taskMemoryTls.context;
        g_taskMemoryTls.context = value;
    }
    ~MemGuard()
    {
        g_taskMemoryTls.context = oldContext;
    }
};

class FUN_00b0fc90 : public FUN_00825800
{
  public:
    RenderPassListCollection* passes;
    RenderMap map;
    unsigned int passCount;
    unsigned int firstPass;
    unsigned int lastPass;
    FUN_00b5b350* instance;
    ActiveList active;
    int grouping;
    bool zPrePass;
    FUN_00b0fc40* groups[13];
    FUN_00b0fc40* alpha[2];
    AlphaList alphaLists[2];
    FUN_00b0fc40* currentAlpha[2];
    FUN_00b0fc90(unsigned int count, int mode);
    void FUN_00b0f640(int);
};

// @fnv 0x00b9a5b0
// pdb: BSBatchRenderer::BSBatchRenderer | BSBatchRenderer.obj | fnv360_0822_retail, call_gap, low
// pdb params: auiPassCount, aeBatchRendererCreationType
FUN_00b0fc90::FUN_00b0fc90(unsigned int aiPassCount, int mode) : map((vptr = DAT_00e96928, 0))
{
    MemGuard context(0x26);
    instance = new FUN_00b5b350;
    passes = new RenderPassListCollection[aiPassCount];
    passCount = aiPassCount;
    grouping = 0;
    FUN_00b0f640(0);
    switch (mode)
    {
    case 99:
        groups[0] = new FUN_00b0fc40((void*)0x2f7);
        groups[1] = new FUN_00b0fc40((void*)0x2f7);
        groups[2] = new FUN_00b0fc40((void*)0x2f7);
        groups[3] = new FUN_00b0fc40((void*)0x2f7);
        groups[4] = new FUN_00b0fc40((void*)0x2f7);
        groups[5] = new FUN_00b0fc40((void*)0x2f7);
        groups[6] = new FUN_00b0fc40((void*)6);
        groups[7] = new FUN_00b0fc40((void*)1);
        groups[8] = new FUN_00b0fc40((void*)4);
        groups[9] = new FUN_00b0fc40((void*)0x2f7);
        groups[10] = new FUN_00b0fc40((void*)0x2f7);
        groups[11] = new FUN_00b0fc40((void*)6);
        groups[12] = new FUN_00b0fc40((void*)4);
        alpha[0] = new FUN_00b0fc40((void*)0x2f7);
        alpha[1] = new FUN_00b0fc40((void*)0x2f7);
        alpha[0]->m_ucEntryType |= 1;
        alpha[1]->m_ucEntryType |= 1;
        alphaLists[0].FUN_00bd12d0();
        alphaLists[1].FUN_00bd12d0();
        break;
    case 100:
        groups[0] = 0;
        groups[1] = 0;
        groups[2] = 0;
        groups[3] = 0;
        groups[4] = 0;
        groups[5] = 0;
        groups[6] = 0;
        groups[7] = 0;
        groups[8] = 0;
        groups[9] = 0;
        groups[10] = 0;
        groups[11] = 0;
        groups[12] = 0;
        alpha[0] = 0;
        alpha[1] = 0;
        break;
    case 101:
        groups[0] = 0;
        groups[1] = 0;
        groups[2] = 0;
        groups[3] = 0;
        groups[4] = 0;
        groups[5] = 0;
        groups[6] = 0;
        groups[7] = 0;
        groups[8] = 0;
        groups[9] = new FUN_00b0fc40((void*)0x2f7);
        groups[10] = 0;
        groups[11] = 0;
        groups[12] = 0;
        alpha[0] = new FUN_00b0fc40((void*)0x2f7);
        alpha[1] = new FUN_00b0fc40((void*)0x2f7);
        alpha[0]->m_ucEntryType |= 1;
        alpha[1]->m_ucEntryType |= 1;
        alphaLists[0].FUN_00bd12d0();
        alphaLists[1].FUN_00bd12d0();
        break;
    }
}
}   // namespace f3m_00b0fc90

// @f3 0x00b1cca0 (community match, verified in this file)
extern __declspec(thread) unsigned int g_tlsAllocTag;
namespace f3m_00b1cca0 {
class NiTexture; class BSRenderedTexture;
namespace task1124 {

struct TLSTagGuard
{
    unsigned int uiOld;
    TLSTagGuard(unsigned int uiTag)
    {
        uiOld = g_tlsAllocTag;
        g_tlsAllocTag = uiTag;
    }
    ~TLSTagGuard()
    {
        g_tlsAllocTag = uiOld;
    }
};

struct ISTexture
{
    bool b0;
    bool b1;
    bool b2;
    void* pTileTexture;
    int i8;
    int iC;
    ISTexture() : b0(false), b1(false), b2(false), pTileTexture(0), i8(0), iC(0)
    {}
    ~ISTexture();
    void FUN_00b22380(NiTexture* apTex);
    void FUN_00b22330(BSRenderedTexture* apTex);
};

struct ISEffectShader
{
    virtual void vf0();
    virtual void Render(void* apGeom, void* apArg2, void* apArg5, void* apArg6);
    void FUN_00b228d0(unsigned int uiIndex, ISTexture* apTex, int iFilter);
};

struct ImageSpaceOwner
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
    void* pGeom1f0;
    int unk1f4;
    void* pGeom1f8;
    bool bUseAlt;
    void FUN_00b1cca0(ISEffectShader* apShader, void* apArg2, NiTexture* apSource, BSRenderedTexture* apDest,
                      void* apArg5, void* apArg6);
};

// @fnv 0x00b8c980
// pdb: ImageSpaceManager::RenderEffect | ImageSpaceManager.obj | fnv360_1110_retail, call_seq, medium
// pdb params: apEffect, apRenderer, apSourceBuffer, apDestinationBuffer, apParam, abEndFrame
void ImageSpaceOwner::FUN_00b1cca0(ISEffectShader* apShader, void* apArg2, NiTexture* apSource,
                                   BSRenderedTexture* apDest, void* apArg5, void* apArg6)
{
    TLSTagGuard kGuard(0x27);
    ISTexture kSource;
    ISTexture kDest;
    kSource.FUN_00b22380(apSource);
    kDest.FUN_00b22330(apDest);
    if (apShader)
    {
        apShader->FUN_00b228d0(0, &kDest, 0);
        apShader->FUN_00b228d0(1, &kSource, 0);
        void** ppGeom = bUseAlt ? &pGeom1f8 : &pGeom1f0;
        void* pGeom = *ppGeom;
        apShader->Render(pGeom, apArg2, apArg5, apArg6);
        apShader->FUN_00b228d0(0, 0, 0);
        apShader->FUN_00b228d0(1, 0, 0);
    }
}

}
}   // namespace f3m_00b1cca0

// @f3 0x00b0f0d0 (community match, verified in this file)
namespace PassSetupFast

{

struct Texture;
extern Texture* DAT_01091a20[16];
struct Shader202 { void FUN_00b00830(); };
struct Shader209 { void FUN_00b00830(); };

extern void __cdecl FUN_00b0e510();

class Shader

{

public:

    virtual void Slot000();

    virtual void Slot004();

    virtual void Slot008();

    virtual void Slot00C();

    virtual void Slot010();

    virtual void Slot014();

    virtual void Slot018();

    virtual void Slot01C();

    virtual void Slot020();

    virtual void Slot024();

    virtual void Slot028();

    virtual void Slot02C();

    virtual void Slot030();

    virtual void Slot034();

    virtual void Slot038();

    virtual void Slot03C();

    virtual void Slot040();

    virtual void Slot044();

    virtual void Slot048();

    virtual void Slot04C();

    virtual void Slot050();

    virtual void Slot054();

    virtual void Slot058();

    virtual void Slot05C();

    virtual void Slot060();

    virtual void Slot064();

    virtual void Slot068();

    virtual void Slot06C();

    virtual void Slot070();

    virtual void Slot074();

    virtual void Slot078();

    virtual void Slot07C();

    virtual void Slot080();

    virtual void Slot084();

    virtual void Slot088();

    virtual void Slot08C();

    virtual void Slot090();

    virtual void Slot094();

    virtual void Slot098();

    virtual void Slot09C();

    virtual void Slot0A0();

    virtual void Slot0A4();

    virtual void Slot0A8();

    virtual void Slot0AC();

    virtual void Slot0B0();

    virtual void Slot0B4();

    virtual void Slot0B8();

    virtual void Slot0BC();

    virtual void Slot0C0();

    virtual void Slot0C4();

    virtual void Slot0C8();

    virtual void Slot0CC();

    virtual void Slot0D0();

    virtual void Slot0D4();

    virtual void Slot0D8();

    virtual void Slot0DC();

    virtual void Slot0E0();

    virtual void Slot0E4();

    virtual void Slot0E8();

    virtual void Slot0EC();

    virtual void BeginPass(unsigned int pass);

    virtual void SetPassStateF4(unsigned int pass);

    virtual void SetPassStateF8(unsigned int pass);

    virtual void SetPassStateFC(unsigned int pass);

    virtual void SetPassState100(unsigned int pass);

    void FUN_00b006d0();

    void FUN_00b00830();

};

extern unsigned short DAT_01068974;

extern Shader* DAT_01175eb4;

extern unsigned int DAT_01175eb8;

extern bool DAT_01067ee4;

extern void __cdecl FUN_00b0da30(bool first,int second);

}



// pdb: BSBatchRenderer::BeginPass | BSBatchRenderer.obj | fnv360_0822_retail, udata + bridge(call_gap|udata), high
void __cdecl BSBatchRenderer_BeginPass(unsigned int pass,PassSetupFast::Shader* shader)

{

    using namespace PassSetupFast;

    FUN_00b0e510();

    DAT_01068974=0xffff;

    shader->BeginPass(pass);

    for (int i=0;i<16;i++) DAT_01091a20[i]=0;

    switch(pass)

    {

    case 252:

    case 253:

        shader->FUN_00b006d0();

        FUN_00b0da30(true,0);

        break;

    case 258:

        shader->FUN_00b006d0();

        break;

    case 202:

        ((Shader202*)shader)->FUN_00b00830();

        break;

    case 209:

        ((Shader209*)shader)->FUN_00b00830();

        break;

    default:

        shader->SetPassStateFC(pass);

        shader->SetPassStateF8(pass);

        shader->SetPassState100(pass);

        break;

    }

    shader->SetPassStateF4(pass);

    DAT_01175eb8=pass;

    DAT_01175eb4=shader;

    DAT_01067ee4=true;

}

// @f3 0x00b10860 (community match, verified in this file)
class BSBatchRenderer__PassList {
public:
    virtual void Slot0();
    void* head;
    unsigned int count;
    void* spare;
    unsigned int extra;

    BSBatchRenderer__PassList() throw() : head(0), count(0), spare(0) {}
    void FUN_00ae7440() throw();
    __forceinline void Clear() throw()
    {
        FUN_00ae7440();
        void* previous = head;
        head = 0;
        count = 0;
        extra = 0;
        spare = previous;
    }
    __forceinline void Reset() throw()
    {
        FUN_00ae7440();
        spare = head;
        head = 0;
        count = 0;
        extra = 0;
    }
};

namespace RenderPlanes {

struct Plane {
    float x, y, z, offset;
};
struct Axis {
    float x, y, z;
};
struct Transform {
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
    unsigned int unk60;
    unsigned int unk64;
    Axis basis[3];
};

struct Heap {
    void* FUN_0086b930(unsigned int size);
};
extern Heap DAT_01090a78;
struct PlaneLink {
    void FUN_00b0f640(int index);
};
struct RenderPlane {
    unsigned char flags;
    unsigned short passCount;
    unsigned int material;
    PlaneLink* link;
    BSBatchRenderer__PassList passes;
    float distance;

    __forceinline RenderPlane() throw()
    {
        flags = 0;
        link = 0;
        material = 0x2f7;
        passCount = 0;
        passes.Reset();
    }
    static void* operator new(unsigned int size) throw() { return DAT_01090a78.FUN_0086b930(size); }
};

struct Node {
    Node* next;
    Node* previous;
    RenderPlane* data;
};
struct PoolLock {
    volatile long owner;
    unsigned int recursion;
    void FUN_00409a80(const char* source);
};
extern PoolLock DAT_0106e5a0;
extern Node* DAT_0106e588;
extern long (__stdcall* DAT_00d9b06c)(volatile long*, long, long);
void __cdecl FUN_00422ab0();
struct AtomicValues { long exchange; long comparand; };
inline void ReleaseOwner(volatile long* destination, AtomicValues values) { DAT_00d9b06c(destination, values.exchange, values.comparand); }

struct NodeCount {
    unsigned int size;
    Node* FUN_00423640();
};
struct PlaneList {
    Node* head;
    Node* tail;
    NodeCount count;
};

struct Owner {
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
    unsigned int requestCount;
    bool mode;
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
    PlaneList lists[2];
    RenderPlane* planes[2];

    void FUN_00b10860(const Plane& plane, bool mode, const Transform* transform, bool subtractOffset);
};

// pdb: BSBatchRenderer::StartGroupingAlphas | BSBatchRenderer.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aBound, abZPrePass, apCamera, abGetSortByClosestPoint
void Owner::FUN_00b10860(const Plane& plane, bool newMode, const Transform* transform, bool subtractOffset)
{
    if (!requestCount && transform) {
        for (int i = 0; i < 2; i++) {
            RenderPlane* entry = new RenderPlane;
            entry->passes.Reset();
            if (entry->link)
                entry->link->FUN_00b0f640(0);
            entry->passCount = 0;
            if (subtractOffset) {
                const Axis normal = { transform->basis[0].x, transform->basis[1].x, transform->basis[2].x };
                const float distance = plane.x * normal.x + plane.y * normal.y + plane.z * normal.z;
                entry->distance = distance - plane.offset;
            } else {
                const Axis normal = { transform->basis[0].x, transform->basis[1].x, transform->basis[2].x };
                entry->distance = plane.x * normal.x + plane.y * normal.y + plane.z * normal.z;
            }
            if (!newMode)
                entry->flags |= 1;
            else
                entry->flags &= 0xfe;

            bool inserted = false;
            Node* current = lists[i].head;
            while (!inserted && current) {
                const float currentDistance = current->data->distance;
                if (currentDistance < entry->distance) {
                    DAT_0106e5a0.FUN_00409a80(0);
                    Node* node = DAT_0106e588;
                    if (!node) {
                        FUN_00422ab0();
                        node = DAT_0106e588;
                    }
                    DAT_0106e588 = node->next;
                    node->data = 0;
                    node->next = 0;
                    node->previous = 0;
                    if (--DAT_0106e5a0.recursion == 0)
                    {
                    AtomicValues values = {0, DAT_0106e5a0.owner};
                    ReleaseOwner(&DAT_0106e5a0.owner, values);
                }

                    node->data = entry;
                    node->next = current;
                    node->previous = current->previous;
                    if (current->previous)
                        current->previous->next = node;
                    else
                        lists[i].head = node;
                    current->previous = node;
                    ++lists[i].count.size;
                    inserted = true;
                }
                current = current->next;
            }
            if (!inserted) {
                PlaneList* list = &lists[i];
                Node* node = list->count.FUN_00423640();
                node->data = entry;
                node->next = 0;
                node->previous = list->tail;
                if (list->tail)
                    list->tail->next = node;
                else
                    list->head = node;
                ++list->count.size;
                list->tail = node;
            }

            planes[i] = entry;
        }
        mode = newMode;
    }
    ++requestCount;
}

} // namespace RenderPlanes

// @f3 0x00b102a0 (community match, verified in this file)
namespace f3m_00b102a0 {
namespace task1564 {
struct NiProperty99
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
    bool GetAlphaBlending() const
    {
        return (bool)(m_usFlags & 1);
    }
    bool GetAlphaTesting() const
    {
        return (bool)((m_usFlags >> 9) & 1);
    }
};
struct ShaderProperty99
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
    unsigned int m_uiValue1;
    float m_fAlpha;
    float m_fFadeAlpha;
};
struct Geometry99
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
    NiProperty99* m_pkAlphaProperty;
    int unka0;
    int unka4;
    ShaderProperty99* m_pkShaderProperty;
    NiProperty99* m_pkStencilProperty;
};
struct RenderPass99
{
    Geometry99* m_pkRenderableGeometry;
    unsigned short m_usPassEnum;
    unsigned char unk06;
    bool m_bIsAlpha;
};
struct PassNode99 {PassNode99* next;PassNode99* previous;RenderPass99* pass;};
struct PassSubGroup99 {
 PassNode99* head;PassNode99* tail;unsigned int unknown08;PassNode99* freeNodes;unsigned int count;
};
struct PassGroup99 {
 PassSubGroup99 groups[5];int m_iArrayLength;
 void FUN_00b0f540(bool bFree);
 void FUN_00b0fb60(int iMode,RenderPass99* pkPass);
 void FUN_00b0fbd0(int iMode,RenderPass99* pkPass);
 bool IsEmpty()const{return m_iArrayLength==0;}
};
struct PassMap99
{
    bool FUN_00bea7b0(unsigned int uiKey, unsigned int& uiValue) const;
    void FUN_00880f70(unsigned int uiKey, unsigned int uiValue);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
};
struct PassList99
{
    void FUN_00b0f470(unsigned int uiPass, int(__cdecl* pfnCompare)(unsigned short, unsigned short));
};
int __cdecl FUN_00b0e4f0(unsigned short usA, unsigned short usB);
struct S00b99c90_Shell
{
    int unk00;
    int unk04;
    PassGroup99* m_pPassBucketEntries;
    PassMap99 m_kGroupIndexMap;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    PassList99 m_kActivePassList;
    void FUN_00b102a0(RenderPass99* pkPass, unsigned int uiPassEnum);
};
// Classifies the pass using shader, stencil, and alpha state, ensures its pass enum has a group index, then adds it to a pass bucket.
// pdb: BSBatchRenderer::RegisterPass | BSBatchRenderer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apRenderPass, auiPassEnum
void S00b99c90_Shell::FUN_00b102a0(RenderPass99* pkPass, unsigned int uiPassEnum)
{
    if (!pkPass || !pkPass->m_pkRenderableGeometry)
        return;
    Geometry99* pkGeometry = pkPass->m_pkRenderableGeometry;
    bool bStencil = false;
    ShaderProperty99* pkShaderProp = pkGeometry->m_pkShaderProperty;
    if (pkPass->m_pkRenderableGeometry->m_pkStencilProperty &&
        (pkGeometry->m_pkStencilProperty->m_usFlags & 0xc00) == 0xc00)
        bStencil = true;
    bool bAlpha = false;
    NiProperty99* pkAlphaProp = pkGeometry->m_pkAlphaProperty;
    if (pkAlphaProp)
    {
        bAlpha = pkAlphaProp->GetAlphaTesting() && pkPass->m_bIsAlpha;
        if (bAlpha && (pkShaderProp->m_fAlpha < 1.0f || pkShaderProp->m_fFadeAlpha < 1.0f) &&
            !pkGeometry->m_pkAlphaProperty->GetAlphaBlending() && uiPassEnum != 2)
            bAlpha = false;
    }
    if (uiPassEnum == 0xe || uiPassEnum == 0xf || uiPassEnum == 4 || uiPassEnum == 5 || uiPassEnum == 0x23a)
        bAlpha = true;
    int iGroup;
    if ((pkShaderProp->m_uiValue1 & 0x400000) > 0)
        iGroup = 4;
    else if (bAlpha)
        iGroup = bStencil ? 2 : 3;
    else
        iGroup = bStencil ? 1 : 0;
    unsigned int uiPass = pkPass->m_usPassEnum;
    if (uiPassEnum)
        uiPass = uiPassEnum;
    unsigned int uiFound;
    unsigned int uiIndex;
    if (!m_kGroupIndexMap.FUN_00bea7b0(uiPass, uiFound))
    {
        uiIndex = m_kGroupIndexMap.m_uiCount;
        m_kGroupIndexMap.FUN_00880f70(uiPass, uiIndex);
        m_pPassBucketEntries[uiIndex].FUN_00b0f540(false);
    }
    else
        uiIndex = uiFound;
    PassGroup99* const buckets = *reinterpret_cast<PassGroup99* const volatile*>(&m_pPassBucketEntries);
    if (buckets[uiIndex].IsEmpty())
        m_kActivePassList.FUN_00b0f470(uiPass, FUN_00b0e4f0);
    if (pkPass->m_bIsAlpha && (uiPass < 0x238 || uiPass > 0x23e))
        m_pPassBucketEntries[uiIndex].FUN_00b0fb60(iGroup, pkPass);
    else
        m_pPassBucketEntries[uiIndex].FUN_00b0fbd0(iGroup, pkPass);
}
}




}   // namespace f3m_00b102a0

// @f3 0x00b0fa90 (community match, verified in this file)
namespace f3m_00b0fa90 {
struct SimpleArray {
  void** m_ppVirtualMethodTable;
  unsigned int pBuffer;
  unsigned int iSize;
  unsigned int iAllocSize;
  unsigned int unk10;
  void FUN_00ae7440();
  void Reset() {
    unsigned int buffer = pBuffer;
    iAllocSize = buffer;
    pBuffer = 0;
    iSize = 0;
    unk10 = 0;
  }
};

struct PlaneLink {
  void FUN_00b0f640(int);
};

struct FUN_00b0fc40 {
  unsigned char flag;
  unsigned char unk01;
  unsigned short count;
  void* owner;
  int unk08;
  SimpleArray items;
  void BSBatchRenderer_GeometryGroup_ClearPasses();
};

// pdb: BSBatchRenderer::GeometryGroup::ClearPasses | BSBatchRenderer.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
void FUN_00b0fc40::BSBatchRenderer_GeometryGroup_ClearPasses() {
  items.FUN_00ae7440();
  items.Reset();
  if (unk08 != 0)
    reinterpret_cast<PlaneLink*>(unk08)->FUN_00b0f640(0);
  count = 0;
}
}   // namespace f3m_00b0fa90

// @f3 0x00b0f430 (community match, verified in this file)
struct Heap {
    void* FUN_0086b930(unsigned);
    void FUN_0086ba60(void*);
};

extern Heap DAT_01090a78;

struct Node {
    unsigned short unk00;
    unsigned short pad02;
    Node* next;
    void FUN_00ae8980();
};

struct Container {
    unsigned short unk00;
    unsigned short pad02;
    Node* items;
    void FUN_00b0f430();
};

// pdb: BSSimpleList<unsigned short>::RemoveHead | BSBatchRenderer.obj | fnv360_0822_retail, call_gap, low
void Container::FUN_00b0f430()
{
    Node* node = items;
    if (node)
    {
        items = node->next;
        unk00 = node->unk00;
        node->next = 0;
        node->FUN_00ae8980();
        DAT_01090a78.FUN_0086ba60(node);
    }
    else
    {
        unk00 = 0;
    }
}

// @f3 0x00b1f340 (community match, verified in this file)
namespace f3m_00b1f340 {
struct BufferMethods {
    void* unk00;
    void* unk04;
    void (__stdcall* release)(void*);
};
extern BufferMethods DAT_00e9e794;
struct BufferHeap {
    void FUN_0086ba60(void*);
};
extern BufferHeap DAT_01090a78;
struct Buffer {
    BufferMethods* methods;
    void* data;
    unsigned int size;
    unsigned int capacity;
    void* FUN_00b1f340(unsigned int flags);
};
void* Buffer::FUN_00b1f340(unsigned int flags)
{
    methods = &DAT_00e9e794;
    if (data) {
        DAT_00e9e794.release(data);
        data = 0;
        capacity = 0;
        size = 0;
    }
    if (flags & 1)
        DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}   // namespace f3m_00b1f340

// @f3 0x00b0f5d0 (community match, verified in this file)
namespace f3m_00b0f5d0 {
struct FUN_00b0f5d0_Node
{
    FUN_00b0f5d0_Node* next;
    FUN_00b0f5d0_Node* prev;
    void* element;
};

struct FUN_00b0f5d0_Pool
{
    unsigned int count;
    FUN_00b0f5d0_Node* FUN_00423640();
};

struct FUN_00b0f5d0_List
{
    int unk00;
    FUN_00b0f5d0_Node* head;
    FUN_00b0f5d0_Node* tail;
    FUN_00b0f5d0_Node* freeList;
    FUN_00b0f5d0_Pool pool;
    void FUN_00b0f5d0(void* const& value);
};

// pdb: BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::AddHead | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: atElement
void FUN_00b0f5d0_List::FUN_00b0f5d0(void* const& value)
{
    FUN_00b0f5d0_Node* node;
    if (!freeList) {
        node = pool.FUN_00423640();
    } else {
        node = freeList;
        freeList = node->next;
    }
    node->element = value;
    node->next = head;
    node->prev = 0;
    if (head) {
        head->prev = node;
        ++pool.count;
        head = node;
    } else {
        ++pool.count;
        tail = node;
        head = node;
    }
}
}   // namespace f3m_00b0f5d0

// @f3 0x00b09cb0 (community match, verified in this file)
namespace f3m_00b09cb0 {
class MemoryManager { public: void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern void (__stdcall *DAT_00e967b0)(void*);

class Foo {
public:
    void* vptr;
    void* buf;
    unsigned int sz;
    unsigned int cap;
    void* FUN_00b09cb0(unsigned char flag);
};

void* Foo::FUN_00b09cb0(unsigned char flag)
{
    void* b = buf;
    vptr = (void*)0x00e967a8;
    if (b) {
        DAT_00e967b0(b);
        buf = 0;
        cap = 0;
        sz = 0;
    }
    if (flag & 1) DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}   // namespace f3m_00b09cb0

// @f3 0x00b0ebc0 (community match, verified in this file)
namespace f3m_00b0ebc0 {
struct OwnerB0EB;

typedef fo3_b0ee50::DrawRenderer RendererB0EB;

struct PropertyB0EB {
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
    void* value34;
};

struct OperationB0EB {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Finish6c(OwnerB0EB*,int,void*,void*);
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Start78(void*);
    virtual void Start7c(void*);
    virtual void Apply80(void*);
    virtual void Apply84(void*);
    virtual void Apply88(void*,unsigned int);
    virtual void End8c(void*);
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Unknownc0();
    virtual void Unknownc4();
    virtual void Unknownc8();
    virtual void Unknowncc();
    virtual void Unknownd0();
    virtual void Unknownd4();
    virtual void Unknownd8();
    virtual void Unknowndc();
    virtual void Unknowne0();
    virtual void Unknowne4();
    virtual void Unknowne8();
    virtual void Unknownec();
    virtual void Unknownf0();
    virtual void Unknownf4();
    virtual void Unknownf8();
    virtual void Unknownfc();
    virtual void Unknown100();
    virtual void Unknown104();
    virtual void Unknown108();
    virtual void Unknown10c();
    virtual void Apply110(void*);
    void FUN_00b00760(void*);
    void FUN_00b00ad0(void*);
    void FUN_00b00850(void*);
    void FUN_00b00960(void*);
};

struct OwnerB0EB {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0c();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1c();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2c();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3c();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4c();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5c();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6c();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7c();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8c();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9c();
    virtual void Unknowna0();
    virtual void Unknowna4();
    virtual void Unknowna8();
    virtual void Unknownac();
    virtual void Unknownb0();
    virtual void Unknownb4();
    virtual void Unknownb8();
    virtual void Unknownbc();
    virtual void Unknownc0();
    virtual void Unknownc4();
    virtual void Unknownc8();
    virtual void Unknowncc();
    virtual void Unknownd0();
    virtual void Unknownd4();
    virtual void Unknownd8();
    virtual void Unknowndc();
    virtual void Restoree0(RendererB0EB*);
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
    unsigned int data9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    PropertyB0EB* propertyb8;
    unsigned int unkbc;
    OperationB0EB* operationc0;
};

struct DescriptionB0EB { OwnerB0EB* owner00; unsigned short selector04; unsigned char unk06; unsigned char tag07; };

// pdb: BSBatchRenderer::RenderPassImmediately_Standard | BSBatchRenderer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apRenderPass, abAlphaTest, abAlphaPass, abGeometryRenderStates
void __cdecl FUN_00b0ebc0(DescriptionB0EB* description,bool applyFirst,bool applySecond,bool applyTag)
{
    unsigned int selector = description->selector04;
    RendererB0EB* renderer = fo3_b0ee50::DAT_0108f048;
    OwnerB0EB* owner = description->owner00;

    PropertyB0EB* property=owner->propertyb8;
    OperationB0EB* operation=owner->operationc0;
    void* data=&owner->data9c;

    renderer->SetProperties(data);
    renderer->context->FUN_0088b120(renderer->driver,reinterpret_cast<fo3_b0ee50::DrawData*>(property),0,0,0,0);

    void* value=property->value34;

    switch(selector) {
    case 0xfc:
    case 0xfd:
        operation->FUN_00b00760(data);
        if(applyFirst) operation->Apply84(data);
        if(applySecond) operation->Apply80(data);
        break;
    case 0x102:
        operation->FUN_00b00ad0(data);
        if(applyFirst) operation->Apply84(data);
        if(applySecond) operation->Apply80(data);
        break;
    case 0xca:
        operation->FUN_00b00850(data);
        if(applyFirst) operation->Apply84(data);
        if(applySecond) operation->Apply80(data);
        if(applyTag) operation->Apply88(data,description->tag07);
        break;
    case 0xd1:
        operation->FUN_00b00960(data);
        if(applyFirst) operation->Apply84(data);
        if(applySecond) operation->Apply80(data);
        if(applyTag) operation->Apply88(data,description->tag07);
        break;
    default:
        operation->Start78(data);
        operation->Start7c(data);
        if(description->tag07) {
            if(applySecond&&!fo3_b0ee50::FUN_00ae6910(selector)) operation->Apply80(data);
            if(applyFirst&&(selector<4||selector>5)&&(selector<14||selector>15)&&selector!=0x23a)
                operation->Apply84(data);
        } else if(fo3_b0ee50::DAT_01067ee4&&!fo3_b0ee50::FUN_00ae6910(selector)) {
            operation->Apply110(data);
            fo3_b0ee50::DAT_01067ee4=false;
        }
        if(applyTag) operation->Apply88(data,description->tag07);
        break;
    }

    operation->Finish6c(owner,0,value,data);
    owner->Restoree0(renderer);
    operation->End8c(data);
}
}   // namespace f3m_00b0ebc0

// @f3 0x00b1f310 (community match, verified in this file)
extern const char DAT_00e9e794[];
namespace f3m_00b1f310 {
extern void (__stdcall *DAT_00e9e79c)(void*);

struct U {
    unsigned u0;
    void* p4;
    unsigned u8;
    unsigned uC;
    void FUN_00b1f310();
};

// pdb: hkArrayBase<hkpWorldRayCastOutput>::clear | BGSDecalManager.obj | fnv360_0822_debug, objrun_open, low
void U::FUN_00b1f310()
{
    void* eax = p4;
    u0 = (unsigned)DAT_00e9e794;
    if (eax) {
        DAT_00e9e79c(eax);
        p4 = 0;
        uC = 0;
        u8 = 0;
    }
}
}   // namespace f3m_00b1f310

// @f3 0x00b1ce20 (community match, verified in this file)
extern __declspec(thread) unsigned int g_tlsAllocTag;
namespace f3m_00b1ce20 {
struct ObjectB1ce20 {
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
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 unsigned unkac;
 unsigned unkb0;
 void FUN_00b1ce20(unsigned x);
};
// pdb: ImageSpaceManager::SetOverrideBaseParameterData | ImageSpaceManager.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: Script::GetHeader)
// pdb params: apParameterData
void ObjectB1ce20::FUN_00b1ce20(unsigned x) {
 unsigned old=g_tlsAllocTag;
 unkb0=x;
 g_tlsAllocTag=old;
}
}   // namespace f3m_00b1ce20

// @f3 0x00b1d860 (community match, verified in this file)
extern __declspec(thread) unsigned int g_tlsAllocTag;
namespace f3m_00b1d860 {
struct AllocationTagGuardB1d860 {
 unsigned saved;
 AllocationTagGuardB1d860(unsigned tag) : saved(g_tlsAllocTag) {g_tlsAllocTag=tag;}
 ~AllocationTagGuardB1d860() {g_tlsAllocTag=saved;}
};
struct CallerB1d860 {
 unsigned unk00,unk04;
 void** entries;
 void FUN_00b1cb50(void*,int,int,int,int,int);
 void FUN_00b1d860(unsigned,int,int,int,int,int);
};
// pdb: ImageSpaceManager::RenderEffect | ImageSpaceManager.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiEffect, apRenderer, apSourceBuffer, apDestinationBuffer, apParam, abEndFrame
void CallerB1d860::FUN_00b1d860(unsigned index,int b,int c,int d,int e,int f) {
 AllocationTagGuardB1d860 guard(0x27);
 FUN_00b1cb50(entries[index],b,c,d,e,f);
}
}   // namespace f3m_00b1d860

// @f3 0x00b1d900 (community match, verified in this file)
extern __declspec(thread) unsigned int g_tlsAllocTag;
namespace f3m_00b1d900 {
struct AllocationTagGuardB1d900 {
 unsigned saved;
 AllocationTagGuardB1d900(unsigned tag) : saved(g_tlsAllocTag) {g_tlsAllocTag=tag;}
 ~AllocationTagGuardB1d900() {g_tlsAllocTag=saved;}
};
struct CallerB1d900 {
 unsigned unk00,unk04;
 void** entries;
 void FUN_00b1cca0(void*,int,int,int,int,int);
 void FUN_00b1d900(unsigned,int,int,int,int,int);
};
// pdb: ImageSpaceManager::RenderEffect | ImageSpaceManager.obj | fnv360_1110_retail, call_gap, low
// pdb params: aiEffect, apRenderer, apSourceBuffer, apDestinationBuffer, apParam, abEndFrame
void CallerB1d900::FUN_00b1d900(unsigned index,int b,int c,int d,int e,int f) {
 AllocationTagGuardB1d900 guard(0x27);
 FUN_00b1cca0(entries[index],b,c,d,e,f);
}
}   // namespace f3m_00b1d900

// @f3 0x00b0f640 (community match, verified in this file)
namespace f3m_00b0f640 {
namespace f3m_00b0f640 {
typedef void* MapIterator;

struct MapItem;
struct Map
{
    virtual ~Map();
    unsigned int m_uiHashSize;
    MapItem** m_ppHashTable;
    unsigned int m_uiCount;

    MapIterator GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppHashTable[i])
                return m_ppHashTable[i];
        }
        return 0;
    }
    void FUN_0089a5d0(MapIterator& pos, unsigned int& key, unsigned int& value) const;
};

struct Slot
{
    void FUN_00ae7440();
    int unk00;
    int m_i04;
    int m_i08;
    int m_i0c;
    unsigned int m_uiCount;
};

struct Record
{
    Slot m_akSlots[5];
    int m_i64;
};

struct Cache
{
    void FUN_00ae8980();
};
}

struct f3m_00b0f640_Owner
{
    int unk00;
    int unk04;
    f3m_00b0f640::Record* m_pRecords;
    f3m_00b0f640::Map m_kMap;
    int unk1c; int unk20; int unk24; int unk28;
    f3m_00b0f640::Cache m_kCache;

    void FUN_00b0f640(int unused);
};

// pdb: BSBatchRenderer::ClearRenderPasses | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: abReportUnrendered
void f3m_00b0f640_Owner::FUN_00b0f640(int unused)
{
    f3m_00b0f640::MapIterator pos = m_kMap.GetFirstPos();
    while (pos)
    {
        unsigned int key;
        unsigned int index;
        m_kMap.FUN_0089a5d0(pos, key, index);
        f3m_00b0f640::Record* __restrict record = &m_pRecords[index];
        for (int i = 0; i < 5; i++)
        {
            f3m_00b0f640::Slot& slot = record->m_akSlots[i];
            if (slot.m_uiCount > 0)
            {
                slot.FUN_00ae7440();
                slot.m_i0c = slot.m_i04;
                slot.m_i04 = 0;
                slot.m_i08 = 0;
                slot.m_uiCount = 0;
            }
        }
        record->m_i64 = 0;
    }
    m_kCache.FUN_00ae8980();
}
}   // namespace f3m_00b0f640

// @f3 0x00b0eb60 (community match, verified in this file)
extern Heap DAT_01090a78;
namespace f3m_00b0eb60 {
namespace ListB0eb60 {
struct Heap {void* FUN_0086b930(unsigned);};
struct Node {
 unsigned short count;
 Node* head;
 Node(unsigned short value):count(value),head(0) {}
 static void* operator new(unsigned size) throw() {return DAT_01090a78.FUN_0086b930(size);}
 static void operator delete(void*);
};
struct Owner {
 unsigned short count;
 Node* head;
 void FUN_00b0eb60(Owner*);
};
// pdb: BSSimpleList<unsigned short>::AddHead | BSBatchRenderer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: item
void Owner::FUN_00b0eb60(Owner* arg) {
 unsigned short nextCount=arg->count;
 if(nextCount) {
  if(count) {
   Node* node=new Node(count);
   node->head=head;
   head=node;
   count=arg->count;
  } else count=nextCount;
 }
}
}
}   // namespace f3m_00b0eb60

// @f3 0x00b0f580 (community match, verified in this file)
namespace f3m_00b0f580 {
// Model of FUN_00b0f580 (80 bytes) - fresh claim, give_ups=0 ✓✓ thiscall with one stack parameter ('retn 4'), returning nothing. The pack declares only 5 thread-locals and the body touches none ✓✓
//   push esi ; mov esi,ecx ; mov eax,[esi+0Ch] ; test eax,eax ; jnz 0xB0F594       - 'this' to ESI; the cached free-node pointer at +0x0C decides where the node comes from ✓✓ 
//      (empty case) lea ecx,[esi+10h] ; call sub_423640                            - ECX is the ADDRESS of +0x10, so that helper is a member of an object embedded at this+0x10 - and it RETURNS
//                                                                                     the node in EAX (their build jumps to the shared tail using whatever EAX holds; nothing is re-read from
//                                                                                     +0x0C on this path) ✓✓ so the source assigns from the call ✓✓ 
//      (reuse case) mov ecx,[eax] ; mov [esi+0Ch],ecx                              - pop the free chain: freeNode := node->next, with EAX keeping the popped node ✓✓ 
//   0xB0F599: mov edx,[esp+4+arg_0] ; mov ecx,[edx] ; mov [eax+8],ecx              - node+8 := the pointer stored inside the parameter object at its +0 (two dereferences) ✓✓ 
//   mov dword ptr [eax], 0                                                         - node->next = 0, written with an IMMEDIATE here (their build did not cache a zero register in this
//                                                                                     function, unlike 0x422a30) ✓✓ so a plain literal is right ✓✓ 
//   mov edx,[esi+8] ; mov [eax+4],edx                                              - node+4 := the current tail at this+0x08 (a back link) ✓✓ 
//   mov ecx,[esi+8] ; test ecx,ecx                                                - the tail is read a SECOND time rather than reused from EDX ✓✓ (stores through EAX may alias, so VC8 reloads;
//                                                                                     repeating the member access in source reproduces it) ✓✓ 
//      jz 0xB0F5C2 → else branch: add dword ptr [esi+10h],1 ; mov [esi+4],eax ; mov [esi+8],eax    - empty list: set BOTH head (+0x04) and tail, and the counter at +0x10 is incremented
//                                                                                     inside each branch (it appears twice in the machine code, so the source duplicated it rather than sharing one
//                                                                                     statement after the if) ✓✓ 
//      taken branch: mov [ecx],eax ; add dword ptr [esi+10h],1 ; mov [esi+8],eax    - old tail's next := node, then count++, then tail := node ✓✓ 
//   pop esi ; retn 4 in both shapes                                                ✓✓ 

namespace f3m_00b0f580 {

struct NodeB0F;                                     // forward declaration for the chain type ✓✓

struct CounterB0F {                                 // embedded at this+0x10: its own address is the receiver of FUN_00423640, and its first field is the +0x10 counter ✓✓
    unsigned long count;                            // +0x00 relative (this+0x10): ORIG 'add dword ptr [esi+10h],1' in both branches ✓✓ 
    struct NodeB0F* FUN_00423640();                 // ORIG: lea ecx,[esi+10h] ; call sub_423640 - a member of this embedded object returning the freshly obtained node in EAX ✓✓ 
};

struct NodeB0F {                                    // an intrusive list node ✓✓
    struct NodeB0F* next;                           // +0x00: ORIG 'mov dword ptr [eax], 0' and 'mov [ecx],eax' ✓✓ 
    struct NodeB0F* back;                           // +0x04: ORIG 'mov edx,[esi+8] ; mov [eax+4],edx' - the previous tail ✓✓ 
    void* payload;                                  // +0x08: ORIG reads it out of the parameter object's own first dword ✓✓ 
};

struct ListB0F {                                    // 'this' (ESI) ✓✓
    char pad04[0x04];
    struct NodeB0F* head;                           // +0x04: set only when the list was empty ✓✓ 
    struct NodeB0F* tail;                           // +0x08: read twice, then updated in both branches ✓✓ 
    struct NodeB0F* freeNode;                       // +0x0C: a cached node to reuse, popped from its own chain ✓✓ 
    struct CounterB0F counter;                      // +0x10 ✓✓ 

    void FUN_00b0f580(void** parameter);            // thiscall with one stack parameter (retn 4) ✓✓ the parameter is dereferenced once to obtain the payload pointer ✓✓
};

// pdb: BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::AddTail | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: atElement
void ListB0F::FUN_00b0f580(void** parameter) {
    struct NodeB0F* node;

    if (this->freeNode == 0)                        // ORIG: mov eax,[esi+0Ch] ; test eax,eax ; jnz reuse ✓✓ 
        node = this->counter.FUN_00423640();        // ORIG: lea ecx,[esi+10h] ; call sub_423640 - the embedded counter object is the receiver, and its result becomes the node ✓✓ 
    else {
        node = this->freeNode;                      // ORIG: EAX already holds it ✓✓ 
        this->freeNode = node->next;                // ORIG: mov ecx,[eax] ; mov [esi+0Ch],ecx - pop the free chain ✓✓ 
    }

    node->payload = *parameter;                     // ORIG: mov edx,[esp+4+arg_0] ; mov ecx,[edx] ; mov [eax+8],ecx - one dereference into the parameter object ✓✓ 
    node->next = 0;                                 // ORIG: mov dword ptr [eax], 0 - an immediate zero ✓✓ 
    node->back = this->tail;                        // ORIG: mov edx,[esi+8] ; mov [eax+4],edx ✓✓ 

    if (this->tail != 0) {                          // ORIG re-reads [esi+8] here instead of reusing EDX ✓✓ 
        this->tail->next = node;                    // ORIG: mov [ecx],eax ✓✓ 
        this->counter.count += 1;                   // ORIG: add dword ptr [esi+10h],1 - duplicated inside each branch ✓✓ 
        this->tail = node;                          // ORIG: mov [esi+8],eax ✓✓ 
    } else {
        this->counter.count += 1;                   // ORIG 0xB0F5C2: add dword ptr [esi+10h],1 first here too ✓✓ 
        this->head = node;                          // ORIG: mov [esi+4],eax - the only place the head is written ✓✓ 
        this->tail = node;                          // ORIG: mov [esi+8],eax ✓✓ 
    }
}

}
}   // namespace f3m_00b0f580

// @f3 0x00b0fad0 (community match, verified in this file)
namespace f3m_00b0fad0 {
namespace ActionB0fad0 {
struct State { void FUN_00ae8980(); };
struct Target {
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
virtual void action(int,int,void*);
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
State state;
};
struct Payload { int unk00; };
void BSBatchRenderer_RenderPersistentPassList(Payload*,void*);
struct Object { unsigned char flags,unk01; unsigned short count; int unk04; Target* target; Payload payload; void BSBatchRenderer_GeometryGroup_Render(void*); };
// pdb: BSBatchRenderer::GeometryGroup::Render | BSBatchRenderer.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Object::BSBatchRenderer_GeometryGroup_Render(void* value) {
 if((flags&1)>0u) BSBatchRenderer_RenderPersistentPassList(&payload,value);
 else { Target* object=target; if(object) object->action(1,0x2f1,value); }
 Target* object=target;
 if(object) object->state.FUN_00ae8980();
 count=0;
}
}
}   // namespace f3m_00b0fad0

// @f3 0x00b0fa10 (community match, verified in this file)
extern const char DAT_00e94aec[];
namespace f3m_00b0fa10 {
namespace DestroyB0fa10 {
struct Target {virtual ~Target();};
struct Array {
 const void* table; void* data; unsigned count; void* previous; unsigned capacity;
 void FUN_00ae7440() throw();
 __forceinline ~Array(){
 table=DAT_00e94aec;
 FUN_00ae7440();
 previous=data;
 data=0;
 count=0;
 capacity=0;
 FUN_00ae7440();
 }
};
struct FUN_00b0fa10 {int unk00,unk04;Target* target;Array array;~FUN_00b0fa10();};
// pdb: BSBatchRenderer::GeometryGroup::~GeometryGroup | BSBatchRenderer.obj | fnv360_0822_retail, call_dedup, low
FUN_00b0fa10::~FUN_00b0fa10(){if(target){delete target;target=0;}}
}

}   // namespace f3m_00b0fa10

// @f3 0x00b10420 (community match, verified in this file)
namespace f3m_00b10420 {
namespace Query299 {
struct Leaf {int unk00;char unk04,unk05,unk06,value;};struct Value {int unk00,unk04;Leaf* leaf;};struct Cell {int unk00;Value* value;int unk08,unk0c,unk10;};struct Row {Cell cells[5];int tail;};struct Map {void FUN_00bea7b0(void*,int*);};
struct Object {int unk00,unk04;Row* rows;Map map;bool FUN_00b0e710(int,int*);bool FUN_00b0f980(void**,int*);bool BSBatchRenderer_PrepareNextRenderPass(void**,int*,char*);};
// pdb: BSBatchRenderer::PrepareNextRenderPass | BSBatchRenderer.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
bool Object::BSBatchRenderer_PrepareNextRenderPass(void** key,int* column,char* out){bool result=true;int row=0;if(!*key){result=FUN_00b0f980(key,column);}else{map.FUN_00bea7b0(*key,&row);if(!FUN_00b0e710(row,column))result=FUN_00b0f980(key,column);}if(result){map.FUN_00bea7b0(*key,&row);*out=rows[row].cells[*column].value->leaf->value;}return result;}
}

}   // namespace f3m_00b10420

// @f3 0x00b0e710 (community match, verified in this file)
namespace f3m_00b0e710 {
struct Class00b0e710 {
    char unk00[8];
    char* m_pTable;
    bool FUN_00b0e710(int row, int* outIndex);
};
// pdb: BSBatchRenderer::PrepareNextRenderPass_SetNextBucket | BSBatchRenderer.obj | fnv360_0822_retail, call_dedup, low
// pdb params: auiIndex, aiBucket
bool Class00b0e710::FUN_00b0e710(int row, int* outIndex)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (*(int*)((char*)m_pTable + (row * 0x68 + i * 0x14) + 4) != 0)
        {
            *outIndex = i;
            i = 5;
        }
    }
    return i == 6;
}
}   // namespace f3m_00b0e710

// @f3 0x00b0e190 (community match, verified in this file)
namespace f3m_00b0e190 {
struct RenderState
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64();
    virtual void SetRenderState(unsigned int state, unsigned int value, bool save, bool restore);
};

struct Renderer
{
    RenderState* GetRenderState() { return *(RenderState**)((char*)this + 0x8b8); }
};

extern Renderer* DAT_0116f2f8;
extern int DAT_0116f2a8;
extern int DAT_01175ab0;

inline unsigned int FloatBits(float value)
{
    return *(unsigned int*)&value;
}

void __cdecl FUN_00b0e190(bool enable, int delta)
{
    if (DAT_01175ab0 == 0)
    {
        if (DAT_0116f2a8 == 1)
            DAT_0116f2f8->GetRenderState()->SetRenderState(0xb5, enable ? 0x434f5441 : FloatBits(0.0f), false, false);
        else if (DAT_0116f2a8 == 2)
            DAT_0116f2f8->GetRenderState()->SetRenderState(0x9a, enable ? 0x314d3241 : 0x304d3241, false, false);
    }
    DAT_01175ab0 += delta;
}
}

// @f3 0x00b107a0 (community match, verified in this file)
namespace f3m_00b107a0 {
namespace Group399 {
extern "C" void* __cdecl FUN_0089eb90(unsigned int);
extern "C" void __cdecl FUN_0089e890(void*);
struct Item { int unk00; unsigned short key; };
struct FUN_00b0fc90 {
virtual void slot00();
virtual void slot04();
virtual void slot08();
virtual void slot0c();
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
virtual void insert(Item*,unsigned int);
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
FUN_00b0fc90(void*,int);
static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); }
static void operator delete(void* p) { FUN_0089e890(p); }
};
struct List { void FUN_00b0f5d0(Item**); void FUN_00b0f580(Item**); };
struct Group {
unsigned char flags,unk01; unsigned short count; void* owner; FUN_00b0fc90* map; List list;
void FUN_00b107a0(Item*,bool);
};
// pdb: BSBatchRenderer::GeometryGroup::RegisterPass | BSBatchRenderer.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apRenderPass, abAddToFront
void Group::FUN_00b107a0(Item* item,bool front) {
 if((flags&1u)>0) {
  if(front) list.FUN_00b0f5d0(&item);
  else list.FUN_00b0f580(&item);
 } else {
  if(!map) map=new FUN_00b0fc90(owner,100);
  unsigned int key=item->key;
  map->insert(item,key);
 }
 ++count;
}
}

}   // namespace f3m_00b107a0

// @f3 0x00b0f370 (community match, verified in this file)
namespace f3m_00b0f370 {
namespace Pass419 {
struct Item {void* geometry;unsigned short pass;};
struct Node {Node* next;Node* previous;Item* value;};
struct List {
 void* vtable;Node* head;Node* tail;Node* freeNodes;unsigned count;
 void FUN_00ae7440();
 Item* next(Node*& position) { Item* const& value=position->value; position=position->next; return value; }
};
void FUN_00b0e510();
void FUN_00b0f230(Item*,unsigned,int,int,int);
// pdb: BSBatchRenderer::RenderPersistentPassList | BSBatchRenderer.obj | fnv360_0822_retail, call_seq + bridge(call_gap|caller_sim), high
void BSBatchRenderer_RenderPersistentPassList(List* list,int context) {
 if(list->count>0) {
  FUN_00b0e510();
  Node* position=list->head;
  if(position) {
   Item* item=list->next(position);
   while(item) {
    if(item->geometry) FUN_00b0f230(item,item->pass,1,context,1);
    if(!position) break;
    item=list->next(position);
   }
  }
  list->FUN_00ae7440();
  list->freeNodes=list->head;
  list->head=0;
  list->tail=0;
  list->count=0;
  FUN_00b0e510();
 }
}
}
}   // namespace f3m_00b0f370

// @f3 0x00b0f470 (community match, verified in this file)
extern Heap DAT_01090a78;
namespace f3m_00b0f470 {
namespace Insert423 {
struct Heap {void* FUN_0086b930(unsigned);};
struct Node {
 unsigned short value;
 unsigned short unk02;
 Node* next;
 static void* operator new(unsigned size) throw() { return DAT_01090a78.FUN_0086b930(size); }
 Node(unsigned short input) : value(input),next(0) {}
 void FUN_00b0eb60(unsigned*);
 void FUN_00b0f470(unsigned,int (__cdecl*)(unsigned short,unsigned short));
};
// pdb: BSSimpleList<unsigned short>::Insert | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apNewItem, apCompareFn
void Node::FUN_00b0f470(unsigned value,int (__cdecl* compare)(unsigned short,unsigned short)) {
 const unsigned input=*(volatile unsigned*)&value;
 if((unsigned short)input) {
  Node* previous=0;
  bool inserted=false;
  Node* current=this;
  while(current && !inserted) {
   if(!current->value) {current->value=input;inserted=true;}
   else if(compare(input,current->value)<=0) {
    if(!previous) FUN_00b0eb60(&value);
    else {
     Node* item=new Node(input);
     previous->next=item;
     item->next=current;
    }
    inserted=true;
   } else if(!current->next) {current->next=new Node(input);inserted=true;}
   previous=current;
   current=current->next;
  }
 }
}
}



}   // namespace f3m_00b0f470

// @f3 0x00b10ab0 (community match, verified in this file)
namespace f3m_00b10ab0 {
static int Max(int a, int b) { return a < b ? b : a; }
struct MemPool { void FUN_0086ba60(void* p); };
extern MemPool DAT_01090a78;
struct SlotFinder { int unk00, unk04, unk08; void FUN_0066bcc0(unsigned short* const& out); };
struct Item { int unk00, unk04; void FUN_00b0fa10(); };
struct R {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int cnt;
    unsigned char flag;
    unsigned char unk39;
    short unk3a;
    int unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    void* unk70;
    void* unk74;
    SlotFinder f78[2];
    unsigned short* s90;
    unsigned short* s94;
    void FUN_00b10ab0();
};
// pdb: BSBatchRenderer::StopGroupingAlphas | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
void R::FUN_00b10ab0()
{
    int v = Max(cnt - 1, 0);
    cnt = v;
    if (v > 0) return;
    unsigned short* p90 = s90;
    if (p90[1] == 0) {
        f78[0].FUN_0066bcc0(s90);
        Item* q = (Item*)s90;
        if (q) {
            q->FUN_00b0fa10();
            DAT_01090a78.FUN_0086ba60(q);
        }
    }
    unsigned short* p94 = s94;
    s90 = 0;
    if (p94[1] == 0) {
        f78[1].FUN_0066bcc0(s94);
        Item* r = (Item*)s94;
        if (r) {
            r->FUN_00b0fa10();
            DAT_01090a78.FUN_0086ba60(r);
        }
    }
    s94 = 0;
    flag = 0;
}
}
