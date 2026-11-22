#include "f3_common.h"
// src/havok/physics/dynamics/phantom/hkpcachingshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpcachingshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCachingShapePhantom.h"

struct hkpCachingShapePhantomStandIn
{
    char m_padding000[0x160];
    void* m_kCollisionDetails;
    int m_collisionDetailsSize;
    char m_padding168[4];
    unsigned char m_bOrderDirty;

    void FUN_00d4d090();
};

// @fnv 0x00d4c910
// pdb: hkpCapsuleShape::getNumCollisionSpheresImpl | hkpCapsuleShape.obj | fnv360_0822_retail, objrun_open, low
int FUN_00d4c910()
{
    return 2;
}

struct GskAgentInput;
struct WorldOperationEntry;

class hkpCollisionAgent
{
  public:
    virtual ~hkpCollisionAgent();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void ProcessAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input,
                                  WorldOperationEntry& output);
};

struct CollisionAgentPair
{
    hkpCollisionAgent* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

class hkpCachingShapePhantomEx : public hkpShapePhantom
{
  public:
    hkArray<CollisionAgentPair> m_kCollisionDetails;
    hkBool m_bOrderDirty;
    char pad16D_0;
    char pad16D_1;
    char pad16D_2;

    void DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input);
};

// @f3 0x009d94b0 (community match, verified in this file)
struct GskAgentInput;
struct WorldOperationEntry;
struct W67World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    GskAgentInput* m_pCollisionInput;
};
struct W67Detail
{
    void* m_pCollisionAgent;
    void* m_kCollidable;
};
struct W67Phantom
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    W67Detail* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// pdb: hkpCachingShapePhantom::getClosestPoints | hkpCachingShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collector, input
void hkpCachingShapePhantomEx::DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input)
{
    W67Phantom* self = (W67Phantom*)this;
    if (!input)
    {
        input = ((W67World*)this->m_pOwningWorld)->m_pCollisionInput;
    }
    for (int i = self->m_iElementCount - 1; i >= 0; --i)
    {
        CollisionAgentPair* detail = &((CollisionAgentPair*)self->m_data)[i];
        detail->m_pCollisionAgent->ProcessAgent(this->m_kCollidable, *detail->m_kCollidable, *input, output);
    }
}


namespace fnv_00d4c980 {
struct CollisionAgentContext;

struct hkpCdBodyPairCollector
{
    virtual ~hkpCdBodyPairCollector();
    hkBool m_earlyOutHit;
};

struct hkpCollisionAgent
{
    virtual ~hkpCollisionAgent();
    virtual void unk04();
    virtual void unk08();
    virtual void getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                 hkpCdBodyPairCollector& collector);
};

struct CollisionAgentPair
{
    hkpCollisionAgent* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

}  // namespace fnv_00d4c980

struct hkBoolD4C9
{
    char m_cBooleanValue;
    hkBoolD4C9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkpCollidableD4C9;

struct hkpCollisionDetailD4C9
{
    void* m_pCollisionAgent;
    hkpCollidableD4C9* m_kCollidable;
};

template <class T> class hkArrayD4C9
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpCachingShapePhantomD4C9
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArrayD4C9<hkpCollisionDetailD4C9> m_kCollisionDetails;

    hkBoolD4C9 ContainsCollidable(const hkpCollidableD4C9* pkCollidable) const;
};

// Searches the collision detail array for an entry whose collidable pointer equals pkCollidable and returns true if found, otherwise false.
// @f3 0x009d9570 (community match, verified in this file)
// pdb: hkpCachingShapePhantom::isOverlappingCollidableAdded | hkpCachingShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collidable
hkBoolD4C9 hkpCachingShapePhantomD4C9::ContainsCollidable(const hkpCollidableD4C9* collidable) const
{
    const hkArrayD4C9<hkpCollisionDetailD4C9>& details =
        *reinterpret_cast<const hkArrayD4C9<hkpCollisionDetailD4C9>*>(&unk150);
    for (int index = 0; index < details.GetLogicalSize(); ++index) {
        if (details[index].m_kCollidable == collidable)
            return true;
    }
    return false;
}


class hkClassD4CD;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayD4CD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};

