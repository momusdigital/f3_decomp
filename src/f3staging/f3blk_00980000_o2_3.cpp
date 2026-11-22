#pragma intrinsic(__rdtsc)
#pragma intrinsic(_ReadWriteBarrier)
// src/f3staging/f3blk_00980000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x0098b810 (community match, verified in this file)
namespace f3m_0098b810 {
namespace w98b810
{
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct Heap98b810
{
    void* FUN_008f6800(unsigned int uiSize, unsigned int uiType);

    // The heap object is only known through this function's uses; fields are named by offset, as the unit does.
    int m_iUnk00, m_iUnk04, m_iUnk08, m_iUnk0C, m_iUnk10, m_iUnk14, m_iUnk18, m_iUnk1C;
    int m_iUnk20, m_iUnk24, m_iUnk28, m_iUnk2C, m_iUnk30, m_iUnk34, m_iUnk38, m_iUnk3C;
    int m_iUnk40, m_iUnk44, m_iUnk48, m_iUnk4C, m_iUnk50, m_iUnk54;
    void* m_pFree;      // +0x58
    int   m_iCount;     // +0x5c
};

struct Node98b810
{
    Node98b810* m_pNext;    // +0x00: the free list link
    int m_iUnk04, m_iUnk08, m_iUnk0C, m_iUnk10, m_iUnk14;
    int m_iUnk18, m_iUnk1C;
    unsigned int m_uiUnk20;
    int m_iUnk24;
    Node98b810* m_pUnk28;
};

struct Lock98b810
{
    void FUN_00908a00();
};

extern Lock98b810 DAT_011692e8;
extern void (__stdcall* DAT_00d9b0a0)(Lock98b810*);
extern int (__stdcall* DAT_00d9b1ac)(Node98b810*, unsigned int);
extern Node98b810* DAT_01169310;
extern int DAT_01169300;
extern int DAT_01169304;
extern Node98b810* DAT_01169318;
}

void __cdecl FUN_0098b810(void)
{
    using namespace w98b810;

    int iUnset = -1;
    Heap98b810* pHeap = (Heap98b810*)w98b810::DAT_00d9b080(w98b810::DAT_010f3170);
    Node98b810* pNode = (Node98b810*)pHeap->m_pFree;

    if (pNode != 0) {
        pHeap->m_iCount += iUnset;
        pHeap->m_pFree = pNode->m_pNext;
    } else {
        pNode = (Node98b810*)pHeap->FUN_008f6800(4, 0x15);
    }

    if (pNode != 0) {
        pNode->m_uiUnk20 = 1000;
        pNode->m_iUnk24 = 0;
        pNode->m_pUnk28 = 0;

        w98b810::DAT_011692e8.FUN_00908a00();

        pNode->m_pUnk28 = w98b810::DAT_01169310;
        if (pNode->m_pUnk28 != 0) {
            pNode->m_pUnk28->m_iUnk24 = (int)pNode;
        }
        pNode->m_iUnk24 = (int)&w98b810::DAT_011692e8;
        w98b810::DAT_01169310 = pNode;
        w98b810::DAT_01169300 = iUnset;
        w98b810::DAT_01169304 = iUnset;

        w98b810::DAT_00d9b0a0(&w98b810::DAT_011692e8);
        w98b810::DAT_00d9b1ac(pNode, 1000);

        pNode->m_iUnk18 = iUnset;
        pNode->m_iUnk1C = iUnset;
        w98b810::DAT_01169318 = pNode;
    } else {
        w98b810::DAT_01169318 = 0;
    }
}
}   // namespace f3m_0098b810

