#include "f3_common.h"
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl FUN_00d687c0(void);

struct Registry_00dd9380
{
    void* Register(char const*, void(__cdecl*)(void));
};

extern int DAT_01269cd0;
extern void* DAT_01269008;

// @fnv 0x00d68800
// pdb: hkpConstraintViewer::registerViewer | hkpConstraintViewer.obj | fnv360_0822_retail, udata, high
// pdb: hkpConstraintViewer::registerViewer | hkpConstraintViewer.obj | fnv360_0822_retail, udata, high (was: RegisterContactPointsInactive)
void hkpConstraintViewer_registerViewer()
{
    Registry_00dd9380* reg = (Registry_00dd9380*)DAT_01269cd0;
    DAT_01269008 = reg->Register("Contact Points (Inactive)", FUN_00d687c0);
}

namespace fnv_00d688d0 {
void FUN_00d68890();
extern int DAT_0126900c;
struct Registry_00dd9380_StandIn
{
    void* FUN_00dd9380(const char*, void(__cdecl*)());
};
extern Registry_00dd9380_StandIn* DAT_01269cd0;
// @fnv 0x00d688d0
// pdb: hkpRigidBodyCentreOfMassViewer::registerViewer | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_debug, udata, high
// pdb: hkpRigidBodyCentreOfMassViewer::registerViewer | hkpRigidBodyCentreOfMassViewer.obj | fnv360_0822_debug, udata, high (was: RegisterContactPointsActive)
void* hkpRigidBodyCentreOfMassViewer_registerViewer()
{
    DAT_0126900c = (int)DAT_01269cd0->FUN_00dd9380("Contact Points (Active)", FUN_00d68890);
    return (void*)DAT_0126900c;
}
}  // namespace fnv_00d688d0

// Constructor of the class whose vftables live at 0x010d1fb0 / 0x010d1f90 /
// 0x010d1f80 / 0x010d1f70: it calls the immediate base constructor and then
// installs the derived vftable pointers for the four base sub-objects.
extern int DAT_010d1fb0;
extern int DAT_010d1f90;
extern int DAT_010d1f80;
extern int DAT_010d1f70;

struct FUN_00d68770_cls
{
    int* m_pVtbl00;
    int m_unk04;
    int* m_pVtbl08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int* m_pVtbl20;
    int m_unk24;
    int* m_pVtbl28;

    void BaseConstruct(int aParam, int aFlags);
    FUN_00d68770_cls* Construct(int aParam);
};

// @fnv 0x00d68770
// pdb: hkpInactiveContactPointViewer::hkpInactiveContactPointViewer | hkpInactiveContactPointViewer.obj | fnv360_0822_retail, uvref, medium
// pdb params: contexts
FUN_00d68770_cls* FUN_00d68770_cls::Construct(int aParam)
{
    BaseConstruct(aParam, 0xff008000);
    m_pVtbl00 = &DAT_010d1fb0;
    m_pVtbl08 = &DAT_010d1f90;
    m_pVtbl20 = &DAT_010d1f80;
    m_pVtbl28 = &DAT_010d1f70;
    return this;
}

// @fnv 0x00d687b0
// pdb: hkpInactiveContactPointViewer::getIslands | hkpInactiveContactPointViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void* __stdcall FUN_00d687b0(char* a1)
{
    return a1 + 0x34;
}

