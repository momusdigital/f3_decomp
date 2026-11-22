// src/f3staging/f3blk_007c0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007c9760 (community match, verified in this file)
template <class T, class Allocator>
inline unsigned int NiTArray<T, Allocator>::GetSize()
{
    return m_usSize;
}

template <class T, class Allocator>
inline T& NiTArray<T, Allocator>::GetAt(unsigned int index)
{
    return m_pBase[index];
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pkBaseRTTI;
};

extern NiRTTI DAT_010f2ee0;
extern NiRTTI DAT_010f33b4;

bool __cdecl FUN_00424d20(const NiRTTI* apRTTI, const NiObject* apObject);

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};

class NiMatrix3
{
  public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};

class NiTransform
{
  public:
    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};

class NiObject
{
  public:
    virtual ~NiObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* CreateClone(void* apCloning);
    virtual NiNode* IsNode();
    int m_uiRefCount;
    void IncRefCount();
    void DecRefCount();
};

class NiAVObject : public NiObject
{
  public:
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* m_spCollisionObject;
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
    NiTransform m_kWorld;

    const NiTransform& GetWorldTransform() const
    {
        return m_kWorld;
    }
};

class NiNode : public NiAVObject
{
  public:
    NiTObjectArray<NiPointer<NiAVObject> > m_kChildren;

    unsigned int GetArrayCount()
    {
        return m_kChildren.GetSize();
    }

    NiAVObject* GetAt(unsigned int i)
    {
        return m_kChildren.GetAt(i);
    }
};

class hkBool
{
  public:
    hkBool() {}
    hkBool(bool b) : m_bool(b ? 1 : 0) {}
    operator bool() const
    {
        return m_bool != 0;
    }

  private:
    char m_bool;
};

FNV_ALIGN(16) class hkVector4
{
  public:
    float x;
    float y;
    float z;
    float w;

    __forceinline hkVector4() {}

    __forceinline hkVector4(const hkVector4& v)
    {
        *this = v;
    }

    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }

    void FUN_008d2970(const class hkTransform& aTransform, const hkVector4& aVec);
};

FNV_ALIGN(16) class hkQuaternion
{
  public:
    hkVector4 m_vec;
};

class hkMatrix3
{
  public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline hkMatrix3() {}
};

class hkRotation : public hkMatrix3
{
  public:
    __forceinline hkRotation() {}
    void hkRotation_set(const hkQuaternion& q);
};

class hkTransform
{
  public:
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkTransform() {}

    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 r0 = t.m_rotation.m_col0;
        const hkVector4 r1 = t.m_rotation.m_col1;
        const hkVector4 r2 = t.m_rotation.m_col2;
        const hkVector4 r3 = t.m_translation;
        m_rotation.m_col0 = r0;
        m_rotation.m_col1 = r1;
        m_rotation.m_col2 = r2;
        m_translation = r3;
    }

    __forceinline void set(const hkQuaternion& q, const hkVector4& t)
    {
        m_rotation.hkRotation_set(q);
        m_translation = t;
    }

    void hkTransform_setMul(const hkTransform& a, const hkTransform& b);
};

void __cdecl FUN_004e5e40(hkTransform& aOut, const NiTransform& aIn);

struct hkpShapeRayCastInput
{
    hkVector4 m_from;
    hkVector4 m_to;
    unsigned int m_filterInfo;
    const void* m_rayShapeCollectionFilter;

    hkpShapeRayCastInput() : m_filterInfo(0), m_rayShapeCollectionFilter(0) {}
};

struct hkpShapeRayCastCollectorOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
    int m_extraInfo;
    int m_pad0;
    int m_pad1;

    void reset()
    {
        m_hitFraction = 1.0f;
        m_extraInfo = -1;
    }

    hkpShapeRayCastCollectorOutput()
    {
        reset();
    }

    hkBool FUN_005740c0() const;
};

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
    unsigned int m_shapeKey0;
    unsigned int m_shapeKey1;
    unsigned int m_shapeKey2;
    unsigned int m_shapeKey3;
    unsigned int m_shapeKey4;
    unsigned int m_shapeKey5;
    unsigned int m_shapeKey6;
    unsigned int m_shapeKey7;
    int m_shapeKeyIndex;

    void _reset()
    {
        m_shapeKeyIndex = 0;
        m_shapeKey0 = 0xffffffff;
    }

    hkpShapeRayCastOutput()
    {
        _reset();
    }
};

class bhkShape;

class hkpShape
{
  public:
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual hkBool castRay(const hkpShapeRayCastInput& aInput, hkpShapeRayCastOutput& aOutput) const;

    int m_memSizeAndFlags;
    bhkShape* m_userData;

    bhkShape* getUserData() const
    {
        return m_userData;
    }
};

struct hkpCdBody
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollidable : public hkpCdBody
{
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_collisionFilterInfo;

    const hkpShape* getShape() const
    {
        return m_shape;
    }

    unsigned int getCollisionFilterInfo() const
    {
        return m_collisionFilterInfo;
    }
};

struct hkpWorldObject
{
    virtual ~hkpWorldObject();
    int m_memSizeAndFlags;
    void* m_world;
    int m_userData;
    hkpCollidable m_collidable;

    const hkpCollidable* getCollidable() const
    {
        return &m_collidable;
    }

    hkpCollidable* getCollidableRw()
    {
        return &m_collidable;
    }
};

class CFilter
{
  public:
    unsigned int iFilter;

    CFilter(unsigned int aFilter = 0) : iFilter(aFilter) {}

    unsigned int GetLayer() const
    {
        return iFilter & 0x7f;
    }

    bool QBipLayer() const
    {
        unsigned int eLayer = GetLayer();
        return eLayer == 8 || eLayer == 0x1d;
    }

    unsigned int GetPart() const
    {
        return (iFilter >> 8) & 0x1f;
    }

    unsigned int GetBipedPart() const
    {
        return GetPart();
    }
};

class bhkShape : public NiObject
{
  public:
    hkpShape* m_pWrappedObject;
    int unk0c;
    unsigned int eMaterial;

    hkpShape* Gethk() const
    {
        return m_pWrappedObject;
    }

    hkpShape* operator*() const
    {
        return this ? Gethk() : 0;
    }

    static bhkShape* Getbhk(const hkpShape* apShape)
    {
        return apShape ? apShape->getUserData() : 0;
    }
};

class bhkWorldObject : public NiObject
{
  public:
    hkpWorldObject* m_pWrappedObject;
    int unk0c;
    unsigned int iFlags;

    hkpWorldObject* Gethk() const
    {
        return m_pWrappedObject;
    }

    const hkpCollidable* GetCollidable() const
    {
        const hkpCollidable* pColl = 0;
        hkpWorldObject* pObj = Gethk();
        if (pObj)
        {
            pColl = pObj->getCollidable();
        }
        return pColl;
    }

    hkpCollidable* GetCollidableRw()
    {
        hkpCollidable* pColl = 0;
        hkpWorldObject* pObj = Gethk();
        if (pObj)
        {
            pColl = pObj->getCollidableRw();
        }
        return pColl;
    }

    const hkpShape* GethkShape()
    {
        hkpCollidable* pColl = GetCollidableRw();
        return pColl ? pColl->getShape() : 0;
    }

    bhkShape* GetShape()
    {
        return bhkShape::Getbhk(GethkShape());
    }

    CFilter GetCollisionFilterInline() const
    {
        const hkpCollidable* pColl = GetCollidable();
        return CFilter(pColl ? pColl->getCollisionFilterInfo() : 0);
    }

    CFilter FUN_00424270() const;
    bool FUN_00726810() const;
};

class bhkRigidBody : public bhkWorldObject
{
  public:
    int unk14;
    int unk18;

    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual hkTransform& GetTransform(hkTransform& aTransform);

    hkpWorldObject* operator*() const
    {
        return this ? Gethk() : 0;
    }
};

class bhkRigidBodyT : public bhkRigidBody
{
  public:
    hkQuaternion LocalRot;
    hkVector4 LocalPos;

    const hkQuaternion& GetLocalRot() const
    {
        return LocalRot;
    }

    const hkVector4& GetLocalPos() const
    {
        return LocalPos;
    }
};

class bhkCollisionObject : public NiObject
{
  public:
    NiAVObject* m_pkSceneObject;
    unsigned int m_uiFlags;
    NiPointer<bhkWorldObject> spWorldObj;

    bhkRigidBody* GetRigidBody()
    {
        return (bhkRigidBody*)(bhkWorldObject*)spWorldObj;
    }
};

bhkCollisionObject* __cdecl FUN_00424fe0(NiAVObject* apObject);

class bhkBlendCollisionObject : public bhkCollisionObject
{
  public:
    bool bRagdollUpdated;
    float fHeirGain;

    float QHeirGain() const
    {
        return fHeirGain;
    }
};

class hkpAllRayHitCollector
{
  public:
    virtual void addRayHit(const hkpCdBody& aBody, const hkpShapeRayCastCollectorOutput& aHitInfo);
    void FUN_008f7110();
};

class bhkPickData : public hkpShapeRayCastInput
{
  public:
    hkpShapeRayCastOutput m_output;
    const hkpCollidable* m_rootCollidable;
    int unk84;
    int unk88;
    int unk8c;
    hkVector4 hkLength;
    char* pCache;
    void* pCloseCollector;
    hkpAllRayHitCollector* pAllCollector;
    bool bPickFailed;

    const hkVector4& GethkFrom()
    {
        return m_from;
    }

    const hkVector4& FUN_00434430();

    hkpAllRayHitCollector* GetAllCollector()
    {
        return pAllCollector;
    }
};

// pdb: Projectile::PickSceneGraph | Projectile.obj | fnv360_0822_retail, call_gap, low
// pdb params: apPickData, apObject, abIgnoreHead, abSort
bool __cdecl FUN_007c9760(bhkPickData* apPickData, NiAVObject* apObject, bool abIgnoreWeapon, bool abSortHits)
{
    bool bHit = false;
    if (apObject)
    {
        bhkCollisionObject* pColObj = FUN_00424fe0(apObject);
        if (pColObj)
        {
            bhkRigidBody* pRigidBody = pColObj->GetRigidBody();
            hkpWorldObject* pObj;
            hkpCollidable* pColl;
            const hkpShape* pHkShape;
            bhkShape* pRawShape;
            bhkShape* pShape =
                pRigidBody
                    ? ((pObj = pRigidBody->Gethk())
                           ? ((pColl = pObj->getCollidableRw())
                                  ? ((pHkShape = pColl->getShape())
                                         ? ((pRawShape = pHkShape->getUserData()) ? pRawShape : 0)
                                         : 0)
                                  : 0)
                           : 0)
                    : 0;
            if (pShape && pRigidBody->GetCollisionFilterInline().QBipLayer() &&
                (!abIgnoreWeapon || pRigidBody->FUN_00424270().GetBipedPart() != 1))
            {
                hkTransform kTransform;
                if (FUN_00424d20(&DAT_010f2ee0, pColObj))
                {
                    bhkBlendCollisionObject* pBlendObj = (bhkBlendCollisionObject*)pColObj;
                    if (!pRigidBody->FUN_00726810() || pBlendObj->QHeirGain() == 1.0f)
                    {
                        FUN_004e5e40(kTransform, apObject->GetWorldTransform());
                        if (FUN_00424d20(&DAT_010f33b4, pRigidBody))
                        {
                            bhkRigidBodyT* pRigidBodyT = (bhkRigidBodyT*)pRigidBody;
                            hkTransform kLocalTransform;
                            hkTransform kWorldTransform(kTransform);
                            kLocalTransform.set(pRigidBodyT->GetLocalRot(), pRigidBodyT->GetLocalPos());
                            kTransform.hkTransform_setMul(kWorldTransform, kLocalTransform);
                        }
                    }
                    else
                    {
                        pRigidBody->GetTransform(kTransform);
                    }
                }
                else
                {
                    pRigidBody->GetTransform(kTransform);
                }

                hkpShapeRayCastInput kRayInput;
                hkpShapeRayCastOutput kRayOutput;
                kRayInput.m_from.FUN_008d2970(kTransform, apPickData->GethkFrom());
                kRayInput.m_to.FUN_008d2970(kTransform, apPickData->FUN_00434430());
                (**pShape)->castRay(kRayInput, kRayOutput);
                if (kRayOutput.FUN_005740c0())
                {
                    apPickData->GetAllCollector()->addRayHit(*(**pRigidBody)->getCollidable(), kRayOutput);
                    bHit = true;
                }
            }
        }

        NiNode* pNode = apObject->IsNode();
        if (pNode)
        {
            for (unsigned int i = 0; i < pNode->GetArrayCount(); i++)
            {
                NiAVObject* pChild = pNode->GetAt(i);
                bHit |= FUN_007c9760(apPickData, pChild, abIgnoreWeapon, false);
            }
        }
    }

    if (abSortHits)
    {
        apPickData->GetAllCollector()->FUN_008f7110();
    }

    return bHit;
}

// @f3 0x007ca320 (community match, verified in this file)
namespace n7ca320
{

struct Node;
struct Actor;
struct World;
struct Controller;
struct ControllerPointer;
struct Process;

struct Point
{
    float x, y, z;
};

struct Filter
{
    unsigned int bits;
    __forceinline unsigned short Group() const { return (unsigned short)(bits >> 16); }
};

struct Node
{
    void** vtable;
};

struct World
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual bool IsActive();
    virtual void HandleNode(Node* node, int first, int second, unsigned int filter, int last);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short unk1c;
    unsigned char active1e;
    unsigned char unk1f;


};

extern World* DAT_01071564;

struct WorldReference
{
    World* FUN_00410f00();
};

struct Middle
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags24;
    WorldReference world28;

    __forceinline World* GetWorld()
    {
        if (flags24 & 1)
            return world28.FUN_00410f00();
        return DAT_01071564;
    }

    float FUN_004d5350();
};

struct ProcessTable
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    void* unk1f4;
    void* unk1f8;
    void* unk1fc;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20c;
    void* unk210;
    void* unk214;
    void* unk218;
    void* unk21c;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22c;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23c;
    void* unk240;
    void* unk244;
    void* unk248;
    void* unk24c;
    void* unk250;
    void* unk254;
    void* unk258;
    void* unk25c;
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26c;
    void* unk270;
    void* unk274;
    void* unk278;
    void* unk27c;
    void* unk280;
    void* unk284;
    void* unk288;
    void (__thiscall *setController28c)(Process*, ControllerPointer);
};

