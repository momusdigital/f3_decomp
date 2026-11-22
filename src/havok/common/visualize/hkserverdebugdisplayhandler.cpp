#include "f3_common.h"
// src/havok/common/visualize/hkserverdebugdisplayhandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkserverdebugdisplayhandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010d7cfc;
void __cdecl _Deallocate(void*);
struct FUN_00dd97c0
{
    int* m_p;
    FUN_00dd97c0(char f);
};
// @fnv 0x00dd97c0
// pdb: std::locale::facet::`scalar deleting destructor' | algs.obj | fnv360_0822_retail, vtable, high
FUN_00dd97c0::FUN_00dd97c0(char acFlags)
{
    m_p = &DAT_010d7cfc;
    if (acFlags & 1)
        _Deallocate(this);
}

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);
struct FUN_00d605d0_Class
{
    void hkOArchive_write32u(unsigned int value);
    void hkOArchive_write8u(unsigned int value);
    void FUN_00dda730(unsigned int value);
    void hkOArchive_write64u(__int64 value);
    void WriteInt(unsigned int value);
    const char* ForwardValueToObject(unsigned int* value);
};

struct FUN_00dd9ab0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool FUN_00dd9ab0(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @f3 0x00a61db0 (community match, verified in this file)
struct WorldLockStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_00908a00();
};

// pdb: hkServerDebugDisplayHandler::displayPoint | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: position, color, id, tag
bool FUN_00dd9ab0_cls::FUN_00dd9ab0(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    static_cast<WorldLockStub*>(m_pWorldLock)->FUN_00908a00();
    if (m_pConfiguration != 0)
    {
        m_pConfiguration->hkOArchive_write32u(0x21);
        m_pConfiguration->hkOArchive_write8u(8);
        m_pConfiguration->FUN_00dda730(a1);
        m_pConfiguration->FUN_00dda730(a2);
        m_pConfiguration->hkOArchive_write32u(a3);
        m_pConfiguration->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = m_pConfiguration->ForwardValueToObject(&a1);
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    WorldLockStub* lk = static_cast<WorldLockStub*>(m_pWorldLock);
    lk->unk18 = -1;
    lk->unk1c = -1;
    _fnv_LeaveCriticalSection(lk);
    return !ok;
}


struct ConfigExt
{
    void unk607b0(unsigned int a, unsigned int b);
};

struct FUN_00dd9be0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_cs;
    bool FUN_00dd9be0(unsigned int a, unsigned int b);
};

// @f3 0x00a62120 (community match, verified in this file)
// pdb: hkServerDebugDisplayHandler::sendMemStatsDump | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: data, length
bool FUN_00dd9be0_cls::FUN_00dd9be0(unsigned int value, unsigned int length)
{
    static_cast<WorldLockStub*>(m_cs)->FUN_00908a00();
    if (m_pConfiguration != 0)
    {
        unsigned int count = length;
        m_pConfiguration->hkOArchive_write32u(count + 5);
        m_pConfiguration->hkOArchive_write8u(0xf);
        m_pConfiguration->WriteInt(count);
        reinterpret_cast<ConfigExt*>(m_pConfiguration)->unk607b0(value, count);
    }
    bool failed;
    if (m_pConfiguration != 0)
    {
        const char* status = m_pConfiguration->ForwardValueToObject(&length);
        if (*status == 0)
            goto clear;
        failed = true;
        goto finish;
    }
clear:
    failed = false;
finish:
    WorldLockStub* section = static_cast<WorldLockStub*>(m_cs);
    section->unk18 = -1;
    section->unk1c = -1;
    _fnv_LeaveCriticalSection(section);
    return !failed;
}


struct S_00dd9c60
{
    int unk00;
    FUN_00d605d0_Class* unk04;
    void* unk08;
    bool FUN_00dd9c60();
};
// @f3 0x00a621a0 (community match, verified in this file)
struct CS_w137
{
    void FUN_00908a00();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct Cfg_w137 : FUN_00d605d0_Class
{
    void FUN_009ee8f0(unsigned int value);
};
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);

// pdb: hkServerDebugDisplayHandler::holdImmediate | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
bool S_00dd9c60::FUN_00dd9c60()
{
    ((CS_w137*)unk08)->FUN_00908a00();
    if (unk04)
    {
        ((Cfg_w137*)unk04)->FUN_009ee8f0(1);
        unk04->hkOArchive_write8u(0xb);
    }
    bool r;
    char c;
    if (unk04 && *unk04->ForwardValueToObject((unsigned int*)&c) != 0)
        r = true;
    else
        r = false;
    CS_w137* cs = (CS_w137*)unk08;
    int m = -1;
    cs->unk18 = m;
    cs->unk1c = m;
    _fnv_LeaveCriticalSection(cs);
    return !r;
}


