#include "f3_common.h"
// src/staging/blk_00dc0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include <math.h>
inline void* __cdecl operator new(unsigned int, void* location) throw()
{
    return location;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct hkVector4
{
    __m128 m_vComponents;
};

struct VectorComponentValue
{
    __m128 m_vValue;
    VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct Contact
{
    hkVector4 m_kPoint;
    hkVector4 m_vHitNormal;
};

struct MemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* m_pStreamAllocator;
};

extern MemoryRouter* __cdecl FUN_00c85750() throw();
extern void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize) throw();

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void AddBack(const T& t)
    {
        MemoryRouter* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

// @f3 0x00a57480 (community match, verified in this file)
extern const float DAT_00de6e60;
extern const double DAT_00db5748;

static inline float Dot3f(const hkVector4& a, const hkVector4& b)
{
    return a.m_vComponents.m128_f32[0] * b.m_vComponents.m128_f32[0]
         + a.m_vComponents.m128_f32[1] * b.m_vComponents.m128_f32[1]
         + a.m_vComponents.m128_f32[2] * b.m_vComponents.m128_f32[2];
}

static inline float Dot4f(const hkVector4& a, const hkVector4& b)
{
    return b.m_vComponents.m128_f32[0] * a.m_vComponents.m128_f32[0]
         + a.m_vComponents.m128_f32[1] * b.m_vComponents.m128_f32[1]
         + a.m_vComponents.m128_f32[2] * b.m_vComponents.m128_f32[2]
         + a.m_vComponents.m128_f32[3] * *(const volatile float*)&b.m_vComponents.m128_f32[3];
}

static inline void CopyContact(Contact& d, const Contact& s)
{
    d.m_kPoint.m_vComponents.m128_f32[0] = s.m_kPoint.m_vComponents.m128_f32[0];
    d.m_kPoint.m_vComponents.m128_f32[1] = s.m_kPoint.m_vComponents.m128_f32[1];
    d.m_vHitNormal.m_vComponents.m128_i32[0] = s.m_vHitNormal.m_vComponents.m128_i32[0];
    d.m_kPoint.m_vComponents.m128_f32[2] = s.m_kPoint.m_vComponents.m128_f32[2];
    d.m_vHitNormal.m_vComponents.m128_i32[1] = s.m_vHitNormal.m_vComponents.m128_i32[1];
    d.m_kPoint.m_vComponents.m128_f32[3] = s.m_kPoint.m_vComponents.m128_f32[3];
    d.m_vHitNormal.m_vComponents.m128_i32[2] = s.m_vHitNormal.m_vComponents.m128_i32[2];
}

void __cdecl FUN_00901f10(void* array, int elementSize);

static __forceinline void PushContact(hkArray<Contact>* array, const Contact& contact)
{
    if (array->m_iElementCount == (array->m_iCapacityState & 0x3fffffff))
        FUN_00901f10(array, sizeof(Contact));
    CopyContact(array->m_data[array->m_iElementCount++], contact);
}
__declspec(noalias) int __cdecl FUN_00a57050(hkArray<hkVector4>* planes, int skip1, int skip2, int plane, Contact* contact);

hkBool __cdecl FUN_00dd66d0(const hkVector4* direction, hkArray<hkVector4>* planes, int skip1, int skip2,
                            hkVector4* position, hkArray<Contact>* contacts)
{
    float best = DAT_00de6e60;
    bool found = false;
    for (int i = 0; i < planes->m_iElementCount; i++)
    {
        if (i == skip1 || i == skip2)
            continue;
        float denom = Dot3f(planes->m_data[i], *direction);
        if (denom > 1e-08f)
        {
            position->m_vComponents.m128_f32[3] = 1.0f;
            float num = Dot4f(planes->m_data[i], *position);
            float dist = -num / (float)fabs(denom);
            if (dist < best + DAT_00db5748)
            {
                Contact contact;
                if (FUN_00a57050(planes, skip1, skip2, i, &contact) == 0)
                {
                    found = true;
                    float diff = dist - best;
                    if ((float)fabs(diff) < DAT_00db5748)
                    {
                        PushContact(contacts, contact);
                    }
                    else
                    {
                        contacts->m_iElementCount = 0;
                        PushContact(contacts, contact);
                        best = dist;
                    }
                }
            }
        }
    }
    return found;
}
