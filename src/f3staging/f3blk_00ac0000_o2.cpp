// src/f3staging/f3blk_00ac0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00ac21e0 (community match, verified in this file)
extern const char* DAT_0116ec38;
extern const char DAT_00de0370[];
extern const char DAT_00e8cc58[];
extern const char DAT_00e8cc4c[];
extern const char DAT_00e8cc34[];
extern const char DAT_00e8cc24[];
extern const char DAT_00e8cc0c[];
extern const char DAT_00e8cbfc[];
extern const char DAT_00e8cbec[];
extern const char DAT_00e8cbd8[];
extern const char DAT_00e8cbcc[];
extern const char DAT_00e8cbb8[];
namespace f3m_00ac21e0 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);

__forceinline char* FormatViewerFloat(const char* label, const float& value)
{
    return FUN_00847dd0(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

struct ViewerColor
{
    char* FUN_0083f9c0(const char* label);
    float r, g, b, a;
};


class NiPSysEmitter
{
public:
    void FUN_00ac60d0(ViewerStrings* strings);
    void FUN_00ac21e0(ViewerStrings* strings);

    unsigned int fields00[6];
    float speed, speedVariation;
    float declination, declinationVariation;
    float planarAngle, planarAngleVariation;
    ViewerColor initialColor;
    float initialRadius, radiusVariation, lifespan, lifespanVariation;
};

// pdb: NiPSysEmitter::GetViewerStrings | NiPSysEmitter.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void NiPSysEmitter::FUN_00ac21e0(ViewerStrings* strings)
{
    FUN_00ac60d0(strings);
    strings->Add(FUN_00847b50(DAT_0116ec38));
    strings->Add(FormatViewerFloat(DAT_00de0370, speed));
    strings->Add(FormatViewerFloat(DAT_00e8cc58, speedVariation));
    strings->Add(FormatViewerFloat(DAT_00e8cc4c, declination));
    strings->Add(FormatViewerFloat(DAT_00e8cc34, declinationVariation));
    strings->Add(FormatViewerFloat(DAT_00e8cc24, planarAngle));
    strings->Add(FormatViewerFloat(DAT_00e8cc0c, planarAngleVariation));
    strings->Add(initialColor.FUN_0083f9c0(DAT_00e8cbfc));
    strings->Add(FormatViewerFloat(DAT_00e8cbec, initialRadius));
    strings->Add(FormatViewerFloat(DAT_00e8cbd8, radiusVariation));
    strings->Add(FormatViewerFloat(DAT_00e8cbcc, lifespan));
    strings->Add(FormatViewerFloat(DAT_00e8cbb8, lifespanVariation));
}
}   // namespace f3m_00ac21e0

// @f3 0x00ad0800 (community match, verified in this file)
extern const char* DAT_0116eea0;
extern const char DAT_00de039c[];
extern const char DAT_00e8f4ec[];
extern const char DAT_00e8f4e0[];
extern const char DAT_00e8f4cc[];
extern const char DAT_00e8f4b8[];
extern const char DAT_00e8f4a8[];
extern const char DAT_00e8f498[];
extern const char DAT_00e8f490[];
namespace f3m_00ad0800 {
char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847dd0(const char* label, float value);

__forceinline char* FormatViewerFloat(const char* label, const float& value)
{
    return FUN_00847dd0(label, value);
}

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

char* __cdecl FUN_00847b90(const char* label, bool value);


struct ViewerVector
{
    char* FUN_00823dc0(const char* label);
    float x, y, z;
};

class NiPSysAirFieldModifier
{
public:
    void FUN_00ad1b10(ViewerStrings* strings);
    void FUN_00ad0800(ViewerStrings* strings);

    unsigned int fields00[16];
    ViewerVector direction, unitDirection;
    float airFriction, inheritVelocity;
    bool inheritRotation, componentOnly, enableSpread;
    float spread;
};

// pdb: NiPSysAirFieldModifier::GetViewerStrings | NiPSysAirFieldModifier.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void NiPSysAirFieldModifier::FUN_00ad0800(ViewerStrings* strings)
{
    FUN_00ad1b10(strings);
    strings->Add(FUN_00847b50(DAT_0116eea0));
    strings->Add(direction.FUN_00823dc0(DAT_00de039c));
    strings->Add(unitDirection.FUN_00823dc0(DAT_00e8f4ec));
    strings->Add(FormatViewerFloat(DAT_00e8f4e0, airFriction));
    strings->Add(FormatViewerFloat(DAT_00e8f4cc, inheritVelocity));
    strings->Add(FUN_00847b90(DAT_00e8f4b8, inheritRotation));
    strings->Add(FUN_00847b90(DAT_00e8f4a8, componentOnly));
    strings->Add(FUN_00847b90(DAT_00e8f498, enableSpread));
    strings->Add(FormatViewerFloat(DAT_00e8f490, spread));
}
}   // namespace f3m_00ad0800

// @f3 0x00adec60 (community match, verified in this file)
#include <intrin.h>
extern volatile unsigned int DAT_01179af4;
extern unsigned char DAT_0116f43c, DAT_0116f217, DAT_0116f20e;
extern int DAT_0116efc8;
extern int DAT_0116f3d4, DAT_0116efb0;
extern float DAT_01173610;
namespace f3m_00adec60 {


struct ThreadState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int context;
};
struct MemScope
{
    ThreadState* state;
    unsigned int old;
    __forceinline MemScope()
    {
        unsigned int index = DAT_01179af4;
        state = ((ThreadState**)__readfsdword(0x2c))[index];
        old = state->context;
        state->context = 0x1c;
    }
    __forceinline ~MemScope()
    {
        state->context = old;
    }
};
struct PassArray
{
    int unk00;
    void** passes;
    int unk08, unk0c;
    unsigned int count;
    void FUN_00b2c0b0(void* geometry, unsigned short pass, bool enabled, unsigned char lights, void* l0, void* l1,
                      void* l2, void* l3);
};
struct PassPointer
{
    PassArray* pointer;
    __forceinline PassArray* operator->() const
    {
        return pointer;
    }
    __forceinline operator PassArray*() const
    {
        return pointer;
    }
};
struct Light
{
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
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    unsigned char active;
};
void __cdecl FUN_00b2ae40(void*, int, void*);
inline int ShadowFeatureEnabled()
{
    return (DAT_0116efc8 & 16) > 0;
}
struct ShaderPassBuilder
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags;
    int unk28, unk2c, unk30, unk34;
    unsigned int cached;
    PassPointer array;
    void FUN_00b2b740(int);
    unsigned short FUN_00af3490();
    void* FUN_00af32e0(void**);
    Light* FUN_00af3280(void**);
    Light* FUN_00af3360(void**);
    PassArray* FUN_00adec60(void*, unsigned int, int, unsigned int, int, int);
};
// Fallout 3 shader pass construction; adapted from FNV 0x00b60790.
PassArray* ShaderPassBuilder::FUN_00adec60(void* geometry, unsigned int mode, int unused, unsigned int variant,
                                           int unused2, int FlushUsageData)
{
    MemScope scope;
    if (cached != mode)
    {
        FUN_00b2b740(2);
        array->count = 0;
        void* position = 0;
        unsigned short lightCount = DAT_0116f43c ? FUN_00af3490() : 0;
        bool special = (flags & 0x400) > 0;
        bool textured = (flags & 0x1000) > 0;
        bool alternate = (flags & 0x2000) > 0;
        bool extra = !DAT_0116f217 && DAT_0116f3d4 && (DAT_0116efc8 & 0x20) && DAT_0116efb0 >= 2 &&
                     (unsigned int)DAT_01173610 != 0;
        unsigned int pass = (DAT_0116f20e ? 0x246 : 0);
        unsigned short noLights = 0;
        pass += lightCount > noLights ? 0x14 : 0;
        if (special)
        {
            if (textured)
            {
                if (!extra)
                    array->FUN_00b2c0b0(geometry, pass + 0x19, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00b2c0b0(geometry, pass + 0x21, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if (!extra)
                    array->FUN_00b2c0b0(geometry, pass + 0x17, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00b2c0b0(geometry, pass + 0x1f, true, 0, 0, 0, 0, 0);
            }
        }
        else if (textured)
        {
            if (alternate)
                array->FUN_00b2c0b0(geometry, pass + 0x27, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00b2c0b0(geometry, pass + 0x18, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00b2c0b0(geometry, pass + 0x20, true, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (alternate)
                array->FUN_00b2c0b0(geometry, pass + 0x26, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00b2c0b0(geometry, pass + 0x16, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00b2c0b0(geometry, pass + 0x1e, true, 0, 0, 0, 0, 0);
            }
        }
        if (lightCount > 0)
        {
            void* light = FUN_00af32e0(&position);
            FUN_00b2ae40(array->passes[array->count - 1], 1, light);
        }
        if (DAT_0116efb0 >= 3)
        {
            int enabled = ShadowFeatureEnabled();
            const bool& bShadow = *(bool*)&enabled;
            if (bShadow)
            {
                Light* light = FUN_00af3280(&position);
                while (light)
                {
                    if (light->active)
                    {
                        if (textured)
                        {
                            if (alternate)
                                array->FUN_00b2c0b0(geometry, 0x287, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00b2c0b0(geometry, 0x285, false, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            if (alternate)
                                array->FUN_00b2c0b0(geometry, 0x286, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00b2c0b0(geometry, 0x284, false, 1, light, 0, 0, 0);
                        }
                    }
                    light = FUN_00af3360(&position);
                }
            }
        }
        cached = mode | (variant << 8);
    }
    return array;
}
}   // namespace f3m_00adec60

// @f3 0x00ac60d0 (community match, verified in this file)
extern const char* DAT_0116ec68;
extern const char DAT_00df2d3c[];
extern const char DAT_00e8d278[];
extern const char DAT_00e220d8[];
namespace f3m_00ac60d0 {


char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847e70(const char* label, void* value);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);
char* __cdecl FUN_00847b90(const char* label, int value);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class NiPSysModifier
{
public:
    void FUN_00825b40(ViewerStrings* strings);

    unsigned int unk00;
    unsigned int unk04;
    const char* name;
    unsigned int order;
    unsigned int unk10;
    unsigned char active;
};

class NiPSysModifierShell : public NiPSysModifier
{
public:
    void FUN_00ac60d0(ViewerStrings* strings);
};

// pdb: NiPSysModifier::GetViewerStrings | NiPSysModifier.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void NiPSysModifierShell::FUN_00ac60d0(ViewerStrings* strings)
{
    FUN_00825b40(strings);
    strings->Add(FUN_00847b50(DAT_0116ec68));
    void* nv = (void*)name;
    strings->Add(FUN_00847e70(DAT_00df2d3c, nv));
    strings->Add(FUN_00847d80(DAT_00e8d278, order));
    strings->Add(FUN_00847b90(DAT_00e220d8, active));
}
}   // namespace f3m_00ac60d0

// @f3 0x00adbe10 (community match, verified in this file)
#include <intrin.h>
extern "C" const unsigned int _tls_index;
struct State23 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    int mode;
};
extern __declspec(thread) State23 DAT_0117c000;
__forceinline State23* GetState23() { return &DAT_0117c000; }
struct Guard23 {
    int previous;
    Guard23(int mode) { State23* state=GetState23(); previous=state->mode; state->mode=mode; }
    ~Guard23() { GetState23()->mode=previous; }
};
struct Shader23 { void FUN_00b55360(int); };
Shader23* FUN_00b55a60();
struct Ref23 { Shader23* value; void FUN_008e9650(Shader23*); };
extern Ref23 DAT_0116f35c;
extern int DAT_0116f2f8;
void __cdecl FUN_00adbe10() {
    if(DAT_0116f2f8) {
        if(!DAT_0116f35c.value) {
            Guard23 guard(5);
            DAT_0116f35c.FUN_008e9650(FUN_00b55a60());
        }
        if(DAT_0116f35c.value) DAT_0116f35c.value->FUN_00b55360(0);
    }
}

// @f3 0x00ad2d80 (community match, verified in this file)
#include <math.h>
namespace task1413 {
struct FadePt3
{
    float x, y, z;
    FadePt3()
    {}
    FadePt3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
    FadePt3 operator-(const FadePt3& o) const
    {
        return FadePt3(x - o.x, y - o.y, z - o.z);
    }
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
};

struct FadeCamera
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    FadePt3 m_kWorldTranslate;  // 0x8c
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    float m_fTrailingValue;  // 0x110
};

struct FadeCuller
{
    int unk00;
    int unk04;
    int unk08;
    FadeCamera* m_pCamera;  // 0x0c
};

struct FadeQueue
{
    void FUN_00ae6dc0(const char* name, int b);
    void FUN_00ae68b0();
};

struct FadeQueueHolder
{
    int unk00;
    int unk04;
    FadeQueue* m_pQueue;
};

extern char DAT_01067af0;
extern float DAT_01067af4[11];
extern float DAT_01067b1c;
extern float DAT_01067b20;
extern float DAT_01067b24;
extern float DAT_01067b28;
extern float DAT_01067b2c;
extern float DAT_01067b30;
extern float DAT_01090bac;
extern int DAT_0116eee4;
extern FadeQueueHolder* DAT_0108f048;
extern int DAT_0116fd88;
extern char DAT_0108edc8[];

float FUN_0090d870(float a, float b);
float FUN_00401e20(float a, float b);
bool FUN_00424d20(void* list, FadeQueue* q);

struct FadeNodeObj;
void FUN_00aeeec0(FadeNodeObj* node, float fade);

struct FadeNodeObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const char* m_pcName;  // 0x20
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiValue1;  // 0x30
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    FadePt3 m_kWorldTranslate;  // 0x8c
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    float fNearDistSqr;      // 0xac
    float fFarDistSqr;       // 0xb0
    float fLastFade;         // 0xb4
    float fCurrentFade;      // 0xb8
    float m_fFadeDelta;      // 0xbc
    float fTimeSinceUpdate;  // 0xc0
    int eMultType;           // 0xc4
    int iFrameCounter;       // 0xc8

    bool IsCulledFlag() const
    {
        return (m_uiValue1 >> 15) & 1;
    }
    bool IsFadedIn() const
    {
        return (m_uiValue1 >> 14) & 1;
    }
    bool IsAlwaysFade() const
    {
        return (m_uiValue1 >> 28) & 1;
    }
    void FUN_0082d9f0(FadeCuller& culler);
    float FUN_00ad28b0();
    void BSFadeNode_OnVisible(FadeCuller& culler);
};

// Updates the fade state of a FadeNodeObj based on camera distance and fade thresholds, queueing a batch render when the fade target is in progress.
// @fnv 0x00b4e490
// pdb: BSFadeNode::OnVisible | BSFadeNode.obj | fnv360_0822_retail, udata, high
void FadeNodeObj::BSFadeNode_OnVisible(FadeCuller& culler)
{
    if (!DAT_01067af0 || IsCulledFlag())
    {
        FUN_0082d9f0(culler);
        return;
    }
    float fFadeAmount;
    if (eMultType == 6)
    {
        if (!IsFadedIn())
        {
            fFadeAmount = FUN_0090d870(1.0f, FUN_0090d870(DAT_01090bac / DAT_01067b1c, DAT_01067b30) + fCurrentFade);
            fCurrentFade = fFadeAmount;
            FUN_00aeeec0(this, fFadeAmount);
            fLastFade = fCurrentFade;
            if (fCurrentFade >= 1.0f)
                m_uiValue1 |= 0x4000;
        }
        FUN_0082d9f0(culler);
        return;
    }

    float fMult = DAT_01067af4[eMultType];
    FadeCamera* pCamera = culler.m_pCamera;
    float fDist;
    FadePt3 kDiff;
    if (fMult > 0.0f)
    {
        fDist = pCamera->m_fTrailingValue / fMult;
    }
    else
    {
        fDist = 0.2f;
        m_uiValue1 |= 0x4000;
        fLastFade = fCurrentFade = 1.0f;
        FUN_00aeeec0(this, *(volatile float*)&fCurrentFade);
    }

    kDiff = m_kWorldTranslate - pCamera->m_kWorldTranslate;
    fDist = kDiff.Length() * fDist;
    fFadeAmount = 1.0f;
    float fNear = fNearDistSqr * DAT_01067b2c;
    if (fDist > fNear)
    {
        float fFar = fFarDistSqr * DAT_01067b2c;
        fFadeAmount = 1.0f - (fDist - fNear) / (fFar - fNear);
    }
    if (eMultType != 8 && iFrameCounter < DAT_0116eee4 - 20 && m_fFadeDelta < 600.0f)
    {
        if (fFadeAmount > DAT_01067b24 || (IsFadedIn() && fFadeAmount > DAT_01067b28))
        {
            FUN_00aeeec0(this, 1.0f);
            fLastFade = fCurrentFade = 1.0f;
            m_uiValue1 |= 0x4000;
        }
        else
        {
            FUN_00aeeec0(this, 0.0f);
            fLastFade = fCurrentFade = 0.0f;
            m_uiValue1 &= ~0x4000;
        }
    }
    iFrameCounter = DAT_0116eee4;

    float fTarget = FUN_00ad28b0();
    bool bFadeQueuedCur = false;
    if (IsFadedIn() && fTarget > 0.0f && fTarget < 1.0f)
    {
        FadeQueue* m_pPrimaryTaskProcessor = DAT_0108f048->m_pQueue;
        if (FUN_00424d20(&DAT_0116fd88, m_pPrimaryTaskProcessor))
        {
            m_pPrimaryTaskProcessor->FUN_00ae6dc0(m_pcName ? m_pcName : DAT_0108edc8, 1);
            bFadeQueuedCur = true;
            FUN_00aeeec0(this, fTarget);
            fLastFade = fCurrentFade = fTarget;
        }
    }
    else if ((!IsFadedIn() && fFadeAmount > DAT_01067b24) ||
             (fCurrentFade > 0.0f && fCurrentFade < 1.0f && fFadeAmount > DAT_01067b24))
    {
        fFadeAmount = FUN_0090d870(1.0f, FUN_0090d870(DAT_01090bac / DAT_01067b1c, DAT_01067b30) + fCurrentFade);
        fCurrentFade = fFadeAmount;
        FUN_00aeeec0(this, fFadeAmount);
        fLastFade = fCurrentFade;
        if (fCurrentFade >= 1.0f)
            m_uiValue1 |= 0x4000;
    }
    else if ((IsFadedIn() && fFadeAmount < DAT_01067b28) ||
             (fCurrentFade < 1.0f && fCurrentFade > 0.0f && fFadeAmount < DAT_01067b28))
    {
        fCurrentFade = FUN_00401e20(0.0f, fCurrentFade - FUN_0090d870(DAT_01090bac / DAT_01067b20, DAT_01067b30));
        FUN_00aeeec0(this, fCurrentFade);
        fLastFade = fCurrentFade;
        if (fCurrentFade <= 0.0f)
            m_uiValue1 &= ~0x4000;
    }

    if (fCurrentFade > 0.0f && fTarget != 0.0f)
        FUN_0082d9f0(culler);
    if (bFadeQueuedCur)
        DAT_0108f048->m_pQueue->FUN_00ae68b0();
}
}  // namespace task1413

// @f3 0x00acdad0 (community match, verified in this file)
extern const char* DAT_0116ee78;
namespace f3m_00acdad0 {
struct Sink_acdad0 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60(f3m_00ac21e0::ViewerStrings* strings);
};
struct Emit_acdad0 {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    Sink_acdad0* unk18;
    void FUN_00acdad0(f3m_00ac21e0::ViewerStrings* strings);
};
// pdb: NiPSysColliderManager::GetViewerStrings | NiPSysColliderManager.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void Emit_acdad0::FUN_00acdad0(f3m_00ac21e0::ViewerStrings* strings)
{
    ((f3m_00ac21e0::NiPSysEmitter*)this)->FUN_00ac60d0(strings);
    strings->Add(f3m_00ac21e0::FUN_00847b50(DAT_0116ee78));
    unk18->slot60(strings);
}
}   // namespace f3m_00acdad0

// @f3 0x00ad3ab0 (community match, verified in this file)
namespace f3m_00ad3ab0 {

// pdb: BSShaderProperty::GetSIBlockRenderPasses | DistantLODShaderProperty.obj | fnv360_0822_retail, objrun, low
unsigned short __stdcall FUN_00ad3ab0(int a)
{
    return 1;
}
}   // namespace f3m_00ad3ab0

// @f3 0x00aca720 (community match, verified in this file)
extern char FUN_00e8dfe4;
namespace f3m_00aca720 {
extern void* __cdecl FUN_0089eb90(unsigned int size);

struct Obj
{
    void* vtable;
    unsigned int unk04[5];
    float f18;
    unsigned short w1c;
    float f20;
    unsigned short w24;
    float f28;

    void FUN_00ac5e10();
};


void* __cdecl FUN_00aca720()
{
    Obj* esi = (Obj*)FUN_0089eb90(0x2c);
    if (esi)
    {
        esi->FUN_00ac5e10();
        esi->vtable = &FUN_00e8dfe4;
        float zero = 0.0f;
        esi->f18 = zero;
        esi->f20 = zero;
        esi->f28 = zero;
        esi->w1c = 0;
        esi->w24 = 0;
        return esi;
    }
    else
    {
        return 0;
    }
}
}   // namespace f3m_00aca720

// @f3 0x00adaec0 (community match, verified in this file)
struct Obj {
    virtual void slot0();
    virtual void DeleteThis();
    volatile long ref;
    void DecRefCount() { if (InterlockedDecrement(&ref) == 0) DeleteThis(); }
    void IncRefCount() { InterlockedIncrement(&ref); }
};

extern Obj* DAT_0116f3dc;

void __cdecl FUN_00adaec0(Obj* arg)
{
    if (DAT_0116f3dc != arg) {
        if (DAT_0116f3dc) {
            DAT_0116f3dc->DecRefCount();
        }
        DAT_0116f3dc = arg;
        if (arg) {
            arg->IncRefCount();
        }
    }
}

// @f3 0x00acbea0 (community match, verified in this file)
extern const char* DAT_0116ee50;
namespace f3m_00acbea0 {
struct StrArr;
void __stdcall AppendCameraPathEntries(StrArr* strings);
char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_0096ad30(unsigned int capacity);
    void FUN_0096ae90(unsigned int index, char*& value);

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

void __stdcall FUN_00acbea0(ViewerStrings* strings)
{
    AppendCameraPathEntries((StrArr*)strings);
    char* value = FUN_00847b50(DAT_0116ee50);
    unsigned int index = strings->firstFree;
    if (index >= strings->capacity)
        strings->FUN_0096ad30(index + strings->growBy);
    strings->FUN_0096ae90(index, value);
}
}   // namespace f3m_00acbea0

// @f3 0x00ad0b80 (community match, verified in this file)
extern const char* DAT_0116eea8;
namespace f3m_00ad0b80 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ad27f0(f3m_00ad0800::ViewerStrings* strings);

// pdb: NiPSysAirFieldAirFrictionCtlr::GetViewerStrings | NiPSysAirFieldAirFrictionCtlr.obj | fnv360_0721_retail, objrun_open, low
// pdb params: pkStrings
void __stdcall FUN_00ad0b80(f3m_00ad0800::ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116eea8));
}
}   // namespace f3m_00ad0b80

// @f3 0x00ad0ce0 (community match, verified in this file)
extern const char* DAT_0116eeb0;
namespace f3m_00ad0ce0 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ad27f0(f3m_00ad0800::ViewerStrings* strings);

void __stdcall FUN_00ad0ce0(f3m_00ad0800::ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116eeb0));
}
}   // namespace f3m_00ad0ce0

