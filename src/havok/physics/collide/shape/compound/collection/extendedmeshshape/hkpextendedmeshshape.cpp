#include "f3_common.h"
// src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator;

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

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct hkShortArray
{
    short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserveExactly(int n)
    {
        AudioMgr* m = audio();
        if (getCapacity() < n)
            FUN_00c908c0(m->heap(), this, n, sizeof(short));
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(short));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct S_00d56880_Alloc
{
};
struct S_00d56880_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00d56880_Alloc* m_pStreamAllocator;
    static S_00d56880_Router& FUN_00c85750();
    S_00d56880_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(S_00d56880_Alloc& a, void* arr, int n, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00d56880_Elem
{
    unsigned char unk0;
    unsigned char unk1;
    short unk2;
    int unk4;
    short unk8;
    short unka;
    int unkc;
    int unk10;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d56880_Elem()
    {
        unk8 = 0;
        unk2 = 0;
        unka = 1;
        unk0 = 1;
        unk1 = 1;
        unkc = 0;
        unk4 = 0;
        unk10 = 0;
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct S_00d56880_Array
{
    S_00d56880_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00d56880_Alloc& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(a, this, newSize, sizeof(S_00d56880_Elem));
        }
    }
    __forceinline S_00d56880_Elem* expandBy(int n)
    {
        S_00d56880_Alloc& a = S_00d56880_Router::FUN_00c85750().heap();
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        S_00d56880_Elem* p = m_data + m_iElementCount;
        for (int i = 0; i < n; i++)
            new (p + i) S_00d56880_Elem();
        m_iElementCount += n;
        return m_data + oldsize;
    }
};

struct Child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a1, int a2);
};

struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Child** m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_3c;
};

struct FUN_00d55a90_cls
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
    Group* m_0c0;
    int m_0c4;

    int __thiscall FUN_00d55a90(int a1, int a2);
};

// @f3 0x009e3420 (community match, verified in this file)
struct ChildF3
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a, int b);
};
struct GroupF3
{
    int unk00, unk04, unk08, unk0C;
    ChildF3** m_ppChildren;
    int m_iChildCount;
    unsigned char m_bA;
    unsigned char m_bB;
};
struct OwnerD55AF3
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
    GroupF3* m_pGroups;
    int m_iGroupCount;
};
// pdb: hkArrayBase<unsigned short>::copyFromArray | hkpExtendedMeshShape.obj | fnv360_0822_debug, objrun_open, low
// pdb params: alloc, a, __formal
int FUN_00d55a90_cls::FUN_00d55a90(int a1, int a2)
{
    OwnerD55AF3* self = (OwnerD55AF3*)this;
    int i = 0;
    if (self->m_iGroupCount > 0)
    {
        volatile int off = 0;
        do
        {
            GroupF3* pGroup = self->m_pGroups;
            pGroup = (GroupF3*)((char*)pGroup + off);
            for (int iChildIndex = 0; iChildIndex < pGroup->m_iChildCount; ++iChildIndex)
            {
                int r = pGroup->m_ppChildren[iChildIndex]->v18(a1, 0x100);
                int limit;
                if (pGroup->m_bA == 0 && pGroup->m_bB == 0)
                    limit = 0x200;
                else if (pGroup->m_bB == 0 && pGroup->m_bA != 0)
                    limit = 0x1d0;
                else
                    limit = 0x1a0;
                if (r < 0 || r > limit)
                    return -1;
            }
            ++i;
            off += 0x40;
        } while (i < self->m_iGroupCount);
    }
    return 0xc0;
}


struct __declspec(align(16)) S_00d55bd0_Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00d55bd0_Bool
{
    char m_cBooleanValue;
    S_00d55bd0_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00d55bd0_Shape
{
    int unk0;
    int unk4;
    int unk8;
    int m_type;
};

struct S_00d55bd0_TriangleShape : S_00d55bd0_Shape
{
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d55bd0_Vector4 m_kVertexA;
    S_00d55bd0_Vector4 m_kVertexB;
    S_00d55bd0_Vector4 m_kVertexC;
};

S_00d55bd0_Bool IsDegenerateTriangle(const S_00d55bd0_Vector4& a, const S_00d55bd0_Vector4& b,
                                     const S_00d55bd0_Vector4& c, float tolerance);

struct S_00d55bd0_TrianglesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int m_iTriangleCount;
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
};

