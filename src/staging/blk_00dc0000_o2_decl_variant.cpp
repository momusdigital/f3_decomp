#include "f3_common.h"
// src/staging/blk_00dc0000_o2_decl_variant.cpp - declaration variant unit created 2026-10-27 by decl_variants.py for paused function 0x00dcc820: the skeleton of src/staging/blk_00dc0000_o2.cpp
// with declarations corrected to what the original code does (unit: static __declspec(noinline) unsigned short readInteger64(unsi -> static __declspec(noinline) __int64 readInteger64(unsigned ch). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00dc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
template <class K, class V, class O> class HashEntryTable
{
  public:
    void clear();
};
template <class K> struct KeyMarker
{
};
struct AllocatorState
{
    int unk00, unk04, unk08, unk0C;
    void* pool;
    void* GetPool() const
    {
        return pool;
    }
};
extern "C" AllocatorState* __cdecl FUN_00c85750();
// FUN_00dd5150: initialises six float members of the object: five of them to
// 1.0 and the last one to the global float constant DAT_01016248; returns the
// object pointer.
// Constructor for the object handled by FUN_00dd7110.
//
// The class holds a run of scalar members; every one of them is zeroed by the
// constructor except m_iUninitialised08, which is left for the caller to fill
// in later.  The ten members cleared through the initialiser list are stored
// first (in declaration order), the two cleared in the constructor body are
// stored afterwards.
struct S_00dd8cf0_Ret
{
    bool v;
    S_00dd8cf0_Ret()
    {}
};
// Object built by Construct: it installs its own vtable, clears a couple
// of members and then hands the object over to FUN_00dd7f10 for a full reset.
struct SpawnedObject
{
    int* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int* m_a4;
    int* m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    void FUN_00dd7f10();
    SpawnedObject* Construct(int value);
};
void SpawnedObject::FUN_00dd7f10()
{
    m_c0 = 0;
    m_bc = 0;
    m_08 = 0;
    m_0c = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
    m_8c = 0;
    m_90 = 0;
    m_94 = 0;
    m_9c = 0;
    m_14 = 0;
    m_a0 = 3;
    m_10 = (int*)&m_9c;
    m_a8 = (int*)&m_a4;
    m_a4 = (int*)&m_a4;
}
struct IniTokenStream
{
    void* m_vt;
};
extern "C" void ReadIniLine(void);
// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) unsigned short readInteger64(IniTokenStream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (unsigned short)(int)(stream != 0);
}
extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);
struct Bool1
{
    char v;
    Bool1(char x) : v(x)
    {}
};
struct S_00dcc240_Reader
{
    int unk00;
    int unk04;
    unsigned short unk08;
};
extern "C" void __cdecl eatWhiteSpace(void);
// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) __int64 readInteger64(unsigned char* ok, S_00dcc240_Reader* reader)
{
    *ok = 0;
    eatWhiteSpace();
    return reader->unk08;
}
typedef __int64 FNVInt64;
struct S_00dcc8a0_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};
struct S_00dcc8a0_Handle
{
    S_00dcc8a0_Reader* reader;
};
static __declspec(noinline) FNVInt64 S_00dcc8a0_ParseInt(S_00dcc8a0_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_00dcc8a0_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}
struct hkEntryDCB1
{
    int m_uiFilterValue;
    int m_04;
};
struct hkTableDCB1
{
    int m_00;
    int m_04;
    int m_08;
    hkEntryDCB1* m_entries;
};
class hkOwnerDCB1;
struct hkRefDCB1
{
    const hkOwnerDCB1* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDCB1(const hkOwnerDCB1* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};
class hkOwnerDCB1
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB1* m_table;

