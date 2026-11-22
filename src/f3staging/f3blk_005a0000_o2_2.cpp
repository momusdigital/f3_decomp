#include <windows.h>
// src/f3staging/f3blk_005a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x005bab10 (community match, verified in this file)
namespace f3m_005bab10 {

struct Table { void (__thiscall* f0)(void*); void (__thiscall* f1)(void*); void (__thiscall* release)(void*,void*); };
extern const Table DAT_00e008ec;
extern const Table DAT_00e008e4;
extern const Table DAT_00e008d8;
extern const Table DAT_00dffec0;
extern const Table DAT_00dffe50;
extern const Table DAT_00e008c4;
extern const Table DAT_00dfff08;
extern const Table DAT_00dffe8c;
extern const Table DAT_00dffe78;
extern const Table DAT_00dffe64;
extern const Table DAT_00dffef4;
extern const Table DAT_00db7764;
extern long DAT_011f4400;
struct Base { virtual ~Base(); int unk04,unk08,unk0c,unk10,unk14; void FUN_00455a70(); };
struct Ref { int refs; virtual ~Ref() { InterlockedDecrement(&DAT_011f4400); } };
struct Side { virtual void sideMethod(); };
struct Arr { const Table* vptr; void* data; unsigned int count,capacity;
 void Clear() { if(data) { vptr->release(this,data); data=0; capacity=0; count=0; } }
};
struct A28 : Arr { ~A28() { vptr=&DAT_00dffef4; if(data) { DAT_00dffef4.release(this,data); data=0; capacity=0; count=0; } } };
struct A38 : Arr { ~A38() { vptr=&DAT_00dffe64; if(data) { DAT_00dffe64.release(this,data); data=0; capacity=0; count=0; } } };
struct A48 : Arr { ~A48() { vptr=&DAT_00dffe78; if(data) { DAT_00dffe78.release(this,data); data=0; capacity=0; count=0; } } };
struct A58 : Arr { ~A58() { vptr=&DAT_00dffe8c; if(data) { DAT_00dffe8c.release(this,data); data=0; capacity=0; count=0; } } };
struct A68 : Arr { ~A68() { vptr=&DAT_00dfff08; if(data) { DAT_00dfff08.release(this,data); data=0; capacity=0; count=0; } } };
struct A78 : Arr { ~A78() { vptr=&DAT_00dffe50; if(data) { DAT_00dffe50.release(this,data); data=0; capacity=0; count=0; } } };
struct A98 : Arr { ~A98() { vptr=&DAT_00dffe50; if(data) { DAT_00dffe50.release(this,data); data=0; capacity=0; count=0; } } };
struct Ae4 : Arr { ~Ae4() { vptr=&DAT_00dffe50; if(data) { DAT_00dffe50.release(this,data); data=0; capacity=0; count=0; } } };
struct Af4 : Arr { ~Af4() { vptr=&DAT_00dffec0; if(data) { DAT_00dffec0.release(this,data); data=0; capacity=0; count=0; } } };
struct A88 { int unk00,unk04,unk08,unk0c; void FUN_005b8f90(); ~A88(){ FUN_005b8f90(); } };
struct Ad0 : Arr { void FUN_005e5240(void*,unsigned int); ~Ad0() { vptr=&DAT_00e008c4; if(data) { FUN_005e5240(data,count); vptr->release(this,data); data=0; capacity=0; count=0; } } };
struct Aux { int unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4,unkc8,unkcc; void FUN_005c3620(); };
struct Obj { virtual void destroy(bool); void FUN_005d89b0(void*); };
struct Owner : Base, Side, Ref {
 int unk24;
 A28 a28; A38 a38; A48 a48; A58 a58; A68 a68; A78 a78; A88 a88; A98 a98;
 Aux aa8; Ad0 ad0; Obj* oe0; Ae4 ae4; Af4 af4; Obj* o104;
 ~Owner();
};
// pdb: NavMesh::~NavMesh | NavMesh.obj | fnv360_0822_retail, call_seq, medium
Owner::~Owner() {

 a28.Clear(); a38.Clear(); a48.Clear(); a58.Clear(); a78.Clear();
 aa8.FUN_005c3620();
 if(o104) o104->FUN_005d89b0(0);
 if(oe0) oe0->destroy(true);
}
}   // namespace f3m_005bab10

