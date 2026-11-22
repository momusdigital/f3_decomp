#include "f3_common.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiObject;
struct NiStream
{
    NiObject* GetLoadedObject();
    unsigned int GetLinkID();
};
struct bhkRigidBody
{
    void FUN_00c859e0(NiStream*);
    void FUN_00c8ef80(NiObject*);
    void FUN_00c8f3c0(NiStream*);
};
// Calls FUN_00c859e0, reads a count from the stream, then reads that many NiObjects and passes each non-null one to FUN_00c8ef80.
// @fnv 0x00c8f3c0
// pdb: bhkRigidBody::LinkObject | bhkRigidBody.obj | fnv360_0822_debug, objrun_open, low
// pdb params: arStream
void bhkRigidBody::FUN_00c8f3c0(NiStream* stream)
{
    FUN_00c859e0(stream);
    unsigned int count = stream->GetLinkID();
    for (unsigned int i = 0; i < count; ++i)
    {
        NiObject* obj = stream->GetLoadedObject();
        if (obj)
            FUN_00c8ef80(obj);
    }
}

char* __cdecl FUN_00a7d5e0(const char*, const char*);
struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(unsigned int const&);
};
struct StrArr
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char*& e)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, e);
    }
};

// Appends the MOTION type name string matching type (DYNAMIC, SPHERE, BOX, KEYFRAMED, FIXED, THIN BOX, else INVALID) to arr.
// @f3 0x00900970 (community match, verified in this file)
// pdb: bhkRigidBody::AddMotionType | bhkRigidBody.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings, aeType
void __cdecl AddMotionTypeName(StrArr* arr, int type)
{
    char* s;
    switch (type)
    {
    case 1:
        s = FUN_00a7d5e0("MOTION", "DYNAMIC");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 2:
    case 3:
        s = FUN_00a7d5e0("MOTION", "SPHERE");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 4:
    case 5:
        s = FUN_00a7d5e0("MOTION", "BOX");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 6:
        s = FUN_00a7d5e0("MOTION", "KEYFRAMED");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 7:
        s = FUN_00a7d5e0("MOTION", "FIXED");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 8:
        s = FUN_00a7d5e0("MOTION", "THIN BOX");
        ((NiTPrimitiveArray_unsigned_int_*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    default:
        s = FUN_00a7d5e0("MOTION", "INVALID");
        arr->Add(s);
        break;
    }
}


struct FUN_00c8eb00_s
{
    void __thiscall ProcessListNodes();
    void __thiscall FUN_00c9d590();
    void __thiscall FUN_00c8eb00();
};
// @fnv 0x00c8eb00
// pdb: bhkRigidBody::Remove | bhkRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void __thiscall FUN_00c8eb00_s::FUN_00c8eb00()
{
    *(unsigned int*)(this + 0x10) &= 0xffffff77;
    ProcessListNodes();
    FUN_00c9d590();
}

struct LinkedRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct RigidLinkSource
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual LinkedRecord* GetLinkedRecord();

    unsigned int unk04;
    LinkedRecord* unk08;

    unsigned int GetLinkedRecordValue();
};

// Returns unk08 of the record from GetLinkedRecord when unk08 and its unk08 are set, otherwise 0.
// @f3 0x008fc0f0 (community match, verified in this file)
struct RigidLinkSourceF3
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual LinkedRecord* GetLinkedRecord();
};
// pdb: bhkConstraint::GethkWorld | bhkConstraint.obj | fnv360_0721_beta, caller, medium
unsigned int RigidLinkSource::GetLinkedRecordValue()
{
    unsigned int result = 0;
    if (this && unk08 && unk08->unk08)
    {
        LinkedRecord* record = ((RigidLinkSourceF3*)this)->GetLinkedRecord();
        if (record)
            result = record->unk08;
    }
    return result;
}


struct S_00c8d440_Arg
{
    bool unk00;
    S_00c8d440_Arg(bool b)
    {
        unk00 = b;
    }
    S_00c8d440_Arg(const S_00c8d440_Arg& o)
    {
        unk00 = o.unk00;
    }
};

struct NativeData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float factor18, factor1c;
    unsigned int unk20;
    void* lastUpdate;
    int count;
};
struct NativeThing
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual NativeData* GetData();
    unsigned int unk04;
    void* world;
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
    unsigned char motionType;
};
struct NiRTTI
{
};
extern NiRTTI DAT_01267b70;
struct NativeLink
{
    NativeThing* object;
    unsigned int category;
};
NativeLink* FUN_00c85ef0(NativeLink*, NativeThing*, const NiRTTI*);
struct BodyUpdate
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void Reset();
    unsigned int unk04;
    NativeThing* native;
    unsigned int unk0c;
    unsigned int flags;
    unsigned char IsDisabled() const
    {
        return (flags >> 6) & 1;
    }
    bool FUN_00c85810(void*);
    void FUN_00a29680();
    void UpdateMatchingNodes(void*);
    void* FUN_00c87a40();
    bool InWorld()
    {
        NativeThing* body = native;
        if (!body)
            return false;
        FUN_00a29680();
        bool inWorld = body->world != 0;
        FUN_00a29680();
        return inWorld;
    }
    int MotionType() const
    {
        return native ? native->motionType : 0;
    }
    bool IsMoving() const
    {
        int motion = MotionType();
        return motion > 0 && (motion <= 3 || motion == 6);
    }
    bool UpdateBody(void*);
};
// @f3 0x008ff320 (community match, verified in this file)
struct Slot7NativeQuery
{
    NativeLink* FUN_00477900(NativeLink* link,const NiRTTI* type);
};
struct Slot7BodyMethods
{
    bool FUN_008f9b20(void* update);
    void FUN_008ff290(void* update);
    void* FUN_008f81f0();
};
struct Slot7Motion
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned char type;
};
struct Slot7BodyPredicates
{
    void* vtable;
    unsigned int unk04;
    NativeThing* native;
    bool InWorld()
    {
        NativeThing* body=native;
        if(!body) return false;
        bool inWorld=body->world!=0;
        return inWorld;
    }
    bool IsMoving() const
    {
        NativeThing* body=native;
        if(!body) return false;
        int motion=reinterpret_cast<Slot7Motion*>(body)->type;
        return motion<6 || motion==8;
    }
};
extern const NiRTTI DAT_010f2c30;
extern unsigned char FUN_00f79455;
// pdb: bhkRigidBody::Add | bhkRigidBody.obj | fnv360_0822_retail, objrun, medium
// pdb params: apWorld
bool BodyUpdate::UpdateBody(void* update)
{
    NativeLink link;
    NativeData* data;
    if (this && native)
    {
        NativeThing* object = reinterpret_cast<Slot7NativeQuery*>(native)->FUN_00477900(&link, &DAT_010f2c30)->object;
        data = object ? object->GetData() : 0;
    }
    else
        data = 0;
    bool bUnitScale = data && data->factor18 == 1.0f && data->factor1c == 1.0f;
    if ((!bUnitScale || data->count > 0 || FUN_00f79455) && !IsDisabled())
    {
        bool result = reinterpret_cast<Slot7BodyMethods*>(this)->FUN_008f9b20(update);
        if (result || (reinterpret_cast<Slot7BodyPredicates*>(this)->InWorld() && reinterpret_cast<Slot7BodyPredicates*>(this)->IsMoving()))
        {
            if ((!bUnitScale || data->count > 0) && !IsDisabled())
                reinterpret_cast<Slot7BodyMethods*>(this)->FUN_008ff290(update);
        }
        if (data)
            data->lastUpdate = update;
        return result;
    }
    else
    {
        if (reinterpret_cast<Slot7BodyMethods*>(this)->FUN_008f81f0())
            Reset();
        if (data)
            data->lastUpdate = update;
        return true;
    }
}


