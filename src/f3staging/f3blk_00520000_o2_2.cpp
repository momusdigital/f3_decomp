#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00520000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0052b2e0 (community match, verified in this file)
namespace f3m_0052b2e0 {
struct ParamInfo;class ScriptEventList;
bool __cdecl FUN_00517950(ParamInfo*,void*,unsigned int*,TESObjectREFR*,TESObjectREFR*,Script*,ScriptEventList*,...);
struct Form52b2e0 {};
struct Obj52b2e0 {void FUN_004d35a0(Form52b2e0*);};
namespace player52b2e0 {struct Player {int unk00;int unk04;int unk08;int unk0C;int unk10;int unk14;int unk18;Form52b2e0* base;};extern Player* DAT_0107a104;}
// pdb: Script::SetCellOwnershipFunction | TESScriptFunctions.obj | fnv360_0822_retail, caller_sim, low, conflict (skyrim: Script::SetCanPCFastTravelFunction)
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
bool __cdecl FUN_0052b2e0(ParamInfo* a1,void* a2,TESObjectREFR* a3,TESObjectREFR* a4,Script* a5,ScriptEventList* a6,double*,unsigned int* a8) {
 Obj52b2e0* first;Form52b2e0* second;second=0;first=0;
 if(!FUN_00517950(a1,a2,a8,a3,a4,a5,a6,&first,&second)) return false;
 if(!second) second=player52b2e0::DAT_0107a104->base;
 if(first) first->FUN_004d35a0(second);
 return true;
}

}   // namespace f3m_0052b2e0

// @f3 0x00525d00 (community match, verified in this file)
namespace f3m_00525d00 {
struct ParamInfo;class ScriptEventList;
bool __cdecl FUN_00517950(ParamInfo*,void*,unsigned int*,TESObjectREFR*,TESObjectREFR*,Script*,ScriptEventList*,...);
struct Obj525d00 {void FUN_00551360(void*,unsigned int);};
// pdb: Script::SetFactionReaction | TESScriptFunctions.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(objrun_open), high
bool __cdecl Script_SetFactionReaction(ParamInfo* a1,void* a2,TESObjectREFR* a3,TESObjectREFR* a4,Script* a5,ScriptEventList* a6,double* out,unsigned int* a8) {
 unsigned int option;Obj525d00* receiver;void* target;
 receiver=0;target=0;option=0;
 if(!FUN_00517950(a1,a2,a8,a3,a4,a5,a6,&receiver,&target,&option)) return false;
 *out=0.0;
 if(target && receiver) receiver->FUN_00551360(target,option);
 return true;
}
}   // namespace f3m_00525d00

// @f3 0x0052b3a0 (community match, verified in this file)
namespace f3m_0052b3a0 {

class ParamInfo;
class ScriptEventList;

bool __cdecl Script_IsRunningConditionFunction(TESObjectREFR* thisObj, unsigned int unusedA,
    unsigned int unusedB, double* result);

// pdb: Script::IsRunningFunction | TESScriptFunctions.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
bool __cdecl Script_IsRunningFunction(ParamInfo* paramInfo, void* scriptData, TESObjectREFR* thisObj,
    TESObjectREFR* containingObj, Script* scriptObj, ScriptEventList* eventList, double* result,
    unsigned int* opcodeOffsetPtr)
{
    Script_IsRunningConditionFunction(thisObj, 0, 0, result);
    return true;
}
}   // namespace f3m_0052b3a0

