#include "f3_common.h"
// src/staging/blk_00a80000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a80000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct BSFadeNode
{
    void* vtbl;
    static void* operator new(unsigned int size);
};
extern "C" void NiFreeAlias(void*);
void __cdecl NiFreeAlias(void*);
void NiFree(void*);
void NiFreeAlias(void*);
extern "C" void __cdecl NiFreeAlias(void*);
struct CloningProcess;
struct NiExtraData
{
    void* p;
    void FUN_00a7b330(void* dst, CloningProcess* cp);
};
struct NiLODData
{
    NiLODData();
    void* operator new(size_t, void* p)
    {
        return p;
    }
};
struct NiProperty
{
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    short m_18;
    short m_1a;
    int m_1c;
    NiProperty();
};
void __cdecl NiFree(void*);
void* __cdecl NiMalloc(unsigned int);
extern const void* vftable_NiRefObject;
void __cdecl FUN_00a9b8b0();
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_0109e470;
void NiFree(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern const void* vftable_NiRefObject;
struct CloningProcess;
void __cdecl NiFree(void*);
void _NiFree(void*);
extern MemoryManager _g_memoryManager;
extern void __cdecl _NiFree(void*);
extern MemoryManager _g_memoryManager;
void __cdecl operator delete(void* p, unsigned int);
void __cdecl FUN_00a9b8b0();
void __cdecl FUN_00a9b9b0();
static const float kPi = 3.1415927f;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct S_a819e0_O
{
    virtual ~S_a819e0_O()
    {}
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
};
// FUN_00a81ba0 : constructor of a plain object whose first member is the
// class vtable pointer. Clears the dword fields at +4..+0x18, a word at +0x22
// and a dword at +0x28.
extern int DAT_0109e470;
extern MemoryManager g_memoryManager;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
void* __cdecl FUN_00aa13e0(unsigned int size) throw();
// FUN_00a87790: thiscall, 10 bytes.
// Loads the vtable pointer of this, reads the function pointer stored in
// vtable slot 0xdc and tail-jumps to it, forwarding the single stack
// argument of this method.
struct BlockColorDecoder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned int ReadWord()
    {
        unsigned int value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodeBlockColors(unsigned char* output);
};
void DecodeBlockColors();
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct S_00a8f2c0_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
extern const void* DAT_0109f4dc;
struct S_00a8f2c0_Sub
{
    int unk00;
    void FUN_00a5f860(S_00a8f2c0_Arg* c);
};
struct S_00a8f2c0_Obj
{
    void* vft;
    int unk04;
    int unk08;
    int unk0c;
    S_00a8f2c0_Sub sub;
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    S_00a8f2c0_Obj() throw()
    {
        FUN_00a5d3a0();
        vft = (void*)&DAT_0109f4dc;
        unk08 = 0;
        unk0c = 0;
        sub.unk00 = 0;
    }
    void FUN_00a5d3a0();
    void SetRefObject(S_00a8f2c0_Arg* c);
};
struct FUN_00aa4060_class
{
    void FUN_00aa4060(void* object);
};
extern FUN_00aa4060_class DAT_011f6238;
extern void* __cdecl FUN_00aa13e0(unsigned int);
void __declspec(noreturn) FUN_00aa0dc0();
void __cdecl FUN_00a9b9b0();
extern "C" void* DAT_0109b220;
struct ReferenceHandle
{
    volatile long* value;
    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next)
        {
            if (next != DAT_0109b220)
                InterlockedIncrement(next - 2);
            if (value != DAT_0109b220)
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};

struct MemMgr : MemoryManager
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
void __cdecl NiFree(void* p);

struct WeightEntry
{
    unsigned int index;
    float weight;
};

struct WeightArray
{
    WeightEntry* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;

    WeightArray() throw();
    ~WeightArray()
    {
        NiFree(m_data);
    }
    void SetCapacity(unsigned int cap);
    void Normalize();

    void Add(const WeightEntry& entry)
    {
        if (m_iElementCount == m_pRayCursor)
            SetCapacity(m_pRayCursor > 0 ? m_pRayCursor * 2 : 1);
        m_data[m_iElementCount] = entry;
        m_iElementCount++;
    }

    static void* operator new[](unsigned int size)
    {
        return static_cast<MemMgr&>(g_memoryManager).Allocate(size);
    }
    static void operator delete[](void* p)
    {
        static_cast<MemMgr&>(g_memoryManager).Deallocate(p);
    }
};

struct BoneWeight
{
    unsigned short vertex;
    unsigned short pad02;
    float weight;
};

struct SkinBone
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    BoneWeight* weights;
    unsigned short weightCount;
    unsigned short unk4A;
};

