// fallout_shared/facegen/bsfacegenninode.cpp: FaceNode, FaceGenNode, DumpNode (2 functions)
#include "f3_common.h"
#include "bsfacegenninode.h"

class NiNode
{
  public:
    const NiPoint3& FUN_0045bb80() const;
};

struct GeometryVertexBuffer
{
    char b[12];
    GeometryVertexBuffer();
};
struct FUN_00663430
{
    char* ptri;
    GeometryVertexBuffer iter;
    FUN_00663430();
};
// @fnv 0x00663430
FUN_00663430::FUN_00663430()
{}

struct FUN_00663a10_shell : public BSFaceGenAnimationData
{
    void FUN_00663a10(bool);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

namespace fnv_00663a70 {
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

struct NiAVObject
{
    bool FUN_00456610();
};
struct NiNode
{
    void UpdateDownwardPass(NiUpdateData*, unsigned int);
};
}  // namespace fnv_00663a70

struct NiAVObject;
struct NiNode;
struct NiTriBasedGeom;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct NiBound;
struct NiAVObject
{
    NiBound& GetBoundingVolume();
};

struct BSStrHelper663
{
    operator const char*() const;
};

struct GlobalObject_0044f440
{
    void FUN_00450410(void);
};

GlobalObject_0044f440 g_011d5b28;

namespace fnv_006633e0 {
struct GlobalObject_0044f440
{
    void FUN_00450410(void);
};

GlobalObject_0044f440 g_011d5b34;

}  // namespace fnv_006633e0

namespace fnv_00663ab0 {
struct NiUpdateData
{
};

struct NiNode
{
    virtual void UpdateTransformAndBounds(NiUpdateData&);
};

}  // namespace fnv_00663ab0

namespace fnv_00663510 {
class Actor;
class PlayerCharacter;
class BaseProcess
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual bool IsArrested();
    virtual void vq000();
    virtual void vq004();
    virtual void vq008();
    virtual void vq00c();
    virtual void vq010();
    virtual void vq014();
    virtual void vq018();
    virtual void vq01c();
    virtual void vq020();
    virtual void vq024();
    virtual void vq028();
    virtual Actor* GetCombatTarget();
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual void vr100();
    virtual void vr104();
    virtual void vr108();
    virtual void vr10c();
    virtual void vr110();
    virtual void vr114();
    virtual void vr118();
    virtual void vr11c();
    virtual void vr120();
    virtual void vr124();
    virtual void vr128();
    virtual void vr12c();
    virtual void vr130();
    virtual void vr134();
    virtual void vr138();
    virtual void vr13c();
    virtual void vr140();
    virtual void vr144();
    virtual void vr148();
    virtual void vr14c();
    virtual void vr150();
    virtual void vr154();
    virtual void vr158();
    virtual void vr15c();
    virtual void vr160();
    virtual void vr164();
    virtual void vr168();
    virtual void vr16c();
    virtual void vr170();
    virtual void vr174();
    virtual void vr178();
    virtual void vr17c();
    virtual void vr180();
    virtual void vr184();
    virtual void vr188();
    virtual void vr18c();
    virtual void vr190();
    virtual void vr194();
    virtual void vr198();
    virtual void vr19c();
    virtual void vr1a0();
    virtual void vr1a4();
    virtual void vr1a8();
    virtual void vr1ac();
    virtual void vr1b0();
    virtual void vr1b4();
    virtual void vr1b8();
    virtual void vr1bc();
    virtual void vr1c0();
    virtual void vr1c4();
    virtual void vr1c8();
    virtual void vr1cc();
    virtual void vr1d0();
    virtual void vr1d4();
    virtual void vr1d8();
    virtual void vr1dc();
    virtual void vr1e0();
    virtual void vr1e4();
    virtual void vr1e8();
    virtual void vr1ec();
    virtual void vr1f0();
    virtual void vr1f4();
    virtual void vr1f8();
    virtual void vr1fc();
    virtual void vr200();
    virtual void vr204();
    virtual void vr208();
    virtual void vr20c();
    virtual void vr210();
    virtual void vr214();
    virtual void vr218();
    virtual void vr21c();
    virtual void vr220();
    virtual void vr224();
    virtual void vr228();
    virtual void vr22c();
    virtual void vr230();
    virtual void vr234();
    virtual void vr238();
    virtual void vr23c();
    virtual void vr240();
    virtual void vr244();
    virtual void vr248();
    virtual void vr24c();
    virtual void vr250();
    virtual void vr254();
    virtual void vr258();
    virtual void vr25c();
    virtual void vr260();
    virtual void vr264();
    virtual void vr268();
    virtual void vr26c();
    virtual void vr270();
    virtual void vr274();
    virtual void vr278();
    virtual void vr27c();
    virtual void vr280();
    virtual void vr284();
    virtual void vr288();
    virtual void vr28c();
    virtual void vr290();
    virtual void vr294();
    virtual void vr298();
    virtual void vr29c();
    virtual void vr2a0();
    virtual void vr2a4();
    virtual void vr2a8();
    virtual void vr2ac();
    virtual void vr2b0();
    virtual void vr2b4();
    virtual void vr2b8();
    virtual void vr2bc();
    virtual void vr2c0();
    virtual void vr2c4();
    virtual void vr2c8();
    virtual void vr2cc();
    virtual void vr2d0();
    virtual void vr2d4();
    virtual void vr2d8();
    virtual void vr2dc();
    virtual void vr2e0();
    virtual void vr2e4();
    virtual void vr2e8();
    virtual void vr2ec();
    virtual void vr2f0();
    virtual void vr2f4();
    virtual void vr2f8();
    virtual void vr2fc();
    virtual void vr300();
    virtual void vr304();
    virtual void vr308();
    virtual void vr30c();
    virtual void vr310();
    virtual void vr314();
    virtual void vr318();
    virtual void vr31c();
    virtual void vr320();
    virtual void vr324();
    virtual void vr328();
    virtual void vr32c();
    virtual void vr330();
    virtual void vr334();
    virtual void vr338();
    virtual void vr33c();
    virtual void vr340();
    virtual void vr344();
    virtual void vr348();
    virtual void vr34c();
    virtual void vr350();
    virtual void vr354();
    virtual void vr358();
    virtual void vr35c();
    virtual void vr360();
    virtual void vr364();
    virtual void vr368();
    virtual void vr36c();
    virtual void vr370();
    virtual void vr374();
    virtual void vr378();
    virtual void vr37c();
    virtual void vr380();
    virtual void vr384();
    virtual void vr388();
    virtual void vr38c();
    virtual void vr390();
    virtual void vr394();
    virtual void vr398();
    virtual void vr39c();
    virtual void vr3a0();
    virtual void vr3a4();
    virtual void vr3a8();
    virtual void vr3ac();
    virtual void vr3b0();
    virtual void vr3b4();
    virtual void vr3b8();
    virtual void vr3bc();
    virtual void vr3c0();
    virtual void vr3c4();
    virtual void vr3c8();
    virtual void vr3cc();
    virtual void vr3d0();
    virtual void vr3d4();
    virtual void vr3d8();
    virtual void vr3dc();
    virtual void vr3e0();
    virtual void vr3e4();
    virtual void vr3e8();
    virtual void vr3ec();
    virtual void vr3f0();
    virtual void vr3f4();
    virtual void vr3f8();
    virtual void vr3fc();
    virtual void vr400();
    virtual void vr404();
    virtual void vr408();
    virtual void vr40c();
    virtual void vr410();
    virtual void vr414();
    virtual void vr418();
    virtual void vr41c();
    virtual void vr420();
    virtual void vr424();
    virtual void vr428();
    virtual void vr42c();
    virtual void vr430();
    virtual void vr434();
    virtual void vr438();
    virtual void vr43c();
    virtual void vr440();
    virtual void vr444();
    virtual void vr448();
    virtual void vr44c();
    virtual void vr450();
    virtual void vr454();
    virtual void vr458();
    virtual void vr45c();
    virtual void vr460();
    virtual void vr464();
    virtual void vr468();
    virtual void vr46c();
    virtual void vr470();
    virtual void vr474();
    virtual void vr478();
    virtual void vr47c();
    virtual void vr480();
    virtual void vr484();
    virtual void vr488();
    virtual void vr48c();
    virtual void vr490();
    virtual void vr494();
    virtual void vr498();
    virtual void vr49c();
    virtual void vr4a0();
    virtual void vr4a4();
    virtual void vr4a8();
    virtual void vr4ac();
    virtual void vr4b0();
    virtual void vr4b4();
    virtual void vr4b8();
    virtual void vr4bc();
    virtual void vr4c0();
    virtual void vr4c4();
    virtual void vr4c8();
    virtual void vr4cc();
    virtual void vr4d0();
    virtual void vr4d4();
    virtual void vr4d8();
    virtual void vr4dc();
    virtual void vr4e0();
    virtual void vr4e4();
    virtual void vr4e8();
    virtual void vr4ec();
    virtual void vr4f0();
    virtual void vr4f4();
    virtual void vr4f8();
    virtual void vr4fc();
    virtual void vr500();
    virtual void vr504();
    virtual void vr508();
    virtual void vr50c();
    virtual void vr510();
    virtual void vr514();
    virtual void vr518();
    virtual void vr51c();
    virtual void vr520();
    virtual void vr524();
    virtual void vr528();
    virtual void vr52c();
    virtual void vr530();
    virtual void vr534();
    virtual void vr538();
    virtual void vr53c();
    virtual void vr540();
    virtual void vr544();
    virtual void vr548();
    virtual void vr54c();
    virtual void vr550();
    virtual void vr554();
    virtual void vr558();
    virtual void vr55c();
    virtual void vr560();
    virtual void vr564();
    virtual void vr568();
    virtual void vr56c();
    virtual void vr570();
    virtual void vr574();
    virtual void vr578();
    virtual void vr57c();
    virtual void vr580();
    virtual void vr584();
    virtual void vr588();
    virtual void vr58c();
    virtual void vr590();
    virtual void vr594();
    virtual void vr598();
    virtual void vr59c();
    virtual void vr5a0();
    virtual void vr5a4();
    virtual void vr5a8();
    virtual void vr5ac();
    virtual void vr5b0();
    virtual void vr5b4();
    virtual void vr5b8();
    virtual void vr5bc();
    virtual void vr5c0();
    virtual void vr5c4();
    virtual void vr5c8();
    virtual void* GetCurrentPackage678();
};
class MobileObject
{
  public:
    BaseProcess* GetCurrentAIProcess() const;
    unsigned int GetCurrentProcessLevel();
};

class FaceGenAnimData
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual bool UpdateMorphs();
    virtual bool NeedsUpdate();
    virtual void SetUpdated(bool);
    virtual bool IsDead();
    virtual void vb000();
    virtual void vb004();
    virtual void vb008();
    virtual void vb00c();
    virtual void vb010();
    virtual void vb014();
    virtual void vb018();
    virtual void vb01c();
    virtual void vb020();
    virtual void vb024();
    virtual void vb028();
    virtual void vb02c();
    virtual void vb030();
    virtual void vb034();
    virtual void vb038();
    virtual void vb03c();
    virtual void vb040();
    virtual void vb044();
    virtual void vb048();
    virtual void vb04c();
    virtual bool UpdateAnimation(float);
    bool FUN_0064be40(float, unsigned int);
};
struct FUN_00663a10_shell
{
    void FUN_00663a10(bool);
};

