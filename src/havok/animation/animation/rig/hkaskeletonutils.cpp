#include "f3_common.h"
// src/havok/animation/animation/rig/hkaskeletonutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaskeletonutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cdd3f0_s
{
    int a[6];
    int* field_0x18;
    int field_0x1c;
};

// @f3 0x00957b80 (community match, verified in this file)
// pdb: hkaSkeletonUtils::unlockTranslations | hkaSkeletonUtils.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: skeleton
void FUN_00cdd3f0(FUN_00cdd3f0_s* entries) {
    int count = entries->a[4];
    for (int index = 0; index < count; ++index)
        *((unsigned char*)(((int**)entries->a[3])[index]) + 4) = 0;
}


extern "C" void __cdecl FUN_00cddad0(int, int, int*, int, int);
extern int DAT_01268700;

// Calls FUN_00cddad0 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddcf0
// pdb: hkaSkeletonUtils::transformLocalPoseToModelPose | hkaSkeletonUtils.obj | fnv360_0822_debug, caller, medium
// pdb params: numTransforms, parentIndices, poseLocal, poseModelOut
void __cdecl CallWithGlobal(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00cddad0(aiArg1, aiArg2, &DAT_01268700, aiArg3, aiArg4);
}

extern "C" void __cdecl FUN_00cddd20(void* a, void* b, void* c, void* d, void* e);
extern int DAT_01268700;

// Calls FUN_00cddd20 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddef0
// pdb: hkaSkeletonUtils::transformModelPoseToLocalPose | hkaSkeletonUtils.obj | fnv360_0822_retail, call_gap + skyrim(objrun), high
void hkaSkeletonUtils_transformModelPoseToLocalPose(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00cddd20(apArg1, apArg2, &DAT_01268700, apArg3, apArg4);
}

int __cdecl hkString_strCasecmp(const void* pKey, const void* pItem);
struct S_00cdd390_Entry
{
    unsigned int m_uiTaggedItem;
    int unk04;
};
struct S_00cdd390_Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00cdd390_Entry* m_pEntries;
    int m_iArrayLength;
    int GetCount() const
    {
        return m_iArrayLength;
    }
    void* GetAt(int i) const
    {
        return (void*)(m_pEntries[i].m_uiTaggedItem & ~1u);
    }
};
// Searches the table's entries for one matching pKey via pfnCompare (default hkString_strCasecmp) and returns its index, or -1 if none match.
// @f3 0x00957b20 (community match, verified in this file)
struct FindTableLayout
{
    int unk00;
    int unk04;
    int unk08;
    void** m_ppEntries;
    int m_iArrayLength;
};

// pdb: hkaSkeletonUtils::findBoneWithName | hkaSkeletonUtils.obj | fnv360_0822_retail, call_seq, high
// pdb params: skeleton, name, compare
// pdb: hkaSkeletonUtils::findBoneWithName | hkaSkeletonUtils.obj | fnv360_0822_retail, call_seq, high (was: FindIndexByKey)
short __cdecl hkaSkeletonUtils_findBoneWithName(S_00cdd390_Table* pSearchEntries, const void* pKey, int(__cdecl* pfnCompare)(const void*, const void*))
{
    FindTableLayout* t = (FindTableLayout*)pSearchEntries;
    int iCount = t->m_iArrayLength;
    if (!pfnCompare)
        pfnCompare = hkString_strCasecmp;
    for (short i = 0; i < iCount; i++)
    {
        if (pfnCompare(pKey, *(const void* const*)t->m_ppEntries[i]) == 0)
            return i;
    }
    return -1;
}


template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
};

struct Sequence
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short* values;
    int count;
};
// Checks every value in sequence->values against limits->field_0x1c, writing true to result if all are in [0, limit) and false otherwise.
// @f3 0x00957bb0 (community match, verified in this file)
struct SequenceStub
{
    int unk00;
    short* values;
    int count;
};
struct LimitStub
{
    int unk00, unk04, unk08, unk0c;
    int limit;
};
// pdb: hkaSkeletonUtils::unlockTranslations | hkaSkeletonUtils.obj | fnv360_0822_debug, objrun_sim, low
// pdb params: skeleton
bool* __cdecl AreSequenceValuesInRange(bool* pbInRange, FUN_00cdd3f0_s* limits, Sequence* sequence)
{
    SequenceStub* seq = (SequenceStub*)sequence;
    LimitStub* range = (LimitStub*)limits;
    int i = 0;
    for (; i < seq->count; ++i)
    {
        short value = seq->values[i];
        if (value < 0 || value >= range->limit)
        {
            *pbInRange = false;
            return pbInRange;
        }
    }
    *pbInRange = true;
    return pbInRange;
}