struct SkinData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    SkinBone* bones;
    unsigned int boneCount;
};

// @fnv 0x00a84810
// pdb: NiSkinPartition::CreateVertexInteractions | NiSkinPartition.obj | fnv360_0822_retail, call_gap + bridge(call_seq|objrun_prop) + skyrim(call_gap), high
WeightArray* __stdcall NiSkinPartition_CreateVertexInteractions(unsigned int vertexCount, SkinData* skin)
{
    WeightArray* arrays = new WeightArray[vertexCount];
    unsigned int boneCount = skin->boneCount;
    for (unsigned int i = 0; i < boneCount; i++)
    {
        SkinBone* bone = &skin->bones[i];
        for (unsigned int j = 0; j < bone->weightCount; j++)
        {
            WeightEntry entry;
            entry.index = i;
            entry.weight = bone->weights[j].weight;
            arrays[bone->weights[j].vertex].Add(entry);
        }
    }
    for (unsigned int k = 0; k < vertexCount; k++)
    {
        if (arrays[k].m_iElementCount == 0)
        {
            delete[] arrays;
            return 0;
        }
        arrays[k].Normalize();
        arrays[k].Normalize();
    }
    return arrays;
}

void __cdecl FUN_00aa10f0(void* p);  // NiFree

struct S911d0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pkName0;
    void* m_pkName1;
    void* m_pkName2;
};

class S911d0_EntryPool
{
  public:
    void FindOrAdd(S911d0_Entry** ppkEntry);  // Delete
};
extern S911d0_EntryPool* DAT_011f5e50;