struct Process
{
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
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void SetController(ControllerPointer controller);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int dead28;
};

struct BaseObject
{
    float FUN_0076e160();
};

struct Target
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual bool IsActor();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4a();
    virtual void vf4b();
    virtual void vf4c();
    virtual void vf4d();
    virtual void vf4e();
    virtual void vf4f();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf5a();
    virtual void vf5b();
    virtual void vf5c();
    virtual void vf5d();
    virtual void vf5e();
    virtual void vf5f();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf6a();
    virtual void vf6b();
    virtual void vf6c();
    virtual void vf6d();
    virtual void vf6e();
    virtual void vf6f();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual Node* Get3D();



    Filter* FUN_00766b00(Filter* output);
};

struct CollisionObject
{
    unsigned int unk00, unk04, unk08, unk0c;
    struct WorldObject* worldObject10;
};

struct WorldObject
{
    Filter* FUN_00424270(Filter* output);
};

struct Setting
{
    float* FUN_00401eb0();
};

void* __cdecl FUN_0089eb90(unsigned int size);
void* __cdecl FUN_008dba50(unsigned int size);

struct Shape
{
    __forceinline static void* operator new(unsigned int size) throw() { return FUN_0089eb90(size); }
    static void operator delete(void* memory) throw();
    Shape(float radius, int type);
    unsigned int unk00, unk04, unk08, unk0c, unk10;
};

struct __declspec(align(16)) ControllerInfo
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    Node* node80;
    unsigned int filter84;
    World* world88;
    float scale8c;
    float height90;
    bool flag94;
    bool flag95;
    unsigned short unk96;
    unsigned int unk98;
    unsigned int layer9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;

    ControllerInfo(int type);
    ~ControllerInfo();
    void FUN_006a8d30(const Point* position);
    void FUN_006a8f30(Shape* shape);
};

struct UpVector
{
    float x, y, z, w;
    __forceinline UpVector(float first, float second, float third, float fourth)
        : x(first), y(second), z(third), w(fourth) {}
};

struct UpOwner
{
    void hkpCharacterProxy_setLinearVelocity(const UpVector& vector);
};

extern const double DAT_00dbe7c0;

struct Controller
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void SetState(int state);
    unsigned int unk04;
    UpOwner* up08;
 
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    struct Flags
    {
        unsigned int value;
        void Set(unsigned int mask, bool on)
        {
            if (on)
                value |= mask;
            else
                value &= ~mask;
        }
    } flags294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    float fallDistance3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    bhkWorldObject* object424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;

    __forceinline static void* operator new(unsigned int size) throw() { return FUN_008dba50(size); }
    static void operator delete(void* memory) throw();
    Controller(ControllerInfo& info, Actor* actor);

    void FUN_006a8f80(unsigned int enabled);
    void FUN_008e9e90(int duration, Actor* actor);
    World* FUN_00568690();
    void bhkCharacterController_SetWorld(World* world);
    Node* FUN_006a8fb0();
    void FUN_004e94e0(Node* node);
    void bhkCharacterController_SetPosition(const hkVector4& position);
    __declspec(noinline) void FUN_004e6580(const Point& position)
    {
        hkVector4 v;
        v.x = position.x * DAT_00dbe7c0;
        v.y = position.y * DAT_00dbe7c0;
        v.z = position.z * DAT_00dbe7c0;
        bhkCharacterController_SetPosition(v);
    }
    __declspec(noinline) CFilter FUN_0061f4f0()
    {
        return object424 ? object424->GetCollisionFilterInline() : CFilter(0);
    }


    __forceinline void SetFallDistance(float distance)
    {
        fallDistance3c8 = distance;
    }
};

struct ControllerPointer
{
    Controller* pointer;
    ControllerPointer(Controller* value);
    ControllerPointer(const ControllerPointer& other);
    ~ControllerPointer();
};

struct Actor
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4a();
    virtual void vf4b();
    virtual void vf4c();
    virtual void vf4d();
    virtual void vf4e();
    virtual void vf4f();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf5a();
    virtual void vf5b();
    virtual void vf5c();
    virtual void vf5d();
    virtual void vf5e();
    virtual void vf5f();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf6a();
    virtual void vf6b();
    virtual void vf6c();
    virtual void vf6d();
    virtual void vf6e();
    virtual void vf6f();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual Node* Get3D();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf7a();
    virtual void vf7b();
    virtual void vf7c();
    virtual const Point* GetPosition();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    BaseObject* base1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    Middle* middle3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    Process* process60;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    unsigned int flagsc0;
    unsigned int unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    unsigned int unke0, unke4, unke8, unkec, unkf0;
    Target* targetf4;



    Controller* FUN_00764ea0();
    void FUN_007ca320();
};

extern unsigned char DAT_0107a0f2;
extern Setting DAT_00f6077c;
extern Setting DAT_00f60788;
extern const float DAT_00db7260;
extern const double DAT_00dbe7c0;
extern const double DAT_00dd2798;

void __cdecl FUN_008d78f0(Node* node, int first, int second, int third);
void __cdecl FUN_008d7b90(Node* node, int type, int first, int second, int third);
void __cdecl FUN_008d7960(Node* node, float value, int first, int second);
void __cdecl FUN_008d79d0(Node* node, float value, int first, int second);
void __cdecl FUN_008d7d00(Node* node, int type, int first, int second, int third);
void __cdecl FUN_008d7c10(Node* node, unsigned int filter, int first, int second);
CollisionObject* __cdecl FUN_00477d90(Node* node);
void __cdecl FUN_008d7720(Node* node, int first, int second);
void __cdecl FUN_00aeeca0(Node* node, int enabled);

// pdb: Projectile::InitHavok | Projectile.obj | fnv360_0822_retail, vtable, medium
void Actor::FUN_007ca320()
{
    Node* node = Get3D();
    if (!node || !process60 || process60->dead28)
        return;

    Middle* middle = middle3c;
    World* world;
    if (!middle)
        return;

    world = middle->GetWorld();
    if (!world)
        return;

    unsigned int actorFlags = flagsc0;
    if (((unsigned char)(actorFlags >> 3)) & 1)
    {
        FUN_008d78f0(node, 0, 1, 0);
        FUN_008d7b90(node, 6, 1, 0, 1);
        return;
    }

    if (((unsigned char)(actorFlags >> 2)) & 1)
    {
        FUN_008d7b90(Get3D(), 1, 1, 0, 1);
        if (*DAT_00f6077c.FUN_00401eb0() != 0.0f)
            FUN_008d7960(node, *DAT_00f6077c.FUN_00401eb0(), 1, 0);
        if (*DAT_00f60788.FUN_00401eb0() != 0.0f)
            FUN_008d79d0(node, *DAT_00f60788.FUN_00401eb0(), 1, 0);
        FUN_008d7d00(node, 6, 0, 1, 0);

        Target* target = targetf4;
        if (target)
        {
            bool ownerIsActor = target->IsActor();
            Target* owner = targetf4;
            if (ownerIsActor)
            {
                Filter ownerFilter;
                FUN_008d7c10(node, owner->FUN_00766b00(&ownerFilter)->Group(), 1, 0);
            }
            else
            {
                CollisionObject* collision = FUN_00477d90(owner->Get3D());
                WorldObject* object = collision ? collision->worldObject10 : 0;
                if (object)
                {
                    Filter ownerFilter;
                    FUN_008d7c10(node, object->FUN_00424270(&ownerFilter)->Group(), 1, 0);
                }
            }
        }
        world->HandleNode(node, 1, 1, 0, 0);
        return;
    }

    Controller* controller = FUN_00764ea0();
    if (!controller)
    {
        ControllerInfo info(1);
        info.scale8c = 1.0f;
        info.world88 = world;
        info.node80 = node;
        info.FUN_006a8d30(GetPosition());
        info.FUN_006a8f30(new Shape(0.1f, 1));
        info.flag95 = false;
        info.flag94 = false;
        info.height90 = base1c->FUN_0076e160();
        if (targetf4 && targetf4->IsActor())
        {
            Target* target = targetf4;
            Filter filter;
            info.filter84 = (target->FUN_00766b00(&filter)->Group() << 16) | 6;
        }
        info.layer9c = 6;

        controller = new Controller(info, this);
        controller->FUN_006a8f80(DAT_0107a0f2);
        controller->flags294.Set(0x80000, true);
        UpVector up(DAT_00db7260, 0.0f, 0.0f, 0.0f);
        if (controller && controller->up08)
            controller->up08->hkpCharacterProxy_setLinearVelocity(up);
        process60->SetController(controller);
        controller->FUN_008e9e90(1000, this);
        FUN_008d78f0(node, 0, 1, 0);
    }

    if (controller)
    {
        controller->SetFallDistance((float)(middle->FUN_004d5350() * DAT_00dbe7c0));
        World* oldWorld = controller->FUN_00568690();
        controller->bhkCharacterController_SetWorld(world);
        Node* oldNode = controller->FUN_006a8fb0();
        if (oldNode != node)
        {
            controller->FUN_004e94e0(node);
            if (world && world->active1e)
            {
                controller->SetState(0);
                FUN_00aeeca0(controller->FUN_006a8fb0(), 1);
            }
            FUN_008d7b90(node, 6, 1, 0, 1);
        }

        Point position = *GetPosition();
        if (oldWorld != world)
        {
            if (oldWorld)
                FUN_008d7720(node, 1, 0);
            position.z = (float)(position.z + DAT_00dd2798);
        }

        if (world)
        {
            controller->FUN_004e6580(position);
            CFilter filter = controller->FUN_0061f4f0();
            world->HandleNode(node, 1, 0, filter.iFilter >> 16, 0);
        }
    }
}

}

// @f3 0x007cd730 (community match, verified in this file)
struct S7cd730_PickData
{
    hkVector4 m_from;              // 0x00
    hkVector4 m_to;                // 0x10
    bool m_enableShapeCollectionFilter; // 0x20
    unsigned int m_filterInfo;     // 0x24
    int unk28;
    int unk2c;
    hkpShapeRayCastOutput m_output; // 0x30
    const hkpCollidable* m_rootCollidable; // 0x80
    int unk84;
    int unk88;
    int unk8c;
    hkVector4 hkLength;            // 0x90
    char* pCache;                  // 0xa0
    void* pCloseCollector;         // 0xa4
    void* pAllCollector;           // 0xa8
    bool bPickFailed;              // 0xac

    S7cd730_PickData();            // FUN_00468f40
    void FUN_0068daa0(const NiPoint3& arDirection);
    NiPoint3 FUN_00437150();
};

struct S7cd730_RayHit
{
    hkpShapeRayCastOutput m_output;
    const hkpCollidable* m_rootCollidable;
    int unk54;
    int unk58;
    int unk5c;
};

FNV_ALIGN(16) struct S7cd730_AllRayHitCollector
{
    void* vtbl;
    float m_earlyOutHitFraction;
    S7cd730_RayHit* m_data;
    int m_size;
    int m_capacityAndFlags;
    S7cd730_RayHit m_storage[8];

    S7cd730_AllRayHitCollector();  // FUN_0046a820
    ~S7cd730_AllRayHitCollector(); // FUN_0046a920
};

struct S7cd730_World
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual bool Pick(S7cd730_PickData* apData);
};

struct S7cd730_WorldHolder
{
    S7cd730_World* FUN_00410f00();
};

struct S7cd730_Ref
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4a();
    virtual void vf4b();
    virtual void vf4c();
    virtual void vf4d();
    virtual void vf4e();
    virtual void vf4f();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf5a();
    virtual void vf5b();
    virtual void vf5c();
    virtual void vf5d();
    virtual void vf5e();
    virtual void vf5f();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf6a();
    virtual void vf6b();
    virtual void vf6c();
    virtual void vf6d();
    virtual void vf6e();
    virtual void vf6f();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf7a();
    virtual void vf7b();
    virtual void vf7c();
    virtual NiPoint3* GetPos();
};

struct S7cd730_Player;
struct S7cd730_BaseForm;
extern S7cd730_Player* DAT_0107a104;
extern S7cd730_World* DAT_01071564;
extern const double DAT_00dbe7c0;
extern const float DAT_00db9568;
extern const double DAT_00db88e8;

struct S7cd730_ParentCell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int uiCellFlags;      // 0x24
    S7cd730_WorldHolder kHolder;   // 0x28

    float FUN_004d5350();
};

struct S7cd730_Player : public S7cd730_Ref
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S7cd730_ParentCell* pParentCell; // 0x3c
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
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
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    float fEyeHeight; // 0x5f4

    float FUN_004e6d80();
    CFilter FUN_00766b00(); // collision filter
};

struct S7cd730_Self : public S7cd730_Ref
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    S7cd730_BaseForm* pBaseForm; // 0x1c
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S7cd730_ParentCell* pParentCell; // 0x3c
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    float fTimer; // 0xcc
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    S7cd730_Player* pTarget; // 0xf4

    n7ca320::Controller* FUN_00764ea0();
    bool FUN_007cbc10(S7cd730_PickData* apPickData, float* apHitFraction);
    bool FUN_007cd730();

    S7cd730_BaseForm* GetBaseForm() const
    {
        return pBaseForm;
    }
};


int __cdecl FUN_007cc540(S7cd730_PickData* apPickData, S7cd730_Self* apSelf, S7cd730_BaseForm* apBaseForm, int aiArg4, int aiArg5, float afHitFraction);

static inline NiPoint3 S7cd730_Make(float x, float y, float z)
{
    NiPoint3 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}

static inline NiPoint3 S7cd730_Sub(const NiPoint3& a, const NiPoint3& b)
{
    return S7cd730_Make(a.x - b.x, a.y - b.y, a.z - b.z);
}

// Same source file as FUN_007cd730: its body is visible there, so the hit fraction passed by address does not escape
// (that is what lets it share its slot with the earlier float temporaries).
__declspec(noinline) bool S7cd730_Self::FUN_007cbc10(S7cd730_PickData* apPickData, float* apHitFraction)
{
    S7cd730_ParentCell* pCell = pParentCell;
    if (!pCell || !(pCell->uiCellFlags & 2))
        return false;
    float fWaterHeight = pCell->FUN_004d5350();
    float fFromZ = (float)(apPickData->m_from.z * DAT_00db88e8);
    NiPoint3 kHit = apPickData->FUN_00437150();
    if (!(fWaterHeight < fFromZ))
        return false;
    if (!(kHit.z <= fWaterHeight))
        return false;
    float fAbove = fWaterHeight - fFromZ;
    float fRay = kHit.z - fFromZ;
    *apHitFraction = fAbove / fRay;
    return true;
}