namespace fnv_00c8dcb0 {
struct S_c8dcb0_Res
{
    struct S_c8dcb0_Obj* p;
    int hi;
};
struct S_c8dcb0_Obj
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
    virtual S_c8dcb0_Obj* v15();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24;
};
extern int DAT_01267b70;
S_c8dcb0_Res* __cdecl FUN_00c85ef0(S_c8dcb0_Res*, int, int*);
}  // namespace fnv_00c8dcb0

struct ListNode;

struct ObjBase
{
    virtual void v00();
    virtual void v04();
    virtual ListNode* v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    int Helper1();
    int Helper2();
};

struct ListNode
{
    ObjBase* m_00;
    ListNode* m_04;
};

struct FUN_00c8e770_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ListNode m_14;
    void ProcessListNodes();
};

extern char DAT_0126818c;
extern char DAT_01268158;

// Walks the m_14 list; for each node with an ObjBase, checks its v08 list for DAT_0126818c/DAT_01268158 and calls Helper1/Helper2, invoking vA0 if nonzero.
// @fnv 0x00c8e770
// pdb: bhkRigidBody::RemoveActionConstraintsFromWorld | bhkRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
void FUN_00c8e770_cls::ProcessListNodes()
{
    ListNode* n = &m_14;
    while (n)
    {
        if (n->m_04 == 0 && n->m_00 == 0)
            return;
        ObjBase* o = n->m_00;
        if (o)
        {
            int r = 0;
            ListNode* p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (ListNode*)&DAT_0126818c)
                    {
                        r = o->Helper1();
                        goto L_070;
                    }
                }
            }
            p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (ListNode*)&DAT_01268158)
                    {
                        r = o->Helper2();
                        goto L_070;
                    }
                }
            }
            goto L_080;
        L_070:
            if (r)
                o->vA0();
        }
    L_080:
        n = n->m_04;
    }
}

struct C8EC60RTTI
{
    const char* m_pcName;
    const C8EC60RTTI* m_pBaseRTTI;
};

class C8EC60Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const C8EC60RTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void ResetWorldObject();

    bool IsKindOfType(const C8EC60RTTI& kRTTI) const
    {
        for (const C8EC60RTTI* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }
};

class C8EC60Constraint : public C8EC60Object
{
  public:
    static const C8EC60RTTI ms_kRTTI;

    void* GetConstraint();
};

class C8EC60RefObject : public C8EC60Object
{
  public:
    static const C8EC60RTTI ms_kRTTI;

    void* GetReferencedData();
};

class C8EC60Iterator
{
  public:
    C8EC60Object* m_pkCurrent;

    void Next();
};

class C8EC60World
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C8EC60Iterator m_kIterator;

    C8EC60Iterator* GetIterator()
    {
        return &m_kIterator;
    }
    void FUN_00c8ec60();
};

// Iterates the world's objects and calls ResetWorldObject on constraints and ref objects that hold a non-null constraint or referenced data.
// @fnv 0x00c8ec60
// pdb: bhkRigidBody::RemoveActionConstraints | bhkRigidBody.obj | fnv360_0822_retail, call_gap, medium
void C8EC60World::FUN_00c8ec60()
{
    C8EC60Iterator* pkIter = GetIterator();
    while (pkIter && pkIter->m_pkCurrent)
    {
        C8EC60Object* pkObject = pkIter->m_pkCurrent;
        if (pkObject->IsKindOfType(C8EC60Constraint::ms_kRTTI))
        {
            if (static_cast<C8EC60Constraint*>(pkObject)->GetConstraint())
                pkObject->ResetWorldObject();
        }
        else if (pkObject->IsKindOfType(C8EC60RefObject::ms_kRTTI))
        {
            if (static_cast<C8EC60RefObject*>(pkObject)->GetReferencedData())
                pkObject->ResetWorldObject();
        }
        pkIter->Next();
    }
}

extern int DAT_0126810c;
extern int DAT_012681fc;
extern int DAT_012681bc;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

struct Pair8
{
    unsigned int a;
    unsigned int b;
    Pair8()
    {
        a = 0;
        b = 0;
    }
};

struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    Pair8 m_0c;
    ChainA_cls()
    {
        DAT_0126810c += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012681fc += 1;
    }
};

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    unsigned int m_14;
    unsigned int m_18;
    SpawnedObject()
    {
        m_14 = 0;
        m_18 = 0;
        DAT_012681bc += 1;
    }
};

// Allocates and constructs a new SpawnedObject, incrementing the three global counters in its constructors, and returns it.
// @fnv 0x00c8ed70
// pdb: bhkRigidBody::CreateObject | bhkRigidBody.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, medium
SpawnedObject* __cdecl FUN_00c8ed70()
{
    return new SpawnedObject();
}

