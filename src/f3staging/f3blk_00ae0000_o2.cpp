#include <windows.h>
// src/f3staging/f3blk_00ae0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00af6d90 (community match, verified in this file)
extern const char DAT_00db3438[];
extern const char DAT_00dbcfe4[];
extern const char DAT_00dc0cc8[];
extern const char DAT_00dc0cdc[];
extern const char DAT_00dcad64[];
extern const char DAT_00dd7f00[];
extern const char DAT_00dfa7c4[];
extern const char DAT_00dfa7dc[];
extern const char DAT_00dfa7e8[];
extern const char DAT_00dfa7f4[];
extern const char DAT_00dfa800[];
extern const char DAT_00dfa80c[];
extern const char DAT_00dfa818[];
extern const char DAT_00dfa824[];
extern const char DAT_00e2a504[];
extern const char DAT_00e2f46c[];
extern const char DAT_00e340d4[];
extern const char DAT_00e95494[];
extern const char DAT_00e95504[];
extern const char DAT_00e95554[];
extern const char DAT_00e9555c[];
extern const char DAT_00e95588[];
extern const char DAT_00e95594[];
extern const char DAT_00e955a0[];
extern const char DAT_00e9560c[];
extern const char DAT_00e95634[];
extern const char DAT_00e95644[];
extern const char DAT_00e956a4[];
extern const char DAT_00e956c4[];
extern const char DAT_00e956d0[];
extern const char DAT_00e956d8[];
extern const char DAT_00e956f0[];
extern const char DAT_00e956fc[];
extern const char DAT_00e95748[];
extern const char DAT_00e95750[];
extern const char DAT_00e95778[];
extern const char DAT_00e957dc[];
extern const char DAT_00e95810[];
extern const char DAT_00e95884[];
extern const char DAT_00e95894[];
extern const char DAT_00e958f4[];
extern const char DAT_00e95908[];
extern const char DAT_00e95918[];
extern const char DAT_00e95920[];
extern const char DAT_00e95930[];
extern const char DAT_00e9593c[];
extern const char DAT_00e95944[];
extern const char DAT_00e9594c[];
extern const char DAT_00e95954[];
extern const char DAT_00e95960[];
extern const char DAT_00e95984[];
extern const char DAT_00e9598c[];
extern const char DAT_00e959a8[];
extern const char DAT_00e959b8[];
extern const char DAT_00e959d4[];
extern const char DAT_00e959e0[];
extern const char DAT_00e959ec[];
extern const char DAT_00e959fc[];
extern const char DAT_00e95a08[];
extern const char DAT_00e95a24[];
extern const char DAT_00e95a30[];
extern const char DAT_00e95a40[];
extern const char DAT_00e95a60[];
extern const char DAT_00e95a64[];
extern const char DAT_00e95a84[];
extern const char DAT_00e95aa4[];
extern const char DAT_00e95ac8[];
extern const char DAT_00e95aec[];
extern const char DAT_00e95b10[];
extern const char DAT_00e95b1c[];
extern const char DAT_00e95b3c[];
extern const char DAT_00e95b60[];
extern const char DAT_00e95b7c[];
extern const char DAT_00e95b84[];
extern const char DAT_00e95ba0[];
extern const char DAT_00e95bc0[];
extern const char DAT_00e95be0[];
extern const char DAT_00e95bf8[];
extern const char DAT_00e95c14[];
extern const char DAT_00e95c24[];
extern const char DAT_00e95c44[];
extern const char DAT_00e95c60[];
extern const char DAT_00e95c6c[];
extern const char DAT_00e95c88[];
extern const char DAT_00e95c90[];
extern const char DAT_00e95c9c[];
extern const char DAT_00e95ca4[];
extern const char DAT_00e95cbc[];
extern const char DAT_00e95ce0[];
extern const char DAT_00e95d00[];
extern const char DAT_00e95d1c[];
extern const char DAT_00e95d44[];
extern const char DAT_00e95d4c[];
extern const char DAT_00e95d74[];
extern const char DAT_00e95d98[];
extern const char DAT_00e95db8[];
extern const char DAT_00e95dc4[];
extern const char DAT_00e95de4[];
extern const char DAT_00e95e04[];
extern "C" char* __cdecl _gcvt(double, int, char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern float DAT_01067f04;
extern float DAT_01067f08;
extern int DAT_0116efb0;
extern int DAT_0116efac;
extern int DAT_0116efa0;
struct MacroPair { const char* name; const char* value; };
struct ShaderDefinition { const char* file; MacroPair macros[9]; };
class ShaderObject {
public:
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
    void IncRefCount() { InterlockedIncrement(&references); }
    void DecRefCount() { if (!InterlockedDecrement(&references)) Destroy(); }
};
extern NiPointer<ShaderObject> DAT_011737c8[48];
extern NiPointer<ShaderObject> DAT_01173888[160];
void __cdecl FUN_00b62b90(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
class ShaderBuilder {
public:
    ShaderObject* FUN_00b636d0(const char*, const MacroPair*, const char*, const char*);
    void FUN_00af6d90();
};
// pdb: ShadowLightShader::LoadPixelShaders | ShadowLightShader.obj | fnv360_0822_retail, ustr, medium
void ShaderBuilder::FUN_00af6d90() {
    char specularText[350];
    char emissiveText[350];
    _gcvt(DAT_01067f04, 12, specularText);
    _gcvt(DAT_01067f08, 12, emissiveText);
    ShaderDefinition baseline[48] = {
        {DAT_00e95e04, 0},
        {DAT_00e95de4, 0},
        {DAT_00e95dc4, 0},
        {DAT_00e95e04, DAT_00e957dc, DAT_00db3438, 0},
        {DAT_00e95e04, DAT_00e957dc, DAT_00db3438, DAT_00e95894, DAT_00db3438, 0},
        {DAT_00e95e04, DAT_00e957dc, DAT_00db3438, DAT_00e95884, DAT_00db3438, 0},
        {DAT_00e95e04, DAT_00e957dc, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95d98, DAT_00e95db8, specularText, 0},
        {DAT_00e95d74, DAT_00e95db8, specularText, 0},
        {DAT_00e95d4c, 0},
        {DAT_00e95d4c, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95d44, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95894, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95894, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95894, DAT_00db3438, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95894, DAT_00db3438, DAT_00e95d44, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95884, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95884, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95884, DAT_00db3438, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95884, DAT_00db3438, DAT_00e95810, DAT_00db3438, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95d44, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95894, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95894, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95894, DAT_00db3438, DAT_00e95d44, DAT_00db3438, 0},
        {DAT_00e95d4c, DAT_00e95778, DAT_00db3438, DAT_00e95894, DAT_00db3438, DAT_00e95d44, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95d1c, 0},
        {DAT_00e95e04, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95e04, DAT_00e95810, DAT_00db3438, DAT_00e957dc, DAT_00db3438, 0},
        {DAT_00e95d00, 0},
        {DAT_00e95d00, DAT_00e95894, DAT_00db3438, 0},
        {DAT_00e95ce0, 0},
        {DAT_00e95cbc, 0},
        {DAT_00e95ca4, DAT_00e95c9c, DAT_00db3438, DAT_00e95c90, emissiveText, 0},
        {DAT_00e95ca4, DAT_00e95c90, emissiveText, 0},
        {DAT_00e95ca4, DAT_00e95c88, 0, 0},
        {DAT_00e95e04, 0},
        {DAT_00e95c6c, 0},
        {DAT_00e95c6c, DAT_00e95750, DAT_00db3438, 0},
        {DAT_00e95c6c, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95c6c, DAT_00e95750, DAT_00db3438, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95c6c, DAT_00e95748, DAT_00db3438, 0},
        {DAT_00e95c6c, DAT_00e95750, DAT_00db3438, DAT_00e95748, DAT_00db3438, 0},
        {0},
        {DAT_00e95e04, DAT_00e95c60, DAT_00db3438, 0},
    };
    ShaderDefinition features[160] = {
        {DAT_00e95c44, 0},
        {DAT_00e95c44, DAT_00e956a4, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956a4, DAT_00db3438, DAT_00dd7f00, DAT_00db3438, 0},
        {DAT_00e95c24, DAT_00e956fc, DAT_00db3438, DAT_00e956f0, DAT_00db3438, DAT_00e95c14, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c24, DAT_00e956fc, DAT_00db3438, DAT_00e956d8, DAT_00db3438, DAT_00e956f0, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00dcad64, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00dbcfe4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956d0, DAT_00dfa818, DAT_00dbcfe4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa818, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, 0},
        {0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa818, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95c44, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {0},
        {DAT_00e95bf8, DAT_00e956d0, DAT_00dfa7c4, 0},
        {DAT_00e95bf8, DAT_00e956d0, DAT_00dfa7c4, DAT_00e95778, 0, 0},
        {DAT_00e95bf8, DAT_00e956d0, DAT_00dfa800, 0},
        {DAT_00e95bf8, DAT_00e956a4, DAT_00db3438, DAT_00e956d0, DAT_00dfa800, 0},
        {DAT_00e95bf8, DAT_00e956d0, DAT_00dfa800, DAT_00e95778, 0, 0},
        {DAT_00e95bf8, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa800, 0},
        {DAT_00e95bf8, DAT_00e956a4, DAT_00db3438, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa800, 0},
        {DAT_00e95bf8, DAT_00e956c4, DAT_00db3438, DAT_00e956d0, DAT_00dfa800, DAT_00e95778, 0, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa818, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa818, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa818, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa80c, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa80c, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa80c, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95be0, DAT_00e956d0, DAT_00dfa80c, DAT_00e95778, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95bc0, DAT_00e956d0, DAT_00dfa818, 0},
        {DAT_00e95bc0, DAT_00e956d0, DAT_00dfa80c, 0},
        {DAT_00e95ba0, 0},
        {DAT_00e95ba0, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e956d8, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95644, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95644, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95634, DAT_00dfa818, DAT_00e95644, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95634, DAT_00dfa818, DAT_00e95644, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95634, DAT_00dfa80c, DAT_00e95644, DAT_00db3438, 0},
        {DAT_00e95ba0, DAT_00e95634, DAT_00dfa80c, DAT_00e95644, DAT_00db3438, DAT_00dbcfe4, DAT_00db3438, 0},
        {DAT_00e95b84, 0},
        {DAT_00e95b84, DAT_00e95b7c, DAT_00db3438, 0},
        {DAT_00e95b84, DAT_00e9560c, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e956d8, DAT_00db3438, DAT_00e95750, DAT_00db3438, 0},
        {DAT_00e95b3c, DAT_00e2f46c, DAT_00db3438, DAT_00e95748, DAT_00db3438, 0},
        {DAT_00e95b3c, DAT_00e956c4, DAT_00db3438, 0},
        {0},
        {DAT_00e95b3c, DAT_00e95750, DAT_00db3438, DAT_00e2f46c, DAT_00db3438, DAT_00e95748, DAT_00db3438, 0},
        {DAT_00e95b3c, DAT_00e95750, DAT_00db3438, DAT_00e956c4, DAT_00db3438, 0},
        {0},
        {DAT_00e95b3c, DAT_00e956c4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95b3c, DAT_00e95750, DAT_00db3438, DAT_00e956c4, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95b1c, DAT_00e955a0, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95b1c, DAT_00e955a0, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, DAT_00e95594, DAT_00db3438, 0},
        {DAT_00e95b1c, DAT_00e955a0, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, DAT_00e340d4, DAT_00db3438, 0},
        {DAT_00e95b1c, DAT_00e955a0, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, DAT_00e340d4, DAT_00db3438, DAT_00e95594, DAT_00db3438, 0},
        {DAT_00e95b1c, DAT_00e955a0, DAT_00db3438, DAT_00e95588, DAT_00db3438, 0},
        {DAT_00e95aec, 0},
        {DAT_00e95aec, DAT_00e9555c, DAT_00db3438, 0},
        {DAT_00e95aec, DAT_00e95554, DAT_00db3438, 0},
        {DAT_00e95ac8, 0},
        {DAT_00e95aa4, 0},
        {DAT_00e95b60, 0},
        {DAT_00e95b60, DAT_00e95750, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e95504, DAT_00db3438, DAT_00e95810, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e95750, DAT_00db3438, DAT_00e95778, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e95748, DAT_00db3438, 0},
        {DAT_00e95b60, DAT_00e95750, DAT_00db3438, DAT_00e95748, DAT_00db3438, 0},
        {DAT_00e95a84, 0},
        {DAT_00e95a84, DAT_00e95554, DAT_00db3438, 0},
        {DAT_00e95a64, DAT_00e95a60, DAT_00db3438, 0},
        {DAT_00e95a40, 0},
        {DAT_00e95a40, DAT_00e95a30, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa824, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa818, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa80c, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa800, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7f4, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7e8, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, 0},
        {DAT_00e95a08, DAT_00e959fc, DAT_00dfa7dc, DAT_00e95810, DAT_00db3438, DAT_00e95a24, DAT_00db3438, DAT_00e959e0, DAT_00db3438, DAT_00e959ec, DAT_00db3438, DAT_00e956d8, DAT_00db3438, 0},
        {DAT_00e959b8, DAT_00e95810, DAT_00db3438, DAT_00e959d4, DAT_00db3438},
        {DAT_00e95c24, DAT_00e956fc, DAT_00db3438, DAT_00e956f0, DAT_00db3438, DAT_00e95c14, DAT_00db3438, DAT_00e959d4, DAT_00db3438, 0},
        {DAT_00e95e04, DAT_00e95810, DAT_00db3438, DAT_00e959a8, DAT_00db3438, 0},
        {DAT_00e9598c, DAT_00e956d0, DAT_00dc0cc8, DAT_00e959d4, DAT_00db3438, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa824, DAT_00e95944, DAT_00dfa824, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa824, DAT_00e95944, DAT_00dfa824, DAT_00e95594, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa800, DAT_00e95944, DAT_00dfa824, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa800, DAT_00e95944, DAT_00dfa824, DAT_00e95594, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa800, DAT_00e95944, DAT_00dfa818, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95960, DAT_00e95494, DAT_00db3438, DAT_00e95954, DAT_00e9594c, DAT_00e95984, DAT_00dfa800, DAT_00e95944, DAT_00dfa818, DAT_00e95594, DAT_00db3438, DAT_00e95b10, DAT_00dfa80c, 0},
        {DAT_00e95a40, DAT_00e9593c, DAT_00db3438, 0},
        {DAT_00e95a40, DAT_00e95930, DAT_00db3438, 0},
    };
    char name[260];
    char path[260];
    for (int i=0; i<48; ++i) {
        if (baseline[i].file) {
            FUN_00b62b90(baseline[i].file, path);
            FUN_00403230(name,260,"SLS1%03i.pso",i);
            DAT_011737c8[i] = FUN_00b636d0(path,baseline[i].macros,"ps_2_0",name);
        }
    }
    int quality=DAT_0116efb0;
    if (quality>=2) {
        char bias[]="-0.6";
        if (DAT_0116efac==6 || DAT_0116efac==4) {
            features[152].macros[1].value=bias;
            features[153].macros[1].value=bias;
            features[154].macros[1].value=bias;
            features[155].macros[1].value=bias;
            features[156].macros[1].value=bias;
            features[157].macros[1].value=bias;
        }
        char lights[4];
        sprintf(lights,"%i",DAT_0116efa0);
        features[152].macros[4].value=lights;
        features[153].macros[5].value=lights;
        features[70].macros[1].value=lights;
        features[71].macros[1].value=lights;
        features[72].macros[1].value=lights;
        features[73].macros[1].value=lights;
        for (int i=0; i<160; ++i) {
            if (!features[i].file) DAT_01173888[i]=0;
            else if (i<=153 || quality>=5) {
                FUN_00b62b90(features[i].file,path);
                FUN_00403230(name,260,"SLS2%03i.pso",i);
                if ((i>=152 && i<=152) || (i>=70 && i<=73))
                    FUN_00403230(name,260,"SLS2%03is%01i.pso",i,DAT_0116efa0);
                DAT_01173888[i]=FUN_00b636d0(path,features[i].macros,"ps_2_0",name);
            }
        }
    }
}

// @f3 0x00ae7ca0 (community match, verified in this file)
struct F3Lock
{
    unsigned int value;
    void FUN_00409a80(char* arg);
};

extern F3Lock DAT_0106e5a0;
extern unsigned int DAT_0106e5a4;
extern FNVPointerListItem* DAT_0106e588;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* dest,
                                                                          long exchange, long comparand);

void FUN_00b0e510();
void FUN_00b0f230(void* pass, unsigned short index, int a, int b, int c);

struct AccumS
{
    int unk00;
    int unk04;
    int unk08;
    FNVPointerListBase m_kList;    // 0x0c
    FNVPointerListBase* pList;     // 0x18
    unsigned int m_uiCount;        // 0x1c
    int unk20;
    FNVPointerListItem** m_ppBase; // 0x24
    int unk28;
    unsigned int m_uiIndex;        // 0x2c
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    int unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0;
    void* pPass;           // 0x1a4
    unsigned short usIndex; // 0x1a8

    void FUN_00ae7ca0();

    void* First()
    {
        m_uiIndex = m_uiCount;
        if (m_uiCount)
            return m_ppBase[--m_uiIndex];
        return 0;
    }
    void* Next()
    {
        if (m_uiIndex)
            return m_ppBase[--m_uiIndex];
        return 0;
    }
};

// pdb: BSShaderAccumulator::RenderAlphaGeometry | BSShaderAccumulator.obj | fnv360_0822_retail, caller_sim, medium
void AccumS::FUN_00ae7ca0()
{
    FUN_00b0e510();
    for (void* p = First(); p; p = Next())
    {
        pPass = p;
        FUN_00b0f230(&pPass, usIndex, 1, 1, 1);
    }
    if (pList)
    {
        while (pList->m_kItemCount.m_uiCount)
        {
            FNVPointerListBase* l = pList;
            FNVPointerListItem* node = l->m_pkHead;
            FNVPointerListItem* next = node->m_pkNext;
            l->m_pkHead = next;
            if (next)
                next->m_pkPrev = 0;
            else
                l->m_pkTail = 0;
            node->m_element = 0;
            DAT_0106e5a0.FUN_00409a80(0);
            node->m_pkPrev = 0;
            node->m_pkNext = DAT_0106e588;
            DAT_0106e588 = node;
            if (--DAT_0106e5a4 == 0)
            {
                long owner = *(long const volatile*)&DAT_0106e5a0.value;
                InterlockedCompareExchange((volatile long*)&DAT_0106e5a0, 0, owner);
            }
            --l->m_kItemCount.m_uiCount;
        }
    }
    else
    {
        while (m_kList.m_kItemCount.m_uiCount)
        {
            FNVPointerListItem* node = m_kList.m_pkHead;
            m_kList.m_pkHead = node->m_pkNext;
            if (m_kList.m_pkHead)
                m_kList.m_pkHead->m_pkPrev = 0;
            else
                m_kList.m_pkTail = 0;
            node->m_element = 0;
            DAT_0106e5a0.FUN_00409a80(0);
            node->m_pkPrev = 0;
            node->m_pkNext = DAT_0106e588;
            DAT_0106e588 = node;
            if (--DAT_0106e5a4 == 0)
            {
                long owner = *(long const volatile*)&DAT_0106e5a0.value;
                InterlockedCompareExchange((volatile long*)&DAT_0106e5a0, 0, owner);
            }
            --m_kList.m_kItemCount.m_uiCount;
        }
    }
    FUN_00b0e510();
}

// @f3 0x00ae4e90 (community match, verified in this file)
typedef long (__stdcall* CompareExchange)(long volatile*, long, long);
extern "C" CompareExchange const FUN_00d9b06c;

namespace SceneContextSwitch {

class RecursiveLock {
public:
    long volatile owner;
    unsigned int depth;

    void FUN_00409a80(const char* source);

    void Release(CompareExchange compareExchange)
    {
        if (--depth == 0) {
            const long previousOwner = owner;
            compareExchange(&owner, 0, previousOwner);
        }
    }
};

extern RecursiveLock DAT_0116fc80;
extern RecursiveLock DAT_0116fca0;

struct SceneFields {
    template <class T>
    T& Field(unsigned int offset)
    {
        return *reinterpret_cast<T*>(reinterpret_cast<unsigned char*>(this) + offset);
    }
};

template <class T>
struct Link {
    Link* next;
    Link* previous;
    T* item;

    static T*& Next(Link*& position)
    {
        T*& item = position->item;
        position = position->next;
        return item;
    }
};

template <class T>
class Array {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void FreeStorage(T** storage);

    T** data;
    unsigned int count;
    unsigned int capacity;

    __forceinline unsigned int Find(T* value, unsigned int size)
    {
        for (unsigned int i = 0; i < size; ++i) {
            if (data && data[i] == value)
                return i;
        }
        return ~0u;
    }

    __forceinline void Clear()
    {
        if (data) {
            FreeStorage(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }

    void __fastcall FUN_005e4fb0(unsigned int count, unsigned int index, bool compact);
};

struct Geometry;
struct Light;
struct Object : SceneFields {
    Array<Geometry>& GeometryLinks() { return Field<Array<Geometry> >(0x210); }
    Array<Light>& LightLinks() { return Field<Array<Light> >(0x220); }
};

struct Geometry : SceneFields {
    Array<Object>& Objects() { return Field<Array<Object> >(0xdc); }
    Link<Light>* Lights() { return Field<Link<Light>*>(0xb4); }
};

struct LightData : SceneFields {
    Array<Object>& Objects() { return Field<Array<Object> >(0xb0); }
};

struct Light : SceneFields {
    LightData* Data() { return Field<LightData*>(0x104); }
};

struct Context : SceneFields {
    Link<Geometry>* Geometries() { return Field<Link<Geometry>*>(0x20); }
};

struct ObjectList {
    void* first;
    void* last;
    unsigned int count;
    void FUN_00abb340();
};

struct Target : SceneFields {
    void FUN_00ae39b0();
    void FUN_00ae4e90(Context* next);
};

// pdb: ShadowSceneNode::SetPortalGraph | ShadowSceneNode.obj | fnv360_0822_retail, call_dedup, low
// pdb params: apBSPortalGraph
void Target::FUN_00ae4e90(Context* next)
{
    Context*& context = Field<Context*>(0x1e0);
    if (next != context) {
        DAT_0116fc80.FUN_00409a80(0);
        DAT_0116fca0.FUN_00409a80(0);
        Field<bool>(0x1fc) = false;
        Field<ObjectList>(0xe4).FUN_00abb340();
        Field<ObjectList>(0xf0).FUN_00abb340();
        Field<ObjectList>(0xfc).FUN_00abb340();
        Field<ObjectList>(0x108).FUN_00abb340();
        Field<ObjectList>(0x114).FUN_00abb340();

        if (context) {
            Link<Geometry>* geometryPosition = context->Geometries();
            while (geometryPosition) {
                Geometry*& geometryItem = Link<Geometry>::Next(geometryPosition);
                Geometry* geometry = geometryItem;
                if (geometry) {
                    unsigned int i = 0;
                    if (i < geometry->Objects().count) {
                        do {
                            Object* object = geometry->Objects().data[i];
                            const unsigned int size = object->GeometryLinks().count;
                            Array<Geometry>& links = object->GeometryLinks();
                            unsigned int index = links.Find(geometry, size);
                            if (index != ~0u)
                                links.FUN_005e4fb0(size, index, true);
                        } while (++i < geometry->Objects().count);
                    }
                    geometry->Objects().Clear();

                    Link<Light>* lightPosition = geometry->Lights();
                    while (lightPosition) {
                        Light*& lightItem = Link<Light>::Next(lightPosition);
                        Light* light = lightItem;
                        if (light) {
                            const int count = static_cast<int>(light->Data()->Objects().count);
                            for (int i = 0; i < count; ++i) {
                                Object* object = light->Data()->Objects().data[i];
                                const unsigned int size = object->LightLinks().count;
                                Array<Light>& links = object->LightLinks();
                                unsigned int index = links.Find(light, size);
                                if (index != ~0u)
                                    links.FUN_005e4fb0(size, index, true);
                            }
                            light->Data()->Objects().Clear();
                        }
                    }
                }
            }
        }

        const CompareExchange compareExchange = FUN_00d9b06c;
        Field<bool>(0x1fc) = true;
        DAT_0116fc80.Release(compareExchange);
        DAT_0116fca0.Release(compareExchange);
        FUN_00ae39b0();
    }
    context = next;
}

}

// @f3 0x00ae1ad0 (community match, verified in this file)
// FO3 task 0003: preserve FNV helper structure and types, adapt FO3 bindings.
class NiPoint3 { public: float x, y, z; };
class NiProperty
{
public:
    void* m_vtable;
    long m_refCount;
    void* unk08;
    void* unk0c;
    void* unk10;
    unsigned short unk14, unk16;
};
struct ShadowLightFlags;
class ShadowSceneLight
{
public:
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
    ShadowLightFlags* lightData;
};
struct ShadowListItem
{
    ShadowListItem* next;
    ShadowListItem* prev;
    ShadowSceneLight* light;
};
struct ShadowList
{
    ShadowListItem* head;
    ShadowListItem* tail;
    unsigned int count;
};
class ShadowSceneNode
{
public:
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
    ShadowList lights;
};

namespace f3_00ae1ad0 {
class FourComponentFloatVector
{
  public:
    NiPoint3 center;
    float radius;
};

extern FourComponentFloatVector DAT_0108edc8;
struct S00b5b260_Geom;
struct S00b5b260_Light : public ShadowSceneLight
{
    bool FUN_00b1fe60(FourComponentFloatVector*, ShadowLightFlags*, float);
    void FUN_00b21960(S00b5b260_Geom*);
};

class BSShaderProperty : public NiProperty
{
  public:
    unsigned short unk18, unk1a;

    unsigned int shaderType;
};

class BSShaderLightingProperty : public BSShaderProperty
{
  public:
    void FUN_00af44e0();

    void FUN_00af4210(S00b5b260_Geom*);
};

struct S00b5b260_Geom
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    FourComponentFloatVector* worldBound;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int flags;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    BSShaderProperty* shader;
};

struct LightOwnerA
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

    S00b5b260_Light** lights;
    unsigned int count;
};

struct LightOwnerB
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

    S00b5b260_Light** lights;
    unsigned int count;
};

struct SceneGraph
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

    ShadowSceneNode* scene;
};

SceneGraph* FUN_00ad5a50();

extern ShadowSceneNode* DAT_0116efb8;

static inline BSShaderProperty* AsShader(BSShaderProperty* p)
{
    return p->shaderType != ~0u ? p : 0;
}
static inline int IsLightingType(BSShaderProperty* p)
{
    unsigned int t = p->shaderType;
    return t >= 1 && t <= 11;
}
static inline BSShaderLightingProperty* AsLighting(BSShaderProperty* p)
{
    return IsLightingType(p) ? static_cast<BSShaderLightingProperty*>(p) : 0;
}
static inline ShadowSceneLight* GetNext(ShadowListItem*& pos)
{
    ShadowSceneLight*& result = pos->light;
    pos = pos->next;
    return result;
}
static inline void S00b5b260_Apply(S00b5b260_Light* light, FourComponentFloatVector* bound, S00b5b260_Geom* geom)
{
    if (light)
    {
        ShadowLightFlags* data = light->lightData;
        if (light->FUN_00b1fe60(bound, data, 1.0f))
            light->FUN_00b21960(geom);
    }
}
// @fnv 0x00b5b260
// pdb: ShadowSceneNode::UpdateQueuedObjectLighting | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apGeom, apSceneNode, abActiveLightsOnly, apRoom, apPortal
bool FUN_00ae1ad0(S00b5b260_Geom* geom, ShadowSceneNode* scene, void* unused, LightOwnerA* ownerA, LightOwnerB* ownerB)
{
    BSShaderProperty* pShader = geom->shader;
    if (pShader)
    {
        BSShaderProperty* shader = AsShader(pShader);
        BSShaderLightingProperty* lighting = 0;
        if (shader)
            lighting = AsLighting(shader);
        if (!lighting)
            return false;
        if (!scene)
        {
            scene = FUN_00ad5a50()->scene;
            if (!scene)
                scene = DAT_0116efb8;
        }
        lighting->FUN_00af44e0();
        FourComponentFloatVector* bound = geom->worldBound;
        if (!bound)
            bound = &DAT_0108edc8;
        FourComponentFloatVector boundCopy = *bound;
        if (ownerA)
        {
            for (unsigned int i = 0; i < ownerA->count; ++i)
            {
                S00b5b260_Apply(ownerA->lights[i], &boundCopy, geom);
            }
        }
        else if (ownerB)
        {
            for (unsigned int i = 0; i < ownerB->count; ++i)
            {
                S00b5b260_Apply(ownerB->lights[i], &boundCopy, geom);
            }
        }
        else
        {
            ShadowListItem* pos = scene->lights.head;
            while (pos)
            {
                S00b5b260_Apply((S00b5b260_Light*)GetNext(pos), &boundCopy, geom);
            }
        }
        lighting->FUN_00af4210(geom);
        geom->flags |= 0x400000;
        return true;
    }
    return true;
}
}  // namespace f3_00ae1ad0

