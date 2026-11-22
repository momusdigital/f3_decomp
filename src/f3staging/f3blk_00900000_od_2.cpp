#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_00900000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00918e70 (community match, verified in this file)
namespace f3m_00918e70 {
namespace f3m_00918e70 {

typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef hkUint32 hkpShapeKey;

class hkBool
{
public:
    inline hkBool() { }
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
    inline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
private:
    char m_bool;
};

class hkVector4
{
public:
    __forceinline hkVector4() { }
    __forceinline hkVector4(const hkVector4& v);
    __forceinline void operator=(const hkVector4& v);
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, hkReal t);
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
public:
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};
inline hkReal& hkVector4::operator()(int i)
{
    return (&x)[i];
}
inline const hkReal& hkVector4::operator()(int i) const
{
    return (&x)[i];
}
inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}
inline hkVector4::hkVector4(const hkVector4& v)
{
    *this = v;
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkReal t)
{
    hkReal s = 1.0f - t;
    hkVector4& d = *this;
    d(0) = s * v0(0) + t * v1(0);
    d(1) = s * v0(1) + t * v1(1);
    d(2) = s * v0(2) + t * v1(2);
    d(3) = s * v0(3) + t * v1(3);
}

template <typename T>
class hkArray
{
public:
    enum { DONT_DEALLOCATE_FLAG = int(0x80000000) };
    __forceinline hkArray(T* ptr, int size, int capacity);
    __forceinline const T& operator[](int i) const;
    __forceinline int getSize() const;
    __forceinline void clear();
protected:
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};
template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
    : m_data(ptr),
      m_size(size),
      m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline const T& hkArray<T>::operator[](int i) const
{
    return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
    return m_size;
}
template <typename T>
__forceinline void hkArray<T>::clear()
{
    m_size = 0;
}

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
public:
    __forceinline hkInplaceArray(int size = 0) : hkArray<T>(m_storage, size, N) { }
public:
    T m_storage[N];
};

class hkpShape;
class hkpCdBody
{
public:
    const hkpShape* m_shape;
    hkpShapeKey m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

class hkpBroadPhaseHandle
{
public:
    hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:
    __forceinline int getType() const;
    __forceinline hkUint32 getCollisionFilterInfo() const;
public:
    hkInt8 m_type;
    hkInt8 m_ownerOffset;
    hkUint16 m_objectQualityType;
    hkUint32 m_collisionFilterInfo;
};
int hkpTypedBroadPhaseHandle::getType() const
{
    return m_type;
}
hkUint32 hkpTypedBroadPhaseHandle::getCollisionFilterInfo() const
{
    return m_collisionFilterInfo;
}

class hkpCollidable : public hkpCdBody
{
public:
    inline void* getOwner() const
    {
        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
    }
    __forceinline hkUint32 getCollisionFilterInfo() const;
    __forceinline int getType() const;
public:
    hkInt8 m_ownerOffset;
    hkUint8 m_forceCollideOntoPpu;
    hkUint16 m_shapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle;
};
int hkpCollidable::getType() const
{
    return m_broadPhaseHandle.getType();
}
hkUint32 hkpCollidable::getCollisionFilterInfo() const
{
    return m_broadPhaseHandle.getCollisionFilterInfo();
}

class hkpWorld;
class hkpWorldObject
{
public:
    enum BroadPhaseType
    {
        BROAD_PHASE_INVALID,
        BROAD_PHASE_ENTITY,
        BROAD_PHASE_PHANTOM,
        BROAD_PHASE_BORDER,
        BROAD_PHASE_MAX_ID
    };
    inline const hkpCollidable* getCollidable() const;
public:
    void* m_vtable;
    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    hkpWorld* m_world;
    void* m_userData;
    hkpCollidable m_collidable;
};
inline const hkpCollidable* hkpWorldObject::getCollidable() const
{
    return &m_collidable;
}

inline hkpWorldObject* hkGetWorldObject(const hkpCollidable* collidable)
{
    return reinterpret_cast<hkpWorldObject*>( const_cast<void*>(collidable->getOwner()) );
}

class hkpEntity : public hkpWorldObject
{
};

class hkpRigidBody : public hkpEntity
{
};

inline hkpRigidBody* hkGetRigidBody( const hkpCollidable* collidable )
{
    if ( collidable->getType() == hkpWorldObject::BROAD_PHASE_ENTITY )
    {
        return static_cast<hkpRigidBody*>( hkGetWorldObject(collidable) );
    }
    return 0;
}

struct hkpShapeRayCastCollectorOutput
{
    inline hkpShapeRayCastCollectorOutput();
    inline void reset();
    hkVector4 m_normal;
    hkReal m_hitFraction;
    int m_extraInfo;
    int m_pad0;
    int m_pad1;
};
void hkpShapeRayCastCollectorOutput::reset()
{
    m_hitFraction = 1.0f;
    m_extraInfo = -1;
}
hkpShapeRayCastCollectorOutput::hkpShapeRayCastCollectorOutput()
{
    reset();
}

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
public:
    enum { MAX_HIERARCHY_DEPTH = 8 };
public:
    __forceinline hkpShapeRayCastOutput();
private:
    __forceinline void _reset();
public:
    hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
private:
    int m_shapeKeyIndex;
};
void hkpShapeRayCastOutput::_reset()
{
    m_shapeKeyIndex = 0;
    m_shapeKeys[0] = 0xffffffff;
}
hkpShapeRayCastOutput::hkpShapeRayCastOutput()
{
    _reset();
}

