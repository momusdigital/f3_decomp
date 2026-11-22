// src/f3staging/f3blk_00ce0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00cf4f80 (community match, verified in this file)
struct FUN_006ed270_Stand {
    void FUN_006ed270(const char* name, const char* def);
};
extern FUN_006ed270_Stand g_settings;
extern char g_d973b0;
void FUN_00ec658f(void* p);

// pdb: `dynamic initializer for 'sBasePathS'' | Main.obj | fnv360_0822_debug, ustr, high
void FUN_00cf4f80() {
    g_settings.FUN_006ed270("sBasePath", ".\\");
    FUN_00ec658f(&g_d973b0);
}

// @f3 0x00cf9440 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf9440 {
struct Obj
{
    int unk00;
    void FUN_007fbb00(int a, int b);
};
extern Obj DAT_0107bd18;
void __cdecl FUN_00d97950();
}

// pdb: `dynamic initializer for 'ConflictingPick'' | PlayerCharacter.obj | fnv360_0822_retail, objopen_prop, medium
void __cdecl FUN_00cf9440()
{
    f3m_00cf9440::DAT_0107bd18.FUN_007fbb00(0, 8);
    atexit(f3m_00cf9440::FUN_00d97950);
}

// @f3 0x00ce02f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce02f0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66100;
void __cdecl FUN_00d94b40();

// pdb: `dynamic initializer for 'fUpdateInterval'' | BSTreeNode.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce02f0()
{
    DAT_00f66100.Setting::Setting();
    atexit(FUN_00d94b40);
}
}

// @f3 0x00ce6ef0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6ef0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075d54;
void __cdecl FUN_00d959c0();
}

// pdb: `dynamic initializer for 'iConsoleFont'' | MenuConsole.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6ef0()
{
    f3m_00ce6ef0::DAT_01075d54.FUN_0043b7f0("iConsoleFont:Menu", 2);
    atexit(f3m_00ce6ef0::FUN_00d959c0);
}

// @f3 0x00cf4e90 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4e90 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_0107a254;
void __cdecl FUN_00d97370();
}

// pdb: `dynamic initializer for 'iDebugTextTopBottomOffset'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4e90()
{
    f3m_00cf4e90::DAT_0107a254.FUN_0043b7f0("iDebugTextTopBottomOffset:Display", 10);
    atexit(f3m_00cf4e90::FUN_00d97370);
}

// @f3 0x00ce2220 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2220 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f666a8;
void __cdecl FUN_00d94fa0();

void __cdecl FUN_00ce2220()
{
    DAT_00f666a8.Setting::Setting();
    atexit(FUN_00d94fa0);
}
}

// @f3 0x00ce6f50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6f50 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075d44;
void __cdecl FUN_00d959f0();
}

// pdb: `dynamic initializer for 'iConsoleLineSpacing'' | MenuConsole.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6f50()
{
    f3m_00ce6f50::DAT_01075d44.FUN_0043b7f0("iConsoleLineSpacing:Menu", 35);
    atexit(f3m_00ce6f50::FUN_00d959f0);
}

// @f3 0x00cf4fa0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4fa0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6dddc;
void __cdecl FUN_00d97440();

// pdb: `dynamic initializer for 'pYesText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf4fa0()
{
    DAT_00f6dddc.Setting::Setting();
    atexit(FUN_00d97440);
}
}

// @f3 0x00cf8e10 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf8e10 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_0107bd4c;
void __cdecl FUN_00d97ad0();
}

// pdb: `dynamic initializer for 'iJoystickLookUpDown'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf8e10()
{
    f3m_00cf8e10::DAT_0107bd4c.FUN_0043b7f0("iJoystickLookUpDown:Controls", 6);
    atexit(f3m_00cf8e10::FUN_00d97ad0);
}

// @f3 0x00cf3f00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf3f00 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_01079f04;
void __cdecl FUN_00d96ba0();
}

// pdb: `dynamic initializer for 'BGSMoviePlayer::sMainMenuMovieIntro'' | BGSMoviePlayer.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf3f00()
{
    f3m_00cf3f00::DAT_01079f04.FUN_0043b7f0("sMainMenuMovieIntro:General", "");
    atexit(f3m_00cf3f00::FUN_00d96ba0);
}

// @f3 0x00cfb7a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfb7a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f707dc;
void __cdecl FUN_00d97f20();

void __cdecl FUN_00cfb7a0()
{
    DAT_00f707dc.Setting::Setting();
    atexit(FUN_00d97f20);
}
}

// @f3 0x00cee7d0 (community match, verified in this file)
extern char DAT_010783ec;
namespace f3m_00cee7d0 {
namespace f3m_00cee7d0 {
void __cdecl FUN_006a8370();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cee7d0()
{
    using namespace f3m_00cee7d0;
    DAT_010783ec = FUN_00401db0(0xb, FUN_006a8370);
}
}   // namespace f3m_00cee7d0

// @f3 0x00ce61f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce61f0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, unsigned int a1);
};
extern Setting DAT_010758f8;
void __cdecl FUN_00d956e0();
}

// pdb: `dynamic initializer for 'uTerrainTextureFadeTime'' | BGSTerrainNode.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce61f0()
{
    f3m_00ce61f0::DAT_010758f8.FUN_0043b7f0("uTerrainTextureFadeTime:TerrainManager", 1000u);
    atexit(f3m_00ce61f0::FUN_00d956e0);
}

// @f3 0x00cf4620 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4620 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107a3b0;
void __cdecl FUN_00d96fb0();
}

// pdb: `dynamic initializer for 'sUnessentialFileCacheList'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4620()
{
    f3m_00cf4620::DAT_0107a3b0.FUN_0043b7f0("sUnessentialFileCacheList:General", "Data\\Fallout - Meshes.bsa, Data\\Fallout - Textures.bsa");
    atexit(f3m_00cf4620::FUN_00d96fb0);
}

// @f3 0x00ce69e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce69e0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075bdc;
void __cdecl FUN_00d95820();
}

// pdb: `dynamic initializer for 'iXenonMenuStickDeadZone'' | InterfaceManager.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce69e0()
{
    f3m_00ce69e0::DAT_01075bdc.FUN_0043b7f0("iXenonMenuStickDeadZone:Controls", 20000);
    atexit(f3m_00ce69e0::FUN_00d95820);
}

// @f3 0x00ce0290 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0290 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f660f4;
void __cdecl FUN_00d94b30();

// pdb: `dynamic initializer for 'iNumGroups'' | BSTreeNode.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce0290()
{
    DAT_00f660f4.Setting::Setting();
    atexit(FUN_00d94b30);
}
}

// @f3 0x00ce0ac0 (community match, verified in this file)
#include <stdlib.h>
struct Manager2 { virtual void v00(); virtual void Register(void* setting); };
extern Manager2* DAT_010701a8;
void __cdecl FUN_00403080();
struct Cleanup2 { void FUN_00403170(); __forceinline ~Cleanup2() { FUN_00403170(); } };
struct Setting2 : Cleanup2 { __forceinline Setting2() { FUN_00403080(); DAT_010701a8->Register(this); } };
extern Setting2 DAT_00f66334;
void __cdecl FUN_00d94c40();

void FUN_00ce0ac0()
{
    DAT_00f66334.Setting2::Setting2();
    atexit(FUN_00d94c40);
}

// @f3 0x00ce1e00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1e00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66624;
void __cdecl FUN_00d94ef0();

void __cdecl FUN_00ce1e00()
{
    DAT_00f66624.Setting::Setting();
    atexit(FUN_00d94ef0);
}
}

// @f3 0x00cf4e50 (community match, verified in this file)
#include <stdlib.h>
struct DebugTextStandIn { void FUN_0043b7f0(const char* name, const char* value); };
extern DebugTextStandIn DAT_0107a38c;
void __cdecl FUN_00d97350();

// pdb: `dynamic initializer for 'sDebugText'' | Main.obj | fnv360_0822_debug, ustr, high
void FUN_00cf4e50()
{
    DAT_0107a38c.FUN_0043b7f0("sDebugText:Display", "VATS");
    atexit(FUN_00d97350);
}

// @f3 0x00ce0b80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0b80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6634c;
void __cdecl FUN_00d94c60();

void __cdecl FUN_00ce0b80()
{
    DAT_00f6634c.Setting::Setting();
    atexit(FUN_00d94c60);
}
}

// @f3 0x00ce2bb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2bb0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f668d8;
void __cdecl FUN_00d950f0();

void __cdecl FUN_00ce2bb0()
{
    DAT_00f668d8.Setting::Setting();
    atexit(FUN_00d950f0);
}
}

// @f3 0x00ce2c70 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2c70 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f668f0;
void __cdecl FUN_00d95110();

void __cdecl FUN_00ce2c70()
{
    DAT_00f668f0.Setting::Setting();
    atexit(FUN_00d95110);
}
}

// @f3 0x00cf8be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf8be0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107bc54;
void __cdecl FUN_00d97a00();
}

// pdb: `dynamic initializer for 'sTrackProgressPath'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf8be0()
{
    f3m_00cf8be0::DAT_0107bc54.FUN_0043b7f0("sTrackProgressPath:GamePlay", "\\\\vault2\\Fallout\\LevelData\\");
    atexit(f3m_00cf8be0::FUN_00d97a00);
}

// @f3 0x00ce0be0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0be0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66358;
void __cdecl FUN_00d94c70();

void __cdecl FUN_00ce0be0()
{
    DAT_00f66358.Setting::Setting();
    atexit(FUN_00d94c70);
}
}

// @f3 0x00cf0890 (community match, verified in this file)
extern char DAT_01078b3c;
namespace f3m_00cf0890 {
namespace f3m_00cf0890 {
void __cdecl FUN_006ba560();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf0890()
{
    using namespace f3m_00cf0890;
    DAT_01078b3c = FUN_00401db0(5, FUN_006ba560);
}
}   // namespace f3m_00cf0890

// @f3 0x00ce0dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0dc0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66394;
void __cdecl FUN_00d94cc0();

void __cdecl FUN_00ce0dc0()
{
    DAT_00f66394.Setting::Setting();
    atexit(FUN_00d94cc0);
}
}

// @f3 0x00cf8b60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf8b60 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_0107bc90;
void __cdecl FUN_00d979c0();
}

// pdb: `dynamic initializer for 'iActorsDismemberedPerFrame'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf8b60()
{
    f3m_00cf8b60::DAT_0107bc90.FUN_0043b7f0("iActorsDismemberedPerFrame:GamePlay", 2);
    atexit(f3m_00cf8b60::FUN_00d979c0);
}

// @f3 0x00ced910 (community match, verified in this file)
extern char DAT_0107808e;
namespace f3m_00ced910 {
namespace f3m_00ced910 {
void __cdecl FUN_006a6980();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced910()
{
    using namespace f3m_00ced910;
    DAT_0107808e = FUN_00401db0(30, FUN_006a6980);
}
}   // namespace f3m_00ced910

// @f3 0x00ce0520 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0520 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66280;
void __cdecl FUN_00d94b50();

void __cdecl FUN_00ce0520()
{
    DAT_00f66280.Setting::Setting();
    atexit(FUN_00d94b50);
}
}

// @f3 0x00ce0a00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0a00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6631c;
void __cdecl FUN_00d94c20();

void __cdecl FUN_00ce0a00()
{
    DAT_00f6631c.Setting::Setting();
    atexit(FUN_00d94c20);
}
}

// @f3 0x00ced930 (community match, verified in this file)
extern char DAT_010780dc;
namespace f3m_00ced930 {
namespace f3m_00ced930 {
void __cdecl FUN_006a6a10();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced930()
{
    using namespace f3m_00ced930;
    DAT_010780dc = FUN_00401db0(31, FUN_006a6a10);
}
}   // namespace f3m_00ced930

// @f3 0x00ce6c50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6c50 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075c50;
void __cdecl FUN_00d95900();
}

// pdb: `dynamic initializer for 'iSafeZoneX'' | InterfaceManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6c50()
{
    f3m_00ce6c50::DAT_01075c50.FUN_0043b7f0("iSafeZoneX:Interface", 15);
    atexit(f3m_00ce6c50::FUN_00d95900);
}

// @f3 0x00cf4980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4980 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107a1b4;
void __cdecl FUN_00d97160();
}

// pdb: `dynamic initializer for 'sCameraPathDir'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4980()
{
    f3m_00cf4980::DAT_0107a1b4.FUN_0043b7f0("sDirectoryName:CameraPath", "TestCameraPath");
    atexit(f3m_00cf4980::FUN_00d97160);
}

// @f3 0x00ce0b20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0b20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66340;
void __cdecl FUN_00d94c50();

void __cdecl FUN_00ce0b20()
{
    DAT_00f66340.Setting::Setting();
    atexit(FUN_00d94c50);
}
}

// @f3 0x00ce31e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce31e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66bd4;
void __cdecl FUN_00d95140();

void __cdecl FUN_00ce31e0()
{
    DAT_00f66bd4.Setting::Setting();
    atexit(FUN_00d95140);
}
}

// @f3 0x00cf6cf0 (community match, verified in this file)
#include <stdlib.h>
struct _RTL_CRITICAL_SECTION { void* DebugInfo; long LockCount; long RecursionCount; void* OwningThread; void* LockSemaphore; unsigned long SpinCount; };
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(_RTL_CRITICAL_SECTION* cs);
namespace f3m_00cf6cf0 {
extern _RTL_CRITICAL_SECTION DAT_0107b080;
extern int DAT_0107b0c0;
extern int DAT_0107b0c4;
void __cdecl FUN_00d977c0();
}

void __cdecl FUN_00cf6cf0()
{
    using namespace f3m_00cf6cf0;
    InitializeCriticalSection(&DAT_0107b080);
    DAT_0107b0c0 = 0;
    DAT_0107b0c4 = 0;
    atexit(FUN_00d977c0);
}

// @f3 0x00cea620 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea620 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6b6a8;
void __cdecl FUN_00d96230();

void __cdecl FUN_00cea620()
{
    DAT_00f6b6a8.Setting::Setting();
    atexit(FUN_00d96230);
}
}

// @f3 0x00ce1d40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1d40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6660c;
void __cdecl FUN_00d94ed0();

void __cdecl FUN_00ce1d40()
{
    DAT_00f6660c.Setting::Setting();
    atexit(FUN_00d94ed0);
}
}

// @f3 0x00cfe050 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfe050 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f70e00;
void __cdecl FUN_00d98020();

void __cdecl FUN_00cfe050()
{
    DAT_00f70e00.Setting::Setting();
    atexit(FUN_00d98020);
}
}

// @f3 0x00ce08e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce08e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f662f8;
void __cdecl FUN_00d94bf0();

void __cdecl FUN_00ce08e0()
{
    DAT_00f662f8.Setting::Setting();
    atexit(FUN_00d94bf0);
}
}

// @f3 0x00ce6f30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6f30 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075d34;
void __cdecl FUN_00d959e0();
}

// pdb: `dynamic initializer for 'iConsoleTextYPos'' | MenuConsole.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6f30()
{
    f3m_00ce6f30::DAT_01075d34.FUN_0043b7f0("iConsoleTextYPos:Menu", 940);
    atexit(f3m_00ce6f30::FUN_00d959e0);
}

// @f3 0x00ce1550 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1550 {
struct Block { int m_data[0x49]; };
extern Block DAT_01073eb8;
void __cdecl FUN_00d94d80();
}
using namespace f3m_00ce1550;

void __cdecl FUN_00ce1550()
{
    for (int i = 0; i < 0x49; i++) DAT_01073eb8.m_data[i] = 0;
    atexit(FUN_00d94d80);
}

// @f3 0x00ce09a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce09a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66310;
void __cdecl FUN_00d94c10();

void __cdecl FUN_00ce09a0()
{
    DAT_00f66310.Setting::Setting();
    atexit(FUN_00d94c10);
}
}

// @f3 0x00cf4800 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4800 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107a500;
void __cdecl FUN_00d970a0();
}

// pdb: `dynamic initializer for 'sStartingCellX'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4800()
{
    f3m_00cf4800::DAT_0107a500.FUN_0043b7f0("sStartingCellX:General", "");
    atexit(f3m_00cf4800::FUN_00d970a0);
}

// @f3 0x00cf11a0 (community match, verified in this file)
extern char DAT_01078cfc;
namespace f3m_00cf11a0 {
namespace f3m_00cf11a0 {
void __cdecl FUN_006bc770();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf11a0()
{
    using namespace f3m_00cf11a0;
    DAT_01078cfc = FUN_00401db0(34, FUN_006bc770);
}
}   // namespace f3m_00cf11a0

// @f3 0x00ce87a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce87a0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_010769e0;
void __cdecl FUN_00d95ba0();
}

// pdb: `dynamic initializer for 'LoadingMenu::sTitleMusic'' | LoadingMenu.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce87a0()
{
    f3m_00ce87a0::DAT_010769e0.FUN_0043b7f0("sTitleMusic:Loading", "MainTitle");
    atexit(f3m_00ce87a0::FUN_00d95ba0);
}

// @f3 0x00cf3280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf3280 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_01079b20;
void __cdecl FUN_00d96b10();
}

// pdb: `dynamic initializer for 'sSaveGameSafeMarkerID'' | BGSSaveLoadManager.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf3280()
{
    f3m_00cf3280::DAT_01079b20.FUN_0043b7f0("sSaveGameSafeMarkerID:SaveGame", "32D4");
    atexit(f3m_00cf3280::FUN_00d96b10);
}

// @f3 0x00ce0f40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0f40 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f663c4;
void __cdecl FUN_00d94d00();

void __cdecl FUN_00ce0f40()
{
    DAT_00f663c4.Setting::Setting();
    atexit(FUN_00d94d00);
}
}

// @f3 0x00ced000 (community match, verified in this file)
extern char DAT_01077eb0;
namespace f3m_00ced000 {
namespace f3m_00ced000 {
void __cdecl FUN_006a5e90();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced000()
{
    using namespace f3m_00ced000;
    DAT_01077eb0 = FUN_00401db0(12, FUN_006a5e90);
}
}   // namespace f3m_00ced000

// @f3 0x00ce2460 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2460 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f666f0;
void __cdecl FUN_00d95000();

void __cdecl FUN_00ce2460()
{
    DAT_00f666f0.Setting::Setting();
    atexit(FUN_00d95000);
}
}

// @f3 0x00ce1c20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1c20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f665e8;
void __cdecl FUN_00d94ea0();

void __cdecl FUN_00ce1c20()
{
    DAT_00f665e8.Setting::Setting();
    atexit(FUN_00d94ea0);
}
}

// @f3 0x00ce26a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce26a0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66738;
void __cdecl FUN_00d95060();

void __cdecl FUN_00ce26a0()
{
    DAT_00f66738.Setting::Setting();
    atexit(FUN_00d95060);
}
}

// @f3 0x00cf4ce0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4ce0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107a528;
void __cdecl FUN_00d972a0();
}

// pdb: `dynamic initializer for 'sCopyProtectionMessage'' | Main.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf4ce0()
{
    f3m_00cf4ce0::DAT_0107a528.FUN_0043b7f0("sCopyProtectionMessage:CopyProtectionStrings", "Unable to find a CD-ROM/DVD drive on this computer.");
    atexit(f3m_00cf4ce0::FUN_00d972a0);
}

// @f3 0x00cf6070 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf6070 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_0107adcc;
void __cdecl FUN_00d97640();
}

// pdb: `dynamic initializer for 'iDetectionPicks'' | Actor.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf6070()
{
    f3m_00cf6070::DAT_0107adcc.FUN_0043b7f0("iDetectionPicks:GamePlay", 21);
    atexit(f3m_00cf6070::FUN_00d97640);
}

// @f3 0x00ce0820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0820 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f662e0;
void __cdecl FUN_00d94bd0();

void __cdecl FUN_00ce0820()
{
    DAT_00f662e0.Setting::Setting();
    atexit(FUN_00d94bd0);
}
}

// @f3 0x00ce2700 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2700 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66744;
void __cdecl FUN_00d95070();

void __cdecl FUN_00ce2700()
{
    DAT_00f66744.Setting::Setting();
    atexit(FUN_00d95070);
}
}

// @f3 0x00ced950 (community match, verified in this file)
extern char DAT_0107808d;
namespace f3m_00ced950 {
namespace f3m_00ced950 {
void __cdecl FUN_006a6a90();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced950()
{
    using namespace f3m_00ced950;
    DAT_0107808d = FUN_00401db0(32, FUN_006a6a90);
}
}   // namespace f3m_00ced950

// @f3 0x00cfbf80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfbf80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f70928;
void __cdecl FUN_00d97f50();

void __cdecl FUN_00cfbf80()
{
    DAT_00f70928.Setting::Setting();
    atexit(FUN_00d97f50);
}
}

// @f3 0x00ce2400 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2400 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f666e4;
void __cdecl FUN_00d94ff0();

void __cdecl FUN_00ce2400()
{
    DAT_00f666e4.Setting::Setting();
    atexit(FUN_00d94ff0);
}
}

