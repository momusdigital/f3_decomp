#include <string.h>
#include <new>
// src/f3staging/f3blk_004a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004a5d30 (community match, verified in this file)
#include <string.h>
namespace f3m_004a5d30 {

class TESForm {
public:
    virtual ~TESForm();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BGSPlaceableWater : public TESForm {
public:
    bool CompareBaseW(BGSPlaceableWater* other);
    bool FUN_004a5d30(TESForm* other);
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

// pdb: BGSPlaceableWater::Compare | BGSPlaceableWater.obj | fnv360_0822_retail, vtable, medium
// pdb params: apCompare
bool BGSPlaceableWater::FUN_004a5d30(TESForm* other)
{
    BGSPlaceableWater* otherWater = dynamic_cast<BGSPlaceableWater*>(other);
    if (!otherWater)
        return true;
    if (CompareBaseW(otherWater))
        return true;
    if (memcmp(&unk48, &otherWater->unk48, 8) != 0)
        return true;
    return false;
}
}   // namespace f3m_004a5d30

// @f3 0x004bfd80 (community match, verified in this file)
namespace f3m_004bfd80 {


class EntryHeap {
public:
    void* FUN_0086b930(size_t size);
    void FUN_0086ba60(void* pointer);
};
extern EntryHeap DAT_01090a78;
class FUN_00456190 {
public:
    virtual ~FUN_00456190();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00c();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01c();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02c();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03c();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04c();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05c();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06c();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07c();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08c();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09c();
    virtual void Unk0a0();
    virtual void Unk0a4();
    virtual void Unk0a8();
    virtual void Unk0ac();
    virtual void Unk0b0();
    virtual void Unk0b4();
    virtual void Unk0b8();
    virtual void Unk0bc();
    virtual void Unk0c0();
    virtual void Unk0c4();
    virtual void Unk0c8();
    virtual void Unk0cc();
    virtual void Unk0d0();
    virtual void Unk0d4();
    virtual void Unk0d8();
    virtual void Unk0dc();
    virtual void Unk0e0();
    virtual void Unk0e4();
    virtual void Unk0e8();
    virtual void Unk0ec();
    virtual void Unk0f0();
    virtual void Unk0f4();
    virtual void Unk0f8();
    virtual void Unk0fc();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10c();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11c();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Configure(int type, bool enabled);
    virtual void Unk12c();
    virtual void Unk130();
    virtual void SetName(const char* name);
    unsigned char type;
    unsigned int unk08, unk0C, unk10, unk14;
    FUN_00456190();
};
class RegisteredEntry : public FUN_00456190 {
public:
    unsigned int unk18, unk1C, unk20, unk24, unk28, unk2C;
    RegisteredEntry() { type = 0x61; memset(&unk18, 0, 6 * sizeof(unk18)); }
    virtual ~RegisteredEntry();
    static void* operator new(size_t size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* pointer) { DAT_01090a78.FUN_0086ba60(pointer); }
};
extern RegisteredEntry* DAT_01070ac0;
extern const char DAT_00dcb7d0[];
class EntryRegistry {
public:
    void FUN_00444630(RegisteredEntry* entry);
};
extern EntryRegistry* DAT_0106cdcc;
// pdb: BGSEncounterZone::CreateNoZone | BGSEncounterZone.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void BGSEncounterZone_CreateNoZone() {
    if (!DAT_01070ac0) {
        DAT_01070ac0 = new RegisteredEntry;
        DAT_01070ac0->Configure(0x1e, true);
        DAT_01070ac0->SetName(DAT_00dcb7d0);
        DAT_0106cdcc->FUN_00444630(DAT_01070ac0);
    }
}


}   // namespace f3m_004bfd80

// @f3 0x004a8c80 (community match, verified in this file)
extern float DAT_01076230;
extern float DAT_01076270;
extern float DAT_01076284;
extern float DAT_010761f4;
extern float DAT_01076254;
extern const float DAT_00db9568;
namespace f3m_004a8c80 {
namespace f3m_004a8c80 {

unsigned int __fastcall FUN_004a8bb0(void* a, void* b, int c);

// pdb: BGSTerminal::GetMinSkillRequiredToHack | BGSTerminal.obj | fnv360_0822_debug, call_seq + bridge(call_gap|call_seq), high
float __fastcall BGSTerminal_GetMinSkillRequiredToHack(void* a, void* b, int c)
{
    switch (FUN_004a8bb0(a, b, c)) {
    case 0: return DAT_01076230;
    case 1: return DAT_01076270;
    case 2: return DAT_01076284;
    case 3: return DAT_010761f4;
    case 4: return DAT_01076254;
    }
    return DAT_00db9568;
}
}
}   // namespace f3m_004a8c80

// @f3 0x004ae610 (community match, verified in this file)
#include <stdlib.h>
#include <string.h>
namespace f3m_004ae610 {
extern "C" void* __cdecl _alloca(unsigned int);
namespace Load4ae610 {
struct File {
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
    unsigned chunkSize;
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
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned char unk298; bool swapEndian;
    unsigned char TESFile_GetTESForm();
    int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    void FUN_00447d60(void*,unsigned);
};
struct Data {
    unsigned flags; unsigned short value,unk06;
    unsigned unk08,unk0c,unk10,unk14,unk18,unk1c;
    void Clear() { flags=0; value=0; unk06=0; unk08=0; unk0c=0; unk10=0; unk14=0; unk18=0; unk1c=0; }
    static void Swap16(unsigned short* value) { *value=_byteswap_ushort(*value); }
    static void Swap32(unsigned* value) { *value=_byteswap_ulong(*value); }
    void Swap() { Swap16(&value); Swap32(&unk08); Swap32(&unk0c); Swap32(&unk10); Swap32(&unk14); Swap32(&unk18); }
};
void __cdecl FUN_00458210(void*,File*);
struct Form {
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void LoadBounds(File*);
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void SetEditorID(const char*);
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
    Data data;
    void FUN_00454410(File*);
    void TESForm_SetInitialized(int);
    void TESForm_LoadData(File*,void*,unsigned);
    bool FUN_004ae610(File*);
};
// pdb: TESGrass::Load | TESGrass.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Form::FUN_004ae610(File* file) {
    if(file->TESFile_GetTESForm()!=0x24) return false;
    Data* contents=&data;
    memset(contents,0,sizeof(*contents));
    FUN_00454410(file);
    TESForm_SetInitialized(0);
    int chunk=file->TESFile_GetTESChunk();
    while(chunk) {
        switch(chunk) {
        case 0x44494445: {
            char* buffer=(char*)_alloca(file->chunkSize);
            file->FUN_00447d60(buffer,0x200);
            SetEditorID(buffer);
            break;
        }
        case 0x41544144: TESForm_LoadData(file,contents,0x20); break;
        case 0x444e424f: LoadBounds(file); break;
        case 0x4c444f4d:
        case 0x54444f4d: FUN_00458210(this ? reinterpret_cast<char*>(this)+0x30:0,file); break;
        }
        if(chunk==0x41544144 && file->swapEndian) contents->Swap();
        if(!file->TESFile_NextChunk()) break;
        chunk=file->TESFile_GetTESChunk();
    }
    return true;
}
}
}   // namespace f3m_004ae610

