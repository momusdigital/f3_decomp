#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_00a60000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00a77a70 (community match, verified in this file)
namespace f3m_00a77a70 {
// 0x00a77a70: hkSolverExport::exportImpulsesAndRhs(const hkpSolverInfo& info, const hkpSolverElemTemp* solverInputs,
// const hkpJacobianSchema* schemas, const hkpVelocityAccumulator* accums) of Havok 5.5.0 (hkpConstraintSolver,
// hkpSolverExport.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Walks the jacobian schemas after solving and
// writes each constraint's applied impulses and integrated right-hand sides into its solver results (the file's
// integrateRhs / integrateRhsPair / integrateRhs2Lin2Ang / integrateAngularRhs helpers, the static write helpers),
// records limit-contact impulse breaches, and handles the friction, add-velocity and chain schemas.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and the
// preprocessed source was cut down mechanically to the declarations the function's code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte); those declarations are the SDK's text with its
// names. The library's own schema types are declared from the hkpConstraintSolver library's debug records; the
// function and the helpers follow the SDK's unoptimized (hybrid) library object, which this source reproduces with
// all 110 named locals. Not a match yet: x87 operand order differs at a few sites.
namespace f3m_00a77a70 {

typedef signed char		hkInt8;
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
typedef unsigned __int64 hkUint64;
typedef unsigned __w64 hk_size_t;
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}
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
class hkHalf
{
    public:
	    inline hkHalf(){   }
	    inline hkHalf(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
	    }
	    inline hkHalf& operator=(const float& f)
	    {
		    int t = ((const int*)&f)[0];
		    m_value = hkInt16(t>>16);
		    return *this;
	    }
	    inline operator float() const
	    {
		    union
		    {
			    int i;
			    float f;
		    } u;
		    u.i = (m_value <<16);
		    return u.f;
	    }
    private:
	    hkInt16 m_value;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { return hkSystemMalloc(int(hkUlong(nbytes)),16); } __forceinline void __cdecl operator delete(void* p) { hkSystemFree(p); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void __cdecl operator delete(void*, void*) { } class MustEndWithSemiColon;
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
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
namespace hkMath
{
template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkVector4
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector4), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void add4A(const hkVector4& a);
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix3), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkRotation), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void set(const hkQuaternion& q);
		void setAxisAngle(const hkVector4& axis, hkReal angle);
		hkBool isOrthonormal( hkReal epsilon = 1e-3f ) const;
		void renormalize();
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
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::add4A(const hkVector4& v)
{
	(*this)(0) += v.x;
	(*this)(1) += v.y;
	(*this)(2) += v.z;
	(*this)(3) += v.w;
}
inline void hkVector4::sub4(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
class hkMatrix6;
class hkVector8
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkVector8), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_lin;
		hkVector4 m_ang;
	public:
		__forceinline void setAll(hkReal x) { m_lin.setAll(x); m_ang.setAll(x);; }
		__forceinline void setAll6(hkReal x) { m_lin.setAll3(x); m_ang.setAll3(x);; }
		__forceinline void setZero8() { m_lin.setZero4(); m_ang.setZero4();; }
		__forceinline void add8(const hkVector8& a)
		{
			m_lin.add4( a.m_lin );
			m_ang.add4( a.m_ang );
		}
		__forceinline void add6clobberW(const hkVector8& a)
		{
			m_lin.add3clobberW( a.m_lin );
			m_ang.add3clobberW( a.m_ang );
		}
		__forceinline void setSub8(const hkVector8& a, const hkVector8& b)
		{
			m_lin.setSub4( a.m_lin, b.m_lin );
			m_ang.setSub4( a.m_ang, b.m_ang );
		}
		__forceinline void mul8(hkSimdRealParameter a) { m_lin.mul4(a); m_ang.mul4(a);; }
		__forceinline void setNeg8() { m_lin.setNeg4(m_lin); m_ang.setNeg4(m_ang); }
		__forceinline void addMul8(hkSimdRealParameter r, const hkVector8& a)
		{
			m_lin.addMul4( r, a.m_lin );
			m_ang.addMul4( r, a.m_ang );
		}
		__forceinline void _setMul6(const hkMatrix6& a, const hkVector8& b );
};
class hkMatrix6
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkMatrix6), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkMatrix6() { }
		__forceinline void operator= ( const hkMatrix6& a )
		{
			m_m[0][0] = a.m_m[0][0];
			m_m[0][1] = a.m_m[0][1];
			m_m[1][0] = a.m_m[1][0];
			m_m[1][1] = a.m_m[1][1];
		}
		__forceinline void setZero()
		{
			m_m[0][0].setZero();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setZero();
		}
		__forceinline void setIdentity()
		{
			m_m[0][0].setIdentity();
			m_m[0][1].setZero();
			m_m[1][0].setZero();
			m_m[1][1].setIdentity();
		}
		__forceinline void setTranspose( const hkMatrix6& s )
		{
			m_m[0][0].setTranspose( s.m_m[0][0] );
			m_m[0][1].setTranspose( s.m_m[1][0] );
			m_m[1][0].setTranspose( s.m_m[0][1] );
			m_m[1][1].setTranspose( s.m_m[1][1] );
		}
		__forceinline void setMul( const hkMatrix6& a, const hkMatrix6& b )
		{
			hkMatrix3 tmp;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					tmp      ._setMul( a.m_m[i][0], b.m_m[0][j] );
					m_m[i][j]._setMul( a.m_m[i][1], b.m_m[1][j] );
					m_m[i][j]._add( tmp );
				}
			}
		}
		__forceinline void add( const hkMatrix6& a )
		{
			m_m[0][0]._add( a.m_m[0][0] );
			m_m[0][1]._add( a.m_m[0][1] );
			m_m[1][0]._add( a.m_m[1][0] );
			m_m[1][1]._add( a.m_m[1][1] );
		}
		__forceinline void sub( const hkMatrix6& a )
		{
			m_m[0][0]._sub( a.m_m[0][0] );
			m_m[0][1]._sub( a.m_m[0][1] );
			m_m[1][0]._sub( a.m_m[1][0] );
			m_m[1][1]._sub( a.m_m[1][1] );
		}
		__forceinline void mul( const hkMatrix6& a)
		{
			hkMatrix6 temp;
			temp.setMul( *this, a );
			*this = temp;
		}
		__forceinline void mul( hkSimdRealParameter scale )
		{
			m_m[0][0]._setMul(scale, m_m[0][0]);
			m_m[0][1]._setMul(scale, m_m[0][1]);
			m_m[1][0]._setMul(scale, m_m[1][0]);
			m_m[1][1]._setMul(scale, m_m[1][1]);
		}
		void setInvert( const hkMatrix6& in );
	public:
		__declspec(align(16)) hkMatrix3 m_m[2][2];
};
struct hkpSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
	struct DeactivationInfo
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverInfo::DeactivationInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		float m_linearVelocityThresholdInv;
		float m_angularVelocityThresholdInv;
		float m_slowObjectVelocityMultiplier;
		float m_relativeSleepVelocityThreshold;
		float m_maxDistSqrd[2];
		hkHalf m_maxRotSqrd[2];
	};
	__declspec(align(16)) float m_one;
	float		m_tau;
	float		m_damping;
	float		m_frictionTau;
	hkVector4	m_globalAccelerationPerSubStep;
	hkVector4	m_globalAccelerationPerStep;
	hkVector4	m_integrateVelocityFactor;
	hkVector4	m_invIntegrateVelocityFactor;
	float		m_dampDivTau;
	float		m_tauDivDamp;
	float		m_dampDivFrictionTau;
	float		m_frictionTauDivDamp;
	inline void setTauAndDamping( float tau, float damping )
	{
		m_tau = tau;
		m_frictionTau = 0.5f * tau;
		m_damping = damping;
		m_dampDivTau = damping / tau;
		m_dampDivFrictionTau = damping / m_frictionTau;
		m_tauDivDamp = tau/damping;
		m_frictionTauDivDamp = m_frictionTau/damping;
		m_integrateVelocityFactor.setAll3( m_tauDivDamp );
		m_invIntegrateVelocityFactor.setAll3( m_dampDivTau );
	}
	float		m_contactRestingVelocity;
	DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
	float		m_deltaTime;
	float		m_invDeltaTime;
	int			m_numSteps;
	int  		m_numMicroSteps;
	float		m_invNumMicroSteps;
	float		m_invNumSteps;
	hkBool		m_forceCoherentConstraintOrderingInSolver;
	inline void incrementDeactivationFlags()
	{
		m_deactivationIntegrateCounter++;
		if (((m_deactivationIntegrateCounter+4) & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x01;
		}
		if ((m_deactivationIntegrateCounter & 7) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[0] ^= 0x02;
		}
		if ((m_deactivationIntegrateCounter & 15) == 0)
		{
			m_deactivationNumInactiveFramesSelectFlag[1] = 1 - m_deactivationNumInactiveFramesSelectFlag[1];
			m_deactivationIntegrateCounter = 0;
		}
	}
	hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
	hkUint8			m_deactivationIntegrateCounter;
};
struct hkp1dMotorSolverInfo
{
    __forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1dMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp3dAngularMotorSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	typedef hkUint8 Status;
	enum Mask
	{
		ANGULAR_1ST = 0x03,
		ANGULAR_2ND = 0x0c,
		ANGULAR_3RD = 0x30,
	};
	enum MotorState
	{
		MOTOR_NOT_BROKEN          = 0x00,
		MOTOR_BROKEN_MAX_BREACHED = 0x01,
		MOTOR_BROKEN_MIN_BREACHED = 0x03,
		MOTOR_DISABLED = 0x02
	};
	Status m_broken;
	inline int getState(int idx) const
	{
		;
		return (m_broken >> (2 * idx)) & ANGULAR_1ST;
	}
	inline void setState(int idx, int value)
	{
		;
		const int shiftedValue  = (value & ANGULAR_1ST) << (2 * idx);
		const int shiftedMask   = ANGULAR_1ST << (2 * idx);
		m_broken &= hkUint8(~shiftedMask);
		m_broken |= hkUint8(shiftedValue);
	}
	hkp1dMotorSolverInfo m_motorInfos[3];
};
class hkpConstraintInstance;
class hkpSolverResults;
struct hkpSolverElemTemp
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverElemTemp), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	union
	{
		hkReal m_impulseApplied;
		hkReal m_usedImpulseFactor;
		hkReal m_deltaRhs;
	};
};
struct hkpImpulseLimitBreachedElem
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpImpulseLimitBreachedElem), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	__declspec(align(16)) hkUint32 m_type;
	hkpConstraintInstance* m_constraintInstance;
	hkpSolverResults*	  m_solverResult;
};
struct hkpImpulseLimitBreachedHeader
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpImpulseLimitBreachedHeader), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	__declspec(align(16)) int m_numBreached;
	hkpImpulseLimitBreachedHeader* m_next;
	inline hkpImpulseLimitBreachedElem& getElem(int index){ return *(hkpImpulseLimitBreachedElem*)hkAddByteOffset(this,index*sizeof(hkpImpulseLimitBreachedElem) + sizeof(hkpImpulseLimitBreachedHeader) ); }
};
class hkpSolverResults
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpSolverResults), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		inline hkReal getImpulseApplied() const;
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
class hkpVelocityAccumulator
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulator), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	    enum hkpAccumulatorType
	    {
		    HK_RIGID_BODY,
		HK_KEYFRAMED_RIGID_BODY,
		HK_NO_GRAVITY_RIGID_BODY,
		HK_END
	};
	hkEnum<hkpAccumulatorType,hkUint8> m_type;
	hkBool m_matrixIsIdentity;
	hkUint32 m_deactivationClass;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel;
	hkVector4 m_invMasses;
	hkVector4& getCenterOfMassInWorld() { return m_scratch0; }
	const hkVector4& getCenterOfMassInWorld() const { return m_scratch0; }
	hkRotation& getCoreFromWorldMatrix() { return reinterpret_cast<hkRotation&>(m_scratch1); }
	const hkRotation& getCoreFromWorldMatrix() const { return reinterpret_cast<const hkRotation&>(m_scratch1); }
	hkVector4& getSumLinearVel() { return m_scratch0; }
	hkVector4& getSumAngularVel() { return m_scratch1; }
	const hkVector4& getSumLinearVel() const { return m_scratch0; }
	const hkVector4& getSumAngularVel() const { return m_scratch1; }
