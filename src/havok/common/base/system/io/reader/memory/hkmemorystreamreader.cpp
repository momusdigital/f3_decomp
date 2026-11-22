#include "f3_common.h"
// src/havok/common/base/system/io/reader/memory/hkmemorystreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/memory/hkmemorystreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e059e0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int __thiscall hkMemoryStreamReader_rewindToMark();
};

// @fnv 0x00e059e0
// pdb: hkMemoryStreamReader::rewindToMark | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb: hkMemoryStreamReader::rewindToMark | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high (was: GetCurrentOffset)
int __thiscall FUN_00e059e0::hkMemoryStreamReader_rewindToMark()
{
    if (m_14 >= 0)
    {
        m_0c = m_14;
        return 0;
    }
    return 1;
}

struct hkMemoryStreamReader
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    unsigned char* __thiscall IsSupported(unsigned char* supported);
};

// @fnv 0x00e059c0
// pdb: hkMemoryStreamReader::markSupported | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
unsigned char* __thiscall hkMemoryStreamReader::IsSupported(unsigned char* supported)
{
    *supported = (m_10 != 0);
    return supported;
}

struct FUN_00e05bf0Manager
{
// @fnv 0x00e05bf0
    virtual void FUN_00e05bf0_0()
    {}
    virtual void FUN_00e05bf0_1()
    {}
    virtual void FUN_00e05bf0_2(hkMemoryStreamReader* object, unsigned short value)
    {}
};

struct FUN_00e059d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    int m_14;
    unsigned char* hkMemoryStreamReader_setMark(unsigned char* supported);
};

// @fnv 0x00e059d0
// pdb: hkMemoryStreamReader::setMark | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
unsigned char* FUN_00e059d0_cls::hkMemoryStreamReader_setMark(unsigned char* supported)
{
    m_14 = m_0c;
    return 0;
}

// hkMemoryStreamReader_seekTellSupported: sets the flag byte pointed to by the argument to 1 and returns the argument.
// @fnv 0x00e05a00
// pdb: hkMemoryStreamReader::seekTellSupported | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
unsigned char* __stdcall hkMemoryStreamReader_seekTellSupported(unsigned char* supported)
{
    *supported = 1;
    return supported;
}

struct hkBoolE059
{
    char m_cBooleanValue;
    hkBoolE059(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkObjectE059
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iEnd;
    int m_iCurrent;

    hkBoolE059 hkMemoryStreamReader_isOk() const;
};

// @fnv 0x00e059a0
// pdb: hkMemoryStreamReader::isOk | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb: hkMemoryStreamReader::isOk | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high (was: IsNotAtEnd)
hkBoolE059 hkObjectE059::hkMemoryStreamReader_isOk() const
{
    return m_iEnd != m_iCurrent + 1;
}

struct FUN_00e05a10_cls : hkMemoryStreamReader
{
    int __thiscall hkMemoryStreamReader_seek(int arg4, int mode);
};
// Computes a new stream position from arg4 and mode, clamps it to [0, m_10], stores it in m_0c and returns whether clamping occurred.
// @fnv 0x00e05a10
// pdb: hkMemoryStreamReader::seek | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int __thiscall FUN_00e05a10_cls::hkMemoryStreamReader_seek(int aiOffset, int mode)
{
    int edx = -1;
    switch (mode)
    {
    case 0:
        edx = aiOffset;
        break;
    case 1:
        edx = m_0c + aiOffset;
        break;
    case 2:
        edx = m_10 - aiOffset;
        break;
    }
    int result = 0;
    if (edx < 0)
    {
        edx = 0;
        result = edx + 1;
    }
    else
    {
        int esi = m_10;
        if (edx > esi)
        {
            edx = esi;
            result = 1;
        }
    }
    m_0c = edx;
    return result;
}

struct FnvCpu_FUN_00e05a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int FUN_00e05a70();
};
// @fnv 0x00e05a70
// pdb: NonActorMagicCaster::GetCurrentSpell | NonActorMagicCaster.obj | fnv360_0822_retail, vtable, medium
int FnvCpu_FUN_00e05a70_CpuObject::FUN_00e05a70()
{
    return value;
}

struct FUN_00e05a80Class
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual unsigned char* checkState(unsigned char* state);

    int m_04;
    unsigned char* m_08;
    int m_0c;
    int m_10;

    int __thiscall hkMemoryStreamReader_read(void* destination, int count);
};
extern "C" void __cdecl FUN_00cb1260(void* destination, const void* source, int count);

