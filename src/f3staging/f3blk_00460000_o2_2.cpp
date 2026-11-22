#include <windows.h>
#include <string.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_00460000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004699b0 (community match, verified in this file)
namespace f3m_004699b0 {

class RefCountedV {
public:
    virtual ~RefCountedV();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class RefHolderV {
public:
    int unk00;
    bool unk04;
    int unk08;
    NiPointer<RefCountedV> spObject;
    RefHolderV(RefCountedV* object, int value8, int value0);
};

// pdb: BGSDecalEmitter::BGSDecalEmitter | BGSDecalManager.obj | fnv360_0822_retail, objrun, medium
// pdb params: apParticleData, apImpactData, aiNumDecals
RefHolderV::RefHolderV(RefCountedV* object, int value8, int value0)
{
    spObject = object;
    unk08 = value8;
    unk00 = value0;
    unk04 = false;
}
}   // namespace f3m_004699b0

// @f3 0x0046da70 (community match, verified in this file)
namespace f3m_0046da70 {

class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class BGSPrimitive {
public:
    virtual ~BGSPrimitive();
    virtual void Unk04() = 0;
    virtual void Unk08() = 0;
    virtual void Unk0C() = 0;
    virtual void Unk10() = 0;
    virtual void Unk14();
    void DetachGeometryV();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    NiPointer<NiRefObject> spObject24;
    NiPointer<NiRefObject> spObject28;
    NiPointer<NiRefObject> spObject2C;
};

// pdb: BGSPrimitive::~BGSPrimitive | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
BGSPrimitive::~BGSPrimitive()
{
    DetachGeometryV();
}
}   // namespace f3m_0046da70

// @f3 0x0046dbe0 (community match, verified in this file)
namespace f3m_0046dbe0 {


class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((LONG*)&m_uiRefCount))
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

class BGSPrimitive
{
  public:
    BGSPrimitive();
    virtual ~BGSPrimitive();
    unsigned int m_eType;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    NiPointer<NiRefObject> unk24;
    NiPointer<NiRefObject> unk28;
    NiPointer<NiRefObject> unk2C;
};

class BGSPrimitiveBox : public BGSPrimitive
{
  public:
    BGSPrimitiveBox();
    virtual ~BGSPrimitiveBox();
};

// pdb: BGSPrimitiveBox::BGSPrimitiveBox | BGSPrimitive.obj | fnv360_0822_retail, uvref, medium
BGSPrimitiveBox::BGSPrimitiveBox()
{
    unk24 = 0;
    unk2C = 0;
    m_eType = 1;
}
}   // namespace f3m_0046dbe0

// @f3 0x0046c8c0 (community match, verified in this file)
#include <windows.h>
extern char* g_nullStringHandleAL;
namespace f3m_0046c8c0 {

void* __cdecl FUN_0089eb90(unsigned int bytes);
void __cdecl FUN_0089ec10(void* memory);
char* __cdecl FUN_008242a0(const char* text);

class FixedStringAL46 {
public:
    char* m_handle;
    FixedStringAL46(const char* text) { m_handle = FUN_008242a0(text); }
    ~FixedStringAL46()
    {
        if (m_handle != g_nullStringHandleAL)
            InterlockedDecrement((LONG*)(m_handle - 8));
    }
};

class PlaneObjAL46 {
public:
    PlaneObjAL46();
    virtual void Slot00();
    virtual void DeleteThis();
    LONG m_refCount;
    void IncRefCount() { InterlockedIncrement(&m_refCount); }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_refCount) == 0)
            DeleteThis();
    }
    void FUN_008245d0(const FixedStringAL46& name);
    void FUN_008268a0();
    static void* operator new(size_t bytes) { return FUN_0089eb90(bytes); }
    static void operator delete(void* memory) { FUN_0089ec10(memory); }
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
};

class PlaneOwnerAL46 {
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
    NiPointer<PlaneObjAL46> m_plane;
    void FUN_0046c8c0();
};

// pdb: BGSPrimitivePlane::Build | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
void PlaneOwnerAL46::FUN_0046c8c0()
{
    m_plane = new PlaneObjAL46;
    m_plane->FUN_008245d0("Plane");
    m_plane->FUN_008268a0();
}
}   // namespace f3m_0046c8c0

// @f3 0x00469140 (community match, verified in this file)
namespace f3m_00469140 {
class Culler_469140 {
public:
    virtual void vf00();
    virtual void vf04();

    long m_uiRefCount;
};

class FUN_00a693e0 {
public:
    virtual void vf00();

    ~FUN_00a693e0();
};

class BSCullingProcess : public FUN_00a693e0 {
public:
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
    Culler_469140* unkC4;

    ~BSCullingProcess();
};

// pdb: BSCullingProcess::~BSCullingProcess | BGSDecalManager.obj | fnv360_0822_retail, call_seq, medium
BSCullingProcess::~BSCullingProcess()
{
    Culler_469140* culler = unkC4;
    if (culler && InterlockedDecrement(&culler->m_uiRefCount) == 0)
        culler->vf04();
}
}   // namespace f3m_00469140

// @f3 0x0046c770 (community match, verified in this file)
namespace f3m_0046c770 {
namespace f3m_0046c770 {
struct RefObj
{
    virtual void vf00();
    virtual void DeleteThis();
    long refcount;
};
struct Quad
{
    float x, y, z;
    Quad() : x(0.0f), y(0.0f), z(0.0f) {}
};
struct RefPtr
{
    RefObj* p;
    RefPtr() : p(0) {}
    ~RefPtr() { if (p && InterlockedDecrement(&p->refcount) == 0) p->DeleteThis(); }
    RefPtr& operator=(RefObj* o)
    {
        if (p != o)
        {
            RefObj* old = p;
            if (old && InterlockedDecrement(&old->refcount) == 0) old->DeleteThis();
            p = o;
        }
        return *this;
    }
};
struct Obj46c770
{
    virtual ~Obj46c770();
    int unk04;
    Quad unk08;
    float unk14;
    int unk18;
    int unk1C;
    int unk20;
    RefPtr unk24;
    RefPtr unk28;
    RefPtr unk2C;
    int unk30;
    Obj46c770();
};
}
using namespace f3m_0046c770;
// pdb: BGSPrimitive::BGSPrimitive | BGSPrimitive.obj | fnv360_0822_retail, call_seq, medium
Obj46c770::Obj46c770() : unk14(0.0f)
{
    unk24 = 0;
    unk2C = 0;
    unk28 = 0;
    unk30 = 7;
}
}   // namespace f3m_0046c770

// @f3 0x00470960 (community match, verified in this file)
#include <string.h>
extern const char* DAT_00f4c434[5];
extern const char DAT_00dbfbfc[];
namespace f3m_00470960 {

struct Sub470960 {
    int unk00;
    int unk04;
    void* unk08;
};

struct Obj470960 {
    int unk00;
    int unk04;
    void* unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub470960* unk18;
};

struct Rec470960 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
};

void* BipedAnim_GetLightingProperty(Obj470960* p);
int FUN_00c020cb(void* a, const char* s, int len);
int FUN_00887da0(const char* fmt, void* a, void* b);

// pdb: BipedAnim::GetSkinBipedObject | BipedAnim.obj | fnv360_0822_retail, ustr, low, conflict (skyrim: BSDismemberSkinInstance::EnableAllParts)
// pdb params: apObj, apLightingProperty
int FUN_00470960(Obj470960* p1, Rec470960* p2)
{
    Rec470960* r = p2;
    if (r == 0) {
        r = (Rec470960*)BipedAnim_GetLightingProperty(p1);
    }
    if (r == 0 || (r->unk20 & 0x400) <= 0) {
        return -1;
    }
    void* ebx = (*(Obj470960* volatile*)&p1)->unk08;
    int result = 2;
    int i = 0;
    while (i < 5) {
        if (ebx != 0) {
            const char* name = DAT_00f4c434[i];
            if (FUN_00c020cb(ebx, name, (int)strlen(name)) == 0) {
                break;
            }
        }
        i++;
    }
    switch (i) {
    case 0:
    case 1:
    case 4:
        break;
    case 2:
        result = 3;
        break;
    case 3:
        result = 4;
        break;
    default:
        FUN_00887da0(DAT_00dbfbfc, ebx, (*(Obj470960* volatile*)&p1)->unk18->unk08);
        break;
    }
    return result;
}
}   // namespace f3m_00470960

// @f3 0x00475020 (community match, verified in this file)
extern void* DAT_01090a78;
namespace f3m_00475020 {

class Heap47 {
public:
    void FUN_0086ba60(void* memory);
};

class Obj47 {
public:
    void FUN_00474f10(void*, void*);
};

extern "C" Obj47* __cdecl FUN_00474ba0(int flag);

class Ref47 {
public:
    void* m_00;
    void* m_04;
    long m_08;
    void FUN_00475020();
};

// pdb: BSCloneReserver::DecRefCount | BSClonePool.obj | fnv360_0822_retail, call_seq, medium
void Ref47::FUN_00475020() {
    if (InterlockedDecrement(&m_08) != 0)
        return;
    if (!this)
        return;
    if (m_00 != 0 && m_04 != 0) {
        FUN_00474ba0(1)->FUN_00474f10(m_00, m_04);
    }
    ((Heap47*)&DAT_01090a78)->FUN_0086ba60(this);
}
}   // namespace f3m_00475020