struct NiNode;
struct HavokShape
{
    void FUN_00c8f080();
    void FUN_00c8eb20(void* context);
};
struct HavokLookup
{
    void* ReportDiagnostic;
    void* unused4;
    void* unused8;
    void* unusedC;
    HavokShape* shape;
};
struct HavokProperty
{
    HavokLookup* FUN_00653290(const void* key);
};
struct HavokObject
{
    virtual void Virt0();
    virtual void Virt1();
    virtual void Virt2();
    virtual NiNode* GetCellChildAt();

    unsigned int referenceCount;
    void* extraData;
    void* userData;
    void* collisionData;
    void* owner;
    void* source;
    HavokProperty* property;

    void FUN_00a68bf0();
};
struct NiTransform
{
    float rotation[3][3];
    float translation[3];
    float scale;
};
struct NiBound
{
    float center[3];
    float radius;
};
struct NiNode
{
    void* vtbl;
    unsigned int referenceCount;
    const char* name;
    void* controller;
    void* extraData;
    unsigned short extraDataCount;
    unsigned short extraDataCapacity;
    void* parent;
    NiBound worldBound;
    NiTransform local;
    NiTransform world;
    void* collisionObject;
    unsigned int flags;
    unsigned int unknown9C;
    HavokObject** children;
    unsigned short maxChildren;
    unsigned short childCount;
};
extern char DAT_012043f8;
// @f3 0x00900ce0 (community match, verified in this file)
// pdb: bhkRigidBody::SetFixed | bhkRigidBody.obj | fnv360_0721_retail, call_seq, high
// pdb params: apObject, abFix, abAddRemainingConstraints
// pdb: bhkRigidBody::SetFixed | bhkRigidBody.obj | fnv360_0721_retail, call_seq, high (was: ApplyHavokOperation)
void __cdecl bhkRigidBody_SetFixed(HavokObject* object, int operation, void* context)
{
    HavokLookup* __cdecl FUN_00424fe0(HavokObject* object);
    if (object != 0)
    {
        object->FUN_00a68bf0();
        HavokLookup* link = FUN_00424fe0(object);
        if (link != 0 && link->shape != 0)
        {
            if ((char)operation)
                link->shape->FUN_00c8f080();
            else
                link->shape->FUN_00c8eb20(context);
        }
        NiNode* node = object->GetCellChildAt();
        if (node)
        {
            for (unsigned int index = 0; index < node->childCount; ++index)
                bhkRigidBody_SetFixed(node->children[index], operation, context);
        }
    }
}


struct NiObject;
struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float scale;
};

struct NiCloneable
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual NiObject* CreateCloneStub(CloningProcess* c);
};

struct CloneNode
{
    NiCloneable* data;
    CloneNode* next;
};

struct hkWorldObjSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
};

struct hkWorldObjStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkWorldObjSub sub;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    hkWorldObjSub* GetSub()
    {
        return this ? &sub : 0;
    }
};
static inline unsigned int GetWFlags(hkWorldObjStub* w)
{
    hkWorldObjSub* s = w ? &w->sub : 0;
    return s ? s->flags : 0;
}
static inline bool WFlag13(hkWorldObjStub* w)
{
    return (GetWFlags(w) >> 13) & 1;
}

struct ScaledBody
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    float m70[12];
    float vA0[4];
    float fB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    char unkD4;
    void Scale(float s);
};

__declspec(noinline) void ScaledBody::Scale(float s)
{
    float s2 = s * s;
    this->vA0[0] *= s;
    this->vA0[1] *= s;
    this->vA0[2] *= s;
    this->vA0[3] *= s;
    float* p = m70;
    for (int i = 0; i < 3; i++)
    {
        p[0] *= s2;
        p[4] *= s2;
        p[8] *= s2;
        p++;
    }
    this->fB0 *= s;
}

struct RigidBodyS
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual void VB0();
    virtual ScaledBody* GetBodyStub(bool* out);
    virtual void VB8();
    virtual void VBC();
    virtual void VC0();
    virtual void UpdateStub();
    int unk04;
    hkWorldObjStub* unk08;
    int unk0C;
    unsigned int unk10;
    CloneNode list;

    void BaseCopyMembers(RigidBodyS* dest, CloningProcess* c);
    void LockStub();
    unsigned int GetFlagsW()
    {
        return GetWFlags(unk08);
    }
    unsigned int GetFlagsWith(unsigned int bit)
    {
        unsigned int f = GetFlagsW() | bit;
        return f;
    }
    void SetFlagsW(unsigned int f)
    {
        hkWorldObjStub* w = unk08;
        if (!w)
            return;
        LockStub();
        hkWorldObjSub* s = w->GetSub();
        LockStub();
        if (s)
            s->flags = f;
    }
    bool Flag9() const
    {
        return (unk10 >> 9) & 1;
    }
    void AddClonedStub(NiObject*);
    void CopyBodyToClone(RigidBodyS* dest, CloningProcess* c);
};

// Copies body members into dest, scales the body stub when c->scale != 1, sets unk28 from unk08->unk210, and clones list nodes into dest.
// @f3 0x00900e00 (community match, verified in this file)
struct NativeRigidCloneAttachment {
    void FUN_00900ad0(NiObject* child);
};

// pdb: bhkRigidBody::CopyMembers | bhkRigidBody.obj | fnv360_0721_beta, caller_sim, low
// pdb params: apDest, arCloneData
void RigidBodyS::CopyBodyToClone(RigidBodyS* dest, CloningProcess* context)
{
    bool bodyStatus;
    ScaledBody* body = GetBodyStub(&bodyStatus);
    if (Flag9())
        *reinterpret_cast<unsigned char*>(&body->unkD0) = 1;

    if (body) {
        const float scale = context->scale;
        if (scale != 1.0f)
            body->Scale(scale);
    }

    BaseCopyMembers(dest, context);
    dest->unk10 = (dest->unk10 | unk10) & 0xfffffc07u;

    CloneNode* link = &list;
    if (WFlag13(unk08) || context->scale != 1.0f) {
        hkWorldObjStub* world = dest->unk08;
        const unsigned int flags = GetWFlags(world) | 0x2000u;
        if (world) {
            hkWorldObjSub* sub = world->GetSub();
            if (sub)
                sub->flags = flags;
        }
        dest->VC0();
    }

    for (; link && link->data; link = link->next) {
        NiObject* child = link->data->CreateCloneStub(context);
        reinterpret_cast<NativeRigidCloneAttachment*>(dest)->FUN_00900ad0(child);
    }
}


