#include "f3_common.h"
// src/staging/blk_00ce0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_010cc164;
void __cdecl FUN_00d86220();

struct FUN_00cf45d0_class
{
    int vtable;
    FUN_00cf45d0_class();
};

// @fnv 0x00cf45d0
FUN_00cf45d0_class::FUN_00cf45d0_class()
{
    FUN_00d86220();
    vtable = (int)&DAT_010cc164;
}

struct hkReferencedObject
{
    void RetainReference();
};

struct FUN_00cf4ca0_class
{
    int m_auiShapeKeys[6];
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    void FUN_00cf4ca0();
};

// @fnv 0x00cf4ca0
void FUN_00cf4ca0_class::FUN_00cf4ca0()
{
    if (m_kPointA)
        m_kPointA->RetainReference();
    if (m_kPointB)
        m_kPointB->RetainReference();
}

struct FUN_00cf86f0_class
{
    int IsFieldEqual();
};

// @fnv 0x00cf86f0
// pdb: hkpSimulation::isSimulationAtMarker | hkpSimulation.obj | fnv360_0822_retail, objrun_open, low
int FUN_00cf86f0_class::IsFieldEqual()
{
    if (*(float*)((char*)this + 0x14) == *(float*)((char*)this + 0x20))
        return 1;
    return 0;
}

extern int DAT_010cb864;

extern int DAT_0102e378;

struct FUN_00cf86e0_class
{
    void FUN_00cf86e0(float f);
};
// @fnv 0x00cf86e0
// pdb: hkpSimulation::setFrameTimeMarker | hkpSimulation.obj | fnv360_0822_retail, objrun_open, low
// pdb params: frameDeltaTime
void FUN_00cf86e0_class::FUN_00cf86e0(float f)
{
    *(float*)((char*)this + 0x20) = *(float*)((char*)this + 0x14) + f;
}

extern int DAT_0102e388;

// FUN_00ce29e0: member function that (re)initialises the object.
//   - installs the base vtable pointer at [this],
//   - calls the constructor of the sub-object living at this+0x10,
//   - then installs the vtable pointer of the derived class at [this].
extern int DAT_010cb864;
extern int DAT_0102e388;

// Sub-object at +0x10; FUN_00ce5370 is the game's constructor for it.
struct FUN_00ce5370_cls
{
    void FUN_00ce5370();
};

struct FnvSpawnedObject;

struct FnvProbe
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char* Match(FnvSpawnedObject** ref);
    unsigned char* Check(FnvSpawnedObject** ref);
};

struct FnvSpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FnvProbe m_10;
    FnvProbe m_20;
    unsigned char* Check(FnvSpawnedObject** ref);
};

namespace fnv_00ce5370 {
extern "C" void _ReadWriteBarrier(void);

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct AudioObjectRef
{
    void Release();
};

struct FUN_00ce5370_cls
{
    AudioObjectRef* m_pObj0;
    AudioObjectRef* m_pObj4;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00ce5370();
};

}  // namespace fnv_00ce5370

struct FnvKeyRec
{
    unsigned short m_iOwnerObjectOffset;
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
};

struct FUN_00ce5480_cls
{
    int unk00;
    int unk04;
    FnvKeyRec* m_pRecords;
    int m_uiItemCount;
};

// @fnv 0x00ce5480
// pdb: hkaSkeletonMapperUtils::findSimpleMapping | hkaSkeletonMapperUtils.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: boneA, mapperdata
void* __cdecl FindKeyRecord(unsigned short aKey, FUN_00ce5480_cls* pKeyBox)
{
    for (int i = 0; i < pKeyBox->m_uiItemCount; i++)
    {
        if (pKeyBox->m_pRecords[i].m_iOwnerObjectOffset == aKey)
        {
            return &pKeyBox->m_pRecords[i];
        }
    }
    return 0;
}

void __cdecl FUN_00d86160(void* stream, void* self);

struct DragBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct DragStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};

struct FUN_00cf4490_cls
{
    char unk00[0x14];
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    void FUN_00cf4490(void* stream);
};

// Reads three fields (m_14, m_18, m_1c) from the stream after calling FUN_00d86160.
// @fnv 0x00cf4490
// pdb: bhkVelocityConstraintMotor::SaveBinary | bhkVelocityConstraintMotor.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arStream
void FUN_00cf4490_cls::FUN_00cf4490(void* stream)
{
    FUN_00d86160(stream, this);
    DragStreamView* s = reinterpret_cast<DragStreamView*>(stream);
    s->m_pUnderlyingStream->Load(&m_14);
    s->m_pUnderlyingStream->Load(&m_18);
    s->m_pUnderlyingStream->Load(&m_1c);
}

