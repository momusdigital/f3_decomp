#include "f3_common.h"
// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __fastcall FUN_00d2d890(void* self, int, void*, int);
void __fastcall CallWithValueSource(void* self, int, int, int);
void __fastcall FUN_00d2d430(void* self, int, int, int);
void __fastcall FUN_00d2d480(void* self, int, int, int);

extern "C" void __cdecl hkAgent1nMachine_WarpTime(void*, float, float, int);
// @fnv 0x00d2d480
// pdb: hkBvTreeAgent3::warpTime | hkpBvTreeAgent3.obj | tesv_win, objrun_sim, low
void __cdecl FUN_00d2d480(void*, void* target, float first, float second, int flags)
{
    hkAgent1nMachine_WarpTime(target, first, second, flags);
}

struct LessU32
{
    int pad;
    bool operator()(unsigned a, unsigned b) const
    {
        return a < b;
    }
};

// Partitions pArr[d..h] around a middle pivot using cmpLess, swapping out-of-order elements, then recurses on the left part and loops on the right.
// @fnv 0x00d2da70
// pdb: hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int> > | hkpBvTreeAgent3.obj | fnv360_0822_retail, call_seq, high
// pdb params: pArr, d, h, cmpLess
extern "C" void __cdecl QuickSortRange(unsigned* auiArray, int aiLow, int aiHigh, LessU32 aComparator)
{
setpoint:
    int iRight = aiHigh;
    int iLeft = aiLow;
    __declspec(align(16)) unsigned pivot = auiArray[(aiLow + aiHigh) >> 1];
    do
    {
        while (aComparator(auiArray[iLeft], pivot))
            iLeft++;
        while (aComparator(pivot, auiArray[iRight]))
            iRight--;
        if (iRight >= iLeft)
        {
            if (iRight != iLeft)
            {
                unsigned t = auiArray[iRight];
                auiArray[iRight] = auiArray[iLeft];
                auiArray[iLeft] = t;
            }
            iRight--;
            iLeft++;
        }
    } while (iLeft <= iRight);
    if (aiLow < iRight)
        QuickSortRange(auiArray, aiLow, iRight, aComparator);
    if (iLeft < aiHigh)
    {
        aiLow = iLeft;
        goto setpoint;
    }
}

struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};

struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// Calls f4 on the ValueSource, fills a CallBuf with the arguments and result, then passes it to hkAgent1nMachine_UpdateShapeCollectionFilter with p2.
// @f3 0x009b4bd0 (community match, verified in this file)
struct SourceDispatch {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    int (__thiscall* GetValue)(ValueSource*);
};
void __cdecl FUN_00a2b420(void*, CallBuf*);
// pdb: hkBvTreeAgent3::updateFilter | hkpBvTreeAgent3.obj | tesv_win, objrun_prop, low
void __cdecl CallWithValueSource(void* unused, void* target, int arg0, ValueSource** source, int arg1, int arg2, int arg3)
{
    int result = (*(SourceDispatch**)*source)->GetValue(*source);
    CallBuf buffer;
    buffer.unk00 = arg0;
    buffer.unk04 = source;
    buffer.unk10 = arg1;
    buffer.unk14 = arg2;
    buffer.unk0c = result;
    buffer.unk18 = arg3;
    FUN_00a2b420(target, &buffer);
}


struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int m_kind;            // 0x0c
    unsigned char m_flag;  // 0x10
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    void* m_ptr18;  // 0x18
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_ptr34;  // 0x34
};

// Returns a pointer stored in the object based on its kind: m_ptr18 for kind 8 when m_flag is 1, m_ptr34 for kind 10, otherwise null.
// @fnv 0x00d2d4c0
void* __cdecl GetSpawnedObjectPointer(void** holder)
{
    SpawnedObject* obj = (SpawnedObject*)*holder;
    switch (obj->m_kind)
    {
    case 8:
        if (obj->m_flag == 1)
        {
            return obj->m_ptr18;
        }
        return 0;
    case 10:
        return obj->m_ptr34;
    default:
        return 0;
    }
}

struct Agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char* typeName);
    virtual void f7();
};

extern "C" void __cdecl FUN_00d97250(int, int, void*);

