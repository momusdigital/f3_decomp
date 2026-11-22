// src/f3staging/f3blk_00540000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00540270 (community match, verified in this file)
class TESForm
{
  public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void MarkAsModified(unsigned int changeFlags);
    virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8();
    virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0();
    virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8();
    virtual void vdc(); virtual void ve0(); virtual void ve4(); virtual void ve8(); virtual void vec();
    virtual bool GetIsReference();
    virtual void vf4(); virtual void vf8(); virtual void vfc(); virtual void v100(); virtual void v104(); virtual void v108();
    virtual void v10c(); virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c(); virtual void v120();
    virtual void v124(); virtual void v128(); virtual void v12c();
    virtual const char* GetName();

    unsigned char cFormType;  // +0x4
    unsigned int iFormFlags;  // +0x8
    unsigned int iFormID;     // +0xC

    unsigned int GetFormID() { return iFormID; }
};

namespace N540270
{
struct ParentCell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned char unk24, unk25;
    unsigned char cCellState;  // +0x26
    bool IsOutdoorCell() { return cCellState == 6; }
};
}

class ScriptLocals;
class Script;

class TESObjectREFR : public TESForm
{
  public:
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    N540270::ParentCell* pParentCell;  // +0x3C
    ScriptLocals* GetReferenceLocals();
    bool IsTemporary() { return (iFormFlags >> 14) & 1; }
    N540270::ParentCell* GetParentCell() { return pParentCell; }
    enum { CHANGE_SCRIPT_VARIABLES = 0x80000000 };
};

class TESQuest : public TESForm
{
  public:
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c,
        unk50, unk54, unk58;
    ScriptLocals* pScriptLocals;  // +0x5C
    ScriptLocals* GetScriptLocalData() { return pScriptLocals; }
};

class TESGlobal : public TESForm
{
  public:
    int unk10, unk14, unk18, unk1c, unk20;
    float fValue;  // +0x24
    void SetValue(float value) { fValue = value; }
};

class ScriptReferencedObject
{
  public:
    int unk00, unk04;
    TESForm* pForm;  // +0x8
};

class ScriptLocals
{
  public:
    Script* m_pOwnerScript;  // +0x0
    void SetVariable(int id, double value);
};

class Script : public TESForm
{
  public:
    int unk10, unk14, unk18, unk1c;
    unsigned int dataSize;  // +0x20
    int unk24, unk28, unk2c;
    char* m_pData;  // +0x30
    char* GetData() { return m_pData; }
    ScriptReferencedObject* GetReferencedForm(int id, ScriptLocals* locals);
    const char* GetVariableName(int id);
    static bool GetValue(double& value, const char* data, unsigned int& offset, TESObjectREFR* reference,
                         TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip);
};

class ScriptFunctionInfo
{
  public:
    const char* pFunctionName;         // +0x0
    const char* pShortName;            // +0x4
    unsigned int iOutput;              // +0x8
    const char* pHelpString;           // +0xC
    bool m_bRequiresReference;         // +0x10
    unsigned short iParamCount;        // +0x12
    const ScriptParameter* pParameters;       // +0x14
    FNVScriptExecuteFunction m_pfnExecute;    // +0x18
    void* m_pfnCompile;                // +0x1C
    void* m_pfnCondition;              // +0x20
    bool unk24;                        // +0x24
    bool m_bSetsExecutionFlag;         // +0x25
    unsigned short unk26;
};

namespace N540270
{
struct Operand
{
    int unk00, unk04, unk08, unk0c;
};
}

class ExpressionEvaluator
{
  public:
    EXPRESSION_ERROR m_eExpressionError;  // +0x0
    char m_sExpression[512];              // +0x4
    char m_sExpressionBuffer[512];        // +0x204
    Stack<int, 64> m_kOperatorStack;      // +0x404
    Stack<N540270::Operand, 32> m_kOperandStack;  // +0x508
    ExpressionEvaluator();
    ~ExpressionEvaluator();
    double Eval(const char* data, TESObjectREFR* reference, TESObjectREFR* container, Script* script,
                ScriptLocals* locals, int length, bool skip);
    EXPRESSION_ERROR ExpressionError() { return m_eExpressionError; }
};

