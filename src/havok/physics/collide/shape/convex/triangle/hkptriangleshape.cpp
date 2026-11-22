#include "f3_common.h"
// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/triangle/hkptriangleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTriangleShape.h"

// FUN_00d1ff10: hkpTriangleShape helper returning (m_ucWeldingPadding + 1) * 3.
class FUN_00d1ff10_cls : public hkpTriangleShape
{
public:
    int FUN_00d1ff10();
};

// @fnv 0x00d1ff10
// pdb: hkpTriangleShape::getNumCollisionSpheresImpl | hkpTriangleShape.obj | fnv360_0822_retail, objrun_open, low
int FUN_00d1ff10_cls::FUN_00d1ff10()
{
    return (m_ucWeldingPadding + 1) * 3;
}

// edge is a triangle edge index (0, 1, or 2).
// @fnv 0x00d1fef0
// pdb: getSingleEdgeBitcode | hkpTriangleShape.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) int __cdecl FUN_00d1fef0(unsigned short weldingInfo, int edge)
{
    char shift = edge * 5;
    return (weldingInfo >> shift) & 31;
}
int __cdecl ExtractEdge(unsigned short weldingInfo, int edge)
{
    return FUN_00d1fef0(weldingInfo, edge);
}

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);

// Computes the normalized cross product of two edge vectors and writes the result to out.
// @fnv 0x00d1ff80
const __m128* volatile inputA;
const __m128* volatile inputB;
const __m128* volatile inputC;
__m128* volatile outputV;

extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);

struct SimdVector {
    union { __m128 value; float component[4]; };
    void FUN_00c7f640(const void* transform, const SimdVector& vertex);
    __forceinline void lower(const SimdVector& a, const SimdVector& b) { value = _mm_min_ps(a.value, b.value); }
    __forceinline void upper(const SimdVector& a, const SimdVector& b) { value = _mm_max_ps(a.value, b.value); }
    __forceinline void sum(const SimdVector& a, const SimdVector& b) { value = _mm_add_ps(a.value, b.value); }
    __forceinline void difference(const SimdVector& a, const SimdVector& b) { value = _mm_sub_ps(a.value, b.value); }
    __forceinline void broadcast(float f) { __m128 scalar = _mm_load_ss(&f); value = _mm_shuffle_ps(scalar, scalar, 0); }
};

extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

struct SupportVector {
    union { __m128 vector; float components[4]; };
    __forceinline void add(const SupportVector& b) { vector = _mm_add_ps(vector, b.vector); }
};

#include <math.h>



extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);

// hkpWeldingUtility sin/cos table: cosAccept0, sinAccept0, cosSnap0, cosSnap1, cosAccept1, sinAccept1
struct FloatArray6 { float value[6]; };

static __forceinline float scalar(__m128 v) { float out; _mm_store_ss(&out, v); return out; }
static __forceinline __m128 splat(__m128 v) { return _mm_shuffle_ps(v, v, 0); }

typedef unsigned char hkUint8_S;
typedef unsigned short hkUint16_S;
typedef unsigned int hkUint32_S;
typedef unsigned long __w64 hkUlong_S;
typedef unsigned __w64 hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass_S;
typedef int hkBool32;
class hkBool_S
{
public:
typedef char CompileTimeTrueType;inline hkBool_S(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
private:
TYPE m_kStorage;};
extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong_S)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
class hkMemoryAllocator
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pStreamAllocator;};
class hkBaseObject_S
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject_S(){}
};
class hkStatisticsCollector;
class hkReferencedObject_S:public hkBaseObject_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16_S m_usMemSizeAndFlags;
public:
hkReferencedObject_S(class FinishingFlag flag){}
};typedef float hkReal_S;