template <class T> class S911d0_ArrayBase
{
  public:
    virtual ~S911d0_ArrayBase()
    {
        FUN_00aa10f0(m_pBase);
    }

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else if (m_pBase[uiIndex] != 0)
        {
            m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    void FUN_00a90180(int iFlags);

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class S911d0_Base
{
  public:
    virtual ~S911d0_Base();  // FUN_00a7b8c0
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
};

class FUN_00a911d0 : public S911d0_Base
{
  public:
    virtual ~FUN_00a911d0();
    S911d0_ArrayBase<S911d0_Entry*> m_kEntries;
};

// @fnv 0x00a911d0
// pdb: NiScreenGeometryData::~NiScreenGeometryData | NiOldScreenSpace.obj | fnv360_0721_beta, objrun, medium
FUN_00a911d0::~FUN_00a911d0()
{
    for (unsigned int i = 0; i < m_kEntries.GetSize(); i++)
    {
        S911d0_Entry* pkEntry = m_kEntries.GetAt(i);
        m_kEntries.SetAt(i, 0);
        if (pkEntry)
        {
            DAT_011f6238.FUN_00aa4060(pkEntry->m_pkName0);
            DAT_011f6238.FUN_00aa4060(pkEntry->m_pkName1);
            DAT_011f6238.FUN_00aa4060(pkEntry->m_pkName2);
            S911d0_Entry* pkDelete = pkEntry;
            DAT_011f5e50->FindOrAdd(&pkDelete);
        }
    }
    m_kEntries.FUN_00a90180(0);
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;
class NiPixelFormat
{
  public:
    NiPixelFormat();
    bool operator==(const NiPixelFormat&) const;
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
};
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat DAT_011aa2a0;
struct BmpColor
{
    unsigned char r, g, b, a;
};
class FUN_00a8b110 : public NiRefObject
{
  public:
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    FUN_00a8b110(bool, unsigned int, const BmpColor*);
};
class NiPixelData
{
  public:
    void* vtable;
    unsigned int refs;
    NiPixelFormat format;
    FUN_00a8b110* palette;
    unsigned char* pixels;
    unsigned int* width;
    unsigned int* height;
    unsigned int* offsets;
    unsigned int levels;
    unsigned int stride;
    unsigned int unk68, unk6c, unk70;
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int = 1, unsigned int = 1);
    unsigned char* Pixels()
    {
        return pixels + offsets[0];
    }
    void SetPalette(FUN_00a8b110* p)
    {
        if (palette != p)
        {
            if (palette)
                palette->DecRefCount();
            palette = p;
            if (palette)
                palette->IncRefCount();
        }
    }
};
struct BmpStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int, int);
    unsigned int position;
    unsigned int(__cdecl* read)(BmpStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int size)
    {
        unsigned int component = 1;
        position += read(this, dst, size, &component, 1);
    }
};
struct BmpReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Header(BmpStream&, unsigned int&, unsigned int&, NiPixelFormat&, bool&, unsigned int&);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int width, height;
    NiPixelFormat format;
    unsigned short bpp;
    unsigned int colorCount, dataOffset;
    bool flip;
    NiPixelData* FUN_00a8e810(BmpStream& stream, NiPixelData* optional);
};
// @fnv 0x00a8e810
// pdb: NiBMPReader::ReadFile | NiBMPReader.obj | tesv_win, vtable, medium
NiPixelData* BmpReader::FUN_00a8e810(BmpStream& stream, NiPixelData* optional)
{
    bool mipmap;
    unsigned int w, h, faces;
    NiPixelFormat headerFormat;
    DAT_00fdf05c(&unk080);
    if (!Header(stream, w, h, headerFormat, mipmap, faces))
    {
        DAT_00fdf100(&unk080);
        return 0;
    }
    NiPixelData* dest;
    if (optional && optional->width[0] == width && optional->height[0] == height && optional->format == format)
        dest = optional;
    else
        dest = new NiPixelData(width, height, format);
    if (format == DAT_011aa210)
    {
        BmpColor colors[256];
        stream.Read(colors, colorCount * sizeof(BmpColor));
        BmpColor* color = colors;
        for (unsigned int i = 0; i < colorCount; ++i, ++color)
        {
            unsigned char temp = color->r;
            color->r = color->b;
            color->b = temp;
            color->a = 255;
        }
        dest->SetPalette(new FUN_00a8b110(false, 256, colors));
    }
    else
    {
        stream.Seek(colorCount * sizeof(BmpColor), DAT_010a2484);
    }
    int extra = dataOffset - 54 - colorCount * sizeof(BmpColor);
    if (extra > 0)
        stream.Seek(extra, DAT_010a2484);
    unsigned int imageSize = (((width * bpp + 31) & ~31) >> 3) * height;
    unsigned int rowSize = dest->width[0] * dest->stride;
    if (bpp == 4)
    {
        unsigned int packedSize = (width >> 1) + (width & 1);
        unsigned int padding = (packedSize & 3) ? 4 - (packedSize & 3) : 0;
        unsigned char* input = (unsigned char*)NiMalloc(packedSize + padding);
        unsigned char* row;
        int step;
        if (flip)
        {
            row = dest->Pixels() + rowSize * (dest->height[0] - 1);
            step = -(int)rowSize;
        }
        else
        {
            row = dest->Pixels();
            step = rowSize;
        }
        for (unsigned int y = 0; y < height; ++y, row += step)
        {
            stream.Read(input, packedSize + padding);
            unsigned char* out = row;
            unsigned char* in = input;
            for (unsigned int x = 0; x < packedSize; ++x)
            {
                *out++ = *in >> 4;
                *out++ = *in & 15;
                ++in;
            }
        }
        NiFree(input);
    }
    else
    {
        if (flip)
        {
            unsigned char* row = dest->Pixels() + rowSize * (height - 1);
            unsigned int y;
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char dummy[4];
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                    row -= rowSize;
                }
            }
            else
            {
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    row -= rowSize;
                }
            }
        }
        else
        {
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char* row = dest->Pixels();
                unsigned char dummy[4];
                for (unsigned int y = 0; y < height; ++y, row += rowSize)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                }
            }
            else
            {
                stream.Read(dest->Pixels(), imageSize);
            }
        }
    }
    if (format == DAT_011aa2e8 || format == DAT_011aa2a0)
    {
        unsigned int pixelStride = dest->stride;
        unsigned int count = width * height;
        unsigned char* pixel = dest->Pixels();
        for (unsigned int i = 0; i < count; ++i, pixel += pixelStride)
        {
            unsigned char swap = pixel[0];
            pixel[0] = pixel[2];
            pixel[2] = swap;
        }
    }
    DAT_00fdf100(&unk080);
    return dest;
}