// @f3 0x00ae2ce0 (community match, verified in this file)
extern int DAT_0109054c;
namespace f3m_00ae2ce0 {
// FUN_00ae2ce0: __cdecl bool(Node*, a2..a5). Walks a node: vf3 twice (test, then container), lookup, else
// recurse over the container's element array (vf7 selects FUN_00ae1ad0 or self), AND-ing the results.

struct FloatRec_ae2ce0 {
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

struct Node_ae2ce0 {
    virtual int VSlot0();
    virtual int VSlot1();
    virtual int VSlot2();
    virtual Node_ae2ce0* VSlot3();
    virtual int VSlot4();
    virtual int VSlot5();
    virtual int VSlot6();
    virtual int VSlot7();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FloatRec_ae2ce0* unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned char unk30;
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    Node_ae2ce0** unkA0;
    unsigned short unkA4;
    unsigned short unkA6;
};

void* __cdecl FUN_00424d50(int* a, Node_ae2ce0* b);
void* __fastcall FUN_007fbf10(void* p);
bool __cdecl FUN_00ae1ad0(Node_ae2ce0* n, int a2, int a3, int a4, int a5);

// pdb: ShadowSceneNode::UpdateQueuedObjectLighting | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apObject, apSceneNode, abActiveLightsOnly, apRoom, apPortal
bool __cdecl FUN_00ae2ce0(Node_ae2ce0* node, int a2, int a3, int a4, int a5)
{
    if (node == 0) {
        return true;
    }
    if (node->unk20 != 0 && node->unk20->unk0C != 0.0f && !(node->unk30 & 1) && node->VSlot3() != 0) {
        Node_ae2ce0* obj = node->VSlot3();
        bool ok = true;
        unsigned int i = 0;
        void* r1 = FUN_00424d50(&DAT_0109054c, obj);
        if (r1 != 0) {
            void* r2 = FUN_007fbf10(r1);
            if (r2 == 0) {
                goto done;
            }
            ok = ok & FUN_00ae2ce0((Node_ae2ce0*)r2, a2, a3, a4, a5);
            goto done;
        }
        for (; i < obj->unkA6; ++i) {
            Node_ae2ce0* elem = obj->unkA0[i];
            if (elem != 0) {
                if (elem->VSlot7()) {
                    ok = ok & FUN_00ae1ad0(elem, a2, a3, a4, a5);
                } else {
                    ok = ok & FUN_00ae2ce0(elem, a2, a3, a4, a5);
                }
            }
        }
    done:
        return ok;
    }
    return false;
}
}   // namespace f3m_00ae2ce0

// @f3 0x00ae33e0 (community match, verified in this file)
// candidate for FUN_00ae33e0 (0x00ae33e0, 311 bytes) - shadow light lookup/alloc on a scene node
extern void (__stdcall* PTR_00d9b068)(unsigned long*);
extern long (__stdcall* PTR_00d9b064)(unsigned long*);
extern void (__stdcall* PTR_00d9b06c)(void*, unsigned long, unsigned long);

class FlagsObj
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
};

class LightEx
{
public:
    virtual void unkVirt00();
    virtual void DeleteThis();
    void IncRefCount() { PTR_00d9b068(&m_uiRefCount); }
    long DecRefCount() { return PTR_00d9b064(&m_uiRefCount); }
    LightEx();
    static void* operator new(unsigned int size);
    void FUN_00ae17d0(void* key);
    void FUN_00b20030(bool flag);
    void FUN_00b1dde0(float f, int i);
    unsigned long m_uiRefCount;
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
    FlagsObj* unkF8;
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
    void* unk128;
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
};

template <class T> class Ref
{
public:
    T* m_pObject;
    Ref(T* object) { m_pObject = object; if (m_pObject) m_pObject->IncRefCount(); }
    ~Ref() { if (m_pObject) { if (!m_pObject->DecRefCount()) m_pObject->DeleteThis(); } }
};

class NodeList
{
public:
    NodeList* unk00;
    void* unk04;
    LightEx* unk08;
};

template <class T> class PtrList
{
public:
    class Node
    {
    public:
        Node* m_pkNext;
        Node* m_pkPrev;
        T* m_element;
    };
    Node* m_pkHead;
    Node* m_pkTail;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
        Node* Allocate();
    } m_kItemCount;
    __declspec(noinline) void FUN_00827100(Ref<T> const& item)
    {
        Node* node = m_kItemCount.Allocate();
        T* old = node->m_element;
        if (old != item.m_pObject)
        {
            if (old)
            {
                if (!old->DecRefCount())
                    old->DeleteThis();
            }
            node->m_element = item.m_pObject;
            if (node->m_element)
                node->m_element->IncRefCount();
        }
        node->m_pkNext = 0;
        node->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = node;
        else
            m_pkHead = node;
        m_kItemCount.m_uiCount++;
        m_pkTail = node;
    }
};

class SpinLock
{
public:
    unsigned long unk00;
    unsigned long unk04;
    void FUN_00409a80(int flag);
    void Unlock()
    {
        if (--unk04 == 0)
            PTR_00d9b06c(this, 0, unk00);
    }
};

extern SpinLock DAT_0116fc80;

class SceneNode
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    NodeList* unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCc;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDc;
    unsigned int unkE0;
    PtrList<LightEx> unkE4;
    LightEx* FUN_00ae33e0(void* key);
};

// pdb: ShadowSceneNode::AddShadowLight | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apObject
LightEx* SceneNode::FUN_00ae33e0(void* key)
{
    NodeList* pos = unkC0;
    while (pos)
    {
        LightEx* const& ref = pos->unk08;
        pos = pos->unk00;
        LightEx* light = ref;
        if (light && light->unk128 == key)
        {
            FlagsObj* flags = light->unkF8;
            flags->unk30 &= 0xfffffffe;
            light->FUN_00b1dde0(1.0f, 0);
            return light;
        }
    }

    DAT_0116fc80.FUN_00409a80(0);
    LightEx* light = new LightEx;
    light->FUN_00ae17d0(key);
    light->FUN_00b20030(true);
    {
        Ref<LightEx> ptr(light);
        unkE4.FUN_00827100(ptr);
    }
    DAT_0116fc80.Unlock();
    return light;
}