extern __declspec(thread) unsigned int hkThreadMemoryFlags;

struct ThreadFlagsGuard
{
    unsigned int saved;
    ThreadFlagsGuard()
    {
        saved = hkThreadMemoryFlags;
        hkThreadMemoryFlags = 0x10;
    }
    ~ThreadFlagsGuard()
    {
        hkThreadMemoryFlags = saved;
    }
};

extern unsigned int g_iRefObjectCountA;
extern int g_iSerializableCount;
extern int g_iLiquidActionCount;

struct bhkRefObjectBase
{
    virtual ~bhkRefObjectBase();
    int refCount;
    int unk08;
    bhkRefObjectBase();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};

struct bhkRefObjectLvl : bhkRefObjectBase
{
    struct LinkPair
    {
        void* unk0C;
        void* unk10;
        LinkPair() : unk0C(0), unk10(0)
        {}
    } links;
    bhkRefObjectLvl()
    {
        ++g_iRefObjectCountA;
    }
};

struct bhkSerializableLvl : bhkRefObjectLvl
{
    bhkSerializableLvl()
    {
        ++g_iSerializableCount;
    }
};

struct bhkLiquidAction : bhkSerializableLvl
{
    int unk14;
    int unk18;
    bhkLiquidAction()
    {
        unk14 = 0;
        unk18 = 0;
        ++g_iLiquidActionCount;
    }
};

extern __declspec(thread) int g_tlsMemContext;

struct ScopedMemoryContext
{
    int iOldContext;
    ScopedMemoryContext(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    ~ScopedMemoryContext()
    {
        g_tlsMemContext = iOldContext;
    }
};

struct GlobalObject_004ee810
{
    void FUN_004ee920();
};

struct FUN_00c9d4c0_holder
{
    void FUN_00c9d4c0();
};

struct Shell_c8da40 : public FUN_00c9d4c0_holder
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    GlobalObject_004ee810 uTmpnk;

    void FUN_00c8da40();
};

// Switches to memory context 0x10, calls FUN_004ee920 on uTmpnk, then calls FUN_00c9d4c0.
// @f3 0x00752180 (community match, verified in this file)
class __declspec(novtable) Base470 {
public:

    unsigned int unk4,unk8,unkc,unk10,unk14,unk18,unk1c,unk20;
    unsigned int unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    unsigned int unk44,unk48,unk4c,unk50,unk54,unk58;
    void FUN_00727210();
    virtual ~Base470() { FUN_00727210(); }
};
struct Small470 { unsigned int unk00,unk04; void FUN_006c8220(); ~Small470(){FUN_006c8220();} };
struct First470 { unsigned int unk00,unk04,unk08,unk0c; void FUN_006c8220(); ~First470(){FUN_006c8220();} };
struct Fourth470 { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14; void FUN_006c8220(); ~Fourth470(){FUN_006c8220();} };
struct Last470 { unsigned int unk00; void FUN_0076b220(); ~Last470(){FUN_0076b220();} };
struct Body470 { void FUN_00723670(); };
struct View470:Base470 {
    First470 first; Small470 second,third; Fourth470 fourth; Last470 last;
    void FUN_00750010();
    __forceinline virtual ~View470() {

        reinterpret_cast<Body470*>(&unk4)->FUN_00723670();
        FUN_00750010();
    }
};
// pdb: LowProcess::~LowProcess | LowProcess.obj | fnv360_0822_retail, call_seq, medium
void Shell_c8da40::FUN_00c8da40() { reinterpret_cast<View470*>(this)->View470::~View470(); }


