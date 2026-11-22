// src/havok/physics/dynamics/world/util/hkpworldoperationutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cb7460_class
{
    int __thiscall hkpAgentNnTrack_getSectorSize(int value);
};
void ClearSlotReference(int* thisPtr, int* p);
void FUN_00d27ac0(int first, int second);
void FUN_00d00960(int first, int second);
void FUN_00cb3c80(int first, int second);
struct FUN_00cb3ca0_object
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
    int refCount94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};
void __cdecl FUN_00d27ac0(FUN_00cb3ca0_object* object, int* value);
void __cdecl FUN_00d00960(FUN_00cb3ca0_object* object, int* value);
int* __cdecl hkpWorldOperationUtil_addConstraintImmediately(FUN_00cb3ca0_object* object, int* value, int shouldNotify);
struct S_00cb3da0_Ctx
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
};
void NotifyTargets(S_00cb3da0_Ctx* ctx, void* p);
void hkpWorldConstraintUtil_removeConstraint(void* p);
void FUN_00cb3da0(S_00cb3da0_Ctx* ctx, void* p);
struct CB3DD0Collidable
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
    unsigned char unk24;
    unsigned char m_flags;
};
struct CB3DD0Entity
{
    int unk00;
    int unk04;
    CB3DD0Collidable* m_kCollidable;
};
struct CB3DD0World
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk098;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk09D;
    unsigned char unk09E;
    unsigned char unk09F;
    int unk0A0;
    int m_iPendingOperationQueueCount;
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
    void* m_kListener;

    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount)
            return;
        if (m_bBlockExecutingPendingOperations)
            return;
        if (m_iPendingOperationCount)
            ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
            ExecutePendingOperationQueues();
    }
};
void __cdecl NotifyTargets(CB3DD0World* world, CB3DD0Entity* entity);
void __cdecl hkpWorldConstraintUtil_removeConstraint(CB3DD0Entity* entity);
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(CB3DD0World* world, CB3DD0Entity* entity, int fireCallbacks);
struct FUN_00d070b0_class
{
    void FUN_00d070b0();
};
struct CleanupList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d070b0_class* finalObject;
    int unk24;
    FUN_00d070b0_class** firstObjects;
    int firstCount;
    int unk30;
    FUN_00d070b0_class** secondObjects;
    int secondCount;
};
void __cdecl FUN_00cb3e90(CleanupList* apCleanupList);
struct Obj;
struct Agent
{
    virtual void v0(int);
    char pad0[0x20 - 4];
    unsigned short m_20;
    char pad1[0x4c - 0x22];
    int m_4c;
    __declspec(nothrow) void RemoveItem(Obj* o);
};
struct Obj
{
    int pad0[2];
    int m_8;
    char pad1[0xc8 - 0xc];
    bool m_c8;
    char pad2[3];
    Agent* m_cc;
};
__declspec(nothrow) void __cdecl hkpWorldOperationUtil_removeIsland(Obj* o, Agent* a);
void __cdecl hkpWorldOperationUtil_removeEntitySI(Obj* ctx, Obj* o);
struct S_00cb5d00_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00cb5d00_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
struct S_00cb5d00_Router
{
    S_00cb5d00_Stack m_aiEntries;
    S_00cb5d00_Heap* m_pStreamAllocator;
    static S_00cb5d00_Router& FUN_00c85750() throw();
    S_00cb5d00_Stack& stack() throw()
    {
        return m_aiEntries;
    }
    S_00cb5d00_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb5d00_Elem
{
    int unk00;
    int unk04;
};
template <class T> struct S_00cb5d00_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00cb5d00_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~S_00cb5d00_Array() throw()
    {
        _clearAndDeallocate(*S_00cb5d00_Router::FUN_00c85750().m_pStreamAllocator);
    }
    void _clearAndDeallocate(S_00cb5d00_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct S_00cb5d00_LocalArray : S_00cb5d00_Array<T>
{
    T* m_pStackAllocation;
    __forceinline S_00cb5d00_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)S_00cb5d00_Router::FUN_00c85750().stack().allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00cb5d00_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        S_00cb5d00_Router::FUN_00c85750().stack().deallocateStack(mem);
    }
};
struct S_00cb5d00_Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out);
    void query(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out) throw()
    {
        unk1C(key, out);
    }
};
struct S_00cb5d00_Sink
{
    void DispatchPairs(S_00cb5d00_Elem* data, int n) throw();
};
struct S_00cb5d00_Owner
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    S_00cb5d00_Source* unk58;
    int unk5C;
    int unk60;
    S_00cb5d00_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
};
struct S_00cb5d00_Query
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
};
void FUN_00cb5d00(S_00cb5d00_Owner* owner, S_00cb5d00_Query* query);
struct Object
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
    int** items;
    int count;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    unsigned char enabled;
};
extern void __cdecl PropagateStateToChildren(Object*, int*);
void __cdecl hkpWorldOperationUtil_splitSimulationIslands(Object* object);
struct Box
{
    char pad[0x14];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};
struct Holder
{
    char pad[0x30];
    Box* box;
};
struct Stats
{
    char pad[8];
    int maxv;
    int sum0;
    int sum1;
    int sum2;
    void hkpConstraintOwner_addConstraintInfo(Holder* h, const int* s);
};
class S_00dd7d00_Bool
{
  public:
    S_00dd7d00_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct S_00dd7d00_Item;
typedef S_00dd7d00_Bool(__cdecl* S_00dd7d00_Less)(S_00dd7d00_Item* a, S_00dd7d00_Item* b);
void FUN_00dd7d00(S_00dd7d00_Item** apItems, int aiLow, int aiHigh, S_00dd7d00_Less apfnLess);
struct S_00c6aca0_Tls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00c6aca0_Tls DAT_tls;
struct S_00c6aca0_Ctx
{
    int saved;
    __forceinline S_00c6aca0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00c6aca0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
struct S_00c6aca0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00c6aca0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c6aca0_Heap* m10;
    __forceinline S_00c6aca0_Heap& heap()
    {
        return *m10;
    }
};
S_00c6aca0_Router* FUN_00c85750() throw();
struct S_00c6aca0_Item
{
    virtual ~S_00c6aca0_Item();
};
struct S_00c6aca0_Arr4
{
    S_00c6aca0_Item** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            int n = cap & 0x3fffffff;
            h.ReturnMemory(m_data, n * 4);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr4() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00c6aca0_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 8);
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr8() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};
struct S_00c6aca0_Cont
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S_00c6aca0_Cont();
    void FUN_00c67f20();
};
struct S_00c6aca0_Mm
{
    void FUN_00aa4060(int p);
};
extern S_00c6aca0_Mm DAT_011f6238;
extern int DAT_012677a4;
struct S_00c6aca0_Ref
{
    void FUN_00c905b0();
};
struct S_00c6aca0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S_00c6aca0_Base();
    void FUN_00c876a0();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    __forceinline void callVfn94()
    {
        vfn_94();
    }
};
struct FUN_00c6aca0 : S_00c6aca0_Base
{
    S_00c6aca0_Ref* unk10;
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
    S_00c6aca0_Arr4 unk70;
    S_00c6aca0_Arr8 unk7c;
    int unk88;
    int unk8c;
    S_00c6aca0_Cont unk90;
    ~FUN_00c6aca0();
};
struct S_00cb3f90_Bool
{
    bool m_cBooleanValue;
    S_00cb3f90_Bool(bool b) : m_cBooleanValue(b)
    {}
};
struct S_00cb3f90_Inner
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    unsigned int unkD4;
};
struct S_00cb3f90_Sub
{
    S_00cb3f90_Inner* m_pInner;
};
struct S_00cb3f90_Obj
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    S_00cb3f90_Sub* m_pSub;
};
S_00cb3f90_Bool worldOperationUtil_less_hkSimulationIslandPtr(S_00cb3f90_Obj* pObjA, S_00cb3f90_Obj* pObjB);
struct ObjB;
struct ObjA
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_94;
    void FUN_00c91160(void* p);
};
struct ObjB
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int m_cc;
};
struct FUN_00cb5570_arg
{
    unsigned char tag;
    ObjB* owner;
    ObjB* other;
};
void __cdecl FUN_00cb4c60(ObjA* a1, int a2, int a3);
void __cdecl hkpWorldOperationUtil_mergeIslands(ObjA* apObjA, ObjB* apOwner, ObjB* apOther);
// Stand-in model for the objects the original touches.
// The polymorphic target: vtable slots 0x10 / 0x1c / 0x20 are used.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* a, void* b);
    virtual void v20(void* a, int b, void* c, int d);
};
// The object at [owner + 0x64] - its member at 0xcf70f0 pops its own arguments.
struct Coll
{
    void __thiscall add(void* p, int n);
};
// The four-word record that is handed to v1c by address.
struct Slot
{
    void* a;
    int b;
    int c;
    void* d;
};
// The thread local block the accessor at 0xc85750 returns.
struct TlsBlk
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    VObj* f4;
};
// The second argument.
struct Evt
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
};
// The first argument.
struct Owner
{
    int unk00;
    int unk04;
    VObj* unk08;
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
    VObj* unk58;
    int unk5c;
    int unk60;
    Coll* unk64;
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
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
};
// The thread local accessor at 0xc85750.
void* __cdecl tlsSlot_cb5c10();
void __cdecl FUN_00cb5c10(Owner* pOwner, Evt* pEvent);
struct FUN_00cb7480_node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
};
struct FUN_00cb7480_holder
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
    FUN_00cb7480_node* m_30;
};
struct FUN_00cb7480_delta
{
    int unk00;
    int m_04;
    int m_08;
    int m_0c;
};
struct FUN_00cb7480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;

    void hkpConstraintOwner_subConstraintInfo(FUN_00cb7480_holder* a1, FUN_00cb7480_delta* a2);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S00cb5310_Sub;
