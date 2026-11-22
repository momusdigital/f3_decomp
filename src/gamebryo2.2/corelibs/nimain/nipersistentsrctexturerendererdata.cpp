#include "f3_common.h"
// src/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiObject
{
};

struct NiStream
{
    static void __cdecl UnregisterObjectLoader(char const*);
    static int __cdecl RegisterObjectLoader(char const*, NiObject*(__cdecl*)(void));
};

extern char const* const DAT_0109f0a0;
NiObject* __cdecl FUN_00a982d0();

// @fnv 0x00a98460
// pdb: NiPersistentSrcTextureRendererData::ResetStreamingFunctions | NiPersistentSrcTextureRendererData.obj | fnv360_0822_debug, caller_sim, low
void __cdecl RegisterNiStreamFactory()
{
    NiStream::UnregisterObjectLoader((char const*)&DAT_0109f0a0);
    NiStream::RegisterObjectLoader((char const*)&DAT_0109f0a0, FUN_00a982d0);
}

extern "C" void __cdecl _NiFreeAlias(void*);

struct NiPersistentSrcTextureRendererData
{
    char pad[0x60];
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    void FreePixelData();
};

// Frees m_pucPixels and clears the pixel pointer, width, height and offset fields.
// @fnv 0x00a980e0
// pdb: NiPersistentSrcTextureRendererData::FreeData | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, objrun_open, low
void NiPersistentSrcTextureRendererData::FreePixelData()
{
    if (m_pucPixels)
    {
        _NiFreeAlias(m_pucPixels);
        m_puiOffsetInBytes = 0;
        m_puiHeight = 0;
        m_puiWidth = 0;
        m_pucPixels = 0;
    }
}

namespace fnv_00a98110 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiObjectHelper
{
    virtual void LinkObject(NiStream&);
};
struct NiStreamHelper
{
    NiObject* GetLoadedObject();
};
struct NiPalette
{
    virtual ~NiPalette();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct NiPersistentSrcTextureRendererData
{
    char _pad[0x90];
    NiPalette* m_spPalette;
    void LinkPalette(NiStream&);
};
// Links the object to the stream, then swaps m_spPalette to the stream's palette, releasing the old one and incrementing the new one's refcount.
// @fnv 0x00a98110
// pdb: NiPersistentSrcTextureRendererData::LinkObject | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: kStream
void NiPersistentSrcTextureRendererData::LinkPalette(NiStream& kStream)
{
    ((NiObjectHelper*)this)->NiObjectHelper::LinkObject(kStream);
    NiPalette* pkPalette = (NiPalette*)((NiStreamHelper*)&kStream)->GetLoadedObject();
    NiPalette* pkOld = m_spPalette;
    if (pkOld != pkPalette)
    {
        if (pkOld && InterlockedDecrement((long volatile*)&pkOld->m_iObjectReferenceCount) == 0)
            pkOld->DeleteThis();
        m_spPalette = pkPalette;
        if (pkPalette)
            InterlockedIncrement((long volatile*)&pkPalette->m_iObjectReferenceCount);
    }
}
}  // namespace fnv_00a98110

namespace fnv_00a98170 {
struct NiObjectHelper
{
    bool RegisterStreamables(NiStream&);
};
struct PaletteHelper
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual bool RegisterStreamables(NiStream&);
};
struct NiPersistentSrcTextureRendererData
{
    char _pad0[0x90];
    PaletteHelper* m_spPalette;
    bool FUN_00a98170(NiStream&);
};
// Registers the object's streamables with kStream, then registers m_spPalette's streamables if it is set; returns false on failure.
// @fnv 0x00a98170
// pdb: NiPersistentSrcTextureRendererData::RegisterStreamables | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: kStream
bool NiPersistentSrcTextureRendererData::FUN_00a98170(NiStream& kStream)
{
    if (!((NiObjectHelper*)this)->NiObjectHelper::RegisterStreamables(kStream))
        return false;
    PaletteHelper* pkPalette = m_spPalette;
    if (pkPalette)
        pkPalette->RegisterStreamables(kStream);
    return true;
}
}  // namespace fnv_00a98170