struct C8DAC0RTTI
{
    const char* m_pcName;
    const C8DAC0RTTI* m_pBaseRTTI;
};
extern char DAT_0126818c;
extern char DAT_01268628;
class C8DAC0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const C8DAC0RTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void Update(void* pvContext);
};
inline bool C8DAC0IsKindOf(const C8DAC0RTTI& kRTTI, const C8DAC0Object* pkObject)
{
    if (!pkObject)
        return false;
    for (const C8DAC0RTTI* pkRTTI = pkObject->GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
    {
        if (pkRTTI == &kRTTI)
            return true;
    }
    return false;
}
struct C8DAC0Node
{
    C8DAC0Object* m_pPointer;
    C8DAC0Node* m_pkNext;
};
class C8DAC0Owner
{
  public:
    virtual ~C8DAC0Owner();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiValue1;
    C8DAC0Node m_kHead;

    unsigned int GetField(unsigned int uiMask, unsigned int uiPos) const
    {
        return (m_uiValue1 & uiMask) >> uiPos;
    }

    void UpdateMatchingNodes(void* pvContext);
};
// @fnv 0x00c8dac0
// pdb: bhkRigidBody::AddActConToWorld | bhkRigidBody.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apWorld
void C8DAC0Owner::UpdateMatchingNodes(void* pvContext)
{
    bool bFilterByKind = (bool)(GetField(4, 2) & 1);
    for (C8DAC0Node* pkNode = &m_kHead; pkNode; pkNode = pkNode->m_pkNext)
    {
        if (!pkNode->m_pPointer)
            break;
        bool bMatch = bFilterByKind &&
                      C8DAC0IsKindOf(reinterpret_cast<const C8DAC0RTTI&>(DAT_0126818c), pkNode->m_pPointer) &&
                      C8DAC0IsKindOf(reinterpret_cast<const C8DAC0RTTI&>(DAT_01268628), pkNode->m_pPointer);
        if (!bFilterByKind || bMatch)
            pkNode->m_pPointer->Update(pvContext);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern __declspec(thread) int g_iAllocTagC8E;
struct AllocTagScopeC8E
{
    int m_iSaved;

    AllocTagScopeC8E(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC8E;
        g_iAllocTagC8E = aiAllocationTag;
    }
    ~AllocTagScopeC8E()
    {
        g_iAllocTagC8E = m_iSaved;
    }
};
class NiRTTIC8E
{
  public:
    const char* m_pcName;
    const NiRTTIC8E* m_pBaseRTTI;

    const NiRTTIC8E* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
};
class NiObjectC8E
{
  public:
    virtual ~NiObjectC8E();
    virtual void DeleteThis();
    virtual const NiRTTIC8E* GetRTTI() const;

    bool IsKindOfType(const NiRTTIC8E& kRTTI) const
    {
        for (const NiRTTIC8E* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->GetBaseRTTI())
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerC8E
{
  public:
    NiPointerC8E(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC8E()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
struct ListItemC8E
{
    ListItemC8E* m_pkNext;
    ListItemC8E* m_pkPrev;
    NiObjectC8E* m_pkElement;
};
ListItemC8E* __cdecl NewListItemC8E(NiObjectC8E* pkObject);
class ObjectListC8E
{
  public:
    __declspec(noinline) void AddTail(const NiPointerC8E<NiObjectC8E>& spRetainedObject)
    {
        ListItemC8E* pkItem = NewListItemC8E(spRetainedObject.m_pObject);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        m_uiCount++;
    }

    ListItemC8E* m_pkHead;
    ListItemC8E* m_pkTail;
    unsigned int m_uiCount;
};
class SceneC8E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ObjectListC8E m_kThirdFollowingStreamField;

    void FUN_00c8ef80(NiObjectC8E* pkObject);
};
// Adds pkObject to the object list if it is a geometry or node, using an allocation tag scope of 0x10.
// @f3 0x00900ad0 (community match, verified in this file)
// pdb: bhkRigidBody::AddActCon | bhkRigidBody.obj | fnv360_0822_retail, call_gap, medium
// pdb params: apActCon
void SceneC8E::FUN_00c8ef80(NiObjectC8E* pkObject)
{
    if (pkObject && (reinterpret_cast<C8EC60Object*>(pkObject)->IsKindOfType(C8EC60Constraint::ms_kRTTI) || reinterpret_cast<C8EC60Object*>(pkObject)->IsKindOfType(C8EC60RefObject::ms_kRTTI)))
    {
        NiPointerC8E<NiObjectC8E> spObject(pkObject);
        m_kThirdFollowingStreamField.AddTail(spObject);
    }
}


struct RefCountedObj
{
    virtual void v0();
    virtual void Destroy();
    long m_iRef;
};

struct LinkNode
{
    RefCountedObj* m_pEntryObject;
    LinkNode* m_pNext;
    void Release();
};

struct LinkNodePool
{
    void Free(LinkNode*);
};
extern LinkNodePool g_linkNodePool;

class FUN_00c88990_cls
{
  public:
    RefCountedObj* m_pEntryObject;
    LinkNode* m_pNext;
    void PopAndRelease();
};

// @fnv 0x00c88990
// pdb: BSSimpleList<NiPointer<BSTempEffect> >::RemoveHead | BGSDecalNode.obj | fnv360_0822_retail, call_seq, high
void FUN_00c88990_cls::PopAndRelease()
{
    LinkNode* node = m_pNext;
    if (node != 0)
    {
        m_pNext = node->m_pNext;
        RefCountedObj* pOldObject = m_pEntryObject;
        if (pOldObject != node->m_pEntryObject)
        {
            if (pOldObject != 0)
            {
                if (InterlockedDecrement(&pOldObject->m_iRef) == 0)
                    pOldObject->Destroy();
            }
            m_pEntryObject = node->m_pEntryObject;
            if (m_pEntryObject != 0)
                InterlockedIncrement(&m_pEntryObject->m_iRef);
        }

        node->m_pNext = 0;
        node->Release();
        g_linkNodePool.Free(node);
    }
    else
    {
        RefCountedObj* obj = m_pEntryObject;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_iRef) == 0)
                obj->Destroy();
            m_pEntryObject = 0;
        }
    }
}

// Recursively visits child nodes, calling FUN_00c8ec60 on the linked shape found via FUN_00653290 on each object's property when present.
// @f3 0x00900500 (community match, verified in this file)
HavokLookup* __cdecl FUN_00424fe0(HavokObject* object);
// pdb: bhkRigidBody::RemoveAllActionConstraints | bhkRigidBody.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apObject
void __cdecl FUN_00c8ecf0(HavokObject* object)
{
    if (!object)
        return;

    HavokLookup* link = FUN_00424fe0(object);
    if (link && link->shape)
        reinterpret_cast<C8EC60World*>(link->shape)->FUN_00c8ec60();

    NiNode* node = object->GetCellChildAt();
    if (node)
    {
        for (unsigned int i = 0; i < node->childCount; ++i)
            FUN_00c8ecf0(node->children[i]);
    }
}


#include <xmmintrin.h>
struct hkVector
{
    __m128 m_vComponents;
    hkVector()
    {}
    hkVector(const hkVector& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
namespace c8d {
struct Body
{
    char pad[0x170];
    hkVector m_kPos;
};
}

struct __declspec(align(16)) hkVector4
{
    __m128 m_vComponents;
    hkVector4()
    {}
    hkVector4(const hkVector4& o) : m_vComponents(o.m_vComponents)
    {}
    hkVector4& operator=(const hkVector4& o)
    {
        m_vComponents = o.m_vComponents;
        return *this;
    }
};

struct Transform_c8d3
{
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;
};
extern Transform_c8d3 DAT_01268370;

struct Aabb_c8d3
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

class Shape_c8d3
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void getAabb(const Transform_c8d3& kLocalToWorld, float fTolerance, Aabb_c8d3& kOut) const;
};

struct CdBody_c8d3
{
    Shape_c8d3* m_pkShape;
    Shape_c8d3* getShape() const
    {
        return m_pkShape;
    }
};

struct EntityBase_c8d3
{
    int unk00, unk04, unk08, unk0c;
};

struct Entity_c8d3 : public EntityBase_c8d3, public CdBody_c8d3
{
};

class WorldObject_c8d3
{
  public:
    int unk00;
    int unk04;
    Entity_c8d3* m_pkEntity;

    void FUN_00a29680();
    void GetAabb(Aabb_c8d3& kOut);
};

// Fills kOut from the entity shape's getAabb (global transform DAT_01268370, tolerance 0.001), or a +-0.001 box around zero when there is no shape.
// @fnv 0x00c8d390
void WorldObject_c8d3::GetAabb(Aabb_c8d3& kOut)
{
    CdBody_c8d3* pkBody = 0;
    if (this)
    {
        Entity_c8d3* pkEntity = m_pkEntity;
        if (pkEntity)
        {
            FUN_00a29680();
            pkBody = static_cast<CdBody_c8d3*>(pkEntity);
            FUN_00a29680();
        }
    }
    Shape_c8d3* pkShape = pkBody ? pkBody->getShape() : 0;
    if (pkShape)
    {
        pkShape->getAabb(DAT_01268370, 0.001f, kOut);
    }
    else
    {
        kOut.m_kMinimumCorner = _mm_setr_ps(-0.001f, -0.001f, -0.001f, 0.0f);
        kOut.m_kMaximumCorner = _mm_setr_ps(0.001f, 0.001f, 0.001f, 0.0f);
    }
}

namespace fnv_00c8d510 {
struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

}  // namespace fnv_00c8d510

struct BuildSettings
{
    unsigned int unk00;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    float fB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    float fC4;
    float fC8;
    unsigned int unkCC;
    float fD0;
    signed char motionType, response, quality, solver;
    unsigned char unkD8, unkD9, callback, unkDB;
};
struct FUN_00ca8c90;
struct BodyAllocator
{
    virtual void unused();
    virtual FUN_00ca8c90* Allocate(unsigned int size);
};
struct BodyMemory
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyAllocator* allocator;
    void* AllocateBody(unsigned int size)
    {
        return allocator->Allocate(size);
    }
};
BodyMemory* FUN_00c85750();
struct FUN_00ca8c90
{
    unsigned int unk00;
    unsigned short allocationSize, references;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    FUN_00ca8c90(void* settings);
    void FUN_00ca8420(int motion, int activate, int extra);
    void FUN_00c905b0();
    static void* operator new(unsigned int size)
    {
        FUN_00ca8c90* p = (FUN_00ca8c90*)FUN_00c85750()->AllocateBody(size);
        p->allocationSize = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};
struct BodyMotion
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned char unk18, unk19, quality;
};
struct BodyNative
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyMotion motion;
};
struct Bounds
{
    __m128 minimum;
    __m128 maximum;
};
struct BodyBuild
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void SetBody(FUN_00ca8c90* body);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void FinishBuild(BuildSettings* settings);
    unsigned int unk04;
    BodyNative* native;
    void FUN_00a29680();
    void GetAabb(Bounds* bounds);
    float FUN_00577b50();
    BodyMotion* GetMotion()
    {
        BodyNative* p = native;
        if (!p)
            return 0;
        FUN_00a29680();
        BodyMotion* result = p ? &p->motion : 0;
        FUN_00a29680();
        return result;
    }
    void ConfigureBody(BuildSettings* settings);
};
// Clamps BuildSettings fields, allocates a body via operator new, sets motion and solver, adjusts quality from bounds, then calls FinishBuild.
// @f3 0x008feed0 (community match, verified in this file)
#include <windows.h>
namespace f3m_008feed0 {
struct NativeVec_8feed0 { __declspec(align(16)) float x; float y,z,w; float& operator[](int i) {return (&x)[i];} };
struct Bounds { NativeVec_8feed0 minimum,maximum; };
struct BodyMotion { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14; unsigned char unk18,unk19; unsigned short quality; };
struct BodyNative { unsigned int unk00,unk04,unk08,unk0c; BodyMotion motion; };
struct Arena_8feed0 { void* FUN_008f6d30(unsigned int size,int tag); };
extern unsigned long DAT_010f3170;
extern float DAT_010f2a7c,DAT_010f2a80;
extern const double DAT_00dba5c8,DAT_00dccdd8;
extern const float DAT_00e00f1c,DAT_00e34814;
struct NativeSettings_2062
{
    unsigned int unk00;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    float fB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;

    float fC4;
    float fC8;
    unsigned int unkCC;
    float fD0;
    signed char motionType, response, quality, solver;
    unsigned char unkD8, unkD9, callback, unkDB;
};
struct FUN_00ca8c90
{
    unsigned int unk00;
    unsigned short allocationSize, references;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    FUN_00ca8c90(void* settings);
    void FUN_00ca8420(int motion,int activate,int extra); void hkpRigidBody_setMotionType(int motion,int activate,int extra);
    void FUN_00c905b0(); void FUN_009316f0();
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
};
struct BuildSettings;
struct BodyBuild
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void SetBody(FUN_00ca8c90* body);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void FinishBuild(BuildSettings* settings);
    unsigned int unk04;
    BodyNative* native;
    void FUN_00a29680();
    void GetAabb(Bounds* bounds);
    float FUN_00577b50(); float FUN_008fec50();
    BodyMotion* GetMotion()
    {
        BodyNative* p = native;
        if (!p)
            return 0;

        BodyMotion* result = p ? &p->motion : 0;

        return result;
    }
    void ConfigureBody(BuildSettings* settings);
};
void* FUN_00ca8c90::operator new(unsigned int size) {
 Arena_8feed0* arena=static_cast<Arena_8feed0*>(TlsGetValue(DAT_010f3170));
 FUN_00ca8c90* object=static_cast<FUN_00ca8c90*>(arena->FUN_008f6d30(size,0x2d));
 object->allocationSize=static_cast<unsigned short>(size); return object;
}
}
// pdb: bhkRigidBody::Init | bhkRigidBody.obj | fnv360_0822_retail, uconst, low
// pdb params: arInfo
void BodyBuild::ConfigureBody(BuildSettings* input) {
 using namespace f3m_008feed0;
 f3m_008feed0::BodyBuild* self=reinterpret_cast<f3m_008feed0::BodyBuild*>(this);
 NativeSettings_2062* settings=reinterpret_cast<NativeSettings_2062*>(input);
 if(!settings) return;
 int savedMotion=10;
 if(settings->fD0<=1.1920928955078125e-7f || settings->fD0>DAT_00dba5c8) settings->fD0=DAT_00e00f1c;
 if(settings->fC8<1000.0) settings->fC8=1000.0f;
 if(settings->fC4>=DAT_00dccdd8) settings->fC4=DAT_00e34814;
 if(settings->fB0!=0.0f) {
  int motion=settings->motionType;
  bool special=motion==6 || motion==7;
  if(special) {savedMotion=motion;settings->motionType=1;settings->solver=4;}
  else if(settings->solver==0) settings->solver=4;
 } else if(settings->motionType==7) settings->solver=1;
 settings->unk20=settings->unk00; settings->unk24=settings->unk04;
 f3m_008feed0::FUN_00ca8c90* body=new f3m_008feed0::FUN_00ca8c90(&settings->unk20);
 if(savedMotion!=10) {settings->motionType=static_cast<signed char>(savedMotion);body->hkpRigidBody_setMotionType(savedMotion,1,0);}
 self->SetBody(body);body->FUN_009316f0();
 int motion=settings->motionType;
 if(motion<6 || motion==8) {
  if(settings->motionType>0) {
   f3m_008feed0::BodyMotion* nativeMotion=self->GetMotion();
   if(nativeMotion) {
    f3m_008feed0::Bounds bounds;self->GetAabb(&bounds);
    NativeVec_8feed0 extent;
    extent.x=bounds.maximum.x-bounds.minimum.x;extent.y=bounds.maximum.y-bounds.minimum.y;
    extent.z=bounds.maximum.z-bounds.minimum.z;extent.w=bounds.maximum.w-bounds.minimum.w;
    int axis;
    if(extent.x>extent.y) axis=extent.y>extent.z?2:1;
    else axis=extent.x>extent.z?2:0;
    if(!(extent[axis]>DAT_010f2a7c)) {
     float threshold=DAT_010f2a80;
     float scale=self->FUN_008fec50();
     if(!(scale<threshold)) {
      if(settings->solver==3) {nativeMotion->quality=4;settings->solver=4;}
     } else {nativeMotion->quality=3;settings->solver=3;}
    } else {nativeMotion->quality=3;settings->solver=3;}
   }
  }
 }
 self->FinishBuild(reinterpret_cast<f3m_008feed0::BuildSettings*>(input));
}


