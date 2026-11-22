#include "f3_common.h"
// src/havok/common/base/object/hkreferencedobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/object/hkreferencedobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkReferencedObject.h"

struct FUN_00c903b0_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    void ReleaseReference();
};

// @fnv 0x00c903b0
void FUN_00c903b0_class::ReleaseReference()
{
    if (m_uiObjectFlags)
    {
        --m_uCount;
        if (!m_uCount)
            ((void(__thiscall*)(void*, int))m_pVTable[0])(this, 1);
    }
}

// hkReferencedObject
struct hkReferencedObjectC903
{
    virtual ~hkReferencedObjectC903();
    unsigned short m_memSizeAndFlags;  // +0x04
    short m_referenceCount;            // +0x06
    void hkSweptTransformUtil_setTimeInformation();
};

// @fnv 0x00c903a0
// pdb: hkSweptTransformUtil::setTimeInformation | hkSweptTransformUtil.obj | fnv360_0721_beta, call_gap + skyrim(call_gap), high
void hkReferencedObjectC903::hkSweptTransformUtil_setTimeInformation()
{
    if (m_memSizeAndFlags != 0)
        m_referenceCount++;
}

extern int DAT_012681d4;

extern int DAT_0102e388;

// @fnv 0x00c903d0
// pdb: bhkListShape::GetRTTI | bhkCharacterController.obj | fnv360_0721_beta, objrun_open, low
int* __cdecl FUN_00c903d0()
{
    return &DAT_0102e388;
}

struct DDCC60World
{
    void removeReference();
};
struct RefObj
{
    void RetainReference();
};

namespace fnv_00d47750 {
struct RefObj
{
    void FUN_00c90510();
};

}  // namespace fnv_00d47750

namespace fnv_00dee6f0 {
struct RefObj
{
    void FUN_00c90510();
};
}  // namespace fnv_00dee6f0

namespace fnv_00e3e840 {
struct FUN_00d1df70
{
    void RetainReference();
};

struct DDCC60World : public FUN_00d1df70
{
    void removeReference();
};

}  // namespace fnv_00e3e840

extern int DAT_012681d4;

struct ThreadMode_9bf0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int m_currentMode;
};
__declspec(thread) ThreadMode_9bf0 tls_9bf0;
struct RestoreMode_9bf0
{
    unsigned int original;
    RestoreMode_9bf0() : original(tls_9bf0.m_currentMode)
    {
        tls_9bf0.m_currentMode = 0x10;
    }
    ~RestoreMode_9bf0()
    {
        tls_9bf0.m_currentMode = original;
    }
};

struct Obj
{
    int a;
    unsigned short w;
    void Init();
};
struct Alloc
{
    virtual ~Alloc();
    virtual Obj* Allocate(unsigned n);
};
struct Mgr
{
    char pad[0x10];
    Alloc* m_alloc;
    Obj* New(unsigned n)
    {
        return m_alloc->Allocate(n);
    }
};
Mgr* FUN_00c85750();

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long index, void* value);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* section);
extern int DAT_012681d4;
extern int DAT_012681d8;

extern int DAT_012681d4;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* pvValue);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkSection);

struct hkCriticalSectionDataC905
{
    void* m_debugInfo;
    long m_lLockCount;
    long m_recursionCount;
    void* m_owningThread;
    void* m_lockSemaphore;
    unsigned long m_spinCount;
};

struct hkReferencedObjectLockC905
{
    int unk00;
    int unk04;
    int m_multiThreaded;
    int m_lLockCount;
    int unk10;
    int unk14;
    hkCriticalSectionDataC905 m_kCriticalSection;
};

class hkReferencedObjectC905 : public hkReferencedObject
{
  public:
    void FUN_00c905b0();
};

// @fnv 0x00c905b0
void hkReferencedObjectC905::FUN_00c905b0()
{
    if (m_usMemSizeAndFlags != 0)
    {
        if (m_sReferenceCount == 1)
        {
            m_sReferenceCount = 0;
            delete this;
            return;
        }
        hkReferencedObjectLockC905* pkLock = reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4);
        const unsigned long& kTls = reinterpret_cast<const unsigned long*>(&DAT_012681d4)[1];
        if (pkLock->m_multiThreaded == 1 && TlsGetValue(kTls) != reinterpret_cast<void*>(0x23df4554))
        {
            if (TlsGetValue(kTls) == reinterpret_cast<void*>(0x23df4554))
            {
                pkLock->m_lLockCount++;
            }
            else
            {
                EnterCriticalSection(&pkLock->m_kCriticalSection);
                pkLock->m_lLockCount = 1;
                TlsSetValue(kTls, reinterpret_cast<void*>(0x23df4554));
            }
            m_sReferenceCount--;
            if (--pkLock->m_lLockCount <= 0)
            {
                TlsSetValue(kTls, 0);
                LeaveCriticalSection(&pkLock->m_kCriticalSection);
            }
        }
        else
        {
            m_sReferenceCount--;
        }
    }
}

