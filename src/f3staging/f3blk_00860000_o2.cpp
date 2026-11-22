#include <intrin.h>
// src/f3staging/f3blk_00860000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0086cb90 (community match, verified in this file)
struct FUN_0086cb90_Obj {
    void FUN_0086cb00(unsigned int value);
    FUN_0086cb90_Obj* FUN_0086cb90(unsigned int value);
};
// pdb: ScrapHeapManager::ScrapHeapManager | ScrapHeap.obj | fnv360_0822_debug, objrun, low
FUN_0086cb90_Obj* FUN_0086cb90_Obj::FUN_0086cb90(unsigned int value)
{
    unsigned int high = value;
    unsigned int low = value & 0xffff;
    if (low != 0) {
        high += 0x10000;
        high &= 0xffff0000;
    }
    FUN_0086cb00(high);
    return this;
}

// @f3 0x00862c60 (community match, verified in this file)
class CleanupObject237 { public: void FUN_0082b560(); };
class CleanupContext237 {
public:
    void FUN_0085ac70(CleanupObject237* object);
    void NiParticleMeshesData_LoadBinary(CleanupObject237* object);
};
// pdb: NiParticleMeshesData::LoadBinary | NiParticleMeshesData.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
void CleanupContext237::NiParticleMeshesData_LoadBinary(CleanupObject237* object) {
    FUN_0085ac70(object);
    object->FUN_0082b560();
}

// @f3 0x0086c000 (community match, verified in this file)
#include <intrin.h>

extern "C" int(__stdcall* const DAT_00d9b1c8)(void*);
extern "C" int(__stdcall* const DAT_00d9b294)(void*, const char*, const char*, unsigned int);

extern void* FUN_00c00610(void* dest, int value, unsigned int size);
void __stdcall FUN_00c06b0d(int code);
void FUN_0086d670(void);
void FUN_0086c600(void);

extern unsigned int DAT_01179af4;

class CloneHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
};
extern CloneHeap DAT_01090a78;

class ScrapHeap;

template <class K, class V> class BSMapBase
{
public:
    virtual ~BSMapBase();
    BSMapBase(unsigned int hashSize);
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_kItemCount;
};

template <class K, class V> class BSMap : public BSMapBase<K, V>
{
public:
    virtual ~BSMap();
    BSMap(unsigned int hashSize);
    virtual void vg00();
    virtual void vg04();
};

template <class K, class V> BSMapBase<K, V>::BSMapBase(unsigned int hashSize)
{
    m_uiHashSize = hashSize;
    m_kItemCount = 0;
    m_ppkHashTable = (void**)DAT_01090a78.FUN_0086b930(hashSize * 4);
    FUN_00c00610(m_ppkHashTable, 0, m_uiHashSize * 4);
}

template <class K, class V> BSMap<K, V>::BSMap(unsigned int hashSize) : BSMapBase<K, V>(hashSize)
{
}

struct MemStatus
{
    unsigned int m_dwLength;
    unsigned int m_unk00;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned __int64 m_availPageFile;
    unsigned __int64 m_unk28;
    unsigned __int64 m_unk30;
    unsigned __int64 m_unk38;
};

struct TLSThreadData
{
    unsigned char m_pad[0x298];
    int m_unk298;
};

class FUN_0086c000
{
public:
    FUN_0086c000();

    void FUN_006e21f0();
    void FUN_006e1e10();
    void FUN_006e1d50();

    bool m_b00;
    unsigned short m_s02;
    unsigned short m_s04;
    int m_i08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7c;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8c;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9c;
    int m_unka0;
    int m_unk_a4;
    int m_unk_a8;
    int m_unk_ac;
    int m_unk_b0;
    int m_unk_b4;
    int m_unk_b8;
    int m_unk_bc;
    int m_unk_c0;
    int m_unk_c4;
    int m_unk_c8;
    int m_unk_cc;
    int m_unk_d0;
    int m_unk_d4;
    int m_unk_d8;
    int m_unk_dc;
    int m_unk_e0;
    int m_unk_e4;
    int m_unk_e8;
    int m_unk_ec;
    int m_unk_f0;
    int m_unk_f4;
    int m_unk_f8;
    int m_unk_fc;
    int m_unk100;
    BSMap<unsigned int, ScrapHeap*> m_map;
    int m_i114;
    bool m_b118;
    bool m_b119;
    int m_i11c;
    int m_i120;
};

// pdb: MemoryManager::MemoryManager | MemoryManager.obj | tesv_win, ustr, medium
FUN_0086c000::FUN_0086c000()
    : m_s02(0), m_s04(0), m_i08(0), m_map(0x25), m_i114(0), m_b118(true), m_b119(true), m_i11c(0), m_i120(0)
{
    MemStatus kStatus;
    kStatus.m_dwLength = sizeof(kStatus);
    if (DAT_00d9b1c8(&kStatus) && kStatus.m_availPageFile < 0x20000000)
    {
        DAT_00d9b294(0, "Not enough memory to run application.", "Memory Error", 0x10);
        FUN_00c06b0d(0);
    }
    FUN_0086d670();
    FUN_006e21f0();
    m_b00 = true;
    FUN_006e1e10();
    unsigned int tlsIndex = *(volatile unsigned int*)&DAT_01179af4;
    void** tlsArray = (void**)__readfsdword(0x2c);
    ((TLSThreadData*)tlsArray[tlsIndex])->m_unk298 = 0;
    FUN_006e1d50();
    FUN_0086c600();
}

// @f3 0x0086e6c0 (community match, verified in this file)
namespace f3m_0086e6c0 {
struct Block726 { int unk00; };
int FUN_008843d0(int value, Block726* block);
struct Owner726 {
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
    int unk25c;
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
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    Block726 block;
    int FUN_0086e6c0(int value);
};
// pdb: NiXenonRenderer::FindClosestPixelFormat | NiXenonRenderer.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: kFmtPrefs
int Owner726::FUN_0086e6c0(int value)
{
    return FUN_008843d0(value, &block);
}
}   // namespace f3m_0086e6c0

// @f3 0x00878e30 (community match, verified in this file)
#include <string.h>

void FUN_00c24b70(const char* pcFormat, ...);

struct FUN_00878e30_Node {
    void* m_pvItem;
    FUN_00878e30_Node* m_pkNext;
};
extern FUN_00878e30_Node DAT_01091858;

struct FUN_00878e30_PresentParams {
    unsigned int m_uiBackBufferWidth;
    unsigned int m_uiBackBufferHeight;
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
};

class FUN_00878e30_Adapter {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual FUN_00878e30_Node* GetListHead();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    FUN_00878e30_PresentParams m_kPresentParams;
    bool ContainsNode(FUN_00878e30_Node* pkNode)
    {
        for (FUN_00878e30_Node* pkCur = GetListHead(); pkCur; pkCur = pkCur->m_pkNext) {
            if (pkCur == pkNode)
                return true;
        }
        return false;
    }
};

struct FUN_00878e30_Slot {
    int unk00; int unk04; int unk08; int unk0C;
    FUN_00878e30_Adapter* m_pkAdapter;
};

class FUN_00878e30_AdapterList {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual FUN_00878e30_Slot* GetSlot(int i);
};

class FUN_00878e30_Renderer {
public:
    char pad[0x884];
    FUN_00878e30_AdapterList* m_pkAdapterList;
    bool FUN_00878700();
    int FUN_00878e30(unsigned int uiWidth, unsigned int uiHeight);
};

// pdb: NiDX9Renderer::Recreate | NiDX9Renderer.obj | tesv_win, ustr, medium
int FUN_00878e30_Renderer::FUN_00878e30(unsigned int uiWidth, unsigned int uiHeight)
{
    FUN_00878e30_Slot* pkSlot = m_pkAdapterList->GetSlot(0);
    FUN_00878e30_Adapter* pkAdapter = pkSlot->m_pkAdapter;
    FUN_00878e30_Adapter* pkDesc = !pkAdapter ? 0 : (pkAdapter->ContainsNode(&DAT_01091858) ? pkAdapter : 0);
    FUN_00878e30_PresentParams* pkParams = &pkDesc->m_kPresentParams;
    FUN_00878e30_PresentParams kSaved;
    memmove(&kSaved, pkParams, sizeof(FUN_00878e30_PresentParams));
    pkParams->m_uiBackBufferWidth = uiWidth;
    pkParams->m_uiBackBufferHeight = uiHeight;
    if (!FUN_00878700()) {
        FUN_00c24b70("NiDX9Renderer::Recreate> Could not reset device to desired parameters - trying to recover original values\n");
        memmove(pkParams, &kSaved, sizeof(FUN_00878e30_PresentParams));
        if (!FUN_00878700()) {
            FUN_00c24b70("NiDX9Renderer::Recreate> Could not recover original presentation parameters\n");
            return 0;
        }
        return 1;
    }
    return 2;
}

// @f3 0x0087f0c0 (community match, verified in this file)
namespace f3m_0087f0c0 {
namespace fo3_0087f0c0 {
struct StreamCopyInfo {
    unsigned int format;
    unsigned short inputBytes;
    unsigned short unk06;
    unsigned short vertexCount;
    unsigned short unk0A;
    unsigned short* indices;
    unsigned char* source;
    unsigned int unk14;
    unsigned int sourceStride;
    unsigned int bytesPerVertex;
    unsigned int outputStride;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char* destination;
};
void* __cdecl FUN_00c00610(void*, int, unsigned int);

// @fnv 0x00e77010
// pdb: NiD3DShaderDeclaration::Pack_FloatToShort | NiXenonShaderDeclaration.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: NiD3DShaderDeclaration::Pack_LongToShort)
// pdb params: kParams
unsigned int __cdecl FUN_0087f0c0(StreamCopyInfo* stream)
{
    unsigned int bytesWritten = 0;
    const unsigned char* source = stream->source;
    unsigned char* destination = stream->destination;
    const unsigned short* indices = stream->indices;

    if (!source) {
        for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
            FUN_00c00610(destination, 0, stream->bytesPerVertex);
            destination += stream->outputStride;
            bytesWritten += stream->bytesPerVertex;
        }
        return bytesWritten;
    }

    unsigned short availableComponents = stream->inputBytes - 4;
    unsigned short outputComponents = stream->format == 6 ? 2 : 4;
    unsigned short components = availableComponents > outputComponents
        ? outputComponents : availableComponents;

    if (indices) {
        unsigned short indexPosition = 0;
        for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
            const unsigned char* input = source + indices[indexPosition++] * stream->sourceStride;
            unsigned short* output = (unsigned short*)destination;
            unsigned short copied = 0;
            for (; copied < components; ++copied) {
                *output++ = *(const unsigned short*)input;
                input += 4;
            }
            for (; copied < outputComponents; ++copied)
                *output++ = 0;
            destination += stream->outputStride;
            bytesWritten += stream->bytesPerVertex;
        }
        return bytesWritten;
    }

    for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
        const unsigned char* input = source;
        unsigned short* output = (unsigned short*)destination;
        unsigned short copied = 0;
            for (; copied < components; ++copied) {
            *output++ = *(const unsigned short*)input;
            input += 4;
        }
        for (; copied < outputComponents; ++copied)
                *output++ = 0;
        source += stream->sourceStride;
        destination += stream->outputStride;
        bytesWritten += stream->bytesPerVertex;
    }
    return bytesWritten;
}

}
}   // namespace f3m_0087f0c0

// @f3 0x0087b170 (community match, verified in this file)
extern unsigned int DAT_01091728;
namespace f3m_0087b170 {
// Stand-in reconstruction of FUN_0087b170 (NiDX9SourceTextureData-style CreateSurf).
// The pack's header declares none of these graphics types, so declare them here.

struct TexInput
{
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    unsigned int* p54;      // 0x54
    unsigned int* p58;      // 0x58
    int unk5c;              // 0x5c
    unsigned int levels;    // 0x60
};

struct TexDevice {
    virtual void __stdcall v00()=0;
    virtual void __stdcall v01()=0;
    virtual void __stdcall v02()=0;
    virtual void __stdcall v03()=0;
    virtual void __stdcall v04()=0;
    virtual void __stdcall v05()=0;
    virtual void __stdcall v06()=0;
    virtual void __stdcall v07()=0;
    virtual void __stdcall v08()=0;
    virtual void __stdcall v09()=0;
    virtual void __stdcall v10()=0;
    virtual void __stdcall v11()=0;
    virtual void __stdcall v12()=0;
    virtual void __stdcall v13()=0;
    virtual void __stdcall v14()=0;
    virtual void __stdcall v15()=0;
    virtual void __stdcall v16()=0;
    virtual void __stdcall v17()=0;
    virtual void __stdcall v18()=0;
    virtual void __stdcall v19()=0;
    virtual void __stdcall v20()=0;
    virtual void __stdcall v21()=0;
    virtual void __stdcall v22()=0;
    virtual long __stdcall CreateTexture(unsigned int Width,unsigned int Height,unsigned int Levels,unsigned int Usage,unsigned int Format,unsigned int Pool,void** ppTexture,void* pSharedHandle)=0;
};

class TexRenderer
{
public:
    virtual void v00(void) = 0;
    virtual void v01(void) = 0;
    virtual void v02(void) = 0;
    virtual void v03(void) = 0;
    virtual void v04(void) = 0;
    virtual void v05(void) = 0;
    virtual void v06(void) = 0;
    virtual void v07(void) = 0;
    virtual void v08(void) = 0;
    virtual void v09(void) = 0;
    virtual void v10(void) = 0;
    virtual void v11(void) = 0;
    virtual void v12(void) = 0;
    virtual void v13(void) = 0;
    virtual void v14(void) = 0;
    virtual void v15(void) = 0;
    virtual void v16(void) = 0;
    virtual void v17(void) = 0;
    virtual void v18(void) = 0;
    virtual void v19(void) = 0;
    virtual void v20(void) = 0;
    virtual void v21(void) = 0;
    virtual void v22(void) = 0;
    virtual void v23(void) = 0;
    virtual void v24(void) = 0;
    virtual void v25(void) = 0;
    virtual void v26(void) = 0;
    virtual void v27(void) = 0;
    virtual void v28(void) = 0;
    virtual void v29(void) = 0;
    virtual void v30(void) = 0;
    virtual void v31(void) = 0;
    virtual void v32(void) = 0;
    virtual void v33(void) = 0;
    virtual void v34(void) = 0;
    virtual void v35(void) = 0;
    virtual void v36(void) = 0;
    virtual void v37(void) = 0;
    virtual void v38(void) = 0;
    virtual void v39(void) = 0;
    virtual unsigned char Flags(void) = 0;   // vtable + 0xa0
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
    int unk25c;
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
    TexDevice* device;      // 0x288
};

struct TexData
{
    int unk00; int unk04; int unk08;
    unsigned int width;     // 0x0c
    unsigned int height;    // 0x10
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    TexRenderer* renderer;  // 0x60
    void* texture;          // 0x64
    unsigned int levels;    // 0x68
    int unk6c; int unk70; int unk74;
    unsigned int skip;      // 0x78

    bool FUN_0087b170(TexInput* input);
};

extern "C" unsigned int FUN_00881ef0(int* sub);
extern "C" const char* FUN_0088ae00(long hr);
extern "C" void FUN_00c24b70(const char* fmt, const char* text);

static inline bool TexIsPowerOfTwo(unsigned int x)
{
    if (x == 0)
        return false;
    return (x & (x - 1)) == 0;
}

// pdb: NiDX9SourceTextureData::CreateSurf | NiDX9SourceTextureData.obj | tesv_win, ustr, medium
bool TexData::FUN_0087b170(TexInput* input)
{
    unsigned int format = FUN_00881ef0(&this->unk14);
    this->width  = *input->p54;
    this->height = *input->p58;
    if ((!TexIsPowerOfTwo(this->width) || !TexIsPowerOfTwo(this->height)) && !(this->renderer->Flags() & 8))
        this->levels = 1;
    else
        this->levels = input->levels;
    unsigned int levels = this->levels;
    unsigned int dropped = DAT_01091728;
    if (dropped > levels - 1)
        dropped = levels - 1;
    for (unsigned int i = 0; i < dropped; ++i)
    {
        if (this->width & 1)
            ++this->width;
        this->width >>= 1;
        if (this->height & 1)
            ++this->height;
        this->height >>= 1;
    }
    this->skip = dropped;
    TexDevice* device = this->renderer->device;
    void* created = 0;
    long hr = device->CreateTexture( this->width, this->height, levels - dropped,
                                          0, format, 1, &created, 0);
    if (hr >= 0 && created)
    {
        this->texture = created;
        return true;
    }
    FUN_00c24b70("NiDX9SourceTextureData::CreateSurf> Failed CreateImageSurface - %s\n",
                 FUN_0088ae00(hr));
    this->texture = 0;
    return false;
}
}   // namespace f3m_0087b170

// @f3 0x0087b3f0 (community match, verified in this file)
extern unsigned int DAT_01091728;
namespace f3m_0087b3f0 {
struct TexInput { char pad[0x74]; unsigned levels; };
struct TexDevice {
    virtual void v00(void) = 0; virtual void v01(void) = 0; virtual void v02(void) = 0; virtual void v03(void) = 0;
    virtual void v04(void) = 0; virtual void v05(void) = 0; virtual void v06(void) = 0; virtual void v07(void) = 0;
    virtual void v08(void) = 0; virtual void v09(void) = 0; virtual void v10(void) = 0; virtual void v11(void) = 0;
    virtual void v12(void) = 0; virtual void v13(void) = 0; virtual void v14(void) = 0; virtual void v15(void) = 0;
    virtual void v16(void) = 0; virtual void v17(void) = 0; virtual void v18(void) = 0; virtual void v19(void) = 0;
    virtual void v20(void) = 0; virtual void v21(void) = 0; virtual void v22(void) = 0;
    virtual long __stdcall CreateTexture(unsigned int Width, unsigned int Height, unsigned int Levels, unsigned int Usage, unsigned int Format, unsigned int Pool, void** ppTexture, void* pSharedHandle) = 0;
};
class TexRenderer {
public:
    virtual void v00(void) = 0; virtual void v01(void) = 0; virtual void v02(void) = 0; virtual void v03(void) = 0;
    virtual void v04(void) = 0; virtual void v05(void) = 0; virtual void v06(void) = 0; virtual void v07(void) = 0;
    virtual void v08(void) = 0; virtual void v09(void) = 0; virtual void v10(void) = 0; virtual void v11(void) = 0;
    virtual void v12(void) = 0; virtual void v13(void) = 0; virtual void v14(void) = 0; virtual void v15(void) = 0;
    virtual void v16(void) = 0; virtual void v17(void) = 0; virtual void v18(void) = 0; virtual void v19(void) = 0;
    virtual void v20(void) = 0; virtual void v21(void) = 0; virtual void v22(void) = 0; virtual void v23(void) = 0;
    virtual void v24(void) = 0; virtual void v25(void) = 0; virtual void v26(void) = 0; virtual void v27(void) = 0;
    virtual void v28(void) = 0; virtual void v29(void) = 0; virtual void v30(void) = 0; virtual void v31(void) = 0;
    virtual void v32(void) = 0; virtual void v33(void) = 0; virtual void v34(void) = 0; virtual void v35(void) = 0;
    virtual void v36(void) = 0; virtual void v37(void) = 0; virtual void v38(void) = 0; virtual void v39(void) = 0;
    virtual unsigned char Flags(void) = 0;
    char pad[0x284]; TexDevice* device;
};
struct TexData {
    int unk00; int unk04; int unk08; unsigned int width; unsigned int height;
    int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    TexRenderer* renderer; void* texture; unsigned int levels; char unk6c; bool b6d; char pad71[0x78-0x6e]; unsigned int skip;
    bool FUN_0087b3f0(TexInput* input, unsigned int format);
};
const char* FUN_0088ae00(long hr);
void FUN_00c24b70(const char* fmt, ...);
static inline bool TexIsPowerOfTwo(unsigned int x) { if (x == 0) return false; return (x & (x - 1)) == 0; }
// pdb: NiDX9SourceTextureData::CreateSurfFromRendererData | NiDX9SourceTextureData.obj | tesv_win, call_gap, low
bool TexData::FUN_0087b3f0(TexInput* input, unsigned int format)
{
    if ((!TexIsPowerOfTwo(this->width) || !TexIsPowerOfTwo(this->height)) && !(this->renderer->Flags() & 8))
        this->levels = 1;
    else
        this->levels = input->levels;
    unsigned int levels = this->levels;
    this->b6d = (levels != 1);
    unsigned int dropped = DAT_01091728;
    if (dropped > levels - 1) dropped = levels - 1;
    for (unsigned int i = 0; i < dropped; ++i) {
        if (this->width & 1) ++this->width;
        this->width >>= 1;
        if (this->height & 1) ++this->height;
        this->height >>= 1;
    }
    unsigned int argLevels = levels - dropped;
    this->skip = dropped;
    TexDevice* device = this->renderer->device;
    void* created = 0;
    long hr = device->CreateTexture(this->width, this->height, argLevels, 0, format, 1, &created, 0);
    if (hr >= 0 && created) { this->texture = created; return true; }
    FUN_00c24b70("NiDX9SourceTextureData::CreateSurfFromRendererData> FAILED to create texture of format: 0x%x, D3D error: %s", format, FUN_0088ae00(hr));
    this->texture = 0; return false;
}
}   // namespace f3m_0087b3f0

// @f3 0x0087f5e0 (community match, verified in this file)
#include <string.h>
namespace f3m_0087f5e0 {
namespace f3m_0087f5e0 {
struct QStream {
    unsigned int format;
    unsigned short inputBytes;
    unsigned short unk06;
    unsigned short vertexCount;
    unsigned short unk0A;
    unsigned short* indices;
    unsigned char* source;
    unsigned int unk14;
    unsigned int sourceStride;
    unsigned int bytesPerVertex;
    unsigned int outputStride;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char* destination;
};
// pdb: NiD3DShaderDeclaration::Pack_UnsignedShortToShort | NiXenonShaderDeclaration.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kParams
unsigned int __cdecl FUN_0087f5e0(QStream* stream)
{
    unsigned int total = 0;
    unsigned char* dst = stream->destination;
    unsigned char* src = stream->source;
    unsigned short* indices = stream->indices;
    if (!src) {
        for (unsigned short i = 0; i < stream->vertexCount; i++) {
            memset(dst, 0, stream->bytesPerVertex);
            dst += stream->outputStride;
            total += stream->bytesPerVertex;
        }
        return total;
    }
    unsigned short avail = (unsigned short)(stream->inputBytes - 16);
    unsigned short elems = (stream->format != 6) ? 4 : 2;
    unsigned short n = (avail > elems) ? elems : avail;
    if (indices) {
        unsigned short k = 0;
        for (unsigned short i = 0; i < stream->vertexCount; i++) {
            unsigned short* s = (unsigned short*)(src + indices[k++] * stream->sourceStride);
            unsigned short* d = (unsigned short*)dst;
            unsigned short j;
            for (j = 0; j < n; j++) *d++ = *s++;
            for (; j < elems; j++) *d++ = 0;
            dst += stream->outputStride;
            total += stream->bytesPerVertex;
        }
    } else {
        for (unsigned short i = 0; i < stream->vertexCount; i++) {
            unsigned short* s = (unsigned short*)src;
            unsigned short* d = (unsigned short*)dst;
            unsigned short j;
            for (j = 0; j < n; j++) *d++ = *s++;
            for (; j < elems; j++) *d++ = 0;
            src += stream->sourceStride;
            dst += stream->outputStride;
            total += stream->bytesPerVertex;
        }
    }
    return total;
}
}
}   // namespace f3m_0087f5e0

// @f3 0x008665c0 (community match, verified in this file)
namespace f3m_008665c0 {
// pdb: NiShaderConstantMap::AddEntry | NiShaderConstantMap.obj | fnv360_0721_beta, objrun_open, low
// pdb params: pszKey, uiFlags, uiExtra, uiShaderRegister, uiRegisterCount, pszVariableName, uiDataSize, uiDataStride, pvDataSource, bCopyData
int __stdcall FUN_008665c0(int a, int b, int c, int d) { return 0x30; }
}   // namespace f3m_008665c0

// @f3 0x0086cdd0 (community match, verified in this file)
namespace f3m_0086cdd0 {
// pdb: BSReadWriteLock::UnlockRead | BSReadWriteLock.obj | fnv360_0721_beta, caller, low
namespace f3m_0086cdd0 { extern long (__stdcall* DAT_00d9b064)(long*); struct O { long count; long FUN_0086cdd0(); }; long O::FUN_0086cdd0() { return DAT_00d9b064(&count); } }
}   // namespace f3m_0086cdd0

// @f3 0x0086d0f0 (community match, verified in this file)
namespace f3m_0086d0f0 {
int __stdcall FUN_0086d0f0(int* p, int unused) { return p[-1]; }
}   // namespace f3m_0086d0f0

// @f3 0x0086ba50 (community match, verified in this file)
namespace f3m_0086ba50 {
struct H86ba50 { void* FUN_0086b930(unsigned int n); void* FUN_0086ba50(unsigned int a, int b, int c, int d); };
// pdb: MemoryManager::Allocate | MemoryManager.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: aSize, apFile, aiLine, apFunction
void* H86ba50::FUN_0086ba50(unsigned int a, int b, int c, int d) { return FUN_0086b930(a); }
}   // namespace f3m_0086ba50

// @f3 0x0086d3c0 (community match, verified in this file)
namespace f3m_0086d3c0 {
struct H86d3c0 { void FUN_0086e220(void* p); void FUN_0086d3c0(void* a, int b); };
void H86d3c0::FUN_0086d3c0(void* a, int b) { FUN_0086e220(a); }
}   // namespace f3m_0086d3c0

// @f3 0x0086b8b0 (community match, verified in this file)
namespace f3m_0086b8b0 {
void __cdecl FUN_00c064b8(int a);
// pdb: OriginalFree | MemoryManager.obj | tesv_win, objopen_prop, low
void __stdcall FUN_0086b8b0(int a, int b) { FUN_00c064b8(a); }
}   // namespace f3m_0086b8b0

// @f3 0x0086c3d0 (community match, verified in this file)
extern unsigned char DAT_01090bbc[];
namespace f3m_0086c3d0 {
// pdb: BSCoreMessage::DisableContextMessages | BSCoreMessage.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: BSCoreMessage::Error)
// pdb params: aWarningContext
void __stdcall FUN_0086c3d0(int index) { DAT_01090bbc[index] = 1; }
}   // namespace f3m_0086c3d0

// @f3 0x0086ce50 (community match, verified in this file)
namespace f3m_0086ce50 {
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitThread(unsigned int code);
void __cdecl FUN_0086ce50(unsigned int code) { ExitThread(code); }
}   // namespace f3m_0086ce50

