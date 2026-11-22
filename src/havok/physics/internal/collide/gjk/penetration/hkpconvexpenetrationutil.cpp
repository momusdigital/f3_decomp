#include "f3_common.h"
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};

struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void FUN_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};

// @fnv 0x00dfaf80
void Obj::SetEntries(const hkVector4* aVecA, const hkVector4* aVecB, const hkVector4* aVecC)
{
    m_num = 4;
    for (int iIndex = 0; iIndex < 4; iIndex++)
    {
        m_usTrailingValue[iIndex].m_kPointA = aVecA[iIndex];
        m_usTrailingValue[iIndex].m_kPointB = aVecB[iIndex];
        m_usTrailingValue[iIndex].m_iThirdValue = aVecC[iIndex];
        m_usTrailingValue[iIndex].m_flag = 0;
    }
    FUN_00e2d440();
    m_iThirdValue = 0;
}

extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

struct S00cd7530_SimdReal
{
    __m128 m_vValue;
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct S00cd7530_Vec
{
    __m128 m_vComponents;
    __forceinline void setSub4(const S00cd7530_Vec& a, const S00cd7530_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline S00cd7530_SimdReal dot3(const S00cd7530_Vec& a) const
    {
        __m128 m = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 y = _mm_shuffle_ps(m, m, 0x55);
        __m128 xy = _mm_add_ss(y, m);
        __m128 z = _mm_shuffle_ps(m, m, 0xaa);
        S00cd7530_SimdReal r;
        r.m_vValue = _mm_add_ss(z, xy);
        return r;
    }
};

struct P
{
    const S00cd7530_Vec* p;
    P()
    {}
};
struct Mid
{
    const S00cd7530_Vec* p;
    Mid()
    {}
};

extern "C" __m128 _mm_add_ps(__m128, __m128);

struct S00dfa940_Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};

struct S00dfa940_Simplex
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    S00dfa940_Entry m_usTrailingValue[0xBA];
    int m_t0;
    int m_t1;
    int m_t2;
    int m_t3;

    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
    int GetNearestEntry();
};

double FUN_00df9ae0();

struct S00dfa940_Solver
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
    hkVector4 m_30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int m_5c;
    const hkVector4* m_60;
    const hkVector4* m_64;
    const hkVector4* m_68;
    int m_6c;

    int FUN_00dfa940(int a1);
    int FUN_00df9fe0(int a1, int* out);
    void FUN_00df9b50(int idx, S00dfa940_Entry* e);
    int FUN_00df9c90(S00dfa940_Simplex* o, int idx, S00dfa940_Entry* e, int* out);
    void FUN_00df9d90(S00dfa940_Simplex* o, int idx, int a1);
};

// Loops building simplex entries until FUN_00df9fe0/FUN_00df9c90 give a result; on result 3 retries up to 0x14 times, adding an offset to m_30; returns status.
// @f3 0x00a7f4f0 (community match, verified in this file)
// pdb: hkpConvexPenetrationUtil::calculatePenetrationDepth | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: output
int S00dfa940_Solver::FUN_00dfa940(int a1)
{
    S00dfa940_Simplex simplex;
    volatile hkVector4 tmp;
    union { int res; float f; };
    int vi;
    int ret;
    S00dfa940_Entry* e;

    for (;;)
    {
        res = 0;
        if (FUN_00df9fe0(a1, &res) == 1)
        {
            ret = res;
            if (ret != 3)
                goto out;
        }
        else
        {
            simplex.SetEntries(m_60, m_64, m_68);
            vi = simplex.GetNearestEntry();
            e = &simplex.m_usTrailingValue[simplex.m_num++];
            e->m_flag = 0;
            FUN_00df9b50(vi, e);
            if (FUN_00df9c90(&simplex, vi, e, &res) != 1)
            {
                for (;;)
                {
                    int n = simplex.m_num;
                    if (n >= 0x37)
                    {
                        ret = 2;
                        goto done;
                    }
                    vi = simplex.GetNearestEntry();
                    simplex.m_num++;
                    e = &simplex.m_usTrailingValue[n];
                    e->m_flag = 0;
                    FUN_00df9b50(vi, e);
                    if (FUN_00df9c90(&simplex, vi, e, &res) == 1)
                        break;
                }
            }
            ret = res;
            if (ret != 3)
                goto done;
        }
        if (++m_5c == 1)
        {
            m_6c = 1;
            continue;
        }
        if (m_5c >= 0x14)
            goto out;
        m_6c = 0;
        f = (float)((FUN_00df9ae0() - *(const double*)0x00db5748) * *(const double*)0x00e87e60);
        tmp.x = f;
        tmp.y = f;
        tmp.z = f;
        const hkVector4& mm = m_30;
        tmp.x = tmp.x + mm.x;
        tmp.y = m_30.y + tmp.y;
        tmp.z = m_30.z + tmp.z;
        tmp.w = m_30.w + tmp.w;
        m_30.x = tmp.x;
        m_30.y = tmp.y;
        m_30.z = tmp.z;
        m_30.w = tmp.w;
    }
done:
    FUN_00df9d90(&simplex, vi, a1);
out:
    return ret;
}


extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD DAT_0126835c;

