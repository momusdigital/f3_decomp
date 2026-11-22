#include "f3_common.h"
// src/havok/common/base/math/quaternion/hkquaternion_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/quaternion/hkquaternion.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/common/base/math/quaternion/hkquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/quaternion/hkquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
/* PACKET-DECLARATIONS IS PROVIDED BY THE CHECKER; DO NOT INCLUDE IT IN YOUR SUBMISSION.
   Only submit the TARGET definition and any genuinely missing declarations that are required
   for compilation. Do not write or repeat packet-declarations, nor any headers that might
   be present in the checker's context. */
class FUN_005611c0_t
{
  public:
    void FUN_005611c0();
    void FUN_00cb2830(float* pts);
};
static float g_sink2550;
extern "C" double cb2550_clobber(double x);
static __declspec(noinline) void FUN_00cb2550(FUN_005611c0_t* obj, float* pts)
{
    float s = pts[0] * pts[1];
    s = (float)cb2550_clobber(s);
    s += pts[5];
    g_sink2550 = s;
    if (s > 1.0e9f)
        *(int*)obj = 0;
}
#include <xmmintrin.h>
#include <math.h>
struct FUN_00cb24c0_cls
{
    __m128 m_00;
    void FUN_00c7f500(unsigned char* flag);
    unsigned char* IsNormalized(unsigned char* flag);
};
struct Block64
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
    __m128 v3;
};
struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void CallSub(Block64* p);
};
__declspec(align(16)) struct FUN_00cf5950_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    SubObj m_sub;
    Block64 m_block;

    void CopyBlock(Block64* src);
};
struct S00cb2550_V4
{
    union
    {
        __m128 q;
        float v[4];
    };
};
struct S00cb2550_Rot
{
    float m[3][4];
    float operator()(int r, int c) const
    {
        return m[c][r];
    }
};
struct S00cb2550_Quat
{
    S00cb2550_V4 q;
};
static void FUN_00cb2550(S00cb2550_Quat* self, const S00cb2550_Rot& r);
void S00cb2550_caller(S00cb2550_Quat* q, const S00cb2550_Rot& r);

__declspec(align(16)) struct FUN_00cb2450_cls
{
    __m128 m_00;
    void hkQuaternion_setAxisAngle(__m128* v, float a1);
};
struct LFrame
{
    float unk04;
    float x;
    volatile float s;
};
// @f3 0x009240d0 (community match, verified in this file)
#include <math.h>

static inline float QuatSin9240d0(float r) { return (float)sin(r); }
static inline float QuatCos9240d0(float r) { return (float)cos(r); }

// pdb: hkQuaternion::setAxisAngle | hkQuaternion.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00cb2450_cls::hkQuaternion_setAxisAngle(__m128* v, float a1)
{
    float halfAngle = a1 * 0.5;
    float s = QuatSin9240d0(halfAngle);
    float* q = m_00.m128_f32;
    const float* axis = v->m128_f32;
    for (int i = 0; i < 4; i++)
        q[i] = axis[i] * s;
    m_00.m128_f32[3] = QuatCos9240d0(halfAngle);
}