struct FnvCpu_FUN_00d687c0_CpuBlock;
struct FnvCpu_FUN_00d687c0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d687c0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d687c0_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(unsigned int value);
};
// @fnv 0x00d687c0
void* __cdecl FUN_00d687c0(unsigned int value)
{
    FnvCpu_FUN_00d687c0_CpuHolder* holder = static_cast<FnvCpu_FUN_00d687c0_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d687c0_CpuBlock* block = static_cast<FnvCpu_FUN_00d687c0_CpuBlock*>(holder->allocator->Invoke(52));
    block->size = 52;
    block = block->Construct(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

extern "C" int DAT_010d203c;
extern "C" int DAT_010d201c;
extern "C" int DAT_010d200c;
extern "C" int DAT_010d1ffc;

void __stdcall FUN_00de29b0(int a, int b);

struct FUN_00d68840_cls
{
    void* m_p00;
    int m_i04;
    void* m_p08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    void* m_p20;
    int m_i24;
    void* m_p28;

    void* Init(int a);
};

// @fnv 0x00d68840
// pdb: hkpActiveContactPointViewer::hkpActiveContactPointViewer | hkpActiveContactPointViewer.obj | fnv360_0822_retail, uvref, medium
// pdb params: contexts
void* FUN_00d68840_cls::Init(int aiValue)
{
    FUN_00de29b0(aiValue, 0xff0000ff);
    m_p00 = (void*)&DAT_010d203c;
    m_p08 = (void*)&DAT_010d201c;
    m_p20 = (void*)&DAT_010d200c;
    m_p28 = (void*)&DAT_010d1ffc;
    return this;
}

// hkpActiveContactPointViewer (Havok Physics) - virtual at vftable offset 0x0c
// of the primary base (complete-object base offset 0) and at slot 11 of the
// base that lives at complete-object offset +0x08.
//
// The routine ignores `this` entirely and converts its single 4-byte stack
// argument into a pointer to the sub-object that sits 0x28 bytes further up.
//
// Original bytes:
//   00d68880  8b 44 24 04   mov eax, dword ptr [esp+4]
//   00d68884  83 c0 28      add eax, 0x28
//   00d68887  c2 04 00      ret 4

// @fnv 0x00d68880
// pdb: hkpActiveContactPointViewer::getIslands | hkpActiveContactPointViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: world
void* __stdcall FUN_00d68880(void* pObject)
{
    return (void*)((char*)pObject + 0x28);
}

namespace fnv_00d68890 {
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct FNV_Buffer
{
    int unk00;
    unsigned short m_w04;
    unsigned short m_w06;
    int unk08;

    void* Init(int a1);
};

AllocHolder* FUN_00c85750();

// @fnv 0x00d68890
void* __cdecl FUN_00d68890(int aiArg)
{
    AllocHolder* holder = FUN_00c85750();
    ObjAllocator* allocator = (ObjAllocator*)holder->m_pAllocator;
    FNV_Buffer* pBuffer = (FNV_Buffer*)allocator->Alloc(0x34);
    pBuffer->m_w04 = 0x34;
    void* r = pBuffer->Init(aiArg);
    return r != 0 ? (char*)r + 8 : 0;
}
}  // namespace fnv_00d68890

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.

extern int DAT_0126900c;

// @fnv 0x00d688f0
// pdb: GFxSpriteDef::GetHeight | GFxSprite.obj | tesv_win, objrun_open, low
int __cdecl FUN_00d688f0()
{
    return DAT_0126900c;
}

namespace fnv_00d68910 {
struct D68910Allocator
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D68910MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D68910Allocator* m_pStreamAllocator;

    D68910Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D68910MemoryRouter& __cdecl FUN_00c85750();

}  // namespace fnv_00d68910

extern char DAT_0126905c;

// @fnv 0x00d6ade0
void* __cdecl FUN_00d6ade0()
{
    return &DAT_0126905c;
}

struct S_00d6adf0_Obj
{
    virtual void vfn00(int arg);
};
// @fnv 0x00d6adf0
// pdb: cleanupLoadedObjecthkpSerializedAgentNnEntry | hkpSerializedAgentNnEntryClass.obj | fnv360_0822_retail, objrun_open, low, conflict (skyrim: cleanupLoadedObjecthkpMountedBallGun)
void __cdecl FUN_00d6adf0(S_00d6adf0_Obj* obj)
{
    obj->vfn00(0);
}

extern int DAT_0126908c;

// @fnv 0x00d6ae00
int* __cdecl FUN_00d6ae00()
{
    return &DAT_0126908c;
}

// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00d6aeb0
// pdb: cleanupLoadedObjecthkpProjectileGun | hkpUtilitiesReflections.obj | tesv_win, objrun_open, low
int __cdecl FUN_00d6aeb0(VtblForwarder* p)
{
    return p->v0(0);
}

extern int DAT_01269104;

// @fnv 0x00d6aee0
// pdb: getVtablehkpConvexPieceStreamData | hkpConvexPieceStreamDataClass.obj | fnv360_0822_retail, objrun_open, low
void* __cdecl FUN_00d6aee0()
{
    return &DAT_01269104;
}

struct ResultFlag
{
    bool value;
    ResultFlag(bool flag) : value(flag)
    {}
    operator bool() const
    {
        return value;
    }
    ResultFlag& operator=(bool flag)
    {
        value = flag;
        return *this;
    }
};
struct MotionSettings
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    float value8;
    float value9;
    float value10;
    float value11;
    ResultFlag IsValid();
};
// Checks that value0 through value4 lie in [0,1] and that value5 through value11 are non-negative, returning the combined result.
// @fnv 0x00d6b1c0
ResultFlag MotionSettings::IsValid()
{
    ResultFlag result(true);
    result = result && value0 >= 0.0f && value0 <= 1.0f;
    result = result && value1 >= 0.0f && value1 <= 1.0f;
    result = result && value2 >= 0.0f && value2 <= 1.0f;
    result = result && value3 >= 0.0f && value3 <= 1.0f;
    result = result && value4 >= 0.0f && value4 <= 1.0f;
    result = result && value5 >= 0.0f;
    result = result && value6 >= 0.0f;
    result = result && value7 >= 0.0f;
    result = result && value8 >= 0.0f;
    result = result && value9 >= 0.0f;
    result = result && value10 >= 0.0f;
    result = result && value11 >= 0.0f;
    return result;
}

struct D6C180Command
{
    union
    {
        float m_fValue;
        unsigned char m_ucType;
    };
    unsigned char m_ucFlag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
};

extern const double g_dD6C180Offset;

// @fnv 0x00d6c180
// pdb: hkSkipSolverResults | hkpBuildJacobianFromAtoms.obj | tesv_win, hash, low
void __fastcall WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag)
{
    D6C180Command* pkCommand = *ppkCursor;
    pkCommand->m_ucFlag = ucFlag;
    pkCommand->m_fValue = (float)(pkCommand->m_fValue + g_dD6C180Offset);
    pkCommand->m_ucType = 3;
    *ppkCursor = pkCommand + 1;
}

struct Inner
{
    void Tail();
};

struct FUN_00d76f90_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void FUN_00d76f90();
};

// @fnv 0x00d76f90
void FUN_00d76f90_cls::FUN_00d76f90()
{
    m_08->Tail();
}

namespace fnv_00d68820 {
extern int DAT_01269008;

// @fnv 0x00d68820
// pdb: NiD3DShaderFactory::GetD3DShaderFactory | NiD3DShaderFactory.obj | fnv360_0822_retail, call_gap_sim, medium
int FUN_00d68820()
{
    return DAT_01269008;
}
}  // namespace fnv_00d68820

inline void* operator new(unsigned int, void* pvMem)
{
    return pvMem;
}

struct hkFinishLoadedObjectFlagD6A
{
    int m_bFinishing;
};

template <class T> class hkSmallArrayD6A
{
  public:
    hkSmallArrayD6A() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

class hkMemberD6A
{
  public:
    hkMemberD6A(hkFinishLoadedObjectFlagD6A flag) throw();

    int unk00;
    int unk04;
    int unk08;
};

class hkBaseD6A
{
  public:
    __forceinline hkBaseD6A()
    {}
    virtual ~hkBaseD6A();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};

class hkDerivedD6A : public hkBaseD6A
{
  public:
    __forceinline hkDerivedD6A(hkFinishLoadedObjectFlagD6A flag) : m_kMemberDescriptor(flag)
    {
        m_iType = -16;
    }
    virtual ~hkDerivedD6A();

    hkSmallArrayD6A<int> m_ppData;
    hkMemberD6A m_kMemberDescriptor;
    int m_iType;
};

// Placement-constructs an hkDerivedD6A at pvObject with a finish-loaded flag built from iFinishing, if pvObject is non-null.
// @f3 0x008e8c10 (community match, verified in this file)
class FUN_008f7c10 {
public:
    FUN_008f7c10();
};
class Sub96 {
public:
    ~Sub96();
    void FUN_0096a7f0(int);
};
extern int DAT_010f33d0;
class FUN_008e8c10 : public FUN_008f7c10 {
    char _p0[0xc];
    int unk0c;
    Sub96 m10;
public:
    FUN_008e8c10();
};
// pdb: bhkRefObject::bhkRefObject | bhkRefObject.obj | fnv360_0721_beta, call_seq, low, conflict (bridge: bhkCharacterProxy::bhkCharacterProxy)
FUN_008e8c10::FUN_008e8c10() : unk0c(0) {
    *(int*)this = 0x00e3321c;
    m10.FUN_0096a7f0(0);
    DAT_010f33d0 += 1;
}


struct hkFinishLoadedObjectFlagD605
{
    int m_bFinishing;
};

class hkReferencedObjectD605
{
  public:
    hkReferencedObjectD605(hkFinishLoadedObjectFlagD605 flag)
    {}
    virtual ~hkReferencedObjectD605();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

extern int DAT_010d14f8;

namespace fnv_00d60860 {
struct HKMemoryManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int);
};
extern HKMemoryManager* DAT_01268364;
extern char DAT_010d14f8;
struct FUN_00d60860
{
    char* m_pVtbl;
    unsigned char m_uc04;
    unsigned short m_usSize;
    void* m_pData;
    unsigned char m_ucType;
    FUN_00d60860(void* pData, unsigned char ucType);
};
// Sets the vtable, size to 1 and type, and stores the result of DAT_01268364->v4(pData) in m_pData.
// @fnv 0x00d60860
// pdb: hkOArchive::hkOArchive | hkOArchive.obj | fnv360_0822_debug, objrun_sim, low
// pdb params: filename, bs
FUN_00d60860::FUN_00d60860(void* pData, unsigned char ucType)
{
    m_usSize = 1;
    m_pVtbl = &DAT_010d14f8;
    m_ucType = ucType;
    m_pData = DAT_01268364->v4((int)pData);
}
}  // namespace fnv_00d60860