// @f3 0x00afc720 (community match, verified in this file)
namespace task0228 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline unsigned int NiAtomicIncrement(unsigned int& value) {
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value) {
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
class NiRefObject {
public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount() { NiAtomicIncrement(m_uiRefCount); }
    void DecRefCount() { if (NiAtomicSubtract(m_uiRefCount) == 0) DeleteThis(); }
};

extern NiPointer<NiRefObject> DAT_01174958;
extern NiPointer<NiRefObject> DAT_011749b0;
struct FUN_00b62e90
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiPointer<NiRefObject> resource28;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    virtual ~FUN_00b62e90();
};
struct RendObj;
struct RendVtbl
{
    void* f0;
    void(__thiscall* release)(RendObj*);
};
struct RendObj
{
    RendVtbl* vtbl;
    long unk04;
    int unk08, unk0c, unk10;
    void* f14;
    int f18, unk1c, unk20, unk24, unk28, unk2c;
    void* f30;
    int unk34, unk38, unk3c, unk40;
    RendObj* f44;
    int unk48, unk4c, unk50, unk54, unk58;
    RendObj* f5c;
    int unk60;
    int refs;
    void FUN_00888c10();
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            FUN_00888c10();
    }
};
extern void* DAT_010af2f8;
extern NiPointer<NiRefObject> DAT_01173b08[156];
extern NiPointer<NiRefObject> DAT_011737c8[208];
extern NiPointer<RendObj> DAT_01173d78[759];
struct FUN_00afc720 : FUN_00b62e90
{
    int mode;
    NiPointer<NiRefObject> resource6c, resource70, resource74, resource78;
    NiPointer<NiRefObject> resource7c, resource80, resource84, resource88;
    ~FUN_00afc720();
};
// Destructor that zeroes global NiPointer arrays and member resource pointers.
// @fnv 0x00b79de0
// pdb: ShadowLightShader::~ShadowLightShader | ShadowLightShader.obj | fnv360_0822_retail, objrun, medium
FUN_00afc720::~FUN_00afc720()
{
    for (int i = 0; i < 156; ++i)
        DAT_01173b08[i] = 0;
    for (int i = 0; i < 208; ++i)
        DAT_011737c8[i] = 0;
    for (int i = 0; i < 759; ++i)
        DAT_01173d78[i] = 0;
    for (int i = 0; i < 22; ++i)
        reinterpret_cast<NiPointer<NiRefObject>*>(&DAT_01174958)[i] = 0;
    for (int i = 0; i < 22; ++i)
        reinterpret_cast<NiPointer<NiRefObject>*>(&DAT_011749b0)[i] = 0;
    resource28 = 0;
    resource6c = 0;
    resource70 = 0;
    resource74 = 0;
    resource78 = 0;
    resource80 = 0;
    resource7c = 0;
    resource88 = 0;
    resource84 = 0;
}
}  // namespace task0228

// @f3 0x00afccc0 (community match, verified in this file)
extern void* DAT_0116f2f8;
namespace f3m_00afccc0 {
namespace f3_0229 {
void* __cdecl FUN_0089eb90(unsigned int);
class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int auiSize) { return FUN_0089eb90(auiSize); }
};

struct FUN_00e76700_desc
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035(int a0, int a1, int a2, int a3, int a4);
    virtual void v036();
    virtual void v037(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
};
FUN_00e76700_desc* __cdecl FUN_0087e9a0(void* apRenderer, int aiType, int aiFlag);

class FUN_00afc480 : public BSFaceGenMorphData
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048(FUN_00e76700_desc* apDesc);
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    FUN_00afc480(FUN_00e76700_desc* ap0, FUN_00e76700_desc* ap1, FUN_00e76700_desc* ap2, FUN_00e76700_desc* ap3);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
};

// Builds four morph descriptors via FUN_0087e9a0, fills them with v035/v037 entries, creates a FUN_00afc480 from them, runs its setup calls and returns it.
// @fnv 0x00b7a380
// pdb: ShadowLightShader::CreateShader | ShadowLightShader.obj | fnv360_0822_retail, call_gap, medium
FUN_00afc480* __cdecl FUN_00afccc0()
{
    FUN_00e76700_desc* pDesc0 = FUN_0087e9a0(DAT_0116f2f8, 6, 1);
    FUN_00e76700_desc* pDesc1 = FUN_0087e9a0(DAT_0116f2f8, 8, 1);
    FUN_00e76700_desc* pDesc2 = FUN_0087e9a0(DAT_0116f2f8, 3, 1);
    FUN_00e76700_desc* pDesc3 = FUN_0087e9a0(DAT_0116f2f8, 8, 1);
    pDesc0->v035(0, 0, 0, 2, 0);
    pDesc0->v035(1, 3, 3, 2, 0);
    pDesc0->v035(2, 5, 4, 3, 0);
    pDesc0->v035(3, 7, 5, 1, 0);
    pDesc0->v035(4, 14, 13, 2, 0);
    pDesc0->v035(5, 15, 14, 2, 0);
    pDesc0->v045();
    pDesc1->v035(0, 0, 0, 2, 0);
    pDesc1->v035(1, 1, 1, 3, 0);
    pDesc1->v035(2, 2, 2, 4, 0);
    pDesc1->v035(3, 3, 3, 2, 0);
    pDesc1->v035(4, 5, 4, 3, 0);
    pDesc1->v035(5, 7, 5, 1, 0);
    pDesc1->v035(6, 14, 13, 2, 0);
    pDesc1->v035(7, 15, 14, 2, 0);
    pDesc1->v045();
    pDesc2->v035(0, 0, 0, 2, 0);
    pDesc2->v035(1, 3, 5, 1, 0);
    pDesc2->v037(0, 2, 5, (int)0x80000000, 0, 5, 1, 0);
    pDesc2->v045();
    pDesc3->v035(0, 0, 0, 2, 0);
    pDesc3->v035(1, 3, 3, 2, 0);
    pDesc3->v035(2, 5, 4, 3, 0);
    pDesc3->v035(3, 7, 5, 1, 0);
    pDesc3->v035(4, 14, 13, 2, 0);
    pDesc3->v035(5, 15, 14, 2, 0);
    pDesc3->v037(0, 6, 8, (int)0x80000000, 3, 5, 1, 0);
    pDesc3->v037(0, 7, 9, (int)0x80000001, 3, 5, 2, 0);
    pDesc3->v045();
    FUN_00afc480* pShader = new FUN_00afc480(pDesc0, pDesc1, pDesc2, pDesc3);
    pShader->v019();
    pShader->v081();
    pShader->v084();
    pShader->v071();
    pShader->v048(pDesc0);
    return pShader;
}
}  // namespace fnv_00b7a380
}   // namespace f3m_00afccc0

