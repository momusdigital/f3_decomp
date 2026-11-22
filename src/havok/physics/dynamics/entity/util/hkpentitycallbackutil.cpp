#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/dynamics/entity/util/hkpentitycallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/util/hkpentitycallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00cff9b0
// pdb: worldCallbackUtil_cleanupNullPointers | hkpWorldCallbackUtil.obj | fnv360_0822_retail, call_gap, high
static void FUN_00cff9b0(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

// Callers so the file-static helper is emitted with its register calling convention.
void CFF9B0CleanupListeners(CFF9B0SmallArray* a, CFF9B0SmallArray* b)
{
    FUN_00cff9b0(*a);
    FUN_00cff9b0(*b);
}

extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    unsigned short size;
    unsigned short capacity;
};
class ActionListenerF3
{
  public:
    virtual ~ActionListenerF3();
    virtual void actionAddedCallback(ContactPointEvent* event);
};
struct ActionArrayF3
{
    ActionListenerF3** data;
    int size;
    int capacity;
};
// hkpWorld: only the members these callbacks read.
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    ActionArrayF3 m_actionListeners;  // +0xF0
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    Array833 contactPointListeners;
};

static __declspec(noinline) void FUN_00cff9b0(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
        }
    }
}
// Invokes HandleContactPointEvent on each non-null contact point listener in world->contactPointListeners, then removes null entries via FUN_00cff9b0.
// @f3 0x009884d0 (community match, verified in this file)
void __cdecl FUN_00cfff00(World833* world, ContactPointEvent* event)
{
    ActionArrayF3& listeners = world->m_actionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            HK_TIMER_BEGIN("actAddCb", HK_NULL);
            listeners.data[i]->actionAddedCallback(event);
            HK_TIMER_END();
        }
    }
    FUN_00cff9b0((Array833&)listeners);
}



extern unsigned long DAT_0126835c;




struct Class_00cffab0;

struct Listener1
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2(Class_00cffab0* obj) = 0;
};

struct Listener2
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual void vfn3() = 0;
    virtual void vfn4(Class_00cffab0* obj) = 0;
};

struct Listener4
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual void vfn3() = 0;
    virtual void vfn4() = 0;
    virtual void vfn5() = 0;
    virtual void vfn6(Class_00cffab0* obj) = 0;
};

struct Container_00cffab0
{
    int unk00;
    int unk04;
    CFF9B0SmallArray listeners;
};

struct ListenerArrayB4
{
    Listener2** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct Class_00cffab0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    CFF9B0SmallArray m_smallArrayAC;
    ListenerArrayB4 m_arrayB4;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    Container_00cffab0* m_container214;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    CFF9B0SmallArray m_smallArray208;

    void UpdateNodeSlotIndices();
};

// Calls vfn2 on the container's listeners, then vfn4 / vfn6 on the other listener arrays until each is empty, with UpdateNodeSlotIndices in between.
// @f3 0x00987de0 (community match, verified in this file)
void __cdecl FUN_00cffab0(Class_00cffab0* obj)
{
    Container_00cffab0* container = obj->m_container214;
    if (container)
    {
        for (int i = container->listeners.m_iElementCount - 1; i >= 0; --i)
        {
            if (container->listeners.m_data[i])
            {
                HK_TIMER_BEGIN("entRemCb", HK_NULL);
                ((Listener1*)container->listeners.m_data[i])->vfn2(obj);
                HK_TIMER_END();
            }
        }
    }

    while (obj->m_smallArrayAC.m_iElementCount)
    {
        HK_TIMER_BEGIN("entRemCb", HK_NULL);
        ((Listener2*)obj->m_smallArrayAC.m_data[0])->vfn4(obj);
        HK_TIMER_END();
    }

    while (obj->m_arrayB4.m_iElementCount)
    {
        HK_TIMER_BEGIN("entRemCb", HK_NULL);
        obj->m_arrayB4.m_data[0]->vfn4(obj);
        HK_TIMER_END();
    }

    while (obj->m_smallArray208.m_iElementCount)
    {
        HK_TIMER_BEGIN("entRemCb", HK_NULL);
        ((Listener4*)obj->m_smallArray208.m_data[0])->vfn6(obj);
        HK_TIMER_END();
    }
}


#include <windows.h>
struct CFFCF0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct CFFCF0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

struct CFFCF0Owner;

struct CFFCF0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void callback(CFFCF0Owner* owner);
};

struct CFFCF0ListenerList
{
    int unk00;
    int unk04;
    CFFCF0Listener** m_kListeners;
    unsigned short m_uiItemCount;
};

