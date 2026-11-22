#include "f3_common.h"
// src/havok/physics/collide/shape/compound/tree/mopp/modifiers/hkpremoveterminalsmoppmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/modifiers/hkpremoveterminalsmoppmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpRemoveTerminalsMoppModifier.h"

struct hkBoolE485
{
    char m_cBooleanValue;
    hkBoolE485(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

template <class T> class hkArrayE485
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkReferencedObjectE485
{
  public:
    virtual ~hkReferencedObjectE485();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpMoppModifierE485
{
  public:
    virtual ~hkpMoppModifierE485();
    virtual hkBoolE485 hkpRemoveTerminalsMoppModifier_shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) = 0;
    virtual void resetTerminal(hkUint32 id, const hkUint32* properties) = 0;
};

class hkpRemoveTerminalsMoppModifierE485 : public hkReferencedObjectE485, public hkpMoppModifierE485
{
  public:
    hkArrayE485<hkUint32> m_kRemovedTerminalIds;
    const hkArrayE485<hkUint32>* m_pTerminalIdsToRemove;

    virtual ~hkpRemoveTerminalsMoppModifierE485();
    virtual hkBoolE485 hkpRemoveTerminalsMoppModifier_shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties);
    virtual void resetTerminal(hkUint32 id, const hkUint32* properties);
};

// @fnv 0x00e48510
// pdb: hkpRemoveTerminalsMoppModifier::shouldTerminalBeRemoved | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, vtable, high
// pdb params: id, properties
// pdb: hkpRemoveTerminalsMoppModifier::shouldTerminalBeRemoved | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, vtable, high (was: IsTerminalRemoved)
hkBoolE485 hkpRemoveTerminalsMoppModifierE485::hkpRemoveTerminalsMoppModifier_shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties)
{
    return m_pTerminalIdsToRemove->indexOf(id) >= 0;
}

namespace fnv_00e48550 {
struct hkBoolE485
{
    char m_cBooleanValue;
    hkBoolE485(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

struct hkBitFieldE485
{
    unsigned int* m_auiBitFieldWords;

    int get(int index) const
    {
        return (m_auiBitFieldWords[index >> 5] >> (index & 0x1f)) & 1;
    }
};

}  // namespace fnv_00e48550

void* __cdecl FUN_00c85750();
struct Packed
{
    unsigned int lo : 8;
    unsigned int hi : 24;
};
struct FUN_00e48580_Array
{
    Packed* unk00;
    int unk04;
    unsigned int unk08;
};
struct FUN_00e48580_Obj
{
    int unk00;
    FUN_00e48580_Array arr;
    void hkpRemoveTerminalsMoppModifier_addTerminalRemoveInfo(int value);
};
// Appends a packed entry to the array, growing it via the allocator when full, then stores 0 in the low 8 bits and value in the high 24 bits.
// @f3 0x00a76540 (community match, verified in this file)
void __cdecl FUN_00901f10(void* array, int elementSize);

// pdb: hkpRemoveTerminalsMoppModifier::addTerminalRemoveInfo | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, vtable, high
// pdb params: relativeMoppAddress
// pdb: hkpRemoveTerminalsMoppModifier::addTerminalRemoveInfo | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, vtable, high (was: AppendPackedValue)
void FUN_00e48580_Obj::hkpRemoveTerminalsMoppModifier_addTerminalRemoveInfo(int value)
{
    FUN_00e48580_Array* arr = &this->arr;
    if (arr->unk04 == (int)(arr->unk08 & 0x3fffffff))
    {
        FUN_00901f10(arr, 4);
    }
    Packed* pEntry = &arr->unk00[arr->unk04++];
    pEntry->lo = 0;
    pEntry->hi = value;
}


class hkRefObjE486
{
  public:
    virtual ~hkRefObjE486() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjE486() throw()
    {
        m_sReferenceCount = 1;
    }
};

class hkVisitorE486
{
  public:
    virtual void visit(void* p) = 0;
};

template <typename T> struct hkArrayE486
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayE486() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

void __cdecl ConstructTemporaryObject(void* a, void* b, hkVisitorE486* visitor) throw();

class FUN_00e486e0 : public hkRefObjE486, public hkVisitorE486
{
  public:
    hkArrayE486<void*> m_found;
    void* m_iValueAtOffset0C;

    FUN_00e486e0(void* a, void* b, void* context) throw();
    virtual ~FUN_00e486e0() throw();
    virtual void visit(void* p);
};

// @fnv 0x00e486e0
// pdb: hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, objrun, medium
// pdb params: moppCode, aabb, shapesToRemove
FUN_00e486e0::FUN_00e486e0(void* apFirst, void* apSecond, void* context) throw()
{
    m_iValueAtOffset0C = context;
    ConstructTemporaryObject(apFirst, apSecond, this);
    m_iValueAtOffset0C = 0;
}

namespace fnv_00e48740 {
class hkMemoryAllocatorE487
{
  public:
    virtual ~hkMemoryAllocatorE487() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE487
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE487* m_pStreamAllocator;
    hkMemoryAllocatorE487& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE487& __cdecl FUN_00c85750();

template <class T> __forceinline void destructE487(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE487
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE487() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructE487(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorE487& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkReferencedObjectE487
{
  public:
    virtual ~hkReferencedObjectE487() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpEntityListenerE487
{
  public:
    virtual ~hkpEntityListenerE487() throw()
    {}
};

}  // namespace fnv_00e48740

struct __declspec(align(16)) FUN_00e67230_Obj
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
    void FUN_00e67230(int a1, int a2, int a3);
};

// Constructs a temporary object and forwards the three arguments to its constructor.
// @fnv 0x00e5d040
// pdb: hkMoppModifyVirtualMachine_queryAabb | hkpMoppMachine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: code, aabb, modifierOut
void __cdecl ConstructTemporaryObject(int a1, int a2, int a3)
{
    FUN_00e67230_Obj tmp;
    tmp.FUN_00e67230(a1, a2, a3);
}

#include <xmmintrin.h>
namespace fnv_00e485d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
}

struct hkVector4E485
{
    __m128 m_vComponents;
    const __m128& getQuad() const
    {
        return m_vComponents;
    }
    __m128& getQuad()
    {
        return m_vComponents;
    }
    void setMin4(const hkVector4E485& a, const hkVector4E485& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVector4E485& a, const hkVector4E485& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkAabbE485
{
    hkVector4E485 m_kMinimumCorner;
    hkVector4E485 m_kMaximumCorner;
};

struct __declspec(align(16)) hkpShapeBufferE485
{
    unsigned int m_kStorage[128];
};

template <class T> struct hkArrayE485
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE485() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T operator[](int i) const
    {
        return m_data[i];
    }
};

struct hkpMoppCodeE485;

class hkReferencedObjectE485
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkReferencedObjectE485()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectE485();
};

class hkpMoppModifierE485
{
  public:
    hkpMoppModifierE485()
    {}
    virtual void InvokeFirstModifierMethod();
    virtual void InvokeSecondModifierMethod();
};

void __cdecl ConstructTemporaryObject(const hkpMoppCodeE485* pkMoppCode, const hkAabbE485& kAabb, hkpMoppModifierE485* pkModifier);

}  // namespace fnv_00e485d0
