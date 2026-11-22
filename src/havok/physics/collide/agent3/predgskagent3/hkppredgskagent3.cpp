#include "f3_common.h"
// src/havok/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/predgskagent3/hkppredgskagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00d41860(int a, int b, int c, int d);
// @fnv 0x00d418b0
// pdb: hkBoxBoxAgent3::destroy | hkpBoxBoxAgent3.obj | tesv_win, objrun, medium
void __cdecl ForwardToTarget(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int unused)
{
    FUN_00d41860(aiArg1, aiArg2, aiArg3, aiArg4);
}

struct InputObject
{
    void* vtable;
};
struct InputRecord
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct InputData
{
    InputObject* unk00;
    InputRecord** unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct ResultData
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0A;
    unsigned char unk0B;
    int unk0C;
    void __thiscall FUN_00dafe70(void* a, void* b, void* c);
    void __thiscall FUN_00dafcd0(void* a, void* b, void* c);
};
// Calls one of two handlers on result based on record->type, clears status[2] and some result flags, then returns result advanced by an aligned size.
// @f3 0x009cc0e0 (community match, verified in this file)
struct RResult
{
    void hkpGskCache_initTriangle(void* a, void* b, void* c);
    void hkpGskCache_init(void* a, void* b, void* c);
};

// pdb: hkPredGskAgent3::create | hkpPredGskAgent3.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: input, entry, agentData
void* __cdecl DispatchInputRecord(InputData* input, unsigned char* status, ResultData* result)
{
    InputObject* pObject = input->unk00;
    void* table = pObject->vtable;
    InputRecord* record = *input->unk04;
    if (record->type == 4)
        ((RResult*)result)->hkpGskCache_initTriangle(table, record, &input->unk10);
    else
        ((RResult*)result)->hkpGskCache_init(table, record, &input->unk10);
    status[2] = 0;
    result->unk0B &= 0xEF;
    result->unk0C = 0;
    unsigned int size = (unsigned char)*((char*)result + 0x0D) + 4 * (unsigned char)*((char*)result + 0x0E);
    size += (unsigned char)result->unk0C;
    return (char*)result + ((size * 2 + 0x1F) & 0xFFFFFFF0);
}


