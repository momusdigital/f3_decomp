// staging/blk_00da0000_o2.cpp: Holder, MapHolder, SpawnedOuter, SearchObject and more (48 functions)
#include "f3_common.h"
#include <windows.h>
// src/staging/blk_00da0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl InitBlockPool(void*);

// @fnv 0x00da6fa0
// pdb: hkListAgent3::create | hkpListAgent3.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: input, entry, agentData
void* __cdecl InitAndReturnTail(void* apUnused1, void* apUnused2, void* apStruct)
{
    if (apStruct)
    {
        *(int*)apStruct = 0;
        *(int*)((char*)apStruct + 4) = 0;
        *(int*)((char*)apStruct + 8) = 0x80000000;
    }
    InitBlockPool(apStruct);
    return (char*)apStruct + 16;
}

// @fnv 0x00da08c0
// pdb: cleanupLoadedObjecthkpRagdollLimitsData | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00da08c0(void** a)
{
    (**(void(__thiscall**)(void*, int))(*a))(a, 0);
}

extern int DAT_010c6bec;

extern int DAT_010c6fd0;

extern int DAT_010d6014;

struct FUN_00db7ab0_class
{
    void* __thiscall FUN_00db7ab0(void* a, void* b, void* c);
};

// @fnv 0x00db7ab0
// pdb: hkStaticClassNameRegistry::hkStaticClassNameRegistry | hkStaticClassNameRegistry.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
// pdb params: classes, classVersion, name
void* __thiscall FUN_00db7ab0_class::FUN_00db7ab0(void* a, void* b, void* c)
{
    *(short*)((char*)this + 6) = 1;
    *(int*)((char*)this + 12) = (int)a;
    *(int*)this = (int)&DAT_010d6014;
    *(int*)((char*)this + 16) = (int)b;
    *(int*)((char*)this + 20) = 1;
    *(int*)((char*)this + 8) = (int)c;
    return this;
}

// @fnv 0x00db7790
// pdb: hkCrcStreamWriter<unsigned int,3988292384>::calcPermute | hkClass.obj | tesv_win, hash, low
int __cdecl Crc32ShiftRight8(unsigned int uiValue)
{
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    return uiValue;
}

void __cdecl FUN_00da6dc0(void*);
void __cdecl FUN_00da6de0(void*);
void __cdecl FUN_00da6e30(void*);
void __cdecl FUN_00da6e60(void*);
void __cdecl BuildEventIndex(void);
void* __cdecl InitAndReturnTail(void* a, void* b, void* c);
void* __cdecl FUN_00da6e10(void* a, void* b, void* c);

// Fills the object at p with function pointers at fixed offsets, zeroes several pointer slots and sets the byte at offset 0x30 to 1.
// @fnv 0x00da6fd0
// pdb: hkListAgent3::initAgentFunc | hkpListAgent3.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: hkpCollectionAgent3::initAgentFunc)
// pdb params: f
void __cdecl FUN_00da6fd0(void* apObject)
{
    char* b = (char*)apObject;
    *(void**)(b + 0) = &InitAndReturnTail;
    *(void**)(b + 0x2c) = &BuildEventIndex;
    *(void**)(b + 0x28) = 0;
    *(void**)(b + 0x8) = 0;
    *(void**)(b + 0xc) = 0;
    *(void**)(b + 0x10) = 0;
    *(void**)(b + 0x14) = 0;
    *(void**)(b + 0x18) = &FUN_00da6e60;
    *(void**)(b + 0x1c) = &FUN_00da6de0;
    *(void**)(b + 0x20) = &FUN_00da6e10;
    *(void**)(b + 0x24) = &FUN_00da6e30;
    *(void**)(b + 0x4) = &FUN_00da6dc0;
    *(unsigned char*)(b + 0x30) = 1;
}

struct FUN_00da0740_vt
{
    virtual void v0(int);
};
// @fnv 0x00da0740
// pdb: cleanupLoadedObjecthkpPoweredChainMapper | hkpUtilitiesReflections.obj | tesv_win, objrun_open, low
void __cdecl FUN_00da0740(FUN_00da0740_vt* p)
{
    p->v0(0);
}

extern int g_unk0126958c;

// @fnv 0x00da0610
void* __cdecl FUN_00da0610()
{
    return &g_unk0126958c;
}

extern char DAT_012695bc;

// @fnv 0x00da0630
char* __cdecl FUN_00da0630(void)
{
    return &DAT_012695bc;
}

extern int DAT_012695ec;

// @fnv 0x00da0660
int* __cdecl FUN_00da0660(void)
{
    return &DAT_012695ec;
}

extern int g_unk0126961c;

// @fnv 0x00da0670
int* __cdecl FUN_00da0670()
{
    return &g_unk0126961c;
}