class FaceGenNode
{
  public:
    virtual void vn000();
    virtual void vn004();
    virtual void vn008();
    virtual void vn00c();
    virtual void vn010();
    virtual void vn014();
    virtual void vn018();
    virtual void vn01c();
    virtual void vn020();
    virtual void vn024();
    virtual void vn028();
    virtual void vn02c();
    virtual void vn030();
    virtual void vn034();
    virtual void vn038();
    virtual void vn03c();
    virtual void vn040();
    virtual void vn044();
    virtual void vn048();
    virtual void vn04c();
    virtual void vn050();
    virtual void vn054();
    virtual void vn058();
    virtual void vn05c();
    virtual void vn060();
    virtual void vn064();
    virtual void vn068();
    virtual void vn06c();
    virtual void vn070();
    virtual void vn074();
    virtual void vn078();
    virtual void vn07c();
    virtual void vn080();
    virtual void vn084();
    virtual void vn088();
    virtual void vn08c();
    virtual void vn090();
    virtual void vn094();
    virtual void vn098();
    virtual void vn09c();
    virtual void vn0a0();
    virtual void vn0a4();
    virtual void vn0a8();
    virtual void vn0ac();
    virtual void vn0b0();
    virtual void vn0b4();
    virtual void vn0b8();
    virtual void vn0bc();
    virtual void vn0c0();
    virtual void vn0c4();
    virtual void vn0c8();
    virtual void vn0cc();
    virtual void vn0d0();
    virtual void vn0d4();
    virtual void vn0d8();
    virtual void vn0dc();
    virtual void vn0e0();
    virtual void vn0e4();
    virtual void vn0e8();
    virtual void vn0ec();
    virtual void vn0f0();
    virtual void vn0f4();
    virtual void vn0f8();
    virtual void vn0fc();
    virtual FaceGenAnimData* GetAnimationData();
    bool GetByteAtOffsetE1();
    void UpdateStateByDistance(int);
    void FUN_00663050(bool);
};
class NiAVObject
{
  public:
    bool FUN_00456610();
    bool FUN_004f0140();
};
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
    bool CanAddActorToList(Actor*, int);
};

}  // namespace fnv_00663510

