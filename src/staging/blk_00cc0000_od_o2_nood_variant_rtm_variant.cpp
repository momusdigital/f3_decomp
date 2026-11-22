// src/staging/blk_00cc0000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00cc0000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
#include <windows.h>
// src/staging/blk_00cc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00cc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.
// src/staging/blk_00cc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __declspec(thread) int tls_memContext;
struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext) { m_iSaved = tls_memContext; tls_memContext = aiMemoryContext; }
    ~MemContextGuard() { tls_memContext = m_iSaved; }
};
struct hkMemoryAllocator
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pThreadAllocator;
    hkMemoryAllocator& heap() { return *m_pThreadAllocator; }
};
hkMemoryRouterStub* FUN_00c85750();
struct hkVector4
{
    __m128 m_vComponents;
    void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
};
struct TransformObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
    hkVector4 m_v30;
    hkVector4 m_v40;
    hkVector4 m_v50;
    hkVector4 m_v60;
    hkVector4 m_v70;
    int unk80;
    float m_f84;
    float m_f88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;

    static void* operator new(unsigned int nbytes)
    {
        TransformObj* p = (TransformObj*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    TransformObj();
};
struct Cd2Target
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
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual bool Accepts(void* key);
};
struct Cd2Entry
{
    int unk00;
    int unk04;
    Cd2Target* m_target;
};
struct Cd2Iterable
{
    virtual void v00();
    virtual void v04();
    virtual int GetFirst();
    virtual int GetNext(int i);
    virtual void v10();
    virtual Cd2Entry* GetEntry(int i, char* buffer);
};
struct Cd2Collection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Cd2Iterable m_items;
};
class Cd2Owner
{
public:
    int unk00;
    int unk04;
    Cd2Collection* m_pShapeCollection;

    __forceinline Cd2Collection* GetCollection() { return this ? m_pShapeCollection : 0; }
    bool FUN_00cd2f10(void* key);
};
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_load_ps(float const*);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
void _mm_store_ps(float*, __m128);
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
__m128 _mm_xor_ps(__m128, __m128);
}
extern "C" const __m128 DAT_010c71e0;
extern "C" const __m128 DAT_010c44d0;
extern "C" const __m128 DAT_010c4c00;
extern "C" const __m128 DAT_010c7170;
extern "C" const __m128 DAT_010c4c10;
struct __declspec(align(16)) PoseVector {
    union { __m128 value; float lane[4]; };
    PoseVector() {}
    PoseVector(__m128 x):value(x) {}
    PoseVector(const PoseVector& x):value(x.value) {}
    PoseVector& operator=(const PoseVector& x) { value=x.value; return *this; }
    __forceinline __m128 dot(const PoseVector& other) const {
        __m128 a=_mm_mul_ps(value,other.value);
        __m128 b=_mm_add_ss(_mm_shuffle_ps(a,a,0x55),a);
        return _mm_add_ss(_mm_shuffle_ps(a,a,0xaa),b);
    }
    __forceinline __m128 dotLoaded(const PoseVector& other) const {
        __m128 a=_mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&value)),other.value);
        __m128 b=_mm_add_ss(_mm_shuffle_ps(a,a,0x55),a);
        return _mm_add_ss(_mm_shuffle_ps(a,a,0xaa),b);
    }
    __forceinline void cross(const PoseVector& a,const PoseVector& b) {
        __m128 first=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        __m128 second=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(first,second);
    }
    __forceinline void addProduct(const PoseVector& a,const PoseVector& b) {value=_mm_add_ps(_mm_mul_ps(a.value,b.value),value);}
    __forceinline void rotate(const PoseVector& q,const PoseVector& v) {
        __m128 real=_mm_shuffle_ps(q.value,q.value,0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real,real),DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value,square.value));
        __m128 dot3=q.dotLoaded(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3,dot3,0));
        accum.addProduct(dotSplat,q);
        PoseVector product;product.cross(q,v);
        PoseVector realV(real);accum.addProduct(realV,product);
        value=_mm_add_ps(accum.value,accum.value);
    }
    __forceinline void rotateBack(const PoseVector& q,const PoseVector& v) {
        __m128 real=_mm_shuffle_ps(q.value,q.value,0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real,real),DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value,square.value));
        __m128 dot3=q.dot(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3,dot3,0));
        accum.addProduct(dotSplat,q);
        PoseVector product;product.cross(v,q);
        PoseVector realV(real);accum.addProduct(realV,product);
        value=_mm_add_ps(accum.value,accum.value);
    }
};
struct PoseQuaternion {PoseVector vector; void FUN_00c66320(const PoseQuaternion&,const PoseQuaternion&);};
struct PoseTransform {
    PoseVector translation;
    PoseQuaternion rotation;
    PoseVector scale;
    PoseTransform& operator=(const PoseTransform& o) {translation=o.translation;rotation.vector=o.rotation.vector;scale=o.scale;return *this;}
    __forceinline void inverse(const PoseTransform& p) {
        translation.rotateBack(p.rotation.vector,p.translation);
        translation.value=_mm_xor_ps(translation.value,DAT_010c44d0);
        rotation.vector.value=_mm_xor_ps(p.rotation.vector.value,DAT_010c4c00);
        __m128 input=_mm_shuffle_ps(p.scale.value,_mm_unpackhi_ps(p.scale.value,DAT_010c7170),0xc4);
        __m128 seed=_mm_rcp_ps(input);
        __m128 correction=_mm_mul_ps(_mm_mul_ps(input,seed),seed);
        scale.value=_mm_and_ps(_mm_sub_ps(_mm_add_ps(seed,seed),correction),DAT_010c4c10);
    }
    __forceinline void multiply(const PoseTransform& a,const PoseTransform& b) {
        PoseVector moved;moved.rotate(a.rotation.vector,b.translation);
        translation.value=_mm_add_ps(a.translation.value,moved.value);
        rotation.FUN_00c66320(a.rotation,b.rotation);
        scale.value=_mm_mul_ps(a.scale.value,b.scale.value);
    }
    __forceinline void relative(const PoseTransform& a,const PoseTransform& b) {
        PoseTransform inverseParent;inverseParent.inverse(a);multiply(inverseParent,b);
    }
};
struct SkeletonData {
    int unk00,unk04,unk08;short* parents;
    int unk10,unk14,unk18;int count;
};
struct PoseState {
    SkeletonData* skeleton;PoseTransform* local;int unk08,unk0c;
    PoseTransform* world;int unk14,unk18;int* flags;int unk20,unk24;
    bool synchronized;
    const PoseTransform& FUN_00cda180(int);
    __forceinline const PoseTransform& getWorld(int i) {
        if(!(flags[i]&2))return world[i];
        return FUN_00cda180(i);
    }
    __forceinline const PoseTransform& getLocal(int i) {
        if(flags[i]&1) {
            const PoseTransform& boneWorld=world[i];
            short parent=skeleton->parents[i];
            if(parent!=-1) {const PoseTransform& parentWorld=getWorld(parent);local[i].relative(parentWorld,boneWorld);}
            else local[i]=boneWorld;
            flags[i]&=~1;
        }
        return local[i];
    }
    __forceinline void prepareChildren(int index) {
        const int count=skeleton->count;
        flags[index]|=4;
        for(int bone=index+1;bone<count;++bone) {
            short parent=skeleton->parents[bone];
            if(parent!=-1 && (flags[parent]&4)) {
                getLocal(bone);flags[bone]|=4;synchronized=false;
            }
        }
        for(int bone=index+1;bone<count;++bone) {
            int state=flags[bone];
            if(state&4) {state|=2;state&=~4;flags[bone]=state;}
        }
    }
    PoseTransform& FUN_00cda8e0(int index);
};
struct SpawnAllocator {
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};
struct SpawnHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAllocator* m_pAllocator;
};
struct FUN_00d4f2a0 {
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;
    __m128 m_50;
    __m128 m_60;
    __m128 m_70;
    int unk80;
    int unk84;
    float m_88;
    float m_8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_a0;
    int unkA4;
    int unkA8;
    int unkAC;
    float m_b0;
    float m_b4;
    int unkB8;
    int unkBC;

