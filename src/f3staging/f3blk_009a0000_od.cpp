// src/f3staging/f3blk_009a0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009b8ba0 (community match, verified in this file)
namespace f3m_009b8ba0 {
// 0x009b8ba0: bounding-volume-tree agent, process collision (x87 build of the physics library).
// Fresh port of the FNV twin's structure with scalar (FPU) vector helpers and the older array/memory layer.
// Matches under /MT /O2 /GS- /EHs-c- /Gy. Fake-match constructs (marked where they stand): 23 dead int locals and one
// dead vector local in calcTimInfo, and the named lane references in Vec4::setCross.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace N9b8ba0 {

typedef float Real;
typedef unsigned int UInt32;
typedef unsigned int Key;

extern unsigned long DAT_0116913c;   // monitor stream thread slot
extern unsigned long DAT_010f3170;   // thread memory thread slot

template <class T>
class Pad
{
	public:
		__forceinline Pad() {}
		__forceinline Pad( T e ) : m_storage( e ) {}
		__forceinline void operator=( T e ) { m_storage = e; }
		__forceinline T val() const { return m_storage; }
		__forceinline T operator->() const { return m_storage; }
		__forceinline operator T() const { return val(); }
	private:
		T m_storage;
};

class Bool
{
	public:
		inline Bool() {}
		inline Bool( bool b ) { m_bool = static_cast<char>( b ); }
		inline operator bool() const { return m_bool != 0; }
	private:
		char m_bool;
};

extern Bool DAT_01061950;   // cache the query box between steps
extern Bool DAT_011693e0;   // use the fast (unsorted) update

class Comparison
{
	public:
		enum Mask
		{
			MASK_NONE = 0,
			MASK_W = 1,
			MASK_Z = 2,
			MASK_Y = 4,
			MASK_X = 8,
			MASK_XYZ = 14
		};
		__forceinline void setAnd( const Comparison& a, const Comparison& b ) { m_mask = a.m_mask & b.m_mask; }
		__forceinline int allAreSet( Mask m ) const { return ( m_mask & m ) == m; }
		int m_mask;
};

class Rotation;
class Transform;

class __declspec(align(16)) Vec4
{
	public:
		__forceinline void operator=( const Vec4& v ) { x = v.x; y = v.y; z = v.z; w = v.w; }
		__forceinline void setAll3( Real a ) { x = a; y = a; z = a; w = a; }
		__forceinline void setZero4() { x = 0; y = 0; z = 0; w = 0; }
		__forceinline void add4( const Vec4& v ) { x += v.x; y += v.y; z += v.z; w += v.w; }
		__forceinline void sub4( const Vec4& v ) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }
		__forceinline void setAdd4( const Vec4& a, const Vec4& b ) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
		__forceinline void setSub4( const Vec4& a, const Vec4& b ) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
		__forceinline void setMul4( Real r, const Vec4& v ) { x = r * v.x; y = r * v.y; z = r * v.z; w = r * v.w; }
		__forceinline void addMul4( Real r, const Vec4& v ) { x += r * v.x; y += r * v.y; z += r * v.z; w += r * v.w; }
		__forceinline void setNeg4( const Vec4& v ) { x = -v.x; y = -v.y; z = -v.z; w = -v.w; }
		__forceinline void setCross( const Vec4& a, const Vec4& b )
		{
			// Fake match: the six lanes are read through named references declared in this order. The declaration order
			// (with the symbol numbering set by the dead locals in calcTimInfo) decides which operand of each product the
			// compiler loads first; plain a.y * b.z loads the second vector's lane first in three products.
			const Real& ax = a.x; const Real& ay = a.y; const Real& az = a.z; const Real& bx = b.x; const Real& by = b.y; const Real& bz = b.z;
			const Real cx = ay * bz - az * by;
			const Real cy = az * bx - ax * bz;
			const Real cz = ax * by - ay * bx;
			x = cx; y = cy; z = cz; w = 0;
		}
		__forceinline void setMin4( const Vec4& a, const Vec4& b )
		{
			x = a.x < b.x ? a.x : b.x;
			y = a.y < b.y ? a.y : b.y;
			z = a.z < b.z ? a.z : b.z;
			w = a.w < b.w ? a.w : b.w;
		}
		__forceinline void setMax4( const Vec4& a, const Vec4& b )
		{
			x = a.x > b.x ? a.x : b.x;
			y = a.y > b.y ? a.y : b.y;
			z = a.z > b.z ? a.z : b.z;
			w = a.w > b.w ? a.w : b.w;
		}
		__forceinline Comparison compareLessThanEqual4( const Vec4& a ) const
		{
			Comparison ret;
			ret.m_mask = ( ( x <= a.x ) ? Comparison::MASK_X : 0 ) |
			             ( ( y <= a.y ) ? Comparison::MASK_Y : 0 ) |
			             ( ( z <= a.z ) ? Comparison::MASK_Z : 0 ) |
			             ( ( w <= a.w ) ? Comparison::MASK_W : 0 );
			return ret;
		}
		__forceinline void rotInvDir( const Rotation& r, const Vec4& b );
		__forceinline void xformInvPos( const Transform& a, const Vec4& b );

		Real x;
		Real y;
		Real z;
		Real w;
};

class Rotation
{
	public:
		Vec4 m_col0;
		Vec4 m_col1;
		Vec4 m_col2;
};

class Transform
{
	public:
		__forceinline Transform() {}
		__forceinline const Rotation& getRotation() const { return m_rotation; }
		__forceinline const Vec4& getTranslation() const { return m_translation; }
		void FUN_00925300( const Transform& a, const Transform& b );
	protected:
		Rotation m_rotation;
		Vec4 m_translation;
};

inline void Vec4::rotInvDir( const Rotation& r, const Vec4& b )
{
	Real v0 = b.x;
	Real v1 = b.y;
	Real v2 = b.z;
	x = r.m_col0.x * v0 + r.m_col0.y * v1 + r.m_col0.z * v2;
	y = r.m_col1.x * v0 + r.m_col1.y * v1 + r.m_col1.z * v2;
	z = r.m_col2.x * v0 + r.m_col2.y * v1 + r.m_col2.z * v2;
	w = 0;
}

inline void Vec4::xformInvPos( const Transform& a, const Vec4& b )
{
	const Rotation& r = a.getRotation();
	Real v0 = b.x - a.getTranslation().x;
	Real v1 = b.y - a.getTranslation().y;
	Real v2 = b.z - a.getTranslation().z;
	x = r.m_col0.x * v0 + r.m_col0.y * v1 + r.m_col0.z * v2;
	y = r.m_col1.x * v0 + r.m_col1.y * v1 + r.m_col1.z * v2;
	z = r.m_col2.x * v0 + r.m_col2.y * v1 + r.m_col2.z * v2;
	w = 0;
}

class Aabb
{
	public:
		Aabb() {}
		__forceinline Bool contains( const Aabb& other ) const
		{
			Comparison mincomp = m_min.compareLessThanEqual4( other.m_min );
			Comparison maxcomp = other.m_max.compareLessThanEqual4( m_max );
			Comparison both; both.setAnd( mincomp, maxcomp );
			return both.allAreSet( Comparison::MASK_XYZ ) != 0;
		}
		Vec4 m_min;
		Vec4 m_max;
};

class Swept
{
	public:
		__forceinline Real getInvDeltaTime() const { return m_centerOfMass1.w; }
		Vec4 m_centerOfMass0;
		Vec4 m_centerOfMass1;
		Vec4 m_rotation0;
		Vec4 m_rotation1;
		Vec4 m_centerOfMassLocal;
};

class MotionState
{
	public:
		inline const Swept& getSweptTransform() const { return m_sweptTransform; }
	protected:
		Transform m_transform;
		Swept m_sweptTransform;
	public:
		Vec4 m_deltaAngle;
		Real m_objectRadius;
		Real m_linearDamping;
		Real m_angularDamping;
};

__forceinline void __cdecl calcTimInfo( const MotionState& ms0, const MotionState& ms1, Real deltaTime, Vec4& timOut )
{
	// Fake match: dead named locals. They only shift the compiler's internal symbol numbering, which decides the
	// operand order of several x87 adds and multiplies further down (centre plus radius lanes, scaled lanes).
	int numberingPad0 = 0;
	int numberingPad1 = 0;
	int numberingPad2 = 0;
	int numberingPad3 = 0;
	int numberingPad4 = 0;
	int numberingPad5 = 0;
	int numberingPad6 = 0;
	int numberingPad7 = 0;
	int numberingPad8 = 0;
	int numberingPad9 = 0;
	int numberingPad10 = 0;
	int numberingPad11 = 0;
	int numberingPad12 = 0;
	int numberingPad13 = 0;
	int numberingPad14 = 0;
	int numberingPad15 = 0;
	int numberingPad16 = 0;
	int numberingPad17 = 0;
	int numberingPad18 = 0;
	int numberingPad19 = 0;
	int numberingPad20 = 0;
	int numberingPad21 = 0;
	int numberingPad22 = 0;
	const Swept& st0 = ms0.getSweptTransform();
	const Swept& st1 = ms1.getSweptTransform();
	// Fake match: a dead vector local declared before the two deltas; it makes the scaled y lane multiply in the
	// original's operand order (scale factor first).
	Vec4 numberingPadV; numberingPadV.setZero4();
	Vec4 diff0; diff0.setSub4( st0.m_centerOfMass0, st0.m_centerOfMass1 );
	Vec4 diff1; diff1.setSub4( st1.m_centerOfMass1, st1.m_centerOfMass0 );
	timOut.setMul4( deltaTime * st0.getInvDeltaTime(), diff0 );
	timOut.addMul4( deltaTime * st1.getInvDeltaTime(), diff1 );
}

// ---- memory ----

class ThreadMemory
{
	public:
		virtual void v00();
		virtual void v04();
		virtual void v08();
		virtual void v0c();
		virtual void v10();
		virtual void* onStackOverflow( int numBytes );
		virtual void onStackUnderflow( void* p );

		void* FUN_008f6d30( int numBytes, int cls );
		void FUN_008f6d90( void* p, int numBytes, int cls );

		static __forceinline ThreadMemory& getInstance() { return *static_cast<ThreadMemory*>( TlsGetValue( DAT_010f3170 ) ); }

		__forceinline void* allocateStack( int numBytes )
		{
			char* current = m_stackCurrent;
			char* next = current + numBytes;
			if ( next <= m_stackEnd )
			{
				m_stackCurrent = next;
				return current;
			}
			return onStackOverflow( numBytes );
		}
		__forceinline void deallocateStack( void* p )
		{
			m_stackCurrent = static_cast<char*>( p );
			if ( p == m_stackBase )
			{
				onStackUnderflow( p );
			}
		}

		int m_unk04;
		int m_unk08;
		int m_unk0c;
		int m_unk10;
		int m_unk14;
		int m_unk18;
		int m_unk1c;
		char* m_stackCurrent;   // 0x20
		char* m_stackPrev;      // 0x24
		char* m_stackBase;      // 0x28
		char* m_stackEnd;       // 0x2c
};

template <typename T>
__forceinline T* __cdecl allocStack( int n )
{
	return static_cast<T*>( ThreadMemory::getInstance().allocateStack( ( n * sizeof( T ) + 16 ) & ~15 ) );
}

template <typename T>
__forceinline void __cdecl freeStack( T* p )
{
	ThreadMemory::getInstance().deallocateStack( p );
}

void __cdecl FUN_00901e90( void* array, int numElem, int sizeElem );   // array reserve

template <typename T>
class Array
{
	public:
		enum
		{
			CAPACITY_MASK = int( 0x3FFFFFFF ),
			FLAG_MASK = int( 0xC0000000 ),
			DONT_DEALLOCATE_FLAG = int( 0x80000000 ),
			LOCKED_FLAG = int( 0x40000000 )
		};
		__forceinline Array() : m_data( 0 ), m_size( 0 ), m_capacityAndFlags( DONT_DEALLOCATE_FLAG ) {}
		__forceinline Array( T* buffer, int size, int capacity ) : m_data( buffer ), m_size( size ), m_capacityAndFlags( capacity | DONT_DEALLOCATE_FLAG ) {}
		__forceinline ~Array()
		{
			if ( ( m_capacityAndFlags & DONT_DEALLOCATE_FLAG ) == 0 )
			{
				ThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * sizeof( T ), 0x17 );
			}
		}
		__forceinline int getSize() const { return m_size; }
		__forceinline int getCapacity() const { return ( m_capacityAndFlags & static_cast<int>( CAPACITY_MASK ) ); }
		__forceinline T* begin() { return m_data; }
		__forceinline T* end() { return m_data + m_size; }
		__forceinline void reserve( int n )
		{
			const int capacity = getCapacity();
			if ( capacity < n )
			{
				int cap2 = 2 * capacity;
				int newSize = ( n < cap2 ) ? cap2 : n;
				FUN_00901e90( this, newSize, sizeof( T ) );
			}
		}
		__forceinline void setSize( int n )
		{
			reserve( n );
			m_size = n;
		}
		__forceinline void removeAtAndCopy( int index )
		{
			m_size--;
			for ( int i = index; i < m_size; i++ )
			{
				m_data[i] = m_data[i + 1];
			}
		}
		__forceinline T* expandAt( int index, int numtoinsert )
		{
			const int newsize = numtoinsert + m_size;
			const int numtomove = m_size - index;
			reserve( newsize );
			copyBackwards( m_data + index + numtoinsert, m_data + index, numtomove );
			m_size = newsize;
			return m_data + index;
		}
		static __forceinline void __cdecl copy( T* dst, const T* src, int n )
		{
			for ( int i = 0; i < n; ++i )
			{
				dst[i] = src[i];
			}
		}
		static __forceinline void __cdecl copyBackwards( T* dst, const T* src, int n )
		{
			for ( int i = n - 1; i >= 0; --i )
			{
				dst[i] = src[i];
			}
		}
		__forceinline Array& operator=( const Array& a )
		{
			if ( getCapacity() < a.m_size )
			{
				if ( ( m_capacityAndFlags & DONT_DEALLOCATE_FLAG ) == 0 )
				{
					ThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * sizeof( T ), 0x17 );
				}
				m_data = static_cast<T*>( ThreadMemory::getInstance().FUN_008f6d30( a.m_size * sizeof( T ), 0x17 ) );
				m_capacityAndFlags = ( m_capacityAndFlags & LOCKED_FLAG ) | a.m_size;
			}
			m_size = a.m_size;
			copy( m_data, a.m_data, m_size );
			return *this;
		}
	protected:
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
};

template <typename T, unsigned N>
class InplaceArray : public Array<T>
{
	public:
		__forceinline InplaceArray() : Array<T>( m_storage, 0, N ) {}
		__forceinline ~InplaceArray() {}
	protected:
		T m_storage[N];
};

template <typename T>
class LocalArray : public Array<T>
{
	public:
		__forceinline LocalArray( int capacity )
		{
			this->m_data = allocStack<T>( capacity );
			this->m_capacityAndFlags = capacity | Array<T>::DONT_DEALLOCATE_FLAG;
			m_localMemory = this->m_data;
		}
		__forceinline ~LocalArray()
		{
			freeStack<T>( m_localMemory );
		}
		T* m_localMemory;
};

template <typename T>
class Less
{
	public:
		__forceinline int operator()( const T& a, const T& b ) { return ( a < b ); }
};

void __cdecl FUN_009b5910( Key* pArr, int d, int h, Less<Key> cmpLess );   // quick sort, recursive part

template <typename T, typename L>
__forceinline void __cdecl quickSort( T* pArr, int nItems, L cmpLess )
{
	if ( nItems > 1 )
	{
		int low = 0;
		int high = nItems - 1;
		FUN_009b5910( pArr, low, high, cmpLess );
	}
}

template <typename T>
__forceinline void __cdecl quickSort( T* pArr, int nItems ) { quickSort( pArr, nItems, Less<T>() ); }

// ---- timers ----

class Monitor
{
	public:
		static __forceinline Monitor& getInstance() { return *static_cast<Monitor*>( TlsGetValue( DAT_0116913c ) ); }
		__forceinline char* getEnd() { return m_end; }
		__forceinline int memoryAvailable() { return m_end < m_capacityMinus16; }
		__forceinline void setEnd( char* ptr ) { m_end = ptr; }
		char* m_start;
		char* m_end;
		char* m_capacity;
		char* m_capacityMinus16;
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct TimerCommand : public Command
		{
			UInt32 m_time0;
			UInt32 m_time1;
			__forceinline void setTime()
			{
				UInt32 ticks;
				__asm {
					rdtsc
					mov dword ptr[ticks], eax
				}
				m_time0 = ticks;
			}
		};
		struct TimerBeginListCommand : public TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};

// ---- collision types ----

class Shape;
class ShapeContainer;
class Agent;
class ContactMgr;
class ConstraintOwner;
struct CollisionInput;
struct ProcessInput;
struct ProcessOutput;

typedef __declspec(align(16)) char ShapeBuffer[512];

class CdBody
{
	public:
		__forceinline CdBody( const CdBody* parent ) { m_parent = parent; m_motion = parent->m_motion; }
		__forceinline const Transform& getTransform() const { return *static_cast<const Transform*>( m_motion ); }
		__forceinline const MotionState* getMotionState() const { return static_cast<const MotionState*>( m_motion ); }
		__forceinline const Shape* getShape() const { return m_shape; }
		__forceinline void setShape( const Shape* shape, Key key ) { m_shape = shape; m_shapeKey = key; }
		const Shape* m_shape;
		Key m_shapeKey;
		const void* m_motion;
		const CdBody* m_parent;
};

class ShapeContainer
{
	public:
		virtual void v00();
		virtual void v04();
		virtual void v08();
		virtual void v0c();
		virtual void v10();
		virtual const Shape* getChildShape( Key key, ShapeBuffer& buffer ) const;
};

class Shape
{
	public:
		virtual void v00();
		virtual void v04();
		virtual void v08();
		virtual void v0c();
		virtual void v10();
		virtual const ShapeContainer* getContainer() const;
		virtual void v18();
		virtual void getAabb( const Transform& localToWorld, Real tolerance, Aabb& out ) const;
		virtual void v20();
		virtual void v24();
		virtual void v28();
		virtual void queryAabb( const Aabb& aabb, Array<Key>& hits ) const;
		__forceinline int getType() const { return m_type; }
		unsigned short m_memSizeAndFlags;
		short m_referenceCount;
		UInt32 m_userData;
		int m_type;
};

class ShapeFilter
{
	public:
		virtual void v00();
		virtual Bool isCollisionEnabled( const CollisionInput& input, const CdBody& a, const CdBody& b, const ShapeContainer& bContainer, Key bKey ) const;
};

class Agent
{
	public:
		virtual void v00();
		virtual void v04();
		virtual void v08();
		virtual void v0c();
		virtual void v10();
		virtual void v14();
		virtual void processCollision( const CdBody& a, const CdBody& b, const ProcessInput& input, ProcessOutput& result );
		virtual void cleanup( ConstraintOwner& info );
		unsigned short m_memSizeAndFlags;
		short m_referenceCount;
		ContactMgr* m_contactMgr;
};

Agent* __cdecl FUN_00990590();   // the shared do-nothing agent

class Dispatcher
{
	public:
		typedef Agent* ( __cdecl *CreateFunc )( const CdBody& collA, const CdBody& collB, const CollisionInput& env, ContactMgr* mgr );
		struct AgentFuncs
		{
			CreateFunc m_createFunc;
			void* m_getPenetrationsFunc;
			void* m_getClosestPointFunc;
			void* m_linearCastFunc;
			Bool m_isFlipped;
			Bool m_isPredictive;
		};
		__forceinline CreateFunc getCollisionAgentCreationFunction( int typeA, int typeB, int predictive ) const
		{
			int idx = ( predictive ? m_agent2TypesPred : m_agent2Types )[typeA][typeB];
			return m_agent2Func[idx].m_createFunc;
		}
		__forceinline Agent* getNewCollisionAgent( const CdBody& collA, const CdBody& collB, const CollisionInput& environment, ContactMgr* mgr ) const;

		void* m_vtable;
		unsigned short m_memSizeAndFlags;
		short m_referenceCount;
		void* m_defaultCollisionAgent;
		void* m_contactMgrFactory[8][8];        // 0x00c
		UInt32 m_hasAlternateType[32];          // 0x10c
		int m_numAgent2Types;                   // 0x18c
		int m_numAgent3Types;                   // 0x190
		int m_collisionAgentRegistered;         // 0x194
		int m_agent3Registered;                 // 0x198
		int m_checkEnabled;                     // 0x19c
		unsigned char m_agent2Types[32][32];    // 0x1a0
		unsigned char m_agent2TypesPred[32][32];// 0x5a0
		AgentFuncs m_agent2Func[64];            // 0x9a0
};

struct CollisionInput
{
	Pad<Dispatcher*> m_dispatcher;                // 0x00
	Pad<Real> m_tolerance;                        // 0x04
	Pad<const ShapeFilter*> m_filter;             // 0x08
	Pad<const void*> m_convexListFilter;          // 0x0c
	mutable Pad<UInt32> m_createPredictiveAgents; // 0x10
	struct Aabb32Info
	{
		Vec4 m_bitOffsetLow;
		Vec4 m_bitOffsetHigh;
		Vec4 m_bitScale;
	};
	Aabb32Info m_aabb32Info;                      // 0x20
};

inline Agent* Dispatcher::getNewCollisionAgent( const CdBody& collA, const CdBody& collB, const CollisionInput& environment, ContactMgr* mgr ) const
{
	const int typeA = collA.getShape()->getType();
	const int typeB = collB.getShape()->getType();
	CreateFunc f = getCollisionAgentCreationFunction( typeA, typeB, environment.m_createPredictiveAgents.val() );
	return f( collA, collB, environment, mgr );
}

struct StepInfo
{
	Pad<Real> m_startTime;
	Pad<Real> m_endTime;
	Pad<Real> m_deltaTime;
	Pad<Real> m_invDeltaTime;
};

