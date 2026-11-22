// src/staging/blk_00d20000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00d20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
void __cdecl FUN_00d365d0();
extern "C" void __cdecl FUN_00d36b70();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetClosestPoints();
void __cdecl hkpListAgent_initAgentFunc(void* apObject);
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl FUN_00d3e110(void);
void __cdecl FUN_00d3ac80(void);
struct CollisionAgentFunctionTable {
    void* a;
    void* b;
    void* c;
    void* d;
    char e;
    char f;
};
struct Agent {
    void FUN_00cfbbe0(CollisionAgentFunctionTable*, int, int);
};
void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
struct D28030FixedArray {
    int* m_data;
    int m_iElementCount;

    int& operator[](int i) { return m_data[i]; }
};
struct D28030UnionFind {
    D28030FixedArray& m_pParentArray;

    __forceinline int _findRootOfNode(int i)
    {
        int root = i;
        while (m_pParentArray[root] >= 0)
            root = m_pParentArray[root];
        while (m_pParentArray[i] >= 0) {
            int j = m_pParentArray[i];
            m_pParentArray[i] = root;
            i = j;
        }
        return i;
    }

    void Union(int i, int j);
};
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct AllocationManager { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
AllocationManager* __cdecl FUN_00c85750();
struct hkMemAllocStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& sizeInOut);
    virtual void ReturnMemory(void* p, int size);

    int* bufAllocInts(int& n)
    {
        int s = n * 4;
        void* p = AllocateBufferWithSize(s);
        n = s / 4;
        return (int*)p;
    }
};
struct hkMemCtxStub
{
    int unk00;
    int unk04;
    int unk08;
    hkMemAllocStub* alloc;
    void* mem;