    FUN_00d4f2a0();
    static void operator delete(void* p) throw() {}
    static __forceinline void* operator new(unsigned int size) throw() {
        SpawnHolder* h = (SpawnHolder*)FUN_00c85750();
        void* p = h->m_pAllocator->Alloc(size);
        ((FUN_00d4f2a0*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
union hkVec4 { __m128 m_vComponents; char m_bytes[16]; };
struct EntityObj {
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    float unk50, unk54, unk58;
    char unk5C, unk5D;
    static void* operator new(unsigned int nbytes) {
        EntityObj* p=(EntityObj*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags=(unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);
    EntityObj(int a,int b,int c);
    void SetPivots(const hkVector4& position,const hkVector4& rotation);
    void removeReference();
};
struct ShapeVector
{
    hkVec4 m_v;
    ShapeVector(float x, float y, float z, float w) { m_v.m_vComponents = _mm_setr_ps(x, y, z, w); }
};
struct IntegerBlock18
{
    int unk00;
    int m_iType;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
};
struct ShapeObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
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

    static void* operator new(unsigned int nbytes)
    {
        ShapeObj* p = (ShapeObj*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    ShapeObj(int iType, const ShapeVector& kVec, float fA, float fB);
    void FUN_00c905b0();
};
struct ShapeOwner
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
    virtual void addObject(struct ShapeObj* pkObj);
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
    virtual void finish(struct IntegerBlock18* pkInfo);
    void FUN_00cc3710(IntegerBlock18* pkInfo);
};
struct S00cc4610_Out {
    int unk00; unsigned short m_iElementCount; unsigned short unk06; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    __m128 q20;
    float m_30;
    float m_34;
    int unk38; int unk3C;
    S00cc4610_Out(int a, int b, int c);
    void* operator new(unsigned int n) {
        hkMemoryAllocator& a = FUN_00c85750()->heap();
        void* p = a.allocateChunk(n);
        ((S00cc4610_Out*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
};
struct S00cc4610_Scope {
    int saved;
    S00cc4610_Scope() { saved = tls_memContext; tls_memContext = 0x10; }
    ~S00cc4610_Scope() { tls_memContext = saved; }
};
static inline void s00cc4610_copy(__m128& d, const __m128& s) { d = s; }
struct __declspec(align(16)) Cc7Vector { unsigned char lanes[16]; };
extern "C" void _ReadWriteBarrier();
struct TypeHeader { unsigned int unk00, unk04, unk08, typeCode; };
struct TypeAttributes { unsigned int attributes; };
struct ObjectType : TypeHeader, TypeAttributes {};
union __declspec(align(16)) Lane128Q { float f32[4]; unsigned __int64 u64[2]; __int8 i8[16]; };
struct ScratchGeometry {
    Lane128Q dimensions;
    float tolerance, radius, margin;
    unsigned char useA, useB, specialShape, useD, useE;
    void FUN_00d54de0();
};
extern void* __cdecl hkpMoppUtility_buildCode(const void*, ScratchGeometry*, unsigned int);
union Quaternion525 {
    __m128 value;
    char bytes[16]; // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
    Quaternion525() {}
    Quaternion525& operator=(const Quaternion525& other) { value=other.value; return *this; }
};
struct StringArray525 : NiTObjectArray<char*> {
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int,char* const&);
    void append(char* const& value) {
        unsigned int index=m_usSize;
        if(index>=m_usMaxSize) FUN_0096ad30(index+m_usGrowBy);
        FUN_0096ae90(index,value);
    }
};
class PositionText525 {
public:
    float x,y,z;
    char* FUN_00a59af0(const char*);
};
char* __cdecl FUN_00a7d330(void*);
char* __cdecl FUN_00a7d550(const char*,float);
void __cdecl FUN_00458620(PositionText525*,const Quaternion525*);
struct TlsState { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; };
extern __declspec(thread) TlsState g_tlsState;
class MemoryManager { public: void* Allocate(unsigned int size); };
extern MemoryManager _g_memoryManager;
struct Holder;
struct CinfoVector {
    hkVec4 value;
    __forceinline CinfoVector(__m128 vector) { value.m_vComponents = vector; }
};
extern "C" __m128 _mm_set_ps1(float);
struct CachedObj {
    int unk00;
    int unk04;
    float unk08;
    int unk0c;
    __m128 unk10;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct AutoMemContext {
    int m_saved;
    AutoMemContext(int ctx) { m_saved = g_tlsState.unk2b4; g_tlsState.unk2b4 = ctx; }
    ~AutoMemContext() { g_tlsState.unk2b4 = m_saved; }
};
struct Holder {
    int unk00;
    int unk04;
    void* unk08;
    CachedObj* unk0c;
    int unk10;
    int unk14;
    void FUN_00ccbce0(void* p);
    CachedObj* FUN_00ccbfa0(bool* created);
};
inline void* AllocAligned(unsigned int size)
{
    unsigned char* p = (unsigned char*)_g_memoryManager.Allocate(size);
    unsigned char pad = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
    p += pad;
    p[-1] = pad;
    return p;
}
struct Vec { float x,y,z; };
struct Mat { float xx,xy,xz,yx,yy,yz,zx,zy,zz; };
union __declspec(align(16)) Transform { struct { __m128 a,b,c,d; }; char bytes[64]; };
struct TLSData {
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
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
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
int context; };
extern __declspec(thread) TLSData g_tlsBlock;
struct Context {
 unsigned int previous;
 Context() { previous=g_tlsBlock.context; g_tlsBlock.context=0x10; }
 ~Context() { g_tlsBlock.context=previous; }
};
struct ConvexShapeNode {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void attach(ConvexShapeNode*,int);
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
Mat rotation; Vec position;
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
ConvexShapeNode(unsigned short); static void* operator new(unsigned int); void SetParentObject(const struct Name&); };
extern char* emptyString;
struct Name { char* value; static char* InternString(const char*); Name(const char* s):value(InternString(s)){} ~Name(){if(value!=emptyString) InterlockedDecrement(reinterpret_cast<volatile long*>(value)-2);} };
void FUN_00458620(Vec*,__m128*);
extern "C" {
__m128 _mm_set_ps1(float);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_max_ps(__m128, __m128);
}
struct BoundsVector : hkVector4
{
    __forceinline const __m128& Get() const { return m_vComponents; }
    __forceinline void SetAll(float value) { m_vComponents = _mm_set_ps1(value); }
    __forceinline void Min(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_min_ps(a.Get(), b.Get());
    }
    __forceinline void Max(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_max_ps(a.Get(), b.Get());
    }
};
struct BoundsBox
{
    BoundsVector m_kMinimumCorner;
    BoundsVector m_kMaximumCorner;
    __forceinline void Include(const BoundsVector& point)
    {
        m_kMinimumCorner.Min(m_kMinimumCorner, point);
        m_kMaximumCorner.Max(m_kMaximumCorner, point);
    }
};
extern __declspec(thread) int DAT_tls_field;
struct S00cc2530_ScopedHeap306 {
 unsigned int old;
 S00cc2530_ScopedHeap306(unsigned int n) {old=DAT_tls_field;DAT_tls_field=n;}
 ~S00cc2530_ScopedHeap306() {DAT_tls_field=old;}
};
struct S00cc2530_Alloc306 {virtual void f0();virtual void* Allocate(int);virtual void Free(void*,int);};
struct S00cc2530_Router306 {int unk00,unk04,unk08,unk0c;S00cc2530_Alloc306* heap; S00cc2530_Alloc306* GetAllocator() {return heap;}};
namespace Memory306 {extern "C" S00cc2530_Router306* FUN_00c85750();}
struct S00cc2530_Source306 {int a,b,unk08,unk0c,unk10,unk14,unk18,unk1c;float m[16];};
struct __declspec(align(16)) Transform306 {float m[16];};
struct S00cc2530_FUN_00d4ce10 {
 virtual ~S00cc2530_FUN_00d4ce10();
 unsigned short memorySize;short references;
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
 unsigned int unka0;
 unsigned int unka4;
 unsigned int unka8;
 unsigned int unkac;
 unsigned int unkb0;
 unsigned int unkb4;
 unsigned int unkb8;
 unsigned int unkbc;
 unsigned int unkc0;
 unsigned int unkc4;
 unsigned int unkc8;
 unsigned int unkcc;
 unsigned int unkd0;
 unsigned int unkd4;
 unsigned int unkd8;
 unsigned int unkdc;
 unsigned int unke0;
 unsigned int unke4;
 unsigned int unke8;
 unsigned int unkec;
 unsigned int unkf0;
 unsigned int unkf4;
 unsigned int unkf8;
 unsigned int unkfc;
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

 S00cc2530_FUN_00d4ce10(int, const __m128*,int);
 void removeReference();
 static void* operator new(unsigned int n) {
  void* p=Memory306::FUN_00c85750()->GetAllocator()->Allocate(n);
  static_cast<S00cc2530_FUN_00d4ce10*>(p)->memorySize=(unsigned short)n;
  return p;
 }
 static void operator delete(void* p) {Memory306::FUN_00c85750()->GetAllocator()->Free(p,0x170);}
};
__forceinline __m128* BuildTransform306(S00cc2530_Source306* src,__m128* t) {
t[0]=_mm_setr_ps(src->m[0],src->m[1],src->m[2],src->m[3]);
t[1]=_mm_setr_ps(src->m[4],src->m[5],src->m[6],src->m[7]);
t[2]=_mm_setr_ps(src->m[8],src->m[9],src->m[10],src->m[11]);
t[3]=_mm_setr_ps(src->m[12],src->m[13],src->m[14],src->m[15]);
return t;}
struct SourceGeometry {
    unsigned int type;
    unsigned int owner;
    unsigned int count;
    unsigned int options;
    __m128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    void FUN_00c905b0();
};
struct InitializePathingRequestFromPosition {
    unsigned int id;
    ObjectType* type;
    SourceGeometry* cachedGeometry;
    float scale;
};
struct RefCountedObject {
    void FUN_00c905b0();
};
namespace fnvc_adapt { extern SourceGeometry* __cdecl hkpMoppUtility_buildCode(const void* attributes,
                                              ScratchGeometry* scratch,
                                              unsigned int options); }
extern int DAT_0102e368;
struct Shape : RefCountedObject {
    const void** volatile methods;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    __m128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    unsigned int combinedFlags;
    unsigned char kind;
    static void* operator new(unsigned int bytes) {
        hkMemoryRouterStub* router = FUN_00c85750();
        Shape* result = static_cast<Shape*>(router->heap().allocateChunk(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    Shape(const __m128& scaled, unsigned int materialValue, unsigned int shapeFlags) {
        methods = reinterpret_cast<const void**>(&DAT_0102e368);
        state = 1;
        dimensions = scaled;
        flags = shapeFlags;
        material = materialValue;
        combinedFlags = shapeFlags | 0x80000000u;
        kind = 2;
    }
};
struct FUN_00cc9d00 : RefCountedObject {
    unsigned int unk00;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    __m128 dimensions;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_00cc9d00(ObjectType* type, Shape* shape, SourceGeometry* geometry);
    static void* operator new(unsigned int bytes) {
        hkMemoryRouterStub* router = FUN_00c85750();
        FUN_00cc9d00* result = static_cast<FUN_00cc9d00*>(router->heap().allocateChunk(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    static void operator delete(void* memory);
};
struct OutputHandler {
    void FUN_00cca6f0(InitializePathingRequestFromPosition* request);
};
typedef void (__thiscall *OutputMethod)(OutputHandler*, void*);
typedef void (__thiscall *RequestMethod)(OutputHandler*, InitializePathingRequestFromPosition*);
struct ThreadTlsBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern volatile unsigned int DAT_0126fd98;
struct TlsFlagGuard {
    ThreadTlsBlock* m_blk;
    unsigned int m_saved;
    TlsFlagGuard() { unsigned int index = DAT_0126fd98; m_blk = reinterpret_cast<ThreadTlsBlock**>(__readfsdword(0x2c))[index]; m_saved = m_blk->m_2b4; m_blk->m_2b4 = 0x10; }
    ~TlsFlagGuard() { m_blk->m_2b4 = m_saved; }
};
struct NameArr {
    virtual ~NameArr();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int i, const unsigned int& v);
};
struct __declspec(align(16)) Blk {
    int i0;
    float f4;
    float f8;
    float fc;
    float v0, v1, v2, v3;
    float w0, w1, w2, w3;
    float z0;
    float z1, z2;
};
unsigned int __cdecl FUN_00a7d330(unsigned int v);
namespace fnvc_adapt { unsigned int __cdecl FUN_00a7d550(const char* s, float f); }
static void AddName(NameArr* arr, const unsigned int& v) {
    unsigned int n = arr->m_usSize;
    if (n >= arr->m_usMaxSize) {
        arr->FUN_0096ad30(n + arr->m_usGrowBy);
    }
    arr->FUN_0096ae90(n, v);
}
extern "C" void _mm_store_ss(float*, __m128);
struct hkVec4Q {
    hkVec4 storage;
    __forceinline void setSub4(const hkVec4Q& a, const hkVec4Q& b) { storage.m_vComponents = _mm_sub_ps(a.storage.m_vComponents, b.storage.m_vComponents); }
    __forceinline __m128 dot3(const hkVec4Q& a) const
    {
        __m128 x2 = _mm_mul_ps(storage.m_vComponents, a.storage.m_vComponents);
        __m128 result = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), result);
    }
};
struct AlignedPairData {
    hkVec4Q m_vContactPosition;
    hkVec4Q m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_type;
    int unk28;
    int unk2C;
    hkVec4Q unk30;
    hkVec4Q unk40;
    hkVec4Q unk50;
    hkVec4Q unk60;
};
template <int ELEMENTSIZE>
__forceinline void memCpyOneAligned(void* dst, const void* src)
{
    int i = 0;
    do {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    } while (++i < int(ELEMENTSIZE / 8));
}
struct ContactArray {
    AlignedPairData* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline AlignedPairData& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAligned<sizeof(AlignedPairData)>(m_data + index, m_data + m_iElementCount);
    }
};
extern "C" __m128 _mm_setzero_ps();
extern float DAT_011b153c;
union hkVecQ3E
{
    __m128 m_vComponents;
    char m_bytes[16];
    __forceinline hkVecQ3E() {}
    __forceinline hkVecQ3E(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};
struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    __forceinline hkReferencedObject() { m_sReferenceCount = 1; }

    __forceinline static void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* p = (hkReferencedObject*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    void FUN_00c905b0();
};
struct hkpShape : hkReferencedObject
{
    int m_ulUserData;
    int m_type;

    __forceinline hkpShape(int iType) { m_ulUserData = 0; m_type = iType; }
};
struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;

    __forceinline hkpConvexShape(int iType, float fRadius) : hkpShape(iType) { m_fSphereRadius = fRadius; }
};
struct ShapeObj_SI : hkpConvexShape
{
    unsigned short unk14;
    unsigned char unk16;
    unsigned char unk17;
    hkVecQ3E m_v20;
    hkVecQ3E m_v30;
    hkVecQ3E m_v40;
    hkVecQ3E m_v50;

    __forceinline ShapeObj_SI(const hkVecQ3E& a, const hkVecQ3E& b, const hkVecQ3E& c, float fRadius = DAT_011b153c)
        : hkpConvexShape(3, fRadius)
    {
        m_v20.m_vComponents = a.m_vComponents;
        m_v30.m_vComponents = b.m_vComponents;
        m_v40.m_vComponents = c.m_vComponents;
        m_v50.m_vComponents = _mm_setzero_ps();
        unk14 = 0;
        unk17 = 0;
        unk16 = 6;
    }
    virtual ~ShapeObj_SI();
};
void* __cdecl FUN_00aa13e0(unsigned);
void __cdecl FreeStorage(void*);
using ::MemoryManager;
using ::_g_memoryManager;
struct ExtendedMeshFloat {
    float value;
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }
};
struct ExtendedMeshIndex {
    unsigned short value;
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }
};
struct Vec3 { float x,y,z; };
struct Triangle { unsigned short a,b,c,unk06; };
struct Region { unsigned value; unsigned count; unsigned other; };
struct Geometry {

    unsigned unk00,unk04;

    unsigned short triangleCount,unk0A,unk0C,unk0E,regionCount,unk12;

    Triangle* triangles;

    Vec3* vertices;

    unsigned unk1C,unk20;

    Region* regions;

    __forceinline bool GetTriangle(unsigned short index,Triangle*& out) {

        out=&triangles[index];

        return index>=triangleCount;

    }

};
struct MeshPart {
    static void* operator new[](unsigned size) { return _g_memoryManager.Allocate(size); }

    unsigned vertexCount;

    Vec3* vertices;

    unsigned triangleCount;

    unsigned short* indices;

    struct Bounds* bounds;

    MeshPart();

    ~MeshPart();

};
struct Bounds { unsigned first,second; __forceinline void Init(unsigned a,unsigned b) { first=a;second=b; } };
struct FUN_00a5d3a0 {

    FUN_00a5d3a0();

    virtual ~FUN_00a5d3a0();

    unsigned references;

};
struct Mesh : FUN_00a5d3a0 {

    unsigned count;

    MeshPart* parts;

    static void* operator new(unsigned n) { return FUN_00aa13e0(n); }

    Mesh() : count(0), parts(0) {}

    virtual ~Mesh();

};
extern void* indexVtable[];
struct IndexArray {

    void** vtable;

    ~IndexArray() { FreeStorage(data); }

    unsigned short* data;

    unsigned short capacity,size,used,grow;

    IndexArray() { capacity=0; grow=1; size=0; used=0; data=0; vtable=indexVtable; }

    void Resize(unsigned);

    __forceinline void Append(unsigned short value) { SetAt(size,value); }

    __forceinline void SetAt(unsigned index,unsigned short value) {

        if(index>=capacity) Resize(index+grow);

        if(index>=size) {

            size=index+1;

            if(value) ++used;

        } else if(value) {

            if(!data[index]) ++used;

        } else {

            if(data[index]) --used;

        }

        data[index]=value;

    }

    void Clear() {

        unsigned short* values=data;

        unsigned short count=size;

        for(unsigned short index=0;index<count;++index) values[index]=0;

        size=0; used=0;

    }

};
struct __declspec(align(16)) ExtendedMeshStoredVector {
    hkVec4 lanes;
    __forceinline ExtendedMeshStoredVector& operator=(__m128 v) { _mm_store_ps(reinterpret_cast<float*>(&lanes.m_bytes[0]),v);return *this; }
    __forceinline operator const __m128&() const { return *reinterpret_cast<const __m128*>(&lanes.m_bytes[0]); }
};

struct ThreadBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int allocationType;
};
extern "C" { extern __declspec(thread) ThreadBlock s_tlsData; }
struct AllocationTypeScope {
    unsigned int previous;
    AllocationTypeScope(unsigned int type) : previous(s_tlsData.allocationType) {s_tlsData.allocationType=type;}
    ~AllocationTypeScope() {s_tlsData.allocationType=previous;}
};
struct RouterHeap {
    virtual void Unk00();
    virtual void* Allocate(int bytes);
    virtual void Release(void* memory,int bytes);
};
extern "C" __m128 _mm_load_ss(float const*);
struct SimdReal { hkVec4 m; SimdReal(float f){ m.m_vComponents=_mm_load_ss(&f);} };
union __declspec(align(16)) MotionVector {__m128 quad;hkVec4 storage;
    void Mul(const SimdReal& r){ quad=_mm_mul_ps(_mm_shuffle_ps(r.m.m_vComponents,r.m.m_vComponents,0),quad);}
    void Mul(float f){ __m128 s=_mm_load_ss(&f); quad=_mm_mul_ps(_mm_shuffle_ps(s,s,0),quad);}
};
class FUN_00d4edc0 {
public:
    void* vtable;
    unsigned short allocatedBytes;
    short references;
    int unk08,unk0c;
    MotionVector state10,state20,state30,state40,state50,state60,state70,state80,state90;
    float unkA0,valueA4,valueA8,unkAC,valueB0,valueB4,unkB8,unkBC;
    MotionVector stateC0,stateD0,stateE0,stateF0,state100,state110,state120,state130,state140,state150;
    FUN_00d4edc0();
    static void* operator new(size_t bytes) {
        void* memory=FUN_00c85750()->heap().allocateChunk((int)bytes);
        ((FUN_00d4edc0*)memory)->allocatedBytes=(unsigned short)bytes;
        return memory;
    }
    static void operator delete(void* memory) {
        FUN_00d4edc0* motion=(FUN_00d4edc0*)memory;
        RouterHeap* heap=(RouterHeap*)FUN_00c85750()->m_pThreadAllocator;
        heap->Release(memory,motion->allocatedBytes);
    }
};

extern "C" __m128 _mm_load_ss(const float*);
struct BlockAllocator {
    virtual void unknown00();
    virtual void* allocate(int);
    virtual void release(void*, int);
};
struct Motor513 {
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual Motor513* clone();
    void FUN_00c905b0();
};
struct Vector513 {
    float x,y,z,w;
    __m128 get() const { return *reinterpret_cast<const __m128*>(this); }
    void set(__m128 value) { *reinterpret_cast<__m128*>(this)=value; }
    Vector513& operator=(const Vector513& other) { set(other.get()); return *this; }
    void multiply(const float& scale) { hkVec4 s; s.m_vComponents=_mm_load_ss(&scale); set(_mm_mul_ps(_mm_shuffle_ps(s.m_vComponents,s.m_vComponents,0),get())); }
};
struct Transform513 { Vector513 axis0,axis1,axis2,translation; };
struct ConstraintReference513 {
    virtual void unknown00();
    unsigned short memorySize, referenceCount;
    unsigned int userData,unk0c;
};
struct FUN_00d4fe80 : ConstraintReference513 {
    unsigned int atom10,unk14,unk18,unk1c;
    Transform513 transformA,transformB;
    unsigned char a0,a1,motorEnabled,a3;
    unsigned int unkA4;
    float a8;
    Motor513* motor;
    unsigned int unkB0;
    float b4;
    unsigned int unkB8,unkBc,unkC0;
    unsigned short unkC4;
    unsigned char unkC6,unkC7;
    float minimum,maximum;
    FUN_00d4fe80();
    static void* allocate(hkMemoryAllocator& heap,unsigned int size) {
        FUN_00d4fe80* result=(FUN_00d4fe80*)heap.allocateChunk(size);
        result->memorySize=(unsigned short)size;
        return result;
    }
    static void* operator new(unsigned int size) {
        return allocate(FUN_00c85750()->heap(),size);
    }
    static void operator delete(void* p) { ((BlockAllocator*)FUN_00c85750()->m_pThreadAllocator)->release(p,((FUN_00d4fe80*)p)->memorySize); }
    void SetReferencedObject(Motor513*);
};
struct CloneData513 { unsigned int unk00,unk04,unk08,unk0c; float scale; };
struct CloneOwner513 {
    unsigned int unk00;
    FUN_00d4fe80* source;
    void ReleaseObject(FUN_00d4fe80*, CloneData513*);
    void FUN_00cc7600(FUN_00d4fe80*, CloneData513*);
};
// @f3 0x0094b1a0 (community match, verified in this file)
struct S_0094b1a0_ThreadMemory
{
    static DWORD s_tlsIndex;
    void* allocateChunk(int nbytes, int memClass);
    static S_0094b1a0_ThreadMemory& getInstance()
    {
        return *static_cast<S_0094b1a0_ThreadMemory*>(TlsGetValue(s_tlsIndex));
    }
};
struct S_0094b1a0_Motor
{
    virtual ~S_0094b1a0_Motor();
    virtual void unknown04();
    virtual void unknown08();
    virtual S_0094b1a0_Motor* clone();
    unsigned short memorySize;
    short referenceCount;
    void removeReference()
    {
        if (memorySize != 0)
        {
            if (--referenceCount == 0)
            {
                delete this;
            }
        }
    }
};
struct S_0094b1a0_SimdReal
{
    float m_real;
    S_0094b1a0_SimdReal(float r) : m_real(r) {}
    operator float() const { return m_real; }
};
struct S_0094b1a0_Vector
{
    float x, y, z, w;
    void mul(const S_0094b1a0_SimdReal& s) { x *= s; y *= s; z *= s; w *= s; }
};
struct S_0094b1a0_Transform
{
    S_0094b1a0_Vector axis0, axis1, axis2, translation;
    S_0094b1a0_Transform& operator=(const S_0094b1a0_Transform& other);
};
struct S_0094b1a0_Ref
{
    virtual void unknown00();
    unsigned short memorySize, referenceCount;
    unsigned int userData, unk0c;
};
struct S_0094b1a0_Clone : S_0094b1a0_Ref
{
    unsigned int atom10, unk14, unk18, unk1c;
    S_0094b1a0_Transform transformA, transformB;
    unsigned char a0, a1, motorEnabled, a3;
    unsigned int unkA4;
    float a8;
    S_0094b1a0_Motor* motor;
    unsigned int unkB0;
    float b4;
    unsigned int unkB8, unkBc, unkC0;
    unsigned short unkC4;
    unsigned char unkC6, unkC7;
    float minimum, maximum;
    S_0094b1a0_Clone();
    static void* operator new(unsigned int size)
    {
        S_0094b1a0_Clone* result = static_cast<S_0094b1a0_Clone*>(S_0094b1a0_ThreadMemory::getInstance().allocateChunk(size, 0x2c));
        result->memorySize = (unsigned short)size;
        return result;
    }
    static void operator delete(void* p);
    void SetReferencedObject(S_0094b1a0_Motor*);
};
struct S_0094b1a0_Data { unsigned int unk00, unk04, unk08, unk0c; float scale; };
struct S_0094b1a0_Owner
{
    unsigned int unk00;
    S_0094b1a0_Clone* source;
    void ReleaseObject(S_0094b1a0_Clone*, S_0094b1a0_Data*);
};
void CloneOwner513::FUN_00cc7600(FUN_00d4fe80* output_, CloneData513* data_)
{
    S_0094b1a0_Clone* output = (S_0094b1a0_Clone*)output_;
    S_0094b1a0_Data* data = (S_0094b1a0_Data*)data_;
    S_0094b1a0_Clone* input = ((S_0094b1a0_Owner*)this)->source;
    if (!output)
        output = new S_0094b1a0_Clone;
    output->transformA = input->transformA;
    output->transformB = input->transformB;
    output->maximum = input->maximum;
    output->minimum = input->minimum;
    output->b4 = input->b4;
    float scale = data->scale;
    if (scale != 1.0f)
    {
        output->transformA.translation.mul(scale);
        output->transformB.translation.mul(scale);
        output->minimum = output->minimum * scale;
        output->maximum = scale * output->maximum;
    }
    S_0094b1a0_Motor* motor = input->motor;
    if (motor)
    {
        S_0094b1a0_Motor* copy = motor->clone();
        output->SetReferencedObject(copy);
        copy->removeReference();
        output->motorEnabled = input->motorEnabled;
    }
    ((S_0094b1a0_Owner*)this)->ReleaseObject(output, data);
}


extern "C" __m128 _mm_load_ss(float const*_A);


__forceinline void scale(__m128& v, float f)
{
    __m128 q = _mm_load_ss(&f);
    v = _mm_mul_ps(_mm_shuffle_ps(q, q, 0), v);
}

extern "C" __m128 _mm_load_ss(const float*);


struct RefObjStandIn
{
    virtual ~RefObjStandIn();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

extern "C" {
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*,__m128);
void _ReadBarrier();
void _ReadWriteBarrier();
}
struct Motion;
struct MotionVtable {
void* slot00;
void* slot04;
void* slot08;
void* slot0c;
void* slot10;
void* slot14;
void* slot18;
void* slot1c;
void* slot20;
void* slot24;
void* slot28;
void* slot2c;
void* slot30;
void* slot34;
void* slot38;
void* slot3c;
void* slot40;
void* slot44;
void* slot48;
void* slot4c;
void* slot50;
void* slot54;
void* slot58;
void* slot5c;
void* slot60;
void* slot64;
void* slot68;
void* slot6c;
void* slot70;
void* slot74;
void* slot78;
void* slot7c;
void* slot80;
void* slot84;
void* slot88;
void* slot8c;
void* slot90;
Transform* (__thiscall *getTransform)(Motion*);
};
struct Motion {
MotionVtable* vtable;
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
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
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
int unk45c;
int unk460;
int unk464;
int unk468;
int unk46c;
int unk470;
int unk474;
int unk478;
int unk47c;
int unk480;
int unk484;
int unk488;
int unk48c;
int unk490;
int unk494;
int unk498;
int unk49c;
__m128 vec4a0;
__m128 vec4b0;
__m128 vec4c0;
__m128 vec4d0;
float value4e0; float value4e4; float value4e8; float value4ec;
__m128 vec4f0;
__m128 vec500;
__m128 vec510;
int state;
float value524;
float value528;
float value52c;
float value530;
float value534;
float value538;
float value53c;
float value540;
float value544;
float value548;
float value54c;
void SubtractVectors(__m128*);
void FUN_00c6cba0();
};

struct __declspec(align(16)) StoredVector {
    unsigned char lanes[16];
    __forceinline StoredVector& operator=(__m128 v) { _mm_store_ps(reinterpret_cast<float*>(&lanes[0]),v);return *this; }
    __forceinline operator const __m128&() const { return *reinterpret_cast<const __m128*>(&lanes[0]); }
};
struct Step { float time; __m128 surfaceVelocity; __m128 up; __m128 normal; __m128 oldVelocity; __m128 gravity; float limit; __m128 basis; };
extern "C" void __cdecl FUN_00d6aef0(Step*, __m128*);

extern __m128 DAT_010c7160;
extern float DAT_01011d78;

extern "C" void _ReadBarrier(void);
#pragma intrinsic(_ReadBarrier)
extern "C" float _mm_cvtss_f32(__m128 _A);
extern "C" __m128 _mm_load_ss(float const*_A);
extern "C" void _mm_store_ss(float *_V, __m128 _A);
extern "C" __m128 _mm_sub_ss(__m128 _A, __m128 _B);



extern float DAT_01011d78;
extern __m128 DAT_010c7160;

struct S00cd3fb0_RealValue { float value; };
class S00cd3fb0_hkVector4 {
public:
    __m128 m_vComponents;
    __forceinline S00cd3fb0_hkVector4() {}
    __forceinline void set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
    __forceinline S00cd3fb0_hkVector4(const S00cd3fb0_hkVector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline S00cd3fb0_hkVector4& operator=(const S00cd3fb0_hkVector4& v) { m_vComponents = v.m_vComponents; return *this; }
    __forceinline __m128 dot3(const S00cd3fb0_hkVector4& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void addMul4(__m128 s, const S00cd3fb0_hkVector4& b) { m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents), m_vComponents); }
};

struct S00cd3fb0_MotionTransform {
    S00cd3fb0_hkVector4 m_pHeadNode;
    S00cd3fb0_hkVector4 m_direction;
};

struct S00cd3fb0_MotionParams {
    float m_factor;
    char unk04[12];
    S00cd3fb0_hkVector4 m_v10;
    S00cd3fb0_hkVector4 m_vHitNormal;
    S00cd3fb0_hkVector4 m_normal2;
    S00cd3fb0_hkVector4 m_fVelocity;
    S00cd3fb0_hkVector4 m_v50;
    float m_vScale;
    float unk64;
    float unk68;
    float unk6c;
    S00cd3fb0_hkVector4 m_v70;
};

class S00cd3fb0_MotionObject;
struct S00cd3fb0_MotionVtable {
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0c;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1c;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2c;
    void* slot30;
    void* slot34;
    void* slot38;
    void* slot3c;
    void* slot40;
    void* slot44;
    void* slot48;
    void* slot4c;
    void* slot50;
    void* slot54;
    void* slot58;
    void* slot5c;
    void* slot60;
    void* slot64;
    void* slot68;
    void* slot6c;
    void* slot70;
    void* slot74;
    void* slot78;
    void* slot7c;
    void* slot80;
    void* slot84;
    void* slot88;
    void* slot8c;
    void* slot90;
    S00cd3fb0_MotionTransform* (__thiscall *GetResult)(S00cd3fb0_MotionObject*);
};
extern void __cdecl FUN_00d6aef0(S00cd3fb0_MotionParams*, S00cd3fb0_hkVector4*);

class S00cd3fb0_MotionObject {
public:
    S00cd3fb0_MotionVtable* vtable;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    unsigned int unknown24c;
    unsigned int unknown250;
    unsigned int unknown254;
    unsigned int unknown258;
    unsigned int unknown25c;
    unsigned int unknown260;
    unsigned int unknown264;
    unsigned int unknown268;
    unsigned int unknown26c;
    unsigned int unknown270;
    unsigned int unknown274;
    unsigned int unknown278;
    unsigned int unknown27c;
    unsigned int unknown280;
    unsigned int unknown284;
    unsigned int unknown288;
    unsigned int unknown28c;
    unsigned int unknown290;
    unsigned int unknown294;
    unsigned int unknown298;
    unsigned int unknown29c;
    unsigned int unknown2a0;
    unsigned int unknown2a4;
    unsigned int unknown2a8;
    unsigned int unknown2ac;
    unsigned int unknown2b0;
    unsigned int unknown2b4;
    unsigned int unknown2b8;
    unsigned int unknown2bc;
    unsigned int unknown2c0;
    unsigned int unknown2c4;
    unsigned int unknown2c8;
    unsigned int unknown2cc;
    unsigned int unknown2d0;
    unsigned int unknown2d4;
    unsigned int unknown2d8;
    unsigned int unknown2dc;
    unsigned int unknown2e0;
    unsigned int unknown2e4;
    unsigned int unknown2e8;
    unsigned int unknown2ec;
    unsigned int unknown2f0;
    unsigned int unknown2f4;
    unsigned int unknown2f8;
    unsigned int unknown2fc;
    unsigned int unknown300;
    unsigned int unknown304;
    unsigned int unknown308;
    unsigned int unknown30c;
    unsigned int unknown310;
    unsigned int unknown314;
    unsigned int unknown318;
    unsigned int unknown31c;
    unsigned int unknown320;
    unsigned int unknown324;
    unsigned int unknown328;
    unsigned int unknown32c;
    unsigned int unknown330;
    unsigned int unknown334;
    unsigned int unknown338;
    unsigned int unknown33c;
    unsigned int unknown340;
    unsigned int unknown344;
    unsigned int unknown348;
    unsigned int unknown34c;
    unsigned int unknown350;
    unsigned int unknown354;
    unsigned int unknown358;
    unsigned int unknown35c;
    unsigned int unknown360;
    unsigned int unknown364;
    unsigned int unknown368;
    unsigned int unknown36c;
    unsigned int unknown370;
    unsigned int unknown374;
    unsigned int unknown378;
    unsigned int unknown37c;
    unsigned int unknown380;
    unsigned int unknown384;
    unsigned int unknown388;
    unsigned int unknown38c;
    unsigned int unknown390;
    unsigned int unknown394;
    unsigned int unknown398;
    unsigned int unknown39c;
    unsigned int unknown3a0;
    unsigned int unknown3a4;
    unsigned int unknown3a8;
    unsigned int unknown3ac;
    unsigned int unknown3b0;
    unsigned int unknown3b4;
    unsigned int unknown3b8;
    unsigned int unknown3bc;
    unsigned int unknown3c0;
    unsigned int unknown3c4;
    unsigned int unknown3c8;
    unsigned int unknown3cc;
    unsigned int unknown3d0;
    unsigned int unknown3d4;
    unsigned int unknown3d8;
    unsigned int unknown3dc;
    unsigned int unknown3e0;
    unsigned int unknown3e4;
    unsigned int unknown3e8;
    unsigned int unknown3ec;
    unsigned int unknown3f0;
    unsigned int unknown3f4;
    unsigned int unknown3f8;
    unsigned int unknown3fc;
    unsigned int unknown400;
    unsigned int unknown404;
    unsigned int unknown408;
    unsigned int unknown40c;
    unsigned int unknown410;
    unsigned int m_flags;
    unsigned int unknown418;
    unsigned int unknown41c;
    unsigned int unknown420;
    unsigned int unknown424;
    unsigned int unknown428;
    unsigned int unknown42c;
    unsigned int unknown430;
    unsigned int unknown434;
    unsigned int unknown438;
    unsigned int unknown43c;
    unsigned int unknown440;
    unsigned int unknown444;
    unsigned int unknown448;
    unsigned int unknown44c;
    unsigned int unknown450;
    unsigned int unknown454;
    unsigned int unknown458;
    unsigned int unknown45c;
    unsigned int unknown460;
    unsigned int unknown464;
    unsigned int unknown468;
    unsigned int unknown46c;
    unsigned int unknown470;
    unsigned int unknown474;
    unsigned int unknown478;
    unsigned int unknown47c;
    unsigned int unknown480;
    unsigned int unknown484;
    unsigned int unknown488;
    unsigned int unknown48c;
    unsigned int unknown490;
    unsigned int unknown494;
    unsigned int unknown498;
    unsigned int unknown49c;
    S00cd3fb0_hkVector4 m_v4a0;
    unsigned int unknown4b0;
    unsigned int unknown4b4;
    unsigned int unknown4b8;
    unsigned int unknown4bc;
    S00cd3fb0_hkVector4 m_vHitNormal;
    S00cd3fb0_hkVector4 m_v4d0;
    unsigned int unknown4e0;
    unsigned int unknown4e4;
    float m_scale4e8;
    unsigned int unknown4ec;
    S00cd3fb0_hkVector4 m_fVelocity;
    unsigned int unknown500;
    unsigned int unknown504;
    unsigned int unknown508;
    unsigned int unknown50c;
    S00cd3fb0_hkVector4 m_v510;
    int m_uiContentCount;
    unsigned int unknown524;
    unsigned int unknown528;
    unsigned int unknown52c;
    unsigned int unknown530;
    float m_uiCommandId;
    unsigned int unknown538;
    unsigned int unknown53c;
    unsigned int unknown540;
    unsigned int unknown544;
    float m_factor;
    float m_scale54c;
    unsigned int unknown550;
    unsigned int unknown554;
    unsigned int unknown558;
    unsigned int unknown55c;
    unsigned int unknown560;
    unsigned int unknown564;
    unsigned int unknown568;
    unsigned int unknown56c;
    unsigned int unknown570;
    unsigned int unknown574;
    unsigned int unknown578;
    unsigned int unknown57c;
    unsigned int unknown580;
    unsigned int unknown584;
    unsigned int unknown588;
    unsigned int unknown58c;
    unsigned int unknown590;
    unsigned int unknown594;
    unsigned int unknown598;
    unsigned int unknown59c;
    unsigned int unknown5a0;
    unsigned int unknown5a4;
    unsigned int unknown5a8;
    unsigned int unknown5ac;
    unsigned int unknown5b0;
    unsigned int unknown5b4;
    unsigned int unknown5b8;
    unsigned int unknown5bc;
    unsigned int unknown5c0;
    unsigned int unknown5c4;
    unsigned int unknown5c8;
    unsigned int unknown5cc;
    unsigned int unknown5d0;
    unsigned int unknown5d4;
    unsigned int unknown5d8;
    unsigned int unknown5dc;
    unsigned int unknown5e0;
    unsigned int unknown5e4;
    unsigned int unknown5e8;
    unsigned int unknown5ec;
    unsigned int unknown5f0;
    unsigned int unknown5f4;
    unsigned int unknown5f8;
    unsigned int unknown5fc;
    unsigned int unknown600;
    unsigned int unknown604;
    unsigned int unknown608;
    unsigned int unknown60c;
    unsigned char m_bSlotEnabled;
    unsigned char unknown611;
    unsigned short unknown612;
    unsigned int unknown614;
    unsigned int unknown618;
    unsigned int unknown61c;
    S00cd3fb0_hkVector4 m_v620;

    __forceinline S00cd3fb0_RealValue scale54c() const { S00cd3fb0_RealValue r = { m_scale54c }; return r; }
    __forceinline float scale4e8() const { return m_scale4e8; }
    __forceinline float getX510() const { __m128 value = m_v510.m_vComponents; _ReadBarrier(); return _mm_cvtss_f32(value); }
    float GetAnimationSpeed();
    void Reset();
    void Finish();
    void GetAudioPosition(S00cd3fb0_hkVector4* out);
};

struct S00cd3fb0_MotionScalarLane { __m128 value; __forceinline S00cd3fb0_MotionScalarLane(float v) { value = _mm_load_ss(&v); } __forceinline S00cd3fb0_MotionScalarLane(S00cd3fb0_RealValue v) { value=_mm_load_ss(&v.value); } __forceinline __m128 broadcast() const { return _mm_shuffle_ps(value,value,0); } };

extern "C" {
void _ReadWriteBarrier();
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_mul_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_cmpeq_ss(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_set_ss(float);
__m128 _mm_set_ps1(float);
__m128 _mm_load_ps(const float*);
float _mm_cvtss_f32(__m128);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*, __m128);
}
extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);

struct MotionData {
    __m128 orientation;
    __m128 direction;
};
struct ProxyHolder { const char* hkpCharacterProxy_getLinearVelocity(); };
struct MotionController;
struct MotionListener {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void update(MotionController* controller);
};
struct ListenerTable { MotionListener* hkpCharacterStateManager_getState(unsigned int index); };
struct MotionVTable {
    void* slot00;
    void* slot01;
    void* slot02;
    void* slot03;
    void* slot04;
    void* slot05;
    void* slot06;
    void* slot07;
    void* slot08;
    void* slot09;
    void* slot10;
    void* slot11;
    void* slot12;
    void* slot13;
    void* slot14;
    void* slot15;
    void* slot16;
    void* slot17;
    void* slot18;
    void* slot19;
    void* slot20;
    void* slot21;
    void* slot22;
    void* slot23;
    void* slot24;
    void* slot25;
    void* slot26;
    void* slot27;
    void* slot28;
    void* slot29;
    void* slot30;
    void* slot31;
    void* slot32;
    void* slot33;
    void* slot34;
    void* slot35;
    void* slot36;
    MotionData* (__thiscall *getMotionData)(MotionController*);
};
struct MotionController {
    MotionVTable* vtable;
    unsigned int unk004;
    ProxyHolder* proxy;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    ListenerTable* listeners;
    unsigned int listenerIndex;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int flags;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    __m128 velocity;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    int state;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    float acceleration;
    float heading;
    unsigned int unk548;
    float directionScale;
    void FUN_00c6cba0();
    const void* FUN_00c89720();
    void SubtractVectors(__m128* result);
};
extern float DAT_01011d78;
void __cdecl FUN_00458620(__m128* result, const __m128* vector);

union __declspec(align(16)) GsVec4 { __m128 v; float f[4]; char c[16]; };


extern "C" __m128 _mm_load_ss(const float*);



class CCEAE0Node;

struct CCEAE0Vector {
    float x, y, z, w;
};

class CCEAE0Arg {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
};

class CCEAE0Node {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual CCEAE0Node* v18(CCEAE0Arg* a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44();
    virtual CCEAE0Node* v45(bool* flag);
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51();
    virtual bool v52(CCEAE0Arg* a);

    int unk04;
    CCEAE0Node* m_08;
    int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    CCEAE0Vector m_40;

    void bhkShape_CopyMembers(void* a1, CCEAE0Arg* a2);
    void FUN_00cceae0(void* a1, CCEAE0Arg* a2);
};

template<class T> struct NativeArray {
    T* data;int size,capacity;
    __forceinline const T& operator[](int i) const {return data[i];}
    __forceinline T& operator[](int i) {return data[i];}
};
extern "C" {
::__m128 _mm_load_ss(const float*);
::__m128 _mm_setzero_ps();
void _ReadWriteBarrier();
}
extern const ::__m128  DAT_010c71e0;
extern const ::__m128  DAT_010c44d0;
extern const ::__m128  DAT_010c4c00;
extern const ::__m128  DAT_010c7170;
extern const ::__m128  DAT_010c4c10;
extern const ::__m128  DAT_010ec7f0;

struct NScalar {
private:
    ::__m128 bits;
public:
    inline const ::__m128& bitsValue() const {return bits;}
    NScalar(const ::__m128& a):bits(a) {}
    NScalar(float a) {bits=_mm_load_ss(&a);}
    operator float() const { float a;(::_mm_store_ss)(&a,bits);return a; }
    __forceinline ::__m128 splat() const {return _mm_shuffle_ps(bits,bits,0);}
};
class NQuaternion;
struct NTransform;
class NVector {
    union {::__m128 data;float lanes[4];};
public:
    __forceinline void operator=(const NVector& a) {data=a.data;}
    __forceinline void operator=(const ::__m128& a) {data=a;}
    __forceinline float& operator()(int i) {return lanes[i];}
    __forceinline const ::__m128& quad() const {return data;}
    __forceinline ::__m128& quad() {return data;}
    __forceinline NScalar dot3(const NVector& a) const {
        ::__m128 p=_mm_mul_ps(data,a.data);
        ::__m128 y=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);
        return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),y);
    }
    __forceinline operator ::__m128() const {return data;}
    __forceinline void negAll(const NVector& a) {data=_mm_xor_ps(a.data,DAT_010c44d0);}
    __forceinline void negThree(const NVector& a) {data=_mm_xor_ps(a.data,DAT_010c4c00);}
    __forceinline void xyzZero(const NVector& a) {data=_mm_and_ps(a,DAT_010c4c10);}
    __forceinline void splatFrom(const NVector& a,int i) {if(i==0)data=_mm_shuffle_ps(a.data,a.data,0);else if(i==1)data=_mm_shuffle_ps(a.data,a.data,0x55);else if(i==2)data=_mm_shuffle_ps(a.data,a.data,0xaa);else if(i==3)data=_mm_shuffle_ps(a.data,a.data,0xff);}
    __forceinline void setZero4() {data=_mm_setzero_ps();}
    __forceinline void setMul4(const NVector& a,const NVector& b) {data=_mm_mul_ps(a.data,b.data);}
    __forceinline void setAdd4(const NVector& a,const NVector& b) {data=_mm_add_ps(a.data,b.data);}
    __forceinline void setSub4(const NVector& a,const NVector& b) {data=_mm_sub_ps(a.data,b.data);}
    __forceinline void addMul4(const NVector& a,const NVector& b) {data=_mm_add_ps(data,_mm_mul_ps(a.data,b.data));}
    __forceinline void triple(const NVector& a,const NVector& b,const NVector& c) {data=_mm_add_ps(a.data,_mm_mul_ps(b.data,c.data));}
    __forceinline void broadcast(int i) {splatFrom(*this,i);}
    __forceinline void add4(const NVector& a) {*this=_mm_add_ps(static_cast<::__m128>(*this),static_cast<::__m128>(a));}
    __forceinline void mul4(const NVector& a) {data=_mm_mul_ps(data,a.data);}
    __forceinline void mul4(const NScalar& a) {data=_mm_mul_ps(a.splat(),data);}
    __forceinline void addMul4(const NScalar& a,const NVector& b) {data=_mm_add_ps(data,_mm_mul_ps(a.splat(),b.data));}
    __forceinline void subMul4(const NScalar& a,const NVector& b) {data=_mm_sub_ps(data,_mm_mul_ps(a.splat(),b.data));}
    __forceinline void setAddMul4(const NVector& a,const NVector& b,const NScalar& c) {data=_mm_add_ps(a.data,_mm_mul_ps(c.splat(),b.data));}
    __forceinline void setInterpolate4(const NVector& a,const NVector& b,const NScalar& c) {
        ::__m128 t=c.splat();
        data=_mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,t),a.data),_mm_mul_ps(t,b.data));
    }
    __forceinline void cross(const NVector& a,const NVector& b) {
        ::__m128 first=_mm_mul_ps(_mm_shuffle_ps(a.data,a.data,0xc9),_mm_shuffle_ps(b.data,b.data,0xd2));
        ::__m128 second=_mm_mul_ps(_mm_shuffle_ps(a.data,a.data,0xd2),_mm_shuffle_ps(b.data,b.data,0xc9));
        data=_mm_sub_ps(first,second);
    }
    __forceinline void SetRotatedDirection(const NQuaternion&,const NVector&);
    __forceinline void inverseRotate(const NQuaternion&,const NVector&);
    __forceinline void _setTransformedPos(const NTransform&,const NVector&);
};
class NQuaternion {
public:
    NVector m_vec;
    NQuaternion() {}
    inline void operator=(const NQuaternion& a) {m_vec=a.m_vec;}
    inline const NVector& imag() const {return m_vec;}
    __forceinline void SetConjugate(const NQuaternion& q) {m_vec.negThree(q.imag());}
    void FUN_00cd9d10(const NVector&,const NVector&);
    void FUN_00c66320(const NQuaternion&,const NQuaternion&);
    void FUN_005611c0();
};
static __forceinline ::__m128 reciprocalValue(::__m128 a) {::__m128 seed=_mm_rcp_ps(a);::__m128 error=_mm_mul_ps(_mm_mul_ps(a,seed),seed);return _mm_sub_ps(_mm_add_ps(seed,seed),error);}
struct NTransform {
    NVector m_vTranslation;
    NQuaternion m_rotation;
    NVector m_vScale;
    NTransform() {}
    NTransform(const NTransform& a) {m_vTranslation=a.m_vTranslation;m_rotation=a.m_rotation;m_vScale=a.m_vScale;}
    __forceinline const NVector& getTranslation() const {return m_vTranslation;}
    __forceinline const NQuaternion& getRotation() const {return m_rotation;}
    __forceinline void SetBodyOrientation(const NQuaternion& a) {m_rotation=a;}
    __forceinline void SetConjugate(const NTransform& a) {
        m_vTranslation.inverseRotate(a.m_rotation,a.m_vTranslation);
        m_vTranslation.negAll(m_vTranslation);
        m_rotation.SetConjugate(a.m_rotation);
        NVector ones;ones.quad()=DAT_010c7170;
        NVector withW;
        withW.quad()=_mm_shuffle_ps(a.m_vScale.quad(),_mm_unpackhi_ps(a.m_vScale.quad(),ones.quad()),0xc4);
        NVector inv;inv.quad()=reciprocalValue(withW.quad());
        m_vScale.xyzZero(inv);
    }
};
struct NativeBool {char value;NativeBool(){}NativeBool(bool a):value(a){}operator bool() const {return value!=0;}NativeBool& operator=(bool a){value=a;return *this;}};

struct NativePose {
    void* skeleton;NativeArray<NTransform> locals,transforms;NativeArray<unsigned> flags;
    bool modelSync,localSync;
    const NTransform& FUN_00cda180(int) const;
    NTransform& FUN_00cdad80(int,int);
    __forceinline const NTransform& get(int i) const {
        if(!(flags[i]&2))return transforms[i];
        return FUN_00cda180(i);
    }
};
struct NativeSetup {
    short bone0,bone1,bone2,twist0,twist1;
    NVector axis;
    float gain,limit,weight,weight2,weight3;
    NVector point;NQuaternion targetRotation;NVector offset;
    NQuaternion rotation;
    NativeBool positionOn,rotationOn;
    NativeSetup() {FUN_00c74ed0();}
    void FUN_00c74ed0();
};

static __forceinline ::__m128 rawDot(::__m128 a,::__m128 b) {
    ::__m128 p=_mm_mul_ps(a,b);
    ::__m128 y=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);
    return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),y);
}
extern "C" ::__m128 _mm_rsqrt_ps(::__m128);
static const ::__m128 quaternionUnit={{0.0f,0.0f,0.0f,1.0f}};
static const ::__m128 quaternionOne={{1.0f,1.0f,1.0f,1.0f}};
static const ::__m128 quaternionHalf={{0.5f,0.5f,0.5f,0.5f}};
static const ::__m128 quaternionThree={{3.0f,3.0f,3.0f,3.0f}};
static const ::__m128 parallelLimit={{0.99999f,0.99999f,0.99999f,0.99999f}};
static const ::__m128 opposedLimit={{-0.99999f,-0.99999f,-0.99999f,-0.99999f}};
static const ::__m128 correctionLimit={{-0.999f,-0.999f,-0.999f,-0.999f}};
static const ::__m128 axisFirst={{1.0f,0.0f,0.0f,0.0f}};
static const ::__m128 axisSecond={{0.0f,1.0f,0.0f,0.0f}};