extern __declspec(thread) int g_threadFlag;
struct ThreadFlagGuard
{
    int previousFlag;
    ThreadFlagGuard() : previousFlag(g_threadFlag)
    {
        g_threadFlag = 16;
    }
    ~ThreadFlagGuard()
    {
        g_threadFlag = previousFlag;
    }
};

struct DeviceCallback
{
    int unk00;
    int m_total;
    int(__cdecl* m_callback)(DeviceCallback*, void*, int, int*, int);
    __forceinline void Process(void* p)
    {
        int size = 4;
        m_total += m_callback(this, p, 4, &size, 1);
    }
};
struct Resource
{
    void FUN_00c905b0();
};
struct DeviceOwner;
struct DeviceSubobject
{
    void FUN_00d21ce0(DeviceOwner*);
};
struct DeviceOwner
{
    int unk00, unk04, unk08, unk0c;
    DeviceSubobject m_subobject;
    int unk14, unk18, m_payload;
    void FUN_00ca9b40(Resource*);
};
struct InputObject
{
    DeviceCallback* GetCallback() const
    {
        return *reinterpret_cast<DeviceCallback* const*>(reinterpret_cast<const char*>(this) + 0x24c);
    }
};
Resource* __cdecl FUN_00cf4af0(InputObject*);

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

template <class T> struct hkRefPtrE3EE
{
    T* m_pRetainedObject;

    hkRefPtrE3EE(const hkRefPtrE3EE& rp) throw()
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrE3EE() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    void operator=(const hkRefPtrE3EE& rp) throw()
    {
        if (this != &rp)
            *this = rp.m_pRetainedObject;
    }
};

struct HeapEntryE3EE
{
    hkRefPtrE3EE<FUN_00d1df70> m_object;
    int m_primary;
    int m_secondary;
};

struct HeapLessE3EE
{
    bool operator()(const HeapEntryE3EE& kA, const HeapEntryE3EE& kB) const
    {
        return kB.m_primary > kA.m_primary || (kA.m_primary == kB.m_primary && kA.m_secondary < kB.m_secondary);
    }
};

struct Tls_00c89b60
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
};

extern __declspec(thread) Tls_00c89b60 tls_00c89b60;

struct Scope_00c89b60
{
    int saved;
    Scope_00c89b60()
    {
        saved = tls_00c89b60.unk2b4;
        tls_00c89b60.unk2b4 = 0x10;
    }
    ~Scope_00c89b60()
    {
        tls_00c89b60.unk2b4 = saved;
    }
};

// Sets m_pReference to r, calling FUN_00c90510 on the new reference and FUN_00c905b0 on the old one if present.
// @f3 0x0056a350 (community match, verified in this file)
namespace f3m_0056a350 {
namespace Constructor114 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
struct Ref {
 virtual void Unknown00();
 virtual void Delete();
 long count;
};
struct RefPtr {
 Ref* value;
 RefPtr():value(0) {}
 ~RefPtr(){Reset();}
 void Reset(){
  Ref* old=value;
  if(old){
   if(!InterlockedDecrement(&old->count)) old->Delete();
   value=0;
  }
 }
};
struct Buffer {void FUN_005a22f0();};
struct OwnedBuffer {
 Buffer* value;
 OwnedBuffer():value(0){}
 ~OwnedBuffer(){Reset();}
 void Reset(){if(value){value->FUN_005a22f0();value=0;}}
};
struct FUN_0056a350 {
 RefPtr reference;
 float weight;
 OwnedBuffer buffer;
 FUN_0056a350();
};
// pdb: FOCollisionListener::ObjectDamageImpactData::ObjectDamageImpactData | FOCollisionListener.obj | fnv360_0822_retail, call_seq, medium
FUN_0056a350::FUN_0056a350(){
 reference.Reset();
 weight=0.0f;
 buffer.Reset();
}
}
}   // namespace f3m_0056a350


class hkMemoryAllocatorC904
{
  public:
    virtual ~hkMemoryAllocatorC904() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterC904
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorC904* m_pStreamAllocator;

