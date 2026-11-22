#include <new>
// src/f3staging/f3iso_0098b4c0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0098b4c0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0098b4c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_0098b4c0 {
struct hkpWorldQ;
struct Island98Action;
struct Island98Entity;
struct Island98AgentSector;
class Island98BaseObject
{
public:
    virtual ~Island98BaseObject() {}
};
class Island98ReferencedObject : public Island98BaseObject
{
public:
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    Island98ReferencedObject() : m_referenceCount(1) {}
    virtual ~Island98ReferencedObject() {}
};
struct Island98ConstraintInfo
{
    int m_maxSizeOfSchema;
    int m_sizeOfSchemas;
    int m_numSolverResults;
    int m_numSolverElemTemps;
    void clear() { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
};
class Island98ConstraintOwner : public Island98ReferencedObject
{
public:
    Island98ConstraintInfo m_constraintInfo;
};
struct Island98MultiThreadCheck
{
    unsigned int m_threadId;
    unsigned short m_markCount;
    unsigned short m_markBitStack;
    Island98MultiThreadCheck() { m_threadId = 0xffffffd1; m_markCount = 0; }
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct Island98ThreadMemory { void FUN_008f6d90(void* data, int bytes, int memoryClass) throw(); };
inline Island98ThreadMemory& island98ThreadMemory() { return *static_cast<Island98ThreadMemory*>(TlsGetValue(DAT_010f3170)); }
template <class T> struct Island98Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ~Island98Array() {
        if ((m_capacityAndFlags & 0x80000000u) == 0)
            island98ThreadMemory().FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffffu) * sizeof(T), 0x17);
    }
    Island98Array() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    Island98Array(T* buffer, int size, int capacity) : m_data(buffer), m_size(size), m_capacityAndFlags(capacity | 0x80000000) {}
};
template <class T, int N> struct Island98InplaceArray : Island98Array<T>
{
    T m_storage[N];
    Island98InplaceArray(int size = 0) : Island98Array<T>(m_storage, size, N) {}
};
struct Island98AgentTrack
{
    unsigned int m_bytesUsedInLastSector;
    Island98InplaceArray<Island98AgentSector*, 1> m_sectors;
    Island98AgentTrack() { m_bytesUsedInLastSector = 0x200; }
};
struct FUN_0098b4c0 : Island98ConstraintOwner
{
    hkpWorldQ* m_world;
    int m_numConstraints;
    unsigned short m_storageIndex;
    unsigned short m_dirtyListIndex;
    unsigned char m_splitCheckFrameCounter;
    unsigned char m_splitCheckRequested : 2;
    unsigned char m_isSparse : 2;
    unsigned char m_actionListCleanupNeeded : 2;
    unsigned char m_allowIslandLocking : 2;
    unsigned char m_isInActiveIslandsArray : 2;
    unsigned char m_activeMark : 2;
    unsigned char m_tryToIncreaseIslandSizeMark : 2;
    Island98MultiThreadCheck m_multiThreadCheck;
    float m_timeSinceLastHighFrequencyCheck;
    float m_timeSinceLastLowFrequencyCheck;
    Island98Array<Island98Action*> m_actions;
    float m_timeOfDeactivation;
    Island98InplaceArray<Island98Entity*, 1> m_entities;
    Island98AgentTrack m_agentTrack;
    virtual ~FUN_0098b4c0();
    FUN_0098b4c0(hkpWorldQ* world);
};
// pdb: hkpSimulationIsland::hkpSimulationIsland | hkpSimulationIsland.obj | fnv360_0822_retail, call_gap, high
// pdb params: world
FUN_0098b4c0::FUN_0098b4c0(hkpWorldQ* world)
    : m_world(world), m_dirtyListIndex(0xffff),
      m_splitCheckRequested(0), m_actionListCleanupNeeded(0),
      m_isInActiveIslandsArray(1), m_activeMark(1), m_tryToIncreaseIslandSizeMark(0),
      m_timeSinceLastHighFrequencyCheck(0.0f), m_timeSinceLastLowFrequencyCheck(0.0f),
      m_timeOfDeactivation(-10.0f)
{
    m_allowIslandLocking = 0;
    m_constraintInfo.clear();
    m_isSparse = 0;
    m_numConstraints = 0;
}


}   // namespace f3m_0098b4c0
