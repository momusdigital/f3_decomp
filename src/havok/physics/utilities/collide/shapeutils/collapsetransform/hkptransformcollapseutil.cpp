#include "f3_common.h"
// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ShapeRefArray
{
    int* refs;
    int count;
};

struct ShapeData
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_00d738f0(int);
    void FUN_00d74a20();
    ShapeData* FUN_00d74b20(ShapeRefArray* refs);
};

// Resets the three fields, forwards each ref's value at offset 0x10 to FUN_00d738f0, then calls FUN_00d74a20 and returns this.
// @fnv 0x00d74b20
// pdb: _SharedShapeData::_SharedShapeData | hkpTransformCollapseUtil.obj | fnv360_0822_retail, call_gap_sim, high
// pdb params: rigidBodies
ShapeData* ShapeData::FUN_00d74b20(ShapeRefArray* refs)
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0x80000000;
    for (int i = 0; i < refs->count; ++i)
        FUN_00d738f0(*(int*)(refs->refs[i] + 0x10));
    FUN_00d74a20();
    return this;
}

struct FUN_00d74980_Class
{
    int* refs;
    int count;
    int FindMappedValue(int value);
};

// Scans the refs array in groups of three and returns the third entry of the first group whose first or second entry equals value, otherwise 0.
// @fnv 0x00d74980
// pdb: hkMatrix4::operator() | hkMathUtil.obj | fnv360_0822_debug, objrun_open, low
// pdb params: r, c
int FUN_00d74980_Class::FindMappedValue(int value)
{
    for (int i = 0; i < count; ++i)
    {
        if (refs[i * 3] == value || refs[i * 3 + 1] == value)
            return refs[i * 3 + 2];
    }

    return 0;
}

// RunContextOperation — __cdecl (caller pops its arguments).
//
// Builds a 12-byte context object on the stack, initializes it to
// (0, 0, 0x80000000), runs its setup pass, resets it, then delegates to the
// helper FUN_00d739f0 and stores its result through the caller's out pointer.
// Finally the context's cleanup pass runs and the function returns 0.

struct FUN_00d74420_Context
{
    int m_kPointA;  // +0x00
    int m_kPointB;  // +0x04
    int m_iThirdValue;  // +0x08, initialized to 0x80000000
    void FUN_00d738f0(int value);
    void FUN_00d74a20();
    void FUN_00d74aa0();
};

int FUN_00d739f0(int a1, int a2, FUN_00d74420_Context* ctx, int a3);

