#include "f3_common.h"
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreebuildjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreebuildjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <windows.h>
extern DWORD DAT_0126835c;
struct __declspec(align(8)) ScratchWord
{
    DWORD unk00;
    DWORD value;
};
struct ArgStruct
{
    DWORD unk00;
    unsigned short size;
    short index;
    DWORD unk08;
    DWORD unk0c;
    int m_10;
    int* m_14;
    DWORD unk18;
    DWORD unk1c;
    int m_20;
    int m_24;
    char* m_28;
    int m_2c;
    int* m_30;
    int* m_34;
    int m_38;
    int m_3c;
    int m_40;
};
struct __declspec(align(16)) VecA
{
    float x;
    float y;
    float z;
    float w;
};
struct OutElem
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short size;
    short index;
    DWORD unk08;
    DWORD unk0c;
    int m_10;
    int* m_14;
    DWORD m_18;
    DWORD unk1c;
    char* m_20;
    int m_24;
    DWORD m_28;
    DWORD m_2c;
    DWORD m_30;
    DWORD m_34;
    DWORD m_38;
    DWORD unk3c;
    VecA m_40vec;
    int* m_50;
    DWORD m_54;
    int m_58;
    DWORD unk5c;
    OutElem()
    {
        b0 = 4;
        b1 = 3;
        size = 0x60;
        index = -1;
        m_10 = 0;
        m_18 = 0;
        b2 = 1;
        m_14 = 0;
        m_50 = 0;
    }
};
struct Ctx
{
    int FUN_00d04400(void* p);
    int InsertItemAndNotify(int h, void* p, int z);
    void FUN_00d04420(int h);
    int ProcessCallback(ArgStruct* a, ArgStruct* b, int z);
};
struct ContextHandle
{
    Ctx* object;
    Ctx* operator->() const
    {
        return object;
    }
};
struct ArgHandle
{
    ArgStruct* object;
    ArgStruct* operator->() const
    {
        return object;
    }
    operator ArgStruct*() const
    {
        return object;
    }
};

extern unsigned long DAT_0126835c;

struct S00d947e0_Obj
{
    char unk000;
};

struct S00d947e0_Info
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
    short unk54;
    short unk56;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
};

struct S00d947e0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    short unk12;
    int unk14;
    S00d947e0_Info* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

enum S00d947e0_JobType
{
    S00d947e0_JOB_DYNAMICS = 0
};
enum S00d947e0_SpuType
{
    S00d947e0_SPU_DISABLED = 2
};

template <class E, class S> struct S00d947e0_Enum
{
    S m_kStorage;
    __forceinline S00d947e0_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
};

struct __declspec(align(16)) S00d947e0_Job
{
    unsigned char m_subType;
    S00d947e0_Enum<S00d947e0_JobType, unsigned char> m_eJobType;
    S00d947e0_Enum<S00d947e0_SpuType, unsigned char> m_spuType;
    unsigned char m_03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    int m_08;
    int m_0c;

    __forceinline S00d947e0_Job(unsigned char subType, unsigned short size)
        : m_subType(subType), m_eJobType(S00d947e0_JOB_DYNAMICS), m_spuType(S00d947e0_SPU_DISABLED), m_iElementCount(size),
          m_iAffinity(-1)
    {}
};

struct S00d947e0_DynJob : S00d947e0_Job
{
    short m_10;
    short m_12;
    int m_14;
    S00d947e0_Info* m_18;
    int m_1c;

    __forceinline S00d947e0_DynJob(unsigned char subType, unsigned short size, const S00d947e0_Data& src)
        : S00d947e0_Job(subType, size)
    {
        m_10 = src.unk10;
        m_14 = src.unk14;
    }
};

struct S00d947e0_Cmd : S00d947e0_DynJob
{
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    short m_34;
    short m_36;
    int m_38;
    unsigned char m_3c;
    unsigned char m_3d;
    short m_3e;
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

