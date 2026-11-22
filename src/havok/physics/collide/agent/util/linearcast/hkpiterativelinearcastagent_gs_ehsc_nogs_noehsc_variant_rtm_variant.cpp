// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

namespace IterativeSweepSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float lane0, lane1, lane2, lane3;
    };
};
extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
    void _mm_store_ps(float*, __m128);
}
}
extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) IterativeSweep_hkVector4
{
    union
    {
        IterativeSweepSimd::__m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };

    __forceinline void SetAllComponents(float v)
    {
        IterativeSweepSimd::__m128 scalar = IterativeSweepSimd::_mm_load_ss(&v);
        quad = IterativeSweepSimd::_mm_shuffle_ps(scalar, scalar, 0);
    }
};

struct __declspec(align(16)) IterativeSweep_hkTransform
{
    IterativeSweep_hkVector4 m_kColumn0;
    IterativeSweep_hkVector4 m_kColumn1;
    IterativeSweep_hkVector4 m_kColumn2;
    IterativeSweep_hkVector4 m_vTranslation;
    IterativeSweep_hkVector4 m_center0;
    IterativeSweep_hkVector4 m_center1;
    IterativeSweep_hkVector4 m_qRotation0;
    IterativeSweep_hkVector4 m_qRotation1;
    IterativeSweep_hkVector4 m_centerLocal;
    IterativeSweep_hkVector4 m_kDeltaAngle;
    float m_fSphereRadius;
    float m_linearLimit;
    float m_fAngularLimit;
    float m_timeFactor;
    void CopyFrom(const void* src);
};

struct IterativeSweep_hkpShape
{
    void* vtable;
    int unk04;
    int unk08;
    int m_type;
};

struct IterativeSweep_hkpCdBody
{
    const IterativeSweep_hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_kMotionState;
    const IterativeSweep_hkpCdBody* m_parent;
};

struct __declspec(align(16)) IterativeSweep_hkContactPoint
{
    IterativeSweep_hkVector4 m_vContactPosition;
    IterativeSweep_hkVector4 m_vSeparatingNormal;
};

struct __declspec(align(16)) IterativeSweep_hkpRootCdPoint
{
    IterativeSweep_hkContactPoint m_kPoint;
    const IterativeSweep_hkpCdBody* m_pRootCollidableA;
    const IterativeSweep_hkpCdBody* m_pRootCollidableB;
};

struct IterativeSweep_hkpCdPointCollector
{
    virtual void unk_dtor();
    virtual void AddCdPoint(const IterativeSweep_hkpRootCdPoint& point) = 0;
    float m_fEarlyOutDistance;
};

extern float DAT_0104da48;

extern char DAT_010cebe0;
struct __declspec(align(16)) IterativeSweep_hkpSimpleClosestContactCollector
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    bool m_bHit;
    IterativeSweep_hkContactPoint m_kHitPoint;
    __forceinline IterativeSweep_hkpSimpleClosestContactCollector()
    {
        m_fEarlyOutDistance = m_kHitPoint.m_vSeparatingNormal.w = DAT_0104da48;
        m_ppVirtualMethodTable = &DAT_010cebe0;
        m_bHit = false;
    }
};

typedef void (*IterativeSweep_hkpLinearCastFunc)(const IterativeSweep_hkpCdBody*, const IterativeSweep_hkpCdBody*,
                                                 const void*, IterativeSweep_hkpSimpleClosestContactCollector*) throw();

struct IterativeSweep_AgentFunctions
{
    void* create;
    void* penetrations;
    IterativeSweep_hkpLinearCastFunc closest;
    void* linearCast;
    int flipped;
};
struct IterativeSweep_CollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    unsigned char m_types[32][32];
    unsigned char m_predictiveTypes[32][32];
    IterativeSweep_AgentFunctions m_functions[256];
};

struct IterativeSweep_hkpLinearCastPath
{
    float m_minDistance;
    int m_numIterations;
};

struct __declspec(align(16)) IterativeSweep_hkpCollisionInput
{
    IterativeSweep_CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
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
};

struct __declspec(align(16)) IterativeSweep_hkpLinearCastCollisionInput : public IterativeSweep_hkpCollisionInput
{
    IterativeSweep_hkVector4 m_step;
    float m_extraPenetration;
    float m_fMaxExtraPenetration;
    IterativeSweep_hkpLinearCastPath* m_path;
};

