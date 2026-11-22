// src/f3staging/f3blk_00a20000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00a256c0 (community match, verified in this file)
namespace f3m_00a256c0 {
// FUN_00a256c0 = Havok 5.5.0 hkpJobQueueUtils::finishDynamicsJob (hkpDynamics.lib, hkpDynamicsJobQueueUtils.obj;
// source file per the object's records: Source\Physics\Dynamics\World\Simulation\Multithreaded\hkpDynamicsJobQueueUtils.cpp,
// lines 405-798), with its file-static callee spawnBuildJacobiansJobs (game 0x00a25450, lines 360-402).
// Written from the SDK headers and the library objects' debug records: the .cpp, hkpDynamicsJobs.h/.inl and
// hkpConstraintSolverSetup.h are not shipped. Reduced from sdk_final.cpp with hktrim.py, then mkcand.py. See note.txt.
namespace f3m_00a256c0 {
typedef float  hkReal;
typedef signed char		hkChar;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
		typedef unsigned __int64 hkUint64;
			typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;

__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
	return hkUlong(pntr) - hkUlong(base);
}

__forceinline int __cdecl hkGetByteOffsetInt( const void* base, const void* pntr)
{
	return static_cast<int>( hkGetByteOffset( base, pntr ) );
}

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
	private:
		char m_bool;
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
	private:
		STORAGE m_storage;
};