// @f3 0x005a72a0 (community match, verified in this file)
namespace f3m_005a72a0 {
namespace FormCapability {

struct CapabilityData {
    bool FUN_00403500() const;
    bool FUN_00403550() const;
    bool FUN_004035a0() const;
};

struct Form {
    unsigned int field00;
    unsigned char type;
    unsigned char field05, field06, field07;
    unsigned int field08, field0c, field10, field14, field18, field1c, field20;
    CapabilityData capabilities;

    bool FUN_0047cb20() const;

    unsigned char ByteAt(unsigned int offset) const
    {
        return reinterpret_cast<const unsigned char*>(this)[offset];
    }
};

// pdb: TESPackage::FormMatchesPackageObjectType | Package.obj | fnv360_0822_retail, call_gap, low
// pdb params: apForm, aeType
bool __cdecl FUN_005a72a0(const Form* form, int kind)
{
    bool allowed = false;
    if (form && kind) {
        switch (form->type) {
        case 21:
            if (kind == 1)
                allowed = true;
            break;
        case 25:
            if (kind == 3)
                allowed = true;
            break;
        case 27:
            if (kind == 5)
                allowed = true;
            break;
        case 28:
            if (kind == 6)
                allowed = true;
            break;
        case 30:
            if (kind == 8)
                allowed = true;
            break;
        case 31:
        case 50:
            if (kind == 9)
                allowed = true;
            break;
        case 38:
            if (kind == 10)
                allowed = true;
            break;
        case 39:
            if (kind == 11)
                allowed = true;
            break;
        case 42:
            if (kind == 14 || kind == 28)
                allowed = true;
            break;
        case 43:
            if (kind == 15 || kind == 28)
                allowed = true;
            break;
        case 46:
            if (kind == 16)
                allowed = true;
            break;
        case 47:
            if (kind == 17 || (kind == 18 && form->FUN_0047cb20()))
                allowed = true;
            break;
        case 29:
            if (kind == 7 || (kind == 18 && (form->ByteAt(0xa0) & 2)))
                allowed = true;
            break;
        case 26:
            if (kind == 4 || kind == 20)
                allowed = true;
            break;
        case 24:
            switch (kind) {
            case 2:
            case 19:
            case 20:
                allowed = true;
                break;
            }
            break;
        case 40:
            switch (kind) {
            case 12:
            case 19:
            case 20:
                allowed = true;
                break;
            case 22:
            case 23: {
                const unsigned char subtype = form->ByteAt(0xf4);
                if ((subtype <= 2 && kind == 22) ||
                    (static_cast<unsigned char>(subtype - 3) <= 9 && kind == 23))
                    allowed = true;
                break;
            }
            }
            break;
        case 41:
            switch (kind) {
            case 13:
            case 19:
            case 20:
                allowed = true;
                break;
            }
            break;
        case 20:
            switch (kind) {
            case 24:
                allowed = true;
                break;
            case 25:
            case 26:
            case 27:
                switch (kind) {
                case 25:
                    if (form->capabilities.FUN_00403500())
                        allowed = true;
                    break;
                case 26:
                    if (form->capabilities.FUN_00403550())
                        allowed = true;
                    break;
                case 27:
                    if (form->capabilities.FUN_004035a0())
                        allowed = true;
                    break;
                }
                break;
            }
            break;
        }
    }
    return allowed;
}

}
}   // namespace f3m_005a72a0

