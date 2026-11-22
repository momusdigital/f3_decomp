#include "f3_common.h"
// src/staging/blk_00d00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @fnv 0x00d1a300
// pdb: hkpEntityAabbUtil::entityBatchInvalidateAabb | hkpEntityAabbUtil.obj | fnv360_0822_retail, call_seq, high
// pdb params: entityBatch, numEntities
// pdb: hkpEntityAabbUtil::entityBatchInvalidateAabb | hkpEntityAabbUtil.obj | fnv360_0822_retail, call_seq, high (was: InitArrayEntries)
void __cdecl hkpEntityAabbUtil_entityBatchInvalidateAabb(int** apEntries, int count)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            int* p = apEntries[i] + 12;
            ++i;
            *(int*)p = 1;
            *(int*)((char*)p + 0x10) = 0;
        } while (i < count);
    }
}

struct D107A0RTTI;
extern D107A0RTTI g_D107A0RTTI;

// @fnv 0x00d10790
// pdb: bhkPositionConstraintMotor::GetRTTI | bhkPositionConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
D107A0RTTI* __cdecl FUN_00d10790()
{
    return &g_D107A0RTTI;
}

extern int DAT_010cd54c;

struct FUN_00d107b0
{
    void** vft;
    unsigned short a;
    unsigned short b;
    int c;
    FUN_00d107b0();
};

// @fnv 0x00d107b0
// pdb: hkpNullAgent::hkpNullAgent | hkpNullAgent.obj | fnv360_0822_retail, uvref, high
FUN_00d107b0::FUN_00d107b0()
{
    b = 1;
    c = 0;
    vft = (void**)&DAT_010cd54c;
}

struct FUN_00d1fa20_t
{
    int m_uiCount;
    void ResetEntries();
};
// @fnv 0x00d1fa20
// pdb: hkaDetectRagdollPenetration::resetBoneStates | hkaDetectRagdollPenetration.obj | fnv360_0822_retail, call_gap, high
void FUN_00d1fa20_t::ResetEntries()
{
    for (int i = 0; i < *(int*)((char*)this + 0x1c); ++i)
        *(unsigned int*)((char*)*(unsigned char**)((char*)this + 0x18) + i * 4) = 1;
    *(unsigned char*)((char*)this + 0x24) = 0;
}

class FUN_00d07910_cls;

class FUN_00d07910_elem
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(FUN_00d07910_cls* owner);
};

class FUN_00d07910_cls
{
  public:
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
    FUN_00d07910_elem** m_98;
    int m_9C;
    void hkpPhantom_firePhantomDeleted();
};

// Iterates the m_98 element array backwards and calls v10(this) on each non-null element.
// @f3 0x009897e0 (community match, verified in this file)
// pdb: hkpPhantom::firePhantomDeleted | hkpPhantom.obj | fnv360_0822_retail, call_dedup, high
// pdb: hkpPhantom::firePhantomDeleted | hkpPhantom.obj | fnv360_0822_retail, call_dedup, high (was: NotifyElements)
void FUN_00d07910_cls::hkpPhantom_firePhantomDeleted() {
    for (int index = unk90 - 1; index >= 0; --index) {
        FUN_00d07910_elem** slot = &reinterpret_cast<FUN_00d07910_elem**>(unk8C)[index];
        if (reinterpret_cast<FUN_00d07910_elem**>(unk8C)[index]) {
            FUN_00d07910_elem* element = *slot;
            element->v10(this);
        }
    }
}


// File-static helper with a compiler-chosen register convention.
// @fnv 0x00d10ab0
// pdb: add1SaturateAndSetLowBit | hkp3AxisSweep.obj | tesv_win, objrun_open, low
static __declspec(noinline) unsigned int FUN_00d10ab0(unsigned int uiValue)
{
    if (uiValue != 0xffff)
        uiValue++;
    return uiValue | 1;
}

unsigned int D10AB0NextOdd(const unsigned int* puiValue)
{
    return FUN_00d10ab0(*puiValue);
}

