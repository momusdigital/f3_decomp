// fallout_shared/tesscriptrunmanager.cpp: ScriptRunner, ScriptExecutor (0 functions)
#include "f3_common.h"
#include "tesscriptrunmanager_layout.h"
#include "tesscriptrunmanager_form.h"
#include "Script.h"
#include "ScriptReferencedObject.h"
#include "ScriptFunctionInfo.h"
#include "TESObjectREFR.h"
#include "original_script.h"
#include "game_constants.h"
#include "ScriptHeaderData.h"
#include "ScriptLocals.h"
#include "ExpressionEvaluator.h"
#include "TESQuest.h"
#include "TESGlobal.h"
#include <new>
#include "tesscriptrunmanager_decls.h"
extern ScriptFunctionInfo g_scriptBlocks[kScriptBlockCount];
extern const char* g_expressionErrorStrings[];
extern void DebugLog(const char* format, ...);
extern bool IsScriptDebuggingEnabled();
extern const char* PrepareScriptMessage(const char* message, bool localized);

struct TLSData_005e23f0
{
    char pad[0x268];
    bool bVal;
};

static __declspec(thread) TLSData_005e23f0 s_tlsData_005e23f0;

namespace fnv_005e1160 {
class TESObjectREFR
{
  public:
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    void Get3D(NiNode* niNode, bool unloadArt);
    TESObject* GetObjectReference();
};

class ScriptRunner
{
  public:
    TESObjectREFR* m_pReference;
    TESObject* m_pScriptObject;
    ScriptLocals* m_pScriptLocals;
    TESTopicInfo* m_pTopicInfo;
    TESGlobal* m_pGlobal;
    Script* m_pScript;
    SCRIPT_ERROR m_eScriptError;
    EXPRESSION_ERROR m_eExpressionError;
    int m_iIfStackDepth;
    int m_aiIfStack[10];
    int m_iBlockStackDepth;
    int m_aiBlockOffsets[10];
    int m_aiBlockSizes[10];
    bool m_bScriptCompileFailed;
    bool m_bExecutionFlagSet;

    ScriptRunner();
    bool ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                     TESObjectREFR** reference, bool skipReference);
    void SetErrorMessage(Script* script, char* message, ...);
    bool ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                    const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber, bool skip,
                    bool skipBlock);
    void SetError(Script* script, SCRIPT_ERROR error);
    bool RunScript(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target, bool arg5,
             bool arg6, bool arg7, float arg8);
};

}  // namespace fnv_005e1160

// @f3 0x00981330 (community match, verified in this file)
namespace f3m_00981330 {
namespace c_00981330 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct Motion { int unk00[0x14]; Vec4 pos; };
struct Entity {
    int unk00[0x1b];
    Motion* motion;
    int unk70[4];
    int unk80;
    int lockCount;
    int unk88;
    char unk8c;
    void FUN_00902550();
};
void __cdecl FUN_009808f0(void* a, void* b, Entity* e);
struct World {
    void FUN_00981160(void* a, void* b, Motion* m, void* e);
    void hkpSimulation_collideEntitiesDiscrete(void* a, void* b, Entity* entity, const Vec4* pos, void* e);
};
// pdb: hkpSimulation::collideEntitiesDiscrete | hkpSimulation.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void World::hkpSimulation_collideEntitiesDiscrete(void* a, void* b, Entity* entity, const Vec4* pos, void* e)
{
    Vec4 saved = *pos;
    Motion* m = entity->motion;
    m->pos = *pos;
    entity->lockCount++;
    FUN_009808f0(a, b, entity);
    FUN_00981160(a, b, m, e);
    if (--entity->lockCount == 0 && !entity->unk8c && entity->unk80)
        entity->FUN_00902550();
    m->pos = saved;
}
}
}   // namespace f3m_00981330
