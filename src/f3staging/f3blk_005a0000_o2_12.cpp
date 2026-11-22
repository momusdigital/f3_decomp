#include <string.h>
#include <string.h>
#include <string.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a68a0 (community match, verified in this file)
namespace f3m_005a68a0 {
namespace N5a68a0 {
class Form {
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Unk0B();
    virtual void Unk0C();
    virtual void Unk0D();
    virtual void Unk0E();
    virtual void Unk0F();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1A();
    virtual void Unk1B();
    virtual void Unk1C();
    virtual void Unk1D();
    virtual void Unk1E();
    virtual void Unk1F();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2A();
    virtual void Unk2B();
    virtual void Unk2C();
    virtual void Unk2D();
    virtual void Unk2E();
    virtual void Unk2F();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk3A();
    virtual void Unk3B();
    virtual void Unk3C();
    virtual void Unk3D();
    virtual void Unk3E();
    virtual void Unk3F();
    virtual bool IsActor();
    unsigned char unk04;
    unsigned char typeID; // +0x05? placeholder
};
struct TypedForm { void* vtbl; unsigned char typeID; };
struct Owner {
    int FUN_005ad6b0();
    Form* FUN_005ad6c0();
    TypedForm* FUN_005ad6d0();
    unsigned int FUN_005ad6e0();
};
class Ref { public: Form* FUN_004e7800(); };
class Condition {
public:
    char pad00[0x30];
    Owner* owner; // +0x30
    bool FUN_005a68a0(Ref* ref);
};
}
// pdb: TESPackage::IsTargetAnActor | Package.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apActor
bool N5a68a0::Condition::FUN_005a68a0(Ref* ref) {
    bool result = false;
    Owner* current = owner;
    if (!current) {
        return false;
    }
    switch (current->FUN_005ad6b0()) {
    case 0:
        if (current->FUN_005ad6c0() && current->FUN_005ad6c0()->IsActor()) {
            result = true;
        }
        break;
    case 3:
        if (ref->FUN_004e7800()) {
            result = ref->FUN_004e7800()->IsActor();
        }
        break;
    case 1: {
        unsigned char type = current->FUN_005ad6d0()->typeID;
        if (type == 0x2a || type == 0x2b) {
            result = true;
        }
        break;
    }
    case 2:
        switch (current->FUN_005ad6e0()) {
        case 14:
        case 15:
            result = true;
            break;
        }
        break;
    }
    return result;
}
}   // namespace f3m_005a68a0

