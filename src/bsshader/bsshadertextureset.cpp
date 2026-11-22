// bsshader/bsshadertextureset.cpp: BipedAnim, BSShaderTextureSet (8 functions)
#include "f3_common.h"
#include "bsshadertextureset_types_BIPED_BONE.h"
#include "bsshadertextureset_types_BipedAnim.h"
#include "bsshadertextureset_types_NiTexture.h"
#include "bsshadertextureset_types_NiStream.h"
#include "bsshadertextureset_stream.h"
#include "bsshadertextureset_decls.h"
#include "bsshadertextureset_types_BSShaderManager.h"
#include "bsshadertextureset_types_BSShaderTextureSet.h"

// @fnv 0x004ab230
#pragma optimize("", off)
#pragma optimize("y", off)
#pragma optimize("y", on)
#pragma optimize("", on)

// Looks up the texture name for a texture type, resolves it via BSShaderManager::GetTexture, and assigns it to textureOut with refcount handling.
// @fnv 0x00ba87f0
// pdb: BSShaderTextureSet::GetTexture | BSShaderTextureSet.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiType, aspTexture
void BSShaderTextureSet::GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& textureOut) const
{
    NiPointer<NiTexture> texture;
    register const char* textureName = GetTextureFilename(textureType);
    if (textureName)
        BSShaderManager::GetTexture(textureName, true, texture, true, textureType == BSShaderProperty::TEXTYPE_ENV);
    if (textureOut.m_pObject != texture.m_pObject)
    {
        NiTexture* previous = textureOut.m_pObject;
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        textureOut.m_pObject = texture.m_pObject;
        if (texture.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&texture.m_pObject->m_uiRefCount));
    }
}

struct FUN_00ba88d0_shell : public BSShaderTextureSet
{
    void LoadTextureSet(NiStream*);
};

// @fnv 0x00ba88d0
// pdb: BSShaderTextureSet::LoadBinary | BSShaderTextureSet.obj | fnv360_0822_retail, vtable, medium
// pdb params: kStream
void FUN_00ba88d0_shell::LoadTextureSet(NiStream* kStream)
{
    BSTextureSet::LoadBinary(*kStream);
    int count = 0;
    char* pcstring = 0;
    NiBinaryStream* pkStream = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(kStream) + 0x24c);
    {
        unsigned int uiBytesRead = 4;
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pkStream) + 4) +=
            (*reinterpret_cast<unsigned int(__cdecl**)(NiBinaryStream*, void*, unsigned int, unsigned int*,
                                                       unsigned int)>(reinterpret_cast<char*>(pkStream) + 8))(
                pkStream, &count, 4, &uiBytesRead, 1);
    }
    for (int i = 0; i < count; ++i)
    {
        kStream->ReadStreamString(pcstring);
        if (i >= 0)
        {
            reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 8)[i].Set(pcstring, 0);
        }
        NiFree(pcstring);
        pcstring = 0;
    }
}

struct FUN_00ba89e0_shell : public BSShaderTextureSet
{
    void FUN_00ba89e0(int, char*);
};

// @fnv 0x00ba89e0
// pdb: BSShaderTextureSet::SetTextureFilename | BSShaderTextureSet.obj | fnv360_0822_retail, vtable, low, conflict (skyrim: BSShaderTextureSet::LinkObject)
// pdb params: aiType, apFilename
void FUN_00ba89e0_shell::FUN_00ba89e0(int aiType, char* apFilename)
{
    reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 8)[aiType].Set(apFilename, 0);
}

// @fnv 0x00ba87e0
// pdb: BipedAnim::GetParentBone | BipedAnim.obj | fnv360_0822_retail, vtable, medium
// pdb params: aeType
int __fastcall FUN_00ba87e0(int* self, int unused, int index)
{
    return self[index * 2 + 2];
}

void __cdecl _MyHelper00a5d2f0(int a);
// @fnv 0x00a81fe0
// pdb: BGSMoviePlayer::UnPauseMusic | BGSMoviePlayer.obj | fnv360_0822_retail, objrun, medium
void __cdecl FUN_00a81fe0(int a)
{
    _MyHelper00a5d2f0(a);
}

void FUN_00a89af0();

// @fnv 0x00a724d0
// pdb: ValueModifierEffect::LoadGame | AbsorbEffect.obj | fnv360_0721_retail, vtable, medium
// pdb params: apActor
void FUN_00a724d0()
{
    FUN_00a89af0();
}

template <class T> inline void NiStreamSaveBinaryBA89(NiBinaryStream* pkStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStream->m_uiStreamFlags += pkStream->m_pfnWrite(pkStream, &value, sizeof(T), &uiSize, 1);
}

class BSShaderTextureSetBA89 : public BSShaderTextureSet
{
  public:
    void BSShaderTextureSet_SaveBinary(NiStream& stream);
};

// Links the object into the stream, writes the texture count 6, and writes each of the six m_kTextureNames strings to the stream.
// @fnv 0x00ba8970
// pdb: BSShaderTextureSet::SaveBinary | BSShaderTextureSet.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(caller_sim), high
void BSShaderTextureSetBA89::BSShaderTextureSet_SaveBinary(NiStream& stream)
{
    ((NiObjectCall*)this)->NiObjectCall::LinkObject(stream);

    unsigned int uiTextureCount = 6;
    NiStreamSaveBinaryBA89(stream.m_pBackingStream, uiTextureCount);

    for (int i = 0; i < 6; i++)
        stream.WriteStreamString(m_kTextureNames[i].pString);
}