// @f3 0x0098b7d0 (community match, verified in this file)
extern void* g_lock_0098b7d0;
namespace f3m_0098b7d0 {

namespace fn_0098b7d0 {

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

struct LockState
{
    int m_f00, m_f04, m_f08, m_f0c, m_f10, m_f14;
    int owner;
    int depth;
    void FUN_00908a00();
};

struct ScopedLock
{
    LockState* lock;
    ScopedLock(LockState* l) : lock(l) { l->FUN_00908a00(); }
    ~ScopedLock() { lock->owner = -1; lock->depth = -1; LeaveCriticalSection(lock); }
};

struct RefHandleObj
{
    int id;
    short refCount;
    unsigned short memFlags;
    void FUN_0098b7d0();
};

void RefHandleObj::FUN_0098b7d0()
{
    if (id == -0x2f)
        return;
    ScopedLock guard(static_cast<LockState*>(g_lock_0098b7d0));
    memFlags >>= 1;
    if (--refCount == 0)
        id = -0xf;
}

} // namespace fn_0098b7d0
}   // namespace f3m_0098b7d0

// @f3 0x00998850 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00998850 {
namespace n998850 {
struct Obj;
struct BlockArray { unsigned char** data; int size; int capAndFlags; };
struct Track { unsigned int used; BlockArray blocks; };
struct Allocator { void* FUN_008f6d30(int bytes, int memoryClass); };
extern Allocator* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901f10(void* array, int elementSize);
// pdb: hkAgentNnMachine_AllocateEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, call_seq + bridge(caller|call_gap) + skyrim(call_seq), high
static __declspec(noinline) Obj* hkAgentNnMachine_AllocateEntry(Track* track) {
 if(track->used<0x200u) {
  unsigned char* page=track->blocks.data[track->blocks.size-1];
  Obj* result=reinterpret_cast<Obj*>(page+track->used);
  track->used+=0x80u;
  return result;
 }
 Allocator* allocator=DAT_00d9b080(DAT_010f3170);
 unsigned char* page=static_cast<unsigned char*>(allocator->FUN_008f6d30(0x200,0x27));
 BlockArray* blocks=&track->blocks;
 if(blocks->size==(blocks->capAndFlags&0x3fffffff))FUN_00901f10(blocks,4);
 blocks->data[blocks->size++]=page;
 track->used=0x80;
 return reinterpret_cast<Obj*>(page);
}
Track* volatile g_track;
Obj* caller_of_FUN_00998850() { return hkAgentNnMachine_AllocateEntry(g_track); }
}
}   // namespace f3m_00998850

// @f3 0x009988c0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009988c0 {
namespace f3m_009988c0 {
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct LifoAllocator
{
    void FUN_008f6d90(void* block, int bytes, int memoryClass);
};
void __cdecl hkArrayUtil__reduce(void* array, int elemSize, void* storage, int capacity);
struct BlockArray
{
    char** data;
    int count;
    unsigned int capacityFlags;
    char* storage;
    char* back() { return data[count - 1]; }
    void popBack() { count--; }
};
struct LifoState
{
    int free;
    BlockArray blocks;
};
// pdb: hkAgentNnMachine_DeallocateLastEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) void hkAgentNnMachine_DeallocateLastEntry(LifoState* state)
{
    state->free -= 0x80;
    if (state->free == 0)
    {
        char* block = state->blocks.back();
        state->blocks.popBack();
        LifoAllocator* allocator = (LifoAllocator*)DAT_00d9b080(DAT_010f3170);
        allocator->FUN_008f6d90(block, 0x200, 0x27);
        state->free = 0x200;
    }
    BlockArray* blocks = &state->blocks;
    unsigned int capacityFlags = blocks->capacityFlags;
    if ((capacityFlags & 0x80000000u) == 0)
    {
        unsigned int n = blocks->count + 3;
        n |= n >> 16;
        n |= n >> 8;
        n |= n >> 4;
        n |= n >> 2;
        int wanted = (int)((n | (n >> 1)) + 1);
        if (wanted < 1)
        {
            hkArrayUtil__reduce(blocks, 4, &blocks->storage, 1);
        }
        else if (wanted < (int)(capacityFlags & 0x3fffffff))
        {
            hkArrayUtil__reduce(blocks, 4, 0, wanted);
        }
    }
}
LifoState* volatile g_state_9988c0;
void caller_of_FUN_009988c0() { hkAgentNnMachine_DeallocateLastEntry(g_state_9988c0); }
}
}   // namespace f3m_009988c0