struct hkpWorldRayCastOutput : public hkpShapeRayCastOutput
{
    inline hkpWorldRayCastOutput();
    const hkpCollidable* m_rootCollidable;
};
hkpWorldRayCastOutput::hkpWorldRayCastOutput() :
    m_rootCollidable(0)
{
}

struct hkpWorldRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    hkBool m_enableShapeCollectionFilter;
    hkUint32 m_filterInfo;

    hkpWorldRayCastInput() : m_enableShapeCollectionFilter(false), m_filterInfo(0) { }
};

class hkpRayHitCollector
{
public:
    inline hkpRayHitCollector();
    virtual void addRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInfo) = 0;
    inline void reset();
    virtual ~hkpRayHitCollector() { }
public:
    hkReal m_earlyOutHitFraction;
};
inline void hkpRayHitCollector::reset()
{
    m_earlyOutHitFraction = 1.f;
}
inline hkpRayHitCollector::hkpRayHitCollector()
{
    reset();
}

class hkpAllRayHitCollector : public hkpRayHitCollector
{
public:
    inline hkpAllRayHitCollector();
    inline void reset();
    virtual ~hkpAllRayHitCollector();
    inline const hkArray<hkpWorldRayCastOutput>& getHits() const;
protected:
    virtual void addRayHit(const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInfo);
protected:
    hkInplaceArray<hkpWorldRayCastOutput, 8> m_hits;
};
void hkpAllRayHitCollector::reset()
{
    m_hits.clear();
    hkpRayHitCollector::reset();
}
hkpAllRayHitCollector::hkpAllRayHitCollector()
{
    reset();
}
const hkArray<hkpWorldRayCastOutput>& hkpAllRayHitCollector::getHits() const
{
    return m_hits;
}

class hkpWorld
{
public:
    void FUN_009787c0(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector) const;
};

class CollisionFilterInfo
{
public:
    inline CollisionFilterInfo(int layer, int group) { m_info = (group << 16) | layer; }
    inline operator hkUint32() const { return m_info; }
private:
    hkUint32 m_info;
};

struct RayCaster
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_layerGroup;

    hkBool FUN_00918e70(hkpWorld* world, const hkVector4& from, const hkVector4& to, hkVector4& outPos, hkVector4& outNormal);
};

// pdb: bhkRagdollPenetrationUtil::castRay | bhkRagdollPenetrationUtil.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: phantomIn, fromWS, toWS, hitPointWS, hitNormalWS
hkBool RayCaster::FUN_00918e70(hkpWorld* world, const hkVector4& from, const hkVector4& to, hkVector4& outPos, hkVector4& outNormal)
{
    bool found = false;
    hkpWorldRayCastInput input;
    hkpAllRayHitCollector collector;

    CollisionFilterInfo filterInfo(0x1d, m_layerGroup);
    input.m_from = from;
    input.m_to = to;
    input.m_filterInfo = filterInfo;
    collector.reset();
    world->FUN_009787c0(input, collector);
    for (int i = 0; i < collector.getHits().getSize() && !found; i++)
    {
        hkpWorldRayCastOutput hit = collector.getHits()[i];
        hkpRigidBody* body = hkGetRigidBody(hit.m_rootCollidable);
        if (body)
        {
            hkUint32 layer = body->getCollidable()->getCollisionFilterInfo() & 0x7f;
            if (layer != 8 && layer != 0x1d)
            {
                found = true;
                outPos.setInterpolate4(input.m_from, input.m_to, hit.m_hitFraction);
                outNormal = hit.m_normal;
            }
        }
    }

    if (!found)
    {
        input.m_from = to;
        input.m_to = from;
        input.m_filterInfo = filterInfo;
        input.m_enableShapeCollectionFilter = true;
        collector.reset();
        world->FUN_009787c0(input, collector);
        for (int i = 0; i < collector.getHits().getSize() && !found; i++)
        {
            hkpWorldRayCastOutput hit = collector.getHits()[i];
            hkpRigidBody* body = hkGetRigidBody(hit.m_rootCollidable);
            if (body)
            {
                hkUint32 layer = body->getCollidable()->getCollisionFilterInfo() & 0x7f;
                if (layer != 8 && layer != 0x1d)
                {
                    found = true;
                    outPos.setInterpolate4(input.m_from, input.m_to, hit.m_hitFraction);
                    outNormal = hit.m_normal;
                }
            }
        }
    }
    return found;
}

}
}   // namespace f3m_00918e70
