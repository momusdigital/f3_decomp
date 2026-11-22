// src/f3staging/f3blk_00a00000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a04480 (community match, verified in this file)
// 0x00a04480: hkpTransformCollapseUtil::collapseTransformShape(const hkpShape* transformShape, const Options& options,
// _SharedShapeData& sharedShapeData, Results& resultsOut) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Collapses one transform, convex transform or convex translate shape: an identity transform is dropped; a transform
// over a list shape is pushed down to the list's children (recursively); capsules, cylinders, convex vertices shapes
// and boxes with an axis-permuting rotation get the transform baked into new shapes; other convex children get a
// convex translate or convex transform shape; every replacement is recorded in the shared shape data.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. _SharedShapeData, a class of the library's own .cpp
// file that no header ships, is declared from the library's debug records (its members, their types and order; no
// bodies). The SDK's int 3 traps in the unused placement operators new[] and delete[] were removed by hand. The
// function body follows the SDK's unoptimized (hybrid) library object statement by statement and reproduces the
// release object. Only the function carries the packet's name.
namespace f3m_00a04480 {

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
};
typedef unsigned __w64 hk_size_t;
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
		}
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
				__forceinline void setData(T p)
				{
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
HK_MEMORY_CLASS_MAX };
class hkMemory;
class hkThreadMemory
{
	public:
		hkThreadMemory( hkMemory* mainMemoryManager, int maxNumElemsOnFreeList = 16);
		void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl );
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
		virtual void setStackArea(void* buf, int nbytes);
		static inline hkThreadMemory* __cdecl getInstancePtr();
		static inline hkThreadMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkThreadMemory* m);
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
					m_end(0)
			{
			}
			__declspec(align(16)) char* m_current;
			char* m_end;
			int getFreeBytes() { return int(m_end - m_current)-16; }
		};
		__forceinline Stack& __cdecl getStack();
		struct FreeList
		{
			void put( void* p )
			{
				m_numElem += 1;
				FreeElem* fl = static_cast<FreeElem*>(p);
			}
			struct FreeElem	{ FreeElem* m_next; };
			FreeElem* m_head;
			int m_numElem;
		};
		FreeList m_free_list[MEMORY_MAX_ALL_ROW];
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
		int m_finishing;
	private:
};
class hkBaseObject
{
	public:
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
		enum
		{
			MASK_MEMSIZE = 0x7fff
		};
		hkUint16 m_memSizeAndFlags;
		mutable hkInt16 m_referenceCount;
};
__forceinline void hkReferencedObject::addReference() const
{
	if ( m_memSizeAndFlags != 0 )
	{
		++m_referenceCount;
	}
}
__forceinline void hkReferencedObject::removeReference() const
{
	if ( m_memSizeAndFlags != 0 )
	{
		--m_referenceCount;
		if ( m_referenceCount == 0 )
		{
			delete this;
		}
	}
}
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
	public:
		__forceinline hkArray();
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline T& back();
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline hkBool isEmpty() const;
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void setSize(int n, const T& fill);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline const_iterator end() const;
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
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
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
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}
template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
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
		__forceinline hkResult normalize3IfNotZero ();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w);
		__forceinline void setW(const hkVector4& v);
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
		hkBool isOk() const;
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
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
		hkQuaternion m_rotation;
		hkVector4 m_scale;
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
inline hkVector4::hkVector4( const hkVector4& v)
{
	*this = v;
}
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline hkReal& hkMatrix3::operator() (int r, int c)
{
	return getColumn(c)(r);
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
inline void hkMatrix3::operator= ( const hkMatrix3& a )
{
	m_col0 = a.getColumn(0);
	m_col1 = a.getColumn(1);
	m_col2 = a.getColumn(2);
}
inline void hkMatrix3::setZero()
{
	hkVector4 zero; zero.setZero4();
	getColumn(0) = zero;
	getColumn(1) = zero;
	getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
	setZero();
	hkReal one = 1.0f;
	(*this)(0,0) = one;
	(*this)(1,1) = one;
	(*this)(2,2) = one;
}
hkVector4& hkTransform::getColumn(int x)
{
	return m_rotation.getColumn(x);
}
hkVector4& hkTransform::getTranslation()
{
	return m_translation;
}
void hkTransform::setTranslation(const hkVector4& t)
{
	m_translation = t;
}
hkRotation& hkTransform::getRotation()
{
	return m_rotation;
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
hkTransform::hkTransform(const hkTransform& t)
{
	const hkVector4 r0 = t.m_rotation.getColumn(0);
	const hkVector4 r1 = t.m_rotation.getColumn(1);
	const hkVector4 r2 = t.m_rotation.getColumn(2);
	const hkVector4 r3 = t.m_rotation.getColumn(3);
	m_rotation.getColumn(0) = r0;
	m_rotation.getColumn(1) = r1;
	m_rotation.getColumn(2) = r2;
	m_rotation.getColumn(3) = r3;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
const hkTransform& __cdecl hkTransform::getIdentity()
{
	extern hkReal hkTransformIdentity[];
	return reinterpret_cast<const hkTransform&>(hkTransformIdentity);
}
void hkTransform::setIdentity()
{
	m_rotation.setIdentity();
	m_translation.setZero4();
}
class hkString
{
	public:
	public:
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
private:
		static void copyAndReplace( char* dest, const char* orig, int origLen, const hkString& from, const hkString& to, const hkArray<int>& indices);
};
class hkpRigidBody;
class hkpShape;
class hkpTransformCollapseUtil
{
	public:
		enum SharedShapeBehaviour
		{
			ALWAYS_COLLAPSE,
			NEVER_COLLAPSE,
			COLLAPSE_IF_LESS_THAN_THRESHOLD,
		};
		struct Options
		{
			SharedShapeBehaviour m_sharedShapeBehaviour;
			int m_sharedShapeThreshold;
			hkBool m_propageTransformInList;
			Options ();
		};
		struct Results
		{
			int m_numCollapsedShapes;
			int m_numIdentityTransformsRemoved;
			int m_numSpecializedTransformShapes;
			int m_numPropagatedTransformsToLists;
			Results();
			void report() const;
			void reset();
		};
		static hkResult __cdecl collapseTransforms (hkpRigidBody* rigidBody, const Options& options, Results& resultsOut);
		static hkResult __cdecl collapseTransforms (hkArray<hkpRigidBody*>& rigidBodies, const Options& options, Results& resultsOut);
	private:
		static const hkpShape* FUN_00a04480 (const hkpShape* transformShape, const Options& options, class _SharedShapeData& sharedShapeData, Results& resultsOut);
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
};
class hkpCdVertex;
class hkAabb;
struct hkpShapeRayCastInput;
struct hkpShapeRayCastOutput;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete(void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().allocateChunk(static_cast<int>(nbytes),HK_MEMORY_CLASS_CDINFO)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; } __forceinline void __cdecl operator delete[](void* p) { hkReferencedObject* b = static_cast<hkReferencedObject*>(p); hkThreadMemory::getInstance().deallocateChunk(p, b->m_memSizeAndFlags,HK_MEMORY_CLASS_CDINFO); } __forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
				hkPadSpu<GetCollisionFilterInfoFunc>		m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
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
namespace hkVector4Util
{
__forceinline void __cdecl transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	;
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum {  HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
		typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
		virtual ~hkpShapeContainer() { }
		virtual int getNumChildShapes() const;
		virtual bool isWeldingEnabled() const { return true; }
};
class hkpSingleShapeContainer : public hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		void* operator new(hk_size_t, void* p) { return p; }
		void  operator delete(void* p) { }
		hkpSingleShapeContainer( const hkpShape* s ) : m_childShape(s)
		{
			m_childShape->addReference();
		}
		hkpSingleShapeContainer(hkFinishLoadedObjectFlag) {}
		~hkpSingleShapeContainer()
		{
			m_childShape->removeReference();
		}
		virtual int getNumChildShapes() const { return 1; }
		virtual hkpShapeKey getFirstKey() const { return 0; }
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const { return 0xffffffff; }
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const;
		inline const hkpShape* getChild() const { return m_childShape; }
		inline const hkpShape* operator->() const { return m_childShape; }
	protected:
		const hkpShape* m_childShape;
};
class hkpTransformShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpTransformShape( const hkpShape* childShape, const hkTransform& transform );
		hkpTransformShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag), m_childShape(flag) { m_type = HK_SHAPE_TRANSFORM; }
		inline const hkpShape* getChildShape() const;
		inline const hkTransform& getTransform() const;
		inline const hkQuaternion& getRotation() const;
		void setTransform(const hkTransform& transform);
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual const hkpShapeContainer* getContainer() const;
	protected:
		class hkpSingleShapeContainer m_childShape;
		hkQuaternion m_rotation;
		hkTransform m_transform;
};
inline const hkpShape* hkpTransformShape::getChildShape() const
{
	return m_childShape.getChild();
}
inline const hkTransform& hkpTransformShape::getTransform() const
{
	return m_transform;
}
class hkpSphereRepShape : public hkpShape
{
	public:
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
	public:
		hkpSphereRepShape( hkpShapeType type ) : hkpShape( type ) {}
		hkpSphereRepShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_SPHERE_REP; }
};
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		inline void setRadius(hkReal radius);
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		inline hkpConvexShape( hkpShapeType type, hkReal radius );
		hkReal m_radius;
	public:
		hkpConvexShape( hkFinishLoadedObjectFlag flag ) : hkpSphereRepShape(flag) { m_type = HK_SHAPE_CONVEX; }
};
inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}
class hkpConvexTransformShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform);
		hkpConvexTransformShape( class hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag), m_childShape(flag) { m_type = HK_SHAPE_CONVEX_TRANSFORM; }
		void setTransform( const hkTransform& transform );
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		inline const hkpConvexShape* getChildShape() const;
		inline hkTransform& getTransform();
		inline const hkTransform& getTransform() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		class hkpSingleShapeContainer m_childShape;
		mutable int m_childShapeSize;
		hkTransform m_transform;
};
inline const hkpConvexShape* hkpConvexTransformShape::getChildShape() const
{
	return static_cast<const hkpConvexShape*>(m_childShape.getChild());
}
inline const hkTransform& hkpConvexTransformShape::getTransform() const
{
	return m_transform;
}
class hkpConvexTranslateShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation);
		hkpConvexTranslateShape( class hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag), m_childShape(flag) { m_type = HK_SHAPE_CONVEX_TRANSLATE; }
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		inline const hkpConvexShape* getChildShape() const;
		inline hkVector4& getTranslation();
		inline const hkVector4& getTranslation() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
	protected:
		class hkpSingleShapeContainer m_childShape;
		mutable int m_childShapeSize;
		hkVector4 m_translation;
};
inline const hkpConvexShape* hkpConvexTranslateShape::getChildShape() const
{
	return static_cast<const hkpConvexShape*>(m_childShape.getChild());
}
inline const hkVector4& hkpConvexTranslateShape::getTranslation() const
{
	return m_translation;
}
extern hkReal hkConvexShapeDefaultRadius;
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
	public:
		hkBool m_disableWelding;
};
class hkMotionState;
class hkpAabbUtil
{
	public:
		static void __cdecl calcAabb( const float* vertexArray, int numVertices, int striding, hkAabb& aabbOut );
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, const hkVector4& center, float extraRadius, hkAabb& aabbOut);
		static inline void __cdecl calcAabb( const hkTransform& BvToWorld, const hkVector4& halfExtents, float extraRadius, hkAabb& aabbOut);
	public:
		struct OffsetAabbInput
		{
		};
		__forceinline static void __cdecl sweepAabb(const hkMotionState* motionstate, hkReal tolerance, const hkAabb& aabbIn, hkAabb& aabbOut);
		static void __cdecl initOffsetAabbInput(const hkMotionState* motionstate, OffsetAabbInput& input);
		static void __cdecl sweepOffsetAabb(const OffsetAabbInput& input, const hkAabb& aabbIn, hkAabb& aabbOut);
};
class hkShapeKeyPair;
class hk1AxisSweep
{
	public:
		struct AabbInt : public hkAabbUint32
		{
			__forceinline hkUint32 yzDisjoint( const AabbInt& other ) const
			{
				hkUint32 yab = m_max[1] - other.m_min[1];
				hkUint32 yba = other.m_max[1] - m_min[1];
				hkUint32 zab = m_max[2] - other.m_min[2];
				hkUint32 zba = other.m_max[2] - m_min[2];
				hkUint32 combined = (yab | yba) | (zab | zba);
				return combined & 0x80000000;
			}
			void operator=( const AabbInt& other )
			{
				hkString::memCpy16<sizeof(AabbInt)>( this, &other );
			}
		};
};
struct hkpCollisionInput;
class hkpListShape : public hkpShapeCollection
{
	public:
		enum { MAX_CHILDREN_FOR_SPU_MIDPHASE = 252 };
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct ChildInfo
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			__declspec(align(16)) const hkpShape* m_shape;
			hkUint32 m_collisionFilterInfo;
			mutable int m_shapeSize;
			mutable int m_numChildShapes;
		};
	public:
		hkpListShape( const hkpShape*const* shapeArray, int numShapes );
		hkpListShape( class hkFinishLoadedObjectFlag flag );
		~hkpListShape();
		inline const hkpShape* getChildShapeInl(int i) const { return m_childInfo[i].m_shape; }
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
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	public:
		friend class hkpListAgent;
		hkArray<struct ChildInfo>	m_childInfo;
		hkVector4					m_aabbHalfExtents;
		hkVector4					m_aabbCenter;
		enum { MAX_DISABLED_CHILDREN = 256 };
		hkUint32 m_enabledChildren[ 8 ];
	protected:
		void setShapes( const hkpShape*const* shapeArray, int numShapes, const hkUint32* filterInfoArray = 0);
};
class hkpCapsuleShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum RayHitType
		{
			HIT_CAP0,
			HIT_CAP1,
			HIT_BODY,
		};
		hkpCapsuleShape( const hkVector4& vertexA,const hkVector4& vertexB, hkReal radius );
		inline const hkVector4* getVertices() const;
		__forceinline const hkVector4& getVertex(int i) const;
		__forceinline void setVertex(int i, const hkVector4& position );
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
	protected:
		hkVector4  m_vertexA;
		hkVector4  m_vertexB;
	public:
		hkpCapsuleShape( hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag) { m_type = HK_SHAPE_CAPSULE; }
};
const hkVector4* hkpCapsuleShape::getVertices() const
{
	return &m_vertexA;
}
class hkpCylinderShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		hkpCylinderShape(	const hkVector4& vertexA,
							const hkVector4& vertexB,
							hkReal cylinderRadius,
							hkReal paddingRadius = hkConvexShapeDefaultRadius );
		inline const hkVector4* getVertices() const;
		__forceinline const hkVector4& getVertex(int i) const;
		__forceinline void setVertex(int i, const hkVector4& position );
		hkReal getCylinderRadius() const;
		void setCylinderRadius(const hkReal radius);
		hkReal getCylinderBaseRadiusFactorForHeightfieldCollisions(hkReal radiusFactor) { return m_cylBaseRadiusFactorForHeightFieldCollisions; }
		inline void setCylinderBaseRadiusFactorForHeightfieldCollisions(hkReal radiusFactor) { m_cylBaseRadiusFactorForHeightFieldCollisions = radiusFactor; }
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
	protected:
		hkReal    m_cylRadius;
		hkReal m_cylBaseRadiusFactorForHeightFieldCollisions;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_perpendicular1;
		hkVector4 m_perpendicular2;
	public:
		hkpCylinderShape( hkFinishLoadedObjectFlag flag );
		enum VertexIdEncoding
		{
			VERTEX_ID_ENCODING_IS_BASE_A_SHIFT     = 7,
			VERTEX_ID_ENCODING_SIN_SIGN_SHIFT      = 6,
			VERTEX_ID_ENCODING_COS_SIGN_SHIFT      = 5,
			VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT = 4,
			VERTEX_ID_ENCODING_VALUE_MASK          = 0x0f
		};
	private:
		static hkReal s_virtualTesselationParameter;
		static hkReal s_virtualTesselationParameterInv;
		static hkReal s_intRoundUpThreshold;
};
const hkVector4* hkpCylinderShape::getVertices() const
{
	return &m_vertexA;
}
struct hkStridedVertices
{
	const float* m_vertices;
	int m_numVertices;
	int m_striding;
};
class hkpConvexVerticesConnectivity;
class hkpConvexVerticesShape : public hkpConvexShape
{
	public:
		struct FourVectors
		{
			static const struct hkInternalClassMember Members[]; struct DefaultStruct;
			hkVector4 m_x;
			hkVector4 m_y;
			hkVector4 m_z;
		};
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		hkpConvexVerticesShape(const hkStridedVertices& vertsIn, const hkArray<hkVector4>& planeEquations, hkReal radius = hkConvexShapeDefaultRadius);
		hkpConvexVerticesShape( FourVectors* rotatedVertices, int numVertices,
				hkVector4* planes, int numPlanes,
				const hkAabb& aabb, hkReal radius = hkConvexShapeDefaultRadius );
		~hkpConvexVerticesShape();
		void getOriginalVertices( hkArray<hkVector4>& vertices ) const;
		const hkArray<hkVector4>& getPlaneEquations() const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		void getFirstVertex(hkVector4& v) const;
		inline const hkpConvexVerticesConnectivity* getConnectivity() const { return m_connectivity; }
        void setConnectivity(const hkpConvexVerticesConnectivity* connect) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
		void copyVertexData(const float* vertexIn, int byteStriding, int numVertices);
	protected:
		hkVector4	m_aabbHalfExtents;
		hkVector4	m_aabbCenter;
		hkArray<struct FourVectors> m_rotatedVertices;
		hkInt32		m_numVertices;
		hkArray<hkVector4>	m_planeEquations;
        mutable const hkpConvexVerticesConnectivity* m_connectivity;
	public:
};
class hkpBoxShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		hkpBoxShape( const hkVector4& halfExtents, hkReal radius = hkConvexShapeDefaultRadius );
		inline const hkVector4& getHalfExtents() const;
		void setHalfExtents(const hkVector4& halfExtents);
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		static void __cdecl registerSimulationFunctions( ShapeFuncs& sf );
		static void __cdecl registerCollideQueryFunctions( ShapeFuncs& sf );
		static void __cdecl registerGetAabbFunction( ShapeFuncs& sf );
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkVector4 m_halfExtents;
	public:
		~hkpBoxShape();
		hkpBoxShape( hkFinishLoadedObjectFlag flag ) : hkpConvexShape(flag) { m_type = HK_SHAPE_BOX; }
};
inline const hkVector4 &hkpBoxShape::getHalfExtents() const
{
	return m_halfExtents;
}
class _SharedShapeData
{
	public:
		void removeSingleReferencedShapeData();
		_SharedShapeData( const hkArray<hkpRigidBody*>& rigidBodies );
		~_SharedShapeData();
		const hkpShape* findReplacement( const hkpShape* originalShape ) const;
		const int numberOfReferences( const hkpShape* shape ) const;
		hkResult setReplacement( const hkpShape* originalShape, const hkpShape* replacementShape );
		struct SharedShape
		{
			const hkpShape* m_originalShape;
			const hkpShape* m_replacementShape;
			int m_numReferences;
		};
	private:
		hkArray<SharedShape> m_sharedShapes;
		int findShapeDataIndex( const hkpShape* shape ) const;
		void recursivelyParseShapeReferences( const hkpShape* shape );
};
const hkpShape* hkpTransformCollapseUtil::FUN_00a04480 (const hkpShape* transformShape, const Options& options, _SharedShapeData& sharedShapeData, Results& resultsOut)
{
	const hkpShapeType transformShapeType = transformShape->getType();
	hkTransform parentFromChild;
	const hkpShape* childShape = 0;
	switch (transformShapeType)
	{
		case HK_SHAPE_TRANSFORM:
		{
			const hkpTransformShape* tformshape = static_cast<const hkpTransformShape*> (transformShape);
			parentFromChild = tformshape->getTransform();
			childShape = tformshape->getChildShape();
			break;
		}
		case HK_SHAPE_CONVEX_TRANSFORM:
		{
			const hkpConvexTransformShape* ctformshape = static_cast<const hkpConvexTransformShape*> (transformShape);
			parentFromChild = ctformshape->getTransform();
			childShape = ctformshape->getChildShape();
			break;
		}
		case HK_SHAPE_CONVEX_TRANSLATE:
		{
			const hkpConvexTranslateShape* ctlateshape = static_cast<const hkpConvexTranslateShape*> (transformShape);
			parentFromChild.setIdentity();
			parentFromChild.setTranslation(ctlateshape->getTranslation());
			childShape = ctlateshape->getChildShape();
			break;
		}
		default:
		{
		}
	}
	const hkpShapeType childShapeType = childShape->getType();
	if (childShapeType == HK_SHAPE_SPHERE)
	{
		parentFromChild.getRotation() = hkTransform::getIdentity().getRotation();
	}
	if (parentFromChild.isApproximatelyEqual(hkTransform::getIdentity(), 0.001f))
	{
		resultsOut.m_numIdentityTransformsRemoved++;
		childShape->addReference();
		sharedShapeData.setReplacement(transformShape, childShape);
		return childShape;
	}
	bool allowChangesToChildShape = true;
	switch (options.m_sharedShapeBehaviour)
	{
		case ALWAYS_COLLAPSE:
			allowChangesToChildShape = true;
			break;
		case NEVER_COLLAPSE:
			allowChangesToChildShape = false;
			break;
		case COLLAPSE_IF_LESS_THAN_THRESHOLD:
			allowChangesToChildShape = sharedShapeData.numberOfReferences(childShape) < options.m_sharedShapeThreshold;
			break;
	}
	if (childShapeType == HK_SHAPE_LIST)
	{
		const hkpListShape* listShape = static_cast<const hkpListShape*> (childShape);
		if (!options.m_propageTransformInList && allowChangesToChildShape)
		{
			resultsOut.m_numPropagatedTransformsToLists++;
			hkArray<const hkpShape*> newChildren;
			for (int i=0; i<listShape->getNumChildShapes(); i++)
			{
				const hkpShape* grandChildShape = listShape->getChildShapeInl(i);
				hkpTransformShape* childTransformShape = new hkpTransformShape(grandChildShape, parentFromChild);
				const hkpShape* collapsedGrandChild = FUN_00a04480(childTransformShape, options, sharedShapeData, resultsOut);
				newChildren.pushBack(collapsedGrandChild);
				childTransformShape->removeReference();
			}
			const hkpListShape* newListShape = new hkpListShape(newChildren.begin(), newChildren.getSize());
			for (int n=0; n<newChildren.getSize(); n++)
			{
				newChildren[n]->removeReference();
			}
			sharedShapeData.setReplacement(transformShape, newListShape);
			return newListShape;
		}
		else
		{
			transformShape->addReference();
			return transformShape;
		}
	}
	if (allowChangesToChildShape)
	{
		switch (childShapeType)
		{
			case HK_SHAPE_CAPSULE:
			{
				const hkpCapsuleShape* childCapsuleShape = static_cast<const hkpCapsuleShape*> (childShape);
				const hkVector4& childA = childCapsuleShape->getVertices()[0];
				const hkVector4& childB = childCapsuleShape->getVertices()[1];
				const hkReal radius = childCapsuleShape->getRadius();
				hkVector4 parentA; parentA.setTransformedPos(parentFromChild, childA);
				hkVector4 parentB; parentB.setTransformedPos(parentFromChild, childB);
				const hkpCapsuleShape* newCapsule = new hkpCapsuleShape(parentA, parentB, radius);
				sharedShapeData.setReplacement(transformShape, newCapsule);
				resultsOut.m_numCollapsedShapes++;
				return newCapsule;
			}
			case HK_SHAPE_CYLINDER:
			{
				const hkpCylinderShape* childCylinderShape = static_cast<const hkpCylinderShape*> (childShape);
				const hkVector4& childA = childCylinderShape->getVertices()[0];
				const hkVector4& childB = childCylinderShape->getVertices()[1];
				const hkReal cylRadius = childCylinderShape->getCylinderRadius();
				const hkReal radius = childCylinderShape->getRadius();
				hkVector4 parentA; parentA.setTransformedPos(parentFromChild, childA);
				hkVector4 parentB; parentB.setTransformedPos(parentFromChild, childB);
				const hkpCylinderShape* newCylinder = new hkpCylinderShape(parentA, parentB, cylRadius, radius);
				sharedShapeData.setReplacement(transformShape, newCylinder);
				resultsOut.m_numCollapsedShapes++;
				return newCylinder;
			}
			case HK_SHAPE_CONVEX_VERTICES:
			{
				const hkpConvexVerticesShape* childCVShape = static_cast<const hkpConvexVerticesShape*> (childShape);
				hkArray<hkVector4> vertices;
				childCVShape->getOriginalVertices(vertices);
				hkVector4Util::transformPoints(parentFromChild, vertices.begin(), vertices.getSize(), vertices.begin());
				hkStridedVertices newverts; newverts.m_numVertices = vertices.getSize();
				newverts.m_striding = sizeof(hkVector4);
				newverts.m_vertices = &(vertices[0](0));
				const hkArray<hkVector4>& planes = childCVShape->getPlaneEquations();
				hkArray<hkVector4> newplanes; newplanes.setSize(planes.getSize());
				hkVector4 pivotShift = parentFromChild.getTranslation();
				for (int p=0; p<planes.getSize(); p++)
				{
					hkVector4 plane = planes[p];
					hkReal newDist = plane(3) - pivotShift.dot3(plane);
					plane.setRotatedDir(parentFromChild.getRotation(), plane);
					plane(3) = newDist;
					newplanes[p] = plane;
				}
				const hkpConvexVerticesShape* newCVShape = new hkpConvexVerticesShape(newverts, newplanes, childCVShape->getRadius());
				sharedShapeData.setReplacement(transformShape, newCVShape);
				resultsOut.m_numCollapsedShapes++;
				return newCVShape;
			}
			case HK_SHAPE_BOX:
			{
				const hkReal tol = 1e-4f;
				if (!parentFromChild.getRotation().isOrthonormal(0.001f) || !parentFromChild.getRotation().isOk())
				{
					break;
				}
				if (parentFromChild.getRotation().isApproximatelyEqual(hkTransform::getIdentity().getRotation(), 0.001f))
				{
					break;
				}
				bool failedA = false;
				bool failedB = false;
				int map[3];
				for (int i=0; i<3; i++)
				{
					hkVector4& axisRot = parentFromChild.getColumn(i);
					bool passedA1 = false;
					for (int j=0; j<3; j++)
					{
						bool testA0 = hkMath::fabs(axisRot(j)) < tol;
						bool testA1 = hkMath::fabs(hkMath::fabs(axisRot(j)) - 1.0f) < tol;
						if (!testA0 && !testA1)
						{
							failedA = true;
							break;
						}
						if (testA1)
						{
							map[j] = i;
							passedA1 = true;
						}
					}
					if (!passedA1) failedA = true;
					if (failedA) break;
					hkReal sum = 0.0f;
					for (int j=0; j<3; j++)
					{
						sum += hkMath::fabs(axisRot(j));
					}
					failedB = !((sum - 1.0f) < tol);
					if (failedB) break;
				}
				if (failedA || failedB) break;
				const hkpBoxShape* childBoxShape = static_cast<const hkpBoxShape*> (childShape);
				const hkVector4& halfExtents = childBoxShape->getHalfExtents();
				hkVector4 newHalfExtents; newHalfExtents.set(halfExtents(map[0]), halfExtents(map[1]), halfExtents(map[2]), 0.0f);
				const hkpBoxShape* newBoxShape = new hkpBoxShape(newHalfExtents);
				if (parentFromChild.getTranslation().length3() < tol)
				{
					sharedShapeData.setReplacement(transformShape, newBoxShape);
					resultsOut.m_numCollapsedShapes++;
					return newBoxShape;
				}
				{
					const hkpConvexTranslateShape* newShape = new hkpConvexTranslateShape(newBoxShape, parentFromChild.getTranslation());
					newBoxShape->removeReference();
					sharedShapeData.setReplacement(transformShape, newShape);
					resultsOut.m_numSpecializedTransformShapes++;
					return newShape;
				}
			}
		}
	}
	switch (childShapeType)
	{
		case HK_SHAPE_CONVEX:
		case HK_SHAPE_SPHERE:
		case HK_SHAPE_CYLINDER:
		case HK_SHAPE_BOX:
		case HK_SHAPE_CAPSULE:
		case HK_SHAPE_CONVEX_VERTICES:
		{
			const hkpConvexShape* childConvexShape = static_cast<const hkpConvexShape*> (childShape);
			hkBool translateOnly = parentFromChild.getRotation().isApproximatelyEqual(hkTransform::getIdentity().getRotation(), 0.001f);
			if (translateOnly && (transformShapeType != HK_SHAPE_CONVEX_TRANSLATE))
			{
				const hkpConvexTranslateShape* newShape = new hkpConvexTranslateShape(childConvexShape, parentFromChild.getTranslation());
				sharedShapeData.setReplacement(transformShape, newShape);
				resultsOut.m_numSpecializedTransformShapes++;
				return newShape;
			}
			else if (transformShapeType == HK_SHAPE_TRANSFORM)
			{
				const hkpConvexTransformShape* newShape = new hkpConvexTransformShape(childConvexShape, parentFromChild);
				sharedShapeData.setReplacement(transformShape, newShape);
				resultsOut.m_numSpecializedTransformShapes++;
				return newShape;
			}
		}
	}
	transformShape->addReference();
	return transformShape;
}

}  // namespace f3m_00a04480

