#include "f3_common.h"
// src/havok/common/base/system/hkbasesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/hkbasesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned char DAT_01268414;

// @fnv 0x00cbb950
// pdb: hkBaseSystem::isInitialized | hkBaseSystem.obj | tesv_win, objrun_sim, low
void __cdecl FUN_00cbb950(unsigned char* out)
{
    *out = DAT_01268414;
}

extern unsigned char DAT_01268414;

extern "C" void __cdecl SetThreadLocalValue(void* value);
extern "C" void __cdecl FUN_00cb0db0();

// @fnv 0x00cbb930
// pdb: hkBaseSystem::initThread | hkBaseSystem.obj | fnv360_0822_debug, callee_sim, low
// pdb params: memoryRouter
int __cdecl FUN_00cbb930(void* value)
{
    SetThreadLocalValue(value);
    FUN_00cb0db0();
    return 0;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
void __cdecl SetThreadLocalValue(int);

namespace impl {
}

extern "C" void* DAT_011b3dbc;
typedef void(__cdecl* Callback)(int, int);
// @fnv 0x00cbbd20
// pdb: hkNativeFileSystem::listDirectory | hkBaseSystem.obj | fnv360_0822_retail, vtable, medium
// pdb params: basePath, listingOut
void __stdcall InvokeCallback(int first, int second)
{
    ((Callback)DAT_011b3dbc)(first, second);
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct LocalBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    void InitBuffer();
};

extern "C" int(__cdecl* DAT_011b3dc0)(int, LocalBuf*);

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0();
};

struct ObjA : RefObj
{
    int unk08, unk0c;
    ObjA* OpenFile(int);
};

struct ObjB : RefObj
{
    int pad[5];
    ObjB* FUN_00d27460(ObjA*, int);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @f3 0x0092eef0 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
extern unsigned long DAT_010f3170;
struct Buffer92 { char* data; int count; int capacity; };
extern "C" const char* (__cdecl* DAT_010611a0)(int, Buffer92*);
struct Heap92 { void* FUN_008f6d30(int size,int tag); void FUN_008f6d90(void* memory,int bytes,int tag); };
struct Source92;
struct SourceMethods92 { void (__thiscall* destroy)(Source92*,int); };
struct Source92 { SourceMethods92* methods; unsigned short size; short references; int unk08; int unk0c; Source92* FUN_009af710(const char*); };
// pdb: hkNativeFileSystem::openWriter | hkBaseSystem.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
ObjB* __stdcall hkNativeFileSystem_openWriter(int name) {
 Buffer92 buffer; buffer.data=0; buffer.count=0; buffer.capacity=0x80000000;
 Heap92* heap=(Heap92*)FUN_00d9b080(DAT_010f3170);
 Source92* object=(Source92*)heap->FUN_008f6d30(0x10,0x1a); object->size=0x10;
 Source92* source=object->FUN_009af710(DAT_010611a0(name,&buffer));
 Heap92* secondHeap=(Heap92*)FUN_00d9b080(DAT_010f3170);
 ObjB* result=(ObjB*)secondHeap->FUN_008f6d30(0x1c,0x1a); result->m_usMemSizeAndFlags=0x1c;
 result=result->FUN_00d27460((ObjA*)source,0x1000);
 if(source->size!=0) { if(--source->references==0) source->methods->destroy(source,1); }
 if(!(buffer.capacity & 0x80000000)) {int capacity=buffer.capacity&0x3fffffff; Heap92* cleanup=(Heap92*)FUN_00d9b080(DAT_010f3170); cleanup->FUN_008f6d90(buffer.data,capacity,0x17);}
 return result;
}


struct FUN_00cbc810_cls;

struct FUN_00aa4060_cls
{
    void FUN_00aa4060(FUN_00cbc810_cls* node);
};

extern FUN_00aa4060_cls DAT_011f6238;

struct FUN_00cbc810_cls
{
    unsigned int m_key;
    FUN_00cbc810_cls* m_next;

