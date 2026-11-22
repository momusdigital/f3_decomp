#include "f3_common.h"
// src/havok/physics/collide/filter/group/hkpgroupfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/group/hkpgroupfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGroupFilter.h"

struct FUN_00e48970_struct : public hkpGroupFilter
{
    void hkpGroupFilter_disableCollisionsUsingBitfield(unsigned int, unsigned int);
};

// @f3 0x00a76990 (community match, verified in this file)
// pdb: hkpGroupFilter::disableCollisionsUsingBitfield | hkpGroupFilter.obj | fnv360_0822_retail, objrun, high
// pdb params: layerBitsA, layerBitsB
// pdb: hkpGroupFilter::disableCollisionsUsingBitfield | hkpGroupFilter.obj | fnv360_0822_retail, objrun, high (was: ClearMaskedBits)
void FUN_00e48970_struct::hkpGroupFilter_disableCollisionsUsingBitfield(unsigned int auiMaskA, unsigned int auiMaskB)
{
    int i = 0;
    unsigned int* mask = m_uiCollisionGroupMasks;

    for (; i < 32; ++i)
    {
        unsigned int bit = 1u << i;
        if (auiMaskA & bit)
            *mask &= ~auiMaskB;

        if (auiMaskB & bit)
            *mask &= ~auiMaskA;

        ++mask;
    }
}


struct hkBoolRet
{
    char b;
    hkBoolRet(bool v) : b(v)
    {}
};

class GroupFilter : public hkpGroupFilter
{
  public:
    hkBoolRet ShouldCollide(unsigned int infoA, unsigned int infoB);
};

// Checks whether two collision filter infos may collide, using group/subgroup masks or the group filter table.
// @fnv 0x00e48830
// pdb: hkpGroupFilter::isCollisionEnabled | hkpGroupFilter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: infoA, infoB
hkBoolRet GroupFilter::ShouldCollide(unsigned int infoA, unsigned int infoB)
{
    if (((infoA ^ infoB) & 0xffff0000) == 0 && (infoA & 0xffff0000) != 0)
    {
        if ((((infoB >> 5) ^ infoA) & 0x3e0) == 0)
            return false;

        if ((((infoA >> 5) ^ infoB) & 0x3e0) == 0)
            return false;

        return true;
    }

    return (m_uiCollisionGroupMasks[infoA & 0x1f] & (1 << (infoB & 0x1f))) != 0;
}

class hkpGroupFilterE489
{
  public:
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
    unsigned int m_uiCollisionGroupMasks[32];

    void DisableCollisionPair(int iLayerA, int iLayerB);
};

// Clears the collision bit for iLayerB in row iLayerA and the bit for iLayerA in row iLayerB of the layer mask table.
// @fnv 0x00e48940
// pdb: hkpGroupFilter::disableCollisionsBetween | hkpGroupFilter.obj | fnv360_0822_retail, objrun, medium
// pdb params: layerA, layerB
void hkpGroupFilterE489::DisableCollisionPair(int iLayerA, int iLayerB)
{
    m_uiCollisionGroupMasks[iLayerA] &= ~(1 << iLayerB);
    m_uiCollisionGroupMasks[iLayerB] &= ~(1 << iLayerA);
}

struct hkBoolE48B
{
    char m_cBooleanValue;
    hkBoolE48B(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef __declspec(align(16)) unsigned int hkpShapeBufferE48B[128];

class hkpShapeE48B : public hkReferencedObject
{
  public:
    hkUlong m_ulUserData;
    int m_type;
};

struct hkpCollidableE48B;

struct hkpCdBodyE48B
{
    const hkpShapeE48B* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyE48B* m_parent;

    const hkpShapeE48B* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }
    const hkpCdBodyE48B* getParent() const
    {
        return m_parent;
    }
    __forceinline const hkpCollidableE48B* getRootCollidable() const
    {
        const hkpCdBodyE48B* pkBody = this;
        while (pkBody->m_parent)
            pkBody = pkBody->m_parent;
        return (const hkpCollidableE48B*)pkBody;
    }
};

struct hkpCollidableE48B : public hkpCdBodyE48B
{
    hkInt8 m_iOwnerOffset;
    hkInt8 m_uiForceCollideOntoPpu;
    hkInt16 m_uiShapeSizeOnSpu;
    hkUint32 m_broadPhaseId;
    hkInt8 m_cBroadPhaseType;
    hkInt8 m_broadPhaseOwnerOffset;
    hkUint16 m_ucObjectQualityType;
    hkUint32 m_uiCollisionFilterData;

    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

struct hkpCollisionDispatcherE48B
{
    int m_unk000, m_unk004, m_unk008, m_unk00c, m_unk010, m_unk014, m_unk018, m_unk01c;
    int m_unk020, m_unk024, m_unk028, m_unk02c, m_unk030, m_unk034, m_unk038, m_unk03c;
    int m_unk040, m_unk044, m_unk048, m_unk04c, m_unk050, m_unk054, m_unk058, m_unk05c;
    int m_unk060, m_unk064, m_unk068, m_unk06c, m_unk070, m_unk074, m_unk078, m_unk07c;
    int m_unk080, m_unk084, m_unk088, m_unk08c, m_unk090, m_unk094, m_unk098, m_unk09c;
    int m_unk0a0, m_unk0a4, m_unk0a8, m_unk0ac, m_unk0b0, m_unk0b4, m_unk0b8, m_unk0bc;
    int m_unk0c0, m_unk0c4, m_unk0c8, m_unk0cc, m_unk0d0, m_unk0d4, m_unk0d8, m_unk0dc;
    int m_unk0e0, m_unk0e4, m_unk0e8, m_unk0ec, m_unk0f0, m_unk0f4, m_unk0f8, m_unk0fc;
    int m_unk100, m_unk104, m_unk108, m_unk10c;
    hkUint32 m_auiAlternateTypeFlags[32];

