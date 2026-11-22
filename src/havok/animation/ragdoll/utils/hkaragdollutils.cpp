#include "f3_common.h"
// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    int __cdecl FUN_00cea030(void*, void*);
    int __cdecl FUN_00ce9db0(void*, void*);
    int __cdecl FUN_00ce9e90(void*);
}

// @fnv 0x00cea7c0
// pdb: hkaRagdollUtils::reorderAndAlignForRagdoll | hkaRagdollUtils.obj | fnv360_0822_retail, caller_sim, low
// pdb params: rigidBodiesInOut, constraintsInOut, warnOnAlignment
int __cdecl FUN_00cea7c0(void* apFirst, void* apSecond, void* apThird)
{
    if (FUN_00cea030(apFirst, apSecond))
        return 1;
    if (FUN_00ce9db0(apSecond, apThird))
        return 1;
    if (FUN_00ce9e90(apSecond))
        return 1;
    return 0;
}

struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};

struct Obj
{
    char pad0[0xc];
    Inner* inner;
};

struct hkErrStream
{
    void* p1;
    void* p2;
    void* p3;
    hkErrStream(void* buf, int size) throw();
    ~hkErrStream() throw();
    hkErrStream& operator<<(const char* str) throw();
};

struct hkError
{
    virtual ~hkError() throw();
    virtual void unk0();
    virtual void unk1();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};

extern hkError* DAT_01268360;

// Returns true if obj->inner->getSomething() is one of 0,1,2,6,7,8; otherwise optionally reports an unsupported-constraint error and returns false.
// @f3 0x0095e380 (community match, verified in this file)
// pdb: _isConstraintSupported | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap, high
// pdb: _isConstraintSupported | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap, high (was: IsSupportedRagdollConstraint)
static __declspec(noinline) bool _isConstraintSupported(Obj* obj, bool reportError) throw()
{
    extern hkError* DAT_010f3364;
    int val = ((int (__thiscall*)(Inner*))(*(void***)obj->inner)[4])(obj->inner);
    switch (val)
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
        return true;
    default:
        break;
    }
    if (reportError)
    {
        unsigned int buf[128];
        hkErrStream stream(buf, 512);
        stream << "Unsupported type of constraint in rag doll";
        DAT_010f3364->message(1, 0xabbabf3b, (char*)buf, ".\\Utils\\hkaRagdollUtils.cpp", 115);
    }
    return false;
}

void caller_of_IsSupportedRagdollConstraint(Obj* obj, bool reportError)
{
    _isConstraintSupported(obj, reportError);
}


void caller(Obj* obj)
{
    _isConstraintSupported(obj, true);
}

struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};

struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

SpawnedGlobal* __cdecl FUN_00c85750() throw();

struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
    int Init(void* a, void* b, int c, void* d);
};

struct SourceRecord
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
    int m_i2c;
};

// Allocates a 0x30-byte SpawnedObject from the global allocator and initializes it from src's fields, returning Init's result.
// @fnv 0x00ce9ff0
int __cdecl SpawnObjectFromRecord(SourceRecord* pSourceRecord)
{
    SpawnedGlobal* holder = FUN_00c85750();
    SpawnedAllocator* pAllocator = holder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)pAllocator->allocate(0x30);
    obj->m_size04 = 0x30;
    int iValue = pSourceRecord->m_i2c;
    return obj->Init(&pSourceRecord->unk08, &pSourceRecord->unk14, iValue, &pSourceRecord->unk20);
}

