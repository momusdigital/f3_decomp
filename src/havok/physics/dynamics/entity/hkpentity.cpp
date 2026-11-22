#include "f3_common.h"
// src/havok/physics/dynamics/entity/hkpentity.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkpentity.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpEntity.h"

struct FUN_00c9c3c0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int GetEntryAt(int index);
};

struct CpuObject
{
    char* FUN_00c9c030();
};

namespace fnv_00c9c3f0 {
struct CpuObject
{
    char* FUN_00c9c3f0();
};
}  // namespace fnv_00c9c3f0

struct FUN_00c9bfa0_Inner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    int m_78;
};

struct FUN_00c9bfa0_Class
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c9bfa0_Inner* m_08;
    unsigned int unk0C;
    int m_10;
    void FUN_00c9bfa0();
};

// If m_08 and m_10 are set, calls FUN_00d1a330 with m_08->m_78, a pointer to this, and 1.
// @f3 0x0090af70 (community match, verified in this file)
void __cdecl FUN_0099a2d0(int a1, int* a2, int a3);
// pdb: hkpEntity::updateCachedAabb | hkpEntity.obj | fnv360_0822_debug, caller_sim, low
void FUN_00c9bfa0_Class::FUN_00c9bfa0()
{
    if (m_08 && m_10)
    {
        FUN_00c9bfa0_Class* self = this;
        FUN_0099a2d0(m_08->unk6C, (int*)&self, 1);
    }
}


struct hkWorldOperationBaseC9C3
{
    unsigned char m_type;
};

class hkpEntityC9C3;

struct hkWorldOperationC9C3 : public hkWorldOperationBaseC9C3
{
    hkpEntityC9C3* m_pEntity;

    hkWorldOperationC9C3()
    {
        m_type = 0x21;
    }
};

class hkpWorldC9C3
{
  public:
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_iCriticalOperationsLockCount;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount != 0;
    }
    void FUN_00c91160(const hkWorldOperationBaseC9C3& kOperation) throw();
};

class hkpEntityC9C3
{
  public:
    int unk00;
    int unk04;
    hkpWorldC9C3* m_pOwningWorld;

    void FUN_00c9c1d0();
    void FUN_00c9c300();
};

// @f3 0x0090b1d0 (community match, verified in this file)
struct WorldF3
{
    int unk[0x21];
    int m_iCriticalOperationsLockCount;
    void FUN_00902570(const hkWorldOperationBaseC9C3& kOperation);
};
struct EntityF3 { void FUN_0090b110(); };

void hkpEntityC9C3::FUN_00c9c300()
{
    WorldF3* world = (WorldF3*)m_pOwningWorld;
    if (world && world->m_iCriticalOperationsLockCount != 0)
    {
        hkWorldOperationC9C3 kOp;
        kOp.m_pEntity = this;
        world->FUN_00902570(kOp);
        return;
    }
    ((EntityF3*)this)->FUN_0090b110();
}


struct FUN_00c9c240_holder : public hkpEntity
{
    void FUN_00c9c240();
    void FUN_00c9c340();
};

struct FUN_00c9c390_Class
{
    char m_auiShapeKeys[0xac];
    int m_ac;
    unsigned short m_b0;
    int* m_b4;
    int GetEntry(int index);
};
// Returns the entry at index from the inline array when index is below m_b0, otherwise from the m_b4 array offset by m_b0.
// @f3 0x0090b220 (community match, verified in this file)
// pdb: hkpEntity::getConstraint | hkpEntity.obj | fnv360_0822_retail, call_gap, high
// pdb params: i
int FUN_00c9c390_Class::GetEntry(int index)
{
    if (index < *(unsigned short*)(m_auiShapeKeys + 0x9c))
        return ((int*)(*(int*)(m_auiShapeKeys + 0x98)))[(index + index * 2) * 4];
    return (*(int**)(m_auiShapeKeys + 0xa0))[index - *(unsigned short*)(m_auiShapeKeys + 0x9c)];
}


class GlobalObjectO2_00d472a0;

class hkStatisticsCollector
{
  public:
    virtual ~hkStatisticsCollector();
    virtual void beginObject(const char* name, const hkClass* cls, const void* obj);
    virtual void endObject();
    virtual void addChildObject(const char* name, const void* obj, int flags);
    virtual void AddObjectInstance(const char* name, const void* obj);
    virtual void AddMemoryChunk(int type, const char* name, const void* chunk, int usedSize, int allocatedSize);
    int unk04;
    int unk08;
    int unk0c;
    bool m_clearDontDeallocate;
};

class hkpEntityExtendedListeners
{
  public:
    hkpEntitySmallArraySerializeOverrideType m_kContactListenerArray;
    hkpEntitySmallArraySerializeOverrideType m_kEntityListenerArray;
};

class hkpEntityStats : public hkpEntity
{
  public:
    void WriteToStream(hkStatisticsCollector* collector, const GlobalObjectO2_00d472a0* cls) const;
    void hkpEntity_calcContentStatistics(hkStatisticsCollector* collector) const;
};

// Reports the entity's constraint, collision, listener and motion data to the statistics collector, skipping flagged arrays unless m_clearDontDeallocate is set.
// @f3 0x0090b350 (community match, verified in this file)
namespace N90b350
{
struct SmallArray
{
    void* m_data;
    unsigned short m_size;
    unsigned short m_capacityAndFlags;
};

struct ExtendedListeners
{
    SmallArray m_activationListeners;
    SmallArray m_entityListeners;
};

class StatisticsCollector
{
  public:
    virtual ~StatisticsCollector();
    virtual void beginObject(const char* name, int statClass, const void* object);
    virtual void addChunk(const char* name, int statClass, const void* chunk, int usedSize, int allocatedSize);
    virtual void addChildObject(const char* name, int statClass, const void* child);
    virtual void pushDir(const char* name);
    virtual void popDir();
    virtual void endObject();
};

struct Entity
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
    ExtendedListeners* m_extendedListeners;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
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
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    void* m_savedMotion;
    int unk1ec;
    SmallArray m_contactListeners;

    void hkpWorldObject_calcContentStatistics(StatisticsCollector* collector) const;
};

}

void __cdecl FUN_0097eef0(const void* object, N90b350::StatisticsCollector* collector, const void* cls);

