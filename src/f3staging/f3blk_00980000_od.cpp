#include <windows.h>
#include <math.h>
// src/f3staging/f3blk_00980000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0099ddd0 (community match, verified in this file)
extern double _gModifierZero;
namespace f3m_0099ddd0 {

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    void add3(const Vec4& v) {
        float vx = v.x;
        float vy = v.y;
        x = (*(float volatile*)&v.x) + x;
        y = y + vy;
        z = z + v.z;
    }
    void addMul4(float s, const Vec4& v) {
        x += v.x * s;
        y += v.y * s;
        z += v.z * s;
        w += v.w * s;
    }
};

struct Mat3 {
    Vec4 c0, c1, c2;
    void mul(const Vec4& v, Vec4& out) const {
        out.x = c0.x * v.x + c0.y * v.y + c0.z * v.z;
        out.y = c1.x * v.x + c1.y * v.y + c1.z * v.z;
        out.z = c2.x * v.x + c2.y * v.y + c2.z * v.z;
    }
    void mulT(const Vec4& v, Vec4& out) const {
        out.x = c0.x * v.x + c1.x * v.y + c2.x * v.z;
        out.y = c0.y * v.x + c1.y * v.y + c2.y * v.z;
        out.z = c0.z * v.x + c1.z * v.y + c2.z * v.z;
    }
};

struct Motion {
    float unk00, unk04, unk08, unk0c;
    Mat3 rot;                                   // 0x10
    float unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    float px, py, pz, unk6c;                    // 0x60
    float unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    float unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    float unkb0, unkb4, unkb8, unkbc;
    float ii0, ii1, ii2, unkcc;                 // 0xc0
    Vec4 vel;                                   // 0xd0
    Vec4 ang;                                   // 0xe0

    void FUN_0099ddd0(const Vec4& imp, const Vec4& point);
};

void Motion::FUN_0099ddd0(const Vec4& imp, const Vec4& point)
{
    vel.addMul4(unkcc, imp);

    Vec4 r;
    r.x = point.x - px;
    r.y = point.y - py;
    r.z = point.z - pz;

    Vec4 torque;
    torque.x = r.y * imp.z - r.z * imp.y;
    torque.y = r.z * imp.x - r.x * imp.z;
    torque.z = r.x * imp.y - r.y * imp.x;

    Vec4 a;
    rot.mul(torque, a);

    r.x = ii0 * a.x;
    r.y = ii1 * a.y;
    r.z = ii2 * a.z;

    rot.mulT(r, a);

    ang.add3(a);
    ang.w += _gModifierZero;
}
}   // namespace f3m_0099ddd0

// @f3 0x00990f00 (community match, verified in this file)
namespace f3m_00990f00 {
struct __declspec(align(16)) Vec990 {
    float x,y,z,w;
    void add(const Vec990& a) { x+=a.x; y+=a.y; z+=a.z; w+=a.w; }
    void setadd(const Vec990& a,const Vec990& b) { x=a.x+b.x; y=a.y+b.y; z=a.z+b.z; w=a.w+b.w; }
    void setyz(const Vec990& a,const Vec990& b) { y=a.y+b.y; z=a.z+b.z; w=a.w+b.w; }
    void reciprocal(const Vec990& a) { x=1.0f/a.x; y=1.0f/a.y; z=1.0f/a.z; w=1.0f; }
    void negate(const Vec990& a) { x=-a.x; y=-a.y; z=-a.z; w=-a.w; }
};
struct Body990 {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void f40(); virtual void f44(); virtual void apply(Vec990*,Vec990*,int);
    int u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30;
    Vec990 p0,p1,d0,p2,p3,d1;
    void FUN_00990f00(Vec990*,Vec990*,int);
};
void Body990::FUN_00990f00(Vec990* in, Vec990* out, int arg) {
    Vec990 neg, result, inv;
    neg.negate(*in);
    apply(&neg,&result,arg);
    p0.add(result);
    inv.reciprocal(d0);
    p1.x=inv.x+p0.x; p1.setyz(p0,inv);
    p2.add(result);
    inv.reciprocal(d1);
    p3.setadd(p2,inv);
    out->negate(result);
}
}   // namespace f3m_00990f00

// @f3 0x0099dfc0 (community match, verified in this file)
namespace f3m_0099dfc0 {
struct hkQuadReal { float v[4]; };
class hkMatrix3;
class __declspec(align(16)) hkVector4
{
public:
    hkQuadReal m_quad;
    __forceinline float& operator()(int i) { return m_quad.v[i]; }
    __forceinline const float& operator()(int i) const { return m_quad.v[i]; }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_quad.v[0] = a.m_quad.v[0] * b.m_quad.v[0];
        m_quad.v[1] = a.m_quad.v[1] * b.m_quad.v[1];
        m_quad.v[2] = a.m_quad.v[2] * b.m_quad.v[2];
        m_quad.v[3] = a.m_quad.v[3] * b.m_quad.v[3];
    }
    __forceinline void add4(const hkVector4& a)
    {
        m_quad.v[0] += a.m_quad.v[0];
        m_quad.v[1] += a.m_quad.v[1];
        m_quad.v[2] += a.m_quad.v[2];
        m_quad.v[3] += a.m_quad.v[3];
    }
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b);
};
class hkMatrix3
{
public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline float operator()(int r, int c) const { return getColumn(c)(r); }
};
__forceinline void hkVector4::_setRotatedDir(const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(0,1)*b1 + r(0,2)*b2;
    m_quad.v[1] = r(1,0)*b0 + r(1,1)*b1 + r(1,2)*b2;
    m_quad.v[2] = r(2,0)*b0 + r(2,1)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkMatrix3& r, const hkVector4& b)
{
    const float b0 = b(0);
    const float b1 = b(1);
    const float b2 = b(2);
    m_quad.v[0] = r(0,0)*b0 + r(1,0)*b1 + r(2,0)*b2;
    m_quad.v[1] = r(0,1)*b0 + r(1,1)*b1 + r(2,1)*b2;
    m_quad.v[2] = r(0,2)*b0 + r(1,2)*b1 + r(2,2)*b2;
    m_quad.v[3] = 0;
}
class Cdfc0
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3 m_rotation;
    int unk40[32];
    hkVector4 m_inertiaAndMassInv;
    hkVector4 m_linearVelocity;
    hkVector4 m_angularVelocity;
    void FUN_0099dfc0(const hkVector4& imp);
};
void Cdfc0::FUN_0099dfc0(const hkVector4& imp)
{
    hkVector4 impulseLocal;
    impulseLocal._setRotatedInverseDir(m_rotation, imp);
    hkVector4 dw;
    dw.setMul4(m_inertiaAndMassInv, impulseLocal);
    hkVector4 dwWorld;
    dwWorld._setRotatedDir(m_rotation, dw);
    m_angularVelocity.add4(dwWorld);
}
}   // namespace f3m_0099dfc0

// @f3 0x00990ab0 (community match, verified in this file)
namespace f3m_00990ab0 {
// hkp3AxisSweep::updateNodesAfterInsert(hkpBpNode* nodes, int numNodes, hkpBpNode& newNode): after a node's six
// endpoints were inserted into the three sorted axes, shift every endpoint index of the other nodes that lies at or
// above an insertion point (each axis gets one min and one max endpoint). The member does not use this.
namespace f3m_00990ab0
{
    typedef unsigned short Uint16;
    typedef unsigned int Uint32;

    struct BroadPhaseHandle;

    // One sweep node: endpoint indices on the three axes plus the owner handle (16 bytes).
    struct BpNode
    {
        Uint16 min_y;
        Uint16 min_z;
        Uint16 max_y;
        Uint16 max_z;
        Uint16 min_x;
        Uint16 max_x;
        BroadPhaseHandle* handle;
    };
}

// pdb: hkp3AxisSweep::updateNodesAfterInsert | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
extern "C" void __stdcall FUN_00990ab0(f3m_00990ab0::BpNode* nodes, int numNodes, f3m_00990ab0::BpNode& newNode)
{
    using namespace f3m_00990ab0;

    // Mask that keeps the handle word untouched in the library's vectorised variant; unused by this loop.
    __declspec(align(16)) const Uint32 protectPointerMask[4] = { 0xffffffff, 0xffffffff, 0xffffffff, 0 };

    // Thresholds laid out like a node, so every field has its own pair (the vector form compares whole nodes).
    BpNode miNode;
    BpNode maNode;
    miNode.min_x = newNode.min_x - 1;
    miNode.max_x = newNode.min_x - 1;
    miNode.min_y = newNode.min_y - 1;
    miNode.max_y = newNode.min_y - 1;
    miNode.min_z = newNode.min_z - 1;
    miNode.max_z = newNode.min_z - 1;
    maNode.min_x = newNode.max_x - 2;
    maNode.max_x = newNode.max_x - 2;
    maNode.min_y = newNode.max_y - 2;
    maNode.max_y = newNode.max_y - 2;
    maNode.min_z = newNode.max_z - 2;
    maNode.max_z = newNode.max_z - 2;

    BpNode* end = nodes + numNodes;
    for (BpNode* n = nodes; n < end; n++)
    {
        // (threshold - value) >> 31 is 1 exactly when value > threshold.
        n->min_x = n->min_x + ((Uint32(miNode.min_x) - n->min_x) >> 31) + ((Uint32(maNode.min_x) - n->min_x) >> 31);
        n->min_y = n->min_y + ((Uint32(miNode.min_y) - n->min_y) >> 31) + ((Uint32(maNode.min_y) - n->min_y) >> 31);
        n->max_x = n->max_x + ((Uint32(miNode.max_x) - n->max_x) >> 31) + ((Uint32(maNode.max_x) - n->max_x) >> 31);
        n->max_y = n->max_y + ((Uint32(miNode.max_y) - n->max_y) >> 31) + ((Uint32(maNode.max_y) - n->max_y) >> 31);
        n->min_z = n->min_z + ((Uint32(miNode.min_z) - n->min_z) >> 31) + ((Uint32(maNode.min_z) - n->min_z) >> 31);
        n->max_z = n->max_z + ((Uint32(miNode.max_z) - n->max_z) >> 31) + ((Uint32(maNode.max_z) - n->max_z) >> 31);
    }
}
}   // namespace f3m_00990ab0

// @f3 0x0098e4c0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long hkMonitorStreamTls;
extern unsigned long DAT_010f3170;
extern const char DAT_00e7dc5c[];

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return m_storage; }
    __forceinline void operator=(T v) { m_storage = v; }
private:
    T m_storage;
};

class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    }

    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
    hkBool m_isBufferAllocatedOnTheHeap;

    struct Command
    {
        const char* m_commandAndMonitor;
    };

    struct TimerCommand : public Command
    {
        unsigned int m_time0;
        unsigned int m_time1;

        __forceinline void setTime()
        {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class hkThreadMemory
{
public:
    virtual ~hkThreadMemory();
    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void* allocateChunk(int nbytes, int cl);
    virtual void deallocateChunk(void* ptr, int nbytes, int cl);
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* ptr);
    void FUN_008f6d90(void* ptr, int nbytes, int cl);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)TlsGetValue(DAT_010f3170);
    }

    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 0x10) & ~0xf;
        char* p = m_stack.m_current;
        char* next = p + nbytes;
        if (next <= m_stack.m_end)
        {
            m_stack.m_current = next;
            return p;
        }
        return onStackOverflow(nbytes);
    }

    __forceinline void deallocateStack(void* p)
    {
        m_stack.m_current = static_cast<char*>(p);
        if (p == m_stack.m_base)
        {
            onStackUnderflow(p);
        }
    }

    struct Stack
    {
        char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    void* m_memory;
    int m_referenceCount;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Stack m_stack;
};

template <typename T>
__forceinline T* hkAllocateStack(int n)
{
    return static_cast<T*>(hkThreadMemory::getInstance().allocateStack(n * sizeof(T)));
}

template <typename T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(static_cast<void*>(p));
}

void __cdecl FUN_00923500(void* dst, int value, int n);

template <typename T>
class hkArray
{
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline hkArray() {}
    __forceinline ~hkArray()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, (m_capacityAndFlags & CAPACITY_MASK) * sizeof(T), 0x17);
    }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void setSizeUnchecked(int n) { m_size = n; }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkLocalArray : public hkArray<T>
{
public:
    __forceinline hkLocalArray(int n)
    {
        m_localMemory = hkAllocateStack<T>(n);
        this->m_data = m_localMemory;
        this->m_size = 0;
        this->m_capacityAndFlags = n | hkArray<T>::DONT_DEALLOCATE_FLAG;
    }
    __forceinline ~hkLocalArray()
    {
        hkDeallocateStack<T>(m_localMemory);
    }
    T* m_localMemory;
};

struct hkpProcessCdPoint
{
    float m_contact[8];
    int unk20, unk24, unk28, unk2c;
};

struct __declspec(align(16)) hkpToiInfo
{
    float m_contact[8];
    float m_time;
    float m_seperatingVelocity;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    float m_impulseApplied;
    float m_internalSolverData;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    __forceinline hkpToiInfo() : m_time(3.40282e38), m_impulseApplied(0.0f), m_internalSolverData(0.0f) {}
};

class hkpSimulationIsland;

struct __declspec(align(16)) hkpProcessCollisionOutput
{
    hkpProcessCdPoint* m_firstFreeContactPoint;
    hkpSimulationIsland* m_constraintOwner;
    int unk08, unk0c;
    hkpProcessCdPoint m_contactPoints[256];
    hkpToiInfo m_toi;
    void* m_potentialContacts;
    __forceinline hkpProcessCollisionOutput(hkpSimulationIsland* owner) : m_constraintOwner(owner) {}
    __forceinline void reset()
    {
        m_firstFreeContactPoint = &m_contactPoints[0];
        m_toi.m_time = 3.40282e38;
        m_potentialContacts = 0;
    }
    __forceinline bool hasContacts() { return m_firstFreeContactPoint != &m_contactPoints[0]; }
};

struct hkpCollisionQualityInfo
{
    int unk00, unk04, unk08, unk0c;
    int m_useContinuousPhysics;
    int unk14[11];
};

struct hkpCollisionDispatcher
{
    int unk0000[0x708];
    hkpCollisionQualityInfo m_collisionQualityInfo[8];
};

struct hkpProcessCollisionInput
{
    hkpCollisionDispatcher* m_dispatcher;
    int unk04, unk08, unk0c;
    int m_createPredictiveAgents;
    int unk14[19];
    hkpCollisionQualityInfo* m_collisionQualityInfo;
};

struct hkpCollidable;

class hkpContactMgr
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void processContact(const hkpCollidable& a, const hkpCollidable& b,
        const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output);
};

struct hkpAgentNnEntry
{
    int unk00, unk04;
    hkpContactMgr* m_contactMgr;
    signed char m_collisionQualityIndex;
    char unk0d, unk0e, unk0f;
    hkpCollidable* m_collidable[2];
};

class hkpEntity;

struct hkpCollidable
{
    int unk00, unk04, unk08, unk0c;
    signed char m_ownerOffset;
    __forceinline hkpEntity* getOwner() { return (hkpEntity*)((char*)this + m_ownerOffset); }
};

struct CollisionEntry
{
    hkpAgentNnEntry* m_agentEntry;
    hkpCollidable* m_partner;
};

class hkpSimulationIsland
{
public:
    int unk00[0x13];
    int m_numEntities;
};

class hkpEntity
{
public:
    int unk00[0x17];
    CollisionEntry* m_collisionEntries;
    int m_numCollisionEntries;
    int unk64[0xc];
    unsigned short m_storageIndex;
    short unk96;
    int unk98[8];
    hkpSimulationIsland* m_simulationIsland;
};

class hkMemory
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual hkBool hasMemoryAvailable(int size);
    int m_memoryState;
};
extern hkMemory* DAT_010f3400;

void __cdecl FUN_00999610(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& input,
    hkpProcessCollisionOutput& output, hkpContactMgr* mgr);

class hkpContinuousSimulation
{
public:
    void FUN_0098c830(const hkpProcessCollisionOutput& output, const hkpAgentNnEntry& entry);
    void collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(hkpEntity** entities, int numEntities, hkpProcessCollisionInput& input);
};

// pdb: hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly | hkpContinuousSimulation.obj | fnv360_0822_retail, objrun_prop + bridge(ustr_rel|vtable), high
void hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(hkpEntity** entities, int numEntities, hkpProcessCollisionInput& input)
{
    hkpSimulationIsland* island = entities[0]->m_simulationIsland;
    int n = island->m_numEntities;
    hkLocalArray<hkBool> processed(n);
    processed.setSizeUnchecked(n);
    FUN_00923500(processed.begin(), 0, n);

    hkpProcessCollisionOutput processOutput(island);

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.getEnd() < mStream.getCapacityMinus16())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = DAT_00e7dc5c;
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    for (int i = 0; i < numEntities; i++)
    {
        hkpEntity* entity = entities[i];
        processed[entity->m_storageIndex] = true;
        for (int j = 0; j < entity->m_numCollisionEntries; j++)
        {
            CollisionEntry& e = entity->m_collisionEntries[j];
            hkpEntity* partner = e.m_partner->getOwner();
            if (partner->m_simulationIsland == island && processed[partner->m_storageIndex])
                continue;

            hkpAgentNnEntry* entry = e.m_agentEntry;
            processOutput.reset();
            input.m_collisionQualityInfo = &input.m_dispatcher->m_collisionQualityInfo[entry->m_collisionQualityIndex];
            input.m_createPredictiveAgents = input.m_collisionQualityInfo->m_useContinuousPhysics;

            FUN_00999610(entry, input, processOutput, entry->m_contactMgr);

            hkMemory* mem = DAT_010f3400;
            if (!mem->hasMemoryAvailable(0))
                mem->m_memoryState = 1;
            if (mem->m_memoryState == 1)
                return;

            if (processOutput.hasContacts())
                entry->m_contactMgr->processContact(*entry->m_collidable[0], *entry->m_collidable[1], input, processOutput);

            if (processOutput.m_toi.m_time != (double)3.40282e38f)
                FUN_0098c830(processOutput, *entry);
        }
    }

    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.getEnd() < mStream.getCapacityMinus16())
        {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

// @f3 0x0098bd20 (community match, verified in this file)
// 0x0098bd20: hkpBroadPhaseBorder::hkpBroadPhaseBorder(hkpWorld* world, hkpWorldCinfo::BroadPhaseBorderBehaviour
// type) of Havok 5.5.0 (hkpDynamics, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-), the constructor of the world's
// broadphase border: it registers as a world deletion listener and puts six AABB phantoms, one on each face of the
// world's broadphase extents, into the world, listening to their overlaps.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then single lines by work\_havok\linecut.py, every cut checked
// byte for byte against the SDK's release library object); those declarations are the SDK's text with its names.
// The SDK's int 3 traps in the unused placement operators new[] and delete[] were removed by hand. The constructor's
// body follows the SDK's unoptimized (hybrid) library object statement by statement and reproduces the release
// object. Only the class is renamed, to the packet's name, so that its constructor carries that name.
namespace f3m_0098bd20 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				__forceinline void setData(T p)
				{
					hkUlong v = hkUlong(p);
					TlsSetValue( m_slotID, (void*)v );
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
__forceinline hkReferencedObject::hkReferencedObject()
: m_referenceCount(1)
{
}
__forceinline void hkReferencedObject::addReference() const
{
	if ( m_memSizeAndFlags != 0 )
	{
		++m_referenceCount;
	}
}
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkBool32 equals3(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkBool32 equals4(const hkVector4 &a, hkReal epsilon = 1e-3f ) const;
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareEqual4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
		__forceinline hkSimdReal length4() const;
		__forceinline hkSimdReal lengthSquared4() const;
		__forceinline hkSimdReal lengthInverse4() const;
		__forceinline void normalize3();
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline void normalize4();
		__forceinline hkSimdReal normalizeWithLength4();
		__forceinline void fastNormalize3();
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
inline const hkReal& hkVector4::operator() (int i) const
{
	; ;
	return (&x)[i];
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
class hkpRayHitCollector;
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody(  ){}
		friend class hkpCollidable;
		__forceinline hkpCdBody( const hkpShape* shape, const hkMotionState* motionState );
		__forceinline hkpCdBody( const hkpShape* shape, const hkTransform* t );
		__forceinline hkpCdBody( const hkpCdBody& body ){}
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
		__forceinline const hkMotionState* getMotionState() const;
		__forceinline void setMotionState( const hkMotionState* state );
		__forceinline void setTransform( const hkTransform* t );
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID,
	HK_COLLIDABLE_QUALITY_FIXED,
	HK_COLLIDABLE_QUALITY_KEYFRAMED,
	HK_COLLIDABLE_QUALITY_DEBRIS,
	HK_COLLIDABLE_QUALITY_MOVING,
	HK_COLLIDABLE_QUALITY_CRITICAL,
	HK_COLLIDABLE_QUALITY_BULLET,
	HK_COLLIDABLE_QUALITY_USER,
	HK_COLLIDABLE_QUALITY_CHARACTER,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
	HK_COLLIDABLE_QUALITY_MAX
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpTypedBroadPhaseHandle( int type );
		__forceinline hkpTypedBroadPhaseHandle( void* owner, int type );
		__forceinline int getType() const;
		__forceinline void setOwner(void* o);
		__forceinline void* getOwner() const;
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		hkpTypedBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ) : hkpBroadPhaseHandle(flag) {}
	protected:
		enum { OFFSET_INVALID = 127 };
		inline void setType( int type );
		friend class FUN_0098bd20;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};
void hkpTypedBroadPhaseHandle::setType( int type )
{
	m_type = static_cast<hkInt8>(type);
}
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpCollidable( const hkpShape* shape, const hkTransform* ms, int type = 0);
		inline hkpCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpCollidable();
		inline const hkpShape* getShape() const;
		inline void setShape(const hkpShape* shape);
		inline void setOwner( void* owner );
		inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
		void checkPerformance();
		inline const hkpTypedBroadPhaseHandle* getBroadPhaseHandle() const;
		inline       hkpTypedBroadPhaseHandle* getBroadPhaseHandle();
		__forceinline hkpCollidableQualityType getQualityType() const;
		__forceinline void setQualityType(hkpCollidableQualityType type);
		__forceinline hkReal getAllowedPenetrationDepth() const;
		__forceinline void setAllowedPenetrationDepth( hkReal val );
	public:
		__forceinline hkUint32 getCollisionFilterInfo() const;
		__forceinline void setCollisionFilterInfo( hkUint32 info );
		__forceinline int getType() const;
		hkpCollidable( class hkFinishLoadedObjectFlag flag );
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				BoundingVolumeData();
				__forceinline const hkAabbUint32& getAabbUint32() const { return reinterpret_cast<const hkAabbUint32&>(m_min); }
				__forceinline       hkAabbUint32& getAabbUint32()		  { return reinterpret_cast<      hkAabbUint32&>(m_min); }
				__forceinline void invalidate() { m_min[0] = 1; m_max[0] = 0; }
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};
inline hkpTypedBroadPhaseHandle* hkpCollidable::getBroadPhaseHandle()
{
	return &m_broadPhaseHandle;
}
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpLinkedCollidable( const hkpShape* shape, const hkMotionState* ms, int type = 0);
		inline ~hkpLinkedCollidable();
		inline hkpLinkedCollidable( class hkFinishLoadedObjectFlag flag ) : hkpCollidable(flag) {}
	public:
		struct CollisionEntry
		{
			hkpAgentNnEntry* m_agentEntry;
			hkpLinkedCollidable*	m_partner;
		};
		hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		__forceinline bool isMarkedForWrite( )
		{
			return true;
		}
		__forceinline bool isMarkedForReadRecursive()
		{
			return true;
		}
		__forceinline void unmarkForRead( )
		{
			;
		}
		__forceinline void unmarkForWrite()
		{
			;
		}
		void disableChecks();
		void enableChecks();
		bool isCheckingEnabled() const;
		void accessCheck( AccessType type ) const;
		static void __cdecl accessCheckWithParent( const hkMultiThreadCheck* parentLock, AccessType parentType, const hkMultiThreadCheck& lock, AccessType type );
		static void staticInit();
		static void staticQuit();
	protected:
		void markForReadImpl(ReadMode mode  );
		void markForWriteImpl( );
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkpPropertyValue;
class hkpWorld;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void addProperty( hkUint32 key, hkpPropertyValue value );
		hkpPropertyValue removeProperty( hkUint32 key );
		void editProperty( hkUint32 key, hkpPropertyValue value );
		inline hkpPropertyValue getProperty( hkUint32 key ) const;
		inline hkBool hasProperty( hkUint32 key ) const;
		void lockProperty( hkUint32 key );
		void unlockProperty( hkUint32 key );
		inline void unlockPropertiesFromLoadedObject();
		inline void clearAndDeallocateProperties();
		inline hkpCollidable* getCollidableRw();
		inline const hkpCollidable* getCollidable() const;
		inline hkpLinkedCollidable* getLinkedCollidable();
		inline const hkpLinkedCollidable* getLinkedCollidable() const;
		inline const hkpLinkedCollidable* getCollidableMtUnchecked() const;
		inline hkBool isAddedToWorld() const;
		inline hkpWorld* getWorld() const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline const char* getName() const;
		inline void setName( const char* name );
		void calcStatistics( hkStatisticsCollector* collector ) const;
		virtual hkWorldOperation::Result setShape( const hkpShape* shape );
		inline void markForRead( );
		inline void markForWrite( );
		void markForWriteImpl( );
		inline void unmarkForRead( );
		inline void unmarkForWrite();
		void checkReadWrite();
		void checkReadOnly() const;
		void addReference();
		void removeReference();
		void addReferenceAsCriticalOperation();
		void removeReferenceAsCriticalOperation();
	public:
		enum BroadPhaseType
		{
			BROAD_PHASE_INVALID,
			BROAD_PHASE_ENTITY,
			BROAD_PHASE_PHANTOM,
			BROAD_PHASE_BORDER,
			BROAD_PHASE_MAX_ID
		};
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationUtil;
		inline void setWorld( hkpWorld* world );
		virtual class hkMotionState* getMotionState() = 0;
		hkpWorldObject( const hkpShape* shape, BroadPhaseType type );
		inline virtual ~hkpWorldObject();
	public:
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		inline void copyProperties( const hkpWorldObject* otherObj );
	protected:
		hkpWorld* m_world;
		hkUlong m_userData;
	protected:
		class hkpLinkedCollidable m_collidable;
	protected:
		class hkMultiThreadCheck m_multiThreadCheck;
		const char* m_name;
		hkArray<class hkpProperty> m_properties;
	public:
		hkpWorldObject( class hkFinishLoadedObjectFlag flag );
};
inline hkpCollidable* hkpWorldObject::getCollidableRw()
{
	return &m_collidable;
}
struct hkpSolverInfo
{
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
class hkpConstraintData;
class hkpConstraintInstance;
class hkpEntity;
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
class hkpWorldCinfo : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum SolverType
		{
			SOLVER_TYPE_INVALID,
			SOLVER_TYPE_2ITERS_SOFT,
			SOLVER_TYPE_2ITERS_MEDIUM,
			SOLVER_TYPE_2ITERS_HARD,
			SOLVER_TYPE_4ITERS_SOFT,
			SOLVER_TYPE_4ITERS_MEDIUM,
			SOLVER_TYPE_4ITERS_HARD,
			SOLVER_TYPE_8ITERS_SOFT,
			SOLVER_TYPE_8ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_HARD,
			SOLVER_TYPE_MAX_ID
		};
		enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
		enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
		enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
		hkpWorldCinfo();
		void setupSolverInfo(enum SolverType st);
		void setBroadPhaseWorldSize(hkReal size);
	public:
		hkVector4 m_gravity;
		hkInt32 m_broadPhaseQuerySize;
		hkReal m_contactRestingVelocity;
		hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
		class hkAabb m_broadPhaseWorldAabb;
		hkReal m_collisionTolerance;
		class hkpCollisionFilter* m_collisionFilter;
		class hkpConvexListFilter* m_convexListFilter;
		hkReal m_expectedMaxLinearVelocity;
		int m_sizeOfToiEventQueue;
		hkReal m_expectedMinPsiDeltaTime;
		class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
		hkInt32 m_broadPhaseNumMarkers;
		hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
		hkReal m_solverTau;
		hkReal m_solverDamp;
		hkInt32 m_solverIterations;
		hkInt32 m_solverMicrosteps;
		hkBool m_forceCoherentConstraintOrderingInSolver;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_enableDeprecatedWelding;
		hkReal m_iterativeLinearCastEarlyOutDistance;
		hkInt32 m_iterativeLinearCastMaxIterations;
		hkReal m_highFrequencyDeactivationPeriod;
		hkReal m_lowFrequencyDeactivationPeriod;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
		hkUint8 m_deactivationIntegrateCounter;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		int m_maxSectorsPerCollideTask;
		hkBool m_processToisMultithreaded;
		int m_maxEntriesPerToiCollideTask;
		hkBool m_enableDeactivation;
		hkEnum<SimulationType, hkInt8> m_simulationType;
		hkBool m_enableSimulationIslands;
		hkUint32 m_minDesiredIslandSize;
		hkBool m_processActionsInSingleThread;
		hkReal m_frameMarkerPsiSnap;
		virtual ~hkpWorldCinfo() {}
		explicit hkpWorldCinfo( hkFinishLoadedObjectFlag flag );
};
enum hkpCollidableAccept
{
	HK_COLLIDABLE_ACCEPT = 0,
	HK_COLLIDABLE_REJECT = 1
};
struct hkpCollidableAddedEvent;
struct hkpCollidableRemovedEvent;
class hkpPhantomOverlapListener
{
	public:
		virtual void collidableAddedCallback(   const hkpCollidableAddedEvent& event ) = 0;
		virtual void collidableRemovedCallback( const hkpCollidableRemovedEvent& event ) = 0;
		virtual ~hkpPhantomOverlapListener() {}
};
class hkpWorldDeletionListener
{
	public:
		virtual ~hkpWorldDeletionListener() {}
		virtual void worldDeletedCallback( hkpWorld* world) = 0;
};
class FUN_0098bd20 : public hkReferencedObject, protected hkpWorldDeletionListener, protected hkpPhantomOverlapListener
{
	public:
		FUN_0098bd20( hkpWorld* world, hkpWorldCinfo::BroadPhaseBorderBehaviour type  = hkpWorldCinfo::BROADPHASE_BORDER_ASSERT );
		virtual ~FUN_0098bd20();
		virtual void maxPositionExceededCallback( hkpEntity* body );
		virtual void deactivate();
		virtual void collidableAddedCallback( const hkpCollidableAddedEvent& event	);
		virtual void collidableRemovedCallback( const hkpCollidableRemovedEvent& event );
	public:
		virtual void worldDeletedCallback( hkpWorld* world );
		hkpWorld* m_world;
		class hkpPhantom* m_phantoms[6];
		hkpWorldCinfo::BroadPhaseBorderBehaviour m_type;
};
enum hkpPhantomType
{
	HK_PHANTOM_AABB = 0,
	HK_PHANTOM_SIMPLE_SHAPE = 1,
	HK_PHANTOM_CACHING_SHAPE = 2,
	HK_PHANTOM_USER0,
	HK_PHANTOM_USER1,
	HK_PHANTOM_USER2,
	HK_PHANTOM_USER3,
	HK_PHANTOM_USER4,
	HK_PHANTOM_USER5,
	HK_PHANTOM_USER6,
	HK_PHANTOM_USER7,
	HK_PHANTOM_USER8,
	HK_PHANTOM_USER9,
	HK_PHANTOM_MAX_ID
};
class hkpPhantomListener;
class hkpPhantom : public hkpWorldObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_PHANTOM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_PHANTOM); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_PHANTOM)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_PHANTOM); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		~hkpPhantom();
		virtual hkpPhantomType getType() const = 0;
		virtual void calcAabb( hkAabb& aabb ) = 0;
		virtual void addOverlappingCollidable( hkpCollidable* collidable ) = 0;
		virtual hkBool isOverlappingCollidableAdded( hkpCollidable* collidable ) = 0;
		virtual void removeOverlappingCollidable( hkpCollidable* collidable ) = 0;
		virtual hkpPhantom* clone() const = 0;
		void addPhantomListener( hkpPhantomListener* el);
		void removePhantomListener( hkpPhantomListener* el);
		void addPhantomOverlapListener( hkpPhantomOverlapListener* el);
		void removePhantomOverlapListener( hkpPhantomOverlapListener* el);
		inline const hkArray<hkpPhantomListener*>& getPhantomListeners() const;
		inline const hkArray<hkpPhantomOverlapListener*>& getPhantomOverlapListeners() const;
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		virtual void updateShapeCollectionFilter() {}
		void firePhantomAdded( );
		void firePhantomRemoved( );
		void firePhantomShapeSet( );
	protected:
		inline hkpPhantom( const hkpShape* shape );
		void firePhantomDeleted( );
	protected:
		inline hkpCollidableAccept fireCollidableAdded( const hkpCollidable* collidable );
		inline void fireCollidableRemoved( const hkpCollidable* collidable, hkBool collidableWasAdded );
	public:
		void updateBroadPhase( const hkAabb& aabb );
	protected:
		hkArray<hkpPhantomOverlapListener*> m_overlapListeners;
		hkArray<hkpPhantomListener*>	       m_phantomListeners;
	public:
		hkpPhantom( class hkFinishLoadedObjectFlag flag ) : hkpWorldObject( flag ) {}
		virtual void deallocateInternalArrays();
};
struct hkpWorldRayCastInput;
struct hkpWorldRayCastOutput;
struct hkpLinearCastInput;
class hkpCdPointCollector;
class hkpAabbPhantom : public hkpPhantom
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpAabbPhantom( const hkAabb& aabb, hkUint32 collisionFilterInfo = 0 );
		~hkpAabbPhantom();
		virtual hkpPhantomType getType() const;
		inline hkArray<hkpCollidable*>& getOverlappingCollidables();
		void castRay( const hkpWorldRayCastInput& input, hkpRayHitCollector& collector ) const;
		void castRay( const hkpWorldRayCastInput& input, hkpWorldRayCastOutput& output ) const;
		virtual void calcAabb( hkAabb& aabb );
		virtual void addOverlappingCollidable( hkpCollidable* collidable );
		virtual hkBool isOverlappingCollidableAdded( hkpCollidable* collidable );
		virtual void removeOverlappingCollidable( hkpCollidable* collidable );
		virtual hkpPhantom* clone() const;
		void setAabb(const hkAabb& newAabb);
		inline const hkAabb& getAabb( ) const;
		void calcStatistics( hkStatisticsCollector* collector ) const;
	protected:
		virtual hkMotionState* getMotionState(){ return 0; }
		class hkAabb m_aabb;
		hkArray<hkpCollidable*> m_overlappingCollidables;
	public:
		hkpAabbPhantom( class hkFinishLoadedObjectFlag flag );
		virtual void deallocateInternalArrays();
	private:
		void ensureSpuAlignment();
};
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkpCollisionDispatcher;
struct hkpCollisionInput;
struct hkpProcessCollisionInput;
class hkpCollisionListener;
class hkpTypedBroadPhaseDispatcher;
class hkpCdBodyPairCollector;
class hkpBroadPhase;
class hkpEntityListener;
class hkpRigidBody;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpAction;
class hkpActionListener;
class hkpConstraintListener;
class hkpPhysicsSystem;
class hkpSimulationIsland;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
namespace hkWorldOperation {
struct BaseOperation;
class UserCallback;
}
enum hkpUpdateCollisionFilterOnWorldMode
{
	HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
	HK_UPDATE_FILTER_ON_WORLD_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
};
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
enum hkpUpdateCollectionFilterMode
{
	HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS,
	HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS
};
struct hkpWorldDynamicsStepInfo
{
	hkStepInfo   m_stepInfo;
	hkpSolverInfo m_solverInfo;
};
struct hkpMultithreadConfig;
enum hkpThreadToken
{
	HK_THREAD_TOKEN_FIRST,
	HK_THREAD_TOKEN_SECOND,
	HK_THREAD_TOKEN_THIRD,
	HK_THREAD_TOKEN_FORTH,
	HK_THREAD_TOKEN_FIFTH,
	HK_THREAD_TOKEN_SIXTH,
};
enum hkpStepResult
{
	HK_STEP_RESULT_SUCCESS,
	HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};