struct Msg
{
    int f0, f4, f8;
    void Init(void* buf, int size);
    void Done();
    Msg& Add(const char* s);
    Msg& Add(const char* s, int v);
    Msg& Add();
    Msg& Fin();
};
struct Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int a, int code, void* msg, const char* file, int line);
};
struct Names
{
    int pad[6];
    unsigned int* names;
    int count;
};
struct Src
{
    int pad[4];
    int n;
    int p14;
    int p18;
    unsigned int* arr;
    int f20;
};
struct Dst
{
    int pad[4];
    short* out;
    int cnt;
};

typedef int(__cdecl* CmpFn)(unsigned int, unsigned int);

// Validates that the binding and track names are initialized, then maps each track to a bone index by comparing names and writes the indices to dst->out.
// @f3 0x00958060 (community match, verified in this file)
struct Names;
struct Src;
struct Dst;
struct TrackEntry
{
    unsigned int key;
};
struct NameEntry
{
    unsigned int key;
};
extern Logger* DAT_010f3364;

namespace f3m_00958060 {
struct NamesView958060
{
    int unk00;
    int unk04;
    int unk08;
    NameEntry** names;
    int count;
};
struct SrcView958060
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int n;
    int unk14;
    int unk18;
    TrackEntry** arr;
    int f20;
};
struct DstView958060
{
    int unk00;
    short* out;
    int cnt;
};
}

// pdb: hkaSkeletonUtils::bindByName | hkaSkeletonUtils.obj | fnv360_0822_retail, ustr, high
// pdb params: skeleton, anim, compare, bindingOut
// pdb: hkaSkeletonUtils::bindByName | hkaSkeletonUtils.obj | fnv360_0822_retail, ustr, high (was: MapTracksToBones)
int __cdecl hkaSkeletonUtils_bindByName(Names* namesIn, Src* srcIn, CmpFn cmp, Dst* dstIn)
{
    f3m_00958060::NamesView958060* names = reinterpret_cast<f3m_00958060::NamesView958060*>(namesIn);
    f3m_00958060::SrcView958060* src = reinterpret_cast<f3m_00958060::SrcView958060*>(srcIn);
    f3m_00958060::DstView958060* dst = reinterpret_cast<f3m_00958060::DstView958060*>(dstIn);
    if (dst->out == 0 || dst->cnt != src->n)
    {
        int buf[0x80];
        Msg m;
        m.Init(buf, 0x200);
        m.Add("Binding is not initiialized");
        DAT_010f3364->Report(3, 0x654e3435, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x16e);
        m.Done();
        return 1;
    }
    if (src->f20 != src->n)
    {
        int buf[0x80];
        Msg m;
        m.Init(buf, 0x200);
        m.Add("No track names present in animation");
        DAT_010f3364->Report(3, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x175);
        m.Done();
        return 1;
    }
    int cnt = names->count;
    int i;
    for (i = 0; i < cnt; i++)
    {
        if (names->names[i]->key == 0)
        {
            int buf[0x80];
            Msg m;
            m.Init(buf, 0x200);
            m.Add("No bone name for bone ", i).Fin();
            DAT_010f3364->Report(3, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x17f);
            m.Done();
            return 1;
        }
    }
    for (int t = 0; t < src->n; t++)
    {
        bool found = false;
        unsigned int key = src->arr[t]->key;
        short j = 0;
        for (j = 0; j < names->count; j++)
        {
            unsigned int uiBoneName = names->names[j]->key;
            if (cmp(uiBoneName, key) == 0)
            {
                found = true;
                dst->out[t] = j;
            }
        }
        if (!found)
        {
            int buf[0x80];
            Msg m;
            m.Init(buf, 0x200);
            m.Add("No match for track ", (int)key).Add();
            DAT_010f3364->Report(3, 0x654e3438, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x195);
            m.Done();
            return 1;
        }
    }
    return 0;
}


struct HolderRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};

struct ScanRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};

struct ScanObj
{
    void FUN_00cde940(int a, int b, void* c);
};

HolderRec* FUN_00c85750();

// @f3 0x00959290 (community match, verified in this file)
struct ScanRec_Local
{
    int unk00;
    unsigned short* m_04;
};

struct FUN_00d27f50_Obj
{
    void FUN_00d27f50(int a, int b);
};

