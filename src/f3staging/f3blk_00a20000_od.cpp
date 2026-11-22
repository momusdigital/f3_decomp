// src/f3staging/f3blk_00a20000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a35270 (community match, verified in this file)
namespace f3m_00a35270 {
// FLAGS: /MT /O2 /GS- /EHs-c- /Gy



typedef float hkReal;
typedef unsigned short hkVertexId;

struct S00a35270_hkBool
{
    char m_bool;
    S00a35270_hkBool(bool b) { m_bool = (char)b; }
};

__declspec(align(16)) struct S00a35270_hkVector4
{
    hkReal x, y, z, w;

    __forceinline void subMul4(hkReal r, const S00a35270_hkVector4& a)
    {
        x -= r * a.x;
        y -= r * a.y;
        z -= r * a.z;
        w -= r * a.w;
    }
    __forceinline void setAddMul4(const S00a35270_hkVector4& a, const S00a35270_hkVector4& b, hkReal r)
    {
        x = a.x + r * b.x;
        y = a.y + r * b.y;
        z = a.z + r * b.z;
        w = a.w + r * b.w;
    }
};

struct S00a35270_hkTransform
{
    S00a35270_hkVector4 m_col0;
    S00a35270_hkVector4 m_col1;
    S00a35270_hkVector4 m_col2;
    S00a35270_hkVector4 m_translation;
    void setMulInverseMul(const S00a35270_hkTransform& a, const S00a35270_hkTransform& b);
};

struct S00a35270_hkpConvexShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void convertVertexIdsToVertices(const hkVertexId* ids, int numIds, S00a35270_hkVector4* verticesOut) const;
    int m_userData;
    int m_type;
    int m_unk0c;
    hkReal m_radius;
};

struct S00a35270_hkCdBody
{
    const S00a35270_hkpConvexShape* m_shape;
    unsigned int m_shapeKey;
    const S00a35270_hkTransform* m_motion;
    const S00a35270_hkCdBody* m_parent;
};

struct S00a35270_hkpCollisionInput
{
    int m_unk00;
    hkReal m_tolerance;
};

struct S00a35270_hkpGskCache
{
    hkVertexId m_vertices[4];
    unsigned char m_dimA;
    unsigned char m_dimB;
    unsigned char m_maxDimA_maxDimB;
    unsigned char m_gskFlags;
};

// Fake match: reference-output staging preserves the original cache-load and solver-store schedule.
static __forceinline const hkVertexId* ReadCache(const S00a35270_hkpGskCache& cache, int& b, unsigned& flags, int& a)
{
    b = cache.m_dimB;
    flags = cache.m_maxDimA_maxDimB;
    a = cache.m_dimA;
    return cache.m_vertices;
}

struct S00a35270_hkpExtendedGskOut
{
    S00a35270_hkVector4 m_normalInA;
    S00a35270_hkVector4 m_pointAinA;
    hkReal m_distance;
    S00a35270_hkVector4 m_pointBinB;
    S00a35270_hkVector4 m_normalInWorld;
};

struct S00a35270_hkpGsk
{
    int m_dimA;
    int m_dimB;
    int m_maxDimA;
    int m_maxDimB;
    int m_doNotHandlePenetration;
    int m_featureChange;
    S00a35270_hkVector4 m_verticesA[4];
    S00a35270_hkVector4 m_verticesBinA[4];
    S00a35270_hkVector4 m_verticesAinB[4];
    S00a35270_hkVector4 m_verticesB[4];
    S00a35270_hkVector4 m_verticesBinB[4];
    S00a35270_hkVector4 m_lastNormal;
    S00a35270_hkVector4 m_lastPoint;

    __forceinline void init(const S00a35270_hkpConvexShape* shapeA, const S00a35270_hkpConvexShape* shapeB, const S00a35270_hkpGskCache& cache)
    {
        m_dimA = cache.m_dimA;
        m_dimB = cache.m_dimB;
        m_maxDimA = cache.m_maxDimA_maxDimB & 0xf;
        m_maxDimB = cache.m_maxDimA_maxDimB >> 4;
        shapeA->convertVertexIdsToVertices(cache.m_vertices, m_dimA, m_verticesA);
        shapeB->convertVertexIdsToVertices(cache.m_vertices + m_dimA, m_dimB, m_verticesB);
    }
    void hkpGsk_getClosestFeature(const S00a35270_hkpConvexShape* shapeA, const S00a35270_hkpConvexShape* shapeB, const S00a35270_hkTransform& aTb, S00a35270_hkVector4& separatingNormal);
    void FUN_00a30af0(S00a35270_hkpGskCache& cache);
    void hkpGsk_convertFeatureToClosestDistance(const S00a35270_hkVector4& separatingNormal, S00a35270_hkpExtendedGskOut& output);
};

struct S00a35270_hkpGskBaseAgent
{
    void* m_vtable;
    int m_unk04;
    int m_contactMgr;
    S00a35270_hkpGskCache m_cache;

    S00a35270_hkBool FUN_00a35270(const S00a35270_hkCdBody& bodyA, const S00a35270_hkCdBody& bodyB, const S00a35270_hkpCollisionInput& input, S00a35270_hkpExtendedGskOut& output);
};

// pdb: hkpGskBaseAgent::getClosestPoint | hkpGskBaseAgent.obj | fnv360_0822_retail, objrun, medium
// pdb params: bodyA, bodyB, input, output
S00a35270_hkBool S00a35270_hkpGskBaseAgent::FUN_00a35270(const S00a35270_hkCdBody& bodyA, const S00a35270_hkCdBody& bodyB, const S00a35270_hkpCollisionInput& input, S00a35270_hkpExtendedGskOut& output)
{
    const S00a35270_hkpConvexShape* shapeA = bodyA.m_shape;
    const S00a35270_hkpConvexShape* shapeB = bodyB.m_shape;

    S00a35270_hkTransform aTb;
    aTb.setMulInverseMul(*bodyA.m_motion, *bodyB.m_motion);

    S00a35270_hkpGsk gsk;
    int countA, countB;
    unsigned flags;
    const hkVertexId* ids = ReadCache(m_cache, countB, flags, countA);
    // Fake match: the restricted conversion alias preserves the twin's scheduling hint.
    const S00a35270_hkpConvexShape* __restrict convertA = shapeA;
    gsk.m_dimB = countB;
    gsk.m_doNotHandlePenetration = 0;
    gsk.m_maxDimA = flags & 0xf;
    gsk.m_dimA = countA;
    gsk.m_maxDimB = flags >> 4;
    gsk.m_featureChange = 0;
    convertA->convertVertexIdsToVertices(ids, countA, gsk.m_verticesA);
    shapeB->convertVertexIdsToVertices(ids + gsk.m_dimA, gsk.m_dimB, gsk.m_verticesB);


    S00a35270_hkVector4 separatingNormal;
    gsk.hkpGsk_getClosestFeature(shapeA, shapeB, aTb, separatingNormal);
    if (gsk.m_featureChange)
    {
        gsk.FUN_00a30af0(m_cache);
    }
    gsk.hkpGsk_convertFeatureToClosestDistance(separatingNormal, output);

    {
        const S00a35270_hkTransform& t = *bodyA.m_motion;
        const hkReal v0 = output.m_normalInA.x;
        const hkReal v1 = output.m_normalInA.y;
        const hkReal v2 = output.m_normalInA.z;
        output.m_normalInWorld.x = t.m_col0.x * v0 + t.m_col1.x * v1 + t.m_col2.x * v2;
        output.m_normalInWorld.y = t.m_col0.y * v0 + t.m_col1.y * v1 + t.m_col2.y * v2;
        output.m_normalInWorld.z = t.m_col0.z * v0 + t.m_col1.z * v1 + t.m_col2.z * v2;
        output.m_normalInWorld.w = 0.0f;
    }

    hkReal dist = output.m_distance - shapeA->m_radius - shapeB->m_radius;
    output.m_distance = dist;
    if (dist < input.m_tolerance)
    {
        output.m_pointAinA.subMul4(shapeA->m_radius, output.m_normalInA);
        separatingNormal.setAddMul4(output.m_pointAinA, output.m_normalInA, -dist);
        {
            const hkReal x = separatingNormal.x - aTb.m_translation.x;
            const hkReal y = separatingNormal.y - aTb.m_translation.y;
            const hkReal z = separatingNormal.z - aTb.m_translation.z;
            output.m_pointBinB.x = aTb.m_col0.x * x + aTb.m_col0.y * y + aTb.m_col0.z * z;
            output.m_pointBinB.y = aTb.m_col1.x * x + aTb.m_col1.y * y + aTb.m_col1.z * z;
            output.m_pointBinB.z = aTb.m_col2.x * x + aTb.m_col2.y * y + aTb.m_col2.z * z;
            output.m_pointBinB.w = 0.0f;
        }
        return true;
    }
    return false;
}
}   // namespace f3m_00a35270

// @f3 0x00a26440 (community match, verified in this file)
extern float DAT_00e35180[];
extern const float DAT_00db8b4c;
extern const float DAT_00de6e60;
extern const double DAT_00dcc5a0=0.0078125;
extern const double DAT_00e7d790;
extern const double DAT_00e85720;
namespace f3m_00a26440 {
struct __declspec(align(16)) ContactVector {
 float x,y,z,w;
 __forceinline void setSub(const ContactVector& a,const ContactVector& b) { x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w; }
 __forceinline const float& lane(int i) const {return (&x)[i];}
 __forceinline void setCross(const ContactVector& a,const ContactVector& b) {const float u=a.lane(1)*b.lane(2)-a.lane(2)*b.lane(1); const float v=a.lane(2)*b.lane(0)-a.lane(0)*b.lane(2); const float t=a.lane(0)*b.lane(1)-a.lane(1)*b.lane(0); x=u;y=v;z=t;w=0.0f;}
 __forceinline void add(const ContactVector& a) {x=a.x+x;y=a.y+y;z=a.z+z;w=a.w+w;}
 __forceinline float dot(const ContactVector& a) const {return x*a.x+y*a.y+z*a.z;}
};
struct ContactTransform {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 ContactVector position;
};
struct ContactCallbackWorld;
struct ContactBody {
 int unk00;
 int unk04;
 ContactCallbackWorld* eventWorld;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 int unkc4;
 int unkc8;
 int unkcc;
 int unkd0;
 int unkd4;
 int unkd8;
 int unkdc;
 int unke0;
 int unke4;
 int unke8;
 int unkec;
 int unkf0;
 int unkf4;
 int unkf8;
 int unkfc;
 int unk100;
 int unk104;
 int unk108;
 int unk10c;
 int unk110;
 int unk114;
 int unk118;
 int unk11c;
 int unk120;
 int unk124;
 int unk128;
 int unk12c;
 int unk130;
 int unk134;
 int unk138;
 int unk13c;
 int unk140;
 int unk144;
 int unk148;
 int unk14c;
 int unk150;
 int unk154;
 int unk158;
 int unk15c;
 int unk160;
 int unk164;
 int unk168;
 int unk16c;
 int unk170;
 int unk174;
 int unk178;
 int unk17c;
 int unk180;
 int unk184;
 int unk188;
 int unk18c;
 int unk190;
 int unk194;
 int unk198;
 float inverseMass;
 ContactVector linearVelocity;
 ContactVector angularVelocity;
 int unk1c0;
 int unk1c4;
 int unk1c8;
 int unk1cc;
 int unk1d0;
 int unk1d4;
 int unk1d8;
 int unk1dc;
 int unk1e0;
 int unk1e4;
 int unk1e8;
 int unk1ec;
 int unk1f0;
 unsigned short callbackFlags;
 __forceinline const ContactVector& linear() const {return linearVelocity;}
 __forceinline const ContactVector& angular() const {return angularVelocity;}
};
struct ContactPoint {ContactVector position;ContactVector normal;
 __forceinline const ContactVector& location() const {return position;}
 __forceinline const ContactVector& direction() const {return normal;}
};
struct ContactProperty {
 float impulse; float internal04; int unk08;
 unsigned char friction,restitution,maxImpulse,flags;
 float projectedVelocity;
};
struct ContactEntity {int unk00,unk04,unk08,unk0c;short unk10;unsigned char flags;};
struct ContactSettings { int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 float threshold;
};
struct ContactWorld {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 ContactSettings* settings;
};
struct ContactOwner {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 ContactBody* bodyA;ContactBody* bodyB;int unk1c,unk20,unk24;ContactEntity* entity;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 ContactWorld* world;
};
struct ContactCallbackWorld {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68;
 ContactWorld* input;
};
struct QueryIn6440 {
 float step;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 ContactTransform* transformA;ContactTransform* transformB;int unk38,unk3c,unk40,unk44;ContactOwner* owner;
};
struct Atom6440 {
 int unk00;unsigned short count,capacity;short unk08;unsigned char stride;unsigned char unk0b;int unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
};
struct Data6440;
struct ContactContext {
 void* bodyA; void* bodyB; int unk08;
 ContactPoint* point; ContactProperty* property;
 float zero,relativeVelocity; int type; Data6440* data;
 __forceinline ContactContext(ContactBody* a,ContactBody* b,ContactPoint* p,ContactProperty* q,float speed,Data6440* d) {
 bodyA=&a->unk10;bodyB=&b->unk10;point=p;property=q;zero=0.0f;relativeVelocity=speed;type=1;data=d;
 }
};
struct __declspec(align(16)) ContactParameters {
 ContactVector normal;
 float friction,restitution,maxImpulse,relativeVelocity;
 float unk20,unk24;bool rejected;
};
struct ContactEvent {int type;ContactOwner* owner;ContactProperty* property;ContactPoint* point;};
void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(ContactCallbackWorld*,ContactContext*);
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(ContactBody*,ContactContext*);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(ContactCallbackWorld*,ContactEvent*,int);
void __cdecl hkpSimpleCollisionResponse_solveSingleContact2(Data6440*,ContactPoint*,ContactParameters*,ContactBody*,ContactBody*,ContactTransform*,ContactTransform*,int*);
inline float DecodeRestitution(unsigned char value) {return (float)(value*DAT_00dcc5a0);}
// pdb: hkSimpleContactConstraintData_fireCallbacks | hkpSimpleContactConstraintData.obj | fnv360_0822_retail, call_seq + bridge(uconst|call_seq) + skyrim(uconst), high
void __cdecl hkSimpleContactConstraintData_fireCallbacks(Data6440* data,const QueryIn6440* in,Atom6440* atom)
{
 ContactOwner* owner=in->owner;
 ContactBody* bodyA=owner->bodyA;
 ContactBody* bodyB=owner->bodyB;
 ContactProperty* property=(ContactProperty*)((char*)(atom+1)+atom->capacity*sizeof(ContactPoint));
 int stride=atom->stride;
 ContactPoint* point=(ContactPoint*)(atom+1);
 int left=atom->count-1;
 if(left>=0) do {
  if(property->flags&1) {
   float projectedVelocity;
   ContactVector velocityA, velocityB, relative;
    {ContactVector offsetA;offsetA.setSub(point->location(),in->transformA->position);
    velocityA.setCross(bodyA->angular(),offsetA);velocityA.add(bodyA->linear());}
    {ContactVector offsetB;offsetB.setSub(point->location(),in->transformB->position);
    velocityB.setCross(bodyB->angular(),offsetB);velocityB.add(bodyB->linear());}
   relative.setSub(velocityA,velocityB);
    projectedVelocity=relative.dot(point->direction());
   const ContactVector& normal=point->direction();
    ContactContext context(bodyA,bodyB,point,property,projectedVelocity,data);
    ContactCallbackWorld* eventId=bodyA->eventWorld;
   hkpWorldCallbackUtil_fireContactPointCallback(eventId,&context);
   if(bodyA->callbackFlags)hkpEntityCallbackUtil_fireContactPointCallbackInternal(bodyA,&context);
   if(bodyB->callbackFlags)hkpEntityCallbackUtil_fireContactPointCallbackInternal(bodyB,&context);
   float restitution=DecodeRestitution(property->restitution);
   float relativeVelocity=context.relativeVelocity;
    if(relativeVelocity < -eventId->input->settings->threshold && DAT_00db8b4c<restitution) {
    ContactParameters parameters;
    parameters.normal.x=normal.x;parameters.normal.y=normal.y;parameters.normal.z=normal.z;parameters.normal.w=normal.w;
    parameters.friction=DAT_00e35180[property->friction];
    parameters.restitution=restitution;
    parameters.unk20=0.0f;parameters.unk24=0.0f;
    parameters.relativeVelocity=relativeVelocity;
     parameters.maxImpulse=DAT_00de6e60;
    if(property->maxImpulse)parameters.maxImpulse=DAT_00e35180[property->maxImpulse];
    int bound;
    hkpSimpleCollisionResponse_solveSingleContact2(data,point,&parameters,bodyA,bodyB,in->transformA,in->transformB,&bound);
    if(parameters.rejected) {
     ContactEvent event;
     event.owner=in->owner;event.type=1;event.point=point;event.property=property;
     hkpWorldCallbackUtil_fireContactImpulseLimitBreached(eventId,&event,1);
    }
    property->impulse=0.0f;property->projectedVelocity=normal.w;
   } else {
    float mass=bodyA->inverseMass+bodyB->inverseMass;
    float inverse=(float)(1.0/(mass+1.000000013351432e-10));
     property->impulse=(float)((inverse*DAT_00e7d790*relativeVelocity)*(1.0f+DecodeRestitution(property->restitution)));
    float projected=(float)(relativeVelocity*DecodeRestitution(property->restitution)*in->step);
     projected=(float)(projected*DAT_00e85720);
    property->internal04=projected;property->projectedVelocity=projected+normal.w;
   }
   property->flags&=~1;
  }
  ++point;property=(ContactProperty*)((char*)property+stride);
 }while(--left>=0);
 owner->entity->flags&=~1;
}
}   // namespace f3m_00a26440

// @f3 0x00a2f9e0 (community match, verified in this file)
#include <math.h>

namespace f3m_00a35270 {

class S00a2f9e0_hkSimdReal
{
public:
    __forceinline S00a2f9e0_hkSimdReal(hkReal r) : m_real(r) {}
    __forceinline operator hkReal() const { return m_real; }
private:
    hkReal m_real;
};

class S00a2f9e0_hkVector4
{
public:
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline void operator=(const S00a2f9e0_hkVector4& v);
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d);
    __forceinline void setAdd4(const S00a2f9e0_hkVector4& a, const S00a2f9e0_hkVector4& b);
    __forceinline void setSub4(const S00a2f9e0_hkVector4& a, const S00a2f9e0_hkVector4& b);
    __forceinline void mul4(const S00a2f9e0_hkVector4& a);
    __forceinline void mul4(hkReal s);
    __forceinline void normalize3IfNotZero();
    __forceinline hkReal length3() const;
    __forceinline void setW(hkReal v);
    __forceinline void subMul4(hkReal r, const S00a2f9e0_hkVector4& a);
    __forceinline void setCross(const S00a2f9e0_hkVector4& a, const S00a2f9e0_hkVector4& b);
    __forceinline void setNeg4(const S00a2f9e0_hkVector4& v);
    __forceinline S00a2f9e0_hkSimdReal dot3(const S00a2f9e0_hkVector4& a) const;
    __forceinline S00a2f9e0_hkSimdReal lengthSquared3() const;
    __forceinline hkReal horizontalAdd3() const;

private:
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

__forceinline hkReal& S00a2f9e0_hkVector4::operator()(int i)
{
    return (&x)[i];
}

__forceinline const hkReal& S00a2f9e0_hkVector4::operator()(int i) const
{
    return (&x)[i];
}

__forceinline void S00a2f9e0_hkVector4::operator=(const S00a2f9e0_hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void S00a2f9e0_hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

__forceinline void S00a2f9e0_hkVector4::setAdd4(const S00a2f9e0_hkVector4& a, const S00a2f9e0_hkVector4& b)
{
    x = a.x + b.x;
    y = a.y + b.y;
    z = a.z + b.z;
    w = a.w + b.w;
}

__forceinline void S00a2f9e0_hkVector4::setSub4(const S00a2f9e0_hkVector4& a, const S00a2f9e0_hkVector4& b)
{
    x = a.x - b.x;
    y = a.y - b.y;
    z = a.z - b.z;
    w = a.w - b.w;
}

__forceinline void S00a2f9e0_hkVector4::mul4(const S00a2f9e0_hkVector4& a)
{
    x *= a.x;
    y *= a.y;
    z *= a.z;
    w *= a.w;
}

__forceinline void S00a2f9e0_hkVector4::setW(hkReal v)
{
    w = v;
}

__forceinline void S00a2f9e0_hkVector4::mul4(hkReal s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

__forceinline void S00a2f9e0_hkVector4::subMul4(hkReal r, const S00a2f9e0_hkVector4& a)
{
    x -= r * a.x;
    y -= r * a.y;
    z -= r * a.z;
    w -= r * a.w;
}

__forceinline void S00a2f9e0_hkVector4::setCross(const S00a2f9e0_hkVector4& v1, const S00a2f9e0_hkVector4& v2)
{
    const hkReal nx = v1(1) * v2(2) - v1(2) * v2(1);
    const hkReal ny = v1(2) * v2(0) - v1(0) * v2(2);
    const hkReal nz = v1(0) * v2(1) - v1(1) * v2(0);
    this->set(nx, ny, nz, 0.0f);
}

__forceinline void S00a2f9e0_hkVector4::setNeg4(const S00a2f9e0_hkVector4& v)
{
    x = -v.x;
    y = -v.y;
    z = -v.z;
    w = -v.w;
}

__forceinline S00a2f9e0_hkSimdReal S00a2f9e0_hkVector4::dot3(const S00a2f9e0_hkVector4& a) const
{
    const S00a2f9e0_hkVector4* p = &a;
    return (x * p->x) + (y * p->y) + (z * p->z);
}

__forceinline S00a2f9e0_hkSimdReal S00a2f9e0_hkVector4::lengthSquared3() const
{
    return (x * x) + (y * y) + (z * z);
}

__forceinline hkReal S00a2f9e0_hkVector4::horizontalAdd3() const
{
    return x + y + z;
}

__forceinline void S00a2f9e0_hkVector4::normalize3IfNotZero()
{
    hkReal l2 = lengthSquared3();
    hkReal inv;
    if (l2 != 0.0f)
    {
        inv = 1.0f / (hkReal)sqrt(l2);
    }
    else
    {
        inv = 0.0f;
    }
    mul4(inv);
}

__forceinline hkReal S00a2f9e0_hkVector4::length3() const
{
    return (hkReal)sqrt(lengthSquared3());
}

struct S00a2f9e0_ClosestLineSegLineSegResult
{
    S00a2f9e0_hkVector4 m_closestPointA;
    S00a2f9e0_hkVector4 m_closestAminusClosestB;
    hkReal m_distanceSquared;
    hkReal m_t;
    hkReal m_u;
};

int FUN_0096f780(const S00a2f9e0_hkVector4& A, const S00a2f9e0_hkVector4& dA, const S00a2f9e0_hkVector4& B, const S00a2f9e0_hkVector4& dB, S00a2f9e0_ClosestLineSegLineSegResult& result);

// pdb: hkGskRecalcContactInternal | hkpGsk.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: verticesA, verticesB, dimA, dimB, masterNormal, pointA, support
void __cdecl FUN_00a2f9e0(const S00a2f9e0_hkVector4* verticesA, const S00a2f9e0_hkVector4* verticesB, int dimA, int dimB,
                          const S00a2f9e0_hkVector4& lastNormal, S00a2f9e0_hkVector4& pointOut, S00a2f9e0_hkVector4& normalOut)
{
    int sw = (dimA << 3) | dimB;
    const S00a2f9e0_hkVector4* tri;
    const S00a2f9e0_hkVector4* pt;
    switch (sw)
    {
    case 0x09:
    {
        normalOut.setSub4(verticesA[0], verticesB[0]);
        hkReal dot = normalOut.dot3(lastNormal);
        hkReal lenSq = normalOut.lengthSquared3();
        hkReal w;
        if (dot * 1000.0f < lenSq)
        {
            w = lastNormal.dot3(normalOut);
            normalOut = lastNormal;
        }
        else
        {
            hkReal len = normalOut.length3();
            hkReal inv = 1.0f / len;
            normalOut.mul4(inv);
            w = len;
        }
        normalOut(3) = w;
        pointOut = verticesA[0];
        break;
    }
    case 0x0a:
    {
        S00a2f9e0_hkVector4 diff;
        diff.setSub4(verticesA[0], verticesB[0]);
        normalOut = lastNormal;
        normalOut(3) = diff.dot3(normalOut);
        pointOut = verticesA[0];
        break;
    }
    case 0x11:
    {
        S00a2f9e0_hkVector4 diff;
        diff.setSub4(verticesB[0], verticesA[0]);
        normalOut = lastNormal;
        hkReal d = diff.dot3(normalOut);
        pointOut = verticesB[0];
        pointOut.subMul4(d, normalOut);
        normalOut(3) = -d;
        break;
    }
    case 0x19:
        tri = verticesA;
        pt = verticesB;
        goto triangle;
    case 0x0b:
        tri = verticesB;
        pt = verticesA;
    triangle:
    {
        S00a2f9e0_hkVector4 e1;
        e1.setSub4(tri[2], tri[1]);
        S00a2f9e0_hkVector4 e0;
        e0.setSub4(tri[0], tri[2]);
        normalOut.setCross(e1, e0);
        hkReal lenSq = normalOut.lengthSquared3();
        hkReal inv;
        if (lenSq != 0.0f)
        {
            inv = 1.0f / (hkReal)sqrt(lenSq);
        }
        else
        {
            inv = 0.0f;
        }
        if (normalOut.dot3(lastNormal) < 0.0f)
        {
            normalOut.setNeg4(normalOut);
        }
        normalOut.mul4(inv);
        S00a2f9e0_hkVector4 diff;
        diff.setSub4(pt[0], tri[0]);
        hkReal d = diff.dot3(normalOut);
        pointOut = pt[0];
        if (sw == 0x0b)
        {
            normalOut(3) = d;
        }
        else
        {
            pointOut.subMul4(d, normalOut);
            normalOut(3) = -d;
        }
        break;
    }
    case 0x12:
    {
        S00a2f9e0_hkVector4 dA;
        dA.setSub4(verticesA[1], verticesA[0]);
        S00a2f9e0_hkVector4 dB;
        dB.setSub4(verticesB[1], verticesB[0]);
        S00a2f9e0_ClosestLineSegLineSegResult result;
        FUN_0096f780(verticesA[0], dA, verticesB[0], dB, result);
        const hkReal nx = dA(1) * dB(2) - dA(2) * dB(1);
        normalOut(0) = nx;
        const hkReal ny = dA(2) * dB(0) - dA(0) * dB(2);
        normalOut(1) = ny;
        const hkReal nz = dA(0) * dB(1) - dA(1) * dB(0);
        normalOut(2) = nz;
        normalOut.setW(0.0f);
        dA.mul4(dA);
        dB.mul4(dB);
        S00a2f9e0_hkVector4 s;
        s.setAdd4(dB, dA);
        hkReal sum = s.horizontalAdd3();
        hkReal lenSq = nx * nx + ny * ny + nz * nz;
        if (lenSq * 0.001f > sum * sum)
        {
            if (normalOut.dot3(lastNormal) < 0.0f)
            {
                normalOut.setNeg4(normalOut);
            }
            normalOut.normalize3IfNotZero();
        }
        else
        {
            normalOut = lastNormal;
        }
        S00a2f9e0_hkVector4 diff;
        diff.setSub4(verticesA[0], verticesB[0]);
        hkReal d = diff.dot3(normalOut);
        pointOut = result.m_closestPointA;
        normalOut(3) = d;
        break;
    }
    }
}

}

// @f3 0x00a26f20 (community match, verified in this file)
#include <math.h>
namespace f3m_00a26f20 {
// Flags: /MT /O2 /GS /EHsc /Gy (the listed /Od is wrong: and esp,-16 frame).

typedef float hkReal;
typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;

namespace hkMath
{
    __forceinline hkReal sqrtInverse(hkReal r) { return 1.0f/(hkReal)sqrt(r); }
    __forceinline hkReal fabs(hkReal r) { return (hkReal)::fabs(r); }
}

class hkMatrix3;

class hkVector4
{
public:
    __forceinline hkReal& operator() (int i);
    __forceinline const hkReal& operator() (int i) const;
    __forceinline hkVector4() {}
    __forceinline hkVector4(const hkVector4& v);
    __forceinline void operator= (const hkVector4& v);
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0);
    __forceinline void setZero4();
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b);
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void mul4(hkSimdRealParameter r);
    __forceinline void setCross(const hkVector4& a, const hkVector4& b);
    __forceinline hkSimdReal lengthInverse3() const;
    __forceinline void normalize3();
    __forceinline void _setRotatedDir(const hkMatrix3& r, const hkVector4& v);
    __forceinline void _setRotatedInverseDir(const hkMatrix3& r, const hkVector4& v);
private:
    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

class hkMatrix3
{
public:
    __forceinline hkReal& operator() (int row, int col);
    __forceinline const hkReal& operator() (int row, int col) const;
    __forceinline hkVector4& getColumn(int i);
    __forceinline const hkVector4& getColumn(int i) const;
    __forceinline void setZero();
    __forceinline void setDiagonalMul(const hkMatrix3& m, const hkVector4& d);
    void FUN_0096cf70(const hkMatrix3& a, const hkMatrix3& b);
    void FUN_0096c410();
private:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

__forceinline hkReal& hkVector4::operator() (int i) { return (&x)[i]; }
__forceinline const hkReal& hkVector4::operator() (int i) const { return (&x)[i]; }
__forceinline hkVector4::hkVector4(const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
__forceinline void hkVector4::operator= (const hkVector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d) { x = a; y = b; z = c; w = d; }
__forceinline void hkVector4::setZero4() { x = y = z = w = 0; }
__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w;
}
__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& a)
{
    for (int i = 0; i < 4; i++) (*this)(i) = a(i) * r;
}
__forceinline void hkVector4::mul4(hkSimdRealParameter r)
{
    for (int i = 0; i < 4; i++) (*this)(i) *= r;
}
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const hkReal nx = v2(2)*v1(1) - v2(1)*v1(2);
    const hkReal ny = v2(0)*v1(2) - v2(2)*v1(0);
    const hkReal nz = v2(1)*v1(0) - v2(0)*v1(1);
    this->set(nx, ny, nz, 0.0f);
}
__forceinline hkSimdReal hkVector4::lengthInverse3() const
{
    hkReal l2 = x*x + y*y + z*z;
    return l2 ? hkMath::sqrtInverse(l2) : 0;
}
__forceinline void hkVector4::normalize3()
{
    this->mul4(this->lengthInverse3());
}
__forceinline void hkVector4::_setRotatedDir(const hkMatrix3& r, const hkVector4& v)
{
    x = r(0,0)*v(0) + r(0,1)*v(1) + r(0,2)*v(2);
    y = r(1,0)*v(0) + r(1,1)*v(1) + r(1,2)*v(2);
    z = r(2,0)*v(0) + r(2,1)*v(1) + r(2,2)*v(2);
    w = 0;
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkMatrix3& r, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    x = r(0,0)*v0 + r(1,0)*v1 + r(2,0)*v2;
    y = r(0,1)*v0 + r(1,1)*v1 + r(2,1)*v2;
    z = r(0,2)*v0 + r(1,2)*v1 + r(2,2)*v2;
    w = 0;
}

__forceinline hkReal& hkMatrix3::operator() (int row, int col) { return getColumn(col)(row); }
__forceinline const hkReal& hkMatrix3::operator() (int row, int col) const { return getColumn(col)(row); }
__forceinline hkVector4& hkMatrix3::getColumn(int i) { return (&m_col0)[i]; }
__forceinline const hkVector4& hkMatrix3::getColumn(int i) const { return (&m_col0)[i]; }
__forceinline void hkMatrix3::setZero()
{
    hkVector4 zero; zero.setZero4();
    m_col0 = zero;
    m_col1 = zero;
    m_col2 = zero;
}

__forceinline void hkMatrix3::setDiagonalMul(const hkMatrix3& m, const hkVector4& d)
{
    hkReal d0 = d(0), d1 = d(1), d2 = d(2);
    m_col0.setMul4(d0, m.m_col0);
    m_col1.setMul4(d1, m.m_col1);
    m_col2.setMul4(d2, m.m_col2);
}

typedef hkVector4 Vector;
typedef hkMatrix3 Matrix;

struct Contact { Vector unk00,unk10; };
struct Input { Vector unk00; Matrix unk10; float unk40; };
struct Pair { Vector unk00,unk10; };
struct CacheBody { Matrix unk00,unk30; float unk60,unk64; };
struct Cache { CacheBody bodies[2]; Matrix unkE0,unk110,unk140; };
struct Accumulator
{
    unsigned char unk00,unk01; unsigned short unk02;
    unsigned int unk04,unk08,unk0c;
    Vector unk10,unk20,unk30,unk40;
    Matrix unk50;
};
struct Owner
{
    unsigned int unk000,unk004,unk008,unk00c,unk010,unk014,unk018,unk01c;
    unsigned int unk020,unk024,unk028,unk02c,unk030,unk034,unk038,unk03c;
    unsigned int unk040,unk044,unk048,unk04c,unk050,unk054,unk058,unk05c;
    unsigned int unk060,unk064,unk068,unk06c,unk070,unk074,unk078,unk07c;
    unsigned int unk080,unk084,unk088,unk08c,unk090,unk094,unk098,unk09c;
    unsigned int unk0a0,unk0a4,unk0a8,unk0ac,unk0b0,unk0b4,unk0b8,unk0bc;
    unsigned int unk0c0,unk0c4,unk0c8,unk0cc,unk0d0,unk0d4;
    unsigned char unk0d8,unk0d9,unk0da,unk0db;
    unsigned int unk0dc,unk0e0,unk0e4,unk0e8,unk0ec,unk0f0,unk0f4,unk0f8,unk0fc;
    unsigned int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    unsigned int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    unsigned int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    unsigned int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    unsigned int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    Vector unk1a0,unk1b0;
};
struct Solver
{
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(const Contact&,Input&,Pair&,Input&,Pair&);
    virtual void v34(const Contact&,float,Input&,Pair&,Input&,Pair&);
};
extern "C" void __cdecl FUN_00a7ce70(const Input&,const Input&,const Matrix&,Cache&);
extern "C" float __cdecl FUN_00a7da50(const Cache&,void*,Pair&,Pair&);
__forceinline void perpendicular(const Vector& v,Vector& r)
{
    int least=0,first=1,second=2;
    hkReal a=hkMath::fabs(v(0)),b=hkMath::fabs(v(1)),c=hkMath::fabs(v(2));
    if (b<a) { first=0; least=1; a=b; }
    if (c<a) { second=least; least=2; }
    r.setZero4(); r(first)=v(second); r(second)=-v(first);
}
__forceinline void basis(const Vector& normal,Matrix& out)
{
    out.getColumn(0)=normal;
    perpendicular(normal,out.getColumn(1));
    out.getColumn(1).normalize3();
    out.getColumn(2).setCross(normal,out.getColumn(1));
}
// pdb: hkpSimpleCollisionResponse::solveSingleContact2 | hkpSimpleCollisionResponse.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void __cdecl hkpSimpleCollisionResponse_solveSingleContact2(Solver* solver,const Contact& contact,void* params,
                         Owner* ownerA,Owner* ownerB,Accumulator* accA,Accumulator* accB,float& result)
{
    Cache cache;
    Pair velocities[2];
    Input inputs[2];
    Matrix axes;
    {
        Accumulator* acc=accA;
        for (int i=0;i<2;++i)
        {
            Input& input=inputs[i];
            Pair& velocity=velocities[i];
            input.unk40=acc->unk30(3);
            input.unk00.setSub4(contact.unk00,acc->unk40);
            velocity.unk00=acc->unk10;
            if (acc->unk01)
            {
                velocity.unk10=acc->unk20;
                input.unk10.setZero();
                input.unk10(0,0)=acc->unk30(0);
                input.unk10(1,1)=acc->unk30(1);
                input.unk10(2,2)=acc->unk30(2);
            }
            else
            {
                velocity.unk10._setRotatedInverseDir(acc->unk50,acc->unk20);
                
                Matrix scaled;
                scaled.setDiagonalMul(acc->unk50,acc->unk30);
                input.unk10.FUN_0096cf70(scaled,acc->unk50);
                input.unk10.FUN_0096c410();
            }
            acc=accB;
        }
    }
    basis(contact.unk10,axes);
    solver->v30(contact,inputs[0],velocities[0],inputs[1],velocities[1]);
    FUN_00a7ce70(inputs[0],inputs[1],axes,cache);
    result=FUN_00a7da50(cache,params,velocities[0],velocities[1]);
    solver->v34(contact,result,inputs[0],velocities[0],inputs[1],velocities[1]);
    accA->unk10=velocities[0].unk00;
    if (ownerA->unk0d8!=7)
    {
        ownerA->unk1a0=velocities[0].unk00;
        ownerA->unk1b0=velocities[0].unk10;
    }
    accB->unk10=velocities[1].unk00;
    if (ownerB->unk0d8!=7)
    {
        ownerB->unk1a0=velocities[1].unk00;
        ownerB->unk1b0=velocities[1].unk10;
    }
    if (accA->unk01) accA->unk20=velocities[0].unk10;
    else accA->unk20._setRotatedDir(accA->unk50,velocities[0].unk10);
    if (accB->unk01) accB->unk20=velocities[1].unk10;
    else accB->unk20._setRotatedDir(accB->unk50,velocities[1].unk10);
}
}   // namespace f3m_00a26f20

