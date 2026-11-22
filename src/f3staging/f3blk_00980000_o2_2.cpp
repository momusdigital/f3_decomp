#include <windows.h>
#include <new>
// src/f3staging/f3blk_00980000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00988180 (community match, verified in this file)
extern unsigned long DAT_0116913c;
extern const char DAT_00e7d880[];
extern const char DAT_00e32798[];
namespace f3m_00988180 {
struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00987ce0
static __declspec(noinline) void FUN_00987ce0(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0116913c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ContactListener
{




    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    int m_08;
    void* m_pObservedSource;
};
struct ListenerOwner
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec;
    CFF9B0SmallArray m_kListeners;
};
// Sets event->m_pObservedSource to owner, calls callback on each non-null listener in reverse with timers, then calls FUN_00987ce0 to remove null entries.
// @fnv 0x00988180
// pdb: hkpEntityCallbackUtil::fireContactPointAddedInternal | hkpEntityCallbackUtil.obj | fnv360_0822_retail, callee_sim, low
// pdb params: entity, event
void __cdecl FUN_00988180(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            unsigned int t1;
            unsigned int uiTimerEnd;
            TimerWriteV(DAT_00e7d880, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_00e32798, uiTimerEnd);
        }
    }
    FUN_00987ce0(kListeners);
}

}   // namespace f3m_00988180

// @f3 0x00989760 (community match, verified in this file)
namespace f3m_00989760 {
struct PtrArray_00989760 {
    void** m_data;
    int m_size;
    void removeAtAndCopy(int index)
    {
        m_size--;
        for (int j = index; j < m_size; j++)
            m_data[j] = m_data[j + 1];
    }
};

// pdb: hkpPhantom::removeNullPhantomListeners | hkpPhantom.obj | tesv_win, call_seq, medium
static __declspec(noinline) void FUN_00989760(PtrArray_00989760* arr)
{
    for (int i = arr->m_size - 1; i >= 0; i--)
    {
        if (arr->m_data[i] == 0)
            arr->removeAtAndCopy(i);
    }
}

void FUN_00989760_caller(PtrArray_00989760* arr)
{
    FUN_00989760(arr);
}
}   // namespace f3m_00989760

