// src/f3staging/f3blk_00780000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0078ed50 (community match, verified in this file)
struct S78ed50_Ref;

struct S78ed50_Form;
struct FUN_00cbc810_cls {
    S78ed50_Form* data;
    FUN_00cbc810_cls* next;
    void RemoveKey(unsigned int* key);
    void Remove(S78ed50_Form* const& key) { RemoveKey((unsigned int*)&key); }
};

struct S78ed50_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    char unk1c;
    char unk1d;
    char unk1e;
};

struct S78ed50_Pkg {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char unk20;
};

struct S78ed50_Process {
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
    virtual void v0e0();
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
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual S78ed50_Pkg* v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual bool v35c();
    virtual void v360(int a);
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual float v694();
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
};

struct S78ed50_Node2 {
    S78ed50_Ref* data;
    bool FUN_00645c20();
    void FUN_00415d70();
};

struct S78ed50_List2 {
    int unk00;
    S78ed50_Node2* FUN_0040c6b0();
    void FUN_0040c5f0(int a);
    void FUN_0040c6d0();
};

struct S78ed50_Form {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010(int a);
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
    virtual void v0d8(int a);
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual bool v0fc();
    virtual bool v100();
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
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int a);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324(int a, int b, int c);
};

struct S78ed50_Ref : S78ed50_Form {
    int unk04;
    unsigned int flags;
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
    S78ed50_List2 list40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    S78ed50_Process* unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    char unk78;
    char unk79;
    char unk7a;
    char unk7b;
    bool IsDisabled() { return (flags >> 21) & 1; }
    bool IsBit5() { return (flags >> 5) & 1; }
    bool IsBit11() { return (flags >> 11) & 1; }
    int GetUnk3c() { return unk3c; }
    S78ed50_Ref* FUN_00619bf0();
    bool FUN_00764e60();
    int TESForm_GetFile(int a);
    int FUN_007650b0();
    void FUN_007654f0();
    int FUN_006191f0();
    bool FUN_006f4a10();
    bool FUN_006f4a40();
    S78ed50_Info* FUN_004ebfc0();
    void FUN_004e7d50();
};

struct S78ed50_Owner {
    int unk00;
    void FUN_0078bc20(S78ed50_Ref* ref, int a);
    void FUN_0078ba80(S78ed50_Ref* ref, int a);
};

struct S78ed50_Checker { bool FUN_0076c8e0(); };
struct S78ed50_Lookup { bool TES_IsCellLoaded(int a, int b); };
struct S78ed50_Clock { unsigned int Calendar_GetHoursPassed(); };

extern S78ed50_Checker* DAT_0107a104;
extern S78ed50_Lookup* DAT_0107a0d8;
extern S78ed50_Clock DAT_01079f68;
extern S78ed50_Owner DAT_0107c0a4;
static S78ed50_Ref* DAT_0107c054;
extern unsigned int DAT_00f4fab4;

struct S78ed50_Mgr {
    int unk00;
    S78ed50_Owner owner;
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
    FUN_00cbc810_cls list78;
    void FUN_0078ed50();
};

