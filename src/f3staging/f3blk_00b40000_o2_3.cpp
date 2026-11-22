#include <windows.h>
// src/f3staging/f3blk_00b40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b504d0 (community match, verified in this file)
namespace f3m_00b504d0 {

struct PassProgram1534 {
    virtual void Unknown00();
    virtual void DeleteThis();
    long references04;
    void AddRef() { InterlockedIncrement(&references04); }
    void Release() { if (!InterlockedDecrement(&references04)) DeleteThis(); }
};
struct PassPointer1534 {
    PassProgram1534* pointer;
    void operator=(PassProgram1534* value) {
        if (pointer != value) {
            if (pointer) pointer->Release();
            pointer=value;
            if (pointer) pointer->AddRef();
        }
    }
    void FUN_008e9650(PassProgram1534*);
};
struct PassRenderer1534 {
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
PassRenderer1534* FUN_00adb960(unsigned int);
struct DispatchRegistry;
extern DispatchRegistry* DAT_01091980;
extern DispatchRegistry* DAT_01177fd0;
extern DispatchRegistry* DAT_01177fd4;
extern DispatchRegistry* DAT_01177fd8;
extern DispatchRegistry* DAT_01177fdc;
extern DispatchRegistry* DAT_01177fe0;
extern DispatchRegistry* DAT_01177fe4;
extern DispatchRegistry* DAT_01177fe8;
extern DispatchRegistry* DAT_01177fec;
extern DispatchRegistry* DAT_01177ff0;
extern DispatchRegistry* DAT_01177ff4;
extern DispatchRegistry* DAT_01177ff8;
extern DispatchRegistry* DAT_01177ffc;
extern DispatchRegistry* DAT_01178000;
extern DispatchRegistry* DAT_01178004;
extern DispatchRegistry* DAT_01178008;
extern DispatchRegistry* DAT_0117800c;
extern DispatchRegistry* DAT_01178010;
extern DispatchRegistry* DAT_01178014;
extern DispatchRegistry* DAT_01178018;
extern DispatchRegistry* DAT_0117801c;
extern DispatchRegistry* DAT_01178020;
extern DispatchRegistry* DAT_01178024;
extern DispatchRegistry* DAT_01178028;
extern DispatchRegistry* DAT_0117802c;
extern DispatchRegistry* DAT_01178030;
extern DispatchRegistry* DAT_01178034;
extern DispatchRegistry* DAT_01178038;
extern DispatchRegistry* DAT_0117803c;
extern DispatchRegistry* DAT_01178040;
extern DispatchRegistry* DAT_01178044;
extern DispatchRegistry* DAT_01178048;
extern DispatchRegistry* DAT_0117804c;
extern DispatchRegistry* DAT_01178050;
struct PassProperty1534 {
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
    PassPointer1534 program28;
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
    PassProgram1534* defaultProgram6C;
    void FUN_00afd8f0(unsigned int);
    void FUN_00b504d0(unsigned int pass);
};

// pdb: ParallaxShader::InitPass | ParallaxShader.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: auiCurrentPass
void PassProperty1534::FUN_00b504d0(unsigned int pass)
{
    program28=defaultProgram6C;
    switch (pass) {
    case 217:
        DAT_01091980=DAT_01177fd0;
        return;
    case 218:
        DAT_01091980=DAT_01177fd4;
        return;
    case 226:
        DAT_01091980=DAT_01177fd8;
        return;
    case 227:
        DAT_01091980=DAT_01177fdc;
        return;
    case 235:
        DAT_01091980=DAT_01177fe0;
        return;
    case 236:
        DAT_01091980=DAT_01177fe4;
        return;
    case 244:
        DAT_01091980=DAT_01177fe8;
        return;
    case 245:
        DAT_01091980=DAT_01177fec;
        return;
    case 153:
        DAT_01091980=DAT_01178014;
        return;
    case 154:
        DAT_01091980=DAT_01178018;
        return;
    case 164:
        DAT_01091980=DAT_0117801c;
        return;
    case 165:
        DAT_01091980=DAT_01178020;
        return;
    case 175:
        DAT_01091980=DAT_01178024;
        return;
    case 176:
        DAT_01091980=DAT_01178028;
        return;
    case 186:
        DAT_01091980=DAT_0117802c;
        return;
    case 187:
        DAT_01091980=DAT_01178030;
        return;
    case 1: case 2:
        FUN_00afd8f0(pass);
        FUN_00adb960(1)->SetPassF0(pass);
        program28.FUN_008e9650(defaultProgram6C);
        return;
    case 257:
        DAT_01091980=DAT_01177ff0;
        return;
    case 258:
        DAT_01091980=DAT_01177ff4;
        return;
    case 259:
        DAT_01091980=DAT_01177ff8;
        return;
    case 270:
        DAT_01091980=DAT_01177ffc;
        return;
    case 271:
        DAT_01091980=DAT_01178000;
        return;
    case 281:
        DAT_01091980=DAT_01178004;
        return;
    case 282:
        DAT_01091980=DAT_01178008;
        return;
    case 292:
        DAT_01091980=DAT_0117800c;
        return;
    case 293:
        DAT_01091980=DAT_01178010;
        return;
    case 308:
        DAT_01091980=DAT_01178034;
        return;
    case 320:
        DAT_01091980=DAT_01178038;
        return;
    case 339:
        DAT_01091980=DAT_0117803c;
        return;
    case 348:
        DAT_01091980=DAT_01178040;
        return;
    case 354:
        DAT_01091980=DAT_01178044;
        return;
    case 360:
        DAT_01091980=DAT_01178048;
        return;
    case 366:
        DAT_01091980=DAT_0117804c;
        return;
    case 372:
        DAT_01091980=DAT_01178050;
        return;
    default:
        FUN_00afd8f0(pass);
        FUN_00adb960(1)->SetPassF0(pass);
        return;
    }
}
}   // namespace f3m_00b504d0
