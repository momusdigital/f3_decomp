#include "f3_common.h"
// src/havok/common/base/memory/util/hkmemutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/util/hkmemutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00d2caa0(void*, void*, unsigned int);

namespace fnv_00d2caa0 {
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00d2caa0
// pdb: bhkShape::RegisterStreamables | bhkShape.obj | fnv360_0822_retail, vtable, high
// pdb params: arStream
void __cdecl FUN_00d2caa0(void* dst, void* src, unsigned int size)
{
    _memmove(dst, src, size);
}
}  // namespace fnv_00d2caa0

void __cdecl FUN_00ec61c0();
// @fnv 0x00d2cab0
// pdb: bhkCollisionObject::RegisterStreamables | bhkCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void __cdecl FUN_00d2cab0()
{
    FUN_00ec61c0();
}