void __cdecl FUN_00a98240();
void __cdecl _delete(void*, unsigned int);
struct S
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a98240, then deletes this with size 0x94 when f has bit 0 set, and returns this.
// @fnv 0x00a98480
// pdb: NiPersistentSrcTextureRendererData::`vector deleting destructor' | NiPersistentSrcTextureRendererData.obj | tesv_win, vtable_prefix, medium
void* S::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00a98240();
    if (auiFlags & 1)
        _delete(this, 0x94);
    return this;
}

extern bool DAT_011f5f00;
struct NiBinaryStream_s
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream_s*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream_s*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 1;
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T>
inline unsigned int NiBinaryStreamSave_s(NiBinaryStream_s& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
inline NiBinaryStream_s* Ostr_s(NiStream& kStream)
{
    return *(NiBinaryStream_s**)((char*)&kStream + 0x250);
}
template <class T> inline void NiStreamSaveBinary_s(NiStream& kStream, const T& tValue)
{
    NiBinaryStreamSave_s(*Ostr_s(kStream), &tValue, 1);
}
template <class T> inline void NiStreamSaveBinary_s(NiStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    NiBinaryStreamSave_s(*Ostr_s(kStream), pValue, uiNumEls);
}
struct NiStreamV_s
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void SaveLinkID(void*);
};
struct NiPixelFormat_s
{
    void NiPixelFormat_SaveBinary(NiStream&);
};
struct RendererDataBase_s
{
    void LinkObject(NiStream&);
};
struct NiPersistentSrcTextureRendererData_s : RendererDataBase_s
{
    char pad[0x14];
    NiPixelFormat_s m_kPixelFormat;
    char pad2[0x60 - 0x15];
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiPixelDataSize;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiFaces;
    int m_iPaletteFormat;
    unsigned char* m_pucPaletteData;
    unsigned int m_uiPaletteSize;
    unsigned int m_uiPaletteEntryCount;
    void* m_spPalette;
    void NiPersistentSrcTextureRendererData_SaveBinary(NiStream& kStream);
};

// Writes the renderer data to the stream: pixel format, palette link ID, mipmap levels, per-level dimensions and offsets, faces, and pixel data.
// @fnv 0x00a984b0
// pdb: NiPersistentSrcTextureRendererData::SaveBinary | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, udata + bridge(vtable|udata) + skyrim(udata), high
void NiPersistentSrcTextureRendererData_s::NiPersistentSrcTextureRendererData_SaveBinary(NiStream& kStream)
{
    RendererDataBase_s::LinkObject(kStream);

    bool bToolModeStreamingValid = DAT_011f5f00 && m_uiPaletteSize && m_uiPaletteEntryCount && m_pucPaletteData;

    m_kPixelFormat.NiPixelFormat_SaveBinary(kStream);
    ((NiStreamV_s*)&kStream)->SaveLinkID(m_spPalette);
    NiStreamSaveBinary_s(kStream, m_uiMipmapLevels);
    NiStreamSaveBinary_s(kStream, m_uiPixelStride);

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        NiStreamSaveBinary_s(kStream, m_puiWidth[i]);
        NiStreamSaveBinary_s(kStream, m_puiHeight[i]);
        NiStreamSaveBinary_s(kStream, m_puiOffsetInBytes[i]);
    }

    if (bToolModeStreamingValid)
    {
        NiStreamSaveBinary_s(kStream, m_uiPaletteSize);
        NiStreamSaveBinary_s(kStream, m_uiPaletteEntryCount);
    }
    else
    {
        NiStreamSaveBinary_s(kStream, m_puiOffsetInBytes[m_uiMipmapLevels]);
        NiStreamSaveBinary_s(kStream, m_uiPixelDataSize);
    }

    NiStreamSaveBinary_s(kStream, m_uiFaces);
    NiStreamSaveBinary_s(kStream, m_iPaletteFormat);

    if (bToolModeStreamingValid)
        NiStreamSaveBinary_s(kStream, m_pucPaletteData, m_uiPaletteSize * m_uiFaces);
    else
        NiStreamSaveBinary_s(kStream, m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces);
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiObj_s
{
  public:
    virtual void v00();
    virtual void v01();
    virtual const NiRTTI* GetRTTI() const;
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsEqual(NiObj_s* pkObject);
    unsigned int m_uiRefCount;
};

