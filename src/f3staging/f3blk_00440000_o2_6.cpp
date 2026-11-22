#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00455330 (community match, verified in this file)
extern unsigned int FUN_00f4a768;
namespace f3m_00455330 {
struct FUN_00455330_node {
    unsigned int vptr;
    int unk04;
    int unk08;
    unsigned int unk0c;
};

int __cdecl FUN_00455100(int);

struct FUN_00455330_cls {
    int unk00;
    unsigned char unk04;
    bool FUN_00455330(FUN_00455330_node* p);
};

// pdb: TESForm::SavesBefore | TESForm.obj | fnv360_0822_retail, vtable, medium
// pdb params: apGroupFORM
bool FUN_00455330_cls::FUN_00455330(FUN_00455330_node* p)
{
    bool r = false;
    if (p != 0 && p->vptr == FUN_00f4a768) {
        switch (p->unk0c) {
        case 0: {
            int c = unk04;
            if (c < FUN_00455100(p->unk08))
                r = true;
            break;
        }
        case 2:
        case 3:
        case 6:
            if (unk04 < 0x39)
                r = true;
            break;
        case 1:
        case 4:
        case 5:
            if (unk04 < 0x41)
                r = true;
            break;
        case 7:
            if (unk04 < 0x45)
                r = true;
            break;
        }
    }
    return r;
}
}   // namespace f3m_00455330

// @f3 0x00453cd0 (community match, verified in this file)
namespace f3m_00453cd0 {
class FUN_00c24b70 {
public:
    ~FUN_00c24b70();
};
class FUN_0044ed00 : public FUN_00c24b70 {
public:
    void* items[38];
    FUN_0044ed00();
    void FUN_0044ed20(void* form);
    void FormComponentCollection_ClearDataAllComponents();
};
namespace f3m_00453cd0 {
struct Member18 {
    void FUN_00c24b70();
};
struct Form {
    int unk00;
    unsigned char kind;
    unsigned char unk05;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Member18 unk18;
    void FUN_00453cd0();
};
// pdb: TESForm::ClearDataAllComponents | TESForm.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: TESForm::InitializeDataAllComponents)
void Form::FUN_00453cd0()
{
    switch (kind) {
    case 0x11:
    case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40:
    case 0x42: case 0x43:
    case 0x49:
        return;
    case 0x39:
        unk18.FUN_00c24b70();
        return;
    }
    FUN_0044ed00 cache;
    cache.FUN_0044ed20(this);
    cache.FormComponentCollection_ClearDataAllComponents();
}
}
}   // namespace f3m_00453cd0
