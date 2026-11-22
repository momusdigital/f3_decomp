// src/f3staging/f3blk_00c80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00c99510 (community match, verified in this file)
struct ParameterList57 { int count; const char* const* names; };
struct ActionDescriptor57 { const char* name; ParameterList57 parameters; int unk0c; };
extern ActionDescriptor57 DAT_00f5a5d0[37];
extern ParameterList57 DAT_00f5a57c;
extern ParameterList57 DAT_00f5a584;
extern ParameterList57 DAT_00f5a58c;
extern ParameterList57 DAT_00f5a594;
extern ParameterList57 DAT_00f5a59c;
extern ParameterList57 DAT_00f5a5a4;
extern ParameterList57 DAT_00f5a5ac;
extern ParameterList57 DAT_00f5a5b4;
extern ParameterList57 DAT_00f5a5bc;
// pdb: `dynamic initializer for 'BGSEntryPoint::EntryPoints'' | BGSEntryPoint.obj | fnv360_0721_beta, udata, high
void __cdecl FUN_00c99510() {
    DAT_00f5a5d0[0].parameters=DAT_00f5a58c;
    DAT_00f5a5d0[1].parameters=DAT_00f5a58c;
    DAT_00f5a5d0[2].parameters=DAT_00f5a58c;
    DAT_00f5a5d0[3].parameters=DAT_00f5a584;
    DAT_00f5a5d0[4].parameters=DAT_00f5a5bc;
    DAT_00f5a5d0[5].parameters=DAT_00f5a584;
    DAT_00f5a5d0[6].parameters=DAT_00f5a5a4;
    DAT_00f5a5d0[7].parameters=DAT_00f5a584;
    DAT_00f5a5d0[8].parameters=DAT_00f5a58c;
    DAT_00f5a5d0[9].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[10].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[11].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[12].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[13].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[14].parameters=DAT_00f5a594;
    DAT_00f5a5d0[15].parameters=DAT_00f5a59c;
    DAT_00f5a5d0[16].parameters=DAT_00f5a5ac;
    DAT_00f5a5d0[17].parameters=DAT_00f5a5b4;
    DAT_00f5a5d0[18].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[19].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[20].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[21].parameters=DAT_00f5a594;
    DAT_00f5a5d0[22].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[23].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[24].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[25].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[26].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[27].parameters=DAT_00f5a594;
    DAT_00f5a5d0[28].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[29].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[30].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[31].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[32].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[33].parameters=DAT_00f5a57c;
    DAT_00f5a5d0[34].parameters=DAT_00f5a584;
    DAT_00f5a5d0[35].parameters=DAT_00f5a58c;
    DAT_00f5a5d0[36].parameters=DAT_00f5a58c;
}

// @f3 0x00c8afc0 (community match, verified in this file)
struct FUN_0043b7f0_Obj {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};

extern FUN_0043b7f0_Obj DAT_0106e120;
extern const char DAT_00dbf4e4[];

extern void __cdecl FUN_00d879d0();
extern void __cdecl FUN_00c00d1f(void (*callback)());

// pdb: `dynamic initializer for 'uGeometryCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8afc0() {
    DAT_0106e120.FUN_0043b7f0(DAT_00dbf4e4, 1000);
    FUN_00c00d1f(FUN_00d879d0);
}

// @f3 0x00c8a990 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106dfc0;
extern int DAT_00d87810;
namespace f3m_00c8a990 {
struct FUN_0043b7f0_Obj
{
    void FUN_0043b7f0(const char* name, unsigned int size);
};

void __cdecl FUN_00c00d1f(void* handler);

// pdb: `dynamic initializer for 'BGSDecalManager::iMaxSkinDecals'' | BGSDecalManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8a990()
{
    DAT_0106dfc0.FUN_0043b7f0("uMaxSkinDecals:Decals", 0x18);
    FUN_00c00d1f(&DAT_00d87810);
}
}   // namespace f3m_00c8a990

// @f3 0x00c8afa0 (community match, verified in this file)
struct FNVEmitterBudgetCaps {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};

extern FNVEmitterBudgetCaps DAT_0106e12c;
extern const char DAT_00dbf4c8[];

void __cdecl FUN_00d879c0();
void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'uEmittersCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8afa0() {
    DAT_0106e12c.FUN_0043b7f0(DAT_00dbf4c8, 0x32);
    FUN_00c00d1f(FUN_00d879c0);
}

// @f3 0x00c8b2c0 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e084;
namespace f3m_00c8b2c0 {

struct FUN_0043b7f0_Obj {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};


typedef void (__cdecl *FUN_00c00d1f_Callback)();
void __cdecl FUN_00c00d1f(FUN_00c00d1f_Callback callback);
void __cdecl FUN_00d87b50();

// pdb: `dynamic initializer for 'uDecalCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b2c0() {
    DAT_0106e084.FUN_0043b7f0("uDecalCountInterior:BudgetCaps", 500);
    FUN_00c00d1f(FUN_00d87b50);
}
}   // namespace f3m_00c8b2c0

// @f3 0x00c8b080 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e210;
extern const char DAT_00dbf584[];
namespace f3m_00c8b080 {
void __cdecl FUN_00d87a30();

// pdb: `dynamic initializer for 'uLightCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b080() {
    DAT_0106e210.FUN_0043b7f0(DAT_00dbf584, 10);
    FUN_00c00d1f(FUN_00d87a30);
}
}   // namespace f3m_00c8b080

// @f3 0x00c9d7f0 (community match, verified in this file)
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());

extern void __cdecl FUN_00d8a650();

struct FUN_005752c0_Obj {
    void __thiscall FUN_005752c0(const char* name, const char* value);
};

extern FUN_005752c0_Obj DAT_01072c74;

// pdb: `dynamic initializer for 'BlendDefault::LUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d7f0() {
    DAT_01072c74.FUN_005752c0("sLUpperArm:DEFAULT", "1.0, 1.0");
    FUN_00c00d1f(FUN_00d8a650);
}

// @f3 0x00c8af20 (community match, verified in this file)
struct F3ActorRefCountCaps {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};

extern F3ActorRefCountCaps DAT_0106e108;
extern const char DAT_00dbf450[];

extern void __cdecl FUN_00d87980();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'uActorRefCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8af20() {
    DAT_0106e108.FUN_0043b7f0(DAT_00dbf450, 0x14);
    FUN_00c00d1f(FUN_00d87980);
}

// @f3 0x00c85c80 (community match, verified in this file)
struct F3mExteriorCellBufferObj {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};

extern F3mExteriorCellBufferObj DAT_0106cb6c;
extern int DAT_0106e9cc;
extern void __cdecl FUN_00d86c50();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'iExteriorBufferSize'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85c80() {
    int value = DAT_0106e9cc;
    int result = (value + 2) * value + 1;
    DAT_0106cb6c.FUN_0043b7f0("uExterior Cell Buffer:General", result);
    FUN_00c00d1f(FUN_00d86c50);
}

// @f3 0x00c862f0 (community match, verified in this file)
struct FUN_00c862f0_Obj
{
    void __thiscall FUN_0043b7f0(const char* name, const char* text);
};
extern FUN_00c862f0_Obj DAT_0106cc00;
extern const char DAT_00db9388[];
extern const char DAT_00db9494[];
extern void __cdecl FUN_00d86e60();
extern void __cdecl FUN_00c00d1f(void (*callback)());

// pdb: `dynamic initializer for 'sSysUtil_DiscEject'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c862f0()
{
    DAT_0106cc00.FUN_0043b7f0(DAT_00db9494, DAT_00db9388);
    FUN_00c00d1f(FUN_00d86e60);
}

// @f3 0x00c9d990 (community match, verified in this file)
struct FUN_00c9d990_Obj
{
    void __thiscall FUN_005752c0(const char* name, const char* text);
};
extern FUN_00c9d990_Obj DAT_01072b1c;
extern const char DAT_00de77d4[];
extern const char DAT_00de7abc[];
extern void __cdecl FUN_00d8a720();
extern void __cdecl FUN_00c00d1f(void (*callback)());

// pdb: `dynamic initializer for 'BlendDefault::Shield'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d990()
{
    DAT_01072b1c.FUN_005752c0(DAT_00de7abc, DAT_00de77d4);
    FUN_00c00d1f(FUN_00d8a720);
}

// @f3 0x00c85d10 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106cb3c;
extern int DAT_00d86c90;
namespace f3m_00c85d10 {
void __cdecl FUN_00c00d1f(void* handler);
// pdb: `dynamic initializer for 'sLerpCloseColor'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85d10() {
    DAT_0106cb3c.FUN_0043b7f0("sLerpCloseColor:Weather", (int)"255,255,255,255");
    FUN_00c00d1f(&DAT_00d86c90);
}
}   // namespace f3m_00c85d10

// @f3 0x00c8b160 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e050;
extern const char DAT_00dbf658[];
namespace f3m_00c8b160 {
struct FUN_0043b7f0_Obj {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};
extern void __cdecl FUN_00d87aa0();
void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'uAnimatedObjectsCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b160() {
    DAT_0106e050.FUN_0043b7f0(DAT_00dbf658, 0x32);
    FUN_00c00d1f(FUN_00d87aa0);
}
}   // namespace f3m_00c8b160

// @f3 0x00c8b020 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e24c;
extern int DAT_00d87a00;
namespace f3m_00c8b020 {
namespace f3m_00c8b020 {
struct FUN_0043b7f0_Obj
{
    void FUN_0043b7f0(const char* name, unsigned int size);
};

void __cdecl FUN_00c00d1f(void* handler);

// pdb: `dynamic initializer for 'uGeometryMemoryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b020()
{
    DAT_0106e24c.FUN_0043b7f0("uGeometryMemory:BudgetCaps", 0x500000);
    FUN_00c00d1f(&DAT_00d87a00);
}
}
}   // namespace f3m_00c8b020

// @f3 0x00c9d450 (community match, verified in this file)
extern FUN_005752c0_Obj DAT_01072cb0;
namespace f3m_00c9d450 {

struct FUN_005752c0_Obj {
    void __thiscall FUN_005752c0(const char* first, const char* second);
};
extern void __cdecl FUN_00d8a480();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());
// pdb: `dynamic initializer for 'BlendHit::sHitStart'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d450() {
    DAT_01072cb0.FUN_005752c0("sHitStart:HIT", "Bip01 Spine1");
    FUN_00c00d1f(FUN_00d8a480);
}
}   // namespace f3m_00c9d450

// @f3 0x00c8b9b0 (community match, verified in this file)
struct FUN_0106e594_Obj {
    void __thiscall FUN_00aa5c40(int value);
};

extern FUN_0106e594_Obj DAT_0106e594;

extern void __cdecl FUN_00c00d1f(void (__cdecl *callback)());
extern void __cdecl FUN_00d87d20();

// pdb: `dynamic initializer for 'messageHandler'' | Defines.obj | fnv360_0822_retail, udata, high
void __cdecl FUN_00c8b9b0() {
    DAT_0106e594.FUN_00aa5c40(1);
    FUN_00c00d1f(FUN_00d87d20);
}

// @f3 0x00c8b180 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e21c;
namespace f3m_00c8b180 {

extern void __cdecl FUN_00d87ab0();

// pdb: `dynamic initializer for 'uParticlesCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b180()
{
    DAT_0106e21c.FUN_0043b7f0("uParticlesCountInterior:BudgetCaps", 5000);
    FUN_00c00d1f(FUN_00d87ab0);
}
}   // namespace f3m_00c8b180

// @f3 0x00c9d5b0 (community match, verified in this file)
namespace f3m_00c9d5b0 {
struct Setting {
    void FUN_005752c0(const char* name, const char* value);
};
extern Setting DAT_01072dd0;
extern const char DAT_00de788c[], DAT_00dbfbdc[];
void FUN_00d8a530();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
// pdb: `dynamic initializer for 'BlendHitQuad::sHitSpot'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d5b0() {
    DAT_01072dd0.FUN_005752c0(DAT_00de788c, DAT_00dbfbdc);
    FUN_00c00d1f(FUN_00d8a530);
}
}

// @f3 0x00c8c850 (community match, verified in this file)
struct F3WaterReflectWidthObject {
    void __thiscall FUN_00491570(const char* text, int value);
};

extern F3WaterReflectWidthObject DAT_0106fc90;
extern const char DAT_00dc1a84[];

void __cdecl FUN_00d88570();

// pdb: `dynamic initializer for 'Renderer::iWaterReflectWidth'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::iWaterReflectWidth'')
void __cdecl FUN_00c8c850() {
    DAT_0106fc90.FUN_00491570(DAT_00dc1a84, 0x200);
    FUN_00c00d1f(FUN_00d88570);
}

// @f3 0x00c9d930 (community match, verified in this file)
namespace f3m_00c9d930 {

struct FNV_01072c80_Obj {
    void __thiscall FUN_005752c0(const char* name, const char* value);
};

extern FNV_01072c80_Obj DAT_01072c80;
extern const char DAT_00de77d4[];
extern const char DAT_00de7a8c[];

void __cdecl FUN_00d8a6f0();
void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'BlendDefault::RCalf'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d930() {
    DAT_01072c80.FUN_005752c0(DAT_00de77d4, DAT_00de7a8c);
    FUN_00c00d1f(FUN_00d8a6f0);
}
}   // namespace f3m_00c9d930

// @f3 0x00c86290 (community match, verified in this file)
namespace f3m_00c86290 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };
extern Setting DAT_0106cbb4;
extern const char DAT_00db9388[], DAT_00db9420[];
void FUN_00d86e30();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
// pdb: `dynamic initializer for 'sSysUtil_GameDataCorrupt'' | TES.obj | fnv360_0822_debug, ustr, high
void FUN_00c86290() {
    DAT_0106cbb4.FUN_0043b7f0(DAT_00db9420, DAT_00db9388);
    FUN_00c00d1f(FUN_00d86e30);
}
}

// @f3 0x00c8b260 (community match, verified in this file)
namespace f3m_00c8b260 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };
extern Setting DAT_0106e114;
extern const char DAT_00dbf77c[];
void FUN_00d87b20();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
// pdb: `dynamic initializer for 'uWaterMemoryBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void FUN_00c8b260() {
    DAT_0106e114.FUN_0043b7f0(DAT_00dbf77c, 0xa00000u);
    FUN_00c00d1f(FUN_00d87b20);
}
}

// @f3 0x00c86350 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c86350 {

struct Setting { void FUN_0043b7f0(const char* name, const char* value); };
extern Setting DAT_0106cc7c;
void __cdecl FUN_00d86e90();
extern const char DAT_00db94e4[];
extern const char DAT_00db9388[];

// pdb: `dynamic initializer for 'sDPad'' | TES.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'sSysUtil_AwardsInstalling'')
void __cdecl FUN_00c86350()
{
    DAT_0106cc7c.FUN_0043b7f0(DAT_00db94e4, DAT_00db9388);
    atexit(FUN_00d86e90);
}

}

// @f3 0x00c8d800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8d800 {

struct Setting { void FUN_0043b7f0(const char* name, int value); };
extern Setting DAT_0106fccc;
void __cdecl FUN_00d88440();
extern const char DAT_00dc25f4[];

// pdb: `dynamic initializer for 'BSRenderer::iLastHDRSetting'' | BSRenderer.obj | tesv_win, ustr, medium
void __cdecl FUN_00c8d800()
{
    DAT_0106fccc.FUN_0043b7f0(DAT_00dc25f4, -1);
    atexit(FUN_00d88440);
}

}

// @f3 0x00c902a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c902a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d924;
void __cdecl FUN_00d88e70();

void __cdecl FUN_00c902a0()
{
    DAT_00f4d924.Setting::Setting();
    atexit(FUN_00d88e70);
}
}

// @f3 0x00c94d70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94d70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e530;
void __cdecl FUN_00d89960();

void __cdecl FUN_00c94d70()
{
    DAT_00f4e530.Setting::Setting();
    atexit(FUN_00d89960);
}
}

// @f3 0x00c93040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93040 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e158;
void __cdecl FUN_00d894d0();

void __cdecl FUN_00c93040()
{
    DAT_00f4e158.Setting::Setting();
    atexit(FUN_00d894d0);
}
}

// @f3 0x00c83e40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c64;
void __cdecl FUN_00d868c0();

void __cdecl FUN_00c83e40()
{
    DAT_00f46c64.Setting::Setting();
    atexit(FUN_00d868c0);
}
}

// @f3 0x00c89530 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89530 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5f8;
void __cdecl FUN_00d87620();

void __cdecl FUN_00c89530()
{
    DAT_00f4a5f8.Setting::Setting();
    atexit(FUN_00d87620);
}
}

// @f3 0x00c82900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46520;
void __cdecl FUN_00d86650();

void __cdecl FUN_00c82900()
{
    DAT_00f46520.Setting::Setting();
    atexit(FUN_00d86650);
}
}

// @f3 0x00c828a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c828a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46514;
void __cdecl FUN_00d86640();

void __cdecl FUN_00c828a0()
{
    DAT_00f46514.Setting::Setting();
    atexit(FUN_00d86640);
}
}

// @f3 0x00c82960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4652c;
void __cdecl FUN_00d86660();

void __cdecl FUN_00c82960()
{
    DAT_00f4652c.Setting::Setting();
    atexit(FUN_00d86660);
}
}

// @f3 0x00c829c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c829c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46538;
void __cdecl FUN_00d86670();

void __cdecl FUN_00c829c0()
{
    DAT_00f46538.Setting::Setting();
    atexit(FUN_00d86670);
}
}

// @f3 0x00c82a20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46544;
void __cdecl FUN_00d86680();

void __cdecl FUN_00c82a20()
{
    DAT_00f46544.Setting::Setting();
    atexit(FUN_00d86680);
}
}

// @f3 0x00c82a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82a80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46550;
void __cdecl FUN_00d86690();

void __cdecl FUN_00c82a80()
{
    DAT_00f46550.Setting::Setting();
    atexit(FUN_00d86690);
}
}

// @f3 0x00c82ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82ae0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4655c;
void __cdecl FUN_00d866a0();

void __cdecl FUN_00c82ae0()
{
    DAT_00f4655c.Setting::Setting();
    atexit(FUN_00d866a0);
}
}

// @f3 0x00c82b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46568;
void __cdecl FUN_00d866b0();

void __cdecl FUN_00c82b40()
{
    DAT_00f46568.Setting::Setting();
    atexit(FUN_00d866b0);
}
}

// @f3 0x00c82ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46574;
void __cdecl FUN_00d866c0();

void __cdecl FUN_00c82ba0()
{
    DAT_00f46574.Setting::Setting();
    atexit(FUN_00d866c0);
}
}

// @f3 0x00c82c00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46580;
void __cdecl FUN_00d866d0();

void __cdecl FUN_00c82c00()
{
    DAT_00f46580.Setting::Setting();
    atexit(FUN_00d866d0);
}
}

// @f3 0x00c82c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4658c;
void __cdecl FUN_00d866e0();

void __cdecl FUN_00c82c60()
{
    DAT_00f4658c.Setting::Setting();
    atexit(FUN_00d866e0);
}
}

// @f3 0x00c82cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82cc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46598;
void __cdecl FUN_00d866f0();

void __cdecl FUN_00c82cc0()
{
    DAT_00f46598.Setting::Setting();
    atexit(FUN_00d866f0);
}
}

// @f3 0x00c82d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465a4;
void __cdecl FUN_00d86700();

void __cdecl FUN_00c82d20()
{
    DAT_00f465a4.Setting::Setting();
    atexit(FUN_00d86700);
}
}

// @f3 0x00c82d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465b0;
void __cdecl FUN_00d86710();

void __cdecl FUN_00c82d80()
{
    DAT_00f465b0.Setting::Setting();
    atexit(FUN_00d86710);
}
}

// @f3 0x00c88210 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88210 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a394;
void __cdecl FUN_00d872f0();

void __cdecl FUN_00c88210()
{
    DAT_00f4a394.Setting::Setting();
    atexit(FUN_00d872f0);
}
}

// @f3 0x00c82de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465bc;
void __cdecl FUN_00d86720();

void __cdecl FUN_00c82de0()
{
    DAT_00f465bc.Setting::Setting();
    atexit(FUN_00d86720);
}
}

// @f3 0x00c82e40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465c8;
void __cdecl FUN_00d86730();

void __cdecl FUN_00c82e40()
{
    DAT_00f465c8.Setting::Setting();
    atexit(FUN_00d86730);
}
}

// @f3 0x00c96150 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c96150 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e9d0;
void __cdecl FUN_00d89ad0();

void __cdecl FUN_00c96150()
{
    DAT_00f4e9d0.Setting::Setting();
    atexit(FUN_00d89ad0);
}
}

// @f3 0x00c82ea0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465d4;
void __cdecl FUN_00d86740();

void __cdecl FUN_00c82ea0()
{
    DAT_00f465d4.Setting::Setting();
    atexit(FUN_00d86740);
}
}

// @f3 0x00c82f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c82f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f465e0;
void __cdecl FUN_00d86750();

void __cdecl FUN_00c82f00()
{
    DAT_00f465e0.Setting::Setting();
    atexit(FUN_00d86750);
}
}

// @f3 0x00c83110 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83110 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46824;
void __cdecl FUN_00d86760();

void __cdecl FUN_00c83110()
{
    DAT_00f46824.Setting::Setting();
    atexit(FUN_00d86760);
}
}

// @f3 0x00c83170 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83170 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46830;
void __cdecl FUN_00d86770();

void __cdecl FUN_00c83170()
{
    DAT_00f46830.Setting::Setting();
    atexit(FUN_00d86770);
}
}

// @f3 0x00c831d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c831d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4683c;
void __cdecl FUN_00d86780();

void __cdecl FUN_00c831d0()
{
    DAT_00f4683c.Setting::Setting();
    atexit(FUN_00d86780);
}
}

// @f3 0x00c83530 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83530 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46aa8;
void __cdecl FUN_00d867a0();

void __cdecl FUN_00c83530()
{
    DAT_00f46aa8.Setting::Setting();
    atexit(FUN_00d867a0);
}
}

// @f3 0x00c83590 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83590 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46ab4;
void __cdecl FUN_00d867b0();

void __cdecl FUN_00c83590()
{
    DAT_00f46ab4.Setting::Setting();
    atexit(FUN_00d867b0);
}
}

// @f3 0x00c835f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c835f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46ac0;
void __cdecl FUN_00d867c0();

void __cdecl FUN_00c835f0()
{
    DAT_00f46ac0.Setting::Setting();
    atexit(FUN_00d867c0);
}
}

// @f3 0x00c83650 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83650 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46acc;
void __cdecl FUN_00d867d0();

void __cdecl FUN_00c83650()
{
    DAT_00f46acc.Setting::Setting();
    atexit(FUN_00d867d0);
}
}

// @f3 0x00c836b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c836b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46ad8;
void __cdecl FUN_00d867e0();

void __cdecl FUN_00c836b0()
{
    DAT_00f46ad8.Setting::Setting();
    atexit(FUN_00d867e0);
}
}

// @f3 0x00c83770 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83770 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46af0;
void __cdecl FUN_00d86800();

void __cdecl FUN_00c83770()
{
    DAT_00f46af0.Setting::Setting();
    atexit(FUN_00d86800);
}
}

// @f3 0x00c837d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c837d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46afc;
void __cdecl FUN_00d86810();

void __cdecl FUN_00c837d0()
{
    DAT_00f46afc.Setting::Setting();
    atexit(FUN_00d86810);
}
}

// @f3 0x00c83a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83a80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46bec;
void __cdecl FUN_00d86820();

void __cdecl FUN_00c83a80()
{
    DAT_00f46bec.Setting::Setting();
    atexit(FUN_00d86820);
}
}

// @f3 0x00c83ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83ae0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46bf8;
void __cdecl FUN_00d86830();

void __cdecl FUN_00c83ae0()
{
    DAT_00f46bf8.Setting::Setting();
    atexit(FUN_00d86830);
}
}

// @f3 0x00c83b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c04;
void __cdecl FUN_00d86840();

void __cdecl FUN_00c83b40()
{
    DAT_00f46c04.Setting::Setting();
    atexit(FUN_00d86840);
}
}

// @f3 0x00c83ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c10;
void __cdecl FUN_00d86850();

void __cdecl FUN_00c83ba0()
{
    DAT_00f46c10.Setting::Setting();
    atexit(FUN_00d86850);
}
}

// @f3 0x00c83c00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c1c;
void __cdecl FUN_00d86860();

void __cdecl FUN_00c83c00()
{
    DAT_00f46c1c.Setting::Setting();
    atexit(FUN_00d86860);
}
}

// @f3 0x00c83c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c28;
void __cdecl FUN_00d86870();

void __cdecl FUN_00c83c60()
{
    DAT_00f46c28.Setting::Setting();
    atexit(FUN_00d86870);
}
}

// @f3 0x00c83cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83cc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c34;
void __cdecl FUN_00d86880();

void __cdecl FUN_00c83cc0()
{
    DAT_00f46c34.Setting::Setting();
    atexit(FUN_00d86880);
}
}

// @f3 0x00c83d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c40;
void __cdecl FUN_00d86890();

void __cdecl FUN_00c83d20()
{
    DAT_00f46c40.Setting::Setting();
    atexit(FUN_00d86890);
}
}

// @f3 0x00c83d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c4c;
void __cdecl FUN_00d868a0();

void __cdecl FUN_00c83d80()
{
    DAT_00f46c4c.Setting::Setting();
    atexit(FUN_00d868a0);
}
}

// @f3 0x00c83de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c58;
void __cdecl FUN_00d868b0();

void __cdecl FUN_00c83de0()
{
    DAT_00f46c58.Setting::Setting();
    atexit(FUN_00d868b0);
}
}

// @f3 0x00c83ea0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83ea0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c70;
void __cdecl FUN_00d868d0();

void __cdecl FUN_00c83ea0()
{
    DAT_00f46c70.Setting::Setting();
    atexit(FUN_00d868d0);
}
}

// @f3 0x00c83f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c7c;
void __cdecl FUN_00d868e0();

void __cdecl FUN_00c83f00()
{
    DAT_00f46c7c.Setting::Setting();
    atexit(FUN_00d868e0);
}
}

// @f3 0x00c83f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c88;
void __cdecl FUN_00d868f0();

void __cdecl FUN_00c83f60()
{
    DAT_00f46c88.Setting::Setting();
    atexit(FUN_00d868f0);
}
}

// @f3 0x00c83fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83fc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46c94;
void __cdecl FUN_00d86900();

void __cdecl FUN_00c83fc0()
{
    DAT_00f46c94.Setting::Setting();
    atexit(FUN_00d86900);
}
}

// @f3 0x00c90660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90660 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d99c;
void __cdecl FUN_00d88f10();

void __cdecl FUN_00c90660()
{
    DAT_00f4d99c.Setting::Setting();
    atexit(FUN_00d88f10);
}
}

// @f3 0x00c84020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84020 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46ca0;
void __cdecl FUN_00d86910();

void __cdecl FUN_00c84020()
{
    DAT_00f46ca0.Setting::Setting();
    atexit(FUN_00d86910);
}
}

// @f3 0x00c8df90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8df90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce44;
void __cdecl FUN_00d887e0();

void __cdecl FUN_00c8df90()
{
    DAT_00f4ce44.Setting::Setting();
    atexit(FUN_00d887e0);
}
}

// @f3 0x00c84080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84080 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cac;
void __cdecl FUN_00d86920();

void __cdecl FUN_00c84080()
{
    DAT_00f46cac.Setting::Setting();
    atexit(FUN_00d86920);
}
}

// @f3 0x00c840e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c840e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cb8;
void __cdecl FUN_00d86930();

void __cdecl FUN_00c840e0()
{
    DAT_00f46cb8.Setting::Setting();
    atexit(FUN_00d86930);
}
}

// @f3 0x00c84140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cc4;
void __cdecl FUN_00d86940();

void __cdecl FUN_00c84140()
{
    DAT_00f46cc4.Setting::Setting();
    atexit(FUN_00d86940);
}
}

// @f3 0x00c841a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c841a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cd0;
void __cdecl FUN_00d86950();

void __cdecl FUN_00c841a0()
{
    DAT_00f46cd0.Setting::Setting();
    atexit(FUN_00d86950);
}
}

// @f3 0x00c84200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cdc;
void __cdecl FUN_00d86960();

void __cdecl FUN_00c84200()
{
    DAT_00f46cdc.Setting::Setting();
    atexit(FUN_00d86960);
}
}

// @f3 0x00c908c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c908c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d9dc;
void __cdecl FUN_00d88f20();

void __cdecl FUN_00c908c0()
{
    DAT_00f4d9dc.Setting::Setting();
    atexit(FUN_00d88f20);
}
}

// @f3 0x00c84260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46ce8;
void __cdecl FUN_00d86970();

void __cdecl FUN_00c84260()
{
    DAT_00f46ce8.Setting::Setting();
    atexit(FUN_00d86970);
}
}

// @f3 0x00c842c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c842c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46cf4;
void __cdecl FUN_00d86980();

