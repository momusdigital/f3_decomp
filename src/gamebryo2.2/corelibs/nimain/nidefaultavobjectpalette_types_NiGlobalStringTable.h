// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIDEFAULTAVOBJECTPALETTE_TYPES_NIGLOBALSTRINGTABLE_LOCAL_H
#define FNV_NIDEFAULTAVOBJECTPALETTE_TYPES_NIGLOBALSTRINGTABLE_LOCAL_H
#include "f3_common.h"
#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION.h"
#include "layout_support.h"
#include "NiGlobalStringTable.h"
class NiCriticalSection;
class NiGlobalStringTable;
class NiTPrimitiveArray_char___;
#pragma pack(push, 4)
class NiTPrimitiveArray_char___ : public NiTArray<char*, NiTMallocInterface<char*> >
{
  public:
    // base NiTArray<char *,NiTMallocInterface<char *> > at +0x0, size 16
    // NiTPrimitiveArray<char *>
    // void __cdecl NiTPrimitiveArray<char *>::*()
    // NiTPrimitiveArray<char *>& __cdecl NiTPrimitiveArray<char *>::*(const NiTPrimitiveArray<char *>&)
    // void __cdecl NiTPrimitiveArray<char *>::*()
    // void __cdecl NiTPrimitiveArray<char *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_char___) == 16);
#pragma pack(push, 4)
class NiCriticalSection
{
  public:
    _RTL_CRITICAL_SECTION m_kCriticalSection;  // +0x0, 28 bytes
    unsigned long m_ulThreadOwner;             // +0x1C, 4 bytes
    unsigned int m_uiLockCount;                // +0x20, 4 bytes
    unsigned char layoutPadding24[92];
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // void* __cdecl NiCriticalSection::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCriticalSection) == 128);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_kCriticalSection) == 0);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_ulThreadOwner) == 28);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_uiLockCount) == 32);
#endif