// pdb: hkpEntity::calcContentStatistics | hkpEntity.obj | fnv360_0822_retail, ustr, high
// pdb params: collector, cls
// pdb: hkpEntity::calcContentStatistics | hkpEntity.obj | fnv360_0822_retail, ustr, high (was: CollectStats)
void hkpEntityStats::hkpEntity_calcContentStatistics(hkStatisticsCollector* statsCollector) const
{
    N90b350::StatisticsCollector* collector = (N90b350::StatisticsCollector*)statsCollector;
    const N90b350::Entity* self = (const N90b350::Entity*)this;

    collector->beginObject("Entity", 2, this);
    FUN_0097eef0(this, collector, 0);
    collector->beginObject("hkpRigidBody", 2, this);
    if ((self->m_contactListeners.m_capacityAndFlags & 0x8000) == 0)
    {
        collector->addChunk("CollisionListnr", 4, self->m_contactListeners.m_data,
                            self->m_contactListeners.m_size * 4,
                            (self->m_contactListeners.m_capacityAndFlags & 0x3fff) * 4);
    }
    if (self->m_extendedListeners)
    {
        collector->addChunk("ExtendedListenersStruct", 4, self->m_extendedListeners, 0x10, 0);
        const N90b350::SmallArray& entityListeners = self->m_extendedListeners->m_entityListeners;
        if ((entityListeners.m_capacityAndFlags & 0x8000) == 0)
        {
            collector->addChunk("EntityListeners", 4, entityListeners.m_data, entityListeners.m_size * 4,
                                (entityListeners.m_capacityAndFlags & 0x3fff) * 4);
        }
        const N90b350::SmallArray& activationListeners = self->m_extendedListeners->m_activationListeners;
        if ((activationListeners.m_capacityAndFlags & 0x8000) == 0)
        {
            collector->addChunk("ActivatonListners", 4, activationListeners.m_data, activationListeners.m_size * 4,
                                (activationListeners.m_capacityAndFlags & 0x3fff) * 4);
        }
    }
    self->hkpWorldObject_calcContentStatistics(collector);
    collector->addChildObject("SavedMotion", 4, self->m_savedMotion);
    collector->endObject();
}


void __cdecl hkSmallArrayUtil__reserveMore(void* array, int elemSize);

template <typename T> class hkSmallArrayC9C5
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    unsigned short getCapacity() const
    {
        return (unsigned short)(m_iCapacityState & 0x3fff);
    }
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void AddBack(const T& t)
    {
        if (m_iElementCount == getCapacity())
            hkSmallArrayUtil__reserveMore(this, sizeof(T));
        m_data[m_iElementCount++] = t;
    }
};

class hkOwnerC9C5
{
  public:
    int unk000[0x80];
    hkSmallArrayC9C5<void*> m_slots;

    void hkpEntity_addContactListener(void* p);
};

// Finds the first null entry in m_slots and replaces it with p, or appends p if no null entry exists.
// @f3 0x0090b490 (community match, verified in this file)
namespace f3m_0090b490 { void __cdecl FUN_0098a9f0(void* array, int elemSize); }
// pdb: hkpEntity::addContactListener | hkpEntity.obj | fnv360_0822_retail, call_seq, high
// pdb params: cl
// pdb: hkpEntity::addContactListener | hkpEntity.obj | fnv360_0822_retail, call_seq, high (was: AddSlot)
void hkOwnerC9C5::hkpEntity_addContactListener(void* p) {
 hkSmallArrayC9C5<void*>& slots=((hkOwnerC9C5*)((char*)this-0x10))->m_slots;
 int i=((hkOwnerC9C5*)((char*)this-0x10))->m_slots.indexOf(0);
 if(i>=0) slots.m_data[i]=p;
 else {
  if(slots.m_iElementCount==slots.getCapacity()) f3m_0090b490::FUN_0098a9f0(&slots,sizeof(void*));
  slots.m_data[slots.m_iElementCount++]=p;
 }
}


class hkpShape;
class hkLocalFrame;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;

extern const int DAT_010c6c64;
extern const int DAT_010c6f7c;

struct hkpMaterialC9CC : public hkpMaterial
{
    hkpMaterialC9CC()
    {
        m_fSlipAngle = 0.5f;
        m_fElasticity = 0.4f;
    }
};

struct hkSmallArrayC9CC : public hkpEntitySmallArraySerializeOverrideType
{
    hkSmallArrayC9CC()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x8000;
    }
};

template <class T> struct hkArrayC9CC : public hkArray<T>
{
    hkArrayC9CC()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct hkpSpuCollisionCallbackC9CC : public hkpEntitySpuCollisionCallback
{
    hkpSpuCollisionCallbackC9CC()
    {
        m_pCallbackData = 0;
        m_pRayCursor = 0;
        m_uiCallbackType = hkpEntity::SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS;
        m_bCallbackEnabled = 1;
    }
};

class __declspec(novtable) hkpMaxSizeMotionC9CC : public hkpMaxSizeMotion
{
  public:
    hkpMaxSizeMotionC9CC()
    {
        m_pSavedMotion = 0;
        *(const int**)this = &DAT_010c6c64;
    }
};

template <class T> struct hkRefPtrC9CC
{
    T* m_pRetainedObject;
    hkRefPtrC9CC() : m_pRetainedObject(0)
    {}
};

class FUN_00cd2ce0 : public hkpWorldObject
{
  public:
    FUN_00cd2ce0(const hkpShape* pkShape, int iType) throw();
};

class __declspec(novtable) hkpEntityBaseC9CC : public FUN_00cd2ce0
{
  public:
    hkpEntityBaseC9CC(const hkpShape* pkShape) throw() : FUN_00cd2ce0(pkShape, hkpWorldObject::BROAD_PHASE_ENTITY)
    {
        *(const int**)this = &DAT_010c6f7c;
    }
};

class __declspec(novtable) FUN_00c9cce0 : public hkpEntityBaseC9CC
{
  public:
    hkpMaterialC9CC m_iMaterialIndex;
    void* m_pEntityUserData;
    hkReal m_fBulletSpread;
    void* m_pShape;
    hkUint32 m_uiFilterInfo;
    hkUint16 m_usStorageIndex;
    hkUint16 m_usNextProcessCallbackDelay;
    hkSmallArrayC9CC m_eSmallArraySerializeOverrideType;
    hkArrayC9CC<hkpConstraintInstance*> m_kSlaveConstraints;
    hkArrayC9CC<hkUint8> m_pByteBuffer;
    void* m_pSimulationIsland;
    hkInt8 m_iAutoRemoveLevel;
    hkUint8 m_ucNumShapeKeysInContactPointProperties;
    hkUint8 m_ucResponseModifierFlags;
    hkUint32 m_uiUniqueId;
    hkpSpuCollisionCallbackC9CC m_kSpuCollisionCallback;
    hkpMaxSizeMotionC9CC m_pMotionState;
    hkSmallArrayC9CC m_kContactListeners;
    hkSmallArrayC9CC m_ppActions;
    hkRefPtrC9CC<hkLocalFrame> m_pLocalFrame;
    hkpEntityExtendedListeners* m_pExtendedListeners;

    FUN_00c9cce0(const hkpShape* pkShape) throw();
};

extern int DAT_010c59f4;

struct FnvCpu_FUN_00c9d160_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00c9d160_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00c9d160_CpuAllocator* allocator;
};
FnvCpu_FUN_00c9d160_CpuAllocatorHolder* __cdecl FUN_00c85750();