// pdb: Projectile::TestProjectileInTriggerZone | Projectile.obj | fnv360_0822_retail, call_seq, low
bool S7cd730_Self::FUN_007cd730()
{
    if (pTarget != DAT_0107a104)
        return false;

    S7cd730_PickData kPick;
    NiPoint3 kPos = *GetPos();
    NiPoint3 kPlayerPos = *DAT_0107a104->GetPos();
    float fEyeHeight = DAT_0107a104->fEyeHeight;
    kPlayerPos.z += DAT_0107a104->FUN_004e6d80() * fEyeHeight;
    NiPoint3 kDirection = S7cd730_Sub(kPos, kPlayerPos);

    n7ca320::Controller* pController = FUN_00764ea0();
    CFilter kFilter;
    if (pController)
        kFilter = pController->FUN_0061f4f0();
    else
        kFilter = DAT_0107a104->FUN_00766b00();
    hkVector4 kFrom;
    kFrom.x = kPlayerPos.x * DAT_00dbe7c0;
    kFrom.y = kPlayerPos.y * DAT_00dbe7c0;
    kFrom.z = kPlayerPos.z * DAT_00dbe7c0;
    kFilter.iFilter &= ~0x7f;
    kFilter.iFilter |= 6;
    kPick.m_filterInfo = kFilter.iFilter;
    kPick.m_from = kFrom;
    kPick.FUN_0068daa0(kDirection);

    // The collector lives in a block of its own: with it at function scope the two filter temporaries above are
    // kept apart (the frame grows by 16 bytes).
    bool bHit;
    {
        S7cd730_AllRayHitCollector kCollector;
        kPick.pAllCollector = &kCollector;
        kPick.pCloseCollector = 0;

        S7cd730_ParentCell* pCell = DAT_0107a104->pParentCell;
        S7cd730_World* pWorld = (pCell->uiCellFlags & 1) ? pCell->kHolder.FUN_00410f00() : DAT_01071564;
        bHit = pWorld->Pick(&kPick);
        float fHitFraction = DAT_00db9568;
        bHit |= FUN_007cbc10(&kPick, &fHitFraction);
        if (bHit)
        {
            bHit = FUN_007cc540(&kPick, this, GetBaseForm(), 0, 1, fHitFraction) != 0;
            if (bHit)
                fTimer = 0.0f;
        }
    }
    return bHit;
}

// @f3 0x007cc540 (community match, verified in this file)
// FUN_007cc540 -- a projectile's pick results, walked in hit order (structure as in FNV 0x009c0d80): trigger phantoms on
// layers 0x17/0x18 get the script trigger flags, a phantom that stands for a body (or a character controller) is
// picked again against the owner's own bodies, and the first hit the projectile accepts gets OnCollision. Without a
// hit the projectile is sent to the end of its ray; then the impact or fly-by sound is played.

#include <math.h>

struct S7cc540_Point
{
    float x;
    float y;
    float z;

    S7cc540_Point() {}
    S7cc540_Point(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    S7cc540_Point operator+(const S7cc540_Point& pt) const
    {
        return S7cc540_Point(x + pt.x, y + pt.y, z + pt.z);
    }
    S7cc540_Point operator-(const S7cc540_Point& pt) const
    {
        return S7cc540_Point(x - pt.x, y - pt.y, z - pt.z);
    }
    S7cc540_Point operator*(float fScalar) const
    {
        return S7cc540_Point(x * fScalar, y * fScalar, z * fScalar);
    }
    float Dot(const S7cc540_Point& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
    __forceinline float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    // Length and Unitize are header inlines the original did not expand everywhere: out of line, bodies visible.
    __declspec(noinline) float FUN_00432bd0() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
    __declspec(noinline) void FUN_00468d00()
    {
        float length = FUN_00432bd0();
        if (length > 1e-06f)
        {
            float recip = 1.0f / length;
            x *= recip;
            y *= recip;
            z *= recip;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }

    __forceinline void SetUnitized(const S7cc540_Point& pt)
    {
        *this = pt;
        FUN_00468d00();
    }
};

inline S7cc540_Point operator*(float fScalar, const S7cc540_Point& pt)
{
    return S7cc540_Point(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
}

extern const double DAT_00db88e8; // Havok to game units

inline float S7cc540_Lane(const hkVector4& v, int i)
{
    return (&v.x)[i];
}

inline void S7cc540_HkToNi(S7cc540_Point& out, const hkVector4& in)
{
    out.x = S7cc540_Lane(in, 0) * DAT_00db88e8;
    out.y = S7cc540_Lane(in, 1) * DAT_00db88e8;
    out.z = S7cc540_Lane(in, 2) * DAT_00db88e8;
}

struct S7cc540_Collidable // hkpCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char ownerOffset; // 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    signed char type; // 0x18: broad-phase type, 2 = phantom
};

struct S7cc540_ShapeHit // hkpShapeRayCastOutput
{
    hkVector4 m_normal;
    float m_hitFraction;
    int m_extraInfo;
    int m_pad0;
    int m_pad1;
    unsigned int m_shapeKeys[8];
    int m_shapeKeyIndex;

    // The compiler-made copy assignment, out of line in the original.
    __declspec(noinline) S7cc540_ShapeHit& FUN_007c8a50(const S7cc540_ShapeHit& other)
    {
        m_normal = other.m_normal;
        m_hitFraction = other.m_hitFraction;
        m_extraInfo = other.m_extraInfo;
        m_pad0 = other.m_pad0;
        m_pad1 = other.m_pad1;
        for (int k = 0; k < 8; k++)
            m_shapeKeys[k] = other.m_shapeKeys[k];
        m_shapeKeyIndex = other.m_shapeKeyIndex;
        return *this;
    }
};

struct S7cc540_RayHit : public S7cc540_ShapeHit // hkpWorldRayCastOutput
{
    const S7cc540_Collidable* m_rootCollidable; // 0x50

    // The compiler-made copy assignment, out of line in the original.
    __declspec(noinline) S7cc540_RayHit& FUN_007cb010(const S7cc540_RayHit& other)
    {
        FUN_007c8a50(other);
        m_rootCollidable = other.m_rootCollidable;
        return *this;
    }
};

struct S7cc540_Hits // hkInplaceArray<hkpWorldRayCastOutput, 8>
{
    S7cc540_RayHit* m_data;
    int m_size;
    int m_capacityAndFlags;
    S7cc540_RayHit m_storage[8];
};

struct S7cc540_Collector // hkpAllRayHitCollector
{
    void* vtbl;
    float m_earlyOutHitFraction;
    S7cc540_Hits m_hits; // 0x10

    S7cc540_Collector();  // FUN_0046a820
    ~S7cc540_Collector(); // FUN_0046a920
};

struct S7cc540_PickData // bhkPickData
{
    hkVector4 m_from;                   // 0x00
    hkVector4 m_to;                     // 0x10
    bool m_enableShapeCollectionFilter; // 0x20
    unsigned int m_filterInfo;          // 0x24
    int unk28;
    int unk2c;
    S7cc540_RayHit m_output;           // 0x30
    hkVector4 hkLength;                // 0x90
    char* pCache;                      // 0xa0
    void* pCloseCollector;             // 0xa4
    S7cc540_Collector* pAllCollector;  // 0xa8
    bool bPickFailed;                  // 0xac

    S7cc540_PickData(); // FUN_00468f40
    bool FUN_00432d10() const;
    S7cc540_Point FUN_00530b30(); // hit point, in game units

    // from, in game units
    __forceinline S7cc540_Point FromInGameUnits() const
    {
        S7cc540_Point from;
        from.x = m_from.x * DAT_00db88e8;
        from.y = m_from.y * DAT_00db88e8;
        from.z = m_from.z * DAT_00db88e8;
        return from;
    }

    // The same, out of line in the original (an inline helper the compiler did not expand there).
    __declspec(noinline) S7cc540_Point FUN_00434400() const
    {
        S7cc540_Point from;
        from.x = m_from.x * DAT_00db88e8;
        from.y = m_from.y * DAT_00db88e8;
        from.z = m_from.z * DAT_00db88e8;
        return from;
    }

    // length, in game units
    __declspec(noinline) S7cc540_Point FUN_007c8020() const
    {
        S7cc540_Point length;
        length.x = hkLength.x * DAT_00db88e8;
        length.y = hkLength.y * DAT_00db88e8;
        length.z = hkLength.z * DAT_00db88e8;
        return length;
    }

    // to, in game units
    __declspec(noinline) void FUN_00437150(S7cc540_Point& to)
    {
        if (FUN_00432d10())
        {
            m_to.x = hkLength.x + m_from.x;
            m_to.y = hkLength.y + m_from.y;
            m_to.z = hkLength.z + m_from.z;
            m_to.w = hkLength.w + m_from.w;
        }
        to.x = m_to.x * DAT_00db88e8;
        to.y = m_to.y * DAT_00db88e8;
        to.z = m_to.z * DAT_00db88e8;
    }
    void FUN_00469050(const S7cc540_Point& from);
    void FUN_0068daa0(const S7cc540_Point& length);
};

struct S7cc540_WorldObject : public bhkWorldObject
{
    virtual void w010(); virtual void w014(); virtual void w018(); virtual void w01c(); virtual void w020(); virtual void w024();
    virtual void w028(); virtual void w02c(); virtual void w030(); virtual void w034(); virtual void w038(); virtual void w03c();
    virtual void w040(); virtual void w044(); virtual void w048(); virtual void w04c(); virtual void w050(); virtual void w054();
    virtual void w058(); virtual void w05c(); virtual void w060(); virtual void w064(); virtual void w068(); virtual void w06c();
    virtual void w070(); virtual void w074(); virtual void w078(); virtual void w07c(); virtual void w080(); virtual void w084();
    virtual void w088(); virtual void w08c(); virtual void w090(); virtual void w094();
    virtual int w098();
};

struct S7cc540_Phantom // hkpPhantom
{
    int unk00;
    int unk04;
    int unk08;
    S7cc540_WorldObject* m_userData; // 0x0c
};

struct S7cc540_ColObj // bhkCollisionObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S7cc540_WorldObject* worldObject; // 0x10
};

struct S7cc540_Sound // TESSound
{
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
    const char* m_filename; // 0x34

    const char* FileName() const
    {
        return m_filename ? m_filename : "";
    }
};

struct S7cc540_ProjBase // BGSProjectile
{
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    S7cc540_Sound* sound; // 0x88
};

struct S7cc540_Ref // TESObjectREFR
{
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00c(); virtual void v010(); virtual void v014();
    virtual void v018(); virtual void v01c(); virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02c();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03c(); virtual void v040(); virtual void v044();
    virtual void v048(); virtual void v04c(); virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05c();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06c(); virtual void v070(); virtual void v074();
    virtual void v078(); virtual void v07c(); virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08c();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09c(); virtual void v0a0(); virtual void v0a4();
    virtual void v0a8(); virtual void v0ac(); virtual void v0b0(); virtual void v0b4(); virtual void v0b8(); virtual void v0bc();
    virtual void v0c0(); virtual void v0c4(); virtual void v0c8(); virtual void v0cc(); virtual void v0d0(); virtual void v0d4();
    virtual void v0d8(); virtual void v0dc(); virtual void v0e0(); virtual void v0e4(); virtual void v0e8(); virtual void v0ec();
    virtual void v0f0(); virtual void v0f4(); virtual void v0f8(); virtual void v0fc(); virtual void v100(); virtual void v104();
    virtual void v108(); virtual void v10c(); virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11c();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12c(); virtual void v130(); virtual void v134();
    virtual void v138(); virtual void v13c(); virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14c();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15c(); virtual void v160(); virtual void v164();
    virtual void v168(); virtual void v16c(); virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17c();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18c(); virtual void v190(); virtual void v194();
    virtual void v198(); virtual void v19c(); virtual void v1a0(); virtual void v1a4(); virtual void v1a8(); virtual void v1ac();
    virtual void v1b0(); virtual void v1b4(); virtual void v1b8(); virtual void v1bc(); virtual void v1c0(); virtual void v1c4();
    virtual void v1c8(); virtual void v1cc(); virtual void v1d0(); virtual void v1d4(); virtual void v1d8(); virtual void v1dc();
    virtual void v1e0(); virtual void v1e4(); virtual void v1e8(); virtual void v1ec(); virtual void v1f0();
    virtual S7cc540_Point* GetPos(); // 0x1f4

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S7cc540_ProjBase* baseForm; // 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int extra40; // 0x40
};

struct S7cc540_Projectile : public S7cc540_Ref
{
    virtual void p1f8(); virtual void p1fc(); virtual void p200(); virtual void p204(); virtual void p208(); virtual void p20c();
    virtual void p210(); virtual void p214(); virtual void p218(); virtual void p21c(); virtual void p220(); virtual void p224();
    virtual void p228(); virtual void p22c(); virtual void p230(); virtual void p234(); virtual void p238(); virtual void p23c();
    virtual void p240(); virtual void p244(); virtual void p248(); virtual void p24c(); virtual void p250(); virtual void p254();
    virtual void p258(); virtual void p25c(); virtual void p260(); virtual void p264(); virtual void p268(); virtual void p26c();
    virtual void p270(); virtual void p274(); virtual void p278(); virtual void p27c(); virtual void p280(); virtual void p284();
    virtual void p288(); virtual void p28c(); virtual void p290(); virtual void p294(); virtual void p298(); virtual void p29c();
    virtual void p2a0(); virtual void p2a4(); virtual void p2a8(); virtual void p2ac(); virtual void p2b0(); virtual void p2b4();
    virtual void p2b8(); virtual void p2bc(); virtual void p2c0(); virtual void p2c4(); virtual void p2c8(); virtual void p2cc();
    virtual void p2d0(); virtual void p2d4(); virtual void p2d8(); virtual void p2dc(); virtual void p2e0(); virtual void p2e4();
    virtual void p2e8(); virtual void p2ec(); virtual void p2f0(); virtual void p2f4(); virtual void p2f8(); virtual void p2fc();
    virtual void p300(); virtual void p304(); virtual void p308(); virtual void p30c(); virtual void p310(); virtual void p314();
    virtual void p318(); virtual void p31c(); virtual void p320(); virtual void p324(); virtual void p328();
    virtual bool OnCollision(S7cc540_Ref* ref, const S7cc540_Point& point, const S7cc540_Point& normal,
                             const S7cc540_Collidable* collidable, int shapeKey, int material); // 0x32c

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
    unsigned int flags; // 0xc0
    int unkc4;
    int unkc8;
    float range; // 0xcc
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    S7cc540_Ref* unkf0;
    S7cc540_Ref* unkf4;
    int unkf8;
    S7cc540_Point direction; // 0xfc

    __forceinline void SetDirectionFrom(S7cc540_Point delta)
    {
        direction = delta;
        direction.FUN_00468d00();
    }
};

struct S7cc540_SoundHandle // BSSoundHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    int state;

    bool FUN_00bd0290(float x, float y, float z); // set position
    bool FUN_00bd00c0(int flags);                 // play
};

struct S7cc540_Listener
{
    virtual void l00();
    virtual void l04();
    virtual void l08();
    virtual S7cc540_Point* GetPosition(); // 0x0c
};

struct S7cc540_Audio // BSAudioManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S7cc540_Listener* listener; // 0x10