// @f3 0x00999b70 (community match, verified in this file)
namespace f3m_00999b70 {



namespace Sol999b70 {

template<class T> struct Pad {
    T value;
    __forceinline Pad() {}
    __forceinline T val() const { return value; }
    __forceinline operator T() const { return val(); }
    __forceinline T operator->() const { return value; }
    __forceinline void operator=(T v) { value=v; }
};


struct Vec {
    __declspec(align(16)) float x;
    float y,z,w;
    __forceinline float& operator()(int i) { return (&x)[i]; }
    __forceinline const float& operator()(int i) const { return (&x)[i]; }
    __forceinline void setSub4(const Vec& a,const Vec& b) { x=a.x-b.x; y=a.y-b.y; z=a.z-b.z; w=a.w-b.w; }
    __forceinline void setMul4(float r,const Vec& a) { float s=r; x=s*a.x; y=s*a.y; z=s*a.z; w=s*a.w; }
    __forceinline void addMul4(float r,const Vec& a) { float s=r; x+=s*a.x; y+=s*a.y; z+=s*a.z; w+=s*a.w; }
    __forceinline void setZero4() { x=y=z=w=0.0f; }
    __forceinline float dot4xyz1(const Vec& a) const { return a.x*x+a.y*y+a.z*z+w; }
    __forceinline float project(const Vec& a) const { return x*a.x+y*a.y+z*a.z+a.w; }
};
struct Transform {
    Vec c0,c1,c2,c3;
    void FUN_00925300(const Transform&,const Transform&);
};
struct Swept {
    Vec m_vCenterOfMass0,m_vCenterOfMass1;
    Vec m_rotation0,m_rotation1;
    Vec m_localCenter;
    __forceinline float getInvDeltaTime() const { return m_vCenterOfMass1(3); }
};
struct Motion {
    Transform m_kTransform;
    Swept m_kSweptTransform;
    Vec m_kDeltaAngle;
    float m_fObjectRadius;
    float unkA4,unkA8,unkAc;
    __forceinline const Transform& getTransform() const { return m_kTransform; }
    __forceinline const Swept& getSweptTransform() const { return m_kSweptTransform; }
};
struct Body {
    const void* m_shape;
    unsigned m_shapeKey;
    const void* m_state;
    const Body* m_parent;
    __forceinline Body() {}
    __forceinline Body(const Body* parent,const Transform* transform) { m_parent=parent; m_state=transform; }
    __forceinline const Motion* GetMotionState() const { return (const Motion*)m_state; }
    __forceinline const void* getShape() const { return m_shape; }
    __forceinline unsigned getShapeKey() const { return m_shapeKey; }
    __forceinline void SetCollisionShapeAndKey(const void* p,unsigned k) { m_shape=p; m_shapeKey=k; }
};
struct Input;
struct Output;
struct Manager {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void processContact(const Body&,const Body&,const Input&,Output&);
};
struct Entry {
    unsigned char m_ucAgentType,m_ucNnTrackType,m_usNumContactPoints,m_iElementCount;
    unsigned short unk04,unk06;
    Manager* m_pContactManager;
    unsigned char unk0c,unk0d,unk0e,unk0f;
    Body* m_kCollidable[2];
    __forceinline Body* getCollidableA() { return m_kCollidable[0]; }
    __forceinline Body* getCollidableB() { return m_kCollidable[1]; }
};
struct PaddedEntry: Entry { int unk18,unk1c; };
struct TimedEntry: Entry { float m_fFloatValue; int unk1c; Vec m_vSeparatingNormal; };
struct Query {
    Pad<const Body*> m_pBodyA;
    Pad<const Body*> m_pBodyB;
    Pad<const Input*> m_pRayCastInput;
    Pad<Manager*> m_pContactManager;
    Transform m_kTransform;
};
struct ProcessQuery: Query {
    Pad<float> m_fSubtypeValue;
    Pad<int> unk54;
    Vec m_vSubtypePosition;
    __forceinline ProcessQuery() {}
};
typedef void* (__cdecl *Cleanup)(Entry*,void*,Manager*,void*);
typedef void (__cdecl *SepNormal)(const Query&,Entry*,void*,Vec&);
typedef void* (__cdecl *Process)(const ProcessQuery&,Entry*,void*,Vec*,Output&);
struct Agent2Funcs {
    void* create; void* penetrate; void* closest; void* cast;
    char flipped,predictive;
};
struct __declspec(align(16)) Agent3Funcs {
    void* create; void* destroy; Cleanup cleanup;
    void* remove; void* commit; void* zombie; void* filter; void* stats;
    void* invalidate; void* warp; SepNormal normal; Process process;
    char predictive,ignore,reuse;
};
struct Agent3Record { Agent3Funcs functions; int symmetric; };
struct Dispatcher {
    void* vtable;
    unsigned short unk04,unk06;
    void* m_defaultAgent;
    void* m_contactFactories[8][8];
    __declspec(align(16)) unsigned m_alternateTypes[32];
    int m_numAgent2Types;
    __declspec(align(16)) unsigned char m_agent2Types[32][32];
    unsigned char m_agent2TypesPred[32][32];
    Agent2Funcs m_agent2Funcs[64];
    int m_numAgent3Types;
    __declspec(align(16)) unsigned char m_agent3Types[32][32];
    __declspec(align(16)) unsigned char m_agent3TypesPred[32][32];
    Agent3Record m_agent3Funcs[16];
    __forceinline Cleanup getAgent3CleanupFunc(int i) { return m_agent3Funcs[i].functions.cleanup; }
    __forceinline SepNormal getAgent3SepNormalFunc(int i) { return m_agent3Funcs[i].functions.normal; }
    __forceinline Process getAgent3ProcessFunc(int i) { return m_agent3Funcs[i].functions.process; }
};
struct Quality { int unk00,unk04,unk08,unk0c; int m_useContinuousPhysics; };
struct Step { float m_uiStartTime,m_fEndTime,m_fTimeStep,m_fInvTimeStep; };
struct Input {
    Dispatcher* m_pCollisionDispatcher;
    float m_tolerance;
    int unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
    Step m_pStepInfo;
    Quality* m_pCollisionQualityInfo;
    __forceinline float getTolerance() const { return m_tolerance; }
};
struct Contact { Vec position,normal; int id,unk24,unk28,unk2c; };
struct Toi {
    Vec position,normal;
    float time,separatingVelocity;
    int unk28,unk2c,unk30,unk34,unk38,unk3c;
    float impulse,internalSolver;
    int unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    __forceinline Toi():time(3.40282e38f),impulse(0.0f),internalSolver(0.0f) {}
};
struct Output {
    Contact* m_pAlignedPairData;
    void* m_pConstraintOwner;
    int unk08,unk0c;
    Contact m_akContactPoints[256];
    Toi m_fTimeOfImpact;
    void* m_akContactRecords;
    __forceinline Output(void* owner) { m_pConstraintOwner=owner; }
    __forceinline void reset() { m_pAlignedPairData=&m_akContactPoints[0]; m_fTimeOfImpact.time=3.40282e38f; m_akContactRecords=0; }
    __forceinline bool isEmpty() const { return m_pAlignedPairData==&m_akContactPoints[0]; }
};
struct Sector { Entry* getBegin() { return (Entry*)this; } Entry* GetStreamEnd() { return (Entry*)((char*)this+512); } };
struct Sectors {
    Sector** m_data; int m_size,m_capacity;
    __forceinline int GetLogicalSize() const { return m_size; }
    __forceinline Sector* operator[](int i) const { return m_data[i]; }
};
struct Track { unsigned m_iBytesUsedInLastSector; Sectors m_kSectors; };
struct PreviousBodies { Body a,b; Transform ta,tb; };
void __cdecl hkSweptTransformUtil_lerp2(const Swept&,float,Transform&);
static __forceinline void fillPrevious(const Query& current,PreviousBodies& b,Query& previous) {
    hkSweptTransformUtil_lerp2(current.m_pBodyA->GetMotionState()->getSweptTransform(),current.m_pRayCastInput->m_pStepInfo.m_uiStartTime,b.ta);
    hkSweptTransformUtil_lerp2(current.m_pBodyB->GetMotionState()->getSweptTransform(),current.m_pRayCastInput->m_pStepInfo.m_uiStartTime,b.tb);
    previous.m_pBodyA=&b.a;
    previous.m_pBodyB=&b.b;
    previous.m_pContactManager=current.m_pContactManager;
    previous.m_pRayCastInput=current.m_pRayCastInput;
    b.a.SetCollisionShapeAndKey(current.m_pBodyA->getShape(),current.m_pBodyA->getShapeKey());
    b.b.SetCollisionShapeAndKey(current.m_pBodyB->getShape(),current.m_pBodyB->getShapeKey());
    ::new (&b.a) Body(current.m_pBodyA,&b.ta);
    ::new (&b.b) Body(current.m_pBodyB,&b.tb);
    previous.m_kTransform.FUN_00925300(b.ta,b.tb);
}
static __forceinline void motionDelta(const Motion& a,const Motion& b,float dt,Vec& out) {
    const Swept& sa=a.getSweptTransform();
    const Swept& sb=b.getSweptTransform();
    Vec da,db;
    da.setSub4(sa.m_vCenterOfMass0,sa.m_vCenterOfMass1);
    db.setSub4(sb.m_vCenterOfMass1,sb.m_vCenterOfMass0);
    float fa=dt*sa.getInvDeltaTime();
    float fb=dt*sb.getInvDeltaTime();
    out.setMul4(fa,da);
    out.addMul4(fb,db);
    out(3)=fa*a.m_kDeltaAngle(3)*a.m_fObjectRadius+fb*b.m_kDeltaAngle(3)*b.m_fObjectRadius;
}
static __forceinline void processEntry(Entry* e,const Input& context,int& skipped,Output& out) {
    switch(e->m_ucAgentType) {
    case 6: {
        Manager* agent=*(Manager**)((PaddedEntry*)e+1);
        agent->processContact(*e->getCollidableA(),*e->getCollidableB(),context,out);
        break;
    }
    case 2: {
        ProcessQuery query;
        query.m_pBodyA=e->getCollidableA(); query.m_pBodyB=e->getCollidableB();
        query.m_pContactManager=e->m_pContactManager;
        query.m_pRayCastInput=&context;
        const Motion* am=query.m_pBodyA->GetMotionState();
        const Motion* bm=query.m_pBodyB->GetMotionState();
        motionDelta(*am,*bm,query.m_pRayCastInput->m_pStepInfo.m_fTimeStep,query.m_vSubtypePosition);
        query.m_kTransform.FUN_00925300(am->getTransform(),bm->getTransform());
        void* data=(PaddedEntry*)e+1;
        query.unk54=0;
        context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)(query,e,data,0,out);
        break;
    }
    case 4: {
        TimedEntry* timed=(TimedEntry*)e;
        ProcessQuery query;
        query.m_pBodyA=e->getCollidableA(); query.m_pBodyB=e->getCollidableB();
        query.m_pContactManager=e->m_pContactManager;
        query.m_pRayCastInput=&context;
        query.unk54=0;
        const Motion* am=query.m_pBodyA->GetMotionState();
        const Motion* bm=query.m_pBodyB->GetMotionState();
        motionDelta(*am,*bm,query.m_pRayCastInput->m_pStepInfo.m_fTimeStep,query.m_vSubtypePosition);
        void* data=timed+1;
        float distance;
        if(timed->m_fFloatValue!=context.m_pStepInfo.m_uiStartTime) {
            if(!context.m_pCollisionQualityInfo->m_useContinuousPhysics) {
                timed->m_fFloatValue=context.m_pStepInfo.m_fEndTime;
                distance=-3.40282e38f;
                timed->m_vSeparatingNormal.setZero4();
                timed->m_vSeparatingNormal(3)=distance;
                goto collide;
            }
            PreviousBodies bodies;
            Query previous;
            fillPrevious(query,bodies,previous);
            context.m_pCollisionDispatcher->getAgent3SepNormalFunc(e->m_ucNnTrackType)(previous,e,data,timed->m_vSeparatingNormal);
        }
        {
            Vec& normal=timed->m_vSeparatingNormal;
            timed->m_fFloatValue=context.m_pStepInfo.m_fEndTime;
            float oldDistance=normal(3);
            float movement=normal.project(query.m_vSubtypePosition);
            distance=oldDistance-movement;
            if(distance>=context.getTolerance()) {
                timed->m_vSeparatingNormal(3)=distance;
                if(e->m_usNumContactPoints)
                    context.m_pCollisionDispatcher->getAgent3CleanupFunc(e->m_ucNnTrackType)(e,data,query.m_pContactManager,out.m_pConstraintOwner);
                ++skipped;
                break;
            }
        }
    collide:
        query.m_fSubtypeValue=distance;
        query.m_kTransform.FUN_00925300(am->getTransform(),bm->getTransform());
        context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)(query,e,data,&timed->m_vSeparatingNormal,out);
        break;
    }
    }
}
struct Bool {
    char value;
    __forceinline operator bool() const { return value!=0; }
};
struct Memory {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual Bool hasMemoryAvailable(int);
    int m_memoryState;
};
extern Memory* DAT_010f3400;
extern unsigned long DAT_0116913c;
extern const char DAT_00e7ddac[];
struct Monitor { char *start,*end,*capacity,*limit; };

