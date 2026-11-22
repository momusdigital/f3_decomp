// src/f3staging/f3blk_005a0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005a2aa0 (community match, verified in this file)
namespace f3m_005a2aa0 {
extern "C" void* __cdecl _alloca(unsigned int size);

struct FileObj;

struct CompFullName { int unk00; int unk04; int unk08; };
struct CompDesc { int unk00; int unk04; };
struct CompTexture { int unk00; int unk04; int unk08; int unk0c; };

struct ThisObj {
    virtual void v00(FileObj* file);
    virtual void v01(FileObj* file);
    virtual void v02(FileObj* file);
    virtual void v03(FileObj* file);
    virtual void v04(FileObj* file);
    virtual void v05(FileObj* file);
    virtual void v06(FileObj* file);
    virtual void v07(FileObj* file);
    virtual void v08(FileObj* file);
    virtual void v09(FileObj* file);
    virtual void v10(FileObj* file);
    virtual void v11(FileObj* file);
    virtual void v12(FileObj* file);
    virtual void v13(FileObj* file);
    virtual void v14(FileObj* file);
    virtual void v15(FileObj* file);
    virtual void v16(FileObj* file);
    virtual void v17(FileObj* file);
    virtual void v18(FileObj* file);
    virtual void v19(FileObj* file);
    virtual void v20(FileObj* file);
    virtual void v21(FileObj* file);
    virtual void v22(FileObj* file);
    virtual void v23(FileObj* file);
    virtual void v24(FileObj* file);
    virtual void v25(FileObj* file);
    virtual void v26(FileObj* file);
    virtual void v27(FileObj* file);
    virtual void v28(FileObj* file);
    virtual void v29(FileObj* file);
    virtual void v30(FileObj* file);
    virtual void v31(FileObj* file);
    virtual void v32(FileObj* file);
    virtual void v33(FileObj* file);
    virtual void v34(FileObj* file);
    virtual void v35(FileObj* file);
    virtual void v36(FileObj* file);
    virtual void v37(FileObj* file);
    virtual void v38(FileObj* file);
    virtual void v39(FileObj* file);
    virtual void v40(FileObj* file);
    virtual void v41(FileObj* file);
    virtual void v42(FileObj* file);
    virtual void v43(FileObj* file);
    virtual void v44(FileObj* file);
    virtual void v45(FileObj* file);
    virtual void v46(FileObj* file);
    virtual void v47(FileObj* file);
    virtual void v48(FileObj* file);
    virtual void v49(FileObj* file);
    virtual void v50(FileObj* file);
    virtual void v51(FileObj* file);
    virtual void v52(FileObj* file);
    virtual void v53(FileObj* file);
    virtual void v54(FileObj* file);
    virtual void v55(FileObj* file);
    virtual void v56(FileObj* file);
    virtual void v57(FileObj* file);
    virtual void v58(FileObj* file);
    virtual void v59(FileObj* file);
    virtual void v60(FileObj* file);
    virtual void v61(FileObj* file);
    virtual void v62(FileObj* file);
    virtual void v63(FileObj* file);
    virtual void v64(FileObj* file);
    virtual void v65(FileObj* file);
    virtual void v66(FileObj* file);
    virtual void v67(FileObj* file);
    virtual void v68(FileObj* file);
    virtual void v69(FileObj* file);
    virtual void v70(FileObj* file);
    virtual void v71(FileObj* file);
    virtual void v72(FileObj* file);
    virtual void v73(FileObj* file);
    virtual void v74(FileObj* file);
    virtual void v75(FileObj* file);
    virtual void v76(FileObj* file);
    virtual void v77(char* buf);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CompFullName fullName;
    CompDesc description;
    CompTexture icon;
    BSStringT<char> animName;
    void FUN_00454410(FileObj* file);
    void TESForm_SetInitialized(char flag);
    bool FUN_005a2aa0(FileObj* file);
};

struct FileObj {
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
    char TESFile_GetTESForm();
    int TESFile_GetTESChunk();
    char TESFile_NextChunk();
    void FUN_00447d60(char* buf, int len);
};

void FUN_00453570(CompDesc* desc, FileObj* file);
void FUN_00456560(CompFullName* name, FileObj* file);
void TESTexture_LoadTextureChunk(CompTexture* icon, FileObj* file);

// pdb: ActorValueInfo::Load | ActorValue.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool ThisObj::FUN_005a2aa0(FileObj* file)
{
    if (file->TESFile_GetTESForm() != 'Y')
        return false;

    FUN_00454410(file);
    TESForm_SetInitialized(0);

    int type = file->TESFile_GetTESChunk();
    if (type != 0) {
        do {
            switch (type) {
            case 0x444e424f:
                v56(file);
                break;
            case 0x44494445: {
                char* buf = (char*)_alloca(file->unk25c);
                file->FUN_00447d60(buf, 0x200);
                v77(buf);
                break;
            }
            case 0x43534544:
                FUN_00453570(this ? &description : 0, file);
                break;
            case 0x4c4c5546:
                FUN_00456560(this ? &fullName : 0, file);
                break;
            case 0x4e4f4349:
                TESTexture_LoadTextureChunk(this ? &icon : 0, file);
                break;
            case 0x4d414e41:
                if (file->unk25c) {
                    char* p = (char*)_alloca(file->unk25c);
                    file->FUN_00447d60(p, 0);
                    animName.Set(p, 0);
                } else
                    animName.Set("", 0);
                break;
            }
        } while (file->TESFile_NextChunk() && (type = file->TESFile_GetTESChunk()) != 0);
    }
    return true;
}
}   // namespace f3m_005a2aa0
