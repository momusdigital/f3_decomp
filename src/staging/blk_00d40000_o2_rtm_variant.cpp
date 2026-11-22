// src/staging/blk_00d40000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d40000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00d40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern int DAT_010cf9a4;
extern int DAT_010cfb34;
struct FUN_00d4b250_vt
{
    virtual void __thiscall FUN_00d4b250(int);
};
void __cdecl FUN_00d4b250(FUN_00d4b250_vt* p);
struct FUN_00d4be50_vt
{
    virtual void FUN_00d4be50(int);
};
void __cdecl FUN_00d4be50(FUN_00d4be50_vt* p);
struct FUN_00d4b1f0_vt
{
    virtual void __thiscall FUN_00d4b1f0(int);
};
void __cdecl FUN_00d4b1f0(FUN_00d4b1f0_vt* p);
struct FUN_00d4bf30_vt
{
    virtual void FUN_00d4bf30(int);
};
void __cdecl FUN_00d4bf30(FUN_00d4bf30_vt* p);
// CreateSpawnObject: cdecl factory. Allocates one of two object sizes through the
// global allocator holder. A non-zero flag selects the large object (0x80 bytes,
// constructor takes the flag, then the vtable is stored); zero selects the small
// object (0x30 bytes, constructor returns the object).
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};
struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
AllocHolder* __cdecl FUN_00c85750();
struct FNVDispatchType
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
    virtual void v10();
    virtual void v11(void* first, void* second, int code);
    int m_unk04;
    int m_unk08;
    int m_typeId;
};
struct FNVDispatchNode
{
    FNVDispatchType* m_pName;
    int m_unk04;
    int m_unk08;
    FNVDispatchNode* m_pNext;
};
static FNVDispatchNode* FNVTailOf(FNVDispatchNode* n)
{
    FNVDispatchNode* t = n;
    while (t->m_pNext != 0)
    {
        t = t->m_pNext;
    }
    return t;
}
void __cdecl FUN_00d42760();
void __cdecl FUN_00d42780();
extern int DAT_010cf9a4;
struct S_00d483a0_Result
{
    char v;
    S_00d483a0_Result()
    {}
    S_00d483a0_Result(char c)
    {
        v = c;
    }
};
static inline unsigned S_00d483a0_Swap(unsigned value)
{
    unsigned r;
    unsigned char* p = (unsigned char*)&r;
    p[0] = (unsigned char)(value >> 24);
    p[1] = (unsigned char)(value >> 16);
    p[2] = (unsigned char)(value >> 8);
    p[3] = (unsigned char)value;
    return r;
}
// InitAndCall: cdecl, 5 stack args. Builds a 12-byte temp from (a1, a2),
// reads a field of the temp's returned pointer, calls a 4-arg cdecl helper,
// then disposes the temp and returns the helper result.
void* __cdecl FUN_00d48fc0(void* p, void* b, void* c, void* d);
extern int DAT_010cfb34;
// @fnv 0x00d4b160
// Forwarding helper: if the object pointer is valid, pass the second
// argument on to the object's own handler.
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is handed to a member function of that
// object.
// Constructor of a scene-graph style node: initialises the base node
// (FUN_00dcd310) and then the derived node's own vtable pointers and
// member state.
struct D4BF10FinishFlag
{
    int m_bFinishing;
};
class D4BF10Object
{
  public:
    D4BF10Object(D4BF10FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
extern int DAT_01268f74;
extern int DAT_01268188;
extern int DAT_01268f74;
extern __declspec(thread) int g_ThreadMemoryContext;
void* __cdecl FUN_00aa13e0(unsigned int size);
struct DataBase
{
    DataBase();
    virtual ~DataBase();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct DataIntermediate : DataBase
{
    int unk04;
    int unk08;
    int unk0c;
    DataIntermediate() : unk0c(0)
    {
        ++DAT_01268188;
    }
};
struct DataObject : DataIntermediate
{
    DataObject()
    {
        ++DAT_01268f74;
    }
};
struct MemoryContextScope
{
    int previousContext;
    MemoryContextScope()
    {
        previousContext = g_ThreadMemoryContext;
        g_ThreadMemoryContext = 16;
    }
    ~MemoryContextScope()
    {
        g_ThreadMemoryContext = previousContext;
    }
};
// FUN_00d53220 — destructor of a polymorphic class.
//
// Shape deduced from the target disassembly:
//   * SEH prologue (push -1 / handler / fs:[0]) with an EH state slot at
//     [esp+0x14] and a saved `this` slot at [esp+8]  -> destructor whose
//     unwind funclet must run the base class destructor.
//   * `mov [esi], vftable`  -> class with a virtual destructor.
//   * state 0 guards the body call to the free routine at 0x00c876a0.
//   * `dec dword ptr [0x1268f80]` -> body decrements a global counter.
//   * `mov ecx, esi / state -1 / call 0x00c89640` -> compiler-generated
//     base class destructor call (stand-in base named by its address).
// Stand-in for the polymorphic base class whose destructor lives at
// 0x00c89640. The base supplies the vfptr at offset 0, so the generated
// base-destructor call in ~FUN_00d53220 passes `this` unchanged.
class D53360BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(D53360BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(D53360BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
class D53360Object;
class D53360Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(D53360Object* pkObject);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    D53360BinaryStream* m_pBackingStream;
};
template <class T>
inline void D53360BinaryStreamSave(D53360BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void D53360SaveBinary(D53360Stream& kStream, const T& value)
{
    D53360BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class ObjBaseA
{
  public:
    virtual ~ObjBaseA();
    int m_04;
    int m_08;
    int m_0c;

    ObjBaseA(int flag)
    {
        if (flag)
            *(volatile int*)&m_0c = 0;
        m_0c = 0x12;
    }
};
struct SearchObject
{
    int Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
void __cdecl ResizeAudioStream(void*, void*, int);
extern __declspec(thread) int g_tlsMemContext;
struct ScopedMemoryContextD53
{
    int iOldContext;
    __forceinline ScopedMemoryContextD53(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    __forceinline ~ScopedMemoryContextD53()
    {
        g_tlsMemContext = iOldContext;
    }
};
class hkBool
{
  public:
    char m_cBooleanValue;
    __forceinline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
class hkErrorD53
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine);
};
extern hkErrorD53* DAT_01268360;
struct WorldObjD53
{
    char pad00[0x24];
    void* m_pvEntity;
};
struct ParamD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual WorldObjD53* v037();
    virtual void v038();
    virtual void v039();
    char pad04[0x14];
    unsigned int m_uiCount;
};
struct HolderD53
{
    char pad00[8];
    void* m_pvWorld;
};
struct ConstraintD53
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual int v037();
    virtual void v038();
    virtual void v039(ParamD53* pkParam);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050(ParamD53* pkParam);
    char pad04[4];
    HolderD53* m_pkHolder;
    char pad0c[4];
    unsigned char m_ucFlags;

    void FUN_00a29680();
};
__forceinline hkBool IsInWorldD53(HolderD53* pkHolder)
{
    return pkHolder->m_pvWorld != 0;
}
__forceinline bool HasWorldD53(ConstraintD53* pkConstraint, HolderD53* pkHolder)
{
    pkConstraint->FUN_00a29680();
    bool bResult = IsInWorldD53(pkHolder);
    pkConstraint->FUN_00a29680();
    return bResult;
}
__forceinline void* GetEntityD53(WorldObjD53* pkObj)
{
    void* pvEntity = 0;
    if (pkObj)
        pvEntity = pkObj->m_pvEntity;
    return pvEntity;
}
struct D53970Stream
{
    unsigned int ReadCount();
    struct D53970Link* ReadLink();
};
struct D53970Link
{
    int unk00;
    int unk04;
    int m_uiFilterValue;
};
struct D53970Alloc
{
    int unk00;
};
struct D53970Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D53970Alloc* m_pStreamAllocator;
    D53970Alloc& Heap()
    {
        return *m_pStreamAllocator;
    }
};
D53970Router& GetMemoryRouter();
struct D53970HeapAlloc
{
    D53970Alloc& Get()
    {
        return GetMemoryRouter().Heap();
    }
};
struct D53970Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void Reserve(D53970Alloc& alloc, int n);
    void SetSizeA(D53970Alloc& alloc, int n)
    {
        Reserve(alloc, n);
        m_iElementCount = n;
    }
    void SetSize(int n)
    {
        SetSizeA(D53970HeapAlloc().Get(), n);
    }
};
struct D53970Scope
{
    int m_saved;
    int* m_pVar;
    D53970Scope()
    {
        m_pVar = &g_ThreadMemoryContext;
        m_saved = *m_pVar;
        *m_pVar = 16;
    }
    ~D53970Scope()
    {
        *m_pVar = m_saved;
    }
};
void __cdecl FUN_00c908c0(D53970Alloc* alloc, D53970Array* arr, int n, int elemSize);
inline void D53970Array::Reserve(D53970Alloc& alloc, int n)
{
    if (GetCapacity() < n)
    {
        int cap2 = 2 * GetCapacity();
        int newSize = (n < cap2) ? cap2 : n;
        FUN_00c908c0(&alloc, this, newSize, 4);
    }
}
struct PlaceTag
{
};
inline void* operator new(unsigned int, void* p, PlaceTag)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, PlaceTag)
{}
AllocHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, void*, int);
namespace d51 {
template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& e)
    {
        AllocHolder* a = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(a->m_pAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount], PlaceTag()) T(e);
        m_iElementCount++;
    }
};
struct Writer
{
    int unk;
    int m_iBytes;
    int m_iArrayLength;
    int m_iCount2;
    char pad[0x1c - 0x10];
    hkArray<int> m_kArr;
    void Add()
    {
        m_iArrayLength++;
        m_iCount2++;
        m_iBytes += 0x30;
    }
};
}
void FUN_00d42760();
void __cdecl FUN_00d42780();
struct FUN_00c90510_Obj
{
    void FUN_00c90510();
};
class hkMemoryAllocatorD539;
struct hkMemoryRouterD539
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD539* m_pStreamAllocator;

    hkMemoryAllocatorD539& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD539 {
extern "C" hkMemoryRouterD539& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD539& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T> class hkArrayD539
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD539& kAlloc, int n)
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
        reserve(hkRouterD539::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
float __fastcall FUN_00d54dd0(char* self, int);
typedef unsigned int D57Uint32;
static __forceinline void D57MemCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const D57Uint32* src32 = reinterpret_cast<const D57Uint32*>(src);
    D57Uint32* dst32 = reinterpret_cast<D57Uint32*>(dst);
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}
class hkMemoryAllocatorD5E0
{
  public:
    virtual ~hkMemoryAllocatorD5E0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD5E0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD5E0* m_pStreamAllocator;
    hkMemoryAllocatorD5E0& heap()
    {
        return *m_pStreamAllocator;
    }
};
class hkReferencedObject
{
  public:
    void removeReference() throw();
};
class hkReferencedObjectD5E0
{
  public:
    virtual ~hkReferencedObjectD5E0() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        reinterpret_cast<hkMemoryRouterD5E0*>(FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<hkReferencedObjectD5E0*>(p)->m_usMemSizeAndFlags);
    }
};
class hkpShapeContainerD5E0
{
  public:
    virtual ~hkpShapeContainerD5E0() throw()
    {}
};
class hkpSingleShapeContainerD5E0 : public hkpShapeContainerD5E0
{
  public:
    hkReferencedObject* m_pContainedShape;