struct QualityInfo
{
	Real m_keepContact;
	Real m_create4dContact;
	Real m_manifoldTimDistance;
	Real m_createContact;
	Pad<UInt32> m_useContinuousPhysics;
};

struct ProcessInput : public CollisionInput
{
	StepInfo m_stepInfo;                              // 0x50
	mutable Pad<QualityInfo*> m_collisionQualityInfo; // 0x60
};

struct ProcessOutput
{
	void* m_firstFreeContactPoint;
	Pad<ConstraintOwner*> m_constraintOwner;
};

class DispatchHelper
{
	public:
		__forceinline DispatchHelper( const CdBody& body ) : m_bodyB( &body )
		{
		}
		__forceinline const CdBody* getBodyB( const CdBody& cIn, const CollisionInput& input, Key key )
		{
			m_bodyB.setShape( m_container->getChildShape( key, m_shapeBuffer ), key );
			return &m_bodyB;
		}
		__forceinline const ShapeContainer* getShapeContainerB()
		{
			return m_container;
		}
		const ShapeContainer* m_container;
		CdBody m_bodyB;
		ShapeBuffer m_shapeBuffer;
};

template <class KEY, class ENTRY, class HELPER>
class DispatchUtil
{
	public:
		static __forceinline void __cdecl update( Array<ENTRY>& entries, Array<KEY>& keys, const CdBody& cA, const CdBody& cB,
			const CollisionInput& input, ContactMgr* mgr, ConstraintOwner& constraintOwner, HELPER& base );
		static __forceinline void __cdecl fastUpdate( Array<ENTRY>& entries, Array<KEY>& hitList, const CdBody& cA, const CdBody& cB,
			const CollisionInput& input, ContactMgr* mgr, ConstraintOwner& constraintOwner, HELPER& base );
};

template <class KEY, class ENTRY, class HELPER>
void __cdecl DispatchUtil<KEY, ENTRY, HELPER>::update( Array<ENTRY>& entries, Array<KEY>& keys, const CdBody& cA, const CdBody& cB,
	const CollisionInput& input, ContactMgr* mgr, ConstraintOwner& constraintOwner, HELPER& base )
{
	ENTRY* oldEntriesItr = entries.begin();
	ENTRY* oldEntriesEnd = entries.end();

	KEY* newKeysItr = keys.begin();
	KEY* newKeysEnd = keys.end();

	LocalArray<ENTRY> newEntries( keys.getSize() );
	newEntries.setSize( keys.getSize() );

	const ShapeContainer* shapeContainer = base.getShapeContainerB();

	ENTRY* newEntriesItr = newEntries.begin();

	while ( oldEntriesItr != oldEntriesEnd && newKeysItr != newKeysEnd )
	{
		if ( *newKeysItr == oldEntriesItr->getKey() )
		{
			*newEntriesItr = *oldEntriesItr;
			newEntriesItr++;
			oldEntriesItr++;
			newKeysItr++;
			continue;
		}
		if ( *newKeysItr < oldEntriesItr->getKey() )
		{
			const CdBody& bodyA = cA;
			const CdBody& bodyB = cB;
			const CdBody& modifiedB = *base.getBodyB( cB, input, *newKeysItr );
			if ( input.m_filter->isCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *newKeysItr ) )
			{
				newEntriesItr->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
			}
			else
			{
				newEntriesItr->m_collisionAgent = FUN_00990590();
			}
			newEntriesItr->setKey( *newKeysItr );
			newEntriesItr++;
			newKeysItr++;
			continue;
		}
		if ( oldEntriesItr->m_collisionAgent )
		{
			oldEntriesItr->m_collisionAgent->cleanup( constraintOwner );
		}
		oldEntriesItr++;
	}

	while ( oldEntriesItr != oldEntriesEnd )
	{
		if ( oldEntriesItr->m_collisionAgent )
		{
			oldEntriesItr->m_collisionAgent->cleanup( constraintOwner );
		}
		oldEntriesItr++;
	}

	while ( newKeysItr != newKeysEnd )
	{
		const CdBody& bodyA = cA;
		const CdBody& bodyB = cB;
		const CdBody& modifiedB = *base.getBodyB( cB, input, *newKeysItr );
		if ( input.m_filter->isCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *newKeysItr ) )
		{
			newEntriesItr->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
		}
		else
		{
			newEntriesItr->m_collisionAgent = FUN_00990590();
		}
		newEntriesItr->setKey( *newKeysItr );
		newEntriesItr++;
		newKeysItr++;
	}

	entries = newEntries;
}

template <class KEY, class ENTRY, class HELPER>
void __cdecl DispatchUtil<KEY, ENTRY, HELPER>::fastUpdate( Array<ENTRY>& entries, Array<KEY>& hitList, const CdBody& cA, const CdBody& cB,
	const CollisionInput& input, ContactMgr* mgr, ConstraintOwner& constraintOwner, HELPER& base )
{
	{
		ENTRY* itr = entries.begin();
		ENTRY* end = entries.end();
		KEY* lastHit = hitList.begin();
		KEY* endHitList = hitList.end();

		for ( ; itr != end; itr++ )
		{
			if ( lastHit != endHitList && itr->getKey() == *lastHit )
			{
				lastHit++;
				continue;
			}
			for ( lastHit = hitList.begin(); lastHit != endHitList; lastHit++ )
			{
				if ( itr->getKey() == *lastHit )
				{
					lastHit++;
					goto hitFound;
				}
			}
			itr->m_collisionAgent->cleanup( constraintOwner );
			entries.removeAtAndCopy( int( itr - entries.begin() ) );
			itr--;
			end--;
hitFound:
			;
		}
	}

	const ShapeContainer* shapeContainer = base.getShapeContainerB();

	if ( hitList.getSize() != entries.getSize() )
	{
		ENTRY* lastHit = entries.begin();
		ENTRY* end = entries.end();
		KEY* hitItr = hitList.begin();
		KEY* endHitList = hitList.end();

		for ( ; hitItr != endHitList; hitItr++ )
		{
			if ( lastHit != end && lastHit->getKey() == *hitItr )
			{
				lastHit++;
				continue;
			}
			int index = int( hitItr - hitList.begin() );
			lastHit = entries.expandAt( index, 1 );

			const CdBody& bodyA = cA;
			const CdBody& bodyB = cB;
			const CdBody& modifiedB = *base.getBodyB( cB, input, *hitItr );
			if ( input.m_filter->isCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *hitItr ) )
			{
				lastHit->m_collisionAgent = input.m_dispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
			}
			else
			{
				lastHit->m_collisionAgent = FUN_00990590();
			}
			lastHit->m_key = *hitItr;
			end = entries.end();
			lastHit++;
		}
	}
}

enum Result { RES_SUCCESS = 0, RES_FAILURE = 1 };

class BvTreeAgent : public Agent
{
	public:
		void hkpBvTreeAgent_processCollision( const CdBody& bodyA, const CdBody& bodyB, const ProcessInput& input, ProcessOutput& result );
		static __forceinline Result __cdecl calcAabbAndQueryTree( const CdBody& bodyA, const CdBody& bodyB, const Transform& bTa,
			const Vec4& linearTimInfo, const ProcessInput& input, Aabb* cachedAabb, Array<Key>& hitListOut );
	protected:
		__forceinline void prepareCollisionPartnersProcess( const CdBody& bodyA, const CdBody& bodyB, const ProcessInput& input, ConstraintOwner& constraintOwner );
		struct EntryInfo
		{
			Key m_key;
			int m_pad;
			Agent* m_collisionAgent;
			Key& getKey() { return m_key; }
			void setKey( Key& key ) { m_key = key; }
		};
		Array<EntryInfo> m_collisionPartners;   // 0x0c
		Aabb m_cachedAabb;                      // 0x20
};

inline Result __cdecl BvTreeAgent::calcAabbAndQueryTree( const CdBody& bodyA, const CdBody& bodyB, const Transform& bTa,
	const Vec4& linearTimInfo, const ProcessInput& input, Aabb* cachedAabb, Array<Key>& hitListOut )
{
	Aabb aabb;
	{
		const MotionState* msA = bodyA.getMotionState();
		const MotionState* msB = bodyB.getMotionState();

		Vec4 timInfo;
		timInfo.rotInvDir( bodyB.getTransform().getRotation(), linearTimInfo );

		Vec4 aabbExtents;
		if ( input.m_collisionQualityInfo->m_useContinuousPhysics.val() )
		{
			Real secOrdErrA = ( msA->m_deltaAngle.w + msB->m_deltaAngle.w ) * msA->m_objectRadius;
			Real secOrdErrB = msB->m_deltaAngle.w * msB->m_deltaAngle.w * msB->m_objectRadius;
			Real checkEpsilon = input.m_tolerance * 0.5 + ( secOrdErrA + secOrdErrB );
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );

			Vec4 massCenterAinB;
			{
				Vec4 radius4; radius4.setAll3( input.m_tolerance * 0.5 + msA->m_objectRadius + secOrdErrB );
				massCenterAinB.xformInvPos( bodyB.getTransform(), msA->getSweptTransform().m_centerOfMass1 );
				Vec4 maxR; maxR.setAdd4( massCenterAinB, radius4 );
				Vec4 minR; minR.setSub4( massCenterAinB, radius4 );
				aabb.m_min.setMax4( aabb.m_min, minR );
				aabb.m_max.setMin4( aabb.m_max, maxR );
			}
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
			{
				if ( msB->m_deltaAngle.w > 0.0 )
				{
					Vec4 relPos; relPos.setSub4( massCenterAinB, msB->getSweptTransform().m_centerOfMassLocal );
					Vec4 offsetOut; offsetOut.setCross( relPos, msB->m_deltaAngle );
					Real f = input.m_stepInfo.m_deltaTime * msB->getSweptTransform().getInvDeltaTime();
					timInfo.addMul4( f, offsetOut );
				}
				Vec4 zero; zero.setZero4();
				Vec4 minPath; minPath.setMin4( zero, timInfo );
				Vec4 maxPath; maxPath.setMax4( zero, timInfo );
				aabb.m_min.add4( minPath );
				aabb.m_max.add4( maxPath );
			}
		}
		else
		{
			Real checkEpsilon = input.m_tolerance * 0.5;
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
		}

		if ( cachedAabb )
		{
			if ( cachedAabb->contains( aabb ) )
			{
				return RES_FAILURE;
			}
			Vec4 zero; zero.setZero4();
			Vec4 minPath; minPath.setMin4( zero, timInfo );
			Vec4 maxPath; maxPath.setMax4( zero, timInfo );

			Vec4 expand4; expand4.setAll3( input.m_tolerance * 0.5 );
			aabb.m_min.sub4( expand4 );
			aabb.m_max.add4( expand4 );

			Real maxExpand = 0.4f;
			Real framesLookAhead = -2.0f;
			Vec4 minExtentPath; minExtentPath.setMul4( framesLookAhead, maxPath );
			Vec4 maxExtentPath; maxExtentPath.setMul4( framesLookAhead, minPath );
			Vec4 maxExpand4; maxExpand4.setMul4( maxExpand, aabbExtents );
			maxExtentPath.setMin4( maxExtentPath, maxExpand4 );
			Vec4 minExpand4; minExpand4.setNeg4( maxExpand4 );
			minExtentPath.setMax4( minExtentPath, minExpand4 );
			aabb.m_min.add4( minExtentPath );
			aabb.m_max.add4( maxExtentPath );
			*cachedAabb = aabb;
		}
	}
	const Shape* bvB = bodyB.getShape();
	bvB->queryAabb( aabb, hitListOut );
	return RES_SUCCESS;
}

inline void BvTreeAgent::prepareCollisionPartnersProcess( const CdBody& bodyA, const CdBody& bodyB, const ProcessInput& input, ConstraintOwner& constraintOwner )
{
	Result prepareSuccessfull;
	InplaceArray<Key, 128> hitList;
	{
		Transform bTa;
		{
			const Transform& wTb = bodyB.getTransform();
			const Transform& wTa = bodyA.getTransform();
			bTa.FUN_00925300( wTb, wTa );
		}
		Vec4 linearTimInfo;
		{
			const MotionState* msA = bodyA.getMotionState();
			const MotionState* msB = bodyB.getMotionState();
			calcTimInfo( *msA, *msB, input.m_stepInfo.m_deltaTime, linearTimInfo );
		}
		Aabb* cachedAabb = ( DAT_01061950 ) ? &m_cachedAabb : 0;
		prepareSuccessfull = calcAabbAndQueryTree( bodyA, bodyB, bTa, linearTimInfo, input, cachedAabb, hitList );
	}

	if ( prepareSuccessfull != RES_SUCCESS )
	{
		return;
	}

	{
		const Shape* bvB = bodyB.getShape();
		const ShapeContainer* shapeContainer = bvB->getContainer();
		DispatchHelper helper( bodyB );
		helper.m_container = shapeContainer;

		if ( DAT_011693e0 )
		{
			DispatchUtil<Key, EntryInfo, DispatchHelper>::fastUpdate( m_collisionPartners, hitList, bodyA, bodyB, input, m_contactMgr, constraintOwner, helper );
		}
		else
		{
			quickSort( hitList.begin(), hitList.getSize() );
			DispatchUtil<Key, EntryInfo, DispatchHelper>::update( m_collisionPartners, hitList, bodyA, bodyB, input, m_contactMgr, constraintOwner, helper );
		}
	}
}

// pdb: hkpBvTreeAgent::processCollision | hkpBvTreeAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void BvTreeAgent::hkpBvTreeAgent_processCollision( const CdBody& bodyA, const CdBody& bodyB, const ProcessInput& input, ProcessOutput& result )
{
	{
		Monitor& mStream = Monitor::getInstance();
		if ( mStream.memoryAvailable() )
		{
			Monitor::TimerBeginListCommand* h = reinterpret_cast<Monitor::TimerBeginListCommand*>( mStream.getEnd() );
			h->m_commandAndMonitor = "LtBvTree";
			h->m_nameOfFirstSplit = "StQueryTree";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}

	prepareCollisionPartnersProcess( bodyA, bodyB, input, *result.m_constraintOwner.val() );

	EntryInfo* itr = m_collisionPartners.begin();
	EntryInfo* end = m_collisionPartners.end();

	CdBody modifiedBodyB( &bodyB );

	{
		Monitor& mStream = Monitor::getInstance();
		if ( mStream.memoryAvailable() )
		{
			Monitor::TimerCommand* h = reinterpret_cast<Monitor::TimerCommand*>( mStream.getEnd() );
			h->m_commandAndMonitor = "StNarrowPhase";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}
	const Shape* bvB = bodyB.getShape();
	const ShapeContainer* shapeContainer = bvB->getContainer();
	ShapeBuffer shapeBuffer;
	while ( itr != end )
	{
		const Shape* shape = shapeContainer->getChildShape( itr->m_key, shapeBuffer );
		modifiedBodyB.setShape( shape, itr->m_key );

		itr->m_collisionAgent->processCollision( bodyA, modifiedBodyB, input, result );
		itr++;
	}
	{
		Monitor& mStream = Monitor::getInstance();
		if ( mStream.memoryAvailable() )
		{
			Monitor::TimerCommand* h = reinterpret_cast<Monitor::TimerCommand*>( mStream.getEnd() );
			h->m_commandAndMonitor = "lt";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}
}

}   // namespace
}   // namespace f3m_009b8ba0

// @f3 0x009a2680 (community match, verified in this file)
namespace f3m_009a2680 {
typedef float hkReal;
namespace n9a2680 {
namespace hkMath {
    template <class T> inline T min2(T x, T y) { return x < y ? x : y; }
    template <class T> inline T max2(T x, T y) { return x > y ? x : y; }
}
class hkTransform;
class __declspec(align(16)) hkVector4 {
public:
    hkReal x, y, z, w;
    __forceinline void operator=(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    hkReal& operator()(int i) { return (&x)[i]; }
    hkReal operator()(int i) const { return (&x)[i]; }
    void setAll(hkReal a) { x = a; y = a; z = a; w = a; }
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b)
    {
        x = hkMath::min2(a.x, b.x);
        y = hkMath::min2(a.y, b.y);
        z = hkMath::min2(a.z, b.z);
        w = hkMath::min2(a.w, b.w);
    }
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b)
    {
        x = hkMath::max2(a.x, b.x);
        y = hkMath::max2(a.y, b.y);
        z = hkMath::max2(a.z, b.z);
        w = hkMath::max2(a.w, b.w);
    }
    __forceinline void sub4(const hkVector4& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; }
    __forceinline void add4(const hkVector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};
class hkRotation {
public:
    hkVector4 m_col0, m_col1, m_col2;
    void setCols(const hkVector4& c0, const hkVector4& c1, const hkVector4& c2) { m_col0 = c0; m_col1 = c1; m_col2 = c2; }
    hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    hkReal& operator()(int r, int c) { return getColumn(c)(r); }
    hkReal operator()(int r, int c) const { return getColumn(c)(r); }
};
class hkTransform {
public:
    hkRotation m_rotation;
    hkVector4 m_translation;
    hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.setCols(col0, col1, col2);
        m_translation = col3;
    }
    const hkRotation& getRotation() const { return m_rotation; }
    const hkVector4& getTranslation() const { return m_translation; }
    const hkVector4& getColumn(int i) const { return (&m_rotation.m_col0)[i]; }
    hkReal operator()(int r, int c) const { return getColumn(c)(r); }
};
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    const hkVector4& tr = t.getTranslation();
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    this->x = r(0,0)*v0 + r(0,1)*v1 + r(0,2)*v2 + tr(0);
    this->y = r(1,0)*v0 + r(1,1)*v1 + r(1,2)*v2 + tr(1);
    this->z = r(2,0)*v0 + r(2,1)*v1 + r(2,2)*v2 + tr(2);
    this->w = 0;
}
namespace hkVector4Util {
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}
struct hkAabb {
    hkVector4 m_min;
    hkVector4 m_max;
};
class hkpCapsuleShape {
public:
    void* m_vtable;
    int unk04;
    int unk08;
    int unk0c;
    hkReal m_radius;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    const hkVector4* getVertices() const { return &m_vertexA; }
    void FUN_009a2680(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
};
}
using namespace n9a2680;
void hkpCapsuleShape::FUN_009a2680(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    hkVector4 tol4;
    tol4.setAll(tolerance + m_radius);
    hkVector4 obj[2];
    hkVector4Util::transformPoints(localToWorld, getVertices(), 2, obj);
    out.m_min.setMin4(obj[0], obj[1]);
    out.m_min.sub4(tol4);
    out.m_max.setMax4(obj[0], obj[1]);
    out.m_max.add4(tol4);
}
}   // namespace f3m_009a2680

// @f3 0x009a4830 (community match, verified in this file)
namespace f3m_009a4830 {
// FUN_009a4830: one-plane case of the character simplex solver (x87 build of the vector library).
// Removes the plane component of the velocity relative to the surface, applies the extra up/down static
// friction along the horizontal direction, then the dynamic friction blend, and writes surface velocity plus
// the remaining relative velocity. FNV twin: FUN_00d234e0 (SSE there).
// Flags: matches under /MT /O2 /GS- /EHs-c- /Gy (the pack lists /Od /Oy-).
namespace f3m_009a4830
{
typedef float hkReal;
typedef float hkSimdReal;
typedef float hkSimdRealParameter;
extern "C" double sqrt(double);

__forceinline hkReal hkSqrt(hkReal r)
{
    return (hkReal)sqrt(r);
}
__forceinline hkReal hkSqrtInverse(hkReal r)
{
    return 1.0f / hkSqrt(r);
}

__declspec(align(16)) class hkVector4
{
public:
    hkReal x, y, z, w;

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    __forceinline void mul4(hkSimdRealParameter rs)
    {
        x *= rs;
        y *= rs;
        z *= rs;
        w *= rs;
    }
    __forceinline void subMul4(hkSimdRealParameter rs, const hkVector4& a)
    {
        hkReal r = rs;
        x -= r * a.x;
        y -= r * a.y;
        z -= r * a.z;
        w -= r * a.w;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const hkReal nx = v1.y * v2.z - v1.z * v2.y;
        const hkReal ny = v1.z * v2.x - v1.x * v2.z;
        const hkReal nz = v1.x * v2.y - v1.y * v2.x;
        x = nx;
        y = ny;
        z = nz;
        w = 0.0f;
    }
    __forceinline hkSimdReal dot3(const hkVector4& a) const
    {
        return (x * a.x) + (y * a.y) + (z * a.z);
    }
    __forceinline hkSimdReal lengthSquared3() const
    {
        return (x * x) + (y * y) + (z * z);
    }
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};

struct hkpSurfaceConstraintInfo
{
    hkVector4 m_plane;
    hkVector4 m_velocity;
    hkReal m_staticFriction;
    hkReal m_extraUpStaticFriction;
    hkReal m_extraDownStaticFriction;
    hkReal m_dynamicFriction;
    int m_priority;
};

struct hkpSimplexSolverInput
{
    hkVector4 m_position;
    hkVector4 m_velocity;
    hkVector4 m_maxSurfaceVelocity;
    hkVector4 m_upVector;
};

struct SimplexSolverInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    hkpSimplexSolverInput* m_input;
};

// pdb: hkSimplexSolverSolve1d | hkpSimplexSolver.obj | tesv_win, call_dedup, low
static __declspec(noinline) void FUN_009a4830(const SimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci,
                                              const hkVector4& velocityIn, hkVector4& velocityOut)
{
    const hkReal staticFriction = sci.m_staticFriction;
    const hkReal dynamicFriction = sci.m_dynamicFriction;

    // Fake match: this named reference is used for one of the five reads of the plane only (the first
    // subtract-multiply); that choice sets the load order of two products in the cross product below.
    const hkVector4& plane = sci.m_plane;
    hkVector4 relativeVelocity;
    relativeVelocity.setSub4(velocityIn, sci.m_velocity);

    const hkReal planeVel = relativeVelocity.dot3(sci.m_plane);
    const hkReal origVelocity2 = relativeVelocity.lengthSquared3();
    relativeVelocity.subMul4(planeVel, plane);

    const hkReal vp2 = planeVel * planeVel;

    const hkVector4& up = info.m_input->m_upVector;
    hkReal extraStaticFriction = relativeVelocity.dot3(up);
    if (extraStaticFriction > 0)
    {
        extraStaticFriction = sci.m_extraUpStaticFriction;
    }
    else
    {
        extraStaticFriction = sci.m_extraDownStaticFriction;
    }

    if (extraStaticFriction > 0)
    {
        hkVector4 horizontal;
        horizontal.setCross(info.m_input->m_upVector, sci.m_plane);
        hkReal horLen2 = horizontal.lengthSquared3();
        hkReal horVel = 0.0f;
        if (horLen2 > 1.192092896e-07F)
        {
            horizontal.mul4(hkSqrtInverse(horLen2));
            horVel = horizontal.dot3(relativeVelocity);
            hkReal sf2 = staticFriction * staticFriction;
            hkReal horVel2 = horVel * horVel;
            if (sf2 * vp2 >= horVel2)
            {
                relativeVelocity.subMul4(horVel, horizontal);
                horVel = 0.0f;
            }
        }
        hkReal f2 = (extraStaticFriction + staticFriction) * (extraStaticFriction + staticFriction);
        hkReal rest2 = origVelocity2 - horVel * horVel - vp2;
        if (f2 * vp2 >= rest2)
        {
            if (horVel == 0.0f)
            {
                velocityOut = sci.m_velocity;
                return;
            }
            relativeVelocity.setMul4(horVel, horizontal);
        }
    }
    else
    {
        hkReal sf2 = staticFriction * staticFriction;
        if ((sf2 + 1.0) * vp2 >= origVelocity2)
        {
            velocityOut = sci.m_velocity;
            return;
        }
    }

    if (dynamicFriction < 1.0f)
    {
        const hkReal velOut2 = relativeVelocity.lengthSquared3();
        if (velOut2 >= 1.192092896e-07F && origVelocity2 * 0.001f < velOut2)
        {
            hkReal ratio = origVelocity2 / velOut2;
            hkReal root = hkSqrt(ratio);
            hkReal f = dynamicFriction + (1.0f - dynamicFriction) * root;
            relativeVelocity.mul4(f);
            const hkReal p = sci.m_plane.dot3(relativeVelocity);
            relativeVelocity.subMul4(p, sci.m_plane);
        }
    }
    velocityOut.setAdd4(sci.m_velocity, relativeVelocity);
}

SimplexSolverInfo* volatile g_info;
hkpSurfaceConstraintInfo* volatile g_sci;
hkVector4* volatile g_in;
hkVector4* volatile g_out;
// Fake match: the target is an internal-linkage function with a private register convention; this caller keeps it alive.
void FUN_009a4830_caller()
{
    FUN_009a4830(*g_info, *g_sci, *g_in, *g_out);
}
}
}   // namespace f3m_009a4830

