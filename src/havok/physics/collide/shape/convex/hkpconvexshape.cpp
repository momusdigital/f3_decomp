#include "f3_common.h"
// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexShape.h"

// @fnv 0x00c9e1e0
// pdb: hkArrayBase<hkaDetectRagdollPenetration::BonePenetration>::getCapacity | bhkRagdollPenetrationUtil.obj | fnv360_0822_debug, objrun_open, low
int __stdcall FUN_00c9e1e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 2;
}

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectC9E3
{
  public:
    hkReferencedObjectC9E3() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC9E3() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpShapeC9E3 : public hkReferencedObjectC9E3
{
  public:
    hkpShapeC9E3(int iType) : m_ulUserData(0), m_type(iType)
    {}
    hkUlong m_ulUserData;
    int m_type;
};

class hkpConvexShapeC9E3 : public hkpShapeC9E3
{
  public:
    hkpConvexShapeC9E3(int iType, hkReal fRadius) : hkpShapeC9E3(iType)
    {
        m_fSphereRadius = fRadius;
    }
    hkReal m_fSphereRadius;
};

class hkpShapeContainerC9E3
{
  public:
    virtual ~hkpShapeContainerC9E3() throw()
    {}
};

class hkpSingleShapeContainerC9E3 : public hkpShapeContainerC9E3
{
  public:
    hkpSingleShapeContainerC9E3(FUN_00d1df70* pkChild, int iRef) : m_pContainedShape(pkChild)
    {
        if (iRef == 1)
            m_pContainedShape->FUN_00c90510();
    }
    virtual ~hkpSingleShapeContainerC9E3() throw();
    FUN_00d1df70* m_pContainedShape;
};

#include <xmmintrin.h>
class hkClass;
class hkStatisticsCollector;
// hkBool
struct hkBoolC9E
{
    char m_bool;
    hkBoolC9E(bool b) : m_bool((char)b) {}
};
// hkpConvexShape: the sixteen slots of the Fallout 3 vtables of its subclasses (hkpSphereShape 0x00e7c8d4: slot 3 is
// this function, 4 casts a ray through slot 8 and transforms the hit for a collector, 5 returns no container, 9 returns
// one sphere, 12 writes a supporting vertex, 14 returns WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED), named as the New
// Vegas Xbox 360 PDB names them.
struct S00c9e1f0_Obj
{
    virtual ~S00c9e1f0_Obj();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual float getMaximumProjection(int direction) const;
    virtual void castRayWithCollectorImpl(const void* input, const void* cdBody, void* collector) const;
    virtual const void* getContainer() const;
    virtual int calcSizeForSpu(const void* input, int spuBufferSizeLeft) const;
    virtual void getAabbImpl(const void* localToWorld, float tolerance, void* out) const;
    virtual hkBoolC9E castRayImpl(const void* input, void* results) const;
    virtual int getNumCollisionSpheresImpl() const;
    virtual const void* getCollisionSpheresImpl(void* sphereBuffer) const;
    virtual void getFirstVertex(float* v) const;
    virtual void getSupportingVertexImpl(int direction, float* supportingVertexOut) const;

    float unk04;
    float unk08;
    float unk0C;
    float m_10;

    float GetDotProductOffset(int arg);
};

// Returns the radius (m_10) plus the projection of the supporting vertex in the direction onto that direction.
// @f3 0x00916f60 (community match, verified in this file)
float S00c9e1f0_Obj::GetDotProductOffset(int arg)
{
    __declspec(align(16)) float v[4];
    getSupportingVertexImpl(arg, v);
    const float* a = reinterpret_cast<const float*>(arg);
    float dot = a[1] * v[1] + a[0] * v[0] + a[2] * v[2];
    float result = dot + m_10;
    return result;
}


struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Mat3
{
    Vec4 c0, c1, c2;
};

struct P2
{
    int unk0;
    int unk1;
    Mat3* m;
};

struct Cb;

struct VTable
{
    void(__thiscall* fn)(Cb*, P2*, Vec4*);
};

struct Cb
{
    VTable* vt;
    float f;
};
