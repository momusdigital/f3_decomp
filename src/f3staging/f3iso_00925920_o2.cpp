#include <new>
// src/f3staging/f3iso_00925920_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00925920 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00925920 (community match, verified in this file)
namespace f3m_00925920 {
struct __declspec(align(16)) Vector4 { float x,y,z,w; };
struct Transform {
    Vector4 rotation[3], translation;
    void hkRotation_set(const Vector4*);
};
struct Frame;
struct FrameMethods {
    void* preceding[51];
    void (__thiscall *translation)(Frame*,Vector4*);
    void (__thiscall *rotation)(Frame*,Vector4*);
};
struct Frame {
    FrameMethods* methods;
    Transform* FUN_00925920(Transform*);
};
// pdb: bhkRigidBodyT::GetTransform | bhkRigidBodyT.obj | fnv360_0822_retail, objrun, medium
// pdb params: arTrans
Transform* Frame::FUN_00925920(Transform* result) {
    Vector4 rotation;
    methods->translation(this,&result->translation);
    methods->rotation(this,&rotation);
    result->hkRotation_set(&rotation);
    return result;
}
}   // namespace f3m_00925920