// pdb: hkaSkeletonUtils::getBoneChain | hkaSkeletonUtils.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkLifoAllocator::allocateFromNewSlab)
// pdb params: skeleton, startBone, endBone, bonesInOut
unsigned char* WalkChainUntilLimit(unsigned char* pabResult, ScanRec* rec, short asLimit, short asStart, ScanObj* obj)
{
    int s = (unsigned short)asStart;
    int current=s;
    if (asStart > 0)
    {
        ScanRec_Local* r = (ScanRec_Local*)rec;
        FUN_00d27f50_Obj* o = (FUN_00d27f50_Obj*)obj;
        struct LimitValue { short value; };
        LimitValue limit={asLimit};
        do
        {
            if ((short)s == limit.value)
                break;
            o->FUN_00d27f50(0, (int)&current);
            s = r->m_04[(short)s];
            current=s;
        } while ((short)s > 0);
    }
    ((FUN_00d27f50_Obj*)obj)->FUN_00d27f50(0, (int)&asLimit);
    *pabResult = ((short)s >= 0);
    return pabResult;
}


namespace fnv_00cde450 {
struct S_00cde450_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};

struct S_00cde450_Router
{
    char* m_fMinimumV;
    int unk04;
    int unk08;
    int unk0c;
    S_00cde450_Heap* m_pStreamAllocator;
    S_00cde450_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cde450_Router* __cdecl FUN_00c85750();

struct S_00cde450_ByteArr;
struct S_00cde450_UShortArr;
void __cdecl ResizeAudioStream(S_00cde450_Heap& h, S_00cde450_UShortArr* a, int elemSize);

struct S_00cde450_UShortArr
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_cap;

    void AddBack(unsigned short v)
    {
        S_00cde450_Heap& h = FUN_00c85750()->heap();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(h, this, 2);
        unsigned short* p = m_data + m_iElementCount;
        for (int k = 0; k < 1; k++)
            p[k] = v;
        m_iElementCount++;
    }
};

struct S_00cde450_ByteArr
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;
};

}  // namespace fnv_00cde450

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
struct __declspec(align(16)) V4
{
    __m128 q;
};

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern const __m128 DAT_010c71e0;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4& b) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    __forceinline void setMul4(__m128 r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(r, v.m_vComponents);
    }
    __forceinline void addMul4(__m128 r, const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r, v.m_vComponents));
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void SetRotatedDirection(const hkVector4& quat, const hkVector4& direction)
    {
        const hkVector4& imag = quat;
        const __m128 qreal = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
        const __m128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0);
        hkVector4 ret;
        ret.setMul4(q2minus1, direction);
        const __m128 imagDotDir = imag.dot3(direction);
        ret.addMul4(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), imag);
        hkVector4 imagCrossDir;
        imagCrossDir.setCross(imag, direction);
        ret.addMul4(qreal, imagCrossDir);
        setAdd4(ret, ret);
    }
    __forceinline void SetTransformedPoint(const struct hkQsTransform& t, const hkVector4& v);
    __forceinline hkVector4& operator=(const hkVector4& o)
    {
        m_vComponents = o.m_vComponents;
        return *this;
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkVector4 m_rotation;
    hkVector4 m_vScale;
};

__forceinline void hkVector4::SetTransformedPoint(const hkQsTransform& t, const hkVector4& v)
{
    SetRotatedDirection(t.m_rotation, v);
    add4(t.m_vTranslation);
}

typedef short hkInt16;

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" const __m128 DAT_010c44d0;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern char DAT_010cb7dc[];
extern char DAT_010c41f8[];

struct TimerEntry
{
    const char* tag;
    unsigned int stamp;
    unsigned int unk08;
};
struct Monitor
{
    int unk00;
    TimerEntry* current;
    int unk08;
    TimerEntry* end;
};
static __forceinline void timer(const char* tag)
{
    Monitor* monitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
    TimerEntry* entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->tag = tag;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        entry->stamp = stamp;
        monitor->current = entry + 1;
    }
}

