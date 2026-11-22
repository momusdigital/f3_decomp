// src/f3staging/f3blk_00960000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0097a770 (community match, verified in this file)
extern const char DAT_00e7d118[],DAT_00e7d104[],DAT_00e7d0e8[],DAT_00e7d0d0[];
extern const char DAT_00e7d0b8[],DAT_00e7d0a4[],DAT_00e7d088[],DAT_00e7d074[];
extern const char DAT_00e7d060[],DAT_00e7d048[],DAT_00e7d030[],DAT_00e0398c[];
namespace f3m_0097a770 {
namespace creator_names_1617 {
// pdb: bhkConstraintManager::GetTypeName | bhkConstraintManager.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
const char* __cdecl bhkConstraintManager_GetTypeName(unsigned int kind) {
    switch(kind) {
    case 0: return DAT_00e7d118;
    case 1: return DAT_00e7d104;
    case 2: return DAT_00e7d0e8;
    case 3: return DAT_00e7d0d0;
    case 6: return DAT_00e7d0b8;
    case 7: return DAT_00e7d0a4;
    case 8: return DAT_00e7d088;
    case 9: return DAT_00e7d074;
    case 10: return DAT_00e7d060;
    case 12: return DAT_00e7d048;
    case 13: return DAT_00e7d030;
    default: return DAT_00e0398c;
    }
}
}
}   // namespace f3m_0097a770

// @f3 0x00978100 (community match, verified in this file)
#include <intrin.h>
extern double FUN_00db38b0;
namespace f3m_00978100 {

struct S {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float t0, t1, t2, t3;
    float n0, n1, n2, n3;
    float p0, p1, p2, p3;
    float q0, q1, q2, q3;
    float r0, r1, r2, r3;
    float u80, u84, u88, u8c;
    float u90, u94, u98, u9c;
};

// pdb: hkSweptTransformUtil::warpToPosition | hkSweptTransformUtil.obj | tesv_win, objrun, medium
void FUN_00978100(float* a, S* s)
{
    s->u9c = 0.0f;
    s->u98 = 0.0f;
    s->u94 = 0.0f;
    s->u90 = 0.0f;

    s->t0 = a[0];
    s->t1 = a[1];
    s->t2 = a[2];
    s->t3 = a[3];

    float vx = s->u80;
    float vy = s->u84;
    float vz = s->u88;

    __declspec(align(16)) float m[4];
    m[0] = s->m00 * vx + s->m10 * vy + s->m20 * vz;
    m[1] = s->m01 * vx + s->m11 * vy + s->m21 * vz;
    m[2] = s->m02 * vx + s->m12 * vy + s->m22 * vz;

    float oldw = s->n3;

    s->n0 = a[0] + m[0];
    s->n1 = *(volatile float*)&a[1] + m[1];
    s->n2 = a[2] + m[2];
    _ReadWriteBarrier();
    s->n3 = (float)(a[3] + FUN_00db38b0);

    s->p0 = s->n0;
    s->p1 = s->n1;
    s->p2 = s->n2;
    s->p3 = s->n3;

    _ReadWriteBarrier();
    s->q0 = s->r0;
    s->q1 = s->r1;
    s->q2 = s->r2;
    s->q3 = s->r3;

    s->n3 = oldw;
    s->p3 = 0.0f;
}
}   // namespace f3m_00978100

