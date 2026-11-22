#include "f3_common.h"
// src/havok/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstrainedSystemFilter.h"

struct hkBoolE46B
{
    char m_cBooleanValue;
    hkBoolE46B(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class FUN_00c9c3c0_Class;

class hkpCollidableE46B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11[7];
    char m_cBroadPhaseType;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

inline FUN_00c9c3c0_Class* hkGetRigidBodyE46B(const hkpCollidableE46B* pkCollidable)
{
    if (pkCollidable->m_cBroadPhaseType == 1)
        return static_cast<FUN_00c9c3c0_Class*>(pkCollidable->getOwner());
    return 0;
}

class hkpConstraintDataE46B
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void V1C() throw();
    virtual int getType() const throw();
};

struct hkpConstraintInstanceE46B
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintDataE46B* m_data;
    int unk10;
    FUN_00c9c3c0_Class* m_pEntityA;
    FUN_00c9c3c0_Class* m_pEntityB;
};

class FUN_00c9c3c0_Class
{
  public:
    int FUN_00c9c380() throw();
    int GetEntryAt(int i) throw();
};

class hkpCollidableCollidableFilterE46B
{
  public:
    virtual void V00() throw();
    virtual hkBoolE46B IsCollisionEnabled(const hkpCollidableE46B& a, const hkpCollidableE46B& b) const throw();
};

class hkpCollisionFilterE46B
{
  public:
    int unk00;
    int unk04;
    hkpCollidableCollidableFilterE46B m_collidableFilter;
};

class hkpConstraintCollisionFilterE46B
{
  public:
    char unk00[0x2c];
    hkpCollisionFilterE46B* m_pChildFilter;

    hkBoolE46B hkpConstrainedSystemFilter_isCollisionEnabled(const hkpCollidableE46B& a, const hkpCollidableE46B& b) const throw();
};

// Returns false if the collidable filter rejects the pair or a non-type-11 constraint links the two rigid bodies; true otherwise.
// @f3 0x00a74320 (community match, verified in this file)
class Task1447ConstraintData
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual int getType() const throw();
};
class Task1447Entity
{
  public:
    int hkpEntity_getNumConstraints() throw();
    int hkpEntity_getConstraint(int i) throw();
};
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: a, b
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high (was: ConstraintCollisionFilter)
hkBoolE46B hkpConstraintCollisionFilterE46B::hkpConstrainedSystemFilter_isCollisionEnabled(const hkpCollidableE46B& a,
                                                                       const hkpCollidableE46B& b) const throw()
{
    FUN_00c9c3c0_Class* pkBodyA = hkGetRigidBodyE46B(&a);
    FUN_00c9c3c0_Class* pkBodyB = hkGetRigidBodyE46B(&b);

    if (m_pChildFilter && !m_pChildFilter->m_collidableFilter.IsCollisionEnabled(a, b))
        return false;

    if (!pkBodyA || !pkBodyB)
        return true;

    const bool bSwapBodies = reinterpret_cast<Task1447Entity*>(pkBodyA)->hkpEntity_getNumConstraints() > reinterpret_cast<Task1447Entity*>(pkBodyB)->hkpEntity_getNumConstraints();
    FUN_00c9c3c0_Class* pkEntityA = bSwapBodies ? pkBodyB : pkBodyA;
    FUN_00c9c3c0_Class* pkEntityB = bSwapBodies ? pkBodyA : pkBodyB;

    int numConstraints = reinterpret_cast<Task1447Entity*>(pkEntityA)->hkpEntity_getNumConstraints();
    for (int i = 0; i < numConstraints; i++)
    {
        const hkpConstraintInstanceE46B* pkConstraint =
            reinterpret_cast<const hkpConstraintInstanceE46B*>(reinterpret_cast<Task1447Entity*>(pkEntityA)->hkpEntity_getConstraint(i));
        if (pkConstraint && reinterpret_cast<const Task1447ConstraintData*>(pkConstraint->m_data)->getType() != 11)
        {
            if (pkConstraint->m_pEntityA == pkEntityB || pkConstraint->m_pEntityB == pkEntityB)
                return false;
        }
    }
    return true;
}


struct CheckInterface
{
    virtual void unused();
    virtual unsigned char* evaluate(int*, int, int, int, int, int);
};
struct FilterDelegate
{
    int unk00;
    int unk04;
    int unk08;
    CheckInterface callback;
};
struct FilterResult
{
    bool value;
    FilterResult(bool v) : value(v)
    {}
};
struct ConstraintFilter
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    FilterDelegate* delegate;
    FilterResult Evaluate(int, int, int, int, int);
};
// @fnv 0x00e46cf0
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: input, a, b, bContainer, bKey
FilterResult ConstraintFilter::Evaluate(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FilterDelegate* const& ref = delegate;
    return FilterResult(ref == 0 || *delegate->callback.evaluate(&aiArg5, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5) != 0);
}

struct hkBoolE46D
{
    char m_cBooleanValue;
    hkBoolE46D(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

class hkFilterE46D
{
  public:
    virtual void V0();
    virtual hkBoolE46D IsCollisionEnabled(void* a, void* b);
};

struct hkWorldE46D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkFilterE46D m_iFilter;
};

class hkObjE46D
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkWorldE46D* m_pOwningWorld;

    hkBoolE46D IsInWorldFilter(void* a, void* b);
};

