// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CpuObject
{
    int value;
    void FUN_00e10a10(int value);
};
// @fnv 0x00e10a10
// pdb: BGSUnloadedFormBuffer::BGSUnloadedFormBuffer | BGSUnloadedFormBuffer.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apBuffer
void CpuObject::FUN_00e10a10(int value)
{
    this->value = value;
}

// @f3twin 0x00a8f460 of 0x004237f0
struct F3Twin_00a8f460 : public CpuObject { void F3_FUN_00a8f460(int value) ; };
// pdb: hkpPrimitiveDrawer::setDisplayHandler | hkpPrimitiveDrawer.obj | fnv360_0822_retail, call_gap, low
// pdb params: displayHandler
void F3Twin_00a8f460::F3_FUN_00a8f460(int value) 
{
    this->value = value;
}