struct S00cb5310_Node;
struct S00cb5310_Piece;
struct S00cb5310_Owner;
struct S00cb5310_Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40(void* p);
    virtual void v44(void* p);
};
struct S00cb5310_List
{
    S00cb5310_Node** m_00;
    int m_04;
    unsigned int m_08;
};
struct S00cb5310_Alloc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct S00cb5310_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char m_26;
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float m_44;
    S00cb5310_Piece** m_48;
    int m_4c;
};
struct S00cb5310_Piece
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S00cb5310_Sub m_e0;
    int unkE4;
    int unkE8;
    int unkEC;
    int m_f0;
    int unkF4;
    int unkF8;
    int unkFC;
};
struct S00cb5310_Owner
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
    S00cb5310_Node** m_28;
    int m_2c;
    int unk30;
    S00cb5310_List m_34;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    float m_1d0;
};
extern int DAT_01267e30;
void ResizeAudioStream(void* alloc, S00cb5310_List* list, int n);
bool hkRigidMotionUtilCanDeactivateFinal(float* p, S00cb5310_Piece** arr, int n, int size);
void UpdateRotationInterpolation(float f, void* p);
void FUN_00d011b0(S00cb5310_Owner* a1, S00cb5310_Node* a2);
void __cdecl FUN_00cb5310(S00cb5310_Owner* a1, S00cb5310_Node* a2);
struct Cb5750_Deferred
{
    unsigned char tag;
    struct Cb5750_Param* arg;
};
struct Cb5750_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};
struct Cb5750_Nav
{
    int unk00;
    int unk04;
    int unk08;
    Cb5750_Bv m_bv;
};
struct Cb5750_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    Cb5750_Nav m_nav;
};
struct Cb5750_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Cb5750_Inner inner;
};
struct Cb5750_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};
struct Cb5750_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};
S_00c6aca0_Router* Cb5750_router() throw();
struct Cb5750_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb5750_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Cb5750_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~Cb5750_Array() throw()
    {
        S_00c6aca0_Router* router = Cb5750_router();
        S_00c6aca0_Heap& heap = *router->m10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            heap.vfn_10(m_data, (cap & 0x3fffffff) * (int)sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct Cb5750_LocalArray : Cb5750_Array<T>
{
    T* m_pStackAllocation;
    __forceinline Cb5750_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)((Cb5750_Stack*)Cb5750_router())->allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~Cb5750_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        ((Cb5750_Stack*)Cb5750_router())->deallocateStack(mem);
    }
};
struct Cb5750_Source
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual void v2c(Cb5750_Nav** key, Cb5750_Aabb* aabb, int count, Cb5750_Array<S_00cb5d00_Elem>* a,
                     Cb5750_Array<S_00cb5d00_Elem>* b) throw();
};
struct Cb5750_Sink
{
    void addSecond(S_00cb5d00_Elem* data, int n) throw();
    void addFirst(S_00cb5d00_Elem* data, int n, void* extra) throw();
};
S_00c6aca0_Router* Cb5750_router() throw();
void __cdecl Cb5750_merge(Cb5750_Array<S_00cb5d00_Elem>* a, Cb5750_Array<S_00cb5d00_Elem>* b) throw();
void __cdecl Cb5750_invalid(void* world, Cb5750_Param** pp, int count) throw();
struct Cb5750_Owner
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    Cb5750_Source* unk58;
    int unk5C;
    int unk60;
    Cb5750_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;
    Cb5750_Sub8* unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
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
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;

    void defer(Cb5750_Deferred* d) throw();
    void flush8c() throw();
    void flush90() throw();
    void __cdecl AddCollisionShape(Cb5750_Param* param) throw();
};
struct Item_cb3d10
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
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
};
struct Owner_cb3d10
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
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
};
struct List_cb3d10
{
    Item_cb3d10** m_data;
    int m_iElementCount;
};
static Item_cb3d10* FindItemForThreshold(Owner_cb3d10* owner, List_cb3d10* list, int threshold, Item_cb3d10* target);
volatile int g_cb3d10_thr;
Owner_cb3d10* volatile g_cb3d10_owner;
List_cb3d10* volatile g_cb3d10_list;
Item_cb3d10* volatile g_cb3d10_target;
Item_cb3d10* volatile g_cb3d10_out;
void CallTarget_cb3d10();
struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_List
{
    B10293_Item** m_data;
    int m_uiItemCount;
};
struct B10293_Ctx
{
    unsigned char Sel(int off) const
    {
        return *((const unsigned char*)this + off);
    }
};
struct B10293_Arr
{
    int* m_aiIndexedValues;
};
struct B10293_Chain
{
    B10293_Arr* m_aiIndexedValues;
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}
static void MarkIndexedValues(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx);
int keep_alive_b10293(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx);
struct Shape
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    unsigned short m_numShapeKeys;  // +0xb0
};
struct ShapeList
{
    Shape** m_items;
    int m_uiItemCount;
};
static void FUN_00cb41e0(int*** indexMap, int** counts, ShapeList* list, int** flags);
int keep_alive_b11420(ShapeList* list, int** flags, int*** indexMap, int** counts);
template <class T> inline void S00cb4c60_copy(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
struct hkpWorld;
struct hkpSimulationIsland;
struct hkpEntity;
struct hkpAction;
struct hkBool
{
    char value;
    hkBool(bool b) : value(b)
    {}
    hkBool(const hkBool& other) : value(other.value)
    {}
};
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> struct hkArrayNative
{
    T* data;
    int count;
    unsigned int capRaw;
    int getCapacity() const
    {
        return capRaw & 0x3fffffff;
    }
    void reserve(int n)
    {
        S_00c6aca0_Heap& a = FUN_00c85750()->heap();
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
    void AddBack(const T& t)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (count == getCapacity())
            ResizeAudioStream(&r->heap(), this, sizeof(T));
        S00cb4c60_copy(data + count, 1, t);
        count++;
    }
    void SetSize(int size)
    {
        reserve(size);
        count = size;
    }
};
struct hkpConstraintInstance
{
    int unk00, unk04;
    hkpSimulationIsland* owner;
};
struct ConstraintRuntimeInfo
{
    hkpConstraintInstance* constraint;
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
};
struct hkpAction
{
    int unk00, unk04, unk08;
    hkpSimulationIsland* owner;
};
struct hkpEntity
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short storageIndex, unkAA;
    ConstraintRuntimeInfo* constraintMasters;
    unsigned short constraintMasterCount, unkB2;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    hkpSimulationIsland* owner;
};
struct hkpSimulationIsland
{
    virtual ~hkpSimulationIsland();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short storageIndex, dirtyIndex;
    unsigned char unk24, flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char f26lo : 2;
            unsigned char f26mid : 2;
        } f26;
    };
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayNative<hkpAction*> actions;
    int unk44;
    hkArrayNative<hkpEntity*> entities;
    int unk54;
    int unk58;
    void FUN_00d07120();
    void MergeFrom(hkpSimulationIsland*);
};
struct hkpWorld
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpSimulationIsland* fixedIsland;
    int unk24;
    hkArrayNative<hkpSimulationIsland*> active;
    hkArrayNative<hkpSimulationIsland*> inactive;
    hkArrayNative<hkpSimulationIsland*> dirty;
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
    int refCount94;
    int unk98;
    unsigned char flag9c, unk9d, unk9e, unk9f;
    int unka0;
    int unka4;
    void hkpConstraintInstance_entityAddedCallback(hkpSimulationIsland*);
    void FUN_00c91120();
    void FUN_00c91140();
};
void __cdecl hkpWorldOperationUtil_internalActivateIsland(hkpWorld*, hkpSimulationIsland*, hkBool);
void __cdecl FUN_00cff290(void*, void*);
void __cdecl FUN_00c908c0(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl ClearSlotReference(hkpWorld*, hkpSimulationIsland*);
static inline int GrowCap(int cap, int need)
{
    int nc = cap * 2;
    if (need >= nc)
        nc = need;
    return nc;
}
void __cdecl FUN_00cb4c60(hkpWorld* a1, hkpSimulationIsland* P, hkpSimulationIsland* Q);
struct IslandList
{
    struct IslandNode** items;
    int count;
    int capacity;
};
struct IslandNode
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
    unsigned char index;
    unsigned char flags;
    union
    {
        unsigned char state;
        struct
        {
            unsigned char lowState : 2;
            unsigned char highState : 2;
            unsigned char otherState : 4;
        };
    };
    unsigned char unk27;
    IslandList first;
    IslandList second;
};
void __cdecl hkpWorldOperationUtil_splitSimulationIsland(IslandNode* data, Object* object, IslandList* list, int value);
void __cdecl AddItemToContainer(Object* object, IslandNode* item);
void __cdecl PropagateStateToChildren(Object* object, int* data);
#include <windows.h>
struct Cb4890_Elem
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned short unk0e8;
    unsigned short m_ea;
    unsigned short m_ec;
};
struct Cb4890_ElemArray
{
    Cb4890_Elem** m_data;
    int m_iElementCount;
};
struct Cb4890_IntArray
{
    int* m_data;
    int m_iElementCount;
};
struct Cb4890_CharArray
{
    char* m_data;
    int m_iElementCount;
};
struct Cb4890_Stack
{
    char* m_next;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb4890_LocalBuffer
{
    T* m_p;
    int m_iElementCount;
    __forceinline Cb4890_LocalBuffer(int n) throw()
    {
        m_p = (T*)((Cb4890_Stack*)FUN_00c85750())->allocateStack(n * (int)sizeof(T));
    }
    __forceinline ~Cb4890_LocalBuffer() throw()
    {
        ((Cb4890_Stack*)FUN_00c85750())->deallocateStack(m_p);
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_p[i];
    }
};
struct Cb4890_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
struct Cb4890_RemapTable
{
    Cb4890_IntArray* m_entries;
    int m_iElementCount;
    void RemapAndAccumulate(Cb4890_LocalBuffer<int>& map, int count, Cb4890_IntArray* src) throw();
};
template <class T> __forceinline T Cb4890_max2(T a, T b)
{
    return a > b ? a : b;
}
__forceinline int RemapOne(Cb4890_LocalBuffer<int>& used, int* mapped, Cb4890_CharArray* out, int i, int count)
{
    if (used[i])
        mapped[i] = 0;
    else
    {
        mapped[i] = count;
        out->m_data[count] = 0;
        count++;
    }
    return count;
}
static void RemapElements(const Cb4890_ElemArray& list, Cb4890_RemapTable* remap, Cb4890_Owner* owner,
                          Cb4890_IntArray* src, Cb4890_CharArray* out);
volatile int g_cb4890[5];
void Cb4890_caller();
struct S00cb5100_WBits
{
    unsigned short lo : 14;
    unsigned short hi : 2;
};
struct S00cb5100_Bits
{
    unsigned char lo : 2;
    unsigned char hi : 6;
};
struct S00cb5100_Body;
struct S00cb5100_Ent
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    S00cb5100_Body* owner_cc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char unke8;
    union
    {
        unsigned char be9;
        S00cb5100_Bits bits9;
    };
    union
    {
        unsigned short wea;
        S00cb5100_WBits bea;
    };
    union
    {
        unsigned short wec;
        S00cb5100_WBits bec;
    };
    unsigned short unkee;
    int unkf0;
    void FUN_00c90510();
    void FUN_00c905b0();
    void setFilter(int a0, int a1, int a2)
    {
        if ((unsigned int)(a2 & 3) < (unsigned int)(be9 & 3))
            a0 = (~a0) << 14;
        else
            a0 <<= 14;
        if (a2 < be9)
            a1 = (~a1) << 14;
        else
            a1 <<= 14;
        wea = (unsigned short)((wea & 0x3fff) | a0);
        wec = (unsigned short)((wec & 0x3fff) | a1);
    }
};
struct S00cb5100_Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int f1c;
    unsigned short idx20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned char flags26;
    unsigned char unk27;
    int unk28;
    int unk2c;
    float f30;
    float f34;
    int unk38;
    int unk3c;
    int unk40;
    float f44;
    S00cb5100_Ent** list48;
    int count4c;
};
void ResizeAudioStream(void* heap, void* arr, int elemSize);
struct S00cb5100_Arr
{
    S00cb5100_Body** m_data;
    int m_iElementCount;
    int m_cap;
    S00cb5100_Body* pick(int* n, S00cb5100_Body** b, int k);
    void AddBack(S00cb5100_Body* const& e)
    {
        S_00c6aca0_Router* r = FUN_00c85750();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->m10, this, 4);
        S00cb5100_Body** out = m_data + m_iElementCount;
        for (int k = 0; k < 1; ++k)
            out[k] = e;
        ++m_iElementCount;
    }
};
void FUN_00cf1480(float a, float b, void* p);
void hkpWorldAgentUtil_warpTime(S00cb5100_Body* b, float f, float g, int h);
struct S00cb5100_World
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
    S00cb5100_Arr arr28;
    S00cb5100_Body** data34;
    int size38;
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
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
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
    float f1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char b305;
    unsigned char b306;
    union
    {
        unsigned char b307;
        S00cb5100_Bits bits307;
    };
};
void ProcessSceneCallbacks(S00cb5100_World* w, S00cb5100_Body* b);
static __declspec(noinline) S00cb5100_Body* FindItemForThreshold(S00cb5100_World* w, S00cb5100_Arr* arr, int n,
                                                                 S00cb5100_Body* b)
{
    if (w->size38 == 0 || arr->m_iElementCount == 0)
        return 0;
    return arr->pick(&n, &b, w->size38);
}
static inline bool S00cb5100_lt(unsigned char a, unsigned char b)
{
    return a < b;
}
void hkpWorldOperationUtil_internalActivateIsland(S00cb5100_World* w, S00cb5100_Body* b, bool merge);
#include <xmmintrin.h>
extern float DAT_01017d00;
__forceinline int c6a870Equals3(const __m128& a, const __m128& b, float eps = 0.001f)
{
    static __declspec(align(16)) const unsigned int mask[4] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
    __m128 d = _mm_sub_ps(a, b);
    d = _mm_and_ps(d, _mm_load_ps((const float*)mask));
    __m128 e = _mm_set_ps1(eps);
    return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
}
struct C6A870_Child
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044, f048, f04c, f050, f054, f058, f05c;
    int f060, f064, f068, f06c, f070, f074, f078, f07c;
    int f080, f084, f088, f08c, f090, f094, f098, f09c;
    int f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc;
    int f0c0, f0c4, f0c8, f0cc, f0d0, f0d4, f0d8, f0dc;
    int f0e0, f0e4, f0e8, f0ec, f0f0, f0f4, f0f8, f0fc;
    int f100, f104, f108, f10c, f110, f114, f118, f11c;
    int f120, f124, f128, f12c, f130, f134, f138, f13c;
    int f140, f144, f148, f14c, f150, f154, f158, f15c;
    int f160, f164, f168, f16c, f170, f174, f178, f17c;
    int f180, f184, f188, f18c, f190, f194, f198, f19c;
    int f1a0, f1a4, f1a8, f1ac;
    __m128 m_vLinearConstraint;
    __m128 m_vAngularConstraint;
};
struct C6A870_Item
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044;
    C6A870_Child** m_children;
    int m_uiItemCount;
};
struct C6A870_Heap;
typedef void*(__thiscall* C6A870_AllocFn)(C6A870_Heap*, int&);
typedef void(__thiscall* C6A870_FreeFn)(C6A870_Heap*, void*, int);
struct C6A870_HeapTable
{
    void* v00;
    void* v04;
    void* v08;
    C6A870_AllocFn alloc;
    C6A870_FreeFn free;
};
struct C6A870_Heap
{
    C6A870_HeapTable* table;
    __forceinline void* AllocateBufferWithSize(int& numBytes)
    {
        return table->alloc(this, numBytes);
    }
    __forceinline void ReturnMemory(void* p, int n) throw()
    {
        table->free(this, p, n);
    }
    template <typename T> __forceinline T* _bufAlloc(int& n, int& numBytes)
    {
        C6A870_AllocFn alloc = table->alloc;
        numBytes = n * int(sizeof(T));
        void* p = alloc(this, numBytes);
        n = numBytes / int(sizeof(T));
        return (T*)p;
    }
};
__forceinline C6A870_Heap& c6a870Heap()
{
    return *(C6A870_Heap*)&FUN_00c85750()->heap();
}
template <typename T> __forceinline void c6a870Copy(T* dst, const T* src, int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}
template <typename T> struct C6A870_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline C6A870_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~C6A870_Array() throw()
    {
        _clearAndDeallocate(c6a870Heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(C6A870_Heap& h) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _copyFromArray(C6A870_Heap& h, const C6A870_Array& a, int& scratch)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                h.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = a.GetLogicalSize();
            m_data = h._bufAlloc<T>(n, scratch);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        c6a870Copy(m_data, a.m_data, m_iElementCount);
    }
    __forceinline C6A870_Array& assign(const C6A870_Array& a, int& scratch)
    {
        _copyFromArray(c6a870Heap(), a, scratch);
        return *this;
    }
};
struct C6A870_World
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024;
    C6A870_Array<C6A870_Item*> m_items;
};
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(C6A870_World* world);
void __cdecl AddItemToContainer(C6A870_World* world, C6A870_Item* item);
struct C6A870_Self;
typedef C6A870_World*(__thiscall* C6A870_Query)(C6A870_Self*);
struct C6A870_QueryTable
{
    void* f00;
    void* f04;
    void* f08;
    void* f0c;
    void* f10;
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    void* f40;
    void* f44;
    void* f48;
    void* f4c;
    void* f50;
    void* f54;
    void* f58;
    void* f5c;
    void* f60;
    void* f64;
    void* f68;
    void* f6c;
    void* f70;
    void* f74;
    void* f78;
    void* f7c;
    void* f80;
    void* f84;
    void* f88;
    void* f8c;
    void* f90;
    C6A870_Query query;
};
struct C6A870_View
{
    C6A870_QueryTable* table;
};
struct C6A870_Self
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual C6A870_World* getWorld();

    void FUN_00c6a870();
};
struct Motion4120
{
    virtual void unused();
    unsigned short storageSize, refCount;
    unsigned char kind, counter;
    unsigned short inactive[2];
    __forceinline int frames(int slot, int flag)
    {
        int packed = inactive[slot];
        int mode = packed >> 14;
        int n;
        if (flag != mode)
        {
            n = packed & 127;
        }
        else
        {
            n = (packed >> 7) & 127;
        }
        return n & 127;
    }
};
struct Selector
{
    unsigned char first;
    unsigned char second;
};
struct Entry4120
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
    int unk98;
    int unk9c;

    int unka0;
    int unka4;
    int unka8;
    int unkac;

    unsigned short countB0;
    unsigned short unkb2;
    unsigned short unkb4;
    unsigned short unkb6;

    unsigned short unkb8;
    unsigned short unkba;
    unsigned short unkbc;
    unsigned short unkbe;

    unsigned short unkc0;
    unsigned short unkc2;
    unsigned short unkc4;
    unsigned short unkc6;

    unsigned short unkc8;
    unsigned short unkca;
    unsigned short unkcc;
    unsigned short unkce;

    unsigned short unkd0;
    unsigned short unkd2;
    unsigned short unkd4;
    unsigned short unkd6;

    unsigned short unkd8;
    unsigned short unkda;
    unsigned short unkdc;
    unsigned short unkde;

    Motion4120 motion;
    __forceinline Motion4120* movement()
    {
        return &motion;
    }
};
template <class T> struct View4120
{
    T* data;
    int count;
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline int size() const
    {
        return count;
    }
};
struct Groups4120
{
    View4120<int>& groups;
    int n;
};
template <class T> __forceinline T greater4120(T a, T b)
{
    return a > b ? a : b;
}
static void UpdateGroupActivity(const Groups4120& map, const View4120<Entry4120*>& entries, int unusedGroups,
                                View4120<int>& active, View4120<int>& sizes, unsigned char* flags);