// @f3 0x00ad1660 (community match, verified in this file)
extern const char* DAT_0116eeb8;
namespace f3m_00ad1660 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ac5000(f3m_00ad0800::ViewerStrings* strings);

// pdb: NiMeshPSysData::GetViewerStrings | NiMeshPSysData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void __stdcall FUN_00ad1660(f3m_00ad0800::ViewerStrings* strings)
{
    FUN_00ac5000(strings);
    strings->Add(FUN_00847b50(DAT_0116eeb8));
}
}   // namespace f3m_00ad1660

// @f3 0x00ad27f0 (community match, verified in this file)
extern const char* DAT_0116eed8;
namespace f3m_00ad27f0 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ac67c0(f3m_00ad0800::ViewerStrings* strings);

// pdb: NiPSysModifierFloatCtlr::GetViewerStrings | NiPSysModifierFloatCtlr.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void __stdcall FUN_00ad27f0(f3m_00ad0800::ViewerStrings* strings)
{
    FUN_00ac67c0(strings);
    strings->Add(FUN_00847b50(DAT_0116eed8));
}
}   // namespace f3m_00ad27f0

// @f3 0x00ade560 (community match, verified in this file)
__declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* dest, long exchange, long comparand);

class RecursiveSpinLock
{
public:
    void FUN_00409a80(bool wait);
    volatile long owner;
    long count;
};

