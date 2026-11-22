#include "f3_common.h"
// src/havok/common/base/system/io/oarchive/hkoarchive.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/oarchive/hkoarchive.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned int __stdcall hkOArchive_writeArrayGeneric(void*, int, int);

// @fnv 0x00d609c0
// pdb: hkOArchive::writeFloat32 | hkOArchive.obj | fnv360_0822_debug, objrun, high
// pdb params: f
// pdb: hkOArchive::writeFloat32 | hkOArchive.obj | fnv360_0822_debug, objrun, high (was: HashUInt)
unsigned int __stdcall hkOArchive_writeFloat32(unsigned int auiValue)
{
    return hkOArchive_writeArrayGeneric(&auiValue, 4, 1);
}

struct hkOArchive
{
    void WriteBinaryData(void* p, int n, int m);
    void FUN_00d609e0(int n, int m);
};
// @fnv 0x00d609e0
void hkOArchive::FUN_00d609e0(int n, int m)
{
    WriteBinaryData(&n, 8, 1);
}

struct FUN_00d60a20_class
{
    void __thiscall hkOArchive_writeArrayGeneric(const void* data, int type, unsigned int size);
    void __thiscall hkOArchive_writeArray8u(const void* data, unsigned int size);
};

// @fnv 0x00d60a20
// pdb: hkOArchive::writeArray8u | hkOArchive.obj | fnv360_0822_debug, objrun + skyrim(objrun), high
void __thiscall FUN_00d60a20_class::hkOArchive_writeArray8u(const void* data, unsigned int size)
{
    hkOArchive_writeArrayGeneric(data, 1, size);
}

struct FUN_00d60600_class
{
    void hkOArchive_writeArrayGeneric(int a, int b, int c);
};

struct FUN_00d60a60_class : public FUN_00d60600_class
{
    void hkOArchive_writeArray16u(int a, int b);
};

// @fnv 0x00d60a60
// pdb: hkOArchive::writeArray16u | hkOArchive.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void FUN_00d60a60_class::hkOArchive_writeArray16u(int aiFirst, int aiSecond)
{
    hkOArchive_writeArrayGeneric(aiFirst, 2, aiSecond);
}

struct FUN_00d60a80_class
{
    void hkOArchive_writeArrayGeneric(const void* p, unsigned int count, unsigned int elementSize);
    void FUN_00d60a80(const void* p, unsigned int count);
};

// @fnv 0x00d60a80
void FUN_00d60a80_class::FUN_00d60a80(const void* apData, unsigned int count)
{
    hkOArchive_writeArrayGeneric(apData, 4, count);
}

struct FUN_00d60aa0_class
{
    void hkOArchive_writeArrayGeneric(const void* data, int count, int size);
    void FUN_00d60aa0(const void* data, int count);
};

// @fnv 0x00d60aa0
// pdb: hkOArchive::writeArray32u | hkOArchive.obj | fnv360_0822_retail, objrun, medium
// pdb params: array, nelem
void FUN_00d60aa0_class::FUN_00d60aa0(const void* data, int count)
{
    hkOArchive_writeArrayGeneric(data, 4, count);
}

namespace fnv_00d60ac0 {
struct hkOArchive
{
    void hkOArchive_writeArrayGeneric(const void* data, unsigned int size, unsigned int elementCount);
    void writeArray64(const void* data, unsigned int elementCount);
};
// @fnv 0x00d60ac0
// pdb: hkOArchive::writeArray64 | hkOArchive.obj | fnv360_0822_retail, objrun, high
// pdb params: array, nelem
// pdb: hkOArchive::writeArray64 | hkOArchive.obj | fnv360_0822_retail, objrun, high (was: WriteArray)
void hkOArchive::writeArray64(const void* data, unsigned int elementCount)
{
    hkOArchive_writeArrayGeneric(data, 8, elementCount);
}
}  // namespace fnv_00d60ac0

struct FUN_00d60ae0_Class
{
    void hkOArchive_writeArrayGeneric(void* p, int a, int b);
    void FUN_00d60ae0(int a, int b);
};
// @fnv 0x00d60ae0
void FUN_00d60ae0_Class::FUN_00d60ae0(int a, int b)
{
    hkOArchive_writeArrayGeneric((void*)a, 8, b);
}

struct hkOArchive_2
{
    void WriteBinaryData(void* p, int n, int m);
    void WriteInt(int val);
};
// @fnv 0x00d60940
// pdb: hkOArchive::write32 | hkOArchive.obj | fnv360_0822_retail, call_seq, high
// pdb params: i
void hkOArchive_2::WriteInt(int aiValue)
{
    WriteBinaryData(&aiValue, 4, 1);
}

