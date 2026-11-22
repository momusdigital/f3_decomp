// NiNode: a scene graph object with children.
// Names: FNV360_PDB (NiNode, 0822 retail/debug). Vtable: 64 slots, checked against F3_EXE's NiNode vtable 0x00e213cc
// (64 slots). Visual C++ lays out each overload pair in the reverse of its declaration order. PC layout: 0xAC bytes.
#ifndef FNV_NINODE_H
#define FNV_NINODE_H
#include "layout_support.h"
#include "NiAVObject.h"
#pragma pack(push, 4)
class NiNode : public NiAVObject
{
  public:
    virtual ~NiNode();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsNode();
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    virtual void SetBound(BSNiBound* apBound);
    virtual void UpdateControllers(NiUpdateData& UpdateData);
    virtual void ApplyTransform(const NiMatrix3&, const NiPoint3&, bool);
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid);
    virtual void UpdateDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdatePropertiesDownward(NiPropertyState* pkParentState);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& UpdateData);
    virtual void OnVisible(NiCullingProcess& kCuller);
    virtual void PurgeRendererData(NiRenderer* apkRenderer);

    virtual void AttachChild(NiAVObject* pkChild, bool bFirstAvail);                              // 55
    virtual void InsertChildAt(unsigned int i, NiAVObject* pkChild);                             // 56
    virtual void DetachChild(NiAVObject* pkChild);                                               // 58
    virtual void DetachChild(NiAVObject* pkChild, NiPointer<NiAVObject>& aspAVObject);           // 57
    virtual void DetachChildAt(unsigned int i);                                                  // 60
    virtual void DetachChildAt(unsigned int i, NiPointer<NiAVObject>& aspAVObject);              // 59
    virtual void SetAt(unsigned int i, NiAVObject* pkChild);                                     // 62
    virtual void SetAt(unsigned int i, NiAVObject* pkChild, NiPointer<NiAVObject>& aspAVObject);  // 61
    virtual void UpdateUpwardPass();                                                             // 63

    void CopyMembers(NiNode* pkDest, NiCloningProcess& kCloning);
    void UpdatePropertiesUpward(NiPropertyState*& apState);
    static NiObject* CreateObject();

    NiTObjectArray<NiPointer<NiAVObject> > m_kChildren;  // +0x9C

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiNode) == 0xAC);
FNV_STATIC_ASSERT(offsetof(NiNode, m_kChildren) == 0x9C);
#endif
