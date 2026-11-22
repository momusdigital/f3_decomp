#include <math.h>
#include <math.h>
#include <windows.h>
// src/f3staging/f3blk_00a40000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00a433d0 (community match, verified in this file)
namespace f3m_00a433d0 {

// FUN_00a433d0 = Havok 5.5.0 hk4dGskCollideCalcToi (hkpInternal.lib, hkpContinuousGsk.obj) as the game links it:
// the game's build also welds the TOI contact against a triangle on body A (an else-if branch after the body-B
// weld), which the SDK's library object does not have. REWRITTEN from the SDK's debug records (release and hybrid
// line records, locals, blocks, pdb layouts; hkpContinuousGsk.cpp is not shipped) on the SDK headers, then cut with
// hktrim.py; the body-A branch follows the New Vegas twin's shape (fnv_decomp, community text). See note.txt.
namespace f3m_00a433d0 {
typedef float hkReal;
typedef signed char hkInt8;
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
enum HK_MEMORY_CLASS { HK_MEMORY_CLASS_ROOT };
class hkMemory;
class hkThreadMemory
{
	public:
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void alignedDeallocate(void* ptr);
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
			PAGE_ALIGN = 64,
			MEMORY_MAX_SMALL_ROW = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK = 512,
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
		__forceinline virtual ~hkBaseObject() {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
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
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline hkBool __cdecl equal(hkReal x, hkReal y, hkReal tolerance2=1e-5f)
	{
		return hkMath::fabs(x-y) < tolerance2;
	}
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
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline int getInt24W( ) const ;
		__forceinline void add4(const hkVector4& a);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
	public:
		hkVector4 m_vec;
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkMatrix3::hkMatrix3( const hkMatrix3& other )
{
	m_col0 = other.m_col0;
	m_col1 = other.m_col1;
	m_col2 = other.m_col2;
}
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkTransform& r);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
	public:
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
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
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
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
inline int hkVector4::getInt24W( ) const
{
	return (reinterpret_cast<const int*>(this))[3] & ~0x3f000000;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& m0, const hkVector4& m1)
{
	x = a.x + m0.x * m1.x;
	y = a.y + m0.y * m1.y;
	z = a.z + m0.z * m1.z;
	w = a.w + m0.w * m1.w;
}
	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = v.w;
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
	inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
	inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
		t(1) = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
		t(2) = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
		t(3) = 0;
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
	inline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0) - t(0,3);
		hkReal v1 = v(1) - t(1,3);
		hkReal v2 = v(2) - t(2,3);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(1,0)*v1 + t(2,0)*v2;
		d(1) = t(0,1)*v0 + t(1,1)*v1 + t(2,1)*v2;
		d(2) = t(0,2)*v0 + t(1,2)*v1 + t(2,2)*v2;
		d(3) = 0.0f;
	}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w );
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
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
hkTime hkSweptTransform::getBaseTime() const
{
	return hkTime(m_centerOfMass0(3));
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
hkReal hkSweptTransform::getInterpolationValue( hkTime t ) const
{
	hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
	return dt;
}
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
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base )
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
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb
{
	public:
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
class hkSphere
{
	public:
	protected:
		hkVector4 m_pos;
};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		inline hkVector4& getPosition();
		inline const hkVector4& getNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setDistance( hkReal d );
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setSeparatingNormal( const hkVector4& separatingNormal )
{
	m_separatingNormal = separatingNormal;
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
class hkpCdVertex: public hkVector4
{
	public:
		int getId() const { return getInt24W(); }
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
enum { HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		__forceinline hkpShapeType getType() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc) (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int (__cdecl *GetNumCollisionSpheresFunc) (const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc) (const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc> m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc> m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc> m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc> m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc> m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc> m_getAabbFunc;
				hkPadSpu<CastRayFunc> m_castRay;
				hkPadSpu<GetChildShapeFunc> m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc> m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc m_convertVertexIdsToVertices;
				WeldContactPointFunc m_weldContactPointFunc;
				GetCentreFunc m_getCentreFunc;
				GetNumCollisionSpheresFunc m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc m_getCollisionSpheresFunc;
				GetAabbFunc m_getAabbFunc;
				CastRayFunc m_castRay;
				GetChildShapeFunc m_getChildShapeFunc;
				GetCollisionFilterInfoFunc m_getCollisionFilterInfoFunc;
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
class hkMotionState;
class hkpCdBody
{
	public:
		friend class hkpCollidable;
		__forceinline const hkpShape* getShape() const;
	public:
		__forceinline const hkMotionState* getMotionState() const;
	public:
		const hkpShape* m_shape;
		hkpShapeKey m_shapeKey;
		const void* m_motion;
		const hkpCdBody* m_parent;
};
const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
struct hkpAgentEntry
{
	hkUchar m_streamCommand;
	hkUchar m_agentType;
	hkUchar m_numContactPoints;
	hkUchar m_size;
};
struct hkpAgent3Input
{
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform m_aTb;
};
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	hkPadSpu<hkReal> m_distAtT1;
	hkPadSpu<int> m_offsetPpuSectorMinusSpuSector;
	hkVector4 m_linearTimInfo;
};
struct hkpCollisionQualityInfo
{
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32> m_useContinuousPhysics;
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
struct hkpProcessCollisionData;
class hkpGskCache;
class hkpSolverResults
{
	public:
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
inline void hkpSolverResults::init()
{
	m_impulseApplied = 0.0f;
	m_internalSolverData = 0.0f;
}
inline hkpSolverResults::hkpSolverResults()
{
	init();
}
class hkContactPointMaterial
{
	public:
		inline void setUserData( hkUlong data );
	protected:
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		enum FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
inline void hkContactPointMaterial::setUserData( hkUlong data )
{
	m_userData = data;
}
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
};
__declspec(align(16)) class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
	public:
		void set(const hkContactPointPropertiesWithExtendedUserData16& other)
		{
			*this = other;
		}
		hkpContactPointProperties::UserData m_extendedUserDatas[7];
};
class hkpContactMgr: public hkReferencedObject
{
	public:
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
		__forceinline ToiAccept addToi( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut );
		__forceinline void removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties );
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
hkpContactMgr::ToiAccept hkpContactMgr::addToi( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut )
{
	return addToiImpl( a, b, input, output, toi, cp, gskCache, projectedVelocity, propertiesOut );
}
void hkpContactMgr::removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties )
{
	removeToiImpl( constraintOwner, properties );
}
struct hkpProcessCdPoint
{
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};
class hkMotionState
{
	public:
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
class hkpSphereRepShape : public hkpShape
{
	public:
		__forceinline int getNumCollisionSpheres( ) const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl( ) const = 0;
		virtual const hkSphere* getCollisionSpheresImpl( hkSphere* sphereBuffer ) const = 0;
};
int hkpSphereRepShape::getNumCollisionSpheres( ) const
{
	return this->getNumCollisionSpheresImpl( );
}
const hkSphere* hkpSphereRepShape::getCollisionSpheres( hkSphere* sphereBuffer ) const
{
	return this->getCollisionSpheresImpl( sphereBuffer );
}
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl( hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl( hkVector4& centreOut ) const;
	protected:
		hkReal m_radius;
};
inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}
void hkpConvexShape::convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const
{
	this->convertVertexIdsToVerticesImpl( ids, numIds, vertixArrayOut );
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
															hkVector4& contactPointWs, const hkTransform* thisObjTransform,
															const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const
{
	return (WeldResult)this->weldContactPointImpl(	featurePoints, numFeaturePoints,
													contactPointWs, thisObjTransform,
													collidingShape, collidingTransform, separatingNormalInOut );
}
class hkpCollideTriangleUtil
{
	public:
		struct ClosestLineSegLineSegResult
		{
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal> m_distanceSquared;
		};
};
class hkpGskCache
{
	public:
		hkUint16 m_vertices[4];
		hkUint8 m_dimA;
		hkUint8 m_dimB;
		enum MaxDim
		{
			MAX_DIM_MAX = 15
		};
		hkUint8 m_maxDimA : 4;
		hkUint8 m_maxDimB : 4;
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER = 0x01,
			GSK_FLAGS_SHAPE_B_IS_CYLINDER = 0x02,
			GSK_FLAGS_REPLACE_SHAPE_A_WITH_CAPSULE = 0x04,
			GSK_FLAGS_REPLACE_SHAPE_B_WITH_CAPSULE = 0x08,
			GSK_FLAGS_CYLINDER_AGENT_FLAGS = 0x0f,
			GSK_FLAGS_DISABLE_CONTACT_TIMS = 0x10,
			GSK_FLAGS_CONVEX_LIST_IN_GSK_MODE = 0x20,
			GSK_FLAGS_PROCESS_FUNCTION_CALLED = 0x40,
			ONE_BIT_STILL_UNUSED = 0x80
		};
		hkUint8 m_gskFlags;
};
__declspec(align(16)) class hkGskCache16 : public hkpGskCache
{
	public:
		void set(const hkGskCache16& other)
		{
				*this = other;
		}
};
enum hkpGskStatus
{
	HK_GSK_OK = 0,
	HK_GSK_PD_HEURISTIC_SAMPLING = 1,
	HK_GSK_PD_OUT_OF_MEMORY = 2,
	HK_GSK_PD_UNSOLVABLE = 3,
	HK_GSK_PENETRATING = 4
};
class hkpGsk
{
	public:
		enum
		{
			GSK_NONE_NONE = 0,
			GSK_POINT_POINT = 9,
			GSK_POINT_EDGE = 10,
			GSK_EDGE_POINT = 17,
			GSK_POINT_TRIANGLE = 11,
			GSK_TRIANGLE_POINT = 25,
			GSK_EDGE_TRIANGLE = 19,
			GSK_TRIANGLE_EDGE = 26,
			GSK_POINT_TETRA = 12,
			GSK_TETRA_POINT = 33,
			GSK_EDGE_EDGE = 18
		};
		enum NextCase
		{
			NEXT_IS_BREAK = 0,
			NEXT_IS_PENETRATION = 1,
			NEXT_IS_EDGE_EDGE = 2
		};
		enum SupportTypes
		{
			BUILD_NEG_SUPPORT = -8,
			BUILD_NO_SUPPORT = 0,
			BUILD_POS_SUPPORT = 8
		};
		enum SupportState
		{
			SUPPORT_CHANGED = 0,
			DONT_CALL_GET_SUPPORTING_VERTEX_A = 8,
			DONT_CALL_GET_SUPPORTING_VERTEX_B = -8
		};
		enum ReduceDimensionResult
		{
			REDUCE_DIMENSION_OK = 0,
			REDUCE_DIMENSION_PENETRATION = 1
		};
		struct GetClosesetPointInput
		{
			hkPadSpu<const hkTransform*> m_aTb;
			hkPadSpu<const hkTransform*> m_transformA;
			hkPadSpu<const hkpConvexShape*> m_shapeA;
			hkPadSpu<const hkpConvexShape*> m_shapeB;
			hkPadSpu<hkReal> m_collisionTolerance;
		};
		hkpGsk();
		void init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkpGskCache& cache );
		hkpGskStatus getClosestFeature( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb, hkVector4& separatingNormal );
		void getClosestPointAinA( const hkVector4& separatingNormal, hkVector4& pointOnAinA );
		void checkForChangesAndUpdateCache( hkpGskCache& cache );
	public:
		void exitAndExportCacheImpl( hkpGskCache& cache ) const;
	public:
		hkPadSpu<int> m_dimA;
		hkPadSpu<int> m_dimB;
		hkPadSpu<int> m_maxDimA;
		hkPadSpu<int> m_maxDimB;
		hkPadSpu<hkUint32> m_doNotHandlePenetration;
		hkPadSpu<int> m_featureChange;
		hkpCdVertex m_verticesA[4];
		hkVector4 m_dummy[4];
		hkVector4 m_verticesBinA[4];
		hkpCdVertex m_verticesBinB[4];
		hkVector4 m_support;
		hkpCollideTriangleUtil::ClosestLineSegLineSegResult m_closestLineLineResult;
		hkVector4 m_checkTriangleDots;
		hkPadSpu<int> m_lastDimB;
		SupportState m_supportState;
};
__forceinline hkpGsk::hkpGsk()
	: m_doNotHandlePenetration( 0 )
{
}
__forceinline void hkpGsk::init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkpGskCache& cache )
{
	m_dimA = cache.m_dimA;
	m_dimB = cache.m_dimB;
	m_maxDimA = cache.m_maxDimA;
	m_maxDimB = cache.m_maxDimB;
	m_featureChange = 0;
	shapeA->convertVertexIdsToVertices( &cache.m_vertices[0], m_dimA, &m_verticesA[0] );
	shapeB->convertVertexIdsToVertices( &cache.m_vertices[m_dimA], m_dimB, &m_verticesBinB[0] );
}
__forceinline void hkpGsk::checkForChangesAndUpdateCache( hkpGskCache& cache )
{
	if ( m_featureChange )
	{
		exitAndExportCacheImpl( cache );
	}
}
__forceinline void hkpGsk::getClosestPointAinA( const hkVector4& separatingNormal, hkVector4& pointInA )
{
	if ( m_dimA == 1 )
	{
		pointInA = m_verticesA[0];
	}
	else if ( m_dimB == 1 )
	{
		pointInA = m_verticesBinA[0];
		pointInA.addMul4( separatingNormal.getSimdAt(3), separatingNormal );
	}
	else
	{
		pointInA = m_closestLineLineResult.m_closestPointA;
	}
}
extern "C"
{
	void __cdecl hkGskRecalcContactInternal( hkVector4* verticesA, hkVector4* verticesB, int dimA, int dimB, const hkVector4& masterNormal, hkVector4& pointA, hkVector4& support );
	__forceinline void __cdecl hkGskRecalcContact( hkpGsk& gsk, const hkVector4& masterNormalA, hkVector4& pointBinAOut, hkVector4& supportOut )
	{
		hkGskRecalcContactInternal( &gsk.m_verticesA[0], &gsk.m_verticesBinA[0], gsk.m_dimA, gsk.m_dimB, masterNormalA, pointBinAOut, supportOut );
	}
}
namespace hkVector4Util
{
	__forceinline void __cdecl transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
	__forceinline void __cdecl rotateInversePoints( const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
	__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::rotateInversePoints( const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	hkRotation unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setRotatedInverseDir( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
inline void __cdecl hkVector4Util::transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap16(T& x, T& y)
	{
		__declspec(align(16)) T t = x;
		x = y;
		y = t;
	}
}
class hkStepInfo
{
	public:
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
namespace hkSweptTransformUtil
{
		void __cdecl lerp2Ha( const hkSweptTransform& sweptTrans, hkTime t, hkReal tAddOn, hkTransform& transformOut );
		__forceinline void __cdecl calcAngularTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4* deltaAngleOut0, hkVector4* deltaAngleOut1 );
}
void __cdecl hkSweptTransformUtil::calcAngularTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4* __restrict deltaAngleOut0, hkVector4* __restrict deltaAngleOut1)
{
	const hkSweptTransform& st0 = ms0.getSweptTransform();
	const hkSweptTransform& st1 = ms1.getSweptTransform();
	hkReal f0 = deltaTime * st0.getInvDeltaTime();
	hkReal f1 = deltaTime * st1.getInvDeltaTime();
	hkVector4 ang0; ang0.setMul4( f0, ms0.m_deltaAngle );
	hkVector4 ang1; ang1.setMul4( f1, ms1.m_deltaAngle );
	deltaAngleOut0[0] = ang0;
	deltaAngleOut1[0] = ang1;
}
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
	enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpProcessCollisionData
{
	public:
		inline hkBool hasToi() const;
	public:
		hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
		hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
		hkpProcessCdPoint m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
			public:
				hkContactPoint m_contactPoint;
				hkPadSpu<hkReal> m_time;
				hkPadSpu<hkReal> m_seperatingVelocity;
				hkGskCache16 m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
};
inline hkBool hkpProcessCollisionData::hasToi() const
{
	return m_toi.m_time != 3.40282e+38f;
}
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
	public:
		struct ContactRef
		{
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry* m_agentEntry;
			void* m_agentData;
		};
		struct PotentialInfo
		{
			ContactRef* m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint* m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*> m_potentialContacts;
};
struct hkp4dGskVertexCollidePointsInput
{
	hkPadSpu<const hkMotionState*> m_motionA;
	hkPadSpu<const hkMotionState*> m_motionB;
	hkPadSpu<hkVector4*> m_verticesA;
	hkPadSpu<int> m_numVertices;
	hkPadSpu<int> m_allocatedNumVertices;
	hkPadSpu<hkReal> m_radiusSum;
	hkPadSpu<hkReal> m_maxAccel;
	hkPadSpu<hkReal> m_invMaxAccel;
	hkVector4 m_planeB;
	hkVector4 m_pointOnPlaneB;
	hkPadSpu<const hkStepInfo*> m_stepInfo;
	hkPadSpu<hkReal> m_worstCaseApproachingDelta;
	hkVector4 m_linearTimInfo;
	hkVector4 m_deltaAngles[2];
	hkPadSpu<hkReal> m_startRt;
};
struct hkp4dGskTolerances
{
	hkPadSpu<hkReal> m_toiSeparation;
	hkPadSpu<hkReal> m_minSeparation;
	hkPadSpu<hkReal> m_minSafeDeltaRt;
	hkPadSpu<hkReal> m_minToiDeltaTime;
	hkPadSpu<hkReal> m_toiAccuracy;
};
struct hkp4dGskVertexCollidePointsOutput
{
	hkp4dGskVertexCollidePointsOutput() { m_Rtoi = 1.0f; }
	hkPadSpu<hkReal> m_Rtoi;
	hkVector4 m_collidingPoint;
};
struct hk4dGskCollideMatrices
{
	hkTransform m_wTa;
	hkTransform m_wTb;
	hkTransform m_aTb;
	hkVector4 m_plane;
	hkVector4 m_pointOnPlane;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel[2];
	hkVector4 m_massCenterAinA;
	hkVector4 m_massCenterBinA;
};
void __cdecl hk4dGskCollideInitMatrices( const hkp4dGskVertexCollidePointsInput& input, hkReal Rt, hk4dGskCollideMatrices& out )
{
	const hkStepInfo* stepInfo = input.m_stepInfo;
	hkReal timeAddon = Rt * stepInfo->m_deltaTime;
	hkSweptTransformUtil::lerp2Ha( input.m_motionA->getSweptTransform(), stepInfo->m_startTime, timeAddon, out.m_wTa );
	hkSweptTransformUtil::lerp2Ha( input.m_motionB->getSweptTransform(), stepInfo->m_startTime, timeAddon, out.m_wTb );
	out.m_aTb.setMulInverseMul( out.m_wTa, out.m_wTb );
	out.m_plane.setRotatedDir( out.m_aTb.getRotation(), input.m_planeB );
	out.m_pointOnPlane.setTransformedPos( out.m_aTb, input.m_pointOnPlaneB );
	out.m_plane(3) = -input.m_radiusSum;
	out.m_massCenterAinA = input.m_motionA->getSweptTransform().m_centerOfMassLocal;
	hkVector4Util::rotateInversePoints( out.m_wTa.getRotation(), input.m_deltaAngles, 2, out.m_angularVel );
	out.m_massCenterBinA.setTransformedPos( out.m_aTb, input.m_motionB->getSweptTransform().m_centerOfMassLocal );
	out.m_linearVel.setRotatedInverseDir( out.m_wTa.getRotation(), input.m_linearTimInfo );
}
hkReal __cdecl hk4dGskCollidePointWithPlaneFinal( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, const hkVector4& vertexA, hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1, hkReal velocity, hkp4dGskVertexCollidePointsOutput& out )
{
	hk4dGskCollideMatrices mat;
	hkReal Rt = startRt;
	hkReal distance = distance0;
	const hkReal accuracy = tol.m_toiAccuracy * 0.25;
	for ( int iteration = 0; iteration < 10; iteration++ )
	{
		if ( distance0 <= tol.m_toiSeparation )
		{
			break;
		}
		hkReal delta = distance1 - distance0;
		if ( delta > -accuracy )
		{
			break;
		}
		hkReal rel = ( tol.m_toiSeparation - distance0 ) / delta;
		if ( !( iteration & 1 ) )
		{
			rel = hkMath::max2( rel, 0.1f );
			rel = hkMath::min2( rel, 0.9f );
		}
		Rt = ( 1.0f - rel ) * startRt + endRt * rel;
		hk4dGskCollideInitMatrices( input, Rt, mat );
		hkVector4 r; r.setSub4( vertexA, mat.m_pointOnPlane );
		distance = mat.m_plane.dot4xyz1( r );
		if ( hkMath::equal( distance, tol.m_toiSeparation, accuracy ) )
		{
			break;
		}
		if ( distance < tol.m_toiSeparation )
		{
			endRt = Rt;
			distance1 = distance;
		}
		else
		{
			startRt = Rt;
			distance0 = distance;
		}
	}
	if ( Rt < out.m_Rtoi )
	{
		out.m_Rtoi = Rt;
		out.m_collidingPoint = vertexA;
	}
	return out.m_Rtoi;
}
extern "C" void __cdecl hk4dGskCollidePointsWithPlane( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, hkp4dGskVertexCollidePointsOutput& out )
{
	hkReal endRt = 1.0f;
	hkReal Rt = input.m_startRt;
	hkReal lastT = Rt;
	int numVerticesA = input.m_numVertices;
	while ( numVerticesA )
	{
		hk4dGskCollideMatrices mat;
		hk4dGskCollideInitMatrices( input, Rt, mat );
		hkVector4* s = input.m_verticesA;
		hkVector4* d = s;
		hkReal timeRemaining = endRt - Rt;
		hkReal worstCaseDelta = timeRemaining * input.m_worstCaseApproachingDelta;
		hkReal nextT = endRt;
		int i = numVerticesA;
		numVerticesA = 0;
		for ( i--; i >= 0; s++, i-- )
		{
			hkReal distance;
			{
				hkVector4 r; r.setSub4( *s, mat.m_pointOnPlane );
				distance = mat.m_plane.dot4xyz1( r );
			}
			if ( distance > worstCaseDelta + tol.m_toiSeparation )
			{
				continue;
			}
			hkReal velocity;
			{
				hkVector4 mrA; mrA.setSub4( *s, mat.m_massCenterAinA );
				hkVector4 mrB; mrB.setSub4( *s, mat.m_massCenterBinA );
				hkVector4 armA; armA.setCross( mat.m_angularVel[0], mrA );
				hkVector4 armB; armB.setCross( mat.m_angularVel[1], mrB );
				hkVector4 vel4; vel4.setSub4( armA, mat.m_linearVel );
				vel4.sub4( armB );
				velocity = mat.m_plane.dot3( vel4 );
			}
			const hkReal hitDistance = distance - tol.m_toiSeparation;
			const hkReal hitDistanceAtT1UsingLinearProjection = hitDistance + velocity * timeRemaining;
			const hkReal maxSecondOrderError = timeRemaining * 0.5f * timeRemaining * input.m_maxAccel;
			if ( hitDistanceAtT1UsingLinearProjection > maxSecondOrderError )
			{
				continue;
			}
			if ( distance < tol.m_toiSeparation )
			{
				if ( Rt == input.m_startRt )
				{
					out.m_Rtoi = Rt;
					out.m_collidingPoint = *s;
					endRt = Rt;
				}
				else
				{
					hkReal oldDistance = (*s)(3);
					endRt = hk4dGskCollidePointWithPlaneFinal( input, tol, *s, lastT, Rt, oldDistance, distance, velocity, out );
				}
				continue;
			}
			hkAlgorithm::swap16( *s, *d );
			(*d)(3) = distance;
			d++;
			numVerticesA++;
			hkReal timeStep;
			{
				hkReal d0 = distance - tol.m_minSeparation;
				hkReal d1 = tol.m_toiSeparation - tol.m_minSeparation;
				hkReal t0sq = d0 * 2.0f * input.m_invMaxAccel;
				if ( t0sq > timeRemaining * timeRemaining )
				{
					continue;
				}
				hkReal t1sq = d1 * 2.0f * input.m_invMaxAccel;
				hkReal t0 = hkMath::sqrt( t0sq );
				if ( velocity >= 0.0f )
				{
					t0 += 2.0f * ( velocity * input.m_invMaxAccel );
				}
				else
				{
					hkReal t0x = -velocity * input.m_invMaxAccel;
					t0 = hkMath::max2( t0x, t0 );
				}
				if ( t0 > timeRemaining )
				{
					continue;
				}
				hkReal t1 = hkMath::sqrt( t1sq );
				timeStep = t0 + t1;
				timeStep = hkMath::max2( timeStep, tol.m_minSafeDeltaRt.val() );
			}
			nextT = hkMath::min2( nextT, timeStep + Rt );
		}
		if ( endRt < Rt )
		{
			break;
		}
		if ( Rt == nextT && endRt <= Rt )
		{
			break;
		}
		lastT = Rt;
		Rt = nextT;
		nextT = endRt;
	}
}
static hkReal hk4dGskCalcPointVelocityAssumingAngularVelError( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingPoint, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t )
{
	const hkReal angularVelocityFactor = 1.2f;
	hkVector4 relVel; relVel.setNeg4( linearTimInfo );
	hkReal separatingVelocity = relVel.dot3( separatingNormal );
	{
		const hkReal relT = msA->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msA->getSweptTransform().m_centerOfMass0, msA->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[0], relPos );
		const hkReal angVelPart = arm.dot3( separatingNormal );
		if ( angVelPart <= 0.0f )
		{
			separatingVelocity += angVelPart * angularVelocityFactor;
		}
		else
		{
			separatingVelocity += angVelPart / angularVelocityFactor;
		}
	}
	{
		const hkReal relT = msB->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msB->getSweptTransform().m_centerOfMass0, msB->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[1], relPos );
		const hkReal angVelPart = arm.dot3( separatingNormal );
		if ( angVelPart >= 0.0f )
		{
			separatingVelocity -= angVelPart * angularVelocityFactor;
		}
		else
		{
			separatingVelocity -= angVelPart / angularVelocityFactor;
		}
	}
	return separatingVelocity;
}
static __forceinline void hk4dGskCalcSeparatingNormal( const hkTransform& tA, const hkTransform& tB, const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, hkpGsk& gsk, hkVector4& separatingNormalOut, hkVector4& pointOnBInB )
{
	hkTransform aTb; aTb.setMulInverseMul( tA, tB );
	hkVector4 separatingNormalA;
	gsk.getClosestFeature( shapeA, shapeB, aTb, separatingNormalA );
	separatingNormalOut._setRotatedDir( tA.getRotation(), separatingNormalA );
	hkVector4 pointInA;
	gsk.getClosestPointAinA( separatingNormalA, pointInA );
	pointInA.subMul4( separatingNormalA.getSimdAt(3), separatingNormalA );
	pointOnBInB._setTransformedInversePos( aTb, pointInA );
	separatingNormalOut(3) = separatingNormalA(3) - shapeA->getRadius() - shapeB->getRadius();
}
static __forceinline void hk4dGskCalcWorstCaseProjectedVelocity( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkReal& realProjectedLinearDelta, hkReal& projectedAngularDelta )
{
	hkVector4 crossAngleA; crossAngleA.setCross( deltaAngles[0], separatingNormal );
	hkVector4 crossAngleB; crossAngleB.setCross( deltaAngles[1], separatingNormal );
	hkReal lenA = crossAngleA.length3() * msA->m_objectRadius;
	hkReal lenB = crossAngleB.length3() * msB->m_objectRadius;
	projectedAngularDelta = lenA + lenB;
	realProjectedLinearDelta = linearTimInfo.dot3( separatingNormal );
}
static __forceinline void hk4dGskCollPInputInitialize( const hkpAgent3ProcessInput& in3, hkp4dGskVertexCollidePointsInput& input )
{
	const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
	const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
	const hkMotionState* msA = in3.m_bodyA->getMotionState();
	const hkMotionState* msB = in3.m_bodyB->getMotionState();
	input.m_motionA = msA;
	input.m_motionB = msB;
	input.m_radiusSum = shapeA->getRadius() + shapeB->getRadius();
	input.m_linearTimInfo = in3.m_linearTimInfo;
	input.m_stepInfo = &in3.m_input->m_stepInfo;
	int numVertices = shapeA->getNumCollisionSpheres();
	input.m_allocatedNumVertices = numVertices;
	input.m_numVertices = numVertices;
	input.m_verticesA = hkAllocateStack<hkVector4>( numVertices );
	shapeA->getCollisionSpheres( reinterpret_cast<hkSphere*>( input.m_verticesA.val() ) );
	const hkReal a = msA->m_objectRadius * input.m_deltaAngles[0](3) * input.m_deltaAngles[0](3);
	const hkReal b = msB->m_objectRadius * input.m_deltaAngles[1](3) * input.m_deltaAngles[1](3);
	input.m_maxAccel = a + b;
	input.m_invMaxAccel = 1.0f / ( input.m_maxAccel + 1.192092896e-07F );
}
static __forceinline hkReal hk4dGskCalcPointVelocity( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingPoint, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t )
{
	hkVector4 relVel; relVel.setNeg4( linearTimInfo );
	{
		const hkReal relT = msA->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msA->getSweptTransform().m_centerOfMass0, msA->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[0], relPos );
		relVel.add4( arm );
	}
	{
		const hkReal relT = msB->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msB->getSweptTransform().m_centerOfMass0, msB->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[1], relPos );
		relVel.sub4( arm );
	}
	const hkReal separatingVelocity = relVel.dot3( separatingNormal );
	return separatingVelocity;
}
static __forceinline void hk4dGskCalcToiFinal( const hkpAgent3ProcessInput& in3, hkp4dGskTolerances& tol, hkpGsk& gsk, int featureChange, const hkVector4& oldMasterNormal, const hkVector4* deltaAngles, hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1, hkpProcessCollisionOutput& out )
{
	hkReal Rt = startRt;
	hkReal distance = distance0;
	hkTransform wTa;
	hkTransform wTb;
	hkTransform aTb;
	hkVector4 normalA;
	hkVector4 pointA;
	hkReal radiusSum;
	{
		const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
		const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
		radiusSum = shapeA->getRadius() + shapeB->getRadius();
	}
	hkReal velocityBasedOnDistance = ( distance1 - distance0 ) / ( endRt - startRt );
	for ( int iteration = 0; iteration < 10; iteration++ )
	{
		hkReal delta = distance1 - distance0;
		if ( delta > -tol.m_toiAccuracy )
		{
			endRt = startRt;
			delta = 0.5f;
		}
		hkBool earlyOut;
		if ( hkMath::equal( distance1, tol.m_toiSeparation, tol.m_toiAccuracy ) )
		{
			earlyOut = true;
			featureChange = 0;
			Rt = endRt;
		}
		else
		{
			earlyOut = false;
			hkReal rel = ( tol.m_toiSeparation - distance0 ) / delta;
			rel = hkMath::max2( rel, 0.1f );
			rel = hkMath::min2( rel, 0.9f );
			Rt = ( 1.0f - rel ) * startRt + endRt * rel;
		}
		const hkStepInfo& stepInfo = in3.m_input->m_stepInfo;
		hkReal timeAddon = Rt * stepInfo.m_deltaTime;
		hkSweptTransformUtil::lerp2Ha( in3.m_bodyA->getMotionState()->getSweptTransform(), stepInfo.m_startTime, timeAddon, wTa );
		hkSweptTransformUtil::lerp2Ha( in3.m_bodyB->getMotionState()->getSweptTransform(), stepInfo.m_startTime, timeAddon, wTb );
		aTb.setMulInverseMul( wTa, wTb );
		if ( featureChange )
		{
			const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
			const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
			gsk.getClosestFeature( shapeA, shapeB, aTb, normalA );
			gsk.getClosestPointAinA( normalA, pointA );
		}
		else
		{
			hkVector4Util::transformPoints( aTb, &gsk.m_verticesBinB[0], gsk.m_dimB, &gsk.m_verticesBinA[0] );
			hkVector4 oldMasterNormalInA; oldMasterNormalInA._setRotatedInverseDir( wTa.getRotation(), oldMasterNormal );
			hkGskRecalcContact( gsk, oldMasterNormalInA, pointA, normalA );
		}
		distance = normalA(3) - radiusSum;
		if ( hkMath::equal( distance, tol.m_toiSeparation, tol.m_toiAccuracy ) || earlyOut )
		{
			break;
		}
		if ( startRt == endRt )
		{
			break;
		}
		if ( distance < tol.m_toiSeparation )
		{
			endRt = Rt;
			distance1 = distance;
		}
		else
		{
			startRt = Rt;
			distance0 = distance;
		}
	}
	const hkStepInfo& stepInfo = in3.m_input->m_stepInfo;
	hkReal deltaTime = hkMath::max2( stepInfo.m_deltaTime.val() * Rt, tol.m_minToiDeltaTime.val() );
	hkTime toi = stepInfo.m_startTime + deltaTime;
	if ( toi < out.m_toi.m_time && toi < stepInfo.m_endTime - tol.m_minToiDeltaTime )
	{
		hkGskCache16 cache;
		hkReal separatingVelocity;
		const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
		hkContactPoint cp;
		{
			hkVector4 pointWs; pointWs.setTransformedPos( wTa, pointA );
			cp.getSeparatingNormal().setRotatedDir( wTa.getRotation(), normalA );
			cp.getPosition().setAddMul4( pointWs, cp.getSeparatingNormal(), -shapeA->getRadius() - distance );
			cp.setDistance( distance );
			hkpConvexShape::WeldResult weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
			hkVector4 weldedNormal = cp.getSeparatingNormal();
			if ( in3.m_bodyB->getShape()->getType() == HK_SHAPE_TRIANGLE )
			{
				{
					hkpVertexId featurePoints[3];
					hkUint8 numFeaturePoints = hkUint8( gsk.m_dimB );
					featurePoints[0] = hkpVertexId( gsk.m_verticesBinB[0].getId() );
					featurePoints[1] = numFeaturePoints < 2 ? 0xffff : hkpVertexId( gsk.m_verticesBinB[1].getId() );
					featurePoints[2] = numFeaturePoints < 3 ? 0xffff : hkpVertexId( gsk.m_verticesBinB[2].getId() );
					const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
					weldResult = shapeB->weldContactPoint( featurePoints, numFeaturePoints, cp.getPosition(), &wTb, shapeA, &wTa, weldedNormal );
				}
				cp.setSeparatingNormal( weldedNormal );
			}
			else if ( in3.m_bodyA->getShape()->getType() == HK_SHAPE_TRIANGLE )
			{
				hkpVertexId featurePoints[3];
				hkUint8 numFeaturePoints = hkUint8( gsk.m_dimA );
				featurePoints[0] = hkpVertexId( gsk.m_verticesA[0].getId() );
				featurePoints[1] = numFeaturePoints < 2 ? 0xffff : hkpVertexId( gsk.m_verticesA[1].getId() );
				featurePoints[2] = numFeaturePoints < 3 ? 0xffff : hkpVertexId( gsk.m_verticesA[2].getId() );
				hkVector4 dist; dist.setBroadcast( weldedNormal, 3 );
				hkVector4 pointOnA; pointOnA.setAddMul4( cp.getPosition(), weldedNormal, dist );
				weldedNormal.setNeg3( weldedNormal );
				const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
				weldResult = shapeA->weldContactPoint( featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb, weldedNormal );
				weldedNormal.setNeg3( weldedNormal );
				cp.setSeparatingNormal( weldedNormal );
			}
if ( weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT && in3.m_input->m_collisionQualityInfo->m_enableToiWeldRejection )
{
return;
}
const hkMotionState* msA = in3.m_bodyA->getMotionState();
const hkMotionState* msB = in3.m_bodyB->getMotionState();
separatingVelocity = hk4dGskCalcPointVelocity( msA, msB, cp.getPosition(), cp.getNormal(), in3.m_linearTimInfo, deltaAngles, toi );
			if ( weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED && separatingVelocity > -1.192092896e-07F )
			{
				hkp4dGskVertexCollidePointsInput collPInput;
				collPInput.m_startRt = Rt;
				{
					hkSweptTransformUtil::calcAngularTimInfo( *msA, *msB, in3.m_input->m_stepInfo.m_deltaTime, &collPInput.m_deltaAngles[0], &collPInput.m_deltaAngles[1] );
					hkReal realProjectedLinearDelta, projectedAngularDelta;
					hk4dGskCalcWorstCaseProjectedVelocity( msA, msB, cp.getNormal(), in3.m_linearTimInfo, collPInput.m_deltaAngles, realProjectedLinearDelta, projectedAngularDelta );
					collPInput.m_worstCaseApproachingDelta = realProjectedLinearDelta + projectedAngularDelta;
				}
				hk4dGskCollPInputInitialize( in3, collPInput );
				collPInput.m_planeB.setRotatedInverseDir( wTb.getRotation(), cp.getNormal() );
				collPInput.m_pointOnPlaneB = gsk.m_verticesBinB[0];
				if ( collPInput.m_verticesA.val() )
				{
					hkp4dGskVertexCollidePointsOutput collidePointsOut;
					hk4dGskCollidePointsWithPlane( collPInput, tol, collidePointsOut );
					hkDeallocateStack( collPInput.m_verticesA.val() );
					if ( collidePointsOut.m_Rtoi < 1.0f )
					{
						hkVector4 newPos; newPos.setTransformedPos( wTa, collidePointsOut.m_collidingPoint );
						cp.getPosition() = newPos;
					}
				}
			}
			if ( velocityBasedOnDistance < separatingVelocity )
			{
				if ( separatingVelocity * 1.2f < velocityBasedOnDistance )
				{
					separatingVelocity = velocityBasedOnDistance;
				}
				else
				{
					separatingVelocity = hk4dGskCalcPointVelocityAssumingAngularVelError( in3.m_bodyA->getMotionState(), in3.m_bodyB->getMotionState(), cp.getPosition(), cp.getNormal(), in3.m_linearTimInfo, deltaAngles, toi );
					separatingVelocity = hkMath::min2( 0.0f, separatingVelocity );
				}
			}
			separatingVelocity *= stepInfo.m_invDeltaTime;
		}
		hkContactPointPropertiesWithExtendedUserData16 properties;
		properties.setUserData( 0 );
		properties.m_internalDataA = 321.0f;
		properties.m_internalSolverData = 0.0f;
		properties.m_impulseApplied = 0.0f;
		gsk.exitAndExportCacheImpl( cache );
		hkpContactMgr::ToiAccept cbResult = in3.m_contactMgr->addToi( *in3.m_bodyA.val(), *in3.m_bodyB.val(), *in3.m_input.val(), out, toi, cp, &cache, separatingVelocity, properties );
		if ( cbResult == hkpContactMgr::TOI_ACCEPT )
		{
			if ( out.hasToi() )
			{
				in3.m_contactMgr->removeToi( *out.m_constraintOwner.val(), out.m_toi.m_properties );
			}
			out.m_toi.m_seperatingVelocity = separatingVelocity;
			out.m_toi.m_contactPoint = cp;
			out.m_toi.m_time = toi;
			out.m_toi.m_properties.set( properties );
			out.m_toi.m_gskCache.set( cache );
		}
	}
}
// pdb: hk4dGskCollideCalcToi | hkpContinuousGsk.obj | fnv360_0822_debug, objrun_prop, low, conflict (bridge: hkGskManifold_verifyAndGetPoints)
// pdb params: in3, allowedPenetrationDepth, minSeparation, toiSeparation, gskCache, separatingNormal, out
void __cdecl FUN_00a433d0( const hkpAgent3ProcessInput& in3, const hkReal allowedPenetrationDepth, const hkReal minSeparation, const hkReal toiSeparation, hkpGskCache& gskCache, hkVector4& separatingNormal, hkpProcessCollisionOutput& out )
{
	hkp4dGskTolerances tol;
	{
		hkpCollisionQualityInfo* qi = in3.m_input->m_collisionQualityInfo.val();
		tol.m_minSeparation = minSeparation;
		tol.m_toiSeparation = toiSeparation;
		tol.m_toiAccuracy = qi->m_toiAccuracy * allowedPenetrationDepth;
		tol.m_minSafeDeltaRt = hkMath::max2( qi->m_minSafeDeltaTime * allowedPenetrationDepth, qi->m_minAbsoluteSafeDeltaTime ) * in3.m_input->m_stepInfo.m_invDeltaTime;
		tol.m_minToiDeltaTime = qi->m_minToiDeltaTime;
	}
	const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
	const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
	const hkMotionState* msA = in3.m_bodyA->getMotionState();
	const hkMotionState* msB = in3.m_bodyB->getMotionState();
	hkp4dGskVertexCollidePointsInput collPInput;
	collPInput.m_verticesA = 0;
	hkBool collPInputNormalInitialized = false;
	hkBool collPIgnore = false;
	hkSweptTransformUtil::calcAngularTimInfo( *msA, *msB, in3.m_input->m_stepInfo.m_deltaTime, &collPInput.m_deltaAngles[0], &collPInput.m_deltaAngles[1] );
	{
		int numIter = 0;
		hkpGsk gsk;
		gsk.init( shapeA, shapeB, gskCache );
		hkVector4 lastMasterNormal; lastMasterNormal.setZero4();
		hkReal lastDistance = separatingNormal(3);
		int featureChange = 1;
		hkReal Rt = 0.0f;
		hkReal endRt = 1.0f;
		hkReal lastRt = 0.0f;
		while ( 1 )
		{
			const hkReal currentDistance = separatingNormal(3);
			if ( currentDistance <= tol.m_toiSeparation + tol.m_toiAccuracy )
			{
				hk4dGskCalcToiFinal( in3, tol, gsk, featureChange, lastMasterNormal, collPInput.m_deltaAngles, lastRt, Rt, lastDistance, currentDistance, out );
				goto END;
			}
			const hkReal restRt = endRt - Rt;
			if ( restRt <= 0.0f )
			{
				goto END;
			}
			hkReal realProjectedLinearDelta, projectedAngularDelta;
			hk4dGskCalcWorstCaseProjectedVelocity( msA, msB, separatingNormal, in3.m_linearTimInfo, collPInput.m_deltaAngles, realProjectedLinearDelta, projectedAngularDelta );
			const hkReal worstCaseApproachingDelta = realProjectedLinearDelta + projectedAngularDelta;
			const hkReal distAtT1 = separatingNormal(3) - worstCaseApproachingDelta * restRt;
			if ( worstCaseApproachingDelta <= 0.0f || distAtT1 > tol.m_minSeparation )
			{
				goto END;
			}
			const hkReal maxAllowedTravelDistance = separatingNormal(3) - tol.m_minSeparation;
			hkReal safeTimeStep = maxAllowedTravelDistance / worstCaseApproachingDelta;
			if ( safeTimeStep < 0.2f && !collPIgnore && collPInputNormalInitialized && realProjectedLinearDelta * 1.0 < projectedAngularDelta )
			{
				if ( !collPInput.m_verticesA )
				{
					hk4dGskCollPInputInitialize( in3, collPInput );
					if ( !collPInput.m_verticesA.val() )
					{
						collPIgnore = true;
						goto skipPointPlaneOptimization;
					}
				}
				collPInput.m_startRt = Rt;
				collPInput.m_worstCaseApproachingDelta = worstCaseApproachingDelta;
				hkp4dGskVertexCollidePointsOutput collidePointsOut;
				hk4dGskCollidePointsWithPlane( collPInput, tol, collidePointsOut );
				const hkReal newSafeTimeStep = collidePointsOut.m_Rtoi - Rt;
				if ( newSafeTimeStep < safeTimeStep * 2.0 )
				{
					collPIgnore = true;
				}
				safeTimeStep = hkMath::max2( safeTimeStep, newSafeTimeStep );
			}
skipPointPlaneOptimization:
			if ( Rt + safeTimeStep >= endRt )
			{
				goto END;
			}
			lastRt = Rt;
			safeTimeStep = hkMath::max2( tol.m_minSafeDeltaRt.val(), safeTimeStep );
			Rt += safeTimeStep;
			Rt = hkMath::min2( Rt, endRt );
			lastMasterNormal = separatingNormal;
			lastDistance = separatingNormal(3);
			{
				const hkStepInfo& stepInfo = in3.m_input->m_stepInfo;
				const hkReal timeAddon = Rt * stepInfo.m_deltaTime;
				hkTransform tA; hkSweptTransformUtil::lerp2Ha( msA->getSweptTransform(), stepInfo.m_startTime, timeAddon, tA );
				hkTransform tB; hkSweptTransformUtil::lerp2Ha( msB->getSweptTransform(), stepInfo.m_startTime, timeAddon, tB );
				numIter++;
				hk4dGskCalcSeparatingNormal( tA, tB, shapeA, shapeB, gsk, separatingNormal, collPInput.m_pointOnPlaneB );
				featureChange = gsk.m_featureChange;
				collPInputNormalInitialized = true;
				collPInput.m_planeB._setRotatedInverseDir( tB.getRotation(), separatingNormal );
			}
		}
END:
		if ( collPInput.m_verticesA )
		{
			hkDeallocateStack( collPInput.m_verticesA.val() );
		}
		gsk.checkForChangesAndUpdateCache( gskCache );
	}
}
}
}   // namespace f3m_00a433d0

