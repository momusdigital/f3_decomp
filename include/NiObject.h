// NiObject: the base of every streamable, clonable Gamebryo class.
// Names: FNV360_PDB (NiObject, 0822 retail). Vtable: 35 slots, checked against F3_EXE's NiObject vtable 0x00e2087c
// (35 slots); slots 0-1 are NiRefObject's.
#ifndef FNV_NIOBJECT_H
#define FNV_NIOBJECT_H
#include "layout_support.h"
#include "NiRefObject.h"
#include "NiRTTI.h"
class BSFadeNode;
class BSMultiBoundNode;
class BSNiBound;
class BSResizableTriShape;
class BSSegmentedTriShape;
class NiCloningProcess;
class NiControllerManager;
class NiGeometry;
class NiLines;
class NiNode;
class NiObjectGroup;
class NiParticles;
class NiStream;
class NiTriBasedGeom;
class NiTriShape;
class NiTriStrips;
class bhkBlendCollisionObject;
class bhkLimitedHingeConstraint;
class bhkNiCollisionObject;
class bhkRigidBody;
template <class T> class NiTPrimitiveArray;
#pragma pack(push, 4)
class NiObject : public NiRefObject
{
  public:
    NiObject();
    virtual ~NiObject();
    virtual const NiRTTI* GetRTTI() const;                                         //  2
    virtual NiNode* IsNode();                                                      //  3
    virtual BSFadeNode* IsFadeNode();                                              //  4
    virtual BSMultiBoundNode* IsMultiBoundNode();                                  //  5
    virtual NiGeometry* IsGeometry();                                              //  6
    virtual NiTriBasedGeom* IsTriBasedGeom();                                      //  7
    virtual NiTriStrips* IsTriStrips();                                            //  8
    virtual NiTriShape* IsTriShape();                                              //  9
    virtual BSSegmentedTriShape* IsSegmentedTriShape();                            // 10
    virtual BSResizableTriShape* IsResizableTriShape();                            // 11
    virtual NiParticles* IsParticlesGeom();                                        // 12
    virtual NiLines* IsLinesGeom();                                                // 13
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();                        // 14
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();                  // 15
    virtual bhkRigidBody* IsBhkRigidBody() const;                                  // 16
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();              // 17
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);                     // 18
    virtual void LoadBinary(NiStream& kStream);                                    // 19
    virtual void LinkObject(NiStream& kStream);                                    // 20
    virtual bool RegisterStreamables(NiStream& kStream);                           // 21
    virtual void SaveBinary(NiStream& kStream);                                    // 22
    virtual bool IsEqual(NiObject* pkObject);                                      // 23
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings);            // 24
    virtual void AddViewerStrings(NiTPrimitiveArray<char*>* pkStrings);            // 25
    virtual void ProcessClone(NiCloningProcess& kCloning);                         // 26
    virtual void PostLinkObject(NiStream& kStream);                                // 27
    virtual bool StreamCanSkip();                                                  // 28
    virtual const NiRTTI* GetStreamableRTTI() const;                               // 29
    virtual void SetBound(BSNiBound* pkBound);                                     // 30
    virtual unsigned int GetBlockAllocationSize() const;                           // 31
    virtual NiObjectGroup* GetGroup() const;                                       // 32
    virtual void SetGroup(NiObjectGroup* pkGroup);                                 // 33
    virtual NiControllerManager* IsNiControllerManager();                          // 34

    NiObject* Clone();
    NiObject* Clone(NiCloningProcess& kCloning);
    void CopyMembers(NiObject* pkDest, NiCloningProcess& kCloning);
    NiObject* CreateSharedClone(NiCloningProcess& kCloning);

    static const NiRTTI ms_RTTI;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiObject) == 0x8);
#endif