inline void* operator new[](unsigned int size, int) throw()
{
    return static_cast<MemMgr&>(g_memoryManager).Allocate(size);
}

struct Interaction
{
    unsigned int bone;
    float weight;
};

struct TempRecord
{
    void* data;
    unsigned int size;
    unsigned int count;
    ~TempRecord()
    {
        NiFree(data);
    }
    static void operator delete[](void* block)
    {
        g_memoryManager.Deallocate(block);
    }
};

struct Holder
{
    void* data;
    unsigned int size;
    unsigned int count;
    unsigned short index;
    unsigned short flags;
    ~Holder()
    {
        NiFree(data);
    }
    static void operator delete(void* block)
    {
        g_memoryManager.Deallocate(block);
    }
    bool ContainsSortedSubset(const Holder* other);
};

__declspec(noinline) bool Holder::ContainsSortedSubset(const Holder* other)
{
    unsigned int i = 0;
    for (unsigned int j = 0; j < other->count; ++j, ++i)
    {
        while (i < count &&
               static_cast<const unsigned short*>(data)[i] < static_cast<const unsigned short*>(other->data)[j])
            ++i;
        if (i == count ||
            static_cast<const unsigned short*>(data)[i] != static_cast<const unsigned short*>(other->data)[j])
            return false;
    }
    return true;
}

struct SourceGeometry
{
    unsigned int unk00, unk04;
    unsigned short vertexCount, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned short triangleCount, unk42;
    unsigned short GetCount() const
    {
        return vertexCount;
    }
    unsigned short GetTriangleCount() const
    {
        return triangleCount;
    }
};

struct SkinBuildData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned int unk20;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int boneCount;
};

struct C082d30
{
    void* data;
    unsigned int size;
    unsigned int count;
    void NiSkinPartition_TriangleSet_AddTriangles(int, void*, unsigned int);
    void Grow(unsigned int);
};

// pdb: NiSkinPartition::TriangleSet::AddTriangles | NiSkinPartition.obj | fnv360_0822_retail, call_gap_sim, high (was: AppendMatchingIndices)
__declspec(noinline) void C082d30::NiSkinPartition_TriangleSet_AddTriangles(int partition, void* assignments, unsigned int triangleTotal)
{
    const int* map = static_cast<const int*>(assignments);
    for (unsigned int triangle = 0; triangle < triangleTotal; ++triangle)
    {
        if (map[triangle] != partition)
            continue;
        if (count == size)
            Grow(size == 0 ? 1 : 2 * size);
        static_cast<unsigned short*>(data)[count] = static_cast<unsigned short>(triangle);
        ++count;
    }
}

struct FUN_00a81ba0
{
    void* m_pVTable;
    unsigned short* m_04;
    float* m_08;
    unsigned short* m_0c;
    unsigned char* m_10;
    unsigned short* m_14;
    unsigned short* m_18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int m_28;

