#include "f3_common.h"
// src/staging/blk_00c80000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00c80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct ScalarFactor
{
    __m128 value;
    __forceinline ScalarFactor(float x) : value(_mm_load_ss(&x))
    {}
};
struct ScaledVector
{
    __m128 value;
    __forceinline void Multiply(const ScalarFactor& factor)
    {
        value = _mm_mul_ps(_mm_shuffle_ps(factor.value, factor.value, 0), value);
    }
};
struct LocalTypeTag
{
    const char* name;
    LocalTypeTag* parent;
};
extern const LocalTypeTag DAT_012043f8;
struct ScaledBackend
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
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 firstVector;
    __m128 secondVector;
    void OnTrigger(const __m128*);
    void FUN_00561800(const __m128*);
};
struct PhysicsWrapper
{
    unsigned int unk00, unk04;
    ScaledBackend* backend;
    void FUN_00a29680();
};
struct CollisionState
{
    unsigned int unk00, unk04, unk08, unk0c;
    PhysicsWrapper* physics;
};
struct CollisionBase
{
    CollisionState* FUN_00653290(const LocalTypeTag*);
};
struct SceneBranch;
struct SceneObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual SceneBranch* GetBranch();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    CollisionBase* collision;
};
struct SceneBranch : SceneObject
{
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
    SceneObject** children;
    unsigned short capacity;
    unsigned short count;
};

union __declspec(align(16)) ResultBuffer
{
    void* hit;
    char storage[0x30];
    ResultBuffer() : hit(0)
    {}
};

class bhkLimitedHingeVector
{
  public:
    float x;
    float y;
    float z;
    float w;
    void FUN_004b4db0(const float* p);
};

struct FnvMat4
{
    __m128 m_uiX;
    __m128 m_uiY;
    __m128 m_uiZ;
    __m128 m_w;
};

struct __declspec(align(16)) hkVector4C9E
{
    __m128 m_vComponents;
};

namespace fnv_00c9ecb0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};

struct hkVector4
{
    __m128 m_vComponents;
};

struct bhkLimitedHingeVector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_004b4db0(const float* v);
};

}  // namespace fnv_00c9ecb0

#include <xmmintrin.h>
namespace fnv_00c88520 {
struct FnvMat4
{
    __m128 m_uiX;
    __m128 m_uiY;
    __m128 m_uiZ;
    __m128 m_w;
};
struct Vec3
{
    float x, y, z;
};
struct Transform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vec3 translate;
    float scale;
    Transform FUN_0062c250(const Transform& rhs) const;
};
struct __declspec(align(16)) FourFloatVector
{
    float elements[4];
    void FUN_005611c0();
};
struct SceneObject;
struct CastObject
{
    int unk00, unk04, unk08, unk0c;
    SceneObject* unk10;
    SceneObject* GetBody()
    {
        if (this)
            return unk10;
        return 0;
    }
    CastObject* FUN_00653290(const void* type);
};
struct SceneObject
{
    void** vtable;
    int unk04, unk08, unk0c, unk10, unk14;
    SceneObject* unk18;
    CastObject* unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c,
        unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94;
    float unk98;
};
struct Wrapper
{
    int unk00, unk04;
    SceneObject* unk08;
    int unk0c;
    SceneObject* unk10;
    SceneObject* GetSource()
    {
        if (this)
            return unk08;
        return 0;
    }
    SceneObject* GetDestination()
    {
        if (this)
            return unk10;
        return 0;
    }
};

extern char DAT_012043f8;

Wrapper* __cdecl FUN_00c802d0(SceneObject*);
void __cdecl FUN_004a3e00(FourFloatVector&, const Vec3&);

}  // namespace fnv_00c88520

#include <string.h>
extern __declspec(thread) int g_tlsMemContext;
inline int GetMemContext()
{
    return g_tlsMemContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    g_tlsMemContext = aiMemoryContext;
}
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};
struct StrArr
{
    void** vtable;
    char** data;
    unsigned short capacity, size, used, growBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    __forceinline void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (value)
                ++used;
        }
        else if (value)
        {
            if (!data[index])
                ++used;
        }
        else if (data[index])
        {
            --used;
        }
        data[index] = value;
    }
};
struct BaseCall
{
    void** vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    void FUN_00a6d830(StrArr*);
};
class NiPoint3
{
  public:
    float x, y, z;
};
struct KeyData : BaseCall
{
    NiPoint3* keys;
    unsigned int unk40, unk44;
    unsigned int count;
    void FUN_00c9bbb0(StrArr* strings);
};
int _sprintf_s(char*, unsigned int, const char*, ...);
int _strcpy_s(char*, unsigned int, const char*);
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;

