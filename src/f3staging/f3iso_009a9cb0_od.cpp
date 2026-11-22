#include <new>
// src/f3staging/f3iso_009a9cb0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009a9cb0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009a9cb0 (community match, verified in this file)
#include <math.h>
namespace MotionIntegration009a9cb0 {







namespace N9ac100 {

typedef float Real;
typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef unsigned int UInt32;

extern float DAT_00e35180[256];   

namespace Math {
inline Real sqrt(Real r) { return sqrtf(r); }
inline Real sqrtInverse(Real r) { Real s = Math::sqrt(r); return 1.0f / s; }
inline Real fabs(Real r) { return fabsf(r); }
inline Real min2(Real x, Real y) { return x < y ? x : y; }
inline Real max2(Real x, Real y) { return x > y ? x : y; }
inline int min2(int x, int y) { return x < y ? x : y; }
inline int max2(int x, int y) { return x > y ? x : y; }
}

template <class T>
class Pad
{
  public:
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return val(); }

  private:
    T m_storage;
};

class Comparison
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };
    __forceinline int getMask() const { return m_mask; }
    int m_mask;
};

class Rotation;
class Quaternion;

class Vec4
{
  public:
    __forceinline Vec4() {}
    __forceinline void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline Real& operator()(int i) { return (&x)[i]; }
    __forceinline const Real& operator()(int i) const { return (&x)[i]; }

    void hkVector4_setRotatedDir(const Rotation& r, const Vec4& v);   
    void FUN_00477880(const Rotation& r, const Vec4& v);   
    __forceinline void _setRotatedDir(const Rotation& r, const Vec4& v);

    __forceinline void setReciprocal4(const Vec4& v) { x = 1.0f / v.x; y = 1.0f / v.y; z = 1.0f / v.z; w = 1.0f / v.w; }
    __forceinline void mul4(const Vec4& v) { (*this)(0) *= v(0); (*this)(1) *= v(1); (*this)(2) *= v(2); (*this)(3) *= v(3); }
    __forceinline void mul4(Real rs) { Real s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline void setMul4(Real r, const Vec4& v) { x = r * v.x; y = r * v.y; z = r * v.z; w = r * v.w; }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void addMul4(Real r, const Vec4& v) { x += r * v.x; y += r * v.y; z += r * v.z; w += r * v.w; }
    __forceinline void setAbs4(const Vec4& v) { x = Math::fabs(v.x); y = Math::fabs(v.y); z = Math::fabs(v.z); w = Math::fabs(v.w); }
    __forceinline Real lengthSquared3() const { return x * x + y * y + z * z; }
    
    
    __forceinline Real lengthSquared3p() const { const Real* p = &x; return p[0] * p[0] + p[1] * p[1] + p[2] * p[2]; }
    __forceinline Real dot4(const Vec4& a) const { return x * a.x + y * a.y + z * a.z + w * a.w; }
    __forceinline void zeroElement(int i) { (*this)(i) = 0.0f; }
    __forceinline Comparison compareLessThan4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x < v.x) ? 8 : 0;
        int my = (y < v.y) ? 4 : 0;
        int mz = (z < v.z) ? 2 : 0;
        int mw = (w < v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }
    __forceinline Comparison compareEqual4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x == v.x) ? 8 : 0;
        int my = (y == v.y) ? 4 : 0;
        int mz = (z == v.z) ? 2 : 0;
        int mw = (w == v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }

    __declspec(align(16)) Real x;
    Real y;
    Real z;
    Real w;
};

extern Vec4 DAT_01061120;   
extern Vec4 DAT_010f3370;   

class Rotation
{
  public:
    __forceinline const Vec4& getColumn(int i) const { return (&m_col0)[i]; }
    void hkRotation_set(const Quaternion& q);   

    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
};

class Transform
{
  public:
    __forceinline Rotation& getRotation() { return m_rotation; }
    __forceinline const Rotation& getRotation() const { return m_rotation; }
    __forceinline Vec4& getTranslation() { return m_translation; }
    __forceinline void setRotation(const Quaternion& q) { m_rotation.hkRotation_set(q); }
    __forceinline static const Vec4& getIdentityColumn0() { return DAT_010f3370; }

    Rotation m_rotation;
    Vec4 m_translation;
};

