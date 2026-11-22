// src/f3staging/f3blk_008e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008f9170 (community match, verified in this file)
#include <new>
extern unsigned long tlsIndex_f3;
namespace f3m_008f9170 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct __declspec(align(16)) align16vec {
    float x, y, z, w;
    align16vec(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
struct Input_f3 {
    int unk00, unk04, unk08, unk0c;
    float a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3;
};
struct Heap_f3 { void* allocate(int, int); };
struct Object_f3 {
    virtual ~Object_f3();
    unsigned short size;
    short refs;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c;
    static void* operator new(size_t n) {
        Heap_f3* heap = (Heap_f3*)TlsGetValue(tlsIndex_f3);
        void* p = heap->allocate(n, 41);
        ((Object_f3*)p)->size = (unsigned short)n;
        return p;
    }
    static void operator delete(void*);
    Object_f3(const align16vec&, const align16vec&, float, float, float, int, int);
    void set(float);
};
class Owner_f3 {
public:
    void FUN_008f9170(Input_f3*);
};
typedef void (__thiscall *OwnerCall_f3)(Owner_f3*, void*);
// pdb: bhkMouseSpringAction::Init | bhkMouseSpringAction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arInfo
void Owner_f3::FUN_008f9170(Input_f3* input) {
    if (input) {
        Object_f3* obj = new Object_f3(align16vec(input->a0, input->a1, input->a2, input->a3), align16vec(input->b0, input->b1, input->b2, input->b3), input->c0, input->c1, input->c3, input->unk04, 0);
        obj->set(input->c2);
        ((OwnerCall_f3)(*(void***)this)[35])(this, obj);
        if (obj->size && --obj->refs == 0) delete obj;
        ((OwnerCall_f3)(*(void***)this)[47])(this, input);
    }
}
}   // namespace f3m_008f9170