// pdb: NiTPointerAllocator<unsigned int>::Deallocate | TES.obj | fnv360_0822_retail, call_seq, low
// pdb params: pkDel
void __stdcall FUN_00ade560(void* pointer)
{
    PoolAllocatorBase<unsigned int>::LinkedListEntry* entry = (PoolAllocatorBase<unsigned int>::LinkedListEntry*)pointer;
    entry->m_element = 0;
    PoolAllocatorBase<unsigned int>::ms_kPoolState.FUN_00409a80(false);
    entry->m_pUserData = 0;
    entry->m_pkNext = PoolAllocatorBase<unsigned int>::ms_pFreeList;
    --PoolAllocatorBase<unsigned int>::ms_kPoolState.count;
    PoolAllocatorBase<unsigned int>::ms_pFreeList = entry;
    if (PoolAllocatorBase<unsigned int>::ms_kPoolState.count == 0) {
        long owner = PoolAllocatorBase<unsigned int>::ms_kPoolState.owner;
        InterlockedCompareExchange(&PoolAllocatorBase<unsigned int>::ms_kPoolState.owner, 0, owner);
    }
}

// @f3 0x00ac0a10 (community match, verified in this file)
extern unsigned int DAT_01202530;
namespace f3m_00ac0a10 {
struct NiStreamLocal
{
    char m_unk00[8];
    unsigned short m_usCapacity; // 0x08
    unsigned short m_usSize;     // 0x0a
    unsigned short m_usUnk0c;    // 0x0c
    unsigned short m_usGrowBy;   // 0x0e
    void FUN_00555790(unsigned int auiCount);
    void FUN_005b3880(int aiIndex, unsigned int* apuiValue);
};

struct NiPSysModifierLocal
{
    virtual void SaveBinary(NiStreamLocal& arStream);
};

struct ModifierSubLocal : NiPSysModifierLocal
{
    void FUN_00ac0a10(NiStreamLocal* apStream);
};

unsigned int __cdecl FUN_00847b50(unsigned int auiValue);

// pdb: NiPSysMeshUpdateModifier::GetViewerStrings | NiPSysMeshUpdateModifier.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void ModifierSubLocal::FUN_00ac0a10(NiStreamLocal* apStream)
{
    NiPSysModifierLocal::SaveBinary(*apStream);
    unsigned int uiValue = FUN_00847b50(DAT_01202530);
    unsigned int uiIndex = apStream->m_usSize;
    if (uiIndex >= apStream->m_usCapacity)
        apStream->FUN_00555790(uiIndex + apStream->m_usGrowBy);
    apStream->FUN_005b3880(uiIndex, &uiValue);
}
}   // namespace f3m_00ac0a10