extern const Groups4120* volatile inputMap4120;
extern const View4120<Entry4120*>* volatile inputEntities4120;
extern View4120<int>* volatile outputActive4120;
extern View4120<int>* volatile outputSizes4120;
extern unsigned char* volatile inputFlags4120;
extern int volatile groupCount4120;
void caller4120();
struct Inner;
struct CallA
{
    signed char delta;
    void UpdateCollisionIndices();
    void CopyAndSortGeometryList(void* p);
};
struct Mgr2
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    unsigned char unk24;
    bool splitRequested : 2;
    bool sparseEnabled : 2;
    bool cleanup : 2;
    bool inActive : 2;
    unsigned char unk26, unk27;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int m_4c;
    int unk050;
    int unk054;
    int m_58;
    __forceinline void mark()
    {
        splitRequested = true;
    }
    __forceinline int count() const
    {
        return m_4c;
    }
};
struct MotionObj
{
    void* vt;
    int unk04;
    Inner* m_08;
    int unk0c;
    CallA collidable;
    unsigned char unk11, unk12, unk13;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    Mgr2* m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8, unke9, unkea, unkeb;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int m_1f8;
};
struct Inner
{
    int unk00, unk04;
    MotionObj* m_08;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int m_8c, m_90, m_94, unk98;
    unsigned char m_9c, m_9d, unk9e, unk9f;
    int m_a0, m_a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    float m_1d0;
};
typedef void(__thiscall* FnFree)(void* self, void* p, int bytes);
typedef void(__thiscall* Fn20)(void* self, void* p, int a, void* b, int c);
struct RemRef
{
    void FUN_00c905b0();
};
struct CallB
{
    void UpdateNodeSlotIndices();
    void FUN_00c90510();
};
struct CallInner
{
    void hkpWorld_updateCollisionFilterOnEntity(void* p, void* q, int a);
    void FUN_00c91120();
    void FUN_00c91140();
};
void FUN_00cf9c60(void* p, int a, void* b);
void FUN_00cb5000(MotionObj* a0, void* b);
void CollectActorEntries(Inner* s, MotionObj* a0, void* a);
void CollectProducers(Inner* s, MotionObj* a0, void* a);
void hkpWorldOperationUtil_removeEntitySI(Inner* s, MotionObj* a0);
void hkpWorldOperationUtil_addConstraintImmediately(Inner* s, void* e, int z);
struct ModeBool
{
    bool value;
    ModeBool()
    {}
    ModeBool(bool b) : value(b)
    {}
    ModeBool(const ModeBool& b) : value(b.test())
    {}
    void set(bool b)
    {
        static_cast<volatile bool&>(value) = b;
    }
    bool test() const
    {
        return value;
    }
    operator bool() const
    {
        return test();
    }
};
void FUN_00cb4230(MotionObj* a0, int mode, ModeBool fMode, ModeBool fCur, Inner* s);
void FUN_00cb4640(Inner* s, int a5, int a7);
void ApplyConstraintsToEntity(Inner* s, int a8, void* p);
void FUN_00cb3ee0(void* m, MotionObj* a3, void* w, int mode);
void FUN_00cff290(void* m, void* w);
void hkpWorldOperationUtil_mergeIslands(Inner* in, MotionObj* a0, MotionObj* e);
void UpdateRotationInterpolation(float f, void* p);
void NotifyEntityRemoved(void* p, MotionObj* a3);
struct VecB
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct VecA
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct Work
{
    int f0;
    void* data;
    int size;
    int cap;
    int buf0;
};
struct Elem8
{
    int f0;
    MotionObj* f4;
};
struct VecC
{
    Elem8* data;
    int size;
    int cap;
    VecC() : data(0), size(0), cap((int)0x80000000)
    {}
};
struct HeadC
{
    short unk10;
    ModeBool fCur;
    ModeBool fMode;
};
static __forceinline void FreeVec(void** dataP, int* sizeP, int* capP, int elem)
{
    S_00c6aca0_Router* m = FUN_00c85750();
    void* fo = m->m10;
    int cap = *capP;
    *sizeP = 0;
    if ((cap & (int)0x80000000) == 0)
    {
        FnFree fn = (FnFree)(*(void***)fo)[4];
        fn(fo, *dataP, (cap & 0x3fffffff) * elem);
    }
    *dataP = 0;
    *capP = (int)0x80000000;
}
void FUN_00cb6f70(MotionObj* a0, int mode, int a2, MotionObj* a3, int a4, int a5, int a6, int a7, int a8);
struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
struct InertiaTensor
{
    InertiaTensor()
    {}
    S00cb4230_Vec4 m_kColumn0;
    S00cb4230_Vec4 m_kColumn1;
    S00cb4230_Vec4 m_kColumn2;
};
struct S00cb4230_Rotation : InertiaTensor
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
struct S00cb4230_Swept
{
    S00cb4230_Swept()
    {}
    float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    S00cb4230_Vec4 m_vCenterOfMass0;
    S00cb4230_Vec4 m_vCenterOfMass1;
    S00cb4230_Quat m_qRotation0;
    S00cb4230_Quat m_qRotation1;
    S00cb4230_Vec4 m_vCenterOfMassLocal;
};
extern float DAT_010c7948[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    S00cb4230_Swept& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const S00cb4230_Swept& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void FUN_00c86660(void* p);
    S00cb4230_Transform m_kMotionTransform;
    S00cb4230_Swept m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
enum S00cb4230_MotionType
{
    S00cb4230_INVALID,
    S00cb4230_DYNAMIC,
    S00cb4230_SPHERE,
    S00cb4230_BOX,
    S00cb4230_KEYFRAMED,
    S00cb4230_FIXED
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct AllocObj
{
    virtual void v00();
    virtual void* v01(int size);
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00();
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    {}
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(InertiaTensor& out) const;
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    S00cb4230_MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return m_kMotionState.getSweptTransform().m_qRotation1;
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return m_kMotionState.getSweptTransform().m_vCenterOfMassLocal;
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<S00cb4230_MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0();
    void FUN_00d1dff0();
    void hkpMotion_setWorldSelectFlagsNeg(int a, int b, int c);
    void FUN_00c86610(MotionBase* p);
    float hkpMotion_getMass();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        S_00c6aca0_Heap& h = FUN_00c85750()->heap();
        RefHeader31* b = static_cast<RefHeader31*>(((AllocObj*)&h)->v01(static_cast<int>(nbytes)));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S00cb4230_Keyframed : MotionBase
{
    S00cb4230_Keyframed() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    S00cb4230_Keyframed(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : S00cb4230_Keyframed
{
    MotionState() : S00cb4230_Keyframed()
    {}
};
struct BoxMotion : MotionBase
{
    BoxMotion(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
enum S00cb4230_Quality
{
    S00cb4230_QUALITY_FIXED,
    S00cb4230_QUALITY_KEYFRAMED
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    char m_auiShapeKeys;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
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
    float m_5c;
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
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    S00cb4230_Quality getQualityType() const
    {
        return S00cb4230_Quality(getCollidable()->getQualityType());
    }
    void setQualityType(S00cb4230_Quality type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = char(type);
    }
    void UpdateBoundingVolume(void* a, const void* b);
};
struct Node4
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    char m_305;
    char m_306;
    char m_307;
    float FUN_00c91020();
};
void __cdecl FUN_00cb1280(void* p, int a, int b);
template <typename T> __forceinline T* __cdecl S00cb4230_AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
void __cdecl FUN_00ca8240(int mode, const S00cb4230_Vec4* p40, const S00cb4230_Quat* p80, float fret,
                          const InertiaTensor* out, const S00cb4230_Vec4* p90, float f0, float f1, MotionBase* motion);
void __cdecl UpdateRotationInterpolation(float f, S00cb4230_MotionStateData* p);
void __cdecl FUN_00cb4230(ThisObj* self, S00cb4230_MotionType mode, MotionFlag31 flagA, MotionFlag31 flagB,
                          Node4* node);
struct MergeWorld
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    unsigned char state0;
    bool enabled;
    unsigned char state2;
    unsigned char state3;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
union MergeListArg
{
    Cb4890_ElemArray* value;
};
static __forceinline void tallyActive(Cb4890_RemapTable* remap_, Cb4890_ElemArray*& list, int n,
                                      Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt, MergeWorld* owner,
                                      Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        int a = Dec(e->m_ec, owner->m_306);
        int b = Dec(e->m_ea, owner->m_305);
        int am = a & 0x7f;
        int bm = b & 0x7f;
        int mx = (bm > am) ? bm : am;
        if (mx <= 5)
            map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
static __forceinline void tallyAll(Cb4890_RemapTable* remap_, Cb4890_ElemArray* list, int n,
                                   Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
void FUN_00cb49e0(MergeWorld* owner, int remap_, MergeListArg listArg, Cb4890_IntArray* src, Cb4890_CharArray* out);
struct S00cb3ee0_Entry
{
    int item;
    char* obj;
};
struct S00cb3ee0_Holder
{
    S00cb3ee0_Entry* entries;
    int count;
};
struct S00cb3ee0_Sub
{
    S00cb3ee0_Holder* FUN_00d081e0();
};
int PickIslandByValue(int a, int b, int c);
void CloneRecord(int a, int b);
void FUN_00cfe020(int a, int b);
void FUN_00cb3ee0(void* m, MotionObj* motion, void* w, int mode);
struct S55Item;
template <typename T>

struct S55Array
{

    T* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }

    __forceinline void popBack()
    {
        m_iElementCount--;
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00c6aca0_Heap& a, int n);

    __forceinline void _setSize(S_00c6aca0_Heap& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
};
void __cdecl FUN_00c908c0(S_00c6aca0_Heap& a, void* array, int reqCapacity, int sizeElem);
template <typename T>

__forceinline void S55Array<T>::GrowArrayCapacity(S_00c6aca0_Heap& a, int n)

{

    const int capacity = getCapacity();

    if (capacity < n)
    {

        int cap2 = 2 * capacity;

        int newSize = (n < cap2) ? cap2 : n;

        FUN_00c908c0(a, this, newSize, sizeof(T));
    }
}
struct S55Item
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int m_1c;

    unsigned short unk20;

    unsigned short m_22;

    unsigned char unk24;

    unsigned char m_25;

    unsigned char m_26;

    unsigned char unk27;

    int unk28;

    int unk2c;

    int unk30;

    int unk34;

    S55Array<S55Item*> m_38;

    int unk44;

    ObjB** m_48;

    int m_4c;
};
struct S55Bool
{

    char m_cBooleanValue;

    S55Bool(bool b) : m_cBooleanValue(b)
    {}
};
struct S55Owner
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

    S55Array<S55Item*> m_28;

    int unk34;

    int unk38;

    int unk3c;

    S55Array<S55Item*> m_40;

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

    int unk98;

    int unk9c;

    int unka0;

    int unka4;

    int unka8;

    int unkac;

    int unkb0;

    int m_b4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    unsigned char m_c8;

    void __thiscall FUN_00c910b0();
};
void __cdecl hkpWorldOperationUtil_internalActivateIsland(S55Owner* owner, S55Item* item, S55Bool b);
void __cdecl FUN_00cb5310(S55Owner* owner, S55Item* item);
extern "C" void __cdecl hkpWorldOperationUtil_mergeIslands(S55Owner* owner, ObjB* first, ObjB* second);
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(S55Owner* owner);

struct SplitIsland_Target;
struct SplitIsland_Target;
struct SplitIsland_Node2;
extern "C" void _ReadWriteBarrier(void);
// Partition physics island nodes into groups, relink owners, and redistribute stream records.
struct SplitIsland_CursorObj
{
    int cur;
    int unk04;
    int unk08;
    int unk0c;
    struct SplitIsland_Alloc* alloc;
};
struct SplitIsland_Alloc
{
    virtual void V00();
    virtual void V04();
    virtual void V08(void* p, int n);
    virtual void V0c();
    virtual void FreeLike(void* p, int size);
};
__forceinline int* SplitIsland_cursor()
{
    return &FUN_00c85750()->unk00;
}
void FUN_00cb1280(void* p, int a, int b);
void FUN_00c908c0(void* alloc, void* vec, int cap, int elemsz);
void ResizeAudioStream(void* alloc, void* vec, int elemsz);
void FUN_00c909d0(void* alloc, void* vec, int elemsz, void* p, int n);
struct SplitIsland_AllocB
{
    virtual void V00();
    virtual void* AllocSz(int sz);
};
template <class T> __forceinline void SplitIsland_copyItems(T* destination, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
    {
        __assume(destination + i != 0);
        new (destination + i) T(value);
    }
}
struct SplitIsland_Vec48
{
    __forceinline void SplitIsland_appendNodeUnchecked(SplitIsland_Node2* const&);
    int* data;
    int cnt;
    int cap;
    void SwapThreeInts(int arg);
    __forceinline void SplitIsland_reserve(int n)
    {
        SplitIsland_CursorObj* router = (SplitIsland_CursorObj*)SplitIsland_cursor();
        if ((cap & 0x3fffffff) < n)
            FUN_00c908c0(router->alloc, this, n, 4);
    }
    __forceinline void SplitIsland_append(int value)
    {
        SplitIsland_CursorObj* router = (SplitIsland_CursorObj*)SplitIsland_cursor();
        if (cnt == (cap & 0x3fffffff))
            ResizeAudioStream(router->alloc, this, 4);
        int* destination = data + cnt;
        __assume(destination != 0);
        new (destination) int(value);
        ++cnt;
    }
    __forceinline void SplitIsland_appendUnchecked(const int& value)
    {
        SplitIsland_copyItems(data + cnt, 1, value);
        ++cnt;
    }
    __forceinline void SplitIsland_compact()
    {
        int capacity = cap;
        if ((capacity & 0x80000000) == 0)
        {
            unsigned int v = cnt + 3;
            v |= v >> 16;
            v |= v >> 8;
            v |= v >> 4;
            v |= v >> 2;
            int wanted = (v | (v >> 1)) + 1;
            if (wanted < 1)
            {
                FUN_00c909d0(((SplitIsland_CursorObj*)SplitIsland_cursor())->alloc, this, 4, this + 1, 1);
            }
            else if (wanted < (capacity & 0x3fffffff))
            {
                FUN_00c909d0(((SplitIsland_CursorObj*)SplitIsland_cursor())->alloc, this, 4, 0, wanted);
            }
        }
    }
};
struct SplitIsland_Arg2Vec
{
    int* data;
    int cnt;
    int cap;
};
struct SplitIsland_Obj38
{
    int** f00;
    int unk04;
    void FUN_00d27f70(int* p, int n);
    void RemapIndices(struct SplitIsland_L60* p);
    int hkUnionFind_moveBiggestGroupToIndexZero(struct SplitIsland_L60* p);
    void RemapAndAccumulate(int* q, int n, struct SplitIsland_L60* p);
};
struct SplitIsland_L60
{
    int* f00;
    int f04;
    int f08;
    int data[32];
};
struct SplitIsland_H44;
struct SplitIsland_Arg0
{
    inline void SplitIsland_removeTransfer(SplitIsland_Target*, SplitIsland_H44&);
    int unk00;
    short f04;
    short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    short unk22;
    unsigned char unk24;
    union
    {
        unsigned char f25;
        struct
        {
            unsigned char stateLow : 2;
            unsigned char groupState : 2;
            unsigned char stateHigh : 4;
        };
    };
    union
    {
        unsigned char f26;
        struct
        {
            unsigned char type26 : 2;
            unsigned char active26 : 1;
            unsigned char pending26 : 1;
            unsigned char high26 : 4;
        };
    };
    unsigned char unk27;
    int field28;
    int field2C;
    int field30;
    int field34;
    SplitIsland_Vec48 f38v;
    int unk44;
    SplitIsland_Vec48 f48v;
    int field54;
    int f58;
    SplitIsland_Vec48 v5c;
    int inline68;
    char CheckConnectivity(void* p);
    SplitIsland_Arg0* FUN_00d07830(void* arg);
    inline void hkpConstraintOwner_addConstraintInfo(SplitIsland_Target*, SplitIsland_H44&);
};
struct SplitIsland_H44
{
    int f00;
    int f04;
    int f06;
    int f08;
};
struct SplitIsland_Target;
struct SplitIsland_Sub30
{
    inline void SplitIsland_readTransfer(SplitIsland_H44&) const;
    inline void SplitIsland_debitTransfer(const SplitIsland_H44&);
    SplitIsland_Target* f00;
    int field04;
    int field08;
    int field0C;
    int field10;
    unsigned short f14;
    unsigned short f16;
    unsigned short f18;
    short unk1a;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct SplitIsland_Target
{
    inline void SplitIsland_assignOwner(SplitIsland_Arg0*);
    int unk00;
    int unk04;
    SplitIsland_Arg0* SplitIsland_owner;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SplitIsland_Sub30* f30;
};
struct SplitIsland_Node2
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    short fA8;
    short unkAA;
    int fAC;
    short fB0;
    unsigned short fieldB2;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    short unkE8;
    unsigned short fEA;
    unsigned short fEC;
};
struct SplitIsland_TempEC
{
    int* f00;
    int f04;
    int f08;
    int data[16];
};
struct SplitIsland_Elem2
{
    virtual void V00();
    virtual void V04();
    virtual void V08(void* p, int n);
    virtual void V0c();
    virtual void GetList(SplitIsland_TempEC* t);
    int unk04;
    int unk08;
    int f0c;
};
void CloneRecord(int* p, void* q);
void FUN_00cfe020(void* p, void* q);
void FUN_00c909d0(void* alloc, void* vec, int elemsz, void* p, int n);
struct SplitIsland_Head58
{
    int hdr;
    SplitIsland_Vec48 vec;
    int inlineBuf;
};
struct SplitIsland_Arg1
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int f20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    int fieldD0;
    unsigned char fieldD4;
    unsigned char fD5;
    unsigned short fieldD6;
    int fieldD8;
    int fieldDC;
    int fieldE0;
    int fieldE4;
    int fieldE8;
    int fieldEC;
    int fieldF0;
    int fieldF4;
    int fieldF8;
    int fieldFC;
    int field100;
    int field104;
    int field108;
    int field10C;
    int field110;
    int field114;
    int field118;
    int field11C;
    int field120;
    int field124;
    int field128;
    int field12C;
    int field130;
    int field134;
    int field138;
    int field13C;
    int field140;
    int field144;
    int field148;
    int field14C;
    int field150;
    int field154;
    int field158;
    int field15C;
    int field160;
    int field164;
    int field168;
    int field16C;
    int field170;
    int field174;
    int field178;
    int field17C;
    int field180;
    int field184;
    int field188;
    int field18C;
    int field190;
    int field194;
    int field198;
    int field19C;
    int field1A0;
    int field1A4;
    int field1A8;
    int field1AC;
    int field1B0;
    int field1B4;
    int field1B8;
    int field1BC;
    int field1C0;
    int field1C4;
    int field1C8;
    int field1CC;
    int field1D0;
    int field1D4;
    int field1D8;
    int field1DC;
    int field1E0;
    int field1E4;
    int field1E8;
    int field1EC;
    int field1F0;
    int field1F4;
    int field1F8;
    int field1FC;
    int field200;
    int field204;
    int field208;
    int field20C;
    int field210;
    int field214;
    int field218;
    int field21C;
    int field220;
    int field224;
    int field228;
    int field22C;
    int field230;
    int field234;
    int field238;
    int field23C;
    int field240;
    int field244;
    int field248;
    int field24C;
    int field250;
    int field254;
    int field258;
    int field25C;
    int field260;
    int field264;
    int field268;
    int field26C;
    int field270;
    int field274;
    int field278;
    int field27C;
    int field280;
    int field284;
    int field288;
    int field28C;
    int field290;
    int field294;
    int field298;
    int field29C;
    int field2A0;
    int field2A4;
    int field2A8;
    int field2AC;
    int field2B0;
    int field2B4;
    int field2B8;
    int field2BC;
    int field2C0;
    int field2C4;
    int field2C8;
    int field2CC;
    int field2D0;
    int field2D4;
    int field2D8;
    int field2DC;
    int field2E0;
    int field2E4;
    int field2E8;
    int field2EC;
    int field2F0;
    int field2F4;
    int field2F8;
    int field2FC;
    int field300;
    unsigned char field304;
    unsigned char f305;
    unsigned char f306;
    void FUN_00c911f0(SplitIsland_Arg0* a);
    void FUN_00c91230(SplitIsland_Arg0* a);
};
struct SplitIsland_StreamLink
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char ownerOffset;
    __forceinline SplitIsland_Arg0* SplitIsland_owner()
    {
        return (SplitIsland_Arg0*)((SplitIsland_Node2*)((char*)this + ownerOffset))->fCC;
    }
};
struct SplitIsland_StreamRecord
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
    int unk04;
    int unk08;
    int unk0c;
    SplitIsland_StreamLink* link10;
    SplitIsland_StreamLink* link14;
};
template <class T> class SplitIsland_CursorValue
{
    T value;

  public:
    __forceinline SplitIsland_CursorValue()
    {}
    __forceinline SplitIsland_CursorValue(T p) : value(p)
    {}
    __forceinline void operator=(T p)
    {
        value = p;
    }
    __forceinline T SplitIsland_val() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return SplitIsland_val();
    }
};
template <class T> __forceinline T* SplitIsland_memoryAdvance(T* p, long size)
{
    return (T*)((char*)p + size);
}
struct SplitIsland_ScratchArena
{
    SplitIsland_CursorValue<void*> next;
    SplitIsland_CursorValue<void*> start;
    SplitIsland_CursorValue<void*> end;
    __forceinline void* SplitIsland_allocateRaw(int rounded)
    {
        void* p = next;
        next = SplitIsland_memoryAdvance(p, rounded);
        return p;
    }
    __forceinline void* SplitIsland_allocateRound(int n)
    {
        int rounded = (n + 127) & ~127;
        return SplitIsland_allocateRaw(rounded);
    }
};
__forceinline SplitIsland_ScratchArena& SplitIsland_scratch()
{
    return *(SplitIsland_ScratchArena*)SplitIsland_cursor();
}
template <class T> __forceinline T* SplitIsland_allocateWords(int n)
{
    return (T*)SplitIsland_scratch().SplitIsland_allocateRound(n * sizeof(T));
}
template <class T> struct SplitIsland_StackBuffer
{
    T* data;
    __forceinline SplitIsland_StackBuffer()
    {}
    __forceinline SplitIsland_StackBuffer(int n)
    {
        SplitIsland_allocate(n);
    }
    __forceinline void SplitIsland_allocate(int n)
    {
        int* cur = SplitIsland_cursor();
        int address = *cur;
        *cur = address + ((n * sizeof(T) + 127) & ~127);
        data = (T*)address;
    }
    __forceinline SplitIsland_StackBuffer(int n, bool includeSentinel)
    {
        int* cur = SplitIsland_cursor();
        int address = *cur;
        int elements = n + (includeSentinel ? 1 : 0);
        *cur = address + ((elements * sizeof(T) + 127) & ~127);
        data = (T*)address;
    }
    __forceinline void SplitIsland_release()
    {
        T* p = data;
        *SplitIsland_cursor() = (int)p;
    }
};
template <class T> struct SplitIsland_CountedBuffer : SplitIsland_StackBuffer<T>
{
    int debugCount;
    __forceinline SplitIsland_CountedBuffer(int n) : SplitIsland_StackBuffer<T>(n)
    {}
    __forceinline SplitIsland_CountedBuffer(int n, bool sentinel) : SplitIsland_StackBuffer<T>(n, sentinel)
    {}
};
__forceinline int SplitIsland_packedLevel(unsigned short encoded, unsigned char generation)
{
    int value = encoded;
    if (generation == (value >> 14))
        return (value >> 7) & 127;
    return value & 127;
}
__forceinline int SplitIsland_strongerLevel(int e, int a)
{
    e &= 127;
    a &= 127;
    return a > e ? a : e;
}
struct SplitIsland_WorkArrays
{
    SplitIsland_L60 groups;
    SplitIsland_TempEC members;
};
struct SplitIsland_MapWord
{
    __forceinline void SplitIsland_allocatePlain(int n)
    {
        int* at = SplitIsland_cursor();
        int start = *at;
        *at = start + ((n * 4 + 127) & ~127);
        data = (int*)start;
    }

    int* data;
    int debugCount;
    __forceinline void SplitIsland_allocate(int n)
    {
        data = SplitIsland_allocateWords<int>(n);
    }
    __forceinline void SplitIsland_release()
    {
        int* old = data;
        *SplitIsland_cursor() = (int)old;
    }
};
union SplitIsland_MapReuse
{
    SplitIsland_MapWord map;
    int biggest;
};
__forceinline int SplitIsland_boundedWeight(int minimum, int actual)
{
    return minimum > actual ? minimum : actual;
}
__forceinline void SplitIsland_combineGroups(SplitIsland_Arg1* world, SplitIsland_Obj38& find, SplitIsland_Vec48& nodes,
                                             SplitIsland_L60& sizes, SplitIsland_StackBuffer<char>& flags)
{
    int count = sizes.f04;
    SplitIsland_CountedBuffer<int> totals(count);
    SplitIsland_MapWord active;
    active.SplitIsland_allocate(count);
    for (int i = 0; i < count; ++i)
    {
        active.data[i] = 0;
        totals.data[i] = 0;
    }
    if (world->fD5)
    {
        for (int i = 0; i < nodes.cnt; ++i)
        {
            SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
            int group = (*find.f00)[i];
            int q = SplitIsland_packedLevel(node->fEC, world->f306);
            int a = SplitIsland_packedLevel(node->fEA, world->f305);
            int level = SplitIsland_strongerLevel(q, a);
            if (level <= 5)
                active.data[group] = 1;
            totals.data[group] += SplitIsland_boundedWeight(1, (unsigned short)node->fB0);
        }
    }
    else
    {
        for (int i = 0; i < nodes.cnt; ++i)
        {
            SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
            int group = (*find.f00)[i];
            active.data[group] = 1;
            totals.data[group] += SplitIsland_boundedWeight(1, (unsigned short)node->fB0);
        }
    }
    for (int i = 0; i < count; ++i)
        if (!active.data[i])
            totals.data[i] = -1;
    int* map = active.data;
    int outputs = 0;
    if (count > 0)
    {
        for (int i = 0, *outMap = map; i < count; ++i, ++outMap)
        {
            int weight = totals.data[i];
            if (weight == -2)
                continue;
            int group = outputs++;
            flags.data[group] = 0;
            *outMap = group;
            if (weight < 0)
                continue;
            for (int j = i + 1; j < count; ++j)
            {
                if (weight + 10 >= world->fB4)
                    break;
                int next = totals.data[j];
                if (next < 0)
                    continue;
                int sum = next + weight;
                if (sum >= world->fB4)
                    continue;
                flags.data[group] = 1;
                map[j] = group;
                weight = sum;
                totals.data[j] = -2;
            }
        }
    }
    find.RemapAndAccumulate((int*)&active.data, outputs, &sizes);
    active.SplitIsland_release();
    totals.SplitIsland_release();
}
__forceinline void SplitIsland_classifyParts(SplitIsland_Arg1* world, SplitIsland_Obj38& find, SplitIsland_Vec48& nodes,
                                             SplitIsland_L60& sizes, SplitIsland_StackBuffer<char>& flags)
{
    int count = sizes.f04;
    SplitIsland_MapWord mark;
    mark.SplitIsland_allocatePlain(count);
    for (int i = 0; i < count; ++i)
        mark.data[i] = 0;
    for (int i = 0; i < nodes.cnt; ++i)
    {
        SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
        int q = SplitIsland_packedLevel(node->fEC, world->f306);
        int a = SplitIsland_packedLevel(node->fEA, world->f305);
        if (SplitIsland_strongerLevel(q, a) <= 5)
            mark.data[(*find.f00)[i]] = 1;
    }
    int* map = mark.data;
    int outputs = 1;
    flags.data[0] = (char)outputs;
    for (int i = 0; i < count; ++i)
    {
        if (mark.data[i])
            map[i] = 0;
        else
        {
            map[i] = outputs;
            flags.data[outputs] = 0;
            ++outputs;
        }
    }
    if (outputs > count)
    {
        flags.data[0] = 0;
        mark.SplitIsland_release();
    }
    else
    {
        find.RemapAndAccumulate((int*)&mark.data, outputs, &sizes);
        mark.SplitIsland_release();
    }
}

inline void SplitIsland_Sub30::SplitIsland_readTransfer(SplitIsland_H44& info) const
{
    info.f00 = f14;
    info.f04 = f14;
    info.f06 = f16;
    info.f08 = f18;
}
inline void SplitIsland_Sub30::SplitIsland_debitTransfer(const SplitIsland_H44& info)
{
    f16 -= info.f06;
    f18 -= info.f08;
    f14 -= info.f04;
}
inline void SplitIsland_Arg0::SplitIsland_removeTransfer(SplitIsland_Target* constraint, SplitIsland_H44& info)
{
    if (constraint->f30)
    {
        unk0c -= info.f04;
        unk10 -= info.f06;
        unk14 -= info.f08;
        constraint->f30->SplitIsland_debitTransfer(info);
    }
}
inline void SplitIsland_Target::SplitIsland_assignOwner(SplitIsland_Arg0* p)
{
    SplitIsland_owner = p;
}
__forceinline void SplitIsland_Vec48::SplitIsland_appendNodeUnchecked(SplitIsland_Node2* const& value)
{
    int* destination = data + cnt;
    __assume(destination != 0);
    new (destination) int((int)value);
    ++cnt;
}
// @f3 0x009287f0 (community match, verified in this file)
// Fallout 3 0x009287f0: Havok 5.5.0 hkpWorldOperationUtil::splitSimulationIsland( currentIsland, world, newIslandsOut,
// oldEntitiesOut ) (hkpDynamics.lib, hkpWorldOperationUtil.obj) plus the two island lock calls of the game's build around
// the agent move. Namespace hk550 holds declarations cut from the Havok 5.5.0 SDK headers (preprocessed text): every
// data member and virtual function of each class is kept, unused member functions are cut, hkpShape is only forward
// declared. The two static helpers and the function body were written from the SDK's unoptimized library object.
struct SplitIsland_Arg0; struct SplitIsland_Arg1; struct SplitIsland_Arg2Vec;
void hkpWorldOperationUtil_splitSimulationIsland(SplitIsland_Arg0* a0, SplitIsland_Arg1* a1, SplitIsland_Arg2Vec* a2, void* a3);
namespace hk550
{
typedef float  hkReal;
typedef signed char		hkInt8;
typedef signed short	hkInt16;
typedef signed int		hkInt32;
typedef unsigned char	hkUchar;
typedef unsigned char	hkUint8;
typedef unsigned short	hkUint16;
typedef unsigned int	hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
typedef hkReal hkTime;
__forceinline hkUlong __cdecl hkGetByteOffset( const void* base, const void* pntr)
{
	return hkUlong(pntr) - hkUlong(base);
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAddByteOffset( TYPE* base, hkUlong offset )
{
	return reinterpret_cast<TYPE*>( reinterpret_cast<char*>(base) + offset );
}
__forceinline hkUint32 hkNextPowerOf2(hkUint32 in)
{
	in -= 1;
	in |= in >> 16;
	in |= in >> 8;
	in |= in >> 4;
	in |= in >> 2;
	in |= in >> 1;
	return in + 1;
}
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
inline hkBool(bool b)
		{
			m_bool = static_cast<char>(b);
		}
inline operator bool() const
		{
			return m_bool != 0;
		}
private:
char m_bool;
};
class hkHalf
{
private:
hkInt16 m_value;
};
class hkUFloat8
{
public:
hkUint8 m_value;
};
template<typename ENUM, typename STORAGE>
class hkEnum
{
private:
STORAGE m_storage;
};
template <typename TYPE>
class hkPadSpu
{
public:
__forceinline hkPadSpu() {}
__forceinline hkPadSpu(TYPE e)
			: m_storage( e )
		{
		}
__forceinline TYPE val() const
		{
			return m_storage;
		}
__forceinline operator TYPE() const
		{
			return val();
		}
private:
TYPE m_storage;
};
extern "C" {
__declspec(dllimport) void* _stdcall TlsGetValue( unsigned long dwTlsIndex );
}
template<typename T>
		class hkThreadLocalData
		{
public:
__forceinline T getData() const
				{
					return (T)(hkUlong)TlsGetValue(m_slotID) ;
				}
unsigned long m_slotID;
};
enum HK_MEMORY_CLASS {
	HK_MEMORY_CLASS_ROOT,
	HK_MEMORY_CLASS_BASE,
	HK_MEMORY_CLASS_COLLIDE,
	HK_MEMORY_CLASS_CONSTRAINT_SOLVER,
	HK_MEMORY_CLASS_DYNAMICS,
	HK_MEMORY_CLASS_EXPORT,
	HK_MEMORY_CLASS_SERIALIZE,
	HK_MEMORY_CLASS_GEOMETRY,
	HK_MEMORY_CLASS_DISPLAY,
	HK_MEMORY_CLASS_MATH,
	HK_MEMORY_CLASS_SCENE_DATA,
	HK_MEMORY_CLASS_VEHICLE,
	HK_MEMORY_CLASS_DESTRUCTION,
	HK_MEMORY_CLASS_UTILITIES,
	HK_MEMORY_CLASS_ANIMATION,
	HK_MEMORY_CLASS_BEHAVIOR,
	HK_MEMORY_CLASS_CLOTH,
	HK_MEMORY_CLASS_TOOLS,
	HK_MEMORY_CLASS_DEMO_FRAMEWORK,
	HK_MEMORY_CLASS_DEMO,
	HK_MEMORY_CLASS_USER,
	HK_MEMORY_CLASS_BASE_CLASS,
	HK_MEMORY_CLASS_STRING,
	HK_MEMORY_CLASS_ARRAY,
	HK_MEMORY_CLASS_SINGLETON,
	HK_MEMORY_CLASS_SCRATCHPAD,
	HK_MEMORY_CLASS_STREAM,
	HK_MEMORY_CLASS_MONITOR,
	HK_MEMORY_CLASS_MAP,
	HK_MEMORY_CLASS_TREE,
	HK_MEMORY_CLASS_HKCLASS,
	HK_MEMORY_CLASS_AGENT,
	HK_MEMORY_CLASS_ALGORITHM,
	HK_MEMORY_CLASS_BROAD_PHASE,
	HK_MEMORY_CLASS_CONTACT,
	HK_MEMORY_CLASS_DISPATCH,
	HK_MEMORY_CLASS_MANIFOLD,
	HK_MEMORY_CLASS_SHAPE,
	HK_MEMORY_CLASS_COLLIDABLE,
	HK_MEMORY_CLASS_CDINFO,
	HK_MEMORY_CLASS_MOPP,
	HK_MEMORY_CLASS_ACTION,
	HK_MEMORY_CLASS_DYNCOLLIDE,
	HK_MEMORY_CLASS_DEACTIVATOR,
	HK_MEMORY_CLASS_CONSTRAINT,
	HK_MEMORY_CLASS_ENTITY,
	HK_MEMORY_CLASS_MOTION,
	HK_MEMORY_CLASS_WORLD,
	HK_MEMORY_CLASS_RIGID_BODY,
	HK_MEMORY_CLASS_PHANTOM,
	HK_MEMORY_CLASS_SIMISLAND,
	HK_MEMORY_CLASS_CAMERA,
	HK_MEMORY_CLASS_CHARACTER,
	HK_MEMORY_CLASS_VDB,
	HK_MEMORY_CLASS_INERTIA,
	HK_MEMORY_CLASS_ANIM_UNCOMPRESSED,
	HK_MEMORY_CLASS_ANIM_COMPRESSED,
	HK_MEMORY_CLASS_ANIM_DATA,
	HK_MEMORY_CLASS_ANIM_MOTION,
	HK_MEMORY_CLASS_ANIM_RIG,
	HK_MEMORY_CLASS_ANIM_CONTROL,
	HK_MEMORY_CLASS_ANIM_RUNTIME,
	HK_MEMORY_CLASS_ANIM_CACHE,
	HK_MEMORY_CLASS_BEHAVIOR_RUNTIME,
	HK_MEMORY_CLASS_BEHAVIOR_DEMOS,
	HK_MEMORY_CLASS_CLOTH_RUNTIME,
	HK_MEMORY_CLASS_CLOTH_DATA,
	HK_MEMORY_CLASS_USER_1,
	HK_MEMORY_CLASS_USER_2,
	HK_MEMORY_CLASS_USER_3,
	HK_MEMORY_CLASS_USER_4,
	HK_MEMORY_CLASS_PRE_ALLOCATED,
HK_MEMORY_CLASS_MAX };
class hkMemory;
class hkThreadMemory
{
public:
void* FUN_008f6d30( int nbytes, HK_MEMORY_CLASS cl );
void FUN_008f6d90(void*, int nbytes, HK_MEMORY_CLASS );
__forceinline void* allocateStack(int nbytes);
__forceinline void deallocateStack(void* p);
virtual void* alignedAllocate(int alignment, int nbytes, HK_MEMORY_CLASS cl);
virtual void  alignedDeallocate(void* ptr);
virtual void setStackArea(void* buf, int nbytes);
static inline hkThreadMemory* __cdecl getInstancePtr();
static inline hkThreadMemory& __cdecl getInstance();
virtual void releaseCachedMemory();
__forceinline virtual ~hkThreadMemory(){ releaseCachedMemory(); }
protected:
virtual void* onStackOverflow(int nbytes);
virtual void onStackUnderflow(void* p);
public:
enum
		{
			PAGE_ALIGN  = 64,
			MEMORY_MAX_SMALL_ROW  = 13,
			MEMORY_MAX_ALL_ROW = (MEMORY_MAX_SMALL_ROW+4),
			MEMORY_MAX_SIZE_SMALL_BLOCK  = 512,
			MEMORY_MAX_SIZE_LARGE_BLOCK = 8192,
			MEMORY_LARGE_BLOCK_RSHIFT_BITS = 10,
			MEMORY_SYSTEM_PAGE_SIZE = 8192,
			MEMORY_MAGIC_NUMBER = 0x3425234
		};
struct Stack
		{
__declspec(align(16)) char* m_current;
Stack* m_prev;
char* m_base;
char* m_end;
};
public:
hkMemory* m_memory;
int m_referenceCount;
Stack m_stack;
int m_stackSize;
int m_maxNumElemsOnFreeList;
struct FreeList
		{
struct FreeElem	{
FreeElem* m_next;
};
FreeElem* m_head;
int m_numElem;
};
FreeList m_free_list[MEMORY_MAX_ALL_ROW];
int m_row_to_size_lut[MEMORY_MAX_ALL_ROW];
char m_small_size_to_row_lut[MEMORY_MAX_SIZE_SMALL_BLOCK+1];
int m_large_size_to_row_lut[ (MEMORY_MAX_SIZE_LARGE_BLOCK >> MEMORY_LARGE_BLOCK_RSHIFT_BITS) ];
};
hkThreadMemory* __cdecl hkThreadMemory::getInstancePtr()
{
	extern hkThreadLocalData<hkThreadMemory*> DAT_010f3170;
	return DAT_010f3170.getData();
}
hkThreadMemory& __cdecl hkThreadMemory::getInstance()
{
	hkThreadMemory* instance = getInstancePtr();
	return *instance;
}
template <typename TYPE>	__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0);
class hkFinishLoadedObjectFlag
{
public:
int m_finishing;
};
class hkBaseObject
{
public:
static const struct hkInternalClassMember Members[];
__forceinline virtual ~hkBaseObject() {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
public:
static const struct hkInternalClassMember Members[];
virtual ~hkReferencedObject() { }
virtual void calcStatistics( hkStatisticsCollector* collector ) const;
virtual void calcContentStatistics( hkStatisticsCollector* collector,const hkClass* cls ) const;
public:
hkUint16 m_memSizeAndFlags;
mutable hkInt16 m_referenceCount;
};
namespace hkArrayUtil
{
void __cdecl FUN_00901e90(void*, int numElem, int sizeElem);
void __cdecl FUN_00901f10(void* array, int sizeElem);
void __cdecl hkArrayUtil__reduce(void* array, int sizeElem, char* inplaceMem, int requestedCapacity);
}
template <typename T>
class hkArray
{
public:
__forceinline hkArray(T* ptr, int size, int capacity);
public:
__forceinline ~hkArray();
__forceinline T& operator[] (int i);
__forceinline const T& operator[] (int i) const;
__forceinline int getSize() const;
__forceinline int getCapacity() const;
__forceinline void clear();
__forceinline void pushBack(const T& e);
__forceinline void pushBackUnchecked(const T& e);
__forceinline void reserveExactly(int n);
void swap(hkArray<T>& a);
typedef T* iterator;
__forceinline iterator begin();
public:
enum
		{
			CAPACITY_MASK = int(0x3FFFFFFF),
			FLAG_MASK = int(0xC0000000),
			DONT_DEALLOCATE_FLAG = int(0x80000000),
			LOCKED_FLAG = int(0x40000000),
			FORCE_SIGNED = -1
		};
protected:
void releaseMemory();
T* m_data;
int m_size;
int m_capacityAndFlags;
};
template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
	public:
		typedef hkInplaceArray<T,N> mytype;
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(mytype), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkInplaceArray(int size = 0);
		__forceinline hkInplaceArray(const hkInplaceArray<T,N>& a);
		__forceinline ~hkInplaceArray(){}
		hkArray<T>& operator= (const hkArray<T>& a);
		hkArray<T>& operator= (const hkInplaceArray<T,N>& a);
		__forceinline void optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact=false );
		inline hkBool wasReallocated() const;
		inline int stillInplaceUsingMask() const;
	public:
		T m_storage[N];
	public:
		hkInplaceArray(hkFinishLoadedObjectFlag f) : hkArray<T>(f) { }
};
template <typename T>
__forceinline T& hkArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
__forceinline const T& hkArray<T>::operator[] (int i) const
{
	;
	return m_data[i];
}
template <typename T>
__forceinline int hkArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
__forceinline int hkArray<T>::getCapacity() const
{
	return (m_capacityAndFlags & static_cast<int>(CAPACITY_MASK));
}
template <typename T>
__forceinline void hkArray<T>::clear()
{
	m_size = 0;
}
template <typename T>
__forceinline void hkArray<T>::releaseMemory()
{
	if( (m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
	{
		hkThreadMemory::getInstance().FUN_008f6d90( m_data, getCapacity() * int(sizeof(T)), HK_MEMORY_CLASS_ARRAY);
	}
}
template <typename T>
__forceinline hkArray<T>::hkArray(T* ptr, int size, int capacity)
	:	m_data(ptr),
		m_size(size),
		m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
{
}
template <typename T>
__forceinline hkArray<T>::~hkArray()
{
	releaseMemory();
}
template <typename T>
__forceinline void hkArray<T>::reserveExactly(int n)
{
	if(getCapacity() < n)
	{
		hkArrayUtil::FUN_00901e90(this, n, sizeof(T));
	}
}
template <typename T>
__forceinline void hkArray<T>::pushBack(const T& t)
{
	if(m_size == getCapacity())
	{
		hkArrayUtil::FUN_00901f10( this, sizeof(T) );
	}
	m_data[m_size++] = t;
}
template <typename T>
__forceinline void hkArray<T>::pushBackUnchecked(const T& t)
{
	;
	m_data[m_size++] = t;
}
template <typename T>
void hkArray<T>::swap(hkArray<T>& a)
{
	;
	;
	T* d = m_data;
	m_data = a.m_data;
	a.m_data = d;
	int s = m_size;
	m_size = a.m_size;
	a.m_size = s;
	int c = m_capacityAndFlags;
	m_capacityAndFlags = a.m_capacityAndFlags;
	a.m_capacityAndFlags = c;
}
template <typename T, unsigned N>
__forceinline hkInplaceArray<T,N>::hkInplaceArray(int size)
	: hkArray<T>(m_storage, size, N)
{
}
template <typename T, unsigned N>
__forceinline void hkInplaceArray<T,N>::optimizeCapacity( int numFreeElemsLeft, hkBool32 shrinkExact )
{
	if( (this->m_capacityAndFlags & hkArray<T>::DONT_DEALLOCATE_FLAG) == 0)
	{
		int totalCapacity = (shrinkExact) ? (this->m_size + numFreeElemsLeft) : hkNextPowerOf2(this->m_size + numFreeElemsLeft);
		if( totalCapacity < int(N) )
		{
			hkArrayUtil::hkArrayUtil__reduce( this, int(sizeof(T)), (char*)(&m_storage[0]), N );
		}
		else if( totalCapacity < this->getCapacity() )
		{
			hkArrayUtil::hkArrayUtil__reduce( this, int(sizeof(T)), 0, totalCapacity );
		}
	}
}
template <typename T>
typename hkArray<T>::iterator hkArray<T>::begin()
{
	return m_data;
}
template <typename T>
class hkSmallArray
{
public:
__forceinline int getSize() const;
typedef T* iterator;
__forceinline iterator begin();
protected:
T*			m_data;
hkUint16	m_size;
hkUint16	m_capacityAndFlags;
};
template <typename T>
__forceinline int hkSmallArray<T>::getSize() const
{
	return m_size;
}
template <typename T>
typename hkSmallArray<T>::iterator hkSmallArray<T>::begin()
{
	return m_data;
}
namespace hkMath
{
template <typename T>
	inline T __cdecl max2( T x, T y)
	{
		return x > y ? x : y;
	}
}
class hkVector4
{
private:
__declspec(align(16)) hkReal x;
hkReal y;
hkReal z;
hkReal w;
};
class hkQuaternion
{
public:
hkVector4 m_vec;
};
class hkMatrix3
{
protected:
hkVector4 m_col0;
hkVector4 m_col1;
hkVector4 m_col2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
};
class hkTransform
{
private:
hkRotation m_rotation;
hkVector4 m_translation;
};
class hkSweptTransform
{
public:
static const struct hkInternalClassMember Members[];
public:
hkVector4 m_centerOfMass0;
hkVector4 m_centerOfMass1;
hkQuaternion m_rotation0;
hkQuaternion m_rotation1;
hkVector4 m_centerOfMassLocal;
};
class hkString
{
private:
hkArray<char> m_string;
public:
static void __cdecl FUN_00923500(void* dst, const int c, int nBytes);
};
void* hkThreadMemory::allocateStack(int nbytesin)
{
	int actualBytes = (nbytesin+16) & (~((16)-1));
	char* p = m_stack.m_current;
	char* end = p + actualBytes;
	if( end <= m_stack.m_end )
	{
		m_stack.m_current = end;
		return p;
	}
	else
	{
		return onStackOverflow(actualBytes);
	}
}
void hkThreadMemory::deallocateStack(void* p)
{
	m_stack.m_current = static_cast<char*>(p);
	if( p == m_stack.m_base  )
	{
		onStackUnderflow(p);
	}
}
template <typename TYPE>
__forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what )
{
	hkThreadMemory& mem = hkThreadMemory::getInstance();
	return static_cast<TYPE*>( mem.allocateStack(n*int(sizeof(TYPE))) );
}
template <typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
	hkThreadMemory::getInstance().deallocateStack( static_cast<void*>(ptr) );
}
class hkpCollisionDispatcher;
typedef hkUint32 hkpShapeKey;
class hkpShape;
class hkpCdBody
{
public:
static const struct hkInternalClassMember Members[];
public:
const hkpShape*       m_shape;
hkpShapeKey           m_shapeKey;
const void* m_motion;
const hkpCdBody*		 m_parent;
};
class hkpBroadPhaseHandle
{
public:
static const struct hkInternalClassMember Members[];
hkUint32 m_id;
};
class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:
static const struct hkInternalClassMember Members[];
protected:
hkInt8 m_type;
hkInt8 m_ownerOffset;
public:
hkUint16 m_objectQualityType;
hkUint32 m_collisionFilterInfo;
};
struct hkAabbUint32;
class hkpCollidable : public hkpCdBody
{
public:
static const struct hkInternalClassMember Members[];
inline void* getOwner() const
		{
	        return const_cast<char*>( reinterpret_cast<const char*>(this) + m_ownerOffset );
	    }
public:
struct BoundingVolumeData
		{
static const struct hkInternalClassMember Members[];
public:
hkUint32		m_min[3];
hkUint8			m_expansionMin[3];
hkUint8			m_expansionShift;
hkUint32		m_max[3];
hkUint8			m_expansionMax[3];
hkUint8			m_padding;
hkUint16		m_numChildShapeAabbs;
hkAabbUint32*	m_childShapeAabbs;
};
protected:
hkInt8 m_ownerOffset;
public:
hkUint8   m_forceCollideOntoPpu;
hkUint16 m_shapeSizeOnSpu;
class hkpTypedBroadPhaseHandle m_broadPhaseHandle;
public:
struct BoundingVolumeData m_boundingVolumeData;
hkReal m_allowedPenetrationDepth;
};
struct hkpAgentNnEntry;
class hkpLinkedCollidable: public hkpCollidable
{
public:
static const struct hkInternalClassMember Members[];
public:
struct CollisionEntry
		{
hkpAgentNnEntry* m_agentEntry;
hkpLinkedCollidable*	m_partner;
};
hkArray<struct CollisionEntry> m_collisionEntries;
};
class hkMultiThreadCheck
{
public:
static const struct hkInternalClassMember Members[];
public:
hkUint32 m_threadId;
hkInt16 m_markCount;
protected:
hkUint16 m_markBitStack;
public:
static class hkCriticalSection* m_criticalSection;
};
class hkpWorld;
class hkpRigidBody;
namespace hkWorldOperation
{
enum Result
	{
		POSTPONED,
		DONE
	};
}
class hkpWorldObject : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
virtual hkWorldOperation::Result setShape( const hkpShape* shape );
protected:
virtual class hkMotionState* getMotionState() = 0;
inline virtual ~hkpWorldObject();
protected:
hkpWorld* m_world;
hkUlong m_userData;
protected:
class hkpLinkedCollidable m_collidable;
protected:
class hkMultiThreadCheck m_multiThreadCheck;
const char* m_name;
hkArray<class hkpProperty> m_properties;
};
class hkpMaterial
{
public:
static const struct hkInternalClassMember Members[];
enum ResponseType
		{
			RESPONSE_INVALID,
			RESPONSE_SIMPLE_CONTACT,
			RESPONSE_REPORTING,
			RESPONSE_NONE,
			RESPONSE_MAX_ID
		};
private:
hkEnum<ResponseType,hkInt8> m_responseType;
hkReal m_friction;
hkReal m_restitution;
};
struct hkpSolverInfo
{
enum DeactivationClass
	{
		DEACTIVATION_CLASS_INVALID,
		DEACTIVATION_CLASS_OFF,
		DEACTIVATION_CLASS_LOW,
		DEACTIVATION_CLASS_MEDIUM,
		DEACTIVATION_CLASS_HIGH,
		DEACTIVATION_CLASS_AGGRESSIVE,
		DEACTIVATION_CLASSES_END
	};
struct DeactivationInfo
	{
float m_linearVelocityThresholdInv;
float m_angularVelocityThresholdInv;
float m_slowObjectVelocityMultiplier;
float m_relativeSleepVelocityThreshold;
float m_maxDistSqrd[2];
hkHalf m_maxRotSqrd[2];
};
__declspec(align(16)) float m_one;
float		m_tau;
float		m_damping;
float		m_frictionTau;
hkVector4	m_globalAccelerationPerSubStep;
hkVector4	m_globalAccelerationPerStep;
hkVector4	m_integrateVelocityFactor;
hkVector4	m_invIntegrateVelocityFactor;
float		m_dampDivTau;
float		m_tauDivDamp;
float		m_dampDivFrictionTau;
float		m_frictionTauDivDamp;
float		m_contactRestingVelocity;
DeactivationInfo m_deactivationInfo[ DEACTIVATION_CLASSES_END ];
float		m_deltaTime;
float		m_invDeltaTime;
int			m_numSteps;
int  		m_numMicroSteps;
float		m_invNumMicroSteps;
float		m_invNumSteps;
hkBool		m_forceCoherentConstraintOrderingInSolver;
hkUint8			m_deactivationNumInactiveFramesSelectFlag[2];
hkUint8			m_deactivationIntegrateCounter;
};
struct hkpConstraintInfo
{
int m_maxSizeOfSchema;
int m_sizeOfSchemas;
int m_numSolverResults;
int m_numSolverElemTemps;
inline void add( const hkpConstraintInfo& other);
inline void sub( const hkpConstraintInfo& other);
};
inline void hkpConstraintInfo::add( const hkpConstraintInfo& delta)
{
	m_maxSizeOfSchema = hkMath::max2( m_maxSizeOfSchema, int(delta.m_maxSizeOfSchema));
	m_maxSizeOfSchema = hkMath::max2( m_maxSizeOfSchema, int(delta.m_sizeOfSchemas));
	m_sizeOfSchemas    += delta.m_sizeOfSchemas;
	m_numSolverResults += delta.m_numSolverResults;
	m_numSolverElemTemps += delta.m_numSolverElemTemps;
}
inline void hkpConstraintInfo::sub( const hkpConstraintInfo& delta)
{
	m_sizeOfSchemas    -= delta.m_sizeOfSchemas;
	m_numSolverResults -= delta.m_numSolverResults;
	m_numSolverElemTemps -= delta.m_numSolverElemTemps;
}
class hkpConstraintOwner;
typedef void hkpConstraintRuntime;
class hkpEntity;
class hkpSimulationIsland;
class hkpConstraintInstance : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
enum ConstraintPriority
		{
			PRIORITY_INVALID,
			PRIORITY_PSI,
			PRIORITY_TOI,
			PRIORITY_TOI_HIGHER,
			PRIORITY_TOI_FORCED,
		};
