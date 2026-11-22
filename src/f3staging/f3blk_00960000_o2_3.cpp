#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_00960000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x0097a150 (community match, verified in this file)
namespace f3m_0097a150 {
// hkpConstraintInstance::clone (Havok 5.5): a shallow copy shares the constraint data; otherwise the data is cloned
// when it can have motors, else shared with an extra reference, and the local reference is released after the new
// instance took its own. The class allocator stores the chunk size in the new object's size field before the
// constructor runs. Data and priority are read through the class's inline getters.
namespace f3o_97a150 {

template <typename T>
struct ThreadLocalData
{
    T getData() const { return (T)(unsigned long)TlsGetValue(m_slotID); }
    unsigned long m_slotID;
};

struct ThreadMemory;
extern ThreadLocalData<ThreadMemory*> s_threadMemoryInstance;

struct ThreadMemory
{
    void* allocateChunk(int nbytes, int cl);
    static inline ThreadMemory* getInstancePtr() { return s_threadMemoryInstance.getData(); }
    static inline ThreadMemory& getInstance()
    {
        ThreadMemory* instance = getInstancePtr();
        return *instance;
    }
};

struct ReferencedObject
{
    virtual ~ReferencedObject();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;

    void addReference()
    {
        if (m_memSizeAndFlags != 0)
            ++m_referenceCount;
    }
    void removeReference()
    {
        if (m_memSizeAndFlags != 0)
        {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }
};

struct Entity;

template <typename ENUM, typename STORAGE>
struct Enum
{
    operator ENUM() const { return static_cast<ENUM>(m_storage); }
    STORAGE m_storage;
};
struct ConstraintData : ReferencedObject {};

ConstraintData* cloneIfCanHaveMotors(const ConstraintData* data);

struct ConstraintInstance : ReferencedObject
{
    enum ConstraintPriority { PRIORITY_INVALID, PRIORITY_PSI, PRIORITY_SIMPLIFIED_TOI_UNUSED, PRIORITY_TOI, PRIORITY_TOI_HIGHER, PRIORITY_TOI_FORCED };
    enum CloningMode { CLONE_INSTANCES_ONLY = 0, CLONE_DATAS_WITH_MOTORS = 1 };

    static void* operator new(unsigned int nbytes)
    {
        ReferencedObject* b = static_cast<ReferencedObject*>(ThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes), 0x2c));
        b->m_memSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    int m_owner;
    ConstraintData* m_data;
    int m_modifiers;
    Entity* m_entities[2];
    Enum<ConstraintPriority, unsigned char> m_priority;
    bool m_wantRuntime;
    int m_name;
    int m_userData;
    int m_internal;

    ConstraintData* getData() const { return m_data; }
    ConstraintPriority getPriority() const { return m_priority; }
    ConstraintInstance(Entity* entityA, Entity* entityB, ConstraintData* data, ConstraintPriority priority);
    ConstraintInstance* FUN_0097a150(Entity* newEntityA, Entity* newEntityB, CloningMode mode) const;
};

}

// pdb: hkpConstraintInstance::isConstrainedToWorld | hkpConstraintInstance.obj | fnv360_0822_retail, call_gap, low
f3o_97a150::ConstraintInstance* f3o_97a150::ConstraintInstance::FUN_0097a150(Entity* newEntityA, Entity* newEntityB, CloningMode mode) const
{
    if (mode == CLONE_INSTANCES_ONLY)
    {
        return new ConstraintInstance(newEntityA, newEntityB, getData(), getPriority());
    }

    ConstraintData* clonedData = cloneIfCanHaveMotors(getData());
    if (!clonedData)
    {
        clonedData = getData();
        clonedData->addReference();
    }

    ConstraintInstance* instance = new ConstraintInstance(newEntityA, newEntityB, clonedData, getPriority());
    clonedData->removeReference();

    return instance;
}
}   // namespace f3m_0097a150
