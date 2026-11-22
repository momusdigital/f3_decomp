// NiStream: reads and writes a NIF file: the header, the object table, links between objects and the string table.
// Names: FNV360_PDB (NiStream, 0822 retail/debug). Vtable: 24 slots, checked against F3_EXE's NiStream vtable
// 0x00e21204 (24 slots); the Load and Save overloads are laid out in the reverse of their declaration order. The PC
// layout is the Xbox 360 one (m_uiNifFileVersion +0xD8, m_pkIstr +0x24C, as the PC code reads them).
#ifndef FNV_NISTREAM_H
#define FNV_NISTREAM_H
#include "layout_support.h"
#include "BSStreamHeader.h"
#include "NiBinaryStream.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "NiProcessorAffinity.h"
#include "NiTLargeObjectArray.h"
#include "NiTPrimitiveArray.h"
#include "NiTSet.h"
class NiAVObject;
class NiSearchPath;
class NiTexture;
class NiThread;
#pragma pack(push, 4)
class NiStream
{
  public:
    enum ThreadStatus
    {
        IDLE = 0,
        LOADING = 1,
        CANCELLING = 2,
        PAUSING = 3,
        PAUSED = 4
    };

    enum
    {
        STREAM_OKAY = 0,
        FILE_NOT_LOADED = 1,
        NOT_NIF_FILE = 2,
        OLDER_VERSION = 3,
        LATER_VERSION = 4,
        NO_CREATE_FUNCTION = 5,
        ENDIAN_MISMATCH = 6
    };

    class BackgroundLoadProcedure;
    typedef NiObject*(__cdecl* CreateFunction)();
    typedef void(__cdecl* PostProcessFunction)(NiStream& kStream, NiObject* pkObject);

    virtual ~NiStream();                                                         //  0
    virtual bool Load(const char* pcFileName);                                   //  3
    virtual bool Load(char* pcBuffer, int iBufferSize);                          //  2
    virtual bool Load(NiBinaryStream* pkIstr);                                   //  1
    virtual bool Save(const char* pcFileName);                                   //  6
    virtual bool Save(char*& pcBuffer, int& iBufferSize);                        //  5
    virtual bool Save(NiBinaryStream* pkOstr);                                   //  4
    virtual void BackgroundLoadOnExit();                                         //  7
    virtual bool RegisterFixedString(const NiFixedString& kString);              //  8
    virtual bool RegisterSaveObject(NiObject* pkObject);                         //  9
    virtual void ChangeObject(NiObject* pkNewObject);                            // 10
    virtual unsigned int GetLinkIDFromObject(const NiObject* pkObject) const;    // 11
    virtual void SaveLinkID(const NiObject* pkObject);                           // 12
    virtual bool LoadHeader();                                                   // 13
    virtual void SaveHeader();                                                   // 14
    virtual bool LoadStream();                                                   // 15
    virtual bool SaveStream();                                                   // 16
    virtual void RegisterObjects();                                              // 17
    virtual void LoadTopLevelObjects();                                          // 18
    virtual void SaveTopLevelObjects();                                          // 19
    virtual bool LoadObject();                                                   // 20
    virtual unsigned int PreSaveObjectSizeTable();                               // 21
    virtual bool SaveObjectSizeTable(unsigned int uiStartOffset);                // 22
    virtual bool LoadObjectSizeTable();                                          // 23

    unsigned int GetFileVersion() const
    {
        return m_uiNifFileVersion;
    }
    unsigned int GetFileUserDefinedVersion() const
    {
        return m_uiNifFileUserDefinedVersion;
    }
    NiBinaryStream& Istr()
    {
        return *m_pkIstr;
    }
    NiBinaryStream& Ostr()
    {
        return *m_pkOstr;
    }
    static unsigned int GetVersion(unsigned int uiMajor, unsigned int uiMinor, unsigned int uiPatch,
                                   unsigned int uiRevision)
    {
        return (uiMajor << 24) | (uiMinor << 16) | (uiPatch << 8) | uiRevision;
    }

    void ReadLinkID();
    unsigned int ReadMultipleLinkIDs();
    NiObject* GetObjectFromLinkID();
    NiObject* ResolveLinkID();  // F3 0x0082b5d0: the link to NiStream::ResolveLinkID is medium tier (call_seq)
    unsigned int GetNumberOfLinkIDs();
    void SetNumberOfLinkIDs(unsigned int uiLinks);
    NiObjectGroup* GetGroupFromID(unsigned int uiID) const;
    unsigned int GetIDFromGroup(NiObjectGroup* pkGroup) const;
    void LoadCString(char*& pcString);
    void SaveCString(const char* pcString);
    void LoadFixedString(NiFixedString& kString);
    void SaveFixedString(const NiFixedString& kString);
    void LoadCStringAsFixedString(NiFixedString& kString);
    void InsertObject(NiObject* pkObject);
    void RemoveAllObjects();
    void SetFilePath(const char* pcFilePath);
    bool GetNextSearchPath(char* pcPath, unsigned int uiStringLen);
    void GetTexture(const char* pcTexture, NiPointer<NiTexture>& spTexture) const;
    void SetTexture(NiTexture* pkTexture);
    void SetLastError(unsigned int uiError);
    static unsigned int GetVersionFromString(const char* pcVersionString);
    static NiObject* CreateObjectByRTTI(const char* pcRTTI);
    static void RegisterPostProcessFunction(PostProcessFunction pfnFunc);
    static void UnregisterPostProcessFunction(PostProcessFunction pfnFunc);