struct CloningProcess
{
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_006628c0 : A51BF0Base
{
    FUN_006628c0();

    void FUN_00663c30(FUN_006628c0* pnode, CloningProcess& cloneData);

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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26(CloningProcess& cloneData);

    unsigned char padding[0xec];

    FUN_006628c0* FUN_00663b80(CloningProcess& cloneData);
};

struct S_00a953b0_Node
{
    void CopyMemberData(S_00a953b0_Node*, void*);
};

struct Helper62d0
{
    void* operator=(void const*);
    void* value;
};

struct FUN_00663c30_shell : S_00a953b0_Node
{
    struct Block36
    {
        int values[9];
    };

    unsigned char padding[0xab];
    Helper62d0 helper;
    Block36 block;
    unsigned char value_d4;
    unsigned char value_d5;
    unsigned char value_d6;
    unsigned char value_d7;
    unsigned char padding_d8[4];
    float value_dc;
    unsigned char value_e0;
    unsigned char value_e1;

    void FUN_00663c30(FUN_00663c30_shell*, void*);
};

struct FUN_00662b70_cls
{
    struct Block36
    {
        int values[9];
    };

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
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual unsigned int v108(unsigned int* out);

    unsigned char unk04[0xac];
    Block36 block;
    unsigned char unkD4;
    unsigned char unkD5;
    unsigned char unkD6;
    unsigned char flagD7;

