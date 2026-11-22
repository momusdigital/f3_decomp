// src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "f3_common.h"
// src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00d60000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
void __cdecl FUN_00d687c0(void);
// Constructor of the class whose vftables live at 0x010d1fb0 / 0x010d1f90 /
// 0x010d1f80 / 0x010d1f70: it calls the immediate base constructor and then
// installs the derived vftable pointers for the four base sub-objects.
struct FnvCpu_FUN_00d687c0_CpuBlock;
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(unsigned int value);
};
void* __cdecl FUN_00d687c0(unsigned int value);
// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.
// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
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
char* __cdecl FUN_00cb1130(char* pcHaystack, const char* pcNeedle);
inline char toLowerD614(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
int __cdecl FUN_00cb1130(int a1, int a2);
inline char toLowerD615(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
int __cdecl FUN_00cb0fa0(int, int);
int __cdecl hkString_strLen(int s);
int __cdecl hkString_strLen(const char* str);
static inline int tolower_custom(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        return c + 0x20;
    return c;
}
struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
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

    int ReplaceChar(char from, char to, int replaceType);
};
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
struct FnvCpu_FUN_00d645f0_CpuBlock;
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
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
// FUN_00d73400's body must be in-TU so VC9 knows it clobbers only eax:
// that is what lets the ctor keep `this` live in ECX across the call
// (matches orig: xor eax,eax; mov [ecx..0xc],eax; call; mov eax,ecx; ret).
class FUN_00d73410;
class FUN_00d73410
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    FUN_00d73410();
};
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
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;
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

extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
}
#include <math.h>

inline float Fwd(float x)
{
    return x;
}

// @f3 0x00a02b30 (community match, verified in this file)
static __declspec(noinline) float FUN_00d6b3c0(__m128* p, float a1, float a2)
{
    float* v = (float*)p;
    float lenSq = v[1] * v[1] + v[0] * v[0] + v[2] * v[2];
    float minSq = a1 * a1;
    float ratio = lenSq / minSq;
    if (lenSq > minSq)
    {
        float maxSq = a2 * a2;
        if (maxSq > lenSq)
        {
            float scale = Fwd(sqrtf(minSq / lenSq));
            v[0] = scale * v[0];
            v[1] = scale * v[1];
            v[2] = scale * v[2];
            v[3] = scale * v[3];
        }
        else
        {
            float scale = (a1 * a2) / lenSq;
            v[0] = scale * v[0];
            v[1] = scale * v[1];
            v[2] = scale * v[2];
            v[3] = scale * v[3];
        }
    }
    return ratio;
}


volatile __m128* g_vec;
volatile float g_a1, g_a2, g_sink;
void zz_caller(void)
{
    g_sink = FUN_00d6b3c0((__m128*)g_vec, g_a1, g_a2);
}
