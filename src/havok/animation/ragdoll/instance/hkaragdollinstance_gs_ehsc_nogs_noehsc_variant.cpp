#include "f3_common.h"
// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaRagdollInstance.h"
struct ArrayAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* buffer, int bytes);
};
struct ArrayRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
};
ArrayRouter* __cdecl FUN_00c85750();
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void assign(const ObjectArray& source)
    {
        ArrayAllocator* heap = FUN_00c85750()->m_pStreamAllocator;
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < source.m_iElementCount)
        {
            if (!(m_iCapacityState & 0x80000000))
                heap->freeBuffer(m_data, capacity * (int)sizeof(T));
            int bytes = source.m_iElementCount * (int)sizeof(T);
            m_data = (T*)heap->allocateBuffer(bytes);
            m_iCapacityState = bytes / (int)sizeof(T);
        }
        m_iElementCount = source.m_iElementCount;
        int count = m_iElementCount;
        T* destination = m_data;
        const T* input = source.m_data;
        for (int i = 0; i < count; ++i)
            destination[i] = input[i];
    }
};
typedef unsigned int hk_size_tR;
class hkMemoryAllocatorR
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterR
{
    void* m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorR* m_pStreamAllocator;
    hkMemoryAllocatorR& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterR& __cdecl GetMemoryRouterR() throw();
void __cdecl hkArrayUtil_reserveR(hkMemoryAllocatorR& kAlloc, void* pkArray, int iNumElements, int iSizeElem) throw();
template <typename T> struct hkArrayR
{
    hkArrayR() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayR() throw()
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtil_reserveR(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackR(int n)
{
    hkMemoryRouterR& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayR : public hkArrayR<T>
{
    __forceinline hkLocalArrayR(int n) throw()
    {
        T* pLocal = hkAllocateStackR<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayR() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackR(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};
class hkReferencedObjectR
{
  public:
    virtual ~hkReferencedObjectR() throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpRigidBodyR : public hkReferencedObjectR
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual hkpRigidBodyR* clone() const throw();
};
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBodyR* pkEntityA, hkpRigidBodyR* pkEntityB, int eCloneMode) const throw();
};
class hkaSkeletonR : public hkReferencedObjectR
{
  public:
    const char* m_name;
    hkArrayR<short> m_kParentIndices;
};
class hkaRagdollInstanceR : public hkReferencedObjectR
{
  public:
    __forceinline void* operator new(hk_size_tR uiBytes)
    {
        hkReferencedObjectR* b =
            static_cast<hkReferencedObjectR*>(GetMemoryRouterR().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, hk_size_tR uiBytes);
    hkaRagdollInstanceR(const hkArrayR<hkpRigidBodyR*>& kRigidBodies,
                        const hkArrayR<hkpConstraintInstanceR*>& kConstraints, const hkaSkeletonR* pkSkeleton,
                        const hkArrayR<int>& kBoneToRigidBodyMap) throw();
    hkaRagdollInstanceR* FUN_00ce2730(int eMode) const throw();
    const hkaSkeletonR* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayR<hkpRigidBodyR*> m_ppRigidBodies;
    hkArrayR<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayR<int> m_kBoneMap;
    const hkaSkeletonR* m_pSkeleton;
};

#include <xmmintrin.h>
// FUN_00ce0d30 - build orthonormal basis from 3 indexed points, convert to quaternion via FUN_00cb26e0

ArrayRouter* __cdecl FUN_00c85750();

struct __declspec(align(16)) Pose32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    int unk18;
    int unk1C;
};
struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};
struct Owner
{
    Pose32* data;
    int count;
    int capacity;
    int unk0C;
    SubObj sub;
    void FUN_00ce0d30(void* pose, Pose32* poseData);
    int FUN_00ce1420(void* pose, int arg2, float time);
};

struct __declspec(align(16)) Quaternion
{
    __m128 value;
    void FUN_00cb26e0(const __m128* matrix);
    void FUN_00c66320(const Quaternion& a, const Quaternion& b);
};
static __m128 cross3(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v));
}
static __declspec(noinline) void FUN_00ce0ff0(SubObj* object, Pose32* pose)
{
    __m128 axis = _mm_load_ps(reinterpret_cast<float*>(object));
    __declspec(align(16)) float absAxis[4];
    _mm_store_ps(absAxis, _mm_andnot_ps(_mm_set1_ps(-0.0f), axis));
    int major;
    if (absAxis[0] > absAxis[1])
        major = absAxis[0] > absAxis[2] ? 0 : 2;
    else
        major = absAxis[1] > absAxis[2] ? 1 : 2;
    __declspec(align(16)) float basis[4] = {0, 0, 0, 0};
    basis[(major + 1) % 3] = 1.0f;
    __m128 vector = _mm_load_ps(basis);
    __m128 q = _mm_load_ps(reinterpret_cast<float*>(pose));
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 d = dot3(q, vector);
    __m128 rotated = _mm_add_ps(_mm_mul_ps(cross3(q, vector), w),
                                _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), _mm_set1_ps(-0.5f)), vector),
                                           _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q)));
    rotated = _mm_add_ps(rotated, rotated);
    __m128 third = cross3(rotated, axis);
    __m128 length = dot3(third, third);
    __m128 inverse = _mm_rsqrt_ss(length);
    inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverse),
                         _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, inverse), inverse)));
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_setzero_ps()), inverse);
    third = _mm_mul_ps(third, _mm_shuffle_ps(inverse, inverse, 0));
    __m128 matrix[3] = {cross3(axis, third), axis, third};
    Quaternion orient;
    orient.FUN_00cb26e0(matrix);
    Quaternion conjugate;
    conjugate.value = _mm_xor_ps(orient.value, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    Quaternion result;
    result.FUN_00c66320(conjugate, *reinterpret_cast<Quaternion*>(pose));
    _mm_store_ps(reinterpret_cast<float*>(pose), result.value);
}