struct FUN_00da0720_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00da0720
// pdb: cleanupLoadedObjecthkpPoweredChainMapper | hkpPoweredChainMapperClass.obj | fnv360_0822_retail, objrun_open, low
void __cdecl FUN_00da0720(FUN_00da0720_Class* param_1)
{
    param_1->vf00(0);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126967c;
// @fnv 0x00da0730
// pdb: hkpEntity::staticClass | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
CpuOpaque* __cdecl FUN_00da0730()
{
    return &DAT_0126967c;
}

extern int DAT_012696c4;

// @fnv 0x00da0750
int* __cdecl FUN_00da0750()
{
    return &DAT_012696c4;
}

// FUN_00da08a0 : cdecl, 13 bytes
//   mov ecx, [esp+4]
//   mov eax, [ecx]
//   mov edx, [eax]
//   push 0
//   call edx
//   ret
// Calls slot 0 of the object's vtable with the argument 0.

struct FUN_00da08a0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00da08a0
int __cdecl FUN_00da08a0(FUN_00da08a0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_0126970c;

// @fnv 0x00da08b0
int* __cdecl FUN_00da08b0()
{
    return &DAT_0126970c;
}

extern int DAT_01269754;

// @fnv 0x00da08d0
// pdb: hkpKeyframedRigidMotion::staticClass | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void* __cdecl FUN_00da08d0(void)
{
    return &DAT_01269754;
}

extern int DAT_010c6bec;

// @fnv 0x00da0910
// pdb: getVtablehkpDefaultWorldMemoryWatchDog | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
void* __cdecl FUN_00da0910(void)
{
    return &DAT_010c6bec;
}

struct DA0920FinishFlag
{
    int m_bFinishing;
};

class DA0920Half
{
  public:
    short m_uiFilterValue;

    void operator=(float f)
    {
        int t = *reinterpret_cast<int*>(&f);
        m_uiFilterValue = static_cast<short>(t >> 16);
    }
};

class DA0920Base
{
  public:
    short unk004;
    short unk006;
    short unk008;
    short unk00A;
    short unk00C;
    short unk00E;
    short unk010;
    short unk012;
    short unk014;
    short unk016;
    short unk018;
    short unk01A;
    short unk01C;
    short unk01E;
    short unk020;
    short unk022;
    short unk024;
    short unk026;
    short unk028;
    short unk02A;
    short unk02C;
    short unk02E;
    short unk030;
    short unk032;
    short unk034;
    short unk036;
    short unk038;
    short unk03A;
    short unk03C;
    short unk03E;
    short unk040;
    short unk042;
    short unk044;
    short unk046;
    short unk048;
    short unk04A;
    short unk04C;
    short unk04E;
    short unk050;
    short unk052;
    short unk054;
    short unk056;
    short unk058;
    short unk05A;
    short unk05C;
    short unk05E;
    short unk060;
    short unk062;
    short unk064;
    short unk066;
    short unk068;
    short unk06A;
    short unk06C;
    short unk06E;
    short unk070;
    short unk072;
    short unk074;
    short unk076;
    short unk078;
    short unk07A;
    short unk07C;
    short unk07E;
    short unk080;
    short unk082;
    short unk084;
    short unk086;
    short unk088;
    short unk08A;
    short unk08C;
    short unk08E;
    short unk090;
    short unk092;
    short unk094;
    short unk096;
    short unk098;
    short unk09A;
    short unk09C;
    short unk09E;
    short unk0A0;
    short unk0A2;
    short unk0A4;
    short unk0A6;
    short unk0A8;
    short unk0AA;
    short unk0AC;
    short unk0AE;
    short unk0B0;
    short unk0B2;
    short unk0B4;
    short unk0B6;
    short unk0B8;
    short unk0BA;
    short unk0BC;
    short unk0BE;
    short unk0C0;
    short unk0C2;
    short unk0C4;
    short unk0C6;
    short unk0C8;
    short unk0CA;
    short unk0CC;
    short unk0CE;
    short unk0D0;
    short unk0D2;
    short unk0D4;
    short unk0D6;
    short unk0D8;
    short unk0DA;
    short unk0DC;
    short unk0DE;
    short unk0E0;
    short unk0E2;
    short unk0E4;
    short unk0E6;
    short unk0E8;
    short unk0EA;
    short unk0EC;
    short unk0EE;
    short unk0F0;
    short unk0F2;
    short unk0F4;
    short unk0F6;
    short unk0F8;
    short unk0FA;
    short unk0FC;
    short unk0FE;
    short unk100;
    short unk102;
    short unk104;
    short unk106;
    short unk108;
    short unk10A;
    short unk10C;
    short unk10E;
    short unk110;
    short unk112;
    short unk114;
    short unk116;
    short unk118;
    short unk11A;
    short unk11C;
    DA0920Half m_fWeight;

    DA0920Base(DA0920FinishFlag flag)
    {
        if (flag.m_bFinishing)
            m_fWeight = 1.0f;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

class DA0920Object : public DA0920Base
{
  public:
    DA0920Object(DA0920FinishFlag flag) : DA0920Base(flag)
    {}
    virtual void vfunc00();
};

extern int g_unk010c6c64;

// @fnv 0x00da0950
void* __cdecl FUN_00da0950()
{
    return &g_unk010c6c64;
}

extern int DAT_0126979c;

// @fnv 0x00da0970
// pdb: finishLoadedObjecthkpWorld | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
void* __cdecl FUN_00da0970()
{
    return &DAT_0126979c;
}

extern void* DAT_012697cc;

// @fnv 0x00da09a0
// pdb: getVtablehkpSimulation | hkpDynamicsReflections.obj | tesv_win, objrun_open, low
void* FUN_00da09a0()
{
    return &DAT_012697cc;
}

struct CpuOpaque;
extern CpuOpaque DAT_012697fc;
// @fnv 0x00da09c0
CpuOpaque* __cdecl FUN_00da09c0()
{
    return &DAT_012697fc;
}

extern int DAT_0126982c;

// @fnv 0x00da09e0
void* __cdecl FUN_00da09e0()
{
    return &DAT_0126982c;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126985c;
// @fnv 0x00da0a00
CpuOpaque* __cdecl FUN_00da0a00()
{
    return &DAT_0126985c;
}

extern int DAT_0126988c;

// @fnv 0x00da0a20
void* __cdecl FUN_00da0a20()
{
    return &DAT_0126988c;
}

// FUN_00da0a40 : a one-line function - getter
extern int g_target_00da0a40;
// @fnv 0x00da0a40
// pdb: getVtablehkpLinearParametricCurve | hkpLinearParametricCurveClass.obj | fnv360_0822_retail, objrun_open, low
void* FUN_00da0a40()
{
    return &g_target_00da0a40;
}

extern int DAT_012698ec;

// @fnv 0x00da0a60
void* __cdecl FUN_00da0a60()
{
    return &DAT_012698ec;
}

// FUN_00da0a80 : returns the address of a global data object.
extern int DAT_0126991c;

// @fnv 0x00da0a80
int* __cdecl FUN_00da0a80(void)
{
    return &DAT_0126991c;
}

extern int DAT_0126994c;

// @fnv 0x00da0aa0
int __cdecl FUN_00da0aa0()
{
    return reinterpret_cast<int>(&DAT_0126994c);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126997c;
// @fnv 0x00da0ac0
CpuOpaque* __cdecl FUN_00da0ac0()
{
    return &DAT_0126997c;
}

extern int DAT_012699ac;

// @fnv 0x00da0ae0
int* __cdecl FUN_00da0ae0(void)
{
    return &DAT_012699ac;
}

struct FUN_00da0af0_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00da0af0
// pdb: cleanupLoadedObjecthkpStiffSpringChainData | hkpDynamicsReflections.obj | tesv_win, objrun, medium
void __cdecl FUN_00da0af0(FUN_00da0af0_Class* param_1)
{
    param_1->vf00(0);
}

extern int DAT_01269a0c;

// @fnv 0x00da0b00
void* __cdecl FUN_00da0b00()
{
    return &DAT_01269a0c;
}

extern int DAT_010c6fd0;

// @fnv 0x00da0b20
void* __cdecl FUN_00da0b20()
{
    return &DAT_010c6fd0;
}

struct DB7570Pair
{
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};

enum DB7570Result
{
    DB7570_SUCCESS = 0,
    DB7570_FAILURE = 1
};

class DB7570Map
{
  public:
    int unk00;
    DB7570Pair* m_data;
    int m_iElementCount;

    DB7570Result Lookup(unsigned int key, unsigned int& valueOut) const;
};

// Searches m_data for an entry whose m_key equals key; on a match stores its value in valueOut and returns DB7570_SUCCESS, otherwise DB7570_FAILURE.
// @fnv 0x00db7570
// pdb: hkClassEnum::getNameOfValue | hkClassEnum.obj | fnv360_0822_retail, call_gap, high
// pdb params: val, name
DB7570Result DB7570Map::Lookup(unsigned int key, unsigned int& valueOut) const
{
    for (int i = 0; i < m_iElementCount; i++)
    {
        if (m_data[i].m_key == key)
        {
            valueOut = m_data[i].m_uiFilterValue;
            return DB7570_SUCCESS;
        }
    }
    return DB7570_FAILURE;
}

extern "C" int __cdecl hkString_strCasecmp(int a1, int a2);

struct FUN_00db75b0_entry
{
    int unk00;
    int unk04;
};

struct FUN_00db75b0_class
{
    int unk00;
    FUN_00db75b0_entry* unk04;
    int unk08;

    unsigned int __thiscall hkClassEnum_getValueOfName(int a1, unsigned int* a2);
};

// @fnv 0x00db75b0
// pdb: hkClassEnum::getValueOfName | hkClassEnum.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_gap), high
unsigned int __thiscall FUN_00db75b0_class::hkClassEnum_getValueOfName(int a1, unsigned int* a2)
{
    for (int index = 0; index < unk08; ++index)
    {
        unsigned int value = unk04[index].unk04;
        if (hkString_strCasecmp(a1, value) == 0)
        {
            unsigned int result = unk04[index].unk00;
            *a2 = result;
            return 0;
        }
    }
    return 1;
}

struct FUN_00db78a0_item
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};

class FUN_00db78a0_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c(void* field, void* item);
    void FUN_00db78a0(FUN_00db78a0_item** a, void** b);
};

// @fnv 0x00db78a0
// pdb: hkVtableClassRegistry::registerList | hkVtableClassRegistry.obj | tesv_win, call_seq, medium
void FUN_00db78a0_cls::FUN_00db78a0(FUN_00db78a0_item** apItems, void** apValues)
{
    FUN_00db78a0_item** p = apItems;
    if (*p == 0)
        return;
    do
    {
        void* item = *(void**)((char*)apValues + ((char*)p - (char*)apItems));
        if (item == 0)
            break;
        void* field = (*p)->m_0c;
        if (field != 0)
            this->vSlot0c(field, item);
        p++;
    } while (*p != 0);
}

struct hkMemoryAllocator;

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();

struct MapPair
{
    unsigned int key;
    unsigned int val;
};

struct HashEntryTable
{
    MapPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    unsigned int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    unsigned int getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }

    void FUN_00cb1870(hkMemoryAllocator& alloc, unsigned int key, unsigned int val);
};

namespace fnv_00db7960 {
extern "C" void* __cdecl FUN_00c85750();

}  // namespace fnv_00db7960

namespace fnv_00db7a20 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00[4];
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();

struct hkBool
{
    char m_cBooleanValue;
};
inline hkBool MakeBool(bool b)
{
    hkBool r;
    r.m_cBooleanValue = (char)b;
    return r;
}

class RefObj
{
  public:
    RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual ~RefObj();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        RefObj* b = (RefObj*)((AudioMgr*)FUN_00c85750())->heap().AllocateMemoryBlock(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void __cdecl operator delete(void* p);
};

struct Inner
{
    __declspec(nothrow) Inner(hkBool bFlag);
    int m_data[4];
};

class Thing : public RefObj
{
  public:
    Thing() : m_kInner(MakeBool(false))
    {
        m_iFadeIndex = 1;
    }
    virtual ~Thing();
    Inner m_kInner;
    int m_iFadeIndex;
};

}  // namespace fnv_00db7a20

namespace fnv_00dba3d0 {
struct DBA3D0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct DBA3D0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DBA3D0Allocator* m_pStreamAllocator;

    DBA3D0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DBA3D0MemoryRouter& __cdecl FUN_00c85750() throw();

template <class T> struct DBA3D0Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~DBA3D0Array() throw()
    {
        DBA3D0Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_iCapacityState = 0x80000000;
        m_data = 0;
    }
};

class DBA3D0MapBase
{
  public:
    ~DBA3D0MapBase() throw();

    void ClearAndRelease(DBA3D0Allocator& alloc) throw();

    int unk00;
    int unk04;
};

class DBA3D0Map : public DBA3D0MapBase
{
  public:
    ~DBA3D0Map() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
};

}  // namespace fnv_00dba3d0

struct hkMemoryAllocator
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C(void* field, void* item);
    virtual void free(void* p, unsigned int nbytes);
};

struct SweepBounds
{
    unsigned int minX, minY, minZ, key;
    unsigned int maxX, maxY, maxZ, reserved;
};
struct SweepPair
{
    unsigned int first, second;
};

inline SweepPair* emitPair(const SweepBounds& a, const SweepBounds& b, SweepPair* out, SweepPair* end, int& skipped)
{
    if (out < end)
    {
        out->first = a.key;
        out->second = b.key;
        ++out;
    }
    else
        ++skipped;
    return out;
}

struct DBA430Listener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vslot10(int a, int b);
};