    __forceinline S00d947e0_Cmd(const S00d947e0_Data& src, S00d947e0_Info* info) : S00d947e0_DynJob(0xb, 0x40, src)
    {
        m_18 = info;
        m_1c = src.unk1c;
        m_20 = info->unk78;
        m_36 = 0;
        m_3c = 0;
        m_34 = info->unk54;
        m_30 = info->unk14;
    }
};

struct S00d947e0_Queue
{
    void FUN_00d04b50(const S00d947e0_Job& job, int a);
    void ProcessCallback(S00d947e0_Data* a, S00d947e0_Data* b, int c);
};

static __forceinline void S00d947e0_memClear16(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
}

// Writes profiler records, clears a buffer, calls FUN_00d8d030, queues an S00d947e0_Cmd via a2->FUN_00d04b50, calls FUN_00df0680, then calls a2->ProcessCallback.
// @f3 0x00a23820 (community match, verified in this file)
// 0x00a23820 - hkCpuSolveConstraintsJob (Havok thread pool): monitor-stream timer begin, solver
// temporaries cleared, constraints solved, integrate-motion job queued, solver results exported, job finished.
#include <new>

struct P2PJobFields
{
    unsigned short m_jobType;
    unsigned short m_islandIndex;
    void* m_island;
    void* m_taskHeader;
    int m_pad0c;
    void* m_buffer;
    int m_bufferSize;
    int m_accumulatorsOffset;
    int m_schemasOffset;
    int m_solverTempOffset;
    int m_numSolverResults;
    int m_numSolverElemTemps;
};

struct P2PHeaderFields
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void* m_buffer;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void* m_accumulatorsBase;
    void* m_accumulatorsEnd;
    unsigned short m_38;
    unsigned short m_3a;
    void* m_schemasBase;
    void* m_solverTempBase;
    int m_44;
    int m_48;
    void* m_4c;
    void* m_50;
    unsigned short m_numAllEntities;
    unsigned short m_entitiesCapacity;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    void* m_firstSolveJacobiansTask;
};

struct P2PThreadFields
{
    void* m_world;
    void* m_simulation;
    int m_threadType;
};

struct P2PJobBase
{
    unsigned short m_jobType;
    unsigned short m_islandIndex;
    void* m_island;
    void* m_taskHeader;
    int m_pad0c;

    P2PJobBase( int type, int islandIndex, void* island, void* taskHeader )
    {
        m_jobType = (unsigned short)type;
        m_islandIndex = (unsigned short)islandIndex;
        m_island = island;
        m_taskHeader = taskHeader;
    }
};

struct P2PIntegrateMotionJob : P2PJobBase
{
    void* m_solveTask;
    int m_pad14;
    int m_pad18;
    int m_pad1c;
    void* m_buffer;
    unsigned short m_numEntities;
    unsigned short m_firstEntityIdx;
    int m_numInactiveFrames;

    P2PIntegrateMotionJob( const P2PJobFields& job, void* solveTask, void* buffer, int firstEntityIdx, int numEntities )
        : P2PJobBase( 11, job.m_islandIndex, job.m_island, job.m_taskHeader )
    {
        m_solveTask = solveTask;
        m_firstEntityIdx = (unsigned short)firstEntityIdx;
        m_numEntities = (unsigned short)numEntities;
        m_buffer = buffer;
    }
};

struct P2PTimerRecord
{
    const char* m_pTag;
    unsigned int m_dwTime;
    int unk08;
};

struct P2PTimerRecord4
{
    const char* m_pTag;
    unsigned int m_dwTime;
    int unk08;
    const char* m_pSplitTag;
};

struct P2PTimerBuffer
{
    int unk00;
    P2PTimerRecord* m_pCurrent;
    int unk08;
    P2PTimerRecord* m_pRecordEnd;
};

struct P2PJobEntry
{
    unsigned int m_data[32];
};

struct P2PQueueApi
{
    void addJob( void* job, int priority, int type );
    int finishJobAndGetNextJob( int threadType, const void* oldJob, P2PJobEntry& jobOut, void* params = 0, int wait = 0 );
};