    hkMemAllocStub& temp() { return *alloc; }
    void* heap() { return mem; }
};
void ArrayReserveImpl(void* mem, void* arr, int numElem, int elemSize);
struct IntArrayStub
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void reserveWith(void* mem, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            ArrayReserveImpl(mem, this, n < cap2 ? cap2 : n, 4);
        }
    }
    void setSizeWith(void* mem, int n)
    {
        reserveWith(mem, n);
        m_iElementCount = n;
    }
};
typedef void (__cdecl *D2F2C0Func)();
void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern float DAT_0104da48;
class D37B90Collector {
public:
    D37B90Collector(int iFilter) : m_fEarlyOutDistance(DAT_0104da48), m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    float m_fEarlyOutDistance;
    int m_iFilter;
};
void __cdecl ReleaseHandles(int a1, int a2, int a3, int a4);
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern float DAT_0104da48;
struct S_00d3f4c0_Obj {
    virtual void vfn0();
    float unk04;
    int unk08;
    S_00d3f4c0_Obj(int a) : unk04(DAT_0104da48), unk08(a) {}
};
void __cdecl FUN_00d3fce0(CollisionAgentFunctionTable*);
template <class T> class hkArrayD27 {
public:
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
extern int DAT_010ce81c;
typedef void (*CallbackD3D)();
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();
struct AgentFuncsD3D {
    AgentFuncsD3D() : m_bA(false), m_bB(false) {}

    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
static __declspec(noinline) void InitFuncsB(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateRetObj;
    pkFuncs->m_pfnB = FUN_00d3d3e0;
    pkFuncs->m_pfnC = FUN_00d3d8c0;
    pkFuncs->m_pfnD = FUN_00daf8e0;
    pkFuncs->m_bA = false;
    pkFuncs->m_bB = false;
}
static __declspec(noinline) void InitFuncsA(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateTargetAgent;
    pkFuncs->m_pfnB = QueryD3DCollector;
    pkFuncs->m_pfnC = FUN_00d3e110;
    pkFuncs->m_pfnD = FUN_00d3ac80;
    pkFuncs->m_bA = true;
    pkFuncs->m_bB = false;
}
void (*g_apfnInitD3D[2])(AgentFuncsD3D*) = { InitFuncsA, InitFuncsB };
class FUN_00d2c7e0 {
public:
    virtual ~FUN_00d2c7e0();
    FUN_00d2c7e0(int count);
};
class ObjD2C840 : public FUN_00d2c7e0 {
public:
    virtual ~ObjD2C840();
    ObjD2C840(int count) : FUN_00d2c7e0(count) {}
    static void* operator new(unsigned int, void* p) throw() { return p; }
    static void operator delete(void*, void*) throw() {}
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern int DAT_010ce81c;
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
typedef void (*CallbackD3D)();
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();
struct D390Callback {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(unsigned int key, void* context);
};
struct D390HandleTable {
    unsigned short handles[3];
    unsigned short state06;
    unsigned short state08;
    unsigned short state0a;
    unsigned short state0c;
    unsigned short state0e;
    unsigned short state10;
    unsigned short state12;
    unsigned short state14;
    unsigned short state16;
    unsigned short state18;
    unsigned short state1a;
    unsigned short state1c;
    unsigned short state1e;
    unsigned short state20;
};
unsigned short* __cdecl ReleaseHandles(void* unused, D390HandleTable* handles, D390Callback* callback, void* context);
struct D3FD30Funcs {
    D3FD30Funcs() : m_bA(false), m_bB(false) {}
    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
void __cdecl FUN_00d3fce0(D3FD30Funcs* pkFuncs);
class hkMemoryAllocatorD262 {
public:
    virtual ~hkMemoryAllocatorD262() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD262 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD262* m_pStreamAllocator;
    hkMemoryAllocatorD262& heap() { return *m_pStreamAllocator; }
};
namespace hkRouterD262 {
    extern "C" hkMemoryRouterD262& __cdecl FUN_00c85750() throw();
}
class FUN_00d496d0 {
public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00d24660() throw();

    static void operator delete(void* p) throw()
    {
        hkRouterD262::FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d496d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d496d0* FUN_00d262e0(unsigned int uiFlags) throw();
};
void hkAgent1nMachine_InvalidateTim(void*, void*);
extern unsigned char DAT_011b4284;
extern unsigned char DAT_011b4284;
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetClosestPoints();
void __cdecl QueryClosestPoints(void* a, void* b, void* c, unsigned int filter);
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern int DAT_010ce81c;
// CreateRetObj: builds a 0x20-byte record from the audio allocation pool.
void* __cdecl CreateRetObj(int a1, char** a2, int a3, int a4);
struct D3E270_obj;
struct D3E270_alloc {
    virtual void v00();
    virtual D3E270_obj* alloc(int size);
};
struct D3E270_obj {
    D3E270_alloc* vt;
    unsigned short f04;
    unsigned short f06;
    int f08;
    unsigned short f0c;
};
#include <xmmintrin.h>
extern float DAT_01011d78;
extern float DAT_01016248;
extern float DAT_01017718;
namespace sd21cc0 {

}
struct __declspec(align(16)) Vector4D22DC0 {
    float x;
    float y;
    float z;
    float w;
    void setZero4() { *reinterpret_cast<__m128*>(this) = _mm_setzero_ps(); }
    void operator=(const Vector4D22DC0& kOther) { *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther); }
};
struct RotationD22DC0 {
    Vector4D22DC0 m_kColumn0;
    Vector4D22DC0 m_kColumn1;
    Vector4D22DC0 m_kColumn2;
    float& operator()(int iRow, int iCol) { return reinterpret_cast<float*>(&m_kColumn0 + iCol)[iRow]; }
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct TransformD22DC0 {
    RotationD22DC0 m_rotation;
    Vector4D22DC0 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct ReferencedD22DC0 {
    ReferencedD22DC0() throw() { m_sReferenceCount = 1; }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0 {
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType) { m_kMotionTransform.setIdentity(); }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    TransformD22DC0 m_kMotionTransform;
    int m_type;
};
struct E48 { int a[12]; };
extern "C" void __cdecl FUN_00d06c30(void* self, int newCap, int elemSize);
struct hkSmallArrayE {
    E48* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void reserve(int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00d06c30(this, newSize, sizeof(E48));
        }
    }
    void Insert(int i, const E48* a, int numtoinsert);
};
struct S00d281b0_Alloc {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T>
    __forceinline void _bufFree(T* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};
struct S00d281b0_Router {
    unsigned int unk00, unk04, unk08;
    S00d281b0_Alloc* allocator;
    S00d281b0_Alloc& heap() { return *allocator; }
};
extern __declspec(thread) unsigned int t_uiMemContextB110;
inline unsigned int GetMemContextB110()
{
    return t_uiMemContextB110;
}
inline void SetMemContextB110(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextB110 = m_uiGeometryShaderFlags;
}
class AutoMemContextB110 {
public:
    AutoMemContextB110(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextB110();
        SetMemContextB110(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextB110() { SetMemContextB110(m_uiPrevious); }
    unsigned int m_uiPrevious;
};
struct hkVector4B110 {
    inline hkVector4B110& operator=(const hkVector4B110& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __m128 m_vComponents;
};
class hkMemoryAllocatorB110 {
public:
    virtual ~hkMemoryAllocatorB110();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterB110 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorB110& heap() { return *m_pStreamAllocator; }
    hkMemoryAllocatorB110* m_pStreamAllocator;
};
hkMemoryRouterB110* __cdecl GetMemoryRouterB110();
class hkReferencedObjectB110 {
public:
    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(GetMemoryRouterB110()->heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(p);
        GetMemoryRouterB110()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~hkReferencedObjectB110();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct ShapeB110;
struct BodyB110 {
    ShapeB110* getShape() const { return m_pCollisionShape; }
    ShapeB110* m_pCollisionShape;
};
extern __declspec(thread) unsigned int t_uiMemContextD2C9;
inline unsigned int GetMemContextD2C9()
{
    return t_uiMemContextD2C9;
}
inline void SetMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextD2C9 = m_uiGeometryShaderFlags;
}
class AutoMemContextD2C9 {
public:
    AutoMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextD2C9();
        SetMemContextD2C9(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextD2C9() { SetMemContextD2C9(m_uiPrevious); }
    unsigned int m_uiPrevious;
};
struct hkMemoryAllocatorD2C9 {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterD2C9 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD2C9* m_pStreamAllocator;

    hkMemoryAllocatorD2C9& heap() { return *m_pStreamAllocator; }
};
struct RouterD2C9 {
    static hkMemoryRouterD2C9& __cdecl FUN_00c85750() throw();
};
struct __declspec(align(16)) hkVector4D2C9 {
    __m128 m_vComponents;
    inline hkVector4D2C9& operator=(const hkVector4D2C9& v) { m_vComponents = v.m_vComponents; return *this; }
};
class hkReferencedObjectD2C9 {
public:
    virtual ~hkReferencedObjectD2C9();

    void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD2C9* b = static_cast<hkReferencedObjectD2C9*>(RouterD2C9::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    void operator delete(void* p, unsigned int nbytes)
    {
        RouterD2C9::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct RequestD2C9 {
    int* m_pName;
    int m_iKind;
    int GetName() const { return *m_pName; }
    int* GetNamePtr() const { return m_pName; }
};
extern float DAT_0104da48;
struct Vec { int x, y, z, w; };
struct Src {
    int u[20];
    Vec v;
    int t0, t1, t2, t3;
};
struct Q {
    int* vt;
    float d;
    int p1, p2;
    Vec v;
    int x;
    int t1, t2, t3;
};
void __cdecl FUN_00d2f0d0();
typedef void (__cdecl *Fn)(int, int, Src*, Q*, Q*);
void __cdecl FUN_00d2daf0(int a, int b, Src* c, int d, int e);
extern "C" void _ReadWriteBarrier();
struct ShapeD2F630 {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct CdBodyD2F630 {
    ShapeD2F630* m_pCollisionShape;
};
struct InputD2F630;
struct CollectorD2F630;
typedef void (__cdecl *AgentFuncD2F630)(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector);
struct AgentFuncsD2F630 {
    AgentFuncD2F630 m_pQueryPenetrationsFunc;
    void* m_func04;
    void* m_func08;
    void* m_func0C;
    void* m_func10;
};
struct DispatcherD2F630 {
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
    unsigned char m_agentTypes[32][32];
    unsigned char m_agentTypesPred[32][32];
    AgentFuncsD2F630 m_agentFuncs[32];
};
struct InputD2F630 {
    DispatcherD2F630* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_createPredictive;
};
extern "C" __m128 DAT_010c4c00;
extern "C" void _ReadWriteBarrier(void);
class hkVector4 {
public:
    __m128 m_vComponents;

    __forceinline hkVector4 getSimdAt3() const {
        hkVector4 r;
        r.m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    __forceinline void addMul4(const hkVector4& a, const hkVector4& b) {
        m_vComponents = _mm_add_ps(_mm_mul_ps(a.m_vComponents, b.m_vComponents), m_vComponents);
    }
    __forceinline static void setNeg4(hkVector4& dst, const hkVector4& a, const __m128& neg) {
        dst.m_vComponents = _mm_xor_ps(a.m_vComponents, neg);
    }
};
struct Point {
    hkVector4 m_pos;
    hkVector4 m_vHitNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    __forceinline void flip() {
        m_pos.addMul4(m_vHitNormal.getSimdAt3(), m_vHitNormal);
        hkVector4::setNeg4(m_vHitNormal, m_vHitNormal, DAT_010c4c00);
    }
};
extern "C" void __cdecl hkAgent1nMachine_InvalidateTim(int, int);
struct D36B70_Heap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct FUN_00d36b20
{
    void* unk00;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    static __forceinline void* operator new(unsigned int size) throw()
    {
        AllocationManager* manager = FUN_00c85750();
        FUN_00d36b20* object = static_cast<FUN_00d36b20*>(static_cast<D36B70_Heap*>(manager->allocator)->AllocateMemoryBlock(size));
        object->m_usMemSizeAndFlags = (unsigned short)size;
        return object;
    }
    FUN_00d36b20(int param1, int param2, int* param3, int param4) throw();
};
FUN_00d36b20* FUN_00d36b70(int param1, int param2, int* param3, int param4);
#include <xmmintrin.h>
class hkpCdBody;
class CollisionAgentContext;
// Explicit layout of the audited collector objects; table objects stay external.
struct hkpCdBodyPairCollector {
    const void* unk00;
    unsigned char unk04;
};
template<class Agent> class hkpSymmetricAgent : public Agent {
public:
    void FUN_00d36d20(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;
extern volatile float DAT_01012054;
struct Body11
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};
class __declspec(align(16)) FUN_00d01a60
{
public:
    Body11 m_kCollisionBody;
    float m_unk2C;
    FUN_00d01a60();
};
struct __declspec(align(16)) V4q
{
    int m0;
    int m1;
    int m2;
    int m3;
};
struct A1Rec
{
    void* unk00;
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
    V4q unk70;
};
struct BroadPhaseHandle
{
    int unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    int unk1C;
    __forceinline void SetOwnerPointer(void* owner)
    {
        unk19 = (unsigned char)((unsigned int)owner - (unsigned int)this);
    }
};
struct __declspec(align(16)) ZT
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    BroadPhaseHandle handle;
    __forceinline ZT()
    {
        unk00 = 0;
        unk08 = 0;
        unk0C = 0;
        unk04 = -1;
        unk10 = 0;
        handle.unk14 = 0;
        handle.unk18 = 0;
        handle.unk1C = 0;
        handle.unk1A = 0xff;
        handle.unk19 = 0x7f;
    }
};
struct CollidableBuffer
{
    ZT z;
    FUN_00d01a60 o40;
    __forceinline CollidableBuffer()
    {
        o40.m_unk2C = DAT_01012054;
        z.handle.SetOwnerPointer(&z);
        z.unk11 = 0;
        z.unk12 = 0;
    }
};
struct __declspec(align(16)) O1T
{
    void* FUN_00d33260(A1Rec* a1);
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
struct __declspec(align(16)) CF56Obj
{
    void* FUN_00cf5640(int* c, int b, void* a);
    void* unk00;
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
};
class FUN_00cf5640
{
public:
    FUN_00cf5640(int* name, int count, void* extra);
    virtual ~FUN_00cf5640();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};
static __forceinline int maxSize(int minimum, int value) {
    _ReadWriteBarrier();
    return value <= minimum ? minimum : value;
}
int FUN_00d365d0(A1Rec* a1, int a2, int a3, int a4, int a5);
__declspec(noinline) void __cdecl hkpListAgent_initAgentFunc(void* apObject);

#include <xmmintrin.h>

extern const __m128 DAT_010c71e0;
extern const __m128 DAT_01017d10;

struct SimdScalar {
    __m128 value;
    __forceinline SimdScalar(__m128 v) : value(v) {}
    __forceinline operator float() const { float f; _mm_store_ss(&f, value); return f; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(value, value, 0); }
};

struct hkVecQ {
    __m128 data;
    __forceinline __m128& getQuad() { return data; }
    __forceinline const __m128& getQuad() const { return data; }

    __forceinline float& operator()(int a) { return getQuad().m128_f32[a]; }
    __forceinline const float& operator()(int a) const { return getQuad().m128_f32[a]; }

    static __forceinline __m128 rotated(const hkVecQ& q, const hkVecQ& v)
    {
        __m128 w = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xff);
        __m128 w2 = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
        __m128 t1 = _mm_mul_ps(w2, v.getQuad());
        __m128 qv = _mm_mul_ps(v.getQuad(), q.getQuad());
        __m128 s1 = _mm_add_ss(_mm_shuffle_ps(qv, qv, 0x55), qv);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(qv, qv, 0xaa), s1);
        __m128 q2 = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xd2);
        __m128 q1 = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xc9);
        __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(v.getQuad(), v.getQuad(), 0xc9), q2);
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v.getQuad(), v.getQuad(), 0xd2), q1);
        __m128 cross = _mm_sub_ps(c1, c2);
        __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q.getQuad());
        __m128 sum = _mm_add_ps(_mm_mul_ps(cross, w), _mm_add_ps(t1, t2));
        return _mm_add_ps(sum, sum);
    }

    static __forceinline SimdScalar dot(__m128 a, __m128 b)
    {
        __m128 p = _mm_mul_ps(a, b);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return SimdScalar(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    }

    __forceinline void setAddMul4(const hkVecQ& a, __m128 b, float r)
    {
        __m128 s = _mm_load_ss(&r);
        getQuad() = _mm_add_ps(a.getQuad(), _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b));
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(getQuad(), getQuad());
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        __m128 lenSq = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        __m128 r = _mm_rsqrt_ss(lenSq);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 nr = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(lenSq, r), r));
        __m128 sc = _mm_mul_ss(_mm_mul_ss(half, r), nr);
        __m128 sel = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, zero), sc);
        getQuad() = _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), getQuad());
    }

    __forceinline void setCross(const hkVecQ& a, const hkVecQ& b)
    {
        __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xc9), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xd2), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xc9));
        getQuad() = _mm_sub_ps(c1, c2);
    }

    __forceinline void setAbs4(const hkVecQ& a)
    {
        getQuad() = _mm_and_ps(a.getQuad(), DAT_01017d10);
    }

    __forceinline int getMajorAxis(hkVecQ& tmp) const
    {
        tmp.setAbs4(*this);
        return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
    }

    __forceinline void setMul4(float r, const hkVecQ& a)
    {
        __m128 s = _mm_load_ss(&r);
        getQuad() = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), a.getQuad());
    }
};

