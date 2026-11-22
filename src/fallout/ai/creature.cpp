// fallout/ai/creature.cpp: Creature, Holder, XActorQ (1 function)
#include "f3_common.h"
#include "creature_decls.h"

namespace ActorValue {
enum Index
{
};
}

struct NiFixedString;

struct NiFixedString;

struct S008d48a0
{
    int FUN_008d4a80(int, int);
    void FUN_008806d0(int);
    void FUN_008d48a0(int, int);
};
// Calls FUN_008d4a80 with a and b, then passes the result to FUN_008806d0.
// @f3 0x005c35d0 (community match, verified in this file)
struct Factory {
    void* FUN_00433ff0(int first, int second);
};
extern Factory* DAT_0107a0d8;
struct SetupMember {
    void FUN_005c41f0(void* value);
};
void S008d48a0::FUN_008d48a0(int first, int second) {
    *(unsigned int*)this = 0;
    void* value = DAT_0107a0d8->FUN_00433ff0(first, second);
    ((SetupMember*)((char*)this + 4))->FUN_005c41f0(value);
}


struct TESActorBase
{
    virtual ~TESActorBase();
};
struct XActor
{
    TESActorBase* GetActorBase();
};

struct Holder
{
    int FUN_008d4a80(int, float, Actor*);
};

namespace fnv_008d4990 {
struct Holder
{
    int FUN_008d4a80(int, float, int);
};
}  // namespace fnv_008d4990

namespace fnv_008d49c0 {
struct Holder
{
    int FUN_008d4a80(int, int, int);
    int FUN_00880fb0(int);
    void FUN_008d49c0(int, int, int);
};
}  // namespace fnv_008d49c0

namespace fnv_008d49f0 {
struct Holder
{
    int FUN_008d4a80(int, float, void*);
    void ApplyActorValueDelta(int);
    void FUN_008d49f0(int, float, void*);
};
}  // namespace fnv_008d49f0

namespace fnv_008c50f0 {
extern double _gModifierZero;

struct ShellH
{
    void FUN_00422750(bool, float);
};

struct XActor
{
    ShellH* GetExtra() const;
};

}  // namespace fnv_008c50f0

extern double _gModifierZero;

struct FUN_0087d880_class
{
    float NiD3DShaderDeclaration_Pack_UnsignedByteToFloat();
};

struct SubA4
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual float vfunc_10(int av);
    virtual float vfunc_14(int av);
    virtual float vfunc_18(int av);
};

namespace fnv_008d4db0 {
extern double _gModifierZero;

struct FUN_0087d880_class
{
    float NiD3DShaderDeclaration_Pack_UnsignedByteToFloat();
};

struct SubA4
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual float vfunc_14(int av);
    virtual float vfunc_18(int av);
};

}  // namespace fnv_008d4db0