void __stdcall hkOArchive_writeArrayGeneric(char**, int, int);

// @fnv 0x00d60900
// pdb: hkOArchive::write16 | hkOArchive.obj | fnv360_0822_retail, call_gap + bridge(call_dedup|call_gap) + skyrim(call_gap), high
void __stdcall hkOArchive_write16(char* p)
{
    hkOArchive_writeArrayGeneric(&p, 2, 1);
}

struct FUN_00d60600_class
{
    void __thiscall hkOArchive_writeArrayGeneric(int a, int b, int c);
    void __thiscall FUN_00d60b20(int a, int b);
};

// @fnv 0x00d60b20
void __thiscall FUN_00d60600_class::FUN_00d60b20(int a, int aiValue)
{
    hkOArchive_writeArrayGeneric(a, 8, aiValue);
}

struct FUN_00d61470_Class
{
    void* FUN_00d61470();
};

// @fnv 0x00d61470
// pdb: BGSCameraPathManager::GetRootPathArray | BGSCameraPathManager.obj | fnv360_0822_debug, call_gap, low
void* FUN_00d61470_Class::FUN_00d61470()
{
    return this;
}

char* __cdecl FUN_00cb1130(char* pcHaystack, const char* pcNeedle);

int __cdecl FUN_00cb1130(int a1, int a2);
struct FUN_00d61520_cls
{
    int unk00;
    int __thiscall FindOffset(int a, int b);
};
// @f3 0x00684960 (community match, verified in this file)
// pdb: StatsMenu::StimpakTargetConditionCallback | StatsMenu.obj | fnv360_0721_beta, call_gap, low
// pdb params: aHO
int FUN_00d61520_cls::FindOffset(int a, int b) {
    int (__cdecl *predicate)(int, int) = reinterpret_cast<int (__cdecl *)(int, int)>(a);
    FUN_00d61520_cls* node = this;
    int result = predicate(node->unk00, b);
    if ((unsigned char)result) {
        do {
            node = *(FUN_00d61520_cls**)((char*)node + 4);
            if (!node) break;
            result = predicate(node->unk00, b);
        } while ((unsigned char)result);
    }
    return result;
}


struct FUN_00d61640_cls
{
    char* m_data;
    int m_fRestLength;

    int FindLastCharInRange(char c, int startIndex, int endIndex);
};

// Searches m_data backwards from endIndex-1 down to startIndex for character c and returns its index, or -1 if not found.
// @fnv 0x00d61640
int FUN_00d61640_cls::FindLastCharInRange(char c, int startIndex, int endIndex)
{
    if (endIndex > m_fRestLength - 1)
        endIndex = m_fRestLength - 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        if (m_data[i] == c)
            return i;
    }
    return -1;
}

int __cdecl FUN_00cb0fa0(int, int);

int __cdecl hkString_strLen(int s);

int __cdecl hkString_strLen(const char* str);

struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

class hkStringBufD618
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int FindLastCharInRange(char c, int iStartIndex, int iEndIndex) const;
    void RemoveFront(int n);
    void TrimToFileName();
};

struct hkStringD618
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getLength() const
    {
        return m_iElementCount - 1;
    }

    ResultFlag ReplaceChar(char from, char to, int replaceType);
};

// @f3 0x00923a80 (community match, verified in this file)
// pdb: hkArrayBase<char>::copy | hkStringBuf.obj | fnv360_0822_debug, objrun_open, low
// pdb params: dst, src, n
ResultFlag hkStringD618::ReplaceChar(char from, char to, int replaceType)
{
    ResultFlag result(false);
    for (int i = 0; i < getLength(); ++i)
    {
        if (m_data[i] == from)
        {
            m_data[i] = to;
            result = true;
            if (replaceType == 0)
                break;
        }
    }
    return result;
}


namespace fnv_00d61890 {
struct hkStringD618
{
    static int toLower(char c)
    {
        return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
    }
};

template <class T> class hkArrayD618
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkStringBufD618
{
  public:
    hkArrayD618<char> m_kStringBuffer;

    void ToLower();
};

}  // namespace fnv_00d61890

class hkMemoryAllocatorD61B;

struct hkMemoryRouterD61B
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61B* m_pTemp;
    hkMemoryAllocatorD61B* m_pStreamAllocator;
    hkMemoryAllocatorD61B& temp()
    {
        return *m_pTemp;
    }
};
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61B& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T, int N> class hkInplaceArrayD61B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    hkInplaceArrayD61B() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(hkMemoryAllocatorD61B& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(static_cast<hkMemoryRouterD61B*>(FUN_00c85750())->temp(), n);
        m_iElementCount = n;
    }
};

int __cdecl hkString_strLen(int);
void* __cdecl FUN_00c85750();

class hkMemoryAllocatorD61E;