    hkUint32 hasAlternateType(int iType, int iAlternate) const
    {
        return m_auiAlternateTypeFlags[iType] & (1 << iAlternate);
    }
};

class hkBoolE48
{
  public:
    hkBoolE48()
    {}
    hkBoolE48(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
class hkpShapeContainerE48
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
};
class hkpCdBodyE48
{
  public:
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyE48* m_parent;
    const class hkpCollidableE48* getRootCollidable() const
    {
        const hkpCdBodyE48* body = this;
        while (body->m_parent)
            body = body->m_parent;
        return reinterpret_cast<const hkpCollidableE48*>(body);
    }
};
class hkpCollidableE48 : public hkpCdBodyE48
{
  public:
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiCollisionFilterData;
    unsigned int GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};
class hkpCollisionInputE48;
class hkReferencedObjectE48
{
  public:
    virtual ~hkReferencedObjectE48();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpCollidableCollidableFilterE48
{
  public:
    virtual ~hkpCollidableCollidableFilterE48();
};
class hkpShapeCollectionFilterE48
{
  public:
    virtual hkBoolE48 FUN_00e48ae0(const hkpCollisionInputE48& input, const hkpCdBodyE48& a, const hkpCdBodyE48& b,
                                   const hkpShapeContainerE48& containerShapeA,
                                   const hkpShapeContainerE48& containerShapeB, unsigned int keyA,
                                   unsigned int keyB) const = 0;
};
class hkpGroupFilterE48 : public hkReferencedObjectE48,
                          public hkpCollidableCollidableFilterE48,
                          public hkpShapeCollectionFilterE48
{
  public:
    enum
    {
        USE_COLLIDABLE_FILTER_INFO = 0xffffffff
    };
    hkBoolE48 ShouldCollide(unsigned int infoA, unsigned int infoB) const;
    virtual hkBoolE48 FUN_00e48ae0(const hkpCollisionInputE48& input, const hkpCdBodyE48& a, const hkpCdBodyE48& b,
                                   const hkpShapeContainerE48& containerShapeA,
                                   const hkpShapeContainerE48& containerShapeB, unsigned int keyA,
                                   unsigned int keyB) const;
};

class GFilterE488 : public hkpGroupFilter
{
  public:
    void hkpGroupFilter_enableCollisionsUsingBitfield(hkUint32 infoA, hkUint32 infoB);
};

// For each of 32 collision groups, if infoA has the bit set, OR infoB into the group mask, and if infoB has the bit set, OR infoA into it.
// @f3 0x00a768f0 (community match, verified in this file)
// pdb: hkpGroupFilter::enableCollisionsUsingBitfield | hkpGroupFilter.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void GFilterE488::hkpGroupFilter_enableCollisionsUsingBitfield(hkUint32 infoA, hkUint32 infoB) {
    for (int i = 0; i < 32; ++i) {
        hkUint32 mask = 1U << i;
        if (infoA & mask) m_uiCollisionGroupMasks[i] |= infoB;
        if (infoB & mask) m_uiCollisionGroupMasks[i] |= infoA;
    }
}


class S00e489b0_A
{
  public:
    S00e489b0_A();  // FUN_00cbfba0
    virtual void vfA();
    int unk04;
};

class __declspec(novtable) S00e489b0_B
{
  public:
    virtual void vfB();
};
class __declspec(novtable) S00e489b0_C
{
  public:
    virtual void vfC();
};
class __declspec(novtable) S00e489b0_D
{
  public:
    virtual void vfD();
};
class __declspec(novtable) S00e489b0_E
{
  public:
    virtual void vfE();
    int unk18;
    int unk1C;
};

class FUN_00e489b0 : public S00e489b0_A, public S00e489b0_B, public S00e489b0_C, public S00e489b0_D, public S00e489b0_E
{
  public:
    FUN_00e489b0();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE();

    int m_iMode;
    int unk24;
    int unk28;
    int unk2C;
    int m_iArrayLength;
    int m_aiSlots[32];
};

// @fnv 0x00e489b0
// pdb: hkpGroupFilter::hkpGroupFilter | hkpGroupFilter.obj | fnv360_0822_retail, objrun, medium
FUN_00e489b0::FUN_00e489b0()
{
    m_iMode = 2;
    for (int i = 0; i < 32; i++)
        m_aiSlots[i] = -1;
    m_iArrayLength = 0;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void FUN_00e00c00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00e00c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c00
    virtual void FUN_00e00c00();
};

Derived::Derived()
{}

namespace fnv_00e00c10 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x14).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// gets a thunk that moves `this` back by the size of the first base (0x14) and tail-jumps to
// the derived implementation. Only the constructor is defined, so the vtables (and the thunk)
// get emitted.
struct PrimaryBase
{
    virtual void FUN_00e00c10();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00e00c10();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c10
    virtual void FUN_00e00c10();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c10

namespace fnv_00e00c20 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00e00c20();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00e00c20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c20
    virtual void FUN_00e00c20();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c20
