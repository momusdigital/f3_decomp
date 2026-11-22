#include "f3_common.h"
// src/havok/common/serialize/copier/hkdeepcopier_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/copier/hkdeepcopier.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/copier/hkdeepcopier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/copier/hkdeepcopier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkMemAlloc
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAlloc* m_pStreamAllocator;
    hkMemAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* arr, int elemSize);
void* AllocateWithHeader(hkMemAlloc& alloc, int numBytes);
void FUN_00cb1260(void* dst, const void* src, int n);

__forceinline hkMemRouter* GetRouter()
{
    return (hkMemRouter*)FUN_00c85750();
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArr()
    {
        _clearAndDeallocate(GetRouter()->heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(hkMemAlloc& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void AddBack(const T& t)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void expandRecord(int offset, const void* obj, const char* name)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        ::new (m_data + m_iElementCount) T(offset, obj, name);
        m_iElementCount++;
    }
    __forceinline void pushBackConstruct(const T& t)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        ::new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct ClassInfo
{
    const char* FUN_00d46d40() const;
    hkBoolRet GetLastNodeFlag() const;
};

struct VtableClassReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual const ClassInfo* GetClassFromVirtualInstance(const void* obj);
};

struct LoadedObjectReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void RegisterLoadedObject(void* obj, const char* typeName);
};

struct PtrMapBase
{
    void** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    __forceinline PtrMapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~PtrMapBase();
    void EnsureCapacity(hkMemAlloc& alloc, int n);
    void FUN_00cb1870(hkMemAlloc& alloc, const void* key, int val);
    int FindSlot(const void* key);
    int LookupHashEntry(const void* key, int def);
    void ProcessArgument(hkMemAlloc& alloc);
    __forceinline bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
};

struct PtrMap
{
    PtrMapBase m_map;
    __forceinline PtrMap()
    {
        m_map.EnsureCapacity(GetRouter()->heap(), 0);
    }
    __forceinline ~PtrMap()
    {
        m_map.ProcessArgument(GetRouter()->heap());
    }
    __forceinline void insert(const void* key, int val)
    {
        m_map.FUN_00cb1870(GetRouter()->heap(), key, val);
    }
    __forceinline int FindValueForKey(const void* key, int def)
    {
        return m_map.LookupHashEntry(key, def);
    }
    __forceinline bool contains(const void* key)
    {
        return m_map.isValid(m_map.FindSlot(key));
    }
};

struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};
extern const StructureLayoutRules g_hostLayoutRules_e4afe0;

struct StructLayout
{
    StructureLayoutRules m_kLayoutRules;
    StructLayout(const StructureLayoutRules& rules);
};

struct LocalFixup
{
    int m_iSourceOffset;
    int m_iTargetOffset;
};
struct TypedPointerRecord
{
    int m_iSourceOffset;
    void* m_pData;
    const ClassInfo* m_pClassInfo;
    int m_type;
};
struct FinishFixup
{
    int m_iSourceOffset;
    const char* m_pClassName;
};
struct ImportFixup
{
    int m_iSourceOffset;
    const char* m_pImportName;
};

struct RelocInfo
{
    hkArr<LocalFixup> m_pTrailingData;
    hkArr<TypedPointerRecord> m_pGlobal;
    hkArr<FinishFixup> m_kFinishFixups;
    hkArr<ImportFixup> m_kImports;
    void* m_kNodePool;
    __forceinline RelocInfo() : m_kNodePool(0)
    {}
    ~RelocInfo();
};

struct OArchive
{
    void* m_ppVirtualMethodTable;
    int m_memSizeAndRefCount;
    void* m_pStreamWriter;
    OArchive(hkArr<char>& buf);
    ~OArchive();
    void* GetStreamWriter()
    {
        return m_pStreamWriter;
    }
};