static __forceinline void scalarDotStore(float& f,::__m128 a,::__m128 b){(::_mm_store_ss)(&f,rawDot(a,b));}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
::__m128 _mm_sub_ss(::__m128,::__m128);
::__m128 _mm_mul_ss(::__m128,::__m128);
::__m128 _mm_andnot_ps(::__m128,::__m128);
::__m128 _mm_cmpeq_ss(::__m128,::__m128);
::__m128 _mm_rsqrt_ss(::__m128);
::__m128 _mm_setzero_ps();
::__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*,::__m128);
}
extern "C" ::__m128 _mm_set_ss(float);
extern "C" ::__m128 _mm_set_ps1(float);
extern "C" unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" double __cdecl sqrt(double);

extern "C" const ::__m128 DAT_010c71b0; // (0,0,0,1)
extern "C" const ::__m128 DAT_010c71e0; // -0.5 splat
extern "C" const ::__m128 DAT_010c4c00; // sign mask xyz
extern "C" const ::__m128 DAT_010c44d0; // sign mask xyzw
extern "C" const ::__m128 DAT_010c4c10; // mask xyz
extern "C" const ::__m128 DAT_010c7170; // 1.0 splat

extern "C" const float DAT_01012068;
extern "C" __declspec(dllimport) int __stdcall IsBadWritePtr(void*,unsigned int);
static __forceinline void StoreTimer(DWORD& out) { DWORD stamp; __assume(!IsBadWritePtr(&stamp,sizeof(stamp)));
__asm {
rdtsc
mov dword ptr[stamp], eax
}
 out=stamp; }