// @f3 0x00525d90 (community match, verified in this file)
namespace f3m_00525d90 {
namespace f3_0291 {
struct TESFaction { void FUN_005513c0(TESFaction*, int); };
bool __cdecl FUN_00517950(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, ...);
// @fnv 0x005c8120
// pdb: Script::SetAllyFunction | TESScriptFunctions.obj | fnv360_0822_retail, objrun + skyrim(objrun_open), high
bool __cdecl Script_SetAllyFunction(const ScriptParameter* parameters, const char* scriptData,
    TESObjectREFR* thisObject, TESObjectREFR* container, Script* script,
    ScriptLocals* locals, double& result, unsigned int& opcodeOffset)
{
    struct {
        TESFaction* firstFaction;
        TESFaction* secondFaction;
        int firstIsFriend;
        int secondIsFriend;
    } relationship;
    relationship.firstFaction = 0;
    relationship.secondFaction = 0;
    relationship.firstIsFriend = 0;
    relationship.secondIsFriend = 0;
    if (!FUN_00517950(parameters, scriptData, &opcodeOffset, thisObject, container,
                     script, locals, &relationship.firstFaction, &relationship.secondFaction,
                     &relationship.firstIsFriend, &relationship.secondIsFriend))
        return false;
    result = 0.0;
    if (relationship.secondFaction && relationship.firstFaction) {
        if (!relationship.firstIsFriend)
            relationship.firstFaction->FUN_005513c0(relationship.secondFaction, 2);
        else
            relationship.firstFaction->FUN_005513c0(relationship.secondFaction, 3);
        if (!relationship.secondIsFriend)
            relationship.secondFaction->FUN_005513c0(relationship.firstFaction, 2);
        else
            relationship.secondFaction->FUN_005513c0(relationship.firstFaction, 3);
    }
    return true;
}

}
}   // namespace f3m_00525d90

// @f3 0x005306c0 (community match, verified in this file)
namespace f3m_005306c0 {
namespace f3_0310 {
struct ScriptAddedFormHelper { void FUN_0050ab40(TESForm*); };
bool __cdecl FUN_00517950(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, ...);
// @fnv 0x005de600
// pdb: Script::AddFormToFormListFunction | TESScriptFunctions.obj | fnv360_0822_retail, objrun, medium
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
bool FUN_005306c0(const ScriptParameter* parameters, const char* scriptData, TESObjectREFR* thisObject,
                  TESObjectREFR* container, Script* script, ScriptLocals* locals, double& result,
                  unsigned int& opcodeOffset)
{
    TESForm* formB = 0;
    TESForm* formA = 0;
    result = 0.0;
    if (!FUN_00517950(parameters, scriptData, &opcodeOffset, thisObject, container, script,
                     locals, &formB, &formA))
        return false;
    if (formA && formB)
        ((ScriptAddedFormHelper*)formB)->FUN_0050ab40(formA);
    return true;
}

}
}   // namespace f3m_005306c0

// @f3 0x0052fb80 (community match, verified in this file)
namespace f3m_0052fb80 {
namespace f3_0328 {
bool __cdecl FUN_00517950(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, ...);
bool __cdecl Script_GetVATSRightAreaFreeConditionFunction(TESObjectREFR*, void*, void*, double&);
// @fnv 0x005c7010
// pdb: Script::GetVATSRightAreaFreeFunction | TESScriptFunctions.obj | fnv360_0822_retail, caller_sim + bridge(caller_sim|caller_sim) + skyrim(caller_sim), high
bool __cdecl Script_GetVATSRightAreaFreeFunction(const ScriptParameter* parameters, const char* scriptData,
                               TESObjectREFR* thisObject, TESObjectREFR* container,
                               Script* script, ScriptLocals* locals, double& result,
                               unsigned int& opcodeOffset)
{
    unsigned int formID = 0;
    if (!FUN_00517950(parameters, scriptData, &opcodeOffset, thisObject, container,
                     script, locals, &formID))
        return false;
    return Script_GetVATSRightAreaFreeConditionFunction(thisObject,
                                              reinterpret_cast<void*>(formID), 0, result);
}

}
}   // namespace f3m_0052fb80

// @f3 0x00524370 (community match, verified in this file)
namespace f3m_00524370 {
namespace f3m_00524370 {
struct Node64 { void FUN_00493f80(bool on, int a, int b); };
struct Mgr {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    Node64* unk64;
    void FUN_00435550(int index, bool on, int c);

};
extern Mgr* DAT_0107a0d8;
extern unsigned int DAT_0107152c;
void __cdecl FUN_006195d0(const char* fmt, ...);
bool __cdecl FUN_00517950(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, int*);
// pdb: Script::ToggleCellNode | TESScriptFunctions.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool __cdecl Script_ToggleCellNode(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h) {
    int value = -1;
    if (!FUN_00517950(a, b, h, c, d, e, f, &value)) return false;
    if (value == -1) return true;
    {
        const char* name;
        switch (value) {
        case 0: name = "Actor"; break;
        case 1: name = "Marker"; break;
        case 2: name = "Land"; break;
        case 3: name = "Static"; break;
        case 4: name = "Dynamic"; break;
        case 5: name = "MultiBound"; break;
        case 6: name = "Water"; break;
        default:
            FUN_006195d0("Invalid node index. (0-6).");
            return true;
        }
        bool on = (DAT_0107152c & (1 << value)) != 0;
        DAT_0107a0d8->FUN_00435550(value, on, 0);
        if (value == 6) {
            Node64* node = DAT_0107a0d8->unk64;
            if (node) node->FUN_00493f80(on, 0, 0);
        }
        FUN_006195d0("Cell %s nodes now %s.", name, on ? "DISPLAYED" : "CULLED");
    }
    return true;
}
}
}   // namespace f3m_00524370