extern "C"{






extern __m128 _mm_rcp_ps(__m128 _A);

extern __m128 _mm_and_ps(__m128 _A,__m128 _B);

extern __m128 _mm_or_ps(__m128 _A,__m128 _B);

extern int _mm_movemask_ps(__m128 _A);

extern __m128 _mm_setzero_ps(void);};
typedef __m128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};
static const Mask ms_kLaneMasks[4];
__forceinline void setAnd(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_and_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setOr(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_or_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setNot(hkVector4ComparisonParameter a)
{
static __declspec(align(16))const hkUint32_S allBits[4]={0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};
m_uiMask=_mm_andnot_ps(a.m_uiMask,*(const hkQuadReal*)&allBits);
}
__forceinline hkBool32 anyIsSet(Mask m)const{return _mm_movemask_ps(m_uiMask)&m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4_S;};
namespace MathUtilities
{inline hkQuadReal quadReciprocal(hkQuadReal r)
{
hkQuadReal e=_mm_rcp_ps(r);
return _mm_sub_ps(_mm_add_ps(e,e),_mm_mul_ps(_mm_mul_ps(e,r),e));
}
}
class hkTransform_S;
class hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4_S&v);
__forceinline void set(hkReal_S x,hkReal_S y,hkReal_S z,hkReal_S w=0);
__forceinline void SetAllComponents(hkSimdRealParameter x);
__forceinline void setZero4();
__forceinline void sub4(const hkVector4_S&a);
__forceinline void setSub4(const hkVector4_S&a,const hkVector4_S&b);
__forceinline void mul4(const hkVector4_S&a);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4_S&a);
__forceinline void addMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setCross(const hkVector4_S&a,const hkVector4_S&b);
__forceinline Vector4Comparison compareLessThan4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareEqual4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareLessThanEqual4(hkVector4Parameter a)const;
__forceinline Vector4Comparison compareGreaterThanEqual4(hkVector4Parameter a)const;
__forceinline VectorComponentValue dot3(const hkVector4_S&a)const;
__forceinline VectorComponentValue lengthSquared3()const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal_S&operator()(int i);
__forceinline void setReciprocal4(const hkVector4_S&v);
__forceinline VectorComponentValue getSimdAt(int i)const;
__forceinline void setBroadcast(hkVector4Parameter v,int i);
__forceinline hkQuadReal&getQuad();
__forceinline const hkQuadReal&getQuad()const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline hkReal_S&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal_S*>(&m_vComponents)[a];
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool_S __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool_S m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32_S m_uiStartTicks;
hkUint32_S m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32_S ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4_S m_kMinimumCorner;};class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
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
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
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
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
enum hkpBufferSize
{
HK_SHAPE_BUFFER_SIZE=512
};
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
typedef hkUint16_S hkpVertexId;
typedef hkUint32_S hkpShapeKey;
class hkpConvexShape_S;
class hkpShape_S:public hkReferencedObject_S
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass_S&__cdecl staticClass();struct DefaultStruct;
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16_S>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject_S*b=static_cast<hkReferencedObject_S*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__forceinline hkpShape_S(CollisionShapeType type);
__forceinline CollisionShapeType getType()const;
__forceinline void getAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const;
virtual hkReal_S getMaximumProjection(const hkVector4_S&direction)const;
inline hkUlong_S getUserData()const;
inline void setUserData(hkUlong_S data);
__forceinline hkBool_S RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
__forceinline Vector4Comparison castRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output)const;
__forceinline Vector4Comparison castRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
__forceinline void castRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const=0;
virtual hkBool_S IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison FUN_00d20e70(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
static void __cdecl verifyShapeFunctions();
typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,hkVector4Parameter direction,Vector4WithInt24W&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const hkpVertexId*ids,int numIds,class Vector4WithInt24W*verticesOut);
typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,hkpVertexId*featurePoints,hkUint8_S&numFeaturePoints,hkVector4_S&contactPointWs,const hkTransform_S*thisObjTransform,const hkpConvexShape_S*collidingShape,const hkTransform_S*collidingTransform,hkVector4_S&separatingNormalInOut);
typedef void(__cdecl*GetCentreFunc)(const void*thisObj,hkVector4_S&centreOut);
typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const hkSphere*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,hkSphere*sphereBuffer);
typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out);
typedef hkBool_S(__cdecl*CastRayFunc)(const void*thisObj,const ShapeRayCastQuery&input,ShapeRayCastOutput&output);
typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector);
typedef Vector4Comparison(__cdecl*CastRayBundleFunc)(const void*thisObj,const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask);
typedef const hkpShape_S*(__cdecl*GetChildShapeFunc)(const void*thisObj,hkpShapeKey key,hkpShapeBuffer&buffer);
typedef hkUint32_S(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,hkpShapeKey key);
struct ShapeCallbackDispatchTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::ShapeCallbackDispatchTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ValueWrapper<GetSupportingVertexFunc>m_kGetSupportingVertexFunction;
ValueWrapper<ConvertVertexIdsToVerticesFunc>m_kConvertVertexIdsToVerticesFunction;
ValueWrapper<WeldContactPointFunc>m_kWeldContactPointFunction;
ValueWrapper<GetCentreFunc>m_kGetCentreFunction;
ValueWrapper<GetNumCollisionSpheresFunc>m_kGetNumCollisionSpheresFunction;
ValueWrapper<GetCollisionSpheresFunc>m_kGetCollisionSpheresFunction;
ValueWrapper<GetAabbFunc>m_kGetAabbFunction;
ValueWrapper<CastRayFunc>m_kCastRayFunction;
ValueWrapper<CastRayWithCollectorFunc>m_kCastRayWithCollectorFunction;
ValueWrapper<CastRayBundleFunc>m_kCastRayBundleFunction;
ValueWrapper<GetChildShapeFunc>m_kGetChildShapeFunction;
ValueWrapper<GetCollisionFilterInfoFunc>m_kGetCollisionFilterInfoFunction;
void reset();
};
struct AlignedShapeCallbackTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_S::AlignedShapeCallbackTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__declspec(align(64))GetSupportingVertexFunc m_kGetSupportingVertexFunction;
ConvertVertexIdsToVerticesFunc m_kConvertVertexIdsToVerticesFunction;
WeldContactPointFunc m_kWeldContactPointFunction;
GetCentreFunc m_kGetCentreFunction;
GetNumCollisionSpheresFunc m_kGetNumCollisionSpheresFunction;
GetCollisionSpheresFunc m_kGetCollisionSpheresFunction;
GetAabbFunc m_kGetAabbFunction;
CastRayFunc m_kCastRayFunction;
CastRayWithCollectorFunc m_kCastRayWithCollectorFunction;
CastRayBundleFunc m_kCastRayBundleFunction;
GetChildShapeFunc m_kGetChildShapeFunction;
GetCollisionFilterInfoFunc m_kGetCollisionFilterInfoFunction;
};
typedef void(__cdecl*RegisterFunc)(ShapeCallbackDispatchTable&sf);
public:
public:
hkUlong_S m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32_S>m_type;
public:
hkpShape_S(class FinishingFlag flag):hkReferencedObject_S(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};struct RayCastHitResult
{
inline void reset();
hkVector4_S m_vHitNormal;
hkReal_S m_fHitFraction;};struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setKey(hkpShapeKey key);
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};inline void ShapeRayCastOutput::setKey(hkpShapeKey key)
{
m_uiShapeKeys[m_uiShapeKeyIndex]=key;
}
struct ShapeRayCastOutputArray
{
ShapeRayCastOutput m_akRayOutputs[4];
void reset(){m_akRayOutputs[0].reset();m_akRayOutputs[1].reset();m_akRayOutputs[2].reset();m_akRayOutputs[3].reset();}
};
class hkpSphereRepShape_S:public hkpShape_S
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape_S(CollisionShapeType type):hkpShape_S(type){}
hkpSphereRepShape_S(FinishingFlag flag):hkpShape_S(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
extern hkReal_S g_fDefaultConvexRadius;
class hkpConvexShape_S:public hkpSphereRepShape_S
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape_S(CollisionShapeType type,hkReal_S radius);
public:
hkpConvexShape_S(FinishingFlag flag):hkpSphereRepShape_S(flag){m_type=HK_SHAPE_CONVEX;}
};class hkpWeldingUtility
{
public:
static const struct ClassMemberDescriptor Members[];
enum WeldingType
{
WELDING_TYPE_ANTICLOCKWISE=0,
WELDING_TYPE_CLOCKWISE=4,
WELDING_TYPE_TWO_SIDED=5,
WELDING_TYPE_NONE=6
};
public:
struct FloatArray6
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpWeldingUtility::FloatArray6));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal_S m_fValue0;
hkReal_S m_fValue1;
hkReal_S m_fValue2;
hkReal_S m_fValue3;
hkReal_S m_fValue4;
hkReal_S m_fValue5;
};};
class hkpTriangleShape_S:public hkpConvexShape_S
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass_S&__cdecl staticClass();struct DefaultStruct;
int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const{return sizeof(*this);};
__forceinline hkpTriangleShape_S(hkReal_S radius=g_fDefaultConvexRadius,hkUint16_S weldingInfo=0,hkpWeldingUtility::WeldingType type=hkpWeldingUtility::WELDING_TYPE_NONE);
__forceinline hkpTriangleShape_S(const hkVector4_S&v0,const hkVector4_S&v1,const hkVector4_S&v2,hkReal_S radius=g_fDefaultConvexRadius);
__forceinline const hkVector4_S*GetIndexedVertices()const;
__forceinline hkVector4_S&getVertex(int i);
__forceinline const hkVector4_S&getVertex(int i)const;
__forceinline void setVertex(int i,const hkVector4_S&vertex);
__forceinline hkUint16_S getWeldingInfo()const;
__forceinline void SetWeldingInfo(hkUint16_S info);
__forceinline hkpWeldingUtility::WeldingType getWeldingType()const;
__forceinline void setWeldingType(hkpWeldingUtility::WeldingType type);
__forceinline bool isExtruded()const;
__forceinline const hkVector4_S&getExtrusion()const;
__forceinline void setExtrusion(const hkVector4_S&extrusion);
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*verticesOut)const;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8_S&numFeaturePoints,hkVector4_S&contactPointWs,const hkTransform_S*thisObjTransform,const hkpConvexShape_S*collidingShape,const hkTransform_S*collidingTransform,hkVector4_S&separatingNormalInOut)const;
virtual void GetCentre(hkVector4_S&centreOut)const;
virtual int GetNumCollisionSpheres()const;
virtual const hkSphere*GetCollisionSpheres(hkSphere*sphereBuffer)const;
virtual void CalculateAabb(const hkTransform_S&localToWorld,hkReal_S tolerance,hkAabb&out)const;
virtual hkBool_S IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&results)const;
virtual Vector4Comparison FUN_00d20e70(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&results,hkVector4ComparisonParameter mask)const;
virtual void GetFirstVertex(hkVector4_S&v)const;
static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerGetAabbFunction(ShapeCallbackDispatchTable&sf);
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass_S*cls)const;
protected:
hkUint16_S m_kWeldingInfo;
hkEnum<hkpWeldingUtility::WeldingType,hkUint8_S>m_eWeldingType;
hkUint8_S m_ucWeldingPadding;
hkVector4_S m_kVertexA;
hkVector4_S m_kVertexB;
hkVector4_S m_kVertexC;
hkVector4_S m_kVertexTransform;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
hkpTriangleShape_S(FinishingFlag flag):hkpConvexShape_S(flag){m_type=HK_SHAPE_TRIANGLE;}
};const hkVector4_S&hkpTriangleShape_S::getVertex(int i)const
{
;
return(&m_kVertexA)[i];
}
struct ShapeRayBundleCastInput
{
hkVector4_S m_vFrom[3];
hkVector4_S m_vTo[3];};
namespace hkVector4Util_S
{
__forceinline void __cdecl mulSigns4(hkVector4_S&inout,const hkVector4_S&signsSource);}