// @f3 0x005a4c70 (community match, verified in this file)
namespace f3m_005a4c70 {
namespace f3m_005a4c70 {
struct Located { char pad[0x3c]; void* unk3C; };
class Quest;
class Process {
public:
    virtual void x1_000();
    virtual void x1_001();
    virtual void x1_002();
    virtual void x1_003();
    virtual void x1_004();
    virtual void x1_005();
    virtual void x1_006();
    virtual void x1_007();
    virtual void x1_008();
    virtual void x1_009();
    virtual void x1_00a();
    virtual void x1_00b();
    virtual void x1_00c();
    virtual void x1_00d();
    virtual void x1_00e();
    virtual void x1_00f();
    virtual void x1_010();
    virtual void x1_011();
    virtual void x1_012();
    virtual void x1_013();
    virtual void x1_014();
    virtual void x1_015();
    virtual void x1_016();
    virtual void x1_017();
    virtual void x1_018();
    virtual void x1_019();
    virtual void x1_01a();
    virtual void x1_01b();
    virtual void x1_01c();
    virtual void x1_01d();
    virtual void x1_01e();
    virtual void x1_01f();
    virtual void x1_020();
    virtual void x1_021();
    virtual void x1_022();
    virtual void x1_023();
    virtual void x1_024();
    virtual void x1_025();
    virtual void x1_026();
    virtual void x1_027();
    virtual void x1_028();
    virtual void x1_029();
    virtual void x1_02a();
    virtual void x1_02b();
    virtual void x1_02c();
    virtual void x1_02d();
    virtual void x1_02e();
    virtual void x1_02f();
    virtual void x1_030();
    virtual void x1_031();
    virtual void x1_032();
    virtual void x1_033();
    virtual void x1_034();
    virtual void x1_035();
    virtual void x1_036();
    virtual void x1_037();
    virtual void x1_038();
    virtual void x1_039();
    virtual void x1_03a();
    virtual void x1_03b();
    virtual void x1_03c();
    virtual void x1_03d();
    virtual void x1_03e();
    virtual void x1_03f();
    virtual void x1_040();
    virtual void x1_041();
    virtual void x1_042();
    virtual void x1_043();
    virtual void x1_044();
    virtual void x1_045();
    virtual void x1_046();
    virtual void x1_047();
    virtual void x1_048();
    virtual void x1_049();
    virtual void x1_04a();
    virtual void x1_04b();
    virtual void x1_04c();
    virtual void x1_04d();
    virtual void x1_04e();
    virtual void x1_04f();
    virtual void x1_050();
    virtual void x1_051();
    virtual void x1_052();
    virtual void x1_053();
    virtual void x1_054();
    virtual void x1_055();
    virtual void x1_056();
    virtual void x1_057();
    virtual void x1_058();
    virtual void x1_059();
    virtual void x1_05a();
    virtual void x1_05b();
    virtual void x1_05c();
    virtual void x1_05d();
    virtual void x1_05e();
    virtual void x1_05f();
    virtual void x1_060();
    virtual void x1_061();
    virtual void x1_062();
    virtual void x1_063();
    virtual void x1_064();
    virtual void x1_065();
    virtual void x1_066();
    virtual void x1_067();
    virtual void x1_068();
    virtual void x1_069();
    virtual void x1_06a();
    virtual void x1_06b();
    virtual void x1_06c();
    virtual void x1_06d();
    virtual void x1_06e();
    virtual void x1_06f();
    virtual void x1_070();
    virtual void x1_071();
    virtual void x1_072();
    virtual void x1_073();
    virtual void x1_074();
    virtual void x1_075();
    virtual void x1_076();
    virtual void x1_077();
    virtual void x1_078();
    virtual void x1_079();
    virtual void x1_07a();
    virtual void x1_07b();
    virtual void x1_07c();
    virtual void x1_07d();
    virtual void x1_07e();
    virtual void x1_07f();
    virtual void x1_080();
    virtual void x1_081();
    virtual void x1_082();
    virtual void x1_083();
    virtual void x1_084();
    virtual void x1_085();
    virtual void x1_086();
    virtual void x1_087();
    virtual void x1_088();
    virtual void x1_089();
    virtual void x1_08a();
    virtual void x1_08b();
    virtual void x1_08c();
    virtual void x1_08d();
    virtual void x1_08e();
    virtual void x1_08f();
    virtual void x1_090();
    virtual void x1_091();
    virtual void x1_092();
    virtual void x1_093();
    virtual void x1_094();
    virtual void x1_095();
    virtual void x1_096();
    virtual void x1_097();
    virtual void x1_098();
    virtual void x1_099();
    virtual void x1_09a();
    virtual void x1_09b();
    virtual void x1_09c();
    virtual void x1_09d();

