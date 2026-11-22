// gamebryo2.2/corelibs/nimain/nicollisionobject.cpp: NiCollisionObject (10 functions)
#include "f3_common.h"
#include "NiAVObject.h"
#include "NiCollisionObject.h"
#include "NiStream.h"
#include "NiViewerStrings.h"

class NiStream;
struct FUN_00a80fd0_shell : public NiObject
{
    void FUN_00a80fd0(NiStream& kStream);
};
// @fnv 0x00a80fd0
// pdb: bhkExtraData::LoadBinary | bhkExtraData.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arStream
void FUN_00a80fd0_shell::FUN_00a80fd0(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    kStream.ReadLinkID();
}

// @fnv 0x00a80ff0
// pdb: NiCollisionObject::LinkObject | NiCollisionObject.obj | fnv360_0822_retail, call_seq, low
// pdb params: kStream
void NiCollisionObject::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    m_pkSceneObject = (NiAVObject*)kStream.GetObjectFromLinkID();
}

// @fnv 0x00a810b0
// pdb: NiCollisionObject::SetSceneGraphObject | NiCollisionObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkSceneObject
void NiCollisionObject::SetSceneGraphObject(NiAVObject* pkSceneObject)
{
    m_pkSceneObject = pkSceneObject;
    if (pkSceneObject && pkSceneObject->GetCollisionObject() != this)
        pkSceneObject->SetCollisionObject(this);
}

// @fnv 0x00a810d0
// pdb: NiCollisionObject::NiCollisionObject | NiCollisionObject.obj | fnv360_0822_retail, call_seq, high
// pdb params: pkSceneObject
NiCollisionObject::NiCollisionObject(NiAVObject* pkSceneObject) : m_pkSceneObject(pkSceneObject)
{
    if (pkSceneObject && pkSceneObject->GetCollisionObject() != this)
        pkSceneObject->SetCollisionObject(this);
}

extern char const* const g_01267b70_arg1;

// @fnv 0x00a810a0
char const* const* __cdecl FUN_00a810a0()
{
    return &g_01267b70_arg1;
}

// @fnv 0x00a81010
// pdb: NiCollisionObject::RegisterStreamables | NiCollisionObject.obj (F3_EXE vtable slot 21)
bool NiCollisionObject::RegisterStreamables(NiStream& kStream)
{
    if (!NiObject::RegisterStreamables(kStream))
        return false;
    if (m_pkSceneObject)
        m_pkSceneObject->RegisterStreamables(kStream);
    return true;
}

// @fnv 0x00a81040
// pdb: NiCollisionObject::SaveBinary | NiCollisionObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: kStream
void NiCollisionObject::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);
    kStream.SaveLinkID(m_pkSceneObject);
}

// Shipped as Gamebryo wrote it: the scene objects are compared for presence against the other object itself, not
// against its scene object.
// @fnv 0x00a81060
// pdb: NiCollisionObject::IsEqual | NiCollisionObject.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkObject
bool NiCollisionObject::IsEqual(NiObject* pkObject)
{
    if (!NiObject::IsEqual(pkObject))
        return false;
    NiCollisionObject* pkOther = (NiCollisionObject*)pkObject;
    if ((m_pkSceneObject && !pkOther) || (!m_pkSceneObject && pkOther))
        return false;
    return true;
}

class BA81100StringArray
{
  public:
    virtual ~BA81100StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcA81100Name;

char* __cdecl FUN_00a7d330(const char* pcString);

class BA81100Base
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void AddExtraViewerStrings(BA81100StringArray* pkStrings);

    void BaseGetViewerStrings(BA81100StringArray* pkStrings);
};

class BA81100Object : public BA81100Base
{
  public:
    void FUN_00a81100(BA81100StringArray* pkStrings);
};

// Appends the base viewer strings, the A81100 name string, and any extra viewer strings to pkStrings.
// @fnv 0x00a81100
// pdb: NiCollisionData::GetViewerStrings | NiCollisionData.obj | fnv360_0822_retail, objrun, medium
// pdb params: pkStrings
void BA81100Object::FUN_00a81100(BA81100StringArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_pcA81100Name));
    AddExtraViewerStrings(pkStrings);
}

// @fnv 0x00a81160
// pdb: NiCollisionObject::AddViewerStrings | NiCollisionObject.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void NiCollisionObject::AddViewerStrings(NiTPrimitiveArray<char*>* pkStrings)
{
    pkStrings->Add(NiGetViewerString(ms_RTTI.GetName()));
    pkStrings->Add(NiGetViewerString("m_pkSceneObject", m_pkSceneObject));
}
