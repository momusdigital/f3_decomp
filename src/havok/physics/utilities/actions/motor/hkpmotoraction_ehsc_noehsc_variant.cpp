#include "f3_common.h"
// src/havok/physics/utilities/actions/motor/hkpmotoraction_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMotorAction.h"

class hkpRigidBody;
class hkpPhantom;

struct hkMemoryAllocatorMA
{
    virtual ~hkMemoryAllocatorMA();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterMA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorMA* m_pStreamAllocator;
    hkMemoryAllocatorMA& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterMA& __cdecl FUN_00c85750();

template <class T> struct hkArrayMA
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpMotorActionMA : public hkpMotorAction
{
  public:
    void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        return b;
    }
    void operator delete(void*, unsigned int);

    hkpMotorActionMA(hkpRigidBody* body, const hkVector4& axis, hkReal spinRate, hkReal gain);

    hkpAction* hkpMotorAction_clone(const hkArrayMA<hkpEntity*>& newEntities, const hkArrayMA<hkpPhantom*>& newPhantoms) const;
};

// @f3 0x009da400 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned int DAT_010f3170;

struct F3MemoryAllocator
{
    void* __thiscall FUN_008f6d30(int size, int alignment);
};

struct hkpMotorActionMAInit
{
    hkpMotorActionMA* __thiscall FUN_009da340(hkpRigidBody* body, const hkVector4& axis,
                                              hkReal spinRate, hkReal gain);
};

// pdb: hkpMotorAction::clone | hkpMotorAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
hkpAction* hkpMotorActionMA::hkpMotorAction_clone(const hkArrayMA<hkpEntity*>& newEntities,
                                          const hkArrayMA<hkpPhantom*>& newPhantoms) const
{
    if (newEntities.GetLogicalSize() != 1)
        return 0;

    if (newPhantoms.GetLogicalSize() != 0)
        return 0;

    F3MemoryAllocator* allocator = (F3MemoryAllocator*)TlsGetValue(DAT_010f3170);
    hkpMotorActionMAInit* memory = (hkpMotorActionMAInit*)allocator->FUN_008f6d30(sizeof(hkpMotorActionMA), 0x29);
    *(unsigned short*)((char*)memory + 4) = sizeof(hkpMotorActionMA);
    hkpMotorActionMA* ma = memory->FUN_009da340(
        (hkpRigidBody*)newEntities[0], m_kAxisEndPoints, m_fSpinRate, m_fGain);
    ma->m_bSlotEnabled = m_bSlotEnabled;
    ma->m_ulUserData = m_ulUserData;
    return ma;
}