// @f3 0x009152c0 (community match, verified in this file)
extern "C" char* __cdecl FUN_00847b50(const char*);
extern "C" char* __cdecl FUN_00847d80(const char*, unsigned);
struct ExactBaseCall : BaseCall { void FUN_00838420(StrArr*); };
extern char* DAT_010f32f8;
extern char FUN_00e363f8[];
extern char FUN_00e363e0[];
// pdb: bhkBlendController::GetViewerStrings | bhkBlendController.obj | fnv360_0822_retail, ustr, medium
// pdb params: apStrings
void KeyData::FUN_00c9bbb0(StrArr* strings)
{
    ((ExactBaseCall*)this)->FUN_00838420(strings);
    char* first = FUN_00847b50(DAT_010f32f8);
    strings->Add(first);
    unsigned n = count;
    char* second = FUN_00847d80(FUN_00e363f8, n);
    strings->Add(second);
    for (unsigned i = 0; i < count; ++i)
    {
        char buffer[64];
        NiPoint3* p = &keys[i];
        _sprintf_s(buffer, 64, FUN_00e363e0, i, p->x, p->y, p->z);
        unsigned len = (unsigned)strlen(buffer) + 1;
        char* value = (char*)g_memoryManager.Allocate(len);
        _strcpy_s(value, len, buffer);
        strings->Append(value);
    }
}


struct TlsBlock
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

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    unsigned int unk13c;

    unsigned int unk140;

    unsigned int unk144;

    unsigned int unk148;

    unsigned int unk14c;

    unsigned int unk150;

    unsigned int unk154;

    unsigned int unk158;

    unsigned int unk15c;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16c;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17c;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18c;

    unsigned int unk190;

    unsigned int unk194;

    unsigned int unk198;

    unsigned int unk19c;

    unsigned int unk1a0;

    unsigned int unk1a4;

    unsigned int unk1a8;

    unsigned int unk1ac;

    unsigned int unk1b0;

    unsigned int unk1b4;

    unsigned int unk1b8;

    unsigned int unk1bc;

    unsigned int unk1c0;

    unsigned int unk1c4;

    unsigned int unk1c8;

    unsigned int unk1cc;

    unsigned int unk1d0;

    unsigned int unk1d4;

    unsigned int unk1d8;

    unsigned int unk1dc;

    unsigned int unk1e0;

    unsigned int unk1e4;

    unsigned int unk1e8;

    unsigned int unk1ec;

    unsigned int unk1f0;

    unsigned int unk1f4;

    unsigned int unk1f8;

    unsigned int unk1fc;

    unsigned int unk200;

    unsigned int unk204;

    unsigned int unk208;

    unsigned int unk20c;

    unsigned int unk210;

    unsigned int unk214;

    unsigned int unk218;

    unsigned int unk21c;

    unsigned int unk220;

    unsigned int unk224;

    unsigned int unk228;

    unsigned int unk22c;

    unsigned int unk230;

    unsigned int unk234;

    unsigned int unk238;

    unsigned int unk23c;

    unsigned int unk240;

    unsigned int unk244;

    unsigned int unk248;

    unsigned int unk24c;

    unsigned int unk250;

    unsigned int unk254;

    unsigned int unk258;

    unsigned int unk25c;

    unsigned int unk260;

    unsigned int unk264;

    unsigned int unk268;

    unsigned int unk26c;

    unsigned int unk270;

    unsigned int unk274;

    unsigned int unk278;

    unsigned int unk27c;

    unsigned int unk280;

    unsigned int unk284;

    unsigned int unk288;

    unsigned int unk28c;

    unsigned int unk290;

    unsigned int unk294;

    unsigned int unk298;

    unsigned int unk29c;

    unsigned int unk2a0;

    unsigned int unk2a4;

    unsigned int unk2a8;

    unsigned int unk2ac;

    unsigned int unk2b0;

    unsigned int context;
};

extern __declspec(thread) TlsBlock tlsBlock;

struct ContextScope
{

    unsigned int previous;

    ContextScope(unsigned int value)
    {
        previous = tlsBlock.context;
        tlsBlock.context = value;
    }

    ~ContextScope()
    {
        tlsBlock.context = previous;
    }
};

struct TypeInfo
{
    const char* name;
    TypeInfo* parent;
};

extern TypeInfo DAT_0126818c, DAT_01268158, DAT_012681f0, DAT_01267e64;

extern const float DAT_01050de4, DAT_0101e2bc, DAT_01016248, DAT_01017718, DAT_01011d78;

struct __declspec(align(16)) Transform
{

    __m128 rotation0, rotation1, rotation2, translation;

    Transform()
    {}

