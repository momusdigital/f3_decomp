#include "f3_common.h"
// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};
struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};
struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};
void __fastcall FUN_00dae220(int unused, S_00dad640_Set* set);

#include <xmmintrin.h>

struct __declspec(align(16)) S_00daee00_Vec
{
    float x;
    float y;
    float z;
    float w;

    void setSub4(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        *(__m128*)this = _mm_sub_ps(*(const __m128*)&a, *(const __m128*)&b);
    }
    void setCross(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        __m128 v1 = *(const __m128*)&a;
        __m128 v2 = *(const __m128*)&b;
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
        *(__m128*)this = _mm_sub_ps(c0, c1);
    }
    void storeLengthSquared3(float& f) const
    {
        __m128 v = *(const __m128*)this;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        _mm_store_ss(&f, r);
    }
};

// @fnv 0x00dad720
volatile int g_rec;
volatile int g_vecs;
volatile int g_out;
volatile int g_res;

#include <xmmintrin.h>
namespace fnv_00dad860 {
#include <xmmintrin.h>

typedef float hkReal;
typedef __m128 hkQuadReal;

class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;

__forceinline VectorComponentValue operator+(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_add_ss(r.getQuad(), s.getQuad());
}
__forceinline VectorComponentValue operator/(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_div_ss(r.getQuad(), s.getQuad());
}

class Vector4Comparison
{
  public:
    enum Mask
    {
        MASK_XY = 3
    };
    __forceinline int anyIsSet(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
    hkQuadReal m_uiMask;
};

class hkVector4
{
  public:
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
    {
        static __declspec(align(16)) const float cw[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        hkQuadReal t = _t.broadcast();
        hkQuadReal s = _mm_sub_ps(*(const hkQuadReal*)&cw, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline Vector4Comparison compareLessThanZero4() const
    {
        hkVector4 zero;
        zero.m_vComponents = _mm_setzero_ps();
        Vector4Comparison m;
        m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline VectorComponentValue getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
        }
    }
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    hkQuadReal m_vComponents;
};

namespace hkVector4Util_S {
}

template <typename T> class ValueWrapper
{
  public:
    __forceinline operator T() const
    {
        return m_kStorage;
    }
    T m_kStorage;
};

struct MeshVertexBasisData
{
    hkVector4 m_pMeshVertexBuffer[16];
    hkVector4 m_kFirstBasisVector;
    ValueWrapper<hkReal> m_kBoxBasisVector;
    ValueWrapper<hkReal> m_kThirdBasisVector;
    ValueWrapper<hkReal> m_kFourthBasisVector;
    ValueWrapper<hkReal> m_fMinimumCollisionSeparation;
    __forceinline const hkVector4& getVertexA(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
    __forceinline const hkVector4& getVertexB(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
};

struct AlignedPairData
{
    unsigned short m_ucDimensionA;
    unsigned short m_ucDimensionB;
    unsigned char m_vert0;
    unsigned char m_vert1;
    unsigned char m_vert2;
};

struct TriangleClosestPointInfo
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 m_kTriangleNormal;
};

const MeshVertexBasisData* volatile g_work;
const AlignedPairData* volatile g_point;
TriangleClosestPointInfo* volatile g_out;
}  // namespace fnv_00dad860

struct S_00dae220_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dae220_Set
{
    unsigned char numA;
    unsigned char numB;
    unsigned char count;
    unsigned char unk3;
    S_00dae220_Entry entries[1];
};

// @f3 0x00a38060 (community match, verified in this file)
#include <intrin.h>

void __fastcall FUN_00dae220(int unused, S_00dae220_Set* set)
{
    __declspec(align(16)) float usedWords[4];
    usedWords[3] = 0.0f;
    usedWords[2] = 0.0f;
    usedWords[1] = 0.0f;
    usedWords[0] = 0.0f;
    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);
    unsigned remap[16];
    unsigned contactCount = set->count;
    if (contactCount > 0)
    {
        _ReadWriteBarrier();
        unsigned remaining = set->count;
        unsigned char* offs = set->entries[0].offs;
        *(volatile unsigned int*)&remaining = remaining;
        do
        {
            int total = offs[-4] + offs[-3];
            used[offs[0] >> 4] = (unsigned char)1;
            used[offs[1] >> 4] = (unsigned char)1;
            if (total >= 3)
                used[offs[2] >> 4] = (unsigned char)1;
            if (total == 4)
                used[offs[3] >> 4] = (unsigned char)1;
            offs += 8;
            remaining -= 1;
        } while (remaining != 0);
    }
    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + contactCount * 8);
    int total = set->numA + set->numB;
    int i = 0;
    unsigned count = 0;
    unsigned offset = 0;
    for (; i < total; ++i)
    {
        remap[i] = offset;
        if (used[i])
        {
            vertices[count++] = vertices[i];
            offset += 16;
        }
    }
    unsigned countA = remap[set->numA] >> 4;
    set->numA = static_cast<unsigned char>(countA);
    set->numB = static_cast<unsigned char>(count - countA);
    for (unsigned i = 0; i < set->count; ++i)
    {
        S_00dae220_Entry& e = set->entries[i];
        e.offs[0] = static_cast<unsigned char>(remap[e.offs[0] >> 4]);
        e.offs[1] = static_cast<unsigned char>(remap[e.offs[1] >> 4]);
        e.offs[2] = static_cast<unsigned char>(remap[e.offs[2] >> 4]);
        e.offs[3] = static_cast<unsigned char>(remap[e.offs[3] >> 4]);
    }
}


extern "C" void _ReadWriteBarrier(void);

struct ContactManifold
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[4];
};

struct ContactRecord
{
    __m128 position;
    __m128 normal;
    unsigned id;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
};
struct ContactCache
{
    ContactRecord points[4];
    int FUN_00daee00();
};
struct ContactContext
{
    unsigned unk00;
    void* userData;
};
struct ContactManager
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned short add(void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                               ContactRecord* point);
    virtual void slot4();
    virtual void remove(unsigned short id, void* userData);
};