// @f3 0x00a3d7c0 (community match, verified in this file)
namespace f3m_00a3d7c0 {
// hkpBoxBoxCollisionDetection_findClosestPoint = Havok 5.5.0 hkpBoxBoxCollisionDetection::findClosestPoint (hkpInternal.lib,
// hkpBoxBoxCollisionDetection.obj; the stock release object is byte-exact against the game).
// Reconstructed (the .cpp is not shipped) from the hybrid library object's line records 1219-1315 and locals, the
// release object's out-of-line helper copies (their own .cpp lines 139-169, 232-255, 698-710, 1134-1215), the pdb
// class layouts, and the SDK's verbatim inline bodies; cut with hktrim.py.
namespace f3m_00a3d7c0 {
// reduced by hktrim.py from sdk.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
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

typedef hkReal hkSimdReal;
typedef hkReal hkSimdRealParameter;
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
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};




namespace hkMath
{
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkRotation;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll(hkReal x);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
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
		__forceinline void getRow( int row, hkVector4& r) const;
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
		__forceinline const hkRotation& getRotation() const;
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

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline hkBool32 hkVector4::allLessThan3(hkVector4Parameter a) const
{
	return x<a.x && y<a.y && z<a.z;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline const hkVector4& hkMatrix3::getColumn(int x) const
{
	return (&m_col0)[x];
}

inline const hkReal& hkMatrix3::operator() (int r, int c) const
{
	return getColumn(c)(r);
}

inline void hkMatrix3::getRow( int row, hkVector4& r) const
{
	r.set( getColumn(0)(row), getColumn(1)(row), getColumn(2)(row) );
}

const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}

inline const hkReal& hkTransform::operator() (int r, int c) const
{
	return m_rotation(r,c);
}

typedef hkUint16 hkContactPointId;

class hkpFeatureContactPoint
{
	public:
		                class MustEndWithSemiColon;
	hkUint8 m_featureIdA;
	hkUint8 m_featureIdB;
	hkContactPointId	m_contactPointId;
};

class hkpCdBody;
struct hkpProcessCollisionOutput;

class hkpBoxBoxManifold
{
	public:
		                class MustEndWithSemiColon;
		inline hkBool findInManifold( const hkpFeatureContactPoint& fcp );
	public:
		hkpFeatureContactPoint m_contactPoints[8];
		hkUchar  m_faceVertexFeatureCount;
		hkUchar  m_numPoints;
		hkBool m_isComplete;
		hkBool m_manifoldNormalInitialized;
		hkUint32 m_manifoldNormalB;
		hkVector4 m_manifoldNormalA;
};

inline hkBool hkpBoxBoxManifold::findInManifold( const hkpFeatureContactPoint& fcp )
{
	for (int i = m_numPoints-1; i>=0; i--)
	{
		if ( m_contactPoints[i].m_featureIdA == fcp.m_featureIdA && m_contactPoints[i].m_featureIdB == fcp.m_featureIdB )
		{
			return true;
		}
	}
	return false;
}

namespace hkVector4Util
{
	__forceinline void __cdecl mulSigns4( hkVector4& inout, const hkVector4& signsSource);
}

inline void __cdecl hkVector4Util::mulSigns4( hkVector4& inout, const hkVector4& signv)
{
	hkUint32* intp = reinterpret_cast<hkUint32*>(&inout);
	const hkUint32* sign = reinterpret_cast<const hkUint32*>(&signv);
	intp[0] ^= (sign[0] & 0x80000000);
	intp[1] ^= (sign[1] & 0x80000000);
	intp[2] ^= (sign[2] & 0x80000000);
	intp[3] ^= (sign[3] & 0x80000000);
}

struct hkpProcessCollisionInput;
class hkpContactMgr;

class hkpBoxBoxCollisionDetection
{
	public:
		                class MustEndWithSemiColon;
		enum hkpBoxBoxFeature
		{
			HK_BOXBOX_FACE_A_X = 0, HK_BOXBOX_FACE_A_Y = 1, HK_BOXBOX_FACE_A_Z = 2,
			HK_BOXBOX_FACE_B_X = 4, HK_BOXBOX_FACE_B_Y = 5, HK_BOXBOX_FACE_B_Z = 6,
			HK_BOXBOX_EDGE_0_0 = 8, HK_BOXBOX_EDGE_0_1 = 9, HK_BOXBOX_EDGE_0_2 = 10,
			HK_BOXBOX_EDGE_1_0 = 12, HK_BOXBOX_EDGE_1_1 = 13, HK_BOXBOX_EDGE_1_2 = 14,
			HK_BOXBOX_EDGE_2_0 = 16, HK_BOXBOX_EDGE_2_1 = 17, HK_BOXBOX_EDGE_2_2 = 18,
			HK_BOXBOX_FEATURE_COUNT = 19
		};
		enum
		{
			HK_FINDCLOSESTPOINT_NO_VALID_POINT = 0,
			HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD = 1,
			HK_FINDCLOSESTPOINT_VALID_POINT = 2
		};
		class hkpFeaturePointCache
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_vA;
				hkVector4 m_vB;
				hkVector4 m_nA;
				hkReal m_normalSign;
				hkReal m_distance;
				int m_featureIndexA;
				int m_featureIndexB;
		};
	protected:
		int hkpBoxBoxCollisionDetection_findClosestPoint( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkpFeaturePointCache& fpp ) const;
		__forceinline void faceAVertexBValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const;
		__forceinline void faceBVertexAValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const;
		__forceinline void edgeEdgeValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp ) const;
		__forceinline hkBool isValidFaceAVertexB( hkpFeaturePointCache& fpp ) const;
		__forceinline hkBool isValidFaceBVertexA( hkpFeaturePointCache& fpp ) const;
		hkBool isValidEdgeEdge( hkpFeaturePointCache& fpp ) const;
	public:
		const hkpCdBody& m_bodyA;
		const hkpCdBody& m_bodyB;
		const hkpProcessCollisionInput* m_env;
		hkpContactMgr* m_contactMgr;
		hkpProcessCollisionOutput* m_result;
		const hkTransform& m_wTa;
		const hkTransform& m_wTb;
		hkTransform m_aTb;
		hkVector4 m_radiusA;
		hkVector4 m_radiusB;
		hkVector4 m_tolerance4;
		hkVector4 m_keepRadiusA;
		hkVector4 m_keepRadiusB;
		const hkReal m_tolerance;
		const hkReal m_boundaryTolerance;
		hkVector4 m_dinA;
		hkVector4 m_dinB;
		mutable hkVector4 m_sepDist[5];
		static const int m_maxFeaturesToReject;
};

const int hkpBoxBoxCollisionDetection::m_maxFeaturesToReject = 8;

class hkBoxBoxUtils
{
	public:
		static __forceinline void __cdecl selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than );
};

void __cdecl hkBoxBoxUtils::selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than )
{
	result(0) = ( greater(0) > than ) ? selectIf : result(0);
	result(1) = ( greater(1) > than ) ? selectIf : result(1);
	result(2) = ( greater(2) > than ) ? selectIf : result(2);
}

static __forceinline hkUint16 calcFaceFeatureBitSetFromAxisMap( const hkVector4& axisMap, hkReal normalSign )
{
	int featureBitSet = axisMap.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ ) << 4;
	featureBitSet |= ( reinterpret_cast<hkUint32&>( normalSign ) & 0x80000000 ) >> 28;
	return hkUint16( featureBitSet );
}

static __forceinline void setEdgeFeatureBitSetFromAxisMap( const hkVector4& axisMapAp, const hkVector4& axisMapBp, int featureIndexA, int featureIndexB, hkpFeatureContactPoint& fcp )
{
	hkVector4 axisMapA = axisMapAp;
	hkVector4 axisMapB = axisMapBp;
	axisMapA( featureIndexA ) = 1.0f;
	axisMapB( featureIndexB ) = 1.0f;
	const int maskA = axisMapA.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ );
	const int maskB = axisMapB.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
	fcp.m_featureIdA = hkUint8( featureIndexA | 0x10 | ( maskA << 4 ) );
	fcp.m_featureIdB = hkUint8( ( maskB << 4 ) + featureIndexB );
}

hkBool hkpBoxBoxCollisionDetection::isValidFaceAVertexB( hkpFeaturePointCache& fpp ) const
{
	hkVector4 vertexB_inA = fpp.m_vA;
	vertexB_inA.setAbs4( vertexB_inA );
	if ( vertexB_inA.allLessThan3( m_keepRadiusA ) )
	{
		const int featureIndex = fpp.m_featureIndexA;
		fpp.m_distance = fpp.m_normalSign * fpp.m_vA( featureIndex ) - m_radiusA( featureIndex );
		return true;
	}
	return false;
}

hkBool hkpBoxBoxCollisionDetection::isValidFaceBVertexA( hkpFeaturePointCache& fpp ) const
{
	hkVector4 vertexA_inB = fpp.m_vB;
	vertexA_inB.setAbs4( vertexA_inB );
	if ( vertexA_inB.allLessThan3( m_keepRadiusB ) )
	{
		const int featureIndex = fpp.m_featureIndexA - 4;
		fpp.m_distance = -fpp.m_normalSign * fpp.m_vB( featureIndex ) - m_radiusB( featureIndex );
		return true;
	}
	return false;
}

void hkpBoxBoxCollisionDetection::faceAVertexBValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const
{
	fpp.m_featureIndexA = featureIndex;
	hkVector4 dimA; m_aTb.getRotation().getRow( featureIndex, dimA );
	if ( m_dinA( featureIndex ) < 0 )
	{
		fpp.m_normalSign = -1.0f;
		fpp.m_vB = m_radiusB;
	}
	else
	{
		fpp.m_normalSign = 1.0f;
		fpp.m_vB.setNeg4( m_radiusB );
	}
	hkVector4 tweak; tweak.setAll( -1e-5f );
	hkBoxBoxUtils::selectIfGT3( tweak, 1e-5f, m_dinB, 0.0f );
	tweak.mul4( fpp.m_normalSign );
	dimA.add4( tweak );
	hkVector4Util::mulSigns4( fpp.m_vB, dimA );
	fpp.m_vA._setTransformedPos( m_aTb, fpp.m_vB );
}

void hkpBoxBoxCollisionDetection::faceBVertexAValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const
{
	fpp.m_featureIndexA = featureIndex + 4;
	hkVector4 dimB = m_aTb.getRotation().getColumn( featureIndex );
	if ( m_dinB( featureIndex ) < 0 )
	{
		fpp.m_normalSign = -1.0f;
		fpp.m_vA.setNeg4( m_radiusA );
	}
	else
	{
		fpp.m_normalSign = 1.0f;
		fpp.m_vA = m_radiusA;
	}
	hkVector4 tweak; tweak.setAll( 1e-5f );
	hkBoxBoxUtils::selectIfGT3( tweak, -1e-5f, m_dinA, 0.0f );
	tweak.mul4( -fpp.m_normalSign );
	dimB.add4( tweak );
	hkVector4Util::mulSigns4( fpp.m_vA, dimB );
	fpp.m_vB._setTransformedInversePos( m_aTb, fpp.m_vA );
}

void hkpBoxBoxCollisionDetection::edgeEdgeValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp ) const
{
	hkVector4 edge_A_in_A; edge_A_in_A.setZero4();
	edge_A_in_A( fpp.m_featureIndexA ) = 1.0f;
	hkVector4 edge_B_in_A = m_aTb.getRotation().getColumn( fpp.m_featureIndexB );
	hkVector4 normal_in_A; normal_in_A.setCross( edge_A_in_A, edge_B_in_A );
	if ( normal_in_A.dot3( m_dinA ) < 0 )
	{
		normal_in_A.setNeg4( normal_in_A );
	}
	hkVector4 normal_in_B; normal_in_B._setRotatedInverseDir( m_aTb.getRotation(), normal_in_A );
	fpp.m_vA = normal_in_A;
	fpp.m_vB = normal_in_B;
}

// pdb: hkpBoxBoxCollisionDetection::findClosestPoint | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun + bridge(call_dedup|call_gap_sim) + skyrim(call_gap), high
int hkpBoxBoxCollisionDetection::hkpBoxBoxCollisionDetection_findClosestPoint( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkpFeaturePointCache& fpp ) const
{
	for ( int featuresToConsider = m_maxFeaturesToReject; featuresToConsider > 0; featuresToConsider-- )
	{
		unsigned int sepFeature = 0;
		{
			hkReal bestDist = m_sepDist[0](0);
			for ( int i = 0; i < 5; i++ )
			{
				if ( m_sepDist[i](0) > bestDist ) { sepFeature = (i<<2);     bestDist = m_sepDist[i](0); }
				if ( m_sepDist[i](1) > bestDist ) { sepFeature = (i<<2) + 1; bestDist = m_sepDist[i](1); }
				if ( m_sepDist[i](2) > bestDist ) { sepFeature = (i<<2) + 2; bestDist = m_sepDist[i](2); }
			}
		}
		if ( sepFeature <= HK_BOXBOX_FACE_A_Z )
		{
			const int featureIndex = sepFeature;
			fcp.m_featureIdA = hkUint8( sepFeature );
			faceAVertexBValidationDataFromFeatureIndex( fpp, featureIndex );
			fcp.m_featureIdB = hkUint8( calcFaceFeatureBitSetFromAxisMap( fpp.m_vB, fpp.m_normalSign ) );
			if ( manifold.findInManifold( fcp ) )
			{
				return HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD;
			}
			if ( isValidFaceAVertexB( fpp ) )
			{
				return HK_FINDCLOSESTPOINT_VALID_POINT;
			}
		}
		else if ( sepFeature <= HK_BOXBOX_FACE_B_Z )
		{
			const int featureIndex = sepFeature - 4;
			fcp.m_featureIdA = hkUint8( sepFeature );
			faceBVertexAValidationDataFromFeatureIndex( fpp, featureIndex );
			fcp.m_featureIdB = hkUint8( calcFaceFeatureBitSetFromAxisMap( fpp.m_vA, fpp.m_normalSign ) );
			if ( manifold.findInManifold( fcp ) )
			{
				return HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD;
			}
			if ( isValidFaceBVertexA( fpp ) )
			{
				return HK_FINDCLOSESTPOINT_VALID_POINT;
			}
		}
		else
		{
			const unsigned int fI = sepFeature - 8;
			fpp.m_featureIndexA = fI >> 2;
			fpp.m_featureIndexB = fI & 3;
			edgeEdgeValidationDataFromFeatureIndex( fpp );
			setEdgeFeatureBitSetFromAxisMap( fpp.m_vA, fpp.m_vB, fpp.m_featureIndexA, fpp.m_featureIndexB, fcp );
			fpp.m_featureIndexA = fcp.m_featureIdA;
			fpp.m_featureIndexB = fcp.m_featureIdB;
			if ( manifold.findInManifold( fcp ) )
			{
				return HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD;
			}
			hkBool result = isValidEdgeEdge( fpp );
			if ( result )
			{
				return HK_FINDCLOSESTPOINT_VALID_POINT;
			}
		}
		m_sepDist[sepFeature >> 2]( sepFeature & 3 ) = -3.40282e+38f;
	}
	return HK_FINDCLOSESTPOINT_NO_VALID_POINT;
}

} // namespace f3m_00a3d7c0
}   // namespace f3m_00a3d7c0

// @f3 0x00a30fb0 (community match, verified in this file)
namespace f3m_00a30fb0 {
// FUN_00a30fb0 = Havok 5.5.0 hkpGsk::linearCast (hkpInternal.lib, hkpGsk.obj; the stock release object is byte-exact
// against the game). The .cpp and hkpGsk.h are not shipped: the class is reconstructed from the pdb, and linearCast,
// the inline member reduceDimension, the static helpers findClosestTriangle / findClosestTriangleBackup and the
// force-inline process_point_edge are reconstructed from the hybrid and debug_multithreaded objects' line records and
// locals, on the SDK's verbatim inline bodies; cut with hktrim.py.
namespace f3m_00a30fb0 {
// reduced by hktrim.py from sdk.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
typedef signed char		hkInt8;
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
	private:
		int m_mask;
		friend class hkVector4;
};


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
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
		__forceinline void setZero4();
		__forceinline void sub3clobberW(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setAbs4(const hkVector4& v);
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline void fastNormalize3NonZero();
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

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
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

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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

inline void hkVector4::fastNormalize3NonZero()
{
	hkReal l2 = (x*x) + (y*y) + (z*z);
	l2 = hkMath::sqrtInverse(l2);
	this->mul4( l2 );
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
		hkEnum< hkpShapeType, hkUint32> m_type;
};

struct hkpShapeRayCastCollectorOutput
{
	                class MustEndWithSemiColon;
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
		                class MustEndWithSemiColon;
	public:
		hkpShapeKey m_shapeKeys[MAX_HIERARCHY_DEPTH];
	private:
		int m_shapeKeyIndex;
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
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		__forceinline void convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const ;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		inline hkReal getRadius() const;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
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

inline hkReal hkpConvexShape::getRadius() const
{
	return m_radius;
}

void hkpConvexShape::getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const
{
	this->getSupportingVertexImpl( direction, supportingVertexOut );
}

void hkpConvexShape::convertVertexIdsToVertices( const hkpVertexId* ids, int numIds, hkpCdVertex* vertixArrayOut) const
{
	this->convertVertexIdsToVerticesImpl( ids, numIds, vertixArrayOut );
}

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

class hkpCollideTriangleUtil
{
	public:
		enum
		{
			CLSLS_POINTA_START = 1,
			CLSLS_POINTA_END   = 2,
			CLSLS_POINTB_START = 4,
			CLSLS_POINTB_END   = 8
		};
		struct ClosestLineSegLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal>  m_distanceSquared;
		};
		static int __cdecl closestLineSegLineSeg( hkVector4Parameter A, hkVector4Parameter dA, hkVector4Parameter B, hkVector4Parameter dB, ClosestLineSegLineSegResult& result );
		struct ClosestPointLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_pointOnEdge;
		};
		struct ClosestPointTriangleCache
		{
			                class MustEndWithSemiColon;
			hkReal m_QQ;
			hkReal m_RR;
			hkReal m_QR;
			hkReal m_invTriNormal;
		};
		struct ClosestPointTriangleResult
		{
			                class MustEndWithSemiColon;
			hkVector4			hitDirection;
			hkPadSpu<hkReal>	distance;
		};
		enum ClosestPointTriangleStatus
		{
			HIT_TRIANGLE_FACE = 0,
			HIT_TRIANGLE_EDGE
		};
		struct PointTriangleDistanceCache
		{
			                class MustEndWithSemiColon;
			hkReal m_invEdgeLen[3];
			hkReal m_invNormalLen;
			hkReal m_normalLen;
		};
		static const hkInt8 maskToIndex[];
		static const hkInt8 vertexToEdgeLut[];
		static inline int __cdecl getNextModulo3( int i ) { return vertexToEdgeLut[i+2]; }
		static inline int __cdecl getPrevModulo3( int i ) { return vertexToEdgeLut[i]; }
};

class hkpGsk
{
	public:
		                class MustEndWithSemiColon;
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
			                class MustEndWithSemiColon;
			hkPadSpu<const hkTransform*> m_aTb;
			hkPadSpu<const hkTransform*> m_transformA;
			hkPadSpu<const hkpConvexShape*> m_shapeA;
			hkPadSpu<const hkpConvexShape*> m_shapeB;
			hkPadSpu<hkReal> m_collisionTolerance;
		};
		hkBool FUN_00a30fb0( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkRotation& aRb, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output );
	protected:
		ReduceDimensionResult reduceDimension();
	protected:
		int checkTriangleBoundaries( const hkVector4& point, hkVector4* triangle, SupportTypes stype );
		NextCase processEdgeTriangle( hkVector4* vertexA, hkVector4* vertexB, hkPadSpu<int>& dimA, hkPadSpu<int>& dimB, hkBool lastDimBWasTwo, SupportTypes stype );
	public:
		hkPadSpu<int> m_dimA;
		hkPadSpu<int> m_dimB;
		hkPadSpu<int> m_maxDimA;
		hkPadSpu<int> m_maxDimB;
		hkPadSpu<hkUint32> m_doNotHandlePenetration;
		hkPadSpu<int> m_featureChange;
		hkpCdVertex m_verticesA[4];
		hkVector4   m_dummy[4];
		hkVector4   m_verticesBinA[4];
		hkpCdVertex m_verticesBinB[4];
		hkVector4 m_support;
		hkpCollideTriangleUtil::ClosestLineSegLineSegResult m_closestLineLineResult;
		hkVector4 m_checkTriangleDots;
		hkPadSpu<int> m_lastDimB;
		SupportState m_supportState;
};

namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}

static int findClosestTriangleBackup( const hkVector4& a0, const hkVector4* tetra, hkVector4& oldDots, hkReal sign )
{
	for ( int i = 0; i < 3; i++ )
	{
		int in = hkpCollideTriangleUtil::getNextModulo3( i );
		int ip = hkpCollideTriangleUtil::getPrevModulo3( i );
		if ( oldDots(in) >= 0.0f && oldDots(ip) >= 0.0f )
		{
			hkVector4 edge0; edge0.setSub4( tetra[in], tetra[i] );
			hkVector4 edge1; edge1.setSub4( tetra[ip], tetra[i] );
			hkVector4 diffA0; diffA0.setSub4( a0, tetra[i] );
			hkVector4 diffT3; diffT3.setSub4( tetra[3], tetra[i] );
			hkReal da0 = diffA0.dot3( edge0 );
			hkReal da1 = diffA0.dot3( edge1 );
			hkReal dT0 = diffT3.dot3( edge0 );
			hkReal dT1 = diffT3.dot3( edge1 );
			if ( hkMath::isNegative( da0 * dT1 - da1 * dT0 ) )
			{
				oldDots(ip) = -1.0f;
			}
			else
			{
				oldDots(in) = -1.0f;
			}
		}
	}
	if ( oldDots(0) > 0.0f ) return 0;
	if ( oldDots(1) > 0.0f ) return 1;
	if ( oldDots(2) > 0.0f ) return 2;
	return -1;
}

static int findClosestTriangle( const hkVector4& a0, const hkVector4* tetra, hkReal sign )
{
	hkVector4 edge0; edge0.setSub4( tetra[2], tetra[1] );
	hkVector4 edge1; edge1.setSub4( tetra[0], tetra[2] );
	hkVector4 edge2; edge2.setSub4( tetra[1], tetra[0] );
	hkVector4 ne0; ne0.setSub4( tetra[3], tetra[0] );
	hkVector4 ne1; ne1.setSub4( tetra[3], tetra[1] );
	hkVector4 ne2; ne2.setSub4( tetra[3], tetra[2] );
	hkRotation normals;
	normals.getColumn(0).setCross( edge0, ne1 );
	normals.getColumn(1).setCross( edge1, ne2 );
	normals.getColumn(2).setCross( edge2, ne0 );
	hkVector4 relA; relA.setSub4( a0, tetra[3] );
	relA.mul4( sign );
	hkVector4 dots; dots._setRotatedInverseDir( normals, relA );
	hkVector4 dotsAbs; dotsAbs.setAbs4( dots );
	hkVector4 dotsSquared; dotsSquared.setMul4( dots, dotsAbs );
	hkReal distanceSquared[3];
	for ( int i = 0; i < 3; i++ )
	{
		hkReal normalLengthSquared = normals.getColumn(i).lengthSquared3();
		if ( normalLengthSquared != 0.0f )
		{
			distanceSquared[i] = dotsSquared(i) / normalLengthSquared;
		}
		else
		{
			distanceSquared[i] = 3.40282e+38f;
		}
	}
	int bestIndex = 1;
	if ( distanceSquared[0] > distanceSquared[1] )
	{
		hkAlgorithm::swap( distanceSquared[0], distanceSquared[1] );
		bestIndex = 0;
	}
	if ( distanceSquared[1] > distanceSquared[2] )
	{
		hkAlgorithm::swap( distanceSquared[1], distanceSquared[2] );
		if ( distanceSquared[0] > distanceSquared[1] )
		{
			hkAlgorithm::swap( distanceSquared[0], distanceSquared[1] );
		}
	}
	else
	{
		bestIndex = 2;
	}
	const hkReal maxDistanceSquared = 0.001f * 0.001f;
	if ( distanceSquared[2] < maxDistanceSquared )
	{
		return -1;
	}
	if ( distanceSquared[1] * 1.1f < distanceSquared[2] )
	{
		return bestIndex;
	}
	hkVector4 newdots = dots;
	int bestTri = findClosestTriangleBackup( a0, tetra, newdots, sign );
	return bestTri;
}

static __forceinline void process_point_edge( hkVector4* __restrict vertexA, hkVector4* __restrict vertexB, hkPadSpu<int>& dimB, hkVector4& support, hkpGsk::SupportTypes stype )
{
	hkVector4 edge; edge.setSub4( vertexB[1], vertexB[0] );
	hkVector4 a; a.setSub4( vertexB[1], vertexA[0] );
	hkVector4 b; b.setSub4( vertexB[0], vertexA[0] );
	hkReal adot = a.dot3( edge );
	hkReal bdot = b.dot3( edge );
	int maskA = hkMath::isNegative( adot );
	int maskB = hkMath::isNegative( bdot );
	if ( maskA != maskB )
	{
		edge.fastNormalize3NonZero();
		hkVector4 c; c.setCross( a, b );
		if ( stype == hkpGsk::BUILD_POS_SUPPORT )
		{
			support.setCross( edge, c );
		}
		else
		{
			support.setCross( c, edge );
		}
		return;
	}
	if ( maskA )
	{
		vertexB[0] = vertexB[1];
		vertexB[4] = vertexB[5];
	}
	dimB = dimB - 1;
	if ( stype == hkpGsk::BUILD_POS_SUPPORT )
	{
		support.setSub4( vertexA[0], vertexB[0] );
	}
	else
	{
		support.setSub4( vertexB[0], vertexA[0] );
	}
}

__forceinline hkpGsk::ReduceDimensionResult hkpGsk::reduceDimension()
{
	m_supportState = SUPPORT_CHANGED;
	while(1)
	{
		switch ( (m_dimA<<3) | m_dimB )
		{
			case GSK_POINT_POINT:
				{
					m_support.setSub4( m_verticesA[0], m_verticesBinA[0] );
					break;
				}
			case GSK_POINT_EDGE:
case_point_edge:
				{
					process_point_edge( m_verticesA, m_verticesBinA, m_dimB, m_support, BUILD_POS_SUPPORT );
					break;
				}
			case GSK_EDGE_POINT:
case_edge_point:
				{
					process_point_edge( m_verticesBinA, m_verticesA, m_dimA, m_support, BUILD_NEG_SUPPORT );
					break;
				}
			case GSK_POINT_TRIANGLE:
case_point_triangle:
				{
					int mask = checkTriangleBoundaries( m_verticesA[0], m_verticesBinA, BUILD_POS_SUPPORT );
					if ( mask == 0xe )
					{
						break;
					}
					int CI = hkpCollideTriangleUtil::maskToIndex[mask];
					if ( CI < 0 )
					{
						CI += 8;
						if ( CI > 3 )
						{
							CI = 1;
						}
						m_dimB = m_dimB - 1;
						m_verticesBinA[CI] = m_verticesBinA[2];
						m_verticesBinB[CI] = m_verticesBinB[2];
						goto case_point_edge;
					}
					int LI = hkpCollideTriangleUtil::getPrevModulo3( CI );
					int UI = hkpCollideTriangleUtil::getNextModulo3( CI );
					hkVector4 diff; diff.setSub4( m_verticesA[0], m_verticesBinA[CI] );
					hkVector4 ledge; ledge.setSub4( m_verticesBinA[LI], m_verticesBinA[CI] );
					hkVector4 uedge; uedge.setSub4( m_verticesBinA[UI], m_verticesBinA[CI] );
					if ( hkMath::isNegative( diff.dot3( ledge ) ) )
					{
						m_dimB = 2;
						m_verticesBinA[LI] = m_verticesBinA[2];
						m_verticesBinB[LI] = m_verticesBinB[2];
					}
					else
					{
						m_dimB = 2;
						m_verticesBinA[UI] = m_verticesBinA[2];
						m_verticesBinB[UI] = m_verticesBinB[2];
						continue;
					}
					if ( hkMath::isNegative( diff.dot3( uedge ) ) )
					{
						if ( UI == m_dimB )
						{
							UI = LI;
						}
						m_dimB = m_dimB - 1;
						m_verticesBinA[UI] = m_verticesBinA[m_dimB];
						m_verticesBinB[UI] = m_verticesBinB[m_dimB];
					}
					continue;
				}
			case GSK_TRIANGLE_POINT:
case_triangle_point:
				{
					int mask = checkTriangleBoundaries( m_verticesBinA[0], m_verticesA, BUILD_NEG_SUPPORT );
					if ( mask == 0xe )
					{
						break;
					}
					int CI = hkpCollideTriangleUtil::maskToIndex[mask];
					if ( CI < 0 )
					{
						CI += 8;
						if ( CI > 3 )
						{
							CI = 1;
						}
						m_dimA = m_dimA - 1;
						m_verticesA[CI] = m_verticesA[2];
						goto case_edge_point;
					}
					int LI = hkpCollideTriangleUtil::getPrevModulo3( CI );
					int UI = hkpCollideTriangleUtil::getNextModulo3( CI );
					hkVector4 diff; diff.setSub4( m_verticesBinA[0], m_verticesA[CI] );
					hkVector4 ledge; ledge.setSub4( m_verticesA[LI], m_verticesA[CI] );
					hkVector4 uedge; uedge.setSub4( m_verticesA[UI], m_verticesA[CI] );
					if ( hkMath::isNegative( diff.dot3( ledge ) ) )
					{
						m_dimA = 2;
						m_verticesA[LI] = m_verticesA[2];
					}
					else
					{
						m_dimA = 2;
						m_verticesA[UI] = m_verticesA[m_dimA];
						continue;
					}
					if ( hkMath::isNegative( diff.dot3( uedge ) ) )
					{
						if ( UI == m_dimA )
						{
							UI = LI;
						}
						m_dimA = m_dimA - 1;
						m_verticesA[UI] = m_verticesA[m_dimA];
					}
					continue;
				}
			case GSK_EDGE_TRIANGLE:
				{
					NextCase nextCase = processEdgeTriangle( m_verticesA, m_verticesBinA, m_dimA, m_dimB, m_lastDimB == 2, BUILD_POS_SUPPORT );
					switch ( nextCase )
					{
						case NEXT_IS_EDGE_EDGE:  goto case_edge_edge;
						case NEXT_IS_PENETRATION: goto penetration;
						default: break;
					}
					break;
				}
			case GSK_TRIANGLE_EDGE:
				{
					NextCase nextCase = processEdgeTriangle( m_verticesBinA, m_verticesA, m_dimB, m_dimA, m_lastDimB == 2, BUILD_NEG_SUPPORT );
					switch ( nextCase )
					{
						case NEXT_IS_EDGE_EDGE:  goto case_edge_edge;
						case NEXT_IS_PENETRATION: goto penetration;
						default: break;
					}
					break;
				}
			case GSK_EDGE_EDGE:
case_edge_edge:
				{
					hkVector4 edgeA; edgeA.setSub4( m_verticesA[1], m_verticesA[0] );
					hkVector4 edgeB; edgeB.setSub4( m_verticesBinA[1], m_verticesBinA[0] );
					int mask = hkpCollideTriangleUtil::closestLineSegLineSeg( m_verticesA[0], edgeA, m_verticesBinA[0], edgeB, m_closestLineLineResult );
					if ( mask == 0 )
					{
						m_support.setCross( edgeA, edgeB );
						hkVector4 pt0; pt0.setSub4( m_verticesA[0], m_verticesBinA[0] );
						if ( hkMath::isNegative( m_support.dot3( pt0 ) ) )
						{
							m_support.setNeg4( m_support );
						}
						break;
					}
					if ( mask & 1 )
					{
						m_verticesA[0] = m_verticesA[1];
						m_dimA = 1;
					}
					else if ( mask & 2 )
					{
						m_dimA = 1;
					}
					if ( mask & 4 )
					{
						m_verticesBinA[0] = m_verticesBinA[1];
						m_verticesBinB[0] = m_verticesBinB[1];
						m_dimB = 1;
					}
					else if ( mask & 8 )
					{
						m_dimB = 1;
					}
					continue;
				}
			case GSK_POINT_TETRA:
				{
					int maxIndex = findClosestTriangle( m_verticesA[0], m_verticesBinA, 1.0f );
					if ( maxIndex >= 0 )
					{
						m_dimB = m_dimB - 1;
						m_verticesBinA[maxIndex] = m_verticesBinA[3];
						m_verticesBinB[maxIndex] = m_verticesBinB[3];
						goto case_point_triangle;
					}
					goto penetration;
				}
			case GSK_TETRA_POINT:
				{
					int maxIndex = findClosestTriangle( m_verticesBinA[0], m_verticesA, -1.0f );
					if ( maxIndex >= 0 )
					{
						m_dimA = m_dimA - 1;
						m_verticesA[maxIndex] = m_verticesA[3];
						goto case_triangle_point;
					}
					goto penetration;
				}
			case GSK_NONE_NONE:
			default:
penetration:
				return REDUCE_DIMENSION_PENETRATION;
		}
		break;
	}
	m_lastDimB = m_dimB;
	return REDUCE_DIMENSION_OK;
}

hkBool hkpGsk::FUN_00a30fb0( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkRotation& aRb, const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output )
{
	hkVector4 ray; ray.setSub4( input.m_to, input.m_from );
	hkReal eps = 0.001f;
	hkReal radiusAB = ( shapeB ) ? shapeA->getRadius() + shapeB->getRadius() : shapeA->getRadius();
	hkReal radiusABplusEps2 = ( radiusAB + eps ) * ( radiusAB + eps );
	hkReal hitFraction = 0.0f;
	hkVector4 normal; normal.setZero4();
	hkVector4 pointOnRay = input.m_from;
	{
		hkpVertexId zero = 0;
		hkpCdVertex tmpv; shapeA->convertVertexIdsToVertices( &zero, 1, &tmpv );
		m_support.setSub4( pointOnRay, tmpv );
	}
	hkVector4 supportNormalized = m_support; supportNormalized.normalize3();
	m_dimA = 0;
	m_dimB = 1;
	hkpCdVertex supportVertex; supportVertex.setZero4();
	hkpCdVertex supportVertexB; supportVertexB.setZero4();
	hkReal dist = 1e7f;
	int count = 0;
	int loopCount = 0;
	while ( dist * dist > radiusABplusEps2 )
	{
		loopCount++;
		shapeA->getSupportingVertex( m_support, supportVertex );
		if ( shapeB )
		{
			hkVector4 supportB; supportB.setNeg4( m_support );
			supportB.setRotatedInverseDir( aRb, supportB );
			shapeB->getSupportingVertex( supportB, supportVertexB );
			hkVector4 rotSupportVertexB; rotSupportVertexB.setRotatedDir( aRb, supportVertexB );
			supportVertex.sub3clobberW( rotSupportVertexB );
		}
		hkBool add = true;
		for ( int i = 0; i < m_dimA; i++ )
		{
			if ( m_verticesA[i](0) == supportVertex(0) && m_verticesA[i](1) == supportVertex(1) && m_verticesA[i](2) == supportVertex(2) )
			{
				add = false;
				break;
			}
		}
		if ( add )
		{
			m_verticesA[m_dimA] = supportVertex;
			m_dimA = m_dimA + 1;
		}
		{
			hkVector4 w;
			{
				hkVector4 tmp = supportNormalized;
				hkVector4 displaceP; displaceP.setAddMul4( supportVertex, supportNormalized, radiusAB );
				w.setSub4( pointOnRay, displaceP );
			}
			hkReal dotVW = m_support.dot3( w );
			if ( dotVW > 0.0f )
			{
				hkReal dotVR = m_support.dot3( ray );
				if ( dotVR >= 0.0f )
				{
					return false;
				}
				hitFraction -= dotVW / dotVR;
				if ( hitFraction >= 1.0f )
				{
					return false;
				}
				pointOnRay.setAddMul4( input.m_from, ray, hitFraction );
				normal = supportNormalized;
			}
		}
		hkVector4 oldV = m_support;
		{
			static_cast<hkVector4&>( m_verticesBinB[0] ) = pointOnRay;
			m_verticesBinA[0] = m_verticesBinB[0];
			hkpGsk::ReduceDimensionResult reduceResult = reduceDimension();
			if ( reduceResult != REDUCE_DIMENSION_OK )
			{
				goto returnTrue;
			}
			m_support.setMul4( -1.0f, m_support );
			supportNormalized = m_support; supportNormalized.normalize3();
			for ( int i = 0; i < m_dimA; i++ )
			{
				hkVector4 tmp; tmp.setSub4( m_verticesBinA[0], m_verticesA[0] );
				hkReal tmpDist = supportNormalized.dot3( tmp );
				tmpDist = hkMath::fabs( tmpDist );
				if ( tmpDist < dist )
				{
					dist = tmpDist;
				}
			}
		}
		hkVector4 dV; dV.setSub4( m_support, oldV );
		if ( dV.lengthSquared3() < 1e-10f && ++count >= 3 )
		{
			break;
		}
	}
returnTrue:
	if ( hitFraction < output.m_hitFraction )
	{
		output.m_hitFraction = hitFraction;
		if ( normal.lengthSquared3() > 0.0f )
		{
			output.m_normal = normal;
		}
		else
		{
			output.m_normal = normal;
		}
		return true;
	}
	else
	{
		return false;
	}
}

} // namespace f3m_00a30fb0
}   // namespace f3m_00a30fb0

// @f3 0x00a2ea30 (community match, verified in this file)
#include <math.h>
extern const float DAT_00e7c758;
namespace f3m_00a2ea30 {
// FLAGS: /MT /O2 /GS /EHsc /Gy
// Fake match: explicitly bind the normal's negative-zero fourth lane.

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
    __forceinline float& lane(int i) { return ((float*)this)[i]; }
    __forceinline const float& lane(int i) const { return ((const float*)this)[i]; }
    __forceinline void assign(float a, float b, float c, float d) {
        x = a; y = b; z = c; w = d;
    }
    __forceinline void difference(const Vec4& a, const Vec4& b) {
        x = a.x-b.x; y = a.y-b.y; z = a.z-b.z; w = a.w-b.w;
    }
    __forceinline void cross(const Vec4& a, const Vec4& b) {
        float a0 = a.lane(1)*b.lane(2)-a.lane(2)*b.lane(1);
        float a1 = a.lane(2)*b.lane(0)-a.lane(0)*b.lane(2);
        float a2 = a.lane(0)*b.lane(1)-a.lane(1)*b.lane(0);
        assign(a0,a1,a2,0.0f);
    }
    __forceinline float dot(const Vec4& b) const {
        return x*b.x+y*b.y+z*b.z;
    }
    __forceinline void negate(const Vec4& a) {
        // Fake match: specialized to this routine's normal, whose w is zero.
        x=-a.x; y=-a.y; z=-a.z; w=DAT_00e7c758;
    }
    __forceinline void scale(float t) {
        float s=t;
        x*=s; y*=s; z*=s; w*=s;
    }
    __forceinline float invLength() const;
};
__forceinline float root(float x) { return sqrtf(x); }
__forceinline float invRoot(float x) { return 1.0f/root(x); }
__forceinline float Vec4::invLength() const {
    float square=x*x+y*y+z*z;
    return square ? invRoot(square) : 0.0f;
}

static __declspec(noinline) float FUN_00a2ea30(const Vec4& p, Vec4* v, const Vec4& q, Vec4& out) {
    Vec4 e1;
    e1.difference(v[2],v[1]);
    Vec4 e2;
    e2.difference(v[0],v[2]);
    out.cross(e1,e2);
    float inv=out.invLength();
    if (out.dot(q)<0.0f) out.negate(out);
    out.scale(inv);
    Vec4 delta;
    delta.difference(p,v[0]);
    // Fake match: the indexed X accessor preserves the final dot-product order.
    return delta.lane(0)*out.x+delta.y*out.y+delta.z*out.z;
}
// Fake match: artificial caller reproduces the target's private register ABI.
Vec4 g_v[3],g_out,g_p,g_q;
void caller_of_FUN_00a2ea30() {
    g_out.w=FUN_00a2ea30(g_p,g_v,g_q,g_out);
}
}   // namespace f3m_00a2ea30