class hkStatisticsCollectorD4CD
{
  public:
    virtual ~hkStatisticsCollectorD4CD() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();
    virtual void beginObject(const char* pcName) throw();
    virtual void endObject() throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayD4CD<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int iAllocated = FUN_00d06f80(kArray.m_data, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkpCollidableD4CD;

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];

    void WritePhantomLists(hkStatisticsCollectorD4CD* pkCollector, const hkClassD4CD* pkClass) const throw();
};

class hkpCollisionAgentD4CD;

struct hkpCollisionDetailD4CD
{
    hkpCollisionAgentD4CD* m_pCollisionAgent;
    hkpCollidableD4CD* m_kCollidable;
};

class hkpCachingShapePhantomD4CD : public FUN_00d08130
{
  public:
    char m_padB0[0xb0];
    hkArrayD4CD<hkpCollisionDetailD4CD> m_kCollisionDetails;
    hkBool m_bOrderDirty;

    void __thiscall hkpCachingShapePhantom_calcContentStatistics(hkStatisticsCollectorD4CD* pkCollector) const throw();
};

// Adds this phantom's base data and its AgentPtr array to the collector, then reports each collision agent as a child object under "agents".
// @f3 0x009d97d0 (community match, verified in this file)
extern char DAT_00e801c8,DAT_00e801bc,DAT_00e7eb64;
struct Detail557 { void* agent; void* collidable; };
struct Collector557 {
    virtual void Slot0();
    virtual void Begin(const char*,int,const void*);
    virtual void Memory(const char*,int,const void*,int,int);
    virtual void Child(const char*,int,const void*);
    virtual void Slot10();
    virtual void Slot14();
    virtual void End();
};
struct View557 {
    void* table;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    Detail557* details;
    int count,capacity;
    void hkpPhantom_calcContentStatistics(Collector557*) const;
};
// pdb: hkpCachingShapePhantom::calcContentStatistics | hkpCachingShapePhantom.obj | fnv360_0822_retail, ustr, high
// pdb params: collector, cls
// pdb: hkpCachingShapePhantom::calcContentStatistics | hkpCachingShapePhantom.obj | fnv360_0822_retail, ustr, high (was: AddToCollector)
void hkpCachingShapePhantomD4CD::hkpCachingShapePhantom_calcContentStatistics(hkStatisticsCollectorD4CD* collector) const throw() {
    const View557* self=reinterpret_cast<const View557*>(this);
    Collector557* out=reinterpret_cast<Collector557*>(collector);
    out->Begin(&DAT_00e801c8,2,self);
    self->hkpPhantom_calcContentStatistics(out);
    if((self->capacity & 0x80000000u)==0) {
        int allocated=self->capacity & 0x3fffffff;
        allocated+=allocated;allocated+=allocated;allocated+=allocated;
        int used=self->count;
        used+=used;used+=used;used+=used;
        out->Memory(&DAT_00e801bc,8,self->details,used,allocated);
    }
    for(int i=0;i<self->count;++i)out->Child(&DAT_00e7eb64,8,self->details[i].agent);
    out->End();
}


