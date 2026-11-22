#include <new>
// src/f3staging/f3iso_0091ba60_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x0091ba60 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0091ba60 (community match, verified in this file)
namespace f3m_0091ba60 {
class Malleable91BaseObject
{
public:
    virtual ~Malleable91BaseObject() {}
};
class Malleable91ReferencedObject : public Malleable91BaseObject
{
public:
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    Malleable91ReferencedObject() : m_referenceCount(1) {}
    virtual ~Malleable91ReferencedObject() {}
};
class Malleable91ConstraintData : public Malleable91ReferencedObject
{
public:
    void* m_userData;
    Malleable91ConstraintData() : m_userData(0) {}
    virtual ~Malleable91ConstraintData();
    // Remaining virtual slots are opaque; this constructor never calls them.
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
};
struct Malleable91ConstraintAtom
{
    unsigned short m_type;
    Malleable91ConstraintAtom(int type) : m_type((unsigned short)type) {}
};
struct Malleable91BridgeAtom : Malleable91ConstraintAtom
{
    void* m_buildJacobianFunc;
    Malleable91ConstraintData* m_constraintData;
    Malleable91BridgeAtom() : Malleable91ConstraintAtom(1) {}
    void hkpBridgeConstraintAtom_init(Malleable91ConstraintData* constraintData);
};
struct Malleable91BridgeAtoms
{
    Malleable91BridgeAtom m_bridgeAtom;
};
class FUN_0091ba60 : public Malleable91ConstraintData
{
public:
    Malleable91ConstraintData* m_constraintData;
    Malleable91BridgeAtoms m_atoms;
    float m_strength;
    FUN_0091ba60();
    virtual ~FUN_0091ba60();
};
// pdb: ahkpMalleableConstraintData::ahkpMalleableConstraintData | bhkMalleableConstraint.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: bhkMalleableConstraint::~bhkMalleableConstraint)
FUN_0091ba60::FUN_0091ba60()
{
    m_constraintData = 0;
    m_atoms.m_bridgeAtom.hkpBridgeConstraintAtom_init(this);
    m_strength = 0.01f;
}

}   // namespace f3m_0091ba60
