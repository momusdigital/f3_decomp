#include <new>
// src/f3staging/f3iso_009cfcf0_od.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009cfcf0 alone: its verified match did not fit its original file.
// Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009cfcf0 (community match, verified in this file)
#include <math.h>
// FUN_009cfcf0 = Havok 5.5.0 hkpCollectionCollectionAgent3::process (hkpInternal.lib, hkpCollectionCollectionAgent3.obj)
// as the game links it. REWRITTEN from the SDK debug records (hybrid + release line records, locals, blocks; the .cpp is
// not shipped) on the SDK headers: the SDK form (sdk_source.cpp) is a library MATCH (process 4850, inlined calcAabbs 2780,
// static extract 3597); cut with tools\hktrim.py and wrapped (mkgame.py). Game build differences, see w4\note.txt: maxVal copy in
// convertAabbToUint32 (game bytes); its zero argument is a hkVector4 global passed directly (g_vZero), and
// convertToUint32WithClip calls fnv_FloatToInt (pack helper) directly: both as in the verified FUN_00991450 text
// (work\9841b0 pack unit); name g_vZero from the New Vegas twin's getZero. All hkVector4 bodies are the SDK's.
namespace f3m_009cfcf0 {
class hkpCollidable;
// void * hkpCollectionCollectionAgent3::FUN_009cfcf0(struct hkpAgent3ProcessInput const &,struct hkpAgentEntry *,void *,class hkVector4 *,struct hkpProcessCollisionOutput &)  (?process@hkpCollectionCollectionAgent3@@YAPAXABUhkpAgent3ProcessInput@@PAUhkpAgentEntry@@PAXPAVhkVector4@@AAUhkpProcessCollisionOutput@@@Z; Havok 5.5.0 hkpInternal.lib / hkpCollectionCollectionAgent3.obj)
// reduced by hktrim.py from sdk_source.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
typedef signed char		hkChar;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
typedef hkReal hkTime;

template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}

class hkClass;
typedef int hkBool32;

class hkBool
{
	public:
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
	public:
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
		__forceinline void* allocateStack(int nbytes);
		__forceinline void shrinkAllocatedStack(void* ptr, int newSize);
		__forceinline void deallocateStack(void* p);
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

template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);

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
		                class MustEndWithSemiColon;
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
		__forceinline int getSize() const;
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

template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}

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


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
}

extern const hkQuadReal hkQuadReal0000;
extern hkVector4 g_vZero;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void setAll(hkReal x);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal length3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline static const hkVector4& __cdecl getZero();
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkQuaternion
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};

class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
};

class hkTransform
{
	public:
		                class MustEndWithSemiColon;
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkVector4& getTranslation() const;
		void setInverse( const hkTransform &t );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

class hkSweptTransform
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
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

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}

inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
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
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
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

inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w =  v.w;
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
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(0,1)*v1 + t(0,2)*v2 + t(0,3);
		d(1) = t(1,0)*v0 + t(1,1)*v1 + t(1,2)*v2 + t(1,3);
		d(2) = t(2,0)*v0 + t(2,1)*v1 + t(2,2)*v2 + t(2,3);
		d(3) = 0;
	}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&hkQuadReal0000);
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
		                class MustEndWithSemiColon;
	public:
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};
	private:
		hkArray<char> m_string;
	public:
		template<int size>
		static __forceinline void __cdecl memCpy16(void* dst, const void* src);
};

void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}

void hkThreadMemory::shrinkAllocatedStack(void* ptr, int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	m_stack.m_current = static_cast<char*>(ptr) + actualBytes;
}

void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}

template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}

template <typename TYPE>
__forceinline void __cdecl hkShrinkAllocatedStack(TYPE* ptr, int newSize )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	mem.shrinkAllocatedStack(ptr, newSize*int(sizeof(TYPE)));
}

template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void setEmpty ();
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

void hkAabb::setEmpty()
{
	m_min.setAll(3.40282e+38f);
	m_max.setAll(-3.40282e+38f);
}