// @f3 0x0097e3f0 (community match, verified in this file)
namespace f3m_0097e3f0 {
struct Vector97e3 {
    __declspec(align(16)) float x; float y, z, w;
    Vector97e3() {}
    Vector97e3(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    Vector97e3 operator-(const Vector97e3& o) const { return Vector97e3(x - o.x, y - o.y, z - o.z, w - o.w); }
    float LengthSqr() const { return x * x + y * y + z * z + w * w; }
};

static __declspec(noinline) float FUN_0097e3f0(const Vector97e3* a, const Vector97e3* b)
{
    Vector97e3 delta = *a - *b;
    return delta.LengthSqr();
}

volatile Vector97e3* g_a97e3;
volatile Vector97e3* g_b97e3;
volatile float g_out97e3;
void caller_of_FUN_0097e3f0() { g_out97e3 = FUN_0097e3f0((const Vector97e3*)g_a97e3, (const Vector97e3*)g_b97e3); }
}   // namespace f3m_0097e3f0

// @f3 0x0096cd80 (community match, verified in this file)
namespace f3m_0096cd80 {
// 0x0096cd80: hkMatrix3_setMulMat3Mat3(hkMatrix3* THIS, const hkMatrix3& aTb, const hkMatrix3& bTc) of Havok 5.5.0
// (hkBase, the C function behind hkMatrix3::setMul, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// THIS = aTb * bTc: each column of bTc is rotated by a copy of aTb, the last column first; the copy makes it safe
// for the result to be bTc itself.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (vector, matrix, the rotate-points
// loop) follow the SDK's inline maths for the x87 build. The parameter names and the single statement are those of
// the SDK's unoptimized library object of this function (its assert compiles out in the release build).
namespace f3m_0096cd80 {

typedef float hkReal;

struct hkMatrix3;

struct hkVector4
{
    __forceinline hkVector4() {}

