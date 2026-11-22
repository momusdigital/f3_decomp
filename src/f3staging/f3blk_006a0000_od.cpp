// src/f3staging/f3blk_006a0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006ae540 (community match, verified in this file)
extern int FUN_00f79e58;
extern void *DAT_01071564;
extern const double FUN_00db7de8;
namespace f3m_006ae540 {

struct V3 { float x, y, z; };

struct MainObj {
    void **vtable;
    char pad04[0x38];
    void *f3c;
};

struct Obj3C {
    char pad00[0x24];
    char f24;
    char pad25[3];
    int f28;
};

struct __declspec(align(16)) S {
    int f00, f04, f08;
    int f0c, f10, f14, f18, f1c, f20;
    int f24;
    int f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c;
    int f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74;
    int f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    int fa0, fa4;
    void ctor();
    void FUN_00469050(V3 *src);
    void FUN_00469bd0(V3 *src);
};

struct EdiObj {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24();
    virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43(); virtual void d44();
    virtual void d45(); virtual void d46(); virtual void d47(); virtual void d48(); virtual void d49();
    virtual bool __thiscall method_C8(S* s);
};

struct Base1 { int x[4]; };
struct Base2 { int y[7]; unsigned int field_1c; };
struct Derived : Base1, Base2 {};

struct Q {
    char pad00[8];
    Derived *f08;
};

struct Ret764 {
    char pad00[0x424];
    Q *f424;
};

extern void *__fastcall FUN_00410f00(void *arg);
extern void __cdecl FUN_008f4480(int a, unsigned int b, int c);
extern float __fastcall FUN_006f5de0(MainObj *self);
extern void __fastcall FUN_00468f40(S *s);
extern Ret764 *__fastcall FUN_00764ea0(MainObj *self);

__forceinline bool Finish(EdiObj* edi, MainObj* pObj, V3& pos, V3 t)
{

    t.z += FUN_006f5de0(pObj) * FUN_00db7de8;

    __declspec(align(16)) S s;
    FUN_00468f40(&s);

    unsigned int x;
    if (FUN_00764ea0(pObj)) {
        Ret764 *p2 = FUN_00764ea0(pObj);
        Q *q = p2->f424;
        if (q) {
            Derived *d = q->f08;
            Base2 *b = d;
            unsigned int v = b ? b->field_1c : 0;
            x = v >> 16;
        } else {
            x = 0;
        }
    } else {
        x = (FUN_00f79e58 + 1) & 0xFFFF;
        FUN_00f79e58 = x;
        if (x == 0) {
            FUN_00f79e58 = 10;
            x = 10;
        }
    }

    s.f24 = (x << 16) | 0x27;

    s.FUN_00469050(&pos);
    s.FUN_00469bd0(&t);

    return !edi->method_C8(&s);
}

// pdb: MagicCaster::RunExplosionLOSPick | MagicCaster.obj | fnv360_0822_retail, call_gap, low
// pdb params: aLocation, apTarget
bool __stdcall FUN_006ae540(V3 pos, MainObj *pObj) {
    if (pObj == 0) return false;

    Obj3C *o3c = (Obj3C*)pObj->f3c;
    if (o3c == 0) return false;

    EdiObj *edi;
    if (o3c->f24 & 1) {
        edi = (EdiObj*)FUN_00410f00(&o3c->f28);
    } else {
        edi = (EdiObj*)DAT_01071564;
    }
    if (edi == 0) return false;

    FUN_008f4480(0x27, 0x26206, 0);

    V3 *r = ((V3*(__fastcall*)(MainObj*))pObj->vtable[0x1F4/4])(pObj);

    return Finish(edi, pObj, pos, *r);
}
}   // namespace f3m_006ae540