// Calls p->f6 with the type name hkBvTreeAgent3, then FUN_00d97250 with a2, a3 and p, then p->f7().
// @f3 0x009b4b50 (community match, verified in this file)
struct AgentViewD430
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void SetTypeName(const char* typeName);
    virtual void v5();
};

void __cdecl FUN_00d2d430(int a1, int a2, int a3, Agent* pAgent)
{
    AgentViewD430* p = (AgentViewD430*)pAgent;
    p->SetTypeName("hkBvTreeAgent3");
    FUN_00d97250(a2, a3, pAgent);
    p->v5();
}


extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ce7ec[];
extern "C" const char str_010ce7e0[];
extern "C" const char str_010ce7d4[];
extern "C" const char str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;

struct S00d2d890_Rec
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
    const char* tag;
};
struct S00d2d890_Buf
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct __declspec(align(16)) S00d2d890_Local
{
    int b00;
    int b01;
    int b02;
    int b03;
    int b04;
    int b05;
    int b06;
    int b07;
    int b08;
    int b09;
    int b0a;
    int b0b;
    int b0c;
    int b0d;
    int b0e;
    int b0f;
    S00d2d890_Local()
    {}
    void FUN_00cb21e0(void* a);
};
struct S00d2d890_Rec3
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
};
int FUN_00d2d4f0(int a, int b, S00d2d890_Local* l, void* c, int d, int e, char* f, int g);

// Takes 0x4000 bytes from an arena, calls FUN_00d2d4f0, FUN_00d2d4b0 and FUN_00da4aa0 between timing markers, restores the arena and returns child + 0x10.
// @f3 0x009b5700 (community match, verified in this file)
extern unsigned long DAT_010f3170;
int FUN_009b4c20(int a);
void FUN_00a2b910(char* a, char* b, void* c, int d, char* e, int f);

struct S00d2d890_TMem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void* vAlloc(int size);
    virtual void vFree(void* p);
    virtual void v07();
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    char* m_cur;
    int m_unk24;
    char* m_base;
    char* m_end;
};

// pdb: hkBvTreeAgent3::process | hkpBvTreeAgent3.obj | fnv360_0822_retail, strset, low
// pdb params: input, entry, agentData, separatingNormal, output
char* __cdecl FUN_00d2d890(char* self, int a1, char* child, int a3, int a4)
{
    volatile unsigned int tb;
    S00d2d890_Buf* t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec* r = (S00d2d890_Rec*)t->cur;
        r->name = str_010ce7ec;
        r->tag = str_010ce7e0;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    S00d2d890_TMem* tm = (S00d2d890_TMem*)TlsGetValue(DAT_010f3170);
    char* mark = tm->m_cur;
    if (mark + 0x4010 <= tm->m_end)
        tm->m_cur = mark + 0x4010;
    else
        mark = (char*)tm->vAlloc(0x4010);
    S00d2d890_Local loc;
    loc.FUN_00cb21e0(self + 0x10);
    int c = *(int*)(self + 8);
    int p1 = *(int*)(self + 4);
    int p0 = *(int*)self;
    int numHits = FUN_00d2d4f0(p0, p1, &loc, self + 0x60, c, 0, mark, 0x1000);
    int tree = *(int*)(self + 4);
    int r4b = FUN_009b4c20(tree);

    t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec3* r = (S00d2d890_Rec3*)t->cur;
        r->name = str_010ce7d4;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    char* cond = numHits < 0 ? 0 : mark;
    FUN_00a2b910(child, (char*)((int)child + *(int*)(self + 0x54)), self, (*(volatile int*)&r4b), cond, a4);
    t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec3* r = (S00d2d890_Rec3*)t->cur;
        r->name = str_01076f38;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    char* ret = child + 0x10;
    tm = (S00d2d890_TMem*)TlsGetValue(DAT_010f3170);
    tm->m_cur = mark;
    if (mark == tm->m_base)
        tm->vFree(mark);
    return ret;
}


__declspec(noinline) void FUN_00d2d9d0(void* pObject);

struct __declspec(align(16)) S_00d2da20_AgentFuncs
{
    void* m_pCreateFunc;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* unk2C;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
    bool unk32;
    S_00d2da20_AgentFuncs()
    {
        m_bIsFlipped = false;
        m_bIsPredictive = false;
        unk32 = false;
        unk18 = 0;
        unk1C = 0;
        unk20 = 0;
        unk24 = 0;
        unk28 = 0;
    }
};
