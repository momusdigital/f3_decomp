#include "f3_common.h"
// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct FUN_00cbc4a0
{
    int* m_ppVirtualMethodTable;
    int m_auiShapeKeys;
    hkReferencedObject* m_states[11];

    ~FUN_00cbc4a0();
};

// @f3 0x0098bbd0 (community match, verified in this file)
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() {}
};

class FUN_00cd1e70
{
  public:
    virtual ~FUN_00cd1e70() {}
};

// pdb: hkpBroadPhaseBorder::~hkpBroadPhaseBorder | hkpBroadPhaseBorder.obj | fnv360_0822_retail, call_seq, medium
FUN_00cbc4a0::~FUN_00cbc4a0()
{
    *(int**)((char*)this + 0x00) = (int*)0xe7dabc;
    *(int**)((char*)this + 0x08) = (int*)0xe7dab0;
    *(int**)((char*)this + 0x0c) = (int*)0xe7daa0;

    for (int i = 3; i < 9; ++i)
    {
        hkReferencedObject* pState = m_states[i];
        if (pState)
        {
            pState->removeReference();
            m_states[i] = 0;
        }
    }

    *(int**)((char*)this + 0x0c) = (int*)0xe7a1a0;
    ((FUN_00cd1e70*)((char*)this + 0x08))->FUN_00cd1e70::~FUN_00cd1e70();
    ((hkBaseObject*)((char*)this + 0x00))->hkBaseObject::~hkBaseObject();
}


struct hkpCharacterStateView
{
    int m_auiShapeKeys[2];
    hkReferencedObject* m_states[32];
    hkReferencedObject* hkpCharacterStateManager_getState(int index);
};

// @fnv 0x00cbc510
// pdb: hkpCharacterStateManager::getState | hkpCharacterStateManager.obj | fnv360_0822_retail, call_seq + skyrim(call_seq), high
hkReferencedObject* hkpCharacterStateView::hkpCharacterStateManager_getState(int index)
{
    return m_states[index];
}