struct hkAabbUint32
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	__declspec(align(16)) hkUint32 m_min[3];
	hkUchar m_expansionMin[3];
	hkUchar m_expansionShift;
	hkUint32 m_max[3];
	hkUchar m_expansionMax[3];
	hkUchar m_sortIndex;
};

class hkSphere
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		hkVector4 m_pos;
};

typedef hkUint16 hkContactPointId;

class hkpCdVertex: public hkVector4
{
	public:
		                class MustEndWithSemiColon;
};

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

class hkpCollisionDispatcher;
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
		                class MustEndWithSemiColon;
		__forceinline hkpShapeType getType() const;
		__forceinline void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			                class MustEndWithSemiColon;
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
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
				                class MustEndWithSemiColon;
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
				                class MustEndWithSemiColon;
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
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

__declspec(align(16)) class hkAlignedShape: public hkpShape{
};

hkpShapeType hkpShape::getType() const
{
	return static_cast<const hkAlignedShape*>(this)->m_type;
}

void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
}

class hkMotionState;

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
		__forceinline const hkpCollidable* getRootCollidable() const;
		__forceinline const hkpCdBody* getParent() const;
	public:
		__forceinline const hkMotionState* getMotionState() const;
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}

const hkpCdBody* hkpCdBody::getParent() const
{
	return m_parent;
}

const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}

const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}

const hkpCollidable* hkpCdBody::getRootCollidable() const
{
	const hkpCdBody* body = this;
	while( body->m_parent )
	{
		body = body->m_parent;
	}
	return reinterpret_cast<const hkpCollidable*>(body);
}

struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
class hkpConstraintOwner;
struct hkpCollisionInput;
class hkpCollisionAgent;

struct hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
};

typedef void hkpAgentData;

struct hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform		m_aTb;
};

struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<hkReal>          m_distAtT1;
	hkPadSpu<int>		m_offsetPpuSectorMinusSpuSector;
	hkVector4       m_linearTimInfo;
};

namespace hkAgent3
{
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
	                class MustEndWithSemiColon;
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
};

class hkpShapeCollectionFilter;
class hkpConvexListFilter;
struct hkpCollisionAgentConfig;

struct hkpCollisionInput
{
		                class MustEndWithSemiColon;
	public:
		hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
		hkPadSpu<hkReal> m_tolerance;
		hkPadSpu<const hkpShapeCollectionFilter*> m_filter;
		hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
		mutable hkPadSpu<hkBool32> m_createPredictiveAgents;
		struct Aabb32Info
		{
			                class MustEndWithSemiColon;
			hkVector4 m_bitOffsetLow;
			hkVector4 m_bitOffsetHigh;
			hkVector4 m_bitScale;
		};
		Aabb32Info m_aabb32Info;
};

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
		                class MustEndWithSemiColon;
		typedef hkpCollisionAgent* (__cdecl *CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& env, hkpContactMgr* mgr);
		typedef void (__cdecl *GetPenetrationsFunc)     (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		typedef void (__cdecl *GetClosestPointsFunc)   (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& output );
		typedef void (__cdecl *LinearCastFunc)         (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector );
		typedef CreateFunc CollisionAgentCreationFunction;
		typedef hkChar CollisionQualityIndex;
		struct AgentFuncs
		{
			                class MustEndWithSemiColon;
			CreateFunc           m_createFunc;
			GetPenetrationsFunc  m_getPenetrationsFunc;
			GetClosestPointsFunc m_getClosestPointFunc;
			LinearCastFunc       m_linearCastFunc;
			hkBool				 m_isFlipped;
			hkBool				 m_isPredictive;
		};
		struct Agent3Funcs
		{
			                class MustEndWithSemiColon;
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
			                class MustEndWithSemiColon;
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
		~hkpCollisionDispatcher();
		inline hkBool32 hasAlternateType( hkpShapeType type, hkpShapeType alternateType );
		void calcStatistics( hkStatisticsCollector* collector ) const;
	public:
		struct ShapeInheritance
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_primaryType;
			hkpShapeType m_alternateType;
		};
		struct AgentEntry
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			AgentFuncs  m_createFunc;
		};
		struct Agent3Entry
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			Agent3Funcs  m_funcs;
		};
		struct Agent3FuncsIntern: public Agent3Funcs
		{
			                class MustEndWithSemiColon;
			hkAgent3::Symmetric       m_symmetric;
		};
		struct DebugEntry
		{
			                class MustEndWithSemiColon;
			char m_typeA;
			char m_typeB;
			char m_priority;
		};
		typedef DebugEntry	DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
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

