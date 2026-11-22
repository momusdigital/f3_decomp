#include <new>
// src/f3staging/f3iso_00987ce0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00987ce0 alone: its staging file did not compile as a pack.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00987ce0 (community match, verified in this file)
namespace f3m_00987ce0 {
namespace S987ce0_ {

struct PtrArray
{
    void** data;
    unsigned short count;
};

// pdb: cleanupNullPointers | hkpEntityCallbackUtil.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkpEntityCallbackUtil_cleanupNullPointers)
static __declspec(noinline) void FUN_00987ce0(PtrArray* arr)
{
    for (int i = arr->count - 1; i >= 0; --i)
    {
        if (arr->data[i] == 0)
        {
            --arr->count;
            for (int j = i; j < arr->count; ++j)
            {
                arr->data[j] = arr->data[j + 1];
            }
        }
    }
}

volatile PtrArray* g_arr;

void EmitTarget()
{
    FUN_00987ce0((PtrArray*)g_arr);
}

}
}   // namespace f3m_00987ce0
