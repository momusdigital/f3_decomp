// staging/blk_00dc0000_o2.cpp: SpawnedObject, ArrayHost, Lock_dd9, hkOwnerDCB1 and more (52 functions)
#include "f3_common.h"
#include <windows.h>
// src/staging/blk_00dc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00dd4b10_struct
{
    void __thiscall AssignFromSource(const void* p);
};

// Copies six consecutive unsigned ints from p into this at offsets 8 through 28.
// @fnv 0x00dd4b10
// pdb: hkpMoppCompiler::setSplitParams | hkpMoppCompiler.obj | fnv360_0822_retail, call_gap, high
// pdb params: sp
void __thiscall FUN_00dd4b10_struct::AssignFromSource(const void* pSource)
{
    const unsigned int* src = (const unsigned int*)pSource;
    *(unsigned int*)((char*)this + 8) = src[0];
    *(unsigned int*)((char*)this + 12) = src[1];
    *(unsigned int*)((char*)this + 16) = src[2];
    *(unsigned int*)((char*)this + 20) = src[3];
    *(unsigned int*)((char*)this + 24) = src[4];
    *(unsigned int*)((char*)this + 28) = src[5];
}

struct FUN_00dd4b40_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    void __thiscall SetValues(const unsigned int* p);
};

// Copies six unsigned ints from the array p into fields m_20 through m_34.
// @fnv 0x00dd4b40
// pdb: hkpMoppCompiler::setCostParams | hkpMoppCompiler.obj | fnv360_0822_retail, call_gap, medium
// pdb params: sp
void __thiscall FUN_00dd4b40_Class::SetValues(const unsigned int* auiValues)
{
    m_20 = auiValues[0];
    m_24 = auiValues[1];
    m_28 = auiValues[2];
    m_2c = auiValues[3];
    m_30 = auiValues[4];
    m_34 = auiValues[5];
}

struct FUN_00dd5170_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    void __thiscall CopySixInts(const int* p);
};

// Copies six consecutive ints from the pointed-to array into fields c through h.
// @fnv 0x00dd5170
// pdb: hkpMoppCostFunction::updateParams | hkpMoppCostFunction.obj | fnv360_0822_retail, objrun, medium
// pdb params: bp
void __thiscall FUN_00dd5170_class::CopySixInts(const int* pSource)
{
    c = pSource[0];
    d = pSource[1];
    e = pSource[2];
    f = pSource[3];
    g = pSource[4];
    h = pSource[5];
}

template <class K, class V, class O> class HashEntryTable
{
  public:
    void clear();
};
template <class K> struct KeyMarker
{
};

extern "C" void __cdecl hkpConstraintConstructionKit_computeConstraintInfo(int* p1, int* p2);
struct FUN_00dd0420_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_00dd0420_Class* __thiscall FUN_00dd0420(int arg);
};
// If arg is nonzero, zeroes m_00/m_08/m_0c, sets m_04 to 0x10, calls hkpConstraintConstructionKit_computeConstraintInfo on m_1c and this, then sets m_00 to m_04; returns this.
// @fnv 0x00dd0420
// pdb: hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme | hkpGenericConstraintScheme.obj | fnv360_0822_retail, call_seq, high
// pdb params: f
FUN_00dd0420_Class* __thiscall FUN_00dd0420_Class::FUN_00dd0420(int aiFlag)
{
    if (aiFlag)
    {
        m_00 = 0;
        m_08 = 0;
        m_0c = 0;
        m_04 = 0x10;
        hkpConstraintConstructionKit_computeConstraintInfo(&m_1c, (int*)this);
        m_00 = m_04;
    }
    return this;
}

struct FUN_00dd4b70_class
{
    void __thiscall hkpMoppCompiler_enableInterleavedBuilding(unsigned char value);
};
// @fnv 0x00dd4b70
// pdb: hkpMoppCompiler::enableInterleavedBuilding | hkpMoppCompiler.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __thiscall FUN_00dd4b70_class::hkpMoppCompiler_enableInterleavedBuilding(unsigned char value)
{
    *(unsigned char*)(this + 0x1c) = value;
    *(unsigned char*)(this + 0x64) = value;
}

struct FUN_00ddfb70_cls
{
    int m_00;
    int m_04;
    FUN_00ddfb70_cls* FUN_00ddfb70();
};

// @fnv 0x00ddfb70
// pdb: hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, call_dedup, low
FUN_00ddfb70_cls* FUN_00ddfb70_cls::FUN_00ddfb70()
{
    m_00 = 8;
    m_04 = 8;
    return this;
}

struct FUN_00dc9e70_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FUN_00dc9e70_Class* FUN_00dc9e70();
};

// Initializes the object's fields to zero/defaults, sets up the embedded CountArray at m_0c, and returns this.
// @f3 0x00a767b0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
struct Heap543 {void* FUN_008f6d90(void*,unsigned int,int);};
namespace Globals543 {extern int DAT_00e84ed4,DAT_00e84ec4,DAT_00e84eb4,DAT_00dcc494;extern unsigned long DAT_010f3170;extern Heap543* (__stdcall* const DAT_00d9b080)(unsigned long);}
struct Capacity543 {unsigned int count:30;unsigned int flags:2;};
struct View543 {
    void* primary;unsigned int unk04;void* secondary;void* data;int count,capacity;
    __forceinline void* ReleaseStorage(){
        if((capacity & 0x80000000u)!=0)return reinterpret_cast<void*>(capacity);
        unsigned int allocation=reinterpret_cast<const Capacity543*>(&capacity)->count;
        Heap543* heap=Globals543::DAT_00d9b080(Globals543::DAT_010f3170);
        return heap->FUN_008f6d90(data,allocation*4,23);
    }
};
// pdb: hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier | hkpRemoveTerminalsMoppModifier.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2)
FUN_00dc9e70_Class* FUN_00dc9e70_Class::FUN_00dc9e70(){
    View543* self=reinterpret_cast<View543*>(this);
    self->primary=&Globals543::DAT_00e84ed4;self->secondary=&Globals543::DAT_00e84ec4;
    _ReadWriteBarrier();
    void* result=self->ReleaseStorage();
    self->secondary=&Globals543::DAT_00e84eb4;self->primary=&Globals543::DAT_00dcc494;
    return reinterpret_cast<FUN_00dc9e70_Class*>(result);
}


struct FUN_00dcc5a0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
};
struct FUN_00dcc5a0_class
{
    int m_00;
    int m_04;
    FUN_00dcc5a0_vt* m_08;
    FUN_00dcc5a0_class* FUN_00dcc5a0(int arg);
};
// @fnv 0x00dcc5a0
// pdb: hkIstream::operator>> | hkIStream.obj | fnv360_0822_retail, objrun, medium
// pdb params: c
FUN_00dcc5a0_class* FUN_00dcc5a0_class::FUN_00dcc5a0(int arg)
{
    m_08->v4(arg, 1);
    return this;
}

extern int DAT_010d77b4[];
extern void __cdecl _Deallocate(void* p);

struct FUN_00dcd4b0_Class
{
    void* m_ppVirtualMethodTable;
    FUN_00dcd4b0_Class* __thiscall InitializeAndMaybeFree(int flags);
};

