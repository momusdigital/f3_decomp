// src/f3staging/f3blk_00640000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006453a0 (community match, verified in this file)
namespace f3m_006453a0 {
struct Tile6453A0 {void FUN_00bee190(unsigned,float,int);};
// pdb: HUDMainMenu::SetBrightness | HUDMainMenu.obj | fnv360_0721_beta, objrun, medium
// pdb params: apTile, aeBrightness
void FUN_006453a0(Tile6453A0* tile,unsigned mode){switch(mode){case 2:tile->FUN_00bee190(0xff5,255.0f,1);break;case 1:case 3:tile->FUN_00bee190(0xff5,175.0f,1);break;case 4:tile->FUN_00bee190(0xff5,44.0f,1);case 5:tile->FUN_00bee190(0xff5,100.0f,1);break;default:tile->FUN_00bee190(0xff5,255.0f,1);}}
}   // namespace f3m_006453a0

// @f3 0x00657580 (community match, verified in this file)
namespace f3m_00657580 {
namespace f3m_00657580 {

struct Tile {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    Tile* unk28;
    double FUN_00becf40(void* trait);
    bool FUN_00becf80(int trait);
    bool FUN_00bee190(void* trait, float value, int update);
};

struct SubList60 {
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    void* FUN_00636fb0(Tile* tile);
    void FUN_00655800(void (__cdecl *callback)(Tile*, int), int first, int last);
};

struct SubList90 {
    bool FUN_00655250(Tile* tile);
    void FUN_006569d0(int flag);
    void FUN_00655950(Tile* tile, int mode);
    int FUN_006557c0();
    void FUN_00655800(void (__cdecl *callback)(Tile*), int first, int last);
};

struct Obj51d {
    bool FUN_0051dfb0();
};

struct Player {
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
    virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10c();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13c();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16c();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19c();
    virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc();
    virtual void v1c0(); virtual void v1c4(); virtual void v1c8(); virtual void v1cc();
    virtual void v1d0(); virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec();
    virtual void v1f0(); virtual void v1f4(); virtual void v1f8(); virtual void v1fc();
    virtual void v200(); virtual void v204(); virtual void v208(); virtual void v20c();
    virtual void v210(); virtual void v214(); virtual void v218(); virtual void v21c();
    virtual void v220(); virtual void v224(); virtual void v228(); virtual void v22c();
    virtual void v230(); virtual void v234(); virtual void v238(); virtual void v23c();
    virtual void v240(); virtual void v244(); virtual void v248(); virtual void v24c();
    virtual void v250(); virtual void v254(); virtual void v258(); virtual void v25c();
    virtual void v260(); virtual void v264(); virtual void v268(); virtual void v26c();
    virtual void v270(); virtual void v274(); virtual void v278(); virtual void v27c();
    virtual void v280(); virtual void v284(); virtual void v288(); virtual void v28c();
    virtual void v290(); virtual void v294(); virtual void v298(); virtual void v29c();
    virtual void v2a0(); virtual void v2a4(); virtual void v2a8(); virtual void v2ac();
    virtual void v2b0(); virtual void v2b4(); virtual void v2b8(); virtual void v2bc();
    virtual void v2c0(); virtual void v2c4(); virtual void v2c8(); virtual void v2cc();
    virtual void v2d0(); virtual void v2d4(); virtual void v2d8(); virtual void v2dc();
    virtual void v2e0(); virtual void v2e4(); virtual void v2e8(); virtual void v2ec();
    virtual void v2f0(); virtual void v2f4(); virtual void v2f8(); virtual void v2fc();
    virtual void v300(); virtual void v304(); virtual void v308(); virtual void v30c();
    virtual void v310(); virtual void v314(); virtual void v318(); virtual void v31c();
    virtual void v320(); virtual void v324(); virtual void v328(); virtual void v32c();
    virtual void v330(); virtual void v334(); virtual void v338(); virtual void v33c();
    virtual void v340(); virtual void v344(); virtual void v348(); virtual void v34c();
    virtual void v350(); virtual void v354(); virtual void v358(); virtual void v35c();
    virtual void v360(); virtual void v364(); virtual void v368(); virtual void v36c();
    virtual void v370(); virtual void v374(); virtual void v378(); virtual void v37c();
    virtual void v380(); virtual void v384(); virtual void v388(); virtual void v38c();
    virtual void Set(void* item, float val);
    virtual void v394(); virtual void v398(); virtual void v39c();
    virtual void v3a0(); virtual void v3a4(); virtual void v3a8(); virtual void v3ac();
    virtual void v3b0(); virtual void v3b4(); virtual void v3b8(); virtual void v3bc();
    virtual void v3c0(); virtual void v3c4(); virtual void v3c8(); virtual void v3cc();
    virtual void v3d0(); virtual void v3d4(); virtual void v3d8(); virtual void v3dc();
    virtual void v3e0(); virtual void v3e4(); virtual void v3e8(); virtual void v3ec();
    virtual void v3f0(); virtual void v3f4(); virtual void v3f8(); virtual void v3fc();
    virtual void v400(); virtual void v404(); virtual void v408(); virtual void v40c();
    virtual void v410(); virtual void v414(); virtual void v418(); virtual void v41c();
    virtual void v420(); virtual void v424(); virtual void v428(); virtual void v42c();
    virtual void v430(); virtual void v434(); virtual void v438(); virtual void v43c();
    virtual void v440(); virtual void v444(); virtual void v448(); virtual void v44c();
    virtual void v450(); virtual void v454(); virtual void v458(); virtual void v45c();
    virtual void v460(); virtual void v464(); virtual void v468(); virtual void v46c();
    virtual void v470(); virtual void v474(); virtual void v478();
    virtual double Get(void* item, bool& flag);