extern int DAT_01268838;

// @fnv 0x00d1f110
// pdb: bhkSpringDamperConstraintMotor::GetRTTI | bhkSpringDamperConstraintMotor.obj | fnv360_0822_retail, objrun_open, low
int* __cdecl FUN_00d1f110()
{
    return &DAT_01268838;
}

extern int g_unk01268868;

// @fnv 0x00d1f130
// pdb: hkpNullAgent::createNullAgent | hkpNullAgent.obj | fnv360_0822_retail, objrun_open, low
// pdb params: bodyA, bodyB, input, mgr
void* __cdecl FUN_00d1f130()
{
    return &g_unk01268868;
}

// FUN_00d1f140 : a one-line function - getter
extern int g_target_00d1f140;
// @fnv 0x00d1f140
// pdb: hkpNullAgent::getNullAgent | hkpNullAgent.obj | fnv360_0822_retail, call_seq, medium
void* FUN_00d1f140()
{
    return &g_target_00d1f140;
}

class D1F150Object
{
  public:
    virtual ~D1F150Object();
};

// @fnv 0x00d1f150
// pdb: hkpStorageSampledHeightFieldShape::calcSizeForSpu | hkpStorageSampledHeightFieldShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: input, spuBufferSizeLeft
void FUN_00d1f150(D1F150Object* pkObject)
{
    pkObject->~D1F150Object();
}

extern int DAT_012688c8;
// @fnv 0x00d1f160
int* __cdecl FUN_00d1f160()
{
    return &DAT_012688c8;
}

struct FUN_00d1f1c0_target
{
    void Run();
};

// @fnv 0x00d1f1c0
void __cdecl FUN_00d1f1c0(FUN_00d1f1c0_target* pTarget)
{
    pTarget->Run();
}

struct S_00d1f730_Base
{
    S_00d1f730_Base(int a, int b);
    virtual void vfn00();
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

};

struct S_00d1f730_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00d1f730_Arr()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct S_00d1f730_Flag
{
    char v;
    S_00d1f730_Flag()
    {
        v = 0;
    }
};

struct FUN_00d1f730 : S_00d1f730_Base
{
    FUN_00d1f730(int a, int b, int c);
    virtual void vfn00();
    S_00d1f730_Arr unk160;

};

// Constructs the object from the base constructor and stores the third argument into unk2c.
// @f3 0x0099e9b0 (community match, verified in this file)
// pdb: hkpSimpleShapePhantom::hkpSimpleShapePhantom | hkpSimpleShapePhantom.obj | fnv360_0822_retail, callee_sim, medium
// pdb params: shape, transform, collisionFilterInfo
FUN_00d1f730::FUN_00d1f730(int aiArg1, int aiArg2, int aiValue) : S_00d1f730_Base(aiArg1, aiArg2)
{
    unk2c = aiValue;
}


int __fastcall FUN_00d04380(void*);
// @fnv 0x00d043b0
// pdb: hkSemaphore::acquire | hkWin32Semaphore.obj | tesv_win, objrun_open, low
int __cdecl FUN_00d043b0(void* ap)
{
    return FUN_00d04380(ap);
}

// @fnv 0x00d043d0
// pdb: hkp3AxisSweep::getType | hkp3AxisSweep.obj | tesv_win, objrun_open, low
int __cdecl FUN_00d043d0()
{
    return 0;
}

struct FnvCpu_FUN_00d081d0_CpuObject
{
    char* FUN_00d081d0();
};
// @fnv 0x00d081d0
char* FnvCpu_FUN_00d081d0_CpuObject::FUN_00d081d0()
{
    return reinterpret_cast<char*>(this) + 80;
}

// @fnv 0x00d08370
// pdb: hkpContinuousSimulation::assertThereIsNoCollisionInformationForAgent | hkpContinuousSimulation.obj | fnv360_0822_retail, vtable_prefix + bridge(vtable_prefix|vtable), high
void __stdcall hkpContinuousSimulation_assertThereIsNoCollisionInformationForAgent(int)
{}