__forceinline void Vec4::_setRotatedDir(const Rotation& r, const Vec4& v)
{
    Real v0 = v.x;
    Real v1 = v.y;
    Real v2 = v.z;
    x = r.m_col0.x * v0 + r.m_col1.x * v1 + r.m_col2.x * v2;
    y = r.m_col0.y * v0 + r.m_col1.y * v1 + r.m_col2.y * v2;
    z = r.m_col0.z * v0 + r.m_col1.z * v1 + r.m_col2.z * v2;
    w = 0.0f;
}

class Quaternion
{
  public:
    void FUN_008d3290(const Quaternion& r, const Quaternion& q);   
    void FUN_004e5c20();                                           

    Vec4 m_vec;
};

UInt32 __cdecl hkVector4Util_packQuaternionIntoInt32(const Vec4& q);   

class SweptTransform
{
  public:
    Vec4 m_centerOfMass0;      
    Vec4 m_centerOfMass1;      
    Quaternion m_rotation0;
    Quaternion m_rotation1;
    Vec4 m_centerOfMassLocal;
};

class UFloat8
{
  public:
    __forceinline operator float() const { return DAT_00e35180[m_value]; }
    UInt8 m_value;
};

class MotionState
{
  public:
    __forceinline Transform& getTransform() { return m_transform; }
    __forceinline const Transform& getTransform() const { return m_transform; }
    __forceinline SweptTransform& getSweptTransform() { return m_sweptTransform; }
    __forceinline const SweptTransform& getSweptTransform() const { return m_sweptTransform; }

    Transform m_transform;
    SweptTransform m_sweptTransform;
    Vec4 m_deltaAngle;
    Real m_objectRadius;
    Real m_linearDamping;
    Real m_angularDamping;
    UFloat8 m_maxLinearVelocity;
    UFloat8 m_maxAngularVelocity;
    UInt8 m_deactivationClass;
};

class Motion
{
  public:
    enum MotionType
    {
        MOTION_INVALID,
        MOTION_DYNAMIC,
        MOTION_SPHERE_INERTIA,
        MOTION_STABILIZED_SPHERE_INERTIA,
        MOTION_BOX_INERTIA,
        MOTION_STABILIZED_BOX_INERTIA,
        MOTION_KEYFRAMED,
        MOTION_FIXED,
        MOTION_THIN_BOX_INERTIA,
        MOTION_CHARACTER
    };
    __forceinline const Transform& getTransform() const { return m_motionState.getTransform(); }
    __forceinline int getNumInactiveFrames(int select) { return m_deactivationNumInactiveFrames[select] & 0x7f; }
    __forceinline void incrementNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        int newdc = dc + 1 - (dc >> 6);
        dc = newdc | (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }
    __forceinline void zeroNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        dc = (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }

    void* m_vtable;
    UInt16 m_memSizeAndFlags;
    short m_referenceCount;
    UInt8 m_type;
    UInt8 m_deactivationIntegrateCounter;
    UInt16 m_deactivationNumInactiveFrames[2];
    MotionState m_motionState;
    Vec4 m_inertiaAndMassInv;
    Vec4 m_linearVelocity;
    Vec4 m_angularVelocity;
    Vec4 m_deactivationRefPosition[2];
    UInt32 m_deactivationRefOrientation[2];
};

class StepInfo
{
  public:
    Pad<Real> m_startTime;
    Pad<Real> m_endTime;
    Pad<Real> m_deltaTime;
    Pad<Real> m_invDeltaTime;
};

__forceinline void calcTransAtT1(const SweptTransform& sweptTrans, Transform& transformOut)
{
    const Quaternion& qt = sweptTrans.m_rotation1;
    transformOut.setRotation(qt);
    Vec4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

__forceinline void clipVelocities(const MotionState& motionState, Vec4& linearVelocity, Vec4& angularVelocity)
{
    Real linVelSq = linearVelocity.lengthSquared3();
    Real angVelSq = angularVelocity.lengthSquared3p();
    const Real maxLinear = motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity;
    const Real maxAngular = motionState.m_maxAngularVelocity * motionState.m_maxAngularVelocity;
    if ((linVelSq > maxLinear) || (linVelSq != linVelSq))
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
        if (linVelSq != linVelSq)
        {
            linearVelocity = Transform::getIdentityColumn0();
        }
    }
    if ((angVelSq > maxAngular) || (angVelSq != angVelSq))
    {
        Real f = motionState.m_maxAngularVelocity * Math::sqrtInverse(angVelSq);
        angularVelocity.mul4(f);
        if (angVelSq != angVelSq)
        {
            angularVelocity = Transform::getIdentityColumn0();
        }
    }
}