// @f3 0x00a29960 (community match, verified in this file)
// FLAGS: /MT /O2 /GS /EHsc /Gy
typedef unsigned long DWORD;
extern "C" void* (__stdcall* DAT_00fdf044)(DWORD);
extern const char DAT_00e3c118[], DAT_00e3c0e0[], DAT_00e3c0d0[], DAT_00e3c0c4[], DAT_00e3ee04[], DAT_00e3c0f0[];
namespace ClassCopyA29960 {
struct Class;
struct Enum;
struct Member;
struct Attributes;
struct Interfaces;
struct Allocator {void* FUN_008f6f60(int bytes,int category);};
extern DWORD DAT_010f3170;
extern Class DAT_0116a994;
struct Cache {
    void* buckets;
    int count;
    unsigned mask;
    void FUN_00922cb0();
};
struct Record {Class* output;Cache offsets;};
struct ArrayValue {void* data;int count;};
struct Variant {
    void* object;
    Class* type;
    void FUN_0093d7d0(void*,Class*);
    __forceinline Variant(void* p,Class* t){FUN_0093d7d0(p,t);}
};
struct Value {
    void* data;
    const void* member;
    void FUN_0093d600(const Variant&,const char*);
    __forceinline Value(const Variant& v,const char* name){FUN_0093d600(v,name);}
    void* FUN_0093d660();
    const ArrayValue& FUN_0093d760(int);
    void*& FUN_0093d670(int);
    int* FUN_0093d6c0(int);
    const int& FUN_0093d6b0(int);
};
struct Class {
    const char* name;
    Class* parent;
    int objectSize;
    int interfaceCount;
    Enum* enums;
    int enumCount;
    Member* members;
    int memberCount;
    void* defaults;
    Attributes* attributes;
    unsigned flags;
    int describedVersion;
    Class* FUN_009b04a0();
    const char* FUN_009b0490();
    void FUN_009b08a0(const char*,Class*,int,const Interfaces*,int,Enum*,int,Member*,int,void*,Attributes*,unsigned);
};
struct Converter {void FUN_00a29760(Class*,Class**);};
char* __cdecl FUN_00923640(const char*);
struct Owner;
void __cdecl FUN_00901e90(Owner*,int count,int elementSize);
struct Owner {
    Record* data;
    int count;
    unsigned capacityAndFlags;
    Enum* FUN_00a29500(void*,int);
    Member* FUN_00a297f0(void*,int,void*,Enum*,int,Cache*,Converter*);
    void* FUN_00a295f0(Class*,void*);
    Class* FUN_00a29960(Class*,const char*,Converter*);
};
Class* Owner::FUN_00a29960(Class* source,const char* optionalName,Converter* converter)
{
    int previous=count;
    int required=previous+1;
    int capacity=capacityAndFlags&0x3fffffff;
    if(capacity<required) {
        int grown=capacity*2;
        if(required>=grown)grown=required;
        FUN_00901e90(this,grown,sizeof(Record));
    }
    count=required;
    Record* record=data+previous;
    Allocator* allocator=static_cast<Allocator*>(DAT_00fdf044(DAT_010f3170));
    record->output=static_cast<Class*>(allocator->FUN_008f6f60(sizeof(Class),6));
    Cache* cache=&record->offsets;
    // Fake match: express the original placement-construction null check explicitly.
    if(cache)cache->FUN_00922cb0();
    if(source->FUN_009b04a0()) {
        Variant destination(record->output,&DAT_0116a994);
        Value parent(destination,::DAT_00e3c118);
        Class** parentAddress=static_cast<Class**>(parent.FUN_0093d660());
        converter->FUN_00a29760(source->FUN_009b04a0(),parentAddress);
    }
    Variant input(source,&DAT_0116a994);
    char* name;
    // Fake match: split the string-copy call across the name-selection arms to reproduce scalar spill allocation.
    if(optionalName) name=FUN_00923640(optionalName); else name=FUN_00923640(source->FUN_009b0490());
    Value enumField(input,::DAT_00e3c0e0);
    const ArrayValue& enums=enumField.FUN_0093d760(0);
    Enum* copiedEnums=FUN_00a29500(enums.data,enums.count);
    Value memberField(input,::DAT_00e3c0d0);
    const ArrayValue& members=memberField.FUN_0093d760(0);
    Member* copiedMembers=FUN_00a297f0(members.data,members.count,enums.data,copiedEnums,enums.count,&record->offsets,converter);
    Value defaultField(input,::DAT_00e3c0c4);
    void* copiedDefaults=FUN_00a295f0(source,defaultField.FUN_0093d670(0));
    Class* output=record->output;
    if(output) {
        Value flagsField(input,::DAT_00e3ee04);
        Value interfacesField(input,::DAT_00e3c0f0);
        output->FUN_009b08a0(name,source->FUN_009b04a0(),0,0,interfacesField.FUN_0093d6b0(0),copiedEnums,enums.count,copiedMembers,members.count,copiedDefaults,0,static_cast<unsigned>(*flagsField.FUN_0093d6c0(0)));
    }
    return record->output;
}
}

// @f3 0x00a21830 (community match, verified in this file)
// FUN_00a21830 = Havok 5.5.0 hkJobQueue::finishJobAndGetNextJob (hkBase.lib, hkJobQueue.obj; the stock release object
// is byte-exact against the game). Finishes the old job (the queue's finish callback may create a follow-up job, which is
// queued), then takes the next job by the thread type's query rules; with none left it releases or wakes waiting threads
// and reports ALL_JOBS_FINISHED, or blocks on the thread type's semaphore and tries again.
// Types, macros and inline bodies: Havok 5.5.0 SDK text (hkJobQueue.h, hkQueue.inl, hkMonitorStream.h/.inl,
// hkWin32CriticalSection.inl, hkBaseTypes.h), asserts empty as in the release build. Reconstructed (the .cpp is not
// shipped): finishJobAndGetNextJob, lockQueue, unlockQueue and the three force-inline helpers, from the hybrid library
// object's line records and locals (hkJobQueue.cpp lines 146-174 and 377-524). Cut to one file by hktrim.py.
// The one assembly block is the SDK's timer read in hkMonitorStream::TimerCommand::setTime (rdtsc).
namespace f3m_00a21830 {
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
		typedef unsigned __int64 hkUint64;

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
	public:
		__forceinline hkPadSpu() {}
		__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
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

extern "C" {
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
extern "C" {
extern "C" {
    typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;
}
typedef long LONG;
typedef void *HANDLE;
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * PRLIST_ENTRY;
typedef struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD   Type;
    WORD   CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD   CreatorBackTraceIndexHigh;
    WORD   SpareWORD  ;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;
typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
}
}

extern "C" {
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
}

class hkCriticalSection
{
	public:
		inline void enter();
		inline void leave();
	public:
		CRITICAL_SECTION  m_section;
		hkUint64 m_currentThread;
		struct SectionList
		{
			int m_spinCount;
			hkCriticalSection* m_prev;
			hkCriticalSection* m_next;
			static hkCriticalSection s_listHead;
		};
		SectionList m_list;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection( CRITICAL_SECTION* lpCriticalSection );

	inline void hkCriticalSection::leave()
	{
		m_currentThread = hkUint64(-1);	// HK_INVALID_THREAD_ID
		LeaveCriticalSection(&m_section );
	}

class hkMonitorStream
{
	public:
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
			const char* m_commandAndMonitor;
		};
		struct TimerCommand : public hkMonitorStream::Command
		{
			hkUint32	m_time0;
			hkUint32	m_time1;
			__forceinline void setTime();
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
		{ // HK_TIMER_END()
			hkMonitorStream& mStream = hkMonitorStream::getInstance();
			if ( mStream.memoryAvailable() )
			{
				hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
				h->m_commandAndMonitor = "E" "t" "";
				h->setTime();
				mStream.setEnd( (char*)(h+1) );
			}
		}
};

class hkSemaphore
{
	public:
		void acquire();
		static void __cdecl release(hkSemaphore* semaphoreOnPpu, int count = 1);
	protected:	void* m_semaphore;
};

typedef hkSemaphore hkSemaphoreBusyWait;

template <typename T>
class hkQueue
{
	public:
		inline void setCapacity(int n);
		inline void enqueue( const T& element );
		inline void enqueueInFront( const T& element );
		inline void dequeue( T& data );
		inline hkBool isEmpty() const;
		inline int getSize() const;
	private:
		inline void increaseCapacity();
		T* m_data;
		int m_capacity;
		int m_head;
		int m_tail;
		int m_elementsInUse;
};

template <typename T>
inline hkBool hkQueue<T>::isEmpty() const
{
	return m_elementsInUse == 0;
}

template <typename T>
inline int hkQueue<T>::getSize() const
{
	return m_elementsInUse;
}

template <typename T>
inline void hkQueue<T>::increaseCapacity( )
{
	if( m_capacity == 0 )
	{
		setCapacity( 8 );
	}
	else
	{
		setCapacity( m_capacity * 2 );
	}
}

template <typename T>
inline void hkQueue<T>::enqueue( const T& element )
{
    if( m_elementsInUse >= m_capacity )
    {
	    increaseCapacity();
    }
	if( m_tail == m_capacity )
	{
		m_tail = 0;
	}
	m_data[m_tail++] = element;
	m_elementsInUse++;
}

template <typename T>
inline void hkQueue<T>::enqueueInFront( const T& element )
{
    if( m_elementsInUse >= m_capacity )
    {
	    increaseCapacity();
    }
    if( m_head == 0 )
    {
	    m_head = m_capacity;
    }
    m_data[--m_head] = element;
    m_elementsInUse++;
}

template <typename T>
inline void hkQueue<T>::dequeue( T& data )
{
    // HK_ASSERT(0xf032ed23, m_elementsInUse ); (empty in release)
    {
	    data = m_data[m_head];
	    if( ++m_head == m_capacity )
	    {
		    m_head = 0;
	    }
	    m_elementsInUse--;
    }
}

class hkJobQueue
{
	public:
		enum Rules
		{
			NO_SPU_AVAILABLE,
			SPU_AVAILABLE_AND_PPU_CAN_TAKE_SPU_TASKS,
			SPU_AVAILABLE_AND_PPU_CANNOT_TAKE_SPU_TASKS
		};
		struct JobQueueEntry
		{
			__declspec(align(16)) hkUchar m_data[128];
		};
		enum JobType
		{
			JOB_TYPE_CPU			= 0,
			JOB_TYPE_CPU_BROADPHASE	= 1,
			JOB_TYPE_CPU_MASTER		= 2,
			JOB_TYPE_HINT_SPU		= 0,
			JOB_TYPE_HINT_SPU_CD	= 0,
			JOB_TYPE_HINT_SPU_CQ	= 0,
			JOB_TYPE_MAX			= 3,
		};
		struct DynamicData
		{
			__declspec(align(16)) int m_numActiveJobs;
			int m_numCpuThreadsWaitingForJobs;
			int m_numSpuThreadsWaitingForJobs;
			int m_numMasterThreadsWaitingForJobs;
			hkBool m_dontReleaseSpus;
			hkQueue< JobQueueEntry > m_jobQueue[JOB_TYPE_MAX];
		};
		enum ThreadType
		{
			THREAD_TYPE_CPU				= JOB_TYPE_CPU,
			THREAD_TYPE_CPU_BROADPHASE	= JOB_TYPE_CPU_BROADPHASE,
			THREAD_TYPE_CPU_MASTER		= JOB_TYPE_CPU_MASTER,
			THREAD_TYPE_MAX				= JOB_TYPE_MAX,
			THREAD_TYPE_INVALID			= -1,
		};
		enum JobPriority
		{
			JOB_HIGH_PRIORITY,
			JOB_LOW_PRIORITY,
		};
		enum JobPopFuncResult
		{
			POP_QUEUE_ENTRY,
			DO_NOT_POP_QUEUE_ENTRY
		};
		typedef JobPopFuncResult (__cdecl *JobPopFunc)( hkJobQueue& queue, hkJobQueue::DynamicData* data, JobQueueEntry& jobIn, JobQueueEntry& jobOut );
		enum JobCreationStatus
		{
			JOB_CREATED,
			NO_JOB_CREATED
		};
		struct JobQueueEntryInput
		{
			hkPadSpu<hkUint32>	m_jobThreadType;
			hkPadSpu<hkUint32>	m_jobPriority;
			JobQueueEntry		m_job;
		};
		typedef JobCreationStatus (__cdecl *FinishJobFunc)( hkJobQueue& queue, DynamicData* data, const JobQueueEntry& jobIn, JobQueueEntryInput& newJobCreatedOut );
	public:
		enum WaitStatus
		{
			WAIT_FOR_NEXT_JOB,
			DO_NOT_WAIT_FOR_NEXT_JOB
		};
		enum JobStatus
		{
			GOT_NEXT_JOB,
			NO_JOBS_AVAILABLE,
			JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
			ALL_JOBS_FINISHED
		};
		JobStatus FUN_00a21830( ThreadType threadType, const JobQueueEntry* oldJob, JobQueueEntry& jobOut, void* params = 0, WaitStatus waitStatus = WAIT_FOR_NEXT_JOB );
	public:
		__forceinline void checkQueueAndReleaseOneWaitingThread( ThreadType threadType, DynamicData* data  );
		__forceinline JobStatus findNextJob(ThreadType threadType, JobQueueEntry& jobOut, DynamicData* data );
		__forceinline hkBool allQueuesEmpty( DynamicData* data );
		DynamicData* lockQueue( char* dynamicDataStorage );
		void unlockQueue( char* dynamicDataStorage );
		void releaseWaitingThreads(DynamicData* data);
	public:
		__declspec(align(64)) hkCriticalSection m_criticalSection;
		DynamicData* m_data;
		struct JobQueryRule
		{
			hkUint8 m_numJobTypesAvailable;
			hkEnum<JobType, hkUint8> m_jobTypeOrder[JOB_TYPE_MAX];
		};
		JobQueryRule m_jobQueryRules[JOB_TYPE_MAX];
		JobPopFunc m_jobPopFunc;
		FinishJobFunc m_finishJobFunc;
		hkUlong m_userData;
		hkSemaphoreBusyWait* m_masterThreadWaitSemaphore;
		hkSemaphoreBusyWait* m_cpuWaitSemaphore;
		hkSemaphoreBusyWait* m_taskCompletionSemaphore;
		hkSemaphoreBusyWait* m_spuWaitSemaphore;
};

hkJobQueue::DynamicData* hkJobQueue::lockQueue( char* dynamicDataStorage )
{
	// HK_ASSERT( 0xff00ff00, (hkUlong(dynamicDataStorage) & 0xf) == 0 ); (empty in release)
	m_criticalSection.enter();
	return m_data;
}

void hkJobQueue::unlockQueue( char* dynamicDataStorage )
{
	// HK_ASSERT( 0xff00ff00, (hkUlong(dynamicDataStorage) & 0xf) == 0 ); (empty in release)
	m_criticalSection.leave();
}

__forceinline void hkJobQueue::checkQueueAndReleaseOneWaitingThread( ThreadType threadType, DynamicData* data )
{
	int numJobs = data->m_jobQueue[JOB_TYPE_CPU].getSize() + data->m_jobQueue[JOB_TYPE_CPU_BROADPHASE].getSize();
	if ( numJobs )
	{
		if ( data->m_numMasterThreadsWaitingForJobs )
		{
			data->m_numMasterThreadsWaitingForJobs--;
			hkSemaphoreBusyWait::release( m_masterThreadWaitSemaphore );
		}
		else if ( data->m_numCpuThreadsWaitingForJobs )
		{
			data->m_numCpuThreadsWaitingForJobs--;
			hkSemaphoreBusyWait::release( m_cpuWaitSemaphore );
		}
	}
}

__forceinline hkJobQueue::JobStatus hkJobQueue::findNextJob( ThreadType threadType, JobQueueEntry& jobOut, DynamicData* data )
{
	JobQueryRule& rule = m_jobQueryRules[threadType];
	for ( int i = 0; i < rule.m_numJobTypesAvailable; i++ )
	{
		hkQueue<JobQueueEntry>& queue = data->m_jobQueue[ rule.m_jobTypeOrder[i] ];
		if ( !queue.isEmpty() )
		{
			JobQueueEntry job;
			queue.dequeue( job );
			if ( m_jobPopFunc( *this, data, job, jobOut ) == DO_NOT_POP_QUEUE_ENTRY )
			{
				queue.enqueueInFront( job );
			}
			data->m_numActiveJobs++;
			return GOT_NEXT_JOB;
		}
	}
	return NO_JOBS_AVAILABLE;
}

__forceinline hkBool hkJobQueue::allQueuesEmpty( DynamicData* data )
{
	int numJobs = data->m_jobQueue[JOB_TYPE_CPU].getSize() + data->m_jobQueue[JOB_TYPE_CPU_BROADPHASE].getSize();
	return numJobs == 0;
}

// pdb: hkJobQueue::finishJobAndGetNextJob | hkJobQueue.obj | fnv360_0822_debug, call_seq, medium
// pdb params: oldJob, jobOut, waitStatus
hkJobQueue::JobStatus hkJobQueue::FUN_00a21830( ThreadType threadType, const JobQueueEntry* oldJob, JobQueueEntry& jobOut, void* params, WaitStatus waitStatus )
{
	// HK_TIME_CODE_BLOCK( "GetNextJob", HK_NULL ): HK_TIMER_BEGIN, then a helper whose destructor ends the timer
	{ // HK_TIMER_BEGIN( "GetNextJob" )
		hkMonitorStream& mStream = hkMonitorStream::getInstance();
		if ( mStream.memoryAvailable() )
		{
			hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
			h->m_commandAndMonitor = "T" "t" "GetNextJob";
			h->setTime();
			mStream.setEnd( (char*)(h+1) );
		}
	}
	hkTimeFunctionHelper timeblock391;

	// HK_ASSERT( 0xf032e454, threadType >= -1 && threadType < THREAD_TYPE_MAX ); (empty in release)
	while ( 1 )
	{
		__declspec(align(16)) char dynamicDataStorage[128];
		DynamicData* data = lockQueue( dynamicDataStorage );
		hkBool jobCreated = false;
		JobQueueEntryInput createdJob;
		if ( oldJob )
		{
			if ( m_finishJobFunc( *this, data, *oldJob, createdJob ) == JOB_CREATED )
			{
				if ( createdJob.m_jobPriority == JOB_HIGH_PRIORITY )
				{
					data->m_jobQueue[ createdJob.m_jobThreadType ].enqueueInFront( createdJob.m_job );
				}
				else
				{
					data->m_jobQueue[ createdJob.m_jobThreadType ].enqueue( createdJob.m_job );
				}
				jobCreated = true;
			}
			if ( threadType == THREAD_TYPE_INVALID )
			{
				checkQueueAndReleaseOneWaitingThread( (ThreadType)createdJob.m_jobThreadType.val(), data );
				unlockQueue( dynamicDataStorage );
				return NO_JOBS_AVAILABLE;
			}
			data->m_numActiveJobs--;
			oldJob = 0;
		}
		JobStatus result = findNextJob( threadType, jobOut, data );
		if ( result == GOT_NEXT_JOB )
		{
			checkQueueAndReleaseOneWaitingThread( threadType, data );
			unlockQueue( dynamicDataStorage );
			return GOT_NEXT_JOB;
		}
		if ( data->m_numActiveJobs == 0 && allQueuesEmpty( data ) )
		{
			if ( data->m_dontReleaseSpus )
			{
				if ( data->m_numMasterThreadsWaitingForJobs > 0 )
				{
					data->m_numMasterThreadsWaitingForJobs--;
					hkSemaphoreBusyWait::release( m_masterThreadWaitSemaphore );
				}
				if ( threadType == THREAD_TYPE_CPU_MASTER )
				{
					unlockQueue( dynamicDataStorage );
					return ALL_JOBS_FINISHED;
				}
			}
			else
			{
				releaseWaitingThreads( data );
				unlockQueue( dynamicDataStorage );
				return ALL_JOBS_FINISHED;
			}
		}
		if ( waitStatus == DO_NOT_WAIT_FOR_NEXT_JOB )
		{
			unlockQueue( dynamicDataStorage );
			return NO_JOBS_AVAILABLE;
		}
		if ( threadType != THREAD_TYPE_CPU_MASTER )
		{
			data->m_numCpuThreadsWaitingForJobs++;
			unlockQueue( dynamicDataStorage );
			{ // HK_TIMER_BEGIN( "WaitForSignal" )
				hkMonitorStream& mStream = hkMonitorStream::getInstance();
				if ( mStream.memoryAvailable() )
				{
					hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
					h->m_commandAndMonitor = "T" "t" "WaitForSignal";
					h->setTime();
					mStream.setEnd( (char*)(h+1) );
				}
			}
			m_cpuWaitSemaphore->acquire();
			{ // HK_TIMER_END()
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
		else
		{
			data->m_numMasterThreadsWaitingForJobs++;
			unlockQueue( dynamicDataStorage );
			{ // HK_TIMER_BEGIN( "WaitForSignal" )
				hkMonitorStream& mStream = hkMonitorStream::getInstance();
				if ( mStream.memoryAvailable() )
				{
					hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
					h->m_commandAndMonitor = "T" "t" "WaitForSignal";
					h->setTime();
					mStream.setEnd( (char*)(h+1) );
				}
			}
			m_masterThreadWaitSemaphore->acquire();
			{ // HK_TIMER_END()
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
	}
}

}

// @f3 0x00a32da0 (community match, verified in this file)
namespace f3m_00a32da0 {
// hkpGsk_getClosestFeature = Havok 5.5.0 hkpGsk::getClosestFeature (hkpInternal.lib, hkpGsk.obj; the stock release object is
// byte-exact against the game). RECONSTRUCTED (the SDK ships neither hkpGsk.cpp nor hkpGsk.h) from the library
// objects' debug records: hybrid line records 797-942 and locals, release/debug out-of-line copies of the static
// helpers, pdb class layouts, and the SDK's verbatim inline bodies; cut to one file with hktrim.py.
// The target and hkGskCalcSupportDistSquared were written for this file; the helpers come from an earlier match.
namespace f3m_00a32da0 {
// reduced by hktrim.py from sdk_final.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
typedef signed char		hkInt8;
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
	private:
		int m_mask;
		friend class hkVector4;
};

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
	inline int __cdecl isNegative(hkReal r0)
	{
		return (r0<0)? hkVector4Comparison::MASK_X : 0;
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
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline void fastNormalize3NonZero();
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
		__forceinline hkTransform(const hkTransform& r);
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkRotation& getRotation() const;
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

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline void hkVector4::setAbs4(const hkVector4& v)
{
	x = hkMath::fabs(v.x);
	y = hkMath::fabs(v.y);
	z = hkMath::fabs(v.z);
	w = hkMath::fabs(v.w);
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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

inline void hkVector4::fastNormalize3NonZero()
{
	hkReal l2 = (x*x) + (y*y) + (z*z);
	l2 = hkMath::sqrtInverse(l2);
	this->mul4( l2 );
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
		hkEnum< hkpShapeType, hkUint32> m_type;
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
		__forceinline void getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const;
		virtual void getFirstVertex(hkVector4& v) const = 0;
		enum WeldResult
		{
			WELD_RESULT_REJECT_CONTACT_POINT,
			WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
			WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
		};
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

void hkpConvexShape::getSupportingVertex( hkVector4Parameter direction, hkpCdVertex& supportingVertexOut ) const
{
	this->getSupportingVertexImpl( direction, supportingVertexOut );
}

class hkpCollideTriangleUtil
{
	public:
		enum
		{
			CLSLS_POINTA_START = 1,
			CLSLS_POINTA_END   = 2,
			CLSLS_POINTB_START = 4,
			CLSLS_POINTB_END   = 8
		};
		struct ClosestLineSegLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_closestPointA;
			hkVector4 m_closestAminusClosestB;
			hkPadSpu<hkReal>  m_distanceSquared;
		};
		static int __cdecl closestLineSegLineSeg( hkVector4Parameter A, hkVector4Parameter dA, hkVector4Parameter B, hkVector4Parameter dB, ClosestLineSegLineSegResult& result );
		struct ClosestPointLineSegResult
		{
			                class MustEndWithSemiColon;
			hkVector4 m_pointOnEdge;
		};
		struct ClosestPointTriangleCache
		{
			                class MustEndWithSemiColon;
			hkReal m_QQ;
			hkReal m_RR;
			hkReal m_QR;
			hkReal m_invTriNormal;
		};
		struct ClosestPointTriangleResult
		{
			                class MustEndWithSemiColon;
			hkVector4			hitDirection;
			hkPadSpu<hkReal>	distance;
		};
		enum ClosestPointTriangleStatus
		{
			HIT_TRIANGLE_FACE = 0,
			HIT_TRIANGLE_EDGE
		};
		struct PointTriangleDistanceCache
		{
			                class MustEndWithSemiColon;
			hkReal m_invEdgeLen[3];
			hkReal m_invNormalLen;
			hkReal m_normalLen;
		};
		static const hkInt8 maskToIndex[];
		static const hkInt8 vertexToEdgeLut[];
		static inline int __cdecl getNextModulo3( int i ) { return vertexToEdgeLut[i+2]; }
		static inline int __cdecl getPrevModulo3( int i ) { return vertexToEdgeLut[i]; }
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
		                class MustEndWithSemiColon;
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
			                class MustEndWithSemiColon;
			hkPadSpu<const hkTransform*> m_aTb;
			hkPadSpu<const hkTransform*> m_transformA;
			hkPadSpu<const hkpConvexShape*> m_shapeA;
			hkPadSpu<const hkpConvexShape*> m_shapeB;
			hkPadSpu<hkReal> m_collisionTolerance;
		};
		hkpGskStatus hkpGsk_getClosestFeature( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb, hkVector4& separatingNormal );
	protected:
		ReduceDimensionResult reduceDimension();
		void handlePenetration( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb );
	protected:
		int checkTriangleBoundaries( const hkVector4& point, hkVector4* triangle, SupportTypes stype );
		NextCase processEdgeTriangle( hkVector4* vertexA, hkVector4* vertexB, hkPadSpu<int>& dimA, hkPadSpu<int>& dimB, hkBool lastDimBWasTwo, SupportTypes stype );
	public:
		hkPadSpu<int> m_dimA;
		hkPadSpu<int> m_dimB;
		hkPadSpu<int> m_maxDimA;
		hkPadSpu<int> m_maxDimB;
		hkPadSpu<hkUint32> m_doNotHandlePenetration;
		hkPadSpu<int> m_featureChange;
		hkpCdVertex m_verticesA[4];
		hkVector4   m_dummy[4];
		hkVector4   m_verticesBinA[4];
		hkpCdVertex m_verticesBinB[4];
		hkVector4 m_support;
		hkpCollideTriangleUtil::ClosestLineSegLineSegResult m_closestLineLineResult;
		hkVector4 m_checkTriangleDots;
		hkPadSpu<int> m_lastDimB;
		SupportState m_supportState;
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
	checkRegisters( 0xf0000000 );
	hkTransform unaliased = t;
	int i = numVectors - 1;
	do
	{
		vectorsOut[i]._setTransformedPos( unaliased, vectorsIn[i] );
	} while( --i >= 0 );
}

static __forceinline hkReal hkGskCalcSupportDistSquared( const hkVector4& support, const hkVector4& newPoint, const hkVector4& oldPoint )
{
	hkVector4 diff0; diff0.setSub4( newPoint, oldPoint );
	hkReal dot0 = diff0.dot3( support );
	return dot0 * hkMath::fabs( dot0 );
}

namespace hkAlgorithm
{
	template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}

static int findClosestTriangleBackup( const hkVector4& a0, const hkVector4* tetra, hkVector4& oldDots, hkReal sign )
{
	for ( int i = 0; i < 3; i++ )
	{
		int in = hkpCollideTriangleUtil::getNextModulo3( i );
		int ip = hkpCollideTriangleUtil::getPrevModulo3( i );
		if ( oldDots(in) >= 0.0f && oldDots(ip) >= 0.0f )
		{
			hkVector4 edge0; edge0.setSub4( tetra[in], tetra[i] );
			hkVector4 edge1; edge1.setSub4( tetra[ip], tetra[i] );
			hkVector4 diffA0; diffA0.setSub4( a0, tetra[i] );
			hkVector4 diffT3; diffT3.setSub4( tetra[3], tetra[i] );
			hkReal da0 = diffA0.dot3( edge0 );
			hkReal da1 = diffA0.dot3( edge1 );
			hkReal dT0 = diffT3.dot3( edge0 );
			hkReal dT1 = diffT3.dot3( edge1 );
			if ( hkMath::isNegative( da0 * dT1 - da1 * dT0 ) )
			{
				oldDots(ip) = -1.0f;
			}
			else
			{
				oldDots(in) = -1.0f;
			}
		}
	}
	if ( oldDots(0) > 0.0f ) return 0;
	if ( oldDots(1) > 0.0f ) return 1;
	if ( oldDots(2) > 0.0f ) return 2;
	return -1;
}

static int findClosestTriangle( const hkVector4& a0, const hkVector4* tetra, hkReal sign )
{
	hkVector4 edge0; edge0.setSub4( tetra[2], tetra[1] );
	hkVector4 edge1; edge1.setSub4( tetra[0], tetra[2] );
	hkVector4 edge2; edge2.setSub4( tetra[1], tetra[0] );
	hkVector4 ne0; ne0.setSub4( tetra[3], tetra[0] );
	hkVector4 ne1; ne1.setSub4( tetra[3], tetra[1] );
	hkVector4 ne2; ne2.setSub4( tetra[3], tetra[2] );
	hkRotation normals;
	normals.getColumn(0).setCross( edge0, ne1 );
	normals.getColumn(1).setCross( edge1, ne2 );
	normals.getColumn(2).setCross( edge2, ne0 );
	hkVector4 relA; relA.setSub4( a0, tetra[3] );
	relA.mul4( sign );
	hkVector4 dots; dots._setRotatedInverseDir( normals, relA );
	hkVector4 dotsAbs; dotsAbs.setAbs4( dots );
	hkVector4 dotsSquared; dotsSquared.setMul4( dots, dotsAbs );
	hkReal distanceSquared[3];
	for ( int i = 0; i < 3; i++ )
	{
		hkReal normalLengthSquared = normals.getColumn(i).lengthSquared3();
		if ( normalLengthSquared != 0.0f )
		{
			distanceSquared[i] = dotsSquared(i) / normalLengthSquared;
		}
		else
		{
			distanceSquared[i] = 3.40282e+38f;
		}
	}
	int bestIndex = 1;
	if ( distanceSquared[0] > distanceSquared[1] )
	{
		hkAlgorithm::swap( distanceSquared[0], distanceSquared[1] );
		bestIndex = 0;
	}
	if ( distanceSquared[1] > distanceSquared[2] )
	{
		hkAlgorithm::swap( distanceSquared[1], distanceSquared[2] );
		if ( distanceSquared[0] > distanceSquared[1] )
		{
			hkAlgorithm::swap( distanceSquared[0], distanceSquared[1] );
		}
	}
	else
	{
		bestIndex = 2;
	}
	const hkReal maxDistanceSquared = 0.001f * 0.001f;
	if ( distanceSquared[2] < maxDistanceSquared )
	{
		return -1;
	}
	if ( distanceSquared[1] * 1.1f < distanceSquared[2] )
	{
		return bestIndex;
	}
	hkVector4 newdots = dots;
	int bestTri = findClosestTriangleBackup( a0, tetra, newdots, sign );
	return bestTri;
}

static __forceinline void process_point_edge( hkVector4* __restrict vertexA, hkVector4* __restrict vertexB, hkPadSpu<int>& dimB, hkVector4& support, hkpGsk::SupportTypes stype )
{
	hkVector4 edge; edge.setSub4( vertexB[1], vertexB[0] );
	hkVector4 a; a.setSub4( vertexB[1], vertexA[0] );
	hkVector4 b; b.setSub4( vertexB[0], vertexA[0] );
	hkReal adot = a.dot3( edge );
	hkReal bdot = b.dot3( edge );
	int maskA = hkMath::isNegative( adot );
	int maskB = hkMath::isNegative( bdot );
	if ( maskA != maskB )
	{
		edge.fastNormalize3NonZero();
		hkVector4 c; c.setCross( a, b );
		if ( stype == hkpGsk::BUILD_POS_SUPPORT )
		{
			support.setCross( edge, c );
		}
		else
		{
			support.setCross( c, edge );
		}
		return;
	}
	if ( maskA )
	{
		vertexB[0] = vertexB[1];
		vertexB[4] = vertexB[5];
	}
	dimB = dimB - 1;
	if ( stype == hkpGsk::BUILD_POS_SUPPORT )
	{
		support.setSub4( vertexA[0], vertexB[0] );
	}
	else
	{
		support.setSub4( vertexB[0], vertexA[0] );
	}
}

__forceinline hkpGsk::ReduceDimensionResult hkpGsk::reduceDimension()
{
	m_supportState = SUPPORT_CHANGED;
	while(1)
	{
		switch ( (m_dimA<<3) | m_dimB )
		{
			case GSK_POINT_POINT:
				{
					m_support.setSub4( m_verticesA[0], m_verticesBinA[0] );
					break;
				}
			case GSK_POINT_EDGE:
case_point_edge:
				{
					process_point_edge( m_verticesA, m_verticesBinA, m_dimB, m_support, BUILD_POS_SUPPORT );
					break;
				}
			case GSK_EDGE_POINT:
case_edge_point:
				{
					process_point_edge( m_verticesBinA, m_verticesA, m_dimA, m_support, BUILD_NEG_SUPPORT );
					break;
				}
			case GSK_POINT_TRIANGLE:
case_point_triangle:
				{
					int mask = checkTriangleBoundaries( m_verticesA[0], m_verticesBinA, BUILD_POS_SUPPORT );
					if ( mask == 0xe )
					{
						break;
					}
					int CI = hkpCollideTriangleUtil::maskToIndex[mask];
					if ( CI < 0 )
					{
						CI += 8;
						if ( CI > 3 )
						{
							CI = 1;
						}
						m_dimB = m_dimB - 1;
						m_verticesBinA[CI] = m_verticesBinA[2];
						m_verticesBinB[CI] = m_verticesBinB[2];
						goto case_point_edge;
					}
					int LI = hkpCollideTriangleUtil::getPrevModulo3( CI );
					int UI = hkpCollideTriangleUtil::getNextModulo3( CI );
					hkVector4 diff; diff.setSub4( m_verticesA[0], m_verticesBinA[CI] );
					hkVector4 ledge; ledge.setSub4( m_verticesBinA[LI], m_verticesBinA[CI] );
					hkVector4 uedge; uedge.setSub4( m_verticesBinA[UI], m_verticesBinA[CI] );
					if ( hkMath::isNegative( diff.dot3( ledge ) ) )
					{
						m_dimB = 2;
						m_verticesBinA[LI] = m_verticesBinA[2];
						m_verticesBinB[LI] = m_verticesBinB[2];
					}
					else
					{
						m_dimB = 2;
						m_verticesBinA[UI] = m_verticesBinA[2];
						m_verticesBinB[UI] = m_verticesBinB[2];
						continue;
					}
					if ( hkMath::isNegative( diff.dot3( uedge ) ) )
					{
						if ( UI == m_dimB )
						{
							UI = LI;
						}
						m_dimB = m_dimB - 1;
						m_verticesBinA[UI] = m_verticesBinA[m_dimB];
						m_verticesBinB[UI] = m_verticesBinB[m_dimB];
					}
					continue;
				}
			case GSK_TRIANGLE_POINT:
case_triangle_point:
				{
					int mask = checkTriangleBoundaries( m_verticesBinA[0], m_verticesA, BUILD_NEG_SUPPORT );
					if ( mask == 0xe )
					{
						break;
					}
					int CI = hkpCollideTriangleUtil::maskToIndex[mask];
					if ( CI < 0 )
					{
						CI += 8;
						if ( CI > 3 )
						{
							CI = 1;
						}
						m_dimA = m_dimA - 1;
						m_verticesA[CI] = m_verticesA[2];
						goto case_edge_point;
					}
					int LI = hkpCollideTriangleUtil::getPrevModulo3( CI );
					int UI = hkpCollideTriangleUtil::getNextModulo3( CI );
					hkVector4 diff; diff.setSub4( m_verticesBinA[0], m_verticesA[CI] );
					hkVector4 ledge; ledge.setSub4( m_verticesA[LI], m_verticesA[CI] );
					hkVector4 uedge; uedge.setSub4( m_verticesA[UI], m_verticesA[CI] );
					if ( hkMath::isNegative( diff.dot3( ledge ) ) )
					{
						m_dimA = 2;
						m_verticesA[LI] = m_verticesA[2];
					}
					else
					{
						m_dimA = 2;
						m_verticesA[UI] = m_verticesA[m_dimA];
						continue;
					}
					if ( hkMath::isNegative( diff.dot3( uedge ) ) )
					{
						if ( UI == m_dimA )
						{
							UI = LI;
						}
						m_dimA = m_dimA - 1;
						m_verticesA[UI] = m_verticesA[m_dimA];
					}
					continue;
				}
			case GSK_EDGE_TRIANGLE:
				{
					NextCase nextCase = processEdgeTriangle( m_verticesA, m_verticesBinA, m_dimA, m_dimB, m_lastDimB == 2, BUILD_POS_SUPPORT );
					switch ( nextCase )
					{
						case NEXT_IS_EDGE_EDGE:  goto case_edge_edge;
						case NEXT_IS_PENETRATION: goto penetration;
						default: break;
					}
					break;
				}
			case GSK_TRIANGLE_EDGE:
				{
					NextCase nextCase = processEdgeTriangle( m_verticesBinA, m_verticesA, m_dimB, m_dimA, m_lastDimB == 2, BUILD_NEG_SUPPORT );
					switch ( nextCase )
					{
						case NEXT_IS_EDGE_EDGE:  goto case_edge_edge;
						case NEXT_IS_PENETRATION: goto penetration;
						default: break;
					}
					break;
				}
			case GSK_EDGE_EDGE:
case_edge_edge:
				{
					hkVector4 edgeA; edgeA.setSub4( m_verticesA[1], m_verticesA[0] );
					hkVector4 edgeB; edgeB.setSub4( m_verticesBinA[1], m_verticesBinA[0] );
					int mask = hkpCollideTriangleUtil::closestLineSegLineSeg( m_verticesA[0], edgeA, m_verticesBinA[0], edgeB, m_closestLineLineResult );
					if ( mask == 0 )
					{
						m_support.setCross( edgeA, edgeB );
						hkVector4 pt0; pt0.setSub4( m_verticesA[0], m_verticesBinA[0] );
						if ( hkMath::isNegative( m_support.dot3( pt0 ) ) )
						{
							m_support.setNeg4( m_support );
						}
						break;
					}
					if ( mask & 1 )
					{
						m_verticesA[0] = m_verticesA[1];
						m_dimA = 1;
					}
					else if ( mask & 2 )
					{
						m_dimA = 1;
					}
					if ( mask & 4 )
					{
						m_verticesBinA[0] = m_verticesBinA[1];
						m_verticesBinB[0] = m_verticesBinB[1];
						m_dimB = 1;
					}
					else if ( mask & 8 )
					{
						m_dimB = 1;
					}
					continue;
				}
			case GSK_POINT_TETRA:
				{
					int maxIndex = findClosestTriangle( m_verticesA[0], m_verticesBinA, 1.0f );
					if ( maxIndex >= 0 )
					{
						m_dimB = m_dimB - 1;
						m_verticesBinA[maxIndex] = m_verticesBinA[3];
						m_verticesBinB[maxIndex] = m_verticesBinB[3];
						goto case_point_triangle;
					}
					goto penetration;
				}
			case GSK_TETRA_POINT:
				{
					int maxIndex = findClosestTriangle( m_verticesBinA[0], m_verticesA, -1.0f );
					if ( maxIndex >= 0 )
					{
						m_dimA = m_dimA - 1;
						m_verticesA[maxIndex] = m_verticesA[3];
						goto case_triangle_point;
					}
					goto penetration;
				}
			case GSK_NONE_NONE:
			default:
penetration:
				return REDUCE_DIMENSION_PENETRATION;
		}
		break;
	}
	m_lastDimB = m_dimB;
	return REDUCE_DIMENSION_OK;
}

// pdb: hkpGsk::getClosestFeature | hkpGsk.obj | fnv360_0822_debug, call_seq + bridge(call_seq|call_gap) + skyrim(call_seq), high
hkpGskStatus hkpGsk::hkpGsk_getClosestFeature( const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb, hkVector4& separatingNormalOut )
{
	hkVector4Util::transformPoints( aTb, &m_verticesBinB[0], m_dimB, &m_verticesBinA[0] );
	int loopCounter = 0;
	hkReal terminationEpsSquared = 1e-10f;
	while ( 1 )
	{
		loopCounter++;
		terminationEpsSquared *= 2.0f;
		int dim = m_dimA + m_dimB;
		ReduceDimensionResult result = reduceDimension();
		const hkReal supportLengthSquared = m_support.lengthSquared3();
		m_featureChange = m_featureChange | ( m_dimA + m_dimB - dim );
		{
			hkVector4 diff; diff.setSub4( m_verticesA[0], m_verticesBinA[0] );
			hkReal distUnscaled = diff.dot3( m_support );
			if ( result != REDUCE_DIMENSION_OK || distUnscaled * hkMath::fabs( distUnscaled ) <= terminationEpsSquared * supportLengthSquared || supportLengthSquared < terminationEpsSquared )
			{
				if ( !m_doNotHandlePenetration )
				{
					handlePenetration( shapeA, shapeB, aTb );
					break;
				}
				else
				{
					if ( m_dimA + m_dimB > 4 )
					{
						if ( m_dimA > m_dimB )
						{
							m_dimA = 3;
							m_dimB = 1;
						}
						else
						{
							m_dimA = 1;
							m_dimB = 3;
						}
					}
					return HK_GSK_PENETRATING;
				}
			}
		}
		const hkReal eps = terminationEpsSquared * supportLengthSquared;
		if ( loopCounter & 1 )
		{
			if ( m_dimA != m_maxDimA && m_supportState != DONT_CALL_GET_SUPPORTING_VERTEX_A )
			{
				hkVector4 supportA; supportA.setNeg4( m_support );
				shapeA->getSupportingVertex( supportA, m_verticesA[m_dimA] );
				if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[0] ) > eps )
				{
					switch ( m_dimA )
					{
						case 3: if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[2] ) < eps ) break;
						case 2: if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[1] ) < eps ) break;
						default:
							m_dimA = m_dimA + 1;
							m_featureChange = 1;
							continue;
					}
				}
			}
		}
		if ( m_dimB != m_maxDimB && m_supportState != DONT_CALL_GET_SUPPORTING_VERTEX_B )
		{
			hkVector4 supportB; supportB._setRotatedInverseDir( aTb.getRotation(), m_support );
			shapeB->getSupportingVertex( supportB, m_verticesBinB[m_dimB] );
			if ( hkGskCalcSupportDistSquared( supportB, m_verticesBinB[m_dimB], m_verticesBinB[0] ) > eps )
			{
				switch ( m_dimB )
				{
					case 3: if ( hkGskCalcSupportDistSquared( supportB, m_verticesBinB[m_dimB], m_verticesBinB[2] ) < eps ) break;
					case 2: if ( hkGskCalcSupportDistSquared( supportB, m_verticesBinB[m_dimB], m_verticesBinB[1] ) < eps ) break;
					default:
						m_verticesBinA[m_dimB]._setTransformedPos( aTb, m_verticesBinB[m_dimB] );
						m_dimB = m_dimB + 1;
						m_featureChange = 1;
						continue;
				}
			}
		}
		if ( ( loopCounter & 1 ) == 0 )
		{
			if ( m_dimA != m_maxDimA && m_supportState != DONT_CALL_GET_SUPPORTING_VERTEX_A )
			{
				hkVector4 supportA; supportA.setNeg4( m_support );
				shapeA->getSupportingVertex( supportA, m_verticesA[m_dimA] );
				if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[0] ) > eps )
				{
					switch ( m_dimA )
					{
						case 3: if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[2] ) < eps ) break;
						case 2: if ( hkGskCalcSupportDistSquared( supportA, m_verticesA[m_dimA], m_verticesA[1] ) < eps ) break;
						default:
							m_dimA = m_dimA + 1;
							m_featureChange = 1;
							continue;
					}
				}
			}
		}
		break;
	}
	{
		hkVector4 diff; diff.setSub4( m_verticesA[0], m_verticesBinA[0] );
		m_support.normalize3();
		separatingNormalOut = m_support;
		hkReal dist = diff.dot3( m_support );
		separatingNormalOut(3) = dist;
		m_support(3) = dist;
	}
	return HK_GSK_OK;
}

} // namespace f3m_00a32da0
}   // namespace f3m_00a32da0