class hkMemoryAllocatorD748
{
  public:
    virtual ~hkMemoryAllocatorD748() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD748
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD748* m_pStreamAllocator;
    hkMemoryAllocatorD748& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD748& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyD748(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD748
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD748() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayD748() throw()
    {
        hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyD748(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityD748;

int __cdecl RemapCollisionShapes(hkArrayD748<hkpEntityD748*>& kEntities, int iA, int iB) throw();

struct D749Entry
{
    int m_key0;
    int m_uiFilterValue;
    int m_key1;
};

struct hkReferencedObject
{
    void removeReference();
};

class D749Table
{
  public:
    D749Entry* m_data;
    int m_uiItemCount;

    int SetEntryValue(int key, int value);
};

// Scans the table for an entry matching key in either key field, releases the old value, stores the new value, and returns 0 on success or 1 if not found.
// @f3 0x00a05790 (community match, verified in this file)
struct ShpObjA057 {
    virtual ~ShpObjA057();
    unsigned short GetAllocationSize;   // [4]
    short refCount;                     // [6]
    int unk08;                          // [8]
    int type;                           // [12]
};

// pdb: _SharedShapeData::findShapeDataIndex | hkpTransformCollapseUtil.obj | fnv360_0822_debug, objrun_open, low
// pdb params: shape
int D749Table::SetEntryValue(int key, int value)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            if (m_data[i].m_key0 == key || m_data[i].m_uiFilterValue == key)
                goto found;
            ++i;
        } while (i < m_uiItemCount);
    }
    return 1;
found:
    ShpObjA057* v = (ShpObjA057*)value;
    if (v->GetAllocationSize != 0)
        v->refCount++;
    ShpObjA057* old = (ShpObjA057*)m_data[i].m_uiFilterValue;
    if (old && old->GetAllocationSize != 0)
    {
        old->refCount--;
        if (old->refCount == 0)
            delete old;
    }
    m_data[i].m_uiFilterValue = value;
    return 0;
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_and_ps(__m128, __m128);

struct Shp_d74480;
struct Alloc_d74480
{
    virtual void unk00();
    virtual void* allocate(int size);
    virtual void unk08();
    virtual void unk0c();
    virtual void deallocate(void* p, int size);
};
struct Router_d74480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Alloc_d74480* m_pStreamAllocator;
    Alloc_d74480& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
Router_d74480* __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(Alloc_d74480*, void*, int);
struct Shp_d74480
{
    void* vtbl;
    unsigned short GetAllocationSize;
    unsigned short refCount;
    int unk08;
    int type;
    void FUN_00c90510();
    void FUN_00c905b0();
    Shp_d74480* FUN_00cf5640(Shp_d74480** shapes, int count, int flag);
    Shp_d74480* FUN_00cf5990(Shp_d74480* child, void* transform);
    Shp_d74480* FUN_00d5d7a0(Shp_d74480* child, void* translation, int flag);
    void FUN_00c9e340(int type, float radius, Shp_d74480* child, int flag);
};
struct CacheEnt_d74480
{
    Shp_d74480* source;
    Shp_d74480* replacement;
    int unk08;
};
struct Cache_d74480
{
    CacheEnt_d74480* data;
    int count;
    int capacity;
    void SetEntryValue(Shp_d74480* source, Shp_d74480* replacement);
};
Shp_d74480* __cdecl FUN_00d739f0(Shp_d74480*, void*, Cache_d74480*, void*);

// Recursively processes a shape tree, replacing nodes with cached or newly allocated equivalents and storing results in the cache.
// @f3 0x00a050e0 (community match, verified in this file)
// 0x00a050e0: hkpTransformCollapseUtil::collapseShapesRecursively(const hkpShape* shape, const Options& options,
// _SharedShapeData& sharedShapeData, Results& resultsOut) of Havok 5.5.0 (hkpUtilities, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// Returns the shape with every transform shape below it collapsed, with one reference for the caller. A shape
// that was replaced before comes from the shared table; a list shape is rebuilt when any child changed; a
// transform, convex transform or convex translate shape is rebuilt around its collapsed child and then collapsed
// itself; any other shape is returned as it is.
// Class, member and function names follow the Havok 5.5.0 SDK headers; the declarations are cut down to what this
// function touches, and the bodies are written from the game's code. The packet's signature is kept: the unit's
// Shp_d74480 and Cache_d74480 stand for hkpShape and _SharedShapeData, the two void pointers for the options and
// the results.
namespace f3m_00a050e0 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;
typedef float hkReal;

enum
{
    HK_MEMORY_CLASS_ARRAY = 0x17,
    HK_MEMORY_CLASS_CDINFO = 0x27
};

extern unsigned long DAT_010f3170;  // thread-local slot of the thread's hkThreadMemory

struct hkThreadMemory
{
    static hkThreadMemory& getInstance() { return *(hkThreadMemory*)TlsGetValue(DAT_010f3170); }
    void* FUN_008f6d30(int nbytes, int cl);          // allocateChunk
    void FUN_008f6d90(void* p, int nbytes, int cl);  // deallocateChunk
};

namespace hkArrayUtil {
// grows the array for one more element
void __cdecl FUN_00901f10(void* array, int sizeElem);
}  // namespace hkArrayUtil

template <typename T> struct hkArray
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    hkArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    // what the array's destructor does. The library was built without exception handling; this unit is compiled
    // with it, where a destructor would give the function an exception frame, so the function below releases its
    // array by hand on both of its ways out.
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
        {
            int capacity = getCapacity();
            hkThreadMemory& memory = hkThreadMemory::getInstance();
            memory.FUN_008f6d90(m_data, capacity * sizeof(T), HK_MEMORY_CLASS_ARRAY);
        }
    }

    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }
    T* begin() { return m_data; }
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }
    void pushBack(const T& t)
    {
        if (m_size == getCapacity())
            hkArrayUtil::FUN_00901f10(this, sizeof(T));
        m_data[m_size++] = t;
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    virtual void calcStatistics(void* collector) const;
    virtual void calcContentStatistics(void* collector, const void* cls) const;

    // the object's size goes into m_memSizeAndFlags
    __forceinline void* operator new(size_t nbytes)
    {
        hkReferencedObject* object =
            (hkReferencedObject*)hkThreadMemory::getInstance().FUN_008f6d30((int)nbytes, HK_MEMORY_CLASS_CDINFO);
        object->m_memSizeAndFlags = (hkUint16)nbytes;
        return object;
    }

    // objects with m_memSizeAndFlags == 0 are not reference counted
    __forceinline void addReference() const
    {
        if (m_memSizeAndFlags != 0)
            m_referenceCount++;
    }
    __forceinline void removeReference() const
    {
        if (m_memSizeAndFlags != 0)
        {
            m_referenceCount--;
            if (m_referenceCount == 0)
                delete this;
        }
    }

    hkUint16 m_memSizeAndFlags;
    mutable hkInt16 m_referenceCount;
};