extern int DAT_010c59f4;

inline void* operator new(unsigned int, void* p)
{
    return p;
}
class MotionGravityBase : public hkpKeyframedRigidMotion
{
  public:
    explicit MotionGravityBase(int initialize)
    {
        if (initialize)
        {
            float gravityFactor = 1.0f;
            volatile short& storedGravityFactor = m_fGravityFactor;
            storedGravityFactor = static_cast<short>(*reinterpret_cast<int*>(&gravityFactor) >> 16);
        }
    }
};
class KeyframedMotionReset : public MotionGravityBase
{
  public:
    explicit KeyframedMotionReset(int initialize) : MotionGravityBase(initialize)
    {}
    KeyframedMotionReset* FUN_00c9d1c0(int initialize);
};

class hkMemoryAllocatorC9D3
{
  public:
    virtual ~hkMemoryAllocatorC9D3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterC9D3
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorC9D3* m_pStreamAllocator;
    hkMemoryAllocatorC9D3& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterC9D3 {
extern "C" hkMemoryRouterC9D3& __cdecl FUN_00c85750() throw();
}

template <typename T> inline void hkDeallocateChunkC9D3(T* p, int n)
{
    hkRouterC9D3::FUN_00c85750().heap().ReleaseBlock(p, n * sizeof(T));
}

template <typename T> class hkSmallArrayC9D3
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    ~hkSmallArrayC9D3() throw()
    {
        if ((m_iCapacityState & 0x8000) == 0)
            hkDeallocateChunkC9D3(m_data, m_iCapacityState & 0x3fff);
    }
};

class FUN_00c9d340
{
  public:
    hkSmallArrayC9D3<void*> m_pHeadNode;
    hkSmallArrayC9D3<void*> m_iSecondInteger;

    ~FUN_00c9d340() throw();
};

// Destructor for a pair of small arrays; the body is empty because the member arrays free themselves.
// @fnv 0x00c9d340
FUN_00c9d340::~FUN_00c9d340() throw()
{}

namespace fnv_00c9d460 {
struct FnvCpu_FUN_00c9d460_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00c9d460_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00c9d460_CpuAllocator* allocator;
};
FnvCpu_FUN_00c9d460_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00c9d460

namespace fnv_00d1f780 {
class hkMemoryAllocatorD1F7
{
  public:
    virtual ~hkMemoryAllocatorD1F7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD1F7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD1F7* m_pStreamAllocator;
    hkMemoryAllocatorD1F7& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD1F7& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayD1F7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorD1F7& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

}  // namespace fnv_00d1f780

struct S00c92a80_Obj
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(int a, int b, void* c, void* d, int n);
};

struct __declspec(align(16)) S00c92a80_Range
{
    float lo;
    float hi;
    float range;
    float inv;
    S00c92a80_Range(float b, float a)
    {
        lo = a;
        hi = b;
        range = b - a;
        inv = range == 0.0f ? 0.0f : 1.0f / range;
    }
};

struct S00c92a80_cls
{
    int unk00;
    int unk04;
    S00c92a80_Obj* obj;
    void FUN_00c92a80(int a0, int a1);
};

// Reads a float from obj, builds a S00c92a80_Range, and calls obj->v1c with a0, a1, this, the range, and 1.
// @fnv 0x00c92a80
// pdb: hkpWorld::findInitialContactPoints | hkpWorld.obj | tesv_win, objrun_open, low
void S00c92a80_cls::FUN_00c92a80(int a0, int a1)
{
    float b = *(float*)((char*)obj + 0x18);
    float a = *(float*)((char*)obj + 0x18);
    S00c92a80_Range r(b, a);
    obj->v1c(a0, a1, this, &r, 1);
}

struct FUN_00c9bff0_Class
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
    void* m_cc;

    unsigned char* FUN_00c9bff0(unsigned char* out);
};

// Writes a 2-bit value extracted from byte 0x26 of m_cc into out, or 0 if m_cc is null.
// @f3 0x0090b0e0 (community match, verified in this file)
unsigned char* FUN_00c9bff0_Class::FUN_00c9bff0(unsigned char* out) {
    struct FlagSource {
        unsigned int unk00;
        unsigned int unk04;
        unsigned int unk08;
        unsigned int unk0c;
        unsigned int unk10;
        unsigned int unk14;
        unsigned int unk18;
        unsigned int unk1c;
        unsigned int unk20;
        unsigned short unk24;
        unsigned char flags;
    };
    FlagSource* source = (FlagSource*)unkb8;
    if (!source) {
        *out = 0;
        return out;
    }
    *out = (source->flags >> 2) & 3;
    return out;
}


class hkpShapeContainerC9C0
{
  public:
    virtual void vfn_00();
    virtual int GetNumChildShapes() const;
};

class hkpShapeC9C0
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkpShapeContainerC9C0* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};

struct hkpCollisionDispatcherC9C0
{
    int unk000[0x110 / 4];
    int m_shapeFlags[1];
};

struct hkpWorldC9C0
{
    int unk00[0x80 / 4];
    hkpCollisionDispatcherC9C0* m_pDispatcher;
};

class hkBoundingVolumeC9C0
{
  public:
    int m_dirty;
    int unk04, unk08, unk0C;
    int m_pChildShapeAabbs;
    int unk14, unk18, unk1C, unk20;
    int m_data;