extern "C" __m128 _mm_setzero_ps();

class LaneScalar {
    __m128 value;
public:
    LaneScalar(const __m128& source) : value(source) {}
    __forceinline __m128 splat() const {
        return _mm_shuffle_ps(value,value,0);
    }
};

class LaneVector {
    __m128 value;
public:
    __forceinline operator __m128() const { return value; }
    __forceinline void operator=(const LaneVector& source) { value=source.value; }
    __forceinline void operator=(const __m128& source) { value=source; }
    __forceinline void broadcast(const LaneVector& source,int lane) {
        if(lane==0) value=_mm_shuffle_ps(source.value,source.value,0);
        else if(lane==1) value=_mm_shuffle_ps(source.value,source.value,0x55);
        else if(lane==2) value=_mm_shuffle_ps(source.value,source.value,0xaa);
        else value=_mm_shuffle_ps(source.value,source.value,0xff);
    }
    __forceinline LaneScalar scalar(int lane) const {
        switch(lane) {
        case 0: return value;
        case 1: return _mm_shuffle_ps(value,value,0x55);
        case 2: return _mm_shuffle_ps(value,value,0xaa);
        default: return _mm_shuffle_ps(value,value,0xff);
        }
    }
    __forceinline void clear() { value=_mm_setzero_ps(); }
    __forceinline void subtract(const LaneVector& other) { value=_mm_sub_ps(value,other.value); }
    __forceinline void product(const LaneVector& a,const LaneVector& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void accumulate(const LaneScalar& scale,const LaneVector& other) {
        value=_mm_add_ps(value,_mm_mul_ps(scale.splat(),other.value));
    }
};

extern "C" void _mm_store_ss(float*, __m128);
struct ShapeRayCastQuery {
    hkVector4_S m_vFrom;
    hkVector4_S m_vTo;
};
