#include "f3_common.h"
// src/gamebryo2.2/corelibs/nianimation/nimaterialcolorcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nimaterialcolorcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f88;

// @fnv 0x00a4b570
// pdb: bhkAabbPhantom::GetRTTI | TESObjectREFR.obj | fnv360_0822_retail, udata + bridge(vtable_prefix|vtable), high
void* __cdecl bhkAabbPhantom_GetRTTI()
{
    return &g_011f3f88;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

namespace fnv_00a4b880 {
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct GlobalObjectO2_00a7b610
{
    char const* m_str;
};
extern GlobalObjectO2_00a7b610 g_011f3f88;
void __stdcall FUN_00a57d10(StrArr*);
char* __cdecl FUN_00a7d330(char const*);

// Appends the string returned by FUN_00a7d330(g_011f3f88.m_str) to pkStrings, growing it when the length reaches the count.
// @fnv 0x00a4b880
// pdb: NiParticleMeshes::GetViewerStrings | NiParticleMeshes.obj | fnv360_0822_retail, caller_sim, low
// pdb params: pkStrings
void __stdcall FUN_00a4b880(StrArr* pkStrings)
{
    FUN_00a57d10(pkStrings);
    char* pStr = FUN_00a7d330(g_011f3f88.m_str);
    unsigned int len = *(unsigned short*)(pkStrings + 0xa);
    unsigned int cnt = *(unsigned short*)(pkStrings + 0x8);
    if (len >= cnt)
    {
        pkStrings->SetSize(*(unsigned short*)(pkStrings + 0xe) + len);
    }
    pkStrings->SetAt(len, pStr);
}
}  // namespace fnv_00a4b880

extern "C" void* g_01201f74;

// @fnv 0x00bc29d0
// pdb: NiInterpController::GetRTTI | NiInterpController.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00bc29d0()
{
    return &g_01201f74;
}

extern unsigned int DAT_011f4998;
extern unsigned int DAT_011f499c;
extern unsigned int DAT_011f49a0;
struct NiColorSource
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int embeddedR;
    unsigned int embeddedG;
    unsigned int embeddedB;
    unsigned int* color;
};
struct ColorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    NiColorSource* source;
    unsigned int unk30;
    unsigned int unk34;
    unsigned short mode;
    void GetColor(float* output);
};
// Selects an RGB color from global constants, source fields, or a color pointer based on mode, then writes the three floats into output.
// @fnv 0x00a4b3c0
void ColorHolder::GetColor(float* afOut)
{
    float red = 0.0f;
    float green = 0.0f;
    float blue = 0.0f;
    register unsigned int type = mode & 7;
    register NiColorSource* source = this->source;
    switch (type)
    {
    case 0:
    case 1:
        *(unsigned int*)&red = DAT_011f4998;
        *(unsigned int*)&green = DAT_011f499c;
        *(unsigned int*)&blue = DAT_011f49a0;
        break;
    case 2:
        *(unsigned int*)&red = source->r;
        *(unsigned int*)&green = source->g;
        *(unsigned int*)&blue = source->b;
        break;
    case 3: {
        unsigned int* selected = source->color ? source->color : &source->embeddedR;
        *(unsigned int*)&red = selected[0];
        *(unsigned int*)&green = selected[1];
        *(unsigned int*)&blue = selected[2];
        break;
    }
    }
    afOut[0] = red;
    afOut[1] = green;
    afOut[2] = blue;
}

struct NiPoint3InterpController
{
    unsigned short m_uiObjectFlags;
};

struct NiMaterialColorController : NiPoint3InterpController
{
    const char* GetChannelName();
};

// Returns the name string selected by the low 3 bits of the flags field at offset 0x38.
// @f3 0x008c5410 (community match, verified in this file)
namespace f3m_008c5410 {
struct ColorControllerView8c5410
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char channelFlags;
};
}

// pdb: NiMaterialColorController::GetCtlrID | NiMaterialColorController.obj | fnv360_0822_retail, ustr, medium
const char* NiMaterialColorController::GetChannelName()
{
    unsigned char flags = reinterpret_cast<f3m_008c5410::ColorControllerView8c5410*>(this)->channelFlags;
    switch (flags & 7)
    {
    case 0:
        return "AMB";
    case 1:
        return "DIFF";
    case 2:
        return "SPEC";
    case 3:
        return "SELF_ILLUM";
    default:
        return 0;
    }
}


#include <windows.h>
struct Source;

struct Thing
{
    virtual void v00();
    virtual void DeleteThis();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void Refresh();

    unsigned int m_uiRefCount;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;

    static void* operator new(unsigned int auiSize) throw();

    Thing(Source* apSource) throw();
};

struct ThingPtr
{
    Thing* m_pObject;