// @fnv 0x00d0a2a0
// pdb: hkpKeyframedRigidMotion::setMass | hkpKeyframedRigidMotion.obj | fnv360_0822_retail, objrun_open, low
// pdb params: m
void __stdcall FUN_00d0a2a0(int)
{}

extern int DAT_010cd664;
void __cdecl FUN_00401030(void*);
struct FUN_00d1bab0_t
{
    int m_vft;
    FUN_00d1bab0_t(bool fInit);
};
// @fnv 0x00d1bab0
// pdb: hkpMoppModifier::`scalar deleting destructor' | hkpRemoveTerminalsMoppModifierClass.obj | fnv360_0822_retail, vtable, high
FUN_00d1bab0_t::FUN_00d1bab0_t(bool fInit)
{
    m_vft = (int)&DAT_010cd664;
    if (fInit & 1)
        FUN_00401030(this);
}

inline void* operator new(unsigned int, void* address)
{
    return address;
}

struct ArrayAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* Allocate(int& bytes);
    virtual void Free(void* data, int bytes);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ArrayAllocator* allocator;
};
Holder* __cdecl _FUN_00c85750();
void __cdecl FUN_00c908c0(ArrayAllocator* allocator, void* array, int capacity, int elementSize);

struct IntArray
{
    int* data;
    int size;
    int capacity;

    __forceinline ~IntArray()
    {
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int cap = capacity;
        size = 0;
        if ((cap & 0x80000000) == 0)
            allocator->Free(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }

    static __forceinline int* allocate(ArrayAllocator* allocator, int& count)
    {
        if (count)
        {
            int bytes = count * 4;
            int* p = static_cast<int*>(allocator->Allocate(bytes));
            count = bytes / 4;
            return p;
        }
        return 0;
    }

    __forceinline IntArray(const IntArray& source) : data(0), size(0), capacity(0x80000000)
    {
        int count = source.size;
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int* buffer = allocate(allocator, count);
        int cap = count ? count : 0x80000000;
        data = buffer;
        size = count;
        capacity = cap;
        const int* input = source.data;
        for (int i = 0; i < count; ++i)
            buffer[i] = input[i];
    }

    __forceinline IntArray& operator=(const IntArray& source)
    {
        ArrayAllocator* allocator = _FUN_00c85750()->allocator;
        if ((capacity & 0x3fffffff) < source.size)
        {
            if ((capacity & 0x80000000) == 0)
                allocator->Free(data, (capacity & 0x3fffffff) * 4);
            int bytes = source.size * 4;
            data = static_cast<int*>(allocator->Allocate(bytes));
            capacity = bytes / 4;
        }
        int n = source.size;
        size = n;
        int* dst = data;
        const int* src = source.data;
        for (int i = 0; i < n; ++i)
            dst[i] = src[i];
        return *this;
    }
};

struct ArrayOfArrays
{
    IntArray* data;
    int size;
    int capacity;
    __forceinline ArrayOfArrays& operator=(const ArrayOfArrays& source)
    {
        Holder* h = _FUN_00c85750();
        ArrayAllocator* allocator = h->allocator;
        int oldSize = size;
        int newSize = source.size;
        int common = (newSize > oldSize) ? oldSize : newSize;
        int reserved = capacity & 0x3fffffff;
        if (reserved < newSize)
        {
            int grown = reserved * 2;
            if (newSize >= grown)
                grown = newSize;
            FUN_00c908c0(allocator, this, grown, sizeof(IntArray));
        }
        IntArray* end = data + newSize;
        for (int i = 0; i < oldSize - newSize; ++i)
            end[i].~IntArray();
        const IntArray* input = source.data;
        IntArray* output = data;
        for (int i = 0; i < common; ++i)
            output[i] = input[i];
        input = source.data + common;
        output = data + common;
        for (int i = 0; i < newSize - common; ++i)
            new (output + i) IntArray(input[i]);
        size = newSize;
        return *this;
    }
};

struct FUN_00d0bc20_Outer;

struct FUN_00d0bc20_Vtable
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void Method(FUN_00d0bc20_Outer* owner, unsigned int value);
};

