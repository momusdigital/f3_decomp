#include "f3_common.h"
// src/fallout_shared/speedtree/bstreemodel_o2_nood_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/speedtree/bstreemodel.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/fallout_shared/speedtree/bstreemodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreemodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct BSTreeModel
{
    virtual ~BSTreeModel();
    void* DestroyAndFree(unsigned int flags);
    static void operator delete(void* p, unsigned int flags);
};
struct GlobalObject_0044f440
{
    struct
    {
        float f;
    }* Float();
};
extern "C" unsigned char __cdecl GetByteAtOffset1B();
unsigned char __cdecl GetByteAtOffset1B();
struct Flt
{
    operator unsigned int() const;
};
GlobalObject_0044f440 g_011d5c80;
struct NiAlphaProperty
{
    char m_auiShapeKeys[0x1c];
    NiAlphaProperty();
    ~NiAlphaProperty();
    void FUN_0049ed90(bool);
    void SetFlag512(bool);
    void SetFlags(unsigned short);
    void FUN_0094db80(unsigned char);
    static void* operator new(unsigned int);
};
NiAlphaProperty* FUN_006698f0();
struct MemObjX
{
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem);
};
template <class T> struct PtrX
{
    T* m_pObject;
    PtrX();
    PtrX(T* apObject);
    ~PtrX();
    PtrX& operator=(T* apObject);
    operator T*() const;
};
struct TreeCloneProcess
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    TreeCloneProcess(float);
    ~TreeCloneProcess();
};
struct NiNode
{
    NiNode* Clone();
    NiNode* CloneWithProcess(TreeCloneProcess*);
};
template <class T> struct NiPointer
{
    T* object;
    NiPointer();
    ~NiPointer();
    NiPointer& operator=(const NiPointer&);
    NiPointer& operator=(T*);
    operator T*();
    static void* operator new[](unsigned int);
    static void operator delete[](void*);
};
struct GlobalObject_00633c90
{
    void* p;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(void*);
};
template <class T> unsigned int BSStringLength(const T* apString);
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND
    };
    static FILE_LOCATION Exist(const char* apPath, char* apOut, unsigned int auiArg, unsigned int auiArgCur);
};
NiNode* __cdecl FUN_00c81380(float afArg, float afArgCur);
namespace TreeBuild {
struct Model;
struct Geometry;
struct GeometryData;
struct Object;
struct Property;
struct Shader;
template <class T> struct Handle
{
    T* object;
    Handle(T*);
    ~Handle();
    T* FUN_00559450();
    void FUN_0066b0d0(T*);
};
extern const char DAT_010667b8[], DAT_01066830[];
extern const double DAT_010240c0, DAT_01012070, DAT_01011590;
struct UpdateData
{
    float time;
    int flags, unk08;
    UpdateData(float, int, int);
};
struct ShaderState
{
    int FUN_004a8a90();
    int FUN_005f36f0();
};
struct Property
{
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
    virtual Shader* CreateShader(Geometry*);
    void FUN_004393c0(int);
    void FUN_00baa000();
    void FUN_00b66ad0(const char*, Object*);
};
Property* FUN_006698f0();
struct Geometry
{
    virtual void v0();
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Geometry(GeometryData*);
    void FUN_00439410(Property*);
    ShaderState* FUN_005495f0();
    void FUN_00539ef0(Shader*);
    void FUN_00874460(void*);
};
struct Tree
{
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
    virtual void* GetBranches();
    virtual void v66();
    virtual void* GetLeaves();
    virtual Geometry* GetBranch(unsigned int);
    virtual void v69();
    virtual void v70();
    virtual void SetBranch(unsigned int, Geometry*);
    virtual void SetLeaf(unsigned int, Geometry*);
    virtual void SetBillboardObject(Object*);
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
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Tree(Model*, Object*);
    void FUN_00a5a040();
    void FUN_00a59c90(UpdateData*);
    void FUN_0066cb40(void*, float);
};
Object* FUN_00c81380(float, float);
struct Model
{
    int unk00, unk04, unk08;
    void* model;
    int unk10;
    Handle<GeometryData>* branches;
    Handle<GeometryData>* leaves;
    Handle<Object> billboard;
    int unk20;
    Handle<Property>* branchProperties;
    Handle<Property>* leafProperties;
    Handle<Object> extra;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    float radius, height;
    Object* ConvertFloatToUInt();
    unsigned short FUN_00669990();
    unsigned short FUN_006699d0();
    bool FUN_00666f00();
    Tree* CreateTree(float);
};
}

