#include <new>
// src/f3staging/f3iso_0097dab0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0097dab0 alone: its served file declares the class differently from the original.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0097dab0 (community match, verified in this file)
namespace f3m_0097dab0 {
namespace list_shape_97 {
struct Shape;
struct Entry {
    Shape* shape;
    int filter;
    int reserved;
    int count;
};
struct ChildArray {
    Entry* data;
    int count;
    unsigned int capacityFlags;
    ChildArray() : data(0), count(0), capacityFlags(0x80000000u) {}
};
struct ShapeBase {
    virtual void Destroy();
    unsigned short allocationSize, references;
    int userData, shapeType;
};
struct ShapeContainer {
    virtual void DestroyContainer();
    unsigned char flags;
};
struct FUN_0099f010 : ShapeBase, ShapeContainer {
    FUN_0099f010(int type);
};
void __cdecl FUN_00901e90(void* array, int capacity, int elementSize);
__forceinline void ReserveChildren(ChildArray& children, int requested) {
    const int capacity = children.capacityFlags & 0x3fffffff;
    if (capacity < requested) {
        const int grown = 2 * capacity;
        FUN_00901e90(&children, requested < grown ? grown : requested, sizeof(Entry));
    }
}
struct FUN_0097dab0 : FUN_0099f010 {
    ChildArray children;
    unsigned int state[3];
    float halfExtents[4], center[4];
    int childIds[8];
    FUN_0097dab0(Shape** shapes, int count);
    void FUN_0097adb0(Shape** shapes, int count, int* filters);
    void FUN_0097aae0();
};
// pdb: hkpListShape::hkpListShape | hkpListShape.obj | fnv360_0822_retail, caller_sim, high
// pdb params: shapeArray, numShapes, ref
FUN_0097dab0::FUN_0097dab0(Shape** shapes, int count) : FUN_0099f010(10) {
    ReserveChildren(children, 4);
    FUN_0097adb0(shapes, count, 0);
    FUN_0097aae0();
    for (int i = 0; i < 8; ++i)
        childIds[i] = -1;
}
}

}   // namespace f3m_0097dab0