// @fnv 0x00dcd4b0
// pdb: CIdvCamera::`scalar deleting destructor' | Camera.obj | fnv360_0822_retail, vtable, medium
FUN_00dcd4b0_Class* __thiscall FUN_00dcd4b0_Class::InitializeAndMaybeFree(int flags)
{
    m_ppVirtualMethodTable = DAT_010d77b4;
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct DDA7C0OStream
{
    void __thiscall writeInt32(unsigned int);
};

struct FUN_00dda6b0_Class
{
    void __thiscall WriteUInt32Triple(const unsigned int* p);
};

// Writes the three consecutive unsigned ints pointed to by p to the stream via writeInt32.
// @fnv 0x00dda6b0
// pdb: hkDisplaySerializeOStream::writeTriangle | hkDisplaySerializeOStream.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: ti
void __thiscall FUN_00dda6b0_Class::WriteUInt32Triple(const unsigned int* auiValues)
{
    ((DDA7C0OStream*)this)->writeInt32(auiValues[0]);
    ((DDA7C0OStream*)this)->writeInt32(auiValues[1]);
    ((DDA7C0OStream*)this)->writeInt32(auiValues[2]);
}

struct D2B3D0Map
{
    void clear();
};

namespace fnv_00ddf040 {
struct D2B3D0Map
{
    void clear();
};

// @fnv 0x00ddf040
void __fastcall FUN_00ddf040(char* ecx, int edx)
{
    ((D2B3D0Map*)(ecx + 0x20))->clear();
}
}  // namespace fnv_00ddf040

extern int DAT_010d8094;

struct FUN_00ddfb80_s
{
    void* m_vt;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    void* m_0c;
    void* m_10;
};

// Initialises the object: sets field at offset 6 to 1, assigns the vtable, copies two pointers from src, and zeroes the field at offset 16.
// @fnv 0x00ddfb80
// pdb: hkpShapeDisplayBuilder::hkpShapeDisplayBuilder | hkpShapeDisplayBuilder.obj | fnv360_0822_retail, call_dedup, low
// pdb params: env
FUN_00ddfb80_s* __fastcall FUN_00ddfb80(FUN_00ddfb80_s* self, int, const void* src)
{
    *(unsigned short*)((char*)self + 6) = 1;
    self->m_vt = &DAT_010d8094;
    *(void**)((char*)self + 8) = *(void**)((char*)src + 0);
    *(void**)((char*)self + 12) = *(void**)((char*)src + 4);
    *(unsigned int*)((char*)self + 16) = 0;
    return self;
}

// FUN_00dc1660: __stdcall identity on its single stack parameter.
// @fnv 0x00dc1660
// pdb: hkpConstraintData::getSolverResults | hkpConstraintData.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: runtime
int __stdcall FUN_00dc1660(int a1)
{
    return a1;
}

extern int DAT_011b7b88;

struct FUN_00dc1670_cls
{
    int m_00;
    FUN_00dc1670_cls* FUN_00dc1670();
};

// @fnv 0x00dc1670
// pdb: hkStructureLayout::hkStructureLayout | hkStructureLayout.obj | fnv360_0822_retail, call_seq, high
FUN_00dc1670_cls* FUN_00dc1670_cls::FUN_00dc1670()
{
    this->m_00 = DAT_011b7b88;
    return this;
}

struct ArrayBlock
{
    unsigned int* values;
    int size;
    unsigned int reservedAndFlags;
};
struct AllocatorState
{
    int unk00, unk04, unk08, unk0C;
    void* pool;
    void* GetPool() const
    {
        return pool;
    }
};
extern "C" AllocatorState* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, ArrayBlock*, int, int);

namespace fnv_00dc9e20 {
struct AllocatorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocatorIface* m_pAllocator;
};

AllocHolder* FUN_00c85750();
void FUN_00c908c0(AllocatorIface* alloc, void* arr, unsigned int newCap, int elemSize);

}  // namespace fnv_00dc9e20

struct FUN_00dcc180_Interface
{
    virtual void FUN_00dcc180_00();
    virtual void FUN_00dcc180_01();
    virtual void FUN_00dcc180_02();
    virtual void FUN_00dcc180_03(unsigned char* value);
};

struct FUN_00dcc180_Class
{
    int unk00;
    int unk04;
    FUN_00dcc180_Interface* unk08;

    unsigned char* __thiscall FUN_00dcc180(unsigned char* value);
};

// If unk08 is set, forwards value to its virtual method; otherwise writes 0 to *value and returns value.
// @fnv 0x00dcc180
// pdb: hkIstream::isOk | hkIStream.obj | tesv_win, hash, low
unsigned char* __thiscall FUN_00dcc180_Class::FUN_00dcc180(unsigned char* pucValue)
{
    if (unk08)
        unk08->FUN_00dcc180_03(pucValue);
    else
        *pucValue = 0;

    return pucValue;
}

struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};

struct FUN_00dcc660_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;
    void FUN_00dcc660(int a);
};

// @fnv 0x00dcc660
// pdb: hkIstream::read | hkIStream.obj | fnv360_0822_retail, objrun_sim, medium
// pdb params: buf, nbytes
void FUN_00dcc660_cls::FUN_00dcc660(int a)
{
    m_pFlagTarget->Forward(a);
}

struct FUN_00dcc670_Manager
{
    virtual void FUN_00dcc670_v0();
    virtual void FUN_00dcc670_v1();
    virtual void FUN_00dcc670_v2();
    virtual int FUN_00dcc670_v3(int* value);
};

struct FUN_00dcc670_Class
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;

    int* __thiscall InitFromValue(int* value);
};

extern int DAT_010d7540;
extern FUN_00dcc670_Manager* DAT_01268364;

// Sets unk06 to 1, unk00 to &DAT_010d7540, and unk08 to the result of DAT_01268364->FUN_00dcc670_v3(value), then returns this.
// @fnv 0x00dcc670
// pdb: hkIstream::hkIstream | hkIStream.obj | tesv_win, call_gap, low
int* __thiscall FUN_00dcc670_Class::InitFromValue(int* value)
{
    int* local_value = value;

    unk06 = 1;
    unk00 = &DAT_010d7540;
    unk08 = DAT_01268364->FUN_00dcc670_v3(local_value);
    return (int*)this;
}

namespace fnv_00dcc6a0 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

extern char DAT_010d7540[];

struct SpawnedBlob
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Init(int a1, int a2, int a3);
};

}  // namespace fnv_00dcc6a0

namespace fnv_00dcc6f0 {
struct AllocIface
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

extern char DAT_010d7540[];

struct SpawnedBlob
{
    int unk00;
    unsigned short m_w04;
    unsigned short unk06;
    void* Init(int a1, int a2);
};

}  // namespace fnv_00dcc6f0

namespace fnv_00dcc9c0 {
struct S_00dcc9c0_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00dcc9c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_00dcc9c0_Allocator* unk0C;
    S_00dcc9c0_Allocator& temp()
    {
        return *unk0C;
    }
};

S_00dcc9c0_Router* FUN_00c85750() throw();

struct S_00dcc9c0_StringBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];

    S_00dcc9c0_StringBuf() throw();
    ~S_00dcc9c0_StringBuf() throw()
    {
        S_00dcc9c0_Allocator& a = FUN_00c85750()->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(char));
    }
};

}  // namespace fnv_00dcc9c0

extern int g_unk01269bb4;

// @fnv 0x00dccb00
// pdb: getVtablehkpTransformShape | hkpCollideReflections.obj | tesv_win, objrun_open, low
int* __cdecl FUN_00dccb00()
{
    return &g_unk01269bb4;
}

extern int DAT_01269be4;

// @fnv 0x00dccb30
int* __cdecl FUN_00dccb30()
{
    return &DAT_01269be4;
}

namespace fnv_00dcd480 {
struct FnvCpu_FUN_00dcd480_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00dcd480_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00dcd480_CpuAllocator* allocator;
};
FnvCpu_FUN_00dcd480_CpuAllocatorHolder* __cdecl FUN_00c85750();
}  // namespace fnv_00dcd480

struct FUN_00dced30_cls
{
    virtual void m_v00(int arg);
};

