#include "f3_common.h"
// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);
extern "C" void* DAT_010ccf7c;

struct FUN_00d08330 {
    void* m_p;
    FUN_00d08330(char);
};

// @fnv 0x00d08330
// pdb: `anonymous namespace'::NearestHitCollector::`scalar deleting destructor' | hkpSampledHeightFieldShape.obj | fnv360_0822_retail, vtable, high
FUN_00d08330::FUN_00d08330(char acFlags)
{
    m_p = &DAT_010ccf7c;
    if (acFlags & 1)
        Deallocate(this);
}

extern int DAT_010ccf8c;
extern void __cdecl Deallocate(void*);

struct FUN_00d08350 {
    void* m_p;
    void* __thiscall Set(void* arg);
};

// Stores the address of DAT_010ccf8c into m_p and, if arg's low bit is set, deallocates self before returning it.
// @fnv 0x00d08350
void* __thiscall FUN_00d08350::Set(void* arg)
{
    void* self = this;
    m_p = &DAT_010ccf8c;
    if ((int)arg & 1)
        Deallocate(self);
    return self;
}

struct FUN_00d08ff0_t {
    int a;
    int b;
    int c;
    int d;
    void FUN_00d08ac0(int);
    void FUN_00d08b90(int);
};
void FUN_00d08ac0(FUN_00d08ff0_t* self, int arg);
void FUN_00d08b90(FUN_00d08ff0_t* self, int arg);
// Clears self->b, then calls FUN_00d08ac0 and FUN_00d08b90 with self and arg.
// @f3 0x006f76d0 (community match, verified in this file)
struct Sub6f76d0 {
    int FUN_005a29a0(int);
};

int __cdecl FUN_005855b0(int, int);

struct Real00d08ff0 {
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
    Sub6f76d0 sub;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual int Get(Real00d08ff0*, int);
};

// pdb: Actor::GetSellValuePercentage | Actor.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: PathingStreamScrapMaps::~PathingStreamScrapMaps)
// pdb params: apActor
void __stdcall FUN_00d08ff0(FUN_00d08ff0_t* self)
{
    int r = ((Real00d08ff0*)self)->sub.FUN_005a29a0(0x20);
    FUN_005855b0(r, ((Real00d08ff0*)self)->Get((Real00d08ff0*)self, 0));
}


extern int DAT_010ccfac;
void __cdecl Deallocate(void*);
struct FUN_00d0a150 {
    int* p;
    FUN_00d0a150(bool b);
};
// @fnv 0x00d0a150
// pdb: hkProcessHandler::`scalar deleting destructor' | hkServerProcessHandler.obj | fnv360_0822_retail, vtable, medium
FUN_00d0a150::FUN_00d0a150(bool abFree)
{
    p = &DAT_010ccfac;
    if (abFree & 1) Deallocate(this);
}

extern int DAT_010ccfa0;
extern int DAT_010ccfac;
extern "C" void __cdecl Deallocate(void*);

struct FUN_00d0a1a0 {
    int* a;
    int* b;
    int __thiscall Init(int p);
};

// Sets a and b to the addresses of two globals, frees this if p has bit 0 set, and returns this.
// @f3 0x00a649d0 (community match, verified in this file)
extern int DAT_00e86ec8;
int __thiscall FUN_00d0a1a0::Init(int aiFlags)
{
    a = &DAT_00e86ec8;
    b = 0;
    if (aiFlags & 1)
        Deallocate(this);
    return (int)this;
}


void __cdecl Deallocate(void*);
struct FUN_00d0a130 {
    void* p;
    void* __thiscall Set(char b);
};
// @fnv 0x00d0a130
// pdb: hkProcess::`scalar deleting destructor' | hkServerProcessHandler.obj | fnv360_0822_retail, vtable, medium
void* FUN_00d0a130::Set(char abFree)
{
    p = &DAT_010ccfa0;
    if (abFree & 1)
        Deallocate(this);
    return this;
}

// add ecx,-0x14; jmp FUN_00d08570 : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089c0();
};

Derived::Derived()
{
}

// @fnv 0x00d089c0
void Derived::FUN_00d089c0()
{
    this->PrimaryBase::FUN_00d08570();
}