class NiPixFmt_s
{
  public:
    bool operator!=(const NiPixFmt_s& kFormat) const;
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
};

struct NiPtr_s
{
    NiObj_s* m_pObject;
    operator NiObj_s*() const
    {
        return m_pObject;
    }
    NiObj_s* operator->() const
    {
        return m_pObject;
    }
};

class PSTRData_s : public NiObj_s
{
  public:
    static NiRTTI ms_kRTTI;
    bool FUN_00a982f0(NiObj_s* pkObject);

    int unk08;
    int unk0C;
    int unk10;
    NiPixFmt_s m_kPixelFormat;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiPixelDataSize;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiFaces;
    int m_iPaletteFormat;
    unsigned char* m_pucPaletteData;
    unsigned int m_uiPaletteSize;
    unsigned int m_uiPaletteEntryCount;
    NiPtr_s m_spPalette;
};

inline bool IsKindOf_s(const NiRTTI* pkRTTI, NiObj_s* pkObject)
{
    if (!pkObject)
        return false;
    const NiRTTI* p = pkObject->GetRTTI();
    while (p)
    {
        if (p == pkRTTI)
            return true;
        p = p->m_pBaseRTTI;
    }
    return false;
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

// @fnv 0x00a982f0
// pdb: NiPersistentSrcTextureRendererData::IsEqual | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: pkObject
bool PSTRData_s::FUN_00a982f0(NiObj_s* pkObject)
{
    if (!IsKindOf_s(&ms_kRTTI, pkObject))
        return false;

    if (!NiObj_s::IsEqual(pkObject))
        return false;

    PSTRData_s* pkData = (PSTRData_s*)pkObject;

    if (m_kPixelFormat != pkData->m_kPixelFormat)
        return false;

    if (m_spPalette)
    {
        if (!m_spPalette->IsEqual(pkData->m_spPalette))
            return false;
    }

    if (m_uiMipmapLevels != pkData->m_uiMipmapLevels || m_uiPixelStride != pkData->m_uiPixelStride)
        return false;

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        if (m_puiWidth[i] != pkData->m_puiWidth[i] || m_puiHeight[i] != pkData->m_puiHeight[i] ||
            m_puiOffsetInBytes[i] != pkData->m_puiOffsetInBytes[i])
            return false;
    }

    if (m_puiOffsetInBytes[m_uiMipmapLevels] != pkData->m_puiOffsetInBytes[m_uiMipmapLevels])
        return false;
    if (m_uiPixelDataSize != pkData->m_uiPixelDataSize)
        return false;
    if (m_uiFaces != pkData->m_uiFaces)
        return false;
    if (m_iPaletteFormat != pkData->m_iPaletteFormat)
        return false;

    if (memcmp(m_pucPixels, pkData->m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels]) != 0)
        return false;

    return true;
}