    hkMemoryAllocatorC904& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterC904 {
extern "C" hkMemoryRouterC904& __cdecl FUN_00c85750() throw();
}

class hkRefObjC904
{
  public:
    virtual ~hkRefObjC904();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjC904()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjC904* b = static_cast<hkRefObjC904*>(hkRouterC904::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class FUN_00c90830 : public hkRefObjC904
{
  public:
    FUN_00c90830() throw();
    void ReleaseReference() throw();

    int m_08;
    int unk0C[9];
};

namespace hkSingletonC904 {
extern FUN_00c90830* DAT_012681d4;
}

struct FUN_00c90510_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    void FUN_00c90510();
};

extern int DAT_012681d4;
extern int DAT_012681d8;
extern int(__stdcall* DAT_00fdf044)(int);
extern int(__stdcall* DAT_00fdf04c)(int, int);
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

// @fnv 0x00c90510
void FUN_00c90510_class::FUN_00c90510()
{
    if (!m_uiObjectFlags)
        return;

    int* state = (int*)DAT_012681d4;
    int one = 1;

    if (state[2] == one)
    {
        int(__stdcall * getValue)(int) = DAT_00fdf044;
        int value = getValue(DAT_012681d8);

        if (value != 0x23df4554)
        {
            value = getValue(DAT_012681d8);

            int(__stdcall * setValue)(int, int) = DAT_00fdf04c;

            if (value == 0x23df4554)
            {
                state[3] += one;
            }
            else
            {
                DAT_00fdf05c(state + 6);
                state[3] = one;
                setValue(DAT_012681d8, 0x23df4554);
            }

            m_uCount += one;
            --state[3];

            if (state[3] <= 0)
            {
                setValue(DAT_012681d8, 0);
                DAT_00fdf100(state + 6);
            }

            return;
        }
    }

    m_uCount += one;
}

namespace fnv_00cc49b0 {
extern __declspec(thread) int tlsMode;
struct ShortPair
{
    int first;
    int second;
};
struct ByteFlag
{
    unsigned char value;
    ByteFlag(bool v) : value(v)
    {}
    ByteFlag(const ByteFlag& other) : value(other.value)
    {}
};
struct FUN_00c90510_class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24(ByteFlag flag, ShortPair* output);
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct FUN_00cc49b0_class;
struct FUN_00d21ce0_class
{
    int unk0c, unk10, unk14;
    void FUN_00d21ce0(FUN_00cc49b0_class* parent);
};
struct FUN_00cc49b0_class
{
    int unk00, unk04, unk08;
    FUN_00d21ce0_class subobject;
    FUN_00c90510_class* owner;
    unsigned short state;
    unsigned short substate;
    void FUN_00cc49b0(FUN_00c90510_class* value);
};
struct ScopedThreadState
{
    int previous;
    ScopedThreadState()
    {
        previous = tlsMode;
        tlsMode = 16;
    }
    ~ScopedThreadState()
    {
        tlsMode = previous;
    }
};
}  // namespace fnv_00cc49b0

class NiBinaryStreamCC4
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCC4*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Read(T& value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &value, sizeof(T), &uiSize, 1);
    }
};

struct NiStream
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248;
    NiBinaryStreamCC4* m_pUnderlyingStream;
};

class hkRefCC4
{
  public:
    void FUN_00c905b0() throw();
};

class hkShapeCC4 : public hkRefCC4
{
};

hkShapeCC4* __cdecl FUN_00cf4af0(NiStream& kStream) throw();

template <class T> struct hkRefPtr_e3eb
{
    T* m_pRetainedObject;
    hkRefPtr_e3eb() throw() : m_pRetainedObject(0)
    {}
    hkRefPtr_e3eb(T* const& e) throw()
    {
        if (e)
            e->FUN_00c90510();
        m_pRetainedObject = e;
    }
    hkRefPtr_e3eb(const hkRefPtr_e3eb& rp) throw()
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtr_e3eb() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

struct E5C4Obj
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

struct E5C4Ref
{
    E5C4Obj* p;
    E5C4Ref(const E5C4Ref& o)
    {
        if (o.p != 0)
        {
            o.p->FUN_00c90510();
        }
        p = o.p;
    }
};

volatile int S00e3eba0_sink;
__declspec(noinline) void __fastcall FUN_00c90510(void* self)
{
    S00e3eba0_sink = (int)self;
}
__declspec(noinline) void __fastcall FUN_00c905b0(void* self)
{
    S00e3eba0_sink = (int)self + 1;
}

// @f3twin 0x00983050 of 0x009316f0
struct F3Twin_00983050 : public FUN_00c903b0_class { void F3_FUN_00983050() ; };
void F3Twin_00983050::F3_FUN_00983050() 
{
    if (m_uiObjectFlags)
    {
        --m_uCount;
        if (!m_uCount)
            ((void(__thiscall*)(void*, int))m_pVTable[0])(this, 1);
    }
}