    void FUN_0043fa80(unsigned int value);
    void FUN_00662b70(Block36* src);
};

// ApplyParamValues candidate
extern "C" void __cdecl FUN_00653340(void* a, void* b);

struct Sub10Obj;
struct FUN_00662f70_cls;
struct FUN_00662f70_arg;
struct FUN_00662f70_p
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
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual float v2B(int);
};

struct Sub10Obj
{
    void FUN_00662030(int, int, int, int, float);
};

struct FUN_00662f70_arg
{
    int m_00;
    int m_04;
    int unk08;
    int unk0c;
    Sub10Obj* m_10;
    int m_14;
    int unk18;
    unsigned char m_1c;
};

struct FUN_00662f70_cls
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
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual FUN_00662f70_p* v40();
    void FUN_00662f70(FUN_00662f70_arg* a1);
};

void __cdecl FUN_00653340(int a, int b);

class B663450Point3
{
  public:
    float x;
    float y;
    float z;

    B663450Point3 operator-(const B663450Point3& kPt) const;
    float Length() const;
};

class B663450Actor;

class B663450Actor
{
  public:
    const B663450Point3& GetPosition();
    bool GetByteAtE0();
    void UpdateStateByDistance(int iState);
};

struct BoneName
{
    const char* FUN_0043b1b0();
};
struct SceneNode;
struct SkinData
{
    unsigned int FUN_008041a0();
};
struct SkinInstance
{
    SkinData* FUN_005585e0();
    SceneNode** FUN_00825c00();
    void SetBone(unsigned int, SceneNode*);
    void FUN_00437730(void*);
};
struct Geometry
{
    SkinInstance* FUN_0043fad0();
};
struct SceneNode
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual Geometry* AsGeometry();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual SceneNode* FindBone(BoneName*);
    BoneName* FUN_00413f40();
};