// @f3 0x00461690 (community match, verified in this file)
extern int DAT_00f5aca8[];
extern int DAT_00f5acac[];
namespace f3m_00461690 {
int TESAnimGroup_GetType(int key);

class Owner_00461690 {
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
    unsigned short unk9C;
    unsigned short unk9E;
    unsigned short unkA0;
    unsigned short unkA2;
    unsigned short unkA4;
    unsigned short unkA6;
    unsigned short unkA8;
    unsigned short unkAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    float unkD0;
    int FUN_00460af0(int a, int b);
    void FUN_0045f220(float f, int a, int b);
    int Animation_PlayGroup(int p1, int p2, int p3, int p4);
};

// pdb: Animation::PlayGroup | Animation.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
int Owner_00461690::Animation_PlayGroup(int p1, int p2, int p3, int p4)
{
    int key = p1;
    int idx = TESAnimGroup_GetType(key);
    int slot = p4;
    if (p4 == -1) {
        slot = DAT_00f5aca8[idx * 9];
    } else {
        slot = p4;
    }
    int result = 0;
    switch (slot) {
    case 0x14:
        slot = 1;
        break;
    case 0x15:
        slot = 4;
        break;
    }
    if (idx == 0xff) {
        return 0;
    }
    {
        switch (DAT_00f5acac[idx * 9]) {
        case 0:
        case 1:
        case 2:
            switch (p2) {
            case 0:
                (&unk9C)[slot] = (unsigned short)key;
                (&unkAC)[slot] = p3;
                break;
            case 1:
                (&unk9C)[slot] = 0xff;
                (&unk7C)[slot] = p3;
                result = FUN_00460af0(key, p4);
                FUN_0045f220(unkD0, 0, 1);
                break;
            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            result = FUN_00460af0(key, p4);
            FUN_0045f220(unkD0, 0, 1);
            break;
        }
    }
    return result;
}
}   // namespace f3m_00461690

// @f3 0x004792a0 (community match, verified in this file)
namespace f3m_004792a0 {

extern const char* DAT_00e207a8;
struct AtomPool4792 { void FUN_0086ba60(void*); };
extern AtomPool4792 DAT_01090a78;
struct Atom4792 {
 const char* text;
 ~Atom4792() { if(text!=DAT_00e207a8) InterlockedDecrement((volatile LONG*)text-2); }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};
extern Atom4792* DAT_0106e7c4;
extern Atom4792* DAT_0106e7c8;
extern Atom4792* DAT_0106e7cc;
extern Atom4792* DAT_0106e7d0;
extern Atom4792* DAT_0106e7dc;
extern Atom4792* DAT_0106e7e0;
extern Atom4792* DAT_0106e7e4;
extern Atom4792* DAT_0106e7e8;
extern Atom4792* DAT_0106e7ec;
extern Atom4792* DAT_0106e7f0;
extern Atom4792* DAT_0106e7f4;
extern Atom4792* DAT_0106e7f8;
extern Atom4792* DAT_0106e7fc;
extern Atom4792* DAT_0106e800;
extern Atom4792* DAT_0106e804;
extern Atom4792* DAT_0106e808;
extern Atom4792* DAT_0106e80c;
extern Atom4792* DAT_0106e810;
extern Atom4792* DAT_0106e814;
extern Atom4792* DAT_0106e818;
extern Atom4792* DAT_0106e81c;
extern Atom4792* DAT_0106e820;
extern Atom4792* DAT_0106e824;
extern Atom4792* DAT_0106e828;
extern Atom4792* DAT_0106e82c;
extern Atom4792* DAT_0106e830;
extern Atom4792* DAT_0106e834;
extern Atom4792* DAT_0106e838;
extern Atom4792* DAT_0106e83c;
extern Atom4792* DAT_0106e840;
extern Atom4792* DAT_0106e844;
extern Atom4792* DAT_0106e848;
extern Atom4792* DAT_0106e84c;
extern Atom4792* DAT_0106e850;
extern Atom4792* DAT_0106e854;
extern Atom4792* DAT_0106e858;
extern Atom4792* DAT_0106e85c;
extern Atom4792* DAT_0106e860;
extern Atom4792* DAT_0106e864;
extern Atom4792* DAT_0106e868;
extern Atom4792* DAT_0106e86c;
extern Atom4792* DAT_0106e870;
extern Atom4792* DAT_0106e874;
extern Atom4792* DAT_0106e878;
extern Atom4792* DAT_0106e87c;
extern Atom4792* DAT_0106e880;
extern Atom4792* DAT_0106e884;
extern Atom4792* DAT_0106e888;
extern Atom4792* DAT_0106e88c;
extern Atom4792* DAT_0106e890;
extern Atom4792* DAT_0106e894;
extern Atom4792* DAT_0106e898;
// pdb: FixedStrings::KillSDM | GlobalFunc.obj | fnv360_0822_retail, udata + bridge(call_gap_sim|udata), high
void FixedStrings_KillSDM() {
 delete DAT_0106e7c4;
 delete DAT_0106e7c8;
 delete DAT_0106e7cc;
 delete DAT_0106e7d0;
 delete DAT_0106e7dc;
 delete DAT_0106e7e0;
 delete DAT_0106e7e4;
 delete DAT_0106e7e8;
 delete DAT_0106e7ec;
 delete DAT_0106e7f0;
 delete DAT_0106e7f4;
 delete DAT_0106e7f8;
 delete DAT_0106e7fc;
 delete DAT_0106e800;
 delete DAT_0106e804;
 delete DAT_0106e808;
 delete DAT_0106e80c;
 delete DAT_0106e810;
 delete DAT_0106e814;
 delete DAT_0106e818;
 delete DAT_0106e81c;
 delete DAT_0106e820;
 delete DAT_0106e824;
 delete DAT_0106e828;
 delete DAT_0106e82c;
 delete DAT_0106e830;
 delete DAT_0106e834;
 delete DAT_0106e838;
 delete DAT_0106e83c;
 delete DAT_0106e840;
 delete DAT_0106e844;
 delete DAT_0106e848;
 delete DAT_0106e84c;
 delete DAT_0106e850;
 delete DAT_0106e854;
 delete DAT_0106e858;
 delete DAT_0106e85c;
 delete DAT_0106e860;
 delete DAT_0106e864;
 delete DAT_0106e868;
 delete DAT_0106e86c;
 delete DAT_0106e870;
 delete DAT_0106e874;
 delete DAT_0106e878;
 delete DAT_0106e87c;
 delete DAT_0106e880;
 delete DAT_0106e884;
 delete DAT_0106e888;
 delete DAT_0106e88c;
 delete DAT_0106e890;
 delete DAT_0106e894;
 delete DAT_0106e898;
}
}   // namespace f3m_004792a0

// @f3 0x00469a50 (community match, verified in this file)
#include <windows.h>
namespace f3m_00469a50 {
struct F3RefCounted {
    virtual ~F3RefCounted();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct FUN_00469a50 {
    unsigned int unk00, unk04, unk08;
    NiPointer<F3RefCounted> m_pReferencedObject;
    ~FUN_00469a50();
};
// pdb: NiTPointerListBase<NiTPointerAllocator<unsigned int>,BGSDecalEmitter *>::RemovePos | BGSDecalManager.obj | fnv360_1110_debug, call_seq, low
// pdb params: kPos
FUN_00469a50::~FUN_00469a50() {
    m_pReferencedObject = (F3RefCounted*)0;
}
}   // namespace f3m_00469a50

// @f3 0x00462020 (community match, verified in this file)
namespace f3m_00462020 {

namespace F3NativeAnimUpdate {
struct Reference;
struct Process;
struct Sequence;
struct MotionController;
struct Idle;
struct AnimData;
struct Vec3 {
    float x, y, z;
    // Fake match: forced inline; left to the inliner, the three scale calls of the second move-vector arm stay
    // real calls once the queue loop above takes its matching form.
    __forceinline Vec3 operator*(float f) const { Vec3 r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec3 operator-(const Vec3& o) const { Vec3 r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
};
struct UpdateData {
    float time;
    bool controllers, selective, rigid, transforms, updateBounds;
    UpdateData(float t, bool c) : time(t), controllers(c), selective(false),
        rigid(false), transforms(false), updateBounds(false) {}
};
struct Heap { void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
struct Vats { Reference* FUN_007cf350(); };
extern Vats DAT_0108d098;
extern int DAT_0108d0a0;
extern bool DAT_0107ba33;
extern Reference* DAT_0107a104;
extern unsigned int DAT_0106de2c, DAT_0106deb0;
extern float DAT_01090bac, DAT_0106de64;
extern const double DAT_00db7268;
extern const Vec3 DAT_0108ec68;
extern char DAT_01091f44, DAT_01091f54, DAT_00dbe590;
extern int DAT_00f5c78c[8];
struct SequenceKind {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int kind;
};
extern SequenceKind DAT_00f5ac8c[];
extern bool __cdecl FUN_0054b820(unsigned short);
extern bool __cdecl FUN_0054bf00(unsigned short);
extern int __cdecl TESAnimGroup_GetType(unsigned short);
extern void __cdecl FUN_00887da0(const char*, ...);
extern bool __cdecl FUN_0061ab20();

struct Process {
    virtual void unkV000();
    virtual void unkV004();
    virtual void unkV008();
    virtual void unkV00c();
    virtual void unkV010();
    virtual void unkV014();
    virtual void unkV018();
    virtual void unkV01c();
    virtual void unkV020();
    virtual void unkV024();
    virtual void unkV028();
    virtual void unkV02c();
    virtual void unkV030();
    virtual void unkV034();
    virtual void unkV038();
    virtual void unkV03c();
    virtual void unkV040();
    virtual void unkV044();
    virtual void unkV048();
    virtual void unkV04c();
    virtual void unkV050();
    virtual void unkV054();
    virtual void unkV058();
    virtual void unkV05c();
    virtual void unkV060();
    virtual void unkV064();
    virtual void unkV068();
    virtual void unkV06c();
    virtual void unkV070();
    virtual void unkV074();
    virtual void unkV078();
    virtual void unkV07c();
    virtual void unkV080();
    virtual void unkV084();
    virtual void unkV088();
    virtual void unkV08c();
    virtual void unkV090();
    virtual void unkV094();
    virtual void unkV098();
    virtual void unkV09c();
    virtual void unkV0a0();
    virtual void unkV0a4();
    virtual void unkV0a8();
    virtual void unkV0ac();
    virtual void unkV0b0();
    virtual void unkV0b4();
    virtual void unkV0b8();
    virtual void unkV0bc();
    virtual void unkV0c0();
    virtual void unkV0c4();
    virtual void unkV0c8();
    virtual void unkV0cc();
    virtual void unkV0d0();
    virtual void unkV0d4();
    virtual void unkV0d8();
    virtual void unkV0dc();
    virtual void unkV0e0();
    virtual void unkV0e4();
    virtual void unkV0e8();
    virtual void unkV0ec();
    virtual void unkV0f0();
    virtual void unkV0f4();
    virtual void unkV0f8();
    virtual void unkV0fc();
    virtual void unkV100();
    virtual void unkV104();
    virtual void unkV108();
    virtual void unkV10c();
    virtual void unkV110();
    virtual void unkV114();
    virtual void unkV118();
    virtual void unkV11c();
    virtual void unkV120();
    virtual void unkV124();
    virtual void unkV128();
    virtual void unkV12c();
    virtual void unkV130();
    virtual void unkV134();
    virtual void unkV138();
    virtual void unkV13c();
    virtual void unkV140();
    virtual void unkV144();
    virtual void unkV148();
    virtual void unkV14c();
    virtual void unkV150();
    virtual void unkV154();
    virtual void unkV158();
    virtual void unkV15c();
    virtual void unkV160();
    virtual void unkV164();
    virtual void unkV168();
    virtual void unkV16c();
    virtual void unkV170();
    virtual void unkV174();
    virtual void unkV178();
    virtual void unkV17c();
    virtual void unkV180();
    virtual void unkV184();
    virtual void unkV188();
    virtual void unkV18c();
    virtual void unkV190();
    virtual void unkV194();
    virtual void unkV198();
    virtual void unkV19c();
    virtual void unkV1a0();
    virtual void unkV1a4();
    virtual void unkV1a8();
    virtual void unkV1ac();
    virtual void unkV1b0();
    virtual void unkV1b4();
    virtual void unkV1b8();
    virtual void unkV1bc();
    virtual void unkV1c0();
    virtual void unkV1c4();
    virtual void unkV1c8();
    virtual void unkV1cc();
    virtual void unkV1d0();
    virtual void unkV1d4();
    virtual void unkV1d8();
    virtual void unkV1dc();
    virtual void unkV1e0();
    virtual void unkV1e4();
    virtual void unkV1e8();
    virtual void unkV1ec();
    virtual void unkV1f0();
    virtual void unkV1f4();
    virtual void unkV1f8();
    virtual void unkV1fc();
    virtual void unkV200();
    virtual void unkV204();
    virtual void unkV208();
    virtual void unkV20c();
    virtual void unkV210();
    virtual void unkV214();
    virtual void unkV218();
    virtual void unkV21c();
    virtual void unkV220();
    virtual void unkV224();
    virtual void unkV228();
    virtual void unkV22c();
    virtual void unkV230();
    virtual void unkV234();
    virtual void unkV238();
    virtual void unkV23c();
    virtual void unkV240();
    virtual void unkV244();
    virtual void unkV248();
    virtual void unkV24c();
    virtual void unkV250();
    virtual void unkV254();
    virtual void unkV258();
    virtual void unkV25c();
    virtual void unkV260();
    virtual void unkV264();
    virtual void unkV268();
    virtual void unkV26c();
    virtual void unkV270();
    virtual void unkV274();
    virtual void unkV278();
    virtual void unkV27c();
    virtual void unkV280();
    virtual void unkV284();
    virtual void unkV288();
    virtual void unkV28c();
    virtual void unkV290();
    virtual void unkV294();
    virtual void unkV298();
    virtual void unkV29c();
    virtual void unkV2a0();
    virtual void unkV2a4();
    virtual void unkV2a8();
    virtual void unkV2ac();
    virtual void unkV2b0();
    virtual void unkV2b4();
    virtual void unkV2b8();
    virtual void unkV2bc();
    virtual void unkV2c0();
    virtual void unkV2c4();
    virtual void unkV2c8();
    virtual void unkV2cc();
    virtual void unkV2d0();
    virtual void unkV2d4();
    virtual void unkV2d8();
    virtual void unkV2dc();
    virtual void unkV2e0();
    virtual void unkV2e4();
    virtual void unkV2e8();
    virtual void unkV2ec();
    virtual void unkV2f0();
    virtual void unkV2f4();
    virtual void unkV2f8();
    virtual void unkV2fc();
    virtual void unkV300();
    virtual void unkV304();
    virtual void unkV308();
    virtual void unkV30c();
    virtual void unkV310();
    virtual void unkV314();
    virtual void unkV318();
    virtual void unkV31c();
    virtual void unkV320();
    virtual void unkV324();
    virtual void unkV328();
    virtual void unkV32c();
    virtual void unkV330();
    virtual void unkV334();
    virtual void unkV338();
    virtual void unkV33c();
    virtual void unkV340();
    virtual void unkV344();
    virtual void unkV348();
    virtual void unkV34c();
    virtual void unkV350();
    virtual void unkV354();
    virtual void unkV358();
    virtual void unkV35c();
    virtual void unkV360();
    virtual void unkV364();
    virtual void unkV368();
    virtual void unkV36c();
    virtual void unkV370();
    virtual void unkV374();
    virtual void unkV378();
    virtual void unkV37c();
    virtual void unkV380();
    virtual void unkV384();
    virtual void unkV388();
    virtual void unkV38c();
    virtual void unkV390();
    virtual void unkV394();
    virtual void unkV398();
    virtual void unkV39c();
    virtual void unkV3a0();
    virtual void unkV3a4();
    virtual void unkV3a8();
    virtual void unkV3ac();
    virtual void unkV3b0();
    virtual void unkV3b4();
    virtual void unkV3b8();
    virtual void unkV3bc();
    virtual void unkV3c0();
    virtual void unkV3c4();
    virtual void unkV3c8();
    virtual void unkV3cc();
    virtual void unkV3d0();
    virtual void unkV3d4();
    virtual void unkV3d8();
    virtual void unkV3dc();
    virtual void unkV3e0();
    virtual void unkV3e4();
    virtual void unkV3e8();
    virtual void unkV3ec();
    virtual void unkV3f0();
    virtual void unkV3f4();
    virtual void unkV3f8();
    virtual void unkV3fc();
    virtual void unkV400();
    virtual void unkV404();
    virtual void unkV408();
    virtual void unkV40c();
    virtual void unkV410();
    virtual void unkV414();
    virtual void unkV418();
    virtual void unkV41c();
    virtual void unkV420();
    virtual void unkV424();
    virtual void unkV428();
    virtual void unkV42c();
    virtual void unkV430();
    virtual void unkV434();
    virtual void unkV438();
    virtual void unkV43c();
    virtual void unkV440();
    virtual void unkV444();
    virtual void unkV448();
    virtual void unkV44c();
    virtual void unkV450();
    virtual void unkV454();
    virtual void unkV458();
    virtual void unkV45c();
    virtual void unkV460();
    virtual void unkV464();
    virtual void unkV468();
    virtual void unkV46c();
    virtual void unkV470();
    virtual void unkV474();
    virtual void unkV478();
    virtual void unkV47c();
    virtual void unkV480();
    virtual void unkV484();
    virtual void unkV488();
    virtual void unkV48c();
    virtual void unkV490();
    virtual void unkV494();
    virtual void unkV498();
    virtual void unkV49c();
    virtual void unkV4a0();
    virtual void unkV4a4();
    virtual void unkV4a8();
    virtual void unkV4ac();
    virtual void unkV4b0();
    virtual void unkV4b4();
    virtual void unkV4b8();
    virtual void unkV4bc();
    virtual void unkV4c0();
    virtual void unkV4c4();
    virtual void unkV4c8();
    virtual void unkV4cc();
    virtual void unkV4d0();
    virtual void unkV4d4();
    virtual void unkV4d8();
    virtual void unkV4dc();
    virtual void unkV4e0();
    virtual void unkV4e4();
    virtual void unkV4e8();
    virtual void unkV4ec();
    virtual void unkV4f0();
    virtual void unkV4f4();
    virtual void unkV4f8();
    virtual void unkV4fc();
    virtual void unkV500();
    virtual void unkV504();
    virtual void unkV508();
    virtual void unkV50c();
    virtual void unkV510();
    virtual void unkV514();
    virtual void unkV518();
    virtual void unkV51c();
    virtual void unkV520();
    virtual void unkV524();
    virtual void unkV528();
    virtual void unkV52c();
    virtual void unkV530();
    virtual void unkV534();
    virtual void unkV538();
    virtual void unkV53c();
    virtual void unkV540();
    virtual void unkV544();
    virtual void unkV548();
    virtual void unkV54c();
    virtual void unkV550();
    virtual void unkV554();
    virtual void unkV558();
    virtual void unkV55c();
    virtual void unkV560();
    virtual void unkV564();
    virtual void unkV568();
    virtual void unkV56c();
    virtual void unkV570();
    virtual void unkV574();
    virtual void unkV578();
    virtual void unkV57c();
    virtual void unkV580();
    virtual void unkV584();
    virtual void unkV588();
    virtual void unkV58c();
    virtual void unkV590();
    virtual void unkV594();
    virtual void unkV598();
    virtual void unkV59c();
    virtual void unkV5a0();
    virtual void unkV5a4();
    virtual void unkV5a8();
    virtual void unkV5ac();
    virtual void unkV5b0();
    virtual void unkV5b4();
    virtual void unkV5b8();
    virtual void unkV5bc();
    virtual void unkV5c0();
    virtual void unkV5c4();
    virtual void unkV5c8();
    virtual void unkV5cc();
    virtual void unkV5d0();
    virtual void unkV5d4();
    virtual void unkV5d8();
    virtual void unkV5dc();
    virtual void unkV5e0();
    virtual void unkV5e4();
    virtual void unkV5e8();
    virtual void unkV5ec();
    virtual void unkV5f0();
    virtual void unkV5f4();
    virtual void unkV5f8();
    virtual void unkV5fc();
    virtual void unkV600();
    virtual void unkV604();
    virtual void unkV608();
    virtual void QueueAction(int);
    virtual void unkV610();
    virtual void unkV614();
    virtual void unkV618();
    virtual void unkV61c();
    virtual void unkV620();
    virtual void unkV624();
    virtual void unkV628();
    virtual void unkV62c();
    virtual void unkV630();
    virtual void unkV634();
    virtual void unkV638();
    virtual void unkV63c();
    virtual void unkV640();
    virtual void unkV644();
    virtual void unkV648();
    virtual void unkV64c();
    virtual void unkV650();
    virtual void unkV654();
    virtual void unkV658();
    virtual void unkV65c();
    virtual void unkV660();
    virtual void unkV664();
    virtual void unkV668();
    virtual void unkV66c();
    virtual void unkV670();
    virtual void unkV674();
    virtual void unkV678();
    virtual void unkV67c();
    virtual void unkV680();
    virtual void unkV684();
    virtual void unkV688();
    virtual void unkV68c();
    virtual void unkV690();
    virtual void unkV694();
    virtual void unkV698();
    virtual void unkV69c();
    virtual void unkV6a0();
    virtual void unkV6a4();
    virtual void unkV6a8();
    virtual void unkV6ac();
    virtual void unkV6b0();
    virtual void unkV6b4();
    virtual void unkV6b8();
    virtual void unkV6bc();
    virtual void unkV6c0();
    virtual void unkV6c4();
    virtual void unkV6c8();
    virtual void unkV6cc();
    virtual void unkV6d0();
    virtual bool HoldsWeapon();
};
struct Reference {
    virtual void unkV000();
    virtual void unkV004();
    virtual void unkV008();
    virtual void unkV00c();
    virtual void unkV010();
    virtual void unkV014();
    virtual void unkV018();
    virtual void unkV01c();
    virtual void unkV020();
    virtual void unkV024();
    virtual void unkV028();
    virtual void unkV02c();
    virtual void unkV030();
    virtual void unkV034();
    virtual void unkV038();
    virtual void unkV03c();
    virtual void unkV040();
    virtual void unkV044();
    virtual void unkV048();
    virtual void unkV04c();
    virtual void unkV050();
    virtual void unkV054();
    virtual void unkV058();
    virtual void unkV05c();
    virtual void unkV060();
    virtual void unkV064();
    virtual void unkV068();
    virtual void unkV06c();
    virtual void unkV070();
    virtual void unkV074();
    virtual void unkV078();
    virtual void unkV07c();
    virtual void unkV080();
    virtual void unkV084();
    virtual void unkV088();
    virtual void unkV08c();
    virtual void unkV090();
    virtual void unkV094();
    virtual void unkV098();
    virtual void unkV09c();
    virtual void unkV0a0();
    virtual void unkV0a4();
    virtual void unkV0a8();
    virtual void unkV0ac();
    virtual void unkV0b0();
    virtual void unkV0b4();
    virtual void unkV0b8();
    virtual void unkV0bc();
    virtual void unkV0c0();
    virtual void unkV0c4();
    virtual void unkV0c8();
    virtual void unkV0cc();
    virtual void unkV0d0();
    virtual void unkV0d4();
    virtual void unkV0d8();
    virtual void unkV0dc();
    virtual void unkV0e0();
    virtual void unkV0e4();
    virtual void unkV0e8();
    virtual void unkV0ec();
    virtual void unkV0f0();
    virtual void unkV0f4();
    virtual void unkV0f8();
    virtual void unkV0fc();
    virtual bool IsActor();
    virtual void unkV104();
    virtual void unkV108();
    virtual void unkV10c();
    virtual void unkV110();
    virtual void unkV114();
    virtual void unkV118();
    virtual void unkV11c();
    virtual void unkV120();
    virtual void unkV124();
    virtual void unkV128();
    virtual void unkV12c();
    virtual const char* GetName();
    virtual void unkV134();
    virtual void unkV138();
    virtual void unkV13c();
    virtual void unkV140();
    virtual void unkV144();
    virtual void unkV148();
    virtual void unkV14c();
    virtual void unkV150();
    virtual void unkV154();
    virtual void unkV158();
    virtual void unkV15c();
    virtual void unkV160();
    virtual void unkV164();
    virtual void unkV168();
    virtual void unkV16c();
    virtual void unkV170();
    virtual void unkV174();
    virtual void unkV178();
    virtual void unkV17c();
    virtual void unkV180();
    virtual void unkV184();
    virtual void unkV188();
    virtual void unkV18c();
    virtual void unkV190();
    virtual void unkV194();
    virtual void unkV198();
    virtual void unkV19c();
    virtual void unkV1a0();
    virtual void unkV1a4();
    virtual void unkV1a8();
    virtual void unkV1ac();
    virtual void unkV1b0();
    virtual void unkV1b4();
    virtual void unkV1b8();
    virtual void unkV1bc();
    virtual void unkV1c0();
    virtual void unkV1c4();
    virtual void unkV1c8();
    virtual void unkV1cc();
    virtual void unkV1d0();
    virtual void unkV1d4();
    virtual void unkV1d8();
    virtual void unkV1dc();
    virtual void unkV1e0();
    virtual void unkV1e4();
    virtual void unkV1e8();
    virtual void unkV1ec();
    virtual void unkV1f0();
    virtual void unkV1f4();
    virtual void unkV1f8();
    virtual void unkV1fc();
    virtual void unkV200();
    virtual void unkV204();
    virtual void unkV208();
    virtual void unkV20c();
    virtual void unkV210();
    virtual void unkV214();
    virtual void unkV218();
    virtual void unkV21c();
    virtual void unkV220();
    virtual void unkV224();
    virtual void unkV228();
    virtual void unkV22c();
    virtual void unkV230();
    virtual void unkV234();
    virtual void unkV238();
    virtual void unkV23c();
    virtual void unkV240();
    virtual void unkV244();
    virtual void unkV248();
    virtual void unkV24c();
    virtual void unkV250();
    virtual void unkV254();
    virtual void unkV258();
    virtual void unkV25c();
    virtual void unkV260();
    virtual void unkV264();
    virtual void unkV268();
    virtual void unkV26c();
    virtual void unkV270();
    virtual void unkV274();
    virtual void unkV278();
    virtual void unkV27c();
    virtual void unkV280();
    virtual void unkV284();
    virtual void unkV288();
    virtual void unkV28c();
    virtual void unkV290();
    virtual void unkV294();
    virtual void unkV298();
    virtual void unkV29c();
    virtual void unkV2a0();
    virtual void unkV2a4();
    virtual void unkV2a8();
    virtual void unkV2ac();
    virtual void unkV2b0();
    virtual void unkV2b4();
    virtual void unkV2b8();
    virtual void unkV2bc();
    virtual void unkV2c0();
    virtual void unkV2c4();
    virtual void unkV2c8();
    virtual void unkV2cc();
    virtual void unkV2d0();
    virtual void unkV2d4();
    virtual void unkV2d8();
    virtual void unkV2dc();
    virtual void unkV2e0();
    virtual void unkV2e4();
    virtual void unkV2e8();
    virtual void unkV2ec();
    virtual void unkV2f0();
    virtual void unkV2f4();
    virtual void unkV2f8();
    virtual void unkV2fc();
    virtual void unkV300();
    virtual void unkV304();
    virtual void unkV308();
    virtual void unkV30c();
    virtual void unkV310();
    virtual void unkV314();
    virtual void unkV318();
    virtual void unkV31c();
    virtual void unkV320();
    virtual void unkV324();
    virtual void unkV328();
    virtual void unkV32c();
    virtual void unkV330();
    virtual void unkV334();
    virtual void unkV338();
    virtual void unkV33c();
    virtual void unkV340();
    virtual void unkV344();
    virtual void unkV348();
    virtual void unkV34c();
    virtual void unkV350();
    virtual void unkV354();
    virtual void unkV358();
    virtual void unkV35c();
    virtual void unkV360();
    virtual void unkV364();
    virtual void unkV368();
    virtual void unkV36c();
    virtual void unkV370();
    virtual void unkV374();
    virtual void unkV378();
    virtual void unkV37c();
    virtual void unkV380();
    virtual void unkV384();
    virtual void unkV388();
    virtual void unkV38c();
    virtual void unkV390();
    virtual void unkV394();
    virtual void unkV398();
    virtual void unkV39c();
    virtual void unkV3a0();
    virtual void unkV3a4();
    virtual void unkV3a8();
    virtual void unkV3ac();
    virtual void unkV3b0();
    virtual void unkV3b4();
    virtual void unkV3b8();
    virtual void unkV3bc();
    virtual void unkV3c0();
    virtual void unkV3c4();
    virtual void unkV3c8();
    virtual void unkV3cc();
    virtual void unkV3d0();
    virtual void unkV3d4();
    virtual void unkV3d8();
    virtual void unkV3dc();
    virtual void unkV3e0();
    virtual void unkV3e4();
    virtual void unkV3e8();
    virtual void unkV3ec();
    virtual void unkV3f0();
    virtual void unkV3f4();
    virtual void unkV3f8();
    virtual void unkV3fc();
    virtual void unkV400();
    virtual void unkV404();
    virtual void unkV408();
    virtual void unkV40c();
    virtual void unkV410();
    virtual void unkV414();
    virtual void unkV418();
    virtual void unkV41c();
    virtual void unkV420();
    virtual void unkV424();
    virtual void unkV428();
    virtual void unkV42c();
    virtual void unkV430();
    virtual void unkV434();
    virtual void unkV438();
    virtual void unkV43c();
    virtual void unkV440();
    virtual void unkV444();
    virtual void unkV448();
    virtual void unkV44c();
    virtual void unkV450();
    virtual void unkV454();
    virtual void unkV458();
    virtual void unkV45c();
    virtual void unkV460();
    virtual void unkV464();
    virtual void unkV468();
    virtual void unkV46c();
    virtual void unkV470();
    virtual void unkV474();
    virtual void unkV478();
    virtual void unkV47c();
    virtual void unkV480();
    virtual void unkV484();
    virtual void unkV488();
    virtual void unkV48c();
    virtual void unkV490();
    virtual void unkV494();
    virtual void unkV498();
    virtual void unkV49c();
    virtual void NotifyPendingGroup(unsigned short,int);
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
    Process* process;
    Process* GetProcess() const { return process; }
    bool FUN_006f6c70();
    void FUN_006ff040(int, Sequence*);
    int FUN_006f7370();
    void Actor_SetHavokWeapon();
    unsigned int FUN_006f58b0();
    unsigned short Actor_GetAnimGroup(int,int,int,int);
    float FUN_004e6d80();
    AnimData* FUN_0076cce0(bool);
};
struct Group {
    unsigned int unk00, unk04;
    unsigned char sectionPriority[8];
    unsigned short code;
    double FUN_0054bb40(int);
    bool FUN_0054bdd0();
    int FUN_0054bef0();
    Vec3 FUN_0054bd40();
    void FUN_0054bfa0(Reference*,float,float,Sequence*);
    double GetActionTime(int i) { return FUN_0054bb40(i); }
    bool IsReloadStart() { return FUN_0054b820(code); }
    bool IsReloadLoop() { return FUN_0054bf00(code); }
    bool HasMoveData() { return FUN_0054bdd0(); }
    int GetGroupType() { return FUN_0054bef0(); }
    Vec3 GetMoveVector() { return FUN_0054bd40(); }
    unsigned char GetSectionPriority(int i) { return sectionPriority[i]; }
};
struct Rtti { const char* name; const Rtti* parent; };
struct Interpolator {
    virtual void unkV000();
    virtual void unkV004();
    virtual const Rtti* GetRtti();
};
struct InterpolatorArray { Interpolator* first; };
struct Sequence {
    unsigned int unk00;
    unsigned int unk04;
    const char* name;
    unsigned int unk0c;
    unsigned int unk10;
    InterpolatorArray* interpolators;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    void* owner;
    float startKey, timeOffset, endKey;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    int state;
    float lastTime;
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
    Group* group;
    void FUN_00424390();
    void FUN_008ac830(float,int);
    float FUN_0049cac0(float);
    unsigned char FUN_0049caf0(const char*,int);
    int GetState() const { return state; }
    Group* GetAnimGroup() const { return group; }
    void* GetOwner() const { return owner; }
    const char* GetName() const { return name; }
    float GetLastTime(int) const { return lastTime - timeOffset; }
    float GetEndKeyTime() const { return endKey; }
    float GetBeginKeyTime() const { return timeOffset; }
    void SetTime(float t) { FUN_008ac830(t, 0); }
    float GetEaseTime(float t) { return FUN_0049cac0(t); }
    Interpolator* GetInterpolator(int i) const { return interpolators[i].first; }
    unsigned char GetPriority(const char* n, int i) { return FUN_0049caf0(n, i); }
};
template <class T> struct List {
    T item; List* next;
    void FUN_006c8220();
    void FUN_00421610(T*);
    bool IsEmpty() const { return !next && !item; }
    T& GetItem() { return item; }
    List* GetNext() const { return next; }
    void Remove(const T& t) { FUN_00421610(const_cast<T*>(&t)); }
    void RemoveHead() {
        List* node = next;
        if (node) {
            next = node->next;
            item = node->item;
            node->next = 0;
            node->FUN_006c8220();
            DAT_01090a78.FUN_0086ba60(node);
        } else {
            item = 0;
        }
    }
};
template <class T> __declspec(noinline) void List<T>::FUN_00421610(T* key)
{
    if (!*key)
        return;
    if (IsEmpty())
        return;
    List* cur = this;
    List* prev = this;
    while (cur->item != *key) {
        prev = cur;
        cur = cur->next;
        if (!cur)
            return;
    }
    if (cur == this) {
        RemoveHead();
    } else {
        prev->next = cur->next;
        cur->next = 0;
        cur->FUN_006c8220();
        DAT_01090a78.FUN_0086ba60(cur);
    }
}
struct TimedEntry { void* target; float remaining; };
struct Idle {
    virtual void unkV000();
    virtual void Destroy();
    volatile long references;
    int state, kind, unk10, unk14;
    Sequence* sequence;
    unsigned int unk1c, unk20, unk24, unk28;
    Reference* owner; unsigned int unk30; Reference* actor;
    Sequence* GetIdleSequence() const { return sequence; }
    Reference* GetIdleForm() const { return owner; }
    int IsFinished() const { return state; }
    int GetIdleState() const { return kind; }
    void SetIdleState(int s) { state = s; }
    void Update(AnimData* anim);
    void DecRefCount() { if (InterlockedDecrement(&references) == 0) Destroy(); }
    void IncRefCount() { InterlockedIncrement(&references); }
};
template <class T> struct Ptr {
    T* p;
    operator T*() const { return p; }
    T* operator->() const { return p; }
    Ptr& operator=(T* n) {
        if (p != n) {
            if (p)
                p->DecRefCount();
            p = n;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};
struct InterpolatorBlend {
    unsigned int unk00, unk04, unk08, unk0c;
    signed char priority;
    int GetHighPriority() const { return priority; }
};
struct MotionController {
    virtual void unkV000();
    virtual void unkV004();
    virtual void unkV008();
    virtual void unkV00c();
    virtual void unkV010();
    virtual void unkV014();
    virtual void unkV018();
    virtual void unkV01c();
    virtual void unkV020();
    virtual void unkV024();
    virtual void unkV028();
    virtual void unkV02c();
    virtual void unkV030();
    virtual void unkV034();
    virtual void unkV038();
    virtual void unkV03c();
    virtual void unkV040();
    virtual void unkV044();
    virtual void unkV048();
    virtual void unkV04c();
    virtual void unkV050();
    virtual void unkV054();
    virtual void unkV058();
    virtual void unkV05c();
    virtual void unkV060();
    virtual void unkV064();
    virtual void unkV068();
    virtual void unkV06c();
    virtual void unkV070();
    virtual void unkV074();
    virtual void unkV078();
    virtual void unkV07c();
    virtual void unkV080();
    virtual void unkV084();
    virtual void unkV088();
    virtual void unkV08c();
    virtual void unkV090();
    virtual void unkV094();
    virtual void unkV098();
    virtual void unkV09c();
    virtual void unkV0a0();
    virtual void unkV0a4();
    virtual void unkV0a8();
    virtual void unkV0ac();
    virtual void unkV0b0();
    virtual void unkV0b4();
    virtual void unkV0b8();
    virtual void unkV0bc();
    virtual void unkV0c0();
    virtual InterpolatorBlend* GetBlend(int);
};
struct RootNode {
    unsigned int unk00, unk04;
    const char* name;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned char flags;
    void FUN_008264c0(UpdateData*);
    void FUN_0049dd70(float,RootNode*);
    MotionController* FUN_00825200(const void*);
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    Vec3 translation;
};
struct SequenceBase {
    virtual void unkV000();
    virtual void unkV004();
    virtual void unkV008();
    virtual void unkV00c();
    virtual Sequence* GetSequence(int);
};
struct MapItem { MapItem* next; unsigned short key; SequenceBase* value; };
struct SequenceMap {
    virtual void unkV000();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short a, unsigned short b);
    unsigned int hashSize;
    MapItem** table;
    bool FUN_0045c6e0(unsigned short key, SequenceBase*& value);
};
__declspec(noinline) bool SequenceMap::FUN_0045c6e0(unsigned short key, SequenceBase*& value)
{
    unsigned int index = KeyToHashIndex(key);
    MapItem* entry = table[index];
    while (entry) {
        if (IsKeysEqual(key, entry->key)) {
            value = entry->value;
            return true;
        }
        entry = entry->next;
    }
    return false;
}
inline float GetTimeMult() { return DAT_01090bac; }
struct AnimData {
    unsigned char flags, unk01, unk02, unk03;
    Reference* attached;
    RootNode* header;
    RootNode* root;
    float deltaX, deltaY;
    unsigned int unk18;
    Vec3 rootTranslation;
    RootNode* bone[8];
    unsigned int unk48;
    unsigned short currentGroup[8];
    int action[8];
    int targetLoops[8];
    unsigned short pendingGroup[8];
    int nextLoops[8];
    signed char state; unsigned char unkcd, unkce, unkcf;
    float time;
    unsigned int unkd4, unkd8;
    SequenceMap* sequenceMap;
    Sequence* sections[8];
    Sequence* previousSequence;
    List<Sequence*> queue;
    float movementRate, combatRate;
    bool skipBlend; unsigned char unk115;
    unsigned short queuedGroup;
    Idle* currentIdle;
    unsigned int unk11c;
    Ptr<Idle> idles[2];
    List<TimedEntry*> timers;
    void FUN_00461a70(Sequence*,bool);
    bool FUN_0045c980();
    void Animation_PlayGroup(unsigned short,int,int,int);
    void FUN_0045feb0(Ptr<Idle>&);
    void FUN_00460af0(unsigned short,int);
    void FUN_0045e4c0(int,bool);
    void FUN_0045dca0();
    void FUN_00460090(bool,bool);
    void FUN_00462020(Reference*,float,float);
    Sequence* GetSectionSequence(int i) const {
        switch (i) { case 0x14: i=1; break; case 0x15: i=4; break; }
        return sections[i];
    }
    float GetSequenceTime(Sequence* s) const { return s->lastTime + time; }
    void ResetMovement(bool b) { if (b) flags |= 1; else flags &= ~1; }
    void UpdateAccumRoot(float t, Vec3* translate, bool) {
        if (root)
            root->translation = *translate;
        header->FUN_0049dd70(t, root);
        if (root) {
            if (translate)
                *translate = root->translation;
            root->translation = DAT_0108ec68;
        }
    }
};
inline void Idle::Update(AnimData* anim)
{
    if (state == 2 && (!sequence || sequence->GetState() == 0)) {
        state = 3;
        if (actor && actor->FUN_006f7370() == 0xd)
            actor->FUN_006ff040(-1, 0);
        if (kind == 2 || kind == 3)
            anim->FUN_00460090(true, false);
    }
}

bool AnimData::FUN_0045c980()
{
    return !queue.IsEmpty();
}

// pdb: Animation::Update | Animation.obj | fnv360_0822_retail, ustr, medium
// pdb params: ownerObject, fSecondsPassed, forceTime
void AnimData::FUN_00462020(Reference* ref, float delta, float requestedTime)
{
    if (FUN_0045c980()) {
        // Fake match: the flag and do-while keep this loop top-tested (one budget test, a jump back after the
        // increment); a for loop with a break compiles bottom-tested with the increment folded into the test.
        bool more = true;
        do {
            if (DAT_0106de2c >= DAT_0106deb0)
                break;
            Sequence* item = queue.GetItem();
            FUN_00461a70(item, false);
            item->FUN_00424390();
            queue.RemoveHead();
            if (FUN_0045c980())
                DAT_0106de2c++;
            else
                more = false;
        } while (more);
    } else if (queuedGroup != 0xff) {
        Sequence* weapon = sections[4];
        switch (action[4]) {
        case 1:
        case 2:
            if (weapon && !weapon->GetAnimGroup()->IsReloadStart() && weapon->GetAnimGroup()->IsReloadLoop())
                break;
        case 3:
            if (attached->FUN_006f6c70()) {
                Animation_PlayGroup(queuedGroup, 1, -1, -1);
                if (ref == DAT_0107a104)
                    DAT_0107a104->NotifyPendingGroup(queuedGroup, 1);
                ref->FUN_006ff040(9, sections[4]);
            }
        default:
            queuedGroup = 0xff;
        }
    }

    if (!timers.IsEmpty()) {
        List<TimedEntry*>* node = &timers;
        while (node) {
            TimedEntry* entry = node->GetItem();
            entry->remaining = entry->remaining - delta;
            if (entry->remaining <= 0.0f) {
                if (node == &timers)
                    node = 0;
                else
                    node = node->GetNext();
                timers.Remove(entry);
                DAT_01090a78.FUN_0086ba60(entry);
                if (!node && !timers.IsEmpty())
                    node = &timers;
            } else {
                node = node->GetNext();
            }
        }
    }

    Reference* actor = 0;
    if (ref && ref->IsActor())
        actor = ref;

    for (int idleIndex = 0; idleIndex < 2; idleIndex++) {
        if (idles[idleIndex]) {
            if (idles[idleIndex]->GetIdleSequence()) {
                if (idles[idleIndex]->GetIdleSequence()->GetState() == 1) {
                    FUN_00887da0(&DAT_00dbe590, attached->GetName(), idles[idleIndex]->GetIdleForm()->GetName(),
                                 idles[idleIndex]->GetIdleSequence()->GetName());
                    idles[idleIndex] = 0;
                } else if (idles[idleIndex]->GetIdleSequence()->GetState() == 0) {
                    FUN_0045feb0(idles[idleIndex]);
                }
            } else if (idles[idleIndex]->IsFinished()) {
                FUN_0045feb0(idles[idleIndex]);
            }
        }
    }

    if (!header)
        return;

    ResetMovement(false);
    deltaX = 0.0f;
    deltaY = 0.0f;

    if (state == 0x14) {
        float updateTime = (requestedTime == -1.0f) ? time : requestedTime;
        UpdateData data(updateTime, false);
        header->FUN_008264c0(&data);
        return;
    }

    float step = delta;
    int groupType = 0xff;
    int nextType;
    Sequence* previousSections[8];
    float previousTimes[8];
    int i;
    for (i = 0; i < 8; i++) {
        groupType = TESAnimGroup_GetType(currentGroup[i]);
        nextType = TESAnimGroup_GetType(pendingGroup[i]);
        if (groupType == 0xff && nextType != 0xff) {
            targetLoops[i] = nextLoops[i];
            FUN_00460af0(pendingGroup[i], -1);
            pendingGroup[i] = nextType = 0xff;
            groupType = TESAnimGroup_GetType(currentGroup[i]);
        }
        Sequence* forward = GetSectionSequence(i);
        previousSections[i] = forward;
        previousTimes[i] = 0.0f;
        if (groupType == 0xff || !forward)
            continue;
        previousTimes[i] = forward->FUN_0049cac0(time);
    }

    if (requestedTime != -1.0f) {
        time = requestedTime;
        UpdateData data(time, true);
        header->FUN_008264c0(&data);
        return;
    }

    time = time + step;

    for (i = 0; i < 8; i++) {
        Sequence* seq = GetSectionSequence(i);
        bool update = true;
        groupType = TESAnimGroup_GetType(currentGroup[i]);
        nextType = TESAnimGroup_GetType(pendingGroup[i]);
        if (groupType == 0xff || !seq)
            continue;
        if (i == 3)
            update = false;
        switch (state) {
        case 0x17:
            if (i != 7 && i != 0)
                update = false;
            break;
        case 0x14:
            update = false;
            break;
        case 0x15:
            switch (i) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                update = false;
            }
            break;
        case 4:
            switch (i) {
            case 4:
            case 5:
            case 6:
                update = false;
            }
            break;
        default:
            if (i == state)
                update = false;
        }

        if (!update) {
            seq->SetTime(seq->GetLastTime(0) - step);
        } else if (seq->GetState() == 1) {
            if (groupType >= 3 && groupType <= 0x10)
                seq->SetTime(seq->GetLastTime(0) + (step * movementRate - step));
            else if (groupType >= 0x18 && groupType <= 0x8a)
                seq->SetTime(seq->GetLastTime(0) + (step * combatRate - step));
        }

        if (update && seq->GetState() == 1) {
            switch (DAT_00f5ac8c[groupType].kind) {
            case 5:
                if (action[i] < 4 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i] + 1))
                    action[i] = action[i] + 1;
                if (action[i] == 4 && GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(4)) {
                    if (nextType != 0xff) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    } else {
                        FUN_0045e4c0(i, false);
                    }
                }
                break;
            case 3:
            case 4:
            case 6:
                if (action[i] < 2 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i] + 1))
                    action[i] = action[i] + 1;
                if (action[i] == 2 && GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(2)) {
                    if (nextType != 0xff) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    } else {
                        FUN_0045e4c0(i, false);
                        if (actor && (DAT_00f5ac8c[groupType].kind == 3 || DAT_00f5ac8c[groupType].kind == 4)) {
                            Process* process = actor->process;
                            if (process) {
                                if (actor != DAT_0107a104)
                                    process->QueueAction(0x4000);
                                else
                                    actor->Actor_SetHavokWeapon();
                            }
                        }
                    }
                }
                break;
            case 7:
                if (action[i] < 4 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i] + 1))
                    action[i] = action[i] + 1;
                if (action[i] == 4 && GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(4)) {
                    if (nextType != 0xff) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    } else {
                        FUN_0045e4c0(i, false);
                    }
                }
                break;
            case 8:
                if (action[i] < 3 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i] + 1))
                    action[i] = action[i] + 1;
                if (action[i] == 3 && GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(3)) {
                    if (nextType != 0xff) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    } else {
                        FUN_0045e4c0(i, false);
                    }
                }
                break;
            case 9:
                if (action[i] < 3 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i] + 1))
                    action[i] = action[i] + 1;
                if (action[i] == 2 && actor && actor->GetProcess() &&
                    ((actor->GetProcess()->HoldsWeapon() && actor->FUN_006f7370() == 2) ||
                     (attached == DAT_0107a104 && DAT_0108d0a0 == 4 && DAT_0108d098.FUN_007cf350())) &&
                    previousTimes[i] <= seq->GetAnimGroup()->FUN_0054bb40(2)) {
                    float loopTime = seq->GetAnimGroup()->FUN_0054bb40(2) - seq->GetAnimGroup()->FUN_0054bb40(1);
                    while (GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i])) {
                        seq->SetTime(seq->GetLastTime(0) - loopTime);
                        previousTimes[i] = previousTimes[i] - loopTime;
                    }
                    action[i] = action[i] - 1;
                }
                if (DAT_0107ba33 && action[i] == 1 && previousTimes[i] <= seq->GetAnimGroup()->FUN_0054bb40(2)) {
                    float loopTime = seq->GetAnimGroup()->FUN_0054bb40(2) - seq->GetAnimGroup()->FUN_0054bb40(1);
                    seq->SetTime(seq->GetLastTime(0) + loopTime);
                    previousTimes[i] = previousTimes[i] + loopTime;
                    action[i] = action[i] + 1;
                }
                if (action[i] == 3 && GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(3)) {
                    if (nextType != 0xff) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    } else {
                        FUN_0045e4c0(i, false);
                    }
                }
                break;
            case 2:
                while (action[i] < 3 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i])) {
                    switch (action[i]) {
                    case 0:
                        action[i] = 1;
                        break;
                    case 1:
                        action[i] = 2;
                        break;
                    case 2:
                        action[i] = 3;
                        break;
                    }
                }
                if (nextType != 0xff) {
                    if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(3)) {
                        targetLoops[i] = nextLoops[i];
                        FUN_00460af0(pendingGroup[i], -1);
                        pendingGroup[i] = nextType = 0xff;
                    }
                } else if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(2) && targetLoops[i]) {
                    FUN_0045dca0();
                    action[i] = 1;
                    float loopTime = seq->GetAnimGroup()->FUN_0054bb40(2) - seq->GetAnimGroup()->FUN_0054bb40(1);
                    seq->SetTime(seq->GetLastTime(0) - loopTime);
                    previousTimes[i] = previousTimes[i] - loopTime;
                    if (targetLoops[i] != -1 && targetLoops[i] < 0xff)
                        targetLoops[i] = targetLoops[i] - 1;
                } else if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(3)) {
                    if (currentIdle->GetIdleState() == 1)
                        currentIdle->SetIdleState(3);
                    else
                        FUN_0045e4c0(i, false);
                }
                break;
            case 0:
            case 1:
                if (!seq->GetOwner()) {
                    while (action[i] < 1 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i])) {
                        switch (action[i]) {
                        case 0:
                            action[i] = 1;
                            break;
                        case 1:
                            action[i] = 1;
                            break;
                        }
                    }
                    if (nextType != 0xff) {
                        if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(1)) {
                            targetLoops[i] = nextLoops[i];
                            FUN_00460af0(pendingGroup[i], -1);
                            pendingGroup[i] = nextType = 0xff;
                        }
                    } else if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(1) && targetLoops[i]) {
                        action[i] = 0;
                        float loopTime = seq->GetEndKeyTime() - seq->GetBeginKeyTime();
                        seq->SetTime(seq->GetLastTime(0) - loopTime);
                        if (targetLoops[i] != -1)
                            targetLoops[i] = targetLoops[i] - 1;
                    } else if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(1)) {
                        FUN_0045e4c0(i, false);
                    }
                } else {
                    if (action[i] == 0 && GetSequenceTime(seq) > seq->GetAnimGroup()->FUN_0054bb40(action[i]))
                        action[i] = 1;
                    if (nextType != 0xff) {
                        if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(1)) {
                            if (i == 1 && !(actor->FUN_006f58b0() & 0xf)) {
                                FUN_0045e4c0(i, false);
                            } else {
                                targetLoops[i] = nextLoops[i];
                                FUN_00460af0(pendingGroup[i], -1);
                            }
                            pendingGroup[i] = nextType = 0xff;
                        }
                    } else if (GetSequenceTime(seq) >= seq->GetAnimGroup()->FUN_0054bb40(1)) {
                        FUN_0045e4c0(i, false);
                    }
                }
                break;
            }
        }
    }

    if (root) {
        Vec3 old = rootTranslation;
        bool useMove = false;
        Vec3 move = DAT_0108ec68;
        if (actor->FUN_006f58b0() & 0xf) {
            unsigned short moveFlags = (unsigned short)actor->FUN_006f58b0();
            if (sections[1] && (moveFlags & 0xf)) {
                int moveType = 0;
                if (sections[1]->GetAnimGroup()->FUN_0054bdd0())
                    useMove = true;
                switch (sections[1]->GetAnimGroup()->FUN_0054bef0()) {
                case 0xa8:
                    useMove = true;
                    break;
                default:
                    switch (sections[1]->GetState()) {
                    case 2:
                    case 5:
                        useMove = true;
                    }
                }
                MotionController* controller = root->FUN_00825200(&DAT_01091f44);
                InterpolatorBlend* blend = controller->GetBlend(0);
                if (blend) {
                    int priority = blend->GetHighPriority();
                    Interpolator* interpolator = sections[1]->GetInterpolator(0);
                    if (interpolator) {
                        const Rtti* rtti = interpolator->GetRtti();
                        while (rtti && rtti != reinterpret_cast<const Rtti*>(&DAT_01091f54))
                            rtti = rtti->parent;
                    }
                    if (sections[1]->GetPriority(root->name, 0) < priority)
                        useMove = false;
                }
                if (useMove) {
                    if (moveFlags & 0x200) {
                        if (moveFlags & 1)
                            moveType = 7;
                        else if (moveFlags & 2)
                            moveType = 8;
                        else if (moveFlags & 4)
                            moveType = 9;
                        else if (moveFlags & 8)
                            moveType = 10;
                    } else if (moveFlags & 0xff00) {
                        if (moveFlags & 1)
                            moveType = 3;
                        else if (moveFlags & 2)
                            moveType = 4;
                        else if (moveFlags & 4)
                            moveType = 5;
                        else if (moveFlags & 8)
                            moveType = 6;
                    }
                    if (moveType == sections[1]->GetAnimGroup()->FUN_0054bef0()) {
                        float timeMult = GetTimeMult();
                        move = sections[1]->GetAnimGroup()->FUN_0054bd40() * timeMult * DAT_0106de64 * movementRate;
                    } else {
                        unsigned short moveGroup = actor->Actor_GetAnimGroup(moveType, 0, 0, 0);
                        moveType = TESAnimGroup_GetType(moveGroup);
                        if (moveType) {
                            SequenceBase* baseSequence;
                            if (sequenceMap->FUN_0045c6e0(moveGroup, baseSequence)) {
                                Sequence* moveSequence = baseSequence->GetSequence(-1);
                                if (moveSequence) {
                                    // Fake match: the 184 dead locals below emit no code. They only raise the number of symbols
                                    // the translation unit holds when the compiler numbers its own temporaries for this function.
                                    // The operand order of the x87 multiplies in the two move-vector arms (component loaded first,
                                    // then multiplied by the scalar kept on the stack) follows those numbers: with fewer symbols the
                                    // y lane of the last scale here, or of the last scale in the first arm, comes out as scalar
                                    // times memory. The real file defines many functions before this one; this unit has only three.
                                    int pad000 = 0, pad001 = 0, pad002 = 0, pad003 = 0, pad004 = 0, pad005 = 0;
                                    int pad006 = 0, pad007 = 0, pad008 = 0, pad009 = 0, pad010 = 0, pad011 = 0;
                                    int pad012 = 0, pad013 = 0, pad014 = 0, pad015 = 0, pad016 = 0, pad017 = 0;
                                    int pad018 = 0, pad019 = 0, pad020 = 0, pad021 = 0, pad022 = 0, pad023 = 0;
                                    int pad024 = 0, pad025 = 0, pad026 = 0, pad027 = 0, pad028 = 0, pad029 = 0;
                                    int pad030 = 0, pad031 = 0, pad032 = 0, pad033 = 0, pad034 = 0, pad035 = 0;
                                    int pad036 = 0, pad037 = 0, pad038 = 0, pad039 = 0, pad040 = 0, pad041 = 0;
                                    int pad042 = 0, pad043 = 0, pad044 = 0, pad045 = 0, pad046 = 0, pad047 = 0;
                                    int pad048 = 0, pad049 = 0, pad050 = 0, pad051 = 0, pad052 = 0, pad053 = 0;
                                    int pad054 = 0, pad055 = 0, pad056 = 0, pad057 = 0, pad058 = 0, pad059 = 0;
                                    int pad060 = 0, pad061 = 0, pad062 = 0, pad063 = 0, pad064 = 0, pad065 = 0;
                                    int pad066 = 0, pad067 = 0, pad068 = 0, pad069 = 0, pad070 = 0, pad071 = 0;
                                    int pad072 = 0, pad073 = 0, pad074 = 0, pad075 = 0, pad076 = 0, pad077 = 0;
                                    int pad078 = 0, pad079 = 0, pad080 = 0, pad081 = 0, pad082 = 0, pad083 = 0;
                                    int pad084 = 0, pad085 = 0, pad086 = 0, pad087 = 0, pad088 = 0, pad089 = 0;
                                    int pad090 = 0, pad091 = 0, pad092 = 0, pad093 = 0, pad094 = 0, pad095 = 0;
                                    int pad096 = 0, pad097 = 0, pad098 = 0, pad099 = 0, pad100 = 0, pad101 = 0;
                                    int pad102 = 0, pad103 = 0, pad104 = 0, pad105 = 0, pad106 = 0, pad107 = 0;
                                    int pad108 = 0, pad109 = 0, pad110 = 0, pad111 = 0, pad112 = 0, pad113 = 0;
                                    int pad114 = 0, pad115 = 0, pad116 = 0, pad117 = 0, pad118 = 0, pad119 = 0;
                                    int pad120 = 0, pad121 = 0, pad122 = 0, pad123 = 0, pad124 = 0, pad125 = 0;
                                    int pad126 = 0, pad127 = 0, pad128 = 0, pad129 = 0, pad130 = 0, pad131 = 0;
                                    int pad132 = 0, pad133 = 0, pad134 = 0, pad135 = 0, pad136 = 0, pad137 = 0;
                                    int pad138 = 0, pad139 = 0, pad140 = 0, pad141 = 0, pad142 = 0, pad143 = 0;
                                    int pad144 = 0, pad145 = 0, pad146 = 0, pad147 = 0, pad148 = 0, pad149 = 0;
                                    int pad150 = 0, pad151 = 0, pad152 = 0, pad153 = 0, pad154 = 0, pad155 = 0;
                                    int pad156 = 0, pad157 = 0, pad158 = 0, pad159 = 0, pad160 = 0, pad161 = 0;
                                    int pad162 = 0, pad163 = 0, pad164 = 0, pad165 = 0, pad166 = 0, pad167 = 0;
                                    int pad168 = 0, pad169 = 0, pad170 = 0, pad171 = 0, pad172 = 0, pad173 = 0;
                                    int pad174 = 0, pad175 = 0, pad176 = 0, pad177 = 0, pad178 = 0, pad179 = 0;
                                    int pad180 = 0, pad181 = 0, pad182 = 0, pad183 = 0;
                                    float timeMult = GetTimeMult();
                                    move = moveSequence->GetAnimGroup()->FUN_0054bd40() * timeMult * DAT_0106de64 *
                                           movementRate;
                                }
                            }
                        }
                    }
                }
            }
        }
        UpdateAccumRoot(time, &rootTranslation, true);
        if (useMove) {
            deltaX = move.x;
            deltaY = move.y;
        } else {
            Vec3 translateDelta = rootTranslation - old;
            deltaX = translateDelta.x;
            deltaY = translateDelta.y;
        }
        deltaX = ref->FUN_004e6d80() * deltaX;
        deltaY = ref->FUN_004e6d80() * deltaY;
        if (!useMove && !sections[1] && previousSequence && previousSequence->GetState()) {
            deltaY = 0.0f;
            deltaX = 0.0f;
        }
        if (previousSequence && !previousSequence->GetState())
            previousSequence = 0;
    }

    if (!(header->flags & 1) || (this == DAT_0107a104->FUN_0076cce0(true) && FUN_0061ab20())) {
        for (i = 0; i < 8; i++) {
            switch (state) {
            case 0x17:
                if (i != 7 && i != 0)
                    continue;
                break;
            case 0x14:
                continue;
                break;
            case 0x15:
                switch (i) {
                case 2:
                case 3:
                case 4:
                    continue;
                }
                break;
            default:
                if (i == state)
                    continue;
                break;
            }
            Sequence* forward = GetSectionSequence(i);
            if (forward && previousSections[i] == forward &&
                (forward->GetState() == 1 || forward->GetState() == 2 || forward->GetState() == 5)) {
                bool playSounds = true;
                if (DAT_00f5c78c[i]) {
                    if (bone[i]) {
                        Sequence* best = 0;
                        unsigned char maxPriority = 0;
                        for (int section = 0; section < 8; section++) {
                            if (sections[section] && bone[i] && bone[i]->name) {
                                unsigned char priority = sections[section]->GetAnimGroup()->GetSectionPriority(i);
                                if (priority > maxPriority) {
                                    best = sections[section];
                                    maxPriority = priority;
                                }
                            }
                        }
                        if (!best || best != forward)
                            playSounds = false;
                    }
                } else {
                    playSounds = false;
                }
                if (playSounds) {
                    float newTime = forward->FUN_0049cac0(time);
                    if (-3.4028234663852886e+38 != newTime && -3.4028234663852886e+38 != previousTimes[i] &&
                        newTime != previousTimes[i])
                        forward->GetAnimGroup()->FUN_0054bfa0(ref, previousTimes[i], newTime, forward);
                }
            }
        }
    }

    if (currentIdle)
        currentIdle->Update(this);
    if (skipBlend)
        skipBlend = false;
    state = -1;
}
}
}   // namespace f3m_00462020