    ~hkpSingleShapeContainerD5E0() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->removeReference();
    }
};
// FUN_00d48fc0 - loads a Havok packfile/tagfile from a stream and dispatches
// on the format that was detected in it.
extern void* DAT_01269b70;
struct Hk48fc0_Bool
{
    char m_bVal;
    Hk48fc0_Bool()
    {}
    operator bool() const
    {
        return m_bVal != 0;
    }
};
struct Hk48fc0_String
{
    char* m_pText;
    void __thiscall FUN_00cb0a60();
    void __thiscall FUN_00cb0c00();
    Hk48fc0_String* __thiscall FUN_00cb0c10(const char* pText);
    int __thiscall Equals(const char* pText);
};
struct Hk48fc0_Magic
{
    unsigned int m_uValue;
    Hk48fc0_Bool __thiscall MatchesTag(const unsigned char* pExpected);
};
struct Hk48fc0_Format
{
    int m_nType;
    Hk48fc0_String m_strVersion;
    Hk48fc0_Magic m_kMagic;
};
struct Hk48fc0_Contents
{
    void* m_pData;
    void __thiscall FUN_00dba7f0();
    void __thiscall FUN_00dba0d0(void* pArg1, void* pArg2);
};
struct Hk48fc0_Data
{
    void* m_pVtbl;
    void* m_pData;
    int m_nRef;
    void __thiscall FUN_00dc8030();
    void __thiscall FUN_00dc8080();
    void* __thiscall ForwardToReceiver(Hk48fc0_Contents* pOut);
};
void* __cdecl FUN_00dc32c0(void* pData, void* pAllocator, void* pLoader);
int __cdecl FUN_00d48950(void* pObj, void* pArg1, void* pArg2, void* pArg3);
void __cdecl FUN_00dc5d50(void* pArg1, void* pArg2, void* pArg3);
__declspec(noinline) static int Hk48fc0_ReadTagfile(Hk48fc0_Data* pObj, void* pError, void* pStream, void* pAllocator)
{
    Hk48fc0_Contents kBuf;
    FUN_00dc5d50(&kBuf, &pStream, pObj);
    if (pError)
    {
        if (FUN_00d48950(pObj, pError, DAT_01269b70, pAllocator) == 0)
        {
            return 1;
        }
    }
    kBuf.FUN_00dba0d0(pObj, pAllocator);
    return 0;
}
__declspec(noinline) static void* Hk48fc0_LoadPackfile(void* pAllocator, void* pStream, Hk48fc0_Format* pFormat,
                                                       void* pError, void* pLoader)
{
    if (pAllocator == 0)
    {
        return 0;
    }
    FUN_00dc5d50(pAllocator, &pStream, &pFormat);
    return FUN_00dc32c0(&pError, &pLoader, 0);
}
void* __cdecl FUN_00d48fc0(void* pStream, void* pError, void* pAllocator, void* pLoader);
struct d20base
{
    int f0;
};
d20base* volatile g_d20_self;
// FUN_00d4b390: element-size helper of the BGS load-form buffer code.
// Takes the base element size and a small type code, and returns the
// element size for that type code: type 1 -> base + 2, type 2 -> base*2 + 1,
// anything else -> base * 3.
//
// The original keeps its operands in registers (base in ecx, type code in
// eax): it is a helper VC9 gives a private register convention because its
// callers are known at compile time. Defining it as a static noinline
// helper with its caller in this file reproduces that convention.
volatile int g_base_d4b390;
volatile int g_code_d4b390;
volatile int g_sink_d4b390;
struct hkFinishLoadedObjectFlagD50
{
    int m_bFinishing;
};
class FUN_00d21ce0_cls
{
  public:
    FUN_00d21ce0_cls(hkFinishLoadedObjectFlagD50 flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pOwnerObject);
    }
    void FUN_00d21ce0(void* owner);

    int unk00;
    int unk04;
    void* m_pOwnerObject;
};
extern __declspec(thread) unsigned int t_uiMemContextD53;
class AutoMemContextD53
{
  public:
    AutoMemContextD53(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = t_uiMemContextD53;
        t_uiMemContextD53 = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextD53()
    {
        t_uiMemContextD53 = m_uiPrevious;
    }
    unsigned int m_uiPrevious;
};
class hkMemoryAllocatorD53
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterD53
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorD53* m_pTemp;
    hkMemoryAllocatorD53* m_pStreamAllocator;
    hkMemoryAllocatorD53& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterD53& __cdecl GetMemoryRouterD53();
struct hkArrayUtilD53
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocatorD53& kAlloc, void* apvArray, int iNumElements,
                                          int iSizeElem);
};
template <typename T> struct hkArrayD53
{
    hkArrayD53() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayD53()
    {
        hkMemoryAllocatorD53& kAlloc = GetMemoryRouterD53().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void reserve(hkMemoryAllocatorD53& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtilD53::GrowArrayCapacity(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(GetMemoryRouterD53().heap(), n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class NiCloningProcessD53;
class hkpShapeContainerD53;
class NiObjectD53
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual NiObjectD53* MakeClone(NiCloningProcessD53& kCloning);
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
    virtual hkpShapeContainerD53* GetContainer(char* pcOut);
};
template <class K, class V> struct NiTMapItemD53
{
    NiTMapItemD53* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTMapD53
{
  public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K key1, K key2) const;
    bool GetAt(K key, V& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItemD53<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    unsigned int m_uiHashSize;
    NiTMapItemD53<K, V>** m_ppkHashTable;
};
class NiCloningProcessD53
{
  public:
    NiTMapD53<NiObjectD53*, NiObjectD53*>* m_pCloneMap;
};
class bhkRefObjectD53 : public NiObjectD53
{
  public:
    unsigned int m_uiRefCount;
    void* m_phkObject;
};
class hkpShapeD53
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    bhkRefObjectD53* m_pkWrapper;
};
class hkpShapeContainerD53
{
  public:
    virtual void v00();
};
class hkpListShapeD53
{
  public:
    unsigned int unk00;
    hkpShapeContainerD53 m_kContainer;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    hkArrayD53<hkpShapeD53*> m_kChildShapes;
};
inline hkpListShapeD53* ToListShapeD53(hkpShapeContainerD53* pkContainer)
{
    return pkContainer ? reinterpret_cast<hkpListShapeD53*>(reinterpret_cast<char*>(pkContainer) - 4) : 0;
}
volatile char* g_d48420_p;
struct FieldWord
{
    unsigned char value;
    FieldWord(unsigned char x) : value(x)
    {}
    FieldWord& operator=(unsigned char x)
    {
        value = x;
        return *this;
    }
    operator unsigned char() const
    {
        return value;
    }
};
extern "C" void _ReadWriteBarrier();
extern int DAT_010cfb34;
class hkMemoryAllocatorD539
{
  public:
    virtual ~hkMemoryAllocatorD539();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
};
class FUN_00d50c90
{
  public:
    virtual ~FUN_00d50c90();
    unsigned short sizeAndFlags, referenceCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void* data28;
    int size2c, flags30;
    void* data34;
    int size38, flags3c;
    void* data40;
    int size44, flags48;
    void* data4c;
    int size50, flags54;
    FUN_00d50c90();
    static void* operator new(unsigned int bytes)
    {
        FUN_00d50c90* p = (FUN_00d50c90*)hkRouterD539::FUN_00c85750().heap().AllocateMemoryBlock(bytes);
        p->sizeAndFlags = (unsigned short)bytes;
        return p;
    }
    static void operator delete(void* p)
    {
        hkRouterD539::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d50c90));
    }
};
struct D502D0_TlsBlock
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) D502D0_TlsBlock g_d502d0Tls;
struct D502D0_TlsGuard
{
    unsigned int m_saved;
    D502D0_TlsGuard()
    {
        m_saved = g_d502d0Tls.m_2b4;
        g_d502d0Tls.m_2b4 = 0x10;
    }
    ~D502D0_TlsGuard()
    {
        g_d502d0Tls.m_2b4 = m_saved;
    }
};
struct D502D0_Allocator
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern D502D0_Allocator DAT_011f6238;
extern int DAT_010c9f38;
struct D502D0_RefData
{
    unsigned int m_uiFilterValue;
};
struct D502D0_RefObject
{
    void* m_pVtable;
    D502D0_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline D502D0_RefData* D502D0_CreateReference()
{
    D502D0_RefObject* object = reinterpret_cast<D502D0_RefObject*>(DAT_011f6238.FUN_00aa3e40(sizeof(D502D0_RefObject)));
    if (object)
    {
        D502D0_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9f38;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
inline void* operator new(unsigned int, void* p)
{
    return p;
}
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);
template <class T> struct hkArray_d51b
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        AllocHolder* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pAllocator, this, sizeof(T));
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};
struct Info_d51b
{
    int unk00;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    int unk10, unk14, unk18;
    hkArray_d51b<int> m_kBridgeAtoms;
    void add(int schema, int results, int temps)
    {
        m_iSchemaByteSize += schema;
        m_iSolverResultCount += results;
        m_iSolverElementTemporaryCount += temps;
    }
};
struct FUN_00dd0530
{
    unsigned int unk00;
    unsigned short size, flags;
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
    FUN_00dd0530(int);
    void hkpConstraintChainInstance_addEntity(int);

    __forceinline void* SetSizeAndGrow(unsigned int n)
    {
        size = (unsigned short)n;
        return this;
    }
    static void* operator new(unsigned int n)
    {
        AllocHolder* h = FUN_00c85750();
        return ((FUN_00dd0530*)((ObjAllocator*)h->m_pAllocator)->Alloc(n))->SetSizeAndGrow(n);
    }
    static void operator delete(void*);
};
extern __declspec(thread) unsigned int t_uiMemContext35D0;
inline unsigned int GetMemContext35D0()
{
    return t_uiMemContext35D0;
}
inline void SetMemContext35D0(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext35D0 = m_uiGeometryShaderFlags;
}
class AutoMemContext35D0
{
  public:
    AutoMemContext35D0(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContext35D0();
        SetMemContext35D0(m_uiGeometryShaderFlags);
    }
    ~AutoMemContext35D0()
    {
        SetMemContext35D0(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};
struct hkpWorld35D0
{
    bool UpdateEntity(void* m_pHavokObject);
};
struct Entity35D0
{
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
    hkpWorld35D0* GetWorld() const
    {
        return m_pkWorld;
    }
    hkpWorld35D0* m_pkWorld;
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
struct hkVector4
{
    __m128 m_vComponents;
};
typedef signed char hkInt8;
typedef unsigned char hkUint8;
struct FinishingFlag
{
    int m_bFinishing;
};
template <typename ENUM, typename STORAGE> struct hkEnumF
{
    STORAGE m_kStorage;

    __forceinline hkEnumF(FinishingFlag)
    {}
    __forceinline operator ENUM() const
    {
        return (ENUM)m_kStorage;
    }
    __forceinline void operator=(ENUM e)
    {
        m_kStorage = (STORAGE)e;
    }
};
template <unsigned int ELEMENTSIZE, unsigned int ALIGNMENT_SIZE>
__forceinline void memCpyOneAligned(void* dst, const void* src)
{
    for (unsigned int i = 0; i < ELEMENTSIZE / 8; i++)
    {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    }
}
struct hkMemoryAllocatorF
{
    virtual ~hkMemoryAllocatorF();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct hkMemoryRouterF
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocatorF* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorF& heap()
    {
        return *m_pStreamAllocator;
    }
};
__forceinline hkMemoryRouterF* getRouter()
{
    return (hkMemoryRouterF*)FUN_00c85750();
}
template <typename T> struct hkArrayF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArrayF(FinishingFlag)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorF& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(getRouter()->heap());
    }

    __forceinline void setDataUserFree(T* p, int size, int capacity)
    {
        m_data = p;
        m_iElementCount = size;
        m_iCapacityState = capacity | 0x80000000;
    }
};
class hkBaseObjectF
{
  public:
    virtual void __vecDelDtor(unsigned int);
};
class hkReferencedObjectF : public hkBaseObjectF
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    __forceinline hkReferencedObjectF(FinishingFlag)
    {}
};
class hkpShapeF : public hkReferencedObjectF
{
  public:
    unsigned int m_ulUserData;
    int m_type;

    __forceinline hkpShapeF(FinishingFlag flag) : hkReferencedObjectF(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 0;
        }
    }
};
class hkpShapeContainerF
{
  public:
    virtual void unkContainer0();
    virtual int GetNumChildShapes() const;
};
class hkpShapeCollectionF : public hkpShapeF, public hkpShapeContainerF
{
  public:
    enum CollectionType
    {
        COLLECTION_LIST,
        COLLECTION_EXTENDED_MESH,
        COLLECTION_TRISAMPLED_HEIGHTFIELD,
        COLLECTION_USER
    };