// @f3 0x00987cb0 (community match, verified in this file)
namespace f3m_00987cb0 {
// FUN_00987cb0 = Havok 5.5.0 hkpSimpleConstraintContactMgr::`scalar deleting destructor' (hkpDynamics.lib, hkpSimpleConstraintContactMgr.obj;
// ??_GhkpSimpleConstraintContactMgr@@UAEPAXI@Z). The stock release object is byte-identical to the game.
// The compiler generates the function. hkpSimpleConstraintContactMgr.cpp does not ship; the source is the SDK header
// hkpSimpleConstraintContactMgr.h (class, virtual ~hkpSimpleConstraintContactMgr declared only; operator delete of hkpContactMgr's
// HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_CONTACT), which the compiler inlines into the deleting destructor) plus the SDK macro
// HK_REFLECTION_DEFINE_VIRTUAL(hkpSimpleConstraintContactMgr) (hkTypeInfo.h; shown expanded, the way hktrim.py writes it), which makes
// the compiler emit the vtable and the deleting destructor. Cut with hktrim.py.
// RENAME (ours): the class hkpSimpleConstraintContactMgr is named FUN_00987cb0 inside namespace f3m_00987cb0, as on 0x00944440 and
// 0x00962850, so the checker can find the compiler-generated ??_G.
namespace f3m_00987cb0 {
typedef float  hkReal;
typedef signed short	hkInt16;
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

			typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;

class hkBool
{
	public:
		inline hkBool(bool b)
		;
	private:
		char m_bool;
};

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
	private:
		STORAGE m_storage;
};

		extern "C" {
			__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
		}

		template<typename T>
		class hkThreadLocalData
		{
			public:
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
		        class MustEndWithSemiColon;
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void  alignedDeallocate(void* ptr);
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
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
			__declspec(align(16)) char* m_current;
			Stack* m_prev;
			char* m_base;
			char* m_end;
		};
	protected:
		enum { BATCH_SIZE=4 };
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
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
		int m_finishing;
	private:
		        class MustEndWithSemiColon;
};

class hkBaseObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline virtual ~hkBaseObject() {}
};

class hkStatisticsCollector;

class hkReferencedObject : public hkBaseObject
{
	public:
		        __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { }       class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkReferencedObject() { }
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

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
	public:
		T m_storage[N];
};


class hkVector4
{
	public:
		                class MustEndWithSemiColon;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		                class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};

class hkpCdBody;
class hkpCollidable;

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};

class hkpConstraintInstance;

struct hkpConstraintInfo
{
	                class MustEndWithSemiColon;
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
};

class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
typedef void hkpConstraintRuntime;

