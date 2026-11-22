#include <new>
// src/f3staging/f3iso_004a3cc0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x004a3cc0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004a3cc0 (community match, verified in this file)
namespace f3m_004a3cc0 {
typedef int LocalChunkId;
class TESFile
{
  public:
    
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
unsigned short version,unk256;unsigned unk258,chunkSize;
unsigned GetChunkSize(){return chunkSize;}
    unsigned short GetFormVersion(){return version;}
    int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    bool FUN_00448800(unsigned int*);
    bool FUN_00447d60(void*, unsigned int);
};
extern "C" void* __cdecl _alloca(unsigned int);
class BGSListForm;
class TESBoundObject;
class TESForm
{
  public:
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
    virtual void LoadBoundObject(TESFile*);
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
    virtual void SetEditorID(const char*);
    void FUN_00454410(TESFile*);
    void TESForm_SetInitialized(bool);
    void TESForm_LoadData(TESFile*, void*, unsigned short);
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    void* pSourceFilesHead;
    void* pSourceFilesNext;
};
class TESBoundObjectBase : public TESForm
{
  public:
    void* pListHead;
    void* pPrev;
    void* pNext;
    short sBoundMinX;
    short sBoundMinY;
    short sBoundMinZ;
    short sBoundMaxX;
    short sBoundMaxY;
    short sBoundMaxZ;
};
class TESFullName
{
  public:
    void* pVtbl;
    char* pFullName;
    unsigned short sLen;
    unsigned short sMax;
};
class TESFullNameLoader
{
  public:
    static void FUN_00456560(TESFullName*, TESFile*);
};
class TESModel
{
  public:
    static void FUN_00458210(TESModel*, TESFile*);
    void* pVtbl;
    char* m_kModelObjectsItem;
    unsigned short sLen;
    unsigned short sMax;
    float m_fFadeDelta;
    void* pTextureList;
    unsigned char cFacegenFlags;
};
class TESModelTextureSwap : public TESModel
{
  public:
    bool FUN_00459340(void*, unsigned int, unsigned int);
    void* pSwapListHead;
    void* pSwapListNext;
};
class TESTexture
{
  public:
    static void __cdecl TESTexture_LoadTextureChunk(TESTexture*, TESFile*);
    void* pVtbl;
    char* pTexture;
    unsigned short sLen;
    unsigned short sMax;
};
class TESScriptableForm
{
  public:
    void FUN_006ecd40(unsigned x){m_pFormScript=(void*)x;}
    void FUN_0045a740(TESForm*);
    void* pVtbl;
    void* m_pFormScript;
    bool bResolved;
};
class TESValueForm
{
  public:
    void* pVtbl;
    int iValue;
};
class TESWeightForm
{
  public:
    void* pVtbl;
    float fWeight;
};
class BGSDestructibleObjectForm
{
  public:
    static void __cdecl FUN_0044c110(BGSDestructibleObjectForm*, TESFile*);
    void* pVtbl;
    void* pData;
};
class BGSMessageIcon
{
  public:
    static void __cdecl FUN_0044d910(BGSMessageIcon*, TESFile*);
    void* pVtbl;
    void* pIconVtbl;
    char* pIcon;
    unsigned int iIconLen;
};
class BGSPickupPutdownSounds
{
  public:
    void* pVtbl;
    void* pPickUpSound;
    void* pPutDownSound;

};
struct FUN_004a3cc0_cobj : public TESBoundObjectBase,
                           public TESFullName,
                           public TESModelTextureSwap,
                           public TESTexture,
                           public TESScriptableForm,
                           public TESValueForm,
                           public TESWeightForm,
                           public BGSDestructibleObjectForm,
                           public BGSMessageIcon,
                           public BGSPickupPutdownSounds
{
    BGSListForm* m_pCreatedObject;
    TESBoundObject* m_pWorkbenchKeyword;
    bool FUN_004a3cc0(TESFile* apFile);
};
// @fnv 0x004f96f0
// pdb: BGSConstructibleObject::Load | BGSConstructibleObject.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool FUN_004a3cc0_cobj::FUN_004a3cc0(TESFile* apFile)
{
    FUN_00454410(apFile);
    TESForm_SetInitialized(false);
    LocalChunkId chunkid;
    while ((chunkid = apFile->TESFile_GetTESChunk()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->FUN_00447d60(pEditorId, 0x200);
            SetEditorID(pEditorId);
            break;
        }
        case 0x444e424f:
            LoadBoundObject(apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::FUN_00456560(this, apFile);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::FUN_00458210(this, apFile);
            break;
        case 0x53444f4d: {
            unsigned int uiChunkSize = apFile->GetChunkSize();
            void* pChunkData = _alloca(uiChunkSize);
            apFile->FUN_00447d60(pChunkData, uiChunkSize);
            TESModelTextureSwap::FUN_00459340(pChunkData, uiChunkSize, apFile->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTexture::TESTexture_LoadTextureChunk(this, apFile);
            break;
        case 0x4f43494d:
            BGSMessageIcon::FUN_0044d910(this, apFile);
            break;
        case 0x49524353: {
            unsigned int tempint = 0;
            apFile->FUN_00448800(&tempint);
            TESScriptableForm::FUN_006ecd40(tempint);
            TESScriptableForm::FUN_0045a740(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::FUN_0044c110(this, apFile);
            break;
        case 0x41544144:
            TESForm_LoadData(apFile, 0, 0);
            break;
        case 0x4d414e52: {
            unsigned int itempint = 0;
            apFile->FUN_00448800(&itempint);
            m_pCreatedObject = (BGSListForm*)itempint;
            break;
        }
        case 0x4d414e43: {
            unsigned int itempint = 0;
            apFile->FUN_00448800(&itempint);
            m_pWorkbenchKeyword = (TESBoundObject*)itempint;
            break;
        }
        }
        if (!apFile->TESFile_NextChunk())
            break;
    }
    return true;
}

}   // namespace f3m_004a3cc0