// pdb: ProcessLists::ChangeProcessLevelTempList | ProcessLists.obj | fnv360_0822_retail, call_gap, medium
void S78ed50_Mgr::FUN_0078ed50()
{
    if (DAT_0107a104->FUN_0076c8e0())
        return;

    FUN_00cbc810_cls* head = &list78;
    FUN_00cbc810_cls* node = head;
    while (node) {
        S78ed50_Form* data = node->data;
        if (!data)
            break;
        DAT_0107c054 = 0;
        if (data->v0fc())
            DAT_0107c054 = static_cast<S78ed50_Ref*>(node->data);
        if (!DAT_0107c054)
            continue;
        S78ed50_Ref* actor = 0;
        if (DAT_0107c054->v100())
            actor = DAT_0107c054;
        node = node->next;
        if (DAT_0107c054->IsDisabled())
            continue;

        if ((DAT_0107c054->v100() && !DAT_0107c054->unk60)
            || (DAT_0107c054->unk79 && DAT_0107c054->FUN_00619bf0() != DAT_0107c054)) {
            if (DAT_0107c054->unk79 && DAT_0107c054->FUN_00764e60()) {
                DAT_0107c0a4.FUN_0078bc20(DAT_0107c054, 0);
            } else if ((DAT_0107c054->IsBit5() && !DAT_0107c054->TESForm_GetFile(-1))
                || (DAT_0107c054->unk79 && !DAT_0107c054->FUN_00764e60())) {
                if (DAT_0107c054->unk60)
                    owner.FUN_0078ba80(DAT_0107c054, DAT_0107c054->FUN_007650b0());
                if (DAT_0107c054)
                    DAT_0107c054->v010(1);
            } else if ((DAT_0107c054->IsBit5() || DAT_0107c054->IsBit11()) && DAT_0107c054->unk60) {
                owner.FUN_0078ba80(DAT_0107c054, DAT_0107c054->FUN_007650b0());
                DAT_0107c054->FUN_007654f0();
            }
            head->Remove(DAT_0107c054);
            if (DAT_0107c054)
                DAT_0107c054->unk7a = 0;
            node = head;
            continue;
        }

        if (actor && actor->v22c(0) && !actor->FUN_006f4a10() && actor->FUN_006f4a40()
            && !DAT_0107a0d8->TES_IsCellLoaded(actor->GetUnk3c(), 0)
            && actor->unk60->v694() != 0.0f) {
            unsigned int now = DAT_00f4fab4;
            if (now + actor->unk60->v694() < DAT_01079f68.Calendar_GetHoursPassed()) {
                S78ed50_Info* info = actor->FUN_004ebfc0();
                if (info && (info->unk1e & 1))
                    continue;
                actor->v324(1, 0, 0);
                S78ed50_Node2* n = actor->list40.FUN_0040c6b0();
                while (n && !n->FUN_00645c20()) {
                    S78ed50_Ref* d = n->data;
                    d->list40.FUN_0040c5f0(0);
                    if (!d->v160())
                        d->FUN_004e7d50();
                    n->FUN_00415d70();
                }
                if (n)
                    actor->list40.FUN_0040c6d0();
                head->Remove(DAT_0107c054);
                if (DAT_0107c054)
                    DAT_0107c054->unk7a = 0;
                node = head;
                continue;
            }
        }

        if (DAT_0107c054->IsBit11()) {
            if (DAT_0107c054->unk60)
                owner.FUN_0078ba80(DAT_0107c054, DAT_0107c054->FUN_007650b0());
            DAT_0107c054->FUN_007654f0();
            head->Remove(DAT_0107c054);
            if (DAT_0107c054)
                DAT_0107c054->unk7a = 0;
            node = head;
            continue;
        }

        if ((DAT_0107c054->unk79 && DAT_0107c054->FUN_006191f0() != 0x3f1)
            || ((DAT_0107c054->flags & 0x20000) && !DAT_0107c054->unk79)) {
            DAT_0107c054->v0d8(0);
            head->Remove(DAT_0107c054);
            S78ed50_Ref* removed = DAT_0107c054;
            if (removed)
                removed->unk7a = 0;
            removed->v224();
            if (DAT_0107c054->IsBit5() && !DAT_0107c054->TESForm_GetFile(-1)) {
                if (DAT_0107c054->unk60)
                    owner.FUN_0078ba80(DAT_0107c054, DAT_0107c054->FUN_007650b0());
                if (DAT_0107c054)
                    DAT_0107c054->v010(1);
            } else if (!DAT_0107c054->IsBit5() && !DAT_0107c054->IsBit11()) {
                S78ed50_Process* proc = DAT_0107c054->unk60;
                if (proc && proc->v35c()) {
                    S78ed50_Pkg* pkg = DAT_0107c054->unk60->v228();
                    if (!pkg || (pkg->unk20 != 1 && pkg->unk20 != 2)) {
                        DAT_0107c054->unk60->v360(0);
                        owner.FUN_0078bc20(DAT_0107c054, DAT_0107c054->unk60->unk28);
                    }
                } else {
                    DAT_0107c054->v260();
                    if (DAT_0107c054 && (DAT_0107c054->flags & 0x20000))
                        DAT_0107c054->v0d8(0);
                }
            } else if (DAT_0107c054->unk60) {
                owner.FUN_0078ba80(DAT_0107c054, DAT_0107c054->FUN_007650b0());
                DAT_0107c054->FUN_007654f0();
            }
            node = head;
        }
    }

    for (FUN_00cbc810_cls* it = head; it && it->data; it = it->next)
        it->data->v0d8(1);
}

// @f3 0x007820f0 (community match, verified in this file)
#include <math.h>