namespace fnv_00d089d0 {
// add ecx,-0x14; jmp FUN_00d08570 : Derived's override forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089d0();
};

Derived::Derived()
{
}

// @fnv 0x00d089d0
void Derived::FUN_00d089d0()
{
    this->PrimaryBase::FUN_00d08570();
}
}  // namespace fnv_00d089d0

namespace fnv_00d089e0 {
struct Base {
    void __thiscall FUN_00d08570();
};

struct Derived {
    void __thiscall FUN_00d089e0();
};

// @fnv 0x00d089e0
void __thiscall Derived::FUN_00d089e0()
{
    ((Base*)((char*)this - 0x18))->FUN_00d08570();
}
}  // namespace fnv_00d089e0

struct __declspec(align(16)) hkVector4D084 {
    float x, y, z, w;
};

struct hkpWorldRayCastInputD084 {
    hkVector4D084 m_vFrom;
    hkVector4D084 m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

struct hkpShapeRayCastOutputD084 {
    hkVector4D084 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    hkpShapeRayCastOutputD084()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct hkpWorldRayCastOutputD084 : public hkpShapeRayCastOutputD084 {
    const void* m_pRootCollidable;

    hkpWorldRayCastOutputD084() { m_pRootCollidable = 0; }
};

struct hkpRayHitCollectorD084;

class hkpRayShapeCollectionFilterD084 {
public:
    virtual ~hkpRayShapeCollectionFilterD084() throw();
};

class hkpRayCollidableFilterD084 {
public:
    virtual ~hkpRayCollidableFilterD084() throw();
};

class hkpRayCastCollectorBaseD084 {
public:
    virtual void CollectRayHit() throw();
};

class hkpTreeCastCallbackD084 {
public:
    virtual float processLeaf() throw();
};

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084, public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    int m_1c;

    FUN_00d9a040() throw();
};

class hkpBroadPhaseCastCollectorD084 {
public:
    virtual void ReleaseCollector() throw();
};

class hkpWorldRayCasterD084 : public hkpBroadPhaseCastCollectorD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
};

struct hkBoolD084 {
    char m_cBooleanValue;
    hkBoolD084(bool b) { m_cBooleanValue = (char)b; }
};

template <class T>
class hkArrayD085 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct PlaceTagD088 {};
inline void* operator new(unsigned int, void* p, PlaceTagD088) throw() { __assume(p != 0); return p; }
inline void operator delete(void*, void*, PlaceTagD088) throw() {}