// @f3 0x004bb210 (community match, verified in this file)
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#pragma intrinsic(_byteswap_ulong)
#pragma intrinsic(_alloca)
namespace f3m_004bb210 {
extern "C" void* __cdecl _alloca(size_t);
namespace Tree2361 {
inline void endian(float* p){unsigned* bits=(unsigned*)p;*bits=_byteswap_ulong(*bits);}
struct File { char unknown000[0x25c]; unsigned size; char unknown260[0x39]; bool endian; unsigned char TESFile_GetTESForm(); int TESFile_GetTESChunk(); bool TESFile_NextChunk(); bool FUN_00447d60(void*,unsigned); };
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);}; extern Heap DAT_01090a78;
struct Seed { unsigned value; static void* operator new[](size_t n){return DAT_01090a78.FUN_0086b930(n);} static void operator delete[](void*p){DAT_01090a78.FUN_0086ba60(p);} };
struct Seeds {char unknown[16];void FUN_0076e130(); void FUN_00ab9e10(const unsigned&);};
struct Data {float curvature,angle,dimming,rock,rustle; int shadowRadius;float speed,leaf;void FUN_00409ea0();};
struct Tree;
struct Vtable {void* unknown000[56];void (__thiscall* bounds)(Tree*,File*);void* unknown0e4[20];void (__thiscall* editor)(Tree*,char*);};
void __cdecl FUN_00458210(void*,File*);void __cdecl TESTexture_LoadTextureChunk(void*,File*);void __cdecl FUN_0044c110(void*,File*);
struct Tree { Vtable* vt; char unknown004[0x2c];char model[0x18];char texture[0xc];char destructible[8];Seeds seeds;Data data;float billboard[2];void FUN_00454410(File*);bool FUN_004bb210(File*);};
// pdb: TESObjectTREE::Load | TESObjectTREE.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Tree::FUN_004bb210(File*file){
 if(file->TESFile_GetTESForm()!=37)return false;
 FUN_00454410(file);
 while(int chunk=file->TESFile_GetTESChunk()){
 switch(chunk){
 case 0x44494445:{char*id=(char*)_alloca(file->size);file->FUN_00447d60(id,512);vt->editor(this,id);break;}
 case 0x444e424f:vt->bounds(this,file);break;
 case 0x4c444f4d:case 0x54444f4d:FUN_00458210(this?model:0,file);break;
 case 0x4e4f4349:TESTexture_LoadTextureChunk(this?texture:0,file);break;
 case 0x54534544:case 0x44545344:FUN_0044c110(this?destructible:0,file);break;
 case 0x4d414e53:{unsigned size=file->size;if(!size || size%4)break;unsigned count=size/4;Seed*values=new Seed[count];memset(values,0,size);file->FUN_00447d60(values,size);seeds.FUN_0076e130();for(unsigned i=0;i<count;++i){if(file->endian)values[i].value=_byteswap_ulong(values[i].value);if(values[i].value>0)seeds.FUN_00ab9e10(values[i].value);}delete[]values;break;}
 case 0x4d414e43:if(file->size!=sizeof(Data))break;file->FUN_00447d60(&data,sizeof(Data));if(file->endian)data.FUN_00409ea0();if(data.shadowRadius<0)data.shadowRadius=128;break;
 case 0x4d414e42:if(file->size!=8)break;file->FUN_00447d60(billboard,8);if(file->endian){endian(&billboard[0]);endian(&billboard[1]);}break;
 }
 if(!file->TESFile_NextChunk())break;
 }
 return true;
}
}



}   // namespace f3m_004bb210

