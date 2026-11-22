#include <new>
// src/f3staging/f3iso_00907d50_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00907d50 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00907d50 (community match, verified in this file)
extern unsigned long DAT_0116913c, DAT_010f3170;
namespace f3m_00907d50 {
// 0x00907d50: reports every body in the world that penetrates a given collidable
// (hkpWorld::getPenetrations in Havok terms).

namespace f3m_00907d50 {

typedef float hkReal;
typedef unsigned int hkUint32;
typedef unsigned char hkUchar;

__declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_bool = static_cast<char>(b); }
    __forceinline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE val) : m_storage(val) {}
    __forceinline void operator=(TYPE val) { m_storage = val; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

private:
    TYPE m_storage;
};

class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance() { return *static_cast<hkMonitorStream*>(FUN_00d9b080(DAT_0116913c)); }
    __forceinline char* getEnd() { return m_end; }
    __forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;

    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : public Command
    {
        hkUint32 m_time0;
        hkUint32 m_time1;
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
    struct TimerBeginListCommand : public TimerCommand
    {
        const char* m_nameOfFirstSplit;
    };
};

enum HK_MEMORY_CLASS
{
    HK_MEMORY_CLASS_ARRAY = 0x17
};

class hkThreadMemory
{
public:
    static __forceinline hkThreadMemory& getInstance() { return *static_cast<hkThreadMemory*>(FUN_00d9b080(DAT_010f3170)); }
    void FUN_008f6d90(void* p, int nbytes, HK_MEMORY_CLASS cl);
};

template <typename T>
class hkArray
{
public:
    enum
    {
        CAPACITY_MASK = int(0x3fffffff),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };

    __forceinline hkArray(T* ptr, int size, int capacity) : m_data(ptr), m_size(size), m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG) {}
    __forceinline T* begin() { return m_data; }
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & int(CAPACITY_MASK); }
    __forceinline void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), HK_MEMORY_CLASS_ARRAY);
        }
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
public:
    __forceinline hkInplaceArray() : hkArray<T>(m_storage, 0, N) {}

    T m_storage[N];
};

class __declspec(align(16)) hkVector4
{
public:
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkTransform;

struct hkAabb
{
    hkVector4 m_min;
    hkVector4 m_max;
};

class hkpShape
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;

    __forceinline int getType() const { return m_type; }

    int unk04;
    unsigned int m_userData;
    int m_type;
};

struct hkpCdBody
{
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }
    __forceinline const hkpShape* getShape() const { return m_shape; }

    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

class hkpCollidable : public hkpCdBody
{
};

class hkpBroadPhaseHandle
{
public:
    hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_ownerOffset); }

    signed char m_type;
    signed char m_ownerOffset;
    unsigned short m_objectQualityType;
    hkUint32 m_collisionFilterInfo;
};

struct hkpBroadPhaseHandlePair
{
    hkpBroadPhaseHandle* m_a;
    hkpBroadPhaseHandle* m_b;
};

class hkpBroadPhase
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void querySingleAabb(const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const;
};

class hkpCdBodyPairCollector
{
public:
    virtual void vf00();

    __forceinline hkBool getEarlyOut() const { return m_earlyOut; }

    hkBool m_earlyOut;
};

struct hkpCollisionInput;

class hkpCollisionDispatcher
{
public:
    typedef void* (__cdecl* CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& input, void* mgr);
    typedef void (__cdecl* GetPenetrationsFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector);
    typedef void (__cdecl* GetClosestPointsFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& input, void* collector);
    typedef void (__cdecl* LinearCastFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const void* input, void* castCollector, void* startCollector);

    struct AgentFuncs
    {
        CreateFunc m_createFunc;
        GetPenetrationsFunc m_getPenetrationsFunc;
        GetClosestPointsFunc m_getClosestPointFunc;
        LinearCastFunc m_linearCastFunc;
        hkBool m_isFlipped;
        hkBool m_isPredictive;
    };