template <class T>
struct hkArrayD088 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void pushBackUnchecked(const T& e)
    {
        new (&m_data[m_iElementCount], PlaceTagD088()) T(e);
        m_iElementCount++;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct hkBoolRetD088 {
    char m_cBooleanValue;
    hkBoolRetD088() throw() {}
};

class hkpEntityD088 {
public:
    hkBoolRetD088 FUN_00c9bff0() const throw();
};

struct hkpCollidableD088 {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    signed char m_iOwnerOffset;
    char m_pad11[3];
    unsigned int m_iOwnerObjectOffset;
    char m_type;

    hkpEntityD088* getOwner() const { return (hkpEntityD088*)((char*)this + m_iOwnerOffset); }
};

class hkpEntityListD088 {
public:
    char m_pad00[0x44];
    hkArrayD088<hkpCollidableD088*> m_kCollidables;
    char m_pad50[0xc];
    bool m_checkAll;
    char m_pad5d[3];
    int m_currentIndex;
    int m_maxChecksPerCall;

    __forceinline void checkCollidable(int i, hkArrayD088<hkpCollidableD088*>& kInactive)
    {
        hkpCollidableD088* pkCollidable = m_kCollidables.m_data[i];
        if (pkCollidable->m_type == 1) {
            hkpEntityD088* pkEntity = pkCollidable->getOwner();
            if (pkEntity && !pkEntity->FUN_00c9bff0().m_cBooleanValue) {
                kInactive.pushBackUnchecked(m_kCollidables.m_data[i]);
                m_kCollidables.removeAt(i);
            }
        }
    }

    bool CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw();
};

class hkMemoryAllocatorD08C;

struct hkMemoryRouterD08C {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD08C* m_pStreamAllocator;
    hkMemoryAllocatorD08C& heap() { return *m_pStreamAllocator; }
};
extern "C" hkMemoryRouterD08C& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T>
__forceinline void constructWithCopyD08C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayD08C {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD08C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyD08C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

namespace fnv_00d08cf0 {
struct IAllocator {
    virtual void unk00();
    virtual void* allocate(unsigned int size);
};

struct BSAudio {
    int unk00; int unk04; int unk08; int unk0c;
    IAllocator* allocator;
};

extern "C" BSAudio* __cdecl FUN_00c85750();

struct MyArray {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    MyArray() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000) {}
};

struct MyMapBase {
    void* m_table;
    int m_iCapacityFlags;
    int m_iPairCount;
    MyMapBase() : m_table(0), m_iCapacityFlags(0), m_iPairCount(-1) {}
    void __thiscall EnsureCapacity(IAllocator* allocator, int type);
};

struct MyBase1
{
    virtual void FUN_00d08570();
    virtual void vfunc1_1();
    virtual void vfunc1_2();
    virtual void vfunc1_3();
    virtual void vfunc1_4();
    virtual void vfunc1_5();
    virtual void vfunc1_6();
    short unk04;
    short unk06;
    int unk08;
    void* unk0C;
    int unk10;
    MyBase1() {
        this->unk0C = 0;
        this->unk10 = 0;
        this->unk06 = 1;
    }
};

}  // namespace fnv_00d08cf0

namespace fnv_00d0a240 {
struct FnvCpu_FUN_00d0a240_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d0a240_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d0a240_CpuAllocator* allocator;
};
FnvCpu_FUN_00d0a240_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00d0a240

extern int DAT_010ccfcc;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d08740_coll {
    int m_00;
    int m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_24;
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
    float m_80;
    void FUN_00d984b0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
    void FUN_00d9a2a0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};

class hkMemoryAllocatorD089;

struct hkMemoryRouterD089 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD089* m_pStreamAllocator;
    hkMemoryAllocatorD089& heap() { return *m_pStreamAllocator; }
};

namespace fnvc_adapt { extern "C" hkMemoryRouterD089* __cdecl FUN_00c85750(); }

enum hkResultD089 { HK_SUCCESS = 0, HK_FAILURE = 1 };

namespace fnv_00d08e80 {
extern "C" void* DAT_010ccf7c;

struct Hk_d08e80_Alloc {
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
    virtual void func3() = 0;
    virtual void ReturnMemory(void* p, int numBytes) = 0;
};

struct Hk_d08e80_Mem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Hk_d08e80_Alloc* m_alloc;
    Hk_d08e80_Alloc& heap() { return *m_alloc; }
};

namespace fnvc_adapt { Hk_d08e80_Mem* __cdecl FUN_00c85750(); }

struct Arr_d08e80 {
    void* m_data;
    int m_iElementCount;
    int m_capFlags;
    ~Arr_d08e80() {
        Hk_d08e80_Alloc& a = fnvc_adapt::FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) {
            a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void destroy() { this->~Arr_d08e80(); }
};

}  // namespace fnv_00d08e80

extern int DAT_010ccfcc;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d0a490_Obj {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    float m_80;
    int m_84;
    int m_88;
    int m_8c;
    int FUN_00d984b0(int, int, int, int, int, int, int, int);
};

extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