    S7cc540_SoundHandle FUN_00bcfc40(const char* name, int flags, S7cc540_Sound* sound);
};

extern S7cc540_Audio* DAT_011790c8; // the audio manager
extern const S7cc540_Point DAT_00f725b0;
extern NiRTTI DAT_010f3430;

NiAVObject* __cdecl FUN_004780d0(const S7cc540_Collidable* collidable);
S7cc540_Ref* __cdecl FUN_004e7b90(NiAVObject* node);
void __cdecl Script_SetActionFlag(S7cc540_Ref* source, int* extra, unsigned int flags);
S7cc540_ColObj* __cdecl FUN_00477d90(NiAVObject* node);
bool __cdecl FUN_007c8ac0(S7cc540_Ref* ref, const S7cc540_Collidable* collidable, S7cc540_Projectile* projectile,
                          S7cc540_ProjBase* base);

// pdb: Projectile::ProcessTargetPick | Projectile.obj | fnv360_0822_retail, call_gap, low
// pdb params: apPickData, apProjectile, apProjectileBase, apHitFraction, bUseCharacterController, afWaterHitRatio
NiAVObject* __cdecl FUN_007cc540(S7cc540_PickData* pick, S7cc540_Projectile* projectile, S7cc540_ProjBase* base,
                                 float* hitTime, bool acceptCharController, float maxTime)
{
    if (!base && projectile)
        base = projectile->baseForm;
    bool done = false;
    NiAVObject* hitNode = 0;
    if (pick && pick->pAllCollector)
    {
        S7cc540_Point rayStart;
        S7cc540_HkToNi(rayStart, pick->m_from);
        S7cc540_Point rayDelta;
        S7cc540_HkToNi(rayDelta, pick->hkLength);
        bool bodyPhantom = false;
        S7cc540_Ref* phantomRef = 0;
        for (int i = 0; !done && i < pick->pAllCollector->m_hits.m_size; ++i)
        {
            S7cc540_RayHit hit = pick->pAllCollector->m_hits.m_data[i];
            if (hit.m_hitFraction > maxTime)
                continue;
            NiAVObject* node = FUN_004780d0(hit.m_rootCollidable);
            S7cc540_Ref* ref = FUN_004e7b90(node);
            if (node)
            {
                bool accept = true;
                const S7cc540_Collidable* collidable = hit.m_rootCollidable;
                S7cc540_Phantom* phantom =
                    collidable->type == 2 ? (S7cc540_Phantom*)((char*)collidable + collidable->ownerOffset) : 0;
                S7cc540_WorldObject* object = phantom ? phantom->m_userData : 0;
                if (object)
                {
                    accept = false;
                    if (projectile && ref &&
                        (object->FUN_00424270().GetLayer() == 0x17 || object->FUN_00424270().GetLayer() == 0x18))
                    {
                        Script_SetActionFlag(projectile, &ref->extra40, 0x80);
                        if (projectile->unkf0)
                            Script_SetActionFlag(projectile->unkf0, &ref->extra40, 0x100);
                    }
                    if (FUN_00424d20(&DAT_010f3430, object) ||
                        (acceptCharController && object->FUN_00424270().GetLayer() == 0x1e))
                    {
                        bodyPhantom = true;
                        phantomRef = ref;
                        S7cc540_ColObj* colObj = FUN_00477d90(node);
                        S7cc540_WorldObject* body = colObj ? colObj->worldObject : 0;
                        if (body)
                        {
                            if (((unsigned char)(body->FUN_00424270().iFilter >> 14)) & 1 || !body->w098())
                            {
                                S7cc540_PickData subPick;
                                S7cc540_Point subFrom = pick->FUN_00434400();
                                S7cc540_Point subDelta = pick->FUN_007c8020();
                                rayDelta.x = 2.0 * rayDelta.x;
                                rayDelta.y = 2.0 * rayDelta.y;
                                rayDelta.z = 2.0 * rayDelta.z;
                                subDelta.x = 2.0 * subDelta.x;
                                subDelta.y = 2.0 * subDelta.y;
                                subDelta.z = 2.0 * subDelta.z;
                                subPick.m_filterInfo = pick->m_filterInfo;
                                subPick.FUN_00469050(subFrom);
                                subPick.FUN_0068daa0(subDelta);
                                S7cc540_Collector subHits;
                                subPick.pAllCollector = &subHits;
                                subPick.pCloseCollector = 0;
                                if (FUN_007c9760((bhkPickData*)&subPick, node, false, true))
                                {
                                    if (subPick.pAllCollector->m_hits.m_size > 0)
                                    {
                                        hit.FUN_007cb010(subPick.pAllCollector->m_hits.m_data[0]);
                                        accept = true;
                                    }
                                }
                            }
                        }
                    }
                }
                if (!FUN_007c8ac0(ref, hit.m_rootCollidable, projectile, base))
                    accept = false;
                if (accept)
                {
                    if (projectile)
                    {
                        S7cc540_Point offset = rayDelta * hit.m_hitFraction;
                        S7cc540_Point point = rayStart + offset;
                        S7cc540_Point normal(hit.m_normal.x, hit.m_normal.y, hit.m_normal.z);
                        if (projectile->flags & 1)
                        {
                            projectile->range = offset.FUN_00432bd0();
                            projectile->SetDirectionFrom(offset);
                        }
                        int shapeKey = -1;
                        for (int k = 0; k < 8 && hit.m_shapeKeys[k] != 0xffffffff; ++k)
                            shapeKey = hit.m_shapeKeys[k];
                        done = projectile->OnCollision(ref, point, normal, hit.m_rootCollidable, shapeKey, 0x20);
                        if (done)
                            hitNode = node;
                    }
                    else
                    {
                        done = true;
                        hitNode = node;
                    }
                    if (done && hitTime)
                        *hitTime = hit.m_hitFraction;
                }
            }
        }
        if (projectile)
        {
            if (!done)
            {
                if (maxTime != 3.4028234663852886e+38)
                {
                    S7cc540_Point maxOffset = rayDelta * maxTime;
                    S7cc540_Point maxPoint = rayStart + maxOffset;
                    if (projectile->flags & 1)
                    {
                        projectile->range = maxOffset.Length();
                        projectile->SetDirectionFrom(maxOffset);
                    }
                    projectile->OnCollision(0, maxPoint, DAT_00f725b0, 0, -1, 8);
                }
            }
            if (!done && bodyPhantom)
            {
                if (phantomRef && phantomRef == (S7cc540_Ref*)DAT_0107a104)
                {
                    S7cc540_Point hitPos = pick->FUN_00530b30();
                    if (projectile->baseForm->sound)
                    {
                        int soundFlags = 0x102;
                        S7cc540_SoundHandle impactSound = DAT_011790c8->FUN_00bcfc40(
                            projectile->baseForm->sound->FileName(), soundFlags, projectile->baseForm->sound);
                        impactSound.FUN_00bd0290(hitPos.x, hitPos.y, hitPos.z);
                        impactSound.FUN_00bd00c0(0);
                    }
                }
            }
            else if (projectile->baseForm->sound && ((done && phantomRef != (S7cc540_Ref*)DAT_0107a104) || !done) &&
                     projectile->unkf4 != (S7cc540_Ref*)DAT_0107a104)
            {
                S7cc540_Listener* listener = DAT_011790c8->listener;
                if (listener)
                {
                    S7cc540_Point ear = *listener->GetPosition();
                    S7cc540_Point rayEnd;
                    if (phantomRef)
                        rayEnd = *phantomRef->GetPos();
                    else
                        pick->FUN_00437150(rayEnd);
                    S7cc540_Point from = pick->FromInGameUnits();
                    S7cc540_Point line = rayEnd - from;
                    S7cc540_Point toEar = ear - from;
                    float along = toEar.Dot(line);
                    float lineSq = line.Dot(line);
                    float t = along / lineSq;
                    S7cc540_Point closest = from + t * line;
                    float gap = (ear - closest).FUN_00432bd0();
                    if (gap < 600.0f)
                    {
                        int soundFlags = 0x102;
                        S7cc540_SoundHandle passSound = DAT_011790c8->FUN_00bcfc40(
                            projectile->baseForm->sound->FileName(), soundFlags, projectile->baseForm->sound);
                        // Both arms are the same call and are merged by the compiler. They stand in for references to
                        // this handle that the original has and that leave no code: with only its three calls the
                        // handle is counted after the hit points and the normal, and takes the hit offset's frame slot.
                        if (passSound.FUN_00bd0290(closest.x, closest.y, closest.z) || passSound.soundID)
                            passSound.FUN_00bd00c0(0);
                        else
                            passSound.FUN_00bd00c0(0);
                    }
                    // Stand-in for code the original compiles away after the sound: a point whose address is taken,
                    // declared after the handle's block. Without it the handle is the last address-taken local of
                    // this function, which keeps it out of every frame slot shared with a local whose address escapes.
                    if (0)
                    {
                        S7cc540_Point unusedPoint;
                        pick->FUN_00437150(unusedPoint);
                    }
                }
            }
        }
    }
    return hitNode;
}