struct ViewerArray
{
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short used;
    unsigned short grow;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char* const*);
    void FUN_0096a610(char* const*);
    void SetAtGrow(unsigned int index, char* const& value)
    {
        if (index >= capacity)
            FUN_0096ad30(index + grow);
        FUN_0096ae90(index, &value);
    }
    unsigned int Add(char* const& value)
    {
        unsigned int index = size;
        SetAtGrow(index, value);
        return index;
    }
};
struct ViewerBase
{
    void AppendCameraPathEntries(ViewerArray*);
};
char* __cdecl FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d510(const char*, unsigned int);
char* __cdecl FUN_00a7d5e0(const char*, const char*);
extern const char* DAT_011f5f04;
struct ViewerData : PSTRData_s
{
    unsigned int GetWidth(unsigned int level = 0) const
    {
        return m_puiWidth[level];
    }
    unsigned int GetHeight(unsigned int level = 0) const
    {
        return m_puiHeight[level];
    }
    const unsigned int& GetMipmapLevels() const
    {
        return m_uiMipmapLevels;
    }
    const unsigned int& GetFaces() const
    {
        return m_uiFaces;
    }
    unsigned int GetTotalSizeInBytes() const
    {
        return m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces;
    }
    unsigned int GetFaceSizeInBytes() const
    {
        return m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    void AppendToStrings(ViewerArray*);
};
// Appends the texture's width, height, mipmap levels, faces, sizes and a target-platform string to the given string array.
// @f3 0x00862990 (community match, verified in this file)
// pdb: NiPersistentSrcTextureRendererData::GetViewerStrings | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, ustr, medium
// pdb params: pkStrings
void ViewerData::AppendToStrings(ViewerArray* strings)
{
    ((ViewerBase*)this)->AppendCameraPathEntries(strings);
    char* value = FUN_00a7d330(DAT_011f5f04);
    strings->Add(value);
    value = FUN_00a7d510("Width", GetWidth());
    strings->Add(value);
    value = FUN_00a7d510("Height", GetHeight());
    strings->Add(value);
    value = FUN_00a7d510("MipmapLevels", GetMipmapLevels());
    strings->Add(value);
    value = FUN_00a7d510("Faces", GetFaces());
    strings->Add(value);
    value = FUN_00a7d510("TotalSizeInBytes", GetTotalSizeInBytes());
    strings->Add(value);
    value = FUN_00a7d510("FaceSizeInBytes", GetFaceSizeInBytes());
    strings->Add(value);
    switch (m_iPaletteFormat)
    {
    case 0: {
        value = FUN_00a7d5e0("TargetPlatform", "NI_ANY - Generic (default)");
        strings->FUN_0096a610(&value);
        break;
    }
    case 3: {
        value = FUN_00a7d5e0("TargetPlatform", "NI_DX9");
        strings->FUN_0096a610(&value);
        break;
    }
    case 1: {
        value = FUN_00a7d5e0("TargetPlatform", "NI_XENON");
        strings->FUN_0096a610(&value);
        break;
    }
    case 2: {
        value = FUN_00a7d5e0("TargetPlatform", "NI_PS3");
        strings->FUN_0096a610(&value);
        break;
    }
    default:
        value = FUN_00a7d5e0("TargetPlatform", "UNKNOWN!");
        strings->Add(value);
        break;
    }
}


struct Input
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(Input*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int ReadBytes(void* data, unsigned int bytes)
    {
        unsigned int size = 1;
        unsigned int result = read(this, data, bytes, &size, 1);
        position += result;
        return result;
    }
    unsigned int Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int result = read(this, data, bytes, sizes, count);
        position += result;
        return result;
    }
};
struct LoadStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Input* input;
    void Resolve();
};
template <class T> inline unsigned int BinaryLoad(Input& input, T* value, unsigned int count)
{
    unsigned int size = sizeof(T);
    return input.Read(value, count * size, &size, 1);
}
template <class T> inline void Load(LoadStream& stream, T& value)
{
    BinaryLoad(*stream.input, &value, 1);
}
struct PixelFormatLoad
{
    void LoadFormat(LoadStream&);
};
struct TextureLoad
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void Allocate(unsigned int, unsigned int, unsigned int);
    unsigned int unk04, unk08, unk0c, unk10;
    PixelFormatLoad format;
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
    unsigned char* pixels;
    unsigned int* width;
    unsigned int* height;
    unsigned int* offsets;
    unsigned int padOffset, levels, stride, faces, target;
    unsigned char* pristine;
    unsigned int pristineMax, pristinePad;
    void LoadBase(LoadStream&);
    void LoadTextureData(LoadStream&);
};
extern bool DAT_011f5f00;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memcpy(void*, const void*, unsigned int);
// @fnv 0x00e917e0
// pdb: NiXenonPersistentSrcTextureRendererData::LoadBinary | NiXenonPersistentSrcTextureRendererData.obj | fnv360_0822_retail, uconst, high
// pdb params: kStream
void TextureLoad::LoadTextureData(LoadStream& stream)
{
    LoadBase(stream);
    format.LoadFormat(stream);
    stream.Resolve();
    Load(stream, levels);
    Load(stream, stride);
    unsigned int widths[16], heights[16], mipOffsets[16];
    for (unsigned int level = 0; level < levels; ++level)
    {
        Load(stream, widths[level]);
        Load(stream, heights[level]);
        Load(stream, mipOffsets[level]);
    }
    Load(stream, mipOffsets[levels]);
    if (stream.unk0d8 >= 0x14020006)
    {
        padOffset = 0;
        Load(stream, padOffset);
    }
    else
        padOffset = mipOffsets[levels];
    Load(stream, faces);
    {
        int platform;
        Load(stream, platform);
        target = platform;
    }
    Allocate(levels, faces, mipOffsets[levels]);
    unsigned int bytesPerLevel = levels * 4;
    memcpy(width, widths, bytesPerLevel);
    memcpy(height, heights, bytesPerLevel);
    memcpy(offsets, mipOffsets, (levels + 1) * 4);
    stream.input->ReadBytes(pixels, offsets[levels] * faces);
    if (DAT_011f5f00)
    {
        pristineMax = offsets[levels];
        pristinePad = padOffset;
        unsigned int bytes = pristineMax * faces;
        pristine = (unsigned char*)NiMalloc(bytes);
        memcpy(pristine, pixels, bytes);
    }
}