// @f3 0x00a0e5d0 (community match, verified in this file)
namespace f3m_00a0e5d0 {
// 0x00a0e5d0: hkSolver_solvePoweredChain(const hkpSolverInfo& solverInfo, const hkSolver::SolverStepTemp& temp,
// hkpVelocityAccumulator* accums, hkpJacobianPoweredChainSchema* chain, hkpSolverElemTemp* sr) of Havok 5.5.0
// (hkpConstraintSolver, hkpSolver.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Solves one powered chain
// schema: fills the chain info from the schema's buffers, adds the motors' target velocities to the angular rhs,
// computes the chain's velocities, enables and then disables motors until no motor limit changes (each change
// updates the LU decomposition), then back-substitutes the impulses link by link and applies them to the bodies.
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the function's code needs (whole
// declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte against the SDK's release library
// object); those declarations are the SDK's text with its names. The library's own types that no SDK header ships
// (hkpChainSolverInfo, hkpJacobianPoweredChainSchema, hkSolver::SolverStepTemp, hkpConstraintChainMatrix6Triple, the
// jacobian classes, hkpVelocityAccumulatorOffset) are declared from the hkpConstraintSolver library's debug records
// (members, types, order, method signatures); the inline bodies (the schema's buffer getters, the accumulator
// lookup, hkSolver::applyImpulse and applyAngularImpulse) follow the SDK's unoptimized (hybrid) library object, which
// this source reproduces, and the release object. Only the function carries the packet's name.
namespace f3m_00a0e5d0 {

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
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::add3clobberW(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}
inline void hkVector4::sub3clobberW(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
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
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::_setMul3( const hkMatrix3& r, const hkVector4& v )
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2;
		t(1) = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2;
		t(2) = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2;
		t(3) = 0;
	}
inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	;
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
struct hkpSolverInfo;
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
void hkVector8::_setMul6(const hkMatrix6& a, const hkVector8& b )
{
	hkVector4 tmp[2];
	tmp[0] ._setMul3( a.m_m[0][0], b.m_lin );
	m_lin._setMul3( a.m_m[0][1], b.m_ang );
	tmp[1] ._setMul3( a.m_m[1][0], b.m_lin );
	m_ang._setMul3( a.m_m[1][1], b.m_ang );
	m_lin.add4(tmp[0]);
	m_ang.add4(tmp[1]);
}
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
class hkp2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_angular[2];
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		hkReal getAngularRhsSr() const;
		hkReal getAngularDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp2AngJacobian& jacB ) const;
};
class hkp1Lin2AngJacobian
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkp1Lin2AngJacobian), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		hkp2AngJacobian& as2AngJacobian_internal();
		void setRHS( hkReal v );
		inline const hkReal& getRHS() const { return m_linear0(3); }
		hkReal& getRHS();
		const hkSimdReal getRhsSr() const;
		hkReal getInvJacDiag() const;
		hkReal getInvJacDiagSr() const;
		void setInvJacDiag( hkReal v );
		hkReal getUserValue() const;
		hkReal getUserValueSr() const;
		void setUserValue( hkReal v );
		hkReal getDiag( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB ) const;
		hkReal getNonDiagOptimized( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagSameObjects( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
		hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject( const hkpVelocityAccumulator& mA, const hkp1Lin2AngJacobian& jacB ) const;
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpVelocityAccumulatorOffset), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkpVelocityAccumulatorOffset( const hkpVelocityAccumulator* base, const hkpVelocityAccumulator* accumulator );
		hkpVelocityAccumulatorOffset();
		inline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<const hkpVelocityAccumulator*>( reinterpret_cast<const char*>(base) + m_offset );
		}
		__forceinline hkpVelocityAccumulator& getAccumulator( hkpVelocityAccumulator* base )
		{
			return *reinterpret_cast<hkpVelocityAccumulator*>( reinterpret_cast<char*>(base) + m_offset );
		}
		unsigned m_offset;
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
struct hkpChainSolverInfo
{
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpChainSolverInfo), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
	__forceinline hkpChainSolverInfo( const hkpSolverInfo& solverInfo ) : m_solverInfo( solverInfo ) {}
	const hkpSolverInfo& m_solverInfo;
	hkPadSpu<int> m_numConstraints;
	hkPadSpu<hkReal> m_schemaTau;
	hkPadSpu<hkReal> m_schemaDamping;
	hkPadSpu<hkp1Lin2AngJacobian*> m_j;
	hkPadSpu<hkp2AngJacobian*> m_jAng;
	hkPadSpu<hkpVelocityAccumulatorOffset*> m_va;
	hkPadSpu<hkpVelocityAccumulator*> m_accumsBase;
	hkPadSpu<hkpConstraintChainMatrix6Triple*> m_triples;
	hkPadSpu<hkp3dAngularMotorSolverInfo*> m_motorsState;
	hkPadSpu<hkVector8*> m_gTempBuffer;
	hkPadSpu<hkVector8*> m_velocitiesBuffer;
};
class hkpJacobianSchema;
class hkpJacobianPoweredChainSchema
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpJacobianPoweredChainSchema), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		void initPoweredChainSchema( int numConstraints, hkpVelocityAccumulatorOffset* accumulators, hkReal tau, hkReal damping, hkp3dAngularMotorSolverInfo* motorsState, hkUint8* statusFlagsOutput );
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
		void* getEnd();
};
namespace hkSolver
{
struct SolverStepTemp
	{
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkSolver::SolverStepTemp), HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_CONSTRAINT_SOLVER); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		hkPadSpu<int> m_currentStep;
		hkPadSpu<hkReal> m_intregratePositions;
	};
__forceinline void __cdecl loadVelocityAccumulators( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl storeVelocityAccumulators( hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl applyImpulse( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyAngularImpulse( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
}
extern "C" void __cdecl hkPoweredChain_CalculateVelocities( const hkpChainSolverInfo& info, hkVector8* velocities );
extern "C" void __cdecl hkPoweredChain_OverwriteVelocityWithExplicitImpulse( int constraintIndex, int coordinateIndex, const hkp3dAngularMotorSolverInfo* motorsState, hkVector8* velocities );
extern "C" void __cdecl hkPoweredChain_SolveConstraintMatrix_ComputeVectorG( const hkpChainSolverInfo& info, hkVector8* g );
extern "C" void __cdecl hkPoweredChain_ScanAndEnableMotors( const hkpChainSolverInfo& info, int& constraintIndex, int& coordinateIndex, hkReal& impulse, hkp3dAngularMotorSolverInfo* motorsState );
extern "C" void __cdecl hkPoweredChain_ScanAndDisableMotors( const hkpChainSolverInfo& info, int& constraintIndex, int& coordinateIndex, hkReal& impulse, hkp3dAngularMotorSolverInfo* motorsState );
extern "C" void __cdecl hkPoweredChain_UpdateLuDecomposition( int constraintIndex, int numConstraints, hkp3dAngularMotorSolverInfo* motorsState, hkpConstraintChainMatrix6Triple* triples );
extern "C" void __cdecl hkPoweredChain_RestoreVelocityValue( int constraintIndex, int coordinateIndex, const hkpChainSolverInfo& info, hkVector8* velocities );
// pdb: hkSolver_solvePoweredChain | hkpSolver.obj | fnv360_0822_retail, objrun, medium
// pdb params: solverInfo, temp, accums, chain, sr
void __cdecl FUN_00a0e5d0( const hkpSolverInfo& solverInfo, const hkSolver::SolverStepTemp& temp, hkpVelocityAccumulator* accums, hkpJacobianPoweredChainSchema* chain, hkpSolverElemTemp* sr )
{
	hkpChainSolverInfo info( solverInfo );
	info.m_numConstraints = chain->m_numConstraints;
	info.m_schemaTau = chain->m_tau;
	info.m_schemaDamping = chain->m_damping;
	info.m_j = hkpJacobianPoweredChainSchema::getLinearJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ) );
	info.m_jAng = hkpJacobianPoweredChainSchema::getAngularJacobians( reinterpret_cast<hkpJacobianSchema*>( chain ), chain->m_numConstraints );
	info.m_va = chain->getAccumulatorOffsetsBase();
	info.m_accumsBase = accums;
	info.m_triples = chain->getMatrixBuffer();
	info.m_motorsState = chain->getChildConstraintStatusBase();
	info.m_gTempBuffer = chain->getTempBuffer();
	info.m_velocitiesBuffer = chain->getVelocityBuffer();
	{
		hkp2AngJacobian* jAngCurr = info.m_jAng;
		for ( int c = 0; c < info.m_numConstraints; c++ )
		{
			for ( int d = 0; d < 3; d++ )
			{
				hkReal rhs = jAngCurr->getAngularRhs();
				rhs += info.m_motorsState[c].m_motorInfos[d].m_velocity * temp.m_intregratePositions;
				jAngCurr->setAngularRhs( rhs );
				jAngCurr++;
			}
		}
	}
	hkPoweredChain_CalculateVelocities( info, info.m_velocitiesBuffer );
	for ( int c = 0; c < info.m_numConstraints; c++ )
	{
		for ( int d = 0; d < 3; d++ )
		{
			if ( info.m_motorsState[c].getState( d ) == hkp3dAngularMotorSolverInfo::MOTOR_DISABLED )
			{
				hkVector8& imp = info.m_velocitiesBuffer[c];
				imp.m_ang( d ) = 0.0f;
			}
			else if ( info.m_motorsState[c].getState( d ) != hkp3dAngularMotorSolverInfo::MOTOR_NOT_BROKEN )
			{
				hkPoweredChain_OverwriteVelocityWithExplicitImpulse( c, d, info.m_motorsState, info.m_velocitiesBuffer );
			}
		}
	}
	for ( ;; )
	{
		hkPoweredChain_SolveConstraintMatrix_ComputeVectorG( info, info.m_gTempBuffer );
		int modifiedConstraintIndex = -1;
		int modifiedCoordinateIndex = -1;
		hkReal impulse = 0.0f;
		hkPoweredChain_ScanAndEnableMotors( info, modifiedConstraintIndex, modifiedCoordinateIndex, impulse, info.m_motorsState );
		if ( modifiedConstraintIndex >= 0 )
		{
			hkPoweredChain_UpdateLuDecomposition( modifiedConstraintIndex, info.m_numConstraints, info.m_motorsState, info.m_triples );
			hkPoweredChain_RestoreVelocityValue( modifiedConstraintIndex, modifiedCoordinateIndex, info, info.m_velocitiesBuffer );
			continue;
		}
		else
		{
			break;
		}
	}
	for ( ;; )
	{
		hkPoweredChain_SolveConstraintMatrix_ComputeVectorG( info, info.m_gTempBuffer );
		int modifiedConstraintIndex = -1;
		int modifiedCoordinateIndex = -1;
		hkReal impulse = 0.0f;
		hkPoweredChain_ScanAndDisableMotors( info, modifiedConstraintIndex, modifiedCoordinateIndex, impulse, info.m_motorsState );
		if ( modifiedConstraintIndex >= 0 )
		{
			hkPoweredChain_UpdateLuDecomposition( modifiedConstraintIndex, info.m_numConstraints, info.m_motorsState, info.m_triples );
			hkPoweredChain_OverwriteVelocityWithExplicitImpulse( modifiedConstraintIndex, modifiedCoordinateIndex, info.m_motorsState, info.m_velocitiesBuffer );
			continue;
		}
		else
		{
			break;
		}
	}
	{
		hkVector8* g = info.m_gTempBuffer + 1;
		hkVector8 imp; imp.setZero8();
		for ( int gi = info.m_numConstraints - 1; gi >= 0; gi-- )
		{
			const int jIdx = gi * 3;
			const int srIdx = gi * 6;
			hkVector8 tmp; tmp._setMul6( info.m_triples[gi].m_upper, imp );
			imp.setSub8( g[gi], tmp );
			hkpVelocityAccumulator* __restrict raA = &info.m_va[gi].getAccumulator( accums );
			hkpVelocityAccumulator* __restrict raB = &info.m_va[gi + 1].getAccumulator( accums );
			hkSolver::loadVelocityAccumulators( *raA, *raB );
			hkSolver::applyImpulse( imp.m_lin.getSimdAt( 0 ), info.m_j[jIdx], *raA, *raB, sr[srIdx] );
			hkSolver::applyImpulse( imp.m_lin.getSimdAt( 1 ), info.m_j[jIdx + 1], *raA, *raB, sr[srIdx + 1] );
			hkSolver::applyImpulse( imp.m_lin.getSimdAt( 2 ), info.m_j[jIdx + 2], *raA, *raB, sr[srIdx + 2] );
			hkSolver::applyAngularImpulse( imp.m_ang.getSimdAt( 0 ), info.m_jAng[jIdx], *raA, *raB, sr[srIdx + 3] );
			hkSolver::applyAngularImpulse( imp.m_ang.getSimdAt( 1 ), info.m_jAng[jIdx + 1], *raA, *raB, sr[srIdx + 4] );
			hkSolver::applyAngularImpulse( imp.m_ang.getSimdAt( 2 ), info.m_jAng[jIdx + 2], *raA, *raB, sr[srIdx + 5] );
			hkSolver::storeVelocityAccumulators( *raA, *raB );
		}
	}
}

}  // namespace f3m_00a0e5d0
}   // namespace f3m_00a0e5d0

