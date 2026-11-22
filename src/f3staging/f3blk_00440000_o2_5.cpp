#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00452690 (community match, verified in this file)
namespace f3m_00452690 {
// pdb: TESContainer::ContainerCanHoldType | TESContainer.obj | tesv_win, call_gap_sim, low
bool FUN_00452690(unsigned char type)
{
    switch (type) {
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x34:
        return true;
    }
    return false;
}
}   // namespace f3m_00452690

// @f3 0x0045d370 (community match, verified in this file)
namespace f3m_0045d370 {
struct Vec3 { float x, y, z; };
struct Mat33 { void* unk00;
 void* unk04;
 void* unk08;
 void* unk0C;
 void* unk10;
 void* unk14;
 void* unk18;
 void* unk1C;
 void* unk20;};

extern Vec3 DAT_0108ec68;
extern float DAT_01090bac;

struct Part {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    int unk74;
};

struct Cnt {
    int __thiscall FUN_0054bef0();
    float __thiscall FUN_0054bd10();
    float __thiscall FUN_004e6d80();
};

struct Obj {
    virtual void v0();
    void* unk04;
};

struct Targ {
    int __thiscall dummy();
};

struct Owner;

struct Item {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Mat33 unk34;
};

struct Inner {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    int unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    Cnt* unk74;
};

struct Rec {
    int unk00;
    Cnt* unk04;
    Item* unk08;
    int unk0C;
    Vec3 unk10;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    
    Inner* unkE4;
    int unkE8;
    int unkEC;
    Inner* unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    
    float unk10C;
    float unk110;
    bool FUN_0045d370(Vec3* out, class Base* obj, bool flag1, bool flag2);
};

class Base {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
    virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
    virtual void v132();
    virtual int v133();
    virtual void v134();
    virtual bool v135();
    int __thiscall FUN_006f58b0();
    float __thiscall FUN_004e6d80();
};

extern void __cdecl FUN_008225c0(Mat33* m, Vec3* a, int one, Vec3* b, Vec3* out);

// pdb: Animation::GetDelta | Animation.obj | fnv360_0822_debug, caller, medium
// pdb params: delta, apRef, applyRot, zeroZ
bool Rec::FUN_0045d370(Vec3* out, Base* obj, bool flag1, bool flag2)
{
    if (!unk08)
        return false;
    Vec3 a = DAT_0108ec68;
    Vec3 b = unk10;
    Mat33 m = unk08->unk34;
    if (!obj->v135() && (obj->FUN_006f58b0() & 0xf) && unkE4 &&
        unkE4->unk74->FUN_0054bef0() >= 3 && unkE4->unk74->FUN_0054bef0() <= 16) {
        float k = DAT_01090bac;
        Cnt* c = unkE4->unk74;
        float v = c->FUN_0054bd10() * unk10C * k * unk04->FUN_004e6d80();
        if (unkF0 && unkF0->unk44 == 1) {
            float k2 = DAT_01090bac;
            Cnt* c2 = unkF0->unk74;
            float v2 = c2->FUN_0054bd10() * unk110 * k2 * unk04->FUN_004e6d80();
            if (v2 > v)
                v = v2;
        }
        float lim = (float)(v * 4.0);
        if (v > 0.0f) {
            if (b.x > lim) b.x = v;
            if (b.y > lim) b.y = v;
            if (b.z > lim) b.z = v;
            if (b.x < -lim) b.x = -v;
            if (b.y < -lim) b.y = -v;
            if (b.z < -lim) b.z = -v;
        }
    }
    switch (obj->v133()) {
    case 3: case 5: case 8: case 10: {
        float d = obj->FUN_004e6d80();
        b.x = b.x / d;
        b.y = b.y / d;
        break;
    }
    default:
        break;
    }
    if (flag2)
        b.z = 0.0f;
    if (flag1) {
        FUN_008225c0(&m, &a, 1, &b, out);
        return true;
    }
    *out = b;
    return true;
}
}   // namespace f3m_0045d370