// @f3 0x00a3bc00 (community match, verified in this file)
namespace f3m_00a3bc00 {
// FUN_00a3bc00 = Havok 5.5.0 hkpBoxBoxCollisionDetection::checkIntersection (hkpInternal.lib,
// hkpBoxBoxCollisionDetection.obj; the stock release object is byte-exact against the game).
// Reconstructed (the .cpp is not shipped) from the hybrid object's line records 990-1130 and locals, the release
// object's out-of-line setvdProj / rsqrtAll3 / selectIfGT3 copies, the pdb layouts and the SDK's verbatim inline
// bodies; cut with hktrim.py.
namespace f3m_00a3bc00 {
// reduced by hktrim.py from sdk_final.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
typedef float  hkReal;
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

typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
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
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};




namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkMatrix3;
class hkRotation;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void add4(const hkVector4& a);
		__forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
		__forceinline void sub4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(const hkVector4& a);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline hkVector4Comparison compareLessThan4(hkVector4Parameter a) const;
		__forceinline hkVector4Comparison compareGreaterThan4(hkVector4Parameter a) const;
		__forceinline void setAbs4(const hkVector4& v);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
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
		__forceinline hkReal& operator() (int row, int col);
		__forceinline const hkReal& operator() (int row, int col) const;
		void setTranspose( const hkMatrix3& s );
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

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
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

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
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

inline hkVector4Comparison hkVector4::compareGreaterThan4(hkVector4Parameter a) const
{
	return a.compareLessThan4(*this);
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

const hkRotation& hkTransform::getRotation() const
{
	return m_rotation;
}

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	protected:
		                class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};

class hkpCdBody;
struct hkpProcessCollisionOutput;

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

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
};

class hkpContactPointProperties : public hkpSolverResults, public hkContactPointMaterial
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_internalDataA;
		typedef hkUint32 UserData;
};

class hkpConstraintOwner;
struct hkpProcessCollisionData;
struct hkpProcessCollisionInput;
class hkpCollidable;

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

class hkpBoxBoxCollisionDetection
{
	public:
		                class MustEndWithSemiColon;
		enum hkpBoxBoxFeature
		{
			HK_BOXBOX_FACE_A_X = 0, HK_BOXBOX_FACE_A_Y = 1, HK_BOXBOX_FACE_A_Z = 2,
			HK_BOXBOX_FACE_B_X = 4, HK_BOXBOX_FACE_B_Y = 5, HK_BOXBOX_FACE_B_Z = 6,
			HK_BOXBOX_EDGE_0_0 = 8, HK_BOXBOX_EDGE_0_1 = 9, HK_BOXBOX_EDGE_0_2 = 10,
			HK_BOXBOX_EDGE_1_0 = 12, HK_BOXBOX_EDGE_1_1 = 13, HK_BOXBOX_EDGE_1_2 = 14,
			HK_BOXBOX_EDGE_2_0 = 16, HK_BOXBOX_EDGE_2_1 = 17, HK_BOXBOX_EDGE_2_2 = 18,
			HK_BOXBOX_FEATURE_COUNT = 19
		};
		enum
		{
			HK_FINDCLOSESTPOINT_NO_VALID_POINT = 0,
			HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD = 1,
			HK_FINDCLOSESTPOINT_VALID_POINT = 2
		};
		class hkpFeaturePointCache
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_vA;
				hkVector4 m_vB;
				hkVector4 m_nA;
				hkReal m_normalSign;
				hkReal m_distance;
				int m_featureIndexA;
				int m_featureIndexB;
		};
	public:
		hkResult FUN_00a3bc00( const hkVector4& tolerance ) const;
		__forceinline void setvdProj( const hkRotation& bRa, int edgeNext, int edgeNextNext, hkVector4& vdproj ) const;
	public:
		const hkpCdBody& m_bodyA;
		const hkpCdBody& m_bodyB;
		const hkpProcessCollisionInput* m_env;
		hkpContactMgr* m_contactMgr;
		hkpProcessCollisionOutput* m_result;
		const hkTransform& m_wTa;
		const hkTransform& m_wTb;
		hkTransform m_aTb;
		hkVector4 m_radiusA;
		hkVector4 m_radiusB;
		hkVector4 m_tolerance4;
		hkVector4 m_keepRadiusA;
		hkVector4 m_keepRadiusB;
		const hkReal m_tolerance;
		const hkReal m_boundaryTolerance;
		hkVector4 m_dinA;
		hkVector4 m_dinB;
		mutable hkVector4 m_sepDist[5];
		static const int m_maxFeaturesToReject;
		static const hkReal m_manifoldConsistencyCheckAngularCosTolerance;
		static const hkReal m_contactNormalAngularCosTolerance;
};

class hkBoxBoxUtils
{
	public:
		static __forceinline void __cdecl rsqrtAll3( hkVector4& v );
		static __forceinline void __cdecl selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than );
};

void hkpBoxBoxCollisionDetection::setvdProj( const hkRotation& bRa, int edgeNext, int edgeNextNext, hkVector4& vdproj ) const
{
	hkVector4 a; a.setMul4( m_dinA.getSimdAt( edgeNextNext ), bRa.getColumn( edgeNext ) );
	hkVector4 b; b.setMul4( m_dinA.getSimdAt( edgeNext ), bRa.getColumn( edgeNextNext ) );
	vdproj.setSub4( a, b );
	vdproj.setAbs4( vdproj );
}

void __cdecl hkBoxBoxUtils::selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than )
{
	result(0) = ( greater(0) > than ) ? selectIf : result(0);
	result(1) = ( greater(1) > than ) ? selectIf : result(1);
	result(2) = ( greater(2) > than ) ? selectIf : result(2);
}

void __cdecl hkBoxBoxUtils::rsqrtAll3( hkVector4& v )
{
	const hkReal eps = 1.192092896e-07F;
	v(0) = hkMath::sqrtInverse( v(0) + eps );
	v(1) = hkMath::sqrtInverse( v(1) + eps );
	v(2) = hkMath::sqrtInverse( v(2) + eps );
	v(3) = 0.0f;
}

// pdb: hkpBoxBoxCollisionDetection::checkIntersection | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun, medium
// pdb params: tolerance
hkResult hkpBoxBoxCollisionDetection::FUN_00a3bc00( const hkVector4& tolerance ) const
{
	const hkReal HK_EDGE_IGNORE_TOLERANCE = 1.0f / 0.001f;
	const hkReal FLT_MINPS = -1e17f;
	hkRotation aRb_;
	aRb_.getColumn(0).setAbs4( m_aTb.getRotation().getColumn(0) );
	aRb_.getColumn(1).setAbs4( m_aTb.getRotation().getColumn(1) );
	aRb_.getColumn(2).setAbs4( m_aTb.getRotation().getColumn(2) );
	{
		hkVector4 vWidth; vWidth._setRotatedDir( aRb_, m_radiusB );
		hkVector4 vdProj; vdProj.setAbs4( m_dinA );
		vWidth.add4( m_radiusA );
		vdProj.sub4( vWidth );
		if ( vdProj.compareGreaterThan4( tolerance ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
		{
			return HK_FAILURE;
		}
		m_sepDist[0] = vdProj;
	}
	{
		hkVector4 vWidth; vWidth._setRotatedInverseDir( aRb_, m_radiusA );
		hkVector4 vdProj; vdProj.setAbs4( m_dinB );
		vWidth.add4( m_radiusB );
		vdProj.sub4( vWidth );
		if ( vdProj.compareGreaterThan4( tolerance ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
		{
			return HK_FAILURE;
		}
		m_sepDist[1] = vdProj;
	}
	{
		hkRotation bRa; bRa.setTranspose( m_aTb.getRotation() );
		hkVector4 aRbSquaredC0 = bRa.getColumn(0);
		hkVector4 aRbSquaredC1 = bRa.getColumn(1);
		hkVector4 aRbSquaredC2 = bRa.getColumn(2);
		aRbSquaredC0.mul4( aRbSquaredC0 );
		aRbSquaredC1.mul4( aRbSquaredC1 );
		aRbSquaredC2.mul4( aRbSquaredC2 );
		{
			hkVector4 vdProj; setvdProj( bRa, 1, 2, vdProj );
			hkVector4 vWidth; vWidth.set( aRb_(2,0) * m_radiusA(1) + aRb_(1,0) * m_radiusA(2) + aRb_(0,2) * m_radiusB(1) + aRb_(0,1) * m_radiusB(2),
			                              aRb_(2,1) * m_radiusA(1) + aRb_(1,1) * m_radiusA(2) + aRb_(0,2) * m_radiusB(0) + aRb_(0,0) * m_radiusB(2),
			                              aRb_(2,2) * m_radiusA(1) + aRb_(1,2) * m_radiusA(2) + aRb_(0,1) * m_radiusB(0) + aRb_(0,0) * m_radiusB(1) );
			hkVector4 vXprodLengthInv; vXprodLengthInv.setAdd4( aRbSquaredC2, aRbSquaredC1 );
			vdProj.sub4( vWidth );
			hkBoxBoxUtils::rsqrtAll3( vXprodLengthInv );
			vdProj.setMul4( vXprodLengthInv, vdProj );
			if ( vdProj.compareGreaterThan4( m_tolerance4 ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
			{
				return HK_FAILURE;
			}
			hkBoxBoxUtils::selectIfGT3( vdProj, FLT_MINPS, vXprodLengthInv, HK_EDGE_IGNORE_TOLERANCE );
			m_sepDist[2] = vdProj;
		}
		{
			hkVector4 vdProj; setvdProj( bRa, 2, 0, vdProj );
			hkVector4 vWidth; vWidth.set( aRb_(2,0) * m_radiusA(0) + aRb_(0,0) * m_radiusA(2) + aRb_(1,2) * m_radiusB(1) + aRb_(1,1) * m_radiusB(2),
			                              aRb_(2,1) * m_radiusA(0) + aRb_(0,1) * m_radiusA(2) + aRb_(1,2) * m_radiusB(0) + aRb_(1,0) * m_radiusB(2),
			                              aRb_(2,2) * m_radiusA(0) + aRb_(0,2) * m_radiusA(2) + aRb_(1,1) * m_radiusB(0) + aRb_(1,0) * m_radiusB(1) );
			hkVector4 vXprodLengthInv; vXprodLengthInv.setAdd4( aRbSquaredC2, aRbSquaredC0 );
			vdProj.sub4( vWidth );
			hkBoxBoxUtils::rsqrtAll3( vXprodLengthInv );
			vdProj.setMul4( vXprodLengthInv, vdProj );
			if ( vdProj.compareGreaterThan4( m_tolerance4 ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
			{
				return HK_FAILURE;
			}
			hkBoxBoxUtils::selectIfGT3( vdProj, FLT_MINPS, vXprodLengthInv, HK_EDGE_IGNORE_TOLERANCE );
			m_sepDist[3] = vdProj;
		}
		{
			hkVector4 vdProj; setvdProj( bRa, 0, 1, vdProj );
			hkVector4 vWidth; vWidth.set( aRb_(1,0) * m_radiusA(0) + aRb_(0,0) * m_radiusA(1) + aRb_(2,2) * m_radiusB(1) + aRb_(2,1) * m_radiusB(2),
			                              aRb_(1,1) * m_radiusA(0) + aRb_(0,1) * m_radiusA(1) + aRb_(2,0) * m_radiusB(2) + aRb_(2,2) * m_radiusB(0),
			                              aRb_(1,2) * m_radiusA(0) + aRb_(0,2) * m_radiusA(1) + aRb_(2,1) * m_radiusB(0) + aRb_(2,0) * m_radiusB(1) );
			hkVector4 vXprodLengthInv; vXprodLengthInv.setAdd4( aRbSquaredC1, aRbSquaredC0 );
			vdProj.sub4( vWidth );
			hkBoxBoxUtils::rsqrtAll3( vXprodLengthInv );
			vdProj.setMul4( vXprodLengthInv, vdProj );
			if ( vdProj.compareGreaterThan4( m_tolerance4 ).anyIsSet( hkVector4Comparison::MASK_XYZ ) )
			{
				return HK_FAILURE;
			}
			hkBoxBoxUtils::selectIfGT3( vdProj, FLT_MINPS, vXprodLengthInv, HK_EDGE_IGNORE_TOLERANCE );
			m_sepDist[4] = vdProj;
		}
	}
	return HK_SUCCESS;
}

} // namespace f3m_00a3bc00
}   // namespace f3m_00a3bc00

// @f3 0x00a38200 (community match, verified in this file)
namespace f3m_00a38200 {
// FUN_00a38200 = Havok 5.5.0 hkGskManifold_verifyAndGetPoints (hkpInternal.lib, hkpGskManifoldUtil.obj; the stock
// release object is byte-exact against the game). RECONSTRUCTED (hkpGskManifoldUtil.cpp/.h are not shipped) from the
// hybrid object's records (lines 441-493; the inlined convert helpers read from the hybrid code), the release /
// debug_multithreaded out-of-line copies of the helpers and of hkGskManifold_garbageCollect, the pdb layouts and the
// SDK's verbatim inline bodies; cut with hktrim.py. See note.txt.
namespace f3m_00a38200 {
// reduced by hktrim.py from sdk.cpp; compile: cl -c -Ox -Ob1 -Oi -Ot -GF -MT -GS- -Z7 -TP -X
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

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

class hkClass;
typedef int hkBool32;

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
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
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		int getMask() const { return m_mask; }
	private:
		int m_mask;
		friend class hkVector4;
};


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
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

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkVector4& getPosition();
		inline void setSeparatingNormal( const hkVector4& separatingNormal );
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
		                class MustEndWithSemiColon;
};

class hkpCdBody;
class hkpCollidable;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpConstraintOwner;

struct hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
};

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

namespace hkVector4Util
{
	__forceinline void __cdecl dot3_3vs3( const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_2vs2( const hkVector4& a0, const hkVector4& a2, const hkVector4& b0, const hkVector4& b1, hkVector4& dotsOut);
}

inline void __cdecl hkVector4Util::dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( b0 );
	dotsOut(1) = a1.dot3( b1 );
	dotsOut(2) = a2.dot3( b2 );
	dotsOut(3) = 0;
}

inline void __cdecl hkVector4Util::dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( vectorIn );
	dotsOut(1) = a1.dot3( vectorIn );
	dotsOut(2) = a2.dot3( vectorIn );
	dotsOut(3) = a3.dot3( vectorIn );
}

inline void __cdecl hkVector4Util::dot3_2vs2( const hkVector4& a0, const hkVector4& a2, const hkVector4& b0, const hkVector4& b1, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( b0 );
	dotsOut(1) = a0.dot3( b1 );
	dotsOut(2) = a2.dot3( b0 );
	dotsOut(3) = a2.dot3( b1 );
}

struct hkpGskManifold
{
	                class MustEndWithSemiColon;
	struct ContactPoint
	{
		                class MustEndWithSemiColon;
		hkUchar m_dimA;
		hkUchar m_dimB;
		hkContactPointId m_id;
		union
		{
			hkUchar m_vert[4];
			hkUint32 m_allVerts;
		};
	};
	typedef hkUint16 VertexId;
	enum { MAX_POINTS = 4 };
	enum { MAX_VERTICES = MAX_POINTS * 4  };
	__forceinline VertexId* getVertexIds();
	hkUchar  m_numVertsA;
	hkUchar  m_numVertsB;
	hkUchar  m_numContactPoints;
	ContactPoint m_contactPoints[ MAX_POINTS ];
	hkUchar m_padding[ MAX_VERTICES * sizeof(VertexId) ];
};

hkpGskManifold::VertexId* hkpGskManifold::getVertexIds()
{
	return (VertexId*)( &m_contactPoints[m_numContactPoints] );
}

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

struct hkpGskManifoldWork
{
	                class MustEndWithSemiColon;
	inline const hkVector4& getVertexA( hkUint32 offset ) const
	{
		return *hkAddByteOffsetConst( &m_vertices[0], offset );
	}
	inline const hkVector4& getVertexB( hkUint32 offset ) const
	{
		return *hkAddByteOffsetConst( &m_vertices[0], offset );
	}
	hkpCdVertex m_vertices[ hkpGskManifold::MAX_VERTICES ];
	hkVector4 m_masterNormal;
	hkPadSpu<hkReal> m_radiusA;
	hkPadSpu<hkReal> m_radiusB;
	hkPadSpu<hkReal> m_keepContact;
	hkPadSpu<hkReal> m_radiusSumSqrd;
};

struct hkGskManifoldConvertOut
{
	hkVector4 m_pointOnA;
	hkVector4 m_AminusB;
	hkVector4 m_normal;
};

static void hkGskManifold_garbageCollect( hkpGskManifold& manifold )
{
	__declspec(align(16)) hkUchar verts[ hkpGskManifold::MAX_VERTICES ];
	reinterpret_cast<hkVector4*>( verts )->setZero4();
	for ( unsigned int cp = 0; cp < manifold.m_numContactPoints; cp++ )
	{
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[cp];
		int dim = feature.m_dimA + feature.m_dimB;
		verts[ feature.m_vert[0] >> 4 ] = 1;
		verts[ feature.m_vert[1] >> 4 ] = 1;
		if ( dim >= 3 ) { verts[ feature.m_vert[2] >> 4 ] = 1; }
		if ( dim == 4 ) { verts[ feature.m_vert[3] >> 4 ] = 1; }
	}
	hkPadSpu<hkUint32> oldToNewMap[ hkpGskManifold::MAX_VERTICES ];
	{
		hkpGskManifold::VertexId* vertexIds = manifold.getVertexIds();
		int numVerts = manifold.m_numVertsA + manifold.m_numVertsB;
		int s = 0;
		int d = 0;
		int d16 = 0;
		for ( ; s < numVerts; s++ )
		{
			oldToNewMap[s] = d16;
			if ( verts[s] )
			{
				vertexIds[d] = vertexIds[s];
				d++;
				d16 += sizeof(hkVector4);
				continue;
			}
		}
		manifold.m_numVertsA = hkUchar( oldToNewMap[ manifold.m_numVertsA ] >> 4 );
		manifold.m_numVertsB = hkUchar( d - manifold.m_numVertsA );
	}
	for ( unsigned int i = 0; i < manifold.m_numContactPoints; i++ )
	{
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[i];
		feature.m_vert[0] = hkUchar( oldToNewMap[ feature.m_vert[0] >> 4 ] );
		feature.m_vert[1] = hkUchar( oldToNewMap[ feature.m_vert[1] >> 4 ] );
		feature.m_vert[2] = hkUchar( oldToNewMap[ feature.m_vert[2] >> 4 ] );
		feature.m_vert[3] = hkUchar( oldToNewMap[ feature.m_vert[3] >> 4 ] );
	}
}

__forceinline int hkGskManifold_convertPointPoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pB = work.getVertexB( feature.m_vert[1] );
	hkVector4 diff; diff.setSub4( pA, pB );
	hkReal dist2 = diff.lengthSquared3();
	if ( dist2 > work.m_radiusSumSqrd )
	{
		return 1;
	}
	out.m_AminusB = diff;
	out.m_normal = work.m_masterNormal;
	out.m_pointOnA = pA;
	return 0;
}

__forceinline int hkGskManifold_convertPointEdge( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA  = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pB0 = work.getVertexB( feature.m_vert[1] );
	const hkVector4& pB1 = work.getVertexB( feature.m_vert[2] );
	out.m_pointOnA = pA;
	out.m_normal = work.m_masterNormal;
	hkVector4 edge; edge.setSub4( pB1, pB0 );
	hkVector4 a; a.setSub4( pB1, pA );
	hkVector4 b; b.setSub4( pA, pB0 );
	hkVector4 cross; cross.setCross( edge, a );
	hkVector4 dots;
	hkVector4Util::dot3_3vs3( a, edge, b, edge, cross, cross, dots );
	hkReal edgeLen2 = edge.lengthSquared3();
	hkBool32 outside = dots.compareLessThanZero4().anyIsSet( hkVector4Comparison::MASK_XY );
	if ( dots(3) > work.m_radiusSumSqrd * edgeLen2 || outside )
	{
		return 1;
	}
	hkSimdReal frac = dots.getSimdAt(0) / ( dots.getSimdAt(0) + dots.getSimdAt(1) );
	hkVector4 pointOnB; pointOnB.setInterpolate4( pB0, pB1, frac );
	out.m_AminusB.setSub4( pA, pointOnB );
	return 0;
}

__forceinline int hkGskManifold_convertEdgePoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& pB  = work.getVertexB( feature.m_vert[2] );
	out.m_normal = work.m_masterNormal;
	hkVector4 edge; edge.setSub4( pA1, pA0 );
	hkVector4 a; a.setSub4( pA1, pB );
	hkVector4 b; b.setSub4( pB, pA0 );
	hkVector4 cross; cross.setCross( edge, a );
	hkVector4 dots;
	hkVector4Util::dot3_3vs3( a, edge, b, edge, cross, cross, dots );
	hkReal edgeLen2 = edge.lengthSquared3();
	hkBool32 outside = dots.compareLessThanZero4().anyIsSet( hkVector4Comparison::MASK_XY );
	if ( dots(3) > work.m_radiusSumSqrd * edgeLen2 || outside )
	{
		return 1;
	}
	hkSimdReal frac = dots.getSimdAt(0) / ( dots.getSimdAt(0) + dots.getSimdAt(1) );
	out.m_pointOnA.setInterpolate4( pA1, pA0, frac );
	out.m_AminusB.setSub4( out.m_pointOnA, pB );
	return 0;
}

__forceinline int hkGskManifold_convertPointFace( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA     = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertB0 = work.getVertexB( feature.m_vert[1] );
	const hkVector4& vertB1 = work.getVertexB( feature.m_vert[2] );
	const hkVector4& vertB2 = work.getVertexB( feature.m_vert[3] );
	out.m_pointOnA = pA;
	out.m_AminusB.setSub4( pA, vertB0 );
	hkVector4 edge0; edge0.setSub4( vertB2, vertB1 );
	hkVector4 edge1; edge1.setSub4( vertB0, vertB2 );
	hkVector4 edge2; edge2.setSub4( vertB1, vertB0 );
	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();
	hkVector4 pt0; pt0.setSub4( pA, vertB1 );
	hkVector4 pt1; pt1.setSub4( pA, vertB2 );
	hkVector4 pt2; pt2.setSub4( pA, vertB0 );
	hkVector4 a0; a0.setCross( pt0, edge0 );
	hkVector4 a1; a1.setCross( pt1, edge1 );
	hkVector4 a2; a2.setCross( pt2, edge2 );
	hkVector4 dots;
	hkVector4Util::dot3_1vs4( normal, a0, a1, a2, work.m_masterNormal, dots );
	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return ( mask & hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
}

__forceinline int hkGskManifold_convertFacePoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& vertA2 = work.getVertexA( feature.m_vert[2] );
	const hkVector4& pB     = work.getVertexB( feature.m_vert[3] );
	out.m_pointOnA = pB;
	out.m_AminusB.setSub4( vertA0, pB );
	hkVector4 edge0; edge0.setSub4( vertA2, vertA1 );
	hkVector4 edge1; edge1.setSub4( vertA0, vertA2 );
	hkVector4 edge2; edge2.setSub4( vertA1, vertA0 );
	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();
	hkVector4 pt0; pt0.setSub4( pB, vertA1 );
	hkVector4 pt1; pt1.setSub4( pB, vertA2 );
	hkVector4 pt2; pt2.setSub4( pB, vertA0 );
	hkVector4 a0; a0.setCross( pt0, edge0 );
	hkVector4 a1; a1.setCross( pt1, edge1 );
	hkVector4 a2; a2.setCross( pt2, edge2 );
	hkVector4 dots;
	hkVector4Util::dot3_1vs4( normal, a0, a1, a2, work.m_masterNormal, dots );
	hkReal dist = out.m_AminusB.dot3( normal );
	out.m_pointOnA.setAddMul4( pB, normal, dist );
	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return ( mask & hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
}

__forceinline int hkGskManifold_convertEdgeEdge( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& vertB0 = work.getVertexB( feature.m_vert[2] );
	const hkVector4& vertB1 = work.getVertexB( feature.m_vert[3] );
	hkVector4 edgeA; edgeA.setSub4( vertA1, vertA0 );
	hkVector4 edgeB; edgeB.setSub4( vertB1, vertB0 );
	hkVector4 diff0; diff0.setSub4( vertA0, vertB0 );
	hkVector4 diff1; diff1.setSub4( vertA1, vertB1 );
	hkVector4 normal; normal.setCross( edgeA, edgeB );
	hkVector4 ortA; ortA.setCross( edgeA, normal );
	hkVector4 ortB; ortB.setCross( edgeB, normal );
	out.m_normal = work.m_masterNormal;
	hkVector4 dots;
	hkVector4Util::dot3_2vs2( diff0, diff1, ortB, ortA, dots );
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask != hkVector4Comparison::MASK_XY && mask != hkVector4Comparison::MASK_ZW )
	{
		return 1;
	}
	hkSimdReal dA0 = dots.getSimdAt(0);
	hkSimdReal dA2 = dots.getSimdAt(2);
	hkSimdReal fracA = dA0 / ( dA0 - dA2 );
	out.m_pointOnA.setInterpolate4( vertA0, vertA1, fracA );
	hkSimdReal dB1 = dots.getSimdAt(1);
	hkSimdReal dB3 = dots.getSimdAt(3);
	hkSimdReal fracB = dB1 / ( dB1 - dB3 );
	hkVector4 pointOnB; pointOnB.setInterpolate4( vertB0, vertB1, fracB );
	out.m_AminusB.setSub4( out.m_pointOnA, pointOnB );
	return 0;
}

__forceinline int hkGskManifold_convertFeature( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	switch ( feature.m_dimA * 4 + feature.m_dimB )
	{
		case 0:		return 1;
		case 1*4+1:	return hkGskManifold_convertPointPoint( work, feature, out );
		case 1*4+2:	return hkGskManifold_convertPointEdge( work, feature, out );
		case 1*4+3:	return hkGskManifold_convertPointFace( work, feature, out );
		case 2*4+1:	return hkGskManifold_convertEdgePoint( work, feature, out );
		case 2*4+2:	return hkGskManifold_convertEdgeEdge( work, feature, out );
		case 3*4+1:	return hkGskManifold_convertFacePoint( work, feature, out );
		default:	return 1;
	}
}

__forceinline void hkGskManifold_moveVertexIds( const hkpGskManifold& manifold, const void* srcIn, void* dstIn )
{
	hkUint32* dst = reinterpret_cast<hkUint32*>( dstIn );
	const hkUint32* src = reinterpret_cast<const hkUint32*>( srcIn );
	int numVertexIds = manifold.m_numVertsA + manifold.m_numVertsB;
	for ( int i = ( numVertexIds - 1 ) >> 1; i >= 0; i-- )
	{
		*(dst++) = *(src++);
	}
}

// pdb: hk4dGskCollideCalcToi | hkpContinuousGsk.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: hkGskManifold_verifyAndGetPoints)
// pdb params: in3, allowedPenetrationDepth, minSeparation, toiSeparation, gskCache, separatingNormal, out
void FUN_00a38200( hkpGskManifold& manifold, const hkpGskManifoldWork& work, int firstPointIndex, hkpProcessCollisionOutput& processOut, hkpContactMgr* contactMgr )
{
	unsigned int oldNumVertices = manifold.m_numContactPoints;
	unsigned int numPoints = oldNumVertices;
	for ( unsigned int i = firstPointIndex; i < numPoints; i++ )
	{
		hkpProcessCdPoint* point = processOut.m_firstFreeContactPoint;
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[i];
		hkGskManifoldConvertOut convertOut;
		int convertFeatureResult = hkGskManifold_convertFeature( work, feature, convertOut );
		if ( convertFeatureResult == 0 )
		{
			const hkVector4& normal = convertOut.m_normal;
			hkReal dist = normal.dot3( convertOut.m_AminusB );
			hkReal radiusSum = work.m_radiusA + work.m_radiusB;
			const hkReal distA = work.m_radiusB - dist;
			dist -= radiusSum;
			if ( dist < work.m_keepContact )
			{
				point->m_contact.getPosition().setAddMul4( convertOut.m_pointOnA, normal, distA );
				point->m_contact.setSeparatingNormal( normal );
				point->m_contact.setDistance( dist );
				point->m_contactPointId = feature.m_id;
				processOut.commitContactPoints( 1 );
				continue;
			}
		}
		if ( feature.m_id != (0xffff) )
		{
			contactMgr->removeContactPoint( feature.m_id, *processOut.m_constraintOwner );
		}
		numPoints--;
		feature = manifold.m_contactPoints[numPoints];
		i--;
	}
	if ( oldNumVertices > numPoints )
	{
		manifold.m_numContactPoints = hkUchar(numPoints);
		hkGskManifold_moveVertexIds( manifold, &manifold.m_contactPoints[oldNumVertices], &manifold.m_contactPoints[numPoints] );
		hkGskManifold_garbageCollect( manifold );
	}
}

} // namespace f3m_00a38200
}   // namespace f3m_00a38200

// @f3 0x00a3d0e0 (community match, verified in this file)
namespace f3m_00a3d0e0 {
// FUN_00a3d0e0 = Havok 5.5.0 hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper (hkpInternal.lib,
// hkpBoxBoxCollisionDetection.obj; the stock release object is byte-exact against the game).
// RECONSTRUCTED (the .cpp is not shipped) from the library objects' debug records: the target from the hybrid
// object's lines 796-810 and locals; addPoint (515-619), contactPointFromFeaturePointCache (495-511), the three
// per-feature contact helpers (442-450, 465-474, 483-490), edgeEdgeValidationDataFromFeatureId (477-480),
// getAxisMapFromFeatureBitSet (205-219) and isValidEdgeEdge (1321-1421, game 0x00a3cc40) from their own
// release / debug_multithreaded / hybrid copies; class layouts from the pdb; SDK inline bodies verbatim.
// Reduced with hktrim.py, SDK inline bodies it emptied added back.
namespace f3m_00a3d0e0 {
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

// HK_ENDIAN_BIG: the SDK's byte-order switch (hkBaseTypes.h; 0 on this x86 build)
enum { HK_ENDIAN_BIG = 0 };

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

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

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
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

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkMatrix3;
class hkRotation;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal normalizeWithLength3();
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
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkRotation& getRotation() const;
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

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::normalizeWithLength3()
	{
		hkReal len = this->length3();
		this->mul4( (1.0f)/len );
		return len;
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

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkVector4& getPosition();
		inline const hkVector4& getNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setDistance( hkReal d );
	protected:
		                class MustEndWithSemiColon;
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

inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}

class hkpFeatureContactPoint
{
	public:
		                class MustEndWithSemiColon;
	hkUint8 m_featureIdA;
	hkUint8 m_featureIdB;
	hkContactPointId	m_contactPointId;
};

class hkpCdBody;

class hkpBoxBoxManifold
{
	public:
		                class MustEndWithSemiColon;
		int addPoint( const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpFeatureContactPoint& fcp );
		void removePoint( int index );
		inline int getNumPoints();
		inline hkpFeatureContactPoint& operator[]( int index );
		inline hkBool findInManifold( const hkpFeatureContactPoint& fcp );
		inline hkBool hasNoPointsLeft();
	public:
		hkpFeatureContactPoint m_contactPoints[8];
		hkUchar  m_faceVertexFeatureCount;
		hkUchar  m_numPoints;
		hkBool m_isComplete;
		hkBool m_manifoldNormalInitialized;
		hkUint32 m_manifoldNormalB;
		hkVector4 m_manifoldNormalA;
};

inline int hkpBoxBoxManifold::getNumPoints()
{
	return m_numPoints;
}

inline hkpFeatureContactPoint& hkpBoxBoxManifold::operator[]( int index )
{
	return m_contactPoints[index];
}

inline hkBool hkpBoxBoxManifold::findInManifold( const hkpFeatureContactPoint& fcp )
{
	for (int i = m_numPoints-1; i>=0; i--)
	{
		if ( m_contactPoints[i].m_featureIdA == fcp.m_featureIdA && m_contactPoints[i].m_featureIdB == fcp.m_featureIdB )
		{
			return true;
		}
	}
	return false;
}

inline hkBool hkpBoxBoxManifold::hasNoPointsLeft()
{
	return (m_numPoints >= 8);
}

struct hkpProcessCdPoint
{
	                class MustEndWithSemiColon;
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
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

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
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

	enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpAgentEntry;
class hkpConstraintOwner;

struct hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
		inline hkpProcessCdPoint& getContactPoint( int i );
		inline hkpProcessCdPoint* getEnd();
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

inline hkpProcessCdPoint* hkpProcessCollisionData::getEnd()
{
	return m_firstFreeContactPoint;
}

inline hkpProcessCdPoint& hkpProcessCollisionData::getContactPoint( int i )
{
	return m_contactPoints[i];
}

struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
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

struct hkpProcessCollisionInput;
class hkpCollidable;

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

class hkpBoxBoxCollisionDetection
{
	public:
		                class MustEndWithSemiColon;
		enum hkpBoxBoxFeature
		{
			HK_BOXBOX_FACE_A_X = 0, HK_BOXBOX_FACE_A_Y = 1, HK_BOXBOX_FACE_A_Z = 2,
			HK_BOXBOX_FACE_B_X = 4, HK_BOXBOX_FACE_B_Y = 5, HK_BOXBOX_FACE_B_Z = 6,
			HK_BOXBOX_EDGE_0_0 = 8, HK_BOXBOX_EDGE_0_1 = 9, HK_BOXBOX_EDGE_0_2 = 10,
			HK_BOXBOX_EDGE_1_0 = 12, HK_BOXBOX_EDGE_1_1 = 13, HK_BOXBOX_EDGE_1_2 = 14,
			HK_BOXBOX_EDGE_2_0 = 16, HK_BOXBOX_EDGE_2_1 = 17, HK_BOXBOX_EDGE_2_2 = 18,
			HK_BOXBOX_FEATURE_COUNT = 19
		};
		class hkpFeaturePointCache
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_vA;
				hkVector4 m_vB;
				hkVector4 m_nA;
				hkReal m_normalSign;
				hkReal m_distance;
				int m_featureIndexA;
				int m_featureIndexB;
		};
	protected:
		void FUN_00a3d0e0( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkReal closestPointDist ) const;
		__forceinline hkResult addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const;
		__forceinline void contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const;
		hkBool isValidEdgeEdge( hkpFeaturePointCache& fpp ) const;
	public:
		const hkpCdBody& m_bodyA;
		const hkpCdBody& m_bodyB;
		const hkpProcessCollisionInput* m_env;
		hkpContactMgr* m_contactMgr;
		hkpProcessCollisionOutput* m_result;
		const hkTransform& m_wTa;
		const hkTransform& m_wTb;
		hkTransform m_aTb;
		hkVector4 m_radiusA;
		hkVector4 m_radiusB;
		hkVector4 m_tolerance4;
		hkVector4 m_keepRadiusA;
		hkVector4 m_keepRadiusB;
		const hkReal m_tolerance;
		const hkReal m_boundaryTolerance;
		hkVector4 m_dinA;
		hkVector4 m_dinB;
		mutable hkVector4 m_sepDist[5];
		static const hkReal m_edgeEndpointTolerance;
};

const hkReal hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance = 1.192092896e-07F;

__declspec(align(16)) static const hkReal vertexSignArray[8][4] =
{
	{  1.0f,  1.0f,  1.0f, 0.0f },
	{  1.0f,  1.0f, -1.0f, 0.0f },
	{  1.0f, -1.0f,  1.0f, 0.0f },
	{  1.0f, -1.0f, -1.0f, 0.0f },
	{ -1.0f,  1.0f,  1.0f, 0.0f },
	{ -1.0f,  1.0f, -1.0f, 0.0f },
	{ -1.0f, -1.0f,  1.0f, 0.0f },
	{ -1.0f, -1.0f, -1.0f, 0.0f }
};

static __forceinline const hkVector4& getAxisMapFromFeatureBitSet( hkUint16 bitSet )
{
	int offset;
	if ( HK_ENDIAN_BIG )
	{
		offset = bitSet & 0x70;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( vertexSignArray ), offset );
	}
	else
	{
		offset = ( bitSet & 0xe0 ) >> 1;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( vertexSignArray ), offset );
	}
}

hkBool hkpBoxBoxCollisionDetection::isValidEdgeEdge( hkpFeaturePointCache& fpp ) const
{
	const int axisDimA = fpp.m_featureIndexA & 0xf;
	const hkVector4& signsA = getAxisMapFromFeatureBitSet( fpp.m_featureIndexA );
	hkVector4 vertexA_inA; vertexA_inA.setMul4( signsA, m_radiusA );
	const int axisDimB = fpp.m_featureIndexB & 0xf;
	const hkVector4& signsB = getAxisMapFromFeatureBitSet( fpp.m_featureIndexB );
	hkVector4 d12;
	hkVector4 edgeB_inA;
	{
		hkVector4 vertexB_inA; vertexB_inA.setMul4( signsB, m_radiusB );
		edgeB_inA.setMul4( m_radiusB( axisDimB ) * 2.0f, m_aTb.getRotation().getColumn( axisDimB ) );
		vertexB_inA._setTransformedPos( m_aTb, vertexB_inA );
		d12.setSub4( vertexB_inA, vertexA_inA );
	}
	hkVector4 normal_inA;
	{
		const hkReal d1_at_DimA = m_radiusA( axisDimA ) * -2.0f;
		const hkReal R = d1_at_DimA * edgeB_inA( axisDimA );
		const hkReal D1 = d1_at_DimA * d1_at_DimA;
		const hkReal D2 = m_radiusB( axisDimB ) * m_radiusB( axisDimB ) * 4.0f;
		const hkReal S1 = d1_at_DimA * d12( axisDimA );
		const hkReal S2 = edgeB_inA.dot3( d12 );
		const hkReal denom = hkMath::fabs( D1 * D2 - R * R );
		hkReal t = S1 * D2 - S2 * R;
		if ( t <= m_edgeEndpointTolerance * denom || t >= ( 1.0f - m_edgeEndpointTolerance ) * denom )
		{
			return false;
		}
		t /= denom;
		const hkReal u = t * R - S2;
		if ( u <= m_edgeEndpointTolerance * D2 || u >= ( 1.0f - m_edgeEndpointTolerance ) * D2 )
		{
			return false;
		}
		vertexA_inA( axisDimA ) += d1_at_DimA * t;
		hkVector4 edgeA_inA; edgeA_inA.setZero4();
		edgeA_inA( axisDimA ) = d1_at_DimA * 0.5f;
		normal_inA.setCross( edgeA_inA, edgeB_inA );
	}
	{
		const hkReal normalLen = normal_inA.normalizeWithLength3();
		if ( normalLen < m_boundaryTolerance )
		{
			return false;
		}
	}
	{
		const hkReal check = normal_inA.dot3( signsA );
		if ( check < 0.0f )
		{
			normal_inA.setNeg4( normal_inA );
		}
		const hkReal depthOut = normal_inA.dot3( d12 );
		if ( depthOut > m_tolerance )
		{
			return false;
		}
		fpp.m_vA = vertexA_inA;
		fpp.m_nA.setNeg4( normal_inA );
		fpp.m_distance = depthOut;
		return true;
	}
}

void hkpBoxBoxCollisionDetection::faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTb, fpp.m_vB );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTa.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA - 4;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTb.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal()._setRotatedDir( m_wTa.getRotation(), fpp.m_nA );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const
{
	fpp.m_featureIndexA = fcp.m_featureIdA;
	fpp.m_featureIndexB = fcp.m_featureIdB;
}

void hkpBoxBoxCollisionDetection::contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndexA = fpp.m_featureIndexA;
	if ( featureIndexA <= HK_BOXBOX_FACE_A_Z )
	{
		faceAVertexBContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else if ( featureIndexA <= HK_BOXBOX_FACE_B_Z )
	{
		faceBVertexAContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else
	{
		edgeEdgeContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
}

hkResult hkpBoxBoxCollisionDetection::addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const
{
	if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
	{
		hkVector4 vCandidate;
		if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_A_Z )
		{
			vCandidate._setTransformedPos( m_wTb, fpp.m_vB );
		}
		else
		{
			vCandidate._setTransformedPos( m_wTa, fpp.m_vA );
		}
		for ( int i = 0; i < manifold.getNumPoints(); i++ )
		{
			if ( manifold.m_contactPoints[i].m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				hkVector4 diff; diff.setSub4( vCandidate, m_result->getContactPoint( i ).m_contact.getPosition() );
				const hkReal distSquared = diff.lengthSquared3();
				if ( distSquared <= hkReal( m_tolerance * m_tolerance + 1.192092896e-07F ) )
				{
					return HK_FAILURE;
				}
			}
		}
	}
	if ( manifold.hasNoPointsLeft() )
	{
		return HK_FAILURE;
	}
	int fcpIndex = manifold.addPoint( m_bodyA, m_bodyB, fcp );
	if ( fcpIndex >= 0 )
	{
		hkpProcessCdPoint* ccp = m_result->getEnd();
		contactPointFromFeaturePointCache( *ccp, fcp, fpp );
		if ( manifold.getNumPoints() > 1 )
		{
				hkpProcessCdPoint* lastPoint = m_result->getEnd() - 1;
			if ( lastPoint->m_contact.getNormal().dot3( ccp->m_contact.getNormal() ) <= 0.0f )
			{
				manifold.removePoint( fcpIndex );
				return HK_FAILURE;
			}
		}
		manifold[fcpIndex].m_contactPointId = m_contactMgr->addContactPoint( m_bodyA, m_bodyB, *m_env, *m_result, 0, ccp->m_contact );
		if ( manifold.m_contactPoints[fcpIndex].m_contactPointId == (0xffff) )
		{
			manifold.removePoint( fcpIndex );
		}
		else
		{
			m_result->commitContactPoints( 1 );
			fcp.m_contactPointId = manifold.m_contactPoints[fcpIndex].m_contactPointId;
			ccp->m_contactPointId = manifold.m_contactPoints[fcpIndex].m_contactPointId;
			if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				manifold.m_faceVertexFeatureCount++;
			}
		}
	}
	return HK_SUCCESS;
}

// pdb: hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun, medium
// pdb params: manifold, fcp, closestPointDist
void hkpBoxBoxCollisionDetection::FUN_00a3d0e0( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkReal closestPointDist ) const
{
	if ( !manifold.findInManifold( fcp ) )
	{
		hkpFeaturePointCache fpp;
		edgeEdgeValidationDataFromFeatureId( fpp, fcp );
		if ( isValidEdgeEdge( fpp ) )
		{
			if ( fpp.m_distance >= closestPointDist * 0.999f )
			{
				addPoint( manifold, fpp, fcp );
			}
		}
	}
}
} // namespace f3m_00a3d0e0
}   // namespace f3m_00a3d0e0

// @f3 0x00a3d5d0 (community match, verified in this file)
namespace f3m_00a3d5d0 {
// hkpBoxBoxCollisionDetection_tryToAddPointOnEdge = Havok 5.5.0 hkpBoxBoxCollisionDetection::tryToAddPointOnEdge (hkpInternal.lib,
// hkpBoxBoxCollisionDetection.obj; the game bytes equal the stock release object, tools\hknear.py).
// RECONSTRUCTED (the .cpp is not shipped) from the library objects' debug records: the target from the hybrid
// object's lines 816-871 and locals; setEdgeFeatureBitSetFromAxisMap (232-245) from its release /
// debug_multithreaded copies. Built on my matched 0x00a3d0e0 file (work\a3d0e0\w2\cand_final.cpp), whose
// FUN_00a3d0e0 is here again under its own name addAdditionalEdgeHelper with its helpers; class layouts from the
// pdb; SDK inline bodies verbatim. New parts reduced with hktrim.py.
namespace f3m_00a3d5d0 {
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

// HK_ENDIAN_BIG: the SDK's byte-order switch (hkBaseTypes.h; 0 on this x86 build)
enum { HK_ENDIAN_BIG = 0 };

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

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

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
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

namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
}

class hkMatrix3;
class hkRotation;
class hkTransform;

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
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal normalizeWithLength3();
		__forceinline hkVector4Comparison compareLessThanZero4() const;
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
		__forceinline const hkReal& operator() (int row, int column) const;
		__forceinline const hkRotation& getRotation() const;
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

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
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

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::normalizeWithLength3()
	{
		hkReal len = this->length3();
		this->mul4( (1.0f)/len );
		return len;
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

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkVector4& getPosition();
		inline const hkVector4& getNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline void setDistance( hkReal d );
	protected:
		                class MustEndWithSemiColon;
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

inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}

class hkpFeatureContactPoint
{
	public:
		                class MustEndWithSemiColon;
	hkpFeatureContactPoint()
	{
		m_contactPointId = 0;
	}
	hkUint8 m_featureIdA;
	hkUint8 m_featureIdB;
	hkContactPointId	m_contactPointId;
};

class hkpCdBody;

class hkpBoxBoxManifold
{
	public:
		                class MustEndWithSemiColon;
		int addPoint( const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpFeatureContactPoint& fcp );
		void removePoint( int index );
		inline int getNumPoints();
		inline hkpFeatureContactPoint& operator[]( int index );
		inline hkBool findInManifold( const hkpFeatureContactPoint& fcp );
		inline hkBool hasNoPointsLeft();
	public:
		hkpFeatureContactPoint m_contactPoints[8];
		hkUchar  m_faceVertexFeatureCount;
		hkUchar  m_numPoints;
		hkBool m_isComplete;
		hkBool m_manifoldNormalInitialized;
		hkUint32 m_manifoldNormalB;
		hkVector4 m_manifoldNormalA;
};

inline int hkpBoxBoxManifold::getNumPoints()
{
	return m_numPoints;
}

inline hkpFeatureContactPoint& hkpBoxBoxManifold::operator[]( int index )
{
	return m_contactPoints[index];
}

inline hkBool hkpBoxBoxManifold::findInManifold( const hkpFeatureContactPoint& fcp )
{
	for (int i = m_numPoints-1; i>=0; i--)
	{
		if ( m_contactPoints[i].m_featureIdA == fcp.m_featureIdA && m_contactPoints[i].m_featureIdB == fcp.m_featureIdB )
		{
			return true;
		}
	}
	return false;
}

inline hkBool hkpBoxBoxManifold::hasNoPointsLeft()
{
	return (m_numPoints >= 8);
}

struct hkpProcessCdPoint
{
	                class MustEndWithSemiColon;
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
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

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
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

	enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpAgentEntry;
class hkpConstraintOwner;

struct hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
		inline hkpProcessCdPoint& getContactPoint( int i );
		inline hkpProcessCdPoint* getEnd();
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

inline hkpProcessCdPoint* hkpProcessCollisionData::getEnd()
{
	return m_firstFreeContactPoint;
}

inline hkpProcessCdPoint& hkpProcessCollisionData::getContactPoint( int i )
{
	return m_contactPoints[i];
}

struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
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

struct hkpProcessCollisionInput;
class hkpCollidable;

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

class hkpBoxBoxCollisionDetection
{
	public:
		                class MustEndWithSemiColon;
		enum hkpBoxBoxFeature
		{
			HK_BOXBOX_FACE_A_X = 0, HK_BOXBOX_FACE_A_Y = 1, HK_BOXBOX_FACE_A_Z = 2,
			HK_BOXBOX_FACE_B_X = 4, HK_BOXBOX_FACE_B_Y = 5, HK_BOXBOX_FACE_B_Z = 6,
			HK_BOXBOX_EDGE_0_0 = 8, HK_BOXBOX_EDGE_0_1 = 9, HK_BOXBOX_EDGE_0_2 = 10,
			HK_BOXBOX_EDGE_1_0 = 12, HK_BOXBOX_EDGE_1_1 = 13, HK_BOXBOX_EDGE_1_2 = 14,
			HK_BOXBOX_EDGE_2_0 = 16, HK_BOXBOX_EDGE_2_1 = 17, HK_BOXBOX_EDGE_2_2 = 18,
			HK_BOXBOX_FEATURE_COUNT = 19
		};
		class hkpFeaturePointCache
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_vA;
				hkVector4 m_vB;
				hkVector4 m_nA;
				hkReal m_normalSign;
				hkReal m_distance;
				int m_featureIndexA;
				int m_featureIndexB;
		};
	protected:
		void hkpBoxBoxCollisionDetection_tryToAddPointOnEdge( hkpBoxBoxManifold& manifold, int edgeA, int edgeB, int nextVertA, int nextVertB, const hkVector4& normalA, const hkVector4& normalB, hkReal closestPointDist ) const;
		void addAdditionalEdgeHelper( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkReal closestPointDist ) const;
		__forceinline hkResult addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const;
		__forceinline void contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const;
		hkBool isValidEdgeEdge( hkpFeaturePointCache& fpp ) const;
	public:
		const hkpCdBody& m_bodyA;
		const hkpCdBody& m_bodyB;
		const hkpProcessCollisionInput* m_env;
		hkpContactMgr* m_contactMgr;
		hkpProcessCollisionOutput* m_result;
		const hkTransform& m_wTa;
		const hkTransform& m_wTb;
		hkTransform m_aTb;
		hkVector4 m_radiusA;
		hkVector4 m_radiusB;
		hkVector4 m_tolerance4;
		hkVector4 m_keepRadiusA;
		hkVector4 m_keepRadiusB;
		const hkReal m_tolerance;
		const hkReal m_boundaryTolerance;
		hkVector4 m_dinA;
		hkVector4 m_dinB;
		mutable hkVector4 m_sepDist[5];
		static const hkReal m_edgeEndpointTolerance;
};

const hkReal hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance = 1.192092896e-07F;

__declspec(align(16)) static const hkReal vertexSignArray[8][4] =
{
	{  1.0f,  1.0f,  1.0f, 0.0f },
	{  1.0f,  1.0f, -1.0f, 0.0f },
	{  1.0f, -1.0f,  1.0f, 0.0f },
	{  1.0f, -1.0f, -1.0f, 0.0f },
	{ -1.0f,  1.0f,  1.0f, 0.0f },
	{ -1.0f,  1.0f, -1.0f, 0.0f },
	{ -1.0f, -1.0f,  1.0f, 0.0f },
	{ -1.0f, -1.0f, -1.0f, 0.0f }
};

static __forceinline const hkVector4& getAxisMapFromFeatureBitSet( hkUint16 bitSet )
{
	int offset;
	if ( HK_ENDIAN_BIG )
	{
		offset = bitSet & 0x70;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( vertexSignArray ), offset );
	}
	else
	{
		offset = ( bitSet & 0xe0 ) >> 1;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( vertexSignArray ), offset );
	}
}

hkBool hkpBoxBoxCollisionDetection::isValidEdgeEdge( hkpFeaturePointCache& fpp ) const
{
	const int axisDimA = fpp.m_featureIndexA & 0xf;
	const hkVector4& signsA = getAxisMapFromFeatureBitSet( fpp.m_featureIndexA );
	hkVector4 vertexA_inA; vertexA_inA.setMul4( signsA, m_radiusA );
	const int axisDimB = fpp.m_featureIndexB & 0xf;
	const hkVector4& signsB = getAxisMapFromFeatureBitSet( fpp.m_featureIndexB );
	hkVector4 d12;
	hkVector4 edgeB_inA;
	{
		hkVector4 vertexB_inA; vertexB_inA.setMul4( signsB, m_radiusB );
		edgeB_inA.setMul4( m_radiusB( axisDimB ) * 2.0f, m_aTb.getRotation().getColumn( axisDimB ) );
		vertexB_inA._setTransformedPos( m_aTb, vertexB_inA );
		d12.setSub4( vertexB_inA, vertexA_inA );
	}
	hkVector4 normal_inA;
	{
		const hkReal d1_at_DimA = m_radiusA( axisDimA ) * -2.0f;
		const hkReal R = d1_at_DimA * edgeB_inA( axisDimA );
		const hkReal D1 = d1_at_DimA * d1_at_DimA;
		const hkReal D2 = m_radiusB( axisDimB ) * m_radiusB( axisDimB ) * 4.0f;
		const hkReal S1 = d1_at_DimA * d12( axisDimA );
		const hkReal S2 = edgeB_inA.dot3( d12 );
		const hkReal denom = hkMath::fabs( D1 * D2 - R * R );
		hkReal t = S1 * D2 - S2 * R;
		if ( t <= m_edgeEndpointTolerance * denom || t >= ( 1.0f - m_edgeEndpointTolerance ) * denom )
		{
			return false;
		}
		t /= denom;
		const hkReal u = t * R - S2;
		if ( u <= m_edgeEndpointTolerance * D2 || u >= ( 1.0f - m_edgeEndpointTolerance ) * D2 )
		{
			return false;
		}
		vertexA_inA( axisDimA ) += d1_at_DimA * t;
		hkVector4 edgeA_inA; edgeA_inA.setZero4();
		edgeA_inA( axisDimA ) = d1_at_DimA * 0.5f;
		normal_inA.setCross( edgeA_inA, edgeB_inA );
	}
	{
		const hkReal normalLen = normal_inA.normalizeWithLength3();
		if ( normalLen < m_boundaryTolerance )
		{
			return false;
		}
	}
	{
		const hkReal check = normal_inA.dot3( signsA );
		if ( check < 0.0f )
		{
			normal_inA.setNeg4( normal_inA );
		}
		const hkReal depthOut = normal_inA.dot3( d12 );
		if ( depthOut > m_tolerance )
		{
			return false;
		}
		fpp.m_vA = vertexA_inA;
		fpp.m_nA.setNeg4( normal_inA );
		fpp.m_distance = depthOut;
		return true;
	}
}

void hkpBoxBoxCollisionDetection::faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTb, fpp.m_vB );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTa.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA - 4;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTb.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal()._setRotatedDir( m_wTa.getRotation(), fpp.m_nA );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const
{
	fpp.m_featureIndexA = fcp.m_featureIdA;
	fpp.m_featureIndexB = fcp.m_featureIdB;
}

void hkpBoxBoxCollisionDetection::contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndexA = fpp.m_featureIndexA;
	if ( featureIndexA <= HK_BOXBOX_FACE_A_Z )
	{
		faceAVertexBContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else if ( featureIndexA <= HK_BOXBOX_FACE_B_Z )
	{
		faceBVertexAContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else
	{
		edgeEdgeContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
}

hkResult hkpBoxBoxCollisionDetection::addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const
{
	if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
	{
		hkVector4 vCandidate;
		if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_A_Z )
		{
			vCandidate._setTransformedPos( m_wTb, fpp.m_vB );
		}
		else
		{
			vCandidate._setTransformedPos( m_wTa, fpp.m_vA );
		}
		for ( int i = 0; i < manifold.getNumPoints(); i++ )
		{
			if ( manifold.m_contactPoints[i].m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				hkVector4 diff; diff.setSub4( vCandidate, m_result->getContactPoint( i ).m_contact.getPosition() );
				const hkReal distSquared = diff.lengthSquared3();
				if ( distSquared <= hkReal( m_tolerance * m_tolerance + 1.192092896e-07F ) )
				{
					return HK_FAILURE;
				}
			}
		}
	}
	if ( manifold.hasNoPointsLeft() )
	{
		return HK_FAILURE;
	}
	int fcpIndex = manifold.addPoint( m_bodyA, m_bodyB, fcp );
	if ( fcpIndex >= 0 )
	{
		hkpProcessCdPoint* ccp = m_result->getEnd();
		contactPointFromFeaturePointCache( *ccp, fcp, fpp );
		if ( manifold.getNumPoints() > 1 )
		{
				hkpProcessCdPoint* lastPoint = m_result->getEnd() - 1;
			if ( lastPoint->m_contact.getNormal().dot3( ccp->m_contact.getNormal() ) <= 0.0f )
			{
				manifold.removePoint( fcpIndex );
				return HK_FAILURE;
			}
		}
		manifold[fcpIndex].m_contactPointId = m_contactMgr->addContactPoint( m_bodyA, m_bodyB, *m_env, *m_result, 0, ccp->m_contact );
		if ( manifold.m_contactPoints[fcpIndex].m_contactPointId == (0xffff) )
		{
			manifold.removePoint( fcpIndex );
		}
		else
		{
			m_result->commitContactPoints( 1 );
			fcp.m_contactPointId = manifold.m_contactPoints[fcpIndex].m_contactPointId;
			ccp->m_contactPointId = manifold.m_contactPoints[fcpIndex].m_contactPointId;
			if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				manifold.m_faceVertexFeatureCount++;
			}
		}
	}
	return HK_SUCCESS;
}

void hkpBoxBoxCollisionDetection::addAdditionalEdgeHelper( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkReal closestPointDist ) const
{
	if ( !manifold.findInManifold( fcp ) )
	{
		hkpFeaturePointCache fpp;
		edgeEdgeValidationDataFromFeatureId( fpp, fcp );
		if ( isValidEdgeEdge( fpp ) )
		{
			if ( fpp.m_distance >= closestPointDist * 0.999f )
			{
				addPoint( manifold, fpp, fcp );
			}
		}
	}
}
static __forceinline void setEdgeFeatureBitSetFromAxisMap( const hkVector4& axisMapAp, const hkVector4& axisMapBp, int featureIndexA, int featureIndexB, hkpFeatureContactPoint& fcp )
{
	hkVector4 axisMapA = axisMapAp;
	hkVector4 axisMapB = axisMapBp;
	axisMapA( featureIndexA ) = 1.0f;
	axisMapB( featureIndexB ) = 1.0f;
	const int maskA = axisMapA.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ );
	const int maskB = axisMapB.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
	fcp.m_featureIdA = hkUint8( featureIndexA | 0x10 | ( maskA << 4 ) );
	fcp.m_featureIdB = hkUint8( ( maskB << 4 ) + featureIndexB );
}

// pdb: hkpBoxBoxCollisionDetection::tryToAddPointOnEdge | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void hkpBoxBoxCollisionDetection::hkpBoxBoxCollisionDetection_tryToAddPointOnEdge( hkpBoxBoxManifold& manifold, int edgeA, int edgeB, int nextVertA, int nextVertB, const hkVector4& normalA, const hkVector4& normalB, hkReal closestPointDist ) const
{
	int HK_VECTOR3_X_SHIFT;
	int HK_VECTOR3_Y_SHIFT;
	int HK_VECTOR3_Z_SHIFT;
	if ( HK_ENDIAN_BIG )
	{
		HK_VECTOR3_X_SHIFT = 0;
		HK_VECTOR3_Y_SHIFT = 1;
		HK_VECTOR3_Z_SHIFT = 2;
	}
	else
	{
		HK_VECTOR3_X_SHIFT = 3;
		HK_VECTOR3_Y_SHIFT = 2;
		HK_VECTOR3_Z_SHIFT = 1;
	}
	hkpFeatureContactPoint fcp;
	setEdgeFeatureBitSetFromAxisMap( normalA, normalB, edgeA, edgeB, fcp );
	addAdditionalEdgeHelper( manifold, fcp, closestPointDist );
	int shiftWidth;
	if ( nextVertA == 0 )
		shiftWidth = HK_VECTOR3_X_SHIFT;
	else if ( nextVertA == 1 )
	{
		shiftWidth = HK_VECTOR3_Y_SHIFT;
	}
	else
		shiftWidth = HK_VECTOR3_Z_SHIFT;
	const int signFlipA = 1 << ( shiftWidth + 4 );
	if ( nextVertB == 0 )
		shiftWidth = HK_VECTOR3_X_SHIFT;
	else if ( nextVertB == 1 )
	{
		shiftWidth = HK_VECTOR3_Y_SHIFT;
	}
	else
		shiftWidth = HK_VECTOR3_Z_SHIFT;
	const int signFlipB = 1 << ( shiftWidth + 4 );
	fcp.m_featureIdA ^= signFlipA;
	addAdditionalEdgeHelper( manifold, fcp, closestPointDist );
	fcp.m_featureIdB ^= signFlipB;
	addAdditionalEdgeHelper( manifold, fcp, closestPointDist );
	fcp.m_featureIdA ^= signFlipA;
	addAdditionalEdgeHelper( manifold, fcp, closestPointDist );
}
} // namespace f3m_00a3d5d0
}   // namespace f3m_00a3d5d0

