#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddfcd0_Router* FUN_00c85750();
struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};

#include <xmmintrin.h>
struct __declspec(align(16)) Mat4
{
    float m[4][4];
};
struct XfResult
{
    int m_00;
    int m_04;
};
struct Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    __declspec(noinline) void resetX();
    void applyX(void* shape, Mat4* m, XfResult* r);
    void FUN_00de0f90(void* shape, XfResult* result);
};
// @f3 0x00a6a690 (community match, verified in this file)
struct View438 {
    int unk00, unk04, unk08, count;
    __declspec(noinline) void FUN_00a68e20();
    void FUN_00a694a0(void* shape, const Mat4* matrix, XfResult* result);
};
__declspec(noinline) void View438::FUN_00a68e20() { count = 0; }
// pdb: hkpConvexRadiusBuilder::buildDisplayGeometries | hkpConvexRadiusBuilder.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: shape, displayGeometries
void Node::FUN_00de0f90(void* shape, XfResult* result) {
    __declspec(align(16)) Mat4 matrix;
    matrix.m[0][0] = 0.0f;
    matrix.m[0][1] = 0.0f;
    matrix.m[0][2] = 0.0f;
    matrix.m[0][3] = 0.0f;
    matrix.m[1][0] = 0.0f;
    matrix.m[1][1] = 0.0f;
    matrix.m[1][2] = 0.0f;
    matrix.m[1][3] = 0.0f;
    matrix.m[2][0] = 0.0f;
    matrix.m[2][1] = 0.0f;
    matrix.m[2][2] = 0.0f;
    matrix.m[2][3] = 0.0f;
    matrix.m[0][0] = 1.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[3][0] = matrix.m[3][1] = matrix.m[3][2] = matrix.m[3][3] = 0.0f;
    View438* self = reinterpret_cast<View438*>(this);
    self->FUN_00a68e20();
    result->m_04 = 0;
    self->FUN_00a694a0(shape,&matrix,result);
}