// @f3 0x00a0d700 (community match, verified in this file)
// 0x00a0d700: hkSolveIntegrateVelocitiesByTheSteps(const hkpSolverInfo& info, int currentSolverStep,
// hkpVelocityAccumulator* accumulators, hkpVelocityAccumulator* accumulatorsEnd, hkBool& outSolveFinished) of Havok
// 5.5.0 (hkpConstraintSolver, hkpSolver.cpp, compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-). Integrates the velocity
// accumulators after a solver step: the file's hkSolver::integrateVelocities walks the accumulators by type (no
// gravity / keyframed / rigid body runs / end), integrateVelocityAccumulator clamps invalid velocities and damps or
// zeroes slow ones (by the deactivation class), updateSumVelocities accumulates the step's velocity sums and, on the
// last step, scales them. This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with
// the real headers, and the preprocessed source was cut down mechanically to the declarations the function's code
// needs (whole declarations by work\_havok\hkpipe\hkreduce.py, every cut checked byte for byte); those declarations
// are the SDK's text with its names. The file's own helpers follow the SDK's unoptimized (hybrid) library object,
// with one difference that the game's code shows: on the last step updateSumVelocities scales the two velocity sums
// with setMul4( sum, sumVelFactor ) (lane times factor, the lane loaded first on every lane); the SDK's library
// object fits mul4( sumVelFactor ) there. The else arm after 'else if ( 1 )' in integrateVelocityAccumulator is
// compiled out but is needed: without it the code is 32 bytes shorter.
namespace f3m_00a0d700 {

typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};
typedef unsigned __w64 hk_size_t;
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
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
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
inline hkReal __cdecl fabs(hkReal r) { return fabsf(r); }
template <typename T>
	inline T __cdecl min2( T x, T y)
	{
		return x < y ? x : y;
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
class hkTransform
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkTransform), HK_MEMORY_CLASS_MATH); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_MATH); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
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
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
	;
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
inline void hkVector4::setAll(hkReal a)
{
	x = a;
	y = a;
	z = a;
	w = a;
}
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
	z = v0.z - v1.z;
	w = v0.w - v1.w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline void hkVector4::addMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x += r * a.x;
	y += r * a.y;
	z += r * a.z;
	w += r * a.w;
}
inline void hkVector4::subMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x -= r * a.x;
	y -= r * a.y;
	z -= r * a.z;
	w -= r * a.w;
}
inline hkVector4Comparison hkVector4::compareLessThan4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline hkVector4Comparison hkVector4::compareEqual4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x==a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y==a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z==a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w==a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline hkVector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<=a.x) ? hkVector4Comparison::MASK_X : 0) |
		((y<=a.y) ? hkVector4Comparison::MASK_Y : 0) |
		((z<=a.z) ? hkVector4Comparison::MASK_Z : 0) |
		((w<=a.w) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}
inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
}
inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline hkSimdReal hkVector4::normalizeWithLength3()
	{
		hkReal len = this->length3();
		this->mul4( (1.0f)/len );
		;
		return len;
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
const hkVector4& hkTransform::getColumn(int x) const
{
	return m_rotation.getColumn(x);
}
const hkTransform& __cdecl hkTransform::getIdentity()
{
	extern hkReal hkTransformIdentity[];
	return reinterpret_cast<const hkTransform&>(hkTransformIdentity);
}
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
extern "C"
{
static const hkQuadReal maxVelf = {1e6f,1e6f,1e6f,1e6f};
}
namespace hkSolver
{
__forceinline void __cdecl integrateVelocityAccumulator( const hkpSolverInfo& info, hkpVelocityAccumulator* accum )
	{
		const hkpSolverInfo::DeactivationInfo& di = info.m_deactivationInfo[ accum->m_deactivationClass ];
		hkVector4 absLinVel; absLinVel.setAbs4( accum->m_linearVel );
		hkVector4 absAngVel; absAngVel.setAbs4( accum->m_angularVel );
		hkVector4 sum;
		sum.setMul4( di.m_linearVelocityThresholdInv, absLinVel );
		sum.addMul4( di.m_angularVelocityThresholdInv, absAngVel );
		hkVector4 one; one.setAll( info.m_one );
		const hkVector4& maxVel = reinterpret_cast<const hkVector4&>( maxVelf );
		int mask = absLinVel.compareLessThan4( maxVel ).getMask() & absAngVel.compareLessThan4( maxVel ).getMask();
		mask &= accum->m_linearVel.compareEqual4( accum->m_linearVel ).getMask() & accum->m_angularVel.compareEqual4( accum->m_angularVel ).getMask();
		if ( ( mask & hkVector4Comparison::MASK_XYZ ) != hkVector4Comparison::MASK_XYZ )
		{
			accum->m_linearVel = hkTransform::getIdentity().getColumn(0);
			accum->m_angularVel = hkTransform::getIdentity().getColumn(0);
		}
		if ( sum.compareLessThanEqual4( one ).allAreSet( hkVector4Comparison::MASK_XYZ ) )
		{
			hkVector4 threshold; threshold.setAll( di.m_relativeSleepVelocityThreshold );
			if ( sum.compareLessThanEqual4( threshold ).allAreSet( hkVector4Comparison::MASK_XYZ ) )
			{
				accum->m_angularVel.setZero4();
				accum->m_linearVel.setZero4();
				return;
			}
			else if ( 1 )
			{
				accum->m_angularVel.mul4( di.m_slowObjectVelocityMultiplier );
				accum->m_linearVel.mul4( di.m_slowObjectVelocityMultiplier );
			}
			else
			{
				hkVector4 linNorm = accum->m_linearVel;
				hkReal linLen = linNorm.normalizeWithLength3();
				if ( linLen > 1.192092896e-07F )
				{
					linLen = hkMath::min2( 0.001f, linLen );
					accum->m_linearVel.subMul4( linLen, linNorm );
				}
				else
				{
					accum->m_linearVel.setZero4();
				}
				hkVector4 angNorm = accum->m_angularVel;
				hkReal angLen = angNorm.normalizeWithLength3();
				if ( angLen > 1.192092896e-07F )
				{
					angLen = hkMath::min2( 0.01f, angLen );
					accum->m_angularVel.subMul4( angLen, angNorm );
				}
				else
				{
					accum->m_angularVel.setZero4();
				}
			}
		}
	}
static __forceinline void __cdecl updateSumVelocities( const hkpSolverInfo& info, const hkVector4& gravity, bool isLast, const hkVector4& sumVelFactor, hkpVelocityAccumulator* accum )
	{
		hkVector4 linVel; linVel.setSub4( accum->m_linearVel, accum->getSumLinearVel() );
		hkVector4 angVel; angVel.setSub4( accum->m_angularVel, accum->getSumAngularVel() );
		accum->getSumLinearVel().addMul4( info.m_integrateVelocityFactor.getSimdAt(0), linVel );
		accum->getSumAngularVel().addMul4( info.m_integrateVelocityFactor.getSimdAt(0), angVel );
		if ( !isLast )
		{
			linVel.add4( accum->getSumLinearVel() );
			angVel.add4( accum->getSumAngularVel() );
			linVel.add4( gravity );
		}
		else
		{
			accum->getSumLinearVel().setMul4( accum->getSumLinearVel(), sumVelFactor );
			accum->getSumAngularVel().setMul4( accum->getSumAngularVel(), sumVelFactor );
		}
		accum->m_linearVel = linVel;
		accum->m_angularVel = angVel;
	}
static __forceinline void __cdecl integrateVelocities( const hkpSolverInfo& info, const hkVector4& gravity, bool isLast, const hkVector4& sumVelFactor, hkpVelocityAccumulator* accum, hkpVelocityAccumulator* accumEnd )
	{
		if ( !accumEnd )
		{
			accumEnd = reinterpret_cast<hkpVelocityAccumulator*>( -1 );
		}
		while ( accum < accumEnd )
		{
			switch ( accum->m_type )
			{
				case hkpVelocityAccumulator::HK_NO_GRAVITY_RIGID_BODY:
					integrateVelocityAccumulator( info, accum );
				case hkpVelocityAccumulator::HK_KEYFRAMED_RIGID_BODY:
					updateSumVelocities( info, hkVector4::getZero(), isLast, sumVelFactor, accum );
					accum++;
					break;
				case hkpVelocityAccumulator::HK_RIGID_BODY:
					do
					{
						integrateVelocityAccumulator( info, accum );
						updateSumVelocities( info, gravity, isLast, sumVelFactor, accum );
						accum++;
					}
					while ( accum->m_type == hkpVelocityAccumulator::HK_RIGID_BODY && accum < accumEnd );
					break;
				case hkpVelocityAccumulator::HK_END:
					return;
				default:
					;
					break;
			}
		}
	}
}
// pdb: hkSolveIntegrateVelocitiesByTheSteps | hkpSolver.obj | fnv360_0822_retail, call_seq, medium
// pdb params: info, currentSolverStep, accumulators, accumulatorsEnd, outSolveFinished
int __cdecl FUN_00a0d700( const hkpSolverInfo& info, int currentSolverStep, hkpVelocityAccumulator* accumulators, hkpVelocityAccumulator* accumulatorsEnd, hkBool& outSolveFinished )
{
	hkVector4 gravity = info.m_globalAccelerationPerSubStep;
	hkVector4 sumVelFactor; sumVelFactor.setAll( info.m_invNumSteps * info.m_invIntegrateVelocityFactor(0) );
	bool isLast = false;
	outSolveFinished = false;
	if ( currentSolverStep >= info.m_numSteps - 1 )
	{
		isLast = true;
		outSolveFinished = true;
	}
	hkSolver::integrateVelocities( info, gravity, isLast, sumVelFactor, accumulators, accumulatorsEnd );
	return 1;
}

}  // namespace f3m_00a0d700

// 0x00a0b990: copy of the community match in f3blk_00a00000_o2.cpp, as a stand-in body (not a match here): the solver functions' frames depend on what the compiler learns from it (19 Nov 2026)
namespace f3m_00a0b990 {
// Best measured flags: /MT /O2 /GS /EHsc /Gy (not the pack's listed flags).
namespace f3m_00a0b990 {
// Fake match: this scalar wrapper preserves the candidate's inlined float rounding and temporary form.
struct S0a0b990_Scalar { float value; S0a0b990_Scalar(float f) : value(f) {} };
union S0a0b990_SolverSlot { float lambda; int bodyOffset; };
struct __declspec(align(16)) S0a0b990_Vec {
    float x;
    float y;
    float z;
    float w;

    void setSub3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
    void setAdd3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; }
    void setMul3(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = b.x * a.x; y = b.y * a.y; z = b.z * a.z; }
    void setMul3(const S0a0b990_Vec& a, float s) { x = a.x * s; y = a.y * s; z = a.z * s; }
    void setMul3r(const S0a0b990_Vec& a, const float& s) { x = a.x * s; y = a.y * s; z = a.z * s; }
    void mul3r(const S0a0b990_Vec& a) { x *= a.x; y *= a.y; z *= a.z; }
    void setMul4(const S0a0b990_Vec& a, const S0a0b990_Scalar& factor) { x = a.x * factor.value; y = a.y * factor.value; z = a.z * factor.value; w = a.w * factor.value; }
    void add3(const S0a0b990_Vec& a) { x += a.x; y += a.y; z += a.z; }
    void sub3(const S0a0b990_Vec& a) { x -= a.x; y -= a.y; z -= a.z; }
    void mul3(const S0a0b990_Vec& a) { x = a.x * x; y = a.y * y; z = a.z * z; }
    void mul3(float s) { x *= s; y *= s; z *= s; }
    void setSub4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    void setAdd4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    void setMul4(const S0a0b990_Vec& a, const S0a0b990_Vec& b) { x = a.x * b.x; y = a.y * b.y; z = a.z * b.z; w = a.w * b.w; }
    void add4(const S0a0b990_Vec& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    void mul4(const S0a0b990_Vec& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    void mul4(const S0a0b990_Scalar& factor) { float s = factor.value; x *= s; y *= s; z *= s; w *= s; }
    float horizontalAdd3() const { return x + y + z; }
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
};

struct S0a0b990_Accum {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S0a0b990_Vec linVel;
    S0a0b990_Vec angVel;
    S0a0b990_Vec invMasses;
    S0a0b990_Vec linVel0;
    S0a0b990_Vec angVel0;
};

struct S0a0b990_Jac {
    S0a0b990_Vec lin;
    S0a0b990_Vec angA;
    S0a0b990_Vec angB;

    __forceinline void calcJv(const S0a0b990_Vec& linA, const S0a0b990_Vec& angA0,
                              const S0a0b990_Vec& linB, const S0a0b990_Vec& angB0, S0a0b990_Vec& out) const
    {
        S0a0b990_Vec l;
        l.setSub4(linA, linB);
        S0a0b990_Vec a;
        a.setMul4(angA0, angA);
        S0a0b990_Vec b;
        b.setMul4(angB0, angB);
        l.mul4(lin);
        a.add4(b);
        out.setAdd4(a, l);
    }
};

struct S0a0b990_Diag {
    float lower;
    float diag;
    float upper;
};

struct S0a0b990_Chain {
    __forceinline unsigned short getnumLinks() {return numLinks;}
    unsigned short unk00;
    unsigned short numLinks;
    float unk04;
    float tau;
    float damping;
    S0a0b990_Jac jacs[1];
};

struct S0a0b990_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    float invDeltaTime;
};

}
using namespace f3m_00a0b990;
// Fake match: the array view steers the inlined subscript's operand ranking.
struct FloatArray { float* data; FloatArray(float* p):data(p){} float& operator[](int i)const{return data[i];} };

static __forceinline void mulLanes(S0a0b990_Vec& v, const S0a0b990_Vec& m, float s) { v.x = m.x * s; v.y = m.y * s; v.z = m.z * s; v.w = m.w * s; }

void FUN_00a0b990(S0a0b990_Info* info, void* unused, char* accums, S0a0b990_Chain* chain, float* impulses)
{
    S0a0b990_Jac* jacs = chain->jacs;
    int* offsets = (int*)((char*)chain->jacs + chain->getnumLinks() * (sizeof(S0a0b990_Jac) + sizeof(S0a0b990_Diag) + sizeof(float)) + sizeof(float));
    S0a0b990_Diag* diags = (S0a0b990_Diag*)((char*)chain->jacs + chain->getnumLinks() * sizeof(S0a0b990_Jac));
    FloatArray lam = (float*)((char*)chain->jacs + chain->getnumLinks() * (sizeof(S0a0b990_Jac) + sizeof(S0a0b990_Diag)) + sizeof(float));
    int n = chain->getnumLinks();

    lam[-1] = 0.0f;
    int i;
    for (i = 0; i < n; i++) {
        float s = chain->tau;
        int oa = offsets[i];
        int ob = offsets[i + 1];
        S0a0b990_Accum* a = (S0a0b990_Accum*)(accums + oa);
        S0a0b990_Accum* b = (S0a0b990_Accum*)(accums + ob);
        S0a0b990_Vec dLinA; dLinA.setSub4(a->linVel, a->linVel0);
        S0a0b990_Vec dAngA; dAngA.setSub4(a->angVel, a->angVel0);
        S0a0b990_Vec dLinB; dLinB.setSub4(b->linVel, b->linVel0);
        S0a0b990_Vec dAngB; dAngB.setSub4(b->angVel, b->angVel0);
        S0a0b990_Vec r1;
        jacs[i].calcJv(dLinA, dAngA, dLinB, dAngB, r1);
        S0a0b990_Vec r2;
        S0a0b990_Vec linA0 = a->linVel0;
        S0a0b990_Vec angA0 = a->angVel0;
        S0a0b990_Vec linB0 = b->linVel0;
        S0a0b990_Vec angB0 = b->angVel0;
        jacs[i].calcJv(linA0, angA0, linB0, angB0, r2);
        r2.mul4(info->invDeltaTime * s);
        float c = chain->damping;
        r1.mul4(c);
        S0a0b990_Vec sum;
        sum.setAdd4(r2, r1);
        float rhs = s * jacs[i].lin.w - sum.horizontalAdd3();
        lam[i] = (rhs - lam[i - 1] * diags[i].lower) / diags[i].diag;
    }

    float x = 0.0f;
    // Guess at the source: the impulses use a second counter j that runs with i. VC8 places each strength-reduced
    // cursor update right after the update of the counter it derives from and merges the two counters afterwards,
    // which gives the original order of the cursor updates (sub esi,4 before sub edx,0x30) with no extra code.
    int j;
    for (j = n - 1, i = j; i >= 0; i--, j--) {
        float up = diags[i].upper;
        x = lam[i] - x * up;
        int oa = offsets[i];
        int ob = offsets[i + 1];
        S0a0b990_Accum* a = (S0a0b990_Accum*)(accums + oa);
        S0a0b990_Accum* b = (S0a0b990_Accum*)(accums + ob);
        S0a0b990_Vec va; mulLanes(va, a->invMasses, x);
        S0a0b990_Vec vb; mulLanes(vb, b->invMasses, x);
        S0a0b990_Vec la; la.setMul3r(jacs[i].lin, va.w);
        S0a0b990_Vec lb; lb.setMul3r(jacs[i].lin, vb.w);
        // Guess: the lane access paths (operator() or member) set the x87 operand order of each add.
        a->linVel(0) += la(0); a->linVel(1) += la.y; a->linVel(2) += la(2);
        b->linVel.x -= lb.x; b->linVel.y -= lb.y; b->linVel.z -= lb.z;
        va.mul3r(jacs[i].angA);
        vb.mul3r(jacs[i].angB);
        a->angVel.add3(va);
        S0a0b990_Vec& bav = b->angVel;   // guess: the alias sets the operand order of the b->angVel.x add
        bav.add3(vb);
        impulses[j] += x;
    }
}

}   // namespace f3m_00a0b990

// 0x00a0c070: copy of the community match in f3blk_00a00000_o2.cpp, as a stand-in body (not a match here): the solver functions' frames depend on what the compiler learns from it (19 Nov 2026)
namespace f3m_00a0c070 {
namespace f3_a0c070 {

typedef float Real;
typedef float SimdReal;
typedef float SimdRealParameter;

class Matrix3;

class __declspec(align(16)) Vector4
{
public:
    Real x, y, z, w;

