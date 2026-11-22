#include "f3_common.h"
// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTriSampledHeightFieldBvTreeShape.h"

// ---------------------------------------------------------------------------
// hkpShape is only forward declared by the pack's headers, so complete it
// here.  hkBaseObject contributes the virtual destructor, which sits in the
// first vtable slot; the four shape virtuals follow it, so the one the
// container forwards to ends up at vtable offset 0x10.
// ---------------------------------------------------------------------------
class hkpShape : public hkBaseObject
{
  public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

struct hkResultD26B
{
    int m_00;
    hkResultD26B()
    {}
};

extern void __cdecl ComputeAabbFromTransform(int, int, float, char*);

class FUN_00d268f0_Shape
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void ProcessBuffer(int, int, float, int);
    virtual void CollectHits(char*, int);
};

// Calls ComputeAabbFromTransform(a, b, c, &buffer), then calls CollectHits with that buffer and d.
// @f3 0x009a82c0 (community match, verified in this file)
struct Task1475Bounds {float minX,minY,minZ,minW,maxX,maxY,maxZ,maxW;};
struct Task1475ShapeView {
 virtual void slot00();
 virtual void slot04();
 virtual void slot08();
 virtual void slot0c();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1c();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void CollectHits(char*,int);
};
void __thiscall FUN_00d268f0_Shape::ProcessBuffer(int a,int b,float c,int d){
 __declspec(align(16)) Task1475Bounds buffer;
 ComputeAabbFromTransform(a,b,c,reinterpret_cast<char*>(&buffer));
 reinterpret_cast<Task1475ShapeView*>(this)->CollectHits(reinterpret_cast<char*>(&buffer),d);
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct hkMemory;

struct hkThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemory* m_pMemoryAllocator;
};

extern "C" hkThreadMemory* FUN_00c85750();
extern "C" void ResizeAudioStream(hkMemory* memory, void* array, int elemSize);
extern "C" void FUN_00c908c0(hkMemory* memory, void* array, int numElements, int elemSize);

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

struct hkShapeKeyArray
{
    hkUint32* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void AddBack(const hkUint32& e)
    {
        hkThreadMemory* tm = FUN_00c85750();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(tm->m_pMemoryAllocator, this, sizeof(hkUint32));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }

    __forceinline void SetSizeAndGrow(int n)
    {
        hkThreadMemory* tm = FUN_00c85750();
        hkMemory* memory = tm->m_pMemoryAllocator;
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(memory, this, newSize, sizeof(hkUint32));
        }
        m_iElementCount = n;
    }
};

class hkpSampledHeightFieldShapeq
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual hkReal getHeightAt(int x, int z) const;

    int m_pad04[7];
    hkReal m_kHeightScaleVector[4];
};

class hkpTriSampledHeightFieldCollectionq
{
  public:
    const hkpSampledHeightFieldShapeq* FUN_00d26450() const;
};

struct hkBoolq
{
    char m_cBooleanValue;
    hkBoolq(bool b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

__declspec(noalias) hkBoolq FUN_00d26940(const hkAabbq* aabb, const hkpTriSampledHeightFieldCollectionq* collection,
                                         hkUint32* minX, hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ);

struct TriSampledHeightFieldBvTreeShapeq : public hkpTriSampledHeightFieldBvTreeShape
{
    __forceinline const hkpTriSampledHeightFieldCollectionq* getShapeCollection() const
    {
        return reinterpret_cast<const hkpTriSampledHeightFieldCollectionq*>(m_kChildContainer.m_pContainedShape);
    }
    void CollectHits(const hkAabbq& aabbIn, hkShapeKeyArray& hits) const;
};

// Appends shape keys for grid cells overlapping aabbIn to hits; with bounds checking, drops them if all sampled heights are above or below the AABB.
// @f3 0x009a88c0 (community match, verified in this file)
namespace hk9a88c0
{
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
		typedef unsigned __int64 hkUint64;
		typedef __int64 hkInt64;
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
		inline hkBool& operator=(bool e)
		{
			m_bool = static_cast<char>(e);
			return *this;
		}
	private:
		char m_bool;
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
	private:
		TYPE m_storage;
};

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
		__forceinline void removeReference() const;
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
	void __cdecl FUN_00901e90(void*, int numElem, int sizeElem);
	void __cdecl FUN_00901f10(void* array, int sizeElem);
	void __cdecl _reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}

template <typename T> class hkObjectArray;

template <typename T>
class hkArray
{
		friend void __cdecl hkArrayUtil::FUN_00901e90(void*, int numElem, int sizeElem);
		friend void __cdecl hkArrayUtil::FUN_00901f10(void* array, int sizeElem);
		friend void __cdecl hkArrayUtil::_reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
		friend class hkObjectArray< hkArray<T> >;
		friend class hkArraySpu;
	public:
	public:
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void pushBack(const T& e);
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
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

template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}

template <typename T>
__forceinline void hkArray<T>::reserve(int n)
{
	const int capacity = getCapacity();
	if( capacity < n)
	{
		int cap2 = 2 * capacity;
		int newSize = (n < cap2) ? cap2 : n;
		hkArrayUtil::FUN_00901e90(this, newSize, sizeof(T));
	}
}

template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::FUN_00901f10( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}

template <typename T>
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}