// @f3 0x007c3770 (community match, verified in this file)
struct Point {float x,y,z; Point(){} Point(const float& a,const float& b,const float& c):x(a),y(b),z(c){}
 Point operator+(const Point& b)const{float a=x+b.x;float c=y+b.y;float d=z+b.z;return Point(a,c,d);}
 Point operator-(const Point& b)const{float a=x-b.x;float c=y-b.y;float d=z-b.z;return Point(a,c,d);}
 Point operator-()const{float a=-x;float c=-y;float d=-z;return Point(a,c,d);}
 void FUN_00468d00(); void FUN_00432b70(const Point&); Point FUN_004c8dc0(float f)const{float inv=1.0f/f;return Point(x*inv,y*inv,z*inv);}
};
struct __declspec(align(16)) Vector {float x,y,z,w;};
struct World {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;unsigned flags;int group;void* FUN_00410f00();};
struct Material {
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
 float factor;unsigned char unk60,id,unk62,unk63,weight;
};
struct MaterialMap {Material* FUN_00542a20(int);Material* FUN_00542a00(int);};
struct Node {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;Point* position;};
struct Shape {};
struct ShapeRef {virtual void slot00();virtual void slot04();virtual void slot08();virtual ShapeRef* parent();int unk04,unk08,unk0c,unk10,unk14;ShapeRef* fallback;};
struct RefActor {
 virtual void slot000();
 virtual void slot004();
 virtual void slot008();
 virtual void slot00c();
 virtual void slot010();
 virtual void slot014();
 virtual void slot018();
 virtual void slot01c();
 virtual void slot020();
 virtual void slot024();
 virtual void slot028();
 virtual void slot02c();
 virtual void slot030();
 virtual void slot034();
 virtual void slot038();
 virtual void slot03c();
 virtual void slot040();
 virtual void slot044();
 virtual void slot048();
 virtual void slot04c();
 virtual void slot050();
 virtual void slot054();
 virtual void slot058();
 virtual void slot05c();
 virtual void slot060();
 virtual void slot064();
 virtual void slot068();
 virtual void slot06c();
 virtual void slot070();
 virtual void slot074();
 virtual void slot078();
 virtual void slot07c();
 virtual void slot080();
 virtual void slot084();
 virtual void slot088();
 virtual void slot08c();
 virtual void slot090();
 virtual void slot094();
 virtual void slot098();
 virtual void slot09c();
 virtual void slot0a0();
 virtual void slot0a4();
 virtual void slot0a8();
 virtual void slot0ac();
 virtual void slot0b0();
 virtual void slot0b4();
 virtual void slot0b8();
 virtual void slot0bc();
 virtual void slot0c0();
 virtual void slot0c4();
 virtual void slot0c8();
 virtual void slot0cc();
 virtual void slot0d0();
 virtual void slot0d4();
 virtual void slot0d8();
 virtual void slot0dc();
 virtual void slot0e0();
 virtual void slot0e4();
 virtual void slot0e8();
 virtual void slot0ec();
 virtual void slot0f0();
 virtual void slot0f4();
 virtual void slot0f8();
 virtual void slot0fc();
 virtual bool eligible();
 virtual void slot104();
 virtual void slot108();
 virtual void slot10c();
 virtual void slot110();
 virtual void slot114();
 virtual void slot118();
 virtual void slot11c();
 virtual void slot120();
 virtual void slot124();
 virtual void slot128();
 virtual void slot12c();
 virtual void slot130();
 virtual void slot134();
 virtual void slot138();
 virtual void slot13c();
 virtual void slot140();
 virtual void slot144();
 virtual void slot148();
 virtual void slot14c();
 virtual void slot150();
 virtual void slot154();
 virtual void slot158();
 virtual void slot15c();
 virtual void slot160();
 virtual void slot164();
 virtual void slot168();
 virtual void slot16c();
 virtual void slot170();
 virtual void slot174();
 virtual void slot178();
 virtual void slot17c();
 virtual MaterialMap* materialMap();
 virtual void slot184();
 virtual void slot188();
 virtual void slot18c();
 virtual void slot190();
 virtual void slot194();
 virtual void slot198();
 virtual void slot19c();
 virtual void slot1a0();
 virtual void slot1a4();
 virtual void slot1a8();
 virtual void slot1ac();
 virtual void slot1b0();
 virtual void slot1b4();
 virtual void slot1b8();
 virtual void slot1bc();
 virtual void slot1c0();
 virtual void slot1c4();
 virtual void slot1c8();
 virtual void slot1cc();
 virtual Node* node();
 virtual void slot1d4();
 virtual void slot1d8();
 virtual void slot1dc();
 virtual void slot1e0();
 virtual void slot1e4();
 virtual void slot1e8();
 virtual void slot1ec();
 virtual void slot1f0();
 virtual void slot1f4();
 virtual void slot1f8();
 virtual void slot1fc();
 virtual void slot200();
 virtual void slot204();
 virtual void slot208();
 virtual void slot20c();
 virtual void slot210();
 virtual void slot214();
 virtual void slot218();
 virtual void slot21c();
 virtual void slot220();
 virtual void slot224();
 virtual void slot228();
 virtual void slot22c();
 virtual void slot230();
 virtual void slot234();
 virtual void slot238();
 virtual void slot23c();
 virtual void slot240();
 virtual void slot244();
 virtual void slot248();
 virtual void slot24c();
 virtual void slot250();
 virtual void slot254();
 virtual void slot258();
 virtual void slot25c();
 virtual void slot260();
 virtual void slot264();
 virtual void slot268();
 virtual void slot26c();
 virtual void slot270();
 virtual void slot274();
 virtual void slot278();
 virtual void slot27c();
 virtual void slot280();
 virtual void slot284();
 virtual void slot288();
 virtual void slot28c();
 virtual void slot290();
 virtual void slot294();
 virtual void slot298();
 virtual void slot29c();
 virtual void slot2a0();
 virtual void slot2a4();
 virtual void slot2a8();
 virtual void slot2ac();
 virtual void slot2b0();
 virtual void slot2b4();
 virtual void slot2b8();
 virtual void slot2bc();
 virtual void slot2c0();
 virtual void slot2c4();
 virtual void slot2c8();
 virtual void slot2cc();
 virtual void slot2d0();
 virtual void slot2d4();
 virtual void slot2d8();
 virtual void slot2dc();
 virtual void slot2e0();
 virtual void slot2e4();
 virtual void slot2e8();
 virtual void slot2ec();
 virtual void slot2f0();
 virtual void slot2f4();
 virtual void slot2f8();
 virtual void slot2fc();
 virtual void slot300();
 virtual void slot304();
 virtual void slot308();
 virtual void slot30c();
 virtual void slot310();
 virtual void slot314();
 virtual void slot318();
 virtual void slot31c();
 virtual void slot320();
 virtual void slot324();
 virtual void slot328();
 virtual void slot32c();
 virtual void slot330();
 virtual void slot334();
 virtual void slot338();
 virtual void slot33c();
 virtual void slot340();
 virtual void slot344();
 virtual void slot348();
 virtual void slot34c();
 virtual void slot350();
 virtual void slot354();
 virtual void slot358();
 virtual bool responseFlag();

 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 RefActor* base;int unk20,unk24,unk28,unk2c,unk30,unk34,unk38;World* world;
 // Stand-in body for FUN_006fe650 (matched in another unit; its source is not in this pack). It is faithful about
 // escapes only: like the real code it returns early when node() is null and otherwise copies its result out of a
 // local, so the caller's return slot is written and never passed on.
 __declspec(noinline) Point FUN_006fe650(bool b){Point r,d;if(!node()){r.x=r.y=r.z=0.0f;return r;}FUN_00701790(&d,&r,b);return d;}
 void FUN_00701790(Point*,Point*,bool);int FUN_006f8e30(ShapeRef*);
};
struct Contact {void* thing;int unk04,unk08,unk0c;int material;};
struct BodyInfo {int unk00;Point position;Point offset;int unk1c,unk20;int material;};
struct Other {BodyInfo* FUN_007c9260(RefActor*);Point FUN_007c2840();};
struct __declspec(align(16)) Hit {Vector position,normal;int unk20,unk24;void* body;int unk2c,unk30,unk34,unk38;void FUN_005742d0(const Hit* h){position=h->position;normal=h->normal;unk20=h->unk20;unk24=h->unk24;body=h->body;unk2c=h->unk2c;unk30=h->unk30;unk34=h->unk34;unk38=h->unk38;}};
struct Flag {unsigned char value;Flag(bool b):value(b){} operator bool()const{return value!=0;}};
struct Manager {int unk00,unk04,unk08,unk0c;Hit* hits;int count;void FUN_0056c5e0(void*);void FUN_0056c470(const Point*,const Point*,float);Flag HasHits(){return count>0;}};
extern Manager* __cdecl FUN_0056c910(int,int);
struct Selection {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 Selection(){FUN_007c3640();}~Selection(){FUN_007c36a0();}void FUN_007c3640();void FUN_007c36a0();
 bool FUN_007c35b0(Material*);void FUN_007c3730(Material*,unsigned int);Material* FUN_007c3540();
};
struct Rigid {void* FUN_00424250();};
extern Point DAT_0108edc8;
extern float DAT_00dc216c,DAT_00e070e0,DAT_00f60d98,DAT_00f60d14;extern const double DAT_00db88e8;
extern bool __cdecl FUN_005a19d0(void*);
extern ShapeRef* __cdecl FUN_004780d0(void*);
extern RefActor* __cdecl FUN_004e7b90(ShapeRef*);
extern int __cdecl FUN_004756f0(void*);
inline void __cdecl FUN_00432ce0(Point* out,const Vector* v){out->x=v->x*DAT_00db88e8;out->y=v->y*DAT_00db88e8;out->z=v->z*DAT_00db88e8;}
// FUN_00468f10 (Gamebryo point to Havok vector, scale 1/6.99904): its real body, called out of line here;
// it reproduces 0x00468f10 byte for byte (tools/f3diff 0x00468f10:37 gives 0).
inline Vector* __cdecl FUN_00468f10(Vector* out,const Point* in){out->x=in->x*0.1428767293691635;out->y=in->y*0.1428767293691635;out->z=in->z*0.1428767293691635;return out;}
extern Rigid* __cdecl FUN_008f2480(Node*,const Vector*,bool);
extern float __cdecl FUN_00583920(void*,Material*,float);
struct Tuning {
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
 unsigned char mode;
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
 float multiplier;};
struct Response {RefActor* source;RefActor* target;int unk08,unk0c;int material;float impulse;int unk18,unk1c;float amount;int unk24,unk28,unk2c;Tuning* tuning;int unk34;Point position,normal;int unk50;Contact* contact;unsigned flags;float friction;
 unsigned char FlagByte(){return (unsigned char)(flags>>11);}
 void FUN_007c3770(Other*);
};
// pdb: HitData::SetTargetedLimb | HitData.obj | fnv360_0822_retail, call_gap, low
// pdb params: apProjectile
void Response::FUN_007c3770(Other* other){
 if(!target || !target->eligible())return;
 MaterialMap* map=target->base->materialMap();
 Material* selected=0;
 bool search=false;
 if(contact){
  if(contact->material!=-1){
   if(map){selected=map->FUN_00542a20(contact->material);material=selected?selected->id:14;}
  }
  else if(FUN_005a19d0(contact->thing)){
   if(FlagByte()&1)material=0;
   else search=true;
  }
  else{
   material=14;
  }
 }
 else if(other){
  search=false;
  BodyInfo* body=other->FUN_007c9260(target);
  if(body){
   material=body->material;
   selected=map->FUN_00542a00(material);
   position=body->position;
   normal=other->FUN_007c2840();
   normal.FUN_00468d00();
   normal.FUN_00432b70(-body->offset);
   normal.FUN_00468d00();
  }
 }
 else{
  search=true;
 }
 if(search){
  Point origin=source->FUN_006fe650(true);
  Point rayEnd,rayDirection;
  source->FUN_00701790(&rayEnd,&rayDirection,false);
  Point copiedEnd=rayEnd;
  bool found=false;
  Selection selection;
  World* world=source->world;
  if(world){
   Manager* manager=FUN_0056c910((void*)source!=(void*)DAT_0107a104,true);
   manager->FUN_0056c5e0(world->flags&1?((World*)&world->group)->FUN_00410f00():DAT_01071564);
   manager->FUN_0056c470(&copiedEnd,&rayDirection,DAT_00dc216c);
   if(manager->HasHits()){
    for(int i=0;i<manager->count;++i){
     Hit hit;hit.FUN_005742d0(manager->hits+i);
     ShapeRef* body=FUN_004780d0(hit.body);RefActor* actor=FUN_004e7b90(body);
     if(actor && actor==target){
      origin.x=hit.position.x*DAT_00db88e8;origin.y=hit.position.y*DAT_00db88e8;origin.z=hit.position.z*DAT_00db88e8;
      if(FUN_004756f0(hit.body)){
       if(!found){found=true;FUN_00432ce0(&position,&hit.position);normal=rayDirection;}
       //PART1
       int id; if(body->parent()) { id=target->FUN_006f8e30(body->parent()); } else { body=body->fallback; id=target->FUN_006f8e30(body); }
       if(id!=-1 && id!=14){Material* m=map->FUN_00542a00(id);if(m && !selection.FUN_007c35b0(m))selection.FUN_007c3730(m,m->weight);}
      }
     }
    }
   }
  }
  if(!found && target->node() && source->node()){
   Point* p=target->node()->position;Point targetPosition=p?*p:DAT_0108edc8;
   p=source->node()->position;Point sourcePosition=p?*p:DAT_0108edc8;
   position=targetPosition+(source->FUN_006fe650(true)-targetPosition).FUN_004c8dc0(DAT_00e070e0);
   normal=targetPosition-sourcePosition;
   Vector center;FUN_00468f10(&center,&origin);Vector queryPoint;queryPoint.x=center.x;queryPoint.y=center.y;queryPoint.z=center.z;queryPoint.w=DAT_00dc216c;
   Rigid* rigid=FUN_008f2480(target->node(),&queryPoint,false);
   if(rigid){
    found=true;
    ShapeRef* body=FUN_004780d0(rigid->FUN_00424250());
    if(body){
     //PART2
     int id; if(body->parent()) { id=target->FUN_006f8e30(body->parent()); } else { body=body->fallback; id=target->FUN_006f8e30(body); }
     if(id!=-1){Material* m=map->FUN_00542a00(id);if(m&&!selection.FUN_007c35b0(m))selection.FUN_007c3730(m,m->weight);}
    }
   }
  }
  if(found){
   selected=selection.FUN_007c3540();material=selected?selected->id:-1;
  }
 }
 if(material==14){float value=impulse;amount=value;if(contact)amount=value*DAT_00f60d98;impulse=0.0f;return;}
 if(selected){material=selected->id;void* receiver=target?(char*)target+0x9c:0;amount=FUN_00583920(receiver,selected,impulse);if(target->responseFlag())amount=DAT_00f60d14*amount;
 float value=selected->factor;if(!tuning || tuning->mode<=2)value=1.0f;if(tuning)amount=tuning->multiplier*amount;if(value>friction)friction=value;}
}

// @f3 0x007ceb30 (community match, verified in this file)
extern const double DAT_00db8c48;
extern NiRTTI DAT_010f3430;
namespace f3m_007ceb30 {
struct S007ceb30_Point3
{
    float x;
    float y;
    float z;

    S007ceb30_Point3() {}
    S007ceb30_Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}

    S007ceb30_Point3 operator*(float fScalar) const
    {
        return S007ceb30_Point3(x * fScalar, y * fScalar, z * fScalar);
    }

    S007ceb30_Point3 operator+(const S007ceb30_Point3& kPt) const
    {
        return S007ceb30_Point3(x + kPt.x, y + kPt.y, z + kPt.z);
    }


    void FUN_00468d00();
};

struct S007ceb30_SimdReal
{
    float m_real;

    operator float() const
    {
        return m_real;
    }
};

inline S007ceb30_SimdReal S007ceb30_GetComponent(const hkVector4& kVec, int i)
{
    S007ceb30_SimdReal kReal;
    kReal.m_real = (&kVec.x)[i];
    return kReal;
}

struct S007ceb30_Matrix3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;

    void NiMatrix3_MakeZRotation(float fAngle);
    void FUN_004bbca0(float fAngle);
    S007ceb30_Matrix3 operator*(const S007ceb30_Matrix3& kMat) const;

    S007ceb30_Point3 GetCol1() const
    {
        return S007ceb30_Point3(m01, m11, m21);
    }
};

__forceinline S007ceb30_Point3 S007ceb30_GetRay(const S007ceb30_Matrix3& kRot)
{
    S007ceb30_Point3 kDir = kRot.GetCol1();
    kDir.FUN_00468d00();
    return S007ceb30_Point3(kDir.x * DAT_00db8c48, kDir.y * DAT_00db8c48, kDir.z * DAT_00db8c48);
}

struct S007ceb30_Collidable
{
    const hkpShape* m_shape;
    unsigned int m_shapeKey;
    const void* m_motion;
    const void* m_parent;
    signed char m_ownerOffset;
    char m_forceCollideOntoPpu;
    short m_shapeSizeOnSpu;
    int m_id;
    char m_type;

    void* getOwner() const
    {
        return (char*)this + m_ownerOffset;
    }
};

struct S007ceb30_Hit : public hkpShapeRayCastOutput
{
    S007ceb30_Collidable* m_rootCollidable;

    S007ceb30_Hit(const S007ceb30_Hit& kOther);
};

struct S007ceb30_Collector : public hkpAllRayHitCollector
{
    float m_earlyOutHitFraction;
    int unk08;
    int unk0C;
    S007ceb30_Hit* m_hits;
    int m_size;
    int m_capacityAndFlags;
    S007ceb30_Hit m_storage[8];

    S007ceb30_Collector();
    ~S007ceb30_Collector();
};

struct S007ceb30_PickData : public bhkPickData
{
    S007ceb30_PickData();
    // Guess: visible __declspec(noinline) body of bhkPickData::SetFrom (from unit_956ed41b78b7.cpp) so escape analysis sees kPos is only read and does not mark kPos address-taken
    __declspec(noinline) void FUN_00469050(const S007ceb30_Point3& kFrom) { m_from.x = kFrom.x * 0.1428767293691635; m_from.y = kFrom.y * 0.1428767293691635; m_from.z = kFrom.z * 0.1428767293691635; }
    void FUN_0068daa0(const S007ceb30_Point3& kTo);
};

struct S007ceb30_NiObj
{
    virtual ~S007ceb30_NiObj();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
};

inline bool S007ceb30_IsKindOf(const NiRTTI* pRTTI, const bhkWorldObject* pObj)
{
    for (const NiRTTI* p = ((const S007ceb30_NiObj*)pObj)->GetRTTI(); p; p = p->m_pkBaseRTTI)
    {
        if (p == pRTTI)
            return true;
    }
    return false;
}


