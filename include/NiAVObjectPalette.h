// NiAVObjectPalette: maps names to the scene graph objects an animation targets.
// Names: FNV360_PDB (NiAVObjectPalette, 0822 retail). Vtable: 37 slots, checked against F3_EXE's NiAVObjectPalette
// vtable 0x00e22174 (37 slots).
#ifndef FNV_NIAVOBJECTPALETTE_H
#define FNV_NIAVOBJECTPALETTE_H
#include "layout_support.h"
#include "NiObject.h"
class NiAVObject;
class NiFixedString;
#pragma pack(push, 4)
class NiAVObjectPalette : public NiObject
{
  public:
    virtual ~NiAVObjectPalette();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);

    virtual NiAVObject* GetAVObject(const NiFixedString& kName) = 0;      // 35
    virtual void SetAVObject(NiFixedString& kName, NiAVObject* pkObj) = 0;  // 36

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAVObjectPalette) == 0x8);
#endif
