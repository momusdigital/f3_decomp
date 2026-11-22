#include <windows.h>
#include <string.h>
// src/f3staging/f3blk_00420000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00433170 (community match, verified in this file)
namespace f3m_00433170 {
struct Item1117 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
    unsigned char kind26;
};
// pdb: TES::IsCellLoaded | TES.obj | fnv360_0822_retail, call_seq + bridge(call_seq|call_seq) + skyrim(call_gap), high
bool __fastcall TES_IsCellLoaded(void* context, void* unused, Item1117* item, bool flag) {
    if (item) {
        switch (item->kind26) {
        case 2:
        case 3:
        case 4:
            if (flag) break;
        case 5:
        case 6:
            return true;
        default: break;
        }
    }
    return false;
}
}   // namespace f3m_00433170

// @f3 0x00434d90 (community match, verified in this file)
namespace f3m_00434d90 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
namespace f3m_00434d90 {
struct Entry {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    short unk24;
    unsigned char type;
};
struct Grid {
    virtual void v00();
    virtual void v04();
    virtual void Refresh();
    int unk04, unk08;
    unsigned int size;
};
struct Shared {
    virtual void v00();
    virtual void DeleteThis();
    long refCount;
    void Release() { if (InterlockedDecrement(&refCount) == 0) DeleteThis(); }
};
struct Queue {
    void FUN_0043cb10(Entry* entry);
};
struct Inner { void FUN_00615340(); };
struct Owner { Inner* FUN_00501cc0(); };
extern int DAT_0106ccd0;
extern unsigned int DAT_0106cb70;
extern Queue* DAT_0106cdcc;
extern Shared* DAT_0116f3d8;
extern bool DAT_00f4c96c;
inline bool IsReady(Entry* e) {
    if (e) {
        switch (e->type) {
        case 2:
        case 3:
        case 4:
            return true;
        case 5:
        case 6:
            return false;
        }
    }
    return true;
}
struct Pool {
    int unk00, unk04;
    Grid* unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    Entry* unk34;
    Entry** unk38;
    Entry** unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84;
    Owner* unk88;
    Entry*& A(int i) { return unk38[i]; }
    Entry* TakeA(int i) { Entry* e = unk38[i]; A(i) = 0; return e; }
    Entry* TakeB(unsigned int i) { Entry* e = unk3c[i]; B(i) = 0; return e; }
    Entry*& B(unsigned int i) { return unk3c[i]; }
    void FUN_004336d0();
    bool FUN_00434d90();
};
// pdb: TES::ClearOldestBufferedCell | TES.obj | fnv360_0822_retail, call_gap, low
bool Pool::FUN_00434d90() {
    Entry* e;
    if (!unk34) {
        for (int i = DAT_0106ccd0 - 1; i >= 0; i--) {
            if (unk38[i]) {
                e = TakeA(i);
                if (e) goto use;
                break;
            }
        }
        FUN_004336d0();
        unsigned int n = unk08->size * unk08->size;
        for (unsigned int j = DAT_0106cb70 - 1; j >= n; j--) {
            if (unk3c[j]) {
                if (!IsReady(unk3c[j])) return false;
                e = TakeB(j);
                goto check;
            }
        }
        return false;
    } else {
        unsigned int n = unk08->size * unk08->size;
        for (unsigned int j = DAT_0106cb70 - 1; j >= n; j--) {
            if (unk3c[j] && IsReady(unk3c[j])) {
                e = TakeB(j);
                if (e) goto use;
                break;
            }
        }
{
        for (int i = DAT_0106ccd0 - 1; i >= 0; i--) {
            if (unk38[i] && unk38[i] != unk34) {
                e = TakeA(i);
                if (e) goto use;
                break;
            }
        }
}
        for (unsigned int k = 0; k < n; k++) {
            if (unk3c[k] && IsReady(unk3c[k])) {
                e = TakeB(k);
                if (DAT_0106cdcc) {
                    unk08->Refresh();
                    if (DAT_0116f3d8) {
                        DAT_0116f3d8->Release();
                        DAT_0116f3d8 = 0;
                    }
                    DAT_00f4c96c = true;
                }
                goto check;
            }
        }
        return false;
    }
check:
    if (!e) return false;
use:
    DAT_0106cdcc->FUN_0043cb10(e);
    if (!unk3c[0] && unk88) unk88->FUN_00501cc0()->FUN_00615340();
    return true;
}
}
}   // namespace f3m_00434d90