template <typename TYPE>
class hkPadSpu
{
	public:
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
	private:
		TYPE m_storage;
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
		class MustEndWithSemiColon;
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
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
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

class hkpJacobianSchema;
class hkpVelocityAccumulator;

struct hkpSolverElemTemp
{
		class MustEndWithSemiColon;
	union
	{
		hkReal m_impulseApplied;
		hkReal m_usedImpulseFactor;
		hkReal m_deltaRhs;
	};
};

struct hkpImpulseLimitBreachedHeader
{
		class MustEndWithSemiColon;
	__declspec(align(16)) int m_numBreached;
	hkpImpulseLimitBreachedHeader* m_next;
};

class hkpConstraintQueryIn;
class hkpEntity;

struct hkConstraintInternal;
class hkpSimulationIsland;

template <typename T>
class hkQueue
{
	public:
		class MustEndWithSemiColon;
		inline void enqueueInFront( const T& element );
	private:
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
		class MustEndWithSemiColon;
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
	public:
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
};

enum
{
	HK_SPU_DMA_GROUP_STALL	= 14,
	HK_SPU_DMA_GROUP_IDLE	= 15,
};

struct hkSpuDmaUtils
{
	static hkInt32 __cdecl incrementInt32InMainMemory( hkInt32* variable, int increment, int dmaGroupId = HK_SPU_DMA_GROUP_STALL );
	static void __cdecl setInt32InMainMemory( hkInt32* variable, hkInt32 value, int dmaGroupId = HK_SPU_DMA_GROUP_STALL );
	static void __cdecl setChar8InMainMemory( hkChar* dstInMainMemory, hkChar c, int dmaGroupId = HK_SPU_DMA_GROUP_STALL );
};

__forceinline hkInt32 hkSpuDmaUtils::incrementInt32InMainMemory( hkInt32* variable, int increment, int dmaGroupId )
{
	hkInt32 newValue = *variable + increment;
	*variable = newValue;
	return newValue;
}

__forceinline void hkSpuDmaUtils::setInt32InMainMemory( hkInt32* variable, hkInt32 value, int dmaGroupId )
{
	*variable = value;
}

__forceinline void hkSpuDmaUtils::setChar8InMainMemory( hkChar* dstInMainMemory, hkChar value, int dmaGroupId  )
{
	*dstInMainMemory = value;
}

class hkStepInfo
{
	public:
		class MustEndWithSemiColon;
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};

struct hkpBuildJacobianTask;
struct hkpSolveConstraintBatchTask;

struct hkpBuildJacobianTaskCollection
{
		class MustEndWithSemiColon;
	hkpBuildJacobianTask* m_buildJacobianTasks;
	int m_numBuildJacobianTasks;
	const hkConstraintInternal** m_callbackConstraints;
	int m_numCallbackConstraints;
};

struct hkpSolveJacobiansTaskCollection
{
		class MustEndWithSemiColon;
	hkpSolveConstraintBatchTask* m_firstSolveJacobiansTask;
	hkUint16 m_firstBatchSize;
};

struct hkpBuildJacobianTaskHeader
{
		class MustEndWithSemiColon;
	mutable int m_openJobs;
	int m_numUnfinishedJobsForBroadphase;
	int m_islandShouldBeDeactivated;
	long m_referenceCount;
	int m_numIslandsAfterSplit;
	void* m_buffer;
	int m_bufferSize;
	hkChar m_exportFinished;
	hkChar m_splitCheckRequested;
	hkpImpulseLimitBreachedHeader* m_impulseLimitsBreached;
	int m_pad[3];
	hkpVelocityAccumulator* m_accumulatorsBase;
	hkpVelocityAccumulator* m_accumulatorsEnd;
	hkUint16 m_numApplyGravityJobs;
	hkUint16 m_numIntegrateVelocitiesJobs;
	hkpJacobianSchema* m_schemasBase;
	hkpSolverElemTemp* m_solverTempBase;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	const hkpConstraintQueryIn* m_constraintQueryIn;
	hkpEntity*const* m_allEntities;
	hkUint16 m_numAllEntities;
	hkUint16 m_entitiesCapacity;
	hkBool m_solveInSingleThread;
	hkBool m_solveInSingleThreadOnPpuOnly;
	hkArray<hkpSimulationIsland*> m_newSplitIslands;
	hkpBuildJacobianTaskCollection m_tasks;
	hkpSolveJacobiansTaskCollection m_solveTasks;
};

struct hkpSolveConstraintBatchTask
{
		class MustEndWithSemiColon;
	hkpSolveConstraintBatchTask* m_next;
	hkpBuildJacobianTaskHeader* m_taskHeader;
	hkpVelocityAccumulator* m_accumulators;
	const hkpJacobianSchema* m_schemas;
	hkpSolverElemTemp* m_solverElemTemp;
	int m_sizeOfSchemaBuffer;
	int m_sizeOfSolverElemTempBuffer;
	hkBool m_isLastTaskInBatch;
	hkUint16 m_sizeOfNextBatch;
	hkpSolveConstraintBatchTask* m_firstTaskInNextBatch;
	int m_pad[3];
};

struct hkpAgentSectorHeader
{
		class MustEndWithSemiColon;
	int m_numTotalTasks;
	int m_openJobs;
	int m_sizeOfJobInfo;
};

class hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		enum JobType
		{
			DYNAMICS_JOB_INTEGRATE,
			DYNAMICS_JOB_BUILD_ACCUMULATORS,
			DYNAMICS_JOB_CREATE_JACOBIAN_TASKS,
			DYNAMICS_JOB_FIRE_JACOBIAN_SETUP_CALLBACK,
			DYNAMICS_JOB_BUILD_JACOBIANS,
			DYNAMICS_JOB_SPLIT_ISLAND,
			DYNAMICS_JOB_SOLVE_CONSTRAINTS,
			DYNAMICS_JOB_SOLVE_APPLY_GRAVITY,
			DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH,
			DYNAMICS_JOB_SOLVE_INTEGRATE_VELOCITIES,
			DYNAMICS_JOB_SOLVE_EXPORT_RESULTS,
			DYNAMICS_JOB_INTEGRATE_MOTION,
			DYNAMICS_JOB_BROADPHASE,
			DYNAMICS_JOB_AGENT_SECTOR,
			DYNAMICS_JOB_POST_COLLIDE,
			DYNAMICS_JOB_AGENT_NN_ENTRY,
			DYNAMICS_JOB_END
		};
		enum NoJob { NO_SRC_JOB };
		typedef hkEnum<JobType,hkObjectIndex> hkpDynamicsJobType;
	public:
		__forceinline hkpDynamicsJob( JobType type, const hkpDynamicsJob& srcJob );
	public:
		__declspec(align(16)) hkpDynamicsJobType m_jobType;
		hkObjectIndex m_islandIndex;
		hkpSimulationIsland* m_island;
		hkpBuildJacobianTaskHeader* m_taskHeader;
};