struct S_00d55bd0_ShapesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int m_iChildShapeCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

static const float DAT_011b2e90 = 1e-07f;

struct S_00d55bd0_MeshShape
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk4;
    int unk8;
    int unkc;
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
    int m_iNumBitsForSubpartIndex;
    S_00d55bd0_TrianglesSubpart* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    int unkac;
    S_00d55bd0_ShapesSubpart* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;

    unsigned int hkpExtendedMeshShape_getNextKey(unsigned int initialKey) const;
};

// @f3 0x009e3d00 (community match, verified in this file)
struct TriSubpartF3
{
    int unk00, unk04, unk08, unk0C;
    int m_iTriangleCount;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};
struct ShapeSubpartF3
{
    int unk00, unk04, unk08, unk0C, unk10;
    int m_iChildShapeCount;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};
struct MeshShapeF3
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk04;
    int m_iNumBitsForSubpartIndex;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    TriSubpartF3* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    ShapeSubpartF3* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;
};
// pdb: hkpExtendedMeshShape::getNextKey | hkpExtendedMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb params: initialKey
// pdb: hkpExtendedMeshShape::getNextKey | hkpExtendedMeshShape.obj | fnv360_0822_retail, bridge_fnvpc, high (was: FindNextNonDegenerateShapeKey)
unsigned int S_00d55bd0_MeshShape::hkpExtendedMeshShape_getNextKey(unsigned int initialKey) const
{
    const MeshShapeF3* self = (const MeshShapeF3*)this;
    // hkpShapeBuffer (512 bytes, 16-aligned); non-char element type, see brief
    __declspec(align(16)) unsigned int buffer[128];

    unsigned int subpartIndex = (initialKey & 0x7fffffff) >> (32 - self->m_iNumBitsForSubpartIndex);
    int terminalIndex = initialKey & (~0U >> self->m_iNumBitsForSubpartIndex);
    unsigned int subpartType = initialKey & 0x80000000;

    while (1)
    {
        if (subpartType == 0)
        {
            if (++terminalIndex >= self->m_kTrianglesSubparts[subpartIndex].m_iTriangleCount)
            {
                subpartIndex++;
                terminalIndex = 0;
                if (subpartIndex >= self->m_numTrianglesSubparts)
                {
                    if (self->m_numShapesSubparts == 0)
                    {
                        return 0xffffffff;
                    }
                    subpartIndex = 0;
                    subpartType = 0x80000000;
                    terminalIndex = -1;
                    continue;
                }
            }
        }
        else
        {
            if (++terminalIndex >= self->m_kShapesSubparts[subpartIndex].m_iChildShapeCount)
            {
                subpartIndex++;
                if (subpartIndex >= self->m_numShapesSubparts)
                {
                    return 0xffffffff;
                }
                terminalIndex = 0;
            }
        }

        unsigned int key = (subpartIndex << (32 - self->m_iNumBitsForSubpartIndex)) | subpartType | terminalIndex;
        const S_00d55bd0_Shape* shape = self->GetShapeForKey(key, buffer);
        if (shape->m_type == 4)
        {
            const S_00d55bd0_TriangleShape* pTriangle = static_cast<const S_00d55bd0_TriangleShape*>(shape);
            if (IsDegenerateTriangle(pTriangle->m_kVertexA, pTriangle->m_kVertexB, pTriangle->m_kVertexC, DAT_011b2e90))
            {
                continue;
            }
        }
        return key;
    }
}


namespace fnv_00d56160 {
__declspec(align(16)) struct FUN_00d56160_vec
{
    float x;
    float y;
    float z;
    float w;
};

__declspec(align(16)) struct FUN_00d56160_out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d56160_vec m_20;
    FUN_00d56160_vec m_30;
    FUN_00d56160_vec m_40;
};

extern float DAT_011b2e90;
unsigned char* __cdecl IsDegenerateTriangle(unsigned char* out, FUN_00d56160_vec* a, FUN_00d56160_vec* b,
                                            FUN_00d56160_vec* c, float r);

}  // namespace fnv_00d56160

struct BufferAllocator
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Release(void* data, unsigned bytes);
};
struct BSAudio
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    BufferAllocator* allocator;
};
BSAudio* FUN_00c85750();

namespace fnv_00d56e00 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

BSAudio* FUN_00c85750();

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void destroyAndDeallocate()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        int n = m_iElementCount;
        T* p = m_data;
        for (int i = 0; i < n; i++)
        {
            p[i].FUN_00d56800();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

}  // namespace fnv_00d56e00

