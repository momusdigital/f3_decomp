#include <new>
// src/f3staging/f3iso_00a6d290_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a6d290 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a6d290 (community match, verified in this file)
// 0x00a6d290: hkpRagdollDrawer::drawConstraint(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler,
// int tag) of Havok 5.5.0 (hkpUtilities, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Draws a ragdoll constraint for the visual debugger: the pivots, an arrow for each body's twist axis with its
// crossed axis, the twist cone, the plane of the planes limit and its two cones, as display geometries.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, then lines inside them while the bytes stayed equal); the
// declarations above the function are therefore the SDK's text with its names. The function body follows the
// SDK's unoptimized (hybrid) library object of this function statement by statement, and built with the SDK's
// headers it reproduces both that object and the release object. Only the function itself carries the packet's
// name; its callees keep the SDK's names.
namespace f3m_00a6d290 {

typedef signed short	hkInt16;
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
__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
	return hkUlong(pntr) - hkUlong(base);
}
__forceinline int __cdecl hkGetByteOffsetInt( const void* base, const void* pntr)
{
	return static_cast<int>( hkGetByteOffset( base, pntr ) );
}
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
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline hkArray<T>::hkArray()
	:	m_data(0),
		m_size(0),
		m_capacityAndFlags(DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal;
class hkVector4Comparison;
extern "C" {
double  __cdecl fabs(     double _X);
double  __cdecl sqrt(     double _X);
inline float fabsf(     float _X)
        {return ((float)fabs((double)_X)); }
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline hkVector4() { }
		__forceinline hkVector4(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline hkVector4(const hkQuadReal& q);
		__forceinline hkVector4( const hkVector4& v);
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
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
		;
	}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}
hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}
class hkDebugDisplayHandler;
class hkpPrimitiveDrawer
{
	public:
	protected:
		hkDebugDisplayHandler* m_displayHandler;
	public:
        hkpPrimitiveDrawer();
		void setDisplayHandler(hkDebugDisplayHandler* displayHandler);
		void displayOrientedPoint(const hkVector4& position,const hkRotation& rot,hkReal size, int color, int tag);
		void displayArrow (const hkVector4& startPos, const hkVector4& arrowDirection, const hkVector4& perpDirection, int color, hkReal scale, int tag);
		void displayPlane(const hkVector4& startPos, const hkVector4& planeNormal, const hkVector4& vectorOnPlane, int color, hkReal scale, int tag);
		void drawSemiCircle(const hkVector4& center, hkVector4& normal,
						    hkVector4& startPerp, hkReal thetaMin, hkReal thetaMax,
							hkReal radius,int numSegments, int color, int tag);
};
class hkpConstraintInstance;
class hkpConstraintDrawer
{
	public:
		hkpConstraintDrawer();
		void setLineLength(hkReal lineLength);
		void setArcRadius(hkReal arcRadius);
		void setNumSegments(int numSegments);
		void setPivotSize(hkReal size);
	protected:
		void drawPivots(int tag);
		void drawBodyFrames(int tag);
		void updateCommonParameters(hkpConstraintInstance* constraint,hkTransform& refLocalToWorld,hkTransform& attLocalToWorld);
		hkReal m_lineLength;
		hkReal m_arcRadius;
		hkReal m_pivotSize;
		hkReal m_arrowSize;
		hkReal m_coneSize;
		hkReal m_planeSize;
		int	   m_numSegments;
		hkVector4 m_bodyAWPos;
		hkVector4 m_bodyBWPos;
		hkVector4 m_bodyAWPivot;
		hkVector4 m_bodyBWPivot;
		hkRotation m_RA;
		hkRotation m_RB;
		hkpPrimitiveDrawer m_primitiveDrawer;
};
enum hkDisplayGeometryType
{
	HK_DISPLAY_RECTANGLE = 0,
	HK_DISPLAY_SPHERE,
	HK_DISPLAY_BOX,
	HK_DISPLAY_AABB,
	HK_DISPLAY_CONE,
	HK_DISPLAY_SEMICIRCLE,
	HK_DISPLAY_CONVEX,
	HK_DISPLAY_PLANE,
	HK_DISPLAY_CAPSULE,
	HK_DISPLAY_CYLINDER
};
struct hkGeometry;
class hkDisplayGeometry : public hkReferencedObject
{
	public:
		inline hkDisplayGeometry(hkDisplayGeometryType type);
		virtual ~hkDisplayGeometry();
		inline hkGeometry* getGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines) = 0;
		virtual void buildGeometry() = 0;
		inline const hkTransform& getTransform() const;
		inline hkTransform& getTransform();
		inline hkDisplayGeometryType getType() const;
		hkGeometry* m_geometry;
	protected:
		hkTransform m_transform;
		hkDisplayGeometryType m_type;
};
class hkDisplayCone : public hkDisplayGeometry
{
	public:
		hkDisplayCone(const hkReal coneAngle,
					  const hkReal coneHeight,
					  const int numSegments,
					  const hkVector4& coneAxis,
					  const hkVector4& startPos);
		hkDisplayCone();
		void setParameters(const hkReal coneAngle,
						   const hkReal coneHeight,
						   const int numSegments,
						   const hkVector4& coneAxis,
						   const hkVector4& startPos);
		virtual void buildGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines);
		hkVector4 getPosition();
		hkVector4 getAxis();
		hkReal getHeight();
		hkReal getAngle();
		int getNumSegments();
	protected:
		hkVector4 m_startPos;
		hkVector4 m_coneAxis;
		int m_numSegments;
		hkReal m_coneAngle;
		hkReal m_coneHeight;
		void generateConeVertices(hkArray<hkVector4>& conePoints);
};
class hkDisplayPlane : public hkDisplayGeometry
{
	public:
		hkDisplayPlane();
		hkDisplayPlane(const hkVector4& normal, const hkVector4& perpToNormal,
			const hkVector4& center, const hkVector4& extents);
		virtual void buildGeometry();
		virtual void getWireframeGeometry(hkArray<hkVector4>& lines);
		void setParameters(const hkVector4& normal, const hkVector4& perpToNormal,
						   const hkVector4& center,  const hkVector4& extents);
		hkVector4& getNormal();
		hkVector4& getCenter();
		hkVector4& getPerpToNormal();
		hkVector4& getExtents();
	protected:
		hkVector4 m_normal;
		hkVector4 m_center;
		hkVector4 m_perpToNormal;
		hkVector4 m_extent;
		void createPlanePoints(hkVector4* points);
};
class hkpRagdollDrawer : public hkpConstraintDrawer
{
	public:
		void FUN_00a6d290(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag);
	protected:
		hkDisplayCone m_twistCone;
		hkDisplayCone m_planeCone1;
		hkDisplayCone m_planeCone2;
		hkDisplayPlane m_plane;
};
class hkpSolverResults
{
	public:
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
struct hkpConstraintInfo
{
	int m_maxSizeOfSchema;
	int m_sizeOfSchemas;
	int m_numSolverResults;
	int m_numSolverElemTemps;
	inline void clear( ) { m_maxSizeOfSchema = 0; m_sizeOfSchemas = 0; m_numSolverResults = 0; m_numSolverElemTemps = 0; }
	inline void addHeader( ) { m_sizeOfSchemas += 16; }
	inline void add( int schemaSize, int numSolverResults, int numSolverTempElems ) { m_sizeOfSchemas += schemaSize; m_numSolverResults += numSolverResults; m_numSolverElemTemps += numSolverTempElems; }
	inline void add( const hkpConstraintInfo& other);
	inline void sub( const hkpConstraintInfo& other);
	inline void merge( const hkpConstraintInfo& other);
};
class hkpConstraintQueryIn;
class hkpConstraintQueryOut;
typedef void hkpConstraintRuntime;
class hkpConstraintData : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpConstraintData(hkFinishLoadedObjectFlag f) {}
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
		inline hkpConstraintData();
		inline virtual ~hkpConstraintData();
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		virtual hkBool isValid() const = 0;
		virtual int getType() const = 0;
		struct RuntimeInfo
		{
			int m_sizeOfExternalRuntime;
			int m_numSolverResults;
		};
		virtual void getRuntimeInfo( hkBool wantRuntime, RuntimeInfo& infoOut ) const = 0;
		virtual hkpSolverResults* getSolverResults( hkpConstraintRuntime* runtime );
		virtual void addInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
		inline void removeInstance( hkpConstraintInstance* constraint, hkpConstraintRuntime* runtime, int sizeOfRuntime ) const;
	protected:
		friend class hkpConstraintSolverSetup;
	public:
		virtual void buildJacobian( const hkpConstraintQueryIn &in, hkpConstraintQueryOut &out ) { ; }
		virtual hkBool isBuildJacobianCallbackRequired() const { return false; }
		virtual void buildJacobianCallback( const hkpConstraintQueryIn &in ) { ; }
		struct ConstraintInfo : public hkpConstraintInfo
		{
			struct hkpConstraintAtom* m_atoms;
			hkUint32		  m_sizeOfAllAtoms;
		};
		virtual void getConstraintInfo( ConstraintInfo& infoOut ) const = 0;
		static void __cdecl getConstraintInfoUtil( const hkpConstraintAtom* atoms, int sizeOfAllAtoms, ConstraintInfo& infoOut );
	public:
		hkUlong m_userData;
};
class hkpEntity;
class hkpRigidBody;
class hkpConstraintOwner;
class hkpSimulationIsland;
class hkpWorld;
class hkpConstraintInstance : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
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
		hkpConstraintInstance(hkpEntity* entityA, hkpEntity* entityB, hkpConstraintData* data, ConstraintPriority priority = PRIORITY_PSI);
		~hkpConstraintInstance();
		hkpConstraintInstance* clone(hkpEntity* newEntityA, hkpEntity* newEntityB, CloningMode mode = CLONE_INSTANCES_ONLY) const;
	protected:
		hkpConstraintInstance(ConstraintPriority priority);
	public:
		inline hkpEntity* getEntityA() const;
		inline hkpEntity* getEntity( int index ) const;
		inline hkpEntity* getEntityB() const;
		inline hkpRigidBody* getRigidBodyA() const;
		inline hkpRigidBody* getRigidBodyB() const;
		inline hkpEntity* getOtherEntity( const hkpEntity* entity );
		hkpSimulationIsland* getSimulationIsland();
		inline hkpConstraintData* getData() const;
		inline hkpConstraintRuntime* getRuntime() const;
		inline void setWantRuntime( hkBool b );
		inline hkBool getWantRuntime() const ;
		inline hkUlong getUserData() const;
		inline void setUserData( hkUlong data );
		inline ConstraintPriority getPriority() const;
		void setPriority( ConstraintPriority priority );
		inline const char* getName() const;
		inline void setName( const char* name );
	public:
		inline hkpConstraintOwner* getOwner() const;
		inline hkpEntity* getMasterEntity() const;
		inline hkpEntity* getSlaveEntity() const;
		virtual void entityAddedCallback(hkpEntity* entity);
		virtual void entityRemovedCallback(hkpEntity* entity);
		virtual void entityDeletedCallback( hkpEntity* entity );
		inline void setOwner( hkpConstraintOwner* island );
		inline struct hkConstraintInternal* getInternal();
		void pointNullsToFixedRigidBody();
		void setFixedRigidBodyPointersToZero( hkpWorld* world );
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
		hkpConstraintInstance(hkFinishLoadedObjectFlag f) { }
	private:
		friend class hkpWorldConstraintUtil;
		friend class hkpSimpleConstraintContactMgr;
		friend class hkpSaveContactPointsUtil;
		hkpConstraintInstance(){}
};
inline hkpConstraintData* hkpConstraintInstance::getData() const
{
	return m_data;
}
struct hkpConstraintAtom
{
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		enum AtomType
		{
			TYPE_INVALID = 0,
			TYPE_BRIDGE,
			TYPE_SET_LOCAL_TRANSFORMS,
			TYPE_SET_LOCAL_TRANSLATIONS,
			TYPE_SET_LOCAL_ROTATIONS,
			TYPE_BALL_SOCKET,
			TYPE_STIFF_SPRING,
			TYPE_LIN,
			TYPE_LIN_SOFT,
			TYPE_LIN_LIMIT,
			TYPE_LIN_FRICTION,
			TYPE_LIN_MOTOR,
			TYPE_2D_ANG,
			TYPE_ANG,
			TYPE_ANG_LIMIT,
			TYPE_TWIST_LIMIT,
			TYPE_CONE_LIMIT,
			TYPE_ANG_FRICTION,
			TYPE_ANG_MOTOR,
			TYPE_RAGDOLL_MOTOR,
			TYPE_PULLEY,
			TYPE_OVERWRITE_PIVOT,
			TYPE_CONTACT,
			TYPE_MODIFIER_SOFT_CONTACT,
			TYPE_MODIFIER_MASS_CHANGER,
			TYPE_MODIFIER_VISCOUS_SURFACE,
			TYPE_MODIFIER_MOVING_SURFACE,
			TYPE_MODIFIER_IGNORE_CONSTRAINT,
			TYPE_MAX
		};
		enum CallbackRequest
		{
			CALLBACK_REQUEST_NONE = 0,
			CALLBACK_REQUEST_NEW_CONTACT_POINT = 1,
			CALLBACK_REQUEST_SETUP_PPU_ONLY = 2,
			CALLBACK_REQUEST_SETUP_CALLBACK = 4
		};
	public:
		__forceinline enum AtomType getType() const { return m_type; }
		__forceinline int isModifierType() const { return m_type >= TYPE_MODIFIER_SOFT_CONTACT; }
	protected:
		hkpConstraintAtom(enum AtomType type) : m_type(type) {}
	private:
		hkpConstraintAtom();
	public:
		hkEnum<AtomType,hkUint16> m_type;
		hkpConstraintAtom(hkFinishLoadedObjectFlag f) {}
};
struct hkpBallSocketConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
public:
	hkpBallSocketConstraintAtom() : hkpConstraintAtom(TYPE_BALL_SOCKET) {}
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 3; }
	__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const { infoOut.add( 3 * 48, 3, 3 ); }
	hkpBallSocketConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpSetLocalTransformsConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpSetLocalTransformsConstraintAtom() : hkpConstraintAtom(TYPE_SET_LOCAL_TRANSFORMS) {}
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 0; }
	hkTransform m_transformA;
	hkTransform m_transformB;
	hkpSetLocalTransformsConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpTwistLimitConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpTwistLimitConstraintAtom() : hkpConstraintAtom(TYPE_TWIST_LIMIT), m_isEnabled(true) {}
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 1; }
	__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const { infoOut.add( 48, 1, 1 ); }
	hkUint8 m_isEnabled;
	hkUint8 m_twistAxis;
	hkUint8 m_refAxis;
	hkReal m_minAngle;
	hkReal m_maxAngle;
	hkReal m_angularLimitsTauFactor;
	hkpTwistLimitConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpConeLimitConstraintAtom() : hkpConstraintAtom(TYPE_CONE_LIMIT), m_isEnabled(true), m_memOffsetToAngleOffset(0) {}
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 1; }
	__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const { infoOut.add( 48, 1, 1 ); }
	hkUint8 m_isEnabled;
	hkUint8 m_twistAxisInA;
	hkUint8 m_refAxisInB;
	enum MeasurementMode
	{
		ZERO_WHEN_VECTORS_ALIGNED = 0,
		ZERO_WHEN_VECTORS_PERPENDICULAR = 1
	};
	hkEnum<MeasurementMode, hkUint8> m_angleMeasurementMode;
	hkUint8 m_memOffsetToAngleOffset;
	hkReal m_minAngle;
	hkReal m_maxAngle;
	hkReal m_angularLimitsTauFactor;
	hkpConeLimitConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpAngFrictionConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpAngFrictionConstraintAtom() : hkpConstraintAtom(TYPE_ANG_FRICTION), m_isEnabled(true), m_numFrictionAxes(1) {}
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return m_numFrictionAxes; }
	hkUint8 m_isEnabled;
	hkUint8 m_firstFrictionAxis;
	hkUint8 m_numFrictionAxes;
	hkReal m_maxFrictionTorque;
	hkpAngFrictionConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