static __forceinline void TimerLayer0(DWORD& out) { StoreTimer(out); }
static __forceinline void TimerLayer1(DWORD& out) { TimerLayer0(out); }
struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
__forceinline void setTime() { TimerLayer1(m_iTick); }
};

struct ProfRec2
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
__forceinline void setTime() { TimerLayer1(m_iTick); }
};

struct hkQsTransform;

static __forceinline unsigned __int64 GetTickCounter()
{
    return __rdtsc();
}

static __forceinline DWORD Tick()
{
    _ReadWriteBarrier();
    DWORD ticks=(DWORD)GetTickCounter();
    return ticks;
}

struct IkVector4
{
    ::__m128 m_vComponents;
    __forceinline IkVector4() {}
    __forceinline void operator=(const IkVector4& v) { m_vComponents = v.m_vComponents; }
    void FUN_00c7f7a0(const hkQsTransform& t, const IkVector4& v);
};

struct QuadWords { unsigned int x,y,z,w; };
struct hkQuaternion
{
    IkVector4 m_vec;
    __forceinline hkQuaternion() {}
    __forceinline hkQuaternion(const hkQuaternion& q) { m_vec.m_vComponents.m128_u64[0]=q.m_vec.m_vComponents.m128_u64[0]; m_vec.m_vComponents.m128_u64[1]=q.m_vec.m_vComponents.m128_u64[1]; }
__forceinline void copyRotation(const hkQuaternion& q) {*(QuadWords*)&m_vec=*(const QuadWords*)&q.m_vec;}
    void FUN_00c66320(const hkQuaternion& q0, const hkQuaternion& q1);
    __declspec(noalias) void FUN_005611c0();
    void hkQuaternion_setAxisAngle(const IkVector4& axis, float angle);
    void FUN_00cdb910(float gain, const IkVector4& from, const IkVector4& to);
    void FUN_00c74ac0(const hkQuaternion& q0, const hkQuaternion& q1);
    void FUN_00cb2850(const hkQuaternion& q0, const hkQuaternion& q1, float t);
};

