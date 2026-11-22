#include "f3_common.h"
// src/havok/common/base/math/swepttransform/hkswepttransformutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/swepttransform/hkswepttransformutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cf1480
// pdb: hkSweptTransformUtil::setTimeInformation | hkSweptTransformUtil.obj | fnv360_0822_retail, call_gap, low
// pdb params: startTime, invDeltaTime, motionState
void FUN_00cf1480(float afValue1, float afValue2, int* piTarget)
{
    *reinterpret_cast<float*>(piTarget + 19) = afValue1;
    *reinterpret_cast<float*>(piTarget + 23) = afValue2;
}

struct S_00cf10f0_BinaryStream;
typedef unsigned int(__cdecl* S_00cf10f0_ReadFn)(S_00cf10f0_BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S_00cf10f0_BinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00cf10f0_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T>
inline void S_00cf10f0_BinaryStreamLoad(S_00cf10f0_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct S_00cf10f0_Stream
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
    S_00cf10f0_BinaryStream* unk24c;
};

struct S_00cf10f0_Tls
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
__declspec(thread) S_00cf10f0_Tls DAT_tls;

struct S_00cf10f0_Ctx
{
    int saved;
    __forceinline S_00cf10f0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00cf10f0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};

struct S_00cf10f0_Heap
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
struct S_00cf10f0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cf10f0_Heap* m10;
    __forceinline S_00cf10f0_Heap& heap()
    {
        return *m10;
    }
};
S_00cf10f0_Router* FUN_00c85750() throw();

struct S_00cf10f0_Arr4;
void __cdecl FUN_00c908c0(S_00cf10f0_Heap* heap, S_00cf10f0_Arr4* arr, int n, int elemSize);

struct S_00cf10f0_Arr4
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(int n) throw()
    {
        S_00cf10f0_Heap& h = FUN_00c85750()->heap();
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
            FUN_00c908c0(&h, this, (n < cap * 2) ? cap * 2 : n, 4);
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        reserve(n);
        m_iElementCount = n;
    }
    __forceinline void _clearAndDeallocate(S_00cf10f0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 4);
        m_data = 0;
        m_cap = 0x80000000;
    }
};

// Reads a count from the stream, resets arr, reserves n elements, loads n ints into arr->m_data and returns n*4 bytes.
// @f3 0x00979c60 (community match, verified in this file)
extern long (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct S_00cf10f0_TlsHeap
{
    void FUN_008f6d90(int* p, unsigned int bytes, int tag);
};
void __cdecl FUN_00901e90(S_00cf10f0_Arr4* arr, int n, int elemSize);

__forceinline void LoadIntArray_SetSize(S_00cf10f0_Arr4* a, int n)
{
    int cap = a->m_cap & 0x3fffffff;
    if (cap < n)
    {
        FUN_00901e90(a, (n < cap * 2) ? cap * 2 : n, 4);
    }
    a->m_iElementCount = n;
}

// pdb: bhkStream::LoadBinary | bhkStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream, arArray
int __cdecl LoadIntArray(S_00cf10f0_Stream* kStream, S_00cf10f0_Arr4* pArray)
{
    int n = 0;
    S_00cf10f0_BinaryStreamLoad(*kStream->unk24c, &n, 1);
    if ((pArray->m_cap & 0x80000000u) == 0)
    {
        unsigned int count = pArray->m_cap & 0x3fffffffu;
        S_00cf10f0_TlsHeap* h = (S_00cf10f0_TlsHeap*)DAT_00d9b080(DAT_010f3170);
        h->FUN_008f6d90(pArray->m_data, count * 4u, 0x17);
    }
    pArray->m_cap = (pArray->m_cap & 0xc0000000u) | 0x80000000u;
    pArray->m_data = 0;
    pArray->m_iElementCount = 0;
    LoadIntArray_SetSize(pArray, n);
    int bytes = n * 4;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            S_00cf10f0_BinaryStreamLoad(*kStream->unk24c, &pArray->m_data[i], 1);
        }
    }
    return bytes;
}


namespace fnv_00cf1270 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

extern "C" __m128 _mm_setzero_ps(void);

extern __declspec(thread) unsigned int g_uiHeapContext;

struct HeapContextGuard
{
    unsigned int m_uiOld;
    HeapContextGuard(unsigned int uiNew)
    {
        m_uiOld = g_uiHeapContext;
        g_uiHeapContext = uiNew;
    }
    ~HeapContextGuard()
    {
        g_uiHeapContext = m_uiOld;
    }
};

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

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct NiBinaryStreamStandIn
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(NiBinaryStreamStandIn* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int componentCount)
    {
        unsigned int bytesRead = read(this, buffer, totalBytes, componentSizes, componentCount);
        absolutePosition += bytesRead;
        return bytesRead;
    }
    template <class T> unsigned int Read(T* value)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(value, sizeof(T), &size, 1);
    }
    template <class T> unsigned int Read(T* array, unsigned int count)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(array, sizeof(T) * count, &size, 1);
    }
    unsigned int ReadRaw(void* buffer, unsigned int bytes)
    {
        return BinaryRead(buffer, bytes, 0, 0);
    }
};

extern char DAT_0102e368[];

struct __declspec(align(16)) BlobVec
{
    unsigned int x, y, z, w;
};

struct ByteArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(char));
        }
        m_iElementCount = n;
    }
};

