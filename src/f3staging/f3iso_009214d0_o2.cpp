#include <new>
// src/f3staging/f3iso_009214d0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x009214d0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x009214d0 (community match, verified in this file)
namespace f3m_009214d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

namespace S9214d0_ {

typedef float hkReal;

class __declspec(align(16)) hkVector4
{
  public:
    hkReal x, y, z, w;
};

class hkStepInfo;
class hkpCollidable;
struct hkpCdPoint;

struct hkContactPoint
{
    hkVector4 m_position;
    hkVector4 m_separatingNormal;
};

struct hkpRootCdPoint
{
    hkContactPoint m_contact;
    const hkpCollidable* m_rootCollidableA;
    unsigned int m_shapeKeyA;
    const hkpCollidable* m_rootCollidableB;
    unsigned int m_shapeKeyB;
    unsigned int m_extraShapeKey1;
    unsigned int m_extraShapeKey2;
    unsigned int m_extraShapeKey3;
};
typedef char fnv_check_hkpRootCdPoint[(sizeof(hkpRootCdPoint) == 64) ? 1 : -1];

class hkThreadMemory
{
  public:
    void FUN_008f6d90(void* p, int nbytes, int cl) throw();
    static inline hkThreadMemory& getInstance();
};

template <typename T>
class hkThreadLocalData
{
  public:
    T getData() const { return (T)(unsigned long)TlsGetValue(m_slotID); }
    unsigned long m_slotID;
};

struct ThreadMemTls
{
    static hkThreadLocalData<hkThreadMemory*> DAT_010f3170;
};

inline hkThreadMemory& hkThreadMemory::getInstance()
{
    return *ThreadMemTls::DAT_010f3170.getData();
}

template <typename T>
class hkArray
{
  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };

    hkArray(T* ptr, int size, int capacity)
        : m_data(ptr), m_size(size), m_capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
    {
    }
    ~hkArray() { releaseMemory(); }

    int getCapacity() const { return m_capacityAndFlags & static_cast<int>(CAPACITY_MASK); }
    void clear() { m_size = 0; }
    void releaseMemory()
    {
        if ((m_capacityAndFlags & DONT_DEALLOCATE_FLAG) == 0)
            hkThreadMemory::getInstance().FUN_008f6d90(m_data, getCapacity() * sizeof(T), 0x17);
    }

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
  public:
    hkInplaceArray(int size = 0) : hkArray<T>(m_storage, size, N) {}
    T m_storage[N];
};

class hkpCdPointCollector
{
  public:
    inline hkpCdPointCollector() { reset(); }
    inline virtual ~hkpCdPointCollector() {}
    virtual void addCdPoint(const hkpCdPoint& point) = 0;
    virtual void addRootCdPoint(const hkpRootCdPoint&) = 0;
    inline void reset() { m_earlyOutDistance = 3.40282e+38f; }

  protected:
    hkReal m_earlyOutDistance;
};

class hkpAllCdPointCollector : public hkpCdPointCollector
{
  public:
    inline hkpAllCdPointCollector() { reset(); }
    inline virtual ~hkpAllCdPointCollector() {}
    inline void reset()
    {
        m_hits.clear();
        hkpCdPointCollector::reset();
    }

  protected:
    virtual void addCdPoint(const hkpCdPoint& point);
    virtual void addRootCdPoint(const hkpRootCdPoint&);

    hkInplaceArray<hkpRootCdPoint, 8> m_hits;
};

class hkpCharacterProxy
{
  public:
    void hkpCharacterProxy_integrateImplementation(const hkStepInfo& stepInfo, const hkVector4& gravity,
                      hkpAllCdPointCollector& castCollector,
                      hkpAllCdPointCollector& startPointCollector) throw();
    void FUN_009214d0(const hkStepInfo& stepInfo, const hkVector4& worldGravity);
};

// pdb: hkpCharacterProxy::integrate | hkpCharacterProxy.obj | tesv_win, caller_sim, low
void hkpCharacterProxy::FUN_009214d0(const hkStepInfo& stepInfo, const hkVector4& worldGravity)
{
    hkpAllCdPointCollector castCollector;
    hkpAllCdPointCollector startPointCollector;
    hkpCharacterProxy_integrateImplementation(stepInfo, worldGravity, castCollector, startPointCollector);
}

}
}   // namespace f3m_009214d0