struct hkMemoryRouterD61E
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61E* m_pTemp;
    hkMemoryAllocatorD61E& temp()
    {
        return *m_pTemp;
    }
};

int __cdecl hkString_strLen(const char* pcString) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61E& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkStringBufD61E
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getLength() const
    {
        return m_iElementCount - 1;
    }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorD61E& kAlloc = static_cast<hkMemoryRouterD61E*>(FUN_00c85750())->temp();
        int iCap = m_iCapacityState & 0x3fffffff;
        if (iCap < n)
        {
            int iNewCap = 2 * iCap;
            FUN_00c908c0(kAlloc, this, n < iNewCap ? iNewCap : n, 1);
        }
        m_iElementCount = n;
    }

    void AppendStrings(const char* s0, const char* s1, const char* s2, const char* s3, const char* s4,
                       const char* s5) throw();
};

class hkMemoryAllocatorD620;

struct hkMemoryRouterD620
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD620* m_pTemp;
    hkMemoryAllocatorD620* m_pStreamAllocator;
    hkMemoryAllocatorD620& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD620 {
extern "C" hkMemoryRouterD620& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD620& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00d2caa0(void* pvDst, void* pvSrc, unsigned int uiNumBytes);

class hkStringBufD620
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD620& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(char));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD620::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }

    void Assign(void* src, int len);
};

int __cdecl hkString_strLen(int value);
void* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(int value1, int value2, int value3, int value4);
void __cdecl FUN_00d2caa0(void* value1, unsigned int value2, unsigned int value3);

extern int __cdecl hkString_strLen(int value);

struct hkStringPtr
{
    const char* m_stringAndFlags;
    const char* cString() const
    {
        return (const char*)((unsigned int)m_stringAndFlags & ~1);
    }
};

struct FUN_00ddccb0_Obj
{
    void FUN_00ddccb0(int a1);
};

struct FUN_00d62ef0_cls
{
    int* unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
    int unk24;
    unsigned char unk28;

    FUN_00d62ef0_cls* FUN_00d62ef0(int aParam, unsigned char aValue);
};

extern int DAT_010d1720;
extern int DAT_010d1700;
extern int DAT_010d16f0;

// Calls FUN_00ddccb0 with aParam, then stores three global addresses and aValue into the object's fields and returns this.
// @fnv 0x00d62ef0
// pdb: hkpWorldSnapshotViewer::hkpWorldSnapshotViewer | hkpWorldSnapshotViewer.obj | fnv360_0822_debug, caller_sim, low
// pdb params: contexts, convertToPC
FUN_00d62ef0_cls* __thiscall FUN_00d62ef0_cls::FUN_00d62ef0(int aParam, unsigned char aValue)
{
    ((FUN_00ddccb0_Obj*)this)->FUN_00ddccb0(aParam);
    unk00 = &DAT_010d1720;
    unk08 = &DAT_010d1700;
    unk20 = &DAT_010d16f0;
    unk28 = aValue;
    return this;
}

struct Allocator_d632c0
{
    virtual void slot00();
    virtual void* Allocate(unsigned int size);
};

struct Holder_d632c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator_d632c0* allocator;
};

struct Base1_d632c0
{
    virtual void vfn1();
    unsigned short size;
    unsigned short ref;
};

struct Base2_d632c0
{
    virtual void vfn2();
};

struct Obj_d632c0 : Base1_d632c0, Base2_d632c0
{
    Obj_d632c0* FUN_00d63280(int a, int b);
};

// @fnv 0x00d632c0
Base2_d632c0* FUN_00d632c0(int aiValue)
{
    Holder_d632c0* holder = (Holder_d632c0*)FUN_00c85750();
    Obj_d632c0* obj = (Obj_d632c0*)holder->allocator->Allocate(0x54);
    obj->size = 0x54;
    obj = obj->FUN_00d63280(0, aiValue);
    return obj;
}

struct hkContainerD633
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
    void** m_items;
    int m_uiItemCount;
};

struct hkListenerD633
{
    virtual void v00(void* p);
    virtual void v04(void* p);
};

struct hkObjD633
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkListenerD633 m_kListener;
    hkContainerD633* m_container;

    void FUN_00d63300();
};

// Iterates the container's items and passes each to the listener's v04 callback when m_container is set.
// @fnv 0x00d63300
// pdb: hkpWorldMemoryViewer::init | hkpWorldMemoryViewer.obj | fnv360_0822_retail, vtable, medium
void hkObjD633::FUN_00d63300()
{
    if (m_container)
    {
        for (int i = 0; i < m_container->m_uiItemCount; i++)
            m_kListener.v04(m_container->m_items[i]);
    }
}

class FUN_00ddf050_cls
{
  public:
    virtual ~FUN_00ddf050_cls() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addObject(const char* pcName, const void* pvObject, int iFlags) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_data;
    int m_iElementCount;

    void ClearContainer() throw();
    void FUN_00ddf030(int i) throw();
    void FUN_00ddf040() throw();

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    bool hasData() const
    {
        return m_iElementCount > 0 && m_data;
    }
    char* getData() const
    {
        return m_iElementCount > 0 ? m_data : 0;
    }
};

class hkDisplayHandlerD633
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void V1C() throw();
    virtual void V20() throw();
    virtual void V24() throw();
    virtual void V28() throw();
    virtual void V2C() throw();
    virtual void V30() throw();
    virtual void V34() throw();
    virtual void V38() throw();
    virtual void V3C() throw();
    virtual void WriteOutput(const char* pcData, int iLength) throw();
};

class hkpWorldD633;

class hkpPhysicsContextD633
{
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
    hkpWorldD633** m_ppWorlds;
    int m_numWorlds;
};

class FUN_00d63370_class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDisplayHandlerD633* m_pDisplayHandler;
    int unk14;
    int unk18;
    hkpPhysicsContextD633* m_iValueAtOffset0C;
    FUN_00ddf050_cls m_pStreamWriter;

    void UpdatePhysicsDebugDisplay(float fFrameTime) throw();
};

// Rebuilds the debug display buffer with each physics world, then passes the buffer and its length to the display handler.
// @f3 0x009ef890 (community match, verified in this file)
class DisplayHandlerX
{
  public:
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
    virtual void WriteOutput(const char* pcData, int iLength) throw();
};

class StreamInner
{
  public:
    virtual ~StreamInner() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addObject(const char* pcName, int iFlags, const void* pvObject) throw();

