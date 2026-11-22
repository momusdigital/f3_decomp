#include "f3_common.h"
// src/havok/physics/dynamics/constraint/hkpconstraintinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/hkpconstraintinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintInstance.h"

void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(void* a, void* b, int c);
// hkpWorldObject: m_world at +0x08 (New Vegas Xbox 360 PDB).
struct ConstraintEntityF3
{
    int unk00, unk04;
    void* m_world;
};
// hkpConstraintInstance
struct FUN_00cf3090_class
{
    void* m0;
    void* m1;
    void* m_owner;  // +0x08
    void* m3;
    void FUN_00cf3090(ConstraintEntityF3* entity);
};
// When the constraint is owned, removes it at once from the removed entity's world.
// @fnv 0x00cf3090
void FUN_00cf3090_class::FUN_00cf3090(ConstraintEntityF3* entity)
{
    if (m_owner)
        hkpWorldOperationUtil_removeConstraintImmediately(entity->m_world, this, 1);
}

struct DDCC60World
{
    void removeReference(void);
};
struct RefObj
{
    void RetainReference(void);
};

namespace fnv_00cf3040 {
struct DDCC60World
{
    void removeReference();
};
// hkpWorld: m_fixedRigidBody at +0x24 (New Vegas Xbox 360 PDB).
struct DDCC60WorldF3
{
    char unk00[0x24];
    DDCC60World* m_fixedRigidBody;
};
// hkpConstraintInstance
struct FUN_00cf3040_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
        void* m4;
    DDCC60World* m_entities[2];  // +0x14
    void* m7;
    void RemoveReferenceFromSlots(DDCC60WorldF3* world);
};
// Drops the references to the world's fixed rigid body from the constraint's two entity slots.
// @fnv 0x00cf3040
// pdb: hkpConstraintInstance::setFixedRigidBodyPointersToZero | hkpConstraintInstance.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: world
void FUN_00cf3040_class::RemoveReferenceFromSlots(DDCC60WorldF3* world)
{
    for (int i = 0; i < 2; ++i)
    {
        DDCC60World* p = m_entities[i];
        if (p == world->m_fixedRigidBody)
        {
            p->removeReference();
            m_entities[i] = 0;
        }
    }
}
}  // namespace fnv_00cf3040

namespace fnv_00cf3e60 {
struct RefObj
{
    void FUN_00c90510();
};

// hkpWorld: m_fixedRigidBody at +0x24; hkpEntity: m_world at +0x08 (New Vegas Xbox 360 PDB).
struct CF3E60World
{
    char unk00[0x24];
    RefObj* m_fixedRigidBody;
};
struct CF3E60Entity
{
    int unk00, unk04;
    CF3E60World* m_world;
};
struct FUN_00cf3e60_class : public hkReferencedObject
{
    void* m_pOwnerObject;
    unsigned char m_ucUnknownByte[8];
    void* m_kActorEntries[8];

    void FUN_00cf3e60();
};

// @fnv 0x00cf3e60
// pdb: hkpConstraintInstance::pointNullsToFixedRigidBody | hkpConstraintInstance.obj | fnv360_0822_retail, call_gap, medium
void FUN_00cf3e60_class::FUN_00cf3e60()
{
    for (int i = 0; i < 2; ++i)
    {
        if (m_kActorEntries[i] == 0)
        {
            void* other = reinterpret_cast<void*>(reinterpret_cast<unsigned int>(m_kActorEntries[1]) ^
                                                  reinterpret_cast<unsigned int>(m_kActorEntries[0]) ^
                                                  reinterpret_cast<unsigned int>(m_kActorEntries[i]));

            if (other != 0)
            {
                                CF3E60World* world = static_cast<CF3E60Entity*>(other)->m_world;
                if (world != 0)
                {
                    RefObj* fixedBody = world->m_fixedRigidBody;
                    m_kActorEntries[i] = fixedBody;
                    fixedBody->FUN_00c90510();
                }
            }
        }
    }
}
}  // namespace fnv_00cf3e60

// @fnv 0x00cf2f90
void __stdcall FUN_00cf2f90(int)
{}

// @fnv 0x00cf2fa0
void __stdcall FUN_00cf2fa0(int)
{}

