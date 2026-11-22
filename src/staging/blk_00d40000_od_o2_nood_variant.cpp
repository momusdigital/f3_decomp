#include "f3_common.h"
// src/staging/blk_00d40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct D51Allocator;
struct D51MemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D51Allocator* m_pThreadAllocator;
};
void* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

struct D51Vector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const D51Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

template <class T> __forceinline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct D51Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& t)
    {
        D51MemHolder* mem = (D51MemHolder*)FUN_00c85750();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(mem->m_pThreadAllocator, this, sizeof(T));
        }
        D51ConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

namespace fnv_00d52640 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
}

struct hkMemoryAllocator;

struct hkThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

extern "C" hkThreadMemory* FUN_00c85750();
void ResizeAudioStream(void* allocator, void* array, int elemSize);

struct hkVector4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& t)
    {
        hkMemoryAllocator& allocator = FUN_00c85750()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(&allocator, this, sizeof(T));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

}  // namespace fnv_00d52640

namespace fnv_00d56470 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" int _mm_movemask_ps(__m128 a);

extern const __m128 DAT_01017d10;
static const float DAT_01017d00 = 0.001f;

struct hkVector4D564
{
    __m128 m_vComponents;

    bool equals3(const hkVector4D564& v, float fEpsilon) const
    {
        const __m128 kDiff = _mm_and_ps(_mm_sub_ps(m_vComponents, v.m_vComponents), DAT_01017d10);
        const __m128 kEps = _mm_load_ps1(&fEpsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(kDiff, kEps)) & 7) == 7;
    }
};

}  // namespace fnv_00d56470

struct __declspec(align(16)) hkpAgent3FuncsD40
{
    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

struct Handle_d49550
{
    int m_v;
};
struct __declspec(align(16)) FUN_00c9ce00
{
    FUN_00c9ce00(Handle_d49550 kHandle);
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
};

struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4b1a0_Object
{
  public:
    S00d4b1a0_Object(FinishingFlag flag);  // FUN_00d4a170
    void* m_ppVirtualMethodTable;
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

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4b1a0
// pdb: hkpStorageMeshShape::staticClass | hkpStorageMeshShapeClass.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: getVtablehkpStorageMeshShape)
const void* __cdecl FUN_00d4b1a0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4b1a0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct W_00d49c40
{
    int x;
};

struct __declspec(align(16)) S_00d49c40
{
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

    void FUN_00d49c40(W_00d49c40 w);
};

// @fnv 0x00d4b200
// pdb: hkpStiffSpringChainData::hkpStiffSpringChainData | hkpStiffSpringChainData.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: getVtablehkpStiffSpringChainData)
// pdb params: f
int FUN_00d4b200()
{
    S_00d49c40 obj;
    obj.FUN_00d49c40(W_00d49c40());
    return obj.unk00;
}

struct W_d4a180
{
    int x;
};

struct __declspec(align(16)) SpawnedObject
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108;
    void FUN_00d4a180(W_d4a180 w);
};

// @fnv 0x00d4b260
int FUN_00d4b260()
{
    SpawnedObject obj;
    obj.FUN_00d4a180(W_d4a180());
    return obj.unk000;
}

struct ZeroD4B
{
    int v;
};

struct __declspec(align(16)) HolderD4B
{
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;

    void FUN_00d56f10(ZeroD4B arg);
};

namespace fnv_00d4be60 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4be60_Object
{
  public:
    S00d4be60_Object(FinishingFlag flag);  // FUN_00d4b3b0
    virtual void vf00();
    int m_kNextStreamField[19];
};

// @fnv 0x00d4be60
// pdb: hkpStorageExtendedMeshShape::MeshSubpartStorage::operator delete | hkpStorageExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: getVtablehkpStorageExtendedMeshShapeMeshSubpartStorage)
// pdb params: p
const void* __cdecl FUN_00d4be60()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4be60_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
}  // namespace fnv_00d4be60

namespace fnv_00d4bec0 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4bec0_Object
{
  public:
    S00d4bec0_Object(FinishingFlag flag);  // FUN_00d4ba30
    void* m_ppVirtualMethodTable;
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

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bec0
// pdb: getVtablehkpListShape | hkpCollideReflections.obj | tesv_win, objrun_prop, low
const void* __cdecl FUN_00d4bec0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bec0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bec0

namespace fnv_00d4bf40 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4bf40_Object
{
  public:
    S00d4bf40_Object(FinishingFlag flag);  // FUN_00dcd380
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bf40
// pdb: hkpMeshShape::staticClass | hkpMeshShapeClass.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low, conflict (skyrim: getVtablehkpMeshShape)
const void* __cdecl FUN_00d4bf40()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bf40_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bf40

namespace fnv_00d51890 {
struct HkRouterD51
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};
void* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* array, int elemSize);

struct HkVecD51
{
    __m128 m_vComponents;
    void operator=(const HkVecD51& o)
    {
        m_vComponents = o.m_vComponents;
    }
};

template <typename T> inline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct HkArrD51
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void AddBack(const T& t)
    {
        HkRouterD51* r = (HkRouterD51*)FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(r->m_pStreamAllocator, this, sizeof(T));
        D51ConstructWithCopy<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

}  // namespace fnv_00d51890

namespace fnv_00d51d40 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
struct HeapContext
{
    void* manager;
    void* archive;
    void* allocations;
    void* scratch;
    void* allocator;
};
HeapContext* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, unsigned int stride);
template <typename T> inline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
}  // namespace fnv_00d51d40