// Returns true if the object has no world or its world's filter accepts the two arguments.
// @fnv 0x00e46df0
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: a, collidableB
hkBoolE46D hkObjE46D::IsInWorldFilter(void* a, void* b)
{
    return !m_pOwningWorld || m_pOwningWorld->m_iFilter.IsCollisionEnabled(a, b).m_cBooleanValue;
}

class hkBoolE46C
{
  public:
    hkBoolE46C()
    {}
    hkBoolE46C(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkBase0E46C
{
  public:
    virtual ~hkBase0E46C();
    int unk04[2];
};

class hkFilterE46C
{
  public:
    virtual hkBoolE46C IsCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e,
                                          const void* f, const void* g) const;
};

class hkFilterImplE46C : public hkBase0E46C, public hkFilterE46C
{
};

class hkListE46C
{
  public:
    int unk00[10];
    hkFilterImplE46C* m_iFilter;

    hkBoolE46C FUN_00e46d40(const void* a, const void* b, const void* c, const void* d, const void* e, const void* f,
                            const void* g) const;
};

// Returns true when m_iFilter is null or when m_iFilter->IsCollisionEnabled(a, b, c, d, e, f, g) is true.
// @fnv 0x00e46d40
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: input, collectionBodyA, collectionBodyB, containerShapeA, containerShapeB, keyA, keyB
hkBoolE46C hkListE46C::FUN_00e46d40(const void* a, const void* b, const void* c, const void* d, const void* e,
                                    const void* f, const void* g) const
{
    return !m_iFilter || m_iFilter->IsCollisionEnabled(a, b, c, d, e, f, g);
}

namespace fnv_00e46da0 {
class hkBoolE46D
{
  public:
    hkBoolE46D()
    {}
    hkBoolE46D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkBase0E46D
{
  public:
    virtual ~hkBase0E46D();
    int unk04[3];
};

class hkFilterE46D
{
  public:
    virtual hkBoolE46D IsCollisionEnabled(const void* a, const void* b, const void* c, const void* d) const;
};

class hkFilterImplE46D : public hkBase0E46D, public hkFilterE46D
{
};

class hkListE46D
{
  public:
    int unk00[9];
    hkFilterImplE46D* m_iFilter;

    hkBoolE46D FUN_00e46da0(const void* a, const void* b, const void* c, const void* d) const;
};

// Returns true when m_iFilter is null or when m_iFilter->IsCollisionEnabled(a, b, c, d) is true.
// @fnv 0x00e46da0
// pdb: hkpConstrainedSystemFilter::isCollisionEnabled | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, vtable, high
// pdb params: aInput, shape, bContainer, bKey
hkBoolE46D hkListE46D::FUN_00e46da0(const void* a, const void* b, const void* c, const void* d) const
{
    return !m_iFilter || m_iFilter->IsCollisionEnabled(a, b, c, d);
}
}  // namespace fnv_00e46da0

int __cdecl CallA(void*, void*);
void __cdecl CallB(void*);
// If the owner at +0xc has type other than 11, calls CallA with the +0x10 offsets of the pointers at +0x14 and +0x18, and passes a nonzero result to CallB.
// @f3 0x00a74560 (community match, verified in this file)
struct OwnerT
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int v10();
};
// pdb: hkpConstrainedSystemFilter::constraintAddedCallback | hkpConstrainedSystemFilter.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
void __stdcall hkpConstrainedSystemFilter_constraintAddedCallback(void* p)
{
    OwnerT* owner = *reinterpret_cast<OwnerT**>(reinterpret_cast<char*>(p) + 0xc);
    if (owner->v10() != 11)
    {
        void* b = *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 0x18);
        void* a = *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 0x14);
        void* obj =
            reinterpret_cast<char*>(CallA(reinterpret_cast<char*>(a) + 0x10, reinterpret_cast<char*>(b) + 0x10));
        if (obj)
            CallB(obj);
    }
}


// Adjustor thunk for FUN_00dffb30: "sub ecx, 8; jmp FUN_00dffb00".
//
// MSVC "this adjusting thunk" emitted for a virtual inherited from a secondary
// base: it moves the secondary-base sub-object pointer back to the derived
// object pointer (sub ecx, 8) and tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base is
// a vtable pointer plus one int member (4 + 4 = 8). Both bases declare the same
// virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the thunk.
struct PrimaryBase
{
    virtual void FUN_00dffb30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00dffb30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb30
    virtual void FUN_00dffb30();
};

Derived::Derived()
{}

namespace fnv_00dffb40 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk for FUN_00dffb40.
// PrimaryBase is vptr + two int fields (size 0xc); SecondaryBase only declares the virtual.
struct PrimaryBase
{
    virtual void FUN_00dffb40();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00dffb40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb40
    virtual void FUN_00dffb40();
};

Derived::Derived()
{}
}  // namespace fnv_00dffb40

// Adjustor thunk: the secondary-base (+0x10) vtable entry for an override defined on the derived class.

namespace fnv_00dffb70 {
// sub ecx,0x14; jmp FUN_00dffb00
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x14 = vptr + four int fields).
struct PrimaryBase
{
    virtual void FUN_00dffb70();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00dffb70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb70
    virtual void FUN_00dffb70();
};

Derived::Derived()
{}
}  // namespace fnv_00dffb70