void __cdecl FUN_00c842c0()
{
    DAT_00f46cf4.Setting::Setting();
    atexit(FUN_00d86980);
}
}

// @f3 0x00c84320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d00;
void __cdecl FUN_00d86990();

void __cdecl FUN_00c84320()
{
    DAT_00f46d00.Setting::Setting();
    atexit(FUN_00d86990);
}
}

// @f3 0x00c84380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d0c;
void __cdecl FUN_00d869a0();

void __cdecl FUN_00c84380()
{
    DAT_00f46d0c.Setting::Setting();
    atexit(FUN_00d869a0);
}
}

// @f3 0x00c843e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c843e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d18;
void __cdecl FUN_00d869b0();

void __cdecl FUN_00c843e0()
{
    DAT_00f46d18.Setting::Setting();
    atexit(FUN_00d869b0);
}
}

// @f3 0x00c84440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d24;
void __cdecl FUN_00d869c0();

void __cdecl FUN_00c84440()
{
    DAT_00f46d24.Setting::Setting();
    atexit(FUN_00d869c0);
}
}

// @f3 0x00c844a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c844a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d30;
void __cdecl FUN_00d869d0();

void __cdecl FUN_00c844a0()
{
    DAT_00f46d30.Setting::Setting();
    atexit(FUN_00d869d0);
}
}

// @f3 0x00c84500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d3c;
void __cdecl FUN_00d869e0();

void __cdecl FUN_00c84500()
{
    DAT_00f46d3c.Setting::Setting();
    atexit(FUN_00d869e0);
}
}

// @f3 0x00c84560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d48;
void __cdecl FUN_00d869f0();

void __cdecl FUN_00c84560()
{
    DAT_00f46d48.Setting::Setting();
    atexit(FUN_00d869f0);
}
}

// @f3 0x00c845c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c845c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d54;
void __cdecl FUN_00d86a00();

void __cdecl FUN_00c845c0()
{
    DAT_00f46d54.Setting::Setting();
    atexit(FUN_00d86a00);
}
}

// @f3 0x00c84620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d60;
void __cdecl FUN_00d86a10();

void __cdecl FUN_00c84620()
{
    DAT_00f46d60.Setting::Setting();
    atexit(FUN_00d86a10);
}
}

// @f3 0x00c84680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d6c;
void __cdecl FUN_00d86a20();

void __cdecl FUN_00c84680()
{
    DAT_00f46d6c.Setting::Setting();
    atexit(FUN_00d86a20);
}
}

// @f3 0x00c846e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c846e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d78;
void __cdecl FUN_00d86a30();

void __cdecl FUN_00c846e0()
{
    DAT_00f46d78.Setting::Setting();
    atexit(FUN_00d86a30);
}
}

// @f3 0x00c84740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84740 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d84;
void __cdecl FUN_00d86a40();

void __cdecl FUN_00c84740()
{
    DAT_00f46d84.Setting::Setting();
    atexit(FUN_00d86a40);
}
}

// @f3 0x00c847a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c847a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d90;
void __cdecl FUN_00d86a50();

void __cdecl FUN_00c847a0()
{
    DAT_00f46d90.Setting::Setting();
    atexit(FUN_00d86a50);
}
}

// @f3 0x00c84800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84800 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46d9c;
void __cdecl FUN_00d86a60();

void __cdecl FUN_00c84800()
{
    DAT_00f46d9c.Setting::Setting();
    atexit(FUN_00d86a60);
}
}

// @f3 0x00c84860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46da8;
void __cdecl FUN_00d86a70();

void __cdecl FUN_00c84860()
{
    DAT_00f46da8.Setting::Setting();
    atexit(FUN_00d86a70);
}
}

// @f3 0x00c848c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c848c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46db4;
void __cdecl FUN_00d86a80();

void __cdecl FUN_00c848c0()
{
    DAT_00f46db4.Setting::Setting();
    atexit(FUN_00d86a80);
}
}

// @f3 0x00c84920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46dc0;
void __cdecl FUN_00d86a90();

void __cdecl FUN_00c84920()
{
    DAT_00f46dc0.Setting::Setting();
    atexit(FUN_00d86a90);
}
}

// @f3 0x00c84980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46dcc;
void __cdecl FUN_00d86aa0();

void __cdecl FUN_00c84980()
{
    DAT_00f46dcc.Setting::Setting();
    atexit(FUN_00d86aa0);
}
}

// @f3 0x00c849e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c849e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46dd8;
void __cdecl FUN_00d86ab0();

void __cdecl FUN_00c849e0()
{
    DAT_00f46dd8.Setting::Setting();
    atexit(FUN_00d86ab0);
}
}

// @f3 0x00c84a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84a40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46de4;
void __cdecl FUN_00d86ac0();

void __cdecl FUN_00c84a40()
{
    DAT_00f46de4.Setting::Setting();
    atexit(FUN_00d86ac0);
}
}

// @f3 0x00c84aa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46df0;
void __cdecl FUN_00d86ad0();

void __cdecl FUN_00c84aa0()
{
    DAT_00f46df0.Setting::Setting();
    atexit(FUN_00d86ad0);
}
}

// @f3 0x00c84b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c84b00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f46dfc;
void __cdecl FUN_00d86ae0();

void __cdecl FUN_00c84b00()
{
    DAT_00f46dfc.Setting::Setting();
    atexit(FUN_00d86ae0);
}
}

// @f3 0x00c85120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47cc0;
void __cdecl FUN_00d86af0();

void __cdecl FUN_00c85120()
{
    DAT_00f47cc0.Setting::Setting();
    atexit(FUN_00d86af0);
}
}

// @f3 0x00c85180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47ccc;
void __cdecl FUN_00d86b00();

void __cdecl FUN_00c85180()
{
    DAT_00f47ccc.Setting::Setting();
    atexit(FUN_00d86b00);
}
}

// @f3 0x00c85660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85660 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d68;
void __cdecl FUN_00d86bd0();

void __cdecl FUN_00c85660()
{
    DAT_00f47d68.Setting::Setting();
    atexit(FUN_00d86bd0);
}
}

// @f3 0x00c851e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c851e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47cd8;
void __cdecl FUN_00d86b10();

void __cdecl FUN_00c851e0()
{
    DAT_00f47cd8.Setting::Setting();
    atexit(FUN_00d86b10);
}
}

// @f3 0x00c85240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47ce4;
void __cdecl FUN_00d86b20();

void __cdecl FUN_00c85240()
{
    DAT_00f47ce4.Setting::Setting();
    atexit(FUN_00d86b20);
}
}

// @f3 0x00c852a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c852a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47cf0;
void __cdecl FUN_00d86b30();

void __cdecl FUN_00c852a0()
{
    DAT_00f47cf0.Setting::Setting();
    atexit(FUN_00d86b30);
}
}

// @f3 0x00c85300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47cfc;
void __cdecl FUN_00d86b40();

void __cdecl FUN_00c85300()
{
    DAT_00f47cfc.Setting::Setting();
    atexit(FUN_00d86b40);
}
}

// @f3 0x00c85360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d08;
void __cdecl FUN_00d86b50();

void __cdecl FUN_00c85360()
{
    DAT_00f47d08.Setting::Setting();
    atexit(FUN_00d86b50);
}
}

// @f3 0x00c853c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c853c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d14;
void __cdecl FUN_00d86b60();

void __cdecl FUN_00c853c0()
{
    DAT_00f47d14.Setting::Setting();
    atexit(FUN_00d86b60);
}
}

// @f3 0x00c85420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d20;
void __cdecl FUN_00d86b70();

void __cdecl FUN_00c85420()
{
    DAT_00f47d20.Setting::Setting();
    atexit(FUN_00d86b70);
}
}

// @f3 0x00c85480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d2c;
void __cdecl FUN_00d86b80();

void __cdecl FUN_00c85480()
{
    DAT_00f47d2c.Setting::Setting();
    atexit(FUN_00d86b80);
}
}

// @f3 0x00c854e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c854e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d38;
void __cdecl FUN_00d86b90();

void __cdecl FUN_00c854e0()
{
    DAT_00f47d38.Setting::Setting();
    atexit(FUN_00d86b90);
}
}

// @f3 0x00c85540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d44;
void __cdecl FUN_00d86ba0();

void __cdecl FUN_00c85540()
{
    DAT_00f47d44.Setting::Setting();
    atexit(FUN_00d86ba0);
}
}

// @f3 0x00c855a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c855a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d50;
void __cdecl FUN_00d86bb0();

void __cdecl FUN_00c855a0()
{
    DAT_00f47d50.Setting::Setting();
    atexit(FUN_00d86bb0);
}
}

// @f3 0x00c85600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d5c;
void __cdecl FUN_00d86bc0();

void __cdecl FUN_00c85600()
{
    DAT_00f47d5c.Setting::Setting();
    atexit(FUN_00d86bc0);
}
}

// @f3 0x00c856c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c856c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d74;
void __cdecl FUN_00d86be0();

void __cdecl FUN_00c856c0()
{
    DAT_00f47d74.Setting::Setting();
    atexit(FUN_00d86be0);
}
}

// @f3 0x00c85720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f47d80;
void __cdecl FUN_00d86bf0();

void __cdecl FUN_00c85720()
{
    DAT_00f47d80.Setting::Setting();
    atexit(FUN_00d86bf0);
}
}

// @f3 0x00c85f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4933c;
void __cdecl FUN_00d86ed0();

// pdb: `dynamic initializer for 'fDebrisMinExtent'' | TES.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00c85f00()
{
    DAT_00f4933c.Setting::Setting();
    atexit(FUN_00d86ed0);
}
}

// @f3 0x00c85f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c85f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f49348;
void __cdecl FUN_00d86ee0();

// pdb: `dynamic initializer for 'fDebrisMaxVelocity'' | TES.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00c85f60()
{
    DAT_00f49348.Setting::Setting();
    atexit(FUN_00d86ee0);
}
}

// @f3 0x00c86130 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c86130 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f49354;
void __cdecl FUN_00d86ef0();

// pdb: `dynamic initializer for 'fFadeToBlackFadeSeconds'' | TES.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00c86130()
{
    DAT_00f49354.Setting::Setting();
    atexit(FUN_00d86ef0);
}
}

// @f3 0x00c86190 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c86190 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f49360;
void __cdecl FUN_00d86f00();

// pdb: `dynamic initializer for 'fCharacterControllerMultipleStepSpeed'' | TES.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00c86190()
{
    DAT_00f49360.Setting::Setting();
    atexit(FUN_00d86f00);
}
}

// @f3 0x00c871f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c871f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a190;
void __cdecl FUN_00d87040();

void __cdecl FUN_00c871f0()
{
    DAT_00f4a190.Setting::Setting();
    atexit(FUN_00d87040);
}
}

// @f3 0x00c87250 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87250 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a19c;
void __cdecl FUN_00d87050();

void __cdecl FUN_00c87250()
{
    DAT_00f4a19c.Setting::Setting();
    atexit(FUN_00d87050);
}
}

// @f3 0x00c872b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c872b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1a8;
void __cdecl FUN_00d87060();

void __cdecl FUN_00c872b0()
{
    DAT_00f4a1a8.Setting::Setting();
    atexit(FUN_00d87060);
}
}

// @f3 0x00c87310 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87310 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1b4;
void __cdecl FUN_00d87070();

void __cdecl FUN_00c87310()
{
    DAT_00f4a1b4.Setting::Setting();
    atexit(FUN_00d87070);
}
}

// @f3 0x00c87370 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87370 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1c0;
void __cdecl FUN_00d87080();

void __cdecl FUN_00c87370()
{
    DAT_00f4a1c0.Setting::Setting();
    atexit(FUN_00d87080);
}
}

// @f3 0x00c873d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c873d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1cc;
void __cdecl FUN_00d87090();

void __cdecl FUN_00c873d0()
{
    DAT_00f4a1cc.Setting::Setting();
    atexit(FUN_00d87090);
}
}

// @f3 0x00c87430 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87430 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1d8;
void __cdecl FUN_00d870a0();

void __cdecl FUN_00c87430()
{
    DAT_00f4a1d8.Setting::Setting();
    atexit(FUN_00d870a0);
}
}

// @f3 0x00c87490 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87490 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1e4;
void __cdecl FUN_00d870b0();

void __cdecl FUN_00c87490()
{
    DAT_00f4a1e4.Setting::Setting();
    atexit(FUN_00d870b0);
}
}

// @f3 0x00c874f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c874f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1f0;
void __cdecl FUN_00d870c0();

void __cdecl FUN_00c874f0()
{
    DAT_00f4a1f0.Setting::Setting();
    atexit(FUN_00d870c0);
}
}

// @f3 0x00c87550 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87550 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a1fc;
void __cdecl FUN_00d870d0();

void __cdecl FUN_00c87550()
{
    DAT_00f4a1fc.Setting::Setting();
    atexit(FUN_00d870d0);
}
}

// @f3 0x00c875b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c875b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a208;
void __cdecl FUN_00d870e0();

void __cdecl FUN_00c875b0()
{
    DAT_00f4a208.Setting::Setting();
    atexit(FUN_00d870e0);
}
}

// @f3 0x00c87610 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87610 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a214;
void __cdecl FUN_00d870f0();

void __cdecl FUN_00c87610()
{
    DAT_00f4a214.Setting::Setting();
    atexit(FUN_00d870f0);
}
}

// @f3 0x00c87670 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87670 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a220;
void __cdecl FUN_00d87100();

void __cdecl FUN_00c87670()
{
    DAT_00f4a220.Setting::Setting();
    atexit(FUN_00d87100);
}
}

// @f3 0x00c876d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c876d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a22c;
void __cdecl FUN_00d87110();

void __cdecl FUN_00c876d0()
{
    DAT_00f4a22c.Setting::Setting();
    atexit(FUN_00d87110);
}
}

// @f3 0x00c87730 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87730 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a238;
void __cdecl FUN_00d87120();

void __cdecl FUN_00c87730()
{
    DAT_00f4a238.Setting::Setting();
    atexit(FUN_00d87120);
}
}

// @f3 0x00c87790 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87790 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a244;
void __cdecl FUN_00d87130();

void __cdecl FUN_00c87790()
{
    DAT_00f4a244.Setting::Setting();
    atexit(FUN_00d87130);
}
}

// @f3 0x00c877f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c877f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a250;
void __cdecl FUN_00d87140();

void __cdecl FUN_00c877f0()
{
    DAT_00f4a250.Setting::Setting();
    atexit(FUN_00d87140);
}
}

// @f3 0x00c87850 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87850 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a25c;
void __cdecl FUN_00d87150();

void __cdecl FUN_00c87850()
{
    DAT_00f4a25c.Setting::Setting();
    atexit(FUN_00d87150);
}
}

// @f3 0x00c878b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c878b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a268;
void __cdecl FUN_00d87160();

void __cdecl FUN_00c878b0()
{
    DAT_00f4a268.Setting::Setting();
    atexit(FUN_00d87160);
}
}

// @f3 0x00c87910 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87910 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a274;
void __cdecl FUN_00d87170();

void __cdecl FUN_00c87910()
{
    DAT_00f4a274.Setting::Setting();
    atexit(FUN_00d87170);
}
}

// @f3 0x00c87970 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87970 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a280;
void __cdecl FUN_00d87180();

void __cdecl FUN_00c87970()
{
    DAT_00f4a280.Setting::Setting();
    atexit(FUN_00d87180);
}
}

// @f3 0x00c879d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c879d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a28c;
void __cdecl FUN_00d87190();

void __cdecl FUN_00c879d0()
{
    DAT_00f4a28c.Setting::Setting();
    atexit(FUN_00d87190);
}
}

// @f3 0x00c87a30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87a30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a298;
void __cdecl FUN_00d871a0();

void __cdecl FUN_00c87a30()
{
    DAT_00f4a298.Setting::Setting();
    atexit(FUN_00d871a0);
}
}

// @f3 0x00c87a90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87a90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2a4;
void __cdecl FUN_00d871b0();

void __cdecl FUN_00c87a90()
{
    DAT_00f4a2a4.Setting::Setting();
    atexit(FUN_00d871b0);
}
}

// @f3 0x00c87af0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87af0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2b0;
void __cdecl FUN_00d871c0();

void __cdecl FUN_00c87af0()
{
    DAT_00f4a2b0.Setting::Setting();
    atexit(FUN_00d871c0);
}
}

// @f3 0x00c87b50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87b50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2bc;
void __cdecl FUN_00d871d0();

void __cdecl FUN_00c87b50()
{
    DAT_00f4a2bc.Setting::Setting();
    atexit(FUN_00d871d0);
}
}

// @f3 0x00c87bb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87bb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2c8;
void __cdecl FUN_00d871e0();

void __cdecl FUN_00c87bb0()
{
    DAT_00f4a2c8.Setting::Setting();
    atexit(FUN_00d871e0);
}
}

// @f3 0x00c87c10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87c10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2d4;
void __cdecl FUN_00d871f0();

void __cdecl FUN_00c87c10()
{
    DAT_00f4a2d4.Setting::Setting();
    atexit(FUN_00d871f0);
}
}

// @f3 0x00c87c70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87c70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2e0;
void __cdecl FUN_00d87200();

void __cdecl FUN_00c87c70()
{
    DAT_00f4a2e0.Setting::Setting();
    atexit(FUN_00d87200);
}
}

// @f3 0x00c87cd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87cd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2ec;
void __cdecl FUN_00d87210();

void __cdecl FUN_00c87cd0()
{
    DAT_00f4a2ec.Setting::Setting();
    atexit(FUN_00d87210);
}
}

// @f3 0x00c87d30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87d30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a2f8;
void __cdecl FUN_00d87220();

void __cdecl FUN_00c87d30()
{
    DAT_00f4a2f8.Setting::Setting();
    atexit(FUN_00d87220);
}
}

// @f3 0x00c87d90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87d90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a304;
void __cdecl FUN_00d87230();

void __cdecl FUN_00c87d90()
{
    DAT_00f4a304.Setting::Setting();
    atexit(FUN_00d87230);
}
}

// @f3 0x00c87df0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87df0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a310;
void __cdecl FUN_00d87240();

void __cdecl FUN_00c87df0()
{
    DAT_00f4a310.Setting::Setting();
    atexit(FUN_00d87240);
}
}

// @f3 0x00c87e50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87e50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a31c;
void __cdecl FUN_00d87250();

void __cdecl FUN_00c87e50()
{
    DAT_00f4a31c.Setting::Setting();
    atexit(FUN_00d87250);
}
}

// @f3 0x00c87eb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87eb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a328;
void __cdecl FUN_00d87260();

void __cdecl FUN_00c87eb0()
{
    DAT_00f4a328.Setting::Setting();
    atexit(FUN_00d87260);
}
}

// @f3 0x00c87f10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87f10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a334;
void __cdecl FUN_00d87270();

void __cdecl FUN_00c87f10()
{
    DAT_00f4a334.Setting::Setting();
    atexit(FUN_00d87270);
}
}

// @f3 0x00c87f70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87f70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a340;
void __cdecl FUN_00d87280();

void __cdecl FUN_00c87f70()
{
    DAT_00f4a340.Setting::Setting();
    atexit(FUN_00d87280);
}
}

// @f3 0x00c87fd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c87fd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a34c;
void __cdecl FUN_00d87290();

void __cdecl FUN_00c87fd0()
{
    DAT_00f4a34c.Setting::Setting();
    atexit(FUN_00d87290);
}
}

// @f3 0x00c88090 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88090 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a364;
void __cdecl FUN_00d872b0();

void __cdecl FUN_00c88090()
{
    DAT_00f4a364.Setting::Setting();
    atexit(FUN_00d872b0);
}
}

// @f3 0x00c970c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c970c0 {

struct Setting { void FUN_0043b7f0(const char* a0, const char* a1); };
extern Setting DAT_01071468;
void __cdecl FUN_00d89c60();
extern const char DAT_00dccd80[];
extern const char DAT_00dccda4[];

// pdb: `dynamic initializer for 'TESObjectLAND::sDefaultLandNormalTexture'' | TESLand.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c970c0()
{
    DAT_01071468.FUN_0043b7f0(DAT_00dccd80, DAT_00dccda4);
    atexit(FUN_00d89c60);
}

}

// @f3 0x00c880f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c880f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a370;
void __cdecl FUN_00d872c0();

void __cdecl FUN_00c880f0()
{
    DAT_00f4a370.Setting::Setting();
    atexit(FUN_00d872c0);
}
}

// @f3 0x00c9eb00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9eb00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e020;
void __cdecl FUN_00d8a900();

void __cdecl FUN_00c9eb00()
{
    DAT_00f5e020.Setting::Setting();
    atexit(FUN_00d8a900);
}
}

// @f3 0x00c88150 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88150 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a37c;
void __cdecl FUN_00d872d0();

void __cdecl FUN_00c88150()
{
    DAT_00f4a37c.Setting::Setting();
    atexit(FUN_00d872d0);
}
}

// @f3 0x00c881b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c881b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a388;
void __cdecl FUN_00d872e0();

void __cdecl FUN_00c881b0()
{
    DAT_00f4a388.Setting::Setting();
    atexit(FUN_00d872e0);
}
}

// @f3 0x00c8b040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8b040 {

struct Setting { void FUN_0043b7f0(const char* a0, const char* a1); };
extern Setting DAT_0106e1ec;
void __cdecl FUN_00d87a10();
extern const char DAT_00dbf550[];
extern const char DAT_01400000[];

// pdb: `dynamic initializer for 'uTextureMemoryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b040()
{
    DAT_0106e1ec.FUN_0043b7f0(DAT_00dbf550, DAT_01400000);
    atexit(FUN_00d87a10);
}

}

// @f3 0x00c88270 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88270 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3a0;
void __cdecl FUN_00d87300();

void __cdecl FUN_00c88270()
{
    DAT_00f4a3a0.Setting::Setting();
    atexit(FUN_00d87300);
}
}

// @f3 0x00c882d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c882d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3ac;
void __cdecl FUN_00d87310();

void __cdecl FUN_00c882d0()
{
    DAT_00f4a3ac.Setting::Setting();
    atexit(FUN_00d87310);
}
}

// @f3 0x00c88330 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88330 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3b8;
void __cdecl FUN_00d87320();

void __cdecl FUN_00c88330()
{
    DAT_00f4a3b8.Setting::Setting();
    atexit(FUN_00d87320);
}
}

// @f3 0x00c88390 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88390 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3c4;
void __cdecl FUN_00d87330();

void __cdecl FUN_00c88390()
{
    DAT_00f4a3c4.Setting::Setting();
    atexit(FUN_00d87330);
}
}

// @f3 0x00c883f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c883f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3d0;
void __cdecl FUN_00d87340();

void __cdecl FUN_00c883f0()
{
    DAT_00f4a3d0.Setting::Setting();
    atexit(FUN_00d87340);
}
}

// @f3 0x00c88450 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88450 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3dc;
void __cdecl FUN_00d87350();

void __cdecl FUN_00c88450()
{
    DAT_00f4a3dc.Setting::Setting();
    atexit(FUN_00d87350);
}
}

// @f3 0x00c884b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c884b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3e8;
void __cdecl FUN_00d87360();

void __cdecl FUN_00c884b0()
{
    DAT_00f4a3e8.Setting::Setting();
    atexit(FUN_00d87360);
}
}

// @f3 0x00c88510 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88510 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a3f4;
void __cdecl FUN_00d87370();

void __cdecl FUN_00c88510()
{
    DAT_00f4a3f4.Setting::Setting();
    atexit(FUN_00d87370);
}
}

// @f3 0x00c88570 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88570 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a400;
void __cdecl FUN_00d87380();

void __cdecl FUN_00c88570()
{
    DAT_00f4a400.Setting::Setting();
    atexit(FUN_00d87380);
}
}

// @f3 0x00c885d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c885d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a40c;
void __cdecl FUN_00d87390();

void __cdecl FUN_00c885d0()
{
    DAT_00f4a40c.Setting::Setting();
    atexit(FUN_00d87390);
}
}

// @f3 0x00c88630 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88630 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a418;
void __cdecl FUN_00d873a0();

void __cdecl FUN_00c88630()
{
    DAT_00f4a418.Setting::Setting();
    atexit(FUN_00d873a0);
}
}

// @f3 0x00c88690 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88690 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a424;
void __cdecl FUN_00d873b0();

void __cdecl FUN_00c88690()
{
    DAT_00f4a424.Setting::Setting();
    atexit(FUN_00d873b0);
}
}

// @f3 0x00c886f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c886f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a430;
void __cdecl FUN_00d873c0();

void __cdecl FUN_00c886f0()
{
    DAT_00f4a430.Setting::Setting();
    atexit(FUN_00d873c0);
}
}

// @f3 0x00c88750 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88750 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a43c;
void __cdecl FUN_00d873d0();

void __cdecl FUN_00c88750()
{
    DAT_00f4a43c.Setting::Setting();
    atexit(FUN_00d873d0);
}
}

// @f3 0x00c887b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c887b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a448;
void __cdecl FUN_00d873e0();

void __cdecl FUN_00c887b0()
{
    DAT_00f4a448.Setting::Setting();
    atexit(FUN_00d873e0);
}
}

// @f3 0x00c88810 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88810 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a454;
void __cdecl FUN_00d873f0();

void __cdecl FUN_00c88810()
{
    DAT_00f4a454.Setting::Setting();
    atexit(FUN_00d873f0);
}
}

// @f3 0x00c88870 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88870 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a460;
void __cdecl FUN_00d87400();

void __cdecl FUN_00c88870()
{
    DAT_00f4a460.Setting::Setting();
    atexit(FUN_00d87400);
}
}

// @f3 0x00c888d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c888d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a46c;
void __cdecl FUN_00d87410();

void __cdecl FUN_00c888d0()
{
    DAT_00f4a46c.Setting::Setting();
    atexit(FUN_00d87410);
}
}

// @f3 0x00c88930 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88930 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a478;
void __cdecl FUN_00d87420();

void __cdecl FUN_00c88930()
{
    DAT_00f4a478.Setting::Setting();
    atexit(FUN_00d87420);
}
}

// @f3 0x00c88990 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88990 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a484;
void __cdecl FUN_00d87430();

void __cdecl FUN_00c88990()
{
    DAT_00f4a484.Setting::Setting();
    atexit(FUN_00d87430);
}
}

// @f3 0x00c889f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c889f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a490;
void __cdecl FUN_00d87440();

void __cdecl FUN_00c889f0()
{
    DAT_00f4a490.Setting::Setting();
    atexit(FUN_00d87440);
}
}

// @f3 0x00c88a50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88a50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a49c;
void __cdecl FUN_00d87450();

void __cdecl FUN_00c88a50()
{
    DAT_00f4a49c.Setting::Setting();
    atexit(FUN_00d87450);
}
}

// @f3 0x00c88ab0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88ab0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4a8;
void __cdecl FUN_00d87460();

void __cdecl FUN_00c88ab0()
{
    DAT_00f4a4a8.Setting::Setting();
    atexit(FUN_00d87460);
}
}

// @f3 0x00c88b10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88b10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4b4;
void __cdecl FUN_00d87470();

void __cdecl FUN_00c88b10()
{
    DAT_00f4a4b4.Setting::Setting();
    atexit(FUN_00d87470);
}
}

// @f3 0x00c88b70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88b70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4c0;
void __cdecl FUN_00d87480();

void __cdecl FUN_00c88b70()
{
    DAT_00f4a4c0.Setting::Setting();
    atexit(FUN_00d87480);
}
}

// @f3 0x00c88bd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88bd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4cc;
void __cdecl FUN_00d87490();

void __cdecl FUN_00c88bd0()
{
    DAT_00f4a4cc.Setting::Setting();
    atexit(FUN_00d87490);
}
}

// @f3 0x00c88c30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88c30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4d8;
void __cdecl FUN_00d874a0();

void __cdecl FUN_00c88c30()
{
    DAT_00f4a4d8.Setting::Setting();
    atexit(FUN_00d874a0);
}
}

// @f3 0x00c88c90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88c90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4e4;
void __cdecl FUN_00d874b0();

void __cdecl FUN_00c88c90()
{
    DAT_00f4a4e4.Setting::Setting();
    atexit(FUN_00d874b0);
}
}

// @f3 0x00c88cf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88cf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4f0;
void __cdecl FUN_00d874c0();

void __cdecl FUN_00c88cf0()
{
    DAT_00f4a4f0.Setting::Setting();
    atexit(FUN_00d874c0);
}
}

// @f3 0x00c88d50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88d50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a4fc;
void __cdecl FUN_00d874d0();

void __cdecl FUN_00c88d50()
{
    DAT_00f4a4fc.Setting::Setting();
    atexit(FUN_00d874d0);
}
}

// @f3 0x00c88db0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88db0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a508;
void __cdecl FUN_00d874e0();

void __cdecl FUN_00c88db0()
{
    DAT_00f4a508.Setting::Setting();
    atexit(FUN_00d874e0);
}
}

// @f3 0x00c88e10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88e10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a514;
void __cdecl FUN_00d874f0();