    ThingPtr& operator=(Thing* apObject)
    {
        Thing* pOld = m_pObject;
        if (pOld != apObject)
        {
            if (pOld)
            {
                if (InterlockedDecrement((LONG*)&pOld->m_uiRefCount) == 0)
                    pOld->DeleteThis();
            }
            m_pObject = apObject;
            if (apObject)
                InterlockedIncrement((LONG*)&apObject->m_uiRefCount);
        }
        return *this;
    }
};

namespace fnv_00a4b540 {
struct NiObject
{
    unsigned char mFlags[0x38];
};

struct NiMaterialColorController
{
    unsigned char mFlags[0x38];
    bool __thiscall FUN_00a57c10(NiObject*);
    bool __thiscall FUN_00a4b540(NiObject* pkObject);
};

// Returns true if pkObject passes FUN_00a57c10 and its mFlags[0x38] low 3 bits match this object's mFlags[0x38] low 3 bits.
// @fnv 0x00a4b540
// pdb: NiMaterialColorController::IsEqual | NiMaterialColorController.obj | fnv360_0822_retail, objrun, low
// pdb params: pkObject
bool __thiscall NiMaterialColorController::FUN_00a4b540(NiObject* pkObject)
{
    if (!FUN_00a57c10(pkObject))
        return false;
    return ((unsigned char)pkObject->mFlags[0x38] ^ (unsigned char)mFlags[0x38]) & 7 ? false : true;
}
}  // namespace fnv_00a4b540

extern const float DAT_01096324;

struct NiUpdateDataA4B5
{
    float m_fTime;
};

struct NiPoint3A4B5
{
    float x, y, z;
};

class NiColorA4B5
{
  public:
    __forceinline void Clamp()
    {
        if (r < 0.0f)
            r = 0.0f;
        else if (r > 1.0f)
            r = 1.0f;
        if (g < 0.0f)
            g = 0.0f;
        else if (g > 1.0f)
            g = 1.0f;
        if (b < 0.0f)
            b = 0.0f;
        else if (b > 1.0f)
            b = 1.0f;
    }
    float r, g, b;
};

class NiMaterialPropertyA4B5
{
  public:
    virtual void vfn_00();
    void SetAmbientColor(const NiColorA4B5&)
    {}
    void SetDiffuseColor(const NiColorA4B5&)
    {}
    void SetSpecularColor(const NiColorA4B5& kColor)
    {
        m_spec = kColor;
        m_uiRevID++;
    }
    void SetEmittance(const NiColorA4B5& kColor)
    {
        m_emit = kColor;
        m_uiRevID++;
    }
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    NiColorA4B5 m_spec;
    NiColorA4B5 m_emit;
    int unk34, unk38, unk3C, unk40;
    unsigned int m_uiRevID;
};

class NiPoint3InterpolatorA4B5
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
    virtual bool Update(float fTime, NiMaterialPropertyA4B5* pkInterpTarget, NiPoint3A4B5& kValue);
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual bool AlwaysUpdate() const;
};

class NiMaterialColorControllerA4B5
{
  public:
    enum MaterialColorChannel
    {
        AMB,
        DIFF,
        SPEC,
        SELF_ILLUM
    };

    virtual void vfn_00();
    bool NiTimeController_DontDoUpdate(float fTime);
    void FUN_00a4b580(NiUpdateDataA4B5& kUpdateData);

    bool GetManagerControlled() const
    {
        return (bool)((m_uiObjectFlags >> 5) & 1);
    }
    MaterialColorChannel GetType() const
    {
        return (MaterialColorChannel)(m_usMatFlags & 7);
    }

    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    unsigned short unk0A;
    float m_fFrequency, m_fPhase, m_fLoKeyTime, m_fHiKeyTime, m_fStartTime, m_fLastTime, m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiMaterialPropertyA4B5* m_pkTarget;
    void* m_spNextController;
    NiPoint3InterpolatorA4B5* m_spControllerInterpolator;
    unsigned short m_usMatFlags;
};

// Sets controller time for manager-controlled updates, then may evaluate the interpolator and update a material color channel.
// @f3 0x008c5520 (community match, verified in this file)
// pdb: NiMaterialColorController::Update | NiMaterialColorController.obj | fnv360_0721_retail, objrun, medium
// pdb params: UpdateData
void NiMaterialColorControllerA4B5::FUN_00a4b580(NiUpdateDataA4B5& kUpdateData)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (NiTimeController_DontDoUpdate(kUpdateData.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        NiPoint3A4B5 kValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, kValue))
        {
            NiMaterialPropertyA4B5* pkMat = m_pkTarget;
            NiColorA4B5 kColor;
            kColor.r = kValue.x;
            kColor.g = kValue.y;
            kColor.b = kValue.z;
            kColor.Clamp();
            switch (GetType())
            {
            case AMB:
                pkMat->SetAmbientColor(kColor);
                break;
            case DIFF:
                pkMat->SetDiffuseColor(kColor);
                break;
            case SPEC:
                pkMat->SetSpecularColor(kColor);
                break;
            case SELF_ILLUM:
                pkMat->SetEmittance(kColor);
                break;
            }
        }
    }
}


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace fnv_00a4b740 {
struct CloningProcess;
struct NiMaterialColorController
{
    char _pad[0x38];
    unsigned short m_uiObjectFlags;
    NiMaterialColorController* Clone(CloningProcess&);
};
}  // namespace fnv_00a4b740