namespace fnv_00e75a70 {
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(volatile long*) throw();
extern "C" void __cdecl _NiFreeAlias(void*) throw();
inline void NiFree(void* p) throw()
{
    _NiFreeAlias(p);
}

void __cdecl RegisterNiStreamFactory() throw();

struct NiRefObject
{
    virtual void Unknown() throw();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    void Release() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer() throw()
    {
        T* object = m_pObject;
        if (object)
        {
            if (InterlockedDecrement(&object->m_uiRefCount) == 0)
            {
                object->DeleteThis();
            }
        }
    }
    operator T*() const throw()
    {
        return m_pObject;
    }
    T* operator->() const throw()
    {
        return m_pObject;
    }
};

template <class T> struct NiPointerArray4
{
    T* m_iWordAt00;
    T* m_cByteAtOffset1;
    T* m_cByteAtOffset2;
    T* m_cByteAtOffset3;
    __forceinline ~NiPointerArray4() throw()
    {
        T** p = &m_cByteAtOffset3 + 1;
        for (int i = 3; i >= 0; --i)
        {
            T* obj = *--p;
            if (obj)
            {
                if (InterlockedDecrement(&obj->m_uiRefCount) == 0)
                    obj->DeleteThis();
            }
        }
    }
    operator T**() throw()
    {
        return &m_iWordAt00;
    }
};

struct NiTMapItem
{
    NiTMapItem* m_pkNext;
    unsigned int m_key;
    void* m_val;
};

template <class Alloc, class Key, class Val> struct NiTMapBase
{
    virtual ~NiTMapBase() throw()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(Key key) const throw();
    void RemoveAll() throw();
    void RemoveAt(Key key) throw();
    void InsertOrUpdate(Key key, void* val) throw();

    void* GetFirstPos() const throw()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(void*& pos, Key& key, Val& val) throw()
    {
        NiTMapItem* pItem = (NiTMapItem*)pos;
        void* next = pItem->m_pkNext;
        key = (Key)pItem->m_key;
        val = (Val)pItem->m_val;
        if (next)
        {
            pos = next;
            return;
        }
        unsigned int i = KeyToHashIndex((Key)pItem->m_key);
        for (i++; i < m_uiHashSize; i++)
        {
            NiTMapItem* found = m_ppkHashTable[i];
            if (found)
            {
                pos = found;
                return;
            }
        }
        pos = 0;
    }

    unsigned int m_uiHashSize;
    NiTMapItem** m_ppkHashTable;
    unsigned int m_uiCount;
};

template <class Key, class Val> struct NiTPointerMap : public NiTMapBase<void, Key, Val>
{
    virtual ~NiTPointerMap() throw()
    {
        this->RemoveAll();
    }
};

struct CachedGeometrySub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiRefObject* m_pReferencedObject;
};

