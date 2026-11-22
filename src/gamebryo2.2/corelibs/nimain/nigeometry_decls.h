// gamebryo2.2/corelibs/nimain/nigeometry_decls.h: declares NiRTTI, NiCollisionObject, NiCullingProcess, NiBinaryReader, NiFixedString and more
#ifndef FNV_TASK_NIGEOMETRY_DECLS_H
#define FNV_TASK_NIGEOMETRY_DECLS_H
#include "f3_common.h"
class NiAVObject;
class NiRTTI
{
  public:
    bool IsExactly(const NiRTTI* type) const
    {
        return this == type;
    }
};
class NiGeometry;
class NiBound;
class NiTransform;
class NiTimeController;
class CloningProcess;
class NiGeometryData;
class NiCollisionObject
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual NiCollisionObject* Clone(CloningProcess&);
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Unk24(void* state);
    virtual void Unk25();
};
class NiCullingProcess
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Append(NiGeometry* geometry);
};
class NiStream;
struct NiBinaryReader
{
    typedef int(__cdecl* ReadProc)(NiBinaryReader*, unsigned int*, unsigned int, void*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiPosition;
    ReadProc m_pRead;
};
class NiFixedString
{
  public:
    char* m_pObject;
};
template <class T> void ReadBinaryValue(NiStream& stream, T& value);
template <> void ReadBinaryValue<unsigned int>(NiStream& stream, unsigned int& value);
class NiObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual NiObject* Clone(CloningProcess& process);
    virtual void Slot19();
    virtual void Slot20();
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void ProcessClone(CloningProcess& process);
    unsigned int m_uiRefCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    operator T*()
    {
        return m_pObject;
    }
    T* operator->()
    {
        return m_pObject;
    }
    NiPointer<T>& operator=(T* object)
    {
        T* old = m_pObject;
        if (old != object)
        {
            if (old && InterlockedDecrement((long volatile*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            m_pObject = object;
            if (object)
                InterlockedIncrement((long volatile*)&object->m_uiRefCount);
        }
        return *this;
    }
};
class NiProperty
{
  public:
    virtual ~NiProperty();
    virtual void DeleteThis();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual int GetType();
    unsigned int m_uiRefCount;
};
class NiPropertyState
{
  public:
    NiPointer<NiProperty> m_aspProps[7];  // src: FNV360_PDB +0x0 (old: m_kProperties)
    NiPropertyState& operator=(const NiPropertyState& other);
};
class NiPropertyNode
{
  public:
    NiPropertyNode* m_pkNext;  // src: FNV360_PDB +0x0
    NiPropertyNode* m_pkPrev;  // src: FNV360_PDB +0x4 (old: m_uiPad)
    NiPointer<NiProperty> m_element;  // src: FNV360_PDB +0x8 (old: m_pkProperty)
    static NiPointer<NiProperty>& GetNext(NiPropertyNode*& pos)
    {
        NiPointer<NiProperty>& value = pos->m_element;
        pos = pos->m_pkNext;
        return value;
    }
};
// NiTPointerList<NiPointer<NiProperty> >: NiTListBase's head, tail and allocator count.
template <class TItem> class NiTPointerList
{
  public:
    TItem* m_pkHead;  // src: FNV360_PDB +0x0
    TItem* m_pkTail;  // src: FNV360_PDB +0x4
    unsigned int m_uiCount;  // src: FNV360_PDB +0x8 (m_kAllocator.m_uiCount)
};
extern unsigned int DAT_011f42a4;
extern unsigned int DAT_011f42a0;
class RecursiveSpinLock
{
  public:
    void Lock(const char* name);
};
class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};
class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
class NiBound
{
  public:
    NiPoint3 center;
    union
    {
        float radius;
        unsigned int radiusBits;
    };
    NiBound()
    {}
    NiBound(const NiBound& b) : center(b.center), radiusBits(b.radiusBits)
    {}
    void SetCenterAndRadius(const NiPoint3& point, float value)
    {
        center = point;
        radius = value;
    }
    void Update(const NiBound&, const NiTransform&);
    void TransformPoint(const NiTransform&);
    bool FUN_00a92660(const NiBound&);
};
extern NiBound DAT_011f4288;
inline const NiBound& __fastcall PreviousBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
inline bool BoundFlag(unsigned int bits, unsigned int shift)
{
    return (bits >> shift) & 1;
}
inline NiBound CopyWorldBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
class NiLODNode;
class NiScreenLODData
{
  public:
    void UpdateScreenBound(NiLODNode*);
};
class NiTransform
{
  public:
    unsigned int values[13];
};
class NiFlags
{
  public:
    unsigned int bits;
    bool GetBit(unsigned int pos) const
    {
        return (bits >> pos) & 1;
    }
};
class NiObjectNET
{
  public:
    void CopyMemberData(NiObjectNET*, CloningProcess&);
};
class NiAVObject
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual NiRTTI* GetRTTI();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void SetWorldBound(NiBound*);
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void FinalUpdate(bool update);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void LoadBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void ApplyPropertyState(const NiPropertyState&);
    void SetName(const NiFixedString&);
    void SetSelectiveUpdateFlags(bool&, bool, bool&);
    void CopyMemberData();
    void FUN_00a5ac90(NiAVObject*, CloningProcess&);
    void FUN_00a5abe0(NiAVObject*, void*, CloningProcess&);
    void AssignCollisionObject(NiCollisionObject*);
    unsigned int m_uiRefCount;  // src: FNV360_PDB +0x4 (old: m_pad18)
    NiFixedString m_kName;  // src: FNV360_PDB +0x8 (old: m_pad18)
    NiTimeController* m_spControllers;  // src: FNV360_PDB +0xC (old: m_pad18)
    unsigned char unk10[0x8];
    void* m_pkParent;  // src: FNV360_PDB +0x18 (old: m_pParentNode)
    NiPointer<NiCollisionObject> m_spCollisionObject;
    NiBound* m_kWorldBound;  // src: FNV360_PDB +0x20 (old: m_worldBound)
    NiTPointerList<NiPropertyNode> m_kPropertyList;  // src: FNV360_PDB +0x24 (old: m_kProperties)
    unsigned int m_uFlags;  // src: FNV360_PDB +0x30 (old: m_flags)
    NiTransform m_kLocal;  // src: FNV360_PDB +0x34 (old: m_kLocalTransform)
    NiTransform m_kWorld;  // src: FNV360_PDB +0x68 (old: m_worldTransform)
};
class NiGeometryData : public NiObject
{
  public:
    unsigned short m_usVertices;  // src: FNV360_PDB +0x8
    unsigned short m_usID;  // src: FNV360_PDB +0xA
    unsigned short m_usDataFlags;  // src: FNV360_PDB +0xC
    unsigned short m_usDirtyFlags;  // src: FNV360_PDB +0xE
    NiBound m_kBound;  // src: FNV360_PDB +0x10
};
template <> NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject*);
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
    static void* operator new(unsigned int, void* memory) throw()
    {
        return memory;
    }
};
class NiD3DShaderInterface : public NiMemObject
{
  public:
    NiD3DShaderInterface() throw();
    bool IsExactKindOf(const NiRTTI* type)
    {
        return GetRTTI()->IsExactly(type);
    }
    virtual void vfn_00();
    virtual void vfn_04();
    virtual NiRTTI* GetRTTI();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void Attach(NiAVObject*);
    char data[0x10];
};
inline NiD3DShaderInterface* CreateGeometryShader()
{
    NiD3DShaderInterface* shader = 0;
    void* memory = NiMemObject::operator new(sizeof(NiD3DShaderInterface));
    if (memory)
        shader = new (memory) NiD3DShaderInterface;
    return shader;
}
inline bool& TestGeometryShaderType(NiD3DShaderInterface* object, const NiRTTI* type, bool& result)
{
    result = (unsigned char)(object->GetRTTI() == type) & 255;
    return result;
}
inline bool NiIsExactKindOf(const NiRTTI* type, NiD3DShaderInterface* object)
{
    return object ? object->IsExactKindOf(type) : false;
}
extern NiRTTI DAT_011f5d08;
class NiTexture
{
  public:
    const NiFixedString& GetFilename();
};
class NiD3DShaderProgram
{
  public:
    const char* GetName();
};
class MagicItem;
class NonActorMagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem*);
};
class NiController
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void Update();
    char pad[0x2c];
    NiController* next;
};
struct NiGeometryProperties
{
    char pad[12];
    NiPropertyState* state;
};
class NiGeometry : public NiAVObject
{
  public:
    NiPropertyState m_PropertyState;  // src: FNV360_PDB +0x9C (old: NiAVObject::m_uiContentCount)
    NiPointer<NiGeometryData> m_spModelData;  // src: FNV360_PDB +0xB8 (old: m_spGeometryData)
    NiPointer<NiObject> m_spSkinInstance;  // src: FNV360_PDB +0xBC (old: m_spSkinningInstance)
    NiD3DShaderInterface* m_spShader;  // src: FNV360_PDB +0xC0 (old: m_shader)
    void SetSelectiveUpdateFlags(bool&, bool, bool&);
    virtual void UpdateWorldBound();
    const NiBound& GetBoundingVolume() const
    {
        if (m_kWorldBound)
            return *m_kWorldBound;
        return DAT_011f4288;
    }
    bool GetFlag19() const
    {
        return ((const NiFlags*)&m_uFlags)->GetBit(19);
    }
    bool GetFlag13() const
    {
        return ((const NiFlags*)&m_uFlags)->GetBit(13);
    }
    bool GetFlag22() const
    {
        return (m_uFlags >> 22) & 1;
    }
    void SetFlag22(bool value)
    {
        unsigned int flags = m_uFlags;
        if (value)
            flags |= 0x400000;
        else
            flags &= ~0x400000;
        m_uFlags = flags;
    }
    NiGeometry* CopyMemberData();
    void UpdatePropertyControllers(NiGeometryProperties&);
    virtual void OnVisible(NiCullingProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual void ReplaceModelData(NiGeometryData* data);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void LoadBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
};
class NiStream
{
  public:
    NiObject* GetLoadedObject();
    void ResetStreamState();
    void ReadStringTableEntry(NiFixedString& value);
    void ReadFixedString(NiFixedString& value);
};
#endif