// @f3 0x005accf0 (community match, verified in this file)
namespace f3m_005accf0 {
struct Owner5accf0 {
    char unk00;
    int unk04;
    int unk08;
    void FUN_005accf0(int a2);
};
// pdb: PackageLocation::SetLocType | PackageLocation.obj | fnv360_0822_debug, caller, low, conflict (skyrim: PackageLocation::SetRadius)
// pdb params: aeLoctype
void Owner5accf0::FUN_005accf0(int a2)
{
    if (a2 != unk00)
    {
        unk00 = a2;
        switch (unk00)
        {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            unk08 = 0;
            break;
        case 1:
            unk08 = 0;
            unk04 = 0;
            break;
        }
    }
}
}   // namespace f3m_005accf0

// @f3 0x005b8620 (community match, verified in this file)
namespace f3m_005b8620 {
struct Array5b8620 {
 void** table; void* buffer; unsigned count; unsigned capacity;
 void FUN_005b8560(void*,void*,unsigned);
 void FUN_005b8620(unsigned,unsigned);
};
// pdb: BSSimpleArray<SandBoxChoiceListItem,1024>::_ReallocateBuffer | SandBoxPackage.obj | fnv360_0822_debug, caller, low
// pdb params: aiNewSize, aiCopyCount
void Array5b8620::FUN_005b8620(unsigned amount,unsigned copyCount) {
 if(buffer) {
  if(copyCount==capacity) { buffer=((void* (__thiscall *)(Array5b8620*,void*,unsigned))table[3])(this,buffer,amount); return; }
  void* replacement=((void* (__thiscall *)(Array5b8620*,unsigned))table[1])(this,amount);
  FUN_005b8560(replacement,buffer,copyCount);
  ((void (__thiscall *)(Array5b8620*,void*))table[2])(this,buffer);
  buffer=replacement;
 } else { buffer=((void* (__thiscall *)(Array5b8620*,unsigned))table[1])(this,amount); capacity=amount; }
}
}   // namespace f3m_005b8620

// @f3 0x005a22f0 (community match, verified in this file)
#include <windows.h>
namespace f3m_005a22f0 {
namespace Release160{
struct Heap160{void FUN_0086ba60(void*);};extern Heap160 DAT_01090a78;
struct Owner160{unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;volatile long references;void FUN_005a2110();void FUN_005a22f0();};
// pdb: ActorCause::DecRefCount | ActorCause.obj | fnv360_0721_beta, call_gap, low, conflict (bridge: NiPointer<ActorCause>::operator=)
void Owner160::FUN_005a22f0(){if(!InterlockedDecrement(&references)&&this){FUN_005a2110();DAT_01090a78.FUN_0086ba60(this);}}
}
}   // namespace f3m_005a22f0

// @f3 0x005aff50 (community match, verified in this file)
#include <windows.h>
namespace f3m_005aff50 {

struct RefFF50 {
    virtual void unk00();
    virtual void DeleteThis();
    long refs;
    void IncRefCount() { InterlockedIncrement(&refs); }
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};

class FUN_005af350 {
public:
    virtual ~FUN_005af350();
    unsigned int unk04;
    float value08;
    unsigned int value0C;
    float value10;
    unsigned char flag14;
    __declspec(noinline) FUN_005af350(unsigned int first, float second);
};

class FUN_005aff50 : public FUN_005af350 {
public:
    virtual ~FUN_005aff50();
    NiPointer<RefFF50> reference;
    unsigned int kind;
    bool enabled;
    bool ready;

    void FUN_005afa40(unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h, float i, unsigned int j);

    FUN_005aff50(unsigned int a, float b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h, float i, unsigned int j, bool k);
};

// pdb: BSTempEffectDebris::BSTempEffectDebris | BSTempEffectDebris.obj | fnv360_0822_retail, call_gap, low
// pdb params: apCell, afLifetime, apFilename, apSourceRef, aPosition, aRotation, aStartLinearVelocity, aStartAngularVelocity, afScale, bUseCache, abAddDebrisCount
FUN_005aff50::FUN_005aff50(unsigned int a, float b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h, float i, unsigned int j, bool k)
    : FUN_005af350(a, b)
{
    reference = 0;
    kind = c;
    enabled = k;
    ready = false;
    FUN_005afa40(d, e, f, g, h, i, j);
}
}   // namespace f3m_005aff50

