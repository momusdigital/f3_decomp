#include "f3_common.h"
// src/havok/common/base/system/io/reader/buffered/hkbufferedstreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/buffered/hkbufferedstreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2bb20_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int hkBufferedStreamReader_setMark(int p);
};

// @fnv 0x00d2bb20
// pdb: hkBufferedStreamReader::setMark | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: markLimit
// pdb: hkBufferedStreamReader::setMark | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high (was: SetValueAndCompare)
int FUN_00d2bb20_cls::hkBufferedStreamReader_setMark(int iValue)
{
    m_1c = m_10;
    m_20 = iValue;
    return iValue > m_18;
}

struct FUN_00d2bb40_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int hkBufferedStreamReader_rewindToMark();
};
// @fnv 0x00d2bb40
// pdb: hkBufferedStreamReader::rewindToMark | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FUN_00d2bb40_cls::hkBufferedStreamReader_rewindToMark()
{
    if (m_1c >= 0)
    {
        m_10 = m_1c;
        return 0;
    }
    return 1;
}

struct FUN_00d2ba80_cls
{
    int hkBufferedStreamReader_skip(int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
        virtual int v12();

    // hkBufferedStreamReader (New Vegas Xbox 360 PDB names): the stream, then m_buf's begin, current and size.
    int unk04;
    void* m_stream;    // +0x08
    char* m_begin;     // +0x0C m_buf.begin
    int m_current;     // +0x10 m_buf.current
    int m_size;        // +0x14 m_buf.size
};
// Advances the read position by n bytes, refilling the buffer via v12() when the remaining bytes are insufficient, and returns the number of bytes consumed.
// @fnv 0x00d2ba80
// pdb: hkBufferedStreamReader::skip | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: nbytes
// pdb: hkBufferedStreamReader::skip | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high (was: SkipBytes)
int FUN_00d2ba80_cls::hkBufferedStreamReader_skip(int aiByteCount)
{
    int iRemaining = aiByteCount;
    int iAvailable = m_size - m_current;
    while (iRemaining > iAvailable)
    {
        iRemaining -= iAvailable;
        if (v12())
            return aiByteCount - iRemaining;
        iAvailable = m_size - m_current;
    }
    m_current += iRemaining;
    return aiByteCount;
}

struct FUN_00d2bb10_this
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    bool* hkBufferedStreamReader_markSupported(bool* out);
};

// @fnv 0x00d2bb10
// pdb: hkBufferedStreamReader::markSupported | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
bool* FUN_00d2bb10_this::hkBufferedStreamReader_markSupported(bool* out)
{
    *out = (m_18 != 0);
    return out;
}

void _FUN_00cb1260(void*, const void*, int);

struct FUN_00d2ba00_cls : FUN_00d2ba80_cls
{
    int hkBufferedStreamReader_read(char* pBuffer, int nSize);
};

// Copies up to nSize bytes from the buffer into pBuffer, refilling via v12 when it runs out, and returns the number of bytes read.
// @fnv 0x00d2ba00
// pdb: hkBufferedStreamReader::read | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int FUN_00d2ba00_cls::hkBufferedStreamReader_read(char* apDest, int nSize)
{
    char* pDest = apDest;
    int nRemaining = nSize;
    int nAvailable = m_size - m_current;

    while (nRemaining > nAvailable)
    {
        _FUN_00cb1260(pDest, m_begin + m_current, nAvailable);
        m_current += nAvailable;
        pDest += nAvailable;
        nRemaining -= nAvailable;

        if (v12() != 0)
            return nSize - nRemaining;

        nAvailable = m_size - m_current;
    }

    _FUN_00cb1260(pDest, m_begin + m_current, nRemaining);
    m_current += nRemaining;
    return nSize;
}

struct FUN_00d2bb60_object
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9(int)
    {}
};

struct FUN_00d2bb60_cls
{
    int* m_pVTable;
    int m_uiStandInValue;
    FUN_00d2bb60_object* m_pObject;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
};

// @fnv 0x00d2bb60
int __fastcall FUN_00d2bb60(FUN_00d2bb60_cls* self, int unused, int value)
{
    self->m_pObject->v9(value);
    return value;
}

struct FUN_00d2bbd0_cls
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d2bbd0_cls* Init(int p);
};
// @f3 0x009af360 (community match, verified in this file)
extern int DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
struct TlsMemory
{
    virtual void* v0(unsigned int size, void* ptr, int type);
};
// pdb: hkBufferedStreamReader::Buffer::Buffer | hkBufferedStreamReader.obj | fnv360_0822_retail, objrun, high
// pdb params: cap
FUN_00d2bbd0_cls* FUN_00d2bbd0_cls::Init(int p)
{
    TlsMemory* mm = (TlsMemory*)TlsGetValue(DAT_010f3170);
    m_00 = mm->v0(0x40, (void*)p, 0x1a);
    m_04 = 0;
    m_08 = 0;
    m_0c = p;
    m_10 = -1;
    m_14 = -1;
    return this;
}


