// fallout/misc/scenegraph.cpp: SceneGraph, StandIn (1 function)
#include "f3_common.h"

extern int DAT_01083b5c;

struct Base_00c517b0
{
    void FUN_00c517b0(char*, bool, void*);
};

struct Wrapper_00878610 : Base_00c517b0
{
    void* FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera);
};

// @f3 0x006a2e70 (community match, verified in this file)
struct Base_6a13f0
{
    void FUN_006a13f0(char* apName, bool abFlag, void* apCamera);
};

extern int DAT_00e09dbc;

// pdb: AssociatedItemEffect::AssociatedItemEffect | AssociatedItemEffect.obj | fnv360_0721_retail, call_seq, medium
// pdb params: apCaster, apSpell, apEffect
void* Wrapper_00878610::FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera)
{
    ((Base_6a13f0*)this)->FUN_006a13f0(apSceneGraphName, abMenuSceneGraph, apCamera);
    *(void**)this = (void*)&DAT_00e09dbc;
    *(int*)((char*)this + 0x48) = *(int*)(*(int*)((char*)apCamera + 0x14) + 0x60);
    return this;
}


extern int DAT_01083b5c;
