#include <windows.h>
// src/f3staging/f3blk_00a40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"


// @f3 0x00a55490 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00a55490 {
// Havok MOPP cached shape mediator: add the k-DOP of a sphere-rep shape. The collision spheres are fetched into a
// thread-stack buffer, a new entry is appended to the mediator's array, and for every splitting direction the
// spheres are projected onto it: extents = [min(dot - radius), max(dot + radius)], or [0, 0] without spheres.


namespace f3m_00a55490 {

typedef float hkReal;

struct hkSimdReal
{
    hkReal m_real;
    __forceinline hkSimdReal() {}
    __forceinline hkSimdReal(hkReal x) { m_real = x; }
    __forceinline operator hkReal() const { return m_real; }
};

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;

    __forceinline hkSimdReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
};

// position in xyz, radius in w
struct hkSphere
{
    hkVector4 m_pos;
    __forceinline const hkVector4& getPosition() const { return m_pos; }
    __forceinline hkReal getRadius() const { return m_pos.w; }
};

struct SphereRepShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual int getNumCollisionSpheres() const;
    virtual const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;
};

// 32 bytes: the direction and two more words
struct SplittingDirection
{
    hkVector4 m_direction;
    hkReal m_cost;
    int m_index;
};

struct ThreadMemory
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* p);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char* m_current;
    int unk24;
    char* m_base;
    char* m_end;

    __forceinline void* allocateStack(int n)
    {
        int bytes = ((n + 1) * 16) & ~15;
        char* p = m_current;
        char* end = p + bytes;
        void* result;
        if (end <= m_end) { m_current = end; result = p; }
        else result = onStackOverflow(bytes);
        return result;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_base) onStackUnderflow(p);
    }
};

__forceinline ThreadMemory* getThreadMemory()
{
    return (ThreadMemory*)TlsGetValue(DAT_010f3170);
}

// 0x6c bytes: the shape key and a [min, max] pair for each of up to 13 directions
struct KdopEntry
{
    unsigned int m_key;
    hkReal m_extents[13][2];
};

void __cdecl FUN_00901f10(void* array, int elemSize);

struct KdopArray
{
    KdopEntry* m_data;
    int m_size;
    int m_capacityAndFlags;

    __forceinline KdopEntry& expandOne()
    {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(KdopEntry));
        return m_data[m_size++];
    }
};

// the mediator: hkReferencedObject header, then the array of cached k-DOPs
struct CachedShapeMediator
{
    void* vtbl;
    int m_memSizeAndFlags;
    KdopArray m_entries;

    void hkpMoppCachedShapeMediator_addConvexShape(const SphereRepShape* shape, unsigned int key, const SplittingDirection* directions, int numDirections);
};

// pdb: hkpMoppCachedShapeMediator::addConvexShape | hkpMoppCachedShapeMediator.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void CachedShapeMediator::hkpMoppCachedShapeMediator_addConvexShape(const SphereRepShape* shape, unsigned int key, const SplittingDirection* directions, int numDirections)
{
    int numSpheres = shape->getNumCollisionSpheres();
    hkSphere* spheres = (hkSphere*)getThreadMemory()->allocateStack(numSpheres);
    shape->getCollisionSpheres(spheres);

    KdopEntry& entry = m_entries.expandOne();
    entry.m_key = key;

    for (int d = 0; d < numDirections; d++)
    {
        hkReal minV;
        hkReal maxV;
        if (numSpheres > 0)
        {
            hkVector4 dir = directions[d].m_direction;
            hkReal radius = spheres[0].getRadius();
            hkReal dist = spheres[0].getPosition().dot3(dir);
            minV = dist - radius;
            maxV = dist + radius;
            for (int i = 1; i < numSpheres; i++)
            {
                dist = spheres[i].getPosition().dot3(dir);
                radius = spheres[i].getRadius();
                hkReal lo = dist - radius;
                hkReal hi = dist + radius;
                if (lo < minV) minV = lo;
                if (hi > maxV) maxV = hi;
            }
        }
        else
        {
            minV = 0.0f;
            maxV = 0.0f;
        }
        entry.m_extents[d][0] = minV;
        entry.m_extents[d][1] = maxV;
    }

    getThreadMemory()->deallocateStack(spheres);
}

}
}   // namespace f3m_00a55490