// @f3 0x00afd070 (community match, verified in this file)
namespace fnv_00b7a730 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct PassShaderObj
{
    virtual void V0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct PassShaderPtr
{
    PassShaderObj* m_pObject;
    PassShaderPtr& operator=(PassShaderObj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class NiD3DPass;
class NiD3DPass
{
  public:
    static void FUN_00888f80(NiPointer<NiD3DPass>& spRenderPass);
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
    PassShaderPtr m_pGeometryShader;
};
extern NiPointer<NiD3DPass> DAT_01173d78[0x2f7];
extern PassShaderObj* DAT_01173b08;
extern int DAT_0116efb0;
struct FUN_00b78980_shell
{
    void FUN_00b64220();
    void FUN_00b65960();
    void FUN_00b693a0();
    void FUN_00b69860();
    void FUN_00b69ec0();
    void FUN_00b6a8f0();
    void FUN_00b6af40();
    void FUN_00b6b8c0();
    void FUN_00b6bfe0();
    void FUN_00b6cc10();
    void FUN_00b6d010();
    void FUN_00b6d7d0();
    void FUN_00b6dcc0();
    void FUN_00b72650();
    void FUN_00b78590();
    void FUN_00b7ae40();
    void FUN_00b7b590();
    void FUN_00b7de40();
    void FUN_00b7e740();
    void FUN_00b82b20();
    void FUN_00b82f60();
    void FUN_00b83700();
    void FUN_00b83b60();
    void FUN_00b83ea0();
    void FUN_00b84280();
    bool FUN_00afd070();
};

// Resets all 0x2f7 NiD3DPass entries to DAT_01173b08, then runs the base pass setup and, at particle shader level >= 2, the extra setup routines; returns true.
// @fnv 0x00b7a730
// pdb: ShadowLightShader::LoadStagesAndPasses | ShadowLightShader.obj | fnv360_0721_beta, caller_sim, medium
bool FUN_00b78980_shell::FUN_00afd070()
{
    for (unsigned int i = 0; i < 0x2f7; i++)
    {
        NiD3DPass::FUN_00888f80(DAT_01173d78[i]);
        DAT_01173d78[i]->m_pGeometryShader = DAT_01173b08;
    }
    FUN_00b6d010();
    FUN_00b6d7d0();
    FUN_00b64220();
    FUN_00b65960();
    FUN_00b693a0();
    FUN_00b69860();
    FUN_00b69ec0();
    FUN_00b6a8f0();
    FUN_00b6af40();
    FUN_00b6b8c0();
    FUN_00b6cc10();
    if (DAT_0116efb0 >= 2)
    {
        FUN_00b78590();
        FUN_00b6dcc0();
        FUN_00b72650();
        FUN_00b7ae40();
        FUN_00b7b590();
        FUN_00b7de40();
        FUN_00b7e740();
        FUN_00b82f60();
        FUN_00b83700();
        FUN_00b83b60();
        FUN_00b83ea0();
        FUN_00b82b20();
        FUN_00b84280();
    }
    else
    {
        FUN_00b6bfe0();
    }
    return true;
}
}  // namespace fnv_00b7a730

// @f3 0x00afc280 (community match, verified in this file)
namespace fo3_afc280 {
struct GatePointer { void* m_pObject; };
extern GatePointer DAT_011749fc;
extern const float DAT_01173664[4];
extern const float DAT_01173644[4];
struct NLPt3
{
    float x, y, z;
    NLPt3()
    {}
    NLPt3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float Dot(const NLPt3& p) const
    {
        const float& rz = z;
        return x * p.x + y * p.y + rz * p.z;
    }
};

struct NLPlane
{
    NLPt3 normal;
    float constant;
    NLPlane()
    {}
    NLPlane(float a, float b, float c, float d) : normal(a, b, c), constant(d)
    {}
};

extern NLPt3 DAT_01170020;
extern NLPlane DAT_0116f3f4;
extern float DAT_0116f404;
extern float DAT_0116f408;

// @fnv 0x00b79730
// pdb: ShadowLightShader::SetupGeometryConstants_WaterFog | ShadowLightShader.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: ShadowLightShader::SetupGeometryConstants_SimpleShadowClipPlanes)
void __cdecl FUN_00afc280()
{
    if (reinterpret_cast<char*>(DAT_011749fc.m_pObject)[8])
    {

        NLPt3 pt(DAT_01170020.x, DAT_01170020.y, DAT_01170020.z);
        NLPlane plane;
        plane = DAT_0116f3f4;
        NLPt3 normal = DAT_0116f3f4.normal;
        float i = plane.normal.Dot(pt);
        NLPlane outPlane(normal.x, normal.y, normal.z, i - plane.constant);
        *(NLPlane*)DAT_01173664 = outPlane;

        float m_fEndValue = DAT_0116f408;
        float dot = DAT_0116f404;
        if (m_fEndValue == 0.0f && dot == 0.0f)
        {
            *(NLPlane*)DAT_01173644 = NLPlane(0.0f, 0.0f, -1.0f, 0.0f);
        }
        else
        {
            *(NLPlane*)DAT_01173644 = NLPlane(m_fEndValue, m_fEndValue - dot, 1.0f, 1.0f);
        }
    }
}

}

// @f3 0x00afbf60 (community match, verified in this file)
struct ConstantEntryPtr { void* m_pObject; };
extern ConstantEntryPtr DAT_011749b8;
struct Vec4
{
    float x, y, z, w;
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};

extern Vec4 DAT_0116fe40[];

// @fnv 0x00b79410
// pdb: ShadowLightShader::SetupGeometryConstants_LandTextureMask | ShadowLightShader.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: ShadowLightShader::SetupGeometryConstants_Toggles)
// pdb params: epass, apRenderPass
void __stdcall FUN_00afbf60(unsigned int uiMessageId, unsigned char* pucPayload)
{
    int iSlotA;
    int iSlotB;

    switch (uiMessageId)
    {
    case 0x93:
    case 0x1f1:
    case 0x1f2:
    case 0x1f3:
    case 0x1f4:
    case 0x1f5: {
        iSlotA = 2;
        iSlotB = 3;
        int iValue = pucPayload[9] + 2;
        if (iValue <= 3)
            iValue = 3;
        *(int*)((char*)DAT_011749b8.m_pObject + 0x20) = iValue;
        break;
    }
    case 0x1f6:
        iSlotA = 0;
        iSlotB = 27;
        break;
    default:
        return;
    }

    int c = pucPayload[11];
    DAT_0116fe40[iSlotA] =
        Vec4(c == 1 ? 1.0f : 0.0f, c == 2 ? 1.0f : 0.0f, c == 3 ? 1.0f : 0.0f, c == 4 ? 1.0f : 0.0f);
    DAT_0116fe40[iSlotB] =
        Vec4(c == 5 ? 1.0f : 0.0f, c == 6 ? 1.0f : 0.0f, c == 7 ? 1.0f : 0.0f, c == 8 ? 1.0f : 0.0f);
}

// @f3 0x00afc100 (community match, verified in this file)
namespace fo3_afc100 {
struct Gate { int unk00, unk04; char enabled; };
extern Gate* DAT_011749c0;
struct BSFogProperty;
BSFogProperty* __cdecl FUN_00adb920(int);
extern unsigned char DAT_0116efb4;
extern float DAT_01170054, DAT_0117005c, DAT_00e95e20, DAT_01170058;
struct GeomS
{
    virtual void Gb0();
    virtual void Gb1();
    virtual void Gb2();
    virtual void Gb3();
    virtual void Gb4();
    virtual void Gb5();
    virtual void Gb6();
    virtual void Gb7();
    virtual void Gb8();
    virtual void Gb9();
    virtual void Gb10();
    virtual void Gb11();
    virtual void Gb12();
    virtual void Gb13();
    virtual void Gb14();
    virtual void Gb15();
    virtual void Gb16();
    virtual void Gb17();
    virtual void Gb18();
    virtual void Gb19();
    virtual void Gb20();
    virtual void Gb21();
    virtual void Gb22();
    virtual void Gb23();
    virtual void Gb24();
    virtual void Gb25();
    virtual void Gb26();
    virtual void Gb27();
    virtual void Gb28();
    virtual void Gb29();
    virtual void Gb30();
    virtual void Gb31();
    virtual void Gb32();
    virtual void Gb33();
    virtual void Gb34();
    virtual void Gb35();
    virtual void Gb36();
    virtual void Gb37();
    virtual void Gb38();
    virtual void Gb39();
    virtual void Gb40();
    virtual void Gb41();
    virtual void Gb42();
    virtual void Gb43();
    virtual void Gb44();
    virtual void Gb45();
    virtual void Gb46();
    virtual void Gb47();
    virtual void Gb48();
    virtual void Gb49();
    virtual void Gb50();
    virtual void Gb51();
    virtual void Gb52();
    virtual void Gb53();
    virtual void Gb54();
    virtual void Gb55();
    virtual void Gb56();
    virtual void Gb57();
    virtual void Gb58();
    virtual void Gb59();
    virtual void Gb60();
    virtual int GetFlag(int, int);
};
struct GeomData
{
    int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
    unsigned int uiFlags;
    int unk24, unk28, unk2c;
    float fAlpha;
};
struct PropS
{
    int unk00;
int unk04;
    unsigned char bFlag;
};
struct MatS
{
    int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
    unsigned short usFlags;
    unsigned char ucAlpha;
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (unsigned short)((usFlags & usMask) >> usPos);
    }
    bool GetBit(unsigned short usMask) const
    {
        return (usFlags & usMask) != 0;
    }
};
struct ShaderS
{
    virtual void Va0();
    virtual void Va1();
    virtual void Va2();
    virtual void Va3();
    virtual void Va4();
    virtual void Va5();
    virtual void Va6();
    virtual void Va7();
    virtual void Va8();
    virtual void Va9();
    virtual void Va10();
    virtual void Va11();
    virtual void Va12();
    virtual void Va13();
    virtual void Va14();
    virtual void Va15();
    virtual void Va16();
    virtual void Va17();
    virtual void Va18();
    virtual void Va19();
    virtual void Va20();
    virtual void Va21();
    virtual void Va22();
    virtual void Va23();
    virtual void Va24();
    virtual void Va25();
    virtual void Va26();
    virtual void Va27();
    virtual void Va28();
    virtual void Va29();
    virtual void Va30();
    virtual void Va31();
    virtual void Va32();
    virtual void Va33();
    virtual void Va34();
    virtual void Va35();
    virtual void Va36();
    virtual void Va37();
    virtual void Va38();
    virtual void Va39();
    virtual void Va40();
    virtual void Va41();
    virtual void Va42();
    virtual void Va43();
    virtual void Va44();
    virtual void Va45();
    virtual void Va46();
    virtual void Va47();
    virtual void Va48();
    virtual void Va49();
    virtual void Va50();
    virtual void Va51();
    virtual void Va52();
    virtual void Va53();
    virtual void Va54();
    virtual void Va55();
    virtual void Va56();
    virtual void Va57();
    virtual void Va58();
    virtual void Va59();
    virtual void Va60();
    virtual void Va61();
    virtual void Va62();
    virtual void Va63();
    virtual void Va64();
    virtual void Va65();
    virtual void Va66();
    virtual void Va67();
    virtual void Va68();
    virtual void Va69();
    virtual void Va70();
    virtual void Va71();
    virtual void Va72();
    virtual void Va73();
    virtual void Va74();
    virtual void Va75();
    virtual void Va76();
    virtual void Va77();
    virtual void Va78();
    virtual void Va79();
    virtual void Va80();
    virtual void Va81();
    virtual void Va82();
    virtual void Va83();
    virtual void Va84();
    virtual void SetFog(void*, BSFogProperty*, void*);
    void FUN_00b856d0(void*, int, GeomS*, int);
    void FUN_00afc100(unsigned int uiPass, void* pArg2, GeomS* pGeom, void* pArg4, PropS* pProp, MatS* pMatrix);
};

// Sets fog or pass-specific state, then updates DAT_0117005c/DAT_01170058 alpha values from the geometry and material flags.
// @fnv 0x00b795b0
// pdb: ShadowLightShader::SetupGeometryConstants_Toggles | ShadowLightShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: epass, pgeometry, pprop, pmaterialProperty, apRenderPass, palphaProp
void ShaderS::FUN_00afc100(unsigned int uiPass, void* pArg2, GeomS* pGeom, void* pArg4, PropS* pProp, MatS* pMatrix)
{
    if (!DAT_011749c0->enabled)
        return;
    if (uiPass - 0x1f7 <= 0x37)
        FUN_00b856d0(pArg2, 0, pGeom, 0);
    else
        SetFog(pArg2, FUN_00adb920(DAT_0116efb4), pArg4);
    if (pProp && !pProp->bFlag)
        DAT_01170054 = 0.0f;
    if (!((((GeomData*)pGeom)->uiFlags & 0x4000) > 0) && (uiPass < 0x248 || uiPass > 0x24b))
    {
        if ((unsigned char)(pMatrix->usFlags >> 9) & 1)
        {
            float fRef = pMatrix->ucAlpha;
            float fAlpha = 1.0 > fRef ? 1.0f : fRef;
            DAT_0117005c = fAlpha / 255.0;
        }
        else
        {
            DAT_0117005c = pMatrix->GetBit(1) ? DAT_00e95e20 : 0.0f;
        }
        return;
    }
    if (uiPass - 0x248 <= 3)
    {
        DAT_0117005c = pGeom->GetFlag(5, 0) ? 1.0f : 0.0f;
        DAT_01170058 = ((GeomData*)pGeom)->fAlpha;
    }
}

}

// @f3 0x00af3aa0 (community match, verified in this file)
struct WaterColor { float r,g,b; WaterColor& operator*=(float f) {r*=f;g*=f;b*=f;return *this;} };
struct WaterRGBA {float r,g,b,a; WaterRGBA() {} WaterRGBA(float x,float y,float z,float w):r(x),g(y),b(z),a(w){} };
struct WaterData {unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
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
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned int unkc0;float fC4; WaterColor kColor,m_kDeepColor;unsigned int unke0;
unsigned int unke4;
unsigned int unke8;
unsigned int unkec;NiPoint3 kWorldPosition;};
struct Water {unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
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
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;
unsigned int unka8;
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned int unkc0;
unsigned int unkc4;
unsigned int unkc8;
unsigned int unkcc;float fD0,fD4;unsigned int unkd8;
unsigned int unkdc;
unsigned int unke0;
unsigned int unke4;
unsigned int unke8;
unsigned int unkec;
unsigned int unkf0;
unsigned int unkf4;WaterData* pData;};
struct WaterShader {unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;int iType; float FUN_00ae9f70();};
struct WaterNode {unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
unsigned int unk1c;
unsigned int unk20;
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
unsigned int unk70;
unsigned int unk74;
unsigned int unk78;
unsigned int unk7c;
unsigned int unk80;
unsigned int unk84;
unsigned int unk88;
unsigned int unk8c;
unsigned int unk90;
unsigned int unk94;
unsigned int unk98;
unsigned int unk9c;
unsigned int unka0;
unsigned int unka4;WaterShader* pShader;};
extern WaterNode** DAT_0116efd0;
extern WaterRGBA DAT_00f73210;
extern float DAT_0116f26c,DAT_0116ef80;
extern bool DAT_0116f20e,DAT_0116f217;
void __cdecl FUN_00b3bb90(unsigned int,WaterRGBA);
void __cdecl FUN_00b3bbc0(unsigned int,WaterRGBA,WaterRGBA);
void __cdecl FUN_00b3dde0(const WaterRGBA*,bool);
// pdb: BSShaderLightingProperty::SetDirectionalLight3x | BSShaderLightingProperty.obj | fnv360_1110_retail, call_seq, medium
// pdb params: auiLightIndex, apLight, afForcedDarkness
void __cdecl FUN_00af3aa0(unsigned int id, Water* water, float scale)
{
    Water* w = water;
    if (!w)
    {
        FUN_00b3bb90(id, DAT_00f73210);
        return;
    }
    WaterShader* p = DAT_0116efd0[0]->pShader;
    WaterData* data = w->pData;
    WaterShader* shader = (p && p->iType >= 7 && p->iType <= 11) ? p : 0;
    NiPoint3 direction = data->kWorldPosition;
    WaterRGBA first;
    first.r = direction.x;
    first.g = direction.y;
    first.b = direction.z;
    first.a = shader ? shader->FUN_00ae9f70() : 1.0f;
    float brightness = DAT_0116f26c;
    bool flag = false;
    WaterRGBA kLightRgba = DAT_00f73210;
    float multiplier = data->fC4;
    if (!DAT_0116f20e && 1.0 < multiplier)
        multiplier = 1.0f;
    WaterColor color = data->kColor;
    color.r *= multiplier;
    color.g *= multiplier;
    color.b *= multiplier;
    if (brightness > 0.0f)
    {
        float grey = (double)0.34f * color.g + (double)0.33f * color.r + color.b + (double)0.33f;
        if (grey <= 0.0f)
            color.b = color.g = color.r = brightness;
        else
        {
            float f = brightness < grey ? 1.0f : brightness / grey;
            color.r = (color.r + double(0.1f)) * f;
            color.g = (color.g + double(0.1f)) * f;
            color.b = (color.b + double(0.1f)) * f;
        }
    }
    color *= scale;
    if (scale < 1.0f)
        flag = true;
    kLightRgba.r = color.r;
    kLightRgba.g = color.g;
    kLightRgba.b = color.b;
    kLightRgba.a = 1.0f;
    FUN_00b3dde0(&kLightRgba, flag);
    multiplier = multiplier * scale;
    multiplier *= w->fD0;
    if (DAT_0116f20e && !DAT_0116f217)
        multiplier *= DAT_0116ef80;
    color = data->m_kDeepColor;
    FUN_00b3bbc0(id, first, WaterRGBA(color.r * multiplier, color.g * multiplier, color.b * multiplier, w->fD4));
}

// @f3 0x00aff4b0 (community match, verified in this file)
namespace light26 {
struct Vec { float x,y,z; Vec operator*(float s) const {Vec r=*this; r.x*=s;r.y*=s;r.z*=s;return r;} };
struct V4 {float x,y,z,w; V4(){} V4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){} };
struct Alpha {float FUN_00ae9f70();};
struct Prop {unsigned int unk000;
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
unsigned int unk0a4;Alpha* alpha;};
struct Light {unsigned int unk000;
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
unsigned int unk088;Vec position;unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;float dimmer;unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;Vec diffuse;float radius;};
struct Entry {unsigned int unk000;
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
unsigned int unk0cc;float dimmer;unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;Light* light;float GetDimmer(){return dimmer;}};
struct Set {Prop* property;int unk04; unsigned char unk08,count; unsigned short unk0a;Entry** entries;};
struct Source {unsigned int unk000;
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
unsigned int unk034;float scale;};
struct Offset {unsigned int unk000;
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
unsigned int unk1e0;Vec translate;};
struct Const {unsigned int unk000;
unsigned int unk004;bool enabled;unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;int active20;};
struct Device;
struct DeviceVT {void* slot0;void* slot1;void* slot2;void* slot3;void* slot4;void* slot5;void* slot6;void* slot7;void* slot8;void* slot9;void* slot10;void* slot11;void* slot12;void* slot13;void* slot14;void* slot15;void* slot16;void* slot17;void* slot18;void* slot19;void* slot20;void* slot21;void* slot22;void* slot23;void* slot24;void* slot25;void* slot26;void* slot27;void* slot28;void* slot29;void* slot30;void* slot31;void* slot32;void* slot33;void* slot34;void* slot35;void* slot36;void* slot37;void* slot38;void* slot39;void* slot40;void* slot41;void* slot42;void* slot43;void* slot44;void* slot45;void* slot46;void* slot47;void* slot48;void* slot49;void* slot50;void* slot51;void* slot52;void* slot53;void* slot54;void* slot55;void* slot56;void* slot57;void* slot58;void* slot59;void* slot60;void* slot61;void* slot62;void* slot63;void* slot64;void* slot65;void* slot66;void* slot67;void* slot68;void* slot69;void* slot70;void* slot71;void* slot72;void* slot73;void* slot74;void* slot75;void* slot76;void* slot77;void* slot78;void* slot79;void* slot80;void* slot81;void* slot82;void* slot83;void* slot84;void* slot85;void* slot86;void* slot87;void* slot88;void* slot89;void* slot90;void* slot91;void* slot92;void* slot93;long (__stdcall* SetVSConst)(Device*,unsigned int,const float*,unsigned int);};
struct Device { DeviceVT* vtable; };
struct Holder {unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;Device* device; long SetVSConst(unsigned int i,const float* p,unsigned int n){return device->vtable->SetVSConst(device,i,p,n);} };
struct Manager {unsigned int unk000;
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
unsigned int unk058;Holder* holder;};
extern Set* DAT_0116efd0;extern Manager* DAT_01091980;extern Const* DAT_011749b8;extern Const* DAT_011749cc;extern Offset* DAT_0116efb8;extern bool DAT_0116f20e;extern V4 DAT_01173728[];extern V4 DAT_0116fe40[];
void __stdcall FUN_00c20856(Vec*,const Vec*,const void*);
extern const float DAT_00e95f80; extern const float DAT_00db99c8;
void __stdcall FUN_00aff4b0(const void* matrix, float radiusScale, Source* source)
{
    Set* lights = reinterpret_cast<Set*>(DAT_0116efd0);
    float alpha = lights->property->alpha->FUN_00ae9f70();
    V4 ambient(DAT_00e95f80, DAT_00e95f80, DAT_00e95f80, alpha);
    DAT_01091980->holder->SetVSConst(25,&ambient.x,1);
    int count = (int)lights->count - 1;
    if (count < 2)
        count = 2;
    DAT_011749b8->active20 = count;
    if (DAT_011749cc->enabled)
        DAT_011749cc->active20 = (int)lights->count - 1;
    float lightCount;
    float scale = source ? source->scale : DAT_00db99c8;
    lightCount = (float)lights->count - 1.0;
    V4 result;
    for (unsigned char i = 1; i < lights->count; ++i)
    {
        Entry* entry = lights->entries[i];
        Light* light = entry->light;
        Vec position = light->position;
        Vec offset = DAT_0116efb8->translate;
        position.x += offset.x;
        position.y += offset.y;
        position.z += offset.z;
        Vec transformed;
        FUN_00c20856(&transformed, &position, matrix);
        float radius = light->radius / radiusScale;
        DAT_01173728[i].x = transformed.x;
        DAT_01173728[i].y = transformed.y;
        DAT_01173728[i].z = transformed.z;
        DAT_01173728[i].w = radius;
        DAT_01091980->holder->SetVSConst(25+i,&DAT_01173728[i].x,1);
        float dimmer = light->dimmer;
        if (!DAT_0116f20e && 1.0 < dimmer)
            dimmer = 1.0f;
        Vec color = light->diffuse * dimmer * entry->GetDimmer();
        result = V4(color.x, color.y, color.z, lightCount);
        DAT_0116fe40[i] = result;
        lightCount = scale;
    }
    if (lights->count == 2)
    {
        result = V4(0.0f, 0.0f, 0.0f, scale);
        DAT_0116fe40[2] = result;
    }
}
}

// @f3 0x00af4060 (community match, verified in this file)
extern const char* DAT_011702e0;
extern const char DAT_00e953d4[];
extern const char DAT_00e953c4[];
extern const char DAT_00e953b4[];
namespace f3m_00af4060 {


char* __cdecl FUN_00847b50(const char* label);
char* __cdecl FUN_00847ce0(const char* label, unsigned int value);
char* __cdecl FUN_00847d80(const char* label, unsigned int value);

class ViewerStrings
{
public:
    void FUN_00555790(unsigned int capacity);
    void FUN_005b3880(unsigned int index, char* const& value);

    __forceinline void Add(char* value)
    {
        unsigned int index = firstFree;
        if (index >= capacity)
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner {
public:
    void FUN_00b2b9f0(ViewerStrings* strings);
    unsigned int FUN_00af3450();
    void FUN_00af4060(ViewerStrings* strings);

    unsigned int unk00[26];
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
};

// pdb: BSShaderLightingProperty::GetViewerStrings | BSShaderLightingProperty.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void Owner::FUN_00af4060(ViewerStrings* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50(DAT_011702e0));
    unsigned int v68 = unk68;
    strings->Add(FUN_00847ce0(DAT_00e953d4, v68));
    strings->Add(FUN_00847ce0(DAT_00e953c4, FUN_00af3450()));
    unsigned int v70 = unk70;
    strings->Add(FUN_00847d80(DAT_00e953b4, v70));
}
}   // namespace f3m_00af4060

// @f3 0x00afb610 (community match, verified in this file)
namespace task1103 {
struct P3_bbb890
{
    float x, y, z;
};
struct M_bbb890
{
    float m[4][4];
};
struct Quad119
{
    float x, y, z, w;
    Quad119& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
        return *this;
    }
};
struct Light119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned char kind;
};
struct Property119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags;
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
    float time;
    Light119* __thiscall FUN_00af3280(void*&);
};
struct Pass119
{
    unsigned int unk0;
    unsigned short type;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char count;
    unsigned short unka;
    Light119** lights;
};
struct Scale119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    float scale;
};
struct Scene119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    P3_bbb890 position;
};
struct Renderer119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    unsigned int colorX, colorY, colorZ, colorW;
};
class NiShaderConstantMapEntry
{
  public:
    unsigned int unk0, unk4;
    unsigned char active;
    unsigned char unk9;
    unsigned short unka;
    unsigned int unkc, unk10, unk14, unk18, unk1c;
    unsigned int value;
};
struct EntryPointer {NiShaderConstantMapEntry* m_pObject;};
extern EntryPointer DAT_01174970, DAT_011749b8, DAT_011749cc;
extern const unsigned char DAT_0116fe40[], DAT_0116fe50[];
extern const float DAT_01173728[];
extern unsigned int DAT_0116efa8;
extern Scene119* DAT_0116efb8;
extern bool DAT_0116f20e;
extern float DAT_0116ef74;
extern const float DAT_00dbe1e0;
extern Quad119 DAT_0116fef0[];
extern float DAT_0116ff70[];
Renderer119* __cdecl FUN_00ad5a60();
void __cdecl FUN_00af34e0(unsigned int, Light119*, float);
P3_bbb890* __stdcall FUN_00c20856(P3_bbb890*, const P3_bbb890*, const M_bbb890*);
P3_bbb890* __stdcall FUN_00c208b0(P3_bbb890*, const P3_bbb890*, const M_bbb890*);
P3_bbb890* __stdcall FUN_00c2085c(P3_bbb890*, const P3_bbb890*);
static inline void Scl(P3_bbb890& v, float f)
{
    v.x *= f;
    v.y *= f;
    v.z *= f;
}
static inline Quad119 QMul(const Quad119& v, float f)
{
    Quad119 r = v;
    r *= f;
    return r;
}
// Updates shader light constants for a pass: writes light positions/radii or directions, adjusts diffuse color, and handles the id 0x24b case.
// @fnv 0x00b78a90
// pdb: ShadowLightShader::SetupGeometryConstants_Lights | ShadowLightShader.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pprop, apRenderPass, d3dInvWorld, aWorld, epass, apSkin
void __stdcall FUN_00afb610(Property119* pProperty, Pass119* pass, M_bbb890 matrix, Scale119* scale, unsigned int id,
                               unsigned int world)
{
    float time = pProperty->time;
    if (DAT_0116efa8 == 15)
    {
        Renderer119* renderer = FUN_00ad5a60();
        unsigned int* color = reinterpret_cast<unsigned int*>(const_cast<unsigned char*>(DAT_0116fe40));
        color[0] = renderer->colorX;
        color[1] = renderer->colorY;
        color[2] = renderer->colorZ;
        color[3] = renderer->colorW;
        return;
    }
    if (DAT_01174970.m_pObject->active)
    {
        if (pass->type >= 16 && pass->type <= 19)
            DAT_01174970.m_pObject->value = 1;
        else
            DAT_01174970.m_pObject->value = pass->count;
    }
    if (DAT_011749b8.m_pObject->active)
        DAT_011749b8.m_pObject->value = pass->count;
    if (DAT_011749cc.m_pObject->active)
        DAT_011749cc.m_pObject->value = pass->count - 1;
    for (unsigned char i = 0; i < pass->count; ++i)
    {
        if (i >= 10)
            break;
        Light119* light = pass->lights[i];
        FUN_00af34e0(i, light, time);
        unsigned int index = i;
        if (pass->type >= 16 && pass->type <= 19)
        {
            reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index] = DAT_0116fef0[index];
            reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].w =
                reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].x;
        }
        else if (light)
        {
            if (light->kind)
            {
                P3_bbb890 position;
                position.x = DAT_0116fef0[index].x;
                position.y = DAT_0116fef0[index].y;
                position.z = DAT_0116fef0[index].z;
                P3_bbb890 sceneOffset = DAT_0116efb8->position;
                position.x = sceneOffset.x + position.x;
                position.y = sceneOffset.y + position.y;
                position.z = sceneOffset.z + position.z;
                P3_bbb890 transformedPos;
                FUN_00c20856(&transformedPos, &position, &matrix);
                float radius = reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].x;
                if (!world)
                {
                    if (pass->type >= 0x231 && pass->type <= 0x233)
                    {
                        Scl(transformedPos, scale->scale);
                    }
                    else
                        radius /= scale->scale;
                }
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].x = transformedPos.x;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].y = transformedPos.y;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].z = transformedPos.z;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].w = radius;
            }
            else
            {
                P3_bbb890 lightDirection;
                lightDirection.x = -reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].x;
                lightDirection.y = -reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].y;
                lightDirection.z = -reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].z;
                P3_bbb890 transformedPos;
                FUN_00c208b0(&transformedPos, &lightDirection, &matrix);
                FUN_00c2085c(&lightDirection, &transformedPos);
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].x = lightDirection.x;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].y = lightDirection.y;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].z = lightDirection.z;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_01173728))[index].w =
                    reinterpret_cast<const Quad119*>(DAT_0116ff70)[index].w;
            }
        }
    }
    Quad119& diffuseColor = *reinterpret_cast<Quad119*>(const_cast<unsigned char*>(DAT_0116fe50));
    if (DAT_0116f20e && (pProperty->flags & 0x400) > 0 && pass->count > 0 && !pass->lights[0]->kind)
    {
        diffuseColor = QMul(diffuseColor, DAT_0116ef74);
    }
    if (id == 0x24b)
    {
        scale = 0;
        if (DAT_0116efa8 != 10)
        {
            Light119* light = pProperty->FUN_00af3280(reinterpret_cast<void*&>(scale));
            if (!light || !light->kind)
                diffuseColor = *reinterpret_cast<const Quad119*>(DAT_0116fe40);
        }
        else
        {
            Light119* light = pProperty->FUN_00af3280(reinterpret_cast<void*&>(scale));
            if (!light || !light->kind)
            {
                Quad119 color;
                color.x = DAT_00dbe1e0;
                color.y = DAT_00dbe1e0;
                color.z = DAT_00dbe1e0;
                color.w = 1.0f;
                diffuseColor = color;
            }
        }
    }
}

}

