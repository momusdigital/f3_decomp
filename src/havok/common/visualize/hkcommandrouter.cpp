#include "f3_common.h"
// src/havok/common/visualize/hkcommandrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkcommandrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd95b0_Source
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual int GetBytes(const char** bytes, int* count);
};
struct FUN_00cb18f0_t
{
    int unk00;
    int unk04;
    int FUN_00cb1fb0(int value);
};
struct FUN_00dd95b0_Outer
{
    int unk00;
    int unk04;
    FUN_00cb18f0_t output;
    void FUN_00dd95b0(FUN_00dd95b0_Source* source);
};
// Gets a byte buffer and count from source and feeds each byte to output.FUN_00cb1fb0.
// @fnv 0x00dd95b0
// pdb: hkCommandRouter::unregisterProcess | hkCommandRouter.obj | fnv360_0822_retail, call_seq, medium
// pdb params: handler
void FUN_00dd95b0_Outer::FUN_00dd95b0(FUN_00dd95b0_Source* source)
{
    int count;
    const char* bytes;
    bytes = 0;
    count = 0;
    source->GetBytes(&bytes, &count);
    for (int i = 0; i < count; ++i)
        output.FUN_00cb1fb0((unsigned char)bytes[i]);
}

struct InputProvider
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void GetData(unsigned char** data, int* length);
};
struct MessageSink
{
    void __thiscall FUN_00cb1870(void* active, unsigned int value, InputProvider* source);
};
struct MessageProcessor
{
    void* unk00;
    void* unk04;
    MessageSink sink;
    void __thiscall ProcessInputData(InputProvider* source);
};
// Reads a byte buffer from source and, for each byte, fetches a MessageContext and passes its active pointer with the byte to sink.FUN_00cb1870.
// @f3 0x00a615c0 (community match, verified in this file)
struct FUN_00922710_Sink
{
    void __thiscall FUN_00922710(int value, InputProvider* source);
};

// pdb: hkCommandRouter::registerProcess | hkCommandRouter.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: hkMapBase<unsigned long,unsigned long,hkMapOperations<unsigned long> >::reserve)
// pdb params: handler
void MessageProcessor::ProcessInputData(InputProvider* source)
{
    unsigned char* bytes = 0;
    int length = 0;

    source->GetData(&bytes, &length);

    for (int index = 0; index < length; ++index)
    {
        reinterpret_cast<FUN_00922710_Sink*>(&sink)->FUN_00922710(bytes[index], source);
    }
}


// Havok Visual Debugger: server-side command dispatch loop (hkServerProcessHandler-style).

typedef unsigned char hkUint8;
typedef unsigned __int64 hkUint64;

struct S_00dd9660_Bool
{
    char m_cBooleanValue;
    S_00dd9660_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) S_00dd9660_Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00dd9660_Heap
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00dd9660_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_00dd9660_Heap* m_pStreamAllocator;

    static S_00dd9660_Router& _FUN_00c85750() throw();
    S_00dd9660_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

int __cdecl FUN_00c908c0(S_00dd9660_Heap& alloc, void* arr, int reqCapacity, int elemSize) throw();

struct S_00dd9660_CharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00dd9660_Heap& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(char));
        }
    }
    __forceinline void _setSize(S_00dd9660_Heap& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(S_00dd9660_Router::_FUN_00c85750().heap(), n);
    }
    __forceinline void _clearAndDeallocate(S_00dd9660_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(char));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00dd9660_CharArray() throw()
    {
        _clearAndDeallocate(S_00dd9660_Router::_FUN_00c85750().heap());
    }
    char& operator[](int i)
    {
        return m_data[i];
    }
};

struct S_00dd9660_InplaceCharArray : S_00dd9660_CharArray
{
    // 128 chars of inline storage, as words so /GS treats it like Havok's build (no cookie)
    unsigned int m_kStorage[32];

    __forceinline S_00dd9660_InplaceCharArray() throw()
    {
        m_data = (char*)m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 128 | 0x80000000;
    }
};

struct S_00dd9660_StringBuf
{
    S_00dd9660_InplaceCharArray m_kStringBuffer;

    __forceinline S_00dd9660_StringBuf() throw()
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    __forceinline void clear() throw()
    {
        m_kStringBuffer[0] = 0;
    }
    void FUN_00d61d00(const char* fmt, ...) throw();
};

struct S_00dd9660_StreamReader;

struct S_00dd9660_IArchive
{
    int unk00;
    int unk04;
    S_00dd9660_StreamReader* m_pStreamReader;
    char m_bStreamResult;

    void FUN_00dd8fe0(void* buf, int elemSize, int nelem);
    void FUN_00ddac60(S_00dd9660_Vector4& v);
    S_00dd9660_Bool GetStreamResult();

    __forceinline hkUint8 read8u()
    {
        hkUint8 c;
        FUN_00dd8fe0(&c, 1, 1);
        return c;
    }
    __forceinline hkUint64 read64u()
    {
        hkUint64 c;
        FUN_00dd8fe0(&c, 8, 1);
        return c;
    }
};
