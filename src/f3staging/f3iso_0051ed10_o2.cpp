#include <new>
// src/f3staging/f3iso_0051ed10_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0051ed10 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0051ed10 (community match, verified in this file)
struct ScriptParameter; class TESObjectREFR; class Script; class ScriptLocals;
struct QuitGameState
{
    unsigned char unk00;
    bool quitRequested;
};

extern QuitGameState* DAT_0107a0d4;
extern void __cdecl FUN_006195d0(const char* format, ...);

// pdb: Script::SaveIniFiles | TESScriptFunctions.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
bool __cdecl FUN_0051ed10(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                           Script*, ScriptLocals*, double&, unsigned int&)
{
    FUN_006195d0("Bye.");
    DAT_0107a0d4->quitRequested = true;
    return true;
}
