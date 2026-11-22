// src/f3staging/f3blk_00500000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00515c10 (community match, verified in this file)
namespace f3m_00515c10 {
extern "C" void* __cdecl _alloca(unsigned int);

struct CB20B0_Class {
    int GetType();
    int ReadTag();
    unsigned __int8 ReadByte();
    void Read(void* dst, int size);
    void ReadEntry(void* dst);
};

struct Matrix44_shell {
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
    virtual void v56(CB20B0_Class* a2);
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
    virtual void v77(char* buf);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void TESForm_LoadForm(CB20B0_Class* a2);
    char FUN_00515c10(CB20B0_Class* a2);
};

// pdb: TESGlobal::Load | TESGlobal.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
char Matrix44_shell::FUN_00515c10(CB20B0_Class* a2)
{
    if (a2->GetType() != 6)
        return 0;
    TESForm_LoadForm(a2);
    int tag;
    while ((tag = a2->ReadTag()) != 0) {
        switch (tag) {
        case 0x44494445:
        {
            char* buf = (char*)_alloca(*(int*)((char*)a2 + 0x25C));
            a2->Read(buf, 0x200);
            v77(buf);
            break;
        }
        case 0x444E424F:
            v56(a2);
            break;
        case 0x4D414E46:
            a2->Read(&unk20, 1);
            break;
        case 0x56544C46:
            a2->ReadEntry(&unk24);
            break;
        }
        if (!a2->ReadByte())
            break;
    }
    return 1;
}
}   // namespace f3m_00515c10

// @f3 0x0050ae40 (community match, verified in this file)
namespace f3m_0050ae40 {
extern "C" void* __cdecl _alloca(unsigned);
struct File50ae{
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
unsigned chunkSize;unsigned char TESFile_GetTESForm();unsigned TESFile_GetTESChunk();bool TESFile_NextChunk();void FUN_00447d60(void*,unsigned);};
void __cdecl TESTexture_LoadTextureChunk(void*,File50ae*);
struct Owner50ae{void**table;int unk04;int unk08;int unk0C;int unk10;int unk14;int icon;void FUN_00454410(File50ae*);bool FUN_0050ae40(File50ae*);};
// pdb: BGSMenuIcon::Load | BGSMenuIcon.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Owner50ae::FUN_0050ae40(File50ae*file){if(file->TESFile_GetTESForm()!=5)return false;FUN_00454410(file);unsigned chunk=file->TESFile_GetTESChunk();while(chunk){switch(chunk){case 0x4e4f4349:TESTexture_LoadTextureChunk(this?&icon:0,file);break;case 0x444e424f:((void(__thiscall*)(Owner50ae*,File50ae*))table[56])(this,file);break;case 0x44494445:{char*text=(char*)_alloca(file->chunkSize);file->FUN_00447d60(text,512);((void(__thiscall*)(Owner50ae*,char*))table[77])(this,text);break;}}if(!file->TESFile_NextChunk())break;chunk=file->TESFile_GetTESChunk();}return true;}
}   // namespace f3m_0050ae40

// @f3 0x0050aa60 (community match, verified in this file)
namespace f3m_0050aa60 {
extern "C" void* __cdecl _alloca(unsigned);
struct File50aa{
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
unsigned chunkSize;void FUN_00448800(unsigned*);unsigned char TESFile_GetTESForm();unsigned TESFile_GetTESChunk();bool TESFile_NextChunk();void FUN_00447d60(void*,unsigned);};
struct List50aa{void FUN_0061c430(unsigned*);};
struct Owner50aa{void**table;int unk04;int unk08;int unk0C;int unk10;int unk14;List50aa list;void TESForm_SetInitialized(int);void FUN_00454410(File50aa*);bool FUN_0050aa60(File50aa*);};
// pdb: BGSListForm::Load | BGSListForm.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Owner50aa::FUN_0050aa60(File50aa*file){FUN_00454410(file);TESForm_SetInitialized(0);unsigned chunk=file->TESFile_GetTESChunk();while(chunk){switch(chunk){case 0x4d414e4c:{unsigned id=0;file->FUN_00448800(&id);unsigned value=id;list.FUN_0061c430(&value);break;}case 0x444e424f:((void(__thiscall*)(Owner50aa*,File50aa*))table[56])(this,file);break;case 0x44494445:{char*text=(char*)_alloca(file->chunkSize);file->FUN_00447d60(text,512);((void(__thiscall*)(Owner50aa*,char*))table[77])(this,text);break;}}if(!file->TESFile_NextChunk())break;chunk=file->TESFile_GetTESChunk();}return true;}
}   // namespace f3m_0050aa60

// @f3 0x0050b9a0 (community match, verified in this file)
#include <malloc.h>
namespace f3m_0050b9a0 {
extern "C" void* __cdecl _alloca(unsigned);
struct Stream50b9 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; unsigned unk25C;unsigned TESFile_GetTESChunk();void FUN_00447d60(void*,unsigned);bool TESFile_NextChunk();};
struct Owner50b9;struct Part50b9;typedef void (__thiscall *PartCall50b9)(Part50b9*,char*);struct PartTable50b9 {int unk00,unk04,unk08,unk0C;PartCall50b9 unk10;};struct Part50b9 {PartTable50b9* unk00;};
typedef void (__thiscall *Read50b9)(Owner50b9*,Stream50b9*);typedef void (__thiscall *Name50b9)(Owner50b9*,char*);struct Table50b9 {int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; Read50b9 unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124; int unk128; int unk12C; int unk130; Name50b9 unk134;};
struct Owner50b9 {Table50b9* unk00;int unk04,unk08,unk0C,unk10,unk14;Part50b9 unk18;void FUN_00454410(Stream50b9*);void TESForm_SetInitialized(int);bool FUN_0050b9a0(Stream50b9*);};
// pdb: BGSMusicType::Load | BGSMusicType.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Owner50b9::FUN_0050b9a0(Stream50b9* stream){FUN_00454410(stream);TESForm_SetInitialized(0);unsigned tag=stream->TESFile_GetTESChunk();while(tag){switch(tag){case 'MANF':{char* text=(char*)_alloca(stream->unk25C);stream->FUN_00447d60(text,0);unk18.unk00->unk10(&unk18,text);break;}case 'DNBO':unk00->unkE0(this,stream);break;case 'DIDE':{char* text=(char*)_alloca(stream->unk25C);stream->FUN_00447d60(text,0x200);unk00->unk134(this,text);break;}}if(!stream->TESFile_NextChunk())break;tag=stream->TESFile_GetTESChunk();}return true;}
}   // namespace f3m_0050b9a0