enum hkpShapeType
{
    HK_SHAPE_LIST = 10,
    HK_SHAPE_CONVEX_TRANSLATE = 12,
    HK_SHAPE_CONVEX_TRANSFORM = 13,
    HK_SHAPE_TRANSFORM = 28
};

struct hkpShape : hkReferencedObject
{
    hkpShapeType getType() const { return m_type; }

    hkUlong m_userData;
    hkpShapeType m_type;
};

struct hkpShapeContainer
{
    virtual ~hkpShapeContainer();
    virtual int getNumChildShapes() const;
};

struct hkpSingleShapeContainer : hkpShapeContainer
{
    const hkpShape* getChild() const { return m_childShape; }

    const hkpShape* m_childShape;
};

struct __declspec(align(16)) hkVector4
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkTransform
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_translation;
};

struct hkpShapeCollection : hkpShape, hkpShapeContainer
{
    bool m_disableWelding;
};

struct hkpListShape : hkpShapeCollection
{
    struct ChildInfo
    {
        __declspec(align(16)) const hkpShape* m_shape;
        hkUint32 m_collisionFilterInfo;
        int m_shapeSize;
        int m_numChildShapes;
    };

    hkpListShape(const hkpShape* const* shapeArray, int numShapes) throw();  // the game's FUN_0097dab0

    const hkpShape* getChildShapeInl(int i) const { return m_childInfo[i].m_shape; }

    hkArray<ChildInfo> m_childInfo;
    hkVector4 m_aabbHalfExtents;
    hkVector4 m_aabbCenter;
    hkUint32 m_enabledChildren[8];
};

struct hkpTransformShape : hkpShape
{
    // the game's FUN_0097dd70
    hkpTransformShape(const hkpShape* childShape, const hkTransform& transform) throw();

    const hkpShape* getChildShape() const { return m_childShape.getChild(); }
    const hkTransform& getTransform() const { return m_transform; }

    hkpSingleShapeContainer m_childShape;
    hkQuaternion m_rotation;
    hkTransform m_transform;
};

struct hkpSphereRepShape : hkpShape
{
};

struct hkpConvexShape : hkpSphereRepShape
{
    hkReal m_radius;
};

struct hkpConvexTransformShape : hkpConvexShape
{
    // the game's FUN_009ecf50
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform) throw();

    const hkpConvexShape* getChildShape() const { return static_cast<const hkpConvexShape*>(m_childShape.getChild()); }
    const hkTransform& getTransform() const { return m_transform; }

    hkpSingleShapeContainer m_childShape;
    int m_childShapeSize;
    hkTransform m_transform;
};

struct hkpConvexTranslateShape : hkpConvexShape
{
    // the game's FUN_00a56ba0
    hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation) throw();

    const hkpConvexShape* getChildShape() const { return static_cast<const hkpConvexShape*>(m_childShape.getChild()); }
    const hkVector4& getTranslation() const { return m_translation; }

    hkpSingleShapeContainer m_childShape;
    int m_childShapeSize;
    hkVector4 m_translation;
};

enum hkResult
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};

// the shapes replaced so far, so that a shape shared by several parents is rebuilt once
class _SharedShapeData
{
public:
    struct Entry
    {
        const hkpShape* m_originalShape;
        const hkpShape* m_replacementShape;
        int m_unk08;
    };