// @f3 0x00a42220 (community match, verified in this file)
namespace f3m_00a42220 {

// FUN_00a42220 = Havok 5.5.0 hk4dGskCalcToiFinal (hkpInternal.lib, hkpContinuousGsk.obj) as the game links it: the
// game's build also welds the TOI contact against a triangle on body A (an else-if after the body-B weld), which the
// SDK's library object does not have. From the 0x00a433d0 SDK-form source (work\a433d0\w2\sdk_source.cpp, a library
// MATCH for this function and every helper), cut with hktrim.py; the body-A branch follows the New Vegas twin. See note.txt.
namespace f3m_00a42220 {
typedef float hkReal;
typedef signed char hkInt8;
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
enum HK_MEMORY_CLASS { HK_MEMORY_CLASS_ROOT };
class hkMemory;
class hkThreadMemory
{
	public:
		__forceinline void* allocateStack(int nbytes);
		__forceinline void deallocateStack(void* p);
		virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
		virtual void alignedDeallocate(void* ptr);
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
			PAGE_ALIGN = 64,
			MEMORY_MAX_SMALL_ROW = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK = 512,
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
		__forceinline virtual ~hkBaseObject() {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
	public:
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
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline hkBool __cdecl equal(hkReal x, hkReal y, hkReal tolerance2=1e-5f)
	{
		return hkMath::fabs(x-y) < tolerance2;
	}
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
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline int getInt24W( ) const ;
		__forceinline void add4(const hkVector4& a);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline void setNeg4(const hkVector4& v);
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		void setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
		__forceinline void setBroadcast(hkVector4Parameter v, int i);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};
class hkQuaternion
{
	public:
	public:
		hkVector4 m_vec;
};
class hkMatrix3
{
	public:
		__forceinline hkMatrix3() {}
		__forceinline hkMatrix3( const hkMatrix3& other );
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkMatrix3::hkMatrix3( const hkMatrix3& other )
{
	m_col0 = other.m_col0;
	m_col1 = other.m_col1;
	m_col2 = other.m_col2;
}
class __declspec(align(16)) hkRotation : public hkMatrix3
{
	public:
};
class hkTransform
{
	public:
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkTransform& r);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline hkRotation& getRotation();
		__forceinline const hkRotation& getRotation() const;
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};
class hkSweptTransform
{
	public:
	public:
		__forceinline hkReal getInterpolationValue( hkTime t ) const;
		__forceinline hkTime getBaseTime() const;
		__forceinline hkReal getInvDeltaTime() const;
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
	return (&x)[i];
}
inline void hkVector4::operator= (const hkVector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
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
inline int hkVector4::getInt24W( ) const
{
	return (reinterpret_cast<const int*>(this))[3] & ~0x3f000000;
}
inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
	x = a.x + r * b.x;
	y = a.y + r * b.y;
	z = a.z + r * b.z;
	w = a.w + r * b.w;
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& m0, const hkVector4& m1)
{
	x = a.x + m0.x * m1.x;
	y = a.y + m0.y * m1.y;
	z = a.z + m0.z * m1.z;
	w = a.w + m0.w * m1.w;
}
	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = v.w;
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
	inline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
	{
		_setMul3(r,v);
	}
	inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& v)
	{
		hkReal v0 = v(0);
		hkReal v1 = v(1);
		hkReal v2 = v(2);
		hkVector4& t = *this;
		t(0) = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
		t(1) = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
		t(2) = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
		t(3) = 0;
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
	inline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& v)
	{
		hkReal v0 = v(0) - t(0,3);
		hkReal v1 = v(1) - t(1,3);
		hkReal v2 = v(2) - t(2,3);
		hkVector4& d = *this;
		d(0) = t(0,0)*v0 + t(1,0)*v1 + t(2,0)*v2;
		d(1) = t(0,1)*v0 + t(1,1)*v1 + t(2,1)*v2;
		d(2) = t(0,2)*v0 + t(1,2)*v1 + t(2,2)*v2;
		d(3) = 0.0f;
	}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w );
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
inline hkVector4& hkMatrix3::getColumn(int x)
{
	return (&m_col0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
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
hkTime hkSweptTransform::getBaseTime() const
{
	return hkTime(m_centerOfMass0(3));
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
hkReal hkSweptTransform::getInterpolationValue( hkTime t ) const
{
	hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
	return dt;
}
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
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base )
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
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkAabb
{
	public:
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};
class hkSphere
{
	public:
	protected:
		hkVector4 m_pos;
};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		inline hkVector4& getPosition();
		inline const hkVector4& getNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
		inline void setDistance( hkReal d );
	protected:
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline const hkVector4& hkContactPoint::getNormal() const
{
	return m_separatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setSeparatingNormal( const hkVector4& separatingNormal )
{
	m_separatingNormal = separatingNormal;
}
inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}
class hkpCdVertex: public hkVector4
{
	public:
		int getId() const { return getInt24W(); }
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
enum { HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
typedef __declspec(align(16)) char ShapeBuffer[HK_SHAPE_BUFFER_SIZE];
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
	public:
		__forceinline hkpShapeType getType() const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
		virtual const hkpShapeContainer* getContainer() const { return 0; }
		struct CalcSizeForSpuInput
		{
			bool m_midphaseAgent3Registered;
			bool m_isFixedOrKeyframed;
		};
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
	protected:
		virtual void getAabbImpl( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
			typedef void (__cdecl *GetSupportingVertexFunc) (const void* thisObj, hkVector4Parameter direction, hkpCdVertex &supportVertex );
			typedef void (__cdecl *ConvertVertexIdsToVerticesFunc)	(const void* thisObj, const hkpVertexId* ids, int numIds, class hkpCdVertex* verticesOut );
			typedef int (__cdecl *WeldContactPointFunc)	(const void* thisObj, hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut );
			typedef void (__cdecl *GetCentreFunc)	(const void* thisObj, hkVector4& centreOut );
			typedef int (__cdecl *GetNumCollisionSpheresFunc) (const void* thisObj );
			typedef const hkSphere* (__cdecl *GetCollisionSpheresFunc)(const void* thisObj, hkSphere* sphereBuffer );
			typedef void (__cdecl *GetAabbFunc) (const void* thisObj, const hkTransform& localToWorld, hkReal tolerance, hkAabb& out );
			typedef hkBool (__cdecl *CastRayFunc) (const void* thisObj, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
			typedef const hkpShape* (__cdecl *GetChildShapeFunc) (const void* thisObj, hkpShapeKey key, ShapeBuffer& buffer );
			typedef hkUint32 (__cdecl *GetCollisionFilterInfoFunc) (const void* thisObj, hkpShapeKey key );
			struct ShapeFuncs
			{
				hkPadSpu<GetSupportingVertexFunc> m_getSupportingVertexFunc;
				hkPadSpu<ConvertVertexIdsToVerticesFunc>	m_convertVertexIdsToVertices;
				hkPadSpu<WeldContactPointFunc> m_weldContactPointFunc;
				hkPadSpu<GetCentreFunc> m_getCentreFunc;
				hkPadSpu<GetNumCollisionSpheresFunc> m_getNumCollisionSpheresFunc;
				hkPadSpu<GetCollisionSpheresFunc> m_getCollisionSpheresFunc;
				hkPadSpu<GetAabbFunc> m_getAabbFunc;
				hkPadSpu<CastRayFunc> m_castRay;
				hkPadSpu<GetChildShapeFunc> m_getChildShapeFunc;
				hkPadSpu<GetCollisionFilterInfoFunc> m_getCollisionFilterInfoFunc;
			};
			struct ShapeFuncs2
			{
				__declspec(align(64)) GetSupportingVertexFunc m_getSupportingVertexFunc;
				ConvertVertexIdsToVerticesFunc m_convertVertexIdsToVertices;
				WeldContactPointFunc m_weldContactPointFunc;
				GetCentreFunc m_getCentreFunc;
				GetNumCollisionSpheresFunc m_getNumCollisionSpheresFunc;
				GetCollisionSpheresFunc m_getCollisionSpheresFunc;
				GetAabbFunc m_getAabbFunc;
				CastRayFunc m_castRay;
				GetChildShapeFunc m_getChildShapeFunc;
				GetCollisionFilterInfoFunc m_getCollisionFilterInfoFunc;
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
class hkMotionState;
class hkpCdBody
{
	public:
		friend class hkpCollidable;
		__forceinline const hkpShape* getShape() const;
	public:
		__forceinline const hkMotionState* getMotionState() const;
	public:
		const hkpShape* m_shape;
		hkpShapeKey m_shapeKey;
		const void* m_motion;
		const hkpCdBody* m_parent;
};
const hkMotionState* hkpCdBody::getMotionState() const
{
	return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}
struct hkpProcessCollisionInput;
class hkpContactMgr;
struct hkpProcessCollisionOutput;
struct hkpAgentEntry
{
	hkUchar m_streamCommand;
	hkUchar m_agentType;
	hkUchar m_numContactPoints;
	hkUchar m_size;
};
struct hkpAgent3Input
{
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform m_aTb;
};
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	hkPadSpu<hkReal> m_distAtT1;
	hkPadSpu<int> m_offsetPpuSectorMinusSpuSector;
	hkVector4 m_linearTimInfo;
};
struct hkpCollisionQualityInfo
{
	__declspec(align(16)) hkReal m_keepContact;
	hkReal m_create4dContact;
	hkReal m_createContact;
	hkReal m_manifoldTimDistance;
	hkPadSpu<hkBool32> m_useContinuousPhysics;
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
struct hkpProcessCollisionData;
class hkpGskCache;
class hkpSolverResults
{
	public:
		inline hkpSolverResults();
		inline void init();
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};
inline void hkpSolverResults::init()
{
	m_impulseApplied = 0.0f;
	m_internalSolverData = 0.0f;
}
inline hkpSolverResults::hkpSolverResults()
{
	init();
}
class hkContactPointMaterial
{
	public:
		inline void setUserData( hkUlong data );
	protected:
		hkUlong m_userData;
		hkUFloat8 m_friction;
		hkUint8 m_restitution;
	public:
		hkUFloat8 m_maxImpulse;
	public:
		enum FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL = 1,
			CONTACT_USES_SOLVER_PATH2 = 2,
			CONTACT_BREAKOFF_OBJECT_ID = 4,
		};
		hkUint8 m_flags;
		friend class hkpSaveContactPointsEndianUtil;
};
inline void hkContactPointMaterial::setUserData( hkUlong data )
{
	m_userData = data;
}
class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
};
__declspec(align(16)) class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
	public:
		void set(const hkContactPointPropertiesWithExtendedUserData16& other)
		{
			*this = other;
		}
		hkpContactPointProperties::UserData m_extendedUserDatas[7];
};
class hkpContactMgr: public hkReferencedObject
{
	public:
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
		__forceinline ToiAccept addToi( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut );
		__forceinline void removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties );
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
hkpContactMgr::ToiAccept hkpContactMgr::addToi( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, hkTime toi, hkContactPoint& cp, const hkpGskCache* gskCache, hkReal& projectedVelocity, hkpContactPointProperties& propertiesOut )
{
	return addToiImpl( a, b, input, output, toi, cp, gskCache, projectedVelocity, propertiesOut );
}
void hkpContactMgr::removeToi( class hkpConstraintOwner& constraintOwner, hkpContactPointProperties& properties )
{
	removeToiImpl( constraintOwner, properties );
}
struct hkpProcessCdPoint
{
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};
class hkMotionState
{
	public:
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
class hkpSphereRepShape : public hkpShape
{
	public:
		__forceinline int getNumCollisionSpheres( ) const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl( ) const = 0;
		virtual const hkSphere* getCollisionSpheresImpl( hkSphere* sphereBuffer ) const = 0;
};
int hkpSphereRepShape::getNumCollisionSpheres( ) const
{
	return this->getNumCollisionSpheresImpl( );
}
const hkSphere* hkpSphereRepShape::getCollisionSpheres( hkSphere* sphereBuffer ) const
{
	return this->getCollisionSpheresImpl( sphereBuffer );
}
class hkpConvexShape : public hkpSphereRepShape
{
	public:
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline hkpConvexShape::WeldResult weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
																	hkVector4& contactPointWs, const hkTransform* thisObjTransform,
																	const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl( hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl( hkVector4& centreOut ) const;
	protected:
		hkReal m_radius;
};
inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}
void hkpConvexShape::convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const
{
	this->convertVertexIdsToVerticesImpl( ids, numIds, vertixArrayOut );
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(	hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
															hkVector4& contactPointWs, const hkTransform* thisObjTransform,
															const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const
{
	return (WeldResult)this->weldContactPointImpl(	featurePoints, numFeaturePoints,
													contactPointWs, thisObjTransform,
													collidingShape, collidingTransform, separatingNormalInOut );
}
class hkpCollideTriangleUtil
{
	public:
		struct ClosestLineSegLineSegResult
		{
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal> m_distanceSquared;
		};
};
class hkpGskCache
{
	public:
		hkUint16 m_vertices[4];
		hkUint8 m_dimA;
		hkUint8 m_dimB;
		enum MaxDim
		{
			MAX_DIM_MAX = 15
		};
		hkUint8 m_maxDimA : 4;
		hkUint8 m_maxDimB : 4;
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER = 0x01,
			GSK_FLAGS_SHAPE_B_IS_CYLINDER = 0x02,
			GSK_FLAGS_REPLACE_SHAPE_A_WITH_CAPSULE = 0x04,
			GSK_FLAGS_REPLACE_SHAPE_B_WITH_CAPSULE = 0x08,
			GSK_FLAGS_CYLINDER_AGENT_FLAGS = 0x0f,
			GSK_FLAGS_DISABLE_CONTACT_TIMS = 0x10,
			GSK_FLAGS_CONVEX_LIST_IN_GSK_MODE = 0x20,
			GSK_FLAGS_PROCESS_FUNCTION_CALLED = 0x40,
			ONE_BIT_STILL_UNUSED = 0x80
		};
		hkUint8 m_gskFlags;
};
__declspec(align(16)) class hkGskCache16 : public hkpGskCache
{
	public:
		void set(const hkGskCache16& other)
		{
				*this = other;
		}
};
enum hkpGskStatus
{
	HK_GSK_OK = 0,
	HK_GSK_PD_HEURISTIC_SAMPLING = 1,
	HK_GSK_PD_OUT_OF_MEMORY = 2,
	HK_GSK_PD_UNSOLVABLE = 3,
	HK_GSK_PENETRATING = 4
};
class hkpGsk
{
	public:
		enum
		{
			GSK_NONE_NONE = 0,
			GSK_POINT_POINT = 9,
			GSK_POINT_EDGE = 10,
			GSK_EDGE_POINT = 17,
			GSK_POINT_TRIANGLE = 11,
			GSK_TRIANGLE_POINT = 25,
			GSK_EDGE_TRIANGLE = 19,
			GSK_TRIANGLE_EDGE = 26,
			GSK_POINT_TETRA = 12,
			GSK_TETRA_POINT = 33,
			GSK_EDGE_EDGE = 18
		};
		enum NextCase
		{
			NEXT_IS_BREAK = 0,
			NEXT_IS_PENETRATION = 1,
			NEXT_IS_EDGE_EDGE = 2
		};
		enum SupportTypes
		{
			BUILD_NEG_SUPPORT = -8,
			BUILD_NO_SUPPORT = 0,
			BUILD_POS_SUPPORT = 8
		};
		enum SupportState
		{
			SUPPORT_CHANGED = 0,
			DONT_CALL_GET_SUPPORTING_VERTEX_A = 8,
			DONT_CALL_GET_SUPPORTING_VERTEX_B = -8
		};
		enum ReduceDimensionResult
		{
			REDUCE_DIMENSION_OK = 0,
			REDUCE_DIMENSION_PENETRATION = 1
		};
		struct GetClosesetPointInput
		{
			hkPadSpu<const hkTransform*> m_aTb;
			hkPadSpu<const hkTransform*> m_transformA;
			hkPadSpu<const hkpConvexShape*> m_shapeA;
			hkPadSpu<const hkpConvexShape*> m_shapeB;
			hkPadSpu<hkReal> m_collisionTolerance;
		};
		hkpGsk();
		void init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkpGskCache& cache );
		hkpGskStatus getClosestFeature( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb, hkVector4& separatingNormal );
		void getClosestPointAinA( const hkVector4& separatingNormal, hkVector4& pointOnAinA );
		void checkForChangesAndUpdateCache( hkpGskCache& cache );
	public:
		void exitAndExportCacheImpl( hkpGskCache& cache ) const;
	public:
		hkPadSpu<int> m_dimA;
		hkPadSpu<int> m_dimB;
		hkPadSpu<int> m_maxDimA;
		hkPadSpu<int> m_maxDimB;
		hkPadSpu<hkUint32> m_doNotHandlePenetration;
		hkPadSpu<int> m_featureChange;
		hkpCdVertex m_verticesA[4];
		hkVector4 m_dummy[4];
		hkVector4 m_verticesBinA[4];
		hkpCdVertex m_verticesBinB[4];
		hkVector4 m_support;
		hkpCollideTriangleUtil::ClosestLineSegLineSegResult m_closestLineLineResult;
		hkVector4 m_checkTriangleDots;
		hkPadSpu<int> m_lastDimB;
		SupportState m_supportState;
};
__forceinline hkpGsk::hkpGsk()
	: m_doNotHandlePenetration( 0 )
{
}
__forceinline void hkpGsk::init( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkpGskCache& cache )
{
	m_dimA = cache.m_dimA;
	m_dimB = cache.m_dimB;
	m_maxDimA = cache.m_maxDimA;
	m_maxDimB = cache.m_maxDimB;
	m_featureChange = 0;
	shapeA->convertVertexIdsToVertices( &cache.m_vertices[0], m_dimA, &m_verticesA[0] );
	shapeB->convertVertexIdsToVertices( &cache.m_vertices[m_dimA], m_dimB, &m_verticesBinB[0] );
}
__forceinline void hkpGsk::checkForChangesAndUpdateCache( hkpGskCache& cache )
{
	if ( m_featureChange )
	{
		exitAndExportCacheImpl( cache );
	}
}
__forceinline void hkpGsk::getClosestPointAinA( const hkVector4& separatingNormal, hkVector4& pointInA )
{
	if ( m_dimA == 1 )
	{
		pointInA = m_verticesA[0];
	}
	else if ( m_dimB == 1 )
	{
		pointInA = m_verticesBinA[0];
		pointInA.addMul4( separatingNormal.getSimdAt(3), separatingNormal );
	}
	else
	{
		pointInA = m_closestLineLineResult.m_closestPointA;
	}
}
extern "C"
{
	void __cdecl hkGskRecalcContactInternal( hkVector4* verticesA, hkVector4* verticesB, int dimA, int dimB, const hkVector4& masterNormal, hkVector4& pointA, hkVector4& support );
	__forceinline void __cdecl hkGskRecalcContact( hkpGsk& gsk, const hkVector4& masterNormalA, hkVector4& pointBinAOut, hkVector4& supportOut )
	{
		hkGskRecalcContactInternal( &gsk.m_verticesA[0], &gsk.m_verticesBinA[0], gsk.m_dimA, gsk.m_dimB, masterNormalA, pointBinAOut, supportOut );
	}
}
namespace hkVector4Util
{
	__forceinline void __cdecl transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
	__forceinline void __cdecl rotateInversePoints( const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
	__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}
__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}
inline void __cdecl hkVector4Util::rotateInversePoints( const hkRotation& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	hkRotation unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setRotatedInverseDir( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
inline void __cdecl hkVector4Util::transformPoints( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}
namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap16(T& x, T& y)
	{
		__declspec(align(16)) T t = x;
		x = y;
		y = t;
	}
}
class hkStepInfo
{
	public:
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
namespace hkSweptTransformUtil
{
		void __cdecl lerp2Ha( const hkSweptTransform& sweptTrans, hkTime t, hkReal tAddOn, hkTransform& transformOut );
		__forceinline void __cdecl calcAngularTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4* deltaAngleOut0, hkVector4* deltaAngleOut1 );
}
void __cdecl hkSweptTransformUtil::calcAngularTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4* __restrict deltaAngleOut0, hkVector4* __restrict deltaAngleOut1)
{
	const hkSweptTransform& st0 = ms0.getSweptTransform();
	const hkSweptTransform& st1 = ms1.getSweptTransform();
	hkReal f0 = deltaTime * st0.getInvDeltaTime();
	hkReal f1 = deltaTime * st1.getInvDeltaTime();
	hkVector4 ang0; ang0.setMul4( f0, ms0.m_deltaAngle );
	hkVector4 ang1; ang1.setMul4( f1, ms1.m_deltaAngle );
	deltaAngleOut0[0] = ang0;
	deltaAngleOut1[0] = ang1;
}
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
	enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpProcessCollisionData
{
	public:
		inline hkBool hasToi() const;
	public:
		hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
		hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
		hkpProcessCdPoint m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
			public:
				hkContactPoint m_contactPoint;
				hkPadSpu<hkReal> m_time;
				hkPadSpu<hkReal> m_seperatingVelocity;
				hkGskCache16 m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
};
inline hkBool hkpProcessCollisionData::hasToi() const
{
	return m_toi.m_time != 3.40282e+38f;
}
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
	public:
		struct ContactRef
		{
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry* m_agentEntry;
			void* m_agentData;
		};
		struct PotentialInfo
		{
			ContactRef* m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint* m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*> m_potentialContacts;
};
struct hkp4dGskVertexCollidePointsInput
{
	hkPadSpu<const hkMotionState*> m_motionA;
	hkPadSpu<const hkMotionState*> m_motionB;
	hkPadSpu<hkVector4*> m_verticesA;
	hkPadSpu<int> m_numVertices;
	hkPadSpu<int> m_allocatedNumVertices;
	hkPadSpu<hkReal> m_radiusSum;
	hkPadSpu<hkReal> m_maxAccel;
	hkPadSpu<hkReal> m_invMaxAccel;
	hkVector4 m_planeB;
	hkVector4 m_pointOnPlaneB;
	hkPadSpu<const hkStepInfo*> m_stepInfo;
	hkPadSpu<hkReal> m_worstCaseApproachingDelta;
	hkVector4 m_linearTimInfo;
	hkVector4 m_deltaAngles[2];
	hkPadSpu<hkReal> m_startRt;
};
struct hkp4dGskTolerances
{
	hkPadSpu<hkReal> m_toiSeparation;
	hkPadSpu<hkReal> m_minSeparation;
	hkPadSpu<hkReal> m_minSafeDeltaRt;
	hkPadSpu<hkReal> m_minToiDeltaTime;
	hkPadSpu<hkReal> m_toiAccuracy;
};
struct hkp4dGskVertexCollidePointsOutput
{
	hkp4dGskVertexCollidePointsOutput() { m_Rtoi = 1.0f; }
	hkPadSpu<hkReal> m_Rtoi;
	hkVector4 m_collidingPoint;
};
struct hk4dGskCollideMatrices
{
	hkTransform m_wTa;
	hkTransform m_wTb;
	hkTransform m_aTb;
	hkVector4 m_plane;
	hkVector4 m_pointOnPlane;
	hkVector4 m_linearVel;
	hkVector4 m_angularVel[2];
	hkVector4 m_massCenterAinA;
	hkVector4 m_massCenterBinA;
};
void __cdecl hk4dGskCollideInitMatrices( const hkp4dGskVertexCollidePointsInput& input, hkReal Rt, hk4dGskCollideMatrices& out )
{
	const hkStepInfo* stepInfo = input.m_stepInfo;
	hkReal timeAddon = Rt * stepInfo->m_deltaTime;
	hkSweptTransformUtil::lerp2Ha( input.m_motionA->getSweptTransform(), stepInfo->m_startTime, timeAddon, out.m_wTa );
	hkSweptTransformUtil::lerp2Ha( input.m_motionB->getSweptTransform(), stepInfo->m_startTime, timeAddon, out.m_wTb );
	out.m_aTb.setMulInverseMul( out.m_wTa, out.m_wTb );
	out.m_plane.setRotatedDir( out.m_aTb.getRotation(), input.m_planeB );
	out.m_pointOnPlane.setTransformedPos( out.m_aTb, input.m_pointOnPlaneB );
	out.m_plane(3) = -input.m_radiusSum;
	out.m_massCenterAinA = input.m_motionA->getSweptTransform().m_centerOfMassLocal;
	hkVector4Util::rotateInversePoints( out.m_wTa.getRotation(), input.m_deltaAngles, 2, out.m_angularVel );
	out.m_massCenterBinA.setTransformedPos( out.m_aTb, input.m_motionB->getSweptTransform().m_centerOfMassLocal );
	out.m_linearVel.setRotatedInverseDir( out.m_wTa.getRotation(), input.m_linearTimInfo );
}
hkReal __cdecl hk4dGskCollidePointWithPlaneFinal( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, const hkVector4& vertexA, hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1, hkReal velocity, hkp4dGskVertexCollidePointsOutput& out )
{
	hk4dGskCollideMatrices mat;
	hkReal Rt = startRt;
	hkReal distance = distance0;
	const hkReal accuracy = tol.m_toiAccuracy * 0.25;
	for ( int iteration = 0; iteration < 10; iteration++ )
	{
		if ( distance0 <= tol.m_toiSeparation )
		{
			break;
		}
		hkReal delta = distance1 - distance0;
		if ( delta > -accuracy )
		{
			break;
		}
		hkReal rel = ( tol.m_toiSeparation - distance0 ) / delta;
		if ( !( iteration & 1 ) )
		{
			rel = hkMath::max2( rel, 0.1f );
			rel = hkMath::min2( rel, 0.9f );
		}
		Rt = ( 1.0f - rel ) * startRt + endRt * rel;
		hk4dGskCollideInitMatrices( input, Rt, mat );
		hkVector4 r; r.setSub4( vertexA, mat.m_pointOnPlane );
		distance = mat.m_plane.dot4xyz1( r );
		if ( hkMath::equal( distance, tol.m_toiSeparation, accuracy ) )
		{
			break;
		}
		if ( distance < tol.m_toiSeparation )
		{
			endRt = Rt;
			distance1 = distance;
		}
		else
		{
			startRt = Rt;
			distance0 = distance;
		}
	}
	if ( Rt < out.m_Rtoi )
	{
		out.m_Rtoi = Rt;
		out.m_collidingPoint = vertexA;
	}
	return out.m_Rtoi;
}
extern "C" void __cdecl hk4dGskCollidePointsWithPlane( const hkp4dGskVertexCollidePointsInput& input, const hkp4dGskTolerances& tol, hkp4dGskVertexCollidePointsOutput& out )
{
	hkReal endRt = 1.0f;
	hkReal Rt = input.m_startRt;
	hkReal lastT = Rt;
	int numVerticesA = input.m_numVertices;
	while ( numVerticesA )
	{
		hk4dGskCollideMatrices mat;
		hk4dGskCollideInitMatrices( input, Rt, mat );
		hkVector4* s = input.m_verticesA;
		hkVector4* d = s;
		hkReal timeRemaining = endRt - Rt;
		hkReal worstCaseDelta = timeRemaining * input.m_worstCaseApproachingDelta;
		hkReal nextT = endRt;
		int i = numVerticesA;
		numVerticesA = 0;
		for ( i--; i >= 0; s++, i-- )
		{
			hkReal distance;
			{
				hkVector4 r; r.setSub4( *s, mat.m_pointOnPlane );
				distance = mat.m_plane.dot4xyz1( r );
			}
			if ( distance > worstCaseDelta + tol.m_toiSeparation )
			{
				continue;
			}
			hkReal velocity;
			{
				hkVector4 mrA; mrA.setSub4( *s, mat.m_massCenterAinA );
				hkVector4 mrB; mrB.setSub4( *s, mat.m_massCenterBinA );
				hkVector4 armA; armA.setCross( mat.m_angularVel[0], mrA );
				hkVector4 armB; armB.setCross( mat.m_angularVel[1], mrB );
				hkVector4 vel4; vel4.setSub4( armA, mat.m_linearVel );
				vel4.sub4( armB );
				velocity = mat.m_plane.dot3( vel4 );
			}
			const hkReal hitDistance = distance - tol.m_toiSeparation;
			const hkReal hitDistanceAtT1UsingLinearProjection = hitDistance + velocity * timeRemaining;
			const hkReal maxSecondOrderError = timeRemaining * 0.5f * timeRemaining * input.m_maxAccel;
			if ( hitDistanceAtT1UsingLinearProjection > maxSecondOrderError )
			{
				continue;
			}
			if ( distance < tol.m_toiSeparation )
			{
				if ( Rt == input.m_startRt )
				{
					out.m_Rtoi = Rt;
					out.m_collidingPoint = *s;
					endRt = Rt;
				}
				else
				{
					hkReal oldDistance = (*s)(3);
					endRt = hk4dGskCollidePointWithPlaneFinal( input, tol, *s, lastT, Rt, oldDistance, distance, velocity, out );
				}
				continue;
			}
			hkAlgorithm::swap16( *s, *d );
			(*d)(3) = distance;
			d++;
			numVerticesA++;
			hkReal timeStep;
			{
				hkReal d0 = distance - tol.m_minSeparation;
				hkReal d1 = tol.m_toiSeparation - tol.m_minSeparation;
				hkReal t0sq = d0 * 2.0f * input.m_invMaxAccel;
				if ( t0sq > timeRemaining * timeRemaining )
				{
					continue;
				}
				hkReal t1sq = d1 * 2.0f * input.m_invMaxAccel;
				hkReal t0 = hkMath::sqrt( t0sq );
				if ( velocity >= 0.0f )
				{
					t0 += 2.0f * ( velocity * input.m_invMaxAccel );
				}
				else
				{
					hkReal t0x = -velocity * input.m_invMaxAccel;
					t0 = hkMath::max2( t0x, t0 );
				}
				if ( t0 > timeRemaining )
				{
					continue;
				}
				hkReal t1 = hkMath::sqrt( t1sq );
				timeStep = t0 + t1;
				timeStep = hkMath::max2( timeStep, tol.m_minSafeDeltaRt.val() );
			}
			nextT = hkMath::min2( nextT, timeStep + Rt );
		}
		if ( endRt < Rt )
		{
			break;
		}
		if ( Rt == nextT && endRt <= Rt )
		{
			break;
		}
		lastT = Rt;
		Rt = nextT;
		nextT = endRt;
	}
}
static hkReal hk4dGskCalcPointVelocityAssumingAngularVelError( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingPoint, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t )
{
	const hkReal angularVelocityFactor = 1.2f;
	hkVector4 relVel; relVel.setNeg4( linearTimInfo );
	hkReal separatingVelocity = relVel.dot3( separatingNormal );
	{
		const hkReal relT = msA->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msA->getSweptTransform().m_centerOfMass0, msA->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[0], relPos );
		const hkReal angVelPart = arm.dot3( separatingNormal );
		if ( angVelPart <= 0.0f )
		{
			separatingVelocity += angVelPart * angularVelocityFactor;
		}
		else
		{
			separatingVelocity += angVelPart / angularVelocityFactor;
		}
	}
	{
		const hkReal relT = msB->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msB->getSweptTransform().m_centerOfMass0, msB->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[1], relPos );
		const hkReal angVelPart = arm.dot3( separatingNormal );
		if ( angVelPart >= 0.0f )
		{
			separatingVelocity -= angVelPart * angularVelocityFactor;
		}
		else
		{
			separatingVelocity -= angVelPart / angularVelocityFactor;
		}
	}
	return separatingVelocity;
}
static __forceinline void hk4dGskCalcSeparatingNormal( const hkTransform& tA, const hkTransform& tB, const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, hkpGsk& gsk, hkVector4& separatingNormalOut, hkVector4& pointOnBInB )
{
	hkTransform aTb; aTb.setMulInverseMul( tA, tB );
	hkVector4 separatingNormalA;
	gsk.getClosestFeature( shapeA, shapeB, aTb, separatingNormalA );
	separatingNormalOut._setRotatedDir( tA.getRotation(), separatingNormalA );
	hkVector4 pointInA;
	gsk.getClosestPointAinA( separatingNormalA, pointInA );
	pointInA.subMul4( separatingNormalA.getSimdAt(3), separatingNormalA );
	pointOnBInB._setTransformedInversePos( aTb, pointInA );
	separatingNormalOut(3) = separatingNormalA(3) - shapeA->getRadius() - shapeB->getRadius();
}
static __forceinline void hk4dGskCalcWorstCaseProjectedVelocity( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkReal& realProjectedLinearDelta, hkReal& projectedAngularDelta )
{
	hkVector4 crossAngleA; crossAngleA.setCross( deltaAngles[0], separatingNormal );
	hkVector4 crossAngleB; crossAngleB.setCross( deltaAngles[1], separatingNormal );
	hkReal lenA = crossAngleA.length3() * msA->m_objectRadius;
	hkReal lenB = crossAngleB.length3() * msB->m_objectRadius;
	projectedAngularDelta = lenA + lenB;
	realProjectedLinearDelta = linearTimInfo.dot3( separatingNormal );
}
static __forceinline void hk4dGskCollPInputInitialize( const hkpAgent3ProcessInput& in3, hkp4dGskVertexCollidePointsInput& input )
{
	const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
	const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
	const hkMotionState* msA = in3.m_bodyA->getMotionState();
	const hkMotionState* msB = in3.m_bodyB->getMotionState();
	input.m_motionA = msA;
	input.m_motionB = msB;
	input.m_radiusSum = shapeA->getRadius() + shapeB->getRadius();
	input.m_linearTimInfo = in3.m_linearTimInfo;
	input.m_stepInfo = &in3.m_input->m_stepInfo;
	int numVertices = shapeA->getNumCollisionSpheres();
	input.m_allocatedNumVertices = numVertices;
	input.m_numVertices = numVertices;
	input.m_verticesA = hkAllocateStack<hkVector4>( numVertices );
	shapeA->getCollisionSpheres( reinterpret_cast<hkSphere*>( input.m_verticesA.val() ) );
	const hkReal a = msA->m_objectRadius * input.m_deltaAngles[0](3) * input.m_deltaAngles[0](3);
	const hkReal b = msB->m_objectRadius * input.m_deltaAngles[1](3) * input.m_deltaAngles[1](3);
	input.m_maxAccel = a + b;
	input.m_invMaxAccel = 1.0f / ( input.m_maxAccel + 1.192092896e-07F );
}
static __forceinline hkReal hk4dGskCalcPointVelocity( const hkMotionState* msA, const hkMotionState* msB, const hkVector4& separatingPoint, const hkVector4& separatingNormal, const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t )
{
	hkVector4 relVel; relVel.setNeg4( linearTimInfo );
	{
		const hkReal relT = msA->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msA->getSweptTransform().m_centerOfMass0, msA->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[0], relPos );
		relVel.add4( arm );
	}
	{
		const hkReal relT = msB->getSweptTransform().getInterpolationValue( t );
		hkVector4 massCenter; massCenter.setInterpolate4( msB->getSweptTransform().m_centerOfMass0, msB->getSweptTransform().m_centerOfMass1, relT );
		hkVector4 relPos; relPos.setSub4( separatingPoint, massCenter );
		hkVector4 arm; arm.setCross( deltaAngles[1], relPos );
		relVel.sub4( arm );
	}
	const hkReal separatingVelocity = relVel.dot3( separatingNormal );
	return separatingVelocity;
}
// pdb: hk4dGskCalcToiFinal | hkpContinuousGsk.obj | tesv_win, caller_sim, low
void __cdecl FUN_00a42220( const hkpAgent3ProcessInput& in3, hkp4dGskTolerances& tol, hkpGsk& gsk, int featureChange, const hkVector4& oldMasterNormal, const hkVector4* deltaAngles, hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1, hkpProcessCollisionOutput& out )
{
	hkReal Rt = startRt;
	hkReal distance = distance0;
	hkTransform wTa;
	hkTransform wTb;
	hkTransform aTb;
	hkVector4 normalA;
	hkVector4 pointA;
	hkReal radiusSum;
	{
		const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
		const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
		radiusSum = shapeA->getRadius() + shapeB->getRadius();
	}
	hkReal velocityBasedOnDistance = ( distance1 - distance0 ) / ( endRt - startRt );
	for ( int iteration = 0; iteration < 10; iteration++ )
	{
		hkReal delta = distance1 - distance0;
		if ( delta > -tol.m_toiAccuracy )
		{
			endRt = startRt;
			delta = 0.5f;
		}
		hkBool earlyOut;
		if ( hkMath::equal( distance1, tol.m_toiSeparation, tol.m_toiAccuracy ) )
		{
			earlyOut = true;
			featureChange = 0;
			Rt = endRt;
		}
		else
		{
			earlyOut = false;
			hkReal rel = ( tol.m_toiSeparation - distance0 ) / delta;
			rel = hkMath::max2( rel, 0.1f );
			rel = hkMath::min2( rel, 0.9f );
			Rt = ( 1.0f - rel ) * startRt + endRt * rel;
		}
		const hkStepInfo& stepInfo = in3.m_input->m_stepInfo;
		hkReal timeAddon = Rt * stepInfo.m_deltaTime;
		hkSweptTransformUtil::lerp2Ha( in3.m_bodyA->getMotionState()->getSweptTransform(), stepInfo.m_startTime, timeAddon, wTa );
		hkSweptTransformUtil::lerp2Ha( in3.m_bodyB->getMotionState()->getSweptTransform(), stepInfo.m_startTime, timeAddon, wTb );
		aTb.setMulInverseMul( wTa, wTb );
		if ( featureChange )
		{
			const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
			const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
			gsk.getClosestFeature( shapeA, shapeB, aTb, normalA );
			gsk.getClosestPointAinA( normalA, pointA );
		}
		else
		{
			hkVector4Util::transformPoints( aTb, &gsk.m_verticesBinB[0], gsk.m_dimB, &gsk.m_verticesBinA[0] );
			hkVector4 oldMasterNormalInA; oldMasterNormalInA._setRotatedInverseDir( wTa.getRotation(), oldMasterNormal );
			hkGskRecalcContact( gsk, oldMasterNormalInA, pointA, normalA );
		}
		distance = normalA(3) - radiusSum;
		if ( hkMath::equal( distance, tol.m_toiSeparation, tol.m_toiAccuracy ) || earlyOut )
		{
			break;
		}
		if ( startRt == endRt )
		{
			break;
		}
		if ( distance < tol.m_toiSeparation )
		{
			endRt = Rt;
			distance1 = distance;
		}
		else
		{
			startRt = Rt;
			distance0 = distance;
		}
	}
	const hkStepInfo& stepInfo = in3.m_input->m_stepInfo;
	hkReal deltaTime = hkMath::max2( stepInfo.m_deltaTime.val() * Rt, tol.m_minToiDeltaTime.val() );
	hkTime toi = stepInfo.m_startTime + deltaTime;
	if ( toi < out.m_toi.m_time && toi < stepInfo.m_endTime - tol.m_minToiDeltaTime )
	{
		hkGskCache16 cache;
		hkReal separatingVelocity;
		const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>( in3.m_bodyA->getShape() );
		hkContactPoint cp;
		{
			hkVector4 pointWs; pointWs.setTransformedPos( wTa, pointA );
			cp.getSeparatingNormal().setRotatedDir( wTa.getRotation(), normalA );
			cp.getPosition().setAddMul4( pointWs, cp.getSeparatingNormal(), -shapeA->getRadius() - distance );
			cp.setDistance( distance );
			hkpConvexShape::WeldResult weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
			hkVector4 weldedNormal = cp.getSeparatingNormal();
			if ( in3.m_bodyB->getShape()->getType() == HK_SHAPE_TRIANGLE )
			{
				{
					hkpVertexId featurePoints[3];
					hkUint8 numFeaturePoints = hkUint8( gsk.m_dimB );
					featurePoints[0] = hkpVertexId( gsk.m_verticesBinB[0].getId() );
					featurePoints[1] = ( numFeaturePoints < 2 ) ? 0xffff : hkpVertexId( gsk.m_verticesBinB[1].getId() );
					featurePoints[2] = ( numFeaturePoints < 3 ) ? 0xffff : hkpVertexId( gsk.m_verticesBinB[2].getId() );
					const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
					weldResult = shapeB->weldContactPoint( featurePoints, numFeaturePoints, cp.getPosition(), &wTb, shapeA, &wTa, weldedNormal );
				}
				cp.setSeparatingNormal( weldedNormal );
EXAMINE_WELD_RESULTS:
				if ( weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT && in3.m_input->m_collisionQualityInfo->m_enableToiWeldRejection )
				{
					return;
				}
			}
			else if ( in3.m_bodyA->getShape()->getType() == HK_SHAPE_TRIANGLE )
			{
				hkpVertexId featurePoints[3];
				hkUint8 numFeaturePoints = hkUint8( gsk.m_dimA );
				featurePoints[0] = hkpVertexId( gsk.m_verticesA[0].getId() );
				featurePoints[1] = ( numFeaturePoints < 2 ) ? 0xffff : hkpVertexId( gsk.m_verticesA[1].getId() );
				featurePoints[2] = ( numFeaturePoints < 3 ) ? 0xffff : hkpVertexId( gsk.m_verticesA[2].getId() );
				hkVector4 dist; dist.setBroadcast( weldedNormal, 3 );
				hkVector4 pointOnA; pointOnA.setAddMul4( cp.getPosition(), weldedNormal, dist );
				weldedNormal.setNeg3( weldedNormal );
				const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>( in3.m_bodyB->getShape() );
				weldResult = shapeA->weldContactPoint( featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb, weldedNormal );
				weldedNormal.setNeg3( weldedNormal );
				cp.setSeparatingNormal( weldedNormal );
				goto EXAMINE_WELD_RESULTS;
			}
			const hkMotionState* msA = in3.m_bodyA->getMotionState();
			const hkMotionState* msB = in3.m_bodyB->getMotionState();
			separatingVelocity = hk4dGskCalcPointVelocity( msA, msB, cp.getPosition(), cp.getNormal(), in3.m_linearTimInfo, deltaAngles, toi );
			if ( weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED && separatingVelocity > -1.192092896e-07F )
			{
				hkp4dGskVertexCollidePointsInput collPInput;
				collPInput.m_startRt = Rt;
				{
					hkSweptTransformUtil::calcAngularTimInfo( *msA, *msB, in3.m_input->m_stepInfo.m_deltaTime, &collPInput.m_deltaAngles[0], &collPInput.m_deltaAngles[1] );
					hkReal realProjectedLinearDelta, projectedAngularDelta;
					hk4dGskCalcWorstCaseProjectedVelocity( msA, msB, cp.getNormal(), in3.m_linearTimInfo, collPInput.m_deltaAngles, realProjectedLinearDelta, projectedAngularDelta );
					collPInput.m_worstCaseApproachingDelta = realProjectedLinearDelta + projectedAngularDelta;
				}
				hk4dGskCollPInputInitialize( in3, collPInput );
				collPInput.m_planeB.setRotatedInverseDir( wTb.getRotation(), cp.getNormal() );
				collPInput.m_pointOnPlaneB = gsk.m_verticesBinB[0];
				if ( collPInput.m_verticesA.val() )
				{
					hkp4dGskVertexCollidePointsOutput collidePointsOut;
					hk4dGskCollidePointsWithPlane( collPInput, tol, collidePointsOut );
					hkDeallocateStack( collPInput.m_verticesA.val() );
					if ( collidePointsOut.m_Rtoi < 1.0f )
					{
						hkVector4 newPos; newPos.setTransformedPos( wTa, collidePointsOut.m_collidingPoint );
						cp.getPosition() = newPos;
					}
				}
			}
			if ( velocityBasedOnDistance < separatingVelocity )
			{
				if ( separatingVelocity * 1.2f < velocityBasedOnDistance )
				{
					separatingVelocity = velocityBasedOnDistance;
				}
				else
				{
					separatingVelocity = hk4dGskCalcPointVelocityAssumingAngularVelError( in3.m_bodyA->getMotionState(), in3.m_bodyB->getMotionState(), cp.getPosition(), cp.getNormal(), in3.m_linearTimInfo, deltaAngles, toi );
					separatingVelocity = hkMath::min2( 0.0f, separatingVelocity );
				}
			}
			separatingVelocity *= stepInfo.m_invDeltaTime;
		}
		hkContactPointPropertiesWithExtendedUserData16 properties;
		properties.setUserData( 0 );
		properties.m_internalDataA = 321.0f;
		properties.m_internalSolverData = 0.0f;
		properties.m_impulseApplied = 0.0f;
		gsk.exitAndExportCacheImpl( cache );
		hkpContactMgr::ToiAccept cbResult = in3.m_contactMgr->addToi( *in3.m_bodyA.val(), *in3.m_bodyB.val(), *in3.m_input.val(), out, toi, cp, &cache, separatingVelocity, properties );
		if ( cbResult == hkpContactMgr::TOI_ACCEPT )
		{
			if ( out.hasToi() )
			{
				in3.m_contactMgr->removeToi( *out.m_constraintOwner.val(), out.m_toi.m_properties );
			}
			out.m_toi.m_seperatingVelocity = separatingVelocity;
			out.m_toi.m_contactPoint = cp;
			out.m_toi.m_time = toi;
			out.m_toi.m_properties.set( properties );
			out.m_toi.m_gskCache.set( cache );
		}
	}
}
}
}   // namespace f3m_00a42220