// @f3 0x009bede0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_009bede0 {
namespace c_009bede0 {

extern void* (__stdcall* const DAT_00d9b080)(unsigned long);

struct __declspec(align(16)) Vec
{
    float x;
    float y;
    float z;
    float w;
    void setSub4(const Vec& a, const Vec& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    void setMul4(float r, const Vec& a)
    {
        x = r * a.x;
        y = r * a.y;
        z = r * a.z;
        w = r * a.w;
    }
    void addMul4(float r, const Vec& a)
    {
        x += r * a.x;
        y += r * a.y;
        z += r * a.z;
        w += r * a.w;
    }
};

struct Transform
{
    Vec columns[3];
    Vec translation;
    void FUN_00925300(const Transform& a, const Transform& b);
};

struct SweptTransform
{
    Vec centerOfMass0;
    Vec centerOfMass1;
    Vec rotation0;
    Vec rotation1;
    Vec centerOfMassLocal;
    float getInvDeltaTime() const { return centerOfMass1.w; }
};

struct MotionState
{
    Transform transform;
    SweptTransform sweptTransform;
    Vec deltaAngle;
    float objectRadius;
    const Transform& getTransform() const { return transform; }
    const SweptTransform& getSweptTransform() const { return sweptTransform; }
};

__forceinline void calcTimInfo(const MotionState& ms0, const MotionState& ms1, float deltaTime, Vec& timOut)
{
    const SweptTransform& st0 = ms0.getSweptTransform();
    const SweptTransform& st1 = ms1.getSweptTransform();
    Vec diff0;
    // Fake match: a dead store to the w lane before the difference is formed. It emits no code, but the compiler
    // then numbers that lane ahead of the others, which decides the operand order of the w lane of the first
    // scaled copy (factor first, as in the original).
    diff0.w = 0.0f;
    diff0.setSub4(st0.centerOfMass0, st0.centerOfMass1);
    Vec diff1;
    diff1.setSub4(st1.centerOfMass1, st1.centerOfMass0);
    float f0 = deltaTime * st0.getInvDeltaTime();
    float f1 = deltaTime * st1.getInvDeltaTime();
    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut.w = f0 * ms0.deltaAngle.w * ms0.objectRadius + f1 * ms1.deltaAngle.w * ms1.objectRadius;
}

struct ShapeBase
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
};

struct Container
{
    virtual void v00();
};

struct ListShape : ShapeBase, Container
{
    int unk14;
    void* childData;
    int childCount;
    int childCapacity;
    int unk24;
    int unk28;
    int unk2c;
    Vec unk30;
    Vec unk40;
    unsigned int enabledChildren[8];
    const Container* getContainer() const { return this; }
    int isChildEnabled(unsigned int index) const
    {
        const unsigned int mask = 1 << (index & 0x1f);
        if (index < 256)
        {
            return enabledChildren[index >> 5] & mask;
        }
        return 1;
    }
};

struct CdBody
{
    const ListShape* shape;
    unsigned int shapeKey;
    const MotionState* motion;
    const CdBody* parent;
    const MotionState* getMotionState() const { return motion; }
};

struct StepInfo
{
    float startTime;
    float endTime;
    float deltaTime;
    float invDeltaTime;
};

struct ProcessCollisionInput
{
    int unk00[0x14];
    StepInfo stepInfo;
};

struct ProcessInput
{
    const CdBody* bodyA;
    const CdBody* bodyB;
    const ProcessCollisionInput* input;
    void* contactMgr;
    Transform aTb;
    Vec unk50;
    Vec linearTimInfo;
};

struct ThreadMemory
{
    struct Stack
    {
        char* current;
        Stack* prev;
        char* base;
        char* end;
    };
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* onStackOverflow(int numBytes);
    virtual void onStackUnderflow(void* p);
    int unk04[7];
    Stack stack;
    static ThreadMemory& getInstance() { return *(ThreadMemory*)DAT_00d9b080(DAT_010f3170); }
    void* allocateStack(int numBytes)
    {
        Stack& s = stack;
        void* current = s.current;
        char* next = (char*)current + numBytes;
        if (next <= s.end)
        {
            s.current = next;
        }
        else
        {
            current = onStackOverflow(numBytes);
        }
        return current;
    }
    void deallocateStack(void* p)
    {
        Stack& s = stack;
        s.current = (char*)p;
        if (p == s.base)
        {
            onStackUnderflow(p);
        }
    }
};

template <class T> struct LocalBuffer
{
    T* data;
    LocalBuffer(int n) { data = (T*)ThreadMemory::getInstance().allocateStack((n * (int)sizeof(T) + 16) & ~15); }
    ~LocalBuffer() { ThreadMemory::getInstance().deallocateStack(data); }
    T& operator[](int i) { return data[i]; }
    T* begin() { return data; }
};

struct Track
{
    int unk00;
};

void __cdecl FUN_00a2b910(Track& track, int unk, ProcessInput& in, const Container* container, const unsigned int* hitList, void* result);

struct ListAgent
{
    virtual void v00();
    int unk04;
    void* contactMgr;
    int unk0c;
    Track agentTrack;
    void hkpListAgent_processCollision(const CdBody& bodyA, const CdBody& bodyB, const ProcessCollisionInput& input, void* result);
};

// pdb: hkpListAgent::processCollision | hkpListAgent.obj | fnv360_0822_retail, objrun_prop + skyrim(objrun_prop), high
void ListAgent::hkpListAgent_processCollision(const CdBody& bodyA, const CdBody& bodyB, const ProcessCollisionInput& input, void* result)
{
    const ListShape* lShape = bodyB.shape;
    ProcessInput in;
    {
        in.bodyA = &bodyA;
        in.bodyB = &bodyB;
        in.contactMgr = contactMgr;
        in.input = &input;
        const MotionState* msA = bodyA.getMotionState();
        const MotionState* msB = bodyB.getMotionState();
        calcTimInfo(*msA, *msB, input.stepInfo.deltaTime, in.linearTimInfo);
        in.aTb.FUN_00925300(msA->getTransform(), msB->getTransform());
    }
    int size = lShape->childCount;
    LocalBuffer<unsigned int> hitList(size + 1);
    int d = 0;
    for (int i = 0; i < size; i++)
    {
        if (lShape->isChildEnabled(i))
        {
            hitList[d++] = (unsigned int)i;
        }
    }
    hitList[d] = 0xffffffff;
    FUN_00a2b910(agentTrack, 0, in, lShape->getContainer(), hitList.begin(), result);
}

}
}   // namespace f3m_009bede0

// @f3 0x009a3110 (community match, verified in this file)
#include <math.h>
namespace f3m_009a3110 {
// 0x009a3110: display capsule, build geometry (x87 build of the visualisation library).
// The body is the library's capsule geometry utility inlined into the member: start, end, radius and the two sample
// counts are read from this, the vertices go through a local array and the finished geometry is stored at the end.
// Matches under /MT /O2 /GS- /EHs-c- /Gy (the pack lists /Od /Oy- /GS /EHsc).
// Fake-match constructs (each marked where it stands):
//   - five dead int locals in hkArray::operator= ahead of the element copy; they only shift the compiler's symbol
//     numbering;
//   - hkVector4::mul4b, a second scale helper whose factor arrives as a double, used for one normalise;
//   - the inlined utility declares its parameters in the reverse of the library's order.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace N9a3110 {

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

extern unsigned long DAT_010f3170;   // thread memory thread slot

struct hkQuadReal
{
    hkReal x, y, z, w;
};
extern const hkQuadReal DAT_00e375d0;   // (0, 0, 1, 0)

namespace hkMath
{
    __forceinline hkReal sqrt(hkReal r) { return ::sqrtf(r); }
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return ::fabsf(r); }
}

class hkTransform;
class hkQuaternion;

class __declspec(align(16)) hkVector4
{
    public:
        __forceinline hkVector4() {}
        __forceinline hkVector4(const hkVector4& v) { *this = v; }
        __forceinline void operator=(const hkVector4& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }
        __forceinline hkQuadReal& getQuad() { return *reinterpret_cast<hkQuadReal*>(this); }
        __forceinline hkReal& operator()(int i) { return (&x)[i]; }
        __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
        __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d = 0.0f)
        {
            x = a;
            y = b;
            z = c;
            w = d;
        }
        __forceinline void setZero4()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            w = 0.0f;
        }
        __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
        {
            x = a.x + b.x;
            y = a.y + b.y;
            z = a.z + b.z;
            w = a.w + b.w;
        }
        __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
        {
            x = a.x - b.x;
            y = a.y - b.y;
            z = a.z - b.z;
            w = a.w - b.w;
        }
        // Fake match: same scale as mul4, but the factor arrives as a double and is narrowed to a float local. Used for
        // the second normalise only: there the x lane must be loaded before the factor while y and z multiply the
        // factor by the lane from memory; mul4 gives factor-first on all lanes once the dead locals below are present.
        __forceinline void mul4b(double rs)
        {
            hkReal s = (hkReal)rs;
            x *= s;
            y *= s;
            z *= s;
            w *= s;
        }
        __forceinline void mul4(hkSimdRealParameter rs)
        {
            hkReal s = rs;
            x *= s;
            y *= s;
            z *= s;
            w *= s;
        }
        __forceinline void setMul4(hkSimdRealParameter rs, const hkVector4& a)
        {
            hkReal r = rs;
            x = r * a.x;
            y = r * a.y;
            z = r * a.z;
            w = r * a.w;
        }
        __forceinline void addMul4(hkSimdRealParameter rs, const hkVector4& a)
        {
            hkReal r = rs;
            x += r * a.x;
            y += r * a.y;
            z += r * a.z;
            w += r * a.w;
        }
        __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter rs)
        {
            hkReal r = rs;
            x = a.x + r * b.x;
            y = a.y + r * b.y;
            z = a.z + r * b.z;
            w = a.w + r * b.w;
        }
        __forceinline hkSimdReal dot3(const hkVector4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
        __forceinline hkSimdReal lengthSquared3() const { return (x * x) + (y * y) + (z * z); }
        __forceinline hkSimdReal length3() const { return hkMath::sqrt((x * x) + (y * y) + (z * z)); }
        __forceinline hkSimdReal lengthInverse3() const
        {
            hkReal l2 = (x * x) + (y * y) + (z * z);
            return l2 ? hkMath::sqrtInverse(l2) : 0.0f;
        }
        __forceinline void normalize3() { this->mul4(this->lengthInverse3()); }
        __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
        {
            const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
            const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
            const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
            set(nx, ny, nz, 0.0f);
        }
        __forceinline void setRotatedDir(const hkQuaternion& quat, const hkVector4& direction);
        void hkVector4_setTransformedPos(const hkTransform& t, const hkVector4& b);
        __forceinline void setTransformedPos(const hkTransform& t, const hkVector4& b) { hkVector4_setTransformedPos(t, b); }

        hkReal x;
        hkReal y;
        hkReal z;
        hkReal w;
};

class hkQuaternion
{
    public:
        __forceinline hkQuaternion() {}
        void FUN_009240d0(const hkVector4& axis, hkReal angle);
        __forceinline void setAxisAngle(const hkVector4& axis, hkReal angle) { FUN_009240d0(axis, angle); }
        __forceinline const hkVector4& getImag() const { return m_vec; }
        __forceinline hkReal getReal() const { return m_vec(3); }

        hkVector4 m_vec;
};

__forceinline void hkVector4::setRotatedDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkReal qreal = quat.m_vec(3);
    hkReal q2minus1 = qreal * qreal - 0.5f;

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkReal imagDotDir = quat.getImag().dot3(direction);

    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

class hkRotation
{
    public:
        __forceinline hkRotation() {}
        __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
        __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
        __forceinline void setIdentity()
        {
            m_col0.setZero4();
            m_col1.setZero4();
            m_col2.setZero4();
            m_col0(0) = 1.0f;
            m_col1(1) = 1.0f;
            m_col2(2) = 1.0f;
        }

        hkVector4 m_col0;
        hkVector4 m_col1;
        hkVector4 m_col2;
};

class hkTransform
{
    public:
        __forceinline hkTransform() {}
        __forceinline void setRotation(const hkRotation& rotation)
        {
            m_rotation.m_col0 = rotation.m_col0;
            m_rotation.m_col1 = rotation.m_col1;
            m_rotation.m_col2 = rotation.m_col2;
        }
        __forceinline void setTranslation(const hkVector4& t) { m_translation = t; }
        __forceinline void setIdentity()
        {
            m_rotation.setIdentity();
            m_translation.setZero4();
        }

        hkRotation m_rotation;
        hkVector4 m_translation;
};

// ---- memory ----

class hkThreadMemory
{
    public:
        virtual void v00();

        struct FreeElem
        {
            FreeElem* m_next;
        };
        struct FreeList
        {
            FreeElem* m_head;
            int m_numElem;
            __forceinline void* get()
            {
                FreeElem* p = m_head;
                if (p)
                {
                    m_numElem--;
                    m_head = p->m_next;
                }
                return p;
            }
        };

        void* FUN_008f6d30(int numBytes, int cls);
        void FUN_008f6d90(void* p, int numBytes, int cls);
        void* FUN_008f6800(int row, int cls);

        static __forceinline hkThreadMemory& getInstance()
        {
            return *static_cast<hkThreadMemory*>(TlsGetValue(DAT_010f3170));
        }
        __forceinline void* allocateRow3(int cls)
        {
            void* p = m_free_list[3].get();
            if (p)
            {
                return p;
            }
            return FUN_008f6800(3, cls);
        }

        int m_unk04;
        int m_unk08;
        int m_unk0c;
        int m_unk10;
        int m_unk14;
        int m_unk18;
        int m_unk1c;
        char* m_stackCurrent;   // 0x20
        char* m_stackPrev;      // 0x24
        char* m_stackBase;      // 0x28
        char* m_stackEnd;       // 0x2c
        int m_unk30;
        int m_unk34;
        FreeList m_free_list[4];   // 0x38
};

void __cdecl FUN_00901e90(void* array, int numElem, int sizeElem);   // array reserve
void __cdecl FUN_00901f10(void* array, int sizeElem);                // array reserve more

template <typename T>
class hkArray
{
    public:
        enum
        {
            CAPACITY_MASK = int(0x3FFFFFFF),
            FLAG_MASK = int(0xC0000000),
            DONT_DEALLOCATE_FLAG = int(0x80000000),
            LOCKED_FLAG = int(0x40000000)
        };
        __forceinline hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}
        __forceinline ~hkArray()
        {
            if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
            {
                hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
            }
        }
        __forceinline int getSize() const { return m_size; }
        __forceinline int getCapacity() const { return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK)); }
        __forceinline T& operator[](int i) { return m_data[i]; }
        __forceinline void reserve(int n)
        {
            if (getCapacity() < n)
            {
                FUN_00901e90(this, n, sizeof(T));
            }
        }
        __forceinline void pushBack(const T& e)
        {
            if (m_size == getCapacity())
            {
                FUN_00901f10(this, sizeof(T));
            }
            m_data[m_size++] = e;
        }
        static __forceinline void __cdecl copy(T* dst, const T* src, int n)
        {
            for (int i = 0; i < n; ++i)
            {
                dst[i] = src[i];
            }
        }
        __forceinline hkArray& operator=(const hkArray& a)
        {
            // Fake match: five dead locals. Together with the four size accessor calls they move the symbol numbers of
            // the two copy pointers above the scaled index of the copy remainder loop, which makes the index the base
            // register of its two address computations (0x1296 and 0x129a). Four are not enough, five to six match.
            int pad0 = 0;
            int pad1 = 0;
            int pad2 = 0;
            int pad3 = 0;
            int pad4 = 0;
            if (getCapacity() < a.getSize())
            {
                if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
                {
                    hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
                }
                m_data = static_cast<T*>(hkThreadMemory::getInstance().FUN_008f6d30(a.m_size * sizeof(T), 0x17));
                m_capacityAndFlags = (m_capacityAndFlags & LOCKED_FLAG) | a.getSize();
            }
            m_size = a.getSize();
            copy(m_data, a.m_data, a.getSize());
            return *this;
        }

        T* m_data;
        int m_size;
        int m_capacityAndFlags;
};

struct hkGeometry
{
    struct Triangle
    {
        int m_a;
        int m_b;
        int m_c;
    };

    __forceinline hkGeometry() {}
    __forceinline void* operator new(size_t) { return hkThreadMemory::getInstance().allocateRow3(0x27); }
    __forceinline void operator delete(void*) {}

    hkArray<hkVector4> m_vertices;
    hkArray<Triangle> m_triangles;
};

class hkReferencedObject
{
    public:
        virtual ~hkReferencedObject();

        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
};

class hkDisplayGeometry : public hkReferencedObject
{
    public:
        hkGeometry* m_geometry;    // 0x08
        hkTransform m_transform;   // 0x10
        int m_type;                // 0x50
};

class hkDisplayCapsule : public hkDisplayGeometry
{
    public:
        void FUN_009a3110();

        hkVector4 m_top;             // 0x60
        hkVector4 m_bottom;          // 0x70
        hkReal m_radius;             // 0x80
        int m_numSides;              // 0x84
        int m_numHeightSegments;     // 0x88
};