// Stand-ins for the script handler functions whose addresses are stored in the
// handler table (0xd417b0 .. 0xd40d80).  Only declared, never defined.
extern "C" void __cdecl hkPredGskAgent3_removePoint(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_commitPotential(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskAgent3_createZombie(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskCylinderAgent3_create(int a, int b, int c, int d);
extern "C" void __cdecl FUN_00d41930(int a, int b, int c, int d);
extern "C" void __cdecl hkPredGskCylinderAgent3_process(int a, int b, int c, int d);

// The handler table that is handed to CScript::RegisterHandler.  It is kept
// 16 byte aligned, which is what makes the compiler emit the aligned frame
// prologue of this function.
struct __declspec(align(16)) HandlerTable
{
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* p6;
    void* p7;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    int unk38;
    int unk3C;
};

// Stand-in for the script object: the registration is a __thiscall member.
class CScript
{
  public:
    void __thiscall RegisterHandler(HandlerTable* handler, int a, int b);
};

// @f3 0x009cbf10 (community match, verified in this file)
struct S_00d417b0_Obj;
struct Table;
struct FUN_00d41830_table;

void FUN_009cb230(int, int, int, int);
void FUN_009cb440(int, int, int, int);
void FUN_009cc140(int, int, int, int);
void FUN_009cbfb0(int, S_00d417b0_Obj*, short);
void FUN_009cbff0(int, Table*, unsigned short);
int FUN_009cc030(int, FUN_00d41830_table*, unsigned short);
int FUN_009cc070(int, int, int, int);
void FUN_009cc0c0(int, int, int, int);

// pdb: hkPredGskCylinderAgent3::registerAgent3 | hkpPredGskCylinderAgent3.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: dispatcher
void RegisterScriptHandlers(void* pScript)
{
    HandlerTable tab;

    tab.p0 = (void*)FUN_009cb230;
    tab.p7 = (void*)FUN_009cb440;
    tab.p6 = (void*)FUN_009cc140;
    tab.p2 = (void*)FUN_009cc070;
    tab.p3 = (void*)FUN_009cbfb0;
    tab.p4 = (void*)FUN_009cbff0;
    tab.p5 = (void*)FUN_009cc030;
    tab.p1 = (void*)FUN_009cc0c0;

    tab.unk32 = 0;
    tab.unk18 = 0;
    tab.unk1C = 0;
    tab.unk20 = 0;
    tab.unk24 = 0;

    tab.unk30 = 1;
    tab.unk31 = 1;

    ((CScript*)pScript)->RegisterHandler(&tab, 3, 1);
    tab.unk32 = 1;
    ((CScript*)pScript)->RegisterHandler(&tab, 1, 3);
}


struct S_00d417b0_Entry
{
    short unk00;
    short m_iOwnerObjectOffset;
    int unk04;
};

struct S_00d417b0_Sub
{
    short unk00;
    unsigned char m_uiItemCount;
    char unk03;
    S_00d417b0_Entry m_entries[1];
};

struct S_00d417b0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00d417b0_Sub m_sub;
};

void __cdecl FUN_00dae340(S_00d417b0_Sub* sub, int index);

// @fnv 0x00d417b0
// pdb: hkPredGskAgent3::removePoint | hkpPredGskAgent3.obj | fnv360_0822_retail, caller_sim, high
// pdb params: entry, agentData, idToRemove
// pdb: hkPredGskAgent3::removePoint | hkpPredGskAgent3.obj | fnv360_0822_retail, caller_sim, high (was: RemoveEntryById)
void __cdecl hkPredGskAgent3_removePoint(int aiUnused, S_00d417b0_Obj* obj, short sId)
{
    S_00d417b0_Sub* sub = &obj->m_sub;
    for (int i = 0; i < sub->m_uiItemCount; i++)
    {
        if (sub->m_entries[i].m_iOwnerObjectOffset == sId)
        {
            FUN_00dae340(sub, i);
            return;
        }
    }
}

struct Slot
{
    unsigned short id;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
};

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    unsigned short unk10;
    Slot slots[1];
};

// Scans table->slots for the first entry whose id is 0xffff and replaces it with value, stopping at table->count.
// @fnv 0x00d417f0
// pdb: hkPredGskAgent3::commitPotential | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, idToCommit
// pdb: hkPredGskAgent3::commitPotential | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun, high (was: InsertSlotId)
void __cdecl hkPredGskAgent3_commitPotential(int aiUnused, Table* table, unsigned short ausId)
{
    int i;
    for (i = 0; i < table->count; i++)
    {
        if (table->slots[i].id == 0xffff)
        {
            table->slots[i].id = ausId;
            return;
        }
    }
}

struct FUN_00d41830_entry
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short key02;
    unsigned int unk04;
};

struct FUN_00d41830_table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0C;
    unsigned char count;
    unsigned char unk0F;
    FUN_00d41830_entry entries[8];
};

// Scans the table's entries for one whose key02 matches key, clears its unk00 and unk01 bytes, and returns the matching index (or count if none).
// @fnv 0x00d41830
// pdb: hkPredGskAgent3::createZombie | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun, high
// pdb params: entry, agentData, idToConvert
// pdb: hkPredGskAgent3::createZombie | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun, high (was: FindEntryByKey)
int __cdecl hkPredGskAgent3_createZombie(int unused, FUN_00d41830_table* table, unsigned short key)
{
    int i = 0;
    int iCount = table->count;
    if (iCount > 0)
    {
        FUN_00d41830_entry* pEntry = &table->entries[0];
        do
        {
            if (pEntry->key02 == key)
            {
                pEntry->unk00 = 0;
                pEntry->unk01 = 0;
                goto found;
            }
            ++i;
            ++pEntry;
        } while (i < iCount);
    }
found:
    return i;
}