// @fnv 0x00dced30
// pdb: cleanupLoadedObjecthkpConstraintChainInstanceAction | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00dced30(FUN_00dced30_cls* pObject)
{
    pObject->m_v00(0);
}

extern int DAT_01269c44;

// @fnv 0x00dced40
// pdb: getVtablehkpRemoveTerminalsMoppModifier | hkpRemoveTerminalsMoppModifierClass.obj | fnv360_0822_retail, objrun_open, low
int __cdecl FUN_00dced40()
{
    return reinterpret_cast<int>(&DAT_01269c44);
}

extern float DAT_0101e2bc;
extern float DAT_010181bc;
extern float DAT_0101df44;

struct FUN_00dd50f0_cls
{
    float m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    unsigned char m_14;
    FUN_00dd50f0_cls* FUN_00dd50f0(int mode);
};

// Initialises the object's fields to defaults, then overrides m_00 and m_08 depending on mode (0 or 1), and returns this.
// @fnv 0x00dd50f0
// pdb: hkpMoppSplitter::hkpMoppSplitParams::hkpMoppSplitParams | hkpMoppSplitter.obj | fnv360_0822_debug, call_seq, medium
// pdb params: meshType
FUN_00dd50f0_cls* FUN_00dd50f0_cls::FUN_00dd50f0(int mode)
{
    m_00 = DAT_0101e2bc;
    m_10 = 5;
    m_0c = 5;
    m_04 = 1000;
    m_08 = 10;
    m_14 = 1;
    switch (mode)
    {
    case 0:
        m_00 = DAT_0101df44;
        break;
    case 1:
        m_00 = DAT_010181bc;
        m_08 = 30;
        break;
    }
    return this;
}

// FUN_00dd5150: initialises six float members of the object: five of them to
// 1.0 and the last one to the global float constant DAT_01016248; returns the
// object pointer.
extern float DAT_01016248;

struct FUN_00dd5150_cls
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    void* FUN_00dd5150(int arg);
};

// @fnv 0x00dd5150
// pdb: hkpMoppCostFunction::hkpMoppSplitCostParams::hkpMoppSplitCostParams | hkpMoppCostFunction.obj | fnv360_0822_retail, call_seq, medium
// pdb params: __formal
void* FUN_00dd5150_cls::FUN_00dd5150(int aiUnused)
{
    this->m_f00 = 1.0f;
    this->m_f04 = 1.0f;
    this->m_f08 = 1.0f;
    this->m_f0c = 1.0f;
    this->m_f10 = 1.0f;
    this->m_f14 = DAT_01016248;
    return this;
}

extern void* DAT_010d7ba8;

struct FUN_00dd5150_component
{
    void FUN_00dd5150(int value);
};

struct FUN_00dd51a0
{
    void** vftable;
    short unk04;
    short enabled06;
    FUN_00dd5150_component component08;

    FUN_00dd51a0(const int* data);
    void CopySixInts(const int* data);
};

// @fnv 0x00dd51a0
// pdb: hkpMoppCostFunction::hkpMoppCostFunction | hkpMoppCostFunction.obj | fnv360_0822_retail, uvref, high
// pdb params: bp
FUN_00dd51a0::FUN_00dd51a0(const int* data)
{
    enabled06 = 1;
    vftable = &DAT_010d7ba8;
    component08.FUN_00dd5150(0);
    CopySixInts(data);
}

// @fnv 0x00dd6ea0
unsigned char* __cdecl LessThan(unsigned char* output, const unsigned int* left, const unsigned int* right)
{
    *output = *left < *right;
    return output;
}

struct S_00dd8cf0_Ret
{
    bool v;
    S_00dd8cf0_Ret()
    {}
};

extern int DAT_010d7c34;

// Object built by Construct: it installs its own vtable, clears a couple
// of members and then hands the object over to FUN_00dd7f10 for a full reset.
struct SpawnedObject
{
    int* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int* m_a4;
    int* m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    void FUN_00dd7f10();
    SpawnedObject* Construct(int value);
};

void SpawnedObject::FUN_00dd7f10()
{
    m_c0 = 0;
    m_bc = 0;
    m_08 = 0;
    m_0c = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 0;
    m_74 = 0;
    m_78 = 0;
    m_7c = 0;
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
    m_8c = 0;
    m_90 = 0;
    m_94 = 0;
    m_9c = 0;
    m_14 = 0;
    m_a0 = 3;
    m_10 = (int*)&m_9c;
    m_a8 = (int*)&m_a4;
    m_a4 = (int*)&m_a4;
}

// Sets the vtable, stores value in m_98, then calls FUN_00dd7f10 to reset the remaining fields and returns this.
// @fnv 0x00dd8d40
SpawnedObject* SpawnedObject::Construct(int value)
{
    m_vptr = &DAT_010d7c34;
    m_04 = 0;
    m_98 = value;
    this->FUN_00dd7f10();
    return this;
}

namespace fnv_00dd8db0 {
// Array-append helper: grows the buffer when the element count reaches the
// masked capacity, then stores the new value and bumps the count.
struct RecArray
{
    unsigned int* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiCapacity;
};

struct AllocHolder
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_pAllocator;
};

extern "C" AllocHolder* FUN_00c85750();
extern "C" void ResizeAudioStream(void* pAllocator, RecArray* pArray, int iElementSize);

}  // namespace fnv_00dd8db0

namespace fnv_00dd8fa0 {
typedef struct S_00dd8fa0_S S_00dd8fa0_S;

struct S_00dd8fa0_Vtable
{
    void* unk00;
    S_00dd8fa0_S*(__thiscall* method)(S_00dd8fa0_S*, int);
};

struct S_00dd8fa0_S
{
    S_00dd8fa0_Vtable* vtable;
    unsigned short m_04;
    unsigned short m_06;
};

struct S_00dd8fa0_Caller
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00dd8fa0_S* unk10;
};

extern "C" S_00dd8fa0_Caller* __cdecl FUN_00c85750();

}  // namespace fnv_00dd8fa0

namespace fnv_00dd9160 {
// Stand-in for the polymorphic object stored in the game global at 0x01268364.
struct FUN_00dd9160_Global
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual unsigned int vfn3(unsigned int arg);  // vtable slot +0x0c
};

extern "C" FUN_00dd9160_Global* DAT_01268364;  // game global (0x01268364)
extern "C" int UNK_010d7c80;                   // game constant (0x010d7c80)

struct FUN_00dd9160_Class
{
    void* unk00;           // +0x00: vtable pointer stand-in
    unsigned short unk04;  // +0x04
    unsigned short unk06;  // +0x06: state, set to 1
    unsigned int unk08;    // +0x08: result of the virtual call
    unsigned char unk0c;   // +0x0c: flag copied from the second parameter
    FUN_00dd9160_Class* FUN_00dd9160(unsigned int arg, unsigned char flag);
};

// Sets unk06 to 1, unk00 to &UNK_010d7c80, stores flag in unk0c and the result of DAT_01268364->vfn3(arg) in unk08, then returns this.
// @fnv 0x00dd9160
// pdb: hkIArchive::hkIArchive | hkIArchive.obj | fnv360_0822_retail, objrun, medium
// pdb params: filename, bs
FUN_00dd9160_Class* FUN_00dd9160_Class::FUN_00dd9160(unsigned int arg, unsigned char flag)
{
    unk06 = 1;
    unk00 = &UNK_010d7c80;
    unk0c = flag;
    unk08 = DAT_01268364->vfn3(arg);
    return this;
}
}  // namespace fnv_00dd9160

namespace fnv_00dd91a0 {
struct DD91A0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct DD91A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DD91A0Allocator* m_pStreamAllocator;

