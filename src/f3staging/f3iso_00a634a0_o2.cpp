#include <new>
// src/f3staging/f3iso_00a634a0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00a634a0 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a634a0 (community match, verified in this file)
struct hkBoolQ
{
    char value;
    hkBoolQ(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};
struct hkClassQ;
struct hkVtableClassRegistryQ
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual const hkClassQ* GetClassFromVirtualInstance(const void* object);
};
struct hkDisplayOStreamQ;
struct hkLayoutRulesQ { int unk00; };
struct hkWrittenObjectQ { const void* m_object; const hkClassQ* m_class; };
struct hkObjectPatchQ
{
    int unk00;
    int unk04;
    const void* m_object;
    int unk0C;
    const hkClassQ* m_class;
    int unk14;
};
template <class T> struct hkArrQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct Ctx_a634
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
    hkVtableClassRegistryQ* m_vtableRegistry;
};
struct hkInspectProcessQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkDisplayOStreamQ* m_pDisplayStream;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    Ctx_a634* m_iValueAtOffset0C;

    int FUN_00a634a0(const void* object, const hkClassQ* pClassInfo, ::hkBoolQ recurse,
                     hkArrQ<hkWrittenObjectQ>* written) throw();

    __forceinline int sendRecursiveQ(const void* apObject, const hkClassQ* apClass,
                                     hkArrQ<hkWrittenObjectQ>* apWrittenObjects) throw()
    {
        return FUN_00a634a0(apObject, apClass, true, apWrittenObjects);
    }
};

extern unsigned int DAT_010f3170;
extern hkLayoutRulesQ DAT_00e7e644;
extern void* DAT_00e7a244[];
extern void* DAT_00dcc494[];

struct Alloc_a634
{
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
extern "C" __declspec(dllimport) Alloc_a634* __stdcall TlsGetValue(unsigned int);

template <typename T> struct Arr_a634
{
    T* data;
    int size;
    int cap;
    Arr_a634() : data(0), size(0), cap(0x80000000) {}
    ~Arr_a634()
    {
        if (!(cap & 0x80000000)) {
            int n = cap & 0x3fffffff;
            Alloc_a634* a = TlsGetValue(DAT_010f3170);
            a->FUN_008f6d90(data, n * sizeof(T), 0x17);
        }
    }
};

template <typename T> struct Owned_a634
{
    void FUN_00943db0(int flags) throw();
};

template <typename T> struct Writer_a634
{
    void* vtbl;
    int unk04;
    Owned_a634<T>* unk08;
    int unk0C;
    int unk10;
    void FUN_00943bb0(Arr_a634<char>* arr, int ownership) throw();
    ~Writer_a634()
    {
        vtbl = DAT_00e7a244;
        if (unk10 == 0 && unk08)
            unk08->FUN_00943db0(1);
        vtbl = DAT_00dcc494;
    }
};

template <typename T> struct Layout_a634
{
    int unk00;
    void FUN_009b2540(const hkLayoutRulesQ& rules) throw();
};

template <typename T> struct ClassInfo_a634
{
    ::hkBoolQ FUN_009b0780() const throw();
};

template <typename T> struct Stream_a634
{
    void FUN_009ee8f0(int size) throw();
    void FUN_009ee560(unsigned int cmd) throw();
    void FUN_009ee740(const char* data, int size) throw();
};

void __cdecl FUN_00901f10(void* arr, int elemSize) throw();
int __cdecl FUN_00a8bb00(void* writer, void* layout, const void* object, int flags, const void* original,
                         const hkClassQ* pClassInfo, void* patches) throw();

// pdb: hkInspectProcess::writeObject | hkInspectProcess.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: ptr, klass, recurse, recursionStack
int hkInspectProcessQ::FUN_00a634a0(const void* object, const hkClassQ* pClassInfo, ::hkBoolQ recurse,
                                    hkArrQ<hkWrittenObjectQ>* written) throw()
{
    Layout_a634<int> layout;
    layout.FUN_009b2540(DAT_00e7e644);
    Arr_a634<hkObjectPatchQ> patches;

    const hkClassQ* realClass = pClassInfo;
    if (m_iValueAtOffset0C->m_vtableRegistry && ((const ClassInfo_a634<int>*)pClassInfo)->FUN_009b0780())
    {
        realClass = m_iValueAtOffset0C->m_vtableRegistry->GetClassFromVirtualInstance(object);
        if (!realClass)
            realClass = pClassInfo;
    }

    if (recurse)
    {
        int i;
        for (i = 0; i < written->m_iElementCount; i++)
        {
            if (written->m_data[i].m_object == object)
                break;
        }
        if (i < written->m_iElementCount)
            return 0;
        if (written->m_iElementCount == (written->m_iCapacityState & 0x3fffffff))
            FUN_00901f10(written, sizeof(hkWrittenObjectQ));
        hkWrittenObjectQ* w = written->m_data + written->m_iElementCount;
        written->m_iElementCount++;
        w->m_object = object;
        w->m_class = realClass;
    }

    Arr_a634<char> buffer;
    Writer_a634<int> writer;
    writer.FUN_00943bb0(&buffer, 1);
    int size = FUN_00a8bb00(&writer, &layout, object, 0, object, realClass, &patches);
    if (size != buffer.size || size < 1)
        return -1;

    int total = size + 1;
    ((Stream_a634<int>*)m_pDisplayStream)->FUN_009ee8f0(total);
    ((Stream_a634<int>*)m_pDisplayStream)->FUN_009ee560(0x24);
    ((Stream_a634<int>*)m_pDisplayStream)->FUN_009ee740(buffer.data, buffer.size);
    if (recurse)
    {
        for (int i = 0; i < patches.size; i++)
        {
            const void* obj = patches.data[i].m_object;
            const hkClassQ* cls = patches.data[i].m_class;
            total += sendRecursiveQ(obj, cls, written);
        }
    }
    return total;
}
