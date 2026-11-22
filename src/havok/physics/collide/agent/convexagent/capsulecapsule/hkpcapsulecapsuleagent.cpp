#include "f3_common.h"
// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Callback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke(unsigned short, int);
};

struct FUN_00d3b3d0_Class
{
    virtual void release(int);
    int unk04;
    Callback* unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    void hkpCapsuleCapsuleAgent_cleanup(int);
};

// Calls invoke on unk08 for each of the three IDs at unk0C unless it is 0xffff, then releases the object.
// @fnv 0x00d3b3d0
// pdb: hkpCapsuleCapsuleAgent::cleanup | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: constraintOwner
// pdb: hkpCapsuleCapsuleAgent::cleanup | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, vtable, high (was: InvokeCallbacksAndRelease)
void FUN_00d3b3d0_Class::hkpCapsuleCapsuleAgent_cleanup(int value)
{
    unsigned short* id = &unk0C;
    int iRemaining = 3;
    do
    {
        unsigned short usId = *id;
        if (usId != 0xffff)
            unk08->invoke(usId, value);
        ++id;
        --iRemaining;
    } while (iRemaining != 0);

    if (this != 0)
        release(1);
}

typedef void (__cdecl* HandlerFn)();

void __cdecl FUN_00d3b420();
void __cdecl FUN_00d3bd80();

struct HandlerSet {
    HandlerFn m_pfnFirst;
    HandlerFn m_pfnSecond;
    HandlerFn m_pfnThird;
    HandlerFn m_pfnFourth;
    char m_cFlagA;
    char m_cFlagB;
};

struct Registry {
    void FUN_00cfbbe0(HandlerSet* apHandlers, int aiFirst, int aiSecond);
};

// Fills a HandlerSet with four handler functions and zeroed flags, then registers it with the registry using 5 and 5.
// @f3 0x009c5720 (community match, verified in this file)
// pdb: hkpCapsuleCapsuleAgent::registerAgent | hkpCapsuleCapsuleAgent.obj | fnv360_0721_beta, objrun, medium
// pdb params: dispatcher
void RegisterHandlers(Registry* registry) {
    void hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent();
    void hkpCapsuleCapsuleAgent_staticGetPenetrations();
    void hkpCapsuleCapsuleAgent_staticGetClosestPoints();
    void FUN_00a3ab70();
    HandlerSet handlers;
    handlers.m_cFlagA=0;
    handlers.m_cFlagB=0;
    handlers.m_pfnFirst=hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent;
    handlers.m_pfnSecond=hkpCapsuleCapsuleAgent_staticGetPenetrations;
    handlers.m_pfnThird=hkpCapsuleCapsuleAgent_staticGetClosestPoints;
    handlers.m_pfnFourth=FUN_00a3ab70;
    registry->FUN_00cfbbe0(&handlers,6,6);
}


void __cdecl FUN_00d3b420(const void* a, const void* b, const void* c, void* d);

struct D3B6D0Agent {
    virtual void hkpCapsuleCapsuleAgent_getPenetrations(const void* a, const void* b, const void* c, void* d);
};

// @fnv 0x00d3b6d0
// pdb: hkpCapsuleCapsuleAgent::getPenetrations | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, vtable, high
// pdb params: bodyA, bodyB, input, collector
// pdb: hkpCapsuleCapsuleAgent::getPenetrations | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, vtable, high (was: ForwardToHandler)
void D3B6D0Agent::hkpCapsuleCapsuleAgent_getPenetrations(const void* apArg1, const void* apArg2, const void* apArg3, void* apArg4)
{
    FUN_00d3b420(apArg1, apArg2, apArg3, apArg4);
}

struct __declspec(intrin_type) __declspec(align(16)) __m128 { float x, y, z, w; };
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);


struct Vec4 { float x, y, z, w; };
struct Mat44 { Vec4 row0, row1, row2, row3; };
struct JointTransform {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float blend;
    float unk14;
    float unk18;
    float unk1C;
    float frameVectors[8];
};
struct TransformInput {
    JointTransform* bone;
    int unk04;
    const Mat44* matrix;
};
struct BlendParameter {
    float unk00;
    float unk04;
    float fraction;
};

void __cdecl FUN_00cd6260(const void* a, float fraction, const void* b, float weightA, float weightB, int flags);

// Transforms each bone's two frameVectors by its matrix, then calls FUN_00cd6260 with the results, each bone's blend value and the parameter's fraction.
// @fnv 0x00d3b8e0
TransformInput* volatile inputFirst;
TransformInput* volatile inputSecond;
const BlendParameter* volatile inputParameter;
volatile int inputFlags;

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
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
__forceinline operator TYPE()const
{
return val();
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
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};