struct CpuOpaque;
extern CpuOpaque DAT_01268740;
// @fnv 0x00cf45f0
// pdb: bhkConvexTransformShape::GetRTTI | bhkConvexTransformShape.obj | fnv360_0822_retail, udata, medium
CpuOpaque* __cdecl FUN_00cf45f0()
{
    return &DAT_01268740;
}

struct PacketSerializer
{
    int metadata, bytesWritten, reserved;
    typedef int(__cdecl* Fn)(PacketSerializer*, const void*, int, int*, int);
    Fn write;
};
struct SerializedObject
{
    int base00, base04, base08, base0C, base10, word14, word18;
    void __thiscall SerializeToStream(int source);
};
extern "C" void __cdecl FUN_00d86160(int, SerializedObject*);
// Writes word14 and word18 to the stream at source+0x250, accumulating bytesWritten, after calling FUN_00d86160.
// @fnv 0x00cf4670
// pdb: bhkSpringDamperConstraintMotor::SaveBinary | bhkSpringDamperConstraintMotor.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arStream
void SerializedObject::SerializeToStream(int source)
{
    int saved = source;
    FUN_00d86160(saved, this);
    PacketSerializer* __restrict stream = *reinterpret_cast<PacketSerializer**>(saved + 0x250);
    source = 4;
    stream->bytesWritten += stream->write(stream, &word14, 4, &source, 1);
    stream = *reinterpret_cast<PacketSerializer**>(saved + 0x250);
    source = 4;
    stream->bytesWritten += stream->write(stream, &word18, 4, &source, 1);
}

// Save a Havok-wrapped object: write its type id, then let a type-specific saver write the rest.

extern __declspec(thread) int g_iCF4BC0AllocTag;

struct CF4BC0AllocTagScope
{
    int m_iSaved;

    CF4BC0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCF4BC0AllocTag;
        g_iCF4BC0AllocTag = aiAllocationTag;
    }
    ~CF4BC0AllocTagScope()
    {
        g_iCF4BC0AllocTag = m_iSaved;
    }
};

class CF4BC0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(CF4BC0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class CF4BC0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CF4BC0BinaryStream* m_pBackingStream;
};

template <class T>
inline void CF4BC0BinaryStreamSave(CF4BC0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void CF4BC0SaveBinary(CF4BC0Stream& kStream, const T& value)
{
    CF4BC0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

extern int DAT_0102e388;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00cf6980_class
{
    virtual void FUN_00cf6980(int);
};

// @fnv 0x00cf6980
// pdb: cleanupLoadedObjecthkLiquidAction | hkLiquidAction.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00cf6980(FUN_00cf6980_class* object)
{
    object->FUN_00cf6980(0);
}

extern int DAT_01268748;
// @fnv 0x00cf6990
int* __cdecl FUN_00cf6990()
{
    return &DAT_01268748;
}

extern int DAT_0102e378;

namespace fnv_00cf6b10 {
extern "C" void* DAT_01268794;

class SpawnedAllocator
{
  public:
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750();

struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* Init(unsigned int count);
};

// Allocates a 0x18-byte SpawnedObject via the holder's allocator, initializes it with count 0x3e8, and stores the result in DAT_01268794.
// @fnv 0x00cf6b10
void __cdecl FUN_00cf6b10()
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    SpawnedAllocator* alloc = pAllocHolder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x18);
    if (obj != 0)
    {
        DAT_01268794 = obj->Init(0x3e8);
        return;
    }
    DAT_01268794 = 0;
}
}  // namespace fnv_00cf6b10

extern int DAT_01268794;

extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(int value);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(int value);

struct FUN_00cf6f80_cls
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    unsigned __int64 FUN_00cf6f80();
};

// @fnv 0x00cf6f80
// pdb: hkAlgorithm::swap<hkpBroadPhaseHandle *> | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_debug, objrun_open, low, conflict (skyrim: keyFromPair)
// pdb params: x, y
unsigned __int64 FUN_00cf6f80_cls::FUN_00cf6f80()
{
    return *(unsigned __int64*)&m_ucLowNibble;
}

// FUN_00cf8710 : thiscall member returning a bool.
//
// Original shape (24 bytes):
//   fld  dword ptr [ecx+0x18]
//   fld  dword ptr [ecx+0x14]
//   fucompp
//   fnstsw ax
//   test ah,0x44
//   jp   <not equal>
//   mov  eax,1
//   ret
//   <not equal>: xor eax,eax ; ret
//
// i.e. a plain float equality test between the two float members at +0x14 and
// +0x18 of the object, with the +0x18 member loaded first.

