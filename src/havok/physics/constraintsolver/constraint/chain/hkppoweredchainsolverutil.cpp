#include "f3_common.h"
// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00df0810_Channel
{
    float value1;
    float value2;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00df0810_Source
{
    unsigned char modes;
    FUN_00df0810_Channel channels[3];
};

struct FUN_00df0810_Dest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float values[3];
    int unk1c;
};

// Selects value1 or value2 of a source channel based on its 2-bit mode and stores it into the destination's values array.
// @fnv 0x00df0810
// pdb: hkPoweredChain_OverwriteVelocityWithExplicitImpulse | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: modifiedConstraintIndex, modifiedCoordinateIndex, motorsState, velocities
void __cdecl CopyChannelValue(int index, int channel, FUN_00df0810_Source* sources, FUN_00df0810_Dest* dests)
{
    FUN_00df0810_Source* source = &sources[index];
    FUN_00df0810_Dest* dest = &dests[index];
    float value;
    if (((source->modes >> (channel * 2)) & 3) == 1)
        value = source->channels[channel].value1;
    else
        value = source->channels[channel].value2;
    dest->values[channel] = value;
}

#include <xmmintrin.h>

struct __declspec(align(16)) CBuf
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
};
struct __declspec(align(16)) BufA
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
};
struct __declspec(align(16)) BufB
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
};

struct hkVector4
{
    union
    {
        __m128 m_vComponents;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct MatrixGroup
{
    char data0[0xc0];
    char data1[0xc0];
    char pad[0x240];
};

struct InputStruct
{
    char pad0[4];
    int count;
    char pad1[0x18];
    MatrixGroup* matrices;
    char pad2[8];
    hkAabb* aabbs;
};

// @f3 0x00a7af40 (community match, verified in this file)
extern "C" void __cdecl FUN_00a98580(void* dst, const void* matrix, const void* src);

// pdb: hkPoweredChain_SolveConstraintMatrix_ComputeVectorG | hkpPoweredChainSolverUtil.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: info, tempBufferG
void __cdecl FUN_00df11a0(InputStruct* apInput, hkAabb* out)
{
    ++out;
    out[-1].m_kMinimumCorner.x = out[-1].m_kMinimumCorner.y = out[-1].m_kMinimumCorner.z = out[-1].m_kMinimumCorner.w = 0.0f;
    out[-1].m_kMaximumCorner.x = out[-1].m_kMaximumCorner.y = out[-1].m_kMaximumCorner.z = out[-1].m_kMaximumCorner.w = 0.0f;

    int index = 0;
    for (; index < apInput->count; ++index)
    {
        __declspec(align(16)) hkAabb scratch;
        const char* matrix = apInput->matrices[index].data0;
        const hkAabb* source = &apInput->aabbs[index];
        FUN_00a98580(&scratch, matrix, &out[index - 1]);

        ((float*)&scratch)[0] = ((const float*)source)[0] - ((float*)&scratch)[0];
        ((float*)&scratch)[1] = ((const float*)source)[1] - ((float*)&scratch)[1];
        ((float*)&scratch)[2] = ((const float*)source)[2] - ((float*)&scratch)[2];
        ((float*)&scratch)[3] = ((const float*)source)[3] - ((float*)&scratch)[3];
        ((float*)&scratch)[4] = ((const float*)source)[4] - ((float*)&scratch)[4];
        ((float*)&scratch)[5] = ((const float*)source)[5] - ((float*)&scratch)[5];
        ((float*)&scratch)[6] = ((const float*)source)[6] - ((float*)&scratch)[6];
        ((float*)&scratch)[7] = ((const float*)source)[7] - ((float*)&scratch)[7];

        FUN_00a98580(&out[index], apInput->matrices[index].data1, &scratch);
    }
}