// @fnv 0x00d60960
// pdb: hkOArchive::write32u | hkOArchive.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap), high
void __stdcall hkOArchive_write32u(const float* p)
{
    hkOArchive_writeArrayGeneric((void*)&p, 4, 1);
}

struct FUN_00d60980_class : public hkOArchive
{
    void FUN_00d60980(int a, int b);
};

// @fnv 0x00d60980
void FUN_00d60980_class::FUN_00d60980(int aiValue, int aiUnused)
{
    WriteBinaryData(&aiValue, 8, 1);
}

struct FUN_00d609a0_Class
{
    void WriteBinaryData(void* p, int n, int m);
    void hkOArchive_write64u(int value, int other);
};

// @fnv 0x00d609a0
// pdb: hkOArchive::write64u | hkOArchive.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_seq), high
void FUN_00d609a0_Class::hkOArchive_write64u(int value, int)
{
    WriteBinaryData(&value, 8, 1);
}

struct FUN_00d605b0_writer
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void write(const void* data, int size) = 0;
};

struct FUN_00d605b0_class
{
    void hkOArchive_write8(unsigned char value);
};

// @fnv 0x00d605b0
// pdb: hkOArchive::write8 | hkOArchive.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
void FUN_00d605b0_class::hkOArchive_write8(unsigned char value)
{
    FUN_00d605b0_writer* writer = *reinterpret_cast<FUN_00d605b0_writer**>(reinterpret_cast<char*>(this) + 8);
    writer->write(&value, 1);
}

struct FUN_00d605d0_impl
{
    virtual void FUN_00d605d0_a();
    virtual void FUN_00d605d0_b();
    virtual void FUN_00d605d0_c();
    virtual void FUN_00d605d0_d();
    virtual void write(const void* data, unsigned int size);
};

struct FUN_00d605d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void hkOArchive_write8u(unsigned char value);
};

// @fnv 0x00d605d0
// pdb: hkOArchive::write8u | hkOArchive.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(objrun), high
void FUN_00d605d0_class::hkOArchive_write8u(unsigned char value)
{
    reinterpret_cast<FUN_00d605d0_impl*>(m_8)->write(&value, 1);
}

struct FUN_00d607e0_object
{
    virtual void FUN_00d607e0_virtual0();
    virtual void FUN_00d607e0_virtual1();
    virtual void FUN_00d607e0_virtual2();
    virtual void FUN_00d607e0_virtual3(int value);
};

struct FUN_00d607e0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00d607e0_object* m_8;

    int __thiscall ForwardValueToObject(int value);
};

// @fnv 0x00d607e0
// pdb: hkSubStreamWriter::isOk | hkBinaryPackfileWriter.obj | fnv360_0822_retail, vtable, high
int __thiscall FUN_00d607e0_class::ForwardValueToObject(int value)
{
    m_8->FUN_00d607e0_virtual3(value);
    return value;
}

struct FUN_00d60a00_class : public hkOArchive
{
    void WriteData(const void* data, unsigned int size);
};

// @fnv 0x00d60a00
// pdb: hkOArchive::writeArray8 | hkOArchive.obj | fnv360_0822_debug, objrun, high
// pdb params: array, nelem
void FUN_00d60a00_class::WriteData(const void* data, unsigned int size)
{
    WriteBinaryData((void*)data, 1, size);
}

struct FUN_00d60a40_class : public hkOArchive
{
    void FUN_00d60a40(int a, int b);
};
// @fnv 0x00d60a40
void FUN_00d60a40_class::FUN_00d60a40(int apData, int b)
{
    WriteBinaryData((void*)apData, 2, b);
}

struct FUN_00d60b00_class
{
    void __thiscall hkOArchive_writeArrayFloat32(const float* data, unsigned int count);
};

// @fnv 0x00d60b00
// pdb: hkOArchive::writeArrayFloat32 | hkOArchive.obj | fnv360_0822_retail, call_seq, high
// pdb params: array, nelem
// pdb: hkOArchive::writeArrayFloat32 | hkOArchive.obj | fnv360_0822_retail, call_seq, high (was: WriteFloatArray)
void __thiscall FUN_00d60b00_class::hkOArchive_writeArrayFloat32(const float* data, unsigned int count)
{
    ((hkOArchive*)this)->WriteBinaryData((void*)data, 4, (int)count);
}