#include <xmmintrin.h>
struct hkVector4C813
{
    __m128 m_vComponents;
};
struct __declspec(align(16)) CapsuleParams
{
    int flags;
    float radius;
    int unk08, unk0c;
    hkVector4C813 endpoints[2];
};
struct AllocatorC813
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
};
struct MemoryC813
{
    int unk00, unk04, unk08, unk0c;
    AllocatorC813* allocator;
    AllocatorC813& heap()
    {
        return *allocator;
    }
};
MemoryC813* FUN_00c85750();
struct __declspec(align(16)) FUN_00c8f510
{
    int filter00;
    void* shape04;
    int unk08;
    void* data;
    int size;
    int capacity;
    int unk18;
    int unk1c;
    int filter20;
    void* shape24;
    int unk28;
    int unk2c;
    hkVector4C813 position;
    hkVector4C813 rotation;
    hkVector4C813 linearVelocity;
    hkVector4C813 angularVelocity;
    hkVector4C813 inertiaTensor[3];
    hkVector4C813 centerOfMass;
    float valueb0;
    int unkb4;
    int unkb8;
    int unkbc;
    float valuec0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned char motion, unkD5, unkD6, unkD7;
    int unkd8;
    int unkdc;
    FUN_00c8f510();
    void ClearAndRelease(AllocatorC813& alloc)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            alloc.Free(data, (capacity & 0x3fffffff) * 8);
    }
    ~FUN_00c8f510()
    {
        ClearAndRelease(FUN_00c85750()->heap());
    }
};
// @f3 0x008f2e60 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned int DAT_010f3170;
extern const double DAT_00dbe7c0;

struct TlsAlloc
{
    void FUN_008f6d90(void* data, unsigned int size, int tag);
};

__forceinline void ReleaseBlock(unsigned int capacity, void* data)
{
    if ((capacity & 0x80000000) == 0)
    {
        unsigned int count = capacity & 0x3fffffff;
        TlsAlloc* alloc = (TlsAlloc*)TlsGetValue(DAT_010f3170);
        void* d = *(void* volatile*)&data;
        alloc->FUN_008f6d90(d, count * 8, 0x17);
    }
}

struct __declspec(align(16)) ParamsLocal
{
    int flags;
    float radius;
    int unk08, unk0c;
    float endpoint0[4];
    float endpoint1[4];
};

struct FUN_0059fa80 : MemObjX
{
    int unk00, unk04;
    void* shape;
    int unk0c, material;
    FUN_0059fa80(CapsuleParams*);
};

struct FUN_004f06c0 : NiNode
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    FUN_004f06c0(FUN_00c8f510*);
};

struct __declspec(align(16)) FUN_00900d70
{
    int filter00;
    void* shape04;
    int unk08;
    void* data;
    int size;
    int capacity;
    int unk18, unk1c;
    int filter20;
    void* shape24;
    int unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    float valueb0;
    int unkb4, unkb8;
    float valuebc;
    int unkc0, unkc4, unkc8, unkcc;
    unsigned char motion, unkD1, unkD2, unkD3;
    int unkd4, unkd8;
    FUN_00900d70();
    ~FUN_00900d70()
    {
        if ((capacity & 0x80000000) == 0)
        {
            unsigned int count = capacity & 0x3fffffff;
            TlsAlloc* alloc = (TlsAlloc*)TlsGetValue(DAT_010f3170);
            alloc->FUN_008f6d90(data, count * 8, 0x17);
        }
    }
};

// pdb: NiPointer<bhkRigidBody>::operator= | TESLand.obj | fnv360_0721_beta, call_dedup, low
// pdb params: pObject
NiNode* __cdecl FUN_00c81380(float a, float b)
{
    NiNode* result = 0;
    ParamsLocal params;
    params.endpoint0[3] = 0.0f;
    params.endpoint1[3] = 0.0f;
    params.flags = 0;
    if (a <= b * 2.0f)
        a = (float)(b * 2.0f + 1.0);
    params.radius = (float)(b * DAT_00dbe7c0);
    params.endpoint0[0] = 0.0f;
    params.endpoint0[1] = 0.0f;
    float delta = a - b;
    params.endpoint0[2] = (float)(delta * DAT_00dbe7c0);
    params.endpoint1[0] = 0.0f;
    params.endpoint1[1] = 0.0f;
    params.endpoint1[2] = params.radius;

    FUN_0059fa80* desc = new FUN_0059fa80((CapsuleParams*)&params);
    if (desc)
    {
        desc->material = 9;
        FUN_00900d70 block;
        void* shape = desc->shape;
        block.valueb0 = 0.0f;
        block.valuebc = 0.6f;
        block.motion = 7;
        block.filter00 = 0x40009;
        block.filter20 = 0x40009;
        block.shape04 = shape;
        block.shape24 = shape;
        result = new FUN_004f06c0((FUN_00c8f510*)&block);
    }
    return result;
}

