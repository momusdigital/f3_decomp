// havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp: AdjDerived (7 functions)
#include "f3_common.h"
#include "fnv_asm_helpers.h"
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010c6fb0;

struct FUN_00e60680_class {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int capacity;
    int __thiscall GetNextIndex(int index);
};
// @fnv 0x00e60680
// pdb: hkpConvexPieceShape::getNextKey | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: oldKey
int __thiscall FUN_00e60680_class::GetNextIndex(int index) {
    int next = index + 1;
    if (next < capacity) return next;
    return -1;
}

struct InnerDispatch {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void run(int,int);
};
struct Dispatch { int x0,x4,x8,xc; InnerDispatch inner; };
struct FUN_00e60690_owner { int unk00; int unk04; int unk08; Dispatch* unk0c; int* unk10; void DispatchToInner(int index,int value); };
// Calls run on the inner dispatcher with the value from unk10 at index and the given value.
// @fnv 0x00e60690
// pdb: hkpConvexPieceShape::getChildShape | hkpConvexPieceShape.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: key, buffer
void FUN_00e60690_owner::DispatchToInner(int index,int value) { unk0c->inner.run(unk10[index],value); }

extern int DAT_010c6fb0;

struct FUN_00e60c30_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    void* volatile m_p14;

    FUN_00e60c30_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00e60670
// pdb: BSFileCache::GetCachedFilesCount | DebugTextXenonFileCache.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: __init_collate)
int FUN_00e60670()
{
    return 0;
}

#include <xmmintrin.h>

struct E606E0Vector4 {
    __m128 m_vComponents;

    void operator=(const E606E0Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct __declspec(align(16)) Vec4 {
    __m128 v;
};

struct Mat {
    Vec4 rows[8];
};

struct __declspec(align(16)) Scratch {
    float data[128];
};

struct Sub {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual Mat* GetMat(void* apKey, Scratch* apScratch);
};

struct Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sub sub10;
};

struct FUN_00e60730_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Holder* m_p20;
    void** m_p24;
    void FUN_00e60730(const unsigned short* apIndices, int aiCount, Vec4* apOut);
};

// @f3 0x00a978b0 (community match, verified in this file)
// pdb: hkpConvexPieceShape::convertVertexIdsToVerticesImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: ids, numIds, verticesOut
void FUN_00e60730_cls::FUN_00e60730(const unsigned short* apIndices, int aiCount, Vec4* apOut)
{
    Scratch scratch;
    for (int i = aiCount - 1; i >= 0; i--)
    {
        int iIndex = *apIndices;
        Mat* pMatrix = m_p20->sub10.GetMat(m_p24[iIndex / 3], &scratch);
        float* dst = (float*)apOut;
        const float* src = (const float*)&pMatrix->rows[iIndex % 3 + 2];
        (*(const unsigned short* volatile*)&apIndices)++;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        *((unsigned int*)apOut + 3) = iIndex | 0x3f000000;
        apOut++;
    }
}


extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD hkMonitorStreamTls;

