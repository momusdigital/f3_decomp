#include "f3_common.h"
// src/havok/physics/dynamics/world/util/hkpworldmemoryutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldmemoryutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d01bc0_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool v8(int key);
};

struct S_00d01bc0_Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00d01bc0_Sink* m_sink;
    S_00d01bc0_Sink* sink()
    {
        return m_sink;
    }
};

struct InnerObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* param);
};

struct ParamObj;

struct ChildObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;
};

struct ParamObj
{
    int unk00;
    int unk04;
    ChildObj* m_08;

    InnerObj* FUN_00c93570();
};

#include <windows.h>

extern "C" void _ReadWriteBarrier(void);

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

unsigned __int64 __cdecl __rdtsc(void);

// If GetA is non-null and vtbl24 returns false, records profiler ticks around a vtbl10 call, then calls FUN_00d88040(0) if DAT_01269200 is set.
// @f3 0x00902ea0 (community match, verified in this file)
#include <windows.h>

extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);

struct D01D20Status;
struct D01D20Task;
struct D01D20Target;

struct D01D20Status
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual unsigned long QueryStatus();
};

struct D01D20Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Execute(const D01D20Target* owner);
    unsigned long unk04;
    unsigned long m_uiBytes;
};

struct D01D20Target
{
    unsigned long unk00;
    unsigned long unk04;
    D01D20Status* m_pStatus;
    unsigned long unk0c;
    unsigned long unk10;
    unsigned long unk14;
    unsigned long unk18;
    unsigned long unk1c;
    unsigned long unk20;
    unsigned long unk24;
    unsigned long unk28;
    unsigned long unk2c;
    unsigned long unk30;
    unsigned long unk34;
    unsigned long unk38;
    unsigned long unk3c;
    unsigned long unk40;
    unsigned long unk44;
    unsigned long unk48;
    unsigned long unk4c;
    D01D20Task* m_pTask;
};

struct D01D20Policy
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual char* Check(char* out, unsigned long bytes);
};

extern D01D20Policy* DAT_010f3400;
extern unsigned long DAT_0116913c;
typedef void* (__stdcall* D01D20TlsFn)(unsigned long);
extern D01D20TlsFn FUN_00d9b080;
extern const char DAT_00e34ba0[];
extern const char FUN_00e32798[];

struct D01D20Rec
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};

struct D01D20Buf
{
    unsigned long unk00;
    D01D20Rec* m_pCur;
    unsigned long unk08;
    D01D20Rec* m_pEnd;
};

__forceinline void D01D20Stamp(D01D20TlsFn tls, const char* name, unsigned long& ticksOut)
{
    D01D20Buf* buf = static_cast<D01D20Buf*>(tls(DAT_0116913c));
    D01D20Rec* rec = buf->m_pCur;
    if (rec < buf->m_pEnd)
    {
        rec->m_pName = name;
        _ReadWriteBarrier();
        volatile unsigned long& ticks = ticksOut;
        ticks = static_cast<unsigned long>(__rdtsc());
        rec->m_iTick = ticks;
        buf->m_pCur = rec + 1;
    }
}

unsigned long __fastcall FUN_00d01d20(const D01D20Target* p)
{
    unsigned long tickSlot;
    unsigned long status = p->m_pStatus->QueryStatus();
    if (status == 0)
    {
        D01D20Task* task = p->m_pTask;
        if (task)
        {
            char value;
            if (*DAT_010f3400->Check(&value, task->m_uiBytes) == 0)
            {
                D01D20TlsFn tls = FUN_00d9b080;
                D01D20Stamp(tls, DAT_00e34ba0, tickSlot);
                task->Execute(p);
                D01D20Stamp(tls, FUN_00e32798, tickSlot);
            }
        }
    }
    return status;
}