// @f3 0x00ce8ad0 (community match, verified in this file)
extern int DAT_01076b5c;
extern int DAT_01076b60;
extern int DAT_01076b64;
extern int DAT_01076b68;
extern int DAT_01076b6c;
extern int DAT_01076b70;
namespace f3m_00ce8ad0 {
namespace f3m_00ce8ad0 {
int __cdecl FUN_0041cdf0(int index);

// pdb: `dynamic initializer for 'LockPickMenu::ciMinSkillRequiredA'' | LockPickMenu.obj | fnv360_0822_retail, objrun_prop, low
void __cdecl FUN_00ce8ad0()
{
    DAT_01076b5c = FUN_0041cdf0(0);
    DAT_01076b60 = FUN_0041cdf0(1);
    DAT_01076b64 = FUN_0041cdf0(2);
    DAT_01076b68 = FUN_0041cdf0(3);
    DAT_01076b6c = FUN_0041cdf0(4);
    DAT_01076b70 = 0x65;
}
}
}   // namespace f3m_00ce8ad0

// @f3 0x00ce2b50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2b50 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f668cc;
void __cdecl FUN_00d950e0();

void __cdecl FUN_00ce2b50()
{
    DAT_00f668cc.Setting::Setting();
    atexit(FUN_00d950e0);
}
}

// @f3 0x00cee090 (community match, verified in this file)
extern char DAT_0107825c;
namespace f3m_00cee090 {
namespace f3m_00cee090 {
void __cdecl FUN_006a76a0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cee090()
{
    using namespace f3m_00cee090;
    DAT_0107825c = FUN_00401db0(22, FUN_006a76a0);
}
}   // namespace f3m_00cee090

// @f3 0x00cee260 (community match, verified in this file)
extern char DAT_01078290;
namespace f3m_00cee260 {
namespace f3m_00cee260 {
void __cdecl FUN_006a7a40();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cee260()
{
    using namespace f3m_00cee260;
    DAT_01078290 = FUN_00401db0(23, FUN_006a7a40);
}
}   // namespace f3m_00cee260

// @f3 0x00ce9bb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9bb0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_01077188;
void __cdecl FUN_00d95f60();
}

// pdb: `dynamic initializer for 'sCharGenQuest'' | StartMenu.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'sCharGenQuest_G'')
void __cdecl FUN_00ce9bb0()
{
    f3m_00ce9bb0::DAT_01077188.FUN_0043b7f0("sCharGenQuest:General", "00014E85");
    atexit(f3m_00ce9bb0::FUN_00d95f60);
}

// @f3 0x00ce2280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2280 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f666b4;
void __cdecl FUN_00d94fb0();

void __cdecl FUN_00ce2280()
{
    DAT_00f666b4.Setting::Setting();
    atexit(FUN_00d94fb0);
}
}

// @f3 0x00ce0940 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0940 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66304;
void __cdecl FUN_00d94c00();

void __cdecl FUN_00ce0940()
{
    DAT_00f66304.Setting::Setting();
    atexit(FUN_00d94c00);
}
}

// @f3 0x00cf0c30 (community match, verified in this file)
extern char DAT_01078be4;
namespace f3m_00cf0c30 {
namespace f3m_00cf0c30 {
void __cdecl FUN_006bb0b0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf0c30()
{
    using namespace f3m_00cf0c30;
    DAT_01078be4 = FUN_00401db0(28, FUN_006bb0b0);
}
}   // namespace f3m_00cf0c30

// @f3 0x00ce1b00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1b00 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f665c4;
void __cdecl FUN_00d94e70();

void __cdecl FUN_00ce1b00()
{
    DAT_00f665c4.Setting::Setting();
    atexit(FUN_00d94e70);
}
}

// @f3 0x00ce0e80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0e80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f663ac;
void __cdecl FUN_00d94ce0();

void __cdecl FUN_00ce0e80()
{
    DAT_00f663ac.Setting::Setting();
    atexit(FUN_00d94ce0);
}
}

// @f3 0x00cf4eb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4eb0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_0107a534;
void __cdecl FUN_00d97380();
}

// pdb: `dynamic initializer for 'iDebugTextLeftRightOffset'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4eb0()
{
    f3m_00cf4eb0::DAT_0107a534.FUN_0043b7f0("iDebugTextLeftRightOffset:Display", 10);
    atexit(f3m_00cf4eb0::FUN_00d97380);
}

// @f3 0x00ce15c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce15c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6651c;
void __cdecl FUN_00d94d90();

void __cdecl FUN_00ce15c0()
{
    DAT_00f6651c.Setting::Setting();
    atexit(FUN_00d94d90);
}
}

// @f3 0x00ce16e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce16e0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66540;
void __cdecl FUN_00d94dc0();

void __cdecl FUN_00ce16e0()
{
    DAT_00f66540.Setting::Setting();
    atexit(FUN_00d94dc0);
}
}

// @f3 0x00cfbf20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfbf20 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f7091c;
void __cdecl FUN_00d97f40();

void __cdecl FUN_00cfbf20()
{
    DAT_00f7091c.Setting::Setting();
    atexit(FUN_00d97f40);
}
}

// @f3 0x00ce1f80 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1f80 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66654;
void __cdecl FUN_00d94f30();

void __cdecl FUN_00ce1f80()
{
    DAT_00f66654.Setting::Setting();
    atexit(FUN_00d94f30);
}
}

// @f3 0x00cf06c0 (community match, verified in this file)
extern char DAT_01078ae4;
namespace f3m_00cf06c0 {
namespace f3m_00cf06c0 {
void __cdecl FUN_006b9eb0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf06c0()
{
    using namespace f3m_00cf06c0;
    DAT_01078ae4 = FUN_00401db0(1, FUN_006b9eb0);
}
}   // namespace f3m_00cf06c0

// @f3 0x00ce2160 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2160 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66690;
void __cdecl FUN_00d94f80();

void __cdecl FUN_00ce2160()
{
    DAT_00f66690.Setting::Setting();
    atexit(FUN_00d94f80);
}
}

// @f3 0x00cf3f20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf3f20 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_01079ee4;
void __cdecl FUN_00d96bb0();
}

// pdb: `dynamic initializer for 'BGSMoviePlayer::sIntroMovie'' | BGSMoviePlayer.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf3f20()
{
    f3m_00cf3f20::DAT_01079ee4.FUN_0043b7f0("sIntroMovie:General", "");
    atexit(f3m_00cf3f20::FUN_00d96bb0);
}

// @f3 0x00cf47e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf47e0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, const char* a1);
};
extern Setting DAT_0107a1f0;
void __cdecl FUN_00d97090();
}

// pdb: `dynamic initializer for 'sStartingWorld'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf47e0()
{
    f3m_00cf47e0::DAT_0107a1f0.FUN_0043b7f0("sStartingWorld:General", "");
    atexit(f3m_00cf47e0::FUN_00d97090);
}

// @f3 0x00cefee0 (community match, verified in this file)
extern char DAT_01078914;
namespace f3m_00cefee0 {
namespace f3m_00cefee0 {
void __cdecl FUN_006b86f0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cefee0()
{
    using namespace f3m_00cefee0;
    DAT_01078914 = FUN_00401db0(15, FUN_006b86f0);
}
}   // namespace f3m_00cefee0

// @f3 0x00cf0e00 (community match, verified in this file)
extern char DAT_01078c4c;
namespace f3m_00cf0e00 {
namespace f3m_00cf0e00 {
void __cdecl FUN_006bbd90();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf0e00()
{
    using namespace f3m_00cf0e00;
    DAT_01078c4c = FUN_00401db0(21, FUN_006bbd90);
}
}   // namespace f3m_00cf0e00

// @f3 0x00ce0880 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0880 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f662ec;
void __cdecl FUN_00d94be0();

void __cdecl FUN_00ce0880()
{
    DAT_00f662ec.Setting::Setting();
    atexit(FUN_00d94be0);
}
}

// @f3 0x00ce6c90 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6c90 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01075c74;
void __cdecl FUN_00d95920();
}

// pdb: `dynamic initializer for 'iSafeZoneXWide'' | InterfaceManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6c90()
{
    f3m_00ce6c90::DAT_01075c74.FUN_0043b7f0("iSafeZoneXWide:Interface", 15);
    atexit(f3m_00ce6c90::FUN_00d95920);
}

// @f3 0x00ce2c10 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2c10 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f668e4;
void __cdecl FUN_00d95100();

void __cdecl FUN_00ce2c10()
{
    DAT_00f668e4.Setting::Setting();
    atexit(FUN_00d95100);
}
}

// @f3 0x00cf4820 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4820 {
struct Obj {
    int unk00;
    void FUN_0043b7f0(int a, void (__cdecl *b)());
};
extern Obj DAT_0107a26c;
void __cdecl FUN_00db3438();
void __cdecl FUN_00d970b0();
}
// pdb: `dynamic initializer for 'sStartingCellY'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4820()
{
    f3m_00cf4820::DAT_0107a26c.FUN_0043b7f0(0xe118a8, f3m_00cf4820::FUN_00db3438);
    atexit(f3m_00cf4820::FUN_00d970b0);
}

// @f3 0x00ce1000 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1000 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f663dc;
void __cdecl FUN_00d94d20();
}

void __cdecl FUN_00ce1000()
{
    f3m_00ce1000::DAT_00f663dc.f3m_00ce1000::Setting::Setting();
    atexit(f3m_00ce1000::FUN_00d94d20);
}

// @f3 0x00cf92f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf92f0 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, unsigned int a1);
};
extern Setting DAT_0107bb24;
extern const char DAT_00e18f44[];
void __cdecl FUN_00d97ca0();
}
// pdb: `dynamic initializer for 'iXenonVertLookAccel'' | PlayerCharacter.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00cf92f0()
{
    f3m_00cf92f0::DAT_0107bb24.FUN_0043b7f0(f3m_00cf92f0::DAT_00e18f44, 2u);
    atexit(f3m_00cf92f0::FUN_00d97ca0);
}

// @f3 0x00cf4df0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4df0 {
struct Obj { int unk00; void FUN_0043b7f0(const char* a, const char* b); };
extern Obj DAT_0107a308;
extern const char DAT_00e11e24[];
extern const char DAT_00e11e40[];
void __cdecl FUN_00d97320();
}
// pdb: `dynamic initializer for 'sArchiveInvalidationFile'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4df0()
{
    f3m_00cf4df0::DAT_0107a308.FUN_0043b7f0(f3m_00cf4df0::DAT_00e11e24, f3m_00cf4df0::DAT_00e11e40);
    atexit(f3m_00cf4df0::FUN_00d97320);
}

// @f3 0x00cf02b0 (community match, verified in this file)
extern char DAT_01078a05;
namespace f3m_00cf02b0 {
char __cdecl FUN_00401db0(int a, void (*f)());
void FUN_006b8f80();
void FUN_00cf02b0()
{
    DAT_01078a05 = FUN_00401db0(0x11, FUN_006b8f80);
}
}   // namespace f3m_00cf02b0

// @f3 0x00ce6ed0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6ed0 {
struct Obj
{
    int unk00;
    void FUN_0043b7f0(const void* a, int b);
};
extern Obj DAT_01075d28;
extern char DAT_00e04530;
void __cdecl FUN_00d959b0();
}
// pdb: `dynamic initializer for 'iConsoleVisibleLines'' | MenuConsole.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6ed0()
{
    f3m_00ce6ed0::DAT_01075d28.FUN_0043b7f0(&f3m_00ce6ed0::DAT_00e04530, 15);
    atexit(f3m_00ce6ed0::FUN_00d959b0);
}

// @f3 0x00cee600 (community match, verified in this file)
extern bool DAT_01078344;
namespace f3m_00cee600 {
bool __cdecl FUN_00401db0(int a, void (__cdecl* f)());
void __cdecl FUN_006a7ee0();
void __cdecl FUN_00cee600()
{
    DAT_01078344 = FUN_00401db0(8, FUN_006a7ee0);
}
}   // namespace f3m_00cee600

// @f3 0x00ce1980 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1980 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66594;
void __cdecl FUN_00d94e30();
}
void __cdecl FUN_00ce1980()
{
    using namespace f3m_00ce1980;
    DAT_00f66594.Setting::Setting();
    atexit(FUN_00d94e30);
}

// @f3 0x00cfb800 (community match, verified in this file)
extern Setting2 DAT_00f707e8;
namespace f3m_00cfb800 {

void FUN_00c00d1f(void (*fn)()) throw();
void FUN_00d97f30();

void __cdecl FUN_00cfb800()
{
    DAT_00f707e8.Setting2::Setting2();
    FUN_00c00d1f(FUN_00d97f30);
}
}   // namespace f3m_00cfb800

// @f3 0x00cf46c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf46c0 {
struct Obj { int unk00; void FUN_0043b7f0(int a, void (__cdecl *fn)()); };
extern Obj DAT_0107a510;
void __cdecl FUN_00db3438();
void __cdecl FUN_00d97000();
}
// pdb: `dynamic initializer for 'sTestFile4'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf46c0()
{
    f3m_00cf46c0::DAT_0107a510.FUN_0043b7f0(0xe117b4, f3m_00cf46c0::FUN_00db3438);
    atexit(f3m_00cf46c0::FUN_00d97000);
}

// @f3 0x00ce2af0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2af0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f668c0;
void __cdecl FUN_00d950d0();
}
void __cdecl FUN_00ce2af0()
{
    f3m_00ce2af0::DAT_00f668c0.f3m_00ce2af0::Setting::Setting();
    atexit(f3m_00ce2af0::FUN_00d950d0);
}

// @f3 0x00ce0170 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce0170 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f660d0;
void __cdecl FUN_00d94b00();

// pdb: `dynamic initializer for 'iCollFreq'' | BSTreeNode.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce0170()
{
    DAT_00f660d0.Setting::Setting();
    atexit(FUN_00d94b00);
}
}

// @f3 0x00ce01d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_ce01d0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f660dc;
void __cdecl FUN_00d94b10();

// pdb: `dynamic initializer for 'iLowDamp'' | BSTreeNode.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce01d0()
{
    DAT_00f660dc.Setting::Setting();
    atexit(FUN_00d94b10);
}
}

// @f3 0x00cf4720 (community match, verified in this file)
#include <stdlib.h>
struct Obj {
    int unk00;
    void FUN_0043b7f0(int a, void (__cdecl* fn)());
};
extern Obj DAT_0107a398;
void __cdecl FUN_00db3438();
void __cdecl FUN_00d97030();

// pdb: `dynamic initializer for 'sTestFile7'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4720()
{
    DAT_0107a398.FUN_0043b7f0(0xe117f0, FUN_00db3438);
    atexit(FUN_00d97030);
}

// @f3 0x00cf5120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5120 {
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

extern Setting DAT_00f6de0c;
void __cdecl FUN_00d97480();
}

// pdb: `dynamic initializer for 'pRetryText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf5120()
{
    using namespace f3m_00cf5120;
    DAT_00f6de0c.Setting::Setting();
    atexit(FUN_00d97480);
}

// @f3 0x00ce1da0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1da0 {
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

extern Setting DAT_00f66618;
void __cdecl FUN_00d94ee0();
}

void __cdecl FUN_00ce1da0()
{
    using namespace f3m_00ce1da0;
    DAT_00f66618.Setting::Setting();
    atexit(FUN_00d94ee0);
}

// @f3 0x00cf4d20 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4d20 {
struct Obj { int unk00; void FUN_0043b7f0(const char* a, const char* b); };
extern Obj DAT_0107a260;
extern char DAT_00e11d24[];
extern char DAT_00e11d54[];
void __cdecl FUN_00d972c0();
}
// pdb: `dynamic initializer for 'sCopyProtectionMessage2'' | Main.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf4d20()
{
    f3m_00cf4d20::DAT_0107a260.FUN_0043b7f0(f3m_00cf4d20::DAT_00e11d24, f3m_00cf4d20::DAT_00e11d54);
    atexit(f3m_00cf4d20::FUN_00d972c0);
}

// @f3 0x00ce0760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0760 {
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

extern Setting DAT_00f662c8;
void __cdecl FUN_00d94bb0();
}

void __cdecl FUN_00ce0760()
{
    using namespace f3m_00ce0760;
    DAT_00f662c8.Setting::Setting();
    atexit(FUN_00d94bb0);
}

// @f3 0x00cf47a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf47a0 {
struct Obj { int unk00; void FUN_0043b7f0(const char* a, void (__cdecl* b)()); };
extern Obj DAT_0107a3dc;
extern char DAT_00e11840[];
void __cdecl FUN_00db3438();
void __cdecl FUN_00d97070();
}
// pdb: `dynamic initializer for 'sStartingCell'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf47a0()
{
    f3m_00cf47a0::DAT_0107a3dc.FUN_0043b7f0(f3m_00cf47a0::DAT_00e11840, f3m_00cf47a0::FUN_00db3438);
    atexit(f3m_00cf47a0::FUN_00d97070);
}

// @f3 0x00ce6cb0 (community match, verified in this file)
struct Setting_c6cb0 {
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting_c6cb0 DAT_01075c38;

extern "C" void FUN_00c00d1f(void (*fn)());
void __cdecl FUN_00d95930();

// pdb: `dynamic initializer for 'iSafeZoneYWide'' | InterfaceManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6cb0()
{
    DAT_01075c38.FUN_0043b7f0("iSafeZoneYWide:Interface", 15);
    FUN_00c00d1f(FUN_00d95930);
}

// @f3 0x00ce0d60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0d60 {
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

extern Setting DAT_00f66388;
void __cdecl FUN_00d94cb0();
}

void __cdecl FUN_00ce0d60()
{
    using namespace f3m_00ce0d60;
    DAT_00f66388.Setting::Setting();
    atexit(FUN_00d94cb0);
}

// @f3 0x00cedcf0 (community match, verified in this file)
#include <stdlib.h>
extern char DAT_01078184;
namespace f3m_00cedcf0 {

namespace f3m_00cedcf0 {
void __cdecl FUN_006a70a0();
char __cdecl FUN_00401db0(int a1, const void* a2);
}

void __cdecl FUN_00cedcf0()
{
    using namespace f3m_00cedcf0;
    DAT_01078184 = FUN_00401db0(7, (const void*)FUN_006a70a0);
}
}   // namespace f3m_00cedcf0

// @f3 0x00ced720 (community match, verified in this file)
#include <stdlib.h>
extern char DAT_0107801d;
namespace f3m_00ced720 {

namespace f3m_00ced720 {
void __cdecl FUN_006a6740();
char __cdecl FUN_00401db0(int a1, const void* a2);
}

void __cdecl FUN_00ced720()
{
    using namespace f3m_00ced720;
    DAT_0107801d = FUN_00401db0(33, (const void*)FUN_006a6740);
}
}   // namespace f3m_00ced720

// @f3 0x00cee9a0 (community match, verified in this file)
#include <stdlib.h>
extern char DAT_01078434;
namespace f3m_00cee9a0 {

namespace f3m_00cee9a0 {
void __cdecl FUN_006a8a50();
char __cdecl FUN_00401db0(int a1, const void* a2);
}

void __cdecl FUN_00cee9a0()
{
    using namespace f3m_00cee9a0;
    DAT_01078434 = FUN_00401db0(13, (const void*)FUN_006a8a50);
}
}   // namespace f3m_00cee9a0

// @f3 0x00cf69c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf69c0 {
extern const char DAT_00e1381c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107b028;
void __cdecl FUN_00d97770();
}

// pdb: `dynamic initializer for 'iAIThread1HWThread'' | AILinearTaskThreadManager.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: AILinearTaskThreadManager::`dynamic initializer for 'iAIThread1HWThread'')
void __cdecl FUN_00cf69c0()
{
    using namespace f3m_00cf69c0;
    DAT_0107b028.FUN_0043b7f0(DAT_00e1381c, 3);
    atexit(FUN_00d97770);
}

// @f3 0x00cf65e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf65e0 {
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

extern Setting DAT_00f6e234;
void __cdecl FUN_00d97730();
}

void __cdecl FUN_00cf65e0()
{
    f3m_00cf65e0::DAT_00f6e234.Setting::Setting();
    atexit(f3m_00cf65e0::FUN_00d97730);
}

// @f3 0x00cf5180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5180 {
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

extern Setting DAT_00f6de18;
void __cdecl FUN_00d97490();
}

// pdb: `dynamic initializer for 'pIgnoreText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf5180()
{
    f3m_00cf5180::DAT_00f6de18.Setting::Setting();
    atexit(f3m_00cf5180::FUN_00d97490);
}

// @f3 0x00ce1060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1060 {
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

extern Setting DAT_00f663e8;
void __cdecl FUN_00d94d30();
}

void __cdecl FUN_00ce1060()
{
    f3m_00ce1060::DAT_00f663e8.Setting::Setting();
    atexit(f3m_00ce1060::FUN_00d94d30);
}

// @f3 0x00cfe0b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cfe0b0 {
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

extern Setting DAT_00f70e0c;
void __cdecl FUN_00d98030();
}

void __cdecl FUN_00cfe0b0()
{
    f3m_00cfe0b0::DAT_00f70e0c.Setting::Setting();
    atexit(f3m_00cfe0b0::FUN_00d98030);
}

// @f3 0x00ce17a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce17a0 {
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

extern Setting DAT_00f66558;
void __cdecl FUN_00d94de0();
}

void __cdecl FUN_00ce17a0()
{
    f3m_00ce17a0::DAT_00f66558.Setting::Setting();
    atexit(f3m_00ce17a0::FUN_00d94de0);
}

// @f3 0x00cebb30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cebb30 {
extern const char DAT_00e09a04[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01077a50;
void __cdecl FUN_00d966f0();
}

// pdb: `dynamic initializer for 'iVATSDistortMaxInterval'' | FOVATSEffectManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cebb30()
{
    f3m_00cebb30::DAT_01077a50.FUN_0043b7f0(f3m_00cebb30::DAT_00e09a04, 0x1194);
    atexit(f3m_00cebb30::FUN_00d966f0);
}