static inline void CopyContact(ContactRecord& destination, const ContactRecord& source)
{
    destination.position = source.position;
    destination.normal = source.normal;
    destination.id = source.id;
}

// Four contact entries are followed immediately by a variable-length vertex table.
// For smaller manifolds the table starts after the last live entry.
static inline unsigned short* VertexIds(ContactManifold* set)
{
    return reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + set->count * 8);
}
static inline S_00dad4d0_Entry& ContactEntry(ContactManifold* set, unsigned index)
{
    return *reinterpret_cast<S_00dad4d0_Entry*>(reinterpret_cast<char*>(set) + 4 + index * 8);
}

static void __fastcall FUN_00dae220(int, ContactManifold* set);

// @f3 0x00a3a420 (community match, verified in this file)
static __declspec(noinline) void __fastcall FUN_00a38060(int, ContactManifold* set)



{



    __declspec(align(16)) unsigned int usedWords[4];



    _mm_store_ps(reinterpret_cast<float*>(usedWords), _mm_setzero_ps());



    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);



    unsigned remap[16];



    unsigned contactCount = set->count;



    unsigned char* offs = ContactEntry(set, 0).offs;



    for (unsigned k = 0; k < contactCount; ++k)



    {



        int total = offs[-4] + offs[-3];



        used[offs[0] >> 4] = 1;



        used[offs[1] >> 4] = 1;



        if (total >= 3)



            used[offs[2] >> 4] = 1;



        if (total == 4)



            used[offs[3] >> 4] = 1;



        offs += 8;



    }



    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + contactCount * 8);



    int total = set->unk0 + set->unk1;



    unsigned count = 0;



    unsigned offset = 0;



    for (int i = 0; i < total; ++i)



    {



        remap[i] = offset;



        if (used[i])



        {



            vertices[count++] = vertices[i];



            offset += 16;



        }



    }



    unsigned countA = remap[set->unk0] >> 4;



    set->unk0 = static_cast<unsigned char>(countA);



    set->unk1 = static_cast<unsigned char>(count - countA);



    for (unsigned i = 0; i < set->count; ++i)



    {



        S_00dad4d0_Entry& entry = ContactEntry(set, i);



        entry.offs[0] = static_cast<unsigned char>(remap[entry.offs[0] >> 4]);



        entry.offs[1] = static_cast<unsigned char>(remap[entry.offs[1] >> 4]);



        entry.offs[2] = static_cast<unsigned char>(remap[entry.offs[2] >> 4]);



        entry.offs[3] = static_cast<unsigned char>(remap[entry.offs[3] >> 4]);



    }



}