class hkpBuildAccumulatorsJob : public hkpDynamicsJob
{
	public:
		class MustEndWithSemiColon;
		enum { ACCUMULATORS_PER_JOB = 128 };
	public:
		hkpEntity*const* m_islandEntitiesArray;
		hkObjectIndex m_firstEntityIdx;
		hkObjectIndex m_numEntities;
};

class hkpFireJacobianSetupCallback : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpFireJacobianSetupCallback( const hkpBuildAccumulatorsJob& baj );
};

class hkpBuildJacobiansJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpBuildJacobiansJob( const hkpDynamicsJob& job, hkpBuildJacobianTask* firstTaskInMainMemory, const hkpBuildJacobianTaskHeader& taskHeader );
	public:
		union
		{
			hkpBuildJacobianTask* m_buildJacobianTask;
			hkpBuildJacobianTask* m_buildJacobianTaskInMainMemory;
		};
		const hkpConstraintQueryIn* m_constraintQueryIn;
		hkBool m_finishSchemasWithGoto;
};

class hkpSplitSimulationIslandJob : public hkpDynamicsJob
{
	public:
		class MustEndWithSemiColon;
		__forceinline hkpSplitSimulationIslandJob( const hkpDynamicsJob& job, JobType type = DYNAMICS_JOB_SPLIT_ISLAND );
};

class hkpSolveConstraintsJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpSolveConstraintsJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader );
	public:
		void* m_buffer;
		hkUint32 m_bufferSize;
		hkUint32 m_accumulatorsOffset;
		hkUint32 m_schemasOffset;
		hkUint32 m_solverTempOffset;
		int m_numSolverResults;
		int m_numSolverElemTemps;
};

class hkpSolveApplyGravityJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		enum { MAX_NUM_ACCUMULATORS_FOR_APPLY_GRAVITY_JOB = 128 };
		__forceinline hkpSolveApplyGravityJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& localTaskHeaderCopy );
	public:
		hkpVelocityAccumulator* m_accumulators;
		hkpVelocityAccumulator* m_accumulatorsEnd;
};

class hkpSolveIntegrateVelocitiesJob;

class hkpSolveConstraintBatchJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpSolveConstraintBatchJob( const hkpSolveApplyGravityJob& sagj, const hkpBuildJacobianTaskHeader& taskHeader );
		__forceinline hkpSolveConstraintBatchJob( const hkpSolveConstraintBatchJob& scbj );
		__forceinline hkpSolveConstraintBatchJob( const hkpSolveIntegrateVelocitiesJob& sivj, const hkpBuildJacobianTaskHeader& taskHeader );
	public:
		hkUint32 m_currentSolverStep;
		hkUint32 m_numSolverMicroSteps;
		hkUint32 m_currentSolverMicroStep;
		union
		{
			hkpSolveConstraintBatchTask* m_solveConstraintBatchTask;
			hkpSolveConstraintBatchTask* m_solveConstraintBatchTaskInMainMemory;
		};
};

class hkpSolveIntegrateVelocitiesJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		enum { MAX_NUM_ACCUMULATORS_FOR_INTEGRATE_VELOCITIES_JOB = 128 };
		__forceinline hkpSolveIntegrateVelocitiesJob( const hkpSolveConstraintBatchJob& scbij, const hkpBuildJacobianTaskHeader& localTaskHeaderCopy );
	public:
		hkpVelocityAccumulator* m_accumulators;
		hkpVelocityAccumulator* m_accumulatorsEnd;
		hkUint32 m_currentSolverStep;
		hkBool m_solvingFinished;
};