// @f3 0x00cecc60 (community match, verified in this file)
extern char DAT_01077dfc;
namespace f3m_00cecc60 {

void __cdecl FUN_006a44e0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());

void __cdecl FUN_00cecc60()
{
    DAT_01077dfc = FUN_00401db0(0x12, FUN_006a44e0);
}
}   // namespace f3m_00cecc60

// @f3 0x00cec510 (community match, verified in this file)
extern char DAT_01077c48;
namespace f3m_00cec510 {


namespace f3m_00cec510 {
namespace f3m_00cec510 {
void __cdecl FUN_006a07d0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cec510()
{
    using namespace f3m_00cec510;
    DAT_01077c48 = FUN_00401db0(4, FUN_006a07d0);
}
}
}   // namespace f3m_00cec510

// @f3 0x00ced1d0 (community match, verified in this file)
extern char DAT_01077f14;
namespace f3m_00ced1d0 {

void __cdecl FUN_006a5ff0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());

void __cdecl FUN_00ced1d0()
{
    DAT_01077f14 = FUN_00401db0(9, FUN_006a5ff0);
}
}   // namespace f3m_00ced1d0

// @f3 0x00cece30 (community match, verified in this file)
extern char DAT_01077e54;
namespace f3m_00cece30 {


namespace f3m_00cece30 {
namespace f3m_00cece30 {
void __cdecl FUN_006a5880();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cece30()
{
    using namespace f3m_00cece30;
    DAT_01077e54 = FUN_00401db0(6, FUN_006a5880);
}
}
}   // namespace f3m_00cece30

// @f3 0x00ced550 (community match, verified in this file)
extern char DAT_01077fe4;
namespace f3m_00ced550 {


namespace f3m_00ced550 {
namespace f3m_00ced550 {
void __cdecl FUN_006a64b0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced550()
{
    using namespace f3m_00ced550;
    DAT_01077fe4 = FUN_00401db0(0xa, FUN_006a64b0);
}
}
}   // namespace f3m_00ced550

// @f3 0x00ce32a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce32a0 {
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

extern Setting DAT_00f66bec;
void __cdecl FUN_00d95160();
}

void __cdecl FUN_00ce32a0()
{
    f3m_00ce32a0::DAT_00f66bec.Setting::Setting();
    atexit(f3m_00ce32a0::FUN_00d95160);
}

// @f3 0x00ce0020 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0020 {
extern const char DAT_00dfcc14[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01073cf8;
void __cdecl FUN_00d94a20();
}

// pdb: `dynamic initializer for 'BSTreeManager::iCanopyShadowScale'' | BSTreeManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce0020()
{
    f3m_00ce0020::DAT_01073cf8.FUN_0043b7f0(f3m_00ce0020::DAT_00dfcc14, 0x200);
    atexit(f3m_00ce0020::FUN_00d94a20);
}

// @f3 0x00cf4740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4740 {
extern const char DAT_00e11804[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a4bc;
void __cdecl FUN_00d97040();
}

// pdb: `dynamic initializer for 'sTestFile8'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4740()
{
    f3m_00cf4740::DAT_0107a4bc.FUN_0043b7f0(f3m_00cf4740::DAT_00e11804, f3m_00cf4740::DAT_00db3438);
    atexit(f3m_00cf4740::FUN_00d97040);
}

// @f3 0x00ce1ce0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1ce0 {
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

extern Setting DAT_00f66600;
void __cdecl FUN_00d94ec0();
}

void __cdecl FUN_00ce1ce0()
{
    f3m_00ce1ce0::DAT_00f66600.Setting::Setting();
    atexit(f3m_00ce1ce0::FUN_00d94ec0);
}

// @f3 0x00ce0fa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0fa0 {
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

extern Setting DAT_00f663d0;
void __cdecl FUN_00d94d10();
}

void __cdecl FUN_00ce0fa0()
{
    f3m_00ce0fa0::DAT_00f663d0.Setting::Setting();
    atexit(f3m_00ce0fa0::FUN_00d94d10);
}

// @f3 0x00ce1740 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1740 {
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

extern Setting DAT_00f6654c;
void __cdecl FUN_00d94dd0();
}

void __cdecl FUN_00ce1740()
{
    f3m_00ce1740::DAT_00f6654c.Setting::Setting();
    atexit(f3m_00ce1740::FUN_00d94dd0);
}

// @f3 0x00cf4660 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4660 {
extern const char DAT_00e11768[];
extern const char DAT_00e1177c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a294;
void __cdecl FUN_00d96fd0();
}

// pdb: `dynamic initializer for 'sTestFile1'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4660()
{
    f3m_00cf4660::DAT_0107a294.FUN_0043b7f0(f3m_00cf4660::DAT_00e11768, f3m_00cf4660::DAT_00e1177c);
    atexit(f3m_00cf4660::FUN_00d96fd0);
}

// @f3 0x00ce2760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2760 {
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

extern Setting DAT_00f66750;
void __cdecl FUN_00d95080();
}

void __cdecl FUN_00ce2760()
{
    f3m_00ce2760::DAT_00f66750.Setting::Setting();
    atexit(f3m_00ce2760::FUN_00d95080);
}

// @f3 0x00ce23a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce23a0 {
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

extern Setting DAT_00f666d8;
void __cdecl FUN_00d94fe0();
}

void __cdecl FUN_00ce23a0()
{
    f3m_00ce23a0::DAT_00f666d8.Setting::Setting();
    atexit(f3m_00ce23a0::FUN_00d94fe0);
}

// @f3 0x00ce2520 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2520 {
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

extern Setting DAT_00f66708;
void __cdecl FUN_00d95020();
}

void __cdecl FUN_00ce2520()
{
    f3m_00ce2520::DAT_00f66708.Setting::Setting();
    atexit(f3m_00ce2520::FUN_00d95020);
}

// @f3 0x00ce33c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce33c0 {
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

extern Setting DAT_00f66c10;
void __cdecl FUN_00d95190();
}

void __cdecl FUN_00ce33c0()
{
    f3m_00ce33c0::DAT_00f66c10.Setting::Setting();
    atexit(f3m_00ce33c0::FUN_00d95190);
}

// @f3 0x00cf4760 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4760 {
extern const char DAT_00e11818[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a134;
void __cdecl FUN_00d97050();
}

// pdb: `dynamic initializer for 'sTestFile9'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4760()
{
    f3m_00cf4760::DAT_0107a134.FUN_0043b7f0(f3m_00cf4760::DAT_00e11818, f3m_00cf4760::DAT_00db3438);
    atexit(f3m_00cf4760::FUN_00d97050);
}

// @f3 0x00cf1c20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf1c20 {
extern const char DAT_00e0c9fc[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107934c;
void __cdecl FUN_00d968f0();
}

// pdb: `dynamic initializer for 'iRadioUpdateInterval'' | FalloutRadio.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf1c20()
{
    f3m_00cf1c20::DAT_0107934c.FUN_0043b7f0(f3m_00cf1c20::DAT_00e0c9fc, 75);
    atexit(f3m_00cf1c20::FUN_00d968f0);
}

// @f3 0x00cf97c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf97c0 {
extern const char DAT_00e19518[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107c078;
void __cdecl FUN_00d97cf0();
}

// pdb: `dynamic initializer for 'iLowProcessingMilliseconds'' | ProcessLists.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf97c0()
{
    f3m_00cf97c0::DAT_0107c078.FUN_0043b7f0(f3m_00cf97c0::DAT_00e19518, 2);
    atexit(f3m_00cf97c0::FUN_00d97cf0);
}

// @f3 0x00ce06a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce06a0 {
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

extern Setting DAT_00f662b0;
void __cdecl FUN_00d94b90();
}

void __cdecl FUN_00ce06a0()
{
    f3m_00ce06a0::DAT_00f662b0.Setting::Setting();
    atexit(f3m_00ce06a0::FUN_00d94b90);
}

// @f3 0x00cf92d0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf92d0 {
extern const char DAT_00e18f24[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107bd00;
void __cdecl FUN_00d97c90();
}

// pdb: `dynamic initializer for 'iXenonHorizLookAccel'' | PlayerCharacter.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00cf92d0()
{
    f3m_00cf92d0::DAT_0107bd00.FUN_0043b7f0(f3m_00cf92d0::DAT_00e18f24, 2);
    atexit(f3m_00cf92d0::FUN_00d97c90);
}

// @f3 0x00cf46a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf46a0 {
extern const char DAT_00e117a0[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a380;
void __cdecl FUN_00d96ff0();
}

// pdb: `dynamic initializer for 'sTestFile3'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf46a0()
{
    f3m_00cf46a0::DAT_0107a380.FUN_0043b7f0(f3m_00cf46a0::DAT_00e117a0, f3m_00cf46a0::DAT_00db3438);
    atexit(f3m_00cf46a0::FUN_00d96ff0);
}

// @f3 0x00cf91b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf91b0 {
extern const char DAT_00e18e5c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107bd0c;
void __cdecl FUN_00d97c20();
}

// pdb: `dynamic initializer for 'iHoursToSleep'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf91b0()
{
    f3m_00cf91b0::DAT_0107bd0c.FUN_0043b7f0(f3m_00cf91b0::DAT_00e18e5c, 3);
    atexit(f3m_00cf91b0::FUN_00d97c20);
}

// @f3 0x00ce1c80 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1c80 {
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

extern Setting DAT_00f665f4;
void __cdecl FUN_00d94eb0();
}

void __cdecl FUN_00ce1c80()
{
    f3m_00ce1c80::DAT_00f665f4.Setting::Setting();
    atexit(f3m_00ce1c80::FUN_00d94eb0);
}

// @f3 0x00cf5060 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5060 {
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

extern Setting DAT_00f6ddf4;
void __cdecl FUN_00d97460();
}

// pdb: `dynamic initializer for 'pYesToAllText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf5060()
{
    f3m_00cf5060::DAT_00f6ddf4.Setting::Setting();
    atexit(f3m_00cf5060::FUN_00d97460);
}

// @f3 0x00ce2a90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2a90 {
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

extern Setting DAT_00f668b4;
void __cdecl FUN_00d950c0();
}

void __cdecl FUN_00ce2a90()
{
    f3m_00ce2a90::DAT_00f668b4.Setting::Setting();
    atexit(f3m_00ce2a90::FUN_00d950c0);
}

// @f3 0x00ce0700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0700 {
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

extern Setting DAT_00f662bc;
void __cdecl FUN_00d94ba0();
}

void __cdecl FUN_00ce0700()
{
    f3m_00ce0700::DAT_00f662bc.Setting::Setting();
    atexit(f3m_00ce0700::FUN_00d94ba0);
}

// @f3 0x00cf4680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4680 {
extern const char DAT_00e1178c[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a230;
void __cdecl FUN_00d96fe0();
}

// pdb: `dynamic initializer for 'sTestFile2'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4680()
{
    f3m_00cf4680::DAT_0107a230.FUN_0043b7f0(f3m_00cf4680::DAT_00e1178c, f3m_00cf4680::DAT_00db3438);
    atexit(f3m_00cf4680::FUN_00d96fe0);
}

// @f3 0x00ce2340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2340 {
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

extern Setting DAT_00f666cc;
void __cdecl FUN_00d94fd0();
}

void __cdecl FUN_00ce2340()
{
    f3m_00ce2340::DAT_00f666cc.Setting::Setting();
    atexit(f3m_00ce2340::FUN_00d94fd0);
}

// @f3 0x00ce1ec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1ec0 {
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

extern Setting DAT_00f6663c;
void __cdecl FUN_00d94f10();
}

void __cdecl FUN_00ce1ec0()
{
    f3m_00ce1ec0::DAT_00f6663c.Setting::Setting();
    atexit(f3m_00ce1ec0::FUN_00d94f10);
}

// @f3 0x00cee430 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cee430 {
void __cdecl FUN_006a7b40();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078318;
}

void __cdecl FUN_00cee430()
{
    f3m_00cee430::DAT_01078318 = f3m_00cee430::FUN_00401db0(2, (const void*)f3m_00cee430::FUN_006a7b40);
}

// @f3 0x00ce0ca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0ca0 {
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

extern Setting DAT_00f66370;
void __cdecl FUN_00d94c90();
}

void __cdecl FUN_00ce0ca0()
{
    f3m_00ce0ca0::DAT_00f66370.Setting::Setting();
    atexit(f3m_00ce0ca0::FUN_00d94c90);
}

// @f3 0x00cf0fd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf0fd0 {
void __cdecl FUN_006bc3e0();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078cd1;
}

void __cdecl FUN_00cf0fd0()
{
    f3m_00cf0fd0::DAT_01078cd1 = f3m_00cf0fd0::FUN_00401db0(27, (const void*)f3m_00cf0fd0::FUN_006bc3e0);
}

// @f3 0x00cf5240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5240 {
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

extern Setting DAT_00f6de30;
void __cdecl FUN_00d974b0();
}

// pdb: `dynamic initializer for 'pContinueText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf5240()
{
    f3m_00cf5240::DAT_00f6de30.Setting::Setting();
    atexit(f3m_00cf5240::FUN_00d974b0);
}

// @f3 0x00ce24c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce24c0 {
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

extern Setting DAT_00f666fc;
void __cdecl FUN_00d95010();
}

void __cdecl FUN_00ce24c0()
{
    f3m_00ce24c0::DAT_00f666fc.Setting::Setting();
    atexit(f3m_00ce24c0::FUN_00d95010);
}

// @f3 0x00ce1a40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1a40 {
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

extern Setting DAT_00f665ac;
void __cdecl FUN_00d94e50();
}

void __cdecl FUN_00ce1a40()
{
    f3m_00ce1a40::DAT_00f665ac.Setting::Setting();
    atexit(f3m_00ce1a40::FUN_00d94e50);
}

// @f3 0x00cf4d00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4d00 {
extern const char DAT_00e11ce0[];
extern const char DAT_00e11d0c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a2a0;
void __cdecl FUN_00d972b0();
}

// pdb: `dynamic initializer for 'sCopyProtectionTitle2'' | Main.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf4d00()
{
    f3m_00cf4d00::DAT_0107a2a0.FUN_0043b7f0(f3m_00cf4d00::DAT_00e11ce0, f3m_00cf4d00::DAT_00e11d0c);
    atexit(f3m_00cf4d00::FUN_00d972b0);
}

// @f3 0x00cebd90 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cebd90 {
extern const char DAT_00e09b44[];
extern const char DAT_00e09544[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_01077a38;
void __cdecl FUN_00d967c0();
}

// pdb: `dynamic initializer for 'sVATSScanlinesTexture'' | FOVATSEffectManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cebd90()
{
    f3m_00cebd90::DAT_01077a38.FUN_0043b7f0(f3m_00cebd90::DAT_00e09b44, f3m_00cebd90::DAT_00e09544);
    atexit(f3m_00cebd90::FUN_00d967c0);
}

// @f3 0x00ce1e60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1e60 {
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

extern Setting DAT_00f66630;
void __cdecl FUN_00d94f00();
}

void __cdecl FUN_00ce1e60()
{
    f3m_00ce1e60::DAT_00f66630.Setting::Setting();
    atexit(f3m_00ce1e60::FUN_00d94f00);
}

// @f3 0x00ce0e20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0e20 {
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

extern Setting DAT_00f663a0;
void __cdecl FUN_00d94cd0();
}

void __cdecl FUN_00ce0e20()
{
    f3m_00ce0e20::DAT_00f663a0.Setting::Setting();
    atexit(f3m_00ce0e20::FUN_00d94cd0);
}

// @f3 0x00ce1180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1180 {
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

extern Setting DAT_00f6640c;
void __cdecl FUN_00d94d60();
}

void __cdecl FUN_00ce1180()
{
    f3m_00ce1180::DAT_00f6640c.Setting::Setting();
    atexit(f3m_00ce1180::FUN_00d94d60);
}

// @f3 0x00ce0580 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0580 {
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

extern Setting DAT_00f6628c;
void __cdecl FUN_00d94b60();
}

void __cdecl FUN_00ce0580()
{
    f3m_00ce0580::DAT_00f6628c.Setting::Setting();
    atexit(f3m_00ce0580::FUN_00d94b60);
}

// @f3 0x00cf46e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf46e0 {
extern const char DAT_00e117c8[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a2d4;
void __cdecl FUN_00d97010();
}

// pdb: `dynamic initializer for 'sTestFile5'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf46e0()
{
    f3m_00cf46e0::DAT_0107a2d4.FUN_0043b7f0(f3m_00cf46e0::DAT_00e117c8, f3m_00cf46e0::DAT_00db3438);
    atexit(f3m_00cf46e0::FUN_00d97010);
}

// @f3 0x00ce3180 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3180 {
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

extern Setting DAT_00f66bc8;
void __cdecl FUN_00d95130();
}

void __cdecl FUN_00ce3180()
{
    f3m_00ce3180::DAT_00f66bc8.Setting::Setting();
    atexit(f3m_00ce3180::FUN_00d95130);
}

// @f3 0x00ce1aa0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1aa0 {
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

extern Setting DAT_00f665b8;
void __cdecl FUN_00d94e60();
}

void __cdecl FUN_00ce1aa0()
{
    f3m_00ce1aa0::DAT_00f665b8.Setting::Setting();
    atexit(f3m_00ce1aa0::FUN_00d94e60);
}

// @f3 0x00cf42f0 (community match, verified in this file)
namespace f3m_00cf42f0 {
struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __declspec(dllimport) int Init(int n);
};
extern Obj DAT_00f6db28;
void __cdecl FUN_00d96c60();
int __cdecl FUN_00c00d1f(void (__cdecl *f)());

void FUN_00cf42f0()
{
    DAT_00f6db28.unk04 = DAT_00f6db28.Init(0x32);
    DAT_00f6db28.unk0c = 0x32;
    FUN_00c00d1f(FUN_00d96c60);
}
}   // namespace f3m_00cf42f0

// @f3 0x00cf4640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4640 {
extern const char DAT_00e11704[];
extern const char DAT_00e11720[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a23c;
void __cdecl FUN_00d96fc0();
}

// pdb: `dynamic initializer for 'sMasterArchiveList'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4640()
{
    f3m_00cf4640::DAT_0107a23c.FUN_0043b7f0(f3m_00cf4640::DAT_00e11704, f3m_00cf4640::DAT_00e11720);
    atexit(f3m_00cf4640::FUN_00d96fc0);
}

// @f3 0x00cffcc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cffcc0 {
extern const char DAT_00e20248[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0108ebd8;
void __cdecl FUN_00d98250();
}

// pdb: `dynamic initializer for 'iIntroSequencePriority'' | MoviePlayer.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cffcc0()
{
    f3m_00cffcc0::DAT_0108ebd8.FUN_0043b7f0(f3m_00cffcc0::DAT_00e20248, 3);
    atexit(f3m_00cffcc0::FUN_00d98250);
}

// @f3 0x00cf59b0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf59b0 {
extern const char DAT_00e12570[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107a78c;
void __cdecl FUN_00d974f0();
}

// pdb: `dynamic initializer for 'iNumBitsForFullySeen'' | SeenData.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf59b0()
{
    f3m_00cf59b0::DAT_0107a78c.FUN_0043b7f0(f3m_00cf59b0::DAT_00e12570, 248);
    atexit(f3m_00cf59b0::FUN_00d974f0);
}

// @f3 0x00cf1370 (community match, verified in this file)
extern char DAT_01078d78;
namespace f3m_00cf1370 {
namespace f3m_00cf1370 {
void __cdecl FUN_006bca20();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00cf1370()
{
    using namespace f3m_00cf1370;
    DAT_01078d78 = FUN_00401db0(0, FUN_006bca20);
}
}   // namespace f3m_00cf1370

// @f3 0x00ce1b60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1b60 {
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

extern Setting DAT_00f665d0;
void __cdecl FUN_00d94e80();
}

void __cdecl FUN_00ce1b60()
{
    f3m_00ce1b60::DAT_00f665d0.Setting::Setting();
    atexit(f3m_00ce1b60::FUN_00d94e80);
}

// @f3 0x00cf6090 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf6090 {
extern const char DAT_00e134f0[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107acec;
void __cdecl FUN_00d97650();
}

// pdb: `dynamic initializer for 'iDetectionHighNumPicks'' | Actor.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf6090()
{
    f3m_00cf6090::DAT_0107acec.FUN_0043b7f0(f3m_00cf6090::DAT_00e134f0, 40);
    atexit(f3m_00cf6090::FUN_00d97650);
}

// @f3 0x00ce2640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2640 {
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

extern Setting DAT_00f6672c;
void __cdecl FUN_00d95050();
}

void __cdecl FUN_00ce2640()
{
    f3m_00ce2640::DAT_00f6672c.Setting::Setting();
    atexit(f3m_00ce2640::FUN_00d95050);
}

// @f3 0x00cf4700 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4700 {
extern const char DAT_00e117dc[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a480;
void __cdecl FUN_00d97020();
}

// pdb: `dynamic initializer for 'sTestFile6'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4700()
{
    f3m_00cf4700::DAT_0107a480.FUN_0043b7f0(f3m_00cf4700::DAT_00e117dc, f3m_00cf4700::DAT_00db3438);
    atexit(f3m_00cf4700::FUN_00d97020);
}

// @f3 0x00ce1fe0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1fe0 {
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

extern Setting DAT_00f66660;
void __cdecl FUN_00d94f40();
}

void __cdecl FUN_00ce1fe0()
{
    f3m_00ce1fe0::DAT_00f66660.Setting::Setting();
    atexit(f3m_00ce1fe0::FUN_00d94f40);
}

