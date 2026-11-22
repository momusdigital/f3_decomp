// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIDEFAULTAVOBJECTPALETTE_TYPES_NIAVOBJECT_LOCAL_H
#define FNV_NIDEFAULTAVOBJECTPALETTE_TYPES_NIAVOBJECT_LOCAL_H
#include "f3_common.h"
#include "layout_support.h"
#include "NiObjectNET.h"
#include "NiPoint3.h"
#include "NiProperty.h"
#include "layout_support.h"
#include "NiNode.h"
class FourComponentFloatVector;
class NiAVObject;
class NiCollisionObject;
class ThreeByThreeMatrix;
class NiPoint4;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator;
class NiTListItem_NiPointer_NiProperty___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiPointer_NiProperty___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTransform;
class FourComponentNumericValue;
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator) ==
                  4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    NiTListItem_NiPointer_NiProperty___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiProperty___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, NiTListItem<NiPointer<NiProperty> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, NiTListItem<NiPointer<NiProperty> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, const NiPointer<NiProperty>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*, const NiPointer<NiProperty>&)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // const NiPointer<NiProperty>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&)
    // NiPointer<NiProperty> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiPointer<NiProperty>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiProperty> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(NiTListItem<NiPointer<NiProperty> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiProperty> >
    // void __cdecl NiTPointerList<NiPointer<NiProperty> >::*()
    // NiTPointerList<NiPointer<NiProperty> >& __cdecl NiTPointerList<NiPointer<NiProperty> >::*(const NiTPointerList<NiPointer<NiProperty> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiProperty> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_NiProperty___) == 12);
#pragma pack(push, 4)
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FourComponentNumericValue) == 16);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_afComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_auiComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, x) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, y) == 4);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, z) == 8);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, w) == 12);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, v) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, u) == 0);
#pragma pack(push, 4)
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint4) == 16);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_kComponents) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_afExtents) == 0);
#pragma pack(push, 4)
class ThreeByThreeMatrix
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ThreeByThreeMatrix) == 48);
FNV_STATIC_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);
#endif
