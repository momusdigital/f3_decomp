#include <new>
// src/f3staging/f3iso_006f70e0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x006f70e0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006f70e0 (community match, verified in this file)
namespace f3m_006f70e0 {
namespace talking {
struct Actor;
struct Package {
    char unknown00[0x20];
    unsigned char kind;
    char unknown21[0x73];
    Actor* target;
};
struct Process;
struct ProcessTable {
    void* beforePackage[0x278/4];
    Package* (__thiscall* getPackage)(Process*);
    void* beforeCheck[(0x308-0x27c)/4];
    bool (__thiscall* check)(Process*);
    void* beforeTalking[(0x4b4-0x30c)/4];
    bool (__thiscall* talking)(Process*,Actor*);
};
struct Sound {
    unsigned handle;
    __declspec(noinline) bool active();
};
struct Process {
    ProcessTable* table;
    char unknown04[0x308];
    Sound sound;
    __declspec(noinline) bool highTalking(Actor*);
    bool baseTalking(Actor*);
};
struct Actor {
    char unknown00[0x60];
    Process* process;
    char unknown64[0x11];
    char talkingFlag;
    __declspec(noinline) bool hasPackage();
    bool FUN_006f70e0();
};
// pdb: Actor::IsTalking | Actor.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: TESForm::IsActor)
bool Actor::FUN_006f70e0(){
    if(talkingFlag) return true;
    if(process) return process->table->talking(process,this);
    return false;
}
}
}   // namespace f3m_006f70e0
