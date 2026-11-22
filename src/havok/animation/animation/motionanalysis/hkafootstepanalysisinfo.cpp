#include "f3_common.h"
// src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motionanalysis/hkafootstepanalysisinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(nothrow) void FUN_00c90510();
    __declspec(nothrow) void FUN_00c905b0();
};

struct Obj : RefObj
{
    int pad[(0x98 - 8) / 4];
    __declspec(nothrow) Obj* FUN_00e40800(int a0, float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8);
};

struct ObjRef
{
    Obj* m_pRetainedObject;
    ObjRef(Obj* p)
    {
        if (p)
            p->FUN_00c90510();
        m_pRetainedObject = p;
    }
    ObjRef(const ObjRef& o)
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~ObjRef()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    Obj* operator->() const
    {
        return m_pRetainedObject;
    }
    operator Obj*() const
    {
        return m_pRetainedObject;
    }
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct ObjArray
{
    ObjRef* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const ObjRef& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(ObjRef));
        new (&m_data[m_iElementCount]) ObjRef(e);
        m_iElementCount++;
    }
    ObjRef& back()
    {
        return m_data[m_iElementCount - 1];
    }
    ObjRef& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct Owner
{
    int unk00, unk04;
    ObjArray m_aiIndexedValues;
    Obj* CreateAndAddObject(int a0, float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8);
};

struct E40FA0ReferencedObject
{
    virtual ~E40FA0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E40FA0ReferencedObject() : m_sReferenceCount(1)
    {}
};

struct E40FA0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E40FA0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

// Default constructor for the referenced object; the array member is default-initialized by its own constructor.
// @f3 0x00409c20 (community match, verified in this file)
namespace f3m_00409c20 {
class FUN_00e40fa0_m {
public:
    int unk00;
    unsigned char unk04;
    char _pad_08[3];
    int unk08;

    FUN_00e40fa0_m* FUN_00409c20();
};

FUN_00e40fa0_m* FUN_00e40fa0_m::FUN_00409c20()
{
    this->unk00 = -1;
    this->unk04 = 0;
    this->unk08 = 0;
    return this;
}
}   // namespace f3m_00409c20


namespace fnv_00e40fd0 {
extern int DAT_0102e388;
void* __cdecl FUN_00c85750();
struct hkReferencedObject
{
    void removeReference();
};
struct Allocator;
typedef void(__thiscall* FreeFunction)(Allocator*, void*, unsigned int);
struct AllocatorVTable
{
    void* slot0;
    void* slot1;
    void* slot2;
    void* slot3;
    FreeFunction free;
};
struct Allocator
{
    AllocatorVTable* vtable;
};
struct Owner
{
    int* vtable;
    unsigned int unk04;
    hkReferencedObject** items;
    int count;
    int size;
    void ClearItems();
};
}  // namespace fnv_00e40fd0

struct CbBase
{
    virtual ~CbBase()
    {}
};

namespace fnv_00e40800 {
// Havok-style object: hkReferencedObject base, five string arrays, six float arrays, three floats.

struct S_00e40800_Allocator
{
    virtual void vf0() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut) throw()
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
};

struct S_00e40800_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e40800_Allocator* m_pStreamAllocator;
    S_00e40800_Allocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

S_00e40800_Router* FUN_00c85750() throw();
int hkString_strLen(const char* s) throw();
char* FUN_00cb1090(char* dst, const char* src) throw();
void FUN_00c908c0(S_00e40800_Allocator& alloc, void* array, int numElem, int sizeElem) throw();

template <typename T> struct S_00e40800_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S_00e40800_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    __forceinline S_00e40800_Array(int size, const T& fill) throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        S_00e40800_Allocator& a = FUN_00c85750()->heap();
        T* p = size ? a._bufAlloc<T>(size) : 0;
        int cap = size ? size : 0x80000000;
        m_data = p;
        m_iElementCount = size;
        m_iCapacityState = cap;
        for (int i = 0; i < size; i++)
        {
            p[i] = fill;
        }
    }

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00e40800_Allocator& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline void _setSize(S_00e40800_Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        int& size = m_iElementCount;
        size = n;
    }

    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(FUN_00c85750()->heap(), n);
    }
};

struct S_00e40800_String
{
    S_00e40800_Array<char> m_kStringBuffer;

    __forceinline void set(const char* s) throw()
    {
        m_kStringBuffer.SetSizeAndGrow(hkString_strLen(s) + 1);
        FUN_00cb1090(m_kStringBuffer.m_data, s);
    }
};

struct S_00e40800_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00e40800_RefObject() throw() : m_sReferenceCount(1)
    {}
    virtual ~S_00e40800_RefObject() throw();
};

struct FUN_00e40800 : S_00e40800_RefObject
{
    S_00e40800_String m_name8;
    S_00e40800_String m_name14;
    S_00e40800_String m_name20;
    S_00e40800_String m_name2c;
    S_00e40800_String m_name38;
    S_00e40800_Array<float> m_arr44;
    S_00e40800_Array<float> m_arr50;
    S_00e40800_Array<float> m_arr5c;
    S_00e40800_Array<float> m_arr68;
    S_00e40800_Array<float> m_arr74;
    S_00e40800_Array<float> m_arr80;
    float m_f8c;
    float m_f90;
    float m_f94;

    FUN_00e40800(int n, float a2, float a3, float a4, const char* s5, const char* s6, const char* s7, const char* s8,
                 const char* s9) throw();
    virtual ~FUN_00e40800() throw();
};

// Initializes string fields from s5-s9, stores a2-a4 into m_f94, m_f8c, m_f90, and sets up six float arrays with given size and fill values.
// @fnv 0x00e40800
FUN_00e40800::FUN_00e40800(int aiSize, float afValue1, float afValue2, float afValue3, const char* apName1,
                           const char* apName2, const char* apName3, const char* apName4, const char* apName5) throw()
    : m_arr44(aiSize, 3.40282e38f), m_arr50(aiSize, -3.40282e38f), m_arr5c(aiSize, 3.40282e38f),
      m_arr68(aiSize, -3.40282e38f), m_arr74(aiSize, 0.0f), m_arr80(aiSize, 1.0f)
{
    m_f8c = afValue2;
    m_f90 = afValue3;
    m_f94 = afValue1;
    m_name8.set(apName1);
    m_name14.set(apName2);
    m_name20.set(apName3);
    m_name2c.set(apName4);
    m_name38.set(apName5);
}
}  // namespace fnv_00e40800

namespace fnv_00e40ca0 {
struct Obj
{
    const void* vptr;
    Obj* FUN_00e40ca0(int unused);
};

}  // namespace fnv_00e40ca0

namespace fnv_00e41050 {
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00e41050

namespace fnv_00e41e20 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();
extern int DAT_0102e388;

}  // namespace fnv_00e41e20
