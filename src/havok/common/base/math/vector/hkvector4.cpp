#include "f3_common.h"
// src/havok/common/base/math/vector/hkvector4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// CheckFloatsFinite (0x00c7f4e0, 21 bytes)
//
// The original is a __thiscall member of a class whose object *is* the float
// array.  It forwards to a file-static helper FUN_00c7f4a0(out, self, count).
//
// MSVC 2008 gives an internal-linkage (file-static) helper its own internal
// "register argument" convention: instead of pushing the arguments on the
// stack they are passed in registers.  With the helper declared as
//     static void* FUN_00c7f4a0(void* out, void* self, int count)
// MSVC 2008 assigns  out->EAX, self->ESI, count->EDX  and the call site
// becomes exactly
//     mov eax,[esp+4] / push esi / mov edx,3 / mov esi,ecx / call / pop esi / ret 4
// The helper returns its first argument, which is what pins that argument
// to EAX; the parameter order (out, self, count) is what makes the call site
// materialise EDX before ESI.

struct Cls_c7f4e0
{
    float unk00[8];
    void CheckFloatsFinite(void* out);
};

static __declspec(noinline) void* FUN_00c7f4a0(void* out, void* self, int count)
{
    for (int i = 0; i < count; i++)
    {
        float v = ((float*)self)[i];
        int bits = *(int*)&v;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *(char*)out = 0;
            return out;
        }
    }
    *(char*)out = 1;
    return out;
}

// @fnv 0x00c7f4e0
// pdb: NiAVObject::QPlayer | bhkCollisionObject.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkVector4::isOk3)
void Cls_c7f4e0::CheckFloatsFinite(void* pResult)
{
    FUN_00c7f4a0(pResult, this, 3);
}

#include <xmmintrin.h>
extern __m128 DAT_01267e30;

struct FUN_00c7f700_cls
{
    __m128 m_result;
    void FUN_00c7f700(void* first, void* second);
};

struct VecSource
{
    __m128* FUN_00cac910();
};

struct HolderNode
{
    int unk00;
    int unk04;
    char* m_p08;
};

struct FUN_00c6e300_cls
{
    int unk00;
    int unk04;
    VecSource* m_p08;
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
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk288;
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
    HolderNode* m_p594;

    void FUN_00c89720();
    void SubtractVectors(__m128* out);
};

// Subtracts res.m_result from the selected vector and stores the difference in out.
// @fnv 0x00c6e300
void FUN_00c6e300_cls::SubtractVectors(__m128* apResult)
{
    HolderNode* holder = m_p594;
    char* base = holder ? holder->m_p08 : 0;

    FUN_00c7f700_cls res;
    res.FUN_00c7f700(base + 0xb0, (char*)this + 0x570);

    __m128* vec = &DAT_01267e30;
    VecSource* src = m_p08;
    if (src != 0)
    {
        FUN_00c89720();
        vec = src->FUN_00cac910();
        FUN_00c89720();
    }

    __m128 a = *vec;
    __m128 b = res.m_result;
    *apResult = _mm_sub_ps(a, b);
}

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    void FUN_00c7f690(void* transform, const Vec4* value);
    void FUN_00c7f700(void* transform, const Vec4* value);
};

typedef __m128 VecArr;

struct HkBool
{
    char m_cBooleanValue;
    HkBool()
    {}
    HkBool(bool b) : m_cBooleanValue((char)b)
    {}
};

struct HitResult;

struct CastInput
{
    Vec4 from;
    Vec4 to;
    unsigned int unk20;
    void* unk24;
    CastInput() : unk20(0), unk24(0)
    {}
};

struct CollisionObject
{
    virtual void ReportDiagnostic() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void FlushUsageData() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual HkBool RayCast(const CastInput& input, HitResult& result) const = 0;
    int unknown04;
    int unknown08;
    int type0c;
};

struct HitResult
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int faceIndex;
    float unknown18, unknown1c;
    unsigned int shapeKeys[8];
    unsigned int flag40;
    int unknown44;
    int unknown48;
    int unknown4c;
    HitResult()
    {
        reset();
    }
    void reset()
    {
        fraction = 1.0f;
        faceIndex = -1;
        shapeKeys[0] = (unsigned int)-1;
        flag40 = 0;
    }
};

