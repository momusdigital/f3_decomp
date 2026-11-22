#include <stdexcept>
#include <new>
#include <new>
#include <new>
#include <new>
#include <new>
#include <string>
#include <vector>
#include <string.h>
#include <new>
#include <intrin.h>
#include <string.h>
// src/f3staging/f3blk_00580000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00599370 (community match, verified in this file)
namespace f3m_00599370 {
namespace f3m_00599370 {

struct Actor;
struct AnimList {
    int unk00,unk04,unk08; float* values; unsigned count;
    __forceinline bool get(unsigned i,float& out){if(i<count){out=values[i];return true;}return false;}
    __forceinline float value(unsigned i){return i<count?values[i]:0.0f;}
};
struct Data { int a,b; bool c; Data():a(0),b(0),c(false){} };
struct Context { Actor* actor; Data data; void* helper; void* keyword; unsigned count; bool loaded; };
struct Helper { void FUN_00597740(int, int, Actor*, int, float); };

extern void FUN_0058ae60(Actor*, Data*);
extern void FUN_0058a940(float, float, float*, float*);

struct Actor {
    virtual void v00();
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    AnimList anims;
};

struct Owner {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual Actor* getActor();
    void FUN_00599370(Context*);
};

// pdb: BSFaceGenNiNode::ApplyFacialModifiers | BSFaceGenNiNode.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arObjData
void Owner::FUN_00599370(Context* ctx)
{
    float left, right;
    for (int i = 0; i < 17; ++i) {
        float weight = 0.0f;
        switch (i) {
        case 8:
        case 11:
            FUN_0058a940(((AnimList*)((char*)getActor() + 0xa8))->value(8),
                         ((AnimList*)((char*)getActor() + 0xa8))->value(11), &left, &right);
            weight = (i == 8) ? left : right;
            break;
        case 9:
        case 10:
            FUN_0058a940(((AnimList*)((char*)getActor() + 0xa8))->value(9),
                         ((AnimList*)((char*)getActor() + 0xa8))->value(10), &left, &right);
            weight = (i == 9) ? left : right;
            break;
        case 14:
        case 15:
        case 16:
            break;
        default:
        case 12:
        case 13:
            {
                Actor* actor = getActor();
                if (i >= 17 || !actor->anims.get(i, weight))
                    continue;
            }
            break;
        }
        if (weight > 0.0f && weight <= 1.0f) {
            if (!ctx->loaded) {
                FUN_0058ae60(ctx->actor, &ctx->data);
                ctx->loaded = true;
            }
            ((Helper*)ctx->helper)->FUN_00597740(2, i, ctx->actor, (int)ctx->keyword, weight);
        }
    }
}

}
}   // namespace f3m_00599370