class hkpWorld : public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpWorld(const hkpWorldCinfo& info, unsigned int sdkversion = ((10000*5) + (100*5) + (0)) );
		void getCinfo(hkpWorldCinfo& info) const;
		hkpEntity* addEntity( hkpEntity* entity, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
		hkBool removeEntity( hkpEntity* entity);
		void addEntityBatch( hkpEntity*const* entityBatch, int numEntities, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
		void removeEntityBatch( hkpEntity*const* entityBatch, int numEntities );
		hkpConstraintInstance* addConstraint( hkpConstraintInstance* constraint);
		hkBool removeConstraint( hkpConstraintInstance* constraint);
		hkpConstraintInstance* createAndAddConstraintInstance( hkpRigidBody* bodyA, hkpRigidBody* bodyB, hkpConstraintData* constraintData );
		hkpAction* addAction( hkpAction* action );
		void removeAction( hkpAction* action );
		void removeActionImmediately( hkpAction* action );
		hkpPhantom* addPhantom( hkpPhantom* phantom );
		void addPhantomBatch( hkpPhantom*const* phantomBatch, int numPhantoms );
		void removePhantom( hkpPhantom* phantom );
		void removePhantomBatch( hkpPhantom*const* phantomBatch, int numPhantoms );
		void activateRegion( const hkAabb& aabb );
		void addPhysicsSystem( const hkpPhysicsSystem* sys );
		void removePhysicsSystem( const hkpPhysicsSystem* sys );
		inline hkpRigidBody* getFixedRigidBody();
		inline const hkpRigidBody* getFixedRigidBody() const;
		void updateCollisionFilterOnEntity( hkpEntity* entity,
			                                hkpUpdateCollisionFilterOnEntityMode updateMode,
											hkpUpdateCollectionFilterMode updateShapeCollectionFilter);
		void addActionListener( hkpActionListener* worldListener );
		void removeActionListener( hkpActionListener* worldListener );
		void addConstraintListener( hkpConstraintListener* worldListener );
		void removeConstraintListener( hkpConstraintListener* worldListener );
		void addEntityListener( hkpEntityListener* worldListener );
		void removeEntityListener( hkpEntityListener* worldListener );
		void addPhantomListener( hkpPhantomListener* worldListener );
		void removePhantomListener( hkpPhantomListener* worldListener );
		void addIslandActivationListener( hkpIslandActivationListener* worldListener );
		void removeIslandActivationListener( hkpIslandActivationListener* worldListener );
		void addWorldPostCollideListener( hkpWorldPostCollideListener* worldListener );
		void removeWorldPostCollideListener( hkpWorldPostCollideListener* worldListener );
		void addWorldPostSimulationListener( hkpWorldPostSimulationListener* worldListener );
		void removeWorldPostSimulationListener( hkpWorldPostSimulationListener* worldListener );
		void addWorldPostIntegrateListener( hkpWorldPostIntegrateListener* worldListener );
		void removeWorldPostIntegrateListener( hkpWorldPostIntegrateListener* worldListener );
		void addIslandPostCollideListener( hkpIslandPostCollideListener* islandListener );
		void removeIslandPostCollideListener( hkpIslandPostCollideListener* islandListener );
		void addIslandPostIntegrateListener( hkpIslandPostIntegrateListener* islandListener );
		void removeIslandPostIntegrateListener( hkpIslandPostIntegrateListener* islandListener );
		void addCollisionListener( hkpCollisionListener* worldListener );
		void removeCollisionListener( hkpCollisionListener* worldListener);
		void addWorldDeletionListener( hkpWorldDeletionListener* worldListener );
		void removeWorldDeletionListener( hkpWorldDeletionListener* worldListener );
		void addContactImpulseLimitBreachedListener( hkpContactImpulseLimitBreachedListener* listener );
		void removeContactImpulseLimitBreachedListener( hkpContactImpulseLimitBreachedListener* listener );
		inline hkpBroadPhase* getBroadPhase();
		inline const hkpBroadPhase* getBroadPhase() const;
		inline const hkpProcessCollisionInput* getCollisionInput() const;
		inline hkpProcessCollisionInput* getCollisionInput();
		inline hkpSolverInfo* getSolverInfo();
		inline hkpCollisionDispatcher* getCollisionDispatcher() const;
		inline const hkpCollisionFilter* getCollisionFilter() const;
		void setCollisionFilter( hkpCollisionFilter* filter,
								 hkBool             runUpdateCollisionFilterOnWorld = true,
								 hkpUpdateCollisionFilterOnWorldMode checkBroadPhaseMode = HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
								 hkpUpdateCollectionFilterMode       updateShapeCollectionFilter = HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS );
		void castRay(const hkpWorldRayCastInput& input, hkpWorldRayCastOutput& output ) const;
		void castRay(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector ) const;
		void getClosestPoints( const hkpCollidable* collA, const hkpCollisionInput& input, hkpCdPointCollector& collector) const;
		void getPenetrations( const hkpCollidable* collA, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector) const;
		class FUN_0098bd20* getBroadPhaseBorder() const;
		void setBroadPhaseBorder( FUN_0098bd20* bpb );
		void shiftBroadPhase( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder );
		inline const hkArray<hkpSimulationIsland*>& getActiveSimulationIslands() const;
		inline const hkArray<hkpSimulationIsland*>& getInactiveSimulationIslands() const;
		inline const hkpSimulationIsland* getFixedIsland() const;
		hkpStepResult stepDeltaTime( hkReal physicsDeltaTime );
		hkpStepResult integrate( hkReal physicsDeltaTime );
		hkpStepResult collide();
		hkpStepResult advanceTime();
		void setFrameTimeMarker( hkReal frameDeltaTime );
		bool isSimulationAtMarker() const;
		bool isSimulationAtPsi() const;
		void stepBeginSt( hkReal physicsDeltaTime );
		void stepProcessMt( const hkpThreadToken& token );
		void stepEndSt();
		void resetThreadTokens();
		hkpThreadToken getThreadToken();
		hkTime getCurrentTime() const;
		hkTime getCurrentPsiTime() const;
		class hkJobQueue* getJobQueue();
		void getMultithreadConfig( hkpMultithreadConfig& config );
		void setMultithreadConfig( const hkpMultithreadConfig& config );
		hkMultiThreadCheck& getMultiThreadCheck() const { return m_multiThreadCheck; }
		void checkAccessGetActiveSimulationIslands() const;
		hkpPhysicsSystem* getWorldAsOneSystem() const;
		void getWorldAsSystems(hkArray<hkpPhysicsSystem*>& systemsOut) const;
		~hkpWorld();
	public:
		hkpSimulation* m_simulation;
		hkVector4			m_gravity;
        hkpSimulationIsland* m_fixedIsland;
			hkpRigidBody*	m_fixedRigidBody;
        hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
        hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
        hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
        hkpWorldMaintenanceMgr* m_maintenanceMgr;
        hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
        hkpBroadPhase* m_broadPhase;
        hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
        hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
        hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
        hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
        hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
        hkpProcessCollisionInput* m_collisionInput;
            hkpCollisionFilter*       m_collisionFilter;
            hkpCollisionDispatcher*   m_collisionDispatcher;
            hkpConvexListFilter*     m_convexListFilter;
        hkpWorldOperationQueue* m_pendingOperations;
			int m_pendingOperationsCount;
			int m_criticalOperationsLockCount;
			int m_criticalOperationsLockCountForPhantoms;
			hkBool m_blockExecutingPendingOperations;
			hkBool m_criticalOperationsAllowed;
            hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
			int m_pendingOperationQueueCount;
        mutable class hkMultiThreadCheck m_multiThreadCheck;
		hkBool m_processActionsInSingleThread;
		hkUint32 m_minDesiredIslandSize;
        class hkCriticalSection* m_modifyConstraintCriticalSection;
        class hkCriticalSection* m_worldLock;
        class hkCriticalSection* m_islandDirtyListCriticalSection;
		struct PropertyLock
		{
			hkUint32 m_key;
			mutable hkMultiThreadCheck m_multiThreadCheck;
		};
        class hkCriticalSection* m_propertyMasterLock;
		hkBool m_wantSimulationIslands;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_wantDeactivation;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		hkBool m_processToisMultithreaded;
		int m_maxSectorsPerCollideTask;
		int m_maxEntriesPerToiCollideTask;
        hkEnum<hkpWorldCinfo::SimulationType,hkInt32>  m_simulationType;
		static hkBool m_forceMultithreadedSimulation;
		class IgnoreForceMultithreadedSimulation
		{
			public:
				~IgnoreForceMultithreadedSimulation() { hkpWorld::m_forceMultithreadedSimulation = m_originalForceMultithreadedSimulationValue; }
			public:
				hkBool m_originalForceMultithreadedSimulationValue;
		};
	protected:
		hkUint32 m_lastEntityUid;
	public:
		friend class hkpWorldOperationUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpSimulation;
		friend class hkHalfstepSimulation;
		friend class hkpContinuousSimulation;
		friend class hkpMultiThreadedSimulation;
		friend class hkpSimpleConstraintContactMgr;
		hkArray<hkpPhantom*> m_phantoms;
        hkArray<hkpActionListener*>              m_actionListeners;
        hkArray<hkpEntityListener*>              m_entityListeners;
        hkArray<hkpPhantomListener*>             m_phantomListeners;
        hkArray<hkpConstraintListener*>          m_constraintListeners;
        hkArray<hkpWorldDeletionListener*>       m_worldDeletionListeners;
        hkArray<hkpIslandActivationListener*>    m_islandActivationListeners;
        hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
        hkArray<hkpWorldPostIntegrateListener*>  m_worldPostIntegrateListeners;
        hkArray<hkpWorldPostCollideListener*>    m_worldPostCollideListeners;
        hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
        hkArray<hkpIslandPostCollideListener*>   m_islandPostCollideListeners;
        hkArray<hkpCollisionListener*>           m_collisionListeners;
        hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
        class FUN_0098bd20*               m_broadPhaseBorder;
	public:
		struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
		hkVector4 m_broadPhaseExtents[2];
		int			m_broadPhaseNumMarkers;
		int			m_sizeOfToiEventQueue;
		hkInt32		m_broadPhaseQuerySize;
		hkInt32		m_broadPhaseUpdateSize;
        hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
		void attachActionToEntity(hkpAction* action, hkpEntity* entity);
		void detachActionFromEntity(hkpAction* action, hkpEntity* entity);
	public:
		__forceinline void	lockCriticalOperations();
		__forceinline void	unlockCriticalOperations();
		__forceinline int		areCriticalOperationsLocked() const;
		__forceinline int		areCriticalOperationsLockedUnchecked() const;
		__forceinline void	unlockCriticalOperationsForPhantoms();
		__forceinline void	lockCriticalOperationsForPhantoms();
		__forceinline int		areCriticalOperationsLockedForPhantoms() const;
		__forceinline void	blockExecutingPendingOperations(hkBool block);
		__forceinline void	unlockAndAttemptToExecutePendingOperations();
		__forceinline void	attemptToExecutePendingOperations();
						void	queueOperation(const hkWorldOperation::BaseOperation& operation);
						hkWorldOperation::UserCallback* queueCallback(hkWorldOperation::UserCallback* callback, hkUlong userData = 0);
	private:
		                void	internal_executePendingOperations();
	public:
		__forceinline void	allowCriticalOperations(hkBool allow);
		explicit hkpWorld( hkFinishLoadedObjectFlag flag );
};
// pdb: hkpBroadPhaseBorder::hkpBroadPhaseBorder | hkpBroadPhaseBorder.obj | fnv360_0822_retail, call_gap, low
// pdb params: world, type, postponeAndSortCallbacks
FUN_0098bd20::FUN_0098bd20( hkpWorld* world, hkpWorldCinfo::BroadPhaseBorderBehaviour type )
{
	m_world = world;
	m_type = type;
	addReference();
	m_world->addWorldDeletionListener( this );
	hkAabb infoAABB;
	const hkVector4 worldMin = m_world->m_broadPhaseExtents[0];
	const hkVector4 worldMax = m_world->m_broadPhaseExtents[1];
	{
		infoAABB.m_min.set( worldMax(0), worldMin(1), worldMin(2) );
		infoAABB.m_max.set( worldMax(0), worldMax(1), worldMax(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[0] = ph;
		world->addPhantom( ph );
	}
	{
		infoAABB.m_min.set( worldMin(0), worldMin(1), worldMin(2) );
		infoAABB.m_max.set( worldMin(0), worldMax(1), worldMax(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[1] = ph;
		world->addPhantom( ph );
	}
	{
		infoAABB.m_min.set( worldMin(0), worldMax(1), worldMin(2) );
		infoAABB.m_max.set( worldMax(0), worldMax(1), worldMax(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[2] = ph;
		world->addPhantom( ph );
	}
	{
		infoAABB.m_min.set( worldMin(0), worldMin(1), worldMin(2) );
		infoAABB.m_max.set( worldMax(0), worldMin(1), worldMax(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[3] = ph;
		world->addPhantom( ph );
	}
	{
		infoAABB.m_min.set( worldMin(0), worldMin(1), worldMax(2) );
		infoAABB.m_max.set( worldMax(0), worldMax(1), worldMax(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[4] = ph;
		world->addPhantom( ph );
	}
	{
		infoAABB.m_min.set( worldMin(0), worldMin(1), worldMin(2) );
		infoAABB.m_max.set( worldMax(0), worldMax(1), worldMin(2) );
		hkpAabbPhantom* ph = new hkpAabbPhantom( infoAABB );
		ph->getCollidableRw()->getBroadPhaseHandle()->setType( hkpWorldObject::BROAD_PHASE_BORDER );
		ph->addPhantomOverlapListener( this );
		m_phantoms[5] = ph;
		world->addPhantom( ph );
	}
}

}  // namespace f3m_0098bd20

// @f3 0x00995490 (community match, verified in this file)
#include <windows.h>
#include <math.h>
namespace Native2183 {


extern unsigned DAT_010f3170;
struct TempStack {
 virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();
 virtual void* AllocateOverflow(int);virtual void FreeOverflow(void*);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 char* top;char* unk24;char* boundary;char* end;
 void* Allocate(int n) { int size=(n+16)&~15;char* p=top;if(p+size<=end)top=p+size;else p=(char*)AllocateOverflow(size);return p; }
 void Free(void* p){top=(char*)p;if(p==boundary)FreeOverflow(p);}
};
extern void* (__stdcall *DAT_00d9b080)(unsigned long);
inline TempStack* GetTemp(){return (TempStack*)DAT_00d9b080(DAT_010f3170);}
struct __declspec(align(16)) S16c50_Vec4 {
 float x,y,z,w;
 void operator=(const S16c50_Vec4&v){x=v.x;y=v.y;z=v.z;w=v.w;}
 float& operator()(int i){return (&x)[i];}
 const float& operator()(int i)const{return (&x)[i];}
 void setZero4(){x=y=z=w=0.0f;}
 void setAdd4(const S16c50_Vec4&a,const S16c50_Vec4&b){x=a.x+b.x;y=a.y+b.y;z=a.z+b.z;w=a.w+b.w;}
 void setSub4(const S16c50_Vec4&a,const S16c50_Vec4&b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;w=a.w-b.w;}
};
union S16c50_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
extern S16c50_Vec4 DAT_01060dd0,DAT_01060db0;
__forceinline void S16c50_convertToUint16WithClip(const S16c50_Vec4& in,const S16c50_Vec4& offset,const S16c50_Vec4& scale,const S16c50_Vec4& minV,const S16c50_Vec4& maxV,S16c50_IntUnion64& out){
 S16c50_Vec4 x; x.setAdd4(offset,in);
x.x*=scale.x;
x.y*=scale.y;
x.z*=scale.z;
x.w*=scale.w;
if(!(x.x<maxV.x)) x.x=maxV.x;
if(!(x.y<maxV.y)) x.y=maxV.y;
if(!(x.z<maxV.z)) x.z=maxV.z;
if(!(x.w<maxV.w)) x.w=maxV.w;
if(!(x.x>minV.x)) x.x=minV.x;
if(!(x.y>minV.y)) x.y=minV.y;
if(!(x.z>minV.z)) x.z=minV.z;
if(!(x.w>minV.w)) x.w=minV.w;
x.x+=DAT_01060db0.x;out.u16[0]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.x)[0]>>7);
x.y+=DAT_01060db0.y;out.u16[1]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.y)[0]>>7);
x.z+=DAT_01060db0.z;out.u16[2]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.z)[0]>>7);
x.w+=DAT_01060db0.w;out.u16[3]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.w)[0]>>7);
}
__forceinline void S16c50_convertToUint16WithClipB(const S16c50_Vec4& in,const S16c50_Vec4& offset,const S16c50_Vec4& scale,const S16c50_Vec4& minV,const S16c50_Vec4& maxV,S16c50_IntUnion64& out){
 S16c50_Vec4 x; const float* pi=&in.x; const float* po=&offset.x; x.x=pi[0]+po[0];x.y=pi[1]+po[1];x.z=pi[2]+po[2];x.w=pi[3]+po[3];
x.x*=scale.x;
x.y*=scale.y;
x.z*=scale.z;
x.w*=scale.w;
if(!(x.x<maxV.x)) x.x=maxV.x;
if(!(x.y<maxV.y)) x.y=maxV.y;
if(!(x.z<maxV.z)) x.z=maxV.z;
if(!(x.w<maxV.w)) x.w=maxV.w;
if(!(x.x>minV.x)) x.x=minV.x;
if(!(x.y>minV.y)) x.y=minV.y;
if(!(x.z>minV.z)) x.z=minV.z;
if(!(x.w>minV.w)) x.w=minV.w;
x.x+=DAT_01060db0.x;out.u16[0]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.x)[0]>>7);
x.y+=DAT_01060db0.y;out.u16[1]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.y)[0]>>7);
x.z+=DAT_01060db0.z;out.u16[2]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.z)[0]>>7);
x.w+=DAT_01060db0.w;out.u16[3]=(unsigned short)(reinterpret_cast<const unsigned*>(&x.w)[0]>>7);
}
struct S16c50_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    int isMaxPoint() const { return m_uiFilterValue & 1; }
};
struct S16c50_Node {
    unsigned short m_min_y;
    unsigned short m_min_z;
    unsigned short m_max_y;
    unsigned short m_max_z;
    unsigned short m_min_x;
    unsigned short m_max_x;
    unsigned int m_handle;
    int isMarker() const { return m_handle & 1; }
};
struct S16c50_Axis {
    S16c50_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_EndPoint* begin() const { return m_data; }
    const S16c50_EndPoint& operator[](int i) const { return m_data[i]; }
};
struct S16c50_NodeArray {
    S16c50_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_Node& operator[](int i) const { return m_data[i]; }
};

struct S16c50_ByteArray {
 unsigned char* m_data;
 __forceinline S16c50_ByteArray(int n){m_data=(unsigned char*)GetTemp()->Allocate(n);}
 __forceinline ~S16c50_ByteArray(){GetTemp()->Free(m_data);}
 unsigned char* begin(){return m_data;}
};
struct S16c50_Collector {
    virtual void v0();
    virtual float ReleaseCollector(unsigned int handle, int castIndex);
};
struct S16c50_CastAabbInput {
    S16c50_Vec4 m_vFrom;
    S16c50_Vec4 m_vTo;
    S16c50_Vec4 m_vHalfExtents;
    const char* m_pBroadPhaseAabbCache;
};

extern const double DAT_010c9300;
extern const float DAT_0104a494, DAT_00dbcbd0;

static __forceinline void S16c50_memclear16(void* dest, int numBytes)
{
    S16c50_Vec4 zero; zero.setZero4();
    S16c50_Vec4* d = (S16c50_Vec4*)dest;
    for (numBytes = numBytes >> 4; numBytes >= 0; numBytes--) {
        *(d++) = zero;
    }
}

static __forceinline float S16c50_min2(float a, float b) { return a < b ? a : b; }

template <class T> static inline void S16c50_swap(T& a, T& b) { T t = a; a = b; b = t; }

static __forceinline int S16c50_getMinComponent(const S16c50_Vec4& v, float& m)
{
    if (v(0) < v(1)) {
        if (v(0) < v(2)) { m = v(0); return 0; }
    } else if (v(1) < v(2)) {
        m = v(1); return 1;
    }
    m = v(2); return 2;
}

__declspec(noinline) int __cdecl FUN_009983b0(const float* v, float* m)
{
    if (v[0] < v[1]) {
        if (v[0] < v[2]) { *m = v[0]; return 0; }
    } else if (v[1] < v[2]) {
        *m = v[1]; return 1;
    }
    *m = v[2]; return 2;
}

static __forceinline void S16c50_calcCurDist(int axis, S16c50_Vec4& curDist, const S16c50_EndPoint* ep, const S16c50_Vec4& invDir, const S16c50_Vec4& start)
{
    curDist(axis) = ep->m_uiFilterValue * invDir(axis) - start(axis);
}

struct S16c50_Sweep {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    S16c50_Vec4 m_kVectorAt40;
    S16c50_Vec4 m_kVectorAt50;
    S16c50_Vec4 m_vScale;
    S16c50_Vec4 unk70;
    S16c50_Vec4 unk80;
    S16c50_Vec4 unk90;
    S16c50_NodeArray m_kNodeCollection;
    S16c50_Axis m_kAxisEndPoints[3];
    int m_iMarkerCount;
    int m_iMarkerCapacity;
    void* m_pOverlappingMarkerInfo;
    float m_fValueAfterOverlappingMarkerInfo;

    __forceinline void convertVectorToInt(const S16c50_Vec4& vec, unsigned int* intsOut) const
    {
        S16c50_Vec4 minVal; minVal.setZero4();
        S16c50_Vec4 maxVal = DAT_01060dd0;
        S16c50_IntUnion64 out;
        S16c50_convertToUint16WithClip(vec, m_kVectorAt40, m_vScale, minVal, maxVal, out);
        intsOut[0] = out.u16[0];
        intsOut[1] = out.u16[1];
        intsOut[2] = out.u16[2];
        intsOut[3] = out.u16[3];
    }
    __forceinline void convertVectorToIntB(const S16c50_Vec4& vec, unsigned int* intsOut) const
    {
        S16c50_Vec4 minVal; minVal.setZero4();
        S16c50_Vec4 maxVal = DAT_01060dd0;
        S16c50_IntUnion64 out;
        S16c50_convertToUint16WithClipB(vec, m_kVectorAt40, m_vScale, minVal, maxVal, out);
        intsOut[0] = out.u16[0];
        intsOut[1] = out.u16[1];
        intsOut[2] = out.u16[2];
        intsOut[3] = out.u16[3];
    }
    void hkp3AxisSweep_castAabb(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const;
};

// pdb: hkp3AxisSweep::castAabb | hkp3AxisSweep.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc + skyrim(caller_sim), high
void S16c50_Sweep::hkp3AxisSweep_castAabb(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const
{
    S16c50_Vec4 fromMin; fromMin.setSub4(input.m_vFrom, input.m_vHalfExtents);
    S16c50_Vec4 fromMax; fromMax.setAdd4(input.m_vFrom, input.m_vHalfExtents);
    __declspec(align(16)) unsigned int auiLowerBounds[4];
    __declspec(align(16)) unsigned int auiUpperBounds[4];
    convertVectorToInt(fromMin, auiLowerBounds);
    convertVectorToIntB(fromMax, auiUpperBounds);

    S16c50_ByteArray bitFieldArray(m_kNodeCollection.GetLogicalSize() + 16);
    S16c50_memclear16(bitFieldArray.begin(), m_kNodeCollection.GetLogicalSize());

    const S16c50_Axis* axisArray = input.m_pBroadPhaseAabbCache ? (const S16c50_Axis*)input.m_pBroadPhaseAabbCache : &m_kAxisEndPoints[0];

    const S16c50_EndPoint* enterCur[3];
    const S16c50_EndPoint* exitCur[3];
    {
        unsigned char* bitField;
        bitField = bitFieldArray.begin();
        int mask = 1;
        for (int i = 0; 3 > i; i++) {
            const S16c50_Axis& val = axisArray[i];
            if (auiLowerBounds[i] < val[val.GetLogicalSize() >> 1].m_uiFilterValue) {
                const S16c50_EndPoint* curEnter = val.begin() + val.GetLogicalSize() - 4;
                const S16c50_EndPoint* enterAxis = &val[1];
                for (; enterAxis < curEnter; enterAxis += 4) {
                    if (enterAxis[3].m_uiFilterValue > auiLowerBounds[i]) break;
                    bitField[enterAxis[0].m_usIndex] ^= mask;
                    bitField[enterAxis[1].m_usIndex] ^= mask;
                    bitField[enterAxis[2].m_usIndex] ^= mask;
                    bitField[enterAxis[3].m_usIndex] ^= mask;
                }
                for (; enterAxis->m_uiFilterValue <= auiLowerBounds[i]; enterAxis++) {
                    bitField[enterAxis->m_usIndex] ^= mask;
                }
                enterCur[i] = enterAxis;
                for (; enterAxis->m_uiFilterValue <= auiUpperBounds[i]; enterAxis++) {
                    bitField[enterAxis->m_usIndex] ^= mask & (enterAxis->isMaxPoint() - 1);
                }
                exitCur[i] = enterAxis;
            } else {
                const S16c50_EndPoint* pEnd;
                pEnd = val.begin() + 4;
                const S16c50_EndPoint* enterAxis;
                enterAxis = &val[val.GetLogicalSize() - 2];
                for (; enterAxis >= pEnd; enterAxis -= 4) {
                    if (enterAxis[-3].m_uiFilterValue <= auiUpperBounds[i]) break;
                    bitField[enterAxis[0].m_usIndex] ^= mask;
                    bitField[enterAxis[-1].m_usIndex] ^= mask;
                    bitField[enterAxis[-2].m_usIndex] ^= mask;
                    bitField[enterAxis[-3].m_usIndex] ^= mask;
                }
                for (; enterAxis->m_uiFilterValue > auiUpperBounds[i]; enterAxis--) {
                    bitField[enterAxis->m_usIndex] ^= mask;
                }
                exitCur[i] = 1 + enterAxis;
                for (; enterAxis->m_uiFilterValue > auiLowerBounds[i]; enterAxis--) {
                    bitField[enterAxis->m_usIndex] ^= mask & (-enterAxis->isMaxPoint());
                }
                enterCur[i] = 1 + enterAxis;
            }
            mask <<= 1;
        }
    }

    float earliestHit = 1.0f;
    {
        const S16c50_Node* node = &m_kNodeCollection[0];
        int lo = m_kNodeCollection.GetLogicalSize();
        unsigned char* axis = bitFieldArray.begin();
        const unsigned int* startDist = (const unsigned int*)axis;
        const unsigned int* flipEnter = startDist + (lo >> 2) + 1;
        for (; startDist < flipEnter; node += 4, startDist++) {
            if (((*startDist + 0x01010101) & 0x08080808) == 0) continue;
            const unsigned char* b = (const unsigned char*)startDist;
            if (b[0] == 7 && !node[0].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[0].m_handle, 0));
            if (b[1] == 7 && !node[1].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[1].m_handle, 0));
            if (b[2] == 7 && !node[2].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[2].m_handle, 0));
            if (b[3] == 7 && !node[3].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[3].m_handle, 0));
        }
    }

    S16c50_Vec4 dir; dir.setSub4(input.m_vTo, input.m_vFrom);
    S16c50_Vec4 invDir;
    S16c50_Vec4 p;
    S16c50_Vec4 endDist;
    unsigned int step[3];
    int start[3];
    unsigned int flipExit[3];
    for (int i = 0; 3 > i; i++) {
        float d = m_vScale(i) * dir(i);
        float absD = fabsf(d);
        if (d > 0.0) {
            step[i] = 4;
            start[i] = 0;
            flipExit[i] = 1;
        } else {
            step[i] = -4;
            S16c50_swap(enterCur[i], exitCur[i]);
            S16c50_swap(fromMin(i), fromMax(i));
            S16c50_swap(auiLowerBounds[i], auiUpperBounds[i]);
            enterCur[i]--;
            exitCur[i]--;
            start[i] = 1;
            flipExit[i] = 0;
        }
        float a = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
        float n = m_kVectorAt40(i);
        float b = (input.m_vTo(i) + n) * m_vScale(i);
        if (absD < a * 1.1920928955078125e-07 || absD < b * 1.1920928955078125e-07) {
            invDir(i) = 0.0f;
            p(i) = -2.0f;
            endDist(i) = -2.0f;
        } else {
            float inv = 1.0f / d;
            invDir(i) = inv;
            float s0 = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
            float s1 = s0 - m_fValueAfterOverlappingMarkerInfo;
            p(i) = inv * s1;
            float e0 = (fromMax(i) + m_kVectorAt40(i)) * m_vScale(i);
            float e1 = e0 - m_fValueAfterOverlappingMarkerInfo;
            endDist(i) = e1 * inv;
        }
    }

    S16c50_Vec4 enterDist;
    S16c50_Vec4 value;
    const S16c50_EndPoint* end[3] = { enterCur[0], enterCur[1], enterCur[2] };
    const S16c50_EndPoint* curExit[3] = { exitCur[0], exitCur[1], exitCur[2] };
    enterDist(0) = end[0]->m_uiFilterValue * invDir(0) - p(0);
    enterDist(1) = end[1]->m_uiFilterValue * invDir(1) - p(1);
    enterDist(2) = end[2]->m_uiFilterValue * invDir(2) - p(2);
    value(0) = curExit[0]->m_uiFilterValue * invDir(0) - endDist(0);
    value(1) = curExit[1]->m_uiFilterValue * invDir(1) - endDist(1);
    value(2) = curExit[2]->m_uiFilterValue * invDir(2) - endDist(2);

    unsigned char* bitField = bitFieldArray.begin();
    bitField[0] = 8;
    float r;
    float d2;
    float d3;
    float d4;
    float d5;
    int ep;
    ep = S16c50_getMinComponent(enterDist, r);
    int exitAxis = S16c50_getMinComponent(value, r);

    while (1) {
        if (value(exitAxis) < enterDist(ep)) {
            if (value(exitAxis) > earliestHit) break;
            while (1) {
                unsigned long nodeIndex = curExit[exitAxis]->m_usIndex;
                int m = (curExit[exitAxis]->isMaxPoint() ^ flipExit[exitAxis]) << exitAxis;
                bitField[nodeIndex] ^= m;
                if (bitField[nodeIndex] >= 7 && m) {
                    if (!nodeIndex) {
                        value(exitAxis) = DAT_00dbcbd0;
                        exitAxis = FUN_009983b0(&value(0), &d2);
                        break;
                    }
                    const S16c50_Node& node = m_kNodeCollection[nodeIndex];
                    if (!node.isMarker()) {
                        earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node.m_handle, 0));
                    }
                }
                unsigned short exitDist = curExit[exitAxis]->m_uiFilterValue;
                curExit[exitAxis] = (const S16c50_EndPoint*)((const char*)curExit[exitAxis] + step[exitAxis]);
                if (exitDist == curExit[exitAxis]->m_uiFilterValue) continue;
                S16c50_EndPoint enterAxis = *curExit[exitAxis];
                S16c50_calcCurDist(exitAxis, value, &enterAxis, invDir, endDist);
                exitAxis = FUN_009983b0(&value(0), &d3);
                break;
            }
        } else {
            if (enterDist(ep) > earliestHit) break;
            while (1) {
                unsigned int nodeIndex = end[ep]->m_usIndex;
                bitField[nodeIndex] ^= (end[ep]->isMaxPoint() ^ start[ep]) << ep;
                if (bitField[nodeIndex] > 8) {
                    enterDist(ep) = DAT_00dbcbd0;
                    ep = FUN_009983b0(&enterDist(0), &d4);
                    break;
                }
                unsigned short exitDist = end[ep]->m_uiFilterValue;
                end[ep] = (const S16c50_EndPoint*)((const char*)end[ep] + step[ep]);
                if (exitDist == end[ep]->m_uiFilterValue) continue;
                S16c50_EndPoint enterAxis = *end[ep];
                S16c50_calcCurDist(ep, enterDist, &enterAxis, invDir, p);
                ep = FUN_009983b0(&enterDist(0), &d5);
                break;
            }
        }
    }
}
}

// @f3 0x00994260 (community match, verified in this file)
extern unsigned long hkMonitorStreamTls;
extern unsigned long DAT_010f3170;
extern const char DAT_00e7d4dc[];
namespace f3m_00994260 {
extern "C" __declspec(dllimport) void* __stdcall DAT_00d9b080(unsigned long dwTlsIndex);

class hkBool
{
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) : m_bool(static_cast<char>(b)) {}
    __forceinline operator bool() const { return m_bool != 0; }
private:
    char m_bool;
};

template <typename T>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return m_storage; }
    __forceinline void operator=(T v) { m_storage = v; }
private:
    T m_storage;
};

class hkMonitorStream
{
public:
    static __forceinline hkMonitorStream& getInstance()
    {
        return *(hkMonitorStream*)DAT_00d9b080(hkMonitorStreamTls);
    }

    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
    hkBool m_isBufferAllocatedOnTheHeap;

    struct Command
    {
        const char* m_commandAndMonitor;
    };

    struct TimerCommand : public Command
    {
        unsigned int m_time0;
        unsigned int m_time1;

        __forceinline void setTime()
        {
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }
    };
};

class hkThreadMemory
{
public:
    virtual ~hkThreadMemory();
    virtual void* alignedAllocate(int alignment, int nbytes, int cl);
    virtual void alignedDeallocate(void* ptr);
    virtual void* allocateChunk(int nbytes, int cl);
    virtual void deallocateChunk(void* ptr, int nbytes, int cl);
    virtual void* onStackOverflow(int nbytes);
    virtual void onStackUnderflow(void* ptr);

    static __forceinline hkThreadMemory& getInstance()
    {
        return *(hkThreadMemory*)DAT_00d9b080(DAT_010f3170);
    }

    __forceinline void* allocateStack(int nbytes)
    {
        nbytes = (nbytes + 0x10) & ~0xf;
        char* p = m_stack.m_current;
        char* next = p + nbytes;
        if (next <= m_stack.m_end)
        {
            m_stack.m_current = next;
            return p;
        }
        return onStackOverflow(nbytes);
    }

