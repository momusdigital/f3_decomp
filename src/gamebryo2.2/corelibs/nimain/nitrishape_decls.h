// gamebryo2.2/corelibs/nimain/nitrishape_decls.h: declares NiMemObject, NiTriBasedGeomData, NiTriShapeData, NiGeometry, NiTriBasedGeom and more
#ifndef NITRISHAPE_DECLS_H
#define NITRISHAPE_DECLS_H
#include "f3_common.h"

#include "nitrishape_types_NiGeometryData__DataFlags.h"

class NiPoint2;
class NiPoint3;
class RgbaColor;
class NiTriShape;

class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};

class NiTriBasedGeomData : public NiMemObject
{
  public:
    unsigned char unk00[0x20];
    NiPoint3* m_pkVertex;  // src: FNV360_PDB NiGeometryData +0x20 (old: geometryFields)
    unsigned char unk24[0x20];
};

class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned char shapeFields[20];
    NiTriShapeData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                   NiGeometryData__DataFlags, unsigned short, unsigned short*) throw();
};

class NiGeometry
{
  public:
    virtual ~NiGeometry();
    unsigned char unk04[0xB4];
    NiTriShapeData* m_spModelData;  // src: FNV360_PDB +0xB8 (old: geometryFields)
    unsigned char unkBC[8];
};

class NiTriBasedGeom : public NiGeometry
{
  public:
    NiTriBasedGeom(NiTriBasedGeomData*) throw();
};

class NiTriShape : public NiTriBasedGeom
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, NiGeometryData__DataFlags,
               unsigned short, unsigned short*);
    virtual ~NiTriShape();
};

FNV_STATIC_ASSERT(sizeof(NiTriShapeData) == 0x58);
FNV_STATIC_ASSERT(sizeof(NiTriShape) == 0xc4);

#endif
