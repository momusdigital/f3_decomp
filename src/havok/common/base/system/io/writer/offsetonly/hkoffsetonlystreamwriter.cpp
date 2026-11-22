#include "f3_common.h"
// src/havok/common/base/system/io/writer/offsetonly/hkoffsetonlystreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/offsetonly/hkoffsetonlystreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class hkClass;
class hkStatisticsCollector;
// Virtual slots as the Fallout 3 vtable of hkOffsetOnlyStreamWriter (0x00e885c4, 9 slots) has them; names from the
// New Vegas Xbox 360 PDB.
struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
};

struct FUN_00e02ef0 : hkReferencedObject
{
    int m_kPointA;
    int m_kPointB;

    FUN_00e02ef0();
    virtual char isOk() const;
    virtual int write(const void* buf, int nbytes);
    virtual void flush();
    virtual char seekTellSupported() const;
    virtual int seek(int offset, int whence);
    virtual int tell() const;
};

// @fnv 0x00e02ef0
// pdb: hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, uvref, high
FUN_00e02ef0::FUN_00e02ef0()
{
    m_kPointA = 0;
    m_kPointB = 0;
}

struct E02E70Stats
{
    int unk00;
    int unk04;
    int m_pTileTemplate;
    int m_peak;

    int hkOffsetOnlyStreamWriter_write(void* p, int numBytes);
};

// Adds numBytes to the running total, updates the peak if the total exceeds it, and returns numBytes.
// @fnv 0x00e02e70
// pdb: hkOffsetOnlyStreamWriter::write | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int E02E70Stats::hkOffsetOnlyStreamWriter_write(void* p, int numBytes)
{
    m_pTileTemplate += numBytes;
    m_peak = (m_pTileTemplate > m_peak) ? m_pTileTemplate : m_peak;
    return numBytes;
}

class FUN_00e02e90_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int hkOffsetOnlyStreamWriter_seek(int value, int mode);
};

// Applies value to m_08 according to mode (set, add, or subtract from m_0c), then stores the larger of m_08 and m_0c into m_0c and returns 0.
// @fnv 0x00e02e90
// pdb: hkOffsetOnlyStreamWriter::seek | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, vtable, high
// pdb params: offset, whence
// pdb: hkOffsetOnlyStreamWriter::seek | hkOffsetOnlyStreamWriter.obj | fnv360_0822_retail, vtable, high (was: ApplyValue)
int FUN_00e02e90_cls::hkOffsetOnlyStreamWriter_seek(int value, int mode)
{
    switch (mode)
    {
    case 0:
        m_08 = value;
        break;
    case 1:
        m_08 += value;
        break;
    case 2:
        m_08 = m_0c - value;
        break;
    }
    int iCurrent = m_08;
    int iOldMax = *(volatile int*)&m_0c;
    if (iCurrent > iOldMax)
    {
        m_0c = iCurrent;
    }
    else
    {
        m_0c = iOldMax;
    }
    return 0;
}

// @fnv 0x00e02f10
// pdb: hkpSimpleContactConstraintData::isValid | hkpSimpleContactConstraintData.obj | tesv_win, objrun_open, low
void __stdcall FUN_00e02f10(unsigned char* output)
{
    *output = 1;
}

// @fnv 0x00e02f20
// pdb: hkCrc32StreamWriter::isOk | hkCrc32StreamWriter.obj | fnv360_0822_retail, vtable, medium
void __stdcall FUN_00e02f20(unsigned char* output)
{
    *output = 1;
}

// hkIArchive (Fallout 3 vtable 0x00e86c40: the destructor and hkReferencedObject's two slots)
struct FUN_00e02ee0_cls
{
    virtual ~FUN_00e02ee0_cls();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    int unk04;
    int unk08;

    int FUN_00e02ee0();
};

// @fnv 0x00e02ee0
// pdb: hkIArchive::getStreamReader | hkIArchive.obj | fnv360_0822_retail, objrun, medium
int FUN_00e02ee0_cls::FUN_00e02ee0()
{
    return unk08;
}
