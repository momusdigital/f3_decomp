#include "f3_common.h"
// src/havok/common/base/system/io/reader/hkstreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/hkstreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct VersionedDataBlock
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Read(void* destination, int size);
    int ReadBytes(int size);
};
// Reads up to size bytes in chunks of at most 512 into a local buffer, stopping on a zero-length read, and returns the number of bytes read.
// @fnv 0x00cb14f0
// pdb: hkStreamReader::skip | hkStreamReader.obj | fnv360_0822_retail, vtable, high
// pdb params: nbytes
int VersionedDataBlock::ReadBytes(int size)
{
    unsigned int buffer[128];
    int remaining = size;
    while (remaining)
    {
        int count = Read(buffer, remaining > 512 ? 512 : remaining);
        if (!count)
            break;
        remaining -= count;
    }
    return size - remaining;
}

class Stream
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Read(void* buf, int n);
    int ReadChar();
};

// @fnv 0x00cb1550
// pdb: hkStreamReader::readChar | hkStreamReader.obj | fnv360_0822_retail, call_seq, medium
int Stream::ReadChar()
{
    char c;
    if (Read(&c, 1))
        return c;
    return -1;
}

struct S_00cb1570
{
    int hkEntitySelectorAll_isEntityOk(void* pArg);
};
// @fnv 0x00cb1570
// pdb: `anonymous namespace'::hkEntitySelectorAll::isEntityOk | hkpSaveContactPointsUtil.obj | fnv360_0721_beta, vtable + skyrim(vtable), high
int S_00cb1570::hkEntitySelectorAll_isEntityOk(void* pArg)
{
    return 1;
}

// @fnv 0x00cb1580
// pdb: Random::nelems | IdvRandom.obj | fnv360_0721_beta, vtable, medium
int __cdecl FUN_00cb1580()
{
    return 1;
}

// @fnv 0x00cb15c0
// pdb: hkStreamReader::markSupported | hkStreamReader.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkStreamReader_markSupported(char* p)
{
    *p = 0;
}

struct CB1590Object
{
    virtual int FUN_00cb1590(const void* a, const void* b) const;
};

// @fnv 0x00cb1590
// pdb: hkFileSystem::listDirectory | HavokStream.obj | fnv360_0721_beta, vtable, medium
// pdb params: basePath, listingOut
int CB1590Object::FUN_00cb1590(const void* a, const void* b) const
{
    return 1;
}

struct CB15B0Bool
{
    char m_cBooleanValue;

    CB15B0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct CB15B0Object
{
    virtual CB15B0Bool hkStreamWriter_seekTellSupported() const;
};

// @fnv 0x00cb15b0
// pdb: hkStreamWriter::seekTellSupported | hkStreamWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
CB15B0Bool CB15B0Object::hkStreamWriter_seekTellSupported() const
{
    return false;
}

// @fnv 0x00cb15a0
// pdb: MagicSystem::MagicSchoolToSkill | MagicSystem.obj | fnv360_0721_beta, call_seq, medium
// pdb params: aeSchool
int FUN_00cb15a0()
{
    return -1;
}