    FUN_00a81ba0() throw();
    ~FUN_00a81ba0()
    {}
    unsigned short* BuildVertexRemapTable(C082d30*, SourceGeometry*);
    void BuildTriangleList(C082d30*, SourceGeometry*, unsigned short*);
    void NiSkinPartition_Partition_Create(C082d30*, Holder*, SourceGeometry*, TempRecord*, bool, bool, unsigned char, unsigned int);
};
typedef FUN_00a81ba0 OutputRecord;

void __cdecl _memmove(void*, const void*, unsigned int);

struct HolderArray
{
    Holder** volatile data;
    unsigned int capacity;
    unsigned int count;
};

struct GeometryBuilder
{
    unsigned int unk00, unk04, count;
    OutputRecord* output;
    TempRecord* NiSkinPartition_CreateVertexInteractions(unsigned int, SkinBuildData*);
    bool NiSkinPartition_RemoveExcessInteractions(SourceGeometry*, unsigned char, unsigned char, TempRecord*);
    bool NiSkinPartition_MakeBoneSets(SourceGeometry*, SkinBuildData*, unsigned char, TempRecord*, HolderArray*, void**,
                      OutputRecord**);
    bool NiSkinPartition_MakePartitions(SourceGeometry*, SkinBuildData*, unsigned char, unsigned char, bool, OutputRecord**,
                      unsigned short*, unsigned char*);
};

// pdb: NiSkinPartition::Partition::Create | NiSkinPartition.obj | fnv360_0822_retail, call_gap_sim, high (was: PopulateSkinData)
__declspec(noinline) void FUN_00a81ba0::NiSkinPartition_Partition_Create(C082d30* triangles, Holder* bones, SourceGeometry* geometry,
                                                         TempRecord* interactions, bool padBones, bool makePalette,
                                                         unsigned char width, unsigned int totalBones)
{
    unsigned int paletteCount = bones->count;
    if (paletteCount < width)
        paletteCount = width;
    unk20 = static_cast<unsigned short>(paletteCount);
    triangleTotal = static_cast<unsigned short>(triangles->count);
    m_04 = static_cast<unsigned short*>(NiMalloc(2 * unk20));
    for (unsigned int i = 0; i < unk20; ++i)
        m_04[i] = i < bones->count ? static_cast<unsigned short*>(bones->data)[i] : 0;
    unsigned short* translation = BuildVertexRemapTable(triangles, geometry);
    BuildTriangleList(triangles, geometry, translation);
    NiFree(translation);
    float* destination;
    if (padBones)
    {
        influencesPerVertex = width;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(NiMalloc(sizeof(float) * count));
        m_10 = static_cast<unsigned char*>(NiMalloc(count));
        unsigned int* remap = static_cast<unsigned int*>(NiMalloc(sizeof(unsigned int) * totalBones));
        for (unsigned int bone = 0; bone < bones->count; ++bone)
            remap[m_04[bone]] = bone;
        destination = m_08;
        unsigned char* palette = m_10;
        float* weights = static_cast<float*>(NiMalloc(sizeof(float) * influencesPerVertex));
        unsigned char* paletteIndices = static_cast<unsigned char*>(NiMalloc(influencesPerVertex));
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < record.count; ++slot)
            {
                weights[slot] = entries[slot].weight;
                paletteIndices[slot] = static_cast<unsigned char>(remap[entries[slot].bone]);
            }
            for (; slot < influencesPerVertex; ++slot)
            {
                weights[slot] = 0.0f;
                paletteIndices[slot] = 0;
            }
            for (unsigned int outputSlot = 0; outputSlot < influencesPerVertex; ++outputSlot)
            {
                unsigned int selected = 0;
                float largest = weights[0];
                for (unsigned int candidate = 1; candidate < influencesPerVertex; ++candidate)
                {
                    if (weights[candidate] > largest)
                    {
                        selected = candidate;
                        largest = weights[candidate];
                    }
                }
                *destination++ = weights[selected];
                *palette++ = paletteIndices[selected];
                weights[selected] = -1.0f;
            }
        }
        NiFree(weights);
        NiFree(paletteIndices);
        NiFree(remap);
    }
    else
    {
        influencesPerVertex = unk20;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(NiMalloc(sizeof(float) * count));
        destination = m_08;
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < bones->count; ++slot)
            {
                float weight = 0.0f;
                unsigned int bone = static_cast<const unsigned short*>(bones->data)[slot];
                for (unsigned int interaction = 0; interaction < record.count; ++interaction)
                {
                    if (entries[interaction].bone == bone)
                    {
                        weight = entries[interaction].weight;
                        break;
                    }
                }
                *destination++ = weight;
            }
            for (; slot < unk20; ++slot)
                *destination++ = 0.0f;
        }
        if (makePalette)
        {
            m_10 = static_cast<unsigned char*>(NiMalloc(count));
            unsigned char* palette = m_10;
            for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
                for (unsigned int bone = 0; bone < unk20; ++bone)
                    *palette++ = static_cast<unsigned char>(bone);
        }
    }
}