// @f3 0x00ae8a50 (community match, verified in this file)
extern CompareExchange DAT_00d9b06c;
extern const char DAT_00e94b38[], DAT_00e94b0c[], DAT_00e94af0[];
namespace f3m_00ae8a50 {

struct MemManager { void FUN_0086ba60(void*); }; extern MemManager DAT_01090a78;
inline void Free(void* p){ DAT_01090a78.FUN_0086ba60(p); }
struct Data14 { ~Data14(); static void operator delete(void* p){ DAT_01090a78.FUN_0086ba60(p); } };
struct Data170 { ~Data170(); static void operator delete(void* p){ DAT_01090a78.FUN_0086ba60(p); } };
struct Data { int unk00,unk04,unk08,unk0c,unk10; Data14* m_p14; };
struct Destroyable { virtual void Destroy(int); };
struct RefObject { virtual void Slot0(); virtual void Delete(); long refs; };
struct Smart { RefObject* p; void Reset(){ RefObject* old=p; if(old){ if(!InterlockedDecrement(&old->refs)) old->Delete(); p=0; }} ~Smart(){ RefObject* old=p; if(old && !InterlockedDecrement(&old->refs)) old->Delete(); } };
struct FUN_00bd12d0 { FNVPointerListItem* head; FNVPointerListItem* tail; unsigned count; ~FUN_00bd12d0() throw();  void RemoveHead(){ FNVPointerListItem* node=head; head=node->m_pkNext; if(head) head->m_pkPrev=0; else tail=0; node->m_element=0; DAT_0106e5a0.FUN_00409a80(0); node->m_pkPrev=0; node->m_pkNext=DAT_0106e588; DAT_0106e588=node; if(--DAT_0106e5a4==0){ long owner=*(long const volatile*)&DAT_0106e5a0.value; DAT_00d9b06c((volatile long*)&DAT_0106e5a0,0,owner); } --count; } };
struct FUN_00ae89e0 { int unk00,unk04,unk08,unk0c,unk10; void FUN_00ae7440(); ~FUN_00ae89e0(); void Reset(){ FUN_00ae7440(); unk0c=unk04; unk04=0; unk08=0; unk10=0; } };
void FUN_0089e890(void*);
struct MapBase { virtual void Slot(); int unk04; void* data; int unk0c; virtual ~MapBase(){ FUN_006bd950(); FUN_0089e890(data); } void FUN_006bd950(); };
struct Map : MapBase { virtual ~Map(){ FUN_006bd950(); } };
struct FUN_00b2aec0 { int unk00,unk04,unk08,unk0c; ~FUN_00b2aec0(); };
struct FUN_00865d20 { virtual ~FUN_00865d20();
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

};
struct Slot { Data14* p; int unk04,unk08,unk0c,unk10; };
struct Critical { CRITICAL_SECTION value; ~Critical(){ DeleteCriticalSection(&value); } };
struct Target : FUN_00865d20 {
 Slot slots[3]; int unk84,unk88; void* p8c;
 FUN_00bd12d0 list90; FUN_00ae89e0 a[4],b[4]; Smart sp13c; FUN_00bd12d0 list140; int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
 Data170* p170; Destroyable *p174,*p178; void *p17c,*p180,*p184,*p188;
 int unk18c,unk190,unk194; Smart sp198; int unk19c; Smart sp1a0; FUN_00b2aec0 member; Map map;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
 Critical cs;
 virtual ~Target();
};
// pdb: BSShaderAccumulator::~BSShaderAccumulator | BSShaderAccumulator.obj | fnv360_0822_retail, caller_sim, low
Target::~Target(){

 for(int i=0;i<4;++i){ a[i].Reset(); b[i].Reset(); }
 Free(p8c);
 while(list140.count){ Data* d=(Data*)list140.head->m_element; if(d){ if(d->m_p14){ delete d->m_p14; d->m_p14=0; } DAT_01090a78.FUN_0086ba60(d); } list140.RemoveHead(); }
 sp13c.Reset();
 for(int i=0;i<3;++i){ if(slots[i].p){ delete slots[i].p; slots[i].p=0; } }
 if(p170){ delete p170; p170=0; }
 if(p174) p174->Destroy(1); if(p178) p178->Destroy(1);
 Free(p17c); Free(p180); Free(p184); Free(p188);
 sp1a0.Reset(); map.FUN_006bd950(); sp198.Reset();
}
}   // namespace f3m_00ae8a50

// @f3 0x00ae2130 (community match, verified in this file)
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

__declspec(thread) extern int g_memContext;

class AutoMemContext
{
  public:
    int m_iOld;
    AutoMemContext(int context)
    {
        m_iOld = g_memContext;
        g_memContext = context;
    }
    ~AutoMemContext()
    {
        g_memContext = m_iOld;
    }
};

struct NiUpdateData
{
    float fTime;
    bool bUpdateControllers;
    bool bIsMultiThreaded;
    bool bUpdateProperties;
    bool bUpdateShaders;
    bool bUpdateCollision;
    NiUpdateData() : fTime(0.0f), bUpdateControllers(false), bIsMultiThreaded(false),
        bUpdateProperties(false), bUpdateShaders(false), bUpdateCollision(false) {}
};

struct NiLightAE2 : NiRefObject
{
    int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    unsigned int m_uiFlags;
    void Update(NiUpdateData& data);
};

struct ShadowLightAE2
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4;
    NiLightAE2* m_pLight;
    int unk0fc; int unk100; int unk104; int unk108; int unk10c;
    unsigned short m_usIndex;
    void Render(int arg, int n);
    void Deactivate();
};

struct ShadowRenderTargetAE2 : NiRefObject
{
    static void* operator new(unsigned int size);
    ShadowRenderTargetAE2(int arg);
    int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110;
    int unk114;
    int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c;
    NiPointer<NiRefObject> sp130;
    int unk134; int unk138; int unk13c;
};

struct RenderHelperAE2
{
    void SetTarget(int a, int b);
};
extern RenderHelperAE2 g_renderHelper;
extern ShadowLightAE2* g_pCurrentShadowLight;

struct ShadowSceneNodeAE2
{
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    NiTListItem<ShadowLightAE2*>* m_pShadowHead;
    int unk0c4;
    unsigned int m_uiShadowCount;
    int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124;
    NiPointer<ShadowRenderTargetAE2> m_spReferencedObject;
    void FUN_00ae2130(int arg);
    ShadowLightAE2* GetNext(NiTListItem<ShadowLightAE2*>*& pos) const
    {
        ShadowLightAE2** elem = &pos->m_element;
        pos = pos->m_pkNext;
        return *elem;
    }
};

// pdb: ShadowSceneNode::UpdateDynamicShadows | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, low
// pdb params: arCuller
void ShadowSceneNodeAE2::FUN_00ae2130(int arg)
{
    AutoMemContext ctx(0x20);
    if (!m_spReferencedObject)
    {
        m_spReferencedObject = new ShadowRenderTargetAE2(0);
    }
    m_spReferencedObject->unk114 = 0;
    if (m_uiShadowCount)
    {
        int n = 0;
        NiTListItem<ShadowLightAE2*>* pos = m_pShadowHead;
        while (pos)
        {
            ShadowLightAE2* light = GetNext(pos);
            if (light && light->m_pLight)
            {
                if (!(light->m_pLight->m_uiFlags & 1))
                {
                    NiUpdateData data;
                    light->m_pLight->Update(data);
                    if (light->m_usIndex != 0xff)
                    {
                        g_pCurrentShadowLight = light;
                        light->Render(arg, n);
                        n++;
                    }
                }
                else
                {
                    light->Deactivate();
                }
            }
        }
        for (int i = n + 0x11; i < 0x15; i++)
            g_renderHelper.SetTarget(1, i);
    }
    m_spReferencedObject->sp130 = 0;
}

