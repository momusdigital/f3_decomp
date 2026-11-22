#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddcdd0
// pdb: hkpMeshWeldingUtility::modifyCombinedEdgesBitcode | hkpMeshWeldingUtility.obj | tesv_win, hash, low
unsigned int FUN_00ddcdd0(unsigned int auiValue, unsigned int auiIndex, unsigned int auiFieldValue)
{
    return (auiValue & ~(0x1f << (auiIndex * 5))) | (auiFieldValue << (auiIndex * 5));
}

struct DDCC60BaseObject
{
    virtual ~DDCC60BaseObject()
    {}
};

struct DDCC60Action
{
    virtual ~DDCC60Action()
    {}

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DDCC60Listener
{
    virtual ~DDCC60Listener()
    {}
};

int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB);

class __declspec(novtable) BDDCCB0ReferencedObject
{
  public:
    BDDCCB0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual ~BDDCCB0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class BDDCCB0ProcessContext
{
  public:
    virtual ~BDDCCB0ProcessContext();
    virtual const char* getType();
};

class BDDCCB0WorldAddedListener;

class BDDCCB0PhysicsContext : public BDDCCB0ReferencedObject, public BDDCCB0ProcessContext
{
  public:
    void AddWorldAddedListener(BDDCCB0WorldAddedListener* pkListener);
    void RetainReference();
};

template <class T> class BDDCCB0Array
{
  public:
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i) const
    {
        return m_data[i];
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class BDDCCB0Process
{
  public:
    BDDCCB0Process(bool bSelectable) : m_bSelectable(bSelectable)
    {}
    virtual ~BDDCCB0Process();

    bool m_bSelectable;
    void* m_pkProcessHandler;
    void* m_pkDisplayHandler;
    void* m_pkInStream;
    void* m_pkOutStream;
};

class BDDCCB0WorldAddedListener
{
  public:
    virtual ~BDDCCB0WorldAddedListener();
};

class FUN_00ddccb0_cls : public BDDCCB0ReferencedObject, public BDDCCB0Process, public BDDCCB0WorldAddedListener
{
  public:
    FUN_00ddccb0_cls(const BDDCCB0Array<BDDCCB0ProcessContext*>& kContexts) throw();
    virtual ~FUN_00ddccb0_cls();

    BDDCCB0PhysicsContext* m_pkContext;
};

// @f3 0x00a648d0 (community match, verified in this file)
// pdb: hkpWorldViewerBase::hkpWorldViewerBase | hkpWorldViewerBase.obj | fnv360_0822_retail, call_seq, medium
// pdb params: contexts
FUN_00ddccb0_cls::FUN_00ddccb0_cls(const BDDCCB0Array<BDDCCB0ProcessContext*>& kContexts) throw()
    : BDDCCB0Process(true), m_pkContext(0)
{
    int iSize = kContexts.GetLogicalSize();
    for (int i = 0; i < iSize; i++)
    {
        if (FUN_00cb0fa0("Physics", kContexts[i]->getType()) == 0)
        {
            m_pkContext = static_cast<BDDCCB0PhysicsContext*>(kContexts[i]);
            break;
        }
    }
    if (m_pkContext)
    {
        m_pkContext->AddWorldAddedListener(this);
        if (m_pkContext->m_usMemSizeAndFlags != 0)
            m_pkContext->m_sReferenceCount++;
    }
}


struct Item
{
    int unk00;
    int unk04;
    float unk08;
};

struct Flag
{
    bool value;
    Flag(bool v) : value(v)
    {}
};

// Compares unk08 of two Item objects and returns a Flag holding whether the first is less than the second.
// @f3 0x00a58ad0 (community match, verified in this file)
// pdb: weightedNeighbourLess | hkGeomConvexHullBuilder.obj | tesv_win, hash, low
Flag __cdecl FUN_00ddcda0(Item* left, Item* right) {
    bool result;
    if (*(float*)&left->unk04 < *(float*)&right->unk04)
        result = true;
    else
        result = false;
    return Flag(result);
}


#include <math.h>

struct DDCE80Bool
{
    char m_cBooleanValue;

    DDCE80Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00ddd040 {
struct S_V
{
    __m128 q;
};
struct S_P
{
    const S_V* p;
    const S_V* val() const
    {
        return p;
    }
};
}  // namespace fnv_00ddd040

struct Base1
{
// @fnv 0x00ddcd50
    virtual void FUN_00ddcd50();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct Base2
{
    virtual void FUN_00ddcd50();
};
struct Derived : Base1, Base2
{
    Derived();
    virtual void FUN_00ddcd50();
};
Derived::Derived()
{}