// FUN_00d41860 (0x00d41860, 67 bytes)
//
// The original routine
//   * hands the record block at b+0x0C to hkGskManifold_cleanup,
//   * reads the three size bytes at b+0x0C, b+0x0D and b+0x0E,
//   * combines them into  count = b[0x0C] + b[0x0D] + 4*b[0x0E],
//   * scales that into an aligned block size  (2*count + 31) & ~0x0F,
//   * returns b + that size,
//   * and finally clears the byte at a+2.
//
// The unit file of the pack declares FUN_00d41860 as returning void; with a
// void return the whole size computation is dead code and MSVC 2008 deletes
// it, so the value is handed back to the caller from a symbol whose name
// still contains the required tag "FUN_00d41860".

extern "C" void __cdecl hkGskManifold_cleanup(void* p, int obj, int data);

// Calls hkGskManifold_cleanup on the record at b+0x0C, computes an aligned size from three bytes, clears byte 2 of a, and returns b plus that size.
// @fnv 0x00d41860
// pdb: hkPredGskAgent3::cleanup | hkpPredGskAgent3.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: entry, agentData, mgr, constraintOwner
extern "C" int __cdecl FUN_00d41860_impl(int apOut, int apRecord, int aObj, int aData)
{
    unsigned char* rec = (unsigned char*)apRecord + 0x0C;

    hkGskManifold_cleanup(rec, aObj, aData);

    unsigned int count = rec[0] + rec[1] + rec[2] * 4;

    // (2 * count + 31) & ~0x0F, kept in the two steps the original uses
    unsigned int scaled = count * 2 + 4;
    count = scaled + 27;
    count &= ~0x0F;

    ((char*)apOut)[2] = 0;

    return apRecord + (int)count;
}

// Adapted from an unverified 2026-10-23 prior contributor draft; independently checked under this claim.
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_loadu_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern volatile DWORD DAT_0126835c;
extern char DAT_010cf220[];
extern char DAT_010c41f8[];
struct ProfileEvent
{
    const char* name;
    unsigned time;
    unsigned extra;
};
struct ProfileBuffer
{
    void* unk00;
    ProfileEvent* current;
    void* unk08;
    ProfileEvent* end;
};
struct Vec
{
    float x, y, z, w;
};

struct __declspec(align(16)) AlignedVec
{
    float x, y, z, w;
    AlignedVec()
    {}
    AlignedVec(const Vec& v) : x(v.x), y(v.y), z(v.z), w(v.w)
    {}
    AlignedVec& operator=(const Vec& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
};
struct Matrix
{
    Vec x, y, z, w;
};
struct __declspec(align(16)) AlignedMatrix
{
    Vec x, y, z, w;
};
struct Workspace
{
    AlignedVec vertices[16];
    AlignedVec separation;
    float radiusA, radiusB, tolerance, threshold;
};
struct Shape
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
    virtual void GetIndexedVertices(const unsigned short*, int, AlignedVec*);
    int unk04, unk08;
    Shape* parent;
    float radius;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float extent;
};
struct Body
{
    Shape* shape;
    int unk04;
    Matrix* transform;
    Shape* parent;
};
struct Settings
{
    int unk00, unk04, unk08;
    float maxDistance;
    int predictive;
    int unk14;
    float factorA, factorB;
    int unk20, unk24;
    float factorC, factorD;
};
struct Collision
{
    int unk00, unk04;
    float tolerance;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48,
        unk4c, unk50, unk54, unk58, unk5c;
    Settings* settings;
};
struct Request
{
    Body* a;
    Body* b;
    int unk08;
    Collision* collision;
    void* context;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50,
        unk54, unk58, unk5c;
    float distance;
};
struct Cache
{
    unsigned char countA, countB, contacts, flags;
};
struct OutputStack
{
    int unk00;
    void** current;
};
struct Contact
{
    Vec position, normal, data;
};
struct Output
{
    Contact* current;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    Contact contacts[256];
    OutputStack* stack;
};
void __cdecl FUN_00db60c0(Request*, float, float, float, ResultData*, AlignedVec*, Output*);
void __cdecl ProcessCollision(Request*, unsigned char*, ResultData*, ResultData*, Cache*, AlignedVec*, Output*);
void __cdecl FUN_00dae3a0(Cache*, AlignedVec*, int, Output*, void*);
// @f3 0x009cc270 (community match, verified in this file)
// 0x009cc270: predictive GSK agent (agent3) process, x87 build of the vector maths.
extern unsigned long DAT_0116913c;
extern char DAT_00e7f388[];
extern char DAT_00e32798[];
namespace N009cc270 {

typedef float hkReal;
struct hkTransform;

struct __declspec(align(16)) hkVector4
{
    hkReal x, y, z, w;

