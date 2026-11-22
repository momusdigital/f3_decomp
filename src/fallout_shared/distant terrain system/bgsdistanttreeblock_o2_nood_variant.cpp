#include "f3_common.h"
// src/fallout_shared/distant terrain system/bgsdistanttreeblock_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct NP
{
    NP& operator=(void*);
};
struct BGSDistantTreeBlockLoadTask
{
    void* Destroy(unsigned int flags);
    void FUN_006f94a0();
};
void BuildNavMeshGeometry(void*);
struct Flt
{
    operator unsigned int();
};
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct BGSDistantTreeBlockLoadTask;
struct Fake076
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
    virtual const char* GetStr();
};
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct Arr
{
    unsigned int* GetAt(int, int);
};
struct ArrSI : public Arr
{
    unsigned int GetFlags();
};
struct BGSDistantTreeBlock
{
    char _pad[52];
    ArrSI mArray;
    void MarkTreeInstance(unsigned int);
    void FUN_006f7780();
    void ProcessAllTrees();
};
template <typename A, typename B> struct NiTPointerMap
{
    bool IsEmpty();
};
struct NiMemObject
{
    static void* operator new(unsigned int);
};
template <typename T> struct PathingRef
{
    void Reset(void*);
};
struct NavMeshPtr
{
    int v;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
void BuildNavMeshGeometry(void* param);
template <class T> struct NiPtrS
{
    T* m_pObject;
    operator T*() const;
    NiPtrS& operator=(T* p);
};
struct Fake076;
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct BGSDistantTreeBlock;
class C6F94A0Base
{
  public:
    virtual ~C6F94A0Base();
};
class FUN_006f94a0 : public C6F94A0Base
{
  public:
    virtual ~FUN_006f94a0();
};
struct Lod77Foo1
{
    static void* operator new(unsigned int);
    Lod77Foo1();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct Lod77Foo2
{
    static void* operator new(unsigned int);
    Lod77Foo2();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex(float, float, float);
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    NiPoint3Ex FUN_0053d280(float) const;
    float Length() const;
};

struct S_00bb6050
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

    int __thiscall FUN_00bb6050(int arg0, int arg1);
};

// @fnv 0x00bb6050
// pdb: BSDistantTreeShader::GetShaderDecl | BSDistantTreeShader.obj | fnv360_0721_beta, objrun, low
// pdb params: apGeometry, apProperty
int __thiscall S_00bb6050::FUN_00bb6050(int arg0, int arg1)
{
    return this->unk80;
}