struct VectorComponentValue
{
    ::__m128 m_vValue;
};

static __forceinline VectorComponentValue Dot3S(const ::__m128& a, const ::__m128& b)
{
    VectorComponentValue r;
    ::__m128 x2 = _mm_mul_ps(a, b);
    ::__m128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return r;
}
static __forceinline VectorComponentValue Dot3Srev(const ::__m128& a, const ::__m128& b)
{
    VectorComponentValue r;
    ::__m128 x2 = _mm_mul_ps(b, a);
    ::__m128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    return r;
}

struct MathQuad {
 ::__m128 m_vComponents;
 __forceinline MathQuad() {}
 __forceinline MathQuad(const ::__m128& x):m_vComponents(x) {}
 template<int shuffle> __forceinline void component(const MathQuad& a) { m_vComponents=_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,shuffle); }
 __forceinline void product(const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void sumProduct(const MathQuad& offset,const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_add_ps(offset.m_vComponents,_mm_mul_ps(a.m_vComponents,b.m_vComponents)); }
 __forceinline void accumulate(const MathQuad& a,const MathQuad& b) { m_vComponents=_mm_add_ps(m_vComponents,_mm_mul_ps(a.m_vComponents,b.m_vComponents)); }
 __forceinline void crossed(const MathQuad& a,const MathQuad& b) {
  m_vComponents=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xc9),_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xd2)),_mm_mul_ps(_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xc9),_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xd2)));
 }
 __forceinline VectorComponentValue dotted(const MathQuad& b) const { return Dot3S(m_vComponents,b.m_vComponents); }
 __forceinline void doubleValue(const MathQuad& a) { m_vComponents=_mm_add_ps(a.m_vComponents,a.m_vComponents); }
};

