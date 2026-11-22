// src/f3staging/f3blk_00540000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005447c0 (community match, verified in this file)
namespace f3m_005447c0 {
extern "C" void* __cdecl _alloca(unsigned int);

class TESFile
{
public:
    int GetChunkType();
    int GetChunkID();
    void GetChunkData(void* data, unsigned int size);
    void GetChunkValue(unsigned int* value);
    bool Continue();
};

class TESModel
{
public:
    void Prepare(TESFile* file);
    bool FUN_005447c0(TESFile* file);
};

class TESModelData
{
public:
    void Apply(void* data, unsigned int size, unsigned short flags);
};

class TESModelValue
{
public:
    void Set(unsigned int* value);
};

extern void FUN_00456560(void* path, TESFile* file);
extern void FUN_00458210(void* target, TESFile* file);

// pdb: BGSHeadPart::Load | BGSHeadPart.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool TESModel::FUN_005447c0(TESFile* file)
{
    if (file->GetChunkType() != 9)
        return false;

    Prepare(file);

    int chunk = file->GetChunkID();
    while (chunk)
    {
        switch (chunk)
        {
        case 0x41544144:
            file->GetChunkData((char*)this + 0x44, 1);
            break;
        case 0x44494445:
        {
            char* data = (char*)_alloca(*(unsigned int*)((char*)file + 0x25c));
            file->GetChunkData(data, 0x200);
            typedef void (__thiscall *ApplyData)(TESModel*, char*);
            ((ApplyData)(*(void***)this)[0x134 / 4])(this, data);
            break;
        }
        case 0x444e424f:
        {
            typedef void (__thiscall *ApplyBounds)(TESModel*, TESFile*);
            ((ApplyBounds)(*(void***)this)[0xe0 / 4])(this, file);
            break;
        }
        case 0x4d414e48:
        {
            int value = 0;
            file->GetChunkValue((unsigned int*)&value);
            int copy = value;
            ((TESModelValue*)((char*)this + 0x48))->Set((unsigned int*)&copy);
            break;
        }
        case 0x4c4c5546:
            FUN_00456560(this ? (char*)this + 0x18 : 0, file);
            break;
        case 0x53444f4d:
        {
            int size = *(int*)((char*)file + 0x25c);
            char* data = (char*)_alloca(size);
            file->GetChunkData(data, size);
            ((TESModelData*)((char*)this + 0x24))->Apply(
                data, size, *(unsigned short*)((char*)file + 0x254));
            break;
        }
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            FUN_00458210(this ? (char*)this + 0x24 : 0, file);
            break;
        }

        if (!file->Continue())
            break;
        chunk = file->GetChunkID();
    }

    return true;
}
}   // namespace f3m_005447c0

