#include "f3_common.h"
// src/havok/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    double m128_f64[2];
} __m128;

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);

extern void* __cdecl FUN_00c85750(void);
extern void __cdecl ResizeAudioStream(void* apCtx, void* apVec, int aElemSize);

struct __declspec(align(16)) FUN_00c7f690_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00c7f690(const __m128* m, const __m128* v);
};

struct FUN_00d52140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_18;
    unsigned char m_19;
    int FUN_00d52000(FUN_00c7f690_cls* t);
    void FUN_00d520a0(FUN_00c7f690_cls* t);
    int FUN_00d52140(char* a1, char* a2, const __m128* a3);
};

// @f3 0x009dfce0 (community match, verified in this file)
// pdb: hkpConstraintConstructionKit::setPivotsHelper | hkpConstraintConstructionKit.obj | tesv_win, caller_sim, low
int FUN_00d52140_cls::FUN_00d52140(char* a1, char* a2, const __m128* a3)
{
    FUN_00c7f690_cls t1;
    FUN_00c7f690_cls t2;
    t1.FUN_00c7f690((const __m128*)(a1 + 0xe0), a3);
    t2.FUN_00c7f690((const __m128*)(a2 + 0xe0), a3);
    int iResult = this->FUN_00d52000(&t1);
    this->FUN_00d520a0(&t2);
    this->m_18 = 1;
    this->m_19 = 1;
    return iResult;
}


struct hkMemoryAllocatorD;

struct hkMemoryRouterD
{
    unsigned int unk, unkCur, unkValue, unk0C;
    hkMemoryAllocatorD* m_pStreamAllocator;

    hkMemoryAllocatorD& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocatorD* pkAlloc, void* pkArray, int iElemSize);

struct hkVector4D521
{
    __m128 m_vComponents;

    void operator=(const hkVector4D521& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
};

template <class T> __forceinline void constructWithCopyD(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct hkArrayD
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD& kAlloc = static_cast<hkMemoryRouterD*>(FUN_00c85750())->heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        }
        constructWithCopyD<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

#include <math.h>
inline void FillWords328(int* dest, int n, const int& value)
{
    for (int i = 0; i < n; ++i)
        dest[i] = value;
}

struct Draw328_intarr
{
    int* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_vecarr
{
    __m128* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Draw328_vecarr m_vec;
    Draw328_intarr m_auiHeaderValues;
};

struct Draw328_cls
{
    int unk00;
    Draw328_mgr* m_pMgr;

    unsigned int AppendHeaderAndVector(unsigned char a1, float a2);
};

// Appends 0x12 and a1 to m_auiHeaderValues, appends a cosf(a2) vector to m_vec, and returns the previous m_vec count.
// @f3 0x009dff00 (community match, verified in this file)
#include <math.h>
void __cdecl FUN_00901f10(void* arr, int elemSize);
extern float FUN_00dc0bc8;
struct __declspec(align(16)) Draw328_Vec4
{
    float x;
    float y;
    float z;
    float w;
};
// pdb: hkpConstraintConstructionKit::setConeLimit | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
unsigned int Draw328_cls::AppendHeaderAndVector(unsigned char a1, float a2)
{
    Draw328_intarr* ints = &m_pMgr->m_auiHeaderValues;
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        FUN_00901f10(ints, 4);
    }
    ints->data[ints->count] = 0x12;
    ++ints->count;

    int tag = a1;
    ints = &m_pMgr->m_auiHeaderValues;
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        FUN_00901f10(ints, 4);
    }
    ints->data[ints->count] = tag;
    ++ints->count;

    float x = cosf(a2);
    Draw328_Vec4 v;
    v.x = x;

    Draw328_mgr* mgr = m_pMgr;
    unsigned int uiIndex = (unsigned int)mgr->m_vec.count;

    Draw328_vecarr* vec = &mgr->m_vec;
    if (vec->count == (int)(vec->capFlags & 0x3fffffffu))
    {
        FUN_00901f10(vec, 0x10);
    }
    float* e = (float*)(vec->data + vec->count);
    vec->count++;
    e[0] = v.x;
    e[1] = FUN_00dc0bc8;
    e[2] = 0.0f;
    e[3] = 0.0f;

    mgr = m_pMgr;
    mgr->unk04 += 0x30;
    mgr->unk08++;
    mgr->unk0c++;
    return uiIndex;
}


struct hkMemAlloc;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAlloc* m_pStreamAllocator;
    hkMemAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline MemRouter* getRouter()
{
    return (MemRouter*)FUN_00c85750();
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(hkMemAlloc& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t)
    {
        _pushBack(getRouter()->heap(), t);
    }
};

struct hkVec4
{
    __m128 m_vComponents;
    __forceinline hkVec4()
    {}
    __forceinline hkVec4(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct GeomBuffer
{
    int m_00;
    int m_iVertexCount;
    int m_uiVertexCount;
    int m_numPrims;
    hkArr<hkVec4> m_verts;
    hkArr<int> m_cmds;
};

struct GeomWriter
{
    int m_00;
    GeomBuffer* m_buffer;
    int FUN_00d524d0(unsigned char a1, unsigned char a2, float a3, float a4);
};

// Appends command 0x13 with a1 and a2, then a vector (sin(a3), sin(a4), 0, 0) to the buffer, updates its counters, and returns the vector's index.
// @f3 0x009dfff0 (community match, verified in this file)
#include <math.h>
extern void __cdecl FUN_00901f10(void*, int);
static __forceinline void AppendGeomCommand(hkArr<int>* commands, const int& value)
{
    if (commands->m_iElementCount == commands->getCapacity())
        FUN_00901f10(commands, sizeof(int));
    commands->m_data[commands->m_iElementCount] = value;
    ++commands->m_iElementCount;
}

// pdb: hkpConstraintConstructionKit::setTwistLimit | hkpConstraintConstructionKit.obj | tesv_win, objrun_open, low
int GeomWriter::FUN_00d524d0(unsigned char a1, unsigned char a2, float a3, float a4)
{
    AppendGeomCommand(&m_buffer->m_cmds, 0x13);
    AppendGeomCommand(&m_buffer->m_cmds, static_cast<int>(a1));
    AppendGeomCommand(&m_buffer->m_cmds, static_cast<int>(a2));
    struct __declspec(align(16)) VertexComponents { float x, y, z, w; } vertex;
    vertex.x = sinf(a3);
    vertex.y = sinf(a4);
    GeomBuffer* buffer = m_buffer;
    const int vertexCapacity = buffer->m_verts.m_iCapacityState & 0x3fffffff;
    int oldCount = buffer->m_verts.m_iElementCount;
    hkArr<hkVec4>* verts = &buffer->m_verts;
    if (verts->m_iElementCount == vertexCapacity)
        FUN_00901f10(verts,16);
    float* dest=(float*)(verts->m_data + verts->m_iElementCount);
    ++verts->m_iElementCount;
    dest[0]=vertex.x;
    dest[1]=vertex.y;
    dest[2]=0.0f;
    dest[3]=0.0f;
    GeomBuffer* updated = m_buffer;
    ++updated->m_uiVertexCount;
    updated->m_iVertexCount += 0x30;
    ++updated->m_numPrims;
    return oldCount;
}