    __forceinline void deallocateStack(void* p)
    {
        m_stack.m_current = static_cast<char*>(p);
        if (p == m_stack.m_base)
        {
            onStackUnderflow(p);
        }
    }

    struct Stack
    {
        char* m_current;
        Stack* m_prev;
        char* m_base;
        char* m_end;
    };

    void* m_memory;
    int m_referenceCount;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Stack m_stack;
};

template <typename T>
__forceinline T* hkAllocateStack(int n)
{
    return static_cast<T*>(hkThreadMemory::getInstance().allocateStack(n * sizeof(T)));
}

template <typename T>
__forceinline void hkDeallocateStack(T* p)
{
    hkThreadMemory::getInstance().deallocateStack(static_cast<void*>(p));
}

void __cdecl FUN_00901f10(void* arr, int elemSize);

template <typename T>
class hkArray
{
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline T* begin() { return m_data; }
    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    __forceinline T& expandOne()
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        return m_data[m_size++];
    }
    __forceinline void pushBack(const T& t)
    {
        if (m_size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = t;
        m_size++;
    }
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T>
class hkLocalBuffer
{
public:
    __forceinline hkLocalBuffer(int n) { m_p = hkAllocateStack<T>(n); }
    __forceinline ~hkLocalBuffer() { hkDeallocateStack<T>(m_p); }
    __forceinline T* begin() { return m_p; }
    T* m_p;
};

struct hkpBroadPhaseHandle
{
    unsigned int m_id;
};

struct hkpBroadPhaseHandlePair
{
    hkpBroadPhaseHandle* m_a;
    hkpBroadPhaseHandle* m_b;
};

struct __declspec(align(16)) hkAabbUint32
{
    unsigned int m_min[3];
    unsigned int m_expansionMin;
    unsigned int m_max[3];
    unsigned int m_expansionMax;
};

struct hkpBpNode
{
    unsigned short min_y;
    unsigned short min_z;
    unsigned short max_y;
    unsigned short max_z;
    unsigned short min_x;
    unsigned short max_x;
    hkpBroadPhaseHandle* m_handle;
    __forceinline int yzDisjoint(const hkpBpNode& other) const
    {
        unsigned int maxA = *(const unsigned int*)&max_y;
        unsigned int minB = *(const unsigned int*)&other.min_y;
        unsigned int maxB = *(const unsigned int*)&other.max_y;
        unsigned int minA = *(const unsigned int*)&min_y;
        maxA -= minB;
        maxB -= minA;
        return (maxA | maxB) & 0x80008000;
    }
    __forceinline int isMarker() const { return int(m_handle) & 1; }
};

struct hkpBpEndPoint
{
    unsigned short m_value;
    unsigned short m_nodeIndex;
};

class hkpBpAxis
{
public:
    void FUN_00991c00(hkpBpNode* nodes, int nodeIndex, unsigned int minPosition, unsigned int maxPosition,
        unsigned short& minInsertPositionOut, unsigned short& maxInsertPositionOut);
    hkArray<hkpBpEndPoint> m_endPoints;
};

struct hkpBpMarker
{
    hkpBroadPhaseHandle* m_nodeIndex;
    hkArray<unsigned short> m_overlappingObjects;
};

class hkp3AxisSweep
{
public:
    int unk00[0x28];
    hkArray<hkpBpNode> m_nodes;
    hkpBpAxis m_axis[3];
    int unkd0;
    int unkd4;
    hkpBpMarker* m_markers;
    void FUN_00990ab0(hkpBpNode* nodes, int nodeIndex, hkpBpNode& node);
    void FUN_00991290(int numNodes, unsigned int minX, hkpBpNode& node, int nodeIndex, unsigned int* bitField);
    __forceinline hkpBpMarker& getMarkerFromNode(const hkpBpNode& node) const
    {
        return *(hkpBpMarker*)((char*)m_markers + (int(node.m_handle) & ~1));
    }
    void collect(hkpBroadPhaseHandle* object, int nodeIndex, const hkpBpNode& node, unsigned int* bits, hkArray<hkpBroadPhaseHandlePair>& newPairsOut);
    void FUN_00994260(hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& newPairsOut);
};

__forceinline void hkp3AxisSweep::collect(hkpBroadPhaseHandle* object, int nodeIndex, const hkpBpNode& node, unsigned int* bits, hkArray<hkpBroadPhaseHandlePair>& newPairsOut)
{
    hkpBpNode* base = m_nodes.begin();
    unsigned int* end = bits + (m_nodes.getSize() >> 5) + 1;
    for (; bits < end; base += 32, bits++)
    {
        hkpBpNode* n = base;
        unsigned int b = *bits;
        while (b)
        {
            if ((b & 0xff) == 0)
            {
                n += 8;
                b >>= 8;
                continue;
            }
            if (b & 1)
            {
                if (!n->yzDisjoint(node))
                {
                    hkpBroadPhaseHandle* h = n->m_handle;
                    if (!(int(h) & 1))
                    {
                        hkpBroadPhaseHandlePair pair;
                        pair.m_a = object;
                        pair.m_b = h;
                        newPairsOut.pushBack(pair);
                    }
                    else
                    {
                        hkpBpMarker& m = *(hkpBpMarker*)((char*)m_markers + (int(h) & ~1));
                        m.m_overlappingObjects.pushBack((unsigned short)nodeIndex);
                    }
                }
            }
            n++;
            b >>= 1;
        }
    }
}

// pdb: hkp3AxisSweep::addObject | hkp3AxisSweep.obj | tesv_win, objrun_prop, low
void hkp3AxisSweep::FUN_00994260(hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& newPairsOut)
{
    hkAabbUint32 a;
    a.m_min[0] = aabb.m_min[0] >> 15;
    a.m_min[1] = aabb.m_min[1] >> 15;
    a.m_min[2] = aabb.m_min[2] >> 15;
    for (int i = 0; i < 3; i++)
    {
        unsigned int m = aabb.m_max[i] >> 15;
        if (m != 0xffff) m++;
        a.m_max[i] = m | 1;
    }
    a.m_min[0] &= 0xfffe;
    a.m_min[1] &= 0xfffe;
    a.m_min[2] &= 0xfffe;

    int nodeIndex = m_nodes.getSize();
    hkpBpNode& node = m_nodes.expandOne();
    hkpBpNode* nodes = m_nodes.begin();
    m_axis[0].FUN_00991c00(nodes, nodeIndex, a.m_min[0], a.m_max[0], node.min_x, node.max_x);
    m_axis[1].FUN_00991c00(nodes, nodeIndex, a.m_min[1], a.m_max[1], node.min_y, node.max_y);
    m_axis[2].FUN_00991c00(nodes, nodeIndex, a.m_min[2], a.m_max[2], node.min_z, node.max_z);
    FUN_00990ab0(nodes, nodeIndex, node);
    node.m_handle = object;
    object->m_id = nodeIndex;

    int numNodes = m_nodes.getSize();
    hkLocalBuffer<unsigned int> bitField((numNodes >> 5) + 8);
    FUN_00991290(numNodes, a.m_min[0], node, nodeIndex, bitField.begin());

    collect(object, nodeIndex, node, bitField.begin(), newPairsOut);
}
}   // namespace f3m_00994260

