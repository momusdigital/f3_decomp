#include "f3_common.h"
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

// In-file stand-in for the helper. Its shape (not its bytes) is what matters:
// pts stays live across an ABI-clobbering call, so it gets a callee-saved
// register home and the private convention passes it in esi; obj is read
// exactly once, late, so it stays on the stack.
static __declspec(noinline) void FUN_00cb2550(FUN_005611c0_t* obj, float* pts)
{
    float s = pts[0] * pts[1];
    s = (float)cb2550_clobber(s);
    s += pts[5];
    g_sink2550 = s;
    if (s > 1.0e9f)
        *(int*)obj = 0;
}

// @fnv 0x00cb2830
// pdb: hkQuaternion::setAndNormalize | hkQuaternion.obj | tesv_win, hash, low
void FUN_005611c0_t::FUN_00cb2830(float* apPoints)
{
    FUN_00cb2550(this, apPoints);
    FUN_005611c0();
}

#include <xmmintrin.h>
#include <math.h>
struct FUN_00cb24c0_cls
{
    __m128 m_00;
    void FUN_00c7f500(unsigned char* flag);
    unsigned char* IsNormalized(unsigned char* flag);
};

// Checks whether the squared length is within 0.001 of 1.0, ANDs that with the existing flag, and stores the result.
// @f3 0x00924140 (community match, verified in this file)
struct FUN_008d27a0_cls
{
    void FUN_008d27a0(unsigned char* flag);
};

// pdb: hkQuaternion::isOk | hkQuaternion.obj | tesv_win, objrun, medium
unsigned char* FUN_00cb24c0_cls::IsNormalized(unsigned char* apResult)
{
    ((FUN_008d27a0_cls*)this)->FUN_008d27a0(apResult);
    float* v = (float*)this;
    float fLengthSq = v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3];
    float fDiff = fLengthSq - 1.0;
    fDiff = fabsf(fDiff);
    bool bIsNormalized = fDiff < 0.001f;
    unsigned char r;
    if (*apResult && bIsNormalized)
        r = 1;
    else
        r = 0;
    *apResult = r;
    return apResult;
}


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

// Converts a rotation matrix to a quaternion and stores the quaternion in self->q.
// @f3 0x009241c0 (community match, verified in this file)
#include <math.h>

// pdb: quaternionFromRotatation | hkQuaternion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
static __declspec(noinline) void FUN_00cb2550(S00cb2550_Quat* apQuat, const S00cb2550_Rot& arRot)
{
    S00cb2550_V4 v;
    float trace = arRot(0, 0) + arRot(1, 1) + arRot(2, 2);
    if (trace > 0)
    {
        float s = sqrtf((float)(trace + 1.0));
        float t = (float)(0.5 / s);
        v.v[0] = (arRot(2, 1) - arRot(1, 2)) * t;
        v.v[1] = (arRot(0, 2) - arRot(2, 0)) * t;
        v.v[2] = (arRot(1, 0) - arRot(0, 1)) * t;
        v.v[3] = (float)(0.5 * s);
    }
    else
    {
        int next[3];
        next[0] = 1;
        next[1] = 2;
        next[2] = 0;
        int iMax = 0;
        if (arRot(1, 1) > arRot(0, 0))
            iMax = 1;
        if (arRot(2, 2) > arRot(iMax, iMax))
            iMax = 2;
        int j = next[iMax];
        int k = next[j];
        float s = sqrtf((float)(arRot(iMax, iMax) - (arRot(j, j) + arRot(k, k)) + 1.0));
        float t = (float)(0.5 / s);
        v.v[iMax] = (float)(s * 0.5);
        v.v[3] = (arRot(k, j) - arRot(j, k)) * t;
        v.v[j] = (arRot(j, iMax) + arRot(iMax, j)) * t;
        v.v[k] = (arRot(k, iMax) + arRot(iMax, k)) * t;
    }
    apQuat->q = v;
}

volatile int g_in2550;
S00cb2550_Quat g_q2550;
S00cb2550_Rot g_r2550;
void FUN_00cb2550_caller()
{
    if (g_in2550)
        FUN_00cb2550(&g_q2550, g_r2550);
}


void S00cb2550_caller(S00cb2550_Quat* q, const S00cb2550_Rot& r)
{
    FUN_00cb2550(q, r);
}