// Fake match: the parameters are declared in the reverse of the library's order (start, end, radius, heightSamples,
// thetaSamples, transform, geometryOut). The order of the two point references decides which operand each lane of the
// centre sum (start + end) loads first; reversed, all four lanes load end first as the original does.
static __forceinline void createCapsuleGeometry(hkGeometry*& geometryOut, const hkTransform& transform, int thetaSamples, hkReal radius, int heightSamples, const hkVector4& end, const hkVector4& start)
{
    const int phiSamples = thetaSamples >> 1;

    hkArray<hkVector4> verts;

    hkTransform capsuleToLocal;

    hkVector4 axis;
    axis.setSub4(end, start);
    hkReal height = axis.length3();
    if (height > 0.0f)
    {
        axis.normalize3();

        hkVector4 canonicalZ;
        canonicalZ.getQuad() = DAT_00e375d0;
        if (hkMath::fabs(axis.dot3(canonicalZ)) < 1.0f - 1e-5f)
        {
            hkRotation rotation;
            hkVector4& col0 = rotation.getColumn(0);
            hkVector4& col1 = rotation.getColumn(1);
            hkVector4& col2 = rotation.getColumn(2);

            col2 = axis;
            col1.setCross(col2, canonicalZ);
            col1.mul4b(col1.lengthInverse3());   // Fake match: see mul4b (a plain normalize3 in the source)
            col0.setCross(col1, col2);
            capsuleToLocal.setRotation(rotation);
        }
        else
        {
            capsuleToLocal.setIdentity();
        }
    }
    else
    {
        capsuleToLocal.setIdentity();
    }

    {
        hkVector4 toCentre;
        toCentre.setAdd4(start, end);
        toCentre.mul4(0.5f);
        capsuleToLocal.setTranslation(toCentre);
    }

    int i, j;

    hkVector4 vert;

    hkVector4 bottomInGeom;
    bottomInGeom.set(0.0f, 0.0f, -height * 0.5f);
    hkVector4 topInGeom;
    topInGeom.set(0.0f, 0.0f, height * 0.5f);
    hkVector4 axisInGeom;
    axisInGeom.setSub4(topInGeom, bottomInGeom);
    hkVector4 axisNInGeom;
    axisNInGeom.set(0.0f, 0.0f, 1.0f);
    hkVector4 normalInGeom;
    normalInGeom.set(1.0f, 0.0f, 0.0f);
    hkVector4 binormalInGeom;
    binormalInGeom.set(0.0f, -1.0f, 0.0f);

    int numVerts = 2 + thetaSamples * (heightSamples + 2 * phiSamples - 1);
    verts.reserve(numVerts);

    vert.set(0.0f, 0.0f, height * 0.5f + radius);
    vert.setTransformedPos(capsuleToLocal, vert);
    verts.pushBack(vert);

    for (i = phiSamples - 1; i >= 0; i--)
    {
        hkQuaternion qTop;
        qTop.setAxisAngle(binormalInGeom, hkReal(i) / phiSamples * 3.14159265358979f * .5f);
        hkVector4 topElevation;
        topElevation.setRotatedDir(qTop, normalInGeom);

        for (j = 0; j < thetaSamples; j++)
        {
            hkQuaternion rotationTop;
            rotationTop.setAxisAngle(axisNInGeom, hkReal(j) / thetaSamples * 3.14159265358979f * 2);
            hkVector4 topDirection;
            topDirection.setRotatedDir(rotationTop, topElevation);

            hkReal dist = radius;
            vert.setAddMul4(topInGeom, topDirection, dist);
            vert.setTransformedPos(capsuleToLocal, vert);

            verts.pushBack(vert);
        }
    }

    for (j = heightSamples - 1; j > 0; j--)
    {
        for (i = 0; i < thetaSamples; i++)
        {
            hkQuaternion q;
            q.setAxisAngle(axisNInGeom, hkReal(i) / thetaSamples * 3.14159265358979f * 2);
            hkVector4 direction;
            direction.setRotatedDir(q, normalInGeom);

            hkVector4 s;
            s.setAddMul4(bottomInGeom, axisInGeom, hkReal(j) / hkReal(heightSamples));

            hkReal dist = radius;

            vert.setAddMul4(s, direction, dist);
            vert.setTransformedPos(capsuleToLocal, vert);

            verts.pushBack(vert);
        }
    }

    for (i = 0; i < phiSamples; i++)
    {
        hkQuaternion qBottom;
        qBottom.setAxisAngle(binormalInGeom, -hkReal(i) / phiSamples * 3.14159265358979f * .5f);
        hkVector4 bottomElevation;
        bottomElevation.setRotatedDir(qBottom, normalInGeom);

        for (j = 0; j < thetaSamples; j++)
        {
            hkQuaternion rotationBottom;
            rotationBottom.setAxisAngle(axisNInGeom, hkReal(j) / thetaSamples * 3.14159265358979f * 2);
            hkVector4 bottomDirection;
            bottomDirection.setRotatedDir(rotationBottom, bottomElevation);

            hkReal dist = radius;
            vert.setAddMul4(bottomInGeom, bottomDirection, dist);
            vert.setTransformedPos(capsuleToLocal, vert);
            verts.pushBack(vert);
        }
    }

    vert.set(0.0f, 0.0f, -(height * 0.5f + radius));
    vert.setTransformedPos(capsuleToLocal, vert);
    verts.pushBack(vert);

    hkGeometry* geom = new hkGeometry;
    geom->m_vertices = verts;

    {
        for (int vi = 0; vi < geom->m_vertices.getSize(); ++vi)
        {
            geom->m_vertices[vi].setTransformedPos(transform, geom->m_vertices[vi]);
        }
    }

    hkGeometry::Triangle tr;
    int currentBaseIndex = 1;
    for (i = 0; i < thetaSamples; i++)
    {
        tr.m_a = 0;
        tr.m_b = currentBaseIndex + i;
        tr.m_c = currentBaseIndex + (i + 1) % (thetaSamples);

        geom->m_triangles.pushBack(tr);
    }

    for (j = 0; j < 2 * (phiSamples - 1) + heightSamples; j++)
    {
        for (i = 0; i < thetaSamples; i++)
        {
            tr.m_a = currentBaseIndex + i;
            tr.m_b = currentBaseIndex + thetaSamples + i;
            tr.m_c = currentBaseIndex + thetaSamples + (i + 1) % (thetaSamples);

            geom->m_triangles.pushBack(tr);

            tr.m_b = currentBaseIndex + i;
            tr.m_a = currentBaseIndex + (i + 1) % (thetaSamples);
            tr.m_c = currentBaseIndex + thetaSamples + (i + 1) % (thetaSamples);

            geom->m_triangles.pushBack(tr);
        }
        currentBaseIndex += thetaSamples;
    }

    for (i = 0; i < thetaSamples; i++)
    {
        tr.m_b = currentBaseIndex + i;
        tr.m_a = currentBaseIndex + (i + 1) % (thetaSamples);
        tr.m_c = currentBaseIndex + thetaSamples;

        geom->m_triangles.pushBack(tr);
    }

    geometryOut = geom;
}

void hkDisplayCapsule::FUN_009a3110()
{
    createCapsuleGeometry(m_geometry, m_transform, m_numSides, m_radius, m_numHeightSegments, m_bottom, m_top);
}

}
}   // namespace f3m_009a3110

// @f3 0x009ac100 (community match, verified in this file)
#include <math.h>
namespace f3m_009ac100 {
// 0x009ac100: rigid motion utility, apply accumulators (x87 build of the physics library).
// Writes the velocity accumulators of the solver back into the motions, steps each motion state, clips the
// velocities and updates the deactivation counters. Returns the smallest inactive-frame count.
// Port of the structure of the FNV twin (0x00d29bf0) with scalar (FPU) vector helpers.
// Matches under /MT /O2 /GS- /EHs-c- /Gy (the pack lists /Od /Oy-, which cannot give this function).
// Three fake-match constructs, each marked where it stands.

namespace N9ac100 {

typedef float Real;
typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef unsigned int UInt32;

extern float DAT_00e35180[256];   // 8-bit float decode table

namespace Math {
inline Real sqrt(Real r) { return sqrtf(r); }
inline Real sqrtInverse(Real r) { Real s = Math::sqrt(r); return 1.0f / s; }
inline Real fabs(Real r) { return fabsf(r); }
inline Real min2(Real x, Real y) { return x < y ? x : y; }
inline Real max2(Real x, Real y) { return x > y ? x : y; }
inline int min2(int x, int y) { return x < y ? x : y; }
inline int max2(int x, int y) { return x > y ? x : y; }
}

template <class T>
class Pad
{
  public:
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return val(); }

  private:
    T m_storage;
};

class Comparison
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };
    __forceinline int getMask() const { return m_mask; }
    int m_mask;
};

class Rotation;
class Quaternion;

class Vec4
{
  public:
    __forceinline Vec4() {}
    __forceinline void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline Real& operator()(int i) { return (&x)[i]; }
    __forceinline const Real& operator()(int i) const { return (&x)[i]; }

    void hkVector4_setRotatedDir(const Rotation& r, const Vec4& v);   // setRotatedDir, out of line
    void FUN_00477880(const Rotation& r, const Vec4& v);   // setRotatedInverseDir, out of line
    __forceinline void _setRotatedDir(const Rotation& r, const Vec4& v);

    __forceinline void setReciprocal4(const Vec4& v) { x = 1.0f / v.x; y = 1.0f / v.y; z = 1.0f / v.z; w = 1.0f / v.w; }
    __forceinline void mul4(const Vec4& v) { (*this)(0) *= v(0); (*this)(1) *= v(1); (*this)(2) *= v(2); (*this)(3) *= v(3); }
    __forceinline void mul4(Real rs) { Real s = rs; x *= s; y *= s; z *= s; w *= s; }
    __forceinline void setMul4(Real r, const Vec4& v) { x = r * v.x; y = r * v.y; z = r * v.z; w = r * v.w; }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void addMul4(Real r, const Vec4& v) { x += r * v.x; y += r * v.y; z += r * v.z; w += r * v.w; }
    __forceinline void setAbs4(const Vec4& v) { x = Math::fabs(v.x); y = Math::fabs(v.y); z = Math::fabs(v.z); w = Math::fabs(v.w); }
    __forceinline Real lengthSquared3() const { return x * x + y * y + z * z; }
    // Fake match: the same length squared read through a lane pointer held in a local. Used for the angular velocity in the
    // clip only: it makes the second lane the first product there and settles the lane order of the scale after it.
    __forceinline Real lengthSquared3p() const { const Real* p = &x; return p[0] * p[0] + p[1] * p[1] + p[2] * p[2]; }
    __forceinline Real dot4(const Vec4& a) const { return x * a.x + y * a.y + z * a.z + w * a.w; }
    __forceinline void zeroElement(int i) { (*this)(i) = 0.0f; }
    __forceinline Comparison compareLessThan4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x < v.x) ? 8 : 0;
        int my = (y < v.y) ? 4 : 0;
        int mz = (z < v.z) ? 2 : 0;
        int mw = (w < v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }
    __forceinline Comparison compareEqual4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x == v.x) ? 8 : 0;
        int my = (y == v.y) ? 4 : 0;
        int mz = (z == v.z) ? 2 : 0;
        int mw = (w == v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }

    __declspec(align(16)) Real x;
    Real y;
    Real z;
    Real w;
};

extern Vec4 DAT_01061120;   // largest velocity the integrator accepts
extern Vec4 DAT_010f3370;   // identity transform, first column

class Rotation
{
  public:
    __forceinline const Vec4& getColumn(int i) const { return (&m_col0)[i]; }
    void hkRotation_set(const Quaternion& q);   // set from a quaternion

    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
};

class Transform
{
  public:
    __forceinline Rotation& getRotation() { return m_rotation; }
    __forceinline const Rotation& getRotation() const { return m_rotation; }
    __forceinline Vec4& getTranslation() { return m_translation; }
    __forceinline void setRotation(const Quaternion& q) { m_rotation.hkRotation_set(q); }
    __forceinline static const Vec4& getIdentityColumn0() { return DAT_010f3370; }

    Rotation m_rotation;
    Vec4 m_translation;
};

__forceinline void Vec4::_setRotatedDir(const Rotation& r, const Vec4& v)
{
    Real v0 = v.x;
    Real v1 = v.y;
    Real v2 = v.z;
    x = r.m_col0.x * v0 + r.m_col1.x * v1 + r.m_col2.x * v2;
    y = r.m_col0.y * v0 + r.m_col1.y * v1 + r.m_col2.y * v2;
    z = r.m_col0.z * v0 + r.m_col1.z * v1 + r.m_col2.z * v2;
    w = 0.0f;
}

class Quaternion
{
  public:
    void FUN_008d3290(const Quaternion& r, const Quaternion& q);   // setMul
    void FUN_004e5c20();                                           // normalize

    Vec4 m_vec;
};

UInt32 __cdecl hkVector4Util_packQuaternionIntoInt32(const Vec4& q);   // pack a quaternion into 32 bits

class SweptTransform
{
  public:
    Vec4 m_centerOfMass0;      // w: start time
    Vec4 m_centerOfMass1;      // w: 1 / delta time
    Quaternion m_rotation0;
    Quaternion m_rotation1;
    Vec4 m_centerOfMassLocal;
};

class UFloat8
{
  public:
    __forceinline operator float() const { return DAT_00e35180[m_value]; }
    UInt8 m_value;
};

class MotionState
{
  public:
    __forceinline Transform& getTransform() { return m_transform; }
    __forceinline const Transform& getTransform() const { return m_transform; }
    __forceinline SweptTransform& getSweptTransform() { return m_sweptTransform; }
    __forceinline const SweptTransform& getSweptTransform() const { return m_sweptTransform; }

    Transform m_transform;
    SweptTransform m_sweptTransform;
    Vec4 m_deltaAngle;
    Real m_objectRadius;
    Real m_linearDamping;
    Real m_angularDamping;
    UFloat8 m_maxLinearVelocity;
    UFloat8 m_maxAngularVelocity;
    UInt8 m_deactivationClass;
};

class Motion
{
  public:
    enum MotionType
    {
        MOTION_INVALID,
        MOTION_DYNAMIC,
        MOTION_SPHERE_INERTIA,
        MOTION_STABILIZED_SPHERE_INERTIA,
        MOTION_BOX_INERTIA,
        MOTION_STABILIZED_BOX_INERTIA,
        MOTION_KEYFRAMED,
        MOTION_FIXED,
        MOTION_THIN_BOX_INERTIA,
        MOTION_CHARACTER
    };
    __forceinline const Transform& getTransform() const { return m_motionState.getTransform(); }
    __forceinline int getNumInactiveFrames(int select) { return m_deactivationNumInactiveFrames[select] & 0x7f; }
    __forceinline void incrementNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        int newdc = dc + 1 - (dc >> 6);
        dc = newdc | (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }
    __forceinline void zeroNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        dc = (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }

    void* m_vtable;
    UInt16 m_memSizeAndFlags;
    short m_referenceCount;
    UInt8 m_type;
    UInt8 m_deactivationIntegrateCounter;
    UInt16 m_deactivationNumInactiveFrames[2];
    MotionState m_motionState;
    Vec4 m_inertiaAndMassInv;
    Vec4 m_linearVelocity;
    Vec4 m_angularVelocity;
    Vec4 m_deactivationRefPosition[2];
    UInt32 m_deactivationRefOrientation[2];
};

class ThinBoxMotion : public Motion
{
};

class Accumulator
{
  public:
    __forceinline const Vec4& getSumLinearVel() const { return getScratch0(); }
    __forceinline const Vec4& getSumAngularVel() const { return getScratch1(); }
    __forceinline const Vec4& getScratch0() const { return m_scratch0; }
    __forceinline const Vec4& getScratch1() const { return m_scratch1; }

    UInt8 m_type;
    UInt8 m_context;
    UInt32 m_deactivationClass;
    Real m_gravityFactor;
    Vec4 m_linearVel;
    Vec4 m_angularVel;
    Vec4 m_invMasses;
    Vec4 m_scratch0;
    Vec4 m_scratch1;
    Vec4 m_scratch2;
    Vec4 m_scratch3;
};

class StepInfo
{
  public:
    Pad<Real> m_startTime;
    Pad<Real> m_endTime;
    Pad<Real> m_deltaTime;
    Pad<Real> m_invDeltaTime;
};

class Half
{
  public:
    __forceinline operator Real() const
    {
        union { int i; float f; } u;
        u.i = m_value << 16;
        return u.f;
    }
    short m_value;
};

class SolverInfo
{
  public:
    struct DeactivationInfo
    {
        Real m_linearVelocityThresholdInv;
        Real m_angularVelocityThresholdInv;
        Real m_slowObjectVelocityMultiplier;
        Real m_relativeSleepVelocityThreshold;
        Real m_maxDistSqrd[2];
        Half m_maxRotSqrd[2];
    };
    __declspec(align(16)) Real m_one;
    Real m_tau;
    Real m_damping;
    Real m_frictionTau;
    Vec4 m_globalAccelerationPerSubStep;
    Vec4 m_globalAccelerationPerStep;
    Vec4 m_integrateVelocityFactor;
    Vec4 m_invIntegrateVelocityFactor;
    Real m_dampDivTau;
    Real m_tauDivDamp;
    Real m_dampDivFrictionTau;
    Real m_frictionTauDivDamp;
    Real m_contactRestingVelocity;
    DeactivationInfo m_deactivationInfo[6];
    Real m_deltaTime;
    Real m_invDeltaTime;
    int m_numSteps;
    int m_numMicroSteps;
    Real m_invNumMicroSteps;
    Real m_invNumSteps;
    bool m_forceCoherentConstraintOrderingInSolver;
    UInt8 m_deactivationNumInactiveFramesSelectFlag[2];
    UInt8 m_deactivationIntegrateCounter;
};

template <typename TYPE> __forceinline TYPE* addByteOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

__forceinline void unPackInt32IntoQuaternion(UInt32 ivalue, Vec4& qout)
{
    int a = ivalue;
    int b = ivalue >> 8;
    int c = ivalue >> 16;
    int d = ivalue >> 24;
    a &= 0xff;
    b &= 0xff;
    c &= 0xff;
    a -= 0x80;
    b -= 0x80;
    c -= 0x80;
    d -= 0x80;
    const Real f = 1.1f / 128.0f;
    qout(0) = f * a;
    qout(1) = f * b;
    qout(2) = f * c;
    qout(3) = f * d;
}

__forceinline void calcTransAtT1(const SweptTransform& sweptTrans, Transform& transformOut)
{
    const Quaternion& qt = sweptTrans.m_rotation1;
    transformOut.setRotation(qt);
    Vec4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

__forceinline void clipVelocities(const MotionState& motionState, Vec4& linearVelocity, Vec4& angularVelocity)
{
    Real linVelSq = linearVelocity.lengthSquared3();
    Real angVelSq = angularVelocity.lengthSquared3p();
    const Real maxLinear = motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity;
    const Real maxAngular = motionState.m_maxAngularVelocity * motionState.m_maxAngularVelocity;
    if ((linVelSq > maxLinear) || (linVelSq != linVelSq))
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
        if (linVelSq != linVelSq)
        {
            linearVelocity = Transform::getIdentityColumn0();
        }
    }
    if ((angVelSq > maxAngular) || (angVelSq != angVelSq))
    {
        Real f = motionState.m_maxAngularVelocity * Math::sqrtInverse(angVelSq);
        angularVelocity.mul4(f);
        if (angVelSq != angVelSq)
        {
            angularVelocity = Transform::getIdentityColumn0();
        }
    }
}

__forceinline void stepMotionState(const StepInfo& info, Vec4& linearVelocity, Vec4& angularVelocity,
                                   MotionState& motionState)
{
    {
        // replace NaN or huge velocities
        Vec4 absLin;
        absLin.setAbs4(linearVelocity);
        Vec4 absAng;
        absAng.setAbs4(angularVelocity);

        int mask = absLin.compareLessThan4(DAT_01061120).getMask() & absAng.compareLessThan4(DAT_01061120).getMask();
        mask &= linearVelocity.compareEqual4(linearVelocity).getMask() &
                angularVelocity.compareEqual4(angularVelocity).getMask();
        if ((mask & Comparison::MASK_XYZ) != Comparison::MASK_XYZ)
        {
            linearVelocity = Transform::getIdentityColumn0();
            angularVelocity = Transform::getIdentityColumn0();
        }
    }

    motionState.getSweptTransform().m_centerOfMass0 = motionState.getSweptTransform().m_centerOfMass1;
    motionState.getSweptTransform().m_centerOfMass0(3) = info.m_startTime;

    Real linVelSq = linearVelocity.lengthSquared3();
    if (linVelSq > motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity)
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
    }

    motionState.getSweptTransform().m_centerOfMass1.addMul4(info.m_deltaTime, linearVelocity);
    motionState.getSweptTransform().m_centerOfMass1(3) = info.m_invDeltaTime;

    Quaternion newRotation = motionState.getSweptTransform().m_rotation1;
    motionState.getSweptTransform().m_rotation0 = newRotation;

    Real angle;
    {
        Quaternion rotationRadians;
        rotationRadians.m_vec.setMul4(info.m_deltaTime * 0.5f, angularVelocity);
        const Real pi = 3.14159265358979f;
        Real numHalfRotations2 = rotationRadians.m_vec.lengthSquared3() * (4.0f / (pi * pi));

        const Real a = 0.822948f;
        const Real b = 0.130529f;
        const Real c = 0.044408f;

        const Real maxAnglePerStep = Math::min2(0.9f, info.m_deltaTime.val() * motionState.m_maxAngularVelocity);

        if (numHalfRotations2 <= maxAnglePerStep * maxAnglePerStep)
        {
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }
        else
        {
            Real factor = maxAnglePerStep * Math::sqrtInverse(numHalfRotations2);
            angularVelocity.mul4(factor);
            rotationRadians.m_vec.mul4(factor);

            numHalfRotations2 = maxAnglePerStep * maxAnglePerStep;
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }

        newRotation.FUN_008d3290(rotationRadians, newRotation);
        newRotation.FUN_004e5c20();

        motionState.m_deltaAngle.setAdd4(rotationRadians.m_vec, rotationRadians.m_vec);
        angle = Math::sqrt(numHalfRotations2) * pi;
        motionState.m_deltaAngle(3) = angle;
    }
    motionState.getSweptTransform().m_rotation1 = newRotation;
    calcTransAtT1(motionState.getSweptTransform(), motionState.getTransform());
}

static __forceinline Real calcVelocityForDeactivation(const Motion& motion, Real radius)
{
    Real linVelSqrd = motion.m_linearVelocity.lengthSquared3();
    Real angVelSqrd = motion.m_angularVelocity.lengthSquared3();
    Real velSqrd = linVelSqrd + radius * radius * angVelSqrd;
    return velSqrd;
}