class DotValue {
 ::__m128 quad;
public:
 __forceinline DotValue(){}
 __forceinline DotValue(const ::__m128& x):quad(x){}
 __forceinline void operator=(const ::__m128& x){quad=x;}
 __forceinline operator ::__m128()const{return quad;}
};
class DotReference {
 ::__m128 quad;
public:
 __forceinline DotReference(){}
 __forceinline DotReference(const ::__m128& x):quad(x){}
 __forceinline void operator=(const ::__m128& x){quad=x;}
 __forceinline operator const ::__m128&()const{return quad;}
};
struct HingeScalar {
private: ::__m128 quad;
public:
 __forceinline HingeScalar() {}
 __forceinline HingeScalar(::__m128 x):quad(x) {}
 __forceinline operator ::__m128() const {return quad;}
 __forceinline ::__m128 raw() const {return quad;}
};
struct HingeVector {
 ::__m128 quad;
 __forceinline HingeVector() {}
 __forceinline HingeVector(const ::__m128& x):quad(x) {}
 __forceinline void mul(const HingeVector& a,const HingeVector& b) {quad=_mm_mul_ps(a.quad,b.quad);}
 __forceinline void addMul(const HingeVector& z,const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(z.quad,_mm_mul_ps(a.quad,b.quad));}
 __forceinline void accum(const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(quad,_mm_mul_ps(a.quad,b.quad));}
 __forceinline void plus(const HingeVector& a,const HingeVector& b) {quad=_mm_add_ps(a.quad,b.quad);}
 __forceinline HingeScalar dot(const HingeVector& b) const {::__m128 p=_mm_mul_ps(quad,b.quad);::__m128 sum=_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p);return HingeScalar(_mm_add_ss(_mm_shuffle_ps(p,p,0xaa),sum));}
 __forceinline void cross(const HingeVector& a,const HingeVector& b) {quad=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.quad,a.quad,0xc9),_mm_shuffle_ps(b.quad,b.quad,0xd2)),_mm_mul_ps(_mm_shuffle_ps(b.quad,b.quad,0xc9),_mm_shuffle_ps(a.quad,a.quad,0xd2)));}
 __forceinline void splat(const HingeVector& a) {quad=_mm_shuffle_ps(a.quad,a.quad,0xff);}
 __forceinline void broadcast() {quad=_mm_shuffle_ps(quad,quad,0);}
};
static __forceinline ::__m128 ForwardDot(const ::__m128& a,const ::__m128& b) { const ::__m128 x=_mm_mul_ps(b,a); const ::__m128 xy=_mm_add_ss(_mm_shuffle_ps(x,x,0x55),x); const ::__m128 z=_mm_shuffle_ps(x,x,0xaa); return _mm_add_ss(z,xy); }
static __forceinline ::__m128 RotateForward(const ::__m128& q, const ::__m128& v)
{
    const ::__m128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::__m128 dot=ForwardDot(q,v);
    ::__m128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::__m128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}static __forceinline ::__m128 InitialForward(const hkQuaternion& rotation,const IkVector4& input) { const ::__m128& v=input.m_vComponents; const ::__m128& q=rotation.m_vec.m_vComponents;
    const ::__m128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::__m128 dot=ForwardDot(q,v);
    ::__m128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::__m128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}