__forceinline float IterativeSweep_dot3(const IterativeSweep_hkVector4& a, const IterativeSweep_hkVector4& b)
{
    IterativeSweepSimd::__m128 mul = IterativeSweepSimd::_mm_mul_ps(a.quad, b.quad);
    IterativeSweepSimd::__m128 shuf1 = IterativeSweepSimd::_mm_shuffle_ps(mul, mul, 0x55);
    IterativeSweepSimd::__m128 shuf2 = IterativeSweepSimd::_mm_shuffle_ps(mul, mul, 0xaa);
    IterativeSweepSimd::__m128 sum = IterativeSweepSimd::_mm_add_ss(shuf1, mul);
    sum = IterativeSweepSimd::_mm_add_ss(shuf2, sum);
    float res;
    IterativeSweepSimd::_mm_store_ss(&res, sum);
    return res;
}

__forceinline IterativeSweep_hkpLinearCastFunc IterativeSweep_getLinearCastFunc(
    const IterativeSweep_CollisionDispatcher* dispatcher, int typeA, int typeB)
{
    unsigned char index = dispatcher->m_types[typeA][typeB];
    return dispatcher->m_functions[index].closest;
}

// @f3 0x00a3ab70 (community match, verified in this file)
// 0x00a3ab70: hkpIterativeLinearCastAgent::staticLinearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector) of
// Havok 5.5.0 (hkpCollide, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Casts body A along input.m_path against body B by repeated closest-point queries: a first query at the start
// position (its hit goes to startCollector when closer than the tolerance), early outs when the bodies separate or
// do not approach, then up to m_iterativeLinearCastMaxIterations steps that move a copy of A's motion state to the
// current fraction of the path and advance the fraction by distance over approach speed; the last contact point
// goes to the collector.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_00a3ab70 {

typedef float  hkReal;
typedef signed char		hkChar;
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
extern "C"
{
extern const hkReal hkUFloat8_intToReal[256];
}
class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
	inline hkUFloat8(){		}
	inline hkUFloat8& operator=(const float& fv)
	{
		hkInt32 f = *(int*)&fv;
		hkInt32* minf = (hkInt32*)&hkUFloat8_intToReal[0];
		hkInt32* maxf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE];
		hkInt32* midf = (hkInt32*)&hkUFloat8_intToReal[MAX_VALUE/2];
		for (int i = 6; i>=0; i--)
		{
			if ( f > midf[0]){		minf = midf;	}	else	{	maxf = midf;	}
			midf = (hkInt32*)(  (hkUlong(minf)>>1) + (hkUlong(maxf)>>1) );
		}
		if ( f > midf[0])
		{
			midf++;
		}
		hkUlong fi = midf - (hkInt32*)(&hkUFloat8_intToReal[0]);
		m_value = hkUint8(fi);
		return *this;
	}
	inline hkUFloat8(const float f)
	{
		*this = f;
	}
	inline operator float() const
	{
		return hkUFloat8_intToReal[m_value];
	}