    BSStreamHeader m_BSStreamHeader;                          // +0x4
    NiTPrimitiveArray<NiObjectGroup*> m_kGroups;              // +0xC8
    unsigned int m_uiNifFileVersion;                          // +0xD8
    unsigned int m_uiNifFileUserDefinedVersion;               // +0xDC
    char m_acFileName[260];                                   // +0xE0
    bool m_bSaveLittleEndian;                                 // +0x1E4
    bool m_bSourceIsLittleEndian;                             // +0x1E5
    NiSearchPath* m_pkSearchPath;                             // +0x1E8
    NiTLargeObjectArray<NiPointer<NiObject> > m_kObjects;     // +0x1EC
    NiTLargePrimitiveArray<unsigned int> m_kObjectSizes;      // +0x204
    NiTLargeObjectArray<NiPointer<NiObject> > m_kTopObjects;  // +0x21C
    NiTLargeObjectArray<NiFixedString> m_kFixedStrings;       // +0x234
    NiBinaryStream* m_pkIstr;                                 // +0x24C
    NiBinaryStream* m_pkOstr;                                 // +0x250
    NiTPrimitiveSet<unsigned int> m_kLinkIDs;                 // +0x254
    unsigned int m_uiLinkIndex;                               // +0x260
    NiTPrimitiveSet<unsigned int> m_kLinkIDBlocks;            // +0x264
    unsigned int m_uiLinkBlockIndex;                          // +0x270
    NiTPointerMap<const NiObject*, unsigned int> m_kRegisterMap;  // +0x274
    unsigned short m_usNiAVObjectFlags;                       // +0x284
    unsigned short m_usNiTimeControllerFlags;                 // +0x286
    unsigned short m_usNiPropertyFlags;                       // +0x288
    ThreadStatus m_eBackgroundLoadStatus;                     // +0x28C
    bool m_bBackgroundLoadExitStatus;                         // +0x290
    unsigned int m_uiLoad;                                    // +0x294
    unsigned int m_uiLink;                                    // +0x298
    unsigned int m_uiPostLink;                                // +0x29C
    NiThread* m_pkThread;                                     // +0x2A0
    BackgroundLoadProcedure* m_pkBGLoadProc;                  // +0x2A4
    int m_ePriority;                                          // +0x2A8 NiThread::Priority
    NiProcessorAffinity m_kAffinity;                          // +0x2AC
    char m_acLastLoadedRTTI[260];                             // +0x2B4
    unsigned int m_uiLastError;                               // +0x3B8
    char m_acLastErrorMessage[260];                           // +0x3BC
    char m_acFilePath[260];                                   // +0x4C0

    static const unsigned int NULL_LINKID;
    static const unsigned int ms_uiNifMinVersion;
    static const unsigned int ms_uiNifMaxVersion;
    static const unsigned int ms_uiNifMinUserDefinedVersion;
    static const unsigned int ms_uiNifMaxUserDefinedVersion;
    static NiTPrimitiveArray<PostProcessFunction>* ms_pkPostProcessFunctions;
    static bool bUseDefaultPath;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiStream) == 0x5C4);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kGroups) == 0xC8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiNifFileVersion) == 0xD8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkSearchPath) == 0x1E8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kObjects) == 0x1EC);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kFixedStrings) == 0x234);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pkIstr) == 0x24C);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kLinkIDs) == 0x254);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kRegisterMap) == 0x274);
FNV_STATIC_ASSERT(offsetof(NiStream, m_eBackgroundLoadStatus) == 0x28C);
FNV_STATIC_ASSERT(offsetof(NiStream, m_kAffinity) == 0x2AC);
FNV_STATIC_ASSERT(offsetof(NiStream, m_uiLastError) == 0x3B8);
FNV_STATIC_ASSERT(offsetof(NiStream, m_acFilePath) == 0x4C0);

template <class T> inline void NiStreamLoadBinary(NiStream& kStream, T& kValue)
{
    NiStreamLoadBinary(kStream.Istr(), kValue);
}
template <class T> inline void NiStreamLoadBinary(NiStream& kStream, T* pkValues, unsigned int uiNumEls)
{
    NiStreamLoadBinary(kStream.Istr(), pkValues, uiNumEls);
}
template <class T> inline void NiStreamSaveBinary(NiStream& kStream, const T& kValue)
{
    NiStreamSaveBinary(kStream.Ostr(), kValue);
}
template <class T> inline void NiStreamSaveBinary(NiStream& kStream, const T* pkValues, unsigned int uiNumEls)
{
    NiStreamSaveBinary(kStream.Ostr(), pkValues, uiNumEls);
}
#endif