// @f3 0x0086b8a0 (community match, verified in this file)
namespace f3m_0086b8a0 {
int __cdecl FUN_00c063f5(int a);
// pdb: BSMap<unsigned long,ScrapHeap *>::DeleteItem | MemoryManager.obj | fnv360_0721_beta, objrun_open, low
// pdb params: pkItem
int __stdcall FUN_0086b8a0(int a, int b) { return FUN_00c063f5(a); }
}   // namespace f3m_0086b8a0

// @f3 0x0086c5d0 (community match, verified in this file)
namespace f3m_0086c5d0 {
struct O86c5d0 { int unk0; int unk4; int unk8; int unkc; void FUN_0086c5d0(int a); };
// pdb: ScrapHeapManager::ScrapHeapManager | ScrapHeap.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: BSCoreMessage::GetWarningContextName)
void O86c5d0::FUN_0086c5d0(int a) { unk4 = unk0; unkc = 0; }
}   // namespace f3m_0086c5d0

// @f3 0x0086d5b0 (community match, verified in this file)
namespace f3m_0086d5b0 {
int __stdcall FUN_0086d5b0(int* p, int unused) { return p[-1] & 0xfffffff; }
}   // namespace f3m_0086d5b0

// @f3 0x0086e590 (community match, verified in this file)
namespace f3m_0086e590 {
struct O86e590 { int unk0; int unk4; void FUN_0086e590(int v, int u); };
// pdb: AbstractHeap::ShouldTrySmallBlockPools | AbstractHeap.obj | tesv_win, objrun_open, low
void O86e590::FUN_0086e590(int v, int u) { unk4 = v; unk0 = 0; }
}   // namespace f3m_0086e590

// @f3 0x0086cb70 (community match, verified in this file)
namespace f3m_0086cb70 {
struct O86cb70 { void FUN_0086cb00(int n); O86cb70* FUN_0086cb70(); };
O86cb70* O86cb70::FUN_0086cb70() { FUN_0086cb00(0x10000); return this; }
}   // namespace f3m_0086cb70

// @f3 0x0086d3d0 (community match, verified in this file)
namespace f3m_0086d3d0 {
void __stdcall FUN_0086e540(void* p);
void __stdcall FUN_0086d3d0(void* p, int unused) { if (p) FUN_0086e540(p); }
}   // namespace f3m_0086d3d0

// @f3 0x0086d610 (community match, verified in this file)
namespace f3m_0086d610 {
int __stdcall FUN_0086d610(int* p) { return (p[-1] & 0xfffffff) + 8; }
}   // namespace f3m_0086d610

// @f3 0x0086d100 (community match, verified in this file)
namespace f3m_0086d100 {
struct O86d100 { virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01c(); virtual void v020(); virtual int Get(int a, int b); int FUN_0086d100(int a); };
int O86d100::FUN_0086d100(int a) { return Get(a, 0) + 4; }
}   // namespace f3m_0086d100

// @f3 0x0086ce10 (community match, verified in this file)
namespace f3m_0086ce10 {
namespace f3m_0086ce10 { extern unsigned long (__stdcall* DAT_00d9b070)(); struct O { int unk0; unsigned long threadId; bool FUN_0086ce10(); }; bool O::FUN_0086ce10() { return DAT_00d9b070() == threadId; } }
}   // namespace f3m_0086ce10

// @f3 0x0086d9a0 (community match, verified in this file)
namespace n86d9a0 {
struct Heap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void* memory); };
extern Heap DAT_01090a78;
struct Pool { void FUN_0086d770(); };
extern Pool* DAT_01090fe0[129];
// pdb: MemoryPool::SortFreeBlockList | MemoryPool.obj | fnv360_0822_debug, objrun_open, low
void FUN_0086d9a0()
{
    for (unsigned int i = 0; i < 129; i++) {
        Pool* p = DAT_01090fe0[i];
        if (p) {
            p->FUN_0086d770();
            DAT_01090a78.FUN_0086ba60(p);
        }
    }
}
}

// @f3 0x0086d510 (community match, verified in this file)
namespace f3m_0086d510 {
// pdb: MemoryHeap::GetCalculatedMemoryUsed | MemoryHeap.obj | tesv_win, objrun_open, low
namespace f3m_0086d510 { extern int (__stdcall* DAT_00d9b150)(void* p, unsigned int size, unsigned int type); int __stdcall FUN_0086d510(void* p) { return DAT_00d9b150(p, 0, 0x8000); } }
}   // namespace f3m_0086d510

// @f3 0x0086ce30 (community match, verified in this file)
namespace f3m_0086ce30 {
// pdb: BSThread::SetThreadProcessor | BSThread_Xenon.obj | fnv360_0822_retail, call_dedup, low, conflict (bridge: BSThread::SetThreadPriority)
// pdb params: aiThread
namespace f3m_0086ce30 { extern int (__stdcall* DAT_00d9b164)(void* h, int a); struct O { char pad[0x1c]; void* h; void FUN_0086ce30(int a); }; void O::FUN_0086ce30(int a) { if (h) DAT_00d9b164(h, a); } }
}   // namespace f3m_0086ce30

// @f3 0x0086bb50 (community match, verified in this file)
#include <string.h>
namespace f3m_0086bb50 {
namespace n86bb50 {
extern "C" void* __cdecl FUN_00c06546(void* p, unsigned int size);
struct MemoryManager {
    unsigned int FUN_0086b8c0(void* p);
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
    void* FUN_0086bb50(void* p, unsigned int size, int a3, int a4, int a5);
};
void* MemoryManager::FUN_0086bb50(void* p, unsigned int size, int a3, int a4, int a5)
{
    void* result = 0;
    unsigned int old = FUN_0086b8c0(p);
    if (old) {
        result = FUN_0086b930(size);
        if (old > size)
            old = size;
        memcpy(result, p, old);
        FUN_0086ba60(p);
    } else {
        FUN_00c06546(p, size);
    }
    return result;
}
}
}   // namespace f3m_0086bb50

// @f3 0x0086bbc0 (community match, verified in this file)
namespace f3m_0086bbc0 {
namespace f3m_0086bbc0 { struct Heap { void FUN_0086ba60(void* p); }; extern Heap DAT_01090a78; }
class FUN_0086bbc0 { public: virtual ~FUN_0086bbc0(); int unk4; void* buf; };
FUN_0086bbc0::~FUN_0086bbc0() { if (buf) f3m_0086bbc0::DAT_01090a78.FUN_0086ba60(buf); }
}   // namespace f3m_0086bbc0

// @f3 0x0086c440 (community match, verified in this file)
namespace f3m_0086c440 {
struct O86c440 { int a0; int a4; char pad[0x9c0]; int a9c8; O86c440* FUN_0086c440(); };
// pdb: BSRandom::UnsignedInt | BGSDestructibleObjectForm.obj | fnv360_0822_debug, call_seq, low
O86c440* O86c440::FUN_0086c440() { a0 = 1; a4 = 0; a9c8 = 0x271; return this; }
}   // namespace f3m_0086c440

// @f3 0x00873b50 (community match, verified in this file)
namespace f3m_00873b50 {
// pdb: NiXenonRenderer::SetMipmapSkipLevel | NiXenonRenderer.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: NiAdditionalGeometryData::NiAGDDataBlock::AllocateBuffer)
// pdb params: uiSkip
namespace f3m_00873b50 { struct Heap { void* FUN_0086b930(unsigned int n); }; extern Heap DAT_01090a78; void* __stdcall FUN_00873b50(unsigned int n) { if (n) return DAT_01090a78.FUN_0086b930(n); return 0; } }
}   // namespace f3m_00873b50

// @f3 0x0086c4b0 (community match, verified in this file)
namespace f3m_0086c4b0 {
namespace batch14_01 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();extern unsigned DAT_00f754d4[2];
struct Generator {unsigned unk00,unk04;unsigned state[624];unsigned index;void FUN_0086c460(unsigned);unsigned FUN_0086c4b0(unsigned);};
// pdb: BSRandom::UnsignedInt | BSRandom.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: TESIdleForm::RemoveChildAtIndex)
// pdb params: aiMax
unsigned Generator::FUN_0086c4b0(unsigned maximum){if(!maximum)return 0;if(index>=624){if(index==625)FUN_0086c460(GetTickCount());unsigned k;for(k=0;k<227;++k){unsigned value=(state[k]&0x80000000)|(state[k+1]&0x7fffffff);state[k]=state[k+397]^(value>>1)^DAT_00f754d4[value&1];}for(;k<623;++k){unsigned value=(state[k]&0x80000000)|(state[k+1]&0x7fffffff);state[k]=state[k-227]^(value>>1)^DAT_00f754d4[value&1];}unsigned value=(state[623]&0x80000000)|(state[0]&0x7fffffff);state[623]=state[396]^(value>>1)^DAT_00f754d4[value&1];index=0;}unsigned result=state[index++];if(maximum==-1u||maximum==0x7fff)return result&maximum;return result%maximum;}
}
}   // namespace f3m_0086c4b0

// @f3 0x0086c5e0 (community match, verified in this file)
namespace f3m_0086c5e0 {
struct O86c5e0 { char pad[0x200]; int a200, a204; char pad2[0x18]; int a220, a224; O86c5e0* FUN_0086c5e0(); };
// pdb: ScrapHeapManager::ScrapHeapManager | ScrapHeap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: ScrapHeapManager::ShrinkBuffer)
O86c5e0* O86c5e0::FUN_0086c5e0() { a200 = 0; a204 = 0; a220 = 0; a224 = 0; return this; }
}   // namespace f3m_0086c5e0

// @f3 0x0086d670 (community match, verified in this file)
namespace f3m_0086d670 {
namespace f3m_0086d670 { extern int DAT_01090fe0[0x81]; extern int DAT_01090be0[0x100]; }
// pdb: `anonymous namespace'::SetupZeroReturns | MemoryManager.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_0086d670() { using namespace f3m_0086d670; for (int i = 0; i < 0x81; i++) DAT_01090fe0[i] = 0; for (int i = 0; i < 0x100; i++) DAT_01090be0[i] = 0; }
}   // namespace f3m_0086d670

// @f3 0x0086df00 (community match, verified in this file)
namespace f3m_0086df00 {
struct _RTL_CRITICAL_SECTION { char data[0x18]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
namespace n86df00 {
struct Block { int unk00, unk04, unk08; Block* next; };
struct Chunk { Chunk* next; };
struct Bin { Block* head; int unk04; };
struct Pool { int used; Block** list; };
struct Mgr {
    char pad00[0x3c];
    Chunk* chunks;
    int unk40;
    Bin bins[0x400];
    char pad2044[4];
    Block* large;
    char pad204c[0xc];
    Pool pools[16];
    _RTL_CRITICAL_SECTION cs;
    void FUN_0086df00();
};
void Mgr::FUN_0086df00()
{
    EnterCriticalSection(&cs);
    for (int i = 0; i < 16; i++) {
        if (pools[i].used) {
            for (Block* b = *pools[i].list; b; b = b->next) {
            }
        }
    }
    for (int i = 0; i < 0x400; i++) {
        for (Block* b = bins[i].head; b; b = b->next) {
        }
    }
    for (Block* b = large; b; b = b->next) {
    }
    for (Chunk* c = chunks; c; c = c->next) {
    }
    LeaveCriticalSection(&cs);
}
}
}   // namespace f3m_0086df00

// @f3 0x0086b870 (community match, verified in this file)
namespace f3m_0086b870 {
struct O86b870 { int unk0; unsigned int base; char pad[0x48]; unsigned int size; int FUN_0086b870(unsigned int p); };
int O86b870::FUN_0086b870(unsigned int p) { if (p >= base && p < base + size) return 1; return 0; }
}   // namespace f3m_0086b870

// @f3 0x0086cff0 (community match, verified in this file)
namespace f3m_0086cff0 {
struct O86cff0 { int unk0; unsigned int size; int unk8; unsigned int lo; int FUN_0086cff0(unsigned int p); };
int O86cff0::FUN_0086cff0(unsigned int p) { if (p > lo && p < lo + size) return 1; return 0; }
}   // namespace f3m_0086cff0

// @f3 0x0086c1f0 (community match, verified in this file)
namespace f3m_0086c1f0 {
struct O86c1f0 { unsigned char a0; char pad[3]; float a4, a8, ac; int a10, a14; unsigned char a18, a19; void FUN_0086c1f0(int p); };
// pdb: BSTimer::Init | BSTimer.obj | fnv360_0822_retail, call_gap, low
// pdb params: aiTime
void O86c1f0::FUN_0086c1f0(int p) { a4 = 0.0f; a8 = 0.0f; a0 = 0; ac = 0.0f; a10 = 0; a14 = p; a19 = 0; a18 = 0; }
}   // namespace f3m_0086c1f0

// @f3 0x0086cde0 (community match, verified in this file)
namespace f3m_0086cde0 {
namespace f3m_0086cde0 { extern long (__stdcall* DAT_00d9b06c)(long* p, long a, long b); }
struct O86cde0 { volatile long count; int a4; void FUN_0086cde0(); };
// pdb: BSReadWriteLock::UnlockWrite | BSReadWriteLock.obj | fnv360_0721_beta, call_seq, medium
void O86cde0::FUN_0086cde0() { count -= 1; if (count == 0x80000000) { long v = count; f3m_0086cde0::DAT_00d9b06c((long*)&count, 0, v); a4 = 0; } }
}   // namespace f3m_0086cde0

// @f3 0x0086c370 (community match, verified in this file)
namespace f3m_0086c370 {
namespace f3m_0086c370 { extern unsigned long (__stdcall* DAT_00d9b090)(); }
struct O86c370 { unsigned char cnt; char pad[0xf]; unsigned long a10, a14; void FUN_0086c370(); };
// pdb: BSTimer::Enable | BSTimer.obj | fnv360_0822_retail, caller, medium
void O86c370::FUN_0086c370() { if (cnt) { cnt = cnt - 1; if (cnt == 0) { unsigned long t = f3m_0086c370::DAT_00d9b090(); a10 = t - a10; a14 = t - a14; } } }
}   // namespace f3m_0086c370

// @f3 0x0086c3a0 (community match, verified in this file)
namespace f3m_0086c3a0 {
namespace f3m_0086c3a0 { extern unsigned long (__stdcall* DAT_00d9b090)(); }
struct O86c3a0 { unsigned char cnt; char pad[0xf]; unsigned long a10, a14; void FUN_0086c3a0(); };
// pdb: BSTimer::Disable | BSTimer.obj | fnv360_0822_retail, call_gap, medium
void O86c3a0::FUN_0086c3a0() { if (cnt++ == 0) { unsigned long t = f3m_0086c3a0::DAT_00d9b090(); a10 = t - a10; a14 = t - a14; } }
}   // namespace f3m_0086c3a0

// @f3 0x0086d090 (community match, verified in this file)
namespace f3m_0086d090 {
struct O86d090 { virtual void v0(); virtual void v1(); virtual int Read(int* out, int n); };
int __stdcall FUN_0086d090(O86d090* p) { if (!p) return 0; int v = 0; return p->Read(&v, 4); }
}   // namespace f3m_0086d090

// @f3 0x0086d0c0 (community match, verified in this file)
namespace f3m_0086d0c0 {
struct O86d0c0 { virtual void v0(); virtual void v1(); virtual int Read(int* out, int n); };
int __stdcall FUN_0086d0c0(O86d0c0* p, int unused) { if (!p) return 0; int v = 0; return p->Read(&v, 4); }
}   // namespace f3m_0086d0c0

// @f3 0x0086ce60 (community match, verified in this file)
namespace f3m_0086ce60 {
namespace f3m_0086ce60 { extern void (__stdcall* DAT_00d9b094)(void* p); }
class FUN_0086ce60 { public: virtual ~FUN_0086ce60(); char cs[0x18]; int a1c, a20, a24, a28; unsigned char b2c; FUN_0086ce60(); };
// pdb: BSThread::BSThread | BSThread_Xenon.obj | fnv360_0822_retail, call_gap, low
FUN_0086ce60::FUN_0086ce60() { f3m_0086ce60::DAT_00d9b094(cs); a1c = 0; a20 = 0; a24 = 0; a28 = 0; b2c = 0; }
}   // namespace f3m_0086ce60

// @f3 0x0086cbc0 (community match, verified in this file)
namespace f3m_0086cbc0 {
namespace f3m_0086cbc0 { struct Heap { void FUN_0086ba60(void* p); }; extern Heap DAT_01090a78; struct O { ~O(); static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); } }; extern O* DAT_01090bdc; }
// pdb: ScrapHeapManager::Shutdown | ScrapHeap.obj | fnv360_0822_retail, caller_sim, low
void __cdecl FUN_0086cbc0() { delete f3m_0086cbc0::DAT_01090bdc; f3m_0086cbc0::DAT_01090bdc = 0; }
}   // namespace f3m_0086cbc0

// @f3 0x008603e0 (community match, verified in this file)
namespace f3m_008603e0 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B008603e0 { virtual ~B008603e0(); virtual void v4(); int pad[5]; B008603e0() throw(); };
struct D008603e0 : B008603e0 { unsigned short value; virtual ~D008603e0(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D008603e0() throw(); };
D008603e0::D008603e0() throw() { value = 0; }
// pdb: NiSpecularProperty::CreateObject | NiSpecularProperty.obj | fnv360_1110_retail, objopen_prop, low
D008603e0* __cdecl FUN_008603e0() { return new D008603e0(); }
}   // namespace f3m_008603e0

// @f3 0x00864bb0 (community match, verified in this file)
namespace f3m_00864bb0 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B00864bb0 { virtual ~B00864bb0(); virtual void v4(); int pad[5]; B00864bb0() throw(); };
struct D00864bb0 : B00864bb0 { unsigned short value; virtual ~D00864bb0(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D00864bb0() throw(); };
D00864bb0::D00864bb0() throw() { value = 0; }
// pdb: NiDitherProperty::CreateObject | NiDitherProperty.obj | fnv360_0721_retail, objopen_prop, medium
D00864bb0* __cdecl FUN_00864bb0() { return new D00864bb0(); }
}   // namespace f3m_00864bb0

// @f3 0x0087f970 (community match, verified in this file)
namespace f3m_0087f970 {
namespace task0681 {
void* __cdecl FUN_00c00610(void*, int, unsigned int);
struct ByteVertexConversion {

    unsigned int format;

    unsigned short sourceType;

    unsigned short unk06;

    unsigned short count;

    unsigned short unk0A;

    const unsigned short* indices;

    const unsigned char* source;

    unsigned int unk14;

    unsigned int sourceStride;

    unsigned int destinationSize;

    unsigned int destinationStride;

    unsigned int unk24;

    unsigned int unk28;

    unsigned char* destination;

};
// @fnv 0x00e77770
// pdb: NiD3DShaderDeclaration::Pack_UnsignedByteToShort | NiXenonShaderDeclaration.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kParams
unsigned int __cdecl FUN_0087f970(ByteVertexConversion* info) {

    unsigned int written = 0;

    const unsigned char* source = info->source;

    const unsigned short* indices = info->indices;

    unsigned char* destination = info->destination;

    if (!source) {

        for (unsigned short i = 0; i < info->count; i++) {

            FUN_00c00610(destination, 0, info->destinationSize);

            destination += info->destinationStride;

            written += info->destinationSize;

        }

        return written;

    }

    unsigned short supplied = info->sourceType - 24;

    unsigned short components = info->format == 6 ? 2 : 4;

    unsigned short copied = supplied > components ? components : supplied;

    if (indices) {

        unsigned short index = 0;

        for (unsigned short i = 0; i < info->count; i++) {

            const unsigned char* input = source + indices[index++] * info->sourceStride;

            unsigned short* output = reinterpret_cast<unsigned short*>(destination);

            unsigned short j;

            for (j = 0; j < copied; j++) *output++ = *input++;

            for (; j < components; j++) *output++ = 0;

            destination += info->destinationStride;

            written += info->destinationSize;

        }

    } else {

        for (unsigned short i = 0; i < info->count; i++) {

            const unsigned char* input = source;

            unsigned short* output = reinterpret_cast<unsigned short*>(destination);

            unsigned short j;

            for (j = 0; j < copied; j++) *output++ = *input++;

            for (; j < components; j++) *output++ = 0;

            source += info->sourceStride;

            destination += info->destinationStride;

            written += info->destinationSize;

        }

    }

    return written;

}

}
}   // namespace f3m_0087f970

// @f3 0x0087f7a0 (community match, verified in this file)
namespace f3m_0087f7a0 {
struct FUN_0087f7a0_Info {
    int eType;
    unsigned short usComps;
    unsigned short unk06;
    unsigned short usVerts;
    unsigned short unk0a;
    unsigned short* pusRemap;
    signed char* pcSrc;
    unsigned int unk14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char* pucDest;
};

// @fnv 0x00e77590
// pdb: NiD3DShaderDeclaration::Pack_ByteToShort | NiXenonShaderDeclaration.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kParams
unsigned int FUN_0087f7a0(FUN_0087f7a0_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    signed char* pcSrc = pkInfo->pcSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!pcSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            FUN_00c00610(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
        return uiTotal;
    }

    unsigned short usSrcComps = pkInfo->usComps - 0x14;
    unsigned short usDestComps = (pkInfo->eType != 6) ? 4 : 2;
    unsigned short usCopy = (usSrcComps > usDestComps) ? usDestComps : usSrcComps;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            signed char* pcIn = pcSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride;
            short* psOut = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *psOut++ = *pcIn++;
            for (; j < usDestComps; j++)
                *psOut++ = 0;
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            signed char* pcIn = pcSrc;
            short* psOut = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *psOut++ = *pcIn++;
            for (; j < usDestComps; j++)
                *psOut++ = 0;
            pcSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
    }
    return uiTotal;
}
}   // namespace f3m_0087f7a0

// @f3 0x0087d880 (community match, verified in this file)
namespace f3m_0087d880 {
namespace task0679 {
void* __cdecl FUN_00c00610(void* dest, int value, unsigned int count);
struct NormalizedStream {
    unsigned short lastComponent, unk02;
    unsigned short type, unk06;
    unsigned short vertices, unk0a;
    unsigned short* indices;
    unsigned char* source;
    unsigned unk14, sourceStride, elementSize, destStride, unk24, unk28;
    unsigned char* dest;
};
// @fnv 0x00e79b40
// pdb: NiD3DShaderDeclaration::Pack_UnsignedByteToFloat | NiD3DShaderDeclaration.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
unsigned __cdecl NiD3DShaderDeclaration_Pack_UnsignedByteToFloat(NormalizedStream* pStream) {
    unsigned a = 0;
    unsigned char* src = pStream->source;
    unsigned short* indices = pStream->indices;
    unsigned char* dst = pStream->dest;
    if (!src) {
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            FUN_00c00610(dst, 0, pStream->elementSize);
            dst += pStream->destStride;
            a += pStream->elementSize;
        }
        return a;
    }
    unsigned short srcComponents = pStream->type - 24;
    unsigned short components = pStream->lastComponent + 1;
    unsigned short b = srcComponents > components ? components : srcComponents;
    if (indices) {
        unsigned short remapIndex = 0;
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            unsigned char* in = src + indices[remapIndex++] * pStream->sourceStride;
            float* out = (float*)dst;
            unsigned short j = 0;
            for (; j < b; ++j) *out++ = *in++ / 255.0;
            for (; j < components; ++j) *out++ = 0.0f;
            dst += pStream->destStride;
            a += pStream->elementSize;
        }
    } else {
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            unsigned char* in = src;
            float* out = (float*)dst;
            unsigned short j = 0;
            for (; j < b; ++j) *out++ = *in++ / 255.0;
            for (; j < components; ++j) *out++ = 0.0f;
            src += pStream->sourceStride;
            dst += pStream->destStride;
            a += pStream->elementSize;
        }
    }
    return a;
}

}
}   // namespace f3m_0087d880

// @f3 0x0086c9a0 (community match, verified in this file)
extern const char DAT_00e27efc[];
namespace f3m_0086c9a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
struct Lock86c9a0 {
    volatile long owner;
    long count;
    void FUN_00409a80(const char* name);
    void Unlock() { if (--count == 0) { long o = owner; InterlockedCompareExchange(&owner, 0, o); } }
};
struct Entry86c9a0 { void* ptr; unsigned int size; };
struct Pool86c9a0 {
    Entry86c9a0 entries[0x40];
    unsigned int count;
    unsigned int total;
    char pad208[0x18];
    Lock86c9a0 lock;
    void FUN_0086c9a0(void* p, unsigned int size);
};
// pdb: ScrapHeapManager::ReleaseBuffer | ScrapHeap.obj | fnv360_0822_retail, ustr, medium
// pdb params: apBuffer, aiCommittedSize
void Pool86c9a0::FUN_0086c9a0(void* p, unsigned int size)
{
    if (count >= 0x40)
        VirtualFree(p, 0, 0x8000);
    lock.FUN_00409a80(DAT_00e27efc);
    if (count >= 0x40) {
        VirtualFree(p, 0, 0x8000);
    } else {
        entries[count].ptr = p;
        entries[count].size = size;
        ++count;
        total += size;
    }
    lock.Unlock();
}
}   // namespace f3m_0086c9a0

// @f3 0x00866240 (community match, verified in this file)
extern unsigned int DAT_01090998[9];
extern unsigned short DAT_01090984[9];
extern bool DAT_01090a09;
namespace f3m_00866240 {
namespace pool_tables_1615 {
void __cdecl FUN_00866240() {
    DAT_01090998[0]=0; DAT_01090998[1]=1; DAT_01090998[2]=2;
    DAT_01090998[3]=3; DAT_01090998[4]=4; DAT_01090998[5]=5;
    DAT_01090998[6]=6; DAT_01090998[7]=7; DAT_01090998[8]=8;
    DAT_01090984[0]=0; DAT_01090984[1]=0x100; DAT_01090984[2]=0x200;
    DAT_01090984[3]=0x300; DAT_01090984[4]=0x400; DAT_01090984[5]=0x500;
    DAT_01090984[6]=0x600; DAT_01090984[7]=0x700; DAT_01090984[8]=0x800;
    DAT_01090a09=true;
}
}
}   // namespace f3m_00866240