    void FreeStorage();
    void FUN_00d01ae0(int iNumChildren);
    void Reset(int iNumChildren)
    {
        FUN_00d01ae0(iNumChildren);
        m_dirty = 1;
        m_pChildShapeAabbs = 0;
    }
};

class hkpEntityC9C0
{
  public:
    int unk00[0x30 / 4];
    hkBoundingVolumeC9C0 m_boundingVolume;
    int unk58[(0xe8 - 0x58) / 4];
    unsigned char m_bFlag;

    void FUN_00c9bfa0();
    void UpdateBoundingVolume(const hkpWorldC9C0* pkWorld, const hkpShapeC9C0* pkShape);
};

// Frees the current bounding volume storage, then resets it from pkShape's container when the shape flags indicate a container shape.
// @f3 0x0090b280 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern "C" void _ReadWriteBarrier(void);

struct ShapeInfoC9C0
{
    virtual void vfn_00();
    virtual int vfn_04();
};

class hkpShapeC9C0Ex : public hkpShapeC9C0
{
  public:
    virtual ShapeInfoC9C0* vfn_14();
};

struct ShapeTypeTableC9C0
{
    int unk[0x110 / 4];
    int m_flags[1];
};

struct FUN_008f6d90_Holder
{
    void FUN_008f6d90(void* p, unsigned int size, int flags);
};

struct FUN_008f6d30_Holder
{
    void* FUN_008f6d30(unsigned int size, int flags);
};

// pdb: hkpEntity::getConstraintSlavesImpl | hkpEntity.obj | fnv360_0822_debug, objrun, low, conflict (bridge: hkpEntity::setCachedShapeData)
void hkpEntityC9C0::UpdateBoundingVolume(const hkpWorldC9C0* pkWorld, const hkpShapeC9C0* pkShape)
{
    char* p = (char*)this;
    int oldData = *(int*)(p + 0x54);
    if (oldData != 0)
    {
        unsigned long g = DAT_010f3170;
        _ReadWriteBarrier();
        unsigned int oldCount = *(unsigned short*)(p + 0x50);
        FUN_008f6d90_Holder* alloc = (FUN_008f6d90_Holder*)DAT_00d9b080(g);
        alloc->FUN_008f6d90((void*)oldData, oldCount << 5, 2);
        *(unsigned short*)(p + 0x50) = 0;
        *(int*)(p + 0x54) = 0;
    }
    if (pkWorld == 0)
        return;
    if (pkShape == 0)
        return;
    ShapeTypeTableC9C0* table = (ShapeTypeTableC9C0*)pkWorld->unk00[0x74 / 4];
    int flags = table->m_flags[pkShape->m_type];
    unsigned char bl = 0;
    ShapeInfoC9C0* info = 0;
    if (flags & 0x100)
    {
        info = ((hkpShapeC9C0Ex*)pkShape)->vfn_14();
    }
    else if (flags & 0x200)
    {
        info = ((hkpShapeC9C0Ex*)pkShape)->vfn_14();
        bl = 1;
    }
    else
    {
        return;
    }
    unsigned char c = (unsigned char)unk58[32];
    if (c == 7 || c == 6)
    {
        if (bl)
            return;
    }
    int num = info->vfn_04();
    *(unsigned short*)(p + 0x50) = (unsigned short)num;
    FUN_008f6d30_Holder* alloc2 = (FUN_008f6d30_Holder*)DAT_00d9b080(DAT_010f3170);
    *(int*)(p + 0x54) = (int)alloc2->FUN_008f6d30((unsigned int)num << 5, 2);
    *(int*)(p + 0x30) = 1;
    *(int*)(p + 0x40) = 0;
}


namespace fnv_00c9c0f0 {
template <class T> class hkSmallArrayC9C0
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
};

class hkpListenerC9C0;

class hkpWorldC9C0
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210;
    hkSmallArrayC9C0<hkpListenerC9C0*>* m_kListeners;

    void RemoveListener(hkpListenerC9C0* listener);
};

}  // namespace fnv_00c9c0f0

template <class T> class hkSmallArrayC9C1
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkOwnerC9C1
{
  public:
    int unk000[128];
    hkSmallArrayC9C1<void*> m_entries;

    void FUN_00c9c140(void* entry);
};

// Sets the entry at the index found by indexOf to 0 in m_entries.
// @f3 0x0090b020 (community match, verified in this file)
namespace Task1479 {
struct View { int padding[124]; hkSmallArrayC9C1<void*> entries; };
}
// pdb: hkpEntity::removeContactListener | hkpEntity.obj | fnv360_0721_beta, call_seq, low, conflict (skyrim: hkpTriggerVolume::triggerBodyLeftWorld)
// pdb params: cl
void hkOwnerC9C1::FUN_00c9c140(void* entry) {
 Task1479::View* self=(Task1479::View*)this;
 self->entries.m_data[self->entries.indexOf(entry)]=0;
}


struct hkBoolC9C
{
    char m_cBooleanValue;
    hkBoolC9C(char b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkpSimulationIslandC9C
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
    unsigned short unk24;
    unsigned char m_isSparse : 1;
    unsigned char m_bActionListCleanupNeeded : 1;
    unsigned char m_bActiveMark : 2;
    hkBoolC9C isActive() const
    {
        return hkBoolC9C(m_bActiveMark);
    }
};

struct hkpWorldC9C
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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    unsigned char unk304;
    unsigned char m_bWantDeactivation;
    unsigned char m_frameA;
    unsigned char m_frameB;
};

void __cdecl AddEntryToList(hkpWorldC9C* world, hkpSimulationIslandC9C* island);

class hkpMotionC9C
{
  public:
    virtual ~hkpMotionC9C();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];

    void hkpMotion_setWorldSelectFlagsNeg(int a, int b, int c);
};

class hkpEntityC9C
{
  public:
    virtual ~hkpEntityC9C();
    int unk04;
    hkpWorldC9C* m_pOwningWorld;
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    hkpSimulationIslandC9C* m_pSimulationIsland;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotionC9C m_pMotionState;

    void FUN_00c9c1d0();
};