namespace N540270
{
class BSString
{
  public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSString() : pString(0), sLen(0), sMaxLen(0) {}
    ~BSString();
    int PrintfString(const char* format, ...);
    const char* String() { return pString; }
};

extern __declspec(thread) char g_tls540270[];
__forceinline bool IsScriptDebuggingEnabled() { return g_tls540270[0x250] != 0; }
}

extern ScriptFunctionInfo DAT_00f525d0[];
extern const char* DAT_00f50acc[];
void __cdecl FUN_00887da0(const char* format, ...);
void __cdecl FUN_006195d0(const char* format, ...);
ScriptFunctionInfo* __cdecl ScriptCompiler_GetFunctionDef(int opcode);
bool __cdecl FUN_00517950(const ScriptParameter* params, const char* data, unsigned int* offset,
                          TESObjectREFR* reference, TESObjectREFR* container, Script* script, ScriptLocals* locals, ...);

class ScriptRunner
{
  public:
    TESObjectREFR* m_pReference;          // +0x0
    TESForm* m_pScriptObject;             // +0x4
    ScriptLocals* m_pScriptLocals;        // +0x8
    void* m_pTopicInfo;                   // +0xC
    TESGlobal* m_pGlobal;                 // +0x10
    Script* m_pScript;                    // +0x14
    SCRIPT_ERROR m_eScriptError;          // +0x18
    EXPRESSION_ERROR m_eExpressionError;  // +0x1C
    int m_iIfStackDepth;                  // +0x20
    int m_aiIfStack[10];                  // +0x24
    int m_iBlockStackDepth;               // +0x4C
    int m_aiBlockOffsets[10];             // +0x50
    int m_aiBlockSizes[10];               // +0x78
    bool m_bScriptCompileFailed;          // +0xA0
    bool m_bExecutionFlagSet;             // +0xA1
    void SetError(Script* script, SCRIPT_ERROR error) { m_eScriptError = error; }
    bool EvaluateLine(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                      const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber,
                      bool skip, bool skipBlock);
};