struct hkpMotionStub {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void ApplyAngularImpulseToBodies(const hkVecQ& imp);

    int unk04, unk08, unk0c;
    hkVecQ unk10, unk20, unk30, unk40, unk50, unk60;
    hkVecQ m_rotation;
    hkVecQ unk90, unka0, unkb0, unkc0, unkd0;
    hkVecQ m_kAngularVelocity;
};

struct hkpRigidBodyStub {
    hkVecQ unk00, unk10, unk20, unk30, unk40, unk50, unk60;
    hkVecQ unk70, unk80, unk90, unka0, unkb0, unkc0, unkd0;
    hkpMotionStub m_pMotionState;

    void __thiscall FUN_00c9c1d0();

    __forceinline void ApplyAngularImpulseToBodies(const hkVecQ& imp)
    {
        FUN_00c9c1d0();
        m_pMotionState.ApplyAngularImpulseToBodies(imp);
    }
};

namespace S00d386c0_N {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; };
extern "C" {
__m128 _mm_load_ss(const float*);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
}
}
typedef S00d386c0_N::__m128 S00d386c0_Quad;

extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}

struct S00d386c0_TimerCommand
{
    const char* m_kStringBuffer;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};

struct S00d386c0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static S00d386c0_MonitorStream& GetMonitorStream() { return *(S00d386c0_MonitorStream*)TlsGetValue(DAT_0126835c); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    char* GetStreamEnd() { return m_kRayEnd; }
    void setEnd(char* e) { m_kRayEnd = e; }
};

