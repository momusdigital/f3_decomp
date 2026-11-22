#include "f3_common.h"
// src/staging/blk_00e40000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include <math.h>
struct RotationVector
{
    __m128 m_vComponents;
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};
extern const __m128 DAT_01017d10;

namespace fnv_00e526f0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_and_ps(__m128 a, __m128 b);
}

extern const __m128 DAT_01017d10;

}  // namespace fnv_00e526f0

union __declspec(align(16)) PackedQuaternionOutput
{
    __m128 simd;
    float components[4];
};

namespace fnv_00e52c30 {
union __declspec(align(16)) PackedQuaternionOutput
{
    __m128 simd;
    float components[4];
};
}  // namespace fnv_00e52c30

struct FNV_ALIGN(16) FUN_00dd1bf0
{
    int m[16];
    void Query(int a1, int a2, int a3, float a4, int a5);
};

// @fnv 0x00e5cfe0
// pdb: hkMoppObbVirtualMachine_queryObb | hkpMoppMachine.obj | fnv360_0822_retail, objrun, medium
// pdb params: code, BvToWorld, extent, radius, primitives_out
void FUN_00e5cfe0(int a1, int a2, int a3, float a4, int a5)
{
    FUN_00dd1bf0 obj;
    obj.Query(a1, a2, a3, a4, a5);
}