// @f3 0x0046df60 (community match, verified in this file)
namespace f3m_0046df60 {
// ---------------------------------------------------------------------------
// stand-ins for the unnamed code and data this function uses
// ---------------------------------------------------------------------------
void* __cdecl FUN_0089eb90(unsigned int uiSize);  // operator new
void __cdecl FUN_00ade300(void* pvA, void* pvB, void* pvC);
extern char* DAT_00e207a8;      // empty string sentinel
extern double DAT_00f4b250[];   // 0x70 triples of doubles

struct MemMgr
{
    void* FUN_0086b930(unsigned int uiSize);
    void FUN_0086ba60(void*);
};
extern MemMgr DAT_01090a78;

char* __cdecl FUN_008242a0(const char* pcName);
struct RefStr
{
    char* m_pcData;
    RefStr(const char* s) : m_pcData(FUN_008242a0(s)) {}
    ~RefStr()
    {
        if (m_pcData != DAT_00e207a8)
            InterlockedDecrement((long*)(m_pcData - 8));
    }
};

// quad element of the vertex array: 0x10 bytes
struct RgbaColor
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    RgbaColor();
    static void* operator new[](unsigned int uiSize) { return DAT_01090a78.FUN_0086b930(uiSize); }
    static void operator delete[](void* pv) { DAT_01090a78.FUN_0086ba60(pv); }
};