    Obj51d* Actor_GetClass(void* p);
};

struct Setting {
    int* FUN_004241e0();
};

extern Player* DAT_0107a104;
extern Setting DAT_00f5ee80;
extern const double DAT_00dbeb78;
extern void* DAT_01076904;
extern void* DAT_010768e8;
extern void* DAT_01076900;

extern void __cdecl FUN_0061a730(int a);
extern void __cdecl FUN_00657540(Tile* tile);
extern void __cdecl LevelUpMenu_ResetSkillsFunc(Tile* tile, int val);

class Manager {
public:
    int unk00;
    Tile* unk04;
    int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    int unk28;
    int unk2C; int unk30; int unk34; int unk38;
    int unk3C; int unk40; int unk44;
    Tile* unk48;
    Tile* unk4C;
    int unk50[4];
    SubList60 sub60;
    SubList90 sub90;

    void FUN_00656ed0(Tile* tile);
    bool FUN_00654d30();
    void FUN_006551a0(Tile* tile);
    void FUN_00656640(int idx);

    bool FUN_00657580(int action, Tile* tile);
};

// pdb: LevelUpMenu::DoClick | LevelUpMenu.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiID, apTarget
bool Manager::FUN_00657580(int action, Tile* tile) {
    switch (action) {
    case 11: {
        if (sub90.FUN_00655250(tile)) {
            sub90.FUN_00655950(tile, 2);
            FUN_00656ed0(tile);
        } else if (tile->FUN_00becf40(DAT_01076904) == DAT_00dbeb78) {
            sub90.FUN_006569d0(1);
            sub90.FUN_00655950(tile, 0);
            FUN_00656ed0(tile);
        }
        unk50[unk28] = sub90.FUN_006557c0();
        unk04->FUN_00bee190(DAT_010768e8, (float)unk50[unk28], 1);
        return FUN_00654d30();
    }
    case 12:
    case 13: {
        if (tile->FUN_00becf80(0xfa3)) {
            void* item = sub60.FUN_00636fb0(tile->unk28);
            action = (action != 12) ? 1 : -1;
            unk50[unk28] += action;
            unk04->FUN_00bee190(DAT_010768e8, (float)unk50[unk28], 1);
            if (DAT_0107a104->Actor_GetClass(item)->FUN_0051dfb0()) {
                action *= *DAT_00f5ee80.FUN_004241e0();
            }
            float delta = (float)action;
            Tile* subTile = tile->unk28;
            subTile->FUN_00bee190(DAT_01076900, (float)(subTile->FUN_00becf40(DAT_01076900) + delta), 1);
            bool flag = false;
            DAT_0107a104->Set(item, (float)(DAT_0107a104->Get(item, flag) + delta));
            FUN_006551a0(tile->unk28);
            return FUN_00654d30();
        }
        break;
    }
    case 9:
    case 10:
    default:
        break;
    case 7: {
        FUN_00656640(unk28 + 1);
        return unk48->FUN_00bee190((void*)0xfc3, 0.0f, 1);
    }
    case 8: {
        FUN_00656640(unk28 - 1);
        return unk4C->FUN_00bee190((void*)0xfc3, 0.0f, 1);
    }
    case 6: {
        if (unk50[unk28] > 0) {
            FUN_0061a730(1);
        }
        unk50[unk28] = 0;
        unk04->FUN_00bee190(DAT_010768e8, (float)unk50[unk28], 1);
        switch (unk28) {
        case 0:
            sub60.FUN_00655800(LevelUpMenu_ResetSkillsFunc, 0, 0x7fffffff);
            break;
        case 1:
            sub90.FUN_00655800(FUN_00657540, 0, 0x7fffffff);
            return FUN_00654d30();
        default:
            break;
        }
        return FUN_00654d30();
    }
    }
}

} // namespace f3m_00657580
}   // namespace f3m_00657580