struct BSAudio
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    DBA430Listener* m_10;
};

BSAudio* __cdecl FUN_00c85750();

extern void*(__stdcall* DAT_00fdf110)();

extern int DAT_010d4de4;

extern BSAudio* __cdecl FUN_00c85750();

void __cdecl hkAgent1nMachine_VisitAllAgents(int a, int b, void* pvCallback);
void __cdecl ProcessCollisionEntry();

// @fnv 0x00da4900
// pdb: hkAgentNmMachine_UpdateShapeCollectionFilter | hkpAgent1nMachine.obj | tesv_win, caller_sim, low
void __cdecl FUN_00da4900(int a, int b)
{
    hkAgent1nMachine_VisitAllAgents(a, b, reinterpret_cast<void*>(&ProcessCollisionEntry));
}

void* __cdecl hkAgent1nMachine_InvalidateTim(void*, void*);
// @fnv 0x00da6e10
// pdb: hkListAgent3::invalidateTim | hkpListAgent3.obj | fnv360_0822_retail, objrun, medium
// pdb params: entry, agentData, input
void* __cdecl FUN_00da6e10(void* apUnused, void* b, void* c)
{
    return hkAgent1nMachine_InvalidateTim(b, c);
}

extern int DAT_010cf7d4;
extern int DAT_010cf804;
extern char str_010cf830[];