class hkpConstraintData : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
        enum ConstraintType
        {
            CONSTRAINT_TYPE_BALLANDSOCKET = 0,
            CONSTRAINT_TYPE_HINGE = 1,
            CONSTRAINT_TYPE_LIMITEDHINGE = 2,
            CONSTRAINT_TYPE_POINTTOPATH = 3,
            CONSTRAINT_TYPE_PRISMATIC = 6,
            CONSTRAINT_TYPE_RAGDOLL = 7,
            CONSTRAINT_TYPE_STIFFSPRING = 8,
            CONSTRAINT_TYPE_WHEEL = 9,
            CONSTRAINT_TYPE_GENERIC = 10,
            CONSTRAINT_TYPE_CONTACT = 11,
            CONSTRAINT_TYPE_BREAKABLE = 12,
            CONSTRAINT_TYPE_MALLEABLE = 13,
            CONSTRAINT_TYPE_POINTTOPLANE = 14,
	        CONSTRAINT_TYPE_PULLEY = 15,
			CONSTRAINT_TYPE_ROTATIONAL = 16,
			CONSTRAINT_TYPE_HINGE_LIMITS = 18,
			CONSTRAINT_TYPE_RAGDOLL_LIMITS = 19,
			CONSTRAINT_TYPE_CUSTOM = 20,
	        BEGIN_CONSTRAINT_CHAIN_TYPES = 100,
	        CONSTRAINT_TYPE_STIFF_SPRING_CHAIN = 100,
	        CONSTRAINT_TYPE_BALL_SOCKET_CHAIN = 101,
	        CONSTRAINT_TYPE_POWERED_CHAIN = 102
        };
		inline virtual ~hkpConstraintData();
		virtual hkBool isValid() const = 0;
		virtual int getType() const = 0;
		struct RuntimeInfo
		{
			                class MustEndWithSemiColon;
			int m_sizeOfExternalRuntime;
			int m_numSolverResults;
		};
		virtual void getRuntimeInfo( hkBool wantRuntime, RuntimeInfo& infoOut ) const = 0;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual void addInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
	protected:
		friend class hkpConstraintSolverSetup;
	public:
		virtual void buildJacobian( const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out ) { ; }
		virtual hkBool isBuildJacobianCallbackRequired() const { return false; }
		virtual void buildJacobianCallback( const hkpConstraintQueryIn &in ) { ; }
		struct ConstraintInfo : public hkpConstraintInfo
		{
			                class MustEndWithSemiColon;
			struct hkpConstraintAtom* m_atoms;
			hkUint32		  m_sizeOfAllAtoms;
		};
		virtual void getConstraintInfo( ConstraintInfo& infoOut ) const = 0;
	public:
		hkUlong m_userData;
};

class hkpEntity;

class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
		enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
		enum AddReferences
		{
			DO_NOT_ADD_REFERENCES,
			DO_ADD_REFERENCES
		};
		enum CloningMode
		{
			CLONE_INSTANCES_ONLY,
			CLONE_DATAS_WITH_MOTORS
		};
		~hkpConstraintInstance();
	public:
		virtual void entityAddedCallback(hkpEntity* entity);
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual void entityDeletedCallback( hkpEntity* entity );
		virtual InstanceType getType() const { return TYPE_NORMAL; }
	protected:
		friend class hkpSimpleContactConstraintData;
		friend class hkpSimulationIsland;
		class hkpConstraintOwner* m_owner;
		class hkpConstraintData*  m_data;
		struct hkpModifierConstraintAtom* m_constraintModifiers;
		class hkpEntity* m_entities[2];
	public:
		hkEnum<ConstraintPriority,hkUint8> m_priority;
	protected:
		hkBool				m_wantRuntime;
		const char* m_name;
	public:
		hkUlong m_userData;
		struct hkConstraintInternal* m_internal;
	public:
		hkpConstraintInstance(hkFinishLoadedObjectFlag f) ;
	private:
		friend class hkpWorldConstraintUtil;
		friend class FUN_00987cb0;
		friend class hkpSaveContactPointsUtil;
};

struct hkpCollisionInput;
class hkpContactMgr;

class hkStatisticsCollector
{
	public:
		virtual ~hkStatisticsCollector() { m_clientData = 0; }
        enum { MAX_STATISTICS_CLASS_BIT = 5 };
		enum StatisticClass
		{
			MEMORY_ALL = 0xf,
			MEMORY_SHARED = 1,
			MEMORY_INSTANCE = 2,
			MEMORY_ENGINE = 4,
			MEMORY_RUNTIME = 8,
			MEMORY_APPLICATION = 16,
			MEMORY_LAST = 32
		};
		virtual void beginObject( const char* name, StatisticClass statisticClass, const hkReferencedObject* object ) = 0;
		virtual void addChunk( const char* name, StatisticClass statisticClass, const void* chunkAddress, int usedSize, int allocatedSize = 0) = 0;
		virtual void addChildObject( const char* name, StatisticClass statisticClass, const hkReferencedObject* object ) = 0;
		virtual void pushDir( const char* dirName ) = 0;
		virtual void popDir() = 0;
		virtual void endObject( ) = 0;
	public:
		const void* m_clientData;
};