// @f3 0x005066c0 (community match, verified in this file)
#include <stdlib.h>
#include <string.h>

extern "C" void* __cdecl _alloca(unsigned int);

class BGSCameraShot;
class BGSCameraPath;

class TESFile
{
public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
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
    unsigned int m_actualChunkSize;
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
    bool bHasGroups;
    bool bMustEndianConvert;

    ENUM_FORM_ID TESFile_GetTESForm();
    CHUNK_ID TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    bool FUN_00447d60(void* pBuffer, unsigned int uiMaxSize);
    bool FUN_00448800(unsigned int& uiData);

    unsigned int GetChunkSize()
    {
        return m_actualChunkSize;
    }

    bool QEndian()
    {
        return bMustEndianConvert;
    }
};

class NiFormArray
{
public:
    int FUN_0048c740(TESForm* pForm);
    TESForm* FUN_00455150(unsigned int uiIndex);
    void FUN_0043eb00();
};

class BGSCameraPathManager
{
public:
    NiFormArray* FUN_00aa2340();
    void FUN_00507600(BGSCameraPath* pPath);
};

extern BGSCameraPath* __cdecl FUN_00507290();
extern BGSCameraPathManager* DAT_0107195c;

class TESCondition
{
public:
    void* pHead;
    unsigned int unk04;

    bool FUN_005ae230(TESFile* pFile);
};

class CameraShotList
{
public:
    BGSCameraShot* m_item;
    CameraShotList* m_pkNext;

    void FUN_0061c430(BGSCameraShot* const& item);
};

struct PATH_DATA
{
    unsigned char cFlags;
};

struct PATH_PARENT_IDS
{
    unsigned int iparentID;
    unsigned int iprevID;

    void Endian()
    {
        iparentID = _byteswap_ulong(iparentID);
        iprevID = _byteswap_ulong(iprevID);
    }
};

class TESForm
{
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual bool LoadObjectBound(TESFile* pFile);
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void vfunc73();
    virtual void vfunc74();
    virtual void vfunc75();
    virtual void vfunc76();
    virtual bool SetFormEditorID(const char* cEditorID);

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;

    void FUN_00454410(TESFile* pFile);
    void TESForm_LoadData(TESFile* pFile, void* pData, unsigned int uiSize);
};

class BGSCameraPath : public TESForm
{
public:
    TESCondition Conditions;
    CameraShotList ShotList;
    PATH_DATA data;
    NiFormArray* pChildPaths;
    BGSCameraPath* pParentPath;
    BGSCameraPath* pPrevPath;

    TESCondition* GetConditions()
    {
        return &Conditions;
    }

    bool FUN_005066c0(TESFile* pFile);
};

// pdb: BGSCameraPath::Load | BGSCameraPath.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool BGSCameraPath::FUN_005066c0(TESFile* pFile)
{
    if (pFile->TESFile_GetTESForm() != ENUM_FORM_ID_CPTH_ID)
        return false;

    if (this == FUN_00507290())
    {
        NiFormArray* pRootArray = DAT_0107195c->FUN_00aa2340();
        int iIndex = pRootArray->FUN_0048c740(this);
        if (iIndex != -1)
        {
            pRootArray->FUN_00455150(iIndex);
            pRootArray->FUN_0043eb00();
        }
    }

    FUN_00454410(pFile);

    while (CHUNK_ID eChunk = pFile->TESFile_GetTESChunk())
    {
        switch (eChunk)
        {
        case CHUNK_ID_EDID_ID:
        {
            char* cBuffer = (char*)_alloca(pFile->GetChunkSize());
            pFile->FUN_00447d60(cBuffer, 0x200);
            SetFormEditorID(cBuffer);
            break;
        }
        case CHUNK_ID_OBND_ID:
            LoadObjectBound(pFile);
            break;
        case CHUNK_ID_DATA_ID:
            TESForm_LoadData(pFile, &data, sizeof(data));
            break;
        case CHUNK_ID_CIDA_ID:
            GetConditions()->FUN_005ae230(pFile);
            break;
        case CHUNK_ID_SNAM_ID:
        {
            unsigned int iShotID = 0;
            pFile->FUN_00448800(iShotID);
            ShotList.FUN_0061c430((BGSCameraShot*)iShotID);
            break;
        }
        case CHUNK_ID_ANAM_ID:
        {
            PATH_PARENT_IDS kParentIDs;
            memset(&kParentIDs, 0, sizeof(kParentIDs));
            pFile->FUN_00447d60(&kParentIDs, sizeof(kParentIDs));
            if (pFile->QEndian())
                kParentIDs.Endian();
            pParentPath = (BGSCameraPath*)kParentIDs.iparentID;
            pPrevPath = (BGSCameraPath*)kParentIDs.iprevID;
            DAT_0107195c->FUN_00507600(this);
            break;
        }
        }

        if (!pFile->TESFile_NextChunk())
            break;
    }

    return true;
}
