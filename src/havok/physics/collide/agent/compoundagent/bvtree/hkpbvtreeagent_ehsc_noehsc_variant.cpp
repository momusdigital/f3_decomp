#include "f3_common.h"
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_d2f5a0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
struct S_d2f5a0_Array
{
    S_d2f5a0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_d2f5a0_Entry* begin()
    {
        return m_data;
    }
    S_d2f5a0_Entry* end()
    {
        return m_data + m_iElementCount;
    }
};
struct __declspec(align(16)) Transform
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;

    Transform(void* apFirst, void* apSecond);
};
struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
extern "C" Global* __cdecl FUN_00c85750();

void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD);
struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D2FA00MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" D2FA00MemoryRouter& __cdecl FUN_00c85750();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    virtual ~D2FA00ReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

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
};
class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};
struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};
template <class T> class hkArrayD2F5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T* begin()
    {
        return m_data;
    }
    T* end()
    {
        return m_data + m_iElementCount;
    }
};

#include <windows.h>
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(unsigned int);

struct S312_Split
{
    const char* m_cmd;
    DWORD m_uiStartTicks;
    DWORD unk08;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile DWORD t = (DWORD)__rdtsc();
        m_uiStartTicks = t;
    }
};
struct S312_Stream
{
    DWORD unk00;
    char* m_kRayEnd;
    DWORD unk08;
    char* m_capMinus16;
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_capMinus16;
    }
};
inline S312_Stream& S312_getInstance()
{
    return *(S312_Stream*)TlsGetValue(DAT_0126835c);
}

struct S312_Shape
{
    void* vt;
    DWORD unk04, unk08;
    DWORD m_type;
};
struct S312_Body
{
    S312_Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    S312_Body* m_parent;
    void SetCollisionShapeAndKey(S312_Shape* s, int k)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = k;
    }
};

struct S312_Container
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual S312_Shape* GetShapeForKey(int key, void* buf);
};
struct S312_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void free(void* p, int n);
    void ReturnMemory(int* p, int n)
    {
        free(p, n * sizeof(int));
    }
};
struct S312_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capAndFlags;
};
inline void S312_dealloc(S312_Alloc* al, int* p, int n);
struct S312_InplaceArray : S312_Array
{
    int m_kStorage[128];
    S312_InplaceArray()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_capAndFlags = (int)0x80000080;
    }
    void ClearAndRelease(S312_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_capAndFlags & 0x80000000) == 0)
            a.ReturnMemory(m_data, m_capAndFlags & 0x3fffffff);
        m_data = 0;
        m_capAndFlags = (int)0x80000000;
    }
    ~S312_InplaceArray()
    {
        ClearAndRelease((S312_Alloc&)fnvc_adapt::FUN_00c85750().heap());
    }
};
struct S312_Input;
struct S312_Filter
{
    virtual void v0();
    virtual bool* IsCollisionEnabled(bool* res, S312_Input* input, S312_Body* a, S312_Body* b, S312_Container* c,
                                     int key);
};
struct S312_FilterHolder
{
    DWORD unk0, unk4, unk8;
    S312_Filter m_iFilter;
};
typedef void(__cdecl* S312_Func)(S312_Body*, S312_Body*, S312_Input*, void*);
struct S312_Input
{
    unsigned char* m_pCollisionDispatcher;
    DWORD unk04, unk08;
    S312_FilterHolder* m_iFilter;
};

inline void S312_dealloc(S312_Alloc* al, int* p, int n)
{
    al->free(p, n * sizeof(int));
}

// @f3 0x009ba3c0 (community match, verified in this file)
namespace NativeBv312 {

struct Body;struct Input;struct Collector;struct Shape;struct Container;

struct __declspec(align(16)) Vector {float x,y,z,w;};

struct __declspec(align(16)) Matrix {

 Vector x,y,z,translation;

 void FUN_00925300(const Matrix&,const Matrix&);

};

struct __declspec(align(16)) Aabb {Vector minimum,maximum;};

struct Bool {char value;operator bool()const{return value!=0;}};

struct ThreadMemory {void FUN_008f6d90(void*,int,int);};

extern unsigned long DAT_010f3170;

extern unsigned long DAT_0116913c;

extern const char DAT_00e7eb94[],DAT_00e7e9a0[],DAT_00e7eb84[],DAT_00e0811c[];

struct MonitorEvent {const char* tag;unsigned start;unsigned other;};

struct MonitorBegin:MonitorEvent {const char* child;};

struct Monitor {int unknown00;char* current;int unknown08;char* end;};

inline Monitor& monitor(){return *static_cast<Monitor*>(TlsGetValue(DAT_0116913c));}

inline void beginMonitor(){

 Monitor& stream=monitor();

 if(stream.current<stream.end){

  MonitorBegin* cmd=reinterpret_cast<MonitorBegin*>(stream.current);

  cmd->tag=DAT_00e7eb94;cmd->child=DAT_00e7e9a0;

  _ReadWriteBarrier();

  unsigned ticks;
  __asm {
    rdtsc
    mov dword ptr[ticks], eax
  }
  cmd->start=ticks;

  stream.current=reinterpret_cast<char*>(cmd+1);

 }

}

inline void splitMonitor(const char* tag){

 Monitor& stream=monitor();

 if(stream.current<stream.end){

  MonitorEvent* cmd=reinterpret_cast<MonitorEvent*>(stream.current);

  cmd->tag=tag;

  _ReadWriteBarrier();

  unsigned ticks;
  __asm {
    rdtsc
    mov dword ptr[ticks], eax
  }
  cmd->start=ticks;

  stream.current=reinterpret_cast<char*>(cmd+1);

 }

}

struct Keys {