struct Matrix
{
    __m128 columns[4];
};
struct Receiver
{
    void FUN_00c7f640(Matrix*, const __m128*);
};
struct BodySlot
{
    void* body;
    __forceinline void* getBody()
    {
        if (this)
            return body;
        return 0;
    }
};
struct CollisionOwner
{
    void* vtable;
    void* unk04;
    void* node;
    void FUN_00a29680();
    void DispatchCollision(Receiver*);
    __forceinline BodySlot* GetSlot()
    {
        char* base = (char*)node;
        if (base)
        {
            FUN_00a29680();
            base += 16;
            FUN_00a29680();
            if (base)
                return (BodySlot*)base;
        }
        return 0;
    }
};

namespace fnv_00c8e800 {
struct RTTI
{
    const char* name;
    const RTTI* parent;
};
extern RTTI DAT_012043f8;
struct Node;
struct Collision;
struct Object
{
    virtual void Slot0();
    virtual void Slot1();
    virtual const RTTI* GetRTTI();
    virtual Node* GetAsNode();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    Collision* collision;
};
extern const __m128 DAT_010ec7f0;
struct Vector
{
    __m128 value;
    void Interpolate(const Vector& oldValue, const Vector& newValue, float factor)
    {
        __m128 weight = _mm_set1_ps(factor);
        value = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, weight), oldValue.value),
                           _mm_mul_ps(weight, newValue.value));
    }
};
struct Body
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void GetNavMeshData(Vector* out);
    float FUN_0062ab20();
};
struct Collision : Object
{
};
struct Node : Object
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    Object** children;
    unsigned short capacity;
    unsigned short count;
};
extern const __m128 DAT_010ec7f0;
inline bool IsKindOfType(Collision* object)
{
    const RTTI* type = object->GetRTTI();
    while (type)
    {
        if (type == &DAT_012043f8)
            return true;
        type = type->parent;
    }
    return false;
}
}  // namespace fnv_00c8e800

