// gamebryo2.2/corelibs/niparticle/nipsysemitter.cpp: NiPSysEmitter, Emitter (6 functions)
#include "f3_common.h"
#include "nipsysemitter_decls.h"
#include "nipsysemitter_types.h"
// @fnv 0x00c223b0
// pdb: NiPSysEmitter::LoadBinary | NiPSysEmitter.obj | fnv360_0822_retail, uconst, high
// pdb params: kStream
void NiPSysEmitter::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    ReadFloat(stream, m_fSpeed);
    ReadFloat(stream, m_fSpeedVar);
    ReadFloat(stream, m_fDeclination);
    ReadFloat(stream, m_fDeclinationVar);
    ReadFloat(stream, m_fPlanarAngle);
    ReadFloat(stream, m_fPlanarAngleVar);
    m_kInitialColor.LoadBinary(stream);
    ReadFloat(stream, m_fInitialRadius);
    if (stream.m_uiNifVersion >= 0x0A030002)
        ReadFloat(stream, m_fRadiusVar);
    ReadFloat(stream, m_fLifeSpan);
    ReadFloat(stream, m_fLifeSpanVar);
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);

struct FUN_00c220a0_shell
{
    void* __thiscall FUN_00c220a0(unsigned int flags);
};

// @fnv 0x00c220a0
void* __thiscall FUN_00c220a0_shell::FUN_00c220a0(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x54);
    return this;
}

// Equals: thiscall bool compare of two objects (float fields + sub-object)

class FUN_00c226a0_sub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    bool unk4a4c90(FUN_00c226a0_sub* other);
};

class FUN_00c226a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00c226a0_sub m_30;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    bool unk00c31830(FUN_00c226a0_cls* other);
    bool Equals(FUN_00c226a0_cls* other);
};

// @fnv 0x00c226a0
// pdb: NiPSysEmitter::IsEqual | NiPSysEmitter.obj | fnv360_0822_retail, call_seq, high
// pdb params: pkObject
bool FUN_00c226a0_cls::Equals(FUN_00c226a0_cls* other)
{
    if (unk00c31830(other) && other->m_18 == m_18 && other->m_1c == m_1c && other->m_20 == m_20 &&
        other->m_24 == m_24 && other->m_28 == m_28 && other->m_2c == m_2c && !other->m_30.unk4a4c90(&m_30) &&
        other->m_40 == m_40 && other->m_44 == m_44 && other->m_48 == m_48 && other->m_4c == m_4c)
        return true;
    return false;
}

// @fnv 0x00d070a0
// pdb: CombatController::ForceFlee | CombatController.obj | fnv360_0721_beta, call_dedup, low
// pdb params: apFleeFrom, abSwimFlee
void __stdcall FUN_00d070a0(int, int)
{}

