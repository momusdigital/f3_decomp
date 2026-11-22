// bsmenu/tile3d.cpp: Tile3D, Tile3DCalc, AnimTile, Interface and more (1 function)
#include "f3_common.h"
#include "tile3d_decls.h"

class NiNode;
class RgbaColor;

template <> class BSStringT<char>
{
  public:
    char opaque[8];
    bool Set(const char* value, unsigned int length);
};

class Tile
{
  public:
    virtual Tile* Destroy(bool doFree);
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalcNode();
    virtual unsigned int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk05(float first, float second);
    virtual Tile* UpdateField(unsigned int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual void* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, const RgbaColor& color);

    char layoutPadding[0x34];
};

class Tile3D : public Tile
{
  public:
    virtual Tile* SetTraitValue(int value, float number, const char* text);

    void* m_pParent;
    void* m_pChildTile;
    BSStringT<char> m_kName;
    BSStringT<char> strFilename;
};

void(__thiscall* const pFUN_0078bb60)(void*, int) = 0;

typedef void(__thiscall* FUN_0078bb60_t)(void*, int);

struct GameTimerRecord
{
    void Update(unsigned int);
    void Enable();
};
extern GameTimerRecord DAT_011f3560;
__declspec(dllimport) unsigned long __stdcall GetTickCount();
struct TileNU
{
    void SetTileType(int);
    void Set(int, float, bool);
};
struct FUN_00a20720_shell : public Tile3D
{
    void InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile);
};
// @f3 0x00bfddf0 (community match, verified in this file)
// pdb: Tile3D::Init | Tile3D.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apParent, apName, apReplacedTile
void FUN_00a20720_shell::InitTile(Tile* apParent, const char* apName, Tile* apReplacedTile)
{
    Tile::Init(apParent, apName, apReplacedTile);
    ((TileNU*)this)->Set(0xff5, 255.0f, true);
    ((TileNU*)this)->Set(0xfb2, 255.0f, true);
    ((TileNU*)this)->Set(0xfb3, 255.0f, true);
    ((TileNU*)this)->Set(0xfb4, 255.0f, true);
    ((TileNU*)this)->Set(0xfa9, 255.0f, true);
    ((TileNU*)this)->Set(0xfa3, 1.0f, true);
    ((TileNU*)this)->SetTileType(3);
    DAT_011f3560.Enable();
    DAT_011f3560.Update(GetTickCount());
}


struct NiTimeController;
struct NiRTTI;
struct NiAVObject
{
    NiTimeController* GetController(NiRTTI const*);
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct AVObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiNode* IsSceneNode();
    virtual void v04();
    virtual void v05();
    virtual PropHelper* IsGeometry();
};