static __forceinline void S00d386c0_timer(const char* name)
{
    S00d386c0_MonitorStream& mStream = S00d386c0_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S00d386c0_TimerCommand* h = (S00d386c0_TimerCommand*)mStream.GetStreamEnd();
        h->m_kStringBuffer = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

struct S00d386c0_SimdReal
{
    S00d386c0_Quad m_vValue;
    __forceinline S00d386c0_SimdReal(float x) { m_vValue = S00d386c0_N::_mm_load_ss(&x); }
    __forceinline S00d386c0_Quad broadcast() const { return S00d386c0_N::_mm_shuffle_ps(m_vValue, m_vValue, 0); }
};

struct S00d386c0_Transform;

struct __declspec(align(16)) S00d386c0_Vector4
{
    S00d386c0_Quad m_vComponents;

    __forceinline S00d386c0_Vector4() {}
    __forceinline void operator=(const S00d386c0_Vector4& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }

    __forceinline void setAddMul4(const S00d386c0_Vector4& a, const S00d386c0_Vector4& b, const S00d386c0_SimdReal& r)
    {
        m_vComponents = S00d386c0_N::_mm_add_ps(a.m_vComponents, S00d386c0_N::_mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void _setTransformedPos(const S00d386c0_Transform& t, const S00d386c0_Vector4& b);
};

struct S00d386c0_Matrix3
{
    S00d386c0_Vector4 m_kColumn0;
    S00d386c0_Vector4 m_kColumn1;
    S00d386c0_Vector4 m_kColumn2;
    __forceinline S00d386c0_Matrix3() {}
    S00d386c0_Vector4& getColumn(int x) { return (&m_kColumn0)[x]; }
    const S00d386c0_Vector4& getColumn(int x) const { return (&m_kColumn0)[x]; }
};

struct S00d386c0_Transform
{
    S00d386c0_Matrix3 m_rotation;
    S00d386c0_Vector4 m_vTranslation;

    __forceinline S00d386c0_Transform(const S00d386c0_Transform& t)
    {
        const S00d386c0_Vector4 r0 = t.m_rotation.getColumn(0);
        const S00d386c0_Vector4 r1 = t.m_rotation.getColumn(1);
        const S00d386c0_Vector4 r2 = t.m_rotation.getColumn(2);
        const S00d386c0_Vector4 r3 = t.m_rotation.getColumn(3);
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_rotation.getColumn(3) = r3;
    }
    const S00d386c0_Matrix3& getRotation() const { return m_rotation; }
    const S00d386c0_Vector4& getTranslation() const { return m_vTranslation; }
};

__forceinline void S00d386c0_Vector4::_setTransformedPos(const S00d386c0_Transform& t, const S00d386c0_Vector4& b)
{
    const S00d386c0_Matrix3& r = t.getRotation();
    S00d386c0_Quad b0 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    S00d386c0_Quad r0 = S00d386c0_N::_mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    S00d386c0_Quad b1 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    S00d386c0_Quad r1 = S00d386c0_N::_mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    S00d386c0_Quad b2 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    S00d386c0_Quad r2 = S00d386c0_N::_mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = S00d386c0_N::_mm_add_ps(S00d386c0_N::_mm_add_ps(r0, r1), S00d386c0_N::_mm_add_ps(r2, t.getTranslation().m_vComponents));
}

static __forceinline void S00d386c0_transformPoints(const S00d386c0_Transform& t, const S00d386c0_Vector4* vectorsIn, int numVectors, S00d386c0_Vector4* vectorsOut)
{
    S00d386c0_Transform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

template <typename T> struct S00d386c0_PadSpu
{
    T m_kStorage;
    operator T() const { return m_kStorage; }
};

struct S00d386c0_Shape
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

struct S00d386c0_ConvexShape : S00d386c0_Shape
{
    float m_fSphereRadius;
    float getRadius() const { return m_fSphereRadius; }
};

struct S00d386c0_TriangleShape : S00d386c0_ConvexShape
{
    int unk14;
    int unk18;
    int unk1c;
    S00d386c0_Vector4 m_kVertexA;
    S00d386c0_Vector4 m_kVertexB;
    S00d386c0_Vector4 m_kVertexC;
    const S00d386c0_Vector4* GetIndexedVertices() const { return &m_kVertexA; }
};

struct S00d386c0_MultiSphereShape : S00d386c0_Shape
{
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1c;
    S00d386c0_Vector4 m_kSpheres[8];
    const S00d386c0_Vector4* getSpheres() const { return m_kSpheres; }
    int getNumSpheres() const { return m_iSphereCount; }
};

struct S00d386c0_CdBody
{
    const S00d386c0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S00d386c0_CdBody* m_parent;
    const S00d386c0_Shape* getShape() const { return m_pCollisionShape; }
    const S00d386c0_Transform& getTransform() const { return *static_cast<const S00d386c0_Transform*>(m_pMotionState); }
};

struct S00d386c0_CollisionInput
{
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    S00d386c0_PadSpu<float> m_fScalar;
    float getTolerance() const { return m_fScalar; }
};

struct S00d386c0_ContactPoint
{
    S00d386c0_Vector4 m_vContactPosition;
    S00d386c0_Vector4 m_vSeparatingNormal;

    S00d386c0_Vector4& getPosition() { return m_vContactPosition; }
    void setSeparatingNormal(const S00d386c0_Vector4& normal, float dist)
    {
        m_vSeparatingNormal = normal;
        m_vSeparatingNormal(3) = dist;
    }
};

struct S00d386c0_CdPoint
{
    S00d386c0_ContactPoint m_kPoint;
    const S00d386c0_CdBody& m_pBodyA;
    const S00d386c0_CdBody& m_pBodyB;
    S00d386c0_CdPoint(const S00d386c0_CdBody& a, const S00d386c0_CdBody& b) : m_pBodyA(a), m_pBodyB(b) {}
    S00d386c0_ContactPoint& getContact() { return m_kPoint; }
};

struct S00d386c0_CdPointCollector
{
    virtual ~S00d386c0_CdPointCollector();
    virtual void AddCdPoint(const S00d386c0_CdPoint& event);
};

// @f3 0x009c7730 (community match, verified in this file)
// 0x009c7730: hkpSphereTriangleAgent::staticGetClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
// const hkpCollisionInput& input, hkpCdPointCollector& collector) of Havok 5.5.0 (hkpCollide, compiled with
// /MT /Ox /Ob1 /Oi /Ot /GF /GS-).
// The static form of the sphere against triangle query: sets up the triangle's closest-point cache on the spot,
// takes the triangle's vertices to world space, asks the triangle utility for the closest point of the sphere's
// centre and hands the point, when it is within the radii plus the tolerance, to the collector with the two
// bodies. A timer brackets it.
// Class and member names follow the Havok 5.5.0 SDK headers; the helper forms (the vector helpers, the
// transform's copy, transformPoints, the contact point's accessors, the timer commands as the SDK's macros expand)
// follow the SDK's inline code for the x87 build. The function's own body and the body of its inline
// closest-point helper are written from the game's code; local names and the order of the statements follow the
// debug records of the SDK's library object.
// The unit declares this function as FUN_00d386c0 with its own stand-in parameter types; the definition keeps
// that declaration and sees the parameters as the Havok types through inline casts at each use.
// The timer reads the clock with the project's accepted two-instruction block (kit/compiler_tips.md, "Timer slot
// still off"), as the SDK's own inline timer code does; it is the only difference from the plain counter-read
// source.
namespace f3m_009c7730 {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef float hkReal;
typedef hkReal hkSimdRealParameter;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

template <typename T> struct hkPadSpu
{
    operator T() const { return m_storage; }
    T val() const { return m_storage; }
    void operator=(T t) { m_storage = t; }

    T m_storage;
};

extern unsigned int DAT_0116913c;  // thread-local slot of the thread's hkMonitorStream

class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }

private:
    char m_bool;
};

struct hkMonitorStream
{
    struct Command
    {
        const char* m_commandAndMonitor;
    };
    struct TimerCommand : Command
    {
        // the low half of the time stamp counter
        __forceinline void setTime()
        {
            hkUint32 ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            m_time0 = ticks;
        }

        hkUint32 m_time0;
        hkUint32 m_time1;
    };

    static hkMonitorStream& getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0116913c); }
    __forceinline char* getEnd() { return m_end.val(); }
    __forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
    __forceinline hkBool memoryAvailable() { return getEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_end = ptr; }

    hkPadSpu<char*> m_start;
    hkPadSpu<char*> m_end;
    hkPadSpu<char*> m_capacity;
    hkPadSpu<char*> m_capacityMinus16;
};

struct hkTransform;

struct hkVector4
{
    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    inline void operator=(const hkVector4& v);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& v);

    __declspec(align(16)) hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

inline void hkVector4::operator=(const hkVector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    x = a.x + r * b.x;
    y = a.y + r * b.y;
    z = a.z + r * b.z;
    w = a.w + r * b.w;
}

struct hkMatrix3
{
    __forceinline hkVector4& getColumn(int i) { return (&m_col0)[i]; }
    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int row, int col) const { return getColumn(col)(row); }

    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline const hkReal& operator()(int row, int column) const { return m_rotation(row, column); }
    __forceinline const hkVector4& getTranslation() const { return m_translation; }

    hkRotation m_rotation;
    hkVector4 m_translation;
};