// @f3 0x00af4760 (community match, verified in this file)
namespace f3m_00af4760 {
extern const char DAT_00dbce24[];
extern const char DAT_00dc0cc8[];
extern const char DAT_00dcad64[];
extern const char DAT_00dd7f00[];
extern const char DAT_00e2f46c[];
extern const char DAT_00e95430[];
extern const char DAT_00e9544c[];
extern const char DAT_00e95504[];
extern const char DAT_00e95588[];
extern const char DAT_00e95594[];
extern const char DAT_00e955a0[];
extern const char DAT_00e955ac[];
extern const char DAT_00e955cc[];
extern const char DAT_00e955f0[];
extern const char DAT_00e956a4[];
extern const char DAT_00e956a8[];
extern const char DAT_00e956e4[];
extern const char DAT_00e956f0[];
extern const char DAT_00e956fc[];
extern const char DAT_00e9570c[];
extern const char DAT_00e95748[];
extern const char DAT_00e95750[];
extern const char DAT_00e9575c[];
extern const char DAT_00e9577c[];
extern const char DAT_00e957a0[];
extern const char DAT_00e957c0[];
extern const char DAT_00e957e0[];
struct ShaderMacro { const char* Name; const char* Definition; };
struct ShaderDefinition { const char* file; ShaderMacro macros[9]; };
struct ShaderObject {
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
extern NiPointer<ShaderObject> DAT_01173b08[31];
extern NiPointer<ShaderObject> DAT_01173b84[22];
extern NiPointer<ShaderObject> DAT_01173bdc[103];
extern int DAT_0116efb0;
void __cdecl BuildShaderPath(const char*, char*);
int __cdecl FUN_00403230(char*, unsigned int, const char*, ...);
struct ShaderOwner {
    ShaderObject* FUN_00b62f60(const char*, const ShaderMacro*, const char*, const char*);
    void FUN_00af4760();
};
// pdb: ShadowLightShader::LoadVertexShaders | ShadowLightShader.obj | fnv360_0822_retail, ustr, medium
void ShaderOwner::FUN_00af4760() {
    ShaderDefinition base[31] = {
        { "lighting\\1x\\v\\base.v.hlsl", 0 },
        { 0, 0 },
        { 0, 0 },
        { "lighting\\1x\\v\\diffusePt.v.hlsl", 0 },
        { "lighting\\1x\\v\\diffuseDir.v.hlsl", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "VC", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "FACEGENBLEND", "", 0 },
        { "lighting\\1x\\v\\specularPt.v.hlsl", 0 },
        { "lighting\\1x\\v\\specularDir.v.hlsl", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "FOG", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "VC", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "FOG", "", "VC", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "FACEGENBLEND", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "FACEGENBLEND", "", "FOG", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "FOG", "", DAT_00e957e0, "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "FOG", "", "TEX", "", 0 },
        { DAT_00e957c0, 0 },
        { DAT_00e957a0, 0 },
        { DAT_00e957a0, "VC", "", 0 },
        { DAT_00e9577c, 0 },
        { DAT_00e9577c, "VC", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SI", "", 0 },
        { DAT_00e9575c, 0 },
        { DAT_00e9575c, DAT_00e95750, "", 0 },
        { DAT_00e9575c, DAT_00e95750, "", "SI", "", 0 },
        { DAT_00e9575c, DAT_00e95748, "", 0 },
        { DAT_00e9575c, DAT_00e95750, "", DAT_00e95748, "", 0 },
        { 0, 0 },
    };
    ShaderDefinition extended[22] = {
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", "FOG", "", DAT_00e957e0, "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", "FOG", "", "TEX", "", 0 },
        { "lighting\\1x\\v\\diffusePt.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\diffuseDir.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", "VC", "", 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", "FACEGENBLEND", "", 0 },
        { "lighting\\1x\\v\\specularPt.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\specularDir.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", "VC", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", "FOG", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", "FOG", "", "VC", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", "FACEGENBLEND", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", "SKIN", "", "FACEGENBLEND", "", "FOG", "", 0 },
        { "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl", "SKIN", "", 0 },
        { DAT_00e957c0, "SKIN", "", 0 },
        { 0, 0 },
        { 0, 0 },
        { "lighting\\1x\\v\\base.v.hlsl", "SKIN", "", "SI", "", 0 },
        { 0, 0 },
    };
    ShaderDefinition advanced[103] = {
        { "lighting\\2x\\v\\ADTS.v.hlsl", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", DAT_00dd7f00, "", 0 },
        { DAT_00e9570c, DAT_00e956fc, "", DAT_00e956f0, "", DAT_00e956e4, "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "PROJ_SHADOW", "", 0 },
        { DAT_00e9570c, DAT_00e956fc, "", "PROJ_SHADOW", "", DAT_00e956f0, "", DAT_00e956e4, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", DAT_00dcad64, "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "LIGHTS", "2", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "LIGHTS", "2", "SKIN", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "LIGHTS", "2", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "LIGHTS", "2", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "SKIN", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "LIGHTS", "2", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "LIGHTS", "2", "SKIN", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "LIGHTS", "2", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\ADTS.v.hlsl", "SPECULAR", "", "LIGHTS", "2", "SKIN", "", "PROJ_SHADOW", "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { DAT_00e956a8, "LIGHTS", "9", 0 },
        { DAT_00e956a8, "LIGHTS", "9", "SKIN", "", 0 },
        { DAT_00e956a8, "LIGHTS", "4", 0 },
        { DAT_00e956a8, DAT_00e956a4, "", "LIGHTS", "4", 0 },
        { DAT_00e956a8, "LIGHTS", "4", "SKIN", "", 0 },
        { DAT_00e956a8, "SPECULAR", "", "LIGHTS", "4", 0 },
        { DAT_00e956a8, DAT_00e956a4, "", "SPECULAR", "", "LIGHTS", "4", 0 },
        { DAT_00e956a8, "SPECULAR", "", "LIGHTS", "4", "SKIN", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "2", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "2", "SKIN", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "2", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "2", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "3", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "3", "SKIN", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "3", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\AD.v.hlsl", "LIGHTS", "3", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\DiffusePt.v.hlsl", "LIGHTS", "2", 0 },
        { "lighting\\2x\\v\\DiffusePt.v.hlsl", "LIGHTS", "2", "SKIN", "", 0 },
        { "lighting\\2x\\v\\DiffusePt.v.hlsl", "LIGHTS", "3", 0 },
        { "lighting\\2x\\v\\DiffusePt.v.hlsl", "LIGHTS", "3", "SKIN", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "SKIN", "", "PROJ_SHADOW", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "POINT", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "SKIN", "", "POINT", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "NUM_PT_LIGHTS", "2", "POINT", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "NUM_PT_LIGHTS", "2", "SKIN", "", "POINT", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "NUM_PT_LIGHTS", "3", "POINT", "", 0 },
        { "lighting\\2x\\v\\Specular.v.hlsl", "NUM_PT_LIGHTS", "3", "SKIN", "", "POINT", "", 0 },
        { "lighting\\2x\\v\\EnvMap.v.hlsl", "ENVMAP", "", 0 },
        { "lighting\\2x\\v\\EnvMap.v.hlsl", "SKIN", "", "ENVMAP", "", 0 },
        { "lighting\\2x\\v\\EnvMap.v.hlsl", "ENVMAP", "", "EYE", 0, 0 },
        { DAT_00e955f0, "PROJ_SHADOW", "", 0 },
        { DAT_00e955f0, DAT_00e95750, "", "PROJ_SHADOW", "", 0 },
        { DAT_00e955cc, DAT_00e2f46c, "", DAT_00e95748, "", 0 },
        { DAT_00e955cc, "SPECULAR", "", 0 },
        { 0 },
        { DAT_00e955cc, DAT_00e95750, "", DAT_00e2f46c, "", DAT_00e95748, "", 0 },
        { DAT_00e955cc, DAT_00e95750, "", "SPECULAR", "", 0 },
        { 0 },
        { DAT_00e955cc, "SPECULAR", "", "PROJ_SHADOW", "", 0 },
        { DAT_00e955cc, DAT_00e95750, "", "SPECULAR", "", "PROJ_SHADOW", "", 0 },
        { DAT_00e955ac, DAT_00e955a0, "", 0 },
        { DAT_00e955ac, DAT_00e955a0, "", DAT_00e95594, "", 0 },
        { DAT_00e955ac, DAT_00e955a0, "", "SKIN", "", 0 },
        { DAT_00e955ac, DAT_00e955a0, "", "SKIN", "", DAT_00e95594, "", 0 },
        { DAT_00e955ac, DAT_00e955a0, "", DAT_00e95588, "", 0 },
        { "lighting\\2x\\v\\renderNormals.v.hlsl", 0 },
        { "lighting\\2x\\v\\renderNormals.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\renderNormals.v.hlsl", "FIRE", "", 0 },
        { "lighting\\2x\\v\\renderNormals.v.hlsl", "CLEAR", "", 0 },
        { "lighting\\2x\\v\\renderNormals.v.hlsl", "CLEAR", "", "SKIN", "", 0 },
        { "lighting\\2x\\v\\renderDepth.v.hlsl", 0 },
        { "lighting\\2x\\v\\renderDepth.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\renderDepth.v.hlsl", DAT_00e956fc, "", 0 },
        { "lighting\\2x\\v\\renderVelocity.v.hlsl", 0 },
        { "lighting\\2x\\v\\renderVelocity.v.hlsl", "SKIN", "", 0 },
        { DAT_00e955f0, 0 },
        { DAT_00e955f0, DAT_00e95750, "", 0 },
        { DAT_00e955f0, DAT_00e95504, "", "FOG", "", 0 },
        { DAT_00e955f0, DAT_00e95750, "", "SI", "", 0 },
        { DAT_00e955f0, DAT_00e95748, "", 0 },
        { DAT_00e955f0, DAT_00e95750, "", DAT_00e95748, "", 0 },
        { "lighting\\2x\\v\\localMap.v.hlsl", 0 },
        { "lighting\\2x\\v\\localMap.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\localMap.v.hlsl", "CLEAR", "", 0 },
        { "lighting\\1x\\v\\texEffect.v.hlsl", 0 },
        { "lighting\\1x\\v\\texEffect.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\SimpleShadow.v.hlsl", "SHADOWMAP", "", 0 },
        { "lighting\\2x\\v\\SimpleShadow.v.hlsl", "SHADOWMAP", "", "SKIN", "", 0 },
        { "lighting\\2x\\v\\SimpleShadow.v.hlsl", "SHADOWMAP", "", DAT_00dbce24, "", "VC", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "SKIN", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "TEXCOORD", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "SKIN", "", "TEXCOORD", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "VC", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "VC", "", "SKIN", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "VC", "", "TEXCOORD", "", 0 },
        { "lighting\\2x\\v\\WaterFog.v.hlsl", "VC", "", "SKIN", "", "TEXCOORD", "", 0 },
        { DAT_00e9544c, "FOG", "", 0 },
        { DAT_00e9544c, "FOG", "", "PROJ_SHADOW", "", 0 },
        { DAT_00e95430, "LIGHTS", DAT_00dc0cc8, 0 },
    };
    char path[260];
    char shaderName[260];
    for (int i=0; i<31; ++i) {
        if (base[i].file) {
            BuildShaderPath(base[i].file,path);
            FUN_00403230(shaderName,260,"SLS1%03i.vso",i);
            DAT_01173b08[i] = FUN_00b62f60(path,base[i].macros,"vs_2_0",shaderName);
        }
    }
    for (int i=0; i<22; ++i) {
        if (extended[i].file) {
            BuildShaderPath(extended[i].file,path);
            FUN_00403230(shaderName,260,"SLS1S%03i.vso",i);
            DAT_01173b84[i] = FUN_00b62f60(path,extended[i].macros,"vs_2_0",shaderName);
        }
    }
    if (DAT_0116efb0>=2) {
        for (int i=0; i<103; ++i) {
            if (!advanced[i].file) {
                DAT_01173bdc[i] = 0;
            } else {
                BuildShaderPath(advanced[i].file,path);
                FUN_00403230(shaderName,260,"SLS2%03i.vso",i);
                DAT_01173bdc[i] = FUN_00b62f60(path,advanced[i].macros,"vs_2_0",shaderName);
            }
        }
    }
}
}   // namespace f3m_00af4760

// @f3 0x00ae3160 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*,long,long);

namespace NativeAE3160 {

struct SpinLock { volatile long owner; long count; void FUN_00409a80(int); void Unlock(){if(--count==0){long old=owner;InterlockedCompareExchange(&owner,0,old);}} };
extern SpinLock DAT_0116fc80;
struct RTTI{const char* name;RTTI* parent;};extern RTTI DAT_0108f468,DAT_0108f498;

struct Light{virtual void v0();virtual void v4();virtual const RTTI* GetRTTI()const;bool Is(const RTTI* t)const{return GetRTTI()==t;}static bool Is(const RTTI* t,const Light* p){if(!p)return false;return p->Is(t);}};



void* FUN_0089eb90(unsigned);void FUN_0089ebd0(void*);

struct FUN_00b21da0{virtual void v0();virtual void DeleteThis();volatile long refs;void IncRefCount(){InterlockedIncrement(&refs);}long DecRefCount(){return InterlockedDecrement(&refs);}

int unk8;int unkc;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;int unka0;int unka4;int unka8;int unkac;int unkb0;int unkb4;int unkb8;int unkbc;int unkc0;int unkc4;int unkc8;int unkcc;int unkd0;int unkd4;int unkd8;int unkdc;int unke0;int unke4;int unke8;int unkec;int unkf0;int unkf4;int unkf8;bool flagFC;

int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;int unk12c;int unk130;int unk134;int unk138;int unk13c;int unk140;int unk144;int unk148;int unk14c;int unk150;int unk154;int unk158;int unk15c;int unk160;int unk164;int unk168;int unk16c;int unk170;int unk174;int unk178;int unk17c;int unk180;int unk184;int unk188;int unk18c;int unk190;int unk194;int unk198;int unk19c;int unk1a0;int unk1a4;int unk1a8;int unk1ac;int unk1b0;int unk1b4;int unk1b8;int unk1bc;int unk1c0;int unk1c4;int unk1c8;int unk1cc;int unk1d0;int unk1d4;int unk1d8;int unk1dc;int unk1e0;int unk1e4;int unk1e8;int unk1ec;int unk1f0;int unk1f4;int unk1f8;int unk1fc;int unk200;int unk204;int unk208;int unk20c;int unk210;int unk214;int unk218;int unk21c;int unk220;int unk224;int unk228;int unk22c;int unk230;int unk234;int unk238;int unk23c;unsigned value240;void SetValue(unsigned value){value240=value;}int unk244,unk248,unk24c;FUN_00b21da0();void FUN_00b20120(Light*);static void* operator new(unsigned n)throw(){return FUN_0089eb90(n);}static void operator delete(void* p){FUN_0089ebd0(p);}};

struct Node{

int unk0;int unk4;int unk8;int unkc;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c;int unk30;int unk34;int unk38;int unk3c;int unk40;int unk44;int unk48;int unk4c;int unk50;int unk54;int unk58;int unk5c;int unk60;int unk64;int unk68;int unk6c;int unk70;int unk74;int unk78;int unk7c;int unk80;int unk84;int unk88;int unk8c;int unk90;int unk94;int unk98;int unk9c;int unka0;int unka4;int unka8;int unkac;int unkb0;int unkb4;int unkb8;int unkbc;int unkc0;int unkc4;int unkc8;int unkcc;int unkd0;int unkd4;int unkd8;int unkdc;int unke0;PtrList<FUN_00b21da0> lights;int unkf0;int unkf4;int unkf8;int unkfc;int unk100;int unk104;int unk108;int unk10c;int unk110;int unk114;int unk118;int unk11c;int unk120;int unk124;int unk128;int unk12c;int unk130;int unk134;int unk138;int unk13c;int unk140;int unk144;int unk148;int unk14c;int unk150;int unk154;int unk158;int unk15c;int unk160;int unk164;int unk168;int unk16c;int unk170;int unk174;int unk178;int unk17c;int unk180;int unk184;int unk188;int unk18c;int unk190;int unk194;int unk198;int unk19c;int unk1a0;int unk1a4;int unk1a8;int unk1ac;int unk1b0;int unk1b4;int unk1b8;int unk1bc;int unk1c0;int unk1c4;int unk1c8;int unk1cc;int unk1d0;int unk1d4;int unk1d8;int unk1dc;unsigned value1e0;FUN_00b21da0* FUN_00ae3160(Light*,bool);};

// pdb: ShadowSceneNode::AddLight | ShadowSceneNode.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apLight, abDynamic
FUN_00b21da0* Node::FUN_00ae3160(Light* light,bool flag){if(!Light::Is(&DAT_0108f468,light)&&!Light::Is(&DAT_0108f498,light))return 0;DAT_0116fc80.FUN_00409a80(0);FUN_00b21da0* result=new FUN_00b21da0;result->FUN_00b20120(light);result->flagFC=flag;{Ref<FUN_00b21da0> temp(result);lights.FUN_00827100(temp);}result->SetValue(value1e0);DAT_0116fc80.Unlock();return result;}

}

// @f3 0x00ae7350 (community match, verified in this file)
namespace f3m_00ae7350 {
struct Owner00ae7350 {
    int FUN_00ae7350();
};

// pdb: Main::DrawWorld_RestartRenderTexture | Main.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apRenderTexture, abMultiSampleEnabled, auiClearMode
int Owner00ae7350::FUN_00ae7350() {
    unsigned count = *(unsigned*)((char*)this + 0x18c);
    int sum = 0;
    if (count > 0) {
        char** entry = (char**)((char*)this + 0x174);
        do {
            char* node = *entry;
            char* sub = *(char**)(node + 0x54);
            sum += *(unsigned short*)(sub + 2);
            ++entry;
        } while (--count);
    }
    return sum;
}
}   // namespace f3m_00ae7350

// @f3 0x00af03c0 (community match, verified in this file)
#include <windows.h>
namespace f3m_00af03c0 {
struct ShaderResource {
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
};
struct ShaderOwner {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c;
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90;
    ShaderResource* resource;
    void FUN_00af03c0();
};
// pdb: BSTextureManager::ClearShadowDepthBuffer | BSTextureManager.obj | fnv360_0822_retail, call_seq, low
void ShaderOwner::FUN_00af03c0()
{
    ShaderResource* current = resource;
    if (current) {
        if (!InterlockedDecrement(&current->references))
            current->Destroy();
        resource = 0;
    }
}
}   // namespace f3m_00af03c0

// @f3 0x00aeda10 (community match, verified in this file)
extern const char* DAT_0116fda0;
namespace f3m_00aeda10 {
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
            FUN_00555790(growBy + index);
        FUN_005b3880(index, value);
    }

    void** table;
    char** buffer;
    unsigned short capacity, firstFree, count, growBy;
};

class Owner
{
public:
    void FUN_00b2b9f0(ViewerStrings* strings);
    void FUN_00aeda10(ViewerStrings* strings);
};

// pdb: WaterShaderProperty::GetViewerStrings | WaterShaderProperty.obj | fnv360_0721_beta, objrun, medium
// pdb params: apStrings
void Owner::FUN_00aeda10(ViewerStrings* strings)
{
    FUN_00b2b9f0(strings);
    strings->Add(FUN_00847b50(DAT_0116fda0));
}
}   // namespace f3m_00aeda10

// @f3 0x00ae9b70 (community match, verified in this file)
namespace f3m_00ae9b70 {
struct FUN_00ae9b70_Ref
{
    virtual ~FUN_00ae9b70_Ref();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};

struct FUN_00ae9b70_Ptr
{
    FUN_00ae9b70_Ref* m_pObject;
    FUN_00ae9b70_Ptr& operator=(FUN_00ae9b70_Ref* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

struct FUN_00ae9b70_Arg
{
    FUN_00ae9b70_Ref* FUN_00082a280();
};

struct FUN_00ae9b70_Cls
{
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FUN_00ae9b70_Ptr m_tex;
    void FUN_00af2f20(FUN_00ae9b70_Arg* arg);
    void FUN_00ae9b70(FUN_00ae9b70_Arg* arg);
};

// pdb: BSShaderPPLightingProperty::LinkObject | BSShaderPPLightingProperty.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: kStream
void FUN_00ae9b70_Cls::FUN_00ae9b70(FUN_00ae9b70_Arg* arg)
{
    FUN_00af2f20(arg);
    m_tex = arg->FUN_00082a280();
}
}   // namespace f3m_00ae9b70

// @f3 0x00af1470 (community match, verified in this file)
namespace f3m_00af1470 {
struct W06_RenderManager {
    void FUN_00aef570(unsigned int renderer, unsigned int kind, unsigned int* width, unsigned int* height, unsigned int* format, unsigned int* extra, unsigned int* flags, unsigned int* samples);
    void* FUN_00af09d0(unsigned int renderer, unsigned int width, unsigned int height, unsigned int flags, unsigned int format, unsigned int extra, unsigned int kind, unsigned int samples, int zero, unsigned int last);
    void* FUN_00af1470(unsigned int renderer, unsigned int kind, unsigned int flags, unsigned int noReuse, unsigned int last);
};
void* W06_RenderManager::FUN_00af1470(unsigned int renderer, unsigned int kind, unsigned int flags, unsigned int noReuse, unsigned int last) {
    if (noReuse) return 0;
    unsigned int width, height, format, extra, outFlags, samples;
    FUN_00aef570(renderer, kind, &width, &height, &format, &extra, &outFlags, &samples);
    return FUN_00af09d0(renderer, width, height, outFlags | flags, format, extra, kind, samples, 0, last);
}
}   // namespace f3m_00af1470

// @f3 0x00ae7440 (community match, verified in this file)
namespace f3m_00ae7440 {
struct ListHolder481 {
    unsigned int unk00, unk04;
    FNVPointerListItem* tail;
    FNVPointerListItem* head;
    void FUN_00ae7440();
};
// pdb: BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::CleanUnusedNodes | BSBatchRenderer.obj | fnv360_0822_retail, call_seq, medium
void ListHolder481::FUN_00ae7440() {
    FNVPointerListItem* node = head;
    if (node) {
        DAT_0106e5a0.FUN_00409a80(0);
        while (node) {
            FNVPointerListItem* item = node;
            node = item->m_pkNext;
            DAT_0106e5a0.FUN_00409a80(0);
            item->m_pkPrev = 0;
            item->m_pkNext = DAT_0106e588;
            DAT_0106e588 = item;
            if (--DAT_0106e5a4 == 0) {
                long owner = *(long const volatile*)&DAT_0106e5a0.value;
                InterlockedCompareExchange((volatile long*)&DAT_0106e5a0, 0, owner);
            }
        }
        if (--DAT_0106e5a4 == 0) {
            long owner = *(long const volatile*)&DAT_0106e5a0.value;
            InterlockedCompareExchange((volatile long*)&DAT_0106e5a0, 0, owner);
        }
    }
    head = 0;
    if (tail) tail->m_pkNext = 0;
}
}   // namespace f3m_00ae7440

// @f3 0x00ae5870 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace fnv_00b5e870 {
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* Addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);
class NiCullingProcess;
struct Obj4
{
    int m_00;
    int m_04;
};
class Item : public NiRefObject
{
  public:
    float unk008;
    float unk00C;
    float unk010;
    float unk014;
    float unk018;
    float unk01C;
    float unk020;
    float unk024;
    float unk028;
    float unk02C;
    float unk030;
    float unk034;
    float unk038;
    float unk03C;
    float unk040;
    float unk044;
    float unk048;
    float unk04C;
    float unk050;
    float unk054;
    float unk058;
    float unk05C;
    float unk060;
    float unk064;
    float unk068;
    float unk06C;
    float unk070;
    float unk074;
    float unk078;
    float unk07C;
    float unk080;
    float unk084;
    float unk088;
    float unk08C;
    float unk090;
    float unk094;
    float unk098;
    float unk09C;
    float unk0A0;
    float unk0A4;
    float unk0A8;
    float unk0AC;
    float unk0B0;
    float unk0B4;
    float unk0B8;
    float unk0BC;
    float unk0C0;
    float unk0C4;
    float unk0C8;
    float unk0CC;
    float unk0D0;
    float unk0D4;
    float unk0D8;
    float unk0DC;
    float unk0E0;
    float unk0E4;
    float unk0E8;
    char m_flagEC;
    char unk0ED;
    char unk0EE;
    char unk0EF;
    char unk0F0;
    char unk0F1;
    char unk0F2;
    char unk0F3;
    char unk0F4;
    char unk0F5;
    char unk0F6;
    char unk0F7;
    Obj4* m_f8;
    char m_flagFC;
    char unkFD, unkFE, unkFF;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    struct GeometryLinks** objects;
    unsigned int objectCount;
    unsigned int unk21C;
    unsigned int unk220;
    struct LinkedLight** linkedLights;
    unsigned int linkedLightCount;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    int m_240;
    void FUN_00b20b40(void* arg);
};
typedef NiPointer<Item> RefPtr_b9fcc0;
struct FirstOwner
{
    Item* m_pObject;
    FirstOwner(Item* p) : m_pObject(p)
    {
        if (p)
            p->IncRefCount();
    }
    ~FirstOwner()
    {
        Item* p = m_pObject;
        if (p)
        {
            // Fake match: the named copy q2 and the barrier only steer VS2005's
            // register choice (load of m_pObject into esi) and let the EH-state
            // store sink past the null test; they emit no code themselves.
            Item* q2 = p;
            _ReadWriteBarrier();
            q2->DecRefCount();
        }
    }
};
struct Node
{
    Node* m_next;
    Node* m_pSecondNode;
    RefPtr_b9fcc0 m_light;
};
class List_b9fcc0
{
  public:
    Node* m_pFirstNode;
    Node* m_pTail;
    unsigned int m_uiItemCount;
    RefPtr_b9fcc0& GetNext(void*& pos)
    {
        RefPtr_b9fcc0& result = static_cast<Node*>(pos)->m_light;
        pos = static_cast<Node*>(pos)->m_next;
        return result;
    }
    RefPtr_b9fcc0 FUN_00af0700(const FirstOwner& r);
    __declspec(noinline) RefPtr_b9fcc0 FUN_00ab43e0(void*& p);
    RefPtr_b9fcc0 PopFront();
    RefPtr_b9fcc0 PopBack();
    void ReleaseRefCountedNode(Node* node);
};
struct Vec3f
{
    float x, y, z;
};
struct MatObj
{
    float unk000;
    float unk004;
    float unk008;
    float unk00C;
    float unk010;
    float unk014;
    float unk018;
    float unk01C;
    float unk020;
    float unk024;
    float unk028;
    float unk02C;
    float unk030;
    float unk034;
    float unk038;
    float unk03C;
    float unk040;
    float unk044;
    float unk048;
    float unk04C;
    float unk050;
    float unk054;
    float unk058;
    float unk05C;
    float unk060;
    float unk064;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    float m_80;
    float m_84;
    float m_88;
    Vec3f m_vContactPosition;
};
class ParamObj
{
  public:
    void FUN_00aad400();
    int m_00;
    int m_04;
    int m_08;
    MatObj* m_0c;
};
struct Obj134
{
    float unk000;
    float unk004;
    float unk008;
    float unk00C;
    float unk010;
    float unk014;
    float unk018;
    float unk01C;
    Vec3f m_kDiffuseColor;
    float m_2c;
    float m_30;
    float unk034;
    float unk038;
    float unk03C;
    float unk040;
    float unk044;
    float unk048;
    float unk04C;
    float unk050;
    float unk054;
    float unk058;
    float unk05C;
    float m_60;
};
char __cdecl FUN_00530bb0();
struct Vec4f
{
    float x, y, z;
    union
    {
        float w;
        unsigned bitsW;
    };
    Vec4f()
    {}
    void Set(const Vec3f& v, float fourth)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = fourth;
    }
};
extern int DAT_0116efb0;
extern unsigned char DAT_0116efb4;
extern void* DAT_0116ef6c;
extern unsigned char DAT_0116ef97;
extern int DAT_01067ba4;
extern int DAT_0116efc8;
extern float DAT_01067b64;
extern Vec4f DAT_01170020;
extern Vec4f DAT_01170030;
extern Vec4f DAT_01170040;
extern Vec4f DAT_01170000;
extern Vec4f DAT_01170010;
extern float DAT_01176284;
extern float DAT_01176280;
extern float DAT_011762d8;
struct LinkArray
{
    virtual void v0();
    unsigned int* data;
    unsigned int count, capacity;
    unsigned int FindFirstMatch(const RefPtr_b9fcc0*, unsigned int, int(__cdecl*)(int*, int*));
    void FUN_00b5ade0(unsigned int, bool);
};
struct GeometryLinks
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    LinkArray objects;
};
struct LinkedLightData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    LinkArray links;
};
struct LinkedLight
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    LinkedLightData* data;
};
struct LightContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int count;
};
extern int __cdecl FUN_00b5a980(int*, int*);
class Self
{
  public:
    char unk000;
    char unk001;
    char unk002;
    char unk003;
    char unk004;
    char unk005;
    char unk006;
    char unk007;
    char unk008;
    char unk009;
    char unk00A;
    char unk00B;
    char unk00C;
    char unk00D;
    char unk00E;
    char unk00F;
    char unk010;
    char unk011;
    char unk012;
    char unk013;
    char unk014;
    char unk015;
    char unk016;
    char unk017;
    char unk018;
    char unk019;
    char unk01A;
    char unk01B;
    char unk01C;
    char unk01D;
    char unk01E;
    char unk01F;
    char unk020;
    char unk021;
    char unk022;
    char unk023;
    char unk024;
    char unk025;
    char unk026;
    char unk027;
    char unk028;
    char unk029;
    char unk02A;
    char unk02B;
    char unk02C;
    char unk02D;
    char unk02E;
    char unk02F;
    char unk030;
    char unk031;
    char unk032;
    char unk033;
    char unk034;
    char unk035;
    char unk036;
    char unk037;
    char unk038;
    char unk039;
    char unk03A;
    char unk03B;
    char unk03C;
    char unk03D;
    char unk03E;
    char unk03F;
    char unk040;
    char unk041;
    char unk042;
    char unk043;
    char unk044;
    char unk045;
    char unk046;
    char unk047;
    char unk048;
    char unk049;
    char unk04A;
    char unk04B;
    char unk04C;
    char unk04D;
    char unk04E;
    char unk04F;
    char unk050;
    char unk051;
    char unk052;
    char unk053;
    char unk054;
    char unk055;
    char unk056;
    char unk057;
    char unk058;
    char unk059;
    char unk05A;
    char unk05B;
    char unk05C;
    char unk05D;
    char unk05E;
    char unk05F;
    char unk060;
    char unk061;
    char unk062;
    char unk063;
    char unk064;
    char unk065;
    char unk066;
    char unk067;
    char unk068;
    char unk069;
    char unk06A;
    char unk06B;
    char unk06C;
    char unk06D;
    char unk06E;
    char unk06F;
    char unk070;
    char unk071;
    char unk072;
    char unk073;
    char unk074;
    char unk075;
    char unk076;
    char unk077;
    char unk078;
    char unk079;
    char unk07A;
    char unk07B;
    char unk07C;
    char unk07D;
    char unk07E;
    char unk07F;
    char unk080;
    char unk081;
    char unk082;
    char unk083;
    char unk084;
    char unk085;
    char unk086;
    char unk087;
    char unk088;
    char unk089;
    char unk08A;
    char unk08B;
    char unk08C;
    char unk08D;
    char unk08E;
    char unk08F;
    char unk090;
    char unk091;
    char unk092;
    char unk093;
    char unk094;
    char unk095;
    char unk096;
    char unk097;
    char unk098;
    char unk099;
    char unk09A;
    char unk09B;
    char unk09C;
    char unk09D;
    char unk09E;
    char unk09F;
    char unk0A0;
    char unk0A1;
    char unk0A2;
    char unk0A3;
    char unk0A4;
    char unk0A5;
    char unk0A6;
    char unk0A7;
    char unk0A8;
    char unk0A9;
    char unk0AA;
    char unk0AB;
    char unk0AC;
    char unk0AD;
    char unk0AE;
    char unk0AF;
    char unk0B0;
    char unk0B1;
    char unk0B2;
    char unk0B3;
    List_b9fcc0 m_listB4;
    List_b9fcc0 m_listC0;
    char unk0CC;
    char unk0CD;
    char unk0CE;
    char unk0CF;
    char unk0D0;
    char unk0D1;
    char unk0D2;
    char unk0D3;
    char unk0D4;
    char unk0D5;
    char unk0D6;
    char unk0D7;
    char unk0D8;
    char unk0D9;
    char unk0DA;
    char unk0DB;
    char unk0DC;
    char unk0DD;
    char unk0DE;
    char unk0DF;
    char unk0E0;
    char unk0E1;
    char unk0E2;
    char unk0E3;
    char unk0E4;
    char unk0E5;
    char unk0E6;
    char unk0E7;
    char unk0E8;
    char unk0E9;
    char unk0EA;
    char unk0EB;
    char unk0EC;
    char unk0ED;
    char unk0EE;
    char unk0EF;
    char unk0F0;
    char unk0F1;
    char unk0F2;
    char unk0F3;
    char unk0F4;
    char unk0F5;
    char unk0F6;
    char unk0F7;
    char unk0F8;
    char unk0F9;
    char unk0FA;
    char unk0FB;
    char unk0FC;
    char unk0FD;
    char unk0FE;
    char unk0FF;
    char unk100;
    char unk101;
    char unk102;
    char unk103;
    char unk104;
    char unk105;
    char unk106;
    char unk107;
    char unk108;
    char unk109;
    char unk10A;
    char unk10B;
    char unk10C;
    char unk10D;
    char unk10E;
    char unk10F;
    char unk110;
    char unk111;
    char unk112;
    char unk113;
    char unk114;
    char unk115;
    char unk116;
    char unk117;
    char unk118;
    char unk119;
    char unk11A;
    char unk11B;
    char unk11C;
    char unk11D;
    char unk11E;
    char unk11F;
    char m_120;
    char unk121;
    char unk122;
    char unk123;
    char unk124;
    char unk125;
    char unk126;
    char unk127;
    char unk128;
    char unk129;
    char unk12A;
    char unk12B;
    char unk12C;
    char unk12D;
    char unk12E;
    char unk12F;
    char m_130;
    char unk131;
    char unk132;
    char unk133;
    Obj134* m_134;
    char unk138;
    char unk139;
    char unk13A;
    char unk13B;
    char unk13C;
    char unk13D;
    char unk13E;
    char unk13F;
    char unk140;
    char unk141;
    char unk142;
    char unk143;
    char unk144;
    char unk145;
    char unk146;
    char unk147;
    char unk148;
    char unk149;
    char unk14A;
    char unk14B;
    char unk14C;
    char unk14D;
    char unk14E;
    char unk14F;
    char unk150;
    char unk151;
    char unk152;
    char unk153;
    char unk154;
    char unk155;
    char unk156;
    char unk157;
    char unk158;
    char unk159;
    char unk15A;
    char unk15B;
    char unk15C;
    char unk15D;
    char unk15E;
    char unk15F;
    char unk160;
    char unk161;
    char unk162;
    char unk163;
    char unk164;
    char unk165;
    char unk166;
    char unk167;
    char unk168;
    char unk169;
    char unk16A;
    char unk16B;
    char unk16C;
    char unk16D;
    char unk16E;
    char unk16F;
    char unk170;
    char unk171;
    char unk172;
    char unk173;
    char unk174;
    char unk175;
    char unk176;
    char unk177;
    char unk178;
    char unk179;
    char unk17A;
    char unk17B;
    char unk17C;
    char unk17D;
    char unk17E;
    char unk17F;
    char unk180;
    char unk181;
    char unk182;
    char unk183;
    char unk184;
    char unk185;
    char unk186;
    char unk187;
    char unk188;
    char unk189;
    char unk18A;
    char unk18B;
    char unk18C;
    char unk18D;
    char unk18E;
    char unk18F;
    char unk190;
    char unk191;
    char unk192;
    char unk193;
    char unk194;
    char unk195;
    char unk196;
    char unk197;
    char unk198;
    char unk199;
    char unk19A;
    char unk19B;
    char unk19C;
    char unk19D;
    char unk19E;
    char unk19F;
    char unk1A0;
    char unk1A1;
    char unk1A2;
    char unk1A3;
    char unk1A4;
    char unk1A5;
    char unk1A6;
    char unk1A7;
    char unk1A8;
    char unk1A9;
    char unk1AA;
    char unk1AB;
    char unk1AC;
    char unk1AD;
    char unk1AE;
    char unk1AF;
    char unk1B0;
    char unk1B1;
    char unk1B2;
    char unk1B3;
    char unk1B4;
    char unk1B5;
    char unk1B6;
    char unk1B7;
    char unk1B8;
    char unk1B9;
    char unk1BA;
    char unk1BB;
    char unk1BC;
    char unk1BD;
    char unk1BE;
    char unk1BF;
    char unk1C0;
    char unk1C1;
    char unk1C2;
    char unk1C3;
    char unk1C4;
    char unk1C5;
    char unk1C6;
    char unk1C7;
    char unk1C8;
    char unk1C9;
    char unk1CA;
    char unk1CB;
    char unk1CC;
    char unk1CD;
    char unk1CE;
    char unk1CF;
    char unk1D0;
    char unk1D1;
    char unk1D2;
    char unk1D3;
    char unk1D4;
    char unk1D5;
    char unk1D6;
    char unk1D7;
    char unk1D8;
    char unk1D9;
    char unk1DA;
    char unk1DB;
    char unk1DC;
    char unk1DD;
    char unk1DE;
    char unk1DF;
    int m_1e0;
    __declspec(noinline) void FUN_00ae3860(RefPtr_b9fcc0& a, void*& b);
    void FUN_00ae4100(Item* item);
    unsigned int FUN_0082d9f0(void* p);
    unsigned int FUN_00ae5870(ParamObj* arg);
};
__declspec(noinline) RefPtr_b9fcc0 List_b9fcc0::FUN_00ab43e0(void*& p)
{
    Node* node = static_cast<Node*>(p);
    if (node == m_pFirstNode)
    {
        p = node->m_next;
        return PopFront();
    }
    if (node == m_pTail)
    {
        p = 0;
        return PopBack();
    }
    Node* previous = node->m_pSecondNode;
    Node* next = node->m_next;
    p = next;
    if (previous)
        previous->m_next = next;
    if (next)
        next->m_pSecondNode = previous;
    RefPtr_b9fcc0 item = node->m_light;
    ReleaseRefCountedNode(node);
    --m_uiItemCount;
    return item;
}
__declspec(noinline) void Self::FUN_00ae3860(RefPtr_b9fcc0& value, void*& position)
{
    LightContext* context = reinterpret_cast<LightContext*>(m_1e0);
    Item* item = value;
    if (context && context->count)
    {
        for (unsigned int i = 0; i < item->objectCount; ++i)
        {
            GeometryLinks* geometry = item->objects[i];
            if (geometry && geometry->objects.count)
            {
                unsigned int index = geometry->objects.FindFirstMatch(&value, 0, FUN_00b5a980);
                if (index != ~0u)
                    geometry->objects.FUN_00b5ade0(index, true);
            }
            item = value;
        }
        for (unsigned int i = 0; i < item->linkedLightCount; ++i)
        {
            LinkedLight* light = item->linkedLights[i];
            if (light && light->data->links.count)
            {
                LinkedLightData* data = light->data;
                unsigned int index = ~0u;
                for (unsigned int j = 0; j < data->links.count; ++j)
                {
                    if (data->links.data && data->links.data[j] == reinterpret_cast<unsigned int>(item))
                    {
                        index = j;
                        break;
                    }
                }
                if (index != ~0u)
                    data->links.FUN_00b5ade0(index, true);
            }
            item = value;
        }
    }
    if (item->m_flagEC)
        m_listC0.FUN_00ab43e0(position);
    else
        m_listB4.FUN_00ab43e0(position);
}
// pdb: ShadowSceneNode::PreOnVisible | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, low
// pdb params: arCuller
unsigned int Self::FUN_00ae5870(ParamObj* arg)
{
    arg->FUN_00aad400();
    MatObj& own = *arg->m_0c;
    if (!m_130)
    {
        void* y = m_listB4.m_pFirstNode;
        while (y)
        {
            void* v = y;
            Item* idx = m_listB4.GetNext(y);
            if (idx)
            {
                if (idx->m_f8 && idx->m_f8->m_04 != 1)
                {
                    if (idx->m_flagFC)
                        FUN_00ae4100(idx);
                    if (!idx->m_flagEC || !FUN_00530bb0())
                        idx->FUN_00b20b40(arg);
                }
                else
                {
                    int id = idx->m_240;
                    int c;
                    c = m_1e0;
                    if (id != c)
                    {
                        if (idx->m_flagEC)
                        {
                            FirstOwner q(idx);
                            m_listC0.FUN_00af0700(q);
                        }
                        else
                        {
                            m_listB4.FUN_00ab43e0(v);
                        }
                    }
                    else
                    {
                        RefPtr_b9fcc0 q(idx);
                        FUN_00ae3860(q, v);
                    }
                }
            }
        }
    }
    DAT_0116efb4 = (unsigned char)m_120;
    DAT_0116ef6c = &own;
    if (DAT_0116efb0 == 0)
    {
        return FUN_0082d9f0(arg);
    }
    if (1 == DAT_0116ef97)
    {
        if (DAT_01067ba4 == -1)
            DAT_01067ba4 = DAT_0116efc8;
        DAT_0116efc8 = 4;
    }
    else
    {
        unsigned long pForm;
        pForm = DAT_01067ba4;
        if (pForm != -1)
        {
            DAT_0116efc8 = pForm;
            DAT_01067ba4 = -1;
        }
    }
    Vec3f ptr;
    ptr = own.m_vContactPosition;
    Vec4f n;
    n.Set(ptr, 0.0f);
    DAT_01170020 = n;
    ptr.x = own.m_68;
    ptr.y = own.m_74;
    ptr.z = own.m_80;
    n.Set(ptr, 0.0f);
    DAT_01170030 = n;
    ptr.x = own.m_70;
    ptr.y = own.m_7c;
    ptr.z = own.m_88;
    n.Set(ptr, 0.0f);
    DAT_01170040 = n;
    Obj134* val;
    val = m_134;
    unsigned result = reinterpret_cast<unsigned>(val);
    if (val)
    {
        ptr = val->m_kDiffuseColor;
        float pObj;
        pObj = val->m_30;
        n.x = pObj;
        n.y = pObj - val->m_2c;
        n.z = val->m_60;
        n.w = 0.0f;
        DAT_01170000 = n;
        n.Set(ptr, 0.0f);
        DAT_01170010 = n;
        result = n.bitsW;
    }
    DAT_011762d8 = DAT_01176280 + (DAT_01176284 - DAT_01176280) * DAT_01067b64;
    return result;
}
}  // namespace fnv_00b5e870