hkBool32 hkpCollisionDispatcher::hasAlternateType( hkpShapeType type, hkpShapeType alternateType )
{
	;
	;
	return ( m_hasAlternateType[type] & (1<<alternateType) );
}

class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		hkUint32 m_id;
};

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	protected:
		enum { OFFSET_INVALID = 127 };
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};

class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				                class MustEndWithSemiColon;
				__forceinline bool isValid() const { return m_min[0] <= m_max[0]; }
			public:
				hkUint32		m_min[3];
				hkUint8			m_expansionMin[3];
				hkUint8			m_expansionShift;
				hkUint32		m_max[3];
				hkUint8			m_expansionMax[3];
				hkUint8			m_padding;
				hkUint16		m_numChildShapeAabbs;
				hkAabbUint32*	m_childShapeAabbs;
		};
		enum ForceCollideOntoPpuReasons
		{
			FORCE_PPU_USER_REQUEST = 1,
			FORCE_PPU_SHAPE_REQUEST = 2,
			FORCE_PPU_MODIFIER_REQUEST = 4,
		};
	protected:
		hkInt8 m_ownerOffset;
	public:
		hkUint8   m_forceCollideOntoPpu;
		hkUint16 m_shapeSizeOnSpu;
		class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	public:
		struct BoundingVolumeData m_boundingVolumeData;
		hkReal m_allowedPenetrationDepth;
};

class hkMotionState
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline const hkSweptTransform& getSweptTransform() const;
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

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
 		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual const hkpShapeContainer* getContainer() const;
		__forceinline bool isWeldingEnabled() const { return !m_disableWelding; }
	public:
		hkBool m_disableWelding;
};

	enum { HK_MAX_NUM_HITS_PER_AABB_QUERY = 4096 };

namespace hkpCollectionCollectionAgent3
{
	hkpAgentData*	__cdecl FUN_009cfcf0			( const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4* separatingNormal, hkpProcessCollisionOutput& result);
}

struct hkpAgent1nSector
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	                class MustEndWithSemiColon;
	enum { SECTOR_SIZE = 512, NET_SECTOR_SIZE = SECTOR_SIZE - 16 };
	hkUint32 m_bytesAllocated;
	hkUint32 m_pad0;
	hkUint32 m_pad1;
	hkUint32 m_pad2;
	hkUint8 m_data[512-16];
};

struct hkpAgent1nTrack
{
	                class MustEndWithSemiColon;
	hkArray<hkpAgent1nSector*> m_sectors;
};

namespace hkBvTreeAgent3
{
	int				__cdecl calcAabbAndQueryTree( const hkpCdBody& bodyA,	const hkpCdBody& bodyB, const hkTransform& bTa,
													const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input,
													hkAabb* cachedAabb, hkpShapeKey* hitListOut, int hitListCapacity );
	const hkpShapeContainer* __cdecl getShapeContainerFrom(const hkpCdBody* body);
	const hkpShapeCollection* __cdecl getShapeCollectionFromChoosenTypesOfBvTree(const hkpCdBody* body);
}

class hkShapeKeyPair
{
public:
	                class MustEndWithSemiColon;
	hkpShapeKey m_shapeKeyA;
	hkpShapeKey m_shapeKeyB;
};

