#include <new>
// src/f3staging/f3iso_009326c0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009326c0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009326c0 (community match, verified in this file)
struct NameRegistry;
struct NameMethods { void* preceding[9]; void (__thiscall *add)(NameRegistry*,void*); };
struct NameRegistry { NameMethods* methods; };
struct TypeRegistry;
struct TypeMethods { void* preceding[3]; void (__thiscall *add)(TypeRegistry*,void*); };
struct TypeRegistry { TypeMethods* methods; };
struct Table { void FUN_009b0320(void**,void**); };
extern NameRegistry* DAT_011693a0;
extern TypeRegistry* DAT_011693a4;
extern Table* DAT_011693a8;
extern int DAT_010f343c, DAT_00e37634;
extern void* DAT_00e7c9c8[], *DAT_00e7cb68;
struct BuiltinRegistry { void* vtable; unsigned short size,references; BuiltinRegistry* FUN_009326c0(); };
// pdb: hkCreateBuiltInTypeRegistry | hkBuiltinTypeRegistry.obj | fnv360_0822_retail, uvref, low, conflict (skyrim: hkDefaultBuiltinTypeRegistry::init)
BuiltinRegistry* BuiltinRegistry::FUN_009326c0() {
    references=1; vtable=&DAT_00e37634;
    NameRegistry* names=DAT_011693a0;
    names->methods->add(names,&DAT_010f343c);
    void** entries=DAT_00e7c9c8;
    void* current=*entries;
    TypeRegistry* registry=DAT_011693a4;
    while(current) { registry->methods->add(registry,current); current=*++entries; }
    DAT_011693a8->FUN_009b0320(DAT_00e7c9c8,&DAT_00e7cb68);
    return this;
}