// @f3 0x00860800 (community match, verified in this file)
namespace f3m_00860800 {
void* __cdecl FUN_0089eb90(unsigned int n) throw();
struct B860800 { virtual ~B860800(); virtual void v4(); int pad[5]; B860800() throw(); };
struct D860800 : B860800 { unsigned short w18; char pad2[2]; int a1c; virtual ~D860800(); static void* operator new(unsigned int n) throw() { return FUN_0089eb90(n); } D860800() throw(); };
D860800::D860800() throw() { a1c = -1; w18 = 1; }
// pdb: NiShadeProperty::CreateObject | NiShadeProperty.obj | fnv360_0822_retail, objopen_prop, low
D860800* __cdecl FUN_00860800() { return new D860800(); }
}   // namespace f3m_00860800

// @f3 0x0086cf00 (community match, verified in this file)
namespace f3m_0086cf00 {
extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* handle;
    int unk20;
    int unk24;
    int unk28;
    unsigned char active;
    void BSThread_Close();
};
// pdb: BSThread::Close | BSThread_Xenon.obj | fnv360_0822_retail, objrun + bridge(call_gap|objopen_prop), high
void Owner::BSThread_Close() {
    if (handle) {
        active = 0;
        fnv_EnterCriticalSection(&unk04);
        CloseHandle(handle);
        handle = 0;
        LeaveCriticalSection(&unk04);
    }
}
}   // namespace f3m_0086cf00

// @f3 0x00866530 (community match, verified in this file)
namespace f3m_00866530 {
namespace format_1616 {
// pdb: NiShaderConstantMap::LookUpObjectMappingType | NiShaderConstantMap.obj | fnv360_0822_retail, call_seq, medium
// pdb params: uiMappingID, uiRegCount, uiFloatCount
unsigned int __cdecl FUN_00866530(unsigned int format,unsigned int* components,unsigned int* bytes) {
    *components=1;
    *bytes=4;
    switch(format) {
    case 1: case 22: *bytes=1; return 4;
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 14: case 15: case 18: case 19: case 20: case 21: return 7;
    case 12: case 13: case 23: case 24: *components=4; *bytes=16; return 9;
    case 16: case 17: *components=3; *bytes=12; return 8;
    default: return 0;
    }
}
}
}   // namespace f3m_00866530

// @f3 0x0086db90 (community match, verified in this file)
namespace f3m_0086db90 {
namespace pool_unlink_1618 {
struct FreeBlock {
    unsigned int unk00;
    unsigned int sizeFlags;
    FreeBlock* previous;
    FreeBlock* next;
};
struct FreeBin { FreeBlock* head; FreeBlock* tail; };
struct BinGroup { int count; unsigned int unk04; };
struct MemoryPool {
    unsigned int unk00,unk04;
    int unitSize;
    unsigned int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int freeCount;
    FreeBin bins[1024];
    unsigned int unk2044;
    FreeBin largeBin;
    unsigned int unk2050,unk2054;
    BinGroup groups[16];
    void FUN_0086db90(FreeBin*,FreeBlock*);
    void FUN_0086daf0(FreeBlock*);
};

// pdb: VirtualAlloc | virtualallocate.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: AbstractHeap::RemoveBlockFromFreeList)
// pdb params: lpAddress, dwSize, flAllocationType, flProtect
void MemoryPool::FUN_0086db90(FreeBin* bin,FreeBlock* block) {
    FreeBlock* next=block->next;
    FreeBlock* previous=block->previous;
    if(previous) previous->next=block->next;
    if(block->next) block->next->previous=block->previous;
    block->sizeFlags&=0xbfffffffu;
    block->next=0;
    block->previous=0;
    if(block==bin->head) bin->head=next;
    if(block==bin->tail) bin->tail=previous;
    int size=block->sizeFlags&0x0fffffffu;
    if(size<=0x1000) {
        int group=(size/unitSize-1)/64;
        if(group!=-1) --groups[group].count;
    }
    --freeCount;
}
}

}   // namespace f3m_0086db90

// @f3 0x0086daf0 (community match, verified in this file)
namespace f3m_0086daf0 {
namespace pool_link_1619 {
struct FreeBlock {
    unsigned int unk00;
    unsigned int sizeFlags;
    FreeBlock* previous;
    FreeBlock* next;
};
struct FreeBin { FreeBlock* head; FreeBlock* tail; };
struct BinGroup { int count; unsigned int unk04; };
struct MemoryPool {
    unsigned int unk00,unk04;
    int unitSize;
    unsigned int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    int freeCount;
    FreeBin bins[1024];
    unsigned int unk2044;
    FreeBin largeBin;
    unsigned int unk2050,unk2054;
    BinGroup groups[16];
    void FUN_0086db90(FreeBin*,FreeBlock*);
    void FUN_0086daf0(FreeBlock*);
};

void MemoryPool::FUN_0086daf0(FreeBlock* block) {
    block->sizeFlags|=0x40000000u;
    unsigned int size=block->sizeFlags&0x0fffffffu;
    block->next=0;
    block->previous=0;
    FreeBin* bin=&largeBin;
    int index=size/static_cast<unsigned int>(unitSize)-1;
    if(index<1024) bin=&bins[index];
    FreeBlock* tail=bin->tail;
    if(tail) {
        block->previous=tail;
        FreeBlock* next=tail->next;
        block->next=next;
        if(next) next->previous=block;
        tail->next=block;
    } else bin->head=block;
    bin->tail=block;
    ++freeCount;
    int actualSize=block->sizeFlags&0x0fffffffu;
    if(actualSize<=0x1000) {
        int group=(actualSize/unitSize-1)/64;
        if(group!=-1) ++groups[group].count;
    }
}
}


}   // namespace f3m_0086daf0

// @f3 0x00865cb0 (community match, verified in this file)
extern const char* DAT_01090974;
namespace f3m_00865cb0 {
namespace register_name_00865cb0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0083c5c0(NameArray*);
    void FUN_00865cb0(NameArray*);
};
// pdb: NiAmbientLight::GetViewerStrings | NiAmbientLight.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pStrings
void Object::FUN_00865cb0(NameArray* names) {
    FUN_0083c5c0(names);
    void* value=FUN_00847b50(DAT_01090974);
    names->Append(value);
}
}

}   // namespace f3m_00865cb0

// @f3 0x00863040 (community match, verified in this file)
extern const char* DAT_01090900;
namespace f3m_00863040 {
namespace register_name_00863040 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct Object {
    void FUN_0085b3a0(NameArray*);
    void FUN_00863040(NameArray*);
};
// pdb: NiParticleMeshesData::GetViewerStrings | NiParticleMeshesData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void Object::FUN_00863040(NameArray* names) {
    FUN_0085b3a0(names);
    void* value=FUN_00847b50(DAT_01090900);
    names->Append(value);
}
}

}   // namespace f3m_00863040

// @f3 0x00864ef0 (community match, verified in this file)
extern const char* DAT_01090950;
extern const char DAT_00e26958[];
namespace f3m_00864ef0 {
namespace extended_00864ef0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
struct String { char* data; unsigned short length,capacity; void* FUN_0083f9c0(const char*); };
struct Object {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    String value;
    void FUN_00845ca0(NameArray*);
    void FUN_00864ef0(NameArray*);
};
// pdb: NiColorExtraData::GetViewerStrings | NiColorExtraData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pStrings
void Object::FUN_00864ef0(NameArray* names) {
    FUN_00845ca0(names);
    void* handle=FUN_00847b50(DAT_01090950);
    names->Append(handle);
    handle=value.FUN_0083f9c0(DAT_00e26958);
    names->Append(handle);
}
}
}   // namespace f3m_00864ef0

// @f3 0x0086df90 (community match, verified in this file)
namespace f3m_0086df90 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
namespace Task0715 {
class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapStatsX
{
  public:
    const char* pName;
    unsigned int iMemHeapSize;
    unsigned int m_uiCurrentCommitSize;
    int m_iUsedSize;
    unsigned int m_iFreeBlockCount;
    unsigned int m_uiFreeBlockCount;
    int iFreeSize;
    int iUsedSize;
    int iMinFreeBlock;
    int iMaxFreeBlock;
    unsigned int iHeapStructSize;
    unsigned int iFreeListBytes;
    int iBlockTableBytes;
    int iUnusedBytes;
    unsigned int m_uiTrailingStatsValue;
};

struct HeapFreeList { void* head; void* tail; };
struct HeapBlockList { HeapFreeList* first; unsigned int count; };
struct AbstractHeapX {
 int unk00;
 const char* pName;
 int alignment;
 unsigned int headerSize,growthEnabled,m_uiMaximumHeapSize,minCommit,m_uiCurrentCommitSize,initialCommit;
 int m_iUsedSize,allocationCount,m_iAllocatedBlockSize;
 void* heapBase;
 unsigned int m_iFreeBlockCount;
 MemoryBlockHeader* m_pFirstBlock;
 MemoryBlockHeader* m_pLastBlock;
 unsigned int m_uiFreeBlockCount;
 HeapFreeList freeLists[1024];
 HeapFreeList* current;
 HeapFreeList sentinel;
 MemoryBlockHeader** blocks;
 unsigned int blockCount;
 HeapBlockList subBuckets[16];
 struct CriticalSection { void* debugInfo; long lockCount, recursionCount; void* owningThread; void* semaphore; unsigned long spinCount; } cs;
 void FUN_0086df90(HeapStatsX*,bool);
};
// @fnv 0x00aaa0e0
void AbstractHeapX::FUN_0086df90(HeapStatsX* stats, bool full)
{
    EnterCriticalSection(&this->cs);
    stats->pName = this->pName;
    stats->iMemHeapSize = this->m_uiMaximumHeapSize;
    stats->m_uiCurrentCommitSize = this->m_uiCurrentCommitSize;
    stats->m_iUsedSize = this->m_iUsedSize;
    stats->m_iFreeBlockCount = this->m_iFreeBlockCount;
    stats->m_uiFreeBlockCount = this->m_uiFreeBlockCount;
    int iZero4 = 0;
    int iBlockBytes2 = stats->m_iFreeBlockCount * iZero4;
    int iHeaderSize3 = sizeof(MemoryBlockHeader) - iZero4;
    stats->iHeapStructSize = sizeof(AbstractHeapX);
    stats->iFreeListBytes = 0x2000;
    stats->iFreeListBytes += 0x80;
    stats->iBlockTableBytes = this->m_iFreeBlockCount * iHeaderSize3;
    stats->iUnusedBytes = iBlockBytes2;
    MemoryBlockHeader* aBlock = this->m_pFirstBlock;
    stats->iFreeSize = this->m_iUsedSize - this->m_iAllocatedBlockSize;
    stats->iUsedSize = this->m_iAllocatedBlockSize;
    stats->iMinFreeBlock = 0xfffffff;
    stats->iMaxFreeBlock = 0;
    if (full)
    {
        stats->iFreeSize = 0;
        stats->iUsedSize = 0;
        while (aBlock)
        {
            if (aBlock->IsFree())
            {
                int freeSize = aBlock->GetSize();
                stats->iFreeSize += freeSize + iHeaderSize3;
                if (freeSize < stats->iMinFreeBlock)
                    stats->iMinFreeBlock = freeSize;
                if (freeSize > stats->iMaxFreeBlock)
                    stats->iMaxFreeBlock = freeSize;
            }
            else
            {
                int usedSize_ = aBlock->GetSize();
                stats->iUsedSize += usedSize_ + iHeaderSize3;
            }
            aBlock = (aBlock == this->m_pLastBlock) ? 0 : aBlock->GetNext();
        }
        if (stats->m_uiFreeBlockCount == 0)
            stats->iMinFreeBlock = 0;
    }
    stats->m_uiTrailingStatsValue = stats->iMemHeapSize - stats->m_iUsedSize + stats->iFreeSize;
    LeaveCriticalSection(&this->cs);
}

}
}   // namespace f3m_0086df90

// @f3 0x0086c600 (community match, verified in this file)
namespace f3m_0086c600 {
namespace f3m_0086c600 { struct Heap { void* FUN_0086b930(unsigned int n); }; extern Heap DAT_01090a78; struct O { char pad[0x200]; int a200, a204; char pad2[0x18]; int a220, a224; char pad3[0x18]; static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); } O() { a200 = 0; a204 = 0; a220 = 0; a224 = 0; } }; extern O* DAT_01090bdc; }
// pdb: ScrapHeapManager::Init | ScrapHeap.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_0086c600() { f3m_0086c600::DAT_01090bdc = new f3m_0086c600::O(); }
}   // namespace f3m_0086c600

// @f3 0x0086e150 (community match, verified in this file)
namespace f3m_0086e150 {
namespace task0719 {
class MemoryHeapType;
struct CriticalSection { void* debugInfo; long lockCount, recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; };
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};

struct HeapFreeList { MemoryBlockHeader* head; MemoryBlockHeader* tail; };
struct HeapBlockList { int count; HeapFreeList* first; };
class IMemoryManagerFile { public: virtual void v0(); virtual void v4(); virtual int Write(const void*,unsigned int); };
struct HeapBlockInfo { int iType; unsigned int iSize; int bFree; int unk0C; int unk10; int iOwner; };
struct AbstractHeapBlockInfo { void* vtable;
    const char* pName;
    int m_iBlockAlignment;
    unsigned int m_uiBlockHeaderSize;
    unsigned int m_uiHeapGrowthEnabled;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiMinimumCommitSize;
    unsigned int m_uiCurrentCommitSize;
    unsigned int m_uiInitialCommitSize;
    int m_iUsedSize;
    int m_iAllocationCount;
    int m_iAllocatedBlockSize;
    char* m_pHeapBase;
    int m_iFreeBlockCount;
    MemoryBlockHeader* m_pFirstBlock;
    MemoryBlockHeader* m_pLastBlock;

    int m_uiFreeBlockCount;
    HeapFreeList m_kFreeLists[1024];
    HeapFreeList* m_pCurrentFreeList;
    HeapFreeList m_kFreeListSentinel;
    MemoryBlockHeader** m_ppHeapBlocks;
    unsigned int m_uiBlockCount;
    HeapBlockList m_kSubBucketLists[16];
    // Win32 critical-section storage; lock imports receive its address.
    CriticalSection m_kCriticalSection;

 int FUN_0086e150(IMemoryManagerFile*,bool); };
// @fnv 0x00aaa430
// pdb: AbstractHeap::BaseFree | AbstractHeap.obj | tesv_win, objopen_prop, low
int AbstractHeapBlockInfo::FUN_0086e150(IMemoryManagerFile* file, bool full)
{
    if (!file)
        return 0;
    DAT_00d9b09c(&m_kCriticalSection);
    int total2 = 0;
    if (full)
    {
        total2 += file->Write(&m_iFreeBlockCount, 4);
        int i;
        HeapBlockInfo info2;
        info2.iType = 8;
        MemoryBlockHeader* block7 = m_pFirstBlock;
        for (i = 0; i < m_iFreeBlockCount; block7 = block7->GetNext(), i++)
        {
            info2.iSize = block7->GetSize();
            info2.bFree = block7->IsFree() != 0;
            info2.iOwner = -1;
            total2 += file->Write(&info2, sizeof(info2));
        }
    }
    else
    {
        int zero4 = 0;
        total2 += file->Write(&zero4, 4);
    }
    DAT_00d9b0a0(&m_kCriticalSection);
    return total2;
}

}

}   // namespace f3m_0086e150

// @f3 0x008656a0 (community match, verified in this file)
namespace task0724 {
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610* DAT_01090958;
struct StrArr
{
    unsigned int m_usSize;
    unsigned int m_usMaxSize;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int, char*&);
};
struct FUN_00c51570_Class
{
    void* FUN_0082ee90(void*);
};
struct FUN_00833040_Owner
{
    char* FUN_00833040(const char*);
};
char* __cdecl FUN_00847b50(GlobalObjectO2_00a7b610*);

struct FUN_00a9acf0_shell
{
    void FUN_008656a0(StrArr* apViewerStrings);
};

// @fnv 0x00a9acf0
// pdb: NiBSPNode::GetViewerStrings | NiBSPNode.obj | fnv360_0822_retail, ustr, medium
// pdb params: pStrings
void FUN_00a9acf0_shell::FUN_008656a0(StrArr* apViewerStrings)
{
    ((FUN_00c51570_Class*)this)->FUN_0082ee90(apViewerStrings);
    char* pName = FUN_00847b50(DAT_01090958);
    unsigned int uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->FUN_00555790(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->FUN_005b3880(uiIndex, pName);
    pName = ((FUN_00833040_Owner*)((char*)this + 0xac))->FUN_00833040("m_kModelPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->FUN_00555790(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->FUN_005b3880(uiIndex, pName);
    pName = ((FUN_00833040_Owner*)((char*)this + 0xbc))->FUN_00833040("m_kWorldPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->FUN_00555790(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->FUN_005b3880(uiIndex, pName);
}

}

// @f3 0x0086ddc0 (community match, verified in this file)
namespace f3m_0086ddc0 {
namespace task0725 {
class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
    __forceinline void SetNextFree(HeapFreeBlock* block)
    {
        m_pNextFree = block;
    }
    __forceinline void SetPrevFree(HeapFreeBlock* block)
    {
        m_pPrevFree = block;
    }
    void RemoveFromFreeList();
};

class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
    __forceinline void AddBlock(HeapFreeBlock* block)
    {
        if (pTail)
        {
            HeapFreeBlock* tail = pTail;
            block->m_pNextFree = tail;
            HeapFreeBlock* previous = tail->m_pPrevFree;
            block->m_pPrevFree = previous;
            if (previous)
                previous->m_pNextFree = block;
            tail->m_pPrevFree = block;
            pTail = block;
        }
        else
        {
            pHead = block;
            pTail = block;
        }
    }
};
class HeapBlockList
{
  public:
    int iCount;
    HeapFreeList* pFirst;
};

class AbstractHeap { public:
virtual void v00();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual unsigned int CleanExtraPages(void*,unsigned int,unsigned int);
    const char* pName;
    int m_iBlockAlignment;
    unsigned int m_uiBlockHeaderSize;
    unsigned int m_uiHeapGrowthEnabled;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiMinimumCommitSize;
    unsigned int m_uiCurrentCommitSize;
    unsigned int m_uiInitialCommitSize;
    int m_iUsedSize;
    int m_iAllocationCount;
    int m_iAllocatedBlockSize;
    char* m_pHeapBase;
    int m_iFreeBlockCount;
    MemoryBlockHeader* m_pFirstBlock;
    MemoryBlockHeader* m_pLastBlock;

    int m_uiFreeBlockCount;
    HeapFreeList m_kFreeLists[1024];
    HeapFreeList* m_pCurrentFreeList;
    HeapFreeList m_kFreeListSentinel;
    MemoryBlockHeader** m_ppHeapBlocks;
    unsigned int m_uiBlockCount;
    HeapBlockList m_kSubBucketLists[16];
    // Win32 critical-section storage; lock imports receive its address.
    struct CriticalSection { void* debugInfo; long lockCount, recursionCount; void* owningThread; void* semaphore; unsigned long spinCount; } m_kCriticalSection;

    __forceinline HeapFreeList* GetFreeList(unsigned int size)
    {
        int bucket = size / m_iBlockAlignment - 1;
        return bucket >= 1024 ? &m_kFreeListSentinel : &m_kFreeLists[bucket];
    }

void FUN_0086db90(HeapFreeList*,HeapFreeBlock*);
void RemoveBlockFromFreeList(HeapFreeBlock* b) { FUN_0086db90(GetFreeList(b->GetSize()),b); }
void FUN_0086ddc0();
};
// @fnv 0x00aa9a70
void AbstractHeap::FUN_0086ddc0()
{
    MemoryBlockHeader* block = m_pLastBlock;
    while (block && block->IsFree() && block->GetNext() == (MemoryBlockHeader*)(m_pHeapBase + m_iUsedSize))
    {
        RemoveBlockFromFreeList((HeapFreeBlock*)block);
        m_iUsedSize -= block->GetTotalSize();
        --m_iFreeBlockCount;
        if (m_pFirstBlock == m_pLastBlock)
        {
            m_pLastBlock = 0;
            m_pFirstBlock = 0;
            break;
        }
        else
        {
            m_pLastBlock = block->GetPrevious();
        }
        block = m_pLastBlock;
    }
    if (m_uiHeapGrowthEnabled)
    {
        unsigned int unused = m_uiCurrentCommitSize - m_iUsedSize;
        if (m_uiCurrentCommitSize - unused < m_uiMinimumCommitSize)
            unused = m_uiCurrentCommitSize - m_uiMinimumCommitSize;
        if (unused >= m_uiHeapGrowthEnabled)
            m_uiCurrentCommitSize -= CleanExtraPages(m_pHeapBase, m_uiCurrentCommitSize, unused);
    }
}

}
}   // namespace f3m_0086ddc0

// @f3 0x0086dcf0 (community match, verified in this file)
namespace f3m_0086dcf0 {
namespace Task0723 {
class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
    __forceinline void SetNextFree(HeapFreeBlock* block)
    {
        m_pNextFree = block;
    }
    __forceinline void SetPrevFree(HeapFreeBlock* block)
    {
        m_pPrevFree = block;
    }
    void RemoveFromFreeList();
};

class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
    __forceinline void AddBlock(HeapFreeBlock* block)
    {
        if (pTail)
        {
            HeapFreeBlock* tail = pTail;
            block->m_pNextFree = tail;
            HeapFreeBlock* previous = tail->m_pPrevFree;
            block->m_pPrevFree = previous;
            if (previous)
                previous->m_pNextFree = block;
            tail->m_pPrevFree = block;
            pTail = block;
        }
        else
        {
            pHead = block;
            pTail = block;
        }
    }
};
class HeapBlockList
{
  public:
    int iCount;
    HeapFreeList* pFirst;
};
struct AbstractHeap {
 int unk00;
 const char* pName;
 int m_iBlockAlignment;
 unsigned int headerSize,growth,maxSize,minCommit,commit,initialCommit;
 int used,allocations,allocated;
 void* heapBase;
 int m_iFreeBlockCount;
 MemoryBlockHeader* m_pFirstBlock;
 MemoryBlockHeader* m_pLastBlock;
 int m_uiFreeBlockCount;
 HeapFreeList m_kFreeLists[1024];
 HeapFreeList* m_pCurrentFreeList;
 HeapFreeList m_kFreeListSentinel;
 MemoryBlockHeader** blocks;
 unsigned int blockCount;
 HeapBlockList m_kSubBucketLists[16];
 __forceinline HeapFreeList* GetFreeList(unsigned int size) { int bucket = size / m_iBlockAlignment - 1; return bucket >= 1024 ? &m_kFreeListSentinel : &m_kFreeLists[bucket]; }
 __forceinline int GetSubBucket(int size) { if(size > 4096) return -1; return (size / m_iBlockAlignment - 1) / 64; }
 void RemoveBlockFromFreeList(HeapFreeBlock*);
 void FUN_0086daf0(HeapFreeBlock*);
 void FUN_0086db90(HeapFreeList*,HeapFreeBlock*);
 void IncrementSubBucket(int);
 void DecrementSubBucket(int);
 void FUN_0086dcf0(HeapFreeBlock*,HeapFreeBlock*);
};
inline void AbstractHeap::RemoveBlockFromFreeList(HeapFreeBlock* block)
{
    FUN_0086db90(GetFreeList(block->GetSize()), block);
}

// Clears the block's fields, marks it free, adds it to the free list for its size, and updates the free-block and sub-bucket counters.
// @fnv 0x00aa9d30
void AbstractHeap::FUN_0086daf0(HeapFreeBlock* block)
{
    block->m_pPrevFree = 0;
    block->m_pNextFree = 0;
    block->SetFree(true);
    HeapFreeList* list = GetFreeList(block->GetSize());
    list->AddBlock(block);
    ++m_uiFreeBlockCount;
    IncrementSubBucket(block->GetSize());
}
// @fnv 0x00aa9e50
void AbstractHeap::FUN_0086db90(HeapFreeList* apFreeList, HeapFreeBlock* block)
{
    HeapFreeBlock* pPrev = block->m_pPrevFree;
    HeapFreeBlock* pNext = block->m_pNextFree;
    block->RemoveFromFreeList();
    block->SetFree(false);
    if (block == apFreeList->pHead)
        apFreeList->pHead = pPrev;
    if (block == apFreeList->pTail)
        apFreeList->pTail = pNext;
    DecrementSubBucket(block->GetSize());
    --m_uiFreeBlockCount;
}
// Unlinks this node from the free list by patching its neighbours' free-list links, then clears the previous and next free pointers.
// @fnv 0x00aaa5e0
inline void HeapFreeBlock::RemoveFromFreeList()
{
    if (m_pNextFree)
        m_pNextFree->SetPrevFree(m_pPrevFree);
    if (m_pPrevFree)
        m_pPrevFree->SetNextFree(m_pNextFree);
    m_pPrevFree = 0;
    m_pNextFree = 0;
}
// Computes the sub-bucket index for size and, if valid, increments that bucket's iCount.
// @fnv 0x00aa9ef0
void AbstractHeap::IncrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        ++m_kSubBucketLists[bucket].iCount;
}
// Looks up the sub-bucket for size and decrements its iCount if a bucket was found.
// @fnv 0x00aa9f50
void AbstractHeap::DecrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        --m_kSubBucketLists[bucket].iCount;
}
// @fnv 0x00aa9970
void AbstractHeap::FUN_0086dcf0(HeapFreeBlock* pFirstBlock, HeapFreeBlock* pSecondBlock)
{
    RemoveBlockFromFreeList(pFirstBlock);
    RemoveBlockFromFreeList(pSecondBlock);
    if (pSecondBlock->IsDecommitted())
        pFirstBlock->SetDecommitted(true);
    pFirstBlock->SetSize(pFirstBlock->GetSize() + pSecondBlock->GetTotalSize());
    if (pSecondBlock == m_pLastBlock)
        m_pLastBlock = pFirstBlock;
    else
        pSecondBlock->GetNext()->SetPrevious(pFirstBlock);
    --m_iFreeBlockCount;
    FUN_0086daf0(pFirstBlock);
}

}
}   // namespace f3m_0086dcf0

// @f3 0x00864ab0 (community match, verified in this file)
extern const char* DAT_0109093c;
extern const char DAT_00e26808[];
namespace f3m_00864ab0 {
namespace viewer_00864ab0 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847dd0(const char*,float);
struct Object {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float value;
    void FUN_00845ca0(NameArray*);
    void FUN_00864ab0(NameArray*);
};
// pdb: NiFloatExtraData::GetViewerStrings | NiFloatExtraData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pStrings
void Object::FUN_00864ab0(NameArray* names) {
    FUN_00845ca0(names);
    void* handle=FUN_00847b50(DAT_0109093c);
    names->Append(handle);
    handle=FUN_00847dd0(DAT_00e26808,value);
    names->Append(handle);
}
}
}   // namespace f3m_00864ab0