// @f3 0x00afeeb0 (community match, verified in this file)
namespace f3m_00afeeb0 {
// Model of FUN_00afeeb0 (114 bytes; symbol is undecorated here but this project reconstructs such entries as member
// functions - the prelude itself does that for verified bodies, e.g. void Obj::FUN_00a7def0()).
// Their shape: push ebx/ebp/esi/edi ; eax=2 ; edx=&dword_11749B4 ; edi=eax+9 ; loop 10 times reading the pointer pair at
// [edx-4] and [edx]; for each non-null pointer store (flagWord[index] & mask)!=0 into byte offset +8, with masks
// 1<<(eax-1) then 1<<eax while eax grows by 2 and edx by 8; finally load the member pointer at this+0x30 and tail-call
// its vtable entry at +0x24 (mov ecx,[ebp+30h] ; mov edx,[ecx] ; mov eax,[edx+24h] ; jmp eax).

struct FlagTarget {                 // their write is mov [esi+8], cl - one byte at offset 8 ??
    char pad[8];
    unsigned char flag;
};

extern void* DAT_011749b4;          // middle of the pointer pair table: [edx-4] and [edx] are read per row, stride 8 ??
extern unsigned DAT_0116efd4;       // mov ecx, dword_116EFD4 - index into the flag word array ??
extern unsigned DAT_01171e20[];     // test dword_1171E20[ecx*4], ebx ??

struct FlaggedChild {               // object reached through this+0x30; its virtual at vtable offset +0x24 is tail-called
    virtual ~FlaggedChild();        // VC8 reserves the two destructor slots, so declared methods start at +0x08 ??
    virtual void vf00();             // +0x08
    virtual void vf01();             // +0x0c
    virtual void vf02();             // +0x10
    virtual void vf03();             // +0x14
    virtual void vf04();             // +0x18
    virtual void vf05();             // +0x1c
    virtual void vf06();             // +0x20
    virtual void vf07();             // +0x20 - their build gives the virtual destructor a single vtable slot, so seven methods precede the target one
    virtual void updateFlags();      // +0x24 - the tenth vtable entry (index 9), which is the slot their tail call loads, exactly the slot their tail call loads ??
};

struct OwnerAe {                    // receiver: only the member at +0x30 is ever touched here
    char pad[0x30];
    FlaggedChild* child;            // ORIG: mov ecx, [ebp+30h] ??
    void FUN_00afeeb0();
};

// pdb: ShadowLightShader::SetSpecularMap | ShadowLightShader.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: ShadowLightShader::SetEnvironmentMaskMap)
// pdb params: pprop, auiStage, auiIndex, abUseDefaultOnNULL
void OwnerAe::FUN_00afeeb0() {                          // v2: two independent induction variables and a bottom-tested countdown, as their loop shows ??
    FlagTarget** pairSlot = (FlagTarget**)&DAT_011749b4;   // ORIG: mov edx, offset dword_11749B4 ; then [edx-4] and [edx] per row, add edx,8 each pass ??
    int bitBase = 2;                                       // ORIG: mov eax, 2 ; add eax,2 each pass (the shift amount is not derived from the row counter) ??
    int rows = 11;                                         // ORIG: lea edi,[eax+9] with eax=2 is 11, and sub edi,1/jnz at the bottom runs eleven times - eleven pointer pairs ??

    do {
        FlagTarget* first = pairSlot[-1];                  // ORIG: mov esi,[edx-4] ; test esi,esi ; jz ??
        if (first) {
            first->flag = (unsigned char)((DAT_01171e20[DAT_0116efd4] & (1 << (bitBase - 1))) != 0);   // ORIG: lea ecx,[eax-1] ; mov ebx,1 ; shl ebx,cl ; test dword_1171E20[ecx*4],ebx ; setnz cl ; mov [esi+8],cl
        }

        FlagTarget* second = *pairSlot;                    // ORIG: mov esi,[edx] ; test esi,esi ; jz ??
        if (second) {
            second->flag = (unsigned char)((DAT_01171e20[DAT_0116efd4] & (1 << bitBase)) != 0);        // ORIG: mov ecx,eax ; mov ebx,1 ; shl ebx,cl ; test ... ; setnz cl ; mov [esi+8],cl
        }

        ++bitBase;                                         // ORIG: add eax,2 - written as two single steps so the shift pair is (bitBase-1, bitBase) ??
        ++bitBase;
        pairSlot += 2;                                     // ORIG: add edx,8 ??
    } while (--rows);                                      // ORIG: sub edi,1 ; jnz short loop head ??

    child->updateFlags();                                  // ORIG: mov ecx,[ebp+30h] ; mov edx,[ecx] ; mov eax,[edx+24h] ; jmp eax ??
}

}   // namespace f3m_00afeeb0