    hkRefDCB1 GetEntryRef(int iIndex) const;
};
struct S_00dcc600_Inner
{
    int __thiscall ReadChar();
};
static __declspec(noinline) int S_00dcc600_Reset(S_00dcc600_Inner* stream)
{
    int count = 0;
    int c = stream->ReadChar();

    while (c != -1 && count < 4)
    {
        ++count;
        c = stream->ReadChar();
    }

    return count;
}
struct Bool388
{
    unsigned char value;
    Bool388()
    {}
    Bool388(unsigned char v) : value(v)
    {}
};
struct Block388
{
    unsigned int previousSize, sizeAndFlags;
    unsigned char Flags() const
    {
        return reinterpret_cast<const unsigned char*>(&sizeAndFlags)[0];
    }
};
class hkMemoryAllocatorDDFB;
struct hkMemoryRouterDDFB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDDFB* m_pStreamAllocator;
    hkMemoryAllocatorDDFB& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDDFB {
extern "C" hkMemoryRouterDDFB& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
struct hkPairDDFB
{
    void* m_object;
    void* m_key;

    hkPairDDFB(void* object, void* key) : m_object(object), m_key(key)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};
template <class T> class hkArrayDDFB
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDDFB& kAlloc = hkRouterDDFB::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};
struct stub_cls
{
    int unk00;
    int unk04;
};
static stub_cls* volatile g_stub_self;
static int volatile g_stub_v;
static int volatile g_stub_out;
// ReadSignedInt: thiscall member returning this; parses an int through readInteger64
// (per-TU private convention: stream on the stack, sign-flag address in EAX),
// negates it when the flag byte is set, and stores it through the int* argument.
struct S_00dcc7e0_Stream
{
    void* m_vt;
};
extern "C" void ReadIniLine(void);
// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) int readInteger64(S_00dcc7e0_Stream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (int)(stream != 0);
}
typedef __int64 FNVInt64;
struct S_dcc860_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};
struct S_dcc860_Handle
{
    S_dcc860_Reader* reader;
};
static __declspec(noinline) FNVInt64 S_dcc860_ParseInt(S_dcc860_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_dcc860_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}
struct S00dcd270_Rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
    int unk24;
    void* unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct S00dcd270_Arr
{
    S00dcd270_Rec* m_data;
    int m_iElementCount;
    int m_cap;
};
extern "C" void __cdecl ResizeAudioStream(void*, S00dcd270_Arr*, int);
class hkBoolDD8
{
  public:
    hkBoolDD8(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct MemChunkDD8
{
    enum
    {
        PINUSE_BIT = 1,
        CINUSE_BIT = 2,
        INUSE_BITS = 3,
        PAYLOAD_OFFSET = 16
    };
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;
    hkBoolDD8 isInuse() const
    {
        return (head & CINUSE_BIT) != 0;
    }
    hkBoolDD8 isPinuse() const
    {
        return (head & PINUSE_BIT) != 0;
    }
    unsigned int getChunkSize() const
    {
        return head & ~(unsigned int)INUSE_BITS;
    }
    const MemChunkDD8* chunkPlusOffset(unsigned int s) const
    {
        return (const MemChunkDD8*)((const char*)this + s);
    }
    const MemChunkDD8* chunkMinusOffset(unsigned int s) const
    {
        return (const MemChunkDD8*)((const char*)this - s);
    }
    static const MemChunkDD8* toChunk(const void* in)
    {
        return (const MemChunkDD8*)((const char*)in - PAYLOAD_OFFSET);
    }
};

struct S_00dcc820_Class
{
    unsigned int m_00;
    unsigned int m_04;
    S_00dcc240_Reader* m_08;

    S_00dcc820_Class* __thiscall FUN_00dcc820(int* result);
};
extern "C" void __cdecl eatWhiteSpace(void);
// @fnv 0x00dcc820
// pdb: hkIstream::operator>> | hkIStream.obj | tesv_win, objrun_sim, low
S_00dcc820_Class* __thiscall S_00dcc820_Class::FUN_00dcc820(int* result)
{
    unsigned char ok;
    int value = readInteger64(&ok, m_08);

    *result = ok ? -value : value;
    return this;
}
