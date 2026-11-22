#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_010d16f0;
extern int DAT_010d1700;
extern int DAT_010d1720;
extern void __cdecl FUN_00ddcc60();
struct FUN_00d62fe0_cls
{
    void __thiscall FUN_00d62fe0();
};
extern int DAT_01268fc0;
extern int DAT_01268fc4;
struct FUN_00d63210_class
{
    int GetValueByFlag();
};
typedef void(__cdecl* SnapshotFn)();
struct ProfileRegistry
{
    int FUN_00dd9380(const char* apName, SnapshotFn apfnHandler);
};
extern ProfileRegistry* DAT_01269cd0;
extern int DAT_01268fc4;
extern int DAT_01268fc0;
void __cdecl FUN_00d62f20();
void __cdecl AllocateRecordWithData();
void __cdecl hkpWorldSnapshotViewer_registerViewer();
struct FUN_00c7be20_cls;
struct FUN_00c7be20_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct FUN_00c7be20_src
{
    int unk00;
    int unk04;
    int* m_08;
    int m_0c;
};
struct FUN_00c7be20_arr
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};
void* __cdecl FUN_00c85750() throw();
void __cdecl FUN_00c908c0(void* allocator, FUN_00c7be20_arr* self, unsigned int newCap, int elemSize);
struct FUN_00c7be20_cls
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
    int unk44;
    FUN_00c7be20_src* m_48;

    void CopySourceArray(FUN_00c7be20_arr* out);
};
struct SubObj
{
    virtual void vfunc0();
    virtual void vfunc1(void* item);
};
struct Container
{
    char pad[0x6c];
    void** m_data;
    int m_iElementCount;
};
struct FUN_00d62fa0_class
{
    char pad[0x18];
    SubObj m_subObj;
    Container* m_container;

    void __thiscall ProcessContainerItems();
};
extern int DAT_010d1794;
extern int DAT_010d1774;
extern int DAT_010d1764;
struct SubObject
{
    void Init(int a, int b);
};
struct FUN_00d63280_cls
{
    void* m_vtbl0;
    int unk04;
    void* m_vtbl8;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vtbl20;
    int unk24;
    SubObject m_sub28;

    void Setup(int b);
    FUN_00d63280_cls* FUN_00d63280(int a, int b);
};

class hkBool
{
  public:
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* __cdecl FUN_00c85750() throw();

struct FUN_00c7be20_arr;
void __cdecl FUN_00c908c0(void* allocator, FUN_00c7be20_arr* self, unsigned int newCap, int elemSize);

inline hkMemoryAllocator& containerHeap()
{
    return ((NineIntegerRecord*)FUN_00c85750())->heap();
}

struct hkCharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkCharArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkCharArray()
    {
        hkMemoryAllocator& alloc = containerHeap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    char* begin()
    {
        return m_data;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& alloc = containerHeap();
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, (FUN_00c7be20_arr*)this, newSize, 1);
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct hkArrayStreamWriter
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    hkCharArray* m_aiIndexedValues;
    int m_offset;
    int m_ownership;

    hkArrayStreamWriter(hkCharArray* arr, int ownership);
    ~hkArrayStreamWriter();
};

struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

extern StructureLayoutRules DAT_010d6ae8;
extern StructureLayoutRules DAT_011b7b88;
extern int DAT_01268fc0;
extern int DAT_01268fc4;

struct hkpWorld;

hkBool __cdecl FUN_00cc0d60(hkpWorld* world, hkArrayStreamWriter* writer, hkBool binary,
                            const StructureLayoutRules* rules, int aiFlags);

struct hkDisplaySerializeOStream
{
    void hkOArchive_write32u(int n);
    void hkOArchive_write8u(unsigned int b);
    void WriteInt(int n);
    void FUN_00d607b0(const char* buf, int n);
};

struct hkProcessHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void deleteProcess(int tag);
};

struct hkpPhysicsContext
{
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
    hkpWorld** m_ppWorlds;
    int m_numWorlds;

    int getNumWorlds() const
    {
        return m_numWorlds;
    }
    hkpWorld* getWorld(int i) const
    {
        return m_ppWorlds[i];
    }
};