// refcounted node object (this+0x24 and this+0x2c)
struct NiNode
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void SetUnk(void* pvValue, int iFlag);  // vtable + 0xdc
    long m_lRefCount;                               // +0x04
    void IncRefCount() { InterlockedIncrement(&m_lRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_lRefCount) == 0) vf01(); }
    void FUN_004236f0(void* pvChild);
    void* FUN_00826590(int iIndex);
    void FUN_008268a0();
    void FUN_008245d0(const RefStr& rStr);
    void FUN_008264c0(void* pvDesc);
};

// node returned by FUN_00826590
struct NiExtra
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_iFlags24;  // +0x24
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_iEx38;  // +0x38
};

// 0x1c byte property object, class named after its vtable address
struct NiPropBase : NiNode
{
    NiPropBase();
};
struct NiAlphaProperty : NiPropBase
{
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    unsigned short m_us18;  // +0x18
    unsigned char m_b1a;    // +0x1a
    NiAlphaProperty() : m_us18(0xec), m_b1a(0) {}
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pv);
};

// 0x80 byte child object, class named after its constructor
struct FUN_00af2240
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_iUnk58;  // +0x58
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    FUN_00af2240();
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pv);
};

// 0xe4 byte property object, class named after its constructor
struct FUN_00ad2a40
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;
    int m_ic0;
    int m_ic4;
    int m_ic8;
    int m_icc;
    int m_id0;
    int m_id4;
    int m_id8;
    int m_idc;
    int m_ie0;;
    FUN_00ad2a40();
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pv);
};