struct S007ceb30_RigidBody : public bhkWorldObject
{
    virtual void vrb010();
    virtual void vrb014();
    virtual void vrb018();
    virtual void vrb01c();
    virtual void vrb020();
    virtual void vrb024();
    virtual void vrb028();
    virtual void vrb02c();
    virtual void vrb030();
    virtual void vrb034();
    virtual void vrb038();
    virtual void vrb03c();
    virtual void vrb040();
    virtual void vrb044();
    virtual void vrb048();
    virtual void vrb04c();
    virtual void vrb050();
    virtual void vrb054();
    virtual void vrb058();
    virtual void vrb05c();
    virtual void vrb060();
    virtual void vrb064();
    virtual void vrb068();
    virtual void vrb06c();
    virtual void vrb070();
    virtual void vrb074();
    virtual void vrb078();
    virtual void vrb07c();
    virtual void vrb080();
    virtual void vrb084();
    virtual void vrb088();
    virtual void vrb08c();
    virtual void vrb090();
    virtual void vrb094();
    virtual int IsFixed();
};

struct S007ceb30_Ref
{
    virtual ~S007ceb30_Ref();
    virtual void vref004();
    virtual void vref008();
    virtual void vref00c();
    virtual void vref010();
    virtual void vref014();
    virtual void vref018();
    virtual void vref01c();
    virtual void vref020();
    virtual void vref024();
    virtual void vref028();
    virtual void vref02c();
    virtual void vref030();
    virtual void vref034();
    virtual void vref038();
    virtual void vref03c();
    virtual void vref040();
    virtual void vref044();
    virtual void vref048();
    virtual void vref04c();
    virtual void vref050();
    virtual void vref054();
    virtual void vref058();
    virtual void vref05c();
    virtual void vref060();
    virtual void vref064();
    virtual void vref068();
    virtual void vref06c();
    virtual void vref070();
    virtual void vref074();
    virtual void vref078();
    virtual void vref07c();
    virtual void vref080();
    virtual void vref084();
    virtual void vref088();
    virtual void vref08c();
    virtual void vref090();
    virtual void vref094();
    virtual void vref098();
    virtual void vref09c();
    virtual void vref0a0();
    virtual void vref0a4();
    virtual void vref0a8();
    virtual void vref0ac();
    virtual void vref0b0();
    virtual void vref0b4();
    virtual void vref0b8();
    virtual void vref0bc();
    virtual void vref0c0();
    virtual void vref0c4();
    virtual void vref0c8();
    virtual void vref0cc();
    virtual void vref0d0();
    virtual void vref0d4();
    virtual void vref0d8();
    virtual void vref0dc();
    virtual void vref0e0();
    virtual void vref0e4();
    virtual void vref0e8();
    virtual void vref0ec();
    virtual void vref0f0();
    virtual void vref0f4();
    virtual void vref0f8();
    virtual void vref0fc();
    virtual void vref100();
    virtual void vref104();
    virtual void vref108();
    virtual void vref10c();
    virtual void vref110();
    virtual void vref114();
    virtual void vref118();
    virtual void vref11c();
    virtual void vref120();
    virtual void vref124();
    virtual void vref128();
    virtual void vref12c();
    virtual void vref130();
    virtual void vref134();
    virtual void vref138();
    virtual void vref13c();
    virtual void vref140();
    virtual void vref144();
    virtual void vref148();
    virtual void vref14c();
    virtual void vref150();
    virtual void vref154();
    virtual void vref158();
    virtual void vref15c();
    virtual void vref160();
    virtual void vref164();
    virtual void vref168();
    virtual void vref16c();
    virtual void vref170();
    virtual void vref174();
    virtual void vref178();
    virtual void vref17c();
    virtual void vref180();
    virtual void vref184();
    virtual void vref188();
    virtual void vref18c();
    virtual void vref190();
    virtual void vref194();
    virtual void vref198();
    virtual void vref19c();
    virtual void vref1a0();
    virtual void vref1a4();
    virtual void vref1a8();
    virtual void vref1ac();
    virtual void vref1b0();
    virtual void vref1b4();
    virtual void vref1b8();
    virtual void vref1bc();
    virtual void vref1c0();
    virtual void vref1c4();
    virtual void vref1c8();
    virtual void vref1cc();
    virtual NiAVObject* GetCurrent3D();
    int unk04;
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
    int unk40;
};

struct S007ceb30_Actor
{
    virtual ~S007ceb30_Actor();
    virtual void vact004();
    virtual void vact008();
    virtual void vact00c();
    virtual void vact010();
    virtual void vact014();
    virtual void vact018();
    virtual void vact01c();
    virtual void vact020();
    virtual void vact024();
    virtual void vact028();
    virtual void vact02c();
    virtual void vact030();
    virtual void vact034();
    virtual void vact038();
    virtual void vact03c();
    virtual void vact040();
    virtual void vact044();
    virtual void vact048();
    virtual void vact04c();
    virtual void vact050();
    virtual void vact054();
    virtual void vact058();
    virtual void vact05c();
    virtual void vact060();
    virtual void vact064();
    virtual void vact068();
    virtual void vact06c();
    virtual void vact070();
    virtual void vact074();
    virtual void vact078();
    virtual void vact07c();
    virtual void vact080();
    virtual void vact084();
    virtual void vact088();
    virtual void vact08c();
    virtual void vact090();
    virtual void vact094();
    virtual void vact098();
    virtual void vact09c();
    virtual void vact0a0();
    virtual void vact0a4();
    virtual void vact0a8();
    virtual void vact0ac();
    virtual void vact0b0();
    virtual void vact0b4();
    virtual void vact0b8();
    virtual void vact0bc();
    virtual void vact0c0();
    virtual void vact0c4();
    virtual void vact0c8();
    virtual void vact0cc();
    virtual void vact0d0();
    virtual void vact0d4();
    virtual void vact0d8();
    virtual void vact0dc();
    virtual void vact0e0();
    virtual void vact0e4();
    virtual void vact0e8();
    virtual void vact0ec();
    virtual void vact0f0();
    virtual void vact0f4();
    virtual void vact0f8();
    virtual void vact0fc();
    virtual void vact100();
    virtual void vact104();
    virtual void vact108();
    virtual void vact10c();
    virtual void vact110();
    virtual void vact114();
    virtual void vact118();
    virtual void vact11c();
    virtual void vact120();
    virtual void vact124();
    virtual void vact128();
    virtual void vact12c();
    virtual void vact130();
    virtual void vact134();
    virtual void vact138();
    virtual void vact13c();
    virtual void vact140();
    virtual void vact144();
    virtual void vact148();
    virtual void vact14c();
    virtual void vact150();
    virtual void vact154();
    virtual void vact158();
    virtual void vact15c();
    virtual void vact160();
    virtual void vact164();
    virtual void vact168();
    virtual void vact16c();
    virtual void vact170();
    virtual void vact174();
    virtual void vact178();
    virtual void vact17c();
    virtual void vact180();
    virtual void vact184();
    virtual void vact188();
    virtual void vact18c();
    virtual void vact190();
    virtual void vact194();
    virtual void vact198();
    virtual void vact19c();
    virtual void vact1a0();
    virtual void vact1a4();
    virtual void vact1a8();
    virtual void vact1ac();
    virtual void vact1b0();
    virtual void vact1b4();
    virtual void vact1b8();
    virtual void vact1bc();
    virtual void vact1c0();
    virtual void vact1c4();
    virtual void vact1c8();
    virtual void vact1cc();
    virtual NiAVObject* GetCurrent3D();
    virtual void vact1d4();
    virtual void vact1d8();
    virtual void vact1dc();
    virtual void vact1e0();
    virtual void vact1e4();
    virtual void vact1e8();
    virtual void vact1ec();
    virtual void vact1f0();
    virtual const S007ceb30_Point3* GetPos();
    virtual void vact1f8();
    virtual void vact1fc();
    virtual void vact200();
    virtual void vact204();
    virtual void vact208();
    virtual void vact20c();
    virtual void vact210();
    virtual void vact214();
    virtual void vact218();
    virtual void vact21c();
    virtual void vact220();
    virtual void vact224();
    virtual void vact228();
    virtual void vact22c();
    virtual void vact230();
    virtual void vact234();
    virtual void vact238();
    virtual void vact23c();
    virtual void vact240();
    virtual void vact244();
    virtual void vact248();
    virtual void vact24c();
    virtual void vact250();
    virtual void vact254();
    virtual void vact258();
    virtual void vact25c();
    virtual void vact260();
    virtual void vact264();
    virtual void vact268();
    virtual void vact26c();
    virtual void vact270();
    virtual void vact274();
    virtual void vact278();
    virtual void vact27c();
    virtual void vact280();
    virtual void vact284();
    virtual void vact288();
    virtual void vact28c();
    virtual void vact290();
    virtual void vact294();
    virtual void vact298();
    virtual void vact29c();
    virtual void vact2a0();
    virtual void vact2a4();
    virtual void vact2a8();
    virtual void vact2ac();
    virtual void vact2b0();
    virtual void vact2b4();
    virtual void vact2b8();
    virtual float GetAngleX(int a);
    virtual void vact2c0();
    virtual void vact2c4();
    virtual void vact2c8();
    virtual void vact2cc();
    virtual void vact2d0();
    virtual void vact2d4();
    virtual void vact2d8();
    virtual void vact2dc();
    virtual void vact2e0();
    virtual void vact2e4();
    virtual void vact2e8();
    virtual void vact2ec();
    virtual void vact2f0();
    virtual void vact2f4();
    virtual void vact2f8();
    virtual void vact2fc();
    virtual void vact300();
    virtual void vact304();
    virtual void vact308();
    virtual void vact30c();
    virtual void vact310();
    virtual void vact314();
    virtual void vact318();
    virtual void vact31c();
    virtual void vact320();
    virtual void vact324();
    virtual void vact328();
    virtual void Hit(S007ceb30_Ref* apRef, const S007ceb30_Point3* apPos, const S007ceb30_Point3* apNormal, S007ceb30_Collidable* apColl, int aiArg, int aiFlags);
    int unk04;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    float FUN_00765430();
};

struct S007ceb30_Contact
{
    hkVector4 m_position;
    hkVector4 m_normal;
    int unk20;
    int unk24;
    S007ceb30_Collidable* m_rootCollidable;
    int unk2C;
};

void* FUN_008f1bf0(S007ceb30_Collidable* apColl);
S007ceb30_Ref* FUN_004e7b90(void* apObj);
void Script_SetActionFlag(S007ceb30_Actor* apActor, int* apData, int aiSize);

struct S007ceb30_Owner
{
    int unk00;
    int unk04;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S007ceb30_Actor* unk250;

    void FUN_007ceb30(S007ceb30_Contact* apContact);
};

// pdb: ProjectileListener::contactPointAddedCallback | ProjectileListener.obj | fnv360_0822_retail, vtable, medium
// pdb params: apProxy, point
void S007ceb30_Owner::FUN_007ceb30(S007ceb30_Contact* apContact)
{
    bool bMiss = true;
    S007ceb30_Actor* pActor = unk250;
    if (!pActor)
        return;

    S007ceb30_Ref* pRef = 0;
    S007ceb30_Collidable* pRoot = apContact->m_rootCollidable;
    void* pObj = FUN_008f1bf0(pRoot);
    if (pObj)
        pRef = FUN_004e7b90(pObj);

    S007ceb30_Point3 kFrom;
    kFrom.x = S007ceb30_GetComponent(apContact->m_position, 0) * DAT_00db88e8;
    kFrom.y = S007ceb30_GetComponent(apContact->m_position, 1) * DAT_00db88e8;
    kFrom.z = S007ceb30_GetComponent(apContact->m_position, 2) * DAT_00db88e8;
    S007ceb30_Point3 kNormal;
    kNormal.x = apContact->m_normal.x;
    kNormal.y = apContact->m_normal.y;
    kNormal.z = apContact->m_normal.z;
    S007ceb30_Collidable* pColl = apContact->m_rootCollidable;
    int iArg = apContact->unk2C;

    hkpWorldObject* pOwner;
    bhkWorldObject* pWorldObj =
        pColl->m_type == 2 ? ((pOwner = (hkpWorldObject*)pColl->getOwner()) ? (bhkWorldObject*)pOwner->m_userData : 0) : 0;

    if (pRef && pWorldObj &&
        (pWorldObj->GetCollisionFilterInline().GetLayer() == 0x17 || pWorldObj->FUN_00424270().GetLayer() == 0x18))
    {
        Script_SetActionFlag(pActor, &pRef->unk40, 0x80);
        // Guess: identical-arms select on spilled pColl keeps stack slots identical while assigning pActor->unkF0 to ebx after esi and edi
        pActor = (S007ceb30_Actor*)(((int)pColl < 0) ? pActor->unkF0 : pActor->unkF0);
        if (pActor)
            Script_SetActionFlag(pActor, &pRef->unk40, 0x100);
        return;
    }

    if (pWorldObj && (S007ceb30_IsKindOf(&DAT_010f3430, pWorldObj) || pWorldObj->FUN_00424270().GetLayer() == 0x1e))
    {
        bMiss = true;
        NiAVObject* p3D = pRef ? pRef->GetCurrent3D() : 0;
        bhkCollisionObject* pColObj = (bhkCollisionObject*)FUN_00477d90(p3D);
        if (pColObj)
        {
            S007ceb30_RigidBody* pRigidBody = (S007ceb30_RigidBody*)(bhkWorldObject*)pColObj->spWorldObj;
            if (pRigidBody && (((unsigned char)(pRigidBody->FUN_00424270().iFilter >> 14) & 1) || !pRigidBody->IsFixed()))
            {

                S007ceb30_PickData kPick;
                S007ceb30_Point3 kPos = *pActor->GetPos();
                S007ceb30_Matrix3 kRot;
                kRot.NiMatrix3_MakeZRotation(pActor->GetAngleX(0));
                S007ceb30_Matrix3 kRotZ;
                kRotZ.FUN_004bbca0(pActor->FUN_00765430());
                kRot = kRot * kRotZ;
                S007ceb30_Point3 kRay = S007ceb30_GetRay(kRot);
                S007ceb30_Point3 kTo = kRay;
                kPick.FUN_00469050(kPos);
                kPick.FUN_0068daa0(kTo);

                S007ceb30_Collector kCollector;
                kPick.pAllCollector = &kCollector;
                kPick.pCloseCollector = 0;
                if (FUN_007c9760(&kPick, p3D, false, true) && ((S007ceb30_Collector*)kPick.GetAllCollector())->m_size > 0)
                {
                    bMiss = false;
                    S007ceb30_Hit kHit(((S007ceb30_Collector*)kPick.GetAllCollector())->m_hits[0]);
                    kFrom = kPos + kRay * kHit.m_hitFraction;
                    pColl = kHit.m_rootCollidable;
                    kNormal.x = kHit.m_normal.x;
                    kNormal.y = kHit.m_normal.y;
                    kNormal.z = kHit.m_normal.z;
                    for (int i = 0; i < 8; i++)
                    {
                        if ((&kHit.m_shapeKey0)[i] == 0xffffffff)
                            break;
                    }
                }
            }
        }
        if (bMiss)
            return;
    }

    pActor->Hit(pRef, &kFrom, &kNormal, pColl, iArg, 0x20);
}
}   // namespace f3m_007ceb30