// @fnv 0x00a84980
// pdb: NiSkinPartition::MakePartitions | NiSkinPartition.obj | fnv360_0822_retail, call_gap + bridge(call_gap|objrun_prop) + skyrim(call_gap), high
bool GeometryBuilder::NiSkinPartition_MakePartitions(SourceGeometry* source, SkinBuildData* other, unsigned char first,
                                   unsigned char second, bool mode, OutputRecord** outputs, unsigned short* indices,
                                   unsigned char* changes)
{
    HolderArray holders = {0, 0, 0};
    void* data;
    TempRecord* records = NiSkinPartition_CreateVertexInteractions(source->GetCount(), other);
    if (!records)
    {
        NiFree(records);
        return false;
    }

    bool success = NiSkinPartition_RemoveExcessInteractions(source, first, second, records);
    if (success)
    {
        success = NiSkinPartition_MakeBoneSets(source, other, first, records, &holders, &data, outputs);
        if (outputs && indices && changes)
        {
            for (unsigned int i = 0; i < holders.count; ++i)
            {
                Holder** entries = holders.data;
                Holder* current = entries[i];
                indices[i] = current->index;
                if (i)
                {
                    Holder* previous = entries[i - 1];
                    if (current->ContainsSortedSubset(previous) && current->count == previous->count)
                        changes[i] = 0;
                    else
                        changes[i] = 1;
                }
                else
                {
                    changes[0] = 1;
                }
            }
        }
        OutputRecord* result = new (0) OutputRecord[count];
        bool padBones = (first != second);
        C082d30 scratch;
        scratch.data = 0;
        scratch.size = 0;
        scratch.count = 0;
        for (unsigned int i = 0; i < count; ++i)
        {
            scratch.NiSkinPartition_TriangleSet_AddTriangles(i, data, source->GetTriangleCount());
            Holder* current = const_cast<Holder**&>(holders.data)[i];
            result[i].NiSkinPartition_Partition_Create(&scratch, current, source, records, padBones, mode, second,
                                       (*(SkinBuildData* volatile*)&other)->boneCount);
            scratch.count = 0;
            delete current;
        }
        NiFree(data);
        while (count)
        {
            unsigned int i = 0;
            for (; i < count; ++i)
            {
                if (!(unsigned short)result[i].unk1c)
                {
                    for (unsigned int j = i; j < count - 1; ++j)
                    {
                        _memmove(&result[j], &result[j + 1], sizeof(OutputRecord));
                        outputs[j] = outputs[j + 1];
                        indices[j] = indices[j + 1];
                        changes[j] = changes[j + 1];
                    }
                    --count;
                    break;
                }
            }
            if (i == count)
                break;
        }
        output = result;
        NiFree(scratch.data);
    }
    delete[] records;
    NiFree(holders.data);
    return success;
}