// @f3 0x00ac18d0 (community match, verified in this file)
extern unsigned int g_012685a4;
namespace f3m_00ac18d0 {
struct NiStreamLocal
{
    char m_unk00[8];
    unsigned short m_usCapacity; // 0x08
    unsigned short m_usSize;     // 0x0a
    unsigned short m_usUnk0c;    // 0x0c
    unsigned short m_usGrowBy;   // 0x0e
    void FUN_00555790(unsigned int auiCount);
    void FUN_005b3880(int aiIndex, unsigned int* apuiValue);
};

struct FUN_00c1b850_clsLocal
{
    virtual void WriteParticleSystemInfo(void* apInfo);
};

struct ModifierSubLocal : FUN_00c1b850_clsLocal
{
    void FUN_00ac18d0(NiStreamLocal* apStream);
};

unsigned int __cdecl FUN_00847b50(unsigned int auiValue);

// pdb: NiMeshParticleSystem::GetViewerStrings | NiMeshParticleSystem.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void ModifierSubLocal::FUN_00ac18d0(NiStreamLocal* apStream)
{
    FUN_00c1b850_clsLocal::WriteParticleSystemInfo(apStream);
    unsigned int uiValue = FUN_00847b50(g_012685a4);
    unsigned int uiIndex = apStream->m_usSize;
    if (uiIndex >= apStream->m_usCapacity)
        apStream->FUN_00555790(uiIndex + apStream->m_usGrowBy);
    apStream->FUN_005b3880(uiIndex, &uiValue);
}
}   // namespace f3m_00ac18d0