void __cdecl FUN_00c88e10()
{
    DAT_00f4a514.Setting::Setting();
    atexit(FUN_00d874f0);
}
}

// @f3 0x00c88ed0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88ed0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a52c;
void __cdecl FUN_00d87510();

void __cdecl FUN_00c88ed0()
{
    DAT_00f4a52c.Setting::Setting();
    atexit(FUN_00d87510);
}
}

// @f3 0x00c88f30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88f30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a538;
void __cdecl FUN_00d87520();

void __cdecl FUN_00c88f30()
{
    DAT_00f4a538.Setting::Setting();
    atexit(FUN_00d87520);
}
}

// @f3 0x00c88f90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88f90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a544;
void __cdecl FUN_00d87530();

void __cdecl FUN_00c88f90()
{
    DAT_00f4a544.Setting::Setting();
    atexit(FUN_00d87530);
}
}

// @f3 0x00c88ff0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88ff0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a550;
void __cdecl FUN_00d87540();

void __cdecl FUN_00c88ff0()
{
    DAT_00f4a550.Setting::Setting();
    atexit(FUN_00d87540);
}
}

// @f3 0x00c89050 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89050 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a55c;
void __cdecl FUN_00d87550();

void __cdecl FUN_00c89050()
{
    DAT_00f4a55c.Setting::Setting();
    atexit(FUN_00d87550);
}
}

// @f3 0x00c890b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c890b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a568;
void __cdecl FUN_00d87560();

void __cdecl FUN_00c890b0()
{
    DAT_00f4a568.Setting::Setting();
    atexit(FUN_00d87560);
}
}

// @f3 0x00c89110 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89110 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a574;
void __cdecl FUN_00d87570();

void __cdecl FUN_00c89110()
{
    DAT_00f4a574.Setting::Setting();
    atexit(FUN_00d87570);
}
}

// @f3 0x00c89170 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89170 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a580;
void __cdecl FUN_00d87580();

void __cdecl FUN_00c89170()
{
    DAT_00f4a580.Setting::Setting();
    atexit(FUN_00d87580);
}
}

// @f3 0x00c891d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c891d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a58c;
void __cdecl FUN_00d87590();

void __cdecl FUN_00c891d0()
{
    DAT_00f4a58c.Setting::Setting();
    atexit(FUN_00d87590);
}
}

// @f3 0x00c89230 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89230 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a598;
void __cdecl FUN_00d875a0();

void __cdecl FUN_00c89230()
{
    DAT_00f4a598.Setting::Setting();
    atexit(FUN_00d875a0);
}
}

// @f3 0x00c89290 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89290 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5a4;
void __cdecl FUN_00d875b0();

void __cdecl FUN_00c89290()
{
    DAT_00f4a5a4.Setting::Setting();
    atexit(FUN_00d875b0);
}
}

// @f3 0x00c892f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c892f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5b0;
void __cdecl FUN_00d875c0();

void __cdecl FUN_00c892f0()
{
    DAT_00f4a5b0.Setting::Setting();
    atexit(FUN_00d875c0);
}
}

// @f3 0x00c89350 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89350 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5bc;
void __cdecl FUN_00d875d0();

void __cdecl FUN_00c89350()
{
    DAT_00f4a5bc.Setting::Setting();
    atexit(FUN_00d875d0);
}
}

// @f3 0x00c893b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c893b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5c8;
void __cdecl FUN_00d875e0();

void __cdecl FUN_00c893b0()
{
    DAT_00f4a5c8.Setting::Setting();
    atexit(FUN_00d875e0);
}
}

// @f3 0x00c89410 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89410 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5d4;
void __cdecl FUN_00d875f0();

void __cdecl FUN_00c89410()
{
    DAT_00f4a5d4.Setting::Setting();
    atexit(FUN_00d875f0);
}
}

// @f3 0x00c89470 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89470 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5e0;
void __cdecl FUN_00d87600();

void __cdecl FUN_00c89470()
{
    DAT_00f4a5e0.Setting::Setting();
    atexit(FUN_00d87600);
}
}

// @f3 0x00c894d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c894d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a5ec;
void __cdecl FUN_00d87610();

void __cdecl FUN_00c894d0()
{
    DAT_00f4a5ec.Setting::Setting();
    atexit(FUN_00d87610);
}
}

// @f3 0x00c89590 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89590 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a604;
void __cdecl FUN_00d87630();

void __cdecl FUN_00c89590()
{
    DAT_00f4a604.Setting::Setting();
    atexit(FUN_00d87630);
}
}

// @f3 0x00c895f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c895f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a610;
void __cdecl FUN_00d87640();

void __cdecl FUN_00c895f0()
{
    DAT_00f4a610.Setting::Setting();
    atexit(FUN_00d87640);
}
}

// @f3 0x00c89650 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89650 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a61c;
void __cdecl FUN_00d87650();

void __cdecl FUN_00c89650()
{
    DAT_00f4a61c.Setting::Setting();
    atexit(FUN_00d87650);
}
}

// @f3 0x00c896b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c896b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a628;
void __cdecl FUN_00d87660();

void __cdecl FUN_00c896b0()
{
    DAT_00f4a628.Setting::Setting();
    atexit(FUN_00d87660);
}
}

// @f3 0x00c89710 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89710 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a634;
void __cdecl FUN_00d87670();

void __cdecl FUN_00c89710()
{
    DAT_00f4a634.Setting::Setting();
    atexit(FUN_00d87670);
}
}

// @f3 0x00c89940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89940 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a66c;
void __cdecl FUN_00d87690();

void __cdecl FUN_00c89940()
{
    DAT_00f4a66c.Setting::Setting();
    atexit(FUN_00d87690);
}
}

// @f3 0x00c899a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c899a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a678;
void __cdecl FUN_00d876a0();

void __cdecl FUN_00c899a0()
{
    DAT_00f4a678.Setting::Setting();
    atexit(FUN_00d876a0);
}
}

// @f3 0x00c89a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89a00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a684;
void __cdecl FUN_00d876b0();

void __cdecl FUN_00c89a00()
{
    DAT_00f4a684.Setting::Setting();
    atexit(FUN_00d876b0);
}
}

// @f3 0x00c89a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89a60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a690;
void __cdecl FUN_00d876c0();

void __cdecl FUN_00c89a60()
{
    DAT_00f4a690.Setting::Setting();
    atexit(FUN_00d876c0);
}
}

// @f3 0x00c89ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c89ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4a69c;
void __cdecl FUN_00d876d0();

void __cdecl FUN_00c89ac0()
{
    DAT_00f4a69c.Setting::Setting();
    atexit(FUN_00d876d0);
}
}

// @f3 0x00c8aa90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8aa90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4b198;
void __cdecl FUN_00d87890();

void __cdecl FUN_00c8aa90()
{
    DAT_00f4b198.Setting::Setting();
    atexit(FUN_00d87890);
}
}

// @f3 0x00c8aaf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8aaf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4b1a4;
void __cdecl FUN_00d878a0();

void __cdecl FUN_00c8aaf0()
{
    DAT_00f4b1a4.Setting::Setting();
    atexit(FUN_00d878a0);
}
}

// @f3 0x00c8ab50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8ab50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4b1b0;
void __cdecl FUN_00d878b0();

void __cdecl FUN_00c8ab50()
{
    DAT_00f4b1b0.Setting::Setting();
    atexit(FUN_00d878b0);
}
}

// @f3 0x00c8b840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8b840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4c428;
void __cdecl FUN_00d87d10();

void __cdecl FUN_00c8b840()
{
    DAT_00f4c428.Setting::Setting();
    atexit(FUN_00d87d10);
}
}

// @f3 0x00c8db10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8db10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdb4;
void __cdecl FUN_00d88720();

void __cdecl FUN_00c8db10()
{
    DAT_00f4cdb4.Setting::Setting();
    atexit(FUN_00d88720);
}
}

// @f3 0x00c8db70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8db70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdc0;
void __cdecl FUN_00d88730();

void __cdecl FUN_00c8db70()
{
    DAT_00f4cdc0.Setting::Setting();
    atexit(FUN_00d88730);
}
}

// @f3 0x00c8dbd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dbd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdcc;
void __cdecl FUN_00d88740();

void __cdecl FUN_00c8dbd0()
{
    DAT_00f4cdcc.Setting::Setting();
    atexit(FUN_00d88740);
}
}

// @f3 0x00c8dc30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dc30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdd8;
void __cdecl FUN_00d88750();

void __cdecl FUN_00c8dc30()
{
    DAT_00f4cdd8.Setting::Setting();
    atexit(FUN_00d88750);
}
}

// @f3 0x00c8dc90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dc90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cde4;
void __cdecl FUN_00d88760();

void __cdecl FUN_00c8dc90()
{
    DAT_00f4cde4.Setting::Setting();
    atexit(FUN_00d88760);
}
}

// @f3 0x00c8dcf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dcf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdf0;
void __cdecl FUN_00d88770();

void __cdecl FUN_00c8dcf0()
{
    DAT_00f4cdf0.Setting::Setting();
    atexit(FUN_00d88770);
}
}

// @f3 0x00c8dd50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dd50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cdfc;
void __cdecl FUN_00d88780();

void __cdecl FUN_00c8dd50()
{
    DAT_00f4cdfc.Setting::Setting();
    atexit(FUN_00d88780);
}
}

// @f3 0x00c8ddb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8ddb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce08;
void __cdecl FUN_00d88790();

void __cdecl FUN_00c8ddb0()
{
    DAT_00f4ce08.Setting::Setting();
    atexit(FUN_00d88790);
}
}

// @f3 0x00c8de10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8de10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce14;
void __cdecl FUN_00d887a0();

void __cdecl FUN_00c8de10()
{
    DAT_00f4ce14.Setting::Setting();
    atexit(FUN_00d887a0);
}
}

// @f3 0x00c8de70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8de70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce20;
void __cdecl FUN_00d887b0();

void __cdecl FUN_00c8de70()
{
    DAT_00f4ce20.Setting::Setting();
    atexit(FUN_00d887b0);
}
}

// @f3 0x00c8ded0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8ded0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce2c;
void __cdecl FUN_00d887c0();

void __cdecl FUN_00c8ded0()
{
    DAT_00f4ce2c.Setting::Setting();
    atexit(FUN_00d887c0);
}
}

// @f3 0x00c8df30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8df30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce38;
void __cdecl FUN_00d887d0();

void __cdecl FUN_00c8df30()
{
    DAT_00f4ce38.Setting::Setting();
    atexit(FUN_00d887d0);
}
}

// @f3 0x00c8dff0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8dff0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce50;
void __cdecl FUN_00d887f0();

void __cdecl FUN_00c8dff0()
{
    DAT_00f4ce50.Setting::Setting();
    atexit(FUN_00d887f0);
}
}

// @f3 0x00c8e050 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e050 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce5c;
void __cdecl FUN_00d88800();

void __cdecl FUN_00c8e050()
{
    DAT_00f4ce5c.Setting::Setting();
    atexit(FUN_00d88800);
}
}

// @f3 0x00c8e0b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e0b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce68;
void __cdecl FUN_00d88810();

void __cdecl FUN_00c8e0b0()
{
    DAT_00f4ce68.Setting::Setting();
    atexit(FUN_00d88810);
}
}

// @f3 0x00c8e110 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e110 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce74;
void __cdecl FUN_00d88820();

void __cdecl FUN_00c8e110()
{
    DAT_00f4ce74.Setting::Setting();
    atexit(FUN_00d88820);
}
}

// @f3 0x00c8e170 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e170 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce80;
void __cdecl FUN_00d88830();

void __cdecl FUN_00c8e170()
{
    DAT_00f4ce80.Setting::Setting();
    atexit(FUN_00d88830);
}
}

// @f3 0x00c8e1d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e1d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce8c;
void __cdecl FUN_00d88840();

void __cdecl FUN_00c8e1d0()
{
    DAT_00f4ce8c.Setting::Setting();
    atexit(FUN_00d88840);
}
}

// @f3 0x00c8e230 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e230 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ce98;
void __cdecl FUN_00d88850();

void __cdecl FUN_00c8e230()
{
    DAT_00f4ce98.Setting::Setting();
    atexit(FUN_00d88850);
}
}

// @f3 0x00c8e290 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e290 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cea4;
void __cdecl FUN_00d88860();

void __cdecl FUN_00c8e290()
{
    DAT_00f4cea4.Setting::Setting();
    atexit(FUN_00d88860);
}
}

// @f3 0x00c91900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de70;
void __cdecl FUN_00d890f0();

void __cdecl FUN_00c91900()
{
    DAT_00f4de70.Setting::Setting();
    atexit(FUN_00d890f0);
}
}

// @f3 0x00c8e2f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e2f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ceb0;
void __cdecl FUN_00d88870();

void __cdecl FUN_00c8e2f0()
{
    DAT_00f4ceb0.Setting::Setting();
    atexit(FUN_00d88870);
}
}

// @f3 0x00c8e350 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e350 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cebc;
void __cdecl FUN_00d88880();

void __cdecl FUN_00c8e350()
{
    DAT_00f4cebc.Setting::Setting();
    atexit(FUN_00d88880);
}
}

// @f3 0x00c8e3b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e3b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cec8;
void __cdecl FUN_00d88890();

void __cdecl FUN_00c8e3b0()
{
    DAT_00f4cec8.Setting::Setting();
    atexit(FUN_00d88890);
}
}

// @f3 0x00c8e410 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e410 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ced4;
void __cdecl FUN_00d888a0();

void __cdecl FUN_00c8e410()
{
    DAT_00f4ced4.Setting::Setting();
    atexit(FUN_00d888a0);
}
}

// @f3 0x00c8e470 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e470 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cee0;
void __cdecl FUN_00d888b0();

void __cdecl FUN_00c8e470()
{
    DAT_00f4cee0.Setting::Setting();
    atexit(FUN_00d888b0);
}
}

// @f3 0x00c8e4d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e4d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ceec;
void __cdecl FUN_00d888c0();

void __cdecl FUN_00c8e4d0()
{
    DAT_00f4ceec.Setting::Setting();
    atexit(FUN_00d888c0);
}
}

// @f3 0x00c8e530 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e530 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cef8;
void __cdecl FUN_00d888d0();

void __cdecl FUN_00c8e530()
{
    DAT_00f4cef8.Setting::Setting();
    atexit(FUN_00d888d0);
}
}

// @f3 0x00c8e590 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e590 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf04;
void __cdecl FUN_00d888e0();

void __cdecl FUN_00c8e590()
{
    DAT_00f4cf04.Setting::Setting();
    atexit(FUN_00d888e0);
}
}

// @f3 0x00c8e5f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e5f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf10;
void __cdecl FUN_00d888f0();

void __cdecl FUN_00c8e5f0()
{
    DAT_00f4cf10.Setting::Setting();
    atexit(FUN_00d888f0);
}
}

// @f3 0x00c8e650 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e650 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf1c;
void __cdecl FUN_00d88900();

void __cdecl FUN_00c8e650()
{
    DAT_00f4cf1c.Setting::Setting();
    atexit(FUN_00d88900);
}
}

// @f3 0x00c8e6b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e6b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf28;
void __cdecl FUN_00d88910();

void __cdecl FUN_00c8e6b0()
{
    DAT_00f4cf28.Setting::Setting();
    atexit(FUN_00d88910);
}
}

// @f3 0x00c8e710 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e710 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf34;
void __cdecl FUN_00d88920();

void __cdecl FUN_00c8e710()
{
    DAT_00f4cf34.Setting::Setting();
    atexit(FUN_00d88920);
}
}

// @f3 0x00c8e770 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e770 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf40;
void __cdecl FUN_00d88930();

void __cdecl FUN_00c8e770()
{
    DAT_00f4cf40.Setting::Setting();
    atexit(FUN_00d88930);
}
}

// @f3 0x00c8e7d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e7d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf4c;
void __cdecl FUN_00d88940();

void __cdecl FUN_00c8e7d0()
{
    DAT_00f4cf4c.Setting::Setting();
    atexit(FUN_00d88940);
}
}

// @f3 0x00c8e830 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e830 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf58;
void __cdecl FUN_00d88950();

void __cdecl FUN_00c8e830()
{
    DAT_00f4cf58.Setting::Setting();
    atexit(FUN_00d88950);
}
}

// @f3 0x00c8e890 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e890 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf64;
void __cdecl FUN_00d88960();

void __cdecl FUN_00c8e890()
{
    DAT_00f4cf64.Setting::Setting();
    atexit(FUN_00d88960);
}
}

// @f3 0x00c8e8f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c8e8f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4cf70;
void __cdecl FUN_00d88970();

void __cdecl FUN_00c8e8f0()
{
    DAT_00f4cf70.Setting::Setting();
    atexit(FUN_00d88970);
}
}

// @f3 0x00c901e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c901e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d90c;
void __cdecl FUN_00d88e50();

void __cdecl FUN_00c901e0()
{
    DAT_00f4d90c.Setting::Setting();
    atexit(FUN_00d88e50);
}
}

// @f3 0x00c90240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d918;
void __cdecl FUN_00d88e60();

void __cdecl FUN_00c90240()
{
    DAT_00f4d918.Setting::Setting();
    atexit(FUN_00d88e60);
}
}

// @f3 0x00c90300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d930;
void __cdecl FUN_00d88e80();

void __cdecl FUN_00c90300()
{
    DAT_00f4d930.Setting::Setting();
    atexit(FUN_00d88e80);
}
}

// @f3 0x00c90360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d93c;
void __cdecl FUN_00d88e90();

void __cdecl FUN_00c90360()
{
    DAT_00f4d93c.Setting::Setting();
    atexit(FUN_00d88e90);
}
}

// @f3 0x00c903c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c903c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d948;
void __cdecl FUN_00d88ea0();

void __cdecl FUN_00c903c0()
{
    DAT_00f4d948.Setting::Setting();
    atexit(FUN_00d88ea0);
}
}

// @f3 0x00c90420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d954;
void __cdecl FUN_00d88eb0();

void __cdecl FUN_00c90420()
{
    DAT_00f4d954.Setting::Setting();
    atexit(FUN_00d88eb0);
}
}

// @f3 0x00c90480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d960;
void __cdecl FUN_00d88ec0();

void __cdecl FUN_00c90480()
{
    DAT_00f4d960.Setting::Setting();
    atexit(FUN_00d88ec0);
}
}

// @f3 0x00c904e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c904e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d96c;
void __cdecl FUN_00d88ed0();

void __cdecl FUN_00c904e0()
{
    DAT_00f4d96c.Setting::Setting();
    atexit(FUN_00d88ed0);
}
}

// @f3 0x00c90540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d978;
void __cdecl FUN_00d88ee0();

void __cdecl FUN_00c90540()
{
    DAT_00f4d978.Setting::Setting();
    atexit(FUN_00d88ee0);
}
}

// @f3 0x00c905a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c905a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d984;
void __cdecl FUN_00d88ef0();

void __cdecl FUN_00c905a0()
{
    DAT_00f4d984.Setting::Setting();
    atexit(FUN_00d88ef0);
}
}

// @f3 0x00c90600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4d990;
void __cdecl FUN_00d88f00();

void __cdecl FUN_00c90600()
{
    DAT_00f4d990.Setting::Setting();
    atexit(FUN_00d88f00);
}
}

// @f3 0x00c90cd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90cd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4da78;
void __cdecl FUN_00d88f30();

void __cdecl FUN_00c90cd0()
{
    DAT_00f4da78.Setting::Setting();
    atexit(FUN_00d88f30);
}
}

// @f3 0x00c90d30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90d30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4da84;
void __cdecl FUN_00d88f40();

void __cdecl FUN_00c90d30()
{
    DAT_00f4da84.Setting::Setting();
    atexit(FUN_00d88f40);
}
}

// @f3 0x00c90f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90f40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd38;
void __cdecl FUN_00d88f50();

void __cdecl FUN_00c90f40()
{
    DAT_00f4dd38.Setting::Setting();
    atexit(FUN_00d88f50);
}
}

// @f3 0x00c90fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c90fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd44;
void __cdecl FUN_00d88f60();

void __cdecl FUN_00c90fa0()
{
    DAT_00f4dd44.Setting::Setting();
    atexit(FUN_00d88f60);
}
}

// @f3 0x00c91000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91000 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd50;
void __cdecl FUN_00d88f70();

void __cdecl FUN_00c91000()
{
    DAT_00f4dd50.Setting::Setting();
    atexit(FUN_00d88f70);
}
}

// @f3 0x00c91060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91060 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd5c;
void __cdecl FUN_00d88f80();

void __cdecl FUN_00c91060()
{
    DAT_00f4dd5c.Setting::Setting();
    atexit(FUN_00d88f80);
}
}

// @f3 0x00c910c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c910c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd68;
void __cdecl FUN_00d88f90();

void __cdecl FUN_00c910c0()
{
    DAT_00f4dd68.Setting::Setting();
    atexit(FUN_00d88f90);
}
}

// @f3 0x00c91120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd74;
void __cdecl FUN_00d88fa0();

void __cdecl FUN_00c91120()
{
    DAT_00f4dd74.Setting::Setting();
    atexit(FUN_00d88fa0);
}
}

// @f3 0x00c91180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd80;
void __cdecl FUN_00d88fb0();

void __cdecl FUN_00c91180()
{
    DAT_00f4dd80.Setting::Setting();
    atexit(FUN_00d88fb0);
}
}

// @f3 0x00c911e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c911e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd8c;
void __cdecl FUN_00d88fc0();

void __cdecl FUN_00c911e0()
{
    DAT_00f4dd8c.Setting::Setting();
    atexit(FUN_00d88fc0);
}
}

// @f3 0x00c91240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dd98;
void __cdecl FUN_00d88fd0();

void __cdecl FUN_00c91240()
{
    DAT_00f4dd98.Setting::Setting();
    atexit(FUN_00d88fd0);
}
}

// @f3 0x00c912a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c912a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dda4;
void __cdecl FUN_00d88fe0();

void __cdecl FUN_00c912a0()
{
    DAT_00f4dda4.Setting::Setting();
    atexit(FUN_00d88fe0);
}
}

// @f3 0x00c91300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddb0;
void __cdecl FUN_00d88ff0();

void __cdecl FUN_00c91300()
{
    DAT_00f4ddb0.Setting::Setting();
    atexit(FUN_00d88ff0);
}
}

// @f3 0x00c91360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddbc;
void __cdecl FUN_00d89000();

void __cdecl FUN_00c91360()
{
    DAT_00f4ddbc.Setting::Setting();
    atexit(FUN_00d89000);
}
}

// @f3 0x00c913c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c913c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddc8;
void __cdecl FUN_00d89010();

void __cdecl FUN_00c913c0()
{
    DAT_00f4ddc8.Setting::Setting();
    atexit(FUN_00d89010);
}
}

// @f3 0x00c91420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddd4;
void __cdecl FUN_00d89020();

void __cdecl FUN_00c91420()
{
    DAT_00f4ddd4.Setting::Setting();
    atexit(FUN_00d89020);
}
}

// @f3 0x00c91480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dde0;
void __cdecl FUN_00d89030();

void __cdecl FUN_00c91480()
{
    DAT_00f4dde0.Setting::Setting();
    atexit(FUN_00d89030);
}
}

// @f3 0x00c914e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c914e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddec;
void __cdecl FUN_00d89040();

void __cdecl FUN_00c914e0()
{
    DAT_00f4ddec.Setting::Setting();
    atexit(FUN_00d89040);
}
}

// @f3 0x00c91540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ddf8;
void __cdecl FUN_00d89050();

void __cdecl FUN_00c91540()
{
    DAT_00f4ddf8.Setting::Setting();
    atexit(FUN_00d89050);
}
}

// @f3 0x00c915a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c915a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de04;
void __cdecl FUN_00d89060();

void __cdecl FUN_00c915a0()
{
    DAT_00f4de04.Setting::Setting();
    atexit(FUN_00d89060);
}
}

// @f3 0x00c91600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de10;
void __cdecl FUN_00d89070();

void __cdecl FUN_00c91600()
{
    DAT_00f4de10.Setting::Setting();
    atexit(FUN_00d89070);
}
}

// @f3 0x00c91660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91660 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de1c;
void __cdecl FUN_00d89080();

void __cdecl FUN_00c91660()
{
    DAT_00f4de1c.Setting::Setting();
    atexit(FUN_00d89080);
}
}

// @f3 0x00c916c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c916c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de28;
void __cdecl FUN_00d89090();

void __cdecl FUN_00c916c0()
{
    DAT_00f4de28.Setting::Setting();
    atexit(FUN_00d89090);
}
}

// @f3 0x00c91720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de34;
void __cdecl FUN_00d890a0();

void __cdecl FUN_00c91720()
{
    DAT_00f4de34.Setting::Setting();
    atexit(FUN_00d890a0);
}
}

// @f3 0x00c91780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de40;
void __cdecl FUN_00d890b0();

void __cdecl FUN_00c91780()
{
    DAT_00f4de40.Setting::Setting();
    atexit(FUN_00d890b0);
}
}

// @f3 0x00c917e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c917e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de4c;
void __cdecl FUN_00d890c0();

void __cdecl FUN_00c917e0()
{
    DAT_00f4de4c.Setting::Setting();
    atexit(FUN_00d890c0);
}
}

// @f3 0x00c91840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de58;
void __cdecl FUN_00d890d0();

void __cdecl FUN_00c91840()
{
    DAT_00f4de58.Setting::Setting();
    atexit(FUN_00d890d0);
}
}

// @f3 0x00c918a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c918a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de64;
void __cdecl FUN_00d890e0();

void __cdecl FUN_00c918a0()
{
    DAT_00f4de64.Setting::Setting();
    atexit(FUN_00d890e0);
}
}

// @f3 0x00c91960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de7c;
void __cdecl FUN_00d89100();

void __cdecl FUN_00c91960()
{
    DAT_00f4de7c.Setting::Setting();
    atexit(FUN_00d89100);
}
}

// @f3 0x00c919c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c919c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de88;
void __cdecl FUN_00d89110();

void __cdecl FUN_00c919c0()
{
    DAT_00f4de88.Setting::Setting();
    atexit(FUN_00d89110);
}
}

// @f3 0x00c91a20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4de94;
void __cdecl FUN_00d89120();

void __cdecl FUN_00c91a20()
{
    DAT_00f4de94.Setting::Setting();
    atexit(FUN_00d89120);
}
}

// @f3 0x00c91a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91a80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dea0;
void __cdecl FUN_00d89130();

void __cdecl FUN_00c91a80()
{
    DAT_00f4dea0.Setting::Setting();
    atexit(FUN_00d89130);
}
}

// @f3 0x00c91ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91ae0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4deac;
void __cdecl FUN_00d89140();

void __cdecl FUN_00c91ae0()
{
    DAT_00f4deac.Setting::Setting();
    atexit(FUN_00d89140);
}
}

// @f3 0x00c91b40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91b40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4deb8;
void __cdecl FUN_00d89150();

void __cdecl FUN_00c91b40()
{
    DAT_00f4deb8.Setting::Setting();
    atexit(FUN_00d89150);
}
}

// @f3 0x00c91ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91ba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dec4;
void __cdecl FUN_00d89160();

void __cdecl FUN_00c91ba0()
{
    DAT_00f4dec4.Setting::Setting();
    atexit(FUN_00d89160);
}
}

// @f3 0x00c91c00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91c00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ded0;
void __cdecl FUN_00d89170();

void __cdecl FUN_00c91c00()
{
    DAT_00f4ded0.Setting::Setting();
    atexit(FUN_00d89170);
}
}

// @f3 0x00c91c60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91c60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dedc;
void __cdecl FUN_00d89180();

void __cdecl FUN_00c91c60()
{
    DAT_00f4dedc.Setting::Setting();
    atexit(FUN_00d89180);
}
}

// @f3 0x00c91cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91cc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dee8;
void __cdecl FUN_00d89190();

void __cdecl FUN_00c91cc0()
{
    DAT_00f4dee8.Setting::Setting();
    atexit(FUN_00d89190);
}
}

// @f3 0x00c91d20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91d20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4def4;
void __cdecl FUN_00d891a0();

void __cdecl FUN_00c91d20()
{
    DAT_00f4def4.Setting::Setting();
    atexit(FUN_00d891a0);
}
}

// @f3 0x00c91d80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91d80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df00;
void __cdecl FUN_00d891b0();

void __cdecl FUN_00c91d80()
{
    DAT_00f4df00.Setting::Setting();
    atexit(FUN_00d891b0);
}
}

// @f3 0x00c91de0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91de0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df0c;
void __cdecl FUN_00d891c0();

void __cdecl FUN_00c91de0()
{
    DAT_00f4df0c.Setting::Setting();
    atexit(FUN_00d891c0);
}
}

// @f3 0x00c91e40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91e40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df18;
void __cdecl FUN_00d891d0();

void __cdecl FUN_00c91e40()
{
    DAT_00f4df18.Setting::Setting();
    atexit(FUN_00d891d0);
}
}

