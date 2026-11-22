#include <new>
// src/f3staging/f3iso_00955ac0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00955ac0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00955ac0 (community match, verified in this file)
namespace f3m_00955ac0 {
namespace pose_constraints {
typedef float hkReal;

struct hkQuaternion;


struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }

    __forceinline void add4(const hkVector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = v.w;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
    __forceinline void setMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    __forceinline void addMul4(hkReal rs, const hkVector4& a)
    {
        hkReal r = rs;
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline hkReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
        const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
        const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
        set(nx, ny, nz, 0);
    }
    
    __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline hkReal getReal() const { return m_vec.w; }
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}


struct hkQsTransform
{
    hkVector4 m_translation;
    hkQuaternion m_rotation;
    hkVector4 m_scale;
};

template <typename T>
struct hkArray
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline int getSize() const { return m_size; }
};

struct hkaBone
{
    char* m_name;
    bool m_lockTranslation;
};

struct hkaSkeleton
{
    char* m_name;
    short* m_parentIndices;
    int m_numParentIndices;
    hkaBone** m_bones;
    int m_numBones;
    hkQsTransform* m_referencePose;
    int m_numReferencePose;
};

class hkaPose {
public:
    enum { BoneModelDirty = 2, BoneChanged = 4, InternalFlags = 0x1c };

    const hkaSkeleton* m_skeleton;
    mutable hkArray<hkQsTransform> m_localPose;
    mutable hkArray<hkQsTransform> m_modelPose;
    mutable hkArray<unsigned> m_boneFlags;
    mutable bool m_modelInSync, m_localInSync;

    void hkaPose_syncLocalSpace() const;
    void hkaPose_syncModelSpace() const;
    hkArray<hkQsTransform>& FUN_00954fc0();
    hkArray<hkQsTransform>& FUN_00955ab0();
    void FUN_00955ac0();

    inline unsigned flagged(int index, unsigned flag) const {
        return m_boneFlags[index] & flag;
    }
    inline void setFlag(int index, unsigned flag) const {
        m_boneFlags[index] |= flag;
    }
    inline void clearInternalFlags() const {
        const int count = m_boneFlags.getSize();
        for (int i = 0; i < count; ++i)
            m_boneFlags[i] &= ~InternalFlags;
    }
};
}
void pose_constraints::hkaPose::FUN_00955ac0()
{
    const int count = m_skeleton->m_numBones;
    hkaPose_syncLocalSpace();
    for (int i = 0; i < count; ++i) {
        if (m_skeleton->m_bones[i]->m_lockTranslation) {
            m_localPose[i].m_translation = m_skeleton->m_referencePose[i].m_translation;
            setFlag(i, BoneModelDirty);
            setFlag(i, BoneChanged);
        } else {
            const short parent = m_skeleton->m_parentIndices[i];
            if (parent != -1 && flagged(parent, BoneChanged)) {
                setFlag(i, BoneModelDirty);
                setFlag(i, BoneChanged);
            }
        }
    }
    clearInternalFlags();
}
}   // namespace f3m_00955ac0