struct FUN_00cf8710_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_14;
    float m_18;

    bool FUN_00cf8710();
};

// @fnv 0x00cf8710
// pdb: hkpSimulation::isSimulationAtPsi | hkpSimulation.obj | fnv360_0822_retail, objrun_open, low
bool FUN_00cf8710_cls::FUN_00cf8710()
{
    return m_18 == m_14;
}

class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager _g_memoryManager;

class CF4840Saver
{
  public:
    void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    virtual void DeleteThis(bool bFree);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Build the Havok object for a serialized node: find its creator, run it, keep the result and delete the creator.

extern __declspec(thread) int g_iF4A30AllocTag;

struct F4A30AllocTagScope
{
    int m_iSaved;

    F4A30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iF4A30AllocTag;
        g_iF4A30AllocTag = aiAllocationTag;
    }
    ~F4A30AllocTagScope()
    {
        g_iF4A30AllocTag = m_iSaved;
    }
};

void __cdecl FUN_00ce51f0();
// @fnv 0x00ce5300
// pdb: bhkWorld::SethkObject | bhkWorld.obj | fnv360_0822_retail, caller_sim, low
// pdb params: aphkObject
void __cdecl FUN_00ce5300()
{
    FUN_00ce51f0();
}

class FUN_00ce5360_This
{
  public:
// @fnv 0x00ce5360
    virtual ~FUN_00ce5360_This()
    {}
    unsigned int FUN_00ce5360(unsigned int arg);
};

struct Stream;
typedef int (*StreamIOFunc)(Stream* stream, void* data, int size, int* count, int flag);

struct Stream
{
    int unk00;
    int pos;
    int unk08;
    StreamIOFunc io;
};

struct StreamOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    Stream* stream;
};

struct Record
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
};

static inline void WriteData(Stream* s, void* data, int size)
{
    int count = size;
    s->pos += s->io(s, data, size, &count, 1);
}

// Writes each 4-byte field of the Record to the owner's stream via WriteData, skipping unk0C.
// @fnv 0x00cf09a0
// pdb: bhkStream::SaveBinary | bhkStream.obj | fnv360_0822_retail, objrun, low, conflict (bridge: bhkPoseArray::bhkPose::SaveBinary)
// pdb params: arStream, arTransf
void FUN_00cf09a0(StreamOwner* owner, Record* rec)
{
    WriteData(owner->stream, &rec->unk00, 4);
    WriteData(owner->stream, &rec->unk04, 4);
    WriteData(owner->stream, &rec->unk08, 4);
    WriteData(owner->stream, &rec->unk10, 4);
    WriteData(owner->stream, &rec->unk14, 4);
    WriteData(owner->stream, &rec->unk18, 4);
    WriteData(owner->stream, &rec->unk1C, 4);
    WriteData(owner->stream, &rec->unk20, 4);
    WriteData(owner->stream, &rec->unk24, 4);
    WriteData(owner->stream, &rec->unk28, 4);
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct ArrayData
{
    unsigned int* m_data;
    int m_iElementCount;
};

// @fnv 0x00cf0e90
// pdb: bhkStream::SaveBinary | bhkStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: arStream, arArray
extern "C" unsigned int __cdecl SaveUIntArray(CF4BC0Stream& kStream, const ArrayData& kArray)
{
    unsigned int count = kArray.m_iElementCount;
    CF4BC0SaveBinary(kStream, count);

    unsigned int totalSize = count * sizeof(unsigned int);
    int i = 0;
    if ((int)count > 0)
    {
        do
        {
            unsigned int val = kArray.m_data[i];
            if ((unsigned char)kStream.unk1E4 != 1)
            {
                val = _byteswap_ulong(val);
            }
            CF4BC0SaveBinary(kStream, val);
            ++i;
        } while (i < (int)count);
    }

    return totalSize;
}

extern int DAT_010cc064;
struct FUN_00cdf560
{
    int m0;
    int m4;
    int m8;
    FUN_00cdf560(float);
};
struct FUN_00cf4190 : FUN_00cdf560
{
    FUN_00cf4190();
};
// @fnv 0x00cf4190
// pdb: bhkPositionConstraintMotor::bhkPositionConstraintMotor | bhkPositionConstraintMotor.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
FUN_00cf4190::FUN_00cf4190() : FUN_00cdf560(0.0f)
{
    m0 = (int)&DAT_010cc064;
}

extern int DAT_01268730;

// @fnv 0x00cf41b0
// pdb: bhkCylinderShape::GetRTTI | bhkCylinderShape.obj | fnv360_0822_retail, udata, medium
int* FUN_00cf41b0()
{
    return &DAT_01268730;
}

extern "C" void __cdecl FUN_00d86100(void* view, void* object);

struct BinaryStream
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, sizeof(T), &byteCount, 1);
    }
};
struct StreamView
{
    BinaryStream* stream()
    {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};
struct SerializedRecord
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int m_14, m_18, m_1c, m_20;
    void FUN_00cf41c0(StreamView* view);
};
// Calls FUN_00d86100 with the view and this record, then loads m_14, m_18, m_1c and m_20 from the view's stream.
// @fnv 0x00cf41c0
// pdb: bhkPositionConstraintMotor::LoadBinary | bhkPositionConstraintMotor.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arStream
void SerializedRecord::FUN_00cf41c0(StreamView* view)
{
    FUN_00d86100(view, this);
    view->stream()->Load(&m_14);
    view->stream()->Load(&m_18);
    view->stream()->Load(&m_1c);
    view->stream()->Load(&m_20);
}