    int unk04;
    char* m_data;
    int m_iElementCount;

    bool hasData() const { return m_iElementCount > 0 && m_data; }
    char* getData() const { return m_iElementCount > 0 ? m_data : 0; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct StreamContainer
{
    int unk00;
    int unk04;
    StreamInner inner;

    void ClearContainer() throw();
    void FUN_00a64ac0(int i) throw();
    void FUN_00a64ae0() throw();
};

// pdb: hkpWorldMemoryViewer::step | hkpWorldMemoryViewer.obj | fnv360_0822_retail, vtable, medium
// pdb params: frameTimeInMs
void FUN_00d63370_class::UpdatePhysicsDebugDisplay(float fFrameTime) throw()
{
    StreamContainer* stream = (StreamContainer*)&m_pStreamWriter;
    stream->ClearContainer();
    stream->FUN_00a64ac0(0xf);
    for (int i = 0; i < m_iValueAtOffset0C->m_numWorlds; i++)
        ((StreamContainer*)&m_pStreamWriter)->inner.addObject("World", 4, m_iValueAtOffset0C->m_ppWorlds[i]);
    stream->FUN_00a64ae0();
    if (stream->inner.hasData())
        ((DisplayHandlerX*)m_pDisplayHandler)->WriteOutput(stream->inner.getData(),
            ((StreamContainer*)&m_pStreamWriter)->inner.GetLogicalSize());
}


namespace fnv_00d63400 {
class FUN_00dd9380_class
{
  public:
    void* FUN_00dd9380(const char* pcName, void* pvCreateFunc);
};

void __cdecl FUN_00d632c0();

extern void* DAT_01268fc8;

// @fnv 0x00d63400
// pdb: hkpSweptTransformDisplayViewer::registerViewer | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, ustr, medium
void __cdecl InitWorldMemory()
{
    DAT_01268fc8 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->FUN_00dd9380("World Memory", (void*)FUN_00d632c0);
}
}  // namespace fnv_00d63400

extern int DAT_01268fc8;
// @fnv 0x00d63420
int __cdecl FUN_00d63420()
{
    return DAT_01268fc8;
}

class hkMemoryAllocatorD634
{
  public:
    virtual ~hkMemoryAllocatorD634() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD634
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD634* m_pStreamAllocator;
    hkMemoryAllocatorD634& heap()
    {
        return *m_pStreamAllocator;
    }
};
void* __cdecl FUN_00c85750();

class FUN_00d63340
{
  public:
    virtual ~FUN_00d63340() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        ((hkMemoryRouterD634*)FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<FUN_00d63340*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d63340* Destroy(unsigned int uiFlags) throw();
};

class hkPart0D642
{
  public:
    virtual ~hkPart0D642() throw();
    int unk04;
};

class hkPart8D642
{
  public:
    virtual void p8() = 0;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkPart20D642
{
  public:
    virtual void p20() = 0;
    int unk24;
};

class hkBaseD642 : public hkPart0D642, public hkPart8D642, public hkPart20D642
{
};

class FUN_00ddccb0 : public hkBaseD642
{
  public:
    FUN_00ddccb0(void* p) throw();
};

class hkIfaceAD642
{
  public:
    virtual void a0() = 0;
};

class hkIfaceBD642
{
  public:
    virtual void b0() = 0;
};

template <class T> struct hkArrayD642
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD642() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00d64260 : public FUN_00ddccb0, public hkIfaceAD642, public hkIfaceBD642
{
  public:
    hkArrayD642<void*> m_ppData;

    FUN_00d64260(void* p) throw();
    virtual ~FUN_00d64260() throw();
    virtual void p8();
    virtual void p20();
    virtual void a0();
    virtual void b0();
};

// Constructs the object by forwarding p to the base constructor and default-initializing the void* array member.
// @fnv 0x00d64260
// pdb: hkpSweptTransformDisplayViewer::hkpSweptTransformDisplayViewer | hkpSweptTransformDisplayViewer.obj | fnv360_0822_retail, caller_sim, medium
// pdb params: contexts
FUN_00d64260::FUN_00d64260(void* p) throw() : FUN_00ddccb0(p)
{}

struct FnvCpu_FUN_00d645f0_CpuBlock;
struct FnvCpu_FUN_00d645f0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d645f0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d645f0_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
// @fnv 0x00d645f0
void* __cdecl FUN_00d645f0(unsigned int value)
{
    FnvCpu_FUN_00d645f0_CpuHolder* holder = static_cast<FnvCpu_FUN_00d645f0_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d645f0_CpuBlock* block = static_cast<FnvCpu_FUN_00d645f0_CpuBlock*>(holder->allocator->Invoke(60));
    block->size = 60;
    block = block->FUN_00d64260(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

namespace fnv_00d64630 {
class FUN_00dd9380_class
{
  public:
    void* FUN_00dd9380(const char* pcName, void* pvCreateFunc);
};

extern void* DAT_01268fd0;
void __cdecl FUN_00d645f0();

// @fnv 0x00d64630
// pdb: hkpShapeDisplayViewer::registerViewer | hkpShapeDisplayViewer.obj | fnv360_0822_retail, call_gap, low
void __cdecl RegisterSweptTransformsTask()
{
    DAT_01268fd0 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->FUN_00dd9380("Swept Transforms", (void*)FUN_00d645f0);
}
}  // namespace fnv_00d64630

struct FnvCpu_FUN_00d65260_CpuObject
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
    unsigned char unk64;
    unsigned char value;
    void FUN_00d65260(unsigned char arg0);
};
// @fnv 0x00d65260
void FnvCpu_FUN_00d65260_CpuObject::FUN_00d65260(unsigned char arg0)
{
    value = arg0;
}

struct FnvCpu_FUN_00d65270_CpuObject
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
    unsigned char unk60;
    unsigned char unk61;
    unsigned char value;
    void FUN_00d65270(unsigned char arg0);
};
// @fnv 0x00d65270
void FnvCpu_FUN_00d65270_CpuObject::FUN_00d65270(unsigned char arg0)
{
    value = arg0;
}

struct FUN_00d65280_cls
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
    char unk60;
    char unk61;
    char unk62;
    bool m_63;

    void FUN_00d65280(bool bValue);
};

// @fnv 0x00d65280
void FUN_00d65280_cls::FUN_00d65280(bool bValue)
{
    m_63 = bValue;
}

struct FnvCpu_FUN_00d65290_CpuObject
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
    unsigned char value;
    void FUN_00d65290(unsigned char arg0);
};
// @fnv 0x00d65290
void FnvCpu_FUN_00d65290_CpuObject::FUN_00d65290(unsigned char arg0)
{
    value = arg0;
}

extern "C" void __cdecl FUN_00d72e90();
// @fnv 0x00d73380
// pdb: bhkHingeLimitsConstraint::SetEntityB | bhkHingeLimitsConstraint.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: apEntity
void __cdecl FUN_00d73380()
{
    FUN_00d72e90();
}

class FUN_00d733e0
{
  public:
    FUN_00d733e0();

    int m_iFirst;
    int m_iSecond;
    bool m_bEnableState;
};

// @fnv 0x00d733e0
// pdb: hkpTransformCollapseUtil::Results::Results | hkpTransformCollapseUtil.obj | fnv360_0822_retail, callee_sim, low, conflict (skyrim: hkpTransformCollapseUtil::Options::Options)
FUN_00d733e0::FUN_00d733e0()
{
    m_iFirst = 0;
    m_iSecond = 0;
    m_bEnableState = true;
}

struct FUN_00d73400_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void FUN_00d73400();
};

// @fnv 0x00d73400
// pdb: hkpTransformCollapseUtil::Results::reset | hkpTransformCollapseUtil.obj | tesv_win, call_seq, medium
void FUN_00d73400_cls::FUN_00d73400()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0C = 0;
}