// @f3 0x00c91f00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91f00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df30;
void __cdecl FUN_00d891f0();

void __cdecl FUN_00c91f00()
{
    DAT_00f4df30.Setting::Setting();
    atexit(FUN_00d891f0);
}
}

// @f3 0x00c91f60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91f60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df3c;
void __cdecl FUN_00d89200();

void __cdecl FUN_00c91f60()
{
    DAT_00f4df3c.Setting::Setting();
    atexit(FUN_00d89200);
}
}

// @f3 0x00c91fc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c91fc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df48;
void __cdecl FUN_00d89210();

void __cdecl FUN_00c91fc0()
{
    DAT_00f4df48.Setting::Setting();
    atexit(FUN_00d89210);
}
}

// @f3 0x00c92020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92020 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df54;
void __cdecl FUN_00d89220();

void __cdecl FUN_00c92020()
{
    DAT_00f4df54.Setting::Setting();
    atexit(FUN_00d89220);
}
}

// @f3 0x00c92080 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92080 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df60;
void __cdecl FUN_00d89230();

void __cdecl FUN_00c92080()
{
    DAT_00f4df60.Setting::Setting();
    atexit(FUN_00d89230);
}
}

// @f3 0x00c920e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c920e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df6c;
void __cdecl FUN_00d89240();

void __cdecl FUN_00c920e0()
{
    DAT_00f4df6c.Setting::Setting();
    atexit(FUN_00d89240);
}
}

// @f3 0x00c92140 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92140 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df78;
void __cdecl FUN_00d89250();

void __cdecl FUN_00c92140()
{
    DAT_00f4df78.Setting::Setting();
    atexit(FUN_00d89250);
}
}

// @f3 0x00c921a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c921a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df84;
void __cdecl FUN_00d89260();

void __cdecl FUN_00c921a0()
{
    DAT_00f4df84.Setting::Setting();
    atexit(FUN_00d89260);
}
}

// @f3 0x00c92200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df90;
void __cdecl FUN_00d89270();

void __cdecl FUN_00c92200()
{
    DAT_00f4df90.Setting::Setting();
    atexit(FUN_00d89270);
}
}

// @f3 0x00c92260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4df9c;
void __cdecl FUN_00d89280();

void __cdecl FUN_00c92260()
{
    DAT_00f4df9c.Setting::Setting();
    atexit(FUN_00d89280);
}
}

// @f3 0x00c922c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c922c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfa8;
void __cdecl FUN_00d89290();

void __cdecl FUN_00c922c0()
{
    DAT_00f4dfa8.Setting::Setting();
    atexit(FUN_00d89290);
}
}

// @f3 0x00c92320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92320 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfb4;
void __cdecl FUN_00d892a0();

void __cdecl FUN_00c92320()
{
    DAT_00f4dfb4.Setting::Setting();
    atexit(FUN_00d892a0);
}
}

// @f3 0x00c92380 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92380 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfc0;
void __cdecl FUN_00d892b0();

void __cdecl FUN_00c92380()
{
    DAT_00f4dfc0.Setting::Setting();
    atexit(FUN_00d892b0);
}
}

// @f3 0x00c923e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c923e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfcc;
void __cdecl FUN_00d892c0();

void __cdecl FUN_00c923e0()
{
    DAT_00f4dfcc.Setting::Setting();
    atexit(FUN_00d892c0);
}
}

// @f3 0x00c92440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfd8;
void __cdecl FUN_00d892d0();

void __cdecl FUN_00c92440()
{
    DAT_00f4dfd8.Setting::Setting();
    atexit(FUN_00d892d0);
}
}

// @f3 0x00c924a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c924a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dfe4;
void __cdecl FUN_00d892e0();

void __cdecl FUN_00c924a0()
{
    DAT_00f4dfe4.Setting::Setting();
    atexit(FUN_00d892e0);
}
}

// @f3 0x00c92500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dff0;
void __cdecl FUN_00d892f0();

void __cdecl FUN_00c92500()
{
    DAT_00f4dff0.Setting::Setting();
    atexit(FUN_00d892f0);
}
}

// @f3 0x00c92560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4dffc;
void __cdecl FUN_00d89300();

void __cdecl FUN_00c92560()
{
    DAT_00f4dffc.Setting::Setting();
    atexit(FUN_00d89300);
}
}

// @f3 0x00c925c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c925c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e008;
void __cdecl FUN_00d89310();

void __cdecl FUN_00c925c0()
{
    DAT_00f4e008.Setting::Setting();
    atexit(FUN_00d89310);
}
}

// @f3 0x00c92620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e014;
void __cdecl FUN_00d89320();

void __cdecl FUN_00c92620()
{
    DAT_00f4e014.Setting::Setting();
    atexit(FUN_00d89320);
}
}

// @f3 0x00c92680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e020;
void __cdecl FUN_00d89330();

void __cdecl FUN_00c92680()
{
    DAT_00f4e020.Setting::Setting();
    atexit(FUN_00d89330);
}
}

// @f3 0x00c926e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c926e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e02c;
void __cdecl FUN_00d89340();

void __cdecl FUN_00c926e0()
{
    DAT_00f4e02c.Setting::Setting();
    atexit(FUN_00d89340);
}
}

// @f3 0x00c92740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92740 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e038;
void __cdecl FUN_00d89350();

void __cdecl FUN_00c92740()
{
    DAT_00f4e038.Setting::Setting();
    atexit(FUN_00d89350);
}
}

// @f3 0x00c927a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c927a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e044;
void __cdecl FUN_00d89360();

void __cdecl FUN_00c927a0()
{
    DAT_00f4e044.Setting::Setting();
    atexit(FUN_00d89360);
}
}

// @f3 0x00c92860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e05c;
void __cdecl FUN_00d89380();

void __cdecl FUN_00c92860()
{
    DAT_00f4e05c.Setting::Setting();
    atexit(FUN_00d89380);
}
}

// @f3 0x00c928c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c928c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e068;
void __cdecl FUN_00d89390();

void __cdecl FUN_00c928c0()
{
    DAT_00f4e068.Setting::Setting();
    atexit(FUN_00d89390);
}
}

// @f3 0x00c92920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e074;
void __cdecl FUN_00d893a0();

void __cdecl FUN_00c92920()
{
    DAT_00f4e074.Setting::Setting();
    atexit(FUN_00d893a0);
}
}

// @f3 0x00c92980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e080;
void __cdecl FUN_00d893b0();

void __cdecl FUN_00c92980()
{
    DAT_00f4e080.Setting::Setting();
    atexit(FUN_00d893b0);
}
}

// @f3 0x00c929e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c929e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e08c;
void __cdecl FUN_00d893c0();

void __cdecl FUN_00c929e0()
{
    DAT_00f4e08c.Setting::Setting();
    atexit(FUN_00d893c0);
}
}

// @f3 0x00c92a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92a40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e098;
void __cdecl FUN_00d893d0();

void __cdecl FUN_00c92a40()
{
    DAT_00f4e098.Setting::Setting();
    atexit(FUN_00d893d0);
}
}

// @f3 0x00c92aa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92aa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0a4;
void __cdecl FUN_00d893e0();

void __cdecl FUN_00c92aa0()
{
    DAT_00f4e0a4.Setting::Setting();
    atexit(FUN_00d893e0);
}
}

// @f3 0x00c92b00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92b00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0b0;
void __cdecl FUN_00d893f0();

void __cdecl FUN_00c92b00()
{
    DAT_00f4e0b0.Setting::Setting();
    atexit(FUN_00d893f0);
}
}

// @f3 0x00c92b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92b60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0bc;
void __cdecl FUN_00d89400();

void __cdecl FUN_00c92b60()
{
    DAT_00f4e0bc.Setting::Setting();
    atexit(FUN_00d89400);
}
}

// @f3 0x00c92bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92bc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0c8;
void __cdecl FUN_00d89410();

void __cdecl FUN_00c92bc0()
{
    DAT_00f4e0c8.Setting::Setting();
    atexit(FUN_00d89410);
}
}

// @f3 0x00c92c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92c20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0d4;
void __cdecl FUN_00d89420();

void __cdecl FUN_00c92c20()
{
    DAT_00f4e0d4.Setting::Setting();
    atexit(FUN_00d89420);
}
}

// @f3 0x00c92c80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92c80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0e0;
void __cdecl FUN_00d89430();

void __cdecl FUN_00c92c80()
{
    DAT_00f4e0e0.Setting::Setting();
    atexit(FUN_00d89430);
}
}

// @f3 0x00c92ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92ce0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0ec;
void __cdecl FUN_00d89440();

void __cdecl FUN_00c92ce0()
{
    DAT_00f4e0ec.Setting::Setting();
    atexit(FUN_00d89440);
}
}

// @f3 0x00c92d40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92d40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e0f8;
void __cdecl FUN_00d89450();

void __cdecl FUN_00c92d40()
{
    DAT_00f4e0f8.Setting::Setting();
    atexit(FUN_00d89450);
}
}

// @f3 0x00c92da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92da0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e104;
void __cdecl FUN_00d89460();

void __cdecl FUN_00c92da0()
{
    DAT_00f4e104.Setting::Setting();
    atexit(FUN_00d89460);
}
}

// @f3 0x00c92e00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92e00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e110;
void __cdecl FUN_00d89470();

void __cdecl FUN_00c92e00()
{
    DAT_00f4e110.Setting::Setting();
    atexit(FUN_00d89470);
}
}

// @f3 0x00c92e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92e60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e11c;
void __cdecl FUN_00d89480();

void __cdecl FUN_00c92e60()
{
    DAT_00f4e11c.Setting::Setting();
    atexit(FUN_00d89480);
}
}

// @f3 0x00c92ec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92ec0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e128;
void __cdecl FUN_00d89490();

void __cdecl FUN_00c92ec0()
{
    DAT_00f4e128.Setting::Setting();
    atexit(FUN_00d89490);
}
}

// @f3 0x00c92f80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e140;
void __cdecl FUN_00d894b0();

void __cdecl FUN_00c92f80()
{
    DAT_00f4e140.Setting::Setting();
    atexit(FUN_00d894b0);
}
}

// @f3 0x00c92fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92fe0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e14c;
void __cdecl FUN_00d894c0();

void __cdecl FUN_00c92fe0()
{
    DAT_00f4e14c.Setting::Setting();
    atexit(FUN_00d894c0);
}
}

// @f3 0x00c930a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c930a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e164;
void __cdecl FUN_00d894e0();

void __cdecl FUN_00c930a0()
{
    DAT_00f4e164.Setting::Setting();
    atexit(FUN_00d894e0);
}
}

// @f3 0x00c93100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93100 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e170;
void __cdecl FUN_00d894f0();

void __cdecl FUN_00c93100()
{
    DAT_00f4e170.Setting::Setting();
    atexit(FUN_00d894f0);
}
}

// @f3 0x00c93160 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93160 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e17c;
void __cdecl FUN_00d89500();

void __cdecl FUN_00c93160()
{
    DAT_00f4e17c.Setting::Setting();
    atexit(FUN_00d89500);
}
}

// @f3 0x00c931c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c931c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e188;
void __cdecl FUN_00d89510();

void __cdecl FUN_00c931c0()
{
    DAT_00f4e188.Setting::Setting();
    atexit(FUN_00d89510);
}
}

// @f3 0x00c93220 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93220 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e194;
void __cdecl FUN_00d89520();

void __cdecl FUN_00c93220()
{
    DAT_00f4e194.Setting::Setting();
    atexit(FUN_00d89520);
}
}

// @f3 0x00c93280 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1a0;
void __cdecl FUN_00d89530();

void __cdecl FUN_00c93280()
{
    DAT_00f4e1a0.Setting::Setting();
    atexit(FUN_00d89530);
}
}

// @f3 0x00c93340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1b8;
void __cdecl FUN_00d89550();

void __cdecl FUN_00c93340()
{
    DAT_00f4e1b8.Setting::Setting();
    atexit(FUN_00d89550);
}
}

// @f3 0x00c933a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c933a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1c4;
void __cdecl FUN_00d89560();

void __cdecl FUN_00c933a0()
{
    DAT_00f4e1c4.Setting::Setting();
    atexit(FUN_00d89560);
}
}

// @f3 0x00c93400 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1d0;
void __cdecl FUN_00d89570();

void __cdecl FUN_00c93400()
{
    DAT_00f4e1d0.Setting::Setting();
    atexit(FUN_00d89570);
}
}

// @f3 0x00c93460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1dc;
void __cdecl FUN_00d89580();

void __cdecl FUN_00c93460()
{
    DAT_00f4e1dc.Setting::Setting();
    atexit(FUN_00d89580);
}
}

// @f3 0x00c934c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c934c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1e8;
void __cdecl FUN_00d89590();

void __cdecl FUN_00c934c0()
{
    DAT_00f4e1e8.Setting::Setting();
    atexit(FUN_00d89590);
}
}

// @f3 0x00c93520 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e1f4;
void __cdecl FUN_00d895a0();

void __cdecl FUN_00c93520()
{
    DAT_00f4e1f4.Setting::Setting();
    atexit(FUN_00d895a0);
}
}

// @f3 0x00c93580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93580 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e200;
void __cdecl FUN_00d895b0();

void __cdecl FUN_00c93580()
{
    DAT_00f4e200.Setting::Setting();
    atexit(FUN_00d895b0);
}
}

// @f3 0x00c935e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c935e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e20c;
void __cdecl FUN_00d895c0();

void __cdecl FUN_00c935e0()
{
    DAT_00f4e20c.Setting::Setting();
    atexit(FUN_00d895c0);
}
}

// @f3 0x00c93640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93640 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e218;
void __cdecl FUN_00d895d0();

void __cdecl FUN_00c93640()
{
    DAT_00f4e218.Setting::Setting();
    atexit(FUN_00d895d0);
}
}

// @f3 0x00c936a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c936a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e224;
void __cdecl FUN_00d895e0();

void __cdecl FUN_00c936a0()
{
    DAT_00f4e224.Setting::Setting();
    atexit(FUN_00d895e0);
}
}

// @f3 0x00c93700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e230;
void __cdecl FUN_00d895f0();

void __cdecl FUN_00c93700()
{
    DAT_00f4e230.Setting::Setting();
    atexit(FUN_00d895f0);
}
}

// @f3 0x00c93760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93760 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e23c;
void __cdecl FUN_00d89600();

void __cdecl FUN_00c93760()
{
    DAT_00f4e23c.Setting::Setting();
    atexit(FUN_00d89600);
}
}

// @f3 0x00c937c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c937c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e248;
void __cdecl FUN_00d89610();

void __cdecl FUN_00c937c0()
{
    DAT_00f4e248.Setting::Setting();
    atexit(FUN_00d89610);
}
}

// @f3 0x00c93820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93820 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e254;
void __cdecl FUN_00d89620();

void __cdecl FUN_00c93820()
{
    DAT_00f4e254.Setting::Setting();
    atexit(FUN_00d89620);
}
}

// @f3 0x00c93880 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e260;
void __cdecl FUN_00d89630();

void __cdecl FUN_00c93880()
{
    DAT_00f4e260.Setting::Setting();
    atexit(FUN_00d89630);
}
}

// @f3 0x00c938e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c938e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e26c;
void __cdecl FUN_00d89640();

void __cdecl FUN_00c938e0()
{
    DAT_00f4e26c.Setting::Setting();
    atexit(FUN_00d89640);
}
}

// @f3 0x00c93940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93940 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e278;
void __cdecl FUN_00d89650();

void __cdecl FUN_00c93940()
{
    DAT_00f4e278.Setting::Setting();
    atexit(FUN_00d89650);
}
}

// @f3 0x00c939a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c939a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e284;
void __cdecl FUN_00d89660();

void __cdecl FUN_00c939a0()
{
    DAT_00f4e284.Setting::Setting();
    atexit(FUN_00d89660);
}
}

// @f3 0x00c93a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93a00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e290;
void __cdecl FUN_00d89670();

void __cdecl FUN_00c93a00()
{
    DAT_00f4e290.Setting::Setting();
    atexit(FUN_00d89670);
}
}

// @f3 0x00c93a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93a60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e29c;
void __cdecl FUN_00d89680();

void __cdecl FUN_00c93a60()
{
    DAT_00f4e29c.Setting::Setting();
    atexit(FUN_00d89680);
}
}

// @f3 0x00c93ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2a8;
void __cdecl FUN_00d89690();

void __cdecl FUN_00c93ac0()
{
    DAT_00f4e2a8.Setting::Setting();
    atexit(FUN_00d89690);
}
}

// @f3 0x00c93b20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2b4;
void __cdecl FUN_00d896a0();

void __cdecl FUN_00c93b20()
{
    DAT_00f4e2b4.Setting::Setting();
    atexit(FUN_00d896a0);
}
}

// @f3 0x00c93b80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2c0;
void __cdecl FUN_00d896b0();

void __cdecl FUN_00c93b80()
{
    DAT_00f4e2c0.Setting::Setting();
    atexit(FUN_00d896b0);
}
}

// @f3 0x00c93be0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2cc;
void __cdecl FUN_00d896c0();

void __cdecl FUN_00c93be0()
{
    DAT_00f4e2cc.Setting::Setting();
    atexit(FUN_00d896c0);
}
}

// @f3 0x00c93c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93c40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2d8;
void __cdecl FUN_00d896d0();

void __cdecl FUN_00c93c40()
{
    DAT_00f4e2d8.Setting::Setting();
    atexit(FUN_00d896d0);
}
}

// @f3 0x00c93ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93ca0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2e4;
void __cdecl FUN_00d896e0();

void __cdecl FUN_00c93ca0()
{
    DAT_00f4e2e4.Setting::Setting();
    atexit(FUN_00d896e0);
}
}

// @f3 0x00c93d00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93d00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2f0;
void __cdecl FUN_00d896f0();

void __cdecl FUN_00c93d00()
{
    DAT_00f4e2f0.Setting::Setting();
    atexit(FUN_00d896f0);
}
}

// @f3 0x00c93d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93d60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e2fc;
void __cdecl FUN_00d89700();

void __cdecl FUN_00c93d60()
{
    DAT_00f4e2fc.Setting::Setting();
    atexit(FUN_00d89700);
}
}

// @f3 0x00c93dc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93dc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e308;
void __cdecl FUN_00d89710();

void __cdecl FUN_00c93dc0()
{
    DAT_00f4e308.Setting::Setting();
    atexit(FUN_00d89710);
}
}

// @f3 0x00c93e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93e20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e314;
void __cdecl FUN_00d89720();

void __cdecl FUN_00c93e20()
{
    DAT_00f4e314.Setting::Setting();
    atexit(FUN_00d89720);
}
}

// @f3 0x00c93e80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93e80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e320;
void __cdecl FUN_00d89730();

void __cdecl FUN_00c93e80()
{
    DAT_00f4e320.Setting::Setting();
    atexit(FUN_00d89730);
}
}

// @f3 0x00c93ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93ee0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e32c;
void __cdecl FUN_00d89740();

void __cdecl FUN_00c93ee0()
{
    DAT_00f4e32c.Setting::Setting();
    atexit(FUN_00d89740);
}
}

// @f3 0x00c93f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93f40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e338;
void __cdecl FUN_00d89750();

void __cdecl FUN_00c93f40()
{
    DAT_00f4e338.Setting::Setting();
    atexit(FUN_00d89750);
}
}

// @f3 0x00c93fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c93fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e344;
void __cdecl FUN_00d89760();

void __cdecl FUN_00c93fa0()
{
    DAT_00f4e344.Setting::Setting();
    atexit(FUN_00d89760);
}
}

// @f3 0x00c94000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94000 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e350;
void __cdecl FUN_00d89770();

void __cdecl FUN_00c94000()
{
    DAT_00f4e350.Setting::Setting();
    atexit(FUN_00d89770);
}
}

// @f3 0x00c94060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94060 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e35c;
void __cdecl FUN_00d89780();

void __cdecl FUN_00c94060()
{
    DAT_00f4e35c.Setting::Setting();
    atexit(FUN_00d89780);
}
}

// @f3 0x00c940c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c940c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e368;
void __cdecl FUN_00d89790();

void __cdecl FUN_00c940c0()
{
    DAT_00f4e368.Setting::Setting();
    atexit(FUN_00d89790);
}
}

// @f3 0x00c94120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94120 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e374;
void __cdecl FUN_00d897a0();

void __cdecl FUN_00c94120()
{
    DAT_00f4e374.Setting::Setting();
    atexit(FUN_00d897a0);
}
}

// @f3 0x00c94180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94180 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e380;
void __cdecl FUN_00d897b0();

void __cdecl FUN_00c94180()
{
    DAT_00f4e380.Setting::Setting();
    atexit(FUN_00d897b0);
}
}

// @f3 0x00c941e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c941e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e38c;
void __cdecl FUN_00d897c0();

void __cdecl FUN_00c941e0()
{
    DAT_00f4e38c.Setting::Setting();
    atexit(FUN_00d897c0);
}
}

// @f3 0x00c94240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94240 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e398;
void __cdecl FUN_00d897d0();

void __cdecl FUN_00c94240()
{
    DAT_00f4e398.Setting::Setting();
    atexit(FUN_00d897d0);
}
}

// @f3 0x00c942a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c942a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3a4;
void __cdecl FUN_00d897e0();

void __cdecl FUN_00c942a0()
{
    DAT_00f4e3a4.Setting::Setting();
    atexit(FUN_00d897e0);
}
}

// @f3 0x00c94300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94300 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3b0;
void __cdecl FUN_00d897f0();

void __cdecl FUN_00c94300()
{
    DAT_00f4e3b0.Setting::Setting();
    atexit(FUN_00d897f0);
}
}

// @f3 0x00c94360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94360 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3bc;
void __cdecl FUN_00d89800();

void __cdecl FUN_00c94360()
{
    DAT_00f4e3bc.Setting::Setting();
    atexit(FUN_00d89800);
}
}

// @f3 0x00c943c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c943c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3c8;
void __cdecl FUN_00d89810();

void __cdecl FUN_00c943c0()
{
    DAT_00f4e3c8.Setting::Setting();
    atexit(FUN_00d89810);
}
}

// @f3 0x00c94420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3d4;
void __cdecl FUN_00d89820();

void __cdecl FUN_00c94420()
{
    DAT_00f4e3d4.Setting::Setting();
    atexit(FUN_00d89820);
}
}

// @f3 0x00c94480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3e0;
void __cdecl FUN_00d89830();

void __cdecl FUN_00c94480()
{
    DAT_00f4e3e0.Setting::Setting();
    atexit(FUN_00d89830);
}
}

// @f3 0x00c944e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c944e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3ec;
void __cdecl FUN_00d89840();

void __cdecl FUN_00c944e0()
{
    DAT_00f4e3ec.Setting::Setting();
    atexit(FUN_00d89840);
}
}

// @f3 0x00c94540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94540 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e3f8;
void __cdecl FUN_00d89850();

void __cdecl FUN_00c94540()
{
    DAT_00f4e3f8.Setting::Setting();
    atexit(FUN_00d89850);
}
}

// @f3 0x00c945a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c945a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e404;
void __cdecl FUN_00d89860();

void __cdecl FUN_00c945a0()
{
    DAT_00f4e404.Setting::Setting();
    atexit(FUN_00d89860);
}
}

// @f3 0x00c94600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94600 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e410;
void __cdecl FUN_00d89870();

void __cdecl FUN_00c94600()
{
    DAT_00f4e410.Setting::Setting();
    atexit(FUN_00d89870);
}
}

// @f3 0x00c94660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94660 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e41c;
void __cdecl FUN_00d89880();

void __cdecl FUN_00c94660()
{
    DAT_00f4e41c.Setting::Setting();
    atexit(FUN_00d89880);
}
}

// @f3 0x00c946c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c946c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e428;
void __cdecl FUN_00d89890();

void __cdecl FUN_00c946c0()
{
    DAT_00f4e428.Setting::Setting();
    atexit(FUN_00d89890);
}
}

// @f3 0x00c94720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e434;
void __cdecl FUN_00d898a0();

void __cdecl FUN_00c94720()
{
    DAT_00f4e434.Setting::Setting();
    atexit(FUN_00d898a0);
}
}

// @f3 0x00c94780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e440;
void __cdecl FUN_00d898b0();

void __cdecl FUN_00c94780()
{
    DAT_00f4e440.Setting::Setting();
    atexit(FUN_00d898b0);
}
}

// @f3 0x00c947e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c947e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e44c;
void __cdecl FUN_00d898c0();

void __cdecl FUN_00c947e0()
{
    DAT_00f4e44c.Setting::Setting();
    atexit(FUN_00d898c0);
}
}

// @f3 0x00c94840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e458;
void __cdecl FUN_00d898d0();

void __cdecl FUN_00c94840()
{
    DAT_00f4e458.Setting::Setting();
    atexit(FUN_00d898d0);
}
}

// @f3 0x00c948a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c948a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e464;
void __cdecl FUN_00d898e0();

void __cdecl FUN_00c948a0()
{
    DAT_00f4e464.Setting::Setting();
    atexit(FUN_00d898e0);
}
}

// @f3 0x00c94900 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94900 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e470;
void __cdecl FUN_00d898f0();

void __cdecl FUN_00c94900()
{
    DAT_00f4e470.Setting::Setting();
    atexit(FUN_00d898f0);
}
}

// @f3 0x00c94960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94960 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e47c;
void __cdecl FUN_00d89900();

void __cdecl FUN_00c94960()
{
    DAT_00f4e47c.Setting::Setting();
    atexit(FUN_00d89900);
}
}

// @f3 0x00c949c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c949c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e488;
void __cdecl FUN_00d89910();

void __cdecl FUN_00c949c0()
{
    DAT_00f4e488.Setting::Setting();
    atexit(FUN_00d89910);
}
}

// @f3 0x00c94a20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94a20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e494;
void __cdecl FUN_00d89920();

void __cdecl FUN_00c94a20()
{
    DAT_00f4e494.Setting::Setting();
    atexit(FUN_00d89920);
}
}

// @f3 0x00c94a80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94a80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e4a0;
void __cdecl FUN_00d89930();

void __cdecl FUN_00c94a80()
{
    DAT_00f4e4a0.Setting::Setting();
    atexit(FUN_00d89930);
}
}

// @f3 0x00c94ae0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94ae0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e4ac;
void __cdecl FUN_00d89940();

void __cdecl FUN_00c94ae0()
{
    DAT_00f4e4ac.Setting::Setting();
    atexit(FUN_00d89940);
}
}

// @f3 0x00c94f80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c94f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e568;
void __cdecl FUN_00d89970();

void __cdecl FUN_00c94f80()
{
    DAT_00f4e568.Setting::Setting();
    atexit(FUN_00d89970);
}
}

// @f3 0x00c95030 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95030 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e580;
void __cdecl FUN_00d89980();

void __cdecl FUN_00c95030()
{
    DAT_00f4e580.Setting::Setting();
    atexit(FUN_00d89980);
}
}

// @f3 0x00c95940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95940 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e8e4;
void __cdecl FUN_00d89a50();

void __cdecl FUN_00c95940()
{
    DAT_00f4e8e4.Setting::Setting();
    atexit(FUN_00d89a50);
}
}

// @f3 0x00c959a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c959a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e8f0;
void __cdecl FUN_00d89a60();

void __cdecl FUN_00c959a0()
{
    DAT_00f4e8f0.Setting::Setting();
    atexit(FUN_00d89a60);
}
}

// @f3 0x00c95a00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95a00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e8fc;
void __cdecl FUN_00d89a70();

void __cdecl FUN_00c95a00()
{
    DAT_00f4e8fc.Setting::Setting();
    atexit(FUN_00d89a70);
}
}

// @f3 0x00c95a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95a60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e908;
void __cdecl FUN_00d89a80();

void __cdecl FUN_00c95a60()
{
    DAT_00f4e908.Setting::Setting();
    atexit(FUN_00d89a80);
}
}

// @f3 0x00c95ac0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95ac0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e914;
void __cdecl FUN_00d89a90();

void __cdecl FUN_00c95ac0()
{
    DAT_00f4e914.Setting::Setting();
    atexit(FUN_00d89a90);
}
}

// @f3 0x00c95b20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e920;
void __cdecl FUN_00d89aa0();

void __cdecl FUN_00c95b20()
{
    DAT_00f4e920.Setting::Setting();
    atexit(FUN_00d89aa0);
}
}

// @f3 0x00c95b80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e92c;
void __cdecl FUN_00d89ab0();

void __cdecl FUN_00c95b80()
{
    DAT_00f4e92c.Setting::Setting();
    atexit(FUN_00d89ab0);
}
}

// @f3 0x00c95be0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c95be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e938;
void __cdecl FUN_00d89ac0();

void __cdecl FUN_00c95be0()
{
    DAT_00f4e938.Setting::Setting();
    atexit(FUN_00d89ac0);
}
}

// @f3 0x00c961b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c961b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e9dc;
void __cdecl FUN_00d89ae0();

