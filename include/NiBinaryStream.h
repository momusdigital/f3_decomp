// NiBinaryStream: the base of Gamebryo's file and memory streams; reads and writes go through two function pointers
// that the derived stream sets (with or without endian swapping).
// Names: FNV360_PDB (NiBinaryStream, 0822 retail/debug; BinaryRead/BinaryWrite and the NiStreamLoadBinary templates
// are inline in nibinarystream.h). Vtable: 5 slots, checked against F3_EXE's NiBinaryStream vtable 0x00e2c508.
#ifndef FNV_NIBINARYSTREAM_H
#define FNV_NIBINARYSTREAM_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiBinaryStream
{
  public:
    typedef unsigned int(__cdecl* READFUNC)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    typedef unsigned int(__cdecl* WRITEFUNC)(NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                             unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStream();                    //  0
    virtual operator bool() const = 0;            //  1
    virtual void Seek(int iNumBytes) = 0;         //  2
    virtual unsigned int GetPosition() const;     //  3
    virtual void SetEndianSwap(bool bDoSwap) = 0;  //  4

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesRead;
        return uiBytesRead;
    }
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents = 1)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiAbsoluteCurrentPos += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int m_uiAbsoluteCurrentPos;  // +0x4
    READFUNC m_pfnRead;                   // +0x8
    WRITEFUNC m_pfnWrite;                 // +0xC

    static bool ms_bEndianMatchHint;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_uiAbsoluteCurrentPos) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_pfnRead) == 0x8);

template <class T> inline void NiStreamLoadBinary(NiBinaryStream& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize);
}
template <class T> inline void NiStreamLoadBinary(NiBinaryStream& kStream, T* pkValues, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pkValues, uiNumEls * sizeof(T), &uiSize);
}
template <class T> inline void NiStreamSaveBinary(NiBinaryStream& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize);
}
template <class T> inline void NiStreamSaveBinary(NiBinaryStream& kStream, const T* pkValues, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(pkValues, uiNumEls * sizeof(T), &uiSize);
}
#endif