struct GeometryCacheEntry : public NiRefObject
{
    virtual void cg_0() throw();
    virtual void cg_1() throw();
    virtual void cg_2() throw();
    virtual void cg_3() throw();
    virtual void cg_4() throw();
    virtual void cg_5() throw();
    virtual void cg_6() throw();
    virtual void cg_7() throw();
    virtual void cg_8() throw();
    virtual void cg_9() throw();
    virtual void cg_10() throw();
    virtual void cg_11() throw();
    virtual void cg_12() throw();
    virtual void cg_13() throw();
    virtual void cg_14() throw();
    virtual void cg_15() throw();
    virtual void cg_16() throw();
    virtual void cg_17() throw();
    virtual void cg_18() throw();
    virtual void cg_19() throw();
    virtual void cg_20() throw();
    virtual void cg_21() throw();
    virtual void cg_22() throw();
    virtual void cg_23() throw();
    virtual void cg_24() throw();
    virtual void cg_25() throw();
    virtual void cg_26() throw();
    virtual void cg_27() throw();
    virtual void cg_28() throw();
    virtual void cg_29() throw();
    virtual void cg_30() throw();
    virtual void cg_31() throw();
    virtual void cg_32() throw();
    virtual void cg_33() throw();
    virtual void cg_34() throw();
    virtual void cg_35() throw();
    virtual void cg_36() throw();
    virtual void cg_37() throw();
    virtual void cg_38() throw();
    virtual unsigned int GetCount() throw();
    virtual void cg2_0() throw();
    virtual void cg2_1() throw();
    virtual CachedGeometrySub* GetSub(unsigned int) throw();
    virtual CachedGeometrySub* GetExtra() throw();
};

template <class T> class NiTPointerAllocator
{
};

class NiPointerCachedGeometry
{
  public:
    GeometryCacheEntry* m_pObject;
    NiPointerCachedGeometry() : m_pObject(0)
    {}
    ~NiPointerCachedGeometry() throw()
    {
        if (m_pObject)
        {
            if (InterlockedDecrement(&m_pObject->m_uiRefCount) == 0)
                m_pObject->DeleteThis();
        }
    }
    operator GeometryCacheEntry*() const throw()
    {
        return m_pObject;
    }
    GeometryCacheEntry* operator->() const throw()
    {
        return m_pObject;
    }
};

template <>
__declspec(noalias) void NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, GeometryCacheEntry*>::GetNext(
    void*& pos, const char*& key, GeometryCacheEntry*& val) throw();

struct NiTPointerMap890 : public NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, GeometryCacheEntry*>
{
    virtual ~NiTPointerMap890() throw()
    {
        this->RemoveAll();
    }
};

template <class Key, class Val> struct NiTMap : public NiTMapBase<void, Key, Val>
{
    virtual ~NiTMap() throw()
    {
        this->RemoveAll();
    }
};

template <class T> struct NiTArray
{
    virtual ~NiTArray() throw()
    {
        NiFree(m_pBase);
    }
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usPad;
};

}  // namespace fnv_00e75a70

void* __cdecl FUN_00aa1070(unsigned int size);
namespace nsa98 {
struct Cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    void AllocateMipMap(unsigned int uiLevels, unsigned int uiFaces, unsigned int uiBytes);
};
}
// Allocates a pixel buffer and sets m_puiWidth, m_puiHeight, and m_puiOffsetInBytes for a mip map with uiLevels and uiFaces.
// @fnv 0x00a98090
// pdb: NiPersistentSrcTextureRendererData::AllocateData | NiPersistentSrcTextureRendererData.obj | fnv360_0822_retail, objrun_open, low
// pdb params: uiLevels, uiFaces, uiBytes
void nsa98::Cls::AllocateMipMap(unsigned int uiLevels, unsigned int uiFaces, unsigned int uiBytes)
{
    unsigned int uiStride = (uiBytes + 3) & ~3;
    unsigned int uiTotal = *(volatile unsigned int*)&uiFaces * uiStride;
    m_pucPixels = (unsigned char*)FUN_00aa1070(uiTotal + uiLevels * 12 + 4);
    m_puiWidth = (unsigned int*)(m_pucPixels + uiTotal);
    m_puiHeight = m_puiWidth + uiLevels;
    m_puiOffsetInBytes = m_puiHeight + uiLevels;
}