extern "C"{


};
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.m_rotation.getColumn(0);
const hkVector4 r1=t.m_rotation.getColumn(1);
const hkVector4 r2=t.m_rotation.getColumn(2);
const hkVector4 r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
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
__forceinline hkBool __cdecl memoryAvailable()
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
hkBool m_bFlag;
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
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};class Vector4WithInt24W:public hkVector4
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
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpCdBodyPairCollector;
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
class hkpCapsuleCapsuleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl FUN_00d3bd80(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkContactPointId m_usContactPointId[3];
};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
class hkpCapsuleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4*GetIndexedVertices()const;
public:
hkpCapsuleShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_CAPSULE;}
protected:
hkVector4 m_kVertexA;};const hkVector4*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}
extern "C"
{
hkResult __cdecl FindCapsuleCapsuleContact(const hkVector4*capsA,hkReal capsARadius,const hkVector4*capsB,hkReal capsBRadius,hkReal collisionTolerance,hkContactPoint&pointOut);}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}

extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);

extern "C" __m128 _mm_load_ps(const float*);
class CapsulePointRotation;
class CapsulePointTransform;

class CapsulePointVector {
public:
    __m128 m_vComponents;
    __forceinline __m128 quadValue() const { return m_vComponents; }
    __forceinline const __m128& quadReference() const { return m_vComponents; }
    __forceinline void getQuad(__m128& out) const { out = m_vComponents; }
    __forceinline void setQuad(__m128 value) { m_vComponents = value; }
    __forceinline void setVector(const CapsulePointVector& value) { m_vComponents = value.m_vComponents; }

    float& operator()(int i) { return (&m_vComponents.x)[i]; }
    const float& operator()(int i) const { return (&m_vComponents.x)[i]; }
    __forceinline void _setTransformedPos(const CapsulePointTransform& t, const CapsulePointVector& b);
};

class CapsulePointRotation {
public:
    CapsulePointVector m_kColumn0;
    CapsulePointVector m_kColumn1;
    CapsulePointVector m_kColumn2;
    __forceinline CapsulePointRotation(const CapsulePointRotation& o) : m_kColumn0(o.m_kColumn0), m_kColumn1(o.m_kColumn1), m_kColumn2(o.m_kColumn2) {}
};

class CapsulePointTransform {
public:
    CapsulePointRotation m_rotation;
    CapsulePointVector m_vTranslation;
    __forceinline CapsulePointTransform(const CapsulePointTransform& o) : m_rotation(o.m_rotation), m_vTranslation(o.m_vTranslation) {}
};

__forceinline void CapsulePointVector::_setTransformedPos(const CapsulePointTransform& t, const CapsulePointVector& b)
{
    const CapsulePointRotation& r = t.m_rotation;
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct CapsulePointTransforms {
    static __forceinline void TransformPointArray(const CapsulePointTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut, CapsulePointVector& scratch)
    {
        CapsulePointVector c0 = t.m_rotation.m_kColumn0;
        CapsulePointVector c1 = t.m_rotation.m_kColumn1;
        CapsulePointVector c2 = t.m_rotation.m_kColumn2;
        scratch = t.m_vTranslation;
        __m128 saved = _mm_load_ps((&scratch.m_vComponents.x));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            __m128 r0 = _mm_mul_ps(b0, c0.m_vComponents);
            __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            __m128 r1 = _mm_mul_ps(b1, c1.m_vComponents);
            __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            __m128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, saved));
        } while (--i >= 0);
    }
    static __forceinline void transformPoints2(const CapsulePointTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut)
    {
        vectorsOut[0] = t.m_rotation.m_kColumn0;
        __m128 saved = vectorsOut[0].m_vComponents;
        CapsulePointVector c1 = t.m_rotation.m_kColumn1;
        CapsulePointVector c2 = t.m_rotation.m_kColumn2;
        CapsulePointVector c3 = t.m_vTranslation;
        CapsulePointVector q1; q1.setQuad(_mm_load_ps((&c1.m_vComponents.x)));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            __m128 r0 = _mm_mul_ps(b0, saved);
            __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            __m128 r1 = _mm_mul_ps(b1, q1.m_vComponents);
            __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            __m128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, c3.m_vComponents));
        } while (--i >= 0);
    }
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream() { return (MonitorStream*)TlsGetValue(DAT_0126835c); }
};

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}



extern "C" hkResult __cdecl FUN_00cd6260(const CapsulePointVector* capsA, float capsARadius, const CapsulePointVector* capsB, float capsBRadius, float collisionTolerance, hkContactPoint& cpoint);

