// NiAVObject: a scene graph object with a parent, a local and a world transform, a world bound and properties.
// Names: FNV360_PDB (NiAVObject, 0822 retail/debug). Vtable: 55 slots, checked against F3_EXE's NiAVObject vtable
// 0x00e20b2c (55 slots). PC layout: 0x9C bytes (NiTransform is 0x34 on PC).
#ifndef FNV_NIAVOBJECT_H
#define FNV_NIAVOBJECT_H
#include "layout_support.h"
#include "NiObjectNET.h"
#include "NiTPointerList.h"
#include "NiTransform.h"
class NiCollisionObject;
class NiCullingProcess;
class NiDynamicEffectState;
class NiProperty;
class NiPropertyState;
class NiRenderer;
class NiUpdateData;
#pragma pack(push, 4)
class NiAVObject : public NiObjectNET
{
  public:
    enum
    {
        UPDATE_FLAG_NONE = 0,
        UPDATE_FLAG_PARENT_IS_CULLED = 1
    };

    virtual ~NiAVObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject);
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    virtual void SetBound(BSNiBound* apBound);

    virtual void UpdateControllers(NiUpdateData& UpdateData);                                // 35
    virtual void ApplyTransform(const NiMatrix3&, const NiPoint3&, bool);                    // 36
    virtual void SetMaterialNeedsUpdate(bool bNeedsUpdate);                                  // 37
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool bFlag);                              // 38
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);                         // 39
    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                         bool& bRigid);                                      // 40
    virtual void UpdateDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);          // 41
    virtual void UpdateSelectedDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);  // 42
    virtual void UpdateRigidDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);     // 43
    virtual void UpdatePropertiesDownward(NiPropertyState* pkParentState);                   // 44
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);                 // 45
    virtual void UpdateWorldData(NiUpdateData& UpdateData);                                  // 46
    virtual void UpdateWorldBound();                                                         // 47
    virtual void UpdateTransformAndBounds(NiUpdateData& UpdateData);                         // 48
    virtual void PreAttachUpdate(NiNode* pEventualParent, NiUpdateData& UpdateData);         // 49
    virtual void PreAttachUpdateProperties(NiNode* pEventualParent);                         // 50
    virtual void PreAttachUpdateEffects(NiNode* pEventualParent);                            // 51
    virtual void PostAttachUpdate();                                                         // 52
    virtual void OnVisible(NiCullingProcess&);                                               // 53
    virtual void PurgeRendererData(NiRenderer* apkRenderer);                                 // 54

    // Inline accessors (FNV360_PDB, 0822 debug build; inline in the retail builds).
    NiNode* GetParent()
    {
        return m_pkParent;
    }
    NiCollisionObject* GetCollisionObject() const
    {
        return m_spCollisionObject;
    }
    const NiTransform& GetLocalTransform() const
    {
        return m_kLocal;
    }
    const NiTransform& GetWorldTransform() const
    {
        return m_kWorld;
    }
    const NiPoint3& GetTranslate() const
    {
        return m_kLocal.m_Translate;
    }
    const NiMatrix3& GetRotate() const
    {
        return m_kLocal.m_Rotate;
    }
    float GetScale() const
    {
        return m_kLocal.m_fScale;
    }
    const NiPoint3& GetWorldTranslate() const
    {
        return m_kWorld.m_Translate;
    }
    const NiMatrix3& GetWorldRotate() const
    {
        return m_kWorld.m_Rotate;
    }
    float GetWorldScale() const
    {
        return m_kWorld.m_fScale;
    }
    bool GetBit(unsigned int uMask) const
    {
        return (m_uFlags & uMask) != 0;
    }

    void AttachParent(NiNode* pkParent);
    void AttachProperty(NiProperty* pkProperty);
    void DetachProperty(NiProperty* pkProperty);
    NiProperty* GetProperty(int iType) const;
    void SetCollisionObject(NiCollisionObject* pkCollisionObject);
    void CopyMembers(NiAVObject* pkDest, NiCloningProcess& kCloning);
    void Cull(NiCullingProcess& kCuller);
    void UpdateProperties();
    void UpdateEffects();
    void UpdateSelected(NiUpdateData& UpdateData);
    bool HasTransformController() const;
    bool HasPropertyController() const;

    NiNode* m_pkParent;                                       // +0x18
    NiPointer<NiCollisionObject> m_spCollisionObject;         // +0x1C
    BSNiBound* m_kWorldBound;                                 // +0x20
    NiTPointerList<NiPointer<NiProperty> > m_kPropertyList;  // +0x24
    unsigned int m_uFlags;                                    // +0x30
    NiTransform m_kLocal;                                     // +0x34
    NiTransform m_kWorld;                                     // +0x68

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAVObject) == 0x9C);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_pkParent) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_spCollisionObject) == 0x1C);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorldBound) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kPropertyList) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_uFlags) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kLocal) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiAVObject, m_kWorld) == 0x68);
#endif