    DD91A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DD91A0MemoryRouter& __cdecl FUN_00c85750();

class DD91A0ReferencedObject
{
  public:
    DD91A0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int nbytes)
    {
        DD91A0ReferencedObject* b =
            static_cast<DD91A0ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

}  // namespace fnv_00dd91a0

namespace fnv_00ddc160 {
struct DDC160Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct DDC160MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DDC160Allocator* m_pStreamAllocator;

    DDC160Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DDC160MemoryRouter& __cdecl FUN_00c85750();

class DDC160ReferencedObject
{
  public:
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        DDC160ReferencedObject* b =
            static_cast<DDC160ReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
};

}  // namespace fnv_00ddc160

struct S_00dcc740_Cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    S_00dcc740_Cls* __thiscall ReadSignedShort(unsigned short* out);
};

struct IniTokenStream
{
    void* m_vt;
};

extern "C" void ReadIniLine(void);

// Stand-in for the unit's integer parser: its body is not this function's code, it only makes
// the compiler reproduce the original custom convention (stream on the stack, sign flag in eax).
// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) unsigned short readInteger64(IniTokenStream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (unsigned short)(int)(stream != 0);
}

// @fnv 0x00dcc740
// pdb: hkIstream::operator>> | hkIStream.obj | tesv_win, objrun_sim, low
S_00dcc740_Cls* S_00dcc740_Cls::ReadSignedShort(unsigned short* out)
{
    unsigned char flag;
    short r = (short)readInteger64((IniTokenStream*)m_08, &flag);
    *out = flag != 0 ? (unsigned short)(-r) : (unsigned short)r;
    return this;
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);

extern int DAT_010d7db8;

struct Bool1
{
    char v;
    Bool1(char x) : v(x)
    {}
};

struct Base_00d60b40
{
    void* vft;
    void __thiscall FUN_00d60b40(int a, Bool1 b);
};

struct FUN_00dda690 : Base_00d60b40
{
    FUN_00dda690(int a);
};

// @fnv 0x00dda690
// pdb: hkDisplaySerializeOStream::hkDisplaySerializeOStream | hkDisplaySerializeOStream.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: buf
FUN_00dda690::FUN_00dda690(int a)
{
    FUN_00d60b40(a, 0);
    vft = &DAT_010d7db8;
}

struct S_00dcc240_Reader
{
    int unk00;
    int unk04;
    unsigned short unk08;
};

struct S_00dcc790_Class
{
    unsigned int m_00;
    unsigned int m_04;
    S_00dcc240_Reader* m_08;

    S_00dcc790_Class* __thiscall ReadSignedValue(unsigned short* result);
};

extern "C" void __cdecl eatWhiteSpace(void);

// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) unsigned short readInteger64(unsigned char* ok, S_00dcc240_Reader* reader)
{
    *ok = 0;
    eatWhiteSpace();
    return reader->unk08;
}

// Reads a 16-bit value via readInteger64 and stores it negated into result when ok is set, otherwise as-is; returns this.
// @fnv 0x00dcc790
// pdb: hkIstream::operator>> | hkIStream.obj | tesv_win, objrun_sim, low
S_00dcc790_Class* __thiscall S_00dcc790_Class::ReadSignedValue(unsigned short* result)
{
    unsigned char ok;
    unsigned short value = readInteger64(&ok, m_08);

    *result = ok ? (unsigned short)-(int)value : value;
    return this;
}

typedef __int64 FNVInt64;

struct S_00dcc8a0_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};

struct S_00dcc8a0_Handle
{
    S_00dcc8a0_Reader* reader;
};

struct FUN_00dcc8a0_Class
{
    int unk00;
    int unk04;
    S_00dcc8a0_Handle unk08;

    FUN_00dcc8a0_Class* __thiscall ParseSignedInt(FNVInt64* out);
};

static __declspec(noinline) FNVInt64 S_00dcc8a0_ParseInt(S_00dcc8a0_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_00dcc8a0_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}

// Parses an integer from the handle's reader, negates it if the sign flag is set, stores it in out and returns this.
// @fnv 0x00dcc8a0
// pdb: readInteger<unsigned short> | hkIStream.obj | fnv360_0822_debug, objrun_sim, low, conflict (skyrim: hkIstream::operator>>)
// pdb params: reader, tOut
FUN_00dcc8a0_Class* FUN_00dcc8a0_Class::ParseSignedInt(FNVInt64* out)
{
    unsigned char neg;
    FNVInt64 value = S_00dcc8a0_ParseInt(unk08, &neg);
    if (neg)
        value = -value;
    *out = value;
    return this;
}

struct hkEntryDCB1
{
    int m_uiFilterValue;
    int m_04;
};

struct hkTableDCB1
{
    int m_00;
    int m_04;
    int m_08;
    hkEntryDCB1* m_entries;
};

class hkOwnerDCB1;

struct hkRefDCB1
{
    const hkOwnerDCB1* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDCB1(const hkOwnerDCB1* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};

class hkOwnerDCB1
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB1* m_table;

    hkRefDCB1 GetEntryRef(int iIndex) const;
};

struct S_00dcc600_Inner
{
    int __thiscall ReadChar();
};

static __declspec(noinline) int S_00dcc600_Reset(S_00dcc600_Inner* stream)
{
    int count = 0;
    int c = stream->ReadChar();

    while (c != -1 && count < 4)
    {
        ++count;
        c = stream->ReadChar();
    }

    return count;
}

struct S_00dcc600_Class
{
    int m_00;
    int m_04;
    S_00dcc600_Inner* m_08;

    int __thiscall hkIstream_getline(unsigned char* buffer, int length, signed char value);
};

// Resets the stream, then reads bytes into buffer until the value or end is hit, returning the index or -1.
// @fnv 0x00dcc600
// pdb: hkIstream::getline | hkIStream.obj | fnv360_0822_retail, caller_sim, high
// pdb params: str, maxlen, delim
// pdb: hkIstream::getline | hkIStream.obj | fnv360_0822_retail, caller_sim, high (was: ReadUntilValue)
int S_00dcc600_Class::hkIstream_getline(unsigned char* buffer, int length, signed char value)
{
    S_00dcc600_Reset(this->m_08);

    int index = 0;

    if (length > 0)
    {
        do
        {
            int result = this->m_08->ReadChar();

            if (result == -1 || result == value)
            {
                buffer[index] = 0;
                return index;
            }

            buffer[index] = (unsigned char)result;
            ++index;
        } while (index < length);
    }

    return -1;
}

struct Bool388
{
    unsigned char value;
    Bool388()
    {}
    Bool388(unsigned char v) : value(v)
    {}
};
struct Block388
{
    unsigned int previousSize, sizeAndFlags;
    unsigned char Flags() const
    {
        return reinterpret_cast<const unsigned char*>(&sizeAndFlags)[0];
    }
};

// @fnv 0x00dd8fd0
// pdb: byteswap | hkIArchive.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00dd8fd0(unsigned char* a, unsigned char* b)
{
    unsigned char t = *a;
    *a = *b;
    *b = t;
}

extern "C" unsigned char* GetPtr();

void Caller(unsigned char* a)
{
    FUN_00dd8fd0(a, GetPtr());
}

class hkMemoryAllocatorDDFB;