struct hkBoolD2B9
{
    char m_cBooleanValue;
};

class hkStreamWriterD2B9
{
  public:
    virtual ~hkStreamWriterD2B9() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual hkBoolD2B9 IsStreamValid() const throw();
    virtual int write(const void* pvBuf, int iNumBytes) throw();
};

class hkBufferedStreamWriterD2B9
{
  public:
    int unk00;
    int unk04;
    hkStreamWriterD2B9* m_stream;
    char* m_buf;
    int m_bufOffset;
    int m_writePos;
    int m_bufSize;

    void FUN_00d2b900() throw();
    int Flush();
};

// @fnv 0x00d2b990
// pdb: hkBufferedStreamReader::refillBuffer | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high
int hkBufferedStreamWriterD2B9::Flush()
{
    if (!m_stream->IsStreamValid().m_cBooleanValue)
        return 1;
    FUN_00d2b900();
    int iNumBytes = m_bufSize - m_writePos;
    int iTotal = 0;
    while (iTotal < iNumBytes)
    {
        int iBytesWritten = m_stream->write(m_buf + m_bufOffset, iNumBytes);
        m_writePos += iBytesWritten;
        iTotal += iBytesWritten;
        if (iBytesWritten != iNumBytes)
            return iTotal == 0;
    }
    return 0;
}

struct Reader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char* v3(unsigned char*);
};
struct hkBool
{
    unsigned char m_cBooleanValue;
    hkBool(bool v) : m_cBooleanValue(v)
    {}
};
struct Stream
{
    int a, b;
    Reader* reader;
    int c, pos, end;
    hkBool hkBufferedStreamReader_isOk();
};
// @fnv 0x00d2bad0
// pdb: hkBufferedStreamReader::isOk | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
hkBool Stream::hkBufferedStreamReader_isOk()
{
    unsigned char byte;
    return hkBool(pos != end || *reader->v3(&byte) != 0);
}

namespace fnv_00d2bba0 {
struct Stream
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int Tell();
};
struct FUN_00d2bba0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    Stream* m_stream;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int GetCurrentPosition();
};
// Returns the stream's Tell() offset adjusted by (m_10 - m_14), or -1 if Tell() is negative.
// @fnv 0x00d2bba0
// pdb: hkBufferedStreamReader::tell | hkBufferedStreamReader.obj | tesv_win, vtable, medium
int FUN_00d2bba0_cls::GetCurrentPosition()
{
    int r = m_stream->Tell();
    if (r >= 0)
        return (m_10 - m_14) + r;
    return -1;
}
}  // namespace fnv_00d2bba0

class hkTargetD2BB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void reset(int flags);
};

class hkTrackerD2BB
{
  public:
    int unk00;
    int unk04;
    hkTargetD2BB* m_target;
    int unk0C;
    int m_uiItemCount;
    int m_total;
    int unk18;
    int m_pHeadNode;
    int m_last;

    void Reset(int flags);
};

// @fnv 0x00d2bb80
// pdb: hkBufferedStreamReader::seek | hkBufferedStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: offset, whence
void hkTrackerD2BB::Reset(int flags)
{
    m_pHeadNode = -1;
    m_last = -1;
    m_uiItemCount = 0;
    m_total = 0;
    m_target->reset(flags);
}

extern "C" void __cdecl FUN_00cb1270(void*, const void*, int);
class BufWriterMarkD2B9
{
  public:
    int unk00;
    int unk04;
    hkStreamWriterD2B9* m_stream;
    char* m_buf;
    int m_bufOffset;
    int m_writePos;
    int m_bufSize;
    int m_iReadPos;
    int m_markLimit;
    void FUN_00d2b900() throw();
    int Flush();
};
// @fnv 0x00d2b900
void BufWriterMarkD2B9::FUN_00d2b900() throw()
{
    if (m_iReadPos < 0)
    {
        m_bufOffset = 0;
        m_writePos = 0;
        return;
    }
    if (m_bufOffset - m_iReadPos > m_markLimit)
    {
        m_bufOffset = 0;
        m_writePos = 0;
        m_iReadPos = -1;
        m_markLimit = -1;
        return;
    }
    if (m_iReadPos > 0)
    {
        int dataSize = m_bufOffset - m_iReadPos;
        int remainder = dataSize % 512;
        int padBytes = (remainder != 0) ? (512 - remainder) : 0;
        FUN_00cb1270(m_buf + padBytes, m_buf + m_iReadPos, dataSize);
        m_iReadPos = padBytes;
        m_bufOffset = ((dataSize / 512) + (remainder != 0 ? 1 : 0)) * 512;
        m_writePos = m_bufOffset;
    }
}