struct Geometry
{
    CollisionObject* collision;
    int unk04;
    void* transform;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int flags;
};

struct State
{
    int* itemAt(int index) const
    {
        return *(int**)(*(char**)((char*)this + 0x160) + index * 8 + 4);
    }
    int count() const
    {
        return *(int*)((char*)this + 0x164);
    }
};

struct bhkCharacterController;
extern float __fastcall GetSettingFloat(bhkCharacterController* controller);

extern float DAT_01011d78;
extern double DAT_010290b0;

struct bhkCharacterController
{
    void SubtractVectors(Vec4* result);
    bool FUN_00c6fa20();
};

// Casts rays between transformed points, adjusts both z coordinates by advance, and returns true when a cast fraction is below 1.
// @f3 0x008ec1a0 (community match, verified in this file)
namespace native1955 {
struct StateEntry {unsigned unknown;Geometry* geometry;};
struct TransformView {Vec4 columns[4];};
struct StateView {unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c;TransformView transform;unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c;StateEntry* entries;int numEntries;Geometry* itemAt(int i)const{return entries[i].geometry;}int count()const{return numEntries;}};
struct NodeView {unsigned unk00,unk04;StateView* state;};
struct ControllerView {unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned unk204; unsigned unk208; unsigned unk20c; unsigned unk210; unsigned unk214; unsigned unk218; unsigned unk21c; unsigned unk220; unsigned unk224; unsigned unk228; unsigned unk22c; unsigned unk230; unsigned unk234; unsigned unk238; unsigned unk23c; unsigned unk240; unsigned unk244; unsigned unk248; unsigned unk24c; unsigned unk250; unsigned unk254; unsigned unk258; unsigned unk25c; unsigned unk260; unsigned unk264; unsigned unk268; unsigned unk26c; unsigned unk270; unsigned unk274; unsigned unk278; unsigned unk27c; unsigned unk280; unsigned unk284; unsigned unk288; unsigned unk28c; unsigned unk290; unsigned unk294; unsigned unk298; unsigned unk29c; unsigned unk2a0; unsigned unk2a4; unsigned unk2a8; unsigned unk2ac; unsigned unk2b0; unsigned unk2b4; unsigned unk2b8; unsigned unk2bc; unsigned unk2c0; unsigned unk2c4; unsigned unk2c8; unsigned unk2cc; unsigned unk2d0; unsigned unk2d4; unsigned unk2d8; unsigned unk2dc; unsigned unk2e0; unsigned unk2e4; unsigned unk2e8; unsigned unk2ec; unsigned unk2f0; unsigned unk2f4; unsigned unk2f8; unsigned unk2fc; unsigned unk300; unsigned unk304; unsigned unk308; unsigned unk30c; unsigned unk310; unsigned unk314; unsigned unk318; unsigned unk31c; unsigned unk320; unsigned unk324; unsigned unk328; unsigned unk32c; unsigned unk330; unsigned unk334; unsigned unk338; unsigned unk33c; unsigned unk340; unsigned unk344; unsigned unk348; unsigned unk34c; unsigned unk350; unsigned unk354; unsigned unk358; unsigned unk35c; unsigned unk360; unsigned unk364; unsigned unk368; unsigned unk36c; unsigned unk370; unsigned unk374; unsigned unk378; unsigned unk37c; unsigned unk380; unsigned unk384; unsigned unk388; unsigned unk38c; unsigned unk390; unsigned unk394; unsigned unk398; unsigned unk39c; unsigned unk3a0; unsigned unk3a4; unsigned unk3a8; unsigned unk3ac; unsigned unk3b0; unsigned unk3b4; unsigned unk3b8; unsigned unk3bc; unsigned unk3c0; unsigned unk3c4; unsigned unk3c8; unsigned unk3cc; unsigned unk3d0; unsigned unk3d4; unsigned unk3d8; unsigned unk3dc; unsigned unk3e0; unsigned unk3e4; unsigned unk3e8; unsigned unk3ec;float advance;unsigned unk3f4; unsigned unk3f8; unsigned unk3fc; unsigned unk400; unsigned unk404; unsigned unk408; unsigned unk40c; unsigned unk410; unsigned unk414; unsigned unk418; unsigned unk41c; unsigned unk420;NodeView* node;};
}
// pdb: bhkCharacterController::CheckInsideOfObject | bhkCharacterController.obj | fnv360_0822_retail, call_gap, low
bool bhkCharacterController::FUN_00c6fa20()
{
    native1955::ControllerView* view = reinterpret_cast<native1955::ControllerView*>(this);
    native1955::NodeView* node = view->node;
    native1955::StateView* state = node ? node->state : 0;
    float advance = view->advance * DAT_010290b0;
    float range = GetSettingFloat(this) + 4.572055339813232;
    Vec4 value;
    value.x = 0.0f; value.y = range; value.z = 0.0f; value.w = 0.0f;
    native1955::StateView* transformState = node ? node->state : 0;
    value.FUN_00c7f700(&transformState->transform, &value);
    Vec4 vStart;
    this->SubtractVectors(&vStart);
    Vec4 vFinish;
    vFinish.x = vStart.x + value.x;
    vFinish.y = vStart.y + value.y;
    vFinish.z = vStart.z + value.z;
    vFinish.w = vStart.w + value.w;

    for (int i = 0; i < state->count(); ++i)
    {
        Geometry* geom = (Geometry*)state->itemAt(i);
        if (!geom)
            continue;
        switch (geom->flags & 0x7f)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 16:
        case 17:
        case 22:
        case 23:
        case 24:
        case 29:
        case 30:
            continue;
        }
        CollisionObject* __restrict shape = geom->collision;
        if (shape->type0c != 9 && shape->type0c != 7 && shape->type0c != 11)
            continue;

        Geometry* __restrict body = geom;
        CastInput input;
        HitResult result;
        input.from.FUN_00c7f690(body->transform, &vStart);
        input.to.FUN_00c7f690(geom->transform, (Vec4*)&vFinish);

        bool hit = false;
        unsigned int j = 0;
        do
        {
            result.fraction = 1.0f;
            input.from.z += advance;
            input.to.z += advance;
            result.faceIndex = -1;
            result.shapeKeys[0] = (unsigned int)-1;
            result.flag40 = 0;
            shape->RayCast(input, result);
            if (result.fraction < 1.0f)
            {
                hit = true;
                break;
            }
        } while (++j < 3);

        input.from.FUN_00c7f690(geom->transform, (Vec4*)&vFinish);
        input.to.FUN_00c7f690(geom->transform, &vStart);

        if (!hit)
        {
            for (unsigned int j = 0; j < 3; ++j)
            {
                result.fraction = 1.0f;
                input.from.z += advance;
                input.to.z += advance;
                result.faceIndex = -1;
                result.shapeKeys[0] = (unsigned int)-1;
                result.flag40 = 0;
                shape->RayCast(input, result);
                if (result.fraction < 1.0f)
                {
                    return true;
                }
            }
        }
    }
    return false;
}