struct hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkpRagdollMotorConstraintAtom() : hkpConstraintAtom(TYPE_RAGDOLL_MOTOR) { m_isEnabled = true; m_initializedOffset = 0; m_previousTargetAnglesOffset = 0; }
	__forceinline hkpConstraintAtom* next() const { return const_cast<hkpConstraintAtom*>( static_cast<const hkpConstraintAtom*>(this+1) ); }
	__forceinline int numSolverResults() const    { return 3; }
	__forceinline void addToConstraintInfo(hkpConstraintInfo& infoOut) const { infoOut.add( 3 * 64, 3, (1+2) * 3 ); }
	hkBool m_isEnabled;
	hkInt16 m_initializedOffset;
	hkInt16 m_previousTargetAnglesOffset;
	hkMatrix3 m_targetFrameAinB;
	class hkpConstraintMotor* m_motors[3];
	hkpRagdollMotorConstraintAtom(hkFinishLoadedObjectFlag f) : hkpConstraintAtom(f) {}
};
class hkpRagdollConstraintData : public hkpConstraintData
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpRagdollConstraintData();
		~hkpRagdollConstraintData();
		void setInWorldSpace(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
						const hkVector4& pivot, const hkVector4& twistAxisW,
						const hkVector4& planeAxisW);
		void setInBodySpace( const hkVector4& pivotA, const hkVector4& pivotB,
						const hkVector4& planeAxisA, const hkVector4& planeAxisB,
						const hkVector4& twistAxisA, const hkVector4& twistAxisB);
		void getConstraintFrameA( hkMatrix3& constraintFrameA ) const;
		void getConstraintFrameB( hkMatrix3& constraintFrameB ) const;
		inline void setTwistMinAngularLimit(hkReal rad);
		inline void setTwistMaxAngularLimit(hkReal rad);
		inline void setPlaneMaxAngularLimit(hkReal rad);
		inline void setPlaneMinAngularLimit(hkReal rad);
		inline void setConeAngularLimit(hkReal rad);
		void setConeLimitStabilization(hkBool enable);
		void setAsymmetricConeAngle(hkReal cone_min, hkReal cone_max );
		void setMaxFrictionTorque(hkReal tmag);
		inline void setAngularLimitsTauFactor( hkReal mag );
 		inline hkReal getAngularLimitsTauFactor() const;
		inline hkReal getTwistMinAngularLimit() const;
		inline hkReal getTwistMaxAngularLimit() const;
		inline hkReal getPlaneMaxAngularLimit() const;
		inline hkReal getPlaneMinAngularLimit() const;
		inline hkReal getConeAngularLimit() const;
		inline hkBool getConeLimitStabilization() const;
		inline hkReal getMaxFrictionTorque() const;
		void setTargetFromRelativeFrame( const hkRotation& bRa );
		void getTarget(hkMatrix3& targetFrameAinB );
		hkpConstraintMotor* getTwistMotor() const;
		void setTwistMotor( hkpConstraintMotor* motor );
		hkpConstraintMotor* getConeMotor() const;
		void setConeMotor( hkpConstraintMotor* motor );
		hkpConstraintMotor* getPlaneMotor() const;
		void setPlaneMotor( hkpConstraintMotor* motor );
		hkBool getMotorsActive() const;
		void setMotorsActive( hkpConstraintInstance* instance, hkBool toBeEnabled );
		hkBool isValid() const;
		virtual int getType() const;
		void setTarget( const hkMatrix3& relativeBasisAinB );
		enum
		{
			SOLVER_RESULT_MOTOR_0 = 0,
			SOLVER_RESULT_MOTOR_1 = 1,
			SOLVER_RESULT_MOTOR_2 = 2,
			SOLVER_RESULT_FRICTION_0 = 3,
			SOLVER_RESULT_FRICTION_1 = 4,
			SOLVER_RESULT_FRICTION_2 = 5,
			SOLVER_RESULT_TWIST = 6,
			SOLVER_RESULT_CONE  = 7,
			SOLVER_RESULT_PLANE = 8,
			SOLVER_RESULT_LIN_0 = 9,
			SOLVER_RESULT_LIN_1 = 10,
			SOLVER_RESULT_LIN_2 = 11,
			SOLVER_RESULT_MAX = 12
		};
		struct Runtime
		{
			__declspec(align(16)) class hkpSolverResults m_solverResults[12 ];
			hkUint8 m_initialized[3];
			hkReal m_previousTargetAngles[3];
			hkReal m_coneAngleOffset;
		};
		static inline Runtime* __cdecl getRuntime( hkpConstraintRuntime* runtime ) { return reinterpret_cast<Runtime*>(runtime); }
		virtual void getConstraintInfo( hkpConstraintData::ConstraintInfo& infoOut ) const;
		virtual void getRuntimeInfo( hkBool wantRuntime, hkpConstraintData::RuntimeInfo& infoOut ) const;
		struct Atoms
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			struct hkpSetLocalTransformsConstraintAtom	m_transforms;
			struct hkpRagdollMotorConstraintAtom         m_ragdollMotors;
			struct hkpAngFrictionConstraintAtom			m_angFriction;
			struct hkpTwistLimitConstraintAtom			m_twistLimit;
			struct hkpConeLimitConstraintAtom			m_coneLimit;
			struct hkpConeLimitConstraintAtom			m_planesLimit;
			struct hkpBallSocketConstraintAtom           m_ballSocket;
			enum Axis
			{
				AXIS_TWIST = 0,
				AXIS_PLANES = 1,
				AXIS_CROSS_PRODUCT = 2
			};
			Atoms(){}
			const hkpConstraintAtom* getAtoms() const { return &m_transforms; }
			int getSizeOfAllAtoms() const               { return hkGetByteOffsetInt(this, &m_ballSocket+1); }
		};
		__declspec(align(16)) struct Atoms m_atoms;
		enum MotorIndex
		{
			MOTOR_TWIST = 0,
			MOTOR_PLANE = 1,
			MOTOR_CONE  = 2
		};
		void setMotor(MotorIndex index, hkpConstraintMotor* newMotor);
	public:
		inline hkpRagdollConstraintData(hkFinishLoadedObjectFlag f);
};
inline hkReal hkpRagdollConstraintData::getConeAngularLimit() const
{
	return m_atoms.m_coneLimit.m_maxAngle;
}
class hkDebugDisplayHandler
{
	public:
		enum Command
		{
			HK_STEP = 0x00,
			HK_ADD_GEOMETRY,
			HK_UPDATE_GEOMETRY,
			HK_SET_COLOR_GEOMETRY,
			HK_REMOVE_GEOMETRY,
			HK_DISPLAY_GEOMETRY_WITH_TRANSFORM,
			HK_DISPLAY_GEOMETRY,
			HK_DISPLAY_POINT,
			HK_DISPLAY_LINE,
			HK_DISPLAY_TEXT,
			HK_SEND_STATISTICS_DUMP_DEPRICATED,
			HK_HOLD_IMMEDIATE,
			HK_ADD_CAMERA,
			HK_UPDATE_CAMERA,
			HK_REMOVE_CAMERA,
			HK_SEND_MEMSTATS_DUMP,
			HK_ADD_GEOMETRY_INSTANCE,
			HK_DISPLAY_TEXT_3D
		};
		virtual ~hkDebugDisplayHandler() {}
		virtual hkResult addGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform, hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult addGeometryInstance(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult setGeometryColor(int color, hkUlong id, int tag) = 0;
		virtual hkResult updateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
		virtual hkResult removeGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
		virtual hkResult updateCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane, hkReal farPlane, hkReal fov, const char* name) = 0;
		virtual hkResult displayPoint(const hkVector4& position, int colour, int tag) = 0;
		virtual hkResult displayLine(const hkVector4& start, const hkVector4& end, int color, int tag) = 0;
		virtual hkResult displayTriangle(const hkVector4& a, const hkVector4& b, const hkVector4& c, int colour, int tag) = 0;
		virtual hkResult displayText(const char* text, int color, int tag) = 0;
		virtual hkResult display3dText(const char* text, const hkVector4& pos, int color, int tag) = 0;
		virtual hkResult displayGeometry(const hkArray<hkDisplayGeometry*>& geometries, const hkTransform& transform, int color, int tag) = 0;
		virtual hkResult displayGeometry(const hkArray<hkDisplayGeometry*>& geometries, int color, int tag) = 0;
		virtual hkResult sendMemStatsDump(const char* data, int length) = 0;
		virtual hkResult holdImmediate() = 0;
		virtual void lockForUpdate() { }
		virtual void unlockForUpdate() { }
};
class hkColor
{
	public:
		static int __cdecl rgbFromChars(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xff);
		static int __cdecl rgbFromFloats(const hkReal red, const hkReal green, const hkReal blue, const hkReal alpha = 1.0f);
		static int __cdecl getRandomColor();
		inline static char __cdecl getAlphaAsChar(int color) { return char((unsigned(color) >> 24) & 0xFF);	}
		inline static hkReal __cdecl getAlphaAsFloat(int color) { return getAlphaAsChar(color) * (1.0f / 255.0f); }
		inline static char __cdecl getRedAsChar(int color) { return char((unsigned(color) >> 16) & 0xFF); }
		inline static hkReal __cdecl getRedAsFloat(int color) { return getRedAsChar(color) * (1.0f / 255.0f); }
		inline static char __cdecl getGreenAsChar(int color) { return char((unsigned(color) >> 8) & 0xFF); }
		inline static hkReal __cdecl getGreenAsFloat(int color) { return getGreenAsChar(color) * (1.0f / 255.0f); }
		inline static char __cdecl getBlueAsChar(int color) { return char(unsigned(color) & 0xFF); }
		inline static hkReal __cdecl getBlueAsFloat(int color) { return getBlueAsChar(color) * (1.0f / 255.0f); }
	public:
		enum ExtendedColours
		{
			MAROON = 0xFF800000,
			DARKRED = 0xFF8B0000,
			RED = 0xFFFF0000,
			LIGHTPINK = 0xFFFFB6C1,
			CRIMSON = 0xFFDC143C,
			PALEVIOLETRED = 0xFFDB7093,
			HOTPINK = 0xFFFF69B4,
			DEEPPINK = 0xFFFF1493,
			MEDIUMVIOLETRED = 0xFFC71585,
			PURPLE = 0xFF800080,
			DARKMAGENTA = 0xFF8B008B,
			ORCHID = 0xFFDA70D6,
			THISTLE = 0xFFD8BFD8,
			PLUM = 0xFFDDA0DD,
			VIOLET = 0xFFEE82EE,
			FUCHSIA = 0xFFFF00FF,
			MAGENTA = 0xFFFF00FF,
			MEDIUMORCHID = 0xFFBA55D3,
			DARKVIOLET = 0xFF9400D3,
			DARKORCHID = 0xFF9932CC,
			BLUEVIOLET = 0xFF8A2BE2,
			SPRINGGREEN = 0xFF00FF7F,
			MEDIUMSEAGREEN = 0xFF3CB371,
			SEAGREEN = 0xFF2E8B57,
			LIMEGREEN = 0xFF32CD32,
			DARKGREEN = 0xFF006400,
			GREEN = 0xFF008000,
			LIME = 0xFF00FF00,
			FORESTGREEN = 0xFF228B22,
			DARKSEAGREEN = 0xFF8FBC8F,
			LIGHTGREEN = 0xFF90EE90,
			PALEGREEN = 0xFF98FB98,
			MINTCREAM = 0xFFF5FFFA,
			HONEYDEW = 0xFFF0FFF0,
			CHARTREUSE = 0xFF7FFF00,
			LAWNGREEN = 0xFF7CFC00,
			OLIVEDRAB = 0xFF6B8E23,
			DARKOLIVEGREEN = 0xFF556B2F,
			YELLOWGREEN = 0xFF9ACD32,
			GREENYELLOW = 0xFFADFF2F,
			BEIGE = 0xFFF5F5DC,
			LINEN = 0xFFFAF0E6,
			LIGHTGOLDENRODYELLOW = 0xFFFAFAD2,
			OLIVE = 0xFF808000,
			YELLOW = 0xFFFFFF00,
			LIGHTYELLOW = 0xFFFFFFE0,
			IVORY = 0xFFFFFFF0,
			DARKKHAKI = 0xFFBDB76B,
			KHAKI = 0xFFF0E68C,
			PALEGOLDENROD = 0xFFEEE8AA,
			WHEAT = 0xFFF5DEB3,
			GOLD = 0xFFFFD700,
			LEMONCHIFFON = 0xFFFFFACD,
			PAPAYAWHIP = 0xFFFFEFD5,
			DARKGOLDENROD = 0xFFB8860B,
			GOLDENROD = 0xFFDAA520,
			ANTIQUEWHITE = 0xFFFAEBD7,
			CORNSILK = 0xFFFFF8DC,
			OLDLACE = 0xFFFDF5E6,
			MOCCASIN = 0xFFFFE4B5,
			NAVAJOWHITE = 0xFFFFDEAD,
			GREY50 = 0xff808080,
			GREY75 = 0xffc0c0c0,
		};
};
// pdb: hkpRagdollDrawer::drawConstraint | hkpRagdollDrawer.obj | fnv360_0822_retail, call_gap, medium
// pdb params: constraint, displayHandler, id, tag
void hkpRagdollDrawer::FUN_00a6d290(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int tag)
{
	hkpRagdollConstraintData* ragdoll = static_cast<hkpRagdollConstraintData*>(constraint->getData());
	m_primitiveDrawer.setDisplayHandler(displayHandler);
	{
		hkTransform refLocalToWorld;
		hkTransform attLocalToWorld;
		updateCommonParameters(constraint, refLocalToWorld, attLocalToWorld);
		m_bodyBWPivot.setTransformedPos(refLocalToWorld, ragdoll->m_atoms.m_transforms.m_transformB.getTranslation());
		m_bodyAWPivot.setTransformedPos(attLocalToWorld, ragdoll->m_atoms.m_transforms.m_transformA.getTranslation());
	}
	drawPivots(tag);
	const hkpRagdollConstraintData::Atoms& atoms = ragdoll->m_atoms;
	const hkTransform& baseA = atoms.m_transforms.m_transformA;
	const hkTransform& baseB = atoms.m_transforms.m_transformB;
	hkVector4 refTwistAxisWorld; refTwistAxisWorld.setRotatedDir(m_RB, atoms.m_transforms.m_transformB.getColumn(atoms.m_twistLimit.m_twistAxis));
	hkVector4 refCrossedWorld; refCrossedWorld.setCross(baseB.getColumn(atoms.m_planesLimit.m_twistAxisInA), baseB.getColumn(atoms.m_planesLimit.m_refAxisInB));
	refCrossedWorld.normalize3();
	refCrossedWorld.setRotatedDir(m_RB, refCrossedWorld);
	hkVector4 refPlaneNormalWorld; refPlaneNormalWorld.setRotatedDir(m_RB, baseB.getColumn(atoms.m_planesLimit.m_refAxisInB));
	hkVector4 cross; cross.setCross(baseA.getColumn(atoms.m_planesLimit.m_refAxisInB), baseA.getColumn(atoms.m_planesLimit.m_twistAxisInA));
	cross.normalize3();
	hkVector4 attCrossedWorld; attCrossedWorld.setRotatedDir(m_RA, cross);
	hkVector4 attTwistAxisWorld; attTwistAxisWorld.setRotatedDir(m_RA, baseA.getColumn(atoms.m_twistLimit.m_twistAxis));
	m_primitiveDrawer.displayArrow(m_bodyBWPivot, refTwistAxisWorld, refCrossedWorld, hkColor::GREEN, m_arrowSize, tag);
	m_primitiveDrawer.displayArrow(m_bodyAWPivot, attTwistAxisWorld, attCrossedWorld, hkColor::rgbFromChars(255, 255, 0), m_arrowSize, tag);
	hkReal coneHeight = 0.5f;
	m_twistCone.setParameters(ragdoll->getConeAngularLimit(), coneHeight, 24, refTwistAxisWorld, m_bodyBWPivot);
	hkVector4 ext; ext.setAll(coneHeight * 0.5f);
	m_plane.setParameters(refPlaneNormalWorld, refCrossedWorld, m_bodyBWPivot, ext);
	{
		hkReal planeMaxLimit = atoms.m_planesLimit.m_maxAngle;
		hkReal planeMinLimit = atoms.m_planesLimit.m_minAngle;
		m_planeCone1.setParameters(3.14159265358979f * 0.5f - hkMath::fabs(planeMaxLimit), coneHeight, 24, refPlaneNormalWorld, m_bodyBWPivot);
		refPlaneNormalWorld.setNeg4(refPlaneNormalWorld);
		m_planeCone2.setParameters(3.14159265358979f * 0.5f - hkMath::fabs(planeMinLimit), coneHeight, 24, refPlaneNormalWorld, m_bodyBWPivot);
	}
	{
		hkArray<hkDisplayGeometry*> twist;
		hkArray<hkDisplayGeometry*> planeCones;
		hkArray<hkDisplayGeometry*> plane;
		twist.setSize(1);
		plane.setSize(1);
		planeCones.setSize(2);
		twist[0] = &m_twistCone;
		planeCones[0] = &m_planeCone1;
		planeCones[1] = &m_planeCone2;
		plane[0] = &m_plane;
		displayHandler->displayGeometry(twist, hkColor::YELLOW, tag);
		displayHandler->displayGeometry(planeCones, hkColor::RED, tag);
		displayHandler->displayGeometry(plane, hkColor::rgbFromChars(255, 0, 255), tag);
	}
}

}  // namespace f3m_00a6d290