extern "C"
{
	void __cdecl hkAgentNmMachine_Process( hkpAgent1nTrack& agentTrack, hkpAgent1nTrack* agentTrackOnPpu, const hkpAgent3ProcessInput& input, const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeCollectionB, const hkShapeKeyPair* hitList, hkpProcessCollisionOutput& output  );
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

struct hkpProcessCollisionInput : public hkpCollisionInput
{
		                class MustEndWithSemiColon;
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};

class hkpAabbUtil
{
	public:
		struct OffsetAabbInput
		{
			                class MustEndWithSemiColon;
			hkPadSpu<const hkMotionState*> m_motionState;
			hkTransform m_transforms[4];
			hkPadSpu<int> m_numTransforms;
			hkTransform m_startTransform;
			hkTransform m_endTransformInv;
		};
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

class hk1AxisSweep
{
	public:
		struct AabbInt : public hkAabbUint32
		{
			                class MustEndWithSemiColon;
			hkpShapeKey& getShapeKey() { return m_min[3]; }
		};
		static int __cdecl collide( const AabbInt* pa, int numA, const AabbInt* pb, int numB, hkShapeKeyPair* __restrict pairsOut, int maxNumPairs, int& numPairsSkipped);
};

class hkpListShape : public hkpShapeCollection
{
	public:
		enum { MAX_CHILDREN_FOR_SPU_MIDPHASE = 252 };
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct ChildInfo
		{
			                class MustEndWithSemiColon;
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			__declspec(align(16)) const hkpShape* m_shape;
			hkUint32 m_collisionFilterInfo;
			mutable int m_shapeSize;
			mutable int m_numChildShapes;
		};
	public:
		~hkpListShape();
		inline virtual int getNumChildShapes() const { return m_childInfo.getSize(); }
		inline virtual hkpShapeKey getFirstKey() const { return 0; }
		inline virtual hkpShapeKey getNextKey( hkpShapeKey key ) const { return int(++key) < m_childInfo.getSize() ? key : 0xffffffff; }
		virtual hkUint32 getCollisionFilterInfo(  hkpShapeKey key ) const;
		__forceinline hkBool32 isChildEnabled( hkpShapeKey index ) const
		{
			if ( index < MAX_DISABLED_CHILDREN )
			{
				return m_enabledChildren[ index>>5 ] & (1<<(index&0x1f));
			}
			return true;
		}
		virtual const hkpShape* getChildShape(  hkpShapeKey key, ShapeBuffer& buffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	public:
		friend class hkpListAgent;
		hkArray<struct ChildInfo>	m_childInfo;
		hkVector4					m_aabbHalfExtents;
		hkVector4					m_aabbCenter;
		enum { MAX_DISABLED_CHILDREN = 256 };
		hkUint32 m_enabledChildren[ 8 ];
};

namespace hkAlgorithm
{
	template<typename T>
	class less
	{
	};
	template<typename T, typename L>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize, L cmpLess);
	template<typename T>
	__forceinline	void __cdecl quickSort(T *pArr, int iSize)
	{
		quickSort( pArr, iSize, less<T>() );
	}
	template< typename T, typename L >
	void __cdecl quickSortRecursive(T *pArr, int d, int h, L cmpLess);
}

namespace hkAlgorithm
{
template<typename T, typename L>
void __cdecl quickSort(T *pArr, int iSize, L cmpLess)
{
	if (iSize > 1)
	{
		int	low = 0;
		int high = iSize - 1;
		quickSortRecursive(pArr,low,high, cmpLess);
	}
}
}

namespace hkVector4Util
{
	__forceinline void __cdecl convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out);
	__forceinline void __cdecl convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut );
	__forceinline void __cdecl uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut);
	extern __declspec(align(16)) float hkAabbUint32MaxVal[4];
}

inline void __cdecl hkVector4Util::convertToUint32WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkUint32* out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	out[0] = static_cast<hkUint32>(fnv_FloatToInt(x(0)));
	out[1] = static_cast<hkUint32>(fnv_FloatToInt(x(1)));
	out[2] = static_cast<hkUint32>(fnv_FloatToInt(x(2)));
	out[3] = static_cast<hkUint32>(fnv_FloatToInt(x(3)));
}