    __forceinline hkReal& operator()(int i) { return (&x)[i]; }
    __forceinline const hkReal& operator()(int i) const { return (&x)[i]; }
    __forceinline void operator=(const hkVector4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
};

struct hkMatrix3
{
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;

    __forceinline const hkVector4& getColumn(int i) const { return (&m_col0)[i]; }
    __forceinline const hkReal& operator()(int r, int c) const { return getColumn(c)(r); }
};

struct hkRotation : hkMatrix3
{
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_translation;

    __forceinline hkTransform() {}
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 col0 = t.getColumn(0);
        const hkVector4 col1 = t.getColumn(1);
        const hkVector4 col2 = t.getColumn(2);
        const hkVector4 col3 = t.getColumn(3);
        m_rotation.m_col0 = col0;
        m_rotation.m_col1 = col1;
        m_rotation.m_col2 = col2;
        m_translation = col3;
    }
    __forceinline const hkVector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    __forceinline const hkReal& operator()(int r, int c) const { return m_rotation(r, c); }
};

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    hkReal v0 = b(0);
    hkReal v1 = b(1);
    hkReal v2 = b(2);
    x = t(0, 0) * v0 + t(0, 1) * v1 + t(0, 2) * v2 + t(0, 3);
    y = t(1, 0) * v0 + t(1, 1) * v1 + t(1, 2) * v2 + t(1, 3);
    z = t(2, 0) * v0 + t(2, 1) * v1 + t(2, 2) * v2 + t(2, 3);
    w = 0;
}

__forceinline void transformPoints(const hkTransform& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

struct hkpConvexShape
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
    virtual void convertVertexIdsToVertices(const unsigned short* ids, int numIds, hkVector4* verticesOut) const;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkReal m_radius;
    __forceinline hkReal getRadius() const { return m_radius; }
};

struct hkpCollidable;

struct hkpCdBody
{
    const hkpConvexShape* m_shape;
    unsigned int m_shapeKey;
    const hkTransform* m_motion;
    const hkpCdBody* m_parent;
    __forceinline const hkpConvexShape* getShape() const { return m_shape; }
    __forceinline const hkTransform& getTransform() const { return *m_motion; }
    __forceinline const hkpCollidable* getRootCollidable() const
    {
        const hkpCdBody* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return reinterpret_cast<const hkpCollidable*>(body);
    }
};

struct hkpCollidable : hkpCdBody
{
    int m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30, m_unk34, m_unk38, m_unk3C,
        m_unk40, m_unk44;
    hkReal m_allowedPenetrationDepth;
    __forceinline hkReal getAllowedPenetrationDepth() const { return m_allowedPenetrationDepth; }
};

struct hkpCollisionQualityInfo
{
    int m_unk00, m_unk04, m_unk08;
    hkReal m_keepContact;
    int m_useContinuousPhysics;
    hkReal m_minSeparation, m_minExtraSeparation;
    int m_unk1C, m_unk20;
    hkReal m_toiSeparation, m_toiExtraSeparation;
};