// pdb: ScriptRunner::EvaluateLine | TESScriptRunManager.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool ScriptRunner::EvaluateLine(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                                const unsigned int inputOffset, unsigned int& lineOffset,
                                const unsigned int lineNumber, bool skip, bool skipBlock)
{
    unsigned int offset = inputOffset;
    const char* data = script->GetData();
    if (output == SCRIPT_OUTPUT_FLOW_BEGIN)
    {
        int blockID = *reinterpret_cast<const short*>(data + offset);
        offset += 2;
        if (blockID < 0 || blockID >= 36)
        {
            FUN_00887da0("Invalid script block for BEGIN on line %i of script '%s' (%08X).", lineNumber,
                         script->GetName(), script->GetFormID());
            return false;
        }
        int skipSize = *reinterpret_cast<const int*>(data + offset);
        offset += 4;
        const ScriptParameter* blockParams = DAT_00f525d0[blockID].pParameters;
        FNVScriptExecuteFunction blockExecute = DAT_00f525d0[blockID].m_pfnExecute;
        if (skip)
        {
            if (blockParams && blockSize)
                FUN_00517950(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
        }
        else
        {
            if (DAT_00f525d0[blockID].m_bRequiresReference && !reference)
            {
                FUN_00887da0("SCRIPTS: Script '%s', line %d: Null for a required ref pointer.", script->GetName(),
                             lineNumber);
                return false;
            }
            double result;
            if (!blockExecute ||
                !blockExecute(blockParams, data, reference, m_pReference, script, m_pScriptLocals, result, offset))
            {
                FUN_00887da0("SCRIPTS: Script '%s', line %d: Error Executing line (Offset %d).", script->GetName(),
                             lineNumber, offset);
                return false;
            }
            if (!result || skipBlock)
                blockSize += skipSize;
        }
    }
    else if (!skipBlock)
    {
        const ScriptFunctionInfo* function;
        switch (output)
        {
        case SCRIPT_OUTPUT_FLOW_SCRIPTNAME:
            break;
        case SCRIPT_OUTPUT_FLOW_BEGIN:
            break;
        case SCRIPT_OUTPUT_FLOW_END:
            break;
        case SCRIPT_OUTPUT_FLOW_SET: {
            char varType = data[offset];
            offset++;
            short variableID = 0;
            ScriptLocals* currentPScriptVariables = m_pScriptLocals;
            ScriptReferencedObject* referencedObject = 0;
            switch (varType)
            {
            case 'G':
            case 'r': {
                short referenceID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
                if (varType == 'r')
                {
                    varType = data[offset];
                    offset++;
                }
                referencedObject = script->GetReferencedForm(referenceID, m_pScriptLocals);
                if (!skip)
                {
                    if (varType != 'r' && referencedObject && referencedObject->pForm)
                    {
                        TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(referencedObject->pForm);
                        if (object)
                            currentPScriptVariables = object->GetReferenceLocals();
                        else
                        {
                            TESQuest* quest = dynamic_cast<TESQuest*>(referencedObject->pForm);
                            if (quest)
                                currentPScriptVariables = quest->GetScriptLocalData();
                        }
                        if (!currentPScriptVariables)
                        {
                            FUN_00887da0("Missing script variables on object for SET on line %i of script '%s' (%08X).",
                                         lineNumber, script->GetName(), script->GetFormID());
                            return false;
                        }
                    }
                    else
                    {
                        FUN_00887da0("Missing ref object in SET on line %i of script '%s' (%08X).", lineNumber,
                                     script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
            }
            switch (varType)
            {
            case 'G':
                break;
            default: {
                variableID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
            }
            break;
            }
            short expressionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator variableExpression;
            double expressionValue = variableExpression.Eval(data + offset, reference, m_pReference, script,
                                                             m_pScriptLocals, expressionSize, skip);
            offset += expressionSize;
            if (variableExpression.ExpressionError())
            {
                FUN_00887da0("SCRIPTS: Script '%s', line %d: Set expression returned an error: %s.\r\n",
                             script->GetName(), lineNumber, DAT_00f50acc[variableExpression.ExpressionError()]);
                script->dataSize = 0;
                return false;
            }
            if (!skip)
            {
                if (varType == 'G')
                {
                    if (referencedObject && referencedObject->pForm)
                    {
                        if (!skip)
                        {
                            static_cast<TESGlobal*>(referencedObject->pForm)
                                ->SetValue(static_cast<float>(expressionValue));
                            if (N540270::IsScriptDebuggingEnabled())
                                FUN_006195d0("set global >> %0.2f", static_cast<float>(expressionValue));
                        }
                    }
                    else
                    {
                        FUN_00887da0("Invalid variable type for SET on line %i of script '%s' (%08X).", lineNumber,
                                     script->GetName(), script->GetFormID());
                        return false;
                    }
                }
                else
                {
                    if (currentPScriptVariables)
                    {
                        switch (varType)
                        {
                        case 'l':
                        case 's':
                            currentPScriptVariables->SetVariable(variableID, static_cast<int>(expressionValue));
                            if (N540270::IsScriptDebuggingEnabled())
                                FUN_006195d0("set %s >> %i",
                                             currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                             static_cast<int>(expressionValue));
                            break;
                        case 'f':
                            currentPScriptVariables->SetVariable(variableID, expressionValue);
                            if (N540270::IsScriptDebuggingEnabled())
                                FUN_006195d0("set %s >> %.2f",
                                             currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                             expressionValue);
                            break;
                        }
                        if ((referencedObject && referencedObject->pForm) || reference)
                        {
                            TESObjectREFR* changedReference = 0;
                            if (referencedObject)
                            {
                                if (referencedObject->pForm && referencedObject->pForm->GetIsReference())
                                    changedReference = static_cast<TESObjectREFR*>(referencedObject->pForm);
                            }
                            else
                                changedReference = reference;
                            if (changedReference && !changedReference->IsTemporary())
                            {
                                if (!changedReference->GetParentCell() ||
                                    !changedReference->GetParentCell()->IsOutdoorCell())
                                    changedReference->MarkAsModified(TESObjectREFR::CHANGE_SCRIPT_VARIABLES);
                            }
                        }
                    }
                    else
                    {
                        FUN_00887da0("Missing scriptvariables for object in SET on line %i of script '%s' (%08X).",
                                     lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
        }
        case SCRIPT_OUTPUT_FLOW_IF:
            if (m_aiIfStack[m_iIfStackDepth])
                m_iIfStackDepth++;
            m_aiIfStack[m_iIfStackDepth] = 1;
        case SCRIPT_OUTPUT_FLOW_ELSEIF: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            short conditionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator condition;
            if (skip)
            {
                condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize, skip);
                m_aiIfStack[m_iIfStackDepth] |= 2;
            }
            else
            {
                if (!(m_aiIfStack[m_iIfStackDepth] & 2) &&
                    condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize,
                                   skip))
                    m_aiIfStack[m_iIfStackDepth] |= 2;
                else
                    lineOffset += skipCount;
            }
            if (condition.ExpressionError())
            {
                SetError(script, SCRIPT_ERROR_ERROR_SCRIPT_EXPRESSION);
                FUN_00887da0("SCRIPTS: Script '%s', line %d: failed to evaluate expression.", script->GetName(),
                             lineNumber);
                script->dataSize = 0;
                m_eExpressionError = condition.ExpressionError();
                return false;
            }
            offset += conditionSize;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ELSE: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            if (!(m_aiIfStack[m_iIfStackDepth] & 2))
                m_aiIfStack[m_iIfStackDepth] |= 2;
            else if (!skip)
                lineOffset += skipCount;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ENDIF:
            m_aiIfStack[m_iIfStackDepth] = 0;
            if (m_iIfStackDepth)
                m_iIfStackDepth--;
            break;
        case SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION:
            break;
        case SCRIPT_OUTPUT_FLOW_RETURN:
            if (skip)
                break;
        default: {
            function = ScriptCompiler_GetFunctionDef(output);
            if (!function)
            {
                N540270::BSString message;
                message.PrintfString("SCRIPTS: Unable to find function definition for command %d in script '%s'.",
                                     output, script->GetName());
                if (N540270::IsScriptDebuggingEnabled())
                    FUN_006195d0(message.String());
                else
                    FUN_00887da0(message.String());
                return false;
            }
            else
            {
                const ScriptParameter* blockParams = function->pParameters;
                if (function->m_bRequiresReference && !reference && !skip)
                {
                    N540270::BSString message;
                    message.PrintfString("SCRIPTS: Script '%s', line %d: Function '%s' requires a reference.",
                                         script->GetName(), lineNumber, function->pFunctionName);
                    if (N540270::IsScriptDebuggingEnabled())
                        FUN_006195d0(message.String());
                    else
                        FUN_00887da0(message.String());
                    return false;
                }
                if (skip)
                {
                    if (blockParams && blockSize)
                    {
                        FUN_00517950(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
                        switch (output)
                        {
                        case SCRIPT_OUTPUT_FUNCTION_MESSAGE: {
                            short valueCount = *reinterpret_cast<const short*>(data + offset);
                            offset += 2;
                            for (short valueIndex = 0; valueIndex < valueCount; valueIndex++)
                            {
                                double expressionValue;
                                Script::GetValue(expressionValue, data, offset, reference, m_pReference, script,
                                                 m_pScriptLocals, true);
                            }
                            offset += 4;
                            break;
                        }
                        }
                    }
                }
                else
                {
                    FNVScriptExecuteFunction blockExecute = function->m_pfnExecute;
                    if (function->m_bSetsExecutionFlag)
                        m_bExecutionFlagSet = true;
                    double result;
                    if (!blockExecute || !blockExecute(blockParams, data, reference, m_pReference, script,
                                                       m_pScriptLocals, result, offset))
                    {
                        FUN_00887da0("Failed to execute function '%s' on line %i of script '%s' (%08X).",
                                     function->pFunctionName, lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
        }
        }
    }
    return true;
}
