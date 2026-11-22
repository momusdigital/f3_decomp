#include <new>
// src/f3staging/f3iso_00bbc5b0_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x00bbc5b0 alone: its served file contradicted the
// function (declarations, stand-in bodies, pragmas). Write your own types and helpers in the candidate. Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00bbc5b0 (community match, verified in this file)
#include <vector>
#include <algorithm>
namespace speedtree_lod {
struct FrondVertex {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
};

struct FrondGuide {
    std::vector<FrondVertex> vertices;
    float f10, f14;
    unsigned char c18;
    float f1c, f20, f24;
    int i28, i2c;
};

extern bool DAT_01178398;
class LeafRandom {
public:
    void FUN_00bc4b70(long seed);
    __declspec(noinline) LeafRandom() { if (!DAT_01178398) FUN_00bc4b70(-1); }
    __declspec(noinline) ~LeafRandom() {}
    float FUN_00bc4b40(float low,float high);
};


typedef FrondGuide Guide;
typedef std::vector<Guide> GuideVector;
typedef LeafRandom GuideRandom;
struct GuideOrder { bool operator()(const Guide& a, const Guide& b) const {return a.f24>b.f24;} };
float FUN_00ba11a0(float,float,float);
struct FrondEngine {
    void* geometry; void* auxiliary;
    GuideVector sourceGuides;
    __forceinline GuideVector& getSourceGuides() {return sourceGuides;}
    std::vector<GuideVector> guides;
    int settings[10];
    unsigned levelCount;
    float firstCoverage,lastCoverage,randomWeight,retainFraction;
    void FUN_00bbc5b0();
};
}
namespace std {
template<> size_t vector<speedtree_lod::FrondGuide>::size() const;
template<> speedtree_lod::FrondGuide& vector<speedtree_lod::FrondGuide>::operator[](size_t);
template<> vector<speedtree_lod::FrondGuide>::iterator vector<speedtree_lod::FrondGuide>::begin();
template<> vector<speedtree_lod::FrondGuide>::iterator vector<speedtree_lod::FrondGuide>::end();
template<> void sort(vector<speedtree_lod::FrondGuide>::iterator, vector<speedtree_lod::FrondGuide>::iterator, speedtree_lod::GuideOrder);
template<> vector<speedtree_lod::FrondGuide>::vector();
template<> vector<speedtree_lod::FrondGuide>::~vector();
template<> vector<speedtree_lod::FrondGuide>::iterator vector<speedtree_lod::FrondGuide>::iterator::operator+(int) const;
template<> void vector<speedtree_lod::FrondGuide>::push_back(const speedtree_lod::FrondGuide&);
template<> vector<speedtree_lod::GuideVector>::iterator vector<speedtree_lod::GuideVector>::iterator::operator+(int) const;
}
namespace speedtree_lod {
// pdb: CFrondEngine::BuildGuideLods | FrondEngine.obj | fnv360_0822_retail, objrun, medium
void FrondEngine::FUN_00bbc5b0()
{

    float fCombinedGuideArea = 0.0f;
    float maximumFrondArea = 0.0f;
    for (unsigned index = 0; index < getSourceGuides().size(); ++index) {
        fCombinedGuideArea += getSourceGuides()[index].f20;
        if (getSourceGuides()[index].f20 > maximumFrondArea)
            maximumFrondArea = getSourceGuides()[index].f20;
    }

    float maximumAreaSquared = maximumFrondArea * maximumFrondArea;
    GuideRandom guideRandomStream;
    float guideThreshold = 1.0f - retainFraction;
    GuideVector retained;
    for (unsigned index = 0; index < getSourceGuides().size(); ++index) {
        float area = getSourceGuides()[index].f20;
        if (area > maximumFrondArea * guideThreshold) {
            retained.push_back(getSourceGuides()[index]);
            getSourceGuides().erase(getSourceGuides().begin() + index);
            --index;
        } else {
            float noiseInfluence = guideRandomStream.FUN_00bc4b40(0.0f, randomWeight);
            float remainingFraction = 1.0f - noiseInfluence;
            area = remainingFraction * area + noiseInfluence * maximumAreaSquared;
            getSourceGuides()[index].f24 = area;
        }
    }

    std::sort(getSourceGuides().begin(), getSourceGuides().end(), GuideOrder());
    std::sort(retained.begin(), retained.end(), GuideOrder());
    for (unsigned index = 0; index < retained.size(); ++index)
        getSourceGuides().insert(getSourceGuides().begin(), retained[index]);

    for (unsigned level = 0; level < levelCount; ++level) {
        float coverageFraction;
        if (levelCount == 1)
            coverageFraction = firstCoverage;
        else
            coverageFraction = FUN_00ba11a0(firstCoverage, lastCoverage, static_cast<float>(level) / (levelCount - 1));
        float levelArea = coverageFraction * fCombinedGuideArea;
        float usedArea = 0.0f;
        GuideVector guidesForLod;
        if (levelArea > 0.0) {
            for (unsigned index = 0; index < getSourceGuides().size() && usedArea <= levelArea; ++index) {
                usedArea += getSourceGuides()[index].f20;
                guidesForLod.push_back(getSourceGuides()[index]);
            }
        }
        guides.push_back(guidesForLod);
    }
}

}