    const hkpShape* findReplacement(const hkpShape* shape) const
    {
        for (int i = 0; i < m_entries.getSize(); i++)
        {
            if (m_entries[i].m_originalShape == shape)
                return m_entries[i].m_replacementShape;
        }
        return 0;
    }
    hkResult FUN_00a05790(const hkpShape* original, const hkpShape* replacement);  // setReplacement

    hkArray<Entry> m_entries;
};

struct Options;
struct Results;

// the unit's Shp_d74480 is the packet's name for hkpShape
inline const hkpShape* asShape(const void* shape)
{
    return (const hkpShape*)shape;
}

// hkpTransformCollapseUtil::collapseTransformShape
const hkpShape* __cdecl FUN_00a04480(const hkpShape* transformShape, const Options& options,
                                     _SharedShapeData& sharedShapeData, Results& resultsOut);

}  // namespace f3m_00a050e0

Shp_d74480* __cdecl ProcessShape(Shp_d74480* shape, void* context, Cache_d74480* cache, void* settings)
{
    namespace hk = f3m_00a050e0;
    const hk::Options& options = *(const hk::Options*)context;
    hk::_SharedShapeData& sharedShapeData = *(hk::_SharedShapeData*)cache;
    hk::Results& resultsOut = *(hk::Results*)settings;

    // replaced before: hand out the replacement with a reference for the caller
    const hk::hkpShape* replacement = sharedShapeData.findReplacement(hk::asShape(shape));
    if (replacement != 0)
    {
        replacement->addReference();
        return (Shp_d74480*)replacement;
    }

    const hk::hkpShape* result;
    switch (hk::asShape(shape)->getType())
    {
    case hk::HK_SHAPE_LIST:
    {
        const hk::hkpListShape* listShape = static_cast<const hk::hkpListShape*>(hk::asShape(shape));
        int numChildren = listShape->getNumChildShapes();
        hk::hkArray<const hk::hkpShape*> newChildren;
        bool unchanged = true;
        for (int i = 0; i < numChildren; i++)
        {
            const hk::hkpShape* child = listShape->getChildShapeInl(i);
            const hk::hkpShape* newChild =
                hk::asShape(ProcessShape((Shp_d74480*)child, context, cache, settings));
            newChildren.pushBack(newChild);
            if (newChild != child)
                unchanged = false;
        }
        if (unchanged)
        {
            // every child came back as it was: drop the children's references and keep the list
            for (int i = 0; i < numChildren; i++)
                newChildren[i]->removeReference();
            hk::asShape(shape)->addReference();
            result = hk::asShape(shape);
            newChildren.releaseMemory();
            break;
        }
        // a new list of the collapsed children takes the old one's place in the table
        hk::hkpListShape* newList = new hk::hkpListShape(newChildren.begin(), numChildren);
        for (int i = 0; i < numChildren; i++)
            newChildren[i]->removeReference();
        sharedShapeData.FUN_00a05790(hk::asShape(shape), newList);
        result = newList;
        newChildren.releaseMemory();
        break;
    }
    case hk::HK_SHAPE_TRANSFORM:
    {
        // the child is collapsed first; when it changed, the transform shape is rebuilt around the new child;
        // then the transform itself is collapsed into the child where that is possible
        const hk::hkpTransformShape* transformShape = static_cast<const hk::hkpTransformShape*>(hk::asShape(shape));
        const hk::hkpShape* child = transformShape->getChildShape();
        const hk::hkpShape* newChild = hk::asShape(ProcessShape((Shp_d74480*)child, context, cache, settings));
        const hk::hkpShape* newShape;
        if (child == newChild)
        {
            newChild->removeReference();
            newShape = hk::asShape(shape);
            hk::asShape(shape)->addReference();
        }
        else
        {
            newShape = new hk::hkpTransformShape(newChild, transformShape->getTransform());
            newChild->removeReference();
            sharedShapeData.FUN_00a05790(hk::asShape(shape), newShape);
        }
        result = hk::FUN_00a04480(newShape, options, sharedShapeData, resultsOut);
        newShape->removeReference();
        break;
    }
    case hk::HK_SHAPE_CONVEX_TRANSFORM:
    {
        const hk::hkpConvexTransformShape* transformShape = static_cast<const hk::hkpConvexTransformShape*>(hk::asShape(shape));
        const hk::hkpShape* child = transformShape->getChildShape();
        const hk::hkpShape* newChild = hk::asShape(ProcessShape((Shp_d74480*)child, context, cache, settings));
        const hk::hkpShape* newShape;
        if (child == newChild)
        {
            newChild->removeReference();
            newShape = hk::asShape(shape);
            hk::asShape(shape)->addReference();
        }
        else
        {
            newShape = new hk::hkpConvexTransformShape(static_cast<const hk::hkpConvexShape*>(newChild),
                                                       transformShape->getTransform());
            newChild->removeReference();
            sharedShapeData.FUN_00a05790(hk::asShape(shape), newShape);
        }
        result = hk::FUN_00a04480(newShape, options, sharedShapeData, resultsOut);
        newShape->removeReference();
        break;
    }
    case hk::HK_SHAPE_CONVEX_TRANSLATE:
    {
        const hk::hkpConvexTranslateShape* translateShape = static_cast<const hk::hkpConvexTranslateShape*>(hk::asShape(shape));
        const hk::hkpShape* child = translateShape->getChildShape();
        const hk::hkpShape* newChild = hk::asShape(ProcessShape((Shp_d74480*)child, context, cache, settings));
        const hk::hkpShape* newShape;
        if (child == newChild)
        {
            newChild->removeReference();
            newShape = hk::asShape(shape);
            hk::asShape(shape)->addReference();
        }
        else
        {
            newShape = new hk::hkpConvexTranslateShape(static_cast<const hk::hkpConvexShape*>(newChild),
                                                       translateShape->getTranslation());
            newChild->removeReference();
            sharedShapeData.FUN_00a05790(hk::asShape(shape), newShape);
        }
        result = hk::FUN_00a04480(newShape, options, sharedShapeData, resultsOut);
        newShape->removeReference();
        break;
    }
    default:
        hk::asShape(shape)->addReference();
        result = hk::asShape(shape);
        break;
    }
    return (Shp_d74480*)result;
}