inline void __cdecl hkVector4Util::convertAabbToUint32( const hkAabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, hkAabbUint32& aabbOut )
{
	hkVector4 maxVal = (*reinterpret_cast<const hkVector4*>(&hkVector4Util::hkAabbUint32MaxVal));
	;
	hkVector4Util::convertToUint32WithClip( aabb.m_min, offsetLow,  scale, g_vZero, maxVal, aabbOut.m_min );
	hkVector4Util::convertToUint32WithClip( aabb.m_max, offsetHigh, scale, g_vZero, maxVal, aabbOut.m_max );
}

inline void __cdecl hkVector4Util::uncompressExpandedAabbUint32(const hkAabbUint32& unexpandedAabbInt, hkAabbUint32& expandedAabbOut)
{
	int shift = unexpandedAabbInt.m_expansionShift;
	hkUint32 mix = unexpandedAabbInt.m_min[0] - (unexpandedAabbInt.m_expansionMin[0] << shift);
	hkUint32 miy = unexpandedAabbInt.m_min[1] - (unexpandedAabbInt.m_expansionMin[1] << shift);
	hkUint32 miz = unexpandedAabbInt.m_min[2] - (unexpandedAabbInt.m_expansionMin[2] << shift);
	expandedAabbOut.m_min[0]= mix;
	expandedAabbOut.m_min[1]= miy;
	expandedAabbOut.m_min[2]= miz;
	hkUint32 maxx = unexpandedAabbInt.m_max[0] + (unexpandedAabbInt.m_expansionMax[0] << shift);
	hkUint32 may  = unexpandedAabbInt.m_max[1] + (unexpandedAabbInt.m_expansionMax[1] << shift);
	hkUint32 maz  = unexpandedAabbInt.m_max[2] + (unexpandedAabbInt.m_expansionMax[2] << shift);
	expandedAabbOut.m_max[0]= maxx;
	expandedAabbOut.m_max[1]= may;
	expandedAabbOut.m_max[2]= maz;
}

class hkMonitorStream;
extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
class hkMonitorStream
{
	public:
		                class MustEndWithSemiColon;
		static hkMonitorStream& getInstance()
		{
			return *hkMonitorStream__m_instance.getData();
		}
	public:
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			                class MustEndWithSemiColon;
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			                class MustEndWithSemiColon;
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			                class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
};

void hkMonitorStream::TimerCommand::setTime()
{
		hkUint32 ticks;
		__asm {
			rdtsc
			mov dword ptr[ticks], eax
		}
		m_time0 = ticks;
}

static int __cdecl FUN_009ceea0( const hkpCdBody* cdBody, const hkpShapeContainer* collection, const hkpProcessCollisionInput& input, hk1AxisSweep::AabbInt* aabbs, int aabbsCapacity )
{
	const int useContinuousPhysics = input.m_collisionQualityInfo->m_useContinuousPhysics;
	int numChildAabbs = 0;
	const hkpCollidable::BoundingVolumeData* bvData;
	if ( !cdBody->getParent() && (bvData = &static_cast<const hkpCollidable*>(cdBody)->m_boundingVolumeData) && bvData->m_childShapeAabbs && bvData->isValid() )
	{
		hkAabbUint32* childShapeAabbs = bvData->m_childShapeAabbs;
		for ( hkpShapeKey key = collection->getFirstKey(); key != 0xffffffff; key = collection->getNextKey( key ) )
		{
			int destIndex = ( numChildAabbs < 256 ) ? childShapeAabbs->m_sortIndex : numChildAabbs;
			hk1AxisSweep::AabbInt& aabbInt = aabbs[destIndex];
			if ( useContinuousPhysics )
			{
				hkVector4Util::uncompressExpandedAabbUint32( *childShapeAabbs, aabbInt );
			}
			else
			{
				hkString::memCpy16<sizeof(hkAabbUint32)>( &aabbInt, childShapeAabbs );
			}
			aabbInt.getShapeKey() = key;
			childShapeAabbs++;
			numChildAabbs++;
		}
		if ( numChildAabbs < 256 && !useContinuousPhysics )
		{
			goto DONT_SORT;
		}
	}
	else
	{
		char buffer[512];
		hkpAabbUtil::OffsetAabbInput sweepInput;
		if ( useContinuousPhysics )
		{
			hkpAabbUtil::initOffsetAabbInput( cdBody->getRootCollidable()->getMotionState(), sweepInput );
		}
		hkAabb rootAabb; rootAabb.setEmpty();
		for ( hkpShapeKey key = collection->getFirstKey(); key != 0xffffffff; key = collection->getNextKey( key ) )
		{
			if ( !collection->isChildEnabled( key ) )
			{
				continue;
			}
			const hkpShape* child = collection->getChildShape( key, buffer );
			hkAabb aabb;
			child->getAabb( cdBody->getTransform(), input.m_tolerance, aabb );
			if ( useContinuousPhysics )
			{
				hkpAabbUtil::sweepOffsetAabb( sweepInput, aabb, aabb );
			}
			rootAabb.m_min.setMin4( rootAabb.m_min, aabb.m_min );
			rootAabb.m_max.setMax4( rootAabb.m_max, aabb.m_max );
			hk1AxisSweep::AabbInt& aabbInt = aabbs[numChildAabbs++];
			hkVector4Util::convertAabbToUint32( aabb, input.m_aabb32Info.m_bitOffsetLow, input.m_aabb32Info.m_bitOffsetHigh, input.m_aabb32Info.m_bitScale, aabbInt );
			aabbInt.getShapeKey() = key;
		}
	}
	hkAlgorithm::quickSort( aabbs, numChildAabbs );
DONT_SORT:
	;
	return numChildAabbs;
}

