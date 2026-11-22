#include "f3_common.h"
// src/havok/common/serialize/data/hkdataobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/hkdataobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

namespace fnv_00dba6c0 {
struct Inner
{
    virtual void v0();
    virtual void v1();
};

}  // namespace fnv_00dba6c0

struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void invoke();
};
struct Wrapper
{
    Target* target;
    void FUN_00dba6f0();
};

struct Interface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};

struct FUN_00dba750
{
    void* m_pObject;

    FUN_00dba750();
};

// @fnv 0x00dba750
// pdb: hkpPrimitiveDrawer::hkpPrimitiveDrawer | hkpPrimitiveDrawer.obj | fnv360_0822_retail, call_seq, medium
FUN_00dba750::FUN_00dba750()
{
    m_pObject = 0;
}

namespace fnv_00dba920 {
struct Target
{
    void* object;
    int value;
    int QueryAndWriteResult();
};
}  // namespace fnv_00dba920

namespace fnv_00dba9a0 {
struct Interface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void* first, unsigned int second);
};
}  // namespace fnv_00dba9a0

namespace fnv_00dbaa00 {
struct Delegate
{
    virtual void slot00(void*) = 0;
    virtual void slot01(void*) = 0;
    virtual void slot02(void*) = 0;
    virtual void slot03(void*) = 0;
    virtual void slot04(void*) = 0;
    virtual void slot05(void*) = 0;
    virtual void slot06(void*) = 0;
    virtual void slot07(void*) = 0;
    virtual void slot08(void*) = 0;
    virtual void slot09(void*) = 0;
    virtual void slot10(void*) = 0;
    virtual void slot11(void*) = 0;
    virtual void slot12(void*) = 0;
    virtual void slot13(void*) = 0;
    virtual void slot14(void*) = 0;
    virtual void Target(void*) = 0;
};
struct Wrapper
{
    Delegate* delegate;
    void* value;
    void FUN_00dbaa00();
};
}  // namespace fnv_00dbaa00

struct Inner2
{
    virtual void v0();
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
    virtual void v16(int a, __int64 b);
};

struct FUN_00dbaaf0_cls
{
    Inner2* m_p;
    int m_iWordAt04;
    void DispatchToInner(unsigned char b, void* p);
};

// @f3 0x00550350 (community match, verified in this file)
struct Disp101
{
    virtual void v0();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void invoke(int a, int b);
};

// pdb: TESActorBase::SetActorValue | TESCreature.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiWhich, afValue
void FUN_00dbaaf0_cls::DispatchToInner(unsigned char b, void* p)
{
    ((Disp101*)this)->invoke(*(int*)&b, (int)*(float*)&p);
}


struct AudioInterface
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Apply(void*, unsigned int, unsigned int);
};
struct AudioHandle
{
    AudioInterface* system;
    void* object;
    void FUN_00dbab10(unsigned int, unsigned int);
};

struct ResultPair
{
    void* m_pFirst;
    void* m_pSecond;

    ResultPair(void* apFirst, void* apSecond) : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};

namespace fnv_00dbac00 {
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void Invoke();
};
struct Wrapper
{
    Target* target;
    void FUN_00dbac00();
};
}  // namespace fnv_00dbac00

namespace fnv_00dbac80 {
struct Target
{
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14();
    virtual void method18();
    virtual void method1c();
    virtual void method20();
    virtual void method24();
    virtual void method28();
    virtual void method2c();
    virtual void apply(void* value);
};
struct Wrapper
{
    Target* target;
    void* value;
    void hkOffsetOnlyStreamWriter_seek();
};
}  // namespace fnv_00dbac80

namespace fnv_00dbad20 {
struct AudioInterface
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Apply(void*, float);
};
struct AudioHandle
{
    AudioInterface* system;
    void* object;
    void FUN_00dbad20(float);
};
}  // namespace fnv_00dbad20

namespace fnv_00dbad40 {
struct Delegate
{
    virtual void slot00(void*, void*) = 0;
    virtual void slot01(void*, void*) = 0;
    virtual void slot02(void*, void*) = 0;
    virtual void slot03(void*, void*) = 0;
    virtual void slot04(void*, void*) = 0;
    virtual void slot05(void*, void*) = 0;
    virtual void slot06(void*, void*) = 0;
    virtual void slot07(void*, void*) = 0;
    virtual void slot08(void*, void*) = 0;
    virtual void slot09(void*, void*) = 0;
    virtual void slot10(void*, void*) = 0;
    virtual void slot11(void*, void*) = 0;
    virtual void slot12(void*, void*) = 0;
    virtual void slot13(void*, void*) = 0;
    virtual void slot14(void*, void*) = 0;
    virtual void Target(void*, void*) = 0;
};
struct Wrapper
{
    Delegate* delegate;
    void* value;
    void FUN_00dbad40(void*);
};
}  // namespace fnv_00dbad40