extern char* EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char*);
    static long* GetRealBufferStart(char* const& h)
    {
        return ((long*)h) - 2;
    }
    static void DecRefCount(char*& h)
    {
        if (h == EmptyFS)
            return;
        NiAtomicSubtract(GetRealBufferStart(h)[0]);
    }
    static const char* GetString(char* const& h)
    {
        return h;
    }
    static long NiAtomicSubtract(long& v)
    {
        return InterlockedDecrement(&v);
    }
};
class NiFixedString
{
  public:
    NiFixedString(const char* pc)
    {
        if (pc == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pc);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    operator const char*() const
    {
        return NiGlobalStringTable::GetString(m_kHandle);
    }
    char* m_kHandle;
};
struct DummyPointerMapItem
{
    DummyPointerMapItem* m_pkNext;
    unsigned int m_key;
    unsigned int m_val;
};
struct DummyPointerMap
{
    virtual void V0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int a, unsigned int b);
    unsigned int m_uiHashSize;
    DummyPointerMapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(unsigned int key, unsigned int& val)
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        DummyPointerMapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(pkItem->m_key, key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};
class NiControllerSequence
{
  public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual bool Deactivate(float fEaseOutTime, bool bTransition);
    bool Activate(char, bool, float, float, NiControllerSequence*, bool);
    int GetState()
    {
        return m_eAnimationState;
    }
    char pad[0x40];
    int m_eAnimationState;
};
struct NiControllerManager
{
    void* vt;
    long rc;
    unsigned short m_uiObjectFlags;
    char pad[0x46];
    DummyPointerMap m_kPointerMap;
    void SetBit(bool bVal, unsigned short uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    NiControllerSequence* FindSequenceByName(const NiFixedString& kName)
    {
        NiControllerSequence* pkSequence;
        if (m_kPointerMap.GetAt((unsigned int)(const char*)kName, (unsigned int&)pkSequence))
            return pkSequence;
        return 0;
    }
    bool StopSequence(NiControllerSequence* pkSequence, float fEaseOutTime = 0.0f)
    {
        return pkSequence->Deactivate(fEaseOutTime, false);
    }
    bool ActivateControllerSequence(NiControllerSequence* pkSequence, int iPriority = 0, bool bStartOver = false,
                                    float fWeight = 1.0f, float fEaseInTime = 0.0f,
                                    NiControllerSequence* pkTimeSyncSeq = 0)
    {
        return pkSequence->Activate((char)iPriority, bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq, false);
    }
};
struct FUN_00a20cc0_t : public Tile3D
{
    NiNode* GetNode()
    {
        return *(NiNode**)((char*)this + 0x2c);
    }
    NiControllerManager* Mgr()
    {
        return (NiControllerManager*)m_pParent;
    }
    bool FUN_00a20cc0(const char* apSequenceName);
};

struct Tile3DStrField : BSStringT<char>
{
    ~Tile3DStrField()
    {
        Set(0, 0);
    }
};

struct Tile3DBaseDtor : Tile
{
    virtual ~Tile3DBaseDtor();
};

struct FUN_00a20650_cls : Tile3DBaseDtor
{
    void* m_pParent;
    void* m_pChildTile;
    Tile3DStrField m_kName;
    Tile3DStrField strFilename;
    __forceinline bool TestFlag(unsigned int mask) const
    {
        return (*(const unsigned int*)((const char*)this + 0x30) & mask) != 0;
    }
    virtual ~FUN_00a20650_cls();
};

class NiExtraData
{
  public:
    NiExtraData();
    virtual ~NiExtraData();
    void SetName(const NiFixedString& name);
    int unk04;
    int unk08;
};

class NiObjectNET
{
  public:
    virtual ~NiObjectNET();
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(NiNode* child, bool firstAvail);
    bool AddExtraData(NiExtraData* extra);
    void DecRefCount();
    void IncRefCount();
};

struct NiNodeChildArray
{
    NiNodeChildArray(int maxSize, int growBy);
    ~NiNodeChildArray();
    void RemoveAll();
    void* vtbl;
    int m_pBase;
    int m_usMaxSize;
    int m_usGrowBy;
};

class NiNode : public NiObjectNET
{
  public:
    NiNode(unsigned short arraySize);
    void UpdateModel();
    static void* operator new(unsigned int size);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNode* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int unk30;
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
    NiNodeChildArray m_kChildList;
};

template <class T> struct NiPtrX
{
    T* m_pObject;
    NiPtrX& operator=(T* p);
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct Tile__Extra : NiExtraData
{
    Tile* pTile;
    NiNode* pNode;
    Tile__Extra(Tile* tile, NiNode* node)
    {
        pTile = tile;
        pNode = node;
        SetName("Tileptr");
    }
    static void* operator new(unsigned int size);
};

struct TileX
{
    NiNode* GetNiNode();
};

extern "C" char* __cdecl strstr(const char*, const char*);
struct ModelPath
{
    char* buffer;
    unsigned int length;
};
int __cdecl FormatModelPath(ModelPath*, const char*, ...);
const char* __cdecl ModelRoot();
NiNode* __cdecl LoadTileModel(const char*, bool*);
NiNode* __cdecl CopyTileModel(NiNode*);
void __cdecl FinishTileModel(int);
void __cdecl FlushTileModel();

struct Tile3DCalc
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    TileX* parent;
    NiPtrX<NiNode> node;

    TileX* GetParent()
    {
        return parent;
    }
    unsigned int flags;
    int unk34, unk38, unk3c, unk40, unk44;
    ModelPath filename;
    const char* GetString(int);
    bool InitControllers(NiNode*);
    void InitGeometry(NiNode*);
    void InitProperties(NiNode*);
    void SetValue(int, float, bool);
    bool hkBufferedStreamWriter_isOk(int);
    void NiBoolInterpolator_Update(int);
    void LoadTile()
    {
        const char* name = GetString(0xfcc);
        if (!name)
            return;
        if (strstr(name, "\\Data"))
            FormatModelPath(&filename, "%s", name);
        else
            FormatModelPath(&filename, "%s\\%s", ModelRoot(), name);
        bool loaded = false;
        NiNode* model = LoadTileModel(filename.buffer, &loaded);
        if (!model)
        {
            node = 0;
            return;
        }
        if (loaded)
            flags |= 0x20000;
        else
            flags &= ~0x20000;
        if (model->m_pParentNode)
            model = CopyTileModel(model);
        InitControllers(model);
        node.m_pObject->m_kChildList.RemoveAll();
        InitGeometry(model);
        InitProperties(model);
        node.m_pObject->AttachChildInAvailableSlot(model, true);
        SetValue(0xfa8, 1.0f, true);
        if (!hkBufferedStreamWriter_isOk(0xfa3))
            node.m_pObject->unk30 |= 1;
        else
            node.m_pObject->unk30 &= ~1;
        node->UpdateModel();
        if (flags & 0x40)
            flags ^= 0x40;
        NiBoolInterpolator_Update(9);
        FinishTileModel(1);
        FlushTileModel();
    }
    NiNode* CreateTileNode();
};

extern "C" unsigned int __cdecl strlen(const char*);
struct AnimString
{
    char* text;
    unsigned short length, capacity;
    int StrCmp(const char*, bool) const;
    bool Set(const char*, unsigned int);
    const char* Get() const
    {
        return text;
    }
    bool operator==(const char* rhs) const
    {
        return !StrCmp(rhs, true);
    }
    AnimString& operator=(const char* rhs)
    {
        Set(rhs, 0);
        return *this;
    }
    bool operator!=(const char* rhs) const
    {
        return !(*this == rhs);
    }
    unsigned int Length() const
    {
        return length == 65535 ? strlen(Get()) : length;
    }
};
struct UpdateData
{
    float time;
    bool controllers, geom, transforms, selective, rigid;
    UpdateData(float t) : time(t), controllers(true), geom(false), transforms(false), selective(false), rigid(false)
    {}
};
struct AnimNode
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
    unsigned int flags;
    void SetFlag(bool b, unsigned int mask)
    {
        if (b)
            flags |= mask;
        else
            flags &= ~mask;
    }
    void Update(UpdateData&);
};
struct AnimSequence
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool Deactivate(float, bool);
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
    float duration, time;
    float GetTime() const
    {
        return time;
    }
    float GetDuration() const
    {
        return duration;
    }
};
struct AnimManager
{
    int unk00, unk04;
    unsigned short flags;
    void SetBit(bool b, unsigned short mask)
    {
        if (b)
            flags |= mask;
        else
            flags &= ~mask;
    }
    bool StopSequence(AnimSequence* seq, float ease = 0.0f)
    {
        return seq->Deactivate(ease, false);
    }
};