struct FUN_00d0bc20_Outer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00d0bc20_Vtable* unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
};

extern int DAT_010c63bc;
extern int DAT_010cd588;
extern int DAT_010cd598;

struct FUN_00d107d0_t
{
    void* p0;
    unsigned short a;
    unsigned short b;
    union
    {
        void* volatile p8a;
        void* p8b;
    };
    int c;
    FUN_00d107d0_t* FUN_00d107d0(int v);
};

// Sets b to 1, points p8a/p0/p8b at DAT_010c63bc/DAT_010cd598/DAT_010cd588, stores v in c, and returns this.
// @fnv 0x00d107d0
// pdb: hkpEntityEntityBroadPhaseListener::hkpEntityEntityBroadPhaseListener | hkpEntityEntityBroadPhaseListener.obj | fnv360_0822_retail, uvref, high
// pdb params: world
FUN_00d107d0_t* FUN_00d107d0_t::FUN_00d107d0(int v)
{
    b = 1;
    p8a = &DAT_010c63bc;
    p0 = &DAT_010cd598;
    p8b = &DAT_010cd588;
    c = v;
    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);

// @fnv 0x00d043e0
int FUN_00d043e0()
{
    return 1;
}

struct DispatchContext;
struct DispatchNode
{
    unsigned char kind;
    unsigned char subtype;
};
typedef int(__cdecl* DispatchHandler)(DispatchContext*, int, DispatchNode*);
struct DispatchEntry
{
    void* first;
    void* second;
    void* third;
    DispatchHandler handler;
};
struct DispatchContext
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
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    DispatchEntry handlers[256];
};
extern "C" void _ReadWriteBarrier(void);

struct D10E90Obj
{
    unsigned short unk00;
};

// @fnv 0x00d10e90
// pdb: getEpValue | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
static __declspec(noinline) unsigned short FUN_00d10e90(D10E90Obj* obj)
{
    return obj->unk00;
}

extern "C" D10E90Obj* d10e90_stub(void);
extern unsigned short d10e90_sink;

void d10e90_caller(void)
{
    d10e90_sink = FUN_00d10e90(d10e90_stub());
}

class MyClass
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

  public:
    int* GetField20();
};

// @fnv 0x00d10fe0
// pdb: hkp3AxisSweep::getOriginalAabb | hkp3AxisSweep.obj | tesv_win, objrun_sim, low
int* MyClass::GetField20()
{
    return &unk20;
}

extern __m128 DAT_011b3810;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" void _ReadWriteBarrier(void);

struct __declspec(align(16)) Vec4
{
    float q[4];
};

void __cdecl FUN_00d1b4d0(const void* a, int b, const Vec4* c, const Vec4* d, int e, int f, int g, int h, int i, int j);

extern "C" void __cdecl FUN_00d1b4d0(int, int, const __m128*, const int*, int, int, int, int, int, int);

struct FUN_00d1ba90
{
    virtual ~FUN_00d1ba90();
};
// @fnv 0x00d1ba90
FUN_00d1ba90::~FUN_00d1ba90()
{}

extern "C" void _ReadWriteBarrier();
struct D01B40_Sub
{
    virtual void v00();
    virtual int GetValueV();
    int GetValue()
    {
        _ReadWriteBarrier();
        return GetValueV();
    }
};

typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int m128i_i32[4];
} __m128i;

