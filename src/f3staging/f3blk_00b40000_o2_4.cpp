#include <windows.h>
// src/f3staging/f3blk_00b40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b533b0 (community match, verified in this file)
namespace f3m_00b533b0 {

struct PassProgram1535 {
    virtual void Unknown00();
    virtual void DeleteThis();
    long references04;
    void AddRef() { InterlockedIncrement(&references04); }
    void Release() { if (!InterlockedDecrement(&references04)) DeleteThis(); }
};
struct PassPointer1535 {
    PassProgram1535* pointer;
    void operator=(const PassPointer1535& value) {
        if (pointer != value.pointer) {
            if (pointer) pointer->Release();
            pointer=value.pointer;
            if (pointer) pointer->AddRef();
        }
    }
    void FUN_008e9650(PassProgram1535*);
    void FUN_008e9600(const PassPointer1535&);
};
struct PassRenderer1535 {
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual void Unknown14();
    virtual void Unknown18();
    virtual void Unknown1C();
    virtual void Unknown20();
    virtual void Unknown24();
    virtual void Unknown28();
    virtual void Unknown2C();
    virtual void Unknown30();
    virtual void Unknown34();
    virtual void Unknown38();
    virtual void Unknown3C();
    virtual void Unknown40();
    virtual void Unknown44();
    virtual void Unknown48();
    virtual void Unknown4C();
    virtual void Unknown50();
    virtual void Unknown54();
    virtual void Unknown58();
    virtual void Unknown5C();
    virtual void Unknown60();
    virtual void Unknown64();
    virtual void Unknown68();
    virtual void Unknown6C();
    virtual void Unknown70();
    virtual void Unknown74();
    virtual void Unknown78();
    virtual void Unknown7C();
    virtual void Unknown80();
    virtual void Unknown84();
    virtual void Unknown88();
    virtual void Unknown8C();
    virtual void Unknown90();
    virtual void Unknown94();
    virtual void Unknown98();
    virtual void Unknown9C();
    virtual void UnknownA0();
    virtual void UnknownA4();
    virtual void UnknownA8();
    virtual void UnknownAC();
    virtual void UnknownB0();
    virtual void UnknownB4();
    virtual void UnknownB8();
    virtual void UnknownBC();
    virtual void UnknownC0();
    virtual void UnknownC4();
    virtual void UnknownC8();
    virtual void UnknownCC();
    virtual void UnknownD0();
    virtual void UnknownD4();
    virtual void UnknownD8();
    virtual void UnknownDC();
    virtual void UnknownE0();
    virtual void UnknownE4();
    virtual void UnknownE8();
    virtual void UnknownEC();
    virtual void SetPassF0(unsigned int);
};
PassRenderer1535* FUN_00adb960(unsigned int);
struct DispatchRegistry;
extern DispatchRegistry* DAT_01091980;
extern DispatchRegistry* DAT_01178060;
extern DispatchRegistry* DAT_01178064;
extern DispatchRegistry* DAT_01178068;
extern DispatchRegistry* DAT_0117806c;
extern DispatchRegistry* DAT_01178070;
extern DispatchRegistry* DAT_01178074;
extern DispatchRegistry* DAT_01178078;
extern DispatchRegistry* DAT_0117807c;
extern DispatchRegistry* DAT_01178080;
extern DispatchRegistry* DAT_01178084;
extern DispatchRegistry* DAT_01178088;
extern DispatchRegistry* DAT_0117808c;
extern DispatchRegistry* DAT_01178090;
extern DispatchRegistry* DAT_01178094;
extern DispatchRegistry* DAT_01178098;
extern DispatchRegistry* DAT_0117809c;
extern DispatchRegistry* DAT_011780a0;
extern DispatchRegistry* DAT_011780a4;
extern DispatchRegistry* DAT_011780a8;
extern DispatchRegistry* DAT_011780ac;
extern DispatchRegistry* DAT_011780b0;
extern DispatchRegistry* DAT_011780b4;
extern DispatchRegistry* DAT_011780b8;
extern DispatchRegistry* DAT_011780bc;
extern DispatchRegistry* DAT_011780c0;
extern DispatchRegistry* DAT_011780c4;
struct PassProperty1535 {
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
    PassPointer1535 program28;
    unsigned int unk2C;
    PassPointer1535 program30;
    PassPointer1535 program34;
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
    PassPointer1535 program6C;
    PassPointer1535 program70;
    unsigned int unk74;
    unsigned int unk78;
    PassPointer1535 program7C;
    PassPointer1535 program80;
    PassPointer1535 program84;
    PassPointer1535 program88;
    void FUN_00afd8f0(unsigned int);
    void FUN_00b533b0(unsigned int pass);
};

// pdb: SkinShader::InitPass | SkinShader.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: NiControllerSequence::ProcessClone)
// pdb params: auiCurrentPass
void PassProperty1535::FUN_00b533b0(unsigned int pass)
{
    switch (pass) {
    case 219:
        DAT_01091980=DAT_01178060;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 222:
        DAT_01091980=DAT_01178064;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 228:
        DAT_01091980=DAT_01178068;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 231:
        DAT_01091980=DAT_0117806c;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 237:
        DAT_01091980=DAT_01178070;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 240:
        DAT_01091980=DAT_01178074;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 246:
        DAT_01091980=DAT_01178078;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 249:
        DAT_01091980=DAT_0117807c;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 197:
        DAT_01091980=DAT_011780b0;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 200:
        DAT_01091980=DAT_011780b4;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 204:
        DAT_01091980=DAT_011780b8;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 207:
        DAT_01091980=DAT_011780bc;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 211:
        DAT_01091980=DAT_011780c0;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 214:
        DAT_01091980=DAT_011780c4;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 1: case 2:
        FUN_00afd8f0(pass);
        FUN_00adb960(1)->SetPassF0(pass);
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 3:
        FUN_00afd8f0(pass);
        FUN_00adb960(1)->SetPassF0(pass);
        program28.FUN_008e9650(program70.pointer);
        break;
    case 256:
        DAT_01091980=DAT_01178080;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 263:
        DAT_01091980=DAT_01178084;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 269:
        DAT_01091980=DAT_01178088;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 275:
        DAT_01091980=DAT_0117808c;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 280:
        DAT_01091980=DAT_01178090;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 286:
        DAT_01091980=DAT_01178094;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 291:
        DAT_01091980=DAT_01178098;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 297:
        DAT_01091980=DAT_0117809c;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 307:
        DAT_01091980=DAT_011780a0;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 310:
        DAT_01091980=DAT_011780a4;
        program28.FUN_008e9650(program70.pointer);
        break;
    case 319:
        DAT_01091980=DAT_011780a8;
        program28.FUN_008e9650(program6C.pointer);
        break;
    case 322:
        DAT_01091980=DAT_011780ac;
        program28.FUN_008e9650(program70.pointer);
        break;
    default:
        FUN_00afd8f0(pass);
        FUN_00adb960(1)->SetPassF0(pass);
        break;
    }
    if (pass==0x250 || pass==0x251) {
        program30=program7C;
        program34=program80;
    } else {
        program30.FUN_008e9600(program84);
        program34.FUN_008e9600(program88);
    }
}
}   // namespace f3m_00b533b0
