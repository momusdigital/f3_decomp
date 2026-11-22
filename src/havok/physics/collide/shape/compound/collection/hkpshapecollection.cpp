#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/hkpshapecollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpShapeCollection.h"

class hkpShapeCollection_L
{
  public:
    virtual ~hkpShapeCollection_L();
    virtual int FUN_00d213d0();
};

// @fnv 0x00d213d0
// pdb: hkpShapeCollection::getContainer | hkpShapeCollection.obj | fnv360_0822_retail, objrun_open, low
int hkpShapeCollection_L::FUN_00d213d0()
{
    if (this != 0)
    {
        return reinterpret_cast<int>(this) + 0x10;
    }
    return 0;
}

// @fnv 0x00d213f0
// pdb: hkpMoppShapeMediator::setSplittingPlaneDirections | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpMoppShapeMediator_setSplittingPlaneDirections(int, int)
{}

// @fnv 0x00d21400
// pdb: hkpExtendedMeshShape::assertShapesSubpartValidity | hkpExtendedMeshShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: part
void __stdcall FUN_00d21400(int a1)
{}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet()
    {}
    hkBoolRet(char b) : m_cBooleanValue(b)
    {}
};

typedef unsigned int hkpShapeKey;

struct StringCursor
{
    char* m_kRayStart;
    char* m_pTileTemplate;
    char* m_pRayCursor;
    char* m_kRayEnd;
};

class ShapeRayCastQuery;
class ShapeRayCastOutput;
class hkpRayShapeCollectionFilter;

class hkpShape_V : public hkpShape
{
  public:
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual hkBoolRet RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual hkpShapeKey getFirstShapeKey() const;
    virtual hkpShapeKey getNextShapeKey(hkpShapeKey key) const;
    virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key) const;
    virtual const hkpShape_V* GetShapeForKey(hkpShapeKey key, void* buffer) const;
};

class FUN_00d21450_Class : public hkpShape
{
  public:
    hkpShapeContainer m_container;
    hkBool m_bDisableWelding;
    hkUint8 m_eCollectionType;
    char unk16;
    char unk17;

    hkBoolRet hkpShapeCollection_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

struct ShapeRayCastQuery
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
    const hkpRayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};

struct ShapeRayCastOutput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpShapeKey m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

class hkpRayShapeCollectionFilter
{
  public:
    virtual hkBoolRet IsCollisionEnabled(const ShapeRayCastQuery& aInput, const FUN_00d21450_Class& aCollection,
                                         const hkpShapeContainer& bContainer, hkpShapeKey aKey) const = 0;
};

// Calls RayCast on each child in m_container (filtered if a filter is given), stores the last hit shape key in output.m_uiShapeKeys, returns true if any hit.
// @fnv 0x00d21450
// pdb: hkpShapeCollection::castRayImpl | hkpShapeCollection.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
hkBoolRet FUN_00d21450_Class::hkpShapeCollection_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    HK_TIMER_BEGIN("rcShpCollect", HK_NULL);
    output.m_uiShapeKeyIndex++;
    const hkpShapeContainer* container = &m_container;
    hkpShapeKey uiHitKey = 0xffffffff;
    __declspec(align(16)) hkUlong buffer[512 / sizeof(hkUlong)];
    hkBoolRet hitResult;
    if (input.m_pRayShapeCollectionFilter == 0)
    {
        hkpShapeKey key = container->getFirstShapeKey();
        while (key != 0xffffffff)
        {
            const hkpShape_V* child = container->GetShapeForKey(key, buffer);
            hitResult.hkBoolRet::hkBoolRet(child->RayCast(input, output));
            if (hitResult.m_cBooleanValue)
                uiHitKey = key;
            key = container->getNextShapeKey(key);
        }
    }
    else
    {
        hkpShapeKey key = container->getFirstShapeKey();
        while (key != 0xffffffff)
        {
            if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *this, *container, key).m_cBooleanValue)
            {
                const hkpShape_V* child = container->GetShapeForKey(key, buffer);
                hitResult.hkBoolRet::hkBoolRet(child->RayCast(input, output));
                if (hitResult.m_cBooleanValue)
                    uiHitKey = key;
            }
            key = container->getNextShapeKey(key);
        }
    }

    output.m_uiShapeKeyIndex--;
    if (uiHitKey != 0xffffffff)
    {
        output.m_uiShapeKeys[output.m_uiShapeKeyIndex] = uiHitKey;
    }
    HK_TIMER_END();
    return hkBoolRet(uiHitKey != 0xffffffff);
}

namespace fnv_00d217d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwIndex);

extern "C" unsigned int DAT_0126835c;
extern "C" char str_010c41f8[];

class Arg0_L;
class Arg1_L;
class Arg2_L;
class ShapeBuf_L;
struct Ctx_L;
class Owner_L;

class Shape_L
{
  public:
    virtual ~Shape_L();
    virtual int s01();
    virtual int s02();
    virtual int s03();
    virtual int s04();
    virtual int s05();
    virtual int s06();
    virtual int s07();
    virtual int s08();
    virtual void process_L(Arg0_L* arg0, Ctx_L* ctx, Arg2_L* arg2);
};