// the translation is the rotation's fourth column
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& v)
{
    hkReal v0 = v(0);
    hkReal v1 = v(1);
    hkReal v2 = v(2);
    hkVector4& d = *this;
    d(0) = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    d(1) = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    d(2) = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    d(3) = 0;
}

namespace hkVector4Util {
// transforms numVectors points, the last one first; the transform is copied so that the output may alias it
__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                   hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}  // namespace hkVector4Util

struct hkpShape
{
    virtual ~hkpShape();

    hkUint16 m_memSizeAndFlags;
    short m_referenceCount;
    unsigned long m_userData;
    hkUint32 m_type;
};

struct hkpConvexShape : hkpShape
{
    __forceinline hkReal getRadius() const { return m_radius; }

    hkReal m_radius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpTriangleShape : hkpConvexShape
{
    __forceinline const hkVector4* getVertices() const { return &m_vertexA; }

    hkUint16 m_weldingInfo;
    unsigned char m_weldingType;
    unsigned char m_isExtruded;
    hkVector4 m_vertexA;
    hkVector4 m_vertexB;
    hkVector4 m_vertexC;
};

struct hkpCdBody
{
    __forceinline const hkpShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *static_cast<const hkTransform*>(m_motion); }

    const hkpShape* m_shape;
    hkUint32 m_shapeKey;
    const void* m_motion;
    const hkpCdBody* m_parent;
};