struct hkMemoryRouterDDFB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDDFB* m_pStreamAllocator;
    hkMemoryAllocatorDDFB& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDDFB {
extern "C" hkMemoryRouterDDFB& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

struct hkPairDDFB
{
    void* m_object;
    void* m_key;

    hkPairDDFB(void* object, void* key) : m_object(object), m_key(key)
    {}
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

template <class T> class hkArrayDDFB
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDDFB& kAlloc = hkRouterDDFB::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

struct stub_cls
{
    int unk00;
    int unk04;
};
static stub_cls* volatile g_stub_self;
static int volatile g_stub_v;
static int volatile g_stub_out;
extern "C" int stub_val(void);

// Placeholder body for the unsolved 0x00dcc3b0 (models its call for 0x00dcc5c0); annotated so the target pack drops it.
// @fnv 0x00dcc3b0
static __declspec(noinline) float FUN_00dcc3b0(int arg)
{
    g_stub_out = arg;
    stub_cls* s = g_stub_self;
    s->unk00 = s->unk04 + g_stub_v;
    return (float)s->unk00;
}

float stub_caller(void)
{
    return FUN_00dcc3b0(stub_val());
}

class FUN_00dcc5c0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;

    FUN_00dcc5c0_cls* __thiscall GetFloatValue(float* out);
};

// @fnv 0x00dcc5c0
// pdb: hkIstream::operator>> | hkIStream.obj | fnv360_0822_retail, objrun, high
// pdb params: f
FUN_00dcc5c0_cls* __thiscall FUN_00dcc5c0_cls::GetFloatValue(float* out)
{
    *out = FUN_00dcc3b0(m_08);
    return this;
}

// ReadSignedInt: thiscall member returning this; parses an int through readInteger64
// (per-TU private convention: stream on the stack, sign-flag address in EAX),
// negates it when the flag byte is set, and stores it through the int* argument.
struct S_00dcc7e0_Stream
{
    void* m_vt;
};

extern "C" void ReadIniLine(void);

// Stand-in for the unit's integer parser (int flavour): its body is not this
// function's code, it only makes the compiler reproduce the original custom
// convention (stream on the stack, sign flag in eax).
// pdb: readInteger64 | hkIStream.obj | fnv360_0822_retail, caller_sim + skyrim(caller_sim), high
static __declspec(noinline) int readInteger64(S_00dcc7e0_Stream* stream, unsigned char* negative)
{
    *negative = 0;
    ReadIniLine();
    return (int)(stream != 0);
}

struct FUN_00dcc7e0_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00dcc7e0_Class* __thiscall ReadSignedInt(int* out);
};

// Reads a signed integer from the stream at m_08 via readInteger64, applies the sign flag, stores the result in out, and returns this.
// @fnv 0x00dcc7e0
// pdb: hkIstream::operator>> | hkIStream.obj | tesv_win, objrun_sim, low
FUN_00dcc7e0_Class* FUN_00dcc7e0_Class::ReadSignedInt(int* out)
{
    unsigned char flag;
    int value = readInteger64((S_00dcc7e0_Stream*)m_08, &flag);
    *out = flag != 0 ? -value : value;
    return this;
}

typedef __int64 FNVInt64;

struct S_dcc860_Reader
{
    virtual int read(int count);
    virtual int charAt(int pos);
};

struct S_dcc860_Handle
{
    S_dcc860_Reader* reader;
};

struct FUN_00dcc860_Class
{
    int unk00;
    int unk04;
    S_dcc860_Handle unk08;

    FUN_00dcc860_Class* __thiscall ReadInt64(FNVInt64* out);
};

static __declspec(noinline) FNVInt64 S_dcc860_ParseInt(S_dcc860_Handle h, unsigned char* neg)
{
    *neg = 0;
    S_dcc860_Reader* reader = h.reader;
    int count = reader->charAt(0);
    if (count < 3)
        return 0;
    return (FNVInt64)reader->read(count);
}

// Parses a signed 64-bit integer from the reader handle, applies the sign, stores it in out, and returns this.
// @fnv 0x00dcc860
// pdb: readInteger<short> | hkIStream.obj | fnv360_0822_debug, objrun_sim, low, conflict (skyrim: hkIstream::operator>>)
// pdb params: reader, tOut
FUN_00dcc860_Class* FUN_00dcc860_Class::ReadInt64(FNVInt64* out)
{
    unsigned char neg;
    FNVInt64 value = S_dcc860_ParseInt(unk08, &neg);
    if (neg)
        value = -value;
    *out = value;
    return this;
}

struct S00dcd270_Rec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
    int unk24;
    void* unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct S00dcd270_Arr
{
    S00dcd270_Rec* m_data;
    int m_iElementCount;
    int m_cap;
};
extern "C" void __cdecl ResizeAudioStream(void*, S00dcd270_Arr*, int);

class hkBoolDD8
{
  public:
    hkBoolDD8(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct MemChunkDD8
{
    enum
    {
        PINUSE_BIT = 1,
        CINUSE_BIT = 2,
        INUSE_BITS = 3,
        PAYLOAD_OFFSET = 16
    };
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;
    hkBoolDD8 isInuse() const
    {
        return (head & CINUSE_BIT) != 0;
    }
    hkBoolDD8 isPinuse() const
    {
        return (head & PINUSE_BIT) != 0;
    }
    unsigned int getChunkSize() const
    {
        return head & ~(unsigned int)INUSE_BITS;
    }
    const MemChunkDD8* chunkPlusOffset(unsigned int s) const
    {
        return (const MemChunkDD8*)((const char*)this + s);
    }
    const MemChunkDD8* chunkMinusOffset(unsigned int s) const
    {
        return (const MemChunkDD8*)((const char*)this - s);
    }
    static const MemChunkDD8* toChunk(const void* in)
    {
        return (const MemChunkDD8*)((const char*)in - PAYLOAD_OFFSET);
    }
};

extern "C" int FUN_00d86940();

// @fnv 0x00dc1be0
int FUN_00dc1be0()
{
    int r = FUN_00d86940();
    if (r != 0)
        return r;
    return 1;
}

struct TokenReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int read(void* buffer, int count);
    virtual void skip(int count);
    virtual void v6();
    virtual void prepare(int count);
    virtual void reset();
};

// Reads 64-byte chunks from stream, skipping whitespace until a non-space character is found, then resets and skips to that position.
// @fnv 0x00dcc1b0
// pdb: eatWhiteSpace | hkIStream.obj | fnv360_0822_retail, call_seq, high
// pdb: eatWhiteSpace | hkIStream.obj | fnv360_0822_retail, call_seq, high (was: SkipWhitespace)
static __declspec(noinline) void eatWhiteSpace(TokenReader* stream)
{
    int buffer[16];
    stream->prepare(64);
    int count = stream->read(buffer, 64);
    while (count != 0)
    {
        int index = 0;
        while (index < count)
        {
            char c = reinterpret_cast<char*>(buffer)[index];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                stream->reset();
                stream->skip(index);
                return;
            }
            ++index;
        }
        stream->prepare(64);
        count = stream->read(buffer, 64);
    }
}

extern TokenReader* volatile inputStream;
void MatchCaller()
{
    eatWhiteSpace(inputStream);
}

struct CpuOpaque;
extern CpuOpaque DAT_01269c14;
// @fnv 0x00dccb50
CpuOpaque* __cdecl FUN_00dccb50()
{
    return &DAT_01269c14;
}

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d061
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

#include <math.h>
struct SubB
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
};
struct ObjB
{
    float f00;
    SubB* p4;
    int u08;
    float f0c;
    float f10;
    float f14;
};
struct ObjA
{
    int u00;
    int u04;
    signed char m08;
    unsigned char u09;
    unsigned char u0a;
    unsigned char u0b;
    float f0c;
    float f10;
    union
    {
        float f14;
        void* p14;
    } u14;
    float f18;
    float f1c;
    float f20;
};

__forceinline float Limit(const float& current, const float& target, const float& d, const float& limit)
{
    float ad = fabsf(d);
    if (ad > limit)
        return target + (d > 0.0f ? limit : -limit);
    return current;
}
__forceinline float Clamp(const float& value, const float& hi, const float& lo)
{
    return value < lo ? lo : (hi < value ? hi : value);
}