struct CpuOpaque;
extern CpuOpaque DAT_01268738;
// @fnv 0x00cf43f0
// pdb: bhkConvexVerticesShape::GetRTTI | bhkConvexVerticesShape.obj | fnv360_0822_retail, objrun_open, low
CpuOpaque* __cdecl FUN_00cf43f0()
{
    return &DAT_01268738;
}

class NiBinaryStreamCF46
{
  public:
    typedef unsigned int (*WriteFn)(NiBinaryStreamCF46* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                    unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline void NiStreamSaveBinaryCF46(NiBinaryStreamCF46& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

struct hkArchiveCF46
{
    int unk000[0x93];
    NiBinaryStreamCF46* m_stream;
};

void __cdecl FUN_00d86100(hkArchiveCF46* ar, void* obj);

class hkObjCF46
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_kPointA;
    int m_kPointB;

    void SaveToArchive(hkArchiveCF46* ar);
};

// @fnv 0x00cf4600
// pdb: bhkSpringDamperConstraintMotor::LoadBinary | bhkSpringDamperConstraintMotor.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arStream
void hkObjCF46::SaveToArchive(hkArchiveCF46* ar)
{
    FUN_00d86100(ar, this);
    NiStreamSaveBinaryCF46(*ar->m_stream, m_kPointA);
    NiStreamSaveBinaryCF46(*ar->m_stream, m_kPointB);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();

unsigned int __cdecl FUN_00d87a40() throw();

struct hkCriticalSectionCF6B
{
    int m_kCriticalSection;
};

struct hkCriticalSectionLockCF6B
{
    hkCriticalSectionCF6B* m_kCriticalSection;
    hkCriticalSectionLockCF6B(hkCriticalSectionCF6B* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6B()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6B
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void MarkForRead();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();

unsigned int __cdecl FUN_00d87a40() throw();

struct hkCriticalSectionCF61
{
    int m_kCriticalSection;
};

struct hkCriticalSectionLockCF61
{
    hkCriticalSectionCF61* m_kCriticalSection;
    hkCriticalSectionLockCF61(hkCriticalSectionCF61* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF61()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF61
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    bool IsCurrentThreadOwner();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();

struct hkCriticalSectionCF6C
{
    int m_kCriticalSection;
};

struct hkCriticalSectionLockCF6C
{
    hkCriticalSectionCF6C* m_kCriticalSection;
    hkCriticalSectionLockCF6C(hkCriticalSectionCF6C* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6C()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6C
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6c60();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();

struct hkCriticalSectionCF6D
{
    int m_kCriticalSection;
};

struct hkCriticalSectionLockCF6D
{
    hkCriticalSectionCF6D* m_kCriticalSection;
    hkCriticalSectionLockCF6D(hkCriticalSectionCF6D* section)
    {
        m_kCriticalSection = section;
        EnterCriticalSection(&section->m_kCriticalSection);
    }
    ~hkCriticalSectionLockCF6D()
    {
        LeaveCriticalSection(&m_kCriticalSection->m_kCriticalSection);
    }
};

struct hkMultiThreadCheckCF6D
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void FUN_00cf6cb0();
};

struct hkMultiThreadCheckCF6E
{
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    bool isCheckingEnabled() const
    {
        return ((m_usMarkedForWrite >> 15) & 1) == 0;
    }

    void ResetThreadCheck();
};

struct CC9F10Shape
{
    void FUN_00c90510();
};

struct FUN_00cf7490_class
{
    void FUN_00cf7490();
};

// @fnv 0x00cf7490
// pdb: bhkNiCollisionObject::SetSceneGraphObject | bhkNiCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: apSceneObject
void FUN_00cf7490_class::FUN_00cf7490()
{
    ((CC9F10Shape*)this)->FUN_00c90510();
}

void __cdecl FUN_00c905b0(void);
// @fnv 0x00cf74a0
void __cdecl FUN_00cf74a0(void)
{
    FUN_00c905b0();
}

struct hkOwnerCF74;

struct hkOwnerCF74
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0;
    unsigned int m_d4;
};

struct hkBoolCF74
{
    char m_cBooleanValue;
    hkBoolCF74()
    {}
    hkBoolCF74(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

// @fnv 0x00cfb050
// pdb: hkNullAgent3::create | hkpCollisionDispatcher.obj | fnv360_0822_retail, objrun_open, low
// pdb params: input, entry, freeMemory
void* __cdecl FUN_00cfb050(void* pvUnused, bool* pbOut, void* pvResult)
{
    *pbOut = false;
    return pvResult;
}

// @fnv 0x00cfb070
// pdb: hkNullAgent3::process | hkpCollisionDispatcher.obj | fnv360_0822_retail, objrun_open, low
// pdb params: input, entry, agentData, separatingNormalOut, result
int __cdecl FUN_00cfb070(int a, int b, int c)
{
    return c;
}

// @fnv 0x00cfc580
void __stdcall FUN_00cfc580(int, int, int, int, int)
{}

extern int DAT_0102e388;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);

void __cdecl FUN_00ce2d10();

// @fnv 0x00ce2f30
// pdb: bhkCollisionObject::SaveBinary | bhkCollisionObject.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: arStream
void __cdecl FUN_00ce2f30()
{
    FUN_00ce2d10();
}

struct NiBinaryStreamCF42
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF42* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiStreamLoadBinaryCF42(NiBinaryStreamCF42& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}

struct NiStreamCF42
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C;
    NiBinaryStreamCF42* m_pUnderlyingStream;

    NiBinaryStreamCF42* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};

class SerializableCF42;
void __cdecl FUN_00d86160(NiStreamCF42& kStream, SerializableCF42* pkObject);

class SerializableCF42
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned int m_uiValue1C;
    unsigned int m_uiValue20;

    void FUN_00cf4260(NiStreamCF42& kStream);
};

// Calls FUN_00d86160 then reads four unsigned int fields from the stream's underlying binary stream.
// @fnv 0x00cf4260
// pdb: bhkPositionConstraintMotor::SaveBinary | bhkPositionConstraintMotor.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: arStream
void SerializableCF42::FUN_00cf4260(NiStreamCF42& kStream)
{
    FUN_00d86160(kStream, this);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue14);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue18);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue1C);
    NiStreamLoadBinaryCF42(*kStream.GetIstr(), m_uiValue20);
}

// bhkVelocityConstraintMotor ctor (hkpVelocityConstraintMotor chain):
// vptr(0), memSizeAndFlags(4), referenceCount(6), motor type(8), min/max force, tau, damping, velocity-clamp bool.
const void* DAT_010cc0ec[];

extern "C" void _ReadWriteBarrier();

struct NiBinaryStreamCF44
{
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCF44* pkThis, void* pvBuffer, unsigned int uiTotalBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiStreamLoadBinaryCF44(NiBinaryStreamCF44& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}

struct NiStreamCF44
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248;
    NiBinaryStreamCF44* m_pUnderlyingStream;

    NiBinaryStreamCF44* GetIstr()
    {
        return m_pUnderlyingStream;
    }
};

class SerializableCF44;
void __cdecl FUN_00d86100(NiStreamCF44& kStream, SerializableCF44* pkObject);

class SerializableCF44
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned int m_uiValue14;
    unsigned int m_uiValue18;
    unsigned char m_ucValue1C;

    void FUN_00cf4400(NiStreamCF44& kStream);
};

// Calls FUN_00d86100, then reads m_uiValue14, m_uiValue18, and m_ucValue1C from the stream via NiStreamLoadBinaryCF44.
// @fnv 0x00cf4400
// pdb: bhkVelocityConstraintMotor::LoadBinary | bhkVelocityConstraintMotor.obj | fnv360_0822_retail, objrun_open, medium
// pdb params: arStream
void SerializableCF44::FUN_00cf4400(NiStreamCF44& kStream)
{
    FUN_00d86100(kStream, this);
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_uiValue14);
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_uiValue18);
    NiStreamLoadBinaryCF44(*kStream.GetIstr(), m_ucValue1C);
}