// @f3 0x005a6550 (community match, verified in this file)
namespace f3m_005a6550 {
namespace q162 {
struct P3 { float x,y,z; };
struct BaseRec { int unk00; unsigned char type; };
struct Src { int FUN_004a0890(); };
struct Part { char pad[0x30]; Src* src; };
struct PartList { Part* FUN_0040bdd0(); };
struct Ref {
    virtual void V000();
    virtual void V004();
    virtual void V008();
    virtual void V00c();
    virtual void V010();
    virtual void V014();
    virtual void V018();
    virtual void V01c();
    virtual void V020();
    virtual void V024();
    virtual void V028();
    virtual void V02c();
    virtual void V030();
    virtual void V034();
    virtual void V038();
    virtual void V03c();
    virtual void V040();
    virtual void V044();
    virtual void V048();
    virtual void V04c();
    virtual void V050();
    virtual void V054();
    virtual void V058();
    virtual void V05c();
    virtual void V060();
    virtual void V064();
    virtual void V068();
    virtual void V06c();
    virtual void V070();
    virtual void V074();
    virtual void V078();
    virtual void V07c();
    virtual void V080();
    virtual void V084();
    virtual void V088();
    virtual void V08c();
    virtual void V090();
    virtual void V094();
    virtual void V098();
    virtual void V09c();
    virtual void V0a0();
    virtual void V0a4();
    virtual void V0a8();
    virtual void V0ac();
    virtual void V0b0();
    virtual void V0b4();
    virtual void V0b8();
    virtual void V0bc();
    virtual void V0c0();
    virtual void V0c4();
    virtual void V0c8();
    virtual void V0cc();
    virtual void V0d0();
    virtual void V0d4();
    virtual void V0d8();
    virtual void V0dc();
    virtual void V0e0();
    virtual void V0e4();
    virtual void V0e8();
    virtual void V0ec();
    virtual void V0f0();
    virtual void V0f4();
    virtual void V0f8();
    virtual void V0fc();
    virtual bool IsActor();
    virtual void V104();
    virtual void V108();
    virtual void V10c();
    virtual void V110();
    virtual void V114();
    virtual void V118();
    virtual void V11c();
    virtual void V120();
    virtual void V124();
    virtual void V128();
    virtual void V12c();
    virtual void V130();
    virtual void V134();
    virtual void V138();
    virtual void V13c();
    virtual void V140();
    virtual void V144();
    virtual void V148();
    virtual void V14c();
    virtual void V150();
    virtual void V154();
    virtual void V158();
    virtual void V15c();
    virtual void V160();
    virtual void V164();
    virtual void V168();
    virtual void V16c();
    virtual void V170();
    virtual void V174();
    virtual void V178();
    virtual void V17c();
    virtual void V180();
    virtual void V184();
    virtual void V188();
    virtual void V18c();
    virtual void V190();
    virtual void V194();
    virtual void V198();
    virtual void V19c();
    virtual void V1a0();
    virtual void V1a4();
    virtual void V1a8();
    virtual void V1ac();
    virtual void V1b0();
    virtual void V1b4();
    virtual void V1b8();
    virtual void V1bc();
    virtual void V1c0();
    virtual void V1c4();
    virtual void V1c8();
    virtual void V1cc();
    virtual void V1d0();
    virtual void V1d4();
    virtual void V1d8();
    virtual P3 Sample();
    virtual void V1e0();
    virtual void V1e4();
    virtual void V1e8();
    virtual void V1ec();
    virtual void V1f0();
    virtual P3* Position();
    virtual void V1f8();
    virtual void V1fc();
    virtual void V200();
    virtual void V204();
    virtual void V208();
    virtual void V20c();
    virtual void V210();
    virtual void V214();
    virtual void V218();
    virtual void V21c();
    virtual void V220();
    virtual void V224();
    virtual void V228();
    virtual void V22c();
    virtual void V230();
    virtual void V234();
    virtual void V238();
    virtual void V23c();
    virtual void V240();
    virtual void V244();
    virtual void V248();
    virtual void V24c();
    virtual void V250();
    virtual void V254();
    virtual void V258();
    virtual void V25c();
    virtual void V260();
    virtual void V264();
    virtual void V268();
    virtual void V26c();
    virtual void V270();
    virtual void V274();
    virtual void V278();
    virtual void V27c();
    virtual void V280();
    virtual void V284();
    virtual void V288();
    virtual void V28c();
    virtual void V290();
    virtual void V294();
    virtual void V298();
    virtual void V29c();
    virtual void V2a0();
    virtual void V2a4();
    virtual void V2a8();
    virtual void V2ac();
    virtual void V2b0();
    virtual void V2b4();
    virtual void V2b8();
    virtual void V2bc();
    virtual void V2c0();
    virtual void V2c4();
    virtual Ref* Resolve();
    virtual void V2cc();
    virtual void V2d0();
    virtual void V2d4();
    virtual void V2d8();
    virtual void V2dc();
    virtual void V2e0();
    virtual void V2e4();
    virtual void V2e8();
    virtual void V2ec();
    virtual void V2f0();
    virtual void V2f4();
    virtual void V2f8();
    virtual void V2fc();
    virtual void V300();
    virtual void V304();
    virtual void V308();
    virtual void V30c();
    virtual void V310();
    virtual void V314();
    virtual void V318();
    virtual void V31c();
    virtual void V320();
    virtual void V324();
    virtual void V328();
    virtual void V32c();
    virtual void V330();
    virtual void V334();
    virtual void V338();
    virtual void V33c();
    virtual void V340();
    virtual void V344();
    virtual void V348();
    virtual void V34c();
    virtual void V350();
    virtual void V354();
    virtual void V358();
    virtual void V35c();
    virtual void V360();
    virtual void V364();
    virtual void V368();
    virtual void V36c();
    virtual void V370();
    virtual void V374();
    virtual void V378();
    virtual float Measure();
    int unk04,unk08,unk0C,unk10,unk14,unk18;
    BaseRec* base;
    int unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C;
    PartList parts;
    bool FUN_004e7210();
    float FUN_004e7d40();
    float FUN_006fa060();
};
}
namespace q162 {
extern BaseRec* DAT_01071664;
extern BaseRec* DAT_01071660;
extern int FUN_00f5e938;
struct Owner {
    int unk00,unk04,unk08,unk0C,unk10,unk14;
    int mode;
    int unk1C;
    unsigned char type;
    char unk21,unk22,unk23;
    int unk24,unk28,unk2C;
    Src* src;
    float FUN_005a6550(Ref* obj, int unused);
};
// pdb: TESPackage::GetPackageRadiusActorToRefTarget | Package.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apMobileObject, abSecondLoc
float Owner::FUN_005a6550(Ref* obj, int unused)
{
    int result = 0;
    Ref* actor = 0;
    if (obj->IsActor()) actor = obj;
    Ref* target = obj->Resolve();
    if (target) {
        if (target->FUN_004e7210()) result = 10;
        else if (target->base == DAT_01071664 || target->base == DAT_01071660) result = 20;
        else {
            Part* part = actor->parts.FUN_0040bdd0();
            Src* s = 0;
            if (type == 0x1c && part) s = part->src;
            if (!s && !(src && mode != 0x1a)) s = 0; else if (!s) s = src;
            if (s) result = s->FUN_004a0890();
            if (!result && !target->IsActor()) {
                result = (int)target->FUN_004e7d40();
                switch (target->base->type) {
                case 0x15: case 0x1b: case 0x20: case 0x21:
                    break;
                default:
                    if (actor) {
                        float measured = actor->Measure();
                        result += (int)measured;
                        double z = actor->Position()->z;
                        float adjusted = (float)(actor->FUN_006fa060() + z - measured);
                        float tz = target->Position()->z;
                        if (adjusted > tz) {
                            double delta = adjusted - tz;
                            if (delta < obj->Sample().z * 0.5)
                                result += (int)(obj->Sample().z * 0.5);
                        }
                    }
                    break;
                }
            }
        }
    }
    if (!result) result = FUN_00f5e938;
    return (float)result;
}
}
}   // namespace f3m_005a6550