struct __declspec(align(16)) SpawnedMatrix
{
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
};

struct __declspec(align(16)) FUN_00c7f640_cls
{
    __m128 m_vResult;

    void FUN_00c7f640(const SpawnedMatrix* apMatrix, const __m128* apVector);
};

struct S_00c7f690_V
{
    __m128 q;
};
struct S_00c7f690_M
{
    S_00c7f690_V c0, c1, c2, c3;
};
struct FUN_00c7f690_cls
{
    void FUN_00c7f690(const S_00c7f690_M* m, const S_00c7f690_V* v);
};

// Subtracts m->c3 from v, multiplies the difference by components assembled from m->c0 through m->c2, and stores the result in this.
// @fnv 0x00c7f690
void FUN_00c7f690_cls::FUN_00c7f690(const S_00c7f690_M* apMatrix, const S_00c7f690_V* apVector)
{
    S_00c7f690_V vDelta;
    vDelta.q = _mm_sub_ps(apVector->q, apMatrix->c3.q);
    __m128 a0 = apMatrix->c0.q, a1 = apMatrix->c1.q, a2 = apMatrix->c2.q;
    __m128 vTmp0 = _mm_unpacklo_ps(a0, a1);
    __m128 vTmp1 = _mm_unpackhi_ps(a0, a1);
    a0 = _mm_movelh_ps(vTmp0, a2);
    a1 = _mm_shuffle_ps(_mm_movehl_ps(a0, vTmp0), a2, 0xd4);
    a2 = _mm_shuffle_ps(vTmp1, a2, 0xe4);
    __m128 x = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x00);
    __m128 y = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x55);
    __m128 z = _mm_shuffle_ps(vDelta.q, vDelta.q, 0xaa);
    ((S_00c7f690_V*)this)->q = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a1), _mm_mul_ps(x, a0)), _mm_mul_ps(a2, z));
}

