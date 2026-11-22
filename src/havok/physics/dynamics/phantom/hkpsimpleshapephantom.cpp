#include "f3_common.h"
// src/havok/physics/dynamics/phantom/hkpsimpleshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpsimpleshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSimpleShapePhantom.h"

// @fnv 0x00d1f220
// pdb: hkpSphereShape::getNumCollisionSpheresImpl | hkpSphereShape.obj | fnv360_0822_retail, objrun_open, low
int FUN_00d1f220()
{
    return 1;
}

struct ShapeDetail
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int key;
};
typedef __declspec(align(16)) ShapeDetail* AlignedShapePtr;
struct DetailLess
{
    bool operator()(ShapeDetail* const& a, ShapeDetail* const& b) const
    {
        return a->key < b->key;
    }
};

struct hkBoolXd1f230
{
    char m_cBooleanValue;
    hkBoolXd1f230(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

template <class T> class hkArrayXd1f230
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct hkBoolD1F5
{
    char m_cBooleanValue;
    hkBoolD1F5(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkpShapeD1F5;

struct hkpCollidableD1F5
{
    const hkpShapeD1F5* m_pCollisionShape;

    const hkpShapeD1F5* getShape() const
    {
        return m_pCollisionShape;
    }
};

template <class T> class hkArrayD1F5
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
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct hkpSimpleShapePhantomCollisionDetailD1F5
{
    hkpCollidableD1F5* m_kCollidable;
};

class FUN_00ca9520_class : public hkpShapePhantom
{
  public:
    void NotifyAll(hkpCollidableD1F5* pkCollidable, hkBoolD1F5 bCollidableWasAdded) throw();
};

class hkpSimpleShapePhantomD1F5 : public FUN_00ca9520_class
{
  public:
    hkArrayD1F5<hkpSimpleShapePhantomCollisionDetailD1F5> m_kCollisionDetails;
    hkBoolD1F5 m_bOrderDirty;

    void FUN_00d1f5a0(hkpCollidableD1F5* pkCollidable) throw();
};

// @f3 0x0099e780 (community match, verified in this file)
// pdb: hkpSimpleShapePhantom::removeOverlappingCollidable | hkpSimpleShapePhantom.obj | fnv360_0822_retail, objopen_prop, medium
// pdb params: collidable
void hkpSimpleShapePhantomD1F5::FUN_00d1f5a0(hkpCollidableD1F5* pkCollidable) throw()
{
    char* self = reinterpret_cast<char*>(this);
    if (pkCollidable->getShape() != 0)
    {
        int i = *reinterpret_cast<int*>(self + 0x154) - 1;
        for (; i >= 0; i--)
        {
            hkpCollidableD1F5** data = *reinterpret_cast<hkpCollidableD1F5***>(self + 0x150);
            if (data[i] == pkCollidable)
            {
                NotifyAll(pkCollidable, true);
                int* count = reinterpret_cast<int*>(self + 0x154);
                *count = *count - 1;
                int last = *count;
                hkpCollidableD1F5** d2 = *reinterpret_cast<hkpCollidableD1F5***>(self + 0x150);
                d2[i] = d2[last];
                return;
            }
        }
        NotifyAll(pkCollidable, false);
    }
}


class hkClassD1F6;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayD1F6
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

class hkStatisticsCollectorD1F6
{
  public:
    virtual ~hkStatisticsCollectorD1F6() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayD1F6<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkOverlapD1F6;

class hkpShapeD1F6
{
  public:
    void WritePhantomLists(hkStatisticsCollectorD1F6* pkCollector, const hkClassD1F6* pkClass) const throw();
};

class hkObjD1F6 : public hkpShapeD1F6
{
  public:
    int unk000;
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
    hkArrayD1F6<hkOverlapD1F6*> m_overlaps;

    void CollectStatistics(hkStatisticsCollectorD1F6* pkCollector, const hkClassD1F6* pkClass) const throw();
};

struct CollisionMemoryRouter
{
    int unk00, unk04, unk08, unk0c;
    void* allocator;
};
extern "C" CollisionMemoryRouter* __cdecl FUN_00c85750();

namespace fnv_00d1f6f0 {

struct hkObjD1F6
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
    void** m_160;
    int m_164;
    int m_168;
    char m_16c;
    void SortAndClearFlag();
};

}  // namespace fnv_00d1f6f0

namespace fnv_00d1f7e0 {
class hkMemoryAllocatorD1F7
{
  public:
    virtual ~hkMemoryAllocatorD1F7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> T* _bufAlloc(int& iReqNumInOut)
    {
        int n = iReqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        iReqNumInOut = n / (int)sizeof(T);
        return (T*)p;
    }
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD1F7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD1F7* m_pStreamAllocator;
    hkMemoryAllocatorD1F7& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD1F7& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD1F7(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayD1F7
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

    __forceinline void operator=(const hkArrayD1F7& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocatorD1F7& kAlloc, const hkArrayD1F7& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyD1F7(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4D1F7
{
    hkReal x, y, z, w;
};

struct hkTransformD1F7
{
    hkVector4D1F7 m_kColumn0;
    hkVector4D1F7 m_kColumn1;
    hkVector4D1F7 m_kColumn2;
    hkVector4D1F7 m_vTranslation;
};

class hkpShapeD1F7;
class hkpPhantomOverlapListenerD1F7;
class hkpPhantomListenerD1F7;

struct hkpCollidableD1F7
{
    const hkpShapeD1F7* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeD1F7* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectD1F7
{
  public:
    virtual ~hkpWorldObjectD1F7() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableD1F7 m_kCollidable;

    const hkpCollidableD1F7* getCollidable() const
    {
        return &m_kCollidable;
    }
    void CopyEntriesFrom(const hkpWorldObjectD1F7* pkOtherObj) throw();
};

class FUN_00d1f730 : public hkpWorldObjectD1F7
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObjectD1F7* p = (hkpWorldObjectD1F7*)FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayD1F7<hkpPhantomOverlapListenerD1F7*> m_kPhantomOverlapListeners;
    hkArrayD1F7<hkpPhantomListenerD1F7*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkTransformD1F7 m_kMotionTransform;
    char m_padF0[0x80];

    const hkTransformD1F7& getTransform() const
    {
        return m_kMotionTransform;
    }

    FUN_00d1f730(const hkpShapeD1F7* pkShape, const hkTransformD1F7& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectD1F7* ClonePhantom() const throw();
};

typedef char fnv_check_d1f7e0[(sizeof(FUN_00d1f730) == 0x170) ? 1 : -1];

}  // namespace fnv_00d1f7e0

struct hkpShapeD1F
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int m_type;
};
struct hkpCdBodyD1F
{
    const hkpShapeD1F* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD1F* m_parent;
};
struct hkpCollisionInputD1F;
template <class T> class hkArrayD1F
{
  public:
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
typedef void(__cdecl* AgentFuncD1F)(const hkpCdBodyD1F& bodyA, const hkpCdBodyD1F& bodyB,
                                    const hkpCollisionInputD1F& input, void* collector);
struct AgentFuncsD1F
{
    AgentFuncD1F m_func;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct hkpCollisionDispatcherD1F
{
    int unk000;
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
    unsigned char m_agentTypes[32][32];
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
    int unk99C;
    int unk9A0;
    int unk9A4;
    AgentFuncsD1F m_agentFuncs[32];
};
struct hkpCollisionInputD1F
{
    hkpCollisionDispatcherD1F* m_pCollisionDispatcher;
};
struct WorldD1F
{
    int unk000;
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
    hkpCollisionInputD1F* m_collisionInput;  // +0x6C (the Fallout 3 hkpWorld's)
    int unk070;
    int unk074;
    hkpCollisionInputD1F* m_pCollisionInput;
};
// hkpSimpleShapePhantom, at its Fallout 3 offsets: the collision details array at +0x150.
class PhantomD1F
{
  public:
    int unk000;
    int unk004;
    WorldD1F* m_pOwningWorld;
    int unk00C;
    hkpCdBodyD1F m_kCollisionBody;
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
    hkArrayD1F<hkpCdBodyD1F*> m_collisionDetails;  // +0x150
    void DispatchOverlaps(void* collector, const hkpCollisionInputD1F* input);
};
// @f3 0x0099e7f0 (community match, verified in this file)
// pdb: hkpSimpleShapePhantom::getClosestPoints | hkpSimpleShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collector, input
void PhantomD1F::DispatchOverlaps(void* collector, const hkpCollisionInputD1F* apCollisionInput)
{
    if (!apCollisionInput)
        apCollisionInput = m_pOwningWorld->m_collisionInput;
    hkpCollisionDispatcherD1F* dispatcher = apCollisionInput->m_pCollisionDispatcher;
    hkArrayD1F<hkpCdBodyD1F*>& overlaps = m_collisionDetails;
    for (int i = overlaps.GetLogicalSize() - 1; i >= 0; i--)
    {
        hkpCdBodyD1F*& pOtherBody = overlaps[i];
        AgentFuncD1F pAgentFunc =
            dispatcher
                ->m_agentFuncs[dispatcher->m_agentTypes[m_kCollisionBody.m_pCollisionShape->m_type]
                                                       [pOtherBody->m_pCollisionShape->m_type]]
                .m_func;
        pAgentFunc(m_kCollisionBody, *pOtherBody, *apCollisionInput, collector);
    }
}


class hkpShape : public hkReferencedObject
{
  public:
    hkUlong m_ulUserData;
    int m_type;
};
class hkpSimpleShapePhantomCollisionDetail
{
  public:
    hkpCollidable* m_kCollidable;
};
struct FUN_00d1f520_Input;
struct FUN_00d1f520_Collector
{
    int unk00;
    hkBool m_fHitDistance;
};
typedef void(__cdecl* FUN_00d1f520_GetPenetrationsFunc)(const hkpCdBody& a, const hkpCdBody& b,
                                                        const FUN_00d1f520_Input& input,
                                                        FUN_00d1f520_Collector& collector);
struct FUN_00d1f520_AgentFuncs
{
    void* m_pCreateFunc;
    FUN_00d1f520_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};
struct FUN_00d1f520_Dispatcher
{
    int unk000;
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
    hkUint8 m_agent2TypeMap[32][32];
    hkUint8 m_agent3TypeMap[32][32];
    FUN_00d1f520_AgentFuncs m_agent2Funcs[1];
};
struct FUN_00d1f520_Input
{
    FUN_00d1f520_Dispatcher* m_pCollisionDispatcher;
};
struct FUN_00d1f520_Phantom : public hkpSimpleShapePhantom
{
    void QueryPenetrations(FUN_00d1f520_Collector& collector, const FUN_00d1f520_Input* input);
};
// Iterates collision details and calls the dispatcher's agent2 penetration query function, breaking early when the collector reports a hit distance.
// @f3 0x0099e870 (community match, verified in this file)
// pdb: hkpSimpleShapePhantom::getPenetrations | hkpSimpleShapePhantom.obj | fnv360_0822_retail, objrun_open, low
// pdb params: collector, input
void FUN_00d1f520_Phantom::QueryPenetrations(FUN_00d1f520_Collector& collector, const FUN_00d1f520_Input* input)
{
    if (!input)
        input = *reinterpret_cast<FUN_00d1f520_Input**>(
            reinterpret_cast<char*>(m_pOwningWorld) + 0x6C);

    FUN_00d1f520_Dispatcher* dispatcher = input->m_pCollisionDispatcher;

    hkArray<hkpSimpleShapePhantomCollisionDetail>* details =
        reinterpret_cast<hkArray<hkpSimpleShapePhantomCollisionDetail>*>(
            reinterpret_cast<char*>(this) + 0x150);

    for (int i = details->m_iElementCount - 1; i >= 0; i--)
    {
        hkpSimpleShapePhantomCollisionDetail* detail = details->m_data + i;

        int shapeType = m_kCollidable.m_pCollisionShape->m_type;
        int detailShapeType = detail->m_kCollidable->m_pCollisionShape->m_type;

        dispatcher->m_agent2Funcs[
            dispatcher->m_agent2TypeMap[shapeType][detailShapeType]
        ].m_pQueryPenetrationsFunc(
            m_kCollidable,
            *detail->m_kCollidable,
            *input,
            collector);

        if (collector.m_fHitDistance)
            break;
    }
}


#include <xmmintrin.h>

namespace fnv_00d1f960 {
// @fnv 0x00d1f960
struct Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void*, unsigned);
};
struct Router
{
    void* a;
    void* b;
    void* c;
    void* d;
    Alloc* heap;
    Alloc& getHeap()
    {
        return *heap;
    }
};
Router* FUN_00c85750();
}  // namespace fnv_00d1f960