class hkpContactMgrFactory: public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		virtual hkpContactMgr*	createContactMgr( const hkpCollidable& a, const hkpCollidable& b, const hkpCollisionInput& input ) = 0;
        virtual void calcStatistics( hkStatisticsCollector* collector ) const
        {
            collector->beginObject("hkpContactMgrFactory", collector->MEMORY_INSTANCE, this);
            collector->endObject();
        }
};

struct hkpProcessCollisionData;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpGskCache;

class hkContactPointMaterial
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		                class MustEndWithSemiColon;
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		enum  FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL  = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};

struct hkpSimpleContactConstraintAtom;

class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
};

class hkpContactMgr: public hkReferencedObject
{
	public:
		  __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CONTACT); } __forceinline void __cdecl operator delete(void*, void*) { }             class MustEndWithSemiColon;
		enum Type
		{
			TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
			TYPE_REPORT_CONTACT_MGR,
			TYPE_CONVEX_LIST_CONTACT_MGR,
			TYPE_NULL_CONTACT_MGR,
			TYPE_USER_CONTACT_MGR,
			TYPE_MAX
		};
		enum ToiAccept
		{
			TOI_ACCEPT = 0,
			TOI_REJECT = 1
		};
	public:
		virtual hkContactPointId addContactPointImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp ) = 0;
		virtual hkResult reserveContactPointsImpl( int numPoints ) = 0;
		virtual void removeContactPointImpl( hkContactPointId cpId, hkpConstraintOwner& constraintOwner ) = 0;
		virtual void processContactImpl( const hkpCollidable& a, const hkpCollidable& b, const hkpProcessCollisionInput& input, hkpProcessCollisionData& collisionData ) = 0;
		virtual ToiAccept addToiImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut ) = 0;
		virtual void removeToiImpl( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties ) = 0;
		virtual void cleanup(){}
	public:
		Type m_type;
};

class hkpDynamicsContactMgr: public hkpContactMgr
{
	public:
		hkpDynamicsContactMgr( Type type );
		virtual hkpContactPointProperties* getContactPointProperties( hkContactPointId id ){ return 0;}
		virtual hkContactPoint* getContactPoint( hkContactPointId id ){ return 0;}
		virtual void getAllContactPointIds( hkArray<hkContactPointId>& contactPointIds ) const {}
		virtual Type getType() const = 0;
		virtual void toiCollisionResponseBeginCallback( const hkContactPoint& cp, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB){}
		virtual void toiCollisionResponseEndCallback( const hkContactPoint& cp, hkReal impulseApplied, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB){}
		virtual class hkpConstraintInstance* getConstraintInstance() { return 0; }
		virtual void confirmToi( struct hkpToiEvent& event, hkReal rotateNormal, class hkArray<class hkpEntity*>& outToBeActivated ){}
	protected:
		class hkpWorld*					m_world;
};

class hkpDynamicsCpIdMgr
{
	public:
		                class MustEndWithSemiColon;
		enum { HK_MAX_IDS_PER_OBJECT = 8 };
		enum { FREE_VALUE = 0xff };
		typedef hkUchar hkpValueType;
	public:
		hkInplaceArray<hkpValueType,HK_MAX_IDS_PER_OBJECT>	m_values;
};

class hkpSimpleContactConstraintData: public hkpConstraintData
{
	public:
		inline ~hkpSimpleContactConstraintData();
		virtual hkBool isValid() const;
		virtual void getConstraintInfo( hkpConstraintData::ConstraintInfo& infoOut ) const;
		virtual void getRuntimeInfo( hkBool wantRuntime, hkpConstraintData::RuntimeInfo& infoOut ) const;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual int getType() const;
		virtual void collisionResponseBeginCallback( const hkContactPoint& cp, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB );
		virtual void collisionResponseEndCallback( const hkContactPoint& cp, hkReal impulseApplied, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB);
		inline hkpSimpleContactConstraintData( hkFinishLoadedObjectFlag f ) ;
	public:
		hkpDynamicsCpIdMgr		m_idMgrA;
		void*					m_clientData;
		hkpConstraintInstance*	m_constraint;
		hkpSimpleContactConstraintAtom*	m_atom;
		int								m_atomSize;
};

