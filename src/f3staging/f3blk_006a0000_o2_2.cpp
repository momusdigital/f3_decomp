#include <windows.h>
// src/f3staging/f3blk_006a0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x006a3f60 (community match, verified in this file)
namespace f3m_006a3f60 {
class FUN_006a2e70{
public:
    FUN_006a2e70(void* a,void* b,void* c);
    virtual ~FUN_006a2e70();
    char pad04[0x4c-4];
};
struct Block6a{
    unsigned int m50;
    unsigned int m54;
    unsigned int m58;
    unsigned int m5c;
    unsigned int m60;
    unsigned int m64;
    unsigned int m68;
    unsigned int m6c;
    unsigned int m70;
    unsigned int m74;
    unsigned int m78;
    unsigned int m7c;
    unsigned int m80;
    unsigned int m84;
    unsigned int m88;
    unsigned int m8c;
    unsigned int m90;
    unsigned int m94;
    unsigned int m98;
    unsigned int m9c;
    __forceinline Block6a(){m50=0;m54=0;m58=0;m5c=0;m60=0;m64=0;m68=0;m6c=0;m70=0;m74=0;m78=0;m7c=0;m80=0;m84=0;m88=0;m8c=0;m90=0;m94=0;m98=0;m9c=0;}
};
class BoundItemEffect:public FUN_006a2e70{
public:
    unsigned int m4c;
    Block6a block;
    float fa0;
    unsigned char ba4,ba5,ba6,ba7,ba8;
    BoundItemEffect(void* a,void* b,void* c);
};
// pdb: BoundItemEffect::BoundItemEffect | BoundItemEffect.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCaster, apSpell, apEffect
BoundItemEffect::BoundItemEffect(void* a,void* b,void* c):FUN_006a2e70(a,b,c),m4c(0){
    fa0=0.0f;
    ba4=0;ba5=0;ba6=0;ba7=0;ba8=0;
}
}   // namespace f3m_006a3f60

// @f3 0x006a84c0 (community match, verified in this file)
namespace f3m_006a84c0 {

namespace Destroy0559 {
struct RefObject {
    virtual ~RefObject();
    virtual void DeleteThis();
    long refs;
    void DecRefCount() { if (!InterlockedDecrement(&refs)) DeleteThis(); }
};
struct RefPointer {
    RefObject* object;
    ~RefPointer() { if (object) object->DecRefCount(); }
};
struct FUN_006a2740 {
    ~FUN_006a2740();
    unsigned int unk00;
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
};
struct FUN_006a84c0 : FUN_006a2740 {
    RefPointer next;
    ~FUN_006a84c0();
};
// pdb: LightEffect::~LightEffect | LightEffect.obj | fnv360_0822_retail, objrun, medium
FUN_006a84c0::~FUN_006a84c0() {}
}
}   // namespace f3m_006a84c0

// @f3 0x006ba480 (community match, verified in this file)
namespace f3m_006ba480 {
namespace Construct6ba4 {
struct Entry {unsigned flags;int unk04;int unk08;int unk0C;bool Valid(){return (flags>>1)&1;}};
extern Entry DAT_00f462b8[];
extern int DAT_00e0c16c;
struct Data {
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
    unsigned type;
};
struct Source {int unk00;int unk04;int unk08;int unk0C;int value;Data* data;};
struct Owner {
    void* table;
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
    int value;
    void FUN_006bc930(void*,void*,Source*);
    Owner(void*,void*,Source*);
};
// pdb: ShieldEffect::ShieldEffect | ShieldEffect.obj | fnv360_0822_retail, uvref, medium
// pdb params: apCaster, apSpell, apEffect
Owner::Owner(void* first,void* second,Source* source) {
    FUN_006bc930(first,second,source);
    table=&DAT_00e0c16c;
    value=DAT_00f462b8[source->data->type].Valid() ? source->value : -1;
}
}
}   // namespace f3m_006ba480

// @f3 0x006b3930 (community match, verified in this file)
#include <windows.h>
namespace f3m_006b3930 {

// Stand-ins for the classes this function walks through.  Only the vtable slot
// positions (0x1D0, 0x9C, 0xE8) and the field at +0x18 of the returned object
// matter here.  NiFixedString is the engine's interned string handle: it is
// created through NiGlobalStringTable::AddString() and released by dropping the
// reference count kept in the eight bytes in front of the character data.

class NiGlobalStringTable
{
public:
    static char* AddString(const char* pcString);
    static char* ms_pcEmptyString;
};

class NiFixedString
{
public:
    NiFixedString(const char* pcString) { m_pcData = NiGlobalStringTable::AddString(pcString); }

