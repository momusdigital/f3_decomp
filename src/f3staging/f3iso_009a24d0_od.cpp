#include <new>
// src/f3staging/f3iso_009a24d0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009a24d0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009a24d0 (community match, verified in this file)
namespace f3m_009a24d0 {
struct __declspec(align(16)) SegmentVec4 { float x,y,z,w; };
// pdb: hkpCapsuleShape::closestPointLineSeg | hkpCapsuleShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: A, B, B2, pt
__declspec(noinline) void FUN_009a24d0(const float* a, const float* b, const float* c, float* out)
{
    SegmentVec4 n;
    SegmentVec4 res;
    float len2, dp, num;

    res.x = b[0] - a[0];
    res.y = b[1] - a[1];
    res.z = b[2] - a[2];
    n.x = c[0] - b[0];
    n.y = c[1] - b[1];
    n.z = c[2] - b[2];
    n.w = c[3] - b[3];
    float ny = n.y;
    float nx = n.x;
    len2 = nx * nx + ny * ny + n.z * n.z;
    double px = nx * res.x;
    dp = px + ny * res.y + n.z * res.z;
    num = -dp;
    if (num <= 0.0f)
    {
        out[0] = b[0];
        out[1] = b[1];
        out[2] = b[2];
        out[3] = b[3];
        return;
    }
    if (len2 <= num)
    {
        out[0] = c[0];
        out[1] = c[1];
        out[2] = c[2];
        out[3] = c[3];
        return;
    }
    num /= len2;
    out[0] = num * nx + b[0];
    out[1] = num * ny + b[1];
    out[2] = n.z * num + b[2];
    out[3] = n.w * num + b[3];
}

}   // namespace f3m_009a24d0