struct Allocator
{
    virtual void Reserved();
    virtual void* Alloc(unsigned int bytes);
};

struct SubObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00d87790(int flags);
};

struct CreatedObject
{
    void* vtable;
    unsigned short allocatedSize;
    unsigned short enabled;
    const char* typeName;
    SubObject base;

    void Init()
    {
        union Flag
        {
            unsigned char byte;
            unsigned int word;
        } flag;

        allocatedSize = 0x20;
        enabled = 1;
        flag.byte = 0;
        unsigned int arg = flag.word;

        vtable = &DAT_010cf7d4;
        typeName = str_010cf830;
        base.FUN_00d87790(arg);
        vtable = &DAT_010cf804;
    }
};

struct FUN_00db7c00_obj
{
    virtual void vslot00(int value);
};

// @fnv 0x00db7c00
// pdb: cleanupLoadedObjecthkpConstraintChainInstance | hkpDynamicsReflections.obj | tesv_win, objopen_prop, low
void __cdecl FUN_00db7c00(FUN_00db7c00_obj* p)
{
    p->vslot00(0);
}

// 0x00db7c10  /MT /O2 /GS /EHsc /Gy   target: B8 28 9B 26 01 C3  (mov eax, offset DAT_01269b28; ret)
extern int DAT_01269b28;