// @f3 0x005a11e0 (community match, verified in this file)
#include <windows.h>
extern unsigned char DAT_01073d7c;
extern const float DAT_00f65f18;
extern const double DAT_00dbe7c0;
extern DWORD DAT_010f3170;
extern int DAT_01066b94;
namespace f3m_005a11e0 {

extern "C" void __cdecl FUN_00901f10(void*,int);

namespace CollisionPrimitiveBuild {
struct Point3 {
    float x,y,z;
    Point3() {}
    Point3(float a,float b,float c):x(a),y(b),z(c){}
    __forceinline float& operator[](int i) {
        return *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this)+i*sizeof(float));
    }
    __forceinline const float& operator[](int i) const {
        return *reinterpret_cast<const float*>(reinterpret_cast<const unsigned char*>(this)+i*sizeof(float));
    }
    Point3(const Point3& p):x(p.x),y(p.y),z(p.z){}
};
static __forceinline Point3 Scaled(const Point3& p,double scale) {
    return Point3(float(p[0]*scale),float(p[1]*scale),float(p[2]*scale));
}
static __forceinline void ScaleInPlace(Point3& p,double units,float scale) {
    p[0]=float(float(p[0]*units)*scale);
    p[1]=float(float(p[1]*units)*scale);
    p[2]=float(float(p[2]*units)*scale);
}
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    Vector4() {}
    __forceinline void Set(const Point3& p,float last) {x=p[0];y=p[1];z=p[2];w=last;}
    __forceinline Vector4& operator=(const Vector4& p) {x=p.x;y=p.y;z=p.z;w=p.w;return *this;}
};
struct HeapObject {
    static void* FUN_0089eb90(unsigned int);
    static void* operator new(unsigned int bytes) {return FUN_0089eb90(bytes);}
    static void operator delete(void*,unsigned int);
};
struct Allocator {void FUN_008f6d90(void*,unsigned int,int);};
template<class T> struct Array {
    T* data;
    int size;
    int capacityFlags;
    Array():data(0),size(0),capacityFlags(0x80000000){}
    ~Array() {
        if((static_cast<unsigned int>(capacityFlags)&0x80000000u)==0) {
            unsigned int capacity=capacityFlags&0x3fffffff;
            Allocator* allocator=(Allocator*)TlsGetValue(DAT_010f3170);
            allocator->FUN_008f6d90(data,capacity*sizeof(T),0x17);
        }
    }
    __forceinline void Add(const T& item) {
        if(size==(capacityFlags&0x3fffffff))FUN_00901f10(this,sizeof(T));
        data[size++]=item;
    }
};
struct InfoHeader {
    unsigned int filterInfo;
    void* shapeData;
    unsigned char motionType,unk09,unk0a,unk0b;
    void* arrayData;
    int arraySize;
    int capacityFlags;
    unsigned int unk18,unk1c;
};
struct __declspec(align(16)) BodyInfo : InfoHeader {
    Vector4 row0,row1,row2,position;
    BodyInfo(){FUN_004f64e0();}
    void FUN_004f64e0();
    ~BodyInfo() {
        if((static_cast<unsigned int>(capacityFlags)&0x80000000u)==0) {
            unsigned int capacity=capacityFlags&0x3fffffff;
            Allocator* allocator=(Allocator*)TlsGetValue(DAT_010f3170);
            allocator->FUN_008f6d90(arrayData,capacity*8,0x17);
        }
    }
};
struct __declspec(align(16)) TransformInfo {
    unsigned int unk00;
    void* childShape;
    unsigned int unk08,unk0c;
    Vector4 row0,row1,row2,position;
    TransformInfo(){FUN_005a02b0();}
    void FUN_005a02b0();
};
struct __declspec(align(16)) CapsuleInfo {
    unsigned int unk00;
    float radius;
    unsigned int unk08,unk0c;
    Vector4 endA,endB;
    CapsuleInfo(){FUN_0059fd90();}
    void FUN_0059fd90();
};
struct MultiSphereInfo {
    unsigned int unk00;
    Array<Vector4> spheres;
    MultiSphereInfo():unk00(0){}
};
struct Shape : HeapObject {
    virtual void v00();
    volatile long refCount;
    void* nativeShape;
    unsigned int unk0c,unk10;
};
struct FUN_004f0790 : Shape {FUN_004f0790(Vector4& halfExtents);};
struct FUN_004e9520 : Shape {FUN_004e9520(float radius,int mode);};
struct FUN_0059f9c0 : Shape {FUN_0059f9c0(TransformInfo& info);};
struct FUN_0059fa80 : Shape {FUN_0059fa80(CapsuleInfo& info);};
struct FUN_0059f900 : Shape {FUN_0059f900(MultiSphereInfo& info);};
static __forceinline void* NativeShape(Shape* shape) {return shape?shape->nativeShape:0;}
struct Body : HeapObject {
    virtual void v00();
    volatile long refCount;
    unsigned int unk08,unk0c,unk10,unk14;
};
struct FUN_004e64b0 : Body {FUN_004e64b0(BodyInfo& info);};
struct SceneNode;
struct CollisionBase : HeapObject {
    void* table;
    unsigned int unk04,unk08,unk0c,unk10;
    CollisionBase(SceneNode* node){FUN_008d9fd0(node);}
    void FUN_008d9fd0(SceneNode* node);
    void FUN_008da000(Body* body);
};
struct CollisionObject : CollisionBase {
    CollisionObject(SceneNode* node):CollisionBase(node){table=&DAT_01066b94;}
};
struct PrimitiveSource {
    unsigned int FUN_00ba2040();
    void FUN_00ba4560(unsigned int index,int* type,Point3* center,Point3* dimensions);
};
struct Owner {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual SceneNode* CollisionNode();
    void FUN_005a11e0(PrimitiveSource* source,float factor);
};
// pdb: BSTreeNode::MakeHavokLeaves | BSTreeNode.obj | fnv360_0822_retail, call_dedup, medium
// pdb params: apST, afScale
void Owner::FUN_005a11e0(PrimitiveSource* source,float factor) {
    if(DAT_01073d7c==1) {
        unsigned int count=source->FUN_00ba2040();
        if(count) {
            float scale=DAT_00f65f18*factor;
            SceneNode* node=CollisionNode();
            BodyInfo bodyInfo;
            if(count==1) {
                Point3 dimensions,center;
                int type;
                source->FUN_00ba4560(0,&type,&center,&dimensions);
                ScaleInPlace(center,DAT_00dbe7c0,scale);
                ScaleInPlace(dimensions,DAT_00dbe7c0,scale);
                switch(type) {
                case 0: {
                    TransformInfo transform;
                    transform.position.Set(center,0.0f);
                    Shape* sphere=new FUN_004e9520(dimensions[0],0);
                    transform.childShape=NativeShape(sphere);
                    bodyInfo.shapeData=NativeShape(new FUN_0059f9c0(transform));
                    break;
                }
                case 1: {
                    CapsuleInfo capsule;
                    capsule.endA.Set(Point3(center[0],center[1],dimensions[0]+center[2]),0.0f);
                    capsule.endB.Set(Point3(center[0],center[1],center[2]+dimensions[1]-dimensions[0]),0.0f);
                    capsule.radius=dimensions[0];
                    bodyInfo.shapeData=NativeShape(new FUN_0059fa80(capsule));
                    break;
                }
                case 2: {
                    TransformInfo transform;
                    int i=0;
                    do { dimensions[i]=float(dimensions[i]*0.5); } while(++i<3);
                    float shiftedZ=dimensions[2]+center[2];
                    Vector4 halfExtents;
                    halfExtents.Set(dimensions,0.0f);
                    transform.position.Set(Point3(center[0],center[1],shiftedZ),0.0f);
                    Shape* box=new FUN_004f0790(halfExtents);
                    transform.childShape=NativeShape(box);
                    bodyInfo.shapeData=NativeShape(new FUN_0059f9c0(transform));
                    break;
                }
                }
            } else {
                MultiSphereInfo multi;
                for(unsigned int i=0;i<count;++i) {
                    Point3 dimensions,center;
                    int type;
                    source->FUN_00ba4560(i,&type,&center,&dimensions);
                    if(type==0) {
                        ScaleInPlace(center,DAT_00dbe7c0,scale);
                        dimensions[0]=float(float(dimensions[0]*DAT_00dbe7c0)*scale);
                        Vector4 sphere;
                        sphere.Set(center,dimensions[0]);
                        multi.spheres.Add(sphere);
                    }
                }
                bodyInfo.shapeData=NativeShape(new FUN_0059f900(multi));
            }
            bodyInfo.filterInfo=0x40009;
            Body* body=new FUN_004e64b0(bodyInfo);
            CollisionObject* collision=new CollisionObject(node);
            collision->FUN_008da000(body);
        }
    }
}
}

}   // namespace f3m_005a11e0