    virtual Quest* GetQuest();
    virtual void x2_000();
    virtual void x2_001();
    virtual void x2_002();
    virtual void x2_003();
    virtual void x2_004();
    virtual void x2_005();
    virtual void x2_006();
    virtual void x2_007();
    virtual void x2_008();
    virtual void x2_009();
    virtual void x2_00a();
    virtual void x2_00b();
    virtual void x2_00c();
    virtual void x2_00d();
    virtual void x2_00e();
    virtual void x2_00f();
    virtual void x2_010();
    virtual void x2_011();
    virtual void x2_012();
    virtual void x2_013();
    virtual void x2_014();
    virtual void x2_015();
    virtual void x2_016();
    virtual void x2_017();
    virtual void x2_018();
    virtual void x2_019();
    virtual void x2_01a();
    virtual void x2_01b();
    virtual void x2_01c();
    virtual void x2_01d();
    virtual void x2_01e();
    virtual void x2_01f();
    virtual void x2_020();
    virtual void x2_021();
    virtual void x2_022();
    virtual void x2_023();
    virtual void x2_024();
    virtual void x2_025();
    virtual void x2_026();
    virtual void x2_027();
    virtual void x2_028();
    virtual void x2_029();
    virtual void x2_02a();
    virtual void x2_02b();
    virtual void x2_02c();
    virtual void x2_02d();
    virtual void x2_02e();
    virtual void x2_02f();
    virtual void x2_030();
    virtual void x2_031();
    virtual void x2_032();
    virtual void x2_033();
    virtual void x2_034();
    virtual void x2_035();
    virtual void x2_036();
    virtual void x2_037();
    virtual void x2_038();
    virtual void x2_039();
    virtual void x2_03a();
    virtual void x2_03b();
    virtual void x2_03c();
    virtual void x2_03d();
    virtual void x2_03e();
    virtual void x2_03f();
    virtual void x2_040();
    virtual void x2_041();
    virtual void x2_042();
    virtual void x2_043();
    virtual void x2_044();
    virtual void x2_045();
    virtual void x2_046();
    virtual void x2_047();
    virtual void x2_048();
    virtual void x2_049();
    virtual void x2_04a();
    virtual void x2_04b();
    virtual void x2_04c();
    virtual void x2_04d();
    virtual void x2_04e();
    virtual void x2_04f();
    virtual void x2_050();
    virtual void x2_051();
    virtual void x2_052();
    virtual void x2_053();
    virtual void x2_054();
    virtual void x2_055();
    virtual void x2_056();
    virtual void x2_057();
    virtual void x2_058();
    virtual void x2_059();
    virtual void x2_05a();
    virtual void x2_05b();
    virtual void x2_05c();
    virtual void x2_05d();
    virtual void x2_05e();
    virtual void x2_05f();
    virtual void x2_060();
    virtual void x2_061();
    virtual void x2_062();
    virtual void x2_063();
    virtual void x2_064();
    virtual void x2_065();
    virtual void x2_066();
    virtual void x2_067();
    virtual void x2_068();
    virtual void x2_069();
    virtual void x2_06a();
    virtual void x2_06b();
    virtual void x2_06c();
    virtual void x2_06d();
    virtual void x2_06e();
    virtual void x2_06f();
    virtual void x2_070();
    virtual void x2_071();
    virtual void x2_072();
    virtual void x2_073();
    virtual void x2_074();
    virtual void x2_075();
    virtual void x2_076();
    virtual void x2_077();
    virtual void x2_078();
    virtual void x2_079();
    virtual void x2_07a();
    virtual void x2_07b();
    virtual void x2_07c();
    virtual void x2_07d();
    virtual void x2_07e();
    virtual void x2_07f();
    virtual void x2_080();
    virtual void x2_081();
    virtual void x2_082();
    virtual void x2_083();
    virtual void x2_084();
    virtual void x2_085();
    virtual void x2_086();
    virtual void x2_087();
    virtual void x2_088();
    virtual void x2_089();
    virtual void x2_08a();
    virtual void x2_08b();
    virtual void x2_08c();
    virtual void x2_08d();
    virtual void x2_08e();
    virtual void x2_08f();
    virtual void x2_090();
    virtual void x2_091();
    virtual void x2_092();
    virtual void x2_093();
    virtual void x2_094();
    virtual void x2_095();
    virtual void x2_096();
    virtual void x2_097();
    virtual void x2_098();
    virtual void x2_099();
    virtual void x2_09a();
    virtual void x2_09b();
    virtual void x2_09c();
    virtual void x2_09d();
    virtual void x2_09e();
    virtual void x2_09f();
    virtual void x2_0a0();
    virtual void x2_0a1();
    virtual void x2_0a2();
    virtual void x2_0a3();