// @f3 0x006bbc40 (community match, verified in this file)
namespace f3m_006bbc40 {
struct QPt3 { float x, y, z; };
extern const QPt3 NiPoint3_ZERO;
extern float DAT_00f62838;
extern const double DAT_00dbe7c0;
struct QMat3 {
    float m[3][3];
    void FUN_00823930(float a, float b, float c);
};
struct __declspec(align(16)) QVec4 {
    float x;
    volatile float y, z;
    float w;
};
struct QMotion {
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
    virtual void v48(const QVec4* v);
};
struct QEntity {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc;
    QMotion motion;
    void FUN_0090b500();
};
struct QBody {
    int unk00, unk04;
    QEntity* entity;
    float FUN_00475710();
    void FUN_004e93a0(const QPt3* v);
};
struct QNode18 {
    int unk00, unk04, unk08;
    QBody* body;
};
struct QNode8 {
    int unk00,unk04,unk08,unk0c,unk10,unk14;
    QNode18* node;
};
struct QCtrl {
    int unk00, unk04;
    QNode8* node;
};
struct QPlayer {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    QPt3 rot;
    int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc,unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c,unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c,unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c,unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c,unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c,unk1a0,unk1a4,unk1a8,unk1ac,unk1b0,unk1b4,unk1b8,unk1bc,unk1c0,unk1c4,unk1c8,unk1cc,unk1d0,unk1d4,unk1d8,unk1dc,unk1e0,unk1e4,unk1e8,unk1ec,unk1f0,unk1f4,unk1f8,unk1fc,unk200,unk204,unk208,unk20c,unk210,unk214,unk218,unk21c,unk220,unk224,unk228,unk22c,unk230,unk234,unk238,unk23c,unk240,unk244,unk248,unk24c,unk250,unk254,unk258,unk25c,unk260,unk264,unk268,unk26c,unk270,unk274,unk278,unk27c,unk280,unk284,unk288,unk28c,unk290,unk294,unk298,unk29c,unk2a0,unk2a4,unk2a8,unk2ac,unk2b0,unk2b4,unk2b8,unk2bc,unk2c0,unk2c4,unk2c8,unk2cc,unk2d0,unk2d4,unk2d8,unk2dc,unk2e0,unk2e4,unk2e8,unk2ec,unk2f0,unk2f4,unk2f8,unk2fc,unk300,unk304,unk308,unk30c,unk310,unk314,unk318,unk31c,unk320,unk324,unk328,unk32c,unk330,unk334,unk338,unk33c,unk340,unk344,unk348,unk34c,unk350,unk354,unk358,unk35c,unk360,unk364,unk368,unk36c,unk370,unk374,unk378,unk37c,unk380,unk384,unk388,unk38c,unk390,unk394,unk398,unk39c,unk3a0,unk3a4,unk3a8,unk3ac,unk3b0,unk3b4,unk3b8,unk3bc,unk3c0,unk3c4,unk3c8,unk3cc,unk3d0,unk3d4,unk3d8,unk3dc,unk3e0,unk3e4,unk3e8,unk3ec,unk3f0,unk3f4,unk3f8,unk3fc,unk400,unk404,unk408,unk40c,unk410,unk414,unk418,unk41c,unk420,unk424,unk428,unk42c,unk430,unk434,unk438,unk43c,unk440,unk444,unk448,unk44c,unk450,unk454,unk458,unk45c,unk460,unk464,unk468,unk46c,unk470,unk474,unk478,unk47c,unk480,unk484,unk488,unk48c,unk490,unk494,unk498,unk49c,unk4a0,unk4a4,unk4a8,unk4ac,unk4b0,unk4b4,unk4b8,unk4bc,unk4c0,unk4c4,unk4c8,unk4cc,unk4d0,unk4d4,unk4d8,unk4dc,unk4e0,unk4e4,unk4e8,unk4ec,unk4f0,unk4f4,unk4f8,unk4fc,unk500,unk504,unk508,unk50c,unk510,unk514,unk518,unk51c,unk520,unk524,unk528,unk52c,unk530,unk534,unk538,unk53c,unk540,unk544,unk548,unk54c,unk550,unk554,unk558,unk55c,unk560,unk564,unk568,unk56c,unk570,unk574,unk578,unk57c,unk580,unk584,unk588,unk58c,unk590;
    QCtrl* ctrl;
    void FUN_00780cc0();
};
extern QPlayer* DAT_0107a104;
struct QThis {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50;
    float unk54;
    int unk58;
    bool unk5c;
    void FUN_006bbc40();
};

// pdb: TelekinesisEffect::RemoveSpring | TelekinesisEffect.obj | fnv360_0822_retail, call_seq, medium
void QThis::FUN_006bbc40() {
    QPlayer* player = DAT_0107a104;
    if (!player->ctrl) return;
    QNode8* n = player->ctrl->node;
    QNode18* n18 = n ? n->node : 0;
    player->FUN_00780cc0();
    if (!n18) return;
    QBody* body = n18->body;
    if (unk5c) {
        QPt3 rot = DAT_0107a104->rot;
        QMat3 mat;
        mat.FUN_00823930(rot.z, rot.x, rot.y);
        float dist = unk54 + DAT_00f62838;
        QPt3 dir;
        dir.x = mat.m[0][1] * dist;
        dir.y = mat.m[1][1] * dist;
        dir.z = mat.m[2][1] * dist;
        QVec4 v;
        v.x = (float)(dir.x * DAT_00dbe7c0);
        v.y = (float)(dir.y * DAT_00dbe7c0);
        v.z = (float)(dir.z * DAT_00dbe7c0);
        float mass = body->FUN_00475710();
        v.x *= mass;
        v.y *= mass;
        v.z *= mass;
        v.w *= mass;
        QEntity* e = body ? body->entity : 0;
        e->FUN_0090b500();
        e->motion.v48(&v);
    } else {
        body->FUN_004e93a0(&NiPoint3_ZERO);
    }
}
}