class hkpSolveExportResultsJob : public hkpSplitSimulationIslandJob
{
	public:
		class MustEndWithSemiColon;
		__forceinline hkpSolveExportResultsJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader, JobType type = DYNAMICS_JOB_SOLVE_EXPORT_RESULTS );
	public:
		union
		{
			hkpSolveConstraintBatchTask* m_solveConstraintBatchTask;
			hkpSolveConstraintBatchTask* m_solveConstraintBatchTaskInMainMemory;
		};
		hkpImpulseLimitBreachedHeader* m_impulseLimitsBreachedPadding;
		int m_numImpulseLimitsBreachedPadding;
};

class hkpIntegrateMotionJob : public hkpSolveExportResultsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		enum { ACCUMULATORS_PER_JOB = 128 };
		__forceinline hkpIntegrateMotionJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader );
	public:
		void* m_buffer;
		hkObjectIndex m_numEntities;
		hkObjectIndex m_firstEntityIdx;
		int m_numInactiveFrames;
};

class hkpBroadPhaseJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpBroadPhaseJob( const hkpDynamicsJob& job, hkpBuildJacobianTaskHeader* newTaskHeader );
	public:
		hkObjectIndex m_numIslands;
};

class hkpAgentBaseJob : public hkpDynamicsJob
{
	public:
		class MustEndWithSemiColon;
		enum { MAX_AGENT_NN_ENTRIES_PER_TASK = 16 };
	public:
		hkpAgentSectorHeader* m_header;
		hkObjectIndex m_taskIndex;
		hkObjectIndex m_numTotalTasks;
		hkObjectIndex m_numElements;
		hkObjectIndex m_numElementsPerTask;
		void*const* m_elements;
		hkStepInfo m_stepInfo;
};

class hkpAgentSectorJob : public hkpAgentBaseJob
{
	public:
		class MustEndWithSemiColon;
	public:
		int m_sectorIndex;
		hkUint16 m_bytesUsedInLastSector;
};

class hkpPostCollideJob : public hkpDynamicsJob
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; }
		class MustEndWithSemiColon;
		__forceinline hkpPostCollideJob( const hkpAgentBaseJob& asj );
	public:
		hkpAgentSectorHeader* m_header;
};

__forceinline hkpDynamicsJob::hkpDynamicsJob( JobType type, const hkpDynamicsJob& srcJob )
{
	m_jobType = type;
	m_islandIndex = srcJob.m_islandIndex;
	m_island = srcJob.m_island;
	m_taskHeader = srcJob.m_taskHeader;
}

__forceinline hkpFireJacobianSetupCallback::hkpFireJacobianSetupCallback( const hkpBuildAccumulatorsJob& baj )
:	hkpDynamicsJob( DYNAMICS_JOB_FIRE_JACOBIAN_SETUP_CALLBACK, baj )
{
}

__forceinline hkpBuildJacobiansJob::hkpBuildJacobiansJob( const hkpDynamicsJob& job, hkpBuildJacobianTask* firstTaskInMainMemory, const hkpBuildJacobianTaskHeader& taskHeader )
:	hkpDynamicsJob( DYNAMICS_JOB_BUILD_JACOBIANS, job )
{
	m_constraintQueryIn = taskHeader.m_constraintQueryIn;
	m_finishSchemasWithGoto = taskHeader.m_solveInSingleThread;
	m_buildJacobianTaskInMainMemory = firstTaskInMainMemory;
}

__forceinline hkpSplitSimulationIslandJob::hkpSplitSimulationIslandJob( const hkpDynamicsJob& job, JobType type )
:	hkpDynamicsJob( type, job )
{
}

__forceinline hkpSolveConstraintsJob::hkpSolveConstraintsJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_CONSTRAINTS, job )
{
	m_buffer = taskHeader.m_buffer;
	m_accumulatorsOffset = hkGetByteOffsetInt( m_buffer, taskHeader.m_accumulatorsBase );
	m_schemasOffset = hkGetByteOffsetInt( m_buffer, taskHeader.m_schemasBase );
	m_solverTempOffset = hkGetByteOffsetInt( m_buffer, taskHeader.m_solverTempBase );
	m_bufferSize = taskHeader.m_bufferSize;
	m_numSolverResults = taskHeader.m_numSolverResults;
	m_numSolverElemTemps = taskHeader.m_numSolverElemTemps;
}