// pdb: hkCpuSolveConstraintsJob | hkpCpuSolveConstraintsJobs.obj | fnv360_0822_retail, strset, low
// pdb params: tl, jobQueue, jobInOut
void __cdecl FUN_00d947e0( S00d947e0_Obj** a1, S00d947e0_Queue* apQueue, S00d947e0_Data* apData )
{
    extern void* (__stdcall* DAT_00d9b080)( unsigned long );
    void __cdecl FUN_00a14ee0( void* info, void* schemas, void* accumulators, void* temp );
    void __cdecl hkExportImpulsesAndRhs( void* info, void* solverTemp, void* schemas, void* accumulators );
    extern const char DAT_00e7d35c[];
    extern const char DAT_00e855d8[];
    extern const char DAT_00e855ec[];
    extern const char DAT_00e0811c[];

    volatile unsigned int tb;

    P2PTimerBuffer* pTb = (P2PTimerBuffer*)DAT_00d9b080( DAT_0126835c );
    P2PTimerRecord* pRec = pTb->m_pCurrent;
    if ( pRec < pTb->m_pRecordEnd )
    {
        P2PTimerRecord4* pRec4 = (P2PTimerRecord4*)pRec;
        pRec4->m_pTag = DAT_00e7d35c;
        pRec4->m_pSplitTag = DAT_00e855d8;
        __asm
        {
            rdtsc
            mov dword ptr [tb], eax
        }
        pRec4->m_dwTime = tb;
        pTb->m_pCurrent = (P2PTimerRecord*)( (char*)pRec + 0x10 );
    }

    P2PJobFields* pJob = (P2PJobFields*)apData;
    char* pBuffer = (char*)pJob->m_buffer;
    char* pAcc = pBuffer + pJob->m_accumulatorsOffset;
    char* pSch = pBuffer + pJob->m_schemasOffset;
    char* pTmp = pBuffer + pJob->m_solverTempOffset;
    unsigned int size = ( (unsigned int)pJob->m_numSolverElemTemps * 4 + 15 ) & 0xfffffff0;

    S00d947e0_memClear16( (int*)pTmp, (int)( size >> 4 ) );

    FUN_00a14ee0( (char*)( (P2PThreadFields*)a1 )->m_world + 0x1a0, pSch, pAcc, pTmp );

    P2PHeaderFields* pHeader = (P2PHeaderFields*)pJob->m_taskHeader;

    {
        __declspec(align(16)) P2PJobEntry jobBuffer;
        (void)new ( &jobBuffer ) P2PIntegrateMotionJob( *pJob, pHeader->m_firstSolveJacobiansTask, pHeader->m_buffer, 0,
                                                        pHeader->m_numAllEntities );
        ((P2PQueueApi*)apQueue)->addJob( &jobBuffer, 0, 0 );
    }

    {
        P2PTimerBuffer* pTb2 = (P2PTimerBuffer*)DAT_00d9b080( DAT_0126835c );
        P2PTimerRecord* pRec2 = pTb2->m_pCurrent;
        if ( pRec2 < pTb2->m_pRecordEnd )
        {
            pRec2->m_pTag = DAT_00e855ec;
            __asm
        {
            rdtsc
            mov dword ptr [tb], eax
        }
            pRec2->m_dwTime = tb;
            pTb2->m_pCurrent = (P2PTimerRecord*)( (char*)pRec2 + 0xc );
        }
    }

    hkExportImpulsesAndRhs( (char*)( (P2PThreadFields*)a1 )->m_world + 0x1a0, pHeader->m_solverTempBase, pHeader->m_schemasBase,
                  pHeader->m_accumulatorsBase );

    {
        P2PTimerBuffer* pTb3 = (P2PTimerBuffer*)DAT_00d9b080( DAT_0126835c );
        P2PTimerRecord* pRec3 = pTb3->m_pCurrent;
        if ( pRec3 < pTb3->m_pRecordEnd )
        {
            pRec3->m_pTag = DAT_00e0811c;
            __asm
        {
            rdtsc
            mov dword ptr [tb], eax
        }
            pRec3->m_dwTime = tb;
            pTb3->m_pCurrent = (P2PTimerRecord*)( (char*)pRec3 + 0xc );
        }
    }

    ((P2PQueueApi*)apQueue)->finishJobAndGetNextJob( ( (P2PThreadFields*)a1 )->m_threadType, apData,
                                                     *(P2PJobEntry*)apData );
}