class hkOstreamD734
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00cb1600(void* pvBuffer, int iSize) throw();
    void FUN_00cc00e0() throw();
    hkOstreamD734& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamD734& WriteInt(int i) throw();

    hkOstreamD734(void* pvBuffer, int iSize)
    {
        FUN_00cb1600(pvBuffer, iSize);
    }
    ~hkOstreamD734()
    {
        FUN_00cc00e0();
    }
};

class hkErrorD734
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorD734* DAT_01268360;

struct hkpTransformCollapseUtilResultsD734
{
    int m_iFirstResult;
    int m_iSecondResult;
    int m_iThirdResult;
    int m_iFourthResult;

    void hkpTransformCollapseUtil_Results_report() throw();
};

// Logs four counters (collapsed shapes, removed identity transforms, specialized shapes, propagated transforms) via hkErrorD734::message.
// @fnv 0x00d73430
// pdb: hkpTransformCollapseUtil::Results::report | hkpTransformCollapseUtil.obj | fnv360_0822_retail, ustr, high
// pdb: hkpTransformCollapseUtil::Results::report | hkpTransformCollapseUtil.obj | fnv360_0822_retail, ustr, high (was: PrintResults)
void hkpTransformCollapseUtilResultsD734::hkpTransformCollapseUtil_Results_report() throw()
{
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of collapsed shapes :").WriteInt(m_iFirstResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 57);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of identity transforms removed : ").WriteInt(m_iSecondResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 58);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of specialized transform shapes : ").WriteInt(m_iThirdResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 59);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of propagated transforms to lists : ").WriteInt(m_iFourthResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 60);
    }
}

struct FnvCpu_FUN_00d76d80_CpuTarget
{
    void FUN_00d81340();
};
struct FnvCpu_FUN_00d76d80_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00d76d80_CpuTarget* target;
    void FUN_00d76d80();
};
// @fnv 0x00d76d80
void FnvCpu_FUN_00d76d80_CpuOwner::FUN_00d76d80()
{
    target->FUN_00d81340();
}

extern int DAT_010d14f8;
struct hkBoolD608
{
    unsigned char value;
    hkBoolD608(bool enabled = false) : value(enabled)
    {}
    hkBoolD608(const hkBoolD608& other) : value(other.value)
    {}
};

int __cdecl FUN_00cb0fa0(int, int);
struct R
{
    volatile char value;
    R(bool b) : value(b)
    {}
};

class hkMemoryAllocatorD619;

struct hkMemoryRouterD619
{
    int unk00, unk04, unk08;
    hkMemoryAllocatorD619* m_pStreamAllocator;

    hkMemoryAllocatorD619& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD619 {
extern "C" hkMemoryRouterD619& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(hkMemoryAllocatorD619& kAlloc, void* pArray, int iElemSize);

template <class T> __forceinline void constructWithCopyD619(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD619
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

    void _pushBack(hkMemoryAllocatorD619& kAlloc, T t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(kAlloc, this, sizeof(T));
        constructWithCopyD619(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(T t)
    {
        _pushBack(hkRouterD619::FUN_00c85750().heap(), t);
    }
};

class hkMemoryAllocatorD61
{
  public:
    virtual ~hkMemoryAllocatorD61();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemoryRouterD61
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61* m_alloc;
};

template <class T> inline void hkArrayCopyD61(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

class FUN_00d619d0
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00d619d0& operator=(const FUN_00d619d0& a);
};

// Copies the source array, growing the buffer via the memory router if the source size exceeds the current capacity.
// @fnv 0x00d619d0
FUN_00d619d0& FUN_00d619d0::operator=(const FUN_00d619d0& aSource)
{
    hkMemoryAllocatorD61& alloc = *static_cast<hkMemoryRouterD61*>(FUN_00c85750())->m_alloc;
    if ((m_iCapacityState & 0x3fffffff) < aSource.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff));
        int n = aSource.m_iElementCount;
        m_data = (char*)alloc.AllocateBufferWithSize(n);
        m_iCapacityState = n;
    }
    m_iElementCount = aSource.m_iElementCount;
    hkArrayCopyD61(m_data, aSource.m_data, m_iElementCount);
    return *this;
}

struct FUN_00d61a50_cls
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int* FUN_00d61a50(int value);
};

namespace fnvc_adapt {
char* __cdecl hkString_strLen(int value);
}
void __cdecl FUN_00c908c0(int allocator, FUN_00d61a50_cls* array, int capacity, int value);
void __cdecl FUN_00cb1260(int* data, int value, char* source);

class hkMemoryAllocatorD61B8
{
  public:
    virtual ~hkMemoryAllocatorD61B8() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD61B8
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61B8* m_pTemp;
    hkMemoryAllocatorD61B8* m_pStreamAllocator;
    hkMemoryAllocatorD61B8& temp()
    {
        return *m_pTemp;
    }
};

template <class T> __forceinline void hkArrayCopyD61B8(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; ++i)
        pDst[i] = pSrc[i];
}

