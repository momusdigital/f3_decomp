#include "f3_common.h"
#include "havok/hkMonitorStream.h"
// src/havok/physics/dynamics/phantom/hkpaabbphantom_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpaabbphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpAabbPhantom.h"
struct hkBoolXcf24d0
{
    char m_cBooleanValue;
    hkBoolXcf24d0(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};
template <class T> class hkArrayXcf24d0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct PresentFlag
{
    bool value;
    PresentFlag(bool v) : value(v)
    {}
    PresentFlag(const PresentFlag& v) : value(v.value)
    {}
};
int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();
template <class T> class hkArrayCF2A
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};
class hkStatisticsCollectorCF2A
{
  public:
    virtual ~hkStatisticsCollectorCF2A() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayCF2A<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int iAllocated = FUN_00d06f80(kArray.m_data, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};
class hkMemoryAllocatorCF2C;
struct hkMemoryRouterCF2C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF2C* m_pStreamAllocator;
    hkMemoryAllocatorCF2C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF2C& __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <class T> __forceinline void constructWithCopyCF2C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> class hkArrayCF2C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorCF2C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyCF2C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
struct hkLessCF2B
{
};
void __cdecl QuickSortShapeDetails(void** pArr, int iStart, int iEnd, hkLessCF2B kCmp);
inline void quickSortCF2B(void** pArr, int iSize, hkLessCF2B kCmp)
{
    if (iSize > 1)
        QuickSortShapeDetails(pArr, 0, iSize - 1, kCmp);
}
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;
struct DummyBool
{
    char m_cBooleanValue;
};
struct __declspec(align(16)) ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};
struct DummyNormal : public hkVector4
{
    void FUN_00c7f700(const void* rot, const void* dir);
};
struct DummyCollidable;
struct WorldRayCastOutput
{
    DummyNormal m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_uiShapeKeyIndex;
    int m_pad1c;
    hkUint32 m_shapeKeys0;
    hkUint32 m_shapeKeys1;
    hkUint32 m_shapeKeys2;
    hkUint32 m_shapeKeys3;
    hkUint32 m_shapeKeys4;
    hkUint32 m_shapeKeys5;
    hkUint32 m_shapeKeys6;
    hkUint32 m_shapeKeys7;
    hkUint32 m_shapeKeys8;
    hkUint32 m_shapeKeys9;
    hkUint32 m_shapeKeys10;
    hkUint32 m_shapeKeys11;
    const DummyCollidable* m_pRootCollidable;
};
struct DummyShape
{
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7() = 0;
    virtual DummyBool RayCast(const ShapeRayCastQuery& input, WorldRayCastOutput& output) const = 0;
};
struct DummyCollidable
{
    DummyShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    DummyCollidable* m_parent;
};
static inline void setRotatedInverseDir(hkVector4& out, const hkRotation& r, const __m128& b)
{
    __m128 c0 = *(const __m128*)&r.m_kColumn0;
    __m128 c1 = *(const __m128*)&r.m_kColumn1;
    __m128 c2 = *(const __m128*)&r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    __m128 r2 = _mm_mul_ps(c2, b2);
    *(__m128*)&out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
static inline void SetTransformedPosition(hkVector4& out, const hkTransform* t, const hkVector4& in)
{
    __m128 d = _mm_sub_ps(*(const __m128*)&in, *(const __m128*)&t->m_vTranslation);
    setRotatedInverseDir(out, t->m_rotation, d);
}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern float DAT_0104da4c;

struct MonTimerCmd
{
    const char* m_iFieldAfterHasHit;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};
struct MonStream
{
    char* unk00;
    char* m_kRayEnd;
    char* unk08;
    char* m_pCurrentCommand;
    static MonStream* GetInstance()
    {
        return (MonStream*)TlsGetValue(DAT_0126835c);
    }
    void Timer(const char* s)
    {
        if (m_kRayEnd < m_pCurrentCommand)
        {
            MonTimerCmd* h = (MonTimerCmd*)m_kRayEnd;
            h->m_iFieldAfterHasHit = s;
            volatile unsigned int t = (unsigned int)__rdtsc();
            h->m_uiStartTicks = t;
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct PadReal
{
    float v;
};
struct __declspec(align(16)) V4
{
    float q[4];
};
struct ShapeS
{
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct CollidableS
{
    ShapeS* m_pCollisionShape;
    int unk04;
    int* m_pMotionState;
};
struct CollInput
{
    void* m_pCollisionDispatcher;
    int m_weld;
    PadReal m_fScalar;
    void* m_iFilter;
    void* m_pConvexListCollisionFilter;
    int m_createPredictive;
    V4 m_aabb0;
    V4 m_aabb1;
    V4 m_aabb2;
    CollInput() : m_weld(0)
    {}
};
struct ProcInput : CollInput
{
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    V4 unk60;
    void* m_pConfiguration;
};
struct LcInput : CollInput
{
    V4 m_path;
    float m_fMaxExtraPenetration;
    float m_fStartPointTolerance;
    void* m_pConfiguration;
    LcInput()
    {
        m_fMaxExtraPenetration = DAT_0104da4c;
    }
    void set(const ProcInput& ci)
    {
        m_pCollisionDispatcher = ci.m_pCollisionDispatcher;
        m_weld = ci.m_weld;
        m_fScalar = ci.m_fScalar;
        m_iFilter = ci.m_iFilter;
        m_pConvexListCollisionFilter = ci.m_pConvexListCollisionFilter;
        m_createPredictive = ci.m_createPredictive;
        _mm_store_ps(m_aabb0.q, _mm_load_ps(ci.m_aabb0.q));
        _mm_store_ps(m_aabb1.q, _mm_load_ps(ci.m_aabb1.q));
        _mm_store_ps(m_aabb2.q, _mm_load_ps(ci.m_aabb2.q));
        m_pConfiguration = ci.m_pConfiguration;
    }
    void setTol(float tol)
    {
        m_fScalar.v = tol;
    }
};
struct LinCastInputS
{
    V4 m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
};
struct FilterS
{
    virtual void unk0();
    virtual bool* IsCollisionEnabled(bool* r, const CollidableS& a, const CollidableS& b) const;
};
typedef void(__cdecl* LinCastFunc)(const CollidableS&, const CollidableS&, const LcInput&, void*, void*);
struct CollisionAgentFunctionTable
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    LinCastFunc m_pLinearCastFunc;
};
struct RefObjS
{
    virtual ~RefObjS();
    int unk04;
};
struct CollFilterS : RefObjS, FilterS
{
};
struct DispatcherS
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
    unsigned char m_agent2TypeMap[32][32];
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    CollisionAgentFunctionTable m_agent2Funcs[1];
};
struct WorldS
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
    ProcInput* m_pCollisionInput;
    CollFilterS* m_pCollisionFilter;
    DispatcherS* m_pDispatcher;
};
struct PhantomS
{
    int unk00;
    int unk04;
    WorldS* m_pOwningWorld;
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
    CollidableS** m_overlapData;
    int m_overlapSize;
    void FUN_00cf2880(const CollidableS* collA, const LinCastInputS& input, void* castCollector, void* startCollector);
};
// @f3 0x00978d20 (community match, verified in this file)
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0116913c;
extern char DAT_00e7c970;
extern char DAT_00e32798;
extern float DAT_00de6e70;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier(void);
#include <math.h>
struct ThreadTimerS {int u00; char* ptr; int u08; char* end;};
struct __declspec(align(16)) CastS {
    int unk00;
    float f04;
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
    V4 m_path;
    float f60; float f64; int u68;
    void init(void* p);
};
struct FilterIfS {
    virtual void v00();
    virtual bool* IsCollisionEnabled(bool* enabled,const CollidableS& a,const CollidableS& b) const;
};
struct FilterHolderS { int u00; int u04; FilterIfS f; };
typedef void (__cdecl* AgentFn)(const CollidableS&,const CollidableS&,const CastS&,void*,void*);
struct AgentS { AgentFn fn; int u04; int u08; int u0C; int u10; };
struct InputS {
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
    int u6c;
};
void PhantomS::FUN_00cf2880(const CollidableS* collA,const LinCastInputS& query,void* collector,void* startCollector)
{
    HK_TIMER_BEGIN("hkpAabbPhantom::linearCast", HK_NULL);
    V4 relative;
    const float* motion=(const float*)collA->m_pMotionState+12;
    for(int i=0;i<4;++i) relative.q[i]=query.m_vTo.q[i]-motion[i];
    CastS cast;
    cast.f60=DAT_00de6e70;
    InputS* inp=(InputS*)m_pOwningWorld->unk6C;
    cast.init(inp);
    cast.u68=inp->u6c;
    cast.m_path.q[0]=relative.q[0]; cast.m_path.q[1]=relative.q[1]; cast.m_path.q[2]=relative.q[2]; cast.m_path.q[3]=relative.q[3];
    float sq=relative.q[0]*relative.q[0]+relative.q[1]*relative.q[1]+relative.q[2]*relative.q[2];
    float len=(float)sqrt(sq);
    cast.f64=len;
    cast.f04=query.m_fMaxExtraPenetrationAgainstFixed;
    cast.f60=query.m_fMaxExtraPenetration;
    void* disp=(void*)m_pOwningWorld->unk74;
    FilterHolderS* holder=(FilterHolderS*)m_pOwningWorld->unk70;
    int n=unkC4;
    for(int i=0;i<n;++i)
    {
        CollidableS* other=((CollidableS**)unkC0)[i];
        bool enabled;
        bool* r=holder->f.IsCollisionEnabled(&enabled,*collA,*other);
        if(!other->m_pCollisionShape || !*r || other==collA) continue;
        unsigned char idx=((unsigned char*)disp)[(collA->m_pCollisionShape->m_type+13)*32+other->m_pCollisionShape->m_type];
        AgentFn fn=((AgentS*)((char*)disp+0x9ac))[idx].fn;
        fn(*collA,*other,cast,collector,startCollector);
    }
    HK_TIMER_END();
}