namespace f3m_00a3a420 {


struct CacheShim { int FUN_00a398e0(); };


struct RecShim { void FUN_00a2b780(const ContactRecord& source); };


}


// pdb: hkGskManifold_addPoint | hkpGskManifoldUtil.obj | fnv360_0822_retail, call_gap_sim + bridge(call_seq|call_gap) + skyrim(call_seq), high
int hkGskManifold_addPoint(ContactManifold* set, void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,



                 ContactRecord* point, ContactCache* cache, ContactManager* manager, int defer)



{



    S_00dad4d0_Key* activeKey;



    int replaced = 4;



    unsigned short id;



    if (set->count == 4)



    {



        int index = reinterpret_cast<f3m_00a3a420::CacheShim*>(cache)->FUN_00a398e0();



        if (index == 4)



            return 5;



        manager->remove(set->entries[index].id, context->userData);



        S_00dad640_Entry* added = &set->entries[index];



        if (index)



            *added = set->entries[0];



        else



            *added = set->entries[1];



        FUN_00a38060(index, set);



        activeKey = key;



        id = manager->add(a, b, c, context, activeKey, point);



        if (id == 0xffff)



        {



            set->entries[0] = set->entries[3];



            unsigned res = set->count;



            unsigned newCount = res - 1;



            set->count = static_cast<unsigned char>(newCount);



            volatile unsigned* destination =



                reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + newCount * 8);



            const unsigned* source = reinterpret_cast<const unsigned*>(reinterpret_cast<char*>(set) + 4 + res * 8);



            for (int words = (set->unk0 + set->unk1 - 1) >> 1; words >= 0; --words)



                *destination++ = *source++;



            reinterpret_cast<f3m_00a3a420::RecShim*>(&cache->points[index])->FUN_00a2b780(cache->points[3]);



            return 6;



        }



        ContactRecord* fresh = *(ContactRecord* volatile*)&point;



        fresh->id = id;



        reinterpret_cast<f3m_00a3a420::RecShim*>(&cache->points[index])->FUN_00a2b780(*fresh);



        replaced = index;



    }



    else



    {



        ContactRecord* appendPoint = *(ContactRecord* volatile*)&point;



        activeKey = *(S_00dad4d0_Key* volatile*)&key;



        if (defer && activeKey->numB != 3)



        {



            id = 0xffff;



        }



        else



        {



            id = manager->add(a, b, c, context, activeKey, appendPoint);



            if (id == 0xffff)



                return 5;



        }



        appendPoint->id = id;



        unsigned res = set->count;



        unsigned newCount = res + 1;



        int lastWord = (set->unk1 + set->unk0 - 1) >> 1;



        unsigned* destination = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + newCount * 8) + lastWord;



        unsigned* source = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + res * 8) + lastWord;



        for (; 0 <= lastWord; --lastWord)



            *destination-- = *source--;



        set->entries[res] = set->entries[0];



        set->count = static_cast<unsigned char>(newCount);



    }







    S_00dad4d0_Entry& entry = ContactEntry(set, 0);



    entry.numA = activeKey->numA;



    entry.numB = activeKey->numB;



    *reinterpret_cast<unsigned*>(entry.offs) = 0;



    _ReadWriteBarrier();



    *reinterpret_cast<unsigned short*>(&entry.unk2) = id;



    unsigned short* vertices = VertexIds(set);



    unsigned selected = 0;



    for (int i = 0; i < activeKey->numA; ++i)



    {



        unsigned index = 0;



        unsigned short vertex = activeKey->ids[i];



        while (index < set->unk0)



        {



            if (vertices[index] == vertex)



                goto foundA;



            ++index;



        }



        {



            unsigned end = set->unk0 + set->unk1;



            while (end > index)



            {



                vertices[end] = vertices[end - 1];



                --end;



            }



            vertices[index] = vertex;



            ++set->unk0;



            _ReadWriteBarrier();



            selected += 0x10;



        }



    foundA:



        entry.offs[i] = static_cast<unsigned char>(index << 4);



    }



    {



        if (selected)



        {



            S_00dad4d0_Entry* previous = &ContactEntry(set, 1);



            for (unsigned contact = 1; contact < set->count; ++contact, ++previous)



            {



                for (unsigned j = previous->numA; j < previous->numB + previous->numA; ++j)



                    previous->offs[j] += static_cast<unsigned char>(selected);



            }



        }



    }



    int i = 0;



    if (i < activeKey->numB)



    {



        do



        {



            unsigned short vertex = activeKey->ids[activeKey->numA + i];



            long index = set->unk0;



            int end;



            end = set->unk0 + set->unk1;



            while (index < end)



            {



                if (vertices[index] == vertex)



                    goto foundB;



                ++index;



            }



            vertices[index] = vertex;



            set->unk1++;



        foundB:



            entry.offs[activeKey->numA + i] = static_cast<unsigned char>(index << 4);



            ++i;



        } while (i < activeKey->numB);



    }



    return replaced;



}


