#include "f3_common.h"
// src/havok/common/base/system/error/hkdefaulterror.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/error/hkdefaulterror.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00626490_Class
{
    int LookupHashEntry(int first, int second);
};
struct FUN_00d2b3b0_Class
{
    int unk00;
    int unk04;
    FUN_00626490_Class helper;
    unsigned char* FUN_00d2b3b0(unsigned char* result, int value);
};
// @fnv 0x00d2b3b0
// pdb: hkDefaultError::isEnabled | hkDefaultError.obj | fnv360_0822_retail, vtable, medium
// pdb params: id
unsigned char* FUN_00d2b3b0_Class::FUN_00d2b3b0(unsigned char* result, int value)
{
    *result = (helper.LookupHashEntry(value, 0) == 0);
    return result;
}

struct D2B3D0Map
{
    void clear();
};

struct D2B3D0Owner
{
    int unk00;
    int unk04;
    D2B3D0Map m_map;

    void FUN_00d2b3d0();
};

// @fnv 0x00d2b3d0
void D2B3D0Owner::FUN_00d2b3d0()
{
    m_map.clear();
}

struct FUN_00c85750_return
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
FUN_00c85750_return* __cdecl FUN_00c85750();

namespace fnv_00d2b710 {
struct ManagerVTable
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void notify(void* object, unsigned short value);
};
struct AudioState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ManagerVTable* unk10;
};
extern AudioState* __cdecl FUN_00c85750();
}  // namespace fnv_00d2b710

struct D2B600Allocator;

struct D2B600MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2B600Allocator* m_pStreamAllocator;

    D2B600Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D2B600MemoryRouter& __cdecl D2B600GetMemoryRouter();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D2B600Object
{
    int unk00;
};

struct D2B600ObjectArray
{
    D2B600Object** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void construct(D2B600Object** p, int n, D2B600Object* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void AddBack(D2B600Object* const& e)
    {
        D2B600Allocator& alloc = D2B600GetMemoryRouter().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D2B600Object*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct S_00d2b3e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void(__cdecl* m_callback)(const char*, int);
    int m_user;
    void hkDefaultError_showMessage(const char* kind, int code, const char* msg, const char* file, int line, char trace);
};

// Formats a message with optional file/line/code/kind, invokes m_callback, and optionally dumps a stack trace via DAT_01269a84.
// @f3 0x0092f010 (community match, verified in this file)
struct D3Str
{
    int unk00;
    int unk04;
    int unk08;
};
struct D3Flag
{
    unsigned char v;
    D3Flag(bool b) : v(b ? 1 : 0)
    {}
    D3Flag(const D3Flag& o) : v(o.v)
    {}
};
struct D3Out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void FUN_009a8fd0(char* buf, int size, D3Flag own);
    void FUN_009a9120();
};
struct D3Trace
{
    int unk00;
    int unk04;
    void FUN_009af940();
    int FUN_009af930(void** frames, int max);
    void FUN_009af7a0(void** frames, int count, void(__cdecl* cb)(const char*, int), int user);
    void FUN_009afa50();
};
struct D3Stream
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00943a00(D3Out* out);
    D3Stream* FUN_00943710(const void* s);
    D3Stream* FUN_009436f0(char c);
    D3Stream* FUN_009437d0(int v);
    void FUN_00943a60();
};
void __cdecl FUN_009232a0(D3Str* out, const char* fmt, int v);

// pdb: hkDefaultError::showMessage | hkDefaultError.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void S_00d2b3e0::hkDefaultError_showMessage(const char* kind, int code, const char* msg, const char* file, int line, char trace)
{
    D3Trace tr;
    D3Stream st;
    D3Str num;
    D3Out out;
    void* frames[20];
    int output[128];
    int count;

    FUN_009232a0(&num, "0x%x", code);
    out.FUN_009a8fd0((char*)output, 512, D3Flag(true));
    st.FUN_00943a00(&out);
    st.FUN_00943710(file)->FUN_009436f0('(')->FUN_009437d0(line)->FUN_00943710("): [")->FUN_00943710(&num)->FUN_00943710("] ")->FUN_00943710(kind)->FUN_00943710(" : '")->FUN_00943710(msg)->FUN_00943710("'\n");
    m_callback((char*)output, m_user);
    if (trace)
    {
        tr.FUN_009af940();
        count = tr.FUN_009af930(frames, 20);
        if (count > 2)
        {
            m_callback("Stack trace is:\n", m_user);
            tr.FUN_009af7a0(frames + 2, count - 2, m_callback, m_user);
        }
        tr.FUN_009afa50();
    }
    st.FUN_00943a60();
    out.FUN_009a9120();
}


struct FUN_00d2b5b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void FUN_00d2b5b0();
};
// @fnv 0x00d2b5b0
// pdb: hkDefaultError::sectionEnd | hkDefaultError.obj | fnv360_0822_retail, vtable, medium
void FUN_00d2b5b0_Class::FUN_00d2b5b0()
{
    unk18--;
}

struct Bool8
{
    unsigned char value;
    Bool8()
    {}
    Bool8(bool v) : value(v ? 1 : 0)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

struct D2ErrorHost
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Bool8 v14(int value);
    int unk04, unk08, unk0c, unk10;
    struct Array
    {
        int* data;
        int size;
        int GetLogicalSize() const
        {
            return size;
        }
        int back() const
        {
            return data[size - 1];
        }
    } items;
    void hkDefaultError_showMessage(const char* name, int key, int a3, int a4, int a5, Bool8 flags);
    int FUN_00d2b4f0(int mode, int index, int a3, int a4, int a5);
};

// Resolves index to last item if -1, validates it via v14, maps mode to a name and flag, calls hkDefaultError_showMessage, returns 1 for modes 2 or 3.
// @fnv 0x00d2b4f0
// pdb: hkDefaultError::message | hkDefaultError.obj | fnv360_0822_retail, vtable, medium
// pdb params: msg, id, description, file, line
int D2ErrorHost::FUN_00d2b4f0(int mode, int index, int aiArg3, int aiArg4, int aiArg5)
{
    if (index == -1)
    {
        if (items.GetLogicalSize() != 0)
            index = items.back();
    }
    if (!v14(index))
        return 0;
    const char* name = "";
    Bool8 flag(false);
    switch (mode)
    {
    case 0:
        name = "Report";
        break;
    case 1:
        name = "Warning";
        break;
    case 2:
        name = "Assert";
        flag = true;
        break;
    case 3:
        name = "Error";
        flag = true;
        break;
    }
    hkDefaultError_showMessage(name, index, aiArg3, aiArg4, aiArg5, flag);
    if (mode == 2 || mode == 3)
        return 1;
    return 0;
}