namespace fnv_00c7f700 {
struct MatrixRows3x4
{
    __m128 row0;
    __m128 row1;
    __m128 row2;
    __m128 row3;
};

struct FUN_00c7f700_cls
{
    __m128 m_result;

    void FUN_00c7f700(MatrixRows3x4* matrix, __m128* vec);
};

// Multiplies a 3D vector by the first three rows of a 3x4 matrix and stores the result in m_result.
// @fnv 0x00c7f700
void FUN_00c7f700_cls::FUN_00c7f700(MatrixRows3x4* matrix, __m128* apVector)
{
    __m128 v = *apVector;
    __m128 vx = _mm_shuffle_ps(v, v, 0x00);
    __m128 vy = _mm_shuffle_ps(v, v, 0x55);
    __m128 vz = _mm_shuffle_ps(v, v, 0xaa);

    __m128 r = _mm_mul_ps(vy, matrix->row1);
    r = _mm_add_ps(r, _mm_mul_ps(vx, matrix->row0));
    r = _mm_add_ps(r, _mm_mul_ps(vz, matrix->row2));
    m_result = r;
}
}  // namespace fnv_00c7f700

struct QueryScalar
{
    __m128 q;
    QueryScalar()
    {}
    QueryScalar(const __m128& value) : q(value)
    {}
    QueryScalar(const QueryScalar& value) : q(value.q)
    {}
    operator float() const
    {
        float v;
        _mm_store_ss(&v, q);
        return v;
    }
};
// Character support query with triangle and general shape paths.
struct Mat16;
struct QueryVector
{
    __m128 q;
    QueryVector()
    {}
    QueryScalar get(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 85);
        case 2:
            return _mm_shuffle_ps(q, q, 170);
        default:
            return _mm_shuffle_ps(q, q, 255);
        }
    }
    float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    QueryVector(const QueryVector& x)
    {
        q = x.q;
    }
    QueryVector& operator=(const QueryVector& x)
    {
        const __m128& ref = x.q;
        q = ref;
        return *this;
    }
    void FUN_00c7f640(void* a, const QueryVector* v);
    void FUN_00c7f690(const Mat16* t, const QueryVector* v);
};
struct Mat16
{
    QueryVector col[4];
};
struct BoundingVolumeNode
{
    void* f00;
    int u04;
    BoundingVolumeNode* child;
    int type;
    union
    {
        int f10;
        float radius;
    };
    int u014;
    int u018;
    int u01c;
    union
    {
        __m128 points[3];
        struct
        {
            int u020, u024, u028, u02c, u030;
            BoundingVolumeNode* f34;
        };
    };
    int FUN_00c84f10(int key);
};
struct ShapeStorage
{
    __declspec(align(16)) char bytes[512];
};
struct Iface
{
    void** vtbl;
};
typedef BoundingVolumeNode*(__thiscall* ResFn)(Iface* self, int id, ShapeStorage* out);
struct BoolResult
{
    char value;
    BoolResult(char v) : value(v)
    {}
};
typedef char(__cdecl* PredFn)(int v);
extern float DAT_01011d78;
static __forceinline void transformed(QueryVector& r, const Mat16& m, __m128 v)
{
    __m128 px = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m.col[0].q);
    __m128 py = _mm_mul_ps(_mm_shuffle_ps(v, v, 85), m.col[1].q);
    __m128 pz = _mm_mul_ps(_mm_shuffle_ps(v, v, 170), m.col[2].q);
    r.q = _mm_add_ps(_mm_add_ps(py, px), _mm_add_ps(pz, m.col[3].q));
}