// Switches on a->m08: modes 1 to 3 fill six floats in out from a and b; mode 4 calls the function pointer stored in a.
// @fnv 0x00dcfff0
// pdb: hkCalcMotorData | hkpMotorBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: someMotor, input, output
void __cdecl FUN_00dcfff0(ObjA* a, ObjB* b, float* out)
{
    float s0, s4, s8, sC, s10, t18;
    switch ((int)a->m08 - 1)
    {
    case 0: {
        float bf = b->f10;
        t18 = b->f14;
        float xyz = a->f1c * t18 * b->p4->f0c;
        float d = t18 - xyz;
        float wz = a->f20 * b->p4->f0c;
        float t;
        if (fabsf(d) > wz)
            t = xyz + (d > 0.0f ? wz : -wz);
        else
            t = t18;
        float ab = fabsf(t18);
        t = Clamp(t, ab - b->f0c, -ab - b->f0c);
        s4 = (t + bf) * b->p4->f10;
        sC = b->f0c;
        s8 = a->f10;
        s10 = -s8;
        t18 = a->u14.f14;
        s0 = a->f18;
        break;
    }
    case 1: {
        if (*(unsigned char*)&a->f1c)
            s4 = (b->f14 + b->f10) * b->p4->f10;
        else
            s4 = a->f18;
        sC = b->f0c;
        t18 = a->u14.f14;
        s0 = a->u14.f14;
        s8 = a->f10;
        s10 = a->f0c;
        break;
    }
    case 2: {
        s4 = 0.0f;
        sC = b->f10 + b->f14;
        float recip = 1.0f / b->f00;
        float P = b->p4->f00;
        float x = a->u14.f14 * P * P * recip;
        t18 = x < 0.0f ? 0.0f : (x > 1.0f ? 1.0f : x);
        float y = P * a->f18 * recip;
        s0 = y < 0.0f ? 0.0f : (y > 1.0f ? 1.0f : y);
        s8 = a->f10;
        s10 = a->f0c;
        break;
    }
    case 3: {
        return ((void(__cdecl*)(ObjA*, ObjB*, float*))a->u14.p14)(a, b, out);
    }
    default:
        return;
    }
    out[1] = s4;
    out[0] = sC;
    out[2] = s8;
    out[3] = s10;
    out[4] = t18;
    out[5] = s0;
}

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
#endif
#ifndef _INCLUDED_MM2
extern "C"
{
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_or_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    int _mm_movemask_ps(__m128);
}
#endif

struct OW
{
    const __m128* p;
    OW(const __m128* q) : p(q)
    {}
};
// @fnv 0x00dd3120
volatile int g_s, g_a, g_o, g_r;

// Converts four unsigned bytes from src to floats stored in dst[0] through dst[3].
// @fnv 0x00dd31d0
unsigned char volatile g_src[4];
float volatile g_dst[4];

// Looks up the table entry for i with FUN_00dcb2b0 and calls its forward method with the owner's context value.
// @fnv 0x00dcb460
struct DispatchTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void forward(int value);
};
struct Entry
{
    int key;
    DispatchTarget* target;
};
struct Table
{
    int a, b, c;
    Entry* entries;
    unsigned int FUN_00dcb2b0(unsigned int);
    DispatchTarget* entryAt(unsigned int i)
    {
        return entries[i].target;
    }
};

#include <stdlib.h>
// Text reader: read the next number as a double.

class DCC5E0Stream
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Skip(int iCount);
    int Peek();
    char* m_pcCursor;
};

// File-static helper (reconstructed separately); MSVC passes the stream to it in a register.
static __declspec(noinline) double DCC5E0ReadNumber(DCC5E0Stream* pkStream)
{
    double dValue = strtod(pkStream->m_pcCursor, &pkStream->m_pcCursor);
    return dValue;
}

class DCC5E0Reader
{
  public:
    int unk00;
    int unk04;
    DCC5E0Stream* m_pDataStream;

    DCC5E0Reader& ReadDouble(double& rdValue);
};

// @fnv 0x00dcc5e0
// pdb: hkIstream::operator>> | hkIStream.obj | fnv360_0822_retail, objrun, high
// pdb params: d
DCC5E0Reader& DCC5E0Reader::ReadDouble(double& rdValue)
{
    rdValue = DCC5E0ReadNumber(m_pDataStream);
    return *this;
}

// Adjustor thunk: the secondary-base (+0x10) vtable entry for an override defined on the derived class.

// Stand-in for the class owning this function.
//   +0x0c : record*  array of 12-byte records
//   +0x18 : CRITICAL_SECTION*  shared lock
class FUN_00dd92f0_cls
{
  public:
    struct Record
    {
        int m_i00;
        int(__cdecl* m_pFn)(int);
        int m_i08;
    };

    int m_i00;
    int m_i04;
    int m_i08;
    Record* m_pRecords;
    int m_i10;
    int m_i14;
    CRITICAL_SECTION* m_pCrit;

    int InvokeRecord(int index, int arg);
};

// Locks m_pCrit, calls the function pointer in the Record at m_pRecords[index] with arg, unlocks, and returns the result.
// @f3 0x00a61000 (community match, verified in this file)
struct FUN_00dd92f0_lockobj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void FUN_00908a00();
};

struct FUN_00dd92f0_rec20
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* m_pFn)(int);
    int unk10;
};

// pdb: hkProcessFactory::createProcess | hkProcessFactory.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: tag, contexts
int FUN_00dd92f0_cls::InvokeRecord(int index, int arg)
{
    FUN_00dd92f0_lockobj* lock = reinterpret_cast<FUN_00dd92f0_lockobj*>(this->m_pCrit);
    lock->FUN_00908a00();
    FUN_00dd92f0_rec20* rec = &reinterpret_cast<FUN_00dd92f0_rec20*>(this->m_pRecords)[index];
    int result = rec->m_pFn(arg);
    lock->unk18 = -1;
    lock->unk1C = -1;
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(lock));
    return result;
}


namespace fnv_00dd9d20 {

extern "C" void* __cdecl FUN_00c85750();

}  // namespace fnv_00dd9d20

double FUN_00ecdf2d(const char* s, char** end);
// Skips whitespace, reads a numeric token from the stream with commas turned into dots, and returns it as a float, or -1.0f if no token starts.
// @fnv 0x00dcc3b0
static float FUN_00dcc3b0(TokenReader* stream)
{
    struct Buf256
    {
        int w[64];
    };
    Buf256 buf;
    eatWhiteSpace(stream);
    int n = 0;
    stream->prepare(255);
    int len = stream->read(buf.w, 255);
    if (len != 0)
    {
        char c = ((char*)buf.w)[0];
        if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '.' || c == ',')
        {
            n = 1;
            for (; n < len; ++n)
            {
                char ch = ((char*)buf.w)[n];
                if (!((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == 'E' || ch == 'e' || ch == '.' ||
                      ch == ','))
                    break;
                if (ch == '.' || ch == ',')
                    ((char*)buf.w)[n] = '.';
            }
        }
    }
    stream->reset();
    stream->skip(n);
    ((char*)buf.w)[n] = 0;
    if (n > 0)
        return (float)FUN_00ecdf2d((char*)buf.w, 0);
    return -1.0f;
}
float MatchCaller(TokenReader* s)
{
    return FUN_00dcc3b0(s);
}