namespace fnv_00663050 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_00457990();
};
struct BSFaceGenMorphData
{
    void* vertices;
    void* normals;
    void* tangents;
};
class MorphGeometryData
{
  public:
    bool FUN_00a67360(bool);
    void NiGeometryData_GetVerticesIterator(BSFaceGenMorphData*);
    void NiGeometryData_UnlockPackedVertexData();
};
class NiTriBasedGeom
{
  public:
    MorphGeometryData* FUN_005495f0();
    unsigned short FUN_00456650();
};
class NiAVObject
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual void Unk_010();
    virtual void Unk_014();
    virtual void Unk_018();
    virtual NiTriBasedGeom* AsTriBasedGeom();
};
struct FUN_00663430
{
    NiTriBasedGeom* geometry;
    BSFaceGenMorphData morph;
    FUN_00663430();
};
class AnimationState
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual void Unk_010();
    virtual void Unk_014();
    virtual void Unk_018();
    virtual void Unk_01c();
    virtual void Unk_020();
    virtual void Unk_024();
    virtual void Unk_028();
    virtual void Unk_02c();
    virtual void Unk_030();
    virtual void Unk_034();
    virtual void Unk_038();
    virtual void Unk_03c();
    virtual void Unk_040();
    virtual void Unk_044();
    virtual void Unk_048();
    virtual void Unk_04c();
    virtual void Unk_050();
    virtual void Unk_054();
    virtual void Unk_058();
    virtual void Unk_05c();
    virtual void Unk_060();
    virtual void Unk_064();
    virtual void Unk_068();
    virtual void Unk_06c();
    virtual void Unk_070();
    virtual void Unk_074();
    virtual void Unk_078();
    virtual void Unk_07c();
    virtual void Unk_080();
    virtual void Unk_084();
    virtual void Unk_088();
    virtual void Unk_08c();
    virtual void Unk_090();
    virtual void Unk_094();
    virtual void Unk_098();
    virtual void Unk_09c();
    virtual void Unk_0a0();
    virtual void Unk_0a4();
    virtual void Unk_0a8();
    virtual void Unk_0ac();
    virtual void Unk_0b0();
    virtual void Update(float, bool, bool, bool, bool, bool);
    virtual void Unk_0b8();
    virtual void Unk_0bc();
    virtual void Unk_0c0();
    virtual void Unk_0c4();
    virtual void Unk_0c8();
    virtual void Unk_0cc();
    virtual void Unk_0d0();
    virtual bool IsActive();
    float FUN_005dd4a0(int);
};
class FaceGenParent
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual int IsReady();
};
class FaceGenNode
{
  public:
    virtual void Unk_000();
    virtual void Unk_004();
    virtual void Unk_008();
    virtual void Unk_00c();
    virtual void Unk_010();
    virtual void Unk_014();
    virtual void Unk_018();
    virtual void Unk_01c();
    virtual void Unk_020();
    virtual void Unk_024();
    virtual void Unk_028();
    virtual void Unk_02c();
    virtual void Unk_030();
    virtual void Unk_034();
    virtual void Unk_038();
    virtual void Unk_03c();
    virtual void Unk_040();
    virtual void Unk_044();
    virtual void Unk_048();
    virtual void Unk_04c();
    virtual void Unk_050();
    virtual void Unk_054();
    virtual void Unk_058();
    virtual void Unk_05c();
    virtual void Unk_060();
    virtual void Unk_064();
    virtual void Unk_068();
    virtual void Unk_06c();
    virtual void Unk_070();
    virtual void Unk_074();
    virtual void Unk_078();
    virtual void Unk_07c();
    virtual void Unk_080();
    virtual void Unk_084();
    virtual void Unk_088();
    virtual void Unk_08c();
    virtual void Unk_090();
    virtual void Unk_094();
    virtual void Unk_098();
    virtual void Unk_09c();
    virtual void Unk_0a0();
    virtual void Unk_0a4();
    virtual void Unk_0a8();
    virtual void Unk_0ac();
    virtual void Unk_0b0();
    virtual void Unk_0b4();
    virtual void Unk_0b8();
    virtual void Unk_0bc();
    virtual void Unk_0c0();
    virtual void Unk_0c4();
    virtual void Unk_0c8();
    virtual void Unk_0cc();
    virtual void Unk_0d0();
    virtual void Unk_0d4();
    virtual void Unk_0d8();
    virtual void Unk_0dc();
    virtual void Unk_0e0();
    virtual void Unk_0e4();
    virtual void Unk_0e8();
    virtual void Unk_0ec();
    virtual void Unk_0f0();
    virtual void Unk_0f4();
    virtual void Unk_0f8();
    virtual void Unk_0fc();
    virtual AnimationState* GetAnimation();
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
    bool resetMorph;
    bool unkD5, unkD6, unkD7;
    unsigned int unkD8, unkDC;
    bool unkE0, unkE1;
    bool forceUpdate, skipUpdate, refreshMorph;
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
    const NiPoint3& FUN_0045bb80() const;
    FaceGenParent* FUN_009611e0();
    void FUN_00662e90(FUN_00663430*);
    void ApplyParamValues(FUN_00663430*);
    void ApplyParameterValues(FUN_00663430*);
    void FUN_00662f70(FUN_00663430*);
    void FUN_00663050(bool);
};
void FUN_00653340(NiTriBasedGeom*, BSFaceGenMorphData*);

}  // namespace fnv_00663050

