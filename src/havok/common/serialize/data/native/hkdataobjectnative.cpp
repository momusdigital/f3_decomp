#include "f3_common.h"
// src/havok/common/serialize/data/native/hkdataobjectnative.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/native/hkdataobjectnative.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

namespace fnv_00dbb4c0 {
struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};
}  // namespace fnv_00dbb4c0

struct FUN_00d873b0_t
{
    int a;
    int b;
    FUN_00d873b0_t(int x, int y);
};
// @fnv 0x00d873b0
// pdb: hkClassAccessor::hkClassAccessor | hkClassMemberAccessor.obj | tesv_win, call_seq, medium
FUN_00d873b0_t::FUN_00d873b0_t(int aiFirst, int aiSecond)
{
    a = aiFirst;
    b = aiSecond;
}

struct D481D0Class
{
    const char* __thiscall getName();
};

namespace fnv_00dbb940 {
struct D481D0Class
{
    char const* getName() const;
};

struct FUN_00d46d50_s
{
    D481D0Class* FUN_00d46d50();
};

struct FUN_00dbb940_VirtualClass
{
    virtual void FUN_00dbb940_0() = 0;
    virtual void FUN_00dbb940_1() = 0;
    virtual void FUN_00dbb940_2() = 0;
    virtual void FUN_00dbb940_3() = 0;
    virtual void FUN_00dbb940_4() = 0;
    virtual void FUN_00dbb940_5() = 0;
    virtual void FUN_00dbb940_6() = 0;
    virtual void FUN_00dbb940_7() = 0;
    virtual void FUN_00dbb940_8() = 0;
    virtual int FUN_00dbb940_9(char const* name) = 0;
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46d50_s* m_0C;
    FUN_00dbb940_VirtualClass* m_10;

    int __thiscall FUN_00dbb940();
};

}  // namespace fnv_00dbb940

namespace fnv_00dbba80 {
struct D481D0Class
{
    char const* getName() const;
};

}  // namespace fnv_00dbba80

namespace fnv_00dbbc20 {
struct D481D0Class
{
    virtual int FUN_00dbbc20_1();
    virtual int FUN_00dbbc20_2();
    virtual int FUN_00dbbc20_3();
    virtual int FUN_00dbbc20_4();
    virtual int FUN_00dbbc20_5();
    virtual int FUN_00dbbc20_6();
    virtual int FUN_00dbbc20_7();
    virtual int FUN_00dbbc20_8();
    virtual int FUN_00dbbc20_9();
    virtual int FUN_00dbbc20_10(char const* name);

    char const* getName() const;
};

}  // namespace fnv_00dbbc20

struct FUN_00d46f20_Class
{
    int __thiscall FUN_00d46f20(int a, int b);
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46f20_Class* m_0c;

    void SetInvocationResult(int result);
    void InvokeMemberFunction(int a, int b);
};

struct FUN_00dbc640_class;

struct FUN_00dbc640_allocator
{
// @fnv 0x00dbc640
    virtual void FUN_00dbc640_0()
    {}
    virtual void FUN_00dbc640_1()
    {}
    virtual void __thiscall FUN_00dbc640_2(FUN_00dbc640_class* p, unsigned short size);
};

struct FUN_00dbc640_router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0C;
    FUN_00dbc640_allocator* m_10;
};

FUN_00dbc640_router* _D1A0E0GetMemoryRouter();

struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void __thiscall FUN_00dbb3f0();

    FUN_00dbc640_class* __thiscall FUN_00dbc640(int flags);
};

// @fnv 0x00dbb130
// pdb: hkpConstraintChainInstanceAction::clone | hkpConstraintChainInstanceAction.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int __stdcall hkpConstraintChainInstanceAction_clone(int a, int b)
{
    return 0;
}

class hkMemoryAllocatorDBB5
{
  public:
    virtual ~hkMemoryAllocatorDBB5() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBB5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB5* m_pStreamAllocator;

