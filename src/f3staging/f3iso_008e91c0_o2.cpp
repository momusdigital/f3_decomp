#include <new>
// src/f3staging/f3iso_008e91c0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x008e91c0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008e91c0 (community match, verified in this file)
#include <xmmintrin.h>
namespace Proxy1659 {
struct FUN_00c92c70_Class {
    void __thiscall FUN_00c92c70(void* phantom);
};
struct FUN_00c936a0_Class {
    void __thiscall FUN_00c936a0(void* phantom);
};
struct NiRTTI;
struct NiObject {
    virtual const NiRTTI* GetStreamableRTTI();
};
union __declspec(align(16)) PositionQuad {
    __m128 simd;
    signed char bytes[16];
};
struct __declspec(align(16)) SavedPosition {
    PositionQuad quad;
    SavedPosition() {}
    SavedPosition(const SavedPosition& other) { quad.simd = *(const __m128*)&other.quad.bytes[0]; }
};
struct ActionObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AssignEntity(void* entity);
    void* unk04;
    FUN_00c92c70_Class* m_pOwningWorld;
    void* unk0C;
    void* m_pEntity;
};
struct FUN_00cac980_Holder {
    void* __thiscall hkpCharacterProxy_getShapePhantom();
};
struct FUN_00cac910_shell : FUN_00cac980_Holder {
    const SavedPosition& __thiscall FUN_00cac910();
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
    ActionObj* unk30;
};
struct ArgClass {
    void* unk00;
    void* unk04;
    void* unk08;
};
extern const SavedPosition zeroPosition;
struct HostClass : NiObject {
    void* unk04;
    FUN_00cac910_shell* unk08;
    __forceinline const SavedPosition& getPosition() {
        FUN_00cac910_shell* proxy = unk08;
        const SavedPosition* result = &zeroPosition;
        if (proxy) {
            this->NiObject::GetStreamableRTTI();
            result = &proxy->FUN_00cac910();
            this->NiObject::GetStreamableRTTI();
        }
        return *result;
    }
    bool __thiscall bhkCharacterController_SetShape(ArgClass* a1, int a2);
};


static inline void* GetArgEnt(ArgClass* a) { return a ? a->unk08 : 0; }
struct ProxyView_c9da80 { void* __thiscall FUN_0091ddd0(); };
struct ProxyPosView { const SavedPosition& __thiscall FUN_0091dd60(); };
struct WorldRemoveView { void __thiscall FUN_009028d0(void* phantom); };
struct WorldAddView { void __thiscall FUN_00903980(void* phantom); };
// pdb: bhkCharacterController::SetShape | bhkCharacterController.obj | fnv360_0721_beta, call_seq + bridge(call_gap|call_gap), high
bool __thiscall HostClass::bhkCharacterController_SetShape(ArgClass* a1, int aiUnused) {
    if (this) {
        FUN_00cac910_shell* obj = unk08;
        if (obj) {
            ActionObj* action = (ActionObj*)((ProxyView_c9da80*)obj)->FUN_0091ddd0();
            if (action) {
                void* oldEntity=action->m_pEntity;
                if (oldEntity != GetArgEnt(a1)) {
                    FUN_00c92c70_Class* world = action->m_pOwningWorld;
                    if (unk08) {SavedPosition position(((ProxyPosView*)unk08)->FUN_0091dd60());}
                    if (world) ((WorldRemoveView*)world)->FUN_009028d0(action);
                    action->AssignEntity(GetArgEnt(a1));
                    if (world) ((WorldAddView*)world)->FUN_00903980(action);
                    return true;
                }
            }
        }
    }
    return false;
}

}