struct FUN_00d55b40_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20[4];
    float unk30[4];
    float unk40[4];
};

struct __declspec(align(16)) FUN_00d55b40_Buffer
{
    int v[128];
};

extern char* __cdecl IsDegenerateTriangle(char* result, const void* v0, const void* v1, const void* v2, float tol);

struct bhkShapeOwner
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual int v3(int);
    virtual void* v4();
    virtual void* v5(int, void*);
    struct
    {
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
    } unk04;
    int unk_a8;
    int unk_ac;
    int unk_b0;
    int unk_b4;
    int hkpExtendedMeshShape_getFirstKey();
};

// @f3 0x009e3c70 (community match, verified in this file)
extern "C" char* __cdecl FUN_00a564b0(char* result, const void* v0, const void* v1, const void* v2, float tol);
// pdb: hkpExtendedMeshShape::getFirstKey | hkpExtendedMeshShape.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, high
// pdb: hkpExtendedMeshShape::getFirstKey | hkpExtendedMeshShape.obj | fnv360_0822_retail, bridge_fnvpc, high (was: GetShapeKey)
int bhkShapeOwner::hkpExtendedMeshShape_getFirstKey()
{
    FUN_00d55b40_Shape* shape;
    FUN_00d55b40_Buffer buffer;
    char degenerate;
    unsigned int key;

    if (this->unk04.unk44 + this->unk04.unk4c == 0)
        return -1;

    key = (this->unk04.unk44 != 0) ? 0u : 0x80000000u;

    shape = (FUN_00d55b40_Shape*)this->v5((int)key, &buffer);

    if (shape->unk0c != 4)
        return (int)key;

    char* result = FUN_00a564b0(&degenerate, &shape->unk20[0], &shape->unk30[0], &shape->unk40[0], 1.0e-7f);

    if (*result == 0)
        return (int)key;

    return this->v3((int)key);
}


// @fnv 0x00d554e0
// pdb: hkpNullBroadPhaseListener::addCollisionPair | hkpNullBroadPhaseListener.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void __stdcall hkpNullBroadPhaseListener_addCollisionPair(int a)
{}

// @fnv 0x00d554f0
void __stdcall FUN_00d554f0(int a0)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D562
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct ElemD562
{
    unsigned char m_b0;
    unsigned char m_b1;
    short m_s2;
    int m_i4;
    short m_s8;
    short m_sA;
    int m_iC;
    int m_i10;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkVector4D562 m_kVec;
    int unk40, unk44;
    unsigned char unk48;
    unsigned char m_b49;
    short unk4A;
    int unk4C;
    int m_i50;
    int unk54, unk58, unk5C;

    ElemD562()
    {
        m_s8 = 0;
        m_s2 = 0;
        m_b0 = 0;
        m_b1 = 1;
        m_sA = 1;
        m_iC = 0;
        m_i4 = 0;
        m_i10 = 0;
        m_b49 = 0;
        m_kVec.setZero4();
        m_i50 = 0;
    }
};

struct ArrayD562
{
    ElemD562* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(ElemD562));
        }
    }
    __forceinline ElemD562& AllocatePair()
    {
        hkMemoryAllocator& alloc = audio()->heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + 1);
        new (m_data + m_iElementCount) ElemD562();
        m_iElementCount += 1;
        return m_data[oldSize];
    }
};

namespace fnv_00d569c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_set_ps1(float fA);
extern "C" __m128 _mm_setzero_ps();

struct hkVector4D569
{
    __m128 m_vComponents;