struct hkShapeEntryD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkReferencedObject* m_pCollisionShape;
};

struct hkShapeEntryArrayD748
{
    hkShapeEntryD748** m_data;
    int m_iElementCount;
};

struct hkShapeOutputD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00d73400() throw();
};

struct hkShapeMapD748
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkShapeMapD748* FUN_00d74b20(hkShapeEntryArrayD748* refs) throw();
    void FUN_00d74aa0() throw();
};

hkReferencedObject* __cdecl ProcessShape(hkReferencedObject* shape, void* context, hkShapeMapD748* map,
                                         hkShapeOutputD748* out) throw();

// Remaps each collision shape in refs via ProcessShape, storing results back into the entries and releasing the old references.
// @f3 0x00a05580 (community match, verified in this file)
// pdb: hkpTransformCollapseUtil::collapseTransforms | hkpTransformCollapseUtil.obj | fnv360_0822_retail, callee_sim, low
// pdb params: rigidBodies, options, resultsOut
int __cdecl RemapCollisionShapes(hkShapeEntryArrayD748* refs, void* context, hkShapeOutputD748* out)
{
    out->FUN_00d73400();
    hkShapeMapD748 map;
    map.FUN_00d74b20(refs);

    for (int i = 0; i < refs->m_iElementCount; ++i)
    {
        hkShapeEntryD748* entry = refs->m_data[i];
        hkReferencedObject* oldShape = entry->m_pCollisionShape;
        hkReferencedObject* newShape = ProcessShape(oldShape, context, &map, out);
        ShpObjA057* ref = (ShpObjA057*)oldShape;
        if (ref->GetAllocationSize != 0)
        {
            if (--ref->refCount == 0)
                delete ref;
        }
        entry->m_pCollisionShape = newShape;
    }

    map.FUN_00d74aa0();
    return 0;
}


struct hkpShapeD737;
struct hkpListChildInfoD737
{
    const hkpShapeD737* m_pCollisionShape;
    unsigned int m_uiCollisionFilterData;
    int m_iShapeKey;
    int m_iChildShapeCount;
};
class hkpShapeContainerD737
{
  public:
    virtual ~hkpShapeContainerD737();
    virtual int GetNumChildShapes() const;
};
struct hkpShapeD737
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    unsigned int m_ulUserData;
    int m_type;
};
struct hkpListShapeD737 : hkpShapeD737
{
    hkpShapeContainerD737 m_container;
    const hkpShapeD737* m_14;
    hkpListChildInfoD737* m_kChildInfoList;
};
struct hkpSingleD737 : hkpShapeD737
{
    int m_10;
    const hkpShapeD737* m_14;
    const hkpShapeD737* m_18;
};

