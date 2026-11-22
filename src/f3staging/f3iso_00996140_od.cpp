#include <new>
// src/f3staging/f3iso_00996140_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00996140 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00996140 (community match, verified in this file)
// FLAGS: /MT /O2 /GS /EHsc /Gy
namespace f3m_00994260 {
struct hkpBroadPhaseHandle;
struct hkpBpEndPoint { unsigned short m_value; unsigned short m_nodeIndex; };
struct hkpBpNode {
    unsigned short min_y, min_z, max_y, max_z, min_x, max_x;
    hkpBroadPhaseHandle* m_handle;
};
void __cdecl FUN_00901e90(void* arr, int cap, int esz);
void __cdecl FUN_00901f10(void* arr, int esz);
}

namespace Native2183 {
struct __declspec(align(16)) S16c50_Vec4 {
    float x, y, z, w;
    void setZero4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
};
extern S16c50_Vec4 DAT_01060db0;
extern S16c50_Vec4 DAT_01060dd0;
extern int DAT_010f3170;
__declspec(dllimport) void* __stdcall FUN_00d9b080(int id);
inline void* GetTemp() { return FUN_00d9b080(DAT_010f3170); }
}

extern void* DAT_00e7dd3c;

struct Heap996140 {
    void* FUN_008f6f60(int size, int flags);
};

struct Bound996140 {
    int x, y, z, w;
    Bound996140(const int* p) : x(p[0]), y(p[1]), z(p[2]), w(p[3]) {}
};

template <typename T>
struct Arr996140 {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    Arr996140() : m_data(0), m_size(0), m_capacityAndFlags((int)0x80000000) {}
    __forceinline T& expandOne() {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            f3m_00994260::FUN_00901f10(this, (int)sizeof(T));
        return m_data[m_size++];
    }
};

struct Marker996140 {
    // Fake match: class-local placement allocation preserves the nonthrowing construction ABI.
    void* operator new(unsigned int, void* p) throw() { return p; }
    unsigned short node, value;
    Arr996140<unsigned short> overlaps;
};

struct Base996140 {
    Base996140() {
        FUN_00a25ba0();
        *(void***)this = &DAT_00e7dd3c;
    }
    void FUN_00a25ba0();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};

template <typename T>
__forceinline void reserve996140(Arr996140<T>& a, int n)
{
    int c = a.m_capacityAndFlags & 0x3fffffff;
    if (c < n) {
        int g = c + c;
        if (n >= g) g = n;
        f3m_00994260::FUN_00901e90(&a, g, (int)sizeof(T));
    }
}

__forceinline void appendEP996140(Arr996140<f3m_00994260::hkpBpEndPoint>& a, const f3m_00994260::hkpBpEndPoint& ep)
{
    a.m_data[a.m_size] = ep;
    ++a.m_size;
}

__forceinline void findShift996140(int value, int& result)
{
    result = -1;
    if (value > 0) {
        int current = result;
        do { value >>= 1; ++current; } while (value > 0);
        result = current;
    }
}



// Fake match: retain full-vector conversion although only its first lane is consumed.
__forceinline unsigned short convert996140(float input,
    const Native2183::S16c50_Vec4& offset, const Native2183::S16c50_Vec4& scale,
    const Native2183::S16c50_Vec4& minimum, const Native2183::S16c50_Vec4& maximum) {
    Native2183::S16c50_Vec4 temp;
    temp.x = input + offset.x;
    temp.y = input + offset.y;
    temp.z = input + offset.z;
    temp.w = input + offset.w;
    temp.x *= scale.x;
    temp.y *= scale.y;
    temp.z *= scale.z;
    temp.w *= scale.w;
    temp.x = temp.x < maximum.x ? temp.x : maximum.x;
    temp.y = temp.y < maximum.y ? temp.y : maximum.y;
    temp.z = temp.z < maximum.z ? temp.z : maximum.z;
    temp.w = temp.w < maximum.w ? temp.w : maximum.w;
    temp.x = temp.x > minimum.x ? temp.x : minimum.x;
    temp.y = temp.y > minimum.y ? temp.y : minimum.y;
    temp.z = temp.z > minimum.z ? temp.z : minimum.z;
    temp.w = temp.w > minimum.w ? temp.w : minimum.w;
    temp.x += Native2183::DAT_01060db0.x;
    temp.y += Native2183::DAT_01060db0.y;
    temp.z += Native2183::DAT_01060db0.z;
    temp.w += Native2183::DAT_01060db0.w;
    struct Quad { float x,y,z,w; };
    union { Quad q; unsigned int u[4]; } bits;
    bits.q = reinterpret_cast<const Quad&>(temp);
    return (unsigned short)(bits.u[0] >> 7);

}

__forceinline unsigned short convertBox(float input,
    const Native2183::S16c50_Vec4& offset, const Native2183::S16c50_Vec4& scale) {
    Native2183::S16c50_Vec4 minimum; minimum.setZero4();
    Native2183::S16c50_Vec4 maximum = Native2183::DAT_01060dd0;
    return convert996140(input, offset, scale, minimum, maximum);
}