struct Node
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* source;
    void* destination;
};
template <class T> struct GameArray
{
    T* data;
    int count;
    int capacity;
    __forceinline void assign(const T* source, int size) throw();
};
typedef GameArray<void*> IntArray;
typedef GameArray<Node*> NodeArray;
struct HeapAllocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void* allocate(int* size);
    virtual void release(void* data, int size);
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
struct ScratchArray
{
    int* data;
    int count;
    unsigned int capacity;
    int* initial;
    __forceinline int& operator[](int index) throw()
    {
        return data[index];
    }
};
struct LogText
{
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* storage, int length) throw();
    LogText(void* storage, int length) throw()
    {
        FUN_00cb1600(storage, length);
    }
    ~LogText() throw()
    {
        FUN_00cc00e0();
    }
    LogText* FUN_00cc01c0(const char* value) throw();
    LogText* WriteInt(int value) throw();
    void FUN_00cc00e0() throw();
};
extern "C" void __cdecl FUN_00c908c0(HeapAllocator* allocator, ScratchArray* array, int capacity, int itemSize);
extern "C" const char DAT_010cbde0[];
extern "C" const char DAT_010cbdec[];
extern "C" const char DAT_010cbe00[];
extern "C" const char DAT_010cbd34[];
struct BSAudio;
BSAudio* __cdecl _FUN_00c85750() throw();
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(_FUN_00c85750());
}
static int* reserveScratch(int bytes) throw()
{
    ScratchAllocator* allocator = scratchState();
    int* result = reinterpret_cast<int*>(allocator->cursor);
    allocator->cursor += bytes;
    return result;
}
static __forceinline void reserveArray(HeapAllocator* allocator, ScratchArray* array, int size) throw()
{
    int capacity = array->capacity & 0x3fffffff;
    if (capacity < size)
    {
        int doubled = capacity * 2;
        int newCapacity = size < doubled ? doubled : size;
        FUN_00c908c0(allocator, array, newCapacity, 4);
    }
}
static __forceinline void fillWords(int* destination, int value, int count) throw()
{
    for (int index = 0; index < count; ++index)
        *destination++ = value;
}
static __forceinline void clearAndFree(HeapAllocator* allocator, ScratchArray* array) throw()
{
    array->count = 0;
    if (!(array->capacity & 0x80000000))
        allocator->release(array->data, (array->capacity & 0x3fffffff) * 4);
    array->data = 0;
    array->capacity = 0x80000000;
}
struct LocalArray : ScratchArray
{
    LocalArray(int size, int bytes) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        int* allocation = reserveScratch(bytes);
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    LocalArray(int size, int* output) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        ScratchAllocator* allocator = scratchState();
        int* allocation = reinterpret_cast<int*>(allocator->cursor);
        *output = (size * 4 + 127) & ~127;
        allocator->cursor += *output;
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    __forceinline void SetSizeAndGrow(int size, int value) throw()
    {
        reserveArray(scratchState()->heap, this, size);
        int num = size - count;
        int* destination = data + count;
        fillWords(destination, value, num);
        count = size;
    }
    __forceinline ~LocalArray() throw()
    {
        int* allocation = initial;
        if (allocation == data)
            count = 0;
        scratchState()->cursor = reinterpret_cast<unsigned char*>(allocation);
        clearAndFree(scratchState()->heap, this);
    }
};
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, unsigned int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, (capacity & 0x3fffffff) * 4);
}
template <class T> struct LocalBuffer
{
    T* data;
    int count;
    unsigned int capacity;
    LocalBuffer(int size, int bytes) throw()
    {
        count = size;
        data = reinterpret_cast<T*>(reserveScratch(bytes));
        capacity = size | 0x80000000;
    }
    __forceinline ~LocalBuffer() throw()
    {
        scratchState()->cursor = reinterpret_cast<unsigned char*>(data);
        freeBuffer(scratchState()->heap, data, capacity);
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
};
template <class T> __forceinline void GameArray<T>::assign(const T* source, int size) throw()
{
    HeapAllocator* allocator = scratchState()->heap;
    int available = capacity & 0x3fffffff;
    if (available < size)
    {
        if (!(capacity & 0x80000000))
            allocator->release(data, available * 4);
        int bytes = size * 4;
        data = reinterpret_cast<T*>(allocator->allocate(&bytes));
        capacity = bytes / 4;
    }
    count = size;
    T* destination = data;
    for (int index = 0; index < size; ++index)
        destination[index] = source[index];
}

template <class T> static __forceinline void swapItems(T& first, T& second) throw()
{
    T temporary = first;
    first = second;
    second = temporary;
}
static int findNode(const IntArray* nodes, void* value)
{
    int count = nodes->count;
    for (int index = 0; index < count; ++index)
        if (nodes->data[index] == value)
            return index;
    return -1;
}
// Checks link count and endpoint membership, then orders nodes by successor-chain length and reorders links accordingly.
// @fnv 0x00cea030
extern "C" int __cdecl FUN_00cea030(void* apNodes, void* apLinks)
{
    IntArray* nodes = static_cast<IntArray*>(apNodes);
    NodeArray* links = static_cast<NodeArray*>(apLinks);
    int nodeCount = nodes->count;
    int linkCount = links->count;
    if (linkCount != nodeCount - 1)
    {
        int messageStorage[128];
        hkErrStream message(messageStorage, 512);
        reinterpret_cast<LogText*>(&message)
            ->FUN_00cc01c0(DAT_010cbde0)
            ->WriteInt(nodeCount - 1)
            ->FUN_00cc01c0(DAT_010cbdec)
            ->WriteInt(linkCount)
            ->FUN_00cc01c0(DAT_010cbe00);
        DAT_01268360->message(1, 0xabba54bb, reinterpret_cast<const char*>(messageStorage), DAT_010cbd34, 0x144);
        return 1;
    }
    int nodeBytes;
    LocalArray linkPosition(nodeCount, &nodeBytes);
    linkPosition.SetSizeAndGrow(nodeCount, 0);
    LocalBuffer<int> permutation(nodeCount, nodeBytes);
    LocalArray successor(nodeCount, nodeBytes);
    successor.SetSizeAndGrow(nodeCount, -1);
    for (int edgeIndex = 0; edgeIndex < linkCount; ++edgeIndex)
    {
        Node* edge = links->data[edgeIndex];
        void* destination = edge->destination;
        void* source = edge->source;
        int sourceIndex = findNode(nodes, source);
        int targetIndex = findNode(nodes, destination);
        if (sourceIndex < 0 || targetIndex < 0)
            return 1;
        if (successor[sourceIndex] != -1 || linkPosition[sourceIndex] != 0)
            return 1;
        linkPosition[sourceIndex] = edgeIndex;
        successor[sourceIndex] = targetIndex;
    }
    {
        LocalArray chainDepth(nodeCount, nodeBytes);
        chainDepth.SetSizeAndGrow(nodeCount, 0);
        for (int index = 0; index < nodeCount; ++index)
        {
            for (int next = successor[index]; next != -1; next = successor[next])
                ++chainDepth[index];
        }
        for (int index = 0; index < nodeCount; ++index)
            permutation[index] = index;
        for (int left = 0; left < nodeCount - 1; ++left)
        {
            for (int right = left + 1; right < nodeCount; ++right)
            {
                if (chainDepth[left] > chainDepth[right])
                {
                    swapItems(chainDepth[left], chainDepth[right]);
                    swapItems(permutation[left], permutation[right]);
                }
            }
        }
    }
    LocalBuffer<void*> sortedNodes(nodeCount, nodeBytes);
    LocalBuffer<Node*> sortedEdges(linkCount, (linkCount * 4 + 127) & ~127);
    for (int index = 0; index < nodeCount; ++index)
    {
        int original = permutation[index];
        sortedNodes[index] = nodes->data[original];
        if (index > 0)
        {
            int position = linkPosition[original];
            if (position >= 0)
                sortedEdges[index - 1] = links->data[position];
            else
                sortedEdges[index - 1] = 0;
        }
    }
    nodes->assign(sortedNodes.data, nodeCount);
    links->assign(sortedEdges.data, linkCount);
    return 0;
}

namespace fnv_00ceaf60 {
struct HeapAllocator
{
    virtual void slot0();
    virtual void* AllocateMemoryBlock(int bytes) throw();
    virtual void slot2();
    virtual void* allocate(int* bytes) throw();
    virtual void release(void* data, int bytes) throw();
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(FUN_00c85750());
}
extern "C" void __cdecl ResizeAudioStream(HeapAllocator*, void*, int);
template <class T> static __forceinline T* allocateBuffer(HeapAllocator* allocator, int& count) throw()
{
    if (count)
    {
        int bytes = count * sizeof(T);
        T* data = (T*)allocator->allocate(&bytes);
        count = bytes / sizeof(T);
        return data;
    }
    return 0;
}
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, capacity & 0x3fffffff);
}
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() throw()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    __forceinline ArrayBase(int count) throw()
    {
        int allocatedCount = count;
        data = allocateBuffer<T>(scratchState()->heap, allocatedCount);
        capacity = allocatedCount ? allocatedCount : 0x80000000;
        size = count;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return size;
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
    __forceinline const T& operator[](int index) const throw()
    {
        return data[index];
    }
    __forceinline void AddBack(HeapAllocator* allocator, const T& value) throw()
    {
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(allocator, this, sizeof(T));
        data[size] = value;
        ++size;
    }
    __forceinline void ClearAndRelease(HeapAllocator* allocator) throw()
    {
        size = 0;
        if (!(capacity & 0x80000000))
            allocator->release(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
template <class T> struct Array : ArrayBase<T>
{
    __forceinline Array() throw()
    {}
    __forceinline Array(int count) throw() : ArrayBase<T>(count)
    {}
    __forceinline void clear() throw()
    {
        ClearAndRelease(scratchState()->heap);
    }
    __forceinline void AddBack(const T& value) throw()
    {
        ArrayBase<T>::AddBack(scratchState()->heap, value);
    }
};
struct RigidBody;
struct Constraint;
struct Skeleton
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int boneCount;
};
struct Ragdoll
{
    unsigned int unk00;
    unsigned short memorySizeAndFlags, referenceCount;
    ArrayBase<RigidBody*> bodies;
    ArrayBase<Constraint*> constraints;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    Ragdoll* FUN_00ce2510(const ArrayBase<RigidBody*>&, const ArrayBase<Constraint*>&, Skeleton*,
                          const ArrayBase<int>&) throw();
    __forceinline Skeleton* getSkeleton() const throw()
    {
        return skeleton;
    }
    __forceinline RigidBody* getBody(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return mapped < 0 ? 0 : bodies[mapped];
    }
    __forceinline Constraint* GetConstraintForBone(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return --mapped < 0 ? 0 : constraints[mapped];
    }
};
}  // namespace fnv_00ceaf60

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
}