// @f3 0x00ce1bc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1bc0 {
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

extern Setting DAT_00f665dc;
void __cdecl FUN_00d94e90();
}

void __cdecl FUN_00ce1bc0()
{
    f3m_00ce1bc0::DAT_00f665dc.Setting::Setting();
    atexit(f3m_00ce1bc0::FUN_00d94e90);
}

// @f3 0x00cf4600 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4600 {
extern const char DAT_00e1151c[];
extern const char DAT_00e11540[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a4ec;
void __cdecl FUN_00d96fa0();
}

// pdb: `dynamic initializer for 'sEssentialFileCacheList'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4600()
{
    f3m_00cf4600::DAT_0107a4ec.FUN_0043b7f0(f3m_00cf4600::DAT_00e1151c, f3m_00cf4600::DAT_00e11540);
    atexit(f3m_00cf4600::FUN_00d96fa0);
}

// @f3 0x00ce2100 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2100 {
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

extern Setting DAT_00f66684;
void __cdecl FUN_00d94f70();
}

void __cdecl FUN_00ce2100()
{
    f3m_00ce2100::DAT_00f66684.Setting::Setting();
    atexit(f3m_00ce2100::FUN_00d94f70);
}

// @f3 0x00ce6c70 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce6c70 {
extern const char DAT_00e03e18[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01075c68;
void __cdecl FUN_00d95910();
}

// pdb: `dynamic initializer for 'iSafeZoneY'' | InterfaceManager.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6c70()
{
    f3m_00ce6c70::DAT_01075c68.FUN_0043b7f0(f3m_00ce6c70::DAT_00e03e18, 15);
    atexit(f3m_00ce6c70::FUN_00d95910);
}

// @f3 0x00cf0a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf0a60 {
void __cdecl FUN_006bab90();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078b94;
}

void __cdecl FUN_00cf0a60()
{
    f3m_00cf0a60::DAT_01078b94 = f3m_00cf0a60::FUN_00401db0(19, (const void*)f3m_00cf0a60::FUN_006bab90);
}

// @f3 0x00cf5920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5920 {
extern const char DAT_00e124e0[];
extern const char DAT_00e124fc[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a710;
void __cdecl FUN_00d974d0();
}

// pdb: ScreenShot::`dynamic initializer for 'siniBaseName'' | ScreenShot.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf5920()
{
    f3m_00cf5920::DAT_0107a710.FUN_0043b7f0(f3m_00cf5920::DAT_00e124e0, f3m_00cf5920::DAT_00e124fc);
    atexit(f3m_00cf5920::FUN_00d974d0);
}

// @f3 0x00ce1620 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1620 {
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

extern Setting DAT_00f66528;
void __cdecl FUN_00d94da0();
}

void __cdecl FUN_00ce1620()
{
    f3m_00ce1620::DAT_00f66528.Setting::Setting();
    atexit(f3m_00ce1620::FUN_00d94da0);
}

// @f3 0x00cf5000 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf5000 {
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

extern Setting DAT_00f6dde8;
void __cdecl FUN_00d97450();
}

// pdb: `dynamic initializer for 'pNoText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf5000()
{
    f3m_00cf5000::DAT_00f6dde8.Setting::Setting();
    atexit(f3m_00cf5000::FUN_00d97450);
}

// @f3 0x00ce0c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0c40 {
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

extern Setting DAT_00f66364;
void __cdecl FUN_00d94c80();
}

void __cdecl FUN_00ce0c40()
{
    f3m_00ce0c40::DAT_00f66364.Setting::Setting();
    atexit(f3m_00ce0c40::FUN_00d94c80);
}

// @f3 0x00ce19e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce19e0 {
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

extern Setting DAT_00f665a0;
void __cdecl FUN_00d94e40();
}

void __cdecl FUN_00ce19e0()
{
    f3m_00ce19e0::DAT_00f665a0.Setting::Setting();
    atexit(f3m_00ce19e0::FUN_00d94e40);
}

// @f3 0x00ce2880 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2880 {
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

extern Setting DAT_00f66774;
void __cdecl FUN_00d950b0();
}

void __cdecl FUN_00ce2880()
{
    f3m_00ce2880::DAT_00f66774.Setting::Setting();
    atexit(f3m_00ce2880::FUN_00d950b0);
}

// @f3 0x00cedec0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cedec0 {
void __cdecl FUN_006a7520();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_010781b1;
}

void __cdecl FUN_00cedec0()
{
    f3m_00cedec0::DAT_010781b1 = f3m_00cedec0::FUN_00401db0(20, (const void*)f3m_00cedec0::FUN_006a7520);
}

// @f3 0x00ce0d00 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0d00 {
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

extern Setting DAT_00f6637c;
void __cdecl FUN_00d94ca0();
}

void __cdecl FUN_00ce0d00()
{
    f3m_00ce0d00::DAT_00f6637c.Setting::Setting();
    atexit(f3m_00ce0d00::FUN_00d94ca0);
}

// @f3 0x00ce05e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce05e0 {
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

extern Setting DAT_00f66298;
void __cdecl FUN_00d94b70();
}

void __cdecl FUN_00ce05e0()
{
    f3m_00ce05e0::DAT_00f66298.Setting::Setting();
    atexit(f3m_00ce05e0::FUN_00d94b70);
}

// @f3 0x00ceb340 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ceb340 {
extern const char DAT_00e09524[];
extern const char DAT_00e09544[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_01077704;
void __cdecl FUN_00d96550();
}

// pdb: `dynamic initializer for 'sInterfaceScanlinesTexture'' | FORenderedMenu.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ceb340()
{
    f3m_00ceb340::DAT_01077704.FUN_0043b7f0(f3m_00ceb340::DAT_00e09524, f3m_00ceb340::DAT_00e09544);
    atexit(f3m_00ceb340::FUN_00d96550);
}

// @f3 0x00ce3300 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3300 {
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

extern Setting DAT_00f66bf8;
void __cdecl FUN_00d95170();
}

void __cdecl FUN_00ce3300()
{
    f3m_00ce3300::DAT_00f66bf8.Setting::Setting();
    atexit(f3m_00ce3300::FUN_00d95170);
}

// @f3 0x00ce2040 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2040 {
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

extern Setting DAT_00f6666c;
void __cdecl FUN_00d94f50();
}

void __cdecl FUN_00ce2040()
{
    f3m_00ce2040::DAT_00f6666c.Setting::Setting();
    atexit(f3m_00ce2040::FUN_00d94f50);
}

// @f3 0x00ce1860 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1860 {
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

extern Setting DAT_00f66570;
void __cdecl FUN_00d94e00();
}

void __cdecl FUN_00ce1860()
{
    f3m_00ce1860::DAT_00f66570.Setting::Setting();
    atexit(f3m_00ce1860::FUN_00d94e00);
}

// @f3 0x00ce3420 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3420 {
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

extern Setting DAT_00f66c1c;
void __cdecl FUN_00d951a0();
}

void __cdecl FUN_00ce3420()
{
    f3m_00ce3420::DAT_00f66c1c.Setting::Setting();
    atexit(f3m_00ce3420::FUN_00d951a0);
}

// @f3 0x00cf0650 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf0650 {
void __cdecl FUN_006b97f0();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078aac;
}

void __cdecl FUN_00cf0650()
{
    f3m_00cf0650::DAT_01078aac = f3m_00cf0650::FUN_00401db0(25, (const void*)f3m_00cf0650::FUN_006b97f0);
}

// @f3 0x00ce1680 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1680 {
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

extern Setting DAT_00f66534;
void __cdecl FUN_00d94db0();
}

void __cdecl FUN_00ce1680()
{
    f3m_00ce1680::DAT_00f66534.Setting::Setting();
    atexit(f3m_00ce1680::FUN_00d94db0);
}

// @f3 0x00cf4780 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4780 {
extern const char DAT_00e1182c[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a3c8;
void __cdecl FUN_00d97060();
}

// pdb: `dynamic initializer for 'sTestFile10'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4780()
{
    f3m_00cf4780::DAT_0107a3c8.FUN_0043b7f0(f3m_00cf4780::DAT_00e1182c, f3m_00cf4780::DAT_00db3438);
    atexit(f3m_00cf4780::FUN_00d97060);
}

// @f3 0x00cf8dd0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf8dd0 {
extern const char DAT_00e18ba0[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107bca0;
void __cdecl FUN_00d97ab0();
}

// pdb: `dynamic initializer for 'iJoystickMoveFrontBack'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf8dd0()
{
    f3m_00cf8dd0::DAT_0107bca0.FUN_0043b7f0(f3m_00cf8dd0::DAT_00e18ba0, 2);
    atexit(f3m_00cf8dd0::FUN_00d97ab0);
}

// @f3 0x00ce6eb0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce6eb0 {
extern const char DAT_00e04514[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01075d1c;
void __cdecl FUN_00d959a0();
}

// pdb: `dynamic initializer for 'iConsoleHistorySize'' | MenuConsole.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce6eb0()
{
    f3m_00ce6eb0::DAT_01075d1c.FUN_0043b7f0(f3m_00ce6eb0::DAT_00e04514, 50);
    atexit(f3m_00ce6eb0::FUN_00d959a0);
}

// @f3 0x00ce07c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce07c0 {
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

extern Setting DAT_00f662d4;
void __cdecl FUN_00d94bc0();
}

void __cdecl FUN_00ce07c0()
{
    f3m_00ce07c0::DAT_00f662d4.Setting::Setting();
    atexit(f3m_00ce07c0::FUN_00d94bc0);
}

// @f3 0x00cf9410 (community match, verified in this file)
struct unk36 {
    int a0, a1, a2, a3, a4, a5, a6, a7, a8;
};
extern unk36 FUN_00f72574;
extern unk36 DAT_0107bc6c;

void FUN_00cf9410()
{
    DAT_0107bc6c = FUN_00f72574;
}

// @f3 0x00ce2820 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce2820 {
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

extern Setting DAT_00f66768;
void __cdecl FUN_00d950a0();
}

void __cdecl FUN_00ce2820()
{
    f3m_00ce2820::DAT_00f66768.Setting::Setting();
    atexit(f3m_00ce2820::FUN_00d950a0);
}

// @f3 0x00ce10c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce10c0 {
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

extern Setting DAT_00f663f4;
void __cdecl FUN_00d94d40();
}

void __cdecl FUN_00ce10c0()
{
    f3m_00ce10c0::DAT_00f663f4.Setting::Setting();
    atexit(f3m_00ce10c0::FUN_00d94d40);
}

// @f3 0x00ce8800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce8800 {
extern const char DAT_00e064a0[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01076a10;
void __cdecl FUN_00d95bd0();
}

// pdb: `dynamic initializer for 'LoadingMenu::iMaxScreens_MainMenu'' | LoadingMenu.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce8800()
{
    f3m_00ce8800::DAT_01076a10.FUN_0043b7f0(f3m_00ce8800::DAT_00e064a0, 20);
    atexit(f3m_00ce8800::FUN_00d95bd0);
}

// @f3 0x00ce21c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce21c0 {
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

extern Setting DAT_00f6669c;
void __cdecl FUN_00d94f90();
}

void __cdecl FUN_00ce21c0()
{
    f3m_00ce21c0::DAT_00f6669c.Setting::Setting();
    atexit(f3m_00ce21c0::FUN_00d94f90);
}

// @f3 0x00ce3240 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3240 {
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

extern Setting DAT_00f66be0;
void __cdecl FUN_00d95150();
}

void __cdecl FUN_00ce3240()
{
    f3m_00ce3240::DAT_00f66be0.Setting::Setting();
    atexit(f3m_00ce3240::FUN_00d95150);
}

// @f3 0x00ce22e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce22e0 {
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

extern Setting DAT_00f666c0;
void __cdecl FUN_00d94fc0();
}

void __cdecl FUN_00ce22e0()
{
    f3m_00ce22e0::DAT_00f666c0.Setting::Setting();
    atexit(f3m_00ce22e0::FUN_00d94fc0);
}

// @f3 0x00ce87c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce87c0 {
extern const char DAT_00e06440[];
extern const char DAT_00e06458[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_01076a60;
void __cdecl FUN_00d95bb0();
}

// pdb: `dynamic initializer for 'LoadingMenu::sInitialSound'' | LoadingMenu.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ce87c0()
{
    f3m_00ce87c0::DAT_01076a60.FUN_0043b7f0(f3m_00ce87c0::DAT_00e06440, f3m_00ce87c0::DAT_00e06458);
    atexit(f3m_00ce87c0::FUN_00d95bb0);
}

// @f3 0x00cf4f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4f20 {
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

extern Setting DAT_00f6ddc4;
void __cdecl FUN_00d97430();
}

void __cdecl FUN_00cf4f20()
{
    f3m_00cf4f20::DAT_00f6ddc4.Setting::Setting();
    atexit(f3m_00cf4f20::FUN_00d97430);
}

// @f3 0x00ce1f20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1f20 {
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

extern Setting DAT_00f66648;
void __cdecl FUN_00d94f20();
}

void __cdecl FUN_00ce1f20()
{
    f3m_00ce1f20::DAT_00f66648.Setting::Setting();
    atexit(f3m_00ce1f20::FUN_00d94f20);
}

// @f3 0x00ce0230 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0230 {
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

extern Setting DAT_00f660e8;
void __cdecl FUN_00d94b20();
}

// pdb: `dynamic initializer for 'iHighDamp'' | BSTreeNode.obj | fnv360_0822_debug, objrun, medium
void __cdecl FUN_00ce0230()
{
    f3m_00ce0230::DAT_00f660e8.Setting::Setting();
    atexit(f3m_00ce0230::FUN_00d94b20);
}

// @f3 0x00ce0ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0ee0 {
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

extern Setting DAT_00f663b8;
void __cdecl FUN_00d94cf0();
}

void __cdecl FUN_00ce0ee0()
{
    f3m_00ce0ee0::DAT_00f663b8.Setting::Setting();
    atexit(f3m_00ce0ee0::FUN_00d94cf0);
}

// @f3 0x00cf4cc0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4cc0 {
extern const char DAT_00e11c38[];
extern const char DAT_00e11c64[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a278;
void __cdecl FUN_00d97290();
}

// pdb: `dynamic initializer for 'sCopyProtectionTitle'' | Main.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf4cc0()
{
    f3m_00cf4cc0::DAT_0107a278.FUN_0043b7f0(f3m_00cf4cc0::DAT_00e11c38, f3m_00cf4cc0::DAT_00e11c64);
    atexit(f3m_00cf4cc0::FUN_00d97290);
}

// @f3 0x00ce25e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce25e0 {
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

extern Setting DAT_00f66720;
void __cdecl FUN_00d95040();
}

void __cdecl FUN_00ce25e0()
{
    f3m_00ce25e0::DAT_00f66720.Setting::Setting();
    atexit(f3m_00ce25e0::FUN_00d95040);
}

// @f3 0x00cedb20 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cedb20 {
void __cdecl FUN_006a6ce0();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078114;
}

void __cdecl FUN_00cedb20()
{
    f3m_00cedb20::DAT_01078114 = f3m_00cedb20::FUN_00401db0(14, (const void*)f3m_00cedb20::FUN_006a6ce0);
}

// @f3 0x00cf51e0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf51e0 {
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

extern Setting DAT_00f6de24;
void __cdecl FUN_00d974a0();
}

// pdb: `dynamic initializer for 'pOKText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf51e0()
{
    f3m_00cf51e0::DAT_00f6de24.Setting::Setting();
    atexit(f3m_00cf51e0::FUN_00d974a0);
}

// @f3 0x00ceb320 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ceb320 {
extern const char DAT_00e09504[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_01077818;
void __cdecl FUN_00d96540();
}

// pdb: `dynamic initializer for 'iDefaultDistortMaxInterval'' | FORenderedMenu.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00ceb320()
{
    f3m_00ceb320::DAT_01077818.FUN_0043b7f0(f3m_00ceb320::DAT_00e09504, 0x1194);
    atexit(f3m_00ceb320::FUN_00d96540);
}

// @f3 0x00cf1c40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf1c40 {
extern const char DAT_00e0ca18[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107938c;
void __cdecl FUN_00d96900();
}

// pdb: `dynamic initializer for 'iRadioStationTimeout'' | FalloutRadio.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf1c40()
{
    f3m_00cf1c40::DAT_0107938c.FUN_0043b7f0(f3m_00cf1c40::DAT_00e0ca18, 0x3e8);
    atexit(f3m_00cf1c40::FUN_00d96900);
}

// @f3 0x00ce3120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3120 {
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

extern Setting DAT_00f66bbc;
void __cdecl FUN_00d95120();
}

void __cdecl FUN_00ce3120()
{
    f3m_00ce3120::DAT_00f66bbc.Setting::Setting();
    atexit(f3m_00ce3120::FUN_00d95120);
}

// @f3 0x00cffca0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cffca0 {
extern const char DAT_00e2022c[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0108ebcc;
void __cdecl FUN_00d98240();
}

// pdb: `dynamic initializer for 'iPreloadSizeLimit'' | MoviePlayer.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cffca0()
{
    f3m_00cffca0::DAT_0108ebcc.FUN_0043b7f0(f3m_00cffca0::DAT_00e2022c, 0x1900000);
    atexit(f3m_00cffca0::FUN_00d98240);
}

// @f3 0x00cf8e30 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf8e30 {
extern const char DAT_00e18c00[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107bad0;
void __cdecl FUN_00d97ae0();
}

// pdb: `dynamic initializer for 'iJoystickLookLeftRight'' | PlayerCharacter.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf8e30()
{
    f3m_00cf8e30::DAT_0107bad0.FUN_0043b7f0(f3m_00cf8e30::DAT_00e18c00, 3);
    atexit(f3m_00cf8e30::FUN_00d97ae0);
}

// @f3 0x00cf1540 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf1540 {
void __cdecl FUN_006bd380();
char __cdecl FUN_00401db0(int a1, const void* a2);
extern char DAT_01078dec;
}

void __cdecl FUN_00cf1540()
{
    f3m_00cf1540::DAT_01078dec = f3m_00cf1540::FUN_00401db0(29, (const void*)f3m_00cf1540::FUN_006bd380);
}

// @f3 0x00ce1120 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1120 {
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

extern Setting DAT_00f66400;
void __cdecl FUN_00d94d50();
}

void __cdecl FUN_00ce1120()
{
    f3m_00ce1120::DAT_00f66400.Setting::Setting();
    atexit(f3m_00ce1120::FUN_00d94d50);
}

// @f3 0x00ce1800 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1800 {
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

extern Setting DAT_00f66564;
void __cdecl FUN_00d94df0();
}

void __cdecl FUN_00ce1800()
{
    f3m_00ce1800::DAT_00f66564.Setting::Setting();
    atexit(f3m_00ce1800::FUN_00d94df0);
}

// @f3 0x00ce18c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce18c0 {
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

extern Setting DAT_00f6657c;
void __cdecl FUN_00d94e10();
}

void __cdecl FUN_00ce18c0()
{
    f3m_00ce18c0::DAT_00f6657c.Setting::Setting();
    atexit(f3m_00ce18c0::FUN_00d94e10);
}

// @f3 0x00cf50c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf50c0 {
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

extern Setting DAT_00f6de00;
void __cdecl FUN_00d97470();
}

// pdb: `dynamic initializer for 'pAbortText'' | Main.obj | tesv_win, objrun, medium
void __cdecl FUN_00cf50c0()
{
    f3m_00cf50c0::DAT_00f6de00.Setting::Setting();
    atexit(f3m_00cf50c0::FUN_00d97470);
}

// @f3 0x00cf3ee0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf3ee0 {
extern const char DAT_00e10db8[];
extern const char DAT_00db3438[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_01079ef4;
void __cdecl FUN_00d96b90();
}

// pdb: `dynamic initializer for 'BGSMoviePlayer::sIntroSequence'' | BGSMoviePlayer.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf3ee0()
{
    f3m_00cf3ee0::DAT_01079ef4.FUN_0043b7f0(f3m_00cf3ee0::DAT_00e10db8, f3m_00cf3ee0::DAT_00db3438);
    atexit(f3m_00cf3ee0::FUN_00d96b90);
}

// @f3 0x00ce3360 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce3360 {
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

extern Setting DAT_00f66c04;
void __cdecl FUN_00d95180();
}

void __cdecl FUN_00ce3360()
{
    f3m_00ce3360::DAT_00f66c04.Setting::Setting();
    atexit(f3m_00ce3360::FUN_00d95180);
}

// @f3 0x00cf1a10 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf1a10 {
extern const char DAT_00e0c828[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107912c;
void __cdecl FUN_00d96870();
}

// pdb: `dynamic initializer for 'FalloutAudio::iMusicTransitionInMS'' | FalloutAudio.obj | fnv360_0822_debug, ustr, medium
void __cdecl FUN_00cf1a10()
{
    f3m_00cf1a10::DAT_0107912c.FUN_0043b7f0(f3m_00cf1a10::DAT_00e0c828, 0x3e8);
    atexit(f3m_00cf1a10::FUN_00d96870);
}

// @f3 0x00ce4630 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce4630 {
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

extern Setting DAT_00f67adc;
void __cdecl FUN_00d952a0();
}

void __cdecl FUN_00ce4630()
{
    f3m_00ce4630::DAT_00f67adc.Setting::Setting();
    atexit(f3m_00ce4630::FUN_00d952a0);
}

// @f3 0x00cf4960 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4960 {
extern const char DAT_00e119d8[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, int a2);
};
extern InitTarget DAT_0107a474;
void __cdecl FUN_00d97150();
}