// @f3 0x00550f10 (community match, verified in this file)
namespace f3m_00550f10 {

extern "C" void* __cdecl _alloca(unsigned int);

namespace f3m_00550f10 {

class Reader
{
public:
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18,
        unk1c, unk20, unk24, unk28, unk2c, unk30,
        unk34, unk38, unk3c, unk40, unk44, unk48,
        unk4c, unk50, unk54, unk58, unk5c, unk60,
        unk64, unk68, unk6c, unk70, unk74, unk78,
        unk7c, unk80, unk84, unk88, unk8c, unk90,
        unk94, unk98, unk9c, unka0, unka4, unka8,
        unkac, unkb0, unkb4, unkb8, unkbc, unkc0,
        unkc4, unkc8, unkcc, unkd0, unkd4, unkd8,
        unkdc, unke0, unke4, unke8, unkec, unkf0,
        unkf4, unkf8, unkfc, unk100, unk104, unk108,
        unk10c, unk110, unk114, unk118, unk11c, unk120,
        unk124, unk128, unk12c, unk130, unk134, unk138,
        unk13c, unk140, unk144, unk148, unk14c, unk150,
        unk154, unk158, unk15c, unk160, unk164, unk168,
        unk16c, unk170, unk174, unk178, unk17c, unk180,
        unk184, unk188, unk18c, unk190, unk194, unk198,
        unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0,
        unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8,
        unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0,
        unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8,
        unk1fc, unk200, unk204, unk208, unk20c, unk210,
        unk214, unk218, unk21c, unk220, unk224, unk228,
        unk22c, unk230, unk234, unk238, unk23c, unk240,
        unk244, unk248, unk24c, unk250, unk254, unk258;
    unsigned int unk25c;
    int TESFile_GetTESForm();
    unsigned int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    void FUN_00447d60(void* dest, unsigned int size);
};

void __cdecl FUN_00456560(void* target, Reader* reader);
void __cdecl TESTexture_LoadTextureChunk(void* target, Reader* reader);
void __cdecl FUN_0045bab0b(void* target, Reader* reader);

class Target
{
public:
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
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void vE0(Reader* reader);
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v134(char* buffer);
    int unk04, unk08, unk0c, unk10, unk14, unk18,
        unk1c, unk20, unk24, unk28, unk2c, unk30,
        unk34;
    void FUN_00454410(Reader* reader);
    bool FUN_00550f10(Reader* reader);
};

// pdb: TESEyes::Load | TESEyes.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Target::FUN_00550f10(Reader* reader)
{
    if (reader->TESFile_GetTESForm() != 0xb)
        return false;
    FUN_00454410(reader);
    for (;;)
    {
        int type = reader->TESFile_GetTESChunk();
        if (!type)
            break;
        switch (type)
        {
        case 0x44494445: // EDID
            {
                char* buffer = (char*)_alloca(reader->unk25c);
                reader->FUN_00447d60(buffer, 0x200);
                v134(buffer);
            }
            break;
        case 0x41544144: // DATA
            reader->FUN_00447d60(&unk30, 1);
            break;
        case 0x444e424f: // OBND
            vE0(reader);
            break;
        case 0x4e4f4349: // ICON
            // a null form has no icon block of its own: pass this (null) instead
            TESTexture_LoadTextureChunk(this ? &unk24 : (void*)this, reader);
            break;
        case 0x4c4c5546: // FULL
            FUN_00456560(this ? &unk18 : 0, reader);
            break;
        }
        if (!reader->TESFile_NextChunk())
            break;
    }
    return true;
}

}
}   // namespace f3m_00550f10

// @f3 0x00552310 (community match, verified in this file)
namespace f3m_00552310 {
extern "C" void* __cdecl _alloca(unsigned int);
class RecordFile {
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
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned TESFile_GetTESForm();
    int TESFile_GetTESChunk();
    bool TESFile_NextChunk();
    void FUN_00447d60(void*, unsigned);
};
class LoaderBase {
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
    virtual void ReadBounds(RecordFile*);
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
    unsigned unk04, unk08, unk0c, unk10, unk14;
    void FUN_00454410(RecordFile*);
};
struct LoaderFullName { void* componentVtable; unsigned unk04, unk08; };
struct LoaderModel { void* componentVtable; unsigned unk04, unk08, unk0c, unk10, unk14; };
struct LoaderIcon { void* componentVtable; unsigned unk04, unk08; };
void __cdecl FUN_00458210(LoaderModel*, RecordFile*);
void __cdecl TESTexture_LoadTextureChunk(LoaderIcon*, RecordFile*);
void __cdecl FUN_00456560(LoaderFullName*, RecordFile*);
class FormIterWrapper : public LoaderBase, public LoaderFullName, public LoaderModel, public LoaderIcon {
public:
    unsigned char data;
    bool FUN_00552310(RecordFile*);
};
// pdb: TESHair::Load | TESHair.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool FormIterWrapper::FUN_00552310(RecordFile* file)
{
    if (file->TESFile_GetTESForm() != 10) return false;
    FUN_00454410(file);
    int type = file->TESFile_GetTESChunk();
    while (type) {
        switch (type) {
        case 0x444e424f:
            ReadBounds(file);
            break;
        case 0x44494445: {
            char* name = (char*)_alloca(file->unk25c);
            file->FUN_00447d60(name, 0x200);
            SetEditorID(name);
            break;
        }
        case 0x41544144:
            file->FUN_00447d60(&data, 1);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            FUN_00458210(static_cast<LoaderModel*>(this), file);
            break;
        case 0x4e4f4349:
            TESTexture_LoadTextureChunk(static_cast<LoaderIcon*>(this), file);
            break;
        case 0x4c4c5546:
            FUN_00456560(static_cast<LoaderFullName*>(this), file);
            break;
        }
        if (!file->TESFile_NextChunk()) break;
        type = file->TESFile_GetTESChunk();
    }
    return true;
}
}   // namespace f3m_00552310
