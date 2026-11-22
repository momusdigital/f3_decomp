// src/f3staging/f3blk_00760000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00772370 (community match, verified in this file)
#include <string.h>
namespace f3m_00772370 {
extern "C" void* __cdecl _alloca(size_t);
extern "C" void _ReadWriteBarrier(void);
namespace f3m_772370w {
struct Form;
struct Node {
    Form* item;
    Node* next;
    bool IsEmpty() const { return !next && !item; }
};
struct Form {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14();
    virtual int GetType();
    int unk04, unk08, unk0C;
    Node list;
};
struct Entry {
    int unk00, unk04;
    Form* form;
};
struct ENode {
    Entry* item;
    ENode* next;
    bool IsEmpty() const { return !next && !item; }
};
struct EList {
    virtual void v00(); virtual void v04();
    virtual ENode* Head();
};
struct Owner {
    int unk00;
    int unk04[0x22];
    EList entries;
    int unk90[0x59];
    Node* known;
    int FUN_00772370();
};

// pdb: PlayerCharacter::GetCurrentPotionCount | PlayerCharacter.obj | fnv360_0822_retail, call_seq, medium
int Owner::FUN_00772370()
{
    Owner* self = this;
    int count = 0;
    for (Node* n = known; n; n = n->next) {
        Form* f = n->item;
        if (!n->next && !f)
            break;
        if (f && f->GetType() == 7)
            ++count;
    }
    Form** forms = (Form**)_alloca(100 * sizeof(Form*));
    unsigned int* uses = (unsigned int*)_alloca(100 * sizeof(unsigned int));
    if (forms && uses) {
        for (int j = 0; j < 100; ++j) { forms[j] = 0; uses[j] = 0; }
        for (ENode* e = entries.Head(); e; e = e->next) {
            if (e->IsEmpty())
                break;
            Form* form = e->item ? e->item->form : 0;
            _ReadWriteBarrier();
            if (!form || form->GetType() != 7)
                continue;
            Node* k;
            for (k = (*(Owner* volatile*)&self)->known; k; k = k->next) {
                if (k->item == form)
                    break;
            }
            if (k)
                continue;
            bool done = false;
            for (int i = 0; i < 100; ++i) {
                if (done)
                    break;
                Form*& slot = forms[i];
                if (!slot) {
                    ++count;
                    slot = form;
                    uses[i] = 1;
                    done = true;
                } else if (slot == form) {
                    unsigned int c = 0;
                    for (Node* m = &forms[i]->list; m; m = m->next) {
                        if (m->item)
                            ++c;
                    }
                    if (uses[i] < c) {
                        ++uses[i];
                        done = true;
                    }
                }
            }
        }
    }
    return *(volatile int*)&count;
}
}
}   // namespace f3m_00772370