// pdb: `dynamic initializer for 'iCameraPathFPS'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4960()
{
    f3m_00cf4960::DAT_0107a474.FUN_0043b7f0(f3m_00cf4960::DAT_00e119d8, 60);
    atexit(f3m_00cf4960::FUN_00d97150);
}

// @f3 0x00ce0a60 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0a60 {
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

extern Setting DAT_00f66328;
void __cdecl FUN_00d94c30();
}

void __cdecl FUN_00ce0a60()
{
    f3m_00ce0a60::DAT_00f66328.Setting::Setting();
    atexit(f3m_00ce0a60::FUN_00d94c30);
}

// @f3 0x00ce0640 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce0640 {
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

extern Setting DAT_00f662a4;
void __cdecl FUN_00d94b80();
}

void __cdecl FUN_00ce0640()
{
    f3m_00ce0640::DAT_00f662a4.Setting::Setting();
    atexit(f3m_00ce0640::FUN_00d94b80);
}

// @f3 0x00ce1920 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce1920 {
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

extern Setting DAT_00f66588;
void __cdecl FUN_00d94e20();
}

void __cdecl FUN_00ce1920()
{
    f3m_00ce1920::DAT_00f66588.Setting::Setting();
    atexit(f3m_00ce1920::FUN_00d94e20);
}

// @f3 0x00cf2350 (community match, verified in this file)
struct Obj_cf2350
{
    int unk00;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Obj_cf2350 DAT_010796a8;
extern const char DAT_00e0d35c[];
void __cdecl FUN_00d96ad0();

// pdb: `dynamic initializer for 'ImpactMixer::iMaxImpactSoundCount'' | ImpactMixer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `anonymous namespace'::`dynamic initializer for 'NPCFootPool'')
void __cdecl FUN_00cf2350()
{
    DAT_010796a8.FUN_0043b7f0(DAT_00e0d35c, 0x20);
    atexit(FUN_00d96ad0);
}

// @f3 0x00cf4940 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf4940 {
extern const char DAT_00e119b4[];
extern const char DAT_00e119c4[];
struct InitTarget
{
    int unk00;
    void FUN_0043b7f0(const void* a1, const void* a2);
};
extern InitTarget DAT_0107a4a4;
void __cdecl FUN_00d97140();
}

// pdb: `dynamic initializer for 'sCameraPathNif'' | Main.obj | fnv360_0822_debug, ustr, high
void __cdecl FUN_00cf4940()
{
    f3m_00cf4940::DAT_0107a4a4.FUN_0043b7f0(f3m_00cf4940::DAT_00e119b4, f3m_00cf4940::DAT_00e119c4);
    atexit(f3m_00cf4940::FUN_00d97140);
}

// @f3 0x00ce20a0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce20a0 {
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

extern Setting DAT_00f66678;
void __cdecl FUN_00d94f60();
}

void __cdecl FUN_00ce20a0()
{
    f3m_00ce20a0::DAT_00f66678.Setting::Setting();
    atexit(f3m_00ce20a0::FUN_00d94f60);
}

// @f3 0x00cf8ba0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf8ba0 {
extern const char DAT_00e18a08[];
struct InitTarget
{
    int unk00;
    void FUN_006f00a0(const void* a1, int a2);
};
extern InitTarget DAT_0107bbc4;
void __cdecl FUN_00d979e0();
}

// pdb: `dynamic initializer for 'iDifficultySetting_G'' | PlayerCharacter.obj | tesv_win, ustr, medium
void __cdecl FUN_00cf8ba0()
{
    f3m_00cf8ba0::DAT_0107bbc4.FUN_006f00a0(f3m_00cf8ba0::DAT_00e18a08, 2);
    atexit(f3m_00cf8ba0::FUN_00d979e0);
}

// @f3 0x00ceeb70 (community match, verified in this file)
extern char DAT_010784b9;
namespace f3m_00ceeb70 {

namespace f3m_00ceeb70 {
void __cdecl FUN_006a8cc0();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ceeb70()
{
    using namespace f3m_00ceeb70;
    DAT_010784b9 = FUN_00401db0(0x10, FUN_006a8cc0);
}
}   // namespace f3m_00ceeb70

// @f3 0x00cf0480 (community match, verified in this file)
extern char DAT_01078a48;
namespace f3m_00cf0480 {
int FUN_00401db0(int size, void (*init)());
void FUN_006b9120();

void FUN_00cf0480()
{
    DAT_01078a48 = (char)FUN_00401db0(0x18, FUN_006b9120);
}
}   // namespace f3m_00cf0480

// @f3 0x00cf1f40 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00cf1f40 {
struct Setting
{
    int unk00;
    int unk04;
    void FUN_0043b7f0(const char* a0, int a1);
};
extern Setting DAT_01079608;
extern char DAT_00e0d0ec[];
void __cdecl FUN_00d96970();
}
// pdb: `dynamic initializer for 'ImpactMixer::iCollisionSoundTimeDelta'' | ImpactMixer.obj | fnv360_0822_debug, ustr, low, conflict (skyrim: `dynamic initializer for 'iCollisionSoundTimeDelta'')
void __cdecl FUN_00cf1f40()
{
    f3m_00cf1f40::DAT_01079608.FUN_0043b7f0(f3m_00cf1f40::DAT_00e0d0ec, 0x14d);
    atexit(f3m_00cf1f40::FUN_00d96970);
}

// @f3 0x00ce27c0 (community match, verified in this file)
#include <stdlib.h>

namespace f3m_00ce27c0 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f6675c;
void __cdecl FUN_00d95090();

void __cdecl FUN_00ce27c0()
{
    DAT_00f6675c.Setting::Setting();
    atexit(FUN_00d95090);
}
}

// @f3 0x00ce2580 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce2580 {
struct Setting;
struct Manager { virtual void v00(); virtual void Register(Setting* setting); };
extern Manager* DAT_010701a8;
void FUN_00403080();
struct Cleanup {
    void FUN_00403170();
    __forceinline ~Cleanup() { FUN_00403170(); }
};
struct Setting : Cleanup {
    __forceinline Setting() { FUN_00403080(); DAT_010701a8->Register(this); }
};
extern Setting DAT_00f66714;
void __cdecl FUN_00d95030();
}

void __cdecl FUN_00ce2580()
{
    using namespace f3m_00ce2580;
    DAT_00f66714.Setting::Setting();
    atexit(FUN_00d95030);
}

// @f3 0x00ced8f0 (community match, verified in this file)
extern char DAT_0107808c;
namespace f3m_00ced8f0 {

namespace f3m_00ced8f0 {
namespace f3m_00ced8f0 {
void __cdecl FUN_006a6900();
char __cdecl FUN_00401db0(int id, void (__cdecl* fn)());
}

void __cdecl FUN_00ced8f0()
{
    using namespace f3m_00ced8f0;
    DAT_0107808c = FUN_00401db0(3, FUN_006a6900);
}
}
}   // namespace f3m_00ced8f0

// @f3 0x00ceb500 (community match, verified in this file)
namespace CleanupCEB500 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_010778cc;
void FUN_00ceb500() { DAT_010778cc.FUN_008a8440(); }
}

// @f3 0x00cfbbb0 (community match, verified in this file)
namespace CleanupCFBB {
struct Object { void FUN_008a8440(); };
extern Object DAT_0108cdc0;
void FUN_00cfbbb0() { DAT_0108cdc0.FUN_008a8440(); }
}

// @f3 0x00cff080 (community match, verified in this file)
struct StaticCleanupA44 { void FUN_008a8440(); };
extern StaticCleanupA44 DAT_0108da6c;
void __cdecl FUN_00cff080() { DAT_0108da6c.FUN_008a8440(); }

// @f3 0x00cf5740 (community match, verified in this file)
namespace f3_00cf5740 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107a6ec;
}

void __cdecl FUN_00cf5740() {
    f3_00cf5740::DAT_0107a6ec.FUN_008a8440();
}

// @f3 0x00cfe040 (community match, verified in this file)
struct CleanupB_00cfe040 {
    void FUN_008a8440();
};
extern CleanupB_00cfe040 DAT_0108d6a8;
void FUN_00cfe040()
{
    DAT_0108d6a8.FUN_008a8440();
}

// @f3 0x00ce9ba0 (community match, verified in this file)
struct CleanupCE9B { void FUN_008a8440(); };
extern CleanupCE9B DAT_010770b6;
void FUN_00ce9ba0() { DAT_010770b6.FUN_008a8440(); }

// @f3 0x00cf3ad0 (community match, verified in this file)
namespace close_00cf3ad0 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01079df0;
}
void FUN_00cf3ad0()
{
    close_00cf3ad0::DAT_01079df0.FUN_008a8440();
}

// @f3 0x00ce4fb0 (community match, verified in this file)
namespace CleanupCE4F {
struct Object { void FUN_008a8440(); };
extern Object DAT_01074908;
void FUN_00ce4fb0() { DAT_01074908.FUN_008a8440(); }
}

// @f3 0x00ce9e20 (community match, verified in this file)
namespace f3m_00ce9e20 {
namespace register_ce9e20 {
void __cdecl FUN_00d95ed0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00ce9e20()
{
    register_ce9e20::FUN_00c00d1f(register_ce9e20::FUN_00d95ed0);
}
}   // namespace f3m_00ce9e20

// @f3 0x00ceba00 (community match, verified in this file)
namespace f3_00ceba00 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01077a9c;
}

void __cdecl FUN_00ceba00() {
    f3_00ceba00::DAT_01077a9c.FUN_008a8440();
}

// @f3 0x00cf1700 (community match, verified in this file)
struct StaticCleanupA74 { void FUN_008a8440(); };
extern StaticCleanupA74 DAT_010790e0;
void __cdecl FUN_00cf1700() { DAT_010790e0.FUN_008a8440(); }

// @f3 0x00cf0640 (community match, verified in this file)
struct StaticCleanupA78 { void FUN_008a8440(); };
extern StaticCleanupA78 DAT_01078aad;
void __cdecl FUN_00cf0640() { DAT_01078aad.FUN_008a8440(); }

// @f3 0x00cea690 (community match, verified in this file)
namespace f3m_00cea690 {
void __cdecl FUN_00d96200();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00cea690() { FUN_00c00d1f(FUN_00d96200); }
}   // namespace f3m_00cea690

// @f3 0x00cf42c0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf42c0 {

void __cdecl FUN_00d96c20();

void __cdecl FUN_00cf42c0() {
    atexit(FUN_00d96c20);
}
}   // namespace f3m_00cf42c0

// @f3 0x00cfc180 (community match, verified in this file)
namespace f3_00cfc180 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0108cefc;
}

void __cdecl FUN_00cfc180() {
    f3_00cfc180::DAT_0108cefc.FUN_008a8440();
}

// @f3 0x00cf6420 (community match, verified in this file)
struct CleanupObjectCf6420 { void FUN_008a8440(); };
extern CleanupObjectCf6420 DAT_0107ae94;
void __cdecl FUN_00cf6420(){DAT_0107ae94.FUN_008a8440();}

// @f3 0x00cefed0 (community match, verified in this file)
namespace f3_00cefed0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01078915;
}

void __cdecl FUN_00cefed0() {
    f3_00cefed0::DAT_01078915.FUN_008a8440();
}

// @f3 0x00cfd110 (community match, verified in this file)
namespace close_00cfd110 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0108d324;
}
void FUN_00cfd110()
{
    close_00cfd110::DAT_0108d324.FUN_008a8440();
}

// @f3 0x00cf9be0 (community match, verified in this file)
struct StaticCleanupA128 { void FUN_008a8440(); };
extern StaticCleanupA128 DAT_0108c509;
void __cdecl FUN_00cf9be0() { DAT_0108c509.FUN_008a8440(); }

// @f3 0x00ced540 (community match, verified in this file)
struct StaticCleanupA136 { void FUN_008a8440(); };
extern StaticCleanupA136 DAT_01077fe5;
void __cdecl FUN_00ced540() { DAT_01077fe5.FUN_008a8440(); }

// @f3 0x00ce3aa0 (community match, verified in this file)
namespace f3_00ce3aa0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01074378;
}

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSTempEffectDebris.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00ce3aa0() {
    f3_00ce3aa0::DAT_01074378.FUN_008a8440();
}

// @f3 0x00cfff00 (community match, verified in this file)
namespace f3m_00cfff00 {
namespace register_cfff00 {
void __cdecl FUN_00d98300();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00cfff00()
{
    register_cfff00::FUN_00c00d1f(register_cfff00::FUN_00d98300);
}
}   // namespace f3m_00cfff00

// @f3 0x00ce79d0 (community match, verified in this file)
struct CleanupObjectCe79d0 { void FUN_008a8440(); };
extern CleanupObjectCe79d0 DAT_010760f4;
void __cdecl FUN_00ce79d0(){DAT_010760f4.FUN_008a8440();}

// @f3 0x00ce6380 (community match, verified in this file)
namespace f3m_00ce6380 {
void FUN_00d95720();
void __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
void FUN_00ce6380() { FUN_00c00d1f(FUN_00d95720); }
}   // namespace f3m_00ce6380

// @f3 0x00ce4450 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce4450 {

void __cdecl FUN_00d95260();

void __cdecl FUN_00ce4450() {
    atexit(FUN_00d95260);
}
}   // namespace f3m_00ce4450

// @f3 0x00ce5620 (community match, verified in this file)
namespace f3m_00ce5620 {
void __cdecl FUN_00d953d0();

void FUN_00ce5620()
{
    FUN_00c00d1f(FUN_00d953d0);
}
}   // namespace f3m_00ce5620

// @f3 0x00cf4520 (community match, verified in this file)
namespace f3m_00cf4520 {
namespace register_cf4520 {
void __cdecl FUN_00d96dc0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00cf4520()
{
    register_cf4520::FUN_00c00d1f(register_cf4520::FUN_00d96dc0);
}
}   // namespace f3m_00cf4520

// @f3 0x00cfc550 (community match, verified in this file)
namespace f3_00cfc550 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0108cfe8;
}

void __cdecl FUN_00cfc550() {
    f3_00cfc550::DAT_0108cfe8.FUN_008a8440();
}

// @f3 0x00cfc700 (community match, verified in this file)
struct CleanupB_00cfc700 {
    void FUN_008a8440();
};
extern CleanupB_00cfc700 DAT_0108d11c;
void FUN_00cfc700()
{
    DAT_0108d11c.FUN_008a8440();
}

// @f3 0x00cea1c0 (community match, verified in this file)
namespace f3m_00cea1c0 {
void __cdecl FUN_00d96090();
void FUN_00cea1c0()
{
    FUN_00c00d1f(FUN_00d96090);
}
}   // namespace f3m_00cea1c0

// @f3 0x00cf69b0 (community match, verified in this file)
struct CleanupB_00cf69b0 {
    void FUN_008a8440();
};
extern CleanupB_00cf69b0 DAT_0107af8a;
void FUN_00cf69b0()
{
    DAT_0107af8a.FUN_008a8440();
}

// @f3 0x00cfed20 (community match, verified in this file)
namespace close_00cfed20 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0108d9a4;
}
void FUN_00cfed20()
{
    close_00cfed20::DAT_0108d9a4.FUN_008a8440();
}

// @f3 0x00ce5e40 (community match, verified in this file)
namespace f3m_00ce5e40 {
void __cdecl FUN_00d95540();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00ce5e40(){FUN_00c00d1f(FUN_00d95540);}
}   // namespace f3m_00ce5e40

// @f3 0x00cedb10 (community match, verified in this file)
namespace close_00cedb10 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01078115;
}
void FUN_00cedb10()
{
    close_00cedb10::DAT_01078115.FUN_008a8440();
}

// @f3 0x00cf3080 (community match, verified in this file)
namespace close_00cf3080 {
struct Object { void FUN_008a8440(); };
extern Object DAT_010799dc;
}
void FUN_00cf3080()
{
    close_00cf3080::DAT_010799dc.FUN_008a8440();
}

// @f3 0x00cf79f0 (community match, verified in this file)
struct CleanupObjectCf79f0 { void FUN_008a8440(); };
extern CleanupObjectCf79f0 DAT_0107b474;
void __cdecl FUN_00cf79f0(){DAT_0107b474.FUN_008a8440();}

// @f3 0x00cef240 (community match, verified in this file)
struct CleanupB_00cef240 {
    void FUN_008a8440();
};
extern CleanupB_00cef240 DAT_0107862d;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | MagicHitEffect.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cef240()
{
    DAT_0107862d.FUN_008a8440();
}

// @f3 0x00ce9060 (community match, verified in this file)
struct CleanupB_00ce9060 {
    void FUN_008a8440();
};
extern CleanupB_00ce9060 DAT_01076da4;
void FUN_00ce9060()
{
    DAT_01076da4.FUN_008a8440();
}

// @f3 0x00ce8eb0 (community match, verified in this file)
namespace f3m_00ce8eb0 {
namespace register_ce8eb0 {
void __cdecl FUN_00d95cf0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00ce8eb0()
{
    register_ce8eb0::FUN_00c00d1f(register_ce8eb0::FUN_00d95cf0);
}
}   // namespace f3m_00ce8eb0

// @f3 0x00cf0c20 (community match, verified in this file)
namespace f3_00cf0c20 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01078be5;
}

void __cdecl FUN_00cf0c20() {
    f3_00cf0c20::DAT_01078be5.FUN_008a8440();
}

// @f3 0x00ceed30 (community match, verified in this file)
struct StaticCleanupA203 { void FUN_008a8440(); };
extern StaticCleanupA203 DAT_0107851c;
void __cdecl FUN_00ceed30() { DAT_0107851c.FUN_008a8440(); }

// @f3 0x00ce8100 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8100 {

void __cdecl FUN_00d95aa0();

void __cdecl FUN_00ce8100() {
    atexit(FUN_00d95aa0);
}
}   // namespace f3m_00ce8100

// @f3 0x00ce9270 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9270 {

void __cdecl FUN_00d95d30();

void __cdecl FUN_00ce9270() {
    atexit(FUN_00d95d30);
}
}   // namespace f3m_00ce9270

// @f3 0x00ce5f20 (community match, verified in this file)
namespace f3m_00ce5f20 {
namespace register_ce5f20 {
void __cdecl FUN_00d955b0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00ce5f20()
{
    register_ce5f20::FUN_00c00d1f(register_ce5f20::FUN_00d955b0);
}
}   // namespace f3m_00ce5f20

// @f3 0x00ce8e90 (community match, verified in this file)
struct CleanupObjectCe8e90 { void FUN_008a8440(); };
extern CleanupObjectCe8e90 DAT_01076d3c;
void __cdecl FUN_00ce8e90(){DAT_01076d3c.FUN_008a8440();}

// @f3 0x00ce9680 (community match, verified in this file)
struct CleanupObjectCe9680 { void FUN_008a8440(); };
extern CleanupObjectCe9680 DAT_01076fb8;
void __cdecl FUN_00ce9680(){DAT_01076fb8.FUN_008a8440();}

// @f3 0x00cf44e0 (community match, verified in this file)
namespace Cleanup_00cf44e0 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_0107a48c;
void FUN_00cf44e0() { DAT_0107a48c.FUN_008a8440(); }
}

// @f3 0x00cfd7d0 (community match, verified in this file)
namespace Cleanup_00cfd7d0 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_0108d4b4;
void FUN_00cfd7d0() { DAT_0108d4b4.FUN_008a8440(); }
}

// @f3 0x00ce5870 (community match, verified in this file)
struct CleanupObjectCe5870 { void FUN_008a8440(); };
extern CleanupObjectCe5870 DAT_010756dc;
void __cdecl FUN_00ce5870(){DAT_010756dc.FUN_008a8440();}

// @f3 0x00ce84f0 (community match, verified in this file)
struct StaticCleanupA232 { void FUN_008a8440(); };
extern StaticCleanupA232 DAT_01076964;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | LoadingMenu.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00ce84f0() { DAT_01076964.FUN_008a8440(); }

// @f3 0x00ce3e50 (community match, verified in this file)
namespace f3_00ce3e50 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01074450;
}

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSTempEffectParticle.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00ce3e50() {
    f3_00ce3e50::DAT_01074450.FUN_008a8440();
}

// @f3 0x00cee420 (community match, verified in this file)
namespace f3_00cee420 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01078319;
}

void __cdecl FUN_00cee420() {
    f3_00cee420::DAT_01078319.FUN_008a8440();
}

// @f3 0x00cf8ad0 (community match, verified in this file)
struct CleanupB_00cf8ad0 {
    void FUN_008a8440();
};
extern CleanupB_00cf8ad0 DAT_0107bd94;
void FUN_00cf8ad0()
{
    DAT_0107bd94.FUN_008a8440();
}

// @f3 0x00cf42e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf42e0 {

void __cdecl FUN_00d96ca0();

void __cdecl FUN_00cf42e0() {
    atexit(FUN_00d96ca0);
}
}   // namespace f3m_00cf42e0

// @f3 0x00ceae60 (community match, verified in this file)
struct CleanupObjectCeae60 { void FUN_008a8440(); };
extern CleanupObjectCeae60 DAT_010776ad;
void __cdecl FUN_00ceae60(){DAT_010776ad.FUN_008a8440();}

// @f3 0x00cf1810 (community match, verified in this file)
namespace f3m_00cf1810 {
void __cdecl FUN_00d967f0();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00cf1810() { FUN_00c00d1f(FUN_00d967f0); }
}   // namespace f3m_00cf1810