struct BlobObject
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    int unk0c;
    BlobVec m_kHeader;
    ByteArray m_data;
    unsigned char unk2c;

    void Init()
    {
        m_vtbl = DAT_0102e368;
        m_usMemSizeAndFlags = 0x30;
        m_sReferenceCount = 1;
        m_data.init();
        unk2c = 2;
        *(__m128*)&m_kHeader = _mm_setzero_ps();
    }
};

}  // namespace fnv_00cf1270

int __cdecl FUN_00cf1f80(int, int, int);
// @fnv 0x00cf2160
// pdb: hkSweptTransformUtil::warpToRotation | hkSweptTransformUtil.obj | tesv_win, caller_sim, low
int __cdecl FUN_00cf2160(unsigned int uiValue, unsigned int arg1)
{
    unsigned int callResult0 = (unsigned int)FUN_00cf1f80((int)(arg1 + 48u), (int)uiValue, (int)arg1);
    return (int)callResult0;
}

#include <xmmintrin.h>

extern double DAT_010924a8;
extern double DAT_01016ff0;
extern float DAT_01016248;
extern float DAT_01011d78;
extern float DAT_01017718;
extern __declspec(align(16)) float DAT_010ec7f0[4];

struct V4
{
    __m128 q;
};

struct FUN_008cd6a0_Class
{
    V4 col0;
    V4 col1;
    V4 col2;
    V4 translation;
    V4 com0;
    V4 com1;
    V4 rot0;
    V4 rot1;
    V4 comLocal;
    void __thiscall FUN_00cb2d90(void*);
};

void FUN_00cf1480(float a, float b, int* c);

struct __declspec(align(16)) MotionVec4
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) MotionMat4
{
    MotionVec4 c0;
    MotionVec4 c1;
    MotionVec4 c2;
    MotionVec4 c3;
};

struct __declspec(align(16)) MotionState_cls
{
    MotionMat4 m_kMotionTransform;  // +0x00
    MotionVec4 m_com0;              // +0x40
    MotionVec4 m_com1;              // +0x50
    MotionVec4 m_rot0;              // +0x60
    MotionVec4 m_rot1;              // +0x70
    MotionVec4 m_comLocal;          // +0x80
    MotionVec4 m_kDeltaAngle;       // +0x90
};

struct Obj_t
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    __m128 m30;
    __m128 m40;
    __m128 m50;
    __m128 m60;
    __m128 m70;
    __m128 m80;
    __m128 m90;

    void FUN_00cb2d90(const __m128& value);
};

// Applies a 3x3 matrix (m00, m10, m20) times a vector (m80) plus translation (first) to produce m40 and m50, preserving the w component of m40.
// @fnv 0x00cf1f80
void __cdecl FUN_00cf1f80(const __m128& apTranslation, const __m128& second, Obj_t* obj)
{
    obj->m90 = _mm_setzero_ps();
    obj->m60 = second;
    obj->m70 = second;
    obj->FUN_00cb2d90(second);
    {
        __m128& t = obj->m30;
        t = apTranslation;
    }
    volatile float saved = ((volatile float*)&obj->m40)[3];
    __m128 v = obj->m80;
    __m128 result = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), obj->m10);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), obj->m00));
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xAA), obj->m20));
    result = _mm_add_ps(result, apTranslation);
    obj->m40 = result;
    obj->m50 = result;
    ((volatile float*)&obj->m40)[3] = saved;
    ((volatile float*)&obj->m50)[3] = 0.0f;
}

extern double DAT_010924a8;
extern double DAT_01016ff0;

struct VectorComponentValue
{
    __m128 m_vValue;
    __forceinline VectorComponentValue(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline VectorComponentValue(__m128 q) : m_vValue(q)
    {}
};

struct hkVector4
{
    union
    {
        __m128 m_vComponents;
        float m_f[4];
    };
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const VectorComponentValue& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void setMul4(const VectorComponentValue& s, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), v.m_vComponents);
    }
    __forceinline void sub4(const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline float lengthSquared4() const
    {
        __m128 l = _mm_mul_ps(m_vComponents, m_vComponents);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0x4e), l);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0xb1), l);
        float r;
        _mm_store_ss(&r, l);
        return r;
    }
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& t)
    {
        __m128 av = a.m_vComponents;
        __m128 weight = t.broadcast();
        __m128 rest = _mm_sub_ps(_mm_load_ps(DAT_010ec7f0), weight);
        m_vComponents = _mm_add_ps(_mm_mul_ps(rest, av), _mm_mul_ps(weight, b.m_vComponents));
    }
    __forceinline void normalize4()
    {
        __m128 l = _mm_mul_ps(m_vComponents, m_vComponents);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0x4e), l);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0xb1), l);
        __m128 e = _mm_rsqrt_ss(l);
        __m128 isZero = _mm_cmpeq_ss(l, _mm_set_ss(DAT_01011d78));
        __m128 three = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(l, e), e));
        __m128 inv = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), e), three));
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m_vComponents);
    }
};

struct __declspec(align(16)) hkVector4L
{
    float x, y, z, w;
    __m128 Vector4f() const
    {
        return _mm_load_ps(&x);
    }
};

struct OutputArg
{
    FUN_008cd6a0_Class* ptr;
    OutputArg(FUN_008cd6a0_Class* p) : ptr(p)
    {}
};
