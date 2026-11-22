#include <math.h>
// src/f3staging/f3blk_00600000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0061e7d0 (community match, verified in this file)
namespace f3m_0061e7d0 {
struct QSnd {
    int id;
    bool flag;
    int unk08;
    QSnd() { id = -1; flag = false; unk08 = 0; }
    QSnd& operator=(const QSnd& o) { id = o.id; flag = o.flag; unk08 = o.unk08; return *this; }
    bool FUN_00bd00c0(int);
};
struct QSndMgr {
    QSnd FUN_00bcfcd0(const char*, int);
};
extern QSndMgr* DAT_011790c8;

// pdb: InterfaceManager::PlayMenuSound | InterfaceManager.obj | fnv360_0822_retail, strset, low
// pdb params: aeMenuSound
void FUN_0061e7d0(int type)
{
    QSnd snd;
    switch (type) {
    case -1:
        return;
    case 36:
        snd = DAT_011790c8->FUN_00bcfcd0("UIMenuMode", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 4:
        snd = DAT_011790c8->FUN_00bcfcd0("UIMenuFocus", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 10:
    case 19:
        snd = DAT_011790c8->FUN_00bcfcd0("UIPopUpMessageGeneral", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 3:
        snd = DAT_011790c8->FUN_00bcfcd0("UIMenuPrevNext", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 1:
        snd = DAT_011790c8->FUN_00bcfcd0("UIMenuOK", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 8:
        snd = DAT_011790c8->FUN_00bcfcd0("UIPopUpQuestNew", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 2:
    case 20:
        snd = DAT_011790c8->FUN_00bcfcd0("UIMenuCancel", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    case 21:
        snd = DAT_011790c8->FUN_00bcfcd0("UILevelUp", 0x121);
        snd.FUN_00bd00c0(0);
        break;
    }
}
}   // namespace f3m_0061e7d0
