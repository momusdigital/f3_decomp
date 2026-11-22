#include <new>
// src/f3staging/f3iso_004d5ed0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x004d5ed0 alone: another function in its served file emitted
// a symbol with the same FUN_ name. Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004d5ed0 (community match, verified in this file)
namespace f3m_004d5ed0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long references;

    __forceinline void IncRefCount() {
        InterlockedIncrement(&references);
    }
    __forceinline void DecRefCount() {
        if (InterlockedDecrement(&references) == 0)
            DeleteThis();
    }
};

struct ConstructorRef {
    NiRefObject* object;
    __forceinline ConstructorRef(NiRefObject* value) : object(value) {
        if (object)
            object->IncRefCount();
    }
    __forceinline ~ConstructorRef() {
        if (object)
            object->DecRefCount();
    }
};

struct QPtr_4de460 {
    ConstructorRef p;
    QPtr_4de460() : p(0) {}
    __forceinline QPtr_4de460(const QPtr_4de460& o) : p(o.p) {
        if (p.object)
            p.object->IncRefCount();
    }
};

class FUN_004d5e40 {
public:
    QPtr_4de460 a;
    QPtr_4de460 b;
    bool flag;
    FUN_004d5e40() : flag(true) {}
    ~FUN_004d5e40();
};

class FUN_004d5ed0 : public FUN_004d5e40 {
public:
    FUN_004d5ed0();
    __declspec(noinline) FUN_004d5ed0(const FUN_004d5ed0& o);
    __forceinline ~FUN_004d5ed0() {}
};

// pdb: TESObjectCELL::QUEUED_ATTACH::QUEUED_ATTACH | TESObjectCELL.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: TESObjectCELL::GetQueuedDistantRefCount)
// pdb params: __that
FUN_004d5ed0::FUN_004d5ed0(const FUN_004d5ed0& o)
    : FUN_004d5e40(o)
{}
}   // namespace f3m_004d5ed0