static __forceinline int checkDeactivation(const SolverInfo& si, Motion& motion)
{
    UInt32 c = motion.m_deactivationIntegrateCounter;
    c += 1;
    motion.m_deactivationIntegrateCounter = UInt8(c);
    if (c & 3)
    {
        // Fake match: this early exit is written as its own return (the other exits go to the shared label).
        // The extra block it adds to the loop merges away later, but it stops the compiler rebasing the
        // accumulator pointer by a constant, so the pointer stays unbiased in a register from the prologue on.
        return Math::max2(motion.getNumInactiveFrames(0), motion.getNumInactiveFrames(1));
    }
    {
        int select;
        if (c & 15)
        {
            select = 0;
        }
        else
        {
            if (c == 0x100)
            {
                motion.m_deactivationIntegrateCounter = 0xff;
                goto END_OF_FUNCTION;
            }
            motion.m_deactivationIntegrateCounter = 0;
            select = 1;
        }

        Real radius = Math::min2(1.0f, motion.m_motionState.m_objectRadius);
        {
            Real velSqrd = calcVelocityForDeactivation(motion, radius);
            Real& maxDeactVel = motion.m_deactivationRefPosition[select](3);
            maxDeactVel = Math::max2(maxDeactVel, velSqrd);
        }

        Vec4& refPosition = motion.m_deactivationRefPosition[select];
        UInt32& refOrientation = motion.m_deactivationRefOrientation[select];
        const SweptTransform& sweptTransform = motion.m_motionState.getSweptTransform();
        const Vec4& currentPosition = sweptTransform.m_centerOfMass1;
        const Quaternion& currentRotation = sweptTransform.m_rotation1;

        while (1)
        {
            const SolverInfo::DeactivationInfo& di = si.m_deactivationInfo[motion.m_motionState.m_deactivationClass];
            {
                Real maxSqrd = di.m_maxDistSqrd[select];
                Vec4 transDist;
                transDist.setSub4(refPosition, currentPosition);
                const Real distSqrd = transDist.lengthSquared3();
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            {
                Quaternion refQ;
                unPackInt32IntoQuaternion(refOrientation, refQ.m_vec);
                Real maxSqrd = di.m_maxRotSqrd[select];
                Vec4 dist;
                dist.setSub4(refQ.m_vec, currentRotation.m_vec);
                const Real distSqrd = dist.dot4(dist);
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            motion.incrementNumInactiveFramesMt(select, si.m_deactivationNumInactiveFramesSelectFlag[select]);
            goto END_OF_FUNCTION;
        }

        motion.zeroNumInactiveFramesMt(select, si.m_deactivationNumInactiveFramesSelectFlag[select]);
        {
            Vec4 pos = currentPosition;
            pos.zeroElement(3);
            refPosition = pos;
        }
        refOrientation = hkVector4Util_packQuaternionIntoInt32(currentRotation.m_vec);
    }
END_OF_FUNCTION:
    return Math::max2(motion.getNumInactiveFrames(0), motion.getNumInactiveFrames(1));
}

}   // namespace N9ac100

using namespace N9ac100;

// pdb: hkRigidMotionUtilApplyAccumulators | hkpRigidMotionUtil.obj | fnv360_0822_debug, caller + bridge(call_gap|call_seq) + skyrim(call_gap), high
int __cdecl hkRigidMotionUtilApplyAccumulators(const SolverInfo& solverInfo, const StepInfo& info, const Accumulator* accumulators,
                         Motion* const* motions, int numMotions, int motionOffset)
{
    const Accumulator* accu = accumulators;
    int numInactiveFrames = 0x7fffffff;

    for (int i = numMotions - 1; i >= 0; motions++, accu++, i--)
    {
        Motion* motion = addByteOffset(motions[0], motionOffset);

        Vec4 integrationLinearVelocity;
        Vec4 integrationAngularVelocity;
        Vec4 angularMomentum;

        switch (motion->m_type)
        {
        case Motion::MOTION_INVALID:
        case Motion::MOTION_THIN_BOX_INERTIA: {
            ThinBoxMotion* tbm = static_cast<ThinBoxMotion*>(motion);
            Vec4 angVelLocalSpace = accu->m_angularVel;
            Vec4 in;
            in.setReciprocal4(tbm->m_inertiaAndMassInv);
            angVelLocalSpace.mul4(in);
            angularMomentum.hkVector4_setRotatedDir(tbm->getTransform().getRotation(), angVelLocalSpace);
        }
        case Motion::MOTION_BOX_INERTIA: {
            motion->m_linearVelocity = accu->m_linearVel;
            motion->m_angularVelocity._setRotatedDir(motion->getTransform().getRotation(), accu->m_angularVel);
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity.hkVector4_setRotatedDir(motion->getTransform().getRotation(), accu->getSumAngularVel());
            goto sphereInertia;
        }
        case Motion::MOTION_STABILIZED_BOX_INERTIA: {
            motion->m_linearVelocity = accu->getSumLinearVel();
            motion->m_angularVelocity = accu->getSumAngularVel();
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity.hkVector4_setRotatedDir(motion->getTransform().getRotation(), accu->getSumAngularVel());
            goto sphereInertia;
        }
        case Motion::MOTION_STABILIZED_SPHERE_INERTIA: {
            motion->m_linearVelocity = accu->getSumLinearVel();
            motion->m_angularVelocity = accu->getSumAngularVel();
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity = accu->getSumAngularVel();
            goto sphereInertia;
        }
        case Motion::MOTION_KEYFRAMED: {
            motion->m_linearVelocity = motion->m_linearVelocity;
            motion->m_angularVelocity = motion->m_angularVelocity;
            integrationLinearVelocity = motion->m_linearVelocity;
            integrationAngularVelocity = motion->m_angularVelocity;
            goto sphereInertia;
        }
        case Motion::MOTION_SPHERE_INERTIA:
        case Motion::MOTION_CHARACTER: {
            motion->m_linearVelocity = accu->m_linearVel;
            motion->m_angularVelocity = accu->m_angularVel;
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity = accu->getSumAngularVel();
        }
        sphereInertia:
        // Fake match: a second label directly after the first. Nothing jumps to it. The extra block boundary it
        // puts in front of the step makes the compiler emit the first lane's duplicate before the motion-state
        // address and the first absolute value before the first mask store, as the original does.
        doStep:
            stepMotionState(info, integrationLinearVelocity, integrationAngularVelocity, motion->m_motionState);
        default:
            break;
        }

        if (motion->m_type == Motion::MOTION_THIN_BOX_INERTIA)
        {
            ThinBoxMotion* tbm = static_cast<ThinBoxMotion*>(motion);
            tbm->m_linearVelocity = accu->m_linearVel;
            Vec4 h;
            h.FUN_00477880(tbm->getTransform().getRotation(), angularMomentum);
            h.mul4(tbm->m_inertiaAndMassInv);
            tbm->m_angularVelocity.hkVector4_setRotatedDir(tbm->getTransform().getRotation(), h);
        }
        clipVelocities(motion->m_motionState, motion->m_linearVelocity, motion->m_angularVelocity);
        numInactiveFrames = Math::min2(numInactiveFrames, checkDeactivation(solverInfo, *motion));
    }
    return numInactiveFrames;
}
}   // namespace f3m_009ac100

// @f3 0x009aa3e0 (community match, verified in this file)
#include <math.h>
namespace f3m_009aa3e0 {
// 0x009aa3e0: rigid motion utility, apply forces and step (x87 build of the physics library).
// Adds the gravity step to each motion, applies damping, steps the motion state (thin boxes keep their
// angular momentum) and updates the deactivation counters. Returns the smallest inactive-frame count.
// Worked under /MT /O2 /GS- /EHs-c- /Gy (the pack lists /Od /EHsc; the target is /O2 with exception handling off).
// Official checker MATCH under the optimized flags above. Six marked dead locals remain;
// the clip and default-add boundaries and three-operand inertia multiply recover the coupled lane order.

namespace N9aa3e0 {

typedef float Real;
typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef unsigned int UInt32;

extern float DAT_00e35180[256];   // 8-bit float decode table

namespace Math {
inline Real sqrt(const Real& r) { return sqrtf(r); }
inline Real sqrtInverse(Real r) { return 1.0f / sqrtf(r); }
inline Real fabs(Real r) { return fabsf(r); }
inline Real min2(Real x, Real y) { return x < y ? x : y; }
inline Real max2(Real x, Real y) { return x > y ? x : y; }
inline int min2(int x, int y) { return x < y ? x : y; }
inline int max2(int x, int y) { return x > y ? x : y; }
}

template <class T>
class Pad
{
  public:
    __forceinline T val() const { return m_storage; }
    __forceinline operator T() const { return val(); }

  private:
    T m_storage;
};

class Comparison
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_W = 1,
        MASK_Z = 2,
        MASK_Y = 4,
        MASK_X = 8,
        MASK_XYZ = 14
    };
    __forceinline int getMask() const { return m_mask; }
    int m_mask;
};

class Rotation;
class Quaternion;

class Vec4
{
  public:
    __forceinline Vec4() {}
    __forceinline void operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    __forceinline Real& operator()(int i) { return (&x)[i]; }
    __forceinline const Real& operator()(int i) const { return (&x)[i]; }

    void hkVector4_setRotatedDir(const Rotation& r, const Vec4& v);   // setRotatedDir, out of line
    void FUN_00477880(const Rotation& r, const Vec4& v);   // setRotatedInverseDir, out of line
    __forceinline void _setRotatedDir(const Rotation& r, const Vec4& v);

    __forceinline void setReciprocal4(const Vec4& a) { x = 1.0f / a.x; y = 1.0f / a.y; z = 1.0f / a.z; w = 1.0f / a.w; }
    __forceinline void add4(const Vec4& a) { x += a.x; y += a.y; z += a.z; w += a.w; }
    __forceinline void mul4(const Vec4& a) { x *= a.x; y *= a.y; z *= a.z; w *= a.w; }
    __forceinline void div4(const Vec4& a) { Vec4 r; r.setReciprocal4(a); mul4(r); }
    __forceinline void mul4(Real rs) { Real r = rs; x *= r; y *= r; z *= r; w *= r; }
    __forceinline void setMul4(Real r, const Vec4& a) { x = r * a.x; y = r * a.y; z = r * a.z; w = r * a.w; }
    __forceinline void setMul4(const Vec4& a, const Vec4& b) { x=a.x*b.x; y=a.y*b.y; z=a.z*b.z; w=a.w*b.w; }
    __forceinline void setAdd4(const Vec4& a, const Vec4& b) { x = a.x + b.x; y = a.y + b.y; z = a.z + b.z; w = a.w + b.w; }
    __forceinline void setSub4(const Vec4& a, const Vec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    __forceinline void addMul4(const Real& rs, const Vec4& a) { Real r = rs; x += r * a.x; y += r * a.y; z += r * a.z; w += r * a.w; }
    __forceinline void setAbs4(const Vec4& v) { x = Math::fabs(v.x); y = Math::fabs(v.y); z = Math::fabs(v.z); w = Math::fabs(v.w); }
    __forceinline Real dot3(const Vec4& a) const { return (x * a.x) + (y * a.y) + (z * a.z); }
    __forceinline Real lengthSquared3() const { return this->dot3(*this); }
    __forceinline Real dot4(const Vec4& a) const { return x * a.x + y * a.y + z * a.z + w * a.w; }
    __forceinline void zeroElement(int i) { (*this)(i) = 0.0f; }
    __forceinline Comparison compareLessThan4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x < v.x) ? 8 : 0;
        int my = (y < v.y) ? 4 : 0;
        int mz = (z < v.z) ? 2 : 0;
        int mw = (w < v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }
    __forceinline Comparison compareEqual4(const Vec4& v) const
    {
        Comparison ret;
        int mx = (x == v.x) ? 8 : 0;
        int my = (y == v.y) ? 4 : 0;
        int mz = (z == v.z) ? 2 : 0;
        int mw = (w == v.w) ? 1 : 0;
        ret.m_mask = mx | my | mz | mw;
        return ret;
    }

    __declspec(align(16)) Real x;
    Real y;
    Real z;
    Real w;
};

extern Vec4 DAT_01061120;   // largest velocity the integrator accepts
extern Vec4 DAT_010f3370;   // identity transform, first column

class Rotation
{
  public:
    __forceinline const Vec4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const Real& operator()(int row, int col) const { return getColumn(col)(row); }
    void hkRotation_set(const Quaternion& q);   // set from a quaternion

    Vec4 m_col0;
    Vec4 m_col1;
    Vec4 m_col2;
};

class Transform
{
  public:
    __forceinline Rotation& getRotation() { return m_rotation; }
    __forceinline const Rotation& getRotation() const { return m_rotation; }
    __forceinline Vec4& getTranslation() { return m_translation; }
    __forceinline void setRotation(const Quaternion& q) { m_rotation.hkRotation_set(q); }
    __forceinline static const Vec4& getIdentityColumn0() { return DAT_010f3370; }

    Rotation m_rotation;
    Vec4 m_translation;
};

__forceinline void Vec4::_setRotatedDir(const Rotation& r, const Vec4& v)
{
    Real v0 = v(0);
    Real v1 = v(1);
    Real v2 = v(2);
    Vec4& t = *this;
    t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2;
    t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2;
    t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2;
    t(3) = 0;
}

class Quaternion
{
  public:
    void FUN_008d3290(const Quaternion& r, const Quaternion& q);   // setMul
    void FUN_004e5c20();                                           // normalize

    Vec4 m_vec;
};

UInt32 __cdecl hkVector4Util_packQuaternionIntoInt32(const Vec4& q);   // pack a quaternion into 32 bits

class SweptTransform
{
  public:
    Vec4 m_centerOfMass0;      // w: start time
    Vec4 m_centerOfMass1;      // w: 1 / delta time
    Quaternion m_rotation0;
    Quaternion m_rotation1;
    Vec4 m_centerOfMassLocal;
};

class UFloat8
{
  public:
    __forceinline operator float() const { return DAT_00e35180[m_value]; }
    UInt8 m_value;
};

class MotionState
{
  public:
    __forceinline Transform& getTransform() { return m_transform; }
    __forceinline const Transform& getTransform() const { return m_transform; }
    __forceinline SweptTransform& getSweptTransform() { return m_sweptTransform; }
    __forceinline const SweptTransform& getSweptTransform() const { return m_sweptTransform; }

    Transform m_transform;
    SweptTransform m_sweptTransform;
    Vec4 m_deltaAngle;
    Real m_objectRadius;
    Real m_linearDamping;
    Real m_angularDamping;
    UFloat8 m_maxLinearVelocity;
    UFloat8 m_maxAngularVelocity;
    UInt8 m_deactivationClass;
};

class Motion
{
  public:
    enum MotionType
    {
        MOTION_INVALID,
        MOTION_DYNAMIC,
        MOTION_SPHERE_INERTIA,
        MOTION_STABILIZED_SPHERE_INERTIA,
        MOTION_BOX_INERTIA,
        MOTION_STABILIZED_BOX_INERTIA,
        MOTION_KEYFRAMED,
        MOTION_FIXED,
        MOTION_THIN_BOX_INERTIA,
        MOTION_CHARACTER
    };
    __forceinline const Transform& getTransform() const { return m_motionState.getTransform(); }
    __forceinline int getNumInactiveFrames(int select) { return m_deactivationNumInactiveFrames[select] & 0x7f; }
    __forceinline void incrementNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        int newdc = dc + 1 - (dc >> 6);
        dc = newdc | (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }
    __forceinline void zeroNumInactiveFramesMt(int select, int selectFlag)
    {
        int dc = m_deactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        dc = (dc << 7) | (selectFlag << 14);
        m_deactivationNumInactiveFrames[select] = UInt16(dc);
    }

    void* m_vtable;
    UInt16 m_memSizeAndFlags;
    short m_referenceCount;
    UInt8 m_type;
    UInt8 m_deactivationIntegrateCounter;
    UInt16 m_deactivationNumInactiveFrames[2];
    MotionState m_motionState;
    Vec4 m_inertiaAndMassInv;
    Vec4 m_linearVelocity;
    Vec4 m_angularVelocity;
    Vec4 m_deactivationRefPosition[2];
    UInt32 m_deactivationRefOrientation[2];
};

class ThinBoxMotion : public Motion
{
};

class Accumulator
{
  public:
    __forceinline const Vec4& getSumLinearVel() const { return getScratch0(); }
    __forceinline const Vec4& getSumAngularVel() const { return getScratch1(); }
    __forceinline const Vec4& getScratch0() const { return m_scratch0; }
    __forceinline const Vec4& getScratch1() const { return m_scratch1; }

    UInt8 m_type;
    UInt8 m_context;
    UInt32 m_deactivationClass;
    Real m_gravityFactor;
    Vec4 m_linearVel;
    Vec4 m_angularVel;
    Vec4 m_invMasses;
    Vec4 m_scratch0;
    Vec4 m_scratch1;
    Vec4 m_scratch2;
    Vec4 m_scratch3;
};

class StepInfo
{
  public:
    Pad<Real> m_startTime;
    Pad<Real> m_endTime;
    Pad<Real> m_deltaTime;
    Pad<Real> m_invDeltaTime;
};

class Half
{
  public:
    __forceinline operator Real() const
    {
        union { int i; float f; } u;
        u.i = m_value << 16;
        return u.f;
    }
    short m_value;
};

class SolverInfo
{
  public:
    struct DeactivationInfo
    {
        Real m_linearVelocityThresholdInv;
        Real m_angularVelocityThresholdInv;
        Real m_slowObjectVelocityMultiplier;
        Real m_relativeSleepVelocityThreshold;
        Real m_maxDistSqrd[2];
        Half m_maxRotSqrd[2];
    };
    __declspec(align(16)) Real m_one;
    Real m_tau;
    Real m_damping;
    Real m_frictionTau;
    Vec4 m_globalAccelerationPerSubStep;
    Vec4 m_globalAccelerationPerStep;
    Vec4 m_integrateVelocityFactor;
    Vec4 m_invIntegrateVelocityFactor;
    Real m_dampDivTau;
    Real m_tauDivDamp;
    Real m_dampDivFrictionTau;
    Real m_frictionTauDivDamp;
    Real m_contactRestingVelocity;
    DeactivationInfo m_deactivationInfo[6];
    Real m_deltaTime;
    Real m_invDeltaTime;
    int m_numSteps;
    int m_numMicroSteps;
    Real m_invNumMicroSteps;
    Real m_invNumSteps;
    bool m_forceCoherentConstraintOrderingInSolver;
    UInt8 m_deactivationNumInactiveFramesSelectFlag[2];
    UInt8 m_deactivationIntegrateCounter;
};

template <typename TYPE> __forceinline TYPE* addByteOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

__forceinline void unPackInt32IntoQuaternion(UInt32 ivalue, Vec4& qout)
{
    int a = ivalue;
    int b = ivalue >> 8;
    int c = ivalue >> 16;
    int d = ivalue >> 24;
    a &= 0xff;
    b &= 0xff;
    c &= 0xff;
    a -= 0x80;
    b -= 0x80;
    c -= 0x80;
    d -= 0x80;
    const Real f = 1.1f / 128.0f;
    qout(0) = f * a;
    qout(1) = f * b;
    qout(2) = f * c;
    qout(3) = f * d;
}

__forceinline void calcTransAtT1(const SweptTransform& sweptTrans, Transform& transformOut)
{
    const Quaternion& qt = sweptTrans.m_rotation1;
    transformOut.setRotation(qt);
    Vec4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_centerOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_centerOfMass1, centerShift);
}

// Fake match: a motion-pointer boundary changes inline symbol identity without changing clipping.
// Fake match: an inline boundary for the default velocity addition controls its first-lane operand order.
__forceinline void addVelocity(Vec4& target, const Vec4& source) { target.setAdd4(source,target); }
__forceinline void clipVelocities(Motion* motion)
{
    const MotionState& motionState=motion->m_motionState;
    Vec4& linearVelocity=motion->m_linearVelocity;
    Vec4& angularVelocity=motion->m_angularVelocity;
    // Fake match: three dead locals. Together with the three in the main function they only shift the compiler
    // symbol numbering, which decides the first-lane operand order of several inlined scale and add sites.
    int padClip0 = 1; // Fake match: retain the measured inline symbol-number phase.
    int padClip1 = 2; // Fake match: retain the measured inline symbol-number phase.
    int padClip2 = 3; // Fake match: retain the measured inline symbol-number phase.
    Real linVelSq = linearVelocity.lengthSquared3();
    Real angVelSq = angularVelocity.lengthSquared3();
    const Real maxLinear = motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity;
    const Real maxAngular = motionState.m_maxAngularVelocity * motionState.m_maxAngularVelocity;
    if ((linVelSq > maxLinear) || (linVelSq != linVelSq))
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
        if (linVelSq != linVelSq)
        {
            linearVelocity = Transform::getIdentityColumn0();
        }
    }
    if ((angVelSq > maxAngular) || (angVelSq != angVelSq))
    {
        Real f = motionState.m_maxAngularVelocity * Math::sqrtInverse(angVelSq);
        angularVelocity.mul4(f);
        if (angVelSq != angVelSq)
        {
            angularVelocity = Transform::getIdentityColumn0();
        }
    }
}

__forceinline void stepMotionState(const StepInfo& info, Vec4& linearVelocity, Vec4& angularVelocity,
                                   MotionState& motionState)
{

    {
        // replace NaN or huge velocities
        Vec4 absLin;
        absLin.setAbs4(linearVelocity);
        Vec4 absAng;
        absAng.setAbs4(angularVelocity);

        int mask = absLin.compareLessThan4(DAT_01061120).getMask() & absAng.compareLessThan4(DAT_01061120).getMask();
        mask &= linearVelocity.compareEqual4(linearVelocity).getMask() &
                angularVelocity.compareEqual4(angularVelocity).getMask();
        if ((mask & Comparison::MASK_XYZ) != Comparison::MASK_XYZ)
        {
            linearVelocity = Transform::getIdentityColumn0();
            angularVelocity = Transform::getIdentityColumn0();
        }
    }

    motionState.getSweptTransform().m_centerOfMass0 = motionState.getSweptTransform().m_centerOfMass1;
    motionState.getSweptTransform().m_centerOfMass0(3) = info.m_startTime;

    Real linVelSq = linearVelocity.lengthSquared3();
    if (linVelSq > motionState.m_maxLinearVelocity * motionState.m_maxLinearVelocity)
    {
        Real f = motionState.m_maxLinearVelocity * Math::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
    }

    motionState.getSweptTransform().m_centerOfMass1.addMul4(info.m_deltaTime, linearVelocity);
    motionState.getSweptTransform().m_centerOfMass1(3) = info.m_invDeltaTime;

    Quaternion newRotation = motionState.getSweptTransform().m_rotation1;
    motionState.getSweptTransform().m_rotation0 = newRotation;

    {
        Quaternion rotationRadians;
        Real angle;
        rotationRadians.m_vec.setMul4(info.m_deltaTime * 0.5f, angularVelocity);
        const Real pi = 3.14159265358979f;
        Real numHalfRotations2 = rotationRadians.m_vec.lengthSquared3() * (4.0f / (pi * pi));

        const Real a = 0.822948f;
        const Real b = 0.130529f;
        const Real c = 0.044408f;

        const Real maxAnglePerStep = Math::min2(0.9f, info.m_deltaTime.val() * motionState.m_maxAngularVelocity);

        if (numHalfRotations2 <= maxAnglePerStep * maxAnglePerStep)
        {
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }
        else
        {
            Real factor = maxAnglePerStep * Math::sqrtInverse(numHalfRotations2);
            angularVelocity.mul4(factor);
            rotationRadians.m_vec.mul4(factor);

            numHalfRotations2 = maxAnglePerStep * maxAnglePerStep;
            const Real numHalfRotations4 = numHalfRotations2 * numHalfRotations2;
            const Real w = 1.0f - a * numHalfRotations2 - b * numHalfRotations4 - c * numHalfRotations2 * numHalfRotations4;
            rotationRadians.m_vec(3) = w;
        }

        newRotation.FUN_008d3290(rotationRadians, newRotation);
        newRotation.FUN_004e5c20();

        motionState.m_deltaAngle.setAdd4(rotationRadians.m_vec, rotationRadians.m_vec);
        angle = Math::sqrt(numHalfRotations2) * pi;
        motionState.m_deltaAngle(3) = angle;
    }
    motionState.getSweptTransform().m_rotation1 = newRotation;
    calcTransAtT1(motionState.getSweptTransform(), motionState.getTransform());
}