__forceinline hkpSolveApplyGravityJob::hkpSolveApplyGravityJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& localTaskHeaderCopy )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_APPLY_GRAVITY, job )
{
	m_accumulators = localTaskHeaderCopy.m_accumulatorsBase;
	m_accumulatorsEnd = localTaskHeaderCopy.m_accumulatorsEnd;
}

__forceinline hkpSolveConstraintBatchJob::hkpSolveConstraintBatchJob( const hkpSolveApplyGravityJob& sagj, const hkpBuildJacobianTaskHeader& taskHeader )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH, sagj )
{
	m_solveConstraintBatchTaskInMainMemory = taskHeader.m_solveTasks.m_firstSolveJacobiansTask;
	m_currentSolverStep = 0;
	m_currentSolverMicroStep = 0;
}

__forceinline hkpSolveConstraintBatchJob::hkpSolveConstraintBatchJob( const hkpSolveConstraintBatchJob& scbj )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH, scbj )
{
	*this = scbj;
	m_solveConstraintBatchTaskInMainMemory = scbj.m_solveConstraintBatchTask->m_firstTaskInNextBatch;
}

__forceinline hkpSolveIntegrateVelocitiesJob::hkpSolveIntegrateVelocitiesJob( const hkpSolveConstraintBatchJob& scbij, const hkpBuildJacobianTaskHeader& localTaskHeaderCopy )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_INTEGRATE_VELOCITIES, scbij )
{
	m_accumulators = localTaskHeaderCopy.m_accumulatorsBase;
	m_accumulatorsEnd = localTaskHeaderCopy.m_accumulatorsEnd;
	m_currentSolverStep = scbij.m_currentSolverStep;
	m_solvingFinished = false;
}

__forceinline hkpSolveConstraintBatchJob::hkpSolveConstraintBatchJob( const hkpSolveIntegrateVelocitiesJob& sivj, const hkpBuildJacobianTaskHeader& taskHeader )
:	hkpDynamicsJob( DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH, sivj )
{
	m_solveConstraintBatchTaskInMainMemory = taskHeader.m_solveTasks.m_firstSolveJacobiansTask;
	m_currentSolverStep = sivj.m_currentSolverStep + 1;
	m_currentSolverMicroStep = 0;
}

__forceinline hkpSolveExportResultsJob::hkpSolveExportResultsJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader, JobType type )
:	hkpSplitSimulationIslandJob( job, type )
{
	m_solveConstraintBatchTaskInMainMemory = taskHeader.m_solveTasks.m_firstSolveJacobiansTask;
}

__forceinline hkpIntegrateMotionJob::hkpIntegrateMotionJob( const hkpDynamicsJob& job, const hkpBuildJacobianTaskHeader& taskHeader )
:	hkpSolveExportResultsJob( job, taskHeader, DYNAMICS_JOB_INTEGRATE_MOTION )
{
	m_firstEntityIdx = 0;
	m_numEntities = taskHeader.m_numAllEntities;
	m_buffer = taskHeader.m_buffer;
}

__forceinline hkpBroadPhaseJob::hkpBroadPhaseJob( const hkpDynamicsJob& job, hkpBuildJacobianTaskHeader* newTaskHeader )
:	hkpDynamicsJob( DYNAMICS_JOB_BROADPHASE, job )
{
	m_taskHeader = newTaskHeader;
	m_numIslands = 1;
}

__forceinline hkpPostCollideJob::hkpPostCollideJob( const hkpAgentBaseJob& asj )
:	hkpDynamicsJob( DYNAMICS_JOB_POST_COLLIDE, asj )
{
	m_islandIndex = asj.m_islandIndex;
	m_header = asj.m_header;
}

