// src/f3staging/f3blk_00ac0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00ad1250 (community match, verified in this file)
namespace f3m_00ad1250 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);

struct NiRefObject
{
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
    inline void DecRefCount() { if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis(); }
    inline void IncRefCount() { InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount)); }
};

struct NiAVObjectSI : NiRefObject {};

template <class T>
class NiPointerSI
{
public:
    T* m_pObject;
    NiPointerSI(T* p = 0) { m_pObject = p; if (m_pObject) m_pObject->IncRefCount(); }
    NiPointerSI(const NiPointerSI<T>& other) { m_pObject = other.m_pObject; if (m_pObject) m_pObject->IncRefCount(); }
    ~NiPointerSI()
    {
        T* p = *(T* volatile*)&m_pObject;
        if (p)
            p->DecRefCount();
    }
    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
};

struct NiAVObject;
struct NiPool
{
    void* m_pVtbl; void* m_pBase;
    unsigned short m_usMaxSize; unsigned short m_usSize;
    void Add(const NiPointerSI<NiAVObjectSI>& pkObject);
};
struct PoolArraySI
{
    void* m_pVtbl; NiPool** m_pBase;
    unsigned short m_usMaxSize; unsigned short m_usSize;
};
struct NiMeshPSysDataSI
{
    char m_00[0x88];
    PoolArraySI m_kPoolArrays;
    void FUN_00ad1250(unsigned int uiIndex, NiPointerSI<NiAVObjectSI> pkObject);
};

// pdb: NiMeshPSysData::AddToPool | NiMeshPSysData.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: uiGeneration, spObject
void NiMeshPSysDataSI::FUN_00ad1250(unsigned int uiIndex, NiPointerSI<NiAVObjectSI> pkObject)
{
    if (uiIndex >= m_kPoolArrays.m_usSize)
        return;
    if (m_kPoolArrays.m_pBase[uiIndex] == 0)
        return;
    NiPool*& rpkSlot = m_kPoolArrays.m_pBase[uiIndex];
    NiPool* pkPool = (*(NiPool** volatile*)&m_kPoolArrays.m_pBase)[uiIndex];
    if (pkPool->m_usSize < pkPool->m_usMaxSize)
        rpkSlot->Add(pkObject);
}
}   // namespace f3m_00ad1250