static __forceinline Real calcVelocityForDeactivation(const Motion& motion, Real radius)
{
    Real linVelSqrd = motion.m_linearVelocity.lengthSquared3();
    Real angVelSqrd = motion.m_angularVelocity.lengthSquared3();
    Real velSqrd = linVelSqrd + radius * radius * angVelSqrd;
    return velSqrd;
}

static __forceinline int checkDeactivation(const SolverInfo& si, Motion& motion)
{

    UInt32 c = motion.m_deactivationIntegrateCounter;
    c += 1;
    motion.m_deactivationIntegrateCounter = UInt8(c);
    if (c & 3)
    {
        goto END_OF_FUNCTION;
    }
    {
        int select;
        if (c & 15)
        {
            select = 0;
        }
        else
        {
            if (c == 0x100)
            {
                motion.m_deactivationIntegrateCounter = 0xff;
                goto END_OF_FUNCTION;
            }
            motion.m_deactivationIntegrateCounter = 0;
            select = 1;
        }

        Real radius = Math::min2(1.0f, motion.m_motionState.m_objectRadius);
        {
            Real velSqrd = calcVelocityForDeactivation(motion, radius);
            Real& maxDeactVel = motion.m_deactivationRefPosition[select](3);
            maxDeactVel = Math::max2(maxDeactVel, velSqrd);
        }

        Vec4& refPosition = motion.m_deactivationRefPosition[select];
        UInt32& refOrientation = motion.m_deactivationRefOrientation[select];
        const SweptTransform& sweptTransform = motion.m_motionState.getSweptTransform();
        const Vec4& currentPosition = sweptTransform.m_centerOfMass1;
        const Quaternion& currentRotation = sweptTransform.m_rotation1;

        while (1)
        {
            const SolverInfo::DeactivationInfo& di = si.m_deactivationInfo[motion.m_motionState.m_deactivationClass];
            {
                Real maxSqrd = di.m_maxDistSqrd[select];
                Vec4 transDist;
                transDist.setSub4(refPosition, currentPosition);
                const Real distSqrd = transDist.lengthSquared3();
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            {
                Quaternion refQ;
                unPackInt32IntoQuaternion(refOrientation, refQ.m_vec);
                Real maxSqrd = di.m_maxRotSqrd[select];
                Vec4 dist;
                dist.setSub4(refQ.m_vec, currentRotation.m_vec);
                const Real distSqrd = dist.dot4(dist);
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            motion.incrementNumInactiveFramesMt(select, si.m_deactivationNumInactiveFramesSelectFlag[select]);
            goto END_OF_FUNCTION;
        }

        motion.zeroNumInactiveFramesMt(select, si.m_deactivationNumInactiveFramesSelectFlag[select]);
        {
            Vec4 pos = currentPosition;
            pos.zeroElement(3);
            refPosition = pos;
        }
        refOrientation = hkVector4Util_packQuaternionIntoInt32(currentRotation.m_vec);
    }
END_OF_FUNCTION:
    return Math::max2(motion.getNumInactiveFrames(0), motion.getNumInactiveFrames(1));
}




}   // namespace N9aa3e0

using namespace N9aa3e0;

// pdb: hkRigidMotionUtilApplyForcesAndStep | hkpRigidMotionUtil.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
int __cdecl hkRigidMotionUtilApplyForcesAndStep(const SolverInfo& solverInfo, const StepInfo& info, const Vec4& deltaVel,
                         Motion* const* motions, int numMotions, int motionOffset)
{
    // Fake match: three dead locals (see the clip helper). They only shift the compiler symbol numbering, which
    // decides which operand of the first lane is loaded first at several inlined vector sites.
    int pad0 = 1; // Fake match: retain the measured inline symbol-number phase.
    int pad1 = 2; // Fake match: retain the measured inline symbol-number phase.
    int pad2 = 3; // Fake match: retain the measured inline symbol-number phase.
    int numInactiveFrames = 0x7fffffff;

    for (int i = numMotions - 1; i >= 0; motions++, i--)
    {
        Motion* motion = addByteOffset(motions[0], motionOffset);

        const int type = motion->m_type;
        switch (type)
        {
        case Motion::MOTION_THIN_BOX_INERTIA: {
            ThinBoxMotion* tbm = static_cast<ThinBoxMotion*>(motion);
            tbm->m_linearVelocity.add4(deltaVel);
            {
                const Real deltaTime = info.m_deltaTime;
                const Real linearDamping = tbm->m_motionState.m_linearDamping;
                tbm->m_linearVelocity.mul4(Math::max2(0.0f, 1.0f - deltaTime * linearDamping));
                tbm->m_angularVelocity.mul4(Math::max2(0.0f, 1.0f - deltaTime * tbm->m_motionState.m_angularDamping));
            }

            Vec4 angularMomentum;
            {
                const Rotation& rot = tbm->getTransform().getRotation();
                Vec4 h;
                h.FUN_00477880(rot, tbm->m_angularVelocity);
                Vec4 in;
                in.setReciprocal4(tbm->m_inertiaAndMassInv);
                h.mul4(in);
                angularMomentum.hkVector4_setRotatedDir(rot, h);
            }

            stepMotionState(info, tbm->m_linearVelocity, tbm->m_angularVelocity, tbm->m_motionState);

            {
                const Rotation& rot = tbm->getTransform().getRotation();
                Vec4 h;
                h.FUN_00477880(rot, angularMomentum);
                // Fake match: the three-operand multiply supplies the body-space product boundary.
                h.setMul4(tbm->m_inertiaAndMassInv, h);
                tbm->m_angularVelocity.hkVector4_setRotatedDir(rot, h);
            }
            clipVelocities(tbm);
            break;
        }
        default:
            addVelocity(motion->m_linearVelocity, deltaVel);
        case Motion::MOTION_CHARACTER:
            {
                const Real deltaTime = info.m_deltaTime;
                const Real linearDamping = motion->m_motionState.m_linearDamping;
                motion->m_linearVelocity.mul4(Math::max2(0.0f, 1.0f - deltaTime * linearDamping));
                const Real angularDamping = motion->m_motionState.m_angularDamping;
                motion->m_angularVelocity.mul4(Math::max2(0.0f, 1.0f - deltaTime * angularDamping));
            }
        case Motion::MOTION_KEYFRAMED:
            stepMotionState(info, motion->m_linearVelocity, motion->m_angularVelocity, motion->m_motionState);
            break;
        case Motion::MOTION_FIXED:
            continue;
        }
        const int motionInactiveFrames = checkDeactivation(solverInfo, *motion);
        numInactiveFrames = Math::min2(numInactiveFrames, motionInactiveFrames);
    }
    return numInactiveFrames;
}
}   // namespace f3m_009aa3e0

// @f3 0x009b5ea0 (community match, verified in this file)
// 0x009b5ea0: hkpBvTreeStreamAgent::processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const
// hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output) of Havok 5.5.0 (hkpCollide,
// hkpBvTreeStreamAgent.cpp; compiled with /MT /Ox /Ob1 /Oi /Ot /GF /GS-): the bounding-volume-tree stream agent's
// collision step. It computes the linear time-of-impact info of the two bodies and B-from-A transform, queries B's
// tree with A's expanded (and cached) bounding box, and when the query ran and enough memory is left, sorts the hit
// keys and runs the 1n agent machine over them (without hits when the cached box still holds the new one).
// The query is hkpBvTreeAgent::calcAabbAndQueryTree, an HK_FORCE_INLINE static member that hkpBvTreeAgent.h declares
// but the SDK does not ship the body of: it is defined here (before the function) from its inlined code in the SDK's
// libraries (statement structure as in the New Vegas decompilation's counterpart): A's box in B's space widened by
// the tolerance and, with continuous physics, by the second-order rotation error and clipped to a sphere around A's
// mass centre, extended along the time-of-impact path; then compared with and stored into the cached box.
// The member is named hkpBvTreeStreamAgent_processCollision inside its class (its virtual processCollision of the base class is not
// overridden here, which changes no byte of the function).
// This file is built from the Havok 5.5.0 SDK's own headers: the function was compiled with the real headers, and
// the preprocessed source was cut down mechanically to the declarations the code needs (whole declarations by
// work\_havok\hkpipe\hkreduce.py, then whole lines, every cut checked byte for byte against the SDK's release
// library object); those declarations are the SDK's text with its names. The body follows the SDK's unoptimized
// (hybrid) library object statement by statement (all 26 named locals at the library's places) and reproduces the
// release object. Only the function carries the packet's name.
namespace f3m_009b5ea0 {

typedef float  hkReal;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
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
class hkOstream;
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
		__forceinline void pushBack(const T& e);
		__forceinline void pushBackUnchecked(const T& e);
		__forceinline void reserve(int n);
		__forceinline void reserveExactly(int n);
		__forceinline void setSize(int size);
		void swap(hkArray<T>& a);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		__forceinline iterator end();
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
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline hkInplaceArray(int size = 0);
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
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
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().deallocateChunk( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t)
{
	;
	m_data[m_size++] = t;
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
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
		int m_mask;
		friend class hkVector4;
};
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
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setNeg4If( int cond );
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
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
		static void __cdecl fastRenormalizeBatch( hkQsTransform* poseOut, hkReal* weight, hkUint32 numTransforms);
	public:
		hkVector4 m_translation;
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
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
inline void hkVector4::setAll3(hkReal a)
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
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
	z = v0.z + v1.z;
	w = v0.w + v1.w;
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
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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
inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
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
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}
inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}
const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}
inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
}
class hkMonitorStream
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		void __cdecl reset();
		void __cdecl resize( int newSize );
	public:
		__forceinline char* __cdecl getStart() { return m_start.val(); }
		__forceinline char* __cdecl getEnd() { return m_end.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* __cdecl getCapacity() { return m_capacity.val(); }
		__forceinline hkBool __cdecl memoryAvailable( )
		{
			return getEnd() < getCapacityMinus16();
		}
		__forceinline int __cdecl getCurrentMonitorDataSize()
		{
			return (int)(m_end.val() - m_start.val());
		}
		__forceinline void* __cdecl expandby( int size ) { char* h = m_end.val(); char* newEnd = h + size; m_end = newEnd; return h; }
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; }
		__forceinline hkBool __cdecl isBufferAllocatedOnTheHeap() { return m_isBufferAllocatedOnTheHeap; }
		void __cdecl setStaticBuffer( char* buffer, int bufferSize );
	public:
		static void __cdecl init();
		void __cdecl quit();
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
	public:
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		struct AddValueCommand : public hkMonitorStream::Command
		{
			float m_value;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
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
const hkTransform& hkMotionState::getTransform() const
{
	return m_transform;
}
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
hkBool hkAabb::contains(const hkAabb& other) const
{
	hkVector4Comparison mincomp = m_min.compareLessThanEqual4(other.m_min);
	hkVector4Comparison maxcomp = other.m_max.compareLessThanEqual4(m_max);
	hkVector4Comparison both; both.setAnd( mincomp, maxcomp );
	return both.allAreSet(hkVector4Comparison::MASK_XYZ) != 0;
}
class hkSphere;
typedef hkUint16 hkContactPointId;
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
void hkpShape::getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const
{
	getAabbImpl( localToWorld, tolerance, out );
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
const hkTransform& hkpCdBody::getTransform() const
{
	;
	return *static_cast<const hkTransform*>(m_motion);
}
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
struct hkpAgent3Input
{
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform		m_aTb;
};
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	hkPadSpu<hkReal>          m_distAtT1;
	hkPadSpu<int>		m_offsetPpuSectorMinusSpuSector;
	hkVector4       m_linearTimInfo;
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
class hkpCollisionDispatcher;
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
class hkpConstraintOwner;
struct hkpProcessCollisionOutput;
struct hkpLinearCastCollisionInput;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
class hkpCollisionAgent : public hkReferencedObject
{
	public:
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner ) {}
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
class hkStepInfo
{
	public:
		hkStepInfo(){}
		void set( hkTime startTime, hkTime endTime)
		{
			m_startTime = startTime;
			m_endTime   = endTime;
			m_deltaTime = endTime - startTime;
			m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
		}
		hkStepInfo( hkTime startTime, hkTime endTime)
		{
			set( startTime, endTime );
		}
	public:
		__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
		hkPadSpu<hkTime> m_endTime;
		hkPadSpu<hkReal> m_deltaTime;
		hkPadSpu<hkReal> m_invDeltaTime;
};
struct hkpProcessCollisionInput : public hkpCollisionInput
{
	public:
		hkStepInfo m_stepInfo;
		mutable hkPadSpu<hkpCollisionQualityInfo*> m_collisionQualityInfo;
		void*	m_dynamicsInfo;
		bool m_enableDeprecatedWelding;
		hkpCollisionAgentConfig* m_config;
};
class hkpBvTreeAgent : public hkpCollisionAgent
{
	public:
		static void __cdecl registerAgent(hkpCollisionDispatcher* dispatcher);
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector ) ;
		static void __cdecl staticGetClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector ) ;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		virtual void processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void cleanup(hkpConstraintOwner& info);
		static void __cdecl setUseAabbCaching( hkBool useIt );
		static hkBool __cdecl getUseAabbCaching();
	public:
		static hkBool m_useFastUpdate;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner );
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
		__forceinline static hkResult __cdecl calcAabbAndQueryTree(
											const hkpCdBody& bodyA,	const hkpCdBody& bodyB, const hkTransform& bTa,
											const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input,
											hkAabb* cachedAabb, hkArray<hkpShapeKey>& hitListOut );
	public:
		hkpBvTreeAgent( hkpContactMgr* mgr );
	protected:
		void calcStatistics( hkStatisticsCollector* collector) const;
		static hkpCollisionAgent* __cdecl defaultAgentCreate( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& env, hkpContactMgr* mgr );
		static inline void __cdecl calcAabbLinearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkAabb& aabbOut);
		static inline void __cdecl staticCalcAabb(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkAabb& aabbOut);
		~hkpBvTreeAgent(){}
		struct hkpBvAgentEntryInfo
		{
			hkpShapeKey m_key;
			hkInt32 m_userInfo;
			hkpCollisionAgent* m_collisionAgent;
			hkpShapeKey& getKey() { return m_key; }
			void setKey( hkpShapeKey& key) { m_key = key; }
		};
		hkArray<hkpBvAgentEntryInfo> m_collisionPartners;
		hkAabb	m_cachedAabb;
		static hkBool m_useAabbCaching;
		static hkpCollisionAgent* __cdecl createShapeBvAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
		static hkpCollisionAgent* __cdecl createBvBvAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
};
typedef void hkpAgentData;
struct hkpAgent1nSector
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	enum { SECTOR_SIZE = 512, NET_SECTOR_SIZE = SECTOR_SIZE - 16 };
	hkUint32 m_bytesAllocated;
	hkUint32 m_pad0;
	hkUint32 m_pad1;
	hkUint32 m_pad2;
	hkUint8 m_data[512-16];
	__forceinline hkpAgentData* getBegin()
	{
		return reinterpret_cast<hkpAgentData*>( &m_data[0] );
	}
	hkpAgentData* getEnd()
	{
		;
		return reinterpret_cast<hkpAgentData*>( &m_data[m_bytesAllocated] );
	}
	int getCapacity()
	{
		return NET_SECTOR_SIZE;
	}
	int getFreeBytes()
	{
		return static_cast<int>(NET_SECTOR_SIZE - m_bytesAllocated);
	}
	inline hkpAgent1nSector(): m_bytesAllocated(0){}
	inline hkpAgent1nSector(class hkFinishLoadedObjectFlag flag) {}
};
struct hkpAgent1nTrack
{
	hkArray<hkpAgent1nSector*> m_sectors;
};
class hkpBvTreeStreamAgent : public hkpCollisionAgent
{
	public:
		static void __cdecl registerAgent(hkpCollisionDispatcher* dispatcher);
		static void __cdecl registerConvexListAgent(hkpCollisionDispatcher* dispatcher);
		static void __cdecl registerMultiRayAgent(hkpCollisionDispatcher* dispatcher);
		virtual void hkpBvTreeStreamAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result);
		virtual void cleanup(hkpConstraintOwner& info);
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector ) ;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner );
		virtual void invalidateTim(hkpCollisionInput& input);
		virtual void warpTime(hkTime oldTime, hkTime newTime, hkpCollisionInput& input);
	protected:
		hkResult prepareCollisionPartnersProcess( hkpAgent3ProcessInput& input, hkArray<hkpShapeKey>& hitList );
		hkpBvTreeStreamAgent( const hkpCdBody& bodyA, 	const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
		~hkpBvTreeStreamAgent(){}
		void calcStatistics( hkStatisticsCollector* collector) const;
	public:
		static hkpCollisionAgent* __cdecl createShapeBvAgent( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr );
	protected:
		hkpCollisionDispatcher* m_dispatcher;
		hkAabb	m_cachedAabb;
		hkpAgent1nTrack m_agentTrack;
};
extern "C"
{
void __cdecl hkAgent1nMachine_Process( hkpAgent1nTrack& agentTrack, hkpAgent1nTrack* agentTrackOnPpu, const hkpAgent3ProcessInput& input, const hkpShapeContainer* shapeContainterB, const hkpShapeKey* hitList, hkpProcessCollisionOutput& output  );
}
namespace hkSweptTransformUtil
{
__forceinline void __cdecl calcTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4& timOut);
}
void __cdecl hkSweptTransformUtil::calcTimInfo( const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, hkVector4& timOut)
{
	const hkSweptTransform& st0 = ms0.getSweptTransform();
	const hkSweptTransform& st1 = ms1.getSweptTransform();
	hkVector4 diff0; diff0.setSub4( st0.m_centerOfMass0, st0.m_centerOfMass1 );
	hkVector4 diff1; diff1.setSub4( st1.m_centerOfMass1, st1.m_centerOfMass0 );
	hkReal f0 = deltaTime * st0.getInvDeltaTime();
	hkReal f1 = deltaTime * st1.getInvDeltaTime();
	;
	timOut.setMul4( f0, diff0 );
	timOut.addMul4( f1, diff1 );
	timOut(3) = f0 * ms0.m_deltaAngle(3) * ms0.m_objectRadius  + f1 * ms1.m_deltaAngle(3) * ms1.m_objectRadius;
}
namespace hkAlgorithm
{
template<typename T>
	class less
	{
		public:
			__forceinline hkBool operator() ( const T& a, const T& b )
			{
				return ( a < b );
			}
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
class hkpBvTreeShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkpBvTreeShape( hkpShapeType type );
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const = 0;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const = 0;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const = 0;
		virtual const hkpShapeContainer* getContainer() const = 0;
	public:
		hkpBvTreeShape( hkFinishLoadedObjectFlag flag ) : hkpShape(flag) { m_type = HK_SHAPE_BV_TREE; }
};
struct hkMemoryStatistics;
class hkLimitedMemoryListener;
typedef void (__cdecl *hkMemoryWalkCallback)(void* start, hk_size_t size,hkBool allocated,int pool,void* param);
class hkMemory
{
	public:
		friend class hkThreadMemory;
		hkMemory();
		virtual ~hkMemory();
		virtual void allocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void deallocateChunkBatch(void** blocksOut, int nblocks, int nbytes) = 0;
		virtual void* allocateChunk( int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateChunk( void*, int nbytes, HK_MEMORY_CLASS cl ) = 0;
		virtual void* allocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void deallocateRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void preAllocateRuntimeBlock(int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void provideRuntimeBlock(void*, int nbytes, HK_MEMORY_CLASS cl) = 0;
		virtual void freeRuntimeBlocks() = 0;
		virtual void reservePagesFromSystemMemory( int numBytes ) {}
        virtual void garbageCollect() {}
        virtual void optimize() {}
		virtual void releaseUnusedPagesToSystemMemory( void ) {}
		virtual void printStatistics(hkOstream* c) = 0;
		virtual int getAllocatedSize( int size );
		virtual bool isDebugMemory(){ return false; }
        virtual void calculateStatistics(hkMemoryStatistics& stats ) =0;
        virtual void setMemoryHardLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemoryHardLimit() { return 0; }
        virtual void setMemorySoftLimit(hk_size_t maxMemory) { }
        virtual hk_size_t getMemorySoftLimit() { return 0; }
        virtual void setLimitedMemoryListener(hkLimitedMemoryListener* listener) {}
        virtual hkLimitedMemoryListener* getLimitedMemoryListener() { return 0; }
        virtual hkBool hasMemoryAvailable(hk_size_t size) { return true; }
		virtual hkBool isOk() const;
		virtual void* findBaseAddress(void* p, int nbytes) { return 0; }
		virtual void lockBlock(void* p) {}
		virtual void unlockBlock(void* p) {}
        virtual hkResult walkMemory(hkMemoryWalkCallback callback,void* param) { return HK_FAILURE; }
		enum MemoryState
		{
			MEMORY_STATE_OK,
			MEMORY_STATE_OUT_OF_MEMORY
		};
		MemoryState m_memoryState;
		int m_criticalMemoryLimit;
        int m_memoryUsed;
		static inline hkMemory& __cdecl getInstance();
		static void __cdecl replaceInstance(hkMemory* m);
		__forceinline void addReference();
		__forceinline void removeReference();
		enum MemoryFill
		{
			MEMORY_FILL_GUARD_AREA = 0xFD,
			MEMORY_FILL_FREE_SPACE = 0xDD,
			MEMORY_FILL_RETURNED_TO_USER = 0xCD
		};
	protected:
		static hkMemory* s_instance;
		int m_referenceCount;
		struct BigBlockData
		{
			hkBool m_available;
			int m_size;
			void* m_memory;
			HK_MEMORY_CLASS m_class;
			hkBool m_providedByOutside;
		};
		enum { BIG_BLOCKS_SLOTS=128 };
		int m_numValidBigBlocks;
		BigBlockData m_bigBlockDataArray[BIG_BLOCKS_SLOTS];
	public:
		static hkInt32 s_fillGuardArea;
		static hkInt32 s_fillFreeSpace;
		static hkInt32 s_fillReturnedToUser;
};
hkMemory& __cdecl hkMemory::getInstance()
{
	return *s_instance;
}
__forceinline hkResult __cdecl hkpBvTreeAgent::calcAabbAndQueryTree( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkTransform& bTa, const hkVector4& linearTimInfo, const hkpProcessCollisionInput& input, hkAabb* cachedAabb, hkArray<hkpShapeKey>& hitListOut )
{
	hkAabb aabb;
	{
		const hkMotionState* msA = bodyA.getMotionState();
		const hkMotionState* msB = bodyB.getMotionState();
		hkVector4 timInfo;
		timInfo._setRotatedInverseDir( bodyB.getTransform().getRotation(), linearTimInfo );
		hkVector4 aabbExtents;
		if ( input.m_collisionQualityInfo->m_useContinuousPhysics )
		{
			hkReal secOrdErrA = ( msA->m_deltaAngle(3) + msB->m_deltaAngle(3) ) * msA->m_objectRadius;
			hkReal secOrdErrB = msB->m_deltaAngle(3) * msB->m_deltaAngle(3) * msB->m_objectRadius;
			hkReal checkEpsilon = input.m_tolerance * 0.5 + ( secOrdErrA + secOrdErrB );
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );
			hkVector4 massCenterAinB;
			{
				hkVector4 radius4; radius4.setAll3( msA->m_objectRadius + input.m_tolerance * 0.5 + secOrdErrB );
				massCenterAinB._setTransformedInversePos( bodyB.getTransform(), msA->getSweptTransform().m_centerOfMass1 );
				hkVector4 maxR; maxR.setAdd4( massCenterAinB, radius4 );
				hkVector4 minR; minR.setSub4( massCenterAinB, radius4 );
				aabb.m_min.setMax4( aabb.m_min, minR );
				aabb.m_max.setMin4( aabb.m_max, maxR );
			}
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
			{
				if ( msB->m_deltaAngle(3) > 0.0f )
				{
					hkVector4 relPos; relPos.setSub4( massCenterAinB, msB->getSweptTransform().m_centerOfMassLocal );
					hkVector4 offsetOut; offsetOut.setCross( relPos, msB->m_deltaAngle );
					hkReal f = input.m_stepInfo.m_deltaTime * msB->getSweptTransform().getInvDeltaTime();
					timInfo.addMul4( f, offsetOut );
				}
				hkVector4 zero; zero.setZero4();
				hkVector4 minPath; minPath.setMin4( zero, timInfo );
				hkVector4 maxPath; maxPath.setMax4( zero, timInfo );
				aabb.m_min.add4( minPath );
				aabb.m_max.add4( maxPath );
			}
		}
		else
		{
			hkReal checkEpsilon = input.m_tolerance * 0.5;
			bodyA.getShape()->getAabb( bTa, checkEpsilon, aabb );
			aabbExtents.setSub4( aabb.m_max, aabb.m_min );
		}
		if ( cachedAabb )
		{
			if ( cachedAabb->contains( aabb ) )
			{
				return HK_FAILURE;
			}
			hkVector4 zero; zero.setZero4();
			hkVector4 minPath; minPath.setMin4( zero, timInfo );
			hkVector4 maxPath; maxPath.setMax4( zero, timInfo );
			hkVector4 expand4; expand4.setAll3( input.m_tolerance * 0.5 );
			aabb.m_min.sub4( expand4 );
			aabb.m_max.add4( expand4 );
			hkReal maxExpand = 0.4f;
			hkReal framesLookAhead = -2.0f;
			hkVector4 minExtentPath; minExtentPath.setMul4( framesLookAhead, maxPath );
			hkVector4 maxExtentPath; maxExtentPath.setMul4( framesLookAhead, minPath );
			hkVector4 maxExpand4; maxExpand4.setMul4( maxExpand, aabbExtents );
			maxExtentPath.setMin4( maxExtentPath, maxExpand4 );
			hkVector4 minExpand4; minExpand4.setNeg4( maxExpand4 );
			minExtentPath.setMax4( minExtentPath, minExpand4 );
			aabb.m_min.add4( minExtentPath );
			aabb.m_max.add4( maxExtentPath );
			*cachedAabb = aabb;
		}
	}
	const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>( bodyB.getShape() );
	bvB->queryAabb( aabb, hitListOut );
	return HK_SUCCESS;
}
// pdb: hkpBvTreeStreamAgent::processCollision | hkpBvTreeStreamAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpBvTreeStreamAgent::hkpBvTreeStreamAgent_processCollision(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output)
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "L" "t" "BvTree3"; h->m_nameOfFirstSplit = "S" "t" "QueryTree"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	hkpAgent3ProcessInput in3;
	{
		in3.m_bodyA = &bodyA;
		in3.m_bodyB = &bodyB;
		in3.m_contactMgr = m_contactMgr;
		in3.m_input = &input;
		const hkMotionState* msA = bodyA.getMotionState();
		const hkMotionState* msB = bodyB.getMotionState();
		hkSweptTransformUtil::calcTimInfo( *msA, *msB, input.m_stepInfo.m_deltaTime, in3.m_linearTimInfo );
		in3.m_aTb.setMulInverseMul( msA->getTransform(), msB->getTransform() );
	}
	hkInplaceArray<hkpShapeKey,128> hitList;
	hitList.pushBackUnchecked( 0xffffffff );
	hkResult prepareSuccessful;
	{
		hkTransform bTa; bTa.setInverse( in3.m_aTb );
		prepareSuccessful = hkpBvTreeAgent::calcAabbAndQueryTree( bodyA, bodyB, bTa, in3.m_linearTimInfo, input, &m_cachedAabb, hitList );
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "S" "t" "Narrow"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
	if ( prepareSuccessful == HK_SUCCESS )
	{
		int newMemNeeded = ( hitList.getSize() / 4 + 1 - m_agentTrack.m_sectors.getSize() ) * hkpAgent1nSector::SECTOR_SIZE;
		if ( !hkMemory::getInstance().hasMemoryAvailable( newMemNeeded ) )
		{
			hkMemory::getInstance().m_memoryState = hkMemory::MEMORY_STATE_OUT_OF_MEMORY;
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return;
		}
		hkAlgorithm::quickSort( hitList.begin(), hitList.getSize() );
		const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>( bodyB.getShape() );
		const hkpShapeContainer* shapeContainer = bvB->getContainer();
		hkAgent1nMachine_Process( m_agentTrack, 0, in3, shapeContainer, hitList.begin(), output );
	}
	else {
		const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>( bodyB.getShape() );
		const hkpShapeContainer* shapeContainer = bvB->getContainer();
		hkAgent1nMachine_Process( m_agentTrack, 0, in3, shapeContainer, 0, output );
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "l" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

}  // namespace f3m_009b5ea0

// @f3 0x009a4d00 (community match, verified in this file)
#include <math.h>
namespace f3m_009a4d00 {
namespace f3m_009a4d00 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char	hkUint8;
typedef int hkBool32;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
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
typedef hkVector4Comparison hkVector4ComparisonParameter;
namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}
class hkMatrix3;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void subMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b ); 
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
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
		__forceinline hkVector4& getColumn(int i);
		__forceinline const hkVector4& getColumn(int i) const;
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
	protected:
		hkVector4 m_col0;
		hkVector4 m_col1;
		hkVector4 m_col2;
};
inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}
inline const hkReal& hkVector4::operator() (int i) const
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
	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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