    bool m_bDisableWelding;
    hkEnumF<CollectionType, hkUint8> m_eCollectionType;

    __forceinline hkpShapeCollectionF(FinishingFlag flag) : hkpShapeF(flag), m_eCollectionType(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = COLLECTION_USER;
        }
    }
};
enum MaterialIndexStridingType
{
    MATERIAL_INDICES_INVALID,
    MATERIAL_INDICES_INT8,
    MATERIAL_INDICES_INT16
};
struct Subpart
{
    hkEnumF<int, hkInt8> m_type;
    hkEnumF<MaterialIndexStridingType, hkInt8> m_iMaterialIndexType;
    short m_iIndexStriding;
    int m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    int m_pIndexBase;
    unsigned int m_ulUserData;

    __forceinline Subpart(FinishingFlag flag) : m_type(flag), m_iMaterialIndexType(flag)
    {}
};
struct TrianglesSubpart : public Subpart
{
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    hkVector4 m_kVertexTransform;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;

    __forceinline TrianglesSubpart(FinishingFlag flag) : Subpart(flag)
    {}
};
struct ArrayData
{
    unsigned int data;
    unsigned int size;
    unsigned int capacityAndFlags;
};
struct LoadResult
{
    ArrayData primary;
    ArrayData secondary;
    LoadResult()
    {
        primary.data = 0;
        primary.size = 0;
        primary.capacityAndFlags = 0x80000000;
        secondary.data = 0;
        secondary.size = 0;
        secondary.capacityAndFlags = 0x80000000;
    }
    ~LoadResult();
};
class hkMemoryAllocatorD47F
{
  public:
    virtual ~hkMemoryAllocatorD47F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD47F
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD47F* m_pStreamAllocator;
    hkMemoryAllocatorD47F& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD47F {
extern "C" hkMemoryRouterD47F& __cdecl FUN_00c85750() throw();
}
class hkStringPtrD47F
{
  public:
    const char* m_pcText;
    void FUN_00cb0c00() throw();
    ~hkStringPtrD47F()
    {
        FUN_00cb0c00();
    }
};
template <class T> class hkRefPtrD47F
{
  public:
    T* m_pRetainedObject;
    ~hkRefPtrD47F()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};
namespace hkArrayUtilD47F {
template <class T> __forceinline void destruct(T* t, int numElements)
{
    for (int i = 0; i < numElements; i++)
        t[i].~T();
}
}
template <class T> class hkArrayD47F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorD47F& alloc)
    {
        hkArrayUtilD47F::destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }

    ~hkArrayD47F()
    {
        _clearAndDeallocate(hkRouterD47F::FUN_00c85750().heap());
    }

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterD47F::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    hkArrayD47F* Destroy(unsigned int uiFlags);
};
// sub ecx,0x10; jmp FUN_00d57120
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x10 = vptr + three int fields).
struct PrimaryBase
{
    virtual void FUN_00d57110();
    int unk04;
    int unk08;
    int unk0C;
};
struct SecondaryBase
{
    virtual void FUN_00d57110();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d57110
    virtual void FUN_00d57110();
};
Derived::Derived()
{}
struct VectorS
{
    __m128 m_vComponents;
    VectorS(const VectorS& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct S
{
    char pad[2];
    char val;
};
volatile S* g_dst;
volatile S* g_src;
volatile int g_b;
volatile int g_c;
class hkStringPtr
{
  public:
    const char* m_pcText;

    void operator=(const char* pcString) throw();
};
class FUN_00cb0a60 : public hkStringPtr
{
  public:
    FUN_00cb0a60() throw();
    using hkStringPtr::operator=;
};
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};
class RefPtrD482
{
  public:
    hkReferencedObject* m_pRetainedObject;

