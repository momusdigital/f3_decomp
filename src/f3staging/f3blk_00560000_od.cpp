// src/f3staging/f3blk_00560000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00565710 (community match, verified in this file)
extern "C" void* __cdecl _alloca(unsigned int size);
namespace f3m_00565710 {
struct File10 {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248, unk24c, unk250, unk254, unk258;
    unsigned int chunkSize;
    unsigned char TESFile_GetTESForm();
    int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    void FUN_00447d60(void* buf, unsigned int size);
    void FUN_00448800(void* out);
};
struct InfoArray10 {
    void* data;
    unsigned int capacity;
    unsigned int size;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int growBy;
    unsigned int GetFlags() { return size; }
    void FUN_006dc4b0(unsigned int newSize);
    void SetGrowBy(unsigned int g) { growBy = g; }
};
struct QuestInfo10 {
    int unk00;
    InfoArray10 infos;
    InfoArray10* GetInfoArray() { return &infos; }
};
struct FullName10 { void* vtbl; int unk04, unk08; };
void __cdecl FUN_00456560(FullName10* name, File10* file);
void __cdecl TESForm_AddCompileIndex(unsigned int* id, void* file);
struct TopicDefault10 {
    void* pTopic;
    int unk;
    const char* pName;
};
extern unsigned int g_auiTopicDefaultCounts10[8];
extern TopicDefault10* g_apTopicDefaults10[8];
struct TESTopic10;
extern TESTopic10* g_loadingTopic10;
struct FormBase10 {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void LoadBounds(struct File10* file);
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void SetEditorID(const char* id);
    int unk04, unk08;
    unsigned int formID;
    int unk10, unk14;
};
struct TESTopic10 : FormBase10, FullName10 {
    unsigned char type;
    unsigned char unk25;
    unsigned short unk26;
    float topicParamB;
    int unk2c, unk30;
    int topicFlags;
    unsigned int GetFormID() { return formID; }
    void FUN_00454410(File10* file);
    void* TESForm_GetFile(int index);
    QuestInfo10* FUN_00565120(unsigned int quest, bool create);
    void TESForm_SetInitialized(bool state);
    bool FUN_00565710(File10* pFile);
};

// pdb: TESTopic::Load | TESTopic.obj | fnv360_0822_retail, vtable, medium
// pdb params: pFile
bool TESTopic10::FUN_00565710(File10* pFile)
{
    if (pFile->TESFile_GetTESForm() != 0x45)
        return false;

    FUN_00454410(pFile);

    int chunkid;
    while ((chunkid = pFile->TESFile_GetTESChunk()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorID = (char*)_alloca(pFile->chunkSize);
            pFile->FUN_00447d60(pEditorID, 0x200);
            SetEditorID(pEditorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(pFile);
            break;
        case 0x4c4c5546:
            FUN_00456560(static_cast<FullName10*>(this), pFile);
            break;
        case 0x49545351: {
            unsigned int uiChunkType = 0;
            pFile->FUN_00448800(&uiChunkType);
            TESForm_AddCompileIndex(&uiChunkType, TESForm_GetFile(-1));
            QuestInfo10* pQuestInfo = FUN_00565120(uiChunkType, false);
            if (pQuestInfo)
            {
                unsigned int uiOldSize = pQuestInfo->GetInfoArray()->GetFlags();
                pQuestInfo->GetInfoArray()->FUN_006dc4b0(uiOldSize + 100);
                pQuestInfo->GetInfoArray()->SetGrowBy(10);
            }
            break;
        }
        case 0x4d414e50:
            pFile->FUN_00448800(&topicParamB);
            break;
        case 0x41544144:
            pFile->FUN_00447d60(&type, 2);
            break;
        case 0x58444958:
            pFile->FUN_00448800(&topicFlags);
            break;
        }
        if (!pFile->TESFile_NextChunk())
            break;
    }

    if (GetFormID() <= 0x7ff)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            for (unsigned int j = 0; j < g_auiTopicDefaultCounts10[i]; j++)
            {
                if (g_apTopicDefaults10[i][j].pTopic == this)
                {
                    type = (unsigned char)i;
                    SetEditorID(g_apTopicDefaults10[i][j].pName);
                }
            }
        }
    }

