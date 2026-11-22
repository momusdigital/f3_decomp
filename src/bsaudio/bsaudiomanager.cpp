#include "f3_common.h"
// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator(void);
    void FUN_00adc670(int, int);
};

namespace fnv_00adad60 {
struct BottomlessStack
{
    void FUN_00ae76b0();
};
struct BSAudioManager
{
    BottomlessStack m_aiEntries;  // +0x24
    void FUN_00adad60();
};

}  // namespace fnv_00adad60

namespace fnv_00adaf80 {
struct SoundMessageRecord;

struct BottomlessStack
{
    SoundMessageRecord* Pop();
};

struct BSAudioManager
{
    SoundMessageRecord* FUN_00adaf80();
};

}  // namespace fnv_00adaf80

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;

namespace fnv_00ae6ca0 {
extern int DAT_011f6ec0;
extern char DAT_01202800;
extern int g_011f6ebc;
}  // namespace fnv_00ae6ca0

namespace fnv_00ae6cf0 {
extern int g_011f6ebc;
extern bool DAT_011f6ec0;
extern bool DAT_01202800;
}  // namespace fnv_00ae6cf0

struct _Base_00441d20
{
    _Base_00441d20();
    ~_Base_00441d20();
};

struct FUN_00ae7020_shell : _Base_00441d20
{
    void __thiscall FUN_00ae7020();
};

struct SoundMessageRecord;
struct BottomlessStack
{
    void Push(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};
typedef char _sizecheck_AudioMessageStack[sizeof(BottomlessStack) == 16 ? 1 : -1];

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager* g_memoryManager;

namespace fnv_00ae7870 {
struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM* g_memoryManager;

}  // namespace fnv_00ae7870

namespace fnv_00ae7b10 {
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void __cdecl DeallocateAlias(void*);
struct FUN_00ae7020_shell
{
    void __thiscall FUN_00ae7020();
};
struct AudioLoadTask : FUN_00ae7020_shell
{
    void* __thiscall FUN_00ae7b10(unsigned int flags);
};
}  // namespace fnv_00ae7b10

struct GO
{
    GO& __thiscall operator=(void*);
};
template <typename T> struct NiTPointerAllocator
{
    void __thiscall Deallocate(void*);
};

namespace fnv_00ae8f20 {
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct S00a0d390
{
    int _0;
    int _4;
    void* _8;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae8f20(int);
};
}  // namespace fnv_00ae8f20

namespace fnv_00ae9010 {
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void __thiscall _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
struct S00a0d390
{
    void __thiscall ClearAll();
};
}  // namespace fnv_00ae9010

namespace fnv_00ae9100 {
void _NiFreeAlias(void*);
struct S00a0d390
{
    void* _00;
    int _04;
    void* _08;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae9100(unsigned int);
};
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00ae9100

struct AudioLoadTask
{
    int _pad[12];
    void* SoundAssetTmp;
    void __thiscall FUN_00ae7360();
};

struct AudioLoadTask;
struct BSAudioManager;
struct BSAudioManagerThread;
struct SoundMessageRecord;

struct Snd_
{
    void __thiscall FUN_00ad7fa0(char const*, int);
};

struct BSAudio : Snd_
{
    unsigned char _pad[6];
    bool bIsMultiThreaded;
};

extern BSAudio* DAT_011f6d98;

struct CritSecA
{
    int unk[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSecA* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSecA* cs);

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;

extern "C" int __cdecl CopyRelativeDataPath(int src, char* dst, unsigned int size);

class BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;

    BaseObj_b5112(int aValue);
    ~BaseObj_b5112();
    void SetupBuffer(char* apBuffer);
    void SetMode(int aMode);
};

class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    int m_30;

    FUN_00ae6f50(int aValue);
};

// @f3 0x00bd1060 (community match, verified in this file)
// pdb: AudioLoadTask::AudioLoadTask | BSAudioManager.obj | fnv360_0721_retail, call_seq, low
// pdb params: apSound
FUN_00ae6f50::FUN_00ae6f50(int aValue) : BaseObj_b5112(0)
{
    m_30 = aValue;
    char buf[0x104];
    CopyRelativeDataPath(m_30 + 0x36, buf, 0x104);
    SetupBuffer(buf);
    SetMode(3);
}


struct Ptr_6e5cc0
{
    void* p;
    Ptr_6e5cc0& operator=(const Ptr_6e5cc0& rhs);
};

struct BSThread
{
    enum StackSize
    {
        kDefaultStack = 0x8000
    };

    void __thiscall Initialize(StackSize eStackSize, const char* apName, bool abSuspended);
    void __thiscall SetName(const char* apName);
    void __thiscall SetPriority(int aiPriority);
    void __thiscall Wakeup(void);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_iThreadId;
};

namespace fnv_00add630 {
typedef bool(__cdecl* ADD630ResolveFunc)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                         unsigned int* puiExtra);

class ADD630Audio
{
  public:
    int unk00;
    bool m_bEnableState;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ADD630ResolveFunc m_pfnResolve;
};

extern ADD630Audio* DAT_011f6d98;

}  // namespace fnv_00add630

struct Sound
{
    virtual ~Sound();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual Sound* Create(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(Sound*, int);
    int p4;
    unsigned int flags;
    char padding[0x138];
    unsigned int id;
    int p148;
    unsigned int size;
};
struct Node
{
    Node* next;
    int p4;
    Sound* sound;
};
struct LinkedSoundQueue
{
    Node* head;
    int p4;
    unsigned int count;
    Sound* FUN_00ae7f90();
    Sound* PopFront();
    void FUN_00a0c9f0(Sound* const&);
};

namespace fnv_00addc70 {
struct LinkedSoundQueue
{
    int pHead;
    int pTail;
    int iCount;
    int __thiscall FUN_00ae7f90();
    void __thiscall FUN_00ae8370();
};
}  // namespace fnv_00addc70

typedef bool(__cdecl* Resolver_ae5680)(int, void*, unsigned int*, int*);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);

extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void*);

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* h, long n, long* prev);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* h, unsigned long ms);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct BSSemaphore_adf080
{
    long count;
    void* semaphore;
};

struct BSAudioManagerThread
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    BSSemaphore_adf080 doneSemaphore30;
    unsigned int unk38;
    BSSemaphore_adf080 workSemaphore3c;
    unsigned int unk44;
    bool waiting48;

    void __thiscall FUN_00aa6590(int, int);
    void FUN_00ae7ac0();
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