namespace fnv_00dbada0 {
struct Interface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void Invoke(void* value, int argument);
};
struct Wrapper
{
    Interface* interfaceObject;
    void* value;
    void InvokeOnInterface(int argument);
};
}  // namespace fnv_00dbada0

namespace fnv_00dbae10 {
struct Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual int v80(int a);
};

}  // namespace fnv_00dbae10

extern char __stdcall Equals(void*);
// @fnv 0x00dbaf90
bool __stdcall FUN_00dbaf90(void* param_1)
{
    char result = Equals(param_1);
    return result == 0;
}

struct FUN_00dba650_cls
{
    unsigned int m_00;
    FUN_00dba650_cls* FUN_00dba650(unsigned int value);
};

// @fnv 0x00dba650
FUN_00dba650_cls* FUN_00dba650_cls::FUN_00dba650(unsigned int value)
{
    this->m_00 = value;
    return this;
}

struct CpuObject
{
    int value;
    bool FUN_00dba670();
};

struct RefCountedObj
{
    virtual ~RefCountedObj()
    {}
    unsigned short unk04;
    short m_refFlags;
    int m_iObjectReferenceCount;
};

struct DBA7F0Object
{
    virtual ~DBA7F0Object();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_iReferenceCount;
};

struct DBA7F0Ref
{
    DBA7F0Object* m_pRetainedObject;

    void FUN_00dba7f0();
};

// @f3 0x008e9140 (community match, verified in this file)
__forceinline short& RefCount929(DBA7F0Object* object) { return object->m_sReferenceCount; }

extern DBA7F0Object* DAT_010f2e7c;

__forceinline void Release929(DBA7F0Object* object) {
    if (object->m_usMemSizeAndFlags) {
        RefCount929(object) -= 1;
        if (RefCount929(object) == 0)
            delete object;
    }
}

// pdb: bhkCharacterControllerCinfo::ReleaseDefaultManager | bhkCharacterController.obj | fnv360_0822_retail, call_gap_sim, low
void DBA7F0Ref::FUN_00dba7f0() {
    if (DAT_010f2e7c) {
        Release929(DAT_010f2e7c);
    }
}


struct FUN_00dbaa30_target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40(void* p, __int64 a);
};

struct FUN_00dbaa30_cls
{
    FUN_00dbaa30_target* m_00;
    void* m_04;
    void __thiscall FUN_00dbaa30(int a1, void* a2);
};

// @f3 0x006e0620 (community match, verified in this file)
struct Heap936 { void* FUN_0086b930(unsigned int size); };
extern Heap936 DAT_01090a78;
struct Stream936 { void FUN_006cde00(void* output, unsigned int size); };
struct Buffer936 {
    FUN_00dbaa30_target* target;
    void* data;
    unsigned int size;
};
// pdb: BGSLoadGameBuffer::Load | BGSLoadGameBuffer.obj | fnv360_0822_retail, objrun, low
// pdb params: apFile, aiSize
void __thiscall FUN_00dbaa30_cls::FUN_00dbaa30(int source, void* size) {
    Buffer936* buffer = (Buffer936*)this;
    buffer->size = (unsigned int)size;
    buffer->data = DAT_01090a78.FUN_0086b930(buffer->size);
    ((Stream936*)source)->FUN_006cde00(buffer->data, buffer->size);
}


struct SpawnedPair
{
    void* first;
    void* second;
};

namespace fnv_00dbac10 {
struct CpuInterface
{
    virtual void slot00();
    virtual void Invoke();
};
struct CpuObject
{
    CpuInterface* target;
    void FUN_00dbac10();
};
}  // namespace fnv_00dbac10

namespace fnv_00dbaf50 {
struct SpawnedPair
{
    int unk00;
    int unk04;
};

struct FUN_00dbaf50_cls
{
    void Fill(SpawnedPair* apOut);
    bool Equals(FUN_00dbaf50_cls* apOther);
};

// Fills two SpawnedPair values via Fill and returns whether both of their fields are equal.
// @fnv 0x00dbaf50
bool FUN_00dbaf50_cls::Equals(FUN_00dbaf50_cls* apOther)
{
    SpawnedPair aLeft;
    SpawnedPair aRight;
    this->Fill(&aLeft);
    apOther->Fill(&aRight);
    return aLeft.unk00 == aRight.unk00 && aLeft.unk04 == aRight.unk04;
}
}  // namespace fnv_00dbaf50

struct S_Alloc
{
    int unk0;
};
struct S_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_Alloc* m10;
    S_Alloc& heap()
    {
        return *m10;
    }
};
S_Router* FUN_00c85750();
void FUN_00c908c0(S_Alloc& a, void* arr, int n, int esz);

struct S_Obj
{
    virtual void v0();
    virtual void v1();
    virtual int v2();
};

struct S_Item
{
    int m0;
    int m4;
    int m8;
    S_Obj* mc;
    int m10;
    S_Item()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
        mc = 0;
        m10 = 0;
    }
};