struct NiPtr6628
{
    void* m_pObject;
    NiPtr6628(void* p);
    ~NiPtr6628();
    NiPtr6628& operator=(void* p);
};

struct Block6628
{
    int v00;
    int v04;
    int v08;
    int v0C;
    int v10;
    int v14;
    int v18;
    int v1C;
    int v20;
    Block6628();
};

struct NodeBase6628
{
    NodeBase6628(unsigned short usChildren);
    virtual ~NodeBase6628();
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
};

namespace fg6628 {
struct FUN_006628c0 : NodeBase6628
{
    FUN_006628c0();
    virtual ~FUN_006628c0();

    NiPtr6628 spAnimationData;
    Block6628 block;
    bool unkD4;
    bool unkD5;
    bool bAnimationUpdate;
    bool unkD7;
    bool bApplyRotationToParent;
    float unkDC;
    bool unkE0;
    bool unkE1;
    bool unkE2;
    int unkE4;
    int unkE8;
    bool unkEC;
};
}

// Constructs the node, initializes spAnimationData, copies DAT_011a9448 into block, and assigns the listed fields.
// @f3 0x006b9260 (community match, verified in this file)
#include <string.h>
// candidate v2 FUN_006b9260 (184B) — new-expression clone
namespace f3m_006b9260 {

struct Heap6b9 {
    void* FUN_0086b930(unsigned int size);
    void FUN_0086ba60(void* p);
};
extern Heap6b9 DAT_01090a78;

struct Obj6b9;

struct FUN_006b91e0 {
    char pad0[0x70];
    static void* operator new(unsigned int s) { return DAT_01090a78.FUN_0086b930(s); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
    FUN_006b91e0(unsigned int a, unsigned int b, unsigned int c);
    ~FUN_006b91e0();
};

struct Obj6b9 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
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
    virtual void vf44(Obj6b9* copy);
    virtual void v48();
    unsigned int pad4;        // +0x04
    unsigned int u8;          // +0x08
    unsigned int uc;          // +0x0c
    unsigned int pad10[6];    // +0x10..0x24
    unsigned int u28;         // +0x28
    unsigned int pad2C[7];    // +0x2c..0x44
    unsigned int u48;         // +0x48
    unsigned int u4c;         // +0x4c
    float f50;       // +0x50
    unsigned int u54;
    unsigned int u58;
    unsigned int u5c;
    unsigned int arr[4];      // +0x60..0x6c
    Obj6b9* FUN_006b9260();
};

}