class hkMemoryAllocatorD4D0
{
  public:
    virtual ~hkMemoryAllocatorD4D0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> T* _bufAlloc(int& iReqNumInOut)
    {
        int n = iReqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        iReqNumInOut = n / (int)sizeof(T);
        return (T*)p;
    }
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4D0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4D0* m_pStreamAllocator;
    hkMemoryAllocatorD4D0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4D0& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD4D0(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayD4D0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void operator=(const hkArrayD4D0& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorD4D0& kAlloc, const hkArrayD4D0& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyD4D0(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4D4D0
{
    hkReal x, y, z, w;
};

struct hkTransformD4D0
{
    hkVector4D4D0 m_kColumn0;
    hkVector4D4D0 m_kColumn1;
    hkVector4D4D0 m_kColumn2;
    hkVector4D4D0 m_vTranslation;
};

class hkpShapeD4D0;
class hkpPhantomOverlapListenerD4D0;
class hkpPhantomListenerD4D0;

struct hkpCollidableD4D0
{
    const hkpShapeD4D0* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeD4D0* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectD4D0
{
  public:
    virtual ~hkpWorldObjectD4D0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableD4D0 m_kCollidable;

    const hkpCollidableD4D0* getCollidable() const
    {
        return &m_kCollidable;
    }
    void CopyEntriesFrom(const hkpWorldObjectD4D0* pkOtherObj) throw();
};

class FUN_00d4ce10 : public hkpWorldObjectD4D0
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObjectD4D0* p = (hkpWorldObjectD4D0*)FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayD4D0<hkpPhantomOverlapListenerD4D0*> m_kPhantomOverlapListeners;
    hkArrayD4D0<hkpPhantomListenerD4D0*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkTransformD4D0 m_kMotionTransform;
    char m_padF0[0x80];

    const hkTransformD4D0& getTransform() const
    {
        return m_kMotionTransform;
    }

    FUN_00d4ce10(const hkpShapeD4D0* pkShape, const hkTransformD4D0& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectD4D0* FUN_00d4d0d0() const throw();
};

typedef char fnv_check_d4d0d0[(sizeof(FUN_00d4ce10) == 0x170) ? 1 : -1];

namespace fnv_00d4d310 {
struct FnvCpu_FUN_00d4d310_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d4d310_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d4d310_CpuAllocator* allocator;
};
FnvCpu_FUN_00d4d310_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d4d310

#include <xmmintrin.h>

extern int DAT_010ccebc;

struct hkBool_d4cc
{
    char m_cBooleanValue;
    hkBool_d4cc(bool b) : m_cBooleanValue(b)
    {}
    hkBool_d4cc(const hkBool_d4cc& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};

struct Visitor_d4cc
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14;
};

struct Listener_d4cc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void visit(Visitor_d4cc* v);
};

struct Entry_d4cc
{
    Listener_d4cc* m_kListener;
    void* m_object;
};

inline void memCpy4_d4cc(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d4cc
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d4cc(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Owned_d4cc
{
    int m_00;
};

struct World_d4cc
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArray_d4cc<Entry_d4cc> m_entries;
    unsigned char m_bValueAt0C;
    void NotifyAll(Owned_d4cc* obj, hkBool_d4cc found);
    void FUN_00d4cca0(Owned_d4cc* obj);
};

// Removes the first entry whose m_object matches obj, notifying listeners via NotifyAll and visit, and sets m_bValueAt0C on success.
// @f3 0x009d95c0 (community match, verified in this file)
extern int DAT_00e7d9c4;
struct hkArrayFn_d4cc
{
    Entry_d4cc* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct WorldFn_d4cc
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    hkArrayFn_d4cc m_entries;
    unsigned char m_bValueAt0C;
};
// pdb: hkpCachingShapePhantom::removeOverlappingCollidable | hkpCachingShapePhantom.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: collidable
void World_d4cc::FUN_00d4cca0(Owned_d4cc* apOwned)
{
    Visitor_d4cc visitor;
    WorldFn_d4cc* self = reinterpret_cast<WorldFn_d4cc*>(this);
    visitor.m_sReferenceCount = 1;
    visitor.m_vtbl = &DAT_00e7d9c4;
    if (!apOwned->m_00)
        return;
    for (int i = self->m_entries.m_iElementCount - 1; i >= 0; i--)
    {
        if (self->m_entries.m_data[i].m_object == apOwned)
        {
            NotifyAll(apOwned, hkBool_d4cc(true));
            Listener_d4cc* listener = self->m_entries.m_data[i].m_kListener;
            if (listener)
                listener->visit(&visitor);
            int last = --self->m_entries.m_iElementCount;
            Entry_d4cc* data = self->m_entries.m_data;
            data[i] = data[last];
            return;
        }
    }
    NotifyAll(apOwned, hkBool_d4cc(false));
}


class hkpCollidable;

void ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();

template <typename T> struct hkArrayD4CF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& _expandOne(hkMemoryAllocatorD4D0& kAlloc)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        return m_data[m_iElementCount++];
    }
    T& AllocatePair()
    {
        return _expandOne(FUN_00c85750().heap());
    }
};

struct hkpProcessCollisionInputD4CF;
struct hkpCollisionAgentD4CF;
typedef hkpCollisionAgentD4CF*(__cdecl* hkpCreateAgentFuncD4CF)(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                                const hkpProcessCollisionInputD4CF& kInput,
                                                                void* pvMgr);

struct hkpAgentFuncsD4CF
{
    hkpCreateAgentFuncD4CF m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};

struct hkpCollisionQualityInfoD4CF
{
    int m_unk00;
};

struct hkpCollisionDispatcherD4CF
{
    int m_unk000, m_unk004, m_unk008, m_unk00c, m_unk010, m_unk014, m_unk018, m_unk01c;
    int m_unk020, m_unk024, m_unk028, m_unk02c, m_unk030, m_unk034, m_unk038, m_unk03c;
    int m_unk040, m_unk044, m_unk048, m_unk04c, m_unk050, m_unk054, m_unk058, m_unk05c;
    int m_unk060, m_unk064, m_unk068, m_unk06c, m_unk070, m_unk074, m_unk078, m_unk07c;
    int m_unk080, m_unk084, m_unk088, m_unk08c, m_unk090, m_unk094, m_unk098, m_unk09c;
    int m_unk0a0, m_unk0a4, m_unk0a8, m_unk0ac, m_unk0b0, m_unk0b4, m_unk0b8, m_unk0bc;
    int m_unk0c0, m_unk0c4, m_unk0c8, m_unk0cc, m_unk0d0, m_unk0d4, m_unk0d8, m_unk0dc;
    int m_unk0e0, m_unk0e4, m_unk0e8, m_unk0ec, m_unk0f0, m_unk0f4, m_unk0f8, m_unk0fc;
    int m_unk100, m_unk104, m_unk108, m_unk10c, m_unk110, m_unk114, m_unk118, m_unk11c;
    int m_unk120, m_unk124, m_unk128, m_unk12c, m_unk130, m_unk134, m_unk138, m_unk13c;
    int m_unk140, m_unk144, m_unk148, m_unk14c, m_unk150, m_unk154, m_unk158, m_unk15c;
    int m_unk160, m_unk164, m_unk168, m_unk16c, m_unk170, m_unk174, m_unk178, m_unk17c;
    int m_unk180, m_unk184, m_unk188, m_unk18c, m_unk190, m_unk194, m_unk198, m_unk19c;
    hkUint8 m_agent2TypeMap[32][32];
    hkUint8 m_agent3TypeMap[32][32];
    hkpAgentFuncsD4CF m_agent2Funcs[240];
    hkpCollisionQualityInfoD4CF m_pCollisionQualityInfo[1];

    hkpCreateAgentFuncD4CF getNewCollisionAgentFunc(int iTypeA, int iTypeB, int iPredictive) const
    {
        const hkUint8* pTypes = iPredictive ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
        int iIdx = pTypes[iTypeA * 32 + iTypeB];
        return m_agent2Funcs[iIdx].m_pCreateFunc;
    }
    hkpCollisionAgentD4CF* getNewCollisionAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                const hkpProcessCollisionInputD4CF& kInput, void* pvMgr) const;
    hkpCollisionQualityInfoD4CF* getCollisionQualityInfo(int iIndex)
    {
        return &m_pCollisionQualityInfo[iIndex];
    }
};

struct __declspec(align(16)) hkVector4D4CF
{
    hkReal x, y, z, w;
};

struct hkpCollisionInputD4CF
{
    hkpCollisionDispatcherD4CF* m_pCollisionDispatcher;
    hkUint32 m_collisionQuality;
    hkUint32 m_forceAcceptContactPoints;
    hkReal m_fScalar;
    const void* m_iFilter;
    hkUint32 m_bCreatePredictiveAgents;
    hkVector4D4CF m_kAabbMin;
    hkVector4D4CF m_kAabbMaximum;
    hkVector4D4CF m_kAabbScale;
};

struct hkpProcessCollisionInputD4CF : public hkpCollisionInputD4CF
{
    hkReal m_uiStartTime;
    hkReal m_fEndTime;
    hkReal m_fTimeStep;
    hkReal m_fInverseDeltaTime;
    hkpCollisionQualityInfoD4CF* m_pCollisionQualityInfo;
    void* m_pAgent1nSector;
    void* m_pCollisionFilter;
    hkBool m_bEnableDeprecatedWelding;
    hkBool m_bAllowToSkipConfirmedCallbacks;
    void* m_pConfiguration;

    hkpProcessCollisionInputD4CF(const hkpProcessCollisionInputD4CF& kOther) throw() : hkpCollisionInputD4CF(kOther)
    {
        m_pAgent1nSector = 0;
        FUN_00cfa7d0(kOther);
    }
    ~hkpProcessCollisionInputD4CF() throw()
    {
        if (m_pAgent1nSector)
            FUN_00c85750().heap().ReleaseBlock(m_pAgent1nSector, 0x200);
    }
    void FUN_00cfa7d0(const hkpProcessCollisionInputD4CF& kOther);
};

#include <string.h>
extern int DAT_010ccebc;

struct VFn20Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(void* a, int b, int* c, void* d);
};

struct PairDC4A30
{
    VFn20Obj* m_obj;
    int m_data;
};

__declspec(align(8)) struct QueryDC4A30
{
    int m_pOwningWorld;
    hkUint16 m_unk04;
    hkUint16 m_type;
    hkUint64 m_unk08;
    hkUint64 m_unk10;
};

struct Ca30Derived : public hkpCachingShapePhantomStandIn
{
    void __thiscall QueryCollisionDetails();
};

// Copies 0x50 bytes from the pointer at (this->8)+0x78 into a local buffer, then calls v20 on each collision detail entry with it and a type-1 query.
// @f3 0x009d9670 (community match, verified in this file)
extern int DAT_00e7d9c4;

// pdb: hkpCachingShapePhantom::updateShapeCollectionFilter | hkpCachingShapePhantom.obj | fnv360_0822_retail, objrun_open, low
void Ca30Derived::QueryCollisionDetails()
{
    QueryDC4A30 query;
    __declspec(align(16)) int buffer[20];

    char* container = *(char**)((char*)this + 8);
    char* src = *(char**)(container + 0x6c);
    memcpy(buffer, src, 0x50);

    query.m_type = 1;
    query.m_pOwningWorld = (int)&DAT_00e7d9c4;

    for (int i = 0; i < *(int*)((char*)this + 0x154); ++i)
    {
        PairDC4A30* pair = (PairDC4A30*)*(char**)((char*)this + 0x150) + i;
        pair->m_obj->v20((char*)this + 0x10, pair->m_data, buffer, &query);
    }
}


namespace fnv_00d4d030 {
class hkMemoryAllocatorD4D0
{
  public:
    virtual ~hkMemoryAllocatorD4D0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4D0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD4D0* m_pStreamAllocator;