    __forceinline Transform(const Transform& r)
    {
        __m128 a = r.rotation0, b = r.rotation1, c = r.rotation2, d = r.translation;
        rotation0 = a;
        rotation1 = b;
        rotation2 = c;
        translation = d;
    }

    void FUN_00cb2fc0();
};

struct Point3
{
    float x, y, z;
};

struct NiTransformLocal
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
    Point3 translation;
    float scale;
};

struct Backend
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

    Transform transform;
};

struct PhysicsObject;

struct PhysicsList
{
    PhysicsObject* object;
    PhysicsList* next;
    void PopAndRelease();
};

struct World;

struct Filter
{
    unsigned int value;
    __forceinline void Layer(unsigned x)
    {
        value = (value & ~0x7f) | (x & 0x7f);
    }
};

struct PhysicsObject
{

    virtual void slot00();

    virtual void slot04();

    virtual TypeInfo* GetType();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual int GetKind();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4c();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5c();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6c();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7c();

    virtual void slot80();

    virtual void slot84();

    virtual void slot88();

    virtual void slot8c();

    virtual void slot90();

    virtual World* GetWorld();

    virtual void slot98();

    virtual void slot9c();

    virtual void Detach();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void SetMotion(int);

    int unk04;

    Backend* underlying;

    PhysicsObject** alternate;

    int unk10;

    PhysicsList objects;

    int GetLinkedRecordValue();

    void* FUN_00c87a40();

    int FUN_00517630();

    void FUN_00c8ef80(void*);

    __declspec(noalias) Filter FUN_0043b4f0();

    void FUN_00626cb0(unsigned int);

    bool FUN_008cffa0();

    void UpdateMatchingNodes(World*);
};

struct Key
{
    float time, value, tangent;
};

struct Controller
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

    Key* keys;
    int unk40, unk44;
    unsigned int count;
};

struct SceneNode;

struct CollisionWrapper
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;
};

struct SceneNode
{
    int unk00, unk04;
    SceneNode* host;
    int unk0c;
    PhysicsObject* body;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    World* world;

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

    NiTransformLocal transform;

    Controller* FUN_00a5c570(TypeInfo*);
};

struct World
{
    void FUN_0056d2c0(PhysicsObject*);
};

struct ConstraintData
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

    float strength;
    int unkc0;
    float tau, damping;

    void FUN_00cb8b60(Transform*, Transform*, __m128*, __m128*);
};

class hkSerializableCinfo
{

  public:
    ConstraintData* data;

    int references, unkc, unk10;

    __forceinline hkSerializableCinfo() : data(0), references(1), unkc(0), unk10(0)
    {}
};

struct hkConstraintCinfo : hkSerializableCinfo
{

    __forceinline hkConstraintCinfo()
    {}

    virtual __forceinline ~hkConstraintCinfo()
    {
        SetChildObject(0);
    }

    void SetChildObject(int);
};

struct hkLimitedHingeConstraintCinfo : hkConstraintCinfo
{

    __forceinline hkLimitedHingeConstraintCinfo()
    {}

    virtual __forceinline ~hkLimitedHingeConstraintCinfo()
    {}

    void FUN_00caa3f0();

    void FUN_009ba320(PhysicsObject*, PhysicsObject*);
};

typedef hkLimitedHingeConstraintCinfo ConstraintInfo;

void* FUN_00aa13e0(unsigned int);

void FUN_00aa1450(void*);

struct FUN_00c88380
{

    int* vtable;
    int references;
    void* object;
    int unk0c;

    static void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }

    static void operator delete(void* p)
    {
        FUN_00aa1450(p);
    }

    FUN_00c88380(ConstraintInfo*);
};

CollisionWrapper* FUN_00c802d0(SceneNode*);

__declspec(noalias) unsigned char FUN_00c8cce0(int*);

static __forceinline void Normalize3(__m128& v)
{

    __m128 h = _mm_set_ss(0.5f), t = _mm_set_ss(3.0f), z = _mm_set_ss(0.0f);
    __m128 p = _mm_mul_ps(v, v);

    __m128 a = _mm_shuffle_ps(p, p, 0x55);

    __m128 b = _mm_add_ss(a, p);

    __m128 n = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), b);

    __m128 mask = _mm_cmpeq_ss(n, z);

    __m128 r = _mm_rsqrt_ss(n);

    __m128 result = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(h, r), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(n, r), r))));

    v = _mm_mul_ps(v, _mm_shuffle_ps(result, result, 0));
}

static __forceinline PhysicsObject* AsType(PhysicsObject* object, TypeInfo* target)
{

    TypeInfo* type = object->GetType();

    while (type)
    {
        if (type == target)
            return object;
        type = type->parent;
    }

    return 0;
}

