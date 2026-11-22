#include <new>
// src/f3staging/f3iso_00a559f0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a559f0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a559f0 (community match, verified in this file)
namespace f3m_00a559f0 {
namespace weld_a559f0 {
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    __forceinline void operator=(const Vec4& v) { x=v.x; y=v.y; z=v.z; w=v.w; }
};
__forceinline void setSub4(Vec4& r, const Vec4& a, const Vec4& b)
{
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
}
__forceinline float lengthSquared3(const Vec4& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
}

// pdb: hkpMeshWeldingUtility::createSingularVertexArray | hkpMeshWeldingUtility.obj | tesv_win, call_gap, low
int __cdecl FUN_00a559f0(const weld_a559f0::Vec4* triangle, const weld_a559f0::Vec4* other, int edgeIndex,
                         weld_a559f0::Vec4* vertices, int* ordered)
{
    using namespace weld_a559f0;
    vertices[0] = triangle[edgeIndex % 3];
    int n = 3;
    vertices[1] = triangle[(edgeIndex + 1) % n];
    vertices[2] = triangle[(edgeIndex + 2) % n];
    int count = n;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Vec4 d;
            setSub4(d, vertices[j], other[i]);
            if (lengthSquared3(d) == 0.0f)
            {
                ordered[j] = i;
                goto next;
            }
        }
        vertices[count++] = other[i];
    next:;
    }
    return count;
}

}   // namespace f3m_00a559f0