// @f3 0x006b1280 (community match, verified in this file)
#include <string.h>

extern "C" void _ReadWriteBarrier();
struct S6b1280_Point3 { float x, y, z; S6b1280_Point3(const S6b1280_Point3& p) { unsigned int vx, vy;
        memcpy(&vx, &p.x, sizeof(vx));
        memcpy(&vy, &p.y, sizeof(vy));
        memcpy(&z, &p.z, sizeof(z));
        memcpy(&x, &vx, sizeof(x));
        memcpy(&y, &vy, sizeof(y));
 } };
extern const double FUN_00dbe7c0;

struct S6b1280_Handle {
    unsigned short lo;
    unsigned short hi;
    S6b1280_Handle();
    unsigned int GetID() const { return hi; }
};

class S6b1280_Heap {
public:
    void* FUN_0086b930(unsigned int size);
};
extern S6b1280_Heap DAT_01090a78;
extern long (__stdcall* DAT_00d9b068)(long volatile* addend);

template <class T> class S6b1280_Ptr {
public:
    S6b1280_Ptr(T* p) : m_p(p) { DAT_00d9b068(&p->m_refCount); }
    ~S6b1280_Ptr();
    T* m_p;
};

class S6b1280_Owner {
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
    virtual void vd0(void* obj, int a, int b, unsigned int id, int c);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    char unk1c;
    char unk1d;
    bool unk1e;
};


class S6b1280_Holder {
public:
    S6b1280_Owner* FUN_00410f00();
};

class S6b1280_Parent {
public:
    float FUN_004d5350();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int unk24;
    S6b1280_Holder unk28;
};

struct S6b1280_Script10 {
    S6b1280_Handle FUN_00424270();

};
struct S6b1280_Script {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S6b1280_Script10* unk10;
};
S6b1280_Script* FUN_00477d90(void* obj);
struct S6b1280_ActorScript10 { S6b1280_Handle FUN_00424270(); };
struct S6b1280_ActorScript {
    int unk00, unk04, unk08, unk0c;
    S6b1280_ActorScript10* unk10;
};
struct S6b1280_ActorScene;
S6b1280_ActorScript* FUN_00477d90(S6b1280_ActorScene* obj);
int FUN_0051de60();

class S6b1280_Ref;
class S6b1280_Mgr;
class S6b1280_Source;

class S6b1280_Refr {
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
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual void* v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const S6b1280_Point3* v1f4();
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
    virtual float v2e4();
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
    S6b1280_Ref* FUN_00764ea0();
    S6b1280_Handle FUN_00766b00();
    void FUN_006b1280();
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
    S6b1280_Parent* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    S6b1280_Mgr* unk60;
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
    S6b1280_Source* unk8c;
};

class S6b1280_Source {
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
    virtual S6b1280_Refr* v2c();
};

class S6b1280_Check {
public:
    bool FUN_008257f0();
};
extern S6b1280_Check* DAT_01079ca4;
extern bool DAT_0107a0f2;
extern float DAT_00e0abd0;