template <class T, int N> class hkInplaceArrayD61B8
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline hkInplaceArrayD61B8(const hkInplaceArrayD61B8& kOther) throw()
        : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {
        hkMemoryAllocatorD61B8& kAlloc = static_cast<hkMemoryRouterD61B8*>(FUN_00c85750())->temp();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = kOther.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(n));
            m_iCapacityState = n / sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        hkArrayCopyD61B8(m_data, kOther.m_data, m_iElementCount);
    }
};

struct C6DF60Router;
struct C6DF60Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};

class hkMemoryAllocatorD61F;

struct hkMemoryRouterD61F
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61F* m_pTemp;
    hkMemoryAllocatorD61F* m_pStreamAllocator;
    hkMemoryAllocatorD61F& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61F {
extern "C" hkMemoryRouterD61F& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61F& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayD61F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD61F& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD61F::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

class hkStringBufD61F
{
  public:
    hkArrayD61F<char> m_kStringBuffer;

    void FUN_00d61f70(int n);
};

namespace fnv_00d61fc0 {
class hkMemoryAllocatorD61F;

struct hkMemoryRouterD61F
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61F* m_pTemp;
    hkMemoryAllocatorD61F* m_pStreamAllocator;
    hkMemoryAllocatorD61F& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61F {
extern "C" hkMemoryRouterD61F& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61F& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkStringBufD61F
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void FUN_00d61fc0(int iOffset, int iLength);
};

}  // namespace fnv_00d61fc0

class hkMemoryAllocatorD62
{
  public:
    virtual ~hkMemoryAllocatorD62() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD62
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD62* m_pStreamAllocator;

    hkMemoryAllocatorD62& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD62 {
extern "C" hkMemoryRouterD62& __cdecl FUN_00c85750() throw();
}

class hkReferencedObjectD62
{
  public:
    virtual ~hkReferencedObjectD62();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD62* b =
            static_cast<hkReferencedObjectD62*>(hkRouterD62::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkpCollisionAgentD62
{
  public:
    virtual void cleanup();
};

class FUN_00d62ef0 : public hkReferencedObjectD62, public hkpCollisionAgentD62
{
  public:
    FUN_00d62ef0(void* contactMgr, int flags) throw();

    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};

// @fnv 0x00d6c1a0
// pdb: hkUndoBeginConstraints | hkpBuildJacobianFromAtoms.obj | tesv_win, objrun_sim, low
__declspec(noinline) static void FUN_00d6c1a0(int* piValue)
{
    *piValue -= 16;
}

void E6C1A0Adjust(int* piValue)
{
    FUN_00d6c1a0(piValue);
}

// FUN_00d73400's body must be in-TU so VC9 knows it clobbers only eax:
// that is what lets the ctor keep `this` live in ECX across the call
// (matches orig: xor eax,eax; mov [ecx..0xc],eax; call; mov eax,ecx; ret).
class FUN_00d73410;

struct Z0
{
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    void FUN_00d73400();
};

__declspec(noinline) void Z0::FUN_00d73400()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
}

class FUN_00d73410
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    FUN_00d73410();
};

// @fnv 0x00d73410
// pdb: hkpTransformCollapseUtil::Options::Options | hkpTransformCollapseUtil.obj | fnv360_0822_retail, call_gap, low, conflict (skyrim: hkpTransformCollapseUtil::Results::Results)
FUN_00d73410::FUN_00d73410()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
    ((Z0*)this)->FUN_00d73400();
}

volatile char g_d61430_c;
char g_d61430_sink;

volatile char g_d61450_c;
char g_d61450_sink;

struct D6C1B0Owner
{
    int unk00;
    void(__cdecl* unk04)(int, int, D6C180Command**);
    int unk08;
};

extern "C" D6C180Command** d6c1b0_cursor_src(void);
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;

// @fnv 0x00d6c1b0
// pdb: callBridgeFromAtom | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun_open, low
static __declspec(noinline) void FUN_00d6c1b0(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1)
{
    *ppkCursor -= 1;
    pOwner->unk04(pOwner->unk08, a1, ppkCursor);
}

void d6c1b0_caller(void)
{
    FUN_00d6c1b0(d6c1b0_cursor_src(), g_d6c1b0_owner, g_d6c1b0_a1);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};

struct IntegratorD720
{
    float unk00;
    float offset;
    float unk08;
    float unk0c;
    float state;
};

IntegratorD720* volatile integratorD720;
volatile float inputD720, stepD720, resultD720;

#include <stdarg.h>
struct hkAllocatorD624
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD624
{
    void* m_apvUnk00[3];
    hkAllocatorD624* m_pkHeap;
    hkAllocatorD624& heap()
    {
        return *m_pkHeap;
    }
};
void* __cdecl FUN_00c85750();
inline hkMemoryRouterD624* getRouterD624()
{
    return (hkMemoryRouterD624*)FUN_00c85750();
}

void __cdecl FUN_00c908c0(hkAllocatorD624& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayD624
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void GrowArrayCapacity(hkAllocatorD624& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(getRouterD624()->heap(), n);
        m_iElementCount = n;
    }
    __forceinline ~hkArrayD624()
    {
        hkAllocatorD624& kAlloc = getRouterD624()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
    }
};

class hkStringBufD624
{
  public:
    hkArrayD624<char> m_kStringBuffer;
    unsigned int m_kStorage[32];

    void InitBuffer() throw();
    hkStringBufD624()
    {
        InitBuffer();
    }

    const char* cString() const
    {
        return m_kStringBuffer.m_data;
    }
    __forceinline void setLength(int iLength)
    {
        m_kStringBuffer.SetSizeAndGrow(iLength + 1);
        m_kStringBuffer[iLength] = 0;
    }
};

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d68830();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d68830();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68830
    virtual void FUN_00d68830();
};

Derived::Derived()
{}

namespace fnv_00d68900 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk (second base's vtable entry).
// PrimaryBase is 0x20 bytes: vptr + seven ints.
struct PrimaryBase
{
    virtual void FUN_00d68900();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68900();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68900
    virtual void FUN_00d68900();
};

Derived::Derived()
{}
}  // namespace fnv_00d68900

// @fnv 0x00d6c590
// pdb: buildJacobianFromIgnoreModifier | hkpBuildJacobianFromAtoms.obj | tesv_win, objrun_sim, low
static __declspec(noinline) void FUN_00d6c590(int* p)
{
    *p -= 0x10;
}