struct Vec3_78 {
    float x, y, z;
    Vec3_78() {}
    Vec3_78(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct __declspec(align(16)) Vec3A_78 {
    float x, y, z;
    Vec3A_78() {}
    Vec3A_78(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Mat3_78 {
    float m[9];
    Mat3_78 FUN_00424020(const Mat3_78& rhs) const;
    void MakeZRot(double fAngle) {
        float c, s;
        fnv_SinCos((float)fAngle, s, c);
        m[0] = c;    m[1] = s;    m[2] = 0.0f;
        m[3] = -s;   m[4] = c;    m[5] = 0.0f;
        m[6] = 0.0f; m[7] = 0.0f; m[8] = 1.0f;
    }
    void MakeXRot(float fAngle) {
        float c, s;
        fnv_SinCos(fAngle, s, c);
        m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f;
        m[3] = 0.0f; m[4] = c;    m[5] = s;
        m[6] = 0.0f; m[7] = -s;   m[8] = c;
    }
};

struct Node78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    Mat3_78 m_localRotate;
    Vec3_78 m_localTranslate;
    void SetLocalRotate(const Mat3_78& r) { m_localRotate = r; }
};

struct B9UpdateData78 {
    float unk00;
    bool unk04;
    bool unk05;
    bool unk06;
    bool unk07;
    bool unk08;
    B9UpdateData78() : unk00(0.0f), unk04(false), unk05(false), unk06(false), unk07(false), unk08(false) {}
};

struct CamNode78 : Node78 {
    void FUN_008264c0(B9UpdateData78& data);
};

struct CamMgr78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    CamNode78** unk_a0;
    unsigned short unk_a4;
    unsigned short unk_a6;
    int unk_a8;
    int unk_ac;
    CamNode78* GetRoot() const {
        if (unk_a6 <= 0)
            return 0;
        return unk_a0[0];
    }
    void SetRootRotate(const Mat3_78& r) {
        GetRoot()->m_localRotate = r;
    }
};

struct MenuObj78 {
    virtual void Destroy(bool freeMem);
};

struct MenuSlot78 {
    MenuObj78* FUN_00beab90();
};

struct MenuBase78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0;
};

struct Location78 {
    void FUN_004bfaa0(int t);
    void FUN_004bfac0(int t);
};

struct FullName78 {
    int vtable;
    BSStringT<char> name;
    const char* GetName() const { return name.pString ? name.pString : ""; }
    const char* GetStr() const { return name.pString; }
};

struct WorldSub78 {
    void* FUN_00501cc0();
};

struct World78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FullName78 fullName;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0;
    FullName78 unkd4;
};

struct Cell78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20;
    unsigned int unk24;
    World78* FUN_004d3780();
    Location78* TESObjectCELL_GetEncounterZone();
    void FUN_004de880(void* ref);
    int FUN_004d55b0(void* arg);
    void TESObjectCELL_AddReference(void* ref, int a);
    bool FUN_004d7380(Vec3_78* p, float* h);
};

struct UnkCellHolder78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    Location78* unkd0;
};

struct Hud78 {
    void FOPipboyManager_ShowPipboyLightEffect(int a, int b, int c);
    void FUN_00698300();
};

struct Stream78 {
    void FUN_00615b90(Vec3_78* p, unsigned int flags);
    void FUN_00615310(Vec3_78* p);
};

struct Unk8c_78 {
    bool MagicTarget_IsSpellTarget(void* node, int a);
    void FUN_006b76e0(void* node, int a, int b);
};

struct Unk57d_78 {
    void Sky_ResetWeather();
};

struct Unk9a0_78 {
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
    virtual void v0d0();
    virtual void v0d4(const Vec3A_78& p);
    void SetPos(Vec3_78 p) {
        Vec3A_78 scaled((float)(p.x * 0.1428767293691635), (float)(p.y * 0.1428767293691635), (float)(p.z * 0.1428767293691635));
        v0d4(scaled);
    }
};

struct Unk730_78 {
    int unk00;
    char unk04;
    char unk05, unk06, unk07;
    int unk08;
    bool BSSoundHandle_IsValid();
    void Clear() {
        unk00 = -1;
        unk04 = 0;
        unk08 = 0;
    }
};

