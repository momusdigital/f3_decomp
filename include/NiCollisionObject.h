// NiCollisionObject: the collision data of one scene graph object.
// Names: FNV360_PDB (NiCollisionObject, 0822 retail). Vtable: 40 slots, checked against F3_EXE's NiCollisionObject vtable 0x00e23964 (40 slots).
#ifndef FNV_NICOLLISIONOBJECT_H
#define FNV_NICOLLISIONOBJECT_H
#include "layout_support.h"
#include "NiObject.h"
class NiAVObject;
class NiUpdateData;
#pragma pack(push, 4)
class NiCollisionObject : public NiObject
{
  public:
    NiCollisionObject(NiAVObject* pkSceneObject);
    virtual ~NiCollisionObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void AddViewerStrings(NiTPrimitiveArray<char*>* pkStrings);

    virtual void SetSceneGraphObject(NiAVObject* pkSceneObject);                             // 35
    virtual void UpdateWorldData(NiUpdateData&) = 0;                                         // 36
    virtual void RecreateWorldData() = 0;                                                    // 37
    virtual void Initialize(void* pkData);                                                   // 38
    virtual void Convert(unsigned int uiVersion, void* pkData);                              // 39

    NiAVObject* m_pkSceneObject;                   // +0x8

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCollisionObject) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiCollisionObject, m_pkSceneObject) == 0x8);
#endif
