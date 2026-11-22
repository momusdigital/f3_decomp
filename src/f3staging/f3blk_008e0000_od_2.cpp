// src/f3staging/f3blk_008e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008ecb40 (community match, verified in this file)
#include <math.h>
namespace f3m_008ecb40 {
namespace Aim2000 {
__forceinline float AimMin(float a,float b){return a<b?a:b;}
__forceinline float AimMax(float a,float b){return a>b?a:b;}
struct __declspec(align(16)) AimVector_c70060 {float x,y,z,w;void FUN_00477880(int,int);};
struct AimNode_c70060 {unsigned unk00,unk04;char* object;};extern float DAT_00f79adc;extern const float DAT_00dcda0c;
struct AimController_c70060 {
unsigned field_000;
unsigned field_004;
unsigned field_008;
unsigned field_00c;
unsigned field_010;
unsigned field_014;
unsigned field_018;
unsigned field_01c;
unsigned field_020;
unsigned field_024;
unsigned field_028;
unsigned field_02c;
unsigned field_030;
unsigned field_034;
unsigned field_038;
unsigned field_03c;
unsigned field_040;
unsigned field_044;
unsigned field_048;
unsigned field_04c;
unsigned field_050;
unsigned field_054;
unsigned field_058;
unsigned field_05c;
unsigned field_060;
unsigned field_064;
unsigned field_068;
unsigned field_06c;
unsigned field_070;
unsigned field_074;
unsigned field_078;
unsigned field_07c;
unsigned field_080;
unsigned field_084;
unsigned field_088;
unsigned field_08c;
unsigned field_090;
unsigned field_094;
unsigned field_098;
unsigned field_09c;
unsigned field_0a0;
unsigned field_0a4;
unsigned field_0a8;
unsigned field_0ac;
unsigned field_0b0;
unsigned field_0b4;
unsigned field_0b8;
unsigned field_0bc;
unsigned field_0c0;
unsigned field_0c4;
unsigned field_0c8;
unsigned field_0cc;
unsigned field_0d0;
unsigned field_0d4;
unsigned field_0d8;
unsigned field_0dc;
unsigned field_0e0;
unsigned field_0e4;
unsigned field_0e8;
unsigned field_0ec;
unsigned field_0f0;
unsigned field_0f4;
unsigned field_0f8;
unsigned field_0fc;
unsigned field_100;
unsigned field_104;
unsigned field_108;
unsigned field_10c;
unsigned field_110;
unsigned field_114;
unsigned field_118;
unsigned field_11c;
unsigned field_120;
unsigned field_124;
unsigned field_128;
unsigned field_12c;
unsigned field_130;
unsigned field_134;
unsigned field_138;
unsigned field_13c;
unsigned field_140;
unsigned field_144;
unsigned field_148;
unsigned field_14c;
unsigned field_150;
unsigned field_154;
unsigned field_158;
unsigned field_15c;
unsigned field_160;
unsigned field_164;
unsigned field_168;
unsigned field_16c;
unsigned field_170;
unsigned field_174;
unsigned field_178;
unsigned field_17c;
unsigned field_180;
unsigned field_184;
unsigned field_188;
unsigned field_18c;
unsigned field_190;
unsigned field_194;
unsigned field_198;
unsigned field_19c;
unsigned field_1a0;
unsigned field_1a4;
unsigned field_1a8;
unsigned field_1ac;
unsigned field_1b0;
unsigned field_1b4;
unsigned field_1b8;
unsigned field_1bc;
unsigned field_1c0;
unsigned field_1c4;
unsigned field_1c8;
unsigned field_1cc;
unsigned field_1d0;
unsigned field_1d4;
unsigned field_1d8;
unsigned field_1dc;
unsigned field_1e0;
unsigned field_1e4;
unsigned field_1e8;
unsigned field_1ec;
unsigned field_1f0;
unsigned field_1f4;
unsigned field_1f8;
unsigned field_1fc;
unsigned field_200;
unsigned field_204;
unsigned field_208;
unsigned field_20c;
unsigned field_210;
unsigned field_214;
unsigned field_218;
unsigned field_21c;
unsigned field_220;
unsigned field_224;
unsigned field_228;
unsigned field_22c;
unsigned field_230;
unsigned field_234;
unsigned field_238;
unsigned field_23c;
unsigned field_240;
unsigned field_244;
unsigned field_248;
unsigned field_24c;
unsigned field_250;
unsigned field_254;
unsigned field_258;
unsigned field_25c;
unsigned field_260;
unsigned field_264;
unsigned field_268;
unsigned field_26c;
unsigned field_270;
unsigned field_274;
unsigned field_278;
unsigned field_27c;
unsigned field_280;
unsigned field_284;
unsigned field_288;
unsigned field_28c;
unsigned field_290;
unsigned field_294;
unsigned field_298;
unsigned field_29c;
unsigned field_2a0;
unsigned field_2a4;
unsigned field_2a8;
unsigned field_2ac;
unsigned field_2b0;
unsigned field_2b4;
unsigned field_2b8;
unsigned field_2bc;
unsigned field_2c0;
unsigned field_2c4;
unsigned field_2c8;
unsigned field_2cc;
unsigned field_2d0;
unsigned field_2d4;
unsigned field_2d8;
unsigned field_2dc;
float field_2e0;
float field_2e4;
float field_2e8;
float field_2ec;
unsigned field_2f0;
unsigned field_2f4;
unsigned field_2f8;
unsigned field_2fc;
unsigned field_300;
unsigned field_304;
unsigned field_308;
unsigned field_30c;
unsigned field_310;
unsigned field_314;
unsigned field_318;
unsigned field_31c;
unsigned field_320;
unsigned field_324;
unsigned field_328;
unsigned field_32c;
unsigned field_330;
unsigned field_334;
unsigned field_338;
unsigned field_33c;
unsigned field_340;
unsigned field_344;
unsigned field_348;
unsigned field_34c;
unsigned field_350;
unsigned field_354;
unsigned field_358;
unsigned field_35c;
unsigned field_360;
unsigned field_364;
unsigned field_368;
unsigned field_36c;
unsigned field_370;
unsigned field_374;
unsigned field_378;
unsigned field_37c;
unsigned field_380;
unsigned field_384;
unsigned field_388;
unsigned field_38c;
unsigned field_390;
unsigned field_394;
unsigned field_398;
unsigned field_39c;
unsigned field_3a0;
unsigned field_3a4;
unsigned field_3a8;
unsigned field_3ac;
unsigned field_3b0;
unsigned field_3b4;
unsigned field_3b8;
float field_3bc;
unsigned field_3c0;
unsigned field_3c4;
unsigned field_3c8;
unsigned field_3cc;
unsigned field_3d0;
unsigned field_3d4;
unsigned field_3d8;
float field_3dc;
float field_3e0;
float field_3e4;
unsigned field_3e8;
unsigned field_3ec;
unsigned field_3f0;
unsigned field_3f4;
unsigned field_3f8;
unsigned field_3fc;
unsigned field_400;
unsigned field_404;
unsigned field_408;
unsigned field_40c;
unsigned field_410;
unsigned field_414;
unsigned field_418;
unsigned field_41c;
unsigned field_420;
AimNode_c70060* field_424;
unsigned field_428;
unsigned field_42c;
unsigned field_430;
unsigned field_434;
unsigned field_438;
unsigned field_43c;
unsigned field_440;
unsigned field_444;
unsigned field_448;
unsigned field_44c;
unsigned field_450;
unsigned field_454;
unsigned field_458;
unsigned field_45c;
unsigned field_460;
unsigned field_464;
unsigned field_468;
unsigned field_46c;
unsigned field_470;
unsigned field_474;
unsigned field_478;
unsigned field_47c;
unsigned field_480;
float field_484;
void FUN_008ea4f0(int,AimVector_c70060*);bool IsFlagSet(unsigned bit)const{return (field_294>>bit)&1;}
void FUN_008ecb40();};
// pdb: bhkCharacterController::~bhkCharacterController | bhkCharacterController.obj | fnv360_0822_debug, udata, low, conflict (bridge: bhkCharacterController::CalculatePitchAndRoll)
void AimController_c70060::FUN_008ecb40()
{
    unsigned int flags=field_294;
    AimVector_c70060 position;
    float difference, angle;
    if (IsFlagSet(18) || !(field_3bc > 0.0f))
        return;
    if (IsFlagSet(0))
    {
        if (IsFlagSet(25))
        {
            difference = field_2e0;
            angle = field_2e4;
            if (difference == 1.1754943508222875e-38f)
            {
                FUN_008ea4f0(0, &position);
                difference =
                    position.z;
            }
            if (angle == 1.1754943508222875e-38f)
            {
                FUN_008ea4f0(1, &position);
                angle = position.z;
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_484;
                float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_00f79adc * 0.01745329238474369)
                        angle = (float)(DAT_00f79adc * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_00f79adc * -0.01745329238474369)
                        angle = (float)(DAT_00f79adc * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_3dc;
            if (difference != 0.0f)
            {
                if (field_3e4 > 1.0f)
                    field_3e4 = 1.0f;
                field_3dc += difference * field_3e4;
            }
        }
        if (IsFlagSet(26))
        {
            difference = field_2e8;
            angle = field_2ec;
            if (difference == 1.1754943508222875e-38f)
            {
                FUN_008ea4f0(2, &position);
                difference =
                    position.z;
            }
            if (angle == 1.1754943508222875e-38f)
            {
                FUN_008ea4f0(3, &position);
                angle = position.z;
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_484;
                float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_00f79adc * 0.01745329238474369)
                        angle = (float)(DAT_00f79adc * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_00f79adc * -0.01745329238474369)
                        angle = (float)(DAT_00f79adc * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_3e0;
            if (difference != 0.0f)
            {
                if (field_3e4 > 1.0f)
                    field_3e4 = 1.0f;
                field_3e0 += difference * field_3e4;
            }
        }
    }
    else
    {
        char* object = field_424 ? field_424->object : 0;
        position.FUN_00477880((int)(object + 0xa0), (int)&field_2d0);
        double ucLimitOffset = DAT_00f79adc * 0.01745329238474369;

        
        float limit = (float)ucLimitOffset;
        if (((unsigned char)(flags >> 26) & 1))
        {
            float angle = AimMax(AimMin((float)(position.x * -1.0), limit), -limit);
            float difference = angle - field_3e0;
            if (difference != 0.0f)
            {
                if (field_3e4 > 1.0f)
                    field_3e4 = 1.0f;
                field_3e0 += difference * field_3e4;
            }
        }
        if (((unsigned char)(flags >> 25) & 1))
        {
            double raw = position.y;
            float angle = AimMax(raw < limit ? (float)raw : limit, -limit);
            float difference = angle - field_3dc;
            if (difference != 0.0f)
            {
                if (field_3e4 > 1.0f)
                    field_3e4 = 1.0f;
                field_3dc += difference * field_3e4;
            }
        }
    }
}

}

}   // namespace f3m_008ecb40