    hkMemoryAllocatorDBB5& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDBB5 {
extern "C" hkMemoryRouterDBB5& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB5
{
  public:
    virtual ~hkRefObjDBB5() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB5() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB5* b = static_cast<hkRefObjDBB5*>(hkRouterDBB5::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkStringDBB5
{
  public:
    void FUN_00d873b0(const char* name, int len) throw();
    int unk00;
    int unk04;
};

class hkStringFnDBB5
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

struct hkNameDescDBB5
{
    const char* m_name;
    int m_len;
};

class hkLibDBB5;

class hkResourceDBB5 : public hkRefObjDBB5
{
  public:
    int m_08;

    hkResourceDBB5() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB5() throw();
};

class hkNodeDBB5 : public hkResourceDBB5
{
  public:
    hkStringDBB5 m_name;
    hkLibDBB5* m_pOwnerObject;

    hkNodeDBB5() throw()
    {}
    virtual ~hkNodeDBB5() throw();
};

class hkNodeRefDBB5
{
  public:
    void FUN_00dba760(hkNodeDBB5* node) throw();
    hkNodeDBB5* m_node;
};

class hkLibDBB5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB5* m_pStringFunctions;

    hkNodeRefDBB5 CreateNode(const hkNameDescDBB5& desc);
};

struct hkErrorDBB7
{
    virtual ~hkErrorDBB7();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorDBB7* DAT_01268360;

struct hkOstreamDBB7
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamDBB7& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamDBB7& FUN_00cc0120(const void* pvPointer) throw();
};

struct hkBoolDBB7
{
    char m_bValue;
    hkBoolDBB7() throw()
    {}
};

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};

struct hkClassDBB7 : FUN_00d46d40_s
{
    hkBoolDBB7 GetLastNodeFlag() const throw();
};

class hkVtableClassRegistryDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual hkClassDBB7* GetClassFromVirtualInstance(void* pvObject) throw();
};

class hkDataWorldNativeDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

class hkDataObjectNativeDBB7
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    hkDataWorldNativeDBB7* m_pkWorld;
    hkVtableClassRegistryDBB7* m_pkVtableRegistry;
    int m_aiUnk10[4];
    void* m_pvObject;
    void* m_pkClass;

    hkDataWorldNativeDBB7* getWorld() const
    {
        return m_pkWorld;
    }
    void SetContents(void* pvObject, hkClassDBB7& kClass);
};

struct hkBoolDBB9
{
    char m_cBooleanValue;
    hkBoolDBB9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkHalf
{
  public:
    short m_uiFilterValue;
    hkHalf()
    {}
    hkHalf(float f)
    {
        int t = *(int*)&f;
        m_uiFilterValue = (short)(t >> 16);
    }
};

class hkOwnerDBBB;

struct hkRefDBBB
{
    hkOwnerDBBB* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDBBB(hkOwnerDBBB* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};

class hkOwnerDBBB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void* pValue);
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8(int iKey);

    hkRefDBBB MakeRef(int iKey);
    void MakeRef(void* pValue);
};

// Constructs and returns an hkRefDBBB holding this owner and the value from V8(iKey).
// @f3 0x004227a0 (community match, verified in this file)
namespace mr_004227a0 {
struct Fields
{
    void* vtable;
    int unk04;
    int unk08;
    char unk0C;
    char pad0D;
    short unk0E;
};
}

// pdb: MapMarkerData::Copy | MapMarkerData.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: apCopy
void hkOwnerDBBB::MakeRef(void* pValue)
{
    V2(pValue);
    mr_004227a0::Fields* self = (mr_004227a0::Fields*)this;
    const mr_004227a0::Fields* src = (const mr_004227a0::Fields*)pValue;
    self->unk0C = src->unk0C;
    self->unk0E = src->unk0E;
}