struct CFFCF0Owner
{
    char unk000[0x214];
    CFFCF0ListenerList* m_listenerList;
};

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);

unsigned __int64 __cdecl __rdtsc(void);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca44[];
extern char DAT_010c41f8[];
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    int m_08;
    void* m_pObservedSource;
};
struct ListenerOwner
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec, m_1f0, m_1f4, m_1f8, m_1fc;
    CFF9B0SmallArray m_kListeners;
};
// Sets event->m_pObservedSource to owner, calls callback on each non-null listener in reverse with timers, then calls FUN_00cff9b0 to remove null entries.
// @fnv 0x00d00110
void __cdecl FUN_00d00110(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int uiTimerEnd;
            TimerWriteV(DAT_010cca44, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_010c41f8, uiTimerEnd);
        }
    }
    FUN_00cff9b0(kListeners);
}

struct CEvent;
struct CFF9B0SmallArray;
struct CListener
{
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05(CEvent* ev);
};
struct CProfileMarker
{
    const char* m_name;
    unsigned int m_tsc;
    unsigned int m_unk08;
};
struct CProfileTls
{
    int m_unk00;
    CProfileMarker* m_cur;
    int m_unk08;
    CProfileMarker* m_kRayEnd;
};
struct CEvent
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pOwnerObject;
};
extern unsigned int g_tcpTlsIndex;
static void __declspec(noinline) FUN_00cff9b0(CFF9B0SmallArray& a);
struct CManager
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    CFF9B0SmallArray m_kListeners;
};
// Sets ev->m_pOwnerObject to mgr, iterates mgr->m_kListeners in reverse calling m05 on each CListener with ev, then calls FUN_00cff9b0 on the listener array.
// @fnv 0x00d001c0
void FUN_00d001c0(CManager* mgr, CEvent* ev)
{
    CFF9B0SmallArray* list = &mgr->m_kListeners;
    ev->m_pOwnerObject = mgr;

    for (int i = list->m_iElementCount - 1; i >= 0; i--)
    {
        if (!list->m_data[i])
            continue;

        {
            CProfileTls* tls = (CProfileTls*)TlsGetValue(g_tcpTlsIndex);
            if (tls->m_cur < tls->m_kRayEnd)
            {
                CProfileMarker* marker = tls->m_cur;
                marker->m_name = "TtcpRemCb";
                _ReadWriteBarrier();
                volatile unsigned int timestamp = (unsigned int)__rdtsc();
                marker->m_tsc = timestamp;
                tls->m_cur = marker + 1;
            }
        }

        ((CListener*)list->m_data[i])->m05(ev);

        {
            CProfileTls* tls = (CProfileTls*)TlsGetValue(g_tcpTlsIndex);
            if (tls->m_cur < tls->m_kRayEnd)
            {
                CProfileMarker* marker = tls->m_cur;
                marker->m_name = "Et";
                _ReadWriteBarrier();
                volatile unsigned int timestamp = (unsigned int)__rdtsc();
                void* p = (void*)&timestamp;
                marker->m_tsc = timestamp;
                tls->m_cur = marker + 1;
            }
        }
    }

    FUN_00cff9b0(*list);
}

extern DWORD DAT_0126835c;
// string literals used inline
// (see below)

unsigned __int64 __cdecl __rdtsc(void);



class ListItem_cffa00
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void* pOwner);
};

struct ItemList_cffa00
{
    DWORD unk00;
    DWORD unk04;
    ListItem_cffa00** m_ppItems;
    WORD m_wCount;
};

// hkpEntity: only the member these callbacks read.
struct ProfOwner_cffa00
{
    DWORD unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    DWORD unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    DWORD unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    DWORD unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    DWORD unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    DWORD unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    DWORD unk0C0, unk0C4, unk0C8;
    ItemList_cffa00* m_extendedListeners;  // +0xCC
};

// Iterates pOwner->m_pItems in reverse, writing TtentAddCb/Et rdtsc ticks to the TLS ProfBuf and calling vtbl04 on each item.
// @f3 0x00987d30 (community match, verified in this file)
// pdb: hkpWorldCallbackUtil::fireEntityAdded | hkpWorldCallbackUtil.obj | fnv360_0721_beta, ustr_rel, low, conflict (skyrim: hkpEntityCallbackUtil::fireEntityAdded)
// pdb params: world, entity
void __cdecl FUN_00cffa00(ProfOwner_cffa00* pOwner)
{
    ItemList_cffa00* pList = pOwner->m_extendedListeners;
    if (pList != 0)
    {
        for (int i = (int)pList->m_wCount - 1; i >= 0; i--)
        {
            if (pList->m_ppItems[i] != 0)
            {
                HK_TIMER_BEGIN("entAddCb", HK_NULL);
                pList->m_ppItems[i]->vtbl04(pOwner);
                HK_TIMER_END();
            }
        }
    }
}


extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
struct TraceTick
{
    volatile DWORD value;
    __forceinline void Record()
    {
        value = (DWORD)__rdtsc();
    }
    __forceinline DWORD Read() const
    {
        return value;
    }
};
struct ItemObj
{
    virtual void v00();
    virtual void v04(void* pParam);
};
struct ItemTable
{
    ItemObj** m_ppItems;
    WORD m_wCount;
};
// Iterates the owner's item table in reverse, calling each item's v04 with apParam and recording TtNewCollCb and Et profiler ticks.
// @fnv 0x00cfffb0
void __cdecl FUN_00cfffb0(void* apOwner, void* apParam)
{
    ItemTable* pItemTable = (ItemTable*)((char*)apOwner + 0x200);
    int i = (int)pItemTable->m_wCount - 1;
    TraceTick tEnter;
    TraceTick tExit;

    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTlsGetValue)(DWORD) = TlsGetValue;
        do
        {
            if (pItemTable->m_ppItems[i] != 0)
            {
                ProfBuf* pBuf = (ProfBuf*)pfnTlsGetValue(DAT_0126835c);
                if (pBuf->m_pCur < pBuf->m_pRecordEnd)
                {
                    ProfRec* pRec = pBuf->m_pCur;
                    pRec->m_pName = "TtNewCollCb";
                    _ReadWriteBarrier();
                    tEnter.Record();
                    pRec->m_iTick = tEnter.Read();
                    pBuf->m_pCur = pRec + 1;
                }

                pItemTable->m_ppItems[i]->v04(apParam);

                ProfBuf* pBuf2 = (ProfBuf*)pfnTlsGetValue(DAT_0126835c);
                if (pBuf2->m_pCur < pBuf2->m_pRecordEnd)
                {
                    ProfRec* pRec2 = pBuf2->m_pCur;
                    pRec2->m_pName = "Et";
                    _ReadWriteBarrier();
                    tExit.Record();
                    pRec2->m_iTick = tExit.Read();
                    pBuf2->m_pCur = pRec2 + 1;
                }
            }
        } while (--i >= 0);
    }

    FUN_00cff9b0(*(CFF9B0SmallArray*)pItemTable);
}

extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(DWORD);
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct TaskContext
{
    DWORD unk00;
    DWORD unk04;
    void* m_pSharedOwner;
};
class TaskObjV7
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(TaskContext* pContext);
};
extern const char str_010cca5c[];
extern const char str_010c41f8[];
typedef CFF9B0SmallArray TaskArray;
// Stores pOwner in pContext, calls v06(pContext) on each non-null entry of the array at pOwner+0x200 in reverse with profiler records, then calls FUN_00cff9b0.
// @fnv 0x00d00270
void __cdecl FUN_00d00270(void* pOwner, TaskContext* pContext)
{
    volatile DWORD t1;
    volatile DWORD* pEndTick = &t1;
    TaskArray* pArr = (TaskArray*)((char*)pOwner + 0x200);
    pContext->m_pSharedOwner = pOwner;
    int i = (int)pArr->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = DAT_00fdf044;
        do
        {
            if (pArr->m_data[i] != 0)
            {
                ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
                ProfRec* cur = pBuf->m_pCur;
                if (cur < pBuf->m_pRecordEnd)
                {
                    cur->m_pName = str_010cca5c;
                    _ReadWriteBarrier();
                    volatile DWORD dwStartTick = (DWORD)__rdtsc();
                    cur->m_iTick = dwStartTick;
                    cur++;
                    pBuf->m_pCur = cur;
                }
                ((TaskObjV7*)pArr->m_data[i])->v06(pContext);
                pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
                cur = pBuf->m_pCur;
                if (cur < pBuf->m_pRecordEnd)
                {
                    cur->m_pName = str_010c41f8;
                    _ReadWriteBarrier();
                    *pEndTick = (DWORD)__rdtsc();
                    cur->m_iTick = *pEndTick;
                    cur++;
                    pBuf->m_pCur = cur;
                }
            }
            i--;
        } while (i >= 0);
    }
    FUN_00cff9b0(*pArr);
}