class hkVector4;
typedef const hkVector4& hkVector4Parameter;

struct hkQuadReal
{
	__declspec(align(16)) hkReal x;
	hkReal y;
	hkReal z;
	hkReal w;
};

extern const hkQuadReal DAT_01092a50;
class hkTransform;

class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setAll(hkReal x);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMin4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMax4(const hkVector4& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkQuadReal& getQuad();
		__forceinline static const hkVector4& __cdecl getZero();
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkQuadReal& hkVector4::getQuad()
{
	return reinterpret_cast<hkQuadReal&>(x);
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

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	w = a.w * b.w;
}

inline void hkVector4::mul4(const hkVector4& a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
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

inline const hkVector4& __cdecl hkVector4::getZero()
{
	const hkVector4& zero = *reinterpret_cast<const hkVector4*>(&DAT_01092a50);
	return zero;
}

class hkAabb
{
	public:
	public:
		hkVector4 m_min;
		hkVector4 m_max;
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

class hkpShape : public hkReferencedObject
{
	public:
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
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const = 0;
		virtual hkBool castRayImpl(  const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const = 0;
	public:
		hkUlong m_userData;
	public:
		hkEnum< hkpShapeType, hkUint32> m_type;
};

class hkpShapeContainer
{
	public:
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

class hkpSingleShapeContainer : public hkpShapeContainer
{
	public:
		~hkpSingleShapeContainer()
		{
			m_childShape->removeReference();
		}
		virtual int getNumChildShapes() const { return 1; }
		virtual hkpShapeKey getFirstKey() const { return 0; }
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const { return 0xffffffff; }
		virtual const hkpShape* getChildShape( hkpShapeKey key, ShapeBuffer& buffer ) const;
		inline const hkpShape* getChild() const { return m_childShape; }
	protected:
		const hkpShape* m_childShape;
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
	public:
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

class hkpBvTreeShape: public hkpShape
{
	public:
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const = 0;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const = 0;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const = 0;
		virtual const hkpShapeContainer* getContainer() const = 0;
};

class hkpTriSampledHeightFieldCollection;

class hkpTriSampledHeightFieldBvTreeShape : public hkpBvTreeShape
{
	public:
		virtual void queryObb( const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance, hkArray< hkpShapeKey >& hits ) const;
		virtual void queryAabb( const hkAabb& aabb, hkArray<hkpShapeKey>& hits ) const;
		virtual hkUint32 queryAabb( const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys ) const;
		const hkpShapeContainer* getContainer() const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		virtual void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
		const hkpTriSampledHeightFieldCollection* FUN_009a82b0() const;
	public:
		class hkpSingleShapeContainer m_childContainer;
		mutable int	m_childSize;
		hkBool m_wantAabbRejectionTest;
};

class hkpSampledHeightFieldShape;

class hkpTriSampledHeightFieldCollection : public hkpShapeCollection
{
	public:
		~hkpTriSampledHeightFieldCollection();
		virtual hkpShapeKey getFirstKey() const;
		virtual hkpShapeKey getNextKey( hkpShapeKey oldKey ) const;
		virtual const hkpShape* getChildShape(  hkpShapeKey key, ShapeBuffer& buffer ) const;
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
		const hkpSampledHeightFieldShape* FUN_009a7e90() const;
		inline hkReal getRadius() const { return m_radius; }
	protected:
		const hkpSampledHeightFieldShape* m_heightfield;
		mutable int	m_childSize;
		hkReal m_radius;
};

class hkpRayShapeCollectionFilter;

struct hkpShapeRayCastInput
{
	hkVector4 m_from;
	hkVector4 m_to;
	hkUint32 m_filterInfo;
	const hkpRayShapeCollectionFilter*	m_rayShapeCollectionFilter;
};

class hkpHeightFieldShape: public hkpShape
{
	public:
		struct CollideSpheresInput
		{
			class hkSphere* m_spheres;
			int		  m_numSpheres;
			hkReal	  m_tolerance;
		};
		typedef hkVector4 SphereCollisionOutput;
		virtual void collideSpheres( const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const = 0;
		struct hkpSphereCastInput: public hkpShapeRayCastInput
		{
			hkReal m_radius;
			hkReal m_maxExtraPenetration;
		};
		virtual void castSphere( const hkpSphereCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const = 0;
};

union hkIntUnion64
{
	hkQuadReal quad;
	hkInt64 i64;
	hkUint64 u64;
	hkInt32 i32[2];
	hkUint32 u32[2];
	hkInt16 i16[4];
	hkUint16 u16[4];
	hkInt8 i8[8];
	hkUint8 u8[8];
};

class hkpSampledHeightFieldShape : public hkpHeightFieldShape
{
	public:
		virtual ~hkpSampledHeightFieldShape();
		virtual void getAabbImpl(  const hkTransform& localToWorld, hkReal tolerance, hkAabb& out ) const;
		virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) const;
		virtual void collideSpheres( const CollideSpheresInput& input, SphereCollisionOutput* outputArray) const = 0;
		virtual void castSphere( const hkpSphereCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
		virtual hkReal getHeightAt( int x, int z ) const = 0;
		virtual hkBool getTriangleFlip() const = 0;
		static __forceinline hkReal getHeightAtImpl( const hkpSampledHeightFieldShape* hf, int x, int z );
		hkBool castRayImpl( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
		void castRayWithCollector( const hkpShapeRayCastInput& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector ) const;
	public:
		int m_xRes;
		int m_zRes;
		hkReal m_heightCenter;
		hkBool m_useProjectionBasedHeight;
		hkVector4 m_intToFloatScale;
		hkVector4 m_floatToIntScale;
		hkVector4 m_floatToIntOffsetFloorCorrected;
		hkVector4 m_extents;
};

__forceinline hkReal hkpSampledHeightFieldShape::getHeightAtImpl( const hkpSampledHeightFieldShape* hf, int x, int z )
{
	return hf->getHeightAt( x, z );
}

extern __declspec(align(16)) const float DAT_010610b0[4];

namespace hkVector4Util
{
__forceinline void __cdecl convertToUint16WithClip( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& min, const hkVector4& max, hkIntUnion64& out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.setMul4(x, scale);
	x.setMin4(x,max);
	x.setMax4(x,min);
	x.add4( reinterpret_cast<const hkVector4&>(DAT_010610b0) );
	union
	{
		hkQuadReal q;
		hkUint32 i[4];
	} u;
	u.q = x.getQuad();
	out.i16[0] = hkInt16(u.i[0] >> 7);
	out.i16[1] = hkInt16(u.i[1] >> 7);
	out.i16[2] = hkInt16(u.i[2] >> 7);
	out.i16[3] = hkInt16(u.i[3] >> 7);
}
}

const hkpTriSampledHeightFieldCollection* hkpTriSampledHeightFieldBvTreeShape::FUN_009a82b0() const
{
	return static_cast<const hkpTriSampledHeightFieldCollection*>( m_childContainer.getChild() );
}
}

// pdb: hkpTriSampledHeightFieldBvTreeShape::queryAabb | hkpTriSampledHeightFieldBvTreeShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: aabbIn, hits
void TriSampledHeightFieldBvTreeShapeq::CollectHits(const hkAabbq& aabbInq, hkShapeKeyArray& hitsq) const
{
	const hk9a88c0::hkpSampledHeightFieldShape* hf = reinterpret_cast<const hk9a88c0::hkpTriSampledHeightFieldBvTreeShape*>(this)->FUN_009a82b0()->FUN_009a7e90();
	hk9a88c0::hkAabb aabb;
	aabb.m_max.setAll( (reinterpret_cast<const hk9a88c0::hkpTriSampledHeightFieldBvTreeShape*>(this)->FUN_009a82b0()->getRadius()) );
	aabb.m_min.setAll( -reinterpret_cast<const hk9a88c0::hkpTriSampledHeightFieldBvTreeShape*>(this)->FUN_009a82b0()->getRadius() );
	aabb.m_max.add4( reinterpret_cast<const hk9a88c0::hkAabb&>(aabbInq).m_max );
	aabb.m_min.add4( reinterpret_cast<const hk9a88c0::hkAabb&>(aabbInq).m_min );
	hk9a88c0::hkIntUnion64 out;
	hk9a88c0::hkVector4Util::convertToUint16WithClip( aabb.m_min, hf->m_floatToIntOffsetFloorCorrected, hf->m_floatToIntScale, hk9a88c0::hkVector4::getZero(), hf->m_extents, out );
	hk9a88c0::hkUint32 minX = out.u16[0];
	hk9a88c0::hkUint32 minZ = out.u16[2];
	hk9a88c0::hkVector4Util::convertToUint16WithClip( aabb.m_max, hf->m_floatToIntOffsetFloorCorrected, hf->m_floatToIntScale, hk9a88c0::hkVector4::getZero(), hf->m_extents, out );
	hk9a88c0::hkUint32 maxX = out.u16[0];
	hk9a88c0::hkUint32 maxZ = out.u16[2];
	if ( ( minX >= hk9a88c0::hkUint32( hf->m_xRes - 1 ) ) && ( maxX >= hk9a88c0::hkUint32( hf->m_xRes - 1 ) ) )
	{
		return;
	}
	if ( ( minZ >= hk9a88c0::hkUint32( hf->m_zRes - 1 ) ) && ( maxZ >= hk9a88c0::hkUint32( hf->m_zRes - 1 ) ) )
	{
		return;
	}
	if ( minX >= hk9a88c0::hkUint32( hf->m_xRes - 1 ) )
	{
		minX = 0;
	}
	if ( minZ >= hk9a88c0::hkUint32( hf->m_zRes - 1 ) )
	{
		minZ = 0;
	}
	if ( maxX >= hk9a88c0::hkUint32( hf->m_xRes - 1 ) )
	{
		maxX = hf->m_xRes - 2;
	}
	if ( maxZ >= hk9a88c0::hkUint32( hf->m_zRes - 1 ) )
	{
		maxZ = hf->m_zRes - 2;
	}
	int initialSize = reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).getSize();
	if ( reinterpret_cast<const hk9a88c0::hkpTriSampledHeightFieldBvTreeShape*>(this)->m_wantAabbRejectionTest )
	{
		hk9a88c0::hkBool aboveHeightField = true;
		hk9a88c0::hkBool belowHeightField = true;
		for ( hk9a88c0::hkUint32 x = minX; x <= maxX; x++ )
		{
			for ( hk9a88c0::hkUint32 z = minZ; z <= maxZ; z++ )
			{
				reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).pushBack( ( z << 16 ) + ( x << 1 ) );
				reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).pushBack( ( ( z << 16 ) + ( x << 1 ) ) | 1 );
				if ( aboveHeightField || belowHeightField )
				{
					hk9a88c0::hkReal height = hf->m_intToFloatScale(1) * hk9a88c0::hkpSampledHeightFieldShape::getHeightAtImpl( hf, x, z );
					if ( aabb.m_min(1) < height )
					{
						aboveHeightField = false;
					}
					if ( aabb.m_max(1) > height )
					{
						belowHeightField = false;
					}
				}
			}
		}
		if ( aboveHeightField || belowHeightField )
		{
			for ( hk9a88c0::hkUint32 x = minX; x <= maxX + 1; x++ )
			{
				hk9a88c0::hkReal height = hf->m_intToFloatScale(1) * hk9a88c0::hkpSampledHeightFieldShape::getHeightAtImpl( hf, x, maxZ + 1 );
				if ( aabb.m_min(1) < height )
				{
					aboveHeightField = false;
				}
				if ( aabb.m_max(1) > height )
				{
					belowHeightField = false;
				}
			}
			for ( hk9a88c0::hkUint32 z = minZ; z <= maxZ + 1; z++ )
			{
				hk9a88c0::hkReal height = hf->m_intToFloatScale(1) * hk9a88c0::hkpSampledHeightFieldShape::getHeightAtImpl( hf, maxX + 1, z );
				if ( aabb.m_min(1) < height )
				{
					aboveHeightField = false;
				}
				if ( aabb.m_max(1) > height )
				{
					belowHeightField = false;
				}
			}
		}
		if ( aboveHeightField || belowHeightField )
		{
			reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).setSize( initialSize );
		}
	}
	else
	{
		for ( hk9a88c0::hkUint32 x = minX; x <= maxX; x++ )
		{
			for ( hk9a88c0::hkUint32 z = minZ; z <= maxZ; z++ )
			{
				reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).pushBack( ( z << 16 ) + ( x << 1 ) );
				reinterpret_cast<hk9a88c0::hkArray<hk9a88c0::hkpShapeKey>&>(hitsq).pushBack( ( ( z << 16 ) + ( x << 1 ) ) | 1 );
			}
		}
	}
}


extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_or_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps(void);
}

struct hkVector4Comparisonq
{
    __m128 m_uiMask;
};

extern const __m128 hkVector4Comparison_maskXYZW;

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

extern const hkTransformq hkTransform_identity;

union hkQuadUintq
{
    __m128 q;
    hkUint32 i[4];
};

struct hkUint16x4
{
    hkUint16 x;
    hkUint16 y;
    hkUint16 z;
    hkUint16 w;
};

// The heightfield's getAabb slot (vtable index 7) with its real parameters.
class hkpSampledHeightFieldShapeAabbq
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void getAabb(const hkTransformq& localToWorld, hkReal tolerance, hkAabbq& out) const;
};

__forceinline const hkVector4q& getFloatToIntScale(const hkpSampledHeightFieldShapeq* hf)
{
    return reinterpret_cast<const hkVector4q*>(hf->m_kHeightScaleVector)[1];
}

__forceinline const hkVector4q& getFloatToIntOffsetFloorCorrected(const hkpSampledHeightFieldShapeq* hf)
{
    return reinterpret_cast<const hkVector4q*>(hf->m_kHeightScaleVector)[2];
}

extern const hkVector4q hkVector4Util_uint16Magic;

__forceinline hkReal getRadius(const hkpTriSampledHeightFieldCollectionq* collection)
{
    return reinterpret_cast<const hkReal*>(collection)[8];
}

__forceinline void SetAllComponents(hkVector4q& self, hkReal r)
{
    self.m_vComponents = _mm_set_ps1(r);
}
__forceinline void setZero4(hkVector4q& self)
{
    self.m_vComponents = _mm_setzero_ps();
}
__forceinline void set(hkVector4q& self, hkReal a, hkReal b, hkReal c, hkReal d)
{
    self.m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void add4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_add_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void sub4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_sub_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void mul4(hkVector4q& self, const hkVector4q& v)
{
    self.m_vComponents = _mm_mul_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void setAdd4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMin4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMax4(hkVector4q& self, const hkVector4q& a, const hkVector4q& b)
{
    self.m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline hkVector4Comparisonq compareLessThan4(const hkVector4q& self, const hkVector4q& a,
                                                    const hkVector4Comparisonq& mask)
{
    hkVector4Comparisonq c;
    c.m_uiMask = _mm_and_ps(_mm_cmplt_ps(self.m_vComponents, a.m_vComponents), mask.m_uiMask);
    return c;
}

__forceinline void setSelect4(hkVector4q& self, const hkVector4Comparisonq& comp, const hkVector4q& trueValue,
                              const hkVector4q& falseValue)
{
    self.m_vComponents = _mm_or_ps(_mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents),
                                   _mm_and_ps(comp.m_uiMask, trueValue.m_vComponents));
}

// Clip-converts one vector and returns the 65536.0f magic vector it added, so the
// second conversion can reuse the loaded value without re-reading the global.
__forceinline __m128 convertToUint16WithClip(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                             const hkVector4q& minVal, const hkVector4q& maxVal, hkUint16x4& out)
{
    hkVector4q x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    // Adding 65536 leaves value * 128 in the low mantissa bits.
    add4(x, hkVector4Util_uint16Magic);
    const __m128 magic = hkVector4Util_uint16Magic.m_vComponents;
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
    return magic;
}

// Same conversion, reusing the magic vector returned by the first call.
__forceinline void convertToUint16WithClipAgain(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                const hkVector4q& minVal, const hkVector4q& maxVal, const __m128 magic,
                                                hkUint16x4& out)
{
    hkVector4q x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    // Adding 65536 leaves value * 128 in the low mantissa bits.
    x.m_vComponents = _mm_add_ps(x.m_vComponents, magic);
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
}

// Expands aabb by the collection radius, clamps it to the height field's AABB, returns false if empty, else outputs uint16 grid min/max X and Z.
// @fnv 0x00d26940
hkBoolq FUN_00d26940(const hkAabbq* aabb, const hkpTriSampledHeightFieldCollectionq* collection, hkUint32* minX,
                     hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ)
{
    // The caller's aabb is expanded and clipped in place.
    const hkpSampledHeightFieldShapeq* hf = collection->FUN_00d26450();

    hkVector4q radius;
    SetAllComponents(radius, getRadius(collection));
    add4(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, radius);
    sub4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, radius);

    {
        hkAabbq hfAabb;
        reinterpret_cast<const hkpSampledHeightFieldShapeAabbq*>(hf)->getAabb(hkTransform_identity, 0.0f, hfAabb);

        hkVector4Comparisonq all;
        all.m_uiMask = hkVector4Comparison_maskXYZW;
        setSelect4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner,
                   compareLessThan4(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, hfAabb.m_kMinimumCorner, all),
                   hfAabb.m_kMinimumCorner, const_cast<hkAabbq*>(aabb)->m_kMinimumCorner);
        setSelect4(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner,
                   compareLessThan4(hfAabb.m_kMaximumCorner, const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, all),
                   hfAabb.m_kMaximumCorner, const_cast<hkAabbq*>(aabb)->m_kMaximumCorner);
    }

    if (_mm_movemask_ps(_mm_cmple_ps(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner.m_vComponents,
                                     const_cast<hkAabbq*>(aabb)->m_kMinimumCorner.m_vComponents)) &
        7)
    {
        return false;
    }

    hkVector4q zero;
    setZero4(zero);
    hkVector4q maxVal;
    set(maxVal, hkReal(hf->m_pad04[3] - 2), 0.0f, hkReal(hf->m_pad04[4] - 2), 0.0f);

    hkUint16x4 out;
    const __m128 magic =
        convertToUint16WithClip(const_cast<hkAabbq*>(aabb)->m_kMinimumCorner, getFloatToIntOffsetFloorCorrected(hf),
                                getFloatToIntScale(hf), zero, maxVal, out);
    *minX = out.x;
    *minZ = out.z;

    convertToUint16WithClipAgain(const_cast<hkAabbq*>(aabb)->m_kMaximumCorner, getFloatToIntOffsetFloorCorrected(hf),
                                 getFloatToIntScale(hf), zero, maxVal, magic, out);
    *maxX = out.x;
    *maxZ = out.z;

    return true;
}

typedef hkUint32 hkpShapeKey;

struct hkAabb
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;

    __forceinline hkAabb(const hkAabb& a) throw()
    {
        m_kMinimumCorner = a.m_kMinimumCorner;
        m_kMaximumCorner = a.m_kMaximumCorner;
    }
};