// @f3 0x00960bd0 (community match, verified in this file)
#include <math.h>

struct AxisVec
{
    float x;
    float y;
    float z;
    float w;
};

struct AxisBasis
{
    AxisVec x;
    AxisVec y;
    AxisVec z;
};

struct AxisQuat
{
    AxisVec v;
    void FUN_00924360(const AxisBasis& basis);
    void FUN_008d3290(const AxisQuat& a, const AxisQuat& b);
};

struct FUN_00960090_owner
{
    void FUN_00960090(void* pose, Pose32* poseData);
};

struct PoseCopy
{
    float a;
    float b;
    float c;
    float d;
    int e;
    float f;
};

void __cdecl FUN_00901f10(void* arr, int elemSize);

static __declspec(noinline) void FUN_009604c0(const AxisVec& axis, AxisQuat& rotation)
{
    float side[4];
    side[0] = 0.0f;
    side[1] = 0.0f;
    side[2] = 0.0f;
    float ax = fabsf(axis.x);
    float ay = fabsf(axis.y);
    float az = fabsf(axis.z);
    int major;
    if (ax < ay)
        major = ay < az ? 2 : 1;
    else
        major = ax < az ? 2 : 0;
    side[(major + 1) % 3] = 1.0f;
    const AxisVec& q = rotation.v;
    float w = q.w;
    float factor = w * w - 0.5f;
    float d = q.x * side[0] + q.y * side[1] + q.z * side[2];
    AxisVec scaled;
    scaled.x = side[0] * factor;
    scaled.y = side[1] * factor;
    scaled.z = side[2] * factor;
    scaled.x = scaled.x + d * q.x;
    scaled.y = scaled.y + d * q.y;
    scaled.z = scaled.z + d * q.z;
    AxisVec cross;
    cross.x = q.y * side[2] - q.z * side[1];
    cross.y = q.z * side[0] - q.x * side[2];
    cross.z = q.x * side[1] - q.y * side[0];
    scaled.x = scaled.x + w * cross.x;
    scaled.y = scaled.y + w * cross.y;
    scaled.z = scaled.z + w * cross.z;
    AxisVec r;
    r.x = scaled.x + scaled.x;
    r.y = scaled.y + scaled.y;
    r.z = scaled.z + scaled.z;
    AxisVec up;
    up.x = r.y * axis.z - r.z * axis.y;
    up.y = r.z * axis.x - r.x * axis.z;
    up.z = r.x * axis.y - r.y * axis.x;
    float length = up.x * up.x + up.y * up.y + up.z * up.z;
    float scale = 0.0f;
    if (length != 0.0f)
        scale = 1.0f / sqrtf(length);
    up.x *= scale;
    up.y *= scale;
    up.z *= scale;
    up.w = 0.0f * scale;
    AxisBasis basis;
    basis.x.x = axis.y * up.z - axis.z * up.y;
    basis.x.y = axis.z * up.x - axis.x * up.z;
    basis.x.z = axis.x * up.y - axis.y * up.x;
    basis.x.w = 0.0f;
    basis.y = axis;
    basis.z = up;
    AxisQuat frame;
    frame.FUN_00924360(basis);
    AxisQuat inverse;
    inverse.v.x = -frame.v.x;
    inverse.v.y = -frame.v.y;
    inverse.v.z = -frame.v.z;
    inverse.v.w = frame.v.w;
    AxisQuat composed;
    composed.FUN_008d3290(inverse, rotation);
    rotation = composed;
}