struct FUN_00d63040_cls
{
    int unk00;
    int unk04;
    int unk08;
    hkDisplaySerializeOStream* m_pDisplayStream;
    int unk10;
    hkProcessHandler* m_pProcessHandler;
    int unk18;
    hkpPhysicsContext* m_iValueAtOffset0C;
    hkBool m_convertToPC;

    void FUN_00d63040(float frameTimeInMs);
};

// @f3 0x009ef520 (community match, verified in this file)
extern int DAT_010f3170;
namespace q2 {
struct Heap {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30;
    int limit;
    int unk38, unk3C, unk40, unk44;
    void* head2;
    int count2;
    void FUN_008f6d90(void* p, int bytes, int tag);
    void FUN_008f6890(int row, void* p, int tag);
};
__declspec(dllimport) Heap* __stdcall FUN_00d9b080(int) throw();
struct CharArray;
void __cdecl FUN_00901e90(CharArray* arr, int newCap, int elemSize);
struct CharArray {
    char* m_data;
    int m_size;
    int m_cap;
    CharArray() : m_data(0), m_size(0), m_cap(0x80000000) {}
    ~CharArray() {
        if ((m_cap & 0x80000000) == 0) {
            int bytes = m_cap & 0x3fffffff;
            Heap* h = FUN_00d9b080(DAT_010f3170);
            h->FUN_008f6d90(m_data, bytes, 0x17);
        }
    }
    int getCapacity() const { return m_cap & 0x3fffffff; }
    void reserve(int n) {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, (n < cap2) ? cap2 : n, 1);
        }
    }
    void setSize(int n) { reserve(n); m_size = n; }
    void operator delete(void* p) {
        Heap* h = FUN_00d9b080(DAT_010f3170);
        if (*(volatile int*)&h->count2 >= h->limit)
            h->FUN_008f6890(2, p, 0x17);
        else {
            void* head = h->head2;
            ++h->count2;
            *(void**)p = head;
            h->head2 = p;
        }
    }
};
}
class hkBaseObject {
public:
    virtual ~hkBaseObject() {}
};
class FUN_00943bb0 : public hkBaseObject {
public:
    int m_memSizeAndFlags;
    q2::CharArray* m_arr;
    int m_offset;
    int m_ownership;
    FUN_00943bb0(q2::CharArray* arr, int ownership);
    ~FUN_00943bb0() {
        if (m_ownership == 0) delete m_arr;
    }
};
namespace q2 {
hkBool __cdecl FUN_00cc0d60(hkpWorld* world, FUN_00943bb0* writer, hkBool binary,
                            const StructureLayoutRules* rules, int aiFlags);
}

// pdb: hkpWorldSnapshotViewer::step | hkpWorldSnapshotViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: frameTimeInMs
void FUN_00d63040_cls::FUN_00d63040(float frameTimeInMs)
{
    int wi = 0;
    if (m_pDisplayStream)
    {
        q2::CharArray storage;
        storage.reserve(100 * 1024);
        FUN_00943bb0 sw(&storage, 1);

        const StructureLayoutRules& rules = m_convertToPC.m_cBooleanValue ? DAT_010d6ae8 : DAT_011b7b88;
        for (; wi < m_iValueAtOffset0C->getNumWorlds(); ++wi)
        {
            storage.setSize(0);
            q2::FUN_00cc0d60(m_iValueAtOffset0C->getWorld(wi), &sw, true, &rules, 0);
            int length = storage.m_size;
            if (length >= 1)
            {
                m_pDisplayStream->hkOArchive_write32u(length + 9);
                m_pDisplayStream->hkOArchive_write8u(0xd0);
                m_pDisplayStream->hkOArchive_write8u(rules.m_ucBytesInPointer);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bLittleEndian);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bReusePaddingOptimization);
                m_pDisplayStream->hkOArchive_write8u(rules.m_bEmptyBaseClassOptimization);
                m_pDisplayStream->WriteInt(length);
                m_pDisplayStream->FUN_00d607b0(storage.m_data, length);
            }
        }
    }

    if (m_pProcessHandler)
    {
        m_pProcessHandler->deleteProcess(m_convertToPC.m_cBooleanValue ? DAT_01268fc0 : DAT_01268fc4);
    }
}