// pdb: hkAgentNnMachine_ProcessTrack | hkpAgentNnMachine.obj | fnv360_0822_retail, call_gap + bridge(call_gap_sim|call_dedup) + skyrim(call_gap_sim), high
void __cdecl hkAgentNnMachine_ProcessTrack(void* owner,Track& track,const Input& context) {
    int skipped=0;
    Output result(owner);
    for(int index=0;index<track.m_kSectors.GetLogicalSize();) {
        Sector* sector=track.m_kSectors[index];
        Entry* entry=sector->getBegin();
        ++index;
        Entry* end=(index==track.m_kSectors.GetLogicalSize())?(Entry*)((char*)entry+track.m_iBytesUsedInLastSector):sector->GetStreamEnd();
        for(;entry<end;entry=(Entry*)((char*)entry+entry->m_iElementCount)) {
            Body* a=entry->getCollidableA();
            Body* b=entry->getCollidableB();
            result.reset();
            processEntry(entry,context,skipped,result);
            // hkBool read through its char member: operator bool() compiles to the same test here but changes the
            // x87 operand order of the case-2 setMul4 y lane (a guess at the source; only this spelling matched)
            if(!DAT_010f3400->hasMemoryAvailable(0).value) DAT_010f3400->m_memoryState=1;
            if(DAT_010f3400->m_memoryState==1) return;
            if(!result.isEmpty()) entry->m_pContactManager->processContact(*a,*b,context,result);
        }
    }
    Monitor& stream=*(Monitor*)TlsGetValue(DAT_0116913c);
    char* cur=stream.end;
    if(cur<stream.limit) {
        *(const char**)cur=DAT_00e7ddac;
        *(float*)(cur+4)=float(skipped);
        stream.end=cur+8;
    }
}
}

}   // namespace f3m_00999b70