// @f3 0x005357e0 (community match, verified in this file)
namespace f3m_005357e0 {


namespace f3m_005357e0 {

struct WaterNode {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    unsigned char unk060;
    unsigned char unk061;
    unsigned char unk062;
    unsigned char bDepth;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    unsigned char unk07C;
    unsigned char unk07D;
    unsigned char unk07E;
    unsigned char bDisabled;
    unsigned char bReflect;
    unsigned char bRefract;
    unsigned char unk082;
    unsigned char unk083;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    float fReflectAmt;
    float fOpacity;
    float fDistort;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    float fFresnel;
    float fNoise;
    float fFog;
};

struct WaterGeom {
    WaterNode* FUN_00826590(int type);
};

struct WaterManager {
    WaterGeom* FUN_004941a0(TESObjectREFR* ref);
    void FUN_00493f80(int a, int b, int c);
    void TESWaterSystem_EnableWaterSystem();
};

struct Cell {
    const char* GetName() { return ""; }
};

struct TES {
    int unk00;
    int unk04;
    int unk08;
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
    WaterManager* waterManager064;
    WaterManager* GetWaterManager() { return waterManager064; }
    Cell* FUN_00435750();
};

struct Setting {
    void* vtbl;
    unsigned char value;
    unsigned char* FUN_00405070();
    void Set(bool b) { value = b; }
};

extern TES* DAT_0107a0d8;
extern Setting DAT_0106fe54;
extern Setting DAT_0106ff40;
extern Setting DAT_0106fea0;
extern float DAT_0117516c;
extern float DAT_01175174;
extern float DAT_01174e8c;
extern float DAT_01175170;
extern float DAT_011756b4;
extern float DAT_01175654;
extern float DAT_01175658;
extern float DAT_0117565c;
extern float DAT_01175630;
extern float DAT_01175644;
extern float DAT_01175648;
extern float DAT_0117564c;
extern float DAT_01175650;
extern float DAT_01175194;
extern unsigned char DAT_0106fd55;
extern unsigned char DAT_00f4cf80;

inline bool IsWaterLocked() { return DAT_00f4cf80 != 0; }

bool __cdecl FUN_00517950(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, char*, float*);
void __cdecl FUN_006195d0(const char*, ...);
void __cdecl FUN_00468bd0(Cell*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
}

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(long long*);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(long long*);

using namespace f3m_005357e0;

// pdb: Script::ModifyWaterShader | TESScriptFunctions.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
bool __cdecl Script_ModifyWaterShader(const ScriptParameter* parameters, const char* scriptData, TESObjectREFR* thisObject, TESObjectREFR* container, Script* script, ScriptLocals* locals, double& result, unsigned int& opcodeOffset)
{
    WaterNode* p;
    float value = 0.0f;
    char buf[512];
    if (!FUN_00517950(parameters, scriptData, &opcodeOffset, thisObject, container, script, locals, buf, &value)) {
        FUN_006195d0("reflectamt, fresnel, opacity, speed, noise, reflect, refract, lod");
        return false;
    }
    p = 0;
    if (thisObject) {
        WaterGeom* water = DAT_0107a0d8->GetWaterManager()->FUN_004941a0(thisObject);
        WaterNode* waterNode = water->FUN_00826590(3);
        p = waterNode;
    }
    if (!_stricmp(buf, "velocity")) {
    } else if (!_stricmp(buf, "direction")) {
    } else if (!_stricmp(buf, "amplitude")) {
    } else if (!_stricmp(buf, "frequency")) {
    } else if (!_stricmp(buf, "reflectamt")) {
        if (value >= 0.0f && value <= 1.0f) {
            if (p) {
                p->fReflectAmt = value;
                FUN_006195d0("set water reflectivity amount to %f", (double)value);
                p->bDisabled = 0;
            } else {
                DAT_0117516c = value;
                FUN_006195d0("set water reflectivity amount to %f", (double)value);
                DAT_0106fd55 = 1;
            }
        } else {
            FUN_006195d0("usage : mws reflectamt (0.0 - 1.0)", (double)value);
        }
    } else if (!_stricmp(buf, "distort")) {
        if (p) {
            p->fDistort = value;
            FUN_006195d0("set water distortion amount to %f", (double)value);
            p->bDisabled = 0;
        } else {
            DAT_01175174 = value;
            FUN_006195d0("set water distortion amount to %f", (double)value);
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "fresnel")) {
        if (value >= 0.0f && value <= 1.0f) {
            if (p) {
                p->fFresnel = value;
                FUN_006195d0("set fresnel term to %f", (double)value);
                p->bDisabled = 0;
            } else {
                DAT_01174e8c = value;
                FUN_006195d0("set fresnel term to %f", (double)value);
                DAT_0106fd55 = 1;
            }
        } else {
            FUN_006195d0("usage : mws fresnel (0.0 - 1.0)", (double)value);
        }
    } else if (!_stricmp(buf, "opacity")) {
        if (value >= 0.0f && value <= 100.0) {
            if (p) {
                p->fOpacity = value / 100.0;
                FUN_006195d0("set water opacity to %d", (int)value);
                p->bDisabled = 0;
            } else {
                DAT_01175170 = value / 100.0;
                FUN_006195d0("set water opacity to %d", (int)value);
                DAT_0106fd55 = 1;
            }
        } else {
            FUN_006195d0("usage : mws opacity (0.0 - 100.0)", (double)value);
        }
    } else if (!_stricmp(buf, "blend")) {
    } else if (!_stricmp(buf, "noise")) {
        if (value >= 0.0f && value <= 100.0) {
            if (p) {
                p->fNoise = value;
                FUN_006195d0("set noise scale to %f", (double)value);
                p->bDisabled = 0;
            } else {
                DAT_011756b4 = value;
                FUN_006195d0("set noise to %f", (double)value);
                DAT_0106fd55 = 1;
            }
        } else {
            FUN_006195d0("usage : mws noise (0.0 - 100.0)", (double)value);
        }
    } else if (!_stricmp(buf, "off")) {
        if (p) {
            p->bDisabled = 1;
        } else {
            DAT_0106fd55 = 0;
        }
    } else if (!_stricmp(buf, "displaceforce")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_01175654 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "displacevelocity")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_01175658 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "displacefalloff")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_0117565c = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "displacedampener")) {
        if (value >= 0.0f && value <= 20.0f) {
            DAT_01175630 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "rainforce")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_01175644 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "rainvelocity")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_01175648 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "rainfalloff")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_0117564c = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "rainsize")) {
        if (value >= 0.0f && value <= 1.0f) {
            DAT_01175650 = value;
            DAT_0106fd55 = 1;
        }
    } else if (!_stricmp(buf, "reflect")) {
        if (p) {
            if (p->bReflect) {
                p->bReflect = 0;
                FUN_006195d0("Toggle Reflections : OFF");
            } else {
                p->bReflect = 1;
                FUN_006195d0("Toggle Reflections : ON");
            }
        } else {
            if (*DAT_0106fe54.FUN_00405070()) {
                DAT_0106fe54.Set(0);
                FUN_006195d0("Toggle Global Water Reflections : OFF");
            } else {
                DAT_0106fe54.Set(1);
                FUN_006195d0("Toggle Global Water Reflections : ON");
            }
        }
    } else if (!_stricmp(buf, "refract")) {
        if (p) {
            if (p->bRefract) {
                p->bRefract = 0;
                FUN_006195d0("Toggle Refractions : OFF");
            } else {
                p->bReflect = 1;
                FUN_006195d0("Toggle Refractions : ON");
            }
        } else {
            if (*DAT_0106ff40.FUN_00405070()) {
                DAT_0106ff40.Set(0);
                FUN_006195d0("Toggle Global Water Refractions : OFF");
            } else {
                DAT_0106ff40.Set(1);
                FUN_006195d0("Toggle Global Water Refractions : ON");
            }
        }
    } else if (!_stricmp(buf, "depth")) {
        if (p) {
            if (p->bDepth) {
                p->bDepth = 0;
                FUN_006195d0("Toggle Depth : OFF");
            } else {
                p->bDepth = 1;
                FUN_006195d0("Toggle Depth : ON");
            }
        } else {
            if (*DAT_0106fea0.FUN_00405070()) {
                DAT_0106fea0.Set(0);
                FUN_006195d0("Toggle Global Water Depth : OFF");
            } else {
                DAT_0106fea0.Set(1);
                FUN_006195d0("Toggle Global Water Depth : ON");
            }
        }
    } else if (!_stricmp(buf, "fog")) {
        if (value >= 0.0f && value <= 100.0) {
            if (p) {
                p->fFog = value / 100.0;
                FUN_006195d0("set fog amount to %d", (int)value);
                p->bDisabled = 0;
            } else {
                DAT_01175194 = value / 100.0;
                FUN_006195d0("set fog amount to %d", (int)value);
                DAT_0106fd55 = 1;
            }
        }
    } else if (!_stricmp(buf, "lod")) {
        if (DAT_0107a0d8->GetWaterManager()) {
            DAT_0107a0d8->GetWaterManager()->FUN_00493f80(1, 1, 1);
        }
        FUN_006195d0("Toggle LOD Water");
    } else if (!_stricmp(buf, "autowater")) {
        double secondsPerTick = 1000.0;
        long long freq;
        reinterpret_cast<unsigned int&>(freq) = 0;
        char msg[256];
        long long end;
        long long start;
        long long dt;
        QueryPerformanceFrequency(&start);
        secondsPerTick = (double)start * 0.000001;
        QueryPerformanceCounter(&freq);
        FUN_00468bd0(DAT_0107a0d8->FUN_00435750());
        QueryPerformanceCounter(&end);
        dt = end - freq;
        FUN_00403230(msg, 0xff, "GeneratePlaceableWaterForCell() for cell %s: Ticks: %I64d, Microseconds: %f",
                     DAT_0107a0d8->FUN_00435750()->GetName(), dt, (double)dt / secondsPerTick);
        if (!IsWaterLocked()) {
            DAT_0107a0d8->GetWaterManager()->TESWaterSystem_EnableWaterSystem();
        }
    }
    return true;
}
}   // namespace f3m_005357e0