    inline Vector4() {}
    inline Real& operator()(int i) { return (&x)[i]; }
    inline const Real& operator()(int i) const { return (&x)[i]; }
    inline SimdReal getSimdAt(int i) const { return (&x)[i]; }
    inline void setZero4() { x = y = z = w = 0.0f; }
    inline void setSub4(const Vector4& a, const Vector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    inline void setAdd4(const Vector4& a, const Vector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    inline void setMul4(const Vector4& a, const Vector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    inline void setMul4(SimdRealParameter rs, const Vector4& a)
    {
        Real r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    inline void mul4(const Vector4& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    inline void mul4(SimdRealParameter rs)
    {
        Real s = rs;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    inline void add4(const Vector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    inline void add3clobberW(const Vector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
    }
    inline void sub3clobberW(const Vector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
    }
    inline void setBroadcast3clobberW(const Vector4& v, int i)
    {
        Real r = v(i);
        x = r;
        y = r;
        z = r;
    }
    inline SimdReal horizontalAdd3() const { return x + y + z; }
    __forceinline void _setMul3(const Matrix3& r, const Vector4& v);
};

class Matrix3
{
public:
    Vector4 m_col0;
    Vector4 m_col1;
    Vector4 m_col2;
    inline Real& operator()(int r, int c) { return (&m_col0)[c](r); }
    inline const Real& operator()(int r, int c) const { return (&m_col0)[c](r); }
};

__forceinline void Vector4::_setMul3(const Matrix3& r, const Vector4& v)
{
    Real v0 = v.x;
    Real v1 = v.y;
    Real v2 = v.z;

    Vector4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

template <class T> inline T* AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

class VelocityAccumulator
{
public:
    Vector4 m_unk00;
    Vector4 m_linearVel;
    Vector4 m_angularVel;
    Vector4 m_invMasses;
    Vector4 m_scratch0;
    Vector4 m_scratch1;
    inline const Vector4& getSumLinearVel() const { return m_scratch0; }
    inline const Vector4& getSumAngularVel() const { return m_scratch1; }
};

class VelocityAccumulatorOffset
{
public:
    inline VelocityAccumulator& getAccumulator(VelocityAccumulator* base) { return *AddByteOffset(base, m_offset); }
    int m_offset;
};

class Lin2AngJacobian
{
public:
    inline Real getRHS() const { return m_linear0(3); }
    Vector4 m_linear0;
    Vector4 m_angular[2];
};

struct ChainMatrixTriple
{
    Matrix3 m_lower;
    Matrix3 m_diagonalInv;
    Matrix3 m_upper;
};

struct BallSocketChainSchema
{
    inline static Lin2AngJacobian* getJacobians(BallSocketChainSchema* s)
    {
        return reinterpret_cast<Lin2AngJacobian*>(s + 1);
    }
    inline ChainMatrixTriple* getMatrixBuffer()
    {
        return reinterpret_cast<ChainMatrixTriple*>(AddByteOffset(getJacobians(this), m_numConstraints * 3 * sizeof(Lin2AngJacobian)));
    }
    inline Vector4* getTempBuffer()
    {
        return reinterpret_cast<Vector4*>(AddByteOffset(getMatrixBuffer(), m_numConstraints * sizeof(ChainMatrixTriple)));
    }
    inline VelocityAccumulatorOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<VelocityAccumulatorOffset*>(AddByteOffset(getTempBuffer(), (m_numConstraints + 1) * sizeof(Vector4)));
    }
    short m_type;
    unsigned short m_numConstraints;
    int m_elementCount;
    Real m_tau;
    Real m_damping;
};

struct SolverInfo
{
    Vector4 m_unk00;
    Vector4 m_unk10;
    Vector4 m_unk20;
    Vector4 m_unk30;
    Vector4 m_integrateVelocityFactor;
};

struct SolverStepTemp
{
    int m_unused;
};

struct SolverElemTemp
{
    Real m_impulseApplied;
};

static __forceinline SimdReal getLinearDv0UserTauWithCustomRhs(const Lin2AngJacobian& jac, const VelocityAccumulator& mA, const VelocityAccumulator& mB, const SolverInfo& info, Real tau, Real damping, Real customRhs)
{
    Vector4 vel4;
    {
        Vector4 linVelA; linVelA.setSub4(mA.m_linearVel, mA.getSumLinearVel());
        Vector4 angVelA; angVelA.setSub4(mA.m_angularVel, mA.getSumAngularVel());
        Vector4 linVelB; linVelB.setSub4(mB.m_linearVel, mB.getSumLinearVel());
        Vector4 angVelB; angVelB.setSub4(mB.m_angularVel, mB.getSumAngularVel());
        Vector4 c; c.setSub4(linVelA, linVelB);
        Vector4 a; a.setMul4(angVelA, jac.m_angular[0]);
        Vector4 b; b.setMul4(angVelB, jac.m_angular[1]);
        c.mul4(jac.m_linear0);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    Vector4 svel4;
    {
        Vector4 linVelA = mA.getSumLinearVel();
        Vector4 angVelA = mA.getSumAngularVel();
        Vector4 linVelB = mB.getSumLinearVel();
        Vector4 angVelB = mB.getSumAngularVel();
        Vector4 c; c.setSub4(linVelA, linVelB);
        Vector4 a; a.setMul4(angVelA, jac.m_angular[0]);
        Vector4 b; b.setMul4(angVelB, jac.m_angular[1]);
        c.mul4(jac.m_linear0);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    const Real tf = info.m_integrateVelocityFactor(0) * tau;
    svel4.mul4(tf);
    vel4.mul4(damping);
    Vector4 rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    SimdReal ru = rhsUpdate.horizontalAdd3();
    SimdReal dv = customRhs * tau - ru;
    return dv;
}

static __forceinline SimdReal getLinearDv0UserTau(const Lin2AngJacobian& jac, const VelocityAccumulator& mA, const VelocityAccumulator& mB, const SolverInfo& info, Real tau, Real damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}


static __forceinline void applyImpulse(SimdRealParameter imp, const Lin2AngJacobian& jac, VelocityAccumulator& mA, VelocityAccumulator& mB, SolverElemTemp& sr)
{
    Vector4 impA; impA.setMul4(imp, mA.m_invMasses);
    Vector4 impB; impB.setMul4(imp, mB.m_invMasses);
    Vector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    Vector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_linear0);
    negImpLinB.mul4(jac.m_linear0);
    mA.m_linearVel.add3clobberW(impLinA);
    mB.m_linearVel.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_angular[0]);
    impB.mul4(jac.m_angular[1]);
    mA.m_angularVel.add3clobberW(impA);
    mB.m_angularVel.add3clobberW(impB);
    Real acc = sr.m_impulseApplied;
    sr.m_impulseApplied = acc + imp;
}

}

using namespace f3_a0c070;

void __cdecl FUN_00a0c070(const SolverInfo& info, const SolverStepTemp& temp, VelocityAccumulator* accums, BallSocketChainSchema* chain, SolverElemTemp* sr)
{
    int numConstraints = chain->m_numConstraints;
    Lin2AngJacobian* j = BallSocketChainSchema::getJacobians(chain);
    VelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
    ChainMatrixTriple* triple = chain->getMatrixBuffer();
    Vector4* g = chain->getTempBuffer() + 1;
    g[-1].setZero4();
    {
        for (int gi = 0; gi < numConstraints; j += 3, gi++)
        {
            VelocityAccumulator* raA = &va[gi].getAccumulator(accums);
            VelocityAccumulator* raB = &va[gi + 1].getAccumulator(accums);
            Vector4 dv;
            dv(0) = getLinearDv0UserTau(j[0], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(1) = getLinearDv0UserTau(j[1], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(2) = getLinearDv0UserTau(j[2], *raA, *raB, info, chain->m_tau, chain->m_damping);
            dv(3) = 0.0f;
            Vector4 tmp;
            tmp._setMul3(triple[gi].m_lower, g[gi - 1]);
            tmp.setSub4(dv, tmp);
            g[gi]._setMul3(triple[gi].m_diagonalInv, tmp);
        }
    }
    {
        Vector4 imp; imp.setZero4();
        j = BallSocketChainSchema::getJacobians(chain);
        for (int gi = numConstraints - 1; gi >= 0; gi--)
        {
            VelocityAccumulator* raA = &va[gi].getAccumulator(accums);
            VelocityAccumulator* raB = &va[gi + 1].getAccumulator(accums);
            int jIdx = gi * 3;
            Vector4 tmp;
            tmp._setMul3(triple[gi].m_upper, imp);
            imp.setSub4(g[gi], tmp);
            applyImpulse(imp(0), j[jIdx], *raA, *raB, sr[jIdx]);
            applyImpulse(imp(1), j[jIdx + 1], *raA, *raB, sr[jIdx + 1]);
            applyImpulse(imp(2), j[jIdx + 2], *raA, *raB, sr[jIdx + 2]);
        }
    }
}
}   // namespace f3m_00a0c070

// @f3 0x00a0f4d0 (community match, verified in this file)
namespace f3m_00a0f4d0 {
// 0x00a0f4d0: hkSolveStepJacobians(const hkpSolverInfo& info, const hkpJacobianSchema* schemas, hkpVelocityAccumulator*
// accumulators, hkpSolverElemTemp* tmp) of Havok 5.5.0 (hkpConstraintSolver, hkpSolver.cpp, the game's build: /MT /Ox
// /Ob1 /Oi /Ot /GF /GS-). One solver pass over a constraint list's jacobian schemas with a fresh step temp (step 0, no
// position integration): hkSolver::stepJacobian loads a body pair at each header schema and hands every following
// schema by type to the file's solve helpers.
// Built from the Havok 5.5.0 SDK's own headers (compiled with them, cut down to the declarations the code needs); the
// SDK ships no hkpSolver.cpp, so the solve helpers and the loop are written here.
// The loop's default case holds Havok's HK_BREAKPOINT: written with the pack's own helper fnv_Breakpoint().
// The three chain solvers are siblings in the game's unit (FUN_00a0b990 stiff spring, FUN_00a0c070 ball and socket,
// FUN_00a0e5d0 powered), and the caller's frame depends on the compiler seeing their bodies (callee summaries), so
// all three are called through the unit's own definitions.
namespace f3m_00a0f4d0 {

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
template <typename TYPE>
__forceinline TYPE* __cdecl hkSelect( int select, TYPE* pairA, TYPE* pairB )
{
	hkUlong ua = hkUlong(pairA);
	hkUlong ub = hkUlong(pairB);
	return reinterpret_cast<TYPE*>( ua ^ ((ua^ub)&(-select)) );
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
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
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
inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
	}
}
class hkQuaternion;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkQsTransform;
class hkp1Lin2AngJacobian;
class hkVector4;
namespace hkSolver { void __cdecl calcLinearVel4_s( const hkp1Lin2AngJacobian& jac, const hkVector4& linVelA, const hkVector4& angVelA, const hkVector4& linVelB, const hkVector4& angVelB, hkVector4& out ); }
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
		__forceinline void sub3_v0op(const hkVector4& a);
		static __forceinline void __cdecl r74_fix(hkSimdRealParameter imp, const hkVector4& invB, hkVector4& impB, const hkVector4& impA, hkVector4& impLinA, hkVector4& negImpLinB, hkVector4& lvA, const hkVector4& lin0){ impB.setMul4(imp, invB); impLinA.setBroadcast3clobberW(impA, 3); negImpLinB.setBroadcast3clobberW(impB, 3); impLinA.mul4(lin0); negImpLinB.setMul4(negImpLinB, lin0); lvA.add3clobberW(impLinA); }
		static __forceinline void __cdecl mv3_L0(hkVector4& d, const hkVector4& a, const hkVector4& b){ d.x=a.x*b.x; d.y=a.y*b.y; d.z=a.z*b.z; d.w=a.w*b.w; }
		static __forceinline void __cdecl mv3_L1(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L0(d, a, b); }
		static __forceinline void __cdecl mv3_L2(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L1(d, a, b); }
		static __forceinline void __cdecl mv3_L3(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L2(d, a, b); }
		static __forceinline void __cdecl mv3_L4(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L3(d, a, b); }
		static __forceinline void __cdecl mv3_L5(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L4(d, a, b); }
		static __forceinline void __cdecl mv3_L6(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L5(d, a, b); }
		static __forceinline void __cdecl mv3_L7(hkVector4& d, const hkVector4& a, const hkVector4& b){ mv3_L6(d, a, b); }
		static __forceinline void __cdecl ms3_L0(hkVector4& d, const hkVector4& a, hkSimdRealParameter rs){ hkReal s=hkReal(rs); d.x=a.x*s; d.y=a.y*s; d.z=a.z*s; d.w=a.w*s; }
		static __forceinline void __cdecl ms3_L1(hkVector4& d, const hkVector4& a, hkSimdRealParameter rs){ ms3_L0(d, a, rs); }
		__forceinline void s3_001(const hkVector4& v){ x=x-v.x; y=y-v.y; z=(z-v.z); }
		__forceinline void m4_3000(const hkVector4& a){ x=(((x*a.x))); y=y*a.y; z=z*a.z; w=w*a.w; }
		static __forceinline void __cdecl sm4_vv_c_dba(hkVector4& d, const hkVector4& b, const hkVector4& a){ d.x=a.x*b.x; d.y=a.y*b.y; d.z=a.z*b.z; d.w=a.w*b.w; }
		static __forceinline void __cdecl mul4_c_ba(const hkVector4& a, hkVector4& d){ d.x*=a.x; d.y*=a.y; d.z*=a.z; d.w*=a.w; }
		static __forceinline void __cdecl mul4_s_ba(hkSimdRealParameter rs, hkVector4& d){ hkReal s=hkReal(rs); d.x=s*d.x; d.y=s*d.y; d.z=s*d.z; d.w=s*d.w; }
		__forceinline void setAdd4_clean(const hkVector4& v0, const hkVector4& v1){ x=v0.x+v1.x; y=v0.y+v1.y; z=v0.z+v1.z; w=v0.w+v1.w; }
		__forceinline void setMul3_now(const hkVector4& a, const hkVector4& b){ x=a.x*b.x; y=a.y*b.y; z=a.z*b.z; }
		__forceinline void add3_now(const hkVector4& a){ x=x+a.x; y=y+a.y; z=z+a.z; }
		__forceinline void a3_100(const hkVector4& v){ x=(x+v.x); y=y+v.y; z=z+v.z; }
		__forceinline void a3_200(const hkVector4& v){ x=((x+v.x)); y=y+v.y; z=z+v.z; }
		__forceinline void a3_010(const hkVector4& v){ x=x+v.x; y=(y+v.y); z=z+v.z; }
		__forceinline void a3_003(const hkVector4& v){ x=x+v.x; y=y+v.y; z=(((z+v.z))); }
		__forceinline void a3_002(const hkVector4& v){ x=x+v.x; y=y+v.y; z=((z+v.z)); }
		__forceinline void a3_130(const hkVector4& v){ x=(x+v.x); y=(((y+v.y))); z=z+v.z; }
		__forceinline void a3_013(const hkVector4& v){ x=x+v.x; y=(y+v.y); z=(((z+v.z))); }
		__forceinline void add4_0130(const hkVector4& v){ x=x+v.x; y=(y+v.y); z=(((z+v.z))); w=w+v.w; }
		__forceinline void add4_0030(const hkVector4& v){ x=x+v.x; y=y+v.y; z=(((z+v.z))); w=w+v.w; }
		__forceinline void m4_0100(const hkVector4& a){ x=x*a.x; y=(y*a.y); z=z*a.z; w=w*a.w; }
		__forceinline void m4_0030(const hkVector4& a){ x=x*a.x; y=y*a.y; z=(((z*a.z))); w=w*a.w; }
		__forceinline void m4_0130(const hkVector4& a){ x=x*a.x; y=(y*a.y); z=(((z*a.z))); w=w*a.w; }
		__forceinline void m4_1000(const hkVector4& a){ x=(x*a.x); y=y*a.y; z=z*a.z; w=w*a.w; }
		__forceinline void m4_1300(const hkVector4& a){ x=(x*a.x); y=(((y*a.y))); z=z*a.z; w=w*a.w; }
		__forceinline void m4_1030(const hkVector4& a){ x=(x*a.x); y=y*a.y; z=(((z*a.z))); w=w*a.w; }
		__forceinline void m4_2000(const hkVector4& a){ x=((x*a.x)); y=y*a.y; z=z*a.z; w=w*a.w; }
		__forceinline void sm_0130(hkSimdRealParameter rs, const hkVector4& a){ hkReal r=hkReal(rs); x=r*a.x; y=(r*a.y); z=(((r*a.z))); w=r*a.w; }
		__forceinline void sm_0100(hkSimdRealParameter rs, const hkVector4& a){ hkReal r=hkReal(rs); x=r*a.x; y=(r*a.y); z=r*a.z; w=r*a.w; }
		__forceinline void sm_0030(hkSimdRealParameter rs, const hkVector4& a){ hkReal r=hkReal(rs); x=r*a.x; y=r*a.y; z=(((r*a.z))); w=r*a.w; }
		__forceinline void sm_0200(hkSimdRealParameter rs, const hkVector4& a){ hkReal r=hkReal(rs); x=r*a.x; y=((r*a.y)); z=r*a.z; w=r*a.w; }
		__forceinline void sm_0020(hkSimdRealParameter rs, const hkVector4& a){ hkReal r=hkReal(rs); x=r*a.x; y=r*a.y; z=((r*a.z)); w=r*a.w; }
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
		friend void __cdecl hkSolver::calcLinearVel4_s( const hkp1Lin2AngJacobian& jac, const hkVector4& linVelA, const hkVector4& angVelA, const hkVector4& linVelB, const hkVector4& angVelB, hkVector4& out );
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
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::add3clobberW(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0(0) + v1.x;
	y = v0(1) + v1.y;
	z = v0(2) + v1.z;
	w = v0(3) + v1.w;
}
inline void hkVector4::sub3_v0op(const hkVector4& v) { x -= v(0); y -= v.y; z -= v.z; }
inline void hkVector4::sub3clobberW(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
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
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	;
	hkReal r = v(i);
	x = r;
	y = r;
	z = r;
	w = r;
}
class hkMatrix6;
class hkVector8
{
	public:
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
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo;
class hkpSolverResults;
struct hkpSolverElemTemp
{
	union
	{
		hkReal m_impulseApplied;
		hkReal m_usedImpulseFactor;
		hkReal m_deltaRhs;
	};
};
class hkpConstraintInstance;
class hkpVelocityAccumulator
{
	public:
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
class hkp2AngJacobian
{
	public:
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		inline hkSimdReal getAngularRhsSr() const { return m_angular[1](3); }
};
class hkp1Lin2AngJacobian
{
	public:
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		inline void setRHS( hkReal v ) { m_linear0(3) = v; }
		inline const hkReal& getRHS() const { return m_linear0(3); }
		inline const hkSimdReal getRhsSr() const { return m_linear0(3); }
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
		inline hkReal getUserValue() const { return m_angular[1](3); }
		inline hkSimdReal getUserValueSr() const { return m_angular[1](3); }
};
class hkp2Lin2AngJacobian
{
	public:
		hkVector4 m_linear[2];
		hkVector4 m_angular[2];
		inline hkReal getRHS() const { return m_linear[0](3); }
		inline hkSimdReal getRhsSr() const { return m_linear[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
};
class hkpJacDouble2Bil
{
	public:
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
};
class hkpJacTriple2Bil1Ang
{
	public:
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
		static inline hkEnum<SchemaType, hkInt8> __cdecl getType( const hkpJacobianSchema* schema )
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
		__forceinline const hkpVelocityAccumulator* getBodyA( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyAIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline const hkpVelocityAccumulator* getBodyB( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyBIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline hkpVelocityAccumulator* getBodyA( hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffset( accums, m_bodyAIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline hkpVelocityAccumulator* getBodyB( hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffset( accums, m_bodyBIndex * sizeof(hkpVelocityAccumulator) );
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
		hkUint32 m_padding0;
		hkUint32 m_offset;
		hkUint32 m_padding1[2];
};
class hkpJacobianShiftSolverResultsPointerSchema
{
	public:
		__forceinline int getNumSolverResults() const { return m_numSolverResultsToSkip; }
		hkUint32 m_padding_1;
		hkUint8 m_numSolverResultsToSkip;
		hkUint32 m_padding2[2];
};
class hkpJacobianSingleContactSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobianPairContactSchema
{
	public:
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_padding[3];
};
class hkpJacobian1dBilateralSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobian1dBilateralUserTauSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_tau;
		hkReal m_damping;
		hkReal m_padding[2];
};
class hkpJacobian1dLinearLimitsSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_padding[2];
};
class hkpJacobian1dFrictionSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dLinearMotorSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian1dPulleySchema
{
	public:
		hkp2Lin2AngJacobian m_jac;
};
class hkpJacobian1dAngularSchema
{
	public:
		hkp2AngJacobian m_jac;
};
class hkpJacobian1dAngularLimitsSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_tau;
		hkReal m_padding;
};
class hkpJacobian1dAngularFrictionSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dAngularMotorSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian2dFrictionSchema
{
	public:
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
		hkVector4 m_invMass0;
		hkVector4 m_invMass1;
};
class hkpJacobianAddVelocitySchema
{
	public:
		hkVector4 m_deltaVel;
		int m_bodyIndex;
		hkUint32 m_padding[3];
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *hkAddByteOffsetConst( base, m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainTriple
{
	hkReal m_lower;
	hkReal m_diagonal;
	hkReal m_upper;
};
struct hkpConstraintChainMatrixTriple
{
	hkMatrix3 m_lower;
	hkMatrix3 m_diagonalInv;
	hkMatrix3 m_upper;
};
class hkpJacobianStiffSpringChainSchema
{
	public:
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
	hkMatrix6 m_lower;
	hkMatrix6 m_diagonalInv;
	hkMatrix6 m_upper;
	hkMatrix6 m_mtxDiag;
	hkMatrix6 m_mtxNextOffdiag;
};
class hkpJacobianPoweredChainSchema
{
	public:
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
namespace hkSolver
{
struct SolverStepTemp
	{
		SolverStepTemp() {}
		hkPadSpu<int> m_currentStep;
		hkPadSpu<hkReal> m_intregratePositions;
	};
__forceinline void __cdecl loadVelocityAccumulators( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl storeVelocityAccumulators( hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl prefetchVelocityAccumulators( hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl storeDelayedResult( hkpSolverElemTemp* delayedResult )
	{
	}
__forceinline hkReal __cdecl getLinearDv0( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; b.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline hkReal __cdecl getAngularDv0( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 b; b.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.add4( b );
		const hkSimdReal vel = a.horizontalAdd3();
		const hkSimdReal dv = jac.getAngularRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl calcLinearVel4( const hkp1Lin2AngJacobian& jac, const hkVector4& linVelA, const hkVector4& angVelA, const hkVector4& linVelB, const hkVector4& angVelB, hkVector4& out )
	{
		hkVector4 a; a.setSub4( linVelA, linVelB );
		hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
		hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		out.setAdd4_clean( b, a );
	}
// Fake match: calcLinearVel4 for the summed-velocity block; the read of a.x numbers its field view early (operand order only)
__forceinline void __cdecl calcLinearVel4_s( const hkp1Lin2AngJacobian& jac, const hkVector4& linVelA, const hkVector4& angVelA, const hkVector4& linVelB, const hkVector4& angVelB, hkVector4& out )
	{
		hkVector4 a; a.setSub4( linVelA, linVelB );
		(void)a.x;
		hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
		hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		out.setAdd4_clean( b, a );
	}
__forceinline hkReal __cdecl getLinearDv0UserTauWithCustomRhs( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 linVelA; linVelA.setSub4( mA.m_linearVel, mA.getSumLinearVel() );
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 linVelB; linVelB.setSub4( mB.m_linearVel, mB.getSumLinearVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			calcLinearVel4( jac, linVelA, angVelA, linVelB, angVelB, vel4 );
		}
		hkVector4 svel4;
		{
			hkVector4 linVelA = mA.getSumLinearVel();
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 linVelB = mB.getSumLinearVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			calcLinearVel4_s( jac, linVelA, angVelA, linVelB, angVelB, svel4 );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		hkVector4::ms3_L1( vel4, vel4, damping );
		hkVector4 dv; dv.setAdd4_clean( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getLinearDv0UserTau_orig( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 linVelA; linVelA.setSub4( mA.m_linearVel, mA.getSumLinearVel() );
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 linVelB; linVelB.setSub4( mB.m_linearVel, mB.getSumLinearVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			hkVector4 a; a.setSub4( linVelA, linVelB );
			hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
			a.mul4( jac.m_linear0 );
			b.add4( c );
			vel4.setAdd4_clean( b, a );
		}
		hkVector4 svel4;
		{
			hkVector4 linVelA = mA.getSumLinearVel();
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 linVelB = mB.getSumLinearVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			hkVector4 a; a.setSub4( linVelA, linVelB );
			hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
			a.mul4( jac.m_linear0 );
			b.add4( c );
			svel4.setAdd4_clean( b, a );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		vel4.mul4( damping );
		hkVector4 dv; dv.setAdd4( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getLinearDv0UserTau( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping )
	{
		return getLinearDv0UserTau_orig( jac, mA, mB, info, tau, damping, jac.getRHS() );
	}
__forceinline hkReal __cdecl getAngularDv0UserTauWithCustomRhs( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customAngularRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; b.setMul4( angVelB, jac.m_angular[1] );
			vel4.setAdd4( a, b );
		}
		hkVector4 svel4;
		{
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; b.setMul4( angVelB, jac.m_angular[1] );
			svel4.setAdd4( a, b );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		vel4.mul4( damping );
		hkVector4 dv; dv.setAdd4( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customAngularRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getAngularDv0UserTauWithCustomRhs_c15( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customAngularRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; b.setMul4( angVelB, jac.m_angular[1] );
			vel4.setAdd4( a, b );
		}
		hkVector4 svel4;
		{
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; const hkVector4& j1 = jac.m_angular[1]; b.setMul4( angVelB, j1 );
			svel4.setAdd4( a, b );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		vel4.mul4( damping );
		hkVector4 dv; dv.setAdd4( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customAngularRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getAngularDv0UserTau( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping )
	{
		return getAngularDv0UserTauWithCustomRhs( jac, mA, mB, info, tau, damping, jac.getAngularRhs() );
	}
__forceinline hkReal __cdecl getDv2Lin2Ang( const hkp2Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 lA; lA.setMul4( mA.m_linearVel, jac.m_linear[0] );
		hkVector4 lB; lB.setMul4( mB.m_linearVel, jac.m_linear[1] );
		hkVector4 a; a.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 b; b.setMul4( mB.m_angularVel, jac.m_angular[1] );
		hkVector4 c; c.setSub4( lA, lB );
		a.add4( b );
		a.add4( c );
		const hkSimdReal vel = a.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline hkReal __cdecl getLinearDv0_j0( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; b.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.m4_0130( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl getDv01( const hkp1Lin2AngJacobian* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut )
	{
		velOut(0) = getLinearDv0_j0( jac[0], mA, mB, info );
		velOut(1) = getLinearDv0( jac[1], mA, mB, info );
	}
__forceinline void __cdecl getDv012( const hkpJacTriple2Bil1Ang* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut )
	{
		velOut(0) = getLinearDv0_j0( jac->m_jac0, mA, mB, info );
		velOut(1) = getLinearDv0( jac->m_jac1, mA, mB, info );
		velOut(2) = getAngularDv0( jac->m_jac2, mA, mB, info );
	}
__forceinline void __cdecl applyImpulse( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse2Lin2Ang( hkSimdRealParameter imp, const hkp2Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 impLinB; impLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear[0] );
		impLinB.mul4( jac.m_linear[1] );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( impLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyAngularImpulse( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse01( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl applyAngularImpulse0( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyAngularImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_bilat( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse_c9( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.sm_0130( imp, mA.m_invMasses );
		hkVector4 impB; impB.sm_0130( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		hkVector4& avB = mB.m_angularVel; avB.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_c9( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_c9( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_c7b( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.a3_010( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.a3_013( impA );
		hkVector4& avB = mB.m_angularVel; avB.a3_003( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_c7b( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_c7b( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_pc2_1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		hkVector4& lvA = mA.m_linearVel; lvA.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_pc2_1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_pc2_1( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyAngularImpulse_c13a1( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		hkVector4& avA = mA.m_angularVel; avA.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyAngularImpulse0_c13a1( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyAngularImpulse_c13a1( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_sc( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4& lvA = mA.m_linearVel;
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		lvA.add3clobberW( impLinA );
		hkVector4& lvB = mB.m_linearVel; lvB.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.setMul4( jac.m_angular[1], impB );
		hkVector4& avA = mA.m_angularVel; avA.add3clobberW( impA );
		hkVector4& avB = mB.m_angularVel; avB.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_sc( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_sc( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_c21h1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; const hkVector4& invA = mA.m_invMasses; impA.setMul4( imp, invA );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_c21h1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_c21h1( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_c22h0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.setMul4( jac.m_angular[0], impA );
		impB.setMul4( jac.m_angular[1], impB );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_c22h0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_c22h0( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse01_c21( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse0_c21h1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl applyImpulse01_c22( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0_c22h0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl solve1dBilateral( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dBilateralSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getLinearDv0( schema.m_jac, mA, mB, info );
		const hkReal invJacDiag = schema.m_jac.getInvJacDiagSr();
		const hkSimdReal impulse = dv * invJacDiag;
		applyImpulse_bilat( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dBilateralUserTau( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dBilateralUserTauSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getLinearDv0UserTau( schema.m_jac, mA, mB, info, schema.m_tau, schema.m_damping );
		const hkSimdReal impulse = dv * schema.m_jac.getInvJacDiagSr();
		applyImpulse( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl applyImpulse_pc1_0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3_v0op( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.a3_100( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_pc1_0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_pc1_0( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_pc1_1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.a3_003( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse1_pc1_1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr ) { applyImpulse_pc1_1( imp, jac, mA, mB, sr ); }
__forceinline void __cdecl applyImpulse01_pc1( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0_pc1_0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse1_pc1_1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl applyImpulse_pc2_0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.setMul4( negImpLinB, jac.m_linear0 );
		mA.m_linearVel.a3_100( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_pc2_0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_pc2_0( imp, jac, mA, mB, sr );
	}
// Fake match: the impulse total in its own inline helper, so its local is numbered after the mass multiplies (operand order only)
__forceinline void __cdecl addImpulseApplied( hkpSolverElemTemp& sr, hkSimdRealParameter imp )
	{
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse_pc2_j1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.a3_003( impA );
		mB.m_angularVel.add3clobberW( impB );
		addImpulseApplied( sr, imp );
	}
__forceinline void __cdecl applyImpulse1_pc2_j1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr ) { applyImpulse_pc2_j1( imp, jac, mA, mB, sr ); }
__forceinline void __cdecl applyImpulse01_pc2( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0_pc2_0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse1_pc2_j1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl applyImpulse_c7a( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB, impLinA, negImpLinB;
		hkVector4::r74_fix( imp, mB.m_invMasses, impB, impA, impLinA, negImpLinB, mA.m_linearVel, jac.m_linear0 );
		mB.m_linearVel.s3_001( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.m4_3000( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.a3_130( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline hkReal __cdecl getLinearDv0_c7( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; hkVector4::sm4_vv_c_dba( b, jac.m_angular[0], mA.m_angularVel );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl solve1dLinLimits( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dLinearLimitsSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkReal dv = getLinearDv0_c7( schema.m_jac, mA, mB, info );
		{
			hkReal impulse = dv - schema.m_minRhs;
			if ( impulse > 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyImpulse_c7a( impulse, schema.m_jac, mA, mB, *sr );
			}
		}
		{
			hkReal impulse = dv - schema.m_maxRhs;
			if ( impulse < 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyImpulse0_c7b( impulse, schema.m_jac, mA, mB, *sr );
			}
		}
	}
__forceinline void __cdecl applyImpulse_c8( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		hkVector4::mv3_L7( impLinA, impLinA, jac.m_linear0 );
		hkVector4::mv3_L7( negImpLinB, negImpLinB, jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		hkVector4::mv3_L7( impB, impB, jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.a3_013( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
// Fake match: 3-component setMul3_now/add3_now on b & c (whose .w is unused before horizontalAdd3), dropping 2 dead field-view keys before applyImpulse_c8
__forceinline hkReal __cdecl getLinearDv0_c8( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; b.setMul3_now( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul3_now( mB.m_angularVel, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add3_now( c );
		b.add3_now( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl solve1dFriction( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkReal dv0 = getLinearDv0_c8( jac, mA, mB, info );
		hkReal imp0 = jac.getInvJacDiag() * dv0;
		const hkReal fimp0 = hkMath::fabs( imp0 );
		if ( fimp0 > schema.m_maxImpulse )
		{
			const hkReal factor = schema.m_maxImpulse / fimp0;
			imp0 *= factor;
			sr[1].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyImpulse_c8( imp0, jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dLinearMotor( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dLinearMotorSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkpSolverElemTemp& sr1 = sr[1];
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkp1dMotorSolverInfo& motorInfo = schema.m_motorSolverInfo;
		sr[2].m_deltaRhs = temp.m_intregratePositions * motorInfo.m_velocity + sr[2].m_deltaRhs;
		const hkReal customRhs = jac.getRHS() + sr[2].m_deltaRhs;
		const hkReal dv0 = getLinearDv0UserTauWithCustomRhs( jac, mA, mB, info, motorInfo.m_tau, motorInfo.m_damping, customRhs );
		hkReal impulse = jac.getInvJacDiag() * dv0;
		if ( impulse > motorInfo.m_maxImpulsePerSubstep )
		{
			sr1.m_usedImpulseFactor = motorInfo.m_maxImpulsePerSubstep / impulse;
			impulse = motorInfo.m_maxImpulsePerSubstep;
		}
		else if ( impulse < motorInfo.m_minImpulsePerSubstep )
		{
			sr1.m_usedImpulseFactor = motorInfo.m_minImpulsePerSubstep / impulse;
			impulse = motorInfo.m_minImpulsePerSubstep;
		}
		else
		{
			sr1.m_usedImpulseFactor = 1.0f;
		}
		applyImpulse0_c9( impulse, jac, mA, mB, *sr );
	}
__forceinline void __cdecl solvePulley( const hkpSolverInfo& info, const hkpJacobian1dPulleySchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp2Lin2AngJacobian& jac = schema.m_jac;
		const hkSimdReal dv = getDv2Lin2Ang( jac, mA, mB, info );
		const hkSimdReal impulse = dv * jac.getInvJacDiagSr();
		applyImpulse2Lin2Ang( impulse, jac, mA, mB, sr[0] );
	}
__forceinline void __cdecl solve1dAngular( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getAngularDv0( schema.m_jac, mA, mB, info );
		const hkSimdReal impulse = dv * schema.m_jac.getInvJacDiagSr();
		applyAngularImpulse( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dAngLimits( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularLimitsSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkReal dv = getAngularDv0UserTau( schema.m_jac, mA, mB, info, schema.m_tau, info.m_damping );
		{
			hkReal impulse = dv - schema.m_minRhs;
			if ( impulse > 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyAngularImpulse0_c13a1( impulse, schema.m_jac, mA, mB, *sr );
				return;
			}
		}
		{
			hkReal impulse = dv - schema.m_maxRhs;
			if ( impulse < 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyAngularImpulse0( impulse, schema.m_jac, mA, mB, *sr );
			}
		}
	}
__forceinline void __cdecl solve1dAngFriction( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkReal dv0 = getAngularDv0( schema.m_jac, mA, mB, info );
		hkReal imp0 = schema.m_jac.getInvJacDiag() * dv0;
		const hkReal fimp0 = hkMath::fabs( imp0 );
		if ( fimp0 > schema.m_maxImpulse )
		{
			const hkReal factor = schema.m_maxImpulse / fimp0;
			imp0 *= factor;
			sr[1].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyAngularImpulse0( imp0, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dAngularMotor( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularMotorSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1dMotorSolverInfo& motorInfo = schema.m_motorSolverInfo;
		sr[2].m_deltaRhs = temp.m_intregratePositions * motorInfo.m_velocity + sr[2].m_deltaRhs;
		const hkReal customAngularRhs = schema.m_jac.getAngularRhs() + sr[2].m_deltaRhs;
		const hkReal dv0 = getAngularDv0UserTauWithCustomRhs_c15( schema.m_jac, mA, mB, info, motorInfo.m_tau, motorInfo.m_damping, customAngularRhs );
		hkReal impulse = schema.m_jac.getInvJacDiag() * dv0;
		if ( impulse > motorInfo.m_maxImpulsePerSubstep )
		{
			sr[1].m_usedImpulseFactor = motorInfo.m_maxImpulsePerSubstep / impulse;
			impulse = motorInfo.m_maxImpulsePerSubstep;
		}
		else if ( impulse < motorInfo.m_minImpulsePerSubstep )
		{
			sr[1].m_usedImpulseFactor = motorInfo.m_minImpulsePerSubstep / impulse;
			impulse = motorInfo.m_minImpulsePerSubstep;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyAngularImpulse( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline hkReal __cdecl getLinearDv0_sc( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; hkVector4::sm4_vv_c_dba( b, jac.m_angular[0], mA.m_angularVel );
		hkVector4 c; c.setMul4( jac.m_angular[1], mB.m_angularVel );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl solveSingleContact( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobianSingleContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getLinearDv0_sc( schema.m_jac, mA, mB, info );
		if ( !hkMath::isNegative( dv ) )
		{
			applyImpulse0_sc( dv * schema.m_jac.getInvJacDiagSr(), schema.m_jac, mA, mB, *sr );
		}
	}
__forceinline void __cdecl applyImpulse_limitContact_in( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.a3_100( impLinA );
		hkVector4& lvB = mB.m_linearVel; lvB.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		hkVector4& avA = mA.m_angularVel; avA.a3_003( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0_limitContact( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse_limitContact_in( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl solveSingleLimitContact( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobianSingleContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkSimdReal dv = getLinearDv0( jac, mA, mB, info );
		if ( !hkMath::isNegative( dv ) )
		{
			hkSimdReal impulse = dv * jac.getInvJacDiagSr();
			const hkSimdReal maxImpulse = jac.getUserValueSr();
			const hkSimdReal impulseApplied = sr->m_impulseApplied;
			const hkSimdReal sumImpulse = impulseApplied + impulse;
			if ( sumImpulse > maxImpulse )
			{
				impulse = maxImpulse - impulseApplied;
			}
			applyImpulse0_limitContact( impulse, jac, mA, mB, *sr );
		}
	}
__forceinline void __cdecl solvePairContact( const hkpSolverInfo& info, const hkpJacobianPairContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkpJacDouble2Bil& jac = schema.m_jac;
		hkVector4 dv4;
		getDv01( &jac.m_jac0, mA, mB, info, dv4 );
		const hkReal dv0 = dv4(0);
		const hkp1Lin2AngJacobian& jac1 = jac.m_jac1;
		const hkReal dv1 = dv4(1);
		hkReal imp0 = jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp1 = jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		if ( imp0 > 0.0f )
		{
			if ( imp1 > 0.0f )
			{
				applyImpulse01_pc1( imp0, imp1, &jac.m_jac0, mA, mB, sr );
			}
			else
			{
checkImp0:
				const hkReal imp01 = jac.m_jac0.getInvJacDiag() * dv0;
				if ( imp01 > 0.0f )
				{
					applyImpulse0( imp01, jac.m_jac0, mA, mB, sr[0] );
				}
			}
		}
		else
		{
			const hkReal imp10 = ( jac1.getInvJacDiag() * dv1 );
			if ( imp10 <= 0.0f )
			{
				goto checkImp0;
			}
			applyImpulse1( imp10, jac1, mA, mB, sr[1] );
		}
	}
__forceinline hkReal __cdecl getLinearDv0_pc2_j1( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		const hkVector4& la = mA.m_linearVel;
		hkVector4 a; a.setSub4( la, mB.m_linearVel );
		hkVector4 b; b.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl getDv01_pc2( const hkp1Lin2AngJacobian* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut )
	{
		velOut(0) = getLinearDv0_j0( jac[0], mA, mB, info );
		velOut(1) = getLinearDv0_pc2_j1( jac[1], mA, mB, info );
	}
__forceinline void __cdecl solvePairContact_2( const hkpSolverInfo& info, const hkpJacobianPairContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkpJacDouble2Bil& jac = schema.m_jac;
		hkVector4 dv4;
		getDv01_pc2( &jac.m_jac0, mA, mB, info, dv4 );
		const hkReal dv0 = dv4(0);
		const hkp1Lin2AngJacobian& jac1 = jac.m_jac1;
		const hkReal dv1 = dv4(1);
		hkReal imp0 = jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp01; // Fake match: imp01 and imp10 declared before imp1 (frame-key order only)
		hkReal imp10;
		(void)imp01; (void)imp10;
		hkReal imp1 = jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		if ( imp0 > 0.0f )
		{
			if ( imp1 > 0.0f )
			{
				applyImpulse01_pc2( imp0, imp1, &jac.m_jac0, mA, mB, sr );
			}
			else
			{
checkImp0:
				imp01 = jac.m_jac0.getInvJacDiag() * dv0;
				if ( imp01 > 0.0f )
				{
					applyImpulse0( imp01, jac.m_jac0, mA, mB, sr[0] );
				}
			}
		}
		else
		{
			imp10 = ( jac1.getInvJacDiag() * dv1 );
			if ( imp10 <= 0.0f )
			{
				goto checkImp0;
			}
			applyImpulse0_pc2_1( imp10, jac1, mA, mB, sr[1] );
		}
	}
__forceinline void __cdecl solve2dFriction( const hkpSolverInfo& info, const hkpJacobian2dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkVector4 vel4;
		getDv01( &schema.m_jac.m_jac0, mA, mB, info, vel4 );
		const hkReal dv0 = vel4(0);
		const hkReal dv1 = vel4(1);
		const hkReal maxImpulse = schema.m_maxImpulse;
		const hkReal maxSquared = maxImpulse * maxImpulse;
		hkReal imp0 = schema.m_jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp1 = schema.m_jac.m_jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
		if ( impSquared > maxSquared )
		{
			const hkReal factor = hkMath::sqrt( maxSquared / impSquared );
			imp0 *= factor;
			imp1 *= factor;
			sr[2].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[2].m_usedImpulseFactor = 1.0f;
		}
		applyImpulse01_c22( imp0, imp1, &schema.m_jac.m_jac0, mA, mB, sr );
	}
__forceinline void __cdecl solve3dFriction( const hkpSolverInfo& info, const hkpJacobian3dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkVector4 vel4;
		getDv012( &schema.m_jac, mA, mB, info, vel4 );
		hkReal imp0; // Fake match: number imp0 & impSquared before dv0 so imp0 takes 0x0b18 (0x631e), imp1 takes 0x109a (0x135f) < factor 0x109b (0x137f) while 3*h(imp1) > 3*h(imp0)
		hkReal impSquared;
		(void)imp0; (void)impSquared;
		const hkReal dv0 = vel4(0);
		const hkReal dv1 = vel4(1);
		const hkReal dva = vel4(2);
		hkReal angularImp = schema.m_jac.m_jac2.getInvJacDiag() * dva;
		const hkReal maxSquared = schema.m_maxImpulse * schema.m_maxImpulse;
		imp0 = schema.m_jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp1 = schema.m_jac.m_jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
		if ( impSquared > maxSquared )
		{
			const hkReal factor = schema.m_maxImpulse * hkMath::sqrtInverse( impSquared );
			imp0 *= factor;
			imp1 *= factor;
			angularImp *= factor;
			sr[3].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[3].m_usedImpulseFactor = 1.0f;
		}
		angularImp *= schema.m_contactRadius;
		applyImpulse01_c21( imp0, imp1, &schema.m_jac.m_jac0, mA, mB, sr );
		applyAngularImpulse0( angularImp, schema.m_jac.m_jac2, mA, mB, sr[2] );
	}
}
namespace hkSolver
{
__forceinline int __cdecl stepJacobian( const hkpSolverInfo& info, SolverStepTemp& temp, const hkpJacobianSchema* schemas, hkpVelocityAccumulator* accums, hkpSolverElemTemp* srIn )
	{
		const hkpJacobianSchema* com = schemas;
		hkpSolverElemTemp* sr = srIn;
		if ( hkpJacobianSchema::getType( com ) == hkpJacobianSchema::SCHEMA_TYPE_END )
		{
			return 0;
		}
		;
		hkpVelocityAccumulator* mA;
		hkpVelocityAccumulator* mB;
		hkpSolverElemTemp* delayedResult = 0;
		goto headerNoStoreVelocity;
		while ( 1 )
		{
			switch ( hkpJacobianSchema::getType( com ) )
			{
				case hkpJacobianSchema::SCHEMA_TYPE_HEADER:
header:
					{
						const hkpJacobianHeaderSchema* sc = reinterpret_cast<const hkpJacobianHeaderSchema*>( com );
						prefetchVelocityAccumulators( *sc->getBodyA( accums ), *sc->getBodyB( accums ) );
						storeVelocityAccumulators( *mA, *mB );
headerNoStoreVelocity:
						{
							const hkpJacobianHeaderSchema* sc2 = reinterpret_cast<const hkpJacobianHeaderSchema*>( com );
							mA = sc2->getBodyA( accums );
							mB = sc2->getBodyB( accums );
							loadVelocityAccumulators( *mA, *mB );
							com = reinterpret_cast<const hkpJacobianSchema*>( sc2 + 1 );
						}
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER:
					{
						const hkpJacobianShiftSolverResultsPointerSchema* sc = reinterpret_cast<const hkpJacobianShiftSolverResultsPointerSchema*>( com );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK:
case_SCHEMA_TYPE_SINGLE_CONTACT:
					{
						const hkpJacobianSingleContactSchema* sc = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
						solveSingleContact( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT ) goto case_SCHEMA_TYPE_SINGLE_CONTACT;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK:
case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
					{
						const hkpJacobianSingleContactSchema* sc = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
						solveSingleLimitContact( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT ) goto case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK:
					{
						{
							const hkpJacobianPairContactSchema* sc = reinterpret_cast<const hkpJacobianPairContactSchema*>( com );
							solvePairContact( info, *sc, *mA, *mB, sr, delayedResult );
							sr += 2;
							com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						}
						if ( hkpJacobianSchema::getType( com ) != hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT )
						{
							continue;
						}
						{
							const hkpJacobianPairContactSchema* sc = reinterpret_cast<const hkpJacobianPairContactSchema*>( com );
							solvePairContact_2( info, *sc, *mA, *mB, sr, delayedResult );
							sr += 2;
							com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						}
						if ( hkpJacobianSchema::getType( com ) != hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION )
						{
							break;
						}
					}
				case hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION:
					{
						const hkpJacobian3dFrictionSchema* sc = reinterpret_cast<const hkpJacobian3dFrictionSchema*>( com );
						solve3dFriction( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 4;
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_HEADER ) goto header;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_2D_FRICTION:
					{
						const hkpJacobian2dFrictionSchema* sc = reinterpret_cast<const hkpJacobian2dFrictionSchema*>( com );
						solve2dFriction( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 3;
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_HEADER ) goto header;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_SCHEMA_TYPE_1D_ANGULAR_FRICTION:
					{
						const hkpJacobian1dAngularFrictionSchema* sc = reinterpret_cast<const hkpJacobian1dAngularFrictionSchema*>( com );
						solve1dAngFriction( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION ) goto case_SCHEMA_TYPE_1D_ANGULAR_FRICTION;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_SCHEMA_TYPE_1D_ANGULAR_LIMITS:
					{
						const hkpJacobian1dAngularLimitsSchema* sc = reinterpret_cast<const hkpJacobian1dAngularLimitsSchema*>( com );
						solve1dAngLimits( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS ) goto case_SCHEMA_TYPE_1D_ANGULAR_LIMITS;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_SCHEMA_TYPE_1D_ANGULAR_MOTOR:
					{
						const hkpJacobian1dAngularMotorSchema* sc = reinterpret_cast<const hkpJacobian1dAngularMotorSchema*>( com );
						solve1dAngularMotor( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR ) goto case_SCHEMA_TYPE_1D_ANGULAR_MOTOR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR:
case_SCHEMA_TYPE_1D_ANGULAR:
					{
						const hkpJacobian1dAngularSchema* sc = reinterpret_cast<const hkpJacobian1dAngularSchema*>( com );
						solve1dAngular( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR ) goto case_SCHEMA_TYPE_1D_ANGULAR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL:
case_SCHEMA_TYPE_1D_BILATERAL:
					{
						const hkpJacobian1dBilateralSchema* sc = reinterpret_cast<const hkpJacobian1dBilateralSchema*>( com );
						solve1dBilateral( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL ) goto case_SCHEMA_TYPE_1D_BILATERAL;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
					{
						const hkpJacobian1dBilateralUserTauSchema* sc = reinterpret_cast<const hkpJacobian1dBilateralUserTauSchema*>( com );
						solve1dBilateralUserTau( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU ) goto case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_FRICTION:
case_SCHEMA_TYPE_1D_FRICTION:
					{
						const hkpJacobian1dFrictionSchema* sc = reinterpret_cast<const hkpJacobian1dFrictionSchema*>( com );
						solve1dFriction( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_FRICTION ) goto case_SCHEMA_TYPE_1D_FRICTION;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_SCHEMA_TYPE_1D_LINEAR_LIMITS:
					{
						const hkpJacobian1dLinearLimitsSchema* sc = reinterpret_cast<const hkpJacobian1dLinearLimitsSchema*>( com );
						solve1dLinLimits( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS ) goto case_SCHEMA_TYPE_1D_LINEAR_LIMITS;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_SCHEMA_TYPE_1D_LINEAR_MOTOR:
					{
						const hkpJacobian1dLinearMotorSchema* sc = reinterpret_cast<const hkpJacobian1dLinearMotorSchema*>( com );
						solve1dLinearMotor( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR ) goto case_SCHEMA_TYPE_1D_LINEAR_MOTOR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_PULLEY:
					{
						const hkpJacobian1dPulleySchema* sc = reinterpret_cast<const hkpJacobian1dPulleySchema*>( com );
						solvePulley( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 1;
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SET_MASS:
					{
						const hkpJacobianSetMassSchema* sc = reinterpret_cast<const hkpJacobianSetMassSchema*>( com );
						storeVelocityAccumulators( *mA, *mB );
						mA->m_invMasses = sc->m_invMass0;
						mB->m_invMasses = sc->m_invMass1;
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						loadVelocityAccumulators( *mA, *mB );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_ADD_VELOCITY:
					{
						const hkpJacobianAddVelocitySchema* sc = reinterpret_cast<const hkpJacobianAddVelocitySchema*>( com );
						storeVelocityAccumulators( *mA, *mB );
						hkpVelocityAccumulator* accum = hkSelect( sc->m_bodyIndex, mA, mB );
						hkVector4 sumVel; sumVel.setMul4( hkReal( temp.m_currentStep ) * info.m_integrateVelocityFactor(0), sc->m_deltaVel );
						accum->m_linearVel.add4_0130( sc->m_deltaVel );
						accum->m_linearVel.add4( sumVel );
						accum->getSumLinearVel().add4( sumVel );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						loadVelocityAccumulators( *mA, *mB );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_GOTO:
					{
						const hkpJacobianGotoSchema* sc = reinterpret_cast<const hkpJacobianGotoSchema*>( com );
						com = hkAddByteOffsetConst( com, sc->m_offset );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_END:
					storeDelayedResult( delayedResult );
					storeVelocityAccumulators( *mA, *mB );
					return 0;
				case hkpJacobianSchema::SCHEMA_TYPE_STIFF_SPRING_CHAIN:
					{
						const hkpJacobianStiffSpringChainSchema* chain = reinterpret_cast<const hkpJacobianStiffSpringChainSchema*>( com );
						::f3m_00a0b990::FUN_00a0b990( (::f3m_00a0b990::S0a0b990_Info*)&info, (void*)&temp, (char*)accums, (::f3m_00a0b990::S0a0b990_Chain*)chain, (float*)sr );
						sr += chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_BALL_SOCKET_CHAIN:
					{
						const hkpJacobianBallSocketChainSchema* chain = reinterpret_cast<const hkpJacobianBallSocketChainSchema*>( com );
						::f3m_00a0c070::FUN_00a0c070( (const ::f3m_00a0c070::SolverInfo&)info, (const ::f3m_00a0c070::SolverStepTemp&)temp, (::f3m_00a0c070::VelocityAccumulator*)accums, (::f3m_00a0c070::BallSocketChainSchema*)chain, (::f3m_00a0c070::SolverElemTemp*)sr );
						sr += 3 * chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_POWERED_CHAIN:
					{
						const hkpJacobianPoweredChainSchema* chain = reinterpret_cast<const hkpJacobianPoweredChainSchema*>( com );
						::f3m_00a0e5d0::f3m_00a0e5d0::FUN_00a0e5d0( (const ::f3m_00a0e5d0::f3m_00a0e5d0::hkpSolverInfo&)info, (const ::f3m_00a0e5d0::f3m_00a0e5d0::hkSolver::SolverStepTemp&)temp, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpVelocityAccumulator*)accums, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpJacobianPoweredChainSchema*)chain, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpSolverElemTemp*)sr );
						sr += 6 * chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				default:
					fnv_Breakpoint();
					return 0;
			}
		}
	}
}
// pdb: hkSolveStepJacobians | hkpSolver.obj | tesv_win, call_gap, low
void __cdecl FUN_00a0f4d0( const hkpSolverInfo& info, const hkpJacobianSchema* schemas, hkpVelocityAccumulator* accumulators, hkpSolverElemTemp* tmp )
{
	hkSolver::SolverStepTemp temp;
	temp.m_intregratePositions = 0.0f;
	temp.m_currentStep = 0;
	hkSolver::stepJacobian( info, temp, schemas, accumulators, tmp );
}

}  // namespace f3m_00a0f4d0
}   // namespace f3m_00a0f4d0

// @f3 0x00a1b9f0 (community match, verified in this file)
// 0x00a1b9f0 hkSolveConstraintsByTheSteps. Build /MT /O2 /GS- /EHsc /Gy (the listed /Od cannot produce this code).
// Body = chk_243ee08030c042049083 (another contributor, credited; itself built on earlier shared drafts) plus three
// changes that only move symbols in the optimiser's tables and emit no code of their own:
//  - solve3dFriction: impSquared gets its first (dead) assignment before imp1 (fixes imp1 *= factor, +0x1f59);
//  - solvePairContact2: imp0, imp1, imp01, imp10 get their first (dead) assignment before jac1;
//  - applyImpulse_pc20_i: six of its vector calls go through ku_* copies of the hkVector4 methods that take unused
//    trailing int arguments (fixes the first-component operand order of impA/impB there, +0x0da0).
// 0x00a1b9f0: hkSolveConstraintsByTheSteps (Havok 5.5.0, hkpSolver.cpp), one solver step over a constraint list's
// jacobian schemas. This is the hand-over draft of 2026-11-19 by another contributor (f3-solver2; their notes are on
// the function), unchanged except that the stiff spring and ball-and-socket chain solvers are called through the
// unit's own definitions (FUN_00a0b990, FUN_00a0c070), as the powered chain already was. It needs a unit that defines
// all three chain solvers before this function; in such a pack copy it measures 23,004 bytes, 166 differing
// instructions, 51 of 90 regions under /MT /O2 /GS- /EHsc /Gy. What differs is x87 operand order only.
// Not from the library's source: against the SDK's unoptimised library copy of this function, this file has ten
// named locals the library does not have (reference locals jac/jac1/sr1 in seven solve helpers, invJacDiag in the
// single contact), five products in another operand order and one parenthesised product; see the mirror checkpoint.
namespace f3m_00a1b9f0 {

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
template <typename TYPE>
__forceinline TYPE* __cdecl hkSelect( int select, TYPE* pairA, TYPE* pairB )
{
	hkUlong ua = hkUlong(pairA);
	hkUlong ub = hkUlong(pairB);
	return reinterpret_cast<TYPE*>( ua ^ ((ua^ub)&(-select)) );
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
class hkVector4Comparison
{
	public:
		enum Mask
		{
			MASK_NONE	= 0,
			MASK_W		= 1,
			MASK_Z		= 2,
			MASK_ZW		= 3,
			MASK_Y		= 4,
			MASK_YW		= 5,
			MASK_YZ		= 6,
			MASK_YZW	= 7,
			MASK_X		= 8,
			MASK_XW		= 9,
			MASK_XZ		= 10,
			MASK_XZW	= 11,
			MASK_XY		= 12,
			MASK_XYW	= 13,
			MASK_XYZ	= 14,
			MASK_XYZW	= 15
		};
		void setAnd( hkVector4Comparison a, hkVector4Comparison b ) { m_mask = a.m_mask & b.m_mask; }
		void set( Mask m ) { m_mask = m; }
		hkBool32 allAreSet( Mask m ) const { return (m_mask & m) == m; }
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		hkBool32 allAreSet() const { return m_mask == MASK_XYZW; }
		hkBool32 anyIsSet() const { return m_mask; }
		int getMask() const { return m_mask; }
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};
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
inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
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
		__forceinline hkVector4() { }
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
		__forceinline void setSub4_s2(const hkVector4& a, const hkVector4& b) { x=(a.x-b.x); y=(a.y-b.y); z=a.z-b.z; w=a.w-b.w; }
		__forceinline void a3_010(const hkVector4& v){x=x+v.x;y=(y+v.y);z=z+v.z;}
		__forceinline void a3_100(const hkVector4& v){x=(x+v.x);y=y+v.y;z=z+v.z;}
		__forceinline 		__forceinline void setMul4_swap(const hkVector4& v, hkReal r){ x = r*v.x; y = r*v.y; z = r*v.z; w = r*v.w; }
		__forceinline void add4_0013(const hkVector4& v){ x = x+v.x; y = y+v.y; z = (z+v.z); w = (((w+v.w))); }
				__forceinline void setMul4_s_keep(const hkVector4& a, hkSimdRealParameter rs){ hkReal r=hkReal(rs); x=r*a.x; y=r*a.y; z=r*a.z; w=r*a.w; }
		static __forceinline void __cdecl add3_c_ab(hkVector4& dst, const hkVector4& v){ dst.x+=v.x; dst.y+=v.y; dst.z+=v.z; }
		static __forceinline void __cdecl sm4_vv_c_dab(hkVector4& dst, const hkVector4& a, const hkVector4& b){ dst.x=a.x*b.x; dst.y=a.y*b.y; dst.z=a.z*b.z; dst.w=a.w*b.w; }
				static __forceinline void __cdecl add3_c_ab_100(hkVector4& d, const hkVector4& v){ d.x=(d.x+v.x); d.y+=v.y; d.z+=v.z; }
		__forceinline void a3_003(const hkVector4& v){ x=x+v.x; y=y+v.y; z=(((z+v.z))); }
		void a3_103(const hkVector4& v){x=(x+v.x);y=y+v.y;z=(((z+v.z)));}
		__forceinline void a3_110(const hkVector4& v){x=(x+v.x);y=(y+v.y);z=z+v.z;}
		__forceinline void a3_130(const hkVector4& v){x=(x+v.x);y=(((y+v.y)));z=z+v.z;}
		__forceinline void a3_220(const hkVector4& v){x=((x+v.x));y=((y+v.y));z=z+v.z;}
		__forceinline void a3_300(const hkVector4& v){x=(((x+v.x)));y=y+v.y;z=z+v.z;}
		__forceinline void m4_1000(const hkVector4& a){x=(x*a.x);y=y*a.y;z=z*a.z;w=w*a.w;}
		__forceinline void m4_1300(const hkVector4& a){x=(x*a.x);y=(((y*a.y)));z=z*a.z;w=w*a.w;}
		__forceinline void s3_300(const hkVector4& v){x=(((x-v.x)));y=y-v.y;z=z-v.z;}
		__forceinline void sm_0130(hkSimdRealParameter rs,const hkVector4& a){hkReal r=hkReal(rs);x=r*a.x;y=(r*a.y);z=(((r*a.z)));w=r*a.w;}
		__forceinline void mul4_s2(const hkVector4& a) { x=(x*a.x); y=(y*a.y); z*=a.z; w*=a.w; }
		__forceinline void ku_setMul4_3(hkSimdRealParameter rs, const hkVector4& a, int u0, int u1, int u2){ hkReal r=hkReal(rs); x=r*a.x; y=r*a.y; z=r*a.z; w=r*a.w; }
		__forceinline void ku_setMul4_2(hkSimdRealParameter rs, const hkVector4& a, int u0, int u1){ hkReal r=hkReal(rs); x=r*a.x; y=r*a.y; z=r*a.z; w=r*a.w; }
		__forceinline void ku_setBroadcast3clobberW_1(const hkVector4& v, int i, int u0){ hkReal r=(&v.x)[i]; x=r; y=r; z=r; w=r; }
		__forceinline void ku_mul4_1(const hkVector4& a, int u0){ x*=a.x; y*=a.y; z*=a.z; w*=a.w; }
		__forceinline void ku_mul4_6(const hkVector4& a, int u0, int u1, int u2, int u3, int u4, int u5){ x*=a.x; y*=a.y; z*=a.z; w*=a.w; }
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
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
inline void hkVector4::add3clobberW(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
}
inline void hkVector4::sub3clobberW(const hkVector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
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
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}
inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}
inline hkSimdReal hkVector4::horizontalAdd3() const
{
	return x+y+z;
}
inline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
	;
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
class hkMatrix6;
class hkVector8
{
	public:
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
    hkReal				m_maxImpulsePerSubstep;
    hkReal				m_minImpulsePerSubstep;
    hkReal				m_velocity;
    hkReal				m_tau;
    hkReal				m_damping;
};
struct hkp3dAngularMotorSolverInfo;
class hkpSolverResults;
struct hkpSolverElemTemp
{
	union
	{
		hkReal m_impulseApplied;
		hkReal m_usedImpulseFactor;
		hkReal m_deltaRhs;
	};
};
class hkpConstraintInstance;
class hkpVelocityAccumulator
{
	public:
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
class hkp2AngJacobian
{
	public:
		hkVector4 m_angular[2];
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
		inline void setAngularRhs( hkReal v ) { m_angular[1](3) = v; }
		inline hkReal getAngularRhs() const { return m_angular[1](3); }
		inline hkSimdReal getAngularRhsSr() const { return m_angular[1](3); }
};
class hkp1Lin2AngJacobian
{
	public:
		hkVector4 m_linear0;
		hkVector4 m_angular[2];
		inline void setRHS( hkReal v ) { m_linear0(3) = v; }
		inline const hkReal& getRHS() const { return m_linear0(3); }
		inline const hkSimdReal getRhsSr() const { return m_linear0(3); }
		inline hkReal getInvJacDiag() const { return m_angular[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
		inline hkReal getUserValue() const { return m_angular[1](3); }
		inline hkSimdReal getUserValueSr() const { return m_angular[1](3); }
};
class hkp2Lin2AngJacobian
{
	public:
		hkVector4 m_linear[2];
		hkVector4 m_angular[2];
		inline hkReal getRHS() const { return m_linear[0](3); }
		inline hkSimdReal getRhsSr() const { return m_linear[0](3); }
		inline hkSimdReal getInvJacDiagSr() const { return m_angular[0](3); }
};
class hkpJacDouble2Bil
{
	public:
		hkp1Lin2AngJacobian m_jac0;
		hkp1Lin2AngJacobian m_jac1;
};
class hkpJacTriple2Bil1Ang
{
	public:
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
		static inline hkEnum<SchemaType, hkInt8> __cdecl getType( const hkpJacobianSchema* schema )
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
		__forceinline const hkpVelocityAccumulator* getBodyA( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyAIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline const hkpVelocityAccumulator* getBodyB( const hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffsetConst( accums, m_bodyBIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline hkpVelocityAccumulator* getBodyA( hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffset( accums, m_bodyAIndex * sizeof(hkpVelocityAccumulator) );
		}
		__forceinline hkpVelocityAccumulator* getBodyB( hkpVelocityAccumulator* accums ) const
		{
			return hkAddByteOffset( accums, m_bodyBIndex * sizeof(hkpVelocityAccumulator) );
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
		hkUint32 m_padding0;
		hkUint32 m_offset;
		hkUint32 m_padding1[2];
};
class hkpJacobianShiftSolverResultsPointerSchema
{
	public:
		__forceinline int getNumSolverResults() const { return m_numSolverResultsToSkip; }
		hkUint32 m_padding_1;
		hkUint8 m_numSolverResultsToSkip;
		hkUint32 m_padding2[2];
};
class hkpJacobianSingleContactSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobianPairContactSchema
{
	public:
		hkpJacDouble2Bil m_jac;
		hkReal m_invJac01;
		hkReal m_padding[3];
};
class hkpJacobian1dBilateralSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
};
class hkpJacobian1dBilateralUserTauSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_tau;
		hkReal m_damping;
		hkReal m_padding[2];
};
class hkpJacobian1dLinearLimitsSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_padding[2];
};
class hkpJacobian1dFrictionSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dLinearMotorSchema
{
	public:
		hkp1Lin2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian1dPulleySchema
{
	public:
		hkp2Lin2AngJacobian m_jac;
};
class hkpJacobian1dAngularSchema
{
	public:
		hkp2AngJacobian m_jac;
};
class hkpJacobian1dAngularLimitsSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkReal m_minRhs;
		hkReal m_maxRhs;
		hkReal m_tau;
		hkReal m_padding;
};
class hkpJacobian1dAngularFrictionSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkReal m_maxImpulse;
		hkReal m_padding[3];
};
class hkpJacobian1dAngularMotorSchema
{
	public:
		hkp2AngJacobian m_jac;
		hkp1dMotorSolverInfo m_motorSolverInfo;
		hkReal m_padding[3];
};
class hkpJacobian2dFrictionSchema
{
	public:
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
		hkVector4 m_invMass0;
		hkVector4 m_invMass1;
};
class hkpJacobianAddVelocitySchema
{
	public:
		hkVector4 m_deltaVel;
		int m_bodyIndex;
		hkUint32 m_padding[3];
};
class hkpVelocityAccumulatorOffset
{
	public:
		__forceinline const hkpVelocityAccumulator& getAccumulator( const hkpVelocityAccumulator* base )
		{
			return *hkAddByteOffsetConst( base, m_offset );
		}
		unsigned m_offset;
};
struct hkpConstraintChainTriple
{
	hkReal m_lower;
	hkReal m_diagonal;
	hkReal m_upper;
};
struct hkpConstraintChainMatrixTriple
{
	hkMatrix3 m_lower;
	hkMatrix3 m_diagonalInv;
	hkMatrix3 m_upper;
};
class hkpJacobianStiffSpringChainSchema
{
	public:
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
	hkMatrix6 m_lower;
	hkMatrix6 m_diagonalInv;
	hkMatrix6 m_upper;
	hkMatrix6 m_mtxDiag;
	hkMatrix6 m_mtxNextOffdiag;
};
class hkpJacobianPoweredChainSchema
{
	public:
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
namespace hkSolver
{
struct SolverStepTemp
	{
		SolverStepTemp() {}
		hkPadSpu<int> m_currentStep;
		hkPadSpu<hkReal> m_intregratePositions;
	};
__forceinline void __cdecl loadVelocityAccumulators( const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl storeVelocityAccumulators( hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl prefetchVelocityAccumulators( hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB )
	{
	}
__forceinline void __cdecl storeDelayedResult( hkpSolverElemTemp* delayedResult )
	{
		
	}
__forceinline hkReal __cdecl getLinearDv0( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; b.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.mul4( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline hkReal __cdecl getAngularDv0( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 b; b.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.add4( b );
		const hkSimdReal vel = a.horizontalAdd3();
		const hkSimdReal dv = jac.getAngularRhsSr() - vel;
		return dv;
	}
__forceinline hkReal __cdecl getLinearDv0UserTauWithCustomRhs( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 linVelA; linVelA.setSub4( mA.m_linearVel, mA.getSumLinearVel() );
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 linVelB; linVelB.setSub4( mB.m_linearVel, mB.getSumLinearVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			hkVector4 a; a.setSub4( linVelA, linVelB );
			hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
			a.mul4( jac.m_linear0 );
			b.add4( c );
			vel4.setAdd4( b, a );
		}
		hkVector4 svel4;
		{
			hkVector4 linVelA = mA.getSumLinearVel();
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 linVelB = mB.getSumLinearVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			hkVector4 a; a.setSub4( linVelA, linVelB );
			hkVector4 b; b.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 c; c.setMul4( angVelB, jac.m_angular[1] );
			a.mul4( jac.m_linear0 );
			b.add4( c );
			svel4.setAdd4( b, a );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		vel4.mul4( damping );
		hkVector4 dv; dv.setAdd4( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getLinearDv0UserTau( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping )
	{
		return getLinearDv0UserTauWithCustomRhs( jac, mA, mB, info, tau, damping, jac.getRHS() );
	}
__forceinline hkReal __cdecl getAngularDv0UserTauWithCustomRhs( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping, hkReal customAngularRhs )
	{
		hkVector4 vel4;
		{
			hkVector4 angVelA; angVelA.setSub4( mA.m_angularVel, mA.getSumAngularVel() );
			hkVector4 angVelB; angVelB.setSub4( mB.m_angularVel, mB.getSumAngularVel() );
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; b.setMul4( angVelB, jac.m_angular[1] );
			vel4.setAdd4( a, b );
		}
		hkVector4 svel4;
		{
			hkVector4 angVelA = mA.getSumAngularVel();
			hkVector4 angVelB = mB.getSumAngularVel();
			hkVector4 a; a.setMul4( angVelA, jac.m_angular[0] );
			hkVector4 b; b.setMul4( angVelB, jac.m_angular[1] );
			svel4.setAdd4( a, b );
		}
		const hkReal ru = info.m_invIntegrateVelocityFactor(0) * tau;
		svel4.mul4( ru );
		vel4.mul4( damping );
		hkVector4 dv; dv.setAdd4( svel4, vel4 );
		const hkReal rhsUpdate = dv.horizontalAdd3();
		return customAngularRhs * tau - rhsUpdate;
	}
__forceinline hkReal __cdecl getAngularDv0UserTau( const hkp2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkReal tau, hkReal damping )
	{
		return getAngularDv0UserTauWithCustomRhs( jac, mA, mB, info, tau, damping, jac.getAngularRhs() );
	}
__forceinline hkReal __cdecl getDv2Lin2Ang( const hkp2Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 lA; lA.setMul4( mA.m_linearVel, jac.m_linear[0] );
		hkVector4 lB; lB.setMul4( mB.m_linearVel, jac.m_linear[1] );
		hkVector4 a; a.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 b; b.setMul4( mB.m_angularVel, jac.m_angular[1] );
		hkVector4 c; c.setSub4( lA, lB );
		a.add4( b );
		a.add4( c );
		const hkSimdReal vel = a.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline hkReal __cdecl getLinearDv0_j0(const hkp1Lin2AngJacobian& jac,const hkpVelocityAccumulator& mA,const hkpVelocityAccumulator& mB,const hkpSolverInfo& info){
hkVector4 a;a.setSub4(mA.m_linearVel,mB.m_linearVel);hkVector4 b;b.setMul4(mA.m_angularVel,jac.m_angular[0]);hkVector4 c;c.setMul4(mB.m_angularVel,jac.m_angular[1]);
a.m4_1000(jac.m_linear0);b.add4(c);b.add4(a);const hkSimdReal vel=b.horizontalAdd3();const hkSimdReal dv=(((jac.getRhsSr()-vel)));return dv;}
__forceinline hkReal __cdecl getLinearDv0_j0_pc2(const hkp1Lin2AngJacobian& jac,const hkpVelocityAccumulator& mA,const hkpVelocityAccumulator& mB,const hkpSolverInfo& info){
hkVector4 a;a.setSub4(mA.m_linearVel,mB.m_linearVel);hkVector4 b;b.setMul4(mA.m_angularVel,jac.m_angular[0]);hkVector4 c;hkVector4::sm4_vv_c_dab(c,mB.m_angularVel,jac.m_angular[1]);
a.mul4(jac.m_linear0);b.add4(c);b.add4(a);const hkSimdReal vel=b.horizontalAdd3();const hkSimdReal dv=jac.getRhsSr()-vel;return dv;}
__forceinline void __cdecl getDv01_pc2( const hkp1Lin2AngJacobian* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut ){ velOut(0)=getLinearDv0_j0_pc2(jac[0],mA,mB,info); velOut(1)=getLinearDv0(jac[1],mA,mB,info); }
__forceinline void __cdecl getDv01( const hkp1Lin2AngJacobian* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut )
	{
		velOut(0) = getLinearDv0_j0( jac[0], mA, mB, info );
		velOut(1) = getLinearDv0( jac[1], mA, mB, info );
	}
__forceinline void __cdecl getDv012( const hkpJacTriple2Bil1Ang* jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, hkVector4& velOut )
	{
		velOut(0) = getLinearDv0_j0( jac->m_jac0, mA, mB, info );
		velOut(1) = getLinearDv0( jac->m_jac1, mA, mB, info );
		velOut(2) = getAngularDv0( jac->m_jac2, mA, mB, info );
	}
__forceinline void __cdecl applyImpulse( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear0 );
		negImpLinB.mul4( jac.m_linear0 );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( negImpLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse2Lin2Ang( const hkp2Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr, hkSimdRealParameter imp )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		hkVector4 impLinA; impLinA.setBroadcast3clobberW( impA, 3 );
		hkVector4 impLinB; impLinB.setBroadcast3clobberW( impB, 3 );
		impLinA.mul4( jac.m_linear[0] );
		impLinB.mul4( jac.m_linear[1] );
		mA.m_linearVel.add3clobberW( impLinA );
		mB.m_linearVel.sub3clobberW( impLinB );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyAngularImpulse( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		hkVector4 impA; impA.setMul4( imp, mA.m_invMasses );
		hkVector4 impB; impB.setMul4( imp, mB.m_invMasses );
		impA.mul4( jac.m_angular[0] );
		impB.mul4( jac.m_angular[1] );
		mA.m_angularVel.add3clobberW( impA );
		mB.m_angularVel.add3clobberW( impB );
		hkSimdReal total = sr.m_impulseApplied;
		total = total + imp;
		sr.m_impulseApplied = total;
	}
__forceinline void __cdecl applyImpulse0( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse1( hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl applyImpulse_lm_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4_s_keep(mB.m_invMasses,imp);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
mA.m_linearVel.a3_220(impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.a3_110(impA);mB.m_angularVel.a3_110(impB);
hkSimdReal total=sr.m_impulseApplied;total=total + imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_lm(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_lm_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse_ll2_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
mA.m_linearVel.a3_130(impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.a3_010(impA);mB.m_angularVel.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=(((total + imp)));sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_ll2(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_ll2_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse_slc_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr,hkVector4& angB){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
hkVector4::add3_c_ab_100(mA.m_linearVel,impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.a3_003(impA);angB.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=total + imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_slc(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_slc_i(imp,jac,mA,mB,sr,mB.m_angularVel);}
__forceinline void __cdecl applyImpulse_ut_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.sm_0130(imp,mA.m_invMasses);hkVector4 impB;impB.sm_0130(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
mA.m_linearVel.add3clobberW(impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.add3clobberW(impA);mB.m_angularVel.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=total + imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_ut(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_ut_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse_pc0_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
mA.m_linearVel.add3clobberW(impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.add3clobberW(impA);mB.m_angularVel.a3_100(impB);
hkSimdReal total=sr.m_impulseApplied;total=(((total + imp)));sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_pc0(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_pc0_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse_pc1_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.m4_1300(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
mA.m_linearVel.a3_100(impLinA);mB.m_linearVel.s3_300(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.a3_100(impA);mB.m_angularVel.a3_300(impB);
hkSimdReal total=sr.m_impulseApplied;total=total + imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_pc1(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_pc1_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse01_pc(hkSimdRealParameter imp0,hkSimdRealParameter imp1,const hkp1Lin2AngJacobian* jacs,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp* srs){applyImpulse_pc0(imp0,jacs[0],mA,mB,srs[0]);applyImpulse_pc1(imp1,jacs[1],mA,mB,srs[1]);}
__forceinline void __cdecl applyImpulse_sc_i(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(jac.m_linear0);negImpLinB.mul4(jac.m_linear0);
hkVector4::add3_c_ab(mA.m_linearVel,impLinA);mB.m_linearVel.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
mA.m_angularVel.add3clobberW(impA);mB.m_angularVel.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=total+imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_sc(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_sc_i(imp,jac,mA,mB,sr);}
__forceinline void __cdecl applyImpulse_pc20_i(const hkVector4& invMA,hkVector4& linB,hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr,hkVector4& linA){
hkVector4 impA;impA.ku_setMul4_3(imp,invMA,0,0,0);hkVector4 impB;impB.ku_setMul4_2(imp,mB.m_invMasses,0,0);
hkVector4 impLinA;impLinA.ku_setBroadcast3clobberW_1(impA,3,0);hkVector4 negImpLinB;negImpLinB.ku_setBroadcast3clobberW_1(impB,3,0);
impLinA.mul4(jac.m_linear0);negImpLinB.ku_mul4_1(jac.m_linear0,0);
linA.add3clobberW(impLinA);linB.sub3clobberW(negImpLinB);
impA.mul4(jac.m_angular[0]);impB.ku_mul4_6(jac.m_angular[1],0,0,0,0,0,0);
mA.m_angularVel.add3clobberW(impA);mB.m_angularVel.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=total+imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyImpulse_pc20(hkSimdRealParameter imp,const hkp1Lin2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyImpulse_pc20_i(mA.m_invMasses,mB.m_linearVel,imp,jac,mA,mB,sr,mA.m_linearVel);}
__forceinline void __cdecl applyImpulse01_pc2(hkSimdRealParameter imp0,hkSimdRealParameter imp1,const hkp1Lin2AngJacobian* jacs,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp* srs){applyImpulse_pc20(imp0,jacs[0],mA,mB,srs[0]);applyImpulse1(imp1,jacs[1],mA,mB,srs[1]);}
__forceinline void __cdecl applyImpulse01( hkSimdRealParameter imp0, hkSimdRealParameter imp1, const hkp1Lin2AngJacobian* jacs, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* srs )
	{
		applyImpulse0( imp0, jacs[0], mA, mB, srs[0] );
		applyImpulse1( imp1, jacs[1], mA, mB, srs[1] );
	}
__forceinline void __cdecl al1_fin(hkVector4& ia, hkVector4& ib, const hkp2AngJacobian& jp, hkVector4& a, hkVector4& b, hkpSolverElemTemp& srp, hkSimdRealParameter impp){ ia.mul4(jp.m_angular[0]); ib.mul4(jp.m_angular[1]); a.add3clobberW(ia); b.add3clobberW(ib); hkSimdReal total=srp.m_impulseApplied; total=total+impp; srp.m_impulseApplied=total; }
__forceinline void __cdecl applyAngularImpulse_al1_i(hkSimdRealParameter imp,const hkp2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr, const hkVector4& invMA){
hkVector4 impA;impA.setMul4(imp,invMA);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
al1_fin(impA, impB, jac, mA.m_angularVel, mB.m_angularVel, sr, imp);}
__forceinline void __cdecl applyAngularImpulse_al1(hkSimdRealParameter imp,const hkp2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyAngularImpulse_al1_i(imp,jac,mA,mB,sr, mA.m_invMasses);}
__forceinline void __cdecl applyAngularImpulse_al2_i(hkSimdRealParameter imp,const hkp2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr,hkVector4& angA){
hkVector4 impA;impA.setMul4(imp,mA.m_invMasses);hkVector4 impB;impB.setMul4(imp,mB.m_invMasses);
impA.mul4(jac.m_angular[0]);impB.mul4(jac.m_angular[1]);
angA.add3clobberW(impA);mB.m_angularVel.add3clobberW(impB);
hkSimdReal total=sr.m_impulseApplied;total=total+imp;sr.m_impulseApplied=total;}
__forceinline void __cdecl applyAngularImpulse_al2(hkSimdRealParameter imp,const hkp2AngJacobian& jac,hkpVelocityAccumulator& mA,hkpVelocityAccumulator& mB,hkpSolverElemTemp& sr){applyAngularImpulse_al2_i(imp,jac,mA,mB,sr,mA.m_angularVel);}
__forceinline void __cdecl applyAngularImpulse0( hkSimdRealParameter imp, const hkp2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr )
	{
		applyAngularImpulse( imp, jac, mA, mB, sr );
	}
__forceinline void __cdecl solve1dBilateral( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dBilateralSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getLinearDv0( schema.m_jac, mA, mB, info );
		const hkSimdReal impulse = ((((dv * schema.m_jac.getInvJacDiagSr()))));
		applyImpulse0( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dBilateralUserTau( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dBilateralUserTauSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkSimdReal dv = getLinearDv0UserTau( jac, mA, mB, info, schema.m_tau, schema.m_damping );
		const hkSimdReal impulse = dv * jac.getInvJacDiagSr();
		applyImpulse_ut( impulse, jac, mA, mB, *sr );
	}
__forceinline hkReal __cdecl getLinearDv0_ll( const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info )
	{
		hkVector4 a; a.setSub4_s2( mA.m_linearVel, mB.m_linearVel );
		hkVector4 b; b.setMul4( mA.m_angularVel, jac.m_angular[0] );
		hkVector4 c; c.setMul4( mB.m_angularVel, jac.m_angular[1] );
		a.mul4_s2( jac.m_linear0 );
		b.add4( c );
		b.add4( a );
		const hkSimdReal vel = b.horizontalAdd3();
		const hkSimdReal dv = jac.getRhsSr() - vel;
		return dv;
	}
__forceinline void __cdecl solve1dLinLimits( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dLinearLimitsSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkReal dv = getLinearDv0_ll( schema.m_jac, mA, mB, info );
		{
			hkReal impulse = dv - schema.m_minRhs;
			if ( impulse > 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyImpulse0( impulse, schema.m_jac, mA, mB, *sr );
			}
		}
		{
			hkReal impulse = dv - schema.m_maxRhs;
			if ( impulse < 0.0f )
			{
				impulse = schema.m_jac.getInvJacDiag() * impulse;
				applyImpulse_ll2( impulse, schema.m_jac, mA, mB, *sr );
			}
		}
	}
__forceinline void __cdecl solve1dFriction( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkReal dv0 = getLinearDv0( schema.m_jac, mA, mB, info );
		hkReal imp0 = schema.m_jac.getInvJacDiag() * dv0;
		const hkReal fimp0 = hkMath::fabs( imp0 );
		if ( fimp0 > schema.m_maxImpulse )
		{
			const hkReal factor = schema.m_maxImpulse / fimp0;
			imp0 *= factor;
			sr[1].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyImpulse0( imp0, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dLinearMotor( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dLinearMotorSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkpSolverElemTemp& sr1 = sr[1];
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkp1dMotorSolverInfo& motorInfo = schema.m_motorSolverInfo;
		sr[2].m_deltaRhs = temp.m_intregratePositions * motorInfo.m_velocity + sr[2].m_deltaRhs;
		const hkReal customRhs = jac.getRHS() + sr[2].m_deltaRhs;
		const hkReal dv0 = getLinearDv0UserTauWithCustomRhs( jac, mA, mB, info, motorInfo.m_tau, motorInfo.m_damping, customRhs );
		hkReal impulse = jac.getInvJacDiag() * dv0;
		if ( impulse > motorInfo.m_maxImpulsePerSubstep )
		{
			sr1.m_usedImpulseFactor = motorInfo.m_maxImpulsePerSubstep / impulse;
			impulse = motorInfo.m_maxImpulsePerSubstep;
		}
		else if ( impulse < motorInfo.m_minImpulsePerSubstep )
		{
			sr1.m_usedImpulseFactor = motorInfo.m_minImpulsePerSubstep / impulse;
			impulse = motorInfo.m_minImpulsePerSubstep;
		}
		else
		{
			sr1.m_usedImpulseFactor = 1.0f;
		}
		applyImpulse_lm( impulse, jac, mA, mB, *sr );
	}
__forceinline void __cdecl pad_4() { int p_0 = 0; int p_1 = 0; int p_2 = 0; int p_3 = 0; }
__forceinline void __cdecl solvePulley( const hkpSolverInfo& info, const hkpJacobian1dPulleySchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp2Lin2AngJacobian& jac = schema.m_jac;
		applyImpulse2Lin2Ang( jac, mA, mB, sr[0], getDv2Lin2Ang( jac, mA, mB, info ) * jac.getInvJacDiagSr() );
	}
__forceinline void __cdecl solve1dAngular( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getAngularDv0( schema.m_jac, mA, mB, info );
		const hkSimdReal impulse = dv * schema.m_jac.getInvJacDiagSr();
		applyAngularImpulse0( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dAngLimits( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularLimitsSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp2AngJacobian& jac = schema.m_jac;
		const hkReal dv = getAngularDv0UserTau( jac, mA, mB, info, schema.m_tau, info.m_damping );
		{
			hkReal impulse = dv - schema.m_minRhs;
			if ( impulse > 0.0f )
			{
				impulse = jac.getInvJacDiag() * impulse;
				applyAngularImpulse_al1( impulse, jac, mA, mB, *sr );
				return;
			}
		}
		{
			hkReal impulse = dv - schema.m_maxRhs;
			if ( impulse < 0.0f )
			{
				impulse = jac.getInvJacDiag() * impulse;
				applyAngularImpulse_al2( impulse, jac, mA, mB, *sr );
			}
		}
	}
__forceinline void __cdecl solve1dAngFriction( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp2AngJacobian& jac = schema.m_jac;
		const hkReal dv0 = getAngularDv0( jac, mA, mB, info );
		hkReal imp0 = jac.getInvJacDiag() * dv0;
		const hkReal fimp0 = hkMath::fabs( imp0 );
		if ( fimp0 > schema.m_maxImpulse )
		{
			const hkReal factor = schema.m_maxImpulse / fimp0;
			imp0 *= factor;
			sr[1].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyAngularImpulse0( imp0, jac, mA, mB, *sr );
	}
__forceinline void __cdecl solve1dAngularMotor( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobian1dAngularMotorSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1dMotorSolverInfo& motorInfo = schema.m_motorSolverInfo;
		sr[2].m_deltaRhs = temp.m_intregratePositions * motorInfo.m_velocity + sr[2].m_deltaRhs;
		const hkReal customAngularRhs = schema.m_jac.getAngularRhs() + sr[2].m_deltaRhs;
		const hkReal dv0 = getAngularDv0UserTauWithCustomRhs( schema.m_jac, mA, mB, info, motorInfo.m_tau, motorInfo.m_damping, customAngularRhs );
		hkReal impulse = schema.m_jac.getInvJacDiag() * dv0;
		if ( impulse > motorInfo.m_maxImpulsePerSubstep )
		{
			sr[1].m_usedImpulseFactor = motorInfo.m_maxImpulsePerSubstep / impulse;
			impulse = motorInfo.m_maxImpulsePerSubstep;
		}
		else if ( impulse < motorInfo.m_minImpulsePerSubstep )
		{
			sr[1].m_usedImpulseFactor = motorInfo.m_minImpulsePerSubstep / impulse;
			impulse = motorInfo.m_minImpulsePerSubstep;
		}
		else
		{
			sr[1].m_usedImpulseFactor = 1.0f;
		}
		applyAngularImpulse0( impulse, schema.m_jac, mA, mB, *sr );
	}
__forceinline void __cdecl solveSingleContact( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobianSingleContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkSimdReal dv = getLinearDv0( schema.m_jac, mA, mB, info );
		if ( !hkMath::isNegative( dv ) )
		{
			const hkReal invJacDiag = schema.m_jac.getInvJacDiagSr();
			const hkSimdReal impulse = dv * invJacDiag;
			applyImpulse_sc( impulse, schema.m_jac, mA, mB, *sr );
		}
	}
__forceinline void __cdecl solveSingleLimitContact( const hkpSolverInfo& info, const SolverStepTemp& temp, const hkpJacobianSingleContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkp1Lin2AngJacobian& jac = schema.m_jac;
		const hkSimdReal dv = getLinearDv0( jac, mA, mB, info );
		if ( !hkMath::isNegative( dv ) )
		{
			hkSimdReal impulse = dv * jac.getInvJacDiagSr();
			const hkSimdReal maxImpulse = jac.getUserValueSr();
			const hkSimdReal impulseApplied = sr->m_impulseApplied;
			const hkSimdReal sumImpulse = impulseApplied + impulse;
			if ( sumImpulse > maxImpulse )
			{
				impulse = maxImpulse - impulseApplied;
			}
			applyImpulse_slc( impulse, jac, mA, mB, *sr );
		}
	}
__forceinline void __cdecl solvePairContact( const hkpSolverInfo& info, const hkpJacobianPairContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkpJacDouble2Bil& jac = schema.m_jac;
		hkVector4 dv4;
		getDv01( &jac.m_jac0, mA, mB, info, dv4 );
		const hkReal dv0 = dv4(0);
		const hkp1Lin2AngJacobian& jac1 = jac.m_jac1;
		const hkReal dv1 = dv4(1);
		hkReal imp0 = jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp1 = jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		if ( imp0 > 0.0f )
		{
			if ( imp1 > 0.0f )
			{
				applyImpulse01_pc( imp0, imp1, &jac.m_jac0, mA, mB, sr );
			}
			else
			{
checkImp0:
				const hkReal imp01 = jac.m_jac0.getInvJacDiag() * dv0;
				if ( imp01 > 0.0f )
				{
					applyImpulse0( imp01, jac.m_jac0, mA, mB, sr[0] );
				}
			}
		}
		else
		{
			const hkReal imp10 = ( jac1.getInvJacDiag() * dv1 );
			if ( imp10 <= 0.0f )
			{
				goto checkImp0;
			}
			applyImpulse1( imp10, jac1, mA, mB, sr[1] );
		}
	}
__forceinline void __cdecl solvePairContact2( const hkpSolverInfo& info, const hkpJacobianPairContactSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		const hkpJacDouble2Bil& jac = schema.m_jac;
		hkVector4 dv4;
		getDv01_pc2( &jac.m_jac0, mA, mB, info, dv4 );
		const hkReal dv0 = dv4(0);
		hkReal imp0 = 0.0f; hkReal imp1 = 0.0f; hkReal imp01 = 0.0f; hkReal imp10 = 0.0f;
		const hkp1Lin2AngJacobian& jac1 = jac.m_jac1;
		const hkReal dv1 = dv4(1);
		imp0 = ( jac.m_jac0.getUserValue() * dv0 ) + dv1 * schema.m_invJac01;
		imp1 = jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		if ( imp0 > 0.0f )
		{
			if ( imp1 > 0.0f )
			{
				applyImpulse01_pc2( imp0, imp1, &jac.m_jac0, mA, mB, sr );
			}
			else
			{
checkImp0:
				imp01 = jac.m_jac0.getInvJacDiag() * dv0;
				if ( imp01 > 0.0f )
				{
					applyImpulse0( imp01, jac.m_jac0, mA, mB, sr[0] );
				}
			}
		}
		else
		{
			imp10 = jac1.getInvJacDiag() * dv1;
			if ( imp10 <= 0.0f )
			{
				goto checkImp0;
			}
			applyImpulse1( imp10, jac1, mA, mB, sr[1] );
		}
	}
__forceinline void __cdecl solve2dFriction( const hkpSolverInfo& info, const hkpJacobian2dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkVector4 vel4;
		getDv01( &schema.m_jac.m_jac0, mA, mB, info, vel4 );
		const hkReal dv0 = vel4(0);
		const hkReal dv1 = vel4(1);
		const hkReal maxImpulse = schema.m_maxImpulse;
		const hkReal maxSquared = maxImpulse * maxImpulse;
		hkReal imp0 = schema.m_jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal imp1 = schema.m_jac.m_jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
		if ( impSquared > maxSquared )
		{
			const hkReal factor = hkMath::sqrt( maxSquared / impSquared );
			imp0 *= factor;
			imp1 *= factor;
			sr[2].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[2].m_usedImpulseFactor = 1.0f;
		}
		applyImpulse01( imp0, imp1, &schema.m_jac.m_jac0, mA, mB, sr );
	}
__forceinline void __cdecl solve3dFriction( const hkpSolverInfo& info, const hkpJacobian3dFrictionSchema& schema, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp* sr, hkpSolverElemTemp*& delayedResult )
	{
		hkVector4 vel4;
		getDv012( &schema.m_jac, mA, mB, info, vel4 );
		const hkReal dv0 = vel4(0);
		const hkReal dv1 = vel4(1);
		const hkReal dva = vel4(2);
		hkReal angularImp = schema.m_jac.m_jac2.getInvJacDiag() * dva;
		const hkReal maxSquared = schema.m_maxImpulse * schema.m_maxImpulse;
		hkReal imp0 = schema.m_jac.m_jac0.getUserValue() * dv0 + dv1 * schema.m_invJac01;
		hkReal impSquared = 0.0f;
		hkReal imp1 = schema.m_jac.m_jac1.getUserValue() * dv1 + dv0 * schema.m_invJac01;
		impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
		if ( impSquared > maxSquared )
		{
			const hkReal factor = schema.m_maxImpulse * hkMath::sqrtInverse( impSquared );
			imp0 *= factor;
			imp1 *= factor;
			angularImp *= factor;
			sr[3].m_usedImpulseFactor = factor;
		}
		else
		{
			sr[3].m_usedImpulseFactor = 1.0f;
		}
		angularImp *= schema.m_contactRadius;
		applyImpulse01( imp0, imp1, &schema.m_jac.m_jac0, mA, mB, sr );
		applyAngularImpulse0( angularImp, schema.m_jac.m_jac2, mA, mB, sr[2] );
	}
}
extern "C" void __cdecl hkSolver_solveStiffSpringChain( const hkpSolverInfo& info, const hkSolver::SolverStepTemp& temp, hkpVelocityAccumulator* accums, const hkpJacobianStiffSpringChainSchema* chain, hkpSolverElemTemp* sr );
extern "C" void __cdecl hkSolver_solveBallAndSocketChain( const hkpSolverInfo& info, const hkSolver::SolverStepTemp& temp, hkpVelocityAccumulator* accums, const hkpJacobianBallSocketChainSchema* chain, hkpSolverElemTemp* sr );
namespace hkSolver
{
__forceinline int __cdecl stepJacobian( const hkpSolverInfo& info, SolverStepTemp& temp, const hkpJacobianSchema* schemas, hkpVelocityAccumulator* accums, hkpSolverElemTemp* srIn )
	{
		const hkpJacobianSchema* com = schemas;
		hkpSolverElemTemp* sr = srIn;
		int schemaType = hkpJacobianSchema::getType( com );
		if ( schemaType == hkpJacobianSchema::SCHEMA_TYPE_END )
		{
			return 0;
		}
		;
		hkpVelocityAccumulator* mA;
		hkpVelocityAccumulator* mB;
		hkpSolverElemTemp* delayedResult = 0;
		goto headerNoStoreVelocity;
		while ( 1 )
		{
			schemaType = hkpJacobianSchema::getType( com );
			switch ( schemaType )
			{
				case hkpJacobianSchema::SCHEMA_TYPE_HEADER:
header:
					{
						const hkpJacobianHeaderSchema* sc = reinterpret_cast<const hkpJacobianHeaderSchema*>( com );
						prefetchVelocityAccumulators( *sc->getBodyA( accums ), *sc->getBodyB( accums ) );
						storeVelocityAccumulators( *mA, *mB );
headerNoStoreVelocity:
						{
							const hkpJacobianHeaderSchema* sc2 = reinterpret_cast<const hkpJacobianHeaderSchema*>( com );
							mA = sc2->getBodyA( accums );
							mB = sc2->getBodyB( accums );
							loadVelocityAccumulators( *mA, *mB );
							com = reinterpret_cast<const hkpJacobianSchema*>( sc2 + 1 );
						}
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SHIFT_SOLVER_RESULTS_POINTER:
					{
						const hkpJacobianShiftSolverResultsPointerSchema* sc = reinterpret_cast<const hkpJacobianShiftSolverResultsPointerSchema*>( com );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT_WITH_ACCESSOR_CHECK:
case_SCHEMA_TYPE_SINGLE_CONTACT:
					{
						const hkpJacobianSingleContactSchema* sc = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
						solveSingleContact( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_SINGLE_CONTACT ) goto case_SCHEMA_TYPE_SINGLE_CONTACT;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT_WITH_ACCESSOR_CHECK:
case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
					{
						const hkpJacobianSingleContactSchema* sc = reinterpret_cast<const hkpJacobianSingleContactSchema*>( com );
						solveSingleLimitContact( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_SINGLE_LIMIT_CONTACT ) goto case_SCHEMA_TYPE_SINGLE_LIMIT_CONTACT;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT:
				case hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT_WITH_ACCESSOR_CHECK:
					{
						{
							const hkpJacobianPairContactSchema* sc = reinterpret_cast<const hkpJacobianPairContactSchema*>( com );
							solvePairContact( info, *sc, *mA, *mB, sr, delayedResult );
							sr += 2;
							com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						}
						if ( hkpJacobianSchema::getType( com ) != hkpJacobianSchema::SCHEMA_TYPE_PAIR_CONTACT )
						{
							continue;
						}
						{
							const hkpJacobianPairContactSchema* sc = reinterpret_cast<const hkpJacobianPairContactSchema*>( com );
							solvePairContact2( info, *sc, *mA, *mB, sr, delayedResult );
							sr += 2;
							com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						}
						if ( hkpJacobianSchema::getType( com ) != hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION )
						{
							break;
						}
					}
				case hkpJacobianSchema::SCHEMA_TYPE_3D_FRICTION:
					{
						const hkpJacobian3dFrictionSchema* sc = reinterpret_cast<const hkpJacobian3dFrictionSchema*>( com );
						solve3dFriction( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 4;
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_HEADER ) goto header;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_2D_FRICTION:
					{
						const hkpJacobian2dFrictionSchema* sc = reinterpret_cast<const hkpJacobian2dFrictionSchema*>( com );
						solve2dFriction( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 3;
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_HEADER ) goto header;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_SCHEMA_TYPE_1D_ANGULAR_FRICTION:
					{
						const hkpJacobian1dAngularFrictionSchema* sc = reinterpret_cast<const hkpJacobian1dAngularFrictionSchema*>( com );
						solve1dAngFriction( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_FRICTION ) goto case_SCHEMA_TYPE_1D_ANGULAR_FRICTION;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_SCHEMA_TYPE_1D_ANGULAR_LIMITS:
					{
						const hkpJacobian1dAngularLimitsSchema* sc = reinterpret_cast<const hkpJacobian1dAngularLimitsSchema*>( com );
						solve1dAngLimits( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_LIMITS ) goto case_SCHEMA_TYPE_1D_ANGULAR_LIMITS;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_SCHEMA_TYPE_1D_ANGULAR_MOTOR:
					{
						const hkpJacobian1dAngularMotorSchema* sc = reinterpret_cast<const hkpJacobian1dAngularMotorSchema*>( com );
						solve1dAngularMotor( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR_MOTOR ) goto case_SCHEMA_TYPE_1D_ANGULAR_MOTOR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR:
case_SCHEMA_TYPE_1D_ANGULAR:
					{
						const hkpJacobian1dAngularSchema* sc = reinterpret_cast<const hkpJacobian1dAngularSchema*>( com );
						solve1dAngular( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_ANGULAR ) goto case_SCHEMA_TYPE_1D_ANGULAR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL:
case_SCHEMA_TYPE_1D_BILATERAL:
					{
						const hkpJacobian1dBilateralSchema* sc = reinterpret_cast<const hkpJacobian1dBilateralSchema*>( com );
						solve1dBilateral( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL ) goto case_SCHEMA_TYPE_1D_BILATERAL;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
					{
						const hkpJacobian1dBilateralUserTauSchema* sc = reinterpret_cast<const hkpJacobian1dBilateralUserTauSchema*>( com );
						solve1dBilateralUserTau( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_BILATERAL_USER_TAU ) goto case_SCHEMA_TYPE_1D_BILATERAL_USER_TAU;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_FRICTION:
case_SCHEMA_TYPE_1D_FRICTION:
					{
						const hkpJacobian1dFrictionSchema* sc = reinterpret_cast<const hkpJacobian1dFrictionSchema*>( com );
						solve1dFriction( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_FRICTION ) goto case_SCHEMA_TYPE_1D_FRICTION;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_SCHEMA_TYPE_1D_LINEAR_LIMITS:
					{
						const hkpJacobian1dLinearLimitsSchema* sc = reinterpret_cast<const hkpJacobian1dLinearLimitsSchema*>( com );
						solve1dLinLimits( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_LIMITS ) goto case_SCHEMA_TYPE_1D_LINEAR_LIMITS;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_SCHEMA_TYPE_1D_LINEAR_MOTOR:
					{
						const hkpJacobian1dLinearMotorSchema* sc = reinterpret_cast<const hkpJacobian1dLinearMotorSchema*>( com );
						solve1dLinearMotor( info, temp, *sc, *mA, *mB, sr, delayedResult );
						sr += hkpJacobianSchema::getNumSolverElemTemps( com );
						const int nextType = hkpJacobianSchema::getType( reinterpret_cast<const hkpJacobianSchema*>( sc + 1 ) );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						if ( nextType == hkpJacobianSchema::SCHEMA_TYPE_1D_LINEAR_MOTOR ) goto case_SCHEMA_TYPE_1D_LINEAR_MOTOR;
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_1D_PULLEY:
					{
						const hkpJacobian1dPulleySchema* sc = reinterpret_cast<const hkpJacobian1dPulleySchema*>( com );
						solvePulley( info, *sc, *mA, *mB, sr, delayedResult );
						sr += 1;
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_SET_MASS:
					{
						const hkpJacobianSetMassSchema* sc = reinterpret_cast<const hkpJacobianSetMassSchema*>( com );
						storeVelocityAccumulators( *mA, *mB );
						mA->m_invMasses = sc->m_invMass0;
						mB->m_invMasses = sc->m_invMass1;
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						loadVelocityAccumulators( *mA, *mB );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_ADD_VELOCITY:
					{
						const hkpJacobianAddVelocitySchema* sc = reinterpret_cast<const hkpJacobianAddVelocitySchema*>( com );
						storeVelocityAccumulators( *mA, *mB );
						hkpVelocityAccumulator* accum = hkSelect( sc->m_bodyIndex, mA, mB );
						pad_4();
						hkVector4 sumVel; sumVel.setMul4_swap( sc->m_deltaVel, hkReal( temp.m_currentStep ) * info.m_integrateVelocityFactor(0) );
						accum->m_linearVel.add4_0013( sc->m_deltaVel );
						accum->m_linearVel.add4( sumVel );
						accum->getSumLinearVel().add4( sumVel );
						com = reinterpret_cast<const hkpJacobianSchema*>( sc + 1 );
						loadVelocityAccumulators( *mA, *mB );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_GOTO:
					{
						const hkpJacobianGotoSchema* sc = reinterpret_cast<const hkpJacobianGotoSchema*>( com );
						com = hkAddByteOffsetConst( com, sc->m_offset );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_END:
					storeDelayedResult( delayedResult );
					storeVelocityAccumulators( *mA, *mB );
					return 0;
				case hkpJacobianSchema::SCHEMA_TYPE_STIFF_SPRING_CHAIN:
					{
						const hkpJacobianStiffSpringChainSchema* chain = reinterpret_cast<const hkpJacobianStiffSpringChainSchema*>( com );
						::f3m_00a0b990::FUN_00a0b990( (::f3m_00a0b990::f3m_00a0b990::S0a0b990_Info*)&info, (void*)&temp, (char*)accums, (::f3m_00a0b990::f3m_00a0b990::S0a0b990_Chain*)chain, (float*)sr );
						sr += chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_BALL_SOCKET_CHAIN:
					{
						const hkpJacobianBallSocketChainSchema* chain = reinterpret_cast<const hkpJacobianBallSocketChainSchema*>( com );
						::f3m_00a0c070::FUN_00a0c070( (const ::f3m_00a0c070::f3_a0c070::SolverInfo&)info, (const ::f3m_00a0c070::f3_a0c070::SolverStepTemp&)temp, (::f3m_00a0c070::f3_a0c070::VelocityAccumulator*)accums, (::f3m_00a0c070::f3_a0c070::BallSocketChainSchema*)chain, (::f3m_00a0c070::f3_a0c070::SolverElemTemp*)sr );
						sr += 3 * chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				case hkpJacobianSchema::SCHEMA_TYPE_POWERED_CHAIN:
					{
						const hkpJacobianPoweredChainSchema* chain = reinterpret_cast<const hkpJacobianPoweredChainSchema*>( com );
						::f3m_00a0e5d0::f3m_00a0e5d0::FUN_00a0e5d0( (const ::f3m_00a0e5d0::f3m_00a0e5d0::hkpSolverInfo&)info, (const ::f3m_00a0e5d0::f3m_00a0e5d0::hkSolver::SolverStepTemp&)temp, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpVelocityAccumulator*)accums, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpJacobianPoweredChainSchema*)chain, (::f3m_00a0e5d0::f3m_00a0e5d0::hkpSolverElemTemp*)sr );
						sr += 6 * chain->m_numConstraints;
						com = hkAddByteOffsetConst( com, chain->m_size );
						break;
					}
				default:
					fnv_Breakpoint();
					return 0;
			}
		}
	}
}
extern hkBool HK_flyingcolors_solver;
extern "C" bool __cdecl processFlyingColors( int );
// pdb: hkSolveConstraintsByTheSteps | hkpSolver.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: info, currentSolverStep, currentSolverMicroStep, schemas, accumulators, elemTemp
int __cdecl FUN_00a1b9f0( const hkpSolverInfo& info, int currentSolverStep, int currentSolverMicroStep, const hkpJacobianSchema* schemas, hkpVelocityAccumulator* accumulators, hkpSolverElemTemp* elemTemp )
{
	if ( !HK_flyingcolors_solver )
	{
		HK_flyingcolors_solver = processFlyingColors( 0 );
		if ( !HK_flyingcolors_solver )
		{
			return 0;
		}
	}
	hkSolver::SolverStepTemp temp;
	temp.m_currentStep = currentSolverStep;
	temp.m_intregratePositions = ( currentSolverMicroStep ) ? 0.0f : 1.0f;
	hkSolver::stepJacobian( info, temp, schemas, accumulators, elemTemp );
	return 1;
}

}  // namespace f3m_00a1b9f0