    hkVector4D569()
    {}
    hkVector4D569(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void SetAllComponents(float fA)
    {
        m_vComponents = _mm_set_ps1(fA);
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

template <class T> struct hkArrayD569
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD569() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectD569
{
  public:
    virtual ~hkBaseObjectD569() throw();
};

class hkReferencedObjectD569 : public hkBaseObjectD569
{
  public:
    virtual ~hkReferencedObjectD569() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD569 : public hkReferencedObjectD569
{
  public:
    virtual ~hkpShapeD569() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD569
{
  public:
    virtual ~hkpShapeContainerD569() throw();
};

class FUN_00d21410 : public hkpShapeD569, public hkpShapeContainerD569
{
  public:
    FUN_00d21410(unsigned int uiType, unsigned char ucCollectionType) throw();
    virtual ~FUN_00d21410() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpExtendedMeshShapeTrianglesSubpartD569
{
    hkpExtendedMeshShapeTrianglesSubpartD569()
    {
        m_type = 0;
        m_materialIndexStridingPad = 0;
        m_pVertexBase = 0;
        m_pIndexBase = 0;
        m_bFlipAlternateTriangles = 0;
        m_iTriangleOffset = 0;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_kVertexTransform.setZero4();
    }

    unsigned char m_type;
    unsigned char m_iMaterialIndexType;
    unsigned short m_iIndexStriding;
    const void* m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    const void* m_materialIndexStridingPad;
    const void* m_pIndexBase;
    unsigned int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    hkVector4D569 m_kVertexTransform;
    unsigned int unk60, unk64;
    unsigned char unk68;
    unsigned char m_bFlipAlternateTriangles;
    unsigned short unk6A;
    unsigned int unk6C;
    int m_iTriangleOffset;
    unsigned int unk74, unk78, unk7C;
};

static const float DAT_0104e148 = -3.40282e+38f;

}  // namespace fnv_00d569c0

extern "C" void _ReadWriteBarrier(void);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern __m128 DAT_010c44d0;

struct hkVec4
{
    __m128 m_vComponents;
    void setMin4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};
struct hkAabbS
{
    hkVec4 m_kMinimumCorner;
    hkVec4 m_kMaximumCorner;
};
struct hkQuatS
{
    hkVec4 m_vec;
};
struct hkTransformS
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
    void FUN_00cb2d90(const hkQuatS& q);
};
struct hkShapeS
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransformS& t, float tolerance, hkAabbS& out) const;
};
struct ShapeHolderS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkShapeS** m_shapes;
    int m_numShapes;
    int unk1C;
    hkQuatS m_rotation;
    hkVec4 m_vTranslation;
};

ShapeHolderS* volatile g_src;
hkAabbS* volatile g_out;

extern "C"
{
    __m128 _mm_set_ps1(float a);
    __m128 _mm_setr_ps(float a, float b, float c, float d);
    __m128 _mm_xor_ps(__m128 a, __m128 b);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
}

typedef float hkReal;

extern __m128 DAT_010c44d0;

struct hkTransformq;

struct __declspec(align(16)) hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
    void FUN_00c7f640(const hkTransformq& t, const hkVector4q& v);
};

struct VertexScratch
{
    __m128 q;
    __forceinline float& at(int i)
    {
        return ((float*)&q)[i];
    }
    __forceinline void load(const float* p)
    {
        at(0) = p[0];
        at(1) = p[1];
        at(2) = p[2];
    }
};
extern "C" void _ReadWriteBarrier(void);
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_and_ps(__m128, __m128);
}

extern int DAT_010c749c;

struct TriangleShape
{
    int vtable;                             // 0x00
    short unk04;                            // 0x04
    short m_iObjectReferenceCount;          // 0x06
    int m_ulUserData;                       // 0x08
    int m_type;                             // 0x0c
    float m_fSphereRadius;                  // 0x10
    short m_kWeldingInfo;                   // 0x14
    char m_eWeldingType;                    // 0x16
    char m_ucWeldingPadding;                // 0x17
    int unk18;                              // 0x18
    int unk1c;                              // 0x1c
    S_00d55bd0_Vector4 m_kVertexA;          // 0x20
    S_00d55bd0_Vector4 m_kVertexB;          // 0x30
    S_00d55bd0_Vector4 m_kVertexC;          // 0x40
    S_00d55bd0_Vector4 m_kVertexTransform;  // 0x50

    __forceinline void setVertices(const __m128* vertices)
    {
        *(__m128*)&m_kVertexA = vertices[0];
        *(__m128*)&m_kVertexB = vertices[1];
        *(__m128*)&m_kVertexC = vertices[2];
    }

    __forceinline TriangleShape(float radius)
    {
        m_iObjectReferenceCount = 1;
        m_fSphereRadius = radius;
        m_ulUserData = 0;
        m_type = 3;
        vtable = (int)&DAT_010c749c;
        m_kWeldingInfo = 0;
        m_eWeldingType = 6;
        *(__m128*)&m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

namespace fnv_00d56200 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

AudioHolder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* a, void* b, int c, int d);

// FUN_00d56200 wrapper for the pack
}  // namespace fnv_00d56200

