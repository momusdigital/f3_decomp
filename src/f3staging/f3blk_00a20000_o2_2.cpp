// src/f3staging/f3blk_00a20000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00a2ec80 (community match, verified in this file)
extern signed char DAT_00e7c778[];
extern signed char DAT_00e7c77a[];
extern float flt_00db38b8;
namespace f3m_00a2ec80 {
// 0x00a2ec80 -- triangle edge / point sign test (x87 scalar version)

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};


// pdb: hkpGsk::checkTriangleBoundaries | hkpGsk.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: findClosestTriangleBackup)
// pdb params: a, b, checkSupport
static __declspec(noinline) int FUN_00a2ec80(const Vec4* av, const Vec4* ap, float* ad)
{
    for (int i = 0; i < 3; i++)
    {
        int a = DAT_00e7c77a[i];
        int b = DAT_00e7c778[i];
        if (ad[a] >= 0.0f && ad[b] >= 0.0f)
        {
            Vec4 ea, eb, d, n;
            ea.x = av[a].x - av[i].x;
            ea.y = av[a].y - av[i].y;
            ea.z = av[a].z - av[i].z;
            eb.x = av[b].x - av[i].x;
            eb.y = av[b].y - av[i].y;
            eb.z = av[b].z - av[i].z;
            d.x = ap->x - av[i].x;
            d.y = ap->y - av[i].y;
            d.z = ap->z - av[i].z;
            n.x = av[3].x - av[i].x;
            n.y = av[3].y - av[i].y;
            n.z = av[3].z - av[i].z;

            float da = d.x * ea.x + d.y * ea.y + d.z * ea.z;
            float db = d.x * eb.x + d.y * eb.y + d.z * eb.z;
            float na = n.x * ea.x + n.y * ea.y + n.z * ea.z;
            float nb = n.x * eb.x + n.y * eb.y + n.z * eb.z;
            float s = da * nb - db * na;

            if (s < 0.0f)
                ad[b] = flt_00db38b8;
            else
                ad[a] = flt_00db38b8;
        }
    }
    if (ad[0] > 0.0f)
        return 0;
    if (ad[1] > 0.0f)
        return 1;
    if (ad[2] > 0.0f)
        return 2;
    return -1;
}

Vec4 g_av[4];
Vec4 g_point;
float g_dist[3];
int g_out;

void caller_of_FUN_00a2ec80()
{
    g_out = FUN_00a2ec80(g_av, &g_point, g_dist);
}
}   // namespace f3m_00a2ec80

// @f3 0x00a292e0 (community match, verified in this file)
namespace f3m_00a292e0 {
// Havok 5.5.0, hkBindingClassNameRegistry.cpp
namespace binding_class_offsets {

class hkClass;
class Dummy;

class hkBool
{
public:
    operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

template <typename T>
class hkPointerMapBase
{
public:
    hkPointerMapBase() throw() { FUN_00922cb0(); }
    ~hkPointerMapBase() throw() { FUN_00922cf0(); }

private:
    void FUN_00922cb0() throw();
    void FUN_00922cf0() throw();

    T* m_elem;
    int m_numElems;
    int m_hashMod;
};

template <typename K, typename V>
class hkPointerMap
{
    hkPointerMapBase<unsigned long> m_map;
};

struct hkStringMapOperations {};

template <typename Operations>
class hkCachedHashMap
{
public:
    typedef Dummy* Iterator;
    Iterator FUN_009b0dc0() const throw();
    unsigned long FUN_009b0df0(Iterator iter) const throw();
    Iterator FUN_009b0e10(Iterator iter) const throw();
    hkBool FUN_009b0e40(Iterator iter) const throw();

private:
    unsigned long* m_elem;
    int m_numElems;
    int m_hashMod;
    Operations m_ops;
};

class hkStringMapBase : public hkCachedHashMap<hkStringMapOperations> {};

template <typename V>
class hkStringMap
{
public:
    typedef hkStringMapBase::Iterator Iterator;

    Iterator getIterator() const { return m_map.FUN_009b0dc0(); }
    V getValue(Iterator iter) const { return reinterpret_cast<V>(m_map.FUN_009b0df0(iter)); }
    Iterator getNext(Iterator iter) const { return m_map.FUN_009b0e10(iter); }
    hkBool isValid(Iterator iter) const { return m_map.FUN_009b0e40(iter); }

private:
    hkStringMapBase m_map;
};

class hkStructureLayout
{
public:
    hkStructureLayout() throw() { FUN_009b2530(); }
    void FUN_009b2a50(hkClass& klass, hkPointerMap<const hkClass*, int>& done) const throw();

private:
    void FUN_009b2530() throw();

    struct LayoutRules
    {
        unsigned char m_bytesInPointer;
        unsigned char m_littleEndian;
        unsigned char m_reusePaddingOptimization;
        unsigned char m_emptyBaseClassOptimization;
    } m_rules;
};

static __declspec(noinline) void FUN_00a292e0(const hkStringMap<hkClass*>& classes)
{
    hkStructureLayout layout;
    hkPointerMap<const hkClass*, int> done;
    hkStringMap<hkClass*>::Iterator iter = classes.getIterator();
    while (classes.isValid(iter))
    {
        hkClass* klass = classes.getValue(iter);
        layout.FUN_009b2a50(*klass, done);
        iter = classes.getNext(iter);
    }
}

void computeClassMapOffsets(const hkStringMap<hkClass*>& classes)
{
    FUN_00a292e0(classes);
}

}
}   // namespace f3m_00a292e0