inline hkVector4Comparison hkVector4::compareGreaterThan4(hkVector4Parameter a) const
{
	return a.compareLessThan4(*this);
}
inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
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
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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
struct hkpSurfaceConstraintInfo
{
	hkVector4 m_plane;
	hkVector4 m_velocity;
	hkReal m_staticFriction;
	hkReal m_extraUpStaticFriction;
	hkReal m_extraDownStaticFriction;
	hkReal    m_dynamicFriction;
	int		  m_priority;
};
struct hkpSimplexSolverInput
{
	hkVector4 m_position;
	hkVector4 m_velocity;
	hkVector4 m_maxSurfaceVelocity;
	hkVector4 m_upVector;
	hkReal	  m_deltaTime;
	hkReal	  m_minDeltaTime;
	hkpSurfaceConstraintInfo* m_constraints;
	int	m_numConstraints;
};
struct hkpSurfaceConstraintInteraction
{
	enum hkpStatus
	{
		HK_STATUS_OK = 0,
		HK_STATUS_3D_FAILURE = 1,
		HK_STATUS_2D_FAILURE = 2
	};
	hkUint8      m_touched;
	hkUint8      m_stopped;
	hkReal    m_surfaceTime;
	hkReal    m_penaltyDistance;	
	hkpStatus  m_status;
};
struct hkpSimplexSolverOutput
{
	hkVector4		  m_position;
	hkVector4		  m_velocity;
	hkReal			  m_deltaTime;
	hkpSurfaceConstraintInteraction* m_planeInteractions;
};
struct hkSimplexSolverActivePlanes
{
	int m_index;
	const hkpSurfaceConstraintInfo* m_constraint;
	hkpSurfaceConstraintInteraction* m_interaction;
};
struct hkSimplexSolverInfo
{
	hkpSurfaceConstraintInteraction& getOutput( const hkpSurfaceConstraintInfo* sci )
	{
		return m_output->m_planeInteractions[ sci - m_input->m_constraints ];
	}
	hkSimplexSolverActivePlanes m_supportPlanes[4];
	int m_numSupportPlanes;
	hkReal m_currentTime;
	const hkpSimplexSolverInput* m_input;
	hkpSimplexSolverOutput* m_output;
};
static void FUN_009a4830( const hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	const hkVector4& groundVelocity = sci.m_velocity;
	const hkReal staticFriction = sci.m_staticFriction;
	const hkReal dynamicFriction = sci.m_dynamicFriction;
	hkVector4 relativeVelocity; relativeVelocity.setSub4( velocityIn, groundVelocity );
	hkReal planeVel = relativeVelocity.dot3( sci.m_plane );
	const hkReal origVelocity2 = relativeVelocity.lengthSquared3();
	relativeVelocity.subMul4( planeVel, sci.m_plane );
	{
		const hkReal vp2 = planeVel * planeVel;
		hkReal extraStaticFriction = ( relativeVelocity.dot3( info.m_input->m_upVector ) > 0 ) ? sci.m_extraUpStaticFriction : sci.m_extraDownStaticFriction;
		if ( extraStaticFriction > 0 )
		{
			hkVector4 horizontal; horizontal.setCross( info.m_input->m_upVector, sci.m_plane );
			hkReal hor2 = horizontal.lengthSquared3();
			hkReal horVel = 0.0f;
			if ( hor2 > 1.192092896e-07F )
			{
				horizontal.mul4( hkMath::sqrtInverse( hor2 ) );
				horVel = relativeVelocity.dot3( horizontal );
				hkReal horVel2 = horVel * horVel;
				const hkReal f2 = staticFriction * staticFriction;
				if ( vp2 * f2 >= horVel2 )
				{
					relativeVelocity.subMul4( horVel, horizontal );
					horVel = 0.0f;
				}
			}
			{
				hkReal vertVel2 = origVelocity2 - horVel * horVel - vp2;
				const hkReal f2 = ( staticFriction + extraStaticFriction ) * ( staticFriction + extraStaticFriction );
				if ( vp2 * f2 >= vertVel2 )
				{
					if ( horVel == 0.0f )
					{
						velocityOut = groundVelocity;
						return;
					}
					relativeVelocity.setMul4( horVel, horizontal );
				}
			}
		}
		else
		{
			const hkReal f2 = staticFriction * staticFriction;
			if ( ( 1.0f + f2 ) * vp2 >= origVelocity2 )
			{
				velocityOut = groundVelocity;
				return;
			}
		}
	}
	if ( dynamicFriction < 1.0f )
	{
		hkReal velOut2 = relativeVelocity.lengthSquared3();
		if ( velOut2 >= 1.192092896e-07F )
		{
			if ( origVelocity2 * 0.001f < velOut2 )
			{
				hkReal f = hkMath::sqrt( origVelocity2 / velOut2 );
				f = dynamicFriction + ( 1.0f - dynamicFriction ) * f;
				relativeVelocity.mul4( f );
				hkReal p = sci.m_plane.dot3( relativeVelocity );
				relativeVelocity.subMul4( p, sci.m_plane );
			}
		}
	}
	velocityOut.setAdd4( relativeVelocity, groundVelocity );
}
// pdb: hkSimplexSolverSolve2d | hkpSimplexSolver.obj | tesv_win, call_dedup, low
static void FUN_009a4d00( hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci0, const hkpSurfaceConstraintInfo& sci1, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	hkVector4 axis; axis.setCross( sci0.m_plane, sci1.m_plane );
	hkReal axisLen2 = axis.lengthSquared3();
	if ( axisLen2 <= 1.192092896e-07F )
	{
hkSimplexSolverSolve2dSolveSequentually:
		info.getOutput( &sci0 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_2D_FAILURE;
		info.getOutput( &sci1 ).m_status = hkpSurfaceConstraintInteraction::HK_STATUS_2D_FAILURE;
		if ( sci0.m_priority > sci1.m_priority )
		{
			FUN_009a4830( info, sci1, velocityIn, velocityOut );
			FUN_009a4830( info, sci0, velocityOut, velocityOut );
		}
		else
		{
			FUN_009a4830( info, sci0, velocityIn, velocityOut );
			FUN_009a4830( info, sci1, velocityOut, velocityOut );
		}
		return;
	}
	hkReal invAxisLen = hkMath::sqrtInverse( axisLen2 );
	axis.mul4( invAxisLen );
	hkVector4 axisVel;
	{
		hkMatrix3 m;
		hkVector4& r0 = m.getColumn(0);
		hkVector4& r1 = m.getColumn(1);
		hkVector4& r2 = m.getColumn(2);
		r0.setCross( sci0.m_plane, sci1.m_plane );
		r1.setCross( sci1.m_plane, axis );
		r2.setCross( axis, sci0.m_plane );
		hkVector4 sVel; sVel.setAdd4( sci0.m_velocity, sci1.m_velocity );
		hkVector4 t; t.set( 0.5f * axis.dot3( sVel ), sci0.m_plane.dot3( sci0.m_velocity ), sci1.m_plane.dot3( sci1.m_velocity ) );
		axisVel._setMul3( m, t );
		axisVel.mul4( invAxisLen );
		hkVector4 absVel; absVel.setAbs4( axisVel );
		if ( absVel.compareGreaterThan4( info.m_input->m_maxSurfaceVelocity ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
		{
			goto hkSimplexSolverSolve2dSolveSequentually;
		}
	}
	const hkVector4& groundVelocity = axisVel;
	hkVector4 relativeVelocity; relativeVelocity.setSub4( velocityIn, groundVelocity );
	const hkReal vel2 = relativeVelocity.lengthSquared3();
	const hkReal axisVert = info.m_input->m_upVector.dot3( axis );
	hkReal axisProjVelocity = relativeVelocity.dot3( axis );
	hkReal staticFriction = sci0.m_staticFriction + sci1.m_staticFriction;
	if ( axisVert * axisProjVelocity > 0 )
	{
		staticFriction += ( sci0.m_extraUpStaticFriction + sci1.m_extraUpStaticFriction ) * axisVert;
	}
	else
	{
		staticFriction += ( sci0.m_extraDownStaticFriction + sci1.m_extraDownStaticFriction ) * axisVert;
	}
	staticFriction *= 0.5f;
	const hkReal dynamicFriction = ( sci0.m_dynamicFriction + sci1.m_dynamicFriction ) * 0.5f;
	{
		const hkReal f2 = staticFriction * staticFriction;
		const hkReal av2 = axisProjVelocity * axisProjVelocity;
		if ( ( vel2 - av2 ) * f2 >= av2 )
		{
			velocityOut = groundVelocity;
			return;
		}
	}
	if ( dynamicFriction < 1.0f )
	{
		if ( axisProjVelocity * axisProjVelocity > 0.001f * vel2 )
		{
			hkReal f = hkMath::sqrt( vel2 ) * hkMath::fabs( 1.0f / axisProjVelocity );
			f = dynamicFriction + ( 1.0f - dynamicFriction ) * f;
			axisProjVelocity *= f;
		}
	}
	velocityOut.setAddMul4( groundVelocity, axis, axisProjVelocity );
}
void f3m_009a4d00_call( hkSimplexSolverInfo& info, const hkpSurfaceConstraintInfo& sci0, const hkpSurfaceConstraintInfo& sci1, const hkVector4& velocityIn, hkVector4& velocityOut )
{
	FUN_009a4d00( info, sci0, sci1, velocityIn, velocityOut );
}

}
}   // namespace f3m_009a4d00

// @f3 0x009a0160 (community match, verified in this file)
// 0x009a0160: Havok 5.5.0 hkpTriangleShape::weldContactPointImpl (hkpCollide.lib, hkpTriangleShape.obj).
// Written from the SDK's hybrid records on the SDK's own FPU inline definitions; the unmodified source gives the
// release library's 2141 bytes (hkcheck MATCH). The game's copy differs from that SDK build in one statement:
// hkpWeldingUtility::snapCollisionNormal ends with normalize3() where this SDK build has normalize4().
// Out-of-line callees and tables carry the game's symbol names.
typedef float  hkReal;
typedef signed short	hkInt16;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
class hkClass;

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
	private:
		TYPE m_storage;
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

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;

#include <math.h>


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline hkReal __cdecl FUN_0090d870( hkReal x, hkReal y)
	{
		return x < y ? x : y;
	}
}

class hkRotation;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		void hkVector4_setRotatedDir(const hkRotation& a, const hkVector4& b);
		void FUN_00477880(const hkRotation& a, const hkVector4& b);
		void hkVector4_setTransformedPos(const hkTransform& a, const hkVector4& b);
		void FUN_008d2970(const hkTransform& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
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
		__forceinline const hkRotation& getRotation() const;
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
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

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (x*x) + (y*y) + (z*z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}

	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );
	}

inline void hkVector4::FUN_00477880(const hkRotation& t, const hkVector4& v)
{
	_setRotatedInverseDir(t,v);
}

const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

class hkSphere
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		hkVector4 m_pos;
};

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
		hkEnum< ::hkpShapeType, hkUint32> m_type;
};

class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
};

class hkpConvexShape : public hkpSphereRepShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
		__forceinline void getCentre( hkVector4& centreOut ) const;
		virtual hkReal getMaximumProjection( const hkVector4& direction ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	protected:
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const = 0;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const = 0;
		virtual int weldContactPointImpl(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
	protected:
		hkReal m_radius;
};

void hkpConvexShape::getCentre( hkVector4& centreOut ) const
{
	return this->getCentreImpl( centreOut );
}

class hkpWeldingUtility
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum WeldingType
		{
			WELDING_TYPE_ANTICLOCKWISE = 0,
			WELDING_TYPE_CLOCKWISE = 4,
			WELDING_TYPE_TWO_SIDED = 5,
			WELDING_TYPE_NONE = 6
		};
		enum SectorType
		{
			ACCEPT_0	= 1,
			SNAP_0		= 0,
			REJECT		= 2,
			SNAP_1		= 4,
			ACCEPT_1	= 3
		};
		static __forceinline void calcSnapVector( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& snapVectorOut );
		static __forceinline SectorType getSector(const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode);
		static __forceinline void snapCollisionNormal( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& collisionNormalInOut );
		static __forceinline hkBool shouldSnapOneSided(hkpWeldingUtility::WeldingType weldingType, const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode );
		static __forceinline void calcSnapVectorOneSided( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, hkpWeldingUtility::WeldingType weldingType, hkVector4& snapVectorOut );
		enum NumAngles
		{
			NUM_ANGLES = 31
		};
	public:
		struct SinCosTableEntry
		{
			                class MustEndWithSemiColon;
			hkReal m_cosAccept0;
			hkReal m_sinAccept0;
			hkReal m_cosSnap0;
			hkReal m_cosSnap1;
			hkReal m_cosAccept1;
			hkReal m_sinAccept1;
		};
};

extern "C" __declspec(align(16)) hkpWeldingUtility::SinCosTableEntry DAT_0116bf50[hkpWeldingUtility::NUM_ANGLES+1];