// @f3 0x00865b30 (community match, verified in this file)
extern const char* DAT_01090968;
extern const char DAT_00e26bc0[];
namespace f3m_00865b30 {
namespace viewer_00865b30 {
struct NameArray {
    void* vtable;
    void** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short liveCount;
    unsigned short growBy;
    void FUN_00555790(unsigned int);
    void FUN_005b3880(unsigned int,void* const&);
    __forceinline void Append(void* const& value) {
        unsigned int index=count;
        if(index>=capacity) FUN_00555790(index+growBy);
        FUN_005b3880(index,value);
    }
};
void* FUN_00847b50(const char*);
void* FUN_00847b90(const char*,bool);
struct Object {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char enabled:1;
    unsigned char unknownFlags:7;
    void FUN_00825cd0(NameArray*);
    void FUN_00865b30(NameArray*);
};
// pdb: NiCullingProperty::GetViewerStrings | NiCullingProperty.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void Object::FUN_00865b30(NameArray* names) {
    FUN_00825cd0(names);
    names->Append(FUN_00847b50(DAT_01090968));
    bool value=enabled;
    names->Append(FUN_00847b90(DAT_00e26bc0,value));
}
}
}   // namespace f3m_00865b30

// @f3 0x0086cf40 (community match, verified in this file)
namespace f3m_0086cf40 {
namespace f3m_0086cf40 { extern void (__stdcall* DAT_00d9b09c)(void* cs); extern void (__stdcall* DAT_00d9b0a4)(void* h); extern void (__stdcall* DAT_00d9b0a0)(void* cs); extern void (__stdcall* DAT_00d9b098)(void* cs); extern char DAT_00e27f48; }
struct O86cf40 { void* vt; char cs[0x18]; void* h; int a20, a24, a28; unsigned char b2c; void FUN_0086cf40(); };
// pdb: LoadingMenuThread::~LoadingMenuThread | LoadingMenu.obj | fnv360_0822_debug, call_seq, low
void O86cf40::FUN_0086cf40() { using namespace f3m_0086cf40; vt = &DAT_00e27f48; if (h) { b2c = 0; DAT_00d9b09c(cs); DAT_00d9b0a4(h); h = 0; DAT_00d9b0a0(cs); } DAT_00d9b098(cs); }
}   // namespace f3m_0086cf40

// @f3 0x0086dc60 (community match, verified in this file)
namespace f3m_0086dc60 {
namespace Task0780 {
struct HeapFreeBlock;
struct HeapFreeList { void* m0; HeapFreeBlock* m4; };
struct AbstractHeap {
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
 virtual void v13(void*);
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int m14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 void* m30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 HeapFreeList m_lists[1024];
 int unk2044;
 HeapFreeBlock* m2048;
 HeapFreeBlock* m204c;
 void FUN_0086db90(HeapFreeList*,HeapFreeBlock*);
 void FUN_0086dc60();
};
// @fnv 0x00aa8ea0
// pdb: AbstractHeap::DeleteHeap | AbstractHeap.obj | tesv_win, objrun_open, low
void AbstractHeap::FUN_0086dc60()
{
    for (int i = 0; i < 0x400; ++i)
    {
        HeapFreeList* list = &m_lists[i];

        while (list->m4 != 0)
        {
            this->FUN_0086db90(list, list->m4);
        }
    }

    while (m204c != 0)
    {
        this->FUN_0086db90(reinterpret_cast<HeapFreeList*>(&m2048), m204c);
    }

    v13(m30);

    m30 = 0;
    m14 = 0;
}

}
}   // namespace f3m_0086dc60

// @f3 0x0086ba60 (community match, verified in this file)
namespace task0800 {
void __cdecl FUN_00c064b8(void*);
struct Heap { virtual void v0(); virtual void v4(); virtual void v8(); virtual void Free(void*, int); };
struct Pool { bool FUN_0086b870(void*); void FUN_0086d930(void*); };
extern Pool* DAT_01090be0[256];
struct Manager {
 unsigned char active, unk01; unsigned short unk02;
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
 Heap* defaultHeap;
 Heap* MemoryManager_GetHeapForPointer(void*);
 void FUN_0086ba60(void* p);
};
void Manager::FUN_0086ba60(void* p) {
 if (!p) return;
 if (!active) { FUN_00c064b8(p); return; }
 if (!defaultHeap) { FUN_00c064b8(p); return; }
 Pool* pool = DAT_01090be0[(unsigned int)p >> 24];
 if (pool && pool->FUN_0086b870(p)) { pool->FUN_0086d930(p); return; }
 Heap* heap = MemoryManager_GetHeapForPointer(p);
 if (heap) heap->Free(p,0);
 else FUN_00c064b8(p);
}
}

// @f3 0x0086c170 (community match, verified in this file)
extern float DAT_00f7544c, DAT_00f75450, DAT_00f75454;
namespace f3m_0086c170 {
// @fnv 0x00aa4e40
void FUN_0086c170()
{
    if (DAT_00f7544c < DAT_00f75450)
    {
        DAT_00f7544c = (1.0f + DAT_00f75454) * DAT_00f7544c;
        if (DAT_00f7544c > DAT_00f75450)
        {
            DAT_00f7544c = DAT_00f75450;
        }
    }
    else if (DAT_00f7544c > DAT_00f75450)
    {
        DAT_00f7544c = (1.0f - DAT_00f75454) * DAT_00f7544c;
        if (DAT_00f7544c < DAT_00f75450)
        {
            DAT_00f7544c = DAT_00f75450;
        }
    }
}
}   // namespace f3m_0086c170

// @f3 0x0086d160 (community match, verified in this file)
namespace task0814 {
struct Allocator {void* FUN_0086b8a0(unsigned int,unsigned int);};
extern Allocator DAT_01090a78;
struct HeapBlockBase
{
    HeapBlockBase()
    {}
    ~HeapBlockBase();
    virtual void v00();
};

struct HeapBlockLink
{
    int m_00;
    int m_04;
    HeapBlockLink() : m_00(0), m_04(0)
    {}
};

struct FUN_0086d160 : HeapBlockBase
{
    unsigned int m_04;
    unsigned int m_08;
    void* m_0c;
    void* m_10;
    int m_14;
    int m_18;
    int m_1c;
    HeapBlockLink m_20;
    FUN_0086d160(unsigned int a, unsigned int b);
    virtual void v00();
};

// @fnv 0x00aa7400
// pdb: ZeroOverheadHeap::ZeroOverheadHeap | ZeroOverheadHeap.obj | tesv_win, call_gap, low
FUN_0086d160::FUN_0086d160(unsigned int a, unsigned int b) : m_04(a), m_08(b), m_14(0)
{
    m_0c = DAT_01090a78.FUN_0086b8a0(a, 1);
    m_10 = m_0c;
}

}

// @f3 0x0086d5c0 (community match, verified in this file)
namespace f3m_0086d5c0 {
namespace n86d5c0 {
extern int (__stdcall* const FUN_00d9b150)(void* addr, unsigned int size, unsigned int type);
struct Block { int prev; unsigned int sizeFlags; };
}
struct Heap86d5c0 {
    char pad[0x10];
    unsigned int pageSize;
    void FUN_0086d5c0(n86d5c0::Block* b);
};
void Heap86d5c0::FUN_0086d5c0(n86d5c0::Block* b)
{
    unsigned int size = b->sizeFlags & 0xfffffff;
    if (size < pageSize) return;
    unsigned int start = (unsigned int)b + 8;
    unsigned int a = (start + pageSize - 1) & ~(pageSize - 1);
    unsigned int len = (start - a + size) & ~(pageSize - 1);
    if (len < pageSize) return;
    n86d5c0::FUN_00d9b150((void*)a, len, 0x4000);
    b->sizeFlags |= 0x20000000;
}
}   // namespace f3m_0086d5c0

// @f3 0x0086bbe0 (community match, verified in this file)
namespace task0833 {
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct MapBase {
    virtual ~MapBase() { if(buckets) DAT_01090a78.FUN_0086ba60(buckets); }
    unsigned int hashSize;
    void** buckets;
    unsigned int count;
    void FUN_006bd950();
};
struct FUN_0086bbe0 : MapBase {
    virtual ~FUN_0086bbe0();
};
FUN_0086bbe0::~FUN_0086bbe0() { FUN_006bd950(); }
}

// @f3 0x0086b8c0 (community match, verified in this file)
namespace f3m_0086b8c0 {
namespace Size302{struct Cache302{unsigned int unk00,base;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
unsigned int unk24;
unsigned int unk28;
unsigned int unk2c;
unsigned int unk30;
unsigned int unk34;
unsigned int unk38;
unsigned int unk3c;
unsigned int value;
unsigned int unk44;
unsigned int unk48;
unsigned int unk4c;
unsigned int length;
};extern Cache302* DAT_01090be0[];struct Region302{
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual unsigned int Query(unsigned int,int);
};unsigned int __cdecl FUN_00c067da(unsigned int);struct Owner302{Region302* MemoryManager_GetHeapForPointer(unsigned int);Region302* MemoryManager_GetHeapForPhysicalPointer(unsigned int);unsigned int FUN_0086b8c0(unsigned int);};
// pdb: MemoryManager::Size | MemoryManager.obj | fnv360_0822_retail, callee_sim, low
// pdb params: apPtr
unsigned int Owner302::FUN_0086b8c0(unsigned int address){Cache302*cached=DAT_01090be0[address>>24];if(cached&&address>=cached->base&&address<cached->base+cached->length)return cached->value;Region302*region=MemoryManager_GetHeapForPointer(address);if(!region)region=MemoryManager_GetHeapForPhysicalPointer(address);if(region)return region->Query(address,0);return FUN_00c067da(address);}
}
}   // namespace f3m_0086b8c0

// @f3 0x0086d020 (community match, verified in this file)
namespace f3m_0086d020 {
namespace task0850 {
struct MemoryHeapStats
{
    const char* m_pHeapName;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiHeapCommitted;
    int m_iAllocatedToBlocks;
    int m_iFreeBlockCount;
    int m_uiFreeBlockCount;
    int m_iFreeInBlocks;
    int m_iUsedInBlocks;
    int m_iSmallestFreeBlock;
    int m_iLargestFreeBlock;
    int m_iHeapOverhead;
    int m_iFreeListOverhead;
    int m_iBlockOverhead;
    int m_iTotalFree;
};
struct FUN_0086d020_t
{
    virtual void v0();
    virtual const char* GetName();
    unsigned int iSize;
    const char* pName;
    void* m_pPoolBase;
    void* m_pCurrent;
    int m_iAllocationCount;
    void FUN_0086d020(MemoryHeapStats* apStats, bool abFullBlockInfo);
};
// @fnv 0x00aa7630
void FUN_0086d020_t::FUN_0086d020(MemoryHeapStats* apStats, bool abFullBlockInfo)
{
    if (!apStats)
        return;
    apStats->m_pHeapName = GetName();
    apStats->m_uiMaximumHeapSize = iSize;
    apStats->m_uiHeapCommitted = iSize;
    apStats->m_iAllocatedToBlocks = (int)m_pCurrent - (int)m_pPoolBase;
    apStats->m_iFreeBlockCount = m_iAllocationCount;
    apStats->m_uiFreeBlockCount = 0;
    apStats->m_iFreeInBlocks = 0;
    apStats->m_iUsedInBlocks = (int)m_pCurrent - (int)m_pPoolBase;
    apStats->m_iSmallestFreeBlock = 0;
    apStats->m_iLargestFreeBlock = 0;
    apStats->m_iHeapOverhead = 0x40;
    apStats->m_iFreeListOverhead = 0;
    apStats->m_iBlockOverhead = m_iAllocationCount << 2;
    apStats->m_iTotalFree = 0;
}

}
}   // namespace f3m_0086d020

// @f3 0x00865a10 (community match, verified in this file)
namespace Task0848 {
extern void* __cdecl FUN_0089eb90(unsigned int);
extern "C" void __fastcall FUN_00824e90(void*);
extern int DAT_00e26b2c;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct NiPropertyMem;
struct NiPropertyVTable
{
    void* reserved;
    void(__thiscall* dispose)(NiPropertyMem*);
};
struct NiPropertyMem
{
    void* vtable;
    volatile long refs;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short flags;

    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
        {
            static_cast<NiPropertyVTable*>(vtable)->dispose(this);
        }
    }
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
};
struct NiPointerProperty
{
    NiPropertyMem* pointer;
    __forceinline void operator=(NiPropertyMem* fresh)
    {
        if (pointer != fresh)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = fresh;
            if (pointer)
                pointer->IncRefCount();
        }
    }
};
extern NiPointerProperty DAT_01090970;
// @fnv 0x00a8f5b0
// pdb: NiCullingProperty::_SDMInit | NiCullingProperty.obj | fnv360_0822_retail, call_gap, medium
void __cdecl FUN_00865a10()
{
    NiPropertyMem* allocated = static_cast<NiPropertyMem*>(FUN_0089eb90(sizeof(NiPropertyMem)));
    NiPropertyMem* fresh;
    if (allocated)
    {
        FUN_00824e90(allocated);
        allocated->flags &= 0xfffe;
        allocated->vtable = &DAT_00e26b2c;
        fresh = allocated;
    }
    else
    {
        fresh = 0;
    }
    DAT_01090970 = fresh;
}

}

// @f3 0x0086c6a0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned long, unsigned long);
namespace task0858 {
struct MemoryManager { int FUN_006e2080(unsigned int,int,bool*); };
extern MemoryManager DAT_01090a78;
// pdb: ScrapHeapManager::AllocateBuffer | ScrapHeap.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
char* __stdcall ScrapHeapManager_AllocateBuffer(unsigned int initialSize) {
 char* buffer=(char*)VirtualAlloc(0,0x400000u,0x2000u,4);
 int memoryPass=0;
 while(!(bool)(int)(VirtualAlloc(buffer,initialSize,0x1000u,4)!=0)) {
  bool allowSystemAlloc=true;
  memoryPass=DAT_01090a78.FUN_006e2080(0,memoryPass,&allowSystemAlloc);
 }
 return buffer;
}
}

// @f3 0x0086de90 (community match, verified in this file)
namespace f3m_0086de90 {
namespace task0857 {
class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
    __forceinline void SetNextFree(HeapFreeBlock* block)
    {
        m_pNextFree = block;
    }
    __forceinline void SetPrevFree(HeapFreeBlock* block)
    {
        m_pPrevFree = block;
    }
    void RemoveFromFreeList();
};

class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
    __forceinline void AddBlock(HeapFreeBlock* block)
    {
        if (pTail)
        {
            HeapFreeBlock* tail = pTail;
            block->m_pNextFree = tail;
            HeapFreeBlock* previous = tail->m_pPrevFree;
            block->m_pPrevFree = previous;
            if (previous)
                previous->m_pNextFree = block;
            tail->m_pPrevFree = block;
            pTail = block;
        }
        else
        {
            pHead = block;
            pTail = block;
        }
    }
};
class HeapBlockList
{
  public:
    int iCount;
    HeapFreeList* pFirst;
};

class AbstractHeap {
public:
    void* vtable;
    const char* pName;
    int m_iBlockAlignment;
    unsigned int m_uiBlockHeaderSize;
    unsigned int m_uiHeapGrowthEnabled;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiMinimumCommitSize;
    unsigned int m_uiCurrentCommitSize;
    unsigned int m_uiInitialCommitSize;
    int m_iUsedSize;
    int m_iAllocationCount;
    int m_iAllocatedBlockSize;
    char* m_pHeapBase;
    int m_iFreeBlockCount;
    MemoryBlockHeader* m_pFirstBlock;
    MemoryBlockHeader* m_pLastBlock;

    int m_uiFreeBlockCount;
    HeapFreeList m_kFreeLists[1024];
    HeapFreeList* m_pCurrentFreeList;
    HeapFreeList m_kFreeListSentinel;
    MemoryBlockHeader** m_ppHeapBlocks;
    unsigned int m_uiBlockCount;
    HeapBlockList m_kSubBucketLists[16];
    __forceinline HeapFreeList* GetFreeList(unsigned int size)
    {
        int bucket = size / m_iBlockAlignment - 1;
        return bucket >= 1024 ? &m_kFreeListSentinel : &m_kFreeLists[bucket];
    }
    __forceinline int GetSubBucket(int size)
    {
        if (size > 4096)
            return -1;
        return (size / m_iBlockAlignment - 1) / 64;
    }
    void RemoveBlockFromFreeList(HeapFreeBlock*);
    void IncrementSubBucket(int);
    void DecrementSubBucket(int);
    __declspec(noinline) void FUN_0086daf0(HeapFreeBlock*);
    __declspec(noinline) void FUN_0086db90(HeapFreeList*, HeapFreeBlock*);
    __declspec(noinline) void FUN_0086dcf0(HeapFreeBlock*, HeapFreeBlock*);
    void FUN_0086ddc0();
    void FUN_0086de90(HeapFreeBlock*);
};
inline void HeapFreeBlock::RemoveFromFreeList()
{
    if (m_pNextFree)
        m_pNextFree->SetPrevFree(m_pPrevFree);
    if (m_pPrevFree)
        m_pPrevFree->SetNextFree(m_pNextFree);
    m_pPrevFree = 0;
    m_pNextFree = 0;
}

void AbstractHeap::IncrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        ++m_kSubBucketLists[bucket].iCount;
}

void AbstractHeap::DecrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        --m_kSubBucketLists[bucket].iCount;
}

void AbstractHeap::FUN_0086daf0(HeapFreeBlock* block)
{
    block->m_pPrevFree = 0;
    block->m_pNextFree = 0;
    block->SetFree(true);
    HeapFreeList* list = GetFreeList(block->GetSize());
    list->AddBlock(block);
    ++m_uiFreeBlockCount;
    IncrementSubBucket(block->GetSize());
}

void AbstractHeap::FUN_0086db90(HeapFreeList* apFreeList, HeapFreeBlock* block)
{
    HeapFreeBlock* pPrev = block->m_pPrevFree;
    HeapFreeBlock* pNext = block->m_pNextFree;
    block->RemoveFromFreeList();
    block->SetFree(false);
    if (block == apFreeList->pHead)
        apFreeList->pHead = pPrev;
    if (block == apFreeList->pTail)
        apFreeList->pTail = pNext;
    DecrementSubBucket(block->GetSize());
    --m_uiFreeBlockCount;
}

inline void AbstractHeap::RemoveBlockFromFreeList(HeapFreeBlock* block)
{
    FUN_0086db90(GetFreeList(block->GetSize()), block);
}

void AbstractHeap::FUN_0086dcf0(HeapFreeBlock* pFirstBlock, HeapFreeBlock* pSecondBlock)
{
    RemoveBlockFromFreeList(pFirstBlock);
    RemoveBlockFromFreeList(pSecondBlock);
    if (pSecondBlock->IsDecommitted())
        pFirstBlock->SetDecommitted(true);
    pFirstBlock->SetSize(pFirstBlock->GetSize() + pSecondBlock->GetTotalSize());
    if (pSecondBlock == m_pLastBlock)
        m_pLastBlock = pFirstBlock;
    else
        pSecondBlock->GetNext()->SetPrevious(pFirstBlock);
    --m_iFreeBlockCount;
    FUN_0086daf0(pFirstBlock);
}

void AbstractHeap::FUN_0086de90(HeapFreeBlock* freeBlock)
{
    HeapFreeBlock* block = freeBlock;
    if (block)
    {
        for (;;)
        {
            HeapFreeBlock* previous = (HeapFreeBlock*)block->GetPrevious();
            if (previous && previous->IsFree())
            {
                FUN_0086dcf0(previous, block);
                block = previous;
            }
            else
            {
                break;
            }
        }
    }
    if (block)
    {
        while (block != m_pLastBlock && block->GetNext()->IsFree())
        {
            FUN_0086dcf0(block, (HeapFreeBlock*)block->GetNext());
        }
    }
    FUN_0086ddc0();
}
}
}   // namespace f3m_0086de90

// @f3 0x0086c460 (community match, verified in this file)
namespace f3m_0086c460 {
namespace random_seed_0086c460 {
struct RandomState {
    unsigned int unk00,unk04;
    unsigned int state[624];
    unsigned int index;
    void FUN_0086c460(unsigned int seed);
};
// pdb: BSRandom::Seed | BSRandom.obj | fnv360_0822_retail, uconst, low
// pdb params: aiSeed
void RandomState::FUN_0086c460(unsigned int seed) {
    state[0]=seed;
    for(index=1;index<624;++index) state[index]=state[index-1]*69069u;
}
}
}   // namespace f3m_0086c460

// @f3 0x00876e00 (community match, verified in this file)
namespace f3m_00876e00 {
namespace Cast336{struct Type336{const char*name;Type336*parent;};extern Type336 DAT_0108f41c;struct Object336{virtual void v0();virtual void v4();virtual Type336* Type();__forceinline bool IsKind(Type336*wanted){Type336*type=Type();while(type){if(type==wanted)return true;type=type->parent;}return false;}Object336* As(){return IsKind(&DAT_0108f41c)?this:0;}};struct Manager336{void FUN_008841c0(Object336*);};struct Owner336{unsigned int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c,unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c,unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c,unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c,unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c,unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc,unk0c0,unk0c4,unk0c8,unk0cc,unk0d0,unk0d4,unk0d8,unk0dc,unk0e0,unk0e4,unk0e8,unk0ec,unk0f0,unk0f4,unk0f8,unk0fc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c,unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c,unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c,unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c,unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc,unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc,unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc,unk300,unk304,unk308,unk30c,unk310,unk314,unk318,unk31c,unk320,unk324,unk328,unk32c,unk330,unk334,unk338,unk33c,unk340,unk344,unk348,unk34c,unk350,unk354,unk358,unk35c,unk360,unk364,unk368,unk36c,unk370,unk374,unk378,unk37c,unk380,unk384,unk388,unk38c,unk390,unk394,unk398,unk39c,unk3a0,unk3a4,unk3a8,unk3ac,unk3b0,unk3b4,unk3b8,unk3bc,unk3c0,unk3c4,unk3c8,unk3cc,unk3d0,unk3d4,unk3d8,unk3dc,unk3e0,unk3e4,unk3e8,unk3ec,unk3f0,unk3f4,unk3f8,unk3fc,unk400,unk404,unk408,unk40c,unk410,unk414,unk418,unk41c,unk420,unk424,unk428,unk42c,unk430,unk434,unk438,unk43c,unk440,unk444,unk448,unk44c,unk450,unk454,unk458,unk45c,unk460,unk464,unk468,unk46c,unk470,unk474,unk478,unk47c,unk480,unk484,unk488,unk48c,unk490,unk494,unk498,unk49c,unk4a0,unk4a4,unk4a8,unk4ac,unk4b0,unk4b4,unk4b8,unk4bc,unk4c0,unk4c4,unk4c8,unk4cc,unk4d0,unk4d4,unk4d8,unk4dc,unk4e0,unk4e4,unk4e8,unk4ec,unk4f0,unk4f4,unk4f8,unk4fc,unk500,unk504,unk508,unk50c,unk510,unk514,unk518,unk51c,unk520,unk524,unk528,unk52c,unk530,unk534,unk538,unk53c,unk540,unk544,unk548,unk54c,unk550,unk554,unk558,unk55c,unk560,unk564,unk568,unk56c,unk570,unk574,unk578,unk57c,unk580,unk584,unk588,unk58c,unk590,unk594,unk598,unk59c,unk5a0,unk5a4,unk5a8,unk5ac,unk5b0,unk5b4,unk5b8,unk5bc,unk5c0,unk5c4,unk5c8,unk5cc,unk5d0,unk5d4,unk5d8,unk5dc,unk5e0,unk5e4,unk5e8,unk5ec,unk5f0,unk5f4,unk5f8,unk5fc,unk600,unk604,unk608,unk60c,unk610,unk614,unk618,unk61c,unk620,unk624,unk628,unk62c,unk630,unk634,unk638,unk63c,unk640,unk644,unk648,unk64c,unk650,unk654,unk658,unk65c,unk660,unk664,unk668,unk66c,unk670,unk674,unk678,unk67c,unk680,unk684,unk688,unk68c,unk690,unk694,unk698,unk69c,unk6a0,unk6a4,unk6a8,unk6ac,unk6b0,unk6b4,unk6b8,unk6bc,unk6c0,unk6c4,unk6c8,unk6cc,unk6d0,unk6d4,unk6d8,unk6dc,unk6e0,unk6e4,unk6e8,unk6ec,unk6f0,unk6f4,unk6f8,unk6fc,unk700,unk704,unk708,unk70c,unk710,unk714,unk718,unk71c,unk720,unk724,unk728,unk72c,unk730,unk734,unk738,unk73c,unk740,unk744,unk748,unk74c,unk750,unk754,unk758,unk75c,unk760,unk764,unk768,unk76c,unk770,unk774,unk778,unk77c,unk780,unk784,unk788,unk78c,unk790,unk794,unk798,unk79c,unk7a0,unk7a4,unk7a8,unk7ac,unk7b0,unk7b4,unk7b8,unk7bc,unk7c0,unk7c4,unk7c8,unk7cc,unk7d0,unk7d4,unk7d8,unk7dc,unk7e0,unk7e4,unk7e8,unk7ec,unk7f0,unk7f4,unk7f8,unk7fc,unk800,unk804,unk808,unk80c,unk810,unk814,unk818,unk81c,unk820,unk824,unk828,unk82c,unk830,unk834,unk838,unk83c,unk840,unk844,unk848,unk84c,unk850,unk854,unk858,unk85c,unk860,unk864,unk868,unk86c,unk870,unk874,unk878,unk87c,unk880,unk884,unk888,unk88c,unk890,unk894,unk898,unk89c,unk8a0,unk8a4,unk8a8,unk8ac,unk8b0,unk8b4,unk8b8,unk8bc,unk8c0,unk8c4;Manager336*manager;void FUN_00876e00(Object336*);};
// pdb: NiXenonRenderer::IsCopySurfaceValid | NiXenonRenderer.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkDest
void Owner336::FUN_00876e00(Object336*object){if(object){Object336*cast=object->As();if(cast)manager->FUN_008841c0(cast);}}
}
}   // namespace f3m_00876e00

// @f3 0x0086d350 (community match, verified in this file)
namespace f3m_0086d350 {
namespace n86d350 {
struct Base {
    virtual ~Base();
    char pad[0x20f1 - 4];
    bool m20f1;
};
}
struct FUN_0086d350 : n86d350::Base {
    virtual ~FUN_0086d350();
    void FUN_0086dc60();
};
FUN_0086d350::~FUN_0086d350() {
    FUN_0086dc60();
    m20f1 = true;
}
}   // namespace f3m_0086d350