// @f3 0x00cf40e0 (community match, verified in this file)
struct StaticCleanupA248 { void FUN_008a8440(); };
extern StaticCleanupA248 DAT_01079f5c;
void __cdecl FUN_00cf40e0() { DAT_01079f5c.FUN_008a8440(); }

// @f3 0x00cf3e80 (community match, verified in this file)
namespace f3_00cf3e80 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01079ec0;
}

void __cdecl FUN_00cf3e80() {
    f3_00cf3e80::DAT_01079ec0.FUN_008a8440();
}

// @f3 0x00ce5e30 (community match, verified in this file)
namespace close_00ce5e30 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0107582c;
}
void FUN_00ce5e30()
{
    close_00ce5e30::DAT_0107582c.FUN_008a8440();
}

// @f3 0x00cf02a0 (community match, verified in this file)
namespace Cleanup_00cf02a0 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_01078a04;
void FUN_00cf02a0() { DAT_01078a04.FUN_008a8440(); }
}

// @f3 0x00cf1800 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf1800 {

void __cdecl FUN_00d967e0();

void __cdecl FUN_00cf1800() {
    atexit(FUN_00d967e0);
}
}   // namespace f3m_00cf1800

// @f3 0x00cf7da0 (community match, verified in this file)
namespace f3_00cf7da0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107b5c7;
}

void __cdecl FUN_00cf7da0() {
    f3_00cf7da0::DAT_0107b5c7.FUN_008a8440();
}

// @f3 0x00cf1d60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf1d60 {

void __cdecl FUN_00d968e0();

void __cdecl FUN_00cf1d60() {
    atexit(FUN_00d968e0);
}
}   // namespace f3m_00cf1d60

// @f3 0x00cef7f0 (community match, verified in this file)
struct StaticCleanupA272 { void FUN_008a8440(); };
extern StaticCleanupA272 DAT_0107879c;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | MagicShaderHitEffect.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00cef7f0() { DAT_0107879c.FUN_008a8440(); }

// @f3 0x00ce38d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce38d0 {
void FUN_00d951d0();
void FUN_00ce38d0() { atexit(FUN_00d951d0); }
}   // namespace f3m_00ce38d0

// @f3 0x00cecff0 (community match, verified in this file)
struct CleanupObjectCecff0 { void FUN_008a8440(); };
extern CleanupObjectCecff0 DAT_01077eb1;
void __cdecl FUN_00cecff0(){DAT_01077eb1.FUN_008a8440();}

// @f3 0x00ce9260 (community match, verified in this file)
namespace f3_00ce9260 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01076e29;
}

void __cdecl FUN_00ce9260() {
    f3_00ce9260::DAT_01076e29.FUN_008a8440();
}

// @f3 0x00ce49e0 (community match, verified in this file)
namespace f3m_00ce49e0 {
namespace register_ce49e0 {
void __cdecl FUN_00d952b0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00ce49e0()
{
    register_ce49e0::FUN_00c00d1f(register_ce49e0::FUN_00d952b0);
}
}   // namespace f3m_00ce49e0

// @f3 0x00ce3ad0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce3ad0 {

void __cdecl FUN_00d951e0();

void __cdecl FUN_00ce3ad0() {
    atexit(FUN_00d951e0);
}
}   // namespace f3m_00ce3ad0

// @f3 0x00ceeee0 (community match, verified in this file)
namespace f3_00ceeee0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01078580;
}

void __cdecl FUN_00ceeee0() {
    f3_00ceeee0::DAT_01078580.FUN_008a8440();
}

// @f3 0x00ce5480 (community match, verified in this file)
namespace f3_00ce5480 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01074a10;
}

void __cdecl FUN_00ce5480() {
    f3_00ce5480::DAT_01074a10.FUN_008a8440();
}

// @f3 0x00cf1a00 (community match, verified in this file)
struct CleanupB_00cf1a00 {
    void FUN_008a8440();
};
extern CleanupB_00cf1a00 DAT_0107919c;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | FalloutRadio.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cf1a00()
{
    DAT_0107919c.FUN_008a8440();
}

// @f3 0x00cfc330 (community match, verified in this file)
namespace f3_00cfc330 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0108cf84;
}

void __cdecl FUN_00cfc330() {
    f3_00cfc330::DAT_0108cf84.FUN_008a8440();
}

// @f3 0x00ce0510 (community match, verified in this file)
namespace f3_00ce0510 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01073dd0;
}

void __cdecl FUN_00ce0510() {
    f3_00ce0510::DAT_01073dd0.FUN_008a8440();
}

// @f3 0x00ce4020 (community match, verified in this file)
struct CleanupObject { void FUN_008a8440(); };
extern CleanupObject DAT_010744c4;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSTempEffectSimpleDecal.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00ce4020() { DAT_010744c4.FUN_008a8440(); }

// @f3 0x00cf7220 (community match, verified in this file)
namespace f3_00cf7220 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107b28c;
}

void __cdecl FUN_00cf7220() {
    f3_00cf7220::DAT_0107b28c.FUN_008a8440();
}

// @f3 0x00cf5570 (community match, verified in this file)
struct StaticCleanupA306 { void FUN_008a8440(); };
extern StaticCleanupA306 DAT_0107a680;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | SceneGraph.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00cf5570() { DAT_0107a680.FUN_008a8440(); }

// @f3 0x00cf9600 (community match, verified in this file)
namespace f3_00cf9600 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107c010;
}

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | ProcessLists.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00cf9600() {
    f3_00cf9600::DAT_0107c010.FUN_008a8440();
}

// @f3 0x00cf8270 (community match, verified in this file)
namespace close_00cf8270 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0107b6b6;
}
void FUN_00cf8270()
{
    close_00cf8270::DAT_0107b6b6.FUN_008a8440();
}

// @f3 0x00cf3230 (community match, verified in this file)
namespace f3_00cf3230 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01079b05;
}

void __cdecl FUN_00cf3230() {
    f3_00cf3230::DAT_01079b05.FUN_008a8440();
}

// @f3 0x00ce8aa0 (community match, verified in this file)
namespace f3_00ce8aa0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_01076b44;
}

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | LockPickMenu.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00ce8aa0() {
    f3_00ce8aa0::DAT_01076b44.FUN_008a8440();
}

// @f3 0x00cea3d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea3d0 {
void FUN_00d961b0();
void FUN_00cea3d0() { atexit(FUN_00d961b0); }
}   // namespace f3m_00cea3d0

// @f3 0x00ce9e40 (community match, verified in this file)
namespace f3m_00ce9e40 {
void __cdecl FUN_00d95f20();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00ce9e40() { FUN_00c00d1f(FUN_00d95f20); }
}   // namespace f3m_00ce9e40

// @f3 0x00cf1d20 (community match, verified in this file)
namespace f3m_00cf1d20 {
void __cdecl FUN_00d96890();
void __cdecl FUN_00c00d1f(void (__cdecl* callback)());
void __cdecl FUN_00cf1d20() { FUN_00c00d1f(FUN_00d96890); }
}   // namespace f3m_00cf1d20

// @f3 0x00cf4590 (community match, verified in this file)
namespace f3m_00cf4590 {
namespace register_cf4590 {
void __cdecl FUN_00d96f10();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00cf4590()
{
    register_cf4590::FUN_00c00d1f(register_cf4590::FUN_00d96f10);
}
}   // namespace f3m_00cf4590

// @f3 0x00ce8060 (community match, verified in this file)
struct CleanupB_00ce8060 {
    void FUN_008a8440();
};
extern CleanupB_00ce8060 DAT_010762bd;
// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | HUDMainMenu.obj | fnv360_0822_retail, objrun_open, low
void FUN_00ce8060()
{
    DAT_010762bd.FUN_008a8440();
}

// @f3 0x00cf3530 (community match, verified in this file)
namespace close_00cf3530 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01079c88;
}
void FUN_00cf3530()
{
    close_00cf3530::DAT_01079c88.FUN_008a8440();
}

// @f3 0x00cf2eb0 (community match, verified in this file)
namespace close_00cf2eb0 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0107996c;
}
void FUN_00cf2eb0()
{
    close_00cf2eb0::DAT_0107996c.FUN_008a8440();
}

// @f3 0x00ce1380 (community match, verified in this file)
struct Obj01073e40
{
    void FUN_008a8440();
};

extern Obj01073e40 DAT_01073e40;

void FUN_00ce1380()
{
    DAT_01073e40.FUN_008a8440();
}

// @f3 0x00ce1540 (community match, verified in this file)
struct Obj01073e5d
{
    void FUN_008a8440();
};

extern Obj01073e5d DAT_01073e5d;

void FUN_00ce1540()
{
    DAT_01073e5d.FUN_008a8440();
}

// @f3 0x00ce2a80 (community match, verified in this file)
struct Obj01074038
{
    void FUN_008a8440();
};

extern Obj01074038 DAT_01074038;

void FUN_00ce2a80()
{
    DAT_01074038.FUN_008a8440();
}

// @f3 0x00ce2f10 (community match, verified in this file)
struct Obj010740b4
{
    void FUN_008a8440();
};

extern Obj010740b4 DAT_010740b4;

void FUN_00ce2f10()
{
    DAT_010740b4.FUN_008a8440();
}

// @f3 0x00ce30c0 (community match, verified in this file)
struct Obj01074118
{
    void FUN_008a8440();
};

extern Obj01074118 DAT_01074118;

void FUN_00ce30c0()
{
    DAT_01074118.FUN_008a8440();
}

// @f3 0x00ce3620 (community match, verified in this file)
struct Obj01074188
{
    void FUN_008a8440();
};

extern Obj01074188 DAT_01074188;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSTECreateTask.obj | fnv360_0822_retail, objrun_open, low
void FUN_00ce3620()
{
    DAT_01074188.FUN_008a8440();
}

// @f3 0x00ce37d0 (community match, verified in this file)
struct Obj010741ec
{
    void FUN_008a8440();
};

extern Obj010741ec DAT_010741ec;

void FUN_00ce37d0()
{
    DAT_010741ec.FUN_008a8440();
}

// @f3 0x00ce3c80 (community match, verified in this file)
struct Obj01074395
{
    void FUN_008a8440();
};

extern Obj01074395 DAT_01074395;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSTempEffectGeometryDecal.obj | fnv360_0822_retail, objrun_open, low
void FUN_00ce3c80()
{
    DAT_01074395.FUN_008a8440();
}

// @f3 0x00ce45b0 (community match, verified in this file)
struct Obj010745cc
{
    void FUN_008a8440();
};

extern Obj010745cc DAT_010745cc;

void FUN_00ce45b0()
{
    DAT_010745cc.FUN_008a8440();
}

// @f3 0x00ce51e0 (community match, verified in this file)
struct Obj01074988
{
    void FUN_008a8440();
};

extern Obj01074988 DAT_01074988;

void FUN_00ce51e0()
{
    DAT_01074988.FUN_008a8440();
}

// @f3 0x00ce5bc0 (community match, verified in this file)
struct Obj0107578c
{
    void FUN_008a8440();
};

extern Obj0107578c DAT_0107578c;

void FUN_00ce5bc0()
{
    DAT_0107578c.FUN_008a8440();
}

// @f3 0x00ce6530 (community match, verified in this file)
struct Obj010759d0
{
    void FUN_008a8440();
};

extern Obj010759d0 DAT_010759d0;

void FUN_00ce6530()
{
    DAT_010759d0.FUN_008a8440();
}

// @f3 0x00ce66e0 (community match, verified in this file)
struct Obj01075ac8
{
    void FUN_008a8440();
};

extern Obj01075ac8 DAT_01075ac8;

void FUN_00ce66e0()
{
    DAT_01075ac8.FUN_008a8440();
}

// @f3 0x00ce69a0 (community match, verified in this file)
struct Obj01075c90
{
    void FUN_008a8440();
};

extern Obj01075c90 DAT_01075c90;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | InterfaceManager.obj | fnv360_0721_retail, objrun_open, low
void FUN_00ce69a0()
{
    DAT_01075c90.FUN_008a8440();
}

// @f3 0x00ce7110 (community match, verified in this file)
struct Obj01075dbc
{
    void FUN_008a8440();
};

extern Obj01075dbc DAT_01075dbc;

void FUN_00ce7110()
{
    DAT_01075dbc.FUN_008a8440();
}

// @f3 0x00ce7310 (community match, verified in this file)
struct Obj01075e89
{
    void FUN_008a8440();
};

extern Obj01075e89 DAT_01075e89;

void FUN_00ce7310()
{
    DAT_01075e89.FUN_008a8440();
}

// @f3 0x00cf0fc0 (community match, verified in this file)
namespace close_00cf0fc0 {
struct Object { void FUN_008a8440(); };
extern Object DAT_01078cd0;
}
void FUN_00cf0fc0()
{
    close_00cf0fc0::DAT_01078cd0.FUN_008a8440();
}

// @f3 0x00cf4320 (community match, verified in this file)
namespace f3m_00cf4320 {
namespace register_cf4320 {
void __cdecl FUN_00d96ce0();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00cf4320() { register_cf4320::FUN_00c00d1f(register_cf4320::FUN_00d96ce0); }
}   // namespace f3m_00cf4320

// @f3 0x00ce99e0 (community match, verified in this file)
namespace f3_00ce99e0 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107708c;
}

void __cdecl FUN_00ce99e0() {
    f3_00ce99e0::DAT_0107708c.FUN_008a8440();
}

// @f3 0x00ce4030 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce4030 {

void __cdecl FUN_00d951f0();

// pdb: `dynamic initializer for 'BSTempEffectSimpleDecal::spPreloadedDecalTextureSets'' | BSTempEffectSimpleDecal.obj | fnv360_0822_retail, objopen_prop, low
void __cdecl FUN_00ce4030() {
    atexit(FUN_00d951f0);
}
}   // namespace f3m_00ce4030

// @f3 0x00cf9f90 (community match, verified in this file)
struct StaticCleanupA353 { void FUN_008a8440(); };
extern StaticCleanupA353 DAT_0108c6a5;
void __cdecl FUN_00cf9f90() { DAT_0108c6a5.FUN_008a8440(); }

// @f3 0x00cf7690 (community match, verified in this file)
namespace f3_00cf7690 {
struct Obj {
    void FUN_008a8440();
};
extern Obj DAT_0107b3a8;
}

void __cdecl FUN_00cf7690() {
    f3_00cf7690::DAT_0107b3a8.FUN_008a8440();
}

// @f3 0x00cffde0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cffde0 {
void FUN_00d98280();
// pdb: `dynamic initializer for 'NiAlphaProperty::ms_spDefault'' | NiAlphaProperty.obj | tesv_win, objrun_open, low
void FUN_00cffde0() { atexit(FUN_00d98280); }
}   // namespace f3m_00cffde0

// @f3 0x00cfdb30 (community match, verified in this file)
namespace close_00cfdb30 {
struct Object { void FUN_008a8440(); };
extern Object DAT_0108d57c;
}
void FUN_00cfdb30()
{
    close_00cfdb30::DAT_0108d57c.FUN_008a8440();
}

// @f3 0x00cfa410 (community match, verified in this file)
extern CleanupObject DAT_0108c800;
namespace f3m_00cfa410 {
struct CleanupObject { void FUN_008a8440(); };
void __cdecl FUN_00cfa410() { DAT_0108c800.FUN_008a8440(); }
}   // namespace f3m_00cfa410

// @f3 0x00ce6d50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6d50 {

void __cdecl FUN_00d957d0();

void __cdecl FUN_00ce6d50() {
    atexit(FUN_00d957d0);
}
}   // namespace f3m_00ce6d50

// @f3 0x00ce74c0 (community match, verified in this file)
struct Obj01075f44
{
    void FUN_008a8440();
};

extern Obj01075f44 DAT_01075f44;

void FUN_00ce74c0()
{
    DAT_01075f44.FUN_008a8440();
}

// @f3 0x00ce7670 (community match, verified in this file)
struct Obj01075fc4
{
    void FUN_008a8440();
};

extern Obj01075fc4 DAT_01075fc4;

void FUN_00ce7670()
{
    DAT_01075fc4.FUN_008a8440();
}

// @f3 0x00ce7820 (community match, verified in this file)
struct Obj01076054
{
    void FUN_008a8440();
};

extern Obj01076054 DAT_01076054;

void FUN_00ce7820()
{
    DAT_01076054.FUN_008a8440();
}

// @f3 0x00ce7c00 (community match, verified in this file)
struct Obj01076190
{
    void FUN_008a8440();
};

extern Obj01076190 DAT_01076190;

void FUN_00ce7c00()
{
    DAT_01076190.FUN_008a8440();
}

// @f3 0x00ce7db0 (community match, verified in this file)
struct Obj01076260
{
    void FUN_008a8440();
};

extern Obj01076260 DAT_01076260;

void FUN_00ce7db0()
{
    DAT_01076260.FUN_008a8440();
}

// @f3 0x00cf1d50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf1d50 {

void __cdecl FUN_00d968d0();

void __cdecl FUN_00cf1d50() {
    atexit(FUN_00d968d0);
}
}   // namespace f3m_00cf1d50

// @f3 0x00ce8ea0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8ea0 {
void FUN_00d95cb0();
void FUN_00ce8ea0() { atexit(FUN_00d95cb0); }
}   // namespace f3m_00ce8ea0

// @f3 0x00cfe2b0 (community match, verified in this file)
namespace Cleanup_00cfe2b0 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_0108d70c;
void FUN_00cfe2b0() { DAT_0108d70c.FUN_008a8440(); }
}

// @f3 0x00cedeb0 (community match, verified in this file)
struct StaticCleanupA376 { void FUN_008a8440(); };
extern StaticCleanupA376 DAT_010781b2;
void __cdecl FUN_00cedeb0() { DAT_010781b2.FUN_008a8440(); }

// @f3 0x00ce8340 (community match, verified in this file)
struct Obj010768c4
{
    void FUN_008a8440();
};

extern Obj010768c4 DAT_010768c4;

void FUN_00ce8340()
{
    DAT_010768c4.FUN_008a8440();
}

// @f3 0x00ce86d0 (community match, verified in this file)
struct Obj01076a54
{
    void FUN_008a8440();
};

extern Obj01076a54 DAT_01076a54;

void FUN_00ce86d0()
{
    DAT_01076a54.FUN_008a8440();
}

// @f3 0x00ce8cc0 (community match, verified in this file)
struct Obj01076bbe
{
    void FUN_008a8440();
};

extern Obj01076bbe DAT_01076bbe;

void FUN_00ce8cc0()
{
    DAT_01076bbe.FUN_008a8440();
}

// @f3 0x00ce94d0 (community match, verified in this file)
struct Obj01076f38
{
    void FUN_008a8440();
};

extern Obj01076f38 DAT_01076f38;

void FUN_00ce94d0()
{
    DAT_01076f38.FUN_008a8440();
}

// @f3 0x00ce9830 (community match, verified in this file)
struct Obj01077024
{
    void FUN_008a8440();
};

extern Obj01077024 DAT_01077024;

void FUN_00ce9830()
{
    DAT_01077024.FUN_008a8440();
}

// @f3 0x00cea000 (community match, verified in this file)
struct Obj01077298
{
    void FUN_008a8440();
};

extern Obj01077298 DAT_01077298;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | SurgeryMenu.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cea000()
{
    DAT_01077298.FUN_008a8440();
}

// @f3 0x00cea1b0 (community match, verified in this file)
struct Obj010773a0
{
    void FUN_008a8440();
};

extern Obj010773a0 DAT_010773a0;

void FUN_00cea1b0()
{
    DAT_010773a0.FUN_008a8440();
}

// @f3 0x00cea5f0 (community match, verified in this file)
struct Obj010774b8
{
    void FUN_008a8440();
};

extern Obj010774b8 DAT_010774b8;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | VATSMenu.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cea5f0()
{
    DAT_010774b8.FUN_008a8440();
}

// @f3 0x00cef400 (community match, verified in this file)
namespace Cleanup_00cef400 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_010786b0;
void FUN_00cef400() { DAT_010786b0.FUN_008a8440(); }
}

// @f3 0x00ceaa90 (community match, verified in this file)
struct Obj01077668
{
    void FUN_008a8440();
};

extern Obj01077668 DAT_01077668;

void FUN_00ceaa90()
{
    DAT_01077668.FUN_008a8440();
}

// @f3 0x00cebff0 (community match, verified in this file)
struct Obj01077b38
{
    void FUN_008a8440();
};

extern Obj01077b38 DAT_01077b38;

void FUN_00cebff0()
{
    DAT_01077b38.FUN_008a8440();
}

// @f3 0x00cec1a0 (community match, verified in this file)
struct Obj01077b9c
{
    void FUN_008a8440();
};

extern Obj01077b9c DAT_01077b9c;

void FUN_00cec1a0()
{
    DAT_01077b9c.FUN_008a8440();
}

// @f3 0x00cec350 (community match, verified in this file)
struct Obj01077c00
{
    void FUN_008a8440();
};

extern Obj01077c00 DAT_01077c00;

void FUN_00cec350()
{
    DAT_01077c00.FUN_008a8440();
}

// @f3 0x00cec500 (community match, verified in this file)
struct Obj01077c49
{
    void FUN_008a8440();
};

extern Obj01077c49 DAT_01077c49;

void FUN_00cec500()
{
    DAT_01077c49.FUN_008a8440();
}

// @f3 0x00cec6d0 (community match, verified in this file)
struct Obj01077ccc
{
    void FUN_008a8440();
};

extern Obj01077ccc DAT_01077ccc;

void FUN_00cec6d0()
{
    DAT_01077ccc.FUN_008a8440();
}