template <class T> static __forceinline void PushBackD737(hkArrayD748<T>* a, const T& t)
{
    hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
    if (a->m_iElementCount == a->getCapacity())
        ResizeAudioStream(&kAlloc, a, sizeof(T));
    constructWithCopyD748(a->m_data + a->m_iElementCount, 1, t);
    a->m_iElementCount++;
}

// Appends the child shapes of a shape to out: every list child for type 9, or the single child pointer for types 15, 12 and 11.
// @f3 0x00a04270 (community match, verified in this file)
void __cdecl FUN_00901f10(void* arr, int elemSize);

static __forceinline void PushBackShapeD737(hkArrayD748<const hkpShapeD737*>* a, const hkpShapeD737* t)
{
    if (a->m_iElementCount == a->getCapacity())
        FUN_00901f10(a, sizeof(const hkpShapeD737*));
    a->m_data[a->m_iElementCount] = t;
    a->m_iElementCount++;
}

// pdb: _getShapeChildren | hkpTransformCollapseUtil.obj | fnv360_0721_beta, objrun_prop, low
static __declspec(noinline) void FUN_00d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    switch (shape->m_type)
    {
    case 10: {
        const hkpListShapeD737* list = (const hkpListShapeD737*)shape;
        for (int i = 0; i < list->m_container.GetNumChildShapes(); i++)
        {
            const hkpShapeD737* child = list->m_kChildInfoList[i].m_pCollisionShape;
            PushBackShapeD737(out, child);
        }
    }
    break;
    case 28: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_14;
        PushBackShapeD737(out, child);
    }
    break;
    case 12:
    case 13: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_18;
        PushBackShapeD737(out, child);
    }
    break;
    }
}
void caller_of_FUN_00a04270(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    FUN_00d737d0(shape, out);
}


void zz_probe_d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    FUN_00d737d0(shape, out);
}

struct D74A20Ref
{
    void FUN_00c905b0();
};

struct D74A20Entry
{
    D74A20Ref* m_kPointA;
    D74A20Ref* m_kPointB;
    int m_uiItemCount;
};

struct D74A20Array
{
    D74A20Entry* m_data;
    int m_iElementCount;
};

// @f3 0x00a056a0 (community match, verified in this file)
static __forceinline void ReleaseRef(D74A20Ref* ref)
{
    Shp_d74480* p = reinterpret_cast<Shp_d74480*>(ref);
    if (p->GetAllocationSize != 0)
    {
        (*(short*)&p->refCount)--;
        if (p->refCount == 0)
        {
            void (__thiscall* fn)(void*, int) = (void (__thiscall*)(void*, int))(((void**)p->vtbl)[0]);
            fn(p, 1);
        }
    }
}

void ShapeData::FUN_00d74a20()
{
    D74A20Array* array = reinterpret_cast<D74A20Array*>(this);
    int index = array->m_iElementCount - 1;
    if (index < 0)
        return;
    while (index >= 0)
    {
        if (array->m_data[index].m_uiItemCount < 2)
        {
            if (array->m_data[index].m_kPointA != 0)
                ReleaseRef(array->m_data[index].m_kPointA);
            if (array->m_data[index].m_kPointB != 0)
                ReleaseRef(array->m_data[index].m_kPointB);
            array->m_iElementCount--;
            array->m_data[index] = array->m_data[array->m_iElementCount];
        }
        index--;
    }
}


extern "C"
{
    __m128 _mm_setzero_ps(void);
    __m128 _mm_and_ps(__m128, __m128);
}

