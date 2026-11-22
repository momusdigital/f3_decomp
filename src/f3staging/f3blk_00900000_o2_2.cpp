#include <windows.h>
// src/f3staging/f3blk_00900000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00910b00 (community match, verified in this file)
namespace f3m_00910b00 {
namespace Shape2035 {
struct ObjectBase {
    virtual ~ObjectBase();
    unsigned short memorySize,refs;
    int userData,type;
};
struct ContainerBase {virtual ~ContainerBase();unsigned char flag14;};
struct CollectionBase:ObjectBase,ContainerBase {
    CollectionBase(int);
    ~CollectionBase();
};
struct Record {int first,second;};
struct ArrayBase {
    virtual ~ArrayBase();
    Record* data;
    unsigned int capacity,size,effective,grow;
    ArrayBase(){capacity=0;grow=1;size=0;effective=0;data=0;}
};
struct PrimitiveArray:ArrayBase {
    PrimitiveArray(){}
    ~PrimitiveArray();
    void FUN_00910490(unsigned int);
    void FUN_00910640(unsigned int,const Record*);
    void Add(const Record& value) {
        unsigned int index=size;
        if(index>=capacity)FUN_00910490(index+grow);
        FUN_00910640(index,&value);
    }
};
struct __declspec(align(16)) Vector4 {
    float x,y,z,w;
    Vector4(){}
    Vector4(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;}
    Vector4& operator=(const Vector4& v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}
};
struct Info {
    int unk00;
    float radius;
    int unk08;
    Record* records;
    int unk10,count,unk18,unk1C;
    Vector4 scale;
};

class Shape:public CollectionBase {
public:
    int unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C,unk40,unk44,unk48,unk4C,unk50,unk54,unk58,unk5C;
    Vector4 minimum,maximum,scale;
    float radius;
    PrimitiveArray strips;
    Shape(const Info*);
    virtual ~Shape();
};
// pdb: hkNiTriStripsShape::hkNiTriStripsShape | hkNiTriStripsShape.obj | fnv360_0822_retail, objrun, medium
// pdb params: arInfo
Shape::Shape(const Info* info):CollectionBase(0x1e) {
    radius=info->radius;
    Vector4 copiedScale(info->scale);
    scale=copiedScale;
    for(int i=0;i<info->count;++i)strips.Add(info->records[i]);
    minimum.x=3.40282e38f;minimum.y=3.40282e38f;minimum.z=3.40282e38f;minimum.w=0;
    maximum.x=-3.40282e38f;maximum.y=-3.40282e38f;maximum.z=-3.40282e38f;maximum.w=0;
}
}
}   // namespace f3m_00910b00

