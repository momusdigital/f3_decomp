#include <new>
// src/f3staging/f3iso_0090de30_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0090de30 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0090de30 (community match, verified in this file)
namespace f3m_0090de30 {
namespace phantom_bounds {
struct Shape {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void getAabb(const void*,float,void*) const;
};
    struct CollisionInput {
        void* dispatcher;
        float tolerance;
    };
    struct World {
        char beforeCollisionInput[0x6c];
        const CollisionInput* collisionInput;
    };
struct ShapePhantom {
        char beforeWorld[8];
        const World* world;
        char beforeShape[4];
        Shape* shape;
        char beforeTransform[0xa0 - 0x14];
        float transform[4][4];
        void hkpShapePhantom_calcAabb(void* aabbOut) const;
    };


// pdb: hkpShapePhantom::calcAabb | hkpShapePhantom.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void ShapePhantom::hkpShapePhantom_calcAabb(void* aabbOut) const {
    shape->getAabb(&transform,static_cast<float>(world->collisionInput->tolerance*0.5),aabbOut);
}
}
}   // namespace f3m_0090de30
