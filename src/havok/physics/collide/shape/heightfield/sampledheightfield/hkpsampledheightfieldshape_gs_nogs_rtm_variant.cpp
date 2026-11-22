#include "f3_common.h"
// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSampledHeightFieldShape.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_load_ps1(const float*);
extern float DAT_01012068;
extern double DAT_01012070;
struct Cls_00d24670 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual float getH(int x, int y);
    virtual void getFlip(bool& flip);
    void FUN_00d24670(int x, int y, float fx, float fy, __m128* nrm, float* height, int* flag);
};
struct hkInfoD260 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScalar;
};
class hkBoolD260 {
public:
    hkBoolD260(bool b) { m_cBooleanValue = (char)b; }
    hkBoolD260(const hkBoolD260& o) { m_cBooleanValue = o.m_cBooleanValue; }

    char m_cBooleanValue;
};
class hkCollectorD260 {
public:
    hkCollectorD260(hkInfoD260* info) : m_fScalar(info->m_fScalar), m_bHasHit(false), m_info(info) {}
    virtual void AddHit(void* hit);

    float m_fScalar;
    bool m_bHasHit;
    hkInfoD260* m_info;
};
struct FUN_00d24b50_Obj {
    void __thiscall FUN_00d24b50(void* object, int flags, hkBoolD260 flag2, float f, hkCollectorD260* collector);
};
class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBoolD260 __thiscall FUN_00d26080(void* object, hkInfoD260* info);
};
struct S00d261b0_Elem {
    __m128 v00;
    float f10;
    int i14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_idx40;
};
struct S00d261b0_cls {
    int unk00;
    float f04;
    unsigned char b08;
    S00d261b0_Elem* p0c;
    void UpdateMinValue(int a0, int a1);
};
extern int DAT_010ce310;
struct Arg3 {
    int unk00;
    float m_04;
};
struct Local12 {
    void* m_00;
    float m_04;
    const Arg3* m_08;
};
struct Val1 {
    unsigned char m_00;
    Val1() : m_00(0) {}
    Val1(const Val1& o) : m_00(o.m_00) {}
};
struct Host {
    void FUN_00d24b50(int a1, int a2, Val1 v, float f, Local12* pLocal);
    void hkpSampledHeightFieldShape_castRayWithCollectorImpl(int a1, int a2, const Arg3* a3);
};
struct __declspec(align(16)) RayData {
    float x; float y; float z; float w;
    float endX; float endY; float endZ; float endW;
    float extraX; float extraY; float extraZ; float extraW;
};
struct Input {
    RayData base;
    float f30;
    float f34;
};
struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;

    void FUN_00d24b50(RayData* data, void* arg2, hkBoolD260 arg3, float arg4, void* arg5);
    void hkpSampledHeightFieldShape_castSphere(Input* input, void* arg2, void* arg3);
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
__declspec(align(16)) const hkVector4 halfScale = {0.5f, 0.5f, 0.5f, 0.5f};
struct SampledHeightField : hkpSampledHeightFieldShape {
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual float getHeightAt(int x, int z);
    void FUN_00d249f0(hkUlong transform, float tolerance, hkUlong aabb);
};
void __cdecl FUN_00d26230(hkUlong, const hkVector4&, const hkVector4&, float, hkUlong);

typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
class hkBoolR
{
public:
typedef char CompileTimeTrueType;
inline hkBoolR()
{
}
inline hkBoolR(bool b)
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
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
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
namespace vc_attributes
{
enum YesNoMaybe
{
No=0x0fff0001,
Maybe=0x0fff0010,
Yes=0x0fff0100
};
enum AccessType
{
NoAccess=0,
Read=1,
Write=2,
ReadWrite=3
};
[repeatable]
[source_annotation_attribute(Parameter)]
struct PreAttribute
{
PreAttribute();
unsigned int Deref;
YesNoMaybe Valid;
YesNoMaybe Null;
YesNoMaybe Tainted;
AccessType Access;
size_t ValidElementsConst;
size_t ValidBytesConst;
const wchar_t*ValidElements;
const wchar_t*ValidBytes;
const wchar_t*ValidElementsLength;
const wchar_t*ValidBytesLength;
size_t WritableElementsConst;
size_t WritableBytesConst;
const wchar_t*WritableElements;
const wchar_t*WritableBytes;
const wchar_t*WritableElementsLength;
const wchar_t*WritableBytesLength;
size_t ElementSizeConst;
const wchar_t*ElementSize;
YesNoMaybe NullTerminated;
const wchar_t*Condition;
};};
const::vc_attributes::YesNoMaybe SA_Yes=::vc_attributes::Yes;
const::vc_attributes::YesNoMaybe SA_No=::vc_attributes::No;
const::vc_attributes::AccessType SA_Read=::vc_attributes::Read;
typedef::vc_attributes::PreAttribute SA_Pre;class hkMemoryAllocator
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
class hkBaseObject_
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject_(){}
};
class hkStatisticsCollector;
class hkReferencedObject_:public hkBaseObject_
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_*b=static_cast<hkReferencedObject_*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject_(class FinishingFlag flag){}
};typedef float hkReal;
extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ss(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ss(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_rsqrt_ss(__m128 _A);
extern __m128 _mm_andnot_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmpeq_ss(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_set_ss(float _A);
extern int _mm_cvtss_si32(__m128 _A);
extern __m128 _mm_set_ps1(float _A);
extern __m128 _mm_load_ss(float const*_A);};
typedef __m128 hkQuadReal;
class hkVector4_;
typedef const hkVector4_&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
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
namespace MathUtilities
{inline int __cdecl hkToIntFast(hkReal r){
return fnv_FloatToInt(r);
}
}
extern "C"{
double __cdecl fabs([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]double _X);inline float fabsf([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]float _X)
{return((float)fabs((double)_X));}
}
namespace MathUtilities
{inline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}
template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
}
class hkTransform_;
class hkVector4_
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setAll3(hkReal x);
__forceinline void add4(const hkVector4_&a);
__forceinline void setAdd4(const hkVector4_&a,const hkVector4_&b);
__forceinline void mul4(const hkVector4_&a);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setInterpolate4(const hkVector4_&a,const hkVector4_&b,hkSimdRealParameter t);
__forceinline VectorComponentValue dot3(const hkVector4_&a)const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal&operator()(int i);
__forceinline hkQuadReal&getQuad();
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
inline hkQuadReal&hkVector4_::getQuad()
{
return m_vComponents;
}
inline void hkVector4_::setAll3(hkReal a)
{
m_vComponents=_mm_set_ps1(a);
}
inline void hkVector4_::add4(const hkVector4_&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_::setAdd4(const hkVector4_&v0,const hkVector4_&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_::mul4(const hkVector4_&v)
{
m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_::setMul4(const hkVector4_&a,const hkVector4_&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_::setInterpolate4(const hkVector4_&v0,const hkVector4_&v1,hkSimdRealParameter _t)
{
static __declspec(align(16))const float cw[4]={1.0f,1.0f,1.0f,1.0f};
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(*(const hkQuadReal*)&cw,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline VectorComponentValue hkVector4_::dot3(const hkVector4_&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4_::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4_::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline hkReal&hkVector4_::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
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
__forceinline hkBoolR __cdecl memoryAvailable()
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
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4_ m_kMinimumCorner;};class Vector4WithInt24W:public hkVector4_
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
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape_:public hkReferencedObject_
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape_(CollisionShapeType type);
virtual hkReal getMaximumProjection(const hkVector4_&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBoolR IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,hkVector4Parameter direction,Vector4WithInt24W&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const hkpVertexId*ids,int numIds,class Vector4WithInt24W*verticesOut);
typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVector4_&contactPointWs,const hkTransform_*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform_*collidingTransform,hkVector4_&separatingNormalInOut);
typedef void(__cdecl*GetCentreFunc)(const void*thisObj,hkVector4_&centreOut);
typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const hkSphere*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,hkSphere*sphereBuffer);
typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out);
typedef hkBoolR(__cdecl*CastRayFunc)(const void*thisObj,const ShapeRayCastQuery&input,ShapeRayCastOutput&output);
typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector);
typedef Vector4Comparison(__cdecl*CastRayBundleFunc)(const void*thisObj,const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask);
typedef const hkpShape_*(__cdecl*GetChildShapeFunc)(const void*thisObj,hkpShapeKey key,hkpShapeBuffer&buffer);
typedef hkUint32(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,hkpShapeKey key);
struct ShapeCallbackDispatchTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape_::ShapeCallbackDispatchTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
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
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape_(class FinishingFlag flag):hkReferencedObject_(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4_ m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
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
namespace hkVector4Util_S
{
__forceinline void __cdecl convertToUint16(const hkVector4_&in,const hkVector4_&offset,const hkVector4_&scale,hkIntUnion64&out);}
inline void __cdecl hkVector4Util_S::convertToUint16(const hkVector4_&in,const hkVector4_&offset,const hkVector4_&scale,hkIntUnion64&out)
{
static hkQuadReal magicQuad={hkReal(0x30000),hkReal(0x30000),hkReal(0x30000),hkReal(0x30000)};
hkVector4_ x,magic;
x.setAdd4(in,offset);
x.mul4(scale);
magic.getQuad()=magicQuad;
x.add4(magic);
union
{
hkQuadReal q;
hkUint32 i[4];
}u;
u.q=x.getQuad();
out.i16[0]=static_cast<hkInt16>(u.i[0]>>6);
out.i16[2]=static_cast<hkInt16>(u.i[2]>>6);}
struct ShapeRayCastQuery
{
hkVector4_ m_vFrom;
hkVector4_ m_vTo;};
class hkpHeightFieldShape_:public hkpShape_
{
public:
static const struct ClassMemberDescriptor Members[];
struct CollisionSphereData
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpHeightFieldShape_::CollisionSphereData));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
class hkSphere*m_kSpheres;
int m_iSphereCount;
hkReal m_fScalar;
};
typedef hkVector4_ SphereCollisionOutput;
struct SphereRayCastQuery:public ShapeRayCastQuery
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpHeightFieldShape_::SphereRayCastQuery));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fSphereRadius;
hkReal m_fMaxExtraPenetration;
};
public:
hkpHeightFieldShape_(CollisionShapeType type):hkpShape_(type){}
public:
hkpHeightFieldShape_(FinishingFlag flag):hkpShape_(flag){m_type=HK_SHAPE_HEIGHT_FIELD;}
};
class ShapeScaleVector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
hkVector4_ m_vScale;};
class SampledHeightRayCastView:public hkpHeightFieldShape_
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
enum HeightFieldType
{
HEIGHTFIELD_STORAGE=0,
HEIGHTFIELD_COMPRESSED,
HEIGHTFIELD_USER,
HEIGHTFIELD_MAX_ID
};
SampledHeightRayCastView(const ShapeScaleVector&ci,HeightFieldType type=HEIGHTFIELD_USER);
virtual ~SampledHeightRayCastView();
void GetHeightFieldCinfo(ShapeScaleVector&cinfo)const;
virtual void CalculateAabb(const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual void CollideSpheres(const CollisionSphereData&input,SphereCollisionOutput*outputArray)const=0;
virtual void CastSphere(const SphereRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
__forceinline hkReal getHeightAt(int x,int z)const;
__forceinline hkBoolR getTriangleFlip()const;
virtual hkReal GetHeightAtGridPoint(int x,int z)const=0;
virtual hkBoolR IsTriangleWindingFlipped()const=0;
static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerHeightFieldFunctions();
virtual hkBoolR IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
public:
void FUN_00d24b50(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkBoolR reportPenetratingStartPosition,hkReal maxExtraPenetration,hkpRayHitCollector&collector)const;
__forceinline void _getHeightAndNormalAt(int xPos,int zPos,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const;
public:
void GetHeightAndNormalAt(int xPos,int zPos,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const;
public:
int m_iXResolution;
int m_iZResolution;
hkReal m_fHeightScale;
hkBoolR m_bUseProjectionBasedHeight;
hkEnum<HeightFieldType,hkUint8>m_ucHeightFieldType;
hkVector4_ m_kHeightScaleVector;
hkVector4_ m_kInverseScale;
hkVector4_ m_kOffset;
hkVector4_ SetCenterPosition;
public:
SampledHeightRayCastView():hkpHeightFieldShape_(HK_SHAPE_SAMPLED_HEIGHT_FIELD){}
SampledHeightRayCastView(FinishingFlag flag):hkpHeightFieldShape_(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_SAMPLED_HEIGHT_FIELD;
}
}
};
__forceinline hkReal SampledHeightRayCastView::getHeightAt(int x,int z)const
{
return GetHeightAtGridPoint(x,z);
}
__forceinline hkBoolR SampledHeightRayCastView::getTriangleFlip()const
{
return IsTriangleWindingFlipped();
}
class hkpRayHitCollector
{
public:
inline hkpRayHitCollector();
virtual void CollectRayHit(const hkpCdBody&cdBody,const RayCastHitResult&hitInfo)=0;
public:
hkReal m_fEarlyOutHitFraction;};__forceinline void SampledHeightRayCastView::_getHeightAndNormalAt(int x,int z,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const
{
normalOut.setAll3(1.0f);
if(getTriangleFlip())
{
hkReal h00=getHeightAt(x,z);
hkReal h11=getHeightAt(x+1,z+1);
if(subX>subZ)
{
hkReal h10=getHeightAt(x+1,z);
hkReal dx=h10-h00;
hkReal dz=h11-h10;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=1;
}
else
{
hkReal h01=getHeightAt(x,z+1);
hkReal dx=h11-h01;
hkReal dz=h01-h00;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=0;
}
}
else
{
hkReal h10=getHeightAt(x+1,z);
hkReal h01=getHeightAt(x,z+1);
if(subX+subZ>1.0f)
{
hkReal h11=getHeightAt(x+1,z+1);
hkReal dx=h11-h01;
hkReal dz=h11-h10;
heightOut=subZ*dz+h10+(subX-1.0f)*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=1;
}
else
{
hkReal h00=getHeightAt(x,z);
hkReal dx=h10-h00;
hkReal dz=h01-h00;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=0;
}
}
}
// @f3 0x009a6260 (community match, verified in this file)
// Diagnostic reconstruction of the heightfield ray cast at 0x009a6260 (audit variant 2: pack-native integer/vector member reads, SDK direct-member lane access in operator=, setAll3, add4, mul4(scalar); dead declarations removed; SDK term order in the height helper; twin parentheses).
// The walk retains the control-flow jumps from the SDK debug records and the New Vegas twin.
extern "C" double __cdecl sqrt(double);
inline float __cdecl sqrtf(float _X) { return ((float)sqrt((double)_X)); }
class hkpCdBody;
extern float __cdecl FUN_00404010(float, float);
namespace hk9a6 {
typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef signed short hkInt16;
typedef unsigned int hkUint32;
typedef int hkInt32;
typedef unsigned long hkUlong;
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef signed char hkInt8;
typedef hkUint32 hkpShapeKey;
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
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkVector4
{
	public:
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void setAll3(hkReal x);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkQuadReal& getQuad();
		__forceinline const hkQuadReal& getQuad() const;
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
inline const hkQuadReal& hkVector4::getQuad() const
{
	return reinterpret_cast<const hkQuadReal&>(x);
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
inline void hkVector4::setAll3(hkReal a)
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
	getQuad().x = v0.getQuad().x + v1.getQuad().x;
	getQuad().y = v0.getQuad().y + v1.getQuad().y;
	getQuad().z = v0.getQuad().z + v1.getQuad().z;
	getQuad().w = v0.getQuad().w + v1.getQuad().w;
}
inline void hkVector4::mul4(const hkVector4& a)
{
	getQuad().x *= a.getQuad().x;
	getQuad().y *= a.getQuad().y;
	getQuad().z *= a.getQuad().z;
	getQuad().w *= a.getQuad().w;
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
	getQuad().x = a.getQuad().x * b.getQuad().x;
	getQuad().y = a.getQuad().y * b.getQuad().y;
	getQuad().z = a.getQuad().z * b.getQuad().z;
	getQuad().w = a.getQuad().w * b.getQuad().w;
}
inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
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
	inline hkSimdReal hkVector4::lengthInverse3() const
	{
		hkReal l2 = (getQuad().x*getQuad().x) + (getQuad().y*getQuad().y) + (getQuad().z*getQuad().z);
		return l2 ? hkMath::sqrtInverse(l2) : 0;
	}
	inline void hkVector4::normalize3()
	{
		this->mul4( this->lengthInverse3() );

	}
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
}
extern const hk9a6::hkVector4 DAT_00f7b0c0;
namespace hk9a6 {
namespace hkVector4Util
{
__forceinline void __cdecl convertToUint16( const hkVector4& in, const hkVector4& offset, const hkVector4& scale, hkIntUnion64& out)
{
	hkVector4 x;
	x.setAdd4(in,offset);
	x.mul4(scale);
	hkVector4 magic = DAT_00f7b0c0;
	x.add4( magic );
	union
	{
		hkQuadReal q;
		hkUint32 i[4];
	} u;
	u.q = x.getQuad();
	out.i16[0] = static_cast<hkInt16>(u.i[0] >> 6);
	out.i16[1] = static_cast<hkInt16>(u.i[1] >> 6);
	out.i16[2] = static_cast<hkInt16>(u.i[2] >> 6);
	out.i16[3] = static_cast<hkInt16>(u.i[3] >> 6);
}
}
struct hkpShapeRayCastCollectorOutput
{
	inline hkpShapeRayCastCollectorOutput();
	inline void reset();
	hkVector4 m_normal;
	hkReal m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};
struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	public:
		enum { MAX_HIERARCHY_DEPTH = 8 };
	public:
		__forceinline hkpShapeRayCastOutput();
	private:
		__forceinline void _reset();
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
};
void hkpShapeRayCastCollectorOutput::reset( )
{
	m_hitFraction = 1.0f;
	m_extraInfo = -1;
}
hkpShapeRayCastCollectorOutput::hkpShapeRayCastCollectorOutput()
{
	reset();
}
void hkpShapeRayCastOutput::_reset()
{
	m_shapeKeyIndex = 0;
	m_shapeKeys[0] = 0xffffffff;
}
hkpShapeRayCastOutput::hkpShapeRayCastOutput()
{
	_reset();
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
class hkMonitorStream 
{
	public:
		static hkMonitorStream& getInstance()
		{
			extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;
			return *hkMonitorStream__m_instance.getData();
		}
		__forceinline char* __cdecl getEnd() { return m_end.val(); } 
		__forceinline char* __cdecl getCapacityMinus16() { return m_capacityMinus16.val(); } 
		__forceinline hkBool __cdecl memoryAvailable( ) 
		{ 
			return getEnd() < getCapacityMinus16(); 
		}
		__forceinline void __cdecl setEnd(char* ptr) {  m_end = ptr; } 
		struct Command
		{
			const char* m_commandAndMonitor;
		};
		typedef ::StringCursor::CommandTimingEntry TimerCommand;
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool		m_isBufferAllocatedOnTheHeap;
};
class hkpRayHitCollector
{
	public:
		virtual void addRayHit( const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInfo ) = 0;
		virtual ~hkpRayHitCollector() { }
		hkReal m_earlyOutHitFraction;
};
struct hkpShapeRayCastInput
{
	hkVector4 m_from;
	hkVector4 m_to;
};
class hkpShape
{
	public:
		virtual void slot00();
		virtual void slot01();
		virtual void slot02();
		virtual void slot03();
		virtual void slot04();
		virtual void slot05();
		virtual void slot06();
		virtual void slot07();
		virtual void slot08();
		virtual void slot09();
		virtual void slot10();
		hkUint16 m_memSizeAndFlags;
		hkUint16 m_referenceCount;
		hkUlong m_userData;
		int m_type;
};
class hkpSampledHeightFieldShape : public hkpShape
{
	public:
		virtual hkReal getHeightAt( int x, int z ) const = 0;
		virtual hkBool getTriangleFlip() const = 0;
		static __forceinline hkReal getHeightAtImpl( const hkpSampledHeightFieldShape* hf, int x, int z )
		{
			return hf->getHeightAt( x, z );
		}
		__forceinline void _getHeightAndNormalAt( int xPos, int zPos, hkReal subX, hkReal subZ, hkVector4& normalOut, hkReal& heightOut, int& triangleIndexOut ) const;
		int m_xRes;
		int m_zRes;
		hkReal m_heightCenter;
		hkBool m_useProjectionBasedHeight;
		hkUint8 m_heightfieldType;
		hkVector4 m_intToFloatScale;
		hkVector4 m_floatToIntScale;
		hkVector4 m_floatToIntOffsetFloorCorrected;
		hkVector4 m_extents;
};
__forceinline void hkpSampledHeightFieldShape::_getHeightAndNormalAt( int x, int z, hkReal subX, hkReal subZ, hkVector4& normalOut, hkReal& heightOut, int& triangleIndexOut ) const
{
	normalOut.setAll3( 1.0f );
	hkReal h10 = getHeightAtImpl( this, x+1, z );
	hkReal h01 = getHeightAtImpl( this, x, z+1 );
	if ( subX + subZ > 1.0f )
	{
		hkReal h11 = getHeightAtImpl( this, x+1, z+1 );
		hkReal dx = h11 - h01;
		hkReal dz = h11 - h10;
		heightOut = h10 + subZ * dz + (subX - 1.0f) * dx;
		normalOut(0) = -dx;
		normalOut(2) = -dz;
		triangleIndexOut = 1;
	}
	else
	{
		hkReal h00 = getHeightAtImpl( this, x, z );
		hkReal dx = h10 - h00;
		hkReal dz = h01 - h00;
		heightOut = h00 + subZ * dz + subX * dx;
		normalOut(0) = -dx;
		normalOut(2) = -dz;
		triangleIndexOut = 0;
	}
}
}
void SampledHeightRayCastView::FUN_00d24b50(const ShapeRayCastQuery& rayInput, const hkpCdBody& cdBody, hkBoolR reportPenetratingStartPosition, hkReal maxExtraPenetration, ::hkpRayHitCollector& rayCollector) const
{
	typedef hk9a6::hkReal hkReal;
	typedef hk9a6::hkUint32 hkUint32;
	typedef hk9a6::hkBool hkBool;
	typedef hk9a6::hkVector4 hkVector4;
	typedef hk9a6::hkIntUnion64 hkIntUnion64;
	typedef hk9a6::hkpShapeRayCastOutput hkpShapeRayCastOutput;
	typedef hk9a6::hkpShapeRayCastInput hkpShapeRayCastInput;
	typedef hk9a6::hkpRayHitCollector hkpRayHitCollector;
	typedef hk9a6::hkpSampledHeightFieldShape hkpSampledHeightFieldShape;
	typedef hk9a6::hkMonitorStream hkMonitorStream;
	namespace hkMath = hk9a6::hkMath;
	namespace hkVector4Util = hk9a6::hkVector4Util;
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "T" "t" "rcHeightFild"; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };

	hkIntUnion64 intFrom;
	hkVector4Util::convertToUint16( reinterpret_cast<const hkVector4&>( rayInput.m_vFrom ), reinterpret_cast<const hkVector4&>( m_kOffset ), reinterpret_cast<const hkVector4&>( m_kInverseScale ), intFrom );

	int ep[3];
	ep[0] = intFrom.i16[0];
	ep[2] = intFrom.i16[2];

	hkVector4 from; from.setMul4( reinterpret_cast<const hkVector4&>( rayInput.m_vFrom ), reinterpret_cast<const hkVector4&>( m_kInverseScale ) );
	hkVector4 to;   to.setMul4( reinterpret_cast<const hkVector4&>( rayInput.m_vTo ), reinterpret_cast<const hkVector4&>( m_kInverseScale ) );


	from(3) = from(1);
	to(3) = to(1);
	from(1) = from(0) + from(2);
	to(1) = to(0) + to(2);

	hkVector4 absRayDir;
	hkVector4 gridLineDistance;
	hkVector4 signedGridLineDistance;
	int signRayDir[3];
	hkReal distToNextCell[3];
	{
		for (int i = 0; i < 3; i++ )
		{
			hkReal delta = to(i) - from(i);
			hkReal fabsDelta = hkMath::fabs( delta );
			absRayDir(i) = fabsDelta;
			if ( fabsDelta < 3.0517578125e-05 )
			{
				gridLineDistance(i) = 0.0f;
				signRayDir[i] = -1;
				distToNextCell[i] = 3.40282e+38f;
				continue;
			}
			hkReal invDelta = 1.0f / delta;
			signedGridLineDistance(i) = invDelta;
			if ( delta < 0.0 )
			{
				signRayDir[i] = -1;
				gridLineDistance(i) = -invDelta;
			}
			else
			{
				signRayDir[i] = 1;
				ep[i] += 1;
				gridLineDistance(i) = invDelta;
			}
			distToNextCell[i] = (ep[i] - from(i)) * invDelta;
		}
	}

	if ( gridLineDistance(0) + gridLineDistance(2) == 0.0 || gridLineDistance(0) + gridLineDistance(1) == 0.0 || gridLineDistance(1) + gridLineDistance(2) == 0.0 )
	{
		int ix = ep[0];
		int iz = ep[2];
		if ( hkUint32(ix) >= hkUint32(m_iXResolution-1) || hkUint32(iz) >= hkUint32(m_iZResolution-1) )
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return;
		}
		hkpShapeRayCastOutput output;
		hkReal fieldHeight;
		int triangleIndexOut;
		reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->_getHeightAndNormalAt( ix, iz, from(0) - ix, from(2) - iz, output.m_normal, fieldHeight, triangleIndexOut );
		const hkReal h0 = from(3) - fieldHeight;
		const hkReal h1 = to(3) - fieldHeight;
		if ( h1 > h0 )
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return;
		}
		hkReal hitFraction;
		if ( reportPenetratingStartPosition && h0 < 0.0 )
		{
			if ( h1 > h0 - maxExtraPenetration )
			{
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				return;
			}
			hitFraction = 0.0f;
		}
		else
		{
			if ( h0 < 0.0 || h1 >= 0.0 )
			{
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				return;
			}
			hitFraction = h0 / ( h0 - h1 );
		}
		if ( hitFraction < reinterpret_cast<hkpRayHitCollector&>( rayCollector ).m_earlyOutHitFraction )
		{
			output.m_normal.setMul4( reinterpret_cast<const hkVector4&>( m_kInverseScale ), output.m_normal );
			output.m_normal.normalize3();
			output.m_hitFraction = hitFraction;
			output.m_extraInfo = (iz<<16) + triangleIndexOut + ix*2;
			reinterpret_cast<hkpRayHitCollector&>( rayCollector ).addRayHit( cdBody, output );
		}
		{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
		return;
	}

	hkVector4 clippedFrom = from;
	{
		int origEp0 = ep[0];
		int origEp2 = ep[2];
		while (1)
		{
			hkReal ratio;
			if ( signRayDir[0] > 0 )
			{
				if ( ep[0] > 0 ) { break; }
				if ( to(0) < 0.0 )
				{
					{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
					return;
				}
				ratio = -from(0) * gridLineDistance(0);
				ep[0] = 1;
			}
			else
			{
				if ( ep[0] <= m_iXResolution - 2 ) { break; }
				const hkReal maxVal = hkReal(m_iXResolution-1);
				if ( to(0) > maxVal )
				{
					{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
					return;
				}
				ratio = (from(0) - maxVal) * gridLineDistance(0);
				ep[0] = m_iXResolution - 2;
			}
			distToNextCell[0] = ratio + gridLineDistance(0);
			clippedFrom.setInterpolate4( from, to, ratio );
			ep[2] = origEp2 + fnv_FloatToInt( ratio * absRayDir(2) ) * signRayDir[2] - 2;
			while ( clippedFrom(2) >= hkReal(ep[2]) )
			{
				ep[2] = ep[2] + 1;
			}
			ep[2] = ep[2] + (signRayDir[2]>>1);
			distToNextCell[2] = (ep[2] - from(2)) * signedGridLineDistance(2);
			break;
		}

		while (1)
		{
			hkReal ratio;
			if ( signRayDir[2] > 0 )
			{
				if ( ep[2] > 0 ) { break; }
				if ( to(2) < 0.0 )
				{
					{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
					return;
				}
				ratio = -from(2) * gridLineDistance(2);
				ep[2] = 1;
			}
			else
			{
				if ( ep[2] <= m_iZResolution - 2 ) { break; }
				const hkReal maxVal = hkReal(m_iZResolution-1);
				if ( to(2) > maxVal )
				{
					{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
					return;
				}
				ratio = (from(2) - maxVal) * gridLineDistance(2);
				ep[2] = m_iZResolution - 2;
			}
			distToNextCell[2] = ratio + gridLineDistance(2);
			clippedFrom.setInterpolate4( from, to, ratio );
			ep[0] = origEp0 + fnv_FloatToInt( ratio * absRayDir(0) ) * signRayDir[0] - 2;
			while ( clippedFrom(0) >= hkReal(ep[0]) )
			{
				ep[0] = ep[0] + 1;
			}
			ep[0] = ep[0] + (signRayDir[0]>>1);
			distToNextCell[0] = (ep[0] - from(0)) * signedGridLineDistance(0);
			break;
		}

		{
			if ( hkUint32(ep[0]) >= hkUint32(m_iXResolution) )
			{
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				return;
			}
			int x = ep[0] - signRayDir[0];
			if ( hkUint32(x) >= hkUint32(m_iXResolution) )
			{
				{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
				return;
			}
		}
	}

	hkBool diagDir = (signRayDir[0] ^ signRayDir[2]) >= 0;
	if ( gridLineDistance(1) == 0.0 )
	{
		diagDir = false;
	}

	int inMoreDistantTriangle = 2;
	{
	ep[1] = ep[0] + ep[2];
		hkReal subPos = clippedFrom(1) - ep[1];
		if ( diagDir )
		{
			if ( hkMath::fabs( subPos ) > 1.0 )
			{
				ep[1] = ep[1] - signRayDir[1];
			}
			else
			{
				inMoreDistantTriangle ^= 2;
			}
		}
		else
		{
			subPos = signRayDir[1] * subPos;
			if ( subPos > 0.0 )
			{
				inMoreDistantTriangle ^= 2;
				ep[1] = ep[1] + signRayDir[1];
			}
		}
		if ( gridLineDistance(1) != 0.0 )
		{
			distToNextCell[1] = (ep[1] - from(1)) * gridLineDistance(1) * signRayDir[1];
		}
		else
		{
			distToNextCell[1] = 3.40282e+38f;
		}
	}

	int backWalkingDir;
	{
		hkReal distToPrevCell[3];
		for (int i = 0; i < 3; i++ )
		{
			if ( gridLineDistance(i) == 0.0 )
			{
				distToPrevCell[i] = -3.40282e+38f;
				continue;
			}
			hkReal cd = distToNextCell[i] - gridLineDistance(i);
			distToPrevCell[i] = cd;
		}

		if ( diagDir )
		{
			backWalkingDir = (inMoreDistantTriangle == 0) ? 1 : ( distToPrevCell[0] > distToPrevCell[2] ? 0 : 2 );
		}
		else if ( absRayDir(0) < absRayDir(2) )
		{
			backWalkingDir = inMoreDistantTriangle ? 2 : ( distToPrevCell[0] > distToPrevCell[1] ? 0 : 1 );
		}
		else
		{
			backWalkingDir = inMoreDistantTriangle ? 0 : ( distToPrevCell[1] > distToPrevCell[2] ? 1 : 2 );
		}
		ep[backWalkingDir] -= signRayDir[backWalkingDir];
		distToNextCell[backWalkingDir] -= gridLineDistance(backWalkingDir);
	}

	hkReal lastFieldHeight = 3.40282e+38f;
	hkReal lastRayHeight = 0.0f;
	hkReal distToLastCrossedCell = -1.0f;

	int sInd = backWalkingDir;
	goto examineCrossedGridBorder;

	while (1)
	{
		if ( diagDir )
		{
			sInd = (inMoreDistantTriangle == 0) ? 1 : ( distToNextCell[0] < distToNextCell[2] ? 0 : 2 );
		}
		else if ( absRayDir(0) < absRayDir(2) )
		{
			sInd = inMoreDistantTriangle ? 2 : ( distToNextCell[0] < distToNextCell[1] ? 0 : 1 );
		}
		else
		{
			sInd = inMoreDistantTriangle ? 0 : ( distToNextCell[1] < distToNextCell[2] ? 1 : 2 );
		}

examineCrossedGridBorder:
		if ( hkUint32(ep[0]) >= hkUint32(m_iXResolution) || hkUint32(ep[2]) >= hkUint32(m_iZResolution) )
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return;
		}

		if ( distToLastCrossedCell > reinterpret_cast<hkpRayHitCollector&>( rayCollector ).m_earlyOutHitFraction )
		{
			break;
		}

		const hkReal fraction = distToNextCell[sInd];
		hkReal hitFraction;
		hkReal rayHeight;
		int triangleIndex;
		hkReal fieldHeight;
		{
			hkVector4 curPos; curPos.setInterpolate4( from, to, fraction );
			int x0 = ep[0];
			int x1 = ep[0] - signRayDir[0];
			int z0 = ep[2];
			if ( sInd == 0 )
			{
				int z1 = ep[2] - signRayDir[2];
				hkReal h0 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z1 );
				hkReal h1 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z0 );
				hkReal frac = hkMath::fabs( curPos(2) - ep[2] );
				fieldHeight = (h0 - h1) * frac + h1;
			}
			else if ( sInd == 2 )
			{
				hkReal h0 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z0 );
				hkReal h1 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z0 );
				hkReal frac = hkMath::fabs( curPos(0) - ep[0] );
				fieldHeight = (h0 - h1) * frac + h1;
			}
			else
			{
				int z1 = z0;
				hkReal frac = hkMath::fabs( curPos(0) - ep[0] );
				if ( diagDir )
				{
					z1 = z1 - signRayDir[2];
				}
				else
				{
					z0 = z0 - signRayDir[2];
				}
				hkReal h0 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z0 );
				hkReal h1 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z1 );
				fieldHeight = (h0 - h1) * frac + h1;
			}
			rayHeight = curPos(3);
		}

		if ( reportPenetratingStartPosition )
		{
			if ( rayHeight >= fieldHeight )
			{
				goto setAndWalk;
			}
			{
				const hkReal height = rayHeight - fieldHeight;
				const hkReal lastHeight = lastRayHeight - lastFieldHeight;
				const hkReal cellFraction = fraction - distToLastCrossedCell;
				if ( height >= lastHeight - cellFraction * maxExtraPenetration )
				{
					goto setAndWalk;
				}
				if ( lastHeight <= 0.0 )
				{
					hitFraction = FUN_00404010( 0.0f, distToLastCrossedCell );
					goto reportHit;
				}
			}
		}
		else
		{
			if ( rayHeight >= fieldHeight || lastRayHeight < lastFieldHeight )
			{
setAndWalk:
				lastFieldHeight = fieldHeight;
				lastRayHeight = rayHeight;
				distToLastCrossedCell = fraction;
				goto walk;
			}
		}
		{
			hkReal height = rayHeight - fieldHeight;
			if ( distToLastCrossedCell >= 0.0 )
			{
				hkReal lastHeight = lastRayHeight - lastFieldHeight;
				hkReal subFraction = lastHeight / ( lastHeight - height );
				hitFraction = (fraction - distToLastCrossedCell) * subFraction + distToLastCrossedCell;
			}
			else
			{
				hkReal f = fraction / ( fraction - distToLastCrossedCell );
				hkReal startFieldHeight = lastFieldHeight * f + (1.0f - f) * fieldHeight;
				hkReal lastHeight = from(3) - startFieldHeight;
				if ( lastHeight < 0.0 )
				{
					if ( !reportPenetratingStartPosition )
					{
						goto setAndWalk;
					}
					lastHeight = 0.0f;
				}
				hkReal subFraction = lastHeight / ( lastHeight - height );
				hitFraction = fraction * subFraction;
			}
		}
reportHit:
		lastFieldHeight = fieldHeight;
		lastRayHeight = rayHeight;
		distToLastCrossedCell = fraction;

		if ( hitFraction > reinterpret_cast<hkpRayHitCollector&>( rayCollector ).m_earlyOutHitFraction )
		{
			{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
			return;
		}

		{
			hkpShapeRayCastOutput output;
			output.m_normal(3) = 0.0f;
			output.m_normal(1) = 1.0f;
			{
				int x0 = ep[0];
				int x1 = ep[0] - signRayDir[0];
				int z0 = ep[2];
				int z1 = ep[2] - signRayDir[2];
				if ( diagDir )
				{
					hkReal h0 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z1 );
					hkReal h1 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z0 );
					if ( sInd == 1 )
					{
						hkReal h2 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z1 );
						output.m_normal(0) = h2 - h0;
						output.m_normal(2) = h2 - h1;
						triangleIndex = z1 > z0;
					}
					else
					{
						hkReal h2 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z0 );
						output.m_normal(0) = h1 - h2;
						output.m_normal(2) = h0 - h2;
						triangleIndex = z0 > z1;
					}
				}
				else
				{
					hkReal h0 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z1 );
					hkReal h1 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z0 );
					if ( sInd == 0 || ( sInd == 1 && absRayDir(0) < absRayDir(2) ) )
					{
						hkReal h2 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x0, z1 );
						output.m_normal(0) = h0 - h2;
						output.m_normal(2) = h2 - h1;
						triangleIndex = z1 > z0;
					}
					else
					{
						hkReal h2 = reinterpret_cast<const hkpSampledHeightFieldShape*>( this )->getHeightAt( x1, z0 );
						output.m_normal(0) = h2 - h1;
						output.m_normal(2) = h0 - h2;
						triangleIndex = z0 > z1;
					}
				}
			}
			output.m_normal(0) *= signRayDir[0];
			output.m_normal(2) *= signRayDir[2];
			output.m_normal.setMul4( reinterpret_cast<const hkVector4&>( m_kInverseScale ), output.m_normal );
			output.m_normal.normalize3();
			output.m_hitFraction = hitFraction;
			{
				int ix = ep[0] - (signRayDir[0]>>1) - 1;
				int iz = ep[2] - (signRayDir[2]>>1) - 1;
				output.m_extraInfo = (iz<<16) + triangleIndex + ix*2;
			}
			reinterpret_cast<hkpRayHitCollector&>( rayCollector ).addRayHit( cdBody, output );
			if ( reportPenetratingStartPosition )
			{
				reportPenetratingStartPosition = false;
			}
		}
walk:
		inMoreDistantTriangle ^= 2;
		ep[sInd] += signRayDir[sInd];
		distToNextCell[sInd] += gridLineDistance(sInd);
	}
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_pCommandName = "E" "t" ""; h->setTime(); mStream.setEnd( (char*)(h+1) ); } };
}