// @f3 0x00999610 (community match, verified in this file)
// 0x00999610: hkAgentNnMachine_ProcessAgent(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& input,
// hkpProcessCollisionOutput& output, hkpContactMgr* mgr) of Havok 5.5.0 (hkpInternal, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Processes one agent of an Nn track by its stream command: a bridged old-style agent, an agent3 process call, or
// an agent3 call guarded by its time-of-impact separating plane (refreshed at the start of the step with
// continuous physics, otherwise reset), with a cleanup when the bodies are apart.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by hkreduce, then single lines; no data member, enumerator or virtual function of a kept class was
// cut; every cut checked against the SDK's release library object; whitespace compacted); those declarations are
// the SDK's text with its names. The function's body is the SDK file's static helper hkAgentNnMachine_InlineProcessAgent,
// inlined (its source is not shipped): reconstructed with the SDK's shipped types as the helper below, with the
// helper's real parameter list as the SDK release object's symbol and debug record give it (the int offset feeds
// the agent3 input's PPU offset; mgr is not read, as in the original). Only the function carries the packet's name.
namespace f3m_00999610 {
typedef float hkReal;
typedef signed char hkChar;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
inline hkBool()
{
}
inline hkBool(bool b)
{
m_bool=static_cast<char>(b);
}
inline operator bool()const
{
return m_bool !=0;
}
inline hkBool&operator=(bool e)
{
m_bool=static_cast<char>(e);
return*this;
}
inline hkBool operator==(bool e)const
{
return static_cast<int>(m_bool)==static_cast<int>(e);
}
inline hkBool operator!=(bool e)const
{
return static_cast<int>(m_bool)!=static_cast<int>(e);
}
private:
char m_bool;
};
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
enum{MAX_VALUE=256};
inline hkUFloat8(){}
inline hkUFloat8&operator=(const float&fv)
{
hkInt32 f=*(int*)&fv;
hkInt32*minf=(hkInt32*)&hkUFloat8_intToReal[0];
hkInt32*maxf=(hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
hkInt32*midf=(hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
for(int i=6;i>=0;i--)
{
if(f > midf[0]){minf=midf;}else{maxf=midf;}
midf=(hkInt32*)((hkUlong(minf)>>1)+(hkUlong(maxf)>>1));
}
if(f > midf[0])
{
midf++;
}
hkUlong fi=midf-(hkInt32*)(&hkUFloat8_intToReal[0]);
m_value=hkUint8(fi);
return*this;
}
inline hkUFloat8(const float f)
{
*this=f;
}
inline operator float()const
{
return hkUFloat8_intToReal[m_value];
}
public:
hkUint8 m_value;
};
template <typename TYPE>
class hkPadSpu
{
public:
__forceinline hkPadSpu(){}
__forceinline hkPadSpu(TYPE e)
: m_storage(e)
{
}
__forceinline void operator=(TYPE e)
{
m_storage=e;
}
__forceinline TYPE val()const
{
return m_storage;
}
__forceinline TYPE operator->()const
{
return m_storage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_storage;
};
enum HK_MEMORY_CLASS{
HK_MEMORY_CLASS_ROOT,
HK_MEMORY_CLASS_BASE,
HK_MEMORY_CLASS_COLLIDE,
HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
HK_MEMORY_CLASS_DYNAMICS,
HK_MEMORY_CLASS_EXPORT,
HK_MEMORY_CLASS_SERIALIZE,
HK_MEMORY_CLASS_GEOMETRY,
HK_MEMORY_CLASS_DISPLAY,
HK_MEMORY_CLASS_MATH,
HK_MEMORY_CLASS_SCENE_DATA,
HK_MEMORY_CLASS_VEHICLE,
HK_MEMORY_CLASS_DESTRUCTION,
HK_MEMORY_CLASS_UTILITIES,
HK_MEMORY_CLASS_ANIMATION,
HK_MEMORY_CLASS_BEHAVIOR,
HK_MEMORY_CLASS_CLOTH,
HK_MEMORY_CLASS_TOOLS,
HK_MEMORY_CLASS_DEMO_FRAMEWORK,
HK_MEMORY_CLASS_DEMO,
HK_MEMORY_CLASS_USER,
HK_MEMORY_CLASS_BASE_CLASS,
HK_MEMORY_CLASS_STRING,
HK_MEMORY_CLASS_ARRAY,
HK_MEMORY_CLASS_SINGLETON,
HK_MEMORY_CLASS_SCRATCHPAD,
HK_MEMORY_CLASS_STREAM,
HK_MEMORY_CLASS_MONITOR,
HK_MEMORY_CLASS_MAP,
HK_MEMORY_CLASS_TREE,
HK_MEMORY_CLASS_HKCLASS,
HK_MEMORY_CLASS_AGENT,
HK_MEMORY_CLASS_ALGORITHM,
HK_MEMORY_CLASS_BROAD_PHASE,
HK_MEMORY_CLASS_CONTACT,
HK_MEMORY_CLASS_DISPATCH,
HK_MEMORY_CLASS_MANIFOLD,
HK_MEMORY_CLASS_SHAPE,
HK_MEMORY_CLASS_COLLIDABLE,
HK_MEMORY_CLASS_CDINFO,
HK_MEMORY_CLASS_MOPP,
HK_MEMORY_CLASS_ACTION,
HK_MEMORY_CLASS_DYNCOLLIDE,
HK_MEMORY_CLASS_DEACTIVATOR,
HK_MEMORY_CLASS_CONSTRAINT,
HK_MEMORY_CLASS_ENTITY,
HK_MEMORY_CLASS_MOTION,
HK_MEMORY_CLASS_WORLD,
HK_MEMORY_CLASS_RIGID_BODY,
HK_MEMORY_CLASS_PHANTOM,
HK_MEMORY_CLASS_SIMISLAND,
HK_MEMORY_CLASS_CAMERA,
HK_MEMORY_CLASS_CHARACTER,
HK_MEMORY_CLASS_VDB,
HK_MEMORY_CLASS_INERTIA,
HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
HK_MEMORY_CLASS_ANIM_COMPRESSED,
HK_MEMORY_CLASS_ANIM_DATA,
HK_MEMORY_CLASS_ANIM_MOTION,
HK_MEMORY_CLASS_ANIM_RIG,
HK_MEMORY_CLASS_ANIM_CONTROL,
HK_MEMORY_CLASS_ANIM_RUNTIME,
HK_MEMORY_CLASS_ANIM_CACHE,
HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
HK_MEMORY_CLASS_CLOTH_RUNTIME,
HK_MEMORY_CLASS_CLOTH_DATA,
HK_MEMORY_CLASS_USER_1,
HK_MEMORY_CLASS_USER_2,
HK_MEMORY_CLASS_USER_3,
HK_MEMORY_CLASS_USER_4,
HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX};
class hkMemory;
extern void*(__cdecl*hkSystemMalloc)(int size,int align);
extern void(__cdecl*hkSystemFree)(void*p);
class hkThreadMemory
{
public:
hkThreadMemory(hkMemory*mainMemoryManager,int maxNumElemsOnFreeList=16);
void*allocateChunk(int nbytes,HK_MEMORY_CLASS cl);
void deallocateChunk(void*,int nbytes,HK_MEMORY_CLASS);
void*allocate(int nbytes,HK_MEMORY_CLASS cl);
void deallocate(void*);
__forceinline void*allocateChunkConstSize(int nbytes,HK_MEMORY_CLASS cl);
__forceinline void deallocateChunkConstSize(void*p,int nbytes,HK_MEMORY_CLASS cl);
__forceinline void*allocateStack(int nbytes);
__forceinline void shrinkAllocatedStack(void*ptr,int newSize);
__forceinline void deallocateStack(void*p);
virtual void*alignedAllocate(int alignment,int nbytes,HK_MEMORY_CLASS cl);
virtual void alignedDeallocate(void*ptr);
virtual void setStackArea(void*buf,int nbytes);
static inline hkThreadMemory*__cdecl getInstancePtr();
static inline hkThreadMemory&__cdecl getInstance();
static void __cdecl replaceInstance(hkThreadMemory*m);
void addReference();
void removeReference();
virtual void releaseCachedMemory();
__forceinline virtual ~hkThreadMemory(){releaseCachedMemory();}
protected:
virtual void*onStackOverflow(int nbytes);
virtual void onStackUnderflow(void*p);
public:
enum
{
PAGE_ALIGN=64,
MEMORY_MAX_SMALL_ROW=13,
MEMORY_MAX_ALL_ROW=(MEMORY_MAX_SMALL_ROW+4),
MEMORY_MAX_SIZE_SMALL_BLOCK=512,
MEMORY_MAX_SIZE_LARGE_BLOCK=8192,
MEMORY_LARGE_BLOCK_RSHIFT_BITS=10,
MEMORY_SYSTEM_PAGE_SIZE=8192,
MEMORY_MAGIC_NUMBER=0x3425234
};
struct Stack
{
Stack()
: m_current(0),
m_prev(0),
m_base((char*)-1),
m_end(0)
{
}
__declspec(align(16))char*m_current;
Stack*m_prev;
char*m_base;
char*m_end;
int getFreeBytes(){return int(m_end-m_current)-16;}
};
__forceinline Stack&__cdecl getStack();
__forceinline int getRow(int nbytes)const;
static __forceinline int __cdecl constSizeToRow(int size);
__forceinline int rowToSize(int row)const;
protected:
enum{BATCH_SIZE=4};
void*onRowEmpty(int row);
void onRowFull(int row,void*p);
void clearRow(int rowIndex);
public:
hkMemory*m_memory;
int m_referenceCount;
Stack m_stack;
int m_stackSize;
int m_maxNumElemsOnFreeList;
struct FreeList
{
enum{MAX_FREELIST=0x0fffffff};
FreeList(): m_head(0),m_numElem(0){}
void put(void*p)
{
m_numElem+=1;
FreeElem*fl=static_cast<FreeElem*>(p);
fl->m_next=m_head;
m_head=fl;
}
void*get()
{
if(void*p=m_head)
{
m_numElem-=1;
m_head=m_head->m_next;
return p;
}
return 0;
}
struct FreeElem{FreeElem*m_next;};
FreeElem*m_head;
int m_numElem;
};
FreeList m_free_list[MEMORY_MAX_ALL_ROW];
int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
int m_large_size_to_row_lut[(MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS)];
};
class hkFinishLoadedObjectFlag
{
public:
hkFinishLoadedObjectFlag(): m_finishing(0){}
int m_finishing;
private:
};
class hkBaseObject
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
__forceinline hkBaseObject(class hkFinishLoadedObjectFlag flag){}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
__forceinline hkReferencedObject();
__forceinline hkReferencedObject(const hkReferencedObject&originalObject);
virtual ~hkReferencedObject(){}
__forceinline void addReference()const;
__forceinline void removeReference()const;
__forceinline int getReferenceCount()const;
__forceinline int getAllocatedSize()const;
virtual void calcStatistics(hkStatisticsCollector*collector)const;
virtual void calcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_memSizeAndFlags;
mutable hkInt16 m_referenceCount;
public:
hkReferencedObject(class hkFinishLoadedObjectFlag flag): m_referenceCount(1){}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*,int numElem,int sizeElem);
void __cdecl _reserveMore(void*array,int sizeElem);
void __cdecl _reduce(void*array,int sizeElem,char*inplaceMem,int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
friend void __cdecl hkArrayUtil::_reserve(void*,int numElem,int sizeElem);
friend void __cdecl hkArrayUtil::_reserveMore(void*array,int sizeElem);
friend void __cdecl hkArrayUtil::_reduce(void*array,int sizeElem,char*inplaceMem,int requestedCapacity);
friend class hkObjectArray< hkArray<T> >;
friend class hkArraySpu;
public:
__forceinline hkArray();
explicit __forceinline hkArray(int size);
__forceinline hkArray(int size,const T&fill);
__forceinline hkArray(T*ptr,int size,int capacity);
private:
hkArray(const hkArray&a);
public:
hkArray&operator=(const hkArray&a);
__forceinline ~hkArray();
__forceinline T&operator[](int i);
__forceinline const T&operator[](int i)const;
__forceinline T&back();
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
LOCKED_FLAG=int(0x40000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
void releaseMemory();
T*m_data;
int m_size;
int m_capacityAndFlags;
public:
hkArray(hkFinishLoadedObjectFlag f){}
};
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
public:
__forceinline void operator=(const hkVector4&v);
__forceinline void operator=(const hkQuadReal&v);
__forceinline void set(hkReal x,hkReal y,hkReal z,hkReal w=0);
__forceinline void setAll(hkReal x);
__forceinline void setAll3(hkReal x);
__forceinline void setZero4();
__forceinline void setInt24W(int value);
__forceinline int getInt24W()const;
__forceinline void storeUncached(void*dest)const;
__forceinline void add4(const hkVector4&a);
__forceinline void add3clobberW(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void sub4(const hkVector4&a);
__forceinline void sub3clobberW(const hkVector4&a);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void mul4(const hkVector4&a);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void subMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void subMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&x,const hkVector4&y);
__forceinline void setCross(const hkVector4&a,const hkVector4&b);
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline hkBool32 equals3(const hkVector4&a,hkReal epsilon=1e-3f)const;
__forceinline hkBool32 equals4(const hkVector4&a,hkReal epsilon=1e-3f)const;
void setTransformedPos(const hkTransform&a,const hkVector4&b);
void setTransformedInversePos(const hkTransform&a,const hkVector4&b);
void setTransformedPos(const hkQsTransform&a,const hkVector4&b);
void setTransformedInversePos(const hkQsTransform&a,const hkVector4&b);
__forceinline void _setMul3(const hkMatrix3&a,const hkVector4&b);
void _setMul4(const hkMatrix3&a,const hkVector4&b);
__forceinline void _setMul4xyz1(const hkTransform&a,const hkVector4&b);
__forceinline void _setRotatedDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setRotatedInverseDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline void _setTransformedInversePos(const hkTransform&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkQsTransform&a,const hkVector4&b);
__forceinline void _setTransformedInversePos(const hkQsTransform&a,const hkVector4&b);
__forceinline hkSimdReal dot3(const hkVector4&a)const;
__forceinline hkReal dot3fpu(const hkVector4&a)const;
__forceinline hkSimdReal dot4(const hkVector4&a)const;
__forceinline hkSimdReal dot4xyz1(const hkVector4&a)const;
__forceinline hkSimdReal horizontalAdd3()const;
__forceinline hkSimdReal horizontalAdd4()const;
__forceinline hkSimdReal length3()const;
__forceinline hkSimdReal lengthSquared3()const;
__forceinline hkSimdReal lengthInverse3()const;
__forceinline hkSimdReal distanceTo3(hkVector4Parameter p)const;
__forceinline hkSimdReal length4()const;
__forceinline hkSimdReal lengthSquared4()const;
__forceinline hkSimdReal lengthInverse4()const;
__forceinline void normalize3();
__forceinline hkSimdReal normalizeWithLength3();
__forceinline void normalize4();
__forceinline hkSimdReal normalizeWithLength4();
__forceinline void fastNormalize3();
__forceinline hkSimdReal fastNormalizeWithLength3();
__forceinline void fastNormalize3NonZero();
__forceinline hkResult normalize3IfNotZero();
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
__forceinline void setXYZW(const hkVector4&xyz,const hkVector4&w);
__forceinline void setW(const hkVector4&v);
__forceinline void setXYZ(const hkVector4&v);
__forceinline void setXYZ0(const hkVector4&xyz);
void store4(hkReal*p)const;
void store4a(hkReal*p)const;
private:
__declspec(align(16))hkReal x;
hkReal y;
hkReal z;
hkReal w;
};
class hkQuaternion
{
public:
inline hkQuaternion(){}
inline hkQuaternion(hkReal ix,hkReal iy,hkReal iz,hkReal r);
explicit inline hkQuaternion(const hkRotation&r);
inline hkQuaternion(const hkVector4&axis,hkReal angle);
inline void operator=(const hkQuaternion&q);
inline void set(hkReal ix,hkReal iy,hkReal iz,hkReal r);
static inline const hkQuaternion&__cdecl getIdentity();
inline void setIdentity();
inline void setInverse(const hkQuaternion&q);
inline hkReal getAngle()const;
inline void getAxis(hkVector4&axis)const;
inline hkBool hasValidAxis()const;
inline const hkReal&operator()(int i)const;
hkBool isOk()const;
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);
};
class hkMatrix3
{
public:
__forceinline hkMatrix3(){}
__forceinline hkMatrix3(const hkMatrix3&other);
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
__forceinline void getRow(int row,hkVector4&r)const;
__forceinline hkReal&operator()(int row,int col);
__forceinline const hkReal&operator()(int row,int col)const;
__forceinline void _setMul(hkSimdRealParameter scale,const hkMatrix3&a);
void addMul(hkSimdRealParameter scale,const hkMatrix3&a);
void changeBasis(const hkRotation&t);
void add(const hkMatrix3&a);
__forceinline void _add(const hkMatrix3&a);
void sub(const hkMatrix3&a);
__forceinline void _sub(const hkMatrix3&a);
void mul(const hkMatrix3&a);
void mul(hkSimdRealParameter scale);
inline void operator=(const hkMatrix3&a);
hkBool isOk()const;
protected:
hkVector4 m_col0;
hkVector4 m_col1;
hkVector4 m_col2;
};
class __declspec(align(16))hkRotation : public hkMatrix3
{
public:
void set(const hkQuaternion&q);
void setAxisAngle(const hkVector4&axis,hkReal angle);
hkBool isOrthonormal(hkReal epsilon=1e-3f)const;
void renormalize();
};
class hkTransform
{
public:
__forceinline hkTransform(){}
__forceinline hkTransform(const hkRotation&r,const hkVector4&t);
__forceinline hkTransform(const hkTransform&r);
__forceinline hkTransform(const hkQuaternion&q,const hkVector4&t);
__forceinline hkReal&operator()(int row,int column);
__forceinline const hkReal&operator()(int row,int column)const;
__forceinline void set(const hkQuaternion&q,const hkVector4&t);
__forceinline void setIdentity();
__forceinline static const hkTransform&__cdecl getIdentity();
hkBool isApproximatelyEqual(const hkTransform&t,hkReal epsilon=1e-3f)const;
__forceinline hkVector4&getTranslation();
__forceinline const hkVector4&getTranslation()const;
__forceinline void setTranslation(const hkVector4&t);
__forceinline hkRotation&getRotation();
__forceinline const hkRotation&getRotation()const;
__forceinline void setRotation(const hkRotation&rotation);
__forceinline void setRotation(const hkQuaternion&quatRotation);
void setInverse(const hkTransform&t);
void setMul(const hkTransform&t1,const hkTransform&t2);
void setMul(const hkQsTransform&t1,const hkTransform&t2);
void setMulInverseMul(const hkTransform&bTa,const hkTransform&bTc);
void setMulEq(const hkTransform&b);
void get4x4ColumnMajor(hkReal*p)const;
void set4x4ColumnMajor(const hkReal*p);
__forceinline void setRows4(const hkVector4&r0,const hkVector4&r1,const hkVector4&r2,const hkVector4&r3);
void setMulMulInverse(const hkTransform&a,const hkTransform&b);
hkBool isOk()const;
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
private:
hkRotation m_rotation;
hkVector4 m_translation;
};
class hkSweptTransform
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
__forceinline hkSweptTransform(){}
public:
__forceinline void _approxTransformAt(hkTime time,hkTransform&transformOut)const;
void approxTransformAt(hkTime time,hkTransform&transformOut)const;
__forceinline hkReal getInterpolationValue(hkTime t)const;
__forceinline hkReal getInterpolationValueHiAccuracy(hkTime t,hkReal deltaTimeAddon)const;
__forceinline hkTime getBaseTime()const;
__forceinline hkReal getInvDeltaTime()const;
void initSweptTransform(const hkVector4&position,const hkQuaternion&rotation);
public:
hkVector4 m_centerOfMass0;
hkVector4 m_centerOfMass1;
hkQuaternion m_rotation0;
hkQuaternion m_rotation1;
hkVector4 m_centerOfMassLocal;
};
inline hkReal&hkVector4::operator()(int i)
{
;;
return(&x)[i];
}
inline const hkReal&hkVector4::operator()(int i)const
{
;;
return(&x)[i];
}
inline void hkVector4::setZero4()
{
x=y=z=w=0;
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
x=v0.x-v1.x;
y=v0.y-v1.y;
z=v0.z-v1.z;
w=v0.w-v1.w;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs,const hkVector4&a)
{
hkReal r=hkReal(rs);
x=r*a.x;
y=r*a.y;
z=r*a.z;
w=r*a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs,const hkVector4&a)
{
hkReal r=hkReal(rs);
x+=r*a.x;
y+=r*a.y;
z+=r*a.z;
w+=r*a.w;
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4&a)const
{
return(x*a.x)+(y*a.y)+(z*a.z)+(w);
}
hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_centerOfMass1(3);
}
struct hkAabbUint32;
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
inline const hkVector4&getPosition()const;
inline hkVector4&getPosition();
inline void setPosition(const hkVector4&position);
inline const hkVector4&getNormal()const;
inline const hkVector4&getSeparatingNormal()const;
inline hkVector4&getSeparatingNormal();
inline void setSeparatingNormal(const hkVector4&normal,hkReal dist);
inline void setSeparatingNormal(const hkVector4&separatingNormal);
inline void setNormal(const hkVector4&normal);
inline hkReal getDistance()const;
inline hkSimdReal getDistanceSimdReal()const;
inline void setDistance(hkReal d);
inline void set(const hkVector4&position,const hkVector4&normal,float dist);
inline void setFlipped(const hkContactPoint&point);
inline void flip();
protected:
hkVector4 m_position;
hkVector4 m_separatingNormal;
};
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkMotionState;
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT);}__forceinline void __cdecl operator delete(void*p){if(p)hkThreadMemory::getInstance().deallocateChunkConstSize(p,sizeof(hkpCdBody),HK_MEMORY_CLASS_AGENT);}__forceinline void*__cdecl operator new[](hk_size_t nbytes){return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT);}__forceinline void __cdecl operator delete[](void*p){hkThreadMemory::getInstance().deallocate(p);}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class MustEndWithSemiColon;
static const struct hkInternalClassMember Members[];struct DefaultStruct;
__forceinline hkpCdBody(){}
friend class hkpCollidable;
__forceinline hkpCdBody(const hkpShape*shape,const hkMotionState*motionState);
__forceinline hkpCdBody(const hkpShape*shape,const hkTransform*t);
__forceinline hkpCdBody(const hkpCdBody&body){}
__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
__forceinline const hkpCollidable*getRootCollidable()const;
__forceinline hkpShapeKey getShapeKey()const;
__forceinline const hkpCdBody*getParent()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline hkpCdBody(const hkpCdBody*parent,const hkMotionState*ms);
__forceinline hkpCdBody(const hkpCdBody*parent,const hkTransform*t);
__forceinline void setShape(const hkpShape*shape,hkpShapeKey key);
__forceinline const hkMotionState*getMotionState()const;
__forceinline void setMotionState(const hkMotionState*state);
__forceinline void setTransform(const hkTransform*t);
public:
const hkpShape*m_shape;
hkpShapeKey m_shapeKey;
const void*m_motion;
const hkpCdBody*m_parent;
};
const hkMotionState*hkpCdBody::getMotionState()const
{
return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_shape;
}
hkpCdBody::hkpCdBody(const hkpCdBody*parent,const hkTransform*t)
{
m_parent=parent;
m_motion=t;
}
hkpShapeKey hkpCdBody::getShapeKey()const
{
return m_shapeKey;
}
void hkpCdBody::setShape(const hkpShape*shape,hkpShapeKey key)
{
m_shape=shape;
m_shapeKey=key;
}
struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
class hkpLinkedCollidable;
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct hkpCollisionInput;
struct hkpAgentEntry
{
hkUchar m_streamCommand;
hkUchar m_agentType;
hkUchar m_numContactPoints;
hkUchar m_size;
};
typedef void hkpAgentData;
struct hkpAgent3Input
{
hkPadSpu<const hkpCdBody*> m_bodyA;
hkPadSpu<const hkpCdBody*> m_bodyB;
hkPadSpu<const hkpProcessCollisionInput*> m_input;
hkPadSpu<hkpContactMgr*> m_contactMgr;
hkTransform m_aTb;
};
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
hkPadSpu<hkReal> m_distAtT1;
hkPadSpu<int> m_offsetPpuSectorMinusSpuSector;
hkVector4 m_linearTimInfo;
};
namespace hkAgent3
{
typedef int AgentType;
enum StreamCommand
{
STREAM_NULL=0,
STREAM_END=1,
STREAM_CALL=2,
STREAM_CALL_FLIPPED=3,
STREAM_CALL_WITH_TIM=4,
STREAM_CALL_WITH_TIM_FLIPPED=5,
STREAM_CALL_AGENT=6,
};
typedef hkpAgentData*(__cdecl*CreateFunc)(const hkpAgent3Input&input,hkpAgentEntry*entry,hkpAgentData*agentData);
typedef void(__cdecl*DestroyFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner,hkpCollisionDispatcher*dispatcher);
typedef hkpAgentData*(__cdecl*ProcessFunc)(const hkpAgent3ProcessInput&input,hkpAgentEntry*entry,hkpAgentData*agentData,hkVector4*separatingNormalOut,hkpProcessCollisionOutput&result);
enum Symmetric
{
IS_SYMMETRIC,
IS_NOT_SYMMETRIC,
IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl*SepNormalFunc)(const hkpAgent3Input&input,hkpAgentEntry*entry,hkpAgentData*agentData,hkVector4&separatingNormalOut);
typedef hkpAgentData*(__cdecl*CleanupFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkContactPointId idToRemove);
typedef void(__cdecl*CommitPotentialFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkContactPointId newId);
typedef void(__cdecl*CreateZombieFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkContactPointId idTobecomeZombie);
typedef void(__cdecl*UpdateFilterFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,const hkpCollisionInput&input,hkStatisticsCollector*collector);
typedef void(__cdecl*InvalidateTimFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkpCollisionInput&input);
typedef void(__cdecl*WarpTimeFunc)(hkpAgentEntry*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,hkpCollisionInput&input);
}
enum hkpCollidableQualityType
{
HK_COLLIDABLE_QUALITY_INVALID,
HK_COLLIDABLE_QUALITY_FIXED,
HK_COLLIDABLE_QUALITY_KEYFRAMED,
HK_COLLIDABLE_QUALITY_DEBRIS,
HK_COLLIDABLE_QUALITY_MOVING,
HK_COLLIDABLE_QUALITY_CRITICAL,
HK_COLLIDABLE_QUALITY_BULLET,
HK_COLLIDABLE_QUALITY_USER,
HK_COLLIDABLE_QUALITY_CHARACTER,
HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,
HK_COLLIDABLE_QUALITY_MAX
};
struct hkpCollisionQualityInfo
{
__declspec(align(16))hkReal m_keepContact;
hkReal m_create4dContact;
hkReal m_createContact;
hkReal m_manifoldTimDistance;
hkPadSpu<hkBool32> m_useContinuousPhysics;
hkReal m_minSeparation;
hkReal m_minExtraSeparation;
hkReal m_minSafeDeltaTime;
hkReal m_minAbsoluteSafeDeltaTime;
hkReal m_toiSeparation;
hkReal m_toiExtraSeparation;
hkReal m_toiAccuracy;
hkReal m_maxContraintViolation;
hkReal m_minToiDeltaTime;
hkUint16 m_constraintPriority;
hkBool m_enableToiWeldRejection;
hkReal calcMinSeparation(hkReal currentDistance)const
{
return m_minSeparation;
}
};
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
public:
hkReal getTolerance()const{return m_tolerance;}
void setTolerance(hkReal t){m_tolerance=t;}
public:
hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
hkPadSpu<hkReal> m_tolerance;
hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
struct Aabb32Info
{
hkVector4 m_bitOffsetLow;
hkVector4 m_bitOffsetHigh;
hkVector4 m_bitScale;
};
Aabb32Info m_aabb32Info;
};
class hkpCollisionAgent;
class hkpContactMgrFactory;
enum hkpShapeType;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct hkpLinearCastCollisionInput;
class hkpCollisionDispatcher : public hkReferencedObject
{
public:
enum{
HK_MAX_RESPONSE_TYPE=8,
HK_MAX_SHAPE_TYPE=32,
HK_MAX_AGENT2_TYPES=64,
HK_MAX_AGENT3_TYPES=16,
HK_MAX_COLLISION_QUALITIES=8
};
public:
typedef hkpCollisionAgent*(__cdecl*CreateFunc)(const hkpCdBody&collA,const hkpCdBody&collB,const hkpCollisionInput&env,hkpContactMgr*mgr);
typedef void(__cdecl*GetPenetrationsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpCdBodyPairCollector&collector);
typedef void(__cdecl*GetClosestPointsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpCdPointCollector&output);
typedef void(__cdecl*LinearCastFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpLinearCastCollisionInput&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector);
typedef CreateFunc CollisionAgentCreationFunction;
typedef hkChar CollisionQualityIndex;
struct AgentFuncs
{
CreateFunc m_createFunc;
GetPenetrationsFunc m_getPenetrationsFunc;
GetClosestPointsFunc m_getClosestPointFunc;
LinearCastFunc m_linearCastFunc;
hkBool m_isFlipped;
hkBool m_isPredictive;
AgentFuncs(): m_isFlipped(false),m_isPredictive(false){}
};
struct Agent3Funcs
{
Agent3Funcs(): m_isPredictive(false),m_ignoreSymmetricVersion(false),m_reusePreviousEntry(false)
{
m_updateFilterFunc=0;
m_calcStatisticsFunc=0;
m_invalidateTimFunc=0;
m_warpTimeFunc=0;
m_sepNormalFunc=0;
}
__declspec(align(16))hkAgent3::CreateFunc m_createFunc;
hkAgent3::DestroyFunc m_destroyFunc;
hkAgent3::CleanupFunc m_cleanupFunc;
hkAgent3::RemovePointFunc m_removePointFunc;
hkAgent3::CommitPotentialFunc m_commitPotentialFunc;
hkAgent3::CreateZombieFunc m_createZombieFunc;
hkAgent3::UpdateFilterFunc m_updateFilterFunc;
hkAgent3::CalcStatisticsFunc m_calcStatisticsFunc;
hkAgent3::InvalidateTimFunc m_invalidateTimFunc;
hkAgent3::WarpTimeFunc m_warpTimeFunc;
hkAgent3::SepNormalFunc m_sepNormalFunc;
hkAgent3::ProcessFunc m_processFunc;
hkBool m_isPredictive;
hkBool m_ignoreSymmetricVersion;
hkBool m_reusePreviousEntry;
};
struct InitCollisionQualityInfo
{
hkReal m_gravityLength;
hkReal m_collisionTolerance;
hkReal m_minDeltaTime;
hkReal m_maxLinearVelocity;
hkUint16 m_defaultConstraintPriority;
hkUint16 m_toiConstraintPriority;
hkUint16 m_toiHigherConstraintPriority;
hkUint16 m_toiForcedConstraintPriority;
hkBool m_wantContinuousCollisionDetection;
hkBool m_enableNegativeManifoldTims;
hkBool m_enableNegativeToleranceToCreateNon4dContacts;
hkBool m_enableToiWeldRejection;
};
enum TableType
{
TABLE_TYPE_AGENT2,
TABLE_TYPE_AGENT2_PRED,
TABLE_TYPE_AGENT3,
TABLE_TYPE_AGENT3_PRED
};
enum IsAgentPredictive
{
IS_NOT_PREDICTIVE,
IS_PREDICTIVE
};
public:
hkpCollisionDispatcher(CreateFunc defaultCreationFunction,hkpContactMgrFactory*defaultContactMgrFactory);
~hkpCollisionDispatcher();
void registerAlternateShapeType(hkpShapeType primaryType,hkpShapeType alternateType);
inline hkBool32 hasAlternateType(hkpShapeType type,hkpShapeType alternateType);
void registerCollisionAgent(AgentFuncs&f,hkpShapeType typeA,hkpShapeType typeB);
void registerCollisionAgent2(AgentFuncs&f,hkpShapeType typeA,hkpShapeType typeB);
void setEnableChecks(hkBool checkEnabled);
void debugPrintTable();
void disableDebugging();
__forceinline hkpCollisionAgent*getNewCollisionAgent(const hkpCdBody&a,const hkpCdBody&b,const hkpCollisionInput&env,hkpContactMgr*mgr)const;
__forceinline CreateFunc getCollisionAgentCreationFunction(hkpShapeType typeA,hkpShapeType typeB,IsAgentPredictive predictive)const;
__forceinline GetPenetrationsFunc getGetPenetrationsFunc(hkpShapeType typeA,hkpShapeType typeB)const;
__forceinline GetClosestPointsFunc getGetClosestPointsFunc(hkpShapeType typeA,hkpShapeType typeB)const;
__forceinline LinearCastFunc getLinearCastFunc(hkpShapeType typeA,hkpShapeType typeB)const;
__forceinline hkBool getIsFlipped(hkpShapeType typeA,hkpShapeType typeB)const;
int registerAgent3(Agent3Funcs&f,hkpShapeType typeA,hkpShapeType typeB);
__forceinline hkAgent3::AgentType getAgent3Type(hkpShapeType typeA,hkpShapeType typeB,hkBool32 predicitve)const;
__forceinline hkAgent3::CreateFunc getAgent3CreateFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::DestroyFunc getAgent3DestroyFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::CleanupFunc getAgent3CleanupFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::RemovePointFunc getAgent3RemovePointFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::CommitPotentialFunc getAgent3CommitPotentialFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::CreateZombieFunc getAgent3CreateZombieFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::UpdateFilterFunc getAgent3UpdateFilterFunc(hkAgent3::AgentType type)const;
__forceinline hkAgent3::CalcStatisticsFunc getAgent3CalcStatisticsFunc(hkAgent3::AgentType type)const;
__forceinline hkAgent3::InvalidateTimFunc getAgent3InvalidateTimFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::WarpTimeFunc getAgent3WarpTimeFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::ProcessFunc getAgent3ProcessFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::SepNormalFunc getAgent3SepNormalFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::Symmetric getAgent3Symmetric(hkAgent3::AgentType type);
void registerContactMgrFactory(hkpContactMgrFactory*,int responseA,int responseB);
__forceinline hkpContactMgrFactory*getContactMgrFactory(int responseA,int responseB)const;
void registerContactMgrFactoryWithAll(hkpContactMgrFactory*,int responseA);
__forceinline CollisionQualityIndex getCollisionQualityIndex(hkpCollidableQualityType a,hkpCollidableQualityType b);
__forceinline hkpCollisionQualityInfo*getCollisionQualityInfo(CollisionQualityIndex index);
void initCollisionQualityInfo(InitCollisionQualityInfo&input);
void calcStatistics(hkStatisticsCollector*collector)const;
public:
struct ShapeInheritance
{
hkpShapeType m_primaryType;
hkpShapeType m_alternateType;
};
struct AgentEntry
{
hkpShapeType m_typeA;
hkpShapeType m_typeB;
hkBool m_checkEnabled;
AgentFuncs m_createFunc;
};
struct Agent3Entry
{
hkpShapeType m_typeA;
hkpShapeType m_typeB;
hkBool m_checkEnabled;
Agent3Funcs m_funcs;
};
struct Agent3FuncsIntern: public Agent3Funcs
{
hkAgent3::Symmetric m_symmetric;
};
struct DebugEntry
{
char m_typeA;
char m_typeB;
char m_priority;
};
typedef DebugEntry DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
protected:
void updateHasAlternateType(hkpShapeType primaryType,hkpShapeType alternateType,int depth);
void resetCreationFunctions();
public:
enum CollisionQualityLevel
{
COLLISION_QUALITY_INVALID,
COLLISION_QUALITY_PSI,
COLLISION_QUALITY_TOI,
COLLISION_QUALITY_TOI_HIGHER,
COLLISION_QUALITY_TOI_FORCED,
COLLISION_QUALITY_CHARACTER,
COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
};
CreateFunc m_defaultCollisionAgent;
hkpContactMgrFactory*m_contactMgrFactory[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
__declspec(align(16))hkUint32 m_hasAlternateType[HK_MAX_SHAPE_TYPE];
int m_numAgent2Types;
__declspec(align(16))hkUchar m_agent2Types[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
hkUchar m_agent2TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
AgentFuncs m_agent2Func[HK_MAX_AGENT2_TYPES];
int m_numAgent3Types;
__declspec(align(16))hkUchar m_agent3Types[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
__declspec(align(16))hkUchar m_agent3TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
Agent3FuncsIntern m_agent3Func[HK_MAX_AGENT3_TYPES];
__declspec(align(16))hkChar m_collisionQualityTable[HK_COLLIDABLE_QUALITY_MAX][HK_COLLIDABLE_QUALITY_MAX];
__declspec(align(16))hkpCollisionQualityInfo m_collisionQualityInfo[HK_MAX_COLLISION_QUALITIES];
hkBool m_collisionAgentRegistered;
hkBool m_agent3Registered;
hkBool m_midphaseAgent3Registered;
hkBool m_checkEnabled;
hkArray<ShapeInheritance> m_shapeInheritance;
DebugTable*m_debugAgent2Table;
DebugTable*m_debugAgent2TablePred;
DebugTable*m_debugAgent3Table;
DebugTable*m_debugAgent3TablePred;
public:
hkReal m_expectedMaxLinearVelocity;
hkReal m_expectedMinPsiDeltaTime;
};
hkAgent3::CleanupFunc hkpCollisionDispatcher::getAgent3CleanupFunc(hkAgent3::AgentType type)
{
return m_agent3Func[type].m_cleanupFunc;
}
hkAgent3::ProcessFunc hkpCollisionDispatcher::getAgent3ProcessFunc(hkAgent3::AgentType type)
{
return m_agent3Func[type].m_processFunc;
}
hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc(hkAgent3::AgentType type)
{
return m_agent3Func[type].m_sepNormalFunc;
}
class hkpBroadPhaseHandle
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
hkUint32 m_id;
hkpBroadPhaseHandle(): m_id(0){}
public:
hkpBroadPhaseHandle(class hkFinishLoadedObjectFlag flag){}
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
__forceinline hkpTypedBroadPhaseHandle(int type);
__forceinline hkpTypedBroadPhaseHandle(void*owner,int type);
__forceinline int getType()const;
__forceinline void setOwner(void*o);
__forceinline void*getOwner()const;
__forceinline hkUint32 getCollisionFilterInfo()const;
__forceinline void setCollisionFilterInfo(hkUint32 info);
hkpTypedBroadPhaseHandle(class hkFinishLoadedObjectFlag flag): hkpBroadPhaseHandle(flag){}
protected:
enum{OFFSET_INVALID=127};
inline void setType(int type);
friend class hkpBroadPhaseBorder;
hkInt8 m_type;
hkInt8 m_ownerOffset;
public:
hkUint16 m_objectQualityType;
hkUint32 m_collisionFilterInfo;
};
class hkpCollidable : public hkpCdBody
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
inline hkpCollidable(const hkpShape*shape,const hkTransform*ms,int type=0);
inline hkpCollidable(const hkpShape*shape,const hkMotionState*ms,int type=0);
inline ~hkpCollidable();
inline const hkpShape*getShape()const;
inline void setShape(const hkpShape*shape);
inline void setOwner(void*owner);
inline void*getOwner()const
{
return const_cast<char*>(reinterpret_cast<const char*>(this)+m_ownerOffset);
}
void checkPerformance();
inline const hkpTypedBroadPhaseHandle*getBroadPhaseHandle()const;
inline hkpTypedBroadPhaseHandle*getBroadPhaseHandle();
__forceinline hkpCollidableQualityType getQualityType()const;
__forceinline void setQualityType(hkpCollidableQualityType type);
__forceinline hkReal getAllowedPenetrationDepth()const;
__forceinline void setAllowedPenetrationDepth(hkReal val);
public:
__forceinline hkUint32 getCollisionFilterInfo()const;
__forceinline void setCollisionFilterInfo(hkUint32 info);
__forceinline int getType()const;
hkpCollidable(class hkFinishLoadedObjectFlag flag);
public:
struct BoundingVolumeData
{
static const struct hkInternalClassMember Members[];struct DefaultStruct;
BoundingVolumeData();
__forceinline const hkAabbUint32&getAabbUint32()const{return reinterpret_cast<const hkAabbUint32&>(m_min);}
__forceinline hkAabbUint32&getAabbUint32(){return reinterpret_cast< hkAabbUint32&>(m_min);}
__forceinline void invalidate(){m_min[0]=1;m_max[0]=0;}
__forceinline bool isValid()const{return m_min[0]<=m_max[0];}
public:
hkUint32 m_min[3];
hkUint8 m_expansionMin[3];
hkUint8 m_expansionShift;
hkUint32 m_max[3];
hkUint8 m_expansionMax[3];
hkUint8 m_padding;
hkUint16 m_numChildShapeAabbs;
hkAabbUint32*m_childShapeAabbs;
};
enum ForceCollideOntoPpuReasons
{
FORCE_PPU_USER_REQUEST=1,
FORCE_PPU_SHAPE_REQUEST=2,
FORCE_PPU_MODIFIER_REQUEST=4,
};
protected:
hkInt8 m_ownerOffset;
public:
hkUint8 m_forceCollideOntoPpu;
hkUint16 m_shapeSizeOnSpu;
class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
public:
struct BoundingVolumeData m_boundingVolumeData;
hkReal m_allowedPenetrationDepth;
};
class hkpSolverResults
{
public:
inline hkReal getImpulseApplied()const;
inline hkpSolverResults();
inline void init();
public:
hkReal m_impulseApplied;
hkReal m_internalSolverData;
};
class hkContactPointMaterial
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
inline hkReal getFriction()const;
inline void setFriction(hkReal r);
inline hkReal getRestitution()const;
inline void setRestitution(hkReal r);
inline hkUlong getUserData()const;
inline void setUserData(hkUlong data);
inline hkBool32 isPotential();
inline void setMaxImpulsePerStep(hkUFloat8 impulse);
inline hkReal getMaxImpulsePerStep();
protected:
hkUlong m_userData;
hkUFloat8 m_friction;
hkUint8 m_restitution;
public:
hkUFloat8 m_maxImpulse;
public:
void reset()
{
m_friction.m_value=0;
m_maxImpulse.m_value=0;
m_restitution=0;
m_flags=CONTACT_IS_NEW_AND_POTENTIAL;
}
enum FlagEnum
{
CONTACT_IS_NEW_AND_POTENTIAL=1,
CONTACT_USES_SOLVER_PATH2=2,
CONTACT_BREAKOFF_OBJECT_ID=4,
};
hkUint8 m_flags;
friend class hkpSaveContactPointsEndianUtil;
};
struct hkpSimpleContactConstraintAtom;
class hkpContactPointProperties : public hkpSolverResults,public hkContactPointMaterial
{
public:
inline hkBool wasUsed()
{
return !isPotential()&&(m_impulseApplied > 0.f);
}
public:
hkReal m_internalDataA;
typedef hkUint32 UserData;
static inline int getNumExtendedUserDatas(const hkpSimpleContactConstraintAtom*atom,int bodyIdx);
inline hkpContactPointProperties::UserData&getExtendedUserData(const hkpSimpleContactConstraintAtom*atom,int bodyIdx,int i);
};
__declspec(align(16))class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
public:
void set(const hkContactPointPropertiesWithExtendedUserData16&other)
{
*this=other;
}
hkpContactPointProperties::UserData m_extendedUserDatas[7];
};
struct hkpProcessCdPoint
{
hkContactPoint m_contact;
hkPadSpu<hkUint32> m_contactPointId;
};
class hkpCollisionAgent : public hkReferencedObject
{
public:
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpCdBodyPairCollector&collector)=0;
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpCdPointCollector&collector)=0;
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpLinearCastCollisionInput&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector)=0;
public:
virtual void processCollision(const hkpCdBody&a,const hkpCdBody&b,const hkpProcessCollisionInput&input,hkpProcessCollisionOutput&result)=0;
virtual void cleanup(hkpConstraintOwner&info)=0;
virtual void updateShapeCollectionFilter(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput&input,hkpConstraintOwner&constraintOwner){}
virtual void invalidateTim(hkpCollisionInput&input);
virtual void warpTime(hkTime oldTime,hkTime newTime,hkpCollisionInput&input);
virtual void removePoint(hkContactPointId idToRemove);
virtual void commitPotential(hkContactPointId newId);
virtual void createZombie(hkContactPointId idTobecomeZombie);
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_contactMgr;
public:
inline hkpContactMgr*getContactMgr();
};
class hkMotionState
{
public:
static const struct hkInternalClassMember Members[];struct DefaultStruct;
inline hkMotionState();
void initMotionState(const hkVector4&position,const hkQuaternion&rotation);
inline hkTransform&getTransform();
inline const hkTransform&getTransform()const;
inline const hkSweptTransform&getSweptTransform()const;
inline hkSweptTransform&getSweptTransform();
protected:
hkTransform m_transform;
class hkSweptTransform m_sweptTransform;
public:
hkVector4 m_deltaAngle;
hkReal m_objectRadius;
hkReal m_linearDamping;
hkReal m_angularDamping;
hkUFloat8 m_maxLinearVelocity;
hkUFloat8 m_maxAngularVelocity;
hkUint8 m_deactivationClass;
};
const hkTransform&hkMotionState::getTransform()const
{
return m_transform;
}
const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_sweptTransform;
}
namespace hkAgent3Bridge
{
__forceinline hkpCollisionAgent*&__cdecl getChildAgent(hkpAgentData*agentData)
{
return*reinterpret_cast<hkpCollisionAgent**>(agentData);
}
}
struct hkpAgentNnEntry: hkpAgentEntry
{
hkObjectIndex m_agentIndexOnCollidable[2];
hkpContactMgr*m_contactMgr;
hkUchar m_collisionQualityIndex;
hkUchar m_forceCollideOntoPpu;
hkUchar m_padding[2];
hkpLinkedCollidable*m_collidable[2];
inline hkpCollidable*getCollidableA(){return reinterpret_cast<hkpCollidable*>(m_collidable[0]);}
inline hkpCollidable*getCollidableB(){return reinterpret_cast<hkpCollidable*>(m_collidable[1]);}
};
struct hkpAgentNnMachinePaddedEntry: hkpAgentNnEntry
{
hkUint32 m_padOutTo16BytesAlignment[2];
};
struct hkpAgentNnMachineTimEntry: hkpAgentNnEntry
{
hkTime m_timeOfSeparatingNormal;
hkVector4 m_separatingNormal;
};
void __cdecl FUN_00999610(hkpAgentNnEntry*entry,const hkpProcessCollisionInput&input,hkpProcessCollisionOutput&output,hkpContactMgr*mgr);
class hkStepInfo
{
public:
hkStepInfo(){}
void set(hkTime startTime,hkTime endTime)
{
m_startTime=startTime;
m_endTime=endTime;
m_deltaTime=endTime-startTime;
m_invDeltaTime=m_deltaTime==0.0f ? 0.0f : 1.0f / m_deltaTime;
}
hkStepInfo(hkTime startTime,hkTime endTime)
{
set(startTime,endTime);
}
public:
__declspec(align(16))hkPadSpu<hkTime> m_startTime;
hkPadSpu<hkTime> m_endTime;
hkPadSpu<hkReal> m_deltaTime;
hkPadSpu<hkReal> m_invDeltaTime;
};
struct hkpProcessCollisionInput : public hkpCollisionInput
{
public:
hkStepInfo m_stepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
void*m_dynamicsInfo;
bool m_enableDeprecatedWelding;
hkpCollisionAgentConfig*m_config;
};
class hkpConvexShape;
class hkpTriangleShape;
class hkpGskCache
{
public:
hkUint16 m_vertices[4];
hkUint8 m_dimA;
hkUint8 m_dimB;
enum MaxDim
{
MAX_DIM_MAX=15
};
hkUint8 m_maxDimA : 4;
hkUint8 m_maxDimB : 4;
typedef hkUint8 GskFlags;
enum GskFlagValues
{
GSK_FLAGS_SHAPE_A_IS_CYLINDER=0x01,
GSK_FLAGS_SHAPE_B_IS_CYLINDER=0x02,
GSK_FLAGS_REPLACE_SHAPE_A_WITH_CAPSULE=0x04,
GSK_FLAGS_REPLACE_SHAPE_B_WITH_CAPSULE=0x08,
GSK_FLAGS_CYLINDER_AGENT_FLAGS=0x0f,
GSK_FLAGS_DISABLE_CONTACT_TIMS=0x10,
GSK_FLAGS_CONVEX_LIST_IN_GSK_MODE=0x20,
GSK_FLAGS_PROCESS_FUNCTION_CALLED=0x40,
ONE_BIT_STILL_UNUSED=0x80
};
hkUint8 m_gskFlags;
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);
void initTriangle(const hkpConvexShape*shapeA,const hkpTriangleShape*shapeB,const hkTransform&btoa);
inline void flip();
};
__declspec(align(16))class hkGskCache16 : public hkpGskCache
{
public:
void set(const hkGskCache16&other)
{
*this=other;
}
};
enum{HK_MAX_CONTACT_POINT=256};
struct hkpProcessCollisionData
{
public:
inline int getNumContactPoints()const;
inline hkpProcessCdPoint&getContactPoint(int i);
inline hkpProcessCdPoint*getFirstContactPoint();
inline hkpProcessCdPoint*getEnd();
inline hkBool isEmpty()const;
inline hkBool hasToi()const;
inline hkContactPoint&getToiContactPoint();
inline hkTime getToi()const;
inline hkpContactPointProperties&getToiProperties();
public:
hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
hkpProcessCdPoint m_contactPoints[HK_MAX_CONTACT_POINT];
struct ToiInfo
{
public:
inline ToiInfo();
inline void flip();
public:
hkContactPoint m_contactPoint;
hkPadSpu<hkReal> m_time;
hkPadSpu<hkReal> m_seperatingVelocity;
hkGskCache16 m_gskCache;
hkContactPointPropertiesWithExtendedUserData16 m_properties;
};
struct ToiInfo m_toi;
inline hkpProcessCollisionData(hkpConstraintOwner*owner);
};
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
public:
inline hkpProcessCollisionOutput(hkpConstraintOwner*owner): hkpProcessCollisionData(owner){}
inline void reset()
{
m_firstFreeContactPoint=&m_contactPoints[0];
m_toi.m_time=3.40282e+38f;
m_potentialContacts=0;
}
inline hkpProcessCdPoint*reserveContactPoints(int numberOfPoints=1)
{
return m_firstFreeContactPoint;
}
inline void commitContactPoints(int numberOfPoints=1)
{
m_firstFreeContactPoint=m_firstFreeContactPoint+numberOfPoints;
;
}
inline void abortContactPoints(int numberOfPoints=1)
{
}
public:
struct ContactRef
{
hkpProcessCdPoint*m_contactPoint;
hkpAgentEntry*m_agentEntry;
void*m_agentData;
};
struct PotentialInfo
{
void reset()
{
m_firstFreePotentialContact=&m_potentialContacts[0];
m_firstFreeRepresentativeContact=&m_representativeContacts[0];
}
ContactRef*m_firstFreePotentialContact;
hkpProcessCdPoint**m_firstFreeRepresentativeContact;
hkpProcessCdPoint*m_representativeContacts[HK_MAX_CONTACT_POINT];
ContactRef m_potentialContacts[HK_MAX_CONTACT_POINT];
};
public:
hkPadSpu<PotentialInfo*> m_potentialContacts;
};
namespace hkSweptTransformUtil
{
void __cdecl lerp2(const hkSweptTransform&sweptTrans,hkTime time,hkTransform&transformOut);
}
static __forceinline void hkAgentNnMachine_calcLinearTimInfo(hkpAgent3ProcessInput&in)
{
const hkMotionState*msA=in.m_bodyA->getMotionState();
const hkMotionState*msB=in.m_bodyB->getMotionState();
hkReal deltaTime=in.m_input->m_stepInfo.m_deltaTime;
hkVector4 diffA;diffA.setSub4(msA->getSweptTransform().m_centerOfMass0,msA->getSweptTransform().m_centerOfMass1);
hkVector4 diffB;diffB.setSub4(msB->getSweptTransform().m_centerOfMass1,msB->getSweptTransform().m_centerOfMass0);
hkReal fA=deltaTime*msA->getSweptTransform().getInvDeltaTime();
hkReal fB=deltaTime*msB->getSweptTransform().getInvDeltaTime();
in.m_linearTimInfo.setMul4(fA,diffA);
in.m_linearTimInfo.addMul4(fB,diffB);
in.m_linearTimInfo(3)=fA*msA->m_deltaAngle(3)*msA->m_objectRadius+fB*msB->m_deltaAngle(3)*msB->m_objectRadius;
}
static __forceinline void hkAgentNnMachine_processAgentByCommand(hkpAgentNnEntry*entry,int offsetPpuSectorMinusSpuSector,const hkpProcessCollisionInput&input,int&numTim,hkpProcessCollisionOutput&output,hkpContactMgr*mgr)
{
switch(entry->m_streamCommand)
{
case hkAgent3::STREAM_CALL_AGENT:
{
hkpAgentData*agentData=reinterpret_cast<hkpAgentNnMachinePaddedEntry*>(entry)+1;
hkpCollisionAgent*agent=hkAgent3Bridge::getChildAgent(agentData);
agent->processCollision(*entry->getCollidableA(),*entry->getCollidableB(),input,output);
break;
}
case hkAgent3::STREAM_CALL:
{
hkpAgentData*agentData=reinterpret_cast<hkpAgentNnMachinePaddedEntry*>(entry)+1;
hkpAgent3ProcessInput in3;
in3.m_bodyA=entry->getCollidableA();
in3.m_bodyB=entry->getCollidableB();
in3.m_contactMgr=entry->m_contactMgr;
in3.m_input=&input;
const hkMotionState*msA=in3.m_bodyA->getMotionState();
const hkMotionState*msB=in3.m_bodyB->getMotionState();
hkAgentNnMachine_calcLinearTimInfo(in3);
in3.m_aTb.setMulInverseMul(msA->getTransform(),msB->getTransform());
in3.m_offsetPpuSectorMinusSpuSector=offsetPpuSectorMinusSpuSector;
input.m_dispatcher->getAgent3ProcessFunc(entry->m_agentType)(in3,entry,agentData,0,output);
break;
}
case hkAgent3::STREAM_CALL_WITH_TIM:
{
hkpAgentNnMachineTimEntry*timEntry=static_cast<hkpAgentNnMachineTimEntry*>(entry);
hkpAgentData*agentData=timEntry+1;
hkpAgent3ProcessInput in3;
in3.m_contactMgr=entry->m_contactMgr;
in3.m_bodyA=entry->getCollidableA();
in3.m_bodyB=entry->getCollidableB();
in3.m_input=&input;
in3.m_offsetPpuSectorMinusSpuSector=offsetPpuSectorMinusSpuSector;
const hkMotionState*msA=in3.m_bodyA->getMotionState();
const hkMotionState*msB=in3.m_bodyB->getMotionState();
hkAgentNnMachine_calcLinearTimInfo(in3);
hkReal distAtT1;
if(timEntry->m_timeOfSeparatingNormal !=input.m_stepInfo.m_startTime)
{
if(!input.m_collisionQualityInfo->m_useContinuousPhysics)
{
timEntry->m_timeOfSeparatingNormal=input.m_stepInfo.m_endTime;
distAtT1=-3.40282e+38f;
timEntry->m_separatingNormal.setZero4();
timEntry->m_separatingNormal(3)=distAtT1;
goto processAgent;
}
struct BodiesAtStart{hkpCdBody m_bodyA;hkpCdBody m_bodyB;hkTransform m_transA;hkTransform m_transB;}start;
hkSweptTransformUtil::lerp2(in3.m_bodyA->getMotionState()->getSweptTransform(),in3.m_input->m_stepInfo.m_startTime,start.m_transA);
hkSweptTransformUtil::lerp2(in3.m_bodyB->getMotionState()->getSweptTransform(),in3.m_input->m_stepInfo.m_startTime,start.m_transB);
hkpAgent3Input in0;
in0.m_bodyA=&start.m_bodyA;
in0.m_bodyB=&start.m_bodyB;
in0.m_contactMgr=in3.m_contactMgr;
in0.m_input=in3.m_input;
start.m_bodyA.setShape(in3.m_bodyA->getShape(),in3.m_bodyA->getShapeKey());
start.m_bodyB.setShape(in3.m_bodyB->getShape(),in3.m_bodyB->getShapeKey());
new(&start.m_bodyA)hkpCdBody(in3.m_bodyA,&start.m_transA);
new(&start.m_bodyB)hkpCdBody(in3.m_bodyB,&start.m_transB);
in0.m_aTb.setMulInverseMul(start.m_transA,start.m_transB);
input.m_dispatcher->getAgent3SepNormalFunc(entry->m_agentType)(in0,entry,agentData,timEntry->m_separatingNormal);
numTim++;
}
timEntry->m_timeOfSeparatingNormal=input.m_stepInfo.m_endTime;
distAtT1=timEntry->m_separatingNormal(3)-in3.m_linearTimInfo.dot4xyz1(timEntry->m_separatingNormal);
if(distAtT1 >=input.getTolerance())
{
timEntry->m_separatingNormal(3)=distAtT1;
if(entry->m_numContactPoints)
{
input.m_dispatcher->getAgent3CleanupFunc(entry->m_agentType)(entry,agentData,in3.m_contactMgr,*output.m_constraintOwner);
}
break;
}
processAgent:
in3.m_distAtT1=distAtT1;
in3.m_aTb.setMulInverseMul(msA->getTransform(),msB->getTransform());
input.m_dispatcher->getAgent3ProcessFunc(entry->m_agentType)(in3,entry,agentData,&timEntry->m_separatingNormal,output);
break;
}
default:
break;
}
}
// pdb: hkAgentNnMachine_ProcessAgent | hkpAgentNnMachine.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: entry, input, output, mgr
void __cdecl FUN_00999610(hkpAgentNnEntry*entry,const hkpProcessCollisionInput&input,hkpProcessCollisionOutput&output,hkpContactMgr*mgr)
{
int numTim=0;
hkAgentNnMachine_processAgentByCommand(entry,0,input,numTim,output,mgr);
}
}  // namespace f3m_00999610