// @f3 0x005ae7e0 (community match, verified in this file)
#include <string.h>
namespace f3m_005ae7e0 {

namespace f3m_005ae7e0 {
struct Obj5ae7e0 {
    unsigned char m_flags;
    char pad01[3];
    float m_04;
    int m_08;
    int m_0c;
    int m_10;
    void FUN_005ae7e0(int a0);
};

// pdb: TESConditionItem::SetDefaultDataForFunction | TESConditionItem.obj | fnv360_0822_retail, objrun, medium
// pdb params: aiFunc
void Obj5ae7e0::FUN_005ae7e0(int a0)
{
    int idx = a0;
    if (a0 >= 0x1000 && a0 <= 0x1237)
        idx = a0 - 0x1000;
    else if (a0 >= 0 && a0 <= 0x237)
        a0 += 0x1000;
    if (idx >= 0 && idx <= 0x237) {
        memset(&m_08, 0, 12);
        *(short*)&m_08 = (short)idx;
        switch (a0) {
        case 0x1001:
            m_flags = (m_flags & 0x1f) | 0x80;
            if ((m_flags & 4) == 0)
                m_04 = 100.0f;
            break;
        case 0x106b:
            m_flags = (m_flags & 0x1f) | 0x20;
            if ((m_flags & 4) == 0)
                m_04 = 0.0f;
            break;
        case 0x10f7:
            m_0c = 0x28;
        case 0x103e:
        case 0x1040:
        case 0x1043:
        case 0x1044:
        case 0x1045:
        case 0x1046:
        case 0x1047:
        case 0x1048:
        case 0x105b:
        case 0x1065:
        case 0x1066:
        case 0x1067:
        case 0x106a:
        case 0x106f:
        case 0x1070:
        case 0x1136:
            m_flags &= 0x1f;
            if ((m_flags & 4) == 0)
                m_04 = 1.0f;
            break;
        }
    }
}
}
}   // namespace f3m_005ae7e0

// @f3 0x005a2490 (community match, verified in this file)
namespace f3m_005a2490 {
namespace f3m_005a2490 {
// pdb: ActorValue::ToArrayIndex | ActorValue.obj | fnv360_0822_retail, call_seq, medium
// pdb params: aiSection, aiIndex
char __cdecl FUN_005a2490(int type, int value)
{
    switch (type) {
    case 0: return value - 5;
    case 1: return value - 12;
    case 2: return value - 32;
    case 3: return value;
    case 4: return value - 25;
    case 5: return value - 46;
    }
    return 0;
}
}
}   // namespace f3m_005a2490