// @f3 0x007cdd90 (community match, verified in this file)
#include <math.h>

extern const double DAT_00db7de8;
extern const float DAT_0108cf70;
extern bool DAT_0108cf54;
extern unsigned int DAT_00f79e58;
void __cdecl FUN_00887da0(const char* apFormat, ...);

class S7cdd90_Point3 : public NiPoint3
{
  public:
    S7cdd90_Point3() {}
    S7cdd90_Point3(const NiPoint3& kPt) : NiPoint3(kPt) {}
    S7cdd90_Point3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    S7cdd90_Point3 operator+(const NiPoint3& kPt) const { return S7cdd90_Point3(x + kPt.x, y + kPt.y, z + kPt.z); }
    S7cdd90_Point3 operator-(const NiPoint3& kPt) const { return S7cdd90_Point3(x - kPt.x, y - kPt.y, z - kPt.z); }
    S7cdd90_Point3 operator*(float fScale) const { return S7cdd90_Point3(x * fScale, y * fScale, z * fScale); }
    void FUN_00468d00();
    S7cdd90_Point3& operator/=(float scale)
    {
        float inverse = 1.0f / scale;
        x *= inverse;
        y *= inverse;
        z *= inverse;
        return *this;
    }
    S7cdd90_Point3& FUN_006b1f50(float fScale);
};

void S7cdd90_Point3::FUN_00468d00()
{
    float fLength = sqrt(x * x + y * y + z * z);
    if (fLength > 1e-06f)
    {
        float fRecip = 1.0f / fLength;
        x *= fRecip;
        y *= fRecip;
        z *= fRecip;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}

S7cdd90_Point3& S7cdd90_Point3::FUN_006b1f50(float fScale)
{
    x *= fScale;
    y *= fScale;
    z *= fScale;
    return *this;
}

struct S7cdd90_ColorA
{
    float r, g, b, a;
    S7cdd90_ColorA(float fR, float fG, float fB, float fA) { r = fR; g = fG; b = fB; a = fA; }
};

class S7cdd90_Matrix3
{
  public:
    float m_pEntry[3][3];
    void MakeZRotation(float fAngle)
    {
        float sn, cs;
        fnv_SinCos(fAngle, sn, cs);
        m_pEntry[0][0] = cs;
        m_pEntry[0][1] = sn;
        m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = -sn;
        m_pEntry[1][1] = cs;
        m_pEntry[1][2] = 0.0f;
        m_pEntry[2][0] = 0.0f;
        m_pEntry[2][1] = 0.0f;
        m_pEntry[2][2] = 1.0f;
    }
    void MakeXRotation(float fAngle)
    {
        float sn, cs;
        fnv_SinCos(fAngle, sn, cs);
        m_pEntry[0][0] = 1.0f;
        m_pEntry[0][1] = 0.0f;
        m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = 0.0f;
        m_pEntry[1][1] = cs;
        m_pEntry[1][2] = sn;
        m_pEntry[2][0] = 0.0f;
        m_pEntry[2][1] = -sn;
        m_pEntry[2][2] = cs;
    }
    void GetCol(unsigned int uiCol, NiPoint3& kCol) const
    {
        kCol.x = m_pEntry[0][uiCol];
        kCol.y = m_pEntry[1][uiCol];
        kCol.z = m_pEntry[2][uiCol];
    }
    S7cdd90_Matrix3 FUN_00424020(const S7cdd90_Matrix3& kMat) const;
};

inline float S7cdd90_GetComponent(const hkVector4& kVec, int i)
{
    return (&kVec.x)[i];
}

inline S7cdd90_Point3 S7cdd90_HK2NI(const hkVector4& kVec)
{
    S7cdd90_Point3 kPt;
    kPt.x = S7cdd90_GetComponent(kVec, 0) * DAT_00db88e8;
    kPt.y = S7cdd90_GetComponent(kVec, 1) * DAT_00db88e8;
    kPt.z = S7cdd90_GetComponent(kVec, 2) * DAT_00db88e8;
    return kPt;
}

inline float S7cdd90_Abs(float fValue)
{
    return (float)fabs(fValue);
}

inline float S7cdd90_Max(float fA, float fB)
{
    return fA > fB ? fA : fB;
}

struct S7cdd90_hkWorld
{
    char m_acPad[0x2d0];
    hkVector4 m_kBroadphaseMin;
    hkVector4 m_kBroadphaseMax;
};

struct S7cdd90_World
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual S7cdd90_hkWorld* GethkWorld();
    void FUN_008d3eb0(NiPoint3* apCenter);
};

struct S7cdd90_WorldHolder
{
    S7cdd90_World* FUN_00410f00();
};

struct S7cdd90_Cell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int uiCellFlags;
    S7cdd90_WorldHolder kHolder;

    float FUN_004d5350();

    S7cdd90_World* GetWorld() { return (uiCellFlags & 1) ? kHolder.FUN_00410f00() : (S7cdd90_World*)DAT_01071564; }
};

struct S7cdd90_String
{
    const char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;

    const char* c_str() const { return m_pString ? m_pString : ""; }
};

struct S7cdd90_BaseForm
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf4a();
    virtual void vf4b();
    virtual const char* GetFullName();
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
    S7cdd90_String m_kName;

    int TESForm_GetFormEditorIDLength();
};

struct S7cdd90_CollHolder
{
    int unk00;
    int unk04;
    char* pFilter;

    char* GetFilter() const { return pFilter; }
};

struct S7cdd90_PickData : public S7cd730_PickData
{
    NiPoint3& FUN_00437150(NiPoint3& endPoint);
    NiPoint3& NiGetFrom(NiPoint3& startPoint) const
    {
        startPoint.x = m_from.x * DAT_00db88e8;
        startPoint.y = m_from.y * DAT_00db88e8;
        startPoint.z = m_from.z * DAT_00db88e8;
        return startPoint;
    }
    void FUN_00469050(const NiPoint3& kFrom);
};

struct S7cdd90_Line;
S7cdd90_Line* __cdecl FUN_0047a4e0(const NiPoint3& kStart, const S7cdd90_ColorA& kStartColor, const NiPoint3& kEnd,
                                   const S7cdd90_ColorA& kEndColor, bool abArg);

struct S7cdd90_LineManager
{
    void FUN_00433df0(S7cdd90_Line* apLine, float afTime);
};
extern S7cdd90_LineManager* DAT_0107a0d8;

struct S7cdd90_Projectile : public S7cd730_Ref
{
    virtual void vf7e();
    virtual void vf7f();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf8a();
    virtual void vf8b();
    virtual void vf8c();
    virtual void vf8d();
    virtual void vf8e();
    virtual void vf8f();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf9a();
    virtual void vf9b();
    virtual void vf9c();
    virtual void vf9d();
    virtual void vf9e();
    virtual void vf9f();
    virtual void vfa0();
    virtual void vfa1();
    virtual void vfa2();
    virtual void vfa3();
    virtual void vfa4();
    virtual void vfa5();
    virtual void vfa6();
    virtual void vfa7();
    virtual void vfa8();
    virtual void vfa9();
    virtual void vfaa();
    virtual void vfab();
    virtual void vfac();
    virtual void vfad();
    virtual void vfae();
    virtual float GetAngle(int aiAxis);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    S7cdd90_BaseForm* pBaseForm;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S7cdd90_Cell* pParentCell;
    int unk040[0x23];
    float fRange;
    int unk0d0[9];
    n7ca320::Target* pShooter;
    int unk0f8[4];
    float fGravity;
    int unk10c[2];
    S7cdd90_CollHolder* pCollHolder;

    S7cdd90_Cell* GetParentCell() const { return pParentCell; }
    S7cdd90_BaseForm* GetBaseForm() const { return pBaseForm; }
    n7ca320::Target* GetShooter() const { return pShooter; }
    float GetRange() const { return fRange; }
    float GetGravity() const { return fGravity; }
    S7cdd90_CollHolder* GetHolder() const { return pCollHolder; }
    float FUN_00765430();
    n7ca320::Controller* FUN_00764ea0();
    bool FUN_007cbc10(S7cdd90_PickData* apPickData, float* afWaterHitRatio);
    void FUN_007c8650();
    bool FUN_007cdd90();
};
int __cdecl FUN_007cc540(S7cd730_PickData* apPickData, S7cdd90_Projectile* apProjectile, S7cdd90_BaseForm* apBaseForm,
                         int aiArg4, int aiArg5, float afHitFraction);

inline unsigned int S7cdd90_GetNewSystemGroup()
{
    DAT_00f79e58 = (DAT_00f79e58 + 1) & 0xffff;
    if (!DAT_00f79e58)
        DAT_00f79e58 = 10;
    return DAT_00f79e58;
}

bool S7cdd90_Projectile::FUN_007cbc10(S7cdd90_PickData* apPickData, float* afWaterHitRatio)
{
    S7cdd90_Cell* pcell = GetParentCell();
    if (pcell && (pcell->uiCellFlags & 2))
    {
        float fwaterHeight = pcell->FUN_004d5350();
        S7cdd90_Point3 startPoint;
        apPickData->NiGetFrom(startPoint);
        S7cdd90_Point3 endPoint;
        apPickData->FUN_00437150(endPoint);
        if (startPoint.z > fwaterHeight && endPoint.z <= fwaterHeight)
        {
            S7cdd90_Point3 length = endPoint - startPoint;
            float ftoWater = fwaterHeight - startPoint.z;
            *afWaterHitRatio = ftoWater / length.z;
            return true;
        }
    }
    return false;
}

// pdb: Projectile::RunTargetPick | Projectile.obj | fnv360_0822_retail, vtable, medium
bool S7cdd90_Projectile::FUN_007cdd90()
{
    if (!GetParentCell() || !GetParentCell()->GetWorld())
        return false;
    S7cdd90_World* pw = GetParentCell()->GetWorld();
    S7cdd90_PickData pd;
    S7cdd90_Point3 origin = *GetPos();
    S7cdd90_Matrix3 rot;
    rot.MakeZRotation(GetAngle(0));
    S7cdd90_Matrix3 rot2;
    rot2.MakeXRotation(FUN_00765430());
    rot = rot.FUN_00424020(rot2);
    bool bhit;
    {
    S7cdd90_Point3 direction;
    rot.GetCol(1, direction);
    direction.FUN_00468d00();

    CFilter filter;
    if (FUN_00764ea0())
    {
        filter = FUN_00764ea0()->FUN_0061f4f0();
    }
    else
    {
        unsigned int uiGroup;
        if (GetShooter() && GetShooter()->IsActor())
        {
            n7ca320::Filter kShooterFilter;
            uiGroup = GetShooter()->FUN_00766b00(&kShooterFilter)->Group();
        }
        else
        {
            uiGroup = S7cdd90_GetNewSystemGroup();
        }
        filter.iFilter = (uiGroup << 16) | 6;
    }
    if (GetHolder() && GetHolder()->GetFilter())
        pd.pCache = GetHolder()->GetFilter();

    S7cdd90_Point3 kray = direction * (GetRange() - GetGravity());
    S7cdd90_Point3 klength(kray.x, kray.y, kray.z);
    {
        S7cdd90_Point3 kbroadphaseCenter;
        pw->FUN_008d3eb0(&kbroadphaseCenter);
        S7cdd90_hkWorld* paw = pw->GethkWorld();
        S7cdd90_Point3 kbroadphaseUpperExtent = S7cdd90_HK2NI(paw->m_kBroadphaseMax);
        S7cdd90_Point3 kbroadphaseLowerExtent = S7cdd90_HK2NI(paw->m_kBroadphaseMin);
        S7cdd90_Point3 kbroadphaseDiagonal = kbroadphaseUpperExtent - kbroadphaseLowerExtent;
        kbroadphaseDiagonal /= 2.0f;
        S7cdd90_Point3 koriginFromBroadphaseCenter = origin - kbroadphaseCenter;
        float foriginRatio = S7cdd90_Max(S7cdd90_Abs(koriginFromBroadphaseCenter.x / kbroadphaseDiagonal.x),
                                         S7cdd90_Max(S7cdd90_Abs(koriginFromBroadphaseCenter.y / kbroadphaseDiagonal.y),
                                                     S7cdd90_Abs(koriginFromBroadphaseCenter.z / kbroadphaseDiagonal.z)));
        if (foriginRatio > 1.0f)
        {
            FUN_00887da0("COMBAT: Projectile %s is spawning outside of the broadphase.",
                         GetBaseForm()->TESForm_GetFormEditorIDLength() ? GetBaseForm()->GetFullName() : GetBaseForm()->m_kName.c_str());
        }
        else
        {
            S7cdd90_Point3 kto = origin + kray;
            S7cdd90_Point3 ktoFromBroadphaseCenter = kto - kbroadphaseCenter;
            float fhighestRatio = S7cdd90_Max(S7cdd90_Abs(ktoFromBroadphaseCenter.x / kbroadphaseDiagonal.x),
                                              S7cdd90_Max(S7cdd90_Abs(ktoFromBroadphaseCenter.y / kbroadphaseDiagonal.y),
                                                          S7cdd90_Abs(ktoFromBroadphaseCenter.z / kbroadphaseDiagonal.z)));
            if (fhighestRatio > 1.0f)
            {
                if (origin.x + kray.x > kbroadphaseUpperExtent.x)
                    klength.FUN_006b1f50((kbroadphaseUpperExtent.x - origin.x) / kray.x);
                if (origin.y + klength.y > kbroadphaseUpperExtent.y)
                    klength.FUN_006b1f50((kbroadphaseUpperExtent.y - origin.y) / klength.y);
                if (origin.z + klength.z > kbroadphaseUpperExtent.z)
                    klength.FUN_006b1f50((kbroadphaseUpperExtent.z - origin.z) / klength.z);
                if (origin.x + klength.x < kbroadphaseLowerExtent.x)
                    klength.FUN_006b1f50((kbroadphaseLowerExtent.x - origin.x) / klength.x);
                if (origin.y + klength.y < kbroadphaseLowerExtent.y)
                    klength.FUN_006b1f50((kbroadphaseLowerExtent.y - origin.y) / klength.y);
                if (origin.z + klength.z < kbroadphaseLowerExtent.z)
                    klength.FUN_006b1f50((kbroadphaseLowerExtent.z - origin.z) / klength.z);
            }
        }
    }
    pd.m_filterInfo = filter.iFilter;
    pd.FUN_00469050(origin);
    pd.FUN_0068daa0(klength);
    S7cd730_AllRayHitCollector collector;
    pd.pAllCollector = &collector;
    pd.pCloseCollector = 0;
    S7cd730_ParentCell* pCell = DAT_0107a104->pParentCell;
    S7cd730_World* pPlayerWorld = (pCell->uiCellFlags & 1) ? pCell->kHolder.FUN_00410f00() : DAT_01071564;
    bhit = pPlayerWorld->Pick(&pd);
    float fwaterHitRatio = DAT_00db9568;
    bhit |= FUN_007cbc10(&pd, &fwaterHitRatio);
    if (bhit)
        bhit = FUN_007cc540(&pd, this, GetBaseForm(), 0, 1, fwaterHitRatio) != 0;
    if (DAT_0108cf54)
    {
        S7cdd90_ColorA color = pd.bPickFailed ? S7cdd90_ColorA(1.0f, 0.0f, 0.0f, 1.0f) : S7cdd90_ColorA(1.0f, 1.0f, 0.0f, 1.0f);
        S7cdd90_Line* pdebug = FUN_0047a4e0(origin, color, origin + klength, color, true);
        DAT_0107a0d8->FUN_00433df0(pdebug, DAT_0108cf70);
    }
    if (pd.bPickFailed)
        FUN_007c8650();
    }
    return bhit;
}

