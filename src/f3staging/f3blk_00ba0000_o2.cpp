// src/f3staging/f3blk_00ba0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00ba9380 (community match, verified in this file)
#include <vector>

struct ByteReader9380 {
    unsigned int offset;
    std::vector<char> data;
    int FUN_00ba9380();
};

// pdb: CTreeFileAccess::PeekToken | FileAccess.obj | fnv360_0822_retail, call_gap, medium
int ByteReader9380::FUN_00ba9380() {
    return *(int*)&data[offset];
}

// @f3 0x00baab70 (community match, verified in this file)
#include <algorithm>

struct SortedEntry_aab70
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
    float m_fPriority;
};

struct PriorityGreater_aab70
{
    bool operator()(const SortedEntry_aab70* left, const SortedEntry_aab70* right) const
    {
        return left->m_fPriority > right->m_fPriority;
    }
};

// pdb: std::_Push_heap<CIdvBranch * *,int,CIdvBranch *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: _First, _Hole, _Top, _Val, _Pred
void FUN_00baab70(SortedEntry_aab70** first, SortedEntry_aab70** mid, SortedEntry_aab70** last)
{
    PriorityGreater_aab70 pred;
    if (pred(*mid, *first))
        std::iter_swap(mid, first);
    if (pred(*last, *mid))
        std::iter_swap(last, mid);
    if (pred(*mid, *first))
        std::iter_swap(mid, first);
}

// @f3 0x00ba1ad0 (community match, verified in this file)
class HeapAL_ba1 {
public:
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern HeapAL_ba1 g_heapAL_ba1;

class Elem40AL_ba1 {
public:
    Elem40AL_ba1();
    void FUN_00bc19e0();
    static void* operator new[](unsigned int size) { return g_heapAL_ba1.FUN_0086b930(size); }
    static void operator delete[](void* memory) { g_heapAL_ba1.FUN_0086ba60(memory); }
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
};

class ElemArrayAL_ba1 {
public:
    unsigned short m_count;
    Elem40AL_ba1* m_items;
    void FUN_00ba1ad0(unsigned short count);
};

void ElemArrayAL_ba1::FUN_00ba1ad0(unsigned short count)
{
    if (m_count != count) {
        g_heapAL_ba1.FUN_0086ba60(m_items);
        m_count = count;
        m_items = new Elem40AL_ba1[count];
    }
    for (int i = 0; i < count; i++) {
        m_items[i].FUN_00bc19e0();
    }
}

// @f3 0x00bb0ce0 (community match, verified in this file)
struct StoredPoint3 { float x, y, z; };
class FloatWriter { public: void FUN_0058da30(float* value); };
class PointWriterOwner {
public:
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
    FloatWriter writer;
    void FUN_00bb0ce0(const StoredPoint3* source);
};
// pdb: CIndexedGeometry::AddVertexTangent | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: pTangent
void PointWriterOwner::FUN_00bb0ce0(const StoredPoint3* source) {
    StoredPoint3 local = { source->x, source->y, source->z };
    writer.FUN_0058da30(&local.x);
    writer.FUN_0058da30(&local.y);
    writer.FUN_0058da30(&local.z);
}

// @f3 0x00bbdcb0 (community match, verified in this file)
void __cdecl FUN_00bbdcb0(unsigned int* first, unsigned int* last, const unsigned int& value) {
    for (; first != last; ++first) *first = value;
}

// @f3 0x00baa390 (community match, verified in this file)
namespace f3m_00baa390 {
struct Element00baa390 {
    int unk00[6];
};
Element00baa390* __cdecl FUN_00baa390(Element00baa390* first, Element00baa390* last, Element00baa390* dest)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
}

// @f3 0x00bae2b0 (community match, verified in this file)
namespace f3m_00bae2b0 {

namespace f3m_00bae2b0 {
struct Settings00bae2b0 {
    float unk00;
    float unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    float unk3C;
    float unk40;
    Settings00bae2b0* FUN_00bae2b0();
};
Settings00bae2b0* Settings00bae2b0::FUN_00bae2b0()
{
    unk00 = 0.0f;
    unk04 = 0.25f;
    unk08 = 2;
    unk0C = 2;
    unk10 = 2;
    unk14 = true;
    unk20 = 0.0f;
    unk24 = 0.0f;
    unk28 = 0;
    unk2C = 4;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0;
    unk3C = 1.0f;
    unk40 = 1.0f;
    unk1C = 1.0f;
    unk18 = 1.0f;
    return this;
}
}
}   // namespace f3m_00bae2b0

// @f3 0x00bbd160 (community match, verified in this file)
namespace f3m_00bbd160 {
struct Guard930 {
    int state;
    void FUN_00bff149(int kind);
    void FUN_00bff16a();
};
struct Owner930 {
    int unk00;
    unsigned int count04;
    void FUN_00bbd160();
};
// pdb: CVec3::Magnitude | FrondEngine.obj | fnv360_1110_debug, objrun_open, low, conflict (skyrim: std::locale::facet::_Incref)
void Owner930::FUN_00bbd160() {
    Guard930 guard;
    guard.FUN_00bff149(0);
    if (count04 < (unsigned int)-1) ++count04;
    guard.FUN_00bff16a();
}
}   // namespace f3m_00bbd160

// @f3 0x00bbe9c0 (community match, verified in this file)
#include <string>
namespace f3m_00bbe9c0 {
namespace f3m_00bbe9c0 {
struct Triple {
    int a, b, c;
};
struct Record {
    char unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    std::string name;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    Triple unk48;
    Record& FUN_00bbe9c0(const Record& other);
};
// pdb: SIdvLeafTexture::operator= | TreeEngine.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: __that
Record& Record::FUN_00bbe9c0(const Record& other)
{
    unk00 = other.unk00;
    unk04 = other.unk04;
    unk08 = other.unk08;
    unk0C = other.unk0C;
    unk10 = other.unk10;
    name = other.name;
    unk30 = other.unk30;
    unk34 = other.unk34;
    unk38 = other.unk38;
    unk3C = other.unk3C;
    unk40 = other.unk40;
    unk44 = other.unk44;
    unk48 = other.unk48;
    return *this;
}
}
}   // namespace f3m_00bbe9c0

// @f3 0x00bbad10 (community match, verified in this file)
namespace f3m_00bbad10 {
struct Holder_bbad10 {
    unsigned int unk00;
    void* m_pBuf;
    unsigned int m_8;
    unsigned int m_c;
};

extern "C" void __cdecl FUN_00bb8e80(void* a, unsigned int b, Holder_bbad10* c, Holder_bbad10* d);
extern "C" void __cdecl FUN_00401010(void* p);

// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::~vector<SFrondGuide,std::allocator<SFrondGuide> > | FrondEngine.obj | fnv360_0822_retail, caller_sim, low
void __stdcall FUN_00bbad10(Holder_bbad10* self)
{
    void* buf = self->m_pBuf;
    if (buf != 0)
    {
        FUN_00bb8e80(buf, self->m_8, self, (Holder_bbad10*)(*(Holder_bbad10* volatile*)&self));
        FUN_00401010(self->m_pBuf);
    }
    self->m_pBuf = 0;
    self->m_8 = 0;
    self->m_c = 0;
}
}   // namespace f3m_00bbad10

// @f3 0x00bb5830 (community match, verified in this file)
namespace f3m_00bb5830 {

unsigned int __cdecl FUN_00bc5f00();
int __cdecl FUN_00bb4760(unsigned int count, unsigned int base);

struct FUN_00bb5830_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    unsigned char __thiscall FUN_00bb5830(unsigned int count);
};

unsigned char __thiscall FUN_00bb5830_Obj::FUN_00bb5830(unsigned int count) {
    unsigned int base = 0;

    this->unk04 = 0;
    this->unk08 = 0;
    this->unk0C = 0;

    if (count == 0)
        return 0;

    if (count > 0x5555555)
        base = FUN_00bc5f00();

    int result = FUN_00bb4760(count, base);
    this->unk04 = result;
    this->unk08 = result;
    this->unk0C = count * 0x30 + result;

    return 1;
}
}   // namespace f3m_00bb5830

// @f3 0x00baad80 (community match, verified in this file)
#include <algorithm>
#include <utility>
namespace f3m_00baad80 {

struct SortedEntry_aad80
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
    float m_fPriority;
};
struct PriorityGreater_aad80
{
    bool operator()(const SortedEntry_aad80* left, const SortedEntry_aad80* right) const
    {
        return left->m_fPriority > right->m_fPriority;
    }
};

typedef SortedEntry_aad80* EP;

void FUN_00baac90(EP* a, EP* b, EP* c, PriorityGreater_aad80 p);

// pdb: std::_Unguarded_partition<CIdvBranch * *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Last, _Pred
std::pair<EP*, EP*> FUN_00baad80(EP* _First, EP* _Last, PriorityGreater_aad80 _Pred)
{
    EP* _Mid = _First + (_Last - _First) / 2;
    FUN_00baac90(_First, _Mid, _Last - 1, _Pred);
    EP* _Pfirst = _Mid;
    EP* _Plast = _Pfirst + 1;
    while (_First < _Pfirst && !_Pred(*(_Pfirst - 1), *_Pfirst) && !_Pred(*_Pfirst, *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last && !_Pred(*_Plast, *_Pfirst) && !_Pred(*_Pfirst, *_Plast))
        ++_Plast;
    EP* _Gfirst = _Plast;
    EP* _Glast = _Pfirst;
    for (;;)
    {
        for (; _Gfirst < _Last; ++_Gfirst)
        {
            if (_Pred(*_Pfirst, *_Gfirst))
                ;
            else if (_Pred(*_Gfirst, *_Pfirst))
                break;
            else
                std::iter_swap(_Plast++, _Gfirst);
        }
        for (; _First < _Glast; --_Glast)
        {
            if (_Pred(*(_Glast - 1), *_Pfirst))
                ;
            else if (_Pred(*_Pfirst, *(_Glast - 1)))
                break;
            else
                std::iter_swap(--_Pfirst, _Glast - 1);
        }
        if (_Glast == _First && _Gfirst == _Last)
            return std::pair<EP*, EP*>(_Pfirst, _Plast);
        if (_Glast == _First)
        {
            if (_Plast != _Gfirst)
                std::iter_swap(_Pfirst, _Plast);
            ++_Plast;
            std::iter_swap(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {
            if (--_Glast != --_Pfirst)
                std::iter_swap(_Glast, _Pfirst);
            std::iter_swap(_Pfirst, --_Plast);
        }
        else
            std::iter_swap(_Gfirst++, --_Glast);
    }
}
}   // namespace f3m_00baad80

// @f3 0x00ba0230 (community match, verified in this file)
extern unsigned char DAT_00ea6e80[];
extern unsigned char DAT_00ea6c80[];
extern unsigned char DAT_00ea6d80[];
extern int DAT_00ea6638[],DAT_00ea6f80[],DAT_00ea66c0[],DAT_00ea6ff8[];
namespace f3m_00ba0230 {
struct Code {unsigned short code,len;};
struct Stream {
int unk00,unk04;unsigned char* unk08;int unk0c,unk10;unsigned int unk14;
int unk0018;int unk001c;int unk0020;int unk0024;int unk0028;int unk002c;int unk0030;int unk0034;int unk0038;int unk003c;
int unk0040;int unk0044;int unk0048;int unk004c;int unk0050;int unk0054;int unk0058;int unk005c;int unk0060;int unk0064;int unk0068;int unk006c;int unk0070;int unk0074;int unk0078;int unk007c;
int unk0080;int unk0084;int unk0088;int unk008c;int unk0090;int unk0094;int unk0098;int unk009c;int unk00a0;int unk00a4;int unk00a8;int unk00ac;int unk00b0;int unk00b4;int unk00b8;int unk00bc;
int unk00c0;int unk00c4;int unk00c8;int unk00cc;int unk00d0;int unk00d4;int unk00d8;int unk00dc;int unk00e0;int unk00e4;int unk00e8;int unk00ec;int unk00f0;int unk00f4;int unk00f8;int unk00fc;
int unk0100;int unk0104;int unk0108;int unk010c;int unk0110;int unk0114;int unk0118;int unk011c;int unk0120;int unk0124;int unk0128;int unk012c;int unk0130;int unk0134;int unk0138;int unk013c;
int unk0140;int unk0144;int unk0148;int unk014c;int unk0150;int unk0154;int unk0158;int unk015c;int unk0160;int unk0164;int unk0168;int unk016c;int unk0170;int unk0174;int unk0178;int unk017c;
int unk0180;int unk0184;int unk0188;int unk018c;int unk0190;int unk0194;int unk0198;int unk019c;int unk01a0;int unk01a4;int unk01a8;int unk01ac;int unk01b0;int unk01b4;int unk01b8;int unk01bc;
int unk01c0;int unk01c4;int unk01c8;int unk01cc;int unk01d0;int unk01d4;int unk01d8;int unk01dc;int unk01e0;int unk01e4;int unk01e8;int unk01ec;int unk01f0;int unk01f4;int unk01f8;int unk01fc;
int unk0200;int unk0204;int unk0208;int unk020c;int unk0210;int unk0214;int unk0218;int unk021c;int unk0220;int unk0224;int unk0228;int unk022c;int unk0230;int unk0234;int unk0238;int unk023c;
int unk0240;int unk0244;int unk0248;int unk024c;int unk0250;int unk0254;int unk0258;int unk025c;int unk0260;int unk0264;int unk0268;int unk026c;int unk0270;int unk0274;int unk0278;int unk027c;
int unk0280;int unk0284;int unk0288;int unk028c;int unk0290;int unk0294;int unk0298;int unk029c;int unk02a0;int unk02a4;int unk02a8;int unk02ac;int unk02b0;int unk02b4;int unk02b8;int unk02bc;
int unk02c0;int unk02c4;int unk02c8;int unk02cc;int unk02d0;int unk02d4;int unk02d8;int unk02dc;int unk02e0;int unk02e4;int unk02e8;int unk02ec;int unk02f0;int unk02f4;int unk02f8;int unk02fc;
int unk0300;int unk0304;int unk0308;int unk030c;int unk0310;int unk0314;int unk0318;int unk031c;int unk0320;int unk0324;int unk0328;int unk032c;int unk0330;int unk0334;int unk0338;int unk033c;
int unk0340;int unk0344;int unk0348;int unk034c;int unk0350;int unk0354;int unk0358;int unk035c;int unk0360;int unk0364;int unk0368;int unk036c;int unk0370;int unk0374;int unk0378;int unk037c;
int unk0380;int unk0384;int unk0388;int unk038c;int unk0390;int unk0394;int unk0398;int unk039c;int unk03a0;int unk03a4;int unk03a8;int unk03ac;int unk03b0;int unk03b4;int unk03b8;int unk03bc;
int unk03c0;int unk03c4;int unk03c8;int unk03cc;int unk03d0;int unk03d4;int unk03d8;int unk03dc;int unk03e0;int unk03e4;int unk03e8;int unk03ec;int unk03f0;int unk03f4;int unk03f8;int unk03fc;
int unk0400;int unk0404;int unk0408;int unk040c;int unk0410;int unk0414;int unk0418;int unk041c;int unk0420;int unk0424;int unk0428;int unk042c;int unk0430;int unk0434;int unk0438;int unk043c;
int unk0440;int unk0444;int unk0448;int unk044c;int unk0450;int unk0454;int unk0458;int unk045c;int unk0460;int unk0464;int unk0468;int unk046c;int unk0470;int unk0474;int unk0478;int unk047c;
int unk0480;int unk0484;int unk0488;int unk048c;int unk0490;int unk0494;int unk0498;int unk049c;int unk04a0;int unk04a4;int unk04a8;int unk04ac;int unk04b0;int unk04b4;int unk04b8;int unk04bc;
int unk04c0;int unk04c4;int unk04c8;int unk04cc;int unk04d0;int unk04d4;int unk04d8;int unk04dc;int unk04e0;int unk04e4;int unk04e8;int unk04ec;int unk04f0;int unk04f4;int unk04f8;int unk04fc;
int unk0500;int unk0504;int unk0508;int unk050c;int unk0510;int unk0514;int unk0518;int unk051c;int unk0520;int unk0524;int unk0528;int unk052c;int unk0530;int unk0534;int unk0538;int unk053c;
int unk0540;int unk0544;int unk0548;int unk054c;int unk0550;int unk0554;int unk0558;int unk055c;int unk0560;int unk0564;int unk0568;int unk056c;int unk0570;int unk0574;int unk0578;int unk057c;
int unk0580;int unk0584;int unk0588;int unk058c;int unk0590;int unk0594;int unk0598;int unk059c;int unk05a0;int unk05a4;int unk05a8;int unk05ac;int unk05b0;int unk05b4;int unk05b8;int unk05bc;
int unk05c0;int unk05c4;int unk05c8;int unk05cc;int unk05d0;int unk05d4;int unk05d8;int unk05dc;int unk05e0;int unk05e4;int unk05e8;int unk05ec;int unk05f0;int unk05f4;int unk05f8;int unk05fc;
int unk0600;int unk0604;int unk0608;int unk060c;int unk0610;int unk0614;int unk0618;int unk061c;int unk0620;int unk0624;int unk0628;int unk062c;int unk0630;int unk0634;int unk0638;int unk063c;
int unk0640;int unk0644;int unk0648;int unk064c;int unk0650;int unk0654;int unk0658;int unk065c;int unk0660;int unk0664;int unk0668;int unk066c;int unk0670;int unk0674;int unk0678;int unk067c;
int unk0680;int unk0684;int unk0688;int unk068c;int unk0690;int unk0694;int unk0698;int unk069c;int unk06a0;int unk06a4;int unk06a8;int unk06ac;int unk06b0;int unk06b4;int unk06b8;int unk06bc;
int unk06c0;int unk06c4;int unk06c8;int unk06cc;int unk06d0;int unk06d4;int unk06d8;int unk06dc;int unk06e0;int unk06e4;int unk06e8;int unk06ec;int unk06f0;int unk06f4;int unk06f8;int unk06fc;
int unk0700;int unk0704;int unk0708;int unk070c;int unk0710;int unk0714;int unk0718;int unk071c;int unk0720;int unk0724;int unk0728;int unk072c;int unk0730;int unk0734;int unk0738;int unk073c;
int unk0740;int unk0744;int unk0748;int unk074c;int unk0750;int unk0754;int unk0758;int unk075c;int unk0760;int unk0764;int unk0768;int unk076c;int unk0770;int unk0774;int unk0778;int unk077c;
int unk0780;int unk0784;int unk0788;int unk078c;int unk0790;int unk0794;int unk0798;int unk079c;int unk07a0;int unk07a4;int unk07a8;int unk07ac;int unk07b0;int unk07b4;int unk07b8;int unk07bc;
int unk07c0;int unk07c4;int unk07c8;int unk07cc;int unk07d0;int unk07d4;int unk07d8;int unk07dc;int unk07e0;int unk07e4;int unk07e8;int unk07ec;int unk07f0;int unk07f4;int unk07f8;int unk07fc;
int unk0800;int unk0804;int unk0808;int unk080c;int unk0810;int unk0814;int unk0818;int unk081c;int unk0820;int unk0824;int unk0828;int unk082c;int unk0830;int unk0834;int unk0838;int unk083c;
int unk0840;int unk0844;int unk0848;int unk084c;int unk0850;int unk0854;int unk0858;int unk085c;int unk0860;int unk0864;int unk0868;int unk086c;int unk0870;int unk0874;int unk0878;int unk087c;
int unk0880;int unk0884;int unk0888;int unk088c;int unk0890;int unk0894;int unk0898;int unk089c;int unk08a0;int unk08a4;int unk08a8;int unk08ac;int unk08b0;int unk08b4;int unk08b8;int unk08bc;
int unk08c0;int unk08c4;int unk08c8;int unk08cc;int unk08d0;int unk08d4;int unk08d8;int unk08dc;int unk08e0;int unk08e4;int unk08e8;int unk08ec;int unk08f0;int unk08f4;int unk08f8;int unk08fc;
int unk0900;int unk0904;int unk0908;int unk090c;int unk0910;int unk0914;int unk0918;int unk091c;int unk0920;int unk0924;int unk0928;int unk092c;int unk0930;int unk0934;int unk0938;int unk093c;
int unk0940;int unk0944;int unk0948;int unk094c;int unk0950;int unk0954;int unk0958;int unk095c;int unk0960;int unk0964;int unk0968;int unk096c;int unk0970;int unk0974;int unk0978;int unk097c;
int unk0980;int unk0984;int unk0988;int unk098c;int unk0990;int unk0994;int unk0998;int unk099c;int unk09a0;int unk09a4;int unk09a8;int unk09ac;int unk09b0;int unk09b4;int unk09b8;int unk09bc;
int unk09c0;int unk09c4;int unk09c8;int unk09cc;int unk09d0;int unk09d4;int unk09d8;int unk09dc;int unk09e0;int unk09e4;int unk09e8;int unk09ec;int unk09f0;int unk09f4;int unk09f8;int unk09fc;
int unk0a00;int unk0a04;int unk0a08;int unk0a0c;int unk0a10;int unk0a14;int unk0a18;int unk0a1c;int unk0a20;int unk0a24;int unk0a28;int unk0a2c;int unk0a30;int unk0a34;int unk0a38;int unk0a3c;
int unk0a40;int unk0a44;int unk0a48;int unk0a4c;int unk0a50;int unk0a54;int unk0a58;int unk0a5c;int unk0a60;int unk0a64;int unk0a68;int unk0a6c;int unk0a70;int unk0a74;int unk0a78;int unk0a7c;
int unk0a80;int unk0a84;int unk0a88;int unk0a8c;int unk0a90;int unk0a94;int unk0a98;int unk0a9c;int unk0aa0;int unk0aa4;int unk0aa8;int unk0aac;int unk0ab0;int unk0ab4;int unk0ab8;int unk0abc;
int unk0ac0;int unk0ac4;int unk0ac8;int unk0acc;int unk0ad0;int unk0ad4;int unk0ad8;int unk0adc;int unk0ae0;int unk0ae4;int unk0ae8;int unk0aec;int unk0af0;int unk0af4;int unk0af8;int unk0afc;
int unk0b00;int unk0b04;int unk0b08;int unk0b0c;int unk0b10;int unk0b14;int unk0b18;int unk0b1c;int unk0b20;int unk0b24;int unk0b28;int unk0b2c;int unk0b30;int unk0b34;int unk0b38;int unk0b3c;
int unk0b40;int unk0b44;int unk0b48;int unk0b4c;int unk0b50;int unk0b54;int unk0b58;int unk0b5c;int unk0b60;int unk0b64;int unk0b68;int unk0b6c;int unk0b70;int unk0b74;int unk0b78;int unk0b7c;
int unk0b80;int unk0b84;int unk0b88;int unk0b8c;int unk0b90;int unk0b94;int unk0b98;int unk0b9c;int unk0ba0;int unk0ba4;int unk0ba8;int unk0bac;int unk0bb0;int unk0bb4;int unk0bb8;int unk0bbc;
int unk0bc0;int unk0bc4;int unk0bc8;int unk0bcc;int unk0bd0;int unk0bd4;int unk0bd8;int unk0bdc;int unk0be0;int unk0be4;int unk0be8;int unk0bec;int unk0bf0;int unk0bf4;int unk0bf8;int unk0bfc;
int unk0c00;int unk0c04;int unk0c08;int unk0c0c;int unk0c10;int unk0c14;int unk0c18;int unk0c1c;int unk0c20;int unk0c24;int unk0c28;int unk0c2c;int unk0c30;int unk0c34;int unk0c38;int unk0c3c;
int unk0c40;int unk0c44;int unk0c48;int unk0c4c;int unk0c50;int unk0c54;int unk0c58;int unk0c5c;int unk0c60;int unk0c64;int unk0c68;int unk0c6c;int unk0c70;int unk0c74;int unk0c78;int unk0c7c;
int unk0c80;int unk0c84;int unk0c88;int unk0c8c;int unk0c90;int unk0c94;int unk0c98;int unk0c9c;int unk0ca0;int unk0ca4;int unk0ca8;int unk0cac;int unk0cb0;int unk0cb4;int unk0cb8;int unk0cbc;
int unk0cc0;int unk0cc4;int unk0cc8;int unk0ccc;int unk0cd0;int unk0cd4;int unk0cd8;int unk0cdc;int unk0ce0;int unk0ce4;int unk0ce8;int unk0cec;int unk0cf0;int unk0cf4;int unk0cf8;int unk0cfc;
int unk0d00;int unk0d04;int unk0d08;int unk0d0c;int unk0d10;int unk0d14;int unk0d18;int unk0d1c;int unk0d20;int unk0d24;int unk0d28;int unk0d2c;int unk0d30;int unk0d34;int unk0d38;int unk0d3c;
int unk0d40;int unk0d44;int unk0d48;int unk0d4c;int unk0d50;int unk0d54;int unk0d58;int unk0d5c;int unk0d60;int unk0d64;int unk0d68;int unk0d6c;int unk0d70;int unk0d74;int unk0d78;int unk0d7c;
int unk0d80;int unk0d84;int unk0d88;int unk0d8c;int unk0d90;int unk0d94;int unk0d98;int unk0d9c;int unk0da0;int unk0da4;int unk0da8;int unk0dac;int unk0db0;int unk0db4;int unk0db8;int unk0dbc;
int unk0dc0;int unk0dc4;int unk0dc8;int unk0dcc;int unk0dd0;int unk0dd4;int unk0dd8;int unk0ddc;int unk0de0;int unk0de4;int unk0de8;int unk0dec;int unk0df0;int unk0df4;int unk0df8;int unk0dfc;
int unk0e00;int unk0e04;int unk0e08;int unk0e0c;int unk0e10;int unk0e14;int unk0e18;int unk0e1c;int unk0e20;int unk0e24;int unk0e28;int unk0e2c;int unk0e30;int unk0e34;int unk0e38;int unk0e3c;
int unk0e40;int unk0e44;int unk0e48;int unk0e4c;int unk0e50;int unk0e54;int unk0e58;int unk0e5c;int unk0e60;int unk0e64;int unk0e68;int unk0e6c;int unk0e70;int unk0e74;int unk0e78;int unk0e7c;
int unk0e80;int unk0e84;int unk0e88;int unk0e8c;int unk0e90;int unk0e94;int unk0e98;int unk0e9c;int unk0ea0;int unk0ea4;int unk0ea8;int unk0eac;int unk0eb0;int unk0eb4;int unk0eb8;int unk0ebc;
int unk0ec0;int unk0ec4;int unk0ec8;int unk0ecc;int unk0ed0;int unk0ed4;int unk0ed8;int unk0edc;int unk0ee0;int unk0ee4;int unk0ee8;int unk0eec;int unk0ef0;int unk0ef4;int unk0ef8;int unk0efc;
int unk0f00;int unk0f04;int unk0f08;int unk0f0c;int unk0f10;int unk0f14;int unk0f18;int unk0f1c;int unk0f20;int unk0f24;int unk0f28;int unk0f2c;int unk0f30;int unk0f34;int unk0f38;int unk0f3c;
int unk0f40;int unk0f44;int unk0f48;int unk0f4c;int unk0f50;int unk0f54;int unk0f58;int unk0f5c;int unk0f60;int unk0f64;int unk0f68;int unk0f6c;int unk0f70;int unk0f74;int unk0f78;int unk0f7c;
int unk0f80;int unk0f84;int unk0f88;int unk0f8c;int unk0f90;int unk0f94;int unk0f98;int unk0f9c;int unk0fa0;int unk0fa4;int unk0fa8;int unk0fac;int unk0fb0;int unk0fb4;int unk0fb8;int unk0fbc;
int unk0fc0;int unk0fc4;int unk0fc8;int unk0fcc;int unk0fd0;int unk0fd4;int unk0fd8;int unk0fdc;int unk0fe0;int unk0fe4;int unk0fe8;int unk0fec;int unk0ff0;int unk0ff4;int unk0ff8;int unk0ffc;
int unk1000;int unk1004;int unk1008;int unk100c;int unk1010;int unk1014;int unk1018;int unk101c;int unk1020;int unk1024;int unk1028;int unk102c;int unk1030;int unk1034;int unk1038;int unk103c;
int unk1040;int unk1044;int unk1048;int unk104c;int unk1050;int unk1054;int unk1058;int unk105c;int unk1060;int unk1064;int unk1068;int unk106c;int unk1070;int unk1074;int unk1078;int unk107c;
int unk1080;int unk1084;int unk1088;int unk108c;int unk1090;int unk1094;int unk1098;int unk109c;int unk10a0;int unk10a4;int unk10a8;int unk10ac;int unk10b0;int unk10b4;int unk10b8;int unk10bc;
int unk10c0;int unk10c4;int unk10c8;int unk10cc;int unk10d0;int unk10d4;int unk10d8;int unk10dc;int unk10e0;int unk10e4;int unk10e8;int unk10ec;int unk10f0;int unk10f4;int unk10f8;int unk10fc;
int unk1100;int unk1104;int unk1108;int unk110c;int unk1110;int unk1114;int unk1118;int unk111c;int unk1120;int unk1124;int unk1128;int unk112c;int unk1130;int unk1134;int unk1138;int unk113c;
int unk1140;int unk1144;int unk1148;int unk114c;int unk1150;int unk1154;int unk1158;int unk115c;int unk1160;int unk1164;int unk1168;int unk116c;int unk1170;int unk1174;int unk1178;int unk117c;
int unk1180;int unk1184;int unk1188;int unk118c;int unk1190;int unk1194;int unk1198;int unk119c;int unk11a0;int unk11a4;int unk11a8;int unk11ac;int unk11b0;int unk11b4;int unk11b8;int unk11bc;
int unk11c0;int unk11c4;int unk11c8;int unk11cc;int unk11d0;int unk11d4;int unk11d8;int unk11dc;int unk11e0;int unk11e4;int unk11e8;int unk11ec;int unk11f0;int unk11f4;int unk11f8;int unk11fc;
int unk1200;int unk1204;int unk1208;int unk120c;int unk1210;int unk1214;int unk1218;int unk121c;int unk1220;int unk1224;int unk1228;int unk122c;int unk1230;int unk1234;int unk1238;int unk123c;
int unk1240;int unk1244;int unk1248;int unk124c;int unk1250;int unk1254;int unk1258;int unk125c;int unk1260;int unk1264;int unk1268;int unk126c;int unk1270;int unk1274;int unk1278;int unk127c;
int unk1280;int unk1284;int unk1288;int unk128c;int unk1290;int unk1294;int unk1298;int unk129c;int unk12a0;int unk12a4;int unk12a8;int unk12ac;int unk12b0;int unk12b4;int unk12b8;int unk12bc;
int unk12c0;int unk12c4;int unk12c8;int unk12cc;int unk12d0;int unk12d4;int unk12d8;int unk12dc;int unk12e0;int unk12e4;int unk12e8;int unk12ec;int unk12f0;int unk12f4;int unk12f8;int unk12fc;
int unk1300;int unk1304;int unk1308;int unk130c;int unk1310;int unk1314;int unk1318;int unk131c;int unk1320;int unk1324;int unk1328;int unk132c;int unk1330;int unk1334;int unk1338;int unk133c;
int unk1340;int unk1344;int unk1348;int unk134c;int unk1350;int unk1354;int unk1358;int unk135c;int unk1360;int unk1364;int unk1368;int unk136c;int unk1370;int unk1374;int unk1378;int unk137c;
int unk1380;int unk1384;int unk1388;int unk138c;int unk1390;int unk1394;int unk1398;int unk139c;int unk13a0;int unk13a4;int unk13a8;int unk13ac;int unk13b0;int unk13b4;int unk13b8;int unk13bc;
int unk13c0;int unk13c4;int unk13c8;int unk13cc;int unk13d0;int unk13d4;int unk13d8;int unk13dc;int unk13e0;int unk13e4;int unk13e8;int unk13ec;int unk13f0;int unk13f4;int unk13f8;int unk13fc;
int unk1400;int unk1404;int unk1408;int unk140c;int unk1410;int unk1414;int unk1418;int unk141c;int unk1420;int unk1424;int unk1428;int unk142c;int unk1430;int unk1434;int unk1438;int unk143c;
int unk1440;int unk1444;int unk1448;int unk144c;int unk1450;int unk1454;int unk1458;int unk145c;int unk1460;int unk1464;int unk1468;int unk146c;int unk1470;int unk1474;int unk1478;int unk147c;
int unk1480;int unk1484;int unk1488;int unk148c;int unk1490;int unk1494;int unk1498;int unk149c;int unk14a0;int unk14a4;int unk14a8;int unk14ac;int unk14b0;int unk14b4;int unk14b8;int unk14bc;
int unk14c0;int unk14c4;int unk14c8;int unk14cc;int unk14d0;int unk14d4;int unk14d8;int unk14dc;int unk14e0;int unk14e4;int unk14e8;int unk14ec;int unk14f0;int unk14f4;int unk14f8;int unk14fc;
int unk1500;int unk1504;int unk1508;int unk150c;int unk1510;int unk1514;int unk1518;int unk151c;int unk1520;int unk1524;int unk1528;int unk152c;int unk1530;int unk1534;int unk1538;int unk153c;
int unk1540;int unk1544;int unk1548;int unk154c;int unk1550;int unk1554;int unk1558;int unk155c;int unk1560;int unk1564;int unk1568;int unk156c;int unk1570;int unk1574;int unk1578;int unk157c;
int unk1580;int unk1584;int unk1588;int unk158c;int unk1590;int unk1594;int unk1598;int unk159c;int unk15a0;int unk15a4;int unk15a8;int unk15ac;int unk15b0;int unk15b4;int unk15b8;int unk15bc;
int unk15c0;int unk15c4;int unk15c8;int unk15cc;int unk15d0;int unk15d4;int unk15d8;int unk15dc;int unk15e0;int unk15e4;int unk15e8;int unk15ec;int unk15f0;int unk15f4;int unk15f8;int unk15fc;
int unk1600;int unk1604;int unk1608;int unk160c;int unk1610;int unk1614;int unk1618;int unk161c;int unk1620;int unk1624;int unk1628;int unk162c;int unk1630;int unk1634;int unk1638;int unk163c;
int unk1640;int unk1644;int unk1648;int unk164c;int unk1650;int unk1654;int unk1658;int unk165c;int unk1660;int unk1664;int unk1668;int unk166c;int unk1670;int unk1674;int unk1678;int unk167c;
int unk1680;int unk1684;int unk1688;int unk168c;
unsigned char* unk1690;int unk1694;unsigned int unk1698;unsigned short* unk169c;
int unk16a0,unk16a4,unk16a8;int unk16ac;unsigned short unk16b0,unk16b2;int unk16b4;
__forceinline void bits(unsigned value,int count) {
 if(unk16b4>16-count) {
  unk16b0|=(unsigned short)(value<<unk16b4);
  unk08[unk14++]=(unsigned char)unk16b0;
  unk08[unk14++]=(unsigned char)(unk16b0>>8);
  unk16b0=(unsigned short)value>>(16-unk16b4);
  unk16b4+=count-16;
 }else {unk16b0|=(unsigned short)(value<<unk16b4);unk16b4+=count;}
}
__forceinline void codeBits(const Code& entry) {
 int count=entry.len;
 if(unk16b4>16-count) {
  unsigned value=entry.code;
  unk16b0|=(unsigned short)(value<<unk16b4);
  unk08[unk14++]=(unsigned char)unk16b0;
  unk08[unk14++]=(unsigned char)(unk16b0>>8);
  unk16b0=(unsigned short)value>>(16-unk16b4);
  unk16b4+=count-16;
 }else {unk16b0|=(unsigned short)(entry.code<<unk16b4);unk16b4+=count;}
}

};
// pdb: compress_block | trees.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: send_all_trees)
static __declspec(noinline) void FUN_00ba0230(Stream* s,Code* literal,Code* distance) {
 unsigned int i=0;
 if(s->unk1698!=0)do {
  unsigned int dist=s->unk169c[i];
  unsigned int value=s->unk1690[i];
  ++i;
  if(dist==0) {s->codeBits(literal[value]);}
  else {
   unsigned int code=DAT_00ea6e80[value];
   s->codeBits(literal[code+257]);
   int extra=DAT_00ea6638[code];
   if(extra) {value-=DAT_00ea6f80[code];s->bits(value,extra);}
   --dist;
   unsigned int dcode=dist<256?(unsigned int)DAT_00ea6c80[dist]:(unsigned int)DAT_00ea6d80[dist>>7];
   {
 int count=distance[dcode].len;
 if(s->unk16b4>16-count) {
  unsigned value=distance[dcode].code;
  s->unk16b0|=(unsigned short)(value<<s->unk16b4);
  s->unk08[s->unk14++]=(unsigned char)s->unk16b0;
  s->unk08[s->unk14++]=(unsigned char)(s->unk16b0>>8);
  s->unk16b0=(unsigned short)value>>(16-s->unk16b4);
  s->unk16b4+=count-16;
 }else {s->unk16b0|=(unsigned short)(distance[dcode].code<<s->unk16b4);s->unk16b4+=count;}}
   extra=DAT_00ea66c0[dcode];
   if(extra) {dist-=DAT_00ea6ff8[dcode];s->bits(dist,extra);}
  }
 }while(i<s->unk1698);
 s->codeBits(literal[256]);
 s->unk16ac=literal[256].len;
}
Stream* volatile inputStream;Code* volatile literalCodes;Code* volatile distanceCodes;
void caller_of_FUN_00ba0230() {FUN_00ba0230(inputStream,literalCodes,distanceCodes);}
}   // namespace f3m_00ba0230

// @f3 0x00ba26e0 (community match, verified in this file)
extern unsigned char DAT_01178274;
extern "C" char DAT_01068a60;
namespace f3m_00ba26e0 {
struct CSpeedTreeRT
{
    void* m_pFirstPointer;
    unsigned short FUN_00b08710();
};
// @fnv 0x00b08710
unsigned short CSpeedTreeRT::FUN_00b08710()
{
    unsigned int v = *(unsigned int*)((char*)m_pFirstPointer + 0xc0);
    return (unsigned short)v;
}
struct FUN_00b08440_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    float FUN_00b08440();
};

// @fnv 0x00b08440
float FUN_00b08440_shell::FUN_00b08440()
{
    float fLevel = -1.0f;
    if (m_34)
    {
        fLevel = *(float*)((char*)m_34 + 0x10);
    }
    else
    {
        fLevel = *(float*)((char*)m_00 + 0x14);
    }
    return fLevel;
}

struct HelperC780
{
    void* FUN_00ba1ba0(float, float);
};
void __cdecl FUN_00ba14c0(float, unsigned short, float, float, float, float, float*, float*, short*, short*);
struct BlockC4
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    float a, b;
};
typedef float EntryC4;
struct ListC4
{
    unsigned int unk000;
    unsigned int unk004;
    int count;
    EntryC4* data;
};
struct OutC4
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
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
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned char active;
    unsigned char unk0f1;
    unsigned char unk0f2;
    unsigned char unk0f3;
    EntryC4* data;
    void* value;
    float weight;
    unsigned short n;
    unsigned char unk102;
    unsigned char unk103;
    unsigned char active2;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char unk107;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned short n2;
    unsigned char unk116;
    unsigned char unk117;
    unsigned char active3;
    unsigned char unk119;
    unsigned char unk11a;
    unsigned char unk11b;
    EntryC4* last;
    void* ptr;
    float weight2;
    unsigned short n3;
};
struct TreeC4
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    HelperC780* helper;
    int p18;
    float x;
    float y;
    int p24;
    float z;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    BlockC4* block;
    unsigned char mode;
    unsigned char unk045;
    unsigned char unk046;
    unsigned char unk047;
    unsigned int unk048;
    ListC4* list;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned char unk06c;
    unsigned char enabled;
    unsigned char unk06e;
    unsigned char unk06f;
    int data;
    void FUN_00ba26e0(OutC4* out);
};
// Fills OutC4 from the speed tree: computes weight from FUN_00ba14c0, sets active flags, data/value pointers and list endpoints.
// @fnv 0x00b0c4f0
// pdb: CSpeedTreeRT::GetSimpleBillboardGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
// pdb params: sGeometry
void TreeC4::FUN_00ba26e0(OutC4* out)
{
    if (DAT_01178274)
    {
        unsigned short p = ((CSpeedTreeRT*)this)->FUN_00b08710() + 1;
        float s = -1.0f;
        float i = -1.0f;
        short h = -1;
        short a = -1;
        float f, eb, cf, q;
        FUN_00ba14c0(((FUN_00b08440_shell*)this)->FUN_00b08440(), p, x, z, y, (float)mode, &s, &i, &h, &a);
        out->weight = -1.0f;
        if (h == p - 1)
            out->weight = s;
        else if (a == p - 1)
            out->weight = i;
        out->active = out->weight != -1.0 ? 1 : 0;
        out->n = 0;
        if (out->active)
        {
            out->value = helper->FUN_00ba1ba0(block->b, block->a);
            if (list)
                out->data = list->data;
            else
                out->data = 0;
        }
        out->active2 = 0;
        out->n2 = 0;
        if (enabled)
        {
            out->ptr = &data;
            if (list)
                out->last = &list->data[8 * (list->count - 1)];
            else
                out->last = 0;
            out->weight2 = out->weight;
            out->active3 = out->weight2 >= 0.0 ? 1 : 0;
            out->weight2 = *(float*)&DAT_01068a60;
        }
        else
            out->active3 = 0;
        out->n3 = 0;
    }
    else
    {
        out->active = 0;
        out->active2 = 0;
        out->active3 = 0;
    }
}
}   // namespace f3m_00ba26e0

// @f3 0x00ba0960 (community match, verified in this file)
namespace f3m_00ba0960 {
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/

// Adapted from zlib 1.2.1 trees.c, Copyright (C) 1995-2003 Jean-loup Gailly.
// Altered for the FO3 contribution: C++ declarations and explicit macro expansions.
// Original source and license retained in the local FNV reference checkout.
typedef unsigned char uch; typedef unsigned char Byte; typedef unsigned char Bytef; typedef unsigned char uchf;
typedef unsigned short ush; typedef unsigned short ushf; typedef unsigned short Posf; typedef unsigned int uInt; typedef unsigned int IPos;
typedef unsigned long ulg; typedef int intf; typedef void* z_streamp;
typedef struct ct_data_s { union { ush freq; ush code; } fc; union { ush dad; ush len; } dl; } ct_data;
typedef struct static_tree_desc_s static_tree_desc;
typedef struct tree_desc_s { ct_data* dyn_tree; int max_code; static_tree_desc* stat_desc; } tree_desc;
struct static_tree_desc_s {
    const ct_data *static_tree;  
    const intf *extra_bits;      
    int     extra_base;          
    int     elems;               
    int     max_length;          
};
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    

    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        

    Bytef *window;

    ulg window_size;

    Posf *prev;

    Posf *head; 

    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      

    uInt  hash_shift;

    long block_start;

    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              

    uInt prev_length;

    uInt max_chain_length;

    uInt max_lazy_match;

    int level;    
    int strategy; 

    uInt good_match;

    int nice_match; 

    struct ct_data_s dyn_ltree[573];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  

    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              

    ush bl_count[15+1];

    int heap[2*286+1];      
    int heap_len;               
    int heap_max;               

    uch depth[2*286+1];

    uchf *l_buf;          

    uInt  lit_bufsize;

    uInt last_lit;      

    ushf *d_buf;

    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   

    ush bi_buf;
    
    int bi_valid;

} deflate_state;

static unsigned bi_reverse(unsigned code, int len);

static void FUN_00b9f6e0(deflate_state* s, ct_data* tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;  
    while (j <= s->heap_len) {
        
        if (j < s->heap_len &&
            (tree[s->heap[j+1]].fc.freq < tree[s->heap[j]].fc.freq || (tree[s->heap[j+1]].fc.freq == tree[s->heap[j]].fc.freq && s->depth[s->heap[j+1]] <= s->depth[s->heap[j]]))) {
            j++;
        }
        
        if ((tree[v].fc.freq < tree[s->heap[j]].fc.freq || (tree[v].fc.freq == tree[s->heap[j]].fc.freq && s->depth[v] <= s->depth[s->heap[j]]))) break;

        s->heap[k] = s->heap[j];  k = j;

        j <<= 1;
    }
    s->heap[k] = v;
}

static void FUN_00b9f7b0(deflate_state* s, tree_desc* desc)
{
    ct_data *tree        = desc->dyn_tree;
    int max_code         = desc->max_code;
    const ct_data *stree = desc->stat_desc->static_tree;
    const intf *extra    = desc->stat_desc->extra_bits;
    int base             = desc->stat_desc->extra_base;
    int max_length       = desc->stat_desc->max_length;
    int h;              
    int n, m;           
    int bits;           
    int xbits;          
    ush f;              
    int overflow = 0;   

    for (bits = 0; bits <= 15; bits++) s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl.len = 0; 

    for (h = s->heap_max+1; h < 573; h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl.dad].dl.len + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].dl.len = (ush)bits;

        if (n > max_code) continue; 

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n-base];
        f = tree[n].fc.freq;
        s->opt_len += (ulg)f * (bits + xbits);
        if (stree) s->static_len += (ulg)f * (stree[n].dl.len + xbits);
    }
    if (overflow == 0) return;

    do {
        bits = max_length-1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;      
        s->bl_count[bits+1] += 2; 
        s->bl_count[max_length]--;
        
        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if (tree[m].dl.len != (unsigned) bits) {
                s->opt_len += ((long)bits - (long)tree[m].dl.len)
                              *(long)tree[m].fc.freq;
                tree[m].dl.len = (ush)bits;
            }
            n--;
        }
    }
}

// pdb: build_bl_tree | trees.obj | fnv360_0822_retail, objrun_sim, low, conflict (skyrim: gen_codes)
static void FUN_00ba08d0(ct_data* tree, int max_code, ushf* bl_count)
{
    ush next_code[15+1]; 
    ush code = 0;              
    int bits;                  
    int n;                     

    for (bits = 1; bits <= 15; bits++) {
        next_code[bits] = code = (code + bl_count[bits-1]) << 1;
    }
    
    for (n = 0;  n <= max_code; n++) {
        int len = tree[n].dl.len;
        if (len == 0) continue;
        
        tree[n].fc.code = bi_reverse(next_code[len]++, len);

        }
}

// pdb: build_tree | trees.obj | fnv360_0721_beta, call_gap_sim + skyrim(call_seq), high
static void build_tree(deflate_state* s, tree_desc* desc)
{
    ct_data *tree         = desc->dyn_tree;
    const ct_data *stree  = desc->stat_desc->static_tree;
    int elems             = desc->stat_desc->elems;
    int n, m;          
    int max_code = -1; 
    int node;          

    s->heap_len = 0, s->heap_max = 573;

    for (n = 0; n < elems; n++) {
        if (tree[n].fc.freq != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].dl.len = 0;
        }
    }

    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].fc.freq = 1;
        s->depth[node] = 0;
        s->opt_len--; if (stree) s->static_len -= stree[node].dl.len;
        
    }
    desc->max_code = max_code;

    for (n = s->heap_len/2; n >= 1; n--) FUN_00b9f6e0(s, tree, n);

    node = elems;              
    do {
        { n = s->heap[1]; s->heap[1] = s->heap[s->heap_len--]; FUN_00b9f6e0(s, tree, 1); }  
        m = s->heap[1]; 

        s->heap[--(s->heap_max)] = n; 
        s->heap[--(s->heap_max)] = m;

        tree[node].fc.freq = tree[n].fc.freq + tree[m].fc.freq;
        s->depth[node] = (uch)((s->depth[n] >= s->depth[m] ?
                                (int)s->depth[n] : (int)s->depth[m]) + 1);
        tree[n].dl.dad = tree[m].dl.dad = (ush)node;

        s->heap[1] = node++;
        FUN_00b9f6e0(s, tree, 1);

    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[1];

    FUN_00b9f7b0(s, (tree_desc *)desc);

    FUN_00ba08d0 ((ct_data *)tree, max_code, s->bl_count);
}

static unsigned bi_reverse(unsigned code, int len)
{
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

deflate_state* volatile input_state_0077;
tree_desc* volatile input_tree_0077;
void EmitTree0077() { build_tree(input_state_0077, input_tree_0077); }
}   // namespace f3m_00ba0960

// @f3 0x00ba2db0 (community match, verified in this file)
namespace f3m_00ba2db0 {
struct FillRecordFO3
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
// pdb: std::vector<CSpeedTreeRT *,std::allocator<CSpeedTreeRT *> >::_Inside | SpeedTreeRT.obj | fnv360_0822_debug, objrun_open, low
// pdb params: _Ptr
void FUN_00ba2db0(FillRecordFO3* first, FillRecordFO3* last, const FillRecordFO3& value)
{
    for (; first != last; ++first)
        *first = value;
}
}   // namespace f3m_00ba2db0

// @f3 0x00ba0cd0 (community match, verified in this file)
namespace f3m_00ba0cd0 {
// Adapted from zlib 1.2.1 trees.c and deflate.h; original typed tables and macro expressions expanded to C++.
namespace f3_00ba0cd0 {
typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef unsigned char uch;
typedef unsigned char uchf;
typedef unsigned short ush;
typedef unsigned short ushf;
typedef unsigned short Posf;
typedef unsigned int uInt;
typedef unsigned int IPos;
typedef unsigned long ulg;
struct z_stream_s;
typedef z_stream_s* z_streamp;
struct ct_data_s {
    union { ush freq; ush code; } fc;
    union { ush dad; ush len; } dl;
};
typedef ct_data_s ct_data;
struct static_tree_desc_s;
struct tree_desc_s {
    ct_data* dyn_tree;
    int max_code;
    static_tree_desc_s* stat_desc;
};
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    

                

    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        

    Bytef *window;
    

    ulg window_size;
    

    Posf *prev;
    

    Posf *head; 

    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      

    uInt  hash_shift;
    

    long block_start;
    

    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              

    uInt prev_length;
    

    uInt max_chain_length;
    

    uInt max_lazy_match;

    

    int level;    
    int strategy; 

    uInt good_match;
    

    int nice_match; 

                
    
    struct ct_data_s dyn_ltree[573];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  

    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              

    ush bl_count[15+1];
    

    int heap[2*286+1];      
    int heap_len;               
    int heap_max;               
    

    uch depth[2*286+1];
    

    uchf *l_buf;          

    uInt  lit_bufsize;
    

    uInt last_lit;      

    ushf *d_buf;
    

    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   



    ush bi_buf;
    
    int bi_valid;
    

} deflate_state;
static const ct_data static_ltree[288] = {
{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},
{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}},
{{ 92},{  8}}, {{220},{  8}}, {{ 60},{  8}}, {{188},{  8}}, {{124},{  8}},
{{252},{  8}}, {{  2},{  8}}, {{130},{  8}}, {{ 66},{  8}}, {{194},{  8}},
{{ 34},{  8}}, {{162},{  8}}, {{ 98},{  8}}, {{226},{  8}}, {{ 18},{  8}},
{{146},{  8}}, {{ 82},{  8}}, {{210},{  8}}, {{ 50},{  8}}, {{178},{  8}},
{{114},{  8}}, {{242},{  8}}, {{ 10},{  8}}, {{138},{  8}}, {{ 74},{  8}},
{{202},{  8}}, {{ 42},{  8}}, {{170},{  8}}, {{106},{  8}}, {{234},{  8}},
{{ 26},{  8}}, {{154},{  8}}, {{ 90},{  8}}, {{218},{  8}}, {{ 58},{  8}},
{{186},{  8}}, {{122},{  8}}, {{250},{  8}}, {{  6},{  8}}, {{134},{  8}},
{{ 70},{  8}}, {{198},{  8}}, {{ 38},{  8}}, {{166},{  8}}, {{102},{  8}},
{{230},{  8}}, {{ 22},{  8}}, {{150},{  8}}, {{ 86},{  8}}, {{214},{  8}},
{{ 54},{  8}}, {{182},{  8}}, {{118},{  8}}, {{246},{  8}}, {{ 14},{  8}},
{{142},{  8}}, {{ 78},{  8}}, {{206},{  8}}, {{ 46},{  8}}, {{174},{  8}},
{{110},{  8}}, {{238},{  8}}, {{ 30},{  8}}, {{158},{  8}}, {{ 94},{  8}},
{{222},{  8}}, {{ 62},{  8}}, {{190},{  8}}, {{126},{  8}}, {{254},{  8}},
{{  1},{  8}}, {{129},{  8}}, {{ 65},{  8}}, {{193},{  8}}, {{ 33},{  8}},
{{161},{  8}}, {{ 97},{  8}}, {{225},{  8}}, {{ 17},{  8}}, {{145},{  8}},
{{ 81},{  8}}, {{209},{  8}}, {{ 49},{  8}}, {{177},{  8}}, {{113},{  8}},
{{241},{  8}}, {{  9},{  8}}, {{137},{  8}}, {{ 73},{  8}}, {{201},{  8}},
{{ 41},{  8}}, {{169},{  8}}, {{105},{  8}}, {{233},{  8}}, {{ 25},{  8}},
{{153},{  8}}, {{ 89},{  8}}, {{217},{  8}}, {{ 57},{  8}}, {{185},{  8}},
{{121},{  8}}, {{249},{  8}}, {{  5},{  8}}, {{133},{  8}}, {{ 69},{  8}},
{{197},{  8}}, {{ 37},{  8}}, {{165},{  8}}, {{101},{  8}}, {{229},{  8}},
{{ 21},{  8}}, {{149},{  8}}, {{ 85},{  8}}, {{213},{  8}}, {{ 53},{  8}},
{{181},{  8}}, {{117},{  8}}, {{245},{  8}}, {{ 13},{  8}}, {{141},{  8}},
{{ 77},{  8}}, {{205},{  8}}, {{ 45},{  8}}, {{173},{  8}}, {{109},{  8}},
{{237},{  8}}, {{ 29},{  8}}, {{157},{  8}}, {{ 93},{  8}}, {{221},{  8}},
{{ 61},{  8}}, {{189},{  8}}, {{125},{  8}}, {{253},{  8}}, {{ 19},{  9}},
{{275},{  9}}, {{147},{  9}}, {{403},{  9}}, {{ 83},{  9}}, {{339},{  9}},
{{211},{  9}}, {{467},{  9}}, {{ 51},{  9}}, {{307},{  9}}, {{179},{  9}},
{{435},{  9}}, {{115},{  9}}, {{371},{  9}}, {{243},{  9}}, {{499},{  9}},
{{ 11},{  9}}, {{267},{  9}}, {{139},{  9}}, {{395},{  9}}, {{ 75},{  9}},
{{331},{  9}}, {{203},{  9}}, {{459},{  9}}, {{ 43},{  9}}, {{299},{  9}},
{{171},{  9}}, {{427},{  9}}, {{107},{  9}}, {{363},{  9}}, {{235},{  9}},
{{491},{  9}}, {{ 27},{  9}}, {{283},{  9}}, {{155},{  9}}, {{411},{  9}},
{{ 91},{  9}}, {{347},{  9}}, {{219},{  9}}, {{475},{  9}}, {{ 59},{  9}},
{{315},{  9}}, {{187},{  9}}, {{443},{  9}}, {{123},{  9}}, {{379},{  9}},
{{251},{  9}}, {{507},{  9}}, {{  7},{  9}}, {{263},{  9}}, {{135},{  9}},
{{391},{  9}}, {{ 71},{  9}}, {{327},{  9}}, {{199},{  9}}, {{455},{  9}},
{{ 39},{  9}}, {{295},{  9}}, {{167},{  9}}, {{423},{  9}}, {{103},{  9}},
{{359},{  9}}, {{231},{  9}}, {{487},{  9}}, {{ 23},{  9}}, {{279},{  9}},
{{151},{  9}}, {{407},{  9}}, {{ 87},{  9}}, {{343},{  9}}, {{215},{  9}},
{{471},{  9}}, {{ 55},{  9}}, {{311},{  9}}, {{183},{  9}}, {{439},{  9}},
{{119},{  9}}, {{375},{  9}}, {{247},{  9}}, {{503},{  9}}, {{ 15},{  9}},
{{271},{  9}}, {{143},{  9}}, {{399},{  9}}, {{ 79},{  9}}, {{335},{  9}},
{{207},{  9}}, {{463},{  9}}, {{ 47},{  9}}, {{303},{  9}}, {{175},{  9}},
{{431},{  9}}, {{111},{  9}}, {{367},{  9}}, {{239},{  9}}, {{495},{  9}},
{{ 31},{  9}}, {{287},{  9}}, {{159},{  9}}, {{415},{  9}}, {{ 95},{  9}},
{{351},{  9}}, {{223},{  9}}, {{479},{  9}}, {{ 63},{  9}}, {{319},{  9}},
{{191},{  9}}, {{447},{  9}}, {{127},{  9}}, {{383},{  9}}, {{255},{  9}},
{{511},{  9}}, {{  0},{  7}}, {{ 64},{  7}}, {{ 32},{  7}}, {{ 96},{  7}},
{{ 16},{  7}}, {{ 80},{  7}}, {{ 48},{  7}}, {{112},{  7}}, {{  8},{  7}},
{{ 72},{  7}}, {{ 40},{  7}}, {{104},{  7}}, {{ 24},{  7}}, {{ 88},{  7}},
{{ 56},{  7}}, {{120},{  7}}, {{  4},{  7}}, {{ 68},{  7}}, {{ 36},{  7}},
{{100},{  7}}, {{ 20},{  7}}, {{ 84},{  7}}, {{ 52},{  7}}, {{116},{  7}},
{{  3},{  8}}, {{131},{  8}}, {{ 67},{  8}}, {{195},{  8}}, {{ 35},{  8}},
{{163},{  8}}, {{ 99},{  8}}, {{227},{  8}}
};
// pdb: bi_flush | trees.obj | fnv360_0822_retail, call_dedup, low
static __declspec(noinline) void FUN_00ba06d0(deflate_state* s)
{
    if (s->bi_valid == 16) {
        s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        s->pending_buf[s->pending++] = (Byte)s->bi_buf;
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}
// pdb: _tr_align | trees.obj | fnv360_0822_retail, call_gap + skyrim(objrun), high
void __cdecl _tr_align(deflate_state* s)
{
{
    int len = 3;
    if (s->bi_valid > 16 - len) {
        int val = 1 << 1;
        s->bi_buf |= (val << s->bi_valid);
        s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);
        s->bi_buf = (ush)val >> (16 - s->bi_valid);
        s->bi_valid += len - 16;
    } else {
        s->bi_buf |= (1 << 1) << s->bi_valid;
        s->bi_valid += len;
    }
}
{
    int len = static_ltree[256].dl.len;
    if (s->bi_valid > 16 - len) {
        int val = static_ltree[256].fc.code;
        s->bi_buf |= (val << s->bi_valid);
        s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);
        s->bi_buf = (ush)val >> (16 - s->bi_valid);
        s->bi_valid += len - 16;
    } else {
        s->bi_buf |= (static_ltree[256].fc.code) << s->bi_valid;
        s->bi_valid += len;
    }
}
FUN_00ba06d0(s);
if (1 + s->last_eob_len + 10 - s->bi_valid < 9) {
{
    int len = 3;
    if (s->bi_valid > 16 - len) {
        int val = 1 << 1;
        s->bi_buf |= (val << s->bi_valid);
        s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);
        s->bi_buf = (ush)val >> (16 - s->bi_valid);
        s->bi_valid += len - 16;
    } else {
        s->bi_buf |= (1 << 1) << s->bi_valid;
        s->bi_valid += len;
    }
}
{
    int len = static_ltree[256].dl.len;
    if (s->bi_valid > 16 - len) {
        int val = static_ltree[256].fc.code;
        s->bi_buf |= (val << s->bi_valid);
        s->pending_buf[s->pending++] = (uch)((s->bi_buf) & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(s->bi_buf) >> 8);
        s->bi_buf = (ush)val >> (16 - s->bi_valid);
        s->bi_valid += len - 16;
    } else {
        s->bi_buf |= (static_ltree[256].fc.code) << s->bi_valid;
        s->bi_valid += len;
    }
}
FUN_00ba06d0(s);
}
s->last_eob_len = 7;
}
}
}   // namespace f3m_00ba0cd0

// @f3 0x00ba0ec0 (community match, verified in this file)
namespace f3m_00ba0ec0 {
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/

// Adapted from zlib 1.2.1 trees.c, Copyright (C) 1995-2003 Jean-loup Gailly.
// Altered for the FO3 contribution: C++ declarations and explicit macro expansions.
// Original source and license retained in the local FNV reference checkout.
typedef unsigned char uch; typedef unsigned char Byte; typedef unsigned char Bytef; typedef unsigned char uchf;
typedef unsigned short ush; typedef unsigned short ushf; typedef unsigned short Posf; typedef unsigned int uInt; typedef unsigned int IPos;
typedef unsigned long ulg; typedef int intf; typedef void* z_streamp;
typedef struct ct_data_s { union { ush freq; ush code; } fc; union { ush dad; ush len; } dl; } ct_data;
typedef struct static_tree_desc_s static_tree_desc;
typedef struct tree_desc_s { ct_data* dyn_tree; int max_code; static_tree_desc* stat_desc; } tree_desc;
struct static_tree_desc_s {
    const ct_data *static_tree;  
    const intf *extra_bits;      
    int     extra_base;          
    int     elems;               
    int     max_length;          
};
typedef struct internal_state {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    

    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        

    Bytef *window;

    ulg window_size;

    Posf *prev;

    Posf *head; 

    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      

    uInt  hash_shift;

    long block_start;

    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              

    uInt prev_length;

    uInt max_chain_length;

    uInt max_lazy_match;

    int level;    
    int strategy; 

    uInt good_match;

    int nice_match; 

    struct ct_data_s dyn_ltree[573];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  

    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              

    ush bl_count[15+1];

    int heap[2*286+1];      
    int heap_len;               
    int heap_max;               

    uch depth[2*286+1];

    uchf *l_buf;          

    uInt  lit_bufsize;

    uInt last_lit;      

    ushf *d_buf;

    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   

    ush bi_buf;
    
    int bi_valid;

} deflate_state;

typedef char charf;
void _tr_stored_block(deflate_state*,charf*,ulg,int);
static const int extra_lbits[29] 
   = {0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0};

static const int extra_dbits[30] 
   = {0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13};

static const int extra_blbits[19]
   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,7};

static const uch bl_order[19]
   = {16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15};

static const ct_data DAT_00ea6788[(256+1+29)+2] = {
{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},
{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}},
{{ 92},{  8}}, {{220},{  8}}, {{ 60},{  8}}, {{188},{  8}}, {{124},{  8}},
{{252},{  8}}, {{  2},{  8}}, {{130},{  8}}, {{ 66},{  8}}, {{194},{  8}},
{{ 34},{  8}}, {{162},{  8}}, {{ 98},{  8}}, {{226},{  8}}, {{ 18},{  8}},
{{146},{  8}}, {{ 82},{  8}}, {{210},{  8}}, {{ 50},{  8}}, {{178},{  8}},
{{114},{  8}}, {{242},{  8}}, {{ 10},{  8}}, {{138},{  8}}, {{ 74},{  8}},
{{202},{  8}}, {{ 42},{  8}}, {{170},{  8}}, {{106},{  8}}, {{234},{  8}},
{{ 26},{  8}}, {{154},{  8}}, {{ 90},{  8}}, {{218},{  8}}, {{ 58},{  8}},
{{186},{  8}}, {{122},{  8}}, {{250},{  8}}, {{  6},{  8}}, {{134},{  8}},
{{ 70},{  8}}, {{198},{  8}}, {{ 38},{  8}}, {{166},{  8}}, {{102},{  8}},
{{230},{  8}}, {{ 22},{  8}}, {{150},{  8}}, {{ 86},{  8}}, {{214},{  8}},
{{ 54},{  8}}, {{182},{  8}}, {{118},{  8}}, {{246},{  8}}, {{ 14},{  8}},
{{142},{  8}}, {{ 78},{  8}}, {{206},{  8}}, {{ 46},{  8}}, {{174},{  8}},
{{110},{  8}}, {{238},{  8}}, {{ 30},{  8}}, {{158},{  8}}, {{ 94},{  8}},
{{222},{  8}}, {{ 62},{  8}}, {{190},{  8}}, {{126},{  8}}, {{254},{  8}},
{{  1},{  8}}, {{129},{  8}}, {{ 65},{  8}}, {{193},{  8}}, {{ 33},{  8}},
{{161},{  8}}, {{ 97},{  8}}, {{225},{  8}}, {{ 17},{  8}}, {{145},{  8}},
{{ 81},{  8}}, {{209},{  8}}, {{ 49},{  8}}, {{177},{  8}}, {{113},{  8}},
{{241},{  8}}, {{  9},{  8}}, {{137},{  8}}, {{ 73},{  8}}, {{201},{  8}},
{{ 41},{  8}}, {{169},{  8}}, {{105},{  8}}, {{233},{  8}}, {{ 25},{  8}},
{{153},{  8}}, {{ 89},{  8}}, {{217},{  8}}, {{ 57},{  8}}, {{185},{  8}},
{{121},{  8}}, {{249},{  8}}, {{  5},{  8}}, {{133},{  8}}, {{ 69},{  8}},
{{197},{  8}}, {{ 37},{  8}}, {{165},{  8}}, {{101},{  8}}, {{229},{  8}},
{{ 21},{  8}}, {{149},{  8}}, {{ 85},{  8}}, {{213},{  8}}, {{ 53},{  8}},
{{181},{  8}}, {{117},{  8}}, {{245},{  8}}, {{ 13},{  8}}, {{141},{  8}},
{{ 77},{  8}}, {{205},{  8}}, {{ 45},{  8}}, {{173},{  8}}, {{109},{  8}},
{{237},{  8}}, {{ 29},{  8}}, {{157},{  8}}, {{ 93},{  8}}, {{221},{  8}},
{{ 61},{  8}}, {{189},{  8}}, {{125},{  8}}, {{253},{  8}}, {{ 19},{  9}},
{{275},{  9}}, {{147},{  9}}, {{403},{  9}}, {{ 83},{  9}}, {{339},{  9}},
{{211},{  9}}, {{467},{  9}}, {{ 51},{  9}}, {{307},{  9}}, {{179},{  9}},
{{435},{  9}}, {{115},{  9}}, {{371},{  9}}, {{243},{  9}}, {{499},{  9}},
{{ 11},{  9}}, {{267},{  9}}, {{139},{  9}}, {{395},{  9}}, {{ 75},{  9}},
{{331},{  9}}, {{203},{  9}}, {{459},{  9}}, {{ 43},{  9}}, {{299},{  9}},
{{171},{  9}}, {{427},{  9}}, {{107},{  9}}, {{363},{  9}}, {{235},{  9}},
{{491},{  9}}, {{ 27},{  9}}, {{283},{  9}}, {{155},{  9}}, {{411},{  9}},
{{ 91},{  9}}, {{347},{  9}}, {{219},{  9}}, {{475},{  9}}, {{ 59},{  9}},
{{315},{  9}}, {{187},{  9}}, {{443},{  9}}, {{123},{  9}}, {{379},{  9}},
{{251},{  9}}, {{507},{  9}}, {{  7},{  9}}, {{263},{  9}}, {{135},{  9}},
{{391},{  9}}, {{ 71},{  9}}, {{327},{  9}}, {{199},{  9}}, {{455},{  9}},
{{ 39},{  9}}, {{295},{  9}}, {{167},{  9}}, {{423},{  9}}, {{103},{  9}},
{{359},{  9}}, {{231},{  9}}, {{487},{  9}}, {{ 23},{  9}}, {{279},{  9}},
{{151},{  9}}, {{407},{  9}}, {{ 87},{  9}}, {{343},{  9}}, {{215},{  9}},
{{471},{  9}}, {{ 55},{  9}}, {{311},{  9}}, {{183},{  9}}, {{439},{  9}},
{{119},{  9}}, {{375},{  9}}, {{247},{  9}}, {{503},{  9}}, {{ 15},{  9}},
{{271},{  9}}, {{143},{  9}}, {{399},{  9}}, {{ 79},{  9}}, {{335},{  9}},
{{207},{  9}}, {{463},{  9}}, {{ 47},{  9}}, {{303},{  9}}, {{175},{  9}},
{{431},{  9}}, {{111},{  9}}, {{367},{  9}}, {{239},{  9}}, {{495},{  9}},
{{ 31},{  9}}, {{287},{  9}}, {{159},{  9}}, {{415},{  9}}, {{ 95},{  9}},
{{351},{  9}}, {{223},{  9}}, {{479},{  9}}, {{ 63},{  9}}, {{319},{  9}},
{{191},{  9}}, {{447},{  9}}, {{127},{  9}}, {{383},{  9}}, {{255},{  9}},
{{511},{  9}}, {{  0},{  7}}, {{ 64},{  7}}, {{ 32},{  7}}, {{ 96},{  7}},
{{ 16},{  7}}, {{ 80},{  7}}, {{ 48},{  7}}, {{112},{  7}}, {{  8},{  7}},
{{ 72},{  7}}, {{ 40},{  7}}, {{104},{  7}}, {{ 24},{  7}}, {{ 88},{  7}},
{{ 56},{  7}}, {{120},{  7}}, {{  4},{  7}}, {{ 68},{  7}}, {{ 36},{  7}},
{{100},{  7}}, {{ 20},{  7}}, {{ 84},{  7}}, {{ 52},{  7}}, {{116},{  7}},
{{  3},{  8}}, {{131},{  8}}, {{ 67},{  8}}, {{195},{  8}}, {{ 35},{  8}},
{{163},{  8}}, {{ 99},{  8}}, {{227},{  8}}
};

static const ct_data DAT_00ea6c08[30] = {
{{ 0},{ 5}}, {{16},{ 5}}, {{ 8},{ 5}}, {{24},{ 5}}, {{ 4},{ 5}},
{{20},{ 5}}, {{12},{ 5}}, {{28},{ 5}}, {{ 2},{ 5}}, {{18},{ 5}},
{{10},{ 5}}, {{26},{ 5}}, {{ 6},{ 5}}, {{22},{ 5}}, {{14},{ 5}},
{{30},{ 5}}, {{ 1},{ 5}}, {{17},{ 5}}, {{ 9},{ 5}}, {{25},{ 5}},
{{ 5},{ 5}}, {{21},{ 5}}, {{13},{ 5}}, {{29},{ 5}}, {{ 3},{ 5}},
{{19},{ 5}}, {{11},{ 5}}, {{27},{ 5}}, {{ 7},{ 5}}, {{23},{ 5}}
};

const uch _dist_code[512] = {
 0,  1,  2,  3,  4,  4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  8,
 8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 10,
10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13,
13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0, 16, 17,
18, 18, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22,
23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
};

const uch _length_code[258-3+1]= {
 0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 12, 12,
13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16,
17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19,
19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22,
22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23,
23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 28
};

static const int base_length[29] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 20, 24, 28, 32, 40, 48, 56,
64, 80, 96, 112, 128, 160, 192, 224, 0
};

static const int base_dist[30] = {
    0,     1,     2,     3,     4,     6,     8,    12,    16,    24,
   32,    48,    64,    96,   128,   192,   256,   384,   512,   768,
 1024,  1536,  2048,  3072,  4096,  6144,  8192, 12288, 16384, 24576
};

static static_tree_desc  static_l_desc =
{DAT_00ea6788, extra_lbits, 256+1, (256+1+29), 15};

static static_tree_desc  static_d_desc =
{DAT_00ea6c08, extra_dbits, 0,          30, 15};

static static_tree_desc  static_bl_desc =
{(const ct_data *)0, extra_blbits, 0,   19, 7};

static void FUN_00b9f670     (deflate_state *s);
static void pqdownheap     (deflate_state *s, ct_data *tree, int k);
static void gen_bitlen     (deflate_state *s, tree_desc *desc);
static void gen_codes      (ct_data *tree, int max_code, ushf *bl_count);
static void build_tree     (deflate_state *s, tree_desc *desc);
static void scan_tree      (deflate_state *s, ct_data *tree, int max_code);
static void send_tree      (deflate_state *s, ct_data *tree, int max_code);
static int  build_bl_tree  (deflate_state *s);
static void FUN_00b9ffd0 (deflate_state *s, int lcodes, int dcodes, int blcodes);
static void FUN_00ba0230 (deflate_state *s, ct_data *ltree, ct_data *dtree);
static void FUN_00ba0640  (deflate_state *s);
static unsigned bi_reverse (unsigned value, int length);
static void FUN_00ba0750      (deflate_state *s);
static void copy_block     (deflate_state *s, charf *buf, unsigned len, int header);

static void FUN_00b9f670(deflate_state *s)
{
    int n; 

    for (n = 0; n < (256+1+29);  n++) s->dyn_ltree[n].fc.freq = 0;
    for (n = 0; n < 30;  n++) s->dyn_dtree[n].fc.freq = 0;
    for (n = 0; n < 19; n++) s->bl_tree[n].fc.freq = 0;

    s->dyn_ltree[256].fc.freq = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

static void pqdownheap(deflate_state *s, ct_data *tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;  
    while (j <= s->heap_len) {
        
        if (j < s->heap_len &&
            (tree[s->heap[j+1]].fc.freq < tree[s->heap[j]].fc.freq || (tree[s->heap[j+1]].fc.freq == tree[s->heap[j]].fc.freq && s->depth[s->heap[j+1]] <= s->depth[s->heap[j]]))) {
            j++;
        }
        
        if ((tree[v].fc.freq < tree[s->heap[j]].fc.freq || (tree[v].fc.freq == tree[s->heap[j]].fc.freq && s->depth[v] <= s->depth[s->heap[j]]))) break;

        s->heap[k] = s->heap[j];  k = j;

        j <<= 1;
    }
    s->heap[k] = v;
}

static void gen_bitlen(deflate_state *s, tree_desc *desc)
{
    ct_data *tree        = desc->dyn_tree;
    int max_code         = desc->max_code;
    const ct_data *stree = desc->stat_desc->static_tree;
    const intf *extra    = desc->stat_desc->extra_bits;
    int base             = desc->stat_desc->extra_base;
    int max_length       = desc->stat_desc->max_length;
    int h;              
    int n, m;           
    int bits;           
    int xbits;          
    ush f;              
    int overflow = 0;   

    for (bits = 0; bits <= 15; bits++) s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl.len = 0; 

    for (h = s->heap_max+1; h < (2*(256+1+29)+1); h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl.dad].dl.len + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].dl.len = (ush)bits;

        if (n > max_code) continue; 

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n-base];
        f = tree[n].fc.freq;
        s->opt_len += (ulg)f * (bits + xbits);
        if (stree) s->static_len += (ulg)f * (stree[n].dl.len + xbits);
    }
    if (overflow == 0) return;

    ;

    do {
        bits = max_length-1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;      
        s->bl_count[bits+1] += 2; 
        s->bl_count[max_length]--;

        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if (tree[m].dl.len != (unsigned) bits) {
                ;
                s->opt_len += ((long)bits - (long)tree[m].dl.len)
                              *(long)tree[m].fc.freq;
                tree[m].dl.len = (ush)bits;
            }
            n--;
        }
    }
}

static void gen_codes(ct_data *tree, int max_code, ushf *bl_count)
{
    ush next_code[15+1]; 
    ush code = 0;              
    int bits;                  
    int n;                     

    for (bits = 1; bits <= 15; bits++) {
        next_code[bits] = code = (code + bl_count[bits-1]) << 1;
    }

    ;
    ;

    for (n = 0;  n <= max_code; n++) {
        int len = tree[n].dl.len;
        if (len == 0) continue;
        
        tree[n].fc.code = bi_reverse(next_code[len]++, len);

        ;
    }
}

static void build_tree(deflate_state *s, tree_desc *desc)
{
    ct_data *tree         = desc->dyn_tree;
    const ct_data *stree  = desc->stat_desc->static_tree;
    int elems             = desc->stat_desc->elems;
    int n, m;          
    int max_code = -1; 
    int node;          

    s->heap_len = 0, s->heap_max = (2*(256+1+29)+1);

    for (n = 0; n < elems; n++) {
        if (tree[n].fc.freq != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].dl.len = 0;
        }
    }

    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].fc.freq = 1;
        s->depth[node] = 0;
        s->opt_len--; if (stree) s->static_len -= stree[node].dl.len;
        
    }
    desc->max_code = max_code;

    for (n = s->heap_len/2; n >= 1; n--) pqdownheap(s, tree, n);

    node = elems;              
    do {
        { n = s->heap[1]; s->heap[1] = s->heap[s->heap_len--]; pqdownheap(s, tree, 1); };  
        m = s->heap[1]; 

        s->heap[--(s->heap_max)] = n; 
        s->heap[--(s->heap_max)] = m;

        tree[node].fc.freq = tree[n].fc.freq + tree[m].fc.freq;
        s->depth[node] = (uch)((s->depth[n] >= s->depth[m] ?
                                (int)s->depth[n] : (int)s->depth[m]) + 1);
        tree[n].dl.dad = tree[m].dl.dad = (ush)node;

        s->heap[1] = node++;
        pqdownheap(s, tree, 1);

    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[1];

    gen_bitlen(s, (tree_desc *)desc);

    gen_codes ((ct_data *)tree, max_code, s->bl_count);
}

static void scan_tree(deflate_state *s, ct_data *tree, int max_code)
{
    int n;                     
    int prevlen = -1;          
    int curlen;                
    int nextlen = tree[0].dl.len; 
    int count = 0;             
    int max_count = 7;         
    int min_count = 4;         

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code+1].dl.len = (ush)0xffff; 

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].dl.len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].fc.freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].fc.freq++;
            s->bl_tree[16].fc.freq++;
        } else if (count <= 10) {
            s->bl_tree[17].fc.freq++;
        } else {
            s->bl_tree[18].fc.freq++;
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

static void send_tree(deflate_state *s, ct_data *tree, int max_code)
{
    int n;                     
    int prevlen = -1;          
    int curlen;                
    int nextlen = tree[0].dl.len; 
    int count = 0;             
    int max_count = 7;         
    int min_count = 4;         

    if (nextlen == 0) max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].dl.len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do { { int len = s->bl_tree[curlen].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[curlen].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[curlen].fc.code) << s->bi_valid; s->bi_valid += len; }}; } while (--count != 0);

        } else if (curlen != 0) {
            if (curlen != prevlen) {
                { int len = s->bl_tree[curlen].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[curlen].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[curlen].fc.code) << s->bi_valid; s->bi_valid += len; }}; count--;
            }
            ;
            { int len = s->bl_tree[16].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[16].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[16].fc.code) << s->bi_valid; s->bi_valid += len; }}; { int len = 2; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = count-3; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (count-3) << s->bi_valid; s->bi_valid += len; }};

        } else if (count <= 10) {
            { int len = s->bl_tree[17].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[17].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[17].fc.code) << s->bi_valid; s->bi_valid += len; }}; { int len = 3; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = count-3; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (count-3) << s->bi_valid; s->bi_valid += len; }};

        } else {
            { int len = s->bl_tree[18].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[18].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[18].fc.code) << s->bi_valid; s->bi_valid += len; }}; { int len = 7; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = count-11; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (count-11) << s->bi_valid; s->bi_valid += len; }};
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

// pdb: build_bl_tree | trees.obj | fnv360_0721_beta, call_gap_sim + skyrim(call_seq), high
static int build_bl_tree(deflate_state *s)
{
    int max_blindex;  

    scan_tree(s, (ct_data *)s->dyn_ltree, s->l_desc.max_code);
    scan_tree(s, (ct_data *)s->dyn_dtree, s->d_desc.max_code);

    build_tree(s, (tree_desc *)(&(s->bl_desc)));

    for (max_blindex = 19-1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[bl_order[max_blindex]].dl.len != 0) break;
    }
    
    s->opt_len += 3*(max_blindex+1) + 5+5+4;

    return max_blindex;
}

static void FUN_00b9ffd0(deflate_state *s, int lcodes, int dcodes, int blcodes) 
{
    int rank;                    

    ;
    ;
    ;
    { int len = 5; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = lcodes-257; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (lcodes-257) << s->bi_valid; s->bi_valid += len; }}; 
    { int len = 5; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = dcodes-1; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (dcodes-1) << s->bi_valid; s->bi_valid += len; }};
    { int len = 4; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = blcodes-4; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (blcodes-4) << s->bi_valid; s->bi_valid += len; }}; 
    for (rank = 0; rank < blcodes; rank++) {
        ;
        { int len = 3; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = s->bl_tree[bl_order[rank]].dl.len; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (s->bl_tree[bl_order[rank]].dl.len) << s->bi_valid; s->bi_valid += len; }};
    }
    ;

    send_tree(s, (ct_data *)s->dyn_ltree, lcodes-1); 
    ;

    send_tree(s, (ct_data *)s->dyn_dtree, dcodes-1); 
    ;
}

// pdb: _tr_stored_block | trees.obj | fnv360_0822_retail, call_gap + skyrim(call_seq), high
void _tr_stored_block(deflate_state *s, charf *buf, ulg stored_len, int eof)
{
    { int len = 3; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = (0<<1)+eof; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= ((0<<1)+eof) << s->bi_valid; s->bi_valid += len; }};  

    copy_block(s, buf, (unsigned)stored_len, 1); 
}

// pdb: _tr_flush_block | trees.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: s, buf, stored_len, eof
void FUN_00ba0ec0(deflate_state *s, charf *buf, ulg stored_len, int eof)
{
    ulg opt_lenb, static_lenb; 
    int max_blindex = 0;  

    if (s->level > 0) {

        if (s->data_type == 2) FUN_00ba0640(s);

        build_tree(s, (tree_desc *)(&(s->l_desc)));

        build_tree(s, (tree_desc *)(&(s->d_desc)));

        max_blindex = build_bl_tree(s);

        opt_lenb = (s->opt_len+3+7)>>3;
        static_lenb = (s->static_len+3+7)>>3;


        if (static_lenb <= opt_lenb) opt_lenb = static_lenb;

    } else {
        opt_lenb = static_lenb = stored_len + 5; 
    }

    if (stored_len+4 <= opt_lenb && buf != (char*)0) {

        _tr_stored_block(s, buf, stored_len, eof);

    } else if (static_lenb == opt_lenb) {

        { int len = 3; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = (1<<1)+eof; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= ((1<<1)+eof) << s->bi_valid; s->bi_valid += len; }};
        FUN_00ba0230(s, (ct_data *)DAT_00ea6788, (ct_data *)DAT_00ea6c08);

    } else {
        { int len = 3; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = (2<<1)+eof; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= ((2<<1)+eof) << s->bi_valid; s->bi_valid += len; }};
        FUN_00b9ffd0(s, s->l_desc.max_code+1, s->d_desc.max_code+1,
                       max_blindex+1);
        FUN_00ba0230(s, (ct_data *)s->dyn_ltree, (ct_data *)s->dyn_dtree);

    }

    FUN_00b9f670(s);

    if (eof) {
        FUN_00ba0750(s);

    }
}

static void FUN_00ba0230(deflate_state *s, ct_data *ltree, ct_data *dtree)
{
    unsigned dist;      
    int lc;             
    unsigned lx = 0;    
    unsigned code;      
    int extra;          

    if (s->last_lit != 0) do {
        dist = s->d_buf[lx];
        lc = s->l_buf[lx++];
        if (dist == 0) {
            { int len = ltree[lc].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = ltree[lc].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (ltree[lc].fc.code) << s->bi_valid; s->bi_valid += len; }}; 
            ;
        } else {
            
            code = _length_code[lc];
            { int len = ltree[code+256+1].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = ltree[code+256+1].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (ltree[code+256+1].fc.code) << s->bi_valid; s->bi_valid += len; }}; 
            extra = extra_lbits[code];
            if (extra != 0) {
                lc -= base_length[code];
                { int len = extra; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = lc; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (lc) << s->bi_valid; s->bi_valid += len; }};       
            }
            dist--; 
            code = ((dist) < 256 ? _dist_code[dist] : _dist_code[256+((dist)>>7)]);
            ;

            { int len = dtree[code].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = dtree[code].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (dtree[code].fc.code) << s->bi_valid; s->bi_valid += len; }};       
            extra = extra_dbits[code];
            if (extra != 0) {
                dist -= base_dist[code];
                { int len = extra; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = dist; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (dist) << s->bi_valid; s->bi_valid += len; }};   
            }
        } 

        ;

    } while (lx < s->last_lit);

    { int len = ltree[256].dl.len; if (s->bi_valid > (int)(8 * 2*sizeof(char)) - len) { int val = ltree[256].fc.code; s->bi_buf |= (val << s->bi_valid); { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; }; s->bi_buf = (ush)val >> ((8 * 2*sizeof(char)) - s->bi_valid); s->bi_valid += len - (8 * 2*sizeof(char)); } else { s->bi_buf |= (ltree[256].fc.code) << s->bi_valid; s->bi_valid += len; }};
    s->last_eob_len = ltree[256].dl.len;
}

// pdb: set_data_type | trees.obj | tesv_win, call_seq, medium
static void FUN_00ba0640(deflate_state *s)
{
    int n = 0;
    unsigned ascii_freq = 0;
    unsigned bin_freq = 0;
    while (n < 7)        bin_freq += s->dyn_ltree[n++].fc.freq;
    while (n < 128)    ascii_freq += s->dyn_ltree[n++].fc.freq;
    while (n < 256) bin_freq += s->dyn_ltree[n++].fc.freq;
    s->data_type = (Byte)(bin_freq > (ascii_freq >> 2) ? 0 : 1);
}

static unsigned bi_reverse(unsigned code, int len)
{
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

// pdb: bi_windup | trees.obj | tesv_win, call_seq, medium
static void FUN_00ba0750(deflate_state *s)
{
    if (s->bi_valid > 8) {
        { {s->pending_buf[s->pending++] = ((uch)((s->bi_buf) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)(s->bi_buf) >> 8));}; };
    } else if (s->bi_valid > 0) {
        {s->pending_buf[s->pending++] = ((Byte)s->bi_buf);};
    }
    s->bi_buf = 0;
    s->bi_valid = 0;

}

static void copy_block(deflate_state *s, charf    *buf, unsigned len, int      header)
{
    FUN_00ba0750(s);        
    s->last_eob_len = 8; 

    if (header) {
        { {s->pending_buf[s->pending++] = ((uch)(((ush)len) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)((ush)len) >> 8));}; };
        { {s->pending_buf[s->pending++] = ((uch)(((ush)~len) & 0xff));}; {s->pending_buf[s->pending++] = ((uch)((ush)((ush)~len) >> 8));}; };

    }

    while (len--) {
        {s->pending_buf[s->pending++] = (*buf++);};
    }
}

}   // namespace f3m_00ba0ec0

// @f3 0x00ba1c50 (community match, verified in this file)
namespace f3m_00ba1c50 {
namespace fo3_ba1c50 {
struct FUN_00b02b70_shell
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned short m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    FUN_00b02b70_shell();
};
// Initializes all fields of the object: sets the first int to -1 and every other field to 0.
// @fnv 0x00b02b70
FUN_00b02b70_shell::FUN_00b02b70_shell()
{
    m_iWordAt00 = -1;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
}


struct FUN_00b02c90_class
{
    char m_iWordAt00;
    float m_iWordAt04;
    int m_8;
    unsigned short m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    FUN_00b02c90_class();
};
// Initializes all members: sets the char and short to 0, the float to -1.0f, and the remaining int fields to 0 or -1.
// @fnv 0x00b02c90
FUN_00b02c90_class::FUN_00b02c90_class()
{
    m_iWordAt00 = 0;
    m_iWordAt04 = -1.0f;
    m_8 = -1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
}
struct FUN_00b02dc0_class
{
    char m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    float m_iThirdValue;
    unsigned short m_10;
    FUN_00b02dc0_class();
};
// Initializes the object's fields to zero, with the float field set to -1.0f.
// @fnv 0x00b02dc0
FUN_00b02dc0_class::FUN_00b02dc0_class()
{
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = -1.0f;
    m_10 = 0;
}


struct BasePart : FUN_00b02b70_shell
{
    ~BasePart();
};
struct RotationPart : FUN_00b02c90_class
{
    ~RotationPart();
};
struct DataPart : FUN_00b02dc0_class
{
    ~DataPart();
};
struct FUN_00ba1c50 : BasePart
{
    float m_38;
    BasePart m_3c;
    float m_74;
    RotationPart m_78;
    RotationPart m_b4;
    DataPart m_f0;
    DataPart m_104;
    DataPart m_118;
    FUN_00ba1c50();
};
// Default constructor for FUN_00ba1c50 that initializes m_38 and m_74 to -1.0f.
// @fnv 0x00b029f0
// pdb: CSpeedTreeRT::SGeometry::SGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
FUN_00ba1c50::FUN_00ba1c50() : m_38(-1.0f), m_74(-1.0f)
{}


}
}   // namespace f3m_00ba1c50

// @f3 0x00bb3070 (community match, verified in this file)
namespace f3m_00bb3070 {
struct LodB28
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    char *p10, *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34, *p38;
    int unk3c;
    char* p40;
};
struct CB28
{
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
    unsigned short count;
    unsigned short unk2a;
    LodB28* lods;
    void FUN_00bb3070();
};
// Frees the twelve heap buffers of each of the count LOD entries and nulls the pointers.
// @fnv 0x00b28ed0
// pdb: CLeafGeometry::FreeLODDataArrays | LeafGeometry.obj | fnv360_0822_retail, call_seq, medium
void CB28::FUN_00bb3070()
{
    if (lods && count)
    {
        for (int i = 0; i < count; ++i)
        {
            delete[] lods[i].p10;
            delete[] lods[i].p14;
            delete[] lods[i].p18;
            delete[] lods[i].p24;
            delete[] lods[i].p28;
            delete[] lods[i].p2c;
            delete[] lods[i].p30;
            delete[] lods[i].p1c;
            delete[] lods[i].p20;
            delete[] lods[i].p34;
            delete[] lods[i].p38;
            lods[i].p10 = 0;
            lods[i].p14 = 0;
            lods[i].p18 = 0;
            lods[i].p24 = 0;
            lods[i].p28 = 0;
            lods[i].p2c = 0;
            lods[i].p30 = 0;
            lods[i].p1c = 0;
            lods[i].p20 = 0;
            lods[i].p34 = 0;
            lods[i].p38 = 0;
            delete[] lods[i].p40;
            lods[i].p40 = 0;
        }
    }
}
}   // namespace f3m_00bb3070

// @f3 0x00bae3d0 (community match, verified in this file)
#include <string.h>
namespace f3m_00bae3d0 {
namespace fo3_00bae3d0 {
struct FUN_00bae3d0_Params
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
};

struct FUN_00bae3d0_cls
{
    int unk00;
    FUN_00bae3d0_Params m_04;
    int unk38;
    FUN_00bae3d0_Params m_3c;
    float unk70;
    int unk74;
    int unk78;
    FUN_00bae3d0_Params m_7c;
    FUN_00bae3d0_cls* FUN_00bae3d0();
};

// Initializes the object's fields and copies three default parameter blocks into m_04, m_3c, and m_7c.
// @fnv 0x00b29fd0
FUN_00bae3d0_cls* FUN_00bae3d0_cls::FUN_00bae3d0()
{
    unk00 = 0;
    unk38 = 0;
    unk70 = 0.5f;
    unk74 = 0;
    unk78 = 0;

    FUN_00bae3d0_Params first;
    first.f00 = 0.8f;
    first.f04 = 0.8f;
    first.f08 = 0.8f;
    first.f0c = 0.2f;
    first.f10 = 0.2f;
    first.f14 = 0.2f;
    first.f18 = 0.0f;
    first.f1c = 0.0f;
    first.f20 = 0.0f;
    first.f24 = 0.0f;
    first.f28 = 0.0f;
    first.f2c = 0.0f;
    first.f30 = 0.0f;

    FUN_00bae3d0_Params second;
    second.f00 = 1.0f;
    second.f04 = 1.0f;
    second.f08 = 1.0f;
    second.f0c = 0.5f;
    second.f10 = 0.5f;
    second.f14 = 0.5f;
    second.f18 = 0.0f;
    second.f1c = 0.0f;
    second.f20 = 0.0f;
    second.f24 = 0.0f;
    second.f28 = 0.0f;
    second.f2c = 0.0f;
    second.f30 = 0.0f;

    FUN_00bae3d0_Params third;
    third.f00 = 1.0f;
    third.f04 = 1.0f;
    third.f08 = 1.0f;
    third.f0c = 0.5f;
    third.f10 = 0.5f;
    third.f14 = 0.5f;
    third.f18 = 0.0f;
    third.f1c = 0.0f;
    third.f20 = 0.0f;
    third.f24 = 0.0f;
    third.f28 = 0.0f;
    third.f2c = 0.0f;
    third.f30 = 0.0f;

    memcpy(&m_04, &first, sizeof(first));
    memcpy(&m_3c, &second, sizeof(second));
    memcpy(&m_7c, &third, sizeof(third));
    return this;
}

}
}   // namespace f3m_00bae3d0

// @f3 0x00bafd80 (community match, verified in this file)
#include <new>
namespace f3m_00bafd80 {
namespace fo3_bafd80 {
unsigned int* __cdecl FUN_00baf540(unsigned int*, unsigned int*, unsigned int*);
struct UIntVector {
 unsigned int allocator;
 unsigned int* _Myfirst;
 unsigned int* _Mylast;
 unsigned int* _Myend;
 unsigned int size() const { return _Myfirst == 0 ? 0 : _Mylast - _Myfirst; }
 unsigned int capacity() const { return _Myfirst == 0 ? 0 : _Myend - _Myfirst; }
 void FUN_00bab240();
 unsigned int* FUN_00bab280(unsigned int*,unsigned int*,unsigned int*);
 bool FUN_00baf7a0(unsigned int);
 UIntVector& FUN_00bafd80(const UIntVector&);
};
// pdb: std::_Move<std::vector<unsigned short,std::allocator<unsigned short> > *,std::vector<unsigned short,std::allocator<unsigned short> > *> | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: _First, _Last, _Dest, __formal
UIntVector& UIntVector::FUN_00bafd80(const UIntVector& r) {
 if (this != &r) {
  if (r.size() == 0) FUN_00bab240();
  else if (r.size() <= size()) {
   unsigned int* end = FUN_00baf540(r._Myfirst,r._Mylast,_Myfirst);
   _Mylast = _Myfirst + r.size();
  } else if (r.size() <= capacity()) {
   unsigned int* split = r._Myfirst + size();
   FUN_00baf540(r._Myfirst,split,_Myfirst);
   _Mylast = FUN_00bab280(split,r._Mylast,_Mylast);
  } else {
   if (_Myfirst != 0) ::operator delete(_Myfirst);
   if (FUN_00baf7a0(r.size())) _Mylast = FUN_00bab280(r._Myfirst,r._Mylast,_Myfirst);
  }
 }
 return *this;
}
}
}   // namespace f3m_00bafd80

// @f3 0x00bb6160 (community match, verified in this file)
#include <new>
namespace f3m_00bb6160 {
namespace fo3_00bb6160 {
unsigned int* __cdecl FUN_00baf540(unsigned int*, unsigned int*, unsigned int*);
struct UIntVector
{
    unsigned int allocatorState;
    unsigned int* first;
    unsigned int* last;
    unsigned int* end;
    unsigned int size() const { return first == 0 ? 0 : last - first; }
    unsigned int capacity() const { return first == 0 ? 0 : end - first; }
    void FUN_00bab240();
    unsigned int* FUN_00bab280(unsigned int*, unsigned int*, unsigned int*);
    bool FUN_004315d0(unsigned int);
    UIntVector& FUN_00bb6160(const UIntVector& source);
};
// pdb: std::vector<float,std::allocator<float> >::operator= | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Right
UIntVector& UIntVector::FUN_00bb6160(const UIntVector& source)
{
    if (this != &source)
    {
        if (source.size() == 0)
            FUN_00bab240();
        else if (source.size() <= size())
        {
            FUN_00baf540(source.first, source.last, first);
            // Unsigned integer elements require no destructor work.
            last = first + source.size();
        }
        else if (source.size() <= capacity())
        {
            unsigned int* middle = source.first + size();
            FUN_00baf540(source.first, middle, first);
            last = FUN_00bab280(middle, source.last, last);
        }
        else
        {
            if (first != 0)
                ::operator delete(first);
            if (FUN_004315d0(source.size()))
                last = FUN_00bab280(source.first, source.last, first);
        }
    }
    return *this;
}
}
}   // namespace f3m_00bb6160

// @f3 0x00bb95b0 (community match, verified in this file)
namespace f3m_00bb95b0 {
struct Entry_bb95b0 { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20; float priority; unsigned int unk28,unk2c; };
extern void __cdecl FUN_00bb9080(Entry_bb95b0*,Entry_bb95b0*,Entry_bb95b0*,int);
extern void __cdecl FUN_00bb6600(Entry_bb95b0*,Entry_bb95b0*);
struct Pred_bb95b0 { bool operator()(const Entry_bb95b0& a,const Entry_bb95b0& b) const { return a.priority > b.priority; } };
void __cdecl FUN_00bb95b0(Entry_bb95b0** result,Entry_bb95b0* first,Entry_bb95b0* last,int comp)
{
 Pred_bb95b0 pred;
 Entry_bb95b0* mid=first+(last-first)/2;
 FUN_00bb9080(first,mid,last-1,comp);
 Entry_bb95b0* left=mid;
 Entry_bb95b0* right=mid+1;
 while (first<left && !pred(*(left-1),*left) && !pred(*left,*(left-1))) --left;
 while (right<last && !pred(*right,*left) && !pred(*left,*right)) ++right;
 Entry_bb95b0* high=right;
 Entry_bb95b0* low=left;
 for (;;) {
   for (;high<last;++high) {
     if (pred(*left,*high)) continue;
     if (pred(*high,*left)) break;
     Entry_bb95b0* oldRight=right; ++right; FUN_00bb6600(oldRight,high);
   }
   for (;first<low;--low) {
     if (pred(*(low-1),*left)) continue;
     if (pred(*left,*(low-1))) break;
     FUN_00bb6600(--left,low-1);
   }
   if (low==first && high==last) break;
   if (low==first) {
     if(right!=high) FUN_00bb6600(left,right);
     Entry_bb95b0* savedHigh=high; Entry_bb95b0* savedLeft=left;
     ++right; ++left; ++high;
     FUN_00bb6600(savedLeft,savedHigh);
   } else {
     --low;
     if (high==last) {
       --left;
       if(low!=left) FUN_00bb6600(low,left);
       --right;
       FUN_00bb6600(left,right);
     } else {
       FUN_00bb6600(high,low);
       ++high;
     }
   }
 }
 result[0]=left; result[1]=right;
}
}   // namespace f3m_00bb95b0

// @f3 0x00bafc60 (community match, verified in this file)
#include <vector>
#include <algorithm>
namespace f3m_00bafc60 {
class WordVector0590 : public std::vector<unsigned short>
{
public:
    WordVector0590& FUN_00bafc60(const WordVector0590& _Right);
};
WordVector0590& WordVector0590::FUN_00bafc60(const WordVector0590& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
            clear();
        else if (_Right.size() <= size())
        {
            pointer _Ptr = stdext::unchecked_copy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            pointer _Ptr = _Right._Myfirst + size();
            stdext::unchecked_copy(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
        }
    }
    return *this;
}
}   // namespace f3m_00bafc60

// @f3 0x00baf7f0 (community match, verified in this file)
namespace f3m_00baf7f0 {
void __cdecl FUN_00401010(void* memory);
__declspec(noreturn) void __cdecl FUN_00bc5f00();
unsigned int* __cdecl FUN_00bbdbe0(unsigned int count, const void* hint);
void __cdecl FUN_00bbdcb0(unsigned int* first, unsigned int* last, const unsigned int& value);
unsigned int* __cdecl FUN_00ba2d80(unsigned int* first, unsigned int* last, unsigned int* end);
struct WordIterator580 { void* container; unsigned int* pointer; };
struct WordVector580 {
    int allocatorState;
    unsigned int* first;
    unsigned int* last;
    unsigned int* end;
    unsigned int size() const { return first == 0 ? 0 : last - first; }
    unsigned int capacity() const { return first == 0 ? 0 : end - first; }
    unsigned int* FUN_00bab280(unsigned int*, unsigned int*, unsigned int*);
    unsigned int* FUN_00bab360(unsigned int*, unsigned int, const unsigned int&);
    void FUN_00baf7f0(WordIterator580 where, unsigned int count, const unsigned int& value);
};
// pdb: std::vector<int,std::allocator<int> >::reserve | Branch.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: _Count
void WordVector580::FUN_00baf7f0(WordIterator580 where, unsigned int count, const unsigned int& value)
{
    unsigned int temporary = value;
    unsigned int capacityValue = capacity();
    if (count == 0) ;
    else if (0x3fffffffU - size() < count) FUN_00bc5f00();
    else if (capacityValue < size() + count) {
        capacityValue = 0x3fffffffU - capacityValue / 2 < capacityValue ? 0 : capacityValue + capacityValue / 2;
        if (capacityValue < size() + count) capacityValue = size() + count;
        unsigned int* newVector = FUN_00bbdbe0(capacityValue, 0);
        unsigned int* ptr = newVector;
        ptr = FUN_00bab280(first, where.pointer, newVector);
        ptr = FUN_00bab360(ptr, count, temporary);
        FUN_00bab280(where.pointer, last, ptr);
        count += size();
        if (first != 0) FUN_00401010(first);
        end = newVector + capacityValue;
        last = newVector + count;
        first = newVector;
    } else if ((unsigned int)(last - where.pointer) < count) {
        FUN_00bab280(where.pointer, last, where.pointer + count);
        FUN_00bab360(last, count - (last - where.pointer), temporary);
        last += count;
        FUN_00bbdcb0(where.pointer, last - count, temporary);
    } else {
        unsigned int* oldEnd = last;
        last = FUN_00bab280(oldEnd - count, oldEnd, last);
        FUN_00ba2d80(where.pointer, oldEnd - count, oldEnd);
        FUN_00bbdcb0(where.pointer, where.pointer + count, temporary);
    }
}
}   // namespace f3m_00baf7f0

// @f3 0x00bbfa10 (community match, verified in this file)
#include <vector>
#include <cstdlib>
#include <ctime>
namespace f3m_00bbfa10 {
struct Vec3 { float x,y,z; Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Matrix { float a,b,c,d,e,f,g,h,i; Matrix():a(1),b(0),c(0),d(0),e(1),f(0),g(0),h(0),i(1){} };
struct Generator { unsigned a,b,c,d,e,f,g,h,i,j; void FUN_00bc4b70(unsigned); float FUN_00bc4b40(float,float); };
struct System { void FUN_00bb2a70(unsigned); void FUN_00baf1d0(int); };
struct FUN_00babd50 { int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p; FUN_00babd50(int); void FUN_00bacd10(unsigned,float,int,void*,float,float,Matrix*,Vec3*,System*,Vec3*,float,unsigned,float); };
struct Elem { int a,b,c,d; Elem(); ~Elem(); };
struct Record {float f00; float f04; float f08; float f0c; float f10; float f14; float f18; float f1c; float f20; float f24; float f28; float f2c; float f30; float f34; float f38; float f3c; float f40; float f44; float f48; float f4c; float f50;};
extern float DAT_00db38b8; extern bool DAT_01068b30; extern int DAT_01068b34; extern int* DAT_011782b0; extern unsigned DAT_011782b8; extern std::vector<void*> DAT_011782d4; void FUN_00bab300();
struct Owner {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
Generator rng;
unsigned seed;
float scale;
float spread;
unsigned cseed;
FUN_00babd50* engine;
System* system;
std::vector<void*> pointers;
unsigned short count70;
Vec3 pos;
int unk80;
int shared;
int unk88;
int unk8c;
int unk90;
std::vector<Record> records;
int unka4;
int unka8;
int unkac;
int unkb0;
int unkb4;
int unkb8;
int unkbc;
unsigned count;
int unkc4;
int unkc8;
int unkcc;
int unkd0;
Elem* elems;
bool mode;
int unkdc;
int unke0;
int unke4;
int unke8;
int unkec;
int global;
void FUN_00bbf090(); void FUN_00bbed60(float); void FUN_00bbfa10(float);
};
// pdb: CTreeEngine::Compute | TreeEngine.obj | fnv360_0822_retail, call_gap, medium
// pdb params: fLeafSizeIncreaseFactor
void Owner::FUN_00bbfa10(float dt) {
 DAT_01068b30 = !mode;
 engine = new FUN_00babd50(0);
 if (!mode) elems = new Elem[count];
 DAT_01068b34 = global;
 FUN_00bab300();
 DAT_011782b0 = &shared;
 for (unsigned i=0; i<pointers.size(); ++i) { void* value=pointers[i]; DAT_011782d4.push_back(value); }
 rng.FUN_00bc4b70(seed);
 float random = rng.FUN_00bc4b40(scale-spread, scale+spread);
 srand(cseed);
 if (scale > 0) for (unsigned i=0; i<records.size(); ++i) { Record& r=records[i]; r.f48=r.f3c*scale; r.f4c=r.f40*scale; }
 rng.FUN_00bc4b70(seed);
 system->FUN_00bb2a70(count70);
 system->FUN_00baf1d0(0);
 Vec3 direction(0,0,1); Matrix rotation;
 DAT_011782b8=seed;
 engine->FUN_00bacd10(seed,random,0,&unk04,0,0,&rotation,&direction,system,&pos,1,seed,DAT_00db38b8);
 FUN_00bbf090();
 if (!mode) FUN_00bbed60(dt);
 srand((unsigned)_time64(0));
}
}   // namespace f3m_00bbfa10

// @f3 0x00ba4bd0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba4bd0 {
namespace tree_ba4bd0 {
struct Geometry {
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
unsigned int unk48;
unsigned int unk4c;
unsigned int unk50;
unsigned int unk54;
std::vector<float> v58;
std::vector<float> v68;
std::vector<float> v78;
std::vector<float> v88;
std::vector<float> v98;
std::vector<float> va8;
std::vector<float> vb8;
std::vector<float> vc8;
std::vector<float> vd8;
std::vector<float> ve8;
std::vector<float> vf8;
std::vector<char> v108;
short FUN_00ba29a0(unsigned short); void* FUN_00ba2a00(unsigned short); void* FUN_00baecf0(unsigned short);
};
struct Tree {
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
unsigned int unk10;
float distance;
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
unsigned int unkac;
unsigned int unkb0;
unsigned int unkb4;
unsigned int unkb8;
unsigned int unkbc;
unsigned short levels; };
struct Override {
unsigned int unk00;
unsigned int unk04;
unsigned int unk08;
unsigned int unk0c;
float distance; };
struct Output {
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
int level; short count; void* data; void* extra; unsigned short vertices; float* positions; float* normals; float* texcoords; float* colors; float* indices; float* tangents; float* attr1; float* attr2; char* bytes; float blend; };
struct Owner { Tree* tree;
unsigned int unk4;
unsigned int unk8;
unsigned int unkc;
unsigned int unk10;
unsigned int unk14;
unsigned int unk18;
float a,b,c,d; unsigned int unk2c,unk30; Override* overrideData; unsigned int unk38,unk3c,unk40; unsigned char blend; unsigned int unk48,unk4c,unk50,unk54,unk58,unk5c; Geometry* geometry;
unsigned short FUN_00ba1f20(float); void FUN_00ba4bd0(Output*,short); };
struct Logger { void FUN_0042f100(const char*,int); }; extern Logger DAT_01068a70; extern char str_00ea72a0[]; extern unsigned char DAT_01178274;
void __cdecl FUN_00ba14c0(float,unsigned short,float,float,float,float,float*,float*,short*,float*);
// pdb: CSpeedTreeRT::GetFrondGeometry | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: sGeometry, sOverrideLodValue
void Owner::FUN_00ba4bd0(Output* out,short level) {
if(geometry) {
unsigned short& vertices=out->vertices; vertices=(unsigned short)(geometry->v68.size()/3);
out->positions=geometry->v58.empty()?0:&geometry->v58[0];
out->indices=geometry->v68.empty()?0:&geometry->v68[0];
out->normals=geometry->v88.empty()?0:&geometry->v88[0];
out->texcoords=geometry->v98.empty()?0:&geometry->v98[0];
out->colors=geometry->va8.empty()?0:&geometry->va8[0];
out->tangents=geometry->vb8.empty()?0:&geometry->vb8[0];
out->attr1=geometry->ve8.empty()?0:&geometry->ve8[0];
out->attr2=geometry->vf8.empty()?0:&geometry->vf8[0];
out->bytes=geometry->v108.empty()?0:&geometry->v108[0];
unsigned short index=level==-1?FUN_00ba1f20(-1.0f):level;
out->level=(short)index;
out->count=geometry->FUN_00ba29a0(index);
out->data=geometry->FUN_00ba2a00(index);
out->extra=geometry->FUN_00baecf0(index);
if(DAT_01178274) {
unsigned short count=tree->levels+1;
float weightA=-1.0f,weightB,aux;
short selectedA=-1;
float distance=overrideData?overrideData->distance:tree->distance; weightB=(float)blend;
FUN_00ba14c0(distance,count,a,d,b,weightB,&weightA,&aux,&selectedA,&distance);
if(selectedA==count-2) out->blend=weightA;
else if(selectedA==count-1) {out->blend=255.0f;out->level=-1;}
else out->blend=weightB;
} else out->blend=(float)blend;
} else DAT_01068a70.FUN_0042f100(str_00ea72a0,0x44);
}
}
}   // namespace f3m_00ba4bd0

// @f3 0x00bb4860 (community match, verified in this file)
#include <vector>
extern float FUN_00e09708;
namespace f3m_00bb4860 {
struct V5 { float x,y,z; V5 operator-(const V5& b) const { V5 v={x-b.x,y-b.y,z-b.z}; return v; } float length() const { float d=x*x+y*y+z*z; *(int*)&d=(*(int*)&d>>1)+0x1fc00000; return d; } };
struct P56 : V5 { int u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34; };
struct Record48 { std::vector<P56> points; float length,half; unsigned char style; float offset,scaled; int u24,u28,u2c; unsigned int FUN_00bb4600(); };
struct Style44 { int u00,u04,u08,u0c,u10,u14,u18; float factor,mult,low,high; };
struct Random5 { Random5() { FUN_00bc4c50(); } ~Random5() { FUN_00a29680(); } void FUN_00bc4c50(); void FUN_00a29680(); float FUN_00bc4b40(float,float); };
struct Target5 { int u00,u04; std::vector<Record48> records; int u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c; std::vector<Style44> styles; void FUN_00bb4860(float); };
// pdb: CFrondEngine::EndGuide | FrondEngine.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: fLodSizeScalar
void Target5::FUN_00bb4860(float scale) {
 Record48& r=records[records.size()-1];
 unsigned i=0;
 for(;i<r.FUN_00bb4600()-1;++i) {
  P56& b=r.points[i+1]; P56& a=r.points[i];
  double y=b.y-a.y, x=b.x-a.x, z=b.z-a.z; float d=x*x+y*y+z*z; *(int*)&d=(*(int*)&d>>1)+0x1fc00000; double estimate=*(volatile float*)&d; r.length=estimate+(*(volatile float*)&r.length);
 }
 Random5 rng;
 if(styles.size()==0) { records[i].style=0; r.half=r.length*0.5; r.offset=0.0f; }
 else {
  r.style=(unsigned int)rng.FUN_00bc4b40(0.0f,FUN_00e09708)%styles.size();
  r.half=styles[r.style].factor*r.length*0.5;
  r.half*=styles[r.style].mult;
  r.offset=rng.FUN_00bc4b40(styles[r.style].low,styles[r.style].high);
  if(records.size()&1) r.offset*=-1.0;
 }
 double factor=*(volatile float*)&scale; r.scaled=factor*(*(volatile float*)&r.length);
}
}   // namespace f3m_00bb4860

// @f3 0x00ba4820 (community match, verified in this file)
#include <vector>
extern unsigned char DAT_01178274;
struct Log4820 { void FUN_0042f100(const char*, int); };
extern Log4820 DAT_01068a70;
extern char DAT_00ea7258[];
void __cdecl FUN_00ba14c0(float,unsigned short,float,float,float,float,float*,float*,short*,short*);
struct Data4820 {
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
    std::vector<int> vec58;
    std::vector<float> vec68;
    std::vector<int> vec78;
    std::vector<int> vec88;
    std::vector<int> vec98;
    std::vector<int> veca8;
    std::vector<int> vecb8;
    std::vector<int> vecc8;
    std::vector<int> vecd8;
    std::vector<int> vece8;
    std::vector<int> vecf8;
    std::vector<unsigned char> vec108;
    short FUN_00ba29a0(unsigned short);
    void* FUN_00ba2a00(unsigned short);
    void* FUN_00baecf0(unsigned short);
};
struct Tree4820 {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    float unk014;
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
    unsigned short levels;
};
struct Branch4820 { int unk00,unk04,unk08,unk0c; float distance; };
struct Out4820 {
 int index; short value; short unk06; void* ptr8; void* ptrc; unsigned short count; short unk12;
 int* p14; int* p18; int* p1c; int* p20; float* p24; int* p28; int* p2c; int* p30; unsigned char* p34; float blend;
};
struct Obj4820 {
 Tree4820* tree; Data4820* data;
 int unk08,unk0c,unk10,unk14,unk18; float a,b,c,d; int unk2c,unk30; Branch4820* branch; int unk38,unk3c,unk40; unsigned char value;
 unsigned short FUN_00ba1ec0(float);
 void FUN_00ba4820(Out4820*,short);
};
// pdb: CSpeedTreeRT::GetBranchGeometry | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: sGeometry, sOverrideLodValue
void Obj4820::FUN_00ba4820(Out4820* out,short index) {
 if(data) {
 out->count=(unsigned short)(data->vec68.size()/3);
 out->p14 = data->vec58.empty()?0:&data->vec58[0];
 out->p24 = data->vec68.empty()?0:&data->vec68[0];
 out->p18 = data->vec88.empty()?0:&data->vec88[0];
 out->p1c = data->vec98.empty()?0:&data->vec98[0];
 out->p20 = data->veca8.empty()?0:&data->veca8[0];
 out->p28 = data->vecb8.empty()?0:&data->vecb8[0];
 out->p2c = data->vece8.empty()?0:&data->vece8[0];
 out->p30 = data->vecf8.empty()?0:&data->vecf8[0];
 out->p34 = data->vec108.empty()?0:&data->vec108[0];
 unsigned short chosen=(index==-1)?FUN_00ba1ec0(-1.0f):index;
 out->index=(short)chosen;
 out->value=data->FUN_00ba29a0(chosen);
 out->ptr8=data->FUN_00ba2a00(chosen);
 out->ptrc=data->FUN_00baecf0(chosen);
 if(DAT_01178274) {
  unsigned short levels=tree->levels+1;
  float result=-1.0f;
  short selected=-1, otherSelected;
  float distance=branch?branch->distance:tree->unk014;
  float other;
  float val=(float)value;
  FUN_00ba14c0(distance,levels,a,d,b,val,&result,&other,&selected,&otherSelected);
  if((short)selected==levels-2) out->blend=result;
  else if((short)selected==levels-1) { out->index=-1; out->blend=255.0f; }
  else out->blend=val;
 } else out->blend=(float)value;
 } else DAT_01068a70.FUN_0042f100(DAT_00ea7258,70);
}

// @f3 0x00bb6850 (community match, verified in this file)
#include <vector>
namespace f3m_00bb6850 {
namespace f3m_00bb6850 {
extern "C" void __cdecl FUN_00401010(void* p);

typedef std::vector<unsigned int> QSub39;

struct QElem39
{
    QSub39 sub;
    float f10;
    float f14;
    unsigned char b18;
    float f1c;
    float f20;
    float f24;
    int i28;
    int i2c;
};

void __cdecl FUN_00bb6850(QElem39* _First, QElem39* _Mid, QElem39* _Last)
{
    int _Shift = _Mid - _First;
    int _Count = _Last - _First;

    for (int _Factor = _Shift; _Factor != 0; )
    {
        int _Tmp = _Count % _Factor;
        _Count = _Factor, _Factor = _Tmp;
    }

    if (_Count < _Last - _First)
        for (; 0 < _Count; --_Count)
        {
            QElem39* _Hole = _First + _Count;
            QElem39* _Next = _Hole;
            QElem39 _Holeval = *_Hole;
            QElem39* _Next1 = _Next + _Shift == _Last ? _First : _Next + _Shift;
            while (_Next1 != _Hole)
            {
                *_Next = *_Next1;
                _Next = _Next1;
                _Next1 = _Shift < _Last - _Next1 ? _Next1 + _Shift
                    : _First + (_Shift - (_Last - _Next1));
            }
            *_Next = _Holeval;
        }
}
}
}   // namespace f3m_00bb6850

// @f3 0x00bbe370 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
namespace f3m_00bbe370 {

class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string&,int);
};
struct FlareReader1540 {
    unsigned int FUN_00ba92d0();
    float FUN_00ba92a0();
};
struct Flare1540 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    float unk24;
    unsigned int unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
};
struct FlareOwner1540 {
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
    std::vector<Flare1540*> flares60;
    void FUN_00bbe370(FlareReader1540*);
};
// pdb: CTreeEngine::ParseFlareInfo | TreeEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void FlareOwner1540::FUN_00bbe370(FlareReader1540* reader)
{
    for (unsigned int i=0;i<flares60.size();++i) {
        if (reader->FUN_00ba92d0()!=0x3e82) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk24=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e83) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk28=reader->FUN_00ba92d0();
        if (reader->FUN_00ba92d0()!=0x3e84) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk2C=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e85) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk30=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e86) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk34=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e87) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk38=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e88) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk3C=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e89) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk40=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e8a) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk44=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e8b) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk48=reader->FUN_00ba92a0();
        if (reader->FUN_00ba92d0()!=0x3e8c) throw IdvFileError("malformed flare info",0);
        flares60[i]->unk4C=reader->FUN_00ba92a0();
    }
    if (reader->FUN_00ba92d0()!=0x3e81) throw IdvFileError("malformed flare info",0);
}
}   // namespace f3m_00bbe370

// @f3 0x00ba40c0 (community match, verified in this file)
#include <new>
#include <vector>
#include <string>
#include <stdexcept>

struct TreeHeap1541 {
    void* FUN_0086b930(unsigned int);
    void FUN_0086ba60(void*);
};
extern TreeHeap1541 DAT_01090a78;
inline void* operator new(size_t size,TreeHeap1541& heap) { return heap.FUN_0086b930(size); }
inline void* operator new[](size_t size,TreeHeap1541& heap) { return heap.FUN_0086b930(size); }
inline void operator delete(void* memory,TreeHeap1541& heap) { heap.FUN_0086ba60(memory); }
inline void operator delete[](void* memory,TreeHeap1541& heap) { heap.FUN_0086ba60(memory); }
template<class T> struct TreeAllocator1541 : std::allocator<T> {
    template<class U> struct rebind { typedef TreeAllocator1541<U> other; };
    TreeAllocator1541() throw() {}
    template<class U> TreeAllocator1541(const TreeAllocator1541<U>&) throw() {}
    T* allocate(size_t count,const void* =0) { return (T*)DAT_01090a78.FUN_0086b930(count*sizeof(T)); }
    void deallocate(T* memory,size_t) { DAT_01090a78.FUN_0086ba60(memory); }
};
template<class T,class U> bool operator==(const TreeAllocator1541<T>&,const TreeAllocator1541<U>&) { return true; }
template<class T,class U> bool operator!=(const TreeAllocator1541<T>&,const TreeAllocator1541<U>&) { return false; }
typedef std::basic_string<char,std::char_traits<char>,TreeAllocator1541<char> > TreeString1541;
class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string&,int);
};
struct TreePath1541 {
    TreeString1541 text;
    TreePath1541(TreeString1541);
    TreeString1541 FUN_00ba3c00();
};
struct TreeReader1541 {
    unsigned int offset;
    std::vector<char> data;
    int FUN_00ba92d0();
    float FUN_00ba92a0();
    TreeString1541 FUN_00ba9460();
    bool FUN_00ba1ab0();
    bool ReadBool() { return data[offset++]!=0; }
};
struct TreeMesh1541 {
    int count00;
    float* values04;
    int count08;
    float* values0C;
    int count10;
    float* values14;
    TreeString1541 name18;
    float unk34,unk38,unk3C,unk40,unk44,unk48,unk4C,unk50;
    TreeMesh1541() : count00(0),values04(0),count08(0),values0C(0),count10(0),values14(0),
        unk34(1.0f),unk38(1.0f),unk3C(0.0f),unk40(1.0f),unk44(0.0f),unk48(0.0f),unk4C(1.0f),unk50(0.0f) {}
};
extern bool DAT_01178275;
struct TreeOwner1541 {
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
    TreeMesh1541* mesh4C;
    unsigned int unk50,unk54,unk58,unk5C,unk60,unk64,unk68;
    bool flag6C,flag6D;
    void FUN_00ba40c0(TreeReader1541*);
};

// pdb: CSpeedTreeRT::ParseTextureCoordInfo | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: pFile
void TreeOwner1541::FUN_00ba40c0(TreeReader1541* reader)
{
    mesh4C=new(DAT_01090a78) TreeMesh1541;
    int tag=reader->FUN_00ba92d0();
    do {
        switch(tag) {
        case 0x2712:
            mesh4C->count00=reader->FUN_00ba92d0();
            if(mesh4C->count00>0) {
                mesh4C->values04=new(DAT_01090a78) float[mesh4C->count00*8];
                for(int i=0;i<mesh4C->count00;++i)
                    for(int j=0;j<8;++j) mesh4C->values04[i*8+j]=reader->FUN_00ba92a0();
            }
            break;
        case 0x2713:
            mesh4C->count08=reader->FUN_00ba92d0();
            if(mesh4C->count08>0) {
                mesh4C->values0C=new(DAT_01090a78) float[mesh4C->count08*8];
                for(int i=0;i<mesh4C->count08;++i) {
                    for(int j=0;j<8;++j) {
                        mesh4C->values0C[i*8+j]=reader->FUN_00ba92a0();
                        if(j%2 && DAT_01178275) mesh4C->values0C[i*8+j]=-mesh4C->values0C[i*8+j];
                    }
                }
            }
            break;
        case 0x2714:
            mesh4C->count10=reader->FUN_00ba92d0();
            if(mesh4C->count10>0) {
                mesh4C->values14=new(DAT_01090a78) float[mesh4C->count10*8];
                for(int i=0;i<mesh4C->count10;++i)
                    for(int j=0;j<8;++j) mesh4C->values14[i*8+j]=reader->FUN_00ba92a0();
            }
            break;
        case 0x2715: {
            TreePath1541 path(reader->FUN_00ba9460());
            mesh4C->name18=path.FUN_00ba3c00();
            break;
        }
        case 0x2716:
            flag6D=reader->ReadBool();
            break;
        case 0x2717:
            flag6C=reader->ReadBool();
            break;
        default:
            throw IdvFileError("malformed texture coord info",0);
        }
        if(reader->FUN_00ba1ab0()) throw IdvFileError("premature end of file reached parsing texture coordinate info",0);
        tag=reader->FUN_00ba92d0();
    } while(tag!=0x2711);
}

// @f3 0x00bb3d00 (community match, verified in this file)
namespace f3m_00bb3d00 {
struct Q3d00 {
    float x, y, z;
    Q3d00() { x = y = z = 0.0f; }
};
struct QElem3d00 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    Q3d00 unk30;
    Q3d00 unk3C;
    Q3d00 unk48;
};
struct QSrc3d00 {
    int unk00; int unk04; int unk08; int unk0C;
    std::vector<QElem3d00> unk10;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    unsigned short unk38; short unk3A;
    int unk3C; int unk40; int unk44; int unk48; int unk4C;
};
class Q3d00Owner {
public:
    int unk00;
    int unk04;
    unsigned short unk08;
    int unk0C;
    int unk10;
    int unk14;
    float* unk18;
    unsigned short unk1C;
    Q3d00* unk20;
    Q3d00* unk24;
    void FUN_00bb36a0(int a, int b);
    void FUN_00bb3d00(int a, int b, const QSrc3d00* src);
};
// pdb: CLeafGeometry::Init | LeafGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: usNumLeafLods, pvLeafLods, sLeafInfo
void Q3d00Owner::FUN_00bb3d00(int a, int b, const QSrc3d00* src)
{
    unk08 = src->unk38;
    unk0C = src->unk4C;
    unk10 = src->unk44;
    unk14 = src->unk48;
    unk1C = (unsigned short)src->unk10.size();
    unk20 = new Q3d00[unk1C];
    unk24 = new Q3d00[unk1C];
    for (int i = 0; i < unk1C; i++) {
        unk20[i] = src->unk10[i].unk48;
        unk24[i] = src->unk10[i].unk30;
    }
    unk18 = new float[unk08 * unk1C * 32];
    FUN_00bb36a0(a, b);
}
}   // namespace f3m_00bb3d00

// @f3 0x00ba4560 (community match, verified in this file)
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
namespace f3m_00ba4560 {

struct QHeap { void FUN_0086ba60(void*); };
extern QHeap DAT_01090a78;

struct QText {
    unsigned char allocator;
    union { char buffer[16]; char* heap; };
    unsigned size;
    unsigned capacity;
    void FUN_0042f100(const char* p, unsigned len);
    void Assign(const char* p) { FUN_0042f100(p, (unsigned)strlen(p)); }
    const char* c_str() const { return capacity >= 16 ? heap : buffer; }
    QText(const char* p) { capacity = 15; size = 0; buffer[0] = 0; Assign(p); }
    ~QText() { if (capacity >= 16) DAT_01090a78.FUN_0086ba60(heap); }
};

extern QText DAT_01068a70;

struct QVec3 { float x, y, z; };

struct QCollisionObject {
    int id;
    QVec3 a;
    QVec3 b;
};

struct QObjectList {
    unsigned allocator;
    QCollisionObject* first;
    QCollisionObject* last;
    QCollisionObject* end;
    unsigned Size() const { if (!first) return 0; return last - first; }
    QCollisionObject& FUN_00ba1990(unsigned index);
};

static __declspec(noinline) QText FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return QText(text);
}

class QTree {
public:
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54;
    QObjectList* objects;

    void FUN_00ba4560(unsigned index, int* id, QVec3* a, QVec3* b);
};

// pdb: CSpeedTreeRT::GetCollisionObject | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: nIndex, eType, pPosition, pDimensions
void QTree::FUN_00ba4560(unsigned index, int* id, QVec3* a, QVec3* b)
{
    if (objects) {
        if (index >= objects->Size()) {
            DAT_01068a70.Assign(FUN_00bb56f0("collision object index (%d) exceeds maximum index (%d)", index, objects->Size()).c_str());
        } else {
            *id = objects->FUN_00ba1990(index).id;
            *a = objects->FUN_00ba1990(index).a;
            *b = objects->FUN_00ba1990(index).b;
        }
    } else {
        DAT_01068a70.Assign("no collision objects are stored with this tree");
    }
}

}

// @f3 0x00ba5630 (community match, verified in this file)
namespace InsertUInt683 {
struct Iterator { void* owner; unsigned int* ptr; };
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
unsigned int* __cdecl FUN_00424af0(unsigned int count, const void* hint);
__declspec(noreturn) void __cdecl FUN_00bc5f00();
unsigned int* __cdecl FUN_00ba2d80(unsigned int* first, unsigned int* last, unsigned int* dest);
void __cdecl FUN_00bbdcb0(unsigned int* first, unsigned int* last, const unsigned int& value);
struct UIntVector {
 unsigned int allocator;
 unsigned int* first;
 unsigned int* last;
 unsigned int* end;
 unsigned int size() const {return first==0 ? 0 : last-first;}
 unsigned int capacity() const {return first==0 ? 0 : end-first;}
 __declspec(noinline) unsigned int* FUN_00bab280(unsigned int* begin,unsigned int* finish,unsigned int* dest) {
  for(;begin!=finish;++begin,++dest) *dest=*begin;
  return dest;
 }
 __declspec(noinline) unsigned int* FUN_00bab360(unsigned int* dest,unsigned int count,const unsigned int& value) {
  for(;count;--count,++dest) *dest=value;
  return dest;
 }
 void FUN_00ba5630(Iterator where,unsigned int count,const unsigned int& value);
};
void UIntVector::FUN_00ba5630(Iterator where,unsigned int count,const unsigned int& value) {
 unsigned int tmp=value;
 unsigned int cap=capacity();
 if(count==0) ;
 else if(0x3fffffffU-size()<count) FUN_00bc5f00();
 else if(cap<size()+count) {
  cap=0x3fffffffU-cap/2<cap ? 0 : cap+cap/2;
  if(cap<size()+count) cap=size()+count;
  unsigned int* newvec=FUN_00424af0(cap,0);
  unsigned int* ptr=newvec;
  ptr=FUN_00bab280(first,where.ptr,newvec);
  ptr=FUN_00bab360(ptr,count,tmp);
  FUN_00bab280(where.ptr,last,ptr);
  count+=size();
  if(first!=0) DAT_01090a78.FUN_0086ba60(first);
  end=newvec+cap;
  last=newvec+count;
  first=newvec;
 } else if((unsigned int)(last-where.ptr)<count) {
  FUN_00bab280(where.ptr,last,where.ptr+count);
  FUN_00bab360(last,count-(last-where.ptr),tmp);
  last+=count;
  FUN_00bbdcb0(where.ptr,last-count,tmp);
 } else {
  unsigned int* oldend=last;
  last=FUN_00bab280(oldend-count,oldend,last);
  FUN_00ba2d80(where.ptr,oldend-count,oldend);
  FUN_00bbdcb0(where.ptr,where.ptr+count,tmp);
 }
}
}

// @f3 0x00ba14c0 (community match, verified in this file)
#include <math.h>
namespace f3m_00ba14c0 {

// pdb: CSpeedTreeRT::GetTransitionValues | SpeedTreeRT.obj | fnv360_0822_retail, call_dedup, low
// pdb params: fLodLevel, usLodCount, fOverlapRadius, fTransitionFactor, fCurveExponent, fTargetAlphaValue, fHighValue, fLowValue, sHighLod, sLowLod
void __cdecl FUN_00ba14c0(float start, unsigned short count, float x, float z, float p, float base,
                          float* out1, float* out2, short* out3, short* out4)
{
    float inv = 1.0f / (float)count;
    float w = (1.0f - start) / inv;
    int k = (int)w;
    float frac = w - k;
    if (frac >= 0.5f)
        k++;
    unsigned short i = (unsigned short)k;
    float rem = (1.0f - start) - (float)i * inv;
    if (i == 0 || i == count || fabs(rem) > x) {
        *out1 = base;
        short v = (short)(int)((1.0f - start) * (float)count);
        *out3 = v;
        *out3 = *out3 < (short)(count - 1) ? *out3 : (short)(count - 1);
        *out2 = 255.0f;
        *out4 = -1;
        return;
    }
    float a1 = 1.0f - (x - rem) / (2.0f * x);
    double den = 1.0 - z;
    float u = 1.0f - (a1 - z) / den;
    if (!(u < 1.0f))
        u = 1.0f;
    double range = 255.0 - base;
    *out3 = (short)(i - 1);
    float e1 = 1.0f - u;
    *out1 = (float)(pow(e1, p) * range + base);
    float v2 = a1 / den;
    if (!(v2 < 1.0f))
        v2 = 1.0f;
    *out4 = i;
    *out2 = (float)(pow(1.0f - v2, p) * range + base);
}
}   // namespace f3m_00ba14c0

// @f3 0x00bb70c0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb70c0 {
namespace task1272 {
struct Inner {int a,b,c,d,e,f,g,h,i,j,k,l,m,n;};
struct Element {std::vector<Inner> elements;float a,b;bool flag;float c,d,e;int f,g;};
void FUN_00bb6e70(Element*,int,int,Element,unsigned);
void FUN_00bb70c0(Element* first,Element* last,Element* destination,Element value,unsigned compare){*destination=*first;FUN_00bb6e70(first,0,last-first,value,compare);}
}
}   // namespace f3m_00bb70c0

// @f3 0x00bab4e0 (community match, verified in this file)
#include <vector>
namespace f3m_00bab4e0 {

namespace f3m_00bab4e0 {
struct TreeNode;

struct ChildEntry
{
    int unk00;
    int unk04;
    TreeNode* node;
};

struct TreeNode
{
    int unk00;
    int unk04;
    std::vector<ChildEntry> children;
    char* buffer;
    int unk1C; int unk20; int unk24; int unk28; int unk2C;
    std::vector<int> values;

    ~TreeNode();
};

// pdb: CIdvBranch::~CIdvBranch | Branch.obj | fnv360_0822_retail, call_gap, low
TreeNode::~TreeNode()
{
    ::operator delete(buffer);
    buffer = 0;
    for (unsigned int i = 0; i < children.size(); i++) {
        TreeNode* node = children[i].node;
        if (node)
            delete node;
        children[i].node = 0;
    }
}
}
}   // namespace f3m_00bab4e0

// @f3 0x00ba3920 (community match, verified in this file)
#pragma intrinsic(strlen)
namespace f3m_00ba3920 {
extern "C" unsigned int __cdecl strlen(const char*);
namespace Task1406 {
struct Heap{void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
int* __cdecl FUN_00c02a76();
char* __cdecl FUN_00c07efc(int);
struct Allocator {Allocator(){} Allocator(const Allocator&){} void deallocate(char*p,unsigned){DAT_01090a78.FUN_0086ba60(p);}};
struct StringBase {Allocator allocator;StringBase(Allocator a=Allocator()):allocator(a){}};
struct String:StringBase {
 union {char buffer[16];char* ptr;} data;
 unsigned size,capacity;
 String& FUN_0042f100(const char*,unsigned);
 String(const char* p):StringBase(){Tidy();FUN_0042f100(p,strlen(p));}
 ~String(){Tidy(true);}
 void Tidy(bool built=false){if(built && capacity>=16)allocator.deallocate(data.ptr,capacity+1);capacity=15;size=0;data.buffer[0]=0;}
};
String __cdecl FUN_00ba3850(const String&,const char*);
String __cdecl FUN_00ba3640(const String&,const String&);
inline String operator+(const String&a,const char*b){return FUN_00ba3850(a,b);}
inline String operator+(const String&a,const String&b){return FUN_00ba3640(a,b);}
struct FUN_00ba3730 {
 virtual ~FUN_00ba3730();
 const char* whatText;int doFree;
 String message;
 FUN_00ba3730(const String&);
};
struct FUN_00ba3920:FUN_00ba3730 {
 FUN_00ba3920(const String&,bool);
 virtual ~FUN_00ba3920();
};
// pdb: IdvFileError::IdvFileError | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, high
// pdb params: strDetails, bAppendSystemError
FUN_00ba3920::FUN_00ba3920(const String&message,bool systemError):FUN_00ba3730(message+" ["+(systemError?String(FUN_00c07efc(*FUN_00c02a76())):String(""))+"]"){}
}
}   // namespace f3m_00ba3920

// @f3 0x00bbd8d0 (community match, verified in this file)
#include <ios>
namespace f3m_00bbd8d0 {
namespace task1488 {
struct Stream {
 int field00,field04,state,exceptions;
 void std_ios_base_clear(int value,bool reraise);
};
// pdb: std::ios_base::clear | algs.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void Stream::std_ios_base_clear(int value,bool reraise) {
 state=value & 0x17;
 if((state & exceptions)==0) ;
 else if(reraise) throw;
 else if(state & exceptions & 4) throw std::ios_base::failure("ios_base::badbit set");
 else if(state & exceptions & 2) throw std::ios_base::failure("ios_base::failbit set");
 else throw std::ios_base::failure("ios_base::eofbit set");
}
}
}   // namespace f3m_00bbd8d0

// @f3 0x00ba9890 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e31f80;
namespace f3m_00ba9890 {
namespace task1533 {
struct Point { float x,y,z; };
struct Matrix { float m[9]; Matrix FUN_00ba9610(const Matrix&); void FUN_00ba9890(float,Point); };
void Matrix::FUN_00ba9890(float angle,Point axis) {
 Matrix rotation;
 float sine=(float)sin((float)(angle/DAT_00e31f80));
 float cosine=(float)cos((float)(angle/DAT_00e31f80));
 float t=1.0f-cosine;
 float x=axis.x,y=axis.y,z=axis.z;
 rotation.m[0]=t*x*x+cosine;
 rotation.m[1]=t*x*y+sine*z;
 rotation.m[2]=t*x*z-sine*y;
 rotation.m[3]=t*x*y-sine*z;
 rotation.m[4]=t*y*y+cosine;
 rotation.m[5]=t*y*z+sine*x;
 rotation.m[6]=t*x*z+sine*y;
 rotation.m[7]=t*y*z-sine*x;
 rotation.m[8]=t*z*z+cosine;
 *this=rotation.FUN_00ba9610(*this);
}
}
}   // namespace f3m_00ba9890

// @f3 0x00bb31b0 (community match, verified in this file)
#include <string.h>
namespace Task1729 {

struct Matrix4f
{
    float m_fComponents[4][4];
};

struct Vector3D
{
    float m_fComponents[3];

    Vector3D(float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f)
    {
        m_fComponents[2] = fZ;
        m_fComponents[1] = fY;
        m_fComponents[0] = fX;
    }
    void Set(float fX, float fY, float fZ)
    {
        m_fComponents[0] = fX;
        m_fComponents[1] = fY;
        m_fComponents[2] = fZ;
    }
    float& operator[](int nIndex)
    {
        return m_fComponents[nIndex];
    }
    __declspec(noinline) Vector3D FUN_00ba1140(const Matrix4f& m) const { Vector3D r;r.m_fComponents[0]=(m_fComponents[0]*m.m_fComponents[0][0]+m_fComponents[1]*m.m_fComponents[1][0])+m_fComponents[2]*m.m_fComponents[2][0]+m.m_fComponents[3][0];r.m_fComponents[1]=(m_fComponents[0]*m.m_fComponents[0][1]+m_fComponents[1]*m.m_fComponents[1][1])+m_fComponents[2]*m.m_fComponents[2][1]+m.m_fComponents[3][1];r.m_fComponents[2]=(m_fComponents[0]*m.m_fComponents[0][2]+m_fComponents[1]*m.m_fComponents[1][2])+m_fComponents[2]*m.m_fComponents[2][2]+m.m_fComponents[3][2];return r;}

};

inline float Interpolate(float fStart, float m_fEndValue, float fNormalizedPosition)
{
    return fStart + (m_fEndValue - fStart) * fNormalizedPosition;
}

extern Matrix4f* DAT_0117830c;

struct WindEngine
{
    static const Matrix4f& GetWindMatrix(unsigned short usIndex)
    {
        return DAT_0117830c[usIndex];
    }
};

struct SLeafLod
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usValueAt0C;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float* m_pFloatArrayAt18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    float* m_pFloatArrayAt34;
    unsigned char* m_pByteArrayAt38;
    int unk3c;
    float* m_pOrigCoordCenterCoords;
};



class CLeafGeometryWind
{
  public:
    unsigned char unk00;
    unsigned char m_bWindEnabled;
    unsigned short unk02;
    void* m_pLeafTreeRuntime;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned short m_usValueAt28;
    unsigned short unk2a;
    SLeafLod* m_pLeafLod;

    void FUN_00bb31b0(unsigned short usLod);
};

// @fnv 0x00b29190
// pdb: CLeafGeometry::ComputeWindEffect | LeafGeometry.obj | fnv360_0822_retail, caller, medium
// pdb params: nLodLevel
void CLeafGeometryWind::FUN_00bb31b0(unsigned short usLod)
{
    SLeafLod* pLod;

    if (m_pLeafTreeRuntime && usLod < m_usValueAt28 && m_bWindEnabled && m_pLeafLod && (pLod = m_pLeafLod + usLod) &&
        pLod->m_pOrigCoordCenterCoords && pLod->m_pFloatArrayAt18)
    {
        Vector3D cPos;
        Vector3D cNewPos;

        for (int i = 0; i < pLod->m_usValueAt0C; ++i)
        {
            float fWeight = pLod->m_pFloatArrayAt34[i];
            const float* pOrigCoord = pLod->m_pOrigCoordCenterCoords + i * 3;
            cPos.Set(pOrigCoord[0], pOrigCoord[1], pOrigCoord[2]);
            unsigned char ucWindMatrix = pLod->m_pByteArrayAt38[i];
            cPos = cPos.FUN_00ba1140(WindEngine::GetWindMatrix(ucWindMatrix));
            cNewPos.Set(Interpolate(pOrigCoord[0], cPos[0], fWeight), Interpolate(pOrigCoord[1], cPos[1], fWeight),
                        Interpolate(pOrigCoord[2], cPos[2], fWeight));
            memcpy(pLod->m_pFloatArrayAt18 + i * 3, &cNewPos, 12);
        }
    }
}

}

// @f3 0x00ba3c00 (community match, verified in this file)
namespace f3m_00ba3c00 {
namespace task1386 {
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
void __cdecl FUN_00c01e8b();
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc(0);
    return (char*)::operator new(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::operator delete(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    static const unsigned int npos;
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal()
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = npos)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00c01e8b();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            _Tidy(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
struct IdvFilename : public String
{
    IdvFilename(String strName) : String(strName)
    {}
    IdvFilename FUN_00ba3c00() const;
};

// @fnv 0x00b09f90
// pdb: CIdvFilename::NoPath | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
IdvFilename IdvFilename::FUN_00ba3c00() const
{
    char szBuffer[1024];
    const char* source = c_str();
    unsigned int copyOffset = reinterpret_cast<unsigned int>(szBuffer) - reinterpret_cast<unsigned int>(source);
    char copied;
    do {
        copied = *source;
        *reinterpret_cast<char*>(reinterpret_cast<unsigned int>(source) + copyOffset) = copied;
        ++source;
    } while (copied != 0);
    int nLength = length();
    for (int i = nLength - 1; i >= 0; --i)
    {
        if ((*this)[i] == '/' || (*this)[i] == '\\')
        {
            int j = i + 1;
            int k = 0;
            for (; j < nLength; ++j, ++k)
                szBuffer[k] = (*this)[j];
            szBuffer[k] = 0;
            break;
        }
    }
    return String(szBuffer);
}
}  // namespace task1386
}   // namespace f3m_00ba3c00

// @f3 0x00bb5fe0 (community match, verified in this file)
namespace f3m_00bb5fe0 {
namespace Slot1VectorBB {
struct Element {int unk00,unk04,unk08,unk0C,unk10,unk14;};
Element* __cdecl FUN_00bb5220(Element*,Element*,Element*);
void __cdecl FUN_00401010(void*);
struct Vector {
    int allocator;
    Element* begin;
    Element* end;
    Element* limit;
    __forceinline unsigned Size()const{if(!begin)return 0;return (unsigned)(end-begin);}
    __forceinline unsigned Capacity()const{if(!begin)return 0;return (unsigned)(limit-begin);}
    void FUN_00bb5600();
    void FUN_00bb54f0(Element*,Element*);
    unsigned FUN_00bb4670()const;
    Element* FUN_00bab3c0(Element*,Element*,Element*);
    bool FUN_00bb5780(unsigned);
    Vector& FUN_00bb5fe0(const Vector&);
};
// pdb: std::vector<CVec,std::allocator<CVec> >::operator= | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Right
Vector& Vector::FUN_00bb5fe0(const Vector& other) {
    if(this!=&other) {
        Element* sourceBegin=other.begin;
        unsigned count=sourceBegin?(unsigned)(other.end-sourceBegin):0;
        if(count==0) FUN_00bb5600();
        else if(count<=Size()) {
            Element* copied=FUN_00bb5220(sourceBegin,other.end,begin);
            FUN_00bb54f0(copied,end);
            end=begin+other.Size();
        } else if(count<=Capacity()) {
            Element* destBegin=begin;
            Element* split=sourceBegin+FUN_00bb4670();
            FUN_00bb5220(sourceBegin,split,destBegin);
            end=FUN_00bab3c0(split,other.end,end);
        } else {
            if(begin) {FUN_00bb54f0(begin,end);FUN_00401010(begin);}
            if(FUN_00bb5780(other.FUN_00bb4670())) end=FUN_00bab3c0(other.begin,other.end,begin);
        }
    }
    return *this;
}
}
}   // namespace f3m_00bb5fe0

// @f3 0x00bb6720 (community match, verified in this file)
namespace f3m_00bb6720 {
namespace task1840 {

struct Vector {unsigned allocator;void* begin;void* end;void* capacity;~Vector(){if(begin)f3m_00bbad10::FUN_00401010(begin);}Vector& FUN_00bb5d10(const Vector&);Vector& operator=(const Vector& other){return FUN_00bb5d10(other);}};
struct Entry {Vector vector;float a,b;bool flag;float c,d,key;int x,y;};
struct Less {bool operator()(const Entry& a,const Entry& b)const{return a.key>b.key;}};
void FUN_00bb6720(Entry* first,int hole,int top,Entry value,Less pred){
 for(int parent=(hole-1)/2;top<hole && pred(first[parent],value);parent=(hole-1)/2){first[hole]=first[parent];hole=parent;}
 first[hole]=value;
}
}
}   // namespace f3m_00bb6720

// @f3 0x00baf000 (community match, verified in this file)
#include <vector>
namespace f3m_00baf000 {

namespace Transform450
{
struct Point
{
    float x, y, z;
    Point() {}
    Point(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Column
{
    float x, y, z, w;
};

struct Matrix
{
    Column x, y, z, translation;

    Point Apply(const Point& point) const
    {
        return Point(x.x * point.x + y.x * point.y + z.x * point.z + translation.x,
                     x.y * point.x + y.y * point.y + z.y * point.z + translation.y,
                     x.z * point.x + y.z * point.y + z.z * point.z + translation.z);
    }
};

struct Geometry
{
    unsigned int unk00, unk04;
    bool transformSecondary;
    unsigned int unk0cTo64[23];
    std::vector<float> positions;
    std::vector<float> secondary;
    void FUN_00baf000(const Matrix* matrix);
};

void Geometry::FUN_00baf000(const Matrix* matrix)
{
    unsigned short count = (unsigned short)(positions.size() / 3);
    Point input;
    for (int i = 0; i < count; ++i)
    {
        Point& dst = *reinterpret_cast<Point*>(&positions[0] + i * 3);
        input.x = dst.x;
        input.y = dst.y;
        input.z = dst.z;
        Point result = matrix->Apply(input);
        dst = result;
        if (transformSecondary && !secondary.empty())
        {
            Point& other = *reinterpret_cast<Point*>(&secondary[0] + i * 3);
            input.x = other.x;
            input.y = other.y;
            input.z = other.z;
            Point resultOther = matrix->Apply(input);
            other = resultOther;
        }
    }
}
}


}   // namespace f3m_00baf000

// @f3 0x00bbeb20 (community match, verified in this file)
namespace f3m_00bbeb20 {
namespace Tree2081 {
struct Camera {virtual void v0();unsigned int unk04,unk08,unk0C;Camera();~Camera();};
struct Control {unsigned char flag;Control();~Control();};
struct BranchRecord {unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30;BranchRecord();~BranchRecord();};
struct Vector {unsigned int proxy;void** first;void** last;void** end;Vector():first(0),last(0),end(0){}~Vector();};
struct Config {
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
    Config();~Config();
};
struct Dimensions {
    float width,height,unk08,lower,upper,depth,value;
    Dimensions();
    
};
struct Seed {unsigned int value;Seed(unsigned int v=0):value(v){}Seed& operator=(unsigned int v){value=v;return *this;}};
struct Tree:Camera {
    float scaleX,scaleY,threshold,phase;
    Control control;unsigned char enabled,unk22,unk23;
    BranchRecord branch;
    unsigned int unk58;Seed seed;
    Vector first;
    unsigned int mode;
    Vector second;
    Config config;
    unsigned int unkD4;unsigned char active,unkD9,unkDA,unkDB;
    float ratio,weight,frequency,offset,range;
    unsigned int kind;
    Dimensions dimensions;
    virtual void v0();Tree(unsigned int);
    void SetBounds(float a,float b,float c){dimensions.lower=a;dimensions.upper=b;dimensions.depth=c;}
    void UpdateBounds(){volatile float h=dimensions.height*2.0f;float w=static_cast<float>(dimensions.width*45.0);dimensions.lower=-w;dimensions.upper=w;dimensions.depth=h;}
};
// pdb: CTreeEngine::CTreeEngine | TreeEngine.obj | fnv360_0822_retail, uvref, medium
// pdb params: pBranchGeometry
Tree::Tree(unsigned int source):scaleX(1.0f),scaleY(1.0f),threshold(-1.0f),phase(0.0f),
    control(),enabled(1),branch(),unk58(0),seed(0),first(),mode(6),second(),config(),
    unkD4(0),active(0),ratio(0.5f),weight(1.0f),frequency(0.3f),offset(0.0f),range(0.05f),kind(1),dimensions(){
    dimensions.value=0.25f;seed=source;UpdateBounds();
}
}
}   // namespace f3m_00bbeb20

// @f3 0x00bba8a0 (community match, verified in this file)
namespace f3m_00bba8a0 {
namespace SortBBA {
struct Element {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;};
struct Compare {};
struct Pair {Element* first;Element* second;Pair(Element* a,Element* b):first(a),second(b) {}};
__declspec(noalias) Pair __cdecl FUN_00bb95b0(Element*,Element*,Compare);
void __cdecl FUN_00bb9830(Element*,Element*,Compare);
void __cdecl FUN_00bb9140(Element*,Element*,Compare,int,int);
void __cdecl FUN_00bb9ba0(Element*,Element*,Compare);
void __cdecl FUN_00bba8a0(Element* first,Element* last,int ideal,Compare compare) {
 int size=last-first;
 while(size>32 && ideal>0) {
  Pair middle=FUN_00bb95b0(first,last,compare);
  ideal/=2;ideal+=ideal/2;
  if(middle.first-first < last-middle.second) {
   FUN_00bba8a0(first,middle.first,ideal,compare);
   first=middle.second;
  } else {
   FUN_00bba8a0(middle.second,last,ideal,compare);
   last=middle.first;
  }
  size=last-first;
 }
 if(size>32) {
  if(last-first>1) FUN_00bb9140(first,last,compare,0,0);
  FUN_00bb9ba0(first,last,compare);
 } else if(size>1) FUN_00bb9830(first,last,compare);
}
}
}   // namespace f3m_00bba8a0

// @f3 0x00bb0a70 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0a70 {
namespace f3m_00bb0a70 {
bool __cdecl FUN_00ba1920();
struct Geom0a70
{
    unsigned char flag00;
    unsigned char unk01, unk02, unk03;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    unsigned short unk20;
    unsigned short index22;
    int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4;
    std::vector<float> uvs;
    std::vector<float> uv2;
    std::vector<unsigned char> sel;
    void FUN_00bb0a70(const float* uv, short selection);
};
// pdb: CIndexedGeometry::AddVertexTexCoord0 | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: pTexCoord, sIndex
void Geom0a70::FUN_00bb0a70(const float* uv, short selection)
{
    if (index22 == uvs.size() / 2)
    {
        uvs.resize(uvs.size() + 2, 0.0f);
        if (selection > -1 && flag00)
        {
            sel.resize(sel.size() + 1, 0);
            uv2.resize(uv2.size() + 2, 0.0f);
        }
    }
    if (selection > -1 && flag00)
    {
        sel[index22] = (unsigned char)selection;
        uv2[index22 * 2] = uv[0];
        uv2[index22 * 2 + 1] = uv[1];
    }
    uvs[index22 * 2] = uv[0];
    uvs[index22 * 2 + 1] = FUN_00ba1920() ? -uv[1] : uv[1];
}
}
}   // namespace f3m_00bb0a70

// @f3 0x00ba2a80 (community match, verified in this file)
#include <math.h>
extern int DAT_01068af4, DAT_01068b04;
extern const double DAT_00e31f80, DAT_00de7c38;
namespace f3m_00ba14c0 { void __cdecl FUN_00ba14c0(float,unsigned short,float,float,float,float,float*,float*,short*,short*); }
namespace Task1945 {
inline float HalfPass1945(unsigned short n) { return (float)(0.5 / n); }
struct V0c
{
    float x, y, z;
    V0c()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    V0c(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    V0c operator-() const
    {
        return V0c(-x, -y, -z);
    }
};
inline float Angle1945(V0c* v) { float angle = (float)atan2((double)v->y,(double)v->x); return (float)(angle * DAT_00e31f80); }
inline float Lerp0c(float t, float a, float b)
{
    return a + (b - a) * t;
}
inline float Lerp1c(float t, float fBase)
{
    return Lerp0c(t, fBase, 255.0f);
}
struct L0c
{
    unsigned char reservedByte1_0; unsigned char reservedByte1_1; unsigned char reservedByte1_2; unsigned char reservedByte1_3; unsigned char reservedByte1_4; unsigned char reservedByte1_5; unsigned char reservedByte1_6; unsigned char reservedByte1_7; unsigned char reservedByte1_8; unsigned char reservedByte1_9; unsigned char reservedByte1_10; unsigned char reservedByte1_11;
    int* data;
};
struct O0c
{
    unsigned char reservedByte2_0; unsigned char reservedByte2_1; unsigned char reservedByte2_2; unsigned char reservedByte2_3; unsigned char reservedByte2_4; unsigned char reservedByte2_5; unsigned char reservedByte2_6; unsigned char reservedByte2_7; unsigned char reservedByte2_8; unsigned char reservedByte2_9; unsigned char reservedByte2_10; unsigned char reservedByte2_11; unsigned char reservedByte2_12; unsigned char reservedByte2_13; unsigned char reservedByte2_14; unsigned char reservedByte2_15; unsigned char reservedByte2_16; unsigned char reservedByte2_17; unsigned char reservedByte2_18; unsigned char reservedByte2_19; unsigned char reservedByte2_20; unsigned char reservedByte2_21; unsigned char reservedByte2_22; unsigned char reservedByte2_23; unsigned char reservedByte2_24; unsigned char reservedByte2_25; unsigned char reservedByte2_26; unsigned char reservedByte2_27; unsigned char reservedByte2_28; unsigned char reservedByte2_29; unsigned char reservedByte2_30; unsigned char reservedByte2_31; unsigned char reservedByte2_32; unsigned char reservedByte2_33; unsigned char reservedByte2_34; unsigned char reservedByte2_35; unsigned char reservedByte2_36; unsigned char reservedByte2_37; unsigned char reservedByte2_38; unsigned char reservedByte2_39; unsigned char reservedByte2_40; unsigned char reservedByte2_41; unsigned char reservedByte2_42; unsigned char reservedByte2_43; unsigned char reservedByte2_44; unsigned char reservedByte2_45; unsigned char reservedByte2_46; unsigned char reservedByte2_47; unsigned char reservedByte2_48; unsigned char reservedByte2_49; unsigned char reservedByte2_50; unsigned char reservedByte2_51; unsigned char reservedByte2_52; unsigned char reservedByte2_53; unsigned char reservedByte2_54; unsigned char reservedByte2_55; unsigned char reservedByte2_56; unsigned char reservedByte2_57; unsigned char reservedByte2_58; unsigned char reservedByte2_59; unsigned char reservedByte2_60; unsigned char reservedByte2_61; unsigned char reservedByte2_62; unsigned char reservedByte2_63; unsigned char reservedByte2_64; unsigned char reservedByte2_65; unsigned char reservedByte2_66; unsigned char reservedByte2_67; unsigned char reservedByte2_68; unsigned char reservedByte2_69; unsigned char reservedByte2_70; unsigned char reservedByte2_71; unsigned char reservedByte2_72; unsigned char reservedByte2_73; unsigned char reservedByte2_74; unsigned char reservedByte2_75; unsigned char reservedByte2_76; unsigned char reservedByte2_77; unsigned char reservedByte2_78; unsigned char reservedByte2_79; unsigned char reservedByte2_80; unsigned char reservedByte2_81; unsigned char reservedByte2_82; unsigned char reservedByte2_83; unsigned char reservedByte2_84; unsigned char reservedByte2_85; unsigned char reservedByte2_86; unsigned char reservedByte2_87; unsigned char reservedByte2_88; unsigned char reservedByte2_89; unsigned char reservedByte2_90; unsigned char reservedByte2_91; unsigned char reservedByte2_92; unsigned char reservedByte2_93; unsigned char reservedByte2_94; unsigned char reservedByte2_95; unsigned char reservedByte2_96; unsigned char reservedByte2_97; unsigned char reservedByte2_98; unsigned char reservedByte2_99; unsigned char reservedByte2_100; unsigned char reservedByte2_101; unsigned char reservedByte2_102; unsigned char reservedByte2_103; unsigned char reservedByte2_104; unsigned char reservedByte2_105; unsigned char reservedByte2_106; unsigned char reservedByte2_107; unsigned char reservedByte2_108; unsigned char reservedByte2_109; unsigned char reservedByte2_110; unsigned char reservedByte2_111; unsigned char reservedByte2_112; unsigned char reservedByte2_113; unsigned char reservedByte2_114; unsigned char reservedByte2_115; unsigned char reservedByte2_116; unsigned char reservedByte2_117; unsigned char reservedByte2_118; unsigned char reservedByte2_119; unsigned char reservedByte2_120; unsigned char reservedByte2_121; unsigned char reservedByte2_122; unsigned char reservedByte2_123; unsigned char reservedByte2_124; unsigned char reservedByte2_125; unsigned char reservedByte2_126; unsigned char reservedByte2_127; unsigned char reservedByte2_128; unsigned char reservedByte2_129; unsigned char reservedByte2_130; unsigned char reservedByte2_131; unsigned char reservedByte2_132; unsigned char reservedByte2_133; unsigned char reservedByte2_134; unsigned char reservedByte2_135; unsigned char reservedByte2_136; unsigned char reservedByte2_137; unsigned char reservedByte2_138; unsigned char reservedByte2_139; unsigned char reservedByte2_140; unsigned char reservedByte2_141; unsigned char reservedByte2_142; unsigned char reservedByte2_143; unsigned char reservedByte2_144; unsigned char reservedByte2_145; unsigned char reservedByte2_146; unsigned char reservedByte2_147; unsigned char reservedByte2_148; unsigned char reservedByte2_149; unsigned char reservedByte2_150; unsigned char reservedByte2_151; unsigned char reservedByte2_152; unsigned char reservedByte2_153; unsigned char reservedByte2_154; unsigned char reservedByte2_155; unsigned char reservedByte2_156; unsigned char reservedByte2_157; unsigned char reservedByte2_158; unsigned char reservedByte2_159; unsigned char reservedByte2_160; unsigned char reservedByte2_161; unsigned char reservedByte2_162; unsigned char reservedByte2_163; unsigned char reservedByte2_164; unsigned char reservedByte2_165; unsigned char reservedByte2_166; unsigned char reservedByte2_167; unsigned char reservedByte2_168; unsigned char reservedByte2_169; unsigned char reservedByte2_170; unsigned char reservedByte2_171; unsigned char reservedByte2_172; unsigned char reservedByte2_173; unsigned char reservedByte2_174; unsigned char reservedByte2_175; unsigned char reservedByte2_176; unsigned char reservedByte2_177; unsigned char reservedByte2_178; unsigned char reservedByte2_179; unsigned char reservedByte2_180; unsigned char reservedByte2_181; unsigned char reservedByte2_182; unsigned char reservedByte2_183; unsigned char reservedByte2_184; unsigned char reservedByte2_185; unsigned char reservedByte2_186; unsigned char reservedByte2_187; unsigned char reservedByte2_188; unsigned char reservedByte2_189; unsigned char reservedByte2_190; unsigned char reservedByte2_191; unsigned char reservedByte2_192; unsigned char reservedByte2_193; unsigned char reservedByte2_194; unsigned char reservedByte2_195; unsigned char reservedByte2_196; unsigned char reservedByte2_197; unsigned char reservedByte2_198; unsigned char reservedByte2_199; unsigned char reservedByte2_200; unsigned char reservedByte2_201; unsigned char reservedByte2_202; unsigned char reservedByte2_203; unsigned char reservedByte2_204; unsigned char reservedByte2_205; unsigned char reservedByte2_206; unsigned char reservedByte2_207; unsigned char reservedByte2_208; unsigned char reservedByte2_209; unsigned char reservedByte2_210; unsigned char reservedByte2_211; unsigned char reservedByte2_212; unsigned char reservedByte2_213; unsigned char reservedByte2_214; unsigned char reservedByte2_215; unsigned char reservedByte2_216; unsigned char reservedByte2_217; unsigned char reservedByte2_218; unsigned char reservedByte2_219; unsigned char reservedByte2_220; unsigned char reservedByte2_221; unsigned char reservedByte2_222; unsigned char reservedByte2_223; unsigned char reservedByte2_224; unsigned char reservedByte2_225; unsigned char reservedByte2_226; unsigned char reservedByte2_227; unsigned char reservedByte2_228; unsigned char reservedByte2_229; unsigned char reservedByte2_230; unsigned char reservedByte2_231; unsigned char reservedByte2_232; unsigned char reservedByte2_233; unsigned char reservedByte2_234; unsigned char reservedByte2_235; unsigned char reservedByte2_236; unsigned char reservedByte2_237; unsigned char reservedByte2_238; unsigned char reservedByte2_239;
    unsigned char bActive;
    unsigned char reservedByte3_0; unsigned char reservedByte3_1; unsigned char reservedByte3_2;
    int* pData;
    int iValue;
    float fWeight;
    short m_sIndex;
    unsigned char reservedByte4_0; unsigned char reservedByte4_1;
    unsigned char bBlend;
    unsigned char reservedByte5_0; unsigned char reservedByte5_1; unsigned char reservedByte5_2;
    int* pData2;
    int iValue2;
    float fWeight2;
    short sIndex2;
};
struct T0c
{
    unsigned char reservedByte6_0; unsigned char reservedByte6_1; unsigned char reservedByte6_2; unsigned char reservedByte6_3; unsigned char reservedByte6_4; unsigned char reservedByte6_5; unsigned char reservedByte6_6; unsigned char reservedByte6_7; unsigned char reservedByte6_8; unsigned char reservedByte6_9; unsigned char reservedByte6_10; unsigned char reservedByte6_11; unsigned char reservedByte6_12; unsigned char reservedByte6_13; unsigned char reservedByte6_14; unsigned char reservedByte6_15; unsigned char reservedByte6_16; unsigned char reservedByte6_17; unsigned char reservedByte6_18; unsigned char reservedByte6_19; unsigned char reservedByte6_20; unsigned char reservedByte6_21; unsigned char reservedByte6_22; unsigned char reservedByte6_23; unsigned char reservedByte6_24; unsigned char reservedByte6_25; unsigned char reservedByte6_26; unsigned char reservedByte6_27; unsigned char reservedByte6_28; unsigned char reservedByte6_29; unsigned char reservedByte6_30; unsigned char reservedByte6_31;
    float f20;
    int i24;
    float f28;
    unsigned char reservedByte7_0; unsigned char reservedByte7_1; unsigned char reservedByte7_2; unsigned char reservedByte7_3; unsigned char reservedByte7_4; unsigned char reservedByte7_5; unsigned char reservedByte7_6; unsigned char reservedByte7_7; unsigned char reservedByte7_8; unsigned char reservedByte7_9; unsigned char reservedByte7_10; unsigned char reservedByte7_11; unsigned char reservedByte7_12; unsigned char reservedByte7_13; unsigned char reservedByte7_14; unsigned char reservedByte7_15; unsigned char reservedByte7_16; unsigned char reservedByte7_17; unsigned char reservedByte7_18; unsigned char reservedByte7_19; unsigned char reservedByte7_20; unsigned char reservedByte7_21; unsigned char reservedByte7_22; unsigned char reservedByte7_23;
    unsigned char ucMin;
    unsigned char reservedByte8_0; unsigned char reservedByte8_1; unsigned char reservedByte8_2; unsigned char reservedByte8_3; unsigned char reservedByte8_4; unsigned char reservedByte8_5; unsigned char reservedByte8_6;
    L0c* pList;
    unsigned char reservedByte9_0; unsigned char reservedByte9_1; unsigned char reservedByte9_2; unsigned char reservedByte9_3;
    unsigned short m_usPassCountLocal;
    void FUN_00ba26e0(O0c* out);
    void FUN_00ba2a80(O0c* pOut, unsigned int uiFlags);
};
// @fnv 0x00b0c050
// pdb: CSpeedTreeRT::Get360BillboardGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: sGeometry, ulBitVector
void T0c::FUN_00ba2a80(O0c* pOut, unsigned int uiFlags)
{
    FUN_00ba26e0(pOut);
    if (pOut->bActive && m_usPassCountLocal)
    {
        float fScale2 = (pOut->fWeight - ucMin) / (255.0 - ucMin);
        V0c vA3;
        V0c vB9;
        vA3 = *(V0c*)&DAT_01068af4;
        vB9 = *(V0c*)&DAT_01068b04;
        vB9 = -vB9;
        float fAngleTmp = Angle1945(&vB9);
        if (fAngleTmp < 0.0)
            fAngleTmp += DAT_00de7c38;
        float fW3 = -1.0f;
        float fWTmp = -1.0f;
        short sA = -1;
        short s3 = -1;
        unsigned short usN = m_usPassCountLocal;
        float fHalf3 = HalfPass1945(usN);
        float fTVal = Lerp0c(fAngleTmp / DAT_00de7c38, fHalf3, 1.0f - fHalf3);
        f3m_00ba14c0::FUN_00ba14c0(fTVal, usN, HalfPass1945(usN), f28, f20, ucMin, &fW3, &fWTmp, &sA, &s3);
        sA = m_usPassCountLocal - 1 - sA;
        s3 = m_usPassCountLocal - 1 - s3;
        while (sA >= usN)
            sA = sA - usN;
        while (s3 >= usN)
            s3 = s3 - usN;
        if (uiFlags & 0x20)
        {
            pOut->bActive = 1;
            if (fW3 < fWTmp)
            {
                pOut->pData = pList->data + sA * 8;
                pOut->fWeight = Lerp1c(fScale2, ucMin);
                pOut->bBlend = 0;
            }
            else
            {
                pOut->pData = pList->data + s3 * 8;
                pOut->fWeight = Lerp1c(fScale2, ucMin);
                pOut->bBlend = 0;
            }
        }
        else
        {
            if (pList)
                pOut->pData = pList->data + sA * 8;
            else
                pOut->pData = 0;
            pOut->fWeight = Lerp0c(fScale2, fW3, 255.0f);
            pOut->m_sIndex = sA;
            pOut->iValue2 = pOut->iValue;
            if (pList)
                pOut->pData2 = pList->data + s3 * 8;
            else
                pOut->pData2 = 0;
            pOut->sIndex2 = s3;
            pOut->bBlend = 1;
            pOut->fWeight2 = Lerp0c(fScale2, fWTmp, 255.0f);
        }
    }
}
}

// @f3 0x00ba2070 (community match, verified in this file)
#include <math.h>
namespace f3m_00ba14c0 {void __cdecl FUN_00ba14c0(float,unsigned short,float,float,float,float,float*,float*,short*,short*);}
namespace Task1957 {
extern const double DAT_00e31f80,DAT_00ea7078;
extern int DAT_01068af4,DAT_01068b04;
extern unsigned char DAT_01178274;
struct CSpeedTreeRT { void* first; unsigned short FUN_00b08710() {return *(unsigned short*)((char*)first+0xc0);} };
struct FUN_00ba1f80_shell {unsigned short FUN_00ba1f80(float);};
struct Eng28 {void FUN_00bb3010(bool*,unsigned short,float,float,float);};
struct OutAd00
{
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
    float m38;
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
    bool m78;
    char unk79;
    char unk7a;
    char unk7b;
    float m7c;
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
    bool mb4;
    char unkb5;
    char unkb6;
    char unkb7;
    float mb8;
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
    bool mf0;
    char unkf1;
    char unkf2;
    char unkf3;
    int unkf4;
    int unkf8;
    float mfc;
};
struct Vec3f
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float f[3];
    };
    float& operator[](int i)
    {
        return f[i];
    }
};


struct SelfAd00
{
    int m00;
    int m04;
    Eng28* m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    unsigned char m44;
    void __thiscall CSpeedTreeRT_GetBSGeometryLODData(OutAd00* out, float param);
};
// @fnv 0x00b0ad00
// pdb: CSpeedTreeRT::GetBSGeometryLODData | SpeedTreeRT.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void __thiscall SelfAd00::CSpeedTreeRT_GetBSGeometryLODData(OutAd00* out, float param)
{
    float asinRad;
    float t2;
    float angRad4;
    float t7;
    float t9;
    unsigned short tfbk;
    float fPf1;
    float pf9;
    unsigned short savedQ;
    float negDeg8;
    short sZ;
    Vec3f vc7;
    short _s1;
    unsigned short nW;
    Vec3f vaTmp;
    Vec3f vbC;
    float deg4;
    savedQ = ((CSpeedTreeRT*)this)->FUN_00b08710();
    nW = savedQ + (DAT_01178274 != 0);
    fPf1 = -1.0f;
    pf9 = -1.0f;
    _s1 = -1;
    sZ = -1;
    f3m_00ba14c0::FUN_00ba14c0(param, nW, m1c, m28, m20, (float)m44, &fPf1, &pf9, &_s1, &sZ);
    if (DAT_01178274)
    {
        out->mfc = -1.0f;
        if (_s1 == nW - 1)
        {
            out->mfc = fPf1;
        }
        else if (sZ == nW - 1)
        {
            out->mfc = pf9;
        }
        out->mf0 = (out->mfc != -1.0);
    }
    else
    {
        out->mf0 = 0;
    }
    if (param < 0.0)
    {
    }
    else
    {
        if (DAT_01178274)
        {
            if (_s1 == nW - 2)
            {
                out->m38 = fPf1;
            }
            else if (_s1 == nW - 1)
            {
                out->m38 = 255.0f;
            }
            else
            {
                out->m38 = (float)m44;
            }
        }
        else
        {
            out->m38 = (float)m44;
        }
        vaTmp.z = 0.0f;
        vaTmp.y = 0.0f;
        vaTmp.x = 0.0f;
        vbC.z = 0.0f;
        vbC.y = 0.0f;
        vbC.x = 0.0f;
        vc7.z = 0.0f;
        vc7.y = 0.0f;
        vc7.x = 0.0f;
        vaTmp = *(Vec3f*)&DAT_01068af4;
        vbC = *(Vec3f*)&DAT_01068b04;
        vc7.x = vbC.x;
        vc7.y = vbC.y;
        vc7.z = vbC.z;
        t7 = vc7[1];
        t9 = vc7[0];
        angRad4 = (float)(double)(float)atan2(t7, t9);
        deg4 = angRad4 * DAT_00e31f80;
        t2 = vc7[2];
        asinRad = (float)(double)(float)asin(t2);
        negDeg8 = (float)(asinRad * DAT_00ea7078);
        if (m18 == 1)
        {
            m08->FUN_00bb3010(&out->m78, 0, deg4, negDeg8, m24);
            out->m78 = (_s1 != -1 && _s1 < savedQ);
            if (out->m78)
            {
                m08->FUN_00bb3010(&out->m78, _s1, deg4, negDeg8, m24);
                out->m7c = fPf1;
            }
            out->mb4 = (sZ != -1 && sZ < savedQ);
            if (out->mb4)
            {
                m08->FUN_00bb3010(&out->mb4, sZ, deg4, negDeg8, m24);
                out->mb8 = pf9;
            }
        }
        else if (m18 == 3)
        {
            m08->FUN_00bb3010(&out->m78, 0, deg4, negDeg8, m24);
            out->m78 = 1;
            out->m7c = (float)m44;
            out->mb4 = 0;
        }
        else
        {
            tfbk = ((FUN_00ba1f80_shell*)this)->FUN_00ba1f80(-1.0f);
            if (tfbk < ((CSpeedTreeRT*)this)->FUN_00b08710())
            {
                m08->FUN_00bb3010(&out->m78, tfbk, deg4, negDeg8, m24);
                out->m78 = 1;
                out->m7c = (float)m44;
            }
            out->mb4 = 0;
        }
    }
}

}

// @f3 0x00ba23d0 (community match, verified in this file)
#include <math.h>
namespace tree1967 {
struct Vector3D {float x,y,z;};
extern Vector3D DAT_01068af4,DAT_01068b04;
extern unsigned char DAT_01178274;
inline int IndexZero(){return 0;} inline int IndexOne(){return 1;} inline int IndexTwo(){return 2;}
struct TreeData {unsigned unk00;unsigned unk04;unsigned unk08;unsigned unk0c;unsigned unk10;float lod;unsigned unk18;unsigned unk1c;unsigned unk20;unsigned unk24;unsigned unk28;unsigned unk2c;unsigned unk30;unsigned unk34;unsigned unk38;unsigned unk3c;unsigned unk40;unsigned unk44;unsigned unk48;unsigned unk4c;unsigned unk50;unsigned unk54;unsigned unk58;unsigned unk5c;unsigned unk60;unsigned unk64;unsigned unk68;unsigned unk6c;unsigned unk70;unsigned unk74;unsigned unk78;unsigned unk7c;unsigned unk80;unsigned unk84;unsigned unk88;unsigned unk8c;unsigned unk90;unsigned unk94;unsigned unk98;unsigned unk9c;unsigned unka0;unsigned unka4;unsigned unka8;unsigned unkac;unsigned unkb0;unsigned unkb4;unsigned unkb8;unsigned unkbc;unsigned count;};
struct LodState {unsigned unk00,unk04,unk08,unk0c;float lod;};
struct TreeGeometry
{
    bool active;
    float alpha;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};
struct TreeOutput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74;
    TreeGeometry first;
    TreeGeometry second;
};
struct TreeEngine
{
    void FUN_00bb3390(TreeGeometry*, unsigned short, float, float, float);
    void FUN_00bb3010(TreeGeometry*, unsigned short, float, float, float);
};
void __cdecl FUN_00ba14c0(float, unsigned short, float, float, float, float, float*, float*, short*, short*);
struct TreeRuntime
{
    TreeData* data;
    int unk04;
    TreeEngine* geometry;
    int unk0c, unk10, unk14;
    int lodMode;
    float lodNear, lodFar, scale, lodTransition;
    int unk2c, unk30; LodState* state; int unk38, unk3c, unk40;
    unsigned char alpha;
    unsigned short FUN_00ba1f80(float);
    unsigned short FUN_00b08710(){unsigned v=data->count;return *reinterpret_cast<unsigned short*>(&v);}
    float Lod(){return state?state->lod:data->lod;}
    void FUN_00ba23d0(TreeOutput*, short);
};

// @fnv 0x00b0bc00
// pdb: CSpeedTreeRT::GetLeafGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: sGeometry, sOverrideLeafLodValue
void TreeRuntime::FUN_00ba23d0(TreeOutput* output, short forcedLod)
{
    float resultVal;
    float pointX;
    float angle7;
    float posTmp;
    float result7;
    unsigned short indexVal;
    unsigned short index_;
    unsigned short count4;
    float angle5;
    Vector3D pos1;
    unsigned short count2;
    Vector3D position;
    Vector3D pos2;
    float angleVal;

    count4 = FUN_00b08710();
    count2 = count4 + (DAT_01178274 != 0);
    position.z = 0.0f;
    position.y = 0.0f;
    position.x = 0.0f;
    pos2.z = 0.0f;
    pos2.y = 0.0f;
    pos2.x = 0.0f;
    pos1.z = 0.0f;
    pos1.y = 0.0f;
    pos1.x = 0.0f;
    position = *reinterpret_cast<const Vector3D*>(&DAT_01068af4);
    pos2 = *reinterpret_cast<const Vector3D*>(&DAT_01068b04);
    pos1.x = pos2.x;
    pos1.y = pos2.y;
    pos1.z = pos2.z;
    posTmp = reinterpret_cast<float*>(&pos1)[IndexOne()];
    result7 = reinterpret_cast<float*>(&pos1)[IndexZero()];
    angle7 = (double)(float)atan2((double)posTmp, (double)result7);
    angleVal = angle7 * 57.295780181884766;
    pointX = reinterpret_cast<float*>(&pos1)[IndexTwo()];
    resultVal = (double)(float)asin(pointX);
    angle5 = (float)(resultVal * -57.295780181884766);
    index_ = 0;
    while (index_ < FUN_00b08710())
    {
        geometry->FUN_00bb3390(&output->first, index_, angleVal, angle5, scale);
        ++index_;
    }
    if (forcedLod > -1)
    {
        geometry->FUN_00bb3010(&output->first, (unsigned short)forcedLod, angleVal, angle5, scale);
        output->first.active = true;
        output->first.alpha = (float)alpha;
        output->second.active = false;
    }
    else if (lodMode == 1)
    {
    float aAngle;
    float angle3;
    short indexX;
    short index6;

        aAngle = -1.0f;
        angle3 = -1.0f;
        index6 = -1;
        indexX = -1;
        FUN_00ba14c0(Lod(), count2, lodNear, lodTransition,
                     lodFar, (float)alpha, &aAngle, &angle3, &index6, &indexX);
        output->first.active = index6 != -1 && index6 < count4;
        if (output->first.active)
        {
            geometry->FUN_00bb3010(&output->first, (unsigned short)index6, angleVal, angle5, scale);
            output->first.alpha = aAngle;
        }
        output->second.active = indexX != -1 && indexX < count4;
        if (output->second.active)
        {
            geometry->FUN_00bb3010(&output->second, (unsigned short)indexX, angleVal, angle5, scale);
            output->second.alpha = angle3;
        }
    }
    else if (lodMode == 3)
    {
        geometry->FUN_00bb3010(&output->first, 0, angleVal, angle5, scale);
        output->first.active = true;
        output->first.alpha = (float)alpha;
        output->second.active = false;
    }
    else
    {
        indexVal = FUN_00ba1f80(-1.0f);
        if (indexVal < FUN_00b08710())
        {
            geometry->FUN_00bb3010(&output->first, indexVal, angleVal, angle5, scale);
            output->first.active = true;
            output->first.alpha = (float)alpha;
        }
        output->second.active = false;
    }
}

}

// @f3 0x00ba89c0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba89c0 {
namespace worker06_2038 {
struct Heap {void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct V3 {float x,y,z;};struct Shape {int iType;V3 a,b;};
struct CollisionList : std::vector<Shape> {
 static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}
 static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}
 void FUN_00ba81b0(const Shape&);
};
struct Parser {int FUN_00ba92d0();float FUN_00ba92a0();bool FUN_00ba1ab0();};
struct Tree {
unsigned unk00;
unsigned unk04;
unsigned unk08;
unsigned unk0c;
unsigned unk10;
unsigned unk14;
unsigned unk18;
unsigned unk1c;
unsigned unk20;
unsigned unk24;
unsigned unk28;
unsigned unk2c;
unsigned unk30;
unsigned unk34;
unsigned unk38;
unsigned unk3c;
unsigned unk40;
unsigned unk44;
unsigned unk48;
unsigned unk4c;
unsigned unk50;
unsigned unk54;
CollisionList* pColl;void FUN_00ba89c0(Parser*);};
// pdb: CSpeedTreeRT::ParseCollisionObjects | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pFile
void Tree::FUN_00ba89c0(Parser* p)
{
    pColl = new CollisionList;
    int iToken3 = p->FUN_00ba92d0();
    V3 kPos2;
    do
    {
        Shape s;
        s.iType = 0;
        s.a.z = 0.0f;
        s.a.y = 0.0f;
        s.a.x = 0.0f;
        s.b.z = 0.0f;
        s.b.y = 0.0f;
        s.b.x = 0.0f;
        int type;
        switch (iToken3)
        {
        case 0x2ee2:
            type = 0;
            break;
        case 0x2ee3:
            type = 1;
            break;
        case 0x2ee4:
            type = 2;
            break;
        default:
            throw f3m_00bbe370::IdvFileError("malformed collision object info", false);
        }
        s.iType=type;
        kPos2.x = p->FUN_00ba92a0();
        kPos2.y = p->FUN_00ba92a0();
        kPos2.z = p->FUN_00ba92a0();
        s.a.x = kPos2.x;
        s.a.y = kPos2.y;
        s.a.z = kPos2.z;
        switch (type)
        {
        case 0:
            s.b.x = p->FUN_00ba92a0();
            break;
        case 1:
            s.b.x = p->FUN_00ba92a0();
            s.b.y = p->FUN_00ba92a0();
            break;
        case 2:
            s.b.x = p->FUN_00ba92a0();
            s.b.y = p->FUN_00ba92a0();
            s.b.z = p->FUN_00ba92a0();
            break;
        default:
            throw f3m_00bbe370::IdvFileError("unknown collision object type", false);
        }
        pColl->FUN_00ba81b0(s);
        if (p->FUN_00ba1ab0())
            throw f3m_00bbe370::IdvFileError("premature end of file reached parsing collision object info", false);
        else
            iToken3 = p->FUN_00ba92d0();
    } while (iToken3 != 0x2ee1);

}

}
}   // namespace f3m_00ba89c0

// @f3 0x00ba3d80 (community match, verified in this file)
#include <stdexcept>
#include <string>
extern const char DAT_00ea70b0[], DAT_00ea709c[];
namespace f3m_00ba3d80 {

class IdvFileError : public std::runtime_error
{
public:
    IdvFileError(const std::string&, bool);
    virtual ~IdvFileError();
};

namespace Lod532
{
struct Message
{
    unsigned int allocator;
    char data[16];
    unsigned int size, capacity;
    __forceinline Message(const char* text, unsigned int length)
    {
        capacity = 15;
        size = 0;
        data[0] = 0;
        FUN_0042f100(text, length);
    }
    ~Message();
    void FUN_0042f100(const char*, unsigned int);
    __forceinline const std::string& String() const
    {
        return *reinterpret_cast<const std::string*>(this);
    }
};
struct Reader
{
    int FUN_00ba92d0();
    float FUN_00ba92a0();
    bool FUN_00ba1ab0();
};
struct Settings { void FUN_00bbdff0(Reader*); };
struct Owner
{
    Settings* settings;
    char pad04[0x14];
    int count;
    float nearDistance, farDistance, bias;
    void FUN_00ba3d80(Reader*);
};
// pdb: CSpeedTreeRT::ParseLodInfo | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pFile
void Owner::FUN_00ba3d80(Reader* reader)
{
    int tag = reader->FUN_00ba92d0();
    do
    {
        switch (tag)
        {
        case 9002:
            count = reader->FUN_00ba92d0();
            break;
        case 9003:
            nearDistance = reader->FUN_00ba92a0();
            break;
        case 9004:
            farDistance = reader->FUN_00ba92a0();
            break;
        case 9009:
            bias = reader->FUN_00ba92a0();
            break;
        case 9005:
            settings->FUN_00bbdff0(reader);
            break;
        default:
            throw IdvFileError(Message(DAT_00ea709c, 18).String(), false);
        }
        if (reader->FUN_00ba1ab0())
            throw IdvFileError(Message(DAT_00ea70b0, 50).String(), false);
        tag = reader->FUN_00ba92d0();
    } while (tag != 9001);
}
}


}   // namespace f3m_00ba3d80

// @f3 0x00ba3010 (community match, verified in this file)
#include <vector>
namespace f3m_00ba3010 {
namespace nba3010 {
struct Mat { float m[4][4]; };
struct Vec { float x, y, z; Vec() {} Vec(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Elem { int type; Vec pos; float s0, s1, s2; };
inline Vec Xform(const Mat& M, const Vec& v)
{
    Vec r;
    r.x = M.m[0][0] * v.x + M.m[1][0] * v.y + M.m[2][0] * v.z + M.m[3][0];
    r.y = M.m[0][1] * v.x + M.m[1][1] * v.y + M.m[2][1] * v.z + M.m[3][1];
    r.z = M.m[0][2] * v.x + M.m[1][2] * v.y + M.m[2][2] * v.z + M.m[3][2];
    return r;
}
struct List {
    std::vector<Elem> v;
    void FUN_00ba3010(const Mat& M);
};
// pdb: SCollisionObjects::TransformAll | SpeedTreeRT.obj | fnv360_0822_retail, objrun, medium
// pdb params: cTransform
void List::FUN_00ba3010(const Mat& M)
{
    for (std::vector<Elem>::iterator it = v.begin(); it != v.end(); ++it)
    {
        Vec p(it->pos.x, it->pos.y, it->pos.z);
        Vec r = Xform(M, p);
        it->pos.x = r.x;
        it->pos.y = r.y;
        it->pos.z = r.z;
        if (it->type == 0)
            it->s0 *= M.m[0][0];
        else if (it->type == 1)
        {
            it->s0 *= M.m[0][0];
            it->s1 *= M.m[0][0];
        }
        else if (it->type == 2)
        {
            it->s0 *= M.m[0][0];
            it->s1 *= M.m[1][1];
            float& s2 = it->s2; s2 = M.m[2][2] * s2;
        }
    }
}
}
}   // namespace f3m_00ba3010

// @f3 0x00bbe150 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
namespace f3m_00bbe150 {
namespace f3m_00bbe150 {

class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string&,int);
};
struct TextureReader150 {
    unsigned int offset;
    std::vector<char> data;
    int FUN_00ba92d0();
    float FUN_00ba92a0();
    bool ReadBool() { return data[offset++]!=0; }
};
struct TextureControl150 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    short unk1C;
    bool flag1E;
    char unk1F;
    float value20;
};
struct TextureOwner150 {
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
    std::vector<TextureControl150*> controls60;
    void FUN_00bbe150(TextureReader150*);
};
// pdb: CTreeEngine::ParseTextureControls | TreeEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void TextureOwner150::FUN_00bbe150(TextureReader150* reader)
{
    for (unsigned int i=0;i<controls60.size();++i) {
        if (reader->FUN_00ba92d0()!=15002) throw IdvFileError("malformed texture controls",0);
        controls60[i]->flag1E=reader->ReadBool();
        if (reader->FUN_00ba92d0()!=15003) throw IdvFileError("malformed texture controls",0);
        controls60[i]->value20=reader->FUN_00ba92a0();
    }
    if (reader->FUN_00ba92d0()!=15001) throw IdvFileError("malformed texture controls",0);
}
}
}   // namespace f3m_00bbe150

// @f3 0x00ba3fa0 (community match, verified in this file)
#include <string>
#include <stdexcept>
namespace f3m_00ba3fa0 {

struct SpdParser3fa0 {
    int FUN_00ba92d0();
    bool FUN_00ba1ab0();
    int ParseToken() { return FUN_00ba92d0(); }
    bool AtEnd() { return FUN_00ba1ab0(); }
};

struct SpdWindInfo3fa0 {
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
    int m_nWindMatrixCount;
    void SetWindMatrixCount(int nCount) { m_nWindMatrixCount = nCount; }
};

struct SpdWindReader {
    SpdWindInfo3fa0* m_pWind;
    void FUN_00ba3fa0(SpdParser3fa0* pParser);
};

// pdb: CSpeedTreeRT::ParseWindInfo | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pFile
void SpdWindReader::FUN_00ba3fa0(SpdParser3fa0* pParser)
{
    int nToken = pParser->ParseToken();
    do
    {
        switch (nToken)
        {
        case 0x2afa:
            m_pWind->SetWindMatrixCount(pParser->ParseToken());
            break;
        default:
            throw IdvFileError("malformed new wind info", 0);
        }
        if (pParser->AtEnd())
            throw IdvFileError("premature end of file reached parsing new wind info", 0);
        else
            nToken = pParser->ParseToken();
    } while (nToken != 0x2af9);
}
}   // namespace f3m_00ba3fa0

// @f3 0x00bbca30 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <stdarg.h>
namespace f3m_00bbca30 {
namespace f3m_00bbca30 {

// pdb: IdvFormatString | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
static __declspec(noinline) std::string FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return std::string(text);
}

struct FrondVertex {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
};

struct FrondGuide {
    std::vector<FrondVertex> vertices;
    float f10, f14;
    unsigned char c18;
    float f1c, f20, f24;
    int i28, i2c;
};

struct FrondGeometry {
    void FUN_00bb2a70(unsigned short);
    void FUN_00baf1d0(unsigned short);
};

static const char vertexLimitMessage[] = "frond vertices exceed %d";
static const char invalidModeMessage[] = "default reached in CFrondEngine::Compute()";

struct FrondEngine {
    FrondGeometry* geometry;
    void* auxiliary;
    int state08, state0c, state10, state14;
    std::vector<std::vector<FrondGuide> > guides;
    int mode;
    int bladeCount;
    int state30;
    int extrusionCount;
    int state38, state3c, state40, state44, state48, state4c;
    unsigned short geometryType;
    void FUN_00bbc5b0();
    void FUN_00bb7280(FrondGuide&);
    void FUN_00bb4bf0(unsigned int, int, FrondGuide&);
    void FUN_00bbad60(FrondGuide&);
    void FUN_00bb4cb0(unsigned int, int, FrondGuide&);
    void FUN_00bbca30(FrondGeometry*, void*);
};

// pdb: CFrondEngine::Compute | FrondEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: pGeometry, pLightingEngine
void FrondEngine::FUN_00bbca30(FrondGeometry* output, void* context)
{
    geometry = output;
    auxiliary = context;
    int vertexCount = 0;
    FUN_00bbc5b0();
    for (unsigned i = 0; i < guides[0].size(); ++i)
    {
        switch (mode)
        {
        case 0: {
            vertexCount += guides[0][i].vertices.size() * 2 * bladeCount;
            break;
        }
        case 1: {
            vertexCount += guides[0][i].vertices.size() * (extrusionCount * 2 - 1);
            break;
        }
        default:
            throw IdvFileError(invalidModeMessage, false);
        }
    }
    if (vertexCount > 65535)
        throw std::runtime_error(FUN_00bb56f0(vertexLimitMessage, 65535));
    geometry->FUN_00bb2a70(geometryType);
    switch (mode)
    {
    case 0: {
        for (unsigned i = 0; i < guides[0].size(); ++i)
        {
            FUN_00bb7280(guides[0][i]);
        }
        for (unsigned short level = 0; level < guides.size(); ++level)
        {
            geometry->FUN_00baf1d0(level);
            for (unsigned j = 0; j < guides[level].size(); ++j)
            {
                FUN_00bb4bf0(level, guides[0][j].i28, guides[level][j]);
            }
        }
        break;
    }
    case 1: {
        for (unsigned i = 0; i < guides[0].size(); ++i)
        {
            FUN_00bbad60(guides[0][i]);
        }
        for (unsigned short level = 0; level < guides.size(); ++level)
        {
            geometry->FUN_00baf1d0(level);
            for (unsigned j = 0; j < guides[level].size(); ++j)
            {
                guides[level][j].i2c = guides[0][j].i2c;
                FUN_00bb4cb0(level, guides[0][j].i28, guides[level][j]);
            }
        }
        break;
    }
    default:
        throw IdvFileError(invalidModeMessage, false);
    }
}

}
}   // namespace f3m_00bbca30

// @f3 0x00bbf5b0 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
namespace f3m_00bbf5b0 {

struct BranchRecord5b0;
struct BinaryReader5b0 { int FUN_00ba92d0(); };
BranchRecord5b0* FUN_00bc4f60(BinaryReader5b0*);
class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string&, bool);
};
struct BranchLoader5b0 {
    char unknown00[0x60];
    std::vector<BranchRecord5b0*> branches;
    void CTreeEngine_ParseBranchInfo(BinaryReader5b0*);
};
// pdb: CTreeEngine::ParseBranchInfo | TreeEngine.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel), high
void BranchLoader5b0::CTreeEngine_ParseBranchInfo(BinaryReader5b0* reader)
{
    branches.clear();
    int count = reader->FUN_00ba92d0();
    for (int i = 0; i < count; ++i)
        branches.push_back(FUN_00bc4f60(reader));
    if (reader->FUN_00ba92d0() != 1015)
        throw IdvFileError(std::string("malformed branch data"), false);
}
}   // namespace f3m_00bbf5b0

// @f3 0x00bb1460 (community match, verified in this file)
namespace f3m_00bb1460 {
namespace vec16_bb1460 {

struct Elem16 { int a, b, c, d; };
struct CategoryTag {};
inline CategoryTag PtrCategory(Elem16*, Elem16*) { CategoryTag cat; return cat; }
struct Vec16;
Elem16* __cdecl FUN_00bb0340(Elem16* first, Elem16* last, Elem16* dest);
void __cdecl FUN_00baf710(Elem16* first, Elem16* last, Vec16& alloc, CategoryTag tag);

struct Vec16 {
    char alval;
    Elem16* first;
    Elem16* last;
    Elem16* end;

    unsigned int size() const { return first == 0 ? 0 : last - first; }
    unsigned int capacity() const { return first == 0 ? 0 : end - first; }
    void FUN_00bb0fe0();
    Elem16* FUN_00bb0f70(Elem16* from, Elem16* to, Elem16* dest);
    void FUN_00bafeb0(Elem16* from, Elem16* to);
    bool FUN_00baf750(unsigned int count);
    Vec16& FUN_00bb1460(const Vec16& right);
};

Vec16& Vec16::FUN_00bb1460(const Vec16& right)
{
    if (this != &right) {
        if (right.size() == 0)
            FUN_00bb0fe0();
        else if (right.size() <= size()) {
            Elem16* ptr = FUN_00bb0340(right.first, right.last, first);
            FUN_00baf710(ptr, last, *this, PtrCategory(ptr, last));
            last = first + right.size();
        } else if (right.size() <= capacity()) {
            Elem16* ptr = right.first + size();
            FUN_00bb0340(right.first, ptr, first);
            last = FUN_00bb0f70(ptr, right.last, last);
        } else {
            if (first != 0) {
                FUN_00bafeb0(first, last);
                operator delete(first);
            }
            if (FUN_00baf750(right.size()))
                last = FUN_00bb0f70(right.first, right.last, first);
        }
    }
    return *this;
}

} // namespace vec16_bb1460
}   // namespace f3m_00bb1460

// @f3 0x00bac000 (community match, verified in this file)
#include <vector>

namespace split_bac000 {
struct Item54 { bool opaque; char unknown01[0x53]; };
struct ItemOwner { char unknown00[0x10]; std::vector<Item54> items; };
}
extern split_bac000::ItemOwner* DAT_011782b0;
extern std::vector<int> DAT_011782e4;
extern std::vector<int> DAT_011782c4;

void __cdecl FUN_00bac000()
{
    DAT_011782e4.clear();
    DAT_011782c4.clear();
    for (unsigned int i = 0; i < DAT_011782b0->items.size(); ++i) {
        if (DAT_011782b0->items[i].opaque) {
            DAT_011782e4.push_back(2 * i);
            DAT_011782e4.push_back(2 * i + 1);
        } else {
            DAT_011782c4.push_back(2 * i);
            DAT_011782c4.push_back(2 * i + 1);
        }
    }
}

// @f3 0x00bba9f0 (community match, verified in this file)
#include <vector>
namespace f3m_00bba9f0 {

namespace vec48_bba9f0 {

struct Elem48 {
    Elem48(const Elem48&);
    Elem48& operator=(const Elem48&);
    ~Elem48();
    int data[12];
};

struct Vec48 : std::vector<Elem48> {
    Vec48& FUN_00bba9f0(const Vec48& _Right)
    {
        if (this != &_Right) {
            if (_Right.size() == 0)
                clear();
            else if (_Right.size() <= size()) {
                pointer _Ptr = stdext::unchecked_copy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                std::_Destroy_range(_Ptr, _Mylast, this->_Alval, std::_Ptr_cat(_Ptr, _Mylast));
                _Mylast = _Myfirst + _Right.size();
            } else if (_Right.size() <= capacity()) {
                pointer _Ptr = _Right._Myfirst + size();
                stdext::unchecked_copy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            } else {
                if (_Myfirst != 0) {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
        return *this;
    }
};

Vec48& (Vec48::*keep)(const Vec48&) = &Vec48::FUN_00bba9f0;

} // namespace vec48_bba9f0
}   // namespace f3m_00bba9f0

// @f3 0x00bb8740 (community match, verified in this file)
#include <vector>
#include <math.h>
extern float DAT_01068e28;
namespace f3m_00bb8740 {

namespace f3m_00bb8740 {


struct FrondPoint
{
    float v[3];
    FrondPoint()
    {
        v[0] = v[1] = v[2] = 0.0f;
    }
    FrondPoint(float x, float y, float z)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    float& operator[](int i)
    {
        return v[i];
    }
    void Normalize()
    {
        float fSumOfSquares = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
        float fInvSquareRoot = 1.0f / (float)sqrt(fSumOfSquares);
        v[0] *= fInvSquareRoot;
        v[1] *= fInvSquareRoot;
        v[2] *= fInvSquareRoot;
    }
};

typedef std::vector<FrondPoint> FrondPointVec;

struct FrondCurve
{
    float FUN_00bc2170(float t);
};

struct FrondScale
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float m_height;
};

struct FrondProfileOwner
{
    int unk00[12];
    FrondCurve* m_profile;
    unsigned m_uiItemCount;
    void FUN_00bb8740(FrondScale* scale, FrondPointVec& points, FrondPointVec& normals);
};

void FrondProfileOwner::FUN_00bb8740(FrondScale* scale, FrondPointVec& points, FrondPointVec& normals)
{
    float base = m_profile->FUN_00bc2170(0.0f) * scale->m_height;
    for (unsigned i = 0; i < m_uiItemCount; i++)
    {
        float t = 1.0 - (float)i / ((float)m_uiItemCount - 1.0);
        FrondPoint p;
        p[0] = 0.0f;
        p[1] = -t * scale->m_height;
        p[2] = m_profile->FUN_00bc2170(t) * scale->m_height - base;
        points.push_back(p);
    }
    for (int j = m_uiItemCount - 2; j >= 0; j--)
    {
        FrondPoint p = points[j];
        p[1] *= -1.0;
        points.push_back(p);
    }
    for (unsigned k = 0; k < points.size(); k++)
    {
        float angle;
        if (k == m_uiItemCount - 1)
            angle = DAT_01068e28;
        else if (k == 0)
        {
            float a = (float)atan2(points[k + 1][2] - points[k][2], points[k + 1][1] - points[k][1]);
            angle = a + DAT_01068e28;
        }
        else if (k == points.size() - 1)
        {
            float a = (float)atan2(points[k][2] - points[k - 1][2], points[k][1] - points[k - 1][1]);
            angle = a + DAT_01068e28;
        }
        else
        {
            float a1 = (float)atan2(points[k + 1][2] - points[k][2], points[k + 1][1] - points[k][1]);
            float a2 = (float)atan2(points[k][2] - points[k - 1][2], points[k][1] - points[k - 1][1]);
            angle = (a2 + a1) * 0.5 + DAT_01068e28;
        }
        FrondPoint n(0.0f, (float)cos(angle), (float)sin(angle));
        n.Normalize();
        normals.push_back(n);
    }
}

}  // namespace f3m_00bb8740
}   // namespace f3m_00bb8740

// @f3 0x00bb6600 (community match, verified in this file)
#include <vector>
#include <algorithm>
namespace f3m_00bb6600 {
namespace wbb6600 {

struct Entry {
    std::vector<unsigned int> list;
    float a, b;
    bool flag;
    float c, d, key;
    int x, y;
};

// pdb: std::vector<SFrondVertex,std::allocator<SFrondVertex> >::operator= | FrondEngine.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: _Right
void __cdecl FUN_00bb6600(Entry* left, Entry* right)
{
    Entry tmp(*left);
    *left = *right;
    *right = tmp;
}

}
}   // namespace f3m_00bb6600

// @f3 0x00bbf6f0 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
namespace f3m_00bbf6f0 {
inline void* __cdecl operator new[](size_t size) { return operator new(size); }
inline void __cdecl operator delete[](void* p) { operator delete(p); }
struct LeafRecord716;
struct BinaryReader716 { int FUN_00ba92d0(); };
LeafRecord716* FUN_00bc58c0(BinaryReader716*);
class IdvFileError : public std::runtime_error {
public:
    IdvFileError(const std::string&,bool);
};
struct LeafLodLoader716 {
    char unknown00[0xc0];
    int levelCount;
    char unknownc4[0x10];
    std::vector<LeafRecord716*>* levels;
    bool loaded;
    void FUN_00bbf6f0(BinaryReader716*);
};
// pdb: CTreeEngine::ParseLeafCluster | TreeEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void LeafLodLoader716::FUN_00bbf6f0(BinaryReader716* reader)
{
    int level = 0;
    levelCount=reader->FUN_00ba92d0();
    delete[] levels;
    levels=new std::vector<LeafRecord716*>[levelCount];
    int token=reader->FUN_00ba92d0();
    while(token!=7001)
    {
        if(level>=levelCount)
            throw IdvFileError(std::string("too many leaf lod levels"),false);
        if(token!=7002)
            throw IdvFileError(std::string("malformed leaf lod data"),false);
        token=reader->FUN_00ba92d0();
        while(token!=7003)
        {
            if(token!=7004)
                throw IdvFileError(std::string("malformed leaf lod data"),false);
            levels[level].push_back(FUN_00bc58c0(reader));
            token=reader->FUN_00ba92d0();
        }
        ++level;
        token=reader->FUN_00ba92d0();
    }
    loaded=true;
}
}   // namespace f3m_00bbf6f0

// @f3 0x00bbf090 (community match, verified in this file)
#include <vector>
namespace f3m_00bbf090 {
inline void* __cdecl operator new[](size_t size) { return operator new(size); }
inline void __cdecl operator delete[](void* p) { operator delete(p); }

namespace leaflod_bbf090 {

struct LodTarget;

struct LeafCluster {
    char unknown00[0x28];
    float size;
    float fade;
    void FUN_00ba9c60(unsigned int lod, LodTarget* target);
};

struct LodTarget {
    char unknown00[0x68];
    std::vector<int> indices;
    unsigned short TriangleCount() const { return (unsigned short)(indices.size() / 3); }
    void FUN_00baed70(int lod);
    void FUN_00baf1d0(unsigned int lod);
    void FUN_00bb0850(int a, int b, int c);
};

struct LeafSource {
    void FUN_00babf70(std::vector<LeafCluster*>* leaves);
};

class LeafRandom {
public:
    void FUN_00bc4c50();
    void FUN_00c24b70();
    float FUN_00bc4b40(float low, float high);
    LeafRandom() { FUN_00bc4c50(); }
    ~LeafRandom() { FUN_00c24b70(); }
};

inline float Lerp(float from, float to, float t) { return from + (to - from) * t; }
void __cdecl FUN_00babba0(std::vector<LeafCluster*>* leaves);

struct LeafLodBuilder {
    char unknown00[0x58];
    LeafSource* source;
    LodTarget* target;
    char unknown60[0x10];
    int lodCount;
    char unknown74[0x68];
    float lastScale;
    float firstScale;
    char unknowne4[4];
    float randomFade;
    float bigFraction;

    void FUN_00bbf090();
};

// pdb: CTreeEngine::BuildBranchLods | TreeEngine.obj | fnv360_0822_retail, call_gap, low
void LeafLodBuilder::FUN_00bbf090()
{
    std::vector<LeafCluster*> leaves;
    if (source && target->TriangleCount() > 0)
        source->FUN_00babf70(&leaves);

    float total = 0.0f;
    float largest = 0.0f;
    for (unsigned int i = 0; i < leaves.size(); ++i) {
        float size = leaves[i]->size;
        total += size;
        if (largest < size)
            largest = size;
    }

    LeafRandom random;
    float threshold = 1.0f - bigFraction;
    std::vector<LeafCluster*> big;
    for (unsigned int j = 0; j < leaves.size(); ++j) {
        float size = leaves[j]->size;
        if (size > threshold * largest) {
            big.push_back(leaves[j]);
            leaves.erase(leaves.begin() + j);
            --j;
        } else {
            float r = random.FUN_00bc4b40(0.0f, randomFade);
            float keep = 1.0f - r;
            size = keep * size + r * largest;
            size = std::max(size, 0.0f);
            leaves[j]->fade = size;
        }
    }

    FUN_00babba0(&leaves);
    FUN_00babba0(&big);
    for (unsigned int i = 0; i < big.size(); ++i)
        leaves.insert(leaves.begin(), big[i]);

    int count = lodCount;
    for (unsigned int lod = 0; lod < count; ++lod) {
        if (lod == 0)
            target->FUN_00baed70(0);
        float scale;
        if (count < 2)
            scale = 1.0f;
        else {
            scale = Lerp(firstScale, lastScale, (float)lod / (count - 1));
        }
        float limit = scale * total;
        float sum = 0.0f;
        int used = 0;
        for (unsigned int i = 0; i < leaves.size(); ++i) {
            if (!(sum < limit))
                break;
            float size = leaves[i]->size;
            ++used;
            sum += size;
        }
        target->FUN_00baf1d0(lod);
        if (lod == 0 && used == 0)
            target->FUN_00bb0850(0, 0, 0);
        else
            for (int k = 0; k < used; ++k)
                leaves[k]->FUN_00ba9c60(lod, target);
    }
}

} // namespace leaflod_bbf090
}   // namespace f3m_00bbf090

// @f3 0x00bb1310 (community match, verified in this file)
#include <new>
namespace f3m_00bb1310 {

namespace NativeVecCopyBB1310 {
struct Element { int a, b, c, d; };
struct Category {};
inline Category PtrCategory(Element*, Element*) { Category tag; return tag; }
struct Vector;
Element* __cdecl FUN_00bb0300(Element* first, Element* last, Element* dest);
void __cdecl FUN_00baf710(Element* first, Element* last, Vector& alloc, Category tag);

struct Vector {
    char allocator;
    Element* first;
    Element* last;
    Element* end;

    unsigned int size() const { return first == 0 ? 0 : last - first; }
    unsigned int capacity() const { return first == 0 ? 0 : end - first; }
    void FUN_00bb0fa0();
    Element* FUN_00bb0f40(Element* from, Element* to, Element* dest);
    void FUN_00bafeb0(Element* from, Element* to);
    bool FUN_00baf750(unsigned int count);
    Vector& FUN_00bb1310(const Vector& right);
};

// pdb: std::vector<std::vector<unsigned short,std::allocator<unsigned short> >,std::allocator<std::vector<unsigned short,std::allocator<unsigned short> > > >::operator= | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Right
Vector& Vector::FUN_00bb1310(const Vector& right)
{
    if (this != &right) {
        if (right.size() == 0)
            FUN_00bb0fa0();
        else if (right.size() <= size()) {
            Element* ptr = FUN_00bb0300(right.first, right.last, first);
            FUN_00baf710(ptr, last, *this, PtrCategory(ptr, last));
            last = first + right.size();
        } else if (right.size() <= capacity()) {
            Element* ptr = right.first + size();
            FUN_00bb0300(right.first, ptr, first);
            last = FUN_00bb0f40(ptr, right.last, last);
        } else {
            if (first != 0) {
                FUN_00bafeb0(first, last);
                operator delete(first);
            }
            if (FUN_00baf750(right.size()))
                last = FUN_00bb0f40(right.first, right.last, first);
        }
    }
    return *this;
}
}
}   // namespace f3m_00bb1310

// @f3 0x00baeee0 (community match, verified in this file)
#include <vector>
namespace f3m_00baeee0 {
namespace nbaeee0 {
struct Point { float x, y, z; };
struct FUN_00c24b70 {
    float m[6];
    ~FUN_00c24b70();
};
struct Bound {
    FUN_00c24b70 a;
    FUN_00c24b70 b;
    Bound FUN_00bc48f0(const Point& p) const;
};
struct Shape {
    char pad[0x68];
    std::vector<float> m_points;
    void FUN_00baeee0(Bound* bound);
};
// pdb: CIndexedGeometry::ComputeExtents | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: cExtents
void Shape::FUN_00baeee0(Bound* bound)
{
    unsigned short count = (unsigned short)(m_points.size() / 3);
    for (int i = 0; i < count; i++)
    {
        const Point& src = ((const Point*)&m_points[0])[i];
        float x = src.x;
        float y = src.y;
        float z = src.z;
        Point p;
        p.x = x;
        p.y = y;
        p.z = z;
        *bound = bound->FUN_00bc48f0(p);
    }
}
}
}   // namespace f3m_00baeee0

// @f3 0x00bbc300 (community match, verified in this file)
#include <new>
extern const char DAT_00ea7d00[];
namespace f3m_00bbc300 {
namespace batch14_17 {

template<int N>struct Vector {
void* data;
unsigned size,cap;
Vector():data(0),size(0),cap(0){
}
~Vector();
}
;

struct String {
unsigned allocator;
union {
char small[16];
char* ptr;
}
;
unsigned length,capacity;
void FUN_0042f100(const char*,unsigned);
String(const char* text,unsigned n){
capacity=15;
length=0;
small[0]=0;
FUN_0042f100(text,n);
}
~String(){
if(capacity>=16)::operator delete(ptr);
}
}
;


struct FUN_00bc4810 {
unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
FUN_00bc4810(const String&);
}
;

struct Vec3 {
float x,y,z;
Vec3(){
x=1.0f;
y=0.0f;
z=0.0f;
}
}
;
struct FUN_00bbc300 {
unsigned a,b,u08;
Vector<0> first;
unsigned u18;
Vector<1> second;
unsigned u28,u2c;
FUN_00bc4810* object;
unsigned u34,u38;
bool flag;
unsigned u40;
Vector<2> third;
unsigned u50;
float x54,y58,z5c;
float f60;
unsigned u64,u68;
FUN_00bbc300();
}
;

// pdb: CFrondEngine::CFrondEngine | FrondEngine.obj | fnv360_0822_retail, ustr, medium
FUN_00bbc300::FUN_00bbc300():a(0),b(0),u28(1),u2c(2),u34(4),u38(1),flag(false),u50(4),x54(1.0f),y58(0.0f),z5c(0.0f),f60(0.05f),u64(2),u68(1){
object=new FUN_00bc4810(String(DAT_00ea7d00,153));
}

}
}   // namespace f3m_00bbc300

// @f3 0x00bafa00 (community match, verified in this file)
namespace f3m_00bafa00 {
namespace w_bafa00 {
class WordVector : public std::vector<unsigned short>
{
public:
    void FUN_00bafa00(iterator _Where, size_type _Count, const unsigned short& _Val);
};
void WordVector::FUN_00bafa00(iterator _Where, size_type _Count, const unsigned short& _Val)
{
    unsigned short _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
        _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
        _Ptr = _Ufill(_Ptr, _Count, _Tmp);
        _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
        _Destroy(_Newvec, _Ptr);
        this->_Alval.deallocate(_Newvec, _Capacity);
        throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try {
        _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
        _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
        throw;
        }
        _Mylast += _Count;
        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}
}
}   // namespace f3m_00bafa00

// @f3 0x00bbed60 (community match, verified in this file)
#include <new>
#include <vector>
namespace f3m_00bbed60 {
extern void __cdecl FUN_00c01e8b();
struct Record { int pad[18]; float x,y; int tail; };
struct Records {
 Record* first; Record* last; Record* end;
 unsigned size() const {return first ? last-first : 0;}
 Record& operator[](unsigned i) {if(i>=size()) FUN_00c01e8b();return first[i];}
};
struct FUN_00be0df0 {
 unsigned allocator; unsigned* first; unsigned* last; unsigned* end;
 FUN_00be0df0(const FUN_00be0df0&);
 FUN_00be0df0& FUN_00bafd80(const FUN_00be0df0&);
 ~FUN_00be0df0() {if(first) ::operator delete(first);first=0;last=0;end=0;}
};
typedef FUN_00be0df0 Vector;
struct Pair {float x,y;};
struct PairVector {
 unsigned allocator; Pair* first; Pair* last; Pair* end;
 ~PairVector() {if(first) ::operator delete(first);first=0;last=0;end=0;}
};
struct FUN_00bc6580 : PairVector {
 float maximum,parameter;void* source;float factor;
 FUN_00bc6580(void*,float,float,float);
 Vector FUN_00bc6dc0(Vector);
};
typedef FUN_00bc6580 Init;
struct Target {
 int pad00[29]; Vector initial; int pad84[4]; std::vector<Record> records;
 float scale;int pada8[6];int count;int padc4[4];Vector* values;int padd8[3];float parameter;
 void FUN_00bbed60(float);
};
// pdb: CTreeEngine::BuildLeafLods | TreeEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: fLeafSizeIncreaseFactor
void Target::FUN_00bbed60(float step) {
 float maximum=-1.0f;
 for(unsigned i=0;i<records.size();i++) {
  Record* record=&records[i];
  float dimension=record->x>record->y?record->x:record->y;
  if(maximum<dimension*scale) maximum=dimension*scale;
 }
 if(maximum==-1.0) maximum=10.0f;
 if(values) {
  values[0].FUN_00bafd80(initial);
  for(int iteration=1;iteration<count;iteration++) {
   float stepFactor=1.0f+iteration*step;
   Init operation(&pad84,(float)(maximum*10.0),parameter,stepFactor);
   values[iteration].FUN_00bafd80(operation.FUN_00bc6dc0(values[iteration-1]));
  }
 }
}
}   // namespace f3m_00bbed60

// @f3 0x00baa550 (community match, verified in this file)
namespace w3_baa550 {
void __cdecl FUN_00c01e8b();
struct Pt3 { float x, y, z; };
struct Rec { char pad[0x48]; float lo, hi, unk50; };
struct Box { int unk00; Pt3 pos; };
struct RecVec {
    int al;
    Rec* first; Rec* last; Rec* end;
    unsigned size() const { return first == 0 ? 0 : last - first; }
    Rec& operator[](unsigned i) { if (i >= size()) FUN_00c01e8b(); return first[i]; }
};
struct BoxVec {
    int al;
    Box** first; Box** last; Box** end;
    unsigned FUN_00baa310() const;
    unsigned isize() const { return first == 0 ? 0 : last - first; }
    Box*& operator[](unsigned i) { if (i >= isize()) FUN_00c01e8b(); return first[i]; }
};
struct Table { char pad[0x10]; RecVec recs; float scale; };
extern Table* DAT_011782b0;
bool __stdcall FUN_00baa550(const Pt3* center, unsigned index, BoxVec* boxes)
{
    bool result = true;
    if (DAT_011782b0->recs.size() != 0) {
    Rec& r = DAT_011782b0->recs[index];
    float rad = r.lo > r.hi ? r.lo : r.hi;
    rad = DAT_011782b0->scale * rad;
    for (unsigned i = 0; i < boxes->FUN_00baa310(); i++) {
        if (!result) break;
        Box* b = (*boxes)[i]; const Pt3& p = b->pos;
        if (center->x < p.x + rad && center->x > p.x - rad &&
            center->y < p.y + rad && center->y > p.y - rad &&
            center->z < p.z + rad && center->z > p.z - rad)
            result = false;
    }
    } else result = false;
    return result;
}
}

// @f3 0x00bbdd30 (community match, verified in this file)
#include <vector>
namespace f3m_00bbdd30 {
namespace f3m_00bbdd30 {
struct Node { virtual ~Node(); };
struct Res { ~Res(); };     // FUN_00bc4e60
struct Sub { ~Sub(); };     // FUN_00bab4e0
typedef std::vector<Node*> NodeVec;   // dtor FUN_00bbdcd0
struct Mgr {
    char pad00[0x21];
    bool active;
    char pad22[0x58 - 0x22];
    Sub* sub;
    char pad5c[4];
    std::vector<Res*> res;
    char pad70[0xc0 - 0x70];
    int count;
    char padc4[0xd4 - 0xc4];
    NodeVec* lists;
    void FUN_00bbdd30();
};
// pdb: CTreeEngine::FreeTransientData | TreeEngine.obj | fnv360_0822_retail, call_seq, medium
void Mgr::FUN_00bbdd30()
{
    if (!active) return;
    delete sub;
    sub = 0;
    for (int i = 0; i < count; i++) {
        if (lists) {
            for (unsigned int j = 0; j < lists[i].size(); j++) {
                delete lists[i][j];
                lists[i][j] = 0;
            }
            lists[i].clear();
        }
    }
    delete[] lists;
    lists = 0;
    for (unsigned int j = 0; j < res.size(); j++) {
        delete res[j];
        res[j] = 0;
    }
    res.clear();
    active = false;
}
}
}   // namespace f3m_00bbdd30

// @f3 0x00ba9c60 (community match, verified in this file)
struct NewTag_ba9c60 {};
inline void* operator new[](unsigned int size, NewTag_ba9c60) { return ::operator new(size); }
namespace nba9c60 {
typedef unsigned short u16;
struct Strip {
    char pad00[0x26];
    unsigned short unk26;
    void FUN_00bb0850(void* owner, unsigned short* indices, int count);
};
struct Grid {
    char pad00[0x1c];
    int m_rows;
    unsigned short m_cols;
    unsigned short pad22;
    unsigned short m_base;
    void FUN_00ba9c60(void* owner, Strip* strip);
};

// pdb: CIdvBranch::ComputeLod | Branch.obj | fnv360_0822_retail, call_gap, low
// pdb params: nDiscreteLodLevel, pGeometry
void Grid::FUN_00ba9c60(void* owner, Strip* strip)
{
    if (m_cols < 2)
        return;
    int cols = m_cols;
    float step = cols == 0 ? 1.0f : (float)m_cols / cols;
    int rows = m_rows;
    int count = ((cols + 2) + (cols + 2)) * (rows - 1);
    NewTag_ba9c60 tag;
    unsigned short* indices = new (tag) u16[count];
    strip->FUN_00bb0850(owner, indices, count);
    float v = 0.0f;
    int i = 0;
    for (int r = 0; r < rows - 1; r++) {
        int start = (int)v;
        indices[i++] = m_base + (unsigned short)v + m_cols + 1;
        indices[i++] = m_base + (unsigned short)v;
        v += step;
        for (int c = 1; c < cols; c++) {
            indices[i++] = m_base + (unsigned short)v + m_cols + 1;
            indices[i++] = m_base + (unsigned short)v;
            v += step;
        }
        indices[i++] = m_cols + m_cols + start + m_base + 1;
        indices[i++] = m_base + start + m_cols;
        int next = m_cols + start + 1;
        indices[i++] = m_cols + start + m_base + 1;
        indices[i++] = m_base + start + m_cols + 1;
        v = (float)next;
    }
    strip->unk26++;
}
}

// @f3 0x00bb5d10 (community match, verified in this file)
#include <vector>
namespace f3m_00bb5d10 {

namespace vec56_bb5d10 {

struct Elem56 {
    Elem56(const Elem56&);
    Elem56& operator=(const Elem56&);
    int data[14];
};

struct Vec56 : std::vector<Elem56> {
    // pdb: std::vector<SFrondVertex,std::allocator<SFrondVertex> >::operator= | FrondEngine.obj | fnv360_0721_beta, objrun_prop, low
    // pdb params: _Right
    Vec56& FUN_00bb5d10(const Vec56& _Right)
    {
        if (this != &_Right) {
            if (_Right.size() == 0)
                clear();
            else if (_Right.size() <= size()) {
                pointer _Ptr = stdext::unchecked_copy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                std::_Destroy_range(_Ptr, _Mylast, this->_Alval, std::_Ptr_cat(_Ptr, _Mylast));
                _Mylast = _Myfirst + _Right.size();
            } else if (_Right.size() <= capacity()) {
                pointer _Ptr = _Right._Myfirst + size();
                stdext::unchecked_copy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            } else {
                if (_Myfirst != 0) {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
        return *this;
    }
};

Vec56& (Vec56::*keep)(const Vec56&) = &Vec56::FUN_00bb5d10;

} // namespace vec56_bb5d10
}   // namespace f3m_00bb5d10

// @f3 0x00bb1c50 (community match, verified in this file)
#include <vector>
namespace f3m_00bb1c50 {

namespace leafdata_bb1c50 {

struct FUN_00bb1c50 {
    char unknown00[0xc];
    int* buffer;
    char unknown10[0x18];
    std::vector<int> v28;
    std::vector<std::vector<int> > v38;
    std::vector<std::vector<int> > v48;
    std::vector<int> v58, v68, v78, v88, v98, va8, vb8, vc8, vd8, ve8, vf8, v108;

    void FUN_00bb1100();
    ~FUN_00bb1c50();
};

// pdb: CIndexedGeometry::~CIndexedGeometry | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
FUN_00bb1c50::~FUN_00bb1c50()
{
    delete buffer;
    buffer = 0;
    FUN_00bb1100();
}

} // namespace leafdata_bb1c50
}   // namespace f3m_00bb1c50

// @f3 0x00bb4670 (community match, verified in this file)
namespace f3m_00bb5fe0 {
namespace Slot1VectorBB {
unsigned Vector::FUN_00bb4670() const
{
    if (!begin)
        return 0;
    return (unsigned)(end - begin);
}
}
}

// @f3 0x00ba3540 (community match, verified in this file)
namespace f3m_00ba3540 {
struct Inner00ba3420 {
    void FUN_00ba3420();
};

struct Outer00ba3540 {
    int unk00;
    Inner00ba3420* unk04;
    void FUN_00ba3540();
};

// pdb: CSpeedTreeRT::FreeBranchWindData | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void Outer00ba3540::FUN_00ba3540() {
    if (unk04) unk04->FUN_00ba3420();
}
}   // namespace f3m_00ba3540

// @f3 0x00bb5f90 (community match, verified in this file)
namespace f3m_00bb5f90 {
struct FUN_00bb5f90_Element {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;

    void __thiscall FUN_0042eff0(FUN_00bb5f90_Element* source, int b, int a);
};

// pdb: std::vector<SFrondVertex,std::allocator<SFrondVertex> >::vector<SFrondVertex,std::allocator<SFrondVertex> > | FrondEngine.obj | fnv360_1110_retail, objopen_prop, low
// pdb params: _Right
int __cdecl FUN_00bb5f90(FUN_00bb5f90_Element* first,
                          FUN_00bb5f90_Element* last,
                          FUN_00bb5f90_Element* dest) {
    if (first != last) {
        do {
            last = reinterpret_cast<FUN_00bb5f90_Element*>(
                reinterpret_cast<char*>(last) - 0x2C);
            dest = reinterpret_cast<FUN_00bb5f90_Element*>(
                reinterpret_cast<char*>(dest) - 0x2C);

            dest->FUN_0042eff0(last, 0, -1);

            dest->unk1C = last->unk1C;
            dest->unk20 = last->unk20;
            dest->unk24 = last->unk24;
            dest->unk28 = last->unk28;
        } while (last != first);
    }

    return reinterpret_cast<int>(dest);
}
}   // namespace f3m_00bb5f90

// @f3 0x00ba5ae0 (community match, verified in this file)
extern char DAT_00ea732c[];
namespace f3m_00ba5ae0 {
struct FUN_00ba5ae0_Data {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;

    void FUN_00bbdd30();
};

struct Logger_01068a70 {
    void FUN_0042f100(const char* message, int code);
};


struct FUN_00ba5ae0_Obj {
    FUN_00ba5ae0_Data* unk00;

    void FUN_00ba5ae0();
};

// pdb: CSpeedTreeRT::DeleteTransientData | SpeedTreeRT.obj | fnv360_0822_retail, ustr_rel, medium
void FUN_00ba5ae0_Obj::FUN_00ba5ae0() {
    FUN_00ba5ae0_Data* data = unk00;

    if (data->unk21 != 0) {
        data->FUN_00bbdd30();
    } else {
        reinterpret_cast<Logger_01068a70*>(&DAT_01068a70)->FUN_0042f100(DAT_00ea732c, 0x3a);
    }
}
}   // namespace f3m_00ba5ae0

// @f3 0x00bacd10 (community match, verified in this file)
#include <math.h>
#include <vector>
extern const double DAT_00e31f80;
namespace f3m_00bacd10 {

struct BranchMatrix;
struct BranchPoint
{
    float x, y, z;
    BranchPoint()
    {}
    BranchPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void Normalize()
    {
        float magnitude = x * x + y * y + z * z;
        float inverse = 1.0f / sqrtf(magnitude);
        x *= inverse;
        y *= inverse;
        z *= inverse;
    }
    float Dot(const BranchPoint& p)
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float FUN_00baa4e0(const BranchPoint& p);
    float AngleBetween(const BranchPoint& p)
    {
        float dot = Dot(p);
        if (dot < -1.0f)
            dot = -1.0f;
        if (dot > 1.0f)
            dot = 1.0f;
        return acosf(dot);
    }
    BranchPoint Cross(const BranchPoint& p)
    {
        return BranchPoint(p.z * y - p.y * z, p.x * z - p.z * x, p.y * x - p.x * y);
    }
    BranchPoint operator*(float f) const
    {
        float a = f * x;
        float b = f * y;
        float c = f * z;
        return BranchPoint(a, b, c);
    }
    BranchPoint operator-(const BranchPoint& p) const
    {
        float a = x - p.x;
        float b = y - p.y;
        float c = z - p.z;
        return BranchPoint(a, b, c);
    }
    BranchPoint operator+(const BranchPoint& p) const
    {
        float a = p.x + x;
        float b = p.y + y;
        float c = p.z + z;
        return BranchPoint(a, b, c);
    }
};

struct BranchMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    BranchMatrix()
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
    }
    BranchPoint TransformVector(const BranchPoint& p) const
    {
        return BranchPoint(p.z * m02 + (p.y * m01 + p.x * m00), p.z * m12 + (p.y * m11 + p.x * m10),
                           p.z * m22 + (p.y * m21 + p.x * m20));
    }
    void FUN_00ba9890(float, BranchPoint);
    void FUN_00ba97a0(float, float);
    void FUN_00ba99a0(float, BranchPoint);
    BranchMatrix FUN_00ba9610(const BranchMatrix&);
};

inline float BranchDegrees(float a)
{
    return a * DAT_00e31f80;
}
inline float BranchFalloff(float p)
{
    return 1.0f - 0.011111111f * p;
}
inline float BranchInterpolate(float a, float b, float t)
{
    return a + (b - a) * t;
}

struct BranchCurve
{
    float FUN_00bc2170(float);
    float FUN_00bc22d0(float);
};

struct BranchCurvePtr
{
    BranchCurve* ptr;
    BranchCurve* operator->() const
    {
        return ptr;
    }
};

struct BranchConfig
{
    int sides, segments;
    float lower, upper, children, width, height;
    bool fixedWidth, fixedHeight, animate;
    char unk1f;
    float twist, exponent;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    BranchCurvePtr orientation, bend, material, variation, length, thickness, radius, base, noise;
};

struct BranchMesh
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    float diameter, start;
    unsigned short unk20, vertices, unk24, groups;
    unsigned short GetVertices() const
    {
        return vertices;
    }
    void SetVertices(unsigned short n)
    {
        vertices = n;
    }
    void SetDiameter(float f)
    {
        diameter = f;
    }
    void SetStart(float f)
    {
        start = f;
    }
    void FUN_00bb0850(int, unsigned short*, unsigned short);
};

struct BranchEntry
{
    BranchPoint direction, position;
    float radius;
    BranchMatrix matrix;
    float distance, weight;
    BranchEntry();
};

struct BranchRandom
{
    float FUN_00bc4b40(float, float);
    void FUN_00bc4b70(unsigned int);
};

struct BranchTransform
{
    float x, y, z;
    BranchPoint RotateBy(const BranchMatrix& a)
    {
        return BranchPoint(a.m20 * z + (a.m10 * y + a.m00 * x), a.m21 * z + (a.m11 * y + a.m01 * x),
                           a.m22 * z + (a.m12 * y + a.m02 * x));
    }
};

struct BranchManager
{
    bool FUN_00bb45c0();
    int FUN_00896c70();
    void FUN_00bbbe30();
    void FUN_00bb71d0(BranchPoint, BranchMatrix, float, unsigned int);
    void FUN_00bb4860(float);
};

extern const float DAT_00e00d60;
extern const float DAT_00de7c24;
extern BranchManager* DAT_011782bc;
extern unsigned int DAT_011782b8;
extern BranchRandom DAT_011782c1;
extern bool DAT_011782c0;
extern int DAT_01068b34;
extern bool DAT_01068b30;
extern float DAT_01068b40;
extern BranchTransform DAT_01068b44;
extern BranchPoint DAT_01068b50;
extern std::vector<BranchConfig*> DAT_011782d4;
extern std::vector<unsigned int> DAT_011782f4;

inline BranchPoint* __cdecl InterpolatePoint(BranchPoint* out, const BranchPoint* a, const BranchPoint* b, float t)
{
    float dx = b->x - a->x, dy = b->y - a->y, dz = b->z - a->z;
    float sx = dx * t, sy = dy * t, sz = dz * t;
    float rx = a->x + sx, ry = a->y + sy, rz = a->z + sz;
    out->x = rx;
    out->y = ry;
    out->z = rz;
    return out;
}

struct BranchNode;
struct BranchChild
{
    int idx;
    float t;
    BranchNode* object;
};

struct BranchNode
{
    BranchNode* parent;
    float time;
    std::vector<BranchChild> childList;
    BranchEntry* entries;
    int entryCount;
    unsigned short type, unk22;
    unsigned int firstVertex;
    float unk28, unk2c;
    std::vector<unsigned int> unk30;

    BranchNode(BranchNode* p)
        : parent(p), time(0.0f), childList(), entries(0), entryCount(-1), type(0), firstVertex(-1), unk28(0.0f),
          unk2c(0.0f), unk30()
    {}
    ~BranchNode();
    unsigned int Count() const
    {
        return childList.size();
    }
    void FUN_00bac000();
    void FUN_00bac610(BranchConfig*);
    float BaseWeight(int id, float a, float b)
    {
        float result = 1.0f;
        if (id == DAT_01068b34)
            result = result - a * b;
        return result;
    }
    float BlendWeight(float value, float factor)
    {
        float result = factor * (0.0 - value) + value;
        return result;
    }
    void FUN_00baa6d0(BranchEntry*, float, float, unsigned short, BranchMesh*, const BranchPoint&, float, unsigned int,
                      float, int);
    void FUN_00ba9fe0(BranchMesh*, unsigned short);
    void FUN_00ba9f60(BranchChild*, float);
    void FUN_00bac830(BranchNode*, float, int, BranchPoint*, float, const BranchMatrix*, BranchEntry*, void*, float,
                      unsigned int);
    void FUN_00ba9ed0();
    void FUN_00bacd10(unsigned int, float, int, const BranchPoint&, float, float, const BranchMatrix&,
                      const BranchPoint&, BranchMesh*, void*, float, unsigned int, float);
};

// pdb: CIdvBranch::Compute | Branch.obj | fnv360_0822_retail, call_gap, low
// pdb params: nSeed, fSize, nLevel, cBasePos, fPercentOfParent, fCombinedPercentOfParent, cBaseTransform, cZAxis, pBranchGeometry, vLeaves, fWindWeight, nWindGroup, fParentRadius
void BranchNode::FUN_00bacd10(unsigned int seed, float scale, int level, const BranchPoint& origin, float age,
                              float parentFactor, const BranchMatrix& transform, const BranchPoint& axis,
                              BranchMesh* mesh, void* context, float weight, unsigned int id, float cap)
{
    bool animation = DAT_011782bc->FUN_00bb45c0() && level >= DAT_011782bc->FUN_00896c70();
    if (level == DAT_01068b34)
        id = DAT_011782b8++;
    if (level == 0)
        FUN_00bac000();
    float thickness;
    BranchConfig* material = DAT_011782d4[level];
    if (!animation)
        firstVertex = mesh->GetVertices();
    time = age;
    if (!animation)
        FUN_00bac610(material);
    float angle = (float)(material->length->FUN_00bc2170(age) * scale);
    float radius = angle / material->segments;
    float base = DAT_011782c1.FUN_00bc4b40(DAT_00e00d60, DAT_00de7c24);
    float config = material->base->FUN_00bc2170(age);
    float managed = material->bend->FUN_00bc2170(age);
    float length = material->thickness->FUN_00bc2170(age) * scale;
    thickness = material->material->FUN_00bc2170(age);
    type = (unsigned short)material->sides;
    float step = material->animate ? base + 0.5 + age : 0.0;
    {
        BranchPoint shape(material->fixedWidth ? material->width : material->width * length * DAT_01068b40,
                          material->fixedHeight ? material->height : angle / scale * material->height,
                          (seed + Count()) % 2 == 0 ? material->twist : -material->twist);
        float bend = material->radius->FUN_00bc2170(0.0f) * length;
        if (cap > 0.0 && bend > cap * 0.85f)
        {
            bend = (float)(cap * 0.85f);
            length = bend;
        }
        entryCount = material->segments + 1;
        if (entryCount < 2)
            return;
        entries = new BranchEntry[entryCount];
        if (!animation)
        {
            unsigned short index = (entryCount - 1) * (material->sides * 2 + 4);
            unsigned short* indices = new unsigned short[index];
            unsigned short column = mesh->GetVertices();
            int vertex = 0;
            int numIndices = 0;
            for (int row = 0; row < entryCount - 1; row++)
            {
                int first = numIndices;
                for (int side = 0; side < material->sides + 1; side++)
                {
                    indices[vertex] = column + (numIndices + (material->sides + 1));
                    vertex++;
                    indices[vertex] = column + numIndices;
                    vertex++;
                    numIndices++;
                }
                indices[vertex] = column + (first + (material->sides + 1));
                vertex++;
                indices[vertex] = column + (first + (material->sides + 1));
                vertex++;
            }
            mesh->FUN_00bb0850(0, indices, index);
            mesh->groups++;
        }
        BranchEntry* current = entries;
        current->position = origin;
        float roll = material->orientation->FUN_00bc22d0(0.0f);
        float pitch = material->orientation->FUN_00bc22d0(0.0f);
        current->matrix = transform;
        BranchPoint rotationAxis = transform.TransformVector(axis);
        current->matrix.FUN_00ba9890(base, rotationAxis);
        current->matrix.FUN_00ba97a0(config + pitch, roll);
        current->direction = DAT_01068b44.RotateBy(current->matrix);
        current->radius = (float)(material->radius->FUN_00bc2170(0.0f) * length);
        float variation = (float)(material->variation->FUN_00bc2170(0.0f) * thickness);
        float degrees = (float)(current->direction.FUN_00baa4e0(DAT_01068b50) * DAT_00e31f80);
        float falloff = 1.0f - 0.011111111f * fabs((float)(90.0 - degrees));
        BranchPoint gravityAxis = current->direction.Cross(DAT_01068b50);
        gravityAxis.Normalize();
        float noise = (float)((material->noise->FUN_00bc2170(0.0f) - 0.5) * 2.0 * -1.0);
        BranchMatrix gravity;
        gravity.FUN_00ba99a0(noise * managed * degrees * falloff, gravityAxis);
        current->matrix = current->matrix.FUN_00ba9610(gravity);
        current->direction = DAT_01068b44.RotateBy(current->matrix);
        if (mesh && level == 0)
        {
            mesh->SetDiameter(current->radius * 2.0f);
            mesh->SetStart(material->lower * angle);
        }
        float currentWeight = weight;
        if (level <= DAT_01068b34)
        {
            current->weight = BaseWeight(level, 0.0f, variation);
            currentWeight = current->weight;
        }
        else if (DAT_011782c0)
        {
            current->weight = BlendWeight(weight, variation);
            currentWeight = current->weight;
        }
        if (!animation)
        {
            float factor = 0.0f;
            if ((bool)level)
                factor = parentFactor;
            FUN_00baa6d0(current, 0.0f, factor, type, mesh, shape, currentWeight, id, step, level);
        }
        else
        {
            DAT_011782bc->FUN_00bbbe30();
            DAT_011782bc->FUN_00bb71d0(current->position, current->matrix, currentWeight, id);
        }
        float distance = 0.0f;
        entries->distance = 0.0f;
        BranchEntry* previous = current;
        for (int segment = 1; segment < entryCount; segment++)
        {
            BranchEntry* entry = &entries[segment];
            float fraction = (float)segment / (entryCount - 1);
            float position = powf(fraction, material->exponent);
            radius = position * angle - distance;
            entry->radius = material->radius->FUN_00bc2170(position) * length;
            float segmentVariation = material->variation->FUN_00bc2170(position) * thickness;
            entry->matrix = previous->matrix;
            entry->direction = DAT_01068b44.RotateBy(entry->matrix);
            float segmentDegrees = BranchDegrees(entry->direction.AngleBetween(DAT_01068b50));
            float segmentFalloff = 1.0f - 0.011111111f * fabs((float)(90.0 - segmentDegrees));
            BranchPoint segmentAxis = entry->direction.Cross(DAT_01068b50);
            segmentAxis.Normalize();
            float segmentNoise = (material->noise->FUN_00bc2170(position) - 0.5) * 2.0 * -1.0;
            gravity.FUN_00ba99a0(segmentNoise * managed * segmentDegrees * segmentFalloff, segmentAxis);
            entry->matrix = entry->matrix.FUN_00ba9610(gravity);
            float segmentRoll = material->orientation->FUN_00bc22d0(position);
            float segmentPitch = material->orientation->FUN_00bc22d0(position);
            entry->matrix.FUN_00ba97a0(segmentPitch, segmentRoll);
            entry->direction = DAT_01068b44.RotateBy(entry->matrix);
            entry->position = previous ? previous->position + previous->direction * radius : origin;
            float segmentWeight = weight;
            if (level <= DAT_01068b34)
            {
                entry->weight = BaseWeight(level, position, segmentVariation);
                segmentWeight = entry->weight;
            }
            else if (DAT_011782c0)
            {
                entry->weight = BlendWeight(weight, segmentVariation);
                segmentWeight = entry->weight;
            }
            if (!animation)
            {
                float currentFactor = 0.0f;
                if (level == 0)
                {
                    float along = position;
                    if (material->lower > along)
                        currentFactor = 1.0f;
                    else
                        currentFactor = material->lower * -1.0 / (1.0 - material->lower);
                }
                else
                    currentFactor = parentFactor;
                FUN_00baa6d0(entry, position, currentFactor, type, mesh, shape, segmentWeight, id, step, level);
            }
            else
                DAT_011782bc->FUN_00bb71d0(entry->position, entry->matrix, segmentWeight, id);
            previous = entry;
            distance += radius;
            entries[segment].distance = distance;
        }
        if (animation)
            DAT_011782bc->FUN_00bb4860(bend);
        else
        {
            mesh->SetVertices((unsigned short)firstVertex);
            FUN_00ba9fe0(mesh, type);
        }
    }
        int childCount = (int)(material->children / scale * angle);
        level++;
        bool last = level >= (int)DAT_011782d4.size() - 1;
        if (!last || DAT_01068b30)
        {
            for (int child = 0; child < childCount; child++)
            {
                BranchChild entryChild;
                entryChild.idx = 0;
                entryChild.t = 0.0f;
                entryChild.object = 0;
                if (!last)
                {
                    seed += 3;
                    DAT_011782c1.FUN_00bc4b70(seed);
                }
                float offset = 0.0f;
                if (!last && child == 0)
                {
                    offset = DAT_011782c1.FUN_00bc4b40(BranchInterpolate(material->lower, material->upper, 0.85f),
                                                       BranchInterpolate(material->lower, material->upper, 0.95f));
                }
                else
                    offset = DAT_011782c1.FUN_00bc4b40(material->lower, material->upper);
                FUN_00ba9f60(&entryChild, offset * angle);
                int index = entryChild.idx;
                float childWeight = weight;
                if (level - 1 == DAT_01068b34 || DAT_011782c0)
                {
                    childWeight = BranchInterpolate(entries[index].weight, entries[index + 1].weight,
                                                    entryChild.t);
                }
                if (!last)
                {
                    DAT_011782c1.FUN_00bc4b70(seed);
                    DAT_011782c1.FUN_00bc4b40(0.0f, 100.0f);
                }
                BranchPoint childOrigin;
                BranchEntry* segmentStart = &entries[index];
                InterpolatePoint(&childOrigin, &segmentStart->position, &segmentStart[1].position,
                                 entryChild.t);
                float childAge = 1.0f;
                if (material->upper != material->lower)
                    childAge = (offset - material->lower) / (material->upper - material->lower);
                if (last)
                {
                    FUN_00bac830(this, scale, level, &childOrigin, childAge, &entries[index].matrix,
                                 &entries[index], context, childWeight, id);
                }
                else
                {
                    float childCap = BranchInterpolate(entries[index].radius,
                                                       entries[index + 1].radius, entryChild.t);
                    BranchNode* node = new BranchNode(this);
                    entryChild.object = node;
                    float childFactor = parentFactor + (1.0f - parentFactor) * childAge;
                    if (level <= 1)
                        childFactor *= childFactor;
                    node->FUN_00bacd10(seed, scale, level, childOrigin, childAge, childFactor,
                                                    entries[index].matrix, entries[index].direction,
                                                    mesh, context, childWeight, id, childCap);
                    if (!DAT_011782bc->FUN_00bb45c0() || level < DAT_011782bc->FUN_00896c70())
                        childList.push_back(entryChild);
                    else
                    {
                        delete node;
                        entryChild.object = 0;
                    }
                }
            }
        }
        if (last)
            DAT_011782f4.clear();
        FUN_00ba9ed0();
}

}

// @f3 0x00ba34f0 (community match, verified in this file)
namespace f3m_00ba34f0 {
struct FUN_00ba34f0_Result {
    int unk00;
    int unk04;
};

struct FUN_00ba34f0_Range {
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_00ba2e10(
        FUN_00ba34f0_Result* first,
        FUN_00ba34f0_Range* second,
        int third,
        FUN_00ba34f0_Range* fourth,
        int fifth);
};

struct FUN_00ba34f0_Data {
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
};

void __cdecl FUN_00c01e8b();

class FUN_00ba34f0_Owner {
public:
    int unk00;
    FUN_00ba34f0_Data* unk04;

    void __thiscall FUN_00ba34f0();
};

// pdb: CSpeedTreeRT::FreeBranchColors | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void __thiscall FUN_00ba34f0_Owner::FUN_00ba34f0()
{
    FUN_00ba34f0_Data* data = unk04;

    if (data != 0) {
        FUN_00ba34f0_Range* range =
            (FUN_00ba34f0_Range*)((unsigned char*)data + 0x58);

        unsigned int end = (unsigned int)range->unk08;

        if ((unsigned int)range->unk04 > end) {
            FUN_00c01e8b();
        }

        unsigned int begin = (unsigned int)range->unk04;

        if (begin > (unsigned int)range->unk08) {
            FUN_00c01e8b();
        }

        FUN_00ba34f0_Result result;
        range->FUN_00ba2e10(&result, range, (int)begin, range, (int)end);
    }
}
}   // namespace f3m_00ba34f0

// @f3 0x00baf660 (community match, verified in this file)
namespace f3m_00baf660 {
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void __cdecl FUN_00c01e8b();

struct FUN_00baf660_Obj {
    unsigned int unk00;
    unsigned short* unk04;
    unsigned short* unk08;
    void FUN_00baf660();
};

void FUN_00baf660_Obj::FUN_00baf660() {
    unsigned short* oldEnd = unk08;
    if (unk04 > oldEnd) FUN_00c01e8b();
    unsigned short* cur = unk04;
    if (cur > unk08) FUN_00c01e8b();
    if (cur != oldEnd) {
        int n = unk08 - oldEnd;
        unsigned short* newEnd = cur + n;
        if (n > 0) memmove_s(cur, n * 2, oldEnd, n * 2);
        unk08 = newEnd;
    }
}
}   // namespace f3m_00baf660

// @f3 0x00bb2c70 (community match, verified in this file)
namespace f3m_00bb2c70 {
struct FUN_00bb2c70
{
    unsigned char unk00;
    unsigned char unk01;
    int unk04;
    unsigned short unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1C;
    int unk20;
    int unk24;
    unsigned short unk28;
    int unk2C;
    FUN_00bb2c70(int value);
};

// pdb: CLeafGeometry::CLeafGeometry | LeafGeometry.obj | fnv360_0822_retail, objrun_open, low
// pdb params: pWindEngine
FUN_00bb2c70::FUN_00bb2c70(int value)
{
    unk00 = 0;
    unk01 = 0;
    unk04 = value;
    unk08 = 3;
    unk0C = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    unk1C = 0;
    unk20 = 0;
    unk24 = 0;
    unk28 = 0;
    unk2C = 0;
}
}   // namespace f3m_00bb2c70

// @f3 0x00bb52b0 (community match, verified in this file)
namespace f3m_00bb52b0 {
void FUN_00bb52b0(f3m_00bbe9c0::f3m_00bbe9c0::Triple* first, f3m_00bbe9c0::f3m_00bbe9c0::Triple* last, const f3m_00bbe9c0::f3m_00bbe9c0::Triple& value)
{
    for (; first != last; ++first)
        *first = value;
}
}   // namespace f3m_00bb52b0

// @f3 0x00bb2ce0 (community match, verified in this file)
#include <string.h>
namespace f3m_00bb2ce0 {

class FNV_Bb2ce0_Obj {
public:
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    int unk0C;
    int* holder;
    int unk14;
    char* unk18;
    unsigned short unk1C;

    int FUN_00bb2ce0(int* out);
};

// pdb: CLeafGeometry::GetLeafBillboardTable | LeafGeometry.obj | fnv360_0721_beta, objrun, medium
// pdb params: nEntryCount
int FNV_Bb2ce0_Obj::FUN_00bb2ce0(int* out)
{
    int count = (unk1C * unk08) << 5;
    char* begin = unk18;
    if (begin != 0 && holder != 0 && *holder != 0 && unk18 != 0) {
        memmove(begin, (void*)*holder, count * 4);
        *out = (count * 4 - (int)unk18 + (int)begin) >> 2;
    }
    return (int)unk18;
}
}   // namespace f3m_00bb2ce0

// @f3 0x00bb6be0 (community match, verified in this file)
namespace f3m_00bb6be0 {
struct FUN_00bb6160_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void __thiscall FUN_00bb6160(unsigned int value);
};

void __cdecl FUN_00bb6be0(FUN_00bb6160_Obj* first, FUN_00bb6160_Obj* last, unsigned int value)
{
    FUN_00bb6160_Obj* current = first;
    while (current != last) {
        current->FUN_00bb6160(value);
        ++current;
    }
}
}   // namespace f3m_00bb6be0

// @f3 0x00bb2f30 (community match, verified in this file)
extern float DAT_00db38b8;
namespace f3m_00bb2f30 {
bool __cdecl FUN_00ba1920();

struct Ow00bb2f30
{
    int unk00, unk04, unk08, unk0C, unk10;
    float* unk14;
    void FUN_00bb2f30(int idx, const float* src);
};

// pdb: CLeafGeometry::SetTextureCoords | LeafGeometry.obj | fnv360_0822_retail, callee_sim, low
// pdb params: nLeafMapIndex, pTexCoords
void Ow00bb2f30::FUN_00bb2f30(int idx, const float* src)
{
    if (unk14 == 0) return;
    if (src == 0) return;
    float s = FUN_00ba1920() ? DAT_00db38b8 : 1.0f;
    int off = idx << 6;
    float* p = (float*)((char*)unk14 + off);
    *p++ = src[0];
    *p++ = src[1] * s;
    *p++ = src[2];
    *p++ = src[3] * s;
    *p++ = src[4];
    *p++ = src[5] * s;
    *p++ = src[6];
    *p = s * src[7];
    p = (float*)((char*)unk14 + off + 0x20);
    *p++ = src[2];
    *p++ = src[1] * s;
    *p++ = src[0];
    *p++ = src[3] * s;
    *p++ = src[6];
    *p++ = src[5] * s;
    *p++ = src[4];
    *p = s * src[7];
}
}   // namespace f3m_00bb2f30

// @f3 0x00bb5070 (community match, verified in this file)
#include <string.h>
namespace f3m_00bb5070 {
namespace f3m_00bb5070 {
struct Values { float values[8]; };
struct Output {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short unk20, written;
    unsigned short FUN_00ba1a50();
    void FUN_00bb0d80(void* context, Values* values);
};
// pdb: CFrondEngine::SetTextureCoords | FrondEngine.obj | fnv360_0822_retail, callee_sim, low
// pdb params: pGeometry, nFrondMapIndex, pTexCoords, bFlip
void __stdcall FUN_00bb5070(Output* output, void* context, const Values* source, bool flip) {
    Values values = *source;
    if (flip) {
        for (int i = 1; i < 8; i += 2) values.values[i] = -values.values[i];
    }
    output->written = 0;
    for (int i = 0; i < output->FUN_00ba1a50(); ++i) {
        output->FUN_00bb0d80(context, &values);
        ++output->written;
    }
}
}
}   // namespace f3m_00bb5070

// @f3 0x00bb2ba0 (community match, verified in this file)
namespace f3m_00bb2ba0 {
class FUN_00bb2ba0_Obj {
public:
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
    char unk3C;
    int unk40;

    int FUN_00bb2ba0();
};

void __cdecl FUN_00ba11c0();

int FUN_00bb2ba0_Obj::FUN_00bb2ba0() {
    FUN_00ba11c0();
    unk3C = 0;
    unk40 = 0;
    return reinterpret_cast<int>(this);
}
}   // namespace f3m_00bb2ba0

// @f3 0x00ba1440 (community match, verified in this file)
namespace f3m_00ba1440 {
class FUN_00ba1440_Obj {
public:
    void* unk00;
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
    void* unk34;

    float __thiscall CSpeedTreeRT_GetLodLevel();
};

// pdb: CSpeedTreeRT::GetLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
float FUN_00ba1440_Obj::CSpeedTreeRT_GetLodLevel()
{
    float result;

    if (unk34 != 0)
        result = *(float*)((char*)unk34 + 0x10);
    else
        result = *(float*)((char*)unk00 + 0x14);

    return result;
}
}   // namespace f3m_00ba1440

// @f3 0x00ba7470 (community match, verified in this file)
namespace f3m_00ba7470 {
void __cdecl FUN_00c01e8b();

struct Elem28 {
    int v[7];
};

struct VecBA7470;

struct Iter28 {
    VecBA7470* cont;
    Elem28* ptr;

    Iter28() {}
    inline Iter28(Elem28* p, VecBA7470* c);
    inline Iter28& operator+=(int off);
    Iter28 operator+(int off) const
    {
        Iter28 tmp = *this;
        return tmp += off;
    }
    int operator-(const Iter28& right) const
    {
        if (cont == 0 || cont != right.cont)
            FUN_00c01e8b();
        return ptr - right.ptr;
    }
};

struct VecBA7470 {
    int alloc;
    Elem28* first;
    Elem28* last;
    Elem28* end;

    unsigned int size() const { return first == 0 ? 0 : last - first; }
    Iter28 begin() { return Iter28(first, this); }
    void FUN_00ba57f0(Iter28 where, unsigned int count, const Elem28& value);
    Iter28 FUN_00ba7470(Iter28 where, const Elem28& value);
};

Iter28::Iter28(Elem28* p, VecBA7470* c)
{
    if (!(c == 0 || (c->first <= p && p <= c->last)))
        FUN_00c01e8b();
    cont = c;
    ptr = p;
}

Iter28& Iter28::operator+=(int off)
{
    if (!(ptr + off <= cont->last && ptr + off >= cont->first))
        FUN_00c01e8b();
    ptr += off;
    return *this;
}

Iter28 VecBA7470::FUN_00ba7470(Iter28 where, const Elem28& value)
{
    unsigned int off = size() == 0 ? 0 : where - begin();
    FUN_00ba57f0(where, 1, value);
    return begin() + off;
}
}   // namespace f3m_00ba7470

// @f3 0x00ba16a0 (community match, verified in this file)
namespace f3m_00ba16a0 {

struct MemoryManager {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* memory);
};
extern MemoryManager DAT_01090a78;

struct Child {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
    static void operator delete(void* memory) { DAT_01090a78.FUN_0086ba60(memory); }
    Child();
    void FUN_00bc08b0(int value);
};

struct Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c;
    Child* child;
    void FUN_00ba16a0(int value);
};

// pdb: CSpeedTreeRT::ParseShadowProjectionInfo | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: pFile
void Owner::FUN_00ba16a0(int value)
{
    child = new Child;
    child->FUN_00bc08b0(value);
}

}

// @f3 0x00baf5d0 (community match, verified in this file)
#include <string.h>
namespace f3m_00baf5d0 {

unsigned short* __cdecl FUN_00baf5d0(unsigned short* first, unsigned short* last, unsigned short* dest)
{
    int off = last - first;
    unsigned short* result = dest - off;
    if (off > 0)
        memmove_s(result, off * sizeof(*first), first, off * sizeof(*first));
    return result;
}
}   // namespace f3m_00baf5d0

// @f3 0x00ba32c0 (community match, verified in this file)
namespace f3m_00ba32c0 {
namespace f3m_00ba32c0 {

struct Elem28 { int v[7]; };
struct Alloc { };
struct NonscalarTag { };
struct RangeCheckedTag { };

void __cdecl FUN_00ba2de0(Elem28* first, unsigned int count, const Elem28& value, Alloc& al, NonscalarTag, RangeCheckedTag);

inline NonscalarTag PtrCat(Elem28*, Elem28*) { NonscalarTag cat; return cat; }

inline void UncheckedFill(Elem28* first, unsigned int count, const Elem28& value, Alloc& al)
{
    FUN_00ba2de0(first, count, value, al, PtrCat(first, first), RangeCheckedTag());
}

struct Vec : Alloc {
    Elem28* FUN_00ba32c0(Elem28* ptr, unsigned int count, const Elem28& value);
};

Elem28* Vec::FUN_00ba32c0(Elem28* ptr, unsigned int count, const Elem28& value)
{
    UncheckedFill(ptr, count, value, *this);
    return ptr + count;
}

}
}   // namespace f3m_00ba32c0

// @f3 0x00bb4600 (community match, verified in this file)
namespace f3m_00bb4600 {
namespace f3m_00bb4600 {

struct P56 { int v[14]; };

struct Vec56 {
    int alloc;
    P56* first;
    P56* last;
    P56* end;
    unsigned int FUN_00bb4600();
};

unsigned int Vec56::FUN_00bb4600()
{
    return first == 0 ? 0 : last - first;
}

}
}   // namespace f3m_00bb4600

// @f3 0x00ba7350 (community match, verified in this file)
namespace f3m_00ba7350 {
void __cdecl FUN_00c01e8b();

struct Elem1 {
    char c;
};

struct VecBA7350;

struct Iter1 {
    VecBA7350* cont;
    Elem1* ptr;

    Iter1() {}
    inline Iter1(Elem1* p, VecBA7350* c);
    inline Iter1& operator+=(int off);
    Iter1 operator+(int off) const
    {
        Iter1 tmp = *this;
        return tmp += off;
    }
    int operator-(const Iter1& right) const
    {
        if (cont == 0 || cont != right.cont)
            FUN_00c01e8b();
        return ptr - right.ptr;
    }
};

struct VecBA7350 {
    int alloc;
    Elem1* first;
    Elem1* last;
    Elem1* end;

    unsigned int size() const { return first == 0 ? 0 : last - first; }
    Iter1 begin() { return Iter1(first, this); }
    void FUN_00bde000(Iter1 where, unsigned int count, const Elem1& value);
    Iter1 FUN_00ba7350(Iter1 where, const Elem1& value);
};

Iter1::Iter1(Elem1* p, VecBA7350* c)
{
    if (!(c == 0 || (c->first <= p && p <= c->last)))
        FUN_00c01e8b();
    cont = c;
    ptr = p;
}

Iter1& Iter1::operator+=(int off)
{
    if (!(ptr + off <= cont->last && ptr + off >= cont->first))
        FUN_00c01e8b();
    ptr += off;
    return *this;
}

Iter1 VecBA7350::FUN_00ba7350(Iter1 where, const Elem1& value)
{
    unsigned int off = size() == 0 ? 0 : where - begin();
    FUN_00bde000(where, 1, value);
    return begin() + off;
}
}   // namespace f3m_00ba7350

// @f3 0x00bb55c0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb55c0 {
namespace f3m_00bb55c0 {
struct Elem { int a, b; };
struct V : std::vector<Elem> {
    void FUN_00bb55c0();
};
// pdb: std::vector<SFrondVertex,std::allocator<SFrondVertex> >::vector<SFrondVertex,std::allocator<SFrondVertex> > | FrondEngine.obj | fnv360_0822_retail, objrun_open, low
// pdb params: _Right
void V::FUN_00bb55c0()
{
    erase(begin(), end());
}
}
}   // namespace f3m_00bb55c0

// @f3 0x00ba1ab0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba1ab0 {
namespace f3m_00ba1ab0 {
struct Reader {
    unsigned int offset;
    std::vector<char> data;
    bool FUN_00ba1ab0();
};
// pdb: CTreeEngine::SetBranchLevelForWeighting | SpeedTreeRT.obj | fnv360_0822_debug, call_gap, low
// pdb params: nLevel
bool Reader::FUN_00ba1ab0()
{
    return offset >= data.size();
}
}
}   // namespace f3m_00ba1ab0

// @f3 0x00bb0c90 (community match, verified in this file)
namespace f3m_00bb0c90 {
namespace f3m_00bb0c90 {
struct Info { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24; unsigned char base; unsigned char unk29, unk2a, unk2b; unsigned int count; };
struct FloatTrack { int unk00, unk04, unk08, unk0c; void FUN_0058da30(const float& value); };
struct ByteTrack { void FUN_00ba80d0(const unsigned char& value); };
struct Obj {
    void* vtable;
    Info* info;
    int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4;
    FloatTrack weight;
    ByteTrack frame;
    void FUN_00bb0c90(float t, unsigned char index);
};
// pdb: CIndexedGeometry::AddVertexWind | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: fWindWeight, ucWindMatrixIndex
void Obj::FUN_00bb0c90(float t, unsigned char index)
{
    index = (unsigned char)(index % info->count + info->base);
    weight.FUN_0058da30(1.0f - t);
    frame.FUN_00ba80d0(index);
}
}
}   // namespace f3m_00bb0c90

// @f3 0x00baabd0 (community match, verified in this file)
namespace f3m_00baabd0 {
void FUN_00baa3e0(SortedEntry_aab70** first, int hole, int top, SortedEntry_aab70* value, PriorityGreater_aab70 pred);

// pdb: std::_Adjust_heap<CIdvBranch * *,int,CIdvBranch *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: _First, _Hole, _Bottom, _Val, _Pred
void FUN_00baabd0(SortedEntry_aab70** first, int hole, int bottom, SortedEntry_aab70* value, PriorityGreater_aab70 pred)
{
    int top = hole;
    int idx = 2 * hole + 2;
    for (; idx < bottom; idx = 2 * idx + 2)
    {
        if (pred(first[idx], first[idx - 1]))
            --idx;
        first[hole] = first[idx];
        hole = idx;
    }
    if (idx == bottom)
    {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00baa3e0(first, hole, top, value, pred);
}
}   // namespace f3m_00baabd0

// @f3 0x00baec30 (community match, verified in this file)
#include <new>
namespace f3m_00baec30 {
namespace f3m_00baec30 {
struct Elem16 { int a, b, c, d; };
// pdb: std::allocator<std::vector<SFrondGuide,std::allocator<SFrondGuide> > >::allocate | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Count
Elem16* __cdecl FUN_00baec30(unsigned int count, Elem16*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(Elem16))
        throw std::bad_alloc(0);
    return (Elem16*)::operator new(count * sizeof(Elem16));
}
}
}   // namespace f3m_00baec30

// @f3 0x00baa2c0 (community match, verified in this file)
namespace f3m_00baa2c0 {
namespace f3m_00baa2c0 {

struct P12 { int a, b, c; };

struct Vec12 {
    int alloc;
    P12* first;
    P12* last;
    P12* end;
    unsigned int FUN_00baa2c0();
};

// pdb: std::vector<FR2Vect3TC<float>,std::allocator<FR2Vect3TC<float> > >::size | BSFaceGenModel.obj | fnv360_0822_debug, call_gap, low
unsigned int Vec12::FUN_00baa2c0()
{
    return first == 0 ? 0 : last - first;
}

}
}   // namespace f3m_00baa2c0

// @f3 0x00bb64a0 (community match, verified in this file)
namespace f3m_00bb64a0 {
namespace f3m_00bb64a0 {
struct Elem44 { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28; };
struct RandomTag { };
struct NonscalarTag { };
struct RangeCheckedTag { };
inline RandomTag IterRandom(Elem44*, Elem44*) { RandomTag cat; return cat; }
void __cdecl FUN_00bb5f90(Elem44* first, Elem44* last, Elem44* dest, RandomTag, NonscalarTag, RangeCheckedTag);
// pdb: SFrondGuide::SFrondGuide | FrondEngine.obj | fnv360_1110_retail, objrun_open, low
// pdb params: __that
Elem44* __cdecl FUN_00bb64a0(Elem44* first, Elem44* last, Elem44* dest)
{
    FUN_00bb5f90(first, last, dest, IterRandom(first, dest), NonscalarTag(), RangeCheckedTag());
    return dest - (last - first);
}
}
}   // namespace f3m_00bb64a0

// @f3 0x00bb6b60 (community match, verified in this file)
namespace f3m_00bb6b60 {
namespace f3m_00bb6b60 {
struct Elem { int a, b; };
struct Alloc { };
struct NonscalarTag { };
void __cdecl FUN_00bb5cd0(Elem* first, Elem* last, Alloc& al, NonscalarTag);
inline NonscalarTag PtrCat(Elem*, Elem*) { NonscalarTag cat; return cat; }
struct Vec : Alloc {
    void FUN_00bb6b60(Elem* first, Elem* last);
};
void Vec::FUN_00bb6b60(Elem* first, Elem* last)
{
    FUN_00bb5cd0(first, last, *this, PtrCat(first, last));
}
}
}   // namespace f3m_00bb6b60

// @f3 0x00bb6c10 (community match, verified in this file)
namespace f3m_00bb6c10 {
namespace f3m_00bb6c10 {
struct Elem48 { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c; };
struct RandomTag { };
struct NonscalarTag { };
struct RangeCheckedTag { };
inline RandomTag IterRandom(Elem48*, Elem48*) { RandomTag cat; return cat; }
void __cdecl FUN_00bb6430(Elem48* first, Elem48* last, Elem48* dest, RandomTag, NonscalarTag, RangeCheckedTag);
// pdb: std::_Move<SFrondGuide *,SFrondGuide *> | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Last, _Dest, __formal
Elem48* __cdecl FUN_00bb6c10(Elem48* first, Elem48* last, Elem48* dest)
{
    FUN_00bb6430(first, last, dest, IterRandom(first, dest), NonscalarTag(), RangeCheckedTag());
    return dest + (last - first);
}
}
}   // namespace f3m_00bb6c10

// @f3 0x00ba1380 (community match, verified in this file)
namespace f3m_00ba1380 {
namespace f3m_00ba1380 {
struct Impl { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; float value; };
struct Handle {
    Impl* impl;
    void FUN_00ba1380(float value);
};
// pdb: CSpeedTreeRT::SetBranchDimmingScalar | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: afBranchDimmingScalar
void Handle::FUN_00ba1380(float value)
{
    if (impl)
        impl->value = value;
}
}
}   // namespace f3m_00ba1380

// @f3 0x00bbdd00 (community match, verified in this file)
namespace f3m_00bbdd00 {
class StringSlot00bbdd00
{
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
    void FUN_00bbdd00();
};
void StringSlot00bbdd00::FUN_00bbdd00()
{
    if (16 <= m_uiRes)
        ::operator delete(m_kBx.m_pcPtr);
    m_uiRes = 15;
    m_uiSize = 0;
    m_kBx.m_acBuf[0] = 0;
}
}   // namespace f3m_00bbdd00

// @f3 0x00ba33f0 (community match, verified in this file)
namespace f3m_00ba33f0 {
namespace f3m_00ba33f0 {
struct Elem { int a, b; };
struct Alloc { };
struct NonscalarTag { };
struct RangeCheckedTag { };
Elem* __cdecl FUN_00ba2910(Elem* first, Elem* last, Elem* dest, Alloc& al, NonscalarTag, RangeCheckedTag);
inline NonscalarTag PtrCat(Elem*, Elem*) { NonscalarTag cat; return cat; }
struct Vec : Alloc {
    Elem* FUN_00ba33f0(Elem* first, Elem* last, Elem* dest);
};
Elem* Vec::FUN_00ba33f0(Elem* first, Elem* last, Elem* dest)
{
    return FUN_00ba2910(first, last, dest, *this, PtrCat(first, dest), RangeCheckedTag());
}
}
}   // namespace f3m_00ba33f0

// @f3 0x00bb4690 (community match, verified in this file)
#include <new>
namespace f3m_00bb4690 {
namespace f3m_00bb4690 {
struct Elem24 { int a, b, c, d, e, f; };
// pdb: std::allocator<SIdvBranchFlare>::allocate | Branch.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Count
Elem24* __cdecl FUN_00bb4690(unsigned int count, Elem24*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(Elem24))
        throw std::bad_alloc(0);
    return (Elem24*)::operator new(count * sizeof(Elem24));
}
}
}   // namespace f3m_00bb4690

// @f3 0x00ba3d50 (community match, verified in this file)
#include <string.h>
extern Log4820 DAT_01068a70;
namespace f3m_00ba3d50 {

struct Log4820 { void FUN_0042f100(const char*, int); };

// pdb: CLeafGeometry::Invalidate | LeafGeometry.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void FUN_00ba3d50(const char* p) {
    DAT_01068a70.FUN_0042f100(p, (int)strlen(p));
}
}   // namespace f3m_00ba3d50

// @f3 0x00bb0a40 (community match, verified in this file)
namespace f3m_00bb0a40 {
namespace f3m_00bb0a40 {
struct Vec3 { float x, y, z; };
struct FloatTrack { void FUN_0058da30(const float& value); };
struct Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84;
    FloatTrack track;
    void FUN_00bb0a40(const Vec3& v);
};
// pdb: CIndexedGeometry::AddVertexNormal | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: pNormal
void Obj::FUN_00bb0a40(const Vec3& v)
{
    track.FUN_0058da30(v.x);
    track.FUN_0058da30(v.y);
    track.FUN_0058da30(v.z);
}
}
}   // namespace f3m_00bb0a40

// @f3 0x00ba1ec0 (community match, verified in this file)
namespace f3m_00ba1ec0 {
namespace f3m_00ba1ec0 {
struct Tree { int unk00, unk04, unk08, unk0c, unk10; float distance; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; unsigned short levels; };
struct Branch { int unk00, unk04, unk08, unk0c; float distance; };
struct Obj {
    Tree* tree; void* data;
    int unk08, unk0c, unk10, unk14, unk18; float a, b, c, d; int unk2c, unk30; Branch* branch;
    unsigned short FUN_00ba1ec0(float t);
};
// pdb: CSpeedTreeRT::GetDiscreteBranchLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
// pdb params: fLodLevel
unsigned short Obj::FUN_00ba1ec0(float t)
{
    if (t == -1.0f) {
        float d = branch ? branch->distance : tree->distance;
        t = d;
    }
    int levels = tree->levels;
    short index = (short)((1.0f - t) * levels);
    if (index == levels)
        index--;
    return (unsigned short)index;
}
}
}   // namespace f3m_00ba1ec0

// @f3 0x00bb0d30 (community match, verified in this file)
namespace f3m_00bb0d30 {
namespace f3m_00bb0d30 {
struct Vec3 { float x, y, z; Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
struct FloatTrack { void FUN_0058da30(const float& value); };
struct Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94;
    FloatTrack track;
    void FUN_00bb0d30(const Vec3& v);
};
// pdb: CIndexedGeometry::AddVertexBinormal | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: pBinormal
void Obj::FUN_00bb0d30(const Vec3& v)
{
    Vec3 copy(v);
    track.FUN_0058da30(copy.x);
    track.FUN_0058da30(copy.y);
    track.FUN_0058da30(copy.z);
}
}
}   // namespace f3m_00bb0d30

// @f3 0x00bb8e50 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb8e50 {

namespace f3m_00bb8e50 {
struct Elem { int v[11]; };   // 0x2c bytes
}

f3m_00bb8e50::Elem* __cdecl FUN_00bb8e50(f3m_00bb8e50::Elem* first, f3m_00bb8e50::Elem* last, f3m_00bb8e50::Elem* dest)
{
    return std::copy_backward(first, last, dest);
}
}   // namespace f3m_00bb8e50

// @f3 0x00ba2f70 (community match, verified in this file)
#include <algorithm>
namespace f3m_00ba2f70 {

namespace f3m_00ba2f70 {
struct Elem { int v[7]; };   // 0x1c bytes
}

f3m_00ba2f70::Elem* __cdecl FUN_00ba2f70(f3m_00ba2f70::Elem* first, f3m_00ba2f70::Elem* last, f3m_00ba2f70::Elem* dest)
{
    return std::copy_backward(first, last, dest);
}
}   // namespace f3m_00ba2f70

// @f3 0x00bb53e0 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb53e0 {

namespace f3m_00bb53e0 {
struct Elem { int v[14]; };   // 0x38 bytes
}

f3m_00bb53e0::Elem* __cdecl FUN_00bb53e0(f3m_00bb53e0::Elem* first, f3m_00bb53e0::Elem* last, f3m_00bb53e0::Elem* dest)
{
    return std::copy_backward(first, last, dest);
}
}   // namespace f3m_00bb53e0

// @f3 0x00bb9580 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb9580 {

namespace f3m_00bb9580 {
struct Elem { int v[12]; };   // 0x30 bytes
}

f3m_00bb9580::Elem* __cdecl FUN_00bb9580(f3m_00bb9580::Elem* first, f3m_00bb9580::Elem* last, f3m_00bb9580::Elem* dest)
{
    return std::copy_backward(first, last, dest);
}
}   // namespace f3m_00bb9580

// @f3 0x00bab390 (community match, verified in this file)
namespace f3m_00bab390 {
namespace f3m_00bab390 {
struct Elem { int a, b; };
struct Alloc { };
struct NonscalarTag { };
struct RangeCheckedTag { };
Elem* __cdecl FUN_00bdff70(Elem* first, Elem* last, Elem* dest, Alloc& al, NonscalarTag, RangeCheckedTag);
inline NonscalarTag PtrCat(Elem*, Elem*) { NonscalarTag cat; return cat; }
struct Vec : Alloc {
    Elem* FUN_00bab390(Elem* first, Elem* last, Elem* dest);
};
Elem* Vec::FUN_00bab390(Elem* first, Elem* last, Elem* dest)
{
    return FUN_00bdff70(first, last, dest, *this, PtrCat(first, dest), RangeCheckedTag());
}
}
}   // namespace f3m_00bab390

// @f3 0x00bb8df0 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb8df0 {

namespace f3m_00bb8df0 {
struct Elem { int v[12]; };   // 0x30 bytes
}

f3m_00bb8df0::Elem* __cdecl FUN_00bb8df0(f3m_00bb8df0::Elem* first, f3m_00bb8df0::Elem* last, f3m_00bb8df0::Elem* dest)
{
    return std::_Copy_opt(std::_Checked_base(first), std::_Checked_base(last), dest, std::_Iter_random(first, last), std::_Ptr_cat(first, last), std::_Range_checked_iterator_tag());
}
}   // namespace f3m_00bb8df0

// @f3 0x00bb5350 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb5350 {

namespace f3m_00bb5350 {
struct Elem { int v[14]; };   // 0x38 bytes
}

f3m_00bb5350::Elem* __cdecl FUN_00bb5350(f3m_00bb5350::Elem* first, f3m_00bb5350::Elem* last, f3m_00bb5350::Elem* dest)
{
    return std::_Copy_opt(std::_Checked_base(first), std::_Checked_base(last), dest, std::_Iter_random(first, last), std::_Ptr_cat(first, last), std::_Range_checked_iterator_tag());
}
}   // namespace f3m_00bb5350

// @f3 0x00bbf9e0 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bbf9e0 {

namespace f3m_00bbf9e0 {
struct Elem { int v[21]; };   // 0x54 bytes
}

f3m_00bbf9e0::Elem* __cdecl FUN_00bbf9e0(f3m_00bbf9e0::Elem* first, f3m_00bbf9e0::Elem* last, f3m_00bbf9e0::Elem* dest)
{
    return std::_Copy_opt(std::_Checked_base(first), std::_Checked_base(last), dest, std::_Iter_random(first, last), std::_Ptr_cat(first, last), std::_Range_checked_iterator_tag());
}
}   // namespace f3m_00bbf9e0

// @f3 0x00bbd270 (community match, verified in this file)
namespace f3m_00bbd270 {
namespace f3m_00bbd270 {
class Owner_00bbd270 {
public:
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    int unk14;
    Owner_00bbd270* FUN_00bbd270();
};
// pdb: CVec::CVec | Vec.obj | fnv360_0822_retail, call_seq, low
Owner_00bbd270* Owner_00bbd270::FUN_00bbd270()
{
    *(volatile float*)&unk10 = 0.0f;
    *(volatile int*)&unk14 = 3;
    *(volatile float*)&unk0C = 0.0f;
    unk08 = 0.0f;
    unk04 = 0.0f;
    unk00 = 0.0f;
    return this;
}
}
}   // namespace f3m_00bbd270

// @f3 0x00ba3300 (community match, verified in this file)
#include <string>
namespace f3m_00ba3300 {
namespace f3m_00ba3300 {
struct Str : std::string {
    Str& FUN_00ba3300(const char* ptr, size_type count);
};
Str& Str::FUN_00ba3300(const char* ptr, size_type count)
{
    if (_Inside(ptr))
        return (Str&)append(*this, ptr - _Myptr(), count);
    if (npos - _Mysize <= count || _Mysize + count < _Mysize)
        _Xlen();
    size_type num;
    if (0 < count && _Grow(num = _Mysize + count)) {
        std::_Traits_helper::copy_s<traits_type>(_Myptr() + _Mysize, _Myres - _Mysize, ptr, count);
        _Eos(num);
    }
    return *this;
}
}
}   // namespace f3m_00ba3300

// @f3 0x00baa2e0 (community match, verified in this file)
#include <vector>
namespace f3m_00baa2e0 {

unsigned int& __fastcall FUN_00baa2e0(std::vector<unsigned int>* self, int, unsigned int index)
{
    return (*self)[index];
}
}   // namespace f3m_00baa2e0

// @f3 0x00ba1960 (community match, verified in this file)
namespace f3m_00ba1960 {

struct FUN_00ba1960_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00ba1960_Obj
{
    int unk00;
    FUN_00ba1960_Elem* first;
    FUN_00ba1960_Elem* last;

    int FUN_00ba1960();
};

int FUN_00ba1960_Obj::FUN_00ba1960()
{
    if (!first)
        return 0;
    return (int)(last - first);
}
}   // namespace f3m_00ba1960

// @f3 0x00bb3320 (community match, verified in this file)
namespace f3m_00bb3320 {
void __cdecl FUN_00401010(void* memory);
void __stdcall FUN_00c00799(void* memory, unsigned int size, unsigned int count, void (__cdecl* dtor)(void*));
void __cdecl FUN_00bb2bc0(void* self);

struct FUN_00bb3320_cls
{
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
    unsigned int* unk2c;

    void FUN_00bb3320();
};

// pdb: CLeafGeometry::~CLeafGeometry | LeafGeometry.obj | fnv360_0822_retail, call_gap, low
void FUN_00bb3320_cls::FUN_00bb3320()
{
    FUN_00401010(reinterpret_cast<void*>(unk20));
    FUN_00401010(reinterpret_cast<void*>(unk24));
    if (unk2c)
    {
        unsigned int* block = unk2c - 1;
        FUN_00c00799(unk2c, 0x44, block[0], FUN_00bb2bc0);
        FUN_00401010(block);
    }
    FUN_00401010(reinterpret_cast<void*>(unk18));
    unk0c = 0;
    unk14 = 0;
    unk20 = 0;
    unk24 = 0;
    unk2c = 0;
    unk18 = 0;
}
}   // namespace f3m_00bb3320

// @f3 0x00baf9b0 (community match, verified in this file)
namespace f3m_00baf9b0 {
struct Baf9b0Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    unsigned char __thiscall FUN_00baf9b0(unsigned int count);
};

unsigned int __cdecl FUN_00bc5f00();
int __cdecl FUN_00baec90(unsigned int count, unsigned int base);

unsigned char __thiscall Baf9b0Obj::FUN_00baf9b0(unsigned int count)
{
    this->unk04 = 0;
    this->unk08 = 0;
    this->unk0C = 0;

    if (count == 0)
        return 0;

    unsigned int base = 0;
    if (count > 0x7FFFFFFF)
        base = FUN_00bc5f00();

    int result = FUN_00baec90(count, base);
    this->unk04 = result;
    this->unk08 = result;
    this->unk0C = result + count * 2;

    return 1;
}
}   // namespace f3m_00baf9b0

// @f3 0x00bab240 (community match, verified in this file)
namespace f3m_00bab240 {
void __cdecl FUN_00c01e8b();
struct FUN_00bab240_Pair { unsigned int a; unsigned int b; };
struct FUN_00bab240_Vec {
    unsigned int allocator;
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    void FUN_00bab240();
    FUN_00bab240_Pair FUN_00ba2e10(FUN_00bab240_Vec*, unsigned int*, FUN_00bab240_Vec*, unsigned int*);
};
void FUN_00bab240_Vec::FUN_00bab240() {
    unsigned int* last = _Mylast;
    if (_Myfirst > last) FUN_00c01e8b();
    unsigned int* first = _Myfirst;
    if (first > _Mylast) FUN_00c01e8b();
    FUN_00ba2e10(this, first, this, last);
}
}   // namespace f3m_00bab240

// @f3 0x00ba1dd0 (community match, verified in this file)
namespace f3m_00ba1dd0 {
namespace f3m_00ba1dd0 {
struct State {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024;
    int unk028, unk02c, unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c, unk070, unk074;
    int unk078, unk07c, unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4;
    int unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c, unk110, unk114;
    int unk118, unk11c, unk120;
    void FUN_00ba1dd0();
};
}

// pdb: CSpeedTreeRT::SGeometry::~SGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
void f3m_00ba1dd0::State::FUN_00ba1dd0()
{
    unk11c = 0;
    unk120 = 0;
    unk108 = 0;
    unk10c = 0;
    unk0f4 = 0;
    unk0f8 = 0;
    unk0c4 = 0;
    unk0c8 = 0;
    unk0cc = 0;
    unk0d8 = 0;
    unk0dc = 0;
    unk0e0 = 0;
    unk0e4 = 0;
    unk0d0 = 0;
    unk0d4 = 0;
    unk0e8 = 0;
    unk0ec = 0;
    unk088 = 0;
    unk08c = 0;
    unk090 = 0;
    unk09c = 0;
    unk0a0 = 0;
    unk0a4 = 0;
    unk0a8 = 0;
    unk094 = 0;
    unk098 = 0;
    unk0ac = 0;
    unk0b0 = 0;
    unk050 = 0;
    unk054 = 0;
    unk058 = 0;
    unk05c = 0;
    unk060 = 0;
    unk064 = 0;
    unk068 = 0;
    unk06c = 0;
    unk070 = 0;
    unk044 = 0;
    unk048 = 0;
    unk014 = 0;
    unk018 = 0;
    unk01c = 0;
    unk020 = 0;
    unk024 = 0;
    unk028 = 0;
    unk02c = 0;
    unk030 = 0;
    unk034 = 0;
    unk008 = 0;
    unk00c = 0;
}
}   // namespace f3m_00ba1dd0

// @f3 0x00ba80d0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba80d0 {

namespace f3m_00ba80d0 {
// std::vector<char>::push_back, written out on a derived class (the library body, VC8 release)
struct CharBuffer : std::vector<char> {
    void FUN_00ba80d0(const char& value);
};
}

// pdb: std::vector<unsigned char,std::allocator<unsigned char> >::push_back | FileAccess.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _Val
void f3m_00ba80d0::CharBuffer::FUN_00ba80d0(const char& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00ba80d0

// @f3 0x00bb6c70 (community match, verified in this file)
namespace f3m_00bb6c70 {
namespace f3m_00bb6c70 {
struct Header {
    int unk00, unk04, unk08, unk0c;
    Header& FUN_00bb5d10(const Header& other);   // operator=
    Header& operator=(const Header& other) { return FUN_00bb5d10(other); }
};
struct Elem {
    Header header;
    float f10;
    float f14;
    bool b18;
    float f1c;
    float f20;
    float f24;
    int i28;
    int i2c;
};
}

// pdb: SFrondGuide::operator= | FrondEngine.obj | fnv360_0822_retail, objrun_open, low
// pdb params: __that
void __cdecl FUN_00bb6c70(f3m_00bb6c70::Elem* first, f3m_00bb6c70::Elem* last, const f3m_00bb6c70::Elem& value)
{
    for (; first != last; ++first)
        *first = value;
}
}   // namespace f3m_00bb6c70

// @f3 0x00baee70 (community match, verified in this file)
#include <vector>
namespace f3m_00baee70 {
namespace f3m_00baee70 {
struct Data {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64;
    std::vector<float> vertices;
    float* FUN_00baee70(int index);
};
// pdb: CIndexedGeometry::GetVertexCoord | IndexedGeometry.obj | fnv360_0721_beta, call_gap, low
// pdb params: nVertexIndex
float* Data::FUN_00baee70(int index)
{
    return &vertices[0] + index * 3;
}
}
}   // namespace f3m_00baee70

// @f3 0x00bb3010 (community match, verified in this file)
namespace f3m_00bb3010 {
namespace f3m_00bb3010 {
struct TreeGeometry
{
    bool active;
    float alpha;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};
struct LeafEntry { TreeGeometry geometry; int unk3c, unk40; };
struct TreeEngine
{
    int unk00;
    void* p04;
    int unk08;
    void* p0c;
    void* p10;
    int unk14, unk18, unk1c;
    void* p20;
    void* p24;
    unsigned short count;
    unsigned short unk2a;
    LeafEntry* entries;
    void FUN_00bb3010(TreeGeometry* out, unsigned short index, float a, float b, float c);
};
// pdb: CLeafGeometry::SmallUpdate | LeafGeometry.obj | fnv360_0822_retail, call_dedup, low
// pdb params: sGeometry, usLodLevel, fAzimuth, fPitch, fSizeIncreaseFactor
void TreeEngine::FUN_00bb3010(TreeGeometry* out, unsigned short index, float, float, float)
{
    if (entries && index < count && p10 && p24 && p20 && p04 && p0c) {
        *out = entries[index].geometry;
        out->active = true;
        out->unk08 = index;
    }
}
}
}   // namespace f3m_00bb3010

// @f3 0x00bb5cd0 (community match, verified in this file)
namespace f3m_00bb5cd0 {
void __cdecl FUN_00401010(void* memory);

struct Elem44 {
    int unk00;
    union {
        char* ptr;
        char buf[16];
    };
    int size;
    unsigned int cap;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

void __cdecl FUN_00bb5cd0(Elem44* first, Elem44* last) {
    if (first == last) {
        return;
    }
    do {
        if (first->cap >= 16) {
            FUN_00401010(first->ptr);
        }
        first->cap = 15;
        first->size = 0;
        first->buf[0] = 0;
        first++;
    } while (first != last);
}
}   // namespace f3m_00bb5cd0

// @f3 0x00baf6b0 (community match, verified in this file)
#include <string.h>
namespace f3m_00baf6b0 {
namespace f3m_00baf6b0 {
struct ShortVec {
    unsigned short* FUN_00baf6b0(unsigned short* from, unsigned short* to, unsigned short* dest);
};
unsigned short* ShortVec::FUN_00baf6b0(unsigned short* from, unsigned short* to, unsigned short* dest)
{
    unsigned int count = to - from;
    unsigned short* result = dest + count;
    if (count)
        memmove_s(dest, count * sizeof(*from), from, count * sizeof(*from));
    return result;
}
}
}   // namespace f3m_00baf6b0

// @f3 0x00ba2d60 (community match, verified in this file)
namespace f3m_00ba2d60 {
// pdb: std::vector<unsigned char,std::allocator<unsigned char> >::_Inside | SpeedTreeRT.obj | fnv360_0822_debug, objrun_open, low
// pdb params: _Ptr
void __cdecl FUN_00ba2d60(char* first, char* last, const char* value) {
    if (first != last) {
        do {
            *first = *value;
            ++first;
        } while (first != last);
    }
}
}   // namespace f3m_00ba2d60

// @f3 0x00bb47c0 (community match, verified in this file)
#include <new>
namespace f3m_00bb47c0 {

namespace f3m_00bb47c0 {
struct Elem { int v[11]; };   // 0x2c bytes
}

// std::_Allocate<Elem> (VC8 xmemory body)
f3m_00bb47c0::Elem* __cdecl FUN_00bb47c0(unsigned int count, f3m_00bb47c0::Elem*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(f3m_00bb47c0::Elem))
        throw std::bad_alloc(0);
    return (f3m_00bb47c0::Elem*)::operator new(count * sizeof(f3m_00bb47c0::Elem));
}
}   // namespace f3m_00bb47c0

// @f3 0x00bbd670 (community match, verified in this file)
namespace f3m_00bbd670 {
namespace f3m_00bbd670 {
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int* state;
    int unk28, unk2c, unk30;
    int* value;
    int FUN_00bbd670();
};
}

// pdb: std::_Iterator012<std::bidirectional_iterator_tag,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,int,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > const *,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > const &,std::_Iterator_base12>::_Iterator012<std::bidirectional_iterator_tag,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,int,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > const *,std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > const &,std::_Iterator_base12> | algs.obj | fnv360_1110_debug, objrun_open, low, conflict (skyrim: std::basic_streambuf<char,struct std::char_traits<char> >::pptr)
int f3m_00bbd670::Owner::FUN_00bbd670()
{
    if (*state != 0)
        return *value;
    return 0;
}
}   // namespace f3m_00bbd670

// @f3 0x00baecf0 (community match, verified in this file)
#include <vector>
namespace f3m_00baecf0 {

namespace f3m_00baecf0 {
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    std::vector<std::vector<int> > lists;   // 0x48
    int* FUN_00baecf0(unsigned short index);
};
}

int* f3m_00baecf0::Owner::FUN_00baecf0(unsigned short index)
{
    if (!lists[index].empty())
        return &lists[index][0];
    return 0;
}
}   // namespace f3m_00baecf0

// @f3 0x00baf7a0 (community match, verified in this file)
#include <vector>
namespace f3m_00baf7a0 {

namespace f3m_00baf7a0 {
// std::vector<int>::_Buy (VC8 release)
struct List : std::vector<int> {
    bool FUN_00baf7a0(size_type capacity);
};
}

bool f3m_00baf7a0::List::FUN_00baf7a0(size_type capacity)
{
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
    if (capacity == 0)
        return false;
    else if (max_size() < capacity)
        _Xlen();
    else {
        _Myfirst = this->_Alval.allocate(capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + capacity;
    }
    return true;
}
}   // namespace f3m_00baf7a0

// @f3 0x00ba2940 (community match, verified in this file)
#include <string.h>
namespace f3m_00ba2940 {

int __cdecl FUN_00ba2940(char* first, char* last, char* dest)
{
    int count = (int)(last - first) / 28;
    char* result = dest - count * 28;
    char* src = last;

    if (first != src)
    {
        char* dst = dest;

        do
        {
            src -= 28;
            dst -= 28;
            memcpy(dst, src, 28);
        }
        while (src != first);
    }

    return (int)result;
}
}   // namespace f3m_00ba2940

// @f3 0x00bb5120 (community match, verified in this file)
#include <string.h>
namespace f3m_00bb5120 {

int __cdecl FUN_00bb5120(char* first, char* last, char* dest)
{
    int count = (int)(last - first) / 56;
    char* result = dest - count * 56;
    char* src = last;

    if (first != src)
    {
        char* dst = dest;

        do
        {
            src -= 56;
            dst -= 56;
            memcpy(dst, src, 56);
        }
        while (src != first);
    }

    return (int)result;
}
}   // namespace f3m_00bb5120

// @f3 0x00ba10b0 (community match, verified in this file)
namespace f3m_00ba10b0 {
namespace f3m_00ba10b0 {
struct Vec3 {
    float x, y, z;
    Vec3* FUN_00ba10b0();
};
}

f3m_00ba10b0::Vec3* f3m_00ba10b0::Vec3::FUN_00ba10b0()
{
    x = y = z = 0.0f;
    return this;
}
}   // namespace f3m_00ba10b0

// @f3 0x00ba1100 (community match, verified in this file)
namespace f3m_00ba1100 {
namespace f3m_00ba1100 {
struct Vec3 {
    float x, y, z;
    bool FUN_00ba1100(const Vec3& o) const;
};
}

// pdb: CVec3::operator!= | SpeedTreeRT.obj | fnv360_0822_debug, callee_sim, low
// pdb params: cVec
bool f3m_00ba1100::Vec3::FUN_00ba1100(const Vec3& o) const
{
    return x != o.x || y != o.y || z != o.z;
}
}   // namespace f3m_00ba1100

// @f3 0x00ba11a0 (community match, verified in this file)
namespace f3m_00ba11a0 {
// pdb: VecInterpolate | SpeedTreeRT.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: fStart, fEnd, fPercent
float __cdecl FUN_00ba11a0(float a, float b, float t)
{
    b = a + (b - a) * t;
    return b;
}
}   // namespace f3m_00ba11a0

// @f3 0x00ba11c0 (community match, verified in this file)
namespace f3m_00ba11c0 {
namespace f3m_00ba11c0 {
struct State {
    bool active;
    float value;
    int index;
    unsigned short flags;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    State* FUN_00ba11c0();
};
}

// pdb: CSpeedTreeRT::SGeometry::SLeaf::SLeaf | SpeedTreeRT.obj | fnv360_0822_retail, objrun, medium
f3m_00ba11c0::State* f3m_00ba11c0::State::FUN_00ba11c0()
{
    value = -1.0f;
    active = false;
    index = -1;
    flags = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    unk1c = 0;
    unk20 = 0;
    unk24 = 0;
    unk28 = 0;
    unk2c = 0;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0;
    return this;
}
}   // namespace f3m_00ba11c0

// @f3 0x00ba1230 (community match, verified in this file)
namespace f3m_00ba1230 {
namespace f3m_00ba1230 {
struct Block {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Block* FUN_00ba1230();
};
}

// pdb: CSpeedTreeRT::STextures::STextures | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
f3m_00ba1230::Block* f3m_00ba1230::Block::FUN_00ba1230()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    return this;
}
}   // namespace f3m_00ba1230

// @f3 0x00ba12f0 (community match, verified in this file)
namespace f3m_00ba12f0 {
namespace f3m_00ba12f0 {
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int* value;
    int FUN_00ba12f0();
};
}

// pdb: CSpeedTreeRT::InstanceOf | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
int f3m_00ba12f0::Owner::FUN_00ba12f0()
{
    int* p = value;
    int result = 0;
    if (p)
        result = *p;
    return result;
}
}   // namespace f3m_00ba12f0

// @f3 0x00ba1370 (community match, verified in this file)
namespace f3m_00ba1370 {
namespace f3m_00ba1370 {
struct Target { int unk00, unk04, unk08, unk0c, unk10; char flag; };
struct Owner {
    int unk00, unk04, unk08, unk0c;
    Target* target;
    void FUN_00ba1370(char flag);
};
}

// pdb: CSpeedTreeRT::SetLeafRockingState | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: bFlag
void f3m_00ba1370::Owner::FUN_00ba1370(char flag)
{
    target->flag = flag;
}
}   // namespace f3m_00ba1370

// @f3 0x00ba13a0 (community match, verified in this file)
namespace f3m_00ba13a0 {
namespace f3m_00ba13a0 {
struct Target {
    float& Value() { return *(float*)((char*)this + 0x88); }
};
struct Owner {
    Target* target;
    void FUN_00ba13a0(float value);
};
}

// pdb: CSpeedTreeRT::SetLeafDimmingScalar | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: afLeafDimmingScalar
void f3m_00ba13a0::Owner::FUN_00ba13a0(float value)
{
    if (target)
        target->Value() = value;
}
}   // namespace f3m_00ba13a0

// @f3 0x00ba13c0 (community match, verified in this file)
namespace f3m_00ba13c0 {
namespace f3m_00ba13c0 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    float FUN_00ba13c0();
};
}

// pdb: CSpeedTreeRT::GetTrunkWidth | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
float f3m_00ba13c0::Owner::FUN_00ba13c0()
{
    if (impl) {
        void* sub = At<void*>(impl, 0x5c);
        if (sub)
            return At<float>(sub, 0x18);
    }
    return 0.0f;
}
}   // namespace f3m_00ba13c0

// @f3 0x00ba1400 (community match, verified in this file)
namespace f3m_00ba1400 {
namespace f3m_00ba1400 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    void FUN_00ba1400(float v);
};
}

// pdb: CSpeedTreeRT::SetMinimumBudAngle | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: afAngle
void f3m_00ba1400::Owner::FUN_00ba1400(float v)
{
    if (impl)
        At<float>(impl, 0xb4) = v;
}
}   // namespace f3m_00ba1400

// @f3 0x00ba1420 (community match, verified in this file)
namespace f3m_00ba1420 {
namespace f3m_00ba1420 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    void FUN_00ba1420(float v);
};
}

// pdb: CSpeedTreeRT::SetMaximumBudAngle | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: afAngle
void f3m_00ba1420::Owner::FUN_00ba1420(float v)
{
    if (impl)
        At<float>(impl, 0xb8) = v;
}
}   // namespace f3m_00ba1420

// @f3 0x00ba1470 (community match, verified in this file)
namespace f3m_00ba1470 {
namespace f3m_00ba1470 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    void FUN_00ba1470(float a, float b);
};
}

// pdb: CSpeedTreeRT::SetLodLimits | SpeedTreeRT.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: fNear, fFar
void f3m_00ba1470::Owner::FUN_00ba1470(float a, float b)
{
    impl->FUN_00bbdaf0(a, b);
}
}   // namespace f3m_00ba1470

// @f3 0x00ba14a0 (community match, verified in this file)
namespace f3m_00ba14a0 {
namespace f3m_00ba14a0 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    unsigned short FUN_00ba14a0();
};
}

// pdb: CSpeedTreeRT::GetNumLeafLodLevels | SpeedTreeRT.obj | fnv360_0822_retail, call_dedup, low
unsigned short f3m_00ba14a0::Owner::FUN_00ba14a0()
{
    return At<unsigned short>(impl, 0xc0);
}
}   // namespace f3m_00ba14a0

// @f3 0x00ba14b0 (community match, verified in this file)
namespace f3m_00ba14b0 {
namespace f3m_00ba14b0 {
template <class T> T& At(void* p, int offset) { return *(T*)((char*)p + offset); }
struct Impl {
    void FUN_00bbdaf0(float a, float b);
};
struct Other { void FUN_00bb3070(); };
struct Owner {
    Impl* impl;
    int unk04;
    Impl* other;
    void FUN_00ba14b0();
};
}

// pdb: CSpeedTreeRT::FreeLeafLODDataArrays | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void f3m_00ba14b0::Owner::FUN_00ba14b0()
{
    if (other)
        ((Other*)other)->FUN_00bb3070();
}
}   // namespace f3m_00ba14b0

// @f3 0x00ba1940 (community match, verified in this file)
#include <vector>
namespace f3m_00ba1940 {

namespace f3m_00ba1940 {
struct Elem { int v[21]; };   // 0x54 bytes
struct List : std::vector<Elem> {
    size_type FUN_00ba1940() const;
};
}

f3m_00ba1940::List::size_type f3m_00ba1940::List::FUN_00ba1940() const
{
    return size();
}
}   // namespace f3m_00ba1940

// @f3 0x00ba1a50 (community match, verified in this file)
#include <vector>
namespace f3m_00ba1a50 {

namespace f3m_00ba1a50 {
struct Mesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    std::vector<int> indices;   // 0x68
    unsigned int FUN_00ba1a50() const;
};
}

unsigned int f3m_00ba1a50::Mesh::FUN_00ba1a50() const
{
    return indices.size() / 3;
}
}   // namespace f3m_00ba1a50

// @f3 0x00ba1a80 (community match, verified in this file)
#include <vector>
namespace f3m_00ba1a80 {

namespace f3m_00ba1a80 {
struct Reader {
    unsigned int position;
    std::vector<char> data;   // 0x04
    bool FUN_00ba1a80();
};
}

// pdb: SFrondTexture::~SFrondTexture | FrondEngine.obj | fnv360_0721_beta, callee_sim, low
bool f3m_00ba1a80::Reader::FUN_00ba1a80()
{
    unsigned int i = position++;
    return data[i] != 0;
}
}   // namespace f3m_00ba1a80

// @f3 0x00ba1ba0 (community match, verified in this file)
namespace f3m_00ba1ba0 {
namespace f3m_00ba1ba0 {
struct Row { float x, y, z; };
extern Row DAT_01068f1c[4];   // unit basis
struct Scaled {
    Row m[4];
    bool valid;
    Scaled* FUN_00ba1ba0(float a, float b);
};
}

// pdb: CSimpleBillboard::GetBillboardCoords | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: fWidth, fHeight
f3m_00ba1ba0::Scaled* f3m_00ba1ba0::Scaled::FUN_00ba1ba0(float a, float b)
{
    if (!valid) {
        m[0].x = DAT_01068f1c[0].x * a;
        m[0].y = DAT_01068f1c[0].y * a;
        m[0].z = DAT_01068f1c[0].z * b;
        m[1].x = DAT_01068f1c[1].x * a;
        m[1].y = DAT_01068f1c[1].y * a;
        m[1].z = DAT_01068f1c[1].z * b;
        m[2].x = DAT_01068f1c[2].x * a;
        m[2].y = DAT_01068f1c[2].y * a;
        m[2].z = DAT_01068f1c[2].z * b;
        m[3].x = DAT_01068f1c[3].x * a;
        m[3].y = DAT_01068f1c[3].y * a;
        m[3].z = DAT_01068f1c[3].z * b;
        valid = true;
    }
    return this;
}
}   // namespace f3m_00ba1ba0

// @f3 0x00ba1870 (community match, verified in this file)
namespace f3m_00ba1870 {
namespace f3m_00ba1870 {
struct Point3 { float x, y, z; void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Box { Point3 min, max; };
struct Volume {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    Box* bounds;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    char unk6c;
    bool enabled;
    Point3 corners[4];
    void FUN_00ba1870();
};
}

// pdb: CSpeedTreeRT::SetupHorizontalBillboard | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void f3m_00ba1870::Volume::FUN_00ba1870()
{
    if (enabled) {
        struct { float z; Point3 max; Point3 min; } l;
        l.min.x = bounds->min.x;
        l.min.y = bounds->min.y;
        l.min.z = bounds->min.z;
        l.max.x = bounds->max.x;
        l.max.y = bounds->max.y;
        l.max.z = bounds->max.z;
        l.z = (l.max.z + l.min.z) * 0.5;
        corners[0].Set(l.max.x, l.max.y, l.z);
        corners[1].Set(l.min.x, l.max.y, l.z);
        corners[2].Set(l.min.x, l.min.y, l.z);
        corners[3].Set(l.max.x, l.min.y, l.z);
    }
}
}   // namespace f3m_00ba1870

// @f3 0x00ba2040 (community match, verified in this file)
#include <vector>
namespace f3m_00ba2040 {

namespace f3m_00ba2040 {
struct Elem { int v[7]; };   // 0x1c bytes
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    std::vector<Elem>* list;
    unsigned int FUN_00ba2040() const;
};
}

// pdb: CSpeedTreeRT::GetCollisionObjectCount | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
unsigned int f3m_00ba2040::Owner::FUN_00ba2040() const
{
    std::vector<Elem>* l = list;
    unsigned int n = 0;
    if (l)
        n = l->size();
    return n;
}
}   // namespace f3m_00ba2040

// @f3 0x00ba28e0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba28e0 {

namespace f3m_00ba28e0 {
struct Elem { int v[4]; };
struct List : std::vector<Elem> {
    Elem& FUN_00ba28e0(size_type index);
};
}

// pdb: CIndexedGeometry::GetVertexTexIndices | SpeedTreeRT.obj | fnv360_0822_debug, objrun_open, low
f3m_00ba28e0::Elem& f3m_00ba28e0::List::FUN_00ba28e0(size_type index)
{
    return (*this)[index];
}
}   // namespace f3m_00ba28e0

// @f3 0x00ba2910 (community match, verified in this file)
#include <memory>
namespace f3m_00ba2910 {

namespace f3m_00ba2910 {
struct Elem { int v[7]; };   // 0x1c bytes
}

// std::_Uninit_copy for a trivially copyable 0x1c-byte element (VC8 xmemory body)
f3m_00ba2910::Elem* __cdecl FUN_00ba2910(f3m_00ba2910::Elem* first, f3m_00ba2910::Elem* last, f3m_00ba2910::Elem* dest,
                                         std::allocator<f3m_00ba2910::Elem>& al, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    f3m_00ba2910::Elem* next = dest;
    try {
        for (; first != last; ++dest, ++first)
            al.construct(dest, *first);
    } catch (...) {
        for (; next != dest; ++next)
            al.destroy(next);
        throw;
    }
    return dest;
}
}   // namespace f3m_00ba2910

// @f3 0x00ba2de0 (community match, verified in this file)
#include <memory>
namespace f3m_00ba2de0 {

namespace f3m_00ba2de0 {
struct Elem { int v[7]; };   // 0x1c bytes
}

// std::_Uninit_fill_n for a trivially copyable 0x1c-byte element (VC8 xmemory body)
// pdb: std::vector<SShape,std::allocator<SShape> >::_Inside | SpeedTreeRT.obj | fnv360_0822_debug, callee_sim, low
// pdb params: _Ptr
void __cdecl FUN_00ba2de0(f3m_00ba2de0::Elem* first, unsigned int count, const f3m_00ba2de0::Elem& value,
                          std::allocator<f3m_00ba2de0::Elem>& al, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    f3m_00ba2de0::Elem* next = first;
    try {
        for (; 0 < count; --count, ++first)
            al.construct(first, value);
    } catch (...) {
        for (; next != first; ++next)
            al.destroy(next);
        throw;
    }
}
}   // namespace f3m_00ba2de0

// @f3 0x00ba10c0 (community match, verified in this file)
namespace f3m_00ba10c0 {
namespace f3m_00ba10c0 {
struct Vec3 {
    float x, y, z;
    float FUN_00ba10c0(const Vec3& o) const;
};
}

// approximate distance (sqrt by exponent halving)
float f3m_00ba10c0::Vec3::FUN_00ba10c0(const Vec3& o) const
{
    float d = (o.x - x) * (o.x - x) + (o.y - y) * (o.y - y) + (o.z - z) * (o.z - z);
    int bits = *(int*)&d;
    bits = (bits >> 1) + 0x1fc00000;
    return *(float*)&bits;
}
}   // namespace f3m_00ba10c0

// @f3 0x00ba34c0 (community match, verified in this file)
namespace f3m_00ba34c0 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct Buffer {
    int unk00, unk04;
    void* first;
    void* last;
    void* end;
    void FUN_00ba34c0();
};
}

// pdb: CTreeFileAccess::~CTreeFileAccess | SpeedTreeRT.obj | fnv360_0822_retail, objrun, low
void f3m_00ba34c0::Buffer::FUN_00ba34c0()
{
    if (first)
        DAT_01090a78.FUN_0086ba60(first);
    first = 0;
    last = 0;
    end = 0;
}

// @f3 0x00ba2fb0 (community match, verified in this file)
namespace f3m_00ba2fb0 {
struct Heap { void FUN_0086ba60(void* p); };
extern Heap DAT_01090a78;
struct String {          // std::string layout with the game allocator
    int allocator;
    union { char buffer[16]; char* pointer; } bx;
    unsigned int size;
    unsigned int reserved;
    void Eos(unsigned int n) { size = n; Ptr()[n] = 0; }
    char* Ptr() { return reserved < 16 ? bx.buffer : bx.pointer; }
    void Tidy()
    {
        if (reserved >= 16)
            DAT_01090a78.FUN_0086ba60(bx.pointer);
        reserved = 15;
        Eos(0);
    }
};
struct Data {
    int unk00;
    void* first;
    int unk08;
    void* second;
    int unk10;
    void* third;
    String name;
    void FUN_00ba2fb0();
};
}

// pdb: SEmbeddedTexCoords::~SEmbeddedTexCoords | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void f3m_00ba2fb0::Data::FUN_00ba2fb0()
{
    DAT_01090a78.FUN_0086ba60(first);
    first = 0;
    DAT_01090a78.FUN_0086ba60(second);
    second = 0;
    DAT_01090a78.FUN_0086ba60(third);
    third = 0;
    name.Tidy();
}

// @f3 0x00ba2e10 (community match, verified in this file)
#include <vector>
namespace f3m_00ba2e10 {

namespace f3m_00ba2e10 {
// std::vector<int>::erase(first, last) (VC8 release, checked iterators)
struct List : std::vector<int> {
    iterator FUN_00ba2e10(iterator first, iterator last);
};
}

// pdb: std::vector<float,std::allocator<float> >::operator[] | BSFaceGenManager.obj | fnv360_0822_debug, call_gap, low
// pdb params: _Pos
f3m_00ba2e10::List::iterator f3m_00ba2e10::List::FUN_00ba2e10(iterator first, iterator last)
{
    if (first != last) {
        pointer ptr = stdext::unchecked_copy(_VEC_ITER_BASE(last), _Mylast, _VEC_ITER_BASE(first));
        _Destroy(ptr, _Mylast);
        _Mylast = ptr;
    }
    return first;
}
}   // namespace f3m_00ba2e10

// @f3 0x00ba3420 (community match, verified in this file)
#include <vector>
namespace f3m_00ba3420 {

namespace f3m_00ba3420 {
struct Buffers {
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4;
    std::vector<int> indices;   // 0xf8
    std::vector<char> bytes;    // 0x108
    void FUN_00ba3420();
};
}

// pdb: CIndexedGeometry::FreeVertexWindData | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
void f3m_00ba3420::Buffers::FUN_00ba3420()
{
    indices.clear();
    bytes.clear();
}
}   // namespace f3m_00ba3420

// @f3 0x00bbdcd0 (community match, verified in this file)
namespace f3m_00bbdcd0 {
void __cdecl FUN_00401010(void* p);

struct FUN_00bbdcd0_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00bbdcd0();
};

void FUN_00bbdcd0_Obj::FUN_00bbdcd0() {
    if (this->unk04 != 0) {
        FUN_00401010((void*)this->unk04);
    }
    this->unk04 = 0;
    this->unk08 = 0;
    this->unk0C = 0;
}
}   // namespace f3m_00bbdcd0

// @f3 0x00ba31d0 (community match, verified in this file)
namespace f3m_00ba31d0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
void* __cdecl FUN_00bffa60(void* dest, const void* src, unsigned int count);   // memcpy
struct String {          // std::string layout with the game allocator
    int allocator;
    union { int words[4]; char* pointer; } bx;
    unsigned int size;
    unsigned int reserved;
    char* Ptr() { return reserved < 16 ? (char*)bx.words : bx.pointer; }
    const char* c_str() { return 16 <= reserved ? bx.pointer : (char*)bx.words; }
    void Eos(unsigned int n) { size = n; Ptr()[n] = 0; }
    ~String()
    {
        if (reserved >= 16)
            DAT_01090a78.FUN_0086ba60(bx.pointer);
        reserved = 15;
        Eos(0);
    }
};
inline char* Duplicate(const char* s)
{
    unsigned int length = strlen(s) + 1;
    char* copy = (char*)DAT_01090a78.FUN_0086b930(length);
    FUN_00bffa60(copy, s, length);
    return copy;
}
struct Reader {
    int FUN_00ba92d0();            // next token
    String FUN_00ba9460();         // token text
};
struct Element {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    char* text;   // 0x68
    void FUN_00ba31d0(Reader* reader);
};
}

// pdb: CSpeedTreeRT::ParseUserData | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: pFile
void f3m_00ba31d0::Element::FUN_00ba31d0(Reader* reader)
{
    int token = reader->FUN_00ba92d0();
    do {
        if (token == 0x4a3a) {
            text = Duplicate(reader->FUN_00ba9460().c_str());
        }
        token = reader->FUN_00ba92d0();
    } while (token != 0x4a39);
}

// @f3 0x00ba3550 (community match, verified in this file)
#include <vector>

namespace f3m_00ba3550 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
struct String {          // std::string layout with the game allocator
    int allocator;
    union { int words[4]; char* pointer; } bx;
    unsigned int size;
    unsigned int reserved;
    char* Ptr() { return reserved < 16 ? (char*)bx.words : bx.pointer; }
    const char* c_str() { return 16 <= reserved ? bx.pointer : (char*)bx.words; }
    void Eos(unsigned int n) { size = n; Ptr()[n] = 0; }
    ~String()
    {
        if (reserved >= 16)
            DAT_01090a78.FUN_0086ba60(bx.pointer);
        reserved = 15;
        Eos(0);
    }
};
struct Named {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    String name;   // 0x24
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
struct Part {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    std::vector<int> indices;   // 0xe8
};
struct Model {
    int unk00;
    Part* first;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Named* named;   // 0x50
    int unk54, unk58, unk5c;
    Part* second;   // 0x60
    void FUN_00ba3550();
};
}

// pdb: CSpeedTreeRT::FreeProjectedShadowData | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
void f3m_00ba3550::Model::FUN_00ba3550()
{
    if (named) {
        delete named;
        named = 0;
    }
    if (first)
        first->indices.clear();
    if (second)
        second->indices.clear();
}

// @f3 0x00ba3700 (community match, verified in this file)
#include <string>

namespace f3m_00ba3700 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
struct Str : String {
    Str& FUN_00ba3700(const char* s);
};
}

// pdb: CSpeedTreeRT::FreeLeafLODDataArrays | SpeedTreeRT.obj | fnv360_0822_debug, objrun_open, low
f3m_00ba3700::Str& f3m_00ba3700::Str::FUN_00ba3700(const char* s)
{
    return (Str&)append(s, traits_type::length(s));
}

// @f3 0x00ba3820 (community match, verified in this file)
#include <string>

namespace f3m_00ba3820 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
struct Str : String {
    Str& FUN_00ba3820(const char* s);
};
}

// pdb: std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >::assign | BipedAnim.obj | tesv_win, call_seq, medium
f3m_00ba3820::Str& f3m_00ba3820::Str::FUN_00ba3820(const char* s)
{
    return (Str&)assign(s, traits_type::length(s));
}

// @f3 0x00ba37a0 (community match, verified in this file)
#include <string>

namespace f3m_00ba37a0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
struct Str : String {
    Str(String s);
};
}

// pdb: CIdvFilename::CIdvFilename | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: strFilename
f3m_00ba37a0::Str::Str(String s) : String(s)
{
}

// @f3 0x00ba3850 (community match, verified in this file)
#include <string>

namespace f3m_00ba3850 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
}

f3m_00ba3850::String __cdecl FUN_00ba3850(const f3m_00ba3850::String& left, const char* right)
{
    return (f3m_00ba3850::String(left) += right);
}

// @f3 0x00ba3b70 (community match, verified in this file)
#include <string>

namespace f3m_00ba3b70 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p) throw();
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
}

class FUN_00ba3b70 : public std::exception {
public:
    virtual ~FUN_00ba3b70();
    f3m_00ba3b70::String message;
};

FUN_00ba3b70::~FUN_00ba3b70()
{
}

// @f3 0x00ba3610 (community match, verified in this file)
namespace f3m_00ba3610 {
// fill count chars with *ch, return the end
char* __stdcall FUN_00ba3610(char* first, unsigned int count, const char* ch)
{
    unsigned int n = count;
    for (char* p = first; n > 0; --n, ++p)
        *p = *ch;
    return first + count;
}
}   // namespace f3m_00ba3610

// @f3 0x00ba3bb0 (community match, verified in this file)
#include <string>

namespace f3m_00ba3bb0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p) throw();
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
}

namespace f3m_00ba3bb0 {
class Error : public std::exception {
public:
    virtual __forceinline ~Error() {}
    String message;
    Error* FUN_00ba3bb0(unsigned int flags);
};
}

// pdb: std::runtime_error::`vector deleting destructor' | TESScriptFunctions_Console.obj | tesv_win, vtable_prefix, medium
f3m_00ba3bb0::Error* f3m_00ba3bb0::Error::FUN_00ba3bb0(unsigned int flags)
{
    this->Error::~Error();
    if (flags & 1)
        DAT_01090a78.FUN_0086ba60(this);
    return this;
}

// @f3 0x00ba3f00 (community match, verified in this file)
#include <string>

namespace f3m_00ba3f00 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p) throw();
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
}

class FUN_00ba3f00 : public std::exception {
public:
    FUN_00ba3f00(const FUN_00ba3f00& other);
    virtual ~FUN_00ba3f00();
    f3m_00ba3f00::String message;
};

// pdb: std::runtime_error::runtime_error | SpeedTreeRT.obj | fnv360_0822_debug, objrun_prop, low
// pdb params: __that
FUN_00ba3f00::FUN_00ba3f00(const FUN_00ba3f00& other) : std::exception(other), message(other.message)
{
}

// @f3 0x00ba60e0 (community match, verified in this file)
#include <string>

namespace f3m_00ba60e0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
struct Vec3 { float x, y, z; };
extern Vec3 DAT_011782a4;   // camera position
extern Vec3 DAT_01068b04;   // camera direction
extern String DAT_01068a70; // last error
}

// pdb: CSpeedTreeRT::GetCamera | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pPosition, pDirection
void __cdecl FUN_00ba60e0(f3m_00ba60e0::Vec3* position, f3m_00ba60e0::Vec3* direction)
{
    if (position && direction) {
        f3m_00ba60e0::Vec3 p = f3m_00ba60e0::DAT_011782a4;
        f3m_00ba60e0::Vec3 d = f3m_00ba60e0::DAT_01068b04;
        *position = p;
        *direction = d;
    } else {
        f3m_00ba60e0::DAT_01068a70 = "GetCamera() requires non-NULL position and direction values";
    }
}

// @f3 0x00bb0060 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0060 {

namespace Task2402 {
class ShortVector : public std::vector<short> {
public:
    void FUN_00bb0060(size_type newSize, short value);
};

void ShortVector::FUN_00bb0060(size_type newSize, short value) {
    if (size() < newSize)
        _Insert_n(end(), newSize - size(), value);
    else if (newSize < size())
        erase(begin() + newSize, end());
}
}
}   // namespace f3m_00bb0060

// @f3 0x00bb09b0 (community match, verified in this file)
namespace f3m_00bb09b0 {
namespace task2408 {
struct Vector3 {float x,y,z;};
struct FloatList {int allocator;float* first;float* last;float* limit;void FUN_0058da30(const float&);};
struct Geometry {
 int vertexData,vertexFlags;
 unsigned char hasWind,renderFlags;unsigned short material;
 int indexData,normalData,colorData,textureData,windData;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64;
 FloatList positions,windPositions;
 void FUN_00bb09b0(const Vector3&);
};
// pdb: CIndexedGeometry::AddVertexCoord | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: pCoord
void Geometry::FUN_00bb09b0(const Vector3& point){
 Vector3 copy={point.x,point.y,point.z};
 positions.FUN_0058da30(copy.x);positions.FUN_0058da30(copy.y);positions.FUN_0058da30(copy.z);
 if(hasWind && colorData==1){windPositions.FUN_0058da30(copy.x);windPositions.FUN_0058da30(copy.y);windPositions.FUN_0058da30(copy.z);}
}
}
}   // namespace f3m_00bb09b0

// @f3 0x00bab3f0 (community match, verified in this file)
namespace f3m_00bab3f0 {
namespace task2407 {
struct Entry { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28; float key; };
struct UnchangedIteratorBase {};
template<class T> inline T CheckedBase(T& it,UnchangedIteratorBase) {return it;}
template<class T> inline T CheckedBase(T& it) {UnchangedIteratorBase tag;return CheckedBase(it,tag);}
inline float sortKey(Entry* entry)
{
    return entry->key;
}
struct Predicate
{
    bool operator()(Entry* a, Entry* b) const
    {
        return sortKey(a) < sortKey(b);
    }
};
template <class A, class B> struct pair
{
    A first;
    B second;
    pair() : first(A()), second(B())
    {}
    pair(const A& a, const B& b) : first(a), second(b)
    {}
};
template <class T> inline T* _Val_type(T*)
{
    return 0;
}
template <class T> inline int* _Dist_type(T*)
{
    return 0;
}
template <class It> struct ItValue;
template <class T> struct ItValue<T*>
{
    typedef T type;
};
template <class It> inline void iter_swap(It a, It b)
{
    if (a != b)
    {
        typename ItValue<It>::type tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
struct RandomIteratorTag
{
};
struct ScalarPointerTag
{
};
struct CheckedRangeTag
{
};
template <class A, class B> inline RandomIteratorTag iteratorCategory(const A&, const B&)
{
    RandomIteratorTag category;
    return category;
}
template <class A, class B> inline ScalarPointerTag pointerCategory(A&, B&)
{
    ScalarPointerTag category;
    return category;
}
extern "C" int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
template <class It, class Cat>
inline It copyBackward(It first, It last, It dest, Cat, ScalarPointerTag, CheckedRangeTag)
{
    int count = last - first;
    It result = dest - count;
    if (count > 0)
        memmove_s(&*result, count * sizeof(*first), &*first, count * sizeof(*first));
    return result;
}
template <class It> inline It unchecked_copy_backward(It first, It last, It dest)
{
    return copyBackward(CheckedBase(first), CheckedBase(last), dest, iteratorCategory(first, dest),
                        pointerCategory(first, dest), CheckedRangeTag());
}
// TEMPLATE FUNCTION push_heap WITH PRED
template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Push_heap(_RanIt _First, _Diff _Hole, _Diff _Top, _Ty _Val, _Pr _Pred)
{  // percolate _Hole to _Top or where _Val belongs, using operator<
    for (_Diff _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {  // move _Hole up to parent
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }

    *(_First + _Hole) = _Val;  // drop _Val into final hole
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Adjust_heap(_RanIt _First, _Diff _Hole, _Diff _Bottom, _Ty _Val, _Pr _Pred)
{  // percolate _Hole to _Bottom, then push _Val, using _Pred
    _Diff _Top = _Hole;
    _Diff _Idx = 2 * _Hole + 2;

    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {  // move _Hole down to larger child
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }

    if (_Idx == _Bottom)
    {  // only child at bottom, move _Hole down to it
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    _Push_heap(_First, _Hole, _Top, _Val, _Pred);
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void _Pop_heap(_RanIt _First, _RanIt _Last, _RanIt _Dest, _Ty _Val, _Pr _Pred, _Diff*)
{  // pop *_First to *_Dest and reheap, using _Pred
    *_Dest = *_First;
    _Adjust_heap(_First, _Diff(0), _Diff(_Last - _First), _Val, _Pred);
}

template <class _RanIt, class _Ty, class _Pr> inline void _Pop_heap_0(_RanIt _First, _RanIt _Last, _Pr _Pred, _Ty*)
{  // pop *_First to *(_Last - 1) and reheap, using _Pred
    _Pop_heap(_First, _Last - 1, _Last - 1, _Ty(*(_Last - 1)), _Pred, _Dist_type(_First));
}

template <class _RanIt, class _Pr> inline void pop_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // pop *_First to *(_Last - 1) and reheap, using _Pred

    if (1 < _Last - _First)
        _Pop_heap_0(CheckedBase(_First), CheckedBase(_Last), _Pred, _Val_type(_First));
}

template <class _RanIt, class _Diff, class _Ty, class _Pr>
inline void FUN_00baad40(_RanIt _First, _RanIt _Last, _Pr _Pred, _Diff*, _Ty*)
{  // make nontrivial [_First, _Last) into a heap, using _Pred
    _Diff _Bottom = _Last - _First;
    for (_Diff _Hole = _Bottom / 2; 0 < _Hole;)
    {  // reheap top half, bottom to top
        --_Hole;
        _Adjust_heap(_First, _Hole, _Bottom, _Ty(*(_First + _Hole)), _Pred);
    }
}

template <class _RanIt, class _Pr> inline void make_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // make [_First, _Last) into a heap, using _Pred

    if (1 < _Last - _First)
        FUN_00baad40(CheckedBase(_First), CheckedBase(_Last), _Pred, _Dist_type(_First), _Val_type(_First));
}

template <class _RanIt, class _Pr> inline void FUN_00bab2b0(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // order heap by repeatedly popping, using _Pred
    for (; 1 < _Last - _First; --_Last)
        pop_heap(_First, _Last, _Pred);
}

template <class _RanIt, class _Pr> inline void sort_heap(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // order heap by repeatedly popping, using _Pred

    FUN_00bab2b0(CheckedBase(_First), CheckedBase(_Last), _Pred);
}

template <class _BidIt, class _Pr, class _Ty> __forceinline void _Insertion_sort1(_BidIt _First, _BidIt _Last, _Pr _Pred, _Ty*)
{  // insertion sort [_First, _Last), using _Pred
    if (_First != _Last)
        for (_BidIt _Next = _First; ++_Next != _Last;)
        {  // order next element
            _BidIt _Next1 = _Next;
            _Ty _Val = *_Next;

            if (_Pred(_Val, *_First))
            {  // found new earliest element, move to front
                unchecked_copy_backward(_First, _Next, ++_Next1);
                *_First = _Val;
            }
            else
            {  // look for insertion point after first
                for (_BidIt _First1 = _Next1; _Pred(_Val, *--_First1); _Next1 = _First1)
                    *_Next1 = *_First1;  // move hole down
                *_Next1 = _Val;          // insert element in hole
            }
        }
}

template <class _BidIt, class _Pr> inline void FUN_00bab100(_BidIt _First, _BidIt _Last, _Pr _Pred)
{  // insertion sort [_First, _Last), using _Pred
    _Insertion_sort1(_First, _Last, _Pred, _Val_type(_First));
}

template <class _RanIt, class _Pr> inline void _Med3(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr _Pred)
{  // sort median of three elements to middle
    if (_Pred(*_Mid, *_First))
        iter_swap(_Mid, _First);
    if (_Pred(*_Last, *_Mid))
        iter_swap(_Last, _Mid);
    if (_Pred(*_Mid, *_First))
        iter_swap(_Mid, _First);
}

template <class _RanIt, class _Pr> inline void _Median(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr _Pred)
{  // sort median element to middle
    if (40 < _Last - _First)
    {  // median of nine
        int _Step = (_Last - _First + 1) / 8;
        _Med3(_First, _First + _Step, _First + 2 * _Step, _Pred);
        _Med3(_Mid - _Step, _Mid, _Mid + _Step, _Pred);
        _Med3(_Last - 2 * _Step, _Last - _Step, _Last, _Pred);
        _Med3(_First + _Step, _Mid, _Last - _Step, _Pred);
    }
    else
        _Med3(_First, _Mid, _Last, _Pred);
}

template <class _RanIt, class _Pr>
inline pair<_RanIt, _RanIt> FUN_00baad80(_RanIt _First, _RanIt _Last, _Pr _Pred)
{  // partition [_First, _Last), using _Pred
    _RanIt _Pfirst = _First + (_Last - _First) / 2;
    _Median(_First, _Pfirst, _Last - 1, _Pred);
    _RanIt _Plast = _Pfirst + 1;

    while (_First < _Pfirst && !_Pred(*(_Pfirst - 1), *_Pfirst) && !_Pred(*_Pfirst, *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last && !_Pred(*_Plast, *_Pfirst) && !_Pred(*_Pfirst, *_Plast))
        ++_Plast;

    _RanIt _Gfirst = _Plast;
    _RanIt _Glast = _Pfirst;

    for (;;)
    {  // partition
        for (; _Gfirst < _Last; ++_Gfirst)
            if (_Pred(*_Pfirst, *_Gfirst))
                ;
            else if (_Pred(*_Gfirst, *_Pfirst))
                break;
            else
                iter_swap(_Plast++, _Gfirst);
        for (; _First < _Glast; --_Glast)
            if (_Pred(*(_Glast - 1), *_Pfirst))
                ;
            else if (_Pred(*_Pfirst, *(_Glast - 1)))
                break;
            else
                iter_swap(--_Pfirst, _Glast - 1);
        if (_Glast == _First && _Gfirst == _Last)
            return (pair<_RanIt, _RanIt>(_Pfirst, _Plast));

        if (_Glast == _First)
        {  // no room at bottom, rotate pivot upward
            if (_Plast != _Gfirst)
                iter_swap(_Pfirst, _Plast);
            ++_Plast;
            iter_swap(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {  // no room at top, rotate pivot downward
            if (--_Glast != --_Pfirst)
                iter_swap(_Glast, _Pfirst);
            iter_swap(_Pfirst, --_Plast);
        }
        else
            iter_swap(_Gfirst++, --_Glast);
    }
}

// @fnv 0x00b16b60
// pdb: std::_Sort<CIdvBranch * *,int,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Last, _Ideal, _Pred
void __cdecl FUN_00bab3f0(Entry** first, Entry** last, int ideal, Predicate pred)
{
    int count;
    for (; 32 < (count = last - first) && 0 < ideal;)
    {
        pair<Entry**, Entry**> mid = FUN_00baad80(first, last, pred);
        ideal /= 2, ideal += ideal / 2;
        if (mid.first - first < last - mid.second)
        {
            FUN_00bab3f0(first, mid.first, ideal, pred);
            first = mid.second;
        }
        else
        {
            FUN_00bab3f0(mid.second, last, ideal, pred);
            last = mid.first;
        }
    }
    if (32 < count)
    {
        make_heap(first, last, pred);
        sort_heap(first, last, pred);
    }
    else if (1 < count)
        FUN_00bab100(first, last, pred);
}
}
}   // namespace f3m_00bab3f0

// @f3 0x00ba1f80 (community match, verified in this file)
extern float DAT_00db38b8;
extern unsigned char DAT_01178274;
namespace f3m_00ba1f80 {
namespace Worker2428 {
struct Data {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    float lod;
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
    unsigned int count;
};
struct Instance {
    unsigned int unk00, unk04, unk08, unk0c;
    float lod;
};
struct Tree {
    Data* data;
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
    Instance* instance;
    float GetLod() {
        float level = -1.0f;
        if (instance) level = instance->lod;
        else level = data->lod;
        return level;
    }
    unsigned short GetCount() { unsigned int value = data->count; return (unsigned short)value; }
    unsigned short FUN_00ba1f80(float lod);
};
// pdb: CSpeedTreeRT::GetDiscreteLeafLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, call_dedup, low
// pdb params: fLodLevel
unsigned short Tree::FUN_00ba1f80(float lod)
{
    unsigned short level = 0;
    if (lod == -1.0f)
        lod = GetLod();
    if (DAT_01178274) {
        int count = GetCount() + 1;
        level = (unsigned short)((1.0f - lod) * count);
        if (level == count) --level;
    } else {
        int count = GetCount();
        level = (unsigned short)((1.0f - lod) * count);
        if (level == count) --level;
    }
    return level;
}
}
}   // namespace f3m_00ba1f80

// @f3 0x00ba3640 (community match, verified in this file)
namespace f3m_00ba3640 {
namespace task2438 {
struct Heap{void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct Allocator{Allocator(){}Allocator(const Allocator&){}void deallocate(char*p,unsigned){DAT_01090a78.FUN_0086ba60(p);}};
struct StringBase{Allocator allocator;StringBase(Allocator a=Allocator()):allocator(a){}};
struct String:StringBase{
 union{char buffer[16];char* ptr;}data;unsigned size,capacity;
 String& FUN_0042eff0(const String&,unsigned,unsigned);
 String& FUN_00ba2e70(const String&,unsigned,unsigned);
 String(const String&other):StringBase(other){Tidy();FUN_0042eff0(other,0,-1);}
 ~String(){Tidy(true);}
 char* Ptr(){return capacity>=16?data.ptr:data.buffer;}
 static void AssignChar(char&d,const char&s){d=s;}
 void Eos(unsigned n){AssignChar(Ptr()[size=n],char());}
 void Tidy(bool built=false){if(built&&capacity>=16)allocator.deallocate(data.ptr,capacity+1);capacity=15;Eos(0);}
};
String __cdecl FUN_00ba3640(const String&left,const String&right){return String(left).FUN_00ba2e70(right,0,-1);}
}
}   // namespace f3m_00ba3640

// @f3 0x00ba19e0 (community match, verified in this file)
#include <new>
namespace Task2449 {
struct Heap {void* FUN_0086b930(unsigned int);};
extern Heap DAT_01090a78;
void* FUN_00ba19e0(unsigned int count){
 if(count<=0){count=0;}
 else if((unsigned int)-1/count<28){const char* msg=0;throw std::bad_alloc(msg);}
 return DAT_01090a78.FUN_0086b930(count*28);
}
}

// @f3 0x00ba99a0 (community match, verified in this file)
#include <math.h>
namespace Worker2440 {
extern double DAT_00e31f80;
struct Point { float x,y,z; };
struct Matrix {
    float m00,m01,m02,m10,m11,m12,m20,m21,m22;
    void FUN_00ba99a0(float angle, Point axis);
};
void Matrix::FUN_00ba99a0(float angle, Point axis)
{
    float sine = (float)sin((float)(angle / DAT_00e31f80));
    float cosine = (float)cos((float)(angle / DAT_00e31f80));
    float complement = 1.0f-cosine;
    float x=axis.x, y=axis.y, z=axis.z;
    m00 = complement*x*x+cosine;
    m01 = complement*x*y+sine*z;
    m02 = complement*x*z-sine*y;
    m10 = complement*x*y-sine*z;
    m11 = complement*y*y+cosine;
    m12 = complement*y*z+sine*x;
    m20 = complement*x*z+sine*y;
    m21 = complement*y*z-sine*x;
    m22 = complement*z*z+cosine;
}
}

// @f3 0x00bb46f0 (community match, verified in this file)
#include <new>
namespace f3m_00bb46f0 {
namespace task2448 {
struct Element {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34;};
Element* __cdecl FUN_00bb46f0(unsigned count,Element*){
 if(count<=0)count=0;
 else if((unsigned(-1)/count)<sizeof(Element))throw std::bad_alloc(0);
 return (Element*)::operator new(count*sizeof(Element));
}
}
}   // namespace f3m_00bb46f0

// @f3 0x00bb4760 (community match, verified in this file)
#include <new>
namespace f3m_00bb4760 {
namespace task2451 {
struct Element {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;};
Element* __cdecl FUN_00bb4760(unsigned count,Element*){
 if(count<=0)count=0;
 else if((unsigned(-1)/count)<sizeof(Element))throw std::bad_alloc(0);
 return (Element*)::operator new(count*sizeof(Element));
}
}

}   // namespace f3m_00bb4760

// @f3 0x00bbdb80 (community match, verified in this file)
#include <new>
namespace f3m_00bbdb80 {
namespace task2455 {
struct Element {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50;};
Element* __cdecl FUN_00bbdb80(unsigned count,Element*){
 if(count<=0)count=0;
 else if((unsigned(-1)/count)<sizeof(Element))throw std::bad_alloc(0);
 return (Element*)::operator new(count*sizeof(Element));
}
}


}   // namespace f3m_00bbdb80

// @f3 0x00bb1020 (community match, verified in this file)
namespace f3m_00bb1020 {
namespace Task2461 {
struct Element { unsigned a,b,c,d; };
struct Allocator {};
struct NonScalarTag {};
struct CheckedTag {};
inline NonScalarTag PtrCat(Element*&,Element*&) { NonScalarTag tag; return tag; }
void __cdecl FUN_00bb03e0(Element*,unsigned,const Element&,Allocator&,NonScalarTag,CheckedTag);
struct Vector {
    Allocator allocator;
    Element* FUN_00bb1020(Element* first,unsigned count,const Element& value);
};
Element* Vector::FUN_00bb1020(Element* first,unsigned count,const Element& value) {
    FUN_00bb03e0(first,count,value,allocator,PtrCat(first,first),CheckedTag());
    return first+count;
}
}
}   // namespace f3m_00bb1020

// @f3 0x00bbdbe0 (community match, verified in this file)
#include <new>
namespace f3m_00bbdbe0 {
void* __cdecl FUN_00401000(unsigned int size);
unsigned int* __cdecl FUN_00bbdbe0(unsigned int count, unsigned int*)
{
    if (count <= 0)
        count = 0;
    else if ((unsigned int)(-1) / count < sizeof(unsigned int))
        throw std::bad_alloc(0);
    return (unsigned int*)FUN_00401000(count * sizeof(unsigned int));
}
}   // namespace f3m_00bbdbe0

// @f3 0x00baa330 (community match, verified in this file)
#include <new>
namespace f3m_00baa330 {
struct Element2450 { int x,y,z; };
Element2450* FUN_00baa330(unsigned int count,Element2450*) {
 if(count<=0) count=0;
 else if((unsigned int)-1/count<sizeof(Element2450)) { const char* message=0; throw std::bad_alloc(message); }
 return static_cast<Element2450*>(operator new(count*sizeof(Element2450)));
}
}   // namespace f3m_00baa330

// @f3 0x00bb5410 (community match, verified in this file)
namespace f3m_00bb5410 {
namespace task2460 {
struct Element {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34;};
struct Allocator {};
struct PointerCategory {};
struct CheckedTag {};
inline PointerCategory Category(Element*&,Element*&) {PointerCategory c;return c;}
void __cdecl FUN_00bb52e0(Element*,unsigned,const Element&,Allocator&,PointerCategory,CheckedTag);
inline void Fill(Element* first,unsigned count,const Element& value,Allocator& al){FUN_00bb52e0(first,count,value,al,Category(first,first),CheckedTag());}
struct Vector {Allocator allocator;Element* FUN_00bb5410(Element*,unsigned,const Element&);};
Element* Vector::FUN_00bb5410(Element* first,unsigned count,const Element& value){Fill(first,count,value,allocator);return first+count;}
}
}   // namespace f3m_00bb5410

// @f3 0x00bb1060 (community match, verified in this file)
namespace f3m_00bb1060 {
namespace worker2462 {
struct Element { int a,b,c,d; };
struct Allocator {};
struct NonscalarTag {};
struct RangeCheckedTag {};
inline NonscalarTag PtrCat(Element*&,Element*&) { NonscalarTag c; return c; }
void __cdecl FUN_00bb0490(Element*,unsigned,const Element&,Allocator&,NonscalarTag,RangeCheckedTag);
inline void UncheckedFill(Element* p,unsigned n,const Element& val,Allocator& alloc) {
 FUN_00bb0490(p,n,val,alloc,PtrCat(p,p),RangeCheckedTag());
}
struct Vector {
 Allocator alloc;
 Element* first; Element* last; Element* end;
 Element* FUN_00bb1060(Element* p,unsigned n,const Element& val);
};
Element* Vector::FUN_00bb1060(Element* p,unsigned n,const Element& val) {
 UncheckedFill(p,n,val,alloc);
 return p+n;
}
}
}   // namespace f3m_00bb1060

// @f3 0x00baec90 (community match, verified in this file)
#include <new>
namespace f3m_00baec90 {
typedef short Element2454;
Element2454* FUN_00baec90(unsigned int count,Element2454*) {
 if(count<=0) count=0;
 else if((unsigned int)-1/count<sizeof(Element2454)) { const char* message=0; throw std::bad_alloc(message); }
 return static_cast<Element2454*>(operator new(count*sizeof(Element2454)));
}
}   // namespace f3m_00baec90

// @f3 0x00bb5450 (community match, verified in this file)
namespace f3m_00bb5450 {
namespace task2466 {
struct Element {unsigned unk00,unk04,unk08;};
struct Allocator {};
struct PointerCategory {};
struct CheckedTag {};
inline PointerCategory Category(Element*&,Element*&) {PointerCategory c;return c;}
void __cdecl FUN_00bb5310(Element*,unsigned,const Element&,Allocator&,PointerCategory,CheckedTag);
inline void Fill(Element* first,unsigned count,const Element& value,Allocator& al){FUN_00bb5310(first,count,value,al,Category(first,first),CheckedTag());}
struct Vector {Allocator allocator;Element* FUN_00bb5450(Element*,unsigned,const Element&);};
Element* Vector::FUN_00bb5450(Element* first,unsigned count,const Element& value){Fill(first,count,value,allocator);return first+count;}
}

}   // namespace f3m_00bb5450

// @f3 0x00bbacc0 (community match, verified in this file)
namespace f3m_00bbacc0 {
extern "C" void __cdecl _invalid_parameter_noinfo();
namespace task2457 {
struct Entry {
    unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
    float key;
};
struct Iterator {
    const void* container;
    Entry* pointer;
    int operator-(const Iterator& other) const {
        if (!(container && container == other.container)) _invalid_parameter_noinfo();
        return pointer - other.pointer;
    }
};
struct Compare { bool operator()(const Entry& a,const Entry& b) const { return a.key > b.key; } };
void __cdecl FUN_00bba8a0(Entry*, Entry*, int, Compare);
void __cdecl FUN_00bbacc0(Iterator first,Iterator last,Compare comp) {
    FUN_00bba8a0(first.pointer,last.pointer,last-first,comp);
}
}
}   // namespace f3m_00bbacc0

// @f3 0x00bbbec0 (community match, verified in this file)
namespace f3m_00bbbec0 {
namespace Worker2464 {
struct Block { unsigned int a,b,c,d; };
struct Allocator { unsigned int state; };
struct NonScalar {};
struct RangeChecked {};
inline NonScalar PointerCategory(Block*,Block*) { NonScalar category; return category; }
void __cdecl FUN_00bbbb70(Block*,unsigned int,const Block&,Allocator&,NonScalar,RangeChecked);
struct Vector {
    Allocator allocator;
    Block* FUN_00bbbec0(Block* pointer,unsigned int count,const Block& value);
};
// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::erase | FrondEngine.obj | fnv360_0721_beta, objrun_sim, low
// pdb params: _Where
Block* Vector::FUN_00bbbec0(Block* pointer,unsigned int count,const Block& value)
{
    FUN_00bbbb70(pointer,count,value,allocator,PointerCategory(pointer,pointer),RangeChecked());
    return pointer+count;
}
}
}   // namespace f3m_00bbbec0

// @f3 0x00bb9220 (community match, verified in this file)
namespace f3m_00bb9220 {
namespace task2463 {
struct Entry { unsigned field0,field4,field8,fieldc; };
struct Allocator {};
struct NonScalarTag {};
struct RangeCheckedTag {};
template<class T> inline NonScalarTag PointerCategory(T&,T&) { NonScalarTag tag; return tag; }
void __cdecl FUN_00bb6cd0(Entry*,unsigned,const Entry&,Allocator&,NonScalarTag,RangeCheckedTag);
inline void UncheckedFill(Entry* first,unsigned count,const Entry& value,Allocator& allocator) {
    FUN_00bb6cd0(first,count,value,allocator,PointerCategory(first,first),RangeCheckedTag());
}
struct Container {
    Allocator allocator;
    Entry* FUN_00bb9220(Entry* first,unsigned count,const Entry& value);
};
Entry* Container::FUN_00bb9220(Entry* first,unsigned count,const Entry& value) {
    UncheckedFill(first,count,value,allocator);
    return first+count;
}
}
}   // namespace f3m_00bb9220

// @f3 0x00bb9030 (community match, verified in this file)
namespace f3m_00bb9030 {
namespace f3m_00bb9030 {
struct Elem {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
inline void SwapField(int& x, int& y) { int t = x; x = y; y = t; }
// pdb: std::_Uninit_move<std::vector<float,std::allocator<float> > *,std::vector<float,std::allocator<float> > *,std::allocator<std::vector<float,std::allocator<float> > >,std::vector<float,std::allocator<float> > > | FrondEngine.obj | fnv360_0822_retail, objrun_open, low
// pdb params: _First, _Last, _Dest, _Al, __formal, __formal
Elem* FUN_00bb9030(Elem* first, Elem* last, Elem* dest)
{
    while (first != last) {
        --last;
        --dest;
        SwapField(dest->unk04, last->unk04);
        SwapField(dest->unk08, last->unk08);
        SwapField(dest->unk0c, last->unk0c);
    }
    return dest;
}
}
}   // namespace f3m_00bb9030

// @f3 0x00bb4820 (community match, verified in this file)
namespace f3m_00bb4820 {
namespace f3m_00bb4820 {
struct Elem { int unk00, unk04, unk08, unk0c, unk10, unk14; };
Elem* FUN_00bb4820(Elem* first, Elem* last, Elem* dest)
{
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}
}
}   // namespace f3m_00bb4820

// @f3 0x00bb0110 (community match, verified in this file)
namespace f3m_00bb0110 {
namespace f3m_00bb0110 {
void __cdecl FUN_00c01e8b();
struct Vec;
struct Iter {
    Vec* cont;
    short* ptr;
};
struct Vec {
    int alloc;
    short* first;
    short* last;
    short* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    Iter mk(short* p) {
        if (first > p || p > last) FUN_00c01e8b();
        Iter it; it.cont = this; it.ptr = p; return it;
    }
    Iter begin() { return mk(first); }
    void FUN_00bafa00(Iter where, unsigned int n, const short& val);
    Iter FUN_00bb0110(Iter where, const short& val);
};
inline int diff(const Iter& a, const Iter& b) {
    if (a.cont == 0 || a.cont != b.cont) FUN_00c01e8b();
    return a.ptr - b.ptr;
}
inline Iter add(Iter it, int n) {
    if (it.ptr + n > it.cont->last || it.ptr + n < it.cont->first) FUN_00c01e8b();
    it.ptr += n; return it;
}
// pdb: std::vector<unsigned short,std::allocator<unsigned short> >::push_back | IndexedGeometry.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Val
Iter Vec::FUN_00bb0110(Iter where, const short& val)
{
    unsigned int off = size() == 0 ? 0 : diff(where, begin());
    FUN_00bafa00(where, 1, val);
    return add(begin(), off);
}
}
}   // namespace f3m_00bb0110

// @f3 0x00bbdaf0 (community match, verified in this file)
namespace f3m_00bbdaf0 {
namespace f3m_00bbdaf0 {
struct Obj {
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
    float unk40;
    float unk44;
    void FUN_00bbdaf0(float a, float b);
};
// pdb: CTreeEngine::SetLodLimits | TreeEngine.obj | fnv360_0822_retail, objrun, medium
// pdb params: fNear, fFar
void Obj::FUN_00bbdaf0(float a, float b)
{
    unk44 = a;
    unk40 = b;
}
}
}   // namespace f3m_00bbdaf0

// @f3 0x00bb57d0 (community match, verified in this file)
namespace f3m_00bb57d0 {
namespace f3m_00bb57d0 {
struct Elem56 { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34; };
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Elem56* __cdecl FUN_00bb46f0(unsigned int n, Elem56* hint);
struct Vec {
    int alloc;
    Elem56* first;
    Elem56* last;
    Elem56* end;
    bool FUN_00bb57d0(unsigned int n);
};
bool Vec::FUN_00bb57d0(unsigned int n)
{
    first = 0;
    last = 0;
    end = 0;
    if (n == 0)
        return false;
    if (0x4924924 < n)
        FUN_00bc5f00();
    first = FUN_00bb46f0(n, 0);
    last = first;
    end = first + n;
    return true;
}
}
}   // namespace f3m_00bb57d0

// @f3 0x00baf1d0 (community match, verified in this file)
namespace f3m_00baf1d0 {
namespace f3m_00baf1d0 {
void __cdecl FUN_00c01e8b();
struct Vec {
    int alloc;
    void** first;
    void** last;
    void** end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    void*& operator[](unsigned int n) {
        if (!(n < size()))
            FUN_00c01e8b();
        return *(first + n);
    }
};
struct Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned short index;
    unsigned short count;
    Vec slots;
    void FUN_00baf1d0(unsigned short v);
};
// pdb: CIndexedGeometry::ResetStripCounter | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: nLodLevel
void Obj::FUN_00baf1d0(unsigned short v)
{
    index = v;
    count = 0;
    slots[v] = 0;
}
}
}   // namespace f3m_00baf1d0

// @f3 0x00bbd2c0 (community match, verified in this file)
namespace f3m_00bbd2c0 {
struct FUN_00bbd2c0 {
    float a;
    float b;
    float c;
    float d;
    float e;
    int mode;
    FUN_00bbd2c0(float x, float y);
};
// pdb: std::ctype_base::ctype_base | TESScriptFunctions_Console.obj | tesv_win, objrun_open, low
FUN_00bbd2c0::FUN_00bbd2c0(float x, float y)
{
    a = x;
    mode = 2;
    b = y;
    c = d = e = 0.0f;
}
}   // namespace f3m_00bbd2c0

// @f3 0x00baf750 (community match, verified in this file)
namespace f3m_00baf750 {
namespace Worker2471 {
struct Block { unsigned int a,b,c,d; };
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Block* __cdecl FUN_00baec30(unsigned int,Block*);
struct Vector {
    unsigned int allocator;
    Block* first;
    Block* last;
    Block* end;
    bool FUN_00baf750(unsigned int capacity);
};
// pdb: std::vector<std::vector<unsigned short,std::allocator<unsigned short> >,std::allocator<std::vector<unsigned short,std::allocator<unsigned short> > > >::_Buy | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: _Capacity
bool Vector::FUN_00baf750(unsigned int capacity)
{
    first=0, last=0, end=0;
    if (capacity==0) return false;
    if (capacity > (unsigned int)(-1)/sizeof(Block))
        FUN_00bc5f00();
    first=FUN_00baec30(capacity,0);
    last=first;
    end=first+capacity;
    return true;
}
}
}   // namespace f3m_00baf750

// @f3 0x00baf600 (community match, verified in this file)
#include <string.h>
#include <stdlib.h>
namespace f3m_00baf600 {
namespace task2474 {
struct Iterator {
 const void* owner;short* ptr;
 Iterator(const void* o,short* p):owner(o),ptr(p){}
 bool operator!=(const Iterator& other)const {if(!owner || owner!=other.owner)_invalid_parameter_noinfo();return ptr!=other.ptr;}
};
struct Vector {
 int allocator;short* first;short* last;short* capacity;
 Iterator FUN_00baf600(Iterator first,Iterator last);
};
Iterator Vector::FUN_00baf600(Iterator begin,Iterator end) {
 if(begin!=end){
  int count=last-end.ptr;
  short* result=begin.ptr+count;
  if(count>0)memmove_s(begin.ptr,count*sizeof(short),end.ptr,count*sizeof(short));
  last=result;
 }
 return begin;
}
}
}   // namespace f3m_00baf600

// @f3 0x00ba95b0 (community match, verified in this file)
#include <math.h>
namespace f3m_00ba95b0 {
namespace task2488 {
struct Vector {float x,y,z;void FUN_00ba95b0();};
void Vector::FUN_00ba95b0(){float sum=x*x+y*y+z*z;float inverse=1.0f/(float)sqrt((double)sum);x*=inverse;y*=inverse;z*=inverse;}
}
}   // namespace f3m_00ba95b0

// @f3 0x00baf710 (community match, verified in this file)
#include <stddef.h>
namespace f3m_00baf710 {

struct Elem16 { int a, b, c, d; };

class Vec16 {
public:
    char alval;
    Elem16* first;
    Elem16* last;
    Elem16* end;
};

namespace vec16_bb1460 {
struct CategoryTag {};
}

extern "C" void __cdecl FUN_00401010(int);

// pdb: std::_Destroy_range<std::allocator<std::vector<float,std::allocator<float> > > > | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: _First, _Last, _Al
void __cdecl FUN_00baf710(Elem16* first, Elem16* last, Vec16& alloc, vec16_bb1460::CategoryTag tag) {
    for (; first != last; first = (Elem16*)((char*)first + 0x10)) {
        if (first->b != 0) {
            FUN_00401010(first->b);
        }
        first->b = 0;
        first->c = 0;
        first->d = 0;
    }
}
}   // namespace f3m_00baf710

// @f3 0x00ba2e70 (community match, verified in this file)
namespace f3m_00ba2e70 {
namespace Task2499 {
extern "C" char* __cdecl FUN_00c01c20(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int uiCount);
struct Str00ba2e70
{
    int unk00;
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
    static void FUN_00bff073();
    static void FUN_00bff0b2();
    void FUN_0042a750(unsigned int uiNewsize, unsigned int uiOldlen);
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Eos(unsigned int uiNewsize)
    {
        _Myptr()[m_uiSize = uiNewsize] = 0;
    }
    __forceinline bool _Grow(unsigned int uiNewsize)
    {
        if (0xfffffffe < uiNewsize)
            FUN_00bff073();
        if (m_uiRes < uiNewsize)
            FUN_0042a750(uiNewsize, m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    Str00ba2e70& FUN_00ba2e70(const Str00ba2e70& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray);
};
Str00ba2e70& Str00ba2e70::FUN_00ba2e70(const Str00ba2e70& kRight,unsigned int uiRoff,unsigned int uiCount) {
    if(kRight.m_uiSize < uiRoff) FUN_00bff0b2();
    unsigned int num=kRight.m_uiSize-uiRoff;
    if(num<uiCount) uiCount=num;
    if(0xffffffffu-m_uiSize<=uiCount || m_uiSize+uiCount<m_uiSize) FUN_00bff073();
    if(0<uiCount && _Grow(num=m_uiSize+uiCount)) {
        FUN_00c01c20(_Myptr()+m_uiSize,m_uiRes-m_uiSize,kRight._Myptr()+uiRoff,uiCount);
        _Eos(num);
    }
    return *this;
}
}
}   // namespace f3m_00ba2e70

// @f3 0x00ba9610 (community match, verified in this file)
namespace f3m_00ba9610 {
namespace task2502 {
struct BranchMatrix {
float m00,m01,m02,m10,m11,m12,m20,m21,m22;
BranchMatrix() { m00=1.0f; m01=0.0f; m02=0.0f; m10=0.0f; m11=1.0f; m12=0.0f; m20=0.0f; m21=0.0f; m22=1.0f; }
BranchMatrix FUN_00ba9610(const BranchMatrix&);
};
// pdb: CRotTransform::operator* | Branch.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: cTrans
BranchMatrix BranchMatrix::FUN_00ba9610(const BranchMatrix& a)
{
    BranchMatrix result;
    result.m00 = m00 * a.m00 + m01 * a.m10 + m02 * a.m20;
    result.m01 = m00 * a.m01 + m01 * a.m11 + m02 * a.m21;
    result.m02 = m00 * a.m02 + m01 * a.m12 + m02 * a.m22;
    result.m10 = m10 * a.m00 + m11 * a.m10 + m12 * a.m20;
    result.m11 = m10 * a.m01 + m11 * a.m11 + m12 * a.m21;
    result.m12 = m10 * a.m02 + m11 * a.m12 + m12 * a.m22;
    result.m20 = m20 * a.m00 + m21 * a.m10 + m22 * a.m20;
    result.m21 = m20 * a.m01 + m21 * a.m11 + m22 * a.m21;
    result.m22 = m20 * a.m02 + m21 * a.m12 + m22 * a.m22;
    return result;
}
}

}   // namespace f3m_00ba9610

// @f3 0x00baff10 (community match, verified in this file)
#include <vector>
namespace f3m_00baff10 {

namespace Task2527 {
class FloatVector : public std::vector<float> {
public:
    void FUN_00baff10(size_type newSize, float value);
};

void FloatVector::FUN_00baff10(size_type newSize, float value) {
    if (size() < newSize)
        _Insert_n(end(), newSize - size(), value);
    else if (newSize < size())
        erase(begin() + newSize, end());
}
}

}   // namespace f3m_00baff10

// @f3 0x00bbd690 (community match, verified in this file)
#include <string>
namespace f3m_00bbd690 {
namespace Task2510 {
struct FUN_00bff16a { int lockKind; ~FUN_00bff16a(); };
struct FUN_00bbd690;
void __cdecl FUN_00bff2de(FUN_00bbd690*);
struct FUN_00bbd690 {
    FUN_00bff16a lock;
    std::string days, months, oldname, newname;
    ~FUN_00bbd690();
};
FUN_00bbd690::~FUN_00bbd690() { FUN_00bff2de(this); }
}
}   // namespace f3m_00bbd690

// @f3 0x00bb2bc0 (community match, verified in this file)
namespace f3m_00bb2bc0 {
struct BufferOwner2543
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char* buffer10;
    unsigned char* buffer14;
    unsigned char* buffer18;
    unsigned char* buffer1c;
    unsigned char* buffer20;
    unsigned char* buffer24;
    unsigned char* buffer28;
    unsigned char* buffer2c;
    unsigned char* buffer30;
    unsigned char* buffer34;
    unsigned char* buffer38;
    int unk3c;
    unsigned char* buffer40;

    void FUN_00ba1200();
    void FUN_00bb2bc0();
};
// @fnv 0x00b274d0
void BufferOwner2543::FUN_00bb2bc0()
{
    delete[] buffer10;
    delete[] buffer14;
    delete[] buffer18;
    delete[] buffer24;
    delete[] buffer28;
    delete[] buffer2c;
    delete[] buffer30;
    delete[] buffer1c;
    delete[] buffer20;
    delete[] buffer34;
    delete[] buffer38;

    buffer10 = 0;
    buffer14 = 0;
    buffer18 = 0;
    buffer24 = 0;
    buffer28 = 0;
    buffer2c = 0;
    buffer30 = 0;
    buffer1c = 0;
    buffer20 = 0;
    buffer34 = 0;
    buffer38 = 0;

    delete[] buffer40;
    buffer40 = 0;
    FUN_00ba1200();
}
}   // namespace f3m_00bb2bc0

// @f3 0x00ba93b0 (community match, verified in this file)
namespace f3m_00ba93b0 {
namespace task2538 {
struct BasicText {
unsigned proxy;
union Storage { char chars[16]; char* ptr; } storage;
unsigned length,capacity;
static void FUN_00bff073();
void FUN_0042a750(unsigned,unsigned);
void FUN_00ba9240(unsigned,unsigned,char);
char* data() { return 16 <= capacity ? storage.ptr : storage.chars; }
void eos(unsigned n) { length=n; data()[n]=char(); }
__forceinline bool grow(unsigned n) { if (0xfffffffeU<n) FUN_00bff073(); if (capacity<n) FUN_0042a750(n,length); else if(n==0) eos(0); return 0<n; }
BasicText& FUN_00ba93b0(unsigned count,char ch);
};
BasicText& BasicText::FUN_00ba93b0(unsigned count,char ch) {
if ((unsigned)-1-length<=count) FUN_00bff073();
unsigned num;
if(0<count && grow(num=length+count)) { FUN_00ba9240(length,count,ch); eos(num); }
return *this;
}
}

}   // namespace f3m_00ba93b0

// @f3 0x00baac90 (community match, verified in this file)
namespace f3m_00baac90 {
namespace Task2542 {
struct SortedEntry_aad80
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
    float m_fPriority;
};
struct PriorityGreater_aad80
{
    bool operator()(const SortedEntry_aad80* left, const SortedEntry_aad80* right) const
    {
        return left->m_fPriority > right->m_fPriority;
    }
};
typedef SortedEntry_aad80* EP;
void __cdecl FUN_00baab70(EP*,EP*,EP*,PriorityGreater_aad80);
// pdb: std::_Median<CIdvBranch * *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Mid, _Last, _Pred
void __cdecl FUN_00baac90(EP* first,EP* mid,EP* last,PriorityGreater_aad80 pred) {
    if(40 < last-first) {
        int step=(last-first+1)/8;
        FUN_00baab70(first,first+step,first+2*step,pred);
        FUN_00baab70(mid-step,mid,mid+step,pred);
        FUN_00baab70(last-2*step,last-step,last,pred);
        FUN_00baab70(first+step,mid,last-step,pred);
    } else FUN_00baab70(first,mid,last,pred);
}
}
}   // namespace f3m_00baac90

// @f3 0x00baeba0 (community match, verified in this file)
namespace f3m_00baeba0 {
struct Color2566 {float r,g,b,a;};
unsigned int __stdcall FUN_00baeba0(const Color2566& color)
{
 return (unsigned int)(color.r * 255.0) + ((unsigned int)(color.g * 255.0) << 8) +
        ((unsigned int)(color.b * 255.0) << 16) - 0x1000000;
}
}   // namespace f3m_00baeba0

// @f3 0x00bb5c30 (community match, verified in this file)
#include <vector>
namespace f3m_00bb5c30 {
namespace task2558 {
struct UIntVector:std::vector<unsigned> {UIntVector* FUN_00bb5c30(const std::vector<unsigned>&);};
UIntVector* UIntVector::FUN_00bb5c30(const std::vector<unsigned>& other){if(_Buy(other.size())) {try{_Mylast=_Ucopy(other.begin(),other.end(),_Myfirst);}catch(...){_Tidy();throw;}}return this;}
}
}   // namespace f3m_00bb5c30

// @f3 0x00bb6500 (community match, verified in this file)
#include <new>
namespace f3m_00bb6500 {
namespace Worker2574 {
struct FUN_00bb5880 {
    unsigned int allocator;
    void* first;
    void* last;
    void* end;
    FUN_00bb5880(const FUN_00bb5880&);
    ~FUN_00bb5880();
};
struct Element {
    FUN_00bb5880 list;
    float x,y;
    bool flag;
    float z,w,v;
    int first,last;
};
void __cdecl FUN_00bb6500(Element* destination,const Element& source)
{
    void* storage=destination;
    ::new(storage) Element(source);
}
}
}   // namespace f3m_00bb6500

// @f3 0x00bbdf60 (community match, verified in this file)
#include <string>
namespace f3m_00bbdf60 {
namespace task2583 {
struct Point {float x,y,z;};
struct FUN_00bbdf60 {
char kind; Point p04; float f10; std::string name; Point p30,p3c,p48;
FUN_00bbdf60(const FUN_00bbdf60& other);
};
FUN_00bbdf60::FUN_00bbdf60(const FUN_00bbdf60& a):kind(a.kind),p04(a.p04),f10(a.f10),name(a.name),p30(a.p30),p3c(a.p3c),p48(a.p48) {}
}
}   // namespace f3m_00bbdf60

// @f3 0x00ba9e40 (community match, verified in this file)
namespace task2581 {
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float threshold;
    float upper;
    int count;
};
extern State* DAT_011782b0;
struct GlobalObject_00b3f100
{
    float FUN_00bc4b40(float, float);
};
extern GlobalObject_00b3f100 DAT_011782c1;
struct Link
{
    Link* next;
    float value;
};
struct Owner
{
    bool FUN_00ba9e40(Link* link, float input);
};
// @fnv 0x00b13b50
// pdb: CIdvBranch::IsBlossom | Branch.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: pParent, fPercentOfParent
bool Owner::FUN_00ba9e40(Link* link, float input)
{
    bool result = false;
    {
        float value = input;
        if (DAT_011782b0->count == 0)
        {
            int current = 1;
            Link* index = link;
            Link* next;
            while (index != 0 && (next = index->next) != 0 && current < DAT_011782b0->count)
            {
                index = index->next;
                ++current;
            }
            if (index != 0)
                value = index->value;
        }
        if (value > DAT_011782b0->threshold)
        {
            if (DAT_011782c1.FUN_00bc4b40(0.0f, 1.0f) <= DAT_011782b0->upper)
                result = true;
        }
    }
    return result;
}

}

// @f3 0x00ba9f60 (community match, verified in this file)
namespace f3m_00ba9f60 {
namespace Task2648 {
struct SegmentEntry
{
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
    float f40;
    int unk44;
};

struct OutPair
{
    int idx;
    float t;
};

struct FUN_00b14be0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SegmentEntry* m_20;
    int m_24;
    void FUN_00ba9f60(OutPair* out, float v);
};

// @fnv 0x00b14be0
// pdb: CIdvBranch::FillBranch | Branch.obj | fnv360_0822_retail, call_gap, low
// pdb params: sBranch, fChildGrowthPos
void FUN_00b14be0_cls::FUN_00ba9f60(OutPair* out, float afValue)
{
    if (m_20 != 0 && m_24 >= 2)
    {
        out->idx = 0;
        for (int i = 1; i < m_24; ++i)
        {
            if (afValue < m_20[i].f40)
            {
                out->idx = i - 1;
                break;
            }
        }
        out->t = (afValue - m_20[out->idx].f40) / (m_20[out->idx + 1].f40 - m_20[out->idx].f40);
    }
}

}
}   // namespace f3m_00ba9f60

// @f3 0x00ba0860 (community match, verified in this file)
namespace task2649 {
typedef void* z_streamp;
typedef unsigned char Byte,Bytef,uch,uchf;
typedef unsigned short ush,ushf,Posf;
typedef unsigned long ulg;
typedef unsigned int uInt,IPos;
struct ct_data_s {union {ush freq,code;} fc; union {ush dad,len;} dl;};
struct StaticTree {const ct_data_s* tree; const int* extra; int base,elems,maxlen;};
struct tree_desc_s {ct_data_s* dyn_tree; int max_code; const StaticTree* stat_desc;};
struct State {
    z_streamp strm;      
    int   status;        
    Bytef *pending_buf;  
    ulg   pending_buf_size; 
    Bytef *pending_out;  
    int   pending;       
    int   wrap;          
    Byte  data_type;     
    Byte  method;        
    int   last_flush;    

                

    uInt  w_size;        
    uInt  w_bits;        
    uInt  w_mask;        

    Bytef *window;
    

    ulg window_size;
    

    Posf *prev;
    

    Posf *head; 

    uInt  ins_h;          
    uInt  hash_size;      
    uInt  hash_bits;      
    uInt  hash_mask;      

    uInt  hash_shift;
    

    long block_start;
    

    uInt match_length;           
    IPos prev_match;             
    int match_available;         
    uInt strstart;               
    uInt match_start;            
    uInt lookahead;              

    uInt prev_length;
    

    uInt max_chain_length;
    

    uInt max_lazy_match;

    

    int level;    
    int strategy; 

    uInt good_match;
    

    int nice_match; 

                
    
    struct ct_data_s dyn_ltree[573];   
    struct ct_data_s dyn_dtree[2*30+1]; 
    struct ct_data_s bl_tree[2*19+1];  

    struct tree_desc_s l_desc;               
    struct tree_desc_s d_desc;               
    struct tree_desc_s bl_desc;              

    ush bl_count[15+1];
    

    int heap[2*286+1];      
    int heap_len;               
    int heap_max;               
    

    uch depth[2*286+1];
    

    uchf *l_buf;          

    uInt  lit_bufsize;
    

    uInt last_lit;      

    ushf *d_buf;
    

    ulg opt_len;        
    ulg static_len;     
    uInt matches;       
    int last_eob_len;   



    ush bi_buf;
    
    int bi_valid;
    

};
extern StaticTree DAT_01068a18,DAT_01068a2c,DAT_01068a40;
static void __cdecl FUN_00b9f670(State* s) {
 int n;
 for(n=0;n<286;n++) s->dyn_ltree[n].fc.freq=0;
 for(n=0;n<30;n++) s->dyn_dtree[n].fc.freq=0;
 for(n=0;n<19;n++) s->bl_tree[n].fc.freq=0;
 s->dyn_ltree[256].fc.freq=1;
 s->opt_len=s->static_len=0L;
 s->last_lit=s->matches=0;
}
// pdb: _tr_init | trees.obj | fnv360_0822_retail, call_seq + skyrim(call_gap), high
void __cdecl _tr_init(State* s) {
 s->l_desc.dyn_tree=s->dyn_ltree;
 s->l_desc.stat_desc=&DAT_01068a18;
 s->d_desc.dyn_tree=s->dyn_dtree;
 s->d_desc.stat_desc=&DAT_01068a2c;
 s->bl_desc.dyn_tree=s->bl_tree;
 s->bl_desc.stat_desc=&DAT_01068a40;
 s->bi_buf=0;
 s->bi_valid=0;
 s->last_eob_len=8;
 FUN_00b9f670(s);
}
}

// @f3 0x00ba3730 (community match, verified in this file)
#include <exception>
#include <string>
namespace f3m_00ba3730 {
class RuntimeError : public std::exception {
    std::string message;
public:
    explicit RuntimeError(const std::string& text);
    virtual ~RuntimeError() {}
    virtual const char* what() const { return message.c_str(); }
};
// pdb: stdext::exception::_Raise | TESObject.obj | fnv360_0721_beta, call_gap, low
RuntimeError::RuntimeError(const std::string& text) : message(text) {}
}   // namespace f3m_00ba3730

// @f3 0x00bb6590 (community match, verified in this file)
namespace f3m_00bb6590 {
namespace task2657 {
struct Vector {int allocator;void* first;void* last;void* end; Vector& FUN_00bb5d10(const Vector&);Vector& operator=(const Vector& r){return FUN_00bb5d10(r);} };
struct Elem {Vector values;float f10,f14;bool b18;float f1c,f20,f24;int i28,i2c;};
struct ForwardTag {};struct NonScalarTag {};struct RangeCheckedTag {};
Elem* FUN_00bb6590(Elem* first,Elem* last,Elem* dest,ForwardTag,NonScalarTag,RangeCheckedTag){while(first!=last)*--dest=*--last;return dest;}
}
}   // namespace f3m_00bb6590

// @f3 0x00bb6430 (community match, verified in this file)
namespace f3m_00bb6430 {
namespace task2656 {
struct List {unsigned unk00;void*first;void*last;void*end;List& FUN_00bb5d10(const List&);List&operator=(const List&r){return FUN_00bb5d10(r);}};
struct Element {List list;float a,b;bool flag;float c,d,e;int f,g;};
struct ForwardTag{};struct NonscalarTag{};struct RangeCheckedTag{};
Element* __cdecl FUN_00bb6430(Element*first,Element*last,Element*dest,ForwardTag,NonscalarTag,RangeCheckedTag){for(;first!=last;++dest,++first)*dest=*first;return dest;}
}
}   // namespace f3m_00bb6430

// @f3 0x00bb6a50 (community match, verified in this file)
namespace f3m_00bb6a50 {
namespace task2682 {
struct VecTE_00b1d130
{
    unsigned int allocatorState; void* first; void* last; void* end;
    VecTE_00b1d130& FUN_00bb5fe0(const VecTE_00b1d130& that);
};
struct VecPI_00b1d5d0
{
    unsigned int allocatorState; void* first; void* last; void* end;
    VecPI_00b1d5d0& FUN_00bb6160(const VecPI_00b1d5d0& that);
};
struct FUN_00b1c7a0_cls
{
    float f00;
    float f04;
    float f08;
    VecTE_00b1d130 m0c;
    VecTE_00b1d130 m24;
    VecPI_00b1d5d0 m3c;
    VecTE_00b1d130 m54;
    VecTE_00b1d130 m6c;
    FUN_00b1c7a0_cls& FUN_00bb6a50(const FUN_00b1c7a0_cls& that);
};

// @fnv 0x00b1c7a0
// pdb: CIdvBezierSpline::operator= | FrondEngine.obj | fnv360_0822_retail, call_dedup, low
// pdb params: __that
FUN_00b1c7a0_cls& FUN_00b1c7a0_cls::FUN_00bb6a50(const FUN_00b1c7a0_cls& that)
{
    f00 = that.f00;
    f04 = that.f04;
    f08 = that.f08;
    m0c.FUN_00bb5fe0(that.m0c);
    m24.FUN_00bb5fe0(that.m24);
    m3c.FUN_00bb6160(that.m3c);
    m54.FUN_00bb5fe0(that.m54);
    m6c.FUN_00bb5fe0(that.m6c);
    return *this;
}

}
}   // namespace f3m_00bb6a50

// @f3 0x00ba1290 (community match, verified in this file)
namespace f3m_00ba1290 {
struct FUN_00c24b70 {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ~FUN_00c24b70();
};
struct FUN_00ba1290 {
    FUN_00c24b70 first;
    FUN_00c24b70 second;
    ~FUN_00ba1290();
};
FUN_00ba1290::~FUN_00ba1290() {}
}   // namespace f3m_00ba1290

// @f3 0x00ba9240 (community match, verified in this file)
namespace f3m_00ba9240 {
namespace Task2691 {
void __cdecl FUN_00c00610(char* dst, int value, int size);

class FUN_00ba9240_cls
{
  public:
    int m_00;
    char* m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    unsigned int m_18;

    void FUN_00ba9240(int offset, int flag, char value);
};

// @fnv 0x00aae180
void FUN_00ba9240_cls::FUN_00ba9240(int offset, int aiSize, char value)
{
    if (aiSize == 1)
    {
        *((m_18 >= 0x10 ? m_04 : (char*)this + 4) + offset) = value;
    }
    else
    {
        char tmp;
        FUN_00c00610((m_18 >= 0x10 ? m_04 : (char*)this + 4) + offset, tmp = value, aiSize);
    }
}

}
}   // namespace f3m_00ba9240

// @f3 0x00bb6b80 (community match, verified in this file)
namespace f3m_00bb6b80 {
namespace task2702 {
struct Input{};struct Forward:Input{};struct Bidirectional:Forward{};struct Random:Bidirectional{};struct Nonscalar{};struct Checked{};
struct Element{int a,b,c,d,e,f,g,h,i,j,k;};
Element* __cdecl FUN_00bb5ea0(Element*,Element*,Element*,Forward,Nonscalar,Checked);
Element* __cdecl FUN_00bb6b80(Element*first,Element*last,Element*dest,Random,Nonscalar,Checked){Element*result=dest+(last-first);FUN_00bb5ea0(first,last,dest,Forward(),Nonscalar(),Checked());return result;}
}
}   // namespace f3m_00bb6b80

// @f3 0x00bb5220 (community match, verified in this file)
namespace f3m_00bb5220 {
namespace Task2700 {
struct InputTag {}; struct ForwardTag : InputTag {}; struct BidiTag : ForwardTag {}; struct RandomTag : BidiTag {};
struct NonscalarTag {}; struct RangeTag {};
struct Element {
 int unk00,unk04,unk08,unk0c,unk10,unk14;
};
Element* __cdecl FUN_00bb4820(Element*,Element*,Element*,ForwardTag,NonscalarTag,RangeTag);
Element* __cdecl FUN_00bb5220(Element* first,Element* last,Element* dest,RandomTag,NonscalarTag,RangeTag) {
 Element* result=dest+(last-first);
 FUN_00bb4820(first,last,dest,ForwardTag(),NonscalarTag(),RangeTag());
 return result;
}
}
}   // namespace f3m_00bb5220

// @f3 0x00bb6db0 (community match, verified in this file)
#include <iterator>
namespace f3m_00bb6db0 {
struct Element2680 {
 unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
};
Element2680* __cdecl FUN_00bb6590(Element2680*,Element2680*,Element2680*,std::forward_iterator_tag,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
Element2680* __cdecl FUN_00bb6db0(Element2680* first,Element2680* last,Element2680* dest,std::random_access_iterator_tag,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag) {
 Element2680* result=dest-(last-first);
 FUN_00bb6590(first,last,dest,std::forward_iterator_tag(),std::_Nonscalar_ptr_iterator_tag(),std::_Range_checked_iterator_tag());
 return result;
}
}   // namespace f3m_00bb6db0

// @f3 0x00baab10 (community match, verified in this file)
namespace f3m_00baab10 {
namespace Task2712 {
struct Element { int x,y,z; };
inline Element* CopyLoop(Element* first,Element* last,Element* dest) {
 while(first!=last) *--dest=*--last;
 return dest;
}
Element* __cdecl FUN_00baab10(Element* first,Element* last,Element* dest) {
 Element* result=dest-(last-first);
 CopyLoop(first,last,dest);
 return result;
}
}
}   // namespace f3m_00baab10

// @f3 0x00bbd1e0 (community match, verified in this file)
namespace f3m_00bbd1e0 {
namespace locale2731 {
struct FUN_00bff149 {
 int kind;
 explicit FUN_00bff149(int);
 void FUN_00bff16a();
 ~FUN_00bff149() { FUN_00bff16a(); }
};
struct Facet {
 unsigned int refs;
 virtual ~Facet();
 Facet* decref() {
  FUN_00bff149 lock(0);
  if(0<refs && refs<(unsigned int)-1) --refs;
  return refs==0?this:0;
 }
};
struct FUN_00bbd1e0 {
 Facet* ptr;
 ~FUN_00bbd1e0();
};
// pdb: std::locale::`scalar deleting destructor' | algs.obj | fnv360_0721_beta, callee_sim, low, conflict (skyrim: std::locale::~locale)
FUN_00bbd1e0::~FUN_00bbd1e0() {
 if(ptr) delete ptr->decref();
}
}
}   // namespace f3m_00bbd1e0

// @f3 0x00bbd7b0 (community match, verified in this file)
#include <exception>
#include <string>
#include <new>
namespace f3m_00bbd7b0 {
namespace f3_2751 {
class Error : public std::exception {
std::string message;
public:
virtual ~Error() {}
virtual const char* what() const { return message.c_str(); }
void* FUN_00bbd7b0(unsigned int flags);
};
// pdb: std::ios_base::failure::`scalar deleting destructor' | TESScriptFunctions_Console.obj | tesv_win, vtable_prefix, medium
void* Error::FUN_00bbd7b0(unsigned int flags) {
this->Error::~Error();
if(flags&1) ::operator delete(this);
return this;
}
}
}   // namespace f3m_00bbd7b0

// @f3 0x00bb5780 (community match, verified in this file)
namespace f3m_00bb5780 {
namespace task2733 {
struct Elem {unsigned int f00,f04,f08,f0c,f10,f14;};
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Elem* __cdecl FUN_00bb4690(unsigned int,const void*);
struct Vector {unsigned int allocatorState; Elem* first; Elem* last; Elem* limit; bool FUN_00bb5780(unsigned int);};
// pdb: std::vector<CVec,std::allocator<CVec> >::_Buy | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: _Capacity
bool Vector::FUN_00bb5780(unsigned int capacity) {
 first=0; last=0; limit=0;
 if(capacity==0) return false;
 else if((unsigned int)-1/sizeof(Elem)<capacity) FUN_00bc5f00();
 else {first=FUN_00bb4690(capacity,0);last=first;limit=first+capacity;}
 return true;
}
}
}   // namespace f3m_00bb5780

// @f3 0x00bbef90 (community match, verified in this file)
namespace f3m_00bbef90 {
namespace copy2742 {
struct Element {
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
 Element& FUN_00bbe9c0(const Element&);
 Element& operator=(const Element& other) { return FUN_00bbe9c0(other); }
};
__forceinline Element* copyForward(Element* first,Element* last,Element* dest) {
 for(;first!=last;++dest,++first) *dest=*first;
 return dest;
}
Element* FUN_00bbef90(Element* first,Element* last,Element* dest) {
 Element* result=dest+(last-first);
 copyForward(first,last,dest);
 return result;
}
}

}   // namespace f3m_00bbef90

// @f3 0x00bb4630 (community match, verified in this file)
#include <vector>
namespace f3m_00bb4630 {

struct Elem48_bb4630 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};

struct Owner_bb4630 {
    std::vector<Elem48_bb4630> items;
    Elem48_bb4630* FUN_00bb4630(unsigned int index);
};

// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::operator[] | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _Pos
Elem48_bb4630* Owner_bb4630::FUN_00bb4630(unsigned int index) {
    return &items[index];
}
}   // namespace f3m_00bb4630

// @f3 0x00baac40 (community match, verified in this file)
#include <new>
namespace f3m_00baac40 {
namespace f3_2767 {
struct Record { int a,b,c,d,e,f; ~Record(); };
// @fnv 0x00b25a90
Record* __cdecl FUN_00baac40(Record* pkCurrentObject, Record* pkLast,
                                            Record* pkDest)
{
    Record* pkNext = pkDest;
    try
    {
        for (; pkCurrentObject != pkLast; ++pkDest, ++pkCurrentObject)
        {
            void* pvWhere = pkDest;
            ::new (pvWhere) Record(*pkCurrentObject);
        }
    }
    catch (...)
    {
        for (; pkNext != pkDest; ++pkNext)
            pkNext->~Record();
        throw;
    }
    return pkDest;
}

}
}   // namespace f3m_00baac40

// @f3 0x00baad40 (community match, verified in this file)
namespace f3m_00baad40 {
namespace f3_2773 {
struct Node;
struct Comparator { bool operator()(const Node*,const Node*) const; };
void FUN_00baabd0(Node**,int,int,Node*,Comparator);
// pdb: std::vector<int,std::allocator<int> >::_Reserve | Branch.obj | fnv360_0822_retail, objrun, medium
// pdb params: _Count
void FUN_00baad40(Node** first,Node** last,Comparator pred,int*,Node**) {
int bottom=last-first;
for(int hole=bottom/2;0<hole;) {
--hole;
FUN_00baabd0(first,hole,bottom,first[hole],pred);
}
}
}

}   // namespace f3m_00baad40

// @f3 0x00bb0c40 (community match, verified in this file)
namespace f3m_00bb0c40 {
namespace task2756 {
bool __cdecl FUN_00ba1920();
struct Floats {unsigned int allocatorState; float* first; float* last; float* end; void FUN_0058da30(const float&);};
struct Owner {
 int field000;
 int field004;
 int field008;
 int field00c;
 int field010;
 int field014;
 int field018;
 int field01c;
 int field020;
 int field024;
 int field028;
 int field02c;
 int field030;
 int field034;
 int field038;
 int field03c;
 int field040;
 int field044;
 int field048;
 int field04c;
 int field050;
 int field054;
 int field058;
 int field05c;
 int field060;
 int field064;
 int field068;
 int field06c;
 int field070;
 int field074;
 int field078;
 int field07c;
 int field080;
 int field084;
 int field088;
 int field08c;
 int field090;
 int field094;
 int field098;
 int field09c;
 int field0a0;
 int field0a4;
 int field0a8;
 int field0ac;
 int field0b0;
 int field0b4;
 int field0b8;
 int field0bc;
 int field0c0;
 int field0c4;
 int field0c8;
 int field0cc;
 int field0d0;
 int field0d4;
 int field0d8;
 int field0dc;
 int field0e0;
 int field0e4;
 Floats values; void FUN_00bb0c40(const float&);
};
// @fnv 0x00b304f0
// pdb: CIndexedGeometry::AddVertexTexCoord1 | IndexedGeometry.obj | fnv360_0721_beta, objrun, medium
// pdb params: pTexCoord
void Owner::FUN_00bb0c40(const float& afValue)
{
    float f;
    values.FUN_0058da30(afValue);
    if (FUN_00ba1920())
    {
        f = -(&afValue)[1];
        values.FUN_0058da30(f);
    }
    else
    {
        values.FUN_0058da30((&afValue)[1]);
    }
}

}
}   // namespace f3m_00bb0c40

// @f3 0x00bbd3c0 (community match, verified in this file)
namespace f3m_00bbd3c0 {
namespace f3_2785 {
struct VectorData {
float data[5]; int count;
float FUN_00bbd320();
void FUN_00bbd3c0();
};
void VectorData::FUN_00bbd3c0() {
float divisor=FUN_00bbd320();
if(divisor!=0.0) {
for(int i=0;i<count;++i) data[i]=data[i]/divisor;
}
}
}
}   // namespace f3m_00bbd3c0

// @f3 0x00bb0980 (community match, verified in this file)
namespace f3m_00bb0980 {
struct Fn00bb0980Sub
{
    void FUN_00babf00(int* value);
};

struct Fn00bb0980Owner
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
    Fn00bb0980Sub unk58;

    int FUN_00baeba0(int value);
    void FUN_00bb0980(int value);
};

void Fn00bb0980Owner::FUN_00bb0980(int value)
{
    value = FUN_00baeba0(value);
    unk58.FUN_00babf00(&value);
}
}   // namespace f3m_00bb0980

// @f3 0x00bbe940 (community match, verified in this file)
namespace f3m_00bbe940 {
namespace f3_2737 {
struct Row {
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
};
__declspec(noreturn) void FUN_00bc5f00();
Row* FUN_00bbdb80(unsigned int,Row*);
struct Vector {
unsigned char allocator; Row* first; Row* last; Row* end;
bool FUN_00bbe940(unsigned int);
};
// pdb: std::vector<CIdvBranch *,std::allocator<CIdvBranch *> >::operator[] | TreeEngine.obj | fnv360_0822_debug, objrun_open, low
// pdb params: _Pos
bool Vector::FUN_00bbe940(unsigned int capacity) {
first=0,last=0,end=0;
if(capacity==0) return false;
else if((unsigned int)(-1)/sizeof(Row)<capacity) FUN_00bc5f00();
else {
first=FUN_00bbdb80(capacity,(Row*)0);
last=first; end=first+capacity;
}
return true;
}
}
}   // namespace f3m_00bbe940

// @f3 0x00bbd230 (community match, verified in this file)
namespace f3m_00bbd230 {
namespace Task2771 {
struct Lock {
 int locktype;
 void FUN_00bff149(int);void FUN_00bff16a();
 explicit Lock(int n) { FUN_00bff149(n); }
 ~Lock() { FUN_00bff16a(); }
};
struct Facet {
 virtual ~Facet();unsigned int refs;
 void Incref() { Lock lock(0);if(refs<(unsigned int)-1) ++refs; }
};
struct Locale {
 Facet* ptr;
 Locale(const Locale& other):ptr(other.ptr) { ptr->Incref(); }
 ~Locale();
};
struct Buffer {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 Locale* locale;
 Locale FUN_00bbd230() const;
};
// pdb: std::locale::id::operator unsigned int | TESScriptFunctions_Console.obj | tesv_win, objrun_prop, low
Locale Buffer::FUN_00bbd230() const {return *locale;}
}
}   // namespace f3m_00bbd230

// @f3 0x00bbd190 (community match, verified in this file)
namespace f3m_00bbd190 {
namespace task2780 {
struct CB770Lockit { int kind; void FUN_00bff149(int) throw();void FUN_00bff16a() throw();CB770Lockit(int k) throw(){FUN_00bff149(k);}~CB770Lockit() throw(){FUN_00bff16a();} };
struct CB770Facet { virtual void v0();unsigned m_uiRefs;CB770Facet* FUN_00bbd190(); };
// @fnv 0x00acb770
// pdb: std::locale::facet::_Incref | algs.obj | fnv360_0721_beta, caller_sim, low, conflict (skyrim: std::locale::facet::_Decref)
CB770Facet* CB770Facet::FUN_00bbd190()
{
    CB770Lockit kLock(0);
    if (0 < m_uiRefs && m_uiRefs < (unsigned int)(-1))
        --m_uiRefs;
    return m_uiRefs == 0 ? this : 0;
}
}
}   // namespace f3m_00bbd190

// @f3 0x00baa280 (community match, verified in this file)
namespace f3m_00baa280 {
namespace Task2784 {
void __cdecl FUN_00c01e8b();
struct Element {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50;};
struct Vector {
 int allocator;
 Element* first;Element* last;Element* end;
 unsigned int size() const { return first==0 ? 0 : last-first; }
 Element& FUN_00baa280(unsigned int index);
};
Element& Vector::FUN_00baa280(unsigned int index) {
 if(!(index<size())) FUN_00c01e8b();
 return first[index];
}
}
}   // namespace f3m_00baa280

// @f3 0x00bbead0 (community match, verified in this file)
#include <string>
namespace f3m_00bbead0 {
namespace f3_2770 {
struct Row {
int field00,field04,field08,field0c,field10;
std::string text;
int field30,field34,field38,field3c,field40,field44,field48,field4c,field50;
};
struct Allocator {};
struct NonscalarTag {};
// pdb: std::_Destroy_range<std::allocator<SIdvLeafTexture> > | TreeEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: _First, _Last, _Al, __formal
void FUN_00bbead0(Row* first,Row* last,Allocator&,NonscalarTag) {
for(;first!=last;++first) first->~Row();
}
}
}   // namespace f3m_00bbead0

// @f3 0x00bbbb40 (community match, verified in this file)
namespace f3m_00bbbb40 {
struct Elem16_bbbb40 {
    f3m_00bba9f0::vec48_bba9f0::Vec48 vec;
};
void __cdecl FUN_00bbbb40(Elem16_bbbb40* first, Elem16_bbbb40* last, const f3m_00bba9f0::vec48_bba9f0::Vec48& value)
{
    if (first != last) {
        do {
            first->vec.FUN_00bba9f0(value);
            ++first;
        } while (first != last);
    }
}
}   // namespace f3m_00bbbb40

// @f3 0x00baa240 (community match, verified in this file)
namespace f3m_00baa240 {
namespace task2792 {
struct Link {Link*next;float value;};
// @fnv 0x00b15110
float __cdecl FUN_00baa240(Link* link)
{
    float ratio;
    Link* rest;
    if (link == 0 || (rest = link->next) == 0)
    {
        return 0.0f;
    }
    {
        Link* next = link->next;
        ratio = FUN_00baa240(next);
        float b = link->value;
        float ret = (1.0f - ratio) * b + ratio;
        return ret;
    }
}
}
}   // namespace f3m_00baa240

// @f3 0x00bb0fa0 (community match, verified in this file)
namespace f3m_00bb0fa0 {
namespace VectorClear2793 {
void __cdecl FUN_00c01e8b();
class Vector;
struct Iterator {
 Vector* owner; unsigned* current;
 Iterator(unsigned* p, Vector* v):owner(v),current(p) {}
};
class Vector {
public:
 unsigned unk00; unsigned* first; unsigned* last; unsigned* endStorage;
 Iterator begin() {
  unsigned* p=first;
  if(p>last) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator end() {
  unsigned* p=last;
  if(first>p) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator FUN_00bb0e80(Iterator,Iterator);
 void FUN_00bb0fa0();
};
// pdb: std::vector<std::vector<unsigned short,std::allocator<unsigned short> >,std::allocator<std::vector<unsigned short,std::allocator<unsigned short> > > >::clear | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
void Vector::FUN_00bb0fa0() { FUN_00bb0e80(begin(),end()); }
}
}   // namespace f3m_00bb0fa0

// @f3 0x00bb5600 (community match, verified in this file)
namespace f3m_00bb5600 {
namespace VectorClear2794 {
void __cdecl FUN_00c01e8b();
class Vector;
struct Iterator {
 Vector* owner; unsigned* current;
 Iterator(unsigned* p, Vector* v):owner(v),current(p) {}
};
class Vector {
public:
 unsigned unk00; unsigned* first; unsigned* last; unsigned* endStorage;
 Iterator begin() {
  unsigned* p=first;
  if(p>last) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator end() {
  unsigned* p=last;
  if(first>p) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator FUN_00bb5520(Iterator,Iterator);
 void FUN_00bb5600();
};
void Vector::FUN_00bb5600() { FUN_00bb5520(begin(),end()); }
}
}   // namespace f3m_00bb5600

// @f3 0x00bba4a0 (community match, verified in this file)
namespace f3m_00bba4a0 {
namespace VectorClear0342 {
void __cdecl FUN_00c01e8b();
class Vector;
struct Iterator {
 Vector* owner; unsigned* current;
 Iterator(unsigned* p, Vector* v):owner(v),current(p) {}
};
class Vector {
public:
 unsigned unk00; unsigned* first; unsigned* last; unsigned* endStorage;
 Iterator begin() {
  unsigned* p=first;
  if(p>last) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator end() {
  unsigned* p=last;
  if(first>p) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator FUN_00bb9d60(Iterator,Iterator);
 void FUN_00bba4a0();
};
void Vector::FUN_00bba4a0() { FUN_00bb9d60(begin(),end()); }
}
}   // namespace f3m_00bba4a0

// @f3 0x00bb8db0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb8db0 {
namespace fill2805 {
struct Element {
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
 ~Element();
};
void __cdecl FUN_00bb6350(Element*,unsigned int,const Element&,std::allocator<Element>&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
struct Vector {
 std::allocator<Element> allocator;
 Element* FUN_00bb8db0(Element*,unsigned int,const Element&);
};
Element* Vector::FUN_00bb8db0(Element* ptr,unsigned int count,const Element& value) {
 FUN_00bb6350(ptr,count,value,allocator,std::_Ptr_cat(ptr,ptr),std::_Range_checked_iterator_tag());
 return ptr+count;
}
}
}   // namespace f3m_00bb8db0

// @f3 0x00bb91e0 (community match, verified in this file)
namespace f3m_00bb91e0 {
namespace VectorClear2795 {
void __cdecl FUN_00c01e8b();
class Vector;
struct Iterator {
 Vector* owner; unsigned* current;
 Iterator(unsigned* p, Vector* v):owner(v),current(p) {}
};
class Vector {
public:
 unsigned unk00; unsigned* first; unsigned* last; unsigned* endStorage;
 Iterator begin() {
  unsigned* p=first;
  if(p>last) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator end() {
  unsigned* p=last;
  if(first>p) FUN_00c01e8b();
  return Iterator(p,this);
 }
 Iterator FUN_00bb8d50(Iterator,Iterator);
 void FUN_00bb91e0();
};
// pdb: std::vector<SFrondTexture,std::allocator<SFrondTexture> >::clear | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
void Vector::FUN_00bb91e0() { FUN_00bb8d50(begin(),end()); }
}

}   // namespace f3m_00bb91e0

// @f3 0x00bb9940 (community match, verified in this file)
#include <iterator>
namespace f3m_00bb9940 {
struct Element2801 { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; };
struct Allocator2801 {};
void __cdecl FUN_00bb8ec0(Element2801*,unsigned,const Element2801&,Allocator2801&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
struct Vector2801 {
 Allocator2801 allocator;
 Element2801* FUN_00bb9940(Element2801*,unsigned,const Element2801&);
};
Element2801* Vector2801::FUN_00bb9940(Element2801* dest,unsigned count,const Element2801& value) {
 FUN_00bb8ec0(dest,count,value,allocator,std::_Ptr_cat(dest,dest),std::_Range_checked_iterator_tag());
 return dest+count;
}
}   // namespace f3m_00bb9940

// @f3 0x00ba9c20 (community match, verified in this file)
namespace f3m_00ba9c20 {
namespace task2822 {
struct Vector3 {float x,y,z;Vector3(){x=y=z=0.0f;}};
struct Matrix3 {float m00,m01,m02,m10,m11,m12,m20,m21,m22;Matrix3():m00(1),m01(0),m02(0),m10(0),m11(1),m12(0),m20(0),m21(0),m22(1){} };
struct FUN_00ba9c20 {Vector3 direction,position;float scale;Matrix3 rotation;float extent,weight;FUN_00ba9c20();};
FUN_00ba9c20::FUN_00ba9c20(){}
}
}   // namespace f3m_00ba9c20

// @f3 0x00bbda40 (community match, verified in this file)
namespace f3m_00bbda40 {
class S00bbda40 {
public:
    char pad00[0x4C];
    float unk4C;
    float unk50;
    void FUN_00bbda40(float a, float b);
};

// pdb: CTreeEngine::SetSize | TreeEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: fSize, fVariance
void S00bbda40::FUN_00bbda40(float a, float b)
{
    this->unk4C = a;
    this->unk50 = b;
}
}   // namespace f3m_00bbda40

// @f3 0x00baa4e0 (community match, verified in this file)
#include <math.h>
namespace f3m_00baa4e0 {
namespace task2888 {
struct Point { float x,y,z; float FUN_00baa4e0(const Point&); };
float Point::FUN_00baa4e0(const Point& p) {
float value=p.x*x+p.y*y+p.z*z;
if(value < -1.0f) value=-1.0f;
if(value > 1.0f) value=1.0f;
return (float)acos(value);
}
}
}   // namespace f3m_00baa4e0

// @f3 0x00ba6b90 (community match, verified in this file)
namespace f3m_00ba6b90 {
namespace task2908 {
struct Lod {int unk00,unk04,unk08,unk0c;float value10,value14;};
struct Text {void FUN_0042f100(const char*,unsigned);};extern Text DAT_01068a70;
struct Owner {Lod* root;
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
Lod* lod;void FUN_00ba6b90(float);};
// pdb: CSpeedTreeRT::SetLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: fLevel
void Owner::FUN_00ba6b90(float level){if(level>=0.0 && level<=1.0){if(lod)lod->value10=level;else root->value14=level;}else DAT_01068a70.FUN_0042f100("SetLodLevel() expects a value in the range of 0.0 to 1.0",56);}
}
}   // namespace f3m_00ba6b90

// @f3 0x00ba1310 (community match, verified in this file)
namespace f3m_00ba1310 {
namespace Task2900 {
struct Vec {float x,y,z;Vec(float a,float b,float c):x(a),y(b),z(c){}};
struct Data {int header;Vec value;};
struct Owner {Data* primary;int pad[12];Data* alternate;void FUN_00ba1310(float,float,float);};
// pdb: CSpeedTreeRT::SetTreePosition | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
// pdb params: x, y, z
void Owner::FUN_00ba1310(float a,float b,float c) {
 Data* target=alternate; if(target){target->value.x=a;target->value.y=b;target->value.z=c;}
 else {Vec temp(a,b,c);primary->value=temp;}
}
}

}   // namespace f3m_00ba1310

// @f3 0x00bae370 (community match, verified in this file)
namespace f3m_00bae370 {
namespace task2914 {
struct Object {float unk00,f04,unk08,unk0c,unk10,unk14,f18,f1c,f20,f24;void FUN_00bae370(const float*);};
// pdb: CWindEngine::Init | WindEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: cWindInfo
void Object::FUN_00bae370(const float* p){f18=p[0];f1c=p[1];f20=8.0*p[6]*f1c;f24=180.0*p[6]*f18;f04=p[6];}
}
}   // namespace f3m_00bae370

// @f3 0x00bb51e0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb51e0 {
namespace task2920 {
struct Leaf {float x,y,z,w;float a,b,c,d;float e,f,g,h;};
struct Iterator : std::vector<Leaf>::iterator {std::vector<Leaf>::iterator FUN_00bb51e0(int) const;};
std::vector<Leaf>::iterator Iterator::FUN_00bb51e0(int n) const {return *this+n;}
}
}   // namespace f3m_00bb51e0

// @f3 0x00ba1f20 (community match, verified in this file)
namespace f3_2899 {
extern const float DAT_00db38b8;
struct Primary { unsigned int unk00,unk04,unk08,unk0c,unk10; float level; };
struct Optional { unsigned int unk00,unk04,unk08,unk0c; float level; };
struct Levels {
Primary* primary;
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
Optional* optional;
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
unsigned short count;
float GetLevel() { float level=-1.0f; if(optional) level=optional->level; else level=primary->level; return level; }
short FUN_00ba1f20(float);
};
// pdb: CSpeedTreeRT::GetDiscreteFrondLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: fLodLevel
short Levels::FUN_00ba1f20(float level) {
short index=0;
if(level==-1.0f) level=GetLevel();
int size=count;
index=(short)((1.0-level)*size);
if(index==size) --index;
return index;
}
}

// @f3 0x00bb5ea0 (community match, verified in this file)
namespace f3m_00bb5ea0 {
namespace f3bb5ea0 {
struct String {
    int allocator;
    union { char* pointer; char buffer[16]; } data;
    unsigned int size,capacity;
    String& FUN_0042eff0(const String&,unsigned int,unsigned int);
    String& operator=(const String& rhs) { return FUN_0042eff0(rhs,0,(unsigned int)-1); }
};
struct Element { String name; float x,y,z,w; };
Element* __cdecl FUN_00bb5ea0(Element* first,Element* last,Element* dest) {
    for (;first!=last;++dest,++first) *dest=*first;
    return dest;
}
}
}   // namespace f3m_00bb5ea0

// @f3 0x00bb8e80 (community match, verified in this file)
namespace f3m_00bb8e80 {
namespace Task2922 {
void __cdecl FUN_00401010(void*);
struct Entry {
 unsigned int allocator;
 void* first;
 void* last;
 void* end;
 unsigned int rest[8];
 ~Entry() { tidy(); }
 void tidy() { if(first) FUN_00401010(first); first=0;last=0;end=0; }
};
template<class T> inline void destroy(T* p) {p->~T();}
struct Alloc {void destroy(Entry* p) {Task2922::destroy(p);}};
struct Nonscalar {};
// pdb: std::_Destroy_range<std::allocator<SFrondGuide> > | FrondEngine.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _First, _Last, _Al
void __cdecl FUN_00bb8e80(Entry* first, Entry* last, Alloc& al, Nonscalar) {
 for(;first!=last;++first) al.destroy(first);
}
}
}   // namespace f3m_00bb8e80

// @f3 0x00bab1a0 (community match, verified in this file)
#include <string>
namespace f3m_00bab1a0 {
namespace f3m_00bab1a0 {
struct Object {
    unsigned unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C;
    unsigned unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C;
    unsigned unk40,unk44,unk48,unk4C,unk50,unk54,unk58;
    Object(const std::string& name);
};
struct Reader {
    std::string FUN_00ba9460();
    Object* CTreeFileAccess_ParseBranchParameter();
};
// pdb: CTreeFileAccess::ParseBranchParameter | Branch.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
Object* Reader::CTreeFileAccess_ParseBranchParameter()
{
    return new Object(FUN_00ba9460());
}
}
}   // namespace f3m_00bab1a0

// @f3 0x00ba9700 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e31f80;
namespace f3m_00ba9700 {

namespace f3m_00ba9700 {
namespace task1533 {

struct Matrix {
    float m[9];
    Matrix FUN_00ba9610(const Matrix&);
    void FUN_00ba9700(float);
};

void Matrix::FUN_00ba9700(float angle) {
    Matrix rotation;
    float cosine=(float)cos((float)(angle/DAT_00e31f80));
    float sine=(float)sin((float)(angle/DAT_00e31f80));
    rotation.m[0]=cosine;
    rotation.m[1]=0.0f;
    rotation.m[2]=-sine;
    rotation.m[3]=0.0f;
    rotation.m[4]=1.0f;
    rotation.m[5]=0.0f;
    rotation.m[6]=sine;
    rotation.m[7]=0.0f;
    rotation.m[8]=cosine;
    *this=rotation.FUN_00ba9610(*this);
}

}
}
}   // namespace f3m_00ba9700

// @f3 0x00bae3b0 (community match, verified in this file)
namespace f3m_00bae3b0 {
struct State00bae3b0 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int first, second;
    void FUN_00bae3b0(unsigned int a, unsigned int b);
};
// pdb: CWindEngine::SetLocalMatrices | WindEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: nStartingMatrix, nMatrixSpan
void State00bae3b0::FUN_00bae3b0(unsigned int a, unsigned int b) {
    first = a;
    second = b;
}
}   // namespace f3m_00bae3b0

// @f3 0x00baa310 (community match, verified in this file)
namespace f3m_00baa310 {
struct State00baa310 {
    unsigned int unk00;
    int* begin;
    int* end;
    int FUN_00baa310() const;
};
int State00baa310::FUN_00baa310() const {
    if (!begin)
        return 0;
    return static_cast<int>(end - begin);
}
}   // namespace f3m_00baa310

// @f3 0x00bbdb60 (community match, verified in this file)
namespace f3m_00bbdb60 {
struct SourceView_ba92d0 { unsigned int FUN_00ba92d0(); };
struct ReceiverView_bbdb60 {
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int value54;
    void FUN_00bbdb60(SourceView_ba92d0* source);
};
// pdb: CTreeEngine::ParseFlareSeed | TreeEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: cFile
void ReceiverView_bbdb60::FUN_00bbdb60(SourceView_ba92d0* source) { value54 = source->FUN_00ba92d0(); }
}   // namespace f3m_00bbdb60

// @f3 0x00ba9530 (community match, verified in this file)
extern char DAT_00ea7c04;
namespace f3m_00ba9530 {
struct State00ba9530 {
    void* table;
    float x, y, z;
    State00ba9530* FUN_00ba9530();
};
// pdb: CIdvCamera::CIdvCamera | Camera.obj | fnv360_0822_retail, call_seq, medium
State00ba9530* State00ba9530::FUN_00ba9530() {
    x = 0.0f;
    table = &DAT_00ea7c04;
    y = 0.0f;
    z = 0.0f;
    return this;
}
}   // namespace f3m_00ba9530

// @f3 0x00bafeb0 (community match, verified in this file)
void f3m_00bb1460::vec16_bb1460::Vec16::FUN_00bafeb0(Elem16* from, Elem16* to)
{
    FUN_00baf710(from, to, *this, PtrCategory(from, to));
}

// @f3 0x00bbf9c0 (community match, verified in this file)
namespace f3m_00bbf9c0 {
struct Element00bbf9c0 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50;
};
struct Category00bbf9c0 {};
inline Category00bbf9c0 PtrCategory00bbf9c0(Element00bbf9c0*, Element00bbf9c0*) {
    Category00bbf9c0 category;
    return category;
}
struct Allocator00bbf9c0 {
    void FUN_00bbf9c0(Element00bbf9c0* first, Element00bbf9c0* last);
};
void __cdecl FUN_00bbead0(Element00bbf9c0*, Element00bbf9c0*, Allocator00bbf9c0&, Category00bbf9c0);
void Allocator00bbf9c0::FUN_00bbf9c0(Element00bbf9c0* first, Element00bbf9c0* last) {
    FUN_00bbead0(first, last, *this, PtrCategory00bbf9c0(first, last));
}
}   // namespace f3m_00bbf9c0

// @f3 0x00ba9560 (community match, verified in this file)
namespace f3m_00ba9560 {
struct Vector00ba9560 { float x, y, z; };
struct State00ba9560 {
    void* table;
    Vector00ba9560 vector;
    State00ba9560* FUN_00ba9560(const State00ba9560* other);
};
// pdb: CIdvCamera::operator= | Camera.obj | fnv360_0822_retail, vtable, medium
// pdb params: cRight
State00ba9560* State00ba9560::FUN_00ba9560(const State00ba9560* other) {
    if (other != this)
        vector = other->vector;
    return this;
}
}   // namespace f3m_00ba9560

// @f3 0x00bb54f0 (community match, verified in this file)
namespace f3m_00bb54f0 {
struct Element_bb54f0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void FUN_00c24b70();
};
struct RangeOwner_bb54f0 {
    void FUN_00bb54f0(Element_bb54f0* first, Element_bb54f0* last);
};
void RangeOwner_bb54f0::FUN_00bb54f0(Element_bb54f0* first, Element_bb54f0* last)
{
    while (first != last) {
        first->FUN_00c24b70();
        ++first;
    }
}
}   // namespace f3m_00bb54f0

// @f3 0x00bb03b0 (community match, verified in this file)
namespace f3m_00bb03b0 {
typedef f3m_00bafd80::fo3_bafd80::UIntVector Vector_bb03b0;
void __cdecl FUN_00bb03b0(Vector_bb03b0* first, Vector_bb03b0* last, const Vector_bb03b0& value)
{
    while (first != last) {
        first->FUN_00bafd80(value);
        ++first;
    }
}
}   // namespace f3m_00bb03b0

// @f3 0x00ba92d0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba92d0 {
struct Reader_ba92d0 {
    unsigned int offset;
    std::vector<char> data;
    unsigned int FUN_00ba92d0();
};
// pdb: CTreeFileAccess::ParseInt | FileAccess.obj | fnv360_0822_retail, call_dedup, medium
unsigned int Reader_ba92d0::FUN_00ba92d0()
{
    unsigned int index = offset;
    char* current = &data[index];
    offset += 4;
    return *(unsigned int*)current;
}
}   // namespace f3m_00ba92d0

// @f3 0x00ba1990 (community match, verified in this file)
namespace f3m_00ba1990 {
namespace Task2934 {
void __cdecl FUN_00c01e8b();
struct Element {unsigned int values[7];};
struct Vector {
 unsigned int allocator;
 Element* first;
 Element* last;
 Element* end;
 Element& FUN_00ba1990(unsigned int index);
 unsigned int size() const {return first ? (unsigned int)(last-first):0;}
};
// pdb: std::vector<SShape,std::allocator<SShape> >::operator[] | SpeedTreeRT.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: _Pos
Element& Vector::FUN_00ba1990(unsigned int index) {
 if(index>=size()) FUN_00c01e8b();
 return first[index];
}
}
}   // namespace f3m_00ba1990

// @f3 0x00bb9080 (community match, verified in this file)
namespace f3m_00bb9080 {
struct MedianEntry2923 { unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20; float priority; unsigned unk28,unk2c; };
struct MedianPred2923 {};
void __cdecl FUN_00bb6e10(MedianEntry2923*,MedianEntry2923*,MedianEntry2923*,MedianPred2923);
void __cdecl FUN_00bb9080(MedianEntry2923* first, MedianEntry2923* middle, MedianEntry2923* last, MedianPred2923 comp) {
    if (40 < last-first) {
        unsigned step = (last-first+1)/8;
        FUN_00bb6e10(first, first+step, first+2*step, comp);
        FUN_00bb6e10(middle-step, middle, middle+step, comp);
        FUN_00bb6e10(last-2*step, last-step, last, comp);
        FUN_00bb6e10(first+step, middle, last-step, comp);
    } else FUN_00bb6e10(first,middle,last,comp);
}
}   // namespace f3m_00bb9080

// @f3 0x00bbbf50 (community match, verified in this file)
#include <iterator>
namespace f3m_00bbbf50 {
namespace task2936 {
struct Element {int a,b,c,d;};
void __cdecl FUN_00bbbdb0(Element*,Element*,Element*,std::forward_iterator_tag,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
Element* FUN_00bbbf50(Element* first,Element* last,Element* dest,std::random_access_iterator_tag,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag){Element*result=dest-(last-first);FUN_00bbbdb0(first,last,dest,std::forward_iterator_tag(),std::_Ptr_cat(first,dest),std::_Range_checked_iterator_tag());return result;}
}
}   // namespace f3m_00bbbf50

// @f3 0x00bb9b60 (community match, verified in this file)
namespace f3m_00bb9b60 {
struct Record2935 { void* proxy; void* first; void* last; void* end; };
struct InputTag2935 {};
struct ForwardTag2935 : InputTag2935 {};
struct SwapMoveTag2935 {};
struct CheckedTag2935 {};
void __cdecl FUN_00bb9030(Record2935*,Record2935*,Record2935*,ForwardTag2935,SwapMoveTag2935,CheckedTag2935);
Record2935* __cdecl FUN_00bb9b60(Record2935* first,Record2935* last,Record2935* dest) {
    SwapMoveTag2935 move;
    Record2935* result=dest-(last-first);
    FUN_00bb9030(first,last,dest,ForwardTag2935(),move,CheckedTag2935());
    return result;
}
}   // namespace f3m_00bb9b60

// @f3 0x00ba9300 (community match, verified in this file)
#include <vector>
namespace f3m_00ba9300 {
struct Reader00ba9300 {
    unsigned int offset;
    std::vector<char> data;
    unsigned int FUN_00ba9300();
};
// pdb: CTreeFileAccess::ParseLong | FileAccess.obj | fnv360_0822_retail, call_gap_sim, low
unsigned int Reader00ba9300::FUN_00ba9300() {
    unsigned int index = offset;
    char* current = &data[index];
    offset += 8;
    return *reinterpret_cast<unsigned int*>(current);
}
}   // namespace f3m_00ba9300

// @f3 0x00bab3c0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb5fe0 {
namespace Slot1VectorBB {
Element* __cdecl FUN_00baac40(Element*, Element*, Element*, Vector&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Element* Vector::FUN_00bab3c0(Element* first, Element* last, Element* dest)
{
    return FUN_00baac40(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}
}
}

// @f3 0x00bb10d0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb10d0 {
struct Elem00bb10d0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct Alloc00bb10d0 {
    Elem00bb10d0* FUN_00bb10d0(Elem00bb10d0* first, Elem00bb10d0* last, Elem00bb10d0* dest);
};
Elem00bb10d0* __cdecl FUN_00bb0620(Elem00bb10d0*, Elem00bb10d0*, Elem00bb10d0*, Alloc00bb10d0&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Elem00bb10d0* Alloc00bb10d0::FUN_00bb10d0(Elem00bb10d0* first, Elem00bb10d0* last, Elem00bb10d0* dest) {
    return FUN_00bb0620(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bb10d0

// @f3 0x00bb2cb0 (community match, verified in this file)
namespace f3m_00bb2cb0 {
struct Entry_bb2cb0 {
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
    unsigned char state3c, unk3d, unk3e, unk3f, unk40, unk41, unk42, unk43;
};
struct List_bb2cb0 {
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
    unsigned short count28;
    unsigned short unk2a;
    Entry_bb2cb0* entries2c;
    void FUN_00bb2cb0();
};
// pdb: CLeafGeometry::Invalidate | LeafGeometry.obj | fnv360_0822_retail, call_gap, low
void List_bb2cb0::FUN_00bb2cb0()
{
    if (entries2c) {
        for (int i = 0; i < count28; ++i)
            entries2c[i].state3c = 0;
    }
}
}   // namespace f3m_00bb2cb0

// @f3 0x00bb5280 (community match, verified in this file)
namespace f3m_00bb5280 {
struct Element00bb5280 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
};
void __cdecl FUN_00bb5280(Element00bb5280* first, Element00bb5280* last, const Element00bb5280* value) {
    for (; first != last; ++first)
        *first = *value;
}
}   // namespace f3m_00bb5280

// @f3 0x00bb53b0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb53b0 {
typedef f3m_00bb5fe0::Slot1VectorBB::Element Element_bb53b0;
struct Vector_bb53b0 : std::vector<Element_bb53b0> {
    std::vector<Element_bb53b0>::iterator FUN_00bb53b0();
};
// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::insert<SFrondGuide &> | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _Where, _Val
std::vector<Element_bb53b0>::iterator Vector_bb53b0::FUN_00bb53b0()
{
    return end();
}
}   // namespace f3m_00bb53b0

// @f3 0x00bbbf20 (community match, verified in this file)
#include <memory>
namespace f3m_00bbbf20 {
struct Elem00bbbf20 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct Alloc00bbbf20 {
    Elem00bbbf20* FUN_00bbbf20(Elem00bbbf20* first, Elem00bbbf20* last, Elem00bbbf20* dest);
};
Elem00bbbf20* __cdecl FUN_00bbbc90(Elem00bbbf20*, Elem00bbbf20*, Elem00bbbf20*, Alloc00bbbf20&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Elem00bbbf20* Alloc00bbbf20::FUN_00bbbf20(Elem00bbbf20* first, Elem00bbbf20* last, Elem00bbbf20* dest) {
    return FUN_00bbbc90(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bbbf20

// @f3 0x00bb5640 (community match, verified in this file)
#include <string>
namespace f3m_00bb5640 {
void __stdcall FUN_00bb5640(std::string* value) {
    value->~basic_string();
}
}   // namespace f3m_00bb5640

// @f3 0x00bbe990 (community match, verified in this file)
#include <string>
namespace f3m_00bbe990 {
struct Item_bbe990 {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    std::string text;
};
struct Owner_bbe990 {
    void FUN_00bbe990(Item_bbe990* item);
};
void Owner_bbe990::FUN_00bbe990(Item_bbe990* item)
{
    item->text.~basic_string();
}
}   // namespace f3m_00bbe990

// @f3 0x00bbdb10 (community match, verified in this file)
extern float DAT_00dbcbd0;
extern float DAT_00e19cbc;
namespace f3m_00bbdb10 {


unsigned int __cdecl FUN_00c00690();

struct FUN_00bbdb10_Helper {
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

    void FUN_00bc4b70(int value);
    void FUN_00bc4b40(float value0, float value1);
};

struct FUN_00bbdb10_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    FUN_00bbdb10_Helper helper;

    unsigned int unk48;

    void FUN_00bbdb10(int value);
};

// pdb: CTreeEngine::SetSeed | TreeEngine.obj | fnv360_0822_retail, caller, medium
// pdb params: nSeed
void FUN_00bbdb10_Obj::FUN_00bbdb10(int value)
{
    if (value == 0) {
        helper.FUN_00bc4b70(-1);
        helper.FUN_00bc4b40(DAT_00dbcbd0, DAT_00e19cbc);
        unk48 = FUN_00c00690();
        return;
    }

    if (value != 1) {
        unk48 = value;
    }
}
}   // namespace f3m_00bbdb10

// @f3 0x00bbda20 (community match, verified in this file)
namespace f3m_00bbda20 {
namespace f3m_00bbda20 {
struct Obj {
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
    float unk4c;
    float unk50;
    void FUN_00bbda20(float& a, float& b) const;
};
// pdb: CTreeEngine::GetSize | TreeEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: fSize, fVariance
void Obj::FUN_00bbda20(float& a, float& b) const
{
    a = unk4c;
    b = unk50;
}
}
}   // namespace f3m_00bbda20

// @f3 0x00baed70 (community match, verified in this file)
namespace f3m_00baed70 {
namespace f3m_00baed70 {
void __cdecl FUN_00c01e8b();
void __cdecl FUN_00401010(void* p);
template <class T> struct Vec {
    int alloc;
    T* first;
    T* last;
    T* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    T& operator[](unsigned int n) {
        if (!(n < size()))
            FUN_00c01e8b();
        return *(first + n);
    }
};
struct Group {
    int alloc;
    void** first;
    void** last;
    void** end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    void*& operator[](unsigned int n) {
        if (!(n < size()))
            FUN_00c01e8b();
        return *(first + n);
    }
};
struct Obj {
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
    Vec<Group> groups;
    unsigned short Count(short idx) {
        if (idx > -1)
            return (unsigned short)groups[idx].size();
        return 0;
    }
    void FUN_00baed70(short idx);
};
void Obj::FUN_00baed70(short idx)
{
    for (int i = 0; i < Count(idx); ++i) {
        FUN_00401010(groups[(unsigned short)idx][i]);
        groups[(unsigned short)idx][i] = 0;
    }
}
}
}   // namespace f3m_00baed70

// @f3 0x00baf580 (community match, verified in this file)
#include <string.h>
namespace f3m_00baf580 {
namespace f3m_00baf580 {
short* __cdecl FUN_00baf580(const short* first, const short* last, short* dest)
{
    int off = last - first;
    short* result = dest + off;
    if (off > 0)
        memmove_s(dest, off * sizeof(short), first, off * sizeof(short));
    return result;
}
}
}   // namespace f3m_00baf580

// @f3 0x00bbab80 (community match, verified in this file)
namespace f3m_00bbab80 {
namespace f3m_00bbab80 {
struct Elem48 { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c; };
void __cdecl FUN_00c01e8b();
struct Vec;
struct Iter {
    Vec* cont;
    Elem48* ptr;
};
struct Vec {
    int alloc;
    Elem48* first;
    Elem48* last;
    Elem48* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    Iter mk(Elem48* p) {
        if (first > p || p > last) FUN_00c01e8b();
        Iter it; it.cont = this; it.ptr = p; return it;
    }
    Iter begin() { return mk(first); }
    void FUN_00bba4e0(Iter where, unsigned int n, const Elem48& val);
    Iter FUN_00bbab80(Iter where, const Elem48& val);
};
inline int diff(const Iter& a, const Iter& b) {
    if (a.cont == 0 || a.cont != b.cont) FUN_00c01e8b();
    return a.ptr - b.ptr;
}
inline Iter add(Iter it, int n) {
    if (it.ptr + n > it.cont->last || it.ptr + n < it.cont->first) FUN_00c01e8b();
    it.ptr += n; return it;
}
Iter Vec::FUN_00bbab80(Iter where, const Elem48& val)
{
    unsigned int off = size() == 0 ? 0 : diff(where, begin());
    FUN_00bba4e0(where, 1, val);
    return add(begin(), off);
}
}
}   // namespace f3m_00bbab80

// @f3 0x00ba92a0 (community match, verified in this file)
namespace f3m_00ba92a0 {
namespace f3m_00ba92a0 {
void __cdecl FUN_00c01e8b();
struct Bytes {
    int alloc;
    char* first;
    char* last;
    char* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    char& operator[](unsigned int n) {
        if (!(n < size()))
            FUN_00c01e8b();
        return *(first + n);
    }
};
struct Reader {
    unsigned int pos;
    Bytes buf;
    float FUN_00ba92a0();
};
// pdb: CTreeFileAccess::ParseFloat | FileAccess.obj | fnv360_0822_retail, call_dedup, low
float Reader::FUN_00ba92a0()
{
    char& c = buf[pos];
    pos += 4;
    return *(float*)&c;
}
}
}   // namespace f3m_00ba92a0

// @f3 0x00bbea40 (community match, verified in this file)
namespace f3m_00bbea40 {
namespace f3m_00bbea40 {
void __cdecl FUN_00401010(void* p) throw();
struct Str {
    int alloc;
    union { char buf[16]; char* ptr; };
    unsigned int size;
    unsigned int capacity;
    Str& FUN_0042eff0(const Str& o, unsigned int pos, unsigned int n);
    Str(const Str& o) { capacity = 15; size = 0; buf[0] = 0; FUN_0042eff0(o, 0, (unsigned int)-1); }
    ~Str() { if (capacity >= 16) FUN_00401010(ptr); }
    Str& operator=(const Str& o) { return FUN_0042eff0(o, 0, (unsigned int)-1); }
};
struct Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Str name;
    void FUN_00bbea40(const Str& s);
};
// pdb: CTreeEngine::SetBranchTexture | TreeEngine.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: strFilename
void Obj::FUN_00bbea40(const Str& s)
{
    Str tmp(s);
    name = tmp;
}
}
}   // namespace f3m_00bbea40

// @f3 0x00bb5380 (community match, verified in this file)
namespace f3m_00bb5380 {
namespace f3m_00bb5380 {
void __cdecl FUN_00c01e8b();
struct Vec;
struct Iter {
    Vec* cont;
    int* ptr;
    Iter(int* p, Vec* v);
};
struct Vec {
    int alloc;
    int* first;
    int* last;
    int* end;
    Iter FUN_00bb5380();
};
inline Iter::Iter(int* p, Vec* v)
{
    cont = 0;
    if (v->first > p || p > v->last)
        FUN_00c01e8b();
    cont = v;
    ptr = p;
}
Iter Vec::FUN_00bb5380()
{
    return Iter(first, this);
}
}
}   // namespace f3m_00bb5380

// @f3 0x00bbc270 (community match, verified in this file)
namespace f3m_00bbc270 {
namespace f3m_00bbc270 {
struct Elem16 { int unk00, unk04, unk08, unk0c; };
void __cdecl FUN_00c01e8b();
struct Vec;
struct Iter {
    Vec* cont;
    Elem16* ptr;
};
struct Vec {
    int alloc;
    Elem16* first;
    Elem16* last;
    Elem16* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    Iter mk(Elem16* p) {
        if (first > p || p > last) FUN_00c01e8b();
        Iter it; it.cont = this; it.ptr = p; return it;
    }
    Iter begin() { return mk(first); }
    void FUN_00bbbf90(Iter where, unsigned int n, const Elem16& val);
    Iter FUN_00bbc270(Iter where, const Elem16& val);
};
inline int diff(const Iter& a, const Iter& b) {
    if (a.cont == 0 || a.cont != b.cont) FUN_00c01e8b();
    return a.ptr - b.ptr;
}
inline Iter add(Iter it, int n) {
    if (it.ptr + n > it.cont->last || it.ptr + n < it.cont->first) FUN_00c01e8b();
    it.ptr += n; return it;
}
// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::vector<SFrondGuide,std::allocator<SFrondGuide> > | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _Right
Iter Vec::FUN_00bbc270(Iter where, const Elem16& val)
{
    unsigned int off = size() == 0 ? 0 : diff(where, begin());
    FUN_00bbbf90(where, 1, val);
    return add(begin(), off);
}
}
}   // namespace f3m_00bbc270

// @f3 0x00bb98e0 (community match, verified in this file)
namespace f3m_00bbad10 {

struct Obj_bb98e0 {
    void FUN_00bb98e0(void* a, unsigned int b);
};

void Obj_bb98e0::FUN_00bb98e0(void* a, unsigned int b)
{
    FUN_00bb8e80(a, *(unsigned int volatile*)&b, (Holder_bbad10*)this, (Holder_bbad10*)b);
}

}

// @f3 0x00ba13e0 (community match, verified in this file)
namespace f3m_00ba13e0 {
class C00ba13e0 {
public:
    void* unk00;
    float FUN_00ba13e0();
};

// pdb: CSpeedTreeRT::GetTrunkLength | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
float C00ba13e0::FUN_00ba13e0()
{
    void* p = *(void**)((char*)this + 0x00);
    if (p != 0)
    {
        void* q = *(void**)((char*)p + 0x5c);
        if (q != 0)
            return *(float*)((char*)q + 0x1c);
    }
    return 0.0f;
}
}   // namespace f3m_00ba13e0

// @f3 0x00bbd290 (community match, verified in this file)
namespace f3m_00bbd290 {
class C00bbd290 {
public:
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    int unk14;
    C00bbd290* FUN_00bbd290(int n);
};

// pdb: CVec::CVec | Vec.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: nSize
C00bbd290* C00bbd290::FUN_00bbd290(int n)
{
    float z = 0.0f;
    f10 = z;
    f0c = z;
    f08 = z;
    f04 = z;
    f00 = z;
    if (n > 5)
        n = 5;
    unk14 = n;
    return this;
}
}   // namespace f3m_00bbd290

// @f3 0x00bbd2f0 (community match, verified in this file)
namespace f3m_00bbd2f0 {
struct Values_bbd2f0 {
    float first, second, third, fourth, fifth;
    unsigned int count;
    Values_bbd2f0* FUN_00bbd2f0(float, float, float, float, float);
};
Values_bbd2f0* Values_bbd2f0::FUN_00bbd2f0(float a, float b, float c, float d, float e)
{
    first = a;
    count = 5;
    second = b;
    third = c;
    fourth = d;
    fifth = e;
    return this;
}
}   // namespace f3m_00bbd2f0

// @f3 0x00bb50f0 (community match, verified in this file)
namespace f3m_00bb50f0 {
struct Element00bb50f0 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
};
Element00bb50f0* __cdecl FUN_00bb50f0(Element00bb50f0* first, Element00bb50f0* last, Element00bb50f0* output) {
    unsigned int address = reinterpret_cast<unsigned int>(output);
    while (first != last) {
        if (address)
            *reinterpret_cast<Element00bb50f0*>(address) = *first;
        ++first;
        address += sizeof(Element00bb50f0);
    }
    return reinterpret_cast<Element00bb50f0*>(address);
}
}   // namespace f3m_00bb50f0

// @f3 0x00bb52e0 (community match, verified in this file)
namespace f3m_00bb52e0 {
struct Record_bb52e0 {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
};
void __cdecl FUN_00bb52e0(Record_bb52e0* dest, unsigned int count, const Record_bb52e0& value)
{
    if (count > 0) {
        unsigned int address = (unsigned int)dest;
        do {
            if (address)
                *(Record_bb52e0*)address = value;
            --count;
            address += sizeof(Record_bb52e0);
        } while (count > 0);
    }
}
}   // namespace f3m_00bb52e0

// @f3 0x00bb6290 (community match, verified in this file)
namespace f3m_00bb6290 {
namespace f3_2945 {
void __cdecl FUN_00c01e8b();
struct Element { unsigned int value00,value04,value08,value0c,value10,value14,value18,value1c,value20,value24,value28,value2c,value30,value34; };
class Vector;
struct Iterator {
 Vector* owner; Element* current;
 Iterator(Element* p,Vector* v):owner(v),current(p){}
 int operator-(const Iterator& r)const {if(!(owner && owner==r.owner))FUN_00c01e8b();return current-r.current;}
 Iterator& operator+=(int);
 Iterator operator+(int n)const{Iterator temp=*this;return temp+=n;}
};
class Vector {
public:
 unsigned int unk00;
 Element* first;Element* last;Element* endStorage;
 unsigned int size()const{return first==0?0:last-first;}
 Iterator begin(){Element* p=first;if(p>last)FUN_00c01e8b();return Iterator(p,this);}
 void FUN_00bb5950(Iterator,unsigned int,const Element&);
 Iterator FUN_00bb6290(Iterator where,const Element& value);
};
Iterator& Iterator::operator+=(int n){
 Element* p=current+n;
 if(p>owner->last || p<owner->first)FUN_00c01e8b();
 current=p;return *this;
}
Iterator Vector::FUN_00bb6290(Iterator where,const Element& value){
 unsigned int offset=size()==0?0:where-begin();
 FUN_00bb5950(where,1,value);
 return begin()+offset;
}
}
}   // namespace f3m_00bb6290

// @f3 0x00babca0 (community match, verified in this file)
#include <vector>
namespace f3m_00babca0 {
namespace Task2940 {
struct Element {int values[6];};
struct Vector:std::vector<Element> {
 void FUN_00bab8d0(const_iterator,unsigned int,const Element&);
 iterator FUN_00babca0(const_iterator,const Element&);
};
Vector::iterator Vector::FUN_00babca0(const_iterator where,const Element& value){unsigned int offset=size()==0?0:where-begin();FUN_00bab8d0(where,1,value);return begin()+offset;}
}
}   // namespace f3m_00babca0

// @f3 0x00babbf0 (community match, verified in this file)
#include <vector>
namespace f3m_00babbf0 {
struct Rec2941 { int x,y,z; };
struct Vec2941 : std::vector<Rec2941> {
    void FUN_00bab620(const_iterator where,unsigned count,const Rec2941& value);
    iterator FUN_00babbf0(const_iterator where,const Rec2941& value);
};
Vec2941::iterator Vec2941::FUN_00babbf0(const_iterator where,const Rec2941& value) {
    unsigned off=size()==0 ? 0 : where-begin();
    FUN_00bab620(where,1,value);
    return begin()+off;
}
}   // namespace f3m_00babbf0

// @f3 0x00bafed0 (community match, verified in this file)
#include <memory>
namespace f3m_00bafed0 {
namespace task2950 {
struct Element;
void __cdecl FUN_00baf710(Element*,Element*,std::allocator<Element>&,std::_Nonscalar_ptr_iterator_tag);
void __cdecl FUN_00401010(void*);
struct Vector {std::allocator<Element> allocator;Element* first;Element* last;Element* end;void FUN_00bafed0();};
void Vector::FUN_00bafed0(){if(first){FUN_00baf710(first,last,allocator,std::_Ptr_cat(first,last));FUN_00401010(first);}first=0;last=0;end=0;}
}
}   // namespace f3m_00bafed0

// @f3 0x00bb8d10 (community match, verified in this file)
#include <memory>
#include <iterator>
namespace f3m_00bb8d10 {
namespace f3_2951 {
struct Element { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34; };
void FUN_00bb5cd0(Element*,Element*,std::allocator<Element>&,std::_Nonscalar_ptr_iterator_tag);
struct Vector {
 std::allocator<Element> allocator;
 Element* first;Element* last;Element* endStorage;
 void Destroy(Element* start,Element* finish){FUN_00bb5cd0(start,finish,allocator,std::_Ptr_cat(start,finish));}
 void FUN_00bb8d10();
};
void Vector::FUN_00bb8d10(){
 if(first){Destroy(first,last);allocator.deallocate(first,endStorage-first);}
 first=0,last=0,endStorage=0;
}
}
}   // namespace f3m_00bb8d10

// @f3 0x00bb9900 (community match, verified in this file)
namespace f3m_00bb9900 {
namespace Task2952 {
struct Element {int values[12];};
struct Alloc {};
struct Nonscalar {};
void __cdecl FUN_00bb8e80(Element*,Element*,Alloc&,Nonscalar);
void __cdecl FUN_00401010(void*);
inline Nonscalar category(Element*&,Element*&){Nonscalar tag;return tag;}
inline void destroy(Element* first,Element* last,Alloc& alloc){FUN_00bb8e80(first,last,alloc,category(first,last));}
struct Vector {Alloc alloc;Element* first;Element* last;Element* end;void FUN_00bb9900();};
void Vector::FUN_00bb9900(){if(first){destroy(first,last,alloc);FUN_00401010(first);}first=0;last=0;end=0;}
}
}   // namespace f3m_00bb9900

// @f3 0x00ba97a0 (community match, verified in this file)
#include <math.h>
extern const double DAT_00e31f80;
namespace f3m_00ba97a0 {
namespace task2961 {
struct Matrix {float m00,m01,m02,m10,m11,m12,m20,m21,m22;Matrix FUN_00ba9610(const Matrix&);void FUN_00ba97a0(float,float);};
void Matrix::FUN_00ba97a0(float first,float second){Matrix rotation;float c1=(float)cos((float)(first/DAT_00e31f80));float s1=(float)sin((float)(first/DAT_00e31f80));float c2=(float)cos((float)(second/DAT_00e31f80));float s2=(float)sin((float)(second/DAT_00e31f80));rotation.m00=c1*c2;rotation.m01=c1*s2;rotation.m02=-s1;rotation.m10=-s2;rotation.m11=c2;rotation.m12=0.0f;rotation.m20=s1*c2;rotation.m21=s1*s2;rotation.m22=c1;*this=rotation.FUN_00ba9610(*this);}
}
}   // namespace f3m_00ba97a0

// @f3 0x00bbc230 (community match, verified in this file)
#include <new>
namespace f3m_00bbc230 {
struct Element2953;
struct Alloc2953 {};
struct DestroyTag2953 {};
void __cdecl FUN_00bbbc20(Element2953*,Element2953*,Alloc2953&,DestroyTag2953);
struct Vector2953 {
    Alloc2953 allocator;
    Element2953* first;
    Element2953* last;
    Element2953* end;
    void FUN_00bbc230();
};
void Vector2953::FUN_00bbc230() {
    if (first) {
        DestroyTag2953 tag;
        FUN_00bbbc20(first,last,allocator,tag);
        ::operator delete(first);
    }
    first=0;last=0;end=0;
}
}   // namespace f3m_00bbc230

// @f3 0x00bbd800 (community match, verified in this file)
#include <string>
#include <stdexcept>
namespace f3m_00bbd800 {
namespace f3_2993 {
struct FUN_00bbd800;
void __cdecl FUN_00bff43d(FUN_00bbd800*,const char*);
struct FUN_00bbd800 {
 std::_Lockit lock;
 std::string days,months,oldName,newName;
 FUN_00bbd800(const char*);
 ~FUN_00bbd800();
};
// pdb: std::_Locinfo::_Locinfo | algs.obj | fnv360_0822_retail, ustr, medium
// pdb params: _Pch
FUN_00bbd800::FUN_00bbd800(const char* name):lock(0){
 if(!name)throw std::runtime_error("bad locale name");
 FUN_00bff43d(this,name);
}
}
}   // namespace f3m_00bbd800

// @f3 0x00ba9b00 (community match, verified in this file)
#include <math.h>
extern double DAT_00dc0770;extern float DAT_01068b40;
namespace f3m_00ba9b00 {
namespace task2992 {
inline float difference(float a,float b){return a-b;}
struct ParticleFalloff{float unk00,unk04,unk08,unk0c,unk10,unk14;float FUN_00ba9b00(float,float);};
// pdb: SIdvBranchFlare::Distance | Branch.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: fInputAngle, fInputProgress
float ParticleFalloff::FUN_00ba9b00(float a, float b)
{
    float result2 = 0.0f;
    float loTmp;
    float x = (float)(double)(float)fabs((double)(float)(a - (loTmp = unk00)));
    if (x > DAT_00dc0770)
    {
        if (a < loTmp)
        {
            a = a + DAT_01068b40;
        }
        else
        {
            loTmp = loTmp + DAT_01068b40;
        }
    }
    x = fabs(difference(a, loTmp));
    if (x < unk04)
    {
        float d8 = unk0c - b;
        if (d8 > 0.0)
        {
            result2 = unk14 * (float)pow((double)(float)(1.0f-x/unk04),(double)unk08) * (float)pow((double)(float)(d8/unk0c),(double)unk10);
        }
    }
    return result2;
}

}
}   // namespace f3m_00ba9b00

// @f3 0x00bb0340 (community match, verified in this file)
namespace f3m_00bb0340 {
typedef f3m_00bafd80::fo3_bafd80::UIntVector VectBB;
VectBB* __cdecl FUN_00bb0340(VectBB* first, VectBB* last, VectBB* dest) {
    VectBB* result = dest + (last - first);
    if (first != last) {
        dest = (VectBB*)((unsigned int)dest - (unsigned int)first);
        do {
            ((VectBB*)((unsigned int)first + (unsigned int)dest))->FUN_00bafd80(*first);
            ++first;
        } while (first != last);
    }
    return result;
}

}   // namespace f3m_00bb0340

// @f3 0x00baeea0 (community match, verified in this file)
namespace f3m_00baeea0 {
void __cdecl FUN_00c01e8b();

struct FNV_00baeea0_Vec
{
    int allocator;
    int* begin;
    int* end;
    int* limit;
    unsigned int Size() const { if (!begin) return 0; return (unsigned int)(end - begin); }
};

struct FNV_00baeea0_Obj
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
    FNV_00baeea0_Vec items;

    int* FUN_00baeea0(unsigned int index);
};

int* FNV_00baeea0_Obj::FUN_00baeea0(unsigned int index)
{
    unsigned int position = index + index;
    if (position >= items.Size())
        FUN_00c01e8b();
    return items.begin + position;
}
}   // namespace f3m_00baeea0

// @f3 0x00bbbc20 (community match, verified in this file)
namespace f3m_00bbbc20 {
extern "C" void __cdecl FUN_00401010(void*);
struct ElementBBBC { int allocator; void* first; void* last; void* end; int unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; };
struct VectorBBBC { int allocator; ElementBBBC* first; ElementBBBC* last; ElementBBBC* end; };
void __cdecl FUN_00bbbc20(VectorBBBC* first, VectorBBBC* last) {
 for (; first != last; ++first) {
  if (first->first) {
   ElementBBBC* end=first->last;
   for (ElementBBBC* p=first->first; p!=end; ++p) {
    if (p->first) FUN_00401010(p->first);
    p->first=0; p->last=0; p->end=0;
   }
   FUN_00401010(first->first);
  }
  first->first=0; first->last=0; first->end=0;
 }
}

}   // namespace f3m_00bbbc20

// @f3 0x00bb4cb0 (community match, verified in this file)
#include <new>
namespace f3m_00bb4cb0 {
struct Index { unsigned short value; static void* operator new[](size_t n) { return ::operator new(n); } };
struct GridEntry {
 unsigned int f00,f04,f08,f0c,f10,f14,f18,f1c,f20,f24,f28,f2c,f30,f34;
};
struct Grid {
 unsigned int unk00;
 GridEntry *begin,*end,*capacity;
 unsigned int unk10,unk14,unk18,unk1c,unk20,unk24,unk28;
 unsigned int columns;
 unsigned int size() const { if (!begin) return 0; return (unsigned int)(end-begin); }
 __declspec(noinline) unsigned int FUN_00bb4600();
};
struct Resource {
 unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 unsigned short unk24,counter;
 void FUN_00bb0850(unsigned int id,unsigned short* indices,unsigned int count);
};
struct Builder {
 Resource* resource;
 unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
 unsigned int levels,unk54,unk58,unk5c,unk60,minRows,halfColumns;
 void FUN_00bb4cb0(unsigned int level,unsigned int base,Grid* grid);
};
// pdb: CFrondEngine::ComputeExtrusion | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: nLod, nStart, sGuide
void Builder::FUN_00bb4cb0(unsigned int level,unsigned int base,Grid* grid) {
 if (!resource) return;
 float t;
 if(levels==1) t=1.0f;
 else t=1.0f-(float)level/((float)levels-1.0f);
 float nr=(float)grid->size();
 float minR = (float)(minRows+1);
 float rowCount=minR+(nr-minR)*t;
 int rows=(int)rowCount;
 float numRows=(float)grid->size();
 int rowIntervals=rows-1;
 float rowStep=numRows/rowIntervals;
 float minC=(float)(halfColumns*2+1);
 float maxC=(float)grid->columns;
 float columnCount=minC+(maxC-minC)*t;
 int cols=(int)columnCount;
 float colStep=maxC/(cols-1);
 unsigned int count=(cols*2+1)*rowIntervals-1;
 unsigned short* indices=(unsigned short*)new Index[count];
 int out=0;
 for(int row=0; row<rowIntervals; ++row) {
  int first=(int)(rowStep*row);
  int last=(int)(rowStep*(row+1));
  if(row==rows-2 || last>(int)(grid->FUN_00bb4600()-1)) last=grid->FUN_00bb4600()-1;
  int delta=last-first;
  if(row%2==0) {
   unsigned int rowBase=grid->columns*first;
   unsigned int vertexBase=base+rowBase;
   for(int col=0;col<cols;++col) {
    unsigned int c=(unsigned int)(colStep*col);
    if(col==cols-1)c=grid->columns-1;
    if(c>grid->columns-1)c=grid->columns-1;
    unsigned int vertex=base+rowBase+c;
    indices[out++]=(unsigned short)vertex;
    indices[out++]=(unsigned short)(base+rowBase+grid->columns*delta+c);
   }
   if(row<rows-2) {indices[out]=indices[out-1];++out;}
  } else {
   unsigned int rowBase=grid->columns*first;
   unsigned int vertexBase=base+rowBase;
   for(int col=cols-1;col>=0;--col) {
    unsigned int c=(unsigned int)(colStep*col);
    if(col==cols-1)c=grid->columns-1;
    if(c>grid->columns-1)c=grid->columns-1;
    unsigned int vertex=base+rowBase+c;
    indices[out++]=(unsigned short)vertex;
    indices[out++]=(unsigned short)(base+rowBase+grid->columns*delta+c);
   }
   if(row<rows-2) {indices[out]=indices[out-1];++out;}
  }
 }
 resource->FUN_00bb0850(level,indices,count);
 ++resource->counter;
}

}   // namespace f3m_00bb4cb0

// @f3 0x00ba1200 (community match, verified in this file)
namespace f3m_00ba1200 {
struct State1200 {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    void FUN_00ba1200();
};
// pdb: CSpeedTreeRT::SGeometry::SLeaf::~SLeaf | SpeedTreeRT.obj | fnv360_0822_retail, objrun, medium
void State1200::FUN_00ba1200() {
    unk10=0; unk14=0; unk18=0; unk24=0; unk28=0; unk2c=0; unk30=0;
    unk1c=0; unk20=0; unk34=0; unk38=0;
}
}   // namespace f3m_00ba1200

// @f3 0x00bb0f70 (community match, verified in this file)
#include <memory>
namespace f3m_00bb1460 { namespace vec16_bb1460 {
Elem16* __cdecl FUN_00bb0250(Elem16*, Elem16*, Elem16*, Vec16&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Elem16* Vec16::FUN_00bb0f70(Elem16* first, Elem16* last, Elem16* dest) {
 return FUN_00bb0250(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}
} }

// @f3 0x00bb5590 (community match, verified in this file)
#include <memory>
namespace f3m_00bb5590 {
struct Entry5590 { unsigned int words[14]; };
struct Alloc5590 { Entry5590* FUN_00bb5590(Entry5590*, Entry5590*, Entry5590*); };
Entry5590* __cdecl FUN_00bb50f0(Entry5590*, Entry5590*, Entry5590*, Alloc5590&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Entry5590* Alloc5590::FUN_00bb5590(Entry5590* first, Entry5590* last, Entry5590* dest) {
 return FUN_00bb50f0(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bb5590

// @f3 0x00bb98b0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb98b0 {
struct ElemBB98 { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; ~ElemBB98(); };
struct VecBB98 { ElemBB98* FUN_00bb98b0(ElemBB98*,ElemBB98*,ElemBB98*); };
ElemBB98* __cdecl FUN_00bb7020(ElemBB98*,ElemBB98*,ElemBB98*,VecBB98&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
ElemBB98* VecBB98::FUN_00bb98b0(ElemBB98* first, ElemBB98* last, ElemBB98* dest) {
 return FUN_00bb7020(first,last,dest,*this,std::_Ptr_cat(first,dest),std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bb98b0

// @f3 0x00bb9b30 (community match, verified in this file)
#include <memory>
namespace f3m_00bb9b30 {
struct Entry9b30 { unsigned int words[4]; };
struct Alloc9b30 { Entry9b30* FUN_00bb9b30(Entry9b30*, Entry9b30*, Entry9b30*); };
Entry9b30* __cdecl FUN_00bb8f50(Entry9b30*, Entry9b30*, Entry9b30*, Alloc9b30&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
Entry9b30* Alloc9b30::FUN_00bb9b30(Entry9b30* first, Entry9b30* last, Entry9b30* dest) {
 return FUN_00bb8f50(first, last, dest, *this, std::_Ptr_cat(first, dest), std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bb9b30

// @f3 0x00bb8e20 (community match, verified in this file)
#include <memory>
namespace f3m_00bb8e20 {
struct ElemBB8 { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28; ~ElemBB8(); };
struct VecBB8 { ElemBB8* FUN_00bb8e20(ElemBB8*,ElemBB8*,ElemBB8*); };
ElemBB8* __cdecl FUN_00bb5ef0(ElemBB8*,ElemBB8*,ElemBB8*,VecBB8&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
ElemBB8* VecBB8::FUN_00bb8e20(ElemBB8* first, ElemBB8* last, ElemBB8* dest) {
 return FUN_00bb5ef0(first,last,dest,*this,std::_Ptr_cat(first,dest),std::_Range_checked_iterator_tag());
}

}   // namespace f3m_00bb8e20

// @f3 0x00baf6e0 (community match, verified in this file)
namespace f3m_00baf6e0 {
unsigned short* __stdcall FUN_00baf6e0(unsigned short* dst, unsigned int count, const unsigned short* src)
{
    unsigned int n = count;
    unsigned short* out = dst;
    if (n > 0) {
        do {
            *out = *src;
            n -= 1;
            ++out;
        } while (n > 0);
    }
    return dst + count;
}
}   // namespace f3m_00baf6e0

// @f3 0x00baf540 (community match, verified in this file)
namespace f3m_00baf540 {
void __cdecl FUN_00c01c9b(void* dest, unsigned int size, void* source, unsigned int copySize);

unsigned int* __cdecl FUN_00baf540(unsigned int* first, unsigned int* last, unsigned int* dest)
{
    int count = ((int)((char*)last - (char*)first)) >> 2;
    unsigned int size = count * 4;
    unsigned int* result = (unsigned int*)((char*)dest + size);

    if (count > 0)
        FUN_00c01c9b(dest, size, first, size);

    return result;
}
}   // namespace f3m_00baf540

// @f3 0x00ba2d80 (community match, verified in this file)
namespace f3m_00ba2d80 {
void __cdecl FUN_00c01c9b(void* dest, unsigned int size, void* source, unsigned int copySize);

unsigned int* __cdecl FUN_00ba2d80(unsigned int* first, unsigned int* last, unsigned int* end)
{
    int count = ((int)((char*)last - (char*)first)) >> 2;
    unsigned int bytes = count * 4;
    unsigned int* destination = (unsigned int*)((char*)end - bytes);

    if (count > 0)
        FUN_00c01c9b(destination, bytes, first, bytes);

    return destination;
}
}   // namespace f3m_00ba2d80

// @f3 0x00bb0e80 (community match, verified in this file)
namespace f3m_00bb0e80 {
namespace f3m_00bb0e80 {
struct Elem
{
    int unk00;
};
struct Alloc
{
    char unk00;
};
struct NonscalarTag
{
};
struct Iterator
{
    Iterator() {}
    const void* m_pCont;
    Elem* m_pPtr;
};
extern "C" void __cdecl FUN_00c01e8b();
Elem* __cdecl FUN_00bb0300(Elem* first, Elem* last, Elem* dest);
void __cdecl FUN_00baf710(Elem* first, Elem* last, Alloc& al, NonscalarTag tag);
}

struct FUN_00bb0e80_Vector
{
    f3m_00bb0e80::Alloc m_kAlval;
    f3m_00bb0e80::Elem* m_pFirst;
    f3m_00bb0e80::Elem* m_pLast;
    f3m_00bb0e80::Elem* m_pEnd;

    f3m_00bb0e80::Iterator FUN_00bb0e80(f3m_00bb0e80::Iterator first, f3m_00bb0e80::Iterator last);
};

// pdb: std::_Destroy_range<std::allocator<std::vector<unsigned short,std::allocator<unsigned short> > > > | IndexedGeometry.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: _First, _Last, _Al
f3m_00bb0e80::Iterator FUN_00bb0e80_Vector::FUN_00bb0e80(f3m_00bb0e80::Iterator first, f3m_00bb0e80::Iterator last)
{
    if (first.m_pCont == 0 || first.m_pCont != last.m_pCont)
        f3m_00bb0e80::FUN_00c01e8b();
    if (first.m_pPtr != last.m_pPtr)
    {
        f3m_00bb0e80::Elem* ptr = f3m_00bb0e80::FUN_00bb0300(last.m_pPtr, m_pLast, first.m_pPtr);
        f3m_00bb0e80::NonscalarTag tag;
        f3m_00bb0e80::FUN_00baf710(ptr, m_pLast, m_kAlval, tag);
        m_pLast = ptr;
    }
    return first;
}
}   // namespace f3m_00bb0e80

// @f3 0x00ba1300 (community match, verified in this file)
namespace f3m_00ba1300 {
struct Node {
    int FUN_00bbda20();
};
struct Root {
    Node* node;
    int FUN_00ba1300();
};
// pdb: CSpeedTreeRT::GetTreeSize | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: fSize, fVariance
int Root::FUN_00ba1300()
{
    return node->FUN_00bbda20();
}
}   // namespace f3m_00ba1300

// @f3 0x00ba1490 (community match, verified in this file)
namespace f3m_00ba1490 {
struct Inner {
    short unk00[0x38];
    short unk70;
};
struct Outer {
    Inner* node;
    short FUN_00ba1490();
};
// pdb: CSpeedTreeRT::GetNumBranchLodLevels | SpeedTreeRT.obj | fnv360_0822_retail, objrun, low
short Outer::FUN_00ba1490()
{
    return node->unk70;
}
}   // namespace f3m_00ba1490

// @f3 0x00bbbf00 (community match, verified in this file)
namespace f3m_00bbbf00 {
namespace f3m_00bbbf00 {
class Object_bf00;
void* __cdecl FUN_00bbbc20(void* a_pFirst, unsigned int a_uiSecond, Object_bf00* a_pThis, unsigned int a_uiFourth);

class Object_bf00 {
public:
    void* FUN_00bbbf00(void* a_pFirst, volatile unsigned int a_uiCount);
};

void* Object_bf00::FUN_00bbbf00(void* a_pFirst, volatile unsigned int a_uiCount) {
    return FUN_00bbbc20(a_pFirst, a_uiCount, this, a_uiCount);
}
}
}   // namespace f3m_00bbbf00

// @f3 0x00bb1fd0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb1fd0 {
namespace Resize3076 {
struct Entry { unsigned key; void* memory; unsigned unk08,unk0c; ~Entry(){if(memory) ::operator delete(memory);} };
struct Vector : std::vector<Entry> {
 void FUN_00bb1730(iterator,unsigned,const Entry&);
 iterator FUN_00bb0e80(iterator,iterator);
 void FUN_00bb1fd0(unsigned count,Entry value);
};
void Vector::FUN_00bb1fd0(unsigned count,Entry value) {
 if(size()<count) _Insert_n(end(),count-size(),value);
 else if(count<size()) erase(begin()+count,end());
}
}
}   // namespace f3m_00bb1fd0

// @f3 0x00bb36a0 (community match, verified in this file)
namespace f3m_00bb36a0 {
namespace Group3094 {
void FUN_00c01e8b();
struct BufferGroup
{
    int unk00, unk04, unk08;
    unsigned short count;
    unsigned char* kinds;
    unsigned char* indices;
    float* positions;
    void** auxiliary;
    float** transforms;
    unsigned int* values;
    float* normals;
    float* bitangents;
    float* tangents;
    float* weights;
    unsigned char* selectors;
    int unk3c;
    float* originalPositions;
    BufferGroup();
    ~BufferGroup();
};
struct PointRecord
{
    int unk00;
    struct Vec3
    {
        float x, y, z;
        __forceinline Vec3& operator=(const Vec3& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            return *this;
        }
    } position;
    unsigned char index;
    unsigned int value;
    int unk18;
    Vec3 normal, tangent, bitangent;
    unsigned char kind;
    float weight;
    unsigned char selector;
    __forceinline int getKind() const
    {
        return kind;
    }
    __forceinline unsigned char getIndex() const
    {
        return index;
    }
    __forceinline float getWeight() const
    {
        return weight;
    }
    __forceinline unsigned getValue() const
    {
        return value;
    }
    __forceinline unsigned char getSelector() const
    {
        return selector;
    }
};
struct PointVector { unsigned char flag00,flag01,unk02,unk03; PointRecord** begin; PointRecord** end; PointRecord** capacity;

 unsigned size() const {return begin == 0 ? 0 : (unsigned)(end-begin);}
 PointRecord*& operator[](unsigned i) {if(i>=size()) FUN_00c01e8b();return begin[i];}
};
struct SelectorRange
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned char base,unk29,unk2a,unk2b,count;
    __forceinline void getRange(unsigned& b, unsigned& n) const
    {
        b = base;
        n = count;
    }
};
struct GroupBuilder
{
    unsigned char compact, dynamic;
    SelectorRange* range;
    unsigned short width;
    int unk0c;
    float** matrices;
    float* auxiliary;
    int unk18, unk1c, unk20, unk24;
    unsigned short groupCount;
    BufferGroup* groups;
    void FUN_00bb36a0(unsigned short count, PointVector* input);
};
// @fnv 0x00b29380
void GroupBuilder::FUN_00bb36a0(unsigned short count, PointVector* input)
{
    if (input && matrices && range && auxiliary)
    {
        groupCount = count;
        groups = new BufferGroup[count];
        for (unsigned short i = 0; i < count; i++)
        {
            BufferGroup* group = &groups[i];
            group->count = (unsigned short)input[i].size();
            group->transforms = new float*[group->count];
            for (int j = 0; j < group->count; j++)
            {

                group->transforms[j] = matrices[i] + width * 16 * input[i][j]->getKind() + 16 * input[i][j]->index;
            }
            if (dynamic)
            {
                group->originalPositions = new float[group->count * 3];
                for (int k = 0; k < group->count; k++)
                {
                    *((PointRecord::Vec3*)&group->originalPositions[k * 3]) = input[i][k]->position;
                }
                group->weights = new float[group->count];
                for (int l = 0; l < group->count; l++)
                {

                    group->weights[l] = 1.0f - input[i][l]->getWeight();
                }
                group->selectors = new unsigned char[group->count];
                for (int m = 0; m < group->count; m++)
                {
                    unsigned char selector = input[i][m]->selector;
                    unsigned int remapBase = 0;
                    unsigned int remapCount = 1;
                    range->getRange(remapBase, remapCount);
                    selector = (unsigned char)remapBase + selector % (unsigned char)remapCount;
                    group->selectors[m] = selector;
                }
            }
            group->positions = new float[group->count * 3];
            for (unsigned int n = 0; n < group->count; n++)
            {
                *((PointRecord::Vec3*)&group->positions[n * 3]) = input[i][n]->position;
            }
            group->kinds = new unsigned char[group->count];
            for (unsigned int o = 0; o < group->count; o++)
            {
                group->kinds[o] = input[i][o]->getKind();
            }
            group->indices = new unsigned char[group->count];
            for (unsigned int p = 0; p < group->count; p++)
            {

                group->indices[p] = width * input[i][p]->getKind() + input[i][p]->index;
            }
            group->auxiliary = new void*[group->count];
            for (unsigned int q = 0; q < group->count; q++)
            {
                group->auxiliary[q] = auxiliary + 8 * input[i][q]->kind;
            }
            group->values = new unsigned int[group->count];
            for (unsigned int r = 0; r < group->count; r++)
            {

                group->values[r] = input[i][r]->getValue();
            }
            if (!compact)
            {
                group->normals = new float[group->count * 3];
                for (unsigned int s = 0; s < group->count; s++)
                {
                    *((PointRecord::Vec3*)&group->normals[s * 3]) = input[i][s]->normal;
                }
            }
            if (!compact)
            {
                group->tangents = new float[group->count * 3];
                group->bitangents = new float[group->count * 3];
                for (unsigned int t = 0; t < group->count; t++)
                {
                    *((PointRecord::Vec3*)&group->tangents[t * 3]) = input[i][t]->tangent;
                    *((PointRecord::Vec3*)&group->bitangents[t * 3]) = input[i][t]->bitangent;
                }
            }
        }
    }
}

}
}   // namespace f3m_00bb36a0

// @f3 0x00bac610 (community match, verified in this file)
extern float DAT_01068b40;
extern const double DAT_00e31f80;
extern const double DAT_00dc8dc8;
namespace f3m_00bac610 {
extern int __cdecl FUN_00c04d9a();
inline float __cdecl FUN_00b14e90(float lower, float upper)
{
    float fraction = FUN_00c04d9a() / DAT_00dc8dc8;
    float range = upper - lower;
    float r = fraction * range + lower;
    return r;
}

inline float radians(float degrees)
{
    return degrees / DAT_00e31f80;
}

struct CreationValues
{
    float angle;
    float spread;
    float forward;
    float vertical;
    float magnitude;
    float sideways;
};

struct CreationValuesVector {void FUN_00babe60(CreationValues*);};
struct CreationSettings
{
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
    int count;
    float interval;
    float spread;
    float deviation;
    float forward;
    float tilt;
    float sideways;
    float vertical;
    float verticalRange;
    float verticalDeviation;
};

struct ParticleEmitter
{
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
    CreationValuesVector channel;
    void FUN_00bac610(CreationSettings* settings);
};

// @fnv 0x00b14ca0
// pdb: CIdvBranch::ComputeFlareEntries | Branch.obj | fnv360_0721_beta, call_gap, low
// pdb params: sInfo
void ParticleEmitter::FUN_00bac610(CreationSettings* settings)
{
    if (settings->count != 0)
    {
        float initial = FUN_00b14e90(0.0f, DAT_01068b40);
        float perStep = (float)(DAT_01068b40 / (float)settings->count);
        for (int i = 0; i < settings->count; ++i)
        {
            CreationValues values;
            values.angle = FUN_00b14e90(perStep * settings->interval, perStep) * (float)i + initial;
            if (values.angle > DAT_01068b40)
                values.angle -= DAT_01068b40;
            values.forward = settings->forward;
            values.magnitude = settings->verticalDeviation;
            values.spread =
                radians(FUN_00b14e90(settings->spread - settings->deviation, settings->spread + settings->deviation));
            values.vertical = FUN_00b14e90(settings->vertical - settings->verticalRange,
                                           settings->vertical + settings->verticalRange);
            values.sideways = FUN_00b14e90(settings->tilt - settings->sideways, settings->tilt + settings->sideways);
            channel.FUN_00babe60(&values);
        }
    }
}


}   // namespace f3m_00bac610

// @f3 0x00bb0ee0 (community match, verified in this file)
namespace f3m_00bb0ee0 {
struct FUN_00bb0ee0_Obj {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00bb0ee0(int* volatile output, unsigned int id, unsigned int value,
                      unsigned int id2, unsigned int value2);
};

void __cdecl FUN_00c01e8b();
unsigned int __cdecl FUN_00bb0340(unsigned int value2, unsigned int context,
                                  unsigned int value);
void __cdecl FUN_00baf710(unsigned int result, unsigned int context,
                          FUN_00bb0ee0_Obj* self, int* volatile output);

// pdb: std::_Destroy_range<std::allocator<std::vector<unsigned short *,std::allocator<unsigned short *> > > > | IndexedGeometry.obj | fnv360_0721_beta, objopen_prop, low
// pdb params: _First, _Last, _Al
void __thiscall FUN_00bb0ee0_Obj::FUN_00bb0ee0(int* volatile output,
                                                unsigned int id,
                                                unsigned int value,
                                                unsigned int id2,
                                                unsigned int value2)
{
    if (id == 0 || id != id2)
        FUN_00c01e8b();

    if (value != value2)
    {
        unsigned int result = FUN_00bb0340(value2, this->unk08, value);
        FUN_00baf710(result, this->unk08, this, output);
        this->unk08 = result;
    }

    int* o = output;
    o[0] = id;
    o[1] = value;
}
}   // namespace f3m_00bb0ee0

// @f3 0x00bb8d50 (community match, verified in this file)
namespace f3m_00bb8d50 {
struct FUN_00bb8d50_Obj {
    int unk00;
    int unk04;
    int unk08;

    void __thiscall FUN_00bb8d50(int* volatile output, int key, int value, int key2, int other);
};

extern "C" void __cdecl FUN_00c01e8b();
extern "C" int __cdecl FUN_00bb6b80(int other, int allocator, int value);
extern "C" void __cdecl FUN_00bb5cd0(int entry, int allocator, FUN_00bb8d50_Obj* owner, int* output);

// pdb: std::_Destroy_range<std::allocator<SFrondTexture> > | FrondEngine.obj | fnv360_0822_retail, call_dedup, low
// pdb params: _First, _Last, _Al, __formal
void __thiscall FUN_00bb8d50_Obj::FUN_00bb8d50(int* volatile output, int key, int value, int key2, int other)
{
    if (key == 0 || key != key2)
        FUN_00c01e8b();

    if (value != other)
    {
        int entry = FUN_00bb6b80(other, unk08, value);
        FUN_00bb5cd0(entry, unk08, this, output);
        unk08 = entry;
    }
    int* o = output;
    o[0] = key;
    o[1] = value;
}
}   // namespace f3m_00bb8d50

// @f3 0x00ba9a90 (community match, verified in this file)
namespace f3m_00ba9a90 {
float* __cdecl FUN_00ba9a90(float* result, float* from, float* to, float t)
{
    float d[3];
    float r[3];
    d[0] = to[0] - from[0];
    d[1] = to[1] - from[1];
    d[2] = to[2] - from[2];
    r[0] = t * d[0];
    r[1] = t * d[1];
    r[2] = t * d[2];
    result[0] = from[0] + r[0];
    result[1] = from[1] + r[1];
    result[2] = from[2] + r[2];
    return result;
}
}   // namespace f3m_00ba9a90

// @f3 0x00babba0 (community match, verified in this file)
namespace f3m_00babba0 {
struct LeafClusterBBA0;

void __cdecl FUN_00c01e8b();
void __cdecl FUN_00bab3f0(LeafClusterBBA0** first, LeafClusterBBA0** last, int count, int flag);

struct VectorStorageBBA0 {
    LeafClusterBBA0** first;
    LeafClusterBBA0** last;
    LeafClusterBBA0** end;
};

// pdb: CIdvBranch::SortBranchVector | Branch.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
// pdb params: vAllBranches
void __cdecl FUN_00babba0(VectorStorageBBA0* storage)
{
    unsigned char flag = 0;
    LeafClusterBBA0** end = storage->end;

    if (storage->last > end)
        FUN_00c01e8b();

    LeafClusterBBA0** last = storage->last;

    if (last > storage->end)
        FUN_00c01e8b();

    int count = (int)(end - last);
    FUN_00bab3f0(last, end, count, *(int*)&flag);
}
}   // namespace f3m_00babba0

// @f3 0x00bae300 (community match, verified in this file)
extern double DAT_00de7c28;
extern float DAT_01178304;
namespace f3m_00bae300 {

struct FUN_00bae300_Obj {
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
    float FUN_00bae300(float a, float b, float c);
};

// pdb: CWindEngine::SetWindStrength | WindEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: fNewStrength, fOldStrength, fOldTimeShift
float FUN_00bae300_Obj::FUN_00bae300(float a, float b, float c) {
    unk04 = a;
    float i;
    i = a * 8.0 * unk1C;
    unk20 = i;
    unk24 = a * DAT_00de7c28 * unk18;
    float y;
    y = 8.0 * b * unk1C;
    *(volatile float*)&unk00 = (y * DAT_01178304 + c) - i * DAT_01178304;
    *(int*)&unk34 = 0;
    *(int*)&unk30 = 0;
    return unk00;
}
}   // namespace f3m_00bae300

// @f3 0x00bba810 (community match, verified in this file)
namespace f3m_00bba810 {
void __cdecl FUN_00c01e8b();
namespace f3m_00bba810 {
struct Elem16 { int a, b, c, d; };
struct VecA;
struct IterA {
    VecA* cont;
    Elem16* ptr;
    IterA() {}
    inline IterA(Elem16* p, VecA* c);
    inline IterA& operator+=(int off);
    IterA operator+(int off) const
    {
        IterA tmp = *this;
        return tmp += off;
    }
    int operator-(const IterA& right) const
    {
        if (cont == 0 || cont != right.cont)
            FUN_00c01e8b();
        return ptr - right.ptr;
    }
};
struct VecA {
    int alloc;
    Elem16* first;
    Elem16* last;
    Elem16* end;
    unsigned int size() const { return first == 0 ? 0 : last - first; }
    IterA begin() { return IterA(first, this); }
    void FUN_00bb9dd0(IterA where, unsigned int count, const Elem16& value);
    IterA FUN_00bba810(IterA where, const Elem16& value);
};
IterA::IterA(Elem16* p, VecA* c)
{
    if (!(c == 0 || (c->first <= p && p <= c->last)))
        FUN_00c01e8b();
    cont = c;
    ptr = p;
}
IterA& IterA::operator+=(int off)
{
    if (!(ptr + off <= cont->last && ptr + off >= cont->first))
        FUN_00c01e8b();
    ptr += off;
    return *this;
}
// pdb: std::vector<float,std::allocator<float> >::vector<float,std::allocator<float> > | FrondEngine.obj | fnv360_0822_retail, call_seq, low
// pdb params: _Right
IterA VecA::FUN_00bba810(IterA where, const Elem16& value)
{
    unsigned int off = size() == 0 ? 0 : where - begin();
    FUN_00bb9dd0(where, 1, value);
    return begin() + off;
}
}
}   // namespace f3m_00bba810

// @f3 0x00ba73e0 (community match, verified in this file)
namespace f3m_00ba73e0 {
void __cdecl FUN_00c01e8b();
struct UIntVector;
struct Iterator {
 UIntVector* owner;
 unsigned int* ptr;
 Iterator(unsigned int* p,UIntVector* v):owner(v),ptr(p){}
 int operator-(const Iterator& r)const {if(!(owner && owner==r.owner))FUN_00c01e8b();return ptr-r.ptr;}
 Iterator& operator+=(int);
 Iterator operator+(int n)const {Iterator temp=*this;return temp+=n;}
};
struct UIntVector {
 unsigned int allocator;
 unsigned int* first;
 unsigned int* last;
 unsigned int* end;
 unsigned int size() const {return first==0 ? 0 : last-first;}
 unsigned int capacity() const {return first==0 ? 0 : end-first;}
 Iterator begin() {unsigned int* p=first;if(p>last)FUN_00c01e8b();return Iterator(p,this);}
 void FUN_00ba5630(Iterator where,unsigned int count,const unsigned int& value);
 Iterator FUN_00ba73e0(Iterator where,const unsigned int& value);
};
Iterator& Iterator::operator+=(int n) {
 unsigned int* p=ptr+n;
 if(p>owner->last || p<owner->first)FUN_00c01e8b();
 ptr=p;return *this;
}
Iterator UIntVector::FUN_00ba73e0(Iterator where,const unsigned int& value) {
 unsigned int offset=size()==0?0:where-begin();
 FUN_00ba5630(where,1,value);
 return begin()+offset;
}
}   // namespace f3m_00ba73e0

// @f3 0x00bb6ab0 (community match, verified in this file)
namespace f3m_00bb6ab0 {
struct Elem { void* unk00;
 void* unk04;
 void* unk08;
 void* unk0C;
 void* unk10;
 void* unk14;
 void* unk18;
 void* unk1C;
 void* unk20;
 void* unk24;
 void* unk28;
 void* unk2C;
 void* unk30;
 void* unk34;};
struct Tag { char c; };
struct Iter { Elem* p; int unk; };

struct FUN_00bb6ab0_Obj {
    int unk00;
    Elem* first;
    Elem* last;
    Elem* endcap;

    void FUN_00bb6290(Iter* out, FUN_00bb6ab0_Obj* al, Elem* where, const Elem* val);
    void FUN_00bb6ab0(const Elem* volatile val);
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    unsigned int capacity() const { return first == 0 ? 0 : (unsigned int)(endcap - first); }
};

void __cdecl FUN_00bb52e0(Elem* dest, unsigned int count, const Elem* val,
                          FUN_00bb6ab0_Obj* al, const Elem* val2, Tag tag);
void __cdecl FUN_00c01e8b();

// pdb: std::vector<SFrondVertex,std::allocator<SFrondVertex> >::push_back | FrondEngine.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: _Val
void FUN_00bb6ab0_Obj::FUN_00bb6ab0(const Elem* volatile val)
{
    Iter it;
    if (size() < capacity()) {
        Elem* d = last;
        Tag t;
        t.c = 0;
        FUN_00bb52e0(d, 1, val, this, val, t);
        last = d + 1;
    } else {
        Elem* w = last;
        if (first > w)
            FUN_00c01e8b();
        FUN_00bb6290(&it, this, w, val);
    }
}
}   // namespace f3m_00bb6ab0

// @f3 0x00bb0850 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0850 {

class Owner_bb0850
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned short unk24;
    unsigned short m_usCount;
    std::vector<int> m_kDeltas;
    std::vector<std::vector<unsigned short> > m_kWords;
    std::vector<std::vector<unsigned int> > m_kDwords;

    void FUN_00bb0850(unsigned short usIdx, unsigned int uiVal, unsigned short usDelta);
};

// pdb: CIndexedGeometry::AddStrip | IndexedGeometry.obj | fnv360_0721_beta, caller, medium
// pdb params: nLodLevel, pStrip, nStripLength
void Owner_bb0850::FUN_00bb0850(unsigned short usIdx, unsigned int uiVal, unsigned short usDelta)
{
    m_kWords[usIdx].resize(m_usCount + 1, 0);
    m_kWords[usIdx][m_usCount] = usDelta;
    m_kDwords[usIdx].resize(m_usCount + 1, 0);
    m_kDwords[usIdx][m_usCount] = uiVal;
    m_kDeltas[usIdx] += usDelta - 2;
}
}   // namespace f3m_00bb0850

// @f3 0x00bae170 (community match, verified in this file)
#include <math.h>
namespace f3m_00bae170 {
struct Mat33x {
    float unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    Mat33x MulX(const Mat33x& o) const;
    void FUN_00bae170(float angle);
};
void Mat33x::FUN_00bae170(float angle)
{
    float r = (float)(angle / DAT_00e31f80);
    float c = cosf(r);
    float s = sinf(r);
    Mat33x m;
    m.unk00 = 1.0f; m.unk04 = 0.0f; m.unk08 = 0.0f;
    m.unk0C = 0.0f; m.unk10 = c; m.unk14 = s;
    m.unk18 = 0.0f; m.unk1C = -s; m.unk20 = c;
    *this = m.MulX(*this);
}
}   // namespace f3m_00bae170

// @f3 0x00bb2a70 (community match, verified in this file)
#include <vector>
namespace f3m_00bb2a70 {

struct FrondVertA { float x, y, z; };
struct FrondVertB { float u, v; };

struct FrondGeometryB2a70 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count20;
    int unk24;
    std::vector<int> indices28;
    std::vector<std::vector<FrondVertA> > strips38;
    std::vector<std::vector<FrondVertB> > strips48;
    void FUN_00bb2a70(unsigned short n);
};

// pdb: CIndexedGeometry::SetNumLodLevels | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: nLevels
void FrondGeometryB2a70::FUN_00bb2a70(unsigned short n)
{
    strips38.clear();
    strips48.clear();
    indices28.clear();
    count20 = n;
    strips38.resize(n);
    strips48.resize(n);
    indices28.resize(n);
    for (int i = 0; i < n; i++)
        indices28[i] = 0;
}
}   // namespace f3m_00bb2a70

// @f3 0x00bae4f0 (community match, verified in this file)
#include <vector>
#include <math.h>


struct Vec3
{
    float x, y, z;
    __forceinline float& operator[](int index)
    {
        return ((float*)this)[index];
    }
    __forceinline Vec3()
    {
        x = y = z = 0.0f;
    }
    __forceinline Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void FUN_00b12790()
    {
        float lengthSquared = x * x + y * y + z * z;
        float length = (float)sqrt((double)lengthSquared);
        float reciprocal = 1.0f / length;
        x *= reciprocal;
        y *= reciprocal;
        z *= reciprocal;
    }
    float FUN_00b2a180(void* ptr)
    {
        const Vec3& rhs = *(const Vec3*)ptr;
        float value = x * rhs.x + y * rhs.y + z * rhs.z;
        return value;
    }
    Vec3 operator-(const Vec3& r) const {return Vec3(x-r.x,y-r.y,z-r.z);}
    Vec3 AddVector(const Vec3& rhs)
    {
        return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    Vec3 ScaleSwizzled(float value)
    {
        return Vec3(x * value, y * value, z * value);
    }
    Vec3& FUN_00b2a1c0(void* ptr)
    {
        const Vec3& rhs = *(const Vec3*)ptr;
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    float FUN_00b04d40(Vec3* rhs)
    {
        float squared = (rhs->x - x) * (rhs->x - x) + (rhs->y - y) * (rhs->y - y) + (rhs->z - z) * (rhs->z - z);
        *(int*)&squared = ((*(int*)&squared) >> 1) + 0x1fc00000;
        return squared;
    }
};
struct Color
{
    float r, g, b;
    __forceinline const float& operator[](int index) const
    {
        return ((const float*)this)[index];
    }
};
static __declspec(noinline) unsigned int PackChannel(float value, bool adjust, unsigned char alpha)
{
    if (adjust)
        value *= (float)(alpha / 255.0);
    if (value > 1.0)
        value = 1.0f;
    if (value < 0.0)
        value = 0.0f;
    return (unsigned int)(int)(value * 255.0);
}
struct GameContext
{
    int unk00;
    Vec3 rotation;
    int unk10;
    unsigned int packed14;
    unsigned char alpha18, unk19, unk1a, unk1b;
    Vec3 location;
    void FUN_00bc5520(float*);
    void FUN_00bc5570(const Color&,bool);
    void FUN_00bc5700(int, Vec3*, float);
    float FUN_00b04d40(Vec3*);
};
typedef std::vector<GameContext*> Record;
typedef Record::iterator Iterator;
struct DeviceData
{
    Vec3 position;
    Vec3 scale;
    Vec3 mix;
    int unk24, unk28, unk2c;
    float transformMode;
    float constant, linear, quadratic;
};
extern DeviceData DAT_01068bf8[8];
extern unsigned char DAT_01178310[8];



__forceinline void BlendWeight(float& weight, float blend)
{
    weight = weight * (1.0 - blend) + blend;
}
struct Scene
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34;
    int state38, unk3c, unk40, unk44;
    Vec3 colors48;
    int unk54, unk58, unk5c;
    Vec3 position60;
    int unk6c;
    float blend70;
    int flags74;
    __forceinline float GetBlend()
    {
        return blend70;
    }
    void FUN_00bae4f0(int output, Record* records, int count);
};
// @fnv 0x00b2a210
void Scene::FUN_00bae4f0(int output, Record* records, int count)
{
    if (state38 == 1 && flags74 != 0)
    {
        for (int i = 0; i < count; ++i)
        {
            Iterator it = records[i].begin();
            for (; it != records[i].end(); ++it)
            {
                void* location = &(*it)->location;
                void* rotationW = &(*it)->rotation;
                Color origin20;
                (*it)->FUN_00bc5520(&origin20.r);
                Vec3 best;
                float maximumW2 = -1.0f;
                Vec3 result5;
                for (int j = 0; j < 8; ++j)
                {
                    if (DAT_01178310[j])
                    {
                        Vec3 dir(DAT_01068bf8[j].position.x, DAT_01068bf8[j].position.y, DAT_01068bf8[j].position.z);
                        Vec3 normal_29 =
                            DAT_01068bf8[j].transformMode == 0.0 ? dir : dir-*(const Vec3*)rotationW;
                        normal_29.FUN_00b12790();
                        float weight = normal_29.FUN_00b2a180(location);
                        if (weight >= maximumW2)
                        {
                            maximumW2 = weight;
                            best = dir;
                        }
                        if (weight < 0.0)
                            weight = 0.0f;
                        BlendWeight(weight, blend70);
                        if ((flags74 & 1) != 0)
                        {
                            Vec3 pos29(position60.x, position60.y, position60.z);
                            Vec3 combined5(DAT_01068bf8[j].mix.x * colors48.x, DAT_01068bf8[j].mix.y * colors48.y,
                                           DAT_01068bf8[j].mix.z * colors48.z);
                            float falloff = 1.0f;
                            if (DAT_01068bf8[j].transformMode != 0.0)
                            {
                                float dist8 = ((Vec3*)rotationW)->FUN_00b04d40(&dir);
                                float poly = DAT_01068bf8[j].constant + DAT_01068bf8[j].linear * dist8 +
                                                   DAT_01068bf8[j].quadratic * dist8 * dist8;
                                if (poly != 0.0)
                                    falloff = 1.0f / poly;
                            }
                            Vec3 attenuation((weight * DAT_01068bf8[j].scale.x) * origin20[0],
                                             (weight * DAT_01068bf8[j].scale.y) * origin20[1],
                                             (weight * DAT_01068bf8[j].scale.z) * origin20[2]);
                            result5.FUN_00b2a1c0(
                                &pos29.AddVector(combined5.AddVector(attenuation).ScaleSwizzled(falloff)));
                        }
                    }
                }
                result5[0]<0.0 ? result5[0] = 0.0 : result5[0]> 1.0 ? result5[0] = 1.0
                                                                                      : result5[0] = result5[0];
                result5[1]<0.0 ? result5[1] = 0.0 : result5[1]> 1.0 ? result5[1] = 1.0
                                                                                      : result5[1] = result5[1];
                result5[2]<0.0 ? result5[2] = 0.0 : result5[2]> 1.0 ? result5[2] = 1.0
                                                                                      : result5[2] = result5[2];
                if ((flags74 & 1) != 0)
                {
                    (*it)->FUN_00bc5570((Color&)result5, 0);
                }
                if ((flags74 & 2) != 0)
                {
                    (*it)->FUN_00bc5700(output, &best, blend70);
                }
            }
        }
    }
}

// @f3 0x00baa440 (community match, verified in this file)
namespace f3m_00baa440 {
void __cdecl FUN_00baa440(int* _First, int* _Mid, int* _Last)
{
    int _Shift = _Mid - _First;
    int _Count = _Last - _First;

    for (int _Factor = _Shift; _Factor != 0; ) {
        int _Tmp = _Count % _Factor;
        _Count = _Factor, _Factor = _Tmp;
    }

    if (_Count < _Last - _First)
        for (; 0 < _Count; --_Count) {
            int* _Hole = _First + _Count;
            int* _Next = _Hole;
            int _Holeval = *_Hole;
            int* _Next1 = _Next + _Shift == _Last ? _First : _Next + _Shift;
            while (_Next1 != _Hole) {
                *_Next = *_Next1;
                _Next = _Next1;
                _Next1 = _Shift < _Last - _Next1 ? _Next1 + _Shift
                    : _First + (_Shift - (_Last - _Next1));
            }
            *_Next = _Holeval;
        }
}
}   // namespace f3m_00baa440

// @f3 0x00bb5670 (community match, verified in this file)
namespace f3m_00bb5670 {
void __cdecl FUN_00401010(void* p) throw();
namespace f3m_00bb5670 {
struct Str {
    int alloc;
    union { char buf[16]; char* ptr; };
    unsigned int size;
    unsigned int capacity;
    Str& FUN_0042eff0(const Str& o, unsigned int pos, unsigned int n);
    __forceinline Str(const Str& o) { capacity = 15; size = 0; *(volatile char*)&buf[0] = 0; FUN_0042eff0(o, 0, (unsigned int)-1); }
    ~Str() { if (capacity >= 16) FUN_00401010(ptr); }
};
struct Obj {
    Str name;
    float unk1C, unk20, unk24, unk28;
    __forceinline Obj(const Obj& o) : name(o.name), unk1C(o.unk1C), unk20(o.unk20), unk24(o.unk24), unk28(o.unk28) {}
};
__forceinline void Construct(Obj* p, const Obj& v)
{
    p = ::new ((void*)p) Obj(v);
}
void __cdecl FUN_00bb5670(Obj* dst, const Obj* src)
{
    Construct(dst, *src);
}
}
}   // namespace f3m_00bb5670

// @f3 0x00bb71d0 (community match, verified in this file)
namespace f3m_00bb71d0 {
void __cdecl FUN_00c01e8b();
namespace f3m_00bb71d0 {
struct Block36 { int b00, b04, b08, b0c, b10, b14, b18, b1c, b20; };
struct Args56 {
    int a00, a04, a08;
    Block36 blk;
    float f30;
    int a34;
};
struct Element48 {
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    void __thiscall FUN_00bb6ab0(const Args56* args);
};
struct Owner {
    int u00, u04, u08;
    Element48* first;
    Element48* last;
    unsigned int size() const { Element48* f = *(Element48* volatile*)&first; return f == 0 ? 0 : (unsigned int)(last - f); }
    Element48& at(unsigned int i)
    {
        if (i >= size())
            FUN_00c01e8b();
        return first[i];
    }
    void __thiscall FUN_00bb71d0(int a0, int a1, int a2, Block36 blk, float f, int a13);
};
// pdb: CFrondEngine::AddGuideVertex | FrondEngine.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: cPos, cTrans, fCrossSectionWeight, nWindGroup
void Owner::FUN_00bb71d0(int a0, int a1, int a2, Block36 blk, float f, int a13)
{
    Args56 args;
    args.a00 = a0;
    args.a04 = a1;
    args.a08 = a2;
    args.blk = blk;
    args.f30 = f;
    args.a34 = a13;
    at(size() - 1).FUN_00bb6ab0(&args);
}
}
}   // namespace f3m_00bb71d0

// @f3 0x00bbac30 (community match, verified in this file)
namespace f3m_00bbac30 {
struct Elem { int unk00; int unk04; int unk08; int unk0c; };
struct Allocator {};
struct NonScalarTag {};
struct RangeCheckedTag {};
template<class T> inline NonScalarTag PointerCategory(T&, T&) { NonScalarTag tag; return tag; }
void __cdecl FUN_00bb6cd0(Elem*, unsigned, const Elem&, Allocator&, NonScalarTag, RangeCheckedTag);
void __cdecl FUN_00c01e8b();

struct Iter { unsigned int unk00; void* owner; };

class Obj_bbac30 {
public:
    Allocator allocator;
    Elem* unk04;
    Elem* unk08;
    Elem* unk0C;

    void FUN_00bba810(Iter* it, Obj_bbac30* self, Elem* end, const Elem& value);
    unsigned int size() const { return unk04 == 0 ? 0 : unk08 - unk04; }
    unsigned int capacity() const { return unk04 == 0 ? 0 : unk0C - unk04; }
    void FUN_00bbac30(const Elem* pv);
};

// pdb: std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >::push_back | FrondEngine.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Val
void Obj_bbac30::FUN_00bbac30(const Elem* pv)
{
    Iter it;
    unsigned int sz = size();
    if (unk04 != 0 && sz < capacity()) {
        Elem* end = unk08;
        FUN_00bb6cd0(end, 1, *pv, allocator, PointerCategory(pv, pv), RangeCheckedTag());
        unk08 = end + 1;
        return;
    }
    Elem* end = unk08;
    if (unk04 > end)
        FUN_00c01e8b();
    FUN_00bba810(&it, this, end, *pv);
}
}   // namespace f3m_00bbac30

// @f3 0x00bbc520 (community match, verified in this file)
#include <memory>
namespace f3m_00bbc520 {

void __cdecl FUN_00c01e8b();
namespace f3m_00bbc520 {
struct Elem16 { int a, b, c, d; };
struct Vec16;
struct Iter16 {
    Vec16* cont; Elem16* ptr;
    Iter16(Elem16* p, Vec16* v);
};
struct Vec16 {
    std::allocator<Elem16> alval;
    Elem16* first;
    Elem16* last;
    Elem16* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    unsigned int capacity() const { return first == 0 ? 0 : (unsigned int)(end - first); }
    Elem16* Ufill(Elem16* p, unsigned int n, const Elem16& val)
    {
        stdext::unchecked_uninitialized_fill_n(p, n, val, alval);
        return p + n;
    }
    Iter16 FUN_00bbc270(Iter16 where, const Elem16& val);
    void FUN_00bbc520(const Elem16& val);
};
inline Iter16::Iter16(Elem16* p, Vec16* v)
{
    if (v != 0 && (v->first > p || p > v->last))
        FUN_00c01e8b();
    cont = v;
    ptr = p;
}
// pdb: std::vector<std::vector<SFrondGuide,std::allocator<SFrondGuide> >,std::allocator<std::vector<SFrondGuide,std::allocator<SFrondGuide> > > >::push_back | FrondEngine.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: _Val
void Vec16::FUN_00bbc520(const Elem16& val)
{
    if (size() < capacity())
        last = Ufill(last, 1, val);
    else
        FUN_00bbc270(Iter16(last, this), val);
}
}
}   // namespace f3m_00bbc520

// @f3 0x00bba060 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <stdarg.h>
extern const char DAT_00ea7cd0[];
extern const char DAT_00ea7cb0[];
namespace f3m_00bba060 {
template<class T> struct TreeAllocatorReader : std::allocator<T> {
 template<class U> struct rebind { typedef TreeAllocatorReader<U> other; };
 TreeAllocatorReader() throw() {}
 template<class U> TreeAllocatorReader(const TreeAllocatorReader<U>&) throw() {}
 T* allocate(size_t n,const void* =0) { return (T*)DAT_01090a78.FUN_0086b930(n*sizeof(T)); }
 void deallocate(T* p,size_t) { DAT_01090a78.FUN_0086ba60(p); }
};
template<class T,class U> bool operator==(const TreeAllocatorReader<T>&,const TreeAllocatorReader<U>&) { return true; }
template<class T,class U> bool operator!=(const TreeAllocatorReader<T>&,const TreeAllocatorReader<U>&) { return false; }
typedef std::basic_string<char,std::char_traits<char>,TreeAllocatorReader<char> > ReaderString;

struct Reader {
 int FUN_00ba92d0(); float FUN_00ba92a0(); bool FUN_00ba1a80(); void* CTreeFileAccess_ParseBranchParameter(); ReaderString FUN_00ba9460();
};
struct FUN_00ba37a0 : std::string {
 FUN_00ba37a0() {}
 FUN_00ba37a0(ReaderString s);
 FUN_00ba37a0 FUN_00ba3c00() const;
};

static __declspec(noinline) std::string __cdecl FUN_00bb56f0(const char* fmt, ...) {
 char buffer[1024]; buffer[0] = 0; va_list args; va_start(args,fmt); vsprintf(buffer,fmt,args); va_end(args); return std::string(buffer);
}
struct Record {
 FUN_00ba37a0 name;
 float a,b,c,d;
 Record() : name(),a(.5f),b(1),c(0),d(0) {}
};
struct Collection { unsigned unk00,unk04,unk08,unk0C; void FUN_00bb91e0(); void FUN_00bb9cc0(const Record&); };
struct Target {
 unsigned unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24;
 int unk28,unk2C,unk30,unk34,unk38; bool unk3C;
 Collection unk40;
 int unk50; float unk54,unk58,unk5C,unk60; int unk64,unk68;
 void FUN_00bb45d0(void*);
 void FUN_00bba060(Reader*);
};
// pdb: CFrondEngine::Parse | FrondEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void Target::FUN_00bba060(Reader* r) {
 int token=r->FUN_00ba92d0();
 do {
 switch(token) {
 case 0x32ca: unk38=r->FUN_00ba92d0(); break;
 case 0x32cb: unk28=r->FUN_00ba92d0(); break;
 case 0x32cc: unk2C=r->FUN_00ba92d0(); break;
 case 0x32cd: FUN_00bb45d0(r->CTreeFileAccess_ParseBranchParameter()); break;
 case 0x32ce: unk34=r->FUN_00ba92d0(); break;
 case 0x32cf: unk3C=r->FUN_00ba1a80(); break;
 case 0x32d1: unk50=r->FUN_00ba92d0(); break;
 case 0x32d2: unk54=r->FUN_00ba92a0(); break;
 case 0x32d3: unk58=r->FUN_00ba92a0(); break;
 case 0x32d4: unk5C=r->FUN_00ba92a0(); break;
 case 0x32d5: unk60=r->FUN_00ba92a0(); break;
 case 0x32d0: {
  unk40.FUN_00bb91e0();
  int count=r->FUN_00ba92d0();
  for(int i=0;i<count;++i) {
   Record rec;
   r->FUN_00ba92d0();
   token=r->FUN_00ba92d0();
   do {
    switch(token) {
    case 0x36b2: rec.name = r->FUN_00ba9460(); rec.name = rec.name.FUN_00ba3c00(); break;
    case 0x36b3: rec.a=r->FUN_00ba92a0(); break;
    case 0x36b4: rec.b=r->FUN_00ba92a0(); break;
    case 0x36b5: rec.c=r->FUN_00ba92a0(); break;
    case 0x36b6: rec.d=r->FUN_00ba92a0(); break;
    default: throw IdvFileError(FUN_00bb56f0(DAT_00ea7cd0,token),0);
    }
    token=r->FUN_00ba92d0();
   } while(token!=0x36b1);
   unk40.FUN_00bb9cc0(rec);
  }
  break;
 }
 case 0x36b7: unk64=r->FUN_00ba92d0(); break;
 case 0x36b8: unk68=r->FUN_00ba92d0(); break;
 default: throw IdvFileError(FUN_00bb56f0(DAT_00ea7cb0,token),0);
 }
 token=r->FUN_00ba92d0();
 } while(token!=0x32c9);
}

}   // namespace f3m_00bba060

// @f3 0x00bbffa0 (community match, verified in this file)
#include <vector>
#include <string>
namespace f3m_00bbffa0 {

struct Item00bbffa0 {
    char unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    std::string name;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
};

class ItemVector00bbffa0 : public std::vector<Item00bbffa0>
{
public:
    iterator FUN_00bbffa0(iterator _First, iterator _Last);
};

// pdb: std::vector<SIdvLeafTexture,std::allocator<SIdvLeafTexture> >::resize | LeafInfo.obj | fnv360_1110_retail, caller_sim, low
// pdb params: _Newsize
ItemVector00bbffa0::iterator ItemVector00bbffa0::FUN_00bbffa0(iterator _First, iterator _Last)
{
    if (_First != _Last)
    {
        pointer _Ptr = stdext::unchecked_copy(_Last._Myptr, _Mylast, _First._Myptr);
        _Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}
}   // namespace f3m_00bbffa0

// @f3 0x00bac160 (community match, verified in this file)
#include <math.h>
namespace f3w_bac160 {



void __cdecl FUN_00c01e8b();

struct Vec3
{
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 Cross(const Vec3& o) const { return Vec3(y * o.z - o.y * z, z * o.x - o.z * x, x * o.y - o.x * y); }
    __declspec(noinline) void FUN_00ba95b0()
    {
        float len = x * x + y * y + z * z;
        len = (float)sqrt(len);
        float inv = 1.0f / len;
        x *= inv;
        y *= inv;
        z *= inv;
    }
};

__declspec(noinline) Vec3 FUN_00ba9a90(const Vec3& a, const Vec3& b, float f)
{
    Vec3 d(b.x - a.x, b.y - a.y, b.z - a.z);
    Vec3 s(d.x * f, d.y * f, d.z * f);
    return Vec3(a.x + s.x, s.y + a.y, a.z + s.z);
}
struct Node
{
    Node* parent;
    float f4;
};
static __declspec(noinline) float FUN_00baa240(Node* n)
{
    if (n == 0 || n->parent == 0) return 0.0f;
    float t = FUN_00baa240(n->parent);
    return t + (1.0f - t) * n->f4;
}

__forceinline float Blend(float t, float f)
{
    return t + (1.0f - t) * f;
}
__forceinline float Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}
__forceinline float Blend2(float f, float t)
{
    return t + (1.0f - t) * f;
}

struct Info
{
    int unk00;
    float f4;
    float f8;
    float fc;
    float f10;
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
    float unk44;
    int unk48;
    int unk4c;
    int unk50;
};

struct InfoVec
{
    int alloc;
    Info* first;
    Info* last;
    Info* end;
    Info& FUN_00baa280(unsigned int i);
};

struct IntVec
{
    int alloc;
    int* first;
    int* last;
    int* end;
    unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
    int& operator[](unsigned int i)
    {
        if (first == 0 || i >= size()) FUN_00c01e8b();
        return first[i];
    }
    int& FUN_00baa2e0(unsigned int i);
};

struct Shared
{
    bool flag;
    float f4;
    int unk08;
    int mode;
    InfoVec infos;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int count38;
    unsigned int InfoCount() const { return infos.first == 0 ? 0 : (unsigned int)(infos.last - infos.first); }
};
extern Shared* DAT_011782b0;

struct Random
{
    float FUN_00bc4b40(float lo, float hi);
};
extern Random DAT_011782c1;

struct FUN_00bc5370;
struct ParticleList
{
    void FUN_00babf00(FUN_00bc5370* const& p);
};
extern IntVec DAT_011782c4;
extern IntVec DAT_011782e4;
extern ParticleList DAT_011782f4;

extern int DAT_00ea80bc;
struct FUN_00ba9530 {void* table;Vec3 position;FUN_00ba9530();};
struct FUN_00bc5370 : FUN_00ba9530
{
    __declspec(noinline) FUN_00bc5370(const Vec3& a, char b, int c, float d, int e);
    unsigned char variant; unsigned char unk11,unk12,unk13;
    int id;
    unsigned char alpha; unsigned char unk19,unk1a,unk1b;
    Vec3 dir;
    Vec3 dir2;
    Vec3 side;
    unsigned char index;
    float unk44;
    int unk48;
    void SetA(const Vec3& v) {dir=v;}
    void SetB(const Vec3& v) {dir2=v;}
    void SetC(const Vec3& v) {side=v;}
    void FUN_00bc5570(const Vec3& offset, bool flag);
};



__declspec(noinline) FUN_00bc5370::FUN_00bc5370(const Vec3& a, char b, int c, float d, int e):FUN_00ba9530() {
 table=&DAT_00ea80bc;
 variant=(unsigned char)c;id=-1;alpha=(unsigned char)b;
 dir.z=dir.y=dir.x=0;
 dir2.z=dir2.y=dir2.x=0;
 side.z=side.y=side.x=0;
 index=0;unk44=d;unk48=e;
 position=a;
}

struct Emitter
{
    bool FUN_00ba9e40(Node* a, float b);
    bool FUN_00baa550(const Vec3& a, int b, ParticleList* list);
    void FUN_00bac160(const Vec3& a0, float a1, Node* a2, Vec3* a3, Vec3* a4, float a5, int a6, ParticleList* a7);
};

void Emitter::FUN_00bac160(const Vec3& a0, float a1, Node* a2, Vec3* a3, Vec3* a4, float a5, int a6, ParticleList* a7)
{
    if (DAT_011782b0->InfoCount() == 0) return;
    int index;
    if (DAT_011782e4.size() != 0 && FUN_00ba9e40(a2, a1))
    {
        unsigned int i = 0;
        if (DAT_011782e4.size() > 1)
            i = (unsigned int)DAT_011782c1.FUN_00bc4b40(0.0f, ::FUN_00e09708) % DAT_011782e4.size();
        index = DAT_011782e4[i];
    }
    else
    {
        if (DAT_011782c4.size() > 1)
        {
            float r = DAT_011782c1.FUN_00bc4b40(0.0f, 1000000.0f);
            unsigned int i = (unsigned int)r % DAT_011782c4.size();
            index = DAT_011782c4[i];
        }
        else if (DAT_011782c4.size() == 0)
            return;
        else
            index = DAT_011782c4.FUN_00baa2e0(0);
    }
    bool ok = true;
    switch (DAT_011782b0->mode)
    {
    case 1:
        ok = FUN_00baa550(a0, index / 2, &DAT_011782f4);
        break;
    case 2:
        ok = FUN_00baa550(a0, index / 2, a7);
        break;
    }
    if (!ok) return;
    float alpha = 1.0f;
    if (DAT_011782b0->flag)
    {
        float t = FUN_00baa240(a2);
        t = t + (1.0f - t) * a1;
        t = t * t * t;
        alpha = Blend(t, 1.0f - DAT_011782b0->f4);
    }
    FUN_00bc5370* p = new FUN_00bc5370(a0, (int)(alpha * 255.0), (int)DAT_011782c1.FUN_00bc4b40(0.0f, 10000.0f) % DAT_011782b0->count38, a5, a6);
    {
        FUN_00bc5370* item = p;
        a7->FUN_00babf00(item);
        if (DAT_011782b0->mode == 1) DAT_011782f4.FUN_00babf00(item);
    }
    Info& info = DAT_011782b0->infos.FUN_00baa280(index / 2);
    p->index = (unsigned char)index;
    float len = a3->x * a3->x + a3->y * a3->y + a3->z * a3->z;
    *(int*)&len = (*(int*)&len >> 1) + 0x1fc00000;
    Vec3 dir;
    if (len < 0.0001) dir = *a4; else dir = FUN_00ba9a90(*a4, *a3, info.f10);
    dir.FUN_00ba95b0();
    Vec3& d1 = p->dir; d1 = dir;
    Vec3& d2 = p->dir2; d2 = dir;
    Vec3 side = dir.Cross(dir);
    side.FUN_00ba95b0();
    p->SetC(side);
    float r = DAT_011782c1.FUN_00bc4b40(-info.f10, info.f10);
    Vec3 offset(info.f4 + r, info.f8 + r, info.fc + r);
    p->FUN_00bc5570(offset, true);
}

}

// @f3 0x00babd50 (community match, verified in this file)
#include <vector>
namespace f3m_00babd50 {

class FUN_00babd50 {
public:
    explicit FUN_00babd50(void* owner);
    void* owner;
    float weight;
    std::vector<int> first;     // 0x08
    int unk18;
    int index1c;
    short unk20;
    int index24;
    float unk28;
    float unk2c;
    std::vector<int> second;    // 0x30
};

FUN_00babd50::FUN_00babd50(void* owner)
    : owner(owner), weight(0.0f), unk18(0), index1c(-1), unk20(0), index24(-1), unk28(0.0f), unk2c(0.0f)
{
}
}   // namespace f3m_00babd50

// @f3 0x00bb1f50 (community match, verified in this file)
#include <vector>
namespace f3m_00bb1f50 {

namespace f3m_00bb1f50 {
struct Loader {
    void FUN_00bb1670(int source, std::vector<int>& scratch);
    Loader* FUN_00bb1f50(int source);
};
}

f3m_00bb1f50::Loader* f3m_00bb1f50::Loader::FUN_00bb1f50(int source)
{
    std::vector<int> scratch;
    FUN_00bb1670(source, scratch);
    return this;
}
}   // namespace f3m_00bb1f50

// @f3 0x00bb5490 (community match, verified in this file)
#include <vector>
namespace f3m_00bb5490 {

namespace f3m_00bb5490 {
struct Elem { int v[14]; Elem(const Elem& o) { for (int i = 0; i < 14; i++) v[i] = o.v[i]; } };
struct List : std::vector<Elem> {
    iterator FUN_00bb5490(iterator first, iterator last);
};
}

// pdb: std::_Uninitialized_copy<std::_Vector_const_iterator<std::_Vector_val<SFrondVertex,std::allocator<SFrondVertex> > >,SFrondVertex *,std::allocator<SFrondVertex> > | FrondEngine.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: _First, _Last, _Dest, _Al
f3m_00bb5490::List::iterator f3m_00bb5490::List::FUN_00bb5490(iterator first, iterator last)
{
    if (first != last) {
        pointer ptr = stdext::unchecked_copy(_VEC_ITER_BASE(last), _Mylast, _VEC_ITER_BASE(first));
        _Destroy(ptr, _Mylast);
        _Mylast = ptr;
    }
    return first;
}
}   // namespace f3m_00bb5490

// @f3 0x00babf00 (community match, verified in this file)
#include <vector>
namespace f3m_00babf00 {

namespace f3m_00babf00 {
// std::vector<int>::push_back, written out on a derived class (the library body, VC8 release)
struct IntList : std::vector<int> {
    void FUN_00babf00(const int& value);
};
}

void f3m_00babf00::IntList::FUN_00babf00(const int& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00babf00

// @f3 0x00ba9330 (community match, verified in this file)
#include <vector>
namespace f3m_00ba9330 {

namespace f3m_00ba9330 {
struct Vec3 {
    float x, y, z;
    float& operator[](int i) { return (&x)[i]; }
};
struct Reader {
    unsigned int position;
    std::vector<char> data;   // 0x04
    float ReadFloat()
    {
        const char& c = data[position];
        position += 4;
        return *(const float*)&c;
    }
    Vec3& FUN_00ba9330(Vec3& v);
};
}

// pdb: CTreeFileAccess::ParseVector3 | FileAccess.obj | fnv360_0822_retail, objrun, medium
f3m_00ba9330::Vec3& f3m_00ba9330::Reader::FUN_00ba9330(Vec3& v)
{
    v.x = v.y = v.z = 0.0f;
    for (int i = 0; i < 3; i++)
        v[i] = ReadFloat();
    return v;
}
}   // namespace f3m_00ba9330

// @f3 0x00bb9cc0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb9cc0 {

namespace f3m_00bb9cc0 {
struct Elem { int v[11]; };
// std::vector<Elem>::push_back, written out on a derived class (the library body, VC8 release)
struct List : std::vector<Elem> {
    void FUN_00bb9cc0(const Elem& value);
};
}

// pdb: std::vector<SFrondTexture,std::allocator<SFrondTexture> >::push_back | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: _Val
void f3m_00bb9cc0::List::FUN_00bb9cc0(const Elem& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00bb9cc0

// @f3 0x00ba81b0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba81b0 {

namespace f3m_00ba81b0 {
struct Elem { int v[7]; };
// std::vector<Elem>::push_back, written out on a derived class (the library body, VC8 release)
struct List : std::vector<Elem> {
    void FUN_00ba81b0(const Elem& value);
};
}

// pdb: std::vector<SShape,std::allocator<SShape> >::push_back | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: _Val
void f3m_00ba81b0::List::FUN_00ba81b0(const Elem& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00ba81b0

// @f3 0x00babe60 (community match, verified in this file)
#include <vector>
namespace f3m_00babe60 {

namespace f3m_00babe60 {
struct Elem { int v[6]; };
// std::vector<Elem>::push_back, written out on a derived class (the library body, VC8 release)
struct List : std::vector<Elem> {
    void FUN_00babe60(const Elem& value);
};
}

// pdb: std::vector<SIdvBranchFlare,std::allocator<SIdvBranchFlare> >::push_back | Branch.obj | fnv360_0721_beta, call_seq, medium
// pdb params: _Val
void f3m_00babe60::List::FUN_00babe60(const Elem& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00babe60

// @f3 0x00bb63e0 (community match, verified in this file)
#include <string>

namespace f3m_00bb63e0 {
struct Heap {
    void* FUN_0086b930(unsigned int bytes);
    void FUN_0086ba60(void* p);
};
extern Heap DAT_01090a78;
// the game's STL allocator (memory manager at 0x1090a78)
template <class T> class Alloc {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T* const_pointer;
    typedef const T& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc&) {}
    template <class U> Alloc(const Alloc<U>&) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { DAT_01090a78.FUN_0086ba60(p); }
    void construct(pointer p, const T& v) { ::new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { size_type n = (size_type)(-1) / sizeof(T); return 0 < n ? n : 1; }
};
template <class T, class U> inline bool operator==(const Alloc<T>&, const Alloc<U>&) { return true; }
template <class T, class U> inline bool operator!=(const Alloc<T>&, const Alloc<U>&) { return false; }
typedef std::basic_string<char, std::char_traits<char>, Alloc<char> > String;
struct Elem {
    String name;
    float a, b, c, d;
};
}

// std::_Fill for a {string, 4 floats} element (VC8 xutility body)
void __cdecl FUN_00bb63e0(f3m_00bb63e0::Elem* first, f3m_00bb63e0::Elem* last, const f3m_00bb63e0::Elem& value)
{
    for (; first != last; ++first)
        *first = value;
}

// @f3 0x00bb0300 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bb0300 {

namespace f3m_00bb0300 {
struct Elem {
    int a, b, c, d;
    Elem& FUN_00bafc60(const Elem& other);   // operator=
    Elem& operator=(const Elem& other) { return FUN_00bafc60(other); }
};
}

// std::_Copy_opt, random-access version for a non-scalar 16-byte element (VC8 xutility body)
f3m_00bb0300::Elem* __cdecl FUN_00bb0300(f3m_00bb0300::Elem* first, f3m_00bb0300::Elem* last, f3m_00bb0300::Elem* dest,
                                         std::random_access_iterator_tag, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    f3m_00bb0300::Elem* result = dest + (last - first);
    std::_Copy_opt(first, last, std::_Checked_base(dest), std::forward_iterator_tag(), std::_Nonscalar_ptr_iterator_tag(), std::_Range_checked_iterator_tag());
    return result;
}
}   // namespace f3m_00bb0300

// @f3 0x00babdc0 (community match, verified in this file)
#include <vector>
namespace f3m_00babdc0 {

namespace f3m_00babdc0 {
struct Elem { int v[3]; };
// std::vector<Elem>::push_back, written out on a derived class (the library body, VC8 release)
struct List : std::vector<Elem> {
    void FUN_00babdc0(const Elem& value);
};
}

// pdb: std::vector<SIdvBranch,std::allocator<SIdvBranch> >::push_back | Branch.obj | fnv360_0822_retail, call_gap, low
// pdb params: _Val
void f3m_00babdc0::List::FUN_00babdc0(const Elem& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00babdc0

// @f3 0x00bbbaa0 (community match, verified in this file)
#include <vector>
namespace f3m_00bbbaa0 {

namespace f3m_00bbbaa0 {
struct Elem { int v[12]; };
// std::vector<Elem>::push_back, written out on a derived class (the library body, VC8 release)
struct List : std::vector<Elem> {
    void FUN_00bbbaa0(const Elem& value);
};
}

void f3m_00bbbaa0::List::FUN_00bbbaa0(const Elem& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        insert(end(), value);
}
}   // namespace f3m_00bbbaa0

// @f3 0x00bb9980 (community match, verified in this file)
#include <vector>
namespace f3m_00bb9980 {

namespace f3m_00bb9980 {
struct Elem { int v[11]; Elem(const Elem& o) { for (int i = 0; i < 11; i++) v[i] = o.v[i]; } };
struct List : std::vector<Elem> {
    iterator FUN_00bb9980(iterator where, const Elem& value);
};
}

// std::vector::insert(where, value) (VC8 release body)
// pdb: SFrondTexture::SFrondTexture | FrondEngine.obj | fnv360_0822_retail, call_seq, medium
// pdb params: __that
f3m_00bb9980::List::iterator f3m_00bb9980::List::FUN_00bb9980(iterator where, const Elem& value)
{
    size_type off = size() == 0 ? 0 : where - begin();
    _Insert_n(where, (size_type)1, value);
    return begin() + off;
}
}   // namespace f3m_00bb9980

// @f3 0x00bb20c0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb20c0 {

namespace f3m_00bb20c0 {
typedef std::vector<int> Elem;
struct List : std::vector<Elem> {
    void FUN_00bb20c0(size_type newSize, Elem value);
};
}

// std::vector::resize(n, value) (VC8 release body)
void f3m_00bb20c0::List::FUN_00bb20c0(size_type newSize, Elem value)
{
    if (size() < newSize)
        _Insert_n(end(), newSize - size(), value);
    else if (newSize < size())
        erase(begin() + newSize, end());
}
}   // namespace f3m_00bb20c0

// @f3 0x00bb1ed0 (community match, verified in this file)
#include <vector>
namespace f3m_00bb1ed0 {

namespace f3m_00bb1ed0 {
struct Loader {
    void FUN_00bb15b0(int source, std::vector<int>& scratch);
    Loader* FUN_00bb1ed0(int source);
};
}

f3m_00bb1ed0::Loader* f3m_00bb1ed0::Loader::FUN_00bb1ed0(int source)
{
    std::vector<int> scratch;
    FUN_00bb15b0(source, scratch);
    return this;
}
}   // namespace f3m_00bb1ed0

// @f3 0x00bb0f40 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0f40 {

namespace f3m_00bb0f40 {
struct Elem { int a, b, c, d; Elem(const Elem& o) : a(o.a), b(o.b), c(o.c), d(o.d) {} };
struct List : std::vector<Elem> {
    pointer FUN_00bb0f40(const Elem* first, const Elem* last, pointer ptr);
};
}

f3m_00bb0f40::List::pointer f3m_00bb0f40::List::FUN_00bb0f40(const Elem* first, const Elem* last, pointer ptr)
{
    return stdext::unchecked_uninitialized_copy(first, last, ptr, this->_Alval);
}
}   // namespace f3m_00bb0f40

// @f3 0x00bb5310 (community match, verified in this file)
#include <vector>
namespace f3m_00bb5310 {

namespace f3m_00bb5310 {
struct Vec2 { int a, b, c; };
}

// std::_Uninit_fill_n for Vec2 (VC8 xmemory body)
void __cdecl FUN_00bb5310(f3m_00bb5310::Vec2* first, unsigned int count, const f3m_00bb5310::Vec2& value,
                          std::allocator<f3m_00bb5310::Vec2>& al, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    f3m_00bb5310::Vec2* next = first;
    try {
        for (; 0 < count; --count, ++first)
            al.construct(first, value);
    } catch (...) {
        for (; next != first; ++next)
            al.destroy(next);
        throw;
    }
}
}   // namespace f3m_00bb5310

// @f3 0x00bb1100 (community match, verified in this file)
#include <vector>
namespace f3m_00bb1100 {

namespace f3m_00bb1100 {
struct Item;
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    std::vector<std::vector<Item*> > lists;   // 0x48
    void FUN_00bb1100();
};
}

// pdb: CIndexedGeometry::DeleteIndexData | IndexedGeometry.obj | fnv360_0822_retail, call_seq, medium
void f3m_00bb1100::Owner::FUN_00bb1100()
{
    for (unsigned int i = 0; i < lists.size(); i++) {
        for (unsigned int j = 0; j < lists[i].size(); j++) {
            delete lists[i][j];
            lists[i][j] = 0;
        }
        lists[i].clear();
    }
    lists.clear();
}
}   // namespace f3m_00bb1100

// @f3 0x00bb9140 (community match, verified in this file)
namespace f3m_00bb9140 {
namespace f3m_00bb9140 {
struct FUN_00bb5880 {
    unsigned int allocator;
    void* first;
    void* last;
    void* end;
    FUN_00bb5880(const FUN_00bb5880&);
    ~FUN_00bb5880();
};
struct Element {
    FUN_00bb5880 list;
    float x, y;
    bool flag;
    float z, w, v;
    int first, last;
};
void __cdecl FUN_00bb6e70(Element* first, int hole, int bottom, Element value, unsigned compare);

// std::_Make_heap: sift down every parent from the middle to the root
void __cdecl FUN_00bb9140(Element* first, Element* last, unsigned compare, int*, Element*)
{
    int bottom = last - first;
    for (int hole = bottom / 2; 0 < hole;)
    {
        --hole;
        FUN_00bb6e70(first, hole, bottom, first[hole], compare);
    }
}
}
}   // namespace f3m_00bb9140

// @f3 0x00bb9c60 (community match, verified in this file)
namespace f3m_00bb9c60 {
namespace f3m_00bb9c60 {
struct Elem {
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
};

struct RandomTag {};
struct MoveTag {};
struct CheckedTag {};
struct ScalarTag {};

inline RandomTag IterRandom(Elem*, Elem*) { RandomTag t; return t; }
inline MoveTag MoveCat(Elem*) { MoveTag t; return t; }
inline ScalarTag PtrCat(Elem*, Elem*) { ScalarTag t; return t; }

struct Vec;
struct Iter {
    Vec* cont;
    Elem* ptr;
};

Elem* __cdecl FUN_00bb6c10(Elem* first, Elem* last, Elem* dest, RandomTag, MoveTag, CheckedTag);
void __cdecl FUN_00bb8e80(Elem* first, Elem* last, Vec* al, ScalarTag);

struct Vec {
    Elem* first;
    Elem* unk04;
    Elem* last;
    Iter FUN_00bb9c60(Iter where);
};

// pdb: std::vector<SFrondGuide,std::allocator<SFrondGuide> >::erase | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _Where
Iter Vec::FUN_00bb9c60(Iter where)
{
    FUN_00bb6c10(where.ptr + 1, last, where.ptr, IterRandom(where.ptr + 1, where.ptr), MoveCat(where.ptr), CheckedTag());
    FUN_00bb8e80(last - 1, last, this, PtrCat(last - 1, last));
    --last;
    return where;
}
}
}   // namespace f3m_00bb9c60

// @f3 0x00ba2a00 (community match, verified in this file)
namespace f3m_00ba2a00 {
namespace f3m_00ba2a00 {
struct Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short count20;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    std::vector<std::vector<short> > table38;
    void* FUN_00ba2a00(unsigned short index);
};
void* Owner::FUN_00ba2a00(unsigned short index)
{
    short i = (short)index;
    if (i >= 0 && i < count20 && !table38[i].empty())
        return &table38[i][0];
    return 0;
}
}
}   // namespace f3m_00ba2a00

// @f3 0x00bbbe30 (community match, verified in this file)
namespace f3m_00bbbe30 {
namespace f3m_00bbbe30 {
extern "C" void __cdecl FUN_00401010(void* p);
struct Vector {
    unsigned allocator;
    void* begin;
    void* end;
    void* capacity;
    Vector() : begin(0), end(0), capacity(0) {}
    ~Vector() { if (begin) FUN_00401010(begin); }
};
struct Query {
    Vector list;
    float f10;
    float f14;
    bool b18;
    float f1c;
    float f20;
    float f24;
    int i28;
    int i2c;
    Query() : f10(0.0f), f14(0.0f), b18(false), f1c(0.0f), f20(0.0f), f24(0.0f), i28(0), i2c(0) {}
};
struct Sub { void FUN_00bbbaa0(Query*); };
struct Obj {
    int unk00;
    int unk04;
    Sub sub;
    void FUN_00bbbe30();
};
// pdb: CFrondEngine::StartGuide | FrondEngine.obj | fnv360_0721_beta, objrun_prop, low
void Obj::FUN_00bbbe30()
{
    Query q;
    sub.FUN_00bbbaa0(&q);
}
}
}   // namespace f3m_00bbbe30

// @f3 0x00bbbdb0 (community match, verified in this file)
namespace f3m_00bbbdb0 {
namespace f3m_00bbbdb0 {
void may_throw();
struct Guard { ~Guard() { int z = 0; if (z) may_throw(); } };
struct Elem { int unk00, unk04, unk08, unk0c; };
inline void SwapField(int& x, int& y) { int t = x; x = y; y = t; }
Elem* __cdecl FUN_00bbbdb0(Elem* first, Elem* last, Elem* dest, Guard)
{
    int z = 0;
    if (z) may_throw();
    while (first != last) {
        --last;
        --dest;
        SwapField(dest->unk04, last->unk04);
        SwapField(dest->unk08, last->unk08);
        SwapField(dest->unk0c, last->unk0c);
    }
    return dest;
}
}
}   // namespace f3m_00bbbdb0

// @f3 0x00bb10a0 (community match, verified in this file)
namespace f3m_00bb10a0 {
namespace f3m_00bb10a0 {
struct Elem { int a; };
struct Alloc {};
struct NonscalarTag {};
struct RangeCheckedTag {};

Elem* __cdecl FUN_00bb0540(Elem* first, Elem* last, Elem* dest, Alloc& al, NonscalarTag, RangeCheckedTag);

inline NonscalarTag PtrCat(Elem*, Elem*) { NonscalarTag cat; return cat; }

inline Elem* UncheckedCopy(Elem* first, Elem* last, Elem* dest, Alloc& al)
{
    return FUN_00bb0540(first, last, dest, al, PtrCat(first, dest), RangeCheckedTag());
}

struct Vec : Alloc {
    Elem* FUN_00bb10a0(Elem* first, Elem* last, Elem* dest);
};

Elem* Vec::FUN_00bb10a0(Elem* first, Elem* last, Elem* dest)
{
    return UncheckedCopy(first, last, dest, *this);
}
}
}   // namespace f3m_00bb10a0

// @f3 0x00bac830 (community match, verified in this file)
#include <math.h>
namespace Task1906 {
extern const float DAT_00de7c24,DAT_00e00d60,DAT_00e05de4;
void FUN_00c01e8b();
template <class T> inline const T& max_value(const T& _Left, const T& _Right)
{
    return _Left < _Right ? _Right : _Left;
}
struct Vector3
{
    float x, y, z; enum Uninitialized { NoInit }; explicit Vector3(Uninitialized) {}
    Vector3()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    void SetDifference(const Vector3& a,const Vector3& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}
    Vector3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vector3 AddVector(const Vector3& other) const
    {
        return Vector3(other.x + x, other.y + y, other.z + z);
    }
    Vector3 ScaleSwizzled(float scale) const
    {
        return Vector3(scale * x, scale * y, scale * z);
    }
    Vector3 FUN_00b13040(const Vector3& other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    Vector3 FUN_00b12890(const struct FloatMatrix3&) const;
    void FUN_00b12790()
    {
        float lengthSquared = x * x + y * y + z * z;
        float inverseLength = 1.0f / (float)sqrt(lengthSquared);
        x *= inverseLength;
        y *= inverseLength;
        z *= inverseLength;
    }
};
struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vector3 TransformVector(const Vector3& v) const
    {
        return Vector3(v.z * m02 + (v.y * m01 + v.x * m00), v.z * m12 + (v.y * m11 + v.x * m10),
                       v.z * m22 + (v.y * m21 + v.x * m20));
    }
    void FUN_00ba9890(float, Vector3);
    FloatMatrix3() : m00(1), m01(0), m02(0), m10(0), m11(1), m12(0), m20(0), m21(0), m22(1)
    {}
    FloatMatrix3 Multiply(const FloatMatrix3&) const;
    void FUN_00ba9700(float angle);
};
inline Vector3 Vector3::FUN_00b12890(const FloatMatrix3& m) const
{
    return Vector3(m.m20 * z + (m.m10 * y + m.m00 * x), m.m21 * z + (m.m11 * y + m.m01 * x),
                   m.m22 * z + (m.m12 * y + m.m02 * x));
}
namespace TransformRecord {
struct TransformData
{
    Vector3 direction;
    Vector3 position;
    float scale;
    FloatMatrix3 rotation;
    float extent;
    float weight;
    TransformData()
    {}
};
}
struct Curve
{
    float FUN_00bc2170(float);
};
struct Config
{
    Curve* GetCurve()
    {
        return curve;
    }
    int unk00, count, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    Curve* curve;
};
template <class T> struct ConfigVector
{
    void* m_pContainerProxy;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    unsigned int size() const
    {
        return _Myfirst ? _Mylast - _Myfirst : 0;
    }
    T& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
        {
            FUN_00c01e8b();
        }
        return *(_Myfirst + _Pos);
    }
};
extern ConfigVector<Config*> DAT_011782d4;
struct RandomSource
{
    float FUN_00bc4b40(float, float);
};
extern RandomSource DAT_011782c1;
extern Vector3 DAT_01068b44;
struct ParentNode
{
    ParentNode* parent;
    int unk04, unk08, unk0c, unk10, unk14;
    TransformRecord::TransformData* transform;
    int enabled;
};
struct Settings
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    int parentDepth;
};
extern Settings* DAT_011782b0;
struct Effect
{
    void FUN_00bac830(ParentNode*, float, unsigned int, const Vector3&, float, const FloatMatrix3&, const Vector3&, int,
                      float, int);
    void FUN_00bac160(const Vector3&, float, Effect*, const Vector3&, const Vector3&, float, int, int);
};
// @fnv 0x00b13100
// pdb: CIdvBranch::ComputeBud | Branch.obj | fnv360_0822_retail, call_gap, low
// pdb params: pParent, fSize, nLevel, cBasePos, fPercentOfParent, cBaseTransform, cZAxis, vLeaves, fWindWeight, nWindGroup
void Effect::FUN_00bac830(ParentNode* node, float amount, unsigned int index, const Vector3& position, float time,
                          const FloatMatrix3& rotation, const Vector3& axis, int flags, float speed, int mode)
{
    Config* profile = DAT_011782d4[index];
    const int samplesCount = 2;
    TransformRecord::TransformData transforms[samplesCount];
    float distance = profile->GetCurve()->FUN_00bc2170(time) * amount;
    float step = max_value(distance / profile->count, 0.01f);
    float randomAngle = DAT_011782c1.FUN_00bc4b40(DAT_00e00d60, DAT_00de7c24);
    Vector3 rotated = rotation.TransformVector(axis);
    TransformRecord::TransformData* from = &transforms[0];
    from->position = position;
    from->rotation = rotation;
    from->rotation.FUN_00ba9890(randomAngle, rotated);
    from->rotation.FUN_00ba9700(DAT_00e05de4);
    Vector3 forward = DAT_01068b44.FUN_00b12890(from->rotation);
    from->direction = forward;
    TransformRecord::TransformData* pOther = &transforms[1];
    Vector3 towardParent = from->position.AddVector(from->direction.ScaleSwizzled(step));
    pOther->position = towardParent;
    // Fake match: named references steer the inlined operand liveness without changing the difference.
    const Vector3& first = transforms[0].position;
    const Vector3& second = transforms[1].position;
    forward.SetDifference(second, first);
    forward.FUN_00b12790();
    if (!node || !node->enabled)
    {
        towardParent = forward;
    }
    else
    {
        Vector3 origin = node->transform->position;
        if (DAT_011782b0->parentDepth != 0)
        {
            int level = 0;
            ParentNode* parent = node;
            while (parent && level < DAT_011782b0->parentDepth)
            {
                parent = parent->parent;
                level++;
            }
            if (parent)
                origin = parent->transform->position;
        }
        towardParent = transforms[1].position.FUN_00b13040(origin);
    }
    towardParent.FUN_00b12790();
    FUN_00bac160(transforms[1].position, time, this, forward, towardParent, speed, mode, flags);

}
}  // namespace Task1906

// @f3 0x00ba29a0 (community match, verified in this file)
#include <vector>
namespace f3m_00ba29a0 {
namespace f3m_00ba29a0 {
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    struct SubVec { int unk00; int* first; int* last; int* end; unsigned int size() const { return first == 0 ? 0 : (unsigned short)(last - first); } };
    std::vector<SubVec> lists;
    unsigned int FUN_00ba29a0(short index);
};
}
// pdb: CIndexedGeometry::GetStripLengthsPointer | SpeedTreeRT.obj | fnv360_0822_debug, call_gap_sim, low
// pdb params: sLodLevel
unsigned int f3m_00ba29a0::Owner::FUN_00ba29a0(short index) {
        if (index > -1) {
            return lists[index].size();
        }
        return 0;
    }
}   // namespace f3m_00ba29a0

// @f3 0x00bb0700 (community match, verified in this file)
namespace f3m_00bb0700 {
namespace f3m_00bb0700 {
struct Header {
    unsigned char kind; void* source; unsigned char unk08, unk09; unsigned int unk0c;
    unsigned short unk10; unsigned char unk12; unsigned int unk14, unk18, unk1c;
    unsigned short unk20, unk22, unk24, unk26;
    Header(void* s, unsigned char k) : kind(k), source(s), unk08(0), unk09(0), unk0c(0), unk10(0), unk12(1), unk14(2), unk20(0), unk22(0), unk24(0), unk26(0) {}
    
};
struct R { void* unk00; unsigned unk04, unk08, unk0c; R() : unk04(0),unk08(0),unk0c(0) {} ~R(); };
struct FUN_00bb0700 : Header {
R a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
FUN_00bb0700(void* s, unsigned char k);
};
FUN_00bb0700::FUN_00bb0700(void* s, unsigned char k) : Header(s,k) { try { } catch(...) { throw; } }
}
}   // namespace f3m_00bb0700

// @f3 0x00bbd770 (community match, verified in this file)
namespace f3m_00bbd770 {
extern char off_00ea7084;                 // value ORIG stores at +0x00

struct BBD {                              // +00 slot, +10 ptr/flag (union), +20 field, +24 capacity
    unsigned int slot0;                   // 0x00   same type as the fields below: no aliasing proof
    int pad0[3];                          // 0x04 - 0x0c
    union { void* allocPtr; unsigned char flag; };   // 0x10
    int pad1[3];                          // 0x14 - 0x1c
    unsigned int field20;                 // 0x20
    unsigned int capacity;                // 0x24

    void FUN_00bbd770();
    void FUN_00c01af5();                  // member: ecx = this (ORIG tail-jumps into it)
};

void FUN_00401010(void* p);               // cdecl free-style call (push / call / add esp, 4)

void BBD::FUN_00bbd770() {
    unsigned int* cap = &capacity;      // address escapes: defeats the optimizer's reordering
    slot0 = (unsigned int)&off_00ea7084;

    if (*cap >= 0x10u) {
        FUN_00401010(allocPtr);
    }

    capacity = 0xfu;
    field20 = 0;
    flag = 0;

    return FUN_00c01af5();
}


}   // namespace f3m_00bbd770

// @f3 0x00baffd0 (community match, verified in this file)
#include <vector>
namespace f3m_00baffd0 {
namespace w36 {
class PtrVec : public std::vector<unsigned int*> {
public:
    void FUN_00baf7f0(iterator _Where, size_type _Count, unsigned int* const& _Val);
    iterator FUN_00baffd0(iterator _Where, unsigned int* const& _Val);
};
// pdb: std::vector<int,std::allocator<int> >::push_back | Branch.obj | fnv360_0822_retail, call_gap_sim, low
// pdb params: _Val
PtrVec::iterator PtrVec::FUN_00baffd0(iterator _Where, unsigned int* const& _Val)
{
    size_type _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00baf7f0(_Where, (size_type)1, _Val);
    return (begin() + _Off);
}
}
}   // namespace f3m_00baffd0

// @f3 0x00bb9830 (community match, verified in this file)
// TARGET: 0x00bb9830
namespace f3m_00bba8a0 {
namespace SortBBA {

void __cdecl FUN_00bb6850(Element* first, Element* middle, Element* last, int value0, int value1);

inline void Rotate(Element* first, Element* mid, Element* last)
{
    if (first != mid && mid != last)
        FUN_00bb6850(first, mid, last, 0, 0);
}

inline bool Pred(const Element& a, const Element& b)
{
    return *reinterpret_cast<const float*>(&a.unk24) > *reinterpret_cast<const float*>(&b.unk24);
}

void __cdecl FUN_00bb9830(Element* first, Element* last, Compare compare)
{
    if (first != last)
        for (Element* next = first; ++next != last; )
            if (Pred(*next, *first))
            {
                Element* next1 = next;
                Rotate(first, next, ++next1);
            }
            else
            {
                Element* dest = next;
                for (Element* dest0 = dest; Pred(*next, *--dest0); )
                    dest = dest0;
                if (dest != next)
                {
                    Element* next1 = next;
                    Rotate(dest, next, ++next1);
                }
            }
}

}
}

// @f3 0x00bb9ba0 (community match, verified in this file)
namespace f3m_00bb9ba0 {
namespace work_bb9ba0 {

struct FUN_00bb5880 {
    unsigned int allocator;
    void* first;
    void* last;
    void* end;
    FUN_00bb5880(const FUN_00bb5880&);
    ~FUN_00bb5880();
};

struct Element {
    FUN_00bb5880 list;
    float x, y;
    bool flag;
    float z, w, v;
    int first, last;
};

void __cdecl FUN_00bb70c0(Element* first, Element* last, Element* dest, Element val, unsigned compare, int* dist);

__forceinline void PopHeap0(Element* first, Element* last, unsigned compare, Element*)
{
    FUN_00bb70c0(first, last - 1, last - 1, Element(*(last - 1)), compare, 0);
}

__forceinline void PopHeap(Element* first, Element* last, unsigned compare)
{
    if (1 < last - first)
        PopHeap0(first, last, compare, 0);
}

void __cdecl FUN_00bb9ba0(Element* first, Element* last, unsigned compare)
{
    for (; 1 < last - first; --last)
        PopHeap(first, last, compare);
}

}
}   // namespace f3m_00bb9ba0

// @f3 0x00ba9ed0 (community match, verified in this file)
namespace f3m_00ba9ed0 {
namespace work_ba9ed0 {

struct Vec00ba9ed0 {
    float x, y, z;

    float FastSqrt00ba9ed0(const Vec00ba9ed0& other) const {
        double y1 = other.y - y;
        double x1 = other.x - x;
        double z1 = other.z - z;
        double sum = y1 * y1;
        sum += x1 * x1;
        float f = sum + z1 * z1;
        int i = (*(int*)&f >> 1) + 0x1fc00000;
        return *(float*)&i;
    }
};

struct Elem00ba9ed0 {
    int unk00, unk04, unk08;
    Vec00ba9ed0 vec;
    float weight;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
};

struct Ctx00ba9ed0 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Elem00ba9ed0* elems;
    int count;
    int unk20, unk24;
    float sum;

    void FUN_00ba9ed0();
};

// pdb: CIdvBranch::ComputeVolume | Branch.obj | fnv360_0822_retail, call_gap, low
void Ctx00ba9ed0::FUN_00ba9ed0()
{
    if (this->elems != 0) {
        if (this->count > 1) {
            this->sum = 0.0f;
            for (int i = 0; i < this->count - 1; i++) {
                Elem00ba9ed0* pCurrent = &this->elems[i];
                float len;
                Elem00ba9ed0* pSuccessor = &this->elems[i] + 1;
                {
                    len = pCurrent->vec.FastSqrt00ba9ed0(pSuccessor->vec);
                    this->sum = (pCurrent->weight + pSuccessor->weight) * len + this->sum;
                }
            }
        }
    }
}

}
}   // namespace f3m_00ba9ed0

// @f3 0x00bae210 (community match, verified in this file)
#include <math.h>
extern double FUN_00e31f80;
namespace f3m_00bae210 {
namespace work_bae210 {
struct Mat33z {
    float unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    Mat33z FUN_00ba9610(const Mat33z& o) const;
    void FUN_00bae210(float angle);
};
void Mat33z::FUN_00bae210(float angle)
{
    float r = (float)(angle / FUN_00e31f80);
    float c = cosf(r);
    float s = sinf(r);
    Mat33z m;
    m.unk00 = c; m.unk04 = s; m.unk08 = 0.0f;
    m.unk0C = -s; m.unk10 = c; m.unk14 = 0.0f;
    m.unk18 = 0.0f; m.unk1C = 0.0f; m.unk20 = 1.0f;
    *this = m.FUN_00ba9610(*this);
}
}
}   // namespace f3m_00bae210

// @f3 0x00bbd400 (community match, verified in this file)
namespace f3m_00bbd400 {
struct VectorData {
    float data[5];
    int count;
    VectorData* init(int n) {
        float z = 0.0f;
        data[4] = z;
        data[3] = z;
        data[2] = z;
        data[1] = z;
        data[0] = z;
        if (n > 5)
            n = 5;
        count = n;
        return this;
    }
    VectorData(int n) {
        init(n);
    }
    VectorData FUN_00bbd400(const VectorData& rhs) const;
};

VectorData VectorData::FUN_00bbd400(const VectorData& rhs) const
{
    VectorData result(count < rhs.count ? count : rhs.count);
    for (int i = 0; i < count; ++i)
        result.data[i] = rhs.data[i] + data[i];
    return result;
}
}   // namespace f3m_00bbd400

// @f3 0x00bb0d80 (community match, verified in this file)
#include <vector>
namespace f3m_00bb0d80 {

inline float Lerp(float a, float b, float t) {
    return (b - a) * t + a;
}

struct Object00bb0d80 {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short unk20;
    unsigned short unk22;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    unsigned int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    unsigned int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    unsigned int unkC4;
    std::vector<float> vecFloat;
    std::vector<char> vecChar;

    void FUN_00bb0a70(float* point, int index);
    void FUN_00bb0d80(char key, float* values);
};

bool __cdecl FUN_00ba1920();

void Object00bb0d80::FUN_00bb0d80(char key, float* values) {
    if (key == vecChar[unk22]) {
        float point[2];
        point[0] = Lerp(values[2], values[0], vecFloat[unk22 * 2]);
        point[1] = Lerp(values[5], values[1], vecFloat[unk22 * 2 + 1]);
        if (FUN_00ba1920())
            point[1] = -point[1];
        FUN_00bb0a70(point, -1);
    }
}
}   // namespace f3m_00bb0d80

// @f3 0x00bbd5c0 (community match, verified in this file)
namespace f3m_00bbd5c0 {
struct Vec5 {
    float v[5];
    int count;

    Vec5(int n) {
        v[4] = 0.0f;
        v[3] = 0.0f;
        v[2] = 0.0f;
        v[1] = 0.0f;
        v[0] = 0.0f;
        if (n > 5)
            n = 5;
        count = n;
    }

    Vec5 FUN_00bbd5c0(float scale);
};

Vec5 Vec5::FUN_00bbd5c0(float scale)
{
    Vec5 result(count);
    for (int i = 0; i < count; ++i) {
        result.v[i] = v[i] * scale;
    }
    return result;
}
}   // namespace f3m_00bbd5c0

// @f3 0x00ba53b0 (community match, verified in this file)
namespace f3m_00ba53b0 {
namespace S00ba53b0_ns {
struct S00ba53b0_Leaf {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    TreeString1541 name18;
    float values34[8];
};
struct S00ba53b0_Owner {
    unsigned int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24;
    unsigned int unk28,unk2C,unk30,unk34,unk38,unk3C,unk40,unk44,unk48;
    S00ba53b0_Leaf* mesh4C;
    unsigned int unk50,unk54,unk58,unk5C,unk60,unk64,unk68;
    bool flag6C,flag6D;
    void FUN_00ba53b0(TreeReader1541*);
};
}
// pdb: CSpeedTreeRT::ParseSupplementalTexCoordInfo | SpeedTreeRT.obj | fnv360_0822_retail, ustr_rel, medium
// pdb params: pFile
void S00ba53b0_ns::S00ba53b0_Owner::FUN_00ba53b0(TreeReader1541* reader)
{
    if(mesh4C) {
        int tag=reader->FUN_00ba92d0();
        do {
            switch(tag) {
            case 0x4e22: {
                TreePath1541 path(reader->FUN_00ba9460());
                mesh4C->name18=path.FUN_00ba3c00();
                break;
            }
            case 0x4e23:
                flag6D=reader->ReadBool();
                break;
            case 0x4e24:
                flag6C=reader->ReadBool();
                break;
            case 0x4e25:
                for(int i=0;i<8;++i) mesh4C->values34[i]=reader->FUN_00ba92a0();
                break;
            default:
                throw IdvFileError("malformed texture coord info",0);
            }
            if(reader->FUN_00ba1ab0()) throw IdvFileError("premature end of file reached parsing texture coordinate info",0);
            tag=reader->FUN_00ba92d0();
        } while(tag!=0x4e21);
    }
}
}   // namespace f3m_00ba53b0

// @f3 0x00baf220 (community match, verified in this file)
#include <vector>

void* __cdecl FUN_00401000(unsigned int size);

namespace f3m_00baf220 {

struct S00baf220_Matrix
{
    float m[4][4];
};

extern S00baf220_Matrix* DAT_0117830c;

struct S00baf220_Vec
{
    float v[3];
    S00baf220_Vec(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
        v[2] = z;
        v[1] = y;
        v[0] = x;
    }
    S00baf220_Vec Apply(const S00baf220_Matrix& M) const
    {
        S00baf220_Vec r;
        r.v[0] = (v[0] * M.m[0][0] + v[1] * M.m[1][0]) + v[2] * M.m[2][0] + M.m[3][0];
        r.v[1] = (v[0] * M.m[0][1] + v[1] * M.m[1][1]) + v[2] * M.m[2][1] + M.m[3][1];
        r.v[2] = (v[0] * M.m[0][2] + v[1] * M.m[1][2]) + v[2] * M.m[2][2] + M.m[3][2];
        return r;
    }
};

inline float S00baf220_Interpolate(float s, float e, float t)
{
    return s + (e - s) * t;
}

struct S00baf220_Point
{
    float x, y, z;
};

struct S00baf220_Leaves
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char* flags;
    unsigned short unk10;
    bool computed;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    std::vector<std::vector<unsigned short> > counts;
    std::vector<std::vector<unsigned short*> > lists;
    int unk58, unk5c, unk60, unk64;
    std::vector<float> positions;
    std::vector<float> rest;
    int unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    int unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4;
    std::vector<float> weights;
    std::vector<unsigned char> windIndices;

    unsigned short GroupSize(short group)
    {
        if (group > -1)
            return (unsigned short)lists[group].size();
        return 0;
    }
    bool FUN_00baf220(short group);
};

// pdb: CIndexedGeometry::ComputeWindEffect | IndexedGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: nLodLevel
bool S00baf220_Leaves::FUN_00baf220(short group)
{
    bool ok = false;
    if (!computed)
    {
        unsigned short count = (unsigned short)(positions.size() / 3);
        if (!flags)
            flags = (unsigned char*)FUN_00401000(count);
        for (int k = 0; k < count; ++k)
            flags[k] = 0;

        S00baf220_Vec result;
        for (int i = 0; i < GroupSize(group); ++i)
        {
            for (int j = 0; j < counts[(unsigned short)group][i]; ++j)
            {
                unsigned short idx = lists[(unsigned short)group][i][j];
                if (!flags[idx])
                {
                    float weight = weights[idx];
                    float* src = &rest[0] + idx * 3;
                    S00baf220_Vec in;
                    in.v[0] = src[0];
                    in.v[1] = src[1];
                    in.v[2] = src[2];
                    S00baf220_Vec xf = in.Apply(DAT_0117830c[windIndices[idx]]);
                    float pz = src[2];
                    float py = src[1];
                    float px = src[0];
                    result.v[0] = S00baf220_Interpolate(px, xf.v[0], weight);
                    result.v[1] = S00baf220_Interpolate(py, xf.v[1], weight);
                    result.v[2] = S00baf220_Interpolate(pz, xf.v[2], weight);
                    *(S00baf220_Point*)(&positions[0] + idx * 3) = *(S00baf220_Point*)&result;
                    flags[idx] = 1;
                }
            }
        }
        computed = true;
        ok = true;
    }
    return ok;
}

}

// @f3 0x00baf5b0 (community match, verified in this file)
namespace f3m_00baf5b0 {
// Fills a range with one 16-bit value read once per element.

void __cdecl FUN_00baf5b0(unsigned short* pDest, unsigned short* pEnd, unsigned short* pSrc)
{
    while (pDest != pEnd)
    {
        *pDest = *pSrc;
        pDest++;
    }
}
}   // namespace f3m_00baf5b0

// @f3 0x00bb45d0 (community match, verified in this file)
namespace f3m_00bb45d0 {
namespace f3m_00bb45d0 {
void __cdecl FUN_00401010(void* p);

struct FUN_00bc2e20 {
    ~FUN_00bc2e20();
    static void operator delete(void* p) { FUN_00401010(p); }
};

struct Target {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    FUN_00bc2e20* m_30;

    void FUN_00bb45d0(FUN_00bc2e20* p);
};

// pdb: CIdvBezierSpline::~CIdvBezierSpline | IdvSpline.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void Target::FUN_00bb45d0(FUN_00bc2e20* p)
{
    if (m_30 != p) {
        delete m_30;
        m_30 = p;
    }
}
}
}   // namespace f3m_00bb45d0

// @f3 0x00bab2b0 (community match, verified in this file)
namespace f3m_00bab2b0 {
namespace f3m_00bab2b0 {
void __cdecl FUN_00baabd0(SortedEntry_aab70** first, int hole, int bottom, SortedEntry_aab70* value, PriorityGreater_aab70 pred);

// pdb: std::_Sort_heap<CIdvBranch * *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Last, _Pred
void __cdecl FUN_00bab2b0(SortedEntry_aab70** first, SortedEntry_aab70** last, PriorityGreater_aab70 pred) {
    for (; 1 < last - first; --last) {
        if (1 < last - first) {
            SortedEntry_aab70* val = *(last - 1);
            *(last - 1) = *first;
            FUN_00baabd0(first, 0, (last - 1) - first, val, pred);
        }
    }
}
}
}   // namespace f3m_00bab2b0

// @f3 0x00bb5180 (community match, verified in this file)
namespace f3m_00bb5180 {
namespace Copybb5180 {
struct Record {int unk00;
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
};
Record* FUN_00bb5180(Record* first,Record* last,Record* output){Record* result=output+(last-first);for(Record* current=first;current!=last;++current){*reinterpret_cast<Record*>(reinterpret_cast<char*>(output)+(reinterpret_cast<char*>(current)-reinterpret_cast<char*>(first)))=*current;}return result;}
}


}   // namespace f3m_00bb5180

// @f3 0x00bb6e10 (community match, verified in this file)
namespace f3m_00bb6e10 {
namespace Sortbb6e10 {
struct Record {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;float priority;};
void FUN_00bb6600(Record*,Record*);
// pdb: std::_Move_backward<SFrondGuide *,SFrondGuide *> | FrondEngine.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: _First, _Last, _Dest, __formal
void FUN_00bb6e10(Record* first,Record* middle,Record* last){if(middle->priority>first->priority)FUN_00bb6600(middle,first);if(last->priority>middle->priority)FUN_00bb6600(last,middle);if(middle->priority>first->priority)FUN_00bb6600(middle,first);}
}

}   // namespace f3m_00bb6e10

// @f3 0x00bb5520 (community match, verified in this file)
namespace f3m_00bb5520 {
namespace Erase207 {
struct Entry {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
void FUN_00c24b70();};
struct Iterator {void* owner;Entry* position;};
void FUN_00c01e8b();Entry* FUN_00bb5220(Entry*,Entry*,Entry*);
struct Object {int unk00,unk04;Entry* end;Iterator* FUN_00bb5520(Iterator*,void*,Entry*,void*,Entry*);};
// pdb: std::vector<CVec,std::allocator<CVec> >::resize | IdvSpline.obj | fnv360_0822_retail, call_gap_sim, low, conflict (bridge: std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,CIdvBezierSpline *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,CIdvBezierSpline *> >,0> >::clear)
// pdb params: _Newsize
Iterator* Object::FUN_00bb5520(Iterator* output,void* firstOwner,Entry* first,void* lastOwner,Entry* last){if(!firstOwner||firstOwner!=lastOwner)FUN_00c01e8b();if(first!=last){Entry* newEnd=FUN_00bb5220(last,end,first);Entry* oldEnd=end;for(Entry* current=newEnd;current!=oldEnd;++current)current->FUN_00c24b70();end=newEnd;}output->owner=firstOwner;output->position=first;return output;}
}
}   // namespace f3m_00bb5520

// @f3 0x00babf70 (community match, verified in this file)
#include <vector>
namespace f3m_00babf70 {
namespace Walkbabf70 {
struct Object;struct Child {int a,b;Object* child;};struct Context {void FUN_00babf00(Object**);};
struct Object {int unk00,unk04;std::vector<Child> children;void FUN_00babf70(Context*);};
void Object::FUN_00babf70(Context* context){Object* self=this;context->FUN_00babf00(&self);for(unsigned i=0;i<children.size();++i)children[i].child->FUN_00babf70(context);}
}
}   // namespace f3m_00babf70

// @f3 0x00bab100 (community match, verified in this file)
#include <algorithm>
namespace f3m_00bab100 {
namespace Sort304 {
struct Entry {int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28;float priority;};struct Pred {bool operator()(Entry* a,Entry* b)const{return a->priority>b->priority;}};
// pdb: std::_Make_heap<CIdvBranch * *,int,CIdvBranch *,CBranchVolumeSorter> | Branch.obj | fnv360_0822_retail, objrun_sim, low
// pdb params: _First, _Last, _Pred, __formal, __formal
void FUN_00bab100(Entry** first,Entry** last){Pred pred;if(first!=last)for(Entry** next=first;++next!=last;){if(pred(*next,*first)){Entry** next1=next;std::rotate(first,next,++next1);}else{Entry** dest=next;for(Entry** dest0=dest;pred(*next,*--dest0);dest=dest0){}Entry** next1=next;std::rotate(dest,next,++next1);}}}
}
}   // namespace f3m_00bab100

// @f3 0x00ba8260 (community match, verified in this file)
#include <vector>
namespace f3m_00ba8260 {
namespace Buffer306 {
struct FUN_00ba8260 {int position;std::vector<char> data;FUN_00ba8260(const char*,int);};
// pdb: CTreeFileAccess::CTreeFileAccess | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
// pdb params: pMemory, nNumBytes
FUN_00ba8260::FUN_00ba8260(const char* source,int length):position(0){data.resize(length,0);for(int i=0;i<length;++i)data[i]=source[i];}
}
}   // namespace f3m_00ba8260

// @f3 0x00bbec80 (community match, verified in this file)
namespace f3m_00bbec80 {
struct FUN_00ba9550 {
    int unk00, unk04, unk08, unk0C;
    ~FUN_00ba9550();
};

struct FUN_00c24b70 {
    unsigned char flag;
    ~FUN_00c24b70();
};

struct Vec_bbec80 {
    int alloc;
    void* first;
    void* last;
    void* end;
    ~Vec_bbec80() {
        if (first)
            ::operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }
};

struct FUN_00bc0ee0 {
    int unk00;
    ~FUN_00bc0ee0();
};

struct FUN_00bbec80 : FUN_00ba9550 {
    int unk10, unk14, unk18, unk1C;
    FUN_00c24b70 control20;
    std::string name24;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    Vec_bbec80 vec60;
    int unk70;
    Vec_bbec80 vec74;
    FUN_00bc0ee0 config84;

    ~FUN_00bbec80();
};

// pdb: CTreeEngine::~CTreeEngine | TreeEngine.obj | fnv360_0822_retail, call_seq, medium
FUN_00bbec80::~FUN_00bbec80()
{
}
}   // namespace f3m_00bbec80

// @f3 0x00ba07d0 (community match, verified in this file)
namespace f3m_00ba07d0 {
using namespace f3m_00ba0ec0;
// pdb: bi_windup | trees.obj | fnv360_0822_retail, call_dedup, low, conflict (skyrim: copy_block)
static __declspec(noinline) void FUN_00ba07d0(deflate_state *s, charf *buf, unsigned len, int header)
{
    FUN_00ba0750(s);
    s->last_eob_len = 8;

    if (header) {
        s->pending_buf[s->pending++] = (uch)((ush)len & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(ush)len >> 8);
        s->pending_buf[s->pending++] = (uch)((ush)~len & 0xff);
        s->pending_buf[s->pending++] = (uch)((ush)(ush)~len >> 8);
    }
    while (len--) {
        s->pending_buf[s->pending++] = *buf++;
    }
}
volatile int g_in_ba07d0;
void caller_of_FUN_00ba07d0()
{
    FUN_00ba07d0((deflate_state*)g_in_ba07d0, (charf*)g_in_ba07d0, (unsigned)g_in_ba07d0, g_in_ba07d0);
}
}   // namespace f3m_00ba07d0

// @f3 0x00baa3e0 (community match, verified in this file)
namespace f3m_00baa3e0 {
namespace ns_baa3e0 {
struct Node {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28;
    float key;
};
void __cdecl FUN_00baa3e0(Node** heap, int i, int lo, Node* item)
{
    int parent = (i - 1) / 2;
    while (lo < i && heap[parent]->key > item->key)
    {
        heap[i] = heap[parent];
        i = parent;
        parent = (parent - 1) / 2;
    }
    heap[i] = item;
}
}
}   // namespace f3m_00baa3e0

// @f3 0x00bbdc40 (community match, verified in this file)
namespace f3m_00bbdc40 {
namespace ns_bbdc40 {
int __cdecl FUN_004b20a0(const char* first1, const char* first2, unsigned int count);
void __cdecl FUN_00bff0b2();
struct String
{
    void* unk00;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int size;
    unsigned int res;
    const char* Myptr() const
    {
        return 16 <= res ? bx.ptr : bx.buf;
    }
    int FUN_00bbdc40(unsigned int off, unsigned int n0, const char* ptr, unsigned int count) const;
};
// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::compare | binaryFile.obj | fnv360_0822_retail, call_gap, low, conflict (bridge: CTreeFileAccess::ParseString)
// pdb params: _Off, _N0, _Ptr, _Count
int String::FUN_00bbdc40(unsigned int off, unsigned int n0, const char* ptr, unsigned int count) const
{
    if (size < off)
        FUN_00bff0b2();
    if (size - off < n0)
        n0 = size - off;
    unsigned int ans = FUN_004b20a0(Myptr() + off, ptr, n0 < count ? n0 : count);
    return ans != 0 ? (int)ans : n0 < count ? -1 : n0 == count ? 0 : +1;
}
}
}   // namespace f3m_00bbdc40

// @f3 0x00bb9d60 (community match, verified in this file)
namespace f3m_00bb9d60 {
namespace ns_bb9d60 {
struct Elem;
struct RandomTag {};
struct NonscalarTag {};
struct RangeCheckedTag {};
struct Alloc {};
void __cdecl FUN_00c01e8b();
Elem* __cdecl FUN_00bb6c10(Elem* first, Elem* last, Elem* dest, RandomTag, NonscalarTag, RangeCheckedTag);
void __cdecl FUN_00bb8e80(Elem* first, Elem* last, Alloc& al, NonscalarTag);
inline RandomTag IterRandom(Elem* const&, Elem* const&)
{
    RandomTag cat;
    return cat;
}
inline NonscalarTag PtrCat(Elem* const&, Elem* const&)
{
    NonscalarTag cat;
    return cat;
}
inline Elem* UncheckedCopy(Elem* first, Elem* last, Elem* dest)
{
    return FUN_00bb6c10(first, last, dest, IterRandom(first, dest), PtrCat(first, dest), RangeCheckedTag());
}
inline void DestroyRange(Elem* first, Elem* last, Alloc& al)
{
    FUN_00bb8e80(first, last, al, PtrCat(first, last));
}
struct Vector;
struct Iterator
{
    Vector* cont;
    Elem* ptr;
    bool operator==(const Iterator& right) const
    {
        if (cont == 0 || cont != right.cont)
            FUN_00c01e8b();
        return ptr == right.ptr;
    }
    Elem* Base() const
    {
        return ptr;
    }
    bool operator!=(const Iterator& right) const
    {
        return !(*this == right);
    }
};
struct Vector
{
    Alloc al;
    Elem* myfirst;
    Elem* mylast;
    Elem* myend;
    void Destroy(Elem* first, Elem* last)
    {
        DestroyRange(first, last, al);
    }
    Iterator FUN_00bb9d60(Iterator first, Iterator last);
};
// pdb: std::vector<std::vector<float,std::allocator<float> >,std::allocator<std::vector<float,std::allocator<float> > > >::_Reserve | FrondEngine.obj | fnv360_0721_beta, objrun, medium
// pdb params: _Count
Iterator Vector::FUN_00bb9d60(Iterator first, Iterator last)
{
    if (first != last)
    {
        Elem* ptr = UncheckedCopy(last.Base(), mylast, first.Base());
        Destroy(ptr, mylast);
        mylast = ptr;
    }
    return first;
}
}
}   // namespace f3m_00bb9d60

// @f3 0x00bb4bf0 (community match, verified in this file)
namespace f3m_00bb4bf0 {
namespace f3m_00bb4bf0 {
struct Guide {unsigned FUN_00bb4600();};
struct Geometry {
 unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 unsigned short unk24,count;
 void FUN_00bb0850(unsigned,unsigned short*,unsigned short);
};
struct Engine {
 Geometry* geometry;unsigned unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,blades;
 void FUN_00bb4bf0(unsigned,int,Guide&);
};
// pdb: CFrondEngine::ComputeBlade | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: nLod, nStart, sGuide
void Engine::FUN_00bb4bf0(unsigned level,int start,Guide& guide){
 if(geometry){
  for(unsigned blade=0;blade<blades;++blade){
   unsigned short count=(unsigned short)(guide.FUN_00bb4600()*2);
   unsigned short* indices=new unsigned short[count];
   for(unsigned i=0;i<guide.FUN_00bb4600()*2;++i)
    indices[i]=(unsigned short)(start+guide.FUN_00bb4600()*blade*2+i);
   geometry->FUN_00bb0850(level,indices,count);
   ++geometry->count;
  }
 }
}
}
}   // namespace f3m_00bb4bf0

// @f3 0x00bafbd0 (community match, verified in this file)
#include <vector>
namespace f3m_00bafbd0 {
namespace match637 {
struct Vector : std::vector<unsigned short> {
 Vector* FUN_00bafbd0(const Vector& other);
};
Vector* Vector::FUN_00bafbd0(const Vector& other){
 if(_Buy(other.size()))_Mylast=_Ucopy(other.begin(),other.end(),_Myfirst);
 return this;
}
}
}   // namespace f3m_00bafbd0

// @f3 0x00bbd4e0 (community match, verified in this file)
namespace f3m_00bbd4e0 {
namespace match638b {
struct VectorData {
    float data[5];
    int count;
    VectorData* init(int n) {
        float z = 0.0f;
        data[4] = z;
        data[3] = z;
        data[2] = z;
        data[1] = z;
        data[0] = z;
        if (n > 5)
            n = 5;
        count = n;
        return this;
    }
    VectorData(int n) {
        init(n);
    }
    VectorData FUN_00bbd4e0(const VectorData& rhs) const;
};

VectorData VectorData::FUN_00bbd4e0(const VectorData& rhs) const
{
    VectorData result(count < rhs.count ? count : rhs.count);
    for (int i = 0; i < count; ++i)
        result.data[i] = data[i] - rhs.data[i];
    return result;
}
}



}   // namespace f3m_00bbd4e0

// @f3 0x00bb3390 (community match, verified in this file)
namespace f3m_00bb3390 {
namespace f3m_00bb3390 {
struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
};
struct Row4 { Vec3 v; float w; };
struct Block { Row4 rows[4]; };
struct TreeGeometry
{
    bool active;
    float alpha;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};
struct LeafEntry { TreeGeometry geometry; bool computed; int unk40; };
struct Runtime { int unk00, unk04, unk08, unk0c; int mode; };
struct S00bb3390_Wind
{
    int unk00;
    Runtime* runtime;
    unsigned short rows;
    unsigned short unk0a;
    void* p0c;
    Block** blocks;
    int unk14, unk18;
    unsigned short corners;
    unsigned short unk1e;
    Vec3* sizes;
    Vec3* centers;
    unsigned short count;
    unsigned short unk2a;
    LeafEntry* entries;
    void FUN_00bb31b0(unsigned short usLod);
    void FUN_00bb3390(TreeGeometry* out, unsigned short index, float a, float b, float t);
};
// pdb: CLeafGeometry::Update | LeafGeometry.obj | fnv360_0822_retail, call_seq, medium
// pdb params: sGeometry, usLodLevel, fAzimuth, fPitch, fSizeIncreaseFactor
void S00bb3390_Wind::FUN_00bb3390(TreeGeometry* out, unsigned short index, float, float, float t)
{
    if (entries && index < count && blocks && centers && sizes && runtime && p0c) {
        LeafEntry* entry = &entries[index];
        if (!entry->computed) {
            if (runtime->mode == 1)
                FUN_00bb31b0(index);
            float scale = 1.0f;
            if (index > 0)
                scale = index * t + 1.0;
            Vec3 a[4];
            Vec3 b[4];
            for (int i = 0; i < corners * 2; i++) {
                Vec3 p = centers[i / 2];
                if (i % 2 == 0)
                    p.x = 1.0f - p.x;
                const Vec3& q = sizes[i / 2];
                Vec3 c0(0.0f, (1.0f - p.x) * scale * q.x, (1.0f - p.y) * scale * q.y);
                Vec3 c1(0.0f, -(p.x * q.x * scale), c0.z);
                Vec3 c2(0.0f, c1.y, -(p.y * q.y * scale));
                a[0].x = c0.x; a[0].y = c0.y; a[0].z = c0.z;
                a[1].x = c1.x; a[1].y = c1.y; a[1].z = c1.z;
                a[2].x = c2.x; a[2].y = c2.y; a[2].z = c2.z;
                a[3].x = 0.0f; a[3].y = c0.y; a[3].z = c2.z;
                for (int j = 0; j < rows; j++) {
                    for (int k = 0; k < 4; k++)
                        b[k] = a[k];
                    Block& dst = blocks[index][rows * i + j];
                    Row4* rp = dst.rows;
                    rp->v = b[0]; ++rp;
                    rp->v = b[1]; ++rp;
                    rp->v = b[2]; ++rp;
                    rp->v = b[3];
                }
            }
            entry->computed = true;
        }
        *out = entry->geometry;
        out->active = true;
        out->unk08 = index;
    }
}
}
}   // namespace f3m_00bb3390

// @f3 0x00bbc430 (community match, verified in this file)
namespace f3m_00bbc430 {
namespace f3m_00bbc430 {
struct Alloc {};
struct Tag {};
struct ElemA;
struct ElemB;
struct ElemC;
void __cdecl FUN_00bb8e80(ElemA* first, ElemA* last, Alloc& al, Tag tag) throw();
void __cdecl FUN_00bbbc20(ElemB* first, ElemB* last, Alloc& al, Tag tag) throw();
void __cdecl FUN_00bb5cd0(ElemC* first, ElemC* last, Alloc& al, Tag tag) throw();
void __cdecl FUN_00401010(void* p) throw();

template <class E, void (__cdecl* Destroy)(E*, E*, Alloc&, Tag) throw()>
struct Vec {
    Alloc al;
    E* first;
    E* last;
    E* end;
    ~Vec()
    {
        if (first) {
            Tag tag;
            Destroy(first, last, al, tag);
            FUN_00401010(first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
};

struct Child {
    void FUN_00bc2e20();
};

struct TreeData {
    int unk00;
    int unk04;
    Vec<ElemA, FUN_00bb8e80> vec08;
    Vec<ElemB, FUN_00bbbc20> vec18;
    int unk28;
    int unk2C;
    Child* child;
    int unk34;
    int unk38;
    int unk3C;
    Vec<ElemC, FUN_00bb5cd0> vec40;
    ~TreeData();
};

// pdb: CFrondEngine::~CFrondEngine | FrondEngine.obj | fnv360_0822_retail, call_gap, low
TreeData::~TreeData()
{
    Child* c = child;
    if (c) {
        c->FUN_00bc2e20();
        FUN_00401010(c);
    }
    child = 0;
}
}
}   // namespace f3m_00bbc430

// @f3 0x00bab300 (community match, verified in this file)
#include <vector>
extern std::vector<void*> DAT_011782d4;
namespace f3m_00bab300 {
// pdb: CIdvBranch::BuildBranchVector | Branch.obj | fnv360_0721_retail, objrun, medium
// pdb params: vAllBranches
void __cdecl FUN_00bab300()
{
    DAT_011782d4.clear();
}
}   // namespace f3m_00bab300

// @f3 0x00bbfd70 (community match, verified in this file)
#include <vector>
#include <string>
#include <stdexcept>
namespace f3m_00bbfd70 {

template<class T>
struct TreeAlloc70 : std::allocator<T> {
    template<class U> struct rebind { typedef TreeAlloc70<U> other; };
    TreeAlloc70() throw() {}
    template<class U> TreeAlloc70(const TreeAlloc70<U>&) throw() {}
    T* allocate(size_t n, const void* = 0) { return (T*)DAT_01090a78.FUN_0086b930(n * sizeof(T)); }
    void deallocate(T* p, size_t) { DAT_01090a78.FUN_0086ba60(p); }
};
template<class T, class U> inline bool operator==(const TreeAlloc70<T>&, const TreeAlloc70<U>&) { return true; }
template<class T, class U> inline bool operator!=(const TreeAlloc70<T>&, const TreeAlloc70<U>&) { return false; }

typedef std::basic_string<char, std::char_traits<char>, TreeAlloc70<char> > ReaderString70;

struct FUN_00ba37a0 : std::string {
    FUN_00ba37a0() {}
    FUN_00ba37a0(ReaderString70 s);
    FUN_00ba37a0 FUN_00ba3c00() const;
};

struct BinaryReader70 {
    unsigned int offset;
    std::vector<char> data;
    int FUN_00ba92d0();
    float FUN_00ba92a0();
    ReaderString70 FUN_00ba9460();
    bool ParseBool() { return data[offset++] != 0; }
};

struct GeneralTreeLoader70 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FUN_00ba37a0 textureName;
    float f40;
    float f44;
    int unk48;
    float f4c;
    float f50;

    void CTreeEngine_ParseBranchInfo(BinaryReader70*);
    void FUN_00bbdb10(int);
    void FUN_00bbfd70(BinaryReader70* reader);
};

// pdb: CTreeEngine::ParseTreeInfo | TreeEngine.obj | fnv360_0822_retail, ustr, medium
// pdb params: cFile
void GeneralTreeLoader70::FUN_00bbfd70(BinaryReader70* reader)
{
    int token = reader->FUN_00ba92d0();
    do {
        switch (token) {
        case 1014:
            CTreeEngine_ParseBranchInfo(reader);
            break;
        case 2000:
            textureName = reader->FUN_00ba9460();
            textureName = textureName.FUN_00ba3c00();
            break;
        case 2005:
            FUN_00bbdb10(reader->FUN_00ba92d0());
            break;
        case 2003:
            f44 = reader->FUN_00ba92a0();
            break;
        case 2001:
            f40 = reader->FUN_00ba92a0();
            break;
        case 2004:
            reader->FUN_00ba92d0();
            break;
        case 2002:
            reader->ParseBool();
            break;
        case 2006:
            f4c = reader->FUN_00ba92a0();
            break;
        case 2007:
            f50 = reader->FUN_00ba92a0();
            break;
        default:
            throw IdvFileError("malformed general tree information", false);
        }
        token = reader->FUN_00ba92d0();
    } while (token != 1003);
}
}   // namespace f3m_00bbfd70

// @f3 0x00ba9fe0 (community match, verified in this file)
#include <math.h>
namespace f3m_00ba9fe0 {

struct Vec3_ba9fe0
{
    float x, y, z;
    Vec3_ba9fe0() {}
    Vec3_ba9fe0(float a, float b, float c) : x(a), y(b), z(c) {}
    void Normalize()
    {
        float sum = x * x + y * y + z * z;
        float inv = 1.0f / sqrtf(sum);
        x *= inv;
        y *= inv;
        z *= inv;
    }
    Vec3_ba9fe0 Cross(const Vec3_ba9fe0& p) const
    {
        return Vec3_ba9fe0(y * p.z - p.y * z, z * p.x - p.z * x, x * p.y - p.x * y);
    }
};

struct Mesh_ba9fe0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    float unk1c;
    unsigned short unk20;
    unsigned short vertices;

    float* FUN_00baee70(int index);
    void FUN_00bb0a40(const Vec3_ba9fe0& v);
    void Advance() { ++vertices; }
};

struct Branch_ba9fe0
{
    void* parent;
    float time;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* entries;
    int entryCount;
    unsigned short type;
    unsigned short unk22;
    int firstVertex;

    void FUN_00ba9fe0(Mesh_ba9fe0* pGeometry, unsigned short nSides);
};

// pdb: CIdvBranch::ComputeBranchNormals | Branch.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: pBranchGeometry, usSegments
void Branch_ba9fe0::FUN_00ba9fe0(Mesh_ba9fe0* pGeometry, unsigned short nSides)
{
    for (int i = 0; i < entryCount; ++i)
    {
        int nRing = i * (nSides + 1);
        for (int j = 0; j <= nSides; ++j)
        {
            int nPrevAround = (j == 0) ? nRing + nSides - 1 : nRing + j - 1;
            int nNextAround = (j == nSides) ? nRing + 1 : nRing + j + 1;
            nPrevAround += firstVertex;
            nNextAround += firstVertex;
            const float* pPrevAround = pGeometry->FUN_00baee70(nPrevAround);
            const float* pNextAround = pGeometry->FUN_00baee70(nNextAround);
            Vec3_ba9fe0 cTan1(pNextAround[0] - pPrevAround[0], pNextAround[1] - pPrevAround[1], pNextAround[2] - pPrevAround[2]);
            cTan1.Normalize();

            int nPrevAlong = (i == 0) ? nRing + j : (i - 1) * (nSides + 1) + j;
            int nNextAlong = (i == entryCount - 1) ? nRing + j : (i + 1) * (nSides + 1) + j;
            nPrevAlong += firstVertex;
            nNextAlong += firstVertex;
            const float* pPrevAlong = pGeometry->FUN_00baee70(nPrevAlong);
            const float* pNextAlong = pGeometry->FUN_00baee70(nNextAlong);
            Vec3_ba9fe0 cTan2(pNextAlong[0] - pPrevAlong[0], pNextAlong[1] - pPrevAlong[1], pNextAlong[2] - pPrevAlong[2]);
            cTan2.Normalize();

            pGeometry->FUN_00bb0a40(cTan1.Cross(cTan2));
            pGeometry->Advance();
        }
    }
}
}   // namespace f3m_00ba9fe0

// @f3 0x00bb7280 (community match, verified in this file)
#include <vector>
#include <math.h>
extern double DAT_0104ed58;
namespace f3m_00bb7280 {


namespace frond_bb7280 {

inline float FastRoot(float value)
{
    int bits = (*reinterpret_cast<int*>(&value) >> 1) + 0x1fc00000;
    return *reinterpret_cast<float*>(&bits);
}

class RotTransform
{
public:
    float m[3][3];
    void FUN_00bae170(float angle);
};

class Vec3
{
public:
    float v[3];

    Vec3();
    Vec3(float a, float b, float c);

    Vec3 operator*(const RotTransform& t) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator*(float f) const;
    Vec3 Cross(const Vec3& o) const;
    void Normalize();
    float Magnitude() const;
    float Distance(const Vec3& o) const;
    void Set(float a, float b, float c);
};

inline Vec3::Vec3()
{
    v[0] = v[1] = v[2] = 0.0f;
}

inline Vec3::Vec3(float a, float b, float c)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

inline Vec3 Vec3::operator*(const RotTransform& t) const
{
    return Vec3(v[0] * t.m[0][0] + v[1] * t.m[1][0] + v[2] * t.m[2][0],
                v[0] * t.m[0][1] + v[1] * t.m[1][1] + v[2] * t.m[2][1],
                v[0] * t.m[0][2] + v[1] * t.m[1][2] + v[2] * t.m[2][2]);
}

inline Vec3 Vec3::operator-(const Vec3& o) const
{
    return Vec3(v[0] - o.v[0], v[1] - o.v[1], v[2] - o.v[2]);
}

inline Vec3 Vec3::operator+(const Vec3& o) const
{
    return Vec3(v[0] + o.v[0], v[1] + o.v[1], v[2] + o.v[2]);
}

inline Vec3 Vec3::operator*(float f) const
{
    return Vec3(v[0] * f, v[1] * f, v[2] * f);
}

inline Vec3 Vec3::Cross(const Vec3& o) const
{
    return Vec3(v[1] * o.v[2] - v[2] * o.v[1], v[2] * o.v[0] - v[0] * o.v[2], v[0] * o.v[1] - v[1] * o.v[0]);
}

inline void Vec3::Normalize()
{
    float lengthSquared = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);
    float reciprocal = 1.0f / (float)sqrt(lengthSquared);
    v[0] *= reciprocal;
    v[1] *= reciprocal;
    v[2] *= reciprocal;
}

inline float Vec3::Magnitude() const
{
    return FastRoot(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

inline float Vec3::Distance(const Vec3& o) const
{
    return FastRoot((o.v[0] - v[0]) * (o.v[0] - v[0]) + (o.v[1] - v[1]) * (o.v[1] - v[1]) +
                    (o.v[2] - v[2]) * (o.v[2] - v[2]));
}

inline void Vec3::Set(float a, float b, float c)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

struct GuidePoint
{
    Vec3 pos;
    RotTransform rotation;
    float scale;
    unsigned char material;
};

struct FrondGuide
{
    std::vector<GuidePoint> points;
    float u10;
    float width;
    unsigned char layer;
    float angle;
    float u20;
    float u24;
    unsigned int start;
    unsigned int stride;
};

class Geometry
{
public:
    int u00;
    int u04;
    unsigned char enabled;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    unsigned short u20;
    unsigned short count;

    unsigned short GetCount() const
    {
        return count;
    }
    bool IsEnabled() const
    {
        return enabled != 0;
    }
    void Advance()
    {
        ++count;
    }
    void SetCount(unsigned int n)
    {
        count = (unsigned short)n;
    }
    void FUN_00bb09b0(const float* coord);
    void FUN_00bb0a70(const float* coord, unsigned short layer);
    void FUN_00bb0980(const float* color);
    void FUN_00bb0a40(const float* normal);
    void FUN_00bb0ce0(const float* tangent);
    void FUN_00bb0d30(const float* binormal);
    void FUN_00bb0c90(float scale, unsigned char material);
    const float* FUN_00baee70(unsigned int index);
    const float* FUN_00baeea0(unsigned int index);
};

class FrondEngine
{
public:
    Geometry* geometry;
    void* lighting;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    unsigned int blades;

    void FUN_00bb7280(FrondGuide& guide);
};

// pdb: CFrondEngine::BuildBladeVertices | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: sGuide
void FrondEngine::FUN_00bb7280(FrondGuide& guide)
{
    if (geometry && lighting)
    {
        // Fake match: two dead initialised locals. They only shift the compiler's symbol numbering, which decides
        // the x87 operand order of the first lane in the inlined scale and add helpers further down.
        int pad0 = 0;
        int pad1 = 0;
        float angleBetween = DAT_0104ed58 / (float)blades;

        guide.start = geometry->GetCount();
        guide.stride = 2;

        for (unsigned int k = 0; k < blades; ++k)
        {
            int localStart = geometry->GetCount();
            std::vector<Vec3> rightDirections;
            Vec3 binormal;
            float color[4];

            for (unsigned int i = 0; i < guide.points.size(); ++i)
            {
                RotTransform trans;
                if (i < guide.points.size() - 1)
                    trans = guide.points[i].rotation;
                else
                    trans = guide.points[i - 1].rotation;
                trans.FUN_00bae170(k * angleBetween + guide.angle);

                Vec3 rightDir = Vec3(0.0f, 1.0f, 0.0f) * trans;
                rightDirections.push_back(rightDir);

                Vec3 normal;
                if (i == 0)
                    normal = guide.points[i + 1].pos - guide.points[0].pos;
                else
                    normal = guide.points[i].pos - guide.points[0].pos;
                normal.Normalize();

                Vec3 left, right;
                if (i == guide.points.size() - 1 && guide.points.size() > 0)
                {
                    left = guide.points[i].pos + rightDirections[i - 1] * guide.width;
                    right = guide.points[i].pos - rightDirections[i - 1] * guide.width;
                }
                else if (i > 0 && i < guide.points.size() - 1)
                {
                    Vec3 temp;
                    temp = guide.points[i].pos + rightDirections[i - 1] * guide.width;
                    left = guide.points[i].pos + rightDir * guide.width;
                    left = (left + temp) * 0.5f;
                    temp = guide.points[i].pos - rightDirections[i - 1] * guide.width;
                    right = guide.points[i].pos - rightDir * guide.width;
                    right = (right + temp) * 0.5f;
                }
                else
                {
                    left = guide.points[i].pos + rightDir * guide.width;
                    right = guide.points[i].pos - rightDir * guide.width;
                }

                float lengthPercent = (float)i / ((float)guide.points.size() - 1.0);

                geometry->FUN_00bb09b0(left.v);
                float texCoords[2];
                texCoords[0] = 1.0f;
                texCoords[1] = lengthPercent;
                geometry->FUN_00bb0a70(texCoords, (unsigned short)guide.layer);
                color[0] = color[1] = color[2] = color[3] = 1.0f;
                geometry->FUN_00bb0980(color);
                geometry->FUN_00bb0a40(normal.v);
                geometry->FUN_00bb0ce0(rightDir.v);
                binormal = rightDir.Cross(normal);
                if (binormal.Magnitude() < (double)0.1f)
                    binormal = normal;
                else
                    binormal.Normalize();
                geometry->FUN_00bb0d30(binormal.v);
                if (geometry->IsEnabled())
                    geometry->FUN_00bb0c90(guide.points[i].scale, guide.points[i].material);
                geometry->Advance();

                geometry->FUN_00bb09b0(right.v);
                texCoords[0] = 0.0f;
                geometry->FUN_00bb0a70(texCoords, (unsigned short)guide.layer);
                color[0] = color[1] = color[2] = color[3] = 1.0f;
                geometry->FUN_00bb0980(color);
                geometry->FUN_00bb0a40(normal.v);
                geometry->FUN_00bb0ce0(rightDir.v);
                binormal = rightDir.Cross(normal);
                if (binormal.Magnitude() < (double)0.1f)
                    binormal = normal;
                else
                    binormal.Normalize();
                geometry->FUN_00bb0d30(binormal.v);
                if (geometry->IsEnabled())
                    geometry->FUN_00bb0c90(guide.points[i].scale, guide.points[i].material);
                geometry->Advance();
            }

            float leftLength = 0.0f, rightLength = 0.0f;
            std::vector<float> leftLengths, rightLengths;
            unsigned int size = guide.points.size();
            for (unsigned int i = 0; i < size - 1; ++i)
            {
                const float* thisCoord = geometry->FUN_00baee70(guide.start + i * 2);
                const float* nextCoord = geometry->FUN_00baee70(guide.start + i * 2 + 2);
                Vec3 current(thisCoord[0], thisCoord[1], thisCoord[2]);
                Vec3 next(nextCoord[0], nextCoord[1], nextCoord[2]);
                leftLength += current.Distance(next);
                leftLengths.push_back(leftLength);

                thisCoord = geometry->FUN_00baee70(guide.start + i * 2 + 1);
                nextCoord = geometry->FUN_00baee70(guide.start + i * 2 + 3);
                current.Set(thisCoord[0], thisCoord[1], thisCoord[2]);
                next.Set(nextCoord[0], nextCoord[1], nextCoord[2]);
                rightLength += current.Distance(next);
                rightLengths.push_back(rightLength);
            }

            geometry->SetCount(localStart + 2);
            for (unsigned int i = 1; i < size - 1; ++i)
            {
                const float* texCoord = geometry->FUN_00baeea0(guide.start + i * 2);
                float leftTexCoord[2];
                leftTexCoord[0] = texCoord[0];
                leftTexCoord[1] = leftLengths[i - 1] / leftLength * (double)0.999f;
                geometry->FUN_00bb0a70(leftTexCoord, (unsigned short)guide.layer);
                geometry->Advance();

                texCoord = geometry->FUN_00baeea0(guide.start + i * 2 + 1);
                float rightTexCoord[2];
                rightTexCoord[0] = texCoord[0];
                rightTexCoord[1] = rightLengths[i - 1] / rightLength * (double)0.999f;
                geometry->FUN_00bb0a70(rightTexCoord, (unsigned short)guide.layer);
                geometry->Advance();
            }
            geometry->Advance();
            geometry->Advance();
        }
    }
}

} // namespace frond_bb7280
}   // namespace f3m_00bb7280

// @f3 0x00bab280 (community match, verified in this file)
unsigned int* f3m_00bafd80::fo3_bafd80::UIntVector::FUN_00bab280(unsigned int* first, unsigned int* last, unsigned int* dest)
{
 unsigned int count=(unsigned int)(last-first);
 unsigned int bytes=count*sizeof(unsigned int);
 unsigned int* result=dest+count;
 if(count) f3m_00baf540::FUN_00c01c9b(dest,bytes,first,bytes);
 return result;
}

// @f3 0x00bab360 (community match, verified in this file)
inline void FillBab360(unsigned* dest,unsigned count,const unsigned& value) { for(;count>0;--count,++dest)*dest=value; }
unsigned* __stdcall FUN_00bab360(unsigned* dest,unsigned count,const unsigned& value) { FillBab360(dest,count,value);return dest+count; }

// @f3 0x00ba2fa0 (community match, verified in this file)
#include <string>
namespace f3m_00ba2fa0 {
namespace f3m_00ba2fa0 {
struct Owner {
    int unk00; int unk04; int unk08;
    std::string name;
    const char* FUN_00ba2fa0() const;
};
}
// pdb: std::logic_error::what | BipedAnim.obj | tesv_win, vtable, medium
const char* f3m_00ba2fa0::Owner::FUN_00ba2fa0() const
{
    return name.c_str();
}
}   // namespace f3m_00ba2fa0

// @f3 0x00bbda60 (community match, verified in this file)
extern float DAT_011782a4, DAT_011782a8, DAT_011782ac;
namespace f3m_00bbda60 {
namespace f3m_00bbda60 {
struct State {
 int unk00; float x,y,z; int unk10; float result;
 int unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 float upper,lower;
 float FUN_00bbda60();
};
// pdb: CTreeEngine::ComputeLod | TreeEngine.obj | fnv360_0822_retail, objrun, medium
float State::FUN_00bbda60() {
 
 union { float f; int i; } d;
 d.f=(x-DAT_011782a4)*(x-DAT_011782a4)+(y-DAT_011782a8)*(y-DAT_011782a8)+(z-DAT_011782ac)*(z-DAT_011782ac);
 d.i=(d.i>>1)+0x1fc00000;
 result=1.0f-(d.f-lower)/(upper-lower);
 if(result>1.0f) result=1.0f;
 else if(result<0.0f) result=0.0f;
 return result;
}
}

}   // namespace f3m_00bbda60

// @f3 0x00bb45c0 (community match, verified in this file)
namespace f3m_00bb45c0 {
struct S_00bb45c0 {
    char pad[60];
    char m;
    char FUN_00bb45c0();
};
// pdb: CFrondEngine::Enabled | FrondEngine.obj | fnv360_0822_retail, call_gap, low
char S_00bb45c0::FUN_00bb45c0()
{
    return m;
}
}   // namespace f3m_00bb45c0

// @f3 0x00ba7530 (community match, verified in this file)
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
#include <vector>
#include <string>
#include <algorithm>

namespace F_BA7530 {
struct Heap { void FUN_0086ba60(void*); void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
struct Allocated {
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
template<class T> struct Allocator : std::allocator<T> {
    template<class U> struct rebind { typedef Allocator<U> other; };
    Allocator() throw() {}
    template<class U> Allocator(const Allocator<U>&) throw() {}
    T* allocate(size_t n, const void* = 0) { return (T*)DAT_01090a78.FUN_0086b930(n*sizeof(T)); }
    void deallocate(T* p,size_t) { DAT_01090a78.FUN_0086ba60(p); }
};
template<class T,class U> bool operator==(const Allocator<T>&,const Allocator<U>&) { return true; }
template<class T,class U> bool operator!=(const Allocator<T>&,const Allocator<U>&) { return false; }
struct Owner;
typedef std::vector<Owner*, Allocator<Owner*> > Registry;
struct OwnedRegistry : Registry, Allocated {};
extern Registry DAT_01178294;
extern unsigned char DAT_0117827c[];
extern int DAT_01178278;
void FUN_00bc3850();
struct Resource {
    virtual ~Resource();
    unsigned char unknown04[0x1d];
    bool active;
    void FUN_00bbdd30();
};
struct SubA : Allocated { void FUN_00bb1c50(); ~SubA() { FUN_00bb1c50(); } };
struct SubB : Allocated { void FUN_00bb3320(); ~SubB() { FUN_00bb3320(); } };
struct SubC : Allocated { void FUN_00ba2fb0(); ~SubC() { FUN_00ba2fb0(); } };
struct SubD : Allocated { void FUN_00bbc430(); ~SubD() { FUN_00bbc430(); } };
typedef std::basic_string<char,std::char_traits<char>,Allocator<char> > Text;
struct NamedData : Allocated { unsigned int unknown00[9]; Text text; };
struct Logger { void FUN_0042f100(const char*,int); };
extern Logger DAT_01068a70;
extern const char DAT_00ea732c[];

struct Owner {
    Resource* resource;       // 00
    SubA* sub04;
    SubB* sub08;
    void* raw0c;
    void* raw10;
    void* raw14;
    unsigned int unknown18[5];
    void* raw2c;
    int* references;          // 30
    void* instanceData;       // 34
    OwnedRegistry* instances; // 38
    unsigned int unknown3c;
    void* raw40;
    unsigned int unknown44[2];
    SubC* sub4c;
    NamedData* named50;
    unsigned int unknown54;
    OwnedRegistry* list58;
    SubD* sub5c;
    SubA* sub60;
    unsigned int unknown64;
    void* raw68;
    void FUN_00ba7530();
};

// pdb: CSpeedTreeRT::~CSpeedTreeRT | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void Owner::FUN_00ba7530() {
    if (!instanceData) {
        EnterCriticalSection(&DAT_0117827c);
        Registry::iterator found = std::find(DAT_01178294.begin(),DAT_01178294.end(),this);
        if (found != DAT_01178294.end()) DAT_01178294.erase(found);
        LeaveCriticalSection(&DAT_0117827c);
    }
    --*references;
    if (instanceData) {
        instances->erase(std::find(instances->begin(),instances->end(),this));
        DAT_01090a78.FUN_0086ba60(instanceData);
        instanceData = 0;
    }
    if (!*references) {
        if (resource->active) resource->FUN_00bbdd30();
        else DAT_01068a70.FUN_0042f100(DAT_00ea732c,0x3a);
        delete sub04;
        DAT_01090a78.FUN_0086ba60(raw0c);
        DAT_01090a78.FUN_0086ba60(raw10);
        delete sub08;
        DAT_01090a78.FUN_0086ba60(raw14);
        delete resource;
        DAT_01090a78.FUN_0086ba60(references);
        delete instances;
        DAT_01090a78.FUN_0086ba60(raw40);
        delete list58;
        delete sub4c;
        delete sub5c;
        delete sub60;
        DAT_01090a78.FUN_0086ba60(raw2c);
        delete named50;
        DAT_01090a78.FUN_0086ba60(raw68);
    }
    sub04=0; raw0c=0; raw10=0; sub08=0; raw14=0;
    resource=0; references=0; raw40=0; instances=0; list58=0;
    sub4c=0; sub5c=0; sub60=0; raw2c=0; named50=0; raw68=0;
    if (--DAT_01178278 == 0) FUN_00bc3850();
}
}

// @f3 0x00bb2d40 (community match, verified in this file)
namespace f3m_00bb2d40 {
namespace f3m_00bb2d40 {

struct QMatrix;
struct QVec3 {
    float x;
    float y;
    float z;
    QVec3 transform(const QMatrix& m);
    QVec3() {}
    QVec3(const QVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct QMatrix {
    float m[4][4];
};

inline QVec3 QVec3::transform(const QMatrix& m)
{
    QVec3 r;
    r.x = m.m[0][0] * x + m.m[1][0] * y + m.m[2][0] * z + m.m[3][0];
    r.y = m.m[0][1] * x + m.m[1][1] * y + m.m[2][1] * z + m.m[3][1];
    r.z = m.m[0][2] * x + m.m[1][2] * y + m.m[2][2] * z + m.m[3][2];
    return r;
}

struct QPart {
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    int unk10;
    int unk14;
    QVec3* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    QVec3* unk40;
};

struct QMesh {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1C;
    unsigned short unk1E;
    QVec3* unk20;
    int unk24;
    unsigned short unk28;
    unsigned short unk2A;
    QPart* unk2C;
    void FUN_00bb2d40(const QMatrix& m);
};

// pdb: CLeafGeometry::Transform | LeafGeometry.obj | fnv360_0822_retail, objrun, medium
// pdb params: cTransform
void QMesh::FUN_00bb2d40(const QMatrix& m)
{
    if (!unk2C || !unk20)
        return;
    for (int i = 0; i < unk28; i++) {
        QPart* part = &unk2C[i];
        for (int j = 0; j < part->unk0C; j++) {
            QVec3 v(part->unk18[j]);
            part->unk18[j] = v.transform(m);
            if (unk01) {
                QVec3 v(part->unk40[j]);
                part->unk40[j] = v.transform(m);
            }
        }
    }
    float scale = m.m[0][0];
    for (int k = 0; k < unk1C; k++) {
        QVec3* p = &unk20[k];
        p->x *= scale;
        p->y *= scale;
        p->z *= scale;
    }
}

}
}   // namespace f3m_00bb2d40

// @f3 0x00bb6e70 (community match, verified in this file)
namespace f3m_00bb6e70 {
struct FUN_00bb5880
{
    int unk00;
    char* buffer;
    int unk08;
    int unk0C;

    // Fake match: noalias stands in for the copy constructor body the original compiler could see (it does not
    // capture or write through the source), so the integer loads of the by-value SortEntry copy hoist as in the
    // original. SortEntry itself uses the plain compiler-generated copy.
    __declspec(noalias) FUN_00bb5880(const FUN_00bb5880& other);
    FUN_00bb5880& FUN_00bb5d10(const FUN_00bb5880& other);
    FUN_00bb5880& operator=(const FUN_00bb5880& other) { return FUN_00bb5d10(other); }
    ~FUN_00bb5880()
    {
        if (buffer)
            ::operator delete(buffer);
    }
};

struct SortEntry
{
    FUN_00bb5880 name;
    float unk10;
    float unk14;
    bool unk18;
    float unk1C;
    float unk20;
    float key;
    int unk28;
    int unk2C;

};

struct SortEntryLess
{
    bool operator()(const SortEntry& a, const SortEntry& b) const { return a.key > b.key; }
};

void __cdecl FUN_00bb6e70(SortEntry* _First, int _Hole, int _Bottom, SortEntry _Val, SortEntryLess _Pred)
{
    int _Top = _Hole;
    int _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    std::_Push_heap(_First, _Hole, _Top, _Val, _Pred);
}

}   // namespace f3m_00bb6e70

// @f3 0x00ba1720 (community match, verified in this file)
namespace f3m_00ba1720 {
namespace f3m_00ba1720 {
// Vertex as stored in the array at +0x40.
struct Vertex { float x, y, z; };
// Three-float point with the usual engine helpers; the lane sums go through the (x, y, z) constructor.
struct Point3 {
    float x, y, z;
    Point3() {}
    Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    Point3(const Vertex& v) { x = v.x; y = v.y; z = v.z; }
    Point3 operator+(const Point3& pt) const { return Point3(x + pt.x, y + pt.y, z + pt.z); }
    Point3 operator*(float f) const { return Point3(x * f, y * f, z * f); }
    float FUN_00ba10c0(const Point3& pt) const;
};
struct Obj { void FUN_00bc05e0(int a, Point3 center, float radius, char* p); };
struct Self {
    int unk00; int unk04; int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    Vertex* unk40; int unk44, unk48; char* unk4c; Obj* unk50;
    int unk54, unk58, unk5c; int unk60;
    void FUN_00ba1720();
};
// pdb: CSpeedTreeRT::ComputeSelfShadowTexCoords | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void Self::FUN_00ba1720()
{
    int first = unk04;
    if (!first) return;
    if (!unk60) return;
    Obj* obj = unk50;
    if (!obj) return;

    Point3 p0(unk40[0]);
    Point3 center;
    float radius;
    {
        Point3 p1(unk40[1]);
        float dist = p0.FUN_00ba10c0(p1);
        radius = dist * 0.5;
        center = (p0 + p1) * 0.5;
    }

    if (unk4c) {
        obj->FUN_00bc05e0(first, center, radius, (char*)unk4c + 0x34);
        unk50->FUN_00bc05e0(unk60, center, radius, (char*)unk4c + 0x34);
    } else {
        obj->FUN_00bc05e0(first, center, radius, 0);
        unk50->FUN_00bc05e0(unk60, center, radius, 0);
    }
}
}
}   // namespace f3m_00ba1720

// @f3 0x00bb3f10 (community match, verified in this file)
namespace f3m_00bb3f10 {
void __cdecl operator delete(void*);
namespace T2107 {
struct Vec3
{
    float v[3];
    __forceinline void Set(float a, float b, float c)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
    }
    __forceinline Vec3(float a = 0, float b = 0, float c = 0)
    {
        Set(a, b, c);
    }
    __forceinline Vec3(const float* p)
    {
        Set(p[0], p[1], p[2]);
    }
    __forceinline float& operator[](int n)
    {
        return v[n];
    }
    inline float FUN_00b04d40(const Vec3& other) const
    {
        float squared = (other.v[0] - v[0]) * (other.v[0] - v[0]) + (other.v[1] - v[1]) * (other.v[1] - v[1]) +
                        (other.v[2] - v[2]) * (other.v[2] - v[2]);
        int bits = (*reinterpret_cast<int*>(&squared) >> 1) + 0x1fc00000;
        return *reinterpret_cast<float*>(&bits);
    }
};

struct FUN_00c24b70 {float values[5];int count;~FUN_00c24b70();};
struct FUN_00bc4990 {FUN_00c24b70 lo,hi;FUN_00bc4990();FUN_00bc4990 FUN_00bc48f0(const Vec3&)const;FUN_00bc4990 FUN_00bc4a00(const FUN_00bc4990&)const;};
void __cdecl FUN_00401010(void*);void __cdecl FUN_00c01e8b();
struct Radii {int allocator;float* first;float* last;float* end;
 Radii():first(0),last(0),end(0){}
 ~Radii(){if(first)::operator delete(first);}
 void FUN_0058da30(const float&);
 // std::vector<float> shape: size() and the checked subscript of the VS2005 library.
 unsigned int size() const { return first == 0 ? 0 : (unsigned int)(last - first); }
 float& operator[](unsigned int n){if(!(n<size()))FUN_00c01e8b();return first[n];}
};
struct LeafRecord
{
    int unk00, unk04, unk08;
    unsigned short vertexCount, unk0e;
    unsigned char* textures;
    int unk14;
    float* vertices;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
};
struct LeafGeometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short textureCount, unk1e;
    Vec3* sizes;
    Vec3* origins;
    unsigned short lodCount, unk2a;
    LeafRecord* lods;
    void FUN_00bb3f10(FUN_00bc4990& output);
};

// pdb: CLeafGeometry::ComputeExtents | LeafGeometry.obj | fnv360_0822_retail, call_gap, low
// pdb params: cExtents
void LeafGeometry::FUN_00bb3f10(FUN_00bc4990& output)
{
    if (origins && sizes && lods)
    {
        Radii radii;
        for (int i = 0; i < textureCount; ++i)
        {
            // Fake match: use direct lane-1 reads of sizes below to reproduce x87 temporary ranking.
            Vec3 center(origins[i][0] * sizes[i][0], origins[i][1] * sizes[i].v[1], 0);
            float radius = 0;
            if (center.FUN_00b04d40(Vec3(0, 0, 0)) > radius)
                radius = center.FUN_00b04d40(Vec3(0, 0, 0));
            if (center.FUN_00b04d40(Vec3(sizes[i][0], 0, 0)) > radius)
                radius = center.FUN_00b04d40(Vec3(sizes[i][0], 0, 0));
            if (center.FUN_00b04d40(Vec3(sizes[i][0], sizes[i].v[1], 0)) > radius)
                radius = center.FUN_00b04d40(Vec3(sizes[i][0], sizes[i].v[1], 0));
            if (center.FUN_00b04d40(Vec3(0, sizes[i].v[1], 0)) > radius)
                radius = center.FUN_00b04d40(Vec3(0, sizes[i].v[1], 0));
            radii.FUN_0058da30(radius);
        }
        for (int j = 0; j < lodCount; ++j)
        {
            LeafRecord* lod = &lods[j];
            for (unsigned int k = 0; k < lod->vertexCount; ++k)
            {
                FUN_00bc4990 bounds;
                const float* vertex5 = &lod->vertices[k * 3];
                Vec3 position(vertex5);
                float radius = radii[lod->textures[k] / 2];
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0] + radius, position.v[1], position.v[2]));
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0] - radius, position.v[1], position.v[2]));
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0], position.v[1] + radius, position.v[2]));
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0], position.v[1] - radius, position.v[2]));
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0], position.v[1], position.v[2] + radius));
                bounds = bounds.FUN_00bc48f0(Vec3(position.v[0], position.v[1], position.v[2] - radius));
                output = output.FUN_00bc4a00(bounds);
            }
        }
    }
}

}
}   // namespace f3m_00bb3f10

// @f3 0x00baa6d0 (community match, verified in this file)
#include <math.h>
#include <vector>

namespace f3m_00baa6d0 {

struct BranchPoint
{
    float x, y, z;
    BranchPoint()
    {}
    BranchPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    BranchPoint Cross(const BranchPoint& p)
    {
        return BranchPoint(p.z * y - p.y * z, p.x * z - p.z * x, p.y * x - p.x * y);
    }
};

struct BranchMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};

struct BranchEntry
{
    BranchPoint direction, position;
    float radius;
    BranchMatrix matrix;
    float distance, weight;
};

struct BranchMesh
{
    int unk00, unk04;
    bool hasWind;
    unsigned char unk09;
    unsigned short unk0a;
    int unk0c, unk10, unk14;
    float diameter, start;
    unsigned short unk20, vertices, unk24, groups;
    void FUN_00bb0a70(const float* uv, short selection);
    void FUN_00bb0ce0(const BranchPoint* tangent);
    void FUN_00bb0d30(const BranchPoint& normal);
    void FUN_00bb09b0(const BranchPoint& point);
    void FUN_00bb0980(const float* color);
    void FUN_00bb0c90(float weight, unsigned char index);
};

struct BranchFlare
{
    float unk00, unk04, unk08, unk0c, unk10, unk14;
    float FUN_00ba9b00(float angle, float position);
};

struct BranchShading
{
    int unk00, unk04;
    float blend;
};

extern BranchShading* DAT_011782b0;
extern float DAT_01068b40;
extern float DAT_01068b38;

struct BranchNode
{
    BranchNode* parent;
    float time;
    int unk08, unk0c, unk10, unk14;
    BranchEntry* entries;
    int entryCount;
    unsigned short type, unk22;
    unsigned int firstVertex;
    float unk28, unk2c;
    std::vector<BranchFlare> flares;
    void FUN_00baa6d0(BranchEntry* entry, float position, float factor, int sides, BranchMesh* mesh,
                      const BranchPoint& shape, float weight, unsigned int id, float step, int level);
};

// The flare callee (0x00ba9b00) comes earlier in the same source file; VC8 uses what it knows about this body
// when it allocates registers in FUN_00baa6d0 (with the body hidden, mesh is split around the flare loop).
float BranchFlare::FUN_00ba9b00(float angle, float position)
{
    float offset = 0.0f;
    float flareAngle = unk00;
    float delta = fabs(angle - flareAngle);
    if (delta > 3.14159265f)
    {
        if (flareAngle > angle)
            angle += DAT_01068b40;
        else
            flareAngle += DAT_01068b40;
    }
    delta = fabs(angle - flareAngle);
    if (delta < unk04)
    {
        float along = unk0c - position;
        if (along > 0.0)
        {
            float angular = 1.0f - delta / unk04;
            angular = pow(angular, unk08);
            float lengthwise = along / unk0c;
            lengthwise = pow(lengthwise, unk10);
            offset = unk14 * angular * lengthwise;
        }
    }
    return offset;
}

// pdb: CIdvBranch::BuildCrossSection | Branch.obj | fnv360_0721_beta, objrun_prop, low
// pdb params: pVertex, fBranchProgress, fCombinedBranchProgress, nSegments, pBranchGeometry, cTile, fWindWeight, nWindGroup, fTileOffset, nLevel
void BranchNode::FUN_00baa6d0(BranchEntry* entry, float position, float factor, int sides, BranchMesh* mesh,
                              const BranchPoint& shape, float weight, unsigned int id, float step, int level)
{
    float progress = 0.0f;
    // Guess: the double literal changes no code here; with 1.0f the shade * blend product below loads shade first.
    float increment = 1.0 / sides;
    float shade;
    if (DAT_011782b0)
    {
        shade = (1.0f - factor) * position + factor;
        if (!level)
            shade *= shade;
        shade = shade * DAT_011782b0->blend + (1.0f - DAT_011782b0->blend);
    }
    else
    {
        shade = 1.0f;
    }
    float vertexColor[4];
    vertexColor[2] = shade;
    vertexColor[1] = vertexColor[2];
    vertexColor[0] = vertexColor[1];
    vertexColor[3] = 1.0f;
    for (int i = 0; i <= sides; ++i)
    {
        // Guess: the (float) cast changes no code; it shifts the compiler's expression numbering so that the
        // direction and tangent products load their operands in the target's order (parentheses do the same).
        float angle = (float)(DAT_01068b40 * progress);
        float uv[2];
        uv[0] = progress * shape.x;
        uv[0] += shape.z * position;
        uv[1] = (position + step) * shape.y;
        mesh->FUN_00bb0a70(uv, -1);
        float c = cos(angle);
        float s = sin(angle);
        BranchPoint direction;
        direction.x = c * entry->matrix.m10 + s * entry->matrix.m20;
        direction.y = c * entry->matrix.m11 + s * entry->matrix.m21;
        direction.z = c * entry->matrix.m12 + s * entry->matrix.m22;
        c = cos(angle + DAT_01068b38);
        s = sin(angle + DAT_01068b38);
        BranchPoint tangent;
        tangent.x = c * entry->matrix.m10 + s * entry->matrix.m20;
        tangent.y = c * entry->matrix.m11 + s * entry->matrix.m21;
        tangent.z = c * entry->matrix.m12 + s * entry->matrix.m22;
        mesh->FUN_00bb0ce0(&tangent);
        mesh->FUN_00bb0d30(tangent.Cross(direction));
        float flareSum = 0.0f;
        for (unsigned int j = 0; j < flares.size(); ++j)
            flareSum += flares[j].FUN_00ba9b00(angle, position);
        float radiusScale = flareSum + 1.0;
        BranchPoint point;
        point.x = direction.x * entry->radius + entry->position.x;
        point.y = direction.y * entry->radius + entry->position.y;
        point.z = direction.z * entry->radius + entry->position.z;
        if (radiusScale != 1.0)
        {
            BranchPoint scaled;
            scaled.x = direction.x * entry->radius * radiusScale + entry->position.x;
            scaled.y = direction.y * entry->radius * radiusScale + entry->position.y;
            scaled.z = direction.z * entry->radius * radiusScale + entry->position.z;
            point = scaled;
        }
        mesh->FUN_00bb09b0(point);
        mesh->FUN_00bb0980(vertexColor);
        if (mesh->hasWind)
            mesh->FUN_00bb0c90(weight, id);
        ++mesh->vertices;
        progress += increment;
    }
}

}

// @f3 0x00ba8680 (community match, verified in this file)
struct W474Vec3 { float x, y, z; };
struct W474Shape { int f00; W474Vec3 vec; int f10; float f14; };
struct W474Ref { void* owner; W474Vec3 vec; float f10; };
struct W474Heap { void* FUN_0086b930(unsigned size); };
struct W474Tree;

struct W474Coll { void FUN_00ba8140(W474Tree** p); };

struct W474Text {
    W474Text();
    W474Text(const W474Text&);
    char pad00[4];
    union { char buf[16]; char* ptr; };
    unsigned size;
    unsigned capacity;
    ~W474Text();
    const char* c_str() const { return capacity >= 0x10 ? ptr : buf; }
};

static __declspec(noinline) W474Text w474_fmt(const char* format, ...)
{
    W474Text text;
    va_list args;
    va_start(args, format);
    vsprintf(text.buf, format, args);
    va_end(args);
    return text;
}

struct W474Tree {
    W474Shape* f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    int f2c;
    int* f30;
    W474Ref* f34;
    W474Coll* f38;
    int f3c;
    int f40;
    unsigned char f44;
    char f45;
    int f48;
    int f4c;
    int f50;
    short f54;
    int f58;
    int f5c;
    int f60;
    short f64;
    int f68;
    char f6c;
    unsigned char f6d;
    int block70[12];

    void* FUN_00ba8680(W474Tree* src);
};

void* W474Tree::FUN_00ba8680(W474Tree* src)
{
    extern W474Heap w474_heap;
    extern int w474_counter;
    extern const char w474_strA[];
    extern const char w474_strB[];
    extern const char w474_strC[];
    extern void* w474_copy(void* dest, const void* source, unsigned int count);
    extern void w474_report(const char* text);

    W474Tree* other = src;
    try
    {
        f00 = other->f00;
        f04 = other->f04;
        f08 = other->f08;
        f0c = other->f0c;
        f10 = other->f10;
        f14 = other->f14;
        f18 = other->f18;
        f1c = other->f1c;
        f20 = other->f20;
        src = this;
        f24 = other->f24;
        f28 = other->f28;
        f2c = other->f2c;
        f30 = other->f30;
        f38 = other->f38;
        f3c = other->f3c;
        f40 = other->f40;
        f44 = other->f44;
        f45 = other->f45;
        f48 = other->f48;
        f4c = other->f4c;
        f50 = other->f50;
        f54 = other->f54;
        f58 = other->f58;
        f5c = other->f5c;
        f60 = other->f60;
        f64 = other->f64;
        f68 = other->f68;
        f6c = other->f6c;
        f6d = other->f6d;

        f38->FUN_00ba8140(&src);
        w474_copy(block70, other->block70, 0x30);
        ++*f30;

        W474Ref* node = (W474Ref*)w474_heap.FUN_0086b930(0x14);
        if (node != 0)
        {
            node->owner = 0;
            node->vec.z = 0.0f;
            node->vec.y = 0.0f;
            node->vec.x = 0.0f;
            node->f10 = 1.0f;
        }
        else
        {
            node = 0;
        }
        f34 = node;
        node->owner = other;
        f34->vec = other->f00->vec;

        float offset = other->f34 ? other->f34->f10 : other->f00->f14;
        f34->f10 = offset;
        ++w474_counter;
    }
    catch (std::exception& e)
    {
        w474_report(w474_fmt(w474_strA, w474_strC, e.what()).c_str());
    }
    catch (...)
    {
        w474_report(w474_fmt(w474_strB, w474_strC).c_str());
    }
    return this;
}

// @f3 0x00bbbf90 (community match, verified in this file)
#include <vector>
namespace f3m_00bbbf90 {
namespace f3m_00bbbf90 {
namespace w_bbbf90 {
void __cdecl FUN_00401010(void*) throw();
struct Entry {
    unsigned int allocator;
    void* first;
    void* last;
    void* end;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ~Entry() { tidy(); }
    void tidy() { if (first) FUN_00401010(first); first = 0; last = 0; end = 0; }
};
typedef std::vector<Entry> Row;
class RowVector : public std::vector<Row>
{
public:
    void FUN_00bbbf90(iterator _Where, size_type _Count, const Row& _Val);
};
// pdb: std::_Uninit_move<SFrondGuide *,SFrondGuide *,std::allocator<SFrondGuide>,SFrondGuide> | FrondEngine.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: _First, _Last, _Dest, _Al, __formal, __formal
void RowVector::FUN_00bbbf90(iterator _Where, size_type _Count, const Row& _Val)
{
    Row _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
        _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
        _Ptr = _Ufill(_Ptr, _Count, _Tmp);
        _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
        _Destroy(_Newvec, _Ptr);
        this->_Alval.deallocate(_Newvec, _Capacity);
        throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try {
        _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
        _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
        throw;
        }
        _Mylast += _Count;
        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}
}
}
}   // namespace f3m_00bbbf90

// @f3 0x00ba50e0 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
extern const char DAT_00ea7310[];
extern const char DAT_00ea7220[];
extern const char DAT_00ea71f8[];
namespace f3m_00ba50e0 {
namespace sol_bfc6 {
struct Heap { void* FUN_0086b930(unsigned); };

void FUN_00ba3d50(const char*);
void FUN_00c01e8b();
struct Text {
 unsigned allocator;
 union { char buf[16]; char* ptr; };
 unsigned size, capacity;
 Text(); Text(const Text&);
 void FUN_0042dba0();
 ~Text() { FUN_0042dba0(); }
 const char* c_str() const { return capacity >= 16 ? ptr : buf; }
};
static __declspec(noinline) Text FUN_00bb56f0(const char* fmt, ...) {
 Text t; va_list args; va_start(args,fmt); vsprintf(t.buf,fmt,args); va_end(args); return t;
}
struct TexturePtr {
 const char* ptr;
 static void* operator new[](unsigned size) { return DAT_01090a78.FUN_0086b930(size); }
};
struct Leaf { int unk00,unk04,unk08,unk0c,unk10; Text name; int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50; };
struct Frond { Text name; int unk1c,unk20,unk24,unk28; };
template<class T> struct Vec {
 unsigned allocator; T* first; T* last; T* end;
 unsigned size() const { return first == 0 ? 0 : last-first; }
 unsigned FUN_00ba1940() const;
 T& operator[](unsigned i) { if(i>=size()) FUN_00c01e8b(); return first[i]; }
};
struct Data {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
 Text name;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84,unk88,unk8c,unk90;
 Vec<Leaf> leaves;
};
struct FrondData { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c; Vec<Frond> fronds; };
struct BranchData { int unk00,unk04,unk08,unk0c,unk10,unk14; Text name; };
struct CompositeData { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20; Text name; };
struct Output {const char* branch; unsigned leafCount; TexturePtr* leaves; unsigned frondCount; TexturePtr* fronds; const char* branchMap;const char* composite;};
struct Tree {
 Data* data; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48;
 BranchData* branch; CompositeData* composite; int unk54,unk58; FrondData* frondData;
 void FUN_00ba50e0(Output* out);
};
// pdb: CSpeedTreeRT::GetTextures | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
// pdb params: sTextures
void Tree::FUN_00ba50e0(Output* out) {
 try {
 out->branch=data->name.c_str();
 Vec<Leaf>& leaves=data->leaves;
 out->leafCount=leaves.size();
 if(out->leafCount>0) {
 out->leaves=new TexturePtr[out->leafCount];
 for(unsigned i=0;i<leaves.FUN_00ba1940();i++) out->leaves[i].ptr=leaves[i].name.c_str();
 } else out->leaves=0;
 out->frondCount=frondData->fronds.size();
 if(out->frondCount>0) {
 out->fronds=new TexturePtr[out->frondCount];
 for(unsigned i=0;i<out->frondCount;i++) out->fronds[i].ptr=frondData->fronds[i].name.c_str();
 } else out->fronds=0;
 if(composite) out->composite=composite->name.c_str();
 if(branch) out->branchMap=branch->name.c_str();
 } catch(std::exception& e) {
 FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220,DAT_00ea7310,e.what()).c_str());
 } catch(...) {
 FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8,DAT_00ea7310).c_str());
 }
}
}
}   // namespace f3m_00ba50e0

// @f3 0x00bab8d0 (community match, verified in this file)
#include <memory>
namespace f3m_00bab8d0 {
namespace sol_bab8 {
struct Element {int unk00,unk04,unk08,unk0C,unk10,unk14;};
struct Vector;
struct Iterator {void* owner; Element* pointer;};
void __cdecl FUN_00401010(void*) throw();
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Element* __cdecl FUN_00bb4690(unsigned,Element*);
Element* __cdecl FUN_00baac40(Element*,Element*,Element*,Vector&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
void __cdecl FUN_00bc2130(Element*,Element*,const Element&) throw();
Element* __cdecl FUN_00bc2900(Element*,Element*,Element*);
struct Vector {
 int allocator;
 Element* begin;
 Element* end;
 Element* limit;
 unsigned size()const{return begin==0?0:(unsigned)(end-begin);}
 unsigned capacity()const{return begin==0?0:(unsigned)(limit-begin);}
 unsigned FUN_00bb4670()const;
 Element* FUN_00bab3c0(Element*,Element*,Element*);
 Element* FUN_00bc29d0(Element*,unsigned,const Element&);
 void FUN_00bab8d0(Iterator,unsigned,const Element&);
 __forceinline Element* move_inline(Element* a,Element* b,Element* c){return FUN_00baac40(a,b,c,*this,std::_Ptr_cat(a,c),std::_Range_checked_iterator_tag());}
};
void Vector::FUN_00bab8d0(Iterator where,unsigned count,const Element& value){
 Element temporary=value;
 unsigned capacityValue=capacity();
 if(count==0);
 else if(0xaaaaaaaU-size()<count)FUN_00bc5f00();
 else if(capacityValue<size()+count){
  capacityValue=0xaaaaaaaU-capacityValue/2<capacityValue?0:capacityValue+capacityValue/2;
  if(capacityValue<size()+count)capacityValue=FUN_00bb4670()+count;
  Element* newVector=FUN_00bb4690(capacityValue,0);
  Element* ptr=newVector;
  try{
   ptr=move_inline(begin,where.pointer,newVector);
   ptr=FUN_00bc29d0(ptr,count,temporary);
   move_inline(where.pointer,end,ptr);
  }catch(...){FUN_00401010(newVector);throw;}
  count+=size();
  if(begin!=0)FUN_00401010(begin);
  limit=newVector+capacityValue;
  end=newVector+count;
  begin=newVector;
 }else if((unsigned)(end-where.pointer)<count){
  FUN_00bab3c0(where.pointer,end,where.pointer+count);
  try{
   FUN_00bc29d0(end,count-(end-where.pointer),temporary);
  }catch(...){throw;}
  end+=count;
  FUN_00bc2130(where.pointer,end-count,temporary);
 }else{
  Element* oldEnd=end;
  end=FUN_00bab3c0(oldEnd-count,oldEnd,end);
  FUN_00bc2900(where.pointer,oldEnd-count,oldEnd);
  FUN_00bc2130(where.pointer,where.pointer+count,temporary);
 }
}
}
}   // namespace f3m_00bab8d0

// @f3 0x00ba57f0 (community match, verified in this file)
namespace sol_ba57 {
struct Elem28 { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18; };
struct Iter28 { void* cont; Elem28* ptr; };
struct Alloc { int unk00; };
struct NonscalarTag {};
struct RangeCheckedTag {};
inline NonscalarTag PtrCat(Elem28*,Elem28*) { NonscalarTag cat; return cat; }
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Elem28* __cdecl FUN_00ba19e0(unsigned int, const void*);
Elem28* __cdecl FUN_00ba2910(Elem28*, Elem28*, Elem28*, Alloc&, NonscalarTag, RangeCheckedTag);
__declspec(nothrow) void __cdecl FUN_00ba2db0(Elem28*, Elem28*, const Elem28&);
Elem28* __cdecl FUN_00ba2f70(Elem28*, Elem28*, Elem28*);
struct Vec : Alloc {
 Elem28* first; Elem28* last; Elem28* end;
 unsigned int size() const { return first == 0 ? 0 : last-first; }
 unsigned int capacity() const { return first == 0 ? 0 : end-first; }
 unsigned int FUN_00ba1960();
 Elem28* FUN_00ba32c0(Elem28*,unsigned int,const Elem28&);
 Elem28* FUN_00ba33f0(Elem28*,Elem28*,Elem28*);
 void FUN_00ba57f0(Iter28 where,unsigned int count,const Elem28& value);
 __forceinline Elem28* copy(Elem28* a,Elem28* b,Elem28* d) { return FUN_00ba2910(a,b,d,*this,PtrCat(a,d),RangeCheckedTag()); }
};
void Vec::FUN_00ba57f0(Iter28 where,unsigned int count,const Elem28& value) {
 Elem28 tmp=value;
 unsigned int cap=capacity();
 if(count==0) ;
 else if(0x9249249u-size()<count) FUN_00bc5f00();
 else if(cap<size()+count) {
  cap=0x9249249u-cap/2<cap?0:cap+cap/2;
  if(cap<size()+count) cap=FUN_00ba1960()+count;
  Elem28* newvec=FUN_00ba19e0(cap,0);
  Elem28* ptr=newvec;
  try {
   ptr=copy(first,where.ptr,newvec);
   ptr=FUN_00ba32c0(ptr,count,tmp);
   copy(where.ptr,last,ptr);
  } catch(...) { DAT_01090a78.FUN_0086ba60(newvec); throw; }
  count+=size();
  if(first!=0) DAT_01090a78.FUN_0086ba60(first);
  end=newvec+cap; last=newvec+count; first=newvec;
 } else if((unsigned int)(last-where.ptr)<count) {
  FUN_00ba33f0(where.ptr,last,where.ptr+count);
  try { FUN_00ba32c0(last,count-(last-where.ptr),tmp); }
  catch(...) { throw; }
  last+=count;
  FUN_00ba2db0(where.ptr,last-count,tmp);
 } else {
  Elem28* oldend=last;
  last=FUN_00ba33f0(oldend-count,oldend,last);
  FUN_00ba2f70(where.ptr,oldend-count,oldend);
  FUN_00ba2db0(where.ptr,where.ptr+count,tmp);
 }
}
}

// @f3 0x00ba7d10 (community match, verified in this file)
#include <exception>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
namespace sol7d10 {
struct Vec3 {
 float x,y,z;
 Vec3() {}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3(const float* p):x(p[0]),y(p[1]),z(p[2]){}
 bool operator!=(const Vec3& p) const { return x!=p.x || y!=p.y || z!=p.z; }
 bool FUN_00ba1100(const Vec3&) const;
};
extern Vec3 DAT_011782a4, DAT_01068b04;
extern float DAT_01068a58,DAT_01068a5c,DAT_01068a60;
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
 void FUN_0042f100(const char*,unsigned);
};
extern Text DAT_01068a70;
extern const char DAT_00ea79d8[],DAT_00ea79c0[],DAT_00ea7220[],DAT_00ea71f8[];
void FUN_00ba3d50(const char*);
void FUN_00ba6f70(bool);
void FUN_00bc1a70(const Vec3*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}
// pdb: CSpeedTreeRT::SetCamera | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pPosition, pDirection
void FUN_00ba7d10(const float* position,const float* direction) {
 try {
  if(position && direction) {
   Vec3 oldP=DAT_011782a4;
   Vec3 oldD=DAT_01068b04;
   Vec3 p(position[0],position[1],position[2]);
   Vec3 d(direction[0],direction[1],direction[2]);
   if(p!=oldP || oldD.FUN_00ba1100(d)) {
    DAT_011782a4=p;
    DAT_01068b04=d;
    FUN_00ba6f70(true);
    FUN_00bc1a70(&d);
    FUN_00ba6f70(true);
    float angle=(float)asin(d.z);
    angle *= 57.295780181884766;
    float t=1.0-(angle-DAT_01068a58)/(DAT_01068a5c-DAT_01068a58);
    if(0.0>t) t=0.0;
    if(1.0<t) t=1.0;
    DAT_01068a60=t*171.0+84.0;
   }
  } else DAT_01068a70.FUN_0042f100(DAT_00ea79d8,59);
 } catch(std::exception& e) {
  FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220,DAT_00ea79c0,e.what()).c_str());
 } catch(...) {
  FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8,DAT_00ea79c0).c_str());
 }
}
}

// @f3 0x00ba6f70 (community match, verified in this file)
#include <vector>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void*);
namespace f3m_00ba6f70 {
struct Heap { void FUN_0086ba60(void*); void* FUN_0086b930(unsigned int); };
extern Heap DAT_01090a78;
template<class T> struct Allocator : std::allocator<T> {
    template<class U> struct rebind { typedef Allocator<U> other; };
    Allocator() throw() {}
    template<class U> Allocator(const Allocator<U>&) throw() {}
    T* allocate(size_t n, const void* = 0) { return (T*)DAT_01090a78.FUN_0086b930(n*sizeof(T)); }
    void deallocate(T* p,size_t) { DAT_01090a78.FUN_0086ba60(p); }
};
template<class T,class U> bool operator==(const Allocator<T>&,const Allocator<U>&) { return true; }
template<class T,class U> bool operator!=(const Allocator<T>&,const Allocator<U>&) { return false; }

struct Flagged {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char dirty12;
    void invalidate() { dirty12 = 0; }
};
struct BranchList { void FUN_00bb2cb0(); };
struct Modes {
    unsigned int unk00;
    unsigned int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned char unk14;
    bool usesBranchLighting() const { return unk08 == 1; }
    bool usesFrondLighting() const { return unk0c == 1; }
    bool usesLeafLighting() const { return unk10 == 1; }
    bool hasLeafOverride() const { return unk14 != 0; }
};
struct LeafState {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned char valid30;
};
struct Owner {
    void* resource;
    Flagged* sub04;
    BranchList* sub08;
    void* raw0c;
    Modes* raw10;
    LeafState* raw14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    void* raw2c;
    int* references;
    void* instanceData;
    void* instances;
    unsigned int unknown3c;
    void* raw40;
    unsigned int unk44;
    unsigned int unk48;
    void* sub4c;
    void* named50;
    unsigned int unknown54;
    void* list58;
    void* sub5c;
    Flagged* sub60;
};
typedef std::vector<Owner*, Allocator<Owner*> > Registry;
extern Registry DAT_01178294;
extern unsigned char DAT_0117827c[];

struct StrQ
{
    unsigned char allocator;
    union
    {
        char buffer[16];
        char* heap;
    };
    unsigned size;
    unsigned capacity;
    void FUN_0042dba0();
    ~StrQ()
    {
        FUN_0042dba0();
    }
    void Assign(const char* p, unsigned len);
    StrQ(const char* p)
    {
        capacity = 15;
        size = 0;
        buffer[0] = 0;
        Assign(p, (unsigned)strlen(p));
    }
    const char* c_str() const
    {
        return capacity >= 16 ? heap : buffer;
    }
};

static __declspec(noinline) StrQ FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    va_end(args);
    return StrQ(text);
}
void FUN_00ba3d50(const char* p);

void FUN_00ba6f70(int event)
{
    try
    {
        fnv_EnterCriticalSection(&DAT_0117827c);
        for (Registry::iterator it = DAT_01178294.begin(); it != DAT_01178294.end(); ++it)
        {
            if (event == 0)
            {
                if ((*it)->raw10->usesBranchLighting())
                    (*it)->sub04->invalidate();
                if ((*it)->raw10->usesFrondLighting())
                    (*it)->sub60->invalidate();
                if ((*it)->raw10->usesLeafLighting() || (*it)->raw10->hasLeafOverride())
                    (*it)->sub08->FUN_00bb2cb0();
            }
            else if (event == 1)
            {
                (*it)->sub08->FUN_00bb2cb0();
                (*it)->raw14->valid30 = 0;
            }
        }
        fnv_LeaveCriticalSection(&DAT_0117827c);
    }
    catch (std::exception& e)
    {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::NotifyAllTreesOfEvent", e.what()).c_str());
    }
    catch (...)
    {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::NotifyAllTreesOfEvent").c_str());
    }
}
}

// @f3 0x00ba8300 (community match, verified in this file)
#include <vector>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void*);
namespace f3m_00ba8300 {

struct PoolAlloc { void* Alloc(unsigned int size); void Free(void* p); };
extern PoolAlloc DAT_01090a78;

struct CSpeedTreeRT;
struct RegistryStandIn { void FUN_00ba8140(CSpeedTreeRT* const& ref); };
extern RegistryStandIn DAT_01178294;

extern unsigned char DAT_0117827c[];
extern int DAT_01178278;
extern void* DAT_011782b4;

extern float FUN_00de7b04;
extern float FUN_00db9254;
extern float FUN_00dbe1e0;
struct T44;
struct T118;
struct T110;
struct T30;
struct T34;

struct T44 {
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
    T44();
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct T118 {
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
    T118(T44* p, int v);
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct T110 {
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
    T110(T118* p);
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct Tb0 {
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
    Tb0();
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct T30 {
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
    T30(T44* p);
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct T34 {
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
    T34();
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

struct T6c {
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
    T6c();
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};

template<class T> struct NativeAllocator : std::allocator<T> {
    template<class U> struct rebind { typedef NativeAllocator<U> other; };
    NativeAllocator() throw() {}
    template<class U> NativeAllocator(const NativeAllocator<U>&) throw() {}
    T* allocate(size_t n, const void* = 0) { return (T*)DAT_01090a78.Alloc(n*sizeof(T)); }
    void deallocate(T* p, size_t) { DAT_01090a78.Free(p); }
};
template<class T,class U> bool operator==(const NativeAllocator<T>&,const NativeAllocator<U>&) { return true; }
template<class T,class U> bool operator!=(const NativeAllocator<T>&,const NativeAllocator<U>&) { return false; }
struct G10 {
    std::vector<CSpeedTreeRT*, NativeAllocator<CSpeedTreeRT*> > trees;
    static void* operator new(unsigned int sz) { return DAT_01090a78.Alloc(sz); }
};
typedef char NativeTreeVectorSize[(sizeof(G10) == 16) ? 1 : -1];


struct CSpeedTreeRT {
    T110* m_00;
    T118* m_04;
    T30* m_08;
    Tb0* m_0c;
    T44* m_10;
    T34* m_14;
    int m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    int m_2c;
    int* m_30;
    int m_34;
    G10* m_38;
    int m_3c;
    float* m_40;
    char m_44;
    char m_45;
    int m_48;
    int m_4c;
    int m_50;
    short m_54;
    int m_58;
    T6c* m_5c;
    T118* m_60;
    short m_64;
    int m_68;
    char m_6c;
    char m_6d;
    float m_70[12];
    CSpeedTreeRT();
};

struct StrQ
{
    unsigned char allocator;
    union
    {
        char buffer[16];
        char* heap;
    };
    unsigned size;
    unsigned capacity;
    void FUN_0042dba0();
    ~StrQ()
    {
        FUN_0042dba0();
    }
    void Assign(const char* p, unsigned len);
    StrQ(const char* p)
    {
        capacity = 15;
        size = 0;
        buffer[0] = 0;
        Assign(p, (unsigned)strlen(p));
    }
    const char* c_str() const
    {
        return capacity >= 16 ? heap : buffer;
    }
};

static __declspec(noinline) StrQ FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    va_end(args);
    return StrQ(text);
}
void FUN_00ba3d50(const char* p);


CSpeedTreeRT::CSpeedTreeRT()
{
        m_1c = FUN_00de7b04;
        m_20 = FUN_00db9254;
        m_24 = FUN_00dbe1e0;
        m_00 = 0;
        m_04 = 0;
        m_28 = 0.0f;
        m_08 = 0;
        m_0c = 0;
        m_10 = 0;
        m_14 = 0;
        m_18 = 1;
        m_2c = 0;
        m_30 = 0;
        m_34 = 0;
        m_3c = -1;
        m_40 = 0;
        m_44 = 0x54;
        m_45 = 0;
        m_48 = -1;
        m_4c = 0;
        m_50 = 0;
        m_54 = 0;
        m_58 = 0;
        m_5c = 0;
        m_64 = 0;
        m_68 = 0;
        m_6c = 0;
        m_6d = 0;
    try {
        m_10 = new T44();
        m_04 = new T118(m_10, 0);
        m_00 = new T110(m_04);
        m_0c = new Tb0();
        m_08 = new T30(m_10);
        m_14 = new T34();
        m_40 = (float*)DAT_01090a78.Alloc(0x1c);
        m_30 = (int*)DAT_01090a78.Alloc(4);
        *m_30 = 1;
        m_38 = new G10();
        m_5c = new T6c();
        m_60 = new T118(m_10, 1);
        fnv_EnterCriticalSection(&DAT_0117827c);
        DAT_01178294.FUN_00ba8140(this);
        DAT_01178278 += 1;
        fnv_LeaveCriticalSection(&DAT_0117827c);
        DAT_011782b4 = m_0c;
        m_40[0] = 0.0f;
        m_40[1] = 0.0f;
        m_40[2] = 0.0f;
        m_40[3] = 1.0f;
        m_40[4] = 1.0f;
        m_40[5] = 1.0f;
        m_40[6] = 1.0f;
        for (int i = 0; i < 12; i++)
            m_70[i] = 0.0f;
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::CSpeedTreeRT( )", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::CSpeedTreeRT( )").c_str());
    }

}

}

// @f3 0x00bb19c0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb19c0 {
namespace NativeInsert650 {
struct FUN_00be0df0 {
    std::allocator<unsigned> allocator;
    unsigned* first;
    unsigned* last;
    unsigned* end;
    FUN_00be0df0(const FUN_00be0df0&);
    FUN_00be0df0& FUN_00bafd80(const FUN_00be0df0&);
    ~FUN_00be0df0() { if(first) ::operator delete(first); first=0;last=0;end=0; }
};
typedef FUN_00be0df0 Record;
struct Vector;
struct Iterator { Vector* container;Record* position; };
struct Vector {
    std::allocator<Record> allocator;
    Record* first;
    Record* last;
    Record* end;
    unsigned size() const { return first==0?0:unsigned(last-first); }
    unsigned capacity() const { return first==0?0:unsigned(end-first); }
    unsigned max_size() const { return unsigned(-1)/sizeof(Record); }
    Record* FUN_00bb10d0(Record*,Record*,Record*);
    Record* FUN_00bb1060(Record*,unsigned,const Record&);
    void FUN_00bafeb0(Record*,Record*) throw();
    Record* copyToRaw(Record* begin,Record* finish,Record* destination);
    void FUN_00bb19c0(Iterator where,unsigned count,const Record& value);
};
Record* __cdecl FUN_00baec30(unsigned,Record*);
Record* __cdecl FUN_00bb0620(Record*,Record*,Record*,std::allocator<Record>&,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
void __cdecl FUN_00baf710(Record*,Record*,std::allocator<Record>&,std::_Nonscalar_ptr_iterator_tag) throw();
void __cdecl FUN_00bb03b0(Record*,Record*,const Record&);
Record* __cdecl FUN_00bb9b60(Record*,Record*,Record*);
__declspec(noreturn) void __cdecl FUN_00bc5f00();
inline Record* Vector::copyToRaw(Record* begin,Record* finish,Record* destination)
{ return FUN_00bb0620(begin,finish,destination,allocator,std::_Ptr_cat(begin,destination),std::_Range_checked_iterator_tag()); }
void Vector::FUN_00bb19c0(Iterator where,unsigned count,const Record& value)
{
    Record saved(value);
    unsigned capacity=this->capacity();
    if(count==0) {
    } else if(max_size()-size()<count) {
        FUN_00bc5f00();
    } else if(capacity<size()+count) {
        capacity=max_size()-capacity/2<capacity?0:capacity+capacity/2;
        if(capacity<size()+count)
            capacity=size()+count;
        Record* newFirst=FUN_00baec30(capacity,0);
        Record* constructedEnd=newFirst;
        try {
            constructedEnd=copyToRaw(first,where.position,constructedEnd);
            constructedEnd=FUN_00bb1060(constructedEnd,count,saved);
            copyToRaw(where.position,last,constructedEnd);
        } catch(...) {
            FUN_00bafeb0(newFirst,constructedEnd);
            ::operator delete(newFirst);
            throw;
        }
        count+=size();
        if(first) {
            FUN_00baf710(first,last,allocator,std::_Ptr_cat(first,last));
            ::operator delete(first);
        }
        end=newFirst+capacity;
        last=newFirst+count;
        first=newFirst;
    } else if(unsigned(last-where.position)<count) {
        FUN_00bb10d0(where.position,last,where.position+count);
        try {
            FUN_00bb1060(last,count-unsigned(last-where.position),saved);
        } catch(...) {
            FUN_00bafeb0(where.position+count,last+count);
            throw;
        }
        last+=count;
        FUN_00bb03b0(where.position,last-count,saved);
    } else {
        Record* oldEnd=last;
        last=FUN_00bb10d0(oldEnd-count,oldEnd,last);
        FUN_00bb9b60(where.position,oldEnd-count,oldEnd);
        FUN_00bb03b0(where.position,where.position+count,saved);
    }
}
}

}   // namespace f3m_00bb19c0

// @f3 0x00bbad60 (community match, verified in this file)
#include <vector>
#include <math.h>
namespace f3m_00bbad60 {


inline float FastRoot(float value)
{
    int bits = (*reinterpret_cast<int*>(&value) >> 1) + 0x1fc00000;
    return *reinterpret_cast<float*>(&bits);
}

class RotTransform
{
public:
    float m[3][3];
    __declspec(noinline) void FUN_00bae170(float angle);
    __declspec(noinline) RotTransform FUN_00ba9610(const RotTransform& right) const;
};

// Native helper rotates around the x axis in degrees, then pre-multiplies
// the existing transformation. Both callees are present in the original file.
__declspec(noinline) RotTransform RotTransform::FUN_00ba9610(const RotTransform& right) const
{
    RotTransform result;
    result.m[0][0] = m[0][0] * right.m[0][0] + m[0][1] * right.m[1][0] + m[0][2] * right.m[2][0];
    result.m[0][1] = m[0][0] * right.m[0][1] + m[0][1] * right.m[1][1] + m[0][2] * right.m[2][1];
    result.m[0][2] = m[0][0] * right.m[0][2] + m[0][1] * right.m[1][2] + m[0][2] * right.m[2][2];
    result.m[1][0] = m[1][0] * right.m[0][0] + m[1][1] * right.m[1][0] + m[1][2] * right.m[2][0];
    result.m[1][1] = m[1][0] * right.m[0][1] + m[1][1] * right.m[1][1] + m[1][2] * right.m[2][1];
    result.m[1][2] = m[1][0] * right.m[0][2] + m[1][1] * right.m[1][2] + m[1][2] * right.m[2][2];
    result.m[2][0] = m[2][0] * right.m[0][0] + m[2][1] * right.m[1][0] + m[2][2] * right.m[2][0];
    result.m[2][1] = m[2][0] * right.m[0][1] + m[2][1] * right.m[1][1] + m[2][2] * right.m[2][1];
    result.m[2][2] = m[2][0] * right.m[0][2] + m[2][1] * right.m[1][2] + m[2][2] * right.m[2][2];
    return result;
}

__declspec(noinline) void RotTransform::FUN_00bae170(float angle)
{
    float cosine = (float)cos(angle / 57.29578f);
    float sine = (float)sin(angle / 57.29578f);
    RotTransform rotation;
    rotation.m[0][0] = 1.0f;
    rotation.m[0][1] = 0.0f;
    rotation.m[0][2] = 0.0f;
    rotation.m[1][0] = 0.0f;
    rotation.m[1][1] = cosine;
    rotation.m[1][2] = sine;
    rotation.m[2][0] = 0.0f;
    rotation.m[2][1] = -sine;
    rotation.m[2][2] = cosine;
    *this = rotation.FUN_00ba9610(*this);
}

class Vec3
{
public:
    float v[3];

    Vec3();
    Vec3(float a, float b, float c);

    Vec3 operator*(const RotTransform& t) const;
    Vec3 Rotate(const RotTransform& t) const;
    Vec3 RotateNormal(const RotTransform& t) const;
    Vec3 operator+(const Vec3& o) const;
    Vec3 operator*(float f) const;
    Vec3 Cross(const Vec3& o) const;
    void Normalize(); void NormalizeFromY();
    float Distance(const Vec3& o) const;
};

inline Vec3::Vec3()
{
    v[0] = v[1] = v[2] = 0.0f;
}

inline Vec3::Vec3(float a, float b, float c)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

inline Vec3 Vec3::operator*(const RotTransform& t) const
{
    return Vec3(v[0] * t.m[0][0] + v[1] * t.m[1][0] + v[2] * t.m[2][0],
                v[0] * t.m[0][1] + v[1] * t.m[1][1] + v[2] * t.m[2][1],
                v[0] * t.m[0][2] + v[1] * t.m[1][2] + v[2] * t.m[2][2]);
}
// pos1 uses the operand order of the matched New Vegas CVec3 * rotation (FNV 0x00b12890);
// the other three transforms (pos2, normal1, normal2) use the plain left-to-right operator*.
__forceinline Vec3 Vec3::Rotate(const RotTransform& t) const
{
    return Vec3(t.m[2][0] * v[2] + (t.m[1][0] * v[1] + t.m[0][0] * v[0]),
                t.m[2][1] * v[2] + (t.m[1][1] * v[1] + t.m[0][1] * v[0]),
                t.m[2][2] * v[2] + (t.m[1][2] * v[1] + t.m[0][2] * v[0]));
}

inline Vec3 Vec3::RotateNormal(const RotTransform& t) const
{
    const float (&row0)[3] = t.m[0];
    const float (&row1)[3] = t.m[1];
    return Vec3(v[0] * row0[0] + v[1] * row1[0] + v[2] * t.m[2][0],
                v[0] * row0[1] + v[1] * row1[1] + v[2] * t.m[2][1],
                v[0] * row0[2] + v[1] * row1[2] + v[2] * t.m[2][2]);
}

inline Vec3 Vec3::operator+(const Vec3& o) const
{
    return Vec3(v[0] + o.v[0], v[1] + o.v[1], v[2] + o.v[2]);
}

inline Vec3 Vec3::operator*(float f) const
{
    return Vec3(v[0] * f, v[1] * f, v[2] * f);
}

inline Vec3 Vec3::Cross(const Vec3& o) const
{
    return Vec3(v[1] * o.v[2] - v[2] * o.v[1], v[2] * o.v[0] - v[0] * o.v[2], v[0] * o.v[1] - v[1] * o.v[0]);
}

inline void Vec3::Normalize()
{
    float squaredLength = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    float inverseLength = 1.0f / (float)sqrt(squaredLength);
    v[0] *= inverseLength;
    v[1] *= inverseLength;
    v[2] *= inverseLength;
}
inline void Vec3::NormalizeFromY()
{
    // Local y breaks the commutative squared-sum tie to match target load order (x, y, z).
    float y = v[1];
    float squaredLength = v[0] * v[0] + y * y + v[2] * v[2];
    float inverseLength = 1.0f / (float)sqrt(squaredLength);
    v[0] *= inverseLength;
    v[1] *= inverseLength;
    v[2] *= inverseLength;
}


inline float Vec3::Distance(const Vec3& o) const
{
    return FastRoot((o.v[0] - v[0]) * (o.v[0] - v[0]) + (o.v[1] - v[1]) * (o.v[1] - v[1]) +
                    (o.v[2] - v[2]) * (o.v[2] - v[2]));
}

template<class T> class ProfileVector : public std::vector<T> {
public:
 typedef typename std::vector<T>::size_type size_type;
 // Checked profile access uses the same bounds contract as vector::operator[].
 static __forceinline const T& ReadChecked(const ProfileVector& self, size_type index) {
 if(self._Myfirst == 0 || index >= (size_type)(self._Mylast-self._Myfirst)) _invalid_parameter_noinfo();
 return self._Myfirst[index];
 }
};

struct GuidePoint
{
    Vec3 pos;
    RotTransform rotation;
    float scale;
    unsigned char material;
};

struct FrondSpine
{
    std::vector<GuidePoint> points;
    float u10;
    float width;
    unsigned char layer;
    float angle;
    float u20;
    float u24;
    unsigned int start;
    unsigned int stride;
    unsigned int FUN_00bb4600() const;
};

class MeshBuilder
{
public:
    int u00;
    int u04;
    unsigned char enabled;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    unsigned short u20;
    unsigned short count;

    unsigned short GetCount() const
    {
        return count;
    }
    bool IsEnabled() const
    {
        return enabled != 0;
    }
    void Advance()
    {
        ++count;
    }
    void SetCount(unsigned short n)
    {
        count = n;
    }
    void FUN_00bb09b0(const float* coord);
    void FUN_00bb0a70(const float* coord, unsigned short layer);
    void FUN_00bb0980(const float* color);
    void FUN_00bb0a40(const float* normal);
    void FUN_00bb0ce0(const float* tangent);
    void FUN_00bb0d30(const float* binormal);
    void FUN_00bb0c90(float scale, unsigned char material);
    const float* FUN_00baee70(unsigned int index);
    const float* FUN_00baeea0(unsigned int index);
};

class FrondEngine
{
public:
    MeshBuilder* mesh;
    void* lighting;

    void FUN_00bb8740(FrondSpine& spine, std::vector<Vec3>& profile, std::vector<Vec3>& profileNormals);
    void FUN_00bbad60(FrondSpine& spine);
};

// pdb: CFrondEngine::BuildExtrusionVertices | FrondEngine.obj | fnv360_0822_retail, call_gap, low
// pdb params: sGuide
void FrondEngine::FUN_00bbad60(FrondSpine& spine)
{
    if (mesh && lighting)
    {
        ProfileVector<Vec3> profile;
        std::vector<Vec3> profileNormals;
        FUN_00bb8740(spine, profile, profileNormals);

        spine.stride = profile.size();
        spine.start = mesh->GetCount();

        for (unsigned int i = 0; i < spine.points.size(); ++i)
        {
            float lengthPercent = (float)i / ((float)spine.points.size() - 1.0);
            for (unsigned int j = 0; j < spine.stride; ++j)
            {
                float widthPercent = (float)j / ((float)spine.stride - 1.0);

                RotTransform trans = spine.points[i].rotation;
                RotTransform previousTrans = i ? spine.points[i - 1].rotation : trans;
                trans.FUN_00bae170(spine.angle);
                previousTrans.FUN_00bae170(spine.angle);

                Vec3 pos1 = ProfileVector<Vec3>::ReadChecked(profile, j).Rotate(trans);
                Vec3 pos2 = profile[j] * previousTrans;
                Vec3 pos = spine.points[i].pos + (pos1 + pos2) * 0.5f;
                Vec3 tangent = pos1 + pos2;
                tangent.Normalize();

                mesh->FUN_00bb09b0(pos.v);
                float texCoords[2] = { widthPercent, lengthPercent };
                mesh->FUN_00bb0a70(texCoords, (unsigned short)spine.layer);

                Vec3 normal1 = profileNormals[j].RotateNormal(trans);
                Vec3 normal2 = profileNormals[j].RotateNormal(previousTrans);
                Vec3 normal = (normal1 + normal2) * 0.5f;
                normal.Normalize();

                float color[4];
                color[0] = color[1] = color[2] = color[3] = 1.0f;
                mesh->FUN_00bb0980(color);
                mesh->FUN_00bb0a40(normal.v);
                mesh->FUN_00bb0ce0(tangent.v);
                Vec3 binormal = normal.Cross(tangent);
                binormal.NormalizeFromY();
                mesh->FUN_00bb0d30(binormal.v);
                if (mesh->IsEnabled())
                    mesh->FUN_00bb0c90(spine.points[i].scale, spine.points[i].material);
                mesh->Advance();
            }
        }

        std::vector<float> lengths;
        std::vector<std::vector<float> > runningLengths;
        for (unsigned int i = 0; i < spine.stride; ++i)
        {
            float length = 0.0f;
            std::vector<float> running;
            running.push_back(0.0f);
            for (unsigned int j = 1; j < spine.points.size(); ++j)
            {
                int thisIndex = spine.start + j * spine.stride + i;
                int prevIndex = spine.start + (j - 1) * spine.stride + i;
                const float* thisCoord = mesh->FUN_00baee70(thisIndex);
                const float* prevCoord = mesh->FUN_00baee70(prevIndex);
                Vec3 current(thisCoord[0], thisCoord[1], thisCoord[2]);
                Vec3 previous(prevCoord[0], prevCoord[1], prevCoord[2]);
                length += current.Distance(previous);
                running.push_back(length);
            }
            runningLengths.push_back(running);
            lengths.push_back(length);
        }

        for (unsigned int i = 0; i < spine.stride; ++i)
        {
            for (unsigned int j = 1; j < spine.points.size(); ++j)
            {
                unsigned short thisIndex = spine.start + j * spine.stride + i;
                mesh->SetCount(thisIndex);
                const float* texCoord = mesh->FUN_00baeea0(thisIndex);
                float newTexCoord[2];
                newTexCoord[0] = texCoord[0];
                newTexCoord[1] = runningLengths[i][j] / lengths[i] * 0.999f;
                mesh->FUN_00bb0a70(newTexCoord, (unsigned short)spine.layer);
                mesh->Advance();
            }
        }
    }
}



}   // namespace f3m_00bbad60

// @f3 0x00bbbb70 (community match, verified in this file)
#include <memory>
namespace f3m_00bbbb70 {
// std::_Uninit_fill_n<Elem*, unsigned, Elem, Alloc>(first, count, val, alloc, _Nonscalar_ptr_iterator_tag) from the VS2005 <xmemory>
// (16-byte Elem, copy ctor 0x00bb9a30; Alloc::destroy is the out-of-line instance at 0x00bbad10). Fresh from the header form.

namespace f3m_00bbbb70 {

struct Elem {
    unsigned unk00, unk04, unk08, unk0c;
    Elem(const Elem&);
};

struct Alloc {
    void construct(Elem* p, const Elem& v) { std::_Construct(p, v); }
    void FUN_00bbad10(Elem* p);
};

void __cdecl FUN_00bbbb70(Elem* first, unsigned n, const Elem& value, Alloc& al)
{
    Elem* next = first;
    try {
        for (; n > 0; --n, ++first)
            al.construct(first, value);
    }
    catch (...) {
        for (; next != first; ++next)
            al.FUN_00bbad10(next);
        throw;
    }
}

}



}   // namespace f3m_00bbbb70

// @f3 0x00bb0490 (community match, verified in this file)
#include <memory>
namespace f3m_00bb0490 {
// std::_Uninit_fill_n<Elem*, unsigned, Elem, Alloc> from the VS2005 <xmemory> (16-byte Elem, copy ctor 0x00be0df0; Alloc::destroy instance 0x00bb6d80).

namespace f3m_00bb0490 {

struct Elem {
    unsigned unk00, unk04, unk08, unk0c;
    Elem(const Elem&);
};

struct Alloc {
    void construct(Elem* p, const Elem& v) { std::_Construct(p, v); }
    void FUN_00bb6d80(Elem* p);
};

void __cdecl FUN_00bb0490(Elem* first, unsigned n, const Elem& value, Alloc& al)
{
    Elem* next = first;
    try {
        for (; n > 0; --n, ++first)
            al.construct(first, value);
    }
    catch (...) {
        for (; next != first; ++next)
            al.FUN_00bb6d80(next);
        throw;
    }
}

}
}   // namespace f3m_00bb0490

// @f3 0x00bb6cd0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb6cd0 {
// std::_Uninit_fill_n<Elem*, unsigned, Elem, Alloc> from the VS2005 <xmemory> (16-byte Elem, copy ctor 0x00bb5c30; Alloc::destroy instance 0x00bb6d80).

namespace f3m_00bb6cd0 {

struct Elem {
    unsigned unk[4];
    Elem(const Elem&);

};

struct Alloc {
    void construct(Elem* p, const Elem& v) { std::_Construct(p, v); }
    void FUN_00bb6d80(Elem* p);
};

void __cdecl FUN_00bb6cd0(Elem* first, unsigned n, const Elem& value, Alloc& al)
{
    Elem* next = first;
    try {
        for (; n > 0; --n, ++first)
            al.construct(first, value);
    }
    catch (...) {
        for (; next != first; ++next)
            al.FUN_00bb6d80(next);
        throw;
    }
}

}

}   // namespace f3m_00bb6cd0

// @f3 0x00bb5ef0 (community match, verified in this file)
#include <memory>
namespace f3m_00bb5ef0 {
// std::_Uninit_copy<Elem*, Elem*, Alloc> from the VS2005 <xmemory> (44-byte Elem). Alloc::construct is the header's
// body (std::_Construct(p, v)), but the _Construct<Elem, Elem> instance is out of line here: declared as FUN_00bb5670.
// Alloc::destroy is the out-of-line instance FUN_00bb5640.

namespace f3m_00bb5ef0 {

struct Elem {
    unsigned unk[11];
};

void __cdecl FUN_00bb5670(Elem* p, const Elem& v);   // std::_Construct<Elem, Elem> instance (stand-in name)

struct Alloc {
    void construct(Elem* p, const Elem& v) { FUN_00bb5670(p, v); }
    void FUN_00bb5640(Elem* p);
};

Elem* __cdecl FUN_00bb5ef0(Elem* first, Elem* last, Elem* dest, Alloc& al)
{
    Elem* next = dest;
    try {
        for (; first != last; ++dest, ++first)
            al.construct(dest, *first);
    }
    catch (...) {
        for (; next != dest; ++next)
            al.FUN_00bb5640(next);
        throw;
    }
    return dest;
}

}
}   // namespace f3m_00bb5ef0

// @f3 0x00bb0540 (community match, verified in this file)
namespace f3m_00bb0540 {
// FUN_00bb0540 (223B, __cdecl, unit_423cda705058) — range move/copy over 16-byte vector elements
namespace f3m_00bb0540 {

extern "C" void __cdecl FUN_00401010(void* p);

struct Element {
    int alloc;                 // +0x0 (allocator slot, never touched)
    unsigned short* first;     // +0x4
    unsigned short* last;      // +0x8
    unsigned short* end;       // +0xc
    Element() : first(0), last(0), end(0) {}
    ~Element() { if (first) FUN_00401010(first); }
    Element(const Element& other);   // copy ctor — extern call, binds to 0x00bafbd0 by position
};

struct Alloc {
    void FUN_00bb6d80(Element* p);                 // destroy (binds to 0x00bb6d80)
};

struct NonscalarTag {};
struct RangeCheckedTag {};

inline void swap_ptr(unsigned short*& a, unsigned short*& b)
{
    unsigned short* t = a; a = b; b = t;
}

Element* __cdecl FUN_00bb0540(Element* first, Element* last, Element* dest, Alloc& al, NonscalarTag, RangeCheckedTag)
{
    Element* next = dest;
    Element temp;
    try {
        for (; first != last; ++dest, ++first) {
            void* p = dest;
            ::new (p) Element(temp);
            swap_ptr(dest->first, first->first);
            swap_ptr(dest->last, first->last);
            swap_ptr(dest->end, first->end);
        }
    } catch (...) {
        for (; next != dest; ++next)
            al.FUN_00bb6d80(next);
        throw;
    }
    return dest;
}

}
}   // namespace f3m_00bb0540

// @f3 0x00bbbc90 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bbbc90 {
namespace f3m_00bbbc90 {

struct Item {
    unsigned int unk00;
};

struct Inner {
    std::vector<Item> list;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};

typedef std::vector<Inner> Outer;

struct Alloc : std::allocator<Outer> {
    void FUN_00bbad10(Outer* p);
};

Outer* __cdecl FUN_00bbbc90(Outer* first, Outer* last, Outer* dest, Alloc& al,
                            std::_Swap_move_tag, std::_Range_checked_iterator_tag)
{
    Outer* next = dest;
    Outer val;
    try {
        for (; first != last; ++dest, ++first) {
            al.construct(dest, val);
            std::swap(*dest, *first);
        }
    } catch (...) {
        for (; next != dest; ++next)
            al.FUN_00bbad10(next);
        throw;
    }
    return dest;
}

}
}   // namespace f3m_00bbbc90

// @f3 0x00ba4f80 (community match, verified in this file)
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <exception>

namespace b1713 {

struct STHeap { void* FUN_0086b930(unsigned int size); void FUN_0086ba60(void*); };
extern STHeap DAT_01090a78;

struct STText {
    unsigned char allocator;
    union { char buffer[16]; char* heap; };
    unsigned size;
    unsigned capacity;
    void FUN_0042f100(const char* p, unsigned len);
    void Assign(const char* p) { FUN_0042f100(p, (unsigned)strlen(p)); }
    const char* c_str() const { return capacity >= 16 ? heap : buffer; }
    STText(const char* p) { capacity = 15; size = 0; buffer[0] = 0; Assign(p); }
    ~STText() { if (capacity >= 16) DAT_01090a78.FUN_0086ba60(heap); }
};

static __declspec(noinline) STText FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return STText(text);
}

void FUN_00ba3d50(const char* p);
}
inline void* operator new[](size_t size, b1713::STHeap& heap) { return heap.FUN_0086b930(size); }
namespace b1713 {

struct CSpeedTreeEngine {
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
    unsigned short m_nNumLeafLodLevels;
};

class CSpeedTreeRT {
public:
    CSpeedTreeEngine* m_pEngine;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float m_fLeafLodSizeScale;
    int unk28;
    float* m_pLeafLodSizeAdjustments;

    const float* FUN_00ba4f80();
};

const float* CSpeedTreeRT::FUN_00ba4f80()
{
    try {
        if (m_pLeafLodSizeAdjustments == 0) {
            int nNumLevels = m_pEngine->m_nNumLeafLodLevels;
            m_pLeafLodSizeAdjustments = new(DAT_01090a78) float[nNumLevels];
            for (int i = 0; i < nNumLevels; ++i) {
                m_pLeafLodSizeAdjustments[i] = nNumLevels > 0 ? m_fLeafLodSizeScale * i + 1.0f : 1.0f;
            }
        }
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::GetLeafLodSizeAdjustments", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::GetLeafLodSizeAdjustments").c_str());
    }
    return m_pLeafLodSizeAdjustments;
}

}

// @f3 0x00bab620 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bab620 {
namespace f3m_00bab620 {

struct Elem { int a; int b; int c; };

struct Vec : std::vector<Elem> {
    void FUN_00bab620(iterator _Where, size_type _Count, const Elem& _Val);
};

void Vec::FUN_00bab620(iterator _Where, size_type _Count, const Elem& _Val)
{
    Elem _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Tmp);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}
}   // namespace f3m_00bab620

// @f3 0x00bb5950 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bb5950 {
namespace f3m_00bb5950 {

struct Elem { unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34; };

struct Vec : std::vector<Elem> {
    void FUN_00bb5950(iterator _Where, size_type _Count, const Elem& _Val);
};

void Vec::FUN_00bb5950(iterator _Where, size_type _Count, const Elem& _Val)
{
    Elem _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Tmp);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}
}   // namespace f3m_00bb5950

// @f3 0x00bba4e0 (community match, verified in this file)
#include <vector>
#include <memory>
namespace f3m_00bba4e0 {
namespace f3m_00bba4e0 {

struct Item { unsigned int unk00; unsigned int unk04; };
struct Elem {
    std::vector<Item> list;
    float x, y;
    bool flag;
    float z, w, v;
    int first, last;
};

struct Vec : std::vector<Elem> {
    void FUN_00bba4e0(iterator _Where, size_type _Count, const Elem& _Val);
};

void Vec::FUN_00bba4e0(iterator _Where, size_type _Count, const Elem& _Val)
{
    Elem _Tmp = _Val;
    size_type _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity
            ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;

        try {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Tmp);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
        } catch (...) {
            _Destroy(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        } catch (...) {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        std::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        stdext::_Unchecked_move_backward(_Where._Myptr, _Oldend - _Count, _Oldend);
        std::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}
}   // namespace f3m_00bba4e0

// @f3 0x00bb01a0 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb01a0 {
namespace f3m_00bb01a0 {

struct Item { unsigned int unk00; unsigned int unk04; unsigned int unk08; };
typedef std::vector<Item> Elem;

Elem* __cdecl FUN_00bb01a0(Elem* _First, Elem* _Last, Elem* _Dest, std::allocator<Elem>& _Al,
                          std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _Dest;
    try {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.construct(_Dest, *_First);
    } catch (...) {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

}
}   // namespace f3m_00bb01a0

// @f3 0x00bb03e0 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb03e0 {
namespace f3m_00bb03e0 {

struct Item { unsigned int unk00; unsigned int unk04; unsigned int unk08; };
typedef std::vector<Item> Elem;

void __cdecl FUN_00bb03e0(Elem* _First, unsigned int _Count, const Elem& _Val, std::allocator<Elem>& _Al,
                          std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _First;
    try {
        for (; 0 < _Count; --_Count, ++_First)
            _Al.construct(_First, _Val);
    } catch (...) {
        for (; _Next != _First; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
}

}
}   // namespace f3m_00bb03e0

// @f3 0x00bb0620 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb0620 {
namespace f3m_00bb0620 {

typedef std::vector<unsigned short> Elem;

Elem* __cdecl FUN_00bb0620(Elem* _First, Elem* _Last, Elem* _Dest, std::allocator<Elem>& _Al,
                          std::_Swap_move_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _Dest;
    Elem _Val;
    try {
        for (; _First != _Last; ++_Dest, ++_First) {
            _Al.construct(_Dest, _Val);
            std::swap(*_Dest, *_First);
        }
    } catch (...) {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

}
}   // namespace f3m_00bb0620

// @f3 0x00bb6350 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb6350 {
namespace f3m_00bb6350 {

struct Elem {
    std::string name;
    float unk1C, unk20, unk24, unk28;
};

void __cdecl FUN_00bb6350(Elem* _First, unsigned int _Count, const Elem& _Val, std::allocator<Elem>& _Al,
                          std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _First;
    try {
        for (; 0 < _Count; --_Count, ++_First)
            _Al.construct(_First, _Val);
    } catch (...) {
        for (; _Next != _First; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
}

}
}   // namespace f3m_00bb6350

// @f3 0x00bb7020 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb7020 {
namespace f3m_00bb7020 {

struct Item { unsigned int unk00; unsigned int unk04; };
struct Elem {
    std::vector<Item> list;
    float x, y;
    bool flag;
    float z, w, v;
    int first, last;
};

Elem* __cdecl FUN_00bb7020(Elem* _First, Elem* _Last, Elem* _Dest, std::allocator<Elem>& _Al,
                          std::_Undefined_move_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _Dest;
    try {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.construct(_Dest, *_First);
    } catch (...) {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

}
}   // namespace f3m_00bb7020

// @f3 0x00bb8ec0 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bb8ec0 {
namespace f3m_00bb8ec0 {

struct Item { unsigned int unk00; unsigned int unk04; };
struct Elem {
    std::vector<Item> list;
    float x, y;
    bool flag;
    float z, w, v;
    int first, last;
};

void __cdecl FUN_00bb8ec0(Elem* _First, unsigned int _Count, const Elem& _Val, std::allocator<Elem>& _Al,
                          std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _First;
    try {
        for (; 0 < _Count; --_Count, ++_First)
            _Al.construct(_First, _Val);
    } catch (...) {
        for (; _Next != _First; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
}

}
}   // namespace f3m_00bb8ec0

// @f3 0x00bbefe0 (community match, verified in this file)
#include <vector>
#include <string>
#include <memory>
namespace f3m_00bbefe0 {
namespace f3m_00bbefe0 {

struct Point { float x, y, z; };
struct Elem {
    char kind;
    Point p04;
    float f10;
    std::string name;
    Point p30, p3c, p48;
};

Elem* __cdecl FUN_00bbefe0(Elem* _First, Elem* _Last, Elem* _Dest, std::allocator<Elem>& _Al,
                          std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag)
{
    Elem* _Next = _Dest;
    try {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.construct(_Dest, *_First);
    } catch (...) {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

}
}   // namespace f3m_00bbefe0

// @f3 0x00ba5fb0 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba5fb0 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

extern String DAT_01068a70;

inline void FUN_00ba3d50(const char* error)
{
    DAT_01068a70 = error;
}

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct TreeData {
    char unk00[0x21];
    bool transientDataOk;
    char unk22[0x26];
    int treeSize;
    char unk4c[0x10];
    void* unk5c;
    char unk60[0x5c];
    int leafRockingGroups;
};

struct IndexedGeometry {
    char unk00[8];
    bool manualWind;
    bool staticLighting;
    char unk0a[8];
    bool vertexWeighting;
    char unk13;
    int windMethod;
};

struct LeafGeometry {
    bool staticLighting;
    bool manualWind;
    char unk02[2];
};

struct LightingInfo {
    int branchMethod;
    char unk04[0x34];
    int leafMethod;
    char unk3c[0x3c];
    int frondMethod;
};

struct WindInfo {
    char unk00[8];
    int branchMethod;
    int frondMethod;
    int leafMethod;
};

struct CSpeedTreeRT {
    TreeData* treeData;
    IndexedGeometry* branchGeometry;
    LeafGeometry* leafGeometry;
    LightingInfo* lightingInfo;
    WindInfo* windInfo;
    char unk14[0x1c];
    int* instanceRefCount;
    CSpeedTreeRT* instanceOf;
    char unk38[0xd];
    bool computed;
    char unk46[0x1a];
    IndexedGeometry* frondGeometry;
    char unk64[0x3c];
    void FUN_00ba5fb0(int method);
};

// pdb: CSpeedTreeRT::SetFrondLightingMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba5fb0(int method)
{
    try {
        if (!computed) {
            frondGeometry->staticLighting = (method == 1);
            lightingInfo->frondMethod = method;
        } else
            FUN_00ba3d50("SetFrondLightingMethod() has no effect after Compute() has been called");
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetFrondLightingMethod", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetFrondLightingMethod").c_str());
    }
}
}

// @f3 0x00bb15b0 (community match, verified in this file)
#include <vector>
#include <stdexcept>
namespace f3m_00bb15b0 {

namespace f3m_00bb15b0 {
typedef ::f3m_00bb03e0::f3m_00bb03e0::Elem Elem;
Elem* __cdecl FUN_00baec30(unsigned count, Elem*);

struct VectorE16a {
    std::allocator<Elem> _Alval;
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;

    unsigned max_size() const { return 0x0fffffff; }

    void FUN_00bb15b0(unsigned _Count, const Elem& _Val);   // _Construct_n

    bool _Buy(unsigned _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return (false);
        else if (max_size() < _Capacity)
            ::f3m_00bb19c0::NativeInsert650::FUN_00bc5f00();
        else
        {
            _Myfirst = FUN_00baec30(_Capacity, (Elem*)0);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return (true);
    }

    Elem* _Ufill(Elem* _Ptr, unsigned _Count, const Elem& _Val)
    {
        f3m_00bb03e0::f3m_00bb03e0::FUN_00bb03e0(_Ptr, _Count, _Val, this->_Alval,
                     std::_Ptr_cat(_Ptr, _Ptr), std::_Range_checked_iterator_tag());
        return (_Ptr + _Count);
    }

    void FUN_00bafed0();                                                               // _Tidy
};

void VectorE16a::FUN_00bb15b0(unsigned _Count, const Elem& _Val)
{
    if (_Buy(_Count))
    {
        try {
            _Mylast = _Ufill(_Myfirst, _Count, _Val);
        }
        catch (...) {
            FUN_00bafed0();
            throw;
        }
    }
}

}
}   // namespace f3m_00bb15b0

// @f3 0x00ba7fd0 (community match, verified in this file)
#include <exception>
namespace f3m_00ba7fd0 {

// The complete catch structure follows the shared SetTime handoff.
// Reuse the formatter, error sink and notification function already in this unit.
namespace f3m_00ba7fd0 {
// pdb: CSpeedTreeRT::SetTime | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: fTime
void FUN_00ba7fd0(float time)
{
    using namespace sol7d10;
    try {
        ::DAT_01178304 = time;
        FUN_00ba6f70(false);
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetTime", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetTime").c_str());
    }
}
}
}   // namespace f3m_00ba7fd0

// @f3 0x00ba6d10 (community match, verified in this file)
#include <exception>
namespace f3m_00ba6d10 {

// The shared draft identified the two catch paths. The issued file supplies
// the SpeedTree formatter and error sink. The table accessor returns a float array.
namespace f3m_00ba6d10 {
struct LeafGeometry {
    const float* FUN_00bb2ce0(int* entryCount);
};

struct CSpeedTreeRT {
    void* engine;
    void* branchGeometry;
    LeafGeometry* leafGeometry;
    const float* FUN_00ba6d10(int* entryCount);
};

// pdb: CSpeedTreeRT::GetLeafBillboardTable | SpeedTreeRT.obj | fnv360_0822_retail, call_seq, medium
// pdb params: nEntryCount
const float* CSpeedTreeRT::FUN_00ba6d10(int* entryCount)
{
    using namespace sol7d10;
    const float* billboardTable = 0;
    try {
        billboardTable = leafGeometry->FUN_00bb2ce0(entryCount);
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::GetLeafBillboardTable", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::GetLeafBillboardTable").c_str());
    }
    return billboardTable;
}
}
}   // namespace f3m_00ba6d10

// @f3 0x00ba5c50 (community match, verified in this file)
#include <exception>
namespace f3m_00ba5c50 {

namespace f3m_00ba5c50 {
// The packet's previous partial reconstruction identified these two fields.
struct TreeData {
    char fieldsBeforeTransientData[0x21];
    bool hasTransientData;
    char remainingFields[0x48 - 0x22];
    unsigned int value;
};

struct Tree {
    TreeData* data;
    unsigned int CSpeedTreeRT_GetSeed() const;
};

// pdb: CSpeedTreeRT::GetSeed | SpeedTreeRT.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|ustr_rel), high
unsigned int Tree::CSpeedTreeRT_GetSeed() const {
    using namespace sol7d10;
    unsigned int result = 0;
    try {
        if (data->hasTransientData) {
            result = data->value;
        } else {
            static const char message[] = "SetTreeSize() has no effect after DeleteTransientData() has been called";
            sol7d10::DAT_01068a70.FUN_0042f100(message, sizeof(message) - 1);
        }
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetTreeSize", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetTreeSize").c_str());
    }
    return result;
}
}
}   // namespace f3m_00ba5c50

// @f3 0x00ba5d50 (community match, verified in this file)
#include <exception>
namespace f3m_00ba5d50 {

// The branch fields follow the shared short-span draft. Use the SpeedTree
// error string and the exception helpers supplied by this translation unit.
namespace f3m_00ba5d50 {
struct BranchGeometry {
    char reserved[9];
    bool staticLighting;
};
struct BranchLighting {
    int method;
};
struct CSpeedTreeRT {
    void* treeEngine;
    BranchGeometry* branchGeometry;
    void* leafGeometry;
    BranchLighting* lightingEngine;
    char reserved[0x35];
    bool computed;

    void FUN_00ba5d50(int method);
};

// pdb: CSpeedTreeRT::SetBranchLightingMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba5d50(int method)
{
    using namespace sol7d10;
    try {
        if (!computed) {
            branchGeometry->staticLighting = (method == 1);
            lightingEngine->method = method;
        } else {
            f3m_00ba60e0::DAT_01068a70 = "SetBranchLightingMethod() has no effect after Compute() has been called";
        }
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetBranchLightingMethod", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetBranchLightingMethod").c_str());
    }
}
}
}   // namespace f3m_00ba5d50

// @f3 0x00ba5e80 (community match, verified in this file)
#include <exception>
namespace f3m_00ba5e80 {

namespace f3m_00ba5e80 {
// The handoff established the two branches. Use the published SpeedTree
// owner/geometry fields and the formatter and error sink from this unit.
struct CSpeedTreeRT {
    enum ELightingMethod { LIGHT_DYNAMIC, LIGHT_STATIC };
    struct CLightingEngine {
        char beforeMethod[0x38];
        ELightingMethod leafMethod;
    };
    struct CLeafGeometry {
        bool staticLighting;
    };

    char beforeLeafGeometry[8];
    CLeafGeometry* m_pLeafGeometry;
    CLightingEngine* m_pLightingEngine;
    char beforeComputed[0x45 - 0x10];
    bool m_bTreeComputed;
    void FUN_00ba5e80(ELightingMethod method);
};

// pdb: CSpeedTreeRT::SetLeafLightingMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba5e80(ELightingMethod method) {
    using namespace sol7d10;
    try {
        if (!m_bTreeComputed) {
            m_pLightingEngine->leafMethod = method;
            m_pLeafGeometry->staticLighting = (method == LIGHT_STATIC);
        } else {
            static const char message[] = "SetLeafLightingMethod() has no effect after Compute() has been called";
            sol7d10::DAT_01068a70.FUN_0042f100(message, sizeof(message) - 1);
        }
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetLeafLightingMethod", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafLightingMethod").c_str());
    }
}
}
}   // namespace f3m_00ba5e80

// @f3 0x00ba88b0 (community match, verified in this file)
#include <exception>
extern const char DAT_00ea7a8c[];
namespace f3m_00ba88b0 {


namespace f3m_00ba88b0 {
struct CSpeedTreeRT : W474Tree {
    CSpeedTreeRT(CSpeedTreeRT*);
    static void* operator new(unsigned size) {
        return b1713::DAT_01090a78.FUN_0086b930(size);
    }
    static void operator delete(void* memory) {
        b1713::DAT_01090a78.FUN_0086ba60(memory);
    }
    CSpeedTreeRT* FUN_00ba88b0();
};

// pdb: CSpeedTreeRT::MakeInstance | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
CSpeedTreeRT* CSpeedTreeRT::FUN_00ba88b0()
{
    CSpeedTreeRT* instance = 0;
    try {
        instance = new CSpeedTreeRT(this);
    } catch (std::exception& error) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea7220, DAT_00ea7a8c, error.what()).c_str());
    } catch (...) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea71f8, DAT_00ea7a8c).c_str());
    }
    return instance;
}
}
}   // namespace f3m_00ba88b0

// @f3 0x00ba6be0 (community match, verified in this file)
#include <exception>
extern const char DAT_00ea78b8[];
namespace f3m_00ba6be0 {

namespace f3m_00ba6be0 {
struct ResourceView {
    int state00, state04, state08, state0c, state10, state14, state18, state1c, state20;
    int state24, state28, state2c, state30, state34, state38, state3c, state40, state44;
    int state48, state4c, state50, state54, state58;
    F_BA7530::SubA* branchGeometry;
};
struct Tree {
    ResourceView* resource;
    F_BA7530::SubA* branchGeometry;
    int other08, other0c, other10, other14, other18, other1c, other20, other24, other28, other2c;
    int* referenceCount;
    void* instanceData;
    int other38, other3c, other40;
    char other44;
    bool ownsGeometry;
    void FUN_00ba6be0();
};

// pdb: CSpeedTreeRT::DeleteBranchGeometry | SpeedTreeRT.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void Tree::FUN_00ba6be0() {
    try {
        if (ownsGeometry && branchGeometry && !instanceData && *referenceCount == 1) {
            delete branchGeometry;
            branchGeometry = 0;
            if (resource)
                resource->branchGeometry = 0;
        }
    } catch (std::exception& error) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea7220, DAT_00ea78b8, error.what()).c_str());
        return;
    } catch (...) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea71f8, DAT_00ea78b8).c_str());
        return;
    }
}
}
}   // namespace f3m_00ba6be0

// @f3 0x00ba46f0 (community match, verified in this file)
#include <exception>
namespace f3m_00ba46f0 {

// The shared draft identified the ownership tests. Reuse the supplied
// geometry destructor and allocator and restore the two native error paths.
namespace f3m_00ba46f0 {
typedef F_BA7530::SubA FrondGeometry;
struct CSpeedTreeRT {
    char reserved00[0x30];
    int* referenceCount;
    void* instance;
    char reserved38[0x0d];
    bool computed;
    char reserved46[0x1a];
    FrondGeometry* frondGeometry;

    void FUN_00ba46f0();
};

// pdb: CSpeedTreeRT::DeleteFrondGeometry | SpeedTreeRT.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
void CSpeedTreeRT::FUN_00ba46f0()
{
    using namespace sol7d10;
    try {
        if (computed && frondGeometry && !instance && referenceCount && *referenceCount == 1) {
            delete frondGeometry;
            frondGeometry = 0;
        }
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::DeleteFrondGeometry", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::DeleteFrondGeometry").c_str());
    }
}
}
}   // namespace f3m_00ba46f0

// @f3 0x00ba63b0 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba63b0 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

extern String DAT_01068a70;

inline void FUN_00ba3d50(const char* error)
{
    DAT_01068a70 = error;
}

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct TreeData {
    char unk00[0x21];
    bool transientDataOk;
    char unk22[0x26];
    int treeSize;
    char unk4c[0x10];
    void* unk5c;
    char unk60[0x5c];
    int leafRockingGroups;
};

struct IndexedGeometry {
    char unk00[8];
    bool manualWind;
    bool staticLighting;
    char unk0a[8];
    bool vertexWeighting;
    char unk13;
    int windMethod;
    void FUN_00baf220(bool enable);
    void SetVertexWeighting(bool enable) { vertexWeighting = enable; }
    void SetManualWind(bool enable) { manualWind = enable; }
    void SetWindMethod(int method) { windMethod = method; }
};

struct LeafGeometry {
    bool staticLighting;
    bool manualWind;
    char unk02[2];
};

struct LightingInfo {
    int branchMethod;
    char unk04[0x34];
    int leafMethod;
    char unk3c[0x3c];
    int frondMethod;
};

struct WindInfo {
    char unk00[8];
    int branchMethod;
    int frondMethod;
    int leafMethod;
};

struct CSpeedTreeRT {
    TreeData* treeData;
    IndexedGeometry* branchGeometry;
    LeafGeometry* leafGeometry;
    LightingInfo* lightingInfo;
    WindInfo* windInfo;
    char unk14[0x1c];
    int* instanceRefCount;
    CSpeedTreeRT* instanceOf;
    char unk38[0xd];
    bool computed;
    char unk46[0x1a];
    IndexedGeometry* frondGeometry;
    char unk64[0x3c];
    void FUN_00ba63b0(int method);
};

// pdb: CSpeedTreeRT::SetBranchWindMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba63b0(int method)
{
    try {
        if (!computed) {
            if (method == 2 && windInfo->branchMethod == 1) {
                branchGeometry->SetVertexWeighting(false);
                branchGeometry->FUN_00baf220(false);
            }
            windInfo->branchMethod = method;
            branchGeometry->SetManualWind(method != 2);
            branchGeometry->SetWindMethod(method);
        } else
            FUN_00ba3d50("SetBranchWindMethod() has no effect after Compute() has been called");
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetBranchWindMethod", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetBranchWindMethod").c_str());
    }
}
}

// @f3 0x00ba6500 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba6500 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

extern String DAT_01068a70;

inline void FUN_00ba3d50(const char* error)
{
    DAT_01068a70 = error;
}

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct TreeData {
    char unk00[0x21];
    bool transientDataOk;
    char unk22[0x26];
    int treeSize;
    char unk4c[0x10];
    void* unk5c;
    char unk60[0x5c];
    int leafRockingGroups;
};

struct IndexedGeometry {
    char unk00[8];
    bool manualWind;
    bool staticLighting;
    char unk0a[8];
    bool vertexWeighting;
    char unk13;
    int windMethod;
    void FUN_00baf220(bool enable);
    void SetVertexWeighting(bool enable) { vertexWeighting = enable; }
    void SetManualWind(bool enable) { manualWind = enable; }
    void SetWindMethod(int method) { windMethod = method; }
};

struct LeafGeometry {
    bool staticLighting;
    bool manualWind;
    char unk02[2];
};

struct LightingInfo {
    int branchMethod;
    char unk04[0x34];
    int leafMethod;
    char unk3c[0x3c];
    int frondMethod;
};

struct WindInfo {
    char unk00[8];
    int branchMethod;
    int frondMethod;
    int leafMethod;
};

struct CSpeedTreeRT {
    TreeData* treeData;
    IndexedGeometry* branchGeometry;
    LeafGeometry* leafGeometry;
    LightingInfo* lightingInfo;
    WindInfo* windInfo;
    char unk14[0x1c];
    int* instanceRefCount;
    CSpeedTreeRT* instanceOf;
    char unk38[0xd];
    bool computed;
    char unk46[0x1a];
    IndexedGeometry* frondGeometry;
    char unk64[0x3c];
    void FUN_00ba6500(int method);
};

// pdb: CSpeedTreeRT::SetFrondWindMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba6500(int method)
{
    try {
        if (!computed) {
            if (method == 2 && windInfo->frondMethod == 1) {
                frondGeometry->SetVertexWeighting(false);
                frondGeometry->FUN_00baf220(false);
            }
            windInfo->frondMethod = method;
            frondGeometry->SetManualWind(method != 2);
            frondGeometry->SetWindMethod(method);
        } else
            FUN_00ba3d50("SetFrondWindMethod() has no effect after Compute() has been called");
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetFrondWindMethod", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetFrondWindMethod").c_str());
    }
}
}

// @f3 0x00ba67f0 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba67f0 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

void FUN_00ba3d50(const char* error);

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct WindMatrices { unsigned short count; void FUN_00ba1ad0(int count); };
extern WindMatrices DAT_01178308;

struct CSpeedTreeRT { static void FUN_00ba67f0(int count); };

void CSpeedTreeRT::FUN_00ba67f0(int count)
{
    try {
        DAT_01178308.FUN_00ba1ad0(count);
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetNumWindMatrices", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetNumWindMatrices").c_str());
    }
}
}

// @f3 0x00ba6150 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba6150 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

extern String DAT_01068a70;

inline void FUN_00ba3d50(const char* error)
{
    DAT_01068a70 = error;
}

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct TreeData {
    char unk00[0x21];
    bool transientDataOk;
    char unk22[0x26];
    int treeSize;
    char unk4c[0x10];
    void* unk5c;
    char unk60[0x5c];
    int leafRockingGroups;
};

struct IndexedGeometry {
    char unk00[8];
    bool manualWind;
    bool staticLighting;
    char unk0a[8];
    bool vertexWeighting;
    char unk13;
    int windMethod;
};

struct LeafGeometry {
    bool staticLighting;
    bool manualWind;
    char unk02[2];
};

struct LightingInfo {
    int branchMethod;
    char unk04[0x34];
    int leafMethod;
    char unk3c[0x3c];
    int frondMethod;
};

struct WindInfo {
    char unk00[8];
    int branchMethod;
    int frondMethod;
    int leafMethod;
};

struct CSpeedTreeRT {
    TreeData* treeData;
    IndexedGeometry* branchGeometry;
    LeafGeometry* leafGeometry;
    LightingInfo* lightingInfo;
    WindInfo* windInfo;
    char unk14[0x1c];
    int* instanceRefCount;
    CSpeedTreeRT* instanceOf;
    char unk38[0xd];
    bool computed;
    char unk46[0x1a];
    IndexedGeometry* frondGeometry;
    char unk64[0x3c];
    void FUN_00ba6150(int groups);
};

// pdb: CSpeedTreeRT::SetNumLeafRockingGroups | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: nRockingGroups
void CSpeedTreeRT::FUN_00ba6150(int groups)
{
    try {
        if (!computed) {
            if (groups == 0)
                groups = 1;
            treeData->leafRockingGroups = groups;
        } else
            FUN_00ba3d50("SetNumLeafRockingGroups() has no effect after Compute() has been called");
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetLeafRockingState", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafRockingState").c_str());
    }
}
}

// @f3 0x00ba6280 (community match, verified in this file)
#include <string>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3p_00ba6280 {

// The game's allocator: its heap (the definitions are the game's).
template<class T> class HeapAllocator : public std::allocator<T> {
public:
    template<class U> struct rebind { typedef HeapAllocator<U> other; };
    HeapAllocator() { }
    HeapAllocator(const HeapAllocator&) { }
    template<class U> HeapAllocator(const HeapAllocator<U>&) { }
    T* allocate(size_t count);
    void deallocate(T* memory, size_t count);
};

typedef std::basic_string<char, std::char_traits<char>, HeapAllocator<char> > String;

extern String DAT_01068a70;

inline void FUN_00ba3d50(const char* error)
{
    DAT_01068a70 = error;
}

static __declspec(noinline) String FUN_00bb56f0(const char* format, ...)
{
    char text[1024];
    va_list args;
    va_start(args, format);
    vsprintf(text, format, args);
    return String(text);
}

struct TreeData {
    char unk00[0x21];
    bool transientDataOk;
    char unk22[0x26];
    int treeSize;
    char unk4c[0x10];
    void* unk5c;
    char unk60[0x5c];
    int leafRockingGroups;
};

struct IndexedGeometry {
    char unk00[8];
    bool manualWind;
    bool staticLighting;
    char unk0a[8];
    bool vertexWeighting;
    char unk13;
    int windMethod;
};

struct LeafGeometry {
    bool staticLighting;
    bool manualWind;
    char unk02[2];
};

struct LightingInfo {
    int branchMethod;
    char unk04[0x34];
    int leafMethod;
    char unk3c[0x3c];
    int frondMethod;
};

struct WindInfo {
    char unk00[8];
    int branchMethod;
    int frondMethod;
    int leafMethod;
};

struct CSpeedTreeRT {
    TreeData* treeData;
    IndexedGeometry* branchGeometry;
    LeafGeometry* leafGeometry;
    LightingInfo* lightingInfo;
    WindInfo* windInfo;
    char unk14[0x1c];
    int* instanceRefCount;
    CSpeedTreeRT* instanceOf;
    char unk38[0xd];
    bool computed;
    char unk46[0x1a];
    IndexedGeometry* frondGeometry;
    char unk64[0x3c];
    void FUN_00ba6280(int method);
};

// pdb: CSpeedTreeRT::SetLeafWindMethod | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: eMethod
void CSpeedTreeRT::FUN_00ba6280(int method)
{
    try {
        if (!computed) {
            windInfo->leafMethod = method;
            leafGeometry->manualWind = (method != 2);
        } else
            FUN_00ba3d50("SetLeafWindMethod() has no effect after Compute() has been called");
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetLeafWindMethod", e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafWindMethod").c_str());
    }
}
}

// @f3 0x00ba6a30 (community match, verified in this file)
#include <exception>
extern const char DAT_00ea785c[];
namespace f3m_00ba6a30 {

namespace f3m_00ba6a30 {
struct Position { float x, y, z; };
struct Engine {
    int state00;
    Position position;
    float state10;
    float level;
    float FUN_00bbda60();
};
struct Instance {
    int state00;
    Position position;
    float level;
};
struct Tree {
    Engine* engine;
    int state04, state08, state0c, state10, state14, state18, state1c, state20, state24, state28, state2c, state30;
    Instance* instance;
    void CSpeedTreeRT_ComputeLodLevel();
};
// pdb: CSpeedTreeRT::ComputeLodLevel | SpeedTreeRT.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Tree::CSpeedTreeRT_ComputeLodLevel() {
    try {
        if (instance) {
            Position savedPosition = engine->position;
            float savedLevel = engine->level;
            engine->position = instance->position;
            instance->level = engine->FUN_00bbda60();
            engine->level = savedLevel;
            engine->position = savedPosition;
        } else {
            engine->FUN_00bbda60();
        }
    } catch (std::exception& error) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea7220, DAT_00ea785c, error.what()).c_str());
    } catch (...) {
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(
            DAT_00ea71f8, DAT_00ea785c).c_str());
    }
}
}
}   // namespace f3m_00ba6a30

// @f3 0x00bb9a30 (community match, verified in this file)
#include <memory>
namespace f3m_00bb9a30 {
void __cdecl FUN_00c01e8b();
__declspec(noreturn) void __cdecl FUN_00bc5f00();
namespace f3m_00bb9a30 {
struct Elem48 { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; ~Elem48(); };

struct Alloc9a30 { int unused; };
Elem48* __cdecl FUN_00bb4760(unsigned int count, unsigned int base);
struct FUN_00bb9a30 {
    Alloc9a30 alloc;
    Elem48* first;
    Elem48* last;
    Elem48* end;
    FUN_00bb9a30(const FUN_00bb9a30& right);
    void FUN_00bb9900();
};
Elem48* __cdecl FUN_00bb7020(Elem48* f, Elem48* l, Elem48* dest, Alloc9a30& a, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
FUN_00bb9a30::FUN_00bb9a30(const FUN_00bb9a30& right)
{
    unsigned int count = right.first == 0 ? 0 : (unsigned int)(right.last - right.first);
    first = 0;
    last = 0;
    end = 0;
    if (count != 0) {
        if (count > 0x5555555)
            FUN_00bc5f00();
        Elem48* p = FUN_00bb4760(count, 0);
        first = p;
        last = p;
        end = p + count;
        try {
            Elem48* e = right.last;
            if (right.first > e)
                FUN_00c01e8b();
            Elem48* b = right.first;
            if (b > right.last)
                FUN_00c01e8b();
            Elem48* d = first;
            last = FUN_00bb7020(b, e, d, alloc, std::_Ptr_cat(b, d), std::_Range_checked_iterator_tag());
        } catch (...) {
            FUN_00bb9900();
            throw;
        }
    }
}
}
}   // namespace f3m_00bb9a30

// @f3 0x00ba68f0 (community match, verified in this file)
#include <exception>
extern unsigned short DAT_01178308;
namespace f3m_00ba68f0 {

namespace f3m_00ba68f0 {
// Earlier handoffs identified the two wind-matrix arguments and unsigned bound.
// Use the real wind engine interface and the same-file shared error functions.
// SpeedTree's public owner points to its separately compiled wind engine.
struct CWindEngine {
    void FUN_00bae3b0(unsigned int startingMatrix, unsigned int matrixSpan);
};

struct CSpeedTreeRT {
    char beforeWindEngine[0x10];
    CWindEngine* m_pWindEngine;
    char beforeComputed[0x45 - 0x14];
    bool m_bTreeComputed;

    void FUN_00ba68f0(unsigned int startingMatrix, unsigned int matrixSpan);
};

// pdb: CSpeedTreeRT::SetLocalMatrices | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: nStartingMatrix, nMatrixSpan
void CSpeedTreeRT::FUN_00ba68f0(unsigned int startingMatrix, unsigned int matrixSpan) {
    using namespace sol7d10;
    try {
        if (!m_bTreeComputed) {
            if (startingMatrix + matrixSpan - 1 < DAT_01178308) {
                m_pWindEngine->FUN_00bae3b0(startingMatrix, matrixSpan);
            } else {
                static const char message[] = "SetLocalMatrices() parameters exceed available wind matrices";
                sol7d10::DAT_01068a70.FUN_0042f100(message, sizeof(message) - 1);
            }
        } else {
            static const char message[] = "SetLocalMatrices() has no effect after Compute() has been called";
            sol7d10::DAT_01068a70.FUN_0042f100(message, sizeof(message) - 1);
        }
    } catch (std::exception& error) {
        FUN_00ba3d50(FUN_00bb56f0("%s - failed [%s]", "CSpeedTreeRT::SetLocalMatrices", error.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0("%s - threw an unknown system exception", "CSpeedTreeRT::SetLocalMatrices").c_str());
    }
}
}
}   // namespace f3m_00ba68f0

// @f3 0x00ba8fd0 (community match, verified in this file)
#include <exception>

extern const char DAT_00ea7bd8[], DAT_00ea7bb8[], DAT_00ea7b98[], DAT_00ea7b78[], DAT_00ea7b3c[];
namespace f3m_00ba8fd0 {
struct TreeHeap {
    void* FUN_0086b930(unsigned size);
    void FUN_0086ba60(void* p) throw();
};
extern TreeHeap DAT_01090a78;
struct TreeFile {
    virtual ~TreeFile();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual int GetSize();
    int NiBinaryStream_Read(unsigned char* buffer, int size);
};
TreeFile* FUN_00bc7fc0(const char* filename, int mode, int flags, bool buffered);
int* FUN_00c02a76() throw();
char* FUN_00c07efc(int error) throw();
struct Tree {
    bool FUN_00ba8c40(unsigned char* buffer, int size);
    bool FUN_00ba8fd0(const char* filename);
};

// pdb: CSpeedTreeRT::LoadTree | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pFilename
bool Tree::FUN_00ba8fd0(const char* filename) {
    bool loaded = false;
    TreeFile* file = 0;
    try {
        if (filename) {
            file = FUN_00bc7fc0(filename, 0, 0x2800, true);
            if (file) {
                int size = file->GetSize();
                if (size > 0) {
                    unsigned char* buffer = static_cast<unsigned char*>(
                        DAT_01090a78.FUN_0086b930(size));
                    int count = file->NiBinaryStream_Read(buffer, size);
                    if (count == size) {
                        loaded = FUN_00ba8c40(buffer, size);
                        DAT_01090a78.FUN_0086ba60(buffer);
                        delete file;
                    } else {
                        throw std::exception(sol7d10::FUN_00bb56f0(
                            DAT_00ea7bd8, count, size, filename, FUN_00c07efc(*FUN_00c02a76())).c_str());
                    }
                } else {
                    throw std::exception(sol7d10::FUN_00bb56f0(
                        DAT_00ea7bb8, filename, FUN_00c07efc(*FUN_00c02a76())).c_str());
                }
            } else {
                throw std::exception(sol7d10::FUN_00bb56f0(
                    DAT_00ea7b98, filename, FUN_00c07efc(*FUN_00c02a76())).c_str());
            }
        }
    } catch (std::exception& error) {
        delete file;
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(DAT_00ea7b78, error.what()).c_str());
    } catch (...) {
        delete file;
        sol7d10::FUN_00ba3d50(sol7d10::FUN_00bb56f0(DAT_00ea7b3c).c_str());
    }
    return loaded;
}
}

// @f3 0x00bb9260 (community match, verified in this file)
#include <string>
#include <memory>
#include <iterator>
namespace f3m_00bb9260 {
// The insertion algorithm follows the shared 798-byte VC8 handover.
namespace f3m_00bb9260 {
typedef ::f3m_00bb6350::f3m_00bb6350::Elem Elem;
struct Vec;
struct _Iterator_base {
    const void* _Mycont;
};
struct Iter : _Iterator_base {
    Elem* _Myptr;
};
__declspec(noreturn) void __cdecl FUN_00bc5f00();
Elem* __cdecl FUN_00bb47c0(unsigned int count, Elem* hint);
Elem* __cdecl FUN_00bb5ef0(Elem* first, Elem* last, Elem* dest, Vec& al, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
inline Elem* _Unchecked_uninitialized_move(Elem* first, Elem* last, Elem* dest, Vec& al)
{
    return FUN_00bb5ef0(first, last, dest, al, std::_Ptr_cat(dest, dest), std::_Range_checked_iterator_tag());
}
void __cdecl FUN_00bb5cd0(Elem* first, Elem* last, Vec& al, std::_Nonscalar_ptr_iterator_tag) throw();
Elem* __cdecl FUN_00bb8e50(Elem* first, Elem* last, Elem* dest);
void __cdecl FUN_00bb63e0(Elem* first, Elem* last, const Elem& val);
struct Vec {
    unsigned char _Alval;
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;
    unsigned int size() const { return _Myfirst == 0 ? 0 : (unsigned int)(_Mylast - _Myfirst); }
    unsigned int capacity() const { return _Myfirst == 0 ? 0 : (unsigned int)(_Myend - _Myfirst); }
    unsigned int max_size() const { return size_t(-1) / sizeof(Elem); }
    unsigned int FUN_00bdfe40() const;
    Elem* _Umove_inl(Elem* first, Elem* last, Elem* ptr) { return _Unchecked_uninitialized_move(first, last, ptr, *this); }
    Elem* FUN_00bb8db0(Elem* ptr, unsigned int count, const Elem& val);
    Elem* FUN_00bb8e20(Elem* first, Elem* last, Elem* dest);
    void FUN_00bb6b60(Elem* first, Elem* last);
    void FUN_00bb9260(Iter _Where, unsigned int _Count, const Elem& _Val);
};

void Vec::FUN_00bb9260(Iter _Where, unsigned int _Count, const Elem& _Val)
{
    Elem _Tmp = _Val;
    unsigned int _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        FUN_00bc5f00();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = FUN_00bdfe40() + _Count;
        Elem* _Newvec = FUN_00bb47c0(_Capacity, (Elem*)0);
        Elem* _Ptr = _Newvec;

        try
        {
            _Ptr = _Umove_inl(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = FUN_00bb8db0(_Ptr, _Count, _Tmp);
            _Umove_inl(_Where._Myptr, _Mylast, _Ptr);
        }
        catch (...)
        {
            FUN_00bb6b60(_Newvec, _Ptr);
            ::operator delete(_Newvec);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            std::_Nonscalar_ptr_iterator_tag _Tag;
            FUN_00bb5cd0(_Myfirst, _Mylast, *this, _Tag);
            ::operator delete(_Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where._Myptr) < _Count)
    {
        FUN_00bb8e20(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try
        {
            FUN_00bb8db0(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            FUN_00bb6b60(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;
        FUN_00bb63e0(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        Elem* _Oldend = _Mylast;
        _Mylast = FUN_00bb8e20(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00bb8e50(_Where._Myptr, _Oldend - _Count, _Oldend);
        FUN_00bb63e0(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}
}
}   // namespace f3m_00bb9260

// @f3 0x00bb1670 (community match, verified in this file)
#include <vector>
#include <stdexcept>
namespace f3m_00bb1670 {

namespace f3m_00bb1670 {
typedef ::f3m_00bb1060::worker2462::Element Elem;
Elem* __cdecl FUN_00baec30(unsigned count, Elem*);

struct VectorE16a {
    ::f3m_00bb1060::worker2462::Allocator _Alval;
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;

    unsigned max_size() const { return 0x0fffffff; }

    void FUN_00bb1670(unsigned _Count, const Elem& _Val);   // _Construct_n

    bool _Buy(unsigned _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return (false);
        else if (max_size() < _Capacity)
            ::f3m_00bb19c0::NativeInsert650::FUN_00bc5f00();
        else
        {
            _Myfirst = FUN_00baec30(_Capacity, (Elem*)0);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return (true);
    }

    Elem* _Ufill(Elem* _Ptr, unsigned _Count, const Elem& _Val)
    {
        ::f3m_00bb1060::worker2462::UncheckedFill(_Ptr, _Count, _Val, this->_Alval);
        return (_Ptr + _Count);
    }

    void FUN_00bafed0();                                                               // _Tidy
};

void VectorE16a::FUN_00bb1670(unsigned _Count, const Elem& _Val)
{
    if (_Buy(_Count))
    {
        try {
            _Mylast = _Ufill(_Myfirst, _Count, _Val);
        }
        catch (...) {
            FUN_00bafed0();
            throw;
        }
    }
}

}
}   // namespace f3m_00bb1670

// @f3 0x00ba5b00 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
namespace f3m_00ba5b00 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
 void FUN_0042f100(const char*,unsigned);
};
extern Text DAT_01068a70;
extern const char DAT_00ea73d0[],DAT_00ea7388[],DAT_00ea7368[],DAT_00ea7220[],DAT_00ea71f8[];
void FUN_00ba3d50(const char*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}
struct Engine {
 int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
 char unk20; bool flag21; char unk22, unk23;
 void FUN_00bbda40(float size, float variance);
};
struct Tree {
 Engine* engine;
 void FUN_00ba5b00(float size, float variance);
};
// pdb: CSpeedTreeRT::SetTreeSize | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: fNewSize, fNewVariance
void Tree::FUN_00ba5b00(float size, float variance) {
 try {
  if (engine->flag21) {
   if (size > 0.0) engine->FUN_00bbda40(size, variance);
   else DAT_01068a70.FUN_0042f100(DAT_00ea73d0, 0x3c);
  }
  else DAT_01068a70.FUN_0042f100(DAT_00ea7388, 0x47);
 } catch (std::exception& e) {
  FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea7368, e.what()).c_str());
 } catch (...) {
  FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea7368).c_str());
 }
}
}

// @f3 0x00ba6e00 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
extern const char DAT_00ea7900[],DAT_00ea7220[],DAT_00ea71f8[];
namespace f3m_00ba6e00 {
namespace f3m_00ba6e00 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
};
void FUN_00ba3d50(const char*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}
struct CVec3 {
    CVec3(float fX, float fY, float fZ) : m_fX(fX), m_fY(fY), m_fZ(fZ) { }
    float m_fX, m_fY, m_fZ;
};

struct CLightingEngine {
    void FUN_00bae4f0(const CVec3& cTreeCenter, void* pAllLeaves, unsigned short nNumLeafLods);   // ComputeLeafStaticLighting
};

struct CTreeEngine {
    int unk00[48];
    unsigned short m_nNumLeafLodLevels;     // +0xc0
    short unkc2;
    int unkc4, unkc8, unkcc, unkd0;
    void* m_pAllLeaves;                     // +0xd4
};

struct CSpeedTreeRT {
    CTreeEngine* m_pEngine;                 // +0x00
    int unk04, unk08;
    CLightingEngine* m_pLightingEngine;     // +0x0c
    int unk10[12];
    float* m_pBoundingBox;                  // +0x40
    void GetBoundingBox(float* pBounds) const
    {
        if (pBounds)
            memcpy(pBounds, m_pBoundingBox, 6 * sizeof(float));
        else
            FUN_00ba3d50("GetBoundingBox() expects a non-NULL parameter");
    }
    unsigned short GetNumLeafLodLevels() const { return m_pEngine->m_nNumLeafLodLevels; }
    void FUN_00ba6e00();                    // ComputeLeafStaticLighting
};

// pdb: CSpeedTreeRT::ComputeLeafStaticLighting | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
void CSpeedTreeRT::FUN_00ba6e00()
{
    try {
        float afBoundingBox[6];
        GetBoundingBox(afBoundingBox);
        CVec3 cTreeCenter((afBoundingBox[0] + afBoundingBox[3]) * 0.5,
                          (afBoundingBox[1] + afBoundingBox[4]) * 0.5,
                          (afBoundingBox[2] + afBoundingBox[5]) * 0.5);
        void* pAllLeaves = m_pEngine->m_pAllLeaves;
        m_pLightingEngine->FUN_00bae4f0(cTreeCenter, pAllLeaves, GetNumLeafLodLevels());
    } catch (std::exception& cException) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea7900, cException.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea7900).c_str());
    }
}

}
}   // namespace f3m_00ba6e00

// @f3 0x00ba71d0 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
extern const char DAT_00ea794c[],DAT_00ea7220[],DAT_00ea71f8[];
namespace f3m_00ba71d0 {
namespace f3m_00ba71d0 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
};
void FUN_00ba3d50(const char*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}


struct Geometry;

   // CSpeedTreeRT::SetError

// IdvFormatString

class CSpeedTreeRT {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    unsigned char unk6c_flag;   // +0x6c: 360 billboards available
    void FUN_00ba4820(Geometry* g, unsigned short lod);   // GetBranchGeometry
    void FUN_00ba4bd0(Geometry* g, unsigned short lod);   // GetFrondGeometry
    void FUN_00ba23d0(Geometry* g, unsigned short lod);   // GetLeafGeometry
    void FUN_00ba2a80(Geometry* g, unsigned long flags);  // Get360BillboardGeometry
    void FUN_00ba26e0(Geometry* g) throw();               // GetSimpleBillboardGeometry (nothrow, see above)
    void FUN_00ba71d0(Geometry* g, unsigned long flags, unsigned short branchLod, unsigned short frondLod, unsigned short leafLod);
};

// CSpeedTreeRT::GetGeometry
// pdb: CSpeedTreeRT::GetGeometry | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, low
// pdb params: sGeometry, ulBitVector, sOverrideBranchLodValue, sOverrideFrondLodValue, sOverrideLeafLodValue
void CSpeedTreeRT::FUN_00ba71d0(Geometry* g, unsigned long flags, unsigned short branchLod, unsigned short frondLod, unsigned short leafLod)
{
    try
    {
        if (flags & 1)
            FUN_00ba4820(g, branchLod);
        if (flags & 2)
            FUN_00ba4bd0(g, frondLod);
        if (flags & 4)
            FUN_00ba23d0(g, leafLod);
        if (flags & 8)
        {
            if (unk6c_flag && !(flags & 0x10))
                FUN_00ba2a80(g, flags);
            else
                FUN_00ba26e0(g);
        }
    }
    catch (const std::exception& e)
    {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea794c, e.what()).c_str());
    }
    catch (...)
    {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea794c).c_str());
    }
}

}
}   // namespace f3m_00ba71d0

// @f3 0x00ba6650 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
namespace f3m_00ba6650 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 void FUN_0042f100(const char*,unsigned);
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
};
extern const char DAT_00ea773c[],DAT_00ea7220[],DAT_00ea71f8[];
extern Text DAT_01068a70;
extern const char DAT_00ea775c[];
void FUN_00ba3d50(const char*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}


           // CSpeedTreeRT::m_strError
     // CSpeedTreeRT::SetError

// IdvFormatString

struct CSpeedWind {
    float m_fFrequencyTimeOffset;           // +0x00
    float m_fStrength;                      // +0x04
    int m_eBranchMethod;                    // +0x08
    int m_eFrondMethod;                     // +0x0c
    int m_eLeafMethod;                      // +0x10
    bool m_bLeafWindOverride;               // +0x14
    float GetFrequencyTimeOffset() const { return m_fFrequencyTimeOffset; }
    float FUN_00bae300(float fNewStrength, float fOldStrength, float fFrequencyTimeOffset);   // SetStrength
};

struct CIndexedGeometry {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    bool m_bWindComputed;                   // +0x12
    void SetWindComputed(bool b) { m_bWindComputed = b; }
};

struct CLeafGeometry {
    void FUN_00bb2cb0();                    // Invalidate
};

struct CSpeedTreeRT {
    int unk00;
    CIndexedGeometry* m_pBranchGeometry;    // +0x04
    CLeafGeometry* m_pLeafGeometry;         // +0x08
    int unk0c;
    CSpeedWind* m_pWind;                    // +0x10
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
    CIndexedGeometry* m_pFrondGeometry;     // +0x60
    int GetBranchWindMethod() const { return m_pWind->m_eBranchMethod; }
    int GetFrondWindMethod() const { return m_pWind->m_eFrondMethod; }
    int GetLeafWindMethod() const { return m_pWind->m_eLeafMethod; }
    bool LeafWindOverride() const { return m_pWind->m_bLeafWindOverride; }
    float FUN_00ba6650(float fNewStrength, float fOldStrength, float fFrequencyTimeOffset);   // SetWindStrength
};

// pdb: CSpeedTreeRT::SetWindStrength | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: fNewStrength, fOldStrength, fFrequencyTimeOffset
float CSpeedTreeRT::FUN_00ba6650(float fNewStrength, float fOldStrength, float fFrequencyTimeOffset)
{
    float fNewFrequencyTimeShift = 0.0f;
    try {
        if (fNewStrength >= 0.0) {
            if (fOldStrength == -1.0)
                fOldStrength = m_pWind->m_fStrength;
            if (fFrequencyTimeOffset == -1.0)
                fFrequencyTimeOffset = m_pWind->GetFrequencyTimeOffset();
            fNewFrequencyTimeShift = m_pWind->FUN_00bae300(fNewStrength, fOldStrength, fFrequencyTimeOffset);
            if (GetBranchWindMethod() == 1 && m_pBranchGeometry)
                m_pBranchGeometry->SetWindComputed(false);
            if (GetFrondWindMethod() == 1 && m_pFrondGeometry)
                m_pFrondGeometry->SetWindComputed(false);
            if (GetLeafWindMethod() == 1 || LeafWindOverride())
                m_pLeafGeometry->FUN_00bb2cb0();
        } else {
            DAT_01068a70.FUN_0042f100(DAT_00ea775c, 0x32);
        }
    } catch (std::exception& cException) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea773c, cException.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea773c).c_str());
    }
    return fNewFrequencyTimeShift;
}

}

// @f3 0x00ba8c40 (community match, verified in this file)
#include <exception>
#include <stdio.h>
#include <stdarg.h>
extern unsigned char DAT_011782c0;
extern unsigned short DAT_01178308;
extern const char DAT_00ea7b24[],DAT_00ea7220[],DAT_00ea71f8[];
namespace f3m_00ba8c40 {
extern "C" void __cdecl _invalid_parameter_noinfo();
namespace f3m_00ba8c40 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
};
// CTreeFileAccess: a read cursor over a private copy of the file block (std::vector<char> layout).
struct FUN_00ba8260 {
    unsigned int m_nIndex;
    char m_cAlval;
    char* m_pFirst;
    char* m_pLast;
    char* m_pEnd;
    FUN_00ba8260(const char* block, int size);
    ~FUN_00ba8260() { if (m_pFirst != 0) DAT_01090a78.FUN_0086ba60(m_pFirst); }
    int FUN_00ba92d0();     // ParseToken
    float FUN_00ba92a0();   // ParseFloat
    unsigned int Size() const { return m_pFirst == 0 ? 0 : (unsigned int)(m_pLast - m_pFirst); }
    char& At(unsigned int i) { if (!(i < Size())) _invalid_parameter_noinfo(); return *(m_pFirst + i); }
    bool EndOfFile() const { return m_nIndex >= Size(); }
    bool ParseBool() { unsigned int i = m_nIndex++; return At(i) != 0; }
};

struct CTreeEngine {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int m_nNumBranchLevels;   // +0xf0
    int GetNumBranchLevels() const { return m_nNumBranchLevels; }
    bool FUN_00bc0210(FUN_00ba8260* file);
    void FUN_00bbe370(FUN_00ba8260* file);
    void FUN_00bbe150(FUN_00ba8260* file);
    void FUN_00bbdb60(FUN_00ba8260* file);
};

struct CLightingEngine {
    int m_eBranchLightingMethod;   // +0x00
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int m_eLeafLightingMethod;     // +0x38
    int unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    int m_eFrondLightingMethod;    // +0x78
    void FUN_00baea20(FUN_00ba8260* file);
    int GetBranchLightingMethod() const { return m_eBranchLightingMethod; }
    int GetLeafLightingMethod() const { return m_eLeafLightingMethod; }
    int GetFrondLightingMethod() const { return m_eFrondLightingMethod; }
};

struct CWindEngine {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    float m_fStrength;    // +0x3c
    float m_fResponse;    // +0x40
    void FUN_00bae3b0(int index, unsigned short count);
    void SetStrength(float f) { m_fStrength = f; }
    void SetResponse(float f) { m_fResponse = f; }
};

struct CFrondEngine {
    int FUN_00896c70() const;                // GetLevel: a trivial accessor folded with others at 0x00896c70
    void FUN_00bba060(FUN_00ba8260* file);   // Parse
};


void FUN_00ba3d50(const char* error);   // CSpeedTreeRT::SetError

static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}

class CSpeedTreeRT {
public:
    CTreeEngine* m_pEngine;            // +0x00
    int unk04;
    int unk08;
    CLightingEngine* m_pLightingEngine;   // +0x0c
    CWindEngine* m_pWindEngine;        // +0x10
    int unk14;
    int m_eShadowMode;                 // +0x18
    int unk1C;
    int unk20;
    int unk24;
    float m_fShadowValue;              // +0x28
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int m_nFrondLevel;                 // +0x3c
    int unk40;
    int unk44;
    int m_nBranchLevels;               // +0x48
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    CFrondEngine* m_pFrondEngine;      // +0x5c

    void FUN_00ba3d80(FUN_00ba8260* file);   // ParseLodInfo
    void FUN_00ba40c0(FUN_00ba8260* file);   // ParseTextureCoordInfo
    void FUN_00ba3fa0(FUN_00ba8260* file);   // ParseWindInfo
    void FUN_00ba89c0(FUN_00ba8260* file);   // ParseCollisionObjects
    void FUN_00ba31d0(FUN_00ba8260* file);   // ParseUserData
    void FUN_00ba16a0(FUN_00ba8260* file);   // ParseShadowProjectionInfo
    void FUN_00ba53b0(FUN_00ba8260* file);   // ParseSupplementalTexCoordInfo
    void FUN_00ba5d50(int method);           // SetBranchLightingMethod
    void FUN_00ba5e80(int method);           // SetLeafLightingMethod
    void FUN_00ba5fb0(int method);           // SetFrondLightingMethod

    bool FUN_00ba8c40(const char* block, int size);
};

// pdb: CSpeedTreeRT::LoadTree | SpeedTreeRT.obj | fnv360_0822_retail, call_gap, medium
// pdb params: pBlock, nNumBytes
bool CSpeedTreeRT::FUN_00ba8c40(const char* block, int size)
{
    bool bSuccess = false;
    try {
        FUN_00ba8260 cFile(block, size);
        if (m_pEngine->FUN_00bc0210(&cFile)) {
            if (!cFile.EndOfFile()) {
                bool bDone = false;
                int nToken = cFile.FUN_00ba92d0();
                do {
                    switch (nToken) {
                    case 8000:
                        m_pLightingEngine->FUN_00baea20(&cFile);
                        break;
                    case 9000:
                        FUN_00ba3d80(&cFile);
                        break;
                    case 11000:
                        FUN_00ba3fa0(&cFile);
                        break;
                    case 10000:
                        FUN_00ba40c0(&cFile);
                        break;
                    case 12000:
                        FUN_00ba89c0(&cFile);
                        break;
                    case 13000:
                        m_pFrondEngine->FUN_00bba060(&cFile);
                        break;
                    case 15000:
                        m_pEngine->FUN_00bbe150(&cFile);
                        break;
                    case 16000:
                        m_pEngine->FUN_00bbe370(&cFile);
                        break;
                    case 16013:
                        m_pEngine->FUN_00bbdb60(&cFile);
                        break;
                    case 16014:
                        m_fShadowValue = cFile.FUN_00ba92a0();
                        break;
                    case 18000:
                        FUN_00ba16a0(&cFile);
                        break;
                    case 19000:
                        FUN_00ba31d0(&cFile);
                        break;
                    case 20000:
                        FUN_00ba53b0(&cFile);
                        break;
                    case 21000:
                        m_pWindEngine->SetStrength(cFile.FUN_00ba92a0());
                        break;
                    case 21001:
                        m_pWindEngine->SetResponse(cFile.FUN_00ba92a0());
                        break;
                    case 22000:
                        DAT_011782c0 = cFile.ParseBool();
                        break;
                    default:
                        bDone = true;
                        break;
                    }
                    if (cFile.EndOfFile())
                        bDone = true;
                    else
                        nToken = cFile.FUN_00ba92d0();
                } while (!bDone);
            }
            FUN_00ba5d50(m_pLightingEngine->GetBranchLightingMethod());
            FUN_00ba5e80(m_pLightingEngine->GetLeafLightingMethod());
            FUN_00ba5fb0(m_pLightingEngine->GetFrondLightingMethod());
            m_nBranchLevels = m_pEngine->GetNumBranchLevels();
            m_nFrondLevel = m_pFrondEngine->FUN_00896c70();
            if (m_eShadowMode == 2) {
                m_eShadowMode = 1;
                m_fShadowValue = 0.5f;
            }
            m_pWindEngine->FUN_00bae3b0(0, DAT_01178308);
            bSuccess = true;
        }
    } catch (std::exception& e) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea7b24, e.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea7b24).c_str());
    }
    return bSuccess;
}

}
}   // namespace f3m_00ba8c40

// @f3 0x00ba7860 (community match, verified in this file)
#include <string.h>
#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
namespace f3m_00ba7860 {
struct Text {
 unsigned allocator;
 union { char buffer[16]; char* heap; };
 unsigned size,capacity;
 Text(); Text(const Text&); Text(const char*);
 void FUN_0042dba0();
 ~Text(){ FUN_0042dba0(); }
 const char* c_str() const {return capacity>=16 ? heap:buffer;}
 void FUN_0042f100(const char*,unsigned);
};
extern Text DAT_01068a70;
extern const char DAT_00ea7980[],DAT_00ea7968[],DAT_00ea7220[],DAT_00ea71f8[];
void FUN_00ba3d50(const char*);
static __declspec(noinline) Text FUN_00bb56f0(const char* format,...) {
 char text[1024];
 va_list args;va_start(args,format);
 vsprintf(text,format,args);va_end(args);
 return Text(text);
}
struct CVec3 {
    float m_afData[3];
    CVec3(float fX, float fY, float fZ = 0.0f)
    {
        (*this)[0] = fX;
        (*this)[1] = fY;
        (*this)[2] = fZ;
    }
    float& operator[](int nIndex) { return m_afData[nIndex]; }
    const float& operator[](int nIndex) const { return m_afData[nIndex]; }
    // CVec3::Distance: square root estimated from the float's bits
    float Distance(const CVec3& cPoint) const
    {
        float fSquared = (cPoint.m_afData[0] - (*this)[0]) * (cPoint.m_afData[0] - (*this)[0]) +
                            (cPoint.m_afData[1] - (*this)[1]) * (cPoint.m_afData[1] - (*this)[1]) +
                            (cPoint.m_afData[2] - (*this)[2]) * (cPoint.m_afData[2] - (*this)[2]);
        union { float m_fValue; int m_nBits; } uSquared;
        uSquared.m_fValue = fSquared;
        uSquared.m_nBits = (uSquared.m_nBits >> 1) + 0x1fc00000;
        return uSquared.m_fValue;
    }
};
// a region corner: three coordinates plus three more the region keeps; has a destructor
struct CRegionCorner {
    float m_afData[3];
    float m_afExtra[3];
    ~CRegionCorner();                       // 0x00c24b70
    operator const float*() const { return m_afData; }
};

struct CRegion {
    CRegionCorner m_cMin;
    CRegionCorner m_cMax;
    CRegion();                              // 0x00bc4990
};

struct CTransform {
    float m_afData[16];
    CTransform();                           // 0x00bc1a20
};

// the twin's CopyV(m_p40->min, box.min): copies a region corner's three coordinates
inline void CopyCorner(float* pDest, const CRegionCorner& cCorner)
{
    memcpy(pDest, cCorner.m_afData, 3 * sizeof(float));
}

struct CTreeSizes {
    float m_afBoundingBox[6];
    float m_fSize;                          // +0x18
};

struct CLeafLodArray {                      // a vector of 0x54-byte leaf records
    void FUN_00bc0ab0(unsigned int nCount);
};

struct SLeaf { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50; };          // one 0x54-byte leaf record

// std::vector<SLeaf> layout (allocator, first, last, end)
struct CLeafVector {
    char m_cAlval;
    SLeaf* m_pFirst;
    SLeaf* m_pLast;
    SLeaf* m_pEnd;
    unsigned int size() const { return (m_pFirst == 0 ? 0 : (unsigned int)(m_pLast - m_pFirst)); }
};

struct SWindInfo { int m_nData; };

struct CTreeEngine {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    CLeafLodArray m_cLeafLods;              // +0x84
    int unk88, unk8c, unk90;
    CLeafVector m_vLeaves;           // +0x94
    int unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int m_nLeafTextureCount;                // +0xc0
    int unkc4, unkc8, unkcc, unkd0;
    int m_nLeafLodCount;                    // +0xd4
    int unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0;
    SWindInfo m_sWindInfo;                  // +0xf4
    CLeafLodArray* GetLeafLods() { return &m_cLeafLods; }
    int GetNumLeafTextures() const { return m_nLeafTextureCount; }
    int GetNumLeafLods() const { return m_nLeafLodCount; }
    void FUN_00bbdb10(unsigned int nSeed);  // SetSeed
    void FUN_00bbfa10(float fSize);         // Compute
};

struct CIndexedGeometry {
    unsigned short unk00, unk02, unk04, unk06, unk08, unk0a, unk0c, unk0e, unk10, unk12, unk14, unk16, unk18, unk1a, unk1c, unk1e;
    unsigned short m_usNumStrips;           // +0x20
    unsigned short GetNumStrips() const { return m_usNumStrips; }
    void FUN_00bb21b0(int nMode);           // CombineStrips
    void FUN_00baf000(const CTransform& cTransform);   // Transform
    void FUN_00baeee0(CRegion& cExtents);   // ComputeExtents
};

struct CLeafGeometry {
    void FUN_00bb3d00(int nNumTextures, int nNumLods, CLeafLodArray* pLods);   // Init
    void FUN_00bb2f30(int nIndex, const float* pTexCoords);                     // SetTextureCoords
    void FUN_00bb2d40(const CTransform& cTransform);                            // Transform
    void FUN_00bb3f10(CRegion& cExtents);                                       // ComputeExtents
};

struct CLightingEngine {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    int m_eLeafLightingMethod;              // +0x38
    int GetLeafLightingMethod() const { return m_eLeafLightingMethod; }
};

struct CWindEngine {
    void FUN_00bae370(const SWindInfo& sWindInfo);   // Init
};

struct STextureCoords {
    int m_nNumLeafMaps;
    float* m_pLeafTexCoords;
    int unk08, unk0c;
    int m_nNumFrondMaps;                    // +0x10
    float* m_pFrondTexCoords;               // +0x14
};

struct SCollisionObjects {
    void FUN_00ba3010(const CTransform& cTransform);   // Transform
};

struct CFrondEngine {
    void FUN_00bbca30(CIndexedGeometry* pGeometry, CLightingEngine* pLighting);   // Compute
    void FUN_00bb5070(CIndexedGeometry* pGeometry, int nIndex, const float* pTexCoords, bool bFlip);   // SetTextureCoords
};

extern bool DAT_01178275;                   // texture flip flag
extern CFrondEngine* DAT_011782bc;          // current frond engine

class CSpeedTreeRT {
public:
    CTreeEngine* m_pEngine;                 // +0x00
    CIndexedGeometry* m_pBranchGeometry;    // +0x04
    CLeafGeometry* m_pLeafGeometry;         // +0x08
    CLightingEngine* m_pLightingEngine;     // +0x0c
    CWindEngine* m_pWindEngine;             // +0x10
    int unk14, unk18, unk1c, unk20;
    float m_fTreeSize;                      // +0x24
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    CTreeSizes* m_pTreeSizes;               // +0x40
    bool unk44;
    bool m_bTreeComputed;                   // +0x45
    int unk48;
    STextureCoords* m_pTextureCoords;       // +0x4c
    void* m_pSelfShadow;                    // +0x50
    int unk54;
    SCollisionObjects* m_pCollisionObjects; // +0x58
    CFrondEngine* m_pFrondEngine;           // +0x5c
    CIndexedGeometry* m_pFrondGeometry;     // +0x60
    unsigned short m_usNumFrondStrips;      // +0x64

    void FUN_00ba6e00();                    // ComputeLeafStaticLighting
    void FUN_00ba1720();                    // ComputeSelfShadowTexCoords
    void FUN_00ba1870();                    // InitBoundingBoxCorners
    bool FUN_00ba7860(const float* pTransform, unsigned int nSeed, bool bCompositeStrips);
};

// pdb: CSpeedTreeRT::Compute | SpeedTreeRT.obj | fnv360_0822_retail, ustr, medium
// pdb params: pTransform, nSeed, bCompositeStrips
bool CSpeedTreeRT::FUN_00ba7860(const float* pTransform, unsigned int nSeed, bool bCompositeStrips)
{
    try {
        if (!m_bTreeComputed) {
            DAT_011782bc = m_pFrondEngine;
            m_pEngine->FUN_00bbdb10(nSeed);
            m_pEngine->FUN_00bbfa10(m_fTreeSize);
            m_pFrondEngine->FUN_00bbca30(m_pFrondGeometry, m_pLightingEngine);
            m_usNumFrondStrips = m_pFrondGeometry->GetNumStrips();
            m_pEngine->m_cLeafLods.FUN_00bc0ab0(m_pEngine->m_vLeaves.size());
            if (m_pLightingEngine->GetLeafLightingMethod() == 1)
                FUN_00ba6e00();
            const SWindInfo& sWindInfo = m_pEngine->m_sWindInfo;
            m_pWindEngine->FUN_00bae370(sWindInfo);
            m_pLeafGeometry->FUN_00bb3d00(m_pEngine->GetNumLeafTextures(), m_pEngine->GetNumLeafLods(), m_pEngine->GetLeafLods());
            if (m_pTextureCoords) {
                for (int i = 0; i < m_pTextureCoords->m_nNumLeafMaps; ++i)
                    m_pLeafGeometry->FUN_00bb2f30(i, m_pTextureCoords->m_pLeafTexCoords + i * 8);
                for (int i = 0; i < m_pTextureCoords->m_nNumFrondMaps; ++i)
                    m_pFrondEngine->FUN_00bb5070(m_pFrondGeometry, i, m_pTextureCoords->m_pFrondTexCoords + i * 8, DAT_01178275);
            }
            if (bCompositeStrips) {
                m_pBranchGeometry->FUN_00bb21b0(0);
                m_pFrondGeometry->FUN_00bb21b0(0);
            }
            if (pTransform) {
                CTransform cTransform;
                memmove(cTransform.m_afData, pTransform, 16 * sizeof(float));
                m_pBranchGeometry->FUN_00baf000(cTransform);
                m_pLeafGeometry->FUN_00bb2d40(cTransform);
                m_pFrondGeometry->FUN_00baf000(cTransform);
                if (m_pCollisionObjects)
                    m_pCollisionObjects->FUN_00ba3010(cTransform);
            }
            CVec3 cOrigin(0.0f, 0.0f, 0.0f);
            CRegion cExtents;
            m_pBranchGeometry->FUN_00baeee0(cExtents);
            m_pLeafGeometry->FUN_00bb3f10(cExtents);
            m_pFrondGeometry->FUN_00baeee0(cExtents);
            CopyCorner(m_pTreeSizes->m_afBoundingBox, cExtents.m_cMin);
            CopyCorner(m_pTreeSizes->m_afBoundingBox + 3, cExtents.m_cMax);

            float fDimension = cOrigin.Distance(CVec3(m_pTreeSizes->m_afBoundingBox[0], m_pTreeSizes->m_afBoundingBox[1]));
            fDimension = __max(fDimension, cOrigin.Distance(CVec3(m_pTreeSizes->m_afBoundingBox[0], m_pTreeSizes->m_afBoundingBox[4])));
            fDimension = __max(fDimension, cOrigin.Distance(CVec3(m_pTreeSizes->m_afBoundingBox[3], m_pTreeSizes->m_afBoundingBox[1])));
            fDimension = __max(fDimension, cOrigin.Distance(CVec3(m_pTreeSizes->m_afBoundingBox[3], m_pTreeSizes->m_afBoundingBox[4])));
            m_pTreeSizes->m_fSize = fDimension * 2.0f;

            if (m_pSelfShadow)
                FUN_00ba1720();
            FUN_00ba1870();
            m_bTreeComputed = true;
        } else {
            DAT_01068a70.FUN_0042f100(DAT_00ea7980, 0x3f);
        }
    } catch (std::exception& cException) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea7220, DAT_00ea7968, cException.what()).c_str());
    } catch (...) {
        FUN_00ba3d50(FUN_00bb56f0(DAT_00ea71f8, DAT_00ea7968).c_str());
    }
    return m_bTreeComputed;
}

}

// @f3 0x00ba9460 (community match, verified in this file)
namespace f3m_00ba9460 {
namespace f3m_00ba9460 {
void __cdecl FUN_00c01e8b();
struct Text {
    unsigned proxy;
    union Storage { char chars[16]; char* ptr; } storage;
    unsigned length, capacity;
    char* data() { return 16 <= capacity ? storage.ptr : storage.chars; }
    void eos(unsigned n) { length = n; data()[n] = char(); }
    Text() { capacity = 15; eos(0); }
    ~Text() { FUN_0042dba0(); }
    void FUN_0042dba0();
    Text& FUN_00ba93b0(unsigned count, char ch);
};
struct Buffer {
    int alloc;
    char* first;
    char* last;
    char* end;
    unsigned size() const { return first == 0 ? 0 : (unsigned)(last - first); }
    char& operator[](unsigned i) { if (!(i < size())) FUN_00c01e8b(); return first[i]; }
};
struct Stream {
    unsigned pos;
    Buffer buffer;
    int ReadInt() { const int* p = (const int*)&buffer[pos]; pos += 4; return *p; }
    char ReadChar() { return buffer[pos++]; }
    Text FUN_00ba9460();
};
// pdb: CTreeFileAccess::ParseString | FileAccess.obj | fnv360_0822_retail, call_seq, medium
Text Stream::FUN_00ba9460()
{
    Text result;
    int count = ReadInt();
    for (int i = 0; i < count; ++i)
        result.FUN_00ba93b0(1, ReadChar());
    return result;
}
}
}   // namespace f3m_00ba9460
