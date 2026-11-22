#include "f3_common.h"
// src/havok/animation/ragdoll/utils/hkaragdollutils_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    int __cdecl FUN_00ce9e90(void*);
}

struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};
struct Obj
{
    char pad0[0xc];
    Inner* inner;
};
struct hkErrStream
{
    void* p1;
    void* p2;
    void* p3;
    hkErrStream(void* buf, int size) throw();
    ~hkErrStream() throw();
    hkErrStream& operator<<(const char* str) throw();
};
struct hkError
{
    virtual ~hkError() throw();
    virtual void unk0();
    virtual void unk1();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern hkError* DAT_01268360;
static bool _isConstraintSupported(Obj* obj, bool reportError) throw();

struct Builder390
{
    unsigned int unk00, unk04, unk08;
    void FUN_00cb1600(void*, int);
    void FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct Constraint390
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType();
    unsigned int unk04;
    unsigned int unk08;
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
};
struct Owner390
{
    unsigned int unk00, unk04, unk08;
    Constraint390* data;
};
// @f3 0x0095e4d0 (community match, verified in this file)
// hkaRagdollUtils: returns the constraint data's pivot/transform block by
// constraint type (FNV twin FUN_00ce9cf0). The project's Constraint390 has
// GetType in the wrong vtable slot (0x20; the code calls +0x10), so the data is
// read through a view of our own instead of redefining the shared class.
// Only names declared before FUN_00ce9cf0 in the project file are used.

struct RagdollConstraintView0095e4d0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned int GetType();
    unsigned int unk04;
    unsigned int unk08;
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
};

static __declspec(noinline) void* FUN_00ce9cf0(Owner390* owner)
{
    RagdollConstraintView0095e4d0* data = (RagdollConstraintView0095e4d0*)owner->data;
    switch (data->GetType())
    {
    case 0:
        return &data->unk30;
    case 1:
        return &data->unk90;
    case 2:
        return &data->unk90;
    case 6:
        return &data->unk90;
    case 7:
        return &data->unk90;
    case 8:
        return &data->unk20;
    case 3:
    case 4:
    case 5:
    default: {
        char message[512];
        Builder390 stream;
        stream.FUN_00cb1600(message, sizeof(message));
        stream.FUN_00cc01c0("Unsupported type of constraint in rag doll.");
        DAT_01268360->message(1, 0xabbabf3b, message, ".\\Utils\\hkaRagdollUtils.cpp", 229);
        stream.FUN_00cc00e0();
        return 0;
    }
    }
}

volatile Owner390* g_owner_0095e4d0;
volatile void* g_data_0095e4d0;
void caller_of_FUN_0095e4d0()
{
    g_data_0095e4d0 = FUN_00ce9cf0((Owner390*)g_owner_0095e4d0);
}

void* ConstraintData390(Owner390* owner)
{
    return FUN_00ce9cf0(owner);
}

#include <xmmintrin.h>
__declspec(align(16)) struct Vec4
{
    int x;
    int y;
    int z;
    int w;
};

struct Target
{
    void FUN_00c7f690(void* where, Vec4* v);
};

struct Body : public Obj
{
    int unk10;
    char* shape;
    char* owner;
};

struct List
{
    Body** items;
    int count;
};

// pdb: _isConstraintSupported | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap, high (was: IsSupportedRagdollConstraint)
static __declspec(noinline) bool _isConstraintSupported(Obj* obj, bool reportError) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return true;
    if (reportError)
    {
        DAT_01268360->message(1, 0, 0, 0, 0);
    }
    return false;
}

// pdb: _accessConstraintPivotA | hkaRagdollUtils.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_gap) + skyrim(call_seq), high
static __declspec(noinline) Vec4* _accessConstraintPivotA(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (Vec4*)((char*)inner + 0x20);
    return 0;
}

static __declspec(noinline) Target* FUN_00ce9cf0(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (Target*)((char*)inner + 0x30);
    return 0;
}

// @f3 0x0095e690 (community match, verified in this file)
struct InnerX
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual int getSomething();
};

struct TargetX
{
    void FUN_008d2970(void* where, Vec4* v);
};

struct StreamX
{
    void* p1;
    void* p2;
    void* p3;
    void FUN_00923070(void* buf, int size);
    void FUN_00943710(const char* str);
    void FUN_00943a60();
};

static __declspec(noinline) bool FUN_0095e380(Obj* obj, bool reportError) throw();
static __declspec(noinline) Vec4* FUN_0095e420(Obj* obj) throw();
static __declspec(noinline) TargetX* FUN_0095e4d0(Obj* obj) throw();

extern hkError* DAT_010f3364;
extern const char DAT_00e7c21c[];
extern const char DAT_00e7c1a8[];

// pdb: alignConstraintSpacesToChildren | hkaRagdollUtils.obj | fnv360_0822_retail, ustr, high
extern "C" int __cdecl FUN_00ce9e90(void* p)
{
    List* list = (List*)p;
    int count = list->count;
    for (int i = 0; i < count; i++)
    {
        Body* b = list->items[i];
        if (FUN_0095e380(b, true))
        {
            char* shape = b->shape;
            Vec4 v = *(Vec4*)(shape + 0x110);
            char* owner = b->owner;
            Vec4* vel = FUN_0095e420(b);
            float* f = (float*)vel;
            f[0] = f[1] = f[2] = f[3] = 0.0f;
            TargetX* target = FUN_0095e4d0(b);
            target->FUN_008d2970(owner + 0xe0, &v);
        }
        if (((InnerX*)b->inner)->getSomething() == 8)
        {
            int buf[0x80];
            StreamX stream;
            stream.FUN_00923070(buf, 0x200);
            stream.FUN_00943710(DAT_00e7c21c);
            DAT_010f3364->message(1, 0xabba876d, (const char*)buf,
                                  DAT_00e7c1a8, 0x134);
            stream.FUN_00943a60();
        }
    }
    return 0;
}

static __declspec(noinline) Vec4* FUN_0095e420(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (Vec4*)((char*)inner + 0x20);
    return 0;
}

static __declspec(noinline) TargetX* FUN_0095e4d0(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (TargetX*)((char*)inner + 0x30);
    return 0;
}

static __declspec(noinline) bool FUN_0095e380(Obj* obj, bool reportError) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return true;
    if (reportError)
    {
        DAT_010f3364->message(1, 0, 0, 0, 0);
    }
    return false;
}