class CF4BC0BinaryStreamIn
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(CF4BC0BinaryStreamIn*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Load(T* value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, value, sizeof(T), &uiSize, 1);
    }
};

struct TagState
{
    int oldTag;
    int newTag;
};
struct AllocScope
{
    int saved;
    AllocScope(TagState t) : saved(t.oldTag)
    {
        g_iCF4BC0AllocTag = t.newTag;
    }
    ~AllocScope()
    {
        g_iCF4BC0AllocTag = saved;
    }
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject()
    {}
};

class hkRefObjCF70 : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpBroadPhaseListener
{
  public:
    virtual ~hkpBroadPhaseListener()
    {}
    virtual void AddCollisionPair(void* pair) = 0;
    virtual void RemoveCollisionPair(void* pair) = 0;
};

class ListenerCF70 : public hkRefObjCF70, public hkpBroadPhaseListener
{
  public:
    virtual void AddCollisionPair(void* pair);
    virtual void RemoveCollisionPair(void* pair);
};

class FUN_00cf7060
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    ListenerCF70 m_kListener;

    ~FUN_00cf7060();
};

// @fnv 0x00cf7060
// pdb: hkpTypedBroadPhaseDispatcher::~hkpTypedBroadPhaseDispatcher | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, call_dedup, low
FUN_00cf7060::~FUN_00cf7060()
{}