// @f3 0x0090b500 (community match, verified in this file)
struct hkpWorldC9CF3
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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    unsigned char unk2C4;
    unsigned char m_bWantDeactivation;
    unsigned char m_frameA;
    unsigned char m_frameB;
};
class hkpEntityC9CF3
{
  public:
    virtual ~hkpEntityC9CF3();
    int unk04;
    hkpWorldC9CF3* m_pOwningWorld;
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
    hkpSimulationIslandC9C* m_pSimulationIsland;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    hkpMotionC9C m_pMotionState;
};
// pdb: hkpEntity::activate | hkpEntity.obj | fnv360_0822_retail, call_dedup, low
void hkpEntityC9C::FUN_00c9c1d0()
{
    hkpEntityC9CF3* self = (hkpEntityC9CF3*)this;
    hkBoolC9C active(0);
    if (self->m_pSimulationIsland)
        active = self->m_pSimulationIsland->isActive();
    if (!active && self->m_pMotionState.m_type != 7 && self->m_pOwningWorld)
    {
        self->m_pMotionState.m_ausDeactivationNumInactiveFrames[0] = 0;
        self->m_pMotionState.m_ausDeactivationNumInactiveFrames[1] = 0;
        AddEntryToList((hkpWorldC9C*)self->m_pOwningWorld, self->m_pSimulationIsland);
        self->m_pMotionState.hkpMotion_setWorldSelectFlagsNeg(self->m_pOwningWorld->m_bWantDeactivation, self->m_pOwningWorld->m_frameA,
                                         self->m_pOwningWorld->m_frameB);
    }
}


class hkMemoryAllocatorC9C6
{
  public:
    virtual ~hkMemoryAllocatorC9C6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterC9C6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorC9C6* m_pStreamAllocator;
    hkMemoryAllocatorC9C6& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterC9C6& __cdecl FUN_00c85750() throw();
}

template <class T> class hkSmallArrayC9C6
{
  public:
    hkSmallArrayC9C6() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

struct ListenersC9C6
{
    static void* operator new(unsigned int nbytes)
    {
        return fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
    }

    hkSmallArrayC9C6<void*> m_pHeadNode;
    hkSmallArrayC9C6<void*> m_iSecondInteger;
};

class HostC9C6
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210;
    ListenersC9C6* m_pkListeners;

    void FUN_00c9c670(void* pvListener);
};

// Ensures m_pkListeners is allocated, then nulls the entry for pvListener in m_pkListeners->m_iSecondInteger.
// @f3 0x0090b960 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
extern "C" void* __stdcall FUN_008f6800(int, int);
struct Tls_w152_f3
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
    void* freeHead;
    int freeCount;
};
struct Listeners_w152_f3
{
    hkSmallArrayC9C6<void*> m_pHeadNode;
    hkSmallArrayC9C6<void*> m_iSecondInteger;
};
struct Host_w152_f3
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
    Listeners_w152_f3* m_pkListeners;
};
// pdb: hkpEntity::removeEntityListener | hkpEntity.obj | fnv360_0822_retail, call_gap, low
// pdb params: el
void HostC9C6::FUN_00c9c670(void* pvListener)
{
    Host_w152_f3* self = (Host_w152_f3*)this;
    if (!self->m_pkListeners)
    {
        Tls_w152_f3* tls = (Tls_w152_f3*)DAT_00d9b080(DAT_010f3170);
        void* mem = tls->freeHead;
        if (mem)
        {
            tls->freeCount--;
            tls->freeHead = *(void**)mem;
        }
        else
        {
            mem = FUN_008f6800(2, 4);
        }
        Listeners_w152_f3* p = (Listeners_w152_f3*)mem;
        if (mem)
        {
            p->m_pHeadNode.m_data = 0;
            p->m_pHeadNode.m_iElementCount = 0;
            p->m_pHeadNode.m_iCapacityState = 0x8000;
            p->m_iSecondInteger.m_data = 0;
            p->m_iSecondInteger.m_iElementCount = 0;
            p->m_iSecondInteger.m_iCapacityState = 0x8000;
        }
        else
        {
            p = 0;
        }
        self->m_pkListeners = p;
    }
    hkSmallArrayC9C6<void*>& kArray = self->m_pkListeners->m_iSecondInteger;
    kArray[kArray.indexOf(pvListener)] = 0;
}


namespace fnv_00c9c7c0 {
class hkMemoryAllocatorC9C7;

struct hkMemoryRouterC9C7
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorC9C7* m_pStreamAllocator;
    hkMemoryAllocatorC9C7& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterC9C7& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorC9C7& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayC9C7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorC9C7& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

}  // namespace fnv_00c9c7c0

class hkLocalFrame;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;
extern int DAT_010c59f4;
extern const int DAT_010c6c64;
extern const int DAT_010c6f7c;
struct hkSmallArrayC9CE : public hkpEntitySmallArraySerializeOverrideType
{
    hkSmallArrayC9CE()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x8000;
    }
};
template <class T> struct hkArrayC9CE : public hkArray<T>
{
    hkArrayC9CE()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};
inline void setHalfC9CE(hkHalf& kHalf, const float& f)
{
    int t = ((const int*)&f)[0];
    kHalf = hkHalf(t >> 16);
}
class __declspec(novtable) hkpMotionC9CE : public hkpMaxSizeMotion
{
  public:
    hkpMotionC9CE(int flag)
    {
        *(int**)this = &DAT_010c59f4;
        if (flag)
            setHalfC9CE(m_fGravityFactor, 1.0f);
    }
};
class __declspec(novtable) hkpMaxSizeMotionC9CE : public hkpMotionC9CE
{
  public:
    hkpMaxSizeMotionC9CE(int flag) : hkpMotionC9CE(flag)
    {
        *(const int**)this = &DAT_010c6c64;
    }
};
class FUN_00c9d1c0
{
  public:
    FUN_00c9d1c0(int flag) throw();
};
class FUN_00c9d130
{
  public:
    FUN_00c9d130(int flag) throw();
};
class FUN_00c9d1f0
{
  public:
    FUN_00c9d1f0(int flag) throw();
};
class FUN_00c9d220
{
  public:
    FUN_00c9d220(int flag) throw();
};
class FUN_00cd2c50 : public hkpWorldObject
{
  public:
    FUN_00cd2c50(int flag) throw();
};
class __declspec(novtable) hkpEntityBaseC9CE : public FUN_00cd2c50
{
  public:
    hkpEntityBaseC9CE(int flag) throw() : FUN_00cd2c50(flag)
    {
        *(const int**)this = &DAT_010c6f7c;
    }
};
class __declspec(novtable) FUN_00c9ce00 : public hkpEntityBaseC9CE
{
  public:
    hkpMaterial m_iMaterialIndex;
    void* m_pEntityUserData;
    hkReal m_fBulletSpread;
    void* m_pShape;
    hkUint32 m_uiFilterInfo;
    hkUint16 m_usStorageIndex;
    hkUint16 m_usNextProcessCallbackDelay;
    hkSmallArrayC9CE m_eSmallArraySerializeOverrideType;
    hkArrayC9CE<hkpConstraintInstance*> m_kSlaveConstraints;
    hkArrayC9CE<hkUint8> m_pByteBuffer;
    void* m_pSimulationIsland;
    hkInt8 m_iAutoRemoveLevel;
    hkUint8 m_ucNumShapeKeysInContactPointProperties;
    hkUint8 m_ucResponseModifierFlags;
    hkUint32 m_uiUniqueId;
    hkpEntitySpuCollisionCallback m_kSpuCollisionCallback;
    hkpMaxSizeMotionC9CE m_pMotionState;
    hkSmallArrayC9CE m_kContactListeners;
    hkSmallArrayC9CE m_ppActions;
    hkLocalFrame* m_pLocalFrame;
    hkpEntityExtendedListeners* m_pExtendedListeners;