// @f3 0x00ac51c0 (community match, verified in this file)
extern int g_unk0126afb8;
namespace f3m_00ac51c0 {
struct NiStreamLocal
{
    char m_unk00[8];
    unsigned short m_usCapacity; // 0x08
    unsigned short m_usSize;     // 0x0a
    unsigned short m_usUnk0c;    // 0x0c
    unsigned short m_usGrowBy;   // 0x0e
    void FUN_00555790(unsigned int auiCount);
    void FUN_005b3880(int aiIndex, unsigned int* apuiValue);
};

struct FUN_00c1b850_clsLocal
{
    virtual void WriteParticleSystemInfo(void* apInfo);
};

struct ModifierSubLocal : FUN_00c1b850_clsLocal
{
    void FUN_00ac51c0(NiStreamLocal* apStream);
};

unsigned int __cdecl FUN_00847b50(unsigned int auiValue);

// pdb: BSStripParticleSystem::GetViewerStrings | BSStripParticleSystem.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pkStrings
void ModifierSubLocal::FUN_00ac51c0(NiStreamLocal* apStream)
{
    FUN_00c1b850_clsLocal::WriteParticleSystemInfo(apStream);
    unsigned int uiValue = FUN_00847b50(g_unk0126afb8);
    unsigned int uiIndex = apStream->m_usSize;
    if (uiIndex >= apStream->m_usCapacity)
        apStream->FUN_00555790(uiIndex + apStream->m_usGrowBy);
    apStream->FUN_005b3880(uiIndex, &uiValue);
}
}   // namespace f3m_00ac51c0

// @f3 0x00aca270 (community match, verified in this file)
extern const char* DAT_0116edc8;
namespace f3m_00aca270 {
namespace ns_aca270 {

char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class NiPSysModifierViewer
{
public:
    void FUN_00ad25c0(ViewerStrings* strings);
    void FUN_00aca270(ViewerStrings* strings);
};

// pdb: NiPSysModifierActiveCtlr::GetViewerStrings | NiPSysModifierActiveCtlr.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void NiPSysModifierViewer::FUN_00aca270(ViewerStrings* strings)
{
    FUN_00ad25c0(strings);
    strings->Add(FUN_00847b50(DAT_0116edc8));
}

}
}   // namespace f3m_00aca270

// @f3 0x00acb440 (community match, verified in this file)
extern const char* DAT_0116ee00;
extern const char DAT_00de039c[];
namespace f3m_00acb440 {
namespace ns_acb440 {

char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class ViewerVector
{
public:
    char* FUN_00823dc0(const char* label);
    float x, y, z;
};

class NiPSysFieldViewer
{
public:
    void FUN_00ad1b10(ViewerStrings* strings);
    void FUN_00acb440(ViewerStrings* strings);

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    ViewerVector direction;
};

// pdb: NiPSysGravityFieldModifier::GetViewerStrings | NiPSysGravityFieldModifier.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: pkStrings
void NiPSysFieldViewer::FUN_00acb440(ViewerStrings* strings)
{
    FUN_00ad1b10(strings);
    strings->Add(FUN_00847b50(DAT_0116ee00));
    strings->Add(direction.FUN_00823dc0(DAT_00de039c));
}

}
}   // namespace f3m_00acb440

// @f3 0x00ad25c0 (community match, verified in this file)
extern const char* DAT_0116eed0;
namespace f3m_00ad25c0 {
namespace ns_ad25c0 {

char* __cdecl FUN_00847b50(const char* label);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class BaseViewer
{
public:
    void FUN_00ac67c0(ViewerStrings* strings);
    void FUN_00ad25c0(ViewerStrings* strings);
};

// pdb: NiPSysModifierBoolCtlr::GetViewerStrings | NiPSysModifierBoolCtlr.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void BaseViewer::FUN_00ad25c0(ViewerStrings* strings)
{
    FUN_00ac67c0(strings);
    strings->Add(FUN_00847b50(DAT_0116eed0));
}

}
}   // namespace f3m_00ad25c0

// @f3 0x00ad24e0 (community match, verified in this file)
struct GlobalObjectO2_00a7b610 { };
extern GlobalObjectO2_00a7b610 g_012007a0;

struct NodeAD24 { int unk00; NodeAD24* next; };

class PObjAD24
{
public:
    virtual void slot00();
    virtual void slot04();
    virtual NodeAD24* slot08();
    __forceinline bool IsKindOfType(const void* rtti)
    {
        NodeAD24* r = slot08();
        while (r)
        {
            if ((const void*)r == rtti)
                return true;
            r = r->next;
        }
        return false;
    }
    void FUN_008cd050(bool v);
};

class OwnerAD24
{
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0(bool* out);
    void FUN_00ad24e0(PObjAD24* pkInterp, unsigned short usIndex);
};

// pdb: NiPSysModifierBoolCtlr::SynchronizePoseInterpolator | NiPSysModifierBoolCtlr.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkInterp, usIndex
void OwnerAD24::FUN_00ad24e0(PObjAD24* pkInterp, unsigned short usIndex)
{
    bool bValue;
    PObjAD24* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = pkInterp->IsKindOfType((const void*)&g_012007a0) ? pkInterp : 0;
    this->slotF0(&bValue);
    pkBoolInterp->FUN_008cd050(bValue);
}

// @f3 0x00ade640 (community match, verified in this file)
namespace f3m_00ade640 {
void FUN_00e9497c();
void __cdecl FUN_0089e890(unsigned int value);

struct FUN_00ade640_Node
{
    FUN_00ade640_Node* next;
    unsigned int value;
};

struct FUN_00ade640_Obj
{
    void* vtable;
    unsigned int count;
    FUN_00ade640_Node** entries;
    void* unk0C;
    unsigned char unk10;