int __cdecl FUN_00dda850(const char* str);

struct DD9D70StringArray
{
    const char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// @fnv 0x00dd9d70
// pdb: _getGeometryByteSize | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) int FUN_00dd9d70(const DD9D70StringArray& strings)
{
    int size = 4;
    for (int i = 0; i < strings.m_iElementCount; i++)
    {
        const char* const& s = strings.m_data[i];
        size += FUN_00dda850(s);
    }
    return size;
}

// Caller so the file-static helper is emitted with its register calling convention.
int DD9D70ComputeSize(const DD9D70StringArray* a, const DD9D70StringArray* b)
{
    return FUN_00dd9d70(*a) + FUN_00dd9d70(*b);
}

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);

extern int DAT_010d7cfc;
void __cdecl _Deallocate(void*);

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);

unsigned int FUN_00dd9d70();

struct FUN_00dd9df0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    bool __thiscall FUN_00dd9df0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4);
};

// Locks the critical section, applies the given values to config and parent, then returns whether the config's check fails.
// @f3 0x00a61950 (community match, verified in this file)
struct Bool95{char value;operator bool()const{return value!=0;}};
struct Stream95{
    void FUN_009ee8d0(int value);
    void FUN_009ee560(unsigned char value);
    void FUN_00a623b0(unsigned int value);
    void FUN_009ee8f0(unsigned int value);
    const char* FUN_009ee770(unsigned int* out);
};
struct Lock95{
    int unk00[6];
    int owner;int count;
    void FUN_00908a00();
};
struct Parent95{void FUN_00a61800(unsigned int value);};
// pdb: hkServerDebugDisplayHandler::displayGeometry | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: geometries, transform, color, id, tag
bool FUN_00dd9df0_cls::FUN_00dd9df0(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4){
    ((Lock95*)criticalSection)->FUN_00908a00();
    if(config){
        unsigned int value=a1;
        ((Stream95*)config)->FUN_009ee8d0(FUN_00dd9d70()+0x25);
        ((Stream95*)config)->FUN_009ee560(5);
        ((Parent95*)((char*)this-8))->FUN_00a61800(value);
        ((Stream95*)config)->FUN_00a623b0(a2);
        ((Stream95*)config)->FUN_009ee8f0(a3);
        ((Stream95*)config)->FUN_009ee8d0(a4);
    }
    bool ok=config && *((Stream95*)config)->FUN_009ee770(&a1)!=0;
    Lock95* lk=(Lock95*)criticalSection;
    lk->owner=-1;
    lk->count=-1;
    _fnv_LeaveCriticalSection(lk);
    return !ok;
}


unsigned int FUN_00dd9d70();

struct FUN_00dd9da0_ext
{
    void ApplyItemList(unsigned int value);
};