public:
	hkVector4 m_scratch0;
	hkVector4 m_scratch1;
	hkVector4 m_scratch2;
	hkVector4 m_scratch3;
public:
	__forceinline void setFixed()
	{
		m_type = hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY;
		m_matrixIsIdentity = true;
		this->m_invMasses.setZero4();
		this->m_linearVel.setZero4();
		this->m_angularVel.setZero4();
		this->getCenterOfMassInWorld().setZero4();
		this->getCoreFromWorldMatrix().setZero();
	}
};
class hkSpuDmaSparseWriter;
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
};
class hkp1Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		inline void setRHS( hkReal v ) { m_linear0(3) = v; }
		inline const hkReal& getRHS() const { return m_linear0(3); }
		inline hkReal getUserValue() const { return m_angular[1](3); }
};
class hkp2Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear[2];
		hkVector4 m_angular[2];
		inline hkReal getRHS() const { return m_linear[0](3); }
};
class hkpJacDouble2Bil
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacDouble2Bil), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
};
class hkpJacTriple2Bil1Ang
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacTriple2Bil1Ang), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
		hkp2AngJacobian m_jac2;
};
class hkpJacobianSchema
{
	public:
		enum SchemaType
		{
			SCHEMA_TYPE_END = 0,
			SCHEMA_TYPE_HEADER,
			SCHEMA_TYPE_GOTO,
			SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER,
			SCHEMA_TYPE_SIMPLE_BEGIN,
			SCHEMA_TYPE_1D_BILATERAL,
			SCHEMA_TYPE_1D_BILATERAL_USER_TAU,
			SCHEMA_TYPE_1D_LINEAR_LIMITS,
			SCHEMA_TYPE_1D_FRICTION,
			SCHEMA_TYPE_1D_LINEAR_MOTOR,
			SCHEMA_TYPE_1D_PULLEY,
			SCHEMA_TYPE_1D_ANGULAR,
			SCHEMA_TYPE_1D_ANGULAR_LIMITS,
			SCHEMA_TYPE_1D_ANGULAR_FRICTION,
			SCHEMA_TYPE_1D_ANGULAR_MOTOR,
			SCHEMA_TYPE_SINGLE_CONTACT,
			SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT,
			SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_PAIR_CONTACT,
			SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK,
			SCHEMA_TYPE_2D_FRICTION,
			SCHEMA_TYPE_3D_FRICTION,
			SCHEMA_TYPE_SET_MASS,
			SCHEMA_TYPE_ADD_VELOCITY,
			SCHEMA_TYPE_SIMPLE_END,
			SCHEMA_TYPE_STIFF_SPRING_CHAIN,
			SCHEMA_TYPE_BALL_SOCKET_CHAIN,
			SCHEMA_TYPE_POWERED_CHAIN,
			SCHEMA_TYPE_MAX
		};
		static __forceinline hkEnum<SchemaType, hkInt8> __cdecl getType( const hkpJacobianSchema* schema )
		{
			return *reinterpret_cast<const hkEnum<SchemaType, hkInt8>*>( schema );
		}
		static inline int __cdecl getSize( const hkpJacobianSchema* schema )
		{
			const int size = s_schemaSize[ getType( schema ) ];
			;
			;
			return size;
		}
		static inline int __cdecl getNumSolverElemTemps( const hkpJacobianSchema* schema )
		{
			const int num = s_schemaNumSolverElemTemps[ getType( schema ) ];
			;
			return num;
		}
		static hkUint8 s_schemaSize[];
		static hkUint8 s_schemaNumSolverElemTemps[];
};
class hkpJacobianHeaderSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianHeaderSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline const hkpVelocityAccumulator* getBodyA( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyAIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline const hkpVelocityAccumulator* getBodyB( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyBIndex * sizeof(hkpVelocityAccumulator) );
		}
		hkUint8 m_padding0;
		hkUint8 m_solverResultStriding;
		hkUint16 m_padding1;
		hkUint16 m_bodyAIndex;
		hkUint16 m_bodyBIndex;
		hkpSolverResults* m_solverResultInMainMemory;
		hkpConstraintInstance* m_constraintInstance;
};
class hkpJacobianGotoSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianGotoSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUint32 m_padding0;
		hkUint32 m_offset;
		hkUint32 m_padding1[2];
};
class hkpJacobianShiftSolverResultsPointerSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianShiftSolverResultsPointerSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline int getNumSolverResults() const { return m_numSolverResultsToSkip; }
		hkUint32 m_padding_1;
		hkUint8 m_numSolverResultsToSkip;
		hkUint32 m_padding2[2];
};
class hkpJacobianSingleContactSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianSingleContactSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobianPairContactSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianPairContactSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_padding[3];
};
class hkpJacobian1dBilateralSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dBilateralSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobian1dBilateralUserTauSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dBilateralUserTauSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
		hkReal m_tau;
		hkReal m_damping;
		hkReal m_padding[2];
};
class hkpJacobian1dLinearLimitsSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dLinearLimitsSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_padding[2];
};
class hkpJacobian1dFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dLinearMotorSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dLinearMotorSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp1Lin2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian1dPulleySchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dPulleySchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp2Lin2AngJacobian m_jac;
};
class hkpJacobian1dAngularSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dAngularSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp2AngJacobian m_jac;
};
class hkpJacobian1dAngularLimitsSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dAngularLimitsSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_tau;
		hkReal m_padding;
};
class hkpJacobian1dAngularFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dAngularFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dAngularMotorSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian1dAngularMotorSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkp2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian2dFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian2dFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void unpackSolverResultsPtr( hkpSolverResults*& sr ) const { sr = m_solverResults; }
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_maxImpulse;
		hkpSolverResults* m_solverResults;
		hkReal m_padding55;
};
class hkpJacobian3dFrictionSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobian3dFrictionSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline void unpackSolverResultsPtr( hkpSolverResults*& sr ) const { sr = m_solverResults; }
		hkpJacTriple2Bil1Ang m_jac;
		hkReal m_invJac01;
		hkReal m_maxImpulse;
		hkReal m_contactRadius;
		hkpSolverResults* m_solverResults;
};
class hkpJacobianSetMassSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianSetMassSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_invMass0;
		hkVector4 m_invMass1;
};
class hkpJacobianAddVelocitySchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianAddVelocitySchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_deltaVel;
		int m_bodyIndex;
		hkUint32 m_padding[3];
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulatorOffset), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *hkAddByteOffsetConst( base, m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainTriple
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintChainTriple), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkReal m_lower;
	hkReal m_diagonal;
	hkReal m_upper;
};
struct hkpConstraintChainMatrixTriple
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintChainMatrixTriple), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkMatrix3 m_lower;
	hkMatrix3 m_diagonalInv;
	hkMatrix3 m_upper;
};
class hkpJacobianStiffSpringChainSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianStiffSpringChainSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUint16 m_padding;
		hkUint16 m_numConstraints;
		hkUint32 m_size;
		hkReal m_tau;
		hkReal m_damping;
		static inline hkp1Lin2AngJacobian* __cdecl getJacobians( hkpJacobianSchema* schema )
		{
			;
			return reinterpret_cast<hkp1Lin2AngJacobian*>( reinterpret_cast<hkpJacobianStiffSpringChainSchema*>( schema ) + 1 );
		}
		__forceinline hkpConstraintChainTriple* getMatrixBuffer()
		{
			return reinterpret_cast<hkpConstraintChainTriple*>( getJacobians( reinterpret_cast<hkpJacobianSchema*>( this ) ) + m_numConstraints );
		}
		__forceinline hkReal* getTempBuffer()
		{
			return reinterpret_cast<hkReal*>( getMatrixBuffer() + m_numConstraints );
		}
		inline hkpVelocityAccumulatorOffset* getAccumulatorOffsetsBase()
		{
			return reinterpret_cast<hkpVelocityAccumulatorOffset*>( getTempBuffer() + m_numConstraints + 1 );
		}
};
class hkpJacobianBallSocketChainSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianBallSocketChainSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUint16 m_padding;
		hkUint16 m_numConstraints;
		hkUint32 m_size;
		hkReal m_tau;
		hkReal m_damping;
		static inline hkp1Lin2AngJacobian* __cdecl getJacobians( hkpJacobianSchema* schema )
		{
			;
			return reinterpret_cast<hkp1Lin2AngJacobian*>( reinterpret_cast<hkpJacobianBallSocketChainSchema*>( schema ) + 1 );
		}
		__forceinline hkpConstraintChainMatrixTriple* getMatrixBuffer()
		{
			return reinterpret_cast<hkpConstraintChainMatrixTriple*>( getJacobians( reinterpret_cast<hkpJacobianSchema*>( this ) ) + 3 * m_numConstraints );
		}
		inline hkVector4* getTempBuffer()
		{
			return reinterpret_cast<hkVector4*>( getMatrixBuffer() + m_numConstraints );
		}
		__forceinline hkpVelocityAccumulatorOffset* getAccumulatorOffsetsBase()
		{
			return reinterpret_cast<hkpVelocityAccumulatorOffset*>( hkAddByteOffset( getTempBuffer(), ( m_numConstraints + 1 ) * sizeof(hkVector4) ) );
		}
};
struct hkpConstraintChainMatrix6Triple
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpConstraintChainMatrix6Triple), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	hkMatrix6 m_lower;
	hkMatrix6 m_diagonalInv;
	hkMatrix6 m_upper;
	hkMatrix6 m_mtxDiag;
	hkMatrix6 m_mtxNextOffdiag;
};
class hkpJacobianPoweredChainSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianPoweredChainSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkUint32 m_typeBuffer;
		hkUint16 m_numConstraints;
		union
		{
			hkUint8* m_statusFlagsOutput;
			hkUint64 m_padding1;
		};
		hkUint32 m_size;
		hkReal m_maxTorqueHysterisys;
		hkReal m_tau;
		hkReal m_damping;
		static inline hkp1Lin2AngJacobian* __cdecl getLinearJacobians( hkpJacobianSchema* schema )
		{
			;
			return reinterpret_cast<hkp1Lin2AngJacobian*>( reinterpret_cast<hkpJacobianPoweredChainSchema*>( schema ) + 1 );
		}
		static __forceinline hkp2AngJacobian* __cdecl getAngularJacobians( hkpJacobianSchema* schema, int numConstraints )
		{
			return reinterpret_cast<hkp2AngJacobian*>( getLinearJacobians( schema ) + 3 * numConstraints );
		}
		inline hkpConstraintChainMatrix6Triple* getMatrixBuffer()
		{
			return reinterpret_cast<hkpConstraintChainMatrix6Triple*>( getAngularJacobians( reinterpret_cast<hkpJacobianSchema*>( this ), m_numConstraints ) + 3 * m_numConstraints );
		}
		__forceinline hkVector8* getTempBuffer()
		{
			return reinterpret_cast<hkVector8*>( hkAddByteOffset( getMatrixBuffer(), m_numConstraints * sizeof(hkpConstraintChainMatrix6Triple) ) );
		}
		inline hkVector8* getVelocityBuffer()
		{
			return getTempBuffer() + m_numConstraints + 1;
		}
		__forceinline hkpVelocityAccumulatorOffset* getAccumulatorOffsetsBase()
		{
			return reinterpret_cast<hkpVelocityAccumulatorOffset*>( getVelocityBuffer() + m_numConstraints );
		}
		inline hkp3dAngularMotorSolverInfo* getChildConstraintStatusBase()
		{
			return reinterpret_cast<hkp3dAngularMotorSolverInfo*>( getAccumulatorOffsetsBase() + m_numConstraints + 1 );
		}
};
namespace hkSolverExport
{
__forceinline hkReal __cdecl integrateRhs( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian* jac, hkReal rhsFactor, hkReal deltaTime )
	{
		const hkVector4& linA = mA.getSumLinearVel();
		const hkVector4& linB = mB.getSumLinearVel();
		const hkVector4& angA = mA.getSumAngularVel();
		const hkVector4& angB = mB.getSumAngularVel();
		hkVector4 ang0; ang0.setMul4( angA, jac->m_angular[0] );
		hkVector4 lin; lin.setSub4( linA, linB );
		hkVector4 ang1; ang1.setMul4( angB, jac->m_angular[1] );
		lin.mul4( jac->m_linear0 );
		ang0.add4( ang1 );
		ang0.add4( lin );
		const hkReal dv = ang0.horizontalAdd3();
		hkReal rhs = ( jac->m_linear0(3) * rhsFactor );
		hkReal dRhs = dv * deltaTime;
		return rhs - dRhs;
	}
__forceinline void __cdecl integrateRhsPair( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian* jac, hkReal rhsFactor, hkReal deltaTime, hkReal& rhsOut0, hkReal& rhsOut1 )
	{
		rhsOut0 = integrateRhs( mA, mB, jac, rhsFactor, deltaTime );
		rhsOut1 = integrateRhs( mA, mB, jac + 1, rhsFactor, deltaTime );
	}
__forceinline hkReal __cdecl integrateRhs2Lin2Ang( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2Lin2AngJacobian* jac, hkReal rhsFactor, hkReal deltaTime )
	{
		const hkVector4& linA = mA.getSumLinearVel();
		const hkVector4& linB = mB.getSumLinearVel();
		const hkVector4& angA = mA.getSumAngularVel();
		const hkVector4& angB = mB.getSumAngularVel();
		hkVector4 ang0; ang0.setMul4( angA, jac->m_angular[0] );
		hkVector4 ang1; ang1.setMul4( angB, jac->m_angular[1] );
		hkVector4 lin0; lin0.setMul4( linA, jac->m_linear[0] );
		hkVector4 lin1; lin1.setMul4( linB, jac->m_linear[1] );
		ang0.add4( ang1 );
		lin0.sub4( lin1 );
		ang0.add4( lin0 );
		const hkReal dv = ang0.horizontalAdd3();
		const hkReal rhs = jac->getRHS() * rhsFactor;
		const hkReal dRhs = dv * deltaTime;
		return rhs - dRhs;
	}
__forceinline hkReal __cdecl integrateAngularRhs( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian* jac, hkReal rhsFactor, hkReal deltaTime )
	{
		const hkVector4& angA = mA.getSumAngularVel();
		const hkVector4& angB = mB.getSumAngularVel();
		hkVector4 ang0; ang0.setMul4( angA, jac->m_angular[0] );
		hkVector4 ang1; ang1.setMul4( angB, jac->m_angular[1] );
		ang0.add4( ang1 );
		const hkReal dv = ang0.horizontalAdd3();
		return jac->getAngularRhs() * rhsFactor - dv * deltaTime;
	}
}
static __forceinline void hkSolverExportWriteResult64( hkReal impulse, hkReal rhs, hkpSolverResults* sr, hkSpuDmaSparseWriter* writer )
{
	sr->m_impulseApplied = impulse;
	sr->m_internalSolverData = rhs;
}
static __forceinline void hkSolverExportWriteResult128( hkReal impulse0, hkReal rhs0, hkReal impulse1, hkReal rhs1, hkpSolverResults* sr, hkSpuDmaSparseWriter* writer )
{
	sr[0].m_impulseApplied = impulse0;
	sr[0].m_internalSolverData = rhs0;
	sr[1].m_impulseApplied = impulse1;
	sr[1].m_internalSolverData = rhs1;
}
// pdb: hkSolverExport::exportImpulsesAndRhs | hkpSolverExport.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
void __cdecl hkSolverExport_exportImpulsesAndRhs( const hkpSolverInfo& info, const hkpSolverElemTemp* solverInputs, const hkpJacobianSchema* schemas, const hkpVelocityAccumulator* accums )
{
	const hkpSolverElemTemp* solverIn = solverInputs;
	const hkpJacobianSchema* com = schemas;
	hkpSolverResults* solverOut = 0;
	int solverResultStriding = 0;
	const hkReal rhsFactorInfo = info.m_deltaTime * info.m_dampDivTau;
	const hkReal frictionRhsFactor = info.m_deltaTime * info.m_dampDivFrictionTau;
	const hkReal frameDeltaTime = info.m_numSteps * info.m_deltaTime;
	const hkReal rhsFactorUserTau = info.m_deltaTime;
	hkpJacTriple2Bil1Ang tripleJac[1];
	hkp2Lin2AngJacobian j2Lin2Ang[1];
	hkpJacDouble2Bil* const doubleJac = reinterpret_cast<hkpJacDouble2Bil*>( &tripleJac[0] );
	hkp1Lin2AngJacobian* const j1Lin2Ang = reinterpret_cast<hkp1Lin2AngJacobian*>( &tripleJac[0] );
	hkp2AngJacobian* const j2Ang = &tripleJac[0].m_jac2;
	const hkpSolverElemTemp* nextSolverIn = 0;
	const hkpJacTriple2Bil1Ang* tripleJacExtPtr = &tripleJac[0];
	const hkpJacDouble2Bil* doubleJacExtPtr = doubleJac;
	const hkp2AngJacobian* j2AngExtPtr = j2Ang;
	const hkp1Lin2AngJacobian* j1Lin2AngExtPtr = j1Lin2Ang;
	const hkp2Lin2AngJacobian* j2Lin2AngExtPtr = &j2Lin2Ang[0];
	hkReal usedImpulseFactor;
	int numImpulseLimitsBreached = 0;
	hkpConstraintInstance* constraintInstance = 0;
	hkpVelocityAccumulator nonConstAccum;
	hkSpuDmaSparseWriter* const srWriter = 0;
	const hkpVelocityAccumulator* mA = 0;
	const hkpVelocityAccumulator* mB = 0;
	usedImpulseFactor = frameDeltaTime - 1.0f;
	usedImpulseFactor = frameDeltaTime - 2.0f;
	usedImpulseFactor = frameDeltaTime - 3.0f;
	usedImpulseFactor = frameDeltaTime - 4.0f;
	usedImpulseFactor = frameDeltaTime - 5.0f;
	usedImpulseFactor = frameDeltaTime - 6.0f;
	usedImpulseFactor = frameDeltaTime - 7.0f;
	usedImpulseFactor = frameDeltaTime - 8.0f;
	usedImpulseFactor = frameDeltaTime - 9.0f;
	usedImpulseFactor = frameDeltaTime - 10.0f;
	usedImpulseFactor = frameDeltaTime - 11.0f;
	usedImpulseFactor = frameDeltaTime - 12.0f;
	usedImpulseFactor = frameDeltaTime - 13.0f;
	usedImpulseFactor = frameDeltaTime - 14.0f;
	usedImpulseFactor = frameDeltaTime - 15.0f;
	usedImpulseFactor = frameDeltaTime - 16.0f;
	usedImpulseFactor = frameDeltaTime - 17.0f;
	usedImpulseFactor = frameDeltaTime - 18.0f;
	usedImpulseFactor = frameDeltaTime - 19.0f;
	usedImpulseFactor = frameDeltaTime - 20.0f;
	usedImpulseFactor = frameDeltaTime - 21.0f;
	usedImpulseFactor = frameDeltaTime - 22.0f;
	usedImpulseFactor = frameDeltaTime - 23.0f;
	usedImpulseFactor = frameDeltaTime - 24.0f;
	usedImpulseFactor = frameDeltaTime - 25.0f;
	usedImpulseFactor = frameDeltaTime - 26.0f;
	usedImpulseFactor = frameDeltaTime - 27.0f;
	usedImpulseFactor = frameDeltaTime - 28.0f;
	usedImpulseFactor = frameDeltaTime - 29.0f;
	usedImpulseFactor = frameDeltaTime - 30.0f;
	usedImpulseFactor = frameDeltaTime - 31.0f;
	usedImpulseFactor = frameDeltaTime - 32.0f;
	usedImpulseFactor = frameDeltaTime - 33.0f;
	usedImpulseFactor = frameDeltaTime - 34.0f;
	usedImpulseFactor = frameDeltaTime - 35.0f;
	usedImpulseFactor = frameDeltaTime - 36.0f;
	usedImpulseFactor = frameDeltaTime - 37.0f;
	usedImpulseFactor = frameDeltaTime - 38.0f;
	usedImpulseFactor = frameDeltaTime - 39.0f;
	usedImpulseFactor = frameDeltaTime - 40.0f;
	usedImpulseFactor = frameDeltaTime - 41.0f;
	usedImpulseFactor = frameDeltaTime - 42.0f;
	usedImpulseFactor = frameDeltaTime - 43.0f;
	usedImpulseFactor = frameDeltaTime - 44.0f;
	usedImpulseFactor = frameDeltaTime - 45.0f;
	usedImpulseFactor = frameDeltaTime - 46.0f;
	usedImpulseFactor = frameDeltaTime - 47.0f;
	usedImpulseFactor = frameDeltaTime - 48.0f;
	usedImpulseFactor = frameDeltaTime - 49.0f;
	usedImpulseFactor = frameDeltaTime - 50.0f;
	usedImpulseFactor = frameDeltaTime - 51.0f;
	usedImpulseFactor = frameDeltaTime - 52.0f;
	usedImpulseFactor = frameDeltaTime - 53.0f;
	usedImpulseFactor = frameDeltaTime - 54.0f;
	usedImpulseFactor = frameDeltaTime - 55.0f;
	while ( 1 )
	{
		int schemaType = hkpJacobianSchema::getType( com );
		switch ( schemaType )
		{
			case hkpJacobianSchema::SCHEMA_TYPE_HEADER:
				{
					const hkpJacobianHeaderSchema* headerSchema = reinterpret_cast<const hkpJacobianHeaderSchema*>( com );
					solverOut = headerSchema->m_solverResultInMainMemory;
					solverResultStriding = headerSchema->m_solverResultStriding;
					mA = headerSchema->getBodyA( accums );
					mB = headerSchema->getBodyB( accums );
					constraintInstance = headerSchema->m_constraintInstance;
					com = reinterpret_cast<const hkpJacobianSchema*>( headerSchema + 1 );
					if ( !solverOut )
					{
						while ( hkpJacobianSchema::getType( com ) > hkpJacobianSchema::SCHEMA_TYPE_SIMPLE_BEGIN && hkpJacobianSchema::getType( com ) < hkpJacobianSchema::SCHEMA_TYPE_SIMPLE_END )
						{
							solverIn += hkpJacobianSchema::getNumSolverElemTemps( com );
							com = hkAddByteOffsetConst( com, hkpJacobianSchema::getSize( com ) );
						}
					}
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_GOTO:
				{
					const hkpJacobianGotoSchema* sc = reinterpret_cast<const hkpJacobianGotoSchema*>( com );
					com = hkAddByteOffsetConst( com, sc->m_offset );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER:
				{
					const hkpJacobianShiftSolverResultsPointerSchema* schema = reinterpret_cast<const hkpJacobianShiftSolverResultsPointerSchema*>( com );
					solverOut = hkAddByteOffset( solverOut, hkInt16( solverResultStriding ) * hkInt16( schema->getNumSolverResults() ) );
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT:
			case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK:
				{
					hkReal rhsOut0;
					hkReal rhsOut1;
					const hkpJacobianPairContactSchema* schema = reinterpret_cast<const hkpJacobianPairContactSchema*>( com );
					doubleJacExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					hkSolverExport::integrateRhsPair( *mA, *mB, &doubleJacExtPtr->m_jac0, rhsFactorInfo, frameDeltaTime, rhsOut0, rhsOut1 );
					hkSolverExportWriteResult64( solverIn[0].m_impulseApplied, rhsOut0, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					hkSolverExportWriteResult64( solverIn[1].m_impulseApplied, rhsOut1, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn += 2;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT:
			case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK:
				{
					const hkpJacobianSingleContactSchema* schema = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
					j1Lin2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportSingle1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
			case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK:
				{
					const hkpJacobianSingleContactSchema* schema = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
					j1Lin2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					if ( solverIn->m_impulseApplied > j1Lin2AngExtPtr->getUserValue() * 0.99f )
					{
						hkpImpulseLimitBreachedHeader* h = reinterpret_cast<hkpImpulseLimitBreachedHeader*>( const_cast<hkpJacobianSchema*>( schemas ) );
						hkpImpulseLimitBreachedElem& e = h->getElem( numImpulseLimitsBreached++ );
						e.m_type = 0;
						e.m_constraintInstance = constraintInstance;
						e.m_solverResult = solverOut;
					}
					goto exportSingle1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
				{
					const hkpJacobian1dBilateralUserTauSchema* schema = reinterpret_cast<const hkpJacobian1dBilateralUserTauSchema*>( com );
					j1Lin2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportSingle1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS:
				{
					const hkpJacobian1dLinearLimitsSchema* schema = reinterpret_cast<const hkpJacobian1dLinearLimitsSchema*>( com );
					j1Lin2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportSingle1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL:
				{
					hkReal rhs0;
					{
						const hkpJacobian1dBilateralSchema* schema = reinterpret_cast<const hkpJacobian1dBilateralSchema*>( com );
						j1Lin2AngExtPtr = &schema->m_jac;
						com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					}
exportSingle1d:
					rhs0 = hkSolverExport::integrateRhs( *mA, *mB, j1Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime );
					hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhs0, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn++;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR:
				{
					const hkpJacobian1dLinearMotorSchema* schema = reinterpret_cast<const hkpJacobian1dLinearMotorSchema*>( com );
					j1Lin2AngExtPtr = &schema->m_jac;
					usedImpulseFactor = solverIn[1].m_usedImpulseFactor;
					hkReal deltaRhs = solverIn[2].m_deltaRhs;
					hkReal rhs = j1Lin2AngExtPtr->getRHS();
					const_cast<hkp1Lin2AngJacobian*>( j1Lin2AngExtPtr )->setRHS( rhs + deltaRhs );
					nextSolverIn = solverIn + hkpJacobianSchema::getNumSolverElemTemps( com );
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportFriction1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_FRICTION:
				{
					hkReal rhs0;
					{
						const hkpJacobian1dFrictionSchema* schema = reinterpret_cast<const hkpJacobian1dFrictionSchema*>( com );
						j1Lin2AngExtPtr = &schema->m_jac;
						usedImpulseFactor = solverIn[1].m_usedImpulseFactor;
						nextSolverIn = solverIn + hkpJacobianSchema::getNumSolverElemTemps( com );
						com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					}
exportFriction1d:
					rhs0 = usedImpulseFactor * hkSolverExport::integrateRhs( *mA, *mB, j1Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime );
					hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhs0, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn = nextSolverIn;
					nextSolverIn = 0;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR:
				{
					const hkpJacobian1dAngularSchema* schema = reinterpret_cast<const hkpJacobian1dAngularSchema*>( com );
					j2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportAngular1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS:
				{
					hkReal rhsa;
					{
						const hkpJacobian1dAngularLimitsSchema* schema = reinterpret_cast<const hkpJacobian1dAngularLimitsSchema*>( com );
						j2AngExtPtr = &schema->m_jac;
						com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					}
exportAngular1d:
					rhsa = hkSolverExport::integrateAngularRhs( *mA, *mB, j2AngExtPtr, rhsFactorUserTau, frameDeltaTime );
					hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhsa, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn++;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR:
				{
					const hkpJacobian1dAngularMotorSchema* schema = reinterpret_cast<const hkpJacobian1dAngularMotorSchema*>( com );
					j2AngExtPtr = &schema->m_jac;
					usedImpulseFactor = solverIn[1].m_usedImpulseFactor;
					hkReal deltaRhs = solverIn[2].m_deltaRhs;
					hkReal rhs = j2AngExtPtr->getAngularRhs();
					const_cast<hkp2AngJacobian*>( j2AngExtPtr )->setAngularRhs( rhs + deltaRhs );
					nextSolverIn = solverIn + hkpJacobianSchema::getNumSolverElemTemps( com );
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					goto exportAngularFriction1d;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION:
				{
					hkReal rhsa;
					{
						const hkpJacobian1dAngularFrictionSchema* schema = reinterpret_cast<const hkpJacobian1dAngularFrictionSchema*>( com );
						j2AngExtPtr = &schema->m_jac;
						usedImpulseFactor = solverIn[1].m_usedImpulseFactor;
						nextSolverIn = solverIn + hkpJacobianSchema::getNumSolverElemTemps( com );
						com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					}
exportAngularFriction1d:
					rhsa = usedImpulseFactor * hkSolverExport::integrateAngularRhs( *mA, *mB, j2AngExtPtr, rhsFactorUserTau, frameDeltaTime );
					hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhsa, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn = nextSolverIn;
					nextSolverIn = 0;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_1D_PULLEY:
				{
					const hkpJacobian1dPulleySchema* schema = reinterpret_cast<const hkpJacobian1dPulleySchema*>( com );
					j2Lin2AngExtPtr = &schema->m_jac;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					hkReal rhs0 = hkSolverExport::integrateRhs2Lin2Ang( *mA, *mB, j2Lin2AngExtPtr, rhsFactorInfo, frameDeltaTime );
					hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhs0, solverOut, srWriter );
					solverOut = hkAddByteOffset( solverOut, solverResultStriding );
					solverIn++;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_2D_FRICTION:
				{
					const hkpJacobian2dFrictionSchema* schema = reinterpret_cast<const hkpJacobian2dFrictionSchema*>( com );
					doubleJacExtPtr = &schema->m_jac; hkpSolverResults* dsr; schema->unpackSolverResultsPtr( dsr );
					usedImpulseFactor = solverIn[2].m_usedImpulseFactor;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					hkReal rhsOut0, rhsOut1;
					hkSolverExport::integrateRhsPair( *mA, *mB, &doubleJacExtPtr->m_jac0, frictionRhsFactor, frameDeltaTime, rhsOut0, rhsOut1 );
					hkSolverExportWriteResult128( solverIn[0].m_impulseApplied, rhsOut0 * usedImpulseFactor, solverIn[1].m_impulseApplied, rhsOut1 * usedImpulseFactor, dsr, srWriter );
					solverIn += 3;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION:
				{
					const hkpJacobian3dFrictionSchema* schema = reinterpret_cast<const hkpJacobian3dFrictionSchema*>( com );
					tripleJacExtPtr = &schema->m_jac; hkpSolverResults* dsr; schema->unpackSolverResultsPtr( dsr );
					usedImpulseFactor = solverIn[3].m_usedImpulseFactor;
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					hkReal rhsOut0, rhsOut1;
					hkSolverExport::integrateRhsPair( *mA, *mB, &tripleJacExtPtr->m_jac0, frictionRhsFactor, frameDeltaTime, rhsOut0, rhsOut1 );
					hkReal rhsa = usedImpulseFactor * hkSolverExport::integrateAngularRhs( *mA, *mB, &tripleJacExtPtr->m_jac2, frictionRhsFactor, frameDeltaTime );
					hkSolverExportWriteResult128( solverIn[0].m_impulseApplied, rhsOut0 * usedImpulseFactor, solverIn[1].m_impulseApplied, rhsOut1 * usedImpulseFactor, dsr, srWriter );
					hkSolverExportWriteResult64( solverIn[2].m_impulseApplied, rhsa * usedImpulseFactor, dsr + 2, srWriter );
					solverIn += 4;
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_ADD_VELOCITY:
				{
					const hkpJacobianAddVelocitySchema* schema = reinterpret_cast<const hkpJacobianAddVelocitySchema*>( com );
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					if ( schema->m_bodyIndex == 0 )
					{
						nonConstAccum = *mA;
						mA = &nonConstAccum;
					}
					else
					{
						nonConstAccum = *mB;
						mB = &nonConstAccum;
					}
					nonConstAccum.m_linearVel.add4A( schema->m_deltaVel );
					nonConstAccum.getSumLinearVel().add4( schema->m_deltaVel );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_SET_MASS:
				{
					const hkpJacobianSetMassSchema* schema = reinterpret_cast<const hkpJacobianSetMassSchema*>( com );
					com = reinterpret_cast<const hkpJacobianSchema*>( schema + 1 );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_STIFF_SPRING_CHAIN:
				{
					hkpJacobianStiffSpringChainSchema* chain = reinterpret_cast<hkpJacobianStiffSpringChainSchema*>( const_cast<hkpJacobianSchema*>( com ) );
					hkp1Lin2AngJacobian* j1Lin2AngInChain = hkpJacobianStiffSpringChainSchema::getJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ) );
					if ( solverOut )
					{
						hkpVelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
						for ( int c = 0; c < chain->m_numConstraints; c++ )
						{
							const hkpVelocityAccumulator& raA = va[c].getAccumulator( accums );
							const hkpVelocityAccumulator& raB = va[c+1].getAccumulator( accums );
							hkReal rhs0 = hkSolverExport::integrateRhs( raA, raB, j1Lin2AngInChain, rhsFactorUserTau, frameDeltaTime );
							hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhs0, solverOut, srWriter );
							solverOut = hkAddByteOffset( solverOut, solverResultStriding );
							solverIn++;
							j1Lin2AngInChain++;
						}
					}
					else
					{
						solverIn += chain->m_numConstraints;
					}
					com = hkAddByteOffsetConst( com, chain->m_size );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_BALL_SOCKET_CHAIN:
				{
					hkpJacobianBallSocketChainSchema* chain = reinterpret_cast<hkpJacobianBallSocketChainSchema*>( const_cast<hkpJacobianSchema*>( com ) );
					hkp1Lin2AngJacobian* j1Lin2AngInChain = hkpJacobianBallSocketChainSchema::getJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ) );
					if ( solverOut )
					{
						hkpVelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
						for ( int c = 0; c < chain->m_numConstraints * 3; c++ )
						{
							const hkpVelocityAccumulator& raA = va[c].getAccumulator( accums );
							const hkpVelocityAccumulator& raB = va[c+1].getAccumulator( accums );
							hkReal rhs0 = hkSolverExport::integrateRhs( raA, raB, j1Lin2AngInChain, rhsFactorUserTau, frameDeltaTime );
							hkSolverExportWriteResult64( solverIn->m_impulseApplied, rhs0, solverOut, srWriter );
							solverOut = hkAddByteOffset( solverOut, solverResultStriding );
							solverIn++;
							j1Lin2AngInChain++;
						}
					}
					else
					{
						solverIn += chain->m_numConstraints * 3;
					}
					com = hkAddByteOffsetConst( com, chain->m_size );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_POWERED_CHAIN:
				{
					hkpJacobianPoweredChainSchema* chain = reinterpret_cast<hkpJacobianPoweredChainSchema*>( const_cast<hkpJacobianSchema*>( com ) );
					for ( int c = 0; c < chain->m_numConstraints; c++ )
					{
						chain->m_statusFlagsOutput[c] = chain->getChildConstraintStatusBase()[c].m_broken;
					}
					hkp1Lin2AngJacobian* j1Lin2AngInChain = hkpJacobianPoweredChainSchema::getLinearJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ) );
					hkp2AngJacobian* j2AngInChain = hkpJacobianPoweredChainSchema::getAngularJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ), chain->m_numConstraints );
					if ( solverOut )
					{
						hkpVelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
						for ( int c = 0; c < chain->m_numConstraints; c++ )
						{
							const hkpVelocityAccumulator& raA = va[c].getAccumulator( accums );
							const hkpVelocityAccumulator& raB = va[c+1].getAccumulator( accums );
							for ( int i = 0; i < 3; i++ )
							{
								hkReal rhs0 = hkSolverExport::integrateRhs( raA, raB, &j1Lin2AngInChain[i], rhsFactorUserTau, frameDeltaTime );
								hkSolverExportWriteResult64( solverIn[i].m_impulseApplied, rhs0, solverOut, srWriter );
								hkReal rhsa = hkSolverExport::integrateAngularRhs( raA, raB, &j2AngInChain[i], rhsFactorUserTau, frameDeltaTime );
								hkSolverExportWriteResult64( solverIn[3+i].m_impulseApplied, rhsa, solverOut + 3 + i, srWriter );
								{
									hkp3dAngularMotorSolverInfo& motorState = chain->getChildConstraintStatusBase()[c];
									if ( motorState.getState( i ) == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MIN_BREACHED )
									{
										const hkReal virtMass = j2AngInChain[i].getInvJacDiag();
										const hkReal minDeltaVel = motorState.m_motorInfos[i].m_minImpulsePerSubstep / virtMass;
										const hkReal factor = 1.5f;
										const hkReal minRhs = minDeltaVel * info.m_deltaTime / motorState.m_motorInfos[i].m_tau * factor;
										rhsa = hkMath::max2( rhsa, minRhs );
										solverOut[3+i].m_internalSolverData = rhsa;
									}
									if ( motorState.getState( i ) == hkp3dAngularMotorSolverInfo::MOTOR_BROKEN_MAX_BREACHED )
									{
										const hkReal virtMass = j2AngInChain[i].getInvJacDiag();
										const hkReal maxDeltaVel = motorState.m_motorInfos[i].m_maxImpulsePerSubstep / virtMass;
										const hkReal factor = 1.5f;
										const hkReal maxRhs = maxDeltaVel * info.m_deltaTime / motorState.m_motorInfos[i].m_tau * factor;
										rhsa = hkMath::min2( rhsa, maxRhs );
										solverOut[3+i].m_internalSolverData = rhsa;
									}
								}
							}
							solverOut = hkAddByteOffset( solverOut, solverResultStriding * 6 );
							solverIn += 6;
							j1Lin2AngInChain += 3;
							j2AngInChain += 3;
						}
					}
					else
					{
						solverIn += 6 * chain->m_numConstraints;
					}
					com = hkAddByteOffsetConst( com, chain->m_size );
					break;
				}
			case hkpJacobianSchema::SCHEMA_TYPE_END:
				hkpImpulseLimitBreachedHeader* h;
				h = reinterpret_cast<hkpImpulseLimitBreachedHeader*>( const_cast<hkpJacobianSchema*>( schemas ) );
				h->m_numBreached = numImpulseLimitsBreached;
				return;
			default:
				;
		}
	}
}

}  // namespace f3m_00a77a70
}   // namespace f3m_00a77a70

// @f3 0x00a68e30 (community match, verified in this file)
namespace f3m_00a68e30 {
// 0x00a68e30: appends the six face planes of a shape's AABB to an array of plane equations.
// /O2 gives this static function a private convention: the shape arrives in ecx, the array in edi,
// and the AABB tolerance on the stack.

struct Vec4 { float x,y,z,w; };
struct __declspec(align(16)) Aabb { Vec4 minimum,maximum; };
struct Transform { float rotation[9]; float translation[3]; };
namespace g2403 { extern const Transform DAT_010f3370; }

struct Shape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void GetAabb(const Transform& transform,float tolerance,Aabb& result) const;
};

namespace g2403 { void __cdecl FUN_00901e90(void* array,int capacity,int elementBytes); }

template<class T> struct Array {
    T* data;
    int size;
    unsigned int capacityFlags;
    __forceinline int Capacity() const {return capacityFlags&0x3fffffffu;}
    __forceinline void Reserve(int needed) {
        int capacity=Capacity();
        if (capacity<needed) {
            int grown=capacity*2;
            int target=(needed<grown)?grown:needed;
            g2403::FUN_00901e90(this,target,sizeof(T));
        }
    }
    __forceinline void Resize(int count) {Reserve(count);size=count;}
};

__forceinline void SetPlane(Vec4& plane,float x,float y,float z,float w)
{
    plane.x = x;
    plane.y = y;
    plane.z = z;
    plane.w = w;
}

// pdb: hkpUserConvexRadiusBuilder::registerUserConvexRadiusDisplayBuilder | hkpConvexRadiusBuilder.obj | fnv360_0822_debug, objrun, low, conflict (bridge: _addBoundingPlanes)
// pdb params: f, type
static __declspec(noinline) void FUN_00a68e30(Shape* shape,Array<Vec4>* planes,float tolerance)
{
    Aabb bounds;
    shape->GetAabb(g2403::DAT_010f3370,tolerance,bounds);
    int count = planes->size + 6;
    planes->Resize(count);
    SetPlane(planes->data[count-6],1.0f,0.0f,0.0f,-bounds.maximum.x);
    SetPlane(planes->data[count-5],0.0f,1.0f,0.0f,-bounds.maximum.y);
    SetPlane(planes->data[count-4],0.0f,0.0f,1.0f,-bounds.maximum.z);
    SetPlane(planes->data[count-3],-1.0f,0.0f,0.0f,bounds.minimum.x);
    SetPlane(planes->data[count-2],0.0f,-1.0f,0.0f,bounds.minimum.y);
    SetPlane(planes->data[count-1],0.0f,0.0f,-1.0f,bounds.minimum.z);
}

volatile Shape* g_shape00a68e30;
volatile Array<Vec4>* g_planes00a68e30;
volatile float g_tolerance00a68e30;
void FUN_00a68e30_caller()
{
    FUN_00a68e30((Shape*)g_shape00a68e30,(Array<Vec4>*)g_planes00a68e30,g_tolerance00a68e30);
}
}   // namespace f3m_00a68e30