    FUN_00c9ce00(int flag) throw();
};

namespace fnv_00c9d130 {
struct FinishLoadedFlag
{
    int m_bFinishing;
};
struct PackedHalf
{
    short bits;
    void operator=(float f)
    {
        int value = *(int*)&f;
        bits = (short)(value >> 16);
    }
};
class FinishableBase
{
  public:
    FinishableBase(FinishLoadedFlag flag)
    {
        if (flag.m_bFinishing)
        {
            PackedHalf* scale = (PackedHalf*)((char*)this + 0x11e);
            *scale = 1.0f;
        }
    }
    virtual ~FinishableBase() throw();
};
class FUN_00c9d130 : public FinishableBase
{
  public:
    FUN_00c9d130(FinishLoadedFlag flag) throw();
    virtual ~FUN_00c9d130() throw();
};
}  // namespace fnv_00c9d130

namespace fnv_00c9d220 {
struct MotionCtorBase : public hkpMotion
{
    virtual ~MotionCtorBase();
    MotionCtorBase(int flag)
    {
        if (flag)
        {
            *reinterpret_cast<float*>(&flag) = 1.0f;
            volatile short& gravityFactor = m_fGravityFactor;
            gravityFactor = static_cast<short>(flag >> 16);
        }
    }
};
struct FUN_00c9d220 : public MotionCtorBase
{
    virtual ~FUN_00c9d220();
    FUN_00c9d220(int flag);
};
}  // namespace fnv_00c9d220

struct hkpLinkedCollidableD250
{
    unsigned int unk00[53];
    unsigned int m_uiUniqueId;
};

struct hkpAgentEntryD250
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_kCollidable[2];
    unsigned int unk1C, unk20, unk24, unk28, unk2C, unk30;
    unsigned int m_priority;
};

struct hkEntryLessD250
{
    unsigned int m_key;

    hkpLinkedCollidableD250* getPartner(const hkpAgentEntryD250* pkEntry) const
    {
        return reinterpret_cast<hkpLinkedCollidableD250*>(pkEntry->m_kCollidable[1] ^ pkEntry->m_kCollidable[0] ^
                                                          m_key);
    }

    bool operator()(const hkpAgentEntryD250* pkA, const hkpAgentEntryD250* pkB) const
    {
        if (pkA->m_priority < pkB->m_priority)
        {
            return true;
        }
        if (pkA->m_priority > pkB->m_priority)
        {
            return false;
        }
        return getPartner(pkA)->m_uiUniqueId < getPartner(pkB)->m_uiUniqueId;
    }
};

struct FUN_00c9c700_Array
{
    int* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
};

struct FUN_00c9c700_Class
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    FUN_00c9c700_Array* unk214;

    void __thiscall FUN_00c9c700(int value);
};

// Initializes the internal array if needed, then inserts value into the first empty slot or appends it, growing capacity when full.
// @f3 0x0090ba10 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_010f3170;
extern "C" void* __stdcall FUN_008f6800(int a, int b);
extern "C" void __cdecl FUN_0098a9f0(void* array, int elemSize);
struct FUN_00c9c700_Pool
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    void* unk48;
    int unk4C;
};
void FUN_00c9c700_Class::FUN_00c9c700(int value)
{
    if (unkCC == 0)
    {
        FUN_00c9c700_Pool* pool = (FUN_00c9c700_Pool*)TlsGetValue(DAT_010f3170);
        FUN_00c9c700_Array* array = (FUN_00c9c700_Array*)pool->unk48;
        if (array != 0)
        {
            pool->unk4C += -1;
            pool->unk48 = *(void**)array;
        }
        else
        {
            array = (FUN_00c9c700_Array*)FUN_008f6800(2, 4);
        }
        if (array != 0)
        {
            array->m_data = 0;
            array->m_iElementCount = 0;
            array->m_iCapacityState = 0x8000;
            array->unk08 = 0;
            array->unk0C = 0;
            array->unk0E = 0x8000;
        }
        else
        {
            array = 0;
        }
        unkCC = (int)array;
    }

    FUN_00c9c700_Array* array = (FUN_00c9c700_Array*)unkCC;
    int index = 0;

    if (0 < array->m_iElementCount)
    {
        int* data = array->m_data;
        int* p = data;
        do
        {
            if (*p == 0)
            {
                if (index >= 0)
                {
                    data[index] = value;
                    return;
                }
                break;
            }
            ++index;
            ++p;
        } while (index < ((FUN_00c9c700_Array*)unkCC)->m_iElementCount);
    }

    if (array->m_iElementCount == (array->m_iCapacityState & 0x3fff))
        FUN_0098a9f0(array, 4);

    array->m_data[array->m_iElementCount] = value;
    ++array->m_iElementCount;
}