// Compact the shared vertex table and re-encode every contact's offsets.
static __declspec(noinline) void __fastcall FUN_00dae220(int, ContactManifold* set)
{
    __declspec(align(16)) unsigned int usedWords[4];
    _mm_store_ps(reinterpret_cast<float*>(usedWords), _mm_setzero_ps());
    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);
    unsigned remap[16];
    unsigned contactCount = set->count;
    unsigned char* offs = ContactEntry(set, 0).offs;
    for (unsigned k = 0; k < contactCount; ++k)
    {
        int total = offs[-4] + offs[-3];
        used[offs[0] >> 4] = 1;
        used[offs[1] >> 4] = 1;
        if (total >= 3)
            used[offs[2] >> 4] = 1;
        if (total == 4)
            used[offs[3] >> 4] = 1;
        offs += 8;
    }
    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + contactCount * 8);
    int total = set->unk0 + set->unk1;
    unsigned count = 0;
    unsigned offset = 0;
    for (int i = 0; i < total; ++i)
    {
        remap[i] = offset;
        if (used[i])
        {
            vertices[count++] = vertices[i];
            offset += 16;
        }
    }
    unsigned countA = remap[set->unk0] >> 4;
    set->unk0 = static_cast<unsigned char>(countA);
    set->unk1 = static_cast<unsigned char>(count - countA);
    for (unsigned i = 0; i < set->count; ++i)
    {
        S_00dad4d0_Entry& entry = ContactEntry(set, i);
        entry.offs[0] = static_cast<unsigned char>(remap[entry.offs[0] >> 4]);
        entry.offs[1] = static_cast<unsigned char>(remap[entry.offs[1] >> 4]);
        entry.offs[2] = static_cast<unsigned char>(remap[entry.offs[2] >> 4]);
        entry.offs[3] = static_cast<unsigned char>(remap[entry.offs[3] >> 4]);
    }
}