__forceinline unsigned char DynamicValue(const int& m)
{
    return FUN_00c8cce0(const_cast<int*>(&m));
}
// @f3 0x008fa8d0 (community match, verified in this file)
#include <math.h>
struct __declspec(align(16)) hkVector4f
{
    float x, y, z, w;
    __forceinline hkVector4f()
    {}
    __forceinline hkVector4f(const hkVector4f& v) : x(v.x), y(v.y), z(v.z), w(v.w)
    {}
    __forceinline hkVector4f& operator=(const hkVector4f& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }
    __forceinline void Normalize3()
    {
        float lengthSquared = x * x + y * y + z * z;
        float roundedInverse;
        if (lengthSquared != 0.0f)
            roundedInverse = 1.0f / sqrtf(lengthSquared);
        else
            roundedInverse = 0.0f;
        x = roundedInverse * x;
        const double inverse = roundedInverse;
        y = y * inverse;
        z = z * inverse;
        w = inverse * w;
    }
};
struct __declspec(align(16)) hkTransformf
{
    hkVector4f rotation0, rotation1, rotation2, translation;
    hkTransformf()
    {}
    __forceinline hkTransformf(const hkTransformf& r)
    {
        hkVector4f a = r.rotation0, b = r.rotation1, c = r.rotation2, d = r.translation;
        rotation0 = a;
        rotation1 = b;
        rotation2 = c;
        translation = d;
    }
    void FUN_00924ea0();
};
struct BodyObject;
struct BodyWorld;
struct FilterInfo
{
    unsigned int value;
    __forceinline FilterInfo()
    {}
};
struct BodyShape
{
    int unk00, unk04, unk08;
    BodyObject* body;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkTransformf transform;
};
struct BodyLink
{
    BodyObject* object;
    BodyLink* next;
    void FUN_008fa360();
};
struct BodyObject
{
    virtual void slot00();
    virtual void slot04();
    virtual TypeInfo* GetType();
    virtual void slot0c();
    virtual int GetKind();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual BodyWorld* GetWorld();
    virtual void slot9c();
    virtual void Detach();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void SetMotion(int);
    int unk04;
    BodyShape* underlying;
    BodyObject** alternate;
    int unk10;
    BodyLink objects;
    int FUN_008fc0f0();
    int FUN_008f81f0();
    int FUN_004b80e0();
    void FUN_00900ad0(void*);
    FilterInfo FUN_00424270();
    void FUN_0056c440(unsigned int);
    bool FUN_00726810();
    void FUN_008ff290(BodyWorld*);
};
struct NodeHost
{
    int unk00, unk04;
    NodeHost* host;
    int unk0c;
    BodyObject* body;
    int unk14, unk18, unk1c, unk20;
    BodyWorld* world;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    NiTransformLocal transform;
    Controller* FUN_00825200(char**);
};
struct BodyWrapper
{
    int unk00, unk04;
    NodeHost* host;
    int unk0c;
    BodyObject* body;
};
struct BodyWorld
{
    void FUN_004e5ea0(BodyObject*);
};
struct HingeData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8;
    float strength;
    void SetStrength(float value) { strength = value; }
    int unkc0;
    float tau, damping;
    void FUN_0092b430(hkTransformf*, hkTransformf*, hkVector4f*, hkVector4f*);
};
class SerializableCinfo
{
  public:
    HingeData* data;
    int references, unkc, unk10;
    __forceinline SerializableCinfo() : data(0), unkc(0), unk10(0)
    {
        references = 1;
    }
};
struct ConstraintCinfo : SerializableCinfo
{
    __forceinline ConstraintCinfo()
    {}
    virtual __forceinline ~ConstraintCinfo()
    {
        FUN_008fbbb0(0);
    }
    void FUN_008fbbb0(int);
};
struct LimitedHingeCinfo : ConstraintCinfo
{
    __forceinline LimitedHingeCinfo()
    {}
    virtual __forceinline ~LimitedHingeCinfo()
    {}
    void FUN_0091c870();
    void FUN_007c45e0(BodyObject*, BodyObject*);
};
void* FUN_0089eb90(unsigned int);
void FUN_0089ec00(void*);
struct FUN_008fa290
{
    int* vtable;
    int references;
    void* object;
    int unk0c;
    static void* operator new(unsigned int n)
    {
        return FUN_0089eb90(n);
    }
    static void operator delete(void* p)
    {
        FUN_0089ec00(p);
    }
    FUN_008fa290(LimitedHingeCinfo*);
};
extern TypeInfo DAT_010f31fc, DAT_010f31b0, DAT_010f2ee0;
void FUN_008fa550(SceneNode*, SceneNode*);
BodyWrapper* FUN_008f1d20(SceneNode*);
unsigned char FUN_0056fab0(int);
hkTransformf* FUN_004e5e40(hkTransformf*, NiTransformLocal*);
BodyWorld* FUN_005685e0(BodyWorld*);
NodeHost* FUN_00424d50(TypeInfo*, BodyWrapper*);
void FUN_008fa770(SceneNode*, BodyWorld*);
static __forceinline BodyObject* IsKindOf(BodyObject* object, TypeInfo* target)
{
    TypeInfo* type = object->GetType();
    while (type)
    {
        if (type == target)
            return object;
        type = type->parent;
    }
    return 0;
}
// pdb: WeaponObject::Constrain | WeaponObject.obj | fnv360_0721_beta, call_gap, low
// pdb params: abEnable, aOwnerFilter, apFrom, apTo, abDefaultKeyframed
void __cdecl FUN_00c88a40(bool create, Filter filter, SceneNode* first, SceneNode* second, bool force)
{
    if (!first || !second)
        return;
    FUN_008fa550(first, second);
    BodyWrapper* resolvedFirst = FUN_008f1d20(first);
    BodyWrapper* resolvedSecond = FUN_008f1d20(second);
    if (!resolvedFirst || !resolvedSecond)
        return;
    BodyObject* sourceBody = resolvedFirst->body;
    BodyObject* targetBody = resolvedSecond->body;
    BodyLink* listEntry = &sourceBody->objects;
    bool skipped = false;
    while (listEntry)
    {
        BodyObject* listObject = listEntry->object;
        if (!listObject)
            break;
        if (IsKindOf(listObject, &DAT_010f31fc))
        {
            BodyObject* body = listObject->underlying ? listObject->underlying->body
                                                         : (listObject->alternate ? *listObject->alternate : 0);
            if (body->GetKind() > 100 || body->GetKind() == 18 || body->GetKind() == 19)
            {
                skipped = true;
                listEntry = listEntry->next;
                continue;
            }
            if (listObject->FUN_008fc0f0())
                listObject->Detach();
        }
        else if (IsKindOf(listObject, &DAT_010f31b0) && listObject->FUN_008f81f0())
            listObject->Detach();
        listEntry->FUN_008fa360();
    }
    if (!create)
        return;
    LimitedHingeCinfo info;
    info.FUN_0091c870();
    if (force)
        sourceBody->SetMotion(6);
    else if (FUN_0056fab0(sourceBody->FUN_004b80e0()) != FUN_0056fab0(targetBody->FUN_004b80e0()))
    {
        int motionType;
        Controller* controller = resolvedSecond->host->FUN_00825200(&DAT_010f32f8);
        if (controller && controller->count)
            motionType = controller->keys[controller->count - 1].value < 1.0f ? 1 : 6;
        else
            motionType = FUN_0056fab0(targetBody->FUN_004b80e0()) ? 1 : 6;
        sourceBody->SetMotion(motionType);
    }
    info.FUN_007c45e0(sourceBody, targetBody);
    hkTransformf sourceTransform = (sourceBody ? sourceBody->underlying : 0)->transform;
    hkTransformf targetTransform = (targetBody ? targetBody->underlying : 0)->transform;
    hkTransformf convertedTransform;
    FUN_004e5e40(&convertedTransform, &first->transform);
    sourceTransform.FUN_00924ea0();
    targetTransform.FUN_00924ea0();
    info.data->tau = -0.1f;
    info.data->damping = 0.1f;
    info.data->SetStrength(1.0f);
    Point3 direction;
    direction.x = resolvedFirst->host->transform.r00;
    direction.y = resolvedFirst->host->transform.r10;
    direction.z = resolvedFirst->host->transform.r20;
    hkVector4f axis;
    axis.y = direction.y;
    axis.x = direction.x;
    axis.z = direction.z;
    axis.Normalize3();
    info.data->FUN_0092b430(&sourceTransform, &targetTransform, &sourceTransform.translation, &axis);
    FUN_008fa290* constraint = new FUN_008fa290(&info);
    sourceBody->FUN_00900ad0(constraint);
    unsigned int bits;
    unsigned int sourceBits;
    { const FilterInfo sourceFilter = sourceBody->FUN_00424270(); sourceBits = sourceFilter.value; }
    unsigned int layer = targetBody->FUN_00424270().value & 0x7f;
    bits = static_cast<const volatile unsigned int&>(filter.value);
    bits &= 0xffff1400;
    bits |= sourceBits & 0xe080;
    bits |= 0x1400;
    bits = (bits & ~0x7f) | (layer & 0x7f);
    sourceBody->FUN_0056c440(bits);
    BodyWorld* world = FUN_005685e0(targetBody->GetWorld());
    if (!world)
    {
        NodeHost* fallbackNode = FUN_00424d50(&DAT_010f2ee0, resolvedSecond);
        if (fallbackNode)
            world = fallbackNode->world;
    }
    if (world && targetBody->FUN_00726810())
    {
        if (!sourceBody->GetWorld())
            world->FUN_004e5ea0(sourceBody);
        else
            sourceBody->FUN_008ff290(world);
    }
    if (skipped)
        FUN_008fa770(first, world);
}