    void FUN_00ade5d0();
    void FUN_00ade640();
};

struct FUN_00ade640_Guard
{
    FUN_00ade640_Obj* obj;
    FUN_00ade640_Guard(FUN_00ade640_Obj* o) : obj(o) { o->vtable = (void*)&FUN_00e9497c; }
    ~FUN_00ade640_Guard() { obj->FUN_00ade5d0(); }
};

void FUN_00ade640_Obj::FUN_00ade640()
{
    FUN_00ade640_Guard guard(this);

    if (unk10 != 0)
    {
        for (unsigned int index = 0; index < count; ++index)
        {
            FUN_00ade640_Node* node = entries[index];
            while (node)
            {
                FUN_00ade640_Node* current = node;
                node = node->next;
                FUN_0089e890(current->value);
            }
        }
    }
}
}   // namespace f3m_00ade640

// @f3 0x00ad2700 (community match, verified in this file)
namespace f3m_00ad2700 {
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pkBaseRTTI;
};
extern const NiRTTI DAT_01091f90;

struct NiObject
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOf(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* p = GetRTTI();
        while (p)
        {
            if (p == pkRTTI)
                return true;
            p = p->m_pkBaseRTTI;
        }
        return false;
    }
};

inline NiObject* DynamicCast(const NiRTTI* rtti, NiObject* o)
{
    return o ? (o->IsKindOf(rtti) ? o : 0) : 0;
}
inline NiObject* DynamicCast2(const NiRTTI* rtti, NiObject* o)
{
    if (o)
    {
        bool kind = o->IsKindOf(rtti);
        return kind ? o : 0;
    }
    return o;
}
struct Target : NiObject
{
    void FUN_008b6690(float value);
};
}

struct f3m_00ad2700_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void GetValue(float& value);
    void FUN_00ad2700(f3m_00ad2700::NiObject* obj, int unused);
};

// pdb: NiPSysModifierFloatCtlr::SynchronizePoseInterpolator | NiPSysModifierFloatCtlr.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pkInterp, usIndex
void f3m_00ad2700_Obj::FUN_00ad2700(f3m_00ad2700::NiObject* obj, int unused)
{
    if (obj)
    {
        bool kind = obj->IsKindOf(&f3m_00ad2700::DAT_01091f90);
        obj = kind ? obj : 0;
    }
    f3m_00ad2700::Target* target = (f3m_00ad2700::Target*)obj;
    float value;
    GetValue(value);
    target->FUN_008b6690(value);
}

// @f3 0x00ac9190 (community match, verified in this file)
extern const char* DAT_0116edb0;
namespace f3m_00ac9190 {


char* __cdecl FUN_00847b50(const char* label);

struct ViewerStrings
{
    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
};

void __stdcall FUN_00ac60d0(ViewerStrings* strings);

// pdb: NiPSysPositionModifier::GetViewerStrings | NiPSysPositionModifier.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: NiPSysPositionModifier::CreateObject)
// pdb params: pkStrings
void __stdcall FUN_00ac9190(ViewerStrings* strings)
{
    FUN_00ac60d0(strings);
    char* value = FUN_00847b50(DAT_0116edb0);
    unsigned int index = strings->firstFree;
    unsigned int capacity = strings->capacity;
    if (index >= capacity)
    {
        unsigned int growBy = strings->growBy;
        strings->FUN_00555790(index + growBy);
    }
    strings->FUN_005b3880(index, value);
}
}   // namespace f3m_00ac9190

// @f3 0x00aca370 (community match, verified in this file)
extern const char* DAT_0116edd0;
namespace f3m_00aca370 {

extern char* __cdecl FUN_00847b50(const char* label);
extern void __stdcall FUN_00ad27f0(void* strings);

struct ViewerStrings
{
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

void __stdcall FUN_00aca370(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116edd0));
}
}   // namespace f3m_00aca370

// @f3 0x00acb580 (community match, verified in this file)
extern const char* DAT_0116ee08;
namespace f3m_00acb580 {
char* __cdecl FUN_00847b50(const char* label);

struct ViewerStrings {
    void** table;
    char** buffer;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short count;
    unsigned short growBy;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
    void Add(char* value) {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
};

struct ParticleModifier {
    void FUN_00ad27f0(ViewerStrings* strings);
    void FUN_00acb580(ViewerStrings* strings);
};

void ParticleModifier::FUN_00acb580(ViewerStrings* strings) {
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116ee08));
}
}   // namespace f3m_00acb580

// @f3 0x00acb7a0 (community match, verified in this file)
extern const char* DAT_0116ee18;
namespace f3m_00acb7a0 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ad27f0(void* strings);

struct ViewerStrings
{
    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
};

// pdb: NiPSysFieldAttenuationCtlr::GetViewerStrings | NiPSysFieldAttenuationCtlr.obj | fnv360_0721_retail, objrun_open, low
// pdb params: pkStrings
void __stdcall FUN_00acb7a0(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    char* label = FUN_00847b50(DAT_0116ee18);
    unsigned int index = strings->firstFree;
    if (index >= strings->capacity)
        strings->FUN_00555790(index + strings->growBy);
    strings->FUN_005b3880(index, label);
}
}   // namespace f3m_00acb7a0

// @f3 0x00acb970 (community match, verified in this file)
extern const char* DAT_0116ee28;
namespace f3m_00acb970 {
class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

extern "C" char* __cdecl FUN_00847b50(const char* label);
extern "C" void __stdcall FUN_00ad27f0(void* p);

void __stdcall FUN_00acb970(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    char* label = FUN_00847b50(DAT_0116ee28);

    unsigned int index = strings->firstFree;
    if (index >= strings->capacity)
        strings->FUN_00555790(index + strings->growBy);
    strings->FUN_005b3880(index, label);
}
}   // namespace f3m_00acb970

// @f3 0x00acbac0 (community match, verified in this file)
extern const char* DAT_0116ee30;
namespace f3m_00acbac0 {
void __stdcall FUN_00ad27f0(f3m_00ac21e0::ViewerStrings* strings);
char* __cdecl FUN_00847b50(const char* label);

void __stdcall FUN_00acbac0(f3m_00ac21e0::ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116ee30));
}
}   // namespace f3m_00acbac0

// @f3 0x00acbbc0 (community match, verified in this file)
extern const char* DAT_0116ee38;
namespace f3m_00acbbc0 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ad27f0(void* strings);

void __stdcall FUN_00acbbc0(f3m_00ac21e0::ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    char* value = FUN_00847b50(DAT_0116ee38);
    unsigned int index = strings->firstFree;
    unsigned int capacity = strings->capacity;
    if (index >= capacity) {
        unsigned int growBy = strings->growBy;
        strings->FUN_00555790(index + growBy);
    }
    strings->FUN_005b3880(index, value);
}
}   // namespace f3m_00acbbc0