static __forceinline ::__m128 FirstRestoreForward(const ::__m128& v,::__m128 q) {
    const ::__m128 w = _mm_shuffle_ps(q, q, 0xff);
    const VectorComponentValue dot=Dot3S(v,q);
    ::__m128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::__m128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot.m_vValue,dot.m_vValue,0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}

static __forceinline ::__m128 ContextForward(::__m128 q, ::__m128 v)
{
    const ::__m128 w = _mm_shuffle_ps(q, q, 0xff);
    const ::__m128 dot=ForwardDot(q,v);
    ::__m128 cross;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q,q,0xc9),_mm_shuffle_ps(v,v,0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    cross = _mm_mul_ps(cross, w);
    ::__m128 result;
    result = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    cross = _mm_add_ps(cross, result);
    return _mm_add_ps(cross, cross);
}

static __forceinline ::__m128 RotatedInverseDir(const ::__m128& q, const ::__m128& v)
{
    const ::__m128 w = _mm_shuffle_ps(q, q, 0xff);
    const VectorComponentValue d = Dot3S(q, v);
    IkVector4 c;
    c.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)));
    c.m_vComponents = _mm_mul_ps(c.m_vComponents, w);
    IkVector4 r;
    r.m_vComponents = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    r.m_vComponents = _mm_add_ps(r.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(d.m_vValue, d.m_vValue, 0), q));
    c.m_vComponents = _mm_add_ps(c.m_vComponents, r.m_vComponents);
    return _mm_add_ps(c.m_vComponents, c.m_vComponents);
}