struct hkpJobQueueUtils
{
	static hkJobQueue::JobCreationStatus __cdecl FUN_00a256c0( hkJobQueue& queue, hkJobQueue::DynamicData* data, const hkJobQueue::JobQueueEntry& jobIn, hkJobQueue::JobQueueEntryInput& newJobCreated );
};

static void spawnBuildJacobiansJobs( const hkpDynamicsJob& dynamicsJob, const hkpBuildJacobianTaskHeader& taskHeader, hkJobQueue& queue, hkJobQueue::DynamicData* data, hkJobQueue::JobQueueEntryInput& newJobCreated )
{
	new (&newJobCreated.m_job) hkpBuildJacobiansJob( dynamicsJob, taskHeader.m_tasks.m_buildJacobianTasks, taskHeader );
	taskHeader.m_openJobs = taskHeader.m_tasks.m_numBuildJacobianTasks;
	newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
	newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
}

// pdb: hkpJobQueueUtils::finishIntegrateJob | hkpDynamicsJobQueueUtils.obj | fnv360_0822_retail, objrun_open, low
// pdb params: queue, data, jobIn, newJobCreated
hkJobQueue::JobCreationStatus __cdecl hkpJobQueueUtils::FUN_00a256c0( hkJobQueue& queue, hkJobQueue::DynamicData* data, const hkJobQueue::JobQueueEntry& jobIn, hkJobQueue::JobQueueEntryInput& newJobCreated )
{
	int numJobsToFinish = 1;
	const hkpDynamicsJob& job = reinterpret_cast<const hkpDynamicsJob&>(jobIn);
	const hkpBuildJacobianTaskHeader* localTaskHeader = job.m_taskHeader;
	switch( job.m_jobType )
	{
		case hkpDynamicsJob::DYNAMICS_JOB_BUILD_ACCUMULATORS:
		case hkpDynamicsJob::DYNAMICS_JOB_CREATE_JACOBIAN_TASKS:
commonForCreateJacAndBuildAcc:
		{
			const hkpBuildAccumulatorsJob& baj = reinterpret_cast<const hkpBuildAccumulatorsJob&>(job);
			localTaskHeader->m_openJobs--;
			if ( localTaskHeader->m_openJobs == 0 )
			{
				int numElemsForPpu = localTaskHeader->m_tasks.m_numCallbackConstraints;
				if ( numElemsForPpu > 0 )
				{
					new (&newJobCreated.m_job) hkpFireJacobianSetupCallback( baj );
					newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
					newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_CPU;
				}
				else
				{
					spawnBuildJacobiansJobs( baj, *localTaskHeader, queue, data, newJobCreated );
				}
				goto yesJobCreated;
			}
			goto noJobCreated;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_FIRE_JACOBIAN_SETUP_CALLBACK:
		{
			const hkpFireJacobianSetupCallback& fjscb = reinterpret_cast<const hkpFireJacobianSetupCallback&>(job);
			spawnBuildJacobiansJobs( fjscb, *fjscb.m_taskHeader, queue, data, newJobCreated );
			return hkJobQueue::JOB_CREATED;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_BUILD_JACOBIANS:
		{
			localTaskHeader->m_openJobs--;
			const hkpBuildJacobiansJob& bjj = reinterpret_cast<const hkpBuildJacobiansJob&>(job);
			if ( localTaskHeader->m_openJobs == 0 )
			{
				hkpDynamicsJob* newDynamicsJob;
				if ( localTaskHeader->m_solveInSingleThread )
				{
					newDynamicsJob = new (&newJobCreated.m_job) hkpSolveConstraintsJob( bjj, *localTaskHeader );
					newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
					newJobCreated.m_jobThreadType = localTaskHeader->m_solveInSingleThreadOnPpuOnly ? hkJobQueue::JOB_TYPE_CPU : hkJobQueue::JOB_TYPE_HINT_SPU;
				}
				else
				{
					newDynamicsJob = new (&newJobCreated.m_job) hkpSolveApplyGravityJob( job, *localTaskHeader );
					newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
					newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
					localTaskHeader->m_openJobs = localTaskHeader->m_numApplyGravityJobs;
				}
				if ( localTaskHeader->m_splitCheckRequested )
				{
					data->m_jobQueue[hkJobQueue::JOB_TYPE_CPU].enqueueInFront( (const hkJobQueue::JobQueueEntry&)hkpSplitSimulationIslandJob( *newDynamicsJob ) );
				}
				goto yesJobCreated;
			}
			goto noJobCreated;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SOLVE_CONSTRAINTS:
		{
			hkSpuDmaUtils::setChar8InMainMemory( &job.m_taskHeader->m_exportFinished, hkChar(1) );
			return hkJobQueue::NO_JOB_CREATED;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SOLVE_APPLY_GRAVITY:
		{
			localTaskHeader->m_openJobs--;
			if ( localTaskHeader->m_openJobs == 0 )
			{
				const hkpSolveApplyGravityJob& sagj = reinterpret_cast<const hkpSolveApplyGravityJob&>(job);
				new (&newJobCreated.m_job) hkpSolveConstraintBatchJob( sagj, *localTaskHeader );
				newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
				newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
				localTaskHeader->m_openJobs = localTaskHeader->m_solveTasks.m_firstBatchSize;
				goto yesJobCreated;
			}
			goto noJobCreated;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SOLVE_CONSTRAINT_BATCH:
		{
			const hkpSolveConstraintBatchJob& scbij = reinterpret_cast<const hkpSolveConstraintBatchJob&>(job);
			hkJobQueue::JobCreationStatus status = hkJobQueue::NO_JOB_CREATED;
			localTaskHeader->m_openJobs--;
			if ( localTaskHeader->m_openJobs == 0 )
			{
				int numOpenJobsForNewJobCreated;
				const hkUint32 sizeOfNextBatch = scbij.m_solveConstraintBatchTask->m_sizeOfNextBatch;
				if ( sizeOfNextBatch )
				{
					new (&newJobCreated.m_job) hkpSolveConstraintBatchJob( scbij );
					numOpenJobsForNewJobCreated = sizeOfNextBatch;
				}
				else
				if ( scbij.m_currentSolverMicroStep + 1 < scbij.m_numSolverMicroSteps )
				{
					hkpSolveConstraintBatchJob* newJob = new (&newJobCreated.m_job) hkpSolveConstraintBatchJob( scbij );
					newJob->m_currentSolverMicroStep++;
					newJob->m_solveConstraintBatchTaskInMainMemory = localTaskHeader->m_solveTasks.m_firstSolveJacobiansTask;
					numOpenJobsForNewJobCreated = localTaskHeader->m_solveTasks.m_firstBatchSize;
				}
				else
				{
					new (&newJobCreated.m_job) hkpSolveIntegrateVelocitiesJob( scbij, *localTaskHeader );
					numOpenJobsForNewJobCreated = localTaskHeader->m_numIntegrateVelocitiesJobs;
				}
				newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
				newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
				localTaskHeader->m_openJobs = numOpenJobsForNewJobCreated;
				status = hkJobQueue::JOB_CREATED;
			}
			return status;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SOLVE_INTEGRATE_VELOCITIES:
		{
			const hkpSolveIntegrateVelocitiesJob& sivbij = reinterpret_cast<const hkpSolveIntegrateVelocitiesJob&>(job);
			localTaskHeader->m_openJobs--;
			if ( localTaskHeader->m_openJobs == 0 )
			{
				int numOpenJobsForNewJobCreated;
				if ( !sivbij.m_solvingFinished )
				{
					hkUint32 currentSolverStep = sivbij.m_currentSolverStep;
					hkpSolveConstraintBatchJob* newJob = new (&newJobCreated.m_job) hkpSolveConstraintBatchJob( sivbij, *localTaskHeader );
					numOpenJobsForNewJobCreated = localTaskHeader->m_solveTasks.m_firstBatchSize;
				}
				else
				{
					new (&newJobCreated.m_job) hkpIntegrateMotionJob( sivbij, *localTaskHeader );
					numOpenJobsForNewJobCreated = localTaskHeader->m_tasks.m_numBuildJacobianTasks;
				}
				newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
				newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
				localTaskHeader->m_openJobs = numOpenJobsForNewJobCreated;
				goto yesJobCreated;
			}
			goto noJobCreated;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SOLVE_EXPORT_RESULTS:
		{
			const hkpSolveExportResultsJob& serbij = reinterpret_cast<const hkpSolveExportResultsJob&>(job);
			hkpBuildJacobianTaskHeader* taskHeaderInMainMemory = serbij.m_taskHeader;
			localTaskHeader->m_openJobs--;
			hkpImpulseLimitBreachedHeader* ilbh = (hkpImpulseLimitBreachedHeader*)serbij.m_solveConstraintBatchTask->m_schemas;
			if ( ilbh->m_numBreached )
			{
				ilbh->m_next = taskHeaderInMainMemory->m_impulseLimitsBreached;
				taskHeaderInMainMemory->m_impulseLimitsBreached = ilbh;
			}
			if ( localTaskHeader->m_openJobs == 0 )
			{
				taskHeaderInMainMemory->m_exportFinished = 1;
				localTaskHeader = 0;
				return hkJobQueue::NO_JOB_CREATED;
			}
			goto noJobCreated;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_INTEGRATE_MOTION:
		{
			const hkpIntegrateMotionJob& imj = reinterpret_cast<const hkpIntegrateMotionJob&>(job);
			if ( imj.m_numInactiveFrames <= 5 )
			{
				hkSpuDmaUtils::setInt32InMainMemory( &imj.m_taskHeader->m_islandShouldBeDeactivated, 0 );
			}
			numJobsToFinish = 1 + ( unsigned(imj.m_numEntities-1)/ hkpIntegrateMotionJob::ACCUMULATORS_PER_JOB);
		}
		case hkpDynamicsJob::DYNAMICS_JOB_SPLIT_ISLAND:
commonForIntegrateMotinoAndSplitIsland:
		{
			const hkpSplitSimulationIslandJob& sij = reinterpret_cast<const hkpSplitSimulationIslandJob&>(job);
			int openJobs = hkSpuDmaUtils::incrementInt32InMainMemory( &sij.m_taskHeader->m_numUnfinishedJobsForBroadphase, -numJobsToFinish );
			if ( openJobs == 0 )
			{
				new (&newJobCreated.m_job) hkpBroadPhaseJob( sij, sij.m_taskHeader );
				newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
				newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_CPU_BROADPHASE;
				return hkJobQueue::JOB_CREATED;
			}
			return hkJobQueue::NO_JOB_CREATED;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_AGENT_SECTOR:
		{
			const hkpAgentSectorJob& asj = reinterpret_cast<const hkpAgentSectorJob&>(job);
			if ( !asj.m_header )
			{
				return hkJobQueue::NO_JOB_CREATED;
			}
			int openJobs = hkSpuDmaUtils::incrementInt32InMainMemory( &asj.m_header->m_openJobs, -1 );
			if ( openJobs == 0 )
			{
				new (&newJobCreated.m_job) hkpPostCollideJob( asj );
				newJobCreated.m_jobPriority = hkJobQueue::JOB_HIGH_PRIORITY;
				newJobCreated.m_jobThreadType = hkJobQueue::JOB_TYPE_HINT_SPU;
				return hkJobQueue::JOB_CREATED;
			}
			return hkJobQueue::NO_JOB_CREATED;
		}
		case hkpDynamicsJob::DYNAMICS_JOB_AGENT_NN_ENTRY:
		{
			return hkJobQueue::NO_JOB_CREATED;
		}
		default:
		{
			break;
		}
	}
noJobCreated:
	return hkJobQueue::NO_JOB_CREATED;
yesJobCreated:
	return hkJobQueue::JOB_CREATED;
}
}
}   // namespace f3m_00a256c0