// @f3 0x00acbce0 (community match, verified in this file)
extern const char* DAT_0116ee40;
namespace f3m_00acbce0 {
char* __cdecl FUN_00847b50(const char* label);

struct ViewerStrings {
    void** table;
    char** buffer;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short count;
    unsigned short growBy;
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);
    void Add(char* value) {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }
};

struct ParticleModifier {
    void FUN_00ad27f0(ViewerStrings* strings);
    void FUN_00acbce0(ViewerStrings* strings);
};

void ParticleModifier::FUN_00acbce0(ViewerStrings* strings) {
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116ee40));
}
}   // namespace f3m_00acbce0

// @f3 0x00acbdc0 (community match, verified in this file)
extern const char* DAT_0116ee48;
namespace f3m_00acbdc0 {
extern void __stdcall FUN_00ad27f0(void* strings);

extern char* __cdecl FUN_00847b50(const char* label);


class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

void __stdcall FUN_00acbdc0(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    char* value = FUN_00847b50(DAT_0116ee48);

    unsigned int index = strings->firstFree;
    if (index >= strings->capacity)
        strings->FUN_00555790(index + strings->growBy);
    strings->FUN_005b3880(index, value);
}
}   // namespace f3m_00acbdc0

// @f3 0x00acf900 (community match, verified in this file)
extern const char* DAT_0116ee98;
namespace f3m_00acf900 {
char* __cdecl FUN_00847b50(const char* label);
void __stdcall FUN_00ad27f0(f3m_00ac21e0::ViewerStrings* strings);

void __stdcall FUN_00acf900(f3m_00ac21e0::ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    char* value = FUN_00847b50(DAT_0116ee98);
    unsigned int index = strings->firstFree;
    unsigned int capacity = strings->capacity;
    if (index >= capacity) {
        unsigned int growBy = strings->growBy;
        strings->FUN_00555790(index + growBy);
    }
    strings->FUN_005b3880(index, value);
}
}   // namespace f3m_00acf900

// @f3 0x00acb660 (community match, verified in this file)
extern const char* DAT_0116ee10;
namespace f3m_00acb660 {

extern char* __cdecl FUN_00847b50(const char* label);
extern void __stdcall FUN_00ad27f0(void* strings);

struct ViewerStrings
{
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

void __stdcall FUN_00acb660(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116ee10));
}
}   // namespace f3m_00acb660

// @f3 0x00acb880 (community match, verified in this file)
extern const char* DAT_0116ee20;
namespace f3m_00acb880 {
class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(index + growBy);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

extern char* __cdecl FUN_00847b50(const char* label);
extern void __stdcall FUN_00ad27f0(ViewerStrings* strings);


void __stdcall FUN_00acb880(ViewerStrings* strings)
{
    FUN_00ad27f0(strings);
    strings->Add(FUN_00847b50(DAT_0116ee20));
}
}   // namespace f3m_00acb880

// @f3 0x00ac77a0 (community match, verified in this file)
namespace f3m_00ac21e0 {

extern void* __stdcall FUN_00838420(ViewerStrings* strings);
extern const char* DAT_0116ec38;
extern const char* DAT_0116ed88;

// pdb: NiPSysUpdateCtlr::GetViewerStrings | NiPSysUpdateCtlr.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: pkStrings
void __stdcall FUN_00ac77a0(ViewerStrings* strings)
{
    FUN_00838420(strings);
    strings->Add(FUN_00847b50(DAT_0116ed88));
}

}

// @f3 0x00ad0e30 (community match, verified in this file)
namespace f3m_00ad0e30 {
struct FUN_00ac46e0 {
 virtual ~FUN_00ac46e0();
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 FUN_00ac46e0();
};
struct InnerBaseAd0e30 {
 unsigned value;
 unsigned short a,b,c,d;
 InnerBaseAd0e30() { a=0; b=0; c=0; value=0; d=1; }
};
struct InnerAd0e30 : InnerBaseAd0e30 {
 virtual ~InnerAd0e30();
 InnerAd0e30() {}
};
struct FUN_00ad0e30 : FUN_00ac46e0 {
 volatile unsigned unk7c;
 unsigned unk80,unk84;
 InnerAd0e30 inner;
 virtual ~FUN_00ad0e30();
 FUN_00ad0e30();
};
// pdb: NiMeshPSysData::NiMeshPSysData | NiMeshPSysData.obj | tesv_win, uvref, medium
FUN_00ad0e30::FUN_00ad0e30() : unk7c(0) {}
}   // namespace f3m_00ad0e30

// @f3 0x00ada500 (community match, verified in this file)
extern int* volatile DAT_0116ef60;
extern volatile unsigned int DAT_0116ef58;
namespace f3m_00ada500 {
// pdb: BSShaderManager::GetNextAvailableShadowMapAccumulator | BSShaderManager.obj | fnv360_0822_retail, udata + bridge(call_seq|call_gap_sim), high
unsigned int __cdecl BSShaderManager_GetNextAvailableShadowMapAccumulator() {
 unsigned int i=DAT_0116ef58;
 int* e=DAT_0116ef60+i;
 DAT_0116ef58=i+1;
 return *e;
}
}   // namespace f3m_00ada500

// @f3 0x00ac91f0 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e8da28;
extern float DAT_00e8da20;
extern "C" const double DAT_00db38b0;
extern "C" unsigned int DAT_0116edbc;
extern "C" float DAT_0116edb8;
namespace f3m_00ac91f0 {
namespace Planar2296 {
struct NiPoint3 {float x,y,z; NiPoint3 operator*(float s) const {NiPoint3 result;result.x=x*s;result.y=y*s;result.z=z*s;return result;} float Dot(const NiPoint3& p) const {return x*p.x+y*p.y+z*p.z;} };
struct NiPlane {NiPoint3 m_kPlaneNormal;float m_fPlaneConstant;};
struct VelocityState
{
    NiPoint3 velocity;
    unsigned int unk0c, unk10, unk14, unk18;
};
struct PlaneVector;
struct BoundDataBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    PlaneVector* positions;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    VelocityState* velocities;
};
extern "C" double __cdecl fabs(double);
extern "C" double __cdecl pow(double, double);
inline float absf(float x)
{
    return (float)fabs(x);
}
struct PlaneVector
{
    union {struct {float x,y,z;};float components[3];};
    operator NiPoint3() const {return *reinterpret_cast<const NiPoint3*>(this);}