void __cdecl FUN_00c961b0()
{
    DAT_00f4e9dc.Setting::Setting();
    atexit(FUN_00d89ae0);
}
}

// @f3 0x00c96210 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c96210 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4e9e8;
void __cdecl FUN_00d89af0();

void __cdecl FUN_00c96210()
{
    DAT_00f4e9e8.Setting::Setting();
    atexit(FUN_00d89af0);
}
}

// @f3 0x00c96720 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c96720 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4ec04;
void __cdecl FUN_00d89b30();

void __cdecl FUN_00c96720()
{
    DAT_00f4ec04.Setting::Setting();
    atexit(FUN_00d89b30);
}
}

// @f3 0x00c973c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c973c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4fa98;
void __cdecl FUN_00d89d60();

void __cdecl FUN_00c973c0()
{
    DAT_00f4fa98.Setting::Setting();
    atexit(FUN_00d89d60);
}
}

// @f3 0x00c97420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c97420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4faa4;
void __cdecl FUN_00d89d70();

void __cdecl FUN_00c97420()
{
    DAT_00f4faa4.Setting::Setting();
    atexit(FUN_00d89d70);
}
}

// @f3 0x00c97480 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c97480 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f4fab0;
void __cdecl FUN_00d89d80();

void __cdecl FUN_00c97480()
{
    DAT_00f4fab0.Setting::Setting();
    atexit(FUN_00d89d80);
}
}

// @f3 0x00c977a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c977a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f50124;
void __cdecl FUN_00d89de0();

void __cdecl FUN_00c977a0()
{
    DAT_00f50124.Setting::Setting();
    atexit(FUN_00d89de0);
}
}

// @f3 0x00c97800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c97800 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f50130;
void __cdecl FUN_00d89df0();

void __cdecl FUN_00c97800()
{
    DAT_00f50130.Setting::Setting();
    atexit(FUN_00d89df0);
}
}

// @f3 0x00c98290 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c98290 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f50850;
void __cdecl FUN_00d89f20();

void __cdecl FUN_00c98290()
{
    DAT_00f50850.Setting::Setting();
    atexit(FUN_00d89f20);
}
}

// @f3 0x00c982f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c982f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5085c;
void __cdecl FUN_00d89f30();

void __cdecl FUN_00c982f0()
{
    DAT_00f5085c.Setting::Setting();
    atexit(FUN_00d89f30);
}
}

// @f3 0x00c98350 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c98350 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f50868;
void __cdecl FUN_00d89f40();

void __cdecl FUN_00c98350()
{
    DAT_00f50868.Setting::Setting();
    atexit(FUN_00d89f40);
}
}

// @f3 0x00c98450 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c98450 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f50a50;
void __cdecl FUN_00d89f50();

void __cdecl FUN_00c98450()
{
    DAT_00f50a50.Setting::Setting();
    atexit(FUN_00d89f50);
}
}

// @f3 0x00c991a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c991a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5a478;
void __cdecl FUN_00d8a000();

void __cdecl FUN_00c991a0()
{
    DAT_00f5a478.Setting::Setting();
    atexit(FUN_00d8a000);
}
}

// @f3 0x00c99200 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c99200 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5a484;
void __cdecl FUN_00d8a010();

void __cdecl FUN_00c99200()
{
    DAT_00f5a484.Setting::Setting();
    atexit(FUN_00d8a010);
}
}

// @f3 0x00c99260 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c99260 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5a490;
void __cdecl FUN_00d8a020();

void __cdecl FUN_00c99260()
{
    DAT_00f5a490.Setting::Setting();
    atexit(FUN_00d8a020);
}
}

// @f3 0x00c9a460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9a460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5c7f4;
void __cdecl FUN_00d8a030();

void __cdecl FUN_00c9a460()
{
    DAT_00f5c7f4.Setting::Setting();
    atexit(FUN_00d8a030);
}
}

// @f3 0x00c9a4c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9a4c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5c800;
void __cdecl FUN_00d8a040();

void __cdecl FUN_00c9a4c0()
{
    DAT_00f5c800.Setting::Setting();
    atexit(FUN_00d8a040);
}
}

// @f3 0x00c9a520 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9a520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5c80c;
void __cdecl FUN_00d8a050();

void __cdecl FUN_00c9a520()
{
    DAT_00f5c80c.Setting::Setting();
    atexit(FUN_00d8a050);
}
}

// @f3 0x00c9a580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9a580 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5c818;
void __cdecl FUN_00d8a060();

void __cdecl FUN_00c9a580()
{
    DAT_00f5c818.Setting::Setting();
    atexit(FUN_00d8a060);
}
}

// @f3 0x00c9aba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9aba0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cac8;
void __cdecl FUN_00d8a0b0();

void __cdecl FUN_00c9aba0()
{
    DAT_00f5cac8.Setting::Setting();
    atexit(FUN_00d8a0b0);
}
}

// @f3 0x00c9ac00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ac00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cad4;
void __cdecl FUN_00d8a0c0();

void __cdecl FUN_00c9ac00()
{
    DAT_00f5cad4.Setting::Setting();
    atexit(FUN_00d8a0c0);
}
}

// @f3 0x00c9ac60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ac60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cae0;
void __cdecl FUN_00d8a0d0();

void __cdecl FUN_00c9ac60()
{
    DAT_00f5cae0.Setting::Setting();
    atexit(FUN_00d8a0d0);
}
}

// @f3 0x00c9acc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9acc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5caec;
void __cdecl FUN_00d8a0e0();

void __cdecl FUN_00c9acc0()
{
    DAT_00f5caec.Setting::Setting();
    atexit(FUN_00d8a0e0);
}
}

// @f3 0x00c9b420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b420 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cd18;
void __cdecl FUN_00d8a150();

void __cdecl FUN_00c9b420()
{
    DAT_00f5cd18.Setting::Setting();
    atexit(FUN_00d8a150);
}
}

// @f3 0x00c9b6d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b6d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cd70;
void __cdecl FUN_00d8a1a0();

void __cdecl FUN_00c9b6d0()
{
    DAT_00f5cd70.Setting::Setting();
    atexit(FUN_00d8a1a0);
}
}

// @f3 0x00c9b780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b780 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cda4;
void __cdecl FUN_00d8a1b0();

void __cdecl FUN_00c9b780()
{
    DAT_00f5cda4.Setting::Setting();
    atexit(FUN_00d8a1b0);
}
}

// @f3 0x00c9b7e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b7e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cdb0;
void __cdecl FUN_00d8a1c0();

void __cdecl FUN_00c9b7e0()
{
    DAT_00f5cdb0.Setting::Setting();
    atexit(FUN_00d8a1c0);
}
}

// @f3 0x00c9b840 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b840 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cdbc;
void __cdecl FUN_00d8a1d0();

void __cdecl FUN_00c9b840()
{
    DAT_00f5cdbc.Setting::Setting();
    atexit(FUN_00d8a1d0);
}
}

// @f3 0x00c9b8a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9b8a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5cdc8;
void __cdecl FUN_00d8a1e0();

void __cdecl FUN_00c9b8a0()
{
    DAT_00f5cdc8.Setting::Setting();
    atexit(FUN_00d8a1e0);
}
}

// @f3 0x00c9bc80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9bc80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d1fc;
void __cdecl FUN_00d8a2a0();

void __cdecl FUN_00c9bc80()
{
    DAT_00f5d1fc.Setting::Setting();
    atexit(FUN_00d8a2a0);
}
}

// @f3 0x00c9bce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9bce0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d208;
void __cdecl FUN_00d8a2b0();

void __cdecl FUN_00c9bce0()
{
    DAT_00f5d208.Setting::Setting();
    atexit(FUN_00d8a2b0);
}
}

// @f3 0x00c9ea40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ea40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e008;
void __cdecl FUN_00d8a8e0();

void __cdecl FUN_00c9ea40()
{
    DAT_00f5e008.Setting::Setting();
    atexit(FUN_00d8a8e0);
}
}

// @f3 0x00c9bd40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9bd40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d214;
void __cdecl FUN_00d8a2c0();

void __cdecl FUN_00c9bd40()
{
    DAT_00f5d214.Setting::Setting();
    atexit(FUN_00d8a2c0);
}
}

// @f3 0x00c9bda0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9bda0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d220;
void __cdecl FUN_00d8a2d0();

void __cdecl FUN_00c9bda0()
{
    DAT_00f5d220.Setting::Setting();
    atexit(FUN_00d8a2d0);
}
}

// @f3 0x00c9be00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9be00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d22c;
void __cdecl FUN_00d8a2e0();

void __cdecl FUN_00c9be00()
{
    DAT_00f5d22c.Setting::Setting();
    atexit(FUN_00d8a2e0);
}
}

// @f3 0x00c9c640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9c640 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d7ec;
void __cdecl FUN_00d8a360();

void __cdecl FUN_00c9c640()
{
    DAT_00f5d7ec.Setting::Setting();
    atexit(FUN_00d8a360);
}
}

// @f3 0x00c9e740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e740 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfa8;
void __cdecl FUN_00d8a860();

void __cdecl FUN_00c9e740()
{
    DAT_00f5dfa8.Setting::Setting();
    atexit(FUN_00d8a860);
}
}

// @f3 0x00c9c6a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9c6a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5d7f8;
void __cdecl FUN_00d8a370();

void __cdecl FUN_00c9c6a0()
{
    DAT_00f5d7f8.Setting::Setting();
    atexit(FUN_00d8a370);
}
}

// @f3 0x00c9de70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9de70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dec4;
void __cdecl FUN_00d8a7b0();

void __cdecl FUN_00c9de70()
{
    DAT_00f5dec4.Setting::Setting();
    atexit(FUN_00d8a7b0);
}
}

// @f3 0x00c9e3e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e3e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df3c;
void __cdecl FUN_00d8a7d0();

void __cdecl FUN_00c9e3e0()
{
    DAT_00f5df3c.Setting::Setting();
    atexit(FUN_00d8a7d0);
}
}

// @f3 0x00c9e440 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e440 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df48;
void __cdecl FUN_00d8a7e0();

void __cdecl FUN_00c9e440()
{
    DAT_00f5df48.Setting::Setting();
    atexit(FUN_00d8a7e0);
}
}

// @f3 0x00c9e4a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e4a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df54;
void __cdecl FUN_00d8a7f0();

void __cdecl FUN_00c9e4a0()
{
    DAT_00f5df54.Setting::Setting();
    atexit(FUN_00d8a7f0);
}
}

// @f3 0x00c9e500 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e500 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df60;
void __cdecl FUN_00d8a800();

void __cdecl FUN_00c9e500()
{
    DAT_00f5df60.Setting::Setting();
    atexit(FUN_00d8a800);
}
}

// @f3 0x00c9e560 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e560 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df6c;
void __cdecl FUN_00d8a810();

void __cdecl FUN_00c9e560()
{
    DAT_00f5df6c.Setting::Setting();
    atexit(FUN_00d8a810);
}
}

// @f3 0x00c9e5c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e5c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df78;
void __cdecl FUN_00d8a820();

void __cdecl FUN_00c9e5c0()
{
    DAT_00f5df78.Setting::Setting();
    atexit(FUN_00d8a820);
}
}

// @f3 0x00c9e620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df84;
void __cdecl FUN_00d8a830();

void __cdecl FUN_00c9e620()
{
    DAT_00f5df84.Setting::Setting();
    atexit(FUN_00d8a830);
}
}

// @f3 0x00c9e680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e680 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df90;
void __cdecl FUN_00d8a840();

void __cdecl FUN_00c9e680()
{
    DAT_00f5df90.Setting::Setting();
    atexit(FUN_00d8a840);
}
}

// @f3 0x00c9e6e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e6e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5df9c;
void __cdecl FUN_00d8a850();

void __cdecl FUN_00c9e6e0()
{
    DAT_00f5df9c.Setting::Setting();
    atexit(FUN_00d8a850);
}
}

// @f3 0x00c9e7a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e7a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfb4;
void __cdecl FUN_00d8a870();

void __cdecl FUN_00c9e7a0()
{
    DAT_00f5dfb4.Setting::Setting();
    atexit(FUN_00d8a870);
}
}

// @f3 0x00c9e800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e800 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfc0;
void __cdecl FUN_00d8a880();

void __cdecl FUN_00c9e800()
{
    DAT_00f5dfc0.Setting::Setting();
    atexit(FUN_00d8a880);
}
}

// @f3 0x00c9e860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e860 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfcc;
void __cdecl FUN_00d8a890();

void __cdecl FUN_00c9e860()
{
    DAT_00f5dfcc.Setting::Setting();
    atexit(FUN_00d8a890);
}
}

// @f3 0x00c9e8c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e8c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfd8;
void __cdecl FUN_00d8a8a0();

void __cdecl FUN_00c9e8c0()
{
    DAT_00f5dfd8.Setting::Setting();
    atexit(FUN_00d8a8a0);
}
}

// @f3 0x00c9e920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e920 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dfe4;
void __cdecl FUN_00d8a8b0();

void __cdecl FUN_00c9e920()
{
    DAT_00f5dfe4.Setting::Setting();
    atexit(FUN_00d8a8b0);
}
}

// @f3 0x00c9e980 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dff0;
void __cdecl FUN_00d8a8c0();

void __cdecl FUN_00c9e980()
{
    DAT_00f5dff0.Setting::Setting();
    atexit(FUN_00d8a8c0);
}
}

// @f3 0x00c9e9e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9e9e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5dffc;
void __cdecl FUN_00d8a8d0();

void __cdecl FUN_00c9e9e0()
{
    DAT_00f5dffc.Setting::Setting();
    atexit(FUN_00d8a8d0);
}
}

// @f3 0x00c9eaa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9eaa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e014;
void __cdecl FUN_00d8a8f0();

void __cdecl FUN_00c9eaa0()
{
    DAT_00f5e014.Setting::Setting();
    atexit(FUN_00d8a8f0);
}
}

// @f3 0x00c9eb60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9eb60 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e02c;
void __cdecl FUN_00d8a910();

void __cdecl FUN_00c9eb60()
{
    DAT_00f5e02c.Setting::Setting();
    atexit(FUN_00d8a910);
}
}

// @f3 0x00c9efb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9efb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e088;
void __cdecl FUN_00d8a920();

void __cdecl FUN_00c9efb0()
{
    DAT_00f5e088.Setting::Setting();
    atexit(FUN_00d8a920);
}
}

// @f3 0x00c9fc10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fc10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e280;
void __cdecl FUN_00d8aab0();

void __cdecl FUN_00c9fc10()
{
    DAT_00f5e280.Setting::Setting();
    atexit(FUN_00d8aab0);
}
}

// @f3 0x00c9f010 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f010 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e094;
void __cdecl FUN_00d8a930();

void __cdecl FUN_00c9f010()
{
    DAT_00f5e094.Setting::Setting();
    atexit(FUN_00d8a930);
}
}

// @f3 0x00c9f070 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f070 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0a0;
void __cdecl FUN_00d8a940();

void __cdecl FUN_00c9f070()
{
    DAT_00f5e0a0.Setting::Setting();
    atexit(FUN_00d8a940);
}
}

// @f3 0x00c9f0d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f0d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0ac;
void __cdecl FUN_00d8a950();

void __cdecl FUN_00c9f0d0()
{
    DAT_00f5e0ac.Setting::Setting();
    atexit(FUN_00d8a950);
}
}

// @f3 0x00c9f2e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f2e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0d8;
void __cdecl FUN_00d8a980();

void __cdecl FUN_00c9f2e0()
{
    DAT_00f5e0d8.Setting::Setting();
    atexit(FUN_00d8a980);
}
}

// @f3 0x00c9f340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f340 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0e4;
void __cdecl FUN_00d8a990();

void __cdecl FUN_00c9f340()
{
    DAT_00f5e0e4.Setting::Setting();
    atexit(FUN_00d8a990);
}
}

// @f3 0x00c9f3a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f3a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0f0;
void __cdecl FUN_00d8a9a0();

void __cdecl FUN_00c9f3a0()
{
    DAT_00f5e0f0.Setting::Setting();
    atexit(FUN_00d8a9a0);
}
}

// @f3 0x00c9f400 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e0fc;
void __cdecl FUN_00d8a9b0();

void __cdecl FUN_00c9f400()
{
    DAT_00f5e0fc.Setting::Setting();
    atexit(FUN_00d8a9b0);
}
}

// @f3 0x00c9f460 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e108;
void __cdecl FUN_00d8a9c0();

void __cdecl FUN_00c9f460()
{
    DAT_00f5e108.Setting::Setting();
    atexit(FUN_00d8a9c0);
}
}

// @f3 0x00c9f4c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f4c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e114;
void __cdecl FUN_00d8a9d0();

void __cdecl FUN_00c9f4c0()
{
    DAT_00f5e114.Setting::Setting();
    atexit(FUN_00d8a9d0);
}
}

// @f3 0x00c9f730 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f730 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e1e4;
void __cdecl FUN_00d8a9e0();

void __cdecl FUN_00c9f730()
{
    DAT_00f5e1e4.Setting::Setting();
    atexit(FUN_00d8a9e0);
}
}

// @f3 0x00c9f790 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f790 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e1f0;
void __cdecl FUN_00d8a9f0();

void __cdecl FUN_00c9f790()
{
    DAT_00f5e1f0.Setting::Setting();
    atexit(FUN_00d8a9f0);
}
}

// @f3 0x00c9f7f0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f7f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e1fc;
void __cdecl FUN_00d8aa00();

void __cdecl FUN_00c9f7f0()
{
    DAT_00f5e1fc.Setting::Setting();
    atexit(FUN_00d8aa00);
}
}

// @f3 0x00c9f8b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f8b0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e214;
void __cdecl FUN_00d8aa20();

void __cdecl FUN_00c9f8b0()
{
    DAT_00f5e214.Setting::Setting();
    atexit(FUN_00d8aa20);
}
}

// @f3 0x00c9f910 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f910 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e220;
void __cdecl FUN_00d8aa30();

void __cdecl FUN_00c9f910()
{
    DAT_00f5e220.Setting::Setting();
    atexit(FUN_00d8aa30);
}
}

// @f3 0x00c9f970 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f970 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e22c;
void __cdecl FUN_00d8aa40();

void __cdecl FUN_00c9f970()
{
    DAT_00f5e22c.Setting::Setting();
    atexit(FUN_00d8aa40);
}
}

// @f3 0x00c9f9d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9f9d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e238;
void __cdecl FUN_00d8aa50();

void __cdecl FUN_00c9f9d0()
{
    DAT_00f5e238.Setting::Setting();
    atexit(FUN_00d8aa50);
}
}

// @f3 0x00c9fa30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fa30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e244;
void __cdecl FUN_00d8aa60();

void __cdecl FUN_00c9fa30()
{
    DAT_00f5e244.Setting::Setting();
    atexit(FUN_00d8aa60);
}
}

// @f3 0x00c9fa90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fa90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e250;
void __cdecl FUN_00d8aa70();

void __cdecl FUN_00c9fa90()
{
    DAT_00f5e250.Setting::Setting();
    atexit(FUN_00d8aa70);
}
}

// @f3 0x00c9faf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9faf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e25c;
void __cdecl FUN_00d8aa80();

void __cdecl FUN_00c9faf0()
{
    DAT_00f5e25c.Setting::Setting();
    atexit(FUN_00d8aa80);
}
}

// @f3 0x00c9fb50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fb50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e268;
void __cdecl FUN_00d8aa90();

void __cdecl FUN_00c9fb50()
{
    DAT_00f5e268.Setting::Setting();
    atexit(FUN_00d8aa90);
}
}

// @f3 0x00c9fbb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fbb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e274;
void __cdecl FUN_00d8aaa0();

void __cdecl FUN_00c9fbb0()
{
    DAT_00f5e274.Setting::Setting();
    atexit(FUN_00d8aaa0);
}
}

// @f3 0x00c9fc70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fc70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e28c;
void __cdecl FUN_00d8aac0();

void __cdecl FUN_00c9fc70()
{
    DAT_00f5e28c.Setting::Setting();
    atexit(FUN_00d8aac0);
}
}

// @f3 0x00c9fcd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fcd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e298;
void __cdecl FUN_00d8aad0();

void __cdecl FUN_00c9fcd0()
{
    DAT_00f5e298.Setting::Setting();
    atexit(FUN_00d8aad0);
}
}

// @f3 0x00c9fd30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fd30 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2a4;
void __cdecl FUN_00d8aae0();

void __cdecl FUN_00c9fd30()
{
    DAT_00f5e2a4.Setting::Setting();
    atexit(FUN_00d8aae0);
}
}

// @f3 0x00c9fd90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fd90 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2b0;
void __cdecl FUN_00d8aaf0();

void __cdecl FUN_00c9fd90()
{
    DAT_00f5e2b0.Setting::Setting();
    atexit(FUN_00d8aaf0);
}
}

// @f3 0x00c9fdf0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fdf0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2bc;
void __cdecl FUN_00d8ab00();

void __cdecl FUN_00c9fdf0()
{
    DAT_00f5e2bc.Setting::Setting();
    atexit(FUN_00d8ab00);
}
}

// @f3 0x00c9fe50 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9fe50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2c8;
void __cdecl FUN_00d8ab10();

void __cdecl FUN_00c9fe50()
{
    DAT_00f5e2c8.Setting::Setting();
    atexit(FUN_00d8ab10);
}
}

// @f3 0x00c9feb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9feb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2d4;
void __cdecl FUN_00d8ab20();

void __cdecl FUN_00c9feb0()
{
    DAT_00f5e2d4.Setting::Setting();
    atexit(FUN_00d8ab20);
}
}

// @f3 0x00c9ff10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ff10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2e0;
void __cdecl FUN_00d8ab30();

void __cdecl FUN_00c9ff10()
{
    DAT_00f5e2e0.Setting::Setting();
    atexit(FUN_00d8ab30);
}
}

// @f3 0x00c9ff70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ff70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2ec;
void __cdecl FUN_00d8ab40();

void __cdecl FUN_00c9ff70()
{
    DAT_00f5e2ec.Setting::Setting();
    atexit(FUN_00d8ab40);
}
}

// @f3 0x00c9ffd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9ffd0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e2f8;
void __cdecl FUN_00d8ab50();

void __cdecl FUN_00c9ffd0()
{
    DAT_00f5e2f8.Setting::Setting();
    atexit(FUN_00d8ab50);
}
}

// @f3 0x00c954a0 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_010707b4;
namespace f3m_00c954a0 {
struct FUN_0043b7f0_Obj {
    void __thiscall FUN_0043b7f0(const char* text, int value);
};
extern void __cdecl FUN_00d899e0();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'ATTENUATION_SETTINGS::eQuadraticMethod'' | TESLight.obj | fnv360_0822_debug, ustr, high
void FUN_00c954a0() {
    DAT_010707b4.FUN_0043b7f0("uQuadraticMethod:bLightAttenuation", 2);
    FUN_00c00d1f(FUN_00d899e0);
}
}   // namespace f3m_00c954a0

// @f3 0x00c85c60 (community match, verified in this file)
namespace f3m_00c85c60 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106cccc;
void __cdecl FUN_00d86c40();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iInteriorBufferSize'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85c60()
{
    f3m_00c85c60::DAT_0106cccc.FUN_0043b7f0("uInterior Cell Buffer:General", 3u);
    atexit(f3m_00c85c60::FUN_00d86c40);
}

// @f3 0x00c85eb0 (community match, verified in this file)
namespace f3m_00c85eb0 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106cb28;
void __cdecl FUN_00d86d30();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iEntityBatchRemoveRate'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85eb0()
{
    f3m_00c85eb0::DAT_0106cb28.FUN_0043b7f0("iEntityBatchRemoveRate:HAVOK", 100);
    atexit(f3m_00c85eb0::FUN_00d86d30);
}

// @f3 0x00c8a930 (community match, verified in this file)
namespace f3m_00c8a930 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106df70;
void __cdecl FUN_00d877e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BGSDecalManager::iMaxDecalsPerFrame'' | BGSDecalManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8a930()
{
    f3m_00c8a930::DAT_0106df70.FUN_00491570("iMaxDecalsPerFrame:Display", 10);
    atexit(f3m_00c8a930::FUN_00d877e0);
}

// @f3 0x00c8a950 (community match, verified in this file)
namespace f3m_00c8a950 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106df48;
void __cdecl FUN_00d877f0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BGSDecalManager::iMaxSkinDecalsPerFrame'' | BGSDecalManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8a950()
{
    f3m_00c8a950::DAT_0106df48.FUN_00491570("iMaxSkinDecalsPerFrame:Display", 3);
    atexit(f3m_00c8a950::FUN_00d877f0);
}

// @f3 0x00c8a9b0 (community match, verified in this file)
namespace f3m_00c8a9b0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106df7c;
void __cdecl FUN_00d87820();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BGSDecalManager::iMaxSkinDecalPerActor'' | BGSDecalManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8a9b0()
{
    f3m_00c8a9b0::DAT_0106df7c.FUN_0043b7f0("uMaxSkinDecalPerActor:Decals", 3u);
    atexit(f3m_00c8a9b0::FUN_00d87820);
}

// @f3 0x00c8af40 (community match, verified in this file)
namespace f3m_00c8af40 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e184;
void __cdecl FUN_00d87990();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uActiveRefCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8af40()
{
    f3m_00c8af40::DAT_0106e184.FUN_0043b7f0("uActiveRefCount:BudgetCaps", 100u);
    atexit(f3m_00c8af40::FUN_00d87990);
}

// @f3 0x00c8af60 (community match, verified in this file)
namespace f3m_00c8af60 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e2a0;
void __cdecl FUN_00d879a0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uAnimatedObjectsCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8af60()
{
    f3m_00c8af60::DAT_0106e2a0.FUN_0043b7f0("uAnimatedObjectsCount:BudgetCaps", 50u);
    atexit(f3m_00c8af60::FUN_00d879a0);
}

// @f3 0x00c8b000 (community match, verified in this file)
namespace f3m_00c8b000 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e0d8;
void __cdecl FUN_00d879f0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uWaterCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b000()
{
    f3m_00c8b000::DAT_0106e0d8.FUN_0043b7f0("uWaterCount:BudgetCaps", 10u);
    atexit(f3m_00c8b000::FUN_00d879f0);
}

// @f3 0x00c8b0a0 (community match, verified in this file)
namespace f3m_00c8b0a0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e148;
void __cdecl FUN_00d87a40();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uLightExcessGeometryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b0a0()
{
    f3m_00c8b0a0::DAT_0106e148.FUN_0043b7f0("uLightExcessGeometry:BudgetCaps", 100u);
    atexit(f3m_00c8b0a0::FUN_00d87a40);
}

// @f3 0x00c8b120 (community match, verified in this file)
namespace f3m_00c8b120 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e274;
void __cdecl FUN_00d87a80();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uActorRefCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b120()
{
    f3m_00c8b120::DAT_0106e274.FUN_0043b7f0("uActorRefCountInterior:BudgetCaps", 20u);
    atexit(f3m_00c8b120::FUN_00d87a80);
}

// @f3 0x00c8b140 (community match, verified in this file)
namespace f3m_00c8b140 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e13c;
void __cdecl FUN_00d87a90();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uActiveRefCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b140()
{
    f3m_00c8b140::DAT_0106e13c.FUN_0043b7f0("uActiveRefCountInterior:BudgetCaps", 100u);
    atexit(f3m_00c8b140::FUN_00d87a90);
}

// @f3 0x00c8b1a0 (community match, verified in this file)
namespace f3m_00c8b1a0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e19c;
void __cdecl FUN_00d87ac0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uEmittersCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b1a0()
{
    f3m_00c8b1a0::DAT_0106e19c.FUN_0043b7f0("uEmittersCountInterior:BudgetCaps", 50u);
    atexit(f3m_00c8b1a0::FUN_00d87ac0);
}

// @f3 0x00c8b200 (community match, verified in this file)
namespace f3m_00c8b200 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e16c;
void __cdecl FUN_00d87af0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uWaterCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b200()
{
    f3m_00c8b200::DAT_0106e16c.FUN_0043b7f0("uWaterCountInterior:BudgetCaps", 10u);
    atexit(f3m_00c8b200::FUN_00d87af0);
}

// @f3 0x00c8b280 (community match, verified in this file)
namespace f3m_00c8b280 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e258;
void __cdecl FUN_00d87b30();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uLightCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b280()
{
    f3m_00c8b280::DAT_0106e258.FUN_0043b7f0("uLightCountInterior:BudgetCaps", 10u);
    atexit(f3m_00c8b280::FUN_00d87b30);
}

// @f3 0x00c8c6d0 (community match, verified in this file)
namespace f3m_00c8c6d0 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106fa48;
void __cdecl FUN_00d88540();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iShadowMode'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::iShadowMode'')
void __cdecl FUN_00c8c6d0()
{
    f3m_00c8c6d0::DAT_0106fa48.FUN_00491570("iShadowMode:Display", 3);
    atexit(f3m_00c8c6d0::FUN_00d88540);
}