class NiAVObject;
struct KnockDownNode;
struct CollisionObject;
struct RigidBody;
class NiTimeController;
struct PhysicsBody;
class NiRTTI;

struct hkVector4
{
    __m128 v;
};
class NiPoint3_helper : public NiPoint3
{
  public:
    NiPoint3 operator*(float scale) const;
};
struct bhkFilter
{
    unsigned int value;
};
struct VirtualObject
{
    virtual void VirtualUnknown00();
    virtual void VirtualUnknown04();
    virtual void VirtualUnknown08();
    virtual KnockDownNode* GetNode();
    virtual void VirtualUnknown10();
    virtual void VirtualUnknown14();
    virtual void VirtualUnknown18();
    virtual void VirtualUnknown1c();
    virtual void VirtualUnknown20();
    virtual void VirtualUnknown24();
    virtual void VirtualUnknown28();
    virtual void VirtualUnknown2c();
    virtual void VirtualUnknown30();
    virtual void VirtualUnknown34();
    virtual void VirtualUnknown38();
    virtual void VirtualUnknown3c();
    virtual void VirtualUnknown40();
    virtual void VirtualUnknown44();
    virtual void VirtualUnknown48();
    virtual void VirtualUnknown4c();
    virtual void VirtualUnknown50();
    virtual void VirtualUnknown54();
    virtual void VirtualUnknown58();
    virtual void VirtualUnknown5c();
    virtual void VirtualUnknown60();
    virtual void VirtualUnknown64();
    virtual void VirtualUnknown68();
    virtual void VirtualUnknown6c();
    virtual void VirtualUnknown70();
    virtual void VirtualUnknown74();
    virtual void VirtualUnknown78();
    virtual void VirtualUnknown7c();
    virtual void VirtualUnknown80();
    virtual void VirtualUnknown84();
    virtual void VirtualUnknown88();
    virtual void Update(float);
    virtual void VirtualUnknown90();
    virtual void VirtualUnknown94();
    virtual void VirtualUnknown98();
    virtual void VirtualUnknown9c();
    virtual void VirtualUnknowna0();
    virtual void VirtualUnknowna4();
    virtual void VirtualUnknowna8();
    virtual void VirtualUnknownac();
    virtual void SetMotion(int, int, int);
    virtual void VirtualUnknownb4();
    virtual void VirtualUnknownb8();
    virtual void VirtualUnknownbc();
    virtual void VirtualUnknownc0();
    virtual void VirtualUnknownc4();
    virtual void VirtualUnknownc8();
    virtual void VirtualUnknowncc();
    virtual void VirtualUnknownd0();
    virtual void VirtualUnknownd4();
    virtual void VirtualUnknownd8();
    virtual void VirtualUnknowndc();
    virtual void VirtualUnknowne0();
    virtual void SetBodyMotion(int);
};
struct PhysicsBody
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int filterInfo;
};
struct RigidBody : public VirtualObject
{
    unsigned int unk04;
    PhysicsBody* body;
    bhkFilter FUN_0043b4f0();
    unsigned int GetFilter();
};
struct CollisionObject : public VirtualObject
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    RigidBody* rigidBody;
    unsigned int unk14;
    float beginValue, endValue;
    void ApplyMotion();
};
class NiObject : public VirtualObject
{
  public:
    NiObject* DynamicCast(const NiRTTI* rtti);
};
class NiAVObject : public VirtualObject
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    NiObject* collision;
    NiTimeController* GetController(const NiRTTI* rtti);
};
struct KnockDownNode
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
    NiAVObject** children;
    unsigned short capacity, childCount;
};
struct NiInterpControllerTriple
{
    float time, value, tangent;
    NiInterpControllerTriple();
};
struct ControllerKeys
{
    void* vtable;
    NiInterpControllerTriple* data;
    unsigned int capacity, size, effectiveSize, growBy;
    void Reserve(unsigned int count);
};
class NiTimeController : public VirtualObject
{
  public:
    unsigned int unk04;
    unsigned short flags, unk0a;
    float frequency, phase, startTime, stopTime;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    ControllerKeys keys;
    float unk50, unk54;
    unsigned int mode;
    void Reset();
    void AddKey(const NiInterpControllerTriple& key);
};
struct BodyState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    PhysicsBody physics;
};
inline unsigned int RigidBody::GetFilter()
{
    BodyState* state = (BodyState*)body;
    if (state)
    {
        PhysicsBody* physics = &state->physics;
        if (physics)
            return physics->filterInfo;
    }
    return 0;
}
extern float DAT_01015f5c, DAT_011b0f88, DAT_011b0f8c, DAT_011afe64;
hkVector4& FUN_004a3e00(hkVector4& result, const NiPoint3& point);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void* operator new[](unsigned int, void* p)
{
    return p;
}
struct PlainKey
{
    float time, value, tangent;
};
union KeyVectorStorage
{
    PlainKey keys[2];
    hkVector4 vector;
};
// @f3 0x009158c0 (community match, verified in this file)
struct KnockDownNode;
union KeyVectorStorage;
struct NiInterpControllerTriple;