class hkMemoryAllocatorDBBD
{
  public:
    virtual ~hkMemoryAllocatorDBBD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBBD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDBBD* m_pStreamAllocator;
    hkMemoryAllocatorDBBD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDBBD& __cdecl FUN_00c85750();

class FUN_00dbbb90
{
  public:
    virtual ~FUN_00dbbb90() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void* operator new(unsigned int nbytes)
    {
        FUN_00dbbb90* b = static_cast<FUN_00dbbb90*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00dbbb90(int iWorld, void* pvData, int iSize, int iStride, int iType, int m_iMenuId, int iTupleCount) throw();

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

namespace fnv_00dbbe50 {
class hkBaseDBBE
{
  public:
    virtual ~hkBaseDBBE() throw()
    {}
};

class hkMemoryAllocatorXdbbe50
{
  public:
    virtual ~hkMemoryAllocatorXdbbe50() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXdbbe50
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXdbbe50* m_pStreamAllocator;

    hkMemoryAllocatorXdbbe50& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXdbbe50& __cdecl FUN_00c85750() throw();

class hkObjdbbe50 : public hkBaseDBBE
{
  public:
    hkObjdbbe50* FUN_00dbbe50(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjdbbe50*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

}  // namespace fnv_00dbbe50

namespace fnv_00dbbe80 {
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};

struct hkClassMemberDBBE
{
    const char* m_name;
    int m_class;
    int m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    bool flagsAllAreSet(unsigned short usMask) const
    {
        return (m_flags & usMask) == usMask;
    }
    int FUN_00d86940() const throw();
    FUN_00d46d40_s* FUN_00d86920() const throw();
    void* FUN_00d86960(const char* pcName) const throw();
};

struct FUN_00d871a0
{
    void* m_object;
    const void* m_pObjectTypeInfo;
    FUN_00d871a0(void* pvObject, const char* pcMember) throw();
    const char** FUN_00d87220(int iIndex) throw();
};

int __cdecl GetShapeTypeFlags(int iType, int iSubType, FUN_00d46d40_s* pkClass, int iCount) throw();

}  // namespace fnv_00dbbe80

enum hkTypeDBC3
{
    TYPE_POINTER = 0x1d,
    TYPE_FLAGS = 0x21
};

struct hkClassMemberDBC3
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    hkTypeDBC3 getType() const
    {
        return (hkTypeDBC3)m_type;
    }
};

class hkVariantDBC3
{
  public:
    int unk00;
    int unk04;

    hkVariantDBC3(void* obj, void* name) throw()
    {
        FUN_00d871a0(obj, name);
    }
    void FUN_00d871a0(void* obj, void* name) throw();
    hkClassMemberDBC3* FUN_00d87370() throw();
    unsigned int* FUN_00d87220(int i) throw();
    unsigned int* FUN_00d87230(int i) throw();
};

namespace fnv_00dbc370 {
class hkClassMemberDBC3
{
  public:
    enum Type
    {
        TYPE_VOID,
        TYPE_BOOL,
        TYPE_CHAR,
        TYPE_INT8,
        TYPE_UINT8,
        TYPE_INT16,
        TYPE_UINT16,
        TYPE_INT32,
        TYPE_UINT32,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_REAL,
        TYPE_VECTOR4,
        TYPE_QUATERNION,
        TYPE_MATRIX3,
        TYPE_ROTATION,
        TYPE_QSTRANSFORM,
        TYPE_MATRIX4,
        TYPE_TRANSFORM,
        TYPE_ZERO,
        TYPE_POINTER,
        TYPE_FUNCTIONPOINTER,
        TYPE_ARRAY,
        TYPE_INPLACEARRAY,
        TYPE_ENUM,
        TYPE_STRUCT,
        TYPE_SIMPLEARRAY,
        TYPE_HOMOGENEOUSARRAY,
        TYPE_VARIANT,
        TYPE_CSTRING,
        TYPE_ULONG,
        TYPE_FLAGS
    };
    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;

    Type getType() const
    {
        return (Type)m_type;
    }
    Type getSubType() const
    {
        return (Type)m_eSubtype;
    }
};

struct hkVariantDBC3
{
    void* m_object;
    const void* m_class;
};

class hkClassMemberAccessorDBC3
{
  public:
    void* m_pTargetObject;
    const hkClassMemberDBC3* m_kMemberDescriptor;

    void FUN_00d871a0(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember) throw();
    hkClassMemberAccessorDBC3(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember)
    {
        FUN_00d871a0(kObject, pkMember);
    }

    const hkClassMemberDBC3& FUN_00d87370() const throw();
    signed char& FUN_00d872e0(int iIndex) throw();
    unsigned char& FUN_00d872f0(int iIndex) throw();
    short& FUN_00d872c0(int iIndex) throw();
    unsigned short& FUN_00d872d0(int iIndex) throw();
    int& FUN_00d87270(int iIndex) throw();
    unsigned int& FUN_00d87280(int iIndex) throw();
    __int64& FUN_00d87290(int iIndex) throw();
    unsigned __int64& FUN_00d872a0(int iIndex) throw();
    unsigned long& FUN_00d872b0(int iIndex) throw();
};

}  // namespace fnv_00dbc370

struct FUN_00c85750_Result
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    class FUN_00dba490_heap* m_10;
};

class FUN_00dba490_heap
{
  public:
    virtual void h_slot0();
    virtual void h_slot1();
    virtual void h_slot2();
    virtual void h_slot3();
    virtual void h_freeBlock(int param, int size);
};

class hkMemoryAllocatorDBB6
{
  public:
    virtual ~hkMemoryAllocatorDBB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBB6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB6* m_pStreamAllocator;

    hkMemoryAllocatorDBB6& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDBB6 {
extern "C" hkMemoryRouterDBB6& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB6
{
  public:
    virtual ~hkRefObjDBB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB6() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB6* b = static_cast<hkRefObjDBB6*>(hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkStringDBB6
{
  public:
    void FUN_00d873d0(const hkStringDBB6& other) throw();
    int unk00;
    int unk04;
};

class hkStringFnDBB6
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

class hkLibDBB6;

class hkResourceDBB6 : public hkRefObjDBB6
{
  public:
    int m_08;

    hkResourceDBB6() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB6() throw();
};

class hkNodeDBB6 : public hkResourceDBB6
{
  public:
    hkStringDBB6 m_name;
    hkLibDBB6* m_pOwnerObject;

    hkNodeDBB6() throw()
    {}
    virtual ~hkNodeDBB6() throw();
};

class hkNodeRefDBB6
{
  public:
    void FUN_00dba760(hkNodeDBB6* node) throw();
    hkNodeDBB6* m_node;
};

class hkLibDBB6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB6* m_pStringFunctions;

    int unk10[4];
    hkStringDBB6 m_name;

    hkNodeRefDBB6 FUN_00dbb620();
};

// Returns 0.0f.
// @fnv 0x00dbba10
// pdb: ActorValueOwner::GetBaseActorValue | TESCreature.obj | fnv360_0721_beta, objrun_open, low
// pdb params: aiWhich
float __stdcall FUN_00dbba10(void* pArg)
{
    return 0.0f;
}

struct FUN_00d871a0
{
    int m_00;
    int m_04;
    FUN_00d871a0(void* pair, int x);
    void* FUN_00d87200();
};

struct StreamDBC5C0;
struct StreamDBC5C0
{
    int unk00;
};

extern "C" int __cdecl hkString_snprintf(char* pcBuffer, unsigned int uSize, const char* pcFormat, ...);
extern const char str_010a5824[];
extern "C" int __cdecl hkString_strLen(const char* s);
struct WriterC12
{
    virtual void write(const char* s, int len) throw();
};
static __declspec(noinline) void FUN_00cc0080(WriterC12* pkWriter, const char* pcString)
{
    if (pcString == 0)
        pkWriter->write("(null)", 6);
    else
        pkWriter->write(pcString, hkString_strLen(pcString));
}
// @fnv 0x00cc0120
// pdb: hkOstream::operator<< | hkOStream.obj | fnv360_0822_retail, call_dedup, low
// pdb params: p
hkOstreamDBB7& hkOstreamDBB7::FUN_00cc0120(const void* pvPointer) throw()
{
    int buffer[2506];
    hkString_snprintf((char*)buffer, 0x2728u, str_010a5824, pvPointer);
    FUN_00cc0080((WriterC12*)m_uiLogicalSize, (const char*)buffer);
    return *this;
}

namespace dbb {
}

typedef void(__cdecl* Callback680)(void*, int);
extern const char DAT_010d64bc[], DAT_010d64d0[], DAT_010d64dc[], DAT_010d6394[];

struct RawDispatch680;
typedef void*(__thiscall* DispatchFn680)(RawDispatch680*, void*);
struct DispatchTable680
{
    DispatchFn680 q0, q1, q2, RunFourthVirtual, v4, q5, RunSeventhVirtualOperation, v7;
};
struct RawDispatch680
{
    DispatchTable680* table;
};

void __cdecl ResizeAudioStream(void* allocator, void* array, int elemSize) throw();

struct Allocator_s
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void free(void* p, int nbytes) throw();
};

template <typename T> __forceinline void constructWithCopyRange(T* p, int n, const T& t) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~hkArray() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }

    void AddBack(const T& item) throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(router->m_10, this, sizeof(T));
        }
        constructWithCopyRange(m_data + m_iElementCount, 1, item);
        m_iElementCount++;
    }
};

// local members list (same layout/semantics as hkArray, used for the loop scan)
template <typename T> struct MemberArrLcl
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    MemberArrLcl() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~MemberArrLcl() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
};