namespace fnv_00d52000 {
struct RouterD52
{
    int unk00, unk04, unk08, unk0c;
    void* m_pStreamAllocator;
};
RouterD52& FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
template <typename T> inline void D52ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct VecD52
{
    __m128 m_vComponents;
    VecD52& operator=(const VecD52& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};
template <typename T> struct ArrayD52
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void AddBack(const T& val)
    {
        RouterD52& router = FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        D52ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }
};
}  // namespace fnv_00d52000

extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);
static const float DAT_01011d78 = 0.0f;
struct D529E0_Heap;
struct D529E0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D529E0_Heap* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(D529E0_Heap* heap, void* array, int elementSize);
template <typename T> inline void D529E0_ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct D529E0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const T& value)
    {
        D529E0_Router* router = (D529E0_Router*)FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        D529E0_ConstructWithCopy<T>(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }
};

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}
struct __declspec(align(16)) Vec
{
    __m128 quad;
    __forceinline void copy(const Vec& other)
    {
        quad = other.quad;
    }
    __forceinline __m128 get() const
    {
        return quad;
    }
    __forceinline void set(__m128 result)
    {
        quad = result;
    }
    __forceinline void normalize()
    {
        __m128 vector = quad;
        __m128 squared = _mm_mul_ps(vector, vector);
        __m128 length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), length);
        __m128 estimate = _mm_rsqrt_ss(length);
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
        __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
        inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_set_ss(0.0f)), inverse);
        __m128 result = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);

        quad = result;
    }
    __forceinline void setCross(const Vec& l, const Vec& r)
    {
        __m128 left = l.quad, right = r.quad;
        quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
    }
    static __forceinline __m128 cross(__m128 left, __m128 right)
    {
        return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
    }
};

extern "C"
{
    double __cdecl fabs(double);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
}

struct Vector172
{
    union
    {
        __m128 quad;
        float element[4];
    };
};
struct Row172
{
    float x, y, z, w;
    void FUN_004b4ab0(int index, const Vector172* value);
};
struct Frame172
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Row172 row20, row30, row40, row50, row60, row70;
    void FUN_00d53060(int first, int second, const Vector172* direction);
};
static __forceinline float Absolute172(float value)
{
    volatile float result = static_cast<float>(fabs(static_cast<double>(value)));
    return result;
}
static __forceinline __m128 Normalize172(__m128 vector)
{
    __m128 squares = _mm_mul_ps(vector, vector);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    __m128 length2 = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), sum);
    __m128 estimate = _mm_rsqrt_ss(length2);
    __m128 error = _mm_mul_ss(_mm_mul_ss(length2, estimate), estimate);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), error);
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    __m128 zeroMask = _mm_cmpeq_ss(length2, _mm_set_ss(0.0f));
    inverse = _mm_andnot_ps(zeroMask, inverse);
    return _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);
}
// @f3 0x009e0a70 (community match, verified in this file)
#include <math.h>
__forceinline float Abs53(float v) { return (float)fabs((double)v); }
__forceinline float InvSqrt53(float v) { if(v!=0) return 1.0f/(float)sqrt(v); return 0.0f; }
struct RowCall172 { void FUN_00477880(int index,const Vector172* v); };
void Frame172::FUN_00d53060(int first,int second,const Vector172* direction)
{
    const float* d=direction->element;
    float ax=Absolute172(d[0]);
    float ay=Absolute172(d[1]);
    float az=Absolute172(d[2]);
    int smallerAxis=0;
    int firstAxis=smallerAxis+1;
    int secondAxis=smallerAxis+2;
    if(ay < ax) {
        ax=ay;
        firstAxis=0;
        smallerAxis=1;
    }
    if(az < ax)
        secondAxis=smallerAxis;
    Vector172 perpendicular;
    perpendicular.element[3]=0.0f;
    perpendicular.element[2]=0.0f;
    perpendicular.element[1]=0.0f;
    perpendicular.element[0]=0.0f;
    perpendicular.element[firstAxis]=d[secondAxis];
    perpendicular.element[secondAxis]=-d[firstAxis];
    float lengthSq = perpendicular.element[0]*perpendicular.element[0] +
                     perpendicular.element[1]*perpendicular.element[1] +
                     perpendicular.element[2]*perpendicular.element[2];
    float scale=InvSqrt53(lengthSq);
    for(int i=0;i<4;++i)
        perpendicular.element[i] *= scale;
    Vector172 cross;
    cross.element[0]=d[1]*perpendicular.element[2]-d[2]*perpendicular.element[1];
    cross.element[1]=d[2]*perpendicular.element[0]-d[0]*perpendicular.element[2];
    cross.element[2]=d[0]*perpendicular.element[1]-d[1]*perpendicular.element[0];
    cross.element[3]=0.0f;
    ((RowCall172*)&row20)->FUN_00477880(first,direction);
    ((RowCall172*)&row30)->FUN_00477880(first,&perpendicular);
    ((RowCall172*)&row40)->FUN_00477880(first,&cross);
    ((RowCall172*)&row50)->FUN_00477880(second,direction);
    ((RowCall172*)&row60)->FUN_00477880(second,&perpendicular);
    ((RowCall172*)&row70)->FUN_00477880(second,&cross);
}


namespace WorldLinearDof {

}