// 0xc4 byte geometry object, class named after its constructor
struct FUN_0083c020
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;
    int m_ic0;;
    FUN_0083c020(unsigned short usCount, float* pfPos, int iZero, RgbaColor* pQuads,
                 int iZero2, int iZero3, int iZero4, unsigned short usSub,
                 int iOne, unsigned short* pusCount, unsigned short* pusIdx);
    static void* operator new(unsigned int uiSize) { return FUN_0089eb90(uiSize); }
    static void operator delete(void* pv);
};

// description record handed to FUN_008264c0
struct Unk16
{
    float m_f00;
    bool m_b04;
    bool m_b05;
    bool m_b06;
    bool m_b07;
    bool m_b08;
};

// ---------------------------------------------------------------------------
// the object this function belongs to
// ---------------------------------------------------------------------------
template <class T> struct SPtr
{
    T* m_pObject;
    SPtr(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPtr()
    {
        m_pObject->DecRefCount();
    }
    T* operator->() const { return m_pObject; }
    operator T*() const { return m_pObject; }
};
template <class T> struct NiMemberPtr
{
    T* m_pObject;
    NiMemberPtr& operator=(T* p)
    {
        T* pOld = m_pObject;
        if (pOld != p)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
    T* operator->() const { return m_pObject; }
    operator T*() const { return m_pObject; }
};
extern const char DAT_00dbf100[];
extern const char DAT_00dbf114[];
struct MyThis
{
    virtual void vf00();
    virtual void vf04();
    virtual void Update(float* pfPos);  // vtable + 0x08
    int m_i04;
    RgbaColor m_kQuad;  // +0x08 (16 bytes)
    float m_f18;           // +0x18
    int m_i1c;
    int m_i20;
    NiMemberPtr<NiNode> m_pkNodeA;  // +0x24
    int m_i28;
    NiMemberPtr<NiNode> m_pkNodeB;  // +0x2c
    void FUN_0046df60();
    void FUN_0046d800(float fScale);
};


// pdb: BGSPrimitiveSphere::Build | BGSPrimitive.obj | fnv360_0822_retail, vtable, medium
void MyThis::FUN_0046df60()
{
    if (!m_pkNodeA)
    {
        RgbaColor* pQuads = new RgbaColor[0x70];
        float* pfPos = (float*)DAT_01090a78.FUN_0086b930(0x540);
        unsigned short* pusIdx = (unsigned short*)DAT_01090a78.FUN_0086b930(0xe0);
        for (int i = 0; i < 0x70; ++i)
        {
            pfPos[i * 3 + 0] = (float)DAT_00f4b250[i * 3 + 0] * m_f18;
            pfPos[i * 3 + 1] = (float)DAT_00f4b250[i * 3 + 1] * m_f18;
            pfPos[i * 3 + 2] = (float)DAT_00f4b250[i * 3 + 2] * m_f18;
            pQuads[i] = m_kQuad;
            pusIdx[i] = (unsigned short)i;
        }
        unsigned short* pusCount = (unsigned short*)DAT_01090a78.FUN_0086b930(2);
        *pusCount = 0x70;

        FUN_0083c020* pShape = new FUN_0083c020(0x70, pfPos, 0, pQuads, 0, 0, 0, 0x6e, 1,
                                                pusCount, pusIdx);
        FUN_00af2240* pChild = new FUN_00af2240;
        pChild->m_iUnk58 = 0x21;
        ((NiNode*)pShape)->FUN_004236f0(pChild);
        FUN_00ade300(pShape, 0, 0);
        m_pkNodeA = (NiNode*)pShape;

        SPtr<NiAlphaProperty> spProp = new NiAlphaProperty;
        spProp->FUN_008245d0(RefStr(DAT_00dbf100));
        spProp->m_us18 |= 1;
        m_pkNodeA->FUN_004236f0(spProp);

        NiExtra* pkSlot = (NiExtra*)m_pkNodeA->FUN_00826590(3);
        if ((char)pkSlot->m_iFlags24 & 1)
            pkSlot->m_iEx38 = 0;
        pkSlot->m_iFlags24 &= ~1;

        m_pkNodeB = (NiNode*)new FUN_00ad2a40;
        m_pkNodeB->SetUnk(m_pkNodeA, 1);
        m_pkNodeB->FUN_008245d0(RefStr(DAT_00dbf114));
        m_pkNodeB->FUN_008268a0();
        m_pkNodeA->FUN_008268a0();
    }
    else
    {
        FUN_0046d800(m_f18);
        Update(&m_kQuad.m_f00);
    }

    Unk16 kDesc;
    kDesc.m_f00 = 0.0f;
    kDesc.m_b04 = false;
    kDesc.m_b05 = false;
    kDesc.m_b06 = false;
    kDesc.m_b07 = false;
    kDesc.m_b08 = false;
    m_pkNodeB->FUN_008264c0(&kDesc);
}
}   // namespace f3m_0046df60

// @f3 0x00472750 (community match, verified in this file)
namespace f3m_00472750 {


namespace S472750_ns {
struct S472750_AVObject;
struct S472750_Node;
struct S472750_Geometry;
struct S472750_RTTI { const char* name; const S472750_RTTI* base; };
struct S472750_Heap { void FUN_0086ba60(void* p); };
extern S472750_Heap DAT_01090a78;
extern const S472750_RTTI DAT_0116eeec;
extern const char DAT_00dbffd8[];
extern const char DAT_00dbff90[];
extern const char DAT_00dbff40[];
extern const char DAT_00dbfec8[];

struct S472750_FixedString {
    char* m_kHandle;
    operator const char*() const { return m_kHandle; }
};

struct S472750_Ptr {
    S472750_AVObject* m_pObject;
    static void operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
    S472750_Ptr(S472750_AVObject* object = 0);
    ~S472750_Ptr();
    bool operator!=(S472750_AVObject* object) const { return m_pObject != object; }
    bool operator==(S472750_AVObject* object) const { return m_pObject == object; }
    bool operator!=(const S472750_Ptr& other) const { return m_pObject != other.m_pObject; }
    S472750_Ptr& operator=(const S472750_Ptr& other);
};

struct S472750_Children {
    int unk00;
    S472750_Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_004712a0();
    void FUN_00470e10();
    void UpdateSize()
    {
        while (m_usSize > 0)
        {
            if (m_pBase[m_usSize - 1] != S472750_Ptr(0))
                break;
            m_usSize--;
        }
    }
};

struct S472750_PtrArrayBase {
    S472750_Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    S472750_PtrArrayBase(unsigned int maxSize, unsigned int growBy)
    {
        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~S472750_PtrArrayBase() { delete[] m_pBase; }
    static S472750_Ptr* Allocate(unsigned int count);
    __declspec(noinline) void FUN_005574c0(unsigned int maxSize)
    {
        if (maxSize == m_usMaxSize)
            return;
        unsigned int i;
        if (maxSize < m_usSize)
        {
            for (i = maxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = S472750_Ptr(0);
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)maxSize;
        }
        S472750_Ptr* saved = m_pBase;
        m_usMaxSize = (unsigned short)maxSize;
        if (maxSize > 0)
        {
            m_pBase = Allocate(maxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = saved[i];
        }
        else
            m_pBase = 0;
        delete[] saved;
    }
    __declspec(noinline) void FUN_00470f10(unsigned int index, const S472750_Ptr& element)
    {
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (element.m_pObject != 0)
                m_usESize++;
        }
        else if (element.m_pObject != 0)
        {
            if (m_pBase[index] == 0)
                m_usESize++;
        }
        else if (m_pBase[index] != 0)
            m_usESize--;
        m_pBase[index] = element;
    }
    unsigned int SetAtGrow(unsigned int index, const S472750_Ptr& element)
    {
        if (index >= m_usMaxSize)
            FUN_005574c0(index + m_usGrowBy);
        FUN_00470f10(index, element);
        return index;
    }
};

}
struct BA5EFA0ObjectArray : S472750_ns::S472750_PtrArrayBase {
    BA5EFA0ObjectArray(unsigned int maxSize = 0, unsigned int growBy = 1) : S472750_ns::S472750_PtrArrayBase(maxSize, growBy) {}
};
namespace S472750_ns {

struct S472750_SkinData { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40; unsigned int boneCount44; };
struct S472750_Skin { int unk00; int unk04; S472750_SkinData* data08; int unk0C; S472750_AVObject* root10; S472750_AVObject** bones14;
 S472750_SkinData* GetSkinData() const { return data08; }
 S472750_AVObject* const* GetBones() const { return bones14; }
 void SetBone(unsigned int i, S472750_AVObject* b) { bones14[i] = b; }
 void SetRootParent(S472750_AVObject* p) { root10 = p; } };

struct S472750_AVObject {
    virtual void v00();
    virtual void DeleteThis();
    virtual const S472750_RTTI* GetRTTI();
    virtual S472750_Node* IsNode();
    virtual void v10();
    virtual void v14();
    virtual S472750_Geometry* IsGeometry();
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
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();




    long refs04;
    S472750_FixedString name08;
    int unk0C;
    int unk10;
    int unk14;
    S472750_AVObject* parent18;
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
    // Two readers of the name: a copy of the fixed string, and a reference to the member itself.
    S472750_FixedString GetNameValue() const { return name08; }
    const S472750_FixedString& GetName() const { return name08; }
    void IncRefCount() { ::InterlockedIncrement(&refs04); }
    void DecRefCount() { if (::InterlockedDecrement(&refs04) == 0) DeleteThis(); }
};
struct S472750_Node : S472750_AVObject {
    virtual void AttachChild(S472750_AVObject* child, int first);
    virtual void vE0();
    virtual void vE4();
    virtual void DetachChild(S472750_AVObject* child);
    S472750_Children children9C;
    unsigned int GetArrayCount() const { return children9C.m_usSize; }
    S472750_AVObject* GetAt(unsigned int i) const { return children9C.m_pBase[i].m_pObject; }
};
struct S472750_Geometry : S472750_AVObject {
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    S472750_Skin* skinBC;
    int unkC0;
};
typedef char VerifyAVObjectSize[(sizeof(S472750_AVObject)==0x9c)?1:-1];
typedef char VerifyNodeSize[(sizeof(S472750_Node)==0xac)?1:-1];
typedef char VerifyGeometrySize[(sizeof(S472750_Geometry)==0xc4)?1:-1];
inline S472750_Ptr::S472750_Ptr(S472750_AVObject* object) { m_pObject = object; if (m_pObject) m_pObject->IncRefCount(); }
inline S472750_Ptr::~S472750_Ptr() { if (m_pObject) m_pObject->DecRefCount(); }
inline S472750_Ptr& S472750_Ptr::operator=(const S472750_Ptr& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}

S472750_AVObject* __cdecl FUN_00aab440(S472750_Node* root, const S472750_FixedString& name, int a);

void __cdecl FUN_00887da0(const char* format, ...);

inline bool S472750_IsKindOf(const S472750_RTTI* target, S472750_AVObject* object)
{
    for (const S472750_RTTI* rtti = object->GetRTTI(); rtti; rtti = rtti->base)
        if (rtti == target)
            return true;
    return false;
}


// pdb: BipedAnim::AttachToSkeleton | BipedAnim.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
void __cdecl BipedAnim_AttachToSkeleton(S472750_Node* apSkeleton, S472750_AVObject* apSkin, S472750_Node* apParentNode, bool abShowWarnings)
{
    if (!apSkin)
        return;
    S472750_Node* pnode = apSkin->IsNode();
    if (apSkin->IsGeometry())
    {
        S472750_Geometry* ptri = static_cast<S472750_Geometry*>(apSkin);
        S472750_Skin* pskin = ptri->skinBC;
        if (pskin)
        {
            S472750_AVObject* const* pbones = pskin->GetBones();
            unsigned int ibonecount = pskin->GetSkinData()->boneCount44;
            S472750_AVObject* pnewBone;
            for (unsigned int m = 0; m < ibonecount; m++)
            {
                if (pbones[m])
                {
                    const S472750_FixedString& name = pbones[m]->name08;
                    pnewBone = FUN_00aab440(apSkeleton, name, 1);
                    if (pnewBone)
                    {
                        pskin->SetBone(m, pnewBone);
                    }
                    else
                    {
                        pskin->SetBone(m, apSkeleton);
                        if (abShowWarnings)
                        {
                            if (pnode && !::_strnicmp((const char*)apSkin->GetNameValue(), (const char*)pbones[m]->GetNameValue(), strlen((const char*)pbones[m]->GetNameValue())))
                                FUN_00887da0(DAT_00dbffd8, (const char*)pbones[m]->GetNameValue(), (const char*)pnode->parent18->GetNameValue(), (const char*)pnode->GetNameValue());
                            else if (pnode && apSkeleton)
                                FUN_00887da0(DAT_00dbff90, (const char*)pbones[m]->GetNameValue(), (const char*)pnode->GetNameValue(), (const char*)apSkeleton->GetNameValue());
                            else
                                FUN_00887da0(DAT_00dbff40, (const char*)pbones[m]->GetName());
                        }
                    }
                }
            }
            if (apParentNode)
            {
                pskin->SetRootParent(apParentNode);
                apParentNode->AttachChild(apSkin, 1);
            }
        }
    }
    bool warned = false;
    if (pnode)
    {
        pnode->children9C.FUN_004712a0();
        pnode->children9C.FUN_00470e10();
        BA5EFA0ObjectArray TempArray;
        for (int i = 0; i < pnode->GetArrayCount(); i++)
        {
            S472750_AVObject* pobj = pnode->GetAt(i);
            if (pobj)
            {
                S472750_Node* ptemp = pobj->IsNode();
                if (S472750_IsKindOf(&DAT_0116eeec, pnode) && ptemp)
                    BipedAnim_AttachToSkeleton(apSkeleton, pobj, apParentNode, true);
                else if (!pobj->IsGeometry())
                {
                    if (!warned && ptemp && static_cast<S472750_Node*>(pobj)->children9C.m_usESize)
                    {
                        FUN_00887da0(DAT_00dbfec8, (const char*)pnode->parent18->GetNameValue(), (const char*)pnode->GetNameValue(), (const char*)apSkeleton->GetNameValue());
                        warned = true;
                    }
                    TempArray.SetAtGrow(TempArray.m_usSize, pobj);
                    pnode->DetachChild(pobj);
                }
                else
                    BipedAnim_AttachToSkeleton(apSkeleton, pobj, apParentNode, abShowWarnings);
            }
        }
        pnode->children9C.FUN_004712a0();
        pnode->children9C.UpdateSize();
    }
}
}
}   // namespace f3m_00472750