struct hkBoolQ
{
    hkBoolQ(int b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

template <class T> struct hkArrayQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkpSimulationIslandQ
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char m_bSplitCheckRequested : 2;
    unsigned char m_bSparseEnabled : 2;
    unsigned char m_flags25hi : 4;
    unsigned char m_flags26lo : 2;
    unsigned char m_bActiveMark : 2;
    unsigned char m_flags26hi : 4;
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    hkArrayQ<hkpEntity*> m_kActorEntries;

    hkBoolQ isActive() const
    {
        return m_bActiveMark;
    }
};

void __cdecl PropagateStateToChildren(FUN_00c9c3c0_Class* world, hkpSimulationIslandQ* island);
void __cdecl AddItemToContainer(FUN_00c9c3c0_Class* world, hkpSimulationIslandQ* island);
// If the island is active: runs PropagateStateToChildren when split-check or sparse is set, sets each entity's reference position w to FLT_MAX, then calls AddItemToContainer.
// @f3 0x0090b110 (community match, verified in this file)
struct EntityView
{
    int m_unk000;
    int m_unk004;
    int m_unk008;
    int m_unk00C;
    int m_unk010;
    int m_unk014;
    int m_unk018;
    int m_unk01C;
    int m_unk020;
    int m_unk024;
    int m_unk028;
    int m_unk02C;
    int m_unk030;
    int m_unk034;
    int m_unk038;
    int m_unk03C;
    int m_unk040;
    int m_unk044;
    int m_unk048;
    int m_unk04C;
    int m_unk050;
    int m_unk054;
    int m_unk058;
    int m_unk05C;
    int m_unk060;
    int m_unk064;
    int m_unk068;
    int m_unk06C;
    int m_unk070;
    int m_unk074;
    int m_unk078;
    int m_unk07C;
    int m_unk080;
    int m_unk084;
    int m_unk088;
    int m_unk08C;
    int m_unk090;
    int m_unk094;
    int m_unk098;
    int m_unk09C;
    int m_unk0A0;
    int m_unk0A4;
    int m_unk0A8;
    int m_unk0AC;
    int m_unk0B0;
    int m_unk0B4;
    void* m_pSimulationIsland;
    int m_unk0BC;
    int m_unk0C0;
    int m_unk0C4;
    int m_unk0C8;
    int m_unk0CC;
    int m_unk0D0;
    int m_unk0D4;
    int m_unk0D8;
    int m_unk0DC;
    int m_unk0E0;
    int m_unk0E4;
    int m_unk0E8;
    int m_unk0EC;
    int m_unk0F0;
    int m_unk0F4;
    int m_unk0F8;
    int m_unk0FC;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10C;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11C;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12C;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13C;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14C;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15C;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16C;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17C;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18C;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19C;
    int m_unk1A0;
    int m_unk1A4;
    int m_unk1A8;
    int m_unk1AC;
    int m_unk1B0;
    int m_unk1B4;
    int m_unk1B8;
    int m_unk1BC;
    int m_unk1C0;
    int m_unk1C4;
    int m_unk1C8;
    float m_unk1CC;
    int m_unk1D0;
    int m_unk1D4;
    int m_unk1D8;
    float m_unk1DC;
};

// pdb: hkpEntity::deactivate | hkpEntity.obj | fnv360_0822_retail, caller_sim, low
void FUN_00c9c240_holder::FUN_00c9c240()
{
    EntityView* self = (EntityView*)this;
    hkpSimulationIslandQ* island = (hkpSimulationIslandQ*)self->m_pSimulationIsland;
    if (island)
    {
        unsigned char act = island->m_bActiveMark;
        unsigned char* pact = &act;
        if (*pact)
        {
            if (island->m_bSplitCheckRequested || island->m_bSparseEnabled)
            {
                FUN_00c9c3c0_Class* world = (FUN_00c9c3c0_Class*)m_pOwningWorld;
                int minIslandSize = world->m_a4;
                world->m_a4 = 0;
                ((hkpSimulationIslandQ*)self->m_pSimulationIsland)->m_bSparseEnabled = 0;
                ((hkpSimulationIslandQ*)self->m_pSimulationIsland)->m_bSplitCheckRequested = 1;
                PropagateStateToChildren((FUN_00c9c3c0_Class*)m_pOwningWorld,
                                         (hkpSimulationIslandQ*)self->m_pSimulationIsland);
                ((FUN_00c9c3c0_Class*)m_pOwningWorld)->m_a4 = minIslandSize;
            }
            island = (hkpSimulationIslandQ*)self->m_pSimulationIsland;
            int i = 0;
            if (island->m_kActorEntries.GetLogicalSize() > 0)
            {
                hkpEntity** entities = island->m_kActorEntries.m_data;
                do
                {
                    hkpEntity* entity = *entities++;
                    EntityView* ev = (EntityView*)entity;
                    ev->m_unk1CC = 3.40282e+38f;
                    ev->m_unk1DC = 3.40282e+38f;
                } while (++i < island->m_kActorEntries.GetLogicalSize());
            }
            AddItemToContainer((FUN_00c9c3c0_Class*)m_pOwningWorld, island);
        }
    }
}


namespace fnv_00c9d1f0 {
namespace hkC9D1 {

struct FinishingFlag
{
    int m_bFinishing;
};

class hkHalf
{
    short m_uiFilterValue;

  public:
    hkHalf& operator=(float f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = (short)(t >> 16);
        return *this;
    }
};

class hkpMotion
{
  public:
    hkpMotion(FinishingFlag flag)
    {
        if (flag.m_bFinishing)
            m_fGravityFactor = 1.0f;
    }
    virtual ~hkpMotion();
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
    short unk11C;
    hkHalf m_fGravityFactor;
};

class hkpBoxMotion : public hkpMotion
{
  public:
    hkpBoxMotion(FinishingFlag flag) : hkpMotion(flag)
    {}
    virtual ~hkpBoxMotion();
};

}

namespace FUN_00c9d1f0 {

}
}  // namespace fnv_00c9d1f0

namespace fnv_00c9c8f0 {
struct FnvMem
{
    virtual void f00() = 0;
    virtual void f04() = 0;
    virtual void freeArray(void*, unsigned int) = 0;
    virtual void f0c() = 0;
    virtual void freeBlock(void*, unsigned int) = 0;
};
struct FnvRouter
{
    void* a;
    void* b;
    void* c;
    void* d;
    FnvMem* heap;
};
extern FnvRouter* __cdecl FUN_00c85750();

struct FnvRB
{
    int x;
};
extern void __stdcall FUN_00c9c140(FnvRB*);
struct FnvSmall
{
    void** data;
    unsigned short size;
    unsigned short flags;
    __forceinline void releaseMem(int elem)
    {
        if (!(flags & 0x8000))
        {
            unsigned c = flags & 0x3fff;
            void* d = data;
            FnvRouter* router = FUN_00c85750();
            FnvMem* mem = router->heap;
            mem->freeArray(d, c * elem);
        }
    }
    __forceinline void clearAndDealloc(int elem)
    {
        releaseMem(elem);
        size = 0;
        data = 0;
        flags = (flags & 0xc000) | 0x8000;
    }
    __forceinline void clearIfEmpty(bool& used)
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
            {
                used = true;
                return;
            }
        clearAndDealloc(4);
    }
    __forceinline bool hasAny()
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
                return true;
        return false;
    }
    __forceinline bool clearIfEmpty()
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
                return true;
        clearAndDealloc(4);
        return false;
    }
};
struct FnvTwo
{
    FnvSmall one;
    FnvSmall two;
    __forceinline void destroy()
    {
        two.releaseMem(4);
        one.releaseMem(4);
        FnvRouter* router = FUN_00c85750();
        FnvMem* mem = router->heap;
        mem->freeArray(this, 16);
    }
};
}  // namespace fnv_00c9c8f0