    hkMemoryAllocatorD4D0& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD4D0 {
extern "C" hkMemoryRouterD4D0& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayD4D0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        hkMemoryAllocatorD4D0& alloc = hkRouterD4D0::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

}  // namespace fnv_00d4d030

namespace CastSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float f[4];
    unsigned __int64 u[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    float _mm_cvtss_f32(__m128);
}
}

extern float DAT_0104da4c;

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

class hkpShape : public hkReferencedObject
{
  public:
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void getAabb(const hkTransform& transform, hkReal floatTolerance, hkAabb& out) const;
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    int m_unk04;
    union
    {
        hkReal m_fScalar;
        int m_toleranceInt;
    };
    void* m_unk0c;
    void* m_unk10;
    int m_unk14;
    int m_pad18;
    int m_pad1c;
    hkVector4 m_v0;
    hkVector4 m_v1;
    hkVector4 m_v2;
};

struct GskAgentInput : public CollisionAgentContext
{
    int m_pad50;
    int m_pad54;
    int m_pad58;
    int m_pad5c;
    int m_pad60;
    int m_pad64;
    int m_pad68;
    int m_pad6c;
    void* m_pConfiguration;
};

struct ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_path;
    hkReal m_fMaxExtraPenetration;
    hkReal m_cachedDistances;
    void* m_pConfiguration;

    __forceinline ShapeSweepParameters()
    {
        m_fMaxExtraPenetration = DAT_0104da4c;
        m_unk04 = 0;
    }
    __forceinline void set(const GskAgentInput& input)
    {
        m_pCollisionDispatcher = input.m_pCollisionDispatcher;
        m_unk04 = input.m_unk04;
        m_toleranceInt = input.m_toleranceInt;
        m_unk0c = input.m_unk0c;
        m_unk10 = input.m_unk10;
        m_unk14 = input.m_unk14;
        *(CastSimd::__m128*)&m_v0 = *(CastSimd::__m128*)&input.m_v0;
        *(CastSimd::__m128*)&m_v1 = *(CastSimd::__m128*)&input.m_v1;
        *(CastSimd::__m128*)&m_v2 = *(CastSimd::__m128*)&input.m_v2;
        m_pConfiguration = input.m_pConfiguration;
    }
};