void zz_probe_d6c590(int* p)
{
    FUN_00d6c590(p);
}

namespace fnv_00d61c10 {
class hkMemoryAllocatorD61C;

struct hkMemoryRouterD61C
{
    int unk00, unk04, unk08;
    hkMemoryAllocatorD61C* m_pTemp;
    hkMemoryAllocatorD61C* m_pStreamAllocator;
    hkMemoryAllocatorD61C& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61C {
extern "C" hkMemoryRouterD61C& __cdecl FUN_00c85750() throw();
}
extern "C" int __cdecl hkString_strLen(const char* pcString) throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61C& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T> class hkArrayD61C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD61C& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD61C::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

}  // namespace fnv_00d61c10

namespace fnv_00d63340 {
namespace FUN_00ddcc60 {
class hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldViewerBase();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

class hkpWorldDeletionListenerD633
{
  public:
    virtual void WorldDeletedCallback(void* pkWorld) = 0;
    int unk04, unk08, unk0C, unk10, unk14;
};

class hkpActionListenerD633
{
  public:
    virtual void ActionAddedCallback(void* pkAction) = 0;
};

namespace FUN_00ddf240 {
class hkArrayD633
{
  public:
    ~hkArrayD633() throw();
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
}

namespace FUN_00d63340 {
class hkpWorldMemoryViewer : public FUN_00ddcc60::hkpWorldViewerBase,
                             public hkpWorldDeletionListenerD633,
                             public hkpActionListenerD633
{
  public:
    virtual ~hkpWorldMemoryViewer();
    virtual void WorldDeletedCallback(void* pkWorld);
    virtual void ActionAddedCallback(void* pkAction);

    int unk24;
    FUN_00ddf240::hkArrayD633 m_kArray;
};

// @fnv 0x00d63340
hkpWorldMemoryViewer::~hkpWorldMemoryViewer()
{}
}
}  // namespace fnv_00d63340

class RotationColumns;

class QuadDirection
{
  public:
    __forceinline QuadDirection()
    {}
    __forceinline QuadDirection(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void operator=(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void multiply(const RotationColumns& rotation, const QuadDirection& input);
    __m128 value;
};

class RotationColumns
{
  public:
    __forceinline RotationColumns()
    {}
    __forceinline RotationColumns(const RotationColumns& other)
    {
        columns[0] = other.columns[0];
        columns[1] = other.columns[1];
        columns[2] = other.columns[2];
    }
    __forceinline QuadDirection& column(int i)
    {
        return columns[i];
    }
    __forceinline const QuadDirection& column(int i) const
    {
        return columns[i];
    }
    QuadDirection columns[3];
};

class Orientation : public RotationColumns
{
};

class RigidTransform
{
  public:
    __forceinline Orientation& rotation()
    {
        return orientation;
    }
    __forceinline const Orientation& rotation() const
    {
        return orientation;
    }
    Orientation orientation;
    QuadDirection translation;
};

template <class T> class QueryValue
{
  public:
    __forceinline T get() const
    {
        return value;
    }
    T value;
};

struct ConstraintQuery
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    QueryValue<const RigidTransform*> transformA;
    QueryValue<const RigidTransform*> transformB;
};

extern "C" __m128 _mm_load_ps(const float* p);

class UpperCaseBufferD618 : public hkStringBufD618
{
  public:
    int getLength() const
    {
        return m_iElementCount - 1;
    }
    void FUN_00d618d0();
};

extern "C" __m128 _mm_load_ps(const float*);
struct TransformContext
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
    const __m128* m_pM1;
    const __m128* m_pM2;
};

struct TransformPair
{
    __m128 m_row[4];
};

TransformPair* volatile inputDest;
const __m128* volatile inputSource;
const TransformContext* volatile inputContext;
__m128* volatile inputOut;

struct PivotsC320
{
    QuadDirection m_unk00;
    QuadDirection m_kPivotA;
    QuadDirection m_kPivotB;
};

struct TransformOutputC320
{
    RigidTransform* p;
    TransformOutputC320(RigidTransform* value) : p(value)
    {}
};

const ConstraintQuery* volatile bodiesSourceC320;
const PivotsC320* volatile pivotsSourceC320;
RigidTransform* volatile outASourceC320;
RigidTransform* volatile outBSourceC320;

// @f3 0x00a00dd0 (community match, verified in this file)
    extern float DAT_01063590;
    extern float DAT_01063594;
    extern float DAT_00e368bc;
namespace f3m_00a00dd0 {
struct Cls_a00dd0
{
    int   unk00;
    float f04;
    float f08;
    float f0c;
    float f10;
    int   unk14;
};

static Cls_a00dd0 g_objA00a;
static float g_inA00a;
static float g_inB00a;
static volatile float g_outA00a;

// pdb: calculateRhs | hkpSimpleContactConstraintInfo.obj | tesv_win, hash, low
static __declspec(noinline) float FUN_00a00dd0(Cls_a00dd0* self, float a, float b)
{

    float r = self->f10;
    float d = a - r;
    float u = -self->f04 - d;
    float w = DAT_01063590 * b;
    float lim = -DAT_01063594 * r;
    float m = lim < w ? lim : w;
    r = r + m;
    float z = d - m;
    if (u > w + 2.0f * m)
    {
        r = r - u;
        z = z + u;
    }
    float t;
    if (DAT_00e368bc > r)
        t = r;
    else
        t = DAT_00e368bc;
    self->f10 = t;
    return z;
}

void caller_a00dd0()
{
    g_outA00a = FUN_00a00dd0(&g_objA00a, g_inA00a, g_inB00a);
}
}   // namespace f3m_00a00dd0

// @f3 0x00a00dc0 (community match, verified in this file)
namespace f3m_00a00dc0 {
struct Integrator_a00dc0
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
};

// pdb: hkAddVelocityBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, call_gap_sim, low, conflict (skyrim: hkSimpleContactConstraintDataAddALittleSurfaceViscosity)
// pdb params: deltaVel, bodyIndex, out
void __cdecl FUN_00a00dc0(Integrator_a00dc0* self)
{
    self->unk0c = 0.0f;
    self->unk14 = 0.0f;
    self->unk1c = 0.0f;
}
}   // namespace f3m_00a00dc0