// @f3 0x00cec8d0 (community match, verified in this file)
struct Obj01077d44
{
    void FUN_008a8440();
};

extern Obj01077d44 DAT_01077d44;

void FUN_00cec8d0()
{
    DAT_01077d44.FUN_008a8440();
}

// @f3 0x00cf7840 (community match, verified in this file)
namespace Cleanup_00cf7840 {
struct Owner { void FUN_008a8440(); };
extern Owner DAT_0107b40c;
void FUN_00cf7840() { DAT_0107b40c.FUN_008a8440(); }
}

// @f3 0x00cecc50 (community match, verified in this file)
struct Obj01077dfd
{
    void FUN_008a8440();
};

extern Obj01077dfd DAT_01077dfd;

void FUN_00cecc50()
{
    DAT_01077dfd.FUN_008a8440();
}

// @f3 0x00cece20 (community match, verified in this file)
struct Obj01077e55
{
    void FUN_008a8440();
};

extern Obj01077e55 DAT_01077e55;

void FUN_00cece20()
{
    DAT_01077e55.FUN_008a8440();
}

// @f3 0x00ced1c0 (community match, verified in this file)
struct Obj01077f15
{
    void FUN_008a8440();
};

extern Obj01077f15 DAT_01077f15;

void FUN_00ced1c0()
{
    DAT_01077f15.FUN_008a8440();
}

// @f3 0x00ced390 (community match, verified in this file)
struct Obj01077f9c
{
    void FUN_008a8440();
};

extern Obj01077f9c DAT_01077f9c;

void FUN_00ced390()
{
    DAT_01077f9c.FUN_008a8440();
}

// @f3 0x00ced710 (community match, verified in this file)
struct Obj0107801e
{
    void FUN_008a8440();
};

extern Obj0107801e DAT_0107801e;

void FUN_00ced710()
{
    DAT_0107801e.FUN_008a8440();
}

// @f3 0x00ced8e0 (community match, verified in this file)
struct Obj0107808f
{
    void FUN_008a8440();
};

extern Obj0107808f DAT_0107808f;

void FUN_00ced8e0()
{
    DAT_0107808f.FUN_008a8440();
}

// @f3 0x00cedce0 (community match, verified in this file)
struct Obj01078185
{
    void FUN_008a8440();
};

extern Obj01078185 DAT_01078185;

void FUN_00cedce0()
{
    DAT_01078185.FUN_008a8440();
}

// @f3 0x00cee080 (community match, verified in this file)
struct Obj0107825d
{
    void FUN_008a8440();
};

extern Obj0107825d DAT_0107825d;

void FUN_00cee080()
{
    DAT_0107825d.FUN_008a8440();
}

// @f3 0x00cee250 (community match, verified in this file)
struct Obj01078291
{
    void FUN_008a8440();
};

extern Obj01078291 DAT_01078291;

void FUN_00cee250()
{
    DAT_01078291.FUN_008a8440();
}

// @f3 0x00cee5f0 (community match, verified in this file)
struct Obj01078345
{
    void FUN_008a8440();
};

extern Obj01078345 DAT_01078345;

void FUN_00cee5f0()
{
    DAT_01078345.FUN_008a8440();
}

// @f3 0x00cee7c0 (community match, verified in this file)
struct Obj010783ed
{
    void FUN_008a8440();
};

extern Obj010783ed DAT_010783ed;

void FUN_00cee7c0()
{
    DAT_010783ed.FUN_008a8440();
}

// @f3 0x00cee990 (community match, verified in this file)
struct Obj01078435
{
    void FUN_008a8440();
};

extern Obj01078435 DAT_01078435;

void FUN_00cee990()
{
    DAT_01078435.FUN_008a8440();
}

// @f3 0x00ceeb60 (community match, verified in this file)
struct Obj010784b8
{
    void FUN_008a8440();
};

extern Obj010784b8 DAT_010784b8;

void FUN_00ceeb60()
{
    DAT_010784b8.FUN_008a8440();
}

// @f3 0x00cef090 (community match, verified in this file)
struct Obj010785e8
{
    void FUN_008a8440();
};

extern Obj010785e8 DAT_010785e8;

void FUN_00cef090()
{
    DAT_010785e8.FUN_008a8440();
}

// @f3 0x00cef250 (community match, verified in this file)
struct Obj0107862c
{
    void FUN_00abab70();
};

extern Obj0107862c DAT_0107862c;

void FUN_00cef250()
{
    DAT_0107862c.FUN_00abab70();
}

// @f3 0x00cef620 (community match, verified in this file)
struct Obj01078730
{
    void FUN_008a8440();
};

extern Obj01078730 DAT_01078730;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | MagicModelHitEffect.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cef620()
{
    DAT_01078730.FUN_008a8440();
}

// @f3 0x00cef9a0 (community match, verified in this file)
struct Obj01078808
{
    void FUN_008a8440();
};

extern Obj01078808 DAT_01078808;

void FUN_00cef9a0()
{
    DAT_01078808.FUN_008a8440();
}

// @f3 0x00cefb70 (community match, verified in this file)
struct Obj0107886c
{
    void FUN_008a8440();
};

extern Obj0107886c DAT_0107886c;

void FUN_00cefb70()
{
    DAT_0107886c.FUN_008a8440();
}

// @f3 0x00cefd20 (community match, verified in this file)
struct Obj010788d0
{
    void FUN_008a8440();
};

extern Obj010788d0 DAT_010788d0;

void FUN_00cefd20()
{
    DAT_010788d0.FUN_008a8440();
}

// @f3 0x00cf00a0 (community match, verified in this file)
struct Obj01078998
{
    void FUN_008a8440();
};

extern Obj01078998 DAT_01078998;

void FUN_00cf00a0()
{
    DAT_01078998.FUN_008a8440();
}

// @f3 0x00cf0470 (community match, verified in this file)
struct Obj01078a49
{
    void FUN_008a8440();
};

extern Obj01078a49 DAT_01078a49;

void FUN_00cf0470()
{
    DAT_01078a49.FUN_008a8440();
}

// @f3 0x00cf0880 (community match, verified in this file)
struct Obj01078b3d
{
    void FUN_008a8440();
};

extern Obj01078b3d DAT_01078b3d;

void FUN_00cf0880()
{
    DAT_01078b3d.FUN_008a8440();
}

// @f3 0x00cf0a50 (community match, verified in this file)
struct Obj01078b95
{
    void FUN_008a8440();
};

extern Obj01078b95 DAT_01078b95;

void FUN_00cf0a50()
{
    DAT_01078b95.FUN_008a8440();
}

// @f3 0x00cf0df0 (community match, verified in this file)
struct Obj01078c4d
{
    void FUN_008a8440();
};

extern Obj01078c4d DAT_01078c4d;

void FUN_00cf0df0()
{
    DAT_01078c4d.FUN_008a8440();
}

// @f3 0x00cf1190 (community match, verified in this file)
struct Obj01078cfd
{
    void FUN_008a8440();
};

extern Obj01078cfd DAT_01078cfd;

void FUN_00cf1190()
{
    DAT_01078cfd.FUN_008a8440();
}

// @f3 0x00cf1360 (community match, verified in this file)
struct Obj01078d79
{
    void FUN_008a8440();
};

extern Obj01078d79 DAT_01078d79;

void FUN_00cf1360()
{
    DAT_01078d79.FUN_008a8440();
}

// @f3 0x00cf1530 (community match, verified in this file)
struct Obj01078ded
{
    void FUN_008a8440();
};

extern Obj01078ded DAT_01078ded;

void FUN_00cf1530()
{
    DAT_01078ded.FUN_008a8440();
}

// @f3 0x00cf1c10 (community match, verified in this file)
struct Obj01079398
{
    void FUN_008a8440();
};

extern Obj01079398 DAT_01079398;

void FUN_00cf1c10()
{
    DAT_01079398.FUN_008a8440();
}

// @f3 0x00cf1f30 (community match, verified in this file)
struct Obj010796c4
{
    void FUN_008a8440();
};

extern Obj010796c4 DAT_010796c4;

void FUN_00cf1f30()
{
    DAT_010796c4.FUN_008a8440();
}

// @f3 0x00cf25a0 (community match, verified in this file)
struct Obj0107975c
{
    void FUN_008a8440();
};

extern Obj0107975c DAT_0107975c;

void FUN_00cf25a0()
{
    DAT_0107975c.FUN_008a8440();
}

// @f3 0x00cf2750 (community match, verified in this file)
struct Obj010797c4
{
    void FUN_008a8440();
};

extern Obj010797c4 DAT_010797c4;

void FUN_00cf2750()
{
    DAT_010797c4.FUN_008a8440();
}

// @f3 0x00cf2950 (community match, verified in this file)
struct Obj01079834
{
    void FUN_008a8440();
};

extern Obj01079834 DAT_01079834;

void FUN_00cf2950()
{
    DAT_01079834.FUN_008a8440();
}

// @f3 0x00cf2b50 (community match, verified in this file)
struct Obj010798a4
{
    void FUN_008a8440();
};

extern Obj010798a4 DAT_010798a4;

void FUN_00cf2b50()
{
    DAT_010798a4.FUN_008a8440();
}

// @f3 0x00cf2d00 (community match, verified in this file)
struct Obj01079908
{
    void FUN_008a8440();
};

extern Obj01079908 DAT_01079908;

void FUN_00cf2d00()
{
    DAT_01079908.FUN_008a8440();
}

// @f3 0x00cf36e0 (community match, verified in this file)
struct Obj01079d10
{
    void FUN_008a8440();
};

extern Obj01079d10 DAT_01079d10;

void FUN_00cf36e0()
{
    DAT_01079d10.FUN_008a8440();
}

// @f3 0x00cf38d0 (community match, verified in this file)
struct Obj01079d84
{
    void FUN_008a8440();
};

extern Obj01079d84 DAT_01079d84;

void FUN_00cf38d0()
{
    DAT_01079d84.FUN_008a8440();
}

// @f3 0x00cf3c80 (community match, verified in this file)
struct Obj01079e54
{
    void FUN_008a8440();
};

extern Obj01079e54 DAT_01079e54;

void FUN_00cf3c80()
{
    DAT_01079e54.FUN_008a8440();
}

// @f3 0x00cf42a0 (community match, verified in this file)
struct Obj0107a00c
{
    void FUN_008a8440();
};

extern Obj0107a00c DAT_0107a00c;

void FUN_00cf42a0()
{
    DAT_0107a00c.FUN_008a8440();
}

// @f3 0x00cf5910 (community match, verified in this file)
struct Obj0107a768
{
    void FUN_008a8440();
};

extern Obj0107a768 DAT_0107a768;

void FUN_00cf5910()
{
    DAT_0107a768.FUN_008a8440();
}

// @f3 0x00cf5b70 (community match, verified in this file)
struct Obj0107a800
{
    void FUN_008a8440();
};

extern Obj0107a800 DAT_0107a800;

void FUN_00cf5b70()
{
    DAT_0107a800.FUN_008a8440();
}

// @f3 0x00cfb190 (community match, verified in this file)
struct Obj0108cb88
{
    void FUN_008a8440();
};

extern Obj0108cb88 DAT_0108cb88;

void FUN_00cfb190()
{
    DAT_0108cb88.FUN_008a8440();
}

// @f3 0x00cfb360 (community match, verified in this file)
struct Obj0108cc15
{
    void FUN_008a8440();
};

extern Obj0108cc15 DAT_0108cc15;

void FUN_00cfb360()
{
    DAT_0108cc15.FUN_008a8440();
}

// @f3 0x00cfb5e0 (community match, verified in this file)
struct Obj0108cc94
{
    void FUN_008a8440();
};

extern Obj0108cc94 DAT_0108cc94;

void FUN_00cfb5e0()
{
    DAT_0108cc94.FUN_008a8440();
}

// @f3 0x00cfb790 (community match, verified in this file)
struct Obj0108ccf8
{
    void FUN_008a8440();
};

extern Obj0108ccf8 DAT_0108ccf8;

void FUN_00cfb790()
{
    DAT_0108ccf8.FUN_008a8440();
}

// @f3 0x00cfba00 (community match, verified in this file)
struct Obj0108cd5c
{
    void FUN_008a8440();
};

extern Obj0108cd5c DAT_0108cd5c;

void FUN_00cfba00()
{
    DAT_0108cd5c.FUN_008a8440();
}

// @f3 0x00cfbd60 (community match, verified in this file)
struct Obj0108ce24
{
    void FUN_008a8440();
};

extern Obj0108ce24 DAT_0108ce24;

void FUN_00cfbd60()
{
    DAT_0108ce24.FUN_008a8440();
}

// @f3 0x00cfbf10 (community match, verified in this file)
struct Obj0108ce88
{
    void FUN_008a8440();
};

extern Obj0108ce88 DAT_0108ce88;

void FUN_00cfbf10()
{
    DAT_0108ce88.FUN_008a8440();
}

// @f3 0x00cfca50 (community match, verified in this file)
struct Obj0108d194
{
    void FUN_008a8440();
};

extern Obj0108d194 DAT_0108d194;

void FUN_00cfca50()
{
    DAT_0108d194.FUN_008a8440();
}

// @f3 0x00cfcc00 (community match, verified in this file)
struct Obj0108d1f8
{
    void FUN_008a8440();
};

extern Obj0108d1f8 DAT_0108d1f8;

void FUN_00cfcc00()
{
    DAT_0108d1f8.FUN_008a8440();
}

// @f3 0x00cfcdb0 (community match, verified in this file)
struct Obj0108d25c
{
    void FUN_008a8440();
};

extern Obj0108d25c DAT_0108d25c;

void FUN_00cfcdb0()
{
    DAT_0108d25c.FUN_008a8440();
}

// @f3 0x00cfcf60 (community match, verified in this file)
struct Obj0108d2b1
{
    void FUN_008a8440();
};

extern Obj0108d2b1 DAT_0108d2b1;

void FUN_00cfcf60()
{
    DAT_0108d2b1.FUN_008a8440();
}

// @f3 0x00cfd2c0 (community match, verified in this file)
struct Obj0108d388
{
    void FUN_008a8440();
};

extern Obj0108d388 DAT_0108d388;

void FUN_00cfd2c0()
{
    DAT_0108d388.FUN_008a8440();
}

// @f3 0x00cfd470 (community match, verified in this file)
struct Obj0108d3ec
{
    void FUN_008a8440();
};

extern Obj0108d3ec DAT_0108d3ec;

void FUN_00cfd470()
{
    DAT_0108d3ec.FUN_008a8440();
}

// @f3 0x00cfd620 (community match, verified in this file)
struct Obj0108d450
{
    void FUN_008a8440();
};

extern Obj0108d450 DAT_0108d450;

void FUN_00cfd620()
{
    DAT_0108d450.FUN_008a8440();
}

// @f3 0x00cfd980 (community match, verified in this file)
struct Obj0108d518
{
    void FUN_008a8440();
};

extern Obj0108d518 DAT_0108d518;

void FUN_00cfd980()
{
    DAT_0108d518.FUN_008a8440();
}

// @f3 0x00cfdce0 (community match, verified in this file)
struct Obj0108d5e0
{
    void FUN_008a8440();
};

extern Obj0108d5e0 DAT_0108d5e0;

void FUN_00cfdce0()
{
    DAT_0108d5e0.FUN_008a8440();
}

// @f3 0x00cfde90 (community match, verified in this file)
struct Obj0108d644
{
    void FUN_008a8440();
};

extern Obj0108d644 DAT_0108d644;

void FUN_00cfde90()
{
    DAT_0108d644.FUN_008a8440();
}

// @f3 0x00cfe460 (community match, verified in this file)
struct Obj0108d860
{
    void FUN_008a8440();
};

extern Obj0108d860 DAT_0108d860;

void FUN_00cfe460()
{
    DAT_0108d860.FUN_008a8440();
}

// @f3 0x00cfe9c0 (community match, verified in this file)
struct Obj0108d8d0
{
    void FUN_008a8440();
};

extern Obj0108d8d0 DAT_0108d8d0;

void FUN_00cfe9c0()
{
    DAT_0108d8d0.FUN_008a8440();
}

// @f3 0x00cfeb70 (community match, verified in this file)
struct Obj0108d934
{
    void FUN_008a8440();
};

extern Obj0108d934 DAT_0108d934;

void FUN_00cfeb70()
{
    DAT_0108d934.FUN_008a8440();
}

// @f3 0x00cfeed0 (community match, verified in this file)
struct Obj0108da08
{
    void FUN_008a8440();
};

extern Obj0108da08 DAT_0108da08;

void FUN_00cfeed0()
{
    DAT_0108da08.FUN_008a8440();
}

// @f3 0x00cff230 (community match, verified in this file)
struct Obj0108dadc
{
    void FUN_008a8440();
};

extern Obj0108dadc DAT_0108dadc;

void FUN_00cff230()
{
    DAT_0108dadc.FUN_008a8440();
}

// @f3 0x00cf5f30 (community match, verified in this file)
struct Obj0107ad1e
{
    void FUN_008a8440();
};

extern Obj0107ad1e DAT_0107ad1e;

void FUN_00cf5f30()
{
    DAT_0107ad1e.FUN_008a8440();
}

// @f3 0x00cf65d0 (community match, verified in this file)
struct Obj0107af04
{
    void FUN_008a8440();
};

extern Obj0107af04 DAT_0107af04;

void FUN_00cf65d0()
{
    DAT_0107af04.FUN_008a8440();
}

// @f3 0x00cf6800 (community match, verified in this file)
struct Obj0107af68
{
    void FUN_008a8440();
};

extern Obj0107af68 DAT_0107af68;

void FUN_00cf6800()
{
    DAT_0107af68.FUN_008a8440();
}

// @f3 0x00cf6c20 (community match, verified in this file)
struct Obj0107b158
{
    void FUN_008a8440();
};

extern Obj0107b158 DAT_0107b158;

void FUN_00cf6c20()
{
    DAT_0107b158.FUN_008a8440();
}

// @f3 0x00cf6ec0 (community match, verified in this file)
struct Obj0107b1c4
{
    void FUN_008a8440();
};

extern Obj0107b1c4 DAT_0107b1c4;

void FUN_00cf6ec0()
{
    DAT_0107b1c4.FUN_008a8440();
}

// @f3 0x00cf7070 (community match, verified in this file)
struct Obj0107b228
{
    void FUN_008a8440();
};

extern Obj0107b228 DAT_0107b228;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSDoorHavokController.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cf7070()
{
    DAT_0107b228.FUN_008a8440();
}

// @f3 0x00cf7470 (community match, verified in this file)
struct Obj0107b32c
{
    void FUN_008a8440();
};

extern Obj0107b32c DAT_0107b32c;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | BSPlayerDistanceCheckController.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cf7470()
{
    DAT_0107b32c.FUN_008a8440();
}

// @f3 0x00cf7bf0 (community match, verified in this file)
struct Obj0107b544
{
    void FUN_008a8440();
};

extern Obj0107b544 DAT_0107b544;

// pdb: `dynamic initializer for 'NiAnimationSDMObject'' | HighProcess.obj | fnv360_0822_retail, objrun_open, low
void FUN_00cf7bf0()
{
    DAT_0107b544.FUN_008a8440();
}

// @f3 0x00cf80c0 (community match, verified in this file)
struct Obj0107b688
{
    void FUN_008a8440();
};

extern Obj0107b688 DAT_0107b688;

void FUN_00cf80c0()
{
    DAT_0107b688.FUN_008a8440();
}

// @f3 0x00cf8480 (community match, verified in this file)
struct Obj0107b765
{
    void FUN_008a8440();
};

extern Obj0107b765 DAT_0107b765;

void FUN_00cf8480()
{
    DAT_0107b765.FUN_008a8440();
}

// @f3 0x00cf86d0 (community match, verified in this file)
struct Obj0107b80d
{
    void FUN_008a8440();
};

extern Obj0107b80d DAT_0107b80d;

void FUN_00cf86d0()
{
    DAT_0107b80d.FUN_008a8440();
}

// @f3 0x00cf8880 (community match, verified in this file)
struct Obj0107b835
{
    void FUN_008a8440();
};

extern Obj0107b835 DAT_0107b835;

void FUN_00cf8880()
{
    DAT_0107b835.FUN_008a8440();
}

// @f3 0x00cf97b0 (community match, verified in this file)
struct Obj0108c45c
{
    void FUN_008a8440();
};

extern Obj0108c45c DAT_0108c45c;

void FUN_00cf97b0()
{
    DAT_0108c45c.FUN_008a8440();
}

// @f3 0x00cf9a20 (community match, verified in this file)
struct Obj0108c4c4
{
    void FUN_008a8440();
};

extern Obj0108c4c4 DAT_0108c4c4;

void FUN_00cf9a20()
{
    DAT_0108c4c4.FUN_008a8440();
}

// @f3 0x00cf9ab0 (community match, verified in this file)
struct Obj0108c508
{
    void FUN_00abab70();
};

extern Obj0108c508 DAT_0108c508;

void FUN_00cf9ab0()
{
    DAT_0108c508.FUN_00abab70();
}

// @f3 0x00cf9d90 (community match, verified in this file)
struct Obj0108c648
{
    void FUN_008a8440();
};

extern Obj0108c648 DAT_0108c648;

void FUN_00cf9d90()
{
    DAT_0108c648.FUN_008a8440();
}

// @f3 0x00cfa1c0 (community match, verified in this file)
struct Obj0108c78c
{
    void FUN_008a8440();
};

extern Obj0108c78c DAT_0108c78c;

void FUN_00cfa1c0()
{
    DAT_0108c78c.FUN_008a8440();
}

