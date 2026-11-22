#include "f3_common.h"
// src/havok/common/scenedata/mesh/hkxvertexdescription.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexdescription.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxVertexDescription.h"

struct hkEntryE3DE
{
    int m_iOwnerObjectOffset;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    int m_uiFilterValue;

    bool operator==(const hkEntryE3DE& o) const
    {
        return m_kPointA == o.m_kPointA && m_kPointB == o.m_kPointB && m_iOwnerObjectOffset == o.m_iOwnerObjectOffset &&
               m_uiFilterValue == o.m_uiFilterValue;
    }
};

class hkListE3DE
{
  public:
    hkEntryE3DE* m_data;
    int m_iElementCount;

    bool Equals(const hkListE3DE& o) const;
};

// Compares two lists: returns false if their counts differ or any corresponding entry differs, otherwise true.
// @f3 0x00421880 (community match, verified in this file)
struct ListTagSub21880
{
    void* vtbl;
    void** m_data;
    unsigned int m_size;

    __declspec(noinline) bool FUN_004216e0(const ListTagSub21880* o) const
    {
        if (o->m_size != m_size) return false;
        for (unsigned int i = 0; i < m_size; ++i) {
            if (m_data[i] != o->m_data[i]) return false;
        }
        return true;
    }
};

struct ListEntryView
{
    unsigned char m_tag[4];
    ListTagSub21880 sub;
    bool operator==(const ListEntryView& other) const
    {
        return m_tag[0] == other.m_tag[0] && m_tag[1] == other.m_tag[1] && m_tag[2] == other.m_tag[2] && m_tag[3] == other.m_tag[3] && sub.FUN_004216e0(&other.sub);
    }
};

class ListLayoutE3DE
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_w0C;
    unsigned short m_w0E;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    ListEntryView** m_data;
    unsigned int m_iElementCount;

};

// pdb: ExtraDismemberedLimbs::CheckDismemberedLimbsIdentical | ExtraDataObjects.obj | fnv360_0822_retail, call_gap, low
// pdb params: apDismemberedLimbs
bool hkListE3DE::Equals(const hkListE3DE& other) const
{
    const ListLayoutE3DE* self = reinterpret_cast<const ListLayoutE3DE*>(this);
    const ListLayoutE3DE* rhs = reinterpret_cast<const ListLayoutE3DE*>(&other);
    if (rhs->m_w0C != self->m_w0C)
        return false;
    unsigned int count = self->m_iElementCount;
    if (rhs->m_iElementCount != count)
        return false;
    for (unsigned int i = 0; i < count; ++i)
    {
        ListEntryView* left = self->m_data[i];
        ListEntryView* right = rhs->m_data[i];
        if (left->m_tag[0] != right->m_tag[0] ||
            left->m_tag[1] != right->m_tag[1] ||
            left->m_tag[2] != right->m_tag[2] ||
            left->m_tag[3] != right->m_tag[3])
            return false;
        if (!left->sub.FUN_004216e0(&right->sub))
            return false;
    }
    return true;
}