// Swaps the two bytes stored at the given addresses.
// @fnv 0x00d605f0
static void FUN_00d605f0(unsigned char* pFirst, unsigned char* pSecond)
{
    unsigned char t = *pFirst;
    *pFirst = *pSecond;
    *pSecond = t;
}

// Keeps the helper referenced so the compiler emits its out-of-line body.
void swapBytesCaller(unsigned char* pLeft, unsigned char* pRight)
{
    FUN_00d605f0(pLeft, pRight);
}

class hkClass;
class hkStatisticsCollector;
// hkStreamWriter: the slots of the Fallout 3 vtable (hkSubStreamWriter, 0x00e800c0) up to write, with the New Vegas
// Xbox 360 PDB's names.
struct hkStub
{
    virtual ~hkStub();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual char isOk() const;
    virtual int write(const void* buf, int nbytes);
};
// hkSubStreamWriter
struct FUN_00d607b0_class
{
    int unk00;
    int unk04;
    hkStub* m_childStream;  // +0x08
    int FUN_00d607b0(const void* buf, int nbytes);
};
// @fnv 0x00d607b0
// Forwards to the child stream: slot 4 (write) of the Fallout 3 hkSubStreamWriter vtable (0x00e800c0).
int FUN_00d607b0_class::FUN_00d607b0(const void* buf, int nbytes)
{
    return m_childStream->write(buf, nbytes);
}

struct S_00d607c0
{
    int unk0;
    int unk4;
    int unk8;
    char unkC;
    void FUN_00d607c0(char v);
};
// @fnv 0x00d607c0
void S_00d607c0::FUN_00d607c0(char v)
{
    unkC = v;
}

extern "C" void* __cdecl FUN_00cb1260(void* dest, const void* src, unsigned int count);

struct ObjectWriter
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void write(const void* data, int size) = 0;
};

struct Archive
{
    void* vtable;
    int unk04;
    ObjectWriter* m_pStreamWriter;
    char m_byteswap;

    void hkOArchive_writeArrayGeneric(const void* data, int elementSize, int count);
};

inline void swapBytes(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

// @fnv 0x00d60600
// pdb: hkOArchive::writeArrayGeneric | hkOArchive.obj | fnv360_0822_retail, call_seq, high
// pdb params: ptr, elemSize, arraySize
// pdb: hkOArchive::writeArrayGeneric | hkOArchive.obj | fnv360_0822_retail, call_seq, high (was: WriteSwapped)
void Archive::hkOArchive_writeArrayGeneric(const void* data, int elementSize, int count)
{
    if (!m_byteswap)
    {
        m_pStreamWriter->write(data, elementSize * count);
        return;
    }

    int aiBuffer[128];
    int chunkSize = 512;
    int numInBlock = chunkSize / elementSize;
    const char* cur = (const char*)data;
    int totalBytes = elementSize * count;
    int remBytes = totalBytes % 512;
    int remCount = remBytes / elementSize;

    while (totalBytes > 0)
    {
        if (totalBytes < 512)
        {
            numInBlock = remCount;
            chunkSize = remBytes;
        }

        FUN_00cb1260(aiBuffer, cur, chunkSize);

        switch (elementSize)
        {
        case 2: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[1]);
                p += 2;
            }
        }
        break;
        case 4: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[3]);
                swapBytes(p[1], p[2]);
                p += 4;
            }
        }
        break;
        case 8: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[7]);
                swapBytes(p[1], p[6]);
                swapBytes(p[2], p[5]);
                swapBytes(p[3], p[4]);
                p += 8;
            }
        }
        break;
        }

        m_pStreamWriter->write(aiBuffer, chunkSize);
        cur += chunkSize;
        totalBytes -= chunkSize;
    }
}

struct FnvCpu_FUN_00d607d0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    unsigned char* hkOArchive_getByteSwap(unsigned char* output);
};
// @fnv 0x00d607d0
// pdb: hkOArchive::getByteSwap | hkOArchive.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
unsigned char* FnvCpu_FUN_00d607d0_CpuObject::hkOArchive_getByteSwap(unsigned char* output)
{
    *output = value;
    return output;
}

struct FUN_00d60800_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00d60800();
};
// @fnv 0x00d60800
// pdb: hkClassMember::getEnumType | hkClassMember.obj | fnv360_0822_retail, objrun_open, low
void* FUN_00d60800_class::FUN_00d60800()
{
    return m_8;
}

class hkMemoryAllocatorDBA;

struct hkMemoryRouterDBA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBA* m_pStreamAllocator;
    hkMemoryAllocatorDBA& heap()
    {
        return *m_pStreamAllocator;
    }
};
