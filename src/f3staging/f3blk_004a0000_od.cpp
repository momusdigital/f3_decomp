// src/f3staging/f3blk_004a0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004a6440 (community match, verified in this file)
namespace f3m_004a6440 {
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct Rd {
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
    unsigned int unk25c;
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
    char unk298;
    char unk299;
    char GetType();
    unsigned int NextChunk();
    void Read(void* buf, unsigned int n);
    void ReadU32(unsigned int* out);
    bool Advance();
};

struct Sub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Load(void* buf); };

struct Blob { int unk00; };
void __cdecl Fn456560(Blob* b, Rd* r);
void __cdecl Fn44c110(Blob* b, Rd* r);
void __cdecl Fn458210(Blob* b, Rd* r);
void __cdecl Fn4580b0(Sub* b, Rd* r);

struct Obj {
    virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();
    virtual void Init();
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
    virtual void OnObnd(Rd* r);
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
    virtual void OnEdid(char* s);
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
    Blob unk30;
    int unk34;
    int unk38;
    Blob unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    Blob unk58;
    int unk5c;
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
    Sub unka4;
    int unkA8; int unkAc; int unkB0; int unkB4; int unkB8; unsigned int unkbc;
    void Fn454410(Rd* r);
    void Fn454240(int a);
    void Fn454d10(Rd* r, void* p, int n);
    bool FUN_004a6440(Rd* r);
};

// pdb: BGSProjectile::Load | BGSProjectile.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Obj::FUN_004a6440(Rd* r)
{
    if (r->GetType() != 0x33)
        return false;
    this->Init();
    Fn454410(r);
    Fn454240(0);
    int type;
    while ((type = r->NextChunk()) != 0) {
        switch (type) {
        case 0x324d414e:
            if (r->unk25c != 0)
                Fn4580b0(&unka4, r);
            break;
        case 0x314d414e:
            if (r->unk25c != 0) {
                void* buf = _alloca(r->unk25c);
                r->Read(buf, 0);
                unka4.Load(buf);
            }
            break;
        case 0x41544144:
            Fn454d10(r, &unk60, 0x44);
            goto swap;
        case 0x44494445: {
            void* buf = _alloca(r->unk25c);
            r->Read(buf, 0x200);
            OnEdid((char*)buf);
            break; }
        case 0x444e424f:
            OnObnd(r);
            break;
        case 0x4c4c5546:
            Fn456560(&unk30, r);
            break;
        case 0x4d414e56: {
            unsigned int v;
            r->ReadU32(&v);
            if (v > 3)
                unkbc = 1;
            else
                unkbc = v;
            break; }
        case 0x44545344:
        case 0x54534544:
            Fn44c110(&unk58, r);
            goto chk;
        case 0x4c444f4d:
        case 0x54444f4d:
            Fn458210(&unk3c, r);
            goto chk;
        default:
        chk:
            if (type == 0x41544144) {
        swap:
                if (r->unk299) {
                    *(volatile unsigned int*)&unk60 = _byteswap_ulong(*(volatile unsigned int*)&unk60);
                    *(volatile unsigned int*)&unk64 = _byteswap_ulong(*(volatile unsigned int*)&unk64);
                    *(volatile unsigned int*)&unk68 = _byteswap_ulong(*(volatile unsigned int*)&unk68);
                    *(volatile unsigned int*)&unk6c = _byteswap_ulong(*(volatile unsigned int*)&unk6c);
                    *(volatile unsigned int*)&unk78 = _byteswap_ulong(*(volatile unsigned int*)&unk78);
                    *(volatile unsigned int*)&unk7c = _byteswap_ulong(*(volatile unsigned int*)&unk7c);
                    *(volatile unsigned int*)&unk80 = _byteswap_ulong(*(volatile unsigned int*)&unk80);
                    *(volatile unsigned int*)&unk8c = _byteswap_ulong(*(volatile unsigned int*)&unk8c);
                    *(volatile unsigned int*)&unk90 = _byteswap_ulong(*(volatile unsigned int*)&unk90);
                    *(volatile unsigned int*)&unk94 = _byteswap_ulong(*(volatile unsigned int*)&unk94);
                }
            }
        }
        if (!r->Advance())
            break;
    }
    return true;
}
}   // namespace f3m_004a6440

// @f3 0x004a3530 (community match, verified in this file)
#include <intrin.h>
extern unsigned int DAT_010701ac;
namespace f3m_004a3530 {

extern "C" void* __cdecl _alloca(unsigned int);

namespace f3m_004a3530 {

struct Rd;

struct Model {
    int unk00;
    void Fn459340(void* buf, unsigned int size, unsigned short version);
};

void __cdecl Fn458210(Model* m, Rd* r);

struct Rd {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c; int unk250;
    unsigned short version; unsigned short unk256; int unk258; unsigned int size;
    int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294;
    char unk298; char unk299;
    char GetType();
    unsigned int NextChunk();
    void Read(void* buf, unsigned int n);
    void FUN_00448800(void* p);
    bool Advance();
};


struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void OnObnd(Rd* r);
    virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
    virtual void OnEdid(char* s);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    int unk1c; int unk20; int unk24; int unk28; int unk2c;
    Model unk30;
    int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c;
    unsigned int index;
    unsigned int sound;
    unsigned short data;
    unsigned char flags;
    unsigned char unk5b;
    unsigned int unique;
    void Fn454410(Rd* r);
    bool FUN_004a3530(Rd* r);
};

// pdb: BGSAddonNode::Load | BGSAddonNode.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Obj::FUN_004a3530(Rd* r)
{
    if (r->GetType() != 0x58)
        return false;
    this->Fn454410(r);
    int type;
    while ((type = r->NextChunk()) != 0) {
        switch (type) {
        case 0x41544144:
            r->FUN_00448800(&this->index);
            break;
        case 0x44494445: {
            char* buf = (char*)_alloca(r->size);
            r->Read(buf, 0x200);
            this->OnEdid(buf);
            break; }
        case 0x444e424f:
            this->OnObnd(r);
            break;
        case 0x4d414e53: {
            unsigned int formID = 0;
            r->FUN_00448800(&formID);
            this->sound = formID;
            break; }
        case 0x4d414e44: {
            r->Read(&this->data, 4);
            if (r->unk299) {
                this->data = _byteswap_ushort(this->data);
            }
            if (this->flags & 1) {
                this->unique = DAT_010701ac;
                ++DAT_010701ac;
            }
            break; }
        case 0x53444f4d: {
            unsigned int size = r->size;
            char* buf = (char*)_alloca(size);
            r->Read(buf, size);
            this->unk30.Fn459340(buf, size, r->version);
            break; }
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            Fn458210(this ? &this->unk30 : 0, r);
            break;
        }
        if (!r->Advance())
            break;
    }
    return true;
}
}
}   // namespace f3m_004a3530