__declspec(dllimport) unsigned long __stdcall GetTickCount();
struct AnimTile
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
    AnimNode* node;
    int unk30, unk34;
    AnimManager* manager;
    AnimSequence* sequence;
    AnimString name;
    const char* GetString(int);
    bool HasValue(int);
    bool LoadSequence(const char*);
    AnimNode* GetNode()
    {
        return node;
    }
    bool UpdateAnimation(float value, bool force);
};

namespace fnv_00a21340 {
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct NiTexture;
struct TileShaderProperty : NiMemObject
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned int f68;
    unsigned int f6c;
    unsigned int f70;
    unsigned int f74;
    unsigned int f78;
    unsigned int f7c;
    unsigned int f80;
    unsigned int f84;
    unsigned int f88;
    unsigned int f8c;
    unsigned int f90;
    unsigned int f94;
    unsigned int f98;
    unsigned int f9c;
    unsigned int fa0;
    unsigned int fa4;
    unsigned int fa8;
    unsigned int fac;
    TileShaderProperty(bool);
    void FUN_00bb7a10(NiTexture*);
};

struct AVObj;
struct Geometry;
struct NiNode;

struct AVObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNode* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual Geometry* IsGeometry();
};

struct NodePointer
{
    AVObj* ptr;
    operator AVObj*() const
    {
        return ptr;
    }
    AVObj* operator->() const
    {
        AVObj* result = ptr;
        return result;
    }
};
struct NodeArray
{
    void* vf;
    NodePointer* data;
    unsigned short capacity, allocated, size;
    NodePointer& operator[](unsigned int i)
    {
        return data[i];
    }
};

struct NiNode : AVObj
{
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned int f68;
    unsigned int f6c;
    unsigned int f70;
    unsigned int f74;
    unsigned int f78;
    unsigned int f7c;
    unsigned int f80;
    unsigned int f84;
    unsigned int f88;
    unsigned int f8c;
    unsigned int f90;
    unsigned int f94;
    unsigned int f98;
    NodeArray children;
};