// @f3 0x007c16d0 (community match, verified in this file)
namespace f3w_7c16d0 {

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3() {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator+(const NiPoint3& pt) const
    {
        return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
    }
    NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3 operator*(float fScalar) const
    {
        return NiPoint3(x * fScalar, y * fScalar, z * fScalar);
    }
    void FUN_00468d00();
};

struct NiMatrix3
{
    float m_pEntry[3][3];

    void MakeXRotation(float fAngle)
    {
        float sn, cs;
        fnv_SinCos(fAngle, sn, cs);
        m_pEntry[0][0] = 1.0f;
        m_pEntry[0][1] = 0.0f;
        m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = 0.0f;
        m_pEntry[1][1] = cs;
        m_pEntry[1][2] = sn;
        m_pEntry[2][0] = 0.0f;
        m_pEntry[2][1] = -sn;
        m_pEntry[2][2] = cs;
    }
    void MakeZRotation(float fAngle)
    {
        float sn, cs;
        fnv_SinCos(fAngle, sn, cs);
        m_pEntry[0][0] = cs;
        m_pEntry[0][1] = sn;
        m_pEntry[0][2] = 0.0f;
        m_pEntry[1][0] = -sn;
        m_pEntry[1][1] = cs;
        m_pEntry[1][2] = 0.0f;
        m_pEntry[2][0] = 0.0f;
        m_pEntry[2][1] = 0.0f;
        m_pEntry[2][2] = 1.0f;
    }
    void GetCol(unsigned int uiCol, NiPoint3& col) const
    {
        col.x = m_pEntry[0][uiCol];
        col.y = m_pEntry[1][uiCol];
        col.z = m_pEntry[2][uiCol];
    }
    NiMatrix3 operator*(const NiMatrix3& mat) const;
};

struct NiColorA
{
    float r;
    float g;
    float b;
    float a;

    NiColorA(float fR, float fG, float fB, float fA)
    {
        r = fR;
        g = fG;
        b = fB;
        a = fA;
    }
};

struct CFilter
{
    unsigned int iFilter;

    CFilter(unsigned int aFilter = 0) : iFilter(aFilter) {}
    void SetLayer(unsigned int uiLayer)
    {
        iFilter = (iFilter & ~0x7f) | (uiLayer & 0x7f);
    }
    unsigned short GetGroup() const
    {
        return (unsigned short)(iFilter >> 16);
    }
    void SetGroup(unsigned int uiGroup)
    {
        iFilter = (iFilter & 0xffff) | (uiGroup << 16);
    }
};

extern unsigned int DAT_00f79e58;
inline unsigned int GetNewSystemGroup()
{
    DAT_00f79e58 = (DAT_00f79e58 + 1) & 0xffff;
    if (!DAT_00f79e58)
        DAT_00f79e58 = 10;
    return DAT_00f79e58;
}

inline hkVector4& NI2HK(hkVector4& out, const NiPoint3& in)
{
    out.x = in.x * 0.1428767293691635;
    out.y = in.y * 0.1428767293691635;
    out.z = in.z * 0.1428767293691635;
    return out;
}

struct bhkAllRayHitCollector
{
    unsigned int data[0xc8];

    bhkAllRayHitCollector();
    ~bhkAllRayHitCollector();
};

struct bhkPickData
{
    hkVector4 m_from;
    hkVector4 m_to;
    bool m_enableShapeCollectionFilter;
    unsigned int m_filterInfo;
    unsigned int unk28[0x1a];
    hkVector4 hkLength;
    void* pCache;
    void* pCloseCollector;
    bhkAllRayHitCollector* pAllCollector;
    bool bPickFailed;

    bhkPickData();
    void SetFilter(CFilter aFilter)
    {
        m_filterInfo = aFilter.iFilter;
    }
    void FUN_00469050(const NiPoint3& arFrom);
    void SetFrom(const NiPoint3& arFrom)
    {
        FUN_00469050(arFrom);
    }
    void SetLength(const NiPoint3& arLength)
    {
        hkVector4 hkv;
        hkLength = NI2HK(hkv, arLength);
    }
    void SetAllCollector(bhkAllRayHitCollector* apCollector)
    {
        pAllCollector = apCollector;
        pCloseCollector = 0;
    }
    void SetPickCache(void* apCache)
    {
        pCache = apCache;
    }
    bool GetPickFailed() const
    {
        return bPickFailed;
    }
};

struct bhkWorld
{
    virtual void w000();
    virtual void w004();
    virtual void w008();
    virtual void w00c();
    virtual void w010();
    virtual void w014();
    virtual void w018();
    virtual void w01c();
    virtual void w020();
    virtual void w024();
    virtual void w028();
    virtual void w02c();
    virtual void w030();
    virtual void w034();
    virtual void w038();
    virtual void w03c();
    virtual void w040();
    virtual void w044();
    virtual void w048();
    virtual void w04c();
    virtual void w050();
    virtual void w054();
    virtual void w058();
    virtual void w05c();
    virtual void w060();
    virtual void w064();
    virtual void w068();
    virtual void w06c();
    virtual void w070();
    virtual void w074();
    virtual void w078();
    virtual void w07c();
    virtual void w080();
    virtual void w084();
    virtual void w088();
    virtual void w08c();
    virtual void w090();
    virtual void w094();
    virtual void w098();
    virtual void w09c();
    virtual void w0a0();
    virtual void w0a4();
    virtual void w0a8();
    virtual void w0ac();
    virtual void w0b0();
    virtual void w0b4();
    virtual void w0b8();
    virtual void w0bc();
    virtual void w0c0();
    virtual void w0c4();
    virtual bool PickObject(bhkPickData& arPickData);
};

struct TESObjectCELL_Holder
{
    bhkWorld* FUN_00410f00();
};

extern bhkWorld* DAT_01071564;

struct TESObjectCELL
{
    char unk00[0x24];
    unsigned int uiCellFlags;
    TESObjectCELL_Holder kHolder;

    bhkWorld* GetbhkWorld()
    {
        return (uiCellFlags & 1) ? kHolder.FUN_00410f00() : DAT_01071564;
    }
};

struct bhkCharacterController
{
    CFilter FUN_0061f4f0();
};

struct Shooter
{
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void s0c0();
    virtual void s0c4();
    virtual void s0c8();
    virtual void s0cc();
    virtual void s0d0();
    virtual void s0d4();
    virtual void s0d8();
    virtual void s0dc();
    virtual void s0e0();
    virtual void s0e4();
    virtual void s0e8();
    virtual void s0ec();
    virtual void s0f0();
    virtual void s0f4();
    virtual void s0f8();
    virtual void s0fc();
    virtual bool IsEnabled();
    CFilter FUN_00766b00();
};

struct PickCache
{
    char unk00[8];
    void* pCache;

    void* Get() const
    {
        return pCache;
    }
};

struct BGSProjectile
{
    char unk00[0x6c];
    float fSpread;

    float GetSpread() const
    {
        return fSpread;
    }
};

struct PlayerCharacter;

struct FlameProjectile
{
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
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* GetFiringPosition();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual float GetAngleZ(int iMode);

    char unk04[0x18];
    BGSProjectile* pBaseObject;
    char unk20[0x1c];
    TESObjectCELL* pParentCell;
    char unk40[0x8c];
    float fRange;
    char unkd0[0x24];
    Shooter* pShooter;
    char unkf8[0x10];
    float fDistanceMoved;
    char unk10c[0x8];
    PickCache* pPickCache;
    char unk118[0x2c];
    float fScale;

    TESObjectCELL* GetParentCell() const
    {
        return pParentCell;
    }
    BGSProjectile* GetBaseObject() const
    {
        return pBaseObject;
    }
    Shooter* GetShooter() const
    {
        return pShooter;
    }
    PickCache* GetPickCache() const
    {
        return pPickCache;
    }
    float GetRange() const
    {
        return fRange;
    }
    float GetDistanceMoved() const
    {
        return fDistanceMoved;
    }
    float GetScale() const
    {
        return fScale;
    }
    bhkCharacterController* FUN_00764ea0();
    float FUN_00765430();
    bool FUN_007c16d0();
};

struct PlayerCharacter
{
    char unk00[0x3c];
    TESObjectCELL* pParentCell;

    TESObjectCELL* GetParentCell() const
    {
        return pParentCell;
    }
};

struct BSRandom
{
    unsigned int FUN_0086c4b0(int iMax);
};
BSRandom* __cdecl FUN_0044a2d0();
extern const double DAT_00dbe7d8;

struct BSDebugLine;
struct DebugLineManager
{
    void FUN_00433df0(BSDebugLine* apLine, float afLifetime);
};

extern PlayerCharacter* DAT_0107a104;
extern DebugLineManager* DAT_0107a0d8;
extern bool DAT_0108cf54;
extern float DAT_0108cf70;
extern float DAT_00db9568;

void __cdecl FUN_007c7990(NiPoint3* apPoints, int aiCount, NiPoint3 akOrigin, float afAngleZ, float afAngleX,
                          float afScale, float afSpread, float afRandom);
int __cdecl FUN_007cc540(bhkPickData* apPickData, FlameProjectile* apProjectile, void* apArg3, int aiArg4, int aiArg5,
                         float afHitFraction);
BSDebugLine* __cdecl FUN_0047a4e0(const NiPoint3* apFrom, const NiColorA* apFromColor, const NiPoint3* apTo,
                                  const NiColorA* apToColor, bool abArg5);

// pdb: FlameProjectile::RunTargetPick | FlameProjectile.obj | fnv360_0822_retail, vtable, medium
bool FlameProjectile::FUN_007c16d0()
{
    if (!GetParentCell() || !GetParentCell()->GetbhkWorld())
        return false;
    bool bresult = false;
    bhkWorld* pw = GetParentCell()->GetbhkWorld();
    bhkPickData pd;
    NiPoint3 origin;
    origin = *GetFiringPosition();
    CFilter filter(0);
    int ipickPoints = 4;
    NiPoint3 pickPoints[4];
    {
        NiPoint3 direction;
        NiMatrix3 rot;
        rot.MakeZRotation(GetAngleZ(0));
        float sn, cs;
        fnv_SinCos(FUN_00765430(), sn, cs);
        {
            NiMatrix3 rot2 = {1.0f, 0.0f, 0.0f, 0.0f, cs, sn, 0.0f, -sn, cs};
            rot = rot * rot2;
        }
        rot.GetCol(1, direction);
        direction.FUN_00468d00();
        if (FUN_00764ea0())
        {
            filter = FUN_00764ea0()->FUN_0061f4f0();
        }
        else
        {
            filter.SetLayer(6);
            if (GetShooter() && GetShooter()->IsEnabled())
            {
                filter.SetGroup(GetShooter()->FUN_00766b00().GetGroup());
            }
            else
            {
                filter.SetGroup(GetNewSystemGroup());
            }
        }
        if (GetPickCache() && GetPickCache()->Get())
            pd.SetPickCache(GetPickCache()->Get());
        BSRandom* prng = FUN_0044a2d0();
        unsigned int value = prng->FUN_0086c4b0(-1);
        FUN_007c7990(pickPoints, 3, origin, GetAngleZ(0), FUN_00765430(), GetScale(), GetBaseObject()->GetSpread(),
                     (float)((float)value * DAT_00dbe7d8));
        pickPoints[3] = origin + direction * (GetRange() - GetDistanceMoved());
    }
    pd.SetFilter(filter);
    pd.SetFrom(origin);
    for (int i = 0; i < ipickPoints; ++i)
    {
        pd.SetLength(pickPoints[i] - origin);
        bhkAllRayHitCollector collector;
        pd.SetAllCollector(&collector);
        bool bhit = DAT_0107a104->GetParentCell()->GetbhkWorld()->PickObject(pd);
        if (bhit)
            bhit = FUN_007cc540(&pd, this, 0, 0, 0, DAT_00db9568) != 0;
        if (bhit)
            bresult = true;
        if (DAT_0108cf54)
        {
            NiColorA color = pd.GetPickFailed() ? NiColorA(1.0f, 0.0f, 0.0f, 1.0f) : NiColorA(1.0f, 1.0f, 0.0f, 1.0f);
            BSDebugLine* pdebug = FUN_0047a4e0(&origin, &color, &pickPoints[i], &color, true);
            DAT_0107a0d8->FUN_00433df0(pdebug, DAT_0108cf70);
        }
    }
    return bresult;
}

}