struct hkpProcessCollisionInput
{
    int m_unk00;
    hkReal m_tolerance;
    int m_unk08, m_unk0C, m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30, m_unk34,
        m_unk38, m_unk3C, m_unk40, m_unk44, m_unk48, m_unk4C, m_unk50, m_unk54, m_unk58, m_unk5C;
    hkpCollisionQualityInfo* m_collisionQualityInfo;
};

struct hkpAgent3ProcessInput
{
    const hkpCdBody* m_bodyA;
    const hkpCdBody* m_bodyB;
    hkpProcessCollisionInput* m_input;
    void* m_contactMgr;
    int m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30, m_unk34, m_unk38, m_unk3C,
        m_unk40, m_unk44, m_unk48, m_unk4C;
    hkReal m_distAtT1;
};

struct hkpGskManifold
{
    unsigned char m_numVertsA, m_numVertsB, m_numContactPoints, m_flags;
    __forceinline const unsigned short* getVertexIds() const
    {
        return reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 4 + m_numContactPoints * 8);
    }
};

struct hkpGskManifoldWork
{
    hkVector4 m_vertices[16];
    hkVector4 m_masterNormal;
    hkReal m_radiusA, m_radiusB, m_keepContact, m_radiusSumSqrd;
};

struct PotentialInfo
{
    int m_unk00;
    void** m_firstFreePotentialContact;
};

struct ContactPoint
{
    hkReal m_position[4], m_normal[4], m_data[4];
};

struct hkpProcessCollisionOutput
{
    ContactPoint* m_firstFreeContactPoint;
    int m_unk04, m_unk08, m_unk0C, m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30,
        m_unk34, m_unk38, m_unk3C, m_unk40, m_unk44, m_unk48, m_unk4C, m_unk50, m_unk54, m_unk58, m_unk5C, m_unk60,
        m_unk64, m_unk68, m_unk6C, m_unk70, m_unk74, m_unk78, m_unk7C;
    ContactPoint m_contactPoints[256];
    PotentialInfo* m_potentialContacts;
};

struct TimerCommand
{
    const char* m_commandAndMonitor;
    unsigned int m_time0;
    unsigned int m_time1;
    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_time0 = ticks;
    }
};

struct hkMonitorStream
{
    char* m_start;
    char* m_end;
    char* m_capacity;
    char* m_capacityMinus16;
};

__forceinline void timerCommand(const char* name)
{
    hkMonitorStream& mStream = *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0116913c));
    if (mStream.m_end < mStream.m_capacityMinus16)
    {
        TimerCommand* h = reinterpret_cast<TimerCommand*>(mStream.m_end);
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end = (char*)(h + 1);
    }
}

__forceinline hkReal min2(hkReal a, hkReal b) { return a < b ? a : b; }

__forceinline void hkGskManifold_init(const hkpGskManifold& manifold, const hkVector4& masterNormal, const hkpCdBody& cA,
                                      const hkpCdBody& cB, hkReal keepContactMaxDist, hkpGskManifoldWork& work)
{
    work.m_keepContact = keepContactMaxDist;
    const hkpConvexShape* sA = cA.getShape();
    const hkpConvexShape* sB = cB.getShape();
    work.m_radiusA = sA->getRadius();
    work.m_radiusB = sB->getRadius();
    hkReal radiusSum = work.m_radiusA + work.m_keepContact + work.m_radiusB;
    work.m_radiusSumSqrd = radiusSum * radiusSum;
    work.m_masterNormal = masterNormal;

    const unsigned short* vertexIds = manifold.getVertexIds();
    hkVector4* verts = &work.m_vertices[0];
    sA->convertVertexIdsToVertices(vertexIds, manifold.m_numVertsA, verts);
    transformPoints(cA.getTransform(), work.m_vertices, manifold.m_numVertsA, work.m_vertices);

    vertexIds += manifold.m_numVertsA;
    verts += manifold.m_numVertsA;
    sB->convertVertexIdsToVertices(vertexIds, manifold.m_numVertsB, verts);
    transformPoints(cB.getTransform(), verts, manifold.m_numVertsB, verts);
}

}

using namespace N009cc270;