struct HkObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin();
};
struct HkEntity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int owner;
};
struct HkWorld
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual HkEntity* GetEntity();
};
struct Vec4
{
    float x;
    float y;
    float z;
    float w;
};
union __declspec(align(16)) VectorValue
{
    Vec4 scalar;
    __m128 quad;
};
struct Allocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int);
};
struct AllocationService
{
    int unk00, unk04, unk08, unk0c;
    Allocator* volatile allocator;
};
struct Property
{
    unsigned short type, unk02;
    int unk04, unk08, unk0c;
    unsigned short size, unk12;
    int unk14, unk18, unk1c;
    __m128 vector;
    static void* operator new(unsigned int bytes)
    {
        AllocationService* service = reinterpret_cast<AllocationService*>(FUN_00c85750());
        return service->allocator->Allocate(bytes);
    }
    Property()
    {
        type = 0x1a;
        size = 0x30;
    }
};
extern "C" Property* __cdecl hkpWorldConstraintUtil_findModifier(HkEntity*, int);
extern "C" void __cdecl FUN_00d27960(HkEntity*, HkObj*, Property*);

// Stores a Vec4 into a Property's vector field on an HkEntity, XORing it with DAT_010c44d0 when the entity's owner matches the given owner.
// @f3 0x0095abd0 (community match, verified in this file)
extern unsigned long DAT_010f3170;

namespace smc_abd0 {

// Four-float vector as this game's physics library has it here: plain floats, 16-byte aligned.
struct __declspec(align(16)) Vector4
{
    float x;
    float y;
    float z;
    float w;
    Vector4& operator=(const Vector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    void setNeg4(const Vector4& v)
    {
        x = -v.x;
        y = -v.y;
        z = -v.z;
        w = -v.w;
    }
};

struct ThreadMemory
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    void* freeList58;
    int freeCount5c;
    void* FUN_008f6800(int row, int memoryClass);
};

struct ModifierAtom
{
    unsigned short type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short size;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    Vector4 vector;

    static void* operator new(unsigned int)
    {
        ThreadMemory* memory = static_cast<ThreadMemory*>(TlsGetValue(DAT_010f3170));
        void* result = memory->freeList58;
        if (result)
        {
            --memory->freeCount5c;
            memory->freeList58 = *static_cast<void**>(result);
            return result;
        }
        return memory->FUN_008f6800(4, 0x2c);
    }
    ModifierAtom()
    {
        type = 0x1a;
        size = 0x30;
    }
};

}  // namespace smc_abd0

// pdb: hkpResponseModifier::setSurfaceVelocity | hkpResponseModifier.obj | fnv360_0822_retail, ustr, high
// pdb params: manager, body, constraintOwner, velWorld
// pdb: hkpResponseModifier::setSurfaceVelocity | hkpResponseModifier.obj | fnv360_0822_retail, ustr, high (was: SetModifierConstraint)
void hkpResponseModifier_setSurfaceVelocity(HkWorld* apWorld, int owner, HkObj* apObj, Vec4* apVec)
{
    using namespace smc_abd0;
    HkEntity* e = apWorld->GetEntity();
    if (e)
    {
        apObj->Begin();
        timer(DAT_010cb7dc);
        Vector4 t = *reinterpret_cast<const Vector4*>(apVec);
        if (e->owner == owner)
        {
            t.setNeg4(t);
        }
        ModifierAtom* p = reinterpret_cast<ModifierAtom*>(hkpWorldConstraintUtil_findModifier(e, 0x1a));
        if (p)
        {
            p->vector = t;
        }
        else
        {
            p = new ModifierAtom;
            p->vector = t;
            FUN_00d27960(e, apObj, reinterpret_cast<Property*>(p));
        }
        timer(DAT_010c41f8);
    }
}


extern __m128 DAT_010c7170;

struct S_00cdd600_Out
{
    __m128* p;
    __m128* val() const
    {
        return p;
    }
};

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_rsqrt_ps(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    void _ReadWriteBarrier(void);
}

struct Simd
{
    __m128 m;
    __forceinline float getReal() const
    {
        float f;
        _mm_store_ss(&f, m);
        return f;
    }
};
struct Vec
{
    __m128 m;
    __forceinline Simd lengthSquared() const
    {
        __m128 d = _mm_mul_ps(m, m);
        __m128 s = _mm_add_ps(d, _mm_shuffle_ps(d, d, 0x4e));
        Simd r;
        r.m = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
        return r;
    }
    __forceinline void mul(const Simd& factor)
    {
        m = _mm_mul_ps(_mm_shuffle_ps(factor.m, factor.m, 0), m);
    }
    __forceinline void SetProduct(const Simd& factor, const Vec& v)
    {
        m = _mm_mul_ps(factor.m, v.m);
    }
};

extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

extern "C"
{
    extern const unsigned int DAT_010c4c00[4];
    extern const unsigned int DAT_010c4c10[4];
}

