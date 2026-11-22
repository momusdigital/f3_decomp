#include "f3_common.h"
// src/havok/physics/dynamics/world/util/hkpworldconstraintutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldconstraintutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d27820_Node;
struct S_00d27820_Buf
{
    char* data;
    int size;
};
struct S_00d27820_Rec
{
    S_00d27820_Node* link[3];
    int unk0c, unk10;
    unsigned short px, py, pz;
    unsigned char idx;
    int cnt;
    unsigned short sz;
    unsigned short slot;
    int unk24, unk28, unk2c;
};
struct S_00d27820_Arr
{
    struct S_00d27820_Node** data;
    int count;
};
struct S_00d27820_Node
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00d27820_Rec* unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    S_00d27820_Rec* unkac;
    unsigned short unkb0;
    unsigned short unkb2;
    S_00d27820_Arr arr;
    int unkbc;
    S_00d27820_Buf buf;
};
struct S_00d27820_Vec
{
    int unk00, x, y, z;
    S_00d27820_Vec& Sub(unsigned a, unsigned b, unsigned c)
    {
        x -= a;
        y -= b;
        z -= c;
        return *this;
    }
};
struct S_00d27820_A
{
    int unk00, unk04;
    S_00d27820_Vec vec;
    int unk18;
    int cnt;
    int unk20;
    unsigned char unk24;
    unsigned char flags;
};
struct S_00d27820_P
{
    int unk00, unk04;
    S_00d27820_A* unk08;
    int unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00d27820_Rec* unk30;
    void FUN_00c905b0();
};
void __cdecl FUN_00cb1270(int a, int b, char* c);

// Removes the record p->unk30 from its node lists, shifts the following records down, adjusts buffer sizes and counts, and calls FUN_00c905b0.
// @f3 0x009a9220 (community match, verified in this file)
void __cdecl FUN_009234f0(int a, int b, char* c);

/* Local view of the record / node pair, offsets taken from the assembly. */
struct RRec;
struct RNode;

struct RArr
{
    RNode** data;
    int count;
};

struct RBuf
{
    char* data;
    int size;
};

struct RNode
{
    int unk00[0x28 / 4];                 /* 0x00 */
    RRec* rec;                           /* 0x28 */
    int unk2c[(0x98 - 0x2c) / 4];        /* 0x2c */
    RRec* list;                          /* 0x98 */
    unsigned short listCount;            /* 0x9c */
    unsigned short unk9e;                /* 0x9e */
    RArr arr;                            /* 0xa0 */
    int unkA8;                           /* 0xa8 */
    RBuf buf;                            /* 0xac */
};

struct RRec
{
    RNode* link[3];                      /* 0x00 */
    int unk0c;                           /* 0x0c */
    int unk10;                           /* 0x10 */
    unsigned short px;                   /* 0x14 */
    unsigned short py;                   /* 0x16 */
    unsigned short pz;                   /* 0x18 */
    unsigned char idx;                   /* 0x1a */
    int cnt;                             /* 0x1c */
    unsigned short sz;                   /* 0x20 */
    unsigned short slot;                 /* 0x22 */
    int unk24;                           /* 0x24 */
    RRec* unk28;                         /* 0x28 */
    int unk2c;                           /* 0x2c */
};

struct RP
{
    void** vtbl;                         /* 0x00 */
    unsigned short unk04;                /* 0x04 */
    short unk06;                         /* 0x06 */
    S_00d27820_A* a;                     /* 0x08 */
    int unk0c[(0x28 - 0x0c) / 4];        /* 0x0c */
    RRec* rec;                           /* 0x28 */
};