hkpWeldingUtility::SectorType hkpWeldingUtility::getSector(const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode )
{
	hkReal cosAngle = triangleNormal.dot3(collisionNormal);
	if      ( cosAngle >= DAT_0116bf50[edgeBitcode].m_cosAccept0 )
	{
		return hkpWeldingUtility::ACCEPT_0;
	}
	else if ( cosAngle >= DAT_0116bf50[edgeBitcode].m_cosSnap0 )
	{
		return hkpWeldingUtility::SNAP_0;
	}
	else if ( cosAngle >= DAT_0116bf50[edgeBitcode].m_cosSnap1 )
	{
		return hkpWeldingUtility::REJECT;
	}
	else if ( cosAngle >= DAT_0116bf50[edgeBitcode].m_cosAccept1 )
	{
		return hkpWeldingUtility::SNAP_1;
	}
	return hkpWeldingUtility::ACCEPT_1;
}

hkBool hkpWeldingUtility::shouldSnapOneSided(hkpWeldingUtility::WeldingType weldingType, const hkVector4& triangleNormal, const hkVector4& collisionNormal, int edgeBitcode )
{
	hkReal cosAngle = triangleNormal.dot3(collisionNormal);
	hkReal* sinCosTableEntry = &DAT_0116bf50[edgeBitcode].m_cosAccept0;
	return (weldingType == hkpWeldingUtility::WELDING_TYPE_ANTICLOCKWISE) ? cosAngle < sinCosTableEntry[weldingType] : cosAngle > sinCosTableEntry[weldingType];
}

void hkpWeldingUtility::calcSnapVector( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& snapVectorOut )
{
	hkVector4 orthNormalEdge; orthNormalEdge.setCross(edge, triangleNormal);
	hkReal* sinCosTableEntry = &DAT_0116bf50[edgeBitcode].m_cosAccept0;
	hkVector4 hVec0; hVec0.setMul4( sinCosTableEntry[sector+0], triangleNormal );
	hkVector4 hVec1; hVec1.setMul4( sinCosTableEntry[sector+1], orthNormalEdge );
	snapVectorOut.setAdd4(hVec0, hVec1);
	snapVectorOut.normalize3();
}

void hkpWeldingUtility::calcSnapVectorOneSided( const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, hkpWeldingUtility::WeldingType weldingType, hkVector4& snapVectorOut )
{
	calcSnapVector(triangleNormal, edge, edgeBitcode, (SectorType) weldingType, snapVectorOut );
}

void hkpWeldingUtility::snapCollisionNormal(const hkVector4& triangleNormal, const hkVector4& edge, int edgeBitcode, SectorType sector, hkVector4& collisionNormalInOut )
{
	hkVector4 snapVector; calcSnapVector( triangleNormal, edge, edgeBitcode, sector, snapVector );
	hkSimdReal dot0 = snapVector.dot3(collisionNormalInOut);
	hkSimdReal dot1 = edge.dot3(collisionNormalInOut);
	{
		hkVector4 hVec0; hVec0.setMul4(dot0, snapVector);
		hkVector4 hVec1; hVec1.setMul4(dot1, edge);
		collisionNormalInOut.setAdd4(hVec0, hVec1);
		collisionNormalInOut.normalize3();
	}
	return;
}

class hkpTriangleShape : public hkpConvexShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const { return sizeof(*this); };
		__forceinline const hkVector4& getVertex(int i) const;
		virtual void getSupportingVertexImpl(  hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void convertVertexIdsToVerticesImpl(  const hkpVertexId* ids, int numIds, hkpCdVertex* verticesOut) const;
		virtual int FUN_009a0160(  hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const;
		virtual void getCentreImpl(  hkVector4& centreOut ) const;
		virtual int getNumCollisionSpheresImpl(  ) const;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& results) const;
		virtual void getFirstVertex(hkVector4& v) const;
		virtual void calcStatistics( hkStatisticsCollector* collector) const;
	protected:
		hkUint16 m_weldingInfo;
		hkEnum<hkpWeldingUtility::WeldingType, hkUint8> m_weldingType;
		hkUint8 m_isExtruded;
		hkVector4 m_vertexA;
		hkVector4 m_vertexB;
		hkVector4 m_vertexC;
		hkVector4 m_extrusion;
};

const hkVector4& hkpTriangleShape::getVertex(int i) const
{
	return (&m_vertexA)[i];
}

extern "C" int DAT_01060f20[];
extern "C" hkReal DAT_01060f0c[];

static inline void FUN_0099f710(const hkVector4& vertex0, const hkVector4& vertex1, const hkVector4& vertex2, hkVector4& normal)
{
	hkVector4 edges[2];
	edges[0].setSub4(vertex1, vertex0);
	edges[1].setSub4(vertex2, vertex1);
	normal.setCross(edges[0], edges[1]);
	normal.normalize3();
}

int hkpTriangleShape::FUN_009a0160( hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs, const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut ) const
{
	const hkpTriangleShape* thisObj = this;
	hkpWeldingUtility::WeldingType weldingType = thisObj->m_weldingType;
	if ( weldingType == hkpWeldingUtility::WELDING_TYPE_NONE )
	{
		return hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
	}
	int edgeId0 = DAT_01060f20[ featurePoints[0] ];
	int edgeId1;
	if ( numFeaturePoints > 1 )
	{
		edgeId1 = DAT_01060f20[ featurePoints[1] ];
		if ( numFeaturePoints == 3 )
		{
			if ( featurePoints[0] + featurePoints[1] + featurePoints[2] == 3 )
			{
				return hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
			}
			if ( edgeId1 == edgeId0 )
			{
				edgeId1 = DAT_01060f20[ featurePoints[2] ];
			}
			numFeaturePoints = 2;
			featurePoints[0] = hkpVertexId(edgeId0);
			featurePoints[1] = hkpVertexId(edgeId1);
		}
		if ( DAT_01060f20[ edgeId0 + 1 ] != edgeId1 )
		{
			edgeId0 = edgeId1;
		}
	}
	edgeId1 = DAT_01060f20[ edgeId0 + 1 ];
	hkVector4 sepNormal = separatingNormalInOut;
	hkVector4 sepNormalLocal; sepNormalLocal.FUN_00477880( thisObjTransform->getRotation(), sepNormal );
	hkVector4 triangleNormal; FUN_0099f710( thisObj->m_vertexA, thisObj->m_vertexB, thisObj->m_vertexC, triangleNormal );
	const hkReal cosSnapAngle = hkMath::fabs( sepNormalLocal.dot3( triangleNormal ) );
	hkReal penetrationDist = sepNormal(3);
	penetrationDist *= cosSnapAngle;
	hkVector4 edge; edge.setSub4( thisObj->getVertex(edgeId1), thisObj->getVertex(edgeId0) );
	edge.normalize3();
	int edgeBitcode = ( thisObj->m_weldingInfo >> ( edgeId0 * 5 ) ) & 0x1f;
	if ( weldingType != hkpWeldingUtility::WELDING_TYPE_TWO_SIDED )
	{
		if ( hkpWeldingUtility::shouldSnapOneSided( weldingType, triangleNormal, sepNormalLocal, edgeBitcode ) )
		{
			hkpWeldingUtility::calcSnapVectorOneSided( triangleNormal, edge, edgeBitcode, weldingType, sepNormal );
			sepNormal.hkVector4_setRotatedDir( thisObjTransform->getRotation(), sepNormal );
			if ( thisObj->m_isExtruded )
			{
				{
				triangleNormal.mul4( DAT_01060f0c[ weldingType ] );
				hkVector4 contactPointLocal; contactPointLocal.FUN_008d2970( *thisObjTransform, contactPointWs );
				hkVector4 depthVec; depthVec.setSub4( contactPointLocal, thisObj->getVertex(0) );
				hkReal depth = depthVec.dot3( triangleNormal );
				penetrationDist = hkMath::FUN_0090d870( depth, penetrationDist );
				}
RETURN_ACCEPT_CONTACT_POINT_MODIFIED:
				separatingNormalInOut = sepNormal;
				separatingNormalInOut(3) = penetrationDist;
				return hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED;
			}
			else
			{
				hkVector4 centreOfObjectA; collidingShape->getCentre( centreOfObjectA );
				centreOfObjectA.hkVector4_setTransformedPos( *collidingTransform, centreOfObjectA );
				hkVector4 centreToPlane; centreToPlane.setSub4( contactPointWs, centreOfObjectA );
				if ( sepNormal.dot3( centreToPlane ) <= 0.0f )
				{
					goto RETURN_ACCEPT_CONTACT_POINT_MODIFIED;
				}
				return hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT;
			}
		}
	}
	else
	{
		hkpWeldingUtility::SectorType sector = hkpWeldingUtility::getSector( triangleNormal, sepNormal, edgeBitcode );
		switch ( sector )
		{
		case hkpWeldingUtility::SNAP_0:
		case hkpWeldingUtility::SNAP_1:
			break;
		case hkpWeldingUtility::REJECT:
			return hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT;
		default:
			return hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
		}
		hkpWeldingUtility::snapCollisionNormal( triangleNormal, edge, edgeBitcode, sector, sepNormal );
		goto RETURN_ACCEPT_CONTACT_POINT_MODIFIED;
	}
	return hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
}

// @f3 0x009bbf40 (community match, verified in this file)
// hkpHeightFieldAgent_processCollision = Havok 5.5.0 hkpHeightFieldAgent::processCollision (hkpCollide.lib, hkpHeightFieldAgent.obj).
// Body reconstructed from the hybrid library object's debug records on the SDK's own inline bodies; cut with hktrim.py.
// The member is renamed hkpHeightFieldAgent_processCollision (the pack symbol) inside namespace f3m_009bbf40.
extern "C" {
	__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
namespace f3m_009bbf40 {
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

typedef hkReal hkTime;
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
		__forceinline operator TYPE() const
		{
			return val();
		}
	private:
		TYPE m_storage;
};


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
		void setSize(int n, const T& fill);
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
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

template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}

typedef hkReal hkSimdRealParameter;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
#pragma pack(push,8)
#pragma pack(push,8)
#pragma pack(pop)
#pragma pack(pop)
#pragma pack(push,8)
#pragma pack(pop)
#pragma pack(push,8)
#pragma pack(pop)
class hkMatrix3;
class hkRotation;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline void setW(const hkVector4& v);
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
		__forceinline hkVector4& getColumn(int i);
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
		__forceinline hkTransform() { }
		__forceinline hkTransform(const hkTransform& r);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkRotation& getRotation() const;
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
	private:
		hkRotation m_rotation;
		hkVector4 m_translation;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
	return (&x)[i];
}

__forceinline void hkVector4::setW(const hkVector4& v)
{
	w = v.w;
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
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}

class hkMonitorStream
{
	public:
		                class MustEndWithSemiColon;
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
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

class hkTimeFunctionHelper
{
	public:
		__forceinline ~hkTimeFunctionHelper()
		{
			// Expanded HK_TIMER_END() from hkMonitorStream.inl.
			{
				hkMonitorStream& mStream = hkMonitorStream::getInstance();
				if ( mStream.memoryAvailable() )
				{
					hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
					h->m_commandAndMonitor = "E" "t" "";
					h->setTime();
					mStream.setEnd( (char*)(h+1) );
				}
			}
		}
};

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

class hkSphere
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkReal getRadius() const;
		inline const hkVector4& getPosition() const;
		inline const hkVector4& getPositionAndRadius() const;
		inline hkVector4& getPositionAndRadius();
	protected:
		hkVector4 m_pos;
};

inline hkReal hkSphere::getRadius() const
{
	return m_pos(3);
}

inline const hkVector4& hkSphere::getPosition() const
{
	return m_pos;
}

inline const hkVector4& hkSphere::getPositionAndRadius() const
{
	return m_pos;
}

inline hkVector4& hkSphere::getPositionAndRadius()
{
	return m_pos;
}

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkVector4& getPosition();
		inline hkVector4& getSeparatingNormal();
		inline void setDistance( hkReal d );
	protected:
		                class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};

inline hkVector4& hkContactPoint::getPosition()
{
	return m_position;
}

inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}

inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}

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
		hkEnum< ::hkpShapeType, hkUint32> m_type;
};

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
		__forceinline const hkTransform& getTransform() const;
		__forceinline const hkpShape* getShape() const;
	public:
		const hkpShape*       m_shape;
		hkpShapeKey           m_shapeKey;
		const void* m_motion;
		const hkpCdBody*		 m_parent;
};

const hkTransform& hkpCdBody::getTransform() const
{
	return *static_cast<const hkTransform*>(m_motion);
}

const hkpShape* hkpCdBody::getShape() const
{
	return m_shape;
}

struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpCollisionQualityInfo;
class hkpConstraintOwner;

struct hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
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

class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct hkpLinearCastCollisionInput;
struct hkpProcessCollisionData;
class hkpGskCache;

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};

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

class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
};

__declspec(align(16)) class hkContactPointPropertiesWithExtendedUserData16 : public hkpContactPointProperties
{
	public:
		                class MustEndWithSemiColon;
		hkpContactPointProperties::UserData m_extendedUserDatas[7];
};

class hkpContactMgr: public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
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
		__forceinline hkContactPointId addContactPoint( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp );
		__forceinline void removeContactPoint( hkContactPointId cpId, hkpConstraintOwner& constraintOwner );
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

hkContactPointId hkpContactMgr::addContactPoint( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& output, const hkpGskCache* contactCache, hkContactPoint& cp )
{
	return addContactPointImpl( a, b, input, output, contactCache, cp );
}

void hkpContactMgr::removeContactPoint( hkContactPointId cpId, hkpConstraintOwner& constraintOwner )
{
	removeContactPointImpl( cpId, constraintOwner );
}

struct hkpProcessCdPoint
{
	                class MustEndWithSemiColon;
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
};

class hkpCollisionAgent : public hkReferencedObject
{
	public:
		                class MustEndWithSemiColon;
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector  ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector ) = 0;
	public:
		virtual void processCollision( const hkpCdBody& a, const hkpCdBody& b, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& result ) = 0;
		virtual void cleanup(hkpConstraintOwner& info) = 0;
		virtual void updateShapeCollectionFilter( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpConstraintOwner& constraintOwner ) {}
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
};

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

class hkpGskCache
{
	public:
		                class MustEndWithSemiColon;
		hkUint16  m_vertices[4];
		hkUint8	  m_dimA;
		hkUint8	  m_dimB;
		enum MaxDim
		{
			MAX_DIM_MAX = 15
		};
		hkUint8	  m_maxDimA : 4;
		hkUint8	  m_maxDimB : 4;
		typedef hkUint8 GskFlags;
		enum GskFlagValues
		{
			GSK_FLAGS_SHAPE_A_IS_CYLINDER           = 0x01,
			GSK_FLAGS_SHAPE_B_IS_CYLINDER           = 0x02,
			GSK_FLAGS_REPLACE_SHAPE_A_WITH_CAPSULE  = 0x04,
			GSK_FLAGS_REPLACE_SHAPE_B_WITH_CAPSULE  = 0x08,
			GSK_FLAGS_CYLINDER_AGENT_FLAGS          = 0x0f,
			GSK_FLAGS_DISABLE_CONTACT_TIMS     = 0x10,
			GSK_FLAGS_CONVEX_LIST_IN_GSK_MODE  = 0x20,
			GSK_FLAGS_PROCESS_FUNCTION_CALLED  = 0x40,
			ONE_BIT_STILL_UNUSED     = 0x80
		};
		hkUint8 m_gskFlags;
};

__declspec(align(16)) class hkGskCache16 : public hkpGskCache
{
	public:
		                class MustEndWithSemiColon;
};

	enum {HK_MAX_CONTACT_POINT = 256 };

struct hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkPadSpu<hkpProcessCdPoint*> m_firstFreeContactPoint;
		hkPadSpu<hkpConstraintOwner*> m_constraintOwner;
		hkpProcessCdPoint   m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
				                class MustEndWithSemiColon;
			public:
				hkContactPoint     m_contactPoint;
				hkPadSpu<hkReal>   m_time;
				hkPadSpu<hkReal>      m_seperatingVelocity;
				hkGskCache16			m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
};

struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
		inline hkpProcessCdPoint* reserveContactPoints( int numberOfPoints=1 )
		{
			return m_firstFreeContactPoint;
		}
		inline void commitContactPoints( int numberOfPoints=1 )
		{
			m_firstFreeContactPoint= m_firstFreeContactPoint + numberOfPoints;
		}
	public:
		struct ContactRef
		{
			                class MustEndWithSemiColon;
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry*		m_agentEntry;
			void*			    m_agentData;
		};
		struct PotentialInfo
		{
			                class MustEndWithSemiColon;
			ContactRef*        m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint*  m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef         m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*>    m_potentialContacts;
};

class hkpHeightFieldAgent : public hkpCollisionAgent
{
	public:
        void hkpHeightFieldAgent_processCollision(const hkpCdBody& csBody, const hkpCdBody& hfBody, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& processOutput);
		virtual void getPenetrations(const  hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector);
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector );
		virtual void cleanup( hkpConstraintOwner& constraintOwner );
	protected:
		hkpHeightFieldAgent(const hkpCdBody& A,const  hkpCdBody& B,const  hkpCollisionInput& input, hkpContactMgr* mgr);
		~hkpHeightFieldAgent(){}
	protected:
		hkArray<hkContactPointId> m_contactPointId;
};

class hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
	                class MustEndWithSemiColon;
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};

class hkpHeightFieldShape: public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		struct CollideSpheresInput
		{
			                class MustEndWithSemiColon;
			class hkSphere* m_spheres;
			int		  m_numSpheres;
			hkReal	  m_tolerance;
		};
		typedef hkVector4 SphereCollisionOutput;
		virtual void collideSpheres( const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const = 0;
		struct hkpSphereCastInput: public hkpShapeRayCastInput
		{
			                class MustEndWithSemiColon;
			hkReal m_radius;
			hkReal m_maxExtraPenetration;
		};
		virtual void castSphere( const hkpSphereCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
};

class hkpSphereRepShape : public hkpShape
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline int getNumCollisionSpheres( )  const;
		__forceinline const hkSphere* getCollisionSpheres( hkSphere* sphereBuffer ) const;
	protected:
		virtual int getNumCollisionSpheresImpl(  )  const = 0;
		virtual const hkSphere* getCollisionSpheresImpl(  hkSphere* sphereBuffer ) const = 0;
};

const hkSphere* hkpSphereRepShape::getCollisionSpheres( hkSphere* sphereBuffer ) const
{
	return this->getCollisionSpheresImpl( sphereBuffer );
}

namespace hkVector4Util
{
	__forceinline void __cdecl transformSpheres( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut );
	__forceinline void __cdecl checkRegisters( hkUint32 registerMask );
}

__forceinline void __cdecl hkVector4Util::checkRegisters( hkUint32 registerMask )
{
}

inline void __cdecl hkVector4Util::transformSpheres( const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut )
{
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		hkVector4 v;
		v._setTransformedPos( unaliased, vectorsIn[i] );
		v.setW(vectorsIn[i]);
		vectorsOut[i] = v;
	} while( --i >= 0 );
}


// pdb: hkpHeightFieldAgent::processCollision | hkpHeightFieldAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void hkpHeightFieldAgent::hkpHeightFieldAgent_processCollision(const hkpCdBody& csBody, const hkpCdBody& hfBody, const hkpProcessCollisionInput& input, hkpProcessCollisionOutput& processOutput)
{
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "T" "t" "HeightField"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } }
	hkTimeFunctionHelper timeblock96; // HK_TIME_CODE_BLOCK at original source line 96.
	const hkpSphereRepShape* csShape = static_cast<const hkpSphereRepShape*>(csBody.getShape());
	const hkpHeightFieldShape* hfShape = static_cast<const hkpHeightFieldShape*>(hfBody.getShape());
	hkTransform bTa; bTa.setMulInverseMul( hfBody.getTransform(), csBody.getTransform() );
	const int numSpheres = m_contactPointId.getSize();
	hkSphere* sphereBuffer = hkAllocateStack<hkSphere>( numSpheres );
	hkContactPointId* cpId = m_contactPointId.begin();
	{
		const hkSphere* spheres = csShape->getCollisionSpheres( sphereBuffer );
		hkVector4Util::transformSpheres( bTa, reinterpret_cast<const hkVector4*>(spheres), numSpheres, reinterpret_cast<hkVector4*>(sphereBuffer) );
	}
	hkVector4* out2 = hkAllocateStack<hkVector4>( numSpheres );
	{
		hkpHeightFieldShape::CollideSpheresInput in2;
		in2.m_spheres = sphereBuffer;
		in2.m_numSpheres = numSpheres;
		in2.m_tolerance = input.m_tolerance;
		hfShape->collideSpheres( in2, out2 );
	}
	{
		hkVector4* outP = out2;
		hkSphere* sphereP = sphereBuffer;
		hkReal tolerance = input.m_tolerance;
		for (int i = numSpheres-1; i >= 0; i--)
		{
			if ( (*outP)(3) > tolerance )
			{
				if ( *cpId != (0xffff) )
				{
					m_contactMgr->removeContactPoint( *cpId, *processOutput.m_constraintOwner.val() );
					*cpId = (0xffff);
				}
			}
			else
			{
				hkpProcessCdPoint& point = *processOutput.reserveContactPoints(1);
				hkVector4 position; position.setAddMul4( sphereP->getPosition(), *outP, -sphereP->getRadius() );
				point.m_contact.getPosition()._setTransformedPos( hfBody.getTransform(), position );
				point.m_contact.getSeparatingNormal()._setRotatedDir( hfBody.getTransform().getRotation(), *outP );
				point.m_contact.setDistance( (*outP)(3) );
				if ( *cpId == (0xffff) )
				{
					*cpId = m_contactMgr->addContactPoint( csBody, hfBody, input, processOutput, 0, point.m_contact );
					if ( *cpId == (0xffff) )
					{
					}
					else
					{
						processOutput.commitContactPoints(1);
					}
				}
				else
				{
					processOutput.commitContactPoints(1);
				}
				point.m_contactPointId = *cpId;
			}
			sphereP++;
			outP++;
			cpId++;
		}
	}
	hkDeallocateStack( out2 );
	hkDeallocateStack( sphereBuffer );
}

} // namespace f3m_009bbf40