    virtual Located* GetTarget();
};
class TESObjectREFR {
public:
    virtual void x3_000();
    virtual void x3_001();
    virtual void x3_002();
    virtual void x3_003();
    virtual void x3_004();
    virtual void x3_005();
    virtual void x3_006();
    virtual void x3_007();
    virtual void x3_008();
    virtual void x3_009();
    virtual void x3_00a();
    virtual void x3_00b();
    virtual void x3_00c();
    virtual void x3_00d();
    virtual void x3_00e();
    virtual void x3_00f();
    virtual void x3_010();
    virtual void x3_011();
    virtual void x3_012();
    virtual void x3_013();
    virtual void x3_014();
    virtual void x3_015();
    virtual void x3_016();
    virtual void x3_017();
    virtual void x3_018();
    virtual void x3_019();
    virtual void x3_01a();
    virtual void x3_01b();
    virtual void x3_01c();
    virtual void x3_01d();
    virtual void x3_01e();
    virtual void x3_01f();
    virtual void x3_020();
    virtual void x3_021();
    virtual void x3_022();
    virtual void x3_023();
    virtual void x3_024();
    virtual void x3_025();
    virtual void x3_026();
    virtual void x3_027();
    virtual void x3_028();
    virtual void x3_029();
    virtual void x3_02a();
    virtual void x3_02b();
    virtual void x3_02c();
    virtual void x3_02d();
    virtual void x3_02e();
    virtual void x3_02f();
    virtual void x3_030();
    virtual void x3_031();
    virtual void x3_032();
    virtual void x3_033();
    virtual void x3_034();
    virtual void x3_035();
    virtual void x3_036();
    virtual void x3_037();
    virtual void x3_038();
    virtual void x3_039();
    virtual void x3_03a();
    virtual void x3_03b();
    virtual void x3_03c();
    virtual void x3_03d();
    virtual void x3_03e();
    virtual void x3_03f();
    virtual void x3_040();
    virtual void x3_041();
    virtual void x3_042();
    virtual void x3_043();
    virtual void x3_044();
    virtual void x3_045();
    virtual void x3_046();
    virtual void x3_047();
    virtual void x3_048();
    virtual void x3_049();
    virtual void x3_04a();
    virtual void x3_04b();
    virtual void x3_04c();
    virtual void x3_04d();
    virtual void x3_04e();
    virtual void x3_04f();
    virtual void x3_050();
    virtual void x3_051();
    virtual void x3_052();
    virtual void x3_053();
    virtual void x3_054();
    virtual void x3_055();
    virtual void x3_056();
    virtual void x3_057();
    virtual void x3_058();
    virtual void x3_059();
    virtual void x3_05a();
    virtual void x3_05b();
    virtual void x3_05c();
    virtual void x3_05d();
    virtual void x3_05e();
    virtual void x3_05f();
    virtual void x3_060();
    virtual void x3_061();
    virtual void x3_062();
    virtual void x3_063();
    virtual void x3_064();
    virtual void x3_065();
    virtual void x3_066();
    virtual void x3_067();
    virtual void x3_068();
    virtual void x3_069();
    virtual void x3_06a();
    virtual void x3_06b();
    virtual void x3_06c();
    virtual void x3_06d();
    virtual void x3_06e();
    virtual void x3_06f();
    virtual void x3_070();
    virtual void x3_071();
    virtual void x3_072();
    virtual void x3_073();
    virtual void x3_074();
    virtual void x3_075();
    virtual void x3_076();
    virtual void x3_077();
    virtual void x3_078();
    virtual void x3_079();
    virtual void x3_07a();
    virtual void x3_07b();
    virtual void x3_07c();
    virtual void x3_07d();
    virtual void x3_07e();
    virtual void x3_07f();
    virtual void x3_080();
    virtual void x3_081();
    virtual void x3_082();
    virtual void x3_083();
    virtual void x3_084();
    virtual void x3_085();
    virtual void x3_086();
    virtual void x3_087();
    virtual void x3_088();
    virtual void x3_089();
    virtual void x3_08a();
    virtual void x3_08b();
    virtual void x3_08c();
    virtual void x3_08d();
    virtual void x3_08e();
    virtual void x3_08f();
    virtual void x3_090();
    virtual void x3_091();
    virtual void x3_092();
    virtual void x3_093();
    virtual void x3_094();
    virtual void x3_095();
    virtual void x3_096();
    virtual void x3_097();
    virtual void x3_098();
    virtual void x3_099();
    virtual void x3_09a();
    virtual void x3_09b();
    virtual void x3_09c();
    virtual void x3_09d();
    virtual void x3_09e();
    virtual void x3_09f();
    virtual void x3_0a0();
    virtual void x3_0a1();
    virtual void x3_0a2();
    virtual void x3_0a3();
    virtual void x3_0a4();
    virtual void x3_0a5();

    virtual void* GetLocation();
    char pad04[0x38];
    void* unk3C;
    char pad40[0x20];
    Process* process;
    Located* FUN_004e7800();
    void* FUN_004e7920();
};
extern TESObjectREFR* DAT_0107a104;
struct Target {
    int FUN_005acce0();
    void* FUN_005acda0();
    Located* FUN_005acd80();
};
class Quest {
public:
    char pad00[0x20];
    unsigned char type;
    char pad21[0x7b];
    Located* unk9C;
    Target* FUN_005a4020();
    void* FUN_005a4c70(TESObjectREFR* ref);
};

// pdb: TESPackage::GetSecondLocationCell | Package.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apActor
void* Quest::FUN_005a4c70(TESObjectREFR* ref)
{
    void* result = 0;
    Target* target = FUN_005a4020();
    if (target && target->FUN_005acce0() != 2) {
        switch (target->FUN_005acce0()) {
        case 1:
            result = target->FUN_005acda0();
            break;
        case 0:
            if (target->FUN_005acd80())
                result = target->FUN_005acd80()->unk3C;
            break;
        case 3:
            if (ref)
                result = ref->GetLocation();
            break;
        case 6:
            if (ref && ref->FUN_004e7800())
                result = ref->FUN_004e7800()->unk3C;
            break;
        case 4:
        case 5:
            Process* process;
            if (ref && (process = ref->process) != 0 && process->GetQuest() == this) {
                Located* located = ref->process->GetTarget();
                if (located)
                    result = located->unk3C;
                else
                    result = ref->unk3C;
            } else if (ref == DAT_0107a104 && type == 0x1c && unk9C) {
                result = unk9C->unk3C;
            }
            break;
        }
    } else if (ref) {
        result = ref->FUN_004e7920();
    }
    return result;
}
}
}   // namespace f3m_005a4c70