    void FUN_00b4df30();
    void RemoveKey(unsigned int* pKey);
};

// @fnv 0x00cbc810
// pdb: BSSimpleList<VATS_COMMAND *>::Remove | VATS.obj | fnv360_0822_retail, caller, medium
// pdb params: item
void FUN_00cbc810_cls::RemoveKey(unsigned int* puiKey)
{
    unsigned int key = *puiKey;
    if (key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* head_next = m_next;
    if (head_next == 0 && m_key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* cur = this;
    FUN_00cbc810_cls* prev = this;
    do
    {
        if (cur->m_key == key)
        {
            goto found;
        }
        prev = cur;
        cur = cur->m_next;
    } while (cur != 0);
    return;

found:
    if (cur == this)
    {
        if (head_next != 0)
        {
            m_next = head_next->m_next;
            m_key = head_next->m_key;
            head_next->m_next = 0;
            head_next->FUN_00b4df30();
            DAT_011f6238.FUN_00aa4060(head_next);
            return;
        }
        m_key = 0;
        return;
    }
    prev->m_next = cur->m_next;
    cur->m_next = 0;
    cur->FUN_00b4df30();
    DAT_011f6238.FUN_00aa4060(cur);
}

extern int DAT_01268790;
void __cdecl ResizeAudioStream(void* allocator, void* array, int itemSize);

extern int DAT_01268790;

void __cdecl ResizeAudioStream(void* aAlloc, void* aArray, unsigned int aiElemSize);

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(hkMemoryAllocator* alloc, T val)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc, this, sizeof(T));
        }
        m_data[m_iElementCount++] = val;
    }

    void removeAt(int i)
    {
        m_iElementCount--;
        if (m_iElementCount != i)
        {
            m_data[i] = m_data[m_iElementCount];
        }
    }

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

#include <windows.h>

namespace fnv_00cbb9c0 {
struct SpawnedAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};

struct SpawnedHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

SpawnedHolder* __cdecl FUN_00c85750();

struct SpawnedObject
{
    virtual void v00();
    unsigned short m_w04;
    unsigned short m_w06;

    SpawnedObject()
    {}

    static void* operator new(unsigned int, void* apMemory)
    {
        return apMemory;
    }
};

// Allocates 8 bytes through the holder's allocator, sets m_w04 and m_w06, then placement-constructs a SpawnedObject there.
// @fnv 0x00cbb9c0
void __cdecl FUN_00cbb9c0()
{
    SpawnedHolder* pHolder = FUN_00c85750();
    SpawnedAllocator* pAllocator = pHolder->m_pAllocator;
    SpawnedObject* pSpawnedObject = (SpawnedObject*)pAllocator->Alloc(8);
    pSpawnedObject->m_w04 = 8;
    pSpawnedObject->m_w06 = 1;
    new (pSpawnedObject) SpawnedObject();
}
}  // namespace fnv_00cbb9c0

namespace fnv_00cbbb10 {
extern "C" void __cdecl FUN_00cbb930(int value);

struct FNV_Allocator
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FNV_Allocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750();

}  // namespace fnv_00cbbb10

namespace fnv_00cbbde0 {
struct S_00cbbde0_Allocator
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void vfn8();
    virtual void vfnc();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00cbbde0_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_00cbbde0_Allocator* unkc;
    S_00cbbde0_Allocator* unk10;
    S_00cbbde0_Allocator& temp()
    {
        return *unkc;
    }
    S_00cbbde0_Allocator& heap()
    {
        return *unk10;
    }
};

S_00cbbde0_Router* FUN_00c85750() throw();

struct S_00cbbde0_Bool
{
    char m_cBooleanValue;
    S_00cbbde0_Bool()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00cbbde0_StringBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    // inline storage for 128 chars; declared as ints because the original has no /GS cookie
    unsigned int m_kStorage[32];

    S_00cbbde0_StringBuf() throw();
    ~S_00cbbde0_StringBuf() throw()
    {
        S_00cbbde0_Allocator& a = FUN_00c85750()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(char));
    }
};

struct S_00cbbde0_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00cbbde0_RefObject() throw();
    void* operator new(unsigned int n)
    {
        S_00cbbde0_RefObject* b = static_cast<S_00cbbde0_RefObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*)
    {}
    void FUN_00c905b0() throw();
};

extern const char*(__cdecl* DAT_011b3dc0)(const char* name, S_00cbbde0_StringBuf& buf);

}  // namespace fnv_00cbbde0