// @f3 0x0086d1e0 (community match, verified in this file)
namespace task0877 {
struct MemoryManager { void FUN_0086b8b0(void*,int); };
extern MemoryManager DAT_01090a78;
struct Base { virtual ~Base() {} };
struct FUN_0086d1e0 : Base {
 int field04,field08; void* buffer;
 virtual ~FUN_0086d1e0();
};
FUN_0086d1e0::~FUN_0086d1e0() { DAT_01090a78.FUN_0086b8b0(buffer,1); }
}

// @f3 0x0086cbf0 (community match, verified in this file)
namespace f3m_0086cbf0 {
struct FUN_0086cbf0_Class
{
    unsigned int m_uiItemCount;
    unsigned int m_uiThreadId;

    void __thiscall FUN_0086cbf0();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* destination, long exchange,
                                                                           long comparand);

// @fnv 0x00aa5ff0
// pdb: BSReadWriteLock::LockForRead | BSReadWriteLock.obj | fnv360_0721_beta, call_seq, medium
void __thiscall FUN_0086cbf0_Class::FUN_0086cbf0()
{
    unsigned long threadId = GetCurrentThreadId();

    if (m_uiThreadId == threadId)
    {
        m_uiItemCount = m_uiItemCount + 1;
    }
    else
    {
        unsigned int count = m_uiItemCount & 0x0fffffff;

        while (InterlockedCompareExchange(reinterpret_cast<volatile long*>(&m_uiItemCount),
                                          static_cast<long>(count + 1),
                                          static_cast<long>(count)) != static_cast<long>(count))
        {
            Sleep(0);
            count = m_uiItemCount & 0x0fffffff;
        }
    }
}

}   // namespace f3m_0086cbf0

// @f3 0x0087a160 (community match, verified in this file)
namespace f3m_0087a160 {
struct ShaderNode895 { ShaderNode895* next; ShaderNode895* prev; void* data; };
struct ShaderPool895 {
    unsigned int count;
    ShaderNode895* FUN_00423640();
};
struct ShaderList895 {
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
    unsigned int unk25c;
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
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    ShaderNode895* head;
    ShaderNode895* tail;
    ShaderPool895 pool;
    void FUN_0087a160(void* shader);
};
// pdb: NiXenonRenderer::RegisterD3DShader | NiXenonRenderer.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: pkD3DShader
void ShaderList895::FUN_0087a160(void* shader)
{
    ShaderNode895* node = pool.FUN_00423640();
    node->data = shader;
    node->prev = 0;
    node->next = head;
    if (head) {
        head->prev = node;
        ++pool.count;
        head = node;
    } else {
        ++pool.count;
        tail = node;
        head = node;
    }
}
}   // namespace f3m_0087a160

// @f3 0x0086c220 (community match, verified in this file)
extern float DAT_00f7544c, DAT_00f75450;
namespace f3m_0086c220 {
struct TimeScale901 {
    unsigned int unk00, unk04, unk08;
    float scaledValue;
    unsigned int unk10, unk14;
    bool useGlobal;
    void BSTimer_SetGlobalTimeMultiplier(float mult, bool now);
};
// pdb: BSTimer::SetGlobalTimeMultiplier | BSTimer.obj | fnv360_0822_retail, call_dedup + bridge(call_gap|call_gap) + skyrim(objrun_prop), high
void TimeScale901::BSTimer_SetGlobalTimeMultiplier(float mult, bool now)
{
    bool global = useGlobal;
    if (global) {
        DAT_00f75450 = mult;
        if (now) DAT_00f7544c = DAT_00f75450;
    } else {
        DAT_00f75450 = mult;
        if (mult == DAT_00f7544c) return;
        scaledValue /= DAT_00f7544c;
        DAT_00f7544c = mult;
        scaledValue *= DAT_00f7544c;
    }
}
}   // namespace f3m_0086c220

// @f3 0x0086b820 (community match, verified in this file)
namespace f3m_0086b820 {
namespace Task0905 {
struct Pool {virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual bool Contains(void*);};
struct Allocator {
 int unk00;unsigned short count,unk06;
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
 Pool** pools;
 Pool* MemoryManager_GetHeapForPhysicalPointer(void*);
};
// pdb: MemoryManager::GetHeapForPhysicalPointer | MemoryManager.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
Pool* Allocator::MemoryManager_GetHeapForPhysicalPointer(void* memory) {
 Pool* found=0;
 for(unsigned short i=0;i<count && !found;i++) {
  if(pools[i]->Contains(memory)) found=pools[i];
 }
 return found;
}
}
}   // namespace f3m_0086b820

// @f3 0x0086d4c0 (community match, verified in this file)
namespace f3m_0086d4c0 {
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned long, unsigned long, unsigned long);
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
struct Reservation { void* FUN_0086d4c0(unsigned int, unsigned int); };
// pdb: MemoryHeap::TotalSize | MemoryHeap.obj | tesv_win, objopen_prop, low
void* Reservation::FUN_0086d4c0(unsigned int reserveSize, unsigned int commitSize) {
 void* p=VirtualAlloc(0,reserveSize,0x2000,4);
 if(p) {
  if(!VirtualAlloc(p,commitSize,0x1000,4)) {
   VirtualFree(p,0,0x8000);
   p=0;
  }
 }
 return p;
}
}   // namespace f3m_0086d4c0

// @f3 0x0086ccf0 (community match, verified in this file)
namespace f3m_0086ccf0 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dst, long xchg, long cmp);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ms);
struct FUN_0086ccf0_c {
    volatile long count;
    unsigned long owner;
    bool FUN_0086ccf0();
};
// pdb: BSReadWriteLock::TryLockForRead | BSReadWriteLock.obj | fnv360_0822_retail, call_gap, low
bool FUN_0086ccf0_c::FUN_0086ccf0()
{
    if (owner == GetCurrentThreadId()) {
        count++;
    } else {
        long v = count & 0x0fffffff;
        while (InterlockedCompareExchange(&count, v + 1, v) != v) {
            if (count & 0x80000000)
                return false;
            Sleep(0);
            v = count & 0x0fffffff;
        }
    }
    return true;
}
}   // namespace f3m_0086ccf0

// @f3 0x0086b7d0 (community match, verified in this file)
namespace f3m_0086b7d0 {
struct FUN_00aa45a0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4(int);
};
struct FUN_00aa45a0_Class
{
    unsigned short m_auiShapeKeys;
    unsigned short m_uiItemCount;
    unsigned int m_unknown;
    FUN_00aa45a0_vt** m_items;
    FUN_00aa45a0_vt* __thiscall MemoryManager_GetHeapForPointer(int arg);
};
// @fnv 0x00aa45a0
// pdb: MemoryManager::GetHeapForPointer | MemoryManager.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq), high
FUN_00aa45a0_vt* FUN_00aa45a0_Class::MemoryManager_GetHeapForPointer(int arg)
{
    for (unsigned short i = 0; i < m_uiItemCount; ++i)
    {
        FUN_00aa45a0_vt* item = m_items[i];
        if (item->v4(arg))
            return item;
    }
    return 0;
}

}   // namespace f3m_0086b7d0

// @f3 0x0086d570 (community match, verified in this file)
namespace f3m_0086d570 {
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
struct VirtualHeap967 {
    unsigned int unk00, unk04, unk08, unk0c, granularity;
    unsigned int FUN_0086d570(char*, unsigned int, unsigned int);
};
// pdb: UnitTestMemoryHeap::QSmallBlockList | MemoryHeap.obj | tesv_win, objrun_open, low
unsigned int VirtualHeap967::FUN_0086d570(char* base, unsigned int extent, unsigned int size)
{
    size &= ~(granularity - 1);
    if (size >= granularity) {
        char* address = base + extent - size;
        if (!(bool)(int)(VirtualFree(address, size, 0x4000) == 1)) size = 0;
    } else size = 0;
    return size;
}
}   // namespace f3m_0086d570

// @f3 0x0086d630 (community match, verified in this file)
namespace f3m_0086d630 {
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*,unsigned long,unsigned long,unsigned long);
namespace Task0960 {
struct Reservation {
 int unk00;void* memory;
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
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 unsigned int size;
 void FUN_0086d630();
};
// pdb: MemoryPool::PlatformReserveHeap | MemoryPool.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: AbstractHeap::PointerInHeap)
void Reservation::FUN_0086d630() {
 unsigned int i=1;
 while(memory==0) {
  memory=VirtualAlloc((void*)(i<<24),size,0x2000,4);
  if(i<0xff) i++;else break;
 }
}
}
}   // namespace f3m_0086d630

// @f3 0x0086d530 (community match, verified in this file)
namespace f3m_0086d530 {
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*,unsigned int,unsigned long,unsigned long);
namespace task1093 {
struct Memory{int unk00,unk04,unk08,unk0c;unsigned int growth;unsigned int FUN_0086d530(void*,unsigned int,unsigned int);};
unsigned int Memory::FUN_0086d530(void* base,unsigned int offset,unsigned int size){void* address=(char*)base+offset;size=(size+growth)&~(growth-1);if(!(bool)(VirtualAlloc(address,size,0x1000,4)?1:0))size=0;return size;}
}
}   // namespace f3m_0086d530

// @f3 0x0086c140 (community match, verified in this file)
namespace f3m_0086c140 {
union PerformanceCounter {__int64 QuadPart;};
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(PerformanceCounter*);
// pdb: BSPrecisionTimer::GetTimer | BSPrecisionTimer.obj | fnv360_0822_retail, call_gap, medium
unsigned __int64 FUN_0086c140(){
 PerformanceCounter counter;counter.QuadPart=0;
 QueryPerformanceCounter(&counter);
 return counter.QuadPart;
}
}   // namespace f3m_0086c140

// @f3 0x0086d930 (community match, verified in this file)
extern const char str_00e28034[];
namespace f3m_0086d930 {
extern long (__stdcall* DAT_00d9b06c)(volatile long*, long, long);


struct Lock86d930 {
    volatile long owner;
    unsigned int count;
    void FUN_00409a80(const char* name);
    void Unlock() { if (!--count) { long current = owner; DAT_00d9b06c(&owner, 0, current); } }
};

struct Page86d930 {
    Page86d930* previous;
    Page86d930* next;
};

struct Pool86d930 {
    int unk00;
    char* base;
    Page86d930* freeList;
    int unk0c, unk10, unk14, unk18, unk1c;
    Lock86d930 lock;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned short* usage;
    int unk4c, unk50;
    int freeCount;
    void FUN_0086d930(Page86d930* page);
};

// pdb: MemoryPool::Free | MemoryPool.obj | fnv360_0822_retail, ustr, medium
// pdb params: apPointer
void Pool86d930::FUN_0086d930(Page86d930* page) {
    if (page) {
        lock.FUN_00409a80(str_00e28034);
        page->previous = 0;
        page->next = freeList;
        if (freeList) freeList->previous = page;
        freeCount++;
        freeList = page;
        usage[(unsigned int)((char*)page - base) >> 12]--;
        lock.Unlock();
    }
}
}   // namespace f3m_0086d930

// @f3 0x0086bc50 (community match, verified in this file)
namespace f3m_0086bc50 {
namespace f3m_0086bc50 { struct Heap { void FUN_0086ba60(void* p); }; extern Heap DAT_01090a78; }
// pdb: MemoryManager::GetPoolStats | MemoryManager.obj | tesv_win, objrun_open, low
class FUN_0086bc50 { public: virtual ~FUN_0086bc50(); int unk4; void* buf; static void operator delete(void* p) { f3m_0086bc50::DAT_01090a78.FUN_0086ba60(p); } };
FUN_0086bc50::~FUN_0086bc50() { if (buf) f3m_0086bc50::DAT_01090a78.FUN_0086ba60(buf); }
}   // namespace f3m_0086bc50

// @f3 0x0087e360 (community match, verified in this file)
namespace f3m_0087e360 {
template <class T> class NiTArray87e360 {
public:
    virtual ~NiTArray87e360();
    T* base;
    unsigned short maxSize;
    unsigned short size;
    unsigned short eSize;
    unsigned short growBy;
    NiTArray87e360() { maxSize = 0; growBy = 1; size = 0; eSize = 0; base = 0; }
    void RemoveAll() {
        for (unsigned short i = 0; i < size; i++)
            base[i] = 0;
        size = 0;
        eSize = 0;
    }
};
template <class T> class NiTPrimArray87e360 : public NiTArray87e360<T> {
public:
    virtual ~NiTPrimArray87e360();
};
struct Obj87e360 {
    int type;
    NiTPrimArray87e360<void*> arr;
    Obj87e360();
};
// pdb: NiTPrimitiveArray<NiD3DShaderDeclaration::NiPackerEntry *>::NiTPrimitiveArray<NiD3DShaderDeclaration::NiPackerEntry *> | NiD3DShaderDeclaration.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: NiD3DShaderDeclaration::NiPackerEntry::NiPackerEntry)
// pdb params: uiMaxSize, uiGrowBy
Obj87e360::Obj87e360()
{
    type = 0x11;
    arr.RemoveAll();
}
}   // namespace f3m_0087e360

// @f3 0x0086c640 (community match, verified in this file)
namespace f3m_0086c640 {
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*,unsigned long,unsigned long,unsigned long);
namespace Task0874 {
struct Manager {int FUN_006e2080(int,int,bool*);};
extern Manager DAT_01090a78;
// pdb: ScrapHeapManager::ExpandBuffer | ScrapHeap.obj | fnv360_0822_retail, call_seq + bridge(caller|call_gap) + skyrim(callee_sim), high
void __stdcall ScrapHeapManager_ExpandBuffer(char* buffer,unsigned int size,unsigned int additional) {
 int pass=0;
 while(!VirtualAlloc(buffer+size,additional,0x1000,4)) {
  bool allow=true;
  pass=DAT_01090a78.FUN_006e2080(0,pass,&allow);
 }
}
}
}   // namespace f3m_0086c640

// @f3 0x0086bf10 (community match, verified in this file)
namespace heap_block_construction {
struct ThreadData {
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
    unsigned int unk25c;
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
    int memoryContext;
};
extern __declspec(thread) ThreadData threadData;
struct ContextScope {
    int previous;
    __forceinline ContextScope(int value) { previous=threadData.memoryContext;threadData.memoryContext=value; }
    __forceinline ~ContextScope() { threadData.memoryContext=previous; }
};
struct Heap { void* FUN_0086b930(unsigned int);void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct AllocationBlock {
    unsigned int unk00;
    void* data;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    AllocationBlock(unsigned int,unsigned int,unsigned int);
    ~AllocationBlock();
    static void* operator new(unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
};
struct Owner {
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
    unsigned char unk118;
    bool allocationComplete;
    void FUN_0086bf10(unsigned int,unsigned int,unsigned int);
};
// pdb: MemoryManager::AddPool | MemoryManager.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: aiBlockSize, aiPoolSize, apDesc
void Owner::FUN_0086bf10(unsigned int bytes,unsigned int second,unsigned int third) {
    ContextScope scope(3);
    if(bytes<8)return;
    allocationComplete=false;
    AllocationBlock* block=new AllocationBlock(bytes,second,third);
    if(!block->data) {
        block->~AllocationBlock();
        DAT_01090a78.FUN_0086ba60(block);
    }
    allocationComplete=true;
}
}

// @f3 0x0086d2d0 (community match, verified in this file)
namespace f3m_0086d2d0 {
namespace memory_heap_constructor {
struct IMemoryHeap { virtual ~IMemoryHeap(); };
struct AbstractHeap : IMemoryHeap {
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
    unsigned char bucketStorage[0x2000];
    void* bucketEnd;
    unsigned int unk2048,unk204c,unk2050,unk2054;
    struct Partition { unsigned int count;void* bucket; } partitions[16];
    struct CriticalSection { void* debugInfo;long lockCount,recursionCount;void* ownerThread;void* semaphore;unsigned int spinCount; } lock;
    AbstractHeap(unsigned int,unsigned int,unsigned int,unsigned int);
    virtual ~AbstractHeap();
};
struct MemoryHeap : AbstractHeap {
    bool option;
    bool initialized;
    MemoryHeap(unsigned int,unsigned int,unsigned int,bool);
    void FUN_0086da70();
};
// pdb: MemoryHeap::MemoryHeap | MemoryHeap.obj | tesv_win, callee_sim, low
MemoryHeap::MemoryHeap(unsigned int first,unsigned int second,unsigned int third,bool value) : AbstractHeap(first,second,third,0x10000),option(value) { initialized=false;FUN_0086da70(); }
}
}   // namespace f3m_0086d2d0

// @f3 0x0086cf90 (community match, verified in this file)
namespace f3m_0086cf90 {
struct CriticalSection86cf90 { int unk00, unk04, unk08, unk0c, unk10, unk14; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection86cf90* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection86cf90* section);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CriticalSection86cf90* section);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* handle);

class CloneHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern CloneHeap DAT_01090a78;
extern const int DAT_00e27f48;

struct Owner86cf90 {
    const void* table;
    CriticalSection86cf90 lock;
    void* handle;
    int unk20, unk24, unk28;
    bool unk2c;
    Owner86cf90* FUN_0086cf90(unsigned int flags);
};

// pdb: BSThread::`scalar deleting destructor' | BSThread_Xenon.obj | fnv360_0822_retail, objrun_open, low
Owner86cf90* Owner86cf90::FUN_0086cf90(unsigned int flags) {
    table = &DAT_00e27f48;
    if (handle) {
        unk2c = false;
        EnterCriticalSection(&lock);
        CloseHandle(handle);
        handle = 0;
        LeaveCriticalSection(&lock);
    }
    DeleteCriticalSection(&lock);
    if (flags & 1) DAT_01090a78.FUN_0086ba60(this);
    return this;
}
}   // namespace f3m_0086cf90

// @f3 0x0086d770 (community match, verified in this file)
namespace f3m_0086d770 {
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned long size, unsigned long type);

class CloneHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern CloneHeap DAT_01090a78;
extern void* DAT_01090fe0[];
extern int DAT_01090be0[];

struct Owner86d770 {
    int unk00;
    void* unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40;
    int unk44;
    void* unk48;
    int unk4c;
    unsigned int unk50;
    void FUN_0086d770();
};

// pdb: MemoryPool::~MemoryPool | MemoryPool.obj | fnv360_0822_retail, objrun_prop, low
void Owner86d770::FUN_0086d770() {
    void* address = unk04;
    if (address) {
        VirtualFree(address, 0, 0x8000);
        DAT_01090fe0[unk40 >> 2] = 0;
        unsigned int count = unk50 >> 24;
        if (unk50 & 0xffffff) count++;
        unsigned int region = (unsigned int)unk04 >> 24;
        for (unsigned int i = 0; i < count; i++) DAT_01090be0[region + i] = 0;
    }
    DAT_01090a78.FUN_0086ba60(unk48);
}
}   // namespace f3m_0086d770

