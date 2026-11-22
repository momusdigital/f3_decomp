// NiProperty: a render state (alpha, material, texturing, ...) attached to an NiAVObject.
// Names: FNV360_PDB (NiProperty, 0822 retail). Vtable: 37 slots; F3_EXE has no NiProperty vtable (the class is abstract),
// and its derived classes' vtables agree (NiAlphaProperty 0x00db7534, 37 slots).
#ifndef FNV_NIPROPERTY_H
#define FNV_NIPROPERTY_H
#include "layout_support.h"
#include "NiObjectNET.h"
class NiUpdateData;
#pragma pack(push, 4)
class NiProperty : public NiObjectNET
{
  public:
    enum
    {
        ALPHA = 0,
        CULLING = 1,
        MATERIAL = 2,
        SHADE = 3,
        STENCIL = 4,
        TEXTURING = 5,
        WIREFRAME = 6,
        MAX_TYPES = 7,
        DITHER = 8,
        SPECULAR = 9,
        VERTEX_COLOR = 10,
        ZBUFFER = 11,
        REND_SPEC = 12,
        FOG = 13,
    };

    virtual ~NiProperty();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);

    virtual int Type() const = 0;                                                            // 35
    virtual void Update(NiUpdateData& UpdateData);                                           // 36

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiProperty) == 0x18);
#endif