    RefPtrD482() throw()
    {}
    RefPtrD482(hkReferencedObject* pkObject) throw() : m_pRetainedObject(pkObject)
    {}
    ~RefPtrD482() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
    void operator=(const RefPtrD482& rp) throw()
    {
        if (this != &rp)
        {
            hkReferencedObject* pkNew = rp.m_pRetainedObject;
            if (pkNew)
                ((FUN_00c90510_Obj*)pkNew)->FUN_00c90510();
            if (m_pRetainedObject)
                m_pRetainedObject->removeReference();
            m_pRetainedObject = pkNew;
        }
    }
    FUN_00d46d40_s* FUN_00d477a0() const throw();
    void AssignObject(int iParam) throw();
};
namespace SpringSimd {
union __declspec(intrin_type) __m128
{
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } lanes;
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float*, __m128);
}
struct S_00d4f0f0_B1
{
    virtual void v0();
    short unk04;
    short unk06;
    __forceinline S_00d4f0f0_B1()
    {
        unk06 = 1;
    }
};
struct S_00d4f0f0_B2 : S_00d4f0f0_B1
{
    int unk08;
    int unk0c;
    __forceinline S_00d4f0f0_B2()
    {
        unk08 = 0;
    }
};
struct S_00d4f0f0_H
{
    short unk10;
    __forceinline S_00d4f0f0_H() : unk10(3)
    {}
};
struct S_00d4f0f0_S
{
    short unk40;
    __forceinline S_00d4f0f0_S() : unk40(6)
    {}
};
namespace D4F2A0Simd {
union __declspec(intrin_type) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float*, __m128);
}
struct __declspec(align(16)) D4F2A0Vector
{
    float x, y, z, w;
};
struct hkBaseObjectS
{
    virtual void unk00();
};
struct hkReferencedObjectS : hkBaseObjectS
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObjectS() : m_sReferenceCount(1)
    {}
};
struct hkpConstraintDataS : hkReferencedObjectS
{
    unsigned int m_ulUserData;
    hkpConstraintDataS() : m_ulUserData(0)
    {}
};
inline void setZero4(D4F2A0Vector& v)
{
    D4F2A0Simd::_mm_store_ps(&v.x, D4F2A0Simd::_mm_setzero_ps());
}
struct hkRotationS
{
    D4F2A0Vector m_kColumn0;
    D4F2A0Vector m_kColumn1;
    D4F2A0Vector m_kColumn2;
    void setIdentity()
    {
        setZero4(m_kColumn0);
        setZero4(m_kColumn1);
        setZero4(m_kColumn2);
        m_kColumn0.x = 1.0f;
        m_kColumn1.y = 1.0f;
        m_kColumn2.z = 1.0f;
    }
};
struct hkpSetLocalRotationsAtomS
{
    unsigned short m_type;
    hkRotationS m_kRotationA;
    hkRotationS m_kRotationB;
    hkpSetLocalRotationsAtomS()
    {
        m_type = 4;
    }
};
struct hkpTwistLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucTwistAxis;
    unsigned char m_ucReferenceAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpTwistLimitAtomS()
    {
        m_type = 0xf;
        m_bLimitEnabled = 1;
    }
};
struct hkpConeLimitAtomS
{
    unsigned short m_type;
    unsigned char m_bLimitEnabled;
    unsigned char m_ucMemOffsetToAngleOffset;
    unsigned char m_ucMemOffsetToOldAngleOffset;
    unsigned char m_ucMemOffsetToFirstConstrainedDof;
    unsigned char m_ucAngleMeasurementMode;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
    hkpConeLimitAtomS()
    {
        m_type = 0x10;
        m_bLimitEnabled = 1;
        m_ucAngleMeasurementMode = 0;
    }
};
struct hkpRagdollAtomsS
{
    hkpSetLocalRotationsAtomS m_kLocalRotations;
    hkpTwistLimitAtomS m_kTwistLimit;
    hkpConeLimitAtomS m_kConeLimit;
    hkpConeLimitAtomS m_kPlaneLimit;
    hkpRagdollAtomsS()
    {}
};
namespace HingeLimitsD52FC0Detail {
struct Matrix
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    __forceinline void setZero()
    {
        ::D4F2A0Simd::_mm_store_ps(&m00, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m10, ::D4F2A0Simd::_mm_setzero_ps());
        ::D4F2A0Simd::_mm_store_ps(&m20, ::D4F2A0Simd::_mm_setzero_ps());
    }
    __forceinline void setDiagonal(float x, float y, float z)
    {
        setZero();
        m00 = x;
        m11 = y;
        m22 = z;
    }
    __forceinline void setIdentity()
    {
        setDiagonal(1.0f, 1.0f, 1.0f);
    }
};
}
extern "C" ::D4F2A0Simd::__m128 _mm_setr_ps(float x, float y, float z, float w);
static const float DAT_010181bc = 0.05f;
static const float DAT_01011d78 = 0.0f;
static const float DAT_01017870 = 0.3f;
static const float DAT_010231a8 = 0.4f;
static const float DAT_0101e2bc = 0.1f;
static inline char& MoppInputSetBool(char& rcBool, bool b)
{
    rcBool = static_cast<char>(b);
    return rcBool;
}

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
}
}

