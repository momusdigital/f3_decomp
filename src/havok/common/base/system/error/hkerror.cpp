#include "f3_common.h"
// src/havok/common/base/system/error/hkerror.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/error/hkerror.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
};
struct ErrorReporter
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int Report(int severity, unsigned int category, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
// Builds a reference-count error message from object and context, reports it via DAT_01268360, and breaks if reporting returns nonzero.
// @f3 0x009230c0 (community match, verified in this file)
struct S_Text
{
    S_Text* FUN_00943710(const char* text);
    S_Text* FUN_00943670(const void* value);
    S_Text* FUN_009437d0(int value);
};
struct S_Buf
{
    void FUN_00923070(char* storage, unsigned int size);
    void FUN_00943a60();
};
extern ErrorReporter* DAT_010f3364;

// pdb: hkReferenceCountError | hkError.obj | fnv360_0822_retail, ustr, high
// pdb params: o, why
// pdb: hkReferenceCountError | hkError.obj | fnv360_0822_retail, ustr, high (was: ReportReferenceCountError)
void __cdecl hkReferenceCountError(const void* object, const char* context)
{
    CharBuffer message;
    unsigned int storage[128];
    ((S_Buf*)&message)->FUN_00923070((char*)storage, 0x200);
    int referenceCount = *(const short*)((const char*)object + 6);
    ((S_Text*)&message)
        ->FUN_00943710("Reference count error on object ")
        ->FUN_00943670(object)
        ->FUN_00943710(" with ref count of ")
        ->FUN_009437d0(referenceCount)
        ->FUN_00943710(" in ")
        ->FUN_00943710(context)
        ->FUN_00943710(".\n")
        ->FUN_00943710(" * Are you calling delete instead of removeReference?\n")
        ->FUN_00943710(" * Have you called removeReference too many times?\n")
        ->FUN_00943710(" * Is this a valid object?\n")
        ->FUN_00943710(" * Do you have more than 32768 references? (unlikely)\n");
    DAT_010f3364->Report(3, 0x2c66f2d8, (char*)storage, ".\\System\\Error\\hkError.cpp", 0x1e);
    ((S_Buf*)&message)->FUN_00943a60();
}


struct CB1600Bool
{
    char m_cBooleanValue;

    CB1600Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class CB1600ReferencedObject
{
  public:
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void removeReference();
};

class CB1600MemoryStreamWriter : public CB1600ReferencedObject
{
  public:
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }

    CB1600MemoryStreamWriter(void* buf, int bufSize, CB1600Bool isString);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkClass;
class hkStatisticsCollector;
// hkOstream: the three slots of the Fallout 3 vtables of hkOstream (0x00e7a270) and hkErrStream (0x00e36a08).
class CB1600StreamBase
{
  public:
    CB1600StreamBase(void* writer);
    virtual ~CB1600StreamBase();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

    int unk04;
    CB1600MemoryStreamWriter* m_pStreamWriter;
};

class FUN_00cb1600 : public CB1600StreamBase
{
  public:
    FUN_00cb1600(void* buf, int bufSize);
};

// Constructs a CB1600MemoryStreamWriter in place at the end of the buffer and stores it as the stream's writer, then removes its reference.
// @f3 0x00923070 (community match, verified in this file)
// pdb: hkErrStream::hkErrStream | hkError.obj | fnv360_0822_retail, uvref, high
// pdb params: buf, bufSize
FUN_00cb1600::FUN_00cb1600(void* apBuffer, int aiBufferSize) : CB1600StreamBase(0)
{
    CB1600MemoryStreamWriter* writer =
        new (static_cast<char*>(apBuffer) + aiBufferSize - sizeof(CB1600MemoryStreamWriter))
            CB1600MemoryStreamWriter(apBuffer, aiBufferSize - sizeof(CB1600MemoryStreamWriter), true);
    m_pStreamWriter = writer;
    if (writer->m_usMemSizeAndFlags != 0)
    {
        writer->m_sReferenceCount += 1;
    }
}


struct S_00cb17b0_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00cb17b0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb17b0_Allocator* m_pStreamAllocator;
    S_00cb17b0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00cb17b0_Router* FUN_00c85750();
struct S_00cb17b0_RefObj
{
    virtual ~S_00cb17b0_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p)
    {
        S_00cb17b0_RefObj* b = static_cast<S_00cb17b0_RefObj*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct DiagBuffer
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_buf[128];
    void FUN_00cb1600(unsigned int* buf, unsigned int size) throw();
    void FUN_00cc01c0(const char* s) throw();
    void FUN_00cc00e0() throw();
};

struct DiagLogger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Report(int level, unsigned int hash, const char* msg, const char* file, int line);
};

extern const char str_010c85ac[];

// @f3 0x009231a0 (community match, verified in this file)
// pdb: hkErrorMessage | hkError.obj | fnv360_0822_retail, uconst + bridge(uconst|uconst) + skyrim(uconst), high
void hkErrorMessage(const char* apMsg)
{
    DiagBuffer buf;
    buf.FUN_00cb1600(buf.m_buf, 0x200);
    buf.FUN_00cc01c0(apMsg);
    ((DiagLogger*)DAT_01268360)->Report(3, 0x2636fe25, (const char*)buf.m_buf, str_010c85ac, 0x25);
    buf.FUN_00cc00e0();
}