class hkpSampledHeightFieldShape
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual hkReal GetHeightAtGridPoint(int x, int z) const;

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kHeightScaleVector;

    __forceinline hkReal getHeightAt(int x, int z) const throw()
    {
        hkReal h = GetHeightAtGridPoint(x, z);
        return h * m_kHeightScaleVector.y;
    }

    __forceinline hkReal getScaledHeight(int x, int z) const throw()
    {
        hkReal h = GetHeightAtGridPoint(x, z);
        return m_kHeightScaleVector.y * h;
    }
};

class hkpTriSampledHeightFieldCollection
{
  public:
    const hkpSampledHeightFieldShape* FUN_00d26450() const;
};

struct hkBoolResult
{
    hkBool m_cBooleanValue;
    hkBoolResult() throw();
    hkBoolResult(bool b) throw() : m_cBooleanValue(b)
    {}
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

static __declspec(noinline) hkBoolResult
    __cdecl FUN_00d26940(const hkAabb& aabb, const hkpTriSampledHeightFieldCollection* collection, hkUint32& minX,
                         hkUint32& maxX, hkUint32& minZ, hkUint32& maxZ)
{
    const hkpSampledHeightFieldShape* hf = collection->FUN_00d26450();
    minX = (int)(aabb.m_kMinimumCorner.m128_f32[0] * hf->m_kHeightScaleVector.x);
    maxX = (int)(aabb.m_kMaximumCorner.m128_f32[0] * hf->m_kHeightScaleVector.x);
    minZ = (int)(aabb.m_kMinimumCorner.m128_f32[2] * hf->m_kHeightScaleVector.z);
    maxZ = (int)(aabb.m_kMaximumCorner.m128_f32[2] * hf->m_kHeightScaleVector.z);
    return hkBoolResult(minX <= maxX && minZ <= maxZ);
}

typedef hkBoolResult(__cdecl* ExtentsQueryFn)(const hkAabb&, const hkpTriSampledHeightFieldCollection*, hkUint32&,
                                              hkUint32&, hkUint32&, hkUint32&);
ExtentsQueryFn S00d26ba0_extentsFp = &FUN_00d26940;