// @fnv 0x00db7c10
// pdb: getVtablehkpTriangleShape | hkpCollideReflections.obj | tesv_win, objrun_open, low
int* FUN_00db7c10()
{
    return &DAT_01269b28;
}

typedef void(__cdecl* FuncDA34)();

struct FuncTableDA34
{
    FuncDA34 m_func0;
    FuncDA34 m_func1;
    FuncDA34 m_func2;
    FuncDA34 m_func3;
    FuncDA34 m_func4;
    FuncDA34 m_func5;
    FuncDA34 m_func6;
};

struct RegisterInfoDA34
{
    FuncTableDA34* m_table;
    int m_numFuncs;
    FuncDA34 m_funcA;
    FuncDA34 m_funcB;
};

class DispatcherDA34
{
  public:
    void SetEntry(int type, RegisterInfoDA34 info);
};

namespace fnv_00da3480 {

typedef void(__cdecl* AgentFuncDA34)();

struct AgentTableDA34
{
    AgentFuncDA34 m_apfnFuncs[8];
};

struct AgentInfoDA34
{
    AgentTableDA34* m_pkTable;
    int m_iNumFuncs;
    AgentFuncDA34 m_pfnCreate;
    AgentFuncDA34 m_pfnDestroy;
};

struct DispatcherDA34
{
    void SetEntry(int iType, AgentInfoDA34 kInfo);
};

}  // namespace fnv_00da3480

inline unsigned int mySeparatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}

template <bool swapPairs>
__forceinline SweepPair* collideOneT(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                     int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0 = mySeparatedYZ(*bounds, scan[0]);
        unsigned int d1 = mySeparatedYZ(*bounds, scan[1]);
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (swapPairs)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}

template <>
__forceinline SweepPair* collideOneT<false>(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out,
                                            SweepPair* end, int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0;
        unsigned int d1 = (d0 = mySeparatedYZ(*bounds, scan[0]), mySeparatedYZ(*bounds, scan[1]));
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (false)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}

// @fnv 0x00db09f0
// pdb: getNormalSignFromFeatureBitSet | hkpBoxBoxCollisionDetection.obj | tesv_win, objrun_open, low
static __declspec(noinline) float FUN_00db09f0(unsigned short arg)
{
    union
    {
        float f;
        unsigned int i;
    } u;
    u.f = 1.0f;
    u.i |= ((unsigned int)arg & 0xfffffff8u) << 28;
    return u.f;
}

unsigned short volatile g_in_db09f0;
float volatile g_out_db09f0;

void drive_db09f0(void)
{
    g_out_db09f0 = FUN_00db09f0(g_in_db09f0);
}

struct FUN_00db7c80_class
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int* FUN_00db7c80();
};