struct hkBoolR
{
    char m_cBooleanValue;
    hkBoolR()
    {}
    hkBoolR(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class ScalarValue
{
    __m128 m_uiFilterValue;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& a) : m_uiFilterValue(a)
    {}
    __forceinline const __m128& getQuad() const
    {
        return m_uiFilterValue;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_uiFilterValue, m_uiFilterValue, 0);
    }
};
struct hkQuaternion;
struct hkXform;
class hkVec4
{
    __m128 m_vComponents;

  public:
    operator __m128() const
    {
        return m_vComponents;
    }
    __forceinline __m128& getQuad();
    __forceinline const __m128& getQuad() const;
    void operator=(const hkVec4& a);
    void operator=(const __m128& a);
    void setAdd4(const hkVec4& a, const hkVec4& b);
    void setMul4(const hkVec4& a, const hkVec4& b);
    void setAddMul4(const hkVec4& a, const hkVec4& b, const hkVec4& c);
    void addMul4(const hkVec4& a, const hkVec4& b);
    void addMul4(const ScalarValue& a, const hkVec4& b);
    void setNeg4(const hkVec4& a);
    void setNeg3(const hkVec4& a);
    void setCross(const hkVec4& a, const hkVec4& b);
    ScalarValue dot3(const hkVec4& a) const;
    ScalarValue scalarAt(int i) const;
    void SetAllComponents(const ScalarValue& a);
    void sub4(const hkVec4& a);
    void setXYZW(const hkVec4& xyz, const hkVec4& w);
    void setBroadcast(const hkVec4& a, int i);
    void broadcast(int i);
    void setReciprocal4(const hkVec4& a);
    void setReciprocal3(const hkVec4& a);
    void setXYZ0(const hkVec4& a);
    void SetRotatedDirection(const hkQuaternion& a, const hkVec4& b);
    void setRotatedInverseDir(const hkQuaternion& a, const hkVec4& b);
    void FUN_00c7f690(const hkXform& t, const hkVec4& p);
};
struct hkQuaternion
{
    hkVec4 m_vec;
    const hkVec4& getImag() const;
    void SetConjugate(const hkQuaternion& a);
    inline void FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b);
};
inline __m128& hkVec4::getQuad()
{
    return m_vComponents;
}
inline const __m128& hkVec4::getQuad() const
{
    return m_vComponents;
}
inline void hkVec4::operator=(const hkVec4& a)
{
    m_vComponents = a.m_vComponents;
}
inline void hkVec4::operator=(const __m128& a)
{
    getQuad() = a;
}

