#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <new>
#include <stdlib.h>
#include <string.h>
// src/f3staging/f3blk_00440000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x0045bab0 (community match, verified in this file)
extern char DAT_011f6238;
namespace f3m_0045bab0 {

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" unsigned int __cdecl strlen(const char* s);

struct ArgCh {
    void FUN_00447d60(char* buf, int a);
};

struct Sub4 {
    void FUN_004037f0(int buf, int a);
};

struct Obj8 {
    int unk0;
    void* ptr4;
    unsigned short unk8;
    unsigned short unkA;
};

struct A1450MemoryManager {
    void Deallocate(void* p);
};


// pdb: TESTexture::LoadTextureChunk | TESTexture.obj | fnv360_0822_retail, call_gap + bridge(call_seq|call_seq) + skyrim(call_seq), high
void __cdecl TESTexture_LoadTextureChunk(Obj8* arg_8h, int* arg_ch) {
    if (arg_ch != 0 && arg_8h != 0) {
        if (arg_ch[0x25c / 4] != 0) {
            char* buf = (char*)_alloca(arg_ch[0x25c / 4]);
            ((ArgCh*)arg_ch)->FUN_00447d60(buf, 0);
            if (strlen(buf) != 0 && buf[0] == '\\') {
                unsigned int i = 0;
                if (strlen(buf) != 0) {
                    do {
                        buf[i] = buf[i + 1];
                        i++;
                    } while (i < strlen(buf));
                }
            }
            ((Sub4*)((char*)arg_8h + 4))->FUN_004037f0((int)buf, 0);
        } else {
            if (arg_8h->ptr4 != 0) {
                ((A1450MemoryManager*)&DAT_011f6238)->Deallocate(arg_8h->ptr4);
            }
            arg_8h->ptr4 = 0;
            arg_8h->unkA = 0;
            arg_8h->unk8 = 0;
        }
    }
}
}   // namespace f3m_0045bab0