// @fnv 0x00db7c80
// pdb: NiMaterialResource::GetSemantic | NiMaterialResource.obj | fnv360_0822_retail, call_gap_sim, medium
int* FUN_00db7c80_class::FUN_00db7c80()
{
    return &m_0c;
}

#include <xmmintrin.h>

namespace sda3740 {

}

void __cdecl hkAgent1nMachine_Destroy(void* a, void* b, void* c, void* d);

// Calls hkAgent1nMachine_Destroy with arg2, arg5, arg3 and arg4; arg1 is unused.
// @fnv 0x00da6dc0
// pdb: hkListAgent3::destroy | hkpListAgent3.obj | tesv_win, caller_sim, low
void __cdecl FUN_00da6dc0(void* aUnused, void* arg2, void* arg3, void* arg4, void* arg5)
{
    hkAgent1nMachine_Destroy(arg2, arg5, arg3, arg4);
}

struct S06c0_Alloc
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* AllocateBufferWithSize(int& bytes);
    virtual void ReturnMemory(void* memory, int bytes);

    template <class T> __forceinline T* bufAllocT(int& num)
    {
        int bytes = num * (int)sizeof(T);
        T* p = static_cast<T*>(AllocateBufferWithSize(bytes));
        num = bytes / (int)sizeof(T);
        return p;
    }
};
struct S06c0_Mgr
{
    int unk00, unk04, unk08;
    S06c0_Alloc* unk0c;
    S06c0_Alloc& heap()
    {
        return *unk0c;
    }
};

namespace fnv_00db0e50 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);

volatile unsigned int g_out;
}  // namespace fnv_00db0e50

// Finds the index of the largest value among v[0], v[1], v[2], stores it in out, and returns a bitmask flag for the winning component.
// @fnv 0x00db0e80
volatile int g_a;
float* volatile g_v;
int* volatile g_o;

struct DBBCBC0Target
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

    int FUN_00dbbc00();
};

// @fnv 0x00dbbc00
// pdb: NavMesh::GetParentCell | NavMesh.obj | fnv360_0822_retail, call_seq, medium
int DBBCBC0Target::FUN_00dbbc00()
{
    return unk24;
}

namespace fnv_00da2840 {
extern void*(__stdcall* DAT_00fdf0b0)(const char*);
extern void*(__stdcall* DAT_00fdf0ac)(void*, const char*);
extern void(__stdcall* DAT_00fdf16c)(const char*);
extern HANDLE(__stdcall* DAT_00fdf110)(int, int);

typedef void(__stdcall* DA2840_OutputDebugString)(const char*);
typedef void*(__stdcall* DA2840_GetProcAddress)(void*, const char*);
typedef int(__stdcall* DA2840_SymInitialize)(HANDLE);
typedef int(__stdcall* DA2840_SymRefreshModuleList)(void);
typedef DWORD(__stdcall* DA2840_SymGetOptions)(void);
typedef DWORD(__stdcall* DA2840_SymSetOptions)(DWORD);
typedef void*(__stdcall* DA2840_SymGetSymFromAddr)(void*, void*, void*);
typedef int(__stdcall* DA2840_StackWalk64)(void*, void*, void*, void*, void*, void*, void*, void*);
typedef void*(__stdcall* DA2840_SymFunctionTableAccess64)(void*, void*, void*);
typedef void*(__stdcall* DA2840_SymGetModuleBase64)(void*, void*);
typedef int(__stdcall* DA2840_SymGetLineFromAddr64)(void*, void*, void*, void*);
typedef BOOL(__stdcall* DA2840_SymCleanup)(void*);

}  // namespace fnv_00da2840

struct S00da6eb0_Entry
{
    const char* m_pName;
    unsigned int m_uiEventId;
    unsigned int unk08;
};

struct S00da6eb0_Buf
{
    unsigned int unk00;
    S00da6eb0_Entry* m_pCur;
    unsigned int unk08;
    S00da6eb0_Entry* m_pRecordEnd;
};

struct S00da6eb0_Head
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct S00da6eb0_Sub
{
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_uiSize;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int m_uiHash[32];
};

struct S00da6eb0_List : S00da6eb0_Head, S00da6eb0_Sub
{
};

struct S00da6eb0_Router
{
    S00da6eb0_List* m_pEntries;
};

struct S00da6eb0_Ctx
{
    unsigned int unk00;
    S00da6eb0_Router* m_pRouter;
};

struct S00da6eb0_Alloc
{
    char* m_pCur;
};

extern unsigned long DAT_0126835c;
extern char str_010d50b8[];
extern char str_010c41f8[];

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

void __cdecl FUN_00da4aa0(void* a, void* b, S00da6eb0_Sub* c, unsigned int* d, void* e);