struct S00dbc150_ClassDef
{
    int FUN_00d470d0();
};

struct S00dbc150_Member
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_carraySize;

    S00dbc150_ClassDef* FUN_00d86920();
    int FUN_00d86940();
};

struct S00dbc150_Pair
{
    void* m_data;
    S00dbc150_Member* m_kMemberDescriptor;

    S00dbc150_Pair(void* obj, const char* name)
    {
        FUN_00d871a0(obj, name);
    }
    void FUN_00d871a0(void* obj, const char* name);
    void* FUN_00d87200();
    S00dbc150_Member* FUN_00d87370();
};

int __cdecl GetShapeTypeFlags(int a, int b, int c, int d);
extern int DAT_010d642c[];

struct S00dbbb90_Obj
{
    int* m_00;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    S00dbbb90_Obj* FUN_00dbbb90(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Initializes S00dbbb90_Obj fields from a1-a7, sets m_00 to DAT_010d642c, and computes m_24 from GetShapeTypeFlags.
// @fnv 0x00dbbb90
S00dbbb90_Obj* S00dbbb90_Obj::FUN_00dbbb90(int ai0c, int ai10, int ai14, int ai18, int ai1c, int ai20, int ai28)
{
    m_06 = 0;
    m_08 = 0;
    m_0c = ai0c;
    m_10 = ai10;
    m_14 = ai14;
    m_18 = ai18;
    m_00 = DAT_010d642c;
    m_1c = ai1c;
    m_20 = ai20;
    m_28 = ai28;
    int r = GetShapeTypeFlags(0x16, ai1c, ai20, ai28);
    m_24 = (r > 0x10) ? (r - 0x10) : 0x10;
    return this;
}

hkClassDBB7* volatile inputClass;
hkVtableClassRegistryDBB7* volatile inputRegistry;
hkDataWorldNativeDBB7* volatile inputWorld;
void* volatile inputObject;
void* volatile outputObject;
void* volatile outputClass;
extern hkErrorDBB7* DAT_01268360;

namespace fnv_00dbb520 {
struct Allocator
{
    virtual void a();
    virtual void* allocate(unsigned int);
};
struct Router
{
    int a, b, c, d;
    Allocator* allocator;
};
Router* __cdecl FUN_00c85750();
}  // namespace fnv_00dbb520

struct NativeMemberReferenceDBBA
{
    int object;
    int name;

    NativeMemberReferenceDBBA(int owner, int memberName) : object(owner), name(memberName)
    {}
};