using namespace f3m_006b9260;

// pdb: ReanimateEffect::Copy | ReanimateEffect.obj | fnv360_0721_retail, vtable, medium
Obj6b9* Obj6b9::FUN_006b9260() {
    Obj6b9* obj = (Obj6b9*)new FUN_006b91e0(u28, u8, uc);
    vf44(obj);
    obj->u48 = u48;
    obj->u4c = u4c;
    obj->f50 = f50;
    obj->u54 = u54;
    obj->u58 = u58;
    obj->u5c = u5c;
    memcpy(obj->arr, arr, 0x10);
    return obj;
}


struct S_00662e90_Result
{
    virtual void* f00()
    {
        return 0;
    }
    virtual void* f01()
    {
        return 0;
    }
    virtual void* f02()
    {
        return 0;
    }
    virtual void* f03()
    {
        return 0;
    }
    virtual void* f04()
    {
        return 0;
    }
    virtual void* f05()
    {
        return 0;
    }
    virtual void* f06()
    {
        return 0;
    }
    virtual void* f07()
    {
        return 0;
    }
    virtual void* f08()
    {
        return 0;
    }
    virtual void* f09()
    {
        return 0;
    }
    virtual void* f10()
    {
        return 0;
    }
    virtual void* f11()
    {
        return 0;
    }
    virtual void* f12()
    {
        return 0;
    }
    virtual void* f13()
    {
        return 0;
    }
    virtual void* f14()
    {
        return 0;
    }
    virtual void* f15()
    {
        return 0;
    }
    virtual void* f16()
    {
        return 0;
    }
    virtual void* f17()
    {
        return 0;
    }
    virtual void* f18()
    {
        return 0;
    }
    virtual void* f19()
    {
        return 0;
    }
    virtual void* f20()
    {
        return 0;
    }
    virtual void* f21()
    {
        return 0;
    }
    virtual void* f22()
    {
        return 0;
    }
    virtual void* f23()
    {
        return 0;
    }
    virtual void* f24()
    {
        return 0;
    }
    virtual void* f25()
    {
        return 0;
    }
    virtual void* f26()
    {
        return 0;
    }
    virtual void* f27()
    {
        return 0;
    }
    virtual void* f28()
    {
        return 0;
    }
    virtual void* f29()
    {
        return 0;
    }
    virtual void* f30()
    {
        return 0;
    }
    virtual void* f31()
    {
        return 0;
    }
    virtual void* f32()
    {
        return 0;
    }
    virtual void* f33()
    {
        return 0;
    }
    virtual void* f34()
    {
        return 0;
    }
    virtual void* f35()
    {
        return 0;
    }
    virtual void* f36()
    {
        return 0;
    }
    virtual void* f37()
    {
        return 0;
    }
    virtual void* f38()
    {
        return 0;
    }
    virtual void* f39()
    {
        return 0;
    }
    virtual void* f40()
    {
        return 0;
    }
    virtual float f41(int)
    {
        return 0.0f;
    }
};