extern const __m128 g_hkQuadXYZMask;

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setXYZ0(const hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, g_hkQuadXYZMask);
    }
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkRotation
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkBool IsEqualWithinTolerance(const hkRotation& other, float epsilon) const;
    __forceinline void setIdentity()
    {
        hkVector4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1 = zero;
        m_kColumn1(1) = 1.0f;
        m_kColumn2 = zero;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    static const hkTransform s_identity;
    __forceinline static const hkTransform& GetIdentityTransform()
    {
        return s_identity;
    }
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline const hkRotation& getRotation() const
    {
        return m_rotation;
    }
    __forceinline void setTranslation(const hkVector4& t)
    {
        m_vTranslation = t;
    }
    hkBool IsEqualWithinTolerance(const hkTransform& other, float epsilon) const;
    void SetProduct(const hkTransform& a, const hkTransform& b);
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct NineIntegerRecord
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    static NineIntegerRecord& GetMonitorStream();
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct hkBaseObject
{
    virtual ~hkBaseObject();
};

struct CollapseRefObject : hkBaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __forceinline void* operator new(unsigned int nbytes)
    {
        CollapseRefObject* b =
            static_cast<CollapseRefObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void FUN_00c90510() const;
};

enum CollisionShapeType
{
    HK_SHAPE_CONVEX_TRANSLATE = 0xb,
    HK_SHAPE_CONVEX_TRANSFORM = 0xc,
    HK_SHAPE_TRANSFORM = 0xf,
};

struct hkpShape : CollapseRefObject
{
    unsigned int m_ulUserData;
    int m_type;
    __forceinline int getType() const
    {
        return m_type;
    }
};

struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;
    __forceinline float getRadius() const
    {
        return m_fSphereRadius;
    }
};

struct hkpSingleShapeContainer
{
    virtual ~hkpSingleShapeContainer();
    const hkpShape* m_pContainedShape;
    __forceinline const hkpShape* getChild() const
    {
        return m_pContainedShape;
    }
};

struct hkpConvexTransformShapeBase : hkpConvexShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkpConvexTransformShapeBase(int type, float radius, const hkpConvexShape* childShape, int ref);
    __forceinline const hkpConvexShape* GetShapeForKey() const
    {
        return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild());
    }
};

struct hkpConvexTranslateShape : hkpConvexTransformShapeBase
{
    hkVector4 m_vTranslation;
    __forceinline hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation, int ref = 1)
        : hkpConvexTransformShapeBase(HK_SHAPE_CONVEX_TRANSLATE, childShape->getRadius(), childShape, ref)
    {
        m_vTranslation.setXYZ0(translation);
        m_iChildShapeSize = 0;
    }
    virtual ~hkpConvexTranslateShape();
    __forceinline const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
};

struct hkpConvexTransformShape : hkpConvexTransformShapeBase
{
    hkTransform m_kMotionTransform;
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int ref = 1);
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkpTransformShape : hkpShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkQuaternion m_rotation;
    hkTransform m_kMotionTransform;
    hkpTransformShape(const hkpShape* childShape, const hkTransform& transform);
    __forceinline const hkpShape* GetShapeForKey() const
    {
        return m_pContainedShape.getChild();
    }
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

template <class T> class hkArrayD74
{
  public:
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocatorD748& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct RefPairD74
{
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    int m_iThirdValue;
};
class RefPairListD74
{
  public:
    hkArrayD74<RefPairD74> m_pairs;
    void FUN_00d74aa0();
};
// Removes references from all pairs in m_pairs and then clears and releases the underlying array storage.
// @f3 0x00a29d60 (community match, verified in this file)
struct Member1302{int unk00,unk04,unk08;void FUN_00922cf0();};struct Pair1302{void* key;Member1302 member04;};
struct Heap1302{void FUN_008f6d90(void*,unsigned int,int);};extern unsigned long DAT_010f3170;extern "C" __declspec(dllimport) Heap1302* __stdcall FUN_00d9b080(unsigned long);
struct ArrayView1302{Pair1302* data;int count;union {int capacity;struct {unsigned int length:30;unsigned int flags:2;} bits;};unsigned int GetCapacity() const {return bits.length;}void FUN_00a29c30(void*,Member1302*);void Release(unsigned int n){unsigned int masked=n;Heap1302* heap=FUN_00d9b080(DAT_010f3170);heap->FUN_008f6d90(data,masked*sizeof(Pair1302),0x17);}};

void RefPairListD74::FUN_00d74aa0(){ArrayView1302& array=*reinterpret_cast<ArrayView1302*>(this);for(int i=0;i<array.count;++i){array.FUN_00a29c30(array.data[i].key,&array.data[i].member04);array.data[i].member04.FUN_00922cf0();}unsigned int cap=(unsigned int)array.capacity;if(!(cap&0x80000000u)){array.Release(array.GetCapacity());}}