class Coll_L2 : public hkpShapeCollection_L
{
  public:
    virtual int getFirstKey_L();
    virtual int getNextKey_L(int key);
    virtual int s04();
    virtual Shape_L* getChildShape_L(int key, ShapeBuf_L& buffer);
};

class Filter_L
{
  public:
    virtual char* isEnabled_L(char* out, Arg0_L* arg0, Owner_L* self, Coll_L2* coll, int key);
};

class Arg0_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    Filter_L* m_iFilter;
};

class Arg1_L
{
  public:
    void* unk00;
    void* unk04;
    int unk08;
};
class Arg2_L
{
  public:
    int dummy;
};

struct Ctx_L
{
    Shape_L* shape;
    int key;
    int unk08;
    Arg1_L* arg1;
};

struct __declspec(align(16)) ShapeBuf_L
{
    hkVector4 v00, v01, v02, v03, v04, v05, v06, v07;
    hkVector4 v08, v09, v10, v11, v12, v13, v14, v15;
    hkVector4 v16, v17, v18, v19, v20, v21, v22, v23;
    hkVector4 v24, v25, v26, v27, v28, v29, v30, v31;
};

class Owner_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Coll_L2 m_coll;
    void FUN_00d217d0(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2);
};

}  // namespace fnv_00d217d0

extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern float DAT_0104e148;
extern const char str_010ce228[];
extern const char str_010c41f8[];

struct S00d216e0_Rec
{
    const char* name;
    unsigned int tick;
    unsigned int unk08;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        tick = uiTicks;
    }
};

struct S00d216e0_Ctx
{
    int unk00;
    S00d216e0_Rec* cur;
    int unk08;
    S00d216e0_Rec* end;
    static S00d216e0_Ctx& GetMonitorStream()
    {
        return *(S00d216e0_Ctx*)TlsGetValue(DAT_0126835c);
    }
};

__forceinline void S00d216e0_timer(const char* name)
{
    S00d216e0_Ctx& kCtx = S00d216e0_Ctx::GetMonitorStream();
    if (kCtx.cur < kCtx.end)
    {
        S00d216e0_Rec* h = kCtx.cur;
        h->name = name;
        h->setTime();
        kCtx.cur = h + 1;
    }
}

class ShapeIterator
{
  public:
    virtual ~ShapeIterator();
    virtual void Unk04();
    virtual int First();
    virtual int Next(int idx);
    virtual void Unk10();
    virtual class hkShape_StandIn* GetShape(int idx, float* outBuf);
};

class hkShape_StandIn : public hkpShape
{
  public:
    virtual ~hkShape_StandIn();
    virtual void Unk04();
    virtual void Unk08();
    virtual float GetMaxProjection(int arg);
};

class hkPackedNiTriStripsShape_StandIn : public hkpShapeCollection
{
  public:
    virtual ~hkPackedNiTriStripsShape_StandIn();
    virtual void Unk04();
    virtual int First();
    virtual float hkpShapeCollection_getMaximumProjection(int arg);
    virtual void Unk10();
    virtual void Unk14();
};

// Iterates child shapes via ShapeIterator, calls GetMaxProjection(arg) on each and returns the largest value, between two timer records.
// @fnv 0x00d216e0
// pdb: hkpShapeCollection::getMaximumProjection | hkpShapeCollection.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
float hkPackedNiTriStripsShape_StandIn::hkpShapeCollection_getMaximumProjection(int arg)
{
    volatile float maxProj;
    __declspec(align(16)) float buf[125];

    S00d216e0_timer(str_010ce228);

    ShapeIterator* iter = reinterpret_cast<ShapeIterator*>(reinterpret_cast<char*>(this) + 0x10);

    maxProj = DAT_0104e148;
    int idx = iter->First();

    while (idx != -1)
    {
        hkShape_StandIn* shape = iter->GetShape(idx, buf);
        float currentProj = shape->GetMaxProjection(arg);

        if (!(maxProj > currentProj))
        {
            maxProj = currentProj;
        }

        idx = iter->Next(idx);
    }

    S00d216e0_timer(str_010c41f8);

    return maxProj;
}

// sub ecx,0x10; jmp Destroy == MSVC adjustor thunk: Derived overrides a virtual that both
// bases declare; the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x10.
struct PrimaryBase
{
    virtual void FUN_00cf57d0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00cf57d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf57d0
    virtual void FUN_00cf57d0();
};

Derived::Derived()
{}

class hkpShape_ctor : public hkpShape
{
  public:
    hkpShape_ctor(int type)
    {
        m_sReferenceCount = 1;
        m_ulUserData = 0;
        m_type = type;
    }
};

class ShapeContainerLite
{
  public:
    virtual ~ShapeContainerLite();
    virtual int FUN_00d213d0();
    ShapeContainerLite()
    {}
};

struct WeldingAndType
{
    char m_bDisableWelding;
    char m_eCollectionType;
    __forceinline WeldingAndType(char type)
    {
        m_bDisableWelding = 0;
        m_eCollectionType = type;
    }
};
