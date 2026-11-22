// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DdabeTag
{
    bool b;
    DdabeTag() : b(false)
    {}
    DdabeTag(const DdabeTag& o) : b(o.b)
    {}
};

class hkClass;
class hkStatisticsCollector;
// hkIStream: the three slots of the Fallout 3 vtable of hkDisplaySerializeIStream (0x00e86d68).
struct DdabeBase
{
    DdabeBase(int a, DdabeTag t);
    virtual ~DdabeBase();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
};

struct hkDisplaySerializeIStreamDDAB : DdabeBase
{
    hkDisplaySerializeIStreamDDAB(int a);
};

// @fnv 0x00ddabe0
// pdb: hkDisplaySerializeIStream::hkDisplaySerializeIStream | hkDisplaySerializeIStream.obj | fnv360_0822_retail, uvref, medium
// pdb params: reader
hkDisplaySerializeIStreamDDAB::hkDisplaySerializeIStreamDDAB(int a) : DdabeBase(a, DdabeTag())
{}

struct FUN_00ddac60_Obj
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

void __stdcall FUN_00dd8fe0(FUN_00ddac60_Obj* obj, int a, int b);

// @fnv 0x00ddac60
// pdb: hkDisplaySerializeIStream::readQuadVector4 | hkDisplaySerializeIStream.obj | fnv360_0822_retail, call_seq, low, conflict (skyrim: `anonymous namespace'::Reader::readFloat)
// pdb params: v
void __stdcall FUN_00ddac60(FUN_00ddac60_Obj* obj)
{
    FUN_00dd8fe0(obj, 4, 3);
    obj->unk0C = 0.0f;
}

struct ArrayRecord
{
    void* data;
    int size;
    int capacity;
};
struct ArrayPair
{
    ArrayRecord first;
    ArrayRecord second;
};
struct FUN_00ddacd0_shell
{
    void __thiscall FUN_00dd8fe0(void* output, int elementSize, int count);
    void __thiscall FUN_00ddac60(void* output);
    void __thiscall hkDisplaySerializeIStream_readTriangle(void* output);
    void __thiscall FUN_00ddacd0(ArrayPair* arrays);
};
// @f3 0x00a62a00 (community match, verified in this file)
extern "C" void __cdecl FUN_00901e90(void*,int,int);
struct F3ArrayReader {void FUN_00a62980(void*); void FUN_00a62920(void*);};
// pdb: hkDisplaySerializeIStream::readGeometry | hkDisplaySerializeIStream.obj | fnv360_0822_retail, objrun, low, conflict (skyrim: `anonymous namespace'::Reader::readBitfield)
// pdb params: g
void __thiscall FUN_00ddacd0_shell::FUN_00ddacd0(ArrayPair* arrays)
{
    ArrayPair* originalArrays;
    int& remaining=reinterpret_cast<int&>(arrays);
    {
        int firstCount;
        FUN_00dd8fe0(&firstCount, 4, 1);
        originalArrays=arrays;
        if (firstCount > 0)
        {
            for (remaining = firstCount; remaining != 0; --remaining)
            {
                ArrayRecord* array = &originalArrays->first;
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (!(needed < grown))
                        grown = needed;
                    FUN_00901e90(array, grown, 16);
                }
                array->size = size + 1;
                void* output = (char*)array->data + size * 16;
                reinterpret_cast<F3ArrayReader*>(this)->FUN_00a62980(output);
            }
        }
    }
    {

        FUN_00dd8fe0(&remaining, 4, 1);
        int secondCount=*(volatile int*)&remaining;
        if (secondCount > 0)
        {
            ArrayRecord* array = &originalArrays->second;
            for (remaining=secondCount; remaining != 0; --remaining)
            {
                int size = array->size;
                int needed = size + 1;
                int capacity = array->capacity & 0x3fffffff;
                if (capacity < needed)
                {
                    int grown = capacity * 2;
                    if (!(needed < grown))
                        grown = needed;
                    FUN_00901e90(array, grown, 12);
                }
                array->size = size + 1;
                void* output = (char*)array->data + size * 12;
                reinterpret_cast<F3ArrayReader*>(this)->FUN_00a62920(output);
            }
        }
    }
}


#include <xmmintrin.h>
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_008cd6a0_Class
{
    void FUN_00cb2d90(void* value);
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
    __m128 unk30;
};
struct hkIArchive
{
    void FUN_00dd8fe0(void* destination, int componentSize, int components);
};
struct hkDisplaySerializeIStream : hkIArchive
{
    void FUN_00ddac80(FUN_008cd6a0_Class* target);
};
// Reads a 3-component vector (w set to 1.0f) into target->unk30 and a 4-component value that is passed to target->FUN_00cb2d90.
// @f3 0x00a629a0 (community match, verified in this file)
struct CB2FC0Object
{
    void FUN_00cb2d90(void* value);
};

struct FUN_008cd6a0_View
{
    char pad00[0x30];
    float x;
    float y;
    float z;
    float w;
};

// pdb: hkDisplaySerializeIStream::readTransform | hkDisplaySerializeIStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: t
void hkDisplaySerializeIStream::FUN_00ddac80(FUN_008cd6a0_Class* target)
{
    Vec4 source;
    Vec4 destination;
    FUN_00ddacd0_shell* stream = (FUN_00ddacd0_shell*)this;
    stream->FUN_00dd8fe0(&source, 4, 3);
    source.w = 1.0f;
    stream->FUN_00dd8fe0(&destination, 4, 4);
    FUN_008cd6a0_View* view = (FUN_008cd6a0_View*)target;
    view->x = source.x;
    view->y = source.y;
    view->z = source.z;
    view->w = source.w;
    ((CB2FC0Object*)target)->FUN_00cb2d90(&destination);
}


// Reads three 4-byte integers via FUN_00dd8fe0 and stores them sequentially into the output buffer.
// @fnv 0x00ddac00
// pdb: hkDisplaySerializeIStream::readTriangle | hkDisplaySerializeIStream.obj | fnv360_0822_retail, objrun + bridge(hash|caller_sim), high
__declspec(noinline) void __thiscall FUN_00ddacd0_shell::hkDisplaySerializeIStream_readTriangle(void* output)
{
    int* dst = (int*)output;
    {
        int val1;
        FUN_00dd8fe0(&val1, 4, 1);
        dst[0] = val1;
    }
    {
        int val2;
        FUN_00dd8fe0(&val2, 4, 1);
        dst[1] = val2;
    }
    {
        int val3;
        FUN_00dd8fe0(&val3, 4, 1);
        dst[2] = val3;
    }
}