// @f3 0x004bd470 (community match, verified in this file)
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
extern const char WeaponWarning[];
namespace f3m_004bd470 {
extern "C" void* __cdecl _alloca(unsigned int);
inline bool ValidAttack(unsigned x) { return x >= 32 && x <= 45; }
inline void SwapWord(unsigned short& v) { v = _byteswap_ushort(v); }
inline void SwapLong(unsigned& v) { v = _byteswap_ulong(v); }
struct ChunkFile;
struct ModelComponent {
    virtual void slot00(); virtual void slot04(); virtual void slot08();
    virtual void slot0c(); virtual void slot10(); virtual void slot14();
    virtual void SetPath(const char*);
    unsigned unk04, unk08, unk0c, unk10, unk14;
};
struct SimpleComponent { void FixScript(void*); };
struct ModelBase { void LoadTextures(void*, unsigned, unsigned); };
struct StringField { void Set(const char*, int); };
struct WeaponData {
    signed char kind; unsigned char unkF5, unkF6, unkF7;
    unsigned unkf8;
    unsigned unkfc;
    unsigned char unk100, animation, unk102, unk103;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned char unk11c, attack, shots, unk11f;
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
    float unk168;
    unsigned unk16c;
    unsigned unk170;
    float unk174;
    float unk178;
    void SwapEndian();
};
struct CriticalData { unsigned short unk17c, unk17e; unsigned unk180, unk184, unk188;  void SwapEndian() {
SwapWord(unk17c);
SwapLong(unk180);
} };
struct ChunkFile {
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    unsigned unkec;
    unsigned unkf0;
    unsigned unkf4;
    unsigned unkf8;
    unsigned unkfc;
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
    unsigned short version, unk256;
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
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned char unk298, swapped, unk29a, unk29b;
    unsigned char Type();
    int NextTag();
    bool NextChunk();
    void Read(void*, unsigned);
    void ReadForm(unsigned*);
    void ReadShort(unsigned*);
};
void LoadFullName(void*, ChunkFile*);
void LoadIcon(void*, ChunkFile*);
void LoadSmallIcon(void*, ChunkFile*);
void LoadModel(void*, ChunkFile*);
void LoadModelTexture(void*, ChunkFile*);
void LoadDestructible(void*, ChunkFile*);
bool ValidActorValue(unsigned);
void LogWeapon(const char*, ...);
struct Weapon {
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
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
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0(ChunkFile*);
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual const char* slot130();
    virtual void slot134(const char*);
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    ModelBase model;
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
    SimpleComponent script;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned short unk7c, unk7e;
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
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    unsigned unkec;
    unsigned unkf0;
    WeaponData data;
    CriticalData critical;
    ModelComponent model18c;
    ModelComponent model1a4;
    ModelComponent model1bc;
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
    StringField soundPath;
    unsigned unk204;
    unsigned unk208;
    unsigned GetFormID() const { return unkc; }
    void Initialize(ChunkFile*);
    void Reset(int);
    void LoadData(ChunkFile*, int, int);
    bool FUN_004bd470(ChunkFile* file);
};
// pdb: TESObjectWEAP::Load | TESObjectWEAP.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Weapon::FUN_004bd470(ChunkFile* file) {
    if (file->Type() != 0x28) return false;
    Initialize(file);
    Reset(0);
    int tag = file->NextTag();
    while (tag) {
        switch (tag) {
        case 0x314d414e:
        case 0x32444f4d:
        {
            char* buffer;
            if (file->unk25c) {
                buffer = (char*)_alloca(file->unk25c);
                file->Read(buffer, 0);
            } else buffer = 0;
            model18c.SetPath(buffer);
            break;
        }
        case 0x304d414e:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unka8 = value;
            break;
        }
        case 0x34444f4d:
        {
            char* buffer;
            if (file->unk25c) {
                buffer = (char*)_alloca(file->unk25c);
                file->Read(buffer, 0);
            } else buffer = 0;
            model1bc.SetPath(buffer);
            break;
        }
        case 0x33444f4d:
        {
            char* buffer;
            if (file->unk25c) {
                buffer = (char*)_alloca(file->unk25c);
                file->Read(buffer, 0);
            } else buffer = 0;
            model1a4.SetPath(buffer);
            break;
        }
        case 0x364d414e:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1e8 = value;
            break;
        }
        case 0x384d414e:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1f4 = value;
            break;
        }
        case 0x374d414e:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1e0 = value;
            break;
        }
        case 0x394d414e:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1f0 = value;
            break;
        }
        case 0x41544144:
        {
            LoadData(file, 0, 0);
            break;
        }
        case 0x444e424f:
        {
            slote0(file);
            break;
        }
        case 0x44494445:
        {
            char* buffer = (char*)_alloca(file->unk25c);
            file->Read(buffer, 0x200);
            slot134(buffer);
            break;
        }
        case 0x44534645:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1d4 = value;
            break;
        }
        case 0x49524353:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk6c = value;
            script.FixScript(this);
            break;
        }
        case 0x4c4c5546:
        {
            LoadFullName(this ? (char*)this + 0x30 : 0, file);
            break;
        }
        case 0x4c504552:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unkc0 = value;
            break;
        }
        case 0x4c504942:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unke4 = value;
            break;
        }
        case 0x4d414e59:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unkec = value;
            break;
        }
        case 0x4d414e5a:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unkf0 = value;
            break;
        }
        case 0x4d414e44:
        {
            if (file->version < 12) {
                memset(&data, 0, 0x88);
                data.unk174 = 0.1f;
                data.unk178 = 0.5f;
                file->Read(&data, file->unk25c);
                if (file->swapped) data.SwapEndian();
                if (data.attack < 0x8a && data.attack >= 0x38) {
                    data.attack += 0x12;
                    if (data.attack < 0x8a && data.attack >= 0x56) data.attack += 6;
                }
            } else if (file->version < 14) {
                memset(&data, 0, 0x88);
                data.unk174 = 0.1f;
                data.unk178 = 0.5f;
                file->Read(&data, file->unk25c);
                if (file->swapped) data.SwapEndian();
                if (data.attack < 0x8a && data.attack >= 0x56) data.attack += 6;
            } else {
                memset(&data, 0, 0x88);
                data.unk174 = 0.1f;
                data.unk178 = 0.5f;
                file->Read(&data, 0x88);
                if (file->swapped) data.SwapEndian();
                if (data.unk168 <= 0) data.unk168 = 1;
                if (data.animation < 0xab || (data.animation > 0xad && data.animation != 0xff)) data.animation = 0xff;
                if (!ValidAttack(data.unk15c)) data.unk15c = 45;
                if (!ValidActorValue(data.unk16c) && data.unk16c != -1) data.unk16c = -1;
            }
            break;
        }
        case 0x4d414e57:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1fc = value;
            break;
        }
        case 0x4d414e4e:
        {
            char* buffer = (char*)_alloca(file->unk25c);
            file->Read(buffer, 0);
            soundPath.Set(buffer, 0);
            break;
        }
        case 0x4d414e49:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1f8 = value;
            break;
        }
        case 0x4d414e53:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1d8 = value;
            break;
        }
        case 0x4d414e58:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1dc = value;
            break;
        }
        case 0x4d414e54:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1e4 = value;
            break;
        }
        case 0x4d414e55:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk1ec = value;
            break;
        }
        case 0x4d414e56:
        {
            unsigned enumValue;
            file->ReadForm(&enumValue);
            if (enumValue > 3) unk208 = 1;
            else unk208 = enumValue;
            break;
        }
        case 0x4d414e45:
        case 0x4d544945:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unk78 = value;
            break;
        }
        case 0x4f43494d:
        {
            LoadSmallIcon(this ? (char*)this + 0xd0 : 0, file);
            break;
        }
        case 0x4e4f4349:
        {
            LoadIcon(this ? (char*)this + 0x5c : 0, file);
            break;
        }
        case 0x50595445:
        {
            unsigned value = 0;
            file->ReadForm(&value);
            unkc8 = value;
            break;
        }
        case 0x54324f4d:
        {
            LoadModelTexture(&model18c, file);
            break;
        }
        case 0x53444f4d:
        {
            unsigned size = file->unk25c;
            void* textures = _alloca(size);
            file->Read(textures, size);
            model.LoadTextures(textures, size, file->version);
            break;
        }
        case 0x54334f4d:
        {
            LoadModelTexture(&model1a4, file);
            break;
        }
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x4c444f4d:
        case 0x54444f4d:
        {
            LoadModel(this ? (char*)this + 0x3c : 0, file);
            break;
        }
        case 0x54344f4d:
        {
            LoadModelTexture(&model1bc, file);
            break;
        }
        case 0x54445243:
        {
            file->Read(&critical, 0x10);
            if (file->swapped) {
                critical.SwapEndian();
            }
            break;
        }
        case 0x44545344:
        case 0x54534544:
        {
            LoadDestructible(this ? (char*)this + 0xb4 : 0, file);
            break;
        }
        case 0x4d414e41:
        case 0x544d4145:
        {
            unsigned value = 0;
            file->ReadShort(&value);
            unk7c = (unsigned short)value;
            break;
        }
        }
        if (!file->NextChunk()) break;
        tag = file->NextTag();
    }
    if (!data.shots) data.shots = 1;
    if (data.kind >= 13) {
        LogWeapon("MASTERFILE: Clearing invalid type on weapon '%s' (%08X).", slot130(), GetFormID());
        data.kind = 0;
    }
    return true;
}
}   // namespace f3m_004bd470