struct BinaryStream_c8ea
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BinaryStream_c8ea* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 4;
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class RigidBody_c8ea
{
  public:
    unsigned int m_uiValue1;
    void SwapEndian();
};

class WorldObject_c8ea
{
  public:
    virtual void v00();
    void FUN_00c9d4f0(char* pkStream);
    float FUN_0062ab20();
};

struct LoadStream_c8ea
{
    void NiStream_ReadMultipleLinkIDs();
};

class Entity_c8ea : public WorldObject_c8ea
{
  public:
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
    virtual char* GetRigidBody(int* piIndex);

    int unk04, unk08, unk0c;
    int m_iSlotCount;

    void FUN_00c8ea30(char* pkStream);
};

// Calls FUN_00c9d4f0, swaps the rigid body's endianness unless a stream byte is 1, clamps a float to 1000, may set a type byte, and reads m_iSlotCount.
// @f3 0x00900840 (community match, verified in this file)
// pdb: bhkRigidBody::LoadBinary | bhkRigidBody.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: arStream
void Entity_c8ea::FUN_00c8ea30(char* pkStream)
{
    char* s = pkStream;
    FUN_00c9d4f0(s);
    char* pkBody = GetRigidBody((int*)&pkStream);
    if (pkBody)
    {
        if (*(unsigned int*)(s + 4) < 0x20)
            *(unsigned char*)(pkBody + 0xd5) = 0;
        if (*(unsigned char*)(s + 0x1e5) != 1)
            ((RigidBody_c8ea*)pkBody)->SwapEndian();
        if (*(float*)(pkBody + 0xc4) > 1000.0)
            *(float*)(pkBody + 0xc4) = 1000.0f;
        if (*(float*)(pkBody + 0xb0) == 0.0f && FUN_0062ab20() == 0.0f)
        {
            unsigned int uiType = ((RigidBody_c8ea*)pkBody)->m_uiValue1 & 0x7f;
            if (uiType != 2 && uiType != 0x1c)
                *(unsigned char*)(pkBody + 0xd0) = 7;
        }
    }
    ((LoadStream_c8ea*)s)->NiStream_ReadMultipleLinkIDs();
    BinaryStream_c8ea* __restrict pBin = *(BinaryStream_c8ea**)(s + 0x24c);
    *(int*)&pkStream = 4;
    pBin->m_uiStreamFlags += pBin->m_pfnRead(pBin, &m_iSlotCount, 4, (unsigned int*)&pkStream, 1);
}


extern "C" void _ReadWriteBarrier(void);

struct RTTI_eb20
{
    const char* m_pcName;
    const RTTI_eb20* m_pBaseRTTI;
};

class Constraint_eb20
{
  public:
    virtual ~Constraint_eb20();
    virtual void DeleteThis();
    virtual const RTTI_eb20* GetRTTI() const;
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void SetWorld(int iWorld);
    virtual void RegisterWithWorld();