// @f3 0x0053d570 (community match, verified in this file)
namespace f3m_0053d570 {

// 0x0053d570: script command; places one of two marker forms at the calling reference, turned to the ground
// normal found by a pick ray from 32 above to 256 below. Matches under /MT /O2 /GS /EHsc /Gy (the pack lists
// /Od; the code is optimised). Builds on the stored draft best2.cpp (another contributor); see note.txt.
namespace f3m_0053d570 {
struct NiPoint3 {
    float x, y, z;
    NiPoint3() {}
    NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};
struct NiMatrix3 {
    float m[3][3];
    NiMatrix3() {}
    NiMatrix3(const NiMatrix3& other);
    void FUN_00823590(float* x, float* y, float* z);
};
NiMatrix3 __cdecl FUN_00aab6b0(NiPoint3 normal);

struct CollisionObject {
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int flags;
    bool IsHavokFlag(unsigned int bit) { return ((flags >> bit) & 1) != 0; }
    bool FUN_008f76e0(int key, unsigned int flag);
};
struct ShapeContainer;
struct Shape {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual ShapeContainer* GetContainer();
    unsigned int unk04;
    CollisionObject* userData;
    int type;
};
struct ShapeContainer {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual Shape* GetChildShape(int key, char* buffer);
};
struct Collidable { Shape* shape; };
inline CollisionObject* GetCollisionObject(Shape* shape) { return shape ? shape->userData : 0; }

struct __declspec(align(16)) RayQuery {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int filter;
    unsigned int unk28, unk2C;
    NiPoint3 hitNormal;
    unsigned int unk3C, unk40, unk44, unk48, unk4C;
    int keys[8];
    unsigned int unk70, unk74, unk78, unk7C;
    Collidable* collidable;
    unsigned int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    RayQuery();
    void FUN_00469050(NiPoint3* from);
    void FUN_00469bd0(NiPoint3* to);
    void FUN_00530b30(NiPoint3* point);
    struct HitFlag { bool hit; bool IsHit() const { return hit; } };
    HitFlag GetFlag() const { HitFlag flag; flag.hit = collidable != 0; return flag; }
};

struct ScrapHeap {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual char* Allocate(unsigned int size);
    virtual void Free(char* memory);
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    char* current;
    unsigned int unk24;
    char* last;
    char* end;
    char* Alloc(unsigned int size)
    {
        char* memory;
        char* old = current;
        char* next = old + size;
        if (next <= end) {
            current = next;
            memory = old;
        } else
            memory = Allocate(size);
        return memory;
    }
};
extern DWORD DAT_010f3170;
// Stack buffer taken from the thread's scrap heap. The object is 8 bytes: in the target its home is the dead
// ray start's slot (esp+0x54), and a 4-byte object is never packed into a 12-byte one (measured).
// Only the pointer is written.
struct KeyBuffer {
    char* data;
    unsigned int unk04;
    __forceinline KeyBuffer(unsigned int size) { data = ((ScrapHeap*)TlsGetValue(DAT_010f3170))->Alloc(size); }
    ~KeyBuffer()
    {
        ScrapHeap* heap = (ScrapHeap*)TlsGetValue(DAT_010f3170);
        heap->current = data;
        if (data == heap->last)
            heap->Free(data);
    }
    char* GetAt(int index) { return data + index * 0x200; }
};

struct Ref;
// 0x28 bytes (esp+0x6c up to the query at esp+0x94). An ordinary virtual destructor: the compiler
// writes the vtable store itself (the original's vtable is 0x00dc4dc0, RTTI .?AVPathingLocation@@).
struct PathingLocation {
    PathingLocation(Ref* ref);
    virtual ~PathingLocation() {}
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};
void __cdecl FUN_005f2190(PathingLocation* location, NiPoint3* normal);

struct LinkList { void FUN_00411bd0(Ref* ref); };
struct Ref {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f(); virtual void v10(); virtual void v11();
    virtual void MarkAsModified(unsigned int flags);
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d();
    virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2a(); virtual void v2b(); virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3a(); virtual void v3b();
    virtual void v3c(); virtual void v3d(); virtual void v3e(); virtual void v3f();
    virtual bool Is3DLoaded();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v4a(); virtual void v4b(); virtual void v4c();
    virtual void v4d(); virtual void v4e(); virtual void v4f(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v5a(); virtual void v5b(); virtual void v5c(); virtual void v5d(); virtual void v5e();
    virtual void v5f(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6a();
    virtual void v6b(); virtual void v6c(); virtual void v6d(); virtual void v6e(); virtual void v6f(); virtual void v70();
    virtual void v71(); virtual void v72(); virtual void v73();
    virtual void* Get3D();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v7a();
    virtual void v7b(); virtual void v7c();
    virtual NiPoint3* GetPos();
    unsigned int unk04;
    unsigned int flags;
    unsigned int unk0C, unk10, unk14, unk18, unk1C;
    NiPoint3 angle;
    unsigned int unk2C, unk30, unk34, unk38;
    void* parentCell;
    LinkList linked;
    void* FUN_004e8880();
    void FUN_004e69f0(bool disabled);
    void TESObjectREFR_SetRefPersists(bool value);
    void* GetParentCell() { return parentCell; }
    LinkList* GetLinkNode() { return &linked; }
};

struct DataHandler {
    Ref* FUN_0043def0(void* form, NiPoint3* pos, NiPoint3* angle, void* cell, void* world, int a6, int a7, int a8);
};
extern DataHandler* DAT_0106cdcc;
struct PickWorld { void FUN_0043b770(RayQuery* query); };
extern PickWorld* DAT_0107a0d8;
extern void* DAT_01071698;
extern void* DAT_0107169c;
extern unsigned int DAT_00f79e58;

bool __cdecl FUN_00517950(void* paramInfo, void* scriptData, unsigned int* opcodeOffsetPtr, Ref* thisObj,
                          Ref* containingObj, void* scriptObj, void* eventList, ...);
void __cdecl FUN_008f4480(unsigned int layer, unsigned __int64 mask);

inline unsigned int NextPickId()
{
    DAT_00f79e58 = (DAT_00f79e58 + 1) & 0xffff;
    if (!DAT_00f79e58)
        DAT_00f79e58 = 10;
    return DAT_00f79e58;
}

// pdb: Script::AttachAshPileFunction | TESScriptFunctions.obj | fnv360_0822_retail, uconst, low
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
bool __cdecl FUN_0053d570(void* paramInfo, void* scriptData, Ref* thisObj, Ref* containingObj, void* scriptObj,
                          void* eventList, double* result, unsigned int* opcodeOffsetPtr)
{
    int iType = 0;
    if (!FUN_00517950(paramInfo, scriptData, opcodeOffsetPtr, thisObj, containingObj, scriptObj, eventList, &iType))
        return false;
    if (thisObj && thisObj->Is3DLoaded()) {
        thisObj->Get3D();
        NiPoint3 kPos = *thisObj->GetPos();
        NiPoint3 kAngle(0.0f, 0.0f, thisObj->angle.z);
        bool bAligned = false;
        FUN_008f4480(0x27, 0x8022802);
        RayQuery kQuery;
        kQuery.filter = 0x27 | (NextPickId() << 16);
        {   // the two ray points end here: the key buffer below takes the start point's slot
            NiPoint3 kStart = kPos;
            kStart.z += 32.0;
            NiPoint3 kEnd = kPos;
            kEnd.z -= 256.0;
            kQuery.FUN_00469050(&kStart);
            kQuery.FUN_00469bd0(&kEnd);
        }
        DAT_0107a0d8->FUN_0043b770(&kQuery);
        if (kQuery.GetFlag().IsHit()) {
            Shape* pkShape = kQuery.collidable->shape;
            CollisionObject* pkObj = GetCollisionObject(pkShape);
            bool bSurface = pkObj->IsHavokFlag(6);
            if (!bSurface) {
                Shape* pkCur = pkShape;
                Shape* pkLast = 0;
                int iKey = -1;
                KeyBuffer kBuffer(0x1010);
                for (int i = 0; i < 8 && kQuery.keys[i] != -1; i++) {
                    if (pkCur->type == 11) {
                        i++;
                        if (i >= 8 || kQuery.keys[i] == -1)
                            break;
                    }
                    iKey = kQuery.keys[i];
                    pkLast = pkCur;
                    pkCur = pkCur->GetContainer()->GetChildShape(kQuery.keys[i], kBuffer.GetAt(i));
                }
                CollisionObject* pkLastObj = GetCollisionObject(pkLast);
                if (pkLastObj)
                    bSurface = pkLastObj->FUN_008f76e0(iKey, 0x40);
            }
            NiPoint3 kNormal;
            if (bSurface) {
                PathingLocation kSurface(thisObj);
                FUN_005f2190(&kSurface, &kNormal);
            } else {
                kNormal.x = (float)(kQuery.hitNormal.x * 6.999040126800537);
                kNormal.y = (float)(kQuery.hitNormal.y * 6.999040126800537);
                kNormal.z = (float)(kQuery.hitNormal.z * 6.999040126800537);
            }
            NiMatrix3 kRotate = FUN_00aab6b0(kNormal);
            kRotate.FUN_00823590(&kAngle.x, &kAngle.y, &kAngle.z);
            bAligned = true;
            kQuery.FUN_00530b30(&kPos);
        }
        void* pvForm = iType == 2 ? DAT_0107169c : DAT_01071698;
        Ref* pkNew = DAT_0106cdcc->FUN_0043def0(pvForm, &kPos, &kAngle, thisObj->GetParentCell(), thisObj->FUN_004e8880(), 0, 0, 0);
        pkNew->FUN_004e69f0(!bAligned);
        pkNew->flags |= 0x8000000;
        pkNew->TESObjectREFR_SetRefPersists(true);
        pkNew->GetLinkNode()->FUN_00411bd0(thisObj);
        thisObj->GetLinkNode()->FUN_00411bd0(pkNew);
        pkNew->MarkAsModified(0x80000000);
        thisObj->MarkAsModified(0x80000000);
    }
    return true;
}
}

}   // namespace f3m_0053d570