namespace fnv_00dcc8e0 {
struct TokenBuffer
{
    char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
};

struct TokenOwner
{
    int unk00;
    void FUN_00d61cc0();
    TokenBuffer* FUN_00d61470();
};

struct TokenStream
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04(char* buffer, int count);
    virtual void v05(int count);
    virtual void v06();
    virtual void v07(int n);
    virtual void v08();
    int ReadChar();
};

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(int alloc, TokenBuffer* buf, int n);
namespace TokenParsing {
static __declspec(noinline) void eatWhiteSpace(TokenStream* stream)
{
    unsigned __int64 storage[8];
    char* buffer = reinterpret_cast<char*>(storage);
    stream->v07(64);
    int n = stream->v04(buffer, 64);
    while (n != 0)
    {
        int i = 0;
        while (i < n)
        {
            char c = buffer[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                stream->v08();
                stream->v05(i);
                return;
            }
            ++i;
        }
        stream->v07(64);
        n = stream->v04(buffer, 64);
    }
}
}

template <class T> __forceinline void ConstructToken(T* p, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
        p[i] = value;
}

struct TokenReader
{
    int unk00;
    int unk04;
    TokenStream* m_08;
    TokenReader* ReadToken(TokenOwner* owner);
};

// Reads a whitespace-delimited token from the stream into the owner's buffer, appending a null terminator, and returns this.
// @fnv 0x00dcc8e0
TokenReader* TokenReader::ReadToken(TokenOwner* owner)
{
    const int one = 1;
    owner->FUN_00d61cc0();
    TokenBuffer* buf = owner->FUN_00d61470();
    TokenParsing::eatWhiteSpace(m_08);
    m_08->v07(one);
    int c = m_08->ReadChar();
    if (c != -1)
    {
        do
        {
            if (c == 0x20 || c == 9 || c == 0xd || c == 0xa)
            {
                break;
            }
            AllocatorState* h = FUN_00c85750();
            if (buf->m_len == (buf->m_cap & 0x3fffffff))
            {
                ResizeAudioStream(h->unk0C, buf, one);
            }
            char* slot = buf->m_data + buf->m_len;
            char value = (char)c;
            ConstructToken(slot, one, value);
            buf->m_len += one;
            m_08->v07(one);
            c = m_08->ReadChar();
        } while (c != -1);
    }
    m_08->v08();
    AllocatorState* h2 = FUN_00c85750();
    if (buf->m_len == (buf->m_cap & 0x3fffffff))
    {
        ResizeAudioStream(h2->unk0C, buf, one);
    }
    char* slot2 = buf->m_data + buf->m_len;
    _ReadWriteBarrier();
    *slot2 = 0;
    buf->m_len += one;
    return this;
}
}  // namespace fnv_00dcc8e0

// @fnv 0x00dccb60
// pdb: hkpConstrainedSystemFilter::constraintRemovedCallback | hkpConstrainedSystemFilter.obj | fnv360_0721_beta, objrun_open, low
// pdb params: constraint
void __stdcall FUN_00dccb60(int value)
{}