struct S_Elem
{
    int m0;
    int m4;
    int m8;
    int mc;
};
static inline void SetElem(S_Elem* e, const S_Item& it, int r)
{
    e->m0 = it.m0;
    e->m4 = it.m8;
    e->m8 = it.m10;
    e->mc = r;
}

struct S_Arr
{
    S_Elem* data;
    int size;
    int cap;
    void reserve(S_Alloc& a, int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            int c2 = c + c;
            FUN_00c908c0(a, this, (n < c2) ? c2 : n, 16);
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750()->heap(), n);
        size = n;
    }
};

struct Fnv299VTarget
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20(int arg);
};
typedef void(__thiscall* Fnv299Dispatch)(Fnv299VTarget*, int);

struct DB8000_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DB8000_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DB8000_Alloc* m10;
    DB8000_Alloc& heap()
    {
        return *m10;
    }
};

struct DB8000_Handle
{
    unsigned int m_00;
    DB8000_Handle* FUN_00dba650(unsigned int value);
    void FUN_00dba660();
};

struct DB8000_Ref
{
    void* m_pRetainedObject;
    void FUN_00dba760(void* p);
    void FUN_00dba7f0();
};

struct DB8000_PtrArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }

    void ClearAndRelease()
    {
        DB8000_Alloc& alloc = ((DB8000_Router*)FUN_00c85750())->heap();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct DB8000_Out
{
    const char* m_name;
    int m_unk04;
    int m_unk08;
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init(const char* name, int unk04)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
        m_name = name;
        m_unk04 = unk04;
        m_unk08 = 0;
    }

    void ClearAndRelease()
    {
        DB8000_Alloc& alloc = ((DB8000_Router*)FUN_00c85750())->heap();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * 16);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

typedef void(__cdecl* DB8000_Callback)(DB8000_Ref*);

struct DB8000_OpData
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct DB8000_Op
{
    int m_type;
    DB8000_OpData* m_data;
};

struct DB8000_Item
{
    const char* m_name0;
    const char* m_name1;
    int m_unk08;
    int m_unk0c;
    DB8000_Op* m_pOperations;
    int m_numOps;
};

struct DB8000_ItemArray
{
    DB8000_Item** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct DB8000_Self
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfn3(DB8000_Out* out);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int vfn9(const char* name);

    void FUN_00dc7320(DB8000_Handle* h, const char* name);
    void FUN_00dc73f0(DB8000_Handle* h, int a, int b);
    void FUN_00dc7d20(DB8000_Handle* h, int a, int b, int c, int d);
    void FUN_00dc7600(DB8000_Handle* h, int a);
    void InitAndRun(const char* name, DB8000_PtrArray* out);
    void AssignRefCountedSlot(DB8000_Handle* h1, DB8000_Handle* h2);
    void CallWithReset(const char* name, DB8000_PtrArray* out);
    void FUN_00dc7dc0(DB8000_Ref* ref, DB8000_Handle* h);
    void ReleaseRef(DB8000_Handle* h);
    void FUN_00dc72e0(DB8000_Handle* h, int a);
};

volatile DB8000_Self* g_db8000_self;
volatile DB8000_ItemArray* g_db8000_items;
volatile int g_db8000_ret;

struct MemberValueHandle;

struct MemberValueTarget
{
    virtual void Reserved00();
    virtual void Reserved04();
    virtual void Reserved08();
    virtual void Reserved0c();
    virtual void Reserved10();
    virtual void Reserved14();
    virtual void Reserved18();
    virtual void Reserved1c();
    virtual void Reserved20();
    virtual void Reserved24();
    virtual void Reserved28();
    virtual void Reserved2c();
    virtual void Reserved30();
    virtual void Reserved34();
    virtual void Reserved38();
    virtual void Reserved3c();
    virtual void Reserved40();
    virtual void Reserved44();
    virtual void Reserved48();
    virtual void Reserved4c();
    virtual void Reserved50();
    virtual void Reserved54();
    virtual void Reserved58();
    virtual void Assign(const char* name, const MemberValueHandle& value);
};

struct MemberValueHandle
{
    MemberValueTarget* implementation;
    const char* name;

    void FUN_00dbaa10(const MemberValueHandle& value);
};

struct ArrayBulkTarget;
typedef void(__fastcall* ArrayBulkSlot)(ArrayBulkTarget*, int);
struct ArrayBulkTarget
{
    ArrayBulkSlot* vtbl;
};

struct DataClassResult : FUN_00dba650_cls
{
    DataClassResult* FUN_00dba650(unsigned int value);
    DataClassResult(unsigned int value)
    {
        FUN_00dba650(value);
    }
};

__declspec(noinline) DataClassResult* DataClassResult::FUN_00dba650(unsigned int value)
{
    m_00 = value;
    return this;
}
