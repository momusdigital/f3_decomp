// src/f3staging/f3blk_00440000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0044c110 (community match, verified in this file)
#include <malloc.h>
#include <stdlib.h>
namespace f3m_0044c110 {
extern "C" void* __cdecl _alloca(unsigned int);
struct Model {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void setName(char*);
void FUN_00459340(void*,unsigned int,unsigned short);
};
struct Stage { unsigned char health, index, flags, unk03; unsigned int damage, explosion, debris, count; Model* model; void FUN_0044a1a0(); };
struct Destruction { unsigned int health; unsigned char count, flags; unsigned short unk06; Stage** stages; };
class BGSDestructibleObjectForm { public: virtual void dummy(); Destruction* data; void FUN_0044be90(); void FUN_0044bed0(); Stage** FUN_0044adf0(unsigned int); };
class TESForm { public:
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
virtual void v68();
virtual void v69();
virtual void v70();
virtual void v71();
virtual void v72();
virtual void v73();
virtual void v74();
virtual void v75();
virtual const char* name(); unsigned int unk04,unk08,id; };
struct TESFile {
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
unsigned short version,unk256; unsigned int unk258, chunkSize;
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
unsigned char unk298,swapped;
unsigned int TESFile_GetTESChunk(); void FUN_00447d60(void*,unsigned int); bool TESFile_NextChunk();
};
void FUN_00887da0(const char*,...);
void FUN_004580b0(Model*,TESFile*);
struct Header { unsigned int health; unsigned char count,flags; unsigned short unused; };
struct DiskStage { union { unsigned int packed; struct { unsigned char index,stage,health,flags; }; }; unsigned int damage,explosion,debris,count; };
// pdb: BGSDestructibleObjectForm::LoadChunk | BGSDestructibleObjectForm.obj | fnv360_0822_retail, ustr, medium
// pdb params: apDestruct, apFile
void FUN_0044c110(BGSDestructibleObjectForm* obj,TESFile* file) {
 if (!file || !obj) return;
 unsigned int type=file->TESFile_GetTESChunk();
 obj->FUN_0044be90();
 Destruction* data=obj->data;
 switch(type) {
 case 0x54534544: {
 Header h; h.health=0; h.count=0; h.flags=0;
 if(file->chunkSize!=8) {
 TESForm* form=dynamic_cast<TESForm*>(obj);
 unsigned int id=form->id; FUN_00887da0("MASTERFILE: Old Destruction data found on form %08X %s.  It needs to be resaved.",id,form->name());
 obj->FUN_0044bed0(); return;
 }
 file->FUN_00447d60(&h,0);
 if(file->swapped) h.health=_byteswap_ulong(h.health);
 data->health=h.health; data->count=h.count; data->flags=h.flags;
 if(h.count) data->stages=obj->FUN_0044adf0(*(unsigned int*)&h.count);
 return;
 }
 case 0x44545344: {
 DiskStage d={0}; file->FUN_00447d60(&d,20);
 if(file->swapped) {d.damage=_byteswap_ulong(d.damage);d.explosion=_byteswap_ulong(d.explosion);d.debris=_byteswap_ulong(d.debris);d.count=_byteswap_ulong(d.count);}
 if(d.stage>=data->count)return;
 unsigned int index=d.stage;
 data->stages[index]->health=d.health;
 data->stages[index]->index=d.index;
 data->stages[index]->flags=d.flags;
 data->stages[index]->damage=d.damage;
 data->stages[index]->explosion=d.explosion;
 data->stages[index]->debris=d.debris;
 data->stages[index]->count=d.count;
 int sub=file->TESFile_GetTESChunk();
 while(sub) {
 switch(sub) {
 case 0x46545344: return;
 case 0x4c444d44: { data->stages[index]->FUN_0044a1a0(); char* buf=(char*)_alloca(file->chunkSize); file->FUN_00447d60(buf,0); data->stages[index]->model->setName(buf); break; }
 case 0x53444d44: { data->stages[index]->FUN_0044a1a0(); unsigned int size=file->chunkSize; void* buf=_alloca(size); file->FUN_00447d60(buf,size); data->stages[index]->model->FUN_00459340(buf,size,file->version); break; }
 case 0x54444d44: data->stages[index]->FUN_0044a1a0(); FUN_004580b0(data->stages[index]->model,file); break;
 }
 if(!file->TESFile_NextChunk())break;
 sub=file->TESFile_GetTESChunk();
 }
 }
 }
}
}   // namespace f3m_0044c110