#include <xmmintrin.h>
extern const __m128 g_vectorConstantQuaternionIdentity;

struct __declspec(align(16)) CE5430Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void SetAllComponents(float f)
    {
        m_vComponents = _mm_set_ps1(f);
    }
};

struct __declspec(align(16)) CE5430Quaternion
{
    __m128 m_vec;

    void setIdentity()
    {
        m_vec = g_vectorConstantQuaternionIdentity;
    }
};

struct __declspec(align(16)) CE5430QsTransform
{
    CE5430Vector4 m_vTranslation;
    CE5430Quaternion m_rotation;
    CE5430Vector4 m_vScale;

    void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.SetAllComponents(1.0f);
    }
};

struct __declspec(align(16)) CE5430Pose
{
    short m_sIndex0;
    short m_sIndex1;
    short m_sIndex2;
    short m_sIndex3;
    int unk08;
    int unk0C;
    CE5430QsTransform m_kTransform0;
    CE5430QsTransform m_kTransform1;

    void SetIdentity();
};

struct __declspec(align(16)) hkVector4CE98
{
    __m128 m_vComponents;

    void operator=(const hkVector4CE98& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

extern __declspec(align(16)) float DAT_01017d10[4];

struct BinaryStreamCF0
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(BinaryStreamCF0*, void*, unsigned int, unsigned int*, unsigned int);

    template <typename T> void Load(T* dest, unsigned int uiBytes)
    {
        unsigned int byteCount = sizeof(T);
        absolutePosition += read(this, dest, uiBytes, &byteCount, 1);
    }
};

struct StreamViewCF0
{
    BinaryStreamCF0* stream()
    {
        return *reinterpret_cast<BinaryStreamCF0**>(reinterpret_cast<char*>(this) + 0x24c);
    }
};

struct hkVector4CF0
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct TargetType
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 unk10;
    void* unk20;
    unsigned int unk24;
};

// Writes obj->unk24, obj->unk10 and the buffer at obj->unk20 to the stream, returning the buffer size.
// @f3 0x00979830 (community match, verified in this file)
// pdb: bhkStream::SaveBinary | bhkStream.obj | fnv360_0822_retail, call_seq, medium
// pdb params: arStream, apMoppCode
unsigned int FUN_00cf0dc0(CF4BC0Stream& stream, TargetType* obj)
{
    unsigned int size = 0;
    if (obj)
    {
        size = obj->unk24;
        CF4BC0BinaryStreamSave(*stream.m_pBackingStream, &size);

        __m128 data;
        data.m128_f32[0] = obj->unk10.m128_f32[0];
        data.m128_f32[1] = obj->unk10.m128_f32[1];
        data.m128_f32[2] = obj->unk10.m128_f32[2];
        data.m128_f32[3] = obj->unk10.m128_f32[3];
        CF4BC0BinaryStreamSave(*stream.m_pBackingStream, &data);

        if (size)
        {
            CF4BC0BinaryStreamSave(*stream.m_pBackingStream, (char*)obj->unk20, size);
        }
    }
    return size;
}