// @f3 0x009841b0 (community match, verified in this file)
namespace f3m_009841b0 {
// hkpSimpleWorldRayCaster_addBroadPhaseHandle = Havok 5.5.0 hkpSimpleWorldRayCaster::addBroadPhaseHandle (protected virtual, hkpCollide.lib, hkpSimpleWorldRayCaster.obj;
// ?addBroadPhaseHandle@hkpSimpleWorldRayCaster@@MAEMPBVhkpBroadPhaseHandle@@H@Z). The stock release object is byte-identical to the game.
// No .cpp ships: the body is RECONSTRUCTED from the hybrid object's line records 19-41 and locals (col, shape; block: trans),
// on the SDK's verbatim headers and inline bodies (hkFpuVector4.inl, hkMatrix3/hkTransform .inl, hkpCdBody.inl,
// hkpTypedBroadPhaseHandle.inl, hkpCollidable.inl, hkpShape.inl), cut with hktrim.py.
// Target named hkpSimpleWorldRayCaster_addBroadPhaseHandle (the pack symbol): the member is renamed in the class, in its base and at the definition.
namespace f3m_009841b0 {
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;
class hkClass;

class hkBool
{
	public:
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

class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class hkMatrix3;
class hkRotation;
class hkTransform;

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
		__forceinline void _setMul3(const hkMatrix3& a, const hkVector4& b );
		__forceinline void _setRotatedDir(const hkRotation& a, const hkVector4& b);
		__forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
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

class hkAabb
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
	public:
		hkVector4 m_min;
		hkVector4 m_max;
};

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
		__forceinline hkBool castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const;
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

hkBool hkpShape::castRay( const hkpShapeRayCastInput& input, hkpShapeRayCastOutput& output ) const
{
	return castRayImpl( input, output );
}

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

class hkpCdBody
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		friend class hkpCollidable;
		__forceinline const hkTransform& getTransform() const;
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
		__forceinline void* getOwner() const;
	protected:
		enum { OFFSET_INVALID = 127 };
		friend class hkpBroadPhaseBorder;
		hkInt8 m_type;
		hkInt8 m_ownerOffset;
	public:
		hkUint16 m_objectQualityType;
		hkUint32 m_collisionFilterInfo;
};

void* hkpTypedBroadPhaseHandle::getOwner() const
{
	return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
}

class hkpCollidable : public hkpCdBody
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		inline const hkpShape* getShape() const;
	public:
		struct BoundingVolumeData
		{
				static const struct hkInternalClassMember Members[]; struct DefaultStruct;
				                class MustEndWithSemiColon;
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

__forceinline const hkpShape* hkpCollidable::getShape() const
{
	return m_shape;
}

class hkpBroadPhaseCastCollector
{
	public:
		virtual ~hkpBroadPhaseCastCollector() { }
		virtual	hkReal hkpSimpleWorldRayCaster_addBroadPhaseHandle( const hkpBroadPhaseHandle* broadphaseHandle, int castIndex ) = 0;
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

struct hkpWorldRayCastInput
{
	                class MustEndWithSemiColon;
	hkVector4 m_from;
	hkVector4 m_to;
	hkBool m_enableShapeCollectionFilter;
	hkUint32 m_filterInfo;
};

struct hkpWorldRayCastOutput;
class hkpRayCollidableFilter;

class hkpSimpleWorldRayCaster : public hkpBroadPhaseCastCollector
{
	public:
		~hkpSimpleWorldRayCaster(){}
	protected:
		virtual	hkReal hkpSimpleWorldRayCaster_addBroadPhaseHandle( const hkpBroadPhaseHandle* broadPhaseHandle, int castIndex );
	protected:
		const hkpWorldRayCastInput*   m_input;
		const hkpRayCollidableFilter* m_filter;
		hkpWorldRayCastOutput*  m_result;
		hkpShapeRayCastInput    m_shapeInput;
};

struct hkpWorldRayCastOutput: public hkpShapeRayCastOutput
{
	                class MustEndWithSemiColon;
	const hkpCollidable* m_rootCollidable;
};

class hkpRayCollidableFilter
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		virtual ~hkpRayCollidableFilter() { }
		virtual hkBool isCollisionEnabled( const hkpWorldRayCastInput& a, const hkpCollidable& collidableB ) const = 0;
};

// pdb: hkpSimpleWorldRayCaster::addBroadPhaseHandle | hkpSimpleWorldRayCaster.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
hkReal hkpSimpleWorldRayCaster::hkpSimpleWorldRayCaster_addBroadPhaseHandle( const hkpBroadPhaseHandle* broadPhaseHandle, int castIndex )
{
	const hkpCollidable* col = static_cast<hkpCollidable*>( static_cast<const hkpTypedBroadPhaseHandle*>(broadPhaseHandle)->getOwner() );
	const hkpShape* shape = col->getShape();
	if ( shape )
	{
		if ( m_filter->isCollisionEnabled( m_input[castIndex], *col ) )
		{
			const hkTransform& trans = col->getTransform();
			m_shapeInput.m_from._setTransformedInversePos( trans, m_input[castIndex].m_from );
			m_shapeInput.m_to._setTransformedInversePos( trans, m_input[castIndex].m_to );
			m_shapeInput.m_filterInfo = m_input[castIndex].m_filterInfo;
			if ( shape->castRay( m_shapeInput, *m_result ) )
			{
				m_result->m_rootCollidable = col;
				m_result->m_normal._setRotatedDir( trans.getRotation(), m_result->m_normal );
			}
		}
	}
	return m_result->m_hitFraction;
}

}
}   // namespace f3m_009841b0