int Owner::FUN_00ce1420(void* pose, int arg2, float time)
{
    Pose32 poseData;
    poseData.unk14 = time;
    poseData.unk10 = arg2;
    ((FUN_00960090_owner*)this)->FUN_00960090(pose, &poseData);
    FUN_009604c0(*(AxisVec*)&sub, *(AxisQuat*)&poseData);
    if (count == (capacity & 0x3FFFFFFF))
        FUN_00901f10(this, 0x20);
    PoseCopy* destination = (PoseCopy*)(data + count);
    PoseCopy* source = (PoseCopy*)&poseData;
    count += 1;
    destination->a = source->a;
    int e = source->e;
    destination->b = source->b;
    destination->c = source->c;
    destination->e = e;
    destination->d = source->d;
    destination->f = source->f;
    return count - 1;
}


extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionCE2;

class hkVector4CE2
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CE2& operator=(const hkVector4CE2& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CE2& v1, const hkVector4CE2& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CE2& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CE2& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCE2& q, const hkVector4CE2& dir);
    void setRotatedInverseDir(const hkQuaternionCE2& q, const hkVector4CE2& dir);
};

struct hkRotationCE2
{
    hkVector4CE2 m_kColumn0;
    hkVector4CE2 m_kColumn1;
    hkVector4CE2 m_kColumn2;
};

struct hkTransformCE2
{
    hkRotationCE2 m_rotation;
    hkVector4CE2 m_vTranslation;
};

class hkQuaternionCE2
{
  public:
    hkVector4CE2 m_vec;