class FUN_00987cb0: public hkpDynamicsContactMgr
{
	public:
		~FUN_00987cb0();
		inline FUN_00987cb0( hkFinishLoadedObjectFlag f ) : hkpDynamicsContactMgr( hkpContactMgr::TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR), m_contactConstraintData(f), m_constraint(f) {}
		hkContactPoint* getContactPoint( hkContactPointId id );
		hkpContactPointProperties* getContactPointProperties( hkContactPointId id );
		hkContactPointId addContactPointImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp );
		hkResult reserveContactPointsImpl( int numPoints );
		void removeContactPointImpl( hkContactPointId cpId, hkpConstraintOwner& constraintOwner );
		void processContactImpl( const hkpCollidable& a, const hkpCollidable& b, const hkpProcessCollisionInput& input, hkpProcessCollisionData& collisionData );
		ToiAccept addToiImpl( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& properties );
		void removeToiImpl( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties );
		virtual void confirmToi( struct hkpToiEvent& event, hkReal rotateNormal, class hkArray<class hkpEntity*>& outToBeActivated );
		virtual void cleanup(){ delete this; }
		virtual Type getType() const { return TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR; }
		virtual void getAllContactPointIds( hkArray<hkContactPointId>& contactPointIds ) const;
		virtual hkpConstraintInstance* getConstraintInstance();
		virtual void toiCollisionResponseBeginCallback( const hkContactPoint& cp, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB);
		virtual void toiCollisionResponseEndCallback( const hkContactPoint& cp, hkReal impulseApplied, struct hkpSimpleConstraintInfoInitInput& inA, struct hkpBodyVelocity& velA, hkpSimpleConstraintInfoInitInput& inB, hkpBodyVelocity& velB);
	protected:
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		class Factory: public hkpContactMgrFactory
		{
			public:
				hkpContactMgr*	createContactMgr( const hkpCollidable& a, const hkpCollidable& b, const hkpCollisionInput& input );
			protected:
				hkpWorld* m_world;
		};
	public:
		hkUint16					m_reservedContactPoints;
		hkUint16					m_skipNextNprocessCallbacks;
		hkpSimpleContactConstraintData	m_contactConstraintData;
		hkpConstraintInstance			m_constraint;
		hkUint32					m_pad[4];
};

class hkTypeInfo
{
	public:
		typedef void (__cdecl *FinishLoadedObjectFunction)(void*);
		typedef void (__cdecl *CleanupLoadedObjectFunction)(void*);
		hkTypeInfo( const char* name,
				FinishLoadedObjectFunction finish,
				CleanupLoadedObjectFunction cleanup,
				const void* vtable )
			;
	private:
		const char* m_typeName;
		FinishLoadedObjectFunction m_finishLoadedObjectFunction;
		CleanupLoadedObjectFunction m_cleanupLoadedObjectFunction;
		const void* m_vtable;
};

static void __cdecl finishLoadedObjectFUN_00987cb0(void* p) { hkFinishLoadedObjectFlag f; f.m_finishing = 1; new (p) FUN_00987cb0(f); } static void __cdecl cleanupLoadedObjectFUN_00987cb0(void* p) { static_cast<FUN_00987cb0*>(p)->~FUN_00987cb0(); } static const void* __cdecl getVtableFUN_00987cb0() { union { __declspec(align(16)) void* ptr; char buf[sizeof(FUN_00987cb0)]; } u; hkFinishLoadedObjectFlag f; f.m_finishing = 1; new (u.buf) FUN_00987cb0(f); return u.ptr; }   const hkTypeInfo FUN_00987cb0TypeInfo( "FUN_00987cb0", finishLoadedObjectFUN_00987cb0, cleanupLoadedObjectFUN_00987cb0, getVtableFUN_00987cb0() );

}
}   // namespace f3m_00987cb0