// @f3 0x00afcc00 (community match, verified in this file)
namespace Render395 {
struct Texture { int unk00,unk04; bool enabled; };
struct Node {
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
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6c();
virtual Texture* texture(const char*);
};
struct Renderer;
typedef void (__thiscall *BindFn)(Renderer*, Texture*, void*, unsigned int, int, void*);
struct RendererVtbl {
void *s00,*s04,*s08,*s0c,*s10,*s14,*s18,*s1c,*s20,*s24,*s28,*s2c,*s30,*s34,*s38,*s3c,*s40,*s44,*s48,*s4c,*s50,*s54,*s58,*s5c,*s60,*s64,*s68,*s6c,*s70,*s74;
BindFn bind;
};
struct Renderer {
RendererVtbl* vtbl;
};
struct Manager {
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
Renderer* renderer;
};
struct Geometry {
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
void* data;
};
struct Input { int unk00; void* data;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
unsigned short index;
};
struct Service { void FUN_00874f80(Geometry*,void*,int,int,int); };
extern Service* DAT_0116f2f8;
extern Texture* DAT_01174980;
extern Manager* DAT_01091980;
extern const char DAT_00e275bc[];
struct Owner {
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
Node* current;
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
Node* base;
int FUN_00afcc00(int,Geometry*,Input*,int,int,int,void*,int);
};
// pdb: ShadowLightShader::SetupBoneMatrices | ShadowLightShader.obj | fnv360_0822_retail, objrun, medium
// pdb params: apGeometry, apSkin, apPartition, apBuffData, apState, apEffects, aWorld, aWorldBound
int Owner::FUN_00afcc00(int unused,Geometry* geometry,Input* input,int a,int b,int c,void* context,int d) {
 if((input && !unk38 && DAT_01174980 && DAT_01174980->enabled) || current==base) {
  DAT_0116f2f8->FUN_00874f80(geometry,context,0,3,1);
  void* data=geometry->data;
  Node* node=base;
  if(current==node) { Renderer* renderer=DAT_01091980->renderer; BindFn* fn=&renderer->vtbl->bind; (*fn)(renderer,node->texture(DAT_00e275bc),data,input->index,3,input->data); }
  else { Renderer* r=DAT_01091980->renderer; r->vtbl->bind(r,DAT_01174980,data,input->index,3,input->data); }
 }
 return 0;
}
}

// @f3 0x00ae9090 (community match, verified in this file)
#include <string.h>
struct Heap9090 { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern Heap9090 DAT_01090a78;
inline void* __cdecl operator new[](size_t size) { return DAT_01090a78.FUN_0086b930(size); }
extern __declspec(thread) int DAT_0117c2a4;
namespace f3m_00ae9090 {
void* __cdecl FUN_0089e810(unsigned int);   // NiMalloc
void* __cdecl FUN_0089eb90(unsigned int);   // NiNew
struct Base {
    virtual ~Base();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    short unk38; char unk3a, unk3b;
    int unk3c;
    char unk40, unk41, unk42, unk43;
    float unk44;
    Base();
};
struct Data14;
struct Slot {
    Data14* p; char b; float f; int c; int d;
    Slot() { p = 0; b = 0; f = 0.0f; c = 0; d = 0; }
};
struct List {
    void* head; void* tail; unsigned int count;
    List() { count = 0; head = 0; tail = 0; }
    ~List();
    void FUN_00bd12d0();   // RemoveAll
};
struct Elem {
    int unk00, unk04, unk08, unk0c, unk10;
    Elem();
    ~Elem();
};
struct RefObject { virtual void Slot0(); virtual void Delete(); long refs; };
struct Smart {
    RefObject* p;
    Smart(RefObject* q = 0) { p = q; if (p) InterlockedIncrement(&p->refs); }
    ~Smart() { RefObject* old = p; if (old && !InterlockedDecrement(&old->refs)) old->Delete(); }
    void Reset() { RefObject* old = p; if (old) { if (!InterlockedDecrement(&old->refs)) old->Delete(); p = 0; } }
};
struct Color {
    float r, g, b, a;
    Color() { r = 0.0f; g = 0.0f; b = 0.0f; a = 0.0f; }
    Color(float fr, float fg, float fb, float fa) { r = fr; g = fg; b = fb; a = fa; }
};
struct Data170 {
    int unk00;
    Data170();
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Pass98 {
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
    Pass98(int a, void* b);
    virtual void Destroy(int);
    static void* operator new(unsigned int size) { return FUN_0089eb90(size); }
    static void operator delete(void* p);
};
struct ShaderPass {
    int unk00, unk04, unk08, unk0c;
    ShaderPass(void* geometry, unsigned short pass, bool flag, unsigned char b, void* light, ...);
    ~ShaderPass();
};
struct MapBase {
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    MapBase(unsigned int uiHashSize) {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        m_ppkHashTable = (void**)FUN_0089e810(sizeof(void*) * m_uiHashSize);
        unsigned int uiSize = m_uiHashSize * sizeof(void*);
        memset(m_ppkHashTable, 0, uiSize);
    }
    virtual ~MapBase();
};
struct Map : MapBase {
    Map() : MapBase(37) {}
    virtual ~Map();
};
struct Critical {
    CRITICAL_SECTION value;
    Critical() { InitializeCriticalSection(&value); }
    ~Critical() { DeleteCriticalSection(&value); }
};
struct Target : Base {
    Slot slots[3];
    char unk84, unk85, unk86, unk87;
    unsigned short count88, cap8a;
    int* p8c;
    List list90;
    Elem a[4], b[4];
    Smart sp13c;
    List list140;
    int unk14c;
    char unk150, unk151, unk152, unk153;
    Color color154;
    int unk164, unk168;
    char unk16c, unk16d, unk16e, unk16f;
    Data170* p170;
    Pass98* p174;
    Pass98* p178;
    int* p17c;
    int* p180;
    char* p184;
    char* p188;
    int unk18c, unk190, unk194;
    Smart sp198;
    int unk19c;
    Smart sp1a0;
    ShaderPass pass1a4;
    Map map1b4;
    int unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    Critical cs;
    Target(void* owner, int count, int mode);
    virtual ~Target();
};
// pdb: BSShaderAccumulator::BSShaderAccumulator | BSShaderAccumulator.obj | fnv360_0822_retail, call_gap, low
// pdb params: aeBatchRendererCreationType, auiBatchRendererCount, auiPassesPerBatchRenderer
Target::Target(void* owner, int count, int mode) : pass1a4(0, 0x2f5, true, 0, 0)
{
    unk84 = 1;
    unk85 = 0;
    unk86 = 1;
    p8c = new int[50];
    count88 = 0;
    cap8a = 50;
    for (int i = 0; i < 50; i++)
        p8c[i] = 0;
    list90.FUN_00bd12d0();
    unk44 = 1.0f;
    unk40 = 0;
    unk3c = 0;
    for (int i = 0; i < 3; i++) {
        slots[i].p = 0;
        slots[i].b = 0;
        slots[i].f = 0.0f;
        slots[i].c = 0;
        slots[i].d = 0;
    }
    unk14c = 0;
    unk150 = 0;
    p170 = new Data170;
    unk18c = count;
    unk190 = mode;
    p174 = new Pass98(unk190, owner);
    if (unk18c == 2)
        p178 = new Pass98(unk190, owner);
    else
        p178 = 0;
    p17c = new int[unk18c];
    p180 = new int[unk18c];
    p184 = new char[unk18c];
    p188 = new char[unk18c];
    unk19c = 0;
    sp1a0.Reset();
    DAT_0117c2a4 = 0;
    unk16c = 1;
    sp198.Reset();
    unk3a = 0;
    color154 = Color(0.3f, 0.3f, 0.3f, 1.0f);
}
}

// @f3 0x00ae94b0 (community match, verified in this file)
namespace f3m_00ae94b0 {
namespace f3m_00ae94b0 {
void __cdecl FUN_0089ec10(void*, unsigned);
struct Obj {
    void FUN_00ae8a50();
    Obj* FUN_00ae94b0(unsigned flags);
};
// pdb: BSShaderAccumulator::`scalar deleting destructor' | BSShaderAccumulator.obj | fnv360_0822_retail, caller_sim, low
Obj* Obj::FUN_00ae94b0(unsigned flags) {
    FUN_00ae8a50();
    if (flags & 1) FUN_0089ec10(this, 640);
    return this;
}
}
}   // namespace f3m_00ae94b0

// @f3 0x00ae6580 (community match, verified in this file)
namespace ResumeAE6580 {
struct Bound { float x, y, z, radius; };
extern Bound DAT_0108edc8;
struct NiRefObject {
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct Item : NiRefObject {
    virtual void Reserved08();
    virtual int IsVisibleThing();
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound* bound;
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
    bool flag_ec;
    int unkf0;
    int unkf4;
    int unkf8;
    bool flag_fc;
    int unk100;
    int unk104;
    int unk108;
    NiPointer<NiRefObject> field_10c;
};
inline Bound* BoundOf(Item* item) { return item->bound ? item->bound : &DAT_0108edc8; }
struct ItemList {
    struct Node { Node* next; Node* previous; Item* item; };
    Node* head;
    Node* tail;
    unsigned count;
    void* GetHeadPos() { return head; }
    Item*& GetNext(void*& pos) { Item*& item=((Node*)pos)->item; pos=((Node*)pos)->next; return item; }
    void FUN_00abb340();
    void RemoveAll() { FUN_00abb340(); }
};
struct Sub1e0 { void FUN_00ab49c0(); };
struct BSTextureManager {};
struct GlobalObject_0096a2d0 {
    volatile long owner;
    unsigned count;
    void FUN_00409a80(int);
    void Lock(int x) { FUN_00409a80(x); }
};
struct Owner {
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
    ItemList list0e4;
    ItemList list0f0;
    ItemList list0fc;
    ItemList list108;
    ItemList list114;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    Sub1e0* field_1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    bool flag_1fc;
    void FUN_00ae6580();
};
struct OwnerExact : Owner {
  void FUN_00ae3520(Item*);
  void FUN_00ae5ca0(Item*);
  void FUN_00ae4190(Item*);
  void FUN_00ae3ab0(Item*);
  void FUN_00ae5f90(NiPointer<Item>&);
};
struct BSTextureExact { void FUN_00af08b0(NiRefObject*); };
struct Sub1e0Exact { void FUN_00ab49c0(); };
void FUN_00ae4330(Item*, Owner*, int, bool);
extern BSTextureManager* DAT_0116ef98;

extern GlobalObject_0096a2d0 DAT_0116fc80, DAT_0116fca0;


// pdb: ShadowSceneNode::ProcessQueuedLights | ShadowSceneNode.obj | fnv360_0822_retail, call_gap, medium
void Owner::FUN_00ae6580()
{
    DAT_0116fc80.Lock(0);
    void* pos = list0e4.GetHeadPos();
    while (pos)
    {
        Item* item = list0e4.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
                ((OwnerExact*)this)->FUN_00ae3520(item);
            else
                ((OwnerExact*)this)->FUN_00ae5ca0(item);
        }
    }
    pos = list0fc.GetHeadPos();
    while (pos)
    {
        Item* item = list0fc.GetNext(pos);
        if (item)
        {
            if (item->flag_fc)
                ((OwnerExact*)this)->FUN_00ae4190(item);
            else
                ((OwnerExact*)this)->FUN_00ae3ab0(item);
        }
    }
    pos = list0f0.GetHeadPos();
    while (pos)
    {
        Item* item = list0f0.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
            {
                NiPointer<Item> spItem = item;
                if (spItem)
                {
                    ((BSTextureExact*)DAT_0116ef98)->FUN_00af08b0(spItem->field_10c);
                    spItem->field_10c = 0;
                    ((OwnerExact*)this)->FUN_00ae5f90(spItem);
                }
            }
            else
            {
                NiPointer<Item> spItem = item;
                ((OwnerExact*)this)->FUN_00ae5f90(spItem);
            }
        }
    }
    DAT_0116fca0.Lock(0);
    pos = list114.GetHeadPos();
    while (pos)
    {
        Item* item = list114.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->radius < 150.0)
                FUN_00ae4330(item, this, 1, true);
            else
                FUN_00ae4330(item, this, 1, false);
        }
    }
    pos = list108.GetHeadPos();
    while (pos)
    {
        Item* item = list108.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->radius < 150.0)
                FUN_00ae4330(item, this, 0, true);
            else
                FUN_00ae4330(item, this, 0, false);
        }
    }
    if (field_1e0)
        ((Sub1e0Exact*)field_1e0)->FUN_00ab49c0();
    list0e4.RemoveAll();
    list0f0.RemoveAll();
    list0fc.RemoveAll();
    list108.RemoveAll();
    list114.RemoveAll();
    long(__stdcall* cas)(volatile long*, long, long) = FUN_00d9b06c;
    flag_1fc = true;
    if (--DAT_0116fca0.count == 0) {
        const long previousOwner = DAT_0116fca0.owner;
        cas(&DAT_0116fca0.owner, 0, previousOwner);
    }
    if (--DAT_0116fc80.count == 0) {
        const long previousOwner = DAT_0116fc80.owner;
        cas(&DAT_0116fc80.owner, 0, previousOwner);
    }
}
}