    TESForm_SetInitialized(false);
    g_loadingTopic10 = this;
    return true;
}
}

// @f3 0x00560060 (community match, verified in this file)
#include <vector>
#include <malloc.h>
#include <string.h>

namespace n560060 {
struct Form { int vtbl; int unk04; int unk08; unsigned int refID; };
struct Node { Form* item; Node* next; };
struct Model { int unk00, unk04, unk08, unk0c, unk10, unk14; void FUN_00457d90(unsigned int t1, unsigned int t2); void TESModel_SaveFlags(unsigned int t); };
struct Icon { int unk00, unk04, unk08; void FUN_0045b8e0(unsigned int t); };
struct Desc { int unk00, unk04, unk08; void FUN_00456390(); };
struct Name { int unk00, unk04; void TESDescription_Save(); };
struct Sizes { int unk00, unk04, unk08, unk0c, unk10; void TESSpellList_Save(); };
struct Flags40 { int unk00, unk04, unk08, unk0c; void FUN_00459a10(); };
struct RaceData { unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20; void FUN_0055f040(); };
struct Skills { int unk00, unk04, unk08; void TESAttributes_Save(char* out); };
struct FaceCoeffs { std::vector<float> coeffs; unsigned int count; unsigned int stride; };
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
extern bool DAT_0106dd0e;
struct FormID {
    unsigned int id;
    static void* operator new[](size_t size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
void __cdecl FUN_00454890(unsigned int tag, unsigned int value);
void __cdecl FUN_004554f0(unsigned int tag);
void __cdecl FUN_00455b30(unsigned int tag, const void* data, unsigned int count);
void __cdecl FUN_00455560(unsigned int tag, const void* data, unsigned int size);
void __cdecl FUN_00455710(unsigned int tag, float value);
void __cdecl FUN_00455780(unsigned int tag, unsigned short value);

inline unsigned int ToID(Form* f) { return f ? f->refID : 0; }

struct TESRace {
    int vtbl;
    char pad04[0x14];
    Desc desc18;
    Name name24;
    Sizes sizes2c;
    Flags40 flags40;
    RaceData data50;
    Skills skills74;
    Skills skills80;
    Node list8c;
    Form* form94;
    Form* form98;
    unsigned short unk9c;
    unsigned short unk9e;
    float unka0;
    float unka4;
    Node lista8;
    Model models[2][8];
    Icon icons[2][8];
    Icon bodyIcons[2][3];
    Model bodyModels[2][3];
    Model bodyModel[2];
    FaceCoeffs fg1[4];
    FaceCoeffs fg0[4];
    unsigned short unk4b8;
    unsigned short unk4ba;
    Form* form4bc;
    Form* form4c0;
    Form* form4c4;
    Form* form4c8;
    void FUN_004547d0();
    void FUN_00454860();
    void FUN_00454ab0(void* data, unsigned int size);
    void FUN_00560060();
};

// pdb: TESRace::Save | TESRace.obj | fnv360_0822_retail, vtable, medium
void TESRace::FUN_00560060()
{
    FUN_004547d0();
    desc18.FUN_00456390();
    name24.TESDescription_Save();
    sizes2c.TESSpellList_Save();
    flags40.FUN_00459a10();
    if (DAT_0106dd0e)
        data50.FUN_0055f040();
    FUN_00454ab0(&data50, sizeof(data50));
    if (DAT_0106dd0e)
        data50.FUN_0055f040();
    if (form4c4)
        FUN_00454890('MANO', form4c4->refID);
    if (form4c8)
        FUN_00454890('MANY', form4c8->refID);
    FUN_004554f0('2MAN');
    if (form4bc || form4c0) {
        unsigned int ids[2];
        ids[0] = ToID(form4bc);
        ids[1] = ToID(form4c0);
        FUN_00455b30('KCTV', ids, 2);
    }
    if (form94 || form98) {
        unsigned int ids[2];
        ids[0] = ToID(form94);
        ids[1] = ToID(form98);
        FUN_00455b30('MAND', ids, 2);
    }
    FUN_00455560('MANC', &unk9c, 2);
    FUN_00455710('MANP', unka0);
    FUN_00455710('MANU', unka4);
    char* attr = (char*)_alloca(14);
    skills74.TESAttributes_Save(attr);
    skills80.TESAttributes_Save(attr + 7);
    FUN_00455560('RTTA', attr, 2);
    FUN_004554f0('0MAN');
    for (unsigned int sex = 0; sex < 2; sex++) {
        if (sex == 0)
            FUN_004554f0('MANM');
        else if (sex == 1)
            FUN_004554f0('MANF');
        for (unsigned int i = 0; i < 8; i++) {
            FUN_00454890('XDNI', i);
            models[sex][i].FUN_00457d90('LDOM', 'TDOM');
            models[sex][i].TESModel_SaveFlags('DDOM');
            icons[sex][i].FUN_0045b8e0('NOCI');
        }
    }
    FUN_004554f0('1MAN');
    for (unsigned int sex = 0; sex < 2; sex++) {
        if (sex == 0)
            FUN_004554f0('MANM');
        else if (sex == 1)
            FUN_004554f0('MANF');
        unsigned int i;
        for (i = 0; i < 3; i++) {
            FUN_00454890('XDNI', i);
            bodyIcons[sex][i].FUN_0045b8e0('NOCI');
            bodyModels[sex][i].FUN_00457d90('LDOM', 'TDOM');
            bodyModels[sex][i].TESModel_SaveFlags('DDOM');
        }
        FUN_00454890('XDNI', i);
        bodyModel[sex].FUN_00457d90('LDOM', 'TDOM');
    }
    {
        Node* list = &list8c;
        unsigned int count = 0;
        for (Node* n = list; n; n = n->next)
            if (n->item)
                count++;
        FormID* arr = new FormID[count];
        unsigned int k = 0;
        for (; list && list->item; list = list->next)
            arr[k++].id = list->item->refID;
        FUN_00455b30('MANH', arr, count);
        delete[] arr;
    }
    {
        Node* list = &lista8;
        unsigned int count = 0;
        for (Node* n = list; n; n = n->next)
            if (n->item)
                count++;
        FormID* arr = new FormID[count];
        unsigned int k = 0;
        for (; list && list->item; list = list->next)
            arr[k++].id = list->item->refID;
        FUN_00455b30('MANE', arr, count);
        delete[] arr;
    }
    for (unsigned int sex = 0; sex < 2; sex++) {
        if (sex == 0)
            FUN_004554f0('MANM');
        else if (sex == 1)
            FUN_004554f0('MANF');
        unsigned int count = 0;
        if (sex == 0)
            count = fg0[0].count;
        else if (sex == 1)
            count = fg1[0].count;
        if (count) {
            float* buf = (float*)DAT_01090a78.FUN_0086b930(count * 4);
            memset(buf, 0, count * 4);
            for (unsigned int i = 0; i < count; i++) {
                if (sex == 0)
                    buf[i] = (&fg0[0].coeffs[0])[fg0[0].stride * i];
                else if (sex == 1)
                    buf[i] = (&fg1[0].coeffs[0])[fg1[0].stride * i];
            }
            FUN_00455b30('SGGF', buf, count);
            DAT_01090a78.FUN_0086ba60(buf);
        }
        if (sex == 0)
            count = fg0[1].count;
        else if (sex == 1)
            count = fg1[1].count;
        if (count) {
            float* buf = (float*)DAT_01090a78.FUN_0086b930(count * 4);
            memset(buf, 0, count * 4);
            for (unsigned int i = 0; i < count; i++) {
                if (sex == 0)
                    buf[i] = (&fg0[1].coeffs[0])[fg0[1].stride * i];
                else if (sex == 1)
                    buf[i] = (&fg1[1].coeffs[0])[fg1[1].stride * i];
            }
            FUN_00455b30('AGGF', buf, count);
            DAT_01090a78.FUN_0086ba60(buf);
        }
        if (sex == 0)
            count = fg0[2].count;
        else if (sex == 1)
            count = fg1[2].count;
        if (count) {
            float* buf = (float*)DAT_01090a78.FUN_0086b930(count * 4);
            memset(buf, 0, count * 4);
            for (unsigned int i = 0; i < count; i++) {
                if (sex == 0)
                    buf[i] = (&fg0[2].coeffs[0])[fg0[2].stride * i];
                else if (sex == 1)
                    buf[i] = (&fg1[2].coeffs[0])[fg1[2].stride * i];
            }
            FUN_00455b30('STGF', buf, count);
            DAT_01090a78.FUN_0086ba60(buf);
        }
        FUN_00455780('MANS', unk4b8);
    }
    FUN_00454860();
}
}

// @f3 0x00561fb0 (community match, verified in this file)
#include <vector>
#include <stdlib.h>
#include <string.h>

class TESForm { public: virtual void v000(); };
class TESHair : public TESForm { public: virtual void v004(); };
class TESEyes : public TESForm { public: virtual void v004(); };

namespace s561fb0 {

struct File {
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
    unsigned int subrecordSize25c;
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
    unsigned char unk298, swapped299;
    int TESFile_GetTESForm();
    int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    void FUN_00447d60(void* pBuf, unsigned int uiSize);
    void FUN_00448800(void* pOut);
    void TESFile_GetChunkData(void* pOut);
    unsigned int GetSize() { return subrecordSize25c; }
    bool IsSwapped() { return swapped299 != 0; }
};

inline void Swap(unsigned int& v) { v = _byteswap_ulong(v); }
inline void Swap(float& v) { unsigned int bits; memcpy(&bits, &v, sizeof bits); bits = _byteswap_ulong(bits); memcpy(&v, &bits, sizeof bits); }

struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;

struct FormID {
    unsigned int id;
    static __forceinline void* operator new[](size_t size) { return DAT_01090a78.FUN_0086b930(size); }
    static __forceinline void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Relation {
    unsigned int form;
    unsigned int mod;
    unsigned int reaction;
    static void* operator new(size_t size) { return DAT_01090a78.FUN_0086b930(size); }
};

struct BSString {
    char* pString;
    unsigned short usLen;
    unsigned short usMax;
    bool FUN_004019c0(const char* pText, unsigned short usLength);
};

struct Model {
    virtual void Clear();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetModel(const char* pPath);
    BSString path;
    int unk0c;
    int unk10;
    int unk14;
};

struct Icon {
    virtual void Clear();
    BSString path;
};

struct FaceCoeffs {
    std::vector<float> coeffs;
    unsigned int count;
    unsigned int stride;
    void FUN_0055a0a0(unsigned int n, float v);
};

struct FormBase {
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04c();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07c();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c();
    virtual void v0a0(); virtual void v0a4(); virtual void v0a8(); virtual void v0ac();
    virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc();
    virtual void v0d0(); virtual void v0d4(); virtual void v0d8(); virtual void v0dc();
    virtual void LoadBounds(File* pFile);
    virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char* pID);
    int unk04;
    int unk08;
    unsigned int formID;
    int unk10;
    int unk14;
};
struct FullName { void* vtbl; int unk04; int unk08; };
struct Description { void* vtbl; int unk04; };
struct SpellList { void* vtbl; int unk04; int unk08; int unk0c; int unk10; void FUN_0045ae90(unsigned int id); };
struct RelationNode {
    Relation* item;
    RelationNode* next;
    RelationNode(Relation* const& value) : item(value), next(0) {}
    static void* operator new(size_t size) { return DAT_01090a78.FUN_0086b930(size); }
};
struct RelationList {
    RelationNode head;
    int unk08;
    void FUN_0061c430(Relation* const& item);
};
void RelationList::FUN_0061c430(Relation* const& item) {
    if (item) {
        RelationNode* node = &head;
        while (node->next) node = node->next;
        if (node->item) node->next = new RelationNode(item);
        else node->item = item;
    }
}
struct Reaction { void* vtbl; RelationList list; };
struct Skills { char skill[7]; char unk07; int unk08; void FUN_004516b0(char* pData); };
struct RaceData {
    char skills[14];
    short unk0e;
    float height[2];
    float weight[2];
    unsigned int flags;
};
struct Node { void* item; Node* next; };

void __cdecl FUN_00456560(FullName* pName, File* pFile);
void __cdecl FUN_00453570(Description* pDesc, File* pFile);
void __cdecl TESForm_AddCompileIndex(unsigned int* pID, File* pFile);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int id);
void __cdecl FUN_00887da0(const char* pFormat, ...);
bool __cdecl FUN_0045b840(int chunk);
bool __cdecl FUN_00457b40(int chunk);
void __cdecl TESTexture_LoadTextureChunk(Icon* pIcon, File* pFile);
void __cdecl FUN_00458210(Model* pModel, File* pFile);

extern unsigned int DAT_01071fe4;
extern unsigned int DAT_01071fe8;
extern const char* DAT_00f5cc60[2][8];
extern const char* DAT_00f5cca0[2][8];
extern const char* DAT_00f5ccf8[2][3];
extern const char* DAT_00f5cc34[2];

struct Race : FormBase, FullName, Description, SpellList, Reaction {
    RaceData data;
    Skills skills74;
    Skills skills80;
    Node hairs;
    unsigned int defaultHair94;
    unsigned int defaultHair98;
    unsigned char hairColor9c;
    unsigned char hairColor9d;
    unsigned short unk9e;
    float faceGenMainClamp;
    float faceGenFaceClamp;
    Node eyes;
    Model models[2][8];
    Icon icons[2][8];
    Icon bodyIcons[2][3];
    Model bodyModels[2][3];
    Model bodyModel[2];
    FaceCoeffs faceGen3f8[2][2];
    FaceCoeffs faceGen458[2][2];
    unsigned short unk4b8;
    unsigned short unk4ba;
    unsigned int voice4bc;
    unsigned int voice4c0;
    unsigned int older4c4;
    unsigned int younger4c8;

