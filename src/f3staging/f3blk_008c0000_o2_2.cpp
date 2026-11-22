#include <windows.h>
// src/f3staging/f3blk_008c0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008d2ea0 (community match, verified in this file)
extern const char str_00e31f50[],str_00e31f48[],str_00e31f34[],str_00e31f18[];
namespace f3m_008d2ea0 {
namespace nested_reflected_float_copy {
struct hkClass;
struct hkVariant { void* object;const hkClass* type; };
struct hkClassMember { const hkClass* FUN_0093d890() const; };
struct hkClassMemberAccessor {
    void* object;const hkClassMember* member;
    hkClassMemberAccessor(const hkVariant&,const char*);
    const hkClassMember* FUN_0093d790() const;
    void* FUN_0093d660();
    float* FUN_0093d6a0(int);
};
static __declspec(noinline) void FUN_008d2ea0(const hkVariant& source,const hkVariant& destination) {
    hkClassMemberAccessor from(source,str_00e31f48),to(destination,str_00e31f48);
    hkVariant fromValue;fromValue.type=from.FUN_0093d790()->FUN_0093d890();fromValue.object=from.FUN_0093d660();
    hkVariant toValue;toValue.type=to.FUN_0093d790()->FUN_0093d890();toValue.object=to.FUN_0093d660();
    hkClassMemberAccessor oldField(fromValue,str_00e31f34),newField(toValue,str_00e31f18);
    *newField.FUN_0093d6a0(0)=*oldField.FUN_0093d6a0(0);
}
void FUN_008d2f50(const hkVariant& source,const hkVariant& destination) {
    hkClassMemberAccessor from(source,str_00e31f50),to(destination,str_00e31f50);
    hkVariant fromValue;fromValue.type=from.FUN_0093d790()->FUN_0093d890();fromValue.object=from.FUN_0093d660();
    hkVariant toValue;toValue.type=to.FUN_0093d790()->FUN_0093d890();toValue.object=to.FUN_0093d660();
    FUN_008d2ea0(fromValue,toValue);
}
}
}   // namespace f3m_008d2ea0

// @f3 0x008d3290 (community match, verified in this file)
namespace f3m_008d3290 {
struct __declspec(align(16)) QhkVec4 {
    float x, y, z, w;
    __forceinline void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    __forceinline void setCross(const QhkVec4& v1, const QhkVec4& v2) {
        const float nx = v1.y * v2.z - v1.z * v2.y;
        const float ny = v1.z * v2.x - v1.x * v2.z;
        const float nz = v1.x * v2.y - v1.y * v2.x;
        set(nx, ny, nz, 0.0f);
    }
    __forceinline void addMul4(float r, const QhkVec4& a) {
        x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w;
    }
    __forceinline float dot3(const QhkVec4& a) const { return x * a.x + y * a.y + z * a.z; }
};

struct QhkQuat {
    QhkVec4 m_vec;
    void FUN_008d3290(const QhkQuat& q0, const QhkQuat& q1);
};

// pdb: hkQsTransform::setFromTransformNoScale | hkQsTransform.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkQuaternion::setMul)
// pdb params: transform
void QhkQuat::FUN_008d3290(const QhkQuat& q0, const QhkQuat& q1)
{
    QhkVec4 vec;
    vec.setCross(q0.m_vec, q1.m_vec);
    vec.addMul4(q0.m_vec.w, q1.m_vec);
    vec.addMul4(q1.m_vec.w, q0.m_vec);
    float w = q1.m_vec.w;
    w = w * q0.m_vec.w - q0.m_vec.dot3(q1.m_vec);
    for (int i = 0; i < 4; i++) (&m_vec.x)[i] = (&vec.x)[i];
    m_vec.w = w;
}
}   // namespace f3m_008d3290
