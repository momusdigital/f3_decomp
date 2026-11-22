#include <new>
// src/f3staging/f3iso_007e3780_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x007e3780 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x007e3780 (community match, verified in this file)
#include <math.h>
namespace native2108 {
struct P3Update { float x, y, z; P3Update() {} P3Update Difference(const P3Update& rhs) const { P3Update d; d.x=x-rhs.x; d.y=y-rhs.y; d.z=z-rhs.z; return d; } };
struct UpdateActor {
    virtual void UnkVirtual000();
    virtual void UnkVirtual004();
    virtual void UnkVirtual008();
    virtual void UnkVirtual00C();
    virtual void UnkVirtual010();
    virtual void UnkVirtual014();
    virtual void UnkVirtual018();
    virtual void UnkVirtual01C();
    virtual void UnkVirtual020();
    virtual void UnkVirtual024();
    virtual void UnkVirtual028();
    virtual void UnkVirtual02C();
    virtual void UnkVirtual030();
    virtual void UnkVirtual034();
    virtual void UnkVirtual038();
    virtual void UnkVirtual03C();
    virtual void UnkVirtual040();
    virtual void UnkVirtual044();
    virtual void UnkVirtual048();
    virtual void UnkVirtual04C();
    virtual void UnkVirtual050();
    virtual void UnkVirtual054();
    virtual void UnkVirtual058();
    virtual void UnkVirtual05C();
    virtual void UnkVirtual060();
    virtual void UnkVirtual064();
    virtual void UnkVirtual068();
    virtual void UnkVirtual06C();
    virtual void UnkVirtual070();
    virtual void UnkVirtual074();
    virtual void UnkVirtual078();
    virtual void UnkVirtual07C();
    virtual void UnkVirtual080();
    virtual void UnkVirtual084();
    virtual void UnkVirtual088();
    virtual void UnkVirtual08C();
    virtual void UnkVirtual090();
    virtual void UnkVirtual094();
    virtual void UnkVirtual098();
    virtual void UnkVirtual09C();
    virtual void UnkVirtual0A0();
    virtual void UnkVirtual0A4();
    virtual void UnkVirtual0A8();
    virtual void UnkVirtual0AC();
    virtual void UnkVirtual0B0();
    virtual void UnkVirtual0B4();
    virtual void UnkVirtual0B8();
    virtual void UnkVirtual0BC();
    virtual void UnkVirtual0C0();
    virtual void UnkVirtual0C4();
    virtual void UnkVirtual0C8();
    virtual void UnkVirtual0CC();
    virtual void UnkVirtual0D0();
    virtual void UnkVirtual0D4();
    virtual void UnkVirtual0D8();
    virtual void UnkVirtual0DC();
    virtual void UnkVirtual0E0();
    virtual void UnkVirtual0E4();
    virtual void UnkVirtual0E8();
    virtual void UnkVirtual0EC();
    virtual void UnkVirtual0F0();
    virtual void UnkVirtual0F4();
    virtual void UnkVirtual0F8();
    virtual void UnkVirtual0FC();
    virtual void UnkVirtual100();
    virtual void UnkVirtual104();
    virtual void UnkVirtual108();
    virtual void UnkVirtual10C();
    virtual void UnkVirtual110();
    virtual void UnkVirtual114();
    virtual void UnkVirtual118();
    virtual void UnkVirtual11C();
    virtual void UnkVirtual120();
    virtual void UnkVirtual124();
    virtual void UnkVirtual128();
    virtual void UnkVirtual12C();
    virtual void UnkVirtual130();
    virtual void UnkVirtual134();
    virtual void UnkVirtual138();
    virtual void UnkVirtual13C();
    virtual void UnkVirtual140();
    virtual void UnkVirtual144();
    virtual void UnkVirtual148();
    virtual void UnkVirtual14C();
    virtual void UnkVirtual150();
    virtual void UnkVirtual154();
    virtual void UnkVirtual158();
    virtual void UnkVirtual15C();
    virtual void UnkVirtual160();
    virtual void UnkVirtual164();
    virtual void UnkVirtual168();
    virtual void UnkVirtual16C();
    virtual void UnkVirtual170();
    virtual void UnkVirtual174();
    virtual void UnkVirtual178();
    virtual void UnkVirtual17C();
    virtual void UnkVirtual180();
    virtual void UnkVirtual184();
    virtual void UnkVirtual188();
    virtual void UnkVirtual18C();
    virtual void UnkVirtual190();
    virtual void UnkVirtual194();
    virtual void UnkVirtual198();
    virtual void UnkVirtual19C();
    virtual void UnkVirtual1A0();
    virtual void UnkVirtual1A4();
    virtual void UnkVirtual1A8();
    virtual void UnkVirtual1AC();
    virtual void UnkVirtual1B0();
    virtual void UnkVirtual1B4();
    virtual void UnkVirtual1B8();
    virtual void UnkVirtual1BC();
    virtual void UnkVirtual1C0();
    virtual void UnkVirtual1C4();
    virtual void UnkVirtual1C8();
    virtual void UnkVirtual1CC();
    virtual void UnkVirtual1D0();
    virtual void UnkVirtual1D4();
    virtual void UnkVirtual1D8();
    virtual void UnkVirtual1DC();
    virtual void UnkVirtual1E0();
    virtual void UnkVirtual1E4();
    virtual void UnkVirtual1E8();
    virtual void UnkVirtual1EC();
    virtual void UnkVirtual1F0();
    virtual P3Update& Position();
    virtual void UnkVirtual1F8();
    virtual void UnkVirtual1FC();
    virtual void UnkVirtual200();
    virtual void UnkVirtual204();
    virtual void UnkVirtual208();
    virtual void UnkVirtual20C();
    virtual void UnkVirtual210();
    virtual void UnkVirtual214();
    virtual void UnkVirtual218();
    virtual void UnkVirtual21C();
    virtual void UnkVirtual220();
    virtual void UnkVirtual224();
    virtual void UnkVirtual228();
    virtual void UnkVirtual22C();
    virtual void UnkVirtual230();
    virtual void UnkVirtual234();
    virtual void UnkVirtual238();
    virtual void UnkVirtual23C();
    virtual void UnkVirtual240();
    virtual void UnkVirtual244();
    virtual void UnkVirtual248();
    virtual void UnkVirtual24C();
    virtual void UnkVirtual250();
    virtual void UnkVirtual254();
    virtual void UnkVirtual258();
    virtual void UnkVirtual25C();
    virtual void UnkVirtual260();
    virtual void UnkVirtual264();
    virtual void UnkVirtual268();
    virtual void UnkVirtual26C();
    virtual void UnkVirtual270();
    virtual void UnkVirtual274();
    virtual void UnkVirtual278();
    virtual void UnkVirtual27C();
    virtual void UnkVirtual280();
    virtual void UnkVirtual284();
    virtual void UnkVirtual288();
    virtual void UnkVirtual28C();
    virtual void UnkVirtual290();
    virtual void UnkVirtual294();
    virtual void UnkVirtual298();
    virtual void UnkVirtual29C();
    virtual void UnkVirtual2A0();
    virtual void UnkVirtual2A4();
    virtual void UnkVirtual2A8();
    virtual void UnkVirtual2AC();
    virtual void UnkVirtual2B0();
    virtual void UnkVirtual2B4();
    virtual void UnkVirtual2B8();
    virtual float Heading(bool);
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
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char unk140;
    bool special141;
    float FUN_006f9ec0();
};
struct UpdateMover {
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
    unsigned char unk70;
    unsigned char unk71;
    unsigned char unk72;
    bool hasDestination;
    void FUN_007ddb50(P3Update&);
};
struct UpdateNodeList {
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
    unsigned int count;
    unsigned int Count() const { return count; }
    void FUN_00605d50(float, P3Update&);
};
struct UpdateHandler {
    unsigned int unk00;
    UpdateActor* actor;
    UpdateMover* mover;
    UpdateNodeList* path;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    P3Update tether;
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
    float splineT;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    float facing;
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
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    bool ignoreInitial;
    bool keepHeading;
    unsigned char unkC2;
    unsigned char unkC3;
    float ignoreTether;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned char unkDC;
    unsigned char unkDD;
    bool movementBlocked;
    unsigned char unkDF;
    unsigned char unkE0;
    bool ignoreLook;
};
float FUN_00477b20(const P3Update&);
P3Update FUN_007b7bf0(UpdateActor*);
P3Update CombatUtilities_GetAngleToProjectedPoint(UpdateActor*, P3Update);
}