struct Player78 {
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
    virtual Node78* v1d0();
    virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec();
    virtual void v1f0();
    virtual Vec3_78* v1f4();
    virtual void v1f8(); virtual void v1fc();
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
    virtual void v2a0(); virtual void v2a4();
    virtual void v2a8(Vec3_78* p);
    virtual void v2ac(); virtual void v2b0(); virtual void v2b4(); virtual void v2b8();
    virtual float v2bc(int a);

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    Cell78* unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    Unk8c_78 unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    int unk5a0, unk5a4;
    bool unk5a8;
    char unk5a9, unk5aa, unk5ab;
    int unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    int unk5e0, unk5e4, unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4, unk5f8, unk5fc;
    int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    int unk700;
    int unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    int unk720, unk724, unk728;
    int unk72c;
    Unk730_78 unk730;
    int unk73c;
    int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c;
    int unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    int unk980, unk984, unk988, unk98c, unk990, unk994, unk998, unk99c;
    Unk9a0_78* unk9a0;

    void FUN_004e86c0(Vec3_78 rot);
    void FUN_004e8790(Cell78* cell);
    void FUN_00767f10(float dt, Vec3_78* vel, int flag);
    void PlayerCharacter_CheckForQuestTargetUpdate(Player78* self);
    void Character_Update(float a);
    int Actor_GetAnimation();
    void FUN_0070d7d0(int a, float b);
    void PlayerCharacter_UpdateCamera(int a);
    World78* FUN_004e8880();
    void FUN_007820f0(Vec3_78 pos, Vec3_78 rot, Cell78* targetCell, bool flag24);
};

struct Unk08_78 {
    void FUN_0047ba30();
};
struct Unk0c_78 {
    void FUN_008268a0();
};
struct TES78 {
    int unk00, unk04;
    Unk08_78* unk08;
    Unk0c_78* unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    int unk34;
    int unk38, unk3c, unk40, unk44, unk48, unk4c;
    char unk50, unk51, unk52, unk53;
    UnkCellHolder78* FUN_00b35640();
    void FUN_0043a040(Cell78* cell, Vec3_78* pos);
    void TES_SetWorldSpace(World78* world);
    void FUN_0043a670(Vec3_78* pos);
    void FUN_00437290(float a);
    void FUN_00439030();
    void FUN_00433a30(int a, int b);
};

struct ObjMgr78 {
    void FUN_006ecc50();
    void FUN_00c24b70();
};
struct C0a0_78 {
    void FUN_0078e2b0();
};
struct Clock78 {
    int Calendar_GetHoursPassed();
};
struct Ebbc_78 {
    bool MoviePlayer_GetPlayingSequence();
    void FUN_007f9d50();
    void FUN_007fb230(void* p, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);
};
struct C86c_78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18;
};
struct Audio78 {
    void FUN_0078c030(int a);
    void FUN_00bcf510(Vec3_78 pos);
    void FUN_00bcf6e0(Vec3_78 a, Vec3_78 b);
};
struct B38_78 {
    void FUN_00aa4b30(int a);
};
struct D974_78 {
    void FUN_006181f0(int a, float b, int c);
};
struct Ad5_78 {
    void FUN_00ae87d0();
};
struct Unk9858_78 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240;
    unsigned int unk244_0 : 1;
    unsigned int unk244_1 : 1;
    bool IsBit1() const { return unk244_1; }
};

extern ObjMgr78* DAT_0107a0d4;
extern C0a0_78 DAT_0107c0a0;
extern MenuBase78* DAT_010770ac;
extern Ebbc_78* DAT_0108ebbc;
extern char DAT_01079041;
extern char DAT_00f65ef0;
extern C86c_78* DAT_0106c86c;
extern Audio78* DAT_011790c8;
extern Unk9858_78* DAT_01079858;
extern B38_78* DAT_0116d138;
extern D974_78* DAT_01075974;
extern Mat3_78 DAT_00f72574;
extern Vec3_78 DAT_00f725b0;
extern CamMgr78* DAT_0107a224;
extern char* DAT_0116efb8;
extern Vec3_78 DAT_0108ec68;
extern float DAT_01090bac;
extern char DAT_01075a07;
extern void* DAT_01079ee8;

void __cdecl FUN_0061a020();
MenuSlot78* __cdecl Tile_GetMenuByClass(int id);
bool __cdecl FUN_006bdcd0(int id);
void __cdecl FUN_006be910();
void __cdecl FUN_006bebf0();
void __cdecl BSTreeManager_ClearCanopyShadow();
void __cdecl FUN_0059bfa0();
Hud78* __cdecl Interface_GetPipboy();
Unk57d_78* __cdecl Sky_GetInstance();
Ad5_78* __cdecl FUN_00ad5a50();
void __fastcall FUN_00ae6580(char* s);
void __cdecl FUN_0059bd60(int a, bool b);
void __cdecl FUN_00657ab0();
void __cdecl FUN_0064de10(int a);
void __cdecl FUN_00644490(const char* name);