    bool IsKindOfType(const RTTI_eb20& kRTTI) const
    {
        for (const RTTI_eb20* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }

    unsigned int GetLinkedRecordValue();
};

struct ConstraintList_eb20
{
    Constraint_eb20* m_pkItem;
    ConstraintList_eb20* m_pkNext;
    void PopAndRelease();
};

struct WorldData_eb20
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int m_iWorld;
};

struct RefObject_eb20
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiValue1;
    ConstraintList_eb20 m_kConstraints;

    void* FUN_00c87a40();
    int GetWorld()
    {
        WorldData_eb20* pkData = (WorldData_eb20*)FUN_00c87a40();
        return pkData ? pkData->m_iWorld : 0;
    }
    unsigned char IsInWorld() const
    {
        return (m_uiValue1 >> 2) & 1;
    }
    void FUN_00c8eb20(bool bSetWorld);
};

extern "C" __declspec(thread) int tls_iMemContext_eb20;
struct MemContextGuard_eb20
{
    int m_iOldContext;
    MemContextGuard_eb20(int aiMemoryContext)
    {
        m_iOldContext = tls_iMemContext_eb20;
        tls_iMemContext_eb20 = aiMemoryContext;
    }
    ~MemContextGuard_eb20()
    {
        tls_iMemContext_eb20 = m_iOldContext;
    }
};

extern char DAT_0126818c;

// If in a world, registers linked constraints and pops them, sets the world on the others when bSetWorld is true, then clears the in-world bit.
// @fnv 0x00c8eb20
void RefObject_eb20::FUN_00c8eb20(bool bSetWorld)
{
    MemContextGuard_eb20 kGuard(0x10);
    if (IsInWorld())
    {
        int iWorld = GetWorld();
        _ReadWriteBarrier();
        if (iWorld)
        {
            ConstraintList_eb20* pkNode = &m_kConstraints;
            if (pkNode)
            {
                do
                {
                    Constraint_eb20* pkItem = pkNode->m_pkItem;
                    if (!pkItem)
                        break;
                    Constraint_eb20* pkConstraint =
                        pkItem->IsKindOfType(reinterpret_cast<const RTTI_eb20&>(DAT_0126818c)) ? pkItem : 0;
                    if (pkConstraint)
                    {
                        if (pkConstraint->GetLinkedRecordValue())
                        {
                            pkConstraint->RegisterWithWorld();
                            m_kConstraints.PopAndRelease();
                        }
                        else
                        {
                            pkNode = pkNode->m_pkNext;
                            if (bSetWorld)
                                pkConstraint->SetWorld(iWorld);
                        }
                    }
                } while (pkNode);
            }
            m_uiValue1 &= ~4u;
        }
    }
}

extern "C" unsigned long __readfsdword(unsigned long);
extern unsigned int DAT_0126fd98;
struct TlsBlock
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};
extern __declspec(thread) TlsBlock g_tlsBlock;
struct MemScope
{
    TlsBlock* block;
    int saved;
    MemScope()
    {
        unsigned int index = *(volatile unsigned int*)&DAT_0126fd98;
        block = ((TlsBlock**)__readfsdword(0x2c))[index];
        saved = block->unk2b4;
        block->unk2b4 = 16;
    }
    ~MemScope()
    {
        block->unk2b4 = saved;
    }
};
struct RTTI
{
    const char* name;
    RTTI* parent;
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual RTTI* type();
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
    virtual void attach(void*);
    virtual void detach();
    bool isType(const RTTI* p)
    {
        RTTI* r = type();
        while (r)
        {
            if (r == p)
                return true;
            r = r->parent;
        }
        return false;
    }
};
struct Node
{
    Obj* object;
    Node* next;
};
struct IntegerTriple
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    void* unk350;
};
struct bhkRefObject
{
    void* GetReferencedData();
};
struct ParentData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c;
};
struct Parent
{
    int unk00, unk04, unk08, unk0c;
    ParentData data;
    ParentData* GetSub()
    {
        return this ? &data : 0;
    }
};
struct Target
{
    int unk00, unk04;
    Parent* parent;
    int unk0c;
    unsigned int flags;
    Node list;
    void* getOwner()
    {
        IntegerTriple* data = (IntegerTriple*)((bhkRefObject*)this)->GetReferencedData();
        return data ? data->unk350 : 0;
    }
    unsigned char getFlag()
    {
        return (unsigned char)(flags >> 2);
    }
    __forceinline unsigned int getBits()
    {
        ParentData* s = parent ? parent->GetSub() : 0;
        return s ? s->unk1c : 0;
    }
    void FUN_00c8f080();
};
// Replaces each matching object in the list with the result of FUN_00cc81c0, attached to the owner, then sets flag value 4.
// @f3 0x00900bb0 (community match, verified in this file)
extern RTTI DAT_010f31fc;
extern float DAT_00db8b4c;
extern Obj* __cdecl FUN_0094bba0(Obj* obj, float amount);
struct ProxyRefC8 { IntegerTriple* FUN_008f81f0(); };
struct TargetStub { void FUN_00900ad0(Obj* child); };
// pdb: bhkRigidBody::Fix | bhkRigidBody.obj | fnv360_0822_retail, call_seq, medium
void Target::FUN_00c8f080()
{
    if (getFlag() & 1)
        return;
    IntegerTriple* data = ((ProxyRefC8*)this)->FUN_008f81f0();
    void* owner;
    if (data) *(void* volatile*)&owner = reinterpret_cast<void*>(data->unk310);
    else *(void* volatile*)&owner = 0;
    if (owner == 0)
        return;
    Node* nextNode = &list;
    while (nextNode)
    {
        Obj* object = nextNode->object;
        if (!object)
            break;
        Obj* selected = object->isType(&DAT_010f31fc) ? object : 0;
        nextNode = nextNode->next;
        if (selected)
        {
            float amount = 1.0f;
            unsigned int bits = getBits();
            unsigned int kind = bits & 0x7f;
            if (kind == 8 || kind == 29)
            {
                unsigned int subkind = (bits >> 8) & 0x1f;
                if (subkind == 17 || (subkind - 21u) <= 1u)
                    amount = DAT_00db8b4c;
            }
            Obj* child = FUN_0094bba0(selected, amount);
            if (child)
            {
                ((TargetStub*)this)->FUN_00900ad0(child);
                selected->detach();
                child->attach(owner);
            }
        }
    }
    flags |= 4;
}

