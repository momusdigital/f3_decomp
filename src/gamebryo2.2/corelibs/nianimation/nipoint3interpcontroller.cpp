#include "f3_common.h"
// gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller.cpp: free functions (6 functions)
#include "nipoint3interpcontroller_decls.h"

struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiPoint3
{
    float x, y, z;
};
struct NiPoint3InterpolatorStandIn
{
    NiPoint3InterpolatorStandIn* FUN_00a49650(NiPoint3 v);
};
typedef void(__thiscall* GetPoint3Fn)(void*, NiPoint3*);

// @fnv 0x00a57c20
// pdb: NiPoint3InterpController::CreatePoseInterpolator | NiPoint3InterpController.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void* __fastcall NiPoint3InterpController_CreatePoseInterpolator(void* self, int, unsigned short usIndex)
{
    NiPoint3 kValue;
    (*(GetPoint3Fn**)self)[0xec / 4](self, &kValue);
    void* pMemory = BSFadeNode::operator new(0x20);
    NiPoint3InterpolatorStandIn* pInterpolator = (NiPoint3InterpolatorStandIn*)pMemory;
    if (pInterpolator)
        return pInterpolator->FUN_00a49650(kValue);
    return 0;
}

extern const char* const g_011f3f88_arg1;

namespace fnv_00a57cb0 {
struct NiPoint3
{
    float x, y, z;
};
struct NiPoint3InterpolatorStandIn
{
    void FUN_00a494b0(NiPoint3 v);
};
typedef void(__thiscall* GetPoint3Fn)(void*, NiPoint3*);

}  // namespace fnv_00a57cb0

struct ActorCombatGroup;
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTArray
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > CombatGroupArray;
extern const char* const g_011f3f88_arg1;

extern unsigned int DAT_011f404c;

// @fnv 0x00a532c0
// pdb: NiTask::GetRTTI | BSTECreateTask.obj | fnv360_0822_retail, vtable, medium
unsigned int* __cdecl FUN_00a532c0()
{
    return &DAT_011f404c;
}

struct S_00a53280_Foo
{
    void* unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    void* unk10;
    int unk14;

    void FUN_00a3ca10();
    void* FUN_00a53280(void* arg);
};

extern void(__stdcall* FUN_00fdf1c0)(void*);

// @fnv 0x00a53280
// pdb: NiBoolInterpolator::NiBoolInterpolator | NiBoolInterpolator.obj | fnv360_0822_retail, call_gap, high
// pdb params: pkBoolData
void* S_00a53280_Foo::FUN_00a53280(void* arg)
{
    FUN_00a3ca10();

    unk00 = (void*)&DAT_0109a0b4;
    unk0c = DAT_0109a914;
    unk10 = arg;

    if (arg)
    {
        FUN_00fdf1c0((void*)((unsigned char*)arg + 4));
    }

    unk14 = 0;
    return this;
}
