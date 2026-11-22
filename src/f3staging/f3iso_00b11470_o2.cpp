#include <new>
// src/f3staging/f3iso_00b11470_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00b11470 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b11470 (community match, verified in this file)
namespace f3m_00b11470 {
namespace Sb11470_ {

struct RenderedTex;

struct TexSlot
{
    void* FUN_00b22310();
    void FUN_00b223d0(int type);
    RenderedTex* FUN_00b22300();
};

struct SpaceMgr
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200;
    TexSlot depthTex;

    RenderedTex* FUN_00b11470();
};

// pdb: ImageSpaceManager::GetDepthRenderedTexture | ImageSpaceManager.obj | fnv360_0822_retail, caller_sim, low
RenderedTex* SpaceMgr::FUN_00b11470()
{
    if (!depthTex.FUN_00b22310())
        depthTex.FUN_00b223d0(0x20);
    return depthTex.FUN_00b22300();
}

}
}   // namespace f3m_00b11470