class SReal
{
  public:
    SReal()
    {}
    SReal(const __m128& x) : m_vValue(x)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

__forceinline __m128 approxReciprocal(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

struct QRot;

class QVec
{
  public:
    QVec()
    {}
    QVec(const __m128& q)
    {
        m_vComponents = q;
    }
    QVec(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        getQuad() = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    __m128& getQuad()
    {
        return m_vComponents;
    }
    const __m128& getQuad() const
    {
        return m_vComponents;
    }

    __forceinline void setAdd4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const QVec& a, const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const SReal& r, const QVec& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void sub4(const QVec& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void SetAllComponents(const SReal& r)
    {
        m_vComponents = _mm_shuffle_ps(r.getQuad(), r.getQuad(), 0x00);
    }
    __forceinline SReal lane(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setNeg4(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setNeg3(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, *(const __m128*)&DAT_010c4c00);
    }
    __forceinline void setXYZ0(const QVec& xyz)
    {
        m_vComponents = _mm_and_ps(xyz, *(const __m128*)&DAT_010c4c10);
    }
    __forceinline void setXYZW(const QVec& xyz, const QVec& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const QVec& v)
    {
        m_vComponents = approxReciprocal(v.m_vComponents);
    }
    __forceinline void setReciprocal3(const QVec& v)
    {
        QVec ones;
        ones.getQuad() = DAT_010c7170;
        QVec padded;
        padded.setXYZW(v, ones);
        setReciprocal4(padded);
    }
    __forceinline void setCross(const QVec& a, const QVec& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline SReal dot3(const QVec& a) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline void splat(int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void setSplat(const QVec& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    void rotate(const QRot& q, const QVec& d);
    void rotateInverse(const QRot& q, const QVec& d);

  private:
    __m128 m_vComponents;
};

struct QRot
{
    QVec m_vec;
    __forceinline const QVec& imag() const
    {
        return m_vec;
    }
    __forceinline void SetConjugate(const QRot& q)
    {
        m_vec.setNeg3(q.imag());
    }
    inline void SetProduct(const QRot& a, const QRot& b);
};

inline void QRot::SetProduct(const QRot& a, const QRot& b)
{
    QVec v;
    v.setCross(a.imag(), b.imag());
    v.addMul4(a.m_vec.lane(3), b.imag());
    v.addMul4(b.m_vec.lane(3), a.imag());
    QVec d;
    d.SetAllComponents(a.m_vec.dot3(b.m_vec));
    QVec w;
    w.setMul4(a.m_vec, b.m_vec);
    w.sub4(d);
    m_vec.setXYZW(v, w);
}

__forceinline void QVec::rotate(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(q.imag(), d);
    out.addMul4(w, cr);
    setAdd4(out, out);
}

__forceinline void QVec::rotateInverse(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(d, q.imag());
    out.addMul4(w, cr);
    setAdd4(out, out);
}

struct QsXform
{
    QVec m_vTranslation;
    QRot m_rotation;
    QVec m_vScale;

    QsXform()
    {}

    __forceinline void SetConjugate(const QsXform& t)
    {
        m_vTranslation.rotateInverse(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        QVec inv;
        inv.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(inv);
    }

    __forceinline void SetProduct(const QsXform& ab, const QsXform& bc)
    {
        QVec moved;
        moved.rotate(ab.m_rotation, bc.m_vTranslation);
        m_vTranslation.setAdd4(ab.m_vTranslation, moved);
        m_rotation.SetProduct(ab.m_rotation, bc.m_rotation);
        m_vScale.setMul4(ab.m_vScale, bc.m_vScale);
    }

    __forceinline void SetMulInverse(const QsXform& a, const QsXform& b)
    {
        QsXform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};

__forceinline void toLocal(int count, const short* parents, const QsXform& root, const QsXform* world,
                           QsXform* localOut)
{
    for (int i = 0; i < count; i++)
    {
        const int p = parents[i];
        const QsXform& parentWorld = (p != -1) ? world[p] : root;
        localOut[i].SetMulInverse(parentWorld, world[i]);
    }
}

// Converts world-space QsXform transforms to local-space by calling toLocal with the given count, parents, root, world, and localOut arguments.
// @fnv 0x00cddd20
extern "C" void __cdecl FUN_00cddd20(void* aiCount, void* apParents, void* apRoot, void* apWorld, void* apLocalOut)
{
    toLocal((int)aiCount, (const short*)apParents, *(const QsXform*)apRoot, (const QsXform*)apWorld,
            (QsXform*)apLocalOut);
}