enum InstanceType
		{
			TYPE_NORMAL,
			TYPE_CHAIN
		};
public:
virtual void entityAddedCallback(hkpEntity* entity);
virtual void entityRemovedCallback(hkpEntity* entity);
virtual void entityDeletedCallback( hkpEntity* entity );
inline void setOwner( hkpConstraintOwner* island );
virtual InstanceType getType() const { return TYPE_NORMAL; }
protected:
class hkpConstraintOwner* m_owner;
class hkpConstraintData*  m_data;
struct hkpModifierConstraintAtom* m_constraintModifiers;
class hkpEntity* m_entities[2];
public:
hkEnum<ConstraintPriority,hkUint8> m_priority;
protected:
hkBool				m_wantRuntime;
const char* m_name;
public:
hkUlong m_userData;
struct hkConstraintInternal* m_internal;
};
__declspec(align(16)) struct hkConstraintInternal
{
public:
class hkpConstraintInstance* m_constraint;
class hkpEntity*	  m_entities[2];
protected:
struct hkpConstraintAtom* m_atoms;
hkUint16 m_atomsSize;
public:
hkUint8	m_callbackRequest;
hkEnum<hkpConstraintInstance::ConstraintPriority,hkUint8> m_priority;
hkUint16 m_sizeOfSchemas;
hkUint16 m_numSolverResults;
hkUint16 m_numSolverElemTemps;
inline void getConstraintInfo( hkpConstraintInfo& info ) const;
inline void addConstraintInfo( const hkpConstraintInfo& delta );
inline void subConstraintInfo( const hkpConstraintInfo& delta );
hkUint8	m_whoIsMaster;
hkBool m_isNormalType;
hkpConstraintRuntime*	m_runtime;
hkUint16			m_runtimeSize;
hkObjectIndex		m_slaveIndex;
};
void hkpConstraintInstance::setOwner( hkpConstraintOwner* owner )
{
	m_owner = owner;
}
void hkConstraintInternal::getConstraintInfo( hkpConstraintInfo& info ) const
{
	info.m_maxSizeOfSchema     = m_sizeOfSchemas;
	info.m_sizeOfSchemas       = m_sizeOfSchemas;
	info.m_numSolverResults    = m_numSolverResults;
	info.m_numSolverElemTemps  = m_numSolverElemTemps;
}
void hkConstraintInternal::addConstraintInfo( const hkpConstraintInfo& delta)
{
	const hkUint32 numSolverResults   = this->m_numSolverResults   + delta.m_numSolverResults;
	const hkUint32 numSolverElemTemps = this->m_numSolverElemTemps + delta.m_numSolverElemTemps;
	const hkUint32 sizeOfSchemas      = this->m_sizeOfSchemas      + delta.m_sizeOfSchemas;
	;
	;
	;
	this->m_numSolverResults   = hkUint16(numSolverResults);
	this->m_numSolverElemTemps = hkUint16(numSolverElemTemps);
	this->m_sizeOfSchemas      = hkUint16(sizeOfSchemas);
}
void hkConstraintInternal::subConstraintInfo( const hkpConstraintInfo& delta)
{
	const hkUint32 numSolverResults   = this->m_numSolverResults   - delta.m_numSolverResults;
	const hkUint32 numSolverElemTemps = this->m_numSolverElemTemps - delta.m_numSolverElemTemps;
	const hkUint32 sizeOfSchemas      = this->m_sizeOfSchemas      - delta.m_sizeOfSchemas;
	;
	;
	;
	this->m_numSolverResults = hkUint16(numSolverResults);
	this->m_numSolverElemTemps = hkUint16(numSolverElemTemps);
	this->m_sizeOfSchemas    = hkUint16(sizeOfSchemas);
}
class hkMotionState
{
public:
static const struct hkInternalClassMember Members[];
protected:
hkTransform m_transform;
class hkSweptTransform m_sweptTransform;
public:
hkVector4 m_deltaAngle;
hkReal m_objectRadius;
hkReal	m_linearDamping;
hkReal	m_angularDamping;
hkUFloat8 m_maxLinearVelocity;
hkUFloat8 m_maxAngularVelocity;
hkUint8	m_deactivationClass;
};
class hkpMotion : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_STABILIZED_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_STABILIZED_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};
public:
virtual void setMass(hkReal m);
virtual void setMassInv(hkReal mInv);
virtual void getInertiaLocal(hkMatrix3& inertiaOut) const = 0;
virtual void getInertiaWorld(hkMatrix3& inertiaOut) const = 0;
virtual void setInertiaLocal(const hkMatrix3& inertia) = 0;
virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv) = 0;
virtual void getInertiaInvLocal(hkMatrix3& inertiaInvOut) const = 0;
virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const = 0;
virtual void setCenterOfMassInLocal(const hkVector4& centerOfMass);
virtual void setPosition(const hkVector4& position);
virtual void setRotation(const hkQuaternion& rotation);
virtual void setPositionAndRotation(const hkVector4& position, const hkQuaternion& rotation);
virtual void setTransform(const hkTransform& transform);
virtual void setLinearVelocity(const hkVector4& newVel);
virtual void setAngularVelocity(const hkVector4& newVel);
virtual void applyLinearImpulse(const hkVector4& imp);
virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p) = 0;
virtual void applyAngularImpulse(const hkVector4& imp) = 0;
virtual void applyForce(const hkReal deltaTime, const hkVector4& force) = 0;
virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p) = 0;
virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque) = 0;
public:
virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);
inline int getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag);
public:
hkEnum<MotionType, hkUint8>	m_type;
hkUint8		m_deactivationIntegrateCounter;
hkUint16	m_deactivationNumInactiveFrames[2];
class hkMotionState m_motionState;
hkVector4 m_inertiaAndMassInv;
hkVector4		m_linearVelocity;
hkVector4		m_angularVelocity;
hkVector4 m_deactivationRefPosition[ 2 ];
hkUint32 m_deactivationRefOrientation[2];
class hkpMaxSizeMotion*	m_savedMotion;
hkUint16 m_savedQualityTypeIndex;
};
int hkpMotion::getNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag)
{
	int dc = m_deactivationNumInactiveFrames[select];
	int motionDeactivationFlag = dc >> 14;
	;
	int numInactiveFrames;
	if (worldDeactivationNumInactiveFramesSelectFlag != motionDeactivationFlag)
	{
		numInactiveFrames = dc & 0x7f;
	}
	else
	{
		numInactiveFrames = (dc >> 7) & 0x7f;
	}
	return numInactiveFrames & 0x7f;
}
class hkpKeyframedRigidMotion : public hkpMotion
{
public:
static const struct hkInternalClassMember Members[];
virtual ~hkpKeyframedRigidMotion();
virtual void setMass(hkReal m);
virtual void setMassInv(hkReal mInv);
virtual void getInertiaLocal(hkMatrix3& inertia) const;
virtual void setInertiaLocal(const hkMatrix3& inertia);
virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;
virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);
virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;
virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;
virtual void applyLinearImpulse(const hkVector4& imp);
virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);
virtual void applyAngularImpulse(const hkVector4& imp);
virtual void applyForce(const hkReal deltaTime, const hkVector4& force);
virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);
virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);
public:
virtual void setStepPosition( hkReal position, hkReal timestep );
virtual void setStoredMotion( hkpMaxSizeMotion* savedMotion );
};
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
public:
static const struct hkInternalClassMember Members[];
};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpCollisionListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkpEntity : public hkpWorldObject
{
public:
static const struct hkInternalClassMember Members[];
virtual ~hkpEntity();
inline const hkSmallArray<struct hkConstraintInternal>&  getConstraintMasters() const;
public:
inline hkpMotion* getMotion();
inline hkpSimulationIsland* getSimulationIsland() const;
virtual void deallocateInternalArrays();
virtual hkMotionState* getMotionState(){ return 0; }
protected:
class hkpMaterial m_material;
public:
class SmallArraySerializeOverrideType
		{
public:
static const struct hkInternalClassMember Members[];
void* m_data;
hkUint16 m_size;
hkUint16 m_capacityAndFlags;
};
public:
void* m_breakOffPartsUtil;
public:
hkUint32									m_solverData;
public:
hkObjectIndex								m_storageIndex;
protected:
hkUint16									m_processContactCallbackDelay;
protected:
hkSmallArray<struct hkConstraintInternal>	m_constraintsMaster;
protected:
hkArray<hkpConstraintInstance*>				m_constraintsSlave;
protected:
hkArray<hkUint8> m_constraintRuntime;
hkpSimulationIsland* m_simulationIsland;
public:
hkInt8  m_autoRemoveLevel;
hkUint8 m_numUserDatasInContactPointProperties;
hkUint32 m_uid;
public:
struct SpuCollisionCallback
		{
public:
static const struct hkInternalClassMember Members[];
hkSpuCollisionCallbackUtil* m_util;
hkUint16 m_capacity;
hkUint8 m_eventFilter;
hkUint8	m_userFilter;
};
struct ExtendedListeners
		{
static const struct hkInternalClassMember Members[];
hkSmallArray<hkpEntityActivationListener*>	m_activationListeners;
hkSmallArray<hkpEntityListener*>				m_entityListeners;
};
public:
struct SpuCollisionCallback m_spuCollisionCallback;
protected:
mutable ExtendedListeners* m_extendedListeners;
public:
class hkpMaxSizeMotion m_motion;
protected:
friend class hkpWorldOperationUtil;
friend void ::hkpWorldOperationUtil_splitSimulationIsland(::SplitIsland_Arg0* a0, ::SplitIsland_Arg1* a1, ::SplitIsland_Arg2Vec* a2, void* a3);
hkSmallArray<hkpCollisionListener*>			m_collisionListeners;
hkSmallArray<hkpAction*>						m_actions;
};
inline hkpMotion* hkpEntity::getMotion()
{
	return &m_motion;
}
inline hkpSimulationIsland* hkpEntity::getSimulationIsland() const
{
	return m_simulationIsland;
}
const hkSmallArray<struct hkConstraintInternal>&  hkpEntity::getConstraintMasters() const
{
	return m_constraintsMaster;
}
class hkStepInfo
{
public:
__declspec(align(16)) hkPadSpu<hkTime> m_startTime;
hkPadSpu<hkTime> m_endTime;
hkPadSpu<hkReal> m_deltaTime;
hkPadSpu<hkReal> m_invDeltaTime;
};
class hkAabb
{
public:
static const struct hkInternalClassMember Members[];
public:
hkVector4 m_min;
hkVector4 m_max;
};
class hkpWorldCinfo : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
enum SimulationType
		{
			SIMULATION_TYPE_INVALID,
			SIMULATION_TYPE_DISCRETE,
			SIMULATION_TYPE_CONTINUOUS,
			SIMULATION_TYPE_MULTITHREADED,
		};