    void set(const hkRotationCE2& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionCE2& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCE2& q0, const hkQuaternionCE2& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4CE2::setRotatedInverseDir(const hkQuaternionCE2& quat, const hkVector4CE2& direction)
{
    hkVector4CE2 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CE2 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CE2 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CE2 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCE2
{
  public:
    hkVector4CE2 m_vTranslation;
    hkQuaternionCE2 m_rotation;
    hkVector4CE2 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformCE2& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4CE2 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformCE2& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformCE2& t1, const hkQsTransformCE2& t2)
    {
        hkVector4CE2 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionC21;

class hkVector4C21
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C21& operator=(const hkVector4C21& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C21& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C21& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C21& v1, const hkVector4C21& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C21& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C21& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC21& q, const hkVector4C21& dir);
    void setRotatedInverseDir(const hkQuaternionC21& q, const hkVector4C21& dir);
};

struct hkRotationC21
{
    hkVector4C21 m_kColumn0;
    hkVector4C21 m_kColumn1;
    hkVector4C21 m_kColumn2;
};

struct hkTransformC21
{
    hkRotationC21 m_rotation;
    hkVector4C21 m_vTranslation;
};

class hkQuaternionC21
{
  public:
    hkVector4C21 m_vec;

    void set(const hkRotationC21& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC21& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC21& q0, const hkQuaternionC21& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4C21::setRotatedInverseDir(const hkQuaternionC21& quat, const hkVector4C21& direction)
{
    hkVector4C21 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C21 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C21 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C21 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC21
{
  public:
    hkVector4C21 m_vTranslation;
    hkQuaternionC21 m_rotation;
    hkVector4C21 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC21& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C21 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformC21& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC21& t1, const hkQsTransformC21& t2)
    {
        hkVector4C21 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct Xf12a0
{
    __m128 t, r, s;
    __forceinline void setIdentity()
    {
        t = _mm_setzero_ps();
        r = _mm_load_ps((const float*)&DAT_010c71b0);
        s = _mm_set1_ps(1.0f);
    }
};
__declspec(align(16)) struct Q4
{
    float x, y, z, w;
};

struct SimdNumber
{
    __m128 value;
    __forceinline SimdNumber(__m128 n) : value(n)
    {}
};
struct MathVec
{
    __m128 value;
    __forceinline SimdNumber dot(const MathVec& other) const
    {
        __m128 products = _mm_mul_ps(value, other.value);
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return SimdNumber(_mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), partial));
    }
    __forceinline void cross(const MathVec& a, const MathVec& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline void rotate(const MathVec& q, const MathVec& b)
    {
        __m128 half = _mm_load_ps((const float*)&DAT_010c71e0);
        __m128 scalar = _mm_shuffle_ps(q.value, q.value, 0xff);
        __m128 factor = _mm_add_ps(half, _mm_mul_ps(scalar, scalar));
        __m128 base = _mm_mul_ps(b.value, factor);
        SimdNumber product = q.dot(b);
        __m128 splat = _mm_shuffle_ps(product.value, product.value, 0);
        base = _mm_add_ps(base, _mm_mul_ps(splat, q.value));
        MathVec crossed;
        crossed.cross(q, b);
        base = _mm_add_ps(base, _mm_mul_ps(scalar, crossed.value));
        value = _mm_add_ps(base, base);
    }
};

extern const float DAT_0104da4c = 1.1920928955078125e-7f;

struct ByteResult
{
    char value;
    ByteResult(bool b) : value(b)
    {}
};

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

class hkQuaternionC18;

class hkVector4C18
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C18& operator=(const hkVector4C18& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C18& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C18& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C18& v1, const hkVector4C18& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C18& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C18& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC18& q, const hkVector4C18& dir);
    void setRotatedInverseDir(const hkQuaternionC18& q, const hkVector4C18& dir);
};

class hkQuaternionC18
{
  public:
    hkVector4C18 m_vec;

    __forceinline void SetConjugate(const hkQuaternionC18& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC18& q0, const hkQuaternionC18& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

class hkQsTransformC18
{
  public:
    hkVector4C18 m_vTranslation;
    hkQuaternionC18 m_rotation;
    hkVector4C18 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC18& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.m_vComponents = _mm_xor_ps(m_vTranslation.m_vComponents, DAT_010c44d0);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C18 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformC18& t1, const hkQsTransformC18& t2)
    {
        hkVector4C18 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(m_vScale.m_vComponents, t1.m_vScale.m_vComponents);
    }
    __forceinline void SetMulInverse(const hkQsTransformC18& a, const hkQsTransformC18& b)
    {
        hkQsTransformC18 h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

// Near miss: two load-register encodings remain under accepted GS- flags and RTM.

struct hkVec4
{
    __m128 m_vComponents;
};
extern const __m128 DAT_01017d10;
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c4c00;
// @fnv 0x00ce0ff0

#include <math.h>

class ScalarLane
{
    __m128 data;

  public:
    ScalarLane(const __m128& v) : data(v)
    {}
    operator float() const
    {
        float scalar;
        _mm_store_ss(&scalar, data);
        return scalar;
    }
};

struct PoseVector
{
    union
    {
        __m128 q;
        float component[4];
    };
    PoseVector()
    {}
    PoseVector(const __m128& v) : q(v)
    {}
    PoseVector(const PoseVector& other) : q(other.q)
    {}
    __forceinline void operator=(const PoseVector& other)
    {
        q = other.q;
    }
    ScalarLane dot(const PoseVector& other) const
    {
        __m128 product = _mm_mul_ps(q, other.q);
        __m128 pair = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
        __m128 swapped = _mm_shuffle_ps(pair, pair, 0xb1);
        return _mm_add_ps(pair, swapped);
    }
    __forceinline void cross(const PoseVector& a, const PoseVector& b)
    {
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2)),
                       _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9)));
    }
    __forceinline void normalize()
    {
        __m128 square = _mm_mul_ps(q, q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
        __m128 length = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), xy);
        __m128 estimate = _mm_rsqrt_ss(length);
        __m128 zero = _mm_cmpeq_ss(length, _mm_setzero_ps());
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
        __m128 scale = _mm_andnot_ps(zero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction));
        q = _mm_mul_ps(q, _mm_shuffle_ps(scale, scale, 0));
    }
};

struct PoseBasis
{
    PoseVector x, y, z;
};
struct PoseRotation
{
    PoseVector vector;
    PoseRotation()
    {}
    __forceinline void operator=(const PoseRotation& other)
    {
        vector = other.vector;
    }
    void FUN_00cb26e0(const PoseBasis& basis);
    void FUN_00c66320(const PoseRotation& a, const PoseRotation& b);
};

extern "C"
{
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionC17;

class hkVector4C17
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C17& operator=(const hkVector4C17& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C17& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C17& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C17& v1, const hkVector4C17& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C17& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C17& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC17& q, const hkVector4C17& dir);
    void setRotatedInverseDir(const hkQuaternionC17& q, const hkVector4C17& dir);
};

struct hkRotationC17
{
    hkVector4C17 m_kColumn0;
    hkVector4C17 m_kColumn1;
    hkVector4C17 m_kColumn2;
};

struct hkTransformC17
{
    hkRotationC17 m_rotation;
    hkVector4C17 m_vTranslation;
};

class hkQuaternionC17
{
  public:
    hkVector4C17 m_vec;