struct hkpCollisionDispatcher;

struct hkpCollisionInput
{
    __forceinline hkReal getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<hkReal> m_tolerance;
};

struct hkContactPoint
{
    __forceinline hkVector4& getPosition() { return m_position; }
    __forceinline hkVector4& getSeparatingNormal() { return m_separatingNormal; }
    __forceinline void setDistance(hkReal d) { m_separatingNormal(3) = d; }

    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

// a contact point with the two bodies it belongs to
struct hkpCdPoint
{
    __forceinline hkpCdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_cdBodyA(a), m_cdBodyB(b) {}

    hkContactPoint m_contact;
    const hkpCdBody& m_cdBodyA;
    const hkpCdBody& m_cdBodyB;
};

struct hkpCdPointCollector
{
    virtual ~hkpCdPointCollector();
    virtual void addCdPoint(const hkpCdPoint& point) = 0;

    hkReal m_earlyOutDistance;
};

namespace hkpCollideTriangleUtil {
struct ClosestPointTriangleCache
{
    hkReal m_QQ;
    hkReal m_RR;
    hkReal m_QR;
    hkReal m_invTriNormal;
};

struct ClosestPointTriangleResult
{
    hkVector4 hitDirection;
    hkPadSpu<hkReal> distance;
};

enum ClosestPointTriangleStatus
{
    HIT_TRIANGLE_FACE = 0,
    HIT_TRIANGLE_EDGE
};

// setupClosestPointTriangleCache
void __cdecl FUN_0096fbc0(const hkVector4* tri, ClosestPointTriangleCache& cache);

// closestPointTriangle
ClosestPointTriangleStatus __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* tri,
                                                const ClosestPointTriangleCache& cache,
                                                ClosestPointTriangleResult& result);
}  // namespace hkpCollideTriangleUtil