// pdb: PlayerCharacter::PositionPlayer | PlayerCharacter.obj | fnv360_0822_debug, caller, medium
// pdb params: aPos, aAngle, apCell, abResetWeather
void Player78::FUN_007820f0(Vec3_78 pos, Vec3_78 rot, Cell78* targetCell, bool flag24)
{
    if (!((TES78*)DAT_0107a0d8)->unk51 && !((TES78*)DAT_0107a0d8)->unk52)
        DAT_0107a0d4->FUN_006ecc50();
    DAT_0107c0a0.FUN_0078e2b0();
    if (DAT_010770ac && !(DAT_010770ac->unk1a0 & 1))
    {
        FUN_0061a020();
        MenuObj78* menu = Tile_GetMenuByClass(0x3f5)->FUN_00beab90();
        if (menu)
            menu->Destroy(true);
    }

    bool flag23 = (((TES78*)DAT_0107a0d8)->unk34 != 0);
    UnkCellHolder78* holder = ((TES78*)DAT_0107a0d8)->FUN_00b35640();
    targetCell->FUN_004d3780();
    Location78* newLoc = targetCell->TESObjectCELL_GetEncounterZone();
    Location78* oldLoc = 0;
    if (unk3c)
        oldLoc = unk3c->TESObjectCELL_GetEncounterZone();
    else if (holder)
        oldLoc = holder->unkd0;
    if (oldLoc != newLoc)
    {
        int t = ((Clock78*)&DAT_01079f68)->Calendar_GetHoursPassed();
        if (oldLoc)
            oldLoc->FUN_004bfaa0(t);
        if (newLoc)
            newLoc->FUN_004bfac0(t);
    }

    bool flag17 = DAT_0108ebbc->MoviePlayer_GetPlayingSequence();
    if (unk3c)
        unk3c->FUN_004de880(this);
    v2a8(&pos);
    FUN_004e86c0(rot);
    FUN_004e8790(targetCell);

    if (targetCell && (targetCell->unk24 & 1))
    {
        unk700 = targetCell->FUN_004d55b0(0);
        if (!DAT_01079041 && FUN_006bdcd0(targetCell->FUN_004d55b0(0)) && !flag17)
        {
            FUN_006be910();
            FUN_006bebf0();
        }
        ((TES78*)DAT_0107a0d8)->FUN_0043a040(targetCell, &pos);
        BSTreeManager_ClearCanopyShadow();
    }
    else
    {
        if (targetCell)
        {
            unk700 = targetCell->FUN_004d55b0(0);
            if (FUN_006bdcd0(targetCell->FUN_004d55b0(&pos)) && !flag17)
                FUN_006bebf0();
            const char* name;
            if (DAT_00f65ef0 && (name = targetCell->FUN_004d3780()->unkd4.GetStr()) != 0 && *name)
                FUN_0059bfa0();
            else
            {
                BSTreeManager_ClearCanopyShadow();
                ((TES78*)DAT_0107a0d8)->unk08->FUN_0047ba30();
            }
            ((TES78*)DAT_0107a0d8)->TES_SetWorldSpace(targetCell->FUN_004d3780());
        }

        if (flag23)
        {
            void* n = DAT_0106c86c ? &DAT_0106c86c->unk18 : 0;
            if (unk8c.MagicTarget_IsSpellTarget(n, 1))
            {
                Interface_GetPipboy()->FOPipboyManager_ShowPipboyLightEffect(1, 0, 1);
                Interface_GetPipboy()->FOPipboyManager_ShowPipboyLightEffect(0, 0, 1);
                void* n2 = DAT_0106c86c ? &DAT_0106c86c->unk18 : 0;
                unk8c.FUN_006b76e0(n2, 0, 0);
            }
        }

        ((TES78*)DAT_0107a0d8)->FUN_0043a670(&pos);
    }
    DAT_011790c8->FUN_0078c030(0x1000);
    if (flag24)
        Sky_GetInstance()->Sky_ResetWeather();
    FUN_004e8790(0);
    targetCell->TESObjectCELL_AddReference(this, 0);

    if (!v1d0() && !DAT_01079858->IsBit1())
    {
        DAT_0116d138->FUN_00aa4b30(5);
        DAT_01075974->FUN_006181f0(1, 0.0f, 0);
    }

    Mat3_78 m0 = DAT_00f72574;
    while (rot.z > 3.1415927f)
        rot.z = (float)(rot.z - 6.2831854820251465);
    while (rot.z < -3.1415927f)
        rot.z = (float)(rot.z + 6.2831854820251465);

    Mat3_78 rotMat;
    rotMat.MakeZRot(rot.z);
    m0 = m0.FUN_00424020(rotMat);

    if (rot.z >= 0.0f)
        rotMat.MakeXRot(rot.x - rot.y);
    else
        rotMat.MakeXRot(rot.y + rot.x);

    if (v1d0())
        v1d0()->m_localRotate = rotMat;

    DAT_0107a224->SetRootRotate(rotMat.FUN_00424020(m0));
    DAT_0107a224->GetRoot()->m_localTranslate = pos;

    B9UpdateData78 b9data;
    DAT_0107a224->GetRoot()->FUN_008264c0(b9data);
    ((TES78*)DAT_0107a0d8)->unk0c->FUN_008268a0();
    DAT_011790c8->FUN_00bcf510(pos);

    float fYaw = v2bc(0);
    Vec3_78 dir;
    dir.x = (float)sin(v2bc(0));
    dir.y = (float)cos(fYaw);
    dir.z = 0.0f;
    DAT_011790c8->FUN_00bcf6e0(dir, DAT_00f725b0);
    PlayerCharacter_CheckForQuestTargetUpdate(this);
    Ad5_78* ad5 = FUN_00ad5a50();
    if (ad5)
        ad5->FUN_00ae87d0();
    if (unk5f0)
    {
        Interface_GetPipboy()->FUN_00698300();
        FUN_00ae6580(DAT_0116efb8);

        if (!DAT_01079858->IsBit1())
        {
            Vec3_78 p = *v1f4();
            if (targetCell && !(targetCell->unk24 & 1))
            {
                float h = 0.0f;
                if (targetCell->FUN_004d7380(&p, &h) && p.z < h + 32.0)
                {
                    p.z = (float)(h + 32.0);
                    v2a8(&p);
                }
            }
            int i = 0;
            do
            {
                Vec3_78 prev = *v1f4();
                Vec3_78 vel = DAT_0108ec68;
                FUN_00767f10(0.16f, &vel, 0);
                Vec3_78 cur = *v1f4();
                if (fabs(cur.z - prev.z) < 0.1f)
                    break;
                ++i;
            } while (i < 100);
            if (i == 100)
                v2a8(&p);
        }

        unk5a8 = !unk5a8;
        Character_Update(0.0f);
        FUN_0070d7d0(!unk5a8 ? unk5ec : Actor_GetAnimation(), 0.0f);
        unk5a8 = !unk5a8;
        Character_Update(0.0f);
        FUN_0070d7d0(!unk5a8 ? unk5ec : Actor_GetAnimation(), 0.0f);
        PlayerCharacter_UpdateCamera(0);
    }

    if (unk9a0)
        unk9a0->SetPos(*v1f4());

    FUN_0059bd60(DAT_0107a224->unk_ac, false);
    ((TES78*)DAT_0107a0d8)->FUN_00437290(DAT_01090bac);
    if (!DAT_01079858->IsBit1())
        FUN_00657ab0();
    if (flag17)
        DAT_0108ebbc->FUN_007f9d50();
    if (unk730.BSSoundHandle_IsValid())
    {
        unk730.Clear();
        unk72c = 0;
    }
    ((TES78*)DAT_0107a0d8)->FUN_00439030();
    if (FUN_004e8880())
    {
        ((Stream78*)((WorldSub78*)FUN_004e8880())->FUN_00501cc0())->FUN_00615b90(v1f4(), 0xf);
        ((Stream78*)((WorldSub78*)FUN_004e8880())->FUN_00501cc0())->FUN_00615310(v1f4());
    }
    DAT_0107a0d4->FUN_00c24b70();
    if (DAT_01075a07)
    {
        ((TES78*)DAT_0107a0d8)->FUN_00433a30(0, 0);
        FUN_0064de10(0x17);
        DAT_0108ebbc->FUN_007fb230(DAT_01079ee8, true, true, false, true, true, false, true, true);
        FUN_0064de10(0xc);
    }
    FUN_00644490(((Player78*)DAT_0107a104)->FUN_004e8880() ? ((Player78*)DAT_0107a104)->FUN_004e8880()->fullName.GetName() : 0);
}