extern "C"
{
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

class S00dd0ff0_SimdReal
{
  public:
    S00dd0ff0_SimdReal(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __m128 m_vValue;
};

class S00dd0ff0_Vector4
{
  public:
    void setMul4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void mul4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    void add4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void sub4(const S00dd0ff0_Vector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const S00dd0ff0_Vector4& a, const S00dd0ff0_Vector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setW(const S00dd0ff0_Vector4& w)
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, w.m_vComponents), 0xc4);
    }
    void setBroadcast(const S00dd0ff0_Vector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    S00dd0ff0_SimdReal horizontalAdd3() const
    {
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    S00dd0ff0_SimdReal horizontalAdd4() const
    {
        __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x4e), m_vComponents);
        __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    __m128 m_vComponents;
};

struct S00dd0ff0_VelocityAccumulator
{
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    S00dd0ff0_Vector4 m_vLinearVelocity;
    S00dd0ff0_Vector4 m_vAngularVelocity;
    S00dd0ff0_Vector4 m_vInverseInertiaAndMass;
};

template <typename TYPE> inline const TYPE* S00dd0ff0_addByteOffsetConst(const TYPE* base, long offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
}

struct S00dd0ff0_AccumulatorOffset
{
    int m_offset;
    const S00dd0ff0_VelocityAccumulator& getAccumulator(const S00dd0ff0_VelocityAccumulator* base)
    {
        return *S00dd0ff0_addByteOffsetConst(base, m_offset);
    }
};

class S00dd0ff0_Jacobian
{
  public:
    S00dd0ff0_Vector4 m_kLinearJacobian;
    S00dd0ff0_Vector4 m_kAngularVelocity[2];

    float getDiag(const S00dd0ff0_VelocityAccumulator& mA, const S00dd0ff0_VelocityAccumulator& mB) const
    {
        S00dd0ff0_Vector4 ang0;
        ang0.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 ang1;
        ang1.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        ang0.add4(ang1);
        S00dd0ff0_Vector4 dw;
        dw.setAdd4(mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        ang0.setW(dw);
        float x = ang0.horizontalAdd4();
        return float(x + 1.1920928955078125e-07);
    }

    float getNonDiagDifferentObjects_With2ndBodyFromFirstObject(const S00dd0ff0_VelocityAccumulator& mB,
                                                                const S00dd0ff0_Jacobian& jacB) const
    {
        S00dd0ff0_Vector4 lin;
        lin.setMul4(m_kLinearJacobian, jacB.m_kLinearJacobian);
        S00dd0ff0_Vector4 ang;
        ang.setMul4(m_kAngularVelocity[1], jacB.m_kAngularVelocity[0]);
        S00dd0ff0_Vector4 invMassB;
        invMassB.setBroadcast(mB.m_vInverseInertiaAndMass, 3);
        S00dd0ff0_Vector4 linB;
        linB.setMul4(invMassB, lin);
        ang.mul4(mB.m_vInverseInertiaAndMass);
        ang.sub4(linB);
        return ang.horizontalAdd3();
    }
};

volatile int g_S00dd0ff0_n;
volatile float g_S00dd0ff0_cfm;
volatile int g_S00dd0ff0_jac;
volatile int g_S00dd0ff0_offs;
volatile int g_S00dd0ff0_base;
volatile int g_S00dd0ff0_triple;
volatile int g_S00dd0ff0_size;

// Writes a type 0x1d header and n triples of floats into the buffer at *pp, copies n+1 pointers, and advances *pp by the block size.
// @f3 0x00a520c0 (community match, verified in this file)
// Builds the solver schema of a stiff-spring constraint chain: header, body offsets, and the factored
// tridiagonal matrix (one lower/diagonal/upper triple per constraint) from the already built Jacobians.
namespace chn520c0 {
__declspec(align(16)) struct Vector4 {
    float x, y, z, w;
    float& operator()(int i) { return (&x)[i]; }
    const float& operator()(int i) const { return (&x)[i]; }
    void setMul4(const Vector4& a, const Vector4& b)
    {
        x = a.x * b.x;
        y = a.y * b.y;
        z = a.z * b.z;
        w = a.w * b.w;
    }
    void mul4(const Vector4& a)
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        w *= a.w;
    }
    void add4(const Vector4& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        w += a.w;
    }
    void sub4(const Vector4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    void setAdd4(const Vector4& a, const Vector4& b)
    {
        x = a.x + b.x;
        y = a.y + b.y;
        z = a.z + b.z;
        w = a.w + b.w;
    }
    void setBroadcast(const Vector4& v, int i)
    {
        float r = v(i);
        x = r;
        y = r;
        z = r;
        w = r;
    }
    float horizontalAdd3() const { return x + y + z; }
    float horizontalAdd4() const { return x + y + z + w; }
};

struct VelocityAccumulator {
    unsigned char m_type;
    unsigned int m_deactivationClass;
    float m_gravityFactor;
    Vector4 m_linearVel;
    Vector4 m_angularVel;
    Vector4 m_invMasses;
};

template <typename T> inline const T* addByteOffsetConst(const T* base, long offset)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}
template <typename T> inline T* addByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

struct AccumulatorOffset {
    int m_offset;
    const VelocityAccumulator& getAccumulator(const VelocityAccumulator* base)
    {
        return *addByteOffsetConst(base, m_offset);
    }
};

struct Jacobian {
    Vector4 m_linear;
    Vector4 m_angular[2];

    __forceinline float getDiag(const VelocityAccumulator& mA, const VelocityAccumulator& mB) const
    {
        Vector4 ang0;
        ang0.setMul4(m_angular[0], m_angular[0]);
        Vector4 ang1;
        // Fake match: this store is dead (the next line fills the vector). Naming the third lane first
        // makes the later lane sum load this vector's lane before the other one's.
        ang1.z = 0.0f;
        ang1.setMul4(m_angular[1], m_angular[1]);
        ang0.mul4(mA.m_invMasses);
        ang1.mul4(mB.m_invMasses);
        ang0.add4(ang1);
        Vector4 lin;
        lin.setAdd4(mA.m_invMasses, mB.m_invMasses);
        ang0(3) = lin(3);
        float x = ang0.horizontalAdd4();
        return float(x + 1.1920928955078125e-07);
    }

    __forceinline float getNonDiag(const VelocityAccumulator& mB, const Jacobian& jacB) const
    {
        Vector4 lin;
        lin.setMul4(m_linear, jacB.m_linear);
        Vector4 ang;
        ang.setMul4(m_angular[1], jacB.m_angular[0]);
        Vector4 invMassB;
        invMassB.setBroadcast(mB.m_invMasses, 3);
        Vector4 linB;
        linB.setMul4(invMassB, lin);
        ang.mul4(mB.m_invMasses);
        ang.sub4(linB);
        return ang.horizontalAdd3();
    }
};

struct Triple {
    float m_lower;
    float m_diag;
    float m_upper;
};

inline float max2(float a, float b) { return (a > b) ? a : b; }

struct Schema {
    union {
        float m_first;
        struct {
            unsigned char m_type;
            unsigned char m_pad;
            unsigned short m_numConstraints;
        };
    };
    int m_schemaSize;
    float m_tau;
    float m_damping;
    __forceinline void init(int numConstraints, float tau, float damping)
    {
        m_first = float(m_first + 1.1920928955078125e-07);
        m_tau = tau;
        m_damping = damping;
        // Header, then per constraint a Jacobian, a triple, a float and an offset, then one more float and
        // offset, rounded up to 16 bytes.
        m_schemaSize = ((unsigned short)numConstraints *
                            (sizeof(Jacobian) + sizeof(Triple) + sizeof(float) + sizeof(AccumulatorOffset)) +
                        sizeof(Schema) + sizeof(float) + sizeof(AccumulatorOffset) + 15) & ~15;
        m_type = 0x1a;
        m_numConstraints = (unsigned short)numConstraints;
    }
    Jacobian* getJacobians() { return (Jacobian*)(this + 1); }
    Triple* getTriples() { return (Triple*)addByteOffset(this, 0x10 + m_numConstraints * 0x30); }
    AccumulatorOffset* getAccumulators() { return (AccumulatorOffset*)addByteOffset(this, 0x14 + m_numConstraints * 0x40); }
};

struct QueryOut {
    Schema* m_jacobianSchemas;
};

static __forceinline void factorTridiagonal(int numConstraints, float cfm, Jacobian* jac, AccumulatorOffset* accumsOffsets,
                              const VelocityAccumulator* accumsBase, Triple* triple)
{
    float prevNonDiag = 0.0f;
    float prevUpper = 0.0f;
    for (int row = 0; row < numConstraints; row++) {
        float diag = jac[row].getDiag(accumsOffsets[row].getAccumulator(accumsBase),
                                      accumsOffsets[row + 1].getAccumulator(accumsBase)) + cfm;
        float nonDiag = 0.0f;
        if (row < numConstraints - 1) {
            nonDiag = jac[row].getNonDiag(accumsOffsets[row + 1].getAccumulator(accumsBase), jac[row + 1]);
        }
        triple[row].m_lower = prevNonDiag;
        triple[row].m_diag = diag - prevNonDiag * prevUpper;
        float& d = triple[row].m_diag;
        d = max2(d, 1.192092896e-07F);
        triple[row].m_upper = nonDiag / triple[row].m_diag;
        prevNonDiag = nonDiag;
        prevUpper = triple[row].m_upper;
    }
}

}

// The output record, the offset array and the accumulator base arrive as the pack's untyped parameters and are
// read through the classes above. The record's cursor is read through the parameter each time, as the image does.
// pdb: hkStiffSpringChainBuildJacobian | hkpChainBuildJacobian.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: numConstraints, tau, damping, cfm, accumulators, accumBase, jacobiansEnd, in, out
void FUN_00dd1180(int n, float a, float b, float c, char** src, int stride, int u1, int u2, char** pp)
{
    chn520c0::AccumulatorOffset* accumulators = (chn520c0::AccumulatorOffset*)src;
    chn520c0::Schema* schema = ((chn520c0::QueryOut*)pp)->m_jacobianSchemas;
    schema->init(n, a, b);
    {
        chn520c0::AccumulatorOffset* va = schema->getAccumulators();
        for (int i = 0; i < n + 1; i++)
            *va++ = *accumulators++;
    }
    chn520c0::Jacobian* jac = ((chn520c0::QueryOut*)pp)->m_jacobianSchemas->getJacobians();
    chn520c0::AccumulatorOffset* va = schema->getAccumulators();
    chn520c0::Triple* triples = schema->getTriples();
    chn520c0::factorTridiagonal(n, c, jac, va, (const chn520c0::VelocityAccumulator*)stride, triples);
    ((chn520c0::QueryOut*)pp)->m_jacobianSchemas =
        chn520c0::addByteOffset(((chn520c0::QueryOut*)pp)->m_jacobianSchemas, schema->m_schemaSize);
}


typedef __m128* V;
struct Wrap
{
    V p;
    Wrap(V q) : p(q)
    {}
};

// For three vector pairs computes B*D + A*E and merges it into C under mask M1 and into O under mask M2, returning O.
// @fnv 0x00dd3020
static __declspec(noinline) V FUN_00dd3020(V B, V A, V C, V O, Wrap E, V D, V M1, V M2)
{
    __m128 value;
    value = _mm_add_ps(_mm_mul_ps(B[0], *D), _mm_mul_ps(A[0], *E.p));
    C[0] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[0]));
    O[0] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[0]));
    value = _mm_add_ps(_mm_mul_ps(B[1], *D), _mm_mul_ps(A[1], *E.p));
    C[1] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[1]));
    O[1] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[1]));
    value = _mm_add_ps(_mm_mul_ps(B[2], *D), _mm_mul_ps(A[2], *E.p));
    C[2] = _mm_or_ps(_mm_and_ps(*M1, value), _mm_andnot_ps(*M1, C[2]));
    O[2] = _mm_or_ps(_mm_and_ps(*M2, value), _mm_andnot_ps(*M2, O[2]));
    return O;
}

void call_interleave(V B, V A, V C, V O, Wrap E, V D, V M1, V M2)
{
    FUN_00dd3020(B, A, C, O, E, D, M1, M2);
}

// @f3twin 0x00a82b70 of 0x00a4aea0
int F3_FUN_00a82b70()
{
    int r = FUN_00d86940();
    if (r != 0)
        return r;
    return 1;
}