// @f3 0x00c8c930 (community match, verified in this file)
namespace f3m_00c8c930 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f760;
void __cdecl FUN_00d87f60();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iIniBlendType'' | Renderer.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8c930()
{
    f3m_00c8c930::DAT_0106f760.FUN_0043b7f0("iBlendType:BlurShader", 2);
    atexit(f3m_00c8c930::FUN_00d87f60);
}

// @f3 0x00c8cca0 (community match, verified in this file)
namespace f3m_00c8cca0 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f6c4;
void __cdecl FUN_00d880b0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iIniBlendTypeHDR'' | Renderer.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8cca0()
{
    f3m_00c8cca0::DAT_0106f6c4.FUN_0043b7f0("iBlendType:BlurShaderHDR", 2);
    atexit(f3m_00c8cca0::FUN_00d880b0);
}

// @f3 0x00c8ccc0 (community match, verified in this file)
namespace f3m_00c8ccc0 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f8bc;
void __cdecl FUN_00d880c0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iIniBlurPassesHDR'' | Renderer.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8ccc0()
{
    f3m_00c8ccc0::DAT_0106f8bc.FUN_0043b7f0("iNumBlurpasses:BlurShaderHDR", 2);
    atexit(f3m_00c8ccc0::FUN_00d880c0);
}

// @f3 0x00c8d640 (community match, verified in this file)
namespace f3m_00c8d640 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f808;
void __cdecl FUN_00d88630();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iActorShadowCountExt'' | Renderer.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8d640()
{
    f3m_00c8d640::DAT_0106f808.FUN_00491570("iActorShadowCountExt:Display", 2);
    atexit(f3m_00c8d640::FUN_00d88630);
}

// @f3 0x00c8edd0 (community match, verified in this file)
namespace f3m_00c8edd0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106fecc;
void __cdecl FUN_00d88cc0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESWaterSystem::uMaxExteriorWaterReflections'' | TESWater.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8edd0()
{
    f3m_00c8edd0::DAT_0106fecc.FUN_0043b7f0("uMaxExteriorWaterReflections:Water", 2u);
    atexit(f3m_00c8edd0::FUN_00d88cc0);
}

// @f3 0x00c8eee0 (community match, verified in this file)
namespace f3m_00c8eee0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106fd88;
void __cdecl FUN_00d88d30();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESWaterSystem::iAnimFPS'' | TESWater.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8eee0()
{
    f3m_00c8eee0::DAT_0106fd88.FUN_0043b7f0("uSurfaceFPS:Water", 12u);
    atexit(f3m_00c8eee0::FUN_00d88d30);
}

// @f3 0x00c96f70 (community match, verified in this file)
namespace f3m_00c96f70 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01071450;
void __cdecl FUN_00d89bc0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iMaxGrassTypesPerTexture'' | TESLand.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c96f70()
{
    f3m_00c96f70::DAT_01071450.FUN_0043b7f0("iMaxGrassTypesPerTexure:Grass", 2);
    atexit(f3m_00c96f70::FUN_00d89bc0);
}

// @f3 0x00c96f90 (community match, verified in this file)
namespace f3m_00c96f90 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01071490;
void __cdecl FUN_00d89bd0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iGrassDensityEvalSize'' | TESLand.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c96f90()
{
    f3m_00c96f90::DAT_01071490.FUN_0043b7f0("iGrassDensityEvalSize:Grass", 2);
    atexit(f3m_00c96f90::FUN_00d89bd0);
}

// @f3 0x00c97b80 (community match, verified in this file)
namespace f3m_00c97b80 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01071840;
void __cdecl FUN_00d89e70();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iMinGrassSize'' | TESTerrainLODManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c97b80()
{
    f3m_00c97b80::DAT_01071840.FUN_0043b7f0("iMinGrassSize:Grass", 80);
    atexit(f3m_00c97b80::FUN_00d89e70);
}

// @f3 0x00c9d220 (community match, verified in this file)
namespace f3m_00c9d220 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01072aac;
void __cdecl FUN_00d8a3d0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iMaxViewCasterPicksHavok'' | ViewCaster.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c9d220()
{
    f3m_00c9d220::DAT_01072aac.FUN_0043b7f0("iMaxViewCasterPicksHavok:Interface", 10);
    atexit(f3m_00c9d220::FUN_00d8a3d0);
}

// @f3 0x00c9d240 (community match, verified in this file)
namespace f3m_00c9d240 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01072acc;
void __cdecl FUN_00d8a3e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iMaxViewCasterPicksGamebryo'' | ViewCaster.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c9d240()
{
    f3m_00c9d240::DAT_01072acc.FUN_0043b7f0("iMaxViewCasterPicksGamebryo:Interface", 10);
    atexit(f3m_00c9d240::FUN_00d8a3e0);
}

// @f3 0x00c85cf0 (community match, verified in this file)
namespace f3m_00c85cf0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cb0c;
void __cdecl FUN_00d86c80();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sEnvReduceColor'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85cf0()
{
    f3m_00c85cf0::DAT_0106cb0c.FUN_0043b7f0("sEnvReduceColor:Weather", "255,255,255,255");
    atexit(f3m_00c85cf0::FUN_00d86c80);
}

// @f3 0x00c85d30 (community match, verified in this file)
namespace f3m_00c85d30 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cca0;
void __cdecl FUN_00d86ca0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sBumpFadeColor'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c85d30()
{
    f3m_00c85d30::DAT_0106cca0.FUN_0043b7f0("sBumpFadeColor:Weather", "255,255,255,255");
    atexit(f3m_00c85d30::FUN_00d86ca0);
}

// @f3 0x00c861f0 (community match, verified in this file)
namespace f3m_00c861f0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cb90;
void __cdecl FUN_00d86de0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sLanguage'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c861f0()
{
    f3m_00c861f0::DAT_0106cb90.FUN_0043b7f0("sLanguage:General", "ENGLISH");
    atexit(f3m_00c861f0::FUN_00d86de0);
}

