#include <new>
// src/f3staging/f3iso_00996cf0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00996cf0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00996cf0 (community match, verified in this file)
extern unsigned long DAT_010f3170;
namespace f3m_00996cf0 {
// Reconstructed layout support for the isolated current pack.
// Function body retained from the prior contributor's best draft.
extern void* (__stdcall* DAT_00d9b080)(unsigned long);

struct SweepThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* OnStackOverflow(unsigned int);
    virtual void OnStackUnderflow(void*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* current;
    int unk24;
    char* base;
    char* end;
    void Free(char* p) {
        current = p;
        if (p == base) OnStackUnderflow(p);
    }
};
struct Sub {
    unsigned short x;
    unsigned short unk02;
    unsigned short* idx;
    int n;
    int unk0c;
};
struct Elem {
    int unk00, unk04;
    unsigned short m_usValue08;
    unsigned short unk0a;
    int* h;
    Sub* getMarker(Sub* base) {
        return (Sub*)((char*)base + ((unsigned)h & ~1u));
    }
};
struct KeyPair { unsigned short val, idx; };
struct SweepEndpoint { unsigned short m_uiFilterValue, idx; };
struct KeyLess { char value; KeyLess() : value(0) {} };
void __cdecl FUN_00998410(KeyPair*, int, int, KeyLess);
inline void hkQuickSort(KeyPair* keys, int n, KeyLess cmp) {
    if (n > 1) FUN_00998410(keys, 0, n - 1, cmp);
}
struct SweepNodes {
    Elem* m_data;
    int m_size;
    int m_capacity;
    int GetLogicalSize() const { return m_size; }
    Elem& operator[](int i) { return m_data[i]; }
};
struct AxisPair { void* p; int n; int capacity; };
struct Sweep {
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
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    SweepNodes m_kNodeCollection;
    AxisPair m_ac[3];
    int m_d0;
    int m_d4;
    Sub* m_d8;
    void hkp3AxisSweep_defragment();
};

// pdb: hkp3AxisSweep::defragment | hkp3AxisSweep.obj | fnv360_0822_retail, objrun_prop + skyrim(objrun_prop), high
void Sweep::hkp3AxisSweep_defragment()
{
    void* (__stdcall* tls)(unsigned long) = DAT_00d9b080;
    int n = m_kNodeCollection.GetLogicalSize();

    SweepThreadMemory* mem = (SweepThreadMemory*)tls(DAT_010f3170);
    int elemBytes = (n * (int)sizeof(Elem) + 16) & ~15;
    char* elemCur = mem->current;
    Elem* tmp;
    if (elemCur + elemBytes <= mem->end) {
        mem->current = elemCur + elemBytes;
        tmp = (Elem*)elemCur;
    } else {
        tmp = (Elem*)mem->OnStackOverflow(elemBytes);
    }

    mem = (SweepThreadMemory*)tls(DAT_010f3170);
    int pairBytes = (n * (int)sizeof(KeyPair) + 16) & ~15;
    char* pairCur = mem->current;
    KeyPair* keys;
    if (pairCur + pairBytes <= mem->end) {
        mem->current = pairCur + pairBytes;
        keys = (KeyPair*)pairCur;
    } else {
        keys = (KeyPair*)mem->OnStackOverflow(pairBytes);
    }

    mem = (SweepThreadMemory*)tls(DAT_010f3170);
    int intBytes = (n * (int)sizeof(int) + 16) & ~15;
    char* intCur = mem->current;
    int* remap;
    if (intCur + intBytes <= mem->end) {
        mem->current = intCur + intBytes;
        remap = (int*)intCur;
    } else {
        remap = (int*)mem->OnStackOverflow(intBytes);
    }

    for (int i = 0; i < m_kNodeCollection.GetLogicalSize(); i++) {
        tmp[i] = m_kNodeCollection[i];
        keys[i].val = ((SweepEndpoint*)m_ac[0].p)[m_kNodeCollection[i].m_usValue08].m_uiFilterValue;
        keys[i].idx = (unsigned short)i;
    }

    hkQuickSort(&keys[1], n - 1, KeyLess());

    for (int i = 0; i < m_kNodeCollection.GetLogicalSize(); i++) {
        remap[keys[i].idx] = i;
        m_kNodeCollection[i] = tmp[keys[i].idx];
    }

    for (int i = 1; i < m_kNodeCollection.GetLogicalSize(); i++) {
        int* h = m_kNodeCollection[i].h;
        Elem& node = m_kNodeCollection[i];
        if (((unsigned)node.h & 1) == 0) {
            *h = i;
        } else {
            node.getMarker(m_d8)->x = (unsigned short)i;
        }
    }

    for (int j = 0; j < m_d0; j++) {
        Sub* x = &m_d8[j];
        for (int idx = x->n - 1; idx >= 0; idx--) {
            x->idx[idx] = (unsigned short)remap[x->idx[idx]];
        }
    }

    for (int a = 0; a < 3; a++) {
        KeyPair* w = (KeyPair*)m_ac[a].p;
        for (int idx = 0; idx < m_ac[a].n; idx++) {
            w[idx].idx = (unsigned short)remap[w[idx].idx];
        }
    }

    void* (__stdcall* freeTls)(unsigned long) = DAT_00d9b080;
    SweepThreadMemory* freemem = (SweepThreadMemory*)freeTls(DAT_010f3170);
    freemem->Free((char*)remap);
    freemem = (SweepThreadMemory*)freeTls(DAT_010f3170);
    freemem->Free((char*)keys);
    freemem = (SweepThreadMemory*)freeTls(DAT_010f3170);
    freemem->Free((char*)tmp);
}
}   // namespace f3m_00996cf0