// @f3 0x0086cb00 (community match, verified in this file)
namespace f3m_0086cb00 {
class CloneHeap
{
public:
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern CloneHeap DAT_01090a78;

struct Manager86cb00 {
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    Manager86cb00() { unk200 = 0; unk204 = 0; unk220 = 0; unk224 = 0; }
    static void* operator new(unsigned int size) throw() { return DAT_01090a78.FUN_0086b930(size); }
    char* FUN_0086c840(unsigned int* size);
};

extern Manager86cb00* DAT_01090bdc;

struct FUN_0086cb00_Obj {
    char* unk00;
    char* unk04;
    char* unk08;
    int unk0c;
    void FUN_0086cb00(unsigned int size);
};

// pdb: ScrapHeap::Init | ScrapHeap.obj | fnv360_0822_debug, caller_sim, low
// pdb params: aiInitialSize
void FUN_0086cb00_Obj::FUN_0086cb00(unsigned int size) {
    if (!DAT_01090bdc) DAT_01090bdc = new Manager86cb00;
    char* block = DAT_01090bdc->FUN_0086c840(&size);
    unk00 = block;
    unk04 = block;
    unk0c = 0;
    unk08 = block + size;
}
}   // namespace f3m_0086cb00

// @f3 0x0086dc20 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
namespace task1298 {
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct Base { virtual ~Base() {} };
struct FUN_0086dc20 : Base {
int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020;
int unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c, unk0040;
int unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060;
int unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080;
int unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c, unk00a0;
int unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0;
int unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0;
int unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc, unk0100;
int unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120;
int unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c, unk0140;
int unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c, unk0160;
int unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c, unk0180;
int unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c, unk01a0;
int unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc, unk01c0;
int unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc, unk01e0;
int unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc, unk0200;
int unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c, unk0220;
int unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c, unk0240;
int unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c, unk0260;
int unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c, unk0280;
int unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c, unk02a0;
int unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc, unk02c0;
int unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc, unk02e0;
int unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc, unk0300;
int unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c, unk0320;
int unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c, unk0340;
int unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c, unk0360;
int unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c, unk0380;
int unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c, unk03a0;
int unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc, unk03c0;
int unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc, unk03e0;
int unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc, unk0400;
int unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c, unk0420;
int unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c, unk0440;
int unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c, unk0460;
int unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c, unk0480;
int unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c, unk04a0;
int unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc, unk04c0;
int unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc, unk04e0;
int unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc, unk0500;
int unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c, unk0520;
int unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c, unk0540;
int unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c, unk0560;
int unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c, unk0580;
int unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c, unk05a0;
int unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc, unk05c0;
int unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc, unk05e0;
int unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc, unk0600;
int unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c, unk0620;
int unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c, unk0640;
int unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c, unk0660;
int unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c, unk0680;
int unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c, unk06a0;
int unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc, unk06c0;
int unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc, unk06e0;
int unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc, unk0700;
int unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c, unk0720;
int unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c, unk0740;
int unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c, unk0760;
int unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c, unk0780;
int unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c, unk07a0;
int unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc, unk07c0;
int unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc, unk07e0;
int unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc, unk0800;
int unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c, unk0820;
int unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c, unk0840;
int unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c, unk0860;
int unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c, unk0880;
int unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c, unk08a0;
int unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc, unk08c0;
int unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc, unk08e0;
int unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc, unk0900;
int unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c, unk0920;
int unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c, unk0940;
int unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c, unk0960;
int unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c, unk0980;
int unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c, unk09a0;
int unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc, unk09c0;
int unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc, unk09e0;
int unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc, unk0a00;
int unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c, unk0a20;
int unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c, unk0a40;
int unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c, unk0a60;
int unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c, unk0a80;
int unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c, unk0aa0;
int unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc, unk0ac0;
int unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc, unk0ae0;
int unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc, unk0b00;
int unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c, unk0b20;
int unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c, unk0b40;
int unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c, unk0b60;
int unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c, unk0b80;
int unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c, unk0ba0;
int unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc, unk0bc0;
int unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc, unk0be0;
int unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc, unk0c00;
int unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c, unk0c20;
int unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c, unk0c40;
int unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c, unk0c60;
int unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c, unk0c80;
int unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c, unk0ca0;
int unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc, unk0cc0;
int unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc, unk0ce0;
int unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc, unk0d00;
int unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c, unk0d20;
int unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c, unk0d40;
int unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c, unk0d60;
int unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c, unk0d80;
int unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c, unk0da0;
int unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc, unk0dc0;
int unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc, unk0de0;
int unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc, unk0e00;
int unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c, unk0e20;
int unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c, unk0e40;
int unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c, unk0e60;
int unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c, unk0e80;
int unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c, unk0ea0;
int unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc, unk0ec0;
int unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc, unk0ee0;
int unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc, unk0f00;
int unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c, unk0f20;
int unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c, unk0f40;
int unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c, unk0f60;
int unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c, unk0f80;
int unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c, unk0fa0;
int unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc, unk0fc0;
int unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc, unk0fe0;
int unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc, unk1000;
int unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c, unk1020;
int unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c, unk1040;
int unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c, unk1060;
int unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c, unk1080;
int unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c, unk10a0;
int unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc, unk10c0;
int unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc, unk10e0;
int unk10e4, unk10e8, unk10ec, unk10f0, unk10f4, unk10f8, unk10fc, unk1100;
int unk1104, unk1108, unk110c, unk1110, unk1114, unk1118, unk111c, unk1120;
int unk1124, unk1128, unk112c, unk1130, unk1134, unk1138, unk113c, unk1140;
int unk1144, unk1148, unk114c, unk1150, unk1154, unk1158, unk115c, unk1160;
int unk1164, unk1168, unk116c, unk1170, unk1174, unk1178, unk117c, unk1180;
int unk1184, unk1188, unk118c, unk1190, unk1194, unk1198, unk119c, unk11a0;
int unk11a4, unk11a8, unk11ac, unk11b0, unk11b4, unk11b8, unk11bc, unk11c0;
int unk11c4, unk11c8, unk11cc, unk11d0, unk11d4, unk11d8, unk11dc, unk11e0;
int unk11e4, unk11e8, unk11ec, unk11f0, unk11f4, unk11f8, unk11fc, unk1200;
int unk1204, unk1208, unk120c, unk1210, unk1214, unk1218, unk121c, unk1220;
int unk1224, unk1228, unk122c, unk1230, unk1234, unk1238, unk123c, unk1240;
int unk1244, unk1248, unk124c, unk1250, unk1254, unk1258, unk125c, unk1260;
int unk1264, unk1268, unk126c, unk1270, unk1274, unk1278, unk127c, unk1280;
int unk1284, unk1288, unk128c, unk1290, unk1294, unk1298, unk129c, unk12a0;
int unk12a4, unk12a8, unk12ac, unk12b0, unk12b4, unk12b8, unk12bc, unk12c0;
int unk12c4, unk12c8, unk12cc, unk12d0, unk12d4, unk12d8, unk12dc, unk12e0;
int unk12e4, unk12e8, unk12ec, unk12f0, unk12f4, unk12f8, unk12fc, unk1300;
int unk1304, unk1308, unk130c, unk1310, unk1314, unk1318, unk131c, unk1320;
int unk1324, unk1328, unk132c, unk1330, unk1334, unk1338, unk133c, unk1340;
int unk1344, unk1348, unk134c, unk1350, unk1354, unk1358, unk135c, unk1360;
int unk1364, unk1368, unk136c, unk1370, unk1374, unk1378, unk137c, unk1380;
int unk1384, unk1388, unk138c, unk1390, unk1394, unk1398, unk139c, unk13a0;
int unk13a4, unk13a8, unk13ac, unk13b0, unk13b4, unk13b8, unk13bc, unk13c0;
int unk13c4, unk13c8, unk13cc, unk13d0, unk13d4, unk13d8, unk13dc, unk13e0;
int unk13e4, unk13e8, unk13ec, unk13f0, unk13f4, unk13f8, unk13fc, unk1400;
int unk1404, unk1408, unk140c, unk1410, unk1414, unk1418, unk141c, unk1420;
int unk1424, unk1428, unk142c, unk1430, unk1434, unk1438, unk143c, unk1440;
int unk1444, unk1448, unk144c, unk1450, unk1454, unk1458, unk145c, unk1460;
int unk1464, unk1468, unk146c, unk1470, unk1474, unk1478, unk147c, unk1480;
int unk1484, unk1488, unk148c, unk1490, unk1494, unk1498, unk149c, unk14a0;
int unk14a4, unk14a8, unk14ac, unk14b0, unk14b4, unk14b8, unk14bc, unk14c0;
int unk14c4, unk14c8, unk14cc, unk14d0, unk14d4, unk14d8, unk14dc, unk14e0;
int unk14e4, unk14e8, unk14ec, unk14f0, unk14f4, unk14f8, unk14fc, unk1500;
int unk1504, unk1508, unk150c, unk1510, unk1514, unk1518, unk151c, unk1520;
int unk1524, unk1528, unk152c, unk1530, unk1534, unk1538, unk153c, unk1540;
int unk1544, unk1548, unk154c, unk1550, unk1554, unk1558, unk155c, unk1560;
int unk1564, unk1568, unk156c, unk1570, unk1574, unk1578, unk157c, unk1580;
int unk1584, unk1588, unk158c, unk1590, unk1594, unk1598, unk159c, unk15a0;
int unk15a4, unk15a8, unk15ac, unk15b0, unk15b4, unk15b8, unk15bc, unk15c0;
int unk15c4, unk15c8, unk15cc, unk15d0, unk15d4, unk15d8, unk15dc, unk15e0;
int unk15e4, unk15e8, unk15ec, unk15f0, unk15f4, unk15f8, unk15fc, unk1600;
int unk1604, unk1608, unk160c, unk1610, unk1614, unk1618, unk161c, unk1620;
int unk1624, unk1628, unk162c, unk1630, unk1634, unk1638, unk163c, unk1640;
int unk1644, unk1648, unk164c, unk1650, unk1654, unk1658, unk165c, unk1660;
int unk1664, unk1668, unk166c, unk1670, unk1674, unk1678, unk167c, unk1680;
int unk1684, unk1688, unk168c, unk1690, unk1694, unk1698, unk169c, unk16a0;
int unk16a4, unk16a8, unk16ac, unk16b0, unk16b4, unk16b8, unk16bc, unk16c0;
int unk16c4, unk16c8, unk16cc, unk16d0, unk16d4, unk16d8, unk16dc, unk16e0;
int unk16e4, unk16e8, unk16ec, unk16f0, unk16f4, unk16f8, unk16fc, unk1700;
int unk1704, unk1708, unk170c, unk1710, unk1714, unk1718, unk171c, unk1720;
int unk1724, unk1728, unk172c, unk1730, unk1734, unk1738, unk173c, unk1740;
int unk1744, unk1748, unk174c, unk1750, unk1754, unk1758, unk175c, unk1760;
int unk1764, unk1768, unk176c, unk1770, unk1774, unk1778, unk177c, unk1780;
int unk1784, unk1788, unk178c, unk1790, unk1794, unk1798, unk179c, unk17a0;
int unk17a4, unk17a8, unk17ac, unk17b0, unk17b4, unk17b8, unk17bc, unk17c0;
int unk17c4, unk17c8, unk17cc, unk17d0, unk17d4, unk17d8, unk17dc, unk17e0;
int unk17e4, unk17e8, unk17ec, unk17f0, unk17f4, unk17f8, unk17fc, unk1800;
int unk1804, unk1808, unk180c, unk1810, unk1814, unk1818, unk181c, unk1820;
int unk1824, unk1828, unk182c, unk1830, unk1834, unk1838, unk183c, unk1840;
int unk1844, unk1848, unk184c, unk1850, unk1854, unk1858, unk185c, unk1860;
int unk1864, unk1868, unk186c, unk1870, unk1874, unk1878, unk187c, unk1880;
int unk1884, unk1888, unk188c, unk1890, unk1894, unk1898, unk189c, unk18a0;
int unk18a4, unk18a8, unk18ac, unk18b0, unk18b4, unk18b8, unk18bc, unk18c0;
int unk18c4, unk18c8, unk18cc, unk18d0, unk18d4, unk18d8, unk18dc, unk18e0;
int unk18e4, unk18e8, unk18ec, unk18f0, unk18f4, unk18f8, unk18fc, unk1900;
int unk1904, unk1908, unk190c, unk1910, unk1914, unk1918, unk191c, unk1920;
int unk1924, unk1928, unk192c, unk1930, unk1934, unk1938, unk193c, unk1940;
int unk1944, unk1948, unk194c, unk1950, unk1954, unk1958, unk195c, unk1960;
int unk1964, unk1968, unk196c, unk1970, unk1974, unk1978, unk197c, unk1980;
int unk1984, unk1988, unk198c, unk1990, unk1994, unk1998, unk199c, unk19a0;
int unk19a4, unk19a8, unk19ac, unk19b0, unk19b4, unk19b8, unk19bc, unk19c0;
int unk19c4, unk19c8, unk19cc, unk19d0, unk19d4, unk19d8, unk19dc, unk19e0;
int unk19e4, unk19e8, unk19ec, unk19f0, unk19f4, unk19f8, unk19fc, unk1a00;
int unk1a04, unk1a08, unk1a0c, unk1a10, unk1a14, unk1a18, unk1a1c, unk1a20;
int unk1a24, unk1a28, unk1a2c, unk1a30, unk1a34, unk1a38, unk1a3c, unk1a40;
int unk1a44, unk1a48, unk1a4c, unk1a50, unk1a54, unk1a58, unk1a5c, unk1a60;
int unk1a64, unk1a68, unk1a6c, unk1a70, unk1a74, unk1a78, unk1a7c, unk1a80;
int unk1a84, unk1a88, unk1a8c, unk1a90, unk1a94, unk1a98, unk1a9c, unk1aa0;
int unk1aa4, unk1aa8, unk1aac, unk1ab0, unk1ab4, unk1ab8, unk1abc, unk1ac0;
int unk1ac4, unk1ac8, unk1acc, unk1ad0, unk1ad4, unk1ad8, unk1adc, unk1ae0;
int unk1ae4, unk1ae8, unk1aec, unk1af0, unk1af4, unk1af8, unk1afc, unk1b00;
int unk1b04, unk1b08, unk1b0c, unk1b10, unk1b14, unk1b18, unk1b1c, unk1b20;
int unk1b24, unk1b28, unk1b2c, unk1b30, unk1b34, unk1b38, unk1b3c, unk1b40;
int unk1b44, unk1b48, unk1b4c, unk1b50, unk1b54, unk1b58, unk1b5c, unk1b60;
int unk1b64, unk1b68, unk1b6c, unk1b70, unk1b74, unk1b78, unk1b7c, unk1b80;
int unk1b84, unk1b88, unk1b8c, unk1b90, unk1b94, unk1b98, unk1b9c, unk1ba0;
int unk1ba4, unk1ba8, unk1bac, unk1bb0, unk1bb4, unk1bb8, unk1bbc, unk1bc0;
int unk1bc4, unk1bc8, unk1bcc, unk1bd0, unk1bd4, unk1bd8, unk1bdc, unk1be0;
int unk1be4, unk1be8, unk1bec, unk1bf0, unk1bf4, unk1bf8, unk1bfc, unk1c00;
int unk1c04, unk1c08, unk1c0c, unk1c10, unk1c14, unk1c18, unk1c1c, unk1c20;
int unk1c24, unk1c28, unk1c2c, unk1c30, unk1c34, unk1c38, unk1c3c, unk1c40;
int unk1c44, unk1c48, unk1c4c, unk1c50, unk1c54, unk1c58, unk1c5c, unk1c60;
int unk1c64, unk1c68, unk1c6c, unk1c70, unk1c74, unk1c78, unk1c7c, unk1c80;
int unk1c84, unk1c88, unk1c8c, unk1c90, unk1c94, unk1c98, unk1c9c, unk1ca0;
int unk1ca4, unk1ca8, unk1cac, unk1cb0, unk1cb4, unk1cb8, unk1cbc, unk1cc0;
int unk1cc4, unk1cc8, unk1ccc, unk1cd0, unk1cd4, unk1cd8, unk1cdc, unk1ce0;
int unk1ce4, unk1ce8, unk1cec, unk1cf0, unk1cf4, unk1cf8, unk1cfc, unk1d00;
int unk1d04, unk1d08, unk1d0c, unk1d10, unk1d14, unk1d18, unk1d1c, unk1d20;
int unk1d24, unk1d28, unk1d2c, unk1d30, unk1d34, unk1d38, unk1d3c, unk1d40;
int unk1d44, unk1d48, unk1d4c, unk1d50, unk1d54, unk1d58, unk1d5c, unk1d60;
int unk1d64, unk1d68, unk1d6c, unk1d70, unk1d74, unk1d78, unk1d7c, unk1d80;
int unk1d84, unk1d88, unk1d8c, unk1d90, unk1d94, unk1d98, unk1d9c, unk1da0;
int unk1da4, unk1da8, unk1dac, unk1db0, unk1db4, unk1db8, unk1dbc, unk1dc0;
int unk1dc4, unk1dc8, unk1dcc, unk1dd0, unk1dd4, unk1dd8, unk1ddc, unk1de0;
int unk1de4, unk1de8, unk1dec, unk1df0, unk1df4, unk1df8, unk1dfc, unk1e00;
int unk1e04, unk1e08, unk1e0c, unk1e10, unk1e14, unk1e18, unk1e1c, unk1e20;
int unk1e24, unk1e28, unk1e2c, unk1e30, unk1e34, unk1e38, unk1e3c, unk1e40;
int unk1e44, unk1e48, unk1e4c, unk1e50, unk1e54, unk1e58, unk1e5c, unk1e60;
int unk1e64, unk1e68, unk1e6c, unk1e70, unk1e74, unk1e78, unk1e7c, unk1e80;
int unk1e84, unk1e88, unk1e8c, unk1e90, unk1e94, unk1e98, unk1e9c, unk1ea0;
int unk1ea4, unk1ea8, unk1eac, unk1eb0, unk1eb4, unk1eb8, unk1ebc, unk1ec0;
int unk1ec4, unk1ec8, unk1ecc, unk1ed0, unk1ed4, unk1ed8, unk1edc, unk1ee0;
int unk1ee4, unk1ee8, unk1eec, unk1ef0, unk1ef4, unk1ef8, unk1efc, unk1f00;
int unk1f04, unk1f08, unk1f0c, unk1f10, unk1f14, unk1f18, unk1f1c, unk1f20;
int unk1f24, unk1f28, unk1f2c, unk1f30, unk1f34, unk1f38, unk1f3c, unk1f40;
int unk1f44, unk1f48, unk1f4c, unk1f50, unk1f54, unk1f58, unk1f5c, unk1f60;
int unk1f64, unk1f68, unk1f6c, unk1f70, unk1f74, unk1f78, unk1f7c, unk1f80;
int unk1f84, unk1f88, unk1f8c, unk1f90, unk1f94, unk1f98, unk1f9c, unk1fa0;
int unk1fa4, unk1fa8, unk1fac, unk1fb0, unk1fb4, unk1fb8, unk1fbc, unk1fc0;
int unk1fc4, unk1fc8, unk1fcc, unk1fd0, unk1fd4, unk1fd8, unk1fdc, unk1fe0;
int unk1fe4, unk1fe8, unk1fec, unk1ff0, unk1ff4, unk1ff8, unk1ffc, unk2000;
int unk2004, unk2008, unk200c, unk2010, unk2014, unk2018, unk201c, unk2020;
int unk2024, unk2028, unk202c, unk2030, unk2034, unk2038, unk203c, unk2040;
int unk2044, unk2048, unk204c, unk2050, unk2054, unk2058, unk205c, unk2060;
int unk2064, unk2068, unk206c, unk2070, unk2074, unk2078, unk207c, unk2080;
int unk2084, unk2088, unk208c, unk2090, unk2094, unk2098, unk209c, unk20a0;
int unk20a4, unk20a8, unk20ac, unk20b0, unk20b4, unk20b8, unk20bc, unk20c0;
int unk20c4, unk20c8, unk20cc, unk20d0, unk20d4;
struct CriticalSection { void* debugInfo; long lockCount; long recursionCount; void* owningThread; void* lockSemaphore; unsigned long spinCount; } section;
virtual ~FUN_0086dc20();
static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
FUN_0086dc20::~FUN_0086dc20() { DeleteCriticalSection(&section); }
}

// @f3 0x0086cd60 (community match, verified in this file)
namespace f3m_0086cd60 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*,long,long);
struct Lock1337 { volatile unsigned int state; unsigned long owner; bool FUN_0086cd60(); };
// @fnv 0x00aa6220
// pdb: BSReadWriteLock::TryLockForWriteAndReserve | BSReadWriteLock.obj | fnv360_0822_retail, call_dedup, low
bool Lock1337::FUN_0086cd60()
{
    bool bLocked = false;
    unsigned long dwThreadId = GetCurrentThreadId();
    if (owner == dwThreadId)
    {
        state = state + 1;
        bLocked = true;
    }
    else
    {
        unsigned int uiCompare = state;
        if (owner == 0)
        {
            unsigned int uiExchange = state | 0x80000000;
            if (InterlockedCompareExchange((volatile long*)&state, uiExchange, uiCompare) == uiCompare)
            {
                if (InterlockedCompareExchange((volatile long*)&state, 0x80000001, 0x80000000) == 0x80000000)
                {
                    bLocked = true;
                    owner = dwThreadId;
                }
                else
                {
                    bLocked = false;
                }
            }
        }
    }
    return bLocked;
}
}   // namespace f3m_0086cd60

// @f3 0x0086e5a0 (community match, verified in this file)
namespace f3m_0086e5a0 {
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*,const char*);
// pdb: NiDX9Renderer::CreateDirect3D9 | NiDX9Renderer.obj | tesv_win, call_seq, medium
namespace Batch5Dll{typedef void*(__stdcall*Create)(unsigned);extern void* DAT_010912f0;extern void*DAT_010912f4;extern Create DAT_010912f8;extern const char DAT_00e280a8[],DAT_00e28098[],DAT_00e280d8[],DAT_00e280b4[];void __cdecl FUN_00c24b70(const char*,...);int __cdecl FUN_0086e5a0(){int result=0;if(DAT_010912f4==0){Create create=DAT_010912f8;if(!create){DAT_010912f0=LoadLibraryA(DAT_00e280a8);if(!DAT_010912f0)goto failed;create=DAT_010912f8=(Create)GetProcAddress(DAT_010912f0,DAT_00e28098);if(!create)goto failed;}DAT_010912f4=create(32);if(!DAT_010912f4){failed:FUN_00c24b70(DAT_00e280d8);result=-1;}else FUN_00c24b70(DAT_00e280b4);}return result;}}
}   // namespace f3m_0086e5a0

// @f3 0x0086c7b0 (community match, verified in this file)
namespace f3m_0086c7b0 {
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned long size, unsigned long freeType);

void __cdecl FUN_006e1cd0();

struct ScrapBlock {
    unsigned int size;
    ScrapBlock* prev;
};

struct ScrapHeap {
    char* m_base;
    char* m_top;
    char* m_end;
    ScrapBlock* m_last;
    void ScrapHeap_Deallocate(void* memory);
};

// pdb: ScrapHeap::Deallocate | ScrapHeap.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void ScrapHeap::ScrapHeap_Deallocate(void* memory)
{
    if (!memory)
        return;
    ScrapBlock* block = (ScrapBlock*)((char*)memory - 8);
    if (block->size & 0x80000000)
        return;
    block->size |= 0x80000000;
    for (;;) {
        if (!m_last) {
            m_top = m_base;
            break;
        }
        if (!(m_last->size & 0x80000000)) {
            m_top = (char*)m_last + m_last->size + 8;
            break;
        }
        m_last = m_last->prev;
    }
    unsigned end=(unsigned)m_end;
    unsigned int total=end-(unsigned)m_base;
    unsigned int half=total>>1;
    unsigned base=(unsigned)m_base;
    unsigned available=end-(unsigned)m_top;
    if (available > half && total > 0x10000) {
        FUN_006e1cd0();
        base-=half;
        base+=total;
        VirtualFree((void*)base, half, 0x4000);
        m_end -= half;
    }
}
}   // namespace f3m_0086c7b0

// @f3 0x0086ce90 (community match, verified in this file)
namespace f3m_0086ce90 {
struct CriticalSection86ce90 { int unk00, unk04, unk08, unk0c, unk10, unk14; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection86ce90* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection86ce90* section);
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* attributes, unsigned int stackSize, unsigned long (__stdcall* start)(void*), void* parameter, unsigned long flags, unsigned long* threadId);
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* thread, int priority);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* thread);

unsigned long __stdcall FUN_00aa48a0(void* parameter);

struct Thread86ce90 {
    const void* table;
    CriticalSection86ce90 lock;
    void* thread;
    void* parentThread;
    unsigned long threadId;
    unsigned long parentThreadId;
    bool started;
    void FUN_0086ce90(unsigned int stackSize, int unused);
};

// pdb: BSThread::Initialize | BSThread_Xenon.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeStackSize, apName, bSuspend
void Thread86ce90::FUN_0086ce90(unsigned int stackSize, int unused) {
    if (!thread) {
        parentThread = GetCurrentThread();
        parentThreadId = GetCurrentThreadId();
        thread = CreateThread(0, stackSize, FUN_00aa48a0, this, 0, &threadId);
        EnterCriticalSection(&lock);
        if (thread) SetThreadPriority(thread, -1);
        started = true;
        ResumeThread(thread);
        LeaveCriticalSection(&lock);
    }
}
}   // namespace f3m_0086ce90

// @f3 0x0086da70 (community match, verified in this file)
#include <cstddef>
#include <string.h>
namespace f3m_0086da70 {
namespace buffer70 {void* __cdecl FUN_00c00610(void*,int,unsigned);__declspec(noreturn) void __cdecl FUN_00c06b0d(int);struct Slot {int count;char* data;};struct Counters {int first;int second;};struct Owner;struct Table {
void* unk00;
void* unk04;
void* unk08;
void* unk0c;
void* unk10;
void* unk14;
void* unk18;
void* unk1c;
void* unk20;
void* unk24;
void* unk28;
void* unk2c;
void* (__thiscall *open)(Owner*,int,int);};struct Owner {Table* table;
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
// pdb: AbstractHeap::InitHeap | AbstractHeap.obj | tesv_win, call_seq, medium
void* allocation;int unk34;int unk38;int unk3c;int unk40;char buffer[0x2000];char* cursor;Counters counts;int unk2050;int unk2054;Slot slots[16];void FUN_0086da70();};void Owner::FUN_0086da70(){allocation=table->open(this,unk14,unk1c);if(!allocation)FUN_00c06b0d(0);cursor=buffer+0x1ff8;char** dataCursor=&slots[0].data;for(int i=0;i<16;++i,dataCursor=reinterpret_cast<char**>(reinterpret_cast<char*>(dataCursor)+sizeof(Slot))){*dataCursor=buffer+i*0x200;Slot* record=reinterpret_cast<Slot*>(reinterpret_cast<char*>(dataCursor)-offsetof(Slot,data));record->count=0;}FUN_00c00610(buffer,0,0x2000);memset(&counts,0,sizeof(counts));}}
}   // namespace f3m_0086da70

// @f3 0x0086b930 (community match, verified in this file)
namespace f3m_0086b930 {


void* FUN_00c063f5(unsigned int size);

struct SizeClassHeap
{
    void* FUN_0086d7d0();
};
extern SizeClassHeap* DAT_01090fe0[];
extern unsigned int DAT_01179af4;

struct TLSThreadData
{
    unsigned field000;
unsigned field004;
unsigned field008;
unsigned field00c;
unsigned field010;
unsigned field014;
unsigned field018;
unsigned field01c;
unsigned field020;
unsigned field024;
unsigned field028;
unsigned field02c;
unsigned field030;
unsigned field034;
unsigned field038;
unsigned field03c;
unsigned field040;
unsigned field044;
unsigned field048;
unsigned field04c;
unsigned field050;
unsigned field054;
unsigned field058;
unsigned field05c;
unsigned field060;
unsigned field064;
unsigned field068;
unsigned field06c;
unsigned field070;
unsigned field074;
unsigned field078;
unsigned field07c;
unsigned field080;
unsigned field084;
unsigned field088;
unsigned field08c;
unsigned field090;
unsigned field094;
unsigned field098;
unsigned field09c;
unsigned field0a0;
unsigned field0a4;
unsigned field0a8;
unsigned field0ac;
unsigned field0b0;
unsigned field0b4;
unsigned field0b8;
unsigned field0bc;
unsigned field0c0;
unsigned field0c4;
unsigned field0c8;
unsigned field0cc;
unsigned field0d0;
unsigned field0d4;
unsigned field0d8;
unsigned field0dc;
unsigned field0e0;
unsigned field0e4;
unsigned field0e8;
unsigned field0ec;
unsigned field0f0;
unsigned field0f4;
unsigned field0f8;
unsigned field0fc;
unsigned field100;
unsigned field104;
unsigned field108;
unsigned field10c;
unsigned field110;
unsigned field114;
unsigned field118;
unsigned field11c;
unsigned field120;
unsigned field124;
unsigned field128;
unsigned field12c;
unsigned field130;
unsigned field134;
unsigned field138;
unsigned field13c;
unsigned field140;
unsigned field144;
unsigned field148;
unsigned field14c;
unsigned field150;
unsigned field154;
unsigned field158;
unsigned field15c;
unsigned field160;
unsigned field164;
unsigned field168;
unsigned field16c;
unsigned field170;
unsigned field174;
unsigned field178;
unsigned field17c;
unsigned field180;
unsigned field184;
unsigned field188;
unsigned field18c;
unsigned field190;
unsigned field194;
unsigned field198;
unsigned field19c;
unsigned field1a0;
unsigned field1a4;
unsigned field1a8;
unsigned field1ac;
unsigned field1b0;
unsigned field1b4;
unsigned field1b8;
unsigned field1bc;
unsigned field1c0;
unsigned field1c4;
unsigned field1c8;
unsigned field1cc;
unsigned field1d0;
unsigned field1d4;
unsigned field1d8;
unsigned field1dc;
unsigned field1e0;
unsigned field1e4;
unsigned field1e8;
unsigned field1ec;
unsigned field1f0;
unsigned field1f4;
unsigned field1f8;
unsigned field1fc;
unsigned field200;
unsigned field204;
unsigned field208;
unsigned field20c;
unsigned field210;
unsigned field214;
unsigned field218;
unsigned field21c;
unsigned field220;
unsigned field224;
unsigned field228;
unsigned field22c;
unsigned field230;
unsigned field234;
unsigned field238;
unsigned field23c;
unsigned field240;
unsigned field244;
unsigned field248;
unsigned field24c;
unsigned field250;
unsigned field254;
unsigned field258;
unsigned field25c;
unsigned field260;
unsigned field264;
unsigned field268;
unsigned field26c;
unsigned field270;
unsigned field274;
unsigned field278;
unsigned field27c;
unsigned field280;
unsigned field284;
unsigned field288;
unsigned field28c;
unsigned field290;
unsigned field294;
    int m_unk298;
};

__declspec(thread) TLSThreadData threadData;
struct Heap
{
    virtual void v00();
    virtual void v04();
    virtual void* Alloc(unsigned int size, int unk);
};

class CloneHeap
{
public:
    bool m_b00;
    int unk04;
    int unk08;
    Heap* m_apHeapArray[61];
    Heap* m_pDefaultHeap;
    int unk104, unk108, unk10c, unk110, unk114;
    char unk118;
    bool m_b119;
    int FUN_006e2080(Heap* heap, int value, bool* flag);
    void* FUN_0086b930(unsigned int bytes);
};

void* CloneHeap::FUN_0086b930(unsigned int bytes)
{
    if (!m_b00)
        return FUN_00c063f5(bytes);
    Heap* defHeap = m_pDefaultHeap;
    if (!defHeap)
        return FUN_00c063f5(bytes);
    unsigned int aligned = bytes;
    if (aligned <= 8)
        aligned = 8;
    else
        aligned = (aligned + 3) & ~3u;
    int threadValue = threadData.m_unk298;
    if (m_b119)
    {
        if (aligned <= 0x200)
        {
            SizeClassHeap* sizeHeap = DAT_01090fe0[aligned >> 2];
            if (sizeHeap)
            {
                void* result = sizeHeap->FUN_0086d7d0();
                if (result)
                    return result;
            }
        }
    }
    Heap* threadHeap = m_apHeapArray[threadValue];
    bool flag = false;
    int value = 0;
    for (;;)
    {
        Heap* heap = threadHeap ? threadHeap : defHeap;
        void* result = heap->Alloc(aligned, 0);
        if (result)
            return result;
        if (heap != defHeap)
        {
            result = defHeap->Alloc(aligned, (int)result);
            if (result)
                return result;
        }
        value = FUN_006e2080(threadHeap ? threadHeap : defHeap, value, &flag);
        if (!flag)
            continue;
        result = FUN_00c063f5(aligned);
        if (result)
            return result;
    }
}
}   // namespace f3m_0086b930