struct hkpSphereTriangleAgent
{
    enum ClosestPointResult
    {
        ST_CP_MISS,
        ST_CP_FACE,
        ST_CP_EDGE
    };

    static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                               const hkpCollisionInput& input,
                                                               hkpCollideTriangleUtil::ClosestPointTriangleCache& cache,
                                                               hkContactPoint& cpoint);
};

// the unit's stand-in parameter types seen as the Havok types they stand for (the layouts are the same)
__forceinline const hkpCdBody& asCdBody(const S00d386c0_CdBody& body)
{
    return reinterpret_cast<const hkpCdBody&>(body);
}
__forceinline const hkpCollisionInput& asCollisionInput(const S00d386c0_CollisionInput& input)
{
    return reinterpret_cast<const hkpCollisionInput&>(input);
}
__forceinline hkpCdPointCollector& asCollector(S00d386c0_CdPointCollector& collector)
{
    return reinterpret_cast<hkpCdPointCollector&>(collector);
}

__forceinline hkpSphereTriangleAgent::ClosestPointResult hkpSphereTriangleAgent::getClosestPointInl(
    const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input,
    hkpCollideTriangleUtil::ClosestPointTriangleCache& cache, hkContactPoint& cpoint)
{
    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.getShape());
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.getShape());

    const hkVector4& posA = bodyA.getTransform().getTranslation();

    hkVector4 triVertices[3];
    hkVector4Util::transformPoints(bodyB.getTransform(), triB->getVertices(), 3, &triVertices[0]);

    hkpCollideTriangleUtil::ClosestPointTriangleResult cptr;
    hkpCollideTriangleUtil::ClosestPointTriangleStatus res =
        hkpCollideTriangleUtil::hkpCollideTriangleUtil_closestPointTriangle(posA, &triVertices[0], cache, cptr);

    const hkReal radiusSum = sphereA->getRadius() + triB->getRadius();

    if (cptr.distance < radiusSum + input.getTolerance())
    {
        cpoint.getPosition().setAddMul4(posA, cptr.hitDirection, triB->getRadius() - cptr.distance);
        cpoint.getSeparatingNormal() = cptr.hitDirection;
        cpoint.setDistance(cptr.distance - radiusSum);
        if (res == hkpCollideTriangleUtil::HIT_TRIANGLE_FACE)
        {
            return ST_CP_FACE;
        }
        return ST_CP_EDGE;
    }
    return ST_CP_MISS;
}

}  // namespace f3m_009c7730