// @f3 0x00c86210 (community match, verified in this file)
namespace f3m_00c86210 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cb60;
void __cdecl FUN_00d86df0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sFailureMessage'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86210()
{
    f3m_00c86210::DAT_0106cb60.FUN_0043b7f0("sFailureMessage:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86210::FUN_00d86df0);
}

// @f3 0x00c86230 (community match, verified in this file)
namespace f3m_00c86230 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106ccdc;
void __cdecl FUN_00d86e00();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_Retry'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86230()
{
    f3m_00c86230::DAT_0106ccdc.FUN_0043b7f0("sSysUtil_Retry:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86230::FUN_00d86e00);
}

// @f3 0x00c86250 (community match, verified in this file)
namespace f3m_00c86250 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cd3c;
void __cdecl FUN_00d86e10();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_AutoSaveWarning'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86250()
{
    f3m_00c86250::DAT_0106cd3c.FUN_0043b7f0("sSysUtil_AutoSaveWarning:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86250::FUN_00d86e10);
}

// @f3 0x00c86270 (community match, verified in this file)
namespace f3m_00c86270 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cb78;
void __cdecl FUN_00d86e20();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_GameDataInsufficientSpace'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86270()
{
    f3m_00c86270::DAT_0106cb78.FUN_0043b7f0("sSysUtil_GameDataInsufficientSpace:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86270::FUN_00d86e20);
}

// @f3 0x00c862b0 (community match, verified in this file)
namespace f3m_00c862b0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106ccbc;
void __cdecl FUN_00d86e40();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_SaveDataCreateNew'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c862b0()
{
    f3m_00c862b0::DAT_0106ccbc.FUN_0043b7f0("sSysUtil_SaveDataCreateNew:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c862b0::FUN_00d86e40);
}

// @f3 0x00c862d0 (community match, verified in this file)
namespace f3m_00c862d0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cb84;
void __cdecl FUN_00d86e50();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_SaveDataInsufficientSpace'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c862d0()
{
    f3m_00c862d0::DAT_0106cb84.FUN_0043b7f0("sSysUtil_SaveDataInsufficientSpace:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c862d0::FUN_00d86e50);
}

// @f3 0x00c86310 (community match, verified in this file)
namespace f3m_00c86310 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cd04;
void __cdecl FUN_00d86e70();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSysUtil_DirtyDisc'' | TES.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86310()
{
    f3m_00c86310::DAT_0106cd04.FUN_0043b7f0("sSysUtil_DirtyDisc:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86310::FUN_00d86e70);
}

// @f3 0x00c86330 (community match, verified in this file)
namespace f3m_00c86330 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cd10;
void __cdecl FUN_00d86e80();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sThumbstick'' | TES.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'sSysUtil_AwardsLoading'')
void __cdecl FUN_00c86330()
{
    f3m_00c86330::DAT_0106cd10.FUN_0043b7f0("sThumbstick:LANGUAGE", "No Default string.  Must be loaded from INIFile");
    atexit(f3m_00c86330::FUN_00d86e80);
}

// @f3 0x00c865d0 (community match, verified in this file)
namespace f3m_00c865d0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106ceb0;
void __cdecl FUN_00d86f20();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sLocalMasterPath'' | TESDataHandler.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c865d0()
{
    f3m_00c865d0::DAT_0106ceb0.FUN_0043b7f0("sLocalMasterPath:General", "Data\\");
    atexit(f3m_00c865d0::FUN_00d86f20);
}

// @f3 0x00c865f0 (community match, verified in this file)
namespace f3m_00c865f0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106ce0c;
void __cdecl FUN_00d86f30();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sLocalSavePath'' | TESDataHandler.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c865f0()
{
    f3m_00c865f0::DAT_0106ce0c.FUN_0043b7f0("sLocalSavePath:General", "Saves\\");
    atexit(f3m_00c865f0::FUN_00d86f30);
}

// @f3 0x00c86630 (community match, verified in this file)
namespace f3m_00c86630 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cea4;
void __cdecl FUN_00d86f50();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sMasterMismatch'' | TESDataHandler.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86630()
{
    f3m_00c86630::DAT_0106cea4.FUN_0043b7f0("sMasterMismatchWarning:GeneralWarnings", "One of the files that \"%s\" is dependent on has changed since the last save.");
    atexit(f3m_00c86630::FUN_00d86f50);
}

// @f3 0x00c86650 (community match, verified in this file)
namespace f3m_00c86650 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106cec8;
void __cdecl FUN_00d86f60();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sGMMismatch'' | TESDataHandler.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c86650()
{
    f3m_00c86650::DAT_0106cec8.FUN_0043b7f0("sGeneralMasterMismatchWarning:GeneralWarnings", "One or more plugins could not find the correct versions of the master files they depend on. Errors may occur during load or game play. Check the \"Warnings.txt\" file for more information.\r\n");
    atexit(f3m_00c86650::FUN_00d86f60);
}

// @f3 0x00c8af00 (community match, verified in this file)
namespace f3m_00c8af00 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e0e4;
void __cdecl FUN_00d87970();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uRefCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8af00()
{
    f3m_00c8af00::DAT_0106e0e4.FUN_0043b7f0("uRefCount:BudgetCaps", 700u);
    atexit(f3m_00c8af00::FUN_00d87970);
}

// @f3 0x00c8af80 (community match, verified in this file)
namespace f3m_00c8af80 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e1cc;
void __cdecl FUN_00d879b0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uParticlesCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8af80()
{
    f3m_00c8af80::DAT_0106e1cc.FUN_0043b7f0("uParticlesCount:BudgetCaps", 5000u);
    atexit(f3m_00c8af80::FUN_00d879b0);
}

// @f3 0x00c8afe0 (community match, verified in this file)
namespace f3m_00c8afe0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e0b4;
void __cdecl FUN_00d879e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uTriangleCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8afe0()
{
    f3m_00c8afe0::DAT_0106e0b4.FUN_0043b7f0("uTriangleCount:BudgetCaps", 100000u);
    atexit(f3m_00c8afe0::FUN_00d879e0);
}

// @f3 0x00c8b060 (community match, verified in this file)
namespace f3m_00c8b060 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e2bc;
void __cdecl FUN_00d87a20();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uWaterMemoryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b060()
{
    f3m_00c8b060::DAT_0106e2bc.FUN_0043b7f0("uWaterMemory:BudgetCaps", 5242880u);
    atexit(f3m_00c8b060::FUN_00d87a20);
}

// @f3 0x00c8b0c0 (community match, verified in this file)
namespace f3m_00c8b0c0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e268;
void __cdecl FUN_00d87a50();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uDecalCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b0c0()
{
    f3m_00c8b0c0::DAT_0106e268.FUN_0043b7f0("uDecalCount:BudgetCaps", 500u);
    atexit(f3m_00c8b0c0::FUN_00d87a50);
}

// @f3 0x00c8b0e0 (community match, verified in this file)
namespace f3m_00c8b0e0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e06c;
void __cdecl FUN_00d87a60();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uHavokTriCountBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b0e0()
{
    f3m_00c8b0e0::DAT_0106e06c.FUN_0043b7f0("uHavokTriCount:BudgetCaps", 5000u);
    atexit(f3m_00c8b0e0::FUN_00d87a60);
}

// @f3 0x00c8b1c0 (community match, verified in this file)
namespace f3m_00c8b1c0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e024;
void __cdecl FUN_00d87ad0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uGeometryCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b1c0()
{
    f3m_00c8b1c0::DAT_0106e024.FUN_0043b7f0("uGeometryCountInterior:BudgetCaps", 1000u);
    atexit(f3m_00c8b1c0::FUN_00d87ad0);
}

// @f3 0x00c8b1e0 (community match, verified in this file)
namespace f3m_00c8b1e0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e154;
void __cdecl FUN_00d87ae0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uTriangleCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b1e0()
{
    f3m_00c8b1e0::DAT_0106e154.FUN_0043b7f0("uTriangleCountInterior:BudgetCaps", 100000u);
    atexit(f3m_00c8b1e0::FUN_00d87ae0);
}

// @f3 0x00c8b220 (community match, verified in this file)
namespace f3m_00c8b220 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e2ec;
void __cdecl FUN_00d87b00();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uGeometryMemoryBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b220()
{
    f3m_00c8b220::DAT_0106e2ec.FUN_0043b7f0("uGeometryMemoryInterior:BudgetCaps", 10485760u);
    atexit(f3m_00c8b220::FUN_00d87b00);
}

// @f3 0x00c8b240 (community match, verified in this file)
namespace f3m_00c8b240 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e2cc;
void __cdecl FUN_00d87b10();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uTextureMemoryBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b240()
{
    f3m_00c8b240::DAT_0106e2cc.FUN_0043b7f0("uTextureMemoryInterior:BudgetCaps", 104857600u);
    atexit(f3m_00c8b240::FUN_00d87b10);
}

// @f3 0x00c8b2e0 (community match, verified in this file)
namespace f3m_00c8b2e0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e060;
void __cdecl FUN_00d87b60();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uHavokTriCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b2e0()
{
    f3m_00c8b2e0::DAT_0106e060.FUN_0043b7f0("uHavokTriCountInterior:BudgetCaps", 5000u);
    atexit(f3m_00c8b2e0::FUN_00d87b60);
}

// @f3 0x00c8b5a0 (community match, verified in this file)
namespace f3m_00c8b5a0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e1b4;
void __cdecl FUN_00d87c50();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uLoadedAreaNonActorMemoryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b5a0()
{
    f3m_00c8b5a0::DAT_0106e1b4.FUN_0043b7f0("uLoadedAreaNonActorMemoryBudgetCap:BudgetCaps", 185597952u);
    atexit(f3m_00c8b5a0::FUN_00d87c50);
}

// @f3 0x00c8b5c0 (community match, verified in this file)
namespace f3m_00c8b5c0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e178;
void __cdecl FUN_00d87c60();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uWastelandLODBudgetAdjustment'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b5c0()
{
    f3m_00c8b5c0::DAT_0106e178.FUN_0043b7f0("uWastelandLODBudgetAdjustment:BudgetCaps", 20971520u);
    atexit(f3m_00c8b5c0::FUN_00d87c60);
}

// @f3 0x00c8b5e0 (community match, verified in this file)
namespace f3m_00c8b5e0 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e280;
void __cdecl FUN_00d87c70();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uCityLODBudgetAdjustment'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b5e0()
{
    f3m_00c8b5e0::DAT_0106e280.FUN_0043b7f0("uCityLODBudgetAdjustment:BudgetCaps", 5242880u);
    atexit(f3m_00c8b5e0::FUN_00d87c70);
}

// @f3 0x00c8b600 (community match, verified in this file)
namespace f3m_00c8b600 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106e0a8;
void __cdecl FUN_00d87c80();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'uActorMemoryBudgetCap'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b600()
{
    f3m_00c8b600::DAT_0106e0a8.FUN_0043b7f0("uActorMemoryBudgetCap:BudgetCaps", 10485760u);
    atexit(f3m_00c8b600::FUN_00d87c80);
}

// @f3 0x00c8c570 (community match, verified in this file)
namespace f3m_00c8c570 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f6b4;
void __cdecl FUN_00d88510();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iINIScreenHeight'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::iINIScreenHeight'')
void __cdecl FUN_00c8c570()
{
    f3m_00c8c570::DAT_0106f6b4.FUN_00491570("iSize H:Display", 480);
    atexit(f3m_00c8c570::FUN_00d88510);
}

// @f3 0x00c8c870 (community match, verified in this file)
namespace f3m_00c8c870 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106fb98;
void __cdecl FUN_00d88580();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iWaterReflectHeight'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::iWaterReflectHeight'')
void __cdecl FUN_00c8c870()
{
    f3m_00c8c870::DAT_0106fb98.FUN_00491570("iWaterReflectHeight:Water", 512);
    atexit(f3m_00c8c870::FUN_00d88580);
}

// @f3 0x00c8c9a0 (community match, verified in this file)
namespace f3m_00c8c9a0 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106f930;
void __cdecl FUN_00d87f90();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iIniBlurTexSize'' | Renderer.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8c9a0()
{
    f3m_00c8c9a0::DAT_0106f930.FUN_0043b7f0("iBlurTexSize:BlurShader", 256);
    atexit(f3m_00c8c9a0::FUN_00d87f90);
}

// @f3 0x00c8d6c0 (community match, verified in this file)
namespace f3m_00c8d6c0 {
struct Setting { void FUN_00491570(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_0106fa3c;
void __cdecl FUN_00d88650();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::iShadowMapResolution'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'iShadowMapResolution'')
void __cdecl FUN_00c8d6c0()
{
    f3m_00c8d6c0::DAT_0106fa3c.FUN_00491570("iShadowMapResolution:Display", 256);
    atexit(f3m_00c8d6c0::FUN_00d88650);
}

// @f3 0x00c8d900 (community match, verified in this file)
namespace f3m_00c8d900 {
struct Setting { void FUN_00491570(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106f7e4;
void __cdecl FUN_00d88680();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'Renderer::sD3DDevice'' | Renderer.obj | fnv360_0822_debug, objrun, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::bDirectionalMaterial'')
void __cdecl FUN_00c8d900()
{
    f3m_00c8d900::DAT_0106f7e4.FUN_00491570("sD3DDevice:Display", "");
    atexit(f3m_00c8d900::FUN_00d88680);
}

// @f3 0x00c8ef00 (community match, verified in this file)
namespace f3m_00c8ef00 {
struct Setting { void FUN_0043b7f0(const char* name, unsigned int value); };   // non-inline Setting constructor
extern Setting DAT_0106fe14;
void __cdecl FUN_00d88d40();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESWaterSystem::iNearWaterRadius'' | TESWater.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c8ef00()
{
    f3m_00c8ef00::DAT_0106fe14.FUN_0043b7f0("uNearWaterRadius:Water", 1000u);
    atexit(f3m_00c8ef00::FUN_00d88d40);
}

// @f3 0x00c8f0d0 (community match, verified in this file)
namespace f3m_00c8f0d0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_0106ff6c;
void __cdecl FUN_00d88da0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'sSurfaceTexture'' | TESWater.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8f0d0()
{
    f3m_00c8f0d0::DAT_0106ff6c.FUN_0043b7f0("sSurfaceTexture:Water", "water");
    atexit(f3m_00c8f0d0::FUN_00d88da0);
}

// @f3 0x00c97000 (community match, verified in this file)
namespace f3m_00c97000 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01071474;
void __cdecl FUN_00d89c00();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'iLandBorder1G'' | TESLand.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c97000()
{
    f3m_00c97000::DAT_01071474.FUN_0043b7f0("iLandBorder1G:Landscape", 255);
    atexit(f3m_00c97000::FUN_00d89c00);
}

// @f3 0x00c970a0 (community match, verified in this file)
namespace f3m_00c970a0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_010714d4;
void __cdecl FUN_00d89c50();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESObjectLAND::sDefaultLandDiffuseTexture'' | TESLand.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c970a0()
{
    f3m_00c970a0::DAT_010714d4.FUN_0043b7f0("sDefaultLandDiffuseTexture:Landscape", "DirtWasteland01.dds");
    atexit(f3m_00c970a0::FUN_00d89c50);
}

// @f3 0x00c97db0 (community match, verified in this file)
namespace f3m_00c97db0 {
struct Setting { void FUN_0043b7f0(const char* name, int value); };   // non-inline Setting constructor
extern Setting DAT_01071884;
void __cdecl FUN_00d89ea0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESWaterForm::iWaterNoiseResolution'' | TESWaterForm.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c97db0()
{
    f3m_00c97db0::DAT_01071884.FUN_0043b7f0("iWaterNoiseResolution:Water", 256);
    atexit(f3m_00c97db0::FUN_00d89ea0);
}

// @f3 0x00c9b650 (community match, verified in this file)
namespace f3m_00c9b650 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_010724b4;
void __cdecl FUN_00d8a160();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESResponse::sFileTypeGame'' | TESResponse.obj | fnv360_0822_debug, objrun_open, low
void __cdecl FUN_00c9b650()
{
    f3m_00c9b650::DAT_010724b4.FUN_0043b7f0("sFileTypeGame:Voice", "mp3");
    atexit(f3m_00c9b650::FUN_00d8a160);
}

// @f3 0x00c9b670 (community match, verified in this file)
namespace f3m_00c9b670 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_010724d0;
void __cdecl FUN_00d8a170();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESResponse::sFileTypeSource'' | TESResponse.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c9b670()
{
    f3m_00c9b670::DAT_010724d0.FUN_0043b7f0("sFileTypeSource:Voice", "wav");
    atexit(f3m_00c9b670::FUN_00d8a170);
}

// @f3 0x00c9b690 (community match, verified in this file)
namespace f3m_00c9b690 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072498;
void __cdecl FUN_00d8a180();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESResponse::sFileTypeLip'' | TESResponse.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c9b690()
{
    f3m_00c9b690::DAT_01072498.FUN_0043b7f0("sFileTypeLip:Voice", "lip");
    atexit(f3m_00c9b690::FUN_00d8a180);
}

// @f3 0x00c9b6b0 (community match, verified in this file)
namespace f3m_00c9b6b0 {
struct Setting { void FUN_0043b7f0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072470;
void __cdecl FUN_00d8a190();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'TESResponse::sFileTypeLTF'' | TESResponse.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c9b6b0()
{
    f3m_00c9b6b0::DAT_01072470.FUN_0043b7f0("sFileTypeLTF:Voice", "ltf");
    atexit(f3m_00c9b6b0::FUN_00d8a190);
}

// @f3 0x00c9d430 (community match, verified in this file)
namespace f3m_00c9d430 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d40;
void __cdecl FUN_00d8a470();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::sHitSpot'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d430()
{
    f3m_00c9d430::DAT_01072d40.FUN_005752c0("sHitSpot:HIT", "Bip01 Spine2");
    atexit(f3m_00c9d430::FUN_00d8a470);
}

// @f3 0x00c9d470 (community match, verified in this file)
namespace f3m_00c9d470 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072ca4;
void __cdecl FUN_00d8a490();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::RHand'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d470()
{
    f3m_00c9d470::DAT_01072ca4.FUN_005752c0("sRHand:HIT", "1.0, 1.0");
    atexit(f3m_00c9d470::FUN_00d8a490);
}

// @f3 0x00c9d490 (community match, verified in this file)
namespace f3m_00c9d490 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d1c;
void __cdecl FUN_00d8a4a0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::RForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d490()
{
    f3m_00c9d490::DAT_01072d1c.FUN_005752c0("sRForeArm:HIT", "1.0, 1.0");
    atexit(f3m_00c9d490::FUN_00d8a4a0);
}

// @f3 0x00c9d4d0 (community match, verified in this file)
namespace f3m_00c9d4d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072bec;
void __cdecl FUN_00d8a4c0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::LHand'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d4d0()
{
    f3m_00c9d4d0::DAT_01072bec.FUN_005752c0("sLHand:HIT", "1.0, 1.0");
    atexit(f3m_00c9d4d0::FUN_00d8a4c0);
}

// @f3 0x00c9d4f0 (community match, verified in this file)
namespace f3m_00c9d4f0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c10;
void __cdecl FUN_00d8a4d0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::LForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d4f0()
{
    f3m_00c9d4f0::DAT_01072c10.FUN_005752c0("sLForeArm:HIT", "1.0, 1.0");
    atexit(f3m_00c9d4f0::FUN_00d8a4d0);
}

// @f3 0x00c9d510 (community match, verified in this file)
namespace f3m_00c9d510 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d58;
void __cdecl FUN_00d8a4e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::LUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d510()
{
    f3m_00c9d510::DAT_01072d58.FUN_005752c0("sLUpperArm:HIT", "0.2, 0.5");
    atexit(f3m_00c9d510::FUN_00d8a4e0);
}

// @f3 0x00c9d530 (community match, verified in this file)
namespace f3m_00c9d530 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b40;
void __cdecl FUN_00d8a4f0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::Spine2'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d530()
{
    f3m_00c9d530::DAT_01072b40.FUN_005752c0("sSpine2:HIT", "0.5, 0.7");
    atexit(f3m_00c9d530::FUN_00d8a4f0);
}

// @f3 0x00c9d550 (community match, verified in this file)
namespace f3m_00c9d550 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b34;
void __cdecl FUN_00d8a500();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::Spine1'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d550()
{
    f3m_00c9d550::DAT_01072b34.FUN_005752c0("sSpine1:HIT", "0.6, 0.8");
    atexit(f3m_00c9d550::FUN_00d8a500);
}

// @f3 0x00c9d570 (community match, verified in this file)
namespace f3m_00c9d570 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072bd4;
void __cdecl FUN_00d8a510();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::Body'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d570()
{
    f3m_00c9d570::DAT_01072bd4.FUN_005752c0("sBody:HIT", "1.0, 1.0");
    atexit(f3m_00c9d570::FUN_00d8a510);
}

// @f3 0x00c9d590 (community match, verified in this file)
namespace f3m_00c9d590 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d88;
void __cdecl FUN_00d8a520();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHit::Head'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d590()
{
    f3m_00c9d590::DAT_01072d88.FUN_005752c0("sHead:HIT", "0.4, 0.6");
    atexit(f3m_00c9d590::FUN_00d8a520);
}

// @f3 0x00c9d5d0 (community match, verified in this file)
namespace f3m_00c9d5d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d10;
void __cdecl FUN_00d8a540();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::sHitStart'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d5d0()
{
    f3m_00c9d5d0::DAT_01072d10.FUN_005752c0("sHitStart:QUADHIT", "Bip01 Head");
    atexit(f3m_00c9d5d0::FUN_00d8a540);
}

// @f3 0x00c9d790 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c9d790 {

struct Setting { void FUN_005752c0(const char* a0, const char* a1); };
extern Setting DAT_01072c28;
void __cdecl FUN_00d8a620();
extern const char DAT_00de79a0[];
extern const char DAT_00de77d4[];

// pdb: `dynamic initializer for 'BlendDefault::Body'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d790()
{
    DAT_01072c28.FUN_005752c0(DAT_00de79a0, DAT_00de77d4);
    atexit(FUN_00d8a620);
}

}

// @f3 0x00c9d5f0 (community match, verified in this file)
namespace f3m_00c9d5f0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072cec;
void __cdecl FUN_00d8a550();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::RCalf'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d5f0()
{
    f3m_00c9d5f0::DAT_01072cec.FUN_005752c0("sRCalf:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d5f0::FUN_00d8a550);
}

// @f3 0x00c9d610 (community match, verified in this file)
namespace f3m_00c9d610 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b74;
void __cdecl FUN_00d8a560();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::RThigh'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d610()
{
    f3m_00c9d610::DAT_01072b74.FUN_005752c0("sRThigh:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d610::FUN_00d8a560);
}

// @f3 0x00c9d630 (community match, verified in this file)
namespace f3m_00c9d630 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c34;
void __cdecl FUN_00d8a570();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::RForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d630()
{
    f3m_00c9d630::DAT_01072c34.FUN_005752c0("sRForeArm:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d630::FUN_00d8a570);
}

// @f3 0x00c9d650 (community match, verified in this file)
namespace f3m_00c9d650 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b64;
void __cdecl FUN_00d8a580();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::RUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d650()
{
    f3m_00c9d650::DAT_01072b64.FUN_005752c0("sRUpperArm:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d650::FUN_00d8a580);
}

// @f3 0x00c9d670 (community match, verified in this file)
namespace f3m_00c9d670 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072ddc;
void __cdecl FUN_00d8a590();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::LCalf'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d670()
{
    f3m_00c9d670::DAT_01072ddc.FUN_005752c0("sLCalf:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d670::FUN_00d8a590);
}

// @f3 0x00c9d690 (community match, verified in this file)
namespace f3m_00c9d690 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072dac;
void __cdecl FUN_00d8a5a0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::LThigh'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d690()
{
    f3m_00c9d690::DAT_01072dac.FUN_005752c0("sLThigh:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d690::FUN_00d8a5a0);
}

// @f3 0x00c9d6b0 (community match, verified in this file)
namespace f3m_00c9d6b0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072cbc;
void __cdecl FUN_00d8a5b0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::LForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d6b0()
{
    f3m_00c9d6b0::DAT_01072cbc.FUN_005752c0("sLForeArm:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d6b0::FUN_00d8a5b0);
}

// @f3 0x00c9d6d0 (community match, verified in this file)
namespace f3m_00c9d6d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072ba4;
void __cdecl FUN_00d8a5c0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::LUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d6d0()
{
    f3m_00c9d6d0::DAT_01072ba4.FUN_005752c0("sLUpperArm:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d6d0::FUN_00d8a5c0);
}

// @f3 0x00c9d710 (community match, verified in this file)
namespace f3m_00c9d710 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072bbc;
void __cdecl FUN_00d8a5e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::Spine1'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d710()
{
    f3m_00c9d710::DAT_01072bbc.FUN_005752c0("sSpine1:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d710::FUN_00d8a5e0);
}

// @f3 0x00c9d730 (community match, verified in this file)
namespace f3m_00c9d730 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d94;
void __cdecl FUN_00d8a5f0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendHitQuad::Body'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d730()
{
    f3m_00c9d730::DAT_01072d94.FUN_005752c0("sBody:QUADHIT", "1.0, 1.0");
    atexit(f3m_00c9d730::FUN_00d8a5f0);
}

// @f3 0x00c9d770 (community match, verified in this file)
namespace f3m_00c9d770 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c1c;
void __cdecl FUN_00d8a610();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::Head'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d770()
{
    f3m_00c9d770::DAT_01072c1c.FUN_005752c0("sHead:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d770::FUN_00d8a610);
}

// @f3 0x00c9d7b0 (community match, verified in this file)
namespace f3m_00c9d7b0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c8c;
void __cdecl FUN_00d8a630();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::Spine1'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d7b0()
{
    f3m_00c9d7b0::DAT_01072c8c.FUN_005752c0("sSpine1:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d7b0::FUN_00d8a630);
}

// @f3 0x00c9d7d0 (community match, verified in this file)
namespace f3m_00c9d7d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072be0;
void __cdecl FUN_00d8a640();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::Spine2'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d7d0()
{
    f3m_00c9d7d0::DAT_01072be0.FUN_005752c0("sSpine2:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d7d0::FUN_00d8a640);
}

// @f3 0x00c9d830 (community match, verified in this file)
namespace f3m_00c9d830 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072cf8;
void __cdecl FUN_00d8a670();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::LHand'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d830()
{
    f3m_00c9d830::DAT_01072cf8.FUN_005752c0("sLHand:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d830::FUN_00d8a670);
}

// @f3 0x00c9d850 (community match, verified in this file)
namespace f3m_00c9d850 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b28;
void __cdecl FUN_00d8a680();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::LThigh'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d850()
{
    f3m_00c9d850::DAT_01072b28.FUN_005752c0("sLThigh:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d850::FUN_00d8a680);
}

// @f3 0x00c9d870 (community match, verified in this file)
namespace f3m_00c9d870 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072cc8;
void __cdecl FUN_00d8a690();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::LCalf'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d870()
{
    f3m_00c9d870::DAT_01072cc8.FUN_005752c0("sLCalf:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d870::FUN_00d8a690);
}

// @f3 0x00c9d890 (community match, verified in this file)
namespace f3m_00c9d890 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072d7c;
void __cdecl FUN_00d8a6a0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::LFoot'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d890()
{
    f3m_00c9d890::DAT_01072d7c.FUN_005752c0("sLFoot:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d890::FUN_00d8a6a0);
}

// @f3 0x00c9d8d0 (community match, verified in this file)
namespace f3m_00c9d8d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072da0;
void __cdecl FUN_00d8a6c0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::RForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d8d0()
{
    f3m_00c9d8d0::DAT_01072da0.FUN_005752c0("sRForeArm:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d8d0::FUN_00d8a6c0);
}

// @f3 0x00c9d910 (community match, verified in this file)
namespace f3m_00c9d910 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c98;
void __cdecl FUN_00d8a6e0();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::RThigh'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d910()
{
    f3m_00c9d910::DAT_01072c98.FUN_005752c0("sRThigh:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d910::FUN_00d8a6e0);
}

// @f3 0x00c9d950 (community match, verified in this file)
namespace f3m_00c9d950 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b8c;
void __cdecl FUN_00d8a700();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::RFoot'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d950()
{
    f3m_00c9d950::DAT_01072b8c.FUN_005752c0("sRFoot:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d950::FUN_00d8a700);
}

// @f3 0x00c9d970 (community match, verified in this file)
namespace f3m_00c9d970 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072c40;
void __cdecl FUN_00d8a710();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::Tail'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d970()
{
    f3m_00c9d970::DAT_01072c40.FUN_005752c0("sTail:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d970::FUN_00d8a710);
}

// @f3 0x00c9d9b0 (community match, verified in this file)
namespace f3m_00c9d9b0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072bc8;
void __cdecl FUN_00d8a730();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::Quiver'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d9b0()
{
    f3m_00c9d9b0::DAT_01072bc8.FUN_005752c0("sQuiver:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d9b0::FUN_00d8a730);
}

// @f3 0x00c9d9d0 (community match, verified in this file)
namespace f3m_00c9d9d0 {
struct Setting { void FUN_005752c0(const char* name, const char* value); };   // non-inline Setting constructor
extern Setting DAT_01072b58;
void __cdecl FUN_00d8a740();   // atexit destructor of the setting
}

// pdb: `dynamic initializer for 'BlendDefault::PonyTail'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d9d0()
{
    f3m_00c9d9d0::DAT_01072b58.FUN_005752c0("sPonyTail:DEFAULT", "1.0, 1.0");
    atexit(f3m_00c9d9d0::FUN_00d8a740);
}

// @f3 0x00c9d8b0 (community match, verified in this file)
extern FUN_005752c0_Obj DAT_01072bb0;
namespace f3m_00c9d8b0 {

struct FUN_005752c0_Obj {
    void __thiscall FUN_005752c0(const char* text, const char* name);
};
extern void __cdecl FUN_00c00d1f(void (__cdecl *callback)());
extern void __cdecl DAT_00d8a6b0();

// pdb: `dynamic initializer for 'BlendDefault::RUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d8b0() {
    DAT_01072bb0.FUN_005752c0("sRUpperArm:DEFAULT", "1.0, 1.0");
    FUN_00c00d1f(DAT_00d8a6b0);
}
}   // namespace f3m_00c9d8b0

// @f3 0x00c8b100 (community match, verified in this file)
extern FUN_0043b7f0_Obj DAT_0106e190;
extern const char DAT_00dbf5f0[];
namespace f3m_00c8b100 {
namespace Task2397 { void __cdecl FUN_00d87a70(); }
// pdb: `dynamic initializer for 'uRefCountBudgetCapInterior'' | BGSSceneInfo.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8b100() {
    DAT_0106e190.FUN_0043b7f0(DAT_00dbf5f0, 1000);
    FUN_00c00d1f(Task2397::FUN_00d87a70);
}
}   // namespace f3m_00c8b100

// @f3 0x00c9d6f0 (community match, verified in this file)
struct FUN_005752c0_obj {
    void FUN_005752c0(const char* name, const char* value);
};
extern FUN_005752c0_obj DAT_01072d34;
extern const char DAT_00de7944[], DAT_00de77d4[];
void __cdecl FUN_00d8a5d0();
// pdb: `dynamic initializer for 'BlendHitQuad::Spine2'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d6f0() {
    DAT_01072d34.FUN_005752c0(DAT_00de7944, DAT_00de77d4);
    FUN_00c00d1f(FUN_00d8a5d0);
}

// @f3 0x00c8c550 (community match, verified in this file)
namespace task2398 {
struct Setting {void FUN_00491570(const char*,int);};
extern Setting DAT_0106f900;
extern const char DAT_00dc1840[];
void __cdecl FUN_00d88500();
int __cdecl FUN_00c00d1f(void(__cdecl*)());
// pdb: `dynamic initializer for 'Renderer::iINIScreenWidth'' | Renderer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'BSRenderer::iINIScreenWidth'')
void __cdecl FUN_00c8c550(){DAT_0106f900.FUN_00491570(DAT_00dc1840,640);FUN_00c00d1f(FUN_00d88500);}
}

// @f3 0x00c9d750 (community match, verified in this file)
inline void* operator new(unsigned int, void* p) { return p; }
struct FUN_005752c0 {
    void* vtable;
    const char* value;
    const char* name;
    FUN_005752c0(const char*, const char*);
};
extern FUN_005752c0 DAT_01072c68;
extern const char DAT_00de7974[];
extern const char DAT_00de7984[];
void __cdecl FUN_00d8a600();
extern "C" int __cdecl atexit(void (__cdecl*)());
// pdb: `dynamic initializer for 'BlendHitQuad::Head'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d750() {
    new (&DAT_01072c68) FUN_005752c0(DAT_00de7974, DAT_00de7984);
    atexit(FUN_00d8a600);
}

// @f3 0x00c9d8f0 (community match, verified in this file)
namespace task2401 {
struct Setting {void FUN_005752c0(const char*,const char*);};
extern Setting DAT_01072b80;
extern const char DAT_00de7a60[],DAT_00de7a70[];
void __cdecl FUN_00d8a6d0();
int __cdecl FUN_00c00d1f(void(__cdecl*)());
// pdb: `dynamic initializer for 'BlendDefault::RHand'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d8f0(){DAT_01072b80.FUN_005752c0(DAT_00de7a60,DAT_00de7a70);FUN_00c00d1f(FUN_00d8a6d0);}
}

// @f3 0x00c955d0 (community match, verified in this file)
extern char DAT_010706ed;
namespace f3m_00c955d0 {

extern int GetAttenuationSettings();

// pdb: `dynamic initializer for 'bAttenuationInitialized'' | TESLight.obj | tesv_win, objrun_open, low
void __cdecl FUN_00c955d0() {
    DAT_010706ed = GetAttenuationSettings();
}
}   // namespace f3m_00c955d0

// @f3 0x00c8a970 (community match, verified in this file)
struct FUN_00491570_Obj {
    void __thiscall FUN_00491570(const char* text, int value);
};
extern FUN_00491570_Obj DAT_0106df0c;
extern const char DAT_00dbebdc[];
extern void __cdecl FUN_00d87800();
extern void __cdecl FUN_00c00d1f(void (__cdecl*)());

// pdb: `dynamic initializer for 'BGSDecalManager::iMaxDecals'' | BGSDecalManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c8a970()
{
    DAT_0106df0c.FUN_00491570(DAT_00dbebdc, 0x64);
    FUN_00c00d1f(FUN_00d87800);
}

// @f3 0x00c9d810 (community match, verified in this file)
extern FUN_005752c0_Obj DAT_01072d28;
extern const char DAT_00de79e4[];
extern const char DAT_00de77d4[];
namespace f3m_00c9d810 {


struct FUN_005752c0_Obj {
    void __thiscall FUN_005752c0(const char* a1, const char* a2);
};
extern void __cdecl FUN_00d8a660();
extern void __cdecl FUN_00c00d1f(void (*callback)());

// pdb: `dynamic initializer for 'BlendDefault::LForeArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d810() {
    DAT_01072d28.FUN_005752c0(DAT_00de79e4, DAT_00de77d4);
    FUN_00c00d1f(FUN_00d8a660);
}
}   // namespace f3m_00c9d810

// @f3 0x00c96fe0 (community match, verified in this file)
namespace f3m_00c96fe0 {
struct Setting
{
    void __thiscall FUN_0043b7f0(const char* name, int value);
};
extern Setting DAT_01071400;
typedef void (__cdecl* AtExitCallback)();
void __cdecl FUN_00c00d1f(AtExitCallback callback);
void __cdecl FUN_00d89bf0();

// pdb: `dynamic initializer for 'iLandBorder1R'' | TESLand.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00c96fe0()
{
    DAT_01071400.FUN_0043b7f0("iLandBorder1R:Landscape", 0xff);
    FUN_00c00d1f(FUN_00d89bf0);
}
}

// @f3 0x00c9d4b0 (community match, verified in this file)
namespace f3m_00c9d4b0 {
struct StringSetting
{
    void __thiscall FUN_005752c0(const char* name, const char* value);
};
extern StringSetting DAT_01072d4c;
typedef void (__cdecl* AtExitCallback)();
void __cdecl FUN_00c00d1f(AtExitCallback callback);
void __cdecl FUN_00d8a4b0();

// pdb: `dynamic initializer for 'BlendHit::RUpperArm'' | XBlendSettings.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00c9d4b0()
{
    DAT_01072d4c.FUN_005752c0("sRUpperArm:HIT", "0.2, 0.5");
    FUN_00c00d1f(FUN_00d8a4b0);
}
}

// @f3 0x00c83710 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c83710 {
void __cdecl FUN_00403080();
void __cdecl FUN_00d867f0();

struct Registered3710;
struct Registry3710 {
    virtual void vf00();
    virtual void Register(Registered3710* a_pObject);
};
extern Registry3710* DAT_010701a8;

struct Base3710 {
    Base3710() {}
    ~Base3710();
};

struct Registered3710 : public Base3710 {
    __forceinline Registered3710() {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
    int unk00;
};
extern Registered3710 DAT_00f46ae4;

void __cdecl FUN_00c83710() {
    DAT_00f46ae4.Registered3710::Registered3710();
    atexit(FUN_00d867f0);
}
}

// @f3 0x00c932e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c932e0 {
void __cdecl FUN_00403080();
void __cdecl FUN_00d89540();

struct Registered32e0;
struct Registry32e0 {
    virtual void vf00();
    virtual void Register(Registered32e0* a_pObject);
};
extern Registry32e0* DAT_010701a8;

struct Base32e0 {
    Base32e0() {}
    ~Base32e0();
};

struct Registered32e0 : public Base32e0 {
    __forceinline Registered32e0() {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
    int unk00;
};
extern Registered32e0 DAT_00f4e1ac;

void __cdecl FUN_00c932e0() {
    DAT_00f4e1ac.Registered32e0::Registered32e0();
    atexit(FUN_00d89540);
}
}

// @f3 0x00c92f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92f20 {
void __cdecl FUN_00403080();
void __cdecl FUN_00d894a0();

struct Registered2f20;
struct Registry2f20 {
    virtual void vf00();
    virtual void Register(Registered2f20* a_pObject);
};
extern Registry2f20* DAT_010701a8;

struct Base2f20 {
    Base2f20() {}
    ~Base2f20();
};

struct Registered2f20 : public Base2f20 {
    __forceinline Registered2f20() {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
    int unk00;
};
extern Registered2f20 DAT_00f4e134;

void __cdecl FUN_00c92f20() {
    DAT_00f4e134.Registered2f20::Registered2f20();
    atexit(FUN_00d894a0);
}
}

// @f3 0x00c88e70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88e70 {
void __cdecl FUN_00403080();
void __cdecl FUN_00c2a8ea();

struct Registered8e70;
struct Registry8e70 {
    virtual void vf00();
    virtual void Register(Registered8e70* a_pObject);
};
extern Registry8e70* DAT_010701a8;

struct Base8e70 {
    Base8e70() {}
    ~Base8e70();
};

struct Registered8e70 : public Base8e70 {
    __forceinline Registered8e70() {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
    int unk00;
};
extern Registered8e70 DAT_00f4a520;

void __cdecl FUN_00c88e70() {
    DAT_00f4a520.Registered8e70::Registered8e70();
    atexit(FUN_00c2a8ea);
}
}

// @f3 0x00c92800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c92800 {
void __cdecl FUN_00403080();
void __cdecl FUN_00d89370();

struct Registered2800;
struct Registry2800 {
    virtual void vf00();
    virtual void Register(Registered2800* a_pObject);
};
extern Registry2800* DAT_010701a8;

struct Base2800 {
    Base2800() {}
    ~Base2800();
};

struct Registered2800 : public Base2800 {
    __forceinline Registered2800() {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
    int unk00;
};
extern Registered2800 DAT_00f4e050;

void __cdecl FUN_00c92800() {
    DAT_00f4e050.Registered2800::Registered2800();
    atexit(FUN_00d89370);
}
}

// @f3 0x00c8b8c0 (community match, verified in this file)
struct StartupEntry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
extern StartupEntry DAT_0106e350[20];
void __cdecl FUN_004580f0();
void __cdecl FUN_00458160();
void __cdecl FUN_00d87ca0();
void __stdcall FUN_00c01f76(void* entries, unsigned int entrySize, unsigned int count,
                          void (__cdecl* construct)(), void (__cdecl* destroy)());
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());

void __cdecl FUN_00c8b8c0()
{
    FUN_00c01f76(DAT_0106e350, sizeof(StartupEntry), 20, FUN_004580f0, FUN_00458160);
    FUN_00c00d1f(FUN_00d87ca0);
}

// @f3 0x00c9be60 (community match, verified in this file)
struct StartupEntry84 {
    int unk00;
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
};
extern StartupEntry84 DAT_01072598[2];
void __cdecl FUN_00517010();
void __cdecl FUN_00519960();
void __cdecl FUN_00d8a270();
void __stdcall FUN_00c01f76(void* entries, unsigned int entrySize, unsigned int count,
                          void (__cdecl* construct)(), void (__cdecl* destroy)());
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());

void __cdecl FUN_00c9be60()
{
    FUN_00c01f76(DAT_01072598, sizeof(StartupEntry84), 2, FUN_00517010, FUN_00519960);
    FUN_00c00d1f(FUN_00d8a270);
}

// @f3 0x00c88030 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00c88030 {
struct Setting;
struct SettingManager
{
    virtual void v00();
    virtual void Register(Setting* setting);
};
extern SettingManager* DAT_010701a8;
void FUN_00403080();

struct SettingBase
{
    void FUN_00401e90();
    __forceinline ~SettingBase() { FUN_00401e90(); }
};

struct Setting : SettingBase
{
    __forceinline Setting()
    {
        FUN_00403080();
        DAT_010701a8->Register(this);
    }
};

extern Setting DAT_00f4a358;
void __cdecl FUN_00d872a0();
}

void __cdecl FUN_00c88030()
{
    f3m_00c88030::DAT_00f4a358.Setting::Setting();
    atexit(f3m_00c88030::FUN_00d872a0);
}

// @f3 0x00c9f850 (community match, verified in this file)
namespace f3m_00c9f850 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f5e208;
void __cdecl FUN_00d8aa10();

void __cdecl FUN_00c9f850()
{
    DAT_00f5e208.Setting::Setting();
    atexit(FUN_00d8aa10);
}
}

// @f3 0x00c91ea0 (community match, verified in this file)
namespace f3m_00c91ea0 {
struct SettingCollection { virtual void v00(); virtual void Add(void* setting); };
struct SettingBase { ~SettingBase(); };
// the Setting at 0x00f4df24 is statically initialised (vtable, value, name); only the registration part of its
// constructor runs dynamically
struct SettingRegistration : SettingBase { SettingRegistration(); };
extern SettingCollection* DAT_010701a8;
extern SettingRegistration DAT_00f4df24;
void __cdecl FUN_00403080();   // creates the setting collection singleton on first use
void __cdecl FUN_00d891e0();   // atexit destructor of the setting
__forceinline SettingRegistration::SettingRegistration()
{
    FUN_00403080();
    DAT_010701a8->Add(this);
}
}

void __cdecl FUN_00c91ea0()
{
    f3m_00c91ea0::DAT_00f4df24.f3m_00c91ea0::SettingRegistration::SettingRegistration();
    atexit(f3m_00c91ea0::FUN_00d891e0);
}

// @f3 0x00c9e220 (community match, verified in this file)
namespace close_c9e220 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01072f70;
}
void FUN_00c9e220()
{
    close_c9e220::DAT_01072f70.FUN_008a8440();
}

// @f3 0x00c90b10 (community match, verified in this file)
struct CleanupC90B { void FUN_008a8440(); };
extern CleanupC90B DAT_010704ac;
void FUN_00c90b10() { DAT_010704ac.FUN_008a8440(); }

// @f3 0x00c9b090 (community match, verified in this file)
struct CleanupB_00c9b090 {
    void FUN_008a8440();
};
extern CleanupB_00c9b090 DAT_0107236c;
void FUN_00c9b090()
{
    DAT_0107236c.FUN_008a8440();
}

// @f3 0x00c8a600 (community match, verified in this file)
struct CleanupC8A6 { void FUN_008a8440(); };
extern CleanupC8A6 DAT_0106dec0;
void FUN_00c8a600() { DAT_0106dec0.FUN_008a8440(); }

// @f3 0x00c865a0 (community match, verified in this file)
namespace f3_00c865a0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0106cebc;
}

void __cdecl FUN_00c865a0() {
    f3_00c865a0::DAT_0106cebc.FUN_008a8440();
}

// @f3 0x00c974f0 (community match, verified in this file)
namespace f3m_00c974f0 {
void __cdecl FUN_00d89cf0();
void __cdecl FUN_00c00d1f(void (__cdecl *callback)());
void FUN_00c974f0() { FUN_00c00d1f(FUN_00d89cf0); }
}   // namespace f3m_00c974f0

// @f3 0x00c9a450 (community match, verified in this file)
struct CleanupObjectC9a450 { void FUN_008a8440(); };
extern CleanupObjectC9a450 DAT_01072118;
void __cdecl FUN_00c9a450(){DAT_01072118.FUN_008a8440();}

// @f3 0x00c9dcb0 (community match, verified in this file)
struct StaticCleanupA51 { void FUN_008a8440(); };
extern StaticCleanupA51 DAT_01072e40;
void __cdecl FUN_00c9dcb0() { DAT_01072e40.FUN_008a8440(); }

// @f3 0x00c998f0 (community match, verified in this file)
struct CleanupB_00c998f0 {
    void FUN_008a8440();
};
extern CleanupB_00c998f0 DAT_01071e8c;
void FUN_00c998f0()
{
    DAT_01071e8c.FUN_008a8440();
}

// @f3 0x00c8f340 (community match, verified in this file)
struct CleanupObjectC8f340 { void FUN_008a8440(); };
extern CleanupObjectC8f340 DAT_01070068;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSAnimGroupSequence.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00c8f340(){DAT_01070068.FUN_008a8440();}

// @f3 0x00c8abb0 (community match, verified in this file)
namespace f3m_00c8abb0 {
void __cdecl FUN_00d877a0();
void __cdecl FUN_00c8abb0(){FUN_00c00d1f(FUN_00d877a0);}
}   // namespace f3m_00c8abb0

// @f3 0x00c95230 (community match, verified in this file)
struct CleanupB_00c95230 {
    void FUN_008a8440();
};
extern CleanupB_00c95230 DAT_010706cc;
void FUN_00c95230()
{
    DAT_010706cc.FUN_008a8440();
}

// @f3 0x00c8f000 (community match, verified in this file)
namespace f3m_00c8f000 {
void FUN_00d889b0();
void __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
void FUN_00c8f000() { FUN_00c00d1f(FUN_00d889b0); }
}   // namespace f3m_00c8f000

// @f3 0x00c96710 (community match, verified in this file)
struct StaticCleanupA118 { void FUN_008a8440(); };
extern StaticCleanupA118 DAT_01070b0c;
void __cdecl FUN_00c96710() { DAT_01070b0c.FUN_008a8440(); }

// @f3 0x00c97330 (community match, verified in this file)
namespace close_00c97330 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01071531;
}
void FUN_00c97330()
{
    close_00c97330::DAT_01071531.FUN_008a8440();
}

// @f3 0x00c98950 (community match, verified in this file)
struct StaticCleanupA138 { void FUN_008a8440(); };
extern StaticCleanupA138 DAT_01071b0d;
void __cdecl FUN_00c98950() { DAT_01071b0d.FUN_008a8440(); }

// @f3 0x00c985a0 (community match, verified in this file)
namespace f3m_00c985a0 {
namespace register_c985a0 {
void __cdecl FUN_00d89f60();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00c985a0()
{
    register_c985a0::FUN_00c00d1f(register_c985a0::FUN_00d89f60);
}
}   // namespace f3m_00c985a0

// @f3 0x00c98d90 (community match, verified in this file)
namespace close_00c98d90 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01071c98;
}
void FUN_00c98d90()
{
    close_00c98d90::DAT_01071c98.FUN_008a8440();
}

// @f3 0x00c90f30 (community match, verified in this file)
namespace f3_00c90f30 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01070574;
}

void __cdecl FUN_00c90f30() {
    f3_00c90f30::DAT_01070574.FUN_008a8440();
}

// @f3 0x00c8add0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8add0 {

void __cdecl FUN_00d878d0();

void __cdecl FUN_00c8add0() {
    atexit(FUN_00d878d0);
}
}   // namespace f3m_00c8add0

// @f3 0x00c99ca0 (community match, verified in this file)
namespace f3_00c99ca0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01071f60;
}

void __cdecl FUN_00c99ca0() {
    f3_00c99ca0::DAT_01071f60.FUN_008a8440();
}

// @f3 0x00c97da0 (community match, verified in this file)
namespace f3_00c97da0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_010718b0;
}

void __cdecl FUN_00c97da0() {
    f3_00c97da0::DAT_010718b0.FUN_008a8440();
}

// @f3 0x00c9c240 (community match, verified in this file)
struct CleanupB_00c9c240 {
    void FUN_008a8440();
};
extern CleanupB_00c9c240 DAT_01072768;
void FUN_00c9c240()
{
    DAT_01072768.FUN_008a8440();
}

// @f3 0x00c9baa0 (community match, verified in this file)
namespace close_00c9baa0 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01072564;
}
void FUN_00c9baa0()
{
    close_00c9baa0::DAT_01072564.FUN_008a8440();
}

// @f3 0x00c8f0b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f0b0 {

void __cdecl FUN_00d88b00();

void __cdecl FUN_00c8f0b0() {
    atexit(FUN_00d88b00);
}
}   // namespace f3m_00c8f0b0

// @f3 0x00c9aec0 (community match, verified in this file)
namespace f3_00c9aec0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_010722fc;
}

void __cdecl FUN_00c9aec0() {
    f3_00c9aec0::DAT_010722fc.FUN_008a8440();
}

// @f3 0x00c8f040 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f040 {

void __cdecl FUN_00d88b60();

void __cdecl FUN_00c8f040() {
    atexit(FUN_00d88b60);
}
}   // namespace f3m_00c8f040

// @f3 0x00c9c4f0 (community match, verified in this file)
struct Obj01072810
{
    void FUN_008a8440();
};

extern Obj01072810 DAT_01072810;

void FUN_00c9c4f0()
{
    DAT_01072810.FUN_008a8440();
}

// @f3 0x00c9c8a0 (community match, verified in this file)
struct Obj010728ac
{
    void FUN_008a8440();
};

extern Obj010728ac DAT_010728ac;

void FUN_00c9c8a0()
{
    DAT_010728ac.FUN_008a8440();
}

// @f3 0x00c9caa0 (community match, verified in this file)
struct Obj01072924
{
    void FUN_008a8440();
};

extern Obj01072924 DAT_01072924;

void FUN_00c9caa0()
{
    DAT_01072924.FUN_008a8440();
}

// @f3 0x00c9e3d0 (community match, verified in this file)
struct Obj01072fec
{
    void FUN_008a8440();
};

extern Obj01072fec DAT_01072fec;

void FUN_00c9e3d0()
{
    DAT_01072fec.FUN_008a8440();
}

// @f3 0x00c9eda0 (community match, verified in this file)
struct Obj0107306c
{
    void FUN_008a8440();
};

extern Obj0107306c DAT_0107306c;

void FUN_00c9eda0()
{
    DAT_0107306c.FUN_008a8440();
}

// @f3 0x00c9efa0 (community match, verified in this file)
struct Obj010730dc
{
    void FUN_008a8440();
};

extern Obj010730dc DAT_010730dc;

void FUN_00c9efa0()
{
    DAT_010730dc.FUN_008a8440();
}

// @f3 0x00c9f2d0 (community match, verified in this file)
struct Obj01073168
{
    void FUN_008a8440();
};

extern Obj01073168 DAT_01073168;

void FUN_00c9f2d0()
{
    DAT_01073168.FUN_008a8440();
}

// @f3 0x00c9f720 (community match, verified in this file)
struct Obj010731cc
{
    void FUN_008a8440();
};

extern Obj010731cc DAT_010731cc;

void FUN_00c9f720()
{
    DAT_010731cc.FUN_008a8440();
}

// @f3 0x00c82890 (community match, verified in this file)
struct Obj0106c6dc
{
    void FUN_008a8440();
};

extern Obj0106c6dc DAT_0106c6dc;

void FUN_00c82890()
{
    DAT_0106c6dc.FUN_008a8440();
}

// @f3 0x00c83100 (community match, verified in this file)
struct Obj0106c740
{
    void FUN_008a8440();
};

extern Obj0106c740 DAT_0106c740;

void FUN_00c83100()
{
    DAT_0106c740.FUN_008a8440();
}

// @f3 0x00c832d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c832d0 {

namespace f3m_00c832d0 {

void __cdecl FUN_00d86790();

void __cdecl FUN_00c832d0()
{
    atexit(FUN_00d86790);
}

}
}   // namespace f3m_00c832d0

// @f3 0x00c89ed0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c89ed0 {

namespace f3m_00c89ed0 {

void __cdecl FUN_00d876e0();

void __cdecl FUN_00c89ed0()
{
    atexit(FUN_00d876e0);
}

}
}   // namespace f3m_00c89ed0

// @f3 0x00c8adc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8adc0 {

namespace f3m_00c8adc0 {

void __cdecl FUN_00d878c0();

void __cdecl FUN_00c8adc0()
{
    atexit(FUN_00d878c0);
}

}
}   // namespace f3m_00c8adc0

// @f3 0x00c8ae20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8ae20 {

namespace f3m_00c8ae20 {

void __cdecl FUN_00d878f0();

void __cdecl FUN_00c8ae20()
{
    atexit(FUN_00d878f0);
}

}
}   // namespace f3m_00c8ae20

// @f3 0x00c8ae30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8ae30 {

namespace f3m_00c8ae30 {

void __cdecl FUN_00d87930();

void __cdecl FUN_00c8ae30()
{
    atexit(FUN_00d87930);
}

}
}   // namespace f3m_00c8ae30

// @f3 0x00c8d9f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8d9f0 {

namespace f3m_00c8d9f0 {

void __cdecl FUN_00d87e10();

void __cdecl FUN_00c8d9f0()
{
    atexit(FUN_00d87e10);
}

}
}   // namespace f3m_00c8d9f0

// @f3 0x00c8daf0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8daf0 {

namespace f3m_00c8daf0 {

void __cdecl FUN_00d886b0();

void __cdecl FUN_00c8daf0()
{
    atexit(FUN_00d886b0);
}

}
}   // namespace f3m_00c8daf0

// @f3 0x00c8db00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8db00 {

namespace f3m_00c8db00 {

void __cdecl FUN_00d886e0();

void __cdecl FUN_00c8db00()
{
    atexit(FUN_00d886e0);
}

}
}   // namespace f3m_00c8db00

// @f3 0x00c8ee70 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8ee70 {

namespace f3m_00c8ee70 {

void __cdecl FUN_00d88980();

// pdb: `dynamic initializer for 'TimerRenderWater'' | TESWater1.obj | tesv_win, objrun, medium
void __cdecl FUN_00c8ee70()
{
    atexit(FUN_00d88980);
}

}
}   // namespace f3m_00c8ee70

// @f3 0x00c8f010 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f010 {

namespace f3m_00c8f010 {

void __cdecl FUN_00d889e0();

void __cdecl FUN_00c8f010()
{
    atexit(FUN_00d889e0);
}

}
}   // namespace f3m_00c8f010

// @f3 0x00c8f020 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f020 {

namespace f3m_00c8f020 {

void __cdecl FUN_00d88a10();

void __cdecl FUN_00c8f020()
{
    atexit(FUN_00d88a10);
}

}
}   // namespace f3m_00c8f020

// @f3 0x00c8f030 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f030 {

namespace f3m_00c8f030 {

void __cdecl FUN_00d88a40();

void __cdecl FUN_00c8f030()
{
    atexit(FUN_00d88a40);
}

}
}   // namespace f3m_00c8f030

// @f3 0x00c8f050 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f050 {

namespace f3m_00c8f050 {

void __cdecl FUN_00d88b30();

void __cdecl FUN_00c8f050()
{
    atexit(FUN_00d88b30);
}

}
}   // namespace f3m_00c8f050

// @f3 0x00c8f060 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f060 {

namespace f3m_00c8f060 {

void __cdecl FUN_00d88b40();

void __cdecl FUN_00c8f060()
{
    atexit(FUN_00d88b40);
}

}
}   // namespace f3m_00c8f060

// @f3 0x00c8f070 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f070 {

namespace f3m_00c8f070 {

void __cdecl FUN_00d88b50();

void __cdecl FUN_00c8f070()
{
    atexit(FUN_00d88b50);
}

}
}   // namespace f3m_00c8f070

// @f3 0x00c8f580 (community match, verified in this file)
namespace f3m_00c8f580 {

struct Target
{
    void __thiscall FUN_008a8440();
};

extern Target DAT_010700e0;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BGSAddonNode.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00c8f580()
{
    DAT_010700e0.FUN_008a8440();
}

}

// @f3 0x00c99500 (community match, verified in this file)
namespace close_00c99500 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01071e28;
}
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BGSEntryPoint.obj | fnv360_0721_beta, objrun_open, low
void FUN_00c99500()
{
    close_00c99500::DAT_01071e28.FUN_008a8440();
}