// @f3 0x0086c840 (community match, verified in this file)
extern const char DAT_00e27ed8[];
namespace f3m_0086c840 {
namespace CacheAllocateFast
{
extern long (__stdcall* const DAT_00d9b06c)(volatile long*,long,long);
struct RecursiveLock
{
    volatile long owner;
    unsigned int recursion;
    void FUN_00409a80(const char* name) throw();
    __forceinline void Unlock()
    {
        if(--recursion==0)
        {
            long v=owner;
            DAT_00d9b06c(&owner,0,v);
        }
    }
};
struct Entry
{
    void* memory;
    unsigned int bytes;
};
class Cache
{
public:
    Entry entries[64];
    unsigned int count;
    unsigned int cachedBytes;
    unsigned int unk208,unk20C,unk210,unk214,unk218,unk21C;
    RecursiveLock lock;
    void* ScrapHeapManager_AllocateBuffer(unsigned int bytes) throw();
    void ScrapHeapManager_ExpandBuffer(void* memory,unsigned int oldBytes,unsigned int additionalBytes) throw();
    void* FUN_0086c840(unsigned int* bytes);
};
}

// pdb: ScrapHeapManager::RequestBuffer | ScrapHeap.obj | fnv360_0822_retail, ustr, medium
// pdb params: ariRequestedInitialSize
void* CacheAllocateFast::Cache::FUN_0086c840(unsigned int* bytes)
{
    if(count==0)
        return ScrapHeapManager_AllocateBuffer(*bytes);
    lock.FUN_00409a80(DAT_00e27ed8);
    if(count==0)
    {
        void* memory=ScrapHeapManager_AllocateBuffer(*bytes);
        lock.Unlock();
        return memory;
    }
    unsigned int largestBytes=0;
    unsigned int largestIndex=0;
    for(unsigned int i=0;i<count;++i)
    {
        if(entries[i].bytes>=*bytes)
        {
            *bytes=entries[i].bytes;
            void* memory=entries[i].memory;
            --count;
            cachedBytes-=entries[i].bytes;
            if(i<count)
                entries[i]=entries[count];
            lock.Unlock();
            return memory;
        }
        if(entries[i].bytes>largestBytes)
        {
            largestBytes=entries[i].bytes;
            largestIndex=i;
        }
    }
    void* memory=entries[largestIndex].memory;
    --count;
    cachedBytes-=entries[largestIndex].bytes;
    if(largestIndex<count)
        entries[largestIndex]=entries[count];
    ScrapHeapManager_ExpandBuffer(memory,largestBytes,*bytes-largestBytes);
    lock.Unlock();
    return memory;
}
}   // namespace f3m_0086c840

// @f3 0x0086b610 (community match, verified in this file)
namespace f3m_0086b610 {
struct PoolLock { volatile int owner; };
extern PoolLock DAT_0106e5a0;
struct QueueLockCalls { void FUN_00409a80(const char*); };
struct Link { Link* next; Link* prev; void* data; };
extern Link* DAT_0106e588;
extern unsigned int DAT_0106e5a4;
extern int (__stdcall *DAT_00d9b06c)(volatile int*, int, int);
void FUN_00422ab0();
inline Link* NewLink()
{
    reinterpret_cast<QueueLockCalls*>(&DAT_0106e5a0)->FUN_00409a80(0);
    Link* n = DAT_0106e588;
    if (!n)
    {
        FUN_00422ab0();
        n = DAT_0106e588;
    }
    DAT_0106e588 = n->next;
    n->data = 0;
    n->next = 0;
    n->prev = 0;
    if (!--DAT_0106e5a4)
    {
        int owner = DAT_0106e5a0.owner;
        DAT_00d9b06c(&DAT_0106e5a0.owner, 0, owner);
    }
    return n;
}
struct Source { void** data; unsigned count; };
struct Owner {
    int unk00; int unk04; int unk08;
    Link* head; Link* tail; unsigned size;
    void FUN_0086b610(Source* source);
};
// pdb: NiBackToFrontAccumulator::RegisterObjectArray | NiBackToFrontAccumulator.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kArray
void Owner::FUN_0086b610(Source* source)
{
    unsigned count = source->count;
    for (unsigned i = 0; i < count; ++i) {
        void* item = source->data[i];
        Link* node = NewLink();
        node->data = item;
        node->next = 0;
        node->prev = tail;
        if (tail) tail->next = node; else head = node;
        ++size;
        tail = node;
    }
}
}

// @f3 0x0086d690 (community match, verified in this file)
namespace n86d690 {
struct Heap { void* FUN_0086b930(unsigned int bytes); };
extern Heap DAT_01090a78;
struct Slot {
    unsigned short v;
    static void* operator new[](unsigned int bytes) { return DAT_01090a78.FUN_0086b930(bytes); }
};
}
struct Pool86d690;
namespace n86d690 {
extern Pool86d690* DAT_01090fe0[];
extern Pool86d690* DAT_01090be0[];
}
struct Pool86d690 {
    int owner;
    struct Range { char* base; int m08; int unk0c;int unk10;int unk14;int unk18;int unk1c; int m20, m24; void Reset() { base = 0; m08 = 0; m20 = 0; m24 = 0; } } r;
    char*& base_() { return r.base; }
    int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;
    unsigned int align;
    int m44;
    n86d690::Slot* slots;
    unsigned int pageCount;
    unsigned int size;
    int m54, m58;
    void FUN_0086d630();
    Pool86d690(unsigned int a, unsigned int sz, int o);
};
// pdb: MemoryPool::MemoryPool | MemoryPool.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: aiBlockSize, aiPoolSize, apDesc
Pool86d690::Pool86d690(unsigned int a, unsigned int sz, int o)
{
    const int configuredOwner = *(volatile int*)&o;
    unsigned int configuredSize = *(volatile unsigned int*)&sz;
    *(volatile int*)&owner = configuredOwner;
    unsigned int alignment = *(volatile unsigned int*)&a;
    r.Reset();
    size = configuredSize;
    m44 = 0;
    slots = 0;
    m54 = 0;
    m58 = 0;
    configuredSize >>= 12;
    pageCount = configuredSize;
    align = alignment;
    if (alignment)
        align = (alignment + 3) & ~3u;
    FUN_0086d630();
    if (r.base) {
        slots = new n86d690::Slot[configuredSize];
        for (unsigned int i = 0; i < pageCount; ++i)
            slots[i].v = 0xffff;
        n86d690::DAT_01090fe0[align >> 2] = this;
        unsigned int count = size >> 24;
        if (size & 0xffffff)
            ++count;
        unsigned int idx = (unsigned int)r.base >> 24;
        for (unsigned int i = 0; i < count; ++i)
            n86d690::DAT_01090be0[idx + i] = this;
    }
}

// @f3 0x0086bcb0 (community match, verified in this file)
namespace f3m_0086bcb0 {
struct Heap { void* FUN_0086b930(unsigned int n); };
extern Heap DAT_01090a78;
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct FUN_0086cb70 {
    int unk00, unk04, unk08, unk0c;
    FUN_0086cb70();
    static void* operator new(unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p);
};
struct Map {
    __declspec(noalias) void FUN_00bea7b0(unsigned int key, FUN_0086cb70** out);
    void FUN_004d4260(unsigned int key, FUN_0086cb70* value);
    __forceinline FUN_0086cb70* Find(unsigned int key) { FUN_0086cb70* found = 0; FUN_00bea7b0(key, &found); return found; }
};
struct Owner {
    char unk000[0x104];
    Map map;
    __forceinline FUN_0086cb70* Create() { return new FUN_0086cb70; }
    FUN_0086cb70* FUN_0086bcb0();
};
// pdb: MemoryManager::GetThreadScrapHeap | MemoryManager.obj | fnv360_0822_retail, call_seq, medium
FUN_0086cb70* Owner::FUN_0086bcb0()
{
    unsigned int thread = GetCurrentThreadId();
    {
        FUN_0086cb70* found = 0;
        map.FUN_00bea7b0(thread, &found);
        if (found)
            return found;
    }
    {
        FUN_0086cb70* made = new FUN_0086cb70;
        map.FUN_004d4260(thread, made);
        return made;
    }
}
}

// @f3 0x0086d240 (community match, verified in this file)
namespace f3m_0086d240 {
namespace workerB86d240 {
extern long (__stdcall* DAT_00d9b06c)(volatile long*, long, long);
struct Lock {
    volatile long value;
    int depth;
    void FUN_00409a80(const char*);
    void Release() {
        if (--depth == 0)
            DAT_00d9b06c(&value, 0, value);
    }
};
struct Guard {
    Lock* lock;
    Guard(Lock* l, const char* source) : lock(l) {
        l->FUN_00409a80(source);
    }
    ~Guard() { lock->Release(); }
};
struct Owner {
    int unk00;
    char* begin;
    int unk08;
    unsigned bytes;
    char* volatile current;
    int count;
    int unk18, unk1c;
    Lock lock;
    void* FUN_0086d240(unsigned, int);
};

// pdb: ZeroOverheadHeap::Allocate | ZeroOverheadHeap.obj | tesv_win, objrun_open, low
void* Owner::FUN_0086d240(unsigned size, int unused) {
    unsigned available = bytes;
    if (!available)
        return (void*)available;
    unsigned int result = 0;
    if (current + size + 4 < begin + available) {
        Guard guard(&lock, reinterpret_cast<const char*>(result));
        *(unsigned*)current = size;
        result = reinterpret_cast<unsigned int>(current);
        ++count;
        result += 4;
        current = reinterpret_cast<char*>(result + size);
    }
    return reinterpret_cast<void*>(result);
}
}
}   // namespace f3m_0086d240

// @f3 0x0086bd50 (community match, verified in this file)
#include <string.h>

namespace f3m_0086bd50 {
void* __cdecl FUN_00c00610(void* dest, int value, unsigned int size);
void __cdecl FUN_0086cbc0();
void __cdecl FUN_0086d9a0();
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Elem86 { ~Elem86(); static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); } };
struct MapBase {
    virtual ~MapBase();
    unsigned int hashSize;
    void** buckets;
    unsigned int count;
    void FUN_006bd950();
};
MapBase::~MapBase() { if (buckets) DAT_01090a78.FUN_0086ba60(buckets); }
struct MapItem86 { MapItem86* next; unsigned int key; Elem86* val; };
struct FUN_0086bbe0 : public MapBase {
    virtual ~FUN_0086bbe0();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    __declspec(noinline) void FUN_0089a5d0(void** cur, unsigned int* key, Elem86** val)
    {
        MapItem86* item = (MapItem86*)*cur;
        *key = item->key;
        *val = item->val;
        if (item->next) { *cur = item->next; return; }
        unsigned int i = KeyToHashIndex(item->key);
        for (++i; i < hashSize; i++) { item = (MapItem86*)buckets[i]; if (item) { *cur = item; return; } }
        *cur = 0;
    }
    void* GetFirst86() {
        unsigned int cnt = hashSize;
        unsigned int i = 0;
        if (cnt <= 0) return 0;
        void** table = buckets;
        void** p = table;
        do {
            if (*p) return table[i];
            ++i; ++p;
        } while (i < cnt);
        return 0;
    }
};
FUN_0086bbe0::~FUN_0086bbe0() { FUN_006bd950(); }
struct Poly86 { virtual ~Poly86(); };
struct FUN_0086bd50 {
    bool m_b00;
    unsigned short m_s02;
    unsigned short m_s04;
    void** m_ap1;
    char m_buf[0xf8];
    FUN_0086bbe0 m_map;
    void** m_ap2;
    ~FUN_0086bd50();
};
// pdb: MemoryManager::~MemoryManager | MemoryManager.obj | fnv360_0822_retail, caller_sim, low
FUN_0086bd50::~FUN_0086bd50()
{
    FUN_0086bbe0* const pkMap = &m_map;
    void* cur;
    Elem86* val;
    cur = pkMap->GetFirst86();
    if (cur) {
        do {
            unsigned int key;
            pkMap->FUN_0089a5d0((void**)&cur, &key, &val);
            if (val) delete val;
        } while (cur);
    }
    pkMap->FUN_006bd950();
    FUN_0086cbc0();
    FUN_0086d9a0();
    FUN_00c00610(m_buf, 0, 0xf8);
    m_b00 = false;
    if (m_ap1) {
        for (unsigned short i = 0; i < m_s02; ++i) {
            Poly86* obj = (Poly86*)m_ap1[i];
            if (obj) delete obj;
            m_ap1[i] = 0;
        }
        void** tmp1 = m_ap1;
        DAT_01090a78.FUN_0086ba60(tmp1);
    }
    if (m_ap2) {
        for (unsigned short i = 0; i < m_s04; ++i) {
            Poly86* obj = (Poly86*)m_ap2[i];
            if (obj) delete obj;
            m_ap2[i] = 0;
        }
        void** tmp2 = m_ap2;
        DAT_01090a78.FUN_0086ba60(tmp2);
    }
}
}

// @f3 0x0086d7d0 (community match, verified in this file)
extern const char DAT_00e2801c[];
namespace f3m_0086d7d0 {
struct Lock {
    void FUN_00409a80(const char* arg);
    long volatile owner;
    int count;
};
struct Node {
    void* f00;
    Node* f04;
};
struct Pool {
    int unk00;
    void* base;
    Node* head;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Lock m_lock;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    unsigned int elemSize;
    unsigned int maxv;
    unsigned short* counts;
    unsigned int count;
    int unk50;
    int allocCount;
    int total;
    void FUN_0086d770();
    void Unlink(Node* node)
    {
        head = node->f04;
        if (node->f00 != 0) ((Node*)node->f00)->f04 = node->f04;
        if (node->f04 != 0) node->f04->f00 = node->f00;
    }
    void* FUN_0086d7d0();
};
// pdb: MemoryPool::Allocate | MemoryPool.obj | fnv360_0822_retail, ustr, medium
// pdb params: requested
void* Pool::FUN_0086d7d0()
{
    Lock* lk = &m_lock;
    lk->FUN_00409a80(DAT_00e2801c);
    int index = -1;
    if (head == 0) {
        for (unsigned int i = 0; i < count; ++i) {
            if (counts[i] == 0xffff) { index = (int)i; break; }
        }
        if (index == -1) {
            if (--lk->count == 0) { const long owner = lk->owner; f3m_0086d930::DAT_00d9b06c(&lk->owner, 0, owner); }
            return 0;
        }
        unsigned int perPage = 0x1000 / elemSize;
        char* page = (char*)base + (index << 12);
        if (VirtualAlloc(page, 0x1000, 0x1000, 4) == 0) {
            if (--lk->count == 0) { const long owner = lk->owner; f3m_0086d930::DAT_00d9b06c(&lk->owner, 0, owner); }
            return 0;
        }
        counts[index] = 0;
        for (unsigned int j = 0; j < perPage; ++j) {
            Node* node = (Node*)(page + j * elemSize);
            node->f00 = 0;
            node->f04 = head;
            if (head != 0) head->f00 = node;
            ++allocCount;
            head = node;
        }
        ++total;
        if (total > maxv) maxv = total;
    }
    Node* result = 0;
    if (head != 0) {
        result = head;
        Unlink(head);
        unsigned int page = ((unsigned int)result - (unsigned int)base) >> 12;
        --allocCount;
        ++counts[page];
    }
    if (--lk->count == 0) { const long owner = lk->owner; f3m_0086d930::DAT_00d9b06c(&lk->owner, 0, owner); }
    return result;
}








}   // namespace f3m_0086d7d0

// @f3 0x0087a310 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct ZItem;
struct ZRC {
    virtual ~ZRC();
    virtual void DeleteThis();
    long ref;
    void DecRef() { if (!InterlockedDecrement(&ref)) DeleteThis(); }
};
struct ZVal : ZRC {
    virtual void vx2();
    virtual void vx3();
    virtual void vx4();
    virtual void vx5();
    virtual void vx6();
    virtual void vx7();
    virtual void vx8();
    virtual void vx9();
    virtual void vx10();
    virtual void vx11();
    virtual void vx12();
    virtual void vx13();
    virtual void vx14();
    virtual void vx15();
    virtual void vx16();
    virtual void vx17();
    virtual void vx18();
    virtual void vx19();
    virtual void vx20();
    virtual void vx21();
    virtual void vx22();
    virtual void vx23();
    virtual void vx24();
    virtual void vx25();
    virtual void vx26();
    virtual void vx27();
    virtual void vx28();
    virtual void vx29();
    virtual void vx30();
    virtual void vx31();
    virtual void vx32();
    virtual void vx33();
    virtual void vx34();
    virtual void vx35();
    virtual void vx36();
    virtual void vx37();
    virtual void vx38();
    virtual void vx39();
    virtual void vx40();
    virtual unsigned vA4();
    virtual void vx42();
    virtual void vx43();
    virtual ZItem* vB0(unsigned i);
    virtual ZItem* vB4();

};
struct ZItem { int unk00; int unk04; int unk08; int unk0C; ZRC* m10; };
struct ZPtr {
    ZRC* p;
    ~ZPtr() { if (p) p->DecRef(); }
};
struct ZPtr4 {
    ZRC* p[4];
    ~ZPtr4() {
        ZRC** pp = p + 4;
        int n = 3;
        do {
            ZRC* q = *--pp;
            if (q) q->DecRef();
        } while (--n >= 0);
    }
};
struct ZCom {
    virtual void __stdcall cx0();
    virtual void __stdcall cx1();
    virtual unsigned long __stdcall Release();
    virtual void __stdcall cx3();
    virtual void __stdcall cx4();
    virtual void __stdcall cx5();
    virtual void __stdcall cx6();
    virtual void __stdcall cx7();
    virtual void __stdcall cx8();
    virtual void __stdcall cx9();
    virtual void __stdcall cx10();
    virtual void __stdcall cx11();
    virtual void __stdcall cx12();
    virtual void __stdcall cx13();
    virtual void __stdcall cx14();
    virtual void __stdcall cx15();
    virtual void __stdcall cx16();
    virtual void __stdcall cx17();
    virtual void __stdcall cx18();
    virtual void __stdcall cx19();
    virtual void __stdcall cx20();
    virtual void __stdcall cx21();
    virtual void __stdcall cx22();
    virtual void __stdcall cx23();
    virtual void __stdcall cx24();
    virtual void __stdcall cx25();
    virtual void __stdcall cx26();
    virtual void __stdcall cx27();
    virtual void __stdcall cx28();
    virtual void __stdcall cx29();
    virtual void __stdcall cx30();
    virtual void __stdcall cx31();
    virtual void __stdcall cx32();
    virtual void __stdcall cx33();
    virtual void __stdcall cx34();
    virtual void __stdcall cx35();
    virtual void __stdcall cx36();
    virtual void __stdcall cx37();
    virtual void __stdcall cx38();
    virtual void __stdcall cx39();
    virtual void __stdcall cx40();
    virtual void __stdcall cx41();
    virtual void __stdcall cx42();
    virtual void __stdcall cx43();
    virtual void __stdcall cx44();
    virtual void __stdcall cx45();
    virtual void __stdcall cx46();
    virtual void __stdcall cx47();
    virtual void __stdcall cx48();
    virtual void __stdcall cx49();
    virtual void __stdcall cx50();
    virtual void __stdcall cx51();
    virtual void __stdcall cx52();
    virtual void __stdcall cx53();
    virtual void __stdcall cx54();
    virtual void __stdcall cx55();
    virtual void __stdcall cx56();
    virtual void __stdcall cx57();
    virtual void __stdcall cx58();
    virtual void __stdcall cx59();
    virtual void __stdcall cx60();
    virtual void __stdcall cx61();
    virtual void __stdcall cx62();
    virtual void __stdcall cx63();
    virtual void __stdcall cx64();
    virtual void __stdcall cx65();
    virtual void __stdcall cx66();
    virtual void __stdcall cx67();
    virtual void __stdcall cx68();
    virtual void __stdcall cx69();
    virtual void __stdcall cx70();
    virtual void __stdcall cx71();
    virtual void __stdcall cx72();
    virtual void __stdcall cx73();
    virtual void __stdcall cx74();
    virtual void __stdcall cx75();
    virtual void __stdcall cx76();
    virtual void __stdcall cx77();
    virtual void __stdcall cx78();
    virtual void __stdcall cx79();
    virtual void __stdcall cx80();
    virtual void __stdcall cx81();
    virtual void __stdcall cx82();
    virtual void __stdcall cx83();
    virtual void __stdcall cx84();
    virtual void __stdcall cx85();
    virtual void __stdcall cx86();
    virtual void __stdcall cx87();
    virtual void __stdcall cx88();
    virtual void __stdcall cx89();
    virtual void __stdcall cx90();
    virtual void __stdcall cx91();
    virtual void __stdcall cx92();
    virtual void __stdcall cx93();
    virtual void __stdcall cx94();
    virtual void __stdcall cx95();
    virtual void __stdcall cx96();
    virtual void __stdcall cx97();
    virtual void __stdcall cx98();
    virtual void __stdcall cx99();
    virtual void __stdcall v190(unsigned a,unsigned b,unsigned c,unsigned d);
    virtual void __stdcall cy101();
    virtual void __stdcall cy102();
    virtual void __stdcall cy103();
    virtual void __stdcall v1A0(unsigned a);

};
struct ZB {
    virtual ~ZB();
    virtual void bx1();
    virtual void bx2();
    virtual void bx3();
    virtual void bx4();
    virtual void bx5();
    virtual void bx6();
    virtual void bx7();
    virtual void bx8();
    virtual void bx9();
    virtual void bx10();
    virtual void bx11();
    virtual void bx12();
    virtual void bx13();
    virtual void bx14();
    virtual void bx15();
    virtual void bx16();
    virtual void bx17();
    virtual void bx18();
    virtual void bx19();
    virtual void bx20();
    virtual void bx21();
    virtual void bx22();
    virtual void bx23();
    virtual void bx24();
    virtual void bx25();
    virtual void bx26();
    virtual void bx27();
    virtual void bx28();
    virtual void bx29();
    virtual void bx30();
    virtual void bx31();
    virtual void bx32();
    virtual void bx33();
    virtual void bx34();
    virtual void bx35();
    virtual void bx36();
    virtual void bx37();
    virtual void bx38();
    virtual void bx39();
    virtual void bx40();
    virtual void bx41();
    virtual void bx42();
    virtual void bx43();
    virtual void bx44();
    virtual void bx45();
    virtual void bx46();
    virtual void bx47();
    virtual void bx48();
    virtual void bx49();
    virtual void bx50();
    virtual void bx51();
    virtual void bx52();
    virtual void bx53();
    virtual void bx54();

    virtual void v55(unsigned a, unsigned b);
};
struct ZV { virtual ~ZV(); };
struct ZV2 { virtual ~ZV2(); virtual void v1(); virtual void v2(unsigned a); };
struct ZPlain { void FUN_00883ac0(); };
struct ZMgr { void FUN_0086ba60(unsigned v); };
struct ZLink { int unk0; int unk4; int unk8; ZLink* next; };
struct ZChain { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; ZChain* next; };
struct ZNode { ZNode* next; unsigned key; ZChain* val; };

void FUN_0089ec10(void* p, unsigned size);
void FUN_0089e890(void* p);
void FUN_0085b8c0();
void FUN_0088bcc0();
void FUN_00882980();
void FUN_00884eb0(void* p);
void NiStream_UnregisterLoader(void (*f)());
void FUN_00e24890();
void FUN_008626b0();
extern ZMgr g_mgr;
extern ZLink* g_freeList;
extern unsigned g_count;
extern ZRC* g_arr[256];
extern ZPtr g_ptrs[256];

template<int T> struct ZMapB {
    virtual ~ZMapB() { RemoveAll(); FUN_0089e890(table); }
    virtual unsigned Hash(unsigned key);
    unsigned size;
    ZNode** table;
    unsigned count;
    void RemoveAll();
    __declspec(noinline) void GetNext(ZNode*& pos, unsigned& key, ZVal*& val) {
        ZNode* n = pos;
        key = n->key;
        val = (ZVal*)n->val;
        if (n->next) { pos = n->next; return; }
        unsigned i = Hash(n->key);
        for (++i; i < size; i++) {
            n = table[i];
            if (n) { pos = n; return; }
        }
        pos = 0;
    }
    void Set(unsigned key, ZChain* c);
    void Remove(unsigned key);
    ZNode* First() {
        for (unsigned i = 0; i < size; i++)
            if (table[i]) return table[i];
        return 0;
    }
    void GetNextI(ZNode*& pos, unsigned& key, ZChain*& val) {
        ZNode* n = pos;
        key = n->key;
        val = n->val;
        if (n->next) { pos = n->next; return; }
        unsigned i = Hash(n->key);
        for (++i; i < size; i++) {
            n = table[i];
            if (n) { pos = n; return; }
        }
        pos = 0;
    }
    ZNode* Next(ZNode* n) {
        ZNode* r = n->next;
        if (r) return r;
        for (unsigned i = Hash(n->key) + 1; i < size; i++)
            if (table[i]) return table[i];
        return 0;
    }
};
template<int T> struct ZMapD : ZMapB<T> {
    ~ZMapD() { this->RemoveAll(); }
};
template<int T> struct ZBuf {
    virtual ~ZBuf() { FUN_0089e890(buf); }
    void* buf;
    int unk08;
    int unk0C;
};
struct Z900 {
    ~Z900() { Fn(); }
    void Fn();
    int unk000;
    int unk004;
    int unk008;
};
struct Z90c {
    ~Z90c() { Fn(); }
    void Fn();
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
};

struct ZBase { virtual ~ZBase(); };

struct FUN_0087a310 : ZBase {
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
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    ZCom* m288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    ZMapD<0> m610;
    ZLink* m620;
    unsigned m624;
    int unk628;
    int unk62C;
    ZPtr m630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    unsigned m6e8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    unsigned m700[4][22];
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    ZPtr4 m870;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    ZMapD<1> m890;
    int unk8A0;
    int unk8A4;
    unsigned m8a8;
    ZV2* m8ac;
    unsigned m8b0;
    unsigned m8b4;
    ZB* m8b8;
    ZV* m8bc;
    ZV* m8c0;
    ZV* m8c4;
    ZPlain* m8c8;
    ZMapD<2> m8cc;
    ZMapD<3> m8dc;
    ZMapD<4> m8ec;
    ZPtr m8fc;
    Z900 m900;
    Z90c m90c;
    unsigned ma80;
    unsigned ma84;
    unsigned ma88;
    int unkA8C;
    void* ma90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    ZBuf<2> mad4;
    ZBuf<0> mae4;
    ZBuf<1> maf4;
    ZBuf<0> mb04;
    ZMapD<5> mb14;
    ~FUN_0087a310() throw();
    void FUN_0087a230();
    void FUN_00873bf0();
    void FUN_00873c60();
};