extern "C"
{
    __m128i _mm_unpacklo_epi16(__m128i, __m128i);
    __m128i _mm_unpackhi_epi16(__m128i, __m128i);
    __m128i _mm_slli_epi32(__m128i, int);
    __m128i _mm_srli_epi32(__m128i, int);
    __m128 _mm_cvtepi32_ps(__m128i);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern __m128 DAT_011b3810;
extern "C" void _ReadWriteBarrier(void);

void __cdecl ResizeAudioStream(void* allocator, void* arr, int elemSize);

struct __declspec(align(16)) ScaleSplat
{
    float x, y, z, w;
};

struct __declspec(align(16)) RawWords
{
    int d0, d1, d2, d3;
};

extern "C" __m128 _mm_cmpeq_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_andnot_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_or_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_rcp_ps(__m128 a);

extern __m128 DAT_01267e30;
extern __m128 DAT_010c7170;
extern __m128 DAT_010cd670;

static inline __m128 quadRecip(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}
class HkVec4
{
  public:
    void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        m_vComponents = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    void setSub4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void select32(const HkVec4& a, const HkVec4& b, const __m128& mask)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(mask, b.m_vComponents), _mm_andnot_ps(mask, a.m_vComponents));
    }
    __m128 compareEqual4(const HkVec4& a) const
    {
        return _mm_cmpeq_ps(m_vComponents, a.m_vComponents);
    }
    void setReciprocal4(const HkVec4& v)
    {
        m_vComponents = quadRecip(v.m_vComponents);
    }

  private:
    __m128 m_vComponents;
};
struct HkBundle
{
    HkVec4 m_data[3];
};
struct HkRayBundle
{
    __forceinline HkRayBundle(const HkBundle& from, const HkBundle& to, int mask)
    {
        const HkVec4& kOne = (const HkVec4&)DAT_010c7170;
        const HkVec4& kMaxPoint = (const HkVec4&)DAT_010cd670;
        const HkVec4& kZero = (const HkVec4&)DAT_01267e30;
        m_uiMask = mask;
        m_vFrom = from;
        HkBundle delta;
        for (int i = 0; i < 3; i++)
        {
            delta.m_data[i].setSub4(to.m_data[i], m_vFrom.m_data[i]);
            __m128 isZero = delta.m_data[i].compareEqual4(kZero);
            HkVec4 maskedDelta;
            maskedDelta.select32(delta.m_data[i], kOne, isZero);
            HkVec4 invDelta;
            invDelta.setReciprocal4(maskedDelta);
            m_vInverseDirection.m_data[i].select32(invDelta, kMaxPoint, isZero);
        }
    }
    HkBundle m_vFrom;
    HkBundle m_vInverseDirection;
    int m_uiMask;
};

typedef void*(__stdcall* S00d1b9b0_TlsGet)(unsigned long dwTlsIndex);

struct S00d1b4d0_Node
{
    unsigned code;
    unsigned packed;
    S00d1b4d0_Node* child()
    {
        return (S00d1b4d0_Node*)((char*)this + (code & 0x7ffffffc));
    }
};
struct __declspec(align(8)) S00d1b4d0_NodeCopy
{
    unsigned code;
    unsigned packed;
    void set(const S00d1b4d0_Node* p)
    {
        code = p->code;
        packed = p->packed;
    }
};
struct S00d1b4d0_Result
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct RealVec
{
    union
    {
        __m128 q;
        float f[4];
    };
    RealVec()
    {}
    const float& at(unsigned i) const
    {
        return f[i];
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);

struct IVector
{
    __m128i q;
    void unpackLo(const IVector& a, const IVector& b)
    {
        q = _mm_unpacklo_epi16(a.q, b.q);
    }
    void unpackHi(const IVector& a, const IVector& b)
    {
        q = _mm_unpackhi_epi16(a.q, b.q);
    }
};
struct FVector
{
    __m128 q;
    void convert(const IVector& a, __m128 bias)
    {
        __m128i hi = _mm_srli_epi32(a.q, 16);
        __m128i lo = _mm_srli_epi32(_mm_slli_epi32(a.q, 16), 16);
        q = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(hi), bias), _mm_cvtepi32_ps(lo));
    }
    void mul(const FVector& a, __m128 b)
    {
        q = _mm_mul_ps(a.q, b);
    }
    void add(const FVector& a, __m128 b)
    {
        q = _mm_add_ps(a.q, b);
    }
};