// @f3 0x00c96ef0 (community match, verified in this file)
namespace f3m_00c96ef0 {
void __cdecl FUN_00d89b60();
void FUN_00c96ef0()
{
    FUN_00c00d1f(FUN_00d89b60);
}
}   // namespace f3m_00c96ef0

// @f3 0x00c974e0 (community match, verified in this file)
namespace f3m_00c974e0 {
void __cdecl FUN_00d89ce0();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00c974e0() { FUN_00c00d1f(FUN_00d89ce0); }
}   // namespace f3m_00c974e0

// @f3 0x00c9a250 (community match, verified in this file)
namespace f3_00c9a250 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_010720a4;
}

void __cdecl FUN_00c9a250() {
    f3_00c9a250::DAT_010720a4.FUN_008a8440();
}

// @f3 0x00c8fa90 (community match, verified in this file)
struct Obj0107021c
{
    void FUN_008a8440();
};

extern Obj0107021c DAT_0107021c;

void FUN_00c8fa90()
{
    DAT_0107021c.FUN_008a8440();
}

// @f3 0x00c8fcb0 (community match, verified in this file)
struct Obj01070294
{
    void FUN_008a8440();
};

extern Obj01070294 DAT_01070294;

void FUN_00c8fcb0()
{
    DAT_01070294.FUN_008a8440();
}

// @f3 0x00c8fe60 (community match, verified in this file)
struct Obj010702f8
{
    void FUN_008a8440();
};

extern Obj010702f8 DAT_010702f8;

void FUN_00c8fe60()
{
    DAT_010702f8.FUN_008a8440();
}

// @f3 0x00c90010 (community match, verified in this file)
struct Obj01070364
{
    void FUN_008a8440();
};

extern Obj01070364 DAT_01070364;

void FUN_00c90010()
{
    DAT_01070364.FUN_008a8440();
}

// @f3 0x00c901d0 (community match, verified in this file)
struct Obj010703c8
{
    void FUN_008a8440();
};

extern Obj010703c8 DAT_010703c8;

void FUN_00c901d0()
{
    DAT_010703c8.FUN_008a8440();
}

// @f3 0x00c90860 (community match, verified in this file)
struct Obj01070430
{
    void FUN_008a8440();
};

extern Obj01070430 DAT_01070430;

void FUN_00c90860()
{
    DAT_01070430.FUN_008a8440();
}

// @f3 0x00c90cc0 (community match, verified in this file)
struct Obj01070510
{
    void FUN_008a8440();
};

extern Obj01070510 DAT_01070510;

void FUN_00c90cc0()
{
    DAT_01070510.FUN_008a8440();
}

// @f3 0x00c94d60 (community match, verified in this file)
struct Obj010705ec
{
    void FUN_008a8440();
};

extern Obj010705ec DAT_010705ec;

void FUN_00c94d60()
{
    DAT_010705ec.FUN_008a8440();
}

// @f3 0x00c94f70 (community match, verified in this file)
struct Obj01070654
{
    void FUN_008a8440();
};

extern Obj01070654 DAT_01070654;

void FUN_00c94f70()
{
    DAT_01070654.FUN_008a8440();
}

// @f3 0x00c953e0 (community match, verified in this file)
struct Obj010706ee
{
    void FUN_008a8440();
};

extern Obj010706ee DAT_010706ee;

void FUN_00c953e0()
{
    DAT_010706ee.FUN_008a8440();
}

// @f3 0x00c95780 (community match, verified in this file)
struct Obj01070830
{
    void FUN_008a8440();
};

extern Obj01070830 DAT_01070830;

void FUN_00c95780()
{
    DAT_01070830.FUN_008a8440();
}

// @f3 0x00c95930 (community match, verified in this file)
struct Obj010708a0
{
    void FUN_008a8440();
};

extern Obj010708a0 DAT_010708a0;

void FUN_00c95930()
{
    DAT_010708a0.FUN_008a8440();
}

// @f3 0x00c95de0 (community match, verified in this file)
struct Obj0107090c
{
    void FUN_008a8440();
};

extern Obj0107090c DAT_0107090c;

void FUN_00c95de0()
{
    DAT_0107090c.FUN_008a8440();
}

// @f3 0x00c95f90 (community match, verified in this file)
struct Obj01070978
{
    void FUN_008a8440();
};

extern Obj01070978 DAT_01070978;

void FUN_00c95f90()
{
    DAT_01070978.FUN_008a8440();
}

// @f3 0x00c96140 (community match, verified in this file)
struct Obj0107099d
{
    void FUN_008a8440();
};

extern Obj0107099d DAT_0107099d;

void FUN_00c96140()
{
    DAT_0107099d.FUN_008a8440();
}

// @f3 0x00c96500 (community match, verified in this file)
struct Obj01070a90
{
    void FUN_008a8440();
};

extern Obj01070a90 DAT_01070a90;

void FUN_00c96500()
{
    DAT_01070a90.FUN_008a8440();
}

// @f3 0x00c96a10 (community match, verified in this file)
struct Obj01070ba8
{
    void FUN_008a8440();
};

extern Obj01070ba8 DAT_01070ba8;

void FUN_00c96a10()
{
    DAT_01070ba8.FUN_008a8440();
}

// @f3 0x00c96d10 (community match, verified in this file)
struct Obj01071380
{
    void FUN_008a8440();
};

extern Obj01071380 DAT_01071380;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | TESImageSpaceModifier.obj | fnv360_0822_retail, objrun_open, low
void FUN_00c96d10()
{
    DAT_01071380.FUN_008a8440();
}

// @f3 0x00c96ee0 (community match, verified in this file)
struct Obj010714e0
{
    void FUN_008a8440();
};

extern Obj010714e0 DAT_010714e0;

void FUN_00c96ee0()
{
    DAT_010714e0.FUN_008a8440();
}

// @f3 0x00c97710 (community match, verified in this file)
struct Obj0107172c
{
    void FUN_008a8440();
};

extern Obj0107172c DAT_0107172c;

void FUN_00c97710()
{
    DAT_0107172c.FUN_008a8440();
}

// @f3 0x00c97a40 (community match, verified in this file)
struct Obj01071820
{
    void FUN_008a8440();
};

extern Obj01071820 DAT_01071820;

void FUN_00c97a40()
{
    DAT_01071820.FUN_008a8440();
}

// @f3 0x00c981f0 (community match, verified in this file)
struct Obj010719f8
{
    void FUN_008a8440();
};

extern Obj010719f8 DAT_010719f8;

void FUN_00c981f0()
{
    DAT_010719f8.FUN_008a8440();
}

// @f3 0x00c987a0 (community match, verified in this file)
struct Obj01071ab4
{
    void FUN_008a8440();
};

extern Obj01071ab4 DAT_01071ab4;

void FUN_00c987a0()
{
    DAT_01071ab4.FUN_008a8440();
}

// @f3 0x00c98b50 (community match, verified in this file)
struct Obj01071bf8
{
    void FUN_008a8440();
};

extern Obj01071bf8 DAT_01071bf8;

void FUN_00c98b50()
{
    DAT_01071bf8.FUN_008a8440();
}

// @f3 0x00c98f40 (community match, verified in this file)
struct Obj01071d00
{
    void FUN_008a8440();
};

extern Obj01071d00 DAT_01071d00;

void FUN_00c98f40()
{
    DAT_01071d00.FUN_008a8440();
}

// @f3 0x00c990f0 (community match, verified in this file)
struct Obj01071d74
{
    void FUN_008a8440();
};

extern Obj01071d74 DAT_01071d74;

void FUN_00c990f0()
{
    DAT_01071d74.FUN_008a8440();
}

// @f3 0x00c99af0 (community match, verified in this file)
struct Obj01071efc
{
    void FUN_008a8440();
};

extern Obj01071efc DAT_01071efc;

void FUN_00c99af0()
{
    DAT_01071efc.FUN_008a8440();
}

// @f3 0x00c99e50 (community match, verified in this file)
struct Obj01071fc4
{
    void FUN_008a8440();
};

extern Obj01071fc4 DAT_01071fc4;

void FUN_00c99e50()
{
    DAT_01071fc4.FUN_008a8440();
}

// @f3 0x00c9a0a0 (community match, verified in this file)
struct Obj01072040
{
    void FUN_008a8440();
};

extern Obj01072040 DAT_01072040;

void FUN_00c9a0a0()
{
    DAT_01072040.FUN_008a8440();
}

// @f3 0x00c9a820 (community match, verified in this file)
struct Obj0107219c
{
    void FUN_008a8440();
};

extern Obj0107219c DAT_0107219c;

void FUN_00c9a820()
{
    DAT_0107219c.FUN_008a8440();
}

// @f3 0x00c9a9d0 (community match, verified in this file)
struct Obj010721c1
{
    void FUN_008a8440();
};

extern Obj010721c1 DAT_010721c1;

void FUN_00c9a9d0()
{
    DAT_010721c1.FUN_008a8440();
}

// @f3 0x00c9ab80 (community match, verified in this file)
struct Obj01072280
{
    void FUN_008a8440();
};

extern Obj01072280 DAT_01072280;

void FUN_00c9ab80()
{
    DAT_01072280.FUN_008a8440();
}

// @f3 0x00c9b250 (community match, verified in this file)
struct Obj010723d4
{
    void FUN_008a8440();
};

extern Obj010723d4 DAT_010723d4;

void FUN_00c9b250()
{
    DAT_010723d4.FUN_008a8440();
}

// @f3 0x00c9b2b0 (community match, verified in this file)
struct Obj01072448
{
    void FUN_007fbee0();
};

extern Obj01072448 DAT_01072448;

// pdb: `dynamic initializer for 'NiParticleSDMObject'' | Main.obj | tesv_win, objopen_prop, low
void FUN_00c9b2b0()
{
    DAT_01072448.FUN_007fbee0();
}

// @f3 0x00c9b410 (community match, verified in this file)
struct Obj01072449
{
    void FUN_008a8440();
};

extern Obj01072449 DAT_01072449;

void FUN_00c9b410()
{
    DAT_01072449.FUN_008a8440();
}

// @f3 0x00c9b640 (community match, verified in this file)
struct Obj010724dc
{
    void FUN_008a8440();
};

extern Obj010724dc DAT_010724dc;

void FUN_00c9b640()
{
    DAT_010724dc.FUN_008a8440();
}

// @f3 0x00c9bc70 (community match, verified in this file)
struct Obj01072680
{
    void FUN_008a8440();
};

extern Obj01072680 DAT_01072680;

void FUN_00c9bc70()
{
    DAT_01072680.FUN_008a8440();
}

// @f3 0x00c9c040 (community match, verified in this file)
struct Obj010726ec
{
    void FUN_008a8440();
};

extern Obj010726ec DAT_010726ec;

void FUN_00c9c040()
{
    DAT_010726ec.FUN_008a8440();
}

// @f3 0x00c8f0a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f0a0 {
void FUN_00d88ad0();
void FUN_00c8f0a0() { atexit(FUN_00d88ad0); }
}   // namespace f3m_00c8f0a0

// @f3 0x00c98be0 (community match, verified in this file)
namespace f3m_00c98be0 {
void __cdecl FUN_00d89fb0();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00c98be0() { FUN_00c00d1f(FUN_00d89fb0); }
}   // namespace f3m_00c98be0

// @f3 0x00c9cab0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9cab0 {

void __cdecl FUN_00d8a380();

void __cdecl FUN_00c9cab0() {
    atexit(FUN_00d8a380);
}
}   // namespace f3m_00c9cab0

// @f3 0x00c97520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c97520 {

void __cdecl FUN_00d89c90();

void __cdecl FUN_00c97520() {
    atexit(FUN_00d89c90);
}
}   // namespace f3m_00c97520

// @f3 0x00c8f5f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f5f0 {

void __cdecl FUN_00d88e10();

void __cdecl FUN_00c8f5f0() {
    atexit(FUN_00d88e10);
}
}   // namespace f3m_00c8f5f0

// @f3 0x00c98bb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c98bb0 {

void __cdecl FUN_00d89f80();

void __cdecl FUN_00c98bb0() {
    atexit(FUN_00d89f80);
}
}   // namespace f3m_00c98bb0

// @f3 0x00c8f080 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f080 {

void __cdecl FUN_00d88a70();

void __cdecl FUN_00c8f080() {
    atexit(FUN_00d88a70);
}
}   // namespace f3m_00c8f080

// @f3 0x00c8f0c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f0c0 {

void __cdecl FUN_00d88b70();

void __cdecl FUN_00c8f0c0() {
    atexit(FUN_00d88b70);
}
}   // namespace f3m_00c8f0c0

// @f3 0x00c97500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c97500 {

void __cdecl FUN_00d89c80();

void __cdecl FUN_00c97500() {
    atexit(FUN_00d89c80);
}
}   // namespace f3m_00c97500

// @f3 0x00c8f090 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f090 {

void __cdecl FUN_00d88aa0();

void __cdecl FUN_00c8f090() {
    atexit(FUN_00d88aa0);
}
}   // namespace f3m_00c8f090

// @f3 0x00c8f170 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f170 {

void __cdecl FUN_00d88dd0();

void __cdecl FUN_00c8f170() {
    atexit(FUN_00d88dd0);
}
}   // namespace f3m_00c8f170

// @f3 0x00c83520 (community match, verified in this file)
namespace Thunk_00c83520
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106c7e8;

void FUN_00c83520()
{
    DAT_0106c7e8.FUN_008a8440();
}
}

// @f3 0x00c83a70 (community match, verified in this file)
namespace Thunk_00c83a70
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106c8b8;

void FUN_00c83a70()
{
    DAT_0106c8b8.FUN_008a8440();
}
}

// @f3 0x00c84d00 (community match, verified in this file)
namespace Thunk_00c84d00
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106c91c;

void FUN_00c84d00()
{
    DAT_0106c91c.FUN_008a8440();
}
}

// @f3 0x00c84f50 (community match, verified in this file)
namespace Thunk_00c84f50
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106c9d0;

void FUN_00c84f50()
{
    DAT_0106c9d0.FUN_008a8440();
}
}

// @f3 0x00c85110 (community match, verified in this file)
namespace Thunk_00c85110
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106ca34;

void FUN_00c85110()
{
    DAT_0106ca34.FUN_008a8440();
}
}

// @f3 0x00c85a10 (community match, verified in this file)
namespace Thunk_00c85a10
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106cac8;

void FUN_00c85a10()
{
    DAT_0106cac8.FUN_008a8440();
}
}

// @f3 0x00c85c20 (community match, verified in this file)
namespace Thunk_00c85c20
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106ccc8;

void FUN_00c85c20()
{
    DAT_0106ccc8.FUN_008a8440();
}
}

// @f3 0x00c85c30 (community match, verified in this file)
namespace Thunk_00c85c30
{
struct Owner
{
    void FUN_00abab70();
};

extern Owner DAT_0106cafe;

void FUN_00c85c30()
{
    DAT_0106cafe.FUN_00abab70();
}
}

// @f3 0x00c869b0 (community match, verified in this file)
namespace Thunk_00c869b0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106cf94;

void FUN_00c869b0()
{
    DAT_0106cf94.FUN_008a8440();
}
}

// @f3 0x00c86bf0 (community match, verified in this file)
namespace Thunk_00c86bf0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106da18;

void FUN_00c86bf0()
{
    DAT_0106da18.FUN_008a8440();
}
}

// @f3 0x00c86df0 (community match, verified in this file)
namespace Thunk_00c86df0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106da90;

void FUN_00c86df0()
{
    DAT_0106da90.FUN_008a8440();
}
}

// @f3 0x00c86fc0 (community match, verified in this file)
namespace Thunk_00c86fc0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106daf4;

void FUN_00c86fc0()
{
    DAT_0106daf4.FUN_008a8440();
}
}

// @f3 0x00c871e0 (community match, verified in this file)
namespace Thunk_00c871e0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106db6c;

void FUN_00c871e0()
{
    DAT_0106db6c.FUN_008a8440();
}
}

// @f3 0x00c89910 (community match, verified in this file)
namespace Thunk_00c89910
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106dbb5;

void FUN_00c89910()
{
    DAT_0106dbb5.FUN_008a8440();
}
}

// @f3 0x00c89d10 (community match, verified in this file)
namespace Thunk_00c89d10
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106dc78;

void FUN_00c89d10()
{
    DAT_0106dc78.FUN_008a8440();
}
}

// @f3 0x00c89ec0 (community match, verified in this file)
namespace Thunk_00c89ec0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106dcdc;

void FUN_00c89ec0()
{
    DAT_0106dcdc.FUN_008a8440();
}
}

// @f3 0x00c8a360 (community match, verified in this file)
namespace Thunk_00c8a360
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106ddec;

void FUN_00c8a360()
{
    DAT_0106ddec.FUN_008a8440();
}
}

// @f3 0x00c8a8f0 (community match, verified in this file)
namespace Thunk_00c8a8f0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106dfe8;

void FUN_00c8a8f0()
{
    DAT_0106dfe8.FUN_008a8440();
}
}

// @f3 0x00c8adb0 (community match, verified in this file)
namespace Thunk_00c8adb0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106e298;

void FUN_00c8adb0()
{
    DAT_0106e298.FUN_008a8440();
}
}

// @f3 0x00c8b830 (community match, verified in this file)
namespace Thunk_00c8b830
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106e30d;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | Defines.obj | fnv360_0822_retail, objrun_open, low
void FUN_00c8b830()
{
    DAT_0106e30d.FUN_008a8440();
}
}

// @f3 0x00c8bb80 (community match, verified in this file)
namespace Thunk_00c8bb80
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106e914;

void FUN_00c8bb80()
{
    DAT_0106e914.FUN_008a8440();
}
}

// @f3 0x00c8be40 (community match, verified in this file)
namespace Thunk_00c8be40
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106ea04;

void FUN_00c8be40()
{
    DAT_0106ea04.FUN_008a8440();
}
}

// @f3 0x00c8c010 (community match, verified in this file)
namespace Thunk_00c8c010
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106ea70;

void FUN_00c8c010()
{
    DAT_0106ea70.FUN_008a8440();
}
}

// @f3 0x00c8c320 (community match, verified in this file)
namespace Thunk_00c8c320
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106f4c4;

void FUN_00c8c320()
{
    DAT_0106f4c4.FUN_008a8440();
}
}

// @f3 0x00c8c520 (community match, verified in this file)
namespace Thunk_00c8c520
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106f625;

void FUN_00c8c520()
{
    DAT_0106f625.FUN_008a8440();
}
}

// @f3 0x00c8eaf0 (community match, verified in this file)
namespace Thunk_00c8eaf0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_0106fe61;

void FUN_00c8eaf0()
{
    DAT_0106fe61.FUN_008a8440();
}
}

// @f3 0x00c8f5e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c8f5e0 {
namespace f3m_00c8f5e0 {
void __cdecl FUN_00d88de0();
}
void __cdecl FUN_00c8f5e0()
{
    atexit(f3m_00c8f5e0::FUN_00d88de0);
}
}   // namespace f3m_00c8f5e0

// @f3 0x00c90020 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c90020 {
namespace f3m_00c90020 {
void __cdecl FUN_00d88e40();
}
void __cdecl FUN_00c90020()
{
    atexit(f3m_00c90020::FUN_00d88e40);
}
}   // namespace f3m_00c90020

// @f3 0x00c98bc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c98bc0 {
namespace f3m_00c98bc0 {
void __cdecl FUN_00d89f90();
}
void __cdecl FUN_00c98bc0()
{
    atexit(f3m_00c98bc0::FUN_00d89f90);
}
}   // namespace f3m_00c98bc0

// @f3 0x00c98bd0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c98bd0 {
namespace f3m_00c98bd0 {
void __cdecl FUN_00d89fa0();
}
void __cdecl FUN_00c98bd0()
{
    atexit(f3m_00c98bd0::FUN_00d89fa0);
}
}   // namespace f3m_00c98bd0

// @f3 0x00c9ab90 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9ab90 {
namespace f3m_00c9ab90 {
void __cdecl FUN_00d8a0a0();
}
void __cdecl FUN_00c9ab90()
{
    atexit(f3m_00c9ab90::FUN_00d8a0a0);
}
}   // namespace f3m_00c9ab90

// @f3 0x00c9b0a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9b0a0 {
namespace f3m_00c9b0a0 {
void __cdecl FUN_00d8a100();
}
void __cdecl FUN_00c9b0a0()
{
    atexit(f3m_00c9b0a0::FUN_00d8a100);
}
}   // namespace f3m_00c9b0a0

// @f3 0x00c9bab0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9bab0 {
namespace f3m_00c9bab0 {
void __cdecl FUN_00d8a1f0();
}
void __cdecl FUN_00c9bab0()
{
    atexit(f3m_00c9bab0::FUN_00d8a1f0);
}
}   // namespace f3m_00c9bab0

// @f3 0x00c9bac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9bac0 {
namespace f3m_00c9bac0 {
void __cdecl FUN_00d8a230();
}
void __cdecl FUN_00c9bac0()
{
    atexit(f3m_00c9bac0::FUN_00d8a230);
}
}   // namespace f3m_00c9bac0

// @f3 0x00c9be90 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00c9be90 {
namespace f3m_00c9be90 {
void __cdecl FUN_00d8a290();
}
void __cdecl FUN_00c9be90()
{
    atexit(f3m_00c9be90::FUN_00d8a290);
}
}   // namespace f3m_00c9be90

// @f3 0x00c9cc60 (community match, verified in this file)
struct StaticObject_c9cc60 {
    void FUN_008a8440();
};
extern StaticObject_c9cc60 DAT_01072988;

// Runs at program exit: cleans up the file-level object at DAT_01072988.
void __cdecl FUN_00c9cc60() {
    DAT_01072988.FUN_008a8440();
}

// @f3 0x00c9ce10 (community match, verified in this file)
struct StaticObject_c9ce10 {
    void FUN_008a8440();
};
extern StaticObject_c9ce10 DAT_010729ec;

// Runs at program exit: cleans up the file-level object at DAT_010729ec.
void __cdecl FUN_00c9ce10() {
    DAT_010729ec.FUN_008a8440();
}

// @f3 0x00c9cfc0 (community match, verified in this file)
struct StaticObject_c9cfc0 {
    void FUN_008a8440();
};
extern StaticObject_c9cfc0 DAT_01072a60;

// Runs at program exit: cleans up the file-level object at DAT_01072a60.
void __cdecl FUN_00c9cfc0() {
    DAT_01072a60.FUN_008a8440();
}

// @f3 0x00c9de60 (community match, verified in this file)
struct StaticObject_c9de60 {
    void FUN_008a8440();
};
extern StaticObject_c9de60 DAT_01072ea4;

// Runs at program exit: cleans up the file-level object at DAT_01072ea4.
void __cdecl FUN_00c9de60() {
    DAT_01072ea4.FUN_008a8440();
}

// @f3 0x00c9e070 (community match, verified in this file)
struct StaticObject_c9e070 {
    void FUN_008a8440();
};
extern StaticObject_c9e070 DAT_01072f0c;

// Runs at program exit: cleans up the file-level object at DAT_01072f0c.
void __cdecl FUN_00c9e070() {
    DAT_01072f0c.FUN_008a8440();
}

// @f3 0x00c9d1d0 (community match, verified in this file)
// candidate FUN_00c9d1d0 (10B) — cleanup thunk, pack idiom copied verbatim (lesson 25)
namespace f3m_00c9d1d0 {

struct Cleanup9d1d0 { void FUN_008a8440(); };
extern Cleanup9d1d0 DAT_01072b00;

}

void FUN_00c9d1d0() {
    f3m_00c9d1d0::DAT_01072b00.FUN_008a8440();
}