struct ObjCopier
{
    void* m_ppVirtualMethodTable;
    int m_memSizeAndRefCount;
    int m_iInputSize;
    int m_iOutputSize;
    int m_flags;
    bool m_bStreamResult;
    ObjCopier(const StructLayout& layoutIn, const StructLayout& layoutOut, int flags);
    ~ObjCopier();
    int hkObjectCopier_copyObject(const void* dataIn, const ClassInfo& klassIn, void* dataOut, const ClassInfo& klassOut,
                     RelocInfo& reloc);
};

struct PendingCopy
{
    const void* m_object;
    const ClassInfo* m_pObjectTypeInfo;
};

struct CopyRecord
{
    int m_offset;
    const void* m_object;
    const char* m_pName;
    __forceinline CopyRecord(int offset, const void* obj, const char* name)
        : m_offset(offset), m_object(obj), m_pName(name)
    {}
};

// @f3 0x00a85110 (community match, verified in this file)
namespace na85110
{
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long) throw();
extern unsigned long DAT_010f3170;
struct ThreadMemory
{
    void* FUN_008f6f60(int bytes, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
inline ThreadMemory* Mem() throw()
{
    return (ThreadMemory*)TlsGetValue(DAT_010f3170);
}
void __cdecl FUN_00901f10(void* arr, int elemSize);
void __cdecl FUN_009234e0(void* dst, const void* src, int n);

template <class T> struct Arr
{
    T* m_data;
    int m_size;
    int m_capAndFlags;
    Arr() : m_data(0), m_size(0), m_capAndFlags(0x80000000)
    {}
    ~Arr()
    {
        if ((m_capAndFlags & 0x80000000) == 0)
        {
            int cap = m_capAndFlags & 0x3fffffff;
            Mem()->FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void PushBack(const T& t)
    {
        if (m_size == (m_capAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        m_data[m_size] = t;
        m_size++;
    }
};
struct Map
{
    void* m_elem;
    int m_capFlags;
    int m_pairCount;
    Map();
    ~Map();
    void Insert(const void* key, int val);
    int Get(const void* key, int def);
    int FindKey(const void* key);
    bool Contains(const void* key)
    {
        return FindKey(key) <= m_pairCount;
    }
};
struct Bool
{
    char m_value;
    Bool(bool b) : m_value(b)
    {}
};
struct Class
{
    Bool HasVtable() const;
    const char* GetName() const;
};
struct VtableReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual const Class* GetClassFromVirtualInstance(const void* obj);
};
struct LoadedReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void RegisterLoadedObject(void* obj, const char* typeName);
};
struct LFix
{
    int m_fromOffset;
    int m_toOffset;
};
struct GlobalFixup
{
    int m_fromOffset;
    void* m_toAddress;
    const Class* m_toClass;
};
struct Reloc
{
    Arr<LFix> m_local;
    Arr<GlobalFixup> m_global;
    Arr<LFix> m_finish;
    Arr<LFix> m_imports;
    void* m_pool;
    Reloc() : m_pool(0)
    {}
    ~Reloc();
};
struct Writer;
struct OArch
{
    void* m_vtbl;
    int m_refCount;
    Writer* m_writer;
    OArch(Arr<char>& buf);
    ~OArch();
};
struct Layout
{
    StructureLayoutRules m_rules;
    Layout(const StructureLayoutRules& rules);
};
struct Copier
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Copier(const Layout& layoutIn, const Layout& layoutOut, int flags);
    ~Copier();
    int CopyObject(const void* dataIn, const Class& klassIn, Writer* dataOut, const Class& klassOut, Reloc& reloc);
};
struct Pending
{
    const void* m_object;
    const Class* m_class;
};
struct Record
{
    int m_offset;
    const void* m_object;
    const char* m_name;
};
extern const StructureLayoutRules DAT_01061524;
}

// pdb: hkDeepCopier::deepCopy | hkDeepCopier.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_seq), high
void* hkDeepCopier_deepCopy(const void* dataIn, const ClassInfo& klassInIn, PtrMap* previousCopiesIn,
                   VtableClassReg* vtableClassRegistryIn, LoadedObjectReg* loadedObjectRegistryIn, int flags)
{
    using namespace na85110;
    const Class& klassIn = (const Class&)klassInIn;
    Map* previousCopies = (Map*)previousCopiesIn;
    VtableReg* vtableClassRegistry = (VtableReg*)vtableClassRegistryIn;
    LoadedReg* loadedObjectRegistry = (LoadedReg*)loadedObjectRegistryIn;

    Arr<char> buffer;
    OArch dataOut(buffer);
    Reloc reloc;
    Arr<Pending> todo;
    {
        Pending p;
        p.m_object = dataIn;
        p.m_class = &klassIn;
        todo.PushBack(p);
    }
    Map doneObjects;
    Arr<Record> records;
    Copier copier(DAT_01061524, DAT_01061524, flags);

    for (int todoIndex = 0; todoIndex < todo.m_size; ++todoIndex)
    {
        const void* obj = todo.m_data[todoIndex].m_object;
        const Class* klass = todo.m_data[todoIndex].m_class;
        doneObjects.Insert(obj, buffer.m_size);
        int globalStart = reloc.m_global.m_size;
        if (klass->HasVtable().m_value)
            klass = vtableClassRegistry->GetClassFromVirtualInstance(obj);

        {
            Record r;
            r.m_offset = buffer.m_size;
            r.m_object = obj;
            r.m_name = klass->GetName();
            records.PushBack(r);
        }

        copier.CopyObject(obj, *klass, dataOut.m_writer, *klass, reloc);

        for (int j = globalStart; j < reloc.m_global.m_size; ++j)
        {
            void* ptr = reloc.m_global.m_data[j].m_toAddress;
            if (!ptr)
                continue;
            const Class* ptrClass = reloc.m_global.m_data[j].m_toClass;
            if (!ptrClass)
                continue;
            if (previousCopies)
            {
                int prev = previousCopies->Get(ptr, 0);
                if (prev)
                {
                    reloc.m_global.m_data[j].m_toAddress = (void*)prev;
                    continue;
                }
            }
            if (!doneObjects.Contains(ptr))
            {
                Pending p;
                p.m_object = ptr;
                p.m_class = ptrClass;
                todo.PushBack(p);
            }
        }
    }

    int size = buffer.m_size;
    if (size)
    {
        char* versioned = (char*)Mem()->FUN_008f6f60(size, 5);
        FUN_009234e0(versioned, buffer.m_data, buffer.m_size);

        for (int i = 0; i < reloc.m_local.m_size; ++i)
            *(char**)(versioned + reloc.m_local.m_data[i].m_fromOffset) = versioned + reloc.m_local.m_data[i].m_toOffset;

        for (int i = 0; i < reloc.m_global.m_size; ++i)
        {
            void* ptr = reloc.m_global.m_data[i].m_toAddress;
            int offset = doneObjects.Get(ptr, -1);
            if (offset != -1)
                ptr = versioned + offset;
            *(void**)(versioned + reloc.m_global.m_data[i].m_fromOffset) = ptr;
        }

        int i;
        int off;
        if (previousCopies)
        {
            i = 0;
            if (records.m_size > 0)
            {
                off = 0;
                do
                {
                    Record* r = (Record*)((char*)records.m_data + off);
                    previousCopies->Insert(r->m_object, (int)(versioned + r->m_offset));
                    ++i;
                    off += sizeof(Record);
                } while (i < records.m_size);
            }
        }

        if (loadedObjectRegistry)
        {
            i = 0;
            if (records.m_size > 0)
            {
                off = 0;
                do
                {
                    Record* r = (Record*)((char*)records.m_data + off);
                    loadedObjectRegistry->RegisterLoadedObject(versioned + r->m_offset, r->m_name);
                    ++i;
                    off += sizeof(Record);
                } while (i < records.m_size);
            }
        }

        return versioned;
    }
    return 0;
}