struct hkBoolCF2F
{
    char m_cBooleanValue;
    hkBoolCF2F(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

namespace fnv_00cf2fe0 {
struct hkBoolCF2F
{
    char m_cBooleanValue;
    hkBoolCF2F(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

int __cdecl hkpWorldConstraintUtil_findModifier(const void* pvObject, int iType);

}  // namespace fnv_00cf2fe0

class hkObjCF30
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    void** m_items;
    unsigned short m_numItems;

    int indexOf(void* pv) const
    {
        for (int i = 0; i < m_numItems; i++)
        {
            if (m_items[i] == pv)
                return i;
        }
        return -1;
    }

    void FUN_00cf30b0(void* pv);
};

struct hkAllocatorCF3F
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterCF3F
{
    void* m_apvUnk00[4];
    hkAllocatorCF3F* m_pkHeap;
    hkAllocatorCF3F& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterCF3F* __cdecl FUN_00c85750() throw();

struct hkBoolCF3F
{
    char m_bValue;
    hkBoolCF3F() throw()
    {}
};

class hkpConstraintData : public hkReferencedObject
{
  public:
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class FUN_00cf3ea0 : public hkpConstraintInstance
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        void* p = FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
        ((unsigned short*)p)[2] = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf3ea0(hkpEntity* pkEntityA, hkpEntity* pkEntityB, hkpConstraintData* pkData,
                 ConstraintPriority ePriority) throw();
};

class hkpConstraintInstanceCF3F : public hkpConstraintInstance
{
  public:
    hkBoolCF3F FUN_00cf2fb0() const throw();
    hkpConstraintData* getData() const
    {
        return m_data;
    }
    ConstraintPriority getPriority() const
    {
        return (ConstraintPriority)m_priority;
    }
    hkpConstraintInstance* FUN_00cf3fa0(hkpEntity* pkEntityA, hkpEntity* pkEntityB, int eMode) const throw();
};

namespace fnv_00cf40b0 {
extern void* DAT_010cc040;
extern void* DAT_0102e388;

void __cdecl FUN_00d85ef0(void*) throw();
void __fastcall FUN_00c905b0(void* self) throw();
void* __cdecl FUN_00c85750() throw();

struct MemAllocator
{
    virtual void dummy0() throw();
    virtual void dummy1() throw();
    virtual void deallocate(void* p, int size) throw();
};

struct ThreadMemory
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    MemAllocator* m_pMemoryAllocator;
    inline void deallocate(void* p, int size) throw()
    {
        m_pMemoryAllocator->deallocate(p, size);
    }
};

static inline void hkDeallocate(void* p, int size) throw()
{
    ((ThreadMemory*)FUN_00c85750())->deallocate(p, size);
}

struct FUN_00cb0c00_class
{
    void FUN_00cb0c00() throw();
};

struct ModifierAtom
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_usModifierAtomSize;
    unsigned short unk12;
    ModifierAtom* m_pChildAtom;
};

struct FUN_00cf40b0_class : public hkpConstraintInstance
{
    void FUN_00cf40b0();
};

// @fnv 0x00cf40b0
void FUN_00cf40b0_class::FUN_00cf40b0()
{
    *(void**)this = &DAT_010cc040;
    FUN_00d85ef0(this);
    if (m_kActorEntries[0])
        FUN_00c905b0(m_kActorEntries[0]);
    if (m_kActorEntries[1])
        FUN_00c905b0(m_kActorEntries[1]);
    ModifierAtom* mod = (ModifierAtom*)m_pConstraintModifier;
    if (mod != 0 && mod->m_type >= 0x17)
    {
        do
        {
            ModifierAtom* cur = mod;
            mod = cur->m_pChildAtom;
            hkDeallocate(cur, cur->m_usModifierAtomSize);
        } while (mod->m_type >= 0x17);
    }
    if (m_data)
        FUN_00c905b0(m_data);
    ((FUN_00cb0c00_class*)&m_name)->FUN_00cb0c00();
    if ((m_kListeners.m_iCapacityState & 0x8000) == 0)
    {
        int capacity = m_kListeners.m_iCapacityState & 0x3fff;
        hkDeallocate(m_kListeners.m_data, capacity * 4);
    }
    *(void**)this = &DAT_0102e388;
}
}  // namespace fnv_00cf40b0

namespace fnv_00cf4160 {
class hkMemoryAllocatorCF41
{
  public:
    virtual ~hkMemoryAllocatorCF41() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF41
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF41* m_pStreamAllocator;
    hkMemoryAllocatorCF41& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF41& __cdecl FUN_00c85750();

class FUN_00cf40b0
{
  public:
    virtual ~FUN_00cf40b0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00cf40b0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cf40b0* FUN_00cf4160(unsigned int uiFlags) throw();
};

}  // namespace fnv_00cf4160

struct hkpModifierConstraintAtom
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpModifierConstraintAtom* m_pChildAtom;
};

// Walks the modifier atom chain of a constraint instance and returns the first atom whose m_type equals type, or null if none matches.
// @fnv 0x00d277c0
// pdb: hkpWorldConstraintUtil::findModifier | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: instance, type
// pdb: hkpWorldConstraintUtil::findModifier | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_seq, high (was: FindModifierConstraintAtom)
hkpModifierConstraintAtom* __cdecl hkpWorldConstraintUtil_findModifier(hkpConstraintInstance* aConstraintInstance,
                                                              unsigned int type)
{
    hkpModifierConstraintAtom* atom = aConstraintInstance->m_pConstraintModifier;
    if (!atom)
        return 0;

    while (atom->m_type != type)
    {
        if (atom->m_pChildAtom->m_type < 0x17)
            return 0;
        atom = atom->m_pChildAtom;
    }
    return atom;
}

extern "C" void __cdecl hkSmallArrayUtil__reserveMore(void* apvArray, int iSizeElem);
extern "C" void _ReadWriteBarrier();

struct S00cf3df0_Arr
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_cap;
    __forceinline void put(void* a)
    {
        unsigned short n = m_iElementCount;

        int i = 0;
        if (i < n)
        {
            void** d = m_data;
            void** p = d;
            do
            {
                if (*p == 0)
                {
                    if (i >= 0)
                    {
                        d[i] = a;
                        return;
                    }
                    break;
                }
                _ReadWriteBarrier();
                i++;
                p++;
            } while (i < m_iElementCount);
        }
        if (n == (m_cap & 0x3fff))
            hkSmallArrayUtil__reserveMore(this, 4);
        m_data[m_iElementCount++] = a;
    }
};

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
struct Matrix4f;
struct CVector
{
    __m128 m;
    void FUN_00c7f640(Matrix4f*, CVector*);
    void FUN_00c7f700(Matrix4f*, CVector*);
};
struct __declspec(align(16)) Matrix4f
{
    CVector c0, c1, c2, c3;
};
struct ConstraintReference;
struct ConstraintReferencedBase
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual unsigned getType() const;
    unsigned unk04;
};
struct ConstraintReference : ConstraintReferencedBase
{
    unsigned unk08, unk0c, unk10, unk14;
    ConstraintReference* child18;
    unsigned unk1c;
    Matrix4f a, b, c, d;
    unsigned unk120;
    ConstraintReference* FUN_00cdf6c0();
    void FUN_00d541b0(CVector*, CVector*);
    void FUN_00cbe400(CVector*, CVector*, CVector*, CVector*);
    void FUN_00cb8da0(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void SetBasis(CVector*, CVector*, CVector*);
    void FUN_00d4fba0(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void FUN_00cded30(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void FUN_00d4e960(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
};
struct CBoolean
{
    char b;
    CBoolean() throw()
    {}
    operator bool() const
    {
        return b != 0;
    }
};
static __forceinline CVector getVector(const CVector& s)
{
    return s;
}

extern "C"
{
}

void* __cdecl hkpWorldConstraintUtil_findModifier(void* self, int size);

extern char DAT_010cc040;

// @f3 0x004fed10 (community match, verified in this file)
struct MemoryManager
{
    void FUN_0086ba60(void* pointer);
};
extern MemoryManager DAT_01090a78;

struct BSString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;

    void Set(const char* text, unsigned int length)
    {
        if (pString)
        {
            DAT_01090a78.FUN_0086ba60(pString);
        }
        pString = 0;
        sMaxLen = 0;
        sLen = 0;
    }
};

struct WaterShaderSettings
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    void WaterShaderData_Initialize();
};

struct TESWaterForm
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    unsigned char m_ucOpacity;
    unsigned char cFlags;
    unsigned char field72;
    unsigned char field73;
    BSString m_kMaterialId;
    void* m_pWaterSound;
    int field80;
    WaterShaderSettings m_kSettings;
    TESWaterForm* m_apWaterForms[3];

    WaterShaderSettings* GetSettings() { return &m_kSettings; }
    void FUN_004fed10();
};

// pdb: TESWaterForm::InitializeData | TESWaterForm.obj | fnv360_0822_retail, vtable, medium
void TESWaterForm::FUN_004fed10()
{
    m_ucOpacity = 0x4B;
    cFlags = 0;
    m_pWaterSound = 0;
    m_kMaterialId.Set(0, 0);
    GetSettings()->WaterShaderData_Initialize();

    for (int i = 0; i < 3; ++i)
        m_apWaterForms[i] = 0;
}