// pdb: hkpWorldConstraintUtil::removeConstraint | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_gap, high
// pdb params: constraint
// pdb: hkpWorldConstraintUtil::removeConstraint | hkpWorldConstraintUtil.obj | fnv360_0822_retail, call_gap, high (was: DetachRecord)
void hkpWorldConstraintUtil_removeConstraint(S_00d27820_P* pp)
{
    RP* p = (RP*)pp;
    RRec* pRec = p->rec;
    S_00d27820_A* a = p->a;
    a->flags = (a->flags & ~2) | 1;
    unsigned px = pRec->px;
    unsigned py = pRec->py;
    unsigned pz = pRec->pz;
    if (p->rec)
    {
        S_00d27820_A* a2 = p->a;
        a2->vec.Sub(px, py, pz);
        RRec* pRec2 = p->rec;
        pRec2->py -= py;
        pRec2->pz -= pz;
        pRec2->px -= px;
    }
    a->cnt--;
    p->a = 0;

    RNode* c = pRec->link[2 - pRec->idx];
    unsigned short slot = pRec->slot;
    RArr* arr = &c->arr;
    RNode** data = arr->data;
    RNode* pLastNode = data[arr->count - 1];
    data[slot] = pLastNode;
    arr->count--;
    pLastNode->rec->slot = slot;

    RNode* d = pRec->link[pRec->idx + 1];
    int delta = 0;
    if (pRec->cnt)
    {
        delta = -(int)pRec->sz;
        int iTotal = pRec->sz + pRec->cnt;
        RBuf* pBuf = &d->buf;
        FUN_009234f0(pRec->cnt, iTotal, pBuf->data + (pBuf->size - iTotal));
        pBuf->size -= pRec->sz;
        pRec->cnt = 0;
    }
    p->rec = 0;

    RRec* pIter = pRec;
    RRec* end = &d->list[d->listCount - 1];
    while (pIter < end)
    {
        *pIter = pIter[1];
        pIter->link[0]->rec = pIter;
        pIter->cnt = pIter->cnt ? pIter->cnt + delta : 0;
        pIter++;
    }
    d->listCount--;

    if (p->unk04)
    {
        if (--p->unk06 == 0)
            ((void (__thiscall*)(void*, int))p->vtbl[0])(p, 1);
    }
}


typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

struct hkpConstraintAtom
{
    hkUint16 m_type;
    hkUint16 unk02;
    int unk04;
    int unk08;
    int unk0C;
};

struct GenericConstraintAtomScheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;

    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
};

struct hkpConstraintDataInfo : GenericConstraintAtomScheme
{
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

struct hkpModifierConstraintAtom : hkpConstraintAtom
{
    hkUint16 m_usModifierAtomSize;
    hkUint16 m_iChildSize;
    hkpConstraintAtom* m_pChildAtom;

    int FUN_00d22090(GenericConstraintAtomScheme& infoOut, hkUint8& usedFlagsOut);
};

struct hkpConstraintData
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;
};

struct hkpEntity
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
    hkUint16 unkD0;
    hkUint8 m_ucResponseModifierFlags;
};

struct ConstraintRuntimeInfo
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintAtom* m_kBridgeAtoms;
    hkUint16 m_iAtomsSize;
    hkUint8 m_ucCallbackRequest;
    hkUint8 unk13;
    hkUint16 m_iSchemaByteSize;
};

struct hkpConstraintInstance;

struct hkpConstraintOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void checkAccessRw();

    int unk04;
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;

    void hkpConstraintOwner_addConstraintInfo(hkpConstraintInstance* constraint, GenericConstraintAtomScheme& delta);
};

struct hkpConstraintInstance
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintData* m_data;
    hkpModifierConstraintAtom* m_pConstraintModifier;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    ConstraintRuntimeInfo* m_pConstraintInternal;
};

extern const hkUint16 DAT_010cb7a8[];

hkpModifierConstraintAtom* __cdecl FUN_00d277f0(hkpConstraintInstance* instance);

// Splices newModifier into the modifier atom chain of instance, updating child pointers and accumulating solver stats on the owner.
// @f3 0x009a9550 (community match, verified in this file)
struct hkpConstraintInstanceF3
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintData* m_data;
    hkpModifierConstraintAtom* m_pConstraintModifier;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    ConstraintRuntimeInfo* m_pConstraintInternal;
};

struct hkpModifierConstraintAtomF3 : hkpModifierConstraintAtom
{
    int FUN_00d22090(GenericConstraintAtomScheme& infoOut);
};

struct hkpConstraintDataF3
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
    virtual void v0A();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;
};