namespace fnv_00d0a1d0 {
// sub ecx,4; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (4).
struct PrimaryBase
{
    virtual void FUN_00d0a1d0();
};

struct SecondaryBase
{
    virtual void FUN_00d0a1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a1d0
    virtual void FUN_00d0a1d0();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a1d0

// FUN_00d0a200 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00d0a200 {
    A1_00d0a200();
    virtual void FUN_00d0a200();
    char pad[0x10];
};
struct A2_00d0a200 {
    A2_00d0a200();
    virtual void FUN_00d0a200();
};
struct Own_00d0a200 : A1_00d0a200, A2_00d0a200 {
    Own_00d0a200();
    virtual void key_fn();
// @fnv 0x00d0a200
    void FUN_00d0a200();
};
Own_00d0a200::Own_00d0a200() { }
void Own_00d0a200::key_fn() { }
Own_00d0a200* make_00d0a200() { static Own_00d0a200 o; return &o; }

namespace fnv_00d0a210 {
// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00d0a210();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00d0a210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a210
    virtual void FUN_00d0a210();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a210

namespace fnv_00d0a220 {
// sub ecx,0x1c; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x1c).
struct PrimaryBase
{
    virtual void FUN_00d0a220();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SecondaryBase
{
    virtual void FUN_00d0a220();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a220
    virtual void FUN_00d0a220();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a220

// Adjustor thunk: the secondary-base (+0x20) vtable entry for an override defined on the derived class.

namespace fnv_00d085e0 {
extern "C" void _ReadWriteBarrier();

extern "C" unsigned long DAT_0126835c;
extern "C" char str_010cd014[], str_010cd004[], str_010ccff4[], str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" unsigned __int64 __rdtsc();
struct MyBool0 { int m_v; MyBool0(bool b) { m_v = (int)b; } };
__declspec(noalias) void __cdecl bpv(void*, void*, const hkVector4D084&, const hkVector4D084&, hkpWorldRayCasterD084*) throw();
union Scratch { volatile unsigned int tick; unsigned int result; Scratch() {} };

}  // namespace fnv_00d085e0

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const char str_01076f38[];

struct S00d094a0_Alloc {
    virtual void f00();
    virtual void* AllocateMemoryBlock(int);
    virtual void f08();
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
    template<class T> __forceinline T* elements(int& count) {int bytes=count*4; void* p=AllocateBufferWithSize(bytes);count=bytes/4;return (T*)p;}

};
__forceinline S00d094a0_Alloc& S00d094a0_heap() { return *(S00d094a0_Alloc*)&FUN_00c85750().heap(); }

__forceinline void* reserveExternal(void*& data, int& capacity, int& bytes, int n) {
    S00d094a0_Alloc& a = S00d094a0_heap();
    bytes=n*4;
    void* p=a.AllocateBufferWithSize(bytes);
    int amount=bytes/4;
    data=p;
    capacity=amount;
    if(!capacity) capacity=0x80000000;
    return p;
}
struct __declspec(align(16)) S00d094a0_Vec { float x, y, z, w; };
struct __declspec(align(16)) S00d094a0_Desc {
    int m_uiItemCount; char m_04; char m_isMt; short m_06; int m_08; int m_0c;
    S00d094a0_Vec m_kMinimumCorner;
    S00d094a0_Vec m_kMaximumCorner;
    void FUN_00d976d0();
};
struct S00d094a0_Tree {
    void* m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; void* m_1c;
    int total() const { return m_14 + m_18; }
    void FUN_00d978d0(S00d094a0_Desc*);
    S00d094a0_Tree* Init(S00d094a0_Desc*);
};
struct S00d094a0_Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void getAabb(S00d094a0_Vec*, S00d094a0_Vec*);
};
struct S00d094a0_Ctx {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c; int u50; int u54;
    S00d094a0_Shape* m_pCollisionShape;
    int u5c; int u60; int u64; int u68; int u6c; int u70; int u74;
    void* m_78;
};
struct S00d094a0_Job;
struct S00d094a0_JobHead {
    __declspec(align(16)) char m_00;
    char m_01; char m_02;
    short m_04; short m_06;
    S00d094a0_JobHead() {}
    __forceinline S00d094a0_JobHead(char kind, char sub, short size, char spu)
        : m_00(sub), m_01(kind), m_02(spu), m_04(size), m_06(-1) {}
};
struct S00d094a0_QueryJob : S00d094a0_JobHead {
    void* m_10; int* m_14; int* m_18; void* m_1c;
    S00d094a0_QueryJob() {}
    __forceinline S00d094a0_QueryJob(char sub, short size)
        : S00d094a0_JobHead(3,sub,size,0), m_10(0), m_18(0) {
        m_02=1; m_14=0;
    }
};
struct S00d094a0_DistJob : S00d094a0_QueryJob {
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34;
    int m_38; int m_3c; int m_40;
    S00d094a0_DistJob() {}
    __forceinline S00d094a0_DistJob(int* header) : S00d094a0_QueryJob(3,0x50),m_30(0) { m_14=header; }
};
struct S00d094a0_Job : S00d094a0_DistJob {
    void** m_50;
    S00d094a0_Job() {}
    __forceinline void init(int* header,S00d094a0_Ctx* ctx) { m_06=-1; m_14=header; m_04=0x60; m_1c=ctx->m_78; m_01=3; m_18=0; m_02=1; m_00=6; m_30=0; }
    __forceinline S00d094a0_Job(int* header,S00d094a0_Ctx* ctx) : S00d094a0_DistJob(header) {
        m_00=6; m_04=0x60; m_1c=ctx->m_78;
    }
};
struct __declspec(align(16)) S00d094a0_Build {
    S00d094a0_Desc desc;
    int m_30; int m_uiItemCount; void* m_buf1; void* m_buf2;
    S00d094a0_Job job;
};

template<class T> struct TempArray {
    T* data; int size; int flags;
    __forceinline TempArray(int count) {
        S00d094a0_Alloc& heap=S00d094a0_heap();
        T* pointer=count?heap.elements<T>(count):0;
        int cap=count?count:0x80000000;
        data=pointer;size=count;flags=cap;
    }
    __forceinline void release() {S00d094a0_Alloc& heap=S00d094a0_heap(); if(!(flags&0x80000000))heap.ReturnMemory(data,(flags&0x3fffffff)*sizeof(T));}
    __forceinline T* begin(){return data;}
};

namespace fnv_00d0a170 {
class hkMemoryAllocatorD0A1 {
public:
    virtual ~hkMemoryAllocatorD0A1() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0A1 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD0A1* m_pStreamAllocator;