    unsigned int GetFormID() const { return formID; }
    void FUN_00454410(File* pFile);
    void TESForm_LoadData(File* pFile, void* pData, unsigned int uiSize);
    void FUN_0055ff20(TESHair* pHair);
    void FUN_0055ff70(TESEyes* pEyes);
    bool FUN_00561fb0(File* pFile);
};

// pdb: TESRace::Load | TESRace.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Race::FUN_00561fb0(File* pFile)
{
    int iSex = 0;
    int iIndex = 0;
    bool bFace = false;
    bool bNew = true;
    int iType;
    int iSym;

    if (pFile->TESFile_GetTESForm() != 0xc)
        return false;

    FUN_00454410(pFile);

    int iChunk;
    while ((iChunk = pFile->TESFile_GetTESChunk()) != 0) {
        switch (iChunk) {
        case 'DIDE': {
            char* pID = (char*)_alloca(pFile->GetSize());
            pFile->FUN_00447d60(pID, 0x200);
            SetEditorID(pID);
            break;
        }
        case 'DNBO':
            LoadBounds(pFile);
            break;
        case 'LLUF':
            FUN_00456560(static_cast<FullName*>(this), pFile);
            break;
        case 'CSED':
            FUN_00453570(static_cast<Description*>(this), pFile);
            break;
        case 'OLPS': {
            unsigned int id = 0;
            pFile->FUN_00448800(&id);
            FUN_0045ae90(id);
            break;
        }
        case 'MANX': {
            Relation* pRel = new Relation;
            Relation* pItem = pRel;
            pFile->FUN_00447d60(pRel, sizeof(Relation));
            if (pFile->IsSwapped()) {
                Swap(pRel->form);
                Swap(pRel->mod);
                Swap(pRel->reaction);
            }
            list.FUN_0061c430(pItem);
            break;
        }
        case 'ATAD':
            TESForm_LoadData(pFile, &data, sizeof(data));
            break;
        case 'MANO': {
            unsigned int id = 0;
            pFile->FUN_00448800(&id);
            older4c4 = id;
            break;
        }
        case 'MANY': {
            unsigned int id = 0;
            pFile->FUN_00448800(&id);
            younger4c8 = id;
            break;
        }
        case 'MANP':
            pFile->FUN_00448800(&faceGenMainClamp);
            break;
        case 'MANU':
            pFile->FUN_00448800(&faceGenFaceClamp);
            break;
        case 'RTTA': {
            char* pAttr = (char*)_alloca(14);
            pFile->FUN_00447d60(pAttr, 14);
            skills74.FUN_004516b0(pAttr);
            skills80.FUN_004516b0(pAttr + 7);
            break;
        }
        case 'KCTV':
            if (pFile->GetSize() == 4) {
                voice4bc = DAT_01071fe4;
                voice4c0 = DAT_01071fe8;
            } else if (pFile->GetSize() == 8) {
                unsigned int ids[2];
                pFile->FUN_00447d60(ids, 8);
                if (pFile->IsSwapped()) {
                    for (int i = 0; i < 2; i++)
                        Swap(ids[i]);
                }
                if (!ids[0])
                    voice4bc = DAT_01071fe4;
                else
                    voice4bc = ids[0];
                voice4c0 = ids[1] ? ids[1] : DAT_01071fe8;
            }
            break;
        case 'MAND': {
            unsigned int ids[2];
            pFile->FUN_00447d60(ids, 8);
            if (pFile->IsSwapped()) {
                for (int i = 0; i < 2; i++)
                    Swap(ids[i]);
            }
            defaultHair94 = ids[0];
            defaultHair98 = ids[1];
            break;
        }
        case 'MANC':
            if (pFile->GetSize() == 1) {
                pFile->FUN_00447d60(&hairColor9c, 2);
                pFile->FUN_00447d60(&hairColor9d, 2);
            } else if (pFile->GetSize() == 2) {
                unsigned short usColor;
                pFile->FUN_00447d60(&usColor, 2);
                hairColor9c = (unsigned char)usColor;
                hairColor9d = (unsigned char)(usColor >> 8);
            }
            break;
        case '0MAN':
            bFace = true;
            break;
        case '1MAN':
            bFace = false;
            break;
        case '2MAN':
            bNew = false;
            break;
        case 'MANF':
            iSex = 1;
            break;
        case 'MANM':
            iSex = 0;
            break;
        case 'MANS':
            if (pFile->GetSize() >= 2)
                pFile->TESFile_GetChunkData(&unk4b8);
            break;
        case 'MANH': {
            unsigned int uiSize = pFile->GetSize();
            if (uiSize & 3)
                break;
            unsigned int uiCount = uiSize >> 2;
            if (!uiCount)
                break;
            FormID* pIDs = new FormID[uiCount];
            pFile->FUN_00447d60(pIDs, uiSize);
            for (unsigned int i = 0; i < uiCount; i++) {
                if (pFile->IsSwapped())
                    Swap(pIDs[i].id);
                TESForm_AddCompileIndex(&pIDs[i].id, pFile);
                TESHair* pHair = dynamic_cast<TESHair*>(TESForm_GetFormByNumericID(pIDs[i].id));
                if (pHair)
                    FUN_0055ff20(pHair);
                else
                    FUN_00887da0("MASTERFILE: Could not find hair (%08X) for race '%s' (%08X).", pIDs[i].id, GetEditorID(), GetFormID());
            }
            delete[] pIDs;
            break;
        }
        case 'MANE': {
            unsigned int uiSize = pFile->GetSize();
            if (uiSize & 3)
                break;
            unsigned int uiCount = uiSize >> 2;
            if (!uiCount)
                break;
            FormID* pIDs = new FormID[uiCount];
            pFile->FUN_00447d60(pIDs, uiSize);
            for (unsigned int i = 0; i < uiCount; i++) {
                if (pFile->IsSwapped())
                    Swap(pIDs[i].id);
                TESForm_AddCompileIndex(&pIDs[i].id, pFile);
                TESEyes* pEyes = dynamic_cast<TESEyes*>(TESForm_GetFormByNumericID(pIDs[i].id));
                if (pEyes)
                    FUN_0055ff70(pEyes);
                else
                    FUN_00887da0("MASTERFILE: Could not find eyes (%08X) for race '%s' (%08X).", pIDs[i].id, GetEditorID(), GetFormID());
            }
            delete[] pIDs;
            break;
        }
        case 'SGGF':
        case 'AGGF':
            if (iChunk == 'SGGF') {
                iType = 0;
                iSym = 0;
            } else {
                iType = 0;
                iSym = 1;
            }
            goto LoadFaceGen;
        case 'STGF':
            iType = 1;
            iSym = 0;
        LoadFaceGen:
        {
            unsigned int uiSize = pFile->GetSize();
            unsigned int uiCount = uiSize >> 2;
            if (iSex == 0 || bNew) {
                FaceCoeffs& kMale = faceGen458[iType][iSym];
                kMale.count = uiCount;
                kMale.stride = 1;
                kMale.FUN_0055a0a0(uiCount, 0.0f);
            }
            FaceCoeffs& kFemale = faceGen3f8[iType][iSym];
            kFemale.count = uiCount;
            kFemale.stride = 1;
            kFemale.FUN_0055a0a0(uiCount, 0.0f);
            float* pData = (float*)_alloca(uiSize);
            memset(pData, 0, uiSize);
            pFile->FUN_00447d60(pData, uiSize);
            for (unsigned int i = 0; i < uiCount; i++) {
                if (pFile->IsSwapped())
                    Swap(pData[i]);
                if (iSex == 0 || bNew)
                    (&faceGen458[iType][iSym].coeffs[0])[faceGen458[iType][iSym].stride * i] = pData[i];
                (&kFemale.coeffs[0])[kFemale.stride * i] = pData[i];
            }
            break;
        }
        case 'XDNI':
            pFile->FUN_00448800(&iIndex);
            if (bFace) {
                int iSub = (bNew && iIndex > 1) ? 1 : 0;
                if (iIndex < 8 && iIndex - iSub != 1) {
                    models[iSex][iIndex - iSub].Clear();
                    models[iSex][iIndex - iSub].SetModel(DAT_00f5cc60[iSex][iIndex - iSub]);
                    icons[iSex][iIndex - iSub].Clear();
                    icons[iSex][iIndex - iSub].path.FUN_004019c0(DAT_00f5cca0[iSex][iIndex - iSub], 0);
                }
            } else {
                if (iIndex < 3) {
                    bodyModels[iSex][iIndex].Clear();
                    bodyModels[iSex][iIndex].SetModel(DAT_00f5ccf8[iSex][iIndex]);
                    bodyIcons[iSex][iIndex].Clear();
                }
                if (iIndex == 3) {
                    bodyModel[iSex].Clear();
                    bodyModel[iSex].SetModel(DAT_00f5cc34[iSex]);
                }
            }
            break;
        default:
            if (bFace) {
                int iSub = (bNew && iIndex > 1) ? 1 : 0;
                if (iIndex - iSub < 8 && iIndex - iSub != 1) {
                    if (FUN_0045b840(iChunk))
                        TESTexture_LoadTextureChunk(&icons[iSex][iIndex - iSub], pFile);
                    else if (FUN_00457b40(iChunk))
                        FUN_00458210(&models[iSex][iIndex - iSub], pFile);
                }
            } else {
                if (iIndex < 3) {
                    if (FUN_0045b840(iChunk))
                        TESTexture_LoadTextureChunk(&bodyIcons[iSex][iIndex], pFile);
                    else if (FUN_00457b40(iChunk))
                        FUN_00458210(&bodyModels[iSex][iIndex], pFile);
                }
                if (iIndex == 3)
                    FUN_00458210(&bodyModel[iSex], pFile);
            }
            break;
        }
        if (iChunk == 'ATAD' && pFile->IsSwapped()) {
            for (int i = 0; i < 2; i++) {
                Swap(data.height[i]);
                Swap(data.weight[i]);
            }
            Swap(data.flags);
        }
        if (!pFile->TESFile_NextChunk())
            break;
    }
    return true;
}

}