// @f3 0x00a2b910 (community match, verified in this file)
// FUN_00a2b910 = Havok 5.5.0 hkAgent1nMachine_Process (hkpInternal.lib, hkpAgent1nMachineProcess.obj) as the game
// links it: the game's Havok build passes the memory class to hkThreadMemory::onRowEmpty / onRowFull (FUN_008f6800,
// FUN_008f6890), which the SDK library's hkThreadMemory does not; nothing else differs. Written from the SDK's debug
// records (release and hybrid line records, locals, blocks; hkpAgent1nMachineProcess.cpp is not shipped) on the SDK
// headers, matched against the library object with tools\hkcheck.py, cut with tools\hktrim.py. See note.txt.
namespace f3m_00a2b910 {
typedef float hkReal;
typedef signed char hkChar;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
			typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
	return hkUlong(pntr) - hkUlong(base);
}
__forceinline int __cdecl hkGetByteOffsetInt( const void* base, const void* pntr)
{
	return static_cast<int>( hkGetByteOffset( base, pntr ) );
}
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
		__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
		__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
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
		static __forceinline int __cdecl constSizeToRow( int size );
	protected:
		enum { BATCH_SIZE=4 };
		void* onRowEmpty(int row, HK_MEMORY_CLASS cl);
		void onRowFull(int row, void* p, HK_MEMORY_CLASS cl);
	public:
		hkMemory* m_memory;
		int m_referenceCount;
		Stack m_stack;
		int m_stackSize;
		int m_maxNumElemsOnFreeList;
		struct FreeList
		{
			enum { MAX_FREELIST=0x0fffffff };
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
		__forceinline T& operator[] (int i);
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		__forceinline void reserve(int n);
		__forceinline void setSize(int size);
		__forceinline T* expandAt( int index, int numToInsert );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline iterator begin();
		static void __cdecl copyBackwards(T* dst, const T* src, int n);
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
__forceinline T& hkArray<T>::operator[] (int i)
{
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
__forceinline void __cdecl hkArray<T>::copyBackwards(T* dst, const T* src, int n)
{
	for(int i = n-1; i >= 0; --i)
	{
		dst[i] = src[i];
	}
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
__forceinline void hkArray<T>::setSize(int n)
{
	reserve(n);
	m_size = n;
}
template <typename T>
__forceinline T* hkArray<T>::expandAt(int index, int numtoinsert)
{
	const int newsize = numtoinsert + m_size;
	const int numtomove = m_size - index;
	if(newsize > getCapacity())
	{
		reserve(newsize);
	}
	copyBackwards(m_data + index + numtoinsert, m_data + index, numtomove);
	m_size = newsize;
	return m_data + index;
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
namespace hkMath
{
	inline void prefetch128( const void* ) { }
}
class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void setZero4();
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
		__forceinline void setNeg3(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
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
		                class MustEndWithSemiColon;
	public:
		hkVector4 m_vec;
};
class hkMatrix3
{
	public:
		                class MustEndWithSemiColon;
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
		void setInverse( const hkTransform &t );
		void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
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
inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& m0, const hkVector4& m1)
{
	x = a.x + m0.x * m1.x;
	y = a.y + m0.y * m1.y;
	z = a.z + m0.z * m1.z;
	w = a.w + m0.w * m1.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w );
}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
	hkReal r = (&v.x)[i];
	x = r;
	y = r;
	z = r;
	w = r;
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
	return m_centerOfMass1(3);
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
		static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
};
void __cdecl hkString::memCpy16NonEmpty( void* dst, const void* src, int numQuads)
{
	const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
	hkUint32* dst32 = reinterpret_cast< hkUint32*>(dst);
	{
		do
		{
			dst32[0] = src32[0];
			dst32[1] = src32[1];
			dst32[2] = src32[2];
			dst32[3] = src32[3];
			dst32+= 4;
			src32+= 4;
		}
		while ( --numQuads > 0 );
	}
}
int hkThreadMemory::constSizeToRow( int size )
{
	if (size <= 8 )	return 1;
	else if (size <= 16 )	return 2;
	else if (size <= 32 )	return 3;
	else if (size <= 48 )	return 4;
	else if (size <= 64 )	return 5;
	else if (size <= 96 )	return 6;
	else if (size <= 128 )	return 7;
	else if (size <= 160 )	return 8;
	else if (size <= 192 )	return 9;
	else if (size <= 256 )	return 10;
	else if (size <= 320 )	return 11;
	else if (size <= 512 )	return 12;
	else if (size <= 1024)	return 13;
	else if (size <= 2048)	return 14;
	else if (size <= 4096)	return 15;
	else if (size <= 8192)	return 16;
	else
	{
		return -1;
	}
}
void* hkThreadMemory::allocateChunkConstSize(int nbytes, HK_MEMORY_CLASS cl)
{
	int row = constSizeToRow(nbytes);
	if( void* p = m_free_list[row].get() )
	{
		return p;
	}
	return onRowEmpty(row, cl);
}
void hkThreadMemory::deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl)
{
	int row = constSizeToRow(nbytes);
	if ( m_free_list[row].m_numElem >= m_maxNumElemsOnFreeList )
	{
		onRowFull(row, p, cl);
	}
	else
	{
		m_free_list[row].put(p);
	}
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
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline hkVector4& getSeparatingNormal();
		inline void setFlipped( const hkContactPoint& point );
	protected:
		                class MustEndWithSemiColon;
		hkVector4 m_position;
		hkVector4 m_separatingNormal;
};
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
	return m_separatingNormal;
}
inline void hkContactPoint::setFlipped( const hkContactPoint& point )
{
	hkVector4 dist; dist.setBroadcast( point.m_separatingNormal, 3 );
	m_position.setAddMul4( point.m_position, point.m_separatingNormal, dist );
	m_separatingNormal.setNeg3( point.m_separatingNormal );
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
enum { HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 256 };
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
				                class MustEndWithSemiColon;
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
				                class MustEndWithSemiColon;
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
		        __forceinline void* __cdecl operator new(hk_size_t n, void* p){ return p; } class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		__forceinline hkpCdBody( ){}
		friend class hkpCollidable;
		__forceinline const hkpShape* getShape() const;
		__forceinline hkpShapeKey getShapeKey() const ;
		__forceinline const hkpCdBody* getParent() const;
	public:
		explicit __forceinline hkpCdBody( const hkpCdBody* parent );
		__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
		__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
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
const hkpCdBody* hkpCdBody::getParent() const
{
	return m_parent;
}
hkpCdBody::hkpCdBody( const hkpCdBody* parent )
{
	m_parent = parent;
	m_motion = parent->m_motion;
}
hkpCdBody::hkpCdBody( const hkpCdBody* parent, const hkTransform* t )
{
	m_parent = parent;
	m_motion = t;
}
hkpShapeKey hkpCdBody::getShapeKey() const
{
	return m_shapeKey;
}
void hkpCdBody::setShape( const hkpShape* shape, hkpShapeKey key )
{
	m_shape = shape;
	m_shapeKey = key;
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
	hkUchar m_streamCommand;
	hkUchar m_agentType;
	hkUchar m_numContactPoints;
	hkUchar m_size;
};
typedef void hkpAgentData;
struct hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<const hkpCdBody*> m_bodyA;
	hkPadSpu<const hkpCdBody*> m_bodyB;
	hkPadSpu<const hkpProcessCollisionInput*> m_input;
	hkPadSpu<hkpContactMgr*>	m_contactMgr;
	hkTransform m_aTb;
};
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
	                class MustEndWithSemiColon;
	hkPadSpu<hkReal> m_distAtT1;
	hkPadSpu<int> m_offsetPpuSectorMinusSpuSector;
	hkVector4 m_linearTimInfo;
};
namespace hkAgent3
{
	typedef int AgentType;
	enum {
		MIN_TOTAL_SIZE = 16,
		MAX_MEMORY_INCREASE = 80,
		MAX_INITIAL_SIZE = MAX_MEMORY_INCREASE + MIN_TOTAL_SIZE
	};
	enum StreamCommand
	{
		STREAM_NULL = 0,
		STREAM_END = 1,
		STREAM_CALL = 2,
		STREAM_CALL_FLIPPED = 3,
		STREAM_CALL_WITH_TIM = 4,
		STREAM_CALL_WITH_TIM_FLIPPED = 5,
		STREAM_CALL_AGENT = 6,
	};
	typedef hkpAgentData* (__cdecl* CreateFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData );
	typedef void (__cdecl* DestroyFunc)( hkpAgentEntry* entry, hkpAgentData* agentData, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher );
	typedef hkpAgentData* (__cdecl* ProcessFunc)( const hkpAgent3ProcessInput& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4* separatingNormalOut, hkpProcessCollisionOutput& result);
	enum Symmetric
	{
		IS_SYMMETRIC,
		IS_NOT_SYMMETRIC,
		IS_NOT_SYMMETRIC_AND_FLIPPED
	};
	typedef void (__cdecl* SepNormalFunc)( const hkpAgent3Input& input, hkpAgentEntry* entry, hkpAgentData* agentData, hkVector4& separatingNormalOut );
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
			HK_MAX_SHAPE_TYPE = 32,
			HK_MAX_AGENT2_TYPES = 64,
			HK_MAX_AGENT3_TYPES = 16,
			HK_MAX_COLLISION_QUALITIES = 8
		};
	public:
		                class MustEndWithSemiColon;
		typedef hkpCollisionAgent* (__cdecl *CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const hkpCollisionInput& env, hkpContactMgr* mgr);
		typedef void (__cdecl *GetPenetrationsFunc) (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdBodyPairCollector& collector );
		typedef void (__cdecl *GetClosestPointsFunc) (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& output );
		typedef void (__cdecl *LinearCastFunc) (const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector );
		typedef CreateFunc CollisionAgentCreationFunction;
		typedef hkChar CollisionQualityIndex;
		struct AgentFuncs
		{
			                class MustEndWithSemiColon;
			CreateFunc m_createFunc;
			GetPenetrationsFunc m_getPenetrationsFunc;
			GetClosestPointsFunc m_getClosestPointFunc;
			LinearCastFunc m_linearCastFunc;
			hkBool m_isFlipped;
			hkBool m_isPredictive;
		};
		struct Agent3Funcs
		{
			                class MustEndWithSemiColon;
			__declspec(align(16)) hkAgent3::CreateFunc m_createFunc;
			hkAgent3::DestroyFunc m_destroyFunc;
			hkAgent3::CleanupFunc m_cleanupFunc;
			hkAgent3::RemovePointFunc m_removePointFunc;
			hkAgent3::CommitPotentialFunc m_commitPotentialFunc;
			hkAgent3::CreateZombieFunc m_createZombieFunc;
			hkAgent3::UpdateFilterFunc m_updateFilterFunc;
			hkAgent3::CalcStatisticsFunc m_calcStatisticsFunc;
			hkAgent3::InvalidateTimFunc m_invalidateTimFunc;
			hkAgent3::WarpTimeFunc m_warpTimeFunc;
			hkAgent3::SepNormalFunc m_sepNormalFunc;
			hkAgent3::ProcessFunc m_processFunc;
			hkBool m_isPredictive;
			hkBool m_ignoreSymmetricVersion;
			hkBool m_reusePreviousEntry;
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
		__forceinline hkAgent3::AgentType getAgent3Type( hkpShapeType typeA, hkpShapeType typeB, hkBool32 predicitve ) const;
		__forceinline hkAgent3::CreateFunc getAgent3CreateFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::DestroyFunc getAgent3DestroyFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::CleanupFunc getAgent3CleanupFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::ProcessFunc getAgent3ProcessFunc ( hkAgent3::AgentType type );
		__forceinline hkAgent3::SepNormalFunc getAgent3SepNormalFunc( hkAgent3::AgentType type );
		__forceinline hkAgent3::Symmetric getAgent3Symmetric( hkAgent3::AgentType type );
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
			AgentFuncs m_createFunc;
		};
		struct Agent3Entry
		{
			                class MustEndWithSemiColon;
			hkpShapeType m_typeA;
			hkpShapeType m_typeB;
			hkBool m_checkEnabled;
			Agent3Funcs m_funcs;
		};
		struct Agent3FuncsIntern: public Agent3Funcs
		{
			                class MustEndWithSemiColon;
			hkAgent3::Symmetric m_symmetric;
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
		int m_numAgent2Types;
		__declspec(align(16)) hkUchar m_agent2Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		hkUchar m_agent2TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		AgentFuncs m_agent2Func [ HK_MAX_AGENT2_TYPES ];
		int m_numAgent3Types;
		__declspec(align(16)) hkUchar m_agent3Types [HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		__declspec(align(16)) hkUchar m_agent3TypesPred[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
		Agent3FuncsIntern m_agent3Func [ HK_MAX_AGENT3_TYPES ];
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
hkAgent3::CreateFunc hkpCollisionDispatcher::getAgent3CreateFunc ( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_createFunc;
}
hkAgent3::DestroyFunc hkpCollisionDispatcher::getAgent3DestroyFunc ( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_destroyFunc;
}
hkAgent3::CleanupFunc hkpCollisionDispatcher::getAgent3CleanupFunc ( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_cleanupFunc;
}
hkAgent3::ProcessFunc hkpCollisionDispatcher::getAgent3ProcessFunc ( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_processFunc;
}
hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_sepNormalFunc;
}
hkAgent3::Symmetric hkpCollisionDispatcher::getAgent3Symmetric( hkAgent3::AgentType type )
{
	return m_agent3Func[type ].m_symmetric;
}
hkAgent3::AgentType hkpCollisionDispatcher::getAgent3Type( hkpShapeType typeA, hkpShapeType typeB, hkBool32 predictive ) const
{
	if ( predictive )
	{
		return m_agent3TypesPred[typeA] [ typeB ];
	}
	return m_agent3Types[typeA] [ typeB ];
}
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
		enum FlagEnum
		{
			CONTACT_IS_NEW_AND_POTENTIAL = 1,
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
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpCdPointCollector& collector ) = 0;
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
	protected:
		hkpContactMgr* m_contactMgr;
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
namespace hkSweptTransformUtil
{
		void __cdecl lerp2( const hkSweptTransform& sweptTrans, hkTime time, hkTransform& transformOut );
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
	timOut.setMul4( f0, diff0 );
	timOut.addMul4( f1, diff1 );
	timOut(3) = f0 * ms0.m_deltaAngle(3) * ms0.m_objectRadius + f1 * ms1.m_deltaAngle(3) * ms1.m_objectRadius;
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
		__forceinline void __cdecl setEnd(char* ptr) { m_end = ptr; }
	public:
		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		hkBool m_isBufferAllocatedOnTheHeap;
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
		};
		struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
		{
			                class MustEndWithSemiColon;
			const char* m_nameOfFirstSplit;
		};
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
	public:
		inline void flip();
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
		hkpProcessCdPoint m_contactPoints[HK_MAX_CONTACT_POINT];
		struct ToiInfo
		{
			public:
				                class MustEndWithSemiColon;
				inline void flip();
			public:
				hkContactPoint m_contactPoint;
				hkPadSpu<hkReal> m_time;
				hkPadSpu<hkReal> m_seperatingVelocity;
				hkGskCache16 m_gskCache;
				hkContactPointPropertiesWithExtendedUserData16 m_properties;
		};
		struct ToiInfo m_toi;
};
void hkpProcessCollisionData::ToiInfo::flip()
{
	hkVector4& norm = m_contactPoint.getSeparatingNormal();
	norm.setNeg3( norm );
	m_gskCache.flip();
}
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
	public:
		struct ContactRef
		{
			                class MustEndWithSemiColon;
			hkpProcessCdPoint*	m_contactPoint;
			hkpAgentEntry* m_agentEntry;
			void* m_agentData;
		};
		struct PotentialInfo
		{
			                class MustEndWithSemiColon;
			void reset()
			{
				m_firstFreePotentialContact = &m_potentialContacts[0];
				m_firstFreeRepresentativeContact = &m_representativeContacts[0];
			}
			ContactRef* m_firstFreePotentialContact;
			hkpProcessCdPoint** m_firstFreeRepresentativeContact;
			hkpProcessCdPoint* m_representativeContacts[ HK_MAX_CONTACT_POINT ];
			ContactRef m_potentialContacts[ HK_MAX_CONTACT_POINT ];
		};
	public:
		hkPadSpu<PotentialInfo*> m_potentialContacts;
};
class hkpBvTreeShape;
class hkpShapeCollectionFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB ) const = 0;
		virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB ) const = 0;
		virtual int numShapeKeyHitsLimitBreached( const hkpCollisionInput& input,
															const hkpCdBody& bodyA, const hkpCdBody& bodyB,
															const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
															hkpShapeKey* shapeKeysInOut,
															int shapeKeysCapacity) const = 0;
		virtual ~hkpShapeCollectionFilter() { }
};
class hkpShapeContainer
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum { HK_SHAPE_BUFFER_ALIGNMENT = 16,	HK_SHAPE_BUFFER_SIZE = 512 };
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
struct hkpAgent1nTrack;
class hkShapeKeyPair
{
public:
	                class MustEndWithSemiColon;
	hkpShapeKey m_shapeKeyA;
	hkpShapeKey m_shapeKeyB;
};
struct hkpAgent1nMachineEntry: hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkShapeKeyPair m_shapeKeyPair;
};
struct hkpAgent1nMachinePaddedEntry: hkpAgent1nMachineEntry
{
	                class MustEndWithSemiColon;
	hkUint32 m_padUpTo16Bytes;
};
struct hkpAgent1nMachineTimEntry: hkpAgent1nMachineEntry
{
	                class MustEndWithSemiColon;
	hkTime m_timeOfSeparatingNormal;
	hkVector4 m_separatingNormal;
};
extern "C"
{
	void __cdecl hkAgent1nMachine_Weld( hkpAgent3Input& input, const hkpShapeContainer* shapeCollection, hkpProcessCollisionOutput& output );
}
struct hkpAgent1nSector
{
	static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpAgent1nSector), HK_MEMORY_CLASS_AGENT); } class MustEndWithSemiColon;
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
		return reinterpret_cast<hkpAgentData*>( &m_data[m_bytesAllocated] );
	}
	int getCapacity()
	{
		return NET_SECTOR_SIZE;
	}
	inline hkpAgent1nSector(): m_bytesAllocated(0){}
};
struct hkpAgent1nTrack
{
	                class MustEndWithSemiColon;
	hkArray<hkpAgent1nSector*> m_sectors;
};
struct hkAgent1nMachineBodyTemp
{
	hkpCdBody m_bodyA;
	hkpCdBody m_bodyB;
	hkTransform m_transA;
	hkTransform m_transB;
};
class hkShapeKeyPairLocal1n
{
	public:
		hkPadSpu<hkpShapeKey> m_shapeKeyB;
		__forceinline bool operator==( const hkShapeKeyPair& p )
		{
			return m_shapeKeyB == p.m_shapeKeyB;
		}
		__forceinline bool operator>( const hkShapeKeyPair& p )
		{
			return m_shapeKeyB > p.m_shapeKeyB;
		}
		__forceinline void writeTo( hkShapeKeyPair& p )
		{
			p.m_shapeKeyA = 0xffffffff;
			p.m_shapeKeyB = m_shapeKeyB;
		}
};
static void hkAgent1nMachine_initInputAtTime( hkpAgent3Input& in, hkAgent1nMachineBodyTemp& temp, hkpAgent3Input& out )
{
	hkSweptTransformUtil::lerp2( in.m_bodyA->getMotionState()->getSweptTransform(), in.m_input->m_stepInfo.m_startTime, temp.m_transA );
	hkSweptTransformUtil::lerp2( in.m_bodyB->getMotionState()->getSweptTransform(), in.m_input->m_stepInfo.m_startTime, temp.m_transB );
	out.m_bodyA = &temp.m_bodyA;
	out.m_bodyB = &temp.m_bodyB;
	out.m_contactMgr = in.m_contactMgr;
	out.m_input = in.m_input;
	temp.m_bodyA.setShape( in.m_bodyA->getShape(), in.m_bodyA->getShapeKey() );
	new (&temp.m_bodyA) hkpCdBody( in.m_bodyA, &temp.m_transA );
	new (&temp.m_bodyB) hkpCdBody( in.m_bodyB, &temp.m_transB );
	out.m_aTb.setMulInverseMul( temp.m_transA, temp.m_transB );
}
static void hkAgent1nMachine_flipInput( hkpAgent3ProcessInput& in, hkpAgent3ProcessInput& out )
{
	out.m_bodyA = in.m_bodyB;
	out.m_bodyB = in.m_bodyA;
	out.m_input = in.m_input;
	out.m_offsetPpuSectorMinusSpuSector = in.m_offsetPpuSectorMinusSpuSector;
	out.m_contactMgr = in.m_contactMgr;
	out.m_linearTimInfo.setNeg3( in.m_linearTimInfo );
	out.m_aTb.setInverse( in.m_aTb );
}
static inline void extractChildShapes( hkpShapeKey shapeKey, const hkpShapeContainer* shapeContainerB, hkpShapeContainer::ShapeBuffer& shapeBufferB, hkpCdBody& modifiedBodyB )
{
	const hkpShape* childShape = shapeContainerB->getChildShape( shapeKey, shapeBufferB );
	modifiedBodyB.setShape( childShape, shapeKey );
}
void __cdecl FUN_00a2b910( hkpAgent1nTrack& agentTrack, hkpAgent1nTrack* agentTrackOnPpu, const hkpAgent3ProcessInput& inputIn, const hkpShapeContainer* shapeContainerB, const hkpShapeKey* newKeys, hkpProcessCollisionOutput& output )
{
	hkMath::prefetch128( agentTrack.m_sectors.begin() );
	hkpProcessCollisionOutput::PotentialInfo* oldPotentialInfo = output.m_potentialContacts;
	hkpProcessCollisionOutput::PotentialInfo potentialContacts;
	if ( !oldPotentialInfo && shapeContainerB->isWeldingEnabled() )
	{
		potentialContacts.reset();
		output.m_potentialContacts = &potentialContacts;
	}
	else
	{
		output.m_potentialContacts = 0;
	}
	hkpAgent3ProcessInput input;
	hkString::memCpy16NonEmpty( &input, &inputIn, sizeof( hkpAgent3ProcessInput ) >> 4 );
	hkpCollisionDispatcher* dispatcher = input.m_input->m_dispatcher;
	hkpCdBody modifiedBodyB( input.m_bodyB );
	input.m_bodyB = &modifiedBodyB;
	int numTim = 0;
	hkpAgent1nSector* readSector = agentTrack.m_sectors[0];
	hkpAgent1nSector* currentSector = new hkpAgent1nSector;
	int currentSectorIndex = 0;
	bool prevInputInitialized = false;
	bool prevFlippedInputInitialized = false;
	hkpAgent3Input prevInput;
	hkpAgent3Input prevFlippedInput;
	hkAgent1nMachineBodyTemp prevTemp;
	hkAgent1nMachineBodyTemp prevFlippedTemp;
	hkpShapeContainer::ShapeBuffer shapeBufferB;
	int nextReadSectorIndex = 1;
	void* readData = readSector->getBegin();
	void* readEnd = readSector->getEnd();
	void* currentData = currentSector->getBegin();
	while ( 1 )
	{
		hkShapeKeyPairLocal1n shapeKeyPair;
		if ( !newKeys )
		{
			hkpAgent1nMachineEntry* entry = reinterpret_cast<hkpAgent1nMachineEntry*>( readData );
			int entrySize = entry->m_size;
			hkString::memCpy16NonEmpty( currentData, readData, entrySize >> 4 );
			readData = hkAddByteOffset( readData, entrySize );
			shapeKeyPair.m_shapeKeyB = entry->m_shapeKeyPair.m_shapeKeyB;
		}
		else
		{
			hkpAgent1nMachineEntry* readHeader = reinterpret_cast<hkpAgent1nMachineEntry*>( readData );
			shapeKeyPair.m_shapeKeyB = *newKeys;
			if ( shapeKeyPair == readHeader->m_shapeKeyPair )
			{
				int size = readHeader->m_size;
				hkString::memCpy16NonEmpty( currentData, readData, size >> 4 );
				readData = hkAddByteOffset( readData, size );
				newKeys++;
			}
			else if ( shapeKeyPair > readHeader->m_shapeKeyPair )
			{
				void* agentData = ( ( readHeader->m_streamCommand & 0xe ) == hkAgent3::STREAM_CALL_WITH_TIM ) ? reinterpret_cast<void*>( static_cast<hkpAgent1nMachineTimEntry*>( readHeader ) + 1 ) : reinterpret_cast<void*>( static_cast<hkpAgent1nMachinePaddedEntry*>( readHeader ) + 1 );
				readData = hkAddByteOffset( readData, readHeader->m_size );
				dispatcher->getAgent3DestroyFunc( readHeader->m_agentType )( readHeader, agentData, input.m_contactMgr, *output.m_constraintOwner.val(), dispatcher );
				goto checkReadSector;
			}
			else
			{
				if ( input.m_input->m_filter->isCollisionEnabled( *input.m_input, *inputIn.m_bodyA, *inputIn.m_bodyB, *shapeContainerB, shapeKeyPair.m_shapeKeyB ) )
				{
					extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
					const hkpShape* shapeB = modifiedBodyB.getShape();
					hkpAgent1nMachineEntry* h = reinterpret_cast<hkpAgent1nMachineEntry*>( currentData );
					shapeKeyPair.writeTo( h->m_shapeKeyPair );
					h->m_agentType = hkUchar( dispatcher->getAgent3Type( input.m_bodyA->getShape()->getType(), shapeB->getType(), input.m_input->m_createPredictiveAgents ) );
					h->m_numContactPoints = 0;
					hkpAgent3ProcessInput flippedInput;
					hkpAgent3ProcessInput* in = &input;
					int isFlipped = 0;
					if ( dispatcher->getAgent3Symmetric( h->m_agentType ) == hkAgent3::IS_NOT_SYMMETRIC_AND_FLIPPED )
					{
						isFlipped = 1;
						in = &flippedInput;
						hkAgent1nMachine_flipInput( input, flippedInput );
					}
					if ( dispatcher->getAgent3SepNormalFunc( h->m_agentType ) )
					{
						hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
						entry->m_streamCommand = hkUchar( hkAgent3::STREAM_CALL_WITH_TIM + isFlipped );
						entry->m_timeOfSeparatingNormal = hkTime( -1.0f );
						entry->m_separatingNormal.setZero4();
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						void* agentEnd = dispatcher->getAgent3CreateFunc( entry->m_agentType )( *in, entry, agentData );
						hkUlong size = hkGetByteOffset( entry, agentEnd );
						entry->m_size = hkUchar( size );
					}
					else
					{
						hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
						entry->m_streamCommand = hkUchar( hkAgent3::STREAM_CALL + isFlipped );
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						void* agentEnd = dispatcher->getAgent3CreateFunc( entry->m_agentType )( *in, entry, agentData );
						hkUlong size = hkGetByteOffset( entry, agentEnd );
						entry->m_size = hkUchar( size );
					}
				}
				else
				{
					hkpAgent1nMachinePaddedEntry* h = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
					*reinterpret_cast<hkUint32*>( h ) = 0;
					shapeKeyPair.writeTo( h->m_shapeKeyPair );
					h->m_size = sizeof( hkpAgent1nMachinePaddedEntry );
				}
				newKeys++;
			}
		}
		{
			hkAgent3::StreamCommand command = hkAgent3::StreamCommand( reinterpret_cast<hkpAgentEntry*>( currentData )->m_streamCommand );
			switch ( command )
			{
				case hkAgent3::STREAM_CALL_AGENT:
					{
						hkpAgent1nMachinePaddedEntry* paddedEntry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
						void* agentData = reinterpret_cast<void*>( paddedEntry + 1 );
						extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
						hkpCollisionAgent* agent = *reinterpret_cast<hkpCollisionAgent**>( agentData );
						agent->processCollision( *input.m_bodyA, modifiedBodyB, *input.m_input, output );
						currentData = hkAddByteOffset( agentData, ( ( sizeof( hkpCollisionAgent* ) + ( 16 - 1 ) ) & ( ~( 16 - 1 ) ) ) );
						break;
					}
				case hkAgent3::STREAM_CALL:
					{
						hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
						extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( input, entry, agentData, 0, output );
						entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
						break;
					}
				case hkAgent3::STREAM_CALL_FLIPPED:
					{
						hkpAgent3ProcessInput flippedInput;
						hkAgent1nMachine_flipInput( input, flippedInput );
						hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
						extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
						hkReal oldToi = output.m_toi.m_time;
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						hkpProcessCdPoint* oldResultBegin = output.m_firstFreeContactPoint;
						currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( flippedInput, entry, agentData, 0, output );
						entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
						while ( oldResultBegin < output.m_firstFreeContactPoint )
						{
							oldResultBegin->m_contact.setFlipped( oldResultBegin->m_contact );
							oldResultBegin++;
						}
						if ( oldToi != output.m_toi.m_time )
						{
							output.m_toi.flip();
						}
						break;
					}
				case hkAgent3::STREAM_CALL_WITH_TIM_FLIPPED:
					{
						hkpAgent3ProcessInput flippedInput;
						hkAgent1nMachine_flipInput( input, flippedInput );
						hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
						hkReal distAtT1;
						if ( entry->m_timeOfSeparatingNormal != flippedInput.m_input->m_stepInfo.m_startTime )
						{
							const hkpCollisionQualityInfo& ci = *flippedInput.m_input->m_collisionQualityInfo;
							if ( !ci.m_useContinuousPhysics )
							{
								entry->m_timeOfSeparatingNormal = flippedInput.m_input->m_stepInfo.m_endTime;
								distAtT1 = ci.m_minSeparation * 0.5f;
								entry->m_separatingNormal.setZero4();
								entry->m_separatingNormal(3) = distAtT1;
								goto PROCESS_AT_T1_FLIPPED;
							}
							if ( !prevFlippedInputInitialized )
							{
								prevFlippedInputInitialized = true;
								hkAgent1nMachine_initInputAtTime( flippedInput, prevFlippedTemp, prevFlippedInput );
								prevFlippedTemp.m_bodyB.setShape( flippedInput.m_bodyB->getShape(), flippedInput.m_bodyB->m_shapeKey );
							}
							extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
							prevFlippedTemp.m_bodyA.setShape( modifiedBodyB.getShape(), shapeKeyPair.m_shapeKeyB );
							void* agentData = reinterpret_cast<void*>( entry + 1 );
							dispatcher->getAgent3SepNormalFunc( entry->m_agentType )( prevFlippedInput, entry, agentData, entry->m_separatingNormal );
						}
						entry->m_timeOfSeparatingNormal = flippedInput.m_input->m_stepInfo.m_endTime;
						{
							hkReal worstCaseDeltaDist = flippedInput.m_linearTimInfo.dot4xyz1( entry->m_separatingNormal );
							distAtT1 = entry->m_separatingNormal(3) - worstCaseDeltaDist;
						}
						if ( distAtT1 >= flippedInput.m_input->m_tolerance )
						{
							entry->m_separatingNormal(3) = distAtT1;
							if ( !entry->m_numContactPoints )
							{
								currentData = hkAddByteOffset( currentData, entry->m_size );
							}
							else
							{
								void* agentData = reinterpret_cast<void*>( entry + 1 );
								currentData = dispatcher->getAgent3CleanupFunc( entry->m_agentType )( entry, agentData, flippedInput.m_contactMgr, *output.m_constraintOwner.val() );
								entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
							}
							numTim++;
							break;
						}
PROCESS_AT_T1_FLIPPED:
						flippedInput.m_distAtT1 = distAtT1;
						extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
						hkpProcessCdPoint* oldResultBegin = output.m_firstFreeContactPoint;
						hkReal oldToi = output.m_toi.m_time;
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( flippedInput, entry, agentData, &entry->m_separatingNormal, output );
						entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
						while ( oldResultBegin < output.m_firstFreeContactPoint )
						{
							oldResultBegin->m_contact.setFlipped( oldResultBegin->m_contact );
							oldResultBegin++;
						}
						if ( oldToi != output.m_toi.m_time )
						{
							output.m_toi.flip();
						}
						break;
					}
				case hkAgent3::STREAM_CALL_WITH_TIM:
					{
						hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
						hkReal distAtT1;
						if ( entry->m_timeOfSeparatingNormal != input.m_input->m_stepInfo.m_startTime )
						{
							if ( entry->m_timeOfSeparatingNormal >= input.m_input->m_stepInfo.m_endTime )
							{
								hkReal backDt = entry->m_timeOfSeparatingNormal - input.m_input->m_stepInfo.m_endTime;
								hkVector4 backTim; hkSweptTransformUtil::calcTimInfo( *input.m_bodyA->getMotionState(), *input.m_bodyB->getMotionState(), backDt, backTim );
								hkReal backLinear = backTim.dot3( entry->m_separatingNormal );
								hkReal backAng = backTim(3);
								distAtT1 = entry->m_separatingNormal(3) + backLinear - backAng;
							}
							else
							{
								const hkpCollisionQualityInfo& ci = *input.m_input->m_collisionQualityInfo;
								if ( !ci.m_useContinuousPhysics )
								{
									entry->m_timeOfSeparatingNormal = input.m_input->m_stepInfo.m_endTime;
									distAtT1 = ci.m_minSeparation * 0.1f;
									entry->m_separatingNormal.setZero4();
									entry->m_separatingNormal(3) = distAtT1;
									goto PROCESS_AT_T1;
								}
								if ( !prevInputInitialized )
								{
									prevInputInitialized = true;
									hkAgent1nMachine_initInputAtTime( input, prevTemp, prevInput );
								}
								extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
								prevTemp.m_bodyB.setShape( modifiedBodyB.getShape(), shapeKeyPair.m_shapeKeyB );
								void* agentData = reinterpret_cast<void*>( entry + 1 );
								dispatcher->getAgent3SepNormalFunc( entry->m_agentType )( prevInput, entry, agentData, entry->m_separatingNormal );
							}
						}
						entry->m_timeOfSeparatingNormal = input.m_input->m_stepInfo.m_endTime;
						{
							hkReal worstCaseDeltaDist = input.m_linearTimInfo.dot4xyz1( entry->m_separatingNormal );
							distAtT1 = entry->m_separatingNormal(3) - worstCaseDeltaDist;
						}
						if ( distAtT1 >= input.m_input->m_tolerance )
						{
							entry->m_separatingNormal(3) = distAtT1;
							if ( !entry->m_numContactPoints )
							{
								currentData = hkAddByteOffset( currentData, entry->m_size );
							}
							else
							{
								void* agentData = reinterpret_cast<void*>( entry + 1 );
								currentData = dispatcher->getAgent3CleanupFunc( entry->m_agentType )( entry, agentData, input.m_contactMgr, *output.m_constraintOwner.val() );
								entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
							}
							numTim++;
							break;
						}
PROCESS_AT_T1:
						input.m_distAtT1 = distAtT1;
						extractChildShapes( shapeKeyPair.m_shapeKeyB, shapeContainerB, shapeBufferB, modifiedBodyB );
						void* agentData = reinterpret_cast<void*>( entry + 1 );
						currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( input, entry, agentData, &entry->m_separatingNormal, output );
						entry->m_size = hkUchar( hkGetByteOffsetInt( entry, currentData ) );
						break;
					}
				case hkAgent3::STREAM_NULL:
					{
						currentData = hkAddByteOffset( currentData, sizeof( hkpAgent1nMachinePaddedEntry ) );
						break;
					}
				case hkAgent3::STREAM_END:
					{
						currentData = hkAddByteOffset( currentData, sizeof( hkpAgent1nMachinePaddedEntry ) );
						break;
					}
				default:
					;
			}
		}
checkReadSector:
		;
		if ( readData == readEnd )
		{
			delete readSector;
			if ( nextReadSectorIndex < agentTrack.m_sectors.getSize() )
			{
				readSector = agentTrack.m_sectors[nextReadSectorIndex];
				readData = readSector->getBegin();
				readEnd = readSector->getEnd();
				nextReadSectorIndex++;
			}
			else
			{
				break;
			}
		}
		{
			int nextAgentSize = reinterpret_cast<hkpAgentEntry*>( readData )->m_size;
			int bytesUsed = hkGetByteOffsetInt( currentSector->getBegin(), currentData );
			if ( nextAgentSize + bytesUsed <= currentSector->getCapacity() - hkAgent3::MAX_MEMORY_INCREASE )
			{
				continue;
			}
			currentSector->m_bytesAllocated = bytesUsed;
		}
		if ( currentSectorIndex >= nextReadSectorIndex )
		{
			agentTrack.m_sectors.expandAt( nextReadSectorIndex, 1 );
			nextReadSectorIndex++;
		}
		agentTrack.m_sectors[currentSectorIndex] = currentSector;
		currentSectorIndex++;
		currentSector = new hkpAgent1nSector;
		currentData = currentSector->getBegin();
	}
	{
		int bytesUsed = hkGetByteOffsetInt( currentSector->getBegin(), currentData );
		currentSector->m_bytesAllocated = bytesUsed;
	}
	agentTrack.m_sectors.setSize( currentSectorIndex + 1 );
	agentTrack.m_sectors[currentSectorIndex] = currentSector;
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::AddValueCommand* h = reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "M" "i" "numTim"; h->m_value = float( numTim ); mStream.setEnd( (char*)(h+1) ); } };
	input.m_bodyB = modifiedBodyB.getParent();
	if ( output.m_potentialContacts )
	{
		if ( output.m_potentialContacts->m_firstFreePotentialContact > &output.m_potentialContacts->m_potentialContacts[0] )
		{
			hkAgent1nMachine_Weld( input, shapeContainerB, output );
		}
	}
	output.m_potentialContacts = oldPotentialInfo;
}
}

// @f3 0x00a36e30 (community match, verified in this file)
namespace f3m_00a36e30 {
// Havok 5.5.0, hkpInternal.lib, hkpGskManifoldUtil.obj.
// Reconstructed from the release and hybrid records of hkpGskManifoldUtil.cpp:
// conversion helpers (88-293), convertFeature (297-311), garbageCollect (313-369),
// downshiftVertices (377-393), and verifyAndGetPoints (441-493).
// Release header declarations and inline bodies come from the existing caller reconstruction.
// The private implementation file is absent from the SDK.
namespace f3m_00a36e30 {
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

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
}

class hkClass;
typedef int hkBool32;

class hkUFloat8
{
public:
	enum { MAX_VALUE = 256 };
public:
	hkUint8 m_value;
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
		hkBool32 anyIsSet( Mask m ) const { return m_mask & m; }
		int getMask() const { return m_mask; }
	private:
		int m_mask;
		friend class hkVector4;
};


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl sqrtInverse(hkReal r) { return 1.0f / hkMath::sqrt(r); }
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setZero4();
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline void setInterpolate4( const hkVector4& a, const hkVector4& b, hkSimdRealParameter t);
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal lengthInverse3() const;
		__forceinline void normalize3();
		__forceinline hkReal& operator() (int i);
		__forceinline const hkReal& operator() (int i) const;
		__forceinline hkSimdReal getSimdAt(int i) const;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
};

inline hkReal& hkVector4::operator() (int i)
{
	return (&x)[i];
}

inline const hkReal& hkVector4::operator() (int i) const
{
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

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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

class hkpCdBody;
class hkpCollidable;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
class hkpConstraintOwner;

struct hkpAgentEntry
{
	                class MustEndWithSemiColon;
	hkUchar     m_streamCommand;
	hkUchar     m_agentType;
	hkUchar     m_numContactPoints;
	hkUchar     m_size;
};

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

namespace hkVector4Util
{
	__forceinline void __cdecl dot3_3vs3( const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut);
	__forceinline void __cdecl dot3_2vs2( const hkVector4& a0, const hkVector4& a2, const hkVector4& b0, const hkVector4& b1, hkVector4& dotsOut);
}

inline void __cdecl hkVector4Util::dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1, const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( b0 );
	dotsOut(1) = a1.dot3( b1 );
	dotsOut(2) = a2.dot3( b2 );
	dotsOut(3) = 0;
}

inline void __cdecl hkVector4Util::dot3_1vs4( const hkVector4& vectorIn, const hkVector4& a0, const hkVector4& a1, const hkVector4& a2, const hkVector4& a3, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( vectorIn );
	dotsOut(1) = a1.dot3( vectorIn );
	dotsOut(2) = a2.dot3( vectorIn );
	dotsOut(3) = a3.dot3( vectorIn );
}

inline void __cdecl hkVector4Util::dot3_2vs2( const hkVector4& a0, const hkVector4& a2, const hkVector4& b0, const hkVector4& b1, hkVector4& dotsOut)
{
	dotsOut(0) = a0.dot3( b0 );
	dotsOut(1) = a0.dot3( b1 );
	dotsOut(2) = a2.dot3( b0 );
	dotsOut(3) = a2.dot3( b1 );
}

struct hkpGskManifold
{
	                class MustEndWithSemiColon;
	struct ContactPoint
	{
		                class MustEndWithSemiColon;
		hkUchar m_dimA;
		hkUchar m_dimB;
		hkContactPointId m_id;
		union
		{
			hkUchar m_vert[4];
			hkUint32 m_allVerts;
		};
	};
	typedef hkUint16 VertexId;
	enum { MAX_POINTS = 4 };
	enum { MAX_VERTICES = MAX_POINTS * 4  };
	__forceinline VertexId* getVertexIds();
	hkUchar  m_numVertsA;
	hkUchar  m_numVertsB;
	hkUchar  m_numContactPoints;
	ContactPoint m_contactPoints[ MAX_POINTS ];
	hkUchar m_padding[ MAX_VERTICES * sizeof(VertexId) ];
};

hkpGskManifold::VertexId* hkpGskManifold::getVertexIds()
{
	return (VertexId*)( &m_contactPoints[m_numContactPoints] );
}

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

struct hkpGskManifoldWork
{
	                class MustEndWithSemiColon;
	inline const hkVector4& getVertexA( hkUint32 offset ) const
	{
		return *hkAddByteOffsetConst( &m_vertices[0], offset );
	}
	inline const hkVector4& getVertexB( hkUint32 offset ) const
	{
		return *hkAddByteOffsetConst( &m_vertices[0], offset );
	}
	hkpCdVertex m_vertices[ hkpGskManifold::MAX_VERTICES ];
	hkVector4 m_masterNormal;
	hkPadSpu<hkReal> m_radiusA;
	hkPadSpu<hkReal> m_radiusB;
	hkPadSpu<hkReal> m_keepContact;
	hkPadSpu<hkReal> m_radiusSumSqrd;
};

struct hkGskManifoldConvertOut
{
	hkVector4 m_pointOnA;
	hkVector4 m_AminusB;
	hkVector4 m_normal;
};

static __forceinline int hkGskManifold_convertPointPoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pB = work.getVertexB( feature.m_vert[1] );
	hkVector4 diff; diff.setSub4( pA, pB );
	hkReal dist2 = diff.lengthSquared3();
	if ( dist2 > work.m_radiusSumSqrd )
	{
		return 1;
	}
	out.m_AminusB = diff;
	out.m_normal = work.m_masterNormal;
	out.m_pointOnA = pA;
	return 0;
}

static __forceinline int hkGskManifold_convertPointEdge( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA  = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pB0 = work.getVertexB( feature.m_vert[1] );
	const hkVector4& pB1 = work.getVertexB( feature.m_vert[2] );

	out.m_pointOnA = pA;
	out.m_normal = work.m_masterNormal;

	hkVector4 edge; edge.setSub4( pB1, pB0 );
	hkVector4 a; a.setSub4( pB1, pA );
	hkVector4 b; b.setSub4( pA, pB0 );
	hkVector4 cross; cross.setCross( edge, a );
	hkVector4 dots;
	hkVector4Util::dot3_3vs3( a, edge, b, edge, cross, cross, dots );
	hkReal edgeLen2 = edge.lengthSquared3();
	hkBool32 outside = dots.compareLessThanZero4().anyIsSet( hkVector4Comparison::MASK_XY );
	if ( dots(3) > work.m_radiusSumSqrd * edgeLen2 || outside )
	{
		return 1;
	}
	hkSimdReal frac = dots.getSimdAt(0) / ( dots.getSimdAt(0) + dots.getSimdAt(1) );
	hkVector4 pointOnB; pointOnB.setInterpolate4( pB0, pB1, frac );
	out.m_AminusB.setSub4( pA, pointOnB );
	return 0;
}

static __forceinline int hkGskManifold_convertEdgePoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& pA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& pB  = work.getVertexB( feature.m_vert[2] );

	out.m_normal = work.m_masterNormal;

	hkVector4 edge; edge.setSub4( pA1, pA0 );
	hkVector4 a; a.setSub4( pA1, pB );
	hkVector4 b; b.setSub4( pB, pA0 );
	hkVector4 cross; cross.setCross( edge, a );
	hkVector4 dots;
	hkVector4Util::dot3_3vs3( a, edge, b, edge, cross, cross, dots );
	hkReal edgeLen2 = edge.lengthSquared3();
	hkBool32 outside = dots.compareLessThanZero4().anyIsSet( hkVector4Comparison::MASK_XY );
	if ( dots(3) > work.m_radiusSumSqrd * edgeLen2 || outside )
	{
		return 1;
	}
	hkSimdReal frac = dots.getSimdAt(0) / ( dots.getSimdAt(0) + dots.getSimdAt(1) );
	out.m_pointOnA.setInterpolate4( pA1, pA0, frac );
	out.m_AminusB.setSub4( out.m_pointOnA, pB );
	return 0;
}

static __forceinline int hkGskManifold_convertPointFace( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& pA     = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertB0 = work.getVertexB( feature.m_vert[1] );
	const hkVector4& vertB1 = work.getVertexB( feature.m_vert[2] );
	const hkVector4& vertB2 = work.getVertexB( feature.m_vert[3] );

	out.m_pointOnA = pA;
	out.m_AminusB.setSub4( pA, vertB0 );

	hkVector4 edge0; edge0.setSub4( vertB2, vertB1 );
	hkVector4 edge1; edge1.setSub4( vertB0, vertB2 );
	hkVector4 edge2; edge2.setSub4( vertB1, vertB0 );

	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();

	hkVector4 pt0; pt0.setSub4( pA, vertB1 );
	hkVector4 pt1; pt1.setSub4( pA, vertB2 );
	hkVector4 pt2; pt2.setSub4( pA, vertB0 );

	hkVector4 a0; a0.setCross( pt0, edge0 );
	hkVector4 a1; a1.setCross( pt1, edge1 );
	hkVector4 a2; a2.setCross( pt2, edge2 );

	hkVector4 dots;
	hkVector4Util::dot3_1vs4( normal, a0, a1, a2, work.m_masterNormal, dots );

	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return ( mask & hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
}

static __forceinline int hkGskManifold_convertFacePoint( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& vertA2 = work.getVertexA( feature.m_vert[2] );
	const hkVector4& pB     = work.getVertexB( feature.m_vert[3] );

	out.m_pointOnA = pB;
	out.m_AminusB.setSub4( vertA0, pB );

	hkVector4 edge0; edge0.setSub4( vertA2, vertA1 );
	hkVector4 edge1; edge1.setSub4( vertA0, vertA2 );
	hkVector4 edge2; edge2.setSub4( vertA1, vertA0 );

	hkVector4 normal; normal.setCross( edge0, edge1 );
	normal.normalize3();

	hkVector4 pt0; pt0.setSub4( pB, vertA1 );
	hkVector4 pt1; pt1.setSub4( pB, vertA2 );
	hkVector4 pt2; pt2.setSub4( pB, vertA0 );

	hkVector4 a0; a0.setCross( pt0, edge0 );
	hkVector4 a1; a1.setCross( pt1, edge1 );
	hkVector4 a2; a2.setCross( pt2, edge2 );

	hkVector4 dots;
	hkVector4Util::dot3_1vs4( normal, a0, a1, a2, work.m_masterNormal, dots );

	hkReal dist = out.m_AminusB.dot3( normal );
	out.m_pointOnA.setAddMul4( pB, normal, dist );

	out.m_normal = normal;
	int mask = dots.compareLessThanZero4().getMask();
	if ( mask & hkVector4Comparison::MASK_W )
	{
		out.m_normal.setNeg4( normal );
	}
	return ( mask & hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
}

static __forceinline int hkGskManifold_convertEdgeEdge( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	const hkVector4& vertA0 = work.getVertexA( feature.m_vert[0] );
	const hkVector4& vertA1 = work.getVertexA( feature.m_vert[1] );
	const hkVector4& vertB0 = work.getVertexB( feature.m_vert[2] );
	const hkVector4& vertB1 = work.getVertexB( feature.m_vert[3] );

	hkVector4 edgeA; edgeA.setSub4( vertA1, vertA0 );
	hkVector4 edgeB; edgeB.setSub4( vertB1, vertB0 );
	hkVector4 diff0; diff0.setSub4( vertA0, vertB0 );
	hkVector4 diff1; diff1.setSub4( vertA1, vertB1 );

	hkVector4 normal; normal.setCross( edgeA, edgeB );
	hkVector4 ortA; ortA.setCross( edgeA, normal );
	hkVector4 ortB; ortB.setCross( edgeB, normal );

	out.m_normal = work.m_masterNormal;

	hkVector4 dots;
	hkVector4Util::dot3_2vs2( diff0, diff1, ortB, ortA, dots );

	int mask = dots.compareLessThanZero4().getMask();
	if ( mask != hkVector4Comparison::MASK_XY && mask != hkVector4Comparison::MASK_ZW )
	{
		return 1;
	}

	hkSimdReal dA0 = dots.getSimdAt(0);
	hkSimdReal fracA = dA0 / ( dA0 - dots.getSimdAt(2) );
	out.m_pointOnA.setInterpolate4( vertA0, vertA1, fracA );
	hkSimdReal dB1 = dots.getSimdAt(1);
	hkSimdReal fracB = dB1 / ( dB1 - dots.getSimdAt(3) );
	hkVector4 pointOnB; pointOnB.setInterpolate4( vertB0, vertB1, fracB );
	out.m_AminusB.setSub4( out.m_pointOnA, pointOnB );
	return 0;
}

static __forceinline int FUN_00a36e30( const hkpGskManifoldWork& work, const hkpGskManifold::ContactPoint& feature, hkGskManifoldConvertOut& out )
{
	switch ( feature.m_dimA * 4 + feature.m_dimB )
	{
		case 0:		return 1;
		case 1*4+1:	return hkGskManifold_convertPointPoint( work, feature, out );
		case 1*4+2:	return hkGskManifold_convertPointEdge( work, feature, out );
		case 1*4+3:	return hkGskManifold_convertPointFace( work, feature, out );
		case 2*4+1:	return hkGskManifold_convertEdgePoint( work, feature, out );
		case 2*4+2:	return hkGskManifold_convertEdgeEdge( work, feature, out );
		case 3*4+1:	return hkGskManifold_convertFacePoint( work, feature, out );
		default:	return 1;
	}
}

static void hkGskManifold_garbageCollect( hkpGskManifold& manifold )
{
	__declspec(align(16)) hkUchar verts[ hkpGskManifold::MAX_VERTICES ];
	reinterpret_cast<hkVector4*>( verts )->setZero4();
	for ( unsigned int cp = 0; cp < manifold.m_numContactPoints; cp++ )
	{
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[cp];
		int dim = feature.m_dimA + feature.m_dimB;
		verts[ feature.m_vert[0] >> 4 ] = 1;
		verts[ feature.m_vert[1] >> 4 ] = 1;
		if ( dim >= 3 ) { verts[ feature.m_vert[2] >> 4 ] = 1; }
		if ( dim == 4 ) { verts[ feature.m_vert[3] >> 4 ] = 1; }
	}
	hkPadSpu<hkUint32> oldToNewMap[ hkpGskManifold::MAX_VERTICES ];
	{
		hkpGskManifold::VertexId* vertexIds = manifold.getVertexIds();
		int numVerts = manifold.m_numVertsA + manifold.m_numVertsB;
		int s = 0;
		int d = 0;
		int d16 = 0;
		for ( ; s < numVerts; s++ )
		{
			oldToNewMap[s] = d16;
			if ( verts[s] )
			{
				vertexIds[d] = vertexIds[s];
				d++;
				d16 += sizeof(hkVector4);
			}
		}
		manifold.m_numVertsA = hkUchar( oldToNewMap[ manifold.m_numVertsA ] >> 4 );
		manifold.m_numVertsB = hkUchar( d - manifold.m_numVertsA );
	}
	for ( unsigned int i = 0; i < manifold.m_numContactPoints; i++ )
	{
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[i];
		feature.m_vert[0] = hkUchar( oldToNewMap[ feature.m_vert[0] >> 4 ] );
		feature.m_vert[1] = hkUchar( oldToNewMap[ feature.m_vert[1] >> 4 ] );
		feature.m_vert[2] = hkUchar( oldToNewMap[ feature.m_vert[2] >> 4 ] );
		feature.m_vert[3] = hkUchar( oldToNewMap[ feature.m_vert[3] >> 4 ] );
	}
}

// Reconstructed from hkpGskManifoldUtil.cpp, lines 377-393.
static __forceinline void hkGskManifold_downshiftVertices( hkpGskManifold& manifold, int oldNumContactPoints, int newNumContactPoints )
{
    hkUint32* dst = reinterpret_cast<hkUint32*>( &manifold.m_contactPoints[newNumContactPoints] );
    const hkUint32* src = reinterpret_cast<const hkUint32*>( &manifold.m_contactPoints[oldNumContactPoints] );
    int numVertexIds = manifold.m_numVertsA + manifold.m_numVertsB;
    for ( int i = ( numVertexIds - 1 ) >> 1; i >= 0; i-- )
    {
        *(dst++) = *(src++);
    }
}

extern "C" void hkGskManifold_verifyAndGetPoints( hkpGskManifold& manifold, const hkpGskManifoldWork& work, int firstPointIndex, hkpProcessCollisionOutput& processOut, hkpContactMgr* contactMgr )
{
	unsigned int oldNumVertices = manifold.m_numContactPoints;
	unsigned int numPoints = oldNumVertices;
	for ( unsigned int i = firstPointIndex; i < numPoints; i++ )
	{
		hkpProcessCdPoint* point = processOut.m_firstFreeContactPoint;
		hkpGskManifold::ContactPoint& feature = manifold.m_contactPoints[i];
		hkGskManifoldConvertOut convertOut;
		int convertFeatureResult = FUN_00a36e30( work, feature, convertOut );
		if ( convertFeatureResult == 0 )
		{
			const hkVector4& normal = convertOut.m_normal;
			hkReal dist = normal.dot3( convertOut.m_AminusB );
			hkReal radiusSum = work.m_radiusA + work.m_radiusB;
			const hkReal distA = work.m_radiusB - dist;
			dist -= radiusSum;
			if ( dist < work.m_keepContact )
			{
				point->m_contact.getPosition().setAddMul4( convertOut.m_pointOnA, normal, distA );
				point->m_contact.getSeparatingNormal() = normal;
				point->m_contact.setDistance( dist );
				point->m_contactPointId = feature.m_id;
				processOut.commitContactPoints( 1 );
				continue;
			}
		}
		if ( feature.m_id != (0xffff) )
		{
			contactMgr->removeContactPoint( feature.m_id, *processOut.m_constraintOwner.val() );
		}
		numPoints--;
		feature = manifold.m_contactPoints[numPoints];
		i--;
	}
	if ( oldNumVertices > numPoints )
	{
		manifold.m_numContactPoints = hkUchar(numPoints);
		hkGskManifold_downshiftVertices( manifold, oldNumVertices, numPoints );
		hkGskManifold_garbageCollect( manifold );
	}
}

} // namespace f3m_00a36e30
}   // namespace f3m_00a36e30