// @f3 0x00a239c0 (community match, verified in this file)
namespace f3m_00a239c0 {
// 0x00a239c0: hkCpuBuildJacobiansFromTask of Havok 5.5.0 (hkpDynamics, hkpCpuBuildJacobiansJob.cpp), a file-local
// (static) function: for every atom info of a build-jacobians task it points the constraint query at the constraint's
// two velocity accumulators, transforms and runtime, and builds the jacobian schemas (the contact path or the
// atoms path); then it ends the task's schemas, or links them to the next task's with a goto schema.
// The declarations are the SDK's, cut down to what the code uses. The pack's staging unit declares none of them.

typedef float hkReal;

class hkBool
{
	public:
		hkBool( bool b ) { m_bool = static_cast<char>( b ); }
		operator bool() const { return m_bool != 0; }

		char m_bool;
};

class hkTransform;
class hkpConstraintInstance;
class hkpConstraintAtom;
class hkpSimpleContactConstraintAtom;

class hkpVelocityAccumulator
{
	public:
		hkReal m_data[32];
};

class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO
		};

		static void setType( hkpJacobianSchema* schema, signed char type )
		{
			*reinterpret_cast<hkReal*>( schema ) += 1.192092896e-07f;
			*reinterpret_cast<signed char*>( schema ) = type;
		}
};

class hkpJacobianGotoSchema
{
	public:
		void initOffset( int offset )
		{
			m_offset = offset;
			hkpJacobianSchema::setType( reinterpret_cast<hkpJacobianSchema*>( this ), hkpJacobianSchema::SCHEMA_TYPE_GOTO );
		}

		int m_type;
		int m_offset;
		int m_pad[2];
};

class hkpConstraintQueryStepInfo
{
	public:
		hkReal m_substepDeltaTime;
		hkReal m_microStepDeltaTime;
		hkReal m_substepInvDeltaTime;
		hkReal m_frameDeltaTime;
		hkReal m_frameInvDeltaTime;
		hkReal m_invNumSteps;
		hkReal m_invNumStepsTimesMicroSteps;
		hkReal m_maxConstraintViolationSqrd;
		hkReal m_rhsFactor;
		hkReal m_virtMassFactor;
		hkReal m_frictionRhsFactor;
		hkReal m_microStepInvDeltaTime;
};

class hkpConstraintQueryIn : public hkpConstraintQueryStepInfo
{
	public:
		const hkpVelocityAccumulator* m_bodyA;
		const hkpVelocityAccumulator* m_bodyB;
		const hkTransform* m_transformA;
		const hkTransform* m_transformB;
		hkReal m_tau;
		hkReal m_damping;
		hkpConstraintInstance* m_constraintInstance;
		void* m_constraintRuntime;
		unsigned int m_accumulatorAIndex;
		unsigned int m_accumulatorBIndex;
		void* m_constraintRuntimeInMainMemory;
};

class hkpConstraintQueryOut
{
	public:
		hkpJacobianSchema* m_jacobianSchemas;
};

class hkpConstraintAtom
{
	public:
		enum AtomType { TYPE_CONTACT = 22 };

		AtomType getType() const { return AtomType( m_type ); }

		unsigned short m_type;
};

struct AtomInfo
{
	hkpConstraintAtom* m_atoms;
	hkpConstraintInstance* m_instance;
	void* m_runtime;
	const hkTransform* m_transformA;
	const hkTransform* m_transformB;
	unsigned short m_atomsSize;
	unsigned short m_runtimeSize;
	unsigned short m_accumulatorIndexA;
	unsigned short m_accumulatorIndexB;
};

