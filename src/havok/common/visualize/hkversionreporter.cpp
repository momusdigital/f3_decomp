#include "f3_common.h"
// src/havok/common/visualize/hkversionreporter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkversionreporter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
struct S_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_Alloc* m0c;
    S_Alloc* m10;
    S_Alloc& temp()
    {
        return *m0c;
    }
    S_Alloc& heap()
    {
        return *m10;
    }
};
S_Router* FUN_00c85750();
int hkString_strLen(const char* s);

struct S_Arr
{
    char* data;
    int size;
    int cap;
    void clear(S_Alloc& a)
    {
        size = 0;
        if ((cap & 0x80000000) == 0)
            a.ReturnMemory(data, cap & 0x3fffffff);
        data = 0;
        cap = 0x80000000;
    }
};

struct S_Writer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct S_Out
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_Out* FUN_00dda690(S_Arr* a);
    S_Out* FUN_00dda6e0(const char* name);
    void hkOArchive_write8u(unsigned v);
    void WriteInt(unsigned v);
    void WriteUInt16(unsigned v);
    void FUN_00d607b0(const void* p, int n);
    void FUN_00d60590();
};
struct S_Str : S_Arr
{
    S_Str* InitBuffer();
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
};
int FUN_00d61d00(S_Str* s, const char* fmt, ...);
extern int DAT_011b5dc0;
extern int DAT_011b5dbc;

// Builds a string with the PC_32 value and "MSVC:1500", writes both into a stream, then writes the accumulated buffer to the named output and clears the buffers.
// @f3 0x009ef2c0 (community match, verified in this file)
struct Buffer569 {char* data;int size;unsigned int capacity;};
struct Writer569 {
    int unk00,unk04,unk08,unk0c;
    void FUN_00a62350(Buffer569*);
    void FUN_009ee560(int);
    void FUN_009ee8d0(unsigned int);
    void FUN_009ee8b0(int);
    void FUN_009ee740(const void*,int);
    void FUN_00a62560(const char*);
    void FUN_009ee850();
};
struct Heap569 {void FUN_008f6d90(void*,unsigned int,int);};
extern unsigned long DAT_010f3170;
extern Heap569* (__stdcall* DAT_00d9b080)(unsigned long);
extern unsigned int DAT_01063010,DAT_0106300c;
extern char DAT_00e8097c;
int __cdecl FUN_009233f0(const char*);
// pdb: hkVersionReporter::sendVersionInformation | hkVersionReporter.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: connection
int __cdecl WriteCompilerInfo(const char* name){
    Buffer569 buffer;
    buffer.data=0;buffer.size=0;buffer.capacity=0x80000000;
    Writer569 output;
    output.FUN_00a62350(&buffer);
    output.FUN_009ee560(0x90);
    output.FUN_009ee8d0(DAT_01063010);output.FUN_009ee8d0(DAT_0106300c);
    int size=FUN_009233f0(&DAT_00e8097c);
    if(size>65535)size=65535;
    output.FUN_009ee8b0(size);output.FUN_009ee740(&DAT_00e8097c,size);
    Writer569 file;
    file.FUN_00a62560(name);file.FUN_009ee8d0(buffer.size);file.FUN_009ee740(buffer.data,buffer.size);
    file.FUN_009ee850();output.FUN_009ee850();
    if((buffer.capacity & 0x80000000u)==0){
        unsigned int capacity=buffer.capacity & 0x3fffffff;
        Heap569* heap=DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(buffer.data,capacity,23);
    }
    return 0;
}