struct S_00e609c0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00e609c0_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00e609c0_Timer(const char* name, int& t) {
    S_00e609c0_MonitorStream* s = (S_00e609c0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00e609c0_TimerCommand* h = (S_00e609c0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00e609c0_Bool {
    char m_cBooleanValue;
    S_00e609c0_Bool() {}
    S_00e609c0_Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00e609c0_ShapeBuffer {
    unsigned int m_data[128];
};

struct S_00e609c0_RayInput;

struct S_00e609c0_RayOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void changeLevel(int delta) { m_uiShapeKeyIndex += delta; }
    void setKey(unsigned int key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};

struct S_00e609c0_Shape {
    virtual ~S_00e609c0_Shape();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual S_00e609c0_Bool RayCast(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
    int unk04_;
    int unk08_;
    int unk0C_;
};

struct S_00e609c0_ShapeContainer {
    virtual ~S_00e609c0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00e609c0_Shape* GetShapeForKey(unsigned int key, S_00e609c0_ShapeBuffer& buffer) const;
};

struct S_00e609c0_ShapeCollection : S_00e609c0_Shape, S_00e609c0_ShapeContainer {
};

struct S_00e609c0_RayShapeCollectionFilter {
    virtual S_00e609c0_Bool IsCollisionEnabled(const S_00e609c0_RayInput& input, const S_00e609c0_Shape& shape,
        const S_00e609c0_ShapeContainer& container, unsigned int key) const = 0;
};

struct S_00e609c0_RayInput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    const S_00e609c0_RayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};

struct S_00e609c0_ConvexPieceShape : S_00e609c0_Shape {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const S_00e609c0_ShapeCollection* m_pShapeCollection;
    unsigned int* m_keys;
    int m_numKeys;

    S_00e609c0_Bool FUN_00e609c0(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
};

// Ray-casts each child shape whose filter allows it and, if any hit, sets results' key to the last hit index; returns whether any child was hit.
// @fnv 0x00e609c0
// pdb: hkpConvexPieceShape::castRayImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: input, results
S_00e609c0_Bool S_00e609c0_ConvexPieceShape::FUN_00e609c0(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const
{
    int hitIndex;
    S_00e609c0_Timer("TtrcConvxPiece", hitIndex);
    results.changeLevel(1);
    hitIndex = -1;
    for (int i = 0; i < m_numKeys; i++)
    {
        if (!input.m_pRayShapeCollectionFilter ||
            input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *m_pShapeCollection,
                *static_cast<const S_00e609c0_ShapeContainer*>(m_pShapeCollection), m_keys[i]))
        {
            S_00e609c0_ShapeBuffer buffer;
            const S_00e609c0_Shape* child = m_pShapeCollection->GetShapeForKey(m_keys[i], buffer);
            S_00e609c0_Bool hit = child->RayCast(input, results);
            if (hit)
            {
                hitIndex = i;
            }
        }
    }
    results.changeLevel(-1);
    if (hitIndex != -1)
    {
        results.setKey(hitIndex);
    }
    int endTicks;
    S_00e609c0_Timer("Et", endTicks);
    return hitIndex != -1;
}

extern unsigned int DAT_0126835c;

struct StringCursor {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pFreeList;

    static inline StringCursor& GetMonitorStream() {
        return *(StringCursor*)TlsGetValue(DAT_0126835c);
    }

    inline void timerBegin(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }

    inline void timerEnd(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }
};

struct hkBool {
    char m_cBooleanValue;
    operator bool() const { return m_cBooleanValue != 0; }
};

struct BodyA {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    struct Filter* m_iFilter;
};

struct ShapeBase;
struct ShapeDerived;

struct Filter {
    virtual hkBool IsCollisionEnabled(const BodyA* bodyA, const ShapeDerived* shapeD, const ShapeBase* shapeB, int key);
};

struct ChildShape {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void func24(const BodyA* bodyA, const struct CdBody* bodyB, void* input);
};

struct ShapeBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ChildShape* GetShapeForKey(int key, void* buffer);
};

struct ShapeDerived {
    int unk00; int unk04; int unk08; int unk0c;
    ShapeBase m_base;
};

struct BodyB {
    int unk00; int unk04;
    void* m_kMotionState;
};

struct CdBody {
    ChildShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_kMotionState;
    const BodyB* m_parent;
};

struct FUN_00e60b00_cls {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    ShapeDerived* m_pCollisionShape;
    int* m_keys;
    int m_uiItemCount;

    void ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input);
};

// For each key passing bodyA's filter, gets the child shape and calls its func24 with bodyA, a CdBody built from bodyB, and input, between profiler timers.
// @f3 0x00a97e20 (community match, verified in this file)
extern unsigned int DAT_0116913c;

struct S_00a97e20_Cursor {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pFreeList;
    static inline S_00a97e20_Cursor& GetMonitorStream() {
        return *(S_00a97e20_Cursor*)TlsGetValue(DAT_0116913c);
    }
    inline void timerBegin(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }
    inline void timerEnd(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }
};

struct S_00a97e20_CdBody {
    struct S_00a97e20_Child* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_kMotionState;
    const BodyB* m_parent;
};

struct S_00a97e20_Child {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void func24(const BodyA* bodyA, const S_00a97e20_CdBody* bodyB, void* input);
};

// pdb: hkpConvexPieceShape::castRayWithCollectorImpl | hkpConvexPieceShape.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: input, cdBody, collector
void FUN_00e60b00_cls::ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input) {
    S_00a97e20_Cursor::GetMonitorStream().timerBegin("TtrcConvxPiece");

    for (int i = 0; i < this->m_uiItemCount; ++i) {
        if (bodyA->m_iFilter) {
            const ShapeBase* pShapeBase = this->m_pCollisionShape ? &this->m_pCollisionShape->m_base : 0;
            if (!bodyA->m_iFilter->IsCollisionEnabled(bodyA, this->m_pCollisionShape, pShapeBase, this->m_keys[i]))
                continue;
        }

        __declspec(align(16)) int buffer[128];
        S_00a97e20_Child* child = (S_00a97e20_Child*)this->m_pCollisionShape->m_base.GetShapeForKey(this->m_keys[i], buffer);
        S_00a97e20_CdBody body;
        body.m_parent = bodyB;
        body.m_kMotionState = bodyB->m_kMotionState;
        body.m_pCollisionShape = child;
        body.m_uiCollisionShapeKey = i;
        child->func24(bodyA, &body, input);
    }

    S_00a97e20_Cursor::GetMonitorStream().timerEnd("Et");
}


// sub ecx,0x14; jmp Destroy == MSVC adjustor thunk (Derived overrides a virtual both bases declare).
struct AdjPrimaryBase
{
    virtual void FUN_00e60c20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct AdjSecondaryBase
{
    virtual void FUN_00e60c20();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00e60c20
    virtual void FUN_00e60c20();
};

AdjDerived::AdjDerived()
{
}