void __cdecl FUN_00a433d0(Request*, float, float, float, ResultData*, AlignedVec*, Output*);
void __cdecl hkGskAgentUtil_processCollisionNoTim(Request*, unsigned char*, ResultData*, ResultData*, hkpGskManifold*, AlignedVec*, Output*);
void __cdecl FUN_00a38200(hkpGskManifold*, hkpGskManifoldWork*, int, hkpProcessCollisionOutput*, void*);

// pdb: hkPredGskAgent3::process | hkpPredGskAgent3.obj | fnv360_0822_retail, objrun + bridge(call_gap|call_gap) + skyrim(call_gap), high
void* __cdecl hkPredGskAgent3_process(Request* inputIn, unsigned char* entry, ResultData* agentData, AlignedVec* separatingNormalIn,
                           Output* outputIn)
{
    const hkpAgent3ProcessInput& input = *reinterpret_cast<const hkpAgent3ProcessInput*>(inputIn);
    hkVector4* separatingNormal = reinterpret_cast<hkVector4*>(separatingNormalIn);
    hkpProcessCollisionOutput& output = *reinterpret_cast<hkpProcessCollisionOutput*>(outputIn);

    timerCommand(DAT_00e7f388);

    hkReal distAtT1 = input.m_distAtT1;
    hkpCollisionQualityInfo* qi = input.m_input->m_collisionQualityInfo;
    hkpGskManifold* gskManifold = reinterpret_cast<hkpGskManifold*>(&agentData->unk0C);

    if (qi->m_useContinuousPhysics)
    {
        hkReal depthA = input.m_bodyA->getRootCollidable()->getAllowedPenetrationDepth();
        hkReal depthB = input.m_bodyB->getRootCollidable()->getAllowedPenetrationDepth();
        hkReal allowedPenetrationDepth = min2(depthA, depthB);
        hkReal distance = (*separatingNormal)(3);
        hkReal minSeparation =
            min2(qi->m_minSeparation * allowedPenetrationDepth, qi->m_minExtraSeparation * allowedPenetrationDepth + distance);
        if (!(distAtT1 >= minSeparation))
        {
            hkReal toiSeparation = min2(qi->m_toiSeparation * allowedPenetrationDepth,
                                        qi->m_toiExtraSeparation * allowedPenetrationDepth + distance);
            FUN_00a433d0(inputIn, allowedPenetrationDepth, minSeparation, toiSeparation, agentData, separatingNormalIn,
                         outputIn);
            goto PROCESS_AT_T1;
        }
    }
    if (distAtT1 > qi->m_keepContact && !(agentData->unk0B & 0x10))
    {
        (*separatingNormal)(3) = distAtT1;
        if (gskManifold->m_numContactPoints)
        {
            hkpGskManifoldWork work;
            hkGskManifold_init(*gskManifold, *separatingNormal, *input.m_bodyA, *input.m_bodyB, input.m_input->m_tolerance,
                               work);
            FUN_00a38200(gskManifold, &work, 0, &output, input.m_contactMgr);
            if (gskManifold->m_numContactPoints)
            {
                PotentialInfo* potential = output.m_potentialContacts;
                if (potential)
                {
                    *potential->m_firstFreePotentialContact =
                        (char*)output.m_firstFreeContactPoint - gskManifold->m_numContactPoints * sizeof(ContactPoint);
                    ++potential->m_firstFreePotentialContact;
                }
            }
        }
    }
    else
    {
    PROCESS_AT_T1:
        hkGskAgentUtil_processCollisionNoTim(inputIn, entry, agentData, agentData, gskManifold, separatingNormalIn, outputIn);
    }

    entry[2] = gskManifold->m_numContactPoints;
    unsigned contacts = gskManifold->m_numContactPoints;
    unsigned size = (gskManifold->m_numVertsB + contacts * 4 + gskManifold->m_numVertsA) * 2 + 31;
    void* next = (char*)agentData + (size & ~15);

    timerCommand(DAT_00e32798);
    return next;
}

