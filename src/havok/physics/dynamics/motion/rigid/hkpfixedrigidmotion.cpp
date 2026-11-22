#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpFixedRigidMotion.h"

extern int DAT_010c6cdc;
struct FUN_00d1e160_t
{
    int* vtbl;
    unsigned char m_auiShapeKeys[7];
    unsigned char m_type;
    void FUN_00d1dfa0(int a, int b);
    void* InitFixedRigidMotion(int a, int b);
};
// Calls FUN_00d1dfa0, sets vtbl to &DAT_010c6cdc, writes 5 to byte offset 8, and returns this.
// @fnv 0x00d1e160
// pdb: hkpFixedRigidMotion::hkpFixedRigidMotion | hkpFixedRigidMotion.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: position, rotation
void* FUN_00d1e160_t::InitFixedRigidMotion(int a, int b)
{
    FUN_00d1dfa0(a, b);
    vtbl = &DAT_010c6cdc;
    ((unsigned char*)this)[8] = 5;
    return this;
}

// @fnv 0x00d1e130
void __stdcall FUN_00d1e130(int, int)
{}

// @fnv 0x00d1e140
// pdb: hkEnum<enum hkpSampledHeightFieldShape::HeightFieldType,unsigned char>::hkEnum<enum hkpSampledHeightFieldShape::HeightFieldType,unsigned char> | hkpSampledHeightFieldShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: hkpSampledHeightFieldShape::getCinfo)
// pdb params: e
void __stdcall FUN_00d1e140(void* a)
{}

// 0x00d1e150  /MT /O2 /GS /EHsc /Gy   target: C2 04 00  (ret 4, empty thiscall with one stack arg)
struct C00d1e150
{
    int unk00;
    void FUN_00d1e150(int arg);
};

// @fnv 0x00d1e150
// pdb: hkpExtendedMeshShape::assertTrianglesSubpartValidity | hkpExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: part
void C00d1e150::FUN_00d1e150(int arg)
{}

#include <xmmintrin.h>