 unsigned* data;int size;int capacityFlags;unsigned storage[128];

 Keys():data(storage),size(0),capacityFlags(0x80000080){}

 ~Keys(){

  if((capacityFlags & 0x80000000)==0){

   int capacity=capacityFlags&0x3fffffff;

   ThreadMemory* memory=static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));

   memory->FUN_008f6d90(data,capacity*4,0x17);

  }

 }

};

struct __declspec(align(16)) ShapeBuffer {unsigned char bytes[512];};

struct Container {

 virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();

 virtual const Shape* child(unsigned,ShapeBuffer&)const;

};

struct Shape {

 virtual void slot00();virtual void slot04();virtual void slot08();virtual void slot0c();virtual void slot10();

 virtual const Container* container()const;

 virtual void slot18();

 virtual void aabb(const Matrix&,float,Aabb&)const;

 virtual void slot20();virtual void slot24();virtual void slot28();

 virtual void query(const Aabb&,Keys&)const;

 int unknown04,unknown08;unsigned type;

};

struct Body {

 const Shape* shape;unsigned key;const void* matrix;const Body* parent;

 

 void set(const Shape* s,unsigned k){shape=s;key=k;}

};

struct Filter {

 virtual void slot00();

 virtual Bool enabled(const Input&,const Body&,const Body&,const Container&,unsigned)const;

};

typedef void(__cdecl* DispatchFn)(const Body&,const Body&,const Input&,Collector&);

struct AgentFunctions {void* create;DispatchFn penetrations;void* closest;void* cast;unsigned predictive;};

struct Dispatcher {

 unsigned unknown000,unknown004,unknown008,unknown00c,unknown010,unknown014,unknown018,unknown01c;

 unsigned unknown020,unknown024,unknown028,unknown02c,unknown030,unknown034,unknown038,unknown03c;

 unsigned unknown040,unknown044,unknown048,unknown04c,unknown050,unknown054,unknown058,unknown05c;

 unsigned unknown060,unknown064,unknown068,unknown06c,unknown070,unknown074,unknown078,unknown07c;

 unsigned unknown080,unknown084,unknown088,unknown08c,unknown090,unknown094,unknown098,unknown09c;

 unsigned unknown0a0,unknown0a4,unknown0a8,unknown0ac,unknown0b0,unknown0b4,unknown0b8,unknown0bc;

 unsigned unknown0c0,unknown0c4,unknown0c8,unknown0cc,unknown0d0,unknown0d4,unknown0d8,unknown0dc;

 unsigned unknown0e0,unknown0e4,unknown0e8,unknown0ec,unknown0f0,unknown0f4,unknown0f8,unknown0fc;

 unsigned unknown100,unknown104,unknown108,unknown10c,unknown110,unknown114,unknown118,unknown11c;

 unsigned unknown120,unknown124,unknown128,unknown12c,unknown130,unknown134,unknown138,unknown13c;

 unsigned unknown140,unknown144,unknown148,unknown14c,unknown150,unknown154,unknown158,unknown15c;

 unsigned unknown160,unknown164,unknown168,unknown16c,unknown170,unknown174,unknown178,unknown17c;

 unsigned unknown180,unknown184,unknown188,unknown18c,unknown190,unknown194,unknown198,unknown19c;

 unsigned char agent2Types[32][32];

 unsigned char agent3Types[32][32];

 AgentFunctions agents[32];

 DispatchFn function(unsigned a,unsigned b)const{return agents[agent2Types[a][b]].penetrations;}

};

struct Input {Dispatcher* dispatcher;float tolerance;const Filter* filter;};

struct Collector {virtual void slot00();Bool earlyOut;};

}

// pdb: hkpBvTreeAgent::staticGetPenetrations | hkpBvTreeAgent.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA,void* apB,void* apC,void* apD){

 using namespace NativeBv312;

 beginMonitor();

 const Body& bodyA=*static_cast<const Body*>(apA);

 const Body& bodyB=*static_cast<const Body*>(apB);

 const Input& input=*static_cast<const Input*>(apC);

 Collector& collector=*static_cast<Collector*>(apD);

 Matrix relative;

 relative.FUN_00925300(*static_cast<const Matrix*>(bodyB.matrix),*static_cast<const Matrix*>(bodyA.matrix));

 Aabb bounds;

 bodyA.shape->aabb(relative,input.tolerance,bounds);

 const Shape* tree=bodyB.shape;

 Keys hits;

 tree->query(bounds,hits);

 splitMonitor(DAT_00e7eb84);

 unsigned typeA=bodyA.shape->type;

 {
 const unsigned* it=hits.data;

 const unsigned* end=hits.data+hits.size;

 Body modified; modified.matrix=bodyB.matrix; modified.parent=&bodyB;

 const Container* container=tree->container();

 ShapeBuffer buffer;

 while(it!=end){

  if(input.filter->enabled(input,bodyA,bodyB,*container,*it)){

   const Shape* shape=container->child(*it,buffer);

   modified.set(shape,*it);

   DispatchFn call=input.dispatcher->function(typeA,shape->type);

   call(bodyA,modified,input,collector);

   if(collector.earlyOut)break;

  }

  ++it;

 }

 }
 splitMonitor(DAT_00e0811c);

}