// @f3 0x00981af0 (community match, verified in this file)
#include <new>
namespace f3m_00981af0 {
// A live byte workspace backs the actual agent, post-collide and thread objects, in their natural aligned order.
// Enqueue copies128bytes synchronously; its byte read stays inside this workspace before later slots are constructed.
// Caller-side reconstruction uses opaque job/element-array addresses for the existing byte-oriented APIs.
// Job layouts, initialized fields and helper ABI are retained; no unrelated JobQueueEntry lvalue is formed.
// 0x00981af0: hkpMultiThreadedSimulation::processAgentNnEntries(const hkArray<hkpAgentNnEntry*>& entries,
// const hkpProcessCollisionInput& collisionInput, hkpSimulationIsland* island, hkBool forceManifoldQualityType) of
// Havok 5.5.0 (hkpDynamics, hkpMultithreadedSimulation.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// With multithreaded TOI processing on: puts the agent entries on the job queue as one agent-entry job split into
// tasks, works the queue on this thread, then runs the post-collide job on a thread structure of its own; otherwise
// hands the entries to the continuous simulation's single-threaded version.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them by work\_havok\linecut.py, every cut
// checked byte for byte against the SDK's release library object); those declarations are the SDK's text with its
// names. The classes of the hkpDynamics library that no SDK header ships (hkpContinuousSimulation,
// hkpMultiThreadedSimulation, hkpDynamicsJob, hkpAgentBaseJob, hkpAgentNnEntryJob, hkpPostCollideJob,
// hkpAgentSectorHeader, hkpMtThreadStructure) are declared from the library's debug records (bases, members, their
// types, offsets and order, enumerators, method signatures); the jobs' inline constructors follow the SDK's
// unoptimized (hybrid) library object, which the function reproduces exactly, as it does the release object. The
// SDK's int 3 traps in the unused placement operators new[] and delete[] were removed by hand. Only the function
// carries the packet's name.
namespace f3m_00981af0 {

typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
			return m_bool != 0;
		}
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
		inline hkBool operator==(bool e) const
		{
			return static_cast<int>(m_bool) == static_cast<int>(e);
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
	public:
		hkEnum()
		{
		}
		hkEnum(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		operator ENUM() const
		{
			return static_cast<ENUM>(m_storage);
		}
		void operator=(ENUM e)
		{
			m_storage = static_cast<STORAGE>(e);
		}
		hkBool operator==(ENUM e) const
		{
			return m_storage == static_cast<STORAGE>(e);
		}
		hkBool operator!=(ENUM e) const
		{
			return m_storage != static_cast<STORAGE>(e);
		}
	private:
		STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}
		__forceinline TYPE val() const
		{
			return m_storage;
		}
		__forceinline TYPE operator->() const
		{
			return m_storage;
		}
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		void* allocate( int nbytes, HK_MEMORY_CLASS cl );
		void deallocate(void*);
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		static __forceinline int __cdecl constSizeToRow( int size );
		__forceinline int rowToSize( int row ) const;
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row);
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
		__forceinline hkArray();
		explicit __forceinline hkArray(int size);
		__forceinline hkArray(int size, const T& fill);
		__forceinline hkArray(T* ptr, int size, int capacity);
	private:
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void clear();
		void clearAndDeallocate();
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		void removeAt(int index);
		void removeAtAndCopy(int index);
		int indexOf(const T& t) const;
		int lastIndexOf(const T& t) const;
		__forceinline void popBack( int numElemsToRemove = 1 );
		hkArray<T> getSubarray(int begin, int end);
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		__forceinline void setSizeUnchecked(int size);
		__forceinline hkBool isLocked();
		__forceinline void setLocked( bool locked );
		__forceinline T& expandOne( );
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		static void __cdecl copy(T* dst, const T* src, int n);
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
		__forceinline void setOwnedData(T* ptr, int size, int capacity);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		hkBool isOk4() const;
		hkBool isNormalized3(hkReal eps = 1e-4f) const;
		hkBool isNormalized4(hkReal eps = 1e-4f) const;
		__forceinline void zeroElement( int i );
		__forceinline static const hkVector4& __cdecl getZero();
		void load3(const hkReal* p);
		void load4(const hkReal* p);
		void load4a(const hkReal* p);
		void store3(hkReal* p) const;
		void store4(hkReal* p) const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline void getRow( int row, hkVector4& r) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		__forceinline void setRows( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getRows( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setCols( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
		__forceinline void getCols( hkVector4& r0, hkVector4& r1, hkVector4& r2) const;
		__forceinline void setZero();
		__forceinline void setDiagonal( hkReal m00, hkReal m11, hkReal m22 );
		__forceinline void setIdentity();
		static const hkMatrix3& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkMatrix3& m, hkReal epsilon=1e-3f ) const;
		void setCrossSkewSymmetric( const hkVector4& r );
		hkResult invert(hkReal epsilon);
		void invertSymmetric();
		__forceinline void _invertSymmetric();
		void transpose();
		void setTranspose( const hkMatrix3& s );
		__forceinline void _setTranspose( const hkMatrix3& s );
		void setMul( const hkMatrix3& a, const hkMatrix3& b );
		__forceinline void _setMul( const hkMatrix3& a, const hkMatrix3& b );
		void setMulInverse( const hkMatrix3& a, const hkRotation& b );
		void setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		__forceinline void _setMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void addMul( hkSimdRealParameter scale, const hkMatrix3& a );
		void changeBasis(const hkRotation& t);
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
struct hkpSolverInfo
{
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
class hkpConstraintData;
class hkpEntity;
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
class hkpWorldCinfo : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum SolverType
		{
			SOLVER_TYPE_INVALID,
			SOLVER_TYPE_2ITERS_SOFT,
			SOLVER_TYPE_2ITERS_MEDIUM,
			SOLVER_TYPE_2ITERS_HARD,
			SOLVER_TYPE_4ITERS_SOFT,
			SOLVER_TYPE_4ITERS_MEDIUM,
			SOLVER_TYPE_4ITERS_HARD,
			SOLVER_TYPE_8ITERS_SOFT,
			SOLVER_TYPE_8ITERS_MEDIUM,
			SOLVER_TYPE_8ITERS_HARD,
			SOLVER_TYPE_MAX_ID
		};
		enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
		enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
		enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
		hkpWorldCinfo();
		void setupSolverInfo(enum SolverType st);
		void setBroadPhaseWorldSize(hkReal size);
	public:
		hkVector4 m_gravity;
		hkInt32 m_broadPhaseQuerySize;
		hkReal m_contactRestingVelocity;
		hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
		class hkAabb m_broadPhaseWorldAabb;
		hkReal m_collisionTolerance;
		class hkpCollisionFilter* m_collisionFilter;
		class hkpConvexListFilter* m_convexListFilter;
		hkReal m_expectedMaxLinearVelocity;
		int m_sizeOfToiEventQueue;
		hkReal m_expectedMinPsiDeltaTime;
		class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
		hkInt32 m_broadPhaseNumMarkers;
		hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
		hkReal m_solverTau;
		hkReal m_solverDamp;
		hkInt32 m_solverIterations;
		hkInt32 m_solverMicrosteps;
		hkBool m_forceCoherentConstraintOrderingInSolver;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_enableDeprecatedWelding;
		hkReal m_iterativeLinearCastEarlyOutDistance;
		hkInt32 m_iterativeLinearCastMaxIterations;
		hkReal m_highFrequencyDeactivationPeriod;
		hkReal m_lowFrequencyDeactivationPeriod;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
		hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
		hkUint8 m_deactivationIntegrateCounter;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		int m_maxSectorsPerCollideTask;
		hkBool m_processToisMultithreaded;
		int m_maxEntriesPerToiCollideTask;
		hkBool m_enableDeactivation;
		hkEnum<SimulationType, hkInt8> m_simulationType;
		hkBool m_enableSimulationIslands;
		hkUint32 m_minDesiredIslandSize;
		hkBool m_processActionsInSingleThread;
		hkReal m_frameMarkerPsiSnap;
		virtual ~hkpWorldCinfo() {}
		explicit hkpWorldCinfo( hkFinishLoadedObjectFlag flag );
};
class hkpCollisionDispatcher;
class hkpCollidable;
struct hkpCollisionInput;
struct hkpProcessCollisionInput;
class hkpCollisionListener;
class hkpTypedBroadPhaseDispatcher;
struct hkpWorldRayCastInput;
struct hkpWorldRayCastOutput;
struct hkpLinearCastInput;
class hkpRayHitCollector;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
class hkpBroadPhase;
class hkpBroadPhaseHandle;
class hkpEntityListener;
class hkpRigidBody;
class hkpPhantom;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpAction;
class hkpActionListener;
class hkpConstraintInstance;
class hkpConstraintListener;
class hkpPhysicsSystem;
class hkpSimulationIsland;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
namespace hkWorldOperation {
struct BaseOperation;
class UserCallback;
}
enum hkpUpdateCollisionFilterOnWorldMode
{
	HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
	HK_UPDATE_FILTER_ON_WORLD_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
};
enum hkpUpdateCollisionFilterOnEntityMode
{
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation
{
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE,
	HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
enum hkpUpdateCollectionFilterMode
{
	HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS,
	HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS
};
struct hkpWorldDynamicsStepInfo
{
	hkStepInfo   m_stepInfo;
	hkpSolverInfo m_solverInfo;
};
struct hkpMultithreadConfig
{
	hkpMultithreadConfig();
	enum CanCpuTakeSpuTasks
	{
		CPU_CAN_TAKE_SPU_TASKS,
		CPU_CAN_NOT_TAKE_SPU_TASKS
	};
	hkUint32 m_maxNumConstraintsSolvedSingleThreaded;
};
enum hkpThreadToken
{
	HK_THREAD_TOKEN_FIRST,
	HK_THREAD_TOKEN_SECOND,
	HK_THREAD_TOKEN_THIRD,
	HK_THREAD_TOKEN_FORTH,
	HK_THREAD_TOKEN_FIFTH,
	HK_THREAD_TOKEN_SIXTH,
};
enum hkpStepResult
{
	HK_STEP_RESULT_SUCCESS,
	HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};
class hkpWorld : public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpWorld(const hkpWorldCinfo& info, unsigned int sdkversion = ((10000*5) + (100*5) + (0)) );
		void getCinfo(hkpWorldCinfo& info) const;
		hkpEntity* addEntity( hkpEntity* entity, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
		void checkDeterminism();
		hkWorldMemoryAvailableWatchDog* getMemoryWatchDog( ) const;
		void setMemoryWatchDog( hkWorldMemoryAvailableWatchDog* watchDog );
		void lock();
		void lockReadOnly();
		void unlock();
		void unlockReadOnly();
		bool isLocked();
		void lockIslandForConstraintUpdate( hkpSimulationIsland* island );
		void unlockIslandForConstraintUpdate( hkpSimulationIsland* island );
		enum MtAccessChecking
		{
			MT_ACCESS_CHECKING_ENABLED = 0,
			MT_ACCESS_CHECKING_DISABLED
		};
		inline void setMultithreadedAccessChecking( MtAccessChecking accessCheckState );
		inline MtAccessChecking getMultithreadedAccessChecking() const;
		void markForRead( ) const;
		void markForWrite( );
		void unmarkForRead( ) const;
		void unmarkForWrite();
		void addActionListener( hkpActionListener* worldListener );
		void removeActionListener( hkpActionListener* worldListener );
		void addConstraintListener( hkpConstraintListener* worldListener );
		void removeConstraintListener( hkpConstraintListener* worldListener );
		void addEntityListener( hkpEntityListener* worldListener );
		void removeEntityListener( hkpEntityListener* worldListener );
		void addPhantomListener( hkpPhantomListener* worldListener );
		void removePhantomListener( hkpPhantomListener* worldListener );
		void addIslandActivationListener( hkpIslandActivationListener* worldListener );
		void removeIslandActivationListener( hkpIslandActivationListener* worldListener );
		void addWorldPostCollideListener( hkpWorldPostCollideListener* worldListener );
		void removeWorldPostCollideListener( hkpWorldPostCollideListener* worldListener );
		void addWorldPostSimulationListener( hkpWorldPostSimulationListener* worldListener );
		void removeWorldPostSimulationListener( hkpWorldPostSimulationListener* worldListener );
		void addWorldPostIntegrateListener( hkpWorldPostIntegrateListener* worldListener );
		void removeWorldPostIntegrateListener( hkpWorldPostIntegrateListener* worldListener );
		void addIslandPostCollideListener( hkpIslandPostCollideListener* islandListener );
		void removeIslandPostCollideListener( hkpIslandPostCollideListener* islandListener );
		void addIslandPostIntegrateListener( hkpIslandPostIntegrateListener* islandListener );
		hkTime getCurrentTime() const;
		hkTime getCurrentPsiTime() const;
		class hkJobQueue* getJobQueue();
		void getMultithreadConfig( hkpMultithreadConfig& config );
		void setMultithreadConfig( const hkpMultithreadConfig& config );
		hkMultiThreadCheck& getMultiThreadCheck() const { return m_multiThreadCheck; }
		void checkAccessGetActiveSimulationIslands() const;
		hkpPhysicsSystem* getWorldAsOneSystem() const;
		void getWorldAsSystems(hkArray<hkpPhysicsSystem*>& systemsOut) const;
		~hkpWorld();
	public:
		hkpSimulation* m_simulation;
		hkVector4			m_gravity;
        hkpSimulationIsland* m_fixedIsland;
			hkpRigidBody*	m_fixedRigidBody;
        hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
        hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
        hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
        hkpWorldMaintenanceMgr* m_maintenanceMgr;
        hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
        hkpBroadPhase* m_broadPhase;
        hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
        hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
        hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
        hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
        hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
        hkpProcessCollisionInput* m_collisionInput;
            hkpCollisionFilter*       m_collisionFilter;
            hkpCollisionDispatcher*   m_collisionDispatcher;
            hkpConvexListFilter*     m_convexListFilter;
        hkpWorldOperationQueue* m_pendingOperations;
			int m_pendingOperationsCount;
			int m_criticalOperationsLockCount;
			int m_criticalOperationsLockCountForPhantoms;
			hkBool m_blockExecutingPendingOperations;
			hkBool m_criticalOperationsAllowed;
            hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
			int m_pendingOperationQueueCount;
        mutable class hkMultiThreadCheck m_multiThreadCheck;
		hkBool m_processActionsInSingleThread;
		hkUint32 m_minDesiredIslandSize;
        class hkCriticalSection* m_modifyConstraintCriticalSection;
        class hkCriticalSection* m_worldLock;
        class hkCriticalSection* m_islandDirtyListCriticalSection;
		struct PropertyLock
		{
			hkUint32 m_key;
			mutable hkMultiThreadCheck m_multiThreadCheck;
		};
        class hkCriticalSection* m_propertyMasterLock;
		hkBool m_wantSimulationIslands;
		hkReal m_snapCollisionToConvexEdgeThreshold;
		hkReal m_snapCollisionToConcaveEdgeThreshold;
		hkBool m_enableToiWeldRejection;
		hkBool m_wantDeactivation;
		hkBool m_shouldActivateOnRigidBodyTransformChange;
		hkReal m_deactivationReferenceDistance;
		hkReal m_toiCollisionResponseRotateNormal;
		hkBool m_processToisMultithreaded;
		int m_maxSectorsPerCollideTask;
		int m_maxEntriesPerToiCollideTask;
        hkEnum<hkpWorldCinfo::SimulationType,hkInt32>  m_simulationType;
		static hkBool m_forceMultithreadedSimulation;
		class IgnoreForceMultithreadedSimulation
		{
			public:
				~IgnoreForceMultithreadedSimulation() { hkpWorld::m_forceMultithreadedSimulation = m_originalForceMultithreadedSimulationValue; }
			public:
				hkBool m_originalForceMultithreadedSimulationValue;
		};
	protected:
		hkUint32 m_lastEntityUid;
	public:
		friend class hkpWorldOperationUtil;
		friend class hkpWorldCallbackUtil;
		friend class hkpSimulation;
		friend class hkHalfstepSimulation;
		friend class hkpContinuousSimulation;
		friend class hkpMultiThreadedSimulation;
		friend class hkpSimpleConstraintContactMgr;
	public:
		__forceinline void	allowCriticalOperations(hkBool allow);
		explicit hkpWorld( hkFinishLoadedObjectFlag flag );
};
inline void hkpWorld::markForRead( ) const
{
}
inline void hkpWorld::markForWrite( )
{
}
inline void hkpWorld::unmarkForRead( ) const
{
}
inline void hkpWorld::unmarkForWrite()
{
}
class hkpConstraintQueryIn;
struct hkpProcessCollisionOutput;
struct hkpAgentNnEntry;
class hkpSimulation: public hkReferencedObject
{
	public:
        static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpSimulation( hkpWorld* world );
        hkpSimulation( hkFinishLoadedObjectFlag flag ) : hkReferencedObject(flag) {}
		~hkpSimulation();
		virtual hkpStepResult stepDeltaTime( hkReal physicsDeltaTime );
		virtual hkpStepResult integrate( hkReal physicsDeltaTime );
		virtual hkpStepResult collide();
		virtual hkpStepResult advanceTime();
		void setFrameTimeMarker( hkReal frameDeltaTime );
		bool isSimulationAtMarker();
		bool isSimulationAtPsi() const;
		inline hkReal getCurrentTime() { return m_currentTime; }
		inline hkReal getCurrentPsiTime() { return m_currentPsiTime; }
		inline hkReal getSimulateUntilTime() { return m_simulateUntilTime; }
		inline hkReal getPhysicsDeltaTime() { return m_physicsDeltaTime; }
		enum FindContacts
		{
			FIND_CONTACTS_DEFAULT = 0,
			FIND_CONTACTS_EXTRA
		};
		virtual void collideEntitiesDiscrete( hkpEntity** entities, int numEntities, hkpWorld* world, const hkStepInfo& stepInfo, FindContacts findExtraContacts  );
		static void collideEntitiesBroadPhaseDiscrete( hkpEntity** entities, int numEntities, hkpWorld* world );
		void collideEntitiesNarrowPhaseDiscrete( hkpEntity** entities, int numEntities, const hkpProcessCollisionInput& input, FindContacts findExtraContacts );
		virtual void resetCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world, hkBool skipReinitializationOfAgents = false );
		virtual void assertThereIsNoCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world ) {}
		virtual void removeCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
		virtual void assertThereIsNoCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
	protected:
		friend class hkpWorld;
		friend class hkpWorldOperationQueue;
		virtual void reintegrateAndRecollideEntities( hkpEntity** entityBatch, int numEntities, hkpWorld* world, int reintegrateRecollideMode );
	protected:
		void checkDeltaTimeIsOk( hkReal deltaTime );
		hkpStepResult reCollideAfterStepFailure();
		virtual void collideInternal( const hkStepInfo& stepInfoIn );
		void integrateInternal( const hkStepInfo& stepInfoIn );
		void applyActions();
		static __forceinline void integrateIsland( hkpSimulationIsland* isle, const hkpWorldDynamicsStepInfo& stepInfo, hkpConstraintQueryIn& constraintQueryIn );
		static __forceinline void collideIslandNarrowPhaseDiscrete( hkpSimulationIsland* isle, const hkpProcessCollisionInput& input);
		hkReal snapSimulateTimeAndGetTimeToAdvanceTo();
		typedef void (hkpSimulation::*AgentEntryProcessFunction)(hkpAgentNnEntry*, const hkpProcessCollisionInput&, hkpProcessCollisionOutput&);
		void processAgentCollideDiscrete(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& processInput, hkpProcessCollisionOutput& processOutput);
		void processAgentResetCollisionInformation(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& processInput, hkpProcessCollisionOutput& processOutput);
	public:
		virtual void warpTime( hkReal deltaTime ) {}
	public:
		void setCurrentTime( hkTime time ) { m_currentTime = time; }
		void setCurrentPsiTime( hkTime time ) { m_currentPsiTime = time; }
		void setSimulateUntilTime ( hkTime time ) { m_simulateUntilTime = time; }
		hkpWorld* getWorld(){ return m_world; }
	public:
		hkUint32 m_determinismCheckFrameCounter;
	protected:
		class hkpWorld* m_world;
		enum LastProcessingStep
		{
			INTEGRATE,
			COLLIDE
		};
        hkEnum<LastProcessingStep,hkUint8> m_lastProcessingStep;
		hkTime m_currentTime;
		hkTime m_currentPsiTime;
		hkReal m_physicsDeltaTime;
		hkTime m_simulateUntilTime;
		hkReal m_frameMarkerPsiSnap;
        hkUint32 m_previousStepResult;
};
class hkpVelocityAccumulator;
class hkpTypedBroadPhaseHandlePair;
class hkpBroadPhaseListener
{
	public:
		virtual ~hkpBroadPhaseListener() {}
		virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair ) = 0;
		virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair ) = 0;
};
extern "C" {
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
extern "C" {
extern "C" {
typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;
}
typedef long LONG;
typedef void *HANDLE;
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;
typedef struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD   Type;
    WORD   CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD   CreatorBackTraceIndexHigh;
    WORD   SpareWORD  ;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;
typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
}
}
extern "C" {
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
}
extern "C" {
}
class hkCriticalSection
{
	public:
		inline hkCriticalSection( int spinCount = 0, hkBool32 addToList = true );
		inline ~hkCriticalSection();
		inline void enter();
		inline bool haveEntered();
		inline bool isEntered() const;
		inline void leave();
		static inline void __cdecl setTimersEnabled();
		static inline void __cdecl setTimersDisabled();
		static __forceinline hkUint32 __cdecl atomicExchangeAdd(hkUint32* var, int value);
	public:
		CRITICAL_SECTION  m_section;
		hkUint64 m_currentThread;
		struct SectionList
		{
			SectionList( hkCriticalSection* section, int spinCount, hkBool32 addToList );
			~SectionList();
			int m_spinCount;
			hkCriticalSection* m_prev;
			hkCriticalSection* m_next;
			static hkCriticalSection s_listHead;
		};
		SectionList m_list;
};
class hkSemaphore
{
	public:
		hkSemaphore( int initialCount = 0, int maxCount = 1000 );
		hkSemaphore( hkFinishLoadedObjectFlag f) {}
		~hkSemaphore();
		void acquire();
		void release(int count = 1);
		static void __cdecl acquire(hkSemaphore* semaphoreOnPpu);
		static void __cdecl release(hkSemaphore* semaphoreOnPpu, int count = 1);
	protected:
	protected:	void* m_semaphore;
};
typedef hkSemaphore hkSemaphoreBusyWait;
template <typename T>
class hkQueue
{
	public:
		hkQueue();
		hkQueue( int capacity );
		~hkQueue();
		inline void setCapacity(int n);
		inline void enqueue( const T& element );
		inline void enqueueInFront( const T& element );
		inline void dequeue( T& data );
		inline void clear();
		inline hkBool isEmpty() const;
		inline int getSize() const;
		inline int getCapacity() const;
	private:
		inline void increaseCapacity();
		void releaseMemory();
		T* m_data;
		int m_capacity;
		int m_head;
		int m_tail;
		int m_elementsInUse;
};
class hkJobQueue
{
	public:
		enum Rules
		{
			NO_SPU_AVAILABLE,
			SPU_AVAILABLE_AND_PPU_CAN_TAKE_SPU_TASKS,
			SPU_AVAILABLE_AND_PPU_CANNOT_TAKE_SPU_TASKS
		};
		void setJobQueryRules( Rules rules );
		struct JobQueueEntry
		{
			__declspec(align(16)) hkUchar m_data[128];
		};
		enum JobType
		{
			JOB_TYPE_CPU			= 0,
			JOB_TYPE_CPU_BROADPHASE	= 1,
			JOB_TYPE_CPU_MASTER		= 2,
			JOB_TYPE_HINT_SPU		= 0,
			JOB_TYPE_HINT_SPU_CD	= 0,
			JOB_TYPE_HINT_SPU_CQ	= 0,
			JOB_TYPE_MAX			= 3,
		};
		struct DynamicData
		{
			__declspec(align(16)) int m_numActiveJobs;
			int m_numCpuThreadsWaitingForJobs;
			int m_numSpuThreadsWaitingForJobs;
			int m_numMasterThreadsWaitingForJobs;
			hkBool m_dontReleaseSpus;
			hkQueue< JobQueueEntry > m_jobQueue[JOB_TYPE_MAX];
		};
		enum ThreadType
		{
			THREAD_TYPE_CPU				= JOB_TYPE_CPU,
			THREAD_TYPE_CPU_BROADPHASE	= JOB_TYPE_CPU_BROADPHASE,
			THREAD_TYPE_CPU_MASTER		= JOB_TYPE_CPU_MASTER,
			THREAD_TYPE_MAX				= JOB_TYPE_MAX,
			THREAD_TYPE_INVALID			= -1,
		};
		enum JobPriority
		{
			JOB_HIGH_PRIORITY,
			JOB_LOW_PRIORITY,
		};
		enum JobPopFuncResult
		{
			POP_QUEUE_ENTRY,
			DO_NOT_POP_QUEUE_ENTRY
		};
		typedef JobPopFuncResult (__cdecl *JobPopFunc)( hkJobQueue& queue, hkJobQueue::DynamicData* data, JobQueueEntry& jobIn, JobQueueEntry& jobOut );
		enum JobCreationStatus
		{
			JOB_CREATED,
			NO_JOB_CREATED
		};
		struct JobQueueEntryInput
		{
			hkPadSpu<hkUint32>	m_jobThreadType;
			hkPadSpu<hkUint32>	m_jobPriority;
			JobQueueEntry		m_job;
		};
		typedef JobCreationStatus (__cdecl *FinishJobFunc)( hkJobQueue& queue, DynamicData* data, const JobQueueEntry& jobIn, JobQueueEntryInput& newJobCreatedOut );
	public:
		 hkJobQueue(hkSemaphoreBusyWait* cpuWaitSemaphore, hkSemaphoreBusyWait* taskCompletionSemaphore, hkSemaphoreBusyWait* spuWaitSemaphore);
		~hkJobQueue();
	public:
		void addJob( void* job, JobPriority priority, JobType type );
		void addJobBatch( hkArray<JobQueueEntry*>& jobs, JobPriority priority, JobType type );
		enum WaitStatus
		{
			WAIT_FOR_NEXT_JOB,
			DO_NOT_WAIT_FOR_NEXT_JOB
		};
		enum JobStatus
		{
			GOT_NEXT_JOB,
			NO_JOBS_AVAILABLE,
			JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
			ALL_JOBS_FINISHED
		};
		JobStatus getNextJob( ThreadType threadType, JobQueueEntry& job, WaitStatus waitStatus = WAIT_FOR_NEXT_JOB );
		void setSpuQueueCapacity(int queueCapacity);
	public:
		void releaseOneWaitingThread( JobType jobThreadType, DynamicData* data  );
		__forceinline void checkQueueAndReleaseOneWaitingThread( ThreadType threadType, DynamicData* data  );
		__forceinline JobStatus findNextJob(ThreadType threadType, JobQueueEntry& jobOut, DynamicData* data );
		__forceinline hkBool allQueuesEmpty( DynamicData* data );
		DynamicData* lockQueue( char* dynamicDataStorage );
		void unlockQueue( char* dynamicDataStorage );
		void releaseWaitingThreads(DynamicData* data);
	public:
		__declspec(align(64)) hkCriticalSection m_criticalSection;
		DynamicData* m_data;
		struct JobQueryRule
		{
			hkUint8 m_numJobTypesAvailable;
			hkEnum<JobType, hkUint8> m_jobTypeOrder[JOB_TYPE_MAX];
		};
		JobQueryRule m_jobQueryRules[JOB_TYPE_MAX];
		JobPopFunc m_jobPopFunc;
		FinishJobFunc m_finishJobFunc;
		hkUlong m_userData;
		hkSemaphoreBusyWait* m_masterThreadWaitSemaphore;
		hkSemaphoreBusyWait* m_cpuWaitSemaphore;
		hkSemaphoreBusyWait* m_taskCompletionSemaphore;
		hkSemaphoreBusyWait* m_spuWaitSemaphore;
};
class hkpShapeCollectionFilter;
struct hkpCollisionAgentConfig;
struct hkpCollisionInput
{
	public:
		hkReal getTolerance() const { return m_tolerance; }
		void setTolerance(hkReal t) { m_tolerance = t; }
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};
struct hkpCollisionQualityInfo;
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
class hkpConstraintQueryStepInfo
{
	public:
		__declspec(align(16)) hkPadSpu<float> m_substepDeltaTime;
		hkPadSpu<float>		m_microStepDeltaTime;
		hkPadSpu<float>		m_substepInvDeltaTime;
		hkPadSpu<float>		m_frameDeltaTime;
		hkPadSpu<float>		m_frameInvDeltaTime;
		hkPadSpu<float>		m_invNumSteps;
		hkPadSpu<float>		m_invNumStepsTimesMicroSteps;
		hkPadSpu<float>		m_rhsFactor;
		hkPadSpu<float>		m_virtMassFactor;
		hkPadSpu<float> m_frictionRhsFactor;
};
class hkpConstraintQueryIn: public hkpConstraintQueryStepInfo
{
	public:
		hkpConstraintQueryIn() { }
		__declspec(align(16)) hkPadSpu<const hkpVelocityAccumulator*> m_bodyA;
		hkPadSpu<const hkpVelocityAccumulator*>	m_bodyB;
		hkPadSpu<const hkTransform*>	m_transformA;
		hkPadSpu<const hkTransform*>	m_transformB;
		hkPadSpu<hkReal> m_tau;
		hkPadSpu<hkReal> m_damping;
		hkPadSpu<class hkpConstraintInstance*>	m_constraintInstance;
		hkPadSpu<void*>	m_constraintRuntime;
		hkPadSpu<hkUint32> m_accumulatorAIndex;
		hkPadSpu<hkUint32> m_accumulatorBIndex;
		hkPadSpu<void*> m_constraintRuntimeInMainMemory;
		inline void set( const hkpSolverInfo& si, const hkStepInfo& stepInfo )
		{
			m_substepDeltaTime    = si.m_deltaTime;
			m_microStepDeltaTime  = si.m_deltaTime * si.m_invNumMicroSteps;
			m_substepInvDeltaTime = si.m_invDeltaTime;
			m_invNumSteps		  = si.m_invNumSteps;
			m_invNumStepsTimesMicroSteps	  = si.m_invNumSteps * si.m_invNumMicroSteps;
			m_tau			      = si.m_tau;
			m_damping		      = si.m_damping;
			m_rhsFactor			  = si.m_tauDivDamp * si.m_invDeltaTime;
			m_virtMassFactor      = si.m_damping;
			m_frictionRhsFactor   = si.m_frictionTauDivDamp * si.m_invDeltaTime;
			m_frameDeltaTime      = stepInfo.m_deltaTime;
			m_frameInvDeltaTime   = stepInfo.m_invDeltaTime;
		}
};
struct hkpToiEvent;
class hkpToiResourceMgr;
struct hkpBuildJacobianTaskHeader;
class hkpContinuousSimulation : public hkpSimulation
{
	public:
		hkpContinuousSimulation( hkpWorld* world );
		virtual ~hkpContinuousSimulation();
		virtual void processAgentNnEntries( const hkArray<hkpAgentNnEntry*>& entries, const hkpProcessCollisionInput& collisionInput, hkpSimulationIsland* island, hkBool forceManifoldQualityType );
	public:
		__declspec(align(16)) hkArray<hkpToiEvent> m_toiEvents;
		hkpToiResourceMgr* m_toiResourceMgr;
		int m_toiCounter;
};
class hkpMultiThreadedSimulation : public hkpContinuousSimulation
{
	public:
		hkpMultiThreadedSimulation( hkpWorld* world );
		virtual ~hkpMultiThreadedSimulation();
		void processNextJob( hkJobQueue::ThreadType threadType );
		virtual void FUN_00981af0( const hkArray<hkpAgentNnEntry*>& entries, const hkpProcessCollisionInput& collisionInput, hkpSimulationIsland* island, hkBool forceManifoldQualityType );
		class MtEntityEntityBroadPhaseListener : public hkpBroadPhaseListener
		{
			public:
				MtEntityEntityBroadPhaseListener();
				virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				hkpMultiThreadedSimulation* m_simulation;
		};
		class MtPhantomBroadPhaseListener : public hkpBroadPhaseListener
		{
			public:
				MtPhantomBroadPhaseListener();
				virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				hkCriticalSection* m_criticalSection;
		};
		class MtBroadPhaseBorderListener : public hkpBroadPhaseListener
		{
			public:
				MtBroadPhaseBorderListener();
				virtual void addCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				virtual void removeCollisionPair( hkpTypedBroadPhaseHandlePair& pair );
				hkCriticalSection* m_criticalSection;
		};
	public:
		MtEntityEntityBroadPhaseListener m_entityEntityBroadPhaseListener;
		MtPhantomBroadPhaseListener m_phantomBroadPhaseListener;
		MtBroadPhaseBorderListener m_broadPhaseBorderListener;
		hkBool m_crossIslandPairsCollectingActive;
		hkArray<hkpTypedBroadPhaseHandlePair> m_addedCrossIslandPairs;
		hkCriticalSection m_addCrossIslandPairCriticalSection;
		hkArray<hkpTypedBroadPhaseHandlePair> m_removedCrossIslandPairs;
		hkCriticalSection m_removeCrossIslandPairCriticalSection;
		hkpMultithreadConfig m_multithreadConfig;
		int m_numActiveThreads;
		hkSemaphore m_stepInitSemaphore;
		int m_numActiveIslandsAtBeginningOfStep;
		int m_numInactiveIslandsAtBeginningOfStep;
		hkCriticalSection m_threadTokenCriticalSection;
		hkJobQueue m_jobQueue;
		__declspec(align(128)) hkSemaphore m_jobQueueCpuWaitSemaphore;
		__declspec(align(128)) hkSemaphore m_jobQueueTaskCompletionSemaphore;
		__declspec(align(128)) hkSemaphore m_jobQueueSpuWaitSemaphore;
		__declspec(align(64)) hkCriticalSection m_toiQueueCriticalSection;
		__declspec(align(64)) hkCriticalSection m_phantomCriticalSection;
};
class hkpDynamicsJob
{
	public:
		enum JobType
		{
			DYNAMICS_JOB_INTEGRATE = 0,
			DYNAMICS_JOB_BUILD_ACCUMULATORS = 1,
			DYNAMICS_JOB_CREATE_JACOBIAN_TASKS = 2,
			DYNAMICS_JOB_FIRE_JACOBIAN_SETUP_CALLBACK = 3,
			DYNAMICS_JOB_BUILD_JACOBIANS = 4,
			DYNAMICS_JOB_SPLIT_ISLAND = 5,
			DYNAMICS_JOB_SOLVE_CONSTRAINTS = 6,
			DYNAMICS_JOB_SOLVE_APPLY_GRAVITY = 7,
			DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH = 8,
			DYNAMICS_JOB_SOLVE_INTEGRATE_VELOCITIES = 9,
			DYNAMICS_JOB_SOLVE_EXPORT_RESULTS = 10,
			DYNAMICS_JOB_INTEGRATE_MOTION = 11,
			DYNAMICS_JOB_BROADPHASE = 12,
			DYNAMICS_JOB_AGENT_SECTOR = 13,
			DYNAMICS_JOB_POST_COLLIDE = 14,
			DYNAMICS_JOB_AGENT_NN_ENTRY = 15,
			DYNAMICS_JOB_END = 16
		};
		typedef hkEnum<JobType, hkUint16> hkpDynamicsJobType;
		enum NoJob
		{
			NO_SRC_JOB = 0
		};
		__forceinline hkpDynamicsJob( JobType type, NoJob noJob )
		{
			m_jobType = type;
			m_islandIndex = 0xffff;
			m_island = 0;
			m_taskHeader = 0;
		}
		__forceinline hkpDynamicsJob( JobType type, const hkpDynamicsJob& srcJob )
		{
			m_jobType = type;
			m_islandIndex = srcJob.m_islandIndex;
			m_island = srcJob.m_island;
			m_taskHeader = srcJob.m_taskHeader;
		}
	public:
		__declspec(align(16)) hkpDynamicsJobType m_jobType;
		hkObjectIndex m_islandIndex;
		hkpSimulationIsland* m_island;
		hkpBuildJacobianTaskHeader* m_taskHeader;
};
struct hkpAgentSectorHeader
{
	static hkpAgentSectorHeader* __cdecl allocate( int numTasks, int numElementsPerTask );
	void deallocate();
	static int __cdecl getAllocatedSize( int numTasks );
	int m_numTotalTasks;
	int m_openJobs;
	int m_sizeOfJobInfo;
};
class hkpAgentBaseJob : public hkpDynamicsJob
{
	public:
		enum
		{
			MAX_AGENT_NN_ENTRIES_PER_TASK = 16
		};
		__forceinline hkpAgentBaseJob( NoJob noJob, const hkStepInfo& stepInfo, const void* elements, int numElements, int maxNumElementsPerTask, JobType type )
			: hkpDynamicsJob( type, noJob )
		{
			m_stepInfo = stepInfo;
			m_islandIndex = 0;
			m_taskIndex = 0;
			m_elements = elements;
			m_numElements = hkUint16( numElements );
			m_numElementsPerTask = hkUint16( maxNumElementsPerTask );
			m_header = 0;
		}
	public:
		hkpAgentSectorHeader* m_header;
		hkUint16 m_taskIndex;
		hkUint16 m_numTotalTasks;
		hkUint16 m_numElements;
		hkUint16 m_numElementsPerTask;
		const void* m_elements;
		hkStepInfo m_stepInfo;
};
class hkpAgentNnEntryJob : public hkpAgentBaseJob
{
	public:
		__forceinline hkpAgentNnEntryJob( const hkStepInfo& stepInfo, hkpAgentNnEntry* const* elements, int numElements, int maxNumElementsPerTask, hkBool forceManifoldQualityType )
			: hkpAgentBaseJob( NO_SRC_JOB, stepInfo, elements, numElements, maxNumElementsPerTask, DYNAMICS_JOB_AGENT_NN_ENTRY )
		{
			m_forceManifoldQualityType = forceManifoldQualityType;
		}
	public:
		hkBool m_forceManifoldQualityType;
};
class hkpPostCollideJob : public hkpDynamicsJob
{
	public:
		__forceinline hkpPostCollideJob( const hkpAgentBaseJob& job )
			: hkpDynamicsJob( DYNAMICS_JOB_POST_COLLIDE, job )
		{
			m_islandIndex = job.m_islandIndex;
			m_header = job.m_header;
		}
	public:
		hkpAgentSectorHeader* m_header;
};
__declspec(align(16)) struct hkpMtThreadStructure
{
	hkpMtThreadStructure( hkpWorld* world, hkpMultiThreadedSimulation* simulation, hkJobQueue::ThreadType threadType );
	hkpWorld* m_world;
	hkpMultiThreadedSimulation* m_simulation;
	hkJobQueue::ThreadType m_threadType;
	hkpProcessCollisionInput m_collisionInput;
	hkpConstraintQueryIn m_constraintQueryIn;
};
hkJobQueue::JobStatus __cdecl hkCpuPostCollideJob( hkpMtThreadStructure& tl, hkJobQueue* jobQueue, void* jobInOut );
typedef char AgentJobSize64[sizeof(hkpAgentNnEntryJob) == 64 ? 1 : -1];
typedef char PostJobSize32[sizeof(hkpPostCollideJob) == 32 ? 1 : -1];
typedef char ThreadSize224[sizeof(hkpMtThreadStructure) == 224 ? 1 : -1];
typedef char QueueEntrySize128[sizeof(hkJobQueue::JobQueueEntry) == 128 ? 1 : -1];
typedef char AgentAlignment16[__alignof(hkpAgentNnEntryJob) == 16 ? 1 : -1];
typedef char PostAlignment16[__alignof(hkpPostCollideJob) == 16 ? 1 : -1];
typedef char ThreadAlignment16[__alignof(hkpMtThreadStructure) == 16 ? 1 : -1];
void hkpMultiThreadedSimulation::FUN_00981af0( const hkArray<hkpAgentNnEntry*>& entries, const hkpProcessCollisionInput& collisionInput, hkpSimulationIsland* island, hkBool forceManifoldQualityType )
{
	if ( m_world->m_processToisMultithreaded && m_jobQueue.m_data->m_dontReleaseSpus )
	{
		int maxEntriesPerAgentNnEntryTask = m_world->m_maxEntriesPerToiCollideTask;
		const hkArray<hkpAgentNnEntry*>& entriesOnPpu = entries;
		__declspec(align(16)) unsigned char jobWorkspace[sizeof(hkpAgentNnEntryJob) + sizeof(hkpPostCollideJob) + sizeof(hkpMtThreadStructure)];
        hkpAgentNnEntryJob& agentEntryJob = *new (jobWorkspace) hkpAgentNnEntryJob( collisionInput.m_stepInfo, entriesOnPpu.begin(), entriesOnPpu.getSize(), maxEntriesPerAgentNnEntryTask, forceManifoldQualityType );
		if ( entriesOnPpu.getSize() > 0 )
		{
			int numTasks = ( entriesOnPpu.getSize() - 1 ) / maxEntriesPerAgentNnEntryTask + 1;
			agentEntryJob.m_header = hkpAgentSectorHeader::allocate( numTasks, maxEntriesPerAgentNnEntryTask );
			m_jobQueue.addJob( jobWorkspace, hkJobQueue::JOB_LOW_PRIORITY, hkJobQueue::JOB_TYPE_CPU );
		}
		m_world->unmarkForWrite();
		m_world->markForRead();
		processNextJob( hkJobQueue::THREAD_TYPE_CPU_MASTER );
		m_world->unmarkForRead();
		m_world->markForWrite();
		if ( entriesOnPpu.getSize() > 0 )
		{
			hkpPostCollideJob& postCollideJob = *new (jobWorkspace + sizeof(hkpAgentNnEntryJob)) hkpPostCollideJob( agentEntryJob );
			postCollideJob.m_island = island;
			void* threadSlot = jobWorkspace + sizeof(hkpAgentNnEntryJob) + sizeof(hkpPostCollideJob);
            new (threadSlot) hkpMtThreadStructure( m_world, this, hkJobQueue::THREAD_TYPE_CPU );
            hkpMtThreadStructure& tl = *static_cast<hkpMtThreadStructure*>(threadSlot);
			hkCpuPostCollideJob( tl, 0, &postCollideJob );
		}
	}
	else
	{
		hkpContinuousSimulation::processAgentNnEntries( entries, collisionInput, island, forceManifoldQualityType );
	}
}

}  // namespace f3m_00981af0
}   // namespace f3m_00981af0