__forceinline void __cdecl hkCollectionBvTreeAgent3_calcAabbs( const hkpAgent3ProcessInput& input, const hkpShapeContainer* container, const hkpCdBody* cdBody, const hkpShapeKey* hitList, int numHits, hk1AxisSweep::AabbInt* __restrict aabbsOut )
{
	hkpAabbUtil::OffsetAabbInput sweepInput;
	const int useContinuousPhysics = input.m_input->m_collisionQualityInfo->m_useContinuousPhysics.val();
	if ( useContinuousPhysics )
	{
		hkpAabbUtil::initOffsetAabbInput( cdBody->getRootCollidable()->getMotionState(), sweepInput );
	}
	char shapeBuffer[512];
	for ( int i = 0; i < numHits; i++ )
	{
		hkpShapeKey key = hitList[i];
		const hkpShape* child = container->getChildShape( key, shapeBuffer );
		hkAabb aabb;
		child->getAabb( cdBody->getTransform(), input.m_input->m_tolerance, aabb );
		if ( useContinuousPhysics )
		{
			hkpAabbUtil::sweepOffsetAabb( sweepInput, aabb, aabb );
		}
		hkVector4Util::convertAabbToUint32( aabb, input.m_input->m_aabb32Info.m_bitOffsetLow, input.m_input->m_aabb32Info.m_bitOffsetHigh, input.m_input->m_aabb32Info.m_bitScale, aabbsOut[i] );
		aabbsOut[i].getShapeKey() = key;
	}
}

