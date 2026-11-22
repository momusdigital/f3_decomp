// NiFixedString: a handle to a string in the NiGlobalStringTable; copying shares the string and counts references.
// Names: FNV360_PDB (NiFixedString, 0822 debug: the constructors, destructor, operator=, operator const char*,
// Exists and the operator== overloads are inline in nifixedstring.inl). F3 keeps out-of-line copies of the
// const char* constructor (0x00422920) and the copy constructor (0x00458950) where the compiler did not inline them.
#ifndef FNV_NIFIXEDSTRING_H
#define FNV_NIFIXEDSTRING_H
#include "layout_support.h"
#include "NiGlobalStringTable.h"
#pragma pack(push, 4)
class NiFixedString
{
  public:
    NiFixedString()
    {
        m_kHandle = NiGlobalStringTable::NULL_STRING;
    }
    NiFixedString(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = NiGlobalStringTable::NULL_STRING;
        else
            m_kHandle = NiGlobalStringTable::AddString(pcString);
    }
    NiFixedString(const NiFixedString& kString)
    {
        NiGlobalStringTable::IncRefCount((NiGlobalStringTable::GlobalStringHandle&)kString.m_kHandle);
        m_kHandle = kString.m_kHandle;
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    operator const char*() const
    {
        return NiGlobalStringTable::GetString(m_kHandle);
    }
    NiFixedString& operator=(const NiFixedString& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            NiGlobalStringTable::GlobalStringHandle kHandle = kString.m_kHandle;
            NiGlobalStringTable::IncRefCount(kHandle);
            NiGlobalStringTable::DecRefCount(m_kHandle);
            m_kHandle = kHandle;
        }
        return *this;
    }
    NiFixedString& operator=(const char* pcString)
    {
        if (m_kHandle != pcString)
        {
            NiGlobalStringTable::GlobalStringHandle kHandle = m_kHandle;
            m_kHandle = NiGlobalStringTable::AddString(pcString);
            NiGlobalStringTable::DecRefCount(kHandle);
        }
        return *this;
    }
    bool Exists() const
    {
        return m_kHandle != NiGlobalStringTable::NULL_STRING;
    }

    NiGlobalStringTable::GlobalStringHandle m_kHandle;  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFixedString) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiFixedString, m_kHandle) == 0x0);

inline bool operator==(const NiFixedString& s1, const NiFixedString& s2)
{
    return s1.m_kHandle == s2.m_kHandle;
}
inline bool operator!=(const NiFixedString& s1, const NiFixedString& s2)
{
    return s1.m_kHandle != s2.m_kHandle;
}
#endif