extern "C" {
::__m128 _mm_rsqrt_ps(::__m128);::__m128 _mm_cmpeq_ps(::__m128,::__m128);
::__m128 _mm_unpacklo_ps(::__m128,::__m128);::__m128 _mm_movelh_ps(::__m128,::__m128);
}

struct hkQsTransform
{
    IkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    IkVector4 m_vScale;

    hkQsTransform& CopyFromFloatArray(const hkQsTransform& t);
    __forceinline hkQsTransform() {}
    __forceinline hkQsTransform(const hkQsTransform& t) { m_vTranslation=t.m_vTranslation; m_rotation=t.m_rotation; m_vScale=t.m_vScale; }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(DAT_01012068);
    }

    __forceinline void SetConjugate(const hkQsTransform& t)
    {
        m_vTranslation.m_vComponents = _mm_xor_ps(RotatedInverseDir(t.m_rotation.m_vec.m_vComponents, t.m_vTranslation.m_vComponents), DAT_010c44d0);
        m_rotation.m_vec.m_vComponents = _mm_xor_ps(t.m_rotation.m_vec.m_vComponents, DAT_010c4c00);
        ::__m128 s = t.m_vScale.m_vComponents;
        ::__m128 h = _mm_unpackhi_ps(s, DAT_010c7170);
        s = _mm_shuffle_ps(s, h, 0xc4);
        ::__m128 r = _mm_rcp_ps(s);
        ::__m128 rs = _mm_mul_ps(r, s);
        r = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(rs, r));
        m_vScale.m_vComponents = _mm_and_ps(r, DAT_010c4c10);
    }

    __forceinline void SetProduct(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(RotateForward(a.m_rotation.m_vec.m_vComponents,b.m_vTranslation.m_vComponents), a.m_vTranslation.m_vComponents);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }

    __forceinline void setMulContext(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(ContextForward(a.m_rotation.m_vec.m_vComponents,b.m_vTranslation.m_vComponents), a.m_vTranslation.m_vComponents);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
    __forceinline void setRelativeContext(const hkQsTransform& a, const hkQsTransform& b)
    {
        hkQsTransform inv;
        inv.SetConjugate(a);
        setMulInitial(inv, b);
    }
    __forceinline void setMulInitial(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(InitialForward(a.m_rotation,b.m_vTranslation), a.m_vTranslation.m_vComponents);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
    __forceinline void setMulFirst(const hkQsTransform& a, const hkQsTransform& b)
    {
        m_vTranslation.m_vComponents = _mm_add_ps(FirstRestoreForward(b.m_vTranslation.m_vComponents,a.m_rotation.m_vec.m_vComponents), a.m_vTranslation.m_vComponents);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(a.m_vScale.m_vComponents, b.m_vScale.m_vComponents);
    }
    __forceinline void SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
    {
        hkQsTransform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};

template<class T> struct IkArray {
 T* data; int size; int capacity;
 __forceinline T& operator[](const int& i) { return data[i]; }
 __forceinline const T& operator[](const int& i) const { return data[i]; }
};
struct hkaSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
};

struct SkeletonPoseData
{
    const hkaSkeleton* m_pSkeleton;
    IkArray<hkQsTransform> m_pLocalPose;
    hkQsTransform* m_pModelPose;
    int m_modelPoseSize;
    int m_modelPoseCap;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCap;
    bool m_bPoseFlag;
    bool m_bPoseInitialized;

    const hkQsTransform& FUN_00cda180(int boneIdx);
    hkQsTransform& FUN_00cdad80(int boneIdx, int propagate);

    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if ((m_pBoneFlags[boneIdx] & 2) == 0)
        {
            return m_pModelPose[boneIdx];
        }
        return FUN_00cda180(boneIdx);
    }

    __forceinline const hkQsTransform& getBoneLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        if (m_pBoneFlags[boneIdx] & 1)
        {
            const hkQsTransform& modelFromBone=m_pModelPose[boneIdx];
            const short parentIdx=m_pSkeleton->m_kParentIndices[boneIdx];
            if (parentIdx != -1) m_pLocalPose[boneIdx].SetMulInverse(getBoneModelSpace(parentIdx), modelFromBone);
            else { if(externalRootCopy) m_pLocalPose[boneIdx].CopyFromFloatArray(modelFromBone); else m_pLocalPose[boneIdx]=modelFromBone; }
            m_pBoneFlags[boneIdx] &= ~1;
        }
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        const int numBones = m_pSkeleton->m_iBoneCount;
        m_pBoneFlags[boneIdx] |= 4;
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = m_pSkeleton->m_kParentIndices[i];
            if (parentIdx == -1)
            {
                continue;
            }
            if ((m_pBoneFlags[parentIdx] & 4) == 0)
            {
                continue;
            }
            {
                getBoneLocalSpace(i,externalRootCopy);
                m_pBoneFlags[i] |= 4;
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & 4)
            {
                f = (f & ~4) | 2;
            }
        }
    }

    __forceinline void setBoneModelSpace(int boneIdx, const hkQsTransform& t, bool externalRootCopy=false)
    {
        makeAllChildrenLocalSpace(boneIdx,externalRootCopy);
        m_pModelPose[boneIdx] = t;
        m_pBoneFlags[boneIdx] = 1;
        m_bPoseInitialized = false;
    }
};

template<class T> struct ModelArray {T* data;int size;int capacity;
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}};
struct hkaPoseTyped
{
    const hkaSkeleton* m_pSkeleton;
    ModelArray<hkQsTransform> m_pLocalPose;
    ModelArray<hkQsTransform> m_pModelPose;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCap;
    bool m_bPoseFlag;
    bool m_bPoseInitialized;




    __forceinline const hkQsTransform& getBoneModelSpace(int boneIdx)
    {
        if ((m_pBoneFlags[boneIdx] & 2) == 0)
        {
            return m_pModelPose[boneIdx];
        }
        return ((SkeletonPoseData*)this)->FUN_00cda180(boneIdx);
    }

    __forceinline const hkQsTransform& getBoneLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        if (m_pBoneFlags[boneIdx] & 1)
        {
            const hkQsTransform& modelFromBone=m_pModelPose[boneIdx];
            const short parentIdx=m_pSkeleton->m_kParentIndices[boneIdx];
            if (parentIdx != -1) m_pLocalPose[boneIdx].SetMulInverse(getBoneModelSpace(parentIdx), modelFromBone);
            else { if(externalRootCopy) m_pLocalPose[boneIdx].CopyFromFloatArray(modelFromBone); else m_pLocalPose[boneIdx]=modelFromBone; }
            m_pBoneFlags[boneIdx] &= ~1;
        }
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx, bool externalRootCopy=false)
    {
        const int numBones = m_pSkeleton->m_iBoneCount;
        m_pBoneFlags[boneIdx] |= 4;
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = m_pSkeleton->m_kParentIndices[i];
            if (parentIdx == -1)
            {
                continue;
            }
            if ((m_pBoneFlags[parentIdx] & 4) == 0)
            {
                continue;
            }
            {
                getBoneLocalSpace(i,externalRootCopy);
                m_pBoneFlags[i] |= 4;
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & 4)
            {
                f = (f & ~4) | 2;
            }
        }
    }

    __forceinline void setBoneModelSpace(int boneIdx, const hkQsTransform& t, bool externalRootCopy=false)
    {
        makeAllChildrenLocalSpace(boneIdx,externalRootCopy);
        m_pModelPose[boneIdx] = t;
        m_pBoneFlags[boneIdx] = 1;
        m_bPoseInitialized = false;
    }
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b) { m_cBooleanValue = (char)b; }
};


extern "C" double __cdecl fabs(double);