struct StreamRecord
{
    unsigned int unknown00;
    unsigned int bytesRead;
    int(__cdecl* read)(StreamRecord*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    StreamRecord* record()
    {
        return *(StreamRecord**)((char*)this + 0x24c);
    }
    unsigned int version()
    {
        return *(unsigned int*)((char*)this + 0xd8);
    }
    unsigned short savedFlags()
    {
        return *(unsigned short*)((char*)this + 0x286);
    }
    void NiStream_ReadLinkID();
};
struct Stand840
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34;
    unsigned short selected;
    void Load(NiStream* stream);
};
// @f3 0x008c5760 (community match, verified in this file)
struct S0082b560_Stream
{
    void FUN_0082b560();
};
void __stdcall FUN_008d1870(NiStream*);
typedef unsigned int (__cdecl* ReadProcRef)(StreamRecord*, void*, unsigned int, const unsigned int&, unsigned int);
// pdb: NiMaterialColorController::LoadBinary | NiMaterialColorController.obj | fnv360_0822_retail, objrun_open, low
// pdb params: kStream
void Stand840::Load(NiStream* stream)
{
    FUN_008d1870(stream);
    if (stream->version() < 0x0a000102)
    {
        selected = (unsigned short)((stream->savedFlags() >> 5) & 0xff);
    }
    else
    {
        StreamRecord* record = stream->record();
        unsigned int uiBytesAdded = ((ReadProcRef)record->read)(record, &selected, 2u, 2u, 1u);
        record->bytesRead += uiBytesAdded;
    }
    if (stream->version() < 0x0a010068)
        ((S0082b560_Stream*)stream)->FUN_0082b560();
}


struct NiNode
{
    char _pad[0xAC];
    NiNode(unsigned short);
};
extern float DAT_010ba600;
extern int DAT_010ba608;
struct FUN_00bc2980 : NiNode
{
    unsigned char m_ac;
    unsigned char m_ad;
    float m_b0;
    float m_b4;
    FUN_00bc2980();
};
// Constructs a NiNode-derived object, sets m_b4 to 100.0f, m_b0 to DAT_010ba600, m_ad and m_ac to 0, and sets the vtable pointer to DAT_010ba608.
// @fnv 0x00bc2980
// pdb: BSClearZNode::BSClearZNode | BSClearZNode.obj | fnv360_0822_retail, call_gap_sim, high
FUN_00bc2980::FUN_00bc2980() : NiNode(0)
{
    m_b4 = 100.0f;
    *(void**)this = (void*)&DAT_010ba608;
    m_b0 = DAT_010ba600;
    m_ad = 0;
    m_ac = 0;
}

void __cdecl FUN_00a5ea70();

// @fnv 0x00bc29c0
// pdb: BSStripPSysData::RegisterStreamables | BSStripPSysData.obj | fnv360_0721_retail, objrun_prop, high
// pdb params: kStream
void __cdecl FUN_00bc29c0()
{
    FUN_00a5ea70();
}

namespace fnv_00bc29e0 {
// Placeholder declarations
struct NiMaterialColorController
{
    char _pad[0xb8];
    NiMaterialColorController* FUN_00bc29e0(int arg);
};
extern void __fastcall FUN_00a5e930(NiMaterialColorController*);
extern "C" void __cdecl __Dummy_00b6fef0(NiMaterialColorController*, int);
extern float DAT_010ba600;
extern void* DAT_010ba608;

// Initializes NiMaterialColorController fields, calls FUN_00a5e930, and optionally calls __Dummy_00b6fef0 if arg bit 0 is set.
// @fnv 0x00bc29e0
// pdb: BSClearZNode::`scalar deleting destructor' | BSClearZNode.obj | fnv360_0822_retail, objrun, medium
NiMaterialColorController* __thiscall NiMaterialColorController::FUN_00bc29e0(int aiFlags)
{
    ((float*)this)[0x2d] = 100.0f;
    ((float*)this)[0x2c] = DAT_010ba600;
    ((void**)this)[0] = &DAT_010ba608;
    ((unsigned char*)this)[0xad] = 0;
    ((unsigned char*)this)[0xac] = 0;
    FUN_00a5e930(this);
    if (aiFlags & 1)
        __Dummy_00b6fef0(this, 0xb8);
    return this;
}
}  // namespace fnv_00bc29e0