inline void S00da6eb0_TimerMark(const char* pName)
{
    S00da6eb0_Buf* pBuf = static_cast<S00da6eb0_Buf*>(TlsGetValue(DAT_0126835c));
    S00da6eb0_Entry* pCur = pBuf->m_pCur;

    if (pCur < pBuf->m_pRecordEnd)
    {
        pCur->m_pName = pName;
        _ReadWriteBarrier();
        volatile unsigned int t = __rdtsc();
        pCur->m_uiEventId = t;
        ++pCur;
        pBuf->m_pCur = pCur;
    }
}

inline void* S00da6eb0_ListData(S00da6eb0_List* pList)
{
    return &pList->unk10;
}

// Builds an index array from set bits in the router's hash table, passes it to FUN_00da4aa0, and returns an offset from a3.
// @fnv 0x00da6eb0
void* __cdecl BuildEventIndex(void* apCtx, void* apUnused, void* apOut, void* apUnused2, void* a5)
{
    S00da6eb0_TimerMark(str_010d50b8);

    S00da6eb0_List* pList = static_cast<S00da6eb0_Ctx*>(apCtx)->m_pRouter->m_pEntries;
    int iSize = pList->m_uiSize;

    S00da6eb0_Alloc* pAlloc = reinterpret_cast<S00da6eb0_Alloc*>(FUN_00c85750());
    unsigned int* pEventIndex = reinterpret_cast<unsigned int*>(pAlloc->m_pCur);

    pAlloc->m_pCur += (iSize * 4 + 0x83) & 0xffffff80;

    unsigned int iIndexCount = 0;
    unsigned int uiBitMask = 1;

    for (unsigned int i = 0; (int)i < iSize; ++i)
    {
        unsigned int uiBit = (i < 256) ? (pList->m_uiHash[i >> 5] & uiBitMask) : 1;

        if (uiBit)
            pEventIndex[iIndexCount++] = i;

        uiBitMask = _rotl(uiBitMask, 1);
    }

    pEventIndex[iIndexCount] = 0xffffffff;

    FUN_00da4aa0(apOut, apCtx, pList, pEventIndex, a5);

    S00da6eb0_TimerMark(str_010c41f8);

    reinterpret_cast<S00da6eb0_Alloc*>(FUN_00c85750())->m_pCur = reinterpret_cast<char*>(pEventIndex);

    return reinterpret_cast<char*>(apOut) + 0x10;
}

namespace CleanSimd {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float lane[4];
    unsigned int bits[4];
} __m128;
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    int _mm_movemask_ps(__m128);
}

extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern __m128 DAT_010c44d0;

struct Vector
{
    __m128 value;
    __forceinline void operator=(const Vector& v)
    {
        value = v.value;
    }
    __forceinline void negate(const Vector& a)
    {
        value = _mm_xor_ps(a.value, DAT_010c44d0);
    }
    __forceinline void sub(const Vector& a, const Vector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void cross(const Vector& a, const Vector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline __m128 dot(const Vector& a) const
    {
        __m128 sq = _mm_mul_ps(value, a.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 len = dot(*this);
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 rs = _mm_rsqrt_ss(len);
        __m128 refine = _mm_mul_ss(_mm_mul_ss(half, rs), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, rs), rs)));
        __m128 inv = _mm_andnot_ps(eq, refine);
        value = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), value);
    }
    __forceinline void addMul(const Vector& a, __m128 scale, const Vector& b)
    {
        value = _mm_add_ps(a.value, _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), b.value));
    }
};
struct Indices
{
    unsigned int flags;
    unsigned char b, c, d, a;
};
struct Output
{
    Vector origin, direction, normal;
};
// Builds out origin, direction and normal from four vertices at idx offsets in base, negating the normal if the fourth dot is negative; returns ~mask & 7.
// @fnv 0x00dad110
const Indices* volatile inputIndices;
const char* volatile inputBase;
Output* volatile inputOutput;
volatile int g_iFunctionResult;
}

namespace N {
extern "C" void _ReadWriteBarrier();
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    int _mm_movemask_ps(__m128);
}
extern const __m128 DAT_010c44d0;
class Scalar
{
    __m128 data;

  public:
    __forceinline Scalar(__m128 x) : data(x)
    {}
    __forceinline __m128 get() const
    {
        return data;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(data, data, 0);
    }
};
class Vec
{
    __m128 data;