extern void* DAT_010c63bc;
extern void* DAT_010cc4e0;
extern void* DAT_010cc4d0;

struct NodeBaseA
{
    void* m_vtbl;
    unsigned short m_04;
    unsigned short m_06;
    NodeBaseA()
    {
        m_06 = 1;
    }
};

struct NodeBaseB
{
    void* m_vtbl;
    NodeBaseB()
    {
        m_vtbl = &DAT_010c63bc;
    }
};

struct NodeObj : NodeBaseA, NodeBaseB
{
    NodeObj()
    {
        NodeBaseA::m_vtbl = &DAT_010cc4e0;
        NodeBaseB::m_vtbl = &DAT_010cc4d0;
    }
};

struct FUN_00cf6f90
{
    NodeBaseB* m_apSlots[8][8];
    NodeObj m_kDefault;
    FUN_00cf6f90();
};

// Initializes the 8x8 m_apSlots array so that every slot points to the embedded m_kDefault NodeObj instance.
// @fnv 0x00cf6f90
// pdb: hkpTypedBroadPhaseDispatcher::hkpTypedBroadPhaseDispatcher | hkpTypedBroadPhaseDispatcher.obj | fnv360_0822_retail, uvref, high
FUN_00cf6f90::FUN_00cf6f90()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m_apSlots[i][j] = &m_kDefault;
}

struct VecCFAD
{
    union
    {
        __m128 v;
        float f[4];
    };
};
struct InputCFAD
{
    VecCFAD vec;
    int unk10, unk14, unk18, unk1C;
    unsigned char enabled;
};
struct DescCFAD
{
    VecCFAD vec;
    void* data;
    void* extra;
    unsigned int size;
    unsigned int flags;
};
struct ContextCFAD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
};
struct TargetCFAD;
struct SelfCFAD;
struct TargetCFAD
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C(DescCFAD*, SelfCFAD*, int);
};
struct SelfCFAD
{
    void* unk00;
    InputCFAD* input;
    void* extra;
    unsigned int flags;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* context;
    void FUN_00cfad60(TargetCFAD*, InputCFAD*, void*, ContextCFAD*, unsigned int, unsigned int);
};

struct Cfd50Range
{
    int m_00;
    int* m_04;
    int m_08;
};

// @fnv 0x00cfdb50
// pdb: hkAgentNnMachine_getLastEntry | hkpAgentNnMachine.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) int FUN_00cfdb50(Cfd50Range* apRange)
{
    return apRange->m_00 + apRange->m_04[apRange->m_08 - 1] - 0x80;
}

extern "C" Cfd50Range* Cfd50Get(void);
extern "C" int Cfd50Sink(int);

void Cfd50Caller(void)
{
    volatile int r = FUN_00cfdb50(Cfd50Get());
    Cfd50Sink(r);
}

struct CE1700World
{
    void FUN_00c97e80(char* result, void* object);
    void hkpWorld_removeEntityBatch(void* owner, int flags);
};
struct CE1700Node
{
    int unk00;
    int unk04;
    CE1700World* world;
};
struct CE1700Owner
{
    int unk00;
    int unk04;
    CE1700Node** owner;
    int flags;
    int unk10;
    void** objects;
    int count;
    int hkaRagdollInstance_removeFromWorld();
};
// Returns 1 if the owner's node has no world; otherwise calls world->FUN_00c97e80 per object, then world->hkpWorld_removeEntityBatch(owner, flags), and returns 0.
// @fnv 0x00ce1700
// pdb: hkaRagdollInstance::removeFromWorld | hkaRagdollInstance.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
int CE1700Owner::hkaRagdollInstance_removeFromWorld()
{
    CE1700Node* node = *owner;
    CE1700World* world = 0;
    if (node)
        world = node->world;
    if (!world)
        return 1;
    for (int i = 0; i < count; ++i)
    {
        char result;
        world->FUN_00c97e80(&result, objects[i]);
    }
    world->hkpWorld_removeEntityBatch(owner, flags);
    return 0;
}

struct BlockArr_cfd
{
    unsigned* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned operator[](int i) const
    {
        return m_data[i];
    }
    const unsigned& at(int i) const
    {
        return m_data[i];
    }
};

inline AudioAllocator& heap_cfde()
{
    return *FUN_00c85750()->m_pAllocator;
}
extern "C" void __cdecl FUN_00c909d0(AudioAllocator* alloc, void* array, int elemSize, void* storage, int capacity);

