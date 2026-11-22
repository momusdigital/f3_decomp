// gamebryo2.2/corelibs/nianimation/nitexturetransformcontroller.cpp: NiTextureTransformController, NiNIFImageReader, TextureTransformOwner (20 functions)
#include "f3_common.h"
#include "nitexturetransformcontroller_decls.h"
#include "nitexturetransformcontroller_types_NiTextureTransformController.h"

// Builds and caches a controller ID string from the transform member, formatting it as "%d-%d-<member>".
// @fnv 0x00a46300
// pdb: NiTextureTransformController::GetCtlrID | NiTextureTransformController.obj | fnv360_0822_retail, ustr, medium
const char* NiTextureTransformController::GetControllerID()
{
    char* pCachedID = m_pcCtlrID;
    if (pCachedID)
        return pCachedID;

    m_pcCtlrID = (char*)_NiMalloc(0x32);
    switch (m_eMember)
    {
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_U:
        NiSprintf(m_pcCtlrID, 0x32, "%d-%d-TT_TRANSLATE_U", m_bShaderMap, m_uiMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_V:
        NiSprintf(m_pcCtlrID, 0x32, "%d-%d-TT_TRANSLATE_V", m_bShaderMap, m_uiMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_ROTATE:
        NiSprintf(m_pcCtlrID, 0x32, "%d-%d-TT_ROTATE", m_bShaderMap, m_uiMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_U:
        NiSprintf(m_pcCtlrID, 0x32, "%d-%d-TT_SCALE_U", m_bShaderMap, m_uiMapIndex);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_V:
        NiSprintf(m_pcCtlrID, 0x32, "%d-%d-TT_SCALE_V", m_bShaderMap, m_uiMapIndex);
        break;
    }
    return m_pcCtlrID;  // src: FNV360_PDB +0x4C (old: m_pCachedControllerID)
}

// @fnv 0x00a46740
NiTextureTransformController::NiTextureTransformController(NiObjectNET* property, NiTexturingProperty__Map* map,
                                                           NiTextureTransformController__TransformMember member) throw()
    : m_eMember(member)
{
    m_pcCtlrID = 0;
    m_uiLastIdx = 0;
    m_bShaderMap = false;
    m_uiMapIndex = 0;
    if (m_pkTarget != property)
        m_pkMap = 0;
    NiTimeController::SetTarget(property);
    m_pkMap = map;
    if (!map)
    {
        NiFree(m_pcCtlrID);
        m_pcCtlrID = 0;
        return;
    }
    TexturePropertyLayout* prop = (TexturePropertyLayout*)m_pkTarget;
    if (!prop)
        return;
    for (unsigned int uiIndex = 0; uiIndex < prop->size; ++uiIndex)
    {
        if (prop->maps[uiIndex] == map)
        {
            m_bShaderMap = false;
            m_uiMapIndex = uiIndex;
            NiFree(m_pcCtlrID);
            m_pcCtlrID = 0;
            IsTextureMapValid();
            return;
        }
    }
    unsigned int uiIndex = 0;
    unsigned int count = prop->FUN_00a46410();
    for (; uiIndex < count; ++uiIndex)
    {
        if (prop->GetGeometryShaderObject(uiIndex) == map)
        {
            m_bShaderMap = true;
            m_uiMapIndex = uiIndex;
            NiFree(m_pcCtlrID);
            m_pcCtlrID = 0;
            if (!m_pkMap && m_pkTarget)
            {
                TexturePropertyLayout* p = (TexturePropertyLayout*)m_pkTarget;
                if (m_bShaderMap)
                {
                    NiTexturingProperty__Map* pMap = p->GetGeometryShaderObject(m_uiMapIndex);
                    m_pkMap = pMap;
                }
                else
                    m_pkMap = p->maps[m_uiMapIndex];
            }
            return;
        }
    }
}

// @fnv 0x00a46490
// pdb: NiTextureTransformController::Update | NiTextureTransformController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: UpdateData
void NiTextureTransformController::Update(NiUpdateData* data) throw()
{
    if (((unsigned char)(m_uFlags >> 5)) & 1)
        m_fScaledTime = DAT_01096324;
    else if (AdvanceController(data->fTime))
    {
        if (!m_spInterpolator.m_pObject || !m_spInterpolator.m_pObject->Unk_35())
            return;
    }
    if (!m_spInterpolator.m_pObject)
        return;
    float value;
    if (!m_spInterpolator.m_pObject->Unk_27(m_fScaledTime, m_pkTarget, value))
        return;
    if (!IsTextureMapValid())
        return;
    TextureMapTransform* transform = m_pkMap->transform;
    if (!transform)
    {
        void* memory = g_memoryManager.Allocate(sizeof(TextureMapTransform));
        transform = memory ? new (memory) TextureMapTransform(NiPoint2(0, 0), 0, NiPoint2(1, 1),
                                                             NiPoint2(DAT_01016248, DAT_01016248), 2)
                           : 0;
        m_pkMap->transform = transform;
    }
    switch (m_eMember)
    {
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_U: {
        NiPoint2 p = transform->m_kTranslate;
        p.x = value;
        transform->UpdateFromPair(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_TRANSLATE_V: {
        NiPoint2 p = transform->m_kTranslate;
        p.y = value;
        transform->UpdateFromPair(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_ROTATE:
        transform->SetValue(value);
        break;
    case NiTextureTransformController__TransformMember_TT_SCALE_U: {
        NiPoint2 p = transform->m_kScale;
        p.x = value;
        transform->FUN_00a462b0(p);
        break;
    }
    case NiTextureTransformController__TransformMember_TT_SCALE_V: {
        NiPoint2 p = transform->m_kScale;
        p.y = value;
        transform->FUN_00a462b0(p);
        break;
    }
    }
}

struct FUN_00a46480_shell : public NiTextureTransformController
{
    void* FUN_00a46480();
};

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f20;

// @fnv 0x00a46480
void* FUN_00a46480_shell::FUN_00a46480()
{
    return &g_011f3f20;
}

struct Target_00a46410
{
    unsigned char unk00[0xa];
    unsigned short unk0A;
};
struct FUN_00a46410_shell
{
    unsigned char unk00[0x2c];
    Target_00a46410* m_pkTarget;  // src: FNV360_PDB NiTimeController +0x2C (old: m_0x2c)
    unsigned int __thiscall FUN_00a46410();
};

// @fnv 0x00a46410
unsigned int __thiscall FUN_00a46410_shell::FUN_00a46410()
{
    Target_00a46410* p = m_pkTarget;
    if (!p)
        return 0;
    return p->unk0A;
}

struct FUN_00a461a0_shell : public NiTextureTransformController
{
    void __thiscall FUN_00a461a0(NiObjectNET* target);
};

// @fnv 0x00a461a0
// pdb: NiTextureTransformController::SetTarget | NiTextureTransformController.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: pkTarget
void __thiscall FUN_00a461a0_shell::FUN_00a461a0(NiObjectNET* target)
{
    if (m_pkTarget != target)
        m_pkMap = 0;
    NiTimeController::SetTarget(target);
}

bool __stdcall FUN_00a57c10(NiObject*);
struct FUN_00a461e0_shell : public NiTextureTransformController
{
    bool FUN_00a461e0(NiObject* pkObject);
};
// Returns true if pkObject passes FUN_00a57c10 and its four fields match the expected values.
// @fnv 0x00a461e0
// pdb: NiTextureTransformController::IsEqual | NiTextureTransformController.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: NiFlipController::IsEqual)
// pdb params: pkObject
bool FUN_00a461e0_shell::FUN_00a461e0(NiObject* pkObject)
{
    NiTextureTransformController* pkCtrl = (NiTextureTransformController*)pkObject;
    if (FUN_00a57c10(pkObject) && pkCtrl->m_uiLastIdx == m_uiLastIdx &&
        pkCtrl->m_bShaderMap == m_bShaderMap && pkCtrl->m_uiMapIndex == m_uiMapIndex &&
        pkCtrl->m_eMember == m_eMember)
        return true;
    return false;
}

struct S00a46220
{
    float m_f0;
    float m_f1;
    char m_auiShapeKeys[20];
    bool m_flag;
    void UpdateFromPair(float* p);
};
// Sets m_flag if it was already set or the two floats differ from p[0] and p[1], then copies both floats from p into m_f0 and m_f1.
// @fnv 0x00a46220
// pdb: NiTextureTransform::SetTranslate | NiTextureTransformController.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: kTranslate
void S00a46220::UpdateFromPair(float* afPair)
{
    m_flag = (m_flag || m_f0 != afPair[0] || m_f1 != afPair[1]);
    *(int*)&m_f0 = *(int*)afPair;
    *(int*)&m_f1 = *((int*)afPair + 1);
}

struct S462b0
{
    float x;
    float y;
};
struct C462b0
{
    char _00[12];
    S462b0 m_0c;
    char _14[8];
    bool m_1c;
    void __thiscall FUN_00a462b0(S462b0* p);
};
// Sets m_1c if the stored m_0c differs from p, then copies p into m_0c.
// @fnv 0x00a462b0
// pdb: NiTextureTransform::SetScale | NiTextureTransformController.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: kScale
void __thiscall C462b0::FUN_00a462b0(S462b0* p)
{
    m_1c = m_1c || m_0c.x != p->x || m_0c.y != p->y;
    m_0c = *p;
}

struct FUN_00a463e0_Inner
{
    unsigned int m_iWordAt00;
    void** m_iWordAt04;
    unsigned short m_8;
    unsigned short m_kPointA;
};
struct FUN_00a463e0_Holder
{
    unsigned char _pad[0x2c];
    FUN_00a463e0_Inner* m_2c;
    void* __thiscall GetElementAt(unsigned int);
};
// Returns the element at index from the array held by m_2c if it exists and index is below its count, otherwise returns 0.
// @fnv 0x00a463e0
void* __thiscall FUN_00a463e0_Holder::GetElementAt(unsigned int index)
{
    FUN_00a463e0_Inner* p = m_2c;
    if (p && index < p->m_kPointA)
        return p->m_iWordAt04[index];
    return 0;
}

struct CloningProcess;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiAlphaController
{
    void CopyMemberData(NiAlphaController*, CloningProcess&);
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
inline void __cdecl operator delete(void*, void*)
{}
struct FUN_00a468f0_shell : NiTextureTransformController
{
    NiTextureTransformController* __thiscall Clone(CloningProcess& kCloning);
};
// @fnv 0x00a468f0
// pdb: NiTextKeyExtraData::CreateClone | NiTextKeyExtraData.obj | fnv360_0822_debug, objrun_open, low
// pdb params: kCloning
NiTextureTransformController* __thiscall FUN_00a468f0_shell::Clone(CloningProcess& kCloning)
{
    NiTextureTransformController* pkObject;
    pkObject = (NiTextureTransformController*)BSFadeNode::operator new(0x50);
    if (pkObject)
        pkObject = new (pkObject) NiTextureTransformController(0, 0, (NiTextureTransformController__TransformMember)0);
    else
        pkObject = 0;
    ((NiAlphaController*)this)->CopyMemberData((NiAlphaController*)pkObject, kCloning);
    pkObject->m_uiLastIdx = m_uiLastIdx;
    pkObject->m_bShaderMap = m_bShaderMap;
    pkObject->m_uiMapIndex = m_uiMapIndex;
    pkObject->m_eMember = m_eMember;
    return pkObject;
}

struct StrArr
{
    unsigned char _00[8];
    unsigned short m_08;
    unsigned short m_0A;
    unsigned short _0C;
    unsigned short m_0E;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00a576c0(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Ensures pkStrings has room, then stores the string returned by _FUN_00a7d330 at index m_0A.
// @fnv 0x00a46ac0
void __stdcall FUN_00a46ac0(StrArr* pkStrings)
{
    FUN_00a576c0(pkStrings);
    char* pszString = _FUN_00a7d330(*(const char**)&g_011f3f20);
    unsigned int uiIndex = pkStrings->m_0A;
    if (uiIndex >= pkStrings->m_08)
        pkStrings->SetSize(uiIndex + pkStrings->m_0E);
    pkStrings->SetAt(uiIndex, pszString);
}

void __fastcall UpdateMatrix(void*);
struct NiNIFImageReader
{
    void* m_0x0;
    void* m_0x4;
    float m_0x8;
    void* m_0xc;
    void* m_0x10;
    void* m_0x14;
    void* m_0x18;
    void* m_0x1c;
    void* m_0x20;
    void* m_0x24;
    void* m_0x28;
    void* m_0x2c;
    void* m_0x30;
    void* m_0x34;
    void* m_0x38;
    void* m_0x3c;
    void* m_0x40;
    void* m_0x44;
    NiNIFImageReader* InitFromInputs(const NiNIFImageReader* s, float f, const NiNIFImageReader* t,
                                     const NiNIFImageReader* u, NiNIFImageReader* d);
};
// Copies two fields each from s, t and u, stores f and d, calls UpdateMatrix on this, and returns this.
// @fnv 0x00a88eb0
// pdb: NiTextureTransform::NiTextureTransform | NiTextureTransform.obj | fnv360_0822_retail, call_seq, medium
// pdb params: kTranslate, fRotate, kScale, kCenter, eMethod
NiNIFImageReader* NiNIFImageReader::InitFromInputs(const NiNIFImageReader* apSource, float afValue,
                                                   const NiNIFImageReader* apSecond, const NiNIFImageReader* apThird,
                                                   NiNIFImageReader* d)
{
    m_0x0 = apSource->m_0x0;
    m_0x4 = apSource->m_0x4;
    m_0x8 = afValue;
    m_0xc = apSecond->m_0x0;
    m_0x10 = apSecond->m_0x4;
    m_0x14 = apThird->m_0x0;
    m_0x18 = apThird->m_0x4;
    m_0x44 = d;
    UpdateMatrix(this);
    return this;
}

struct FUN_00a46660_shell : public NiTextureTransformController
{
    void GetTextureTransformValue(float& value);
};
// @fnv 0x00a46660
void FUN_00a46660_shell::GetTextureTransformValue(float& value)
{
    NiPoint2 kPoint;
    if (IsTextureMapValid())
    {
        TextureMapTransform* transform = m_pkMap->transform;
        if (!transform)
        {
            value = 0.0f;
            return;
        }
        switch (m_eMember)
        {
        case NiTextureTransformController__TransformMember_TT_TRANSLATE_U:
            kPoint = transform->m_kTranslate;
            value = kPoint.x;
            break;
        case NiTextureTransformController__TransformMember_TT_TRANSLATE_V:
            kPoint = transform->m_kTranslate;
            value = kPoint.y;
            break;
        case NiTextureTransformController__TransformMember_TT_ROTATE:
            value = transform->m_fRotate;
            break;
        case NiTextureTransformController__TransformMember_TT_SCALE_U:
            kPoint = transform->m_kScale;
            value = kPoint.x;
            break;
        case NiTextureTransformController__TransformMember_TT_SCALE_V:
            kPoint = transform->m_kScale;
            value = kPoint.y;
            break;
        }
    }
}

class FUN_00a46270_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    float m_f08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char m_b1C;
    void SetValue(float v);
};

// @fnv 0x00a46270
void FUN_00a46270_cls::SetValue(float afValue)
{
    int r;
    if (m_b1C == 0 && m_f08 == afValue)
    {
        r = 0;
    }
    else
    {
        r = 1;
    }
    m_f08 = afValue;
    m_b1C = r;
}

struct NiBinaryStreamW
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    char _08[4];
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamW* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
};

struct NiStreamStandInW
{
    char _000[0x250];
    NiBinaryStreamW* m_pBackingStream;
};

struct FUN_00a46a30_Cls
{
    char _00[0x40];
    unsigned char m_40;
    unsigned int m_44;
    unsigned int m_48;
    void __thiscall FUN_00a57c00(NiStreamStandInW* pkStream);
    void __thiscall WriteToStream(NiStreamStandInW* pkStream);
};

// @fnv 0x00a46a30
// pdb: NiTextureTransformController::SaveBinary | NiTextureTransformController.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: kStream
void __thiscall FUN_00a46a30_Cls::WriteToStream(NiStreamStandInW* pkStream)
{
    FUN_00a57c00(pkStream);
    unsigned char ucFlag = m_40;
    pkStream->m_pBackingStream->Write(&ucFlag);
    pkStream->m_pBackingStream->Write(&m_44);
    pkStream->m_pBackingStream->Write(&m_48);
}

void __cdecl FUN_00aa10f0(void* memory);
void __cdecl FUN_00aa1460(void* memory, unsigned int size);

struct InterpolationControllerBase
{
    virtual ~InterpolationControllerBase() throw();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30;
};

struct TextureTransformOwner : InterpolationControllerBase
{
    NiPointer<NiRefObject> interpolator;
    unsigned int unk38, unk3c, unk40, unk44, unk48;
    char* controllerID;
    virtual ~TextureTransformOwner() throw()
    {
        FUN_00aa10f0(controllerID);
        controllerID = 0;
    }
    void* FUN_00a46890(unsigned int flags);
    static void operator delete(void* memory, unsigned int size)
    {
        FUN_00aa1460(memory, size);
    }
};

// Destroys the object and, if the first bit of flags is set, frees its memory with FUN_00aa1460.
// @fnv 0x00a46890
// pdb: bhkBlendController::`scalar deleting destructor' | bhkBlendController.obj | fnv360_0822_retail, caller_sim, low
void* TextureTransformOwner::FUN_00a46890(unsigned int flags)
{
    this->TextureTransformOwner::~TextureTransformOwner();
    if (flags & 1)
        FUN_00aa1460(this, sizeof(TextureTransformOwner));
    return this;
}

struct S7 : NiTextureTransformController
{
    bool GetTaskMap();
};
// Returns true if m_pkMap is set, otherwise resolves it from the target TexturePropertyLayout and returns whether it was found.
// @fnv 0x00a46420
// pdb: NiTextureTransformController::SetInternalMap | NiTextureTransformController.obj | fnv360_0822_retail, call_gap, medium
bool S7::GetTaskMap()
{
    if (m_pkMap)
        return true;
    TexturePropertyLayout* p = reinterpret_cast<TexturePropertyLayout*>(m_pkTarget);
    if (!p)
        return false;
    if (m_bShaderMap)
        m_pkMap = p->GetGeometryShaderObject(m_uiMapIndex);
    else
        m_pkMap = p->maps[m_uiMapIndex];
    return m_pkMap ? true : false;
}

struct S00a46970_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S00a46970_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* pv, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pv, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T>
inline unsigned int S00a46970_BinaryStreamLoad(S00a46970_BinStream& istr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return istr.BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
struct S00a46970_Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiNifVersion;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00a46970_BinStream* m_pUnderlyingStream;
};
template <class T> inline void S00a46970_StreamLoadBinary(S00a46970_Stream& kStream, T& value)
{
    S00a46970_BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}
struct S00a46970_Base
{
    void FUN_00a57c70(S00a46970_Stream& kStream);
};
struct S00a46970_StreamFix
{
    void NiStream_ReadLinkID();
};
struct S00a46970_Ctlr : public NiTextureTransformController
{
    void FUN_00a46970(S00a46970_Stream& kStream);
};
// @fnv 0x00a46970
// pdb: NiTextureTransformController::LoadBinary | NiTextureTransformController.obj | fnv360_0822_retail, caller_sim, low
// pdb params: kStream
void S00a46970_Ctlr::FUN_00a46970(S00a46970_Stream& kStream)
{
    reinterpret_cast<S00a46970_Base*>(this)->FUN_00a57c70(kStream);
    bool bShaderMap;
    S00a46970_StreamLoadBinary(kStream, bShaderMap);
    m_bShaderMap = bShaderMap != 0;
    S00a46970_StreamLoadBinary(kStream, m_uiMapIndex);
    unsigned int uiMember;
    S00a46970_StreamLoadBinary(kStream, uiMember);
    m_eMember = (NiTextureTransformController__TransformMember)uiMember;
    if (kStream.m_uiNifVersion < 0x0a010068)
        reinterpret_cast<S00a46970_StreamFix*>(&kStream)->NiStream_ReadLinkID();
}

// @fnv 0x00a46950
NiTextureTransformController* __cdecl FUN_00a46950()
{
    void* storage = BSFadeNode::operator new(sizeof(NiTextureTransformController));
    if (storage != 0)
        return new (storage)
            NiTextureTransformController(0, 0, NiTextureTransformController__TransformMember_TT_TRANSLATE_U);
    return 0;
}