  public:
    __forceinline operator __m128() const
    {
        return data;
    }
    __forceinline void operator=(const Vec& x)
    {
        data = x.data;
    }
    __forceinline void operator=(const __m128& x)
    {
        data = x;
    }
    __forceinline void difference(const Vec& a, const Vec& b)
    {
        data = _mm_sub_ps(a.data, b.data);
    }
    __forceinline void cross(const Vec& a, const Vec& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 201), _mm_shuffle_ps(b.data, b.data, 210));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 210), _mm_shuffle_ps(b.data, b.data, 201));
        data = _mm_sub_ps(p, q);
    }
    __forceinline Scalar squared() const
    {
        __m128 q = _mm_mul_ps(data, data);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(q, q, 85), q);
        return _mm_add_ss(_mm_shuffle_ps(q, q, 170), y);
    }
    __forceinline Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        __m128 len = squared().get();
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 square = _mm_mul_ss(_mm_mul_ss(len, approx), approx);
        __m128 refine = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, square));
        return _mm_andnot_ps(eq, refine);
    }
    __forceinline void normalize()
    {
        data = _mm_mul_ps(inverseLength().splat(), data);
    }
    __forceinline void negate(const Vec& v)
    {
        data = _mm_xor_ps(v.data, DAT_010c44d0);
    }
};
struct Desc
{
    unsigned char dimA, dimB;
    unsigned short id;
    unsigned char offsets[4];
};
struct Rows
{
    Vec vertices[16];
    Vec separating;
};
struct Out
{
    Vec point, delta, normal;
};
}
// @fnv 0x00dacf10
N::Rows* g_rows;
N::Desc* g_desc;
N::Out* g_output;
volatile int g_sink;

#include <xmmintrin.h>
namespace fnv_00db47a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);

struct S00db47a0_Obj
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;
    float unkA0;
};

struct SmallReal
{
    __m128 value;
    SmallReal(__m128 v) : value(v)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};
struct SmallVec
{
    __m128 value;
    void cross(const SmallVec& x, const SmallVec& y)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(x.value, x.value, 0xc9), _mm_shuffle_ps(y.value, y.value, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(x.value, x.value, 0xd2), _mm_shuffle_ps(y.value, y.value, 0xc9));
        value = _mm_sub_ps(p, q);
    }
    SmallReal dot(const SmallVec& y) const
    {
        __m128 p = _mm_mul_ps(value, y.value);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return SmallReal(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    }
    SmallReal length() const
    {
        return SmallReal(_mm_sqrt_ss(dot(*this).value));
    }
};
struct S00db47a0_Cls
{
    SmallVec a;
};

S00db47a0_Cls* volatile g_self;
S00db47a0_Obj* volatile g_o;
S00db47a0_Obj* volatile g_p;
const SmallVec* volatile g_q;
float* volatile g_out2;
float* volatile g_out1;
}  // namespace fnv_00db47a0

#include <xmmintrin.h>
namespace fnv_00db48a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

union __declspec(align(16)) SlabVec
{
    __m128 v;
    float f[4];
};
struct __declspec(align(16)) SlabObj
{
    __m128 v00;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    SlabVec v40;
    SlabVec v50;
};

struct __declspec(align(16)) VecHolder
{
    __m128 v00;
};

extern const __m128 DAT_010ec7f0;
extern const __m128 DAT_010c44d0;

struct SlabMath
{
    union
    {
        __m128 q;
        float lane[4];
    };
    SlabMath()
    {}
    SlabMath(__m128 v) : q(v)
    {}
    SlabMath(float v) : q(_mm_set_ps1(v))
    {}
    __forceinline void sub(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void add(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    __forceinline void mul(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    __forceinline void cross(const SlabMath& a, const SlabMath& b)
    {
        __m128 bc = _mm_shuffle_ps(b.q, b.q, 0xC9);
        __m128 ad = _mm_shuffle_ps(a.q, a.q, 0xD2);
        __m128 bd = _mm_shuffle_ps(b.q, b.q, 0xD2);
        __m128 ac = _mm_shuffle_ps(a.q, a.q, 0xC9);
        q = _mm_sub_ps(_mm_mul_ps(ad, bc), _mm_mul_ps(ac, bd));
    }
    __forceinline void interpolate(const SlabObj* a, const SlabMath& t)
    {
        q = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t.q), a->v40.v), _mm_mul_ps(a->v50.v, t.q));
    }
    __forceinline SlabMath operator-(const SlabMath& b) const
    {
        return SlabMath(_mm_sub_ps(q, b.q));
    }
    __forceinline SlabMath operator+(const SlabMath& b) const
    {
        return SlabMath(_mm_add_ps(q, b.q));
    }
    __forceinline SlabMath operator*(const SlabMath& b) const
    {
        return SlabMath(_mm_mul_ps(q, b.q));
    }
};
struct W_a
{
    const SlabObj* p;
    W_a(const SlabObj* v) : p(v)
    {}
};
struct W_b
{
    const VecHolder* p;
    W_b(const VecHolder* v) : p(v)
    {}
};
struct W_c
{
    const SlabObj* p;
    W_c(const SlabObj* v) : p(v)
    {}
};

const VecHolder* volatile in_v;
const VecHolder* volatile in_e;
const SlabObj* volatile in_q;
const SlabObj* volatile in_a;
const VecHolder* volatile in_b;
const SlabObj* volatile in_c;
float volatile in_d;
float volatile result;
}  // namespace fnv_00db48a0

extern int DAT_010d4de4;