struct FUN_00dd9f40_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool SetAndCheck(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @fnv 0x00dd9f40
bool FUN_00dd9f40_cls::SetAndCheck(unsigned int uiValue, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    _fnv_EnterCriticalSection(m_pWorldLock);
    if (m_pConfiguration != 0)
    {
        unsigned int v = uiValue;
        m_pConfiguration->WriteInt(FUN_00dd9d70() + 0x11);
        m_pConfiguration->hkOArchive_write8u(6);
        reinterpret_cast<FUN_00dd9da0_ext*>((char*)this - 8)->ApplyItemList(v);
        m_pConfiguration->hkOArchive_write32u(a2);
        m_pConfiguration->hkOArchive_write64u((__int64)a3);
        m_pConfiguration->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = m_pConfiguration->ForwardValueToObject(&uiValue);
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    _fnv_LeaveCriticalSection(m_pWorldLock);
    return !ok;
}

int hkString_strLen(unsigned int value);

int __cdecl hkString_strLen(const char* text);

int hkString_strLen(unsigned int value);

struct FUN_00dda290_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    int WriteConfigValue(unsigned int a, int b, unsigned int c);
};

// @f3 0x00a61f80 (community match, verified in this file)
#include <windows.h>
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
struct FUN_00dda290_lock
{
    CRITICAL_SECTION m_kCriticalSection;
    int m_iOwner;
    int m_iCount;
    void FUN_00908a00();
    void leave()
    {
        m_iOwner = -1;
        m_iCount = -1;
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
struct BoolResultA61 { bool value; BoolResultA61(); operator bool() const { return value; } };
struct FUN_00dda290_cfg
{
    void FUN_009ee8f0(unsigned int value);
    void FUN_009ee560(unsigned int value);
    void FUN_009ee8b0(unsigned int value);
    void FUN_009ee740(unsigned int a, unsigned int len);
    void FUN_009ee8d0(unsigned int value);
    BoolResultA61 FUN_009ee770();
};
int FUN_009233f0(unsigned int value);

// pdb: hkServerDebugDisplayHandler::displayText | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, objrun_open, low, conflict (bridge: hkServerDebugDisplayHandler::displayAnnotation)
// pdb params: text, color, id, tag
int FUN_00dda290_cls::WriteConfigValue(unsigned int a, int aiValue, unsigned int c)
{
    reinterpret_cast<FUN_00dda290_lock*>(criticalSection)->FUN_00908a00();
    if (config != 0)
    {

        int len = FUN_009233f0(a);
        int n = (len < 0xffff) ? len : 0xffff;
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee8f0(n + 0xb);
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee560(9);
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee8b0(n);
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee740(a, n);
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee8d0(aiValue);
        reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee8d0(c);
    }

    bool ok = (config != 0) && (reinterpret_cast<FUN_00dda290_cfg*>(config)->FUN_009ee770());
    reinterpret_cast<FUN_00dda290_lock*>(criticalSection)->leave();
    return !ok;
}


#include <xmmintrin.h>
#include <windows.h>

struct __declspec(align(16)) DD97E0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD97E0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD97E0OStream
{
    void writeCommand(unsigned int value);
    void writeCount(unsigned int value);
    void writeVector(const DD97E0Point& v);
    void writeUint64(unsigned __int64 value);
    void writeTag(int value);
    DD97E0Bool IsStreamValid();
};

struct DD97E0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD97E0DisplayHandler
{
    int unk00;
    DD97E0OStream* m_pDisplayStream;
    DD97E0CriticalSection* m_pSynchronizationLock;

    int FUN_00dd97e0(int a, int b, int c, int d, int e);
};

// Locks m_pSynchronizationLock, checks m_pDisplayStream and its IsStreamValid, then returns 0 if valid or 1 otherwise.
// @f3 0x00a61900 (community match, verified in this file)
struct DD97E0LockF3
{
    CRITICAL_SECTION m_kCriticalSection;
    int m_iOwner;
    int m_iCount;
    void FUN_00908a00();
    void leave()
    {
        m_iOwner = -1;
        m_iCount = -1;
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
// pdb: hkServerDebugDisplayHandler::addGeometryInstance | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: originalInstanceID, transform, id, tag, shapeIdHint
int DD97E0DisplayHandler::FUN_00dd97e0(int aUnused, int bUnused, int c, int dUnused, int eUnused)
{
    ((DD97E0LockF3*)m_pSynchronizationLock)->FUN_00908a00();
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    ((DD97E0LockF3*)m_pSynchronizationLock)->leave();
    return ok ? 0 : 1;
}


struct FUN_00d60940_Class
{
    void WriteInt(unsigned int);
};
struct Stream : FUN_00d605d0_Class
{
    void hkOArchive_write32u(unsigned int);
    void hkOArchive_write64u(unsigned int, int);
    char* ForwardValueToObject(void*);
};
struct Output
{
    int state;
    Stream* stream;
    CRITICAL_SECTION* lock;
    int WriteRecord(unsigned int, unsigned int, unsigned int);
};
// Under the lock, writes command 17, count 3, and the three arguments, then returns the negation of the forwarded value's first byte.
// @f3 0x00a61a90 (community match, verified in this file)
struct W56Lock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_00908a00();
};
// pdb: hkServerDebugDisplayHandler::displayLine | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, low
// pdb params: start, end, color, id, tag
int Output::WriteRecord(unsigned int first, unsigned int second, unsigned int third)
{
    ((W56Lock*)lock)->FUN_00908a00();
    if (stream)
    {
        stream->hkOArchive_write32u(17);
        stream->hkOArchive_write8u(3);
        stream->hkOArchive_write32u(first);
        stream->hkOArchive_write64u(second, 0);
        ((FUN_00d60940_Class*)stream)->WriteInt(third);
    }
    bool failed = stream && *stream->ForwardValueToObject(&first);
    W56Lock* lk = (W56Lock*)lock;
    lk->unk18 = -1;
    lk->unk1c = -1;
    LeaveCriticalSection((CRITICAL_SECTION*)lk);
    return !failed;
}


enum S_00dd98c0_Result
{
    S_00dd98c0_SUCCESS = 0,
    S_00dd98c0_FAILURE = 1
};
struct S_00dd98c0_Bool
{
    char m_cBooleanValue;
    S_00dd98c0_Bool()
    {}
};

struct DD9950Bool
{
    char m_cBooleanValue;

    DD9950Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

enum DD9950Result
{
    DD9950_SUCCESS = 0,
    DD9950_FAILURE = 1
};

struct DD9950CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD9950OArchive
{
    void WriteUint8(unsigned char v);
    void WriteUint32(unsigned int v);
    void WriteUint64(unsigned __int64 v);
    void WriteInt32(int v);
    DD9950Bool IsStreamValid() const;
};

struct DD9950DisplayServer
{
    int unk00;
    DD9950OArchive* m_pDisplayStream;
    DD9950CriticalSection* m_outStreamLock;

    DD9950Result FUN_00dd9950(unsigned long id, int tag, unsigned long shapeIdHint);
};

// @f3 0x00a61bb0 (community match, verified in this file)
struct DD9950LockF3
{
    CRITICAL_SECTION m_kCriticalSection;
    int m_iOwner;
    int m_iCount;
    void FUN_00908a00();
    void leave()
    {
        m_iOwner = -1;
        m_iCount = -1;
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
// pdb: hkServerDebugDisplayHandler::updateGeometry | hkServerDebugDisplayHandler.obj | fnv360_0822_retail, caller_sim, low, conflict (bridge: hkServerDebugDisplayHandler::removeGeometry)
// pdb params: transform, id, tag
DD9950Result DD9950DisplayServer::FUN_00dd9950(unsigned long id, int tag, unsigned long shapeIdHint)
{
    ((DD9950LockF3*)m_outStreamLock)->FUN_00908a00();
    if (m_pDisplayStream)
    {
        m_pDisplayStream->WriteUint8(0xd);
        m_pDisplayStream->WriteUint32(4);
        m_pDisplayStream->WriteUint64(id);
        m_pDisplayStream->WriteInt32(tag);
    }
    bool streamOk = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    ((DD9950LockF3*)m_outStreamLock)->leave();
    return streamOk ? DD9950_SUCCESS : DD9950_FAILURE;
}


namespace fnv_00dd99d0 {
struct DD99D0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD99D0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

extern "C" int __cdecl hkString_strLen(const char* str);

}  // namespace fnv_00dd99d0

struct __declspec(align(16)) DD9FE0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD9FE0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD9FE0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct Vec4_dda340
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) Transform_dda340
{
    Vec4_dda340 rotation0;
    Vec4_dda340 rotation1;
    Vec4_dda340 rotation2;
    Vec4_dda340 translation;
};

struct MemoryAllocator_dda340
{
    virtual void* vfn0() = 0;
    virtual void* vfn1() = 0;
    virtual void* vfn2() = 0;
    virtual void* vfn3() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
};

struct ThreadMemory_dda340
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryAllocator_dda340* m_pMemoryAllocator;
};

ThreadMemory_dda340* FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elemSize);

template <typename T> struct ArrayRef_dda340
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class Array_dda340
{
  public:
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    Array_dda340() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        ThreadMemory_dda340* mem = FUN_00c85750();
        MemoryAllocator_dda340* alloc = mem->m_pMemoryAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(int));
        }
    }

    void AddBack(int val)
    {
        ThreadMemory_dda340* mem = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(mem->m_pMemoryAllocator, this, sizeof(int));
        }
        m_data[m_iElementCount++] = val;
    }
};