struct Prop
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int type;
    unsigned int GetType()
    {
        return type;
    }
    unsigned int IsType(unsigned int t)
    {
        return GetType() == t;
    }
};

struct TexPointer
{
    unsigned int f00, f04;
    NiTexture* ptr;
    NiTexture* Get()
    {
        return ptr;
    }
};
struct TexturingProp : Prop
{
    TexPointer** maps;
    NiTexture* GetTexture(unsigned int index)
    {
        TexPointer* map = maps[index];
        if (map)
        {
            NiTexture* texture = map->Get();
            return texture;
        }
        else
            return 0;
    }
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};

struct Geometry : PropHelper
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned int f68;
    unsigned int f6c;
    unsigned int f70;
    unsigned int f74;
    unsigned int f78;
    unsigned int f7c;
    unsigned int f80;
    unsigned int f84;
    unsigned int f88;
    unsigned int f8c;
    unsigned int f90;
    unsigned int f94;
    unsigned int f98;
    unsigned int f9c;
    unsigned int fa0;
    unsigned int fa4;
    unsigned int fa8;
    unsigned int fac;
    unsigned int fb0;
    unsigned int fb4;
    unsigned int fb8;
    unsigned int fbc;
    void* shader;
    void FUN_00a5b230(unsigned int);
    void RemoveProperty(unsigned int type)
    {
        int a, b, c, d, e;
        FUN_00a5b230(type);
    }
    void FUN_00439410(TileShaderProperty*);
};

void* __cdecl FUN_00b55560(unsigned int);
inline void* AllocateShader()
{
    void* result = FUN_00b55560(32);
    return result;
}

}  // namespace fnv_00a21340

namespace fnv_00a20980 {
long FinishScriptRunLock(void* p);
long InitScriptRunLock(void* p);

class NiAVObject
{
  public:
    void IncRefCount()
    {
        InitScriptRunLock(&unk04);
    }
    void DecRefCount()
    {
        if (!FinishScriptRunLock(&unk04))
            DeleteThis();
    }
    virtual void vf00();
    virtual void DeleteThis();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
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
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
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
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiAVObject* m_parent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int m_flags;

    NiAVObject* GetParent()
    {
        return m_parent;
    }
    void SetBit(bool val, unsigned int mask)
    {
        if (val)
            m_flags |= mask;
        else
            m_flags &= ~mask;
    }
    void SetAppCulled(bool val)
    {
        SetBit(val, 1);
    }
};

template <class T> class NiPtr;

template <class T> class NiTArray
{
  public:
    virtual void vf00();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = T(0);
        m_usSize = 0;
        m_usESize = 0;
    }
};

class NiNode : public NiAVObject
{
  public:
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
    NiTArray<NiPtr<NiAVObject> > m_children;
    void FUN_00a5a040();
};

template <class T> class NiPtr
{
  public:
    T* m_object;
    NiPtr(T* p)
    {
        m_object = p;
        if (m_object)
            m_object->IncRefCount();
    }
    ~NiPtr();
    NiPtr& operator=(const NiPtr& p);
    NiPtr& operator=(T* p)
    {
        if (m_object != p)
        {
            if (m_object)
                m_object->DecRefCount();
            m_object = p;
            if (m_object)
                m_object->IncRefCount();
        }
        return *this;
    }
    T* operator->() const
    {
        return m_object;
    }
    operator T*() const
    {
        return m_object;
    }
};

class BSString
{
  public:
    char* m_data;
    int m_len;
    const char* CStr()
    {
        return m_data;
    }
    int Sprintf(const char* fmt, ...);
};

class Tile3DX
{
  public:
    virtual void vf00();

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
    NiPtr<NiNode> node;
    unsigned int flags;
    int unk34;
    void* m_pParent;
    void* m_pChildTile;
    BSString m_kName;
    BSString strFilename;

    const char* GetString(int id);
    bool hkBufferedStreamWriter_isOk(int id);
    void Set(int id, float value, bool b);
    void FUN_00a07530(int a);
    bool AttachController(NiAVObject* obj);
    void RemovePropertyRecursive(NiAVObject* obj);
    void ConvertShadersToTileShader(NiAVObject* obj);
    void SetFlag20000(bool b)
    {
        b ? (flags |= 0x20000) : (flags &= ~0x20000);
    }
    void LoadTile();
};

}  // namespace fnv_00a20980