    void set(const hkRotationC17& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC17& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void FUN_00c66320(const hkQuaternionC17& q0, const hkQuaternionC17& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 aw = _mm_shuffle_ps(a, a, 0xff);
        __m128 bw = _mm_shuffle_ps(b, b, 0xff);
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

class hkQsTransformC17
{
  public:
    hkVector4C17 m_vTranslation;
    hkQuaternionC17 m_rotation;
    hkVector4C17 m_vScale;

    __declspec(noinline) void FUN_00ce5070(const hkTransformC17& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC17& t1, const hkQsTransformC17& t2)
    {
        hkVector4C17 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

#include <xmmintrin.h>
namespace fnv_00ce1ad0 {
#include <xmmintrin.h>

extern __declspec(align(16)) float DAT_01267e30;
extern __declspec(align(16)) const float DAT_010c71e0;
extern __declspec(align(16)) const float DAT_01017d10;

struct __declspec(align(16)) FUN_005611c0_t;

struct __declspec(align(16)) hkVec4
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }
    void set(__m128 v)
    {
        reinterpret_cast<__m128&>(x) = v;
    }

    void SetRotatedDirection(const FUN_005611c0_t& quat, const hkVec4& direction);
    void setAdd4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_add_ps(a.get(), b.get()));
    }
    void setMul4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_mul_ps(a.get(), b.get()));
    }
    bool equals4(const float* v) const
    {
        __m128 t = _mm_and_ps(_mm_sub_ps(_mm_load_ps(v), get()), _mm_load_ps(&DAT_01017d10));
        __m128 eps = _mm_set1_ps(1e-3f);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
    }
};

struct __declspec(align(16)) FUN_005611c0_t
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }

    void FUN_00c66320(const FUN_005611c0_t* q0, const FUN_005611c0_t* q1);
    void FUN_005611c0();
};

struct RagQsTransform
{
    hkVec4 m_vTranslation;
    FUN_005611c0_t m_rotation;
    hkVec4 m_vScale;

    __forceinline void SetProduct(const RagQsTransform& t1, const RagQsTransform& t2)
    {
        hkVec4 extraTrans;
        extraTrans.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(extraTrans, t1.m_vTranslation);
        m_rotation.FUN_00c66320(&t1.m_rotation, &t2.m_rotation);
        m_vScale.set(_mm_mul_ps(_mm_load_ps(&t1.m_vScale.x), t2.m_vScale.get()));
    }
};

struct RagMotion
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void SetTranslationalVelocity(const float* v);
    virtual void SetRotationalVelocity(const float* v);
};

struct UnkCall
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    RagMotion m_pMotionState;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    __m128 m_kTranslationalVelocity;
    __m128 m_kAngularVelocity;

    void FUN_00c9c1d0();
    void hkpRigidBody_setPositionAndRotation(const hkVec4* pos, const FUN_005611c0_t* rot);

    void SetTranslationalVelocity(const float* v)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(v);
    }
    void SetRotationalVelocity(const float* v)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(v);
    }
};

struct RagSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_kBones;
    int m_iBoneCount;
};

struct RagInstance
{
    int unk00;
    int unk04;
    UnkCall** m_ppRigidBodies;
    int m_iRigidBodyCount;
    int m_rigidBodiesCap;
    void** m_ppConstraints;
    int m_iConstraintCount;
    int m_constraintsCap;
    int* m_kBoneMap;
    int m_numMap;
    int m_mapCap;
    RagSkeleton* m_pSkeleton;

    UnkCall* getRigidBodyOfBone(int b) const
    {
        int rbIdx = m_kBoneMap[b];
        if (rbIdx < 0)
            return 0;
        return m_ppRigidBodies[rbIdx];
    }

    void FUN_00ce1ad0(const RagQsTransform* pose, const RagQsTransform& worldFromModel);
};

}  // namespace fnv_00ce1ad0