struct FUN_00996140 {
    Base996140 base;
    Bound996140 lowBound, highBound;
    Native2183::S16c50_Vec4 unk40, vec50, vec60, unk70, unk80, unk90;
    Arr996140<f3m_00994260::hkpBpNode> nodes;
    Arr996140<f3m_00994260::hkpBpEndPoint> axes[3];
    int mask, shift;
    Marker996140* markers;
    float correction;
    FUN_00996140(const int* low, const int* high, int count);
};

// pdb: hkp3AxisSweep::hkp3AxisSweep | hkp3AxisSweep.obj | fnv360_0822_retail, objrun_prop, high
// pdb params: worldMin, worldMax, numMarkers
FUN_00996140::FUN_00996140(const int* low, const int* high, int count)
    : lowBound(low), highBound(high)
{
    float lower, upper;
    int logarithm;
    int power, markerCount, index, byteOffset;
    f3m_00994260::hkpBpEndPoint last;
    f3m_00994260::hkpBpNode* root;

    // Fake match: the named argument local preserves the original scratch-register allocation.
    int chosenCount = count ? count : 1;
    findShift996140(chosenCount, logarithm);
    reserve996140(nodes, 255);

    unk40.x = unk40.y = unk40.z = unk40.w = 0.0f;
    vec50.x = vec50.y = vec50.z = vec50.w = 0.0f;
    vec60.x = 1.0f;
    vec60.y = 1.0f;
    vec60.z = 1.0f;
    vec60.w = 1.0f;
    lower = 10.0f;
    upper = 11.0f;

    for (int iteration = 0; iteration < 23; ++iteration) {
        float middle = (upper + lower) * 0.5;
        double mid = middle;
        float input = mid + 1.0f;
        unsigned short output = convertBox(input, vec50, vec60);
        if ((unsigned short)(output | 1) < 12) lower = mid;
        else upper = mid;
    }
    correction = (upper + lower) * 0.5 - 11.0;

    vec60.x = vec60.y = vec60.z = vec60.w = 0.0f;
    unk40.x = unk40.y = unk40.z = unk40.w = 0.0f;
    vec50.x = vec50.y = vec50.z = vec50.w = 0.0f;

    root = &nodes.expandOne();
    f3m_00994260::hkpBpNode& rootRef = *root;
    rootRef.min_z = 0;
    rootRef.min_y = 0;
    rootRef.min_x = 0;
    rootRef.m_handle = 0;

    power = 1 << logarithm;
    reserve996140(axes[0], power + power + 510);
    reserve996140(axes[1], 512);
    reserve996140(axes[2], 512);

    {
    f3m_00994260::hkpBpEndPoint endpoint;
    endpoint.m_nodeIndex = 0;
    endpoint.m_value = 0;
    appendEP996140(axes[0], endpoint);
    appendEP996140(axes[1], endpoint);
    appendEP996140(axes[2], endpoint);

    }
    shift = logarithm;
    markerCount = power - 1;
    mask = markerCount;
    markers = 0;
    if (markerCount) {
        markers = (Marker996140*)((Heap996140*)Native2183::GetTemp())->FUN_008f6f60(markerCount << 4, 0x21);
    }

    index = 0;
    if (index < mask) {
        byteOffset = 0;
        for (; index < mask; ++index, byteOffset += 16) {
            Marker996140* marker = new ((char*)markers + byteOffset) Marker996140;
            f3m_00994260::hkpBpEndPoint endpoint;
            endpoint.m_nodeIndex = (unsigned short)nodes.m_size;
            endpoint.m_value = (unsigned short)((index + 1) << (16 - shift));
            marker->node = endpoint.m_nodeIndex;
            marker->value = endpoint.m_value;
            f3m_00994260::hkpBpNode& node = nodes.expandOne();
            node.min_x = (unsigned short)axes[0].m_size;
            appendEP996140(axes[0], endpoint);
            endpoint.m_value = (unsigned short)(endpoint.m_value | 1);
            node.max_x = (unsigned short)axes[0].m_size;
            appendEP996140(axes[0], endpoint);
            node.m_handle = (f3m_00994260::hkpBroadPhaseHandle*)(unsigned int)(byteOffset | 1);
            node.min_z = 0;
            node.min_y = 0;
            node.max_z = 1;
            node.max_y = 1;
        }
    }

    *root = nodes.m_data[0];
    root->max_x = (unsigned short)axes[0].m_size;
    root->max_y = (unsigned short)axes[1].m_size;
    root->max_z = (unsigned short)axes[2].m_size;

    last.m_nodeIndex = 0;
    last.m_value = 0xfffd;
    appendEP996140(axes[0], last);
    appendEP996140(axes[1], last);
    appendEP996140(axes[2], last);
}