struct RecordVector
{
    union
    {
        N::__m128 quad;
        float component[4];
    };
    __forceinline void set(float x, float y, float z, float w)
    {
        quad = N::_mm_setr_ps(x, y, z, w);
    }
    __forceinline RecordVector()
    {}
    __forceinline RecordVector(const RecordVector& other)
    {
        quad = other.quad;
    }
    __forceinline void operator=(const RecordVector& other)
    {
        quad = other.quad;
    }
};

template <class T> __forceinline void CopyItems(T* destination, int count, const T& item)
{
    for (int i = 0; i < count; ++i)
        destination[i] = item;
}
template <class T> struct RecordQueue
{
    T* data;
    int count;
    int capacity;
    __forceinline int GetLogicalSize() const
    {
        return count;
    }
    __forceinline void AddBack(const T& item)
    {
        AllocHolder* arena = FUN_00c85750();
        if (count == (capacity & 0x3fffffff))
            ResizeAudioStream(arena->m_pAllocator, this, sizeof(T));
        CopyItems(data + count, 1, item);
        ++count;
    }
};

extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
}
extern "C" void _ReadWriteBarrier();
struct Scalar380
{
    __m128 value;
    Scalar380(float scalar)
    {
        value = _mm_load_ss(&scalar);
    }
    __m128 Broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct Vector380
{
    __m128 value;
    void SetSub(const Vector380& a, const Vector380& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    void SetAdd(const Vector380& a, const Vector380& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    void Multiply(const Scalar380& scalar)
    {
        value = _mm_mul_ps(scalar.Broadcast(), value);
    }
};
struct ConvexBase380
{
    const void** vtable;
    unsigned short memorySize, references;
    unsigned int userData, shapeType;
    float radius;
    ConvexBase380(float r) : userData(0), shapeType(6), radius(r)
    {}
};
template <class T> struct Array380
{
    T* data;
    int size;
    unsigned int capacityAndFlags;
    Array380(T* p, int n) : data(p), size(n), capacityAndFlags((unsigned int)n | 0x80000000u)
    {}
};
struct TransposedPoints380
{
    Vector380 x, y, z;
};
struct PointArray380
{
    TransposedPoints380* data;
    int size;
    unsigned int capacityAndFlags;
    PointArray380(TransposedPoints380* p, int n)
    {
        data = p;
        size = ((n + 3) & ~3) / 4;
        capacityAndFlags = (unsigned int)size | 0x80000000u;
    }
};

namespace AngularFrictionIntrinsics {
extern "C" ::D4F2A0Simd::__m128 _mm_setr_ps(float, float, float, float);
extern "C" ::D4F2A0Simd::__m128 _mm_load_ps(const float*);
}

struct AngularFrictionRecord : ::D4F2A0Vector
{
    AngularFrictionRecord()
    {}
    AngularFrictionRecord(const AngularFrictionRecord& other)
    {
        ::D4F2A0Simd::_mm_store_ps(&x, AngularFrictionIntrinsics::_mm_load_ps(&other.x));
    }
};

struct AngularFrictionBudget
{
    int unk00;
    int counter04;
    int counter08;
    int counter0c;
    void add(int bytes, int count, int results)
    {
        counter04 += bytes;
        counter08 += count;
        counter0c += results;
    }
};

namespace MoppBuildSimd {
extern "C" ::D4F2A0Simd::__m128 _mm_load_ps(const float*);
extern "C" ::D4F2A0Simd::__m128(_mm_setr_ps)(float, float, float, float);
}

typedef ::D4F2A0Vector hkQuadReal;

struct FUN_00dd5150_Class
{
    float f0, f1, f2, f3, f4, f5;
    FUN_00dd5150_Class(int);
};

struct FUN_00dd50f0_Class
{
    float m_00;
    int m_04, m_08, m_0c, m_10;
    bool m_14;
    FUN_00dd50f0_Class(int);
};

struct Sub3
{
    float f0;
    float f1;
    float f2;
    hkQuadReal v;
    int i20;
    bool b24;

    __forceinline Sub3() : f0(0.5f), f1(0.2f), f2(1.0f), i20(5), b24(true)
    {
        __declspec(align(16))::D4F2A0Simd::__m128 q = MoppBuildSimd::_mm_setr_ps(0.2f, 0.2f, 0.05f, 0.0f);
        v = *reinterpret_cast<const hkQuadReal*>(&q);
    }
};

struct FUN_00d549d0_Class
{
    int m_00;
    int* m_arr1_data;
    int m_arr1_size;
    int m_arr1_capacity;
    int* m_arr2_data;
    int m_arr2_size;
    int m_arr2_capacity;
    int m_1c;
    int m_20;

    void ClearArrays();
};

struct FUN_00dd4bf0_Class
{
    int m_unk00;
    void* m_ptr4;
    FUN_00dd50f0_Class m_sub1;
    FUN_00dd5150_Class m_sub2;
    int m_unk38;
    int m_unk3c;
    Sub3 m_sub3;

    FUN_00dd4bf0_Class(int);
    void SetValues(const FUN_00dd5150_Class*);
    void CopyFromSourceData(const Sub3*);
    void AssignFromSource(const FUN_00dd50f0_Class*);
    int ComputeRequiredSize(void*);
    void* FUN_00dd4cb0(void*, void*, int);
    void FUN_00dd4b00();
};

struct Arg2Struct
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;

    float FUN_00d54db0();
    float FUN_00d54dd0();
    float FUN_00d54d70();
    hkQuadReal* GetValue(hkQuadReal* out);
};

class MyHkError : public ::hkErrorD53
{
  public:
    virtual void SetErrorCodeEnabled(int id, ::hkBool enable);
    virtual ::hkBool isEnabled(int id);
};

__forceinline void DisableSub2Tail(FUN_00dd5150_Class& sub2, ::hkBool bNoFirst, const Arg2Struct* arg2)
{
    if (bNoFirst || arg2->m_1e)
    {
        sub2.f4 = 0.0f;
    }
}

struct SearchCall_d54a40
{
    int Search(unsigned int, unsigned int, unsigned int, unsigned int);
};

__forceinline void ReportResults(::SearchObject* s3, int* data, int size)
{
    ::AllocHolder* alloc = FUN_00c85750();
    ((SearchCall_d54a40*)s3)->Search((unsigned int)alloc->m_pAllocator, 0, (unsigned int)data, size);
}

__forceinline MyHkError& GetHkError()
{
    return *(MyHkError*)DAT_01268360;
}

// @f3 0x009e24a0 (community match, verified in this file)
namespace f3m_009e24a0 {
struct SettingsVector { float x, y, z, w; };
struct Sub3 {
    float f0, f1, f2;
    __declspec(align(16)) SettingsVector v;
    int i20;
    bool b24;
    __forceinline Sub3() : f0(0.5f), f1(0.2f), f2(1.0f), i20(5), b24(true) {
        v.x = 0.2f; v.y = 0.2f; v.z = 0.05f; v.w = 0.0f;
    }
};
}
struct NativeStackArena {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void* AllocateOverflow(unsigned int size);
    virtual void FreeOverflow(void* pointer);
    unsigned char unknown04[0x1c];
    unsigned char* current;
    unsigned char* unknown24;
    unsigned char* overflow;
    unsigned char* limit;
    void* Allocate(int size);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
static __forceinline NativeStackArena* CurrentStackArena() {
    return static_cast<NativeStackArena*>(TlsGetValue(DAT_010f3170));
}

__forceinline void* NativeStackArena::Allocate(int size) {
    const unsigned int bytes = (size + 16) & ~15u;
    unsigned char* result = current;
    unsigned char* next = result + bytes;
    if (next <= limit) {
        current = next;
        return result;
    }
    return AllocateOverflow(bytes);
}
namespace f3m_009e24a0 {
class hkB {
public:
    char m_cBooleanValue;
    __forceinline hkB(bool value) : m_cBooleanValue(static_cast<char>(value)) {}
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
class ErrIface {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int type, int id, const char* description, const char* file, int line);
    virtual void SetErrorCodeEnabled(int id, hkB enabled);
    virtual hkB isEnabled(int id);
};
extern ErrIface* DAT_010f3364;
struct SearchIface { int FUN_009e2360(int flags, int* data, int size); };
}
static __forceinline f3m_009e24a0::ErrIface& NativeError() { return *f3m_009e24a0::DAT_010f3364; }
static __forceinline bool BoolValue(f3m_009e24a0::hkB value) { return value; }
static __forceinline void ConfigureTail(FUN_00dd5150_Class& settings, f3m_009e24a0::hkB noFirst, const Arg2Struct* input) {
    if (noFirst || BoolValue(input->m_1e == 1))
        settings.f4 = 0.0f;
}
void* __cdecl FUN_00d54a40(void* arg0, void* arg1, Arg2Struct* arg2, ::SearchObject* arg3)
{
    void* buffer;
    bool flag17;

    FUN_00dd4bf0_Class big_obj(0);
    {
        FUN_00dd5150_Class sub2(0);
        sub2.f0 = 1.0f;
        ConfigureTail(sub2, arg2->m_1c == 0, arg2);
        big_obj.SetValues(&sub2);
    }

    flag17 = arg2->m_1f != 0;
    if (arg2->m_1e)
    {
        flag17 = false;
    }

    {
        f3m_009e24a0::Sub3 sub3;
        sub3.f0 = arg2->FUN_00d54db0();
        sub3.f1 = arg2->FUN_00d54dd0();
        sub3.f2 = arg2->FUN_00d54d70();
        hkQuadReal tmp;
        const hkQuadReal* value = arg2->GetValue(&tmp);
        sub3.v.x = value->x;
        sub3.v.y = value->y;
        sub3.v.z = value->z;
        sub3.v.w = value->w;
        sub3.b24 = flag17;
        big_obj.CopyFromSourceData(reinterpret_cast<const ::Sub3*>(&sub3));
    }

    {
        FUN_00dd50f0_Class sub1(0);
        if (arg2->m_1d)
        {
            sub1.m_08 = 0x32;
        }
        else
        {
            sub1.m_04 = 0;
            sub1.m_08 = 0;
        }
        sub1.m_0c = 5;
        sub1.m_14 = flag17;
        big_obj.AssignFromSource(&sub1);
    }

    int size = big_obj.ComputeRequiredSize(arg0);
    buffer = CurrentStackArena()->Allocate(size);
    FUN_00d549d0_Class struct4c;
    struct4c.m_00 = 0x200;
    struct4c.m_arr1_data = 0;
    struct4c.m_arr1_size = 0;
    struct4c.m_arr1_capacity = 0x80000000;
    struct4c.m_arr2_data = 0;
    struct4c.m_arr2_size = 0;
    struct4c.m_arr2_capacity = 0x80000000;
    struct4c.m_1c = 0;
    struct4c.m_20 = 0x14;

    if (arg2->m_1e)
    {
        big_obj.m_ptr4 = &struct4c;
    }

    f3m_009e24a0::hkB prevWarning = f3m_009e24a0::DAT_010f3364->isEnabled(0x7dd65995);
    NativeError().SetErrorCodeEnabled(0x7dd65995, false);

    void* retVal = big_obj.FUN_00dd4cb0(arg0, buffer, size);

    f3m_009e24a0::DAT_010f3364->SetErrorCodeEnabled(0x7dd65995, prevWarning);

    f3m_009e24a0::SearchIface* s3 = reinterpret_cast<f3m_009e24a0::SearchIface*>(arg3);
    if (s3 != 0)
    {
        s3->FUN_009e2360(0, struct4c.m_arr1_data, struct4c.m_arr1_size);
    }

    NativeStackArena* releaseArena = CurrentStackArena();
    releaseArena->current = static_cast<unsigned char*>(buffer);
    if (buffer == releaseArena->overflow)
        releaseArena->FreeOverflow(buffer);

    struct4c.ClearArrays();
    big_obj.FUN_00dd4b00();

    return retVal;
}