enum ContactPointGeneration
		{
			CONTACT_POINT_ACCEPT_ALWAYS,
			CONTACT_POINT_REJECT_DUBIOUS,
			CONTACT_POINT_REJECT_MANY,
		};
enum BroadPhaseBorderBehaviour
		{
			BROADPHASE_BORDER_ASSERT,
			BROADPHASE_BORDER_FIX_ENTITY,
			BROADPHASE_BORDER_REMOVE_ENTITY,
			BROADPHASE_BORDER_DO_NOTHING,
		};
public:
hkVector4 m_gravity;
hkInt32 m_broadPhaseQuerySize;
hkReal m_contactRestingVelocity;
hkEnum<BroadPhaseBorderBehaviour,hkInt8> m_broadPhaseBorderBehaviour;
class hkAabb m_broadPhaseWorldAabb;
hkReal m_collisionTolerance;
class hkpCollisionFilter* m_collisionFilter;
class hkpConvexListFilter* m_convexListFilter;
hkReal m_expectedMaxLinearVelocity;
int m_sizeOfToiEventQueue;
hkReal m_expectedMinPsiDeltaTime;
class hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
hkInt32 m_broadPhaseNumMarkers;
hkEnum<ContactPointGeneration, hkInt8> m_contactPointGeneration;
hkReal m_solverTau;
hkReal m_solverDamp;
hkInt32 m_solverIterations;
hkInt32 m_solverMicrosteps;
hkBool m_forceCoherentConstraintOrderingInSolver;
hkReal m_snapCollisionToConvexEdgeThreshold;
hkReal m_snapCollisionToConcaveEdgeThreshold;
hkBool m_enableToiWeldRejection;
hkBool m_enableDeprecatedWelding;
hkReal m_iterativeLinearCastEarlyOutDistance;
hkInt32 m_iterativeLinearCastMaxIterations;
hkReal m_highFrequencyDeactivationPeriod;
hkReal m_lowFrequencyDeactivationPeriod;
hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
hkUint8 m_deactivationIntegrateCounter;
hkBool m_shouldActivateOnRigidBodyTransformChange;
hkReal m_deactivationReferenceDistance;
hkReal m_toiCollisionResponseRotateNormal;
int m_maxSectorsPerCollideTask;
hkBool m_processToisMultithreaded;
int m_maxEntriesPerToiCollideTask;
hkBool m_enableDeactivation;
hkEnum<SimulationType, hkInt8> m_simulationType;
hkBool m_enableSimulationIslands;
hkUint32 m_minDesiredIslandSize;
hkBool m_processActionsInSingleThread;
hkReal m_frameMarkerPsiSnap;
virtual ~hkpWorldCinfo() {}
};
struct hkpProcessCollisionInput;
class hkpTypedBroadPhaseDispatcher;
class hkpBroadPhase;
class hkpPhantom;
class hkpPhantomListener;
class hkpPhantomBroadPhaseListener;
class hkpEntityEntityBroadPhaseListener;
class hkpBroadPhaseBorderListener;
class hkpActionListener;
class hkpConstraintListener;
struct hkpMultithreadedSimulationJobData;
class hkpWorldPostSimulationListener;
class hkpWorldPostIntegrateListener;
class hkpWorldPostCollideListener;
class hkpWorldDeletionListener;
class hkpIslandActivationListener;
class hkpContactImpulseLimitBreachedListener;
class hkpIslandPostIntegrateListener;
class hkpIslandPostCollideListener;
class hkpSimulation;
class hkpWorldOperationQueue;
struct hkpDebugInfoOnPendingOperationQueues;
class hkpWorldMaintenanceMgr;
struct hkpWorldDynamicsStepInfo
{
hkStepInfo   m_stepInfo;
hkpSolverInfo m_solverInfo;
};
class hkpWorld : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
void hkpWorld_lockForIslandSplit( hkpSimulationIsland* island );
void hkpWorld_unlockForIslandSplit( hkpSimulationIsland* island );
inline const hkpSimulationIsland* getFixedIsland() const;
public:
hkpSimulation* m_simulation;
hkVector4			m_gravity;
hkpSimulationIsland* m_fixedIsland;
hkpRigidBody*	m_fixedRigidBody;
hkArray<hkpSimulationIsland*> m_activeSimulationIslands;
hkArray<hkpSimulationIsland*> m_inactiveSimulationIslands;
hkArray<hkpSimulationIsland*> m_dirtySimulationIslands;
hkpWorldMaintenanceMgr* m_maintenanceMgr;
hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
hkpBroadPhase* m_broadPhase;
hkpTypedBroadPhaseDispatcher*    m_broadPhaseDispatcher;
hkpPhantomBroadPhaseListener*    m_phantomBroadPhaseListener;
hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
hkpMultithreadedSimulationJobData* m_multithreadedSimulationJobData;
hkpProcessCollisionInput* m_collisionInput;
hkpCollisionFilter*       m_collisionFilter;
hkpCollisionDispatcher*   m_collisionDispatcher;
hkpConvexListFilter*     m_convexListFilter;
hkpWorldOperationQueue* m_pendingOperations;
int m_pendingOperationsCount;
int m_criticalOperationsLockCount;
int m_criticalOperationsLockCountForPhantoms;
hkBool m_blockExecutingPendingOperations;
hkBool m_criticalOperationsAllowed;
hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
int m_pendingOperationQueueCount;
mutable class hkMultiThreadCheck m_multiThreadCheck;
hkBool m_processActionsInSingleThread;
hkUint32 m_minDesiredIslandSize;
class hkCriticalSection* m_modifyConstraintCriticalSection;
class hkCriticalSection* m_worldLock;
class hkCriticalSection* m_islandDirtyListCriticalSection;
struct PropertyLock
		{
hkUint32 m_key;
mutable hkMultiThreadCheck m_multiThreadCheck;
};
class hkCriticalSection* m_propertyMasterLock;
hkBool m_wantSimulationIslands;
hkReal m_snapCollisionToConvexEdgeThreshold;
hkReal m_snapCollisionToConcaveEdgeThreshold;
hkBool m_enableToiWeldRejection;
hkBool m_wantDeactivation;
hkBool m_shouldActivateOnRigidBodyTransformChange;
hkReal m_deactivationReferenceDistance;
hkReal m_toiCollisionResponseRotateNormal;
hkBool m_processToisMultithreaded;
int m_maxSectorsPerCollideTask;
int m_maxEntriesPerToiCollideTask;
hkEnum<hkpWorldCinfo::SimulationType,hkInt32>  m_simulationType;
static hkBool m_forceMultithreadedSimulation;
class IgnoreForceMultithreadedSimulation
		{
public:
hkBool m_originalForceMultithreadedSimulationValue;
};
protected:
hkUint32 m_lastEntityUid;
public:
hkArray<hkpPhantom*> m_phantoms;
hkArray<hkpActionListener*>              m_actionListeners;
hkArray<hkpEntityListener*>              m_entityListeners;
hkArray<hkpPhantomListener*>             m_phantomListeners;
hkArray<hkpConstraintListener*>          m_constraintListeners;
hkArray<hkpWorldDeletionListener*>       m_worldDeletionListeners;
hkArray<hkpIslandActivationListener*>    m_islandActivationListeners;
hkArray<hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
hkArray<hkpWorldPostIntegrateListener*>  m_worldPostIntegrateListeners;
hkArray<hkpWorldPostCollideListener*>    m_worldPostCollideListeners;
hkArray<hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
hkArray<hkpIslandPostCollideListener*>   m_islandPostCollideListeners;
hkArray<hkpCollisionListener*>           m_collisionListeners;
hkArray<hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
class hkpBroadPhaseBorder*               m_broadPhaseBorder;
public:
struct hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
hkVector4 m_broadPhaseExtents[2];
int			m_broadPhaseNumMarkers;
int			m_sizeOfToiEventQueue;
hkInt32		m_broadPhaseQuerySize;
hkInt32		m_broadPhaseUpdateSize;
hkEnum<hkpWorldCinfo::ContactPointGeneration, hkInt8> m_contactPointGeneration;
};
inline const hkpSimulationIsland* hkpWorld::getFixedIsland() const
{
	;
	return m_fixedIsland;
}
class hkpWorldOperationUtil
{
public:
public:
__forceinline static int  __cdecl estimateIslandSize( int numEntities, int numConstraints );
__forceinline static bool __cdecl	canIslandBeSparse( hkpWorld* world, int islandSize );
};
class hkpConstraintOwner: public hkReferencedObject
{
public:
inline void addConstraintInfo( hkpConstraintInstance* constraint, hkpConstraintInfo& delta )
		{
			;
			if ( constraint->m_internal )
			{
				m_constraintInfo.add( delta );
				constraint->m_internal->addConstraintInfo( delta );
				m_constraintInfo.m_maxSizeOfSchema = hkMath::max2( int(m_constraintInfo.m_maxSizeOfSchema), int(constraint->m_internal->m_sizeOfSchemas) );
			}
		}
inline void subConstraintInfo( hkpConstraintInstance* constraint, hkpConstraintInfo& delta )
		{
			;
			if ( constraint->m_internal )
			{
				m_constraintInfo.sub( delta );
				constraint->m_internal->subConstraintInfo( delta );
			}
		}
public:
virtual void addConstraintToCriticalLockedIsland(      hkpConstraintInstance* constraint ){}
virtual void removeConstraintFromCriticalLockedIsland( hkpConstraintInstance* constraint ){}
virtual void addCallbackRequest( hkpConstraintInstance* constraint, int request ){}
virtual void checkAccessRw() {}
public:
hkpConstraintInfo m_constraintInfo;
};
class hkpContactMgr;
struct hkpAgentEntry
{
hkUchar     m_streamCommand;
hkUchar     m_agentType;
hkUchar     m_numContactPoints;
hkUchar     m_size;
};
struct hkpAgentNnEntry: hkpAgentEntry
{
hkObjectIndex		m_agentIndexOnCollidable[2];
hkpContactMgr*		m_contactMgr;
hkUchar				m_collisionQualityIndex;
hkUchar				m_forceCollideOntoPpu;
hkUchar				m_padding[2];
hkpLinkedCollidable*	m_collidable[2];
};
struct hkpAgentNnSector
{
hkUint8 m_data[ 512 ];
hkpAgentNnEntry* getBegin()
	{
		return reinterpret_cast<hkpAgentNnEntry*>( &m_data[0] );
	}
};
struct hkpAgentNnTrack
{
hkpAgentNnTrack( )
	{
		m_bytesUsedInLastSector = 512;
		;
	}
int getSectorSize( int sectorIndex ) const
	{
		if ( sectorIndex+1 == m_sectors.getSize())
		{
			return m_bytesUsedInLastSector;
		}
		return 512;
	}
hkUint32	m_bytesUsedInLastSector;
hkInplaceArray<hkpAgentNnSector*,1> m_sectors;
};
class hkUnionFind;
class hkpSimulationIsland : public hkpConstraintOwner
{
public:
__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; hkReferencedObject* b = static_cast<hkReferencedObject*>(hkThreadMemory::getInstance().FUN_008f6d30(static_cast<int>(nbytes),HK_MEMORY_CLASS_SIMISLAND)); b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes); return b; }
inline hkBool isFixed() const;
protected:
friend class hkpWorldOperationUtil;
friend void ::hkpWorldOperationUtil_splitSimulationIsland(::SplitIsland_Arg0* a0, ::SplitIsland_Arg1* a1, ::SplitIsland_Arg2Vec* a2, void* a3);
hkpSimulationIsland( hkpWorld* world );
virtual void addConstraintToCriticalLockedIsland(      hkpConstraintInstance* constraint );
virtual void removeConstraintFromCriticalLockedIsland( hkpConstraintInstance* constraint );
virtual void addCallbackRequest( hkpConstraintInstance* constraint, int request );
protected:
hkBool hkpSimulationIsland_isFullyConnected( hkUnionFind& checkConnectivityOut );
public:
hkpWorld*	m_world;
int m_numConstraints;
hkObjectIndex m_storageIndex;
hkObjectIndex m_dirtyListIndex;
hkUchar m_splitCheckFrameCounter;
bool m_splitCheckRequested:2;
bool m_sparseEnabled:2;
bool m_actionListCleanupNeeded:2;
bool m_allowIslandLocking:2;
bool m_isInActiveIslandsArray:2;
bool m_activeMark:2;
bool m_inIntegrateJob:2;
protected:
mutable hkMultiThreadCheck m_multiThreadCheck;
public:
hkReal m_timeSinceLastHighFrequencyCheck;
hkReal m_timeSinceLastLowFrequencyCheck;
hkArray<hkpAction*> m_actions;
hkTime m_timeOfDeactivation;
hkInplaceArray<hkpEntity*,1> m_entities;
hkpAgentNnTrack m_agentTrack;
;
};
inline hkBool hkpSimulationIsland::isFixed() const
{
	return m_storageIndex == 0xffff;
}
int hkpWorldOperationUtil::estimateIslandSize( int numEntities, int numConstraints )
{
	return hkMath::max2(numEntities, numConstraints);
}
bool hkpWorldOperationUtil::canIslandBeSparse( hkpWorld* world, int size )
{
	return size < int(world->m_minDesiredIslandSize);
}
template <typename T>
class hkFixedArray
{
public:
__forceinline T& operator[] (int i);
__forceinline T* begin();
protected:
__forceinline	hkFixedArray(){}
hkPadSpu<T*> m_data;
int m_debugSize;
};
template <typename T>
class hkLocalBuffer: public hkFixedArray<T>
{
	public:
		__forceinline void* __cdecl operator new(hk_size_t nbytes) { ; return hkThreadMemory::getInstance().allocateChunkConstSize(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete(void* p) { if (p) hkThreadMemory::getInstance().deallocateChunkConstSize(p, sizeof(hkLocalBuffer<T>), HK_MEMORY_CLASS_ARRAY); } __forceinline void* __cdecl operator new[](hk_size_t nbytes) { return hkThreadMemory::getInstance().allocate(static_cast<int>(nbytes),HK_MEMORY_CLASS_ARRAY); } __forceinline void __cdecl operator delete[](void* p) { hkThreadMemory::getInstance().deallocate(p); } __forceinline void* __cdecl operator new(hk_size_t n, void* p){ ; return p; } __forceinline void* __cdecl operator new[](hk_size_t, void* p){ return p; } __forceinline void __cdecl operator delete(void*, void*) { } __forceinline void __cdecl operator delete[](void*, void*) { } class MustEndWithSemiColon;
		__forceinline hkLocalBuffer(int n, const char* what = 0 );
		__forceinline ~hkLocalBuffer();
};
template <typename T>
__forceinline hkLocalBuffer<T>::hkLocalBuffer( int capacity, const char* what )
{
	this->m_data = hkAllocateStack<T>(capacity);
	;
}
template <typename T>
__forceinline hkLocalBuffer<T>::~hkLocalBuffer()
{
	hkDeallocateStack( this->m_data.val() );
}
template <typename T>
__forceinline T& hkFixedArray<T>::operator[] (int i)
{
	;
	return m_data[i];
}
template <typename T>
T* hkFixedArray<T>::begin()
{
	return m_data;
}
class hkUnionFind
{
public:
typedef hkFixedArray<int>	IntArray;
public:
hkUnionFind( IntArray& parents, int numElements );
void FUN_009ad3a0( hkArray<int>& elementsPerGroup );
void FUN_009ad510( const hkFixedArray<int>& newIndices, int numNewGroups, hkArray<int>& elementsPerGroup );
int FUN_009ad420( hkArray<int>& elementsPerGroup );
public:
IntArray&	m_parents;
int m_numNodes;
};
namespace hkAlgorithm
{
template<typename T>
	__forceinline void __cdecl swap(T& x, T& y)
	{
		T t(x);
		x = y;
		y = t;
	}
}
class hkpAction : public hkReferencedObject
{
public:
static const struct hkInternalClassMember Members[];
virtual ~hkpAction() { }
virtual void applyAction( const hkStepInfo& stepInfo ) = 0;
virtual void getEntities( hkArray<hkpEntity*>& entitiesOut ) = 0;
virtual void getPhantoms( hkArray<hkpPhantom*>& phantomsOut ) {}
virtual void entityRemovedCallback(hkpEntity* entity) = 0;
virtual hkpAction* clone( const hkArray<hkpEntity*>& newEntities, const hkArray<hkpPhantom*>& newPhantoms ) const = 0;
private:
hkpWorld* m_world;
hkpSimulationIsland* m_island;
protected:
hkUlong m_userData;
const char* m_name;
public:
inline void setSimulationIsland(hkpSimulationIsland* island);
};
inline void hkpAction::setSimulationIsland( hkpSimulationIsland* isl )
{
	m_island = isl;
}
extern "C"
{
void __cdecl FUN_00998ba0(hkpAgentNnTrack& track, hkpAgentNnEntry* entry);
hkpAgentNnEntry* __cdecl hkAgentNnMachine_CopyAndRelinkAgentEntry( hkpAgentNnTrack& destTrack, hkpAgentNnEntry* entry );
}
static __forceinline void __cdecl identifyDeactivatedSubgroups( hkUnionFind& checker, const hkArray<hkpEntity*>& entities, const hkpWorld* world, hkArray<int>& groupsSizes, hkFixedArray<hkInt8>& groupSparse )
{
	int numGroups = groupsSizes.getSize();
	hkLocalBuffer<int> isActive( numGroups );
	{
		for (int i = 0; i < numGroups; i++ )
		{
			isActive[i] = 0;
		}
	}
	{
		const hkUint8* flags = world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag;
		for (int i = 0; i < entities.getSize(); i++ )
		{
			hkpEntity* entity = entities[i];
			int numInactiveFrames = hkMath::max2( entity->getMotion()->getNumInactiveFramesMt( 0, flags[0] ), entity->getMotion()->getNumInactiveFramesMt( 1, flags[1] ) );
			if ( numInactiveFrames <= 5 )
			{
				int group = checker.m_parents[i];
				isActive[group] = 1;
			}
		}
	}
	int numNewGroups = 1;
	int* newIndex = isActive.begin();
	groupSparse[0] = 1;
	{
		for (int i = 0; i < numGroups; i++ )
		{
			if ( isActive[i] )
			{
				newIndex[i] = 0;
			}
			else
			{
				newIndex[i] = numNewGroups;
				groupSparse[numNewGroups] = 0;
				numNewGroups++;
			}
		}
	}
	if ( numNewGroups > numGroups )
	{
		groupSparse[0] = 0;
		return;
	}
	checker.FUN_009ad510( isActive, numNewGroups, groupsSizes );
}
static __forceinline void __cdecl mergeSmallSubgroups( hkpWorld* world, hkUnionFind& checker, const hkArray<hkpEntity*>& entities, hkArray<int>& groupsSizes, hkFixedArray<hkInt8>& groupSparse )
{
	int numGroups = groupsSizes.getSize();
	hkLocalBuffer<int> sizes( numGroups );
	hkLocalBuffer<int> isActive( numGroups );
	{
		for (int i = 0; i < numGroups; i++ )
		{
			isActive[i] = 0;
			sizes[i] = 0;
		}
	}
	if ( world->m_wantDeactivation )
	{
		const hkUint8* flags = world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag;
		for (int i = 0; i < entities.getSize(); i++ )
		{
			hkpEntity* entity = entities[i];
			int group = checker.m_parents[i];
			int numInactiveFrames = hkMath::max2( entity->getMotion()->getNumInactiveFramesMt( 0, flags[0] ), entity->getMotion()->getNumInactiveFramesMt( 1, flags[1] ) );
			if ( numInactiveFrames <= 5 )
			{
				isActive[group] = 1;
			}
			int size = hkpWorldOperationUtil::estimateIslandSize( 1, entity->getConstraintMasters().getSize() );
			sizes[group] += size;
		}
	}
	else
	{
		for (int i = 0; i < entities.getSize(); i++ )
		{
			hkpEntity* entity = entities[i];
			int group = checker.m_parents[i];
			isActive[group] = 1;
			int size = hkpWorldOperationUtil::estimateIslandSize( 1, entity->getConstraintMasters().getSize() );
			sizes[group] += size;
		}
	}
	{
		for (int i = 0; i < numGroups; i++ )
		{
			if ( !isActive[i] )
			{
				sizes[i] = -1;
			}
		}
	}
	int numNewGroups = 0;
	int* newIndex = isActive.begin();
	int minSize = hkpWorldOperationUtil::estimateIslandSize( 10, 10 );
	{
		for (int i = 0; i < numGroups; i++ )
		{
			int size = sizes[i];
			if ( size == -2 )
			{
				continue;
			}
			int newGroup = numNewGroups++;
			groupSparse[newGroup] = 0;
			newIndex[i] = newGroup;
			if ( size < 0 )
			{
				continue;
			}
			for (int j = i+1; j < numGroups; j++ )
			{
				if ( !hkpWorldOperationUtil::canIslandBeSparse( world, size + minSize ) )
				{
					break;
				}
				int otherSize = sizes[j];
				if ( otherSize < 0 )
				{
					continue;
				}
				if ( hkpWorldOperationUtil::canIslandBeSparse( world, size + otherSize ) )
				{
					groupSparse[newGroup] = 1;
					newIndex[j] = newGroup;
					size += otherSize;
					sizes[j] = -2;
				}
			}
		}
	}
	checker.FUN_009ad510( isActive, numNewGroups, groupsSizes );
}
}
// pdb: hkpWorldOperationUtil::splitSimulationIsland | hkpWorldOperationUtil.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_gap) + skyrim(call_seq), high
void hkpWorldOperationUtil_splitSimulationIsland(SplitIsland_Arg0* a0, SplitIsland_Arg1* a1, SplitIsland_Arg2Vec* a2, void* a3)
{
	// the SDK names used below, bound from the namespace that holds the SDK declarations
	using hk550::hkLocalBuffer;
	using hk550::hkFixedArray;
	using hk550::hkUnionFind;
	using hk550::hkBool;
	using hk550::hkInplaceArray;
	using hk550::hkArray;
	using hk550::hkInt8;
	using hk550::hkUchar;
	using hk550::hkUlong;
	using hk550::hkObjectIndex;
	using hk550::hkString;
	using hk550::hkpSimulationIsland;
	using hk550::hkpWorld;
	using hk550::hkpEntity;
	using hk550::hkConstraintInternal;
	using hk550::hkpConstraintInfo;
	using hk550::hkpAction;
	using hk550::hkpAgentNnTrack;
	using hk550::hkpAgentNnSector;
	using hk550::hkpAgentNnEntry;
	using hk550::hkAddByteOffset;
	using hk550::hkGetByteOffset;
	using hk550::hkThreadMemory;
	using hk550::hkAgentNnMachine_CopyAndRelinkAgentEntry;
	using hk550::FUN_00998ba0;
	using hk550::HK_MEMORY_CLASS_CDINFO;
	using hk550::identifyDeactivatedSubgroups;
	using hk550::mergeSmallSubgroups;
	hkpSimulationIsland* currentIsland = (hkpSimulationIsland*)a0;
	hkpWorld* world = (hkpWorld*)a1;
	hkArray<hkpSimulationIsland*>& newIslandsOut = *(hkArray<hkpSimulationIsland*>*)a2;
	hkArray<hkpEntity*>* oldEntitiesOut = (hkArray<hkpEntity*>*)a3;
	hkLocalBuffer<int> entityInfo( currentIsland->m_entities.getSize() );
	hkFixedArray<int>* fixedArray = &entityInfo;
	hkUnionFind checker( *fixedArray, currentIsland->m_entities.getSize() );
	hkBool isConnected = currentIsland->hkpSimulationIsland_isFullyConnected( checker );
	if ( isConnected )
	{
		currentIsland->m_sparseEnabled = false;
		return;
	}
	hkInplaceArray<int,32> groupsSizes; checker.FUN_009ad3a0( groupsSizes );
	hkLocalBuffer<hkInt8> groupSparse( groupsSizes.getSize()+1 );
	if ( currentIsland->m_sparseEnabled )
	{
		if ( world->m_wantDeactivation )
		{
			identifyDeactivatedSubgroups( checker, currentIsland->m_entities, world, groupsSizes, groupSparse );
			if ( groupsSizes.getSize() == 1 )
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	else if ( world->m_minDesiredIslandSize != 0 )
	{
		mergeSmallSubgroups( world, checker, currentIsland->m_entities, groupsSizes, groupSparse );
	}
	else
	{
		hkString::FUN_00923500( groupSparse.begin(), 0, groupsSizes.getSize()+1 );
	}
	{
		int index = checker.FUN_009ad420( groupsSizes );
		hkInt8 h = groupSparse[0];
		groupSparse[0] = groupSparse[index];
		groupSparse[index] = h;
	}
	int biggestGroupSize = groupsSizes[0];
	int numAllEntities = currentIsland->m_entities.getSize();
	int numNewIslands = groupsSizes.getSize();
	if ( numNewIslands == 1 )
	{
		return;
	}
	hkLocalBuffer<hkpSimulationIsland*> islands( numNewIslands );
	currentIsland->m_sparseEnabled = ( groupSparse[0] != 0 );
	{
		islands[0] = currentIsland;
		for ( int j = 1; j < numNewIslands; j++ )
		{
			hkpSimulationIsland* newIsland = new hkpSimulationIsland( world );
			newIsland->m_activeMark = true;
			newIsland->m_isInActiveIslandsArray = true;
			newIsland->m_sparseEnabled = ( groupSparse[j] != 0 );
			newIsland->m_storageIndex = (hkObjectIndex)newIslandsOut.getSize();
			newIslandsOut.pushBack( newIsland );
			islands[j] = newIsland;
			int numEntitiesCapacity = groupsSizes[j];
			newIsland->m_entities.reserveExactly( numEntitiesCapacity );
		}
	}
	{
		hkpEntity** oldEntities = currentIsland->m_entities.begin();
		int oldSize = currentIsland->m_entities.getSize();
		if ( oldEntitiesOut )
		{
			currentIsland->m_entities.swap( *oldEntitiesOut );
			currentIsland->m_entities.clear();
			currentIsland->m_entities.reserveExactly( groupsSizes[0] );
		}
		else
		{
			currentIsland->m_entities.clear();
		}
		for ( int e = 0; e < oldSize; e++ )
		{
			hkpSimulationIsland* newIsland = islands[ entityInfo[e] ];
			hkpEntity* entity = oldEntities[e];
			entity->m_simulationIsland = newIsland;
			entity->m_storageIndex = (hkObjectIndex)newIsland->m_entities.getSize();
			newIsland->m_entities.pushBackUnchecked( entity );
			if ( currentIsland != newIsland )
			{
				hkConstraintInternal* ci = entity->m_constraintsMaster.begin();
				for ( int j = 0; j < entity->m_constraintsMaster.getSize(); ci++, j++ )
				{
					hkpConstraintInfo info; ci->getConstraintInfo( info );
					info.m_maxSizeOfSchema = currentIsland->m_constraintInfo.m_maxSizeOfSchema;
					currentIsland->m_numConstraints--;
					currentIsland->subConstraintInfo( ci->m_constraint, info );
					newIsland->m_numConstraints++;
					ci->m_constraint->setOwner( newIsland );
					newIsland->addConstraintInfo( ci->m_constraint, info );
				}
			}
		}
	}
	{
		const hkpSimulationIsland* fixedIsland = world->getFixedIsland();
		hkpAction** oldActions = currentIsland->m_actions.begin();
		int oldActionSize = currentIsland->m_actions.getSize();
		currentIsland->m_actions.clear();
		for ( int j = 0; j < oldActionSize; j++ )
		{
			hkpAction* action = oldActions[j];
			if ( action )
			{
				hkpSimulationIsland* movingIsland = 0;
				{
					hkInplaceArray<hkpEntity*,16> entities;
					action->getEntities( entities );
					for ( int k = 0; k < entities.getSize(); k++ )
					{
						movingIsland = entities[k]->getSimulationIsland();
						if ( movingIsland != fixedIsland )
						{
							break;
						}
					}
				}
				action->setSimulationIsland( movingIsland );
				movingIsland->m_actions.pushBack( action );
			}
		}
	}
	world->hkpWorld_lockForIslandSplit( currentIsland );
	int entitiesInSmallerGroups = numAllEntities - biggestGroupSize;
	if ( (entitiesInSmallerGroups << 3) < numAllEntities )
	{
		hkpAgentNnTrack& track = currentIsland->m_agentTrack;
		for ( int sectorIndex = 0; sectorIndex < track.m_sectors.getSize(); sectorIndex++ )
		{
			hkpAgentNnSector* currentSector = track.m_sectors[sectorIndex];
			hkpAgentNnEntry* entry = currentSector->getBegin();
			while ( entry < hkAddByteOffset( currentSector->getBegin(), track.getSectorSize( sectorIndex ) ) )
			{
				hkpSimulationIsland* newIsland = static_cast<hkpEntity*>( entry->m_collidable[0]->getOwner() )->getSimulationIsland();
				if ( newIsland->isFixed() )
				{
					newIsland = static_cast<hkpEntity*>( entry->m_collidable[1]->getOwner() )->getSimulationIsland();
				}
				if ( newIsland == currentIsland )
				{
					entry = hkAddByteOffset( entry, entry->m_size );
				}
				else
				{
					hkUlong entryOffset = hkGetByteOffset( currentSector, entry );
					hkAgentNnMachine_CopyAndRelinkAgentEntry( newIsland->m_agentTrack, entry );
					FUN_00998ba0( track, entry );
					if ( sectorIndex >= track.m_sectors.getSize() )
					{
						break;
					}
					currentSector = track.m_sectors[sectorIndex];
					entry = hkAddByteOffset( currentSector->getBegin(), entryOffset );
				}
			}
		}
	}
	else
	{
		hkpAgentNnTrack track;
		if ( currentIsland->m_agentTrack.m_sectors.getSize() == 1 )
		{
			track.m_sectors.pushBackUnchecked( currentIsland->m_agentTrack.m_sectors[0] );
			currentIsland->m_agentTrack.m_sectors.clear();
		}
		else if ( currentIsland->m_agentTrack.m_sectors.getSize() > 1 )
		{
			track.m_sectors.reserveExactly( 2 );
			track.m_sectors.swap( currentIsland->m_agentTrack.m_sectors );
		}
		hk550::hkAlgorithm::swap( track.m_bytesUsedInLastSector, currentIsland->m_agentTrack.m_bytesUsedInLastSector );
		for ( int sectorIndex = 0; sectorIndex < track.m_sectors.getSize(); sectorIndex++ )
		{
			hkpAgentNnSector* currentSector = track.m_sectors[sectorIndex];
			hkpAgentNnEntry* entry = currentSector->getBegin();
			hkpAgentNnEntry* endEntry = hkAddByteOffset( entry, track.getSectorSize( sectorIndex ) );
			for ( ; entry < endEntry; entry = hkAddByteOffset( entry, entry->m_size ) )
			{
				hkpSimulationIsland* newIsland = static_cast<hkpEntity*>( entry->m_collidable[0]->getOwner() )->getSimulationIsland();
				if ( newIsland->isFixed() )
				{
					newIsland = static_cast<hkpEntity*>( entry->m_collidable[1]->getOwner() )->getSimulationIsland();
				}
				hkAgentNnMachine_CopyAndRelinkAgentEntry( newIsland->m_agentTrack, entry );
			}
			hkThreadMemory::getInstance().FUN_008f6d90( currentSector, 512, HK_MEMORY_CLASS_CDINFO );
		}
		track.m_sectors.clear();
	}
	world->hkpWorld_unlockForIslandSplit( currentIsland );
	currentIsland->m_agentTrack.m_sectors.optimizeCapacity( 4 );
	for ( int i = 1; i < numNewIslands; i++ )
	{
		islands[i]->m_splitCheckFrameCounter = hkUchar( currentIsland->m_splitCheckFrameCounter + hkUchar(i) );
	}
}


__forceinline int SplitIsland_largerContribution(int a, int b)
{
    return a > b ? a : b;
}
// pdb: hkpConstraintOwner::addConstraintInfo | hkpWorldOperationUtil.obj | fnv360_0822_retail, caller, high (was: AccumulateStats)
inline void SplitIsland_Arg0::hkpConstraintOwner_addConstraintInfo(SplitIsland_Target* constraint, SplitIsland_H44& info)
{
    if (constraint->f30)
    {
        unk08 = SplitIsland_largerContribution(unk08, info.f00);
        unk08 = SplitIsland_largerContribution(unk08, info.f04);
        unk0c += info.f04;
        unk10 += info.f06;
        unk14 += info.f08;
        SplitIsland_Sub30* rec = constraint->f30;
        const unsigned int r = rec->f16 + info.f06;
        const unsigned int t = rec->f18 + info.f08;
        const unsigned int b = rec->f14 + info.f04;
        rec->f16 = (unsigned short)r;
        rec->f18 = (unsigned short)t;
        rec->f14 = (unsigned short)b;
        unk08 = SplitIsland_largerContribution(unk08, (int)constraint->f30->f14);
    }
}