    hkMemoryAllocatorD0A1& heap() { return *m_pStreamAllocator; }
};

extern "C" hkMemoryRouterD0A1& __cdecl FUN_00c85750() throw();

class hkKdTreeCastCollector {
public:
    virtual ~hkKdTreeCastCollector() throw() {}
};

class CollectorD0A1 : public hkKdTreeCastCollector {
public:
    int unk04, unk08, unk0C, unk10, unk14;

    static void operator delete(void* p)
    {
        FUN_00c85750().heap().ReleaseBlock(p, sizeof(CollectorD0A1));
    }
    CollectorD0A1* FUN_00d0a170(unsigned int uiFlags);
};

}  // namespace fnv_00d0a170

namespace fnv_00d0b0d0 {
class hkMemoryAllocatorD0B0 {
public:
    virtual ~hkMemoryAllocatorD0B0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0B0 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD0B0* m_pStreamAllocator;

    hkMemoryAllocatorD0B0& heap() { return *m_pStreamAllocator; }
};


extern "C" hkMemoryRouterD0B0& __cdecl FUN_00c85750() throw();

template <class T>
class hkArrayD0B0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD0B0() throw()
    {
        hkMemoryAllocatorD0B0& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD0B0 {
    class hkBaseObject {
    public:
        virtual ~hkBaseObject() throw() {}
    };

}

class hkpWorldPostSimulationListener {
public:
    virtual ~hkpWorldPostSimulationListener() throw() {}
};

namespace hkD0B0 {

}

}  // namespace fnv_00d0b0d0

inline void* operator new(unsigned int, void* location) { return location; }

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_alloc;
};

void ResizeAudioStream(void* alloc, void* array, int elemSize);

template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(AllocHolder* h, T val) {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(h->m_alloc, this, sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        __assume(slot != 0);
        new (slot) T(val);
        ++m_iElementCount;
    }
};

extern unsigned int DAT_0126835c;

struct AllocV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void __thiscall ReleaseBlock(void* p, int bytes);
};

struct TempArr {
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
    void destroy()
    {
        hkMemoryAllocatorD08C& a = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            ((AllocV&)a).ReleaseBlock(m_data, (m_capFlags & 0x3fffffff) * 4);
    }
};

namespace RaycasterRework {

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084,
                     public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    float m_fEarlyOutHitFraction;

    FUN_00d9a040() throw();
};

}
