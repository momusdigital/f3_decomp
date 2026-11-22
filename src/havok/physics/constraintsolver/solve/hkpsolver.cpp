// havok/physics/constraintsolver/solve/hkpsolver.cpp: free functions (2 functions)
#include "f3_common.h"
#include "fnv_asm_helpers.h"
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_011b9434[128];

// @fnv 0x00d921d0
int __cdecl FUN_00d921d0(const signed char* index)
{
    return DAT_011b9434[*index];
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

// @fnv 0x00d921c0
// pdb: hkEnum<enum hkpJacobianSchema::SchemaType,signed char>::operator!= | hkpSolver.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkp1Lin2AngJacobian::getInvJacDiagSr)
// pdb params: e
char* __cdecl FUN_00d921c0(char* dst, const char* src)
{
    *dst = *src;
    return dst;
}