// pdb: hkpCollectionCollectionAgent3::process | hkpCollectionCollectionAgent3.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: hkpCollectionCollectionAgent3::process_gatherShapeKeys)
// pdb params: input, entry, agentData, separatingNormal, output
hkpAgentData* __cdecl hkpCollectionCollectionAgent3::FUN_009cfcf0( const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4* separatingNormal, hkpProcessCollisionOutput& output )
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "L" "t" "CollColl3"; h->m_nameOfFirstSplit = "S" "t" "Init"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkpAgent1nTrack* agent1nTrack = reinterpret_cast<hkpAgent1nTrack*>(agentData);
	const bool shapeAisCollection = !input.m_input->m_dispatcher->hasAlternateType( input.m_bodyA->getShape()->getType(), HK_SHAPE_BV_TREE );
	const bool shapeBisCollection = !input.m_input->m_dispatcher->hasAlternateType( input.m_bodyB->getShape()->getType(), HK_SHAPE_BV_TREE );
	bool treatAasCollection;
	if ( shapeAisCollection | shapeBisCollection )
	{
		treatAasCollection = shapeAisCollection;
		if ( ( shapeAisCollection && input.m_bodyA->getShape()->getType() != HK_SHAPE_LIST ) || ( shapeBisCollection && input.m_bodyB->getShape()->getType() != HK_SHAPE_LIST ) )
		{
		}
	}
	else
	{
		const bool bodyAHasCachedChildShapeAabbs = !input.m_bodyA->m_parent && static_cast<const hkpCollidable*>(input.m_bodyA.val())->m_boundingVolumeData.m_childShapeAabbs;
		const bool bodyBHasCachedChildShapeAabbs = !input.m_bodyB->m_parent && static_cast<const hkpCollidable*>(input.m_bodyB.val())->m_boundingVolumeData.m_childShapeAabbs;
		if ( bodyAHasCachedChildShapeAabbs == bodyBHasCachedChildShapeAabbs )
		{
			const hkpShapeCollection* childCollectionA = hkBvTreeAgent3::getShapeCollectionFromChoosenTypesOfBvTree( input.m_bodyA );
			const hkpShapeCollection* childCollectionB = hkBvTreeAgent3::getShapeCollectionFromChoosenTypesOfBvTree( input.m_bodyB );
			const bool shapeAhasList = childCollectionA ? childCollectionA->getType() == HK_SHAPE_LIST : false;
			const bool shapeBhasList = childCollectionB ? childCollectionB->getType() == HK_SHAPE_LIST : false;
			if ( shapeAhasList && shapeBhasList )
			{
				treatAasCollection = static_cast<const hkpListShape*>(childCollectionA)->m_childInfo.getSize() <= static_cast<const hkpListShape*>(childCollectionB)->m_childInfo.getSize();
			}
			else if ( shapeAhasList | shapeBhasList )
			{
				treatAasCollection = shapeAhasList;
			}
			else
			{
				treatAasCollection = input.m_bodyA->getMotionState()->m_objectRadius <= input.m_bodyB->getMotionState()->m_objectRadius;
			}
		}
		else
		{
			treatAasCollection = bodyAHasCachedChildShapeAabbs;
		}
	}
	const hkpShapeContainer* shapeContainerA = hkBvTreeAgent3::getShapeContainerFrom( input.m_bodyA );
	const hkpShapeContainer* shapeContainerB = hkBvTreeAgent3::getShapeContainerFrom( input.m_bodyB );
	hkShapeKeyPair* shapeKeyPairs = hkAllocateStack<hkShapeKeyPair>( HK_MAX_NUM_HITS_PER_AABB_QUERY );
	{
		int numHitsFirst = 0;
		int numHitsSecond = 0;
		hk1AxisSweep::AabbInt* aabbsFirst;
		hk1AxisSweep::AabbInt* aabbsSecond;
		const hkpCdBody* firstCdBody;
		int numShapeKeyPairs;
		{
			const hkpCdBody* secondBody;
			const hkpShapeContainer* secondContainer;
			if ( !(shapeAisCollection & shapeBisCollection) )
			{
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "queryTree"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				const hkpShapeContainer* firstContainer;
				hkpShapeKey hitList[HK_MAX_NUM_HITS_PER_AABB_QUERY];
				if ( treatAasCollection )
				{
					hkTransform bTa; bTa.setInverse( input.m_aTb );
					numHitsFirst = hkBvTreeAgent3::calcAabbAndQueryTree( *input.m_bodyA, *input.m_bodyB, bTa, input.m_linearTimInfo, *input.m_input, 0, hitList, HK_MAX_NUM_HITS_PER_AABB_QUERY );
					firstCdBody = input.m_bodyB;
					firstContainer = shapeContainerB;
					secondBody = input.m_bodyA;
					secondContainer = shapeContainerA;
				}
				else
				{
					hkVector4 negLinearTimInfo; negLinearTimInfo.setNeg3( input.m_linearTimInfo );
					numHitsFirst = hkBvTreeAgent3::calcAabbAndQueryTree( *input.m_bodyB, *input.m_bodyA, input.m_aTb, negLinearTimInfo, *input.m_input, 0, hitList, HK_MAX_NUM_HITS_PER_AABB_QUERY );
					firstCdBody = input.m_bodyA;
					firstContainer = shapeContainerA;
					secondBody = input.m_bodyB;
					secondContainer = shapeContainerB;
				}
				aabbsFirst = hkAllocateStack<hk1AxisSweep::AabbInt>( numHitsFirst + 4 );
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "ConvertHitlist"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				hkCollectionBvTreeAgent3_calcAabbs( input, firstContainer, firstCdBody, hitList, numHitsFirst, aabbsFirst );
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "SortHitList"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				hkAlgorithm::quickSort( aabbsFirst, numHitsFirst );
			}
			else
			{
				numHitsFirst = shapeContainerA->getNumChildShapes();
				aabbsFirst = hkAllocateStack<hk1AxisSweep::AabbInt>( numHitsFirst + 4 );
				numHitsFirst = FUN_009ceea0( input.m_bodyA, shapeContainerA, *input.m_input, aabbsFirst, numHitsFirst );
				firstCdBody = input.m_bodyA;
				secondBody = input.m_bodyB;
				secondContainer = shapeContainerB;
			}
			if ( numHitsFirst )
			{
				numHitsSecond = secondContainer->getNumChildShapes();
				aabbsSecond = hkAllocateStack<hk1AxisSweep::AabbInt>( numHitsSecond + 4 );
				numHitsSecond = FUN_009ceea0( secondBody, secondContainer, *input.m_input, aabbsSecond, numHitsSecond );
			}
			else
			{
				numHitsSecond = 0;
				aabbsSecond = hkAllocateStack<hk1AxisSweep::AabbInt>( 4 );
			}
			for ( int i = numHitsFirst; i < numHitsFirst + 4; i++ ) { aabbsFirst[i].m_min[0] = hkUint32(-1); }
			for ( int i = numHitsSecond; i < numHitsSecond + 4; i++ ) { aabbsSecond[i].m_min[0] = hkUint32(-1); }
		}
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "1-Axis"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			int numPairsSkipped = 0;
			if ( firstCdBody == input.m_bodyA )
			{
				numShapeKeyPairs = hk1AxisSweep::collide( aabbsFirst, numHitsFirst, aabbsSecond, numHitsSecond, shapeKeyPairs, HK_MAX_NUM_HITS_PER_AABB_QUERY - 1, numPairsSkipped );
			}
			else
			{
				numShapeKeyPairs = hk1AxisSweep::collide( aabbsSecond, numHitsSecond, aabbsFirst, numHitsFirst, shapeKeyPairs, HK_MAX_NUM_HITS_PER_AABB_QUERY - 1, numPairsSkipped );
			}
			hkDeallocateStack( aabbsSecond );
			hkDeallocateStack( aabbsFirst );
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "SortHits"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::AddValueCommand* h = reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "M" "i" "NumHits"; h->m_value = float(numShapeKeyPairs); mStream.setEnd( (char*)(h+1) ); } };
			hkAlgorithm::quickSort( shapeKeyPairs, numShapeKeyPairs );
			hkShapeKeyPair& pair = shapeKeyPairs[numShapeKeyPairs];
			pair.m_shapeKeyA = 0xffffffff;
			pair.m_shapeKeyB = 0xffffffff;
		}
		int total = numShapeKeyPairs + 1;
		if ( total < HK_MAX_NUM_HITS_PER_AABB_QUERY )
		{
			hkShrinkAllocatedStack( shapeKeyPairs, total );
		}
	}
	hkpAgent1nTrack* trackOnPpu = hkAddByteOffset( agent1nTrack, input.m_offsetPpuSectorMinusSpuSector );
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "Narrow"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkAgentNmMachine_Process( *agent1nTrack, trackOnPpu, input, shapeContainerA, shapeContainerB, shapeKeyPairs, output );
	hkDeallocateStack( shapeKeyPairs );
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	return hkAddByteOffset( agentData, ( ((sizeof( hkpAgent1nTrack )) + ((16)-1)) & (~((16)-1)) ) );
}

}