// @f3 0x0044d3b0 (community match, verified in this file)
#include <intrin.h>
namespace f3m_0044d3b0 {

struct UnkSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class CThing
{
public:
    char            unk00[4];
    unsigned char   field04;
    unsigned char   field05;
    char            unk06[2];
    UnkSub**        list;
    float           field0C;
    void FUN_0044d3b0();
};

extern "C" void FUN_004556a0(int tag, unsigned char value);
extern "C" void FUN_00455710(int tag, float value);
extern "C" void FUN_00455b30(int tag, int* arr, unsigned int count);

// pdb: BGSIdleCollection::Save | BGSIdleCollection.obj | fnv360_0822_retail, call_seq, medium
void CThing::FUN_0044d3b0()
{
    if (field05 == 0)
        return;
    FUN_004556a0(0x464c4449, field04);
    FUN_004556a0(0x434c4449, field05);
    FUN_00455710(0x544c4449, field0C);
    int* tmp = (int*)_alloca(field05 * 4);
    for (unsigned int i = 0; i < field05; i++)
    {
        if (list[i] != 0)
            tmp[i] = list[i]->unk0C;
        else
            tmp[i] = 0;
    }
    FUN_00455b30(0x414c4449, tmp, field05);
}
}   // namespace f3m_0044d3b0

// @f3 0x00458210 (community match, verified in this file)
namespace f3m_00458210 {
extern "C" void* __cdecl _alloca(unsigned int);

namespace f3m_00458210 {
struct TESFile458 {
    int GetChunkType_4487d0();
    void ReadChunk_447d60(void* buffer, unsigned int length);
    int unk000;
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
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
    int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258;
    unsigned int chunkLength_25c;
};

struct TESModel458 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetModel_18(const char* path);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char flags14;
};

void __cdecl FUN_004580b0(TESModel458* model, TESFile458* file);

// pdb: TESModel::LoadModelChunk | TESModel.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apModel, apFile
void __cdecl FUN_00458210(TESModel458* model, TESFile458* file)
{
    if (file && model) {
        switch (file->GetChunkType_4487d0()) {
        case 0x4c444f4d:
        case 0x4d414e50: {
            char* buffer = (char*)_alloca(file->chunkLength_25c);
            file->ReadChunk_447d60(buffer, 0);
            model->SetModel_18(buffer);
            break;
        }
        case 0x44444f4d:
        case 0x44534f4d: {
            char value;
            file->ReadChunk_447d60(&value, 1);
            model->flags14 = value;
            break;
        }
        case 0x54444f4d:
            FUN_004580b0(model, file);
            break;
        }
    }
}
}
}   // namespace f3m_00458210

// @f3 0x00458510 (community match, verified in this file)
#include <stdlib.h>
#include <string.h>

class TESForm
{
public:
    virtual ~TESForm();
};

class TESModelList
{
public:
    struct Node
    {
        void* item;
        Node* next;
    };
    virtual ~TESModelList();
    Node* GetHead() { return &list; }
    Node list;
};

namespace f3m_00458510 {

extern "C" void* __cdecl _alloca(unsigned int);

class MemoryHeap
{
public:
    void* FUN_0086b930(unsigned int size);
};
extern MemoryHeap DAT_01090a78;

class TESFile
{
public:
    char pad000[0x25c];
    unsigned int chunkSize;
    char pad260[0x39];
    bool bigEndian;
    unsigned int GetChunkSize() { return chunkSize; }
    void FUN_00447d60(void* buffer, unsigned int size);
};

inline void BSEndian(unsigned int* data, int count)
{
    for (int i = 0; i < count; i++)
        data[i] = _byteswap_ulong(data[i]);
}

class FileEntryList
{
public:
    unsigned char count;
    void* entries;
    FileEntryList() : count(0), entries(0) {}
    static void* operator new(size_t size) { return DAT_01090a78.FUN_0086b930(size); }
    void FUN_00457e80(char* data, unsigned int entryCount, TESForm* form, void* item);
};

struct FileEntrySlot
{
    FileEntryList* list;
    static void* operator new[](size_t size) { return DAT_01090a78.FUN_0086b930(size); }
};

class FileEntryListCollection
{
public:
    unsigned int m_uiCount;
    FileEntrySlot* m_ppArray;
    void FUN_004584b0();
    void FUN_00458510(TESModelList* owner, TESFile* file);
};

}

// pdb: TESTextureListArray::Load | TESModelList.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apModelList, apFile
void f3m_00458510::FileEntryListCollection::FUN_00458510(TESModelList* owner, TESFile* file)
{
    FUN_004584b0();
    unsigned int size = file->GetChunkSize();
    char* buffer = (char*)_alloca(size);
    file->FUN_00447d60(buffer, size);
    memcpy(this, buffer, 4);
    if (file->bigEndian)
        BSEndian(&m_uiCount, 1);
    unsigned int offset = 4;
    m_ppArray = new FileEntrySlot[m_uiCount];
    TESModelList::Node* node = owner->GetHead();
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        void* item = 0;
        if (node)
            item = node->item;
        node = node->next;
        m_ppArray[i].list = new FileEntryList;
        unsigned char count = buffer[offset];
        offset++;
        m_ppArray[i].list->FUN_00457e80(buffer + offset, count, dynamic_cast<TESForm*>(owner), item);
        offset += count * 0x18;
    }
}

// @f3 0x00454d10 (community match, verified in this file)
namespace f3m_00454d10 {

namespace f3m_00454d10 {

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);

class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
};