// @f3 0x0098b8c0 (community match, verified in this file)
namespace f3m_0098b8c0 {
namespace n98b8c0 {
struct Lock {
    void FUN_00908ab0(int flag);
};
extern Lock* DAT_01169318;
}
void FUN_0098b8c0()
{
    if (n98b8c0::DAT_01169318) {
        n98b8c0::DAT_01169318->FUN_00908ab0(1);
        n98b8c0::DAT_01169318 = 0;
    }
}
}   // namespace f3m_0098b8c0

// @f3 0x00996690 (community match, verified in this file)
namespace f3m_00996690 {
// FUN_00996690 = Havok 5.5.0 hkp3AxisSweep::queryBatchAabbSub (hkpInternal.lib, hkp3AxisSweep.obj).
// Written from the SDK headers and the library objects' debug records (hkp3AxisSweep.h/.cpp are not shipped: the
// hkp3AxisSweep class text, addNodePair and yzDisjoint are ours); reduced from sdk_final.cpp
// with hktrim.py. The other declarations and inline bodies are SDK text in reduced form. See note.txt.
namespace f3m_00996690 {
typedef float  hkReal;
typedef signed short	hkInt16;
typedef unsigned char	hkUchar;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
	typedef unsigned long __w64 hkUlong;

template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}

class hkClass;

class hkBool
{
	public:
		inline operator bool() const
		{
			return m_bool != 0;
		}
	private:
		char m_bool;
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
		void deallocateChunk(void*, int nbytes, HK_MEMORY_CLASS );
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
		__forceinline hkArray(T* ptr, int size, int capacity);
	public:
		__forceinline ~hkArray();
		__forceinline T& operator[] (int i);
		__forceinline const T& operator[] (int i) const;
		__forceinline const T& back() const;
		__forceinline int getSize() const;
		__forceinline int getCapacity() const;
		void removeAt(int index);
		int indexOf(const T& t) const;
		__forceinline void pushBack(const T& e);
		__forceinline T& expandOne( );
		typedef T* iterator;
		typedef const T* const_iterator;
		__forceinline const_iterator begin() const;
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
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		                class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
	public:
		T m_storage[N];
};

template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	return m_data[i];
}