struct BlockArr_cfde
{
    char*& back()
    {
        return m_data[m_iElementCount - 1];
    }
    void popBack()
    {
        m_iElementCount--;
    }
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char* m_kStorage[1];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void OptimizeCapacity(int numFreeElemsLeft)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            unsigned c = m_iElementCount + numFreeElemsLeft - 1;
            c |= c >> 16;
            c |= c >> 8;
            c |= c >> 4;
            c |= c >> 2;
            c |= c >> 1;
            int newCap = c + 1;
            if (newCap < 1)
            {
                AudioHolder* h = FUN_00c85750();
                FUN_00c909d0(h->m_pAllocator, this, sizeof(char*), m_kStorage, 1);
            }
            else if (newCap < getCapacity())
            {
                AudioAllocator& a = heap_cfde();
                FUN_00c909d0(&a, this, sizeof(char*), 0, newCap);
            }
        }
    }
};

// Havok: build index maps for a selection and propagate it through records and links (hkArray<hkInt16> maps).
typedef short hkInt16;
typedef unsigned short hkUint16;

struct hkBoolX
{
    char m_cBooleanValue;
    hkBoolX() throw()
    {}
    hkBoolX(bool b) throw()
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator() throw();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(T* p, int numElem) throw()
    {
        ReturnMemory(p, numElem * int(sizeof(T)));
    }
};

struct hkMemoryRouterX
{
    int m_pad00, m_pad04, m_pad08, m_pad0c;
    hkMemoryAllocator* m_pStreamAllocator;
    static hkMemoryRouterX& GetMonitorStream() throw();
    __forceinline hkMemoryAllocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
struct hkArrayUtilX
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& a, void* array, int reqElements, int sizeElem) throw();
    static void __cdecl GrowArray(hkMemoryAllocator& a, void* array, int sizeElem) throw();
    template <typename T> static __forceinline void construct(T* p, int n, const T& t) throw()
    {
        for (int i = 0; i < n; ++i)
            p[i] = t;
    }
};

template <typename T> struct hkArrayX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline hkArrayX() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~hkArrayX() throw()
    {
        _clearAndDeallocate(hkMemoryRouterX::GetMonitorStream().heap());
    }

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtilX::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        const int numToFill = n - m_iElementCount;
        T* dst = m_data + m_iElementCount;
        for (int i = 0; i < numToFill; ++i)
            dst[i] = fill;
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize(hkMemoryRouterX::GetMonitorStream().heap(), n, fill);
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, int t) throw()
    {
        if (m_iElementCount == getCapacity())
            hkArrayUtilX::GrowArray(alloc, this, sizeof(T));
        T value = (T)t;
        hkArrayUtilX::construct(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }
    __forceinline void AddBack(int t) throw()
    {
        _pushBack(hkMemoryRouterX::GetMonitorStream().heap(), t);
    }
};

#include <xmmintrin.h>
namespace fnv_00ce0ca0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
}

}  // namespace fnv_00ce0ca0

#include <xmmintrin.h>
namespace fnv_00cf4fb0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

}  // namespace fnv_00cf4fb0

namespace fnv_00cf6d60 {
#include <windows.h>

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

extern CRITICAL_SECTION* DAT_01268794;
}  // namespace fnv_00cf6d60

extern const char DAT_010cba14, DAT_010cb9f8, DAT_010cb9d8, DAT_010cb9c4;
extern const char DAT_010cb9b0, DAT_010cb98c, DAT_010cb964, DAT_010cb8d0;

// @f3 0x00684240 (community match, verified in this file)
namespace f3m_00684240 {
namespace StatsControls {

class Tile {
public:
    void __thiscall Tile_AddFadeControl(unsigned int channel, float from, float to, float seconds, bool reverse);
    void __thiscall FUN_00bed770(int trait);
    void __thiscall FUN_00bee190(int trait, float value, bool notify);
};

// pdb: StatsMenu::FadeControlCallback | StatsMenu.obj | fnv360_0721_retail, caller_sim, medium
// pdb params: apTile, aiOn
bool __cdecl FUN_00684240(Tile* tile, unsigned int gamepad)
{
    const int alpha = 0xFA9;
    if (gamepad) {
        tile->Tile_AddFadeControl(alpha, 255.0f, 0.0f, 1.0f, true);
    } else {
        tile->FUN_00bed770(alpha);
        tile->FUN_00bee190(alpha, 255.0f, true);
    }
    return true;
}

}
}   // namespace f3m_00684240
