// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
// Havok-style bisection: find the sample time t where the support distance along the target plane reaches target.
struct __declspec(align(16)) Sample
{
    unsigned int d[76];
};
struct Out
{
    float t;
    float u[3];
    __m128 pos;
};
void FUN_00db4b50(void* a, float t, Sample* out);
extern const double DAT_010290b0;  // 0.5
extern const double DAT_0101ffa0;  // 0.1
extern const float DAT_0101e2bc;   // 0.1f
extern const double DAT_0106b9e8;  // 0.9
extern const float DAT_010177e8;   // 0.9f
// @f3 0x00a417e0 (community match, verified in this file)
void FUN_00a41610(void* a, float t, Sample* out);
extern const double FUN_00dc2f10;
extern const double FUN_00dc0ac8;
extern const float FUN_00dbe8fc;
extern const double FUN_00e012a0;
extern const float FUN_00db8888;
struct NativeVector4 {
 __m128 quad;
 float Dot4(const NativeVector4& other)const {
  const double firstProduct = quad.m128_f32[1]*other.quad.m128_f32[1];
  return firstProduct+static_cast<const volatile float&>(quad.m128_f32[0])*other.quad.m128_f32[0]+quad.m128_f32[2]*other.quad.m128_f32[2]+quad.m128_f32[3]*other.quad.m128_f32[3];
 }
};
struct SampleFields {
 unsigned int unknown00;
 unsigned int unknown04;
 unsigned int unknown08;
 unsigned int unknown0c;
 unsigned int unknown10;
 unsigned int unknown14;
 unsigned int unknown18;
 unsigned int unknown1c;
 unsigned int unknown20;
 unsigned int unknown24;
 unsigned int unknown28;
 unsigned int unknown2c;
 unsigned int unknown30;
 unsigned int unknown34;
 unsigned int unknown38;
 unsigned int unknown3c;
 unsigned int unknown40;
 unsigned int unknown44;
 unsigned int unknown48;
 unsigned int unknown4c;
 unsigned int unknown50;
 unsigned int unknown54;
 unsigned int unknown58;
 unsigned int unknown5c;
 unsigned int unknown60;
 unsigned int unknown64;
 unsigned int unknown68;
 unsigned int unknown6c;
 unsigned int unknown70;
 unsigned int unknown74;
 unsigned int unknown78;
 unsigned int unknown7c;
 unsigned int unknown80;
 unsigned int unknown84;
 unsigned int unknown88;
 unsigned int unknown8c;
 unsigned int unknown90;
 unsigned int unknown94;
 unsigned int unknown98;
 unsigned int unknown9c;
 unsigned int unknowna0;
 unsigned int unknowna4;
 unsigned int unknowna8;
 unsigned int unknownac;
 unsigned int unknownb0;
 unsigned int unknownb4;
 unsigned int unknownb8;
 unsigned int unknownbc;
 NativeVector4 plane,position;
};
union NativeSample {Sample raw;SampleFields fields;};
struct V3 { float x,y,z; };
union NativeQuad {__m128 simd;float lane[4];};
union ScalarBits {unsigned int bits;float value;};
static __forceinline float SampleFloat(unsigned int bits){ScalarBits word;word.bits=bits;return word.value;}

// pdb: hk4dGskCollidePointWithPlaneFinal | hkpContinuousGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: input, tol, vertexA, startRt, endRt, distance0, distance1, velocity, out
float FUN_00db4ca0(void* a, const float* target, const __m128* origin, float A, float B, float C, float D, int unused, Out* res)
{

    float t = A;
    float eps = (float)(target[4] * FUN_00dc2f10);
    for (int i = 0; i < 10; ++i)
    {
        if (*target >= C) break;
        float delta = D - C;
        if (delta > -eps) break;
        t = (*target - C) / delta;
        if (!(i & 1))
        {
            if (!(t > FUN_00dc0ac8)) t = FUN_00dbe8fc;
            if (!((double)t < FUN_00e012a0)) t = FUN_00db8888;
        }
        NativeSample s;
        t = (1.0f - t) * A + B * t;
        FUN_00a41610(a, t, &s.raw);


        NativeVector4 dv;
        dv.quad.m128_f32[0] = origin->m128_f32[0] - s.fields.position.quad.m128_f32[0];
        dv.quad.m128_f32[1] = origin->m128_f32[1] - s.fields.position.quad.m128_f32[1];
        dv.quad.m128_f32[2] = origin->m128_f32[2] - s.fields.position.quad.m128_f32[2];
        dv.quad.m128_f32[3]=1.0f;
        float r = dv.Dot4(s.fields.plane);
        float e = (float)fabs((float)(r - *target));
        if (e < eps) break;
        if (r < *target) { B = t; D = r; }
        else { A = t; C = r; }
    }
    if (t < res->t)
    {
        res->t = t;
        res->pos.m128_f32[0]=origin->m128_f32[0];
        res->pos.m128_f32[1]=origin->m128_f32[1];
        res->pos.m128_f32[2]=origin->m128_f32[2];
        res->pos.m128_f32[3]=origin->m128_f32[3];
    }
    return res->t;
}