__forceinline void stepMotionState(const StepInfo& info, Vec4& linearVelocity, Vec4& angularVelocity,
                                   MotionState& motionState)
{
    {
        
        Vec4 absLin;
        absLin.setAbs4(linearVelocity);
        Vec4 absAng;
        absAng.setAbs4(angularVelocity);

        int mask = absLin.compareLessThan4(DAT_01061120).getMask() & absAng.compareLessThan4(DAT_01061120).getMask();
        mask &= linearVelocity.compareEqual4(linearVelocity).getMask() &
                angularVelocity.compareEqual4(angularVelocity).getMask();
        if ((mask & Comparison::MASK_XYZ) != Comparison::MASK_XYZ)
        {
            linearVelocity = Transform::getIdentityColumn0();
            angularVelocity = Transform::getIdentityColumn0();
        }
    }

    motionState.getSweptTransform().m_centerOfMass0 = motionState.getSweptTransform().m_centerOfMass1;
    motionState.getSweptTransform().m_centerOfMass0(3) = info.m_startTime;

    Real linVelSq = linearVelocity.lengthSquared3();
    if (linVelSq > motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity)
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
    }

    motionState.getSweptTransform().m_centerOfMass1.addMul4(info.m_deltaTime, linearVelocity);
    motionState.getSweptTransform().m_centerOfMass1(3) = info.m_invDeltaTime;

    Quaternion newRotation = motionState.getSweptTransform().m_rotation1;
    motionState.getSweptTransform().m_rotation0 = newRotation;

    Real angle;
    {
        Quaternion rotationRadians;
        rotationRadians.m_vec.setMul4(info.m_deltaTime * 0.5f, angularVelocity);
        const Real pi = 3.14159265358979f;
        Real numHalfRotations2 = rotationRadians.m_vec.lengthSquared3() * (4.0f / (pi * pi));

        const Real a = 0.822948f;
        const Real b = 0.130529f;
        const Real c = 0.044408f;

        const Real maxAnglePerStep = Math::min2(0.9f, info.m_deltaTime.val() * motionState.m_maxAngularVelocity);

        if (numHalfRotations2 <= maxAnglePerStep * maxAnglePerStep)
        {
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }
        else
        {
            Real factor = maxAnglePerStep * Math::sqrtInverse(numHalfRotations2);
            angularVelocity.mul4(factor);
            rotationRadians.m_vec.mul4(factor);

            numHalfRotations2 = maxAnglePerStep * maxAnglePerStep;
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }

        newRotation.FUN_008d3290(rotationRadians, newRotation);
        newRotation.FUN_004e5c20();

        motionState.m_deltaAngle.setAdd4(rotationRadians.m_vec, rotationRadians.m_vec);
        angle = Math::sqrt(numHalfRotations2) * pi;
        motionState.m_deltaAngle(3) = angle;
    }
    motionState.getSweptTransform().m_rotation1 = newRotation;
    calcTransAtT1(motionState.getSweptTransform(), motionState.getTransform());
}


}
}
// The integration types and inline helper are from the shared motion unit.
// pdb: hkRigidMotionUtilStep | hkpRigidMotionUtil.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_seq) + skyrim(call_gap), high
void __cdecl hkRigidMotionUtilStep(const MotionIntegration009a9cb0::N9ac100::StepInfo& info,
                         void* const* objects, int count, int motionOffset)
{
    using namespace MotionIntegration009a9cb0::N9ac100;
    for (int remaining = count - 1; remaining >= 0; --remaining)
    {
        Motion* motion = reinterpret_cast<Motion*>(
            static_cast<char*>(*objects) + motionOffset);
        stepMotionState(info, motion->m_linearVelocity,
                        motion->m_angularVelocity, motion->m_motionState);
        ++objects;
    }
}
