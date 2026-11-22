#include <new>
#include <new>
// src/f3staging/f3blk_00400000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0040eb90 (community match, verified in this file)
namespace f3m_0040eb90 {
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* destination, long exchange, long comparand);

namespace f3m_0040eb90 {

struct BSSpinLock_40eb90 {
    long owningThread;
    long lockCount;
    void FUN_00409a80(const char* name);
    void Unlock() {
        if (--lockCount == 0)
            InterlockedCompareExchange(&owningThread, 0, owningThread);
    }
};

extern BSSpinLock_40eb90 DAT_0106c980;

class BSExtraData_40eb90 {
public:
    virtual ~BSExtraData_40eb90();
    unsigned char type;
    BSExtraData_40eb90* next;
};

class BaseExtraList_40eb90;
void __cdecl BaseExtraList_ClearLastExtraAll(BaseExtraList_40eb90* list);

class BaseExtraList_40eb90 {
public:
    virtual ~BaseExtraList_40eb90();
    BSExtraData_40eb90* head;
    unsigned char presence[0x12];

    void BaseExtraList_RemoveAllDefault(bool bDelete);
};

// pdb: BaseExtraList::RemoveAllDefault | ExtraDataList.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void BaseExtraList_40eb90::BaseExtraList_RemoveAllDefault(bool bDelete) {
    DAT_0106c980.FUN_00409a80("BaseExtraList::RemoveAllDefault()");
    BaseExtraList_ClearLastExtraAll(this);
    BSExtraData_40eb90* extra = head;
    BSExtraData_40eb90* prev = 0;
    while (extra) {
        unsigned char type = extra->type;
        bool remove = true;
        switch (type) {
        case 0x2e:
        case 0x38:
        case 0x4f:
        case 0x52:
        case 0x54:
        case 0x58:
        case 0x65:
        case 0x7b:
        case 0x84:
            remove = false;
            break;
        }
        BSExtraData_40eb90* next = extra->next;
        if (remove) {
            if (prev)
                prev->next = next;
            else
                head = next;
            if (bDelete)
                delete extra;
            unsigned int index = (unsigned int)type >> 3;
            if (index < 0x12)
                presence[index] &= ~(1 << (type % 8));
        } else {
            prev = extra;
        }
        extra = next;
    }
    DAT_0106c980.Unlock();
}

}
}   // namespace f3m_0040eb90