    PlaneVector()
    {}
    PlaneVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    PlaneVector(const NiPoint3& p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    float Dot(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float operator*(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    PlaneVector operator*(float s) const
    {
        return PlaneVector(x * s, y * s, z * s);
    }
    PlaneVector operator+(const PlaneVector& p) const
    {
        return PlaneVector(x + p.x, y + p.y, z + p.z);
    }
    PlaneVector operator-(const PlaneVector& p) const
    {
        return PlaneVector(x - p.x, y - p.y, z - p.z);
    }
    PlaneVector& operator+=(const PlaneVector& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    PlaneVector& operator-=(const PlaneVector& p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
};
inline PlaneVector operator*(float s, const PlaneVector& p)
{
    return p * s;
}

inline PlaneVector ScaleVectorD(const PlaneVector& v, float s)
{
    PlaneVector r;
    const float* a = v.components+2;
    float* b = r.components+2;
    for (int i = -2; i < 1; ++i)
        b[i] = s * a[i];
    return r;
}
inline float SpecialLength(const PlaneVector& p)
{
    double b = p.y;
    double a = p.x;
    double c = p.z;
    double d = a * a;
    d += b * b;
    d += c * c;
    return d;
}
struct CollisionPlane : NiPlane
{
    float Distance(const NiPoint3& p) const
    {
        float d = reinterpret_cast<const PlaneVector&>(m_kPlaneNormal) * reinterpret_cast<const PlaneVector&>(p);
        return d - m_fPlaneConstant;
    }
};
struct RotationHelper
{
    float m00,m01,m02,m10,m11,m12,m20,m21,m22;
    PlaneVector FUN_004752c0(const NiPoint3& direction) const;
};
struct NiPSysCollider {int unk00,unk04,unk08,unk0c,unk10;NiPoint3 m_kCollisionPosition;float m_fSpawnRate;int unk24,unk28;};
struct NiPSysPlanarCollider:NiPSysCollider {int unk2c,unk30,unk34;NiPoint3 m_kFirstVector,m_kSecondPlaneVector;float m_fWidthSquared,m_fHeightSquared;NiPlane m_kHalfSpacePlane;NiPoint3 m_kPathOffset;RotationHelper rotation;};
struct PlanarColliderExt : NiPSysPlanarCollider
{
    NiPSysCollider* NiPSysPlanarCollider_Resolve(float time, float* collisionTime, BoundDataBlock* data, unsigned short particleId);
    NiPSysCollider* FUN_00ad1cb0(float time, float* collisionTime, BoundDataBlock* data, unsigned short particleId);
};


// pdb: NiPSysPlanarCollider::Resolve | NiPSysPlanarCollider.obj | fnv360_0822_retail, uconst + bridge(vtable|uconst) + skyrim(uconst), high
NiPSysCollider* PlanarColliderExt::NiPSysPlanarCollider_Resolve(float time, float* collisionTime, BoundDataBlock* data,
                                                unsigned short particleId)
{
    bool bCollided = false;
    const PlaneVector& particle = data->positions[particleId];
    const PlaneVector& velocity = reinterpret_cast<const PlaneVector&>(data->velocities[particleId].velocity);
    const PlaneVector& normal = reinterpret_cast<const PlaneVector&>(m_kHalfSpacePlane.m_kPlaneNormal);
    double planeSum = normal.y * particle.y;
    const float* planeN = normal.components + 1;
    const float* planeP = particle.components + 1;
    for (int i = 2; i < 3; ++i)
        planeSum += planeN[i - 3] * planeP[i - 3];
    const float* nz = normal.components + 1;
    const float* pz = particle.components + 2;
    for (int j = 0; 1 > j; ++j)
        planeSum += nz[j + 1] * pz[j];
    float distance = (float)planeSum;
    distance -= m_kHalfSpacePlane.m_fPlaneConstant;
    if (DAT_00e8da20 > distance && DAT_00e8da20 > -distance)
    {
        PlaneVector relative = particle - reinterpret_cast<const PlaneVector&>(m_kPathOffset);
        PlaneVector xAxis=rotation.FUN_004752c0(m_kFirstVector);
        PlaneVector yAxis=rotation.FUN_004752c0(m_kSecondPlaneVector);
        NiPoint3 kAlongX = (NiPoint3)xAxis * (double)(relative * xAxis);
        NiPoint3 kAlongY = (NiPoint3)yAxis * (double)(yAxis * relative);
        if (kAlongX.Dot(kAlongX) < m_fWidthSquared && kAlongY.Dot(kAlongY) < m_fHeightSquared)
        {
            *collisionTime = time;
            m_fSpawnRate = time;
            reinterpret_cast<PlaneVector&>(m_kCollisionPosition) = particle;
            return this;
        }
    }
    else
    {
        float duration;
        duration = *collisionTime - time;
        PlaneVector delta;
        delta.x = duration * velocity.x;
        delta.y = duration * velocity.y;
        delta.z = duration * velocity.z;
        double projectedSum = delta.y * planeN[0];
        const float* nn1 = normal.components;
        const float* dd1 = delta.components;
        for (int l1 = 2; l1 < 3; ++l1)
            projectedSum += nn1[l1 - 2] * dd1[l1 - 2];
        const float* nn2 = normal.components+2;
        const float* dd2 = delta.components+2;
        for (int l2 = 2; l2 < 3; ++l2)
            projectedSum += nn2[l2 - 2] * dd2[l2 - 2];
        float projected = (float)projectedSum;
        float terminalDistance = projected + distance;
        if (absf(terminalDistance) < DAT_00e8da20)
            terminalDistance = 0.0f;
        if (terminalDistance * distance < 0.0)
        {
            float fraction = (-distance * duration) / projected;
            PlaneVector hit = particle + fraction * velocity;
            if (!(DAT_0116edbc & 1u))
            {
                DAT_0116edbc |= 1u;
                double fTolInit = (float)pow(2.0, DAT_00e8da28);
                DAT_0116edb8 = fTolInit;
            }
            float adjustedDistance;
            adjustedDistance = reinterpret_cast<const CollisionPlane&>(m_kHalfSpacePlane).Distance(hit);
            if (adjustedDistance * distance < 0.0)
            {
                double absX = absf(hit.x);
                float maxCoord = absX;
                float fAbsY = absf(hit.y);
                if (fAbsY > maxCoord)
                    maxCoord = fAbsY;
                float fAbsZ;
                fAbsZ = absf(hit.z);
                maxCoord = (fAbsZ > maxCoord) ? fAbsZ : maxCoord;
                if (distance < 0.0f)
                {
                    hit -= ScaleVectorD(normal, maxCoord * DAT_0116edb8);
                }
                else
                {
                    hit += ScaleVectorD(normal, maxCoord * DAT_0116edb8);
                }
            }
            PlaneVector relative = hit - reinterpret_cast<const PlaneVector&>(m_kPathOffset);
            PlaneVector xAxis=rotation.FUN_004752c0(m_kFirstVector);
            PlaneVector yAxis=rotation.FUN_004752c0(m_kSecondPlaneVector);
            PlaneVector kAlongX = (relative * xAxis) * xAxis;
            PlaneVector kAlongY = (yAxis * relative) * yAxis;
            if (SpecialLength(kAlongX) < m_fWidthSquared && SpecialLength(kAlongY) < m_fHeightSquared)
            {
                *collisionTime = fraction + time;
                reinterpret_cast<PlaneVector&>(m_kCollisionPosition) = hit;
                bCollided = true;
                m_fSpawnRate = fraction + time;
            }
        }
    }
    NiPSysCollider* result;
    result = FUN_00ad1cb0(time, collisionTime, data, particleId);
    return result ? result : (bCollided ? this : 0);
}

}





}   // namespace f3m_00ac91f0