namespace ns_007e3780 {

struct HeadingHandler7e3780 : ::native2108::UpdateHandler {
    __declspec(noinline) void FUN_007e3780(float& headingOut, float& lookingOut);
};

// pdb: DetailedActorPathHandler::ComputeHeadingAndLooking | DetailedActorPathHandler.obj | fnv360_0822_retail, call_gap, low
// pdb params: arfHeading, arfLooking
__declspec(noinline) void HeadingHandler7e3780::FUN_007e3780(float& headingOut, float& lookingOut)
{
    using namespace ::native2108;
    float angle = 0.0f, looking = 0.0f;
    if (movementBlocked) {
        angle = facing;
    } else if (ignoreInitial) {
        if (keepHeading) {
            angle = actor->Heading(false);
        } else if ((UpdateNodeList*)path) {
            P3Update target;
            ((UpdateNodeList*)path)->FUN_00605d50(ignoreTether, target);
            P3Update& position = actor->Position();
            float dy = target.y - position.y;
            P3Update d;
            d.x = target.x - position.x;
            d.y = dy;
            d.z = 0.0f;
            angle = FUN_00477b20(d);
        } else {
            angle = actor->Heading(false);
        }
    } else if (!ignoreLook && mover->hasDestination) {
        P3Update target;
        mover->FUN_007ddb50(target);
        P3Update position = FUN_007b7bf0(actor);
        P3Update d = position.Difference(target);
        float distance2 = (float)((double)d.x * d.x + (double)d.y * d.y);
        if (distance2 < actor->FUN_006f9ec0() * actor->FUN_006f9ec0() * 0.25) {
            angle = actor->Heading(false);
        } else {
            P3Update angles = CombatUtilities_GetAngleToProjectedPoint(actor, target);
            if (!actor->special141)
                looking = angles.x;
            if (actor->FUN_006f9ec0() >= 100.0) {
                P3Update& position2 = actor->Position();
                float dy = target.y - position2.y;
                P3Update v;
                v.x = target.x - position2.x;
                v.y = dy;
                v.z = 0;
                angle = FUN_00477b20(v);
            } else {
                angle = angles.z;
            }
        }
    } else {
        P3Update destination;
        if ((UpdateNodeList*)path && ((UpdateNodeList*)path)->Count() > 0)
            ((UpdateNodeList*)path)->FUN_00605d50(float(splineT + 0.10000000149011612), destination);
        else
            destination = tether;
        P3Update& position3 = actor->Position();
        float dy = destination.y - position3.y;
        float dz = destination.z - position3.z;
        P3Update direction;
        direction.x = destination.x - position3.x;
        direction.y = dy;
        direction.z = dz;
        float length = (float)sqrt((float)(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z));
        if (actor->special141 && length * 0.949999988079071 <= (float)fabs(direction.z))
            angle = actor->Heading(false);
        else
            angle = FUN_00477b20(direction);
        if (actor->special141)
            looking = 0;
    }
    headingOut = angle;
    lookingOut = looking;
}

}