extern int __cdecl FUN_00ecadb8();
extern unsigned short DAT_010be248;
extern float DAT_011aeae8;
extern float DAT_011f4ae0[];
extern float DAT_011f52e0[];
inline float RandomFloat0To1()
{
    return (float)(FUN_00ecadb8() / 32767.0);
}
inline float NiSymmetricRandom()
{
    return (float)(2.0 * FUN_00ecadb8() / 32767.0 - 1.0);
}
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator*(float fScalar) const
    {
        NiPoint3 kResult;
        kResult.x = x * fScalar;
        kResult.y = y * fScalar;
        kResult.z = z * fScalar;
        return kResult;
    }
};
struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fLifeSpan;
    float m_fZValue;
    unsigned short m_usFlags;
    unsigned short m_usFirstValue;
};
class NiPSysData
{
  public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual unsigned short GetParticleVertexCount();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPoint3* m_pkVertex;
    unsigned int unk24;
    NiColorA* m_pkColor;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    float* m_pfRadii;
    unsigned int unk50;
    float* m_pfSizes;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char* m_pucTexIndex;
    unsigned int unk68;
    unsigned char m_ucTexCount;
    unsigned char unk6d;
    unsigned short unk6e;
    Point3ParameterData* m_pkParticleInfo;
};
class NiParticleSystem
{
  public:
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    NiPSysData* m_spGeometryData;
    void FUN_00c1aee0(unsigned short usParticle);
};
class Emitter : public NiPSysEmitter
{
  public:
    virtual void ComputeInitialPositionAndVelocity(NiPoint3& kPosition, NiPoint3& kMotionVelocity);
    void NiPSysEmitter_EmitParticles(float fTime, unsigned short usNumParticles, const float* afAges);
};
inline float NiFastSin(float fAngleDifference)
{
    return DAT_011f52e0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
inline float NiFastCos(float fAngleDifference)
{
    return DAT_011f4ae0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
// @fnv 0x00c220c0
// pdb: NiPSysEmitter::EmitParticles | NiPSysEmitter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(udata), high
void Emitter::NiPSysEmitter_EmitParticles(float fTime, unsigned short usNumParticles, const float* afAges)
{
    NiPSysData* pkData = m_pkTarget->m_spGeometryData;
    NiPoint3* pkVertex = pkData->m_pkVertex;
    NiColorA* pkColor = pkData->m_pkColor;
    float* pfRadii = pkData->m_pfRadii;
    float* pfSizes = pkData->m_pfSizes;
    unsigned char* pucTex = pkData->m_pucTexIndex;
    unsigned char ucTexCount = pkData->m_ucTexCount;
    for (unsigned short us = 0; us < usNumParticles; us++)
    {
        float m_fFirstFloatValue = afAges[us];
        float fLifeSpan = m_fLifeSpan + (RandomFloat0To1() - 0.5) * m_fLifeSpanVar;
        if (m_fFirstFloatValue > fLifeSpan)
            continue;
        unsigned short usNew = pkData->GetParticleVertexCount();
        if (usNew == DAT_010be248)
            break;
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[usNew];
        float fSpeed = m_fSpeed + (RandomFloat0To1() - 0.5) * m_fSpeedVar;
        float fDec = m_fDeclination + m_fDeclinationVar * NiSymmetricRandom();
        float fPlanar = m_fPlanarAngle + m_fPlanarAngleVar * NiSymmetricRandom();
        float fSinDec = NiFastSin(fDec);
        NiPoint3 kWorldPosition(NiFastCos(fPlanar) * fSinDec, fSinDec * NiFastSin(fPlanar), NiFastCos(fDec));
        pkInfo->m_kValue = kWorldPosition * fSpeed;
        pkInfo->m_fXValue = m_fFirstFloatValue;
        pkInfo->m_fLifeSpan = fLifeSpan;
        pkInfo->m_usFlags = 0;
        ComputeInitialPositionAndVelocity(pkVertex[usNew], pkInfo->m_kValue);
        if (pkColor)
            pkColor[usNew] = m_kInitialColor;
        if (pfRadii)
            pfRadii[usNew] = (m_fInitialRadius + m_fRadiusVar * NiSymmetricRandom()) * m_fScale;
        if (pfSizes)
            pfSizes[usNew] = 1.0f;
        if (pucTex)
            pucTex[usNew] = FUN_00ecadb8() % ucTexCount;
        pkInfo->m_fZValue = fTime - pkInfo->m_fXValue;
        m_pkTarget->FUN_00c1aee0(usNew);
    }
}

char* __cdecl FUN_00a5b690(const char* pcString);

extern char* g_pcC21FE0NullString;

class BC21FE0FixedString
{
  public:
    BC21FE0FixedString(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = g_pcC21FE0NullString;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }

    ~BC21FE0FixedString()
    {
        if (m_kHandle != g_pcC21FE0NullString)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }

    char* m_kHandle;
};

struct EmitterColorWriter
{
    void NiColorA_SaveBinary(NiStream& stream);
};
struct S_00c22530_BinaryStream : NiBinaryStream
{
    unsigned int(__cdecl* m_readElement)(S_00c22530_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct S_00c22530_Stream : NiStream
{
    S_00c22530_BinaryStream* m_pStreamReader;
};
inline void S_00c22530_BinaryRead(S_00c22530_BinaryStream* b, void* p)
{
    unsigned int size = 4;
    unsigned int got = b->m_readElement(b, p, 4, &size, 1);
    b->m_uiStreamFlags += got;
}
inline void S_00c22530_ReadFloat(S_00c22530_Stream& s, float& f)
{
    S_00c22530_BinaryRead(s.m_pStreamReader, &f);
}
struct S_00c22530_Emitter : NiPSysEmitter
{
    void FUN_00c31950(NiStream& stream);
    void NiPSysEmitter_SaveBinary(S_00c22530_Stream& stream);
};
// Calls FUN_00c31950, then reads emitter fields and particle color from the stream.
// @fnv 0x00c22530
// pdb: NiPSysEmitter::SaveBinary | NiPSysEmitter.obj | fnv360_0822_retail, call_seq + bridge(vtable|caller_sim) + skyrim(caller_sim), high
void S_00c22530_Emitter::NiPSysEmitter_SaveBinary(S_00c22530_Stream& stream)
{
    FUN_00c31950(stream);
    S_00c22530_ReadFloat(stream, m_fSpeed);
    S_00c22530_ReadFloat(stream, m_fSpeedVar);
    S_00c22530_ReadFloat(stream, m_fDeclination);
    S_00c22530_ReadFloat(stream, m_fDeclinationVar);
    S_00c22530_ReadFloat(stream, m_fPlanarAngle);
    S_00c22530_ReadFloat(stream, m_fPlanarAngleVar);
    reinterpret_cast<EmitterColorWriter*>(&m_kInitialColor)->NiColorA_SaveBinary(stream);
    S_00c22530_ReadFloat(stream, m_fInitialRadius);
    S_00c22530_ReadFloat(stream, m_fRadiusVar);
    S_00c22530_ReadFloat(stream, m_fLifeSpan);
    S_00c22530_ReadFloat(stream, m_fLifeSpanVar);
}