// @f3 0x00cfa630 (community match, verified in this file)
struct Obj0108c8e8
{
    void FUN_008a8440();
};

extern Obj0108c8e8 DAT_0108c8e8;

void FUN_00cfa630()
{
    DAT_0108c8e8.FUN_008a8440();
}

// @f3 0x00cfa880 (community match, verified in this file)
struct Obj0108c96c
{
    void FUN_008a8440();
};

extern Obj0108c96c DAT_0108c96c;

void FUN_00cfa880()
{
    DAT_0108c96c.FUN_008a8440();
}

// @f3 0x00cfaa50 (community match, verified in this file)
struct Obj0108c9e0
{
    void FUN_008a8440();
};

extern Obj0108c9e0 DAT_0108c9e0;

void FUN_00cfaa50()
{
    DAT_0108c9e0.FUN_008a8440();
}

// @f3 0x00cfad10 (community match, verified in this file)
struct Obj0108ca52
{
    void FUN_008a8440();
};

extern Obj0108ca52 DAT_0108ca52;

void FUN_00cfad10()
{
    DAT_0108ca52.FUN_008a8440();
}

// @f3 0x00cfafc0 (community match, verified in this file)
struct Obj0108cb18
{
    void FUN_008a8440();
};

extern Obj0108cb18 DAT_0108cb18;

void FUN_00cfafc0()
{
    DAT_0108cb18.FUN_008a8440();
}

// @f3 0x00cff3e0 (community match, verified in this file)
struct Obj0108db40
{
    void FUN_008a8440();
};

extern Obj0108db40 DAT_0108db40;

void FUN_00cff3e0()
{
    DAT_0108db40.FUN_008a8440();
}

// @f3 0x00cff590 (community match, verified in this file)
struct Obj0108dba4
{
    void FUN_008a8440();
};

extern Obj0108dba4 DAT_0108dba4;

void FUN_00cff590()
{
    DAT_0108dba4.FUN_008a8440();
}

// @f3 0x00cff740 (community match, verified in this file)
struct Obj0108dc08
{
    void FUN_008a8440();
};

extern Obj0108dc08 DAT_0108dc08;

void FUN_00cff740()
{
    DAT_0108dc08.FUN_008a8440();
}

// @f3 0x00ce5f00 (community match, verified in this file)
namespace f3m_00ce5f00 {
namespace register_ce5f00 {
void __cdecl FUN_00d95550();
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
}
void FUN_00ce5f00() { register_ce5f00::FUN_00c00d1f(register_ce5f00::FUN_00d95550); }
}   // namespace f3m_00ce5f00

// @f3 0x00cff8f0 (community match, verified in this file)
struct Obj0108dc6c
{
    void FUN_008a8440();
};

extern Obj0108dc6c DAT_0108dc6c;

void FUN_00cff8f0()
{
    DAT_0108dc6c.FUN_008a8440();
}

// @f3 0x00cffaa0 (community match, verified in this file)
struct Obj0108dcdc
{
    void FUN_008a8440();
};

extern Obj0108dcdc DAT_0108dcdc;

void FUN_00cffaa0()
{
    DAT_0108dcdc.FUN_008a8440();
}

// @f3 0x00cffc70 (community match, verified in this file)
struct Obj0108dd40
{
    void FUN_008a8440();
};

extern Obj0108dd40 DAT_0108dd40;

void FUN_00cffc70()
{
    DAT_0108dd40.FUN_008a8440();
}

// @f3 0x00cffd70 (community match, verified in this file)
struct Obj0108ed84
{
    void FUN_00854b50();
};

extern Obj0108ed84 DAT_0108ed84;

// pdb: `dynamic initializer for 'NiMainSDMObject'' | NiObject.obj | fnv360_0822_retail, caller_sim, high
void FUN_00cffd70()
{
    DAT_0108ed84.FUN_00854b50();
}

// @f3 0x00cffea0 (community match, verified in this file)
struct Obj0108ef00
{
    void FUN_008474b0();
};

extern Obj0108ef00 DAT_0108ef00;

// pdb: `dynamic initializer for 'NiTexture::RendererData::ms_kReplacementFormat'' | NiTexture.obj | fnv360_0822_retail, caller_sim, high
void FUN_00cffea0()
{
    DAT_0108ef00.FUN_008474b0();
}

// @f3 0x00cea370 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea370 {
void FUN_00d96120();
void FUN_00cea370() { atexit(FUN_00d96120); }
}   // namespace f3m_00cea370

// @f3 0x00ce7eb0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce7eb0 {

void __cdecl FUN_00d95a10();

void __cdecl FUN_00ce7eb0() {
    atexit(FUN_00d95a10);
}
}   // namespace f3m_00ce7eb0

// @f3 0x00cf5d80 (community match, verified in this file)
struct Obj0107a822
{
    void FUN_008a8440();
};

extern Obj0107a822 DAT_0107a822;

void FUN_00cf5d80()
{
    DAT_0107a822.FUN_008a8440();
}

// @f3 0x00ce8ac0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8ac0 {

void __cdecl FUN_00d95c70();

// pdb: `dynamic initializer for 'LockPickMenu::sp3DCamera'' | LockPickMenu.obj | fnv360_0822_retail, objopen_prop, low
void __cdecl FUN_00ce8ac0() {
    atexit(FUN_00d95c70);
}
}   // namespace f3m_00ce8ac0

// @f3 0x00cf42d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf42d0 {

void __cdecl FUN_00d96c40();

void __cdecl FUN_00cf42d0() {
    atexit(FUN_00d96c40);
}
}   // namespace f3m_00cf42d0

// @f3 0x00cea680 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea680 {

void __cdecl FUN_00d96210();

void __cdecl FUN_00cea680() {
    atexit(FUN_00d96210);
}
}   // namespace f3m_00cea680

// @f3 0x00cf9430 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf9430 {

void __cdecl FUN_00d97970();

void __cdecl FUN_00cf9430() {
    atexit(FUN_00d97970);
}
}   // namespace f3m_00cf9430

// @f3 0x00cf4510 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4510 {

void __cdecl FUN_00d96d90();

void __cdecl FUN_00cf4510() {
    atexit(FUN_00d96d90);
}
}   // namespace f3m_00cf4510

// @f3 0x00ce6d40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce6d40 {

void __cdecl FUN_00d957c0();

void __cdecl FUN_00ce6d40() {
    atexit(FUN_00d957c0);
}
}   // namespace f3m_00ce6d40

// @f3 0x00cf4580 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4580 {

void __cdecl FUN_00d96ee0();

void __cdecl FUN_00cf4580() {
    atexit(FUN_00d96ee0);
}
}   // namespace f3m_00cf4580

// @f3 0x00ce5c50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5c50 {

void __cdecl FUN_00d954a0();

void __cdecl FUN_00ce5c50() {
    atexit(FUN_00d954a0);
}
}   // namespace f3m_00ce5c50

// @f3 0x00ce8ab0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8ab0 {

void __cdecl FUN_00d95c40();

// pdb: `dynamic initializer for 'LockPickMenu::spLockModel'' | LockPickMenu.obj | fnv360_0822_retail, objopen_prop, low
void __cdecl FUN_00ce8ab0() {
    atexit(FUN_00d95c40);
}
}   // namespace f3m_00ce8ab0

// @f3 0x00ce9e10 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9e10 {

void __cdecl FUN_00d95e90();

void __cdecl FUN_00ce9e10() {
    atexit(FUN_00d95e90);
}
}   // namespace f3m_00ce9e10

// @f3 0x00ce8500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8500 {

void __cdecl FUN_00d95b30();

void __cdecl FUN_00ce8500() {
    atexit(FUN_00d95b30);
}
}   // namespace f3m_00ce8500

// @f3 0x00ce9e00 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9e00 {

void __cdecl FUN_00d95e50();

void __cdecl FUN_00ce9e00() {
    atexit(FUN_00d95e50);
}
}   // namespace f3m_00ce9e00

// @f3 0x00cf4530 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4530 {

void __cdecl FUN_00d96df0();

void __cdecl FUN_00cf4530() {
    atexit(FUN_00d96df0);
}
}   // namespace f3m_00cf4530

// @f3 0x00cf7db0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf7db0 {

void __cdecl FUN_00d97820();

void __cdecl FUN_00cf7db0() {
    atexit(FUN_00d97820);
}
}   // namespace f3m_00cf7db0

// @f3 0x00ce5c40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5c40 {

void __cdecl FUN_00d95470();

void __cdecl FUN_00ce5c40() {
    atexit(FUN_00d95470);
}
}   // namespace f3m_00ce5c40

// @f3 0x00ce1390 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce1390 {

void __cdecl FUN_00d94d70();

void __cdecl FUN_00ce1390() {
    atexit(FUN_00d94d70);
}
}   // namespace f3m_00ce1390

// @f3 0x00cf4540 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4540 {

void __cdecl FUN_00d96e20();

void __cdecl FUN_00cf4540() {
    atexit(FUN_00d96e20);
}
}   // namespace f3m_00cf4540

// @f3 0x00ce5f10 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5f10 {

void __cdecl FUN_00d95580();

void __cdecl FUN_00ce5f10() {
    atexit(FUN_00d95580);
}
}   // namespace f3m_00ce5f10

// @f3 0x00ce5c30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5c30 {

void __cdecl FUN_00d95440();

void __cdecl FUN_00ce5c30() {
    atexit(FUN_00d95440);
}
}   // namespace f3m_00ce5c30

// @f3 0x00cf4550 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4550 {

void __cdecl FUN_00d96e50();

void __cdecl FUN_00cf4550() {
    atexit(FUN_00d96e50);
}
}   // namespace f3m_00cf4550

// @f3 0x00ceb850 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ceb850 {

void __cdecl FUN_00d965b0();

void __cdecl FUN_00ceb850() {
    atexit(FUN_00d965b0);
}
}   // namespace f3m_00ceb850

// @f3 0x00cf42b0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf42b0 {

void __cdecl FUN_00d96c00();

void __cdecl FUN_00cf42b0() {
    atexit(FUN_00d96c00);
}
}   // namespace f3m_00cf42b0

// @f3 0x00cecaa0 (community match, verified in this file)
namespace Thunk_00cecaa0
{
struct Owner
{
    void FUN_008a8440();
};

extern Owner DAT_01077da8;

void FUN_00cecaa0()
{
    DAT_01077da8.FUN_008a8440();
}
}

// @f3 0x00ce5bd0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5bd0 {
namespace f3m_00ce5bd0 {
void __cdecl FUN_00d95430();
}
void __cdecl FUN_00ce5bd0()
{
    atexit(f3m_00ce5bd0::FUN_00d95430);
}
}   // namespace f3m_00ce5bd0

// @f3 0x00ce3870 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce3870 {
namespace f3m_00ce3870 {
void __cdecl FUN_00d951c0();
}
void __cdecl FUN_00ce3870()
{
    atexit(f3m_00ce3870::FUN_00d951c0);
}
}   // namespace f3m_00ce3870

// @f3 0x00ce43a0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce43a0 {
namespace f3m_00ce43a0 {
void __cdecl FUN_00d95230();
}
void __cdecl FUN_00ce43a0()
{
    atexit(f3m_00ce43a0::FUN_00d95230);
}
}   // namespace f3m_00ce43a0

// @f3 0x00ce5c60 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce5c60 {
namespace f3m_00ce5c60 {
void __cdecl FUN_00d954d0();
}
void __cdecl FUN_00ce5c60()
{
    atexit(f3m_00ce5c60::FUN_00d954d0);
}
}   // namespace f3m_00ce5c60

// @f3 0x00ce8110 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce8110 {
namespace f3m_00ce8110 {
void __cdecl FUN_00d95ad0();
}
void __cdecl FUN_00ce8110()
{
    atexit(f3m_00ce8110::FUN_00d95ad0);
}
}   // namespace f3m_00ce8110

// @f3 0x00ce9280 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9280 {
namespace f3m_00ce9280 {
void __cdecl FUN_00d95d70();
}
void __cdecl FUN_00ce9280()
{
    atexit(f3m_00ce9280::FUN_00d95d70);
}
}   // namespace f3m_00ce9280

// @f3 0x00ce9290 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9290 {
namespace f3m_00ce9290 {
void __cdecl FUN_00d95db0();
}
void __cdecl FUN_00ce9290()
{
    atexit(f3m_00ce9290::FUN_00d95db0);
}
}   // namespace f3m_00ce9290

// @f3 0x00ce9e30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9e30 {
namespace f3m_00ce9e30 {
void __cdecl FUN_00d95ee0();
}
void __cdecl FUN_00ce9e30()
{
    atexit(f3m_00ce9e30::FUN_00d95ee0);
}
}   // namespace f3m_00ce9e30

// @f3 0x00ce9e50 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00ce9e50 {
namespace f3m_00ce9e50 {
void __cdecl FUN_00d96030();
}
void __cdecl FUN_00ce9e50()
{
    atexit(f3m_00ce9e50::FUN_00d96030);
}
}   // namespace f3m_00ce9e50

// @f3 0x00cea1d0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea1d0 {
namespace f3m_00cea1d0 {
void __cdecl FUN_00d960c0();
}
void __cdecl FUN_00cea1d0()
{
    atexit(f3m_00cea1d0::FUN_00d960c0);
}
}   // namespace f3m_00cea1d0

// @f3 0x00cea1e0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cea1e0 {
namespace f3m_00cea1e0 {
void __cdecl FUN_00d960f0();
}
void __cdecl FUN_00cea1e0()
{
    atexit(f3m_00cea1e0::FUN_00d960f0);
}
}   // namespace f3m_00cea1e0

// @f3 0x00cf1d30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf1d30 {
namespace f3m_00cf1d30 {
void __cdecl FUN_00d968a0();
}
void __cdecl FUN_00cf1d30()
{
    atexit(f3m_00cf1d30::FUN_00d968a0);
}
}   // namespace f3m_00cf1d30

// @f3 0x00cf1d40 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf1d40 {
namespace f3m_00cf1d40 {
void __cdecl FUN_00d968c0();
}
void __cdecl FUN_00cf1d40()
{
    atexit(f3m_00cf1d40::FUN_00d968c0);
}
}   // namespace f3m_00cf1d40

// @f3 0x00cf40f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf40f0 {
namespace f3m_00cf40f0 {
void __cdecl FUN_00d96bc0();
}
void __cdecl FUN_00cf40f0()
{
    atexit(f3m_00cf40f0::FUN_00d96bc0);
}
}   // namespace f3m_00cf40f0

// @f3 0x00cf44f0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf44f0 {
namespace f3m_00cf44f0 {
void __cdecl FUN_00d96d30();
}
void __cdecl FUN_00cf44f0()
{
    atexit(f3m_00cf44f0::FUN_00d96d30);
}
}   // namespace f3m_00cf44f0

// @f3 0x00cf4500 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4500 {
namespace f3m_00cf4500 {
void __cdecl FUN_00d96d60();
}
void __cdecl FUN_00cf4500()
{
    atexit(f3m_00cf4500::FUN_00d96d60);
}
}   // namespace f3m_00cf4500

// @f3 0x00cf4560 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf4560 {
namespace f3m_00cf4560 {
void __cdecl FUN_00d96e80();
}
void __cdecl FUN_00cf4560()
{
    atexit(f3m_00cf4560::FUN_00d96e80);
}
}   // namespace f3m_00cf4560

// @f3 0x00cf5bc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf5bc0 {
namespace f3m_00cf5bc0 {
void __cdecl FUN_00d97500();
}
void __cdecl FUN_00cf5bc0()
{
    atexit(f3m_00cf5bc0::FUN_00d97500);
}
}   // namespace f3m_00cf5bc0

// @f3 0x00cf7dc0 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cf7dc0 {
namespace f3m_00cf7dc0 {
void __cdecl FUN_00d97830();
}
void __cdecl FUN_00cf7dc0()
{
    atexit(f3m_00cf7dc0::FUN_00d97830);
}
}   // namespace f3m_00cf7dc0

// @f3 0x00cfe810 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfe810 {
namespace f3m_00cfe810 {
void __cdecl FUN_00d98040();
}
void __cdecl FUN_00cfe810()
{
    atexit(f3m_00cfe810::FUN_00d98040);
}
}   // namespace f3m_00cfe810

// @f3 0x00cfff30 (community match, verified in this file)
#include <stdlib.h>
namespace f3m_00cfff30 {
namespace f3m_00cfff30 {
void __cdecl FUN_00d98330();
}
void __cdecl FUN_00cfff30()
{
    atexit(f3m_00cfff30::FUN_00d98330);
}
}   // namespace f3m_00cfff30

// @f3 0x00ce99f0 (community match, verified in this file)
extern unsigned char DAT_d95e20;
namespace f3m_00ce99f0 {
namespace Wrap_00ce99f0 {
extern int FUN_c00d24(unsigned int a);
void FUN_00ce99f0() { FUN_c00d24((unsigned int)&DAT_d95e20); }
}
}   // namespace f3m_00ce99f0

// @f3 0x00cf4570 (community match, verified in this file)
extern unsigned char DAT_d96eb0;
namespace f3m_00cf4570 {
namespace Wrap_00cf4570 {
extern int FUN_c00d24(unsigned int a);
void FUN_00cf4570() { FUN_c00d24((unsigned int)&DAT_d96eb0); }
}
}   // namespace f3m_00cf4570

// @f3 0x00cf4d60 (community match, verified in this file)
extern unsigned char DAT_d96f40;
namespace f3m_00cf4d60 {
namespace Wrap_00cf4d60 {
extern int FUN_c00d24(unsigned int a);
void FUN_00cf4d60() { FUN_c00d24((unsigned int)&DAT_d96f40); }
}
}   // namespace f3m_00cf4d60

// @f3 0x00cf5bd0 (community match, verified in this file)
extern unsigned char DAT_d97540;
namespace f3m_00cf5bd0 {
namespace Wrap_00cf5bd0 {
extern int FUN_c00d24(unsigned int a);
void FUN_00cf5bd0() { FUN_c00d24((unsigned int)&DAT_d97540); }
}
}   // namespace f3m_00cf5bd0

// @f3 0x00cf7280 (community match, verified in this file)
extern unsigned char DAT_d97810;
namespace f3m_00cf7280 {
namespace Wrap_00cf7280 {
extern int FUN_c00d24(unsigned int a);
void FUN_00cf7280() { FUN_c00d24((unsigned int)&DAT_d97810); }
}
}   // namespace f3m_00cf7280

// @f3 0x00cf8490 (community match, verified in this file)
extern unsigned char DAT_d978d0;
namespace f3m_00cf8490 {
namespace Wrap_00cf8490 {
extern int FUN_c00d24(unsigned int a);
void FUN_00cf8490() { FUN_c00d24((unsigned int)&DAT_d978d0); }
}
}   // namespace f3m_00cf8490

// @f3 0x00ce86e0 (community match, verified in this file)
struct SettingCE86E0
{
    void FUN_0043b7f0(const char*, const char*); 
    __forceinline SettingCE86E0(const char* name, const char* value) { FUN_0043b7f0(name, value); }
    ~SettingCE86E0();

    int type;
    const char* name;
    const char* value;
};

extern const char DAT_00e063f4[], DAT_00e0640c[];
extern const char DAT_00e063c4[], DAT_00e063dc[];
extern const char DAT_00e06398[], DAT_00e063b0[];
extern const char DAT_00e06368[], DAT_00e06380[];
extern const char DAT_00e0633c[], DAT_00e06358[];

struct SettingsCE86E0
{
    SettingCE86E0 first, second, third, fourth, fifth;

    __forceinline SettingsCE86E0()
        : first(DAT_00e063f4, DAT_00e0640c),
          second(DAT_00e063c4, DAT_00e063dc),
          third(DAT_00e06398, DAT_00e063b0),
          fourth(DAT_00e06368, DAT_00e06380),
          fifth(DAT_00e0633c, DAT_00e06358)
    {}
};

SettingsCE86E0 DAT_01076a8c;

// @f3 0x00cf6a80 (community match, verified in this file)
#include <math.h>
extern float DAT_0107b104;
namespace f3m_00cf6a80 {
void __cdecl FUN_00cf6a80() {
    float root = (float)sqrt(0.9590659737586975);
    DAT_0107b104 = (float)(1.000311017036438 / root);
}
}   // namespace f3m_00cf6a80

// @f3 0x00cf6a40 (community match, verified in this file)
namespace f3m_00cf6a40 {
struct Entry {
    unsigned int unk00, unk04, unk08;
    void FUN_00724180();
    void FUN_00b0ce70();
};

struct Tables {
    int counters[6];
    Entry entries[3];
};

extern Tables DAT_0107afb4;
typedef void (Entry::*EntryOperation)();
void __stdcall FUN_00c01f76(Entry* entries, unsigned int stride, unsigned int count,
                            EntryOperation construct, EntryOperation destroy);
int __cdecl FUN_00c00d1f(void (__cdecl* cleanup)());
void __cdecl FUN_00d97750();

void __cdecl FUN_00cf6a40()
{
    FUN_00c01f76(DAT_0107afb4.entries, sizeof(Entry), 3,
                 &Entry::FUN_00724180, &Entry::FUN_00b0ce70);
    int* p = DAT_0107afb4.counters + 3;
    int* const end = DAT_0107afb4.counters + 6;
    do {
        p[-3] = 0;
        *p = 0;
        ++p;
    } while (reinterpret_cast<int>(p) < reinterpret_cast<int>(end));
    FUN_00c00d1f(FUN_00d97750);
}
}