class NativeVirtual
{
  public:
    virtual void VirtualUnknown00();
    virtual void VirtualUnknown04();
    virtual void VirtualUnknown08();
    virtual KnockDownNode* GetNode();
    virtual void VirtualUnknown10();
    virtual void VirtualUnknown14();
    virtual void VirtualUnknown18();
    virtual void VirtualUnknown1c();
    virtual void VirtualUnknown20();
    virtual void VirtualUnknown24();
    virtual void VirtualUnknown28();
    virtual void VirtualUnknown2c();
    virtual void VirtualUnknown30();
    virtual void VirtualUnknown34();
    virtual void VirtualUnknown38();
    virtual void VirtualUnknown3c();
    virtual void VirtualUnknown40();
    virtual void VirtualUnknown44();
    virtual void VirtualUnknown48();
    virtual void VirtualUnknown4c();
    virtual void VirtualUnknown50();
    virtual void VirtualUnknown54();
    virtual void VirtualUnknown58();
    virtual void VirtualUnknown5c();
    virtual void VirtualUnknown60();
    virtual void VirtualUnknown64();
    virtual void VirtualUnknown68();
    virtual void VirtualUnknown6c();
    virtual void VirtualUnknown70();
    virtual void VirtualUnknown74();
    virtual void VirtualUnknown78();
    virtual void VirtualUnknown7c();
    virtual void VirtualUnknown80();
    virtual void VirtualUnknown84();
    virtual void VirtualUnknown88();
    virtual void Update(float);
    virtual void VirtualUnknown90();
    virtual void VirtualUnknown94();
    virtual void VirtualUnknown98();
    virtual void VirtualUnknown9c();
    virtual void VirtualUnknowna0();
    virtual void VirtualUnknowna4();
    virtual void VirtualUnknowna8();
    virtual void VirtualUnknownac();
    virtual void SetMotion(int, int, int);
    virtual void VirtualUnknownb4();
    virtual void VirtualUnknownb8();
    virtual void VirtualUnknownbc();
    virtual void VirtualUnknownc0();
    virtual void VirtualUnknownc4();
    virtual void VirtualUnknownc8();
    virtual void VirtualUnknowncc();
    virtual void VirtualUnknownd0();
    virtual void VirtualUnknownd4();
    virtual void VirtualUnknownd8();
    virtual void SetNativeBodyMotion(int);
    virtual void VirtualUnknowne0();
    virtual void SetBodyMotion(int);
};
struct NativePhysicsBody
{
    void* field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int filterInfo;
};
struct NativeBodyState
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    NativePhysicsBody physics;
    void FUN_00571d10(float, const hkVector4&);
};
struct NativeRigidBody : public NativeVirtual
{
    unsigned int field04;
    NativeBodyState* body;
    FilterInfo FUN_00424270();
    unsigned int GetFilterNative();
};
struct NativeCollision : public NativeVirtual
{
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    NativeRigidBody* rigidBody;
    unsigned int field14;
    float beginValue, endValue;
    void FUN_008f3760();
};
struct NativeKeys
{
    void* vtable;
    NiInterpControllerTriple* data;
    unsigned int capacity, size, effectiveSize, growBy;
    void FUN_009147c0(unsigned int count);
};
class NativeTime : public NativeVirtual
{
  public:
    unsigned int field04;
    unsigned short flags, field0a;
    float frequency, phase, startTime, stopTime;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    NativeKeys keys;
    float field50, field54;
    unsigned int mode;
    void FUN_00914c00();
    void FUN_00915470(const NiInterpControllerTriple& key);
};
class NativeAV : public NativeVirtual
{
  public:
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    NativeTime* FUN_00825200(const NiRTTI* rtti);
};
class PointMul : public NiPoint3
{
  public:
    NiPoint3 FUN_00432b40(float scale) const;
};