// hkpSphereTriangleAgent::staticGetClosestPoints, under the name and parameter types the unit declares for it
// pdb: hkpSphereTriangleAgent::staticGetClosestPoints | hkpSphereTriangleAgent.obj | fnv360_1110_retail, objrun, medium
// pdb params: bodyA, bodyB, input, collector
void __cdecl FUN_00d386c0(const S00d386c0_CdBody& bodyA, const S00d386c0_CdBody& bodyB, const S00d386c0_CollisionInput& input, S00d386c0_CdPointCollector& collector)
{
    namespace hk = f3m_009c7730;

    {
        hk::hkMonitorStream& mStream = hk::hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hk::hkMonitorStream::TimerCommand* h =
                reinterpret_cast<hk::hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtSphereTri";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }

    hk::hkpCollideTriangleUtil::ClosestPointTriangleCache cache;
    {
        const hk::hkpTriangleShape* triB = static_cast<const hk::hkpTriangleShape*>(hk::asCdBody(bodyB).getShape());
        hk::hkpCollideTriangleUtil::FUN_0096fbc0(triB->getVertices(), cache);
    }

    hk::hkpCdPoint event(hk::asCdBody(bodyA), hk::asCdBody(bodyB));

    if (hk::hkpSphereTriangleAgent::getClosestPointInl(hk::asCdBody(bodyA), hk::asCdBody(bodyB),
                                                       hk::asCollisionInput(input), cache, event.m_contact) !=
        hk::hkpSphereTriangleAgent::ST_CP_MISS)
    {
        hk::asCollector(collector).addCdPoint(event);
    }

    {
        hk::hkMonitorStream& mStream = hk::hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hk::hkMonitorStream::TimerCommand* h =
                reinterpret_cast<hk::hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}
