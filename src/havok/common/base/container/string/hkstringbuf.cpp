#include "f3_common.h"
// src/havok/common/base/container/string/hkstringbuf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringbuf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSAudio
{
};
BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int);

class BufferOwner
{
  public:
    char* m_pData;
    unsigned int m_iReferenceCount;
    unsigned int m_uiObjectFlags;

    BufferOwner* InitBuffer();
};

#include <stdarg.h>
struct PolymorphicBase
{
    virtual void v0();
};
struct Router
{
    int unk00;
    int unk04;
    int unk08;
    PolymorphicBase* m_pStreamAllocator;
    PolymorphicBase& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct StringBuf : public BufferOwner
{
    char* Begin()
    {
        return m_pData;
    }
    int GetCapacity() const
    {
        return m_uiObjectFlags & 0x3fffffff;
    }
    void Reserve(PolymorphicBase& alloc, int n)
    {
        const int capacity = GetCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, 1);
        }
    }
    void SetSize(int n)
    {
        Reserve(((Router*)FUN_00c85750())->heap(), n);
        m_iReferenceCount = n;
    }
    void SetLength(int n)
    {
        SetSize(n + 1);
        m_pData[n] = 0;
    }
    void FUN_00d61d00(const char* fmt, ...);
};
// Formats fmt into the buffer with va_list args, growing capacity until the write fits, then null-terminates.
// @f3 0x009236d0 (community match, verified in this file)
#include <stdarg.h>
void __cdecl FUN_00901e90(void* self, int size, int flag);
void __cdecl hkArrayUtil__reduce(void* self, int a, int b, int size);
int __cdecl FUN_00923270(char* buf, int size, const char* fmt, va_list args);
struct StringBufOps : StringBuf
{
    void Grow3(int n)
    {
        const int capacity = GetCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            FUN_00901e90(this, (n < cap2) ? cap2 : n, 1);
        }
    }
    void SetSize3(int n)
    {
        Grow3(n);
        m_iReferenceCount = n;
    }
};
void StringBuf::FUN_00d61d00(const char* fmt, ...)
{
    int n = GetCapacity();
    if (n < 0x3f && n < 0x100)
    {
        n = 2 * n;
        if (n <= 0x100)
            n = 0x100;
        FUN_00901e90(this, n, 1);
    }
    va_list args;
    va_start(args, fmt);
    while (1)
    {
        n = GetCapacity();
        int iChars = FUN_00923270(Begin(), n, fmt, args);
        if (iChars >= 0)
        {
            if (iChars < n)
            {
                m_iReferenceCount = iChars + 1;
                if (iChars + 1 <= GetCapacity())
                    hkArrayUtil__reduce(this, 1, 0, iChars + 1);
                break;
            }
            ((StringBufOps*)this)->SetSize3(iChars + 1);
            continue;
        }
        int t = 2 * n;
        if (t <= 0xff)
            t = 0xff;
        ((StringBufOps*)this)->SetSize3(t + 1);
    }
    va_end(args);
}