struct S_00662e90_This
{
    virtual void* f00()
    {
        return 0;
    }
    virtual void* f01()
    {
        return 0;
    }
    virtual void* f02()
    {
        return 0;
    }
    virtual void* f03()
    {
        return 0;
    }
    virtual void* f04()
    {
        return 0;
    }
    virtual void* f05()
    {
        return 0;
    }
    virtual void* f06()
    {
        return 0;
    }
    virtual void* f07()
    {
        return 0;
    }
    virtual void* f08()
    {
        return 0;
    }
    virtual void* f09()
    {
        return 0;
    }
    virtual void* f10()
    {
        return 0;
    }
    virtual void* f11()
    {
        return 0;
    }
    virtual void* f12()
    {
        return 0;
    }
    virtual void* f13()
    {
        return 0;
    }
    virtual void* f14()
    {
        return 0;
    }
    virtual void* f15()
    {
        return 0;
    }
    virtual void* f16()
    {
        return 0;
    }
    virtual void* f17()
    {
        return 0;
    }
    virtual void* f18()
    {
        return 0;
    }
    virtual void* f19()
    {
        return 0;
    }
    virtual void* f20()
    {
        return 0;
    }
    virtual void* f21()
    {
        return 0;
    }
    virtual void* f22()
    {
        return 0;
    }
    virtual void* f23()
    {
        return 0;
    }
    virtual void* f24()
    {
        return 0;
    }
    virtual void* f25()
    {
        return 0;
    }
    virtual void* f26()
    {
        return 0;
    }
    virtual void* f27()
    {
        return 0;
    }
    virtual void* f28()
    {
        return 0;
    }
    virtual void* f29()
    {
        return 0;
    }
    virtual void* f30()
    {
        return 0;
    }
    virtual void* f31()
    {
        return 0;
    }
    virtual void* f32()
    {
        return 0;
    }
    virtual void* f33()
    {
        return 0;
    }
    virtual void* f34()
    {
        return 0;
    }
    virtual void* f35()
    {
        return 0;
    }
    virtual void* f36()
    {
        return 0;
    }
    virtual void* f37()
    {
        return 0;
    }
    virtual void* f38()
    {
        return 0;
    }
    virtual void* f39()
    {
        return 0;
    }
    virtual void* f40()
    {
        return 0;
    }
    virtual void* f41()
    {
        return 0;
    }
    virtual void* f42()
    {
        return 0;
    }
    virtual void* f43()
    {
        return 0;
    }
    virtual void* f44()
    {
        return 0;
    }
    virtual void* f45()
    {
        return 0;
    }
    virtual void* f46()
    {
        return 0;
    }
    virtual void* f47()
    {
        return 0;
    }
    virtual void* f48()
    {
        return 0;
    }
    virtual void* f49()
    {
        return 0;
    }
    virtual void* f50()
    {
        return 0;
    }
    virtual void* f51()
    {
        return 0;
    }
    virtual void* f52()
    {
        return 0;
    }
    virtual void* f53()
    {
        return 0;
    }
    virtual void* f54()
    {
        return 0;
    }
    virtual void* f55()
    {
        return 0;
    }
    virtual void* f56()
    {
        return 0;
    }
    virtual void* f57()
    {
        return 0;
    }
    virtual void* f58()
    {
        return 0;
    }
    virtual void* f59()
    {
        return 0;
    }
    virtual void* f60()
    {
        return 0;
    }
    virtual void* f61()
    {
        return 0;
    }
    virtual void* f62()
    {
        return 0;
    }
    virtual void* f63()
    {
        return 0;
    }
    virtual S_00662e90_Result* f64()
    {
        return 0;
    }
};