namespace fnv_00dda660 {
struct FUN_00dda660_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00dda660_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dda660_Allocator* m_pStreamAllocator;

    FUN_00dda660_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" FUN_00dda660_MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00dda660
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dda660();
    virtual ~FUN_00dda660();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dda660* b = static_cast<FUN_00dda660*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// The constructor has an empty body.
// @fnv 0x00dda660
FUN_00dda660::FUN_00dda660()
{}
}  // namespace fnv_00dda660

unsigned int FUN_00dd9d70();

struct FUN_00dd9da0_owner
{
    void ApplyItemList(unsigned int value);
};

struct ConfigQ : FUN_00d605d0_Class
{
    void WriteInt(unsigned int value);
    void WriteTransform(unsigned int value);
    const char* ForwardValueToObject(unsigned int* value);
};

struct SecondaryDisplay
{
    int unk00;
    ConfigQ* config;
    void* criticalSection;

    bool FUN_00dd9e90(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e);
};

// Locks criticalSection, writes values through config when present, and returns true if config is absent or the returned first character is zero.
// @fnv 0x00dd9e90
bool SecondaryDisplay::FUN_00dd9e90(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config)
    {
        unsigned int a2 = a;
        config->WriteInt(FUN_00dd9d70() + 0x2d);
        config->hkOArchive_write8u(5);
        reinterpret_cast<FUN_00dd9da0_owner*>((char*)this - 8)->ApplyItemList(a2);
        config->WriteTransform(b);
        config->hkOArchive_write32u(c);
        config->hkOArchive_write64u((__int64)d);
        config->WriteInt(e);
    }
    bool ok = config != 0 && config->ForwardValueToObject(&a)[0] != 0;
    _fnv_LeaveCriticalSection(criticalSection);
    return !ok;
}