struct ChanEntry
{
    unsigned char unk00;
    unsigned char type;
    short scale;
    unsigned char* data;
    unsigned short stride;
    short unk0A;
    unsigned char* base;
    unsigned char* get(unsigned int off)
    {
        unsigned char* pData = data;
        unsigned char* pBase = base;
        int iScale = scale;
        if (pData)
        {
            unsigned char* p = pData + stride * off;
            if (type == 1)
                return pBase + *p * iScale;
            return pBase + *(unsigned short*)p * iScale;
        }
        return 0;
    }
};

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

struct __declspec(align(16)) Vec4Q
{
    float x, y, z, w;
    void __thiscall FUN_00c7f640(const void* transform, const Vec4Q* point);
};

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_min_ps(__m128, __m128);
struct hkVector4D563
{

    __m128 m_vComponents;

    hkVector4D563()
    {}

    hkVector4D563(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void operator=(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }

    void setAdd4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }

    void setSub4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    void add4(const hkVector4D563& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }

    void sub4(const hkVector4D563& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }

    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }

    void setMin4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }

    void setMax4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkAabbD563
{

    hkVector4D563 m_kMinimumCorner;

    hkVector4D563 m_kMaximumCorner;

    void includeAabb(const hkAabbD563& other)
    {

        m_kMinimumCorner.setMin4(m_kMinimumCorner, other.m_kMinimumCorner);

        m_kMaximumCorner.setMax4(m_kMaximumCorner, other.m_kMaximumCorner);
    }
};

extern "C"
{
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
}

typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;

struct hkConvexShapeS
{
    void RetainReference() const;
    void removeReference() const;
};

template <class T> struct hkRefPtrS
{
    T* m_pRetainedObject;

    __forceinline hkRefPtrS() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(T* e)
    {
        if (e)
        {
            e->RetainReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
};

template <typename T> struct hkArrS
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            new (p + i) T;
        }
    }

    __forceinline T* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        construct(m_data + m_iElementCount, n);
        m_iElementCount += n;
        return m_data + oldsize;
    }

    __forceinline T* expandBy(int n)
    {
        return _expandBy(audio()->heap(), n);
    }
};

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternionS
{
    __m128 m_vec;
    void FUN_00cb26e0(const void* rotation);
};

struct hkBoolS
{
    char m_cBooleanValue;
    hkBoolS(bool b) : m_cBooleanValue(b)
    {}
};

struct hkTransformD566
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;

    hkBoolS FUN_00cd4e00(const hkTransformD566& other, hkReal epsilon) const;
};

struct hkVector4CompS
{
    __m128 m_uiMask;
    __forceinline bool allAreSetXYZ() const
    {
        return (_mm_movemask_ps(m_uiMask) & 7) == 7;
    }
};

struct ShapesSubpartT
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    unsigned int m_ulUserData;
    hkArrS<hkRefPtrS<hkConvexShapeS> > m_kChildShapes;
    hkQuaternionS m_rotation;
    hkVector4f m_vTranslation;

    __forceinline void initSubpart(hkInt8 type)
    {
        m_type = type;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_pIndexBase = 0;
        m_pVertexBase = 0;
        m_ulUserData = 0;
    }
    ShapesSubpartT* FUN_00d56660(hkConvexShapeS* const* childShapes, int numChildShapes,
                                 const hkTransformD566& transform);
};

struct hkMemoryAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct WeldingElem
{
    char a0, a1;
    unsigned short a2;
    int a4;
    unsigned short a8, aa;
    int ac;
    int a10;
    int a14, a18, a1c, a20, a24, a28, a2c;
    __m128 a30;
    int a40, a44;
    char a48, a49, a4a, a4b;
    int a4c, a50;
    int a54, a58, a5c;

    WeldingElem()
    {
        a0 = 0;
        a1 = 1;
        a8 = 0;
        a2 = 0;
        aa = 1;
        ac = 0;
        a4 = 0;
        a10 = 0;
        a49 = 0;
        a30 = _mm_setzero_ps();
        a50 = 0;
    }
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_cap;

    hkArray() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(T));
        }
    }
};

struct Base1
{
    virtual void v1();
    int unk04, unk08, unk0c;
};

struct Base2
{
    virtual void v2();
    int unk14, unk18, unk1c;
};

struct FUN_00d21410 : public Base1, public Base2
{
    FUN_00d21410(int, int) throw();
};