class S6b1280_Small {
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    S6b1280_Small(float scale, int count);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class __declspec(align(16)) S6b1280_Data {
public:
    S6b1280_Data(int kind);
    ~S6b1280_Data();
    void FUN_006a8f30(S6b1280_Small* small);
    float x;
    float y;
    float z;
    int unk0c;
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
    void* unk80;
    int unk84;
    S6b1280_Owner* unk88;
    float unk8c;
    float unk90;
    bool unk94;
    int unk98;
    int unk9c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
};

class S6b1280_Mgr {
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
    virtual void v228();
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
    virtual void v28c(S6b1280_Ptr<S6b1280_Ref> ref);
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

struct S6b1280_SceneNode {
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
    void* unk310;
};
struct S6b1280_Scene {
    int unk00;
    int unk04;
    S6b1280_SceneNode* unk08;
};
struct S6b1280_Body {
    S6b1280_Scene* FUN_0091ddd0();
};
struct S6b1280_Ctrl {
    void* FUN_008f9c90(int a);
};

void FUN_00aeeca0(void* obj, int a);
void FUN_008f3510(void* obj);
void FUN_008d7b90(void* node, int a, bool b, bool c, bool d);
void FUN_008d7720(void* obj, bool a, bool b);

class S6b1280_Ref {
public:
    static void* operator new(unsigned int size)
    {
        char* p = (char*)DAT_01090a78.FUN_0086b930(size + 0x10);
        unsigned char pad = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
        p += pad;
        p[-1] = pad;
        return p;
    }
    static void operator delete(void* p);
    S6b1280_Ref(S6b1280_Data& data, S6b1280_Refr* owner);
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
    virtual void vcc(int a);
    void FUN_008e9e90(int time, S6b1280_Refr* owner);
    void bhkCharacterController_SetWorld(S6b1280_Owner* owner);
    void FUN_004e94e0(void* obj);
    void* FUN_006a8fb0();
    void FUN_004e6580(S6b1280_Point3* pos);
    void FUN_0061f4f0(unsigned int* id);
    S6b1280_Scene* GetScene() { return unk08 ? unk08->FUN_0091ddd0() : 0; }
    void* GetCtrlObj() { return unk424 ? unk424->FUN_008f9c90(0) : 0; }
    long volatile m_refCount;
    S6b1280_Body* unk08;
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
    unsigned int unk294;
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
    float unk3c8;
    int unk3cc;
    int unk3d0;
    float unk3d4;
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
    S6b1280_Ctrl* unk424;
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
};

// pdb: MagicFogProjectile::InitHavok | MagicFogProjectile.obj | fnv360_0822_retail, vtable, medium
void S6b1280_Refr::FUN_006b1280()
{
    if (unk60 && unk60->unk28 == 0) {
        S6b1280_Ref* ref = FUN_00764ea0();
        S6b1280_Parent* parent = unk3c;
        S6b1280_Owner* owner;
        if (parent) {
            if (parent->unk24 & 1)
                owner = parent->unk28.FUN_00410f00();
            else
                owner = (S6b1280_Owner*)DAT_01071564;
        } else {
            owner = 0;
        }
        if (!ref) {
            S6b1280_Data data(1);
            data.unk8c = v2e4();
            data.unk80 = v1d0();
            const S6b1280_Point3* pos = v1f4();
            data.x = pos->x * FUN_00dbe7c0;
            data.y = pos->y * FUN_00dbe7c0;
            data.z = pos->z * FUN_00dbe7c0;
            data.unk88 = owner;
            data.unk90 = 0.0f;
            data.FUN_006a8f30(new S6b1280_Small(1.0f, 1));
            data.unk94 = false;
            S6b1280_Source* source = unk8c;
            S6b1280_Refr* actor = 0;
            if (source)
                actor = source->v2c();
            if (!DAT_01079ca4->FUN_008257f0()) {
                unsigned int id;
                if (actor) {
                    if (actor->v100()) {
                        id = actor->FUN_00766b00().GetID();
                    } else {
                        S6b1280_ActorScript* script = FUN_00477d90((S6b1280_ActorScene*)actor->v1d0());
                        if (script && script->unk10)
                            id = script->unk10->FUN_00424270().GetID();
                        else
                            id = FUN_0051de60();
                    }
                } else {
                    S6b1280_Script* script = FUN_00477d90(v1d0());
                    if (script && script->unk10)
                        id = script->unk10->FUN_00424270().GetID();
                    else
                        id = FUN_0051de60();
                }
                data.unk84 = (id << 16) | 7;
            } else {
                data.unk84 = 7;
            }
            data.unk9c = 6;
            ref = new S6b1280_Ref(data, this);
            ref->unk3d4 = 1.0f;
            if (DAT_0107a0f2)
                ref->unk294 |= 0x100000;
            else
                ref->unk294 &= ~0x100000;
            ref->unk294 |= 0x80000;
            unk60->v28c(ref);
            ref->FUN_008e9e90(1000, this);
        }
        if (parent && owner)
            ref->unk3c8 = parent->FUN_004d5350() * FUN_00dbe7c0;
        else
            ref->unk3c8 = DAT_00e0abd0;
        S6b1280_SceneNode* sceneNode = ref->GetScene()->unk08;
        void* node = sceneNode ? sceneNode->unk310 : 0;
        ref->bhkCharacterController_SetWorld(owner);
        void* obj3D = v1d0();
        if (ref->GetCtrlObj() != obj3D) {
            ref->FUN_004e94e0(obj3D);
            if (owner && owner->unk1e) {
                ref->vcc(0);
                FUN_00aeeca0(ref->FUN_006a8fb0(), 1);
                v310();
            }
            FUN_008f3510(obj3D);
            FUN_008d7b90(obj3D, 6, true, false, true);
        }
        S6b1280_Point3 pos = *v1f4();
        if (node != (void*)owner) {
            if (node)
                FUN_008d7720(obj3D, true, false);
            pos.z += 8.0;
        }
        if (owner) {
            ref->FUN_004e6580(&pos);
            unsigned int id;
            ref->FUN_0061f4f0(&id);
            owner->vd0(obj3D, 1, 0, id >> 16, 0);
        }
    }
}