inline unsigned int NativeRigidBody::GetFilterNative()
{
    if (body)
    {
        NativePhysicsBody* physics = &body->physics;
        if (physics)
            return physics->filterInfo;
    }
    return 0;
}

NativeCollision* __cdecl FUN_007235f0(NativeAV* object);
NativeCollision* __cdecl FUN_00424fe0(NativeAV* object);
hkVector4& __cdecl FUN_00468f10(hkVector4& result, const NiPoint3& point);
void __cdecl bhkForceController_TestForce2(NativeAV* object, const hkVector4& velocity, float scale);
extern float DAT_00f7abf8[32];
extern float DAT_00db7260, DAT_00f7a970, DAT_00f7a974, DAT_00f79460;
extern unsigned int DAT_010f33dc;

void __cdecl FUN_00c9b670(NiAVObject* argument, const NiPoint3& velocity, unsigned int context, float time, bool disable)
{
    NiPoint3 sharedPoint;
    struct PlainKeyPair { PlainKey k0, k1; };
    struct __declspec(align(16)) AlignedVec4 { float x, y, z, w; };
    union SafeWork { PlainKeyPair keys; AlignedVec4 vector; } work;
    if (argument)
    {
        NativeCollision* collision = FUN_007235f0((NativeAV*)argument);
        if (collision)
        {
            collision->FUN_008f3760();
            unsigned int filter = 0;
            if (collision->rigidBody)
                filter = collision->rigidBody->GetFilterNative();
            float speed = DAT_00f7abf8[(filter >> 8) & 31];
            NativeTime* controller = ((NativeAV*)argument)->FUN_00825200((const NiRTTI*)&DAT_010f32f8);
            if (controller && speed >= 0.0f)
            {
                if (!disable)
                {
                    float begin = collision->beginValue;
                    float end = collision->endValue;
                    controller->FUN_00914c00();
                    unsigned int count = 2;
                    controller->mode = count;
                    if (controller->keys.effectiveSize == 0)
                    {
                        NiInterpControllerTriple* values = new (&work.keys) NiInterpControllerTriple[2];
                        values[0].value = begin;
                        values[0].tangent = end;
                        values[0].time = 0.0f;
                        values[1].value = 0.0f;
                        values[1].tangent = 0.0f;
                        values[1].time = speed;
                        controller->keys.FUN_009147c0(2);
                        NiInterpControllerTriple* key = values;
                        do { controller->FUN_00915470(*key); ++key; } while (--count != 0);
                        unsigned short flags = controller->flags;
                        controller->startTime = time;
                        controller->stopTime = speed;
                        controller->flags = (flags & 0xfef5) | 0xc5;
                        controller->phase = 0.0f;
                        controller->frequency = 1.0f;
                        controller->Update(DAT_00db7260);
                    }
                    NativeAV* active = *(NativeAV* const volatile*)&argument;
                    if (!active->FUN_00825200((const NiRTTI*)&DAT_010f33dc))
                    {
                        new (&sharedPoint) NiPoint3(static_cast<const PointMul&>(velocity).FUN_00432b40(DAT_00f7a970));
                        bhkForceController_TestForce2(active, FUN_00468f10(reinterpret_cast<hkVector4&>(work.vector), sharedPoint), DAT_00f7a974);
                        argument = (NiAVObject*)active;
                    }
                }
                else collision->SetMotion(1, 0, 0);
            }
        }
        else
        {
            NativeCollision* fallback = FUN_00424fe0((NativeAV*)argument);
            if (fallback && fallback->rigidBody)
            {
                NativeRigidBody* body = fallback->rigidBody;
                unsigned int filter = body->FUN_00424270().value;
                unsigned int layer = filter & 0x7f;
                if ((layer != 8 && layer != 29) || (filter & 0x1f00) == 0x1400)
                {
                    body->SetNativeBodyMotion(1);
                    if (!disable)
                    {
                        new (&sharedPoint) NiPoint3(static_cast<const PointMul&>(velocity).FUN_00432b40(DAT_00f7a970));
                        body->body->FUN_00571d10(DAT_00f79460, FUN_00468f10(reinterpret_cast<hkVector4&>(work.vector), sharedPoint));
                    }
                }
            }
        }
        KnockDownNode* node = ((NativeAV*)argument)->GetNode();
        if (node)
            for (unsigned int i = 0; i < node->childCount; ++i)
                FUN_00c9b670(node->children[i], velocity, context, time, disable);
    }
}