// @f3 0x00a2c5b0 (community match, verified in this file)
// FUN_00a2c5b0 = Havok 5.5.0 hkAgentNmMachine_Process (hkpInternal.lib, hkpAgent1nMachineProcess.obj), with its two
// file-static helpers hkAgent1nMachine_initInputAtTime and hkAgent1nMachine_flipInput. Written from the SDK headers
// and the library objects' debug records (the .cpp is not shipped); reduced from sdk.cpp with hktrim.py. See note.txt.
namespace f3m_00a2c5b0 {
typedef float  hkReal;
typedef signed char		hkChar;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
return hkUlong(pntr) - hkUlong(base);
}
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
__forceinline void* allocateChunkConstSize( int nbytes, HK_MEMORY_CLASS cl );
__forceinline void deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl );
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
static __forceinline int __cdecl constSizeToRow( int size );
protected:
enum { BATCH_SIZE=4 };
void* onRowEmpty(int row, HK_MEMORY_CLASS cl);
void onRowFull(int row, void* p, HK_MEMORY_CLASS cl);
public:
hkMemory* m_memory;
int m_referenceCount;
Stack m_stack;
int m_stackSize;
int m_maxNumElemsOnFreeList;
struct FreeList
{
enum { MAX_FREELIST=0x0fffffff };
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
__forceinline T& operator[] (int i);
__forceinline int getSize() const;
__forceinline int getCapacity() const;
__forceinline void reserve(int n);
__forceinline void setSize(int size);
__forceinline T* expandAt( int index, int numToInsert );
typedef T* iterator;
typedef const T* const_iterator;
__forceinline iterator begin();
static void __cdecl copyBackwards(T* dst, const T* src, int n);
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
__forceinline T& hkArray<T>::operator[] (int i)
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
__forceinline void __cdecl hkArray<T>::copyBackwards(T* dst, const T* src, int n)
{
for(int i = n-1; i >= 0; --i)
{
dst[i] = src[i];
}
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
__forceinline void hkArray<T>::setSize(int n)
{
reserve(n);
m_size = n;
}
template <typename T>
__forceinline T* hkArray<T>::expandAt(int index, int numtoinsert)
{
;
const int newsize = numtoinsert + m_size;
const int numtomove = m_size - index;
if(newsize > getCapacity())
{
reserve(newsize);
}
copyBackwards(m_data + index + numtoinsert, m_data + index, numtomove);
m_size = newsize;
return m_data + index;
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
namespace hkMath
{
inline void prefetch128( const void* ) { }
}
class hkVector4
{
public:
class MustEndWithSemiColon;
__forceinline void setZero4();
__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
__forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
__forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
__forceinline void setNeg3(const hkVector4& v);
__forceinline hkSimdReal dot3(const hkVector4& a) const;
__forceinline hkSimdReal dot4xyz1(const hkVector4& a) const;
__forceinline hkReal& operator() (int i);
__forceinline const hkReal& operator() (int i) const;
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
class MustEndWithSemiColon;
public:
hkVector4 m_vec;
};
class hkMatrix3
{
public:
class MustEndWithSemiColon;
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
void setInverse( const hkTransform &t );
void setMulInverseMul( const hkTransform& bTa, const hkTransform &bTc );
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
inline void hkVector4::setZero4()
{
x = y = z = w = 0;
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
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& m0, const hkVector4& m1)
{
x = a.x + m0.x * m1.x;
y = a.y + m0.y * m1.y;
z = a.z + m0.z * m1.z;
w = a.w + m0.w * m1.w;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
x = -v.x;
y = -v.y;
z = -v.z;
w =  v.w;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
return (x * a.x) + ( y * a.y ) + ( z * a.z );
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
return (x * a.x) + ( y * a.y ) + ( z * a.z ) + ( w  );
}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
;
hkReal r = (&v.x)[i];
x = r;
y = r;
z = r;
w = r;
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
return m_centerOfMass1(3);
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
static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);
};
void __cdecl hkString::memCpy16NonEmpty( void* dst, const void* src, int numQuads)
{
;
;
;
const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
hkUint32* dst32 = reinterpret_cast<      hkUint32*>(dst);
{
do
{
dst32[0] = src32[0];
dst32[1] = src32[1];
dst32[2] = src32[2];
dst32[3] = src32[3];
dst32+= 4;
src32+= 4;
}
while ( --numQuads > 0 );
}
}
int hkThreadMemory::constSizeToRow( int size )
{
;
;
if (size <= 8 )	return 1;
else if (size <= 16 )	return 2;
else if (size <= 32 )	return 3;
else if (size <= 48 )	return 4;
else if (size <= 64 )	return 5;
else if (size <= 96 )	return 6;
else if (size <= 128 )	return 7;
else if (size <= 160 )	return 8;
else if (size <= 192 )	return 9;
else if (size <= 256 )	return 10;
else if (size <= 320 )	return 11;
else if (size <= 512 )	return 12;
else if (size <= 1024)	return 13;
else if (size <= 2048)	return 14;
else if (size <= 4096)	return 15;
else if (size <= 8192)	return 16;
else
{
return -1;
}
}
void* hkThreadMemory::allocateChunkConstSize(int nbytes, HK_MEMORY_CLASS cl)
{
;
int row = constSizeToRow(nbytes);
if( void* p = m_free_list[row].get() )
{
return p;
}
return onRowEmpty(row, cl);
}
void hkThreadMemory::deallocateChunkConstSize(void* p, int nbytes, HK_MEMORY_CLASS cl)
{
;
;
int row = constSizeToRow(nbytes);
if ( m_free_list[row].m_numElem >= m_maxNumElemsOnFreeList )
{
onRowFull(row, p, cl);
}
else
{
m_free_list[row].put(p);
}
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
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct hkInternalClassMember Members[]; struct DefaultStruct;
inline hkVector4& getSeparatingNormal();
inline void setFlipped( const hkContactPoint& point );
inline void flip();
protected:
class MustEndWithSemiColon;
hkVector4 m_position;
hkVector4 m_separatingNormal;
};
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
return m_separatingNormal;
}
inline void hkContactPoint::setFlipped( const hkContactPoint& point )
{
hkVector4 dist; dist.setBroadcast( point.m_separatingNormal, 3 );
m_position.setAddMul4( point.m_position, point.m_separatingNormal, dist );
m_separatingNormal.setNeg3( point.m_separatingNormal );
}
inline void hkContactPoint::flip()
{
setFlipped(*this);
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
__forceinline hkpShapeType getType() const;
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
class hkMotionState;
class hkpCdBody
{
public:
__forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; }       class MustEndWithSemiColon;
static const struct hkInternalClassMember Members[]; struct DefaultStruct;
__forceinline hkpCdBody(  ){}
friend class hkpCollidable;
__forceinline const hkpShape* getShape() const;
__forceinline hkpShapeKey getShapeKey() const ;
__forceinline const hkpCdBody* getParent() const;
public:
explicit __forceinline hkpCdBody( const hkpCdBody* parent );
__forceinline hkpCdBody( const hkpCdBody* parent, const hkTransform* t );
__forceinline void setShape( const hkpShape* shape, hkpShapeKey key );
__forceinline const hkMotionState* getMotionState() const;
public:
const hkpShape*       m_shape;
hkpShapeKey           m_shapeKey;
const void* m_motion;
const hkpCdBody*		 m_parent;
};
const hkMotionState* hkpCdBody::getMotionState() const
{
return static_cast<const hkMotionState*>(m_motion);
}
const hkpShape* hkpCdBody::getShape() const
{
return m_shape;
}
const hkpCdBody* hkpCdBody::getParent() const
{
return m_parent;
}
hkpCdBody::hkpCdBody( const hkpCdBody* parent )
{
m_parent = parent;
m_motion = parent->m_motion;
}
hkpCdBody::hkpCdBody( const hkpCdBody* parent, const hkTransform* t )
{
m_parent       = parent;
m_motion = t;
}
hkpShapeKey hkpCdBody::getShapeKey() const
{
return m_shapeKey;
}
void hkpCdBody::setShape( const hkpShape* shape, hkpShapeKey key )
{
m_shape = shape;
m_shapeKey = key;
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
typedef int AgentType;
enum {
MIN_TOTAL_SIZE = 16,
MAX_MEMORY_INCREASE = 80,
MAX_INITIAL_SIZE    = MAX_MEMORY_INCREASE + MIN_TOTAL_SIZE
};
enum StreamCommand
{
STREAM_NULL = 0,
STREAM_END  = 1,
STREAM_CALL = 2,
STREAM_CALL_FLIPPED = 3,
STREAM_CALL_WITH_TIM = 4,
STREAM_CALL_WITH_TIM_FLIPPED = 5,
STREAM_CALL_AGENT = 6,
};
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
hkReal getTolerance() const { return m_tolerance; }
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
__forceinline hkAgent3::AgentType getAgent3Type( hkpShapeType typeA, hkpShapeType typeB, hkBool32 predicitve ) const;
__forceinline hkAgent3::CreateFunc           getAgent3CreateFunc  ( hkAgent3::AgentType type );
__forceinline hkAgent3::DestroyFunc          getAgent3DestroyFunc ( hkAgent3::AgentType type );
__forceinline hkAgent3::CleanupFunc          getAgent3CleanupFunc ( hkAgent3::AgentType type );
__forceinline hkAgent3::ProcessFunc          getAgent3ProcessFunc ( hkAgent3::AgentType type );
__forceinline hkAgent3::SepNormalFunc        getAgent3SepNormalFunc( hkAgent3::AgentType type );
__forceinline hkAgent3::Symmetric            getAgent3Symmetric( hkAgent3::AgentType type );
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
hkAgent3::CreateFunc   hkpCollisionDispatcher::getAgent3CreateFunc  ( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_createFunc;
}
hkAgent3::DestroyFunc  hkpCollisionDispatcher::getAgent3DestroyFunc ( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_destroyFunc;
}
hkAgent3::CleanupFunc  hkpCollisionDispatcher::getAgent3CleanupFunc ( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_cleanupFunc;
}
hkAgent3::ProcessFunc  hkpCollisionDispatcher::getAgent3ProcessFunc ( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_processFunc;
}
hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_sepNormalFunc;
}
hkAgent3::Symmetric     hkpCollisionDispatcher::getAgent3Symmetric( hkAgent3::AgentType type )
{
return m_agent3Func[type ].m_symmetric;
}
hkAgent3::AgentType hkpCollisionDispatcher::getAgent3Type( hkpShapeType typeA, hkpShapeType typeB, hkBool32 predictive ) const
{
if ( predictive )
{
return m_agent3TypesPred[typeA] [ typeB ];
}
return m_agent3Types[typeA] [ typeB ];
}
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
protected:
hkpContactMgr* m_contactMgr;
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
};
struct TimerBeginListCommand : public hkMonitorStream::TimerCommand
{
class MustEndWithSemiColon;
const char* m_nameOfFirstSplit;
};
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
namespace hkSweptTransformUtil
{
void __cdecl lerp2( const hkSweptTransform& sweptTrans, hkTime time, hkTransform& transformOut );
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
public:
inline void flip();
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
inline void flip();
public:
hkContactPoint     m_contactPoint;
hkPadSpu<hkReal>   m_time;
hkPadSpu<hkReal>      m_seperatingVelocity;
hkGskCache16			m_gskCache;
hkContactPointPropertiesWithExtendedUserData16 m_properties;
};
struct ToiInfo m_toi;
};
void hkpProcessCollisionData::ToiInfo::flip()
{
hkVector4& norm = m_contactPoint.getSeparatingNormal();
norm.setNeg3( norm );
m_gskCache.flip();
}
struct hkpProcessCollisionOutput: public hkpProcessCollisionData
{
public:
class MustEndWithSemiColon;
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
class hkpBvTreeShape;
class hkpShapeCollectionFilter
{
public:
static const struct hkInternalClassMember Members[]; struct DefaultStruct;
virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB  ) const = 0;
virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB ) const = 0;
virtual int numShapeKeyHitsLimitBreached( const hkpCollisionInput& input,
const hkpCdBody& bodyA, const hkpCdBody& bodyB,
const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
hkpShapeKey* shapeKeysInOut,
int shapeKeysCapacity) const = 0;
virtual ~hkpShapeCollectionFilter() { }
};
struct hkpAgent1nSector
{
static const struct hkInternalClassMember Members[]; struct DefaultStruct;
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_AGENT); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkpAgent1nSector), HK_MEMORY_CLASS_AGENT); }             class MustEndWithSemiColon;
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
inline hkpAgent1nSector(): m_bytesAllocated(0){}
};
struct hkpAgent1nTrack
{
class MustEndWithSemiColon;
hkArray<hkpAgent1nSector*> m_sectors;
};
class hkShapeKeyPair
{
public:
class MustEndWithSemiColon;
hkpShapeKey m_shapeKeyA;
hkpShapeKey m_shapeKeyB;
};
struct hkpAgent1nMachineEntry: hkpAgentEntry
{
class MustEndWithSemiColon;
hkShapeKeyPair m_shapeKeyPair;
};
struct hkpAgent1nMachinePaddedEntry: hkpAgent1nMachineEntry
{
class MustEndWithSemiColon;
hkUint32 m_padUpTo16Bytes;
};
struct hkpAgent1nMachineTimEntry: hkpAgent1nMachineEntry
{
class MustEndWithSemiColon;
hkTime     m_timeOfSeparatingNormal;
hkVector4  m_separatingNormal;
};
struct hkAgent1nMachineBodyTemp
{
	hkpCdBody m_bodyA;
	hkpCdBody m_bodyB;
	hkTransform m_transA;
	hkTransform m_transB;
};
static void hkAgent1nMachine_initInputAtTime( hkpAgent3Input& in, hkAgent1nMachineBodyTemp& temp, hkpAgent3Input& out )
{
	hkSweptTransformUtil::lerp2( in.m_bodyA->getMotionState()->getSweptTransform(), in.m_input->m_stepInfo.m_startTime, temp.m_transA );
	hkSweptTransformUtil::lerp2( in.m_bodyB->getMotionState()->getSweptTransform(), in.m_input->m_stepInfo.m_startTime, temp.m_transB );
	out.m_bodyA = &temp.m_bodyA;
	out.m_bodyB = &temp.m_bodyB;
	out.m_contactMgr = in.m_contactMgr;
	out.m_input = in.m_input;
	temp.m_bodyA.setShape( in.m_bodyA->getShape(), in.m_bodyA->getShapeKey() );
	new (&temp.m_bodyA) hkpCdBody( in.m_bodyA, &temp.m_transA );
	new (&temp.m_bodyB) hkpCdBody( in.m_bodyB, &temp.m_transB );
	out.m_aTb.setMulInverseMul( temp.m_transA, temp.m_transB );
}
static void hkAgent1nMachine_flipInput( hkpAgent3ProcessInput& in, hkpAgent3ProcessInput& out )
{
	out.m_bodyA = in.m_bodyB;
	out.m_bodyB = in.m_bodyA;
	out.m_input = in.m_input;
	out.m_offsetPpuSectorMinusSpuSector = in.m_offsetPpuSectorMinusSpuSector;
	out.m_contactMgr = in.m_contactMgr;
	out.m_linearTimInfo.setNeg3( in.m_linearTimInfo );
	out.m_aTb.setInverse( in.m_aTb );
}
class hkShapeKeyPairLocalNm
{
	public:
		__forceinline bool operator==( const hkShapeKeyPair& p ) { return m_shapeKeyB == p.m_shapeKeyB && m_shapeKeyA == p.m_shapeKeyA; }
		__forceinline bool operator>( const hkShapeKeyPair& p ) { return m_shapeKeyB > p.m_shapeKeyB || ( m_shapeKeyB == p.m_shapeKeyB && m_shapeKeyA > p.m_shapeKeyA ); }
		__forceinline void writeTo( hkShapeKeyPair& p ) { p.m_shapeKeyB = m_shapeKeyB; p.m_shapeKeyA = m_shapeKeyA; }
		hkPadSpu<hkpShapeKey> m_shapeKeyA;
		hkPadSpu<hkpShapeKey> m_shapeKeyB;
};
static __forceinline void hkShapeKeyPairLocalNm_set( hkShapeKeyPairLocalNm& local, const hkShapeKeyPair& p ) { local.m_shapeKeyA = p.m_shapeKeyA; local.m_shapeKeyB = p.m_shapeKeyB; }
static __forceinline void hkAgentNmMachine_extractShapes( const hkShapeKeyPairLocalNm& shapeKeyPair, hkShapeKeyPairLocalNm& extractedShapeKeys,
	const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeContainerB,
	hkpShapeContainer::ShapeBuffer& shapeBufferA, hkpShapeContainer::ShapeBuffer& shapeBufferB,
	hkpCdBody& modifiedBodyA, hkpCdBody& modifiedBodyB )
{
	{
		hkpShapeKey key = shapeKeyPair.m_shapeKeyB;
		if ( extractedShapeKeys.m_shapeKeyB != key )
		{
			extractedShapeKeys.m_shapeKeyB = key;
			const hkpShape* shapeB = shapeContainerB->getChildShape( key, shapeBufferB );
			modifiedBodyB.setShape( shapeB, key );
		}
	}
	{
		hkpShapeKey key = shapeKeyPair.m_shapeKeyA;
		if ( extractedShapeKeys.m_shapeKeyA != key )
		{
			extractedShapeKeys.m_shapeKeyA = key;
			const hkpShape* shapeA = shapeContainerA->getChildShape( key, shapeBufferA );
			modifiedBodyA.setShape( shapeA, key );
		}
	}
}
void FUN_00a2c5b0( hkpAgent1nTrack& agentTrack, hkpAgent1nTrack* agentTrackOnPpu, const hkpAgent3ProcessInput& inputIn, const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeContainerB, const hkShapeKeyPair* newKeys, hkpProcessCollisionOutput& output )
{
	hkMath::prefetch128( agentTrack.m_sectors.begin() );
	hkpAgent3ProcessInput input;
	hkString::memCpy16NonEmpty( &input, &inputIn, sizeof(hkpAgent3ProcessInput) >> 4 );
	hkShapeKeyPairLocalNm extractedShapeKeys;
	extractedShapeKeys.m_shapeKeyA = 0xffffffff; extractedShapeKeys.m_shapeKeyB = 0xffffffff;
	hkpCollisionDispatcher* dispatcher = input.m_input->m_dispatcher;
	hkpCdBody modifiedBodyB( input.m_bodyB );
	hkpCdBody modifiedBodyA( input.m_bodyA );
	input.m_bodyB = &modifiedBodyB;
	input.m_bodyA = &modifiedBodyA;
	int numTim = 0;
	hkpAgent1nSector* readSector = agentTrack.m_sectors[0];
	hkpAgent1nSector* currentSector = new hkpAgent1nSector;
	int currentSectorIndex = 0;
	bool prevInputInitialized = false;
	bool prevFlippedInputInitialized = false;
	hkpAgent3Input prevInput;
	hkpAgent3Input prevFlippedInput;
	hkAgent1nMachineBodyTemp prevTemp;
	hkAgent1nMachineBodyTemp prevFlippedTemp;
	int nextReadSectorIndex = 1;
	void* readData = readSector->getBegin();
	void* readEnd = readSector->getEnd();
	void* currentData = currentSector->getBegin();
	hkpShapeContainer::ShapeBuffer shapeBufferA;
	hkpShapeContainer::ShapeBuffer shapeBufferB;
	while ( 1 )
	{
		hkShapeKeyPairLocalNm shapeKeyPair;
		if ( !newKeys )
		{
			hkpAgent1nMachineEntry* entry = reinterpret_cast<hkpAgent1nMachineEntry*>( readData );
			int entrySize = entry->m_size;
			hkString::memCpy16NonEmpty( currentData, readData, entrySize >> 4 );
			readData = hkAddByteOffset( readData, entrySize );
			hkShapeKeyPairLocalNm_set( shapeKeyPair, entry->m_shapeKeyPair );
		}
		else
		{
			hkpAgent1nMachineEntry* readHeader = reinterpret_cast<hkpAgent1nMachineEntry*>( readData );
			shapeKeyPair.m_shapeKeyA = newKeys->m_shapeKeyA; shapeKeyPair.m_shapeKeyB = newKeys->m_shapeKeyB;
			if ( shapeKeyPair == readHeader->m_shapeKeyPair )
			{
				int size = readHeader->m_size;
				hkString::memCpy16NonEmpty( currentData, readData, size >> 4 );
				readData = hkAddByteOffset( readData, size );
				newKeys++;
			}
			else if ( shapeKeyPair > readHeader->m_shapeKeyPair )
			{
				void* agentData = ( ( readHeader->m_streamCommand & 0xe ) == hkAgent3::STREAM_CALL_WITH_TIM ) ? hkAddByteOffset( readHeader, sizeof(hkpAgent1nMachineTimEntry) ) : hkAddByteOffset( readHeader, sizeof(hkpAgent1nMachinePaddedEntry) );
				readData = hkAddByteOffset( readData, readHeader->m_size );
				dispatcher->getAgent3DestroyFunc( readHeader->m_agentType )( readHeader, agentData, input.m_contactMgr, *output.m_constraintOwner.val(), dispatcher );
				goto checkReadSector;
			}
			else
			{
				if ( input.m_input->m_filter->isCollisionEnabled( *input.m_input, *inputIn.m_bodyA, *inputIn.m_bodyB, *shapeContainerA, *shapeContainerB, shapeKeyPair.m_shapeKeyA, shapeKeyPair.m_shapeKeyB ) )
				{
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					const hkpShape* shapeB = modifiedBodyB.getShape();
					const hkpShape* shapeA = modifiedBodyA.getShape();
					hkpAgent1nMachineEntry* h = reinterpret_cast<hkpAgent1nMachineEntry*>( currentData );
					shapeKeyPair.writeTo( h->m_shapeKeyPair );
					h->m_agentType = hkUchar( dispatcher->getAgent3Type( shapeA->getType(), shapeB->getType(), input.m_input->m_createPredictiveAgents ) );
					h->m_numContactPoints = 0;
					hkpAgent3ProcessInput flippedInput;
					hkpAgent3ProcessInput* in = &input;
					int isFlipped = 0;
					if ( dispatcher->getAgent3Symmetric( h->m_agentType ) == hkAgent3::IS_NOT_SYMMETRIC_AND_FLIPPED )
					{
						isFlipped = 1;
						in = &flippedInput;
						hkAgent1nMachine_flipInput( input, flippedInput );
					}
					if ( dispatcher->getAgent3SepNormalFunc( h->m_agentType ) != 0 )
					{
						hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
						entry->m_streamCommand = hkUchar( hkAgent3::STREAM_CALL_WITH_TIM + isFlipped );
						entry->m_timeOfSeparatingNormal = hkTime( -1.0f );
						entry->m_separatingNormal.setZero4();
						void* agentData = entry + 1;
						void* agentEnd = dispatcher->getAgent3CreateFunc( entry->m_agentType )( *in, entry, agentData );
						hkUlong size = hkGetByteOffset( entry, agentEnd );
						entry->m_size = hkUchar( size );
					}
					else
					{
						hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
						entry->m_streamCommand = hkUchar( hkAgent3::STREAM_CALL + isFlipped ); void* agentData = entry + 1;
						void* agentEnd = dispatcher->getAgent3CreateFunc( entry->m_agentType )( *in, entry, agentData );
						hkUlong size = hkGetByteOffset( entry, agentEnd );
						entry->m_size = hkUchar( size );
					}
				}
				else
				{
					hkpAgent1nMachinePaddedEntry* h = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
					*reinterpret_cast<hkUint32*>( h ) = 0;
					shapeKeyPair.writeTo( h->m_shapeKeyPair );
					h->m_size = sizeof(hkpAgent1nMachinePaddedEntry);
				}
				newKeys++;
			}
		}
		{
			hkAgent3::StreamCommand command = hkAgent3::StreamCommand( reinterpret_cast<hkpAgentEntry*>( currentData )->m_streamCommand );
			switch ( command )
			{
				case hkAgent3::STREAM_CALL_AGENT:
				{   hkpAgent1nMachinePaddedEntry* paddedEntry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
					void* agentData = paddedEntry + 1;
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					hkpCollisionAgent* agent = *reinterpret_cast<hkpCollisionAgent**>( agentData );
					agent->processCollision( modifiedBodyA, modifiedBodyB, *input.m_input, output );
					currentData = hkAddByteOffset( agentData, 16 );
					break;
				}
				case hkAgent3::STREAM_CALL:
				{   hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					void* agentData = entry + 1;
					currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( input, entry, agentData, 0, output );
					entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
					break;
				}
				case hkAgent3::STREAM_CALL_FLIPPED:
				{   hkpAgent3ProcessInput flippedInput;
					hkAgent1nMachine_flipInput( input, flippedInput );
					hkpAgent1nMachinePaddedEntry* entry = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData );
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					hkReal oldToi = output.m_toi.m_time;
					void* agentData = entry + 1;
					hkpProcessCdPoint* oldResultBegin = output.m_firstFreeContactPoint;
					currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( flippedInput, entry, agentData, 0, output );
					entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
					while ( oldResultBegin < output.m_firstFreeContactPoint )
					{
						oldResultBegin->m_contact.flip();
						oldResultBegin++;
					}
					if ( oldToi != output.m_toi.m_time )
					{
						output.m_toi.flip();
					}
					break;
				}
				case hkAgent3::STREAM_CALL_WITH_TIM_FLIPPED:
				{   hkpAgent3ProcessInput flippedInput;
					hkAgent1nMachine_flipInput( input, flippedInput );
					hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
					hkReal distAtT1;
					if ( entry->m_timeOfSeparatingNormal != flippedInput.m_input->m_stepInfo.m_startTime )
					{
						const hkpCollisionQualityInfo& ci = *flippedInput.m_input->m_collisionQualityInfo;
						if ( !ci.m_useContinuousPhysics )
						{
							entry->m_timeOfSeparatingNormal = flippedInput.m_input->m_stepInfo.m_endTime;
							distAtT1 = ci.m_minSeparation * 0.5f;
							entry->m_separatingNormal.setZero4();
							entry->m_separatingNormal( 3 ) = distAtT1;
							goto PROCESS_AT_T1_FLIPPED;
						}
						if ( !prevFlippedInputInitialized )
						{
							prevFlippedInputInitialized = true;
							hkAgent1nMachine_initInputAtTime( flippedInput, prevFlippedTemp, prevFlippedInput );
							prevFlippedTemp.m_bodyB.setShape( flippedInput.m_bodyB->getShape(), flippedInput.m_bodyB->m_shapeKey );
						}
						hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
						prevFlippedTemp.m_bodyA.setShape( modifiedBodyB.getShape(), shapeKeyPair.m_shapeKeyB );
						prevFlippedTemp.m_bodyB.setShape( modifiedBodyA.getShape(), shapeKeyPair.m_shapeKeyA );
						void* agentData = entry + 1;
						dispatcher->getAgent3SepNormalFunc( entry->m_agentType )( prevFlippedInput, entry, agentData, entry->m_separatingNormal );
					}
					entry->m_timeOfSeparatingNormal = flippedInput.m_input->m_stepInfo.m_endTime;
					{
						hkReal worstCaseDeltaDist = flippedInput.m_linearTimInfo.dot4xyz1( entry->m_separatingNormal );
						distAtT1 = entry->m_separatingNormal( 3 ) - worstCaseDeltaDist;
					}
					if ( distAtT1 >= flippedInput.m_input->getTolerance() )
					{
						entry->m_separatingNormal( 3 ) = distAtT1;
						if ( !entry->m_numContactPoints )
						{
							currentData = hkAddByteOffset( currentData, entry->m_size );
						}
						else
						{
							void* agentData = entry + 1;
							currentData = dispatcher->getAgent3CleanupFunc( entry->m_agentType )( entry, agentData, flippedInput.m_contactMgr, *output.m_constraintOwner.val() );
							entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
						}
						numTim++;
						break;
					}
PROCESS_AT_T1_FLIPPED:
					flippedInput.m_distAtT1 = distAtT1;
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					hkpProcessCdPoint* oldResultBegin = output.m_firstFreeContactPoint;
					hkReal oldToi = output.m_toi.m_time;
					void* agentData = entry + 1;
					currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( flippedInput, entry, agentData, &entry->m_separatingNormal, output );
					entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
					while ( oldResultBegin < output.m_firstFreeContactPoint )
					{
						oldResultBegin->m_contact.flip();
						oldResultBegin++;
					}
					if ( oldToi != output.m_toi.m_time )
					{
						output.m_toi.flip();
					}
					break;
				}
				case hkAgent3::STREAM_CALL_WITH_TIM:
				{   hkpAgent1nMachineTimEntry* entry = reinterpret_cast<hkpAgent1nMachineTimEntry*>( currentData );
					hkReal distAtT1;
					if ( entry->m_timeOfSeparatingNormal != input.m_input->m_stepInfo.m_startTime )
					{
						if ( entry->m_timeOfSeparatingNormal >= input.m_input->m_stepInfo.m_endTime )
						{
							hkReal backDt = entry->m_timeOfSeparatingNormal - input.m_input->m_stepInfo.m_endTime;
							hkVector4 backTim;
							hkSweptTransformUtil::calcTimInfo( *input.m_bodyA->getMotionState(), *input.m_bodyB->getMotionState(), backDt, backTim );
							hkReal backLinear = backTim.dot3( entry->m_separatingNormal );
							hkReal backAng = backTim( 3 );
							distAtT1 = entry->m_separatingNormal( 3 ) + backLinear - backAng;
						}
						else
						{
							const hkpCollisionQualityInfo& ci = *input.m_input->m_collisionQualityInfo;
							if ( !ci.m_useContinuousPhysics )
							{
								entry->m_timeOfSeparatingNormal = input.m_input->m_stepInfo.m_endTime;
								distAtT1 = ci.m_minSeparation * 0.1f;
								entry->m_separatingNormal.setZero4();
								entry->m_separatingNormal( 3 ) = distAtT1;
								goto PROCESS_AT_T1;
							}
							if ( !prevInputInitialized )
							{
								prevInputInitialized = true;
								hkAgent1nMachine_initInputAtTime( input, prevTemp, prevInput );
							}
							hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
							prevTemp.m_bodyB.setShape( modifiedBodyB.getShape(), shapeKeyPair.m_shapeKeyB );
							prevTemp.m_bodyA.setShape( modifiedBodyA.getShape(), shapeKeyPair.m_shapeKeyA );
							void* agentData = entry + 1;
							dispatcher->getAgent3SepNormalFunc( entry->m_agentType )( prevInput, entry, agentData, entry->m_separatingNormal );
						}
					}
					entry->m_timeOfSeparatingNormal = input.m_input->m_stepInfo.m_endTime;
					{
						hkReal worstCaseDeltaDist = input.m_linearTimInfo.dot4xyz1( entry->m_separatingNormal );
						distAtT1 = entry->m_separatingNormal( 3 ) - worstCaseDeltaDist;
					}
					if ( distAtT1 >= input.m_input->getTolerance() )
					{
						entry->m_separatingNormal( 3 ) = distAtT1;
						if ( !entry->m_numContactPoints )
						{
							currentData = hkAddByteOffset( currentData, entry->m_size );
						}
						else
						{
							void* agentData = entry + 1;
							currentData = dispatcher->getAgent3CleanupFunc( entry->m_agentType )( entry, agentData, input.m_contactMgr, *output.m_constraintOwner.val() );
							entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
						}
						numTim++;
						break;
					}
PROCESS_AT_T1:
					input.m_distAtT1 = distAtT1;
					hkAgentNmMachine_extractShapes( shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA, shapeBufferB, modifiedBodyA, modifiedBodyB );
					void* agentData = entry + 1;
					currentData = dispatcher->getAgent3ProcessFunc( entry->m_agentType )( input, entry, agentData, &entry->m_separatingNormal, output );
					entry->m_size = hkUchar( hkGetByteOffset( entry, currentData ) );
					break;
				}
				case hkAgent3::STREAM_NULL:
				{
					currentData = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData ) + 1;
					break;
				}
				case hkAgent3::STREAM_END:
				{   currentData = reinterpret_cast<hkpAgent1nMachinePaddedEntry*>( currentData ) + 1;
					break;
				}
				default:
					;
			}
		}
checkReadSector:
		;
		if ( readData == readEnd )
		{
			delete readSector;
			if ( nextReadSectorIndex < agentTrack.m_sectors.getSize() )
			{
				readSector = agentTrack.m_sectors[nextReadSectorIndex];
				readData = readSector->getBegin();
				readEnd = readSector->getEnd();
				nextReadSectorIndex++;
			}
			else { break; }
		}
		int nextAgentSize = reinterpret_cast<hkpAgentEntry*>( readData )->m_size;
		int bytesUsed = hkGetByteOffset( currentSector->getBegin(), currentData );
		if ( nextAgentSize + bytesUsed <= currentSector->getCapacity() - hkAgent3::MAX_MEMORY_INCREASE )
		{
			continue;
		}
		currentSector->m_bytesAllocated = bytesUsed;
		if ( currentSectorIndex >= nextReadSectorIndex )
		{
			agentTrack.m_sectors.expandAt( nextReadSectorIndex, 1 );
			nextReadSectorIndex++;
		}
		agentTrack.m_sectors[currentSectorIndex] = currentSector;
		currentSectorIndex++;
		currentSector = new hkpAgent1nSector;
		currentData = currentSector->getBegin();
	}
	{
		int bytesUsed = hkGetByteOffset( currentSector->getBegin(), currentData );
		currentSector->m_bytesAllocated = bytesUsed;
	}
	agentTrack.m_sectors.setSize( currentSectorIndex + 1 );
	agentTrack.m_sectors[currentSectorIndex] = currentSector;
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); if ( mStream.memoryAvailable() ) { hkMonitorStream::AddValueCommand* h = reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd()); h->m_commandAndMonitor = "M" "i" "numTim"; h->m_value = float(numTim); mStream.setEnd( (char*)(h+1) ); } };
	input.m_bodyB = modifiedBodyB.getParent();
}
}