// Transforms two capsule endpoint pairs into world space, queries their contact point, and adds it to the collector on success.
// @f3 0x009c50d0 (community match, verified in this file)
struct __declspec(align(16)) CapsuleVec4 {
    float x, y, z, w;
    __forceinline CapsuleVec4() {}
    __forceinline void operator=(const CapsuleVec4& v) {
        x = v.x; y = v.y; z = v.z; w = v.w;
    }
    __forceinline float& operator()(int i) { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
    __forceinline const float& operator()(int i) const { if (i == 0) return x; if (i == 1) return y; if (i == 2) return z; return w; }
};

struct CapsuleMat3 {
    CapsuleVec4 m_col0;
    CapsuleVec4 m_col1;
    CapsuleVec4 m_col2;
    __forceinline CapsuleVec4& getColumn(int x) { if (x == 0) return m_col0; if (x == 1) return m_col1; return m_col2; }
    __forceinline const CapsuleVec4& getColumn(int x) const { if (x == 0) return m_col0; if (x == 1) return m_col1; return m_col2; }
    __forceinline float& operator()(int r, int c) { return getColumn(c)(r); }
    __forceinline const float& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct __declspec(align(16)) CapsuleRot : public CapsuleMat3 {};

struct CapsuleTransform {
    CapsuleRot m_rotation;
    CapsuleVec4 m_translation;
    __forceinline CapsuleTransform(const CapsuleTransform& t) {
        const CapsuleVec4 r0 = t.m_rotation.getColumn(0);
        const CapsuleVec4 r1 = t.m_rotation.getColumn(1);
        const CapsuleVec4 r2 = t.m_rotation.getColumn(2);
        const CapsuleVec4 r3 = t.m_translation;
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_translation = r3;
    }
    __forceinline const CapsuleRot& getRotation() const { return m_rotation; }
    __forceinline const CapsuleVec4& getTranslation() const { return m_translation; }
};

struct CapsuleToleranceView {
    int unk00;
    float tolerance;
};

struct CapsuleScalar973 {
    float value;
    __forceinline CapsuleScalar973(float v) : value(v) {}
    friend __forceinline double operator*(float component, const CapsuleScalar973& scalar) { return scalar.value * component; }
};

__forceinline void BuildCapsuleEndpoints(const hkTransform& transform,
                                          const hkVector4* points, hkVector4* output)
{
    CapsuleTransform unaliased = reinterpret_cast<const CapsuleTransform&>(transform);
    int index = 1;
    do {
        const CapsuleVec4& b = reinterpret_cast<const CapsuleVec4&>(points[index]);
        CapsuleVec4& t = reinterpret_cast<CapsuleVec4&>(output[index]);
        const CapsuleRot& r = unaliased.getRotation();
        const CapsuleVec4& tr = unaliased.getTranslation();
        CapsuleScalar973 v0(b(0));
        CapsuleScalar973 v1(b(1));
        CapsuleScalar973 v2(b(2));
        
        t(0) = r(0, 0) * v0 + r(0, 1) * v1 + r(0, 2) * v2 + tr(0);
        t(1) = r(1, 0) * v0 + r(1, 1) * v1 + r(1, 2) * v2 + tr(1);
        t(2) = r(2, 0) * v0 + r(2, 1) * v1 + r(2, 2) * v2 + tr(2);
    
        t(3) = 0;
    } while (--index >= 0);
}

__forceinline void RecordCapsuleEvent(const char* name)
{
    MonitorStream* stream = MonitorStream::GetMonitorStream();
    if (stream->m_kRayEnd < stream->m_pCurrentCommand) {
        CommandTimingEntry* entry = reinterpret_cast<CommandTimingEntry*>(stream->m_kRayEnd);
        entry->m_pCommandName = name;
        unsigned int count;
        __asm {
            rdtsc
            mov dword ptr [count], eax
        }
        entry->m_uiStartTicks = count;
        stream->m_kRayEnd = reinterpret_cast<char*>(entry + 1);
    }
}

__forceinline hkResult GetCapsuleCapsulePoint(const hkpCdBody& firstBody, const hkpCdBody& secondBody,
                                              const CollisionAgentContext& options, hkContactPoint& pointOut)
{
    const hkpCapsuleShape* first = static_cast<const hkpCapsuleShape*>(firstBody.getShape());
    const hkpCapsuleShape* second = static_cast<const hkpCapsuleShape*>(secondBody.getShape());
    hkVector4 firstWorld[2];
    BuildCapsuleEndpoints(firstBody.getTransform(), first->GetIndexedVertices(), firstWorld);
    hkVector4 secondWorld[2];
    BuildCapsuleEndpoints(secondBody.getTransform(), second->GetIndexedVertices(), secondWorld);
    const float tolerance = reinterpret_cast<const CapsuleToleranceView&>(options).tolerance;
    return FUN_00cd6260(reinterpret_cast<const CapsulePointVector*>(firstWorld), first->getRadius(),
                        reinterpret_cast<const CapsulePointVector*>(secondWorld), second->getRadius(),
                        tolerance, pointOut);
}

// pdb: hkpCapsuleCapsuleAgent::getClosestPoints | hkpCapsuleCapsuleAgent.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpCapsuleCapsuleAgent_getClosestPoints(const hkpCdBody& firstBody, const hkpCdBody& secondBody,
                            const CollisionAgentContext& options, hkpCdPointCollector& collector)
{
    RecordCapsuleEvent(DAT_010d1074);
    ContactPointPair hit(firstBody, secondBody);
    if (GetCapsuleCapsulePoint(firstBody, secondBody, options, hit.m_kPoint) == HK_SUCCESS)
        collector.AddCdPoint(hit);
    RecordCapsuleEvent(DAT_010c41f8);
}

