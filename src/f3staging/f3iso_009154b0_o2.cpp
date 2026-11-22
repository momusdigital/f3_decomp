#include <new>
// src/f3staging/f3iso_009154b0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009154b0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009154b0 (community match, verified in this file)
struct FUN_00914ad0
{
    float time;
    float value1;
    float value2;
    FUN_00914ad0();
};
struct FUN_00914ad0Array
{
    void* m_pBase;
    unsigned int m_uiAlloced;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;
    unsigned int m_uiESize;
    void FUN_009147c0(unsigned int count);
};
struct S9154_Controller
{
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(float time);
    int unk04;
    unsigned short flags;
    float frequency;
    float phase;
    float start;
    float end;
    int unk1c[7];
    FUN_00914ad0Array keys;
    int unk4c[3];
    unsigned int mode;
    void FUN_00914c00();
    void FUN_00915470(FUN_00914ad0* key);
};
struct S9154_Shape { int unk00[7]; unsigned int flags; };
struct S9154_BodyBase { int unk00[4]; };
struct S9154_Body : S9154_BodyBase, S9154_Shape {};
struct S9154_Link
{
    int unk00, unk04;
    S9154_Body* body;
    S9154_Shape* GetShape() const { return body; }
    unsigned int GetFlags() const
    {
        S9154_Shape* s = GetShape();
        return s ? s->flags : 0;
    }
};
struct S9154_Extra
{
    int unk00[4];
    S9154_Link* link;
    int unk14;
    float start;
    float end;
    float GetStart() const { return start; }
    float GetEnd() const { return end; }
};
struct S9154_Node;
struct S9154_Object
{
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual S9154_Node* AsNode();
    S9154_Controller* FUN_00825200(const void* rtti);
};
struct S9154_Node : S9154_Object
{
    char pad[0x9c];
    S9154_Object** children;
    unsigned short unka4;
    unsigned short childCount;
};
struct S9154_Range { float start; float end; };
extern S9154_Range DAT_00f7aa78[];
extern S9154_Range DAT_00f7a978[];
extern const char DAT_010f32f8;
extern const float DAT_00db7260;
void* __cdecl FUN_007235f0(void* object);

// pdb: bhkBlendController::DoHit | bhkBlendController.obj | fnv360_0822_retail, call_gap, low
// pdb params: apObject, afTime, abQuad
void __cdecl FUN_009154b0(S9154_Object* object, float middle, bool alternate)
{
    if (!object)
        return;

    S9154_Extra* blendCollisionObject = reinterpret_cast<S9154_Extra*>(FUN_007235f0(static_cast<void*>(object)));
    if (blendCollisionObject) {
        unsigned flags = 0;
        if (blendCollisionObject->link)
            flags = blendCollisionObject->link->GetFlags();
        unsigned tableIndex = (flags >> 8) & 31;

        float first;
        float last;
        if (alternate) {
            first = DAT_00f7aa78[tableIndex].start;
            last = DAT_00f7aa78[tableIndex].end;
        } else {
            first = DAT_00f7a978[tableIndex].start;
            last = DAT_00f7a978[tableIndex].end;
        }

        float objectStart = blendCollisionObject->GetStart();
        float start = objectStart < first ? objectStart : first;
        float objectEnd = blendCollisionObject->GetEnd();
        float end = objectEnd < last ? objectEnd : last;
        S9154_Controller* blendController = object->FUN_00825200(&DAT_010f32f8);
        if (blendController && blendController->mode <= 1) {
            blendController->FUN_00914c00();
            blendController->mode = 1;
            if (blendController->keys.m_uiESize == 0) {
                FUN_00914ad0 keys[3];
                keys[0].value1 = start;
                keys[0].value2 = end;
                keys[0].time = 0.0f;
                keys[1].value1 = first;
                keys[1].value2 = last;
                keys[1].time = 0.15f;
                keys[2].value1 = 1.0f;
                keys[2].value2 = 1.0f;
                keys[2].time = 0.5f;
                blendController->keys.FUN_009147c0(3);
                for (unsigned i = 0; i < 3; ++i)
                    blendController->FUN_00915470(&keys[i]);
                blendController->start = 0.0f;
                blendController->end = 1.0f;
                blendController->frequency = 1.0f;
                blendController->phase = 0.0f;
                blendController->flags = (blendController->flags & 0xfff5) | 0x1c5;
                blendController->v35(DAT_00db7260);
            }
        }
    }

    S9154_Node* node = object->AsNode();
    if (node) {
        for (unsigned i = 0; i < node->childCount; ++i)
            FUN_009154b0(node->children[i], middle, alternate);
    }
}