    ~NiFixedString()
    {
        if (m_pcData != NiGlobalStringTable::ms_pcEmptyString)
            InterlockedDecrement(((long*)m_pcData) - 2);
    }

    const char* m_pcData;
};

class NiNamedObject;
class NiNamedObjectManager;

// Returned by NiNameOwner::GetNameHolder(); AttachName() lives at slot 0x9C.
class NiNameHolder
{
public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual NiNamedObject* AttachName(const NiFixedString& name);
};

// The object AttachName() hands back; its manager pointer sits at +0x18.
class NiNamedObject
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

// Owns the named object; ReleaseName() lives at slot 0xE8.
class NiNamedObjectManager
{
public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void ReleaseName(NiNamedObject* object);
};

// The owner this function is a member of; GetNameHolder() lives at slot 0x1D0.
class NiNameOwner
{
public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual void vf0F8();
    virtual void vf0FC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15C();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17C();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19C();
    virtual void vf1A0();
    virtual void vf1A4();
    virtual void vf1A8();
    virtual void vf1AC();
    virtual void vf1B0();
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual void vf1C4();
    virtual void vf1C8();
    virtual void vf1CC();
    virtual NiNameHolder* GetNameHolder();
    void FUN_006b3930();
};

// pdb: MagicProjectile::KillAreaEffectGeometry | MagicProjectile.obj | fnv360_0822_retail, call_seq, medium
void NiNameOwner::FUN_006b3930()
{
    NiNamedObject* result = GetNameHolder() ? GetNameHolder()->AttachName(NiFixedString("MagicAreaDisplay")) : 0;
    if (result) {
        NiNamedObjectManager* manager = (NiNamedObjectManager*)result->unk18;
        if (manager)
            manager->ReleaseName(result);
    }
}
}   // namespace f3m_006b3930

// @f3 0x006b3e70 (community match, verified in this file)
namespace f3m_006b3e70 {
namespace f3m_6b3e70 {
class QHeap { public: void* FUN_0086b930(unsigned int bytes); void FUN_0086ba60(void* p); };
extern QHeap DAT_01090a78;
struct QClock { float FUN_0078bd10(); };
extern QClock DAT_0107c0a0;
}

struct Q6bPoint { float x, y, z; };

class FUN_0073a860 {
public:
    static void* operator new(unsigned int n) { return f3m_6b3e70::DAT_01090a78.FUN_0086b930(n); }
    static void operator delete(void* p) { f3m_6b3e70::DAT_01090a78.FUN_0086ba60(p); }
    FUN_0073a860();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
};

struct Q6bInner { int unk3c_pad; };
struct Q6bData {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};
class Q6bForm {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28();
    virtual Q6bData* Get2c();
};

class Q6bBase0 {
public:
    virtual ~Q6bBase0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
class Q6bBase1 {
public:
    virtual void w00();
};
class FUN_00764d50 : public Q6bBase0, public Q6bBase1 {
public:
    FUN_00764d50();
    virtual ~FUN_00764d50();
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    FUN_0073a860* unk60;
    int unk64;
    int unk68;
    int unk6c;
};

class Q6b3e70 : public FUN_00764d50 {
public:
    Q6b3e70(Q6bForm* form, int a, int b, int c, Q6bPoint pos, Q6bPoint rot);
    virtual ~Q6b3e70();
    virtual void w00();
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    float unk80;
    float unk84;
    float unk88;
    Q6bForm* unk8c;
    int unk90;
    int unk94;
    int unk98;
    float unk9c;
    void FUN_004eeae0(Q6bPoint* p);
    void FUN_004e86c0(Q6bPoint p);
    void FUN_00764ec0(int v);
    void TESObjectREFR_SetObjectReference(int v);
};
int FUN_006b3860();

// pdb: MagicProjectile::MagicProjectile | MagicProjectile.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apCaster, apSpell, apDominantEffect, apAVEffect, aOrigin, aRotation
Q6b3e70::Q6b3e70(Q6bForm* form, int a, int b, int c, Q6bPoint pos, Q6bPoint rot)
    : unk88(0.0f), unk8c(form), unk90(a), unk94(b), unk98(c)
{
    unk9c = f3m_6b3e70::DAT_0107c0a0.FUN_0078bd10();
    unk84 = unk80 = 0.0f;
    unk60 = new FUN_0073a860();
    FUN_004eeae0(&pos);
    FUN_004e86c0(rot);
    Q6bData* d = form->Get2c();
    if (d) FUN_00764ec0(d->unk3c);
    TESObjectREFR_SetObjectReference(FUN_006b3860());
}
}   // namespace f3m_006b3e70
