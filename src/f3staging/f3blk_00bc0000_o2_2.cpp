#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00bc0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bdb8f0 (community match, verified in this file)
extern int DAT_00e2c4d0,DAT_00e2c4d4,DAT_00e2c4d8;
namespace f3m_00bdb8f0 {
namespace Audio1859 {
struct File {
virtual ~File();
virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
virtual void Seek(int,int);
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
bool valid; int unk030,unk034; int pos038;
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
int pos150;
int NiBinaryStream_Read(void*,int);
};
struct State {
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
int position; File* file;
};
File* FUN_00bc7fc0(const char*,int,int,int);
void FUN_00887da0(const char*);
// pdb: BSFile::Read | BSFile.obj | tesv_win, caller_sim, low
int __stdcall FUN_00bdb8f0(State* state,unsigned op,void* data,int size) {
switch(op) {
case 3: {
File* file=FUN_00bc7fc0((const char*)data,0,0x2800,8);
if(!file || !file->valid) {
if(file) delete file;
return 0x101;
}
state->position=0; state->file=file; return 0;
}
case 4: {
File* file=state->file;
if(!file) { FUN_00887da0("Audio: Could not close file.\n"); return 0x104; }
delete file; return 0;
}
case 0: {
File* file=state->file;
if(!file) return 0x105;
int bytes=file->NiBinaryStream_Read(data,size);
state->position+=bytes; return bytes;
}
case 2: {
int offset=(int)data;
int origin=DAT_00e2c4d4;
if(size==0) origin=DAT_00e2c4d0;
else if(size==2) origin=DAT_00e2c4d8;
File* file=state->file;
if(!file) return 0x107;
file->Seek(offset,origin);
state->position=file->pos038!=-1?file->pos038:file->pos150;
return 0;
}
default: return 0x10c;
}
}
}
}   // namespace f3m_00bdb8f0

// @f3 0x00bd0770 (community match, verified in this file)
namespace f3m_00bd0770 {
namespace f3m_00bd0770 {
struct Storage { char bytes[0x104]; void Init(){bytes[0]=0;} };
struct Path {
    char* text;
    Storage buffer;
};
struct Vec3 { float x, y, z; };
extern const Vec3 DAT_0108ec68;
struct Layout {
    Path first, second;
    float width, height;
    Vec3 dimensions;
    unsigned int flags;
    float horizontal, vertical;
    void* context;
    unsigned int count, capacity;
    Layout();
};
// pdb: BSSoundInfo::BSSoundInfo | BSAudioManager.obj | fnv360_0822_retail, call_dedup, low
// pdb params: aiID
Layout::Layout() {
    width = 0.0f;
    height = 0.0f;
    char* firstBuffer = first.buffer.bytes;
    char* secondBuffer = second.buffer.bytes;
    first.buffer.Init();
    second.buffer.Init();
    first.text = firstBuffer;
    second.text = secondBuffer;
    dimensions = DAT_0108ec68;
    flags = 0;
    horizontal = 0.0f;
    vertical = 0.0f;
    context = 0;
    count = 0;
    capacity = 0;
}
}
}   // namespace f3m_00bd0770

// @f3 0x00bd88b0 (community match, verified in this file)
namespace f3m_00bd88b0 {
struct VolumeView_bd88b0 {
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
    virtual void update(float);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c;
    unsigned short volume;
    unsigned int unk20;
    float unk24;
    void FUN_00bd88b0(unsigned short);
};

void VolumeView_bd88b0::FUN_00bd88b0(unsigned short value)
{
    volume = value;
    update(unk24);
}
}   // namespace f3m_00bd88b0

// @f3 0x00bdc1a0 (community match, verified in this file)
#include <string.h>
namespace f3m_00bdc1a0 {
struct FUN_00bdc1a0 {
    void* table[180];
    int count;
    int unk2d4;
    int unk2d8;
    bool dirty;
    FUN_00bdc1a0();
};
// pdb: XUserInterface::ReloadGame | XUserInterface.obj | fnv360_0822_retail, objrun_open, low
FUN_00bdc1a0::FUN_00bdc1a0() : unk2d4(0), unk2d8(0)
{
    memset(table, 0, sizeof(table));
    dirty = false;
    count = 0;
}
}   // namespace f3m_00bdc1a0

// @f3 0x00bd7a00 (community match, verified in this file)
namespace f3m_00bd7a00 {
namespace f3m_00bd7a00 {
struct FUN_00bd7a00_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned short unk1C;
    unsigned short unk1E;
    unsigned short unk20;
    float unk24;
    float unk28;
    float unk2C;
    int unk30;
    unsigned short unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    unsigned char unk138;
    float unk13C;
    float unk140;
    int unk144;
    int unk148;
    int unk14C;
    float unk150;
    int unk154;
    unsigned char unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;

    void FUN_00bd7a00();
};


// pdb: BSGameSound::Init | BSGameSound.obj | fnv360_0822_retail, objrun, medium
void FUN_00bd7a00_Obj::FUN_00bd7a00()
{
    unk24 = 1.0f;
    unk04 = 0;
    unk08 = 0;
    unk28 = 0.0f;
    unk0C = 0;
    unk2C = 0.0f;
    unk14 = 0;

    unk18 = 0;
    unk13C = 1500.0f;
    unk1A = 0;

    unk1C = 0;
    unk140 = 50.0f;
    unk1E = 0;

    unk20 = 0;
    unk150 = 3.402823466e+38f;

    unk30 = 0;
    unk34 = 0;
    unk14C = 0;
    unk154 = 0;
    unk160 = 0;
    unk15C = 0;
    unk144 = 0;
    unk148 = 0;
    unk158 = 0;
    unk174 = 0;
    unk178 = 0;
    unk164 = 0;
    unk168 = 0;
    unk16C = 0;
    unk170 = 0;
    unk10 = 0x100;
}
}
}   // namespace f3m_00bd7a00