inline void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVec4 cross;
    cross.setCross(a.getImag(), b.getImag());
    cross.addMul4(a.m_vec.scalarAt(3), b.getImag());
    cross.addMul4(b.m_vec.scalarAt(3), a.getImag());
    hkVec4 projection;
    projection.SetAllComponents(a.m_vec.dot3(b.m_vec));
    hkVec4 product;
    product.setMul4(a.m_vec, b.m_vec);
    product.sub4(projection);
    m_vec.setXYZW(cross, product);
}

struct hkQsXform
{
    hkVec4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVec4 m_vScale;

    hkBoolR FUN_00ce5120(const hkQsXform& other, float eps) const;
    void FUN_00ce5070(const void* transform);
    void FUN_00ce50b0(void* transformOut) const;

    __forceinline void SetProduct(const hkQsXform& t1, const hkQsXform& t2)
    {
        hkVec4 extra;
        extra.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(t1.m_vTranslation, extra);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
    __forceinline void SetConjugate(const hkQsXform& t)
    {

        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVec4 reciprocal;
        reciprocal.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(reciprocal);
    }
};

struct hkXform
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
};

struct MemoryRouter : SpawnedGlobal
{
    __forceinline SpawnedAllocator& heap()
    {
        return *m_pAllocator;
    }
};

// @fnv 0x00ce9880
volatile int g_inT;
volatile int g_inBody;
volatile int g_out;