struct S_00dfaac0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00dfaac0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dfaac0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dfaac0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dfaac0_TimerCommand* h = (S_00dfaac0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct S_00dfaac0_Transform
{
    float m[16];
};

struct __declspec(align(16)) S_00dfaac0_Penetration
{
    int unk00;
    S_00dfaac0_Penetration(int a, int b, const S_00dfaac0_Transform& t, float f, int c, int d, int e, int g);
    int FUN_00dfa940(int out);
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
};

int __cdecl FUN_00e2db70(int a, int b, const S_00dfaac0_Transform& t, int c, int d, int out);

// Constructs a Penetration object and calls FUN_00dfa940; if it returns 3, calls FUN_00e2db70 and returns 1, otherwise returns the original result.
// @f3 0x00a7f6b0 (community match, verified in this file)
struct TransformCopyA7 { void FUN_008fda60(const S_00dfaac0_Transform&); };
__forceinline S_00dfaac0_Penetration::S_00dfaac0_Penetration(int a, int b, const S_00dfaac0_Transform& t, float f, int c, int d, int e, int g)
{
    reinterpret_cast<TransformCopyA7*>(&unk00)->FUN_008fda60(t);
    float* farr = (float*)&unk40;
    farr[0] = f;
    farr[1] = f;
    farr[2] = f;
    farr[3] = f;
    *(float*)&unk50 = f * f;
    unk54 = a;
    unk58 = b;
    unk5C = 0;
    unk60 = c;
    unk64 = d;
    unk68 = e;
    unk6C = g;
}

// pdb: hkCalculatePenetrationDepth | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, ustr, high
// pdb params: shapeA, shapeB, btoa, epsTol, pointsAinA, pointsBinB, simplex, simplexSize, output
// pdb: hkCalculatePenetrationDepth | hkpConvexPenetrationUtil.obj | fnv360_0822_retail, ustr, high (was: TestPenetration)
int __cdecl hkCalculatePenetrationDepth(int a, int b, const S_00dfaac0_Transform& t, float f, int c, int d, int e, int g, int out)
{
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("TtPenetration");
    S_00dfaac0_Penetration pen(a, b, t, f, c, d, e, g);
    int res = pen.FUN_00dfa940(out);
    if (res == 3)
    {
        FUN_00e2db70(a, b, t, c, d, out);
        res = 1;
    }
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("Et");
    return res;
}


extern "C"
{

    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}

struct Arg1
{
    int unk00, unk04, unk08, unk0c;
    float float10;
};

struct Arg2
{
    int unk00, unk04, unk08, unk0c;
    float float10;
    float getRadius() const
    {
        return float10;
    }
};

struct OutItem
{
    hkVector4 point;
    hkVector4 direction;
};

struct LocalStruct70
{
    hkVector4 m_v0;
    hkVector4 m_v1;
    float m_f;
};

struct hkTransform
{
    hkVector4 m_rotation[3];
    hkVector4 m_vTranslation;
    void operator=(const hkTransform& o)
    {
        *(__m128*)this = *(const __m128*)&o.m_rotation[0];
        m_rotation[1] = o.m_rotation[1];
        m_rotation[2] = o.m_rotation[2];
        m_vTranslation = o.m_vTranslation;
    }
};

struct WorkObject
{
    int unk00, unk04;
    int m_num;
    int unk0c, unk10, unk14, unk18, unk1c;
    Entry m_usTrailingValue[186];
    hkVector4 unk2ea0;
    void SetEntries(const hkVector4*, const hkVector4*, const hkVector4*);
    Entry* allocEntry()
    {
        Entry* e = &m_usTrailingValue[m_num++];
        e->m_flag = 0;
        return e;
    }
};

struct Item
{
    hkTransform m_matrix;
    __m128 m_vec40;
    float m_float50;
    Arg1* m_arg1;
    Arg2* m_arg2;
    int m_unk5C;
    hkVector4* m_ptr60;
    hkVector4* m_ptr64;
    hkVector4* m_ptr68;
    int m_unk6C;
    hkVector4 m_vec70[4];
    hkVector4 m_vecB0[4];
    hkVector4 m_vecF0[4];
    Arg2* m_arg2_copy;
    OutItem* m_arg5;
    int unk138, unk13c;
    WorkObject m_obj;
    int m_field2ff0;
    int unk2ff4, unk2ff8, unk2ffc;

    void init(Arg1* a1, Arg2* a2, const hkTransform& trans, float eps, hkVector4* v70, hkVector4* vB0, hkVector4* vF0,
              int u6c)
    {
        m_matrix = trans;
        m_vec40 = _mm_set_ps1(eps);
        m_float50 = eps * eps;
        m_arg1 = a1;
        m_arg2 = a2;
        m_ptr60 = v70;
        m_ptr64 = vB0;
        m_unk5C = 0;
        m_ptr68 = vF0;
        m_unk6C = u6c;
    }

    int FUN_00df9fe0(LocalStruct70* s, int* arr);
    void FUN_00df9b50(int field2ff0, Entry* entry);
    int FUN_00df9c90(const WorkObject& obj, int field2ff0, Entry* entry, int* arr);
    void FUN_00df9d90(WorkObject* obj, int field2ff0, LocalStruct70* s);
};

struct WorkArray
{
    Item* data;
    Item& operator[](int i)
    {
        return ((Item*)data)[i];
    }
    Item* begin()
    {
        return data;
    }
};