namespace fnv_00c9cf60 {
class hkMemoryAllocatorC9CF
{
  public:
    virtual ~hkMemoryAllocatorC9CF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void unk0C() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterC9CF
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorC9CF* m_pStreamAllocator;

    hkMemoryAllocatorC9CF& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterC9CF* __cdecl FUN_00c85750();

template <class T> class hkArrayC9CF
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayC9CF() throw()
    {
        hkMemoryAllocatorC9CF& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <class T> class hkSmallArrayC9CF
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    ~hkSmallArrayC9CF() throw()
    {
        if ((m_iCapacityState & 0x8000) == 0)
        {
            int iCapacity = m_iCapacityState & 0x3fff;
            T* pData = m_data;
            FUN_00c85750()->heap().ReleaseBlock(pData, iCapacity * sizeof(T));
        }
    }
};

template <class T> struct hkRefPtrC9CF
{
    T* m_pRetainedObject;

    ~hkRefPtrC9CF() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

class FUN_00c9d340
{
  public:
    ~FUN_00c9d340() throw();
    static void operator delete(void* p, unsigned int uiNumBytes)
    {
        FUN_00c85750()->heap().ReleaseBlock(p, uiNumBytes);
    }

    int unk00, unk04, unk08, unk0C;
};

namespace FUN_00c9d3b0 {
class hkpWorldObject
{
  public:
    virtual ~hkpWorldObject() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
};
}

}  // namespace fnv_00c9cf60

namespace fnv_00c9d3b0 {
class hkMemoryAllocatorC9D3
{
  public:
    virtual ~hkMemoryAllocatorC9D3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterC9D3
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorC9D3* m_pStreamAllocator;

    hkMemoryAllocatorC9D3& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterC9D3& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayC9D3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayC9D3() throw()
    {
        hkMemoryAllocatorC9D3& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace FUN_00cb0c00 {
class hkStringPtr
{
  public:
    ~hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace hkC9D3 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};
}

namespace hkC9D3 {
struct hkpPropertyC9D3
{
    unsigned int m_key;
    unsigned int m_uiAlignmentPadding;
    unsigned int m_valueLo;
    unsigned int m_valueHi;
};

struct hkpLinkedCollidableEntryC9D3
{
    void* m_pAgentEntry;
    void* m_pCollidable;
};
}

namespace FUN_00c9d3b0 {
class hkpWorldObject : public hkC9D3::hkReferencedObject
{
  public:
    virtual ~hkpWorldObject();

    void* m_pOwningWorld;
    unsigned long m_ulUserData;
    hkC9D3::hkReferencedObject* m_pCollisionShape;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    hkArrayC9D3<hkC9D3::hkpLinkedCollidableEntryC9D3> m_kCollisionEntries;
    int m_uiThreadId;
    int m_usMarkedForWrite;
    FUN_00cb0c00::hkStringPtr m_name;
    hkArrayC9D3<hkC9D3::hkpPropertyC9D3> m_kProperties;
    hkC9D3::hkReferencedObject* m_kNextStreamField;
};

// Releases the collision shape and next stream field references held by the hkpWorldObject.
// @fnv 0x00c9d3b0
hkpWorldObject::~hkpWorldObject()
{
    if (m_pCollisionShape)
        m_pCollisionShape->FUN_00c905b0();
    if (m_kNextStreamField)
        m_kNextStreamField->FUN_00c905b0();
}
}
}  // namespace fnv_00c9d3b0

// @f3 0x0093c7a0 (community match, verified in this file)
namespace f3m_0093c7a0 {
struct KeyItem_93c7a0
{
    int key;
    int value;
};
struct KeyArray_93c7a0
{
    KeyItem_93c7a0* data;
    int size;
};

// pdb: hkDataClass::isSuperClass | hkDataObject.obj | fnv360_1110_retail, objrun_open, low
// pdb params: k
static __declspec(noinline) int FUN_0093c7a0(KeyArray_93c7a0* arr, int key)
{
    for (int i = 0; i < arr->size; ++i)
    {
        if (arr->data[i].key == key)
            return arr->data[i].value;
    }
    return 0;
}

KeyArray_93c7a0* volatile g_arr_93c7a0;
volatile int g_key_93c7a0;
volatile int g_out_93c7a0;
void Caller_93c7a0()
{
    g_out_93c7a0 = FUN_0093c7a0(g_arr_93c7a0, g_key_93c7a0);
    g_out_93c7a0 = FUN_0093c7a0(g_arr_93c7a0, g_key_93c7a0);
}
}   // namespace f3m_0093c7a0

// @f3 0x0090b0c0 (community match, verified in this file)
namespace f3m_0090b0c0 {
struct FUN_0090b0c0_Island
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
    unsigned short unk24;
    unsigned char m_flags;
};
struct FUN_0090b0c0_Owner
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
    FUN_0090b0c0_Island* m_island;
};
struct FUN_0090b0c0_State
{
    unsigned char value;
    FUN_0090b0c0_State(unsigned char v) : value(v) {}
};

// pdb: hkEntity_isActive | hkpEntity.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) FUN_0090b0c0_State FUN_0090b0c0(FUN_0090b0c0_Owner* owner)
{
    FUN_0090b0c0_Island* island = owner->m_island;
    if (!island)
        return FUN_0090b0c0_State(0);
    return FUN_0090b0c0_State((island->m_flags >> 2) & 3);
}

unsigned char FUN_0090b0c0_GetState(FUN_0090b0c0_Owner* owner)
{
    return FUN_0090b0c0(owner).value;
}
}   // namespace f3m_0090b0c0