struct hkBuildJacobiansFromTaskInput
{
	AtomInfo* m_atomInfos;
	int m_numAtomInfos;
	hkpVelocityAccumulator* m_accumulators;
	hkpJacobianSchema* m_schemas;
	hkpJacobianSchema* m_schemasOfNextTask;
	void* m_nextTask;
	hkBool m_finishSchemasWithGoto;
};

void __cdecl hkSimpleContactConstraintDataBuildJacobian( const hkpSimpleContactConstraintAtom* atom, const hkpConstraintQueryIn& in, hkBool writeHeaderSchema, hkpConstraintQueryOut& out );
void __cdecl hkSolverBuildJacobianFromAtomsNotContact( const hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryIn& in, hkpConstraintQueryOut& out );

static void FUN_00a239c0( const hkBuildJacobiansFromTaskInput& input, hkpConstraintQueryIn& queryIn )
{
	hkpConstraintQueryOut queryOut;
	queryOut.m_jacobianSchemas = input.m_schemas;

	{
		const AtomInfo* atomInfos = input.m_atomInfos;
		int numAtomInfos = input.m_numAtomInfos;
		for ( int i = 0; i < numAtomInfos; )
		{
			const AtomInfo& atomInfo = atomInfos[i++];

			queryIn.m_transformA = atomInfo.m_transformA;
			queryIn.m_transformB = atomInfo.m_transformB;
			queryIn.m_bodyA = &input.m_accumulators[atomInfo.m_accumulatorIndexA];
			queryIn.m_bodyB = &input.m_accumulators[atomInfo.m_accumulatorIndexB];
			queryIn.m_accumulatorAIndex = atomInfo.m_accumulatorIndexA;
			queryIn.m_accumulatorBIndex = atomInfo.m_accumulatorIndexB;
			queryIn.m_constraintInstance = atomInfo.m_instance;
			queryIn.m_constraintRuntime = atomInfo.m_runtime;
			queryIn.m_constraintRuntimeInMainMemory = atomInfo.m_runtime;

			int sizeOfAllAtoms = atomInfo.m_atomsSize;
			hkpConstraintAtom* atoms = atomInfo.m_atoms;
			if ( atoms->getType() == hkpConstraintAtom::TYPE_CONTACT )
			{
				hkBool writeHeaderSchema = true;
				hkSimpleContactConstraintDataBuildJacobian( reinterpret_cast<hkpSimpleContactConstraintAtom*>( atoms ), queryIn, writeHeaderSchema, queryOut );
			}
			else
			{
				hkSolverBuildJacobianFromAtomsNotContact( atoms, sizeOfAllAtoms, queryIn, queryOut );
			}
		}
	}

	if ( !input.m_finishSchemasWithGoto )
	{
		hkpJacobianSchema* endSchema = queryOut.m_jacobianSchemas;
		*reinterpret_cast<int*>( endSchema ) = 0;
		queryOut.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( reinterpret_cast<char*>( endSchema ) + 16 );
	}
	else
	{
		int branchOffset = int( reinterpret_cast<char*>( input.m_schemasOfNextTask ) - reinterpret_cast<char*>( queryOut.m_jacobianSchemas ) );
		if ( branchOffset > 0 )
		{
			hkpJacobianGotoSchema* gotoSchema = reinterpret_cast<hkpJacobianGotoSchema*>( queryOut.m_jacobianSchemas );
			gotoSchema->initOffset( branchOffset );
			queryOut.m_jacobianSchemas = reinterpret_cast<hkpJacobianSchema*>( gotoSchema + 1 );
		}
	}
}

// A STAND-IN caller, not a function of the game: it only makes the compiler emit the static FUN_00a239c0 above.
void standInCallerOfBuildJacobiansFromTask( const hkBuildJacobiansFromTaskInput& input, hkpConstraintQueryIn& queryIn )
{
	FUN_00a239c0( input, queryIn );
}
}   // namespace f3m_00a239c0
