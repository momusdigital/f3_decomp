// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIDEFAULTAVOBJECTPALETTE_H
#define FNV_NIDEFAULTAVOBJECTPALETTE_H
#include "f3_common.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObjectNET.h"
#include "NiAVObjectPalette.h"
class DFALL_NiTMapItem_NiFixedString_NiAVObject_____;
class NiAVObject;
class NiAVObjectPalette;
class NiStream;
class CloningProcess;
class NiDefaultAVObjectPalette;
class NiTFixedStringMap_NiAVObject___;
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___;
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator;
#pragma pack(push, 4)
class DFALL_NiTMapItem_NiFixedString_NiAVObject_____
{
  public:
    // void* __cdecl DFALL<NiTMapItem<NiFixedString,NiAVObject *> >::*()
    // void __cdecl DFALL<NiTMapItem<NiFixedString,NiAVObject *> >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_NiFixedString_NiAVObject_____) == 1);
#pragma pack(push, 4)
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator
    : public DFALL_NiTMapItem_NiFixedString_NiAVObject_____
{
  public:
    // base DFALL<NiTMapItem<NiFixedString,NiAVObject *> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___
{
  public:
    void RemoveAll();
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<NiFixedString, NiAVObject*>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiFixedString&, NiAVObject*)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&, NiAVObject*&)
    // void* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(void*&, NiFixedString&, NiAVObject*&)
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&, const NiFixedString&)
    // NiTMapItem<NiFixedString,NiAVObject *>* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*, NiFixedString&, NiAVObject*)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*)
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>& __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___) == 16);
FNV_STATIC_ASSERT(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_kItemCount) == 12);
#pragma pack(push, 4)
class NiTFixedStringMap_NiAVObject___
    : public NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___
{
  public:
    void GetNext(void*&, NiFixedString&, NiAVObject*&);
    void RemoveAll();
    // base NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *> at +0x0, size 16
    // NiTFixedStringMap<NiAVObject *>
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // NiTMapItem<NiFixedString,NiAVObject *>* __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*)
    // NiTFixedStringMap<NiAVObject *>& __cdecl NiTFixedStringMap<NiAVObject *>::*(const NiTFixedStringMap<NiAVObject *>&)
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTFixedStringMap_NiAVObject___) == 16);
#pragma pack(push, 4)
class NiDefaultAVObjectPalette : public NiAVObjectPalette
{
  public:
    void BuildPalette();
    void ProcessCloneBase(CloningProcess&);
    virtual void SetAVObject(NiFixedString& kName, NiAVObject* pkObj);
    virtual void LoadBinary(NiStream&);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // base NiAVObjectPalette at +0x0, size 8
    NiTFixedStringMap_NiAVObject___ m_kObjectMap;  // +0x8, 16 bytes
    NiAVObject* m_pkScene;                         // +0x18, 4 bytes
    // const NiRTTI* __cdecl NiDefaultAVObjectPalette::*()
    // NiObject* __cdecl NiDefaultAVObjectPalette::*(CloningProcess&)
    // void __cdecl NiDefaultAVObjectPalette::*(NiDefaultAVObjectPalette*, CloningProcess&)
    // void __cdecl NiDefaultAVObjectPalette::*(NiStream&)
    // void __cdecl NiDefaultAVObjectPalette::*(NiStream&)
    // bool __cdecl NiDefaultAVObjectPalette::*(NiStream&)
    // void __cdecl NiDefaultAVObjectPalette::*(NiStream&)
    // bool __cdecl NiDefaultAVObjectPalette::*(NiObject*)
    // NiObject* __cdecl NiDefaultAVObjectPalette::*()
    // void __cdecl NiDefaultAVObjectPalette::*(NiTPrimitiveArray<char *>*)
    // NiDefaultAVObjectPalette
    // void __cdecl NiDefaultAVObjectPalette::*()
    // NiAVObject* __cdecl NiDefaultAVObjectPalette::*(const NiFixedString&)
    // AddNamedAVObject
    // void __cdecl NiDefaultAVObjectPalette::*(CloningProcess&)
    // void __cdecl NiDefaultAVObjectPalette::*()
    // unsigned int __cdecl NiDefaultAVObjectPalette::*()
    // NiDefaultAVObjectPalette& __cdecl NiDefaultAVObjectPalette::*(const NiDefaultAVObjectPalette&)
    // void __cdecl NiDefaultAVObjectPalette::*()
    // void __cdecl NiDefaultAVObjectPalette::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiDefaultAVObjectPalette) == 28);
FNV_STATIC_ASSERT(offsetof(NiDefaultAVObjectPalette, m_kObjectMap) == 8);
FNV_STATIC_ASSERT(offsetof(NiDefaultAVObjectPalette, m_pkScene) == 24);
#endif