// @fnv 0x00e05a80
// pdb: hkMemoryStreamReader::read | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: buf, nbytes
// pdb: hkMemoryStreamReader::read | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high (was: ReadFromBuffer)
int __thiscall FUN_00e05a80Class::hkMemoryStreamReader_read(void* destination, int count)
{
    unsigned char state;
    if (*checkState(&state))
    {
        int remaining = m_10 - m_0c;
        int copied = count < remaining ? count : remaining;
        FUN_00cb1260(destination, m_08 + m_0c, copied);
        m_0c += copied;
        if (copied == 0 && count != 0)
            m_0c = m_10 + 1;
        return copied;
    }
    return 0;
}

class hkClass;
class hkStatisticsCollector;
// Virtual slots as the Fallout 3 vtable of hkMemoryStreamReader (0x00e88590) has them: the destructor,
// hkReferencedObject's two, then hkStreamReader's isOk, read, skip (names from the New Vegas Xbox 360 PDB).
struct FUN_00e05af0_Obj : hkMemoryStreamReader
{
    virtual ~FUN_00e05af0_Obj();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual hkBoolE059 isOk() const;
    virtual int read(void* buf, int nbytes);
    virtual int ReadBytes(int value);
};

// @fnv 0x00e05af0
// pdb: hkMemoryStreamReader::skip | hkMemoryStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: nbytes
int __thiscall FUN_00e05af0_Obj::ReadBytes(int aiByteCount)
{
    if (isOk())
    {
        int count = m_0c - m_08;

        if (aiByteCount < count)
            count = aiByteCount;

        m_08 += count;

        if (count == 0 && aiByteCount != 0)
            m_08 = m_0c + 1;

        return count;
    }

    return 0;
}

class hkMemoryAllocatorE05B;

struct hkMemoryRouterE05B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE05B* m_pStreamAllocator;

    hkMemoryAllocatorE05B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE05B {
extern "C" hkMemoryRouterE05B& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

class hkRefObjE05B
{
  public:
    virtual ~hkRefObjE05B() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjE05B() throw()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00e05b40 : public hkRefObjE05B
{
  public:
    void* m_data;
    int unk0C;
    int m_iElementCount;
    int unk14;
    int m_external;

    FUN_00e05b40(void* data, int size, int external) throw();
    virtual ~FUN_00e05b40() throw();
};

// Stores size and external flag; if not external, allocates size bytes from the router heap and copies data into it, otherwise keeps the data pointer.
// @f3 0x00a84f70 (community match, verified in this file)
#include <windows.h>

extern DWORD DAT_010f3170;

struct M3_Alloc
{
    void* __thiscall FUN_008f6f60(int size, int cls);
};
extern "C" void* __cdecl FUN_009234e0(void* destination, const void* source, int count);

// pdb: hkMemoryStreamReader::hkMemoryStreamReader | hkMemoryStreamReader.obj | fnv360_0822_retail, objrun, medium
// pdb params: mem, memSize, mt
FUN_00e05b40::FUN_00e05b40(void* data, int size, int external) throw()
{
    unk0C = 0;
    m_iElementCount = size;
    unk14 = -1;
    m_external = external;
    if (!external)
    {
        M3_Alloc* alloc = (M3_Alloc*)TlsGetValue(DAT_010f3170);
        m_data = alloc->FUN_008f6f60(size, 0x1a);
        FUN_009234e0(m_data, data, size);
    }
    else
    {
        m_data = data;
    }
}


namespace fnv_00e05bb0 {
struct hkMemoryRouterE05B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

extern "C" hkMemoryRouterE05B* __cdecl FUN_00c85750() throw();
void __cdecl FUN_00c856c0(void* pAllocator, void* p) throw();

inline void hkDeallocateE05B(void* p)
{
    hkMemoryRouterE05B* r = FUN_00c85750();
    FUN_00c856c0(r->m_pStreamAllocator, p);
}

class hkBaseObjectE05B
{
  public:
    virtual ~hkBaseObjectE05B()
    {}
};

class hkReferencedObjectE05B : public hkBaseObjectE05B
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkObjE05B : public hkReferencedObjectE05B
{
  public:
    void* m_data;
    int unk0C;
    int unk10;
    int unk14;
    int m_iValueAfterFlags;

    virtual ~hkObjE05B()
    {
        if (m_iValueAfterFlags == 0 || m_iValueAfterFlags == 1)
            hkDeallocateE05B(m_data);
    }

    void FUN_00e05bb0();
};

}  // namespace fnv_00e05bb0