    __forceinline void operator=(const hkVector4& v);
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void _setMul3(const hkMatrix3& r, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkMatrix3
{
    __forceinline hkMatrix3() {}
    __forceinline hkMatrix3(const hkMatrix3& other);

    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

__forceinline hkMatrix3::hkMatrix3(const hkMatrix3& other)
{
    m_col0 = other.m_col0;
    m_col1 = other.m_col1;
    m_col2 = other.m_col2;
}

namespace hkVector4Util {
// rotates numVectors directions, the last one first; the matrix is copied so that the output may alias it
__forceinline void rotatePoints(const hkMatrix3& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkMatrix3 unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setMul3(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

// pdb: hk1dAngularBilateralConstraintBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low, conflict (bridge: hkMatrix3_setMulMat3Mat3)
// pdb params: info, in, out
void __cdecl FUN_0096cd80(hkMatrix3* THIS, const hkMatrix3& aTb, const hkMatrix3& bTc)
{
    hkVector4Util::rotatePoints(aTb, &bTc.getColumn(0), 3, &THIS->getColumn(0));
}

}  // namespace f3m_0096cd80
}   // namespace f3m_0096cd80

// @f3 0x0097b1f0 (community match, verified in this file)
namespace f3m_0097b1f0 {
namespace f3m_0097b1f0 {

typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef void* hk_va_list;
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
struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};
class hkVector4Comparison;
extern "C" {
double  __cdecl sqrt(     double _X);
inline float sqrtf(     float _X)
        {return ((float)sqrt((double)_X)); }
}
namespace hkMath
{
inline hkReal __cdecl sqrt(hkReal r) { return sqrtf(r); }
inline int __cdecl hkToIntFast( hkReal r )
	{
		int i = fnv_FloatToInt( r );
		return i;
	}
}
extern const hkQuadReal hkQuadReal0000;
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
class hkQsTransform
{
	public:
		enum IdentityInitializer
		{
			IDENTITY,
		};
		enum ZeroInitializer
		{
			ZERO,
		};
		__forceinline hkQsTransform() { }
		__forceinline hkQsTransform(IdentityInitializer init);
		__forceinline hkQsTransform(ZeroInitializer init);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline hkQsTransform(const hkVector4& translation, const hkQuaternion& rotation);
		__forceinline hkQsTransform(const hkQsTransform& other);
		__forceinline void set(const hkVector4& translation, const hkQuaternion& rotation, const hkVector4& scale);
		__forceinline void setIdentity();
		__forceinline static const hkQsTransform& __cdecl getIdentity();
		__forceinline const hkVector4& getTranslation() const;
		__forceinline void setTranslation(const hkVector4& t);
		__forceinline const hkVector4& getScale() const;
		__forceinline void setScale(const hkVector4& s);
		__forceinline const hkQuaternion& getRotation() const;
		__forceinline void setRotation(const hkQuaternion& rotation);
		__forceinline void setRotation(const hkRotation& rotation);
		__forceinline void setInterpolate4( const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
		void setFromTransformNoScale (const hkTransform& transform);
		void copyToTransformNoScale (hkTransform& transformOut) const;
		void setFromTransform (const hkTransform& transform);
		void copyToTransform (hkTransform& transformOut) const;
		__forceinline void setInverse( const hkQsTransform &t );
		__forceinline void setMul( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulInverseMul( const hkQsTransform& t1, const hkQsTransform &t2 );
		__forceinline void setMulMulInverse( const hkQsTransform &t1, const hkQsTransform &t2 );
		__forceinline void setMulEq( const hkQsTransform& b );
		void get4x4ColumnMajor(hkReal* p) const;
		hkBool set4x4ColumnMajor(const hkReal* p);
		hkBool isOk() const;
		hkBool isApproximatelyEqual( const hkQsTransform& other, hkReal epsilon=1e-3f ) const;
		__forceinline void setZero();
		__forceinline void blendAddMul(const hkQsTransform& other,  hkSimdRealParameter weight = 1.0f );
		__forceinline void blendNormalize( hkSimdRealParameter totalWeight = 1.0f);
		__forceinline void fastRenormalize( hkSimdRealParameter totalWeight = 1.0f);
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
		hkQuaternion m_rotation;
		hkVector4 m_scale;
};
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::operator= (const hkQuadReal& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
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
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::setAll(hkReal a)
{
	(*this)(0) = a;
	(*this)(1) = a;
	(*this)(2) = a;
	(*this)(3) = a;
}
inline void hkVector4::add4(const hkVector4& v)
{
	for (int i = 0; i < 4; i++)
	{
		(&x)[i] += (&v.x)[i];
	}
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
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
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	(*this)(0) *= s;
	(*this)(1) *= s;
	(*this)(2) *= s;
	(*this)(3) *= s;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	(*this)(0) += r * a(0);
	(*this)(1) += r * a(1);
	(*this)(2) += r * a(2);
	(*this)(3) += r * a(3);
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter rt)
{
	hkReal t = hkReal(rt);
	hkReal s = 1.0f - t;
	hkVector4& d = *this;
	d(0) = s * v0(0) + t * v1(0);
	d(1) = s * v0(1) + t * v1(1);
	d(2) = s * v0(2) + t * v1(2);
	d(3) = s * v0(3) + t * v1(3);
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x < b.x ? a.x : b.x;
		y = a.y < b.y ? a.y : b.y;
		z = a.z < b.z ? a.z : b.z;
		w = a.w < b.w ? a.w : b.w;
	}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
	{
		x = a.x > b.x ? a.x : b.x;
		y = a.y > b.y ? a.y : b.y;
		z = a.z > b.z ? a.z : b.z;
		w = a.w > b.w ? a.w : b.w;
	}
inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
	{
        hkReal inputXYZ[3] = {v.getSimdAt(0), v.getSimdAt(1), v.getSimdAt(2)};
		hkVector4& d = *this;
		d(0) = (t(0,0)*inputXYZ[0] + t(0,1)*inputXYZ[1] + t(0,2)*inputXYZ[2]) + t(0,3);
		d(1) = (t(1,0)*inputXYZ[0] + t(1,1)*inputXYZ[1] + t(1,2)*inputXYZ[2]) + t(1,3);
		d(2) = (t(2,0)*inputXYZ[0] + t(2,1)*inputXYZ[1] + t(2,2)*inputXYZ[2]) + t(2,3);
		d(3) = 0;
	}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt(x * x + y * y + z * z);
	}
inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkQuadReal* q = &hkQuadReal0000;
	const hkVector4* v = reinterpret_cast<const hkVector4*>(q);
	const hkVector4& zero = *v;
	return zero;
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkVector4& hkTransform::getTranslation() const
{
	return m_translation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
class hkString
{
	public:
	public:
		__forceinline hkString();
		__forceinline hkString(const char* s);
		__forceinline hkString(const char* b, int len);
		__forceinline hkString(const hkString& s);
	private:
		hkString(char* ptr, int size, int capacity);
		__forceinline	void setLength( int length );
	public:
		__forceinline hkString& operator=(const hkString& s);
		__forceinline hkString& operator=(const char* s);
		__forceinline ~hkString();
		__forceinline char operator[] (int i) const;
		__forceinline void setCapacity(int capacity);
		__forceinline int getCapacity() const;
		void printf(const char* format, ...);
		int indexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		int lastIndexOf (char c, int startIndex=0, int endIndex=2147483647) const;
		__forceinline const char* cString() const;
		int compareTo(const hkString& other) const;
		int compareTo(const char* other) const;
		int compareToIgnoreCase(const hkString& other) const;
		int compareToIgnoreCase(const char* other) const;
		__forceinline hkBool operator< (const hkString& s) const;
		__forceinline hkBool operator== (const hkString& s) const;
		__forceinline hkBool operator!= (const hkString& s) const;
		__forceinline hkBool operator== (const char* s) const;
		__forceinline hkBool operator!= (const char* s) const;
		__forceinline hkBool beginsWith(const hkString& s) const;
		hkBool beginsWith(const char* s) const;
		hkBool endsWith(const hkString& s) const;
		hkBool endsWith(const char* s) const;
		hkString operator+ (const hkString& other) const;
		hkString operator+ (const char* other) const;
		hkString& operator+= (const hkString& other);
		hkString& operator+= (const char* other);
		int getLength() const;
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
		hkString replace(char from, char to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(char from, char to, ReplaceType=REPLACE_ALL);
		hkString replace(const hkString& from, const hkString& to, ReplaceType=REPLACE_ALL) const;
		hkBool replaceInplace(const hkString& from, const hkString& to, hkString::ReplaceType rtype=REPLACE_ALL);
		hkString asUpperCase() const;
		void makeUpperCase();
		hkString asLowerCase() const;
		void makeLowerCase();
		__forceinline hkString substr(int index, int maxChars=2147483647) const;
		__forceinline void setAsSubstr(int index, int maxChars=2147483647);
	private:
		hkArray<char> m_string;
	public:
		static char __cdecl toUpper( char c );
		static char __cdecl toLower( char c );
		static int __cdecl snprintf(char* buf, int n, const char* fmt, ...);
		static int __cdecl vsnprintf(char* buf, int len, const char* fmt, hk_va_list hkargs);
		static int __cdecl sprintf(char* buf, const char* fmt, ...);
		static int __cdecl strCmp(const char* s1, const char* s2 );
		static int __cdecl strNcmp(const char* s1, const char* s2, int n);
		static int __cdecl strCasecmp(const char* s1, const char* s2 );
		static int __cdecl strNcasecmp(const char* s1, const char* s2, int n);
		static void __cdecl strCpy(char* dst, const char* src);
		static void __cdecl strNcpy(char* dst, const char* src, int n);
		static int __cdecl strLen(const char* src);
		static int __cdecl atoi(const char* in);
		static hkReal __cdecl atof(const char* in);
		static const char* __cdecl strStr(const char* haystack, const char* needle);
		static hkBool findAllOccurrences(const char* haystack, const char* needle, hkArray<int>& indices, hkString::ReplaceType rtype);
		static const char* __cdecl strChr(const char* haystack, int needle);
		static const char* __cdecl strRchr(const char* haystack, int needle);
		static char* __cdecl strDup(const char* src);
		static char* __cdecl strNdup(const char* src, int maxlen);
		static char* __cdecl strLwr(char* src);
		static char* __cdecl strUpr(char* src);
		static void __cdecl memCpy(void* dst, const void* src, int n);
		static __forceinline void __cdecl memCpy4(void* dst, const void* src, int numWords);
		static __forceinline void __cdecl memCpy16(void* dst, const void* src, int numQuads);
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
		static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
		static __forceinline void __cdecl memCpy128(void* dst, const void* src);
		static __forceinline void __cdecl memCpy256(void* dst, const void* src);
		static void __cdecl memMove(void* dst, const void* src, int n);
		static void __cdecl memSet(void* dst, const int c, int nBytes);
		static __forceinline void __cdecl memSet4(void* dst, const int value, int numWords);
		static __forceinline void __cdecl memClear16(void* dst, int numQuads);
		static __forceinline void __cdecl memSet16(void* dst, const void* value, int numQuads);
		static int __cdecl memCmp(const void* buf1, const void* buf2, int n);
private:
		static void copyAndReplace( char* dest, const char* orig, int origLen, const hkString& from, const hkString& to, const hkArray<int>& indices);
};
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
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
	return m_sweptTransform;
}
class hkAabb
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkAabb() { }
		__forceinline hkAabb(const hkVector4& min, const hkVector4& max);
		__forceinline hkBool overlaps( const hkAabb& testAabb ) const;
		hkBool isValid() const;
		__forceinline hkBool contains(const hkAabb& other) const;
		__forceinline hkBool containsPoint(const hkVector4& other) const;
		__forceinline void includePoint (const hkVector4& point);
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
struct hkAabbUint32
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	inline void operator=( const hkAabbUint32& other );
	inline void setInvalid();
	inline void setInvalidY();
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};
void hkAabb::setEmpty()
{
	m_min.setAll(3.40282e+38f);
	m_max.setAll(-3.40282e+38f);
}
class hkSphere;
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
		hkEnum< hkpShapeType, hkUint32> m_type;
	public:
		hkpShape( class hkFinishLoadedObjectFlag flag ) { m_type = HK_SHAPE_INVALID; }
};
void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}
class hkpCollisionDispatcher;
class hkpShapeCollectionFilter;
class hkpConvexListFilter;
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
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual hkpShapeKey getFirstKey() const = 0;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const = 0;
		virtual hkUint32 getCollisionFilterInfo( hkpShapeKey key ) const;
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const = 0;
		virtual hkBool32 isChildEnabled( hkpShapeKey key ) const { return true; }
		virtual bool isWeldingEnabled() const { return true; }
};
class hkpAabbUtil
{
	public:
		static void __cdecl calcAabb( const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut );
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, const hkVector4& center, float extraRadius, hkAabb& aabbOut);
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, float extraRadius, hkAabb& aabbOut);
	public:
		struct OffsetAabbInput
		{
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
		__forceinline static void __cdecl sweepAabb(const hkMotionState* motionstate, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut);
		static void __cdecl initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};
__forceinline void __cdecl hkpAabbUtil::sweepOffsetAabb(const hkpAabbUtil::OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut)
{
	hkSimdReal half(0.5f);
	hkVector4 aabbHalfSize; aabbHalfSize.setSub4(aabbIn.m_max, aabbIn.m_min);  aabbHalfSize.mul4(half);
	hkVector4 aabbCenter; aabbCenter.setInterpolate4(aabbIn.m_max, aabbIn.m_min, half);
	hkVector4 arm; arm._setTransformedPos(input.m_endTransformInv, aabbCenter);
	hkVector4 min = aabbCenter;
	hkVector4 max = aabbCenter;
	{
		hkVector4 p; p._setTransformedPos(input.m_startTransform, arm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	const hkVector4 centerOfMassLocal = input.m_motionState->getSweptTransform().m_centerOfMassLocal;
	for (int i = 0; i < input.m_numTransforms; i++)
	{
		hkVector4 extendedArm;
		extendedArm.setSub4(arm, centerOfMassLocal);
		extendedArm.mul4(input.m_transforms[i].getTranslation().getSimdAt(3));
		extendedArm.add4(centerOfMassLocal);
		hkVector4 p; p._setTransformedPos(input.m_transforms[i], extendedArm);
		min.setMin4(min, p);
		max.setMax4(max, p);
	}
	{
		hkSimdReal r = aabbHalfSize.length3();
		hkVector4 radius; radius.setAll(r);
		aabbHalfSize.addMul4(input.m_motionState->m_deltaAngle.getSimdAt(3), radius);
		aabbHalfSize.setMin4(radius, aabbHalfSize);
	}
	aabbOut.m_min.setSub4(min, aabbHalfSize);
	aabbOut.m_max.setAdd4(max, aabbHalfSize);
	aabbOut.m_min.setMin4(aabbIn.m_min, aabbOut.m_min);
	aabbOut.m_max.setMax4(aabbIn.m_max, aabbOut.m_max);
}
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpShapeCollection( hkpShapeType type );
		hkpShapeCollection( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_COLLECTION; }
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
 		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		__forceinline bool isWeldingEnabled() const { return !m_disableWelding; }
		void FUN_0097b1f0( const hkpCollisionInput& collisionInput, const hkpAabbUtil::OffsetAabbInput& input, const hkTransform& localToWorld, const hkVector4& position, hkReal tolerance, hkAabbUint32& rootAabbOut, hkAabbUint32* childAabbs, int numChildAabbs ) const;
	public:
		hkBool m_disableWelding;
};
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out);
__forceinline void __cdecl convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
extern __declspec(align(16)) float hkAabbUint32MaxVal[4];
}
inline void __cdecl hkVector4Util::convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	out[0] = static_cast<hkUint32>(hkMath::hkToIntFast(x(0)));
	out[1] = static_cast<hkUint32>(hkMath::hkToIntFast(x(1)));
	out[2] = static_cast<hkUint32>(hkMath::hkToIntFast(x(2)));
	out[3] = static_cast<hkUint32>(hkMath::hkToIntFast(x(3)));
}
inline void __cdecl hkVector4Util::convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{

    hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&hkVector4Util::hkAabbUint32MaxVal));
    hkVector4Util::convertToUint32WithClip( aabb.m_min, offsetLow,  scale, hkVector4::getZero(), maxVal, aabbOut.m_min );
    hkVector4Util::convertToUint32WithClip( aabb.m_max, offsetHigh, scale, hkVector4::getZero(), maxVal, aabbOut.m_max );
}
inline void hkAabbUint32::setInvalid()
{
	m_min[0] = 0x7fffffff;
	m_min[1] = 0x7fffffff;
	m_min[2] = 0x7fffffff;
	*((int*)&m_expansionMin[0]) = 0;
	m_max[0] = 0;
	m_max[1] = 0;
	m_max[2] = 0;
	*((int*)&m_expansionMax[0]) = 0;
}
__forceinline void __cdecl compressExpandedAabbUint32( const hkAabbUint32& expandedAabbInt, hkAabbUint32& unexpandedAabbInt_InOut )
{
	int expanded0 = unexpandedAabbInt_InOut.m_min[0] - expandedAabbInt.m_min[0];
	int expanded1 = unexpandedAabbInt_InOut.m_min[1] - expandedAabbInt.m_min[1];
	int expanded2 = unexpandedAabbInt_InOut.m_min[2] - expandedAabbInt.m_min[2];
	int mix = expanded0 | expanded1 | expanded2;
	int expanded3 = expandedAabbInt.m_max[0] - unexpandedAabbInt_InOut.m_max[0];
	int expanded4 = expandedAabbInt.m_max[1] - unexpandedAabbInt_InOut.m_max[1];
	int expanded5 = expandedAabbInt.m_max[2] - unexpandedAabbInt_InOut.m_max[2];
	mix |= expanded3 | expanded4 | expanded5;
	int shift = 0;
	while ( mix >= 0x800 ) { shift += 4; mix = hkUint32(mix) >> 4; }
	while ( mix >= 0x100 ) { shift += 1; mix = hkUint32(mix) >> 1; }
	unexpandedAabbInt_InOut.m_expansionShift = hkUchar(shift);
	unexpandedAabbInt_InOut.m_expansionMin[0] = hkUchar(expanded0 >> shift);
	unexpandedAabbInt_InOut.m_expansionMin[1] = hkUchar(expanded1 >> shift);
	unexpandedAabbInt_InOut.m_expansionMin[2] = hkUchar(expanded2 >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[0] = hkUchar(expanded3 >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[1] = hkUchar(expanded4 >> shift);
	unexpandedAabbInt_InOut.m_expansionMax[2] = hkUchar(expanded5 >> shift);
}
void hkpShapeCollection::FUN_0097b1f0( const hkpCollisionInput& collisionInput, const hkpAabbUtil::OffsetAabbInput& input, const hkTransform& localToWorld, const hkVector4& position, hkReal tolerance, hkAabbUint32& rootAabbOut, hkAabbUint32* childAabbs, int numChildAabbs ) const
{
hkAabb rootAabb;
rootAabb.m_min = position;
rootAabb.m_max = position;
hkAabb expandedRootAabb = rootAabb;
for ( hkpShapeKey key = getFirstKey(); key != 0xffffffff; childAabbs++, key = getNextKey( key ) )
{
if ( !isChildEnabled( key ) )
{
childAabbs->setInvalid();
continue;
}
ShapeBuffer buffer;
hkAabb aabb;
getChildShape( key, buffer )->getAabb( localToWorld, tolerance, aabb );
hkAabb expandedAabb;
hkpAabbUtil::sweepOffsetAabb( input, aabb, expandedAabb );
(void)aabb.m_max.getSimdAt(0); // Guess: an unused read of the child max x lane; it sets which operand of the first max-lane add in the conversion loads first
rootAabb.m_min.setMin4( rootAabb.m_min, aabb.m_min );
rootAabb.m_max.setMax4( rootAabb.m_max, aabb.m_max );
expandedRootAabb.m_min.setMin4( expandedRootAabb.m_min, expandedAabb.m_min );
expandedRootAabb.m_max.setMax4( expandedRootAabb.m_max, expandedAabb.m_max );
const hkpCollisionInput::Aabb32Info& info = collisionInput.m_aabb32Info;
hkAabbUint32& childAabb = *childAabbs;
hkVector4Util::convertAabbToUint32( aabb, collisionInput.m_aabb32Info.m_bitOffsetLow, collisionInput.m_aabb32Info.m_bitOffsetHigh, collisionInput.m_aabb32Info.m_bitScale, childAabb );
hkAabbUint32 expandedAabbInt;
const hkAabb& sweptBounds = expandedAabb;
hkVector4Util::convertAabbToUint32( sweptBounds, info.m_bitOffsetLow, info.m_bitOffsetHigh, info.m_bitScale, expandedAabbInt );
compressExpandedAabbUint32( expandedAabbInt, childAabb );
}
const hkpCollisionInput::Aabb32Info& info = collisionInput.m_aabb32Info;
hkVector4Util::convertAabbToUint32( rootAabb, collisionInput.m_aabb32Info.m_bitOffsetLow, collisionInput.m_aabb32Info.m_bitOffsetHigh, collisionInput.m_aabb32Info.m_bitScale, rootAabbOut );
hkAabbUint32 expandedRootAabbInt;
hkVector4Util::convertAabbToUint32( expandedRootAabb, info.m_bitOffsetLow, info.m_bitOffsetHigh, info.m_bitScale, expandedRootAabbInt );
compressExpandedAabbUint32( expandedRootAabbInt, rootAabbOut );
}
}

}   // namespace f3m_0097b1f0
