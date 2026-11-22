// include/havok/hkpWorld.h - hkpWorld as Fallout 3 lays it out: the offsets are those of the matched constructor
// (0x00904ea0, WorldCtor in src/f3staging/f3blk_00900000_od.cpp), the names the New Vegas Xbox 360 PDB's. Fallout 3's
// Havok has no m_assertOnRunningOutOfSolverMemory, m_kdTreeManager, m_autoUpdateTree, m_pendingBodyOperationsCount,
// m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob, m_maxSectorsPerCollideTask, the four TOI penetration
// factors, m_lastEntityUid, m_lastIslandUid, m_violatedConstraintArray, m_collisionCallbackUtil or m_destructionWorld.
#ifndef FNV_HAVOK_HKPWORLD_H
#define FNV_HAVOK_HKPWORLD_H
#include "f3_common.h"
#include "hkBase.h"
#include "hkMultiThreadCheck.h"
#include "hkReferencedObject.h"
class hkpPhantom;
class hkpSimulation;
#pragma pack(push, 1)
class hkpWorld : public hkReferencedObject
{
  public:
    hkpSimulation*           m_simulation;  // +0x8
    int                      unk0C;  // +0xC
    hkVector4                m_gravity;  // +0x10
    void*                    m_fixedIsland;  // +0x20
    void*                    m_fixedRigidBody;  // +0x24
    hkArray<void*>           m_activeSimulationIslands;  // +0x28
    hkArray<void*>           m_inactiveSimulationIslands;  // +0x34
    hkArray<void*>           m_dirtySimulationIslands;  // +0x40
    void*                    m_maintenanceMgr;  // +0x4C
    void*                    m_memoryWatchDog;  // +0x50
    void*                    m_broadPhase;  // +0x54
    void*                    m_broadPhaseDispatcher;  // +0x58
    void*                    m_phantomBroadPhaseListener;  // +0x5C
    void*                    m_entityEntityBroadPhaseListener;  // +0x60
    void*                    m_broadPhaseBorderListener;  // +0x64
    void*                    m_multithreadedSimulationJobData;  // +0x68
    void*                    m_collisionInput;  // +0x6C
    void*                    m_collisionFilter;  // +0x70
    void*                    m_collisionDispatcher;  // +0x74
    void*                    m_convexListFilter;  // +0x78
    void*                    m_pendingOperations;  // +0x7C
    hkInt32                  m_pendingOperationsCount;  // +0x80
    hkInt32                  m_criticalOperationsLockCount;  // +0x84
    hkInt32                  m_criticalOperationsLockCountForPhantoms;  // +0x88
    hkBool                   m_blockExecutingPendingOperations;  // +0x8C
    hkBool                   m_criticalOperationsAllowed;  // +0x8D
    char                     pad8E[0x2];  // +0x8E
    void*                    m_pendingOperationQueues;  // +0x90
    hkInt32                  m_pendingOperationQueueCount;  // +0x94
    hkMultiThreadCheck       m_multiThreadCheck;  // +0x98
    hkBool                   m_processActionsInSingleThread;  // +0xA0
    char                     padA1[0x3];  // +0xA1
    hkUint32                 m_minDesiredIslandSize;  // +0xA4
    void*                    m_modifyConstraintCriticalSection;  // +0xA8
    hkInt32                  m_isLocked;  // +0xAC
    void*                    m_islandDirtyListCriticalSection;  // +0xB0
    void*                    m_propertyMasterLock;  // +0xB4
    hkBool                   m_wantSimulationIslands;  // +0xB8
    char                     padB9[0x3];  // +0xB9
    hkReal                   m_snapCollisionToConvexEdgeThreshold;  // +0xBC
    hkReal                   m_snapCollisionToConcaveEdgeThreshold;  // +0xC0
    hkBool                   m_enableToiWeldRejection;  // +0xC4
    hkBool                   m_wantDeactivation;  // +0xC5
    hkBool                   m_shouldActivateOnRigidBodyTransformChange;  // +0xC6
    char                     padC7[0x1];  // +0xC7
    hkReal                   m_deactivationReferenceDistance;  // +0xC8
    hkReal                   m_toiCollisionResponseRotateNormal;  // +0xCC
    hkBool                   m_processToisMultithreaded;  // +0xD0
    char                     padD1[0x3];  // +0xD1
    hkInt32                  m_maxEntriesPerToiCollideTask;  // +0xD4
    hkInt32                  m_maxNumToiCollisionPairsSinglethreaded;  // +0xD8
    hkInt32                  m_simulationType;  // +0xDC
    hkUint32                 m_lastConstraintUid;  // +0xE0
    hkArray<hkpPhantom*>     m_phantoms;  // +0xE4
    hkArray<void*>           m_actionListeners;  // +0xF0
    hkArray<void*>           m_entityListeners;  // +0xFC
    hkArray<void*>           m_phantomListeners;  // +0x108
    hkArray<void*>           m_constraintListeners;  // +0x114
    hkArray<void*>           m_worldDeletionListeners;  // +0x120
    hkArray<void*>           m_islandActivationListeners;  // +0x12C
    hkArray<void*>           m_worldPostSimulationListeners;  // +0x138
    hkArray<void*>           m_worldPostIntegrateListeners;  // +0x144
    hkArray<void*>           m_worldPostCollideListeners;  // +0x150
    hkArray<void*>           m_islandPostIntegrateListeners;  // +0x15C
    hkArray<void*>           m_islandPostCollideListeners;  // +0x168
    hkArray<void*>           m_contactListeners;  // +0x174
    hkArray<void*>           m_contactImpulseLimitBreachedListeners;  // +0x180
    void*                    m_broadPhaseBorder;  // +0x18C
    char                     m_dynamicsStepInfo[0x140];  // +0x190
    hkVector4                m_broadPhaseExtents[2];  // +0x2D0
    hkInt32                  m_broadPhaseNumMarkers;  // +0x2F0
    hkInt32                  m_sizeOfToiEventQueue;  // +0x2F4
    hkInt32                  m_broadPhaseQuerySize;  // +0x2F8
    hkInt32                  m_broadPhaseUpdateSize;  // +0x2FC
    hkInt8                   m_contactPointGeneration;  // +0x300
    char                     pad301[0xF];  // +0x301
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWorld[(sizeof(hkpWorld) == 0x310) ? 1 : -1];
#endif