public:
	hkUint8 m_value;
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
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThanEqual4(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline hkBool32 allLessThan4(hkVector4Parameter a) const;
		__forceinline void select32( hkVector4Parameter a, hkVector4Parameter b, const hkVector4Comparison& comp);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
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
		void setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		void setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		void setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		void _setMul4(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setMul4xyz1(const hkTransform& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkQsTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkReal dot3fpu(const hkVector4& a) const;
		__forceinline hkSimdReal dot4(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal horizontalAdd3() const;
		__forceinline hkSimdReal horizontalAdd4() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline hkSimdReal distanceTo3( hkVector4Parameter p ) const;
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
class hkQuaternion
{
	public:
		inline hkQuaternion() { }
		inline hkQuaternion(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		explicit inline hkQuaternion(const hkRotation& r);
		inline hkQuaternion(const hkVector4& axis, hkReal angle);
		inline void operator= (const hkQuaternion& q);
		inline void set(hkReal ix, hkReal iy, hkReal iz, hkReal r);
		static inline const hkQuaternion& __cdecl getIdentity();
		inline void setIdentity();
		inline void setInverse( const hkQuaternion &q );
		inline void normalize();
		inline void setMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void addMul(hkSimdRealParameter r, const hkQuaternion& q);
		inline void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void mul(const hkQuaternion& q);
		inline void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
		inline void estimateAngleTo(const hkQuaternion& to, hkVector4& angleOut) const;
		inline void setShortestRotation(const hkVector4& from, const hkVector4& to);
		inline void setShortestRotationDamped(hkReal gain, const hkVector4& from, const hkVector4& to);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		void set(const hkRotation& r);
		void setAndNormalize(const hkRotation& r);
		void removeAxisComponent (const hkVector4& axis);
		void decomposeRestAxis (const hkVector4& axis, hkQuaternion& restOut, hkReal& angleOut) const;
		void setSlerp(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);
		inline void setReal(hkReal r);
		inline hkReal getReal() const;
		inline void setImag(const hkVector4& );
		__forceinline const hkVector4& getImag() const;
		inline hkReal getAngle()const;
		inline void getAxis(hkVector4 &axis) const;
		inline hkBool hasValidAxis() const;
		inline const hkReal& operator()(int i) const;
		hkBool isOk() const;
	public:
		hkVector4 m_vec;
	protected:
		void setFlippedRotation(const hkVector4& from);
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
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkRotation& r, const hkVector4& t);
		__forceinline hkTransform(const hkTransform& r);
		__forceinline hkTransform(const hkQuaternion& q, const hkVector4& t);
		__forceinline hkReal& operator() (int row, int column);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline void set(const hkQuaternion& q, const hkVector4& t);
		__forceinline void setIdentity();
		__forceinline static const hkTransform& __cdecl getIdentity();
		hkBool isApproximatelyEqual( const hkTransform& t, hkReal epsilon=1e-3f ) const;
		__forceinline hkVector4& getTranslation();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setRotation(const hkQuaternion& quatRotation);
		void setInverse( const hkTransform &t );
		void setMul( const hkTransform &t1, const hkTransform &t2 );
		void setMul( const hkQsTransform &t1, const hkTransform &t2 );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
		void setMulEq( const hkTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		void set4x4ColumnMajor(const hkReal* p);
		__forceinline void setRows4( const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3);
		void setMulMulInverse( const hkTransform &a, const hkTransform &b );
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkSweptTransform() { }
	public:
		__forceinline void _approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		void approxTransformAt( hkTime time, hkTransform& transformOut ) const;
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkReal getInterpolationValueHiAccuracy( hkTime t, hkReal deltaTimeAddon ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
		void initSweptTransform( const hkVector4& position, const hkQuaternion& rotation );
	public:
		hkVector4 m_centerOfMass0;
		hkVector4 m_centerOfMass1;
		hkQuaternion m_rotation0;
		hkQuaternion m_rotation1;
		hkVector4 m_centerOfMassLocal;
};
inline hkReal& hkVector4::operator() (int i)
{
	; ;
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}
void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}
class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkMotionState();
		void initMotionState( const hkVector4& position, const hkQuaternion& rotation );
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		inline const hkSweptTransform& getSweptTransform() const;
		inline hkSweptTransform& getSweptTransform();
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
hkTransform& hkMotionState::getTransform()
{
	return m_transform;
}
const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}
class hkAabb;
class hkSphere;
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const;
		inline hkVector4& getPosition();
		inline void setPosition(const hkVector4& position);
		inline const hkVector4& getNormal() const;
		inline const hkVector4& getSeparatingNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& normal, hkReal dist );
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setNormal( const hkVector4& normal );
		inline hkReal getDistance() const;
		inline hkSimdReal getDistanceSimdReal() const;
		inline void setDistance( hkReal d );
		inline void set( const hkVector4& position, const hkVector4& normal, float dist );
		inline void setFlipped( const hkContactPoint& point );
		inline void flip();
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getPosition() const
{
	return m_position;
}
inline void hkContactPoint::setPosition( const hkVector4& position )
{
	m_position = position;
}
inline const hkVector4& hkContactPoint::getSeparatingNormal() const
{
	return m_separatingNormal;
}
inline void hkContactPoint::setSeparatingNormal( const hkVector4& normal, hkReal dist )
{
	m_separatingNormal = normal;
	m_separatingNormal(3) = dist;
}
inline void hkContactPoint::setSeparatingNormal( const hkVector4& separatingNormal )
{
	m_separatingNormal = separatingNormal;
}
inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3);
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
class hkpCdVertex;
enum hkpShapeType
{
	HK_SHAPE_INVALID = 0,
	HK_SHAPE_CONVEX,
	HK_FIRST_SHAPE_TYPE = HK_SHAPE_CONVEX,
	HK_SHAPE_SPHERE,
	HK_SHAPE_CYLINDER,
	HK_SHAPE_TRIANGLE,
	HK_SHAPE_BOX,
	HK_SHAPE_CAPSULE,
	HK_SHAPE_CONVEX_VERTICES,
	HK_SHAPE_COLLECTION,
	HK_SHAPE_BV_TREE,
	HK_SHAPE_LIST,
	HK_SHAPE_MOPP,
	HK_SHAPE_CONVEX_TRANSLATE,
	HK_SHAPE_CONVEX_TRANSFORM,
	HK_SHAPE_SAMPLED_HEIGHT_FIELD,
	HK_SHAPE_EXTENDED_MESH,
	HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_MAX_ID_SPU = HK_SHAPE_USER_SPU_COLLECTION_0,
	HK_SHAPE_PACKED_CONVEX_VERTICES,
	HK_SHAPE_MOPP_EMBEDDED,
	HK_SHAPE_CONVEX_PIECE,
	HK_SHAPE_MULTI_SPHERE,
	HK_SHAPE_CONVEX_LIST,
	HK_SHAPE_TRIANGLE_COLLECTION,
	HK_SHAPE_MULTI_RAY,
	HK_SHAPE_HEIGHT_FIELD,
	HK_SHAPE_SPHERE_REP,
	HK_SHAPE_BV,
	HK_SHAPE_PLANE,
	HK_SHAPE_TRANSFORM,
	HK_SHAPE_PHANTOM_CALLBACK,
	HK_SHAPE_USER0,
	HK_SHAPE_USER1,
	HK_SHAPE_USER2,
	HK_SHAPE_MAX_ID,
	HK_SHAPE_ALL = -1
};
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpShape( hkpShapeType type );
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			static void __cdecl resetShapeFunctions();
			typedef void (__cdecl *GetSupportingVertexFunc)        (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int  (__cdecl *GetNumCollisionSpheresFunc)		(const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc)					(const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc>			m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc>				m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc>						m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc>		m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc>			m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc>						m_getAabbFunc;
				hkPadSpu<CastRayFunc>						m_castRay;
				hkPadSpu<GetChildShapeFunc>					m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc		m_convertVertexIdsToVertices;
				WeldContactPointFunc				m_weldContactPointFunc;
				GetCentreFunc						m_getCentreFunc;
				GetNumCollisionSpheresFunc			m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc				m_getCollisionSpheresFunc;
				GetAabbFunc							m_getAabbFunc;
				CastRayFunc							m_castRay;
				GetChildShapeFunc					m_getChildShapeFunc;
				GetCollisionFilterInfoFunc			m_getCollisionFilterInfoFunc;
			};
	public:
	public:
		hkUlong m_userData;
	public:
		hkEnum<hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
__declspec(align(16)) class hkAlignedShape: public hkpShape{
	hkAlignedShape();
};
hkpShapeType hkpShape::getType() const
{
	return static_cast<const hkAlignedShape*>(this)->m_type;
}
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
const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
hkpCdBody::hkpCdBody( const hkpCdBody* parent, const hkMotionState* ms )
{
	m_parent = parent;
	m_motion = ms;
}
void hkpCdBody::setShape( const hkpShape* shape, hkpShapeKey key )
{
	m_shape = shape;
	m_shapeKey = key;
}
struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct hkpCollisionInput;
struct hkpAgentEntry;
typedef void hkpAgentData;
struct hkpAgent3Input;
struct hkpAgent3ProcessInput;
namespace hkAgent3
{
typedef int AgentType;
typedef hkpAgentData* (__cdecl* CreateFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData );
typedef void  (__cdecl* DestroyFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher );
typedef hkpAgentData* (__cdecl* ProcessFunc)( const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4* separatingNormalOut, hkpProcessCollisionOutput& result);
enum Symmetric
	{
		IS_SYMMETRIC,
		IS_NOT_SYMMETRIC,
		IS_NOT_SYMMETRIC_AND_FLIPPED
	};
typedef void  (__cdecl* SepNormalFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4& separatingNormalOut );
typedef hkpAgentData* (__cdecl* CleanupFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner );
typedef void (__cdecl* RemovePointFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId idToRemove );
typedef void (__cdecl* CommitPotentialFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId newId );
typedef void (__cdecl* CreateZombieFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkContactPointId idTobecomeZombie );
typedef void (__cdecl* UpdateFilterFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner );
typedef void (__cdecl* CalcStatisticsFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, const hkpCollisionInput& input, hkStatisticsCollector* collector );
typedef void (__cdecl* InvalidateTimFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpCollisionInput& input );
typedef void (__cdecl* WarpTimeFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkTime oldTime, hkTime newTime, hkpCollisionInput& input );
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
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32>		m_useContinuousPhysics;
	hkReal m_minSeparation;
	hkReal m_minExtraSeparation;
	hkReal m_minSafeDeltaTime;
	hkReal m_minAbsoluteSafeDeltaTime;
	hkReal m_toiSeparation;
	hkReal m_toiExtraSeparation;
	hkReal m_toiAccuracy;
	hkReal m_maxContraintViolation;
	hkReal m_minToiDeltaTime;
	hkUint16	m_constraintPriority;
	hkBool m_enableToiWeldRejection;
	hkReal calcMinSeparation( hkReal currentDistance ) const
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
class hkpCollisionAgent;
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct hkpLinearCastCollisionInput;
class hkpCollisionDispatcher : public hkReferencedObject
{
	public:
		enum {
			HK_MAX_RESPONSE_TYPE = 8,
			HK_MAX_SHAPE_TYPE    = 32,
			HK_MAX_AGENT2_TYPES  = 64,
			HK_MAX_AGENT3_TYPES = 16,
			HK_MAX_COLLISION_QUALITIES = 8
		};
	public:
		typedef hkpCollisionAgent* (__cdecl *CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& env, hkpContactMgr* mgr);
		typedef void (__cdecl *GetPenetrationsFunc)     (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		typedef void (__cdecl *GetClosestPointsFunc)   (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& output );
		typedef void (__cdecl *LinearCastFunc)         (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector );
		typedef CreateFunc CollisionAgentCreationFunction;
		typedef hkChar CollisionQualityIndex;
		struct AgentFuncs
		{
			CreateFunc           m_createFunc;
			GetPenetrationsFunc  m_getPenetrationsFunc;
			GetClosestPointsFunc m_getClosestPointFunc;
			LinearCastFunc       m_linearCastFunc;
			hkBool				 m_isFlipped;
			hkBool				 m_isPredictive;
			AgentFuncs() : m_isFlipped(false), m_isPredictive(false) {}
		};
		struct Agent3Funcs
		{
			Agent3Funcs() : m_isPredictive(false), m_ignoreSymmetricVersion(false), m_reusePreviousEntry(false)
			{
				m_updateFilterFunc	= 0;
				m_calcStatisticsFunc= 0;
				m_invalidateTimFunc = 0;
				m_warpTimeFunc		= 0;
				m_sepNormalFunc		= 0;
			}
			__declspec(align(16)) hkAgent3::CreateFunc m_createFunc;
			hkAgent3::DestroyFunc     m_destroyFunc;
			hkAgent3::CleanupFunc     m_cleanupFunc;
			hkAgent3::RemovePointFunc m_removePointFunc;
			hkAgent3::CommitPotentialFunc m_commitPotentialFunc;
			hkAgent3::CreateZombieFunc  m_createZombieFunc;
			hkAgent3::UpdateFilterFunc  m_updateFilterFunc;
			hkAgent3::CalcStatisticsFunc  m_calcStatisticsFunc;
			hkAgent3::InvalidateTimFunc m_invalidateTimFunc;
			hkAgent3::WarpTimeFunc      m_warpTimeFunc;
			hkAgent3::SepNormalFunc     m_sepNormalFunc;
			hkAgent3::ProcessFunc       m_processFunc;
			hkBool						m_isPredictive;
			hkBool						m_ignoreSymmetricVersion;
			hkBool						m_reusePreviousEntry;
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
		hkpCollisionDispatcher( CreateFunc defaultCreationFunction, hkpContactMgrFactory* defaultContactMgrFactory );
		~hkpCollisionDispatcher();
		void registerAlternateShapeType( hkpShapeType primaryType, hkpShapeType alternateType );
		inline hkBool32 hasAlternateType( hkpShapeType type, hkpShapeType alternateType );
		void registerCollisionAgent( AgentFuncs& f, hkpShapeType typeA, hkpShapeType typeB );
		void registerCollisionAgent2( AgentFuncs& f, hkpShapeType typeA, hkpShapeType typeB );
		void setEnableChecks( hkBool checkEnabled);
		void debugPrintTable();
		void disableDebugging();
		__forceinline hkpCollisionAgent* getNewCollisionAgent(	const hkpCdBody& a, const hkpCdBody& b, const hkpCollisionInput& env, hkpContactMgr* mgr) const;
		__forceinline CreateFunc getCollisionAgentCreationFunction( hkpShapeType typeA, hkpShapeType typeB, IsAgentPredictive predictive ) const;
		__forceinline GetPenetrationsFunc getGetPenetrationsFunc( hkpShapeType typeA, hkpShapeType typeB ) const;
		__forceinline GetClosestPointsFunc getGetClosestPointsFunc( hkpShapeType typeA, hkpShapeType typeB ) const;
		__forceinline LinearCastFunc getLinearCastFunc( hkpShapeType typeA, hkpShapeType typeB ) const;
		__forceinline hkBool getIsFlipped( hkpShapeType typeA, hkpShapeType typeB ) const;
		int registerAgent3( Agent3Funcs& f, hkpShapeType typeA, hkpShapeType typeB );
		__forceinline hkAgent3::AgentType getAgent3Type( hkpShapeType typeA, hkpShapeType typeB, hkBool32 predicitve ) const;
		__forceinline hkAgent3::CreateFunc           getAgent3CreateFunc  ( hkAgent3::AgentType type );
		__forceinline hkAgent3::DestroyFunc          getAgent3DestroyFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::CleanupFunc          getAgent3CleanupFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::RemovePointFunc      getAgent3RemovePointFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::CommitPotentialFunc  getAgent3CommitPotentialFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::CreateZombieFunc     getAgent3CreateZombieFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::UpdateFilterFunc     getAgent3UpdateFilterFunc ( hkAgent3::AgentType type ) const;
		__forceinline hkAgent3::CalcStatisticsFunc   getAgent3CalcStatisticsFunc ( hkAgent3::AgentType type ) const;
		__forceinline hkAgent3::InvalidateTimFunc    getAgent3InvalidateTimFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::WarpTimeFunc	       getAgent3WarpTimeFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::ProcessFunc          getAgent3ProcessFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::SepNormalFunc        getAgent3SepNormalFunc( hkAgent3::AgentType type );
		__forceinline hkAgent3::Symmetric            getAgent3Symmetric( hkAgent3::AgentType type );
		void registerContactMgrFactory( hkpContactMgrFactory*, int responseA, int responseB );
		__forceinline hkpContactMgrFactory* getContactMgrFactory(int responseA, int responseB) const;
		void registerContactMgrFactoryWithAll( hkpContactMgrFactory*, int responseA );
		__forceinline CollisionQualityIndex getCollisionQualityIndex( hkpCollidableQualityType a, hkpCollidableQualityType b);
		__forceinline hkpCollisionQualityInfo* getCollisionQualityInfo( CollisionQualityIndex index );
		void initCollisionQualityInfo( InitCollisionQualityInfo& input );
		void calcStatistics( hkStatisticsCollector* collector ) const;
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
			AgentFuncs  m_createFunc;
		};
		struct Agent3Entry
		{
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			Agent3Funcs  m_funcs;
		};
		struct Agent3FuncsIntern: public Agent3Funcs
		{
			hkAgent3::Symmetric       m_symmetric;
		};
		struct DebugEntry
		{
			char m_typeA;
			char m_typeB;
			char m_priority;
		};
		typedef DebugEntry	DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
	protected:
		void updateHasAlternateType( hkpShapeType primaryType, hkpShapeType alternateType, int depth );
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
		CreateFunc	m_defaultCollisionAgent;
		hkpContactMgrFactory*	m_contactMgrFactory[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
		__declspec(align(16)) hkUint32 m_hasAlternateType[ HK_MAX_SHAPE_TYPE ];
		int						m_numAgent2Types;
		__declspec(align(16)) hkUchar m_agent2Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		hkUchar				    m_agent2TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		AgentFuncs				m_agent2Func     [ HK_MAX_AGENT2_TYPES ];
		int						m_numAgent3Types;
		__declspec(align(16)) hkUchar m_agent3Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		__declspec(align(16)) hkUchar m_agent3TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		Agent3FuncsIntern       m_agent3Func     [ HK_MAX_AGENT3_TYPES ];
		__declspec(align(16)) hkChar m_collisionQualityTable[ HK_COLLIDABLE_QUALITY_MAX][HK_COLLIDABLE_QUALITY_MAX];
		__declspec(align(16)) hkpCollisionQualityInfo m_collisionQualityInfo[ HK_MAX_COLLISION_QUALITIES ];
		hkBool m_collisionAgentRegistered;
		hkBool m_agent3Registered;
		hkBool m_midphaseAgent3Registered;
		hkBool m_checkEnabled;
		hkArray<ShapeInheritance> m_shapeInheritance;
		DebugTable	*m_debugAgent2Table;
		DebugTable	*m_debugAgent2TablePred;
		DebugTable	*m_debugAgent3Table;
		DebugTable	*m_debugAgent3TablePred;
	public:
		hkReal m_expectedMaxLinearVelocity;
		hkReal m_expectedMinPsiDeltaTime;
};
hkpCollisionDispatcher::GetClosestPointsFunc hkpCollisionDispatcher::getGetClosestPointsFunc( hkpShapeType typeA, hkpShapeType typeB ) const
{
	;
	;
	int idx = m_agent2Types[typeA][typeB];
	return m_agent2Func[idx].m_getClosestPointFunc;
}
struct hkpCdPoint
{
	hkpCdPoint( const hkpCdBody& a, const hkpCdBody& b ) : m_cdBodyA(a), m_cdBodyB(b) {}
	hkContactPoint m_contact;
	const hkpCdBody& m_cdBodyA;
	const hkpCdBody& m_cdBodyB;
};
class hkpCdPointCollector
{
	public:
		inline hkpCdPointCollector();
		inline virtual ~hkpCdPointCollector();
		virtual void addCdPoint( const hkpCdPoint& point ) = 0;
		inline void reset();
		inline hkReal getEarlyOutDistance( ) const;
	protected:
		hkReal m_earlyOutDistance;
};
void hkpCdPointCollector::reset()
{
	m_earlyOutDistance = 3.40282e+38f;
}
hkpCdPointCollector::hkpCdPointCollector()
{
	reset();
}
hkpCdPointCollector::~hkpCdPointCollector()
{
}
hkReal hkpCdPointCollector::getEarlyOutDistance( ) const
{
	return m_earlyOutDistance;
}
class hkpCollisionAgent : public hkReferencedObject
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		virtual void removePoint( hkContactPointId idToRemove );
		virtual void commitPotential( hkContactPointId newId );
		virtual void createZombie( hkContactPointId idTobecomeZombie );
	protected:
		inline virtual ~hkpCollisionAgent();
		inline hkpCollisionAgent( hkpContactMgr* contactMgr );
	protected:
		hkpContactMgr* m_contactMgr;
	public:
		inline hkpContactMgr* getContactMgr();
};
struct hkpLinearCastCollisionInput : public hkpCollisionInput
{
	inline hkpLinearCastCollisionInput();
	inline void set( const hkpProcessCollisionInput& input );
	inline void setPathAndTolerance( const hkVector4& path, hkReal tolerance );
	hkVector4	m_path;
	hkReal m_maxExtraPenetration;
	hkReal m_cachedPathLength;
	hkpCollisionAgentConfig* m_config;
};
class hkpIterativeLinearCastAgent : public hkpCollisionAgent
{
	public:
		hkpIterativeLinearCastAgent(hkpContactMgr* contactMgr): hkpCollisionAgent(contactMgr){}
		static void __cdecl staticLinearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		__forceinline ~hkpIterativeLinearCastAgent(){}
};
struct hkpCollisionAgentConfig
{
	__declspec(align(16)) hkReal m_iterativeLinearCastEarlyOutDistance;
	int m_iterativeLinearCastMaxIterations;
	inline hkpCollisionAgentConfig();
};
class hkpSimpleClosestContactCollector : public hkpCdPointCollector
{
	public:
		inline hkpSimpleClosestContactCollector();
		inline void reset();
		inline virtual ~hkpSimpleClosestContactCollector();
		inline hkBool hasHit( ) const;
		inline const hkContactPoint& getHitContact() const;
	protected:
		virtual void addCdPoint( const hkpCdPoint& pointInfo ) ;
	protected:
		hkBool m_hasHit;
		hkContactPoint	m_hitPoint;
};
void hkpSimpleClosestContactCollector::reset()
{
	m_hasHit = false;
	m_hitPoint.setDistance( 3.40282e+38f );
	hkpCdPointCollector::reset();
}
hkpSimpleClosestContactCollector::hkpSimpleClosestContactCollector()
{
	reset();
}
hkpSimpleClosestContactCollector::~hkpSimpleClosestContactCollector()
{
}
hkBool hkpSimpleClosestContactCollector::hasHit( ) const
{
	return m_hasHit;
}
const hkContactPoint& hkpSimpleClosestContactCollector::getHitContact() const
{
	return m_hitPoint;
}

}  // namespace f3m_00a3ab70

// The packet's symbol is the unit's stand-in FUN_00daf8e0 with pointer parameters: they are read here as the
// SDK's references (body A, body B, the linear cast input, the collector) and the optional start collector.
// pdb: hkpIterativeLinearCastAgent::staticLinearCast | hkpIterativeLinearCastAgent.obj | fnv360_0822_retail, call_seq, medium
// pdb params: bodyA, bodyB, input, collector, startCollector
void FUN_00daf8e0(const IterativeSweep_hkpCdBody* bodyA, const IterativeSweep_hkpCdBody* bodyB, const IterativeSweep_hkpLinearCastCollisionInput* input, IterativeSweep_hkpCdPointCollector* castCollector, IterativeSweep_hkpCdPointCollector* startCollector)
{
	using namespace f3m_00a3ab70;
	hkpSimpleClosestContactCollector startPointCollector;
	hkpCollisionInput in2 = (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input ));
	in2.m_tolerance = in2.m_tolerance + (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_cachedPathLength;
	hkpShapeType typeA = (*reinterpret_cast<const hkpCdBody*>( bodyA )).getShape()->getType();
	hkpShapeType typeB = (*reinterpret_cast<const hkpCdBody*>( bodyB )).getShape()->getType();
	hkpCollisionDispatcher::GetClosestPointsFunc getClosestPoints = (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_dispatcher->getGetClosestPointsFunc( typeA, typeB );
	getClosestPoints( (*reinterpret_cast<const hkpCdBody*>( bodyA )), (*reinterpret_cast<const hkpCdBody*>( bodyB )), in2, startPointCollector );
	if ( !startPointCollector.hasHit() )
	{
		return;
	}
	hkpCdPoint event( (*reinterpret_cast<const hkpCdBody*>( bodyA )), (*reinterpret_cast<const hkpCdBody*>( bodyB )) );
	const hkContactPoint& startPoint = startPointCollector.getHitContact();
	{
		event.m_contact.setSeparatingNormal( startPoint.getSeparatingNormal() );
		event.m_contact.setPosition( startPoint.getPosition() );
		const hkReal dist = startPoint.getDistance();
		if ( dist < (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_tolerance )
		{
			if ( reinterpret_cast<hkpCdPointCollector*>( startCollector ) )
			{
				reinterpret_cast<hkpCdPointCollector*>( startCollector )->addCdPoint( event );
			}
		}
	}
	const hkVector4& path = (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_path;
	hkReal currentFraction = 0.0f;
	{
		const hkReal startDistance = startPoint.getDistance();
		const hkReal pathProjected = startPoint.getSeparatingNormal().dot3( path );
		const hkReal endDistance = startDistance + pathProjected;
		if ( endDistance > 0.0f )
		{
			return;
		}
		;
		if ( pathProjected + (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_maxExtraPenetration >= 0.0f )
		{
			return;
		}
		if ( startDistance <= (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_config->m_iterativeLinearCastEarlyOutDistance )
		{
			if ( startDistance > 0.0f )
			{
				if ( startDistance > (*reinterpret_cast<hkpCdPointCollector*>( castCollector )).getEarlyOutDistance() * (startDistance - endDistance) )
				{
					return;
				}
			}
			event.m_contact.setDistance( 0.0f );
			(*reinterpret_cast<hkpCdPointCollector*>( castCollector )).addCdPoint( event );
			return;
		}
		currentFraction = startDistance / ( startDistance - endDistance );
	}
	{
		hkpSimpleClosestContactCollector checkPointCollector;
		hkMotionState ms = *(*reinterpret_cast<const hkpCdBody*>( bodyA )).getMotionState();
		hkpCdBody bodyACopy( &(*reinterpret_cast<const hkpCdBody*>( bodyA )), &ms );
		bodyACopy.setShape( (*reinterpret_cast<const hkpCdBody*>( bodyA )).getShape(), 0xffffffff );
		for ( int i = (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_config->m_iterativeLinearCastMaxIterations - 1; i >= 0; i-- )
		{
			checkPointCollector.reset();
			{
				const hkVector4& oldPosition = (*reinterpret_cast<const hkpCdBody*>( bodyA )).getMotionState()->getTransform().getTranslation();
				hkVector4 newPosition; newPosition.setAddMul4( oldPosition, path, currentFraction );
				ms.getTransform().setTranslation( newPosition );
			}
			getClosestPoints( bodyACopy, (*reinterpret_cast<const hkpCdBody*>( bodyB )), in2, checkPointCollector );
			if ( !checkPointCollector.hasHit() )
			{
				return;
			}
			{
				const hkContactPoint& checkPoint = checkPointCollector.getHitContact();
				const hkVector4& normal = checkPoint.getSeparatingNormal();
				event.m_contact.setPosition( checkPoint.getPosition() );
				event.m_contact.setSeparatingNormal( checkPoint.getSeparatingNormal(), currentFraction );
				hkReal pathProjected2 = normal.dot3( path );
				if ( pathProjected2 >= 0.0f )
				{
					return;
				}
				pathProjected2 = -pathProjected2;
				const hkReal startDistance2 = checkPoint.getDistance();
				const hkReal preDistance = event.m_contact.getDistance() * pathProjected2;
				;
				if ( startDistance2 + preDistance > pathProjected2 )
				{
					return;
				}
				currentFraction += startDistance2 / pathProjected2;
				if ( currentFraction > (*reinterpret_cast<hkpCdPointCollector*>( castCollector )).getEarlyOutDistance() )
				{
					return;
				}
				if ( startDistance2 <= (*reinterpret_cast<const hkpLinearCastCollisionInput*>( input )).m_config->m_iterativeLinearCastEarlyOutDistance )
				{
					break;
				}
			}
		}
	}
	(*reinterpret_cast<hkpCdPointCollector*>( castCollector )).addCdPoint( event );
}