// @f3 0x00a3e820 (community match, verified in this file)
// hkpBoxBoxCollisionDetection_calcManifold = Havok 5.5.0 hkpBoxBoxCollisionDetection::calcManifold (hkpInternal.lib, hkpBoxBoxCollisionDetection.obj).
// Built /MT /Ox /Ob1 /Oi /Ot /GF /GS- (Havok release set; the pack lists /Od). Body = chk_2620779f645443579cc3 (another
// contributor: real bodies for hkpBoxBoxCollisionDetection_findClosestPoint / FUN_00a3cc40, SDK accessors) plus one dead `if ( 0 )` block in
// findAdditionalManifoldPoints. That block emits no code; it only adds 23 reader temporaries before the first inlined
// calcFaceFeatureBitSetFromAxisMap. The x|y|z|w mask chain is one flattened OPOR sorted by the multi-def ?: temps'
// hash ((key << 6) & 0xffff): the y temp must lie past key 4096 while x stays below it, so that y is or-ed last (and
// spilled) in copy 1 and x in copy 2, as in the original. Frame keys and every x87 operand order are unchanged.
namespace f3m_00a3e820 {
// HK_ENDIAN_BIG: the SDK's byte-order switch (hkBaseTypes.h; 0 on this x86 build)
enum { HK_ENDIAN_BIG = 0 };
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

template <typename TYPE>
__forceinline const TYPE* __cdecl hkAddByteOffsetConst( const TYPE* base, hkUlong offset )
{
	return reinterpret_cast<const TYPE*>( reinterpret_cast<const char*>(base) + offset );
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
		int getMask(Mask m) const { return m_mask & m; }
	private:
		int m_mask;
		friend class hkVector4;
};


namespace hkMath
{
	inline hkReal __cdecl sqrt(hkReal r) { return ::sqrtf(r); }
	inline hkReal __cdecl fabs(hkReal r) { return ::fabsf(r); }
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
		                class MustEndWithSemiColon;
		__forceinline void operator= ( const hkVector4& v );
		__forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w=0);
		__forceinline void setAll3(hkReal x);
		__forceinline void setZero4();
		__forceinline void add4(const hkVector4& a);
		__forceinline void setSub4(const hkVector4& a, const hkVector4& b);
		__forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
		__forceinline void mul4(hkSimdRealParameter a);
		__forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
		__forceinline void setCross( const hkVector4& a, const hkVector4& b );
		__forceinline hkVector4Comparison compareLessThanZero4() const;
		__forceinline hkBool32 allLessThan3(hkVector4Parameter a) const;
		__forceinline void setNeg4(const hkVector4& v);
		__forceinline void setAbs4(const hkVector4& v);
		void setRotatedDir(const hkRotation& a, const hkVector4& b);
		void setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedPos(const hkTransform& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
		__forceinline hkSimdReal dot3(const hkVector4& a) const;
		__forceinline hkSimdReal lengthSquared3() const;
		__forceinline hkSimdReal length3() const;
		__forceinline hkSimdReal normalizeWithLength3();
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
		__forceinline void getRow( int row, hkVector4& r) const;
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
		__forceinline const hkRotation& getRotation() const;
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

inline void hkVector4::setZero4()
{
	x = y = z = w = 0;
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

inline void hkVector4::setMul4(hkSimdRealParameter rs, const hkVector4& a)
{
	hkReal r = hkReal(rs);
	x = r * a.x;
	y = r * a.y;
	z = r * a.z;
	w = r * a.w;
}

inline hkVector4Comparison hkVector4::compareLessThanZero4() const
{
	hkVector4Comparison ret;
	ret.m_mask =
		((x<0) ? hkVector4Comparison::MASK_X : 0) |
		((y<0) ? hkVector4Comparison::MASK_Y : 0) |
		((z<0) ? hkVector4Comparison::MASK_Z : 0) |
		((w<0) ? hkVector4Comparison::MASK_W : 0);
	return ret;
}

inline hkBool32 hkVector4::allLessThan3(hkVector4Parameter a) const
{
	return x<a.x && y<a.y && z<a.z;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
	w = -v.w;
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

inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
	return (x * a.x) + ( y * a.y ) + ( z * a.z );
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
	return this->dot3(*this);
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

inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

	inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
	{
		const hkReal nx = v1(1)*v2(2) - v1(2)*v2(1);
		const hkReal ny = v1(2)*v2(0) - v1(0)*v2(2);
		const hkReal nz = v1(0)*v2(1) - v1(1)*v2(0);
		this->set( nx, ny, nz , 0.0f );
	}

	inline hkSimdReal hkVector4::length3() const
	{
		return hkMath::sqrt((x * x) + ( y * y ) + ( z * z ));
	}

	inline hkSimdReal hkVector4::normalizeWithLength3()
	{
		hkReal len = this->length3();
		this->mul4( (1.0f)/len );
		return len;
	}

inline void hkVector4::mul4(hkSimdRealParameter rs)
{
	hkReal s = hkReal(rs);
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

inline void hkVector4::add4(const hkVector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void hkMatrix3::getRow( int row, hkVector4& r) const
{
	r.set( getColumn(0)(row), getColumn(1)(row), getColumn(2)(row) );
}

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		inline const hkVector4& getPosition() const { return m_position; }
		inline hkVector4& getPosition();
		inline const hkVector4& getNormal() const;
		inline hkVector4& getSeparatingNormal();
		inline hkReal getDistance() const;
		inline void setDistance( hkReal d );
	protected:
		                class MustEndWithSemiColon;
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

inline hkReal hkContactPoint::getDistance() const
{
	return m_separatingNormal(3);
}

inline void hkContactPoint::setDistance( hkReal d )
{
	m_separatingNormal(3) = d;
}

class hkpFeatureContactPoint
{
	public:
		                class MustEndWithSemiColon;
	hkpFeatureContactPoint()
	{
		m_contactPointId = 0;
	}
	hkUint8 m_featureIdA;
	hkUint8 m_featureIdB;
	hkContactPointId	m_contactPointId;
};

class hkpCdBody;

class hkpBoxBoxManifold
{
	public:
		                class MustEndWithSemiColon;
		int addPoint( const hkpCdBody& bodyA, const hkpCdBody& bodyB, hkpFeatureContactPoint& fcp );
		void removePoint( int index );
		inline int getNumPoints();
		inline hkpFeatureContactPoint& operator[]( int index );
		inline hkBool findInManifold( const hkpFeatureContactPoint& fcp );
		inline hkBool isComplete();
		inline void setComplete( hkBool complete );
		inline hkBool hasNoPointsLeft();
	public:
		hkpFeatureContactPoint m_contactPoints[8];
		hkUchar  m_faceVertexFeatureCount;
		hkUchar  m_numPoints;
		hkBool m_isComplete;
		hkBool m_manifoldNormalInitialized;
		hkUint32 m_manifoldNormalB;
		hkVector4 m_manifoldNormalA;
};

inline int hkpBoxBoxManifold::getNumPoints()
{
	return m_numPoints;
}

inline hkpFeatureContactPoint& hkpBoxBoxManifold::operator[]( int index )
{
	return m_contactPoints[index];
}

inline hkBool hkpBoxBoxManifold::findInManifold( const hkpFeatureContactPoint& fcp )
{
	for (int i = m_numPoints-1; i>=0; i--)
	{
		if ( m_contactPoints[i].m_featureIdA == fcp.m_featureIdA && m_contactPoints[i].m_featureIdB == fcp.m_featureIdB )
		{
			return true;
		}
	}
	return false;
}

inline hkBool hkpBoxBoxManifold::isComplete()
{
	return m_isComplete;
}

inline void hkpBoxBoxManifold::setComplete( hkBool complete )
{
	m_isComplete = complete;
}

inline hkBool hkpBoxBoxManifold::hasNoPointsLeft()
{
	return (m_numPoints >= 8);
}

namespace hkVector4Util
{
	__forceinline void __cdecl mulSigns4( hkVector4& inout, const hkVector4& signsSource);
	hkUint32 __cdecl packQuaternionIntoInt32( hkVector4Parameter qin);
	__forceinline void __cdecl unPackInt32IntoQuaternion( hkUint32 ivalue, hkVector4& qout );
}

inline void __cdecl hkVector4Util::mulSigns4( hkVector4& inout, const hkVector4& signv)
{
	hkUint32* intp = reinterpret_cast<hkUint32*>(&inout);
	const hkUint32* sign = reinterpret_cast<const hkUint32*>(&signv);
	intp[0] ^= (sign[0] & 0x80000000);
	intp[1] ^= (sign[1] & 0x80000000);
	intp[2] ^= (sign[2] & 0x80000000);
	intp[3] ^= (sign[3] & 0x80000000);
}

inline void __cdecl hkVector4Util::unPackInt32IntoQuaternion( hkUint32 ivalue, hkVector4& qout )
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
	const hkReal f = 1.1f/128.0f;
	qout(0) = f * a;
	qout(1) = f * b;
	qout(2) = f * c;
	qout(3) = f * d;
}

struct hkpProcessCdPoint
{
	                class MustEndWithSemiColon;
	hkContactPoint m_contact;
    hkPadSpu<hkUint32>	m_contactPointId;
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

class hkpSolverResults
{
	public:
		                class MustEndWithSemiColon;
	public:
		hkReal m_impulseApplied;
		hkReal m_internalSolverData;
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

class hkpConstraintOwner;
	enum {HK_MAX_CONTACT_POINT = 256 };
struct hkpAgentEntry;

struct hkpProcessCollisionData
{
	public:
		                class MustEndWithSemiColon;
		inline int getNumContactPoints() const;
		inline hkpProcessCdPoint& getContactPoint( int i );
		inline hkpProcessCdPoint* getEnd();
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

inline int hkpProcessCollisionData::getNumContactPoints() const
{
	return int(m_firstFreeContactPoint - &m_contactPoints[0]);
}

inline hkpProcessCdPoint* hkpProcessCollisionData::getEnd()
{
	return m_firstFreeContactPoint;
}

inline hkpProcessCdPoint& hkpProcessCollisionData::getContactPoint( int i )
{
	return m_contactPoints[i];
}

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

struct hkpProcessCollisionInput;
class hkpCollidable;

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

class hkpBoxBoxCollisionDetection
{
	public:
		                class MustEndWithSemiColon;
		enum hkpBoxBoxFeature
		{
			HK_BOXBOX_FACE_A_X = 0, HK_BOXBOX_FACE_A_Y = 1, HK_BOXBOX_FACE_A_Z = 2,
			HK_BOXBOX_FACE_B_X = 4, HK_BOXBOX_FACE_B_Y = 5, HK_BOXBOX_FACE_B_Z = 6,
			HK_BOXBOX_EDGE_0_0 = 8, HK_BOXBOX_EDGE_0_1 = 9, HK_BOXBOX_EDGE_0_2 = 10,
			HK_BOXBOX_EDGE_1_0 = 12, HK_BOXBOX_EDGE_1_1 = 13, HK_BOXBOX_EDGE_1_2 = 14,
			HK_BOXBOX_EDGE_2_0 = 16, HK_BOXBOX_EDGE_2_1 = 17, HK_BOXBOX_EDGE_2_2 = 18,
			HK_BOXBOX_FEATURE_COUNT = 19
		};
		enum
		{
			HK_FINDCLOSESTPOINT_NO_VALID_POINT = 0,
			HK_FINDCLOSESTPOINT_POINT_IN_MANIFOLD = 1,
			HK_FINDCLOSESTPOINT_VALID_POINT = 2
		};
		class hkpFeaturePointCache
		{
			public:
				                class MustEndWithSemiColon;
				hkVector4 m_vA;
				hkVector4 m_vB;
				hkVector4 m_nA;
				hkReal m_normalSign;
				hkReal m_distance;
				int m_featureIndexA;
				int m_featureIndexB;
		};
	protected:
		__declspec(noalias) int hkpBoxBoxCollisionDetection_findClosestPoint( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint& fcp, hkpFeaturePointCache& fpp ) const;
		__forceinline void faceAVertexBValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const;
		__forceinline void faceBVertexAValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const;
		__forceinline void edgeEdgeValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp ) const;
		__forceinline hkBool isValidFaceAVertexB( hkpFeaturePointCache& fpp ) const;
		__forceinline hkBool isValidFaceBVertexA( hkpFeaturePointCache& fpp ) const;
		__declspec(noalias) hkBool FUN_00a3cc40( hkpFeaturePointCache& fpp ) const;
	public:
		void hkpBoxBoxCollisionDetection_calcManifold( hkpBoxBoxManifold& manifold ) const;
		hkResult checkIntersection( const hkVector4& tolerance ) const;
	protected:
		void initWorkVariables() const;
		__forceinline void refreshManifold( hkpBoxBoxManifold& manifold ) const;
		__forceinline hkResult addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const;
		__forceinline void findAdditionalManifoldPoints( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcp ) const;
		__forceinline void faceAVertexBValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const;
		__forceinline void faceBVertexAValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const;
		__forceinline void edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const;
		__forceinline void faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void removePoint( hkpBoxBoxManifold& manifold, int index ) const;
		__forceinline void calcManifoldNormal( hkVector4& manifoldN, const hkpFeatureContactPoint& fcp, hkpFeaturePointCache& fpp, hkBool isPointValidated ) const;
		__forceinline hkBool queryManifoldNormalConsistency( hkpBoxBoxManifold& manifold ) const;
		__forceinline void checkManifoldNormalConsistency( hkpBoxBoxManifold& manifold ) const;
		__forceinline void contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const;
		__forceinline void tryToAddPointFaceA( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcpTemplate, hkUint16 planeMask, hkReal closestPointDist ) const;
		__forceinline void tryToAddPointFaceB( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcpTemplate, hkUint16 planeMask, hkReal closestPointDist ) const;
		void checkCompleteness( hkpBoxBoxManifold& manifold, int planeMaskA, int planeMaskB ) const;
	public:
		const hkpCdBody& m_bodyA;
		const hkpCdBody& m_bodyB;
		const hkpProcessCollisionInput* m_env;
		hkpContactMgr* m_contactMgr;
		hkpProcessCollisionOutput* m_result;
		const hkTransform& m_wTa;
		const hkTransform& m_wTb;
		hkTransform m_aTb;
		hkVector4 m_radiusA;
		hkVector4 m_radiusB;
		hkVector4 m_tolerance4;
		hkVector4 m_keepRadiusA;
		hkVector4 m_keepRadiusB;
		const hkReal m_tolerance;
		const hkReal m_boundaryTolerance;
		mutable hkVector4 m_dinA;
		mutable hkVector4 m_dinB;
		mutable hkVector4 m_sepDist[5];

	protected:
		static const int m_maxFeaturesToReject;
		static const hkReal m_manifoldConsistencyCheckAngularCosTolerance;
		static const hkReal m_coplanerAngularCosTolerance;
		static const hkReal m_contactNormalAngularCosTolerance;
		static const hkReal m_edgeEndpointTolerance;
};

class hkBoxBoxUtils
{
	public:
		static __forceinline void __cdecl selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than );
};

const int hkpBoxBoxCollisionDetection::m_maxFeaturesToReject = 8;
const hkReal hkpBoxBoxCollisionDetection::m_edgeEndpointTolerance = 1.192092896e-07F;
const hkReal hkpBoxBoxCollisionDetection::m_manifoldConsistencyCheckAngularCosTolerance = 0.95f;
const hkReal hkpBoxBoxCollisionDetection::m_coplanerAngularCosTolerance = 0.98f;
const hkReal hkpBoxBoxCollisionDetection::m_contactNormalAngularCosTolerance = 0.95f;
extern const hkUint16 DAT_00e86130[7];

extern __declspec(align(16)) const hkReal DAT_00e860b0[8][4];

static __forceinline const hkVector4& getAxisMapFromFeatureBitSet( hkUint16 bitSet )
{
	int offset;
	if ( HK_ENDIAN_BIG )
	{
		offset = bitSet & 0x70;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( DAT_00e860b0 ), offset );
	}
	else
	{
		offset = ( bitSet & 0xe0 ) >> 1;
		return *hkAddByteOffsetConst( reinterpret_cast<const hkVector4*>( DAT_00e860b0 ), offset );
	}
}

static __forceinline hkReal getNormalSignFromFeatureBitSet( hkUint16 bitSet )
{
	hkReal retVal = 1.0f;
	const int bits = bitSet;
	hkUint32* retValBits = reinterpret_cast<hkUint32*>( &retVal );
	*retValBits |= ( bits & 8 ) << 28;
	return retVal;
}

void __cdecl hkBoxBoxUtils::selectIfGT3( hkVector4& result, const hkReal& selectIf, const hkVector4& greater, const hkReal& than )
{
	result(0) = ( greater(0) > than ) ? selectIf : result(0);
	result(1) = ( greater(1) > than ) ? selectIf : result(1);
	result(2) = ( greater(2) > than ) ? selectIf : result(2);
}

static __forceinline hkUint16 calcFaceFeatureBitSetFromAxisMap( const hkVector4& axisMap, hkReal normalSign )
{
	const int mask = axisMap.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ );
	int featureBitSet = mask << 4;
	const hkUint32* normalSignBits = reinterpret_cast<const hkUint32*>( &normalSign );
	featureBitSet |= ( *normalSignBits & 0x80000000 ) >> 28;
	return hkUint16( featureBitSet );
}

static __forceinline void setEdgeFeatureBitSetFromAxisMap( const hkVector4& axisMapAp, const hkVector4& axisMapBp, int featureIndexA, int featureIndexB, hkpFeatureContactPoint& fcp )
{
	hkVector4 axisMapA = axisMapAp;
	hkVector4 axisMapB = axisMapBp;
	axisMapA( featureIndexA ) = 1.0f;
	axisMapB( featureIndexB ) = 1.0f;
	const int maskA = axisMapA.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ );
	const int maskB = axisMapB.compareLessThanZero4().getMask( hkVector4Comparison::MASK_XYZ ) ^ hkVector4Comparison::MASK_XYZ;
	fcp.m_featureIdA = hkUint8( featureIndexA | 0x10 | ( maskA << 4 ) );
	fcp.m_featureIdB = hkUint8( ( maskB << 4 ) + featureIndexB );
}

void hkpBoxBoxCollisionDetection::faceAVertexBContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTb, fpp.m_vB );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTa.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::faceBVertexAContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndex = fcp.m_featureIdA - 4;
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal().setMul4( -fpp.m_normalSign, m_wTb.getRotation().getColumn( featureIndex ) );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeContactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	ccpOut.m_contactPointId = fcp.m_contactPointId;
	ccpOut.m_contact.getPosition()._setTransformedPos( m_wTa, fpp.m_vA );
	ccpOut.m_contact.getSeparatingNormal()._setRotatedDir( m_wTa.getRotation(), fpp.m_nA );
	ccpOut.m_contact.setDistance( fpp.m_distance );
}

void hkpBoxBoxCollisionDetection::edgeEdgeValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const
{
	fpp.m_featureIndexA = fcp.m_featureIdA;
	fpp.m_featureIndexB = fcp.m_featureIdB;
}

void hkpBoxBoxCollisionDetection::contactPointFromFeaturePointCache( hkpProcessCdPoint& ccpOut, const hkpFeatureContactPoint& fcp, const hkpFeaturePointCache& fpp ) const
{
	const int featureIndexA = fpp.m_featureIndexA;
	if ( featureIndexA <= HK_BOXBOX_FACE_A_Z )
	{
		faceAVertexBContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else if ( featureIndexA <= HK_BOXBOX_FACE_B_Z )
	{
		faceBVertexAContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
	else
	{
		edgeEdgeContactPointFromFeaturePointCache( ccpOut, fcp, fpp );
	}
}

hkResult hkpBoxBoxCollisionDetection::addPoint( hkpBoxBoxManifold& manifold, const hkpFeaturePointCache& fpp, hkpFeatureContactPoint& fcp ) const
{
	if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
	{
		hkVector4 vCandidate;
		if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_A_Z )
		{
			vCandidate._setTransformedPos( m_wTb, fpp.m_vB );
		}
		else
		{
			vCandidate._setTransformedPos( m_wTa, fpp.m_vA );
		}
		for ( int i = 0; i < manifold.getNumPoints(); i++ )
		{
			if ( manifold[i].m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				const hkpProcessCdPoint& existingPoint = m_result->getContactPoint( i );
				hkVector4 diff; diff.setSub4( vCandidate, existingPoint.m_contact.getPosition() );
				const hkReal distSquared = diff.dot3( diff );
				if ( distSquared <= hkReal( m_tolerance * m_tolerance + 1.192092896e-07F ) )
				{
					return HK_FAILURE;
				}
			}
		}
	}
	if ( manifold.hasNoPointsLeft() )
	{
		return HK_FAILURE;
	}
	int fcpIndex = manifold.addPoint( m_bodyA, m_bodyB, fcp );
	if ( fcpIndex >= 0 )
	{
		hkpProcessCdPoint* ccp = m_result->reserveContactPoints( 1 );
		contactPointFromFeaturePointCache( *ccp, fcp, fpp );
		if ( manifold.getNumPoints() > 1 )
		{
			hkpProcessCdPoint* lastPoint = m_result->getEnd() - 1;
			if ( lastPoint->m_contact.getNormal().dot3( ccp->m_contact.getNormal() ) <= 0.0f )
			{
				manifold.removePoint( fcpIndex );
				return HK_FAILURE;
			}
		}
		manifold[fcpIndex].m_contactPointId = m_contactMgr->addContactPoint( m_bodyA, m_bodyB, *m_env, *m_result, 0, ccp->m_contact );
		if ( manifold[fcpIndex].m_contactPointId == (0xffff) )
		{
			manifold.removePoint( fcpIndex );
		}
		else
		{
			m_result->commitContactPoints( 1 );
			fcp.m_contactPointId = manifold[fcpIndex].m_contactPointId;
			ccp->m_contactPointId = manifold[fcpIndex].m_contactPointId;
			if ( fcp.m_featureIdA <= HK_BOXBOX_FACE_B_Z )
			{
				manifold.m_faceVertexFeatureCount++;
			}
		}
	}
	return HK_SUCCESS;
}

static __forceinline int getMaxPlaneMask3( const hkVector4& vAbs, const hkVector4& v, int& axisOut )
{
	int axis;
	int mask;
	if ( vAbs(0) > vAbs(1) )
	{
		axis = 0;
		mask = 0x80;
	}
	else
	{
		axis = 1;
		mask = 0x40;
	}
	if ( vAbs(2) > vAbs(axis) )
	{
		axis = 2;
		mask = 0x20;
	}
	axisOut = axis;
	return mask;
}

hkBool hkpBoxBoxCollisionDetection::isValidFaceAVertexB( hkpFeaturePointCache& fpp ) const
{
	hkVector4 vertexB_inA = fpp.m_vA;
	vertexB_inA.setAbs4( vertexB_inA );
	if ( vertexB_inA.allLessThan3( m_keepRadiusA ) )
	{
		const int featureIndex = fpp.m_featureIndexA;
		fpp.m_distance = fpp.m_normalSign * fpp.m_vA( featureIndex ) - m_radiusA( featureIndex );
		return true;
	}
	return false;
}

hkBool hkpBoxBoxCollisionDetection::isValidFaceBVertexA( hkpFeaturePointCache& fpp ) const
{
	hkVector4 vertexA_inB = fpp.m_vB;
	vertexA_inB.setAbs4( vertexA_inB );
	if ( vertexA_inB.allLessThan3( m_keepRadiusB ) )
	{
		const int featureIndex = fpp.m_featureIndexA - 4;
		fpp.m_distance = -fpp.m_normalSign * fpp.m_vB( featureIndex ) - m_radiusB( featureIndex );
		return true;
	}
	return false;
}

void hkpBoxBoxCollisionDetection::faceAVertexBValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const
{
	fpp.m_featureIndexA = featureIndex;
	hkVector4 dimA; m_aTb.getRotation().getRow( featureIndex, dimA );
	if ( m_dinA( featureIndex ) < 0 )
	{
		fpp.m_normalSign = -1.0f;
		fpp.m_vB = m_radiusB;
	}
	else
	{
		fpp.m_normalSign = 1.0f;
		fpp.m_vB.setNeg4( m_radiusB );
	}
	hkVector4 tweak; tweak.setAll3( -1e-5f );
	hkBoxBoxUtils::selectIfGT3( tweak, 1e-5f, m_dinB, 0.0f );
	tweak.mul4( fpp.m_normalSign );
	dimA.add4( tweak );
	hkVector4Util::mulSigns4( fpp.m_vB, dimA );
	fpp.m_vA._setTransformedPos( m_aTb, fpp.m_vB );
}

void hkpBoxBoxCollisionDetection::faceBVertexAValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp, int featureIndex ) const
{
	fpp.m_featureIndexA = featureIndex + 4;
	hkVector4 dimB = m_aTb.getRotation().getColumn( featureIndex );
	if ( m_dinB( featureIndex ) < 0 )
	{
		fpp.m_normalSign = -1.0f;
		fpp.m_vA.setNeg4( m_radiusA );
	}
	else
	{
		fpp.m_normalSign = 1.0f;
		fpp.m_vA = m_radiusA;
	}
	hkVector4 tweak; tweak.setAll3( 1e-5f );
	hkBoxBoxUtils::selectIfGT3( tweak, -1e-5f, m_dinA, 0.0f );
	tweak.mul4( -fpp.m_normalSign );
	dimB.add4( tweak );
	hkVector4Util::mulSigns4( fpp.m_vA, dimB );
	fpp.m_vB._setTransformedInversePos( m_aTb, fpp.m_vA );
}

void hkpBoxBoxCollisionDetection::edgeEdgeValidationDataFromFeatureIndex( hkpFeaturePointCache& fpp ) const
{
	const int axisA = fpp.m_featureIndexA;
	const int axisB = fpp.m_featureIndexB;
	hkVector4 edge_A_in_A; edge_A_in_A.setZero4();
	edge_A_in_A( axisA ) = 1.0f;
	hkVector4 edge_B_in_A = m_aTb.getRotation().getColumn( axisB );
	hkVector4 normal_in_A; normal_in_A.setCross( edge_A_in_A, edge_B_in_A );
	if ( normal_in_A.dot3( m_dinA ) < 0 )
	{
		normal_in_A.setNeg4( normal_in_A );
	}
	hkVector4 normal_in_B; normal_in_B._setRotatedInverseDir( m_aTb.getRotation(), normal_in_A );
	fpp.m_vA = normal_in_A;
	fpp.m_vB = normal_in_B;
}

void hkpBoxBoxCollisionDetection::removePoint( hkpBoxBoxManifold& manifold, int index ) const
{
	if ( manifold[index].m_featureIdA <= HK_BOXBOX_FACE_B_Z )
	{
		manifold.m_faceVertexFeatureCount--;
	}
	m_contactMgr->removeContactPoint( manifold[index].m_contactPointId, *m_result->m_constraintOwner.val() );
	manifold.removePoint( index );
}

void hkpBoxBoxCollisionDetection::faceAVertexBValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const
{
	fpp.m_featureIndexA = fcp.m_featureIdA;
	fpp.m_normalSign = getNormalSignFromFeatureBitSet( fcp.m_featureIdB );
	const hkVector4& axisMap = getAxisMapFromFeatureBitSet( fcp.m_featureIdB );
	fpp.m_vB.setMul4( m_radiusB, axisMap );
	fpp.m_vA._setTransformedPos( m_aTb, fpp.m_vB );
}

void hkpBoxBoxCollisionDetection::faceBVertexAValidationDataFromFeatureId( hkpFeaturePointCache& fpp, const hkpFeatureContactPoint& fcp ) const
{
	fpp.m_featureIndexA = fcp.m_featureIdA;
	fpp.m_normalSign = getNormalSignFromFeatureBitSet( fcp.m_featureIdB );
	const hkVector4& axisMap = getAxisMapFromFeatureBitSet( fcp.m_featureIdB );
	fpp.m_vA.setMul4( m_radiusA, axisMap );
	fpp.m_vB._setTransformedInversePos( m_aTb, fpp.m_vA );
}

void hkpBoxBoxCollisionDetection::tryToAddPointFaceA( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcpTemplate, hkUint16 planeMask, hkReal closestPointDist ) const
{
	for ( int i = 0; i < 7; i++ )
	{
		const hkUint16 mask = DAT_00e86130[i];
		if ( !( mask & planeMask ) )
		{
			const hkUint16 vertexBits = hkUint16( mask ^ fcpTemplate.m_featureIdB );
			hkpFeatureContactPoint fcpTest = fcpTemplate;
			fcpTest.m_featureIdB = hkUint8( vertexBits | ( fcpTest.m_featureIdB & 0xff0f ) );
			if ( !manifold.findInManifold( fcpTest ) )
			{
				hkpFeaturePointCache fpp;
				faceAVertexBValidationDataFromFeatureId( fpp, fcpTest );
				if ( isValidFaceAVertexB( fpp ) )
				{
					if ( fpp.m_distance >= closestPointDist - 1.192092896e-07F )
					{
						addPoint( manifold, fpp, fcpTest );
					}
				}
			}
		}
	}
}

void hkpBoxBoxCollisionDetection::tryToAddPointFaceB( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcpTemplate, hkUint16 planeMask, hkReal closestPointDist ) const
{
	for ( int i = 0; i < 7; i++ )
	{
		const hkUint16 mask = DAT_00e86130[i];
		if ( !( mask & planeMask ) )
		{
			const hkUint16 vertexBits = hkUint16( mask ^ fcpTemplate.m_featureIdB );
			hkpFeatureContactPoint fcpTest = fcpTemplate;
			fcpTest.m_featureIdB = hkUint8( vertexBits | ( fcpTest.m_featureIdB & 0xff0f ) );
			if ( !manifold.findInManifold( fcpTest ) )
			{
				hkpFeaturePointCache fpp;
				faceBVertexAValidationDataFromFeatureId( fpp, fcpTest );
				if ( isValidFaceBVertexA( fpp ) )
				{
					if ( fpp.m_distance >= closestPointDist - 1.192092896e-07F )
					{
						addPoint( manifold, fpp, fcpTest );
					}
				}
			}
		}
	}
}

void hkpBoxBoxCollisionDetection::findAdditionalManifoldPoints( hkpBoxBoxManifold& manifold, hkpFeatureContactPoint fcpATemplate ) const
{
	if ( manifold.getNumPoints() < 1 )
	{
		return;
	}
	const int firstPointIndex = m_result->getNumContactPoints() - manifold.getNumPoints();
	hkpProcessCdPoint& firstPoint = m_result->getContactPoint( firstPointIndex );
	const hkVector4& normal = firstPoint.m_contact.getNormal();
	hkVector4 axisMapA; axisMapA._setRotatedInverseDir( m_wTa.getRotation(), normal );
	hkVector4 axisMapB; axisMapB._setRotatedInverseDir( m_wTb.getRotation(), normal );
	axisMapA.setNeg4( axisMapA );
	hkVector4 axisMapA_; axisMapA_.setAbs4( axisMapA );
	hkVector4 axisMapB_; axisMapB_.setAbs4( axisMapB );
	int planeIndexA;
	int planeIndexB;
	const int planeMaskA = getMaxPlaneMask3( axisMapA_, axisMapA, planeIndexA );
	const int planeMaskB = getMaxPlaneMask3( axisMapB_, axisMapB, planeIndexB );
	if ( axisMapA_( planeIndexA ) < m_coplanerAngularCosTolerance || axisMapB_( planeIndexB ) < m_coplanerAngularCosTolerance )
	{
		return;
	}
	hkpFeatureContactPoint fcpBTemplate;
	const hkReal signA = m_dinA( planeIndexA );
	const hkReal signB = m_dinB( planeIndexB );
	if ( 0 ) { manifold.m_numPoints = hkUchar( manifold.m_numPoints + manifold.m_faceVertexFeatureCount ); manifold.m_numPoints = hkUchar( manifold.m_numPoints + manifold.m_faceVertexFeatureCount ); manifold.m_numPoints = hkUchar( manifold.m_numPoints + manifold.m_faceVertexFeatureCount ); manifold.m_numPoints = 0; }
	fcpATemplate.m_featureIdB = hkUint8( calcFaceFeatureBitSetFromAxisMap( axisMapB, signA ) );
	fcpBTemplate.m_featureIdB = hkUint8( calcFaceFeatureBitSetFromAxisMap( axisMapA, signB ) );
	fcpATemplate.m_featureIdA = hkUint8( planeIndexA );
	fcpBTemplate.m_featureIdA = hkUint8( planeIndexB + 4 );
	hkReal closestPointDist = 1.0f;
	for ( int i = 0; i < manifold.getNumPoints(); i++ )
	{
		const hkReal candidate = m_result->getContactPoint( firstPointIndex + i ).m_contact.getDistance();
		if ( candidate < closestPointDist )
		{
			closestPointDist = candidate;
		}
	}
	tryToAddPointFaceA( manifold, fcpATemplate, hkUint16( planeMaskB ), closestPointDist );
	tryToAddPointFaceB( manifold, fcpBTemplate, hkUint16( planeMaskA ), closestPointDist );
	if ( manifold.m_faceVertexFeatureCount >= 4 )
	{
		manifold.setComplete( true );
	}
	else
	{
		checkCompleteness( manifold, planeMaskA, planeMaskB );
	}
}





void hkpBoxBoxCollisionDetection::calcManifoldNormal( hkVector4& manifoldN, const hkpFeatureContactPoint& fcp, hkpFeaturePointCache& fpp, hkBool isPointValidated ) const
{
	const int featureIndexA = fpp.m_featureIndexA;
	if ( featureIndexA <= HK_BOXBOX_FACE_A_Z )
	{
		const int axis = fcp.m_featureIdA;
		manifoldN.setZero4();
		manifoldN( axis ) = -fpp.m_normalSign;
	}
	else if ( featureIndexA <= HK_BOXBOX_FACE_B_Z )
	{
		const int axis = fcp.m_featureIdA - 4;
		manifoldN.setMul4( -fpp.m_normalSign, m_aTb.getRotation().getColumn( axis ) );
	}
	else
	{
		if ( isPointValidated )
		{
			manifoldN = fpp.m_nA;
		}
	}
}

void hkpBoxBoxCollisionDetection::refreshManifold( hkpBoxBoxManifold& manifold ) const
{
	for ( int i = 0; i < manifold.getNumPoints(); )
	{
		hkpFeatureContactPoint& fcp = manifold[i]; const int featureIdA = fcp.m_featureIdA;
		if ( featureIdA <= HK_BOXBOX_FACE_A_Z )
		{
			hkpFeaturePointCache fpp;
			faceAVertexBValidationDataFromFeatureId( fpp, fcp );
			if ( isValidFaceAVertexB( fpp ) )
			{
				hkpProcessCdPoint* ccp = m_result->reserveContactPoints();
				m_result->commitContactPoints();
				faceAVertexBContactPointFromFeaturePointCache( *ccp, fcp, fpp );
				i++;
				continue;
			}
		}
		else if ( featureIdA <= HK_BOXBOX_FACE_B_Z )
		{
			hkpFeaturePointCache fpp;
			faceBVertexAValidationDataFromFeatureId( fpp, fcp );
			if ( isValidFaceBVertexA( fpp ) )
			{
				hkpProcessCdPoint* ccp = m_result->reserveContactPoints();
				m_result->commitContactPoints();
				faceBVertexAContactPointFromFeaturePointCache( *ccp, fcp, fpp );
				i++;
				continue;
			}
		}
		else
		{
			hkpFeaturePointCache fpp;
			edgeEdgeValidationDataFromFeatureId( fpp, fcp );
			if ( FUN_00a3cc40( fpp ) )
			{
				hkpProcessCdPoint* ccp = m_result->reserveContactPoints();
				m_result->commitContactPoints();
				edgeEdgeContactPointFromFeaturePointCache( *ccp, fcp, fpp );
				i++;
				continue;
			}
		}
		removePoint( manifold, i );
	}
}

hkBool hkpBoxBoxCollisionDetection::queryManifoldNormalConsistency( hkpBoxBoxManifold& manifold ) const
{
	if ( manifold.getNumPoints() < 2 )
	{
		manifold.m_manifoldNormalInitialized = false;
		return true;
	}
	if ( !manifold.m_manifoldNormalInitialized )
	{
		hkVector4 manifoldNormalB; manifoldNormalB.setRotatedInverseDir( m_aTb.getRotation(), manifold.m_manifoldNormalA );
		manifold.m_manifoldNormalInitialized = true;
		manifold.m_manifoldNormalB = hkVector4Util::packQuaternionIntoInt32( manifoldNormalB );
		return true;
	}
	hkVector4 manifoldNormalB; hkVector4Util::unPackInt32IntoQuaternion( manifold.m_manifoldNormalB, manifoldNormalB );
	hkVector4 manNormalBinA; manNormalBinA._setRotatedDir( m_aTb.getRotation(), manifoldNormalB );
	const hkReal cosAngle = manifold.m_manifoldNormalA.dot3( manNormalBinA );
	return cosAngle < m_manifoldConsistencyCheckAngularCosTolerance;
}

void hkpBoxBoxCollisionDetection::checkManifoldNormalConsistency( hkpBoxBoxManifold& manifold ) const
{
	hkVector4 manifoldNormalInWorld; manifoldNormalInWorld.setRotatedDir( m_wTa.getRotation(), manifold.m_manifoldNormalA );
	int ccpIndex = m_result->getNumContactPoints() - manifold.getNumPoints();
	for ( int i = 0; i < manifold.getNumPoints(); )
	{
		const hkpProcessCdPoint& point = m_result->getContactPoint( ccpIndex );
		const hkReal cosAngle = point.m_contact.getNormal().dot3( manifoldNormalInWorld );
		if ( cosAngle < m_contactNormalAngularCosTolerance )
		{
			m_result->getContactPoint( ccpIndex ) = *( m_result->getEnd() - 1 );
			removePoint( manifold, i );
			m_result->commitContactPoints( -1 );
		}
		else
		{
			i++;
			ccpIndex++;
		}
	}
	if ( manifold.getNumPoints() < 2 )
	{
		manifold.m_manifoldNormalInitialized = false;
	}
	else
	{
		hkVector4 manifoldNormalB; manifoldNormalB._setRotatedInverseDir( m_aTb.getRotation(), manifold.m_manifoldNormalA );
		manifold.m_manifoldNormalB = hkVector4Util::packQuaternionIntoInt32( manifoldNormalB );
		manifold.m_manifoldNormalInitialized = true;
	}
}

// pdb: hkpBoxBoxCollisionDetection::calcManifold | hkpBoxBoxCollisionDetection.obj | fnv360_0822_retail, caller + bridge(call_seq|callee_sim) + skyrim(call_seq), high
void hkpBoxBoxCollisionDetection::hkpBoxBoxCollisionDetection_calcManifold( hkpBoxBoxManifold& manifold ) const
{
	initWorkVariables();
	hkpProcessCdPoint* ccp = m_result->getEnd();
	refreshManifold( manifold );
	hkBool requestManifoldNormal = queryManifoldNormalConsistency( manifold );
	if ( !requestManifoldNormal && manifold.isComplete() )
	{
		return;
	}
	hkResult pointsAvailable;
	if ( manifold.getNumPoints() )
	{
		hkReal minDist = ccp->m_contact.getDistance();
		for ( int i = manifold.getNumPoints() - 1; i > 0; i-- )
		{
			minDist = hkMath::min2( minDist, ccp[i].m_contact.getDistance() );
		}
		minDist -= m_tolerance4(0) * 0.05f;
		hkVector4 minTol4; minTol4.setAll3( minDist );
		pointsAvailable = checkIntersection( minTol4 );
	}
	else
	{
		pointsAvailable = checkIntersection( m_tolerance4 );
	}
	if ( pointsAvailable == HK_SUCCESS )
	{
		hkpFeatureContactPoint fcp;
		hkpFeaturePointCache fpp; fpp.m_nA.setZero4();
		int validCollision = hkpBoxBoxCollisionDetection_findClosestPoint( manifold, fcp, fpp );
		if ( requestManifoldNormal && validCollision )
		{
			calcManifoldNormal( manifold.m_manifoldNormalA, fcp, fpp, validCollision == HK_FINDCLOSESTPOINT_VALID_POINT );
			if ( manifold.m_manifoldNormalInitialized )
			{
				checkManifoldNormalConsistency( manifold );
			}
		}
		if ( validCollision == HK_FINDCLOSESTPOINT_VALID_POINT )
		{
			hkResult result = addPoint( manifold, fpp, fcp );
			if ( result == HK_SUCCESS )
			{
				findAdditionalManifoldPoints( manifold, fcp );
			}
		}
	}
}

} // namespace f3m_00a3e820