void __cdecl FUN_00d27960(hkpConstraintInstance* instance, hkpConstraintOwner& constraintOwner,
                          hkpModifierConstraintAtom* newModifier)
{
    constraintOwner.checkAccessRw();

    hkpConstraintInstanceF3* instanceData = (hkpConstraintInstanceF3*)instance;
    hkpModifierConstraintAtom* lastModifier = FUN_00d277f0(instance);
    ConstraintRuntimeInfo* pConstraintInternal = instanceData->m_pConstraintInternal;

    if (newModifier->m_type == 0x1a && lastModifier)
    {
        newModifier->m_pChildAtom = lastModifier->m_pChildAtom;
        newModifier->m_iChildSize = lastModifier->m_iChildSize;
        lastModifier->m_pChildAtom = newModifier;
        lastModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else if (instanceData->m_pConstraintModifier && instanceData->m_pConstraintModifier->m_type == 0x1b)
    {
        newModifier->m_pChildAtom = instanceData->m_pConstraintModifier->m_pChildAtom;
        newModifier->m_iChildSize = instanceData->m_pConstraintModifier->m_iChildSize;
        instanceData->m_pConstraintModifier->m_pChildAtom = newModifier;
        instanceData->m_pConstraintModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else
    {
        instanceData->m_pConstraintModifier = newModifier;
        if (pConstraintInternal)
        {
            newModifier->m_pChildAtom = pConstraintInternal->m_kBridgeAtoms;
            newModifier->m_iChildSize = pConstraintInternal->m_iAtomsSize;
            pConstraintInternal->m_kBridgeAtoms = newModifier;
            pConstraintInternal->m_iAtomsSize = newModifier->m_usModifierAtomSize;
        }
        else
        {
            hkpConstraintDataInfo info;
            ((hkpConstraintDataF3*)instanceData->m_data)->PopulateInfo(info);
            newModifier->m_pChildAtom = info.m_kBridgeAtoms;
            newModifier->m_iChildSize = (hkUint16)info.m_usSizeOfAllAtoms;
        }
    }

    if (pConstraintInternal)
    {
        GenericConstraintAtomScheme info;
        info.clear();
        int callbackRequest = ((hkpModifierConstraintAtomF3*)newModifier)->FUN_00d22090(info);
        constraintOwner.hkpConstraintOwner_addConstraintInfo(instance, info);
        ConstraintRuntimeInfo* internal = instanceData->m_pConstraintInternal;
        if (internal)
            internal->m_ucCallbackRequest |= (hkUint8)callbackRequest;
    }
}


namespace fnv_00d27ac0 {
struct Entity;
struct Constraint;
struct Atom
{
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
};
struct ConstraintInfo
{
    unsigned int unk00;
    unsigned int runtimeBytes;
    unsigned int unk08, unk0c;
    Atom* atoms;
    unsigned short atomSize;
};
struct RuntimeInfo
{
    unsigned int size;
    unsigned int unk04;
};
struct ConstraintData
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void GetRuntimeInfo(unsigned int, RuntimeInfo*);
    virtual void slot28();
    virtual void AddInstance(Constraint*, void*, unsigned int);
    virtual void slot30();
    virtual unsigned char* WantsRuntime(unsigned char*);
    virtual void slot38();
    virtual void GetConstraintInfo(ConstraintInfo*);
};
struct __declspec(align(16)) ConstraintInternal
{
    Constraint* constraint;
    Entity* bodies[2];
    Atom* atoms;
    unsigned short atomSize;
    unsigned char flags;
    unsigned char priority;
    unsigned short unk14, unk16, unk18;
    unsigned char masterIndex;
    unsigned char callbacks;
    char* runtime;
    unsigned short runtimeSize;
    unsigned short slaveIndex;
    unsigned int unk24, unk28, unk2c;
};
struct InternalArray
{
    ConstraintInternal* data;
    unsigned short size;
    unsigned short capacity;
    void FUN_00d27f50(int, ConstraintInternal*);
};
struct ConstraintPointer
{
    Constraint* value;
    __forceinline void Set(Constraint* x)
    {
        value = x;
    }
};
struct ConstraintArray
{
    ConstraintPointer* data;
    int size;
    unsigned int capacity;
};
struct ByteArray
{
    char* data;
    unsigned int size;
    unsigned int capacity;
};
struct Island
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, count;
    void hkpConstraintOwner_addConstraintInfo(Constraint*, ConstraintInfo*);
};
struct Entity
{
    unsigned int unk00;
    unsigned int unk04;
    void* world;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
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
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    InternalArray constraints;
    ConstraintArray slaves;
    ByteArray runtime;
    Island* island;
    unsigned short unkD0;
    unsigned char responseFlags;
    unsigned char unkD3;
    unsigned int uid;
    unsigned int unkD8, unkDC, unkE0, unkE4;
    unsigned char motionType;
};
struct Constraint
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void* GetInternal();
    unsigned int unk04;
    Island* island;
    ConstraintData* data;
    Atom* atoms;
    Entity* bodies[2];
    unsigned char priority;
    unsigned char wantRuntime;
    unsigned short unk1e;
    unsigned int unk20, unk24, unk28, unk2c;
    ConstraintInternal* internal;
    unsigned int uid;
    void FUN_00c90510();
};
extern unsigned short DAT_010cb7a8[];
void FUN_00cb1270(void*, const void*, int);
}  // namespace fnv_00d27ac0