template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	return m_data[i];
}

template <typename T>
__forceinline const T& hkArray<T>::back() const
{
	return m_data[ m_size -1 ];
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
__forceinline void hkArray<T>::removeAt(int i)
{
	m_size--;
	m_data[i] = m_data[m_size];
}

template <typename T>
__forceinline int hkArray<T>::indexOf(const T& t) const
{
	for(int i = 0; i < m_size; ++i)
	{
		if( m_data[i] == t )
		{
			return i;
		}
	}
	return -1;
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
__forceinline T& hkArray<T>::expandOne( )
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::_reserveMore( this, sizeof(T) );
	}
	return m_data[m_size++];
}

template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}

template <typename T>
typename hkArray<T>::const_iterator hkArray<T>::begin() const
{
	return m_data;
}

class hkVector4
{
	public:
		                class MustEndWithSemiColon;
	private:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
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

class hkpBroadPhaseHandle
{
	public:
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		                class MustEndWithSemiColon;
		hkUint32 m_id;
};

class hkMultiThreadCheck
{
	public:
		                class MustEndWithSemiColon;
		static const struct hkInternalClassMember Members[]; struct DefaultStruct;
		enum AccessType
		{
			HK_ACCESS_IGNORE = 0,
			HK_ACCESS_RO     = 1,
			HK_ACCESS_RW     = 2,
		};
		enum ReadMode
		{
			THIS_OBJECT_ONLY,
			RECURSIVE
		};
	public:
		enum
		{
			DISABLED = 0xffffffd1,
			MARKED_RO = 0xffffffe1,
			MARKED_RO_SELF_ONLY = 0xffffffc1,
			UNMARKED = 0xfffffff1
		};
		hkUint32 m_threadId;
		hkInt16 m_markCount;
  protected:
		hkUint16 m_markBitStack;
	public:
		static class hkCriticalSection* m_criticalSection;
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

class hkpBroadPhaseHandlePair;
class hkpBroadPhaseCastCollector;
typedef char hkpBroadPhaseAabbCache;

class hkpBroadPhase: public hkReferencedObject
{
	public:
		~hkpBroadPhase();
		                class MustEndWithSemiColon;
		enum BroadPhaseType
		{
			BROADPHASE_16BIT,
			BROADPHASE_32BIT
		};
		virtual BroadPhaseType getType() const = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObject( hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairsOut  ) = 0;
		virtual void addObjectBatch( hkArray<hkpBroadPhaseHandle*>& addObjectList, hkArray< hkAabb >& addAabbList, hkArray<hkpBroadPhaseHandlePair>& newPairs ) = 0;
		virtual void removeObject( hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairsOut ) = 0;
		virtual void removeObjectBatch( hkArray<hkpBroadPhaseHandle*>& removeObjectList, hkArray<hkpBroadPhaseHandlePair>& delPairsOut ) = 0;
		virtual int getNumObjects() = 0;
		virtual void updateAabbs( hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void updateAabbsUint32( hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair>& addedPairs, hkArray<hkpBroadPhaseHandlePair>& removedPairs ) = 0;
		virtual void defragment() = 0;
		virtual void getAllAabbs( hkArray<hkAabb>& allAabbs ) const = 0;
		virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const = 0;
		virtual void getExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const = 0;
		virtual void querySingleAabb( const hkAabb& aabb, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void reQuerySingleObject( const hkpBroadPhaseHandle* object, hkArray<hkpBroadPhaseHandlePair>& pairs_out) const = 0;
		virtual void shiftAllObjects( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void shiftBroadPhase( const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandle*>& objectsEnteringBroadphaseBorder ) = 0;
		virtual void getOffsetLowHigh32bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const = 0;
		struct hkpCastRayInput
		{
			                class MustEndWithSemiColon;
			hkVector4		m_from;
			int       m_numCasts;
			const hkVector4* m_toBase;
			int		  m_toStriding;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
		};
		virtual	void castRay( const hkpCastRayInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const = 0;
		virtual int getAabbCacheSize() const = 0;
		virtual void calcAabbCache( const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		virtual void calcAabbCache( const hkArray<class hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const = 0;
		struct hkpCastAabbInput
		{
			                class MustEndWithSemiColon;
			hkVector4 m_from;
			hkVector4 m_to;
			hkVector4 m_halfExtents;
			const hkpBroadPhaseAabbCache* m_aabbCacheInfo;
		};
		virtual void castAabb( const hkpCastAabbInput& input, hkpBroadPhaseCastCollector& collector ) const = 0;
		virtual void set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale) = 0;
		typedef hkpBroadPhase* (__cdecl *createBroadPhaseFunc)( const hkVector4& worldMin, const hkVector4& worldMax, int numMarkers );
		static createBroadPhaseFunc m_defaultCreationFunction;
	protected:
		mutable hkMultiThreadCheck m_multiThreadCheck;
		class hkCriticalSection *m_criticalSection;
};

class hkpBroadPhaseHandlePair
{
	public:
		                class MustEndWithSemiColon;
		hkpBroadPhaseHandle* m_a;
		hkpBroadPhaseHandle* m_b;
};

class hkp3AxisSweep : public hkpBroadPhase
{
	public:
		typedef hkUint16 BpInt;
		class hkpBpMarker;
		class hkpBpNode
		{
			public:
				                class MustEndWithSemiColon;
				BpInt min_y;
				BpInt min_z;
				BpInt max_y;
				BpInt max_z;
				BpInt min_x;
				BpInt max_x;
				hkpBroadPhaseHandle* m_handle;
				int isMarker() const { return hkUlong(m_handle) & 1; }
				hkpBpMarker& getMarker( hkpBpMarker* markers ) const { return *hkAddByteOffset( markers, hkUlong(m_handle) & ~1 ); }
				hkUint32 yzDisjoint( const hkpBpNode& other ) const
				{
					hkUint32 minA = *reinterpret_cast<const hkUint32*>( &min_y );
					hkUint32 minB = *reinterpret_cast<const hkUint32*>( &other.min_y );
					hkUint32 maxA = *reinterpret_cast<const hkUint32*>( &max_y );
					hkUint32 maxB = *reinterpret_cast<const hkUint32*>( &other.max_y );
					maxA -= minB;
					maxB -= minA;
					maxA |= maxB;
					maxA &= 0x80008000;
					return maxA;
				}
		};
		class hkpBpMarker
		{
			public:
				BpInt m_nodeIndex;
				BpInt m_value;
				hkArray<BpInt> m_overlappingObjects;
		};
		class hkpBpEndPoint
		{
			public:
				                class MustEndWithSemiColon;
				BpInt m_value;
				BpInt m_nodeIndex;
				int isMaxPoint() const { return m_value & 1; }
		};
		class hkpBpAxis
		{
			public:
				hkArray<hkpBpEndPoint> m_endPoints;
		};
	protected:
		__forceinline void addNodePair( const hkpBpNode* n0, const hkpBpNode* n1, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addMode ) const;
		void FUN_00996690( hkUint32* bitFieldOfQueryNodes, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addMode ) const;
	public:
		hkAabb m_aabb;
		hkVector4 m_offsetLow;
		hkVector4 m_offsetHigh;
		hkVector4 m_scale;
		hkVector4 m_offsetLow32bit;
		hkVector4 m_offsetHigh32bit;
		hkVector4 m_scale32bit;
		hkArray<hkpBpNode> m_nodes;
		hkpBpAxis m_axis[3];
		int m_numMarkers;
		int m_ld2NumMarkers;
		hkpBpMarker* m_markers;
		hkReal m_intToFloatFloorCorrection;
};

__forceinline void hkp3AxisSweep::addNodePair( const hkpBpNode* n0, const hkpBpNode* n1, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addMode ) const
{
	if ( n0->yzDisjoint( *n1 ) )
	{
		return;
	}
	if ( !n1->isMarker() )
	{
		if ( !n0->isMarker() )
		{
			hkpBroadPhaseHandlePair& pair = pairsOut.expandOne();
			pair.m_a = n0->m_handle;
			pair.m_b = n1->m_handle;
			return;
		}
		hkAlgorithm::swap( n0, n1 );
	}
	int nodeIndex = n0 - m_nodes.begin();
	hkpBpMarker& marker = n1->getMarker( m_markers );
	if ( addMode )
	{
		marker.m_overlappingObjects.pushBack( BpInt(nodeIndex) );
	}
	else
	{
		int i = marker.m_overlappingObjects.indexOf( BpInt(nodeIndex) );
		marker.m_overlappingObjects.removeAt( i );
	}
}

// pdb: hkp3AxisSweep::queryBatchAabbSub | hkp3AxisSweep.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: bitFieldOfQueryNodes, pairsOut, addMode
void hkp3AxisSweep::FUN_00996690( hkUint32* bitFieldOfQueryNodes, hkArray<hkpBroadPhaseHandlePair>& pairsOut, hkBool addMode ) const
{
	hkInplaceArray<BpInt,256> openQueryNodes;
	hkInplaceArray<BpInt,256> openOtherNodes;
	const hkpBpAxis& axis = m_axis[0];
	const hkpBpEndPoint* epEnd = &axis.m_endPoints.back();
	for ( const hkpBpEndPoint* ep = &axis.m_endPoints[1]; ep < epEnd; ep++ )
	{
		int nodeIndex = ep->m_nodeIndex;
		int isQueryNode = bitFieldOfQueryNodes[nodeIndex >> 5] & ( 1 << ( nodeIndex & 0x1f ) );
		if ( ep->isMaxPoint() )
		{
			hkInplaceArray<BpInt,256>& array = isQueryNode ? openQueryNodes : openOtherNodes;
			int index = array.indexOf( BpInt(nodeIndex) );
			array.removeAt( index );
			continue;
		}
		const hkpBpNode* node = &m_nodes[nodeIndex];
		for ( int oq = 0; oq < openQueryNodes.getSize(); oq++ )
		{
			BpInt oqi = openQueryNodes[oq];
			const hkpBpNode* oqn = &m_nodes[oqi];
			addNodePair( oqn, node, pairsOut, addMode );
		}
		if ( isQueryNode )
		{
			for ( int oo = 0; oo < openOtherNodes.getSize(); oo++ )
			{
				BpInt ooi = openOtherNodes[oo];
				const hkpBpNode* oon = &m_nodes[ooi];
				addNodePair( oon, node, pairsOut, addMode );
			}
			openQueryNodes.pushBack( BpInt(nodeIndex) );
		}
		else
		{
			openOtherNodes.pushBack( BpInt(nodeIndex) );
		}
	}
}

}
}   // namespace f3m_00996690