    __forceinline GetPenetrationsFunc getGetPenetrationsFunc(int typeA, int typeB) const
    {
        return m_agent2Func[m_agent2Types[typeA][typeB]].m_getPenetrationsFunc;
    }

    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    hkUchar m_agent2Types[32][32];
    hkUchar m_agent2TypesPred[32][32];
    AgentFuncs m_agent2Func[64];
};

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

class hkReferencedObject
{
public:
    virtual void vf00();

    short m_memSizeAndFlags;
    short m_referenceCount;
};

class hkpCollidableCollidableFilter
{
public:
    virtual void vf00();
    virtual hkBool isCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const;
};

class hkpCollisionFilter : public hkReferencedObject, public hkpCollidableCollidableFilter
{
};

class hkpWorld
{
public:
    void hkpWorld_getPenetrations(const hkpCollidable* collA, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector) const;

    __forceinline const hkpCollisionInput* getCollisionInput() const { return m_collisionInput; }
    __forceinline const hkpCollisionFilter* getCollisionFilter() const { return m_collisionFilter; }

    void* m_vtable;
    short m_memSizeAndFlags;
    short m_referenceCount;
    void* m_simulation;
    int unk0c;
    hkReal m_gravityX, m_gravityY, m_gravityZ, m_gravityW;
    void* m_fixedIsland;
    void* m_fixedRigidBody;
    void* m_activeIslandsData;
    int m_activeIslandsSize;
    int m_activeIslandsCapacity;
    void* m_inactiveIslandsData;
    int m_inactiveIslandsSize;
    int m_inactiveIslandsCapacity;
    void* m_dirtySimulationIslandsData;
    int m_dirtySimulationIslandsSize;
    int m_dirtySimulationIslandsCapacity;
    void* m_kdTree;
    void* m_maintenanceMgr;
    hkpBroadPhase* m_broadPhase;
    void* m_broadPhaseDispatcher;
    void* m_phantomBroadPhaseListener;
    void* m_entityEntityBroadPhaseListener;
    void* m_broadPhaseBorderListener;
    void* m_multithreadedSimulationJobData;
    hkpCollisionInput* m_collisionInput;
    hkpCollisionFilter* m_collisionFilter;
};

// pdb: hkpWorld::getPenetrations | hkpWorld.obj | fnv360_0822_retail, ustr + skyrim(ustr), high
void hkpWorld::hkpWorld_getPenetrations(const hkpCollidable* collA, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector) const
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "LthkpWorld::getPenetrations";
            h->m_nameOfFirstSplit = "Stbroadphase";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hkAabb aabb;
    {
        hkReal restTolerance = input.getTolerance() - getCollisionInput()->getTolerance() * 0.5f;
        collA->getShape()->getAabb(collA->getTransform(), restTolerance, aabb);
    }

    hkInplaceArray<hkpBroadPhaseHandlePair, 128> hits;
    m_broadPhase->querySingleAabb(aabb, hits);

    hkpBroadPhaseHandlePair* p = hits.begin();
    const int typeA = collA->getShape()->getType();

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Stnarrowphase";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    for (int i = hits.getSize() - 1; i >= 0; p++, i--)
    {
        const hkpTypedBroadPhaseHandle* tp = static_cast<const hkpTypedBroadPhaseHandle*>(p->m_b);
        const hkpCollidable* collB = static_cast<hkpCollidable*>(tp->getOwner());

        if (collA == collB)
        {
            continue;
        }

        if (!getCollisionFilter()->isCollisionEnabled(*collA, *collB))
        {
            continue;
        }

        const hkpShape* shapeB = collB->getShape();
        if (!shapeB)
        {
            continue;
        }
        const int typeB = shapeB->getType();

        hkpCollisionDispatcher::GetPenetrationsFunc getPenetrationsFunc = input.m_dispatcher->getGetPenetrationsFunc(typeA, typeB);
        (*getPenetrationsFunc)(*collA, *collB, input, collector);
        if (collector.getEarlyOut())
        {
            break;
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "lt";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hits.releaseMemory();
}

}

}   // namespace f3m_00907d50