// pdb: NiDX9Renderer::~NiDX9Renderer | NiDX9Renderer.obj | tesv_win, caller_sim, low
FUN_0087a310::~FUN_0087a310() throw()
{
    if (m288) {
        if (m8b8) {
            for (unsigned i = 0; i < g_count; i++)
                m8b8->v55(i, 0);
        }
        for (unsigned i = 0; i < m6e8; i++)
            m288->v190(i, 0, 0, 0);
        m288->v1A0(0);
    }
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 22; k++)
            g_mgr.FUN_0086ba60(m700[j][k]);
        if (m870.p[j]) {
            m870.p[j]->DecRef();
            m870.p[j] = 0;
        }
    }
    ZLink* l = m620;
    while (l) {
        ZLink* nx = l->next;
        ZLink* t = g_freeList;
        g_freeList = l;
        l->next = t;
        l = nx;
    }
    m620 = 0;
    m624 = 0;
    for (ZLink* q = g_freeList; q; ) {
        ZLink* nx = q->next;
        FUN_0089ec10(q, 0x10);
        q = nx;
    }
    g_freeList = 0;
    ZNode* n = m610.First();
    while (n) {
        unsigned key;
        ZChain* c;
        m610.GetNextI(n, key, c);
        while (c) {
            ZChain* nx = c->next;
            if (nx) m610.Set(key, nx);
            else m610.Remove(key);
            FUN_0089ec10(c, 0x24);
            c = nx;
        }
    }
    FUN_0085b8c0();
    this->FUN_0087a230();
    FUN_0088bcc0();
    FUN_00882980();
    m8cc.RemoveAll();
    m8dc.RemoveAll();
    m8ec.RemoveAll();
    FUN_00884eb0(this);
    ZNode* pos = m890.First();
    unsigned key;
    ZVal* val;
    while (pos) {
        val = 0;
        m890.GetNext(pos, key, val);
        if (val) {
            ZVal* v = val;
            for (unsigned i = 0; i < v->vA4(); i++) {
                ZItem* it = v->vB0(i);
                if (it && it->m10) {
                    it->m10->DecRef();
                    it->m10 = 0;
                }
            }
            ZItem* last = v->vB4();
            if (last && last->m10) {
                last->m10->DecRef();
                last->m10 = 0;
            }
            v->DecRef();
        }
    }
    m890.RemoveAll();
    ZNode* cur = mb14.First();
    while (cur) {
        unsigned k2;
        ZChain* v;
        mb14.GetNextI(cur, k2, v);
        g_mgr.FUN_0086ba60((unsigned)v);
    }
    m8a8 = 0;
    delete m8bc;
    m8bc = 0;
    if (m8c0) {
        delete m8c0;
        m8c0 = 0;
    }
    if (m8ac) {
        m8ac->v2(m8b0);
        m8ac->v2(m8b4);
        delete m8ac;
        m8ac = 0;
    }
    delete m8b8;
    m8b8 = 0;
    delete m8c4;
    m8c4 = 0;
    ZPlain* pl = m8c8;
    if (pl) {
        pl->FUN_00883ac0();
        FUN_0089ec10(pl, 0x23c);
    }
    m8c8 = 0;
    for (unsigned i = 0; i < 256; i++) {
        if (g_arr[i]) {
            g_arr[i]->DecRef();
            g_arr[i] = 0;
        }
    }
    if (m288) {
        m288->Release();
        m288 = 0;
    }
    g_mgr.FUN_0086ba60(ma80);
    g_mgr.FUN_0086ba60(ma84);
    g_mgr.FUN_0086ba60(ma88);
    FUN_0089e890(ma90);
    this->FUN_00873bf0();
    this->FUN_00873c60();
    NiStream_UnregisterLoader(FUN_00e24890);
    FUN_008626b0();
}

// @f3 0x0086c710 (community match, verified in this file)
namespace f3m_0086c710 {
namespace f3m_0086c710 {
struct VmMgr86c710 {
    void __thiscall ScrapHeapManager_ExpandBuffer(void* base, unsigned int oldSize, unsigned int addSize);
};
VmMgr86c710* __cdecl FUN_006e1cd0();

struct Hdr86c710 {
    unsigned int size;
    Hdr86c710* prev;
};

struct Arena86c710 {
    char* base;
    char* cur;
    char* end;
    Hdr86c710* lastHdr;

    void* ScrapHeap_Allocate(unsigned int size, unsigned int align);
};

// pdb: ScrapHeap::Allocate | ScrapHeap.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void* Arena86c710::ScrapHeap_Allocate(unsigned int size, unsigned int align) {
    char* c = cur;
    char* payload = c + 8;
    Hdr86c710* hdr;
    unsigned int rem;
    if (align != 0 && (rem = (align - 1) & (unsigned int)payload) != 0) {
        payload += align - rem;
        hdr = (Hdr86c710*)(payload - 8);
    } else {
        hdr = (Hdr86c710*)c;
    }
    char* nextCur = payload + size;
    if (nextCur >= end) {
        unsigned int curCap = end - base;
        if (curCap < 0x400000) {
            unsigned int needed = nextCur - end;
            unsigned int addCap = curCap;
            unsigned int totalCap = curCap * 2;
            while (addCap < needed) {
                totalCap *= 2;
                addCap = totalCap - curCap;
            }
            FUN_006e1cd0()->ScrapHeapManager_ExpandBuffer(base, curCap, addCap);
            end += addCap;
        }
    }
    if (nextCur < end) {
        hdr->size = size;
        hdr->prev = lastHdr;
        cur = nextCur;
        lastHdr = hdr;
        return payload;
    }
    return 0;
}
}
}   // namespace f3m_0086c710

// @f3 0x0086caa0 (community match, verified in this file)
namespace f3m_0086caa0 {
namespace Recycle86caa0 {
struct Recycler {int unk000;
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
Recycler():unk200(0),unk204(0),unk220(0),unk224(0){} void* operator new(unsigned);void FUN_0086c9a0(void*,unsigned);};extern Recycler* DAT_01090bdc;
struct Heap {void* FUN_0086b930(unsigned);};extern Heap DAT_01090a78;
void* Recycler::operator new(unsigned size){return DAT_01090a78.FUN_0086b930(size);}
struct Object {char* first;int count;char* last;void FUN_0086caa0();};
// pdb: ScrapHeap::~ScrapHeap | ScrapHeap.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: TESObjectREFR::AddMasterParticleAddonNodes)
void Object::FUN_0086caa0(){if(!DAT_01090bdc)DAT_01090bdc=new Recycler;DAT_01090bdc->FUN_0086c9a0(first,last-first);first=0;count=0;}
}
}   // namespace f3m_0086caa0

// @f3 0x0086ca30 (community match, verified in this file)
extern const char DAT_00e27f20[];
namespace f3m_0086ca30 {
namespace f3m_0086ca30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
struct Lock86ca30 {
    volatile long owner;
    long count;
    void FUN_00409a80(const char* name);
    void Unlock() { if (--count == 0) { long o = owner; InterlockedCompareExchange(&owner, 0, o); } }
};
struct Entry86ca30 { void* ptr; unsigned int size; };
struct ScrapHeapManager86ca30 {
    Entry86ca30 entries[0x40];
    unsigned int count;
    unsigned int total;
    char pad208[0x18];
    Lock86ca30 lock;
    void FUN_0086ca30();
};
// pdb: ScrapHeapManager::FreeAllBuffers | ScrapHeap.obj | fnv360_0822_retail, ustr, medium
void ScrapHeapManager86ca30::FUN_0086ca30()
{
    if (count == 0)
        return;
    lock.FUN_00409a80(DAT_00e27f20);
    for (unsigned int i = 0; i < count; ++i)
        VirtualFree(entries[i].ptr, 0, 0x8000);
    count = 0;
    total = 0;
    lock.Unlock();
}
}
}   // namespace f3m_0086ca30

// @f3 0x0086c280 (community match, verified in this file)
extern float DAT_00f7544c;
namespace f3m_0086c280 {
namespace f3m_0086c280 {

extern void (__stdcall* DAT_00d9b074)(unsigned long);

struct Timer86c280 {
    bool paused00;
    float fixedStep04;
    float accum08;
    float scaledValue0c;
    unsigned int lastTime10;
    unsigned int pauseOffset14;
    bool useGlobal18;
    bool zeroDelta19;

    void FUN_0086c280(unsigned int currentTime);
};

// pdb: BSTimer::Update | BSTimer.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: aiTime
void Timer86c280::FUN_0086c280(unsigned int currentTime)
{
    unsigned int adjustedTime = currentTime - pauseOffset14;
    if (paused00) {
        scaledValue0c = 0.0f;
        return;
    }

    if (fixedStep04 != 0.0f) {
        float total = accum08 + fixedStep04;
        unsigned int whole = (unsigned int)total;
        accum08 = total - (float)whole;
        adjustedTime = lastTime10 + whole;
        scaledValue0c = fixedStep04 * 0.0010000000474974513;
    } else {
        unsigned int diff = adjustedTime - lastTime10;
        if (diff == 0) {
            diff = 1;
            zeroDelta19 = true;
        } else {
            zeroDelta19 = false;
        }
        if (diff > 0xa6) {
            diff = 0xa6;
        } else if (diff < 0xa) {
            DAT_00d9b074(0xa - diff);
            diff = 0xa;
        }
        scaledValue0c = (float)diff * 0.0010000000474974513;
    }

    lastTime10 = adjustedTime;
    scaledValue0c *= DAT_00f7544c;
}

}
}   // namespace f3m_0086c280

// @f3 0x0086e080 (community match, verified in this file)
namespace f3m_0086e080 {
namespace Stats407 {
extern void (__stdcall * const DAT_00d9b09c)(void*);
extern void (__stdcall * const DAT_00d9b0a0)(void*);
struct Stream { virtual void slot00(); virtual void slot04(); virtual unsigned int write(const void*,unsigned int); };
struct Node { int unk00,unk04,unk08; Node* next; };
struct Bucket { Node* head; int unk04; };
struct Record { unsigned int bytes,count; };
struct Owner {
int unk00,unk04; unsigned int stride;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
Bucket buckets[1024];
int unk2044; Node* overflow;
int unk204c;
int unk2050;
int unk2054;
int unk2058;
int unk205c;
int unk2060;
int unk2064;
int unk2068;
int unk206c;
int unk2070;
int unk2074;
int unk2078;
int unk207c;
int unk2080;
int unk2084;
int unk2088;
int unk208c;
int unk2090;
int unk2094;
int unk2098;
int unk209c;
int unk20a0;
int unk20a4;
int unk20a8;
int unk20ac;
int unk20b0;
int unk20b4;
int unk20b8;
int unk20bc;
int unk20c0;
int unk20c4;
int unk20c8;
int unk20cc;
int unk20d0;
int unk20d4;
int lock;
unsigned int FUN_0086e080(Stream*);
__forceinline Node*& head(unsigned int bytes) { int index=bytes/stride-1; if(index>=1024) return overflow; return buckets[index].head; }
};
// pdb: VirtualFree | virtualfree.obj | fnv360_0822_debug, objopen_prop, low
// pdb params: lpAddress, dwSize, dwFreeType
unsigned int Owner::FUN_0086e080(Stream* stream) {
 if(!stream) return 0;
 DAT_00d9b09c(&lock);
 int count=1025;
 unsigned int total=stream->write(&count,4);
 for(int i=0;i<count;++i) {
  Record r; r.bytes=stride*(i+1); r.count=0;
  for(Node* node=head(r.bytes);node;node=node->next) ++r.count;
  total+=stream->write(&r,8);
 }
 DAT_00d9b0a0(&lock);
 return total;
}
}

}   // namespace f3m_0086e080

// @f3 0x0086bae0 (community match, verified in this file)
#include <string.h>
namespace f3m_0086bae0 {
struct Heap {
    unsigned FUN_0086b8c0(void* block);
    void* FUN_0086b930(unsigned size);
    void FUN_0086ba60(void* block);
    void* FUN_0086bae0(void* oldBlock, unsigned newSize);
};
extern void FUN_00c06546(void* oldBlock, unsigned newSize);
// pdb: MemoryManager::Reallocate | MemoryManager.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apMem, apMem, aSize, aSize, apFileName, aiLine, apFunction
void* Heap::FUN_0086bae0(void* oldBlock, unsigned newSize)
{
    void* result = 0;
    unsigned oldSize = FUN_0086b8c0(oldBlock);
    if (oldSize) {
        result = FUN_0086b930(newSize);
        unsigned limit = *(volatile unsigned*)&newSize;
        if(oldSize > limit) oldSize = limit;
        memcpy(result, oldBlock, oldSize);
        FUN_0086ba60(oldBlock);
    } else {
        FUN_00c06546(oldBlock, newSize);
    }
    return result;
}


}   // namespace f3m_0086bae0

// @f3 0x0086cc50 (community match, verified in this file)
namespace f3m_0086cc50 {
namespace f3m_0086cc50 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* dst, long xchg, long cmp);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ms);
struct FUN_0086cc50_c {
    volatile long count;
    unsigned long owner;
    void FUN_0086cc50();
};
// pdb: BSReadWriteLock::LockForWrite | BSReadWriteLock.obj | fnv360_0822_retail, call_gap, medium
void FUN_0086cc50_c::FUN_0086cc50()
{
    unsigned long tid = GetCurrentThreadId();
    if (owner == tid) {
        count++;
    } else {
        long v = count & 0x0fffffff;
        long w = count | (long)0x80000000;
        while (InterlockedCompareExchange(&count, w, v) != v) {
            Sleep(0);
            v = count & 0x0fffffff;
            w = count | (long)0x80000000;
        }
        while (InterlockedCompareExchange(&count, (long)0x80000001, (long)0x80000000) != (long)0x80000000) {
            Sleep(0);
        }
        owner = tid;
    }
}
}
}   // namespace f3m_0086cc50

// @f3 0x0086e220 (community match, verified in this file)
namespace f3m_0086e220 {
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned long, unsigned long);
extern void (__stdcall* DAT_00d9b09c)(void*);
extern void (__stdcall* DAT_00d9b0a0)(void*);
namespace f3m_0086e220 {
class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void FUN_0086e590(unsigned int size, MemoryHeapType* type);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
};
class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
    __forceinline void AddBlock(HeapFreeBlock* block)
    {
        if (pTail)
        {
            HeapFreeBlock* tail = pTail;
            block->m_pNextFree = tail;
            HeapFreeBlock* previous = tail->m_pPrevFree;
            block->m_pPrevFree = previous;
            if (previous)
                previous->m_pNextFree = block;
            tail->m_pPrevFree = block;
            pTail = block;
        }
        else
        {
            pHead = block;
            pTail = block;
        }
    }
};
class HeapBlockList
{
  public:
    int iCount;
    HeapFreeList* pFirst;
};
class AbstractHeap
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual unsigned int CreateMorePages(void* pointer, unsigned int size, unsigned int alignment);
    const char* pName;
    int iDefaultAlignment;
    unsigned int MinFreeBlockSize;
    unsigned int iPageSize;
    unsigned int MemHeapSize;
    unsigned int iInitialSize;
    unsigned int iCurrentSize;
    unsigned int iWastedMemory;
    int iMemAllocated;
    int iMemAllocatedHigh;
    int iBlockMemAllocated;
    char* pMemHeap;
    int iNumBlocks;
    MemoryBlockHeader* pBlockHead;
    MemoryBlockHeader* pBlockTail;
    int iNumFreeBlocks;
    HeapFreeList pSmallFreeList[1024];
    HeapFreeList* pLastSmallList;
    HeapFreeList LargeFreeList;
    MemoryBlockHeader** pDelayedFreeBlocksA;
    unsigned int iNextDelayedFreeIndex;
    HeapBlockList pSubBuckets[16];
    unsigned char CriticalSectionO[24];

    __forceinline HeapFreeList* GetFreeList(unsigned int size)
    {
        int bucket = size / iDefaultAlignment - 1;
        return bucket >= 1024 ? &LargeFreeList : &pSmallFreeList[bucket];
    }
    __forceinline int GetSubBucket(int size)
    {
        if (size > 4096)
            return -1;
        return (size / iDefaultAlignment - 1) / 64;
    }
    __forceinline bool IsLastInSubBucket(int bucket, HeapFreeList* list)
    {
        return bucket < 16 ? list >= pSubBuckets[bucket + 1].pFirst : list >= pLastSmallList;
    }
    __forceinline void PushBlock(MemoryBlockHeader* block)
    {
        if (pBlockTail)
        {
            block->SetPrevious(pBlockTail);
            pBlockTail = block;
        }
        else
        {
            pBlockHead = block;
            pBlockTail = pBlockHead;
        }
        ++iNumBlocks;
    }
    void* FUN_0086e220(unsigned int size);
    __forceinline void IncrementSubBucket(int size)
    {
        int bucket = GetSubBucket(size);
        if (bucket != -1)
            ++pSubBuckets[bucket].iCount;
    }
    __declspec(noinline) void FUN_0086daf0(HeapFreeBlock* block);
    void FUN_0086db90(HeapFreeList* list, HeapFreeBlock* block);
    void FUN_0086de90(HeapFreeBlock* block);
};

void AbstractHeap::FUN_0086daf0(HeapFreeBlock* block)
{
    block->m_pPrevFree = 0;
    block->m_pNextFree = 0;
    block->SetFree(true);
    HeapFreeList* list = GetFreeList(block->GetSize());
    list->AddBlock(block);
    ++iNumFreeBlocks;
    IncrementSubBucket(block->GetSize());
}

void* AbstractHeap::FUN_0086e220(unsigned int size)
{
    DAT_00d9b09c(&CriticalSectionO);
    if (size <= 8)
        size = 8;
    else
        size = (size + iDefaultAlignment - 1) & ~(iDefaultAlignment - 1);
    unsigned int uiBlockSize;
    void* pMemory = 0;
    HeapFreeList* pSizeClassFreeList = GetFreeList(size);
    if (!pSizeClassFreeList->pTail && pSizeClassFreeList != &LargeFreeList)
    {
        pSizeClassFreeList += MinFreeBlockSize / iDefaultAlignment;
        if (pSizeClassFreeList > pLastSmallList)
        {
            pSizeClassFreeList = &LargeFreeList;
        }
        else
        {
            int iSubBucketIndex = 0;
            int iFirstBucket = GetSubBucket(size + MinFreeBlockSize);
            for (iSubBucketIndex = iFirstBucket; iSubBucketIndex < 16 && !pSizeClassFreeList->pTail; ++iSubBucketIndex)
            {
                if (pSubBuckets[iSubBucketIndex].iCount)
                {
                    if (pSubBuckets[iSubBucketIndex].pFirst > pSizeClassFreeList)
                        pSizeClassFreeList = pSubBuckets[iSubBucketIndex].pFirst;
                    while (!pSizeClassFreeList->pTail && !IsLastInSubBucket(iSubBucketIndex, pSizeClassFreeList))
                        ++pSizeClassFreeList;
                }
            }
            if (iSubBucketIndex == 16)
                pSizeClassFreeList = &LargeFreeList;
        }
    }
    if (pSizeClassFreeList->pTail)
    {
        HeapFreeBlock* pBlock = pSizeClassFreeList->pHead;
        while (pBlock)
        {
            uiBlockSize = pBlock->GetSize();
            int iExtra = uiBlockSize - size;
            if (iExtra == 0 || iExtra >= (int)MinFreeBlockSize)
            {
                HeapFreeBlock* pNewBlock = 0;
                bool bDecommitted = pBlock->IsDecommitted();
                FUN_0086db90(pSizeClassFreeList, pBlock);
                if (iExtra)
                {
                    if (bDecommitted)
                    {
                        unsigned int iCommitSize = size + 24;
                        bool bCommitted = VirtualAlloc(pBlock, iCommitSize, 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            FUN_0086daf0(pBlock);
                            DAT_00d9b0a0(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                    }
                    pNewBlock = (HeapFreeBlock*)((char*)pBlock + size + sizeof(MemoryBlockHeader));
                    unsigned int iRemainingSize = uiBlockSize - (size + sizeof(MemoryBlockHeader));
                    pNewBlock->m_pNextFree = 0;
                    pNewBlock->m_pPrevFree = 0;
                    pNewBlock->FUN_0086e590(iRemainingSize, 0);
                    pNewBlock->SetPrevious(pBlock);
                    if (pBlock == pBlockTail)
                        pBlockTail = pNewBlock;
                    else
                    {
                        MemoryBlockHeader* pNext = pBlock->GetNext();
                        pNext->SetPrevious(pNewBlock);
                    }
                    ++iNumBlocks;
                    FUN_0086daf0(pNewBlock);
                    FUN_0086de90(pNewBlock);
                }
                else
                {
                    if (bDecommitted)
                    {
                        bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            FUN_0086daf0(pBlock);
                            DAT_00d9b0a0(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                    }
                }
                pBlock->SetSize(size);
                pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
                iBlockMemAllocated += pBlock->GetTotalSize();
                break;
            }
            pBlock = pBlock->m_pPrevFree;
        }
    }
    if (!pMemory)
    {
        unsigned int uiBlockAllocationSizeItem = size + sizeof(MemoryBlockHeader);
        unsigned int iNeededSize = iMemAllocated + uiBlockAllocationSizeItem;
        if (iPageSize && iNeededSize > iCurrentSize && iNeededSize <= MemHeapSize)
            iCurrentSize += CreateMorePages(pMemHeap, iCurrentSize, uiBlockAllocationSizeItem);
        if (iNeededSize <= iCurrentSize)
        {
            MemoryBlockHeader* pBlock = (MemoryBlockHeader*)(pMemHeap + iMemAllocated);
            if (iPageSize)
            {
                bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                if (!bCommitted)
                {
                    DAT_00d9b0a0(&CriticalSectionO);
                    return 0;
                }
            }
            pBlock->FUN_0086e590(size, 0);
            PushBlock(pBlock);
            iMemAllocated += uiBlockAllocationSizeItem;
            if (iMemAllocated > iMemAllocatedHigh)
                iMemAllocatedHigh = iMemAllocated;
            pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
            iBlockMemAllocated += uiBlockAllocationSizeItem;
        }
    }
    DAT_00d9b0a0(&CriticalSectionO);
    return pMemory;
}
}
}   // namespace f3m_0086e220

// @f3 0x00863ee0 (community match, verified in this file)
extern char DAT_00e2652c;
namespace f3m_00863ee0 {
namespace cleanup_863ee0 {
struct Object {
    void* table;
    void FUN_00845a20();
    void FUN_00863ee0();
};
void Object::FUN_00863ee0()
{
    table = &DAT_00e2652c;
    FUN_00845a20();
}
}
}   // namespace f3m_00863ee0

// @f3 0x0086b120 (community match, verified in this file)
extern char DAT_00e27b64;
namespace f3m_0086b120 {
namespace cleanup_86b120 {
struct Object {
    void* table;
    void FUN_00825830();
    void FUN_0086b120();
};
// pdb: NiLODData::~NiLODData | NiLODData.obj | fnv360_0822_retail, objrun_prop, medium
void Object::FUN_0086b120()
{
    table = &DAT_00e27b64;
    FUN_00825830();
}
}
}   // namespace f3m_0086b120

// @f3 0x0086c3e0 (community match, verified in this file)
extern char DAT_00e27ebc;
namespace f3m_0086c3e0 {
struct X86c3e0 { void* vptr; void*& FUN_0086c3e0(); };
// pdb: BSCoreMessage::BSCoreMessage | BSCoreMessage.obj | fnv360_0721_beta, objrun_open, low
void*& X86c3e0::FUN_0086c3e0() { return *(void**)this = &DAT_00e27ebc; }
}   // namespace f3m_0086c3e0

// @f3 0x00865d20 (community match, verified in this file)
extern int FUN_00e26cac;
namespace f3m_00865d20 {
namespace Dtor_00865d20
{

struct Owner
{
    void FUN_0086b510();
    void FUN_00865d20();
};

// pdb: NiAlphaAccumulator::~NiAlphaAccumulator | NiAlphaAccumulator.obj | fnv360_0822_retail, call_gap, high
void Owner::FUN_00865d20()
{
    *(int*)this = (int)&FUN_00e26cac;
    FUN_0086b510();
}
}
}   // namespace f3m_00865d20

// @f3 0x008662f0 (community match, verified in this file)
namespace f3m_008662f0 {
void FUN_00866140();
void FUN_00866240();

void FUN_008662f0()
{
    FUN_00866140();
    FUN_00866240();
}
}   // namespace f3m_008662f0

// @f3 0x0086c400 (community match, verified in this file)
namespace f3m_0086c400 {
// pdb: BSCoreMessage::Warning | BSCoreMessage.obj | fnv360_0721_beta, objrun_open, low, conflict (skyrim: BSCoreMessage::Message)
// pdb params: apMessage
int __stdcall FUN_0086c400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)
{
    return 0;
}
}   // namespace f3m_0086c400

// @f3 0x0086d3f0 (community match, verified in this file)
namespace f3m_0086d3f0 {
namespace fn_0086d3f0 {
struct MemoryHeap {
    int m_poolEntries[2108];
    bool m_statsDisabled;
    void FUN_0086df90(void* stats, bool detailed);
    void FUN_0086d3f0(void* stats, bool detailed);
};
void MemoryHeap::FUN_0086d3f0(void* stats, bool detailed) {
    FUN_0086df90(stats, (!m_statsDisabled) & detailed);
}
}
}   // namespace f3m_0086d3f0

// @f3 0x0086d470 (community match, verified in this file)
namespace f3m_0086d470 {
namespace f3m_0086d470 {
struct AddressRange {
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    unsigned int size;
    unsigned int unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int start;

    int FUN_0086d470(unsigned int address);
};

// pdb: MemoryPool::RemovePoolAsBlockSize | MemoryPool.obj | fnv360_0822_debug, objrun_open, low
// pdb params: aiSize
int AddressRange::FUN_0086d470(unsigned int address)
{
    return address >= start && address < start + size;
}
}
}   // namespace f3m_0086d470

// @f3 0x0086d440 (community match, verified in this file)
namespace f3m_0086d440 {
namespace f3m_0086d440 {
struct Stream {
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08(void* buffer, int size);
};
inline void WriteZero(Stream* stream) {
    int zero = 0;
    stream->Vf08(&zero, 4);
}
struct Obj {
    void FUN_0086e150(Stream* stream, int value);
    void FUN_0086d440(Stream* stream, int value);
    bool Flag() const { return *((const char*)this + 0x20f0) != 0; }
};
// pdb: MemoryPool::AddPoolAsBlockSize | MemoryPool.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: MemoryHeap::Deallocate)
// pdb params: aiSize
void Obj::FUN_0086d440(Stream* stream, int value) {
    if (!Flag()) FUN_0086e150(stream, value);
    else WriteZero(stream);
}
}
}   // namespace f3m_0086d440

// @f3 0x0086d410 (community match, verified in this file)
namespace f3m_0086d410 {
namespace f3m_0086d410 {
struct Stream {
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08(void* buffer, int size);
};
inline void WriteZero(Stream* stream) {
    int zero = 0;
    stream->Vf08(&zero, 4);
}
struct Obj {
    void FUN_0086e080(Stream* stream);
    void FUN_0086d410(Stream* stream);
    bool Flag() const { return *((const char*)this + 0x20f0) != 0; }
};
// pdb: MemoryPool::PlatformDecommitPage | MemoryPool.obj | fnv360_0822_debug, objrun_open, low, conflict (bridge: BSListBase<OEI::IO::IO_Request *>::`scalar deleting destructor')
// pdb params: auiPageIndex, apPageAddress
void Obj::FUN_0086d410(Stream* stream) {
    if (!Flag()) FUN_0086e080(stream);
    else WriteZero(stream);
}
}
}   // namespace f3m_0086d410