// @f3 0x00997130 (community match, verified in this file)
// 0x00997130: hkp3AxisSweep::addObjectBatch(hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray<hkAabb>&
// addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs) of Havok 5.5.0 (hkpInternal, hkp3AxisSweep.cpp, compiled
// with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Adds a batch of objects to the 3-axis sweep: grows the node array and the
// three end point arrays, converts each AABB to the 16-bit grid and writes the node and its six end points, sorts
// the new end points of each axis and merges them into the axis, moves the markers' node bounds, then queries the
// pairs of the new nodes through a bit field.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by a reducer, then whole unused lines, every cut checked byte for byte); those declarations are the
// SDK's text with its names. hkp3AxisSweep itself is a class of the hkpInternal library that no SDK header ships:
// it is declared from the library's debug records (base class, data members, nested types, the methods used).
// The body follows the library's unoptimized object (its line table and named locals); written with the SDK's
// own helpers it compiles to the SDK's release object (1704 bytes, all named locals at the library's places).
// The game's build differs from that object in the inlined AABB conversion only, and so does this file:
// (1) hkp3AxisSweep::_convertAabbToInt copies MaxVal into a local vector before the two clips;
// (2) hkVector4Util::convertToUint16WithClip adds a magic that is a plain static of the file (four times 65536.0,
//     the game's data at 0x01060db0), lane by lane, where the SDK's header has a const float array that the
//     compiler folds into a constant. Being a static whose address is not taken, its loads leave the loop.
// Only the function carries the packet's name.
namespace f3m_00997130 {

typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
extern void* (__cdecl *hkSystemMalloc)(int size, int align);
extern void (__cdecl *hkSystemFree) (void* p);
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		void addReference();
		void removeReference();
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		__forceinline int getRow(int nbytes) const;
		void onRowFull(int row, void* p);
		void clearRow(int rowIndex);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
			FreeList() : m_head(0), m_numElem(0) {}
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
				fl->m_next = m_head;
				m_head = fl;
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
					m_head = m_head->m_next;
					return p;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
		__forceinline hkBaseObject() { }
		__forceinline hkBaseObject( class hkFinishLoadedObjectFlag flag ) {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkReferencedObject();
		__forceinline hkReferencedObject( const hkReferencedObject& originalObject );
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline void removeReference() const;
		__forceinline int getReferenceCount() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
	public:
		hkReferencedObject( class hkFinishLoadedObjectFlag flag ) : m_referenceCount(1) {}
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
		hkArray(const hkArray& a);
	public:
		hkArray& operator= (const hkArray& a);
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		__forceinline T* expandBy( int n );
		__forceinline T* expandByUnchecked( int n );
		__forceinline T* expandAt( int index, int numToInsert );
		void insertAt(int i, const T* p, int numElems );
		void insertAt(int i, const T& t);
        __forceinline int getCapacityAndFlags() const;
	public:
		enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
	protected:
		friend class hkStatisticsCollector;
		void releaseMemory();
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::_reserve(this, newSize, sizeof(T));
	}
}
template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T>
__forceinline T* hkArray<T>::expandBy( int n )
{
	int oldsize = m_size;
	setSize( oldsize + n );
	return m_data+oldsize;
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void setInt24W( int value );
		__forceinline int getInt24W( ) const ;
		__forceinline void storeUncached( void* dest) const;
		__forceinline void add4(const hkVector4& a);
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		void setMul3(const hkMatrix3& a, const hkVector4& b );
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void setRotatedDir(const hkQuaternion& q, const hkVector4& b);
		__forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal fastNormalizeWithLength3();
		__forceinline void fastNormalize3NonZero();
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
		__forceinline void setXYZ(const hkVector4& v);
		__forceinline void setXYZ0(const hkVector4& xyz);
		__forceinline void setReciprocal4(const hkVector4& v);
		__forceinline void setReciprocal3(const hkVector4& v);
		__forceinline void setSqrtInverse4(const hkVector4& v);
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void broadcast(int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline void setBroadcast3clobberW(hkVector4Parameter v, int i);
		__forceinline	int getMajorAxis() const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
		hkBool isOk3() const;
		void store4a(hkReal* p) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
	public:
		void add( const hkMatrix3& a );
		__forceinline void _add( const hkMatrix3& a );
		void sub( const hkMatrix3& a );
		__forceinline void _sub( const hkMatrix3& a );
		void mul( const hkMatrix3& a);
		void mul( hkSimdRealParameter scale );
		inline void operator= ( const hkMatrix3& a );
		hkBool isOk() const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
}
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
struct hkAabbUint32
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline void operator=( const hkAabbUint32& other );
	inline void setInvalid();
	inline void setInvalidY();
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkUint32 m_id;
		hkpBroadPhaseHandle(): m_id(0){}
	public:
		hkpBroadPhaseHandle( class hkFinishLoadedObjectFlag flag ){}
};
class hkMultiThreadCheck
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		__forceinline hkMultiThreadCheck();
		__forceinline void init();
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		static void staticQuit();
	protected:
		void markForReadImpl(ReadMode mode  );
		void markForWriteImpl( );
		bool isMarkedForWriteImpl( );
		void unmarkForReadImpl( );
		void unmarkForWriteImpl();
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
};
class hkpBroadPhaseHandlePair;
class hkpBroadPhaseCastCollector;
typedef char hkpBroadPhaseAabbCache;
class hkpBroadPhase: public hkReferencedObject
{
	public:
		hkpBroadPhase();
		~hkpBroadPhase();
		enum BroadPhaseType
		{
			BROADPHASE_16BIT,
			BROADPHASE_32BIT
		};
		virtual BroadPhaseType getType() const = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void FUN_00997130( hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray< hkAabb >& addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs ) = 0;
		virtual void removeObject( hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairsOut ) = 0;
		virtual void removeObjectBatch( hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut ) = 0;
		virtual int getNumObjects() = 0;
		virtual void updateAabbs( hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void updateAabbsUint32( hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void defragment() = 0;
		virtual void getAllAabbs( hkArray<hkAabb>& allAabbs ) const = 0;
		virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const = 0;
		virtual void getExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const = 0;
		virtual void querySingleAabb( const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void reQuerySingleObject( const hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void shiftAllObjects( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void shiftBroadPhase( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void getOffsetLowHigh32bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const = 0;
		struct hkpCastRayInput
		{
			hkVector4		m_from;
			int       m_numCasts;
			const hkVector4* m_toBase;
			int		  m_toStriding;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastRayInput(): m_numCasts(1), m_toStriding( int(sizeof(hkVector4))),m_aabbCacheInfo(0){}
		};
		virtual	void castRay( const hkpCastRayInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const = 0;
		virtual int getAabbCacheSize() const = 0;
		virtual void calcAabbCache( const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		virtual void calcAabbCache( const hkArray<class hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		struct hkpCastAabbInput
		{
			hkVector4 m_from;
			hkVector4 m_to;
			hkVector4 m_halfExtents;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastAabbInput(): m_aabbCacheInfo(0){}
		};
		virtual void castAabb( const hkpCastAabbInput& input, hkpBroadPhaseCastCollector& collector ) const = 0;
		virtual void set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale) = 0;
		void enableMultiThreading( int spinCountForCriticalSection);
		inline hkMultiThreadCheck& getMultiThreadCheck();
		inline const hkMultiThreadCheck& getMultiThreadCheck() const;
		__forceinline void markForRead() const;
	protected:
		mutable hkMultiThreadCheck m_multiThreadCheck;
		class hkCriticalSection *m_criticalSection;
};
union hkIntUnion64
{
	hkQuadReal quad;
	hkInt64 i64;
	hkUint64 u64;
	hkInt32 i32[2];
	hkUint32 u32[2];
	hkInt16 i16[4];
	hkUint16 u16[4];
	hkInt8 i8[8];
	hkUint8 u8[8];
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out);
}
namespace hkAlgorithm
{
template<typename T>
	class less
	{
		public:
			__forceinline hkBool operator() ( const T& a, const T& b )
			{
				return ( a < b );
			}
	};
template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}
namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}
static hkQuadReal convertToUint16WithClipMagic = {65536.0f,65536.0f,65536.0f,65536.0f};
inline void __cdecl hkVector4Util::convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	x(0) += convertToUint16WithClipMagic.x;
	x(1) += convertToUint16WithClipMagic.y;
	x(2) += convertToUint16WithClipMagic.z;
	x(3) += convertToUint16WithClipMagic.w;
	union
	{
		hkQuadReal q;
		hkUint32 i[4];
	} u;
	u.q = x.getQuad();
	out.i16[0] = hkInt16(u.i[0] >> 7);
	out.i16[1] = hkInt16(u.i[1] >> 7);
	out.i16[2] = hkInt16(u.i[2] >> 7);
	out.i16[3] = hkInt16(u.i[3] >> 7);
}
static inline void memclear16( void* dest, int bytesize )
{
	hkVector4 val; val.setZero4();
	hkVector4* d = (hkVector4*)dest;
	bytesize = bytesize >> 4;
	while ( bytesize >= 0 )
	{
		*(d++) = val;
		bytesize--;
	}
}
static __forceinline void toggleBit( int index, hkUint32* bitField )
{
	int word = index >> 5;
	hkUint32 mask = 1 << ( index & 31 );
	bitField[word] ^= mask;
}
class hkp3AxisSweep : public hkpBroadPhase
{
	public:
		typedef hkUint16 BpInt;
		class hkpBpNode
		{
			public:
				BpInt min_y;
				BpInt min_z;
				BpInt max_y;
				BpInt max_z;
				BpInt min_x;
				BpInt max_x;
				hkpBroadPhaseHandle* m_handle;
		};
		class hkpBpEndPoint
		{
			public:
				__forceinline hkBool operator<( const hkpBpEndPoint& b ) const { return m_value < b.m_value; }
				BpInt m_value;
				BpInt m_nodeIndex;
		};
		class hkpBpAxis
		{
			public:
				void mergeBatch( hkpBpNode* nodes, int oldSize, int numNew, int axisIndex, hkpBpEndPoint* scratch );
				hkArray<hkpBpEndPoint> m_endPoints;
		};
		class hkpBpMarker
		{
			public:
				BpInt m_nodeIndex;
				BpInt m_value;
				hkArray<BpInt> m_overlappingObjects;
		};
		virtual void FUN_00997130( hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray<hkAabb>& addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs );
		__forceinline void _convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const;
		static __forceinline void __cdecl _convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
	protected:
		void queryBatchAabbSub( hkUint32* bitField, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addOrRemove ) const;
	public:
		static __declspec(align(16)) hkUint32 OneMask[4];
		static __declspec(align(16)) hkReal MaxVal[4];
		hkAabb m_aabb;
		hkVector4 m_offsetLow;
		hkVector4 m_offsetHigh;
		hkVector4 m_scale;
		hkVector4 m_offsetLow32bit;
		hkVector4 m_offsetHigh32bit;
		hkVector4 m_scale32bit;
		hkArray<hkpBpNode> m_nodes;
		hkpBpAxis m_axis[3];
		int m_numMarkers;
		int m_ld2NumMarkers;
		hkpBpMarker* m_markers;
		hkReal m_intToFloatFloorCorrection;
};
__forceinline void __cdecl hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	hkVector4 zero; zero.setZero4();
	hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&MaxVal));
	hkIntUnion64 mi;
	hkIntUnion64 ma;
	hkVector4Util::convertToUint16WithClip( aabb.m_min, offsetLow, scale, zero, maxVal, mi );
	hkVector4Util::convertToUint16WithClip( aabb.m_max, offsetHigh, scale, zero, maxVal, ma );
	aabbOut.m_min[0] = mi.u16[0] & 0xfffe;
	aabbOut.m_min[1] = mi.u16[1] & 0xfffe;
	aabbOut.m_min[2] = mi.u16[2] & 0xfffe;
	aabbOut.m_max[0] = ma.u16[0] | 1;
	aabbOut.m_max[1] = ma.u16[1] | 1;
	aabbOut.m_max[2] = ma.u16[2] | 1;
}
__forceinline void hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const
{
	_convertAabbToInt( aabb, m_offsetLow, m_offsetHigh, m_scale, aabbOut );
}
void hkp3AxisSweep::FUN_00997130(hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray<hkAabb>& addAabbList,
    hkArray<hkpBroadPhaseHandlePair>& newPairs)
{
    if (addAabbList.getSize() < 1)
    {
        return;
    }
    int newIdx = m_nodes.getSize();
    int numNew = addObjectList.getSize();
    m_nodes.expandBy(numNew);
    {
        int oldSize[3];
        oldSize[0] = m_axis[0].m_endPoints.getSize();
        oldSize[1] = m_axis[1].m_endPoints.getSize();
        oldSize[2] = m_axis[2].m_endPoints.getSize();
        hkpBpEndPoint* newEps[3];
        newEps[0] = m_axis[0].m_endPoints.expandBy(numNew * 2);
        newEps[1] = m_axis[1].m_endPoints.expandBy(numNew * 2);
        newEps[2] = m_axis[2].m_endPoints.expandBy(numNew * 2);
        hkpBpNode* nodes;
        int i;
        for (i = 0; i < numNew; i++)
        {
            hkAabbUint32 aabb;
            _convertAabbToInt(addAabbList[i], aabb);
            int nodeIdx = newIdx + i;
            hkpBpNode& node = m_nodes[nodeIdx];
            hkpBroadPhaseHandle* object = addObjectList[i];
            node.m_handle = object;
            object->m_id = nodeIdx;
            newEps[0][i + i].m_value = (unsigned short)aabb.m_min[0];
            newEps[0][i + i].m_nodeIndex = (unsigned short)nodeIdx;
            newEps[0][i + i + 1].m_value = (unsigned short)aabb.m_max[0];
            newEps[0][i + i + 1].m_nodeIndex = (unsigned short)nodeIdx;
            newEps[1][i + i].m_value = (unsigned short)aabb.m_min[1];
            newEps[1][i + i].m_nodeIndex = (unsigned short)nodeIdx;
            newEps[1][i + i + 1].m_value = (unsigned short)aabb.m_max[1];
            newEps[1][i + i + 1].m_nodeIndex = (unsigned short)nodeIdx;
            newEps[2][i + i].m_value = (unsigned short)aabb.m_min[2];
            newEps[2][i + i].m_nodeIndex = (unsigned short)nodeIdx;
            newEps[2][i + i + 1].m_value = (unsigned short)aabb.m_max[2];
            newEps[2][i + i + 1].m_nodeIndex = (unsigned short)nodeIdx;
        }
        nodes = &m_nodes[0];
        for (int a = 0; a < 3; a++)
        {
            hkAlgorithm::quickSort(newEps[a], numNew * 2);
        }
        {
            hkpBpEndPoint* scratch = hkAllocateStack<hkpBpEndPoint>(oldSize[0]);
            for (int a = 0; a < 3; a++)
            {
                m_axis[a].mergeBatch(nodes, oldSize[a], numNew * 2, a, scratch);
            }
            hkDeallocateStack(scratch);
        }
        if (m_numMarkers)
        {
            int numNewEndPoints = numNew * 2;
            for (int im = 0; im < m_numMarkers; im++)
            {
                hkpBpMarker& m = m_markers[im];
                hkpBpNode& n = m_nodes[m.m_nodeIndex];
                n.max_y = (unsigned short)(n.max_y + numNewEndPoints);
                n.max_z = (unsigned short)(n.max_z + numNewEndPoints);
            }
        }
    }
    {
        int numBits = m_nodes.getSize();
        int numBytes = numBits >> 3;
        int numInts = (numBits >> 5) + 8;
        hkUint32* bitFieldOfQueryNodes = hkAllocateStack<hkUint32>(numInts);
        memclear16(bitFieldOfQueryNodes, numBytes);
        for (int i = 0; i < numNew; i++)
        {
            toggleBit(newIdx + i, bitFieldOfQueryNodes);
        }
        queryBatchAabbSub(bitFieldOfQueryNodes, newPairs, true);
        hkDeallocateStack(bitFieldOfQueryNodes);
    }
}

}  // namespace f3m_00997130

// @f3 0x009925d0 (community match, verified in this file)
// 0x009925d0: hkp3AxisSweep::querySingleAabbWithCollector(const hkAabb& aabbIn, hkpBroadPhaseCastCollector*
// collector) const of Havok 5.5.0 (hkpInternal, hkp3AxisSweep.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Reports every object whose box overlaps the query box to the collector: a bit field over the nodes on the
// thread's stack block, the query box converted to the 16-bit grid, the bits of the nodes whose x interval
// overlaps set by a sweep along the x axis (started at a marker when there are markers), the y and z index
// ranges of the query box found by a search on the two other axes, then every set bit's node tested on y and z
// and reported. The body is the file's force-inlined _querySingleAabb with the collector query type.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by a reducer, then whole unused lines, every cut checked byte for byte); those declarations are the
// SDK's text with its names. hkp3AxisSweep itself is a class of the hkpInternal library that no SDK header ships:
// it is declared from the library's debug records (base class, data members, nested types, the methods used).
// The body follows the library's records (the debug build's _querySingleAabb with its named locals and line
// table, the hybrid object of this function); written with the SDK's own helpers it compiles to the SDK's
// release object (1,581 bytes). The game's build differs from that object in the inlined AABB conversion only,
// and so does this file:
// (1) hkp3AxisSweep::_convertAabbToInt copies MaxVal into a local vector before the two clips;
// (2) hkVector4Util::convertToUint16WithClip adds a magic that is a plain static of the file (four times 65536.0,
//     the game's data at 0x01060db0), lane by lane, where the SDK's header has a const float array that the
//     compiler folds into a constant.
// hkp3AxisSweep::hkpBpAxis::find, the game's function at 0x00990ea0 (82 bytes), is defined here with its body
// under the name FUN_00990ea0, as it stands before this function in the SDK's file: with the body in sight the
// compiler orders the loads before the first search as the original does. It is marked inline only so that it
// is a section of its own in the object (the SDK's flags have no /Gy) and the checker can bind the four calls;
// the compiler still calls it, and neither function's bytes change. Besides it only querySingleAabbWithCollector
// is renamed, to the packet's name.
namespace f3m_009925d0 {

typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;
class hkBool
{
	public:
		inline hkBool()
		{
		}
		inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
		inline operator bool() const
		{
		}
		inline hkBool operator!=(bool e) const
		{
			return static_cast<int>(m_bool) != static_cast<int>(e);
		}
	private:
		char m_bool;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
			public:
				hkThreadLocalData() { m_slotID =  TlsAlloc(); }
				~hkThreadLocalData() { TlsFree(m_slotID); }
				__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
				unsigned long m_slotID;
		};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
		virtual void releaseCachedMemory();
		__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
	protected:
		virtual void* onStackOverflow(int nbytes);
		virtual void onStackUnderflow(void* p);
	public:
		enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
		struct Stack
		{
			Stack()
				:	m_current(0),
					m_prev(0),
					m_base((char*)-1),
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
			}
			void* get()
			{
				if(void* p = m_head)
				{
					m_numElem -= 1;
				}
				return 0;
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
		int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
		char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
		int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
	public:
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
		virtual ~hkReferencedObject() { }
		__forceinline void addReference() const;
		__forceinline int getAllocatedSize() const;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const;
        virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
	public:
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};
namespace hkArrayUtil
{
void __cdecl _reserve(void*, int numElem, int sizeElem);
void __cdecl _reserveMore(void* array, int sizeElem);
void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
	public:
		__forceinline const T& operator[] (int i) const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
		__forceinline const_iterator begin() const;
		__forceinline const_iterator end() const;
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	public:
		hkArray(hkFinishLoadedObjectFlag f) { }
};
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::end() const
{
	return m_data + m_size;
}
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void operator= ( const hkQuadReal& v );
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void add3clobberW(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkMatrix3
{
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
}
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb
{
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
struct hkAabbUint32
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline void operator=( const hkAabbUint32& other );
	inline void setInvalid();
	inline void setInvalidY();
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
class hkMultiThreadCheck
{
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
		__forceinline void markForRead( ReadMode mode = RECURSIVE )
		{
			;
		}
		__forceinline void markForWrite( )
		{
			;
		}
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
};
class hkpBroadPhaseHandle;
class hkpBroadPhaseHandlePair;
class hkpBroadPhaseCastCollector;
typedef char hkpBroadPhaseAabbCache;
class hkpBroadPhase: public hkReferencedObject
{
	public:
		enum BroadPhaseType
		{
			BROADPHASE_16BIT,
			BROADPHASE_32BIT
		};
		virtual BroadPhaseType getType() const = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObjectBatch( hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray< hkAabb >& addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs ) = 0;
		virtual void removeObject( hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairsOut ) = 0;
		virtual void removeObjectBatch( hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut ) = 0;
		virtual int getNumObjects() = 0;
		virtual void updateAabbs( hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void updateAabbsUint32( hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void defragment() = 0;
		virtual void getAllAabbs( hkArray<hkAabb>& allAabbs ) const = 0;
		virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const = 0;
		virtual void getExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const = 0;
		virtual void querySingleAabb( const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void reQuerySingleObject( const hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void shiftAllObjects( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void shiftBroadPhase( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void getOffsetLowHigh32bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const = 0;
		struct hkpCastRayInput
		{
			hkVector4		m_from;
			int       m_numCasts;
			const hkVector4* m_toBase;
			int		  m_toStriding;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastRayInput(): m_numCasts(1), m_toStriding( int(sizeof(hkVector4))),m_aabbCacheInfo(0){}
		};
		virtual	void castRay( const hkpCastRayInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const = 0;
		virtual int getAabbCacheSize() const = 0;
		virtual void calcAabbCache( const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		virtual void calcAabbCache( const hkArray<class hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		struct hkpCastAabbInput
		{
			hkVector4 m_from;
			hkVector4 m_to;
			hkVector4 m_halfExtents;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
			hkpCastAabbInput(): m_aabbCacheInfo(0){}
		};
		virtual void castAabb( const hkpCastAabbInput& input, hkpBroadPhaseCastCollector& collector ) const = 0;
		virtual void set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale) = 0;
		void enableMultiThreading( int spinCountForCriticalSection);
	protected:
		void lockImplementation();
		void unlockImplementation();
	protected:
		mutable hkMultiThreadCheck m_multiThreadCheck;
		class hkCriticalSection *m_criticalSection;
};
class hkpBroadPhaseHandlePair
{
	public:
		hkpBroadPhaseHandle* m_a;
		hkpBroadPhaseHandle* m_b;
};
class hkpBroadPhaseCastCollector
{
	public:
		virtual ~hkpBroadPhaseCastCollector() { }
		virtual	hkReal addBroadPhaseHandle( const hkpBroadPhaseHandle* broadphaseHandle, int castIndex ) = 0;
};
union hkIntUnion64
{
	hkQuadReal quad;
	hkInt64 i64;
	hkUint64 u64;
	hkInt32 i32[2];
	hkUint32 u32[2];
	hkInt16 i16[4];
	hkUint16 u16[4];
	hkInt8 i8[8];
	hkUint8 u8[8];
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out);
}
static hkQuadReal convertToUint16WithClipMagic = {65536.0f,65536.0f,65536.0f,65536.0f};
inline void __cdecl hkVector4Util::convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	x(0) += convertToUint16WithClipMagic.x;
	x(1) += convertToUint16WithClipMagic.y;
	x(2) += convertToUint16WithClipMagic.z;
	x(3) += convertToUint16WithClipMagic.w;
	union
	{
		hkQuadReal q;
		hkUint32 i[4];
	} u;
	u.q = x.getQuad();
	out.i16[0] = hkInt16(u.i[0] >> 7);
	out.i16[1] = hkInt16(u.i[1] >> 7);
	out.i16[2] = hkInt16(u.i[2] >> 7);
	out.i16[3] = hkInt16(u.i[3] >> 7);
}
static inline void memclear16( void* dest, int bytesize )
{
	hkVector4 val; val.setZero4();
	hkVector4* d = (hkVector4*)dest;
	bytesize = bytesize >> 4;
	while ( bytesize >= 0 )
	{
		*(d++) = val;
		bytesize--;
	}
}
static __forceinline void toggleBit( int index, hkUint32* bitField )
{
	int word = index >> 5;
	hkUint32 mask = 1 << ( index & 31 );
	bitField[word] ^= mask;
}
static __forceinline void clearBit( int index, hkUint32* bitField )
{
	int word = index >> 5;
	hkUint32 mask = 1 << ( index & 31 );
	bitField[word] &= ~mask;
}
class hkp3AxisSweep : public hkpBroadPhase
{
	public:
		typedef hkUint16 BpInt;
		class hkpBpNode
		{
			public:
				__forceinline int isMarker() const { return int( hkUlong( m_handle ) ) & 1; }
				__forceinline hkUint32 yzDisjoint( const hkpBpNode& other ) const
				{
					hkUint32 maxA = *reinterpret_cast<const hkUint32*>( &max_y );
					hkUint32 minB = *reinterpret_cast<const hkUint32*>( &other.min_y );
					hkUint32 maxB = *reinterpret_cast<const hkUint32*>( &other.max_y );
					hkUint32 minA = *reinterpret_cast<const hkUint32*>( &min_y );
					maxA -= minB;
					maxB -= minA;
					return ( maxA | maxB ) & 0x80008000;
				}
				BpInt min_y;
				BpInt min_z;
				BpInt max_y;
				BpInt max_z;
				BpInt min_x;
				BpInt max_x;
				hkpBroadPhaseHandle* m_handle;
		};
		class hkpBpEndPoint
		{
			public:
				__forceinline int isMaxPoint() const { return m_value & 1; }
				BpInt m_value;
				BpInt m_nodeIndex;
		};
		class hkpBpAxis
		{
			public:
				const hkpBpEndPoint* FUN_00990ea0( const hkpBpEndPoint* start, const hkpBpEndPoint* end, BpInt value ) const;
				hkArray<hkpBpEndPoint> m_endPoints;
		};
		class hkpBpMarker
		{
			public:
				BpInt m_nodeIndex;
				BpInt m_value;
				hkArray<BpInt> m_overlappingObjects;
		};
		enum hkpBpQuerySingleType
		{
			HK_BP_REPORT_HANDLES,
			HK_BP_REPORT_NODES,
			HK_BP_REPORT_COLLECTOR
		};
		virtual void FUN_009925d0( const hkAabb& aabbIn, hkpBroadPhaseCastCollector* collector ) const;
		__forceinline void _convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const;
		static __forceinline void __cdecl _convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
	protected:
		__forceinline void querySingleAabbSub( hkpBroadPhaseHandle* object, const hkUint32* bitField, hkpBpNode& refNode, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const;
		__forceinline void _querySingleAabb( const hkAabb& aabbIn, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const;
	public:
		static __declspec(align(16)) hkUint32 OneMask[4];
		static __declspec(align(16)) hkReal MaxVal[4];
		hkAabb m_aabb;
		hkVector4 m_offsetLow;
		hkVector4 m_offsetHigh;
		hkVector4 m_scale;
		hkVector4 m_offsetLow32bit;
		hkVector4 m_offsetHigh32bit;
		hkVector4 m_scale32bit;
		hkArray<hkpBpNode> m_nodes;
		hkpBpAxis m_axis[3];
		int m_numMarkers;
		int m_ld2NumMarkers;
		hkpBpMarker* m_markers;
		hkReal m_intToFloatFloorCorrection;
};
inline const hkp3AxisSweep::hkpBpEndPoint* hkp3AxisSweep::hkpBpAxis::FUN_00990ea0( const hkpBpEndPoint* start, const hkpBpEndPoint* end, BpInt value ) const
{
	while ( end - start > 16 )
	{
		const hkpBpEndPoint* mid = start + ( ( end - start ) >> 1 );
		if ( mid->m_value < value )
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	while ( start->m_value < value )
	{
		start++;
	}
	return start;
}
__forceinline void __cdecl hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	hkVector4 zero; zero.setZero4();
	hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&MaxVal));
	hkIntUnion64 mi;
	hkIntUnion64 ma;
	hkVector4Util::convertToUint16WithClip( aabb.m_min, offsetLow, scale, zero, maxVal, mi );
	hkVector4Util::convertToUint16WithClip( aabb.m_max, offsetHigh, scale, zero, maxVal, ma );
	aabbOut.m_min[0] = mi.u16[0] & 0xfffe;
	aabbOut.m_min[1] = mi.u16[1] & 0xfffe;
	aabbOut.m_min[2] = mi.u16[2] & 0xfffe;
	aabbOut.m_max[0] = ma.u16[0] | 1;
	aabbOut.m_max[1] = ma.u16[1] | 1;
	aabbOut.m_max[2] = ma.u16[2] | 1;
}
__forceinline void hkp3AxisSweep::_convertAabbToInt( const hkAabb& aabb, hkAabbUint32& aabbOut ) const
{
	_convertAabbToInt( aabb, m_offsetLow, m_offsetHigh, m_scale, aabbOut );
}
__forceinline void hkp3AxisSweep::querySingleAabbSub( hkpBroadPhaseHandle* object, const hkUint32* bitField, hkpBpNode& refNode, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const
{
	const hkpBpNode* nodes = &m_nodes[0];
	const hkUint32* bitsEnd = bitField + ( m_nodes.getSize() >> 5 ) + 1;
	for ( ; bitField < bitsEnd; nodes += 32, bitField++ )
	{
		hkUint32 b = *bitField;
		if ( !b )
		{
			continue;
		}
		const hkpBpNode* n = nodes;
		do
		{
			if ( b & 0xf )
			{
				if ( ( b & 1 ) && !refNode.yzDisjoint( n[0] ) && !n[0].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						hkpBroadPhaseHandlePair pair;
						pair.m_a = object;
						pair.m_b = n[0].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[0] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[0].m_handle, 0 );
					}
				}
				if ( ( b & 2 ) && !refNode.yzDisjoint( n[1] ) && !n[1].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						hkpBroadPhaseHandlePair pair;
						pair.m_a = object;
						pair.m_b = n[1].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[1] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[1].m_handle, 0 );
					}
				}
				if ( ( b & 4 ) && !refNode.yzDisjoint( n[2] ) && !n[2].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						hkpBroadPhaseHandlePair pair;
						pair.m_a = object;
						pair.m_b = n[2].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[2] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[2].m_handle, 0 );
					}
				}
				if ( ( b & 8 ) && !refNode.yzDisjoint( n[3] ) && !n[3].isMarker() )
				{
					if ( type == HK_BP_REPORT_HANDLES )
					{
						hkpBroadPhaseHandlePair pair;
						pair.m_a = object;
						pair.m_b = n[3].m_handle;
						pairs_out->pushBack( pair );
					}
					else if ( type == HK_BP_REPORT_NODES )
					{
						nodesOut->pushBackUnchecked( &n[3] );
					}
					else
					{
						collector->addBroadPhaseHandle( n[3].m_handle, 0 );
					}
				}
			}
			n += 4;
		}
		while ( b >>= 4 );
	}
}
__forceinline void hkp3AxisSweep::_querySingleAabb( const hkAabb& aabbIn, hkpBpQuerySingleType type, hkArray<hkpBroadPhaseHandlePair>* pairs_out, hkArray<const hkpBpNode*>* nodesOut, hkpBroadPhaseCastCollector* collector ) const
{
	int numNodes = m_nodes.getSize();
	hkUint32* bitField = hkAllocateStack<hkUint32>( ( numNodes >> 5 ) + 8 );
	memclear16( bitField, numNodes >> 3 );
	hkAabbUint32 aabb;
	_convertAabbToInt( aabbIn, aabb );
	const hkpBpEndPoint* ep = &m_axis[0].m_endPoints[1];
	if ( m_numMarkers )
	{
		int xValue = aabb.m_min[0];
		int pos = xValue >> ( 16 - m_ld2NumMarkers );
		if ( pos > 0 )
		{
			hkpBpMarker* m = &m_markers[pos - 1];
			toggleBit( m->m_nodeIndex, bitField );
			BpInt* o = m->m_overlappingObjects.begin();
			for ( int k = m->m_overlappingObjects.getSize() - 1; k >= 0; k-- )
			{
				toggleBit( *o, bitField );
				o++;
			}
			const hkpBpNode& markerNode = m_nodes[m->m_nodeIndex];
			ep = &m_axis[0].m_endPoints[markerNode.min_x + 1];
			const hkpBpEndPoint* end = &m_axis[0].m_endPoints[markerNode.max_x];
			for ( ; ep < end; ep++ )
			{
				if ( !ep->isMaxPoint() )
				{
					clearBit( ep->m_nodeIndex, bitField );
				}
			}
			ep = &m_axis[0].m_endPoints[markerNode.min_x + 1];
		}
	}
	while ( ep->m_value < aabb.m_min[0] )
	{
		toggleBit( ep->m_nodeIndex, bitField );
		ep++;
	}
	while ( ep->m_value < aabb.m_max[0] )
	{
		if ( !ep->isMaxPoint() )
		{
			toggleBit( ep->m_nodeIndex, bitField );
		}
		ep++;
	}
	hkpBpNode refNode;
	{
		const hkpBpAxis& axis = m_axis[1];
		const hkpBpEndPoint* start = &axis.m_endPoints[0];
		const hkpBpEndPoint* end = axis.m_endPoints.end() - 2;
		refNode.min_y = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_min[1] ) ) - start );
		refNode.max_y = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_max[1] ) ) - ( start + 1 ) );
	}
	{
		const hkpBpAxis& axis = m_axis[2];
		const hkpBpEndPoint* start = &axis.m_endPoints[0];
		const hkpBpEndPoint* end = axis.m_endPoints.end() - 2;
		refNode.min_z = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_min[2] ) ) - start );
		refNode.max_z = BpInt( axis.FUN_00990ea0( start + 1, end, BpInt( aabb.m_max[2] ) ) - ( start + 1 ) );
	}
	querySingleAabbSub( 0, bitField, refNode, type, pairs_out, nodesOut, collector );
	hkDeallocateStack( bitField );
}
void hkp3AxisSweep::FUN_009925d0( const hkAabb& aabbIn, hkpBroadPhaseCastCollector* collector ) const
{
	_querySingleAabb( aabbIn, HK_BP_REPORT_COLLECTOR, 0, 0, collector );
}

}  // namespace f3m_009925d0

