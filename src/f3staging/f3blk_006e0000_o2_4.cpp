#include <windows.h>
// src/f3staging/f3blk_006e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006f73e0 (community match, verified in this file)
namespace f3m_006f73e0 {
namespace f3m_006f73e0 {
struct QForm {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    unsigned int unk1c;
    unsigned short unk20;
    unsigned short unk22;
};
struct QProc {
    virtual void v000(); virtual void v001(); virtual void v002(); virtual void v003(); virtual void v004(); virtual void v005(); virtual void v006(); virtual void v007(); virtual void v008(); virtual void v009(); virtual void v010(); virtual void v011(); virtual void v012(); virtual void v013(); virtual void v014(); virtual void v015(); virtual void v016(); virtual void v017(); virtual void v018(); virtual void v019(); virtual void v020(); virtual void v021(); virtual void v022(); virtual void v023(); virtual void v024(); virtual void v025(); virtual void v026(); virtual void v027(); virtual void v028(); virtual void v029(); virtual void v030(); virtual void v031(); virtual void v032(); virtual void v033(); virtual void v034(); virtual void v035(); virtual void v036(); virtual void v037(); virtual void v038(); virtual void v039(); virtual void v040(); virtual void v041(); virtual void v042(); virtual void v043(); virtual void v044(); virtual void v045(); virtual void v046(); virtual void v047(); virtual void v048(); virtual void v049(); virtual void v050(); virtual void v051(); virtual void v052(); virtual void v053(); virtual void v054(); virtual void v055(); virtual void v056(); virtual void v057(); virtual void v058(); virtual void v059(); virtual void v060(); virtual void v061(); virtual void v062(); virtual void v063(); virtual void v064(); virtual void v065(); virtual void v066(); virtual void v067(); virtual void v068(); virtual void v069(); virtual void v070(); virtual void v071(); virtual void v072(); virtual void v073(); virtual void v074(); virtual void v075(); virtual void v076(); virtual void v077(); virtual void v078(); virtual void v079(); virtual void v080(); virtual void v081(); virtual void v082(); virtual void v083(); virtual void v084(); virtual void v085(); virtual void v086(); virtual void v087(); virtual void v088(); virtual void v089(); virtual void v090(); virtual void v091(); virtual void v092(); virtual void v093(); virtual void v094(); virtual void v095(); virtual void v096(); virtual void v097(); virtual void v098(); virtual void v099(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); 
    virtual QForm* v138();
};
struct QActor {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    QProc* unk60;
    bool FUN_006f73e0(int which);
};

// pdb: Actor::ShouldSkipFallOutBehavior | Actor.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aeFalloutType
bool QActor::FUN_006f73e0(int which)
{
    QForm* form = unk60->v138();
    bool result = false;
    if (form) {
        if (!(((unsigned char)(form->unk1c >> 12)) & 1))
            return false;
        switch (which) {
        case 0: if (!(((unsigned char)(form->unk22 >> 0)) & 1)) result = true; break;
        case 1: if (!(((unsigned char)(form->unk22 >> 1)) & 1)) result = true; break;
        case 2: if (!(((unsigned char)(form->unk22 >> 2)) & 1)) result = true; break;
        case 4: if (!(((unsigned char)(form->unk22 >> 4)) & 1)) result = true; break;
        case 5: if (!(((unsigned char)(form->unk22 >> 5)) & 1)) result = true; break;
        case 6: if (!(((unsigned char)(form->unk22 >> 6)) & 1)) result = true; break;
        case 7: if (!(((unsigned char)(form->unk22 >> 7)) & 1)) result = true; break;
        case 8: if (!(((unsigned char)(form->unk22 >> 8)) & 1)) result = true; break;
        }
    }
    return result;
}
}
}   // namespace f3m_006f73e0