// @f3 0x0090cff0 (community match, verified in this file)
extern float DAT_0104da48;
namespace f3m_0090cff0 {
namespace c_0090cff0 {
struct __declspec(align(16)) Vec4 { float x, y, z, w; };
struct UFloat8 { unsigned char v; void FUN_0090aba0(const float* f); };
struct Motion {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void SetLinearVelocity(const Vec4* v);
    virtual void SetAngularVelocity(const Vec4* v);
    int unk04;
    char type;
    char unk09;
    char unk0a;
    char unk0b;
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
    UFloat8 maxLinear;
    UFloat8 maxAngular;
    void FUN_008f8400(int c);
    static void* operator new(unsigned int, void* p) { return p; }
};
struct FixedMotion : Motion {
    FixedMotion(const Vec4& pos, const Vec4& rot);
};
struct CInfo {
    int unk00;
    void* shape;
    char unk08;
    char pad09;
    short unk0a;
    int pad0c;
    Vec4 position;
    Vec4 rotation;
    Vec4 linearVelocity;
    Vec4 angularVelocity;
    Vec4 inertia[3];
    Vec4 centerOfMass;
    float mass;
    float unk94;
    float unk98;
    float unk9c;
    float unka0;
    float maxLinear;
    float maxAngular;
    float unkac;
    char motionType;
    char unkb1;
    char unkb2;
    char unkb3;
    char unkb4;
    char unkb5;
    char unkb6;
};
void __cdecl FUN_0090c9b0(int type, const Vec4* pos, const Vec4* rot, float mass, const Vec4* inertia, const Vec4* com, float maxLinear, float maxAngular, void* buf);
struct Collidable {
    void* shape;
    int unk04;
    void* motionState;
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
    float allowedPenetrationDepth;
};
inline float Min2(float x, float y) { return x < y ? x : y; }
// Same-file static helper of the constructor (it has a private register
// convention in the original, so it must be visible here with its real body).
static __declspec(noinline) void FUN_0090c7b0(Collidable* collidable, const Vec4& extent)
{
    float minExtent = Min2(Min2(extent.x, extent.y), extent.z);
    if (minExtent < 0.5f)
        collidable->allowedPenetrationDepth = minExtent * 0.2;
    else
        collidable->allowedPenetrationDepth = 0.1f;
}
struct Base {
    Base(void* shape);
    virtual void b00();
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
    int unk14;
    void* unk18;
    int unk1c;
    char unk20;
    unsigned char unk21;
    char unk22;
    char unk23;
    int unk24;
    short unk28;
    short unk2a;
    int unk2c;
};
struct Body : Base {
    virtual void b00();
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
    float unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    char unk80;
    char unk81;
    char unk82;
    char unk83;
    float unk84;
    float unk88;
    int unk8c;
    int unk90;
    short unk94;
    short unk96;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    char unkbc;
    char unkbd;
    char unkbe;
    char unkbf;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int motiond0;
    int motiond4;
    int motiond8;
    int motiondc;
    int motione0;
    int motione4;
    int motione8;
    int motionec;
    int motionf0;
    int motionf4;
    int motionf8;
    int motionfc;
    int motion100;
    int motion104;
    int motion108;
    int motion10c;
    int motion110;
    int motion114;
    int motion118;
    int motion11c;
    int motion120;
    int motion124;
    int motion128;
    int motion12c;
    int motion130;
    int motion134;
    int motion138;
    int motion13c;
    int motion140;
    int motion144;
    int motion148;
    int motion14c;
    int motion150;
    int motion154;
    int motion158;
    int motion15c;
    int motion160;
    int motion164;
    int motion168;
    int motion16c;
    int motion170;
    int motion174;
    int motion178;
    int motion17c;
    int motion180;
    float unk184;
    float unk188;
    void FUN_0090b500();
    void FUN_0090c670(int c);
    void hkpRigidBody_updateCachedShapeInfo(void* p, Vec4* out);
    Body(const CInfo& info);
};
// pdb: hkpWorldObject::copyProperties | hkpRigidBody.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: hkpRigidBody::hkpRigidBody)
// pdb params: otherObj
Body::Body(const CInfo& info) : Base(info.shape)
{
    unk80 = info.unk08;
    unk96 = info.unk0a;
    unk2c = info.unk00;
    if (info.motionType == 7) {
        Motion* m = new (&motiond0) FixedMotion(info.position, info.rotation);
        m->maxLinear.FUN_0090aba0(&info.maxLinear);
        m->maxAngular.FUN_0090aba0(&info.maxAngular);
        m->FUN_008f8400(1);
        unk18 = &motione0;
        if (info.unkac <= 0.0f)
            unk58 = DAT_0104da48;
        else
            unk58 = info.unkac;
    } else {
        Motion* m = (Motion*)&motiond0;
        FUN_0090c9b0(info.motionType, &info.position, &info.rotation, info.mass, info.inertia, &info.centerOfMass, info.maxLinear, info.maxAngular, &motiond0);
        m->FUN_008f8400(info.unkb2);
        FUN_0090b500();
        m->SetLinearVelocity(&info.linearVelocity);
        FUN_0090b500();
        m->SetAngularVelocity(&info.angularVelocity);
        unk18 = &motione0;
        unk58 = info.unkac;
    }
    FUN_0090c670(info.unkb1);
    unk184 = info.unk94;
    unk188 = info.unk98;
    if (unk10) {
        Vec4 v;
        hkpRigidBody_updateCachedShapeInfo(unk10, &v);
        if (unk58 <= 0.0f)
            FUN_0090c7b0((Collidable*)&unk10, v);
    }
    if (info.unkb3)
        unk2a = info.unkb3;
    else if (((Motion*)&motiond0)->type == 7)
        unk2a = 1;
    else
        unk2a = (info.motionType == 6) ? 2 : 3;
    unkbd = info.unkb5;
    unkbc = info.unkb4;
    if (info.unkb6)
        unk21 |= 1;
    unk84 = info.unk9c;
    unk88 = info.unka0;
}
}
}   // namespace f3m_0090cff0