class TESFile
{
  public:
    unsigned short GetChunkSize() { return usChunkSize; }
    bool IsEndianConversionRequired() { return bSwap != 0; }
    void FUN_00447d60(void* apBuf, unsigned int auiSize);
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    unsigned int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    unsigned int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    unsigned int unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254, unk258;
    unsigned short usChunkSize;
    unsigned short unk25e;
    unsigned int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c;
    unsigned int unk290, unk294;
    unsigned char unk298;
    char bSwap;
};

inline void* MemCpy(void* apDest, const void* apSrc, unsigned int auiSize)
{
    return memcpy(apDest, apSrc, auiSize);
}

inline unsigned short MinUShort(unsigned short a, unsigned short b)
{
    return a < b ? a : b;
}

struct SwapTag
{
};

inline void SwapBytes(volatile int* p, SwapTag)
{
    *p = _byteswap_ulong(*p);
}

inline void SwapBytes(volatile int* p)
{
    *p = _byteswap_ushort(*(volatile unsigned short*)p);
}

}

class TESUsesForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void SetUses(unsigned char a) { uses = a; }
    unsigned char uses;
};

class TESValueForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void TESValueForm_SetFormValue(int a);
};

class TESHealthForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void SetHealth(int a) { health = a; }
    int health;
};

class TESWeightForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void SetWeight(float a) { weight = a; }
    float weight;
};

class TESQualityForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void SetQuality(unsigned char a) { quality = a; }
    unsigned char quality;
};

class TESAttackDamageForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void TESAttackDamageForm_SetAttackDamage(unsigned short a);
};

class TESAttributes : public f3m_00454d10::BaseFormComponent
{
  public:
    unsigned int FUN_004516b0(void* p);
};

class BGSClipRoundsForm : public f3m_00454d10::BaseFormComponent
{
  public:
    void SetClipRounds(unsigned char a) { rounds = a; }
    unsigned char rounds;
};

namespace f3m_00454d10 {
class TESForm454 : public ::TESForm
{
  public:
    void TESForm_LoadData(TESFile* file, void* dest, unsigned short count);
};
}

// pdb: TESForm::LoadData | TESForm.obj | fnv360_0822_retail, call_seq + skyrim(caller_sim), high
void f3m_00454d10::TESForm454::TESForm_LoadData(f3m_00454d10::TESFile* file, void* dest, unsigned short count)
{
    volatile int val;
    int damage;
    volatile float fval;
    unsigned short chunkSize = file->GetChunkSize();
    unsigned short pos = count;
    char* buffer = (char*)_alloca(chunkSize);
    file->FUN_00447d60(buffer, chunkSize);
    memcpy(dest, buffer, MinUShort(chunkSize, count));

    ::TESForm* form = this;
    TESUsesForm* pUses = dynamic_cast<TESUsesForm*>(form);
    TESValueForm* pValue = dynamic_cast<TESValueForm*>(form);
    TESHealthForm* pHealth = dynamic_cast<TESHealthForm*>(form);
    TESWeightForm* pWeight = dynamic_cast<TESWeightForm*>(form);
    TESQualityForm* pQuality = dynamic_cast<TESQualityForm*>(form);
    TESAttackDamageForm* pDamage = dynamic_cast<TESAttackDamageForm*>(form);
    TESAttributes* pAttr = dynamic_cast<TESAttributes*>(form);
    BGSClipRoundsForm* pClip = dynamic_cast<BGSClipRoundsForm*>(form);

    if (pUses && pos < chunkSize)
    {
        pUses->SetUses(buffer[pos]);
        pos += 1;
    }
    if (pValue && pos < chunkSize)
    {
        val = *(int*)(buffer + pos);
        pos += 4;
        if (file->IsEndianConversionRequired())
            SwapBytes(&val, SwapTag());
        pValue->TESValueForm_SetFormValue(val);
    }
    if (pHealth && pos < chunkSize)
    {
        val = *(int*)(buffer + pos);
        pos += 4;
        if (file->IsEndianConversionRequired())
            SwapBytes(&val, SwapTag());
        pHealth->SetHealth(val);
    }
    if (pWeight && pos < chunkSize)
    {
        float weight;
        MemCpy(&weight, buffer + pos, 4);
        fval = weight;
        pos += 4;
        if (file->IsEndianConversionRequired())
            SwapBytes((volatile int*)&fval, SwapTag());
        pWeight->SetWeight(fval);
    }
    if (pQuality && pos < chunkSize)
    {
        float quality;
        MemCpy(&quality, buffer + pos, 4);
        fval = quality;
        pos += 4;
        if (file->IsEndianConversionRequired())
            SwapBytes((volatile int*)&fval, SwapTag());
        pQuality->SetQuality((unsigned char)fval);
    }
    if (pDamage && pos < chunkSize)
    {
        *(volatile short*)&damage = *(short*)(buffer + pos);
        pos += 2;
        if (file->IsEndianConversionRequired())
            SwapBytes(&damage);
        pDamage->TESAttackDamageForm_SetAttackDamage(*(volatile unsigned short*)&damage);
    }
    if (pAttr)
        pos += pAttr->FUN_004516b0(buffer + pos);
    if (pClip && pos < chunkSize)
    {
        pClip->SetClipRounds(buffer[pos]);
        pos += 1;
    }
}
}   // namespace f3m_00454d10