// @f3 0x00983680 (community match, verified in this file)
// 0x00983680 = Havok 5.5.0 hkpWorldOperationQueue::executeAllPending (hkpDynamics.lib, hkpWorldOperationQueue.obj), the game's revision.
// SDK-form source w2\sdk.cpp (reconstructed from the library's debug records; MATCH against the library), cut with tools\hktrim.py.
// Game revision: island merges run before the loop, no ISLAND_MERGE case, hkThreadMemory::onRowFull takes the memory class.
namespace f3m_00983680 {
typedef float hkReal;
typedef signed char hkInt8;
typedef signed short	hkInt16;
typedef signed int hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __int64 hkUint64;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
class hkClass;
class hkBool {
public:
	inline hkBool(bool b) {
		m_bool = static_cast<char>(b);
	}
	inline operator bool() const {
		return m_bool != 0;
	}
private:
	char m_bool;
};
class hkHalf {
private:
	hkInt16 m_value;
};
class hkUFloat8 {
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum {
public:
	operator ENUM() const {
		return static_cast<ENUM>(m_storage);
	}
private:
	STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu {
private:
	TYPE m_storage;
};
extern "C" {
	__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
class hkThreadLocalData {
public:
	__forceinline T getData() const {
		return (T)(hkUlong)TlsGetValue(m_slotID) ;
	}
	unsigned long m_slotID;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT, HK_MEMORY_CLASS_BASE, HK_MEMORY_CLASS_COLLIDE, HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS, HK_MEMORY_CLASS_EXPORT, HK_MEMORY_CLASS_SERIALIZE, HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY, HK_MEMORY_CLASS_MATH, HK_MEMORY_CLASS_SCENE_DATA, HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION, HK_MEMORY_CLASS_UTILITIES, HK_MEMORY_CLASS_ANIMATION, HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH, HK_MEMORY_CLASS_TOOLS, HK_MEMORY_CLASS_DEMO_FRAMEWORK, HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER, HK_MEMORY_CLASS_BASE_CLASS, HK_MEMORY_CLASS_STRING, HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON, HK_MEMORY_CLASS_SCRATCHPAD, HK_MEMORY_CLASS_STREAM, HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP, HK_MEMORY_CLASS_TREE, HK_MEMORY_CLASS_HKCLASS, HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM, HK_MEMORY_CLASS_BROAD_PHASE, HK_MEMORY_CLASS_CONTACT, HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD, HK_MEMORY_CLASS_SHAPE, HK_MEMORY_CLASS_COLLIDABLE, HK_MEMORY_CLASS_CDINFO
};
class hkMemory;
class hkThreadMemory {
public:
	void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
	__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
	virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
	virtual void alignedDeallocate(void* ptr);
	virtual void setStackArea(void* buf, int nbytes);
	static inline hkThreadMemory* __cdecl getInstancePtr();
	static inline hkThreadMemory& __cdecl getInstance();
	virtual void releaseCachedMemory();
	__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
protected:
	virtual void* onStackOverflow(int nbytes);
	virtual void onStackUnderflow(void* p);
public:
	enum {
		PAGE_ALIGN = 64, MEMORY_MAX_SMALL_ROW = 13, MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
		MEMORY_MAX_SIZE_SMALL_BLOCK = 512, MEMORY_MAX_SIZE_LARGE_BLOCK = 8192, MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
		MEMORY_SYSTEM_PAGE_SIZE = 8192, MEMORY_MAGIC_NUMBER = 0x3425234
	};
	struct Stack {
		__declspec(align(16)) char* m_current;
		Stack* m_prev;
		char* m_base;
		char* m_end;
	};
	static __forceinline int __cdecl constSizeToRow( int size );
protected:
	enum { BATCH_SIZE=4 };
	void onRowFull(int row, void* p, HK_MEMORY_CLASS cl);
public:
	hkMemory* m_memory;
	int m_referenceCount;
	Stack m_stack;
	int m_stackSize;
	int m_maxNumElemsOnFreeList;
	struct FreeList {
		enum { MAX_FREELIST=0x0fffffff };
		void put( void* p ) {
			m_numElem += 1;
			FreeElem* fl = static_cast<FreeElem*>(p);
			fl->m_next = m_head;
			m_head = fl;
		}
		struct FreeElem	{ FreeElem* m_next; };
		FreeElem* m_head;
		int m_numElem;
	};
	FreeList m_free_list[MEMORY_MAX_ALL_ROW];
	int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
	char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
	int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr() {
	extern hkThreadLocalData<hkThreadMemory*> hkThreadMemory__s_threadMemoryInstance;
	return hkThreadMemory__s_threadMemoryInstance.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance() {
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateChunk(TYPE* ptr, int numberOfObjects, HK_MEMORY_CLASS cl) {
	hkThreadMemory::getInstance().deallocateChunk(static_cast<void*>(ptr), numberOfObjects*int(sizeof(TYPE)), cl);
}
class hkBaseObject {
public:
	__forceinline virtual ~hkBaseObject() {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject {
public:
	virtual ~hkReferencedObject() { }
	__forceinline void removeReference() const;
	virtual void calcStatistics( hkStatisticsCollector* collector ) const;
	virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
public:
	enum {
		MASK_MEMSIZE = 0x7fff
	};
	hkUint16 m_memSizeAndFlags;
	mutable hkInt16 m_referenceCount;
};
__forceinline void hkReferencedObject::removeReference() const {
	if ( m_memSizeAndFlags != 0 ) {
		--m_referenceCount;
		if ( m_referenceCount == 0 ) {
			delete this;
		}
	}
}
namespace hkArrayUtil {
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T> class hkObjectArray;
template <typename T>
class hkArray {
	friend void __cdecl hkArrayUtil::_reserve(void*, int numElem, int sizeElem);
	friend void __cdecl hkArrayUtil::_reserveMore(void* array, int sizeElem);
	friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
	friend class hkObjectArray< hkArray<T> >;
	friend class hkArraySpu;
public:
	__forceinline hkArray();
public:
	__forceinline ~hkArray();
	__forceinline T& operator[] (int i);
	__forceinline T& back();
	__forceinline int getSize() const;
	__forceinline int getCapacity() const;
	__forceinline void clear();
	__forceinline void popBack( int numElemsToRemove = 1 );
	void swap(hkArray<T>& a);
	typedef T* iterator;
	typedef const T* const_iterator;
	__forceinline iterator begin();
public:
	enum {
		CAPACITY_MASK = int(0x3FFFFFFF), FLAG_MASK = int(0xC0000000), DONT_DEALLOCATE_FLAG = int(0x80000000),
		LOCKED_FLAG = int(0x40000000), FORCE_SIGNED = -1
	};
protected:
	friend class hkStatisticsCollector;
	void releaseMemory();
	T* m_data;
	int m_size;
	int m_capacityAndFlags;
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i) {
	return m_data[i];
}
template <typename T>
__forceinline T& hkArray<T>::back() {
	return m_data[ m_size - 1 ];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const {
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const {
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::clear() {
	m_size = 0;
}
template <typename T>
__forceinline hkArray<T>::hkArray()
:	m_data(0),
m_size(0),
m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory() {
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0) {
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray() {
	releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::popBack( int numRemove ) {
	m_size -= numRemove;
}
template <typename T>
void hkArray<T>::swap(hkArray<T>& a) {
	T* d = m_data;
	m_data = a.m_data;
	a.m_data = d;
	int s = m_size;
	m_size = a.m_size;
	a.m_size = s;
	int c = m_capacityAndFlags;
	m_capacityAndFlags = a.m_capacityAndFlags;
	a.m_capacityAndFlags = c;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin() {
	return m_data;
}
namespace hkSmallArrayUtil {
	void __cdecl _reserve(void*, int numElem, int sizeElem);
	void __cdecl _reserveMore(void* array, int sizeElem);
}
template <typename T>
class hkSmallArray {
	friend void __cdecl hkSmallArrayUtil::_reserve(void*, int numElem, int sizeElem);
	friend void __cdecl hkSmallArrayUtil::_reserveMore(void* array, int sizeElem);
public:
	typedef T* iterator;
	typedef const T* const_iterator;
public:
	enum {
		CAPACITY_MASK = hkUint16(0x3fff), FLAG_MASK = hkUint16(0xC000), DONT_DEALLOCATE_FLAG	= hkUint16(0x8000),
		LOCKED_FLAG = hkUint16(0x4000), FORCE_SIGNED = -1
	};
protected:
	friend class hkStatisticsCollector;
	T* m_data;
	hkUint16	m_size;
	hkUint16	m_capacityAndFlags;
};
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkVector4 {
public:
	__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
private:
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkQuaternion {
public:
public:
	hkVector4 m_vec;
};
class hkMatrix3 {
public:
protected:
	hkVector4 m_col0;
	hkVector4 m_col1;
	hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3 {
public:
};
class hkTransform {
public:
private:
	hkRotation m_rotation;
	hkVector4 m_translation;
};
class hkSweptTransform {
public:
public:
	hkVector4 m_centerOfMass0;
	hkVector4 m_centerOfMass1;
	hkQuaternion m_rotation0;
	hkQuaternion m_rotation1;
	hkVector4 m_centerOfMassLocal;
};
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d) {
	x = a;
	y = b;
	z = c;
	w = d;
}
int hkThreadMemory::constSizeToRow( int size ) {
	if (size <= 8 )	return 1;
	else if (size <= 16 )	return 2;
	else if (size <= 32 )	return 3;
	else if (size <= 48 )	return 4;
	else if (size <= 64 )	return 5;
	else if (size <= 96 )	return 6;
	else if (size <= 128 )	return 7;
	else if (size <= 160 )	return 8;
	else if (size <= 192 )	return 9;
	else if (size <= 256 )	return 10;
	else if (size <= 320 )	return 11;
	else if (size <= 512 )	return 12;
	else if (size <= 1024)	return 13;
	else if (size <= 2048)	return 14;
	else if (size <= 4096)	return 15;
	else if (size <= 8192)	return 16;
	else {
		return -1;
	}
}
void hkThreadMemory::deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl) {
	int row = constSizeToRow(nbytes);
	if ( m_free_list[row].m_numElem >= m_maxNumElemsOnFreeList ) {
		onRowFull(row, p, cl);
	}
	else {
		m_free_list[row].put(p);
	}
}
enum hkpShapeType {
	HK_SHAPE_INVALID = 0, HK_SHAPE_CONVEX, HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX, HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER, HK_SHAPE_TRIANGLE, HK_SHAPE_BOX, HK_SHAPE_CAPSULE, HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION, HK_SHAPE_BV_TREE, HK_SHAPE_LIST, HK_SHAPE_MOPP, HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM, HK_SHAPE_SAMPLED_HEIGHT_FIELD, HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0, HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES, HK_SHAPE_MOPP_EMBEDDED, HK_SHAPE_CONVEX_PIECE, HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST, HK_SHAPE_TRIANGLE_COLLECTION, HK_SHAPE_MULTI_RAY, HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP, HK_SHAPE_BV, HK_SHAPE_PLANE, HK_SHAPE_TRANSFORM, HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0, HK_SHAPE_USER1, HK_SHAPE_USER2, HK_SHAPE_MAX_ID, HK_SHAPE_ALL = -1
};
class hkpCollisionDispatcher;
class hkpCdVertex: public hkVector4 {
public:
};
class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum { HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject {
public:
	virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
	virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
	virtual const hkpShapeContainer* getContainer() const { return 0; }
	struct CalcSizeForSpuInput {
		bool m_midphaseAgent3Registered;
		bool m_isFixedOrKeyframed;
	};
	virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
protected:
	virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
	virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
public:
	typedef void (__cdecl *GetSupportingVertexFunc) (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
	typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
	typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
	typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
	typedef int (__cdecl *GetNumCollisionSpheresFunc) (const void* thisObj );
	typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
	typedef void (__cdecl *GetAabbFunc) (const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
	typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
	typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
	typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
	struct ShapeFuncs {
		hkPadSpu<GetSupportingVertexFunc> m_getSupportingVertexFunc;
		hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
		hkPadSpu<WeldContactPointFunc> m_weldContactPointFunc;
		hkPadSpu<GetCentreFunc> m_getCentreFunc;
		hkPadSpu<GetNumCollisionSpheresFunc> m_getNumCollisionSpheresFunc;
		hkPadSpu<GetCollisionSpheresFunc> m_getCollisionSpheresFunc;
		hkPadSpu<GetAabbFunc> m_getAabbFunc;
		hkPadSpu<CastRayFunc> m_castRay;
		hkPadSpu<GetChildShapeFunc> m_getChildShapeFunc;
		hkPadSpu<GetCollisionFilterInfoFunc> m_getCollisionFilterInfoFunc;
	};
	struct ShapeFuncs2 {
		__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
		ConvertVertexIdsToVerticesFunc m_convertVertexIdsToVertices;
		WeldContactPointFunc m_weldContactPointFunc;
		GetCentreFunc m_getCentreFunc;
		GetNumCollisionSpheresFunc m_getNumCollisionSpheresFunc;
		GetCollisionSpheresFunc m_getCollisionSpheresFunc;
		GetAabbFunc m_getAabbFunc;
		CastRayFunc m_castRay;
		GetChildShapeFunc m_getChildShapeFunc;
		GetCollisionFilterInfoFunc m_getCollisionFilterInfoFunc;
	};
public:
	hkUlong m_userData;
public:
	hkEnum< hkpShapeType, hkUint32> m_type;
};
class hkpCdBody {
public:
	friend class hkpCollidable;
public:
	const hkpShape* m_shape;
	hkpShapeKey m_shapeKey;
	const void* m_motion;
	const hkpCdBody* m_parent;
};
class hkpBroadPhaseHandle {
public:
	hkUint32 m_id;
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle {
public:
protected:
	enum { OFFSET_INVALID = 127 };
	friend class hkpBroadPhaseBorder;
	hkInt8 m_type;
	hkInt8 m_ownerOffset;
public:
	hkUint16 m_objectQualityType;
	hkUint32 m_collisionFilterInfo;
};
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody {
public:
public:
	struct BoundingVolumeData {
	public:
		hkUint32 m_min[3];
		hkUint8 m_expansionMin[3];
		hkUint8 m_expansionShift;
		hkUint32 m_max[3];
		hkUint8 m_expansionMax[3];
		hkUint8 m_padding;
		hkUint16 m_numChildShapeAabbs;
		hkAabbUint32*	m_childShapeAabbs;
	};
	enum ForceCollideOntoPpuReasons {
		FORCE_PPU_USER_REQUEST = 1, FORCE_PPU_SHAPE_REQUEST = 2, FORCE_PPU_MODIFIER_REQUEST = 4,
	};
protected:
	hkInt8 m_ownerOffset;
public:
	hkUint8 m_forceCollideOntoPpu;
	hkUint16 m_shapeSizeOnSpu;
	class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
public:
	struct BoundingVolumeData m_boundingVolumeData;
	hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable {
public:
public:
	struct CollisionEntry {
		hkpAgentNnEntry* m_agentEntry;
		hkpLinkedCollidable*	m_partner;
	};
	hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck {
public:
	enum AccessType {
		HK_ACCESS_IGNORE = 0, HK_ACCESS_RO = 1, HK_ACCESS_RW = 2,
	};
	enum ReadMode {
		THIS_OBJECT_ONLY, RECURSIVE
	};
public:
	enum {
		DISABLED = 0xffffffd1, MARKED_RO = 0xffffffe1, MARKED_RO_SELF_ONLY = 0xffffffc1, UNMARKED = 0xfffffff1
	};
	hkUint32 m_threadId;
	hkInt16 m_markCount;
protected:
	hkUint16 m_markBitStack;
public:
	static class hkCriticalSection* m_criticalSection;
};
class hkpWorld;
class hkpPhantom;
class hkpRigidBody;
namespace hkWorldOperation {
	enum Result {
		POSTPONED, DONE
	};
}
class hkpWorldObject : public hkReferencedObject {
public:
	inline hkpWorld* getWorld() const;
	void calcStatistics( hkStatisticsCollector* collector ) const;
	virtual hkWorldOperation::Result setShape( const hkpShape* shape );
	void removeReference();
public:
	enum BroadPhaseType {
		BROAD_PHASE_INVALID, BROAD_PHASE_ENTITY, BROAD_PHASE_PHANTOM, BROAD_PHASE_BORDER, BROAD_PHASE_MAX_ID
	};
protected:
	friend class hkpWorld;
	friend class hkpWorldOperationUtil;
	virtual class hkMotionState* getMotionState() = 0;
	inline virtual ~hkpWorldObject();
protected:
	hkpWorld* m_world;
	hkUlong m_userData;
protected:
	class hkpLinkedCollidable m_collidable;
protected:
	class hkMultiThreadCheck m_multiThreadCheck;
	const char* m_name;
	hkArray<class hkpProperty> m_properties;
};
inline hkpWorld* hkpWorldObject::getWorld() const {
	return m_world;
}
class hkpMaterial {
public:
	enum ResponseType {
		RESPONSE_INVALID, RESPONSE_SIMPLE_CONTACT, RESPONSE_REPORTING, RESPONSE_NONE, RESPONSE_MAX_ID
	};
private:
	hkEnum<ResponseType,hkInt8> m_responseType;
	hkReal m_friction;
	hkReal m_restitution;
};
struct hkpSolverInfo {
	enum DeactivationClass {
		DEACTIVATION_CLASS_INVALID, DEACTIVATION_CLASS_OFF, DEACTIVATION_CLASS_LOW, DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH, DEACTIVATION_CLASS_AGGRESSIVE, DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo {
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float m_tau;
	float m_damping;
	float m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float m_dampDivTau;
	float m_tauDivDamp;
	float m_dampDivFrictionTau;
	float m_frictionTauDivDamp;
	float m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float m_deltaTime;
	float m_invDeltaTime;
	int m_numSteps;
	int m_numMicroSteps;
	float m_invNumMicroSteps;
	float m_invNumSteps;
	hkBool m_forceCoherentConstraintOrderingInSolver;
	hkUint8 m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8 m_deactivationIntegrateCounter;
};
class hkpConstraintOwner;
class hkpEntity;
class hkpConstraintInstance : public hkReferencedObject {
public:
	enum ConstraintPriority {
		PRIORITY_INVALID, PRIORITY_PSI, PRIORITY_TOI, PRIORITY_TOI_HIGHER, PRIORITY_TOI_FORCED,
	};
	enum InstanceType {
		TYPE_NORMAL, TYPE_CHAIN
	};
	enum AddReferences {
		DO_NOT_ADD_REFERENCES, DO_ADD_REFERENCES
	};
	enum CloningMode {
		CLONE_INSTANCES_ONLY, CLONE_DATAS_WITH_MOTORS
	};
	~hkpConstraintInstance();
public:
	inline hkpEntity* getEntityA() const;
	inline hkpEntity* getEntityB() const;
public:
	inline hkpConstraintOwner* getOwner() const;
	virtual void entityAddedCallback(hkpEntity* entity);
	virtual void entityRemovedCallback(hkpEntity* entity);
	virtual void entityDeletedCallback( hkpEntity* entity );
	virtual InstanceType getType() const { return TYPE_NORMAL; }
protected:
	friend class hkpSimpleContactConstraintData;
	friend class hkpSimulationIsland;
	class hkpConstraintOwner* m_owner;
	class hkpConstraintData* m_data;
	struct hkpModifierConstraintAtom* m_constraintModifiers;
	class hkpEntity* m_entities[2];
public:
	hkEnum<ConstraintPriority,hkUint8> m_priority;
protected:
	hkBool m_wantRuntime;
	const char* m_name;
public:
	hkUlong m_userData;
	struct hkConstraintInternal* m_internal;
private:
	friend class hkpWorldConstraintUtil;
	friend class hkpSimpleConstraintContactMgr;
	friend class hkpSaveContactPointsUtil;
};
inline hkpEntity* hkpConstraintInstance::getEntityA() const {
	return m_entities[0];
}
inline hkpEntity* hkpConstraintInstance::getEntityB() const {
	return m_entities[1];
}
inline hkpConstraintOwner* hkpConstraintInstance::getOwner() const {
	return m_owner;
}
class hkMotionState {
public:
protected:
	hkTransform m_transform;
	class hkSweptTransform m_sweptTransform;
public:
	hkVector4 m_deltaAngle;
	hkReal m_objectRadius;
	hkReal	m_linearDamping;
	hkReal	m_angularDamping;
	hkUFloat8 m_maxLinearVelocity;
	hkUFloat8 m_maxAngularVelocity;
	hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject {
public:
	enum MotionType {
		MOTION_INVALID, MOTION_DYNAMIC, MOTION_SPHERE_INERTIA, MOTION_STABILIZED_SPHERE_INERTIA, MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA, MOTION_KEYFRAMED, MOTION_FIXED, MOTION_THIN_BOX_INERTIA, MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
	virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
	virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
	virtual void setPosition(const hkVector4& position);
	virtual void setRotation(const hkQuaternion& rotation);
	virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	virtual void setTransform(const hkTransform& transform);
	virtual void setLinearVelocity(const hkVector4& newVel);
	virtual void setAngularVelocity(const hkVector4& newVel);
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
	virtual void applyAngularImpulse(const hkVector4& imp) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
public:
	virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
public:
	enum { NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5 };
public:
	hkEnum<MotionType, hkUint8>	m_type;
	hkUint8 m_deactivationIntegrateCounter;
	hkUint16	m_deactivationNumInactiveFrames[2];
	class hkMotionState m_motionState;
	hkVector4 m_inertiaAndMassInv;
	hkVector4 m_linearVelocity;
	hkVector4 m_angularVelocity;
	hkVector4 m_deactivationRefPosition[ 2 ];
	hkUint32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion*	m_savedMotion;
	hkUint16 m_savedQualityTypeIndex;
};
class hkpKeyframedRigidMotion : public hkpMotion {
public:
	virtual ~hkpKeyframedRigidMotion();
	virtual void setMass(hkReal m);
	virtual void setMassInv(hkReal mInv);
	virtual void getInertiaLocal(hkMatrix3& inertia) const;
	virtual void setInertiaLocal(const hkMatrix3& inertia);
	virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
	virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
	virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
	virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
	virtual void applyLinearImpulse(const hkVector4& imp);
	virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
	virtual void applyAngularImpulse(const hkVector4& imp);
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
	virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
	virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
public:
	virtual void setStepPosition( hkReal position, hkReal timestep );
	virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion {
public:
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject {
public:
	enum SpuCollisionCallbackEventFilter {
		SPU_SEND_NONE = 0x00, SPU_SEND_CONTACT_POINT_ADDED	= 0x01, SPU_SEND_CONTACT_POINT_PROCESS	= 0x02,
		SPU_SEND_CONTACT_POINT_REMOVED	= 0x04,
		SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
	};
public:
	virtual ~hkpEntity();
	inline hkBool isFixed() const;
	void activate();
	void deactivate();
	void calcStatistics( hkStatisticsCollector* collector) const;
public:
	inline hkpSimulationIsland* getSimulationIsland() const;
	virtual void deallocateInternalArrays();
	virtual hkMotionState* getMotionState(){ return 0; }
protected:
	class hkpMaterial m_material;
protected:
	friend class hkpWorldConstraintUtil;
public:
	class SmallArraySerializeOverrideType {
	public:
		void* m_data;
		hkUint16 m_size;
		hkUint16 m_capacityAndFlags;
	};
	public: void* m_breakOffPartsUtil;
	public: hkUint32 m_solverData;
	public: hkObjectIndex m_storageIndex;
	protected:	hkUint16 m_processContactCallbackDelay;
	protected:	hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
	protected:	hkArray<hkpConstraintInstance*> m_constraintsSlave;
protected:
	hkArray<hkUint8> m_constraintRuntime;
	hkpSimulationIsland* m_simulationIsland;
public:
	hkInt8 m_autoRemoveLevel;
	hkUint8 m_numUserDatasInContactPointProperties;
	hkUint32 m_uid;
public:
	struct SpuCollisionCallback {
	public:
		hkSpuCollisionCallbackUtil* m_util;
		hkUint16 m_capacity;
		hkUint8 m_eventFilter;
		hkUint8	m_userFilter;
	};
	struct ExtendedListeners {
		hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
		hkSmallArray<hkpEntityListener*> m_entityListeners;
	};
public:
	struct SpuCollisionCallback m_spuCollisionCallback;
	protected:	mutable ExtendedListeners* m_extendedListeners;
	public: class hkpMaxSizeMotion m_motion;
protected:
	friend class hkpEntityCallbackUtil;
	friend class hkpWorldCallbackUtil;
	friend class hkpWorld;
	friend class hkpSimulationIsland;
	friend class hkpWorldOperationUtil;
	hkSmallArray<hkpCollisionListener*> m_collisionListeners;
	hkSmallArray<hkpAction*> m_actions;
};
inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const {
	return m_simulationIsland;
}
inline hkBool hkpEntity::isFixed() const {
	return m_motion.m_type == hkpMotion::MOTION_FIXED;
}
class hkStepInfo {
public:
public:
	__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
	hkPadSpu<hkTime> m_endTime;
	hkPadSpu<hkReal> m_deltaTime;
	hkPadSpu<hkReal> m_invDeltaTime;
};
class hkAabb {
public:
	__forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkAabb), HK_MEMORY_CLASS_CDINFO); } class MustEndWithSemiColon;
public:
	hkVector4 m_min;
	hkVector4 m_max;
};
class hkpWorldCinfo : public hkReferencedObject {
public:
	enum SolverType {
		SOLVER_TYPE_INVALID, SOLVER_TYPE_2ITERS_SOFT, SOLVER_TYPE_2ITERS_MEDIUM, SOLVER_TYPE_2ITERS_HARD,
		SOLVER_TYPE_4ITERS_SOFT, SOLVER_TYPE_4ITERS_MEDIUM, SOLVER_TYPE_4ITERS_HARD, SOLVER_TYPE_8ITERS_SOFT,
		SOLVER_TYPE_8ITERS_MEDIUM, SOLVER_TYPE_8ITERS_HARD, SOLVER_TYPE_MAX_ID
	};
	enum SimulationType {
		SIMULATION_TYPE_INVALID, SIMULATION_TYPE_DISCRETE, SIMULATION_TYPE_CONTINUOUS, SIMULATION_TYPE_MULTITHREADED,
	};
	enum ContactPointGeneration {
		CONTACT_POINT_ACCEPT_ALWAYS, CONTACT_POINT_REJECT_DUBIOUS, CONTACT_POINT_REJECT_MANY,
	};
	enum BroadPhaseBorderBehaviour {
		BROADPHASE_BORDER_ASSERT, BROADPHASE_BORDER_FIX_ENTITY, BROADPHASE_BORDER_REMOVE_ENTITY,
		BROADPHASE_BORDER_DO_NOTHING,
	};
public:
	hkVector4 m_gravity;
	hkInt32 m_broadPhaseQuerySize;
	hkReal m_contactRestingVelocity;
	hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
	class hkAabb m_broadPhaseWorldAabb;
	hkReal m_collisionTolerance;
	class hkpCollisionFilter* m_collisionFilter;
	class hkpConvexListFilter* m_convexListFilter;
	hkReal m_expectedMaxLinearVelocity;
	int m_sizeOfToiEventQueue;
	hkReal m_expectedMinPsiDeltaTime;
	class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
	hkInt32 m_broadPhaseNumMarkers;
	hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
	hkReal m_solverTau;
	hkReal m_solverDamp;
	hkInt32 m_solverIterations;
	hkInt32 m_solverMicrosteps;
	hkBool m_forceCoherentConstraintOrderingInSolver;
	hkReal m_snapCollisionToConvexEdgeThreshold;
	hkReal m_snapCollisionToConcaveEdgeThreshold;
	hkBool m_enableToiWeldRejection;
	hkBool m_enableDeprecatedWelding;
	hkReal m_iterativeLinearCastEarlyOutDistance;
	hkInt32 m_iterativeLinearCastMaxIterations;
	hkReal m_highFrequencyDeactivationPeriod;
	hkReal m_lowFrequencyDeactivationPeriod;
	hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
	hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
	hkUint8 m_deactivationIntegrateCounter;
	hkBool m_shouldActivateOnRigidBodyTransformChange;
	hkReal m_deactivationReferenceDistance;
	hkReal m_toiCollisionResponseRotateNormal;
	int m_maxSectorsPerCollideTask;
	hkBool m_processToisMultithreaded;
	int m_maxEntriesPerToiCollideTask;
	hkBool m_enableDeactivation;
	hkEnum<SimulationType, hkInt8> m_simulationType;
	hkBool m_enableSimulationIslands;
	hkUint32 m_minDesiredIslandSize;
	hkBool m_processActionsInSingleThread;
	hkReal m_frameMarkerPsiSnap;
	virtual ~hkpWorldCinfo() {}
};
struct hkpProcessCollisionInput;
class hkpTypedBroadPhaseDispatcher;
class hkpBroadPhase;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
enum hkpUpdateCollisionFilterOnWorldMode {
	HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK, HK_UPDATE_FILTER_ON_WORLD_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
};
enum hkpUpdateCollisionFilterOnEntityMode {
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK, HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY
};
enum hkpEntityActivation {
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE, HK_ENTITY_ACTIVATION_DO_ACTIVATE
};
enum hkpUpdateCollectionFilterMode {
	HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS
};
struct hkpWorldDynamicsStepInfo {
	hkStepInfo m_stepInfo;
	hkpSolverInfo m_solverInfo;
};
enum hkpStepResult {
	HK_STEP_RESULT_SUCCESS, HK_STEP_RESULT_MEMORY_FAILURE_BEFORE_INTEGRATION,
	HK_STEP_RESULT_MEMORY_FAILURE_DURING_COLLIDE, HK_STEP_RESULT_MEMORY_FAILURE_DURING_TOI_SOLVE,
};
class hkpWorld : public hkReferencedObject {
public:
	hkpEntity* addEntity( hkpEntity* entity, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
	hkBool removeEntity( hkpEntity* entity);
	void addEntityBatch( hkpEntity*const* entityBatch, int numEntities, hkpEntityActivation initialActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE);
	void removeEntityBatch( hkpEntity*const* entityBatch, int numEntities );
	hkpConstraintInstance* addConstraint( hkpConstraintInstance* constraint);
	hkBool removeConstraint( hkpConstraintInstance* constraint);
	hkpAction* addAction( hkpAction* action );
	void removeAction( hkpAction* action );
	hkpPhantom* addPhantom( hkpPhantom* phantom );
	void addPhantomBatch( hkpPhantom*const* phantomBatch, int numPhantoms );
	void removePhantom( hkpPhantom* phantom );
	void removePhantomBatch( hkpPhantom*const* phantomBatch, int numPhantoms );
	void activateRegion( const hkAabb& aabb );
	void updateCollisionFilterOnEntity( hkpEntity* entity,
	hkpUpdateCollisionFilterOnEntityMode updateMode,
	hkpUpdateCollectionFilterMode updateShapeCollectionFilter);
	void updateCollisionFilterOnPhantom( hkpPhantom* phantom,
	hkpUpdateCollectionFilterMode updateShapeCollectionFilter );
	void updateCollisionFilterOnWorld( hkpUpdateCollisionFilterOnWorldMode updateMode,
	hkpUpdateCollectionFilterMode updateShapeCollectionFilter );
	enum ReintegrationRecollideMode {
		RR_MODE_REINTEGRATE = 1, RR_MODE_RECOLLIDE_BROADPHASE = 2, RR_MODE_RECOLLIDE_NARROWPHASE = 4, RR_MODE_ALL = 7
	};
	void calcStatistics( hkStatisticsCollector* collector ) const;
	enum MtAccessChecking {
		MT_ACCESS_CHECKING_ENABLED = 0, MT_ACCESS_CHECKING_DISABLED
	};
	~hkpWorld();
public:
	hkpSimulation* m_simulation;
	hkVector4 m_gravity;
	hkpSimulationIsland* m_fixedIsland;
	hkpRigidBody*	m_fixedRigidBody;
	hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
	hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
	hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
	hkpWorldMaintenanceMgr* m_maintenanceMgr;
	hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
	hkpBroadPhase* m_broadPhase;
	hkpTypedBroadPhaseDispatcher* m_broadPhaseDispatcher;
	hkpPhantomBroadPhaseListener* m_phantomBroadPhaseListener;
	hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
	hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
	hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
	hkpProcessCollisionInput* m_collisionInput;
	hkpCollisionFilter* m_collisionFilter;
	hkpCollisionDispatcher* m_collisionDispatcher;
	hkpConvexListFilter* m_convexListFilter;
	hkpWorldOperationQueue* m_pendingOperations;
	int m_pendingOperationsCount;
	int m_criticalOperationsLockCount;
	int m_criticalOperationsLockCountForPhantoms;
	hkBool m_blockExecutingPendingOperations;
	hkBool m_criticalOperationsAllowed;
	hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
	int m_pendingOperationQueueCount;
	mutable class hkMultiThreadCheck m_multiThreadCheck;
	hkBool m_processActionsInSingleThread;
	hkUint32 m_minDesiredIslandSize;
	class hkCriticalSection* m_modifyConstraintCriticalSection;
	class hkCriticalSection* m_worldLock;
	class hkCriticalSection* m_islandDirtyListCriticalSection;
	struct PropertyLock {
		hkUint32 m_key;
		mutable hkMultiThreadCheck m_multiThreadCheck;
	};
	class hkCriticalSection* m_propertyMasterLock;
	hkBool m_wantSimulationIslands;
	hkReal m_snapCollisionToConvexEdgeThreshold;
	hkReal m_snapCollisionToConcaveEdgeThreshold;
	hkBool m_enableToiWeldRejection;
	hkBool m_wantDeactivation;
	hkBool m_shouldActivateOnRigidBodyTransformChange;
	hkReal m_deactivationReferenceDistance;
	hkReal m_toiCollisionResponseRotateNormal;
	hkBool m_processToisMultithreaded;
	int m_maxSectorsPerCollideTask;
	int m_maxEntriesPerToiCollideTask;
	hkEnum<hkpWorldCinfo::SimulationType,hkInt32> m_simulationType;
	static hkBool m_forceMultithreadedSimulation;
	class IgnoreForceMultithreadedSimulation {
	public:
	public:
		hkBool m_originalForceMultithreadedSimulationValue;
	};
protected:
	hkUint32 m_lastEntityUid;
public:
	friend class hkpWorldOperationUtil;
	friend class hkpWorldCallbackUtil;
	friend class hkpSimulation;
	friend class hkHalfstepSimulation;
	friend class hkpContinuousSimulation;
	friend class hkpMultiThreadedSimulation;
	friend class hkpSimpleConstraintContactMgr;
	hkArray<hkpPhantom*> m_phantoms;
	hkArray<hkpActionListener*> m_actionListeners;
	hkArray<hkpEntityListener*> m_entityListeners;
	hkArray<hkpPhantomListener*> m_phantomListeners;
	hkArray<hkpConstraintListener*> m_constraintListeners;
	hkArray<hkpWorldDeletionListener*> m_worldDeletionListeners;
	hkArray<hkpIslandActivationListener*> m_islandActivationListeners;
	hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
	hkArray<hkpWorldPostIntegrateListener*> m_worldPostIntegrateListeners;
	hkArray<hkpWorldPostCollideListener*> m_worldPostCollideListeners;
	hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
	hkArray<hkpIslandPostCollideListener*> m_islandPostCollideListeners;
	hkArray<hkpCollisionListener*> m_collisionListeners;
	hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
	class hkpBroadPhaseBorder* m_broadPhaseBorder;
public:
	struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
	hkVector4 m_broadPhaseExtents[2];
	int m_broadPhaseNumMarkers;
	int m_sizeOfToiEventQueue;
	hkInt32 m_broadPhaseQuerySize;
	hkInt32 m_broadPhaseUpdateSize;
	hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
};
extern "C" {
	typedef unsigned long DWORD;
	typedef unsigned short WORD;
	extern "C" {
		extern "C" {
			typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;
		}
		typedef long LONG;
		typedef void *HANDLE;
		typedef struct _LIST_ENTRY {
			struct _LIST_ENTRY *Flink;
			struct _LIST_ENTRY *Blink;
		} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;
		typedef struct _RTL_CRITICAL_SECTION_DEBUG {
			WORD Type;
			WORD CreatorBackTraceIndex;
			struct _RTL_CRITICAL_SECTION *CriticalSection;
			LIST_ENTRY ProcessLocksList;
			DWORD EntryCount;
			DWORD ContentionCount;
			DWORD Flags;
			WORD CreatorBackTraceIndexHigh;
			WORD SpareWORD ;
		} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;
		typedef struct _RTL_CRITICAL_SECTION {
			PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
			LONG LockCount;
			LONG RecursionCount;
			HANDLE OwningThread;
			HANDLE LockSemaphore;
			ULONG_PTR SpinCount;
		} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
	}
}
extern "C" {
	typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
}
extern "C" {
}
extern "C" {
}
class hkCriticalSection {
public:
public:
	CRITICAL_SECTION m_section;
	hkUint64 m_currentThread;
	struct SectionList {
		int m_spinCount;
		hkCriticalSection* m_prev;
		hkCriticalSection* m_next;
		static hkCriticalSection s_listHead;
	};
	SectionList m_list;
};
namespace hkWorldOperation {
	enum Type {
		OPERATION_ID_ANY = 0, OPERATION_ID_INVALID = 0, ENTITY_ADD, ENTITY_REMOVE, ENTITY_UPDATE_BROAD_PHASE,
		RIGIDBODY_SET_MOTION_TYPE, WORLD_OBJECT_SET_SHAPE, ENTITY_BATCH_ADD, ENTITY_BATCH_REMOVE, CONSTRAINT_ADD,
		CONSTRAINT_REMOVE, ACTION_ADD, ACTION_REMOVE, ISLAND_MERGE, PHANTOM_ADD, PHANTOM_REMOVE, PHANTOM_BATCH_ADD,
		PHANTOM_BATCH_REMOVE, PHANTOM_UPDATE_BROAD_PHASE, UPDATE_FILTER_ENTITY, UPDATE_FILTER_PHANTOM,
		UPDATE_FILTER_WORLD, UPDATE_MOVED_BODY_INFO, ENTITY_BATCH_REINTEGRATE_AND_RECOLLIDE,
		RIGIDBODY_SET_POSITION_AND_ROTATION, RIGIDBODY_SET_LINEAR_VELOCITY, RIGIDBODY_SET_ANGULAR_VELOCITY,
		RIGIDBODY_APPLY_LINEAR_IMPULSE, RIGIDBODY_APPLY_POINT_IMPULSE, RIGIDBODY_APPLY_ANGULAR_IMPULSE,
		WORLD_OBJECT_ADD_REFERENCE, WORLD_OBJECT_REMOVE_REFERENCE, ACTIVATE_REGION, ACTIVATE_ENTITY,
		DEACTIVATE_ENTITY, USER_CALLBACK
	};
	class UserCallback : public hkReferencedObject {
	public:
		virtual void worldOperationUserCallback(hkUlong userData) = 0;
	};
	struct BaseOperation {
		hkEnum<Type, hkUint8> m_type;
	};
	struct AddEntity : public BaseOperation {
		hkpEntity* m_entity;
		hkpEntityActivation m_activation;
	};
	struct RemoveEntity : public BaseOperation {
		hkpEntity* m_entity;
	};
	struct SetRigidBodyMotionType : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkEnum<hkpMotion::MotionType, hkUint8> m_motionType;
		hkEnum<hkpEntityActivation, hkUint8> m_activation;
		hkEnum<hkpUpdateCollisionFilterOnEntityMode, hkUint8> m_collisionFilterUpdateMode;
		hkEnum<hkpUpdateCollectionFilterMode, hkUint8>	m_updateShapeCollections;
	};
	struct SetWorldObjectShape : public BaseOperation {
		hkpWorldObject* m_worldObject;
		const hkpShape* m_shape;
	};
	struct AddEntityBatch : public BaseOperation {
		hkpEntity** m_entities;
		hkObjectIndex m_numEntities;
		hkEnum<hkpEntityActivation, hkUint8> m_activation;
	};
	struct RemoveEntityBatch : public BaseOperation {
		hkpEntity** m_entities;
		hkObjectIndex m_numEntities;
	};
	struct AddConstraint : public BaseOperation {
		hkpConstraintInstance* m_constraint;
	};
	struct RemoveConstraint : public BaseOperation {
		hkpConstraintInstance* m_constraint;
	};
	struct AddAction : public BaseOperation {
		hkpAction* m_action;
	};
	struct RemoveAction : public BaseOperation {
		hkpAction* m_action;
	};
	struct MergeIslands : public BaseOperation {
		hkpEntity* m_entities[2];
	};
	struct AddPhantom : public BaseOperation {
		hkpPhantom* m_phantom;
	};
	struct RemovePhantom : public BaseOperation {
		hkpPhantom* m_phantom;
	};
	struct AddPhantomBatch : public BaseOperation {
		hkpPhantom** m_phantoms;
		hkObjectIndex m_numPhantoms;
	};
	struct RemovePhantomBatch : public BaseOperation {
		hkpPhantom** m_phantoms;
		hkObjectIndex m_numPhantoms;
	};
	struct UpdateEntityBP : public BaseOperation {
		hkpEntity* m_entity;
	};
	struct UpdatePhantomBP : public BaseOperation {
		hkpPhantom* m_phantom;
		hkAabb* m_aabb;
	};
	struct UpdateFilterOnEntity : public BaseOperation {
		hkpEntity* m_entity;
		hkEnum<hkpUpdateCollisionFilterOnEntityMode, hkUint8> m_collisionFilterUpdateMode;
		hkEnum<hkpUpdateCollectionFilterMode, hkUint8> m_updateShapeCollections;
	};
	struct UpdateFilterOnPhantom : public BaseOperation {
		hkpPhantom* m_phantom;
		hkEnum<hkpUpdateCollectionFilterMode, hkUint8> m_updateShapeCollections;
	};
	struct UpdateFilterOnWorld : public BaseOperation {
		hkEnum<hkpUpdateCollisionFilterOnWorldMode, hkUint8> m_collisionFilterUpdateMode;
		hkEnum<hkpUpdateCollectionFilterMode, hkUint8> m_updateShapeCollections;
	};
	struct ReintegrateAndRecollideEntityBatch : public BaseOperation {
		hkpEntity** m_entities;
		hkObjectIndex m_numEntities;
		hkUint8 m_mode;
		hkEnum<hkpEntityActivation, hkUint8> m_activation;
	};
	struct UpdateMovedBodyInfo : public BaseOperation {
		hkpEntity* m_entity;
	};
	struct SetRigidBodyPositionAndRotation : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkVector4* m_positionAndRotation;
	};
	struct SetRigidBodyLinearVelocity : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkReal m_linearVelocity[3];
	};
	struct SetRigidBodyAngularVelocity : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkReal m_angularVelocity[3];
	};
	struct ApplyRigidBodyLinearImpulse : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkReal m_linearImpulse[3];
	};
	struct ApplyRigidBodyPointImpulse : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkVector4* m_pointAndImpulse;
	};
	struct ApplyRigidBodyAngularImpulse : public BaseOperation {
		hkpRigidBody* m_rigidBody;
		hkReal m_angularImpulse[3];
	};
	struct ActivateRegion : public BaseOperation {
		hkAabb* m_aabb;
	};
	struct ActivateEntity : public BaseOperation {
		hkpEntity* m_entity;
	};
	struct DeactivateEntity : public BaseOperation {
		hkpEntity* m_entity;
	};
	struct UserCallbackOperation : public BaseOperation {
		UserCallback* m_userCallback;
		hkUlong m_userData;
	};
	struct BiggestOperation : public BaseOperation {
		hkUlong dummy[3 + 1];
	};
}
class hkpWorldOperationQueue {
public:
	void FUN_00983680();
public:
	hkArray<hkWorldOperation::BiggestOperation> m_pending;
	hkpWorld* m_world;
	hkArray<hkWorldOperation::BiggestOperation> m_islandMerges;
	hkBool m_storeIslandMergesOnSeparateList;
private:
	hkCriticalSection m_queueOperationCriticalSection;
};
class hkpWorldOperationUtil {
public:
	enum FireCallbacks {
		DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS, DO_FIRE_CALLBACKS
	};
public:
	static void __cdecl updateEntityBP ( hkpWorld* world, hkpEntity* entity );
	static __forceinline void
	__cdecl mergeIslandsIfNeeded( hkpEntity* entityA, hkpEntity* entityB);
	static void __cdecl mergeIslands ( hkpWorld* world, hkpEntity* entityA, hkpEntity* entityB);
};
struct hkpProcessCollisionOutput;
void hkpWorldOperationUtil::mergeIslandsIfNeeded( hkpEntity* entityA, hkpEntity* entityB ) {
	if ( !entityA->isFixed() && !entityB->isFixed() &&
	entityA->getSimulationIsland() != entityB->getSimulationIsland() ) {
		hkpWorldOperationUtil::mergeIslands(entityA->getWorld(), entityA, entityB);
	}
}
class hkpSimulation: public hkReferencedObject {
public:
	~hkpSimulation();
	virtual hkpStepResult stepDeltaTime( hkReal physicsDeltaTime );
	virtual hkpStepResult integrate( hkReal physicsDeltaTime );
	virtual hkpStepResult collide();
	virtual hkpStepResult advanceTime();
	enum FindContacts {
		FIND_CONTACTS_DEFAULT = 0, FIND_CONTACTS_EXTRA
	};
	virtual void collideEntitiesDiscrete( hkpEntity** entities, int numEntities, hkpWorld* world, const hkStepInfo& stepInfo, FindContacts findExtraContacts );
	virtual void resetCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world, hkBool skipReinitializationOfAgents = false );
	virtual void assertThereIsNoCollisionInformationForEntities( hkpEntity** entities, int numEntities, hkpWorld* world ) {}
	virtual void removeCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
	virtual void assertThereIsNoCollisionInformationForAgent( hkpAgentNnEntry* agent ) {}
protected:
	friend class hkpWorld;
	friend class hkpWorldOperationQueue;
	virtual void reintegrateAndRecollideEntities( hkpEntity** entityBatch, int numEntities, hkpWorld* world, int reintegrateRecollideMode );
protected:
	virtual void collideInternal( const hkStepInfo& stepInfoIn );
	typedef void (hkpSimulation::*AgentEntryProcessFunction)(hkpAgentNnEntry*, const hkpProcessCollisionInput&, hkpProcessCollisionOutput&);
public:
	virtual void warpTime( hkReal deltaTime ) {}
public:
	hkUint32 m_determinismCheckFrameCounter;
protected:
	class hkpWorld* m_world;
	enum LastProcessingStep {
		INTEGRATE, COLLIDE
	};
	hkEnum<LastProcessingStep,hkUint8> m_lastProcessingStep;
	hkTime m_currentTime;
	hkTime m_currentPsiTime;
	hkReal m_physicsDeltaTime;
	hkTime m_simulateUntilTime;
	hkReal m_frameMarkerPsiSnap;
	hkUint32 m_previousStepResult;
};
class hkpRigidBody : public hkpEntity {
public:
	virtual ~hkpRigidBody();
	void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
	inline void	setLinearVelocity(const hkVector4& newVel);
	inline void	setAngularVelocity(const hkVector4& newVel);
	inline void applyLinearImpulse(const hkVector4& imp);
	inline void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
	inline void applyAngularImpulse(const hkVector4& imp);
	void setMotionType( hkpMotion::MotionType newState,
	hkpEntityActivation preferredActivationState = HK_ENTITY_ACTIVATION_DO_ACTIVATE,
	hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode = HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
	hkWorldOperation::Result setShape(const hkpShape* shape);
	virtual hkpRigidBody* clone() const;
public:
	inline hkpMotion* getRigidMotion() const;
public:
	static void __cdecl updateBroadphaseAndResetCollisionInformationOfWarpedBody( hkpEntity* entity );
protected:
	virtual hkMotionState* getMotionState();
};
inline hkpMotion* hkpRigidBody::getRigidMotion() const {
	return const_cast<hkpMaxSizeMotion*>(&m_motion);
}
inline void hkpRigidBody::applyLinearImpulse(const hkVector4& imp) {
	activate();
	getRigidMotion()->applyLinearImpulse(imp);
}
inline void hkpRigidBody::applyPointImpulse(const hkVector4& imp, const hkVector4& p) {
	activate();
	getRigidMotion()->applyPointImpulse(imp, p);
}
inline void hkpRigidBody::applyAngularImpulse(const hkVector4& imp) {
	activate();
	getRigidMotion()->applyAngularImpulse(imp);
}
void hkpRigidBody::setLinearVelocity(const hkVector4& newVel) {
	activate();
	getRigidMotion()->setLinearVelocity(newVel);
}
void hkpRigidBody::setAngularVelocity(const hkVector4& newVel) {
	activate();
	getRigidMotion()->setAngularVelocity(newVel);
}
enum hkpCollidableAccept {
	HK_COLLIDABLE_ACCEPT = 0, HK_COLLIDABLE_REJECT = 1
};
struct hkpCollidableAddedEvent {
	const hkpPhantom* m_phantom;
	const hkpCollidable* m_collidable;
	mutable hkpCollidableAccept m_collidableAccept;
};
struct hkpCollidableRemovedEvent {
	const hkpPhantom* m_phantom;
	const hkpCollidable* m_collidable;
	hkBool m_collidableWasAdded;
};
class hkpPhantomOverlapListener {
public:
	virtual void collidableAddedCallback( const hkpCollidableAddedEvent& event ) = 0;
	virtual void collidableRemovedCallback( const hkpCollidableRemovedEvent& event ) = 0;
	virtual ~hkpPhantomOverlapListener() {}
};
enum hkpPhantomType {
	HK_PHANTOM_AABB = 0, HK_PHANTOM_SIMPLE_SHAPE = 1, HK_PHANTOM_CACHING_SHAPE = 2, HK_PHANTOM_USER0,
	HK_PHANTOM_USER1, HK_PHANTOM_USER2, HK_PHANTOM_USER3, HK_PHANTOM_USER4, HK_PHANTOM_USER5, HK_PHANTOM_USER6,
	HK_PHANTOM_USER7, HK_PHANTOM_USER8, HK_PHANTOM_USER9, HK_PHANTOM_MAX_ID
};
class hkpPhantom : public hkpWorldObject {
public:
	~hkpPhantom();
	virtual hkpPhantomType getType() const = 0;
	virtual void calcAabb( hkAabb& aabb ) = 0;
	virtual void addOverlappingCollidable( hkpCollidable* collidable ) = 0;
	virtual hkBool isOverlappingCollidableAdded( hkpCollidable* collidable ) = 0;
	virtual void removeOverlappingCollidable( hkpCollidable* collidable ) = 0;
	virtual hkpPhantom* clone() const = 0;
	void calcStatistics( hkStatisticsCollector* collector ) const;
public:
	virtual void updateShapeCollectionFilter() {}
public:
	void updateBroadPhase( const hkAabb& aabb );
protected:
	hkArray<hkpPhantomOverlapListener*> m_overlapListeners;
	hkArray<hkpPhantomListener*> m_phantomListeners;
public:
	virtual void deallocateInternalArrays();
};
class hkpAction : public hkReferencedObject {
public:
	virtual ~hkpAction() { }
	virtual void applyAction( const hkStepInfo& stepInfo ) = 0;
	virtual void getEntities( hkArray<hkpEntity*>& entitiesOut ) = 0;
	virtual void getPhantoms( hkArray<hkpPhantom*>& phantomsOut ) {}
	inline hkpWorld* getWorld();
	virtual void entityRemovedCallback(hkpEntity* entity) = 0;
	virtual hkpAction* clone( const hkArray<hkpEntity*>& newEntities, const hkArray<hkpPhantom*>& newPhantoms ) const = 0;
private:
	hkpWorld* m_world;
	hkpSimulationIsland* m_island;
protected:
	hkUlong m_userData;
	const char* m_name;
	friend class hkpWorld;
	friend class hkpWorldOperationUtil;
	friend class hkpSimulationIsland;
public:
	inline hkpSimulationIsland* getSimulationIsland();
};
inline hkpSimulationIsland* hkpAction::getSimulationIsland() {
	return m_island;
}
inline hkpWorld* hkpAction::getWorld() {
	return m_world;
}
namespace hkAlgorithm {
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
}
namespace hkAlgorithm {
	template<typename T, typename L>
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess) {
		int i,j;
		__declspec(align(16)) T str;
		begin:
		i = h;
		j = d;
		str = pArr[(d+h)>>1];
		do {
			while ( cmpLess( pArr[j], str) ){ j++; }
			while ( cmpLess( str, pArr[i]) ){ i--; }
			if ( i >= j ) {
				if ( i != j ) {
					__declspec(align(16)) T zal;
					T& pi = pArr[i];
					T& pj = pArr[j];
					zal = pi; pi = pj, pj = zal;
				}
				i--;
				j++;
			}
		} while (j <= i);
		if (d < i) {
			quickSortRecursive(pArr,d,i, cmpLess);
		}
		if (j < h) {
			d = j;
			goto begin;
		}
	}
	template<typename T, typename L>
	void __cdecl quickSort(T *pArr, int iSize, L cmpLess) {
		if (iSize > 1) {
			int	low = 0;
			int high = iSize - 1;
			quickSortRecursive(pArr,low,high, cmpLess);
		}
	}
}
static inline void removeReferenceFrom( hkReferencedObject* obj ) {
	obj->removeReference();
}
hkBool islandLess( const hkWorldOperation::BiggestOperation& a, const hkWorldOperation::BiggestOperation& b );
// pdb: hkpWorldOperationQueue::executeAllPending | hkpWorldOperationQueue.obj | tesv_win, call_seq, medium
void hkpWorldOperationQueue::FUN_00983680() {
	hkArray<hkWorldOperation::BiggestOperation> stolenPending;
	stolenPending.swap( m_pending );
	m_world->m_pendingOperationQueueCount++;
	if ( m_islandMerges.getSize() ) {
		hkAlgorithm::quickSort( m_islandMerges.begin(), m_islandMerges.getSize(), islandLess );
		while ( m_islandMerges.getSize() ) {
			hkWorldOperation::BiggestOperation bop = m_islandMerges.back();
			m_islandMerges.popBack();
			hkWorldOperation::MergeIslands& mop = reinterpret_cast<hkWorldOperation::MergeIslands&>( bop );
			if ( mop.m_entities[0]->getWorld() == m_world && mop.m_entities[1]->getWorld() == m_world ) {
				hkpWorldOperationUtil::mergeIslandsIfNeeded( mop.m_entities[0], mop.m_entities[1] );
			}
			removeReferenceFrom( mop.m_entities[0] );
			removeReferenceFrom( mop.m_entities[1] );
		}
	}
	for ( int i = 0; i < stolenPending.getSize(); i++ ) {
		hkWorldOperation::BaseOperation& op = stolenPending[i];
		switch ( op.m_type ) {
			case hkWorldOperation::ENTITY_ADD: {
				hkWorldOperation::AddEntity& cop = static_cast<hkWorldOperation::AddEntity&>( op );
				if ( !cop.m_entity->getWorld() ) {
					m_world->addEntity( cop.m_entity, cop.m_activation );
				}
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::ENTITY_REMOVE: {
				hkWorldOperation::AddEntity& cop = static_cast<hkWorldOperation::AddEntity&>( op );
				if ( cop.m_entity->getWorld() == m_world ) {
					m_world->removeEntity( cop.m_entity );
				}
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::RIGIDBODY_SET_MOTION_TYPE: {
				hkWorldOperation::SetRigidBodyMotionType& cop = static_cast<hkWorldOperation::SetRigidBodyMotionType&>( op );
				cop.m_rigidBody->setMotionType( cop.m_motionType, cop.m_activation, cop.m_collisionFilterUpdateMode );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::WORLD_OBJECT_SET_SHAPE: {
				hkWorldOperation::SetWorldObjectShape& cop = static_cast<hkWorldOperation::SetWorldObjectShape&>( op );
				cop.m_worldObject->setShape( cop.m_shape );
				removeReferenceFrom( cop.m_worldObject );
				cop.m_shape->removeReference();
				break;
			}
			case hkWorldOperation::ENTITY_BATCH_ADD: {
				hkWorldOperation::AddEntityBatch& cop = static_cast<hkWorldOperation::AddEntityBatch&>( op );
				m_world->addEntityBatch( cop.m_entities, cop.m_numEntities, cop.m_activation );
				hkpEntity** e = cop.m_entities;
				hkpEntity** eEnd = e + cop.m_numEntities;
				while ( e < eEnd ) {
					removeReferenceFrom( *e ); e++;
				}
				hkDeallocateChunk<hkpEntity*>( cop.m_entities, cop.m_numEntities, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::ENTITY_BATCH_REMOVE: {
				hkWorldOperation::RemoveEntityBatch& cop = static_cast<hkWorldOperation::RemoveEntityBatch&>( op );
				m_world->removeEntityBatch( cop.m_entities, cop.m_numEntities );
				hkpEntity** e = cop.m_entities;
				hkpEntity** eEnd = e + cop.m_numEntities;
				while ( e < eEnd ) {
					removeReferenceFrom( *e ); e++;
				}
				hkDeallocateChunk<hkpEntity*>( cop.m_entities, cop.m_numEntities, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::CONSTRAINT_ADD: {
				hkWorldOperation::AddConstraint& cop = static_cast<hkWorldOperation::AddConstraint&>( op );
				if ( !cop.m_constraint->getOwner() ) {
					if ( cop.m_constraint->getEntityA()->getWorld() == m_world && cop.m_constraint->getEntityB()->getWorld() == m_world ) {
						m_world->addConstraint( cop.m_constraint );
					}
				}
				removeReferenceFrom( cop.m_constraint );
				break;
			}
			case hkWorldOperation::CONSTRAINT_REMOVE: {
				hkWorldOperation::RemoveConstraint& cop = static_cast<hkWorldOperation::RemoveConstraint&>( op );
				if ( cop.m_constraint->getOwner() ) {
					m_world->removeConstraint( cop.m_constraint );
				}
				cop.m_constraint->removeReference();
				break;
			}
			case hkWorldOperation::ACTION_ADD: {
				hkWorldOperation::AddAction& cop = static_cast<hkWorldOperation::AddAction&>( op );
				if ( !cop.m_action->getWorld() ) {
					hkBool allActionsInWorld = true;
					hkArray<hkpEntity*> actionEntities;
					cop.m_action->getEntities( actionEntities );
					for ( int k = 0; k < actionEntities.getSize(); k++ ) {
						if ( actionEntities[k]->getWorld() != m_world ) {
							allActionsInWorld = false;
							break;
						}
					}
					if ( allActionsInWorld ) {
						m_world->addAction( cop.m_action );
					}
				}
				cop.m_action->removeReference();
				break;
			}
			case hkWorldOperation::ACTION_REMOVE: {
				hkWorldOperation::RemoveAction& cop = static_cast<hkWorldOperation::RemoveAction&>( op );
				if ( cop.m_action->getSimulationIsland() ) {
					m_world->removeAction( cop.m_action );
				}
				cop.m_action->removeReference();
				break;
			}
			case hkWorldOperation::PHANTOM_ADD: {
				hkWorldOperation::AddPhantom& cop = static_cast<hkWorldOperation::AddPhantom&>( op );
				if ( !cop.m_phantom->getWorld() ) {
					m_world->addPhantom( cop.m_phantom );
				}
				removeReferenceFrom( cop.m_phantom );
				break;
			}
			case hkWorldOperation::PHANTOM_REMOVE: {
				hkWorldOperation::RemovePhantom& cop = static_cast<hkWorldOperation::RemovePhantom&>( op );
				if ( cop.m_phantom->getWorld() == m_world ) {
					m_world->removePhantom( cop.m_phantom );
				}
				removeReferenceFrom( cop.m_phantom );
				break;
			}
			case hkWorldOperation::PHANTOM_BATCH_ADD: {
				hkWorldOperation::AddPhantomBatch& cop = static_cast<hkWorldOperation::AddPhantomBatch&>( op );
				m_world->addPhantomBatch( cop.m_phantoms, cop.m_numPhantoms );
				hkpPhantom** p = cop.m_phantoms;
				hkpPhantom** pEnd = p + cop.m_numPhantoms;
				while ( p < pEnd ) {
					removeReferenceFrom( *p ); p++;
				}
				hkDeallocateChunk<hkpPhantom*>( cop.m_phantoms, cop.m_numPhantoms, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::PHANTOM_BATCH_REMOVE: {
				hkWorldOperation::RemovePhantomBatch& cop = static_cast<hkWorldOperation::RemovePhantomBatch&>( op );
				m_world->removePhantomBatch( cop.m_phantoms, cop.m_numPhantoms );
				hkpPhantom** p = cop.m_phantoms;
				hkpPhantom** pEnd = p + cop.m_numPhantoms;
				while ( p < pEnd ) {
					removeReferenceFrom( *p ); p++;
				}
				hkDeallocateChunk<hkpPhantom*>( cop.m_phantoms, cop.m_numPhantoms, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::ENTITY_UPDATE_BROAD_PHASE: {
				hkWorldOperation::UpdateEntityBP& cop = static_cast<hkWorldOperation::UpdateEntityBP&>( op );
				if ( cop.m_entity->getWorld() == m_world ) {
					hkpWorldOperationUtil::updateEntityBP( m_world, cop.m_entity );
				}
				cop.m_entity->removeReference();
				break;
			}
			case hkWorldOperation::PHANTOM_UPDATE_BROAD_PHASE: {
				hkWorldOperation::UpdatePhantomBP& cop = static_cast<hkWorldOperation::UpdatePhantomBP&>( op );
				if ( cop.m_phantom->getWorld() == m_world ) {
					cop.m_phantom->updateBroadPhase( *cop.m_aabb );
				}
				removeReferenceFrom( cop.m_phantom );
				delete cop.m_aabb;
				break;
			}
			case hkWorldOperation::UPDATE_FILTER_ENTITY: {
				hkWorldOperation::UpdateFilterOnEntity& cop = static_cast<hkWorldOperation::UpdateFilterOnEntity&>( op );
				if ( cop.m_entity->getWorld() == m_world ) {
					m_world->updateCollisionFilterOnEntity( cop.m_entity, cop.m_collisionFilterUpdateMode, cop.m_updateShapeCollections );
				}
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::UPDATE_FILTER_PHANTOM: {
				hkWorldOperation::UpdateFilterOnPhantom& cop = static_cast<hkWorldOperation::UpdateFilterOnPhantom&>( op );
				if ( cop.m_phantom->getWorld() == m_world ) {
					m_world->updateCollisionFilterOnPhantom( cop.m_phantom, cop.m_updateShapeCollections );
				}
				removeReferenceFrom( cop.m_phantom );
				break;
			}
			case hkWorldOperation::UPDATE_FILTER_WORLD: {
				hkWorldOperation::UpdateFilterOnWorld& cop = static_cast<hkWorldOperation::UpdateFilterOnWorld&>( op );
				m_world->updateCollisionFilterOnWorld( cop.m_collisionFilterUpdateMode, cop.m_updateShapeCollections );
				break;
			}
			case hkWorldOperation::UPDATE_MOVED_BODY_INFO: {
				hkWorldOperation::UpdateMovedBodyInfo& cop = static_cast<hkWorldOperation::UpdateMovedBodyInfo&>( op );
				hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody( cop.m_entity );
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::RIGIDBODY_SET_POSITION_AND_ROTATION: {
				hkWorldOperation::SetRigidBodyPositionAndRotation& cop = static_cast<hkWorldOperation::SetRigidBodyPositionAndRotation&>( op );
				cop.m_rigidBody->setPositionAndRotation( cop.m_positionAndRotation[0], reinterpret_cast<hkQuaternion&>( cop.m_positionAndRotation[1] ) );
				hkDeallocateChunk<hkVector4>( cop.m_positionAndRotation, 2, HK_MEMORY_CLASS_DYNAMICS );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::RIGIDBODY_SET_LINEAR_VELOCITY: {
				hkWorldOperation::SetRigidBodyLinearVelocity& cop = static_cast<hkWorldOperation::SetRigidBodyLinearVelocity&>( op );
				hkVector4 velocity; velocity.set( cop.m_linearVelocity[0], cop.m_linearVelocity[1], cop.m_linearVelocity[2] );
				cop.m_rigidBody->setLinearVelocity( velocity );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::RIGIDBODY_SET_ANGULAR_VELOCITY: {
				hkWorldOperation::SetRigidBodyAngularVelocity& cop = static_cast<hkWorldOperation::SetRigidBodyAngularVelocity&>( op );
				hkVector4 velocity; velocity.set( cop.m_angularVelocity[0], cop.m_angularVelocity[1], cop.m_angularVelocity[2] );
				cop.m_rigidBody->setAngularVelocity( velocity );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::RIGIDBODY_APPLY_LINEAR_IMPULSE: {
				hkWorldOperation::ApplyRigidBodyLinearImpulse& cop = static_cast<hkWorldOperation::ApplyRigidBodyLinearImpulse&>( op );
				hkVector4 impulse; impulse.set( cop.m_linearImpulse[0], cop.m_linearImpulse[1], cop.m_linearImpulse[2] );
				cop.m_rigidBody->applyLinearImpulse( impulse );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::RIGIDBODY_APPLY_POINT_IMPULSE: {
				hkWorldOperation::ApplyRigidBodyPointImpulse& cop = static_cast<hkWorldOperation::ApplyRigidBodyPointImpulse&>( op );
				hkVector4& point = cop.m_pointAndImpulse[0];
				hkVector4& impulse = cop.m_pointAndImpulse[1];
				cop.m_rigidBody->applyPointImpulse( impulse, point );
				hkDeallocateChunk<hkVector4>( cop.m_pointAndImpulse, 2, HK_MEMORY_CLASS_DYNAMICS );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::RIGIDBODY_APPLY_ANGULAR_IMPULSE: {
				hkWorldOperation::ApplyRigidBodyAngularImpulse& cop = static_cast<hkWorldOperation::ApplyRigidBodyAngularImpulse&>( op );
				hkVector4 impulse; impulse.set( cop.m_angularImpulse[0], cop.m_angularImpulse[1], cop.m_angularImpulse[2] );
				cop.m_rigidBody->applyAngularImpulse( impulse );
				removeReferenceFrom( cop.m_rigidBody );
				break;
			}
			case hkWorldOperation::ACTIVATE_REGION: {
				hkWorldOperation::ActivateRegion& cop = static_cast<hkWorldOperation::ActivateRegion&>( op );
				hkAabb& aabb = *cop.m_aabb;
				m_world->activateRegion( aabb );
				hkDeallocateChunk<hkAabb>( cop.m_aabb, 1, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::ACTIVATE_ENTITY: {
				hkWorldOperation::ActivateEntity& cop = static_cast<hkWorldOperation::ActivateEntity&>( op );
				cop.m_entity->activate();
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::DEACTIVATE_ENTITY: {
				hkWorldOperation::DeactivateEntity& cop = static_cast<hkWorldOperation::DeactivateEntity&>( op );
				if ( cop.m_entity->getWorld() == m_world ) {
					cop.m_entity->deactivate();
				}
				removeReferenceFrom( cop.m_entity );
				break;
			}
			case hkWorldOperation::ENTITY_BATCH_REINTEGRATE_AND_RECOLLIDE: {
				hkWorldOperation::ReintegrateAndRecollideEntityBatch& cop = static_cast<hkWorldOperation::ReintegrateAndRecollideEntityBatch&>( op );
				m_world->m_simulation->reintegrateAndRecollideEntities( cop.m_entities, cop.m_numEntities, m_world, cop.m_mode );
				hkpEntity** e = cop.m_entities;
				hkpEntity** eEnd = e + cop.m_numEntities;
				while ( e < eEnd ) {
					removeReferenceFrom( *e ); e++;
				}
				hkDeallocateChunk<hkpEntity*>( cop.m_entities, cop.m_numEntities, HK_MEMORY_CLASS_DYNAMICS );
				break;
			}
			case hkWorldOperation::USER_CALLBACK: {
				hkWorldOperation::UserCallbackOperation& cop = static_cast<hkWorldOperation::UserCallbackOperation&>( op );
				cop.m_userCallback->worldOperationUserCallback( cop.m_userData );
				removeReferenceFrom( cop.m_userCallback );
				break;
			}
			default:
			break;
		}
		if ( m_pending.getSize() ) {
			FUN_00983680();
		}
	}
	stolenPending.swap( m_pending );
	m_pending.clear();
	m_world->m_pendingOperationQueueCount--;
}
}
