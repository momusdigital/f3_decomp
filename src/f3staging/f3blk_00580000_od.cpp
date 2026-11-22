// src/f3staging/f3blk_00580000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0059da90 (community match, verified in this file)
#include <string.h>
struct Allocator59 { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern Allocator59 DAT_01090a78;
inline void* __cdecl operator new[](unsigned int n) { return DAT_01090a78.FUN_0086b930(n); }
inline void __cdecl operator delete[](void* p) { DAT_01090a78.FUN_0086ba60(p); }
void* __cdecl FUN_0089e810(unsigned);
void __cdecl FUN_0089e890(void*);
void* __cdecl FUN_0089eb90(unsigned);
void __cdecl FUN_0089ec10(void*,unsigned);
extern "C" int __cdecl FUN_00c018aa(double);
inline void* Copy59(void* d,const void* s,unsigned int n) { return memcpy(d,s,n); }
inline void* Set59(void* d,int c,unsigned int n) { return memset(d,c,n); }
struct Point59 {
 float x,y,z;
 Point59() {}
 Point59(float a,float b,float c):x(a),y(b),z(c) {}
};
struct UV59 {
 float x,y;
 UV59() {}
 UV59(float a,float b):x(a),y(b) {}
};
struct Color59 {
 float r,g,b,a;
 Color59() {}
 Color59(float fR,float fG,float fB,float fA):r(fR),g(fG),b(fB),a(fA) {}
};
extern const Point59 DAT_00f725b0;
struct MemObject59 {
 static void* operator new(unsigned n) { return FUN_0089eb90(n); }
 static void operator delete(void* p,unsigned n);
};
struct Ref59 : MemObject59 {
 virtual void v00();
 virtual void DeleteThis();
 long m_lRefCount;
 void IncRefCount() { InterlockedIncrement(&m_lRefCount); }
 void DecRefCount() { if(!InterlockedDecrement(&m_lRefCount)) DeleteThis(); }
};
template<class T> struct Ptr59 {
 T* m_pObject;
 Ptr59(T* p) { m_pObject=p; if(m_pObject) m_pObject->IncRefCount(); }
 ~Ptr59() { if(m_pObject) m_pObject->DecRefCount(); }
 operator T*() const { return m_pObject; }
 T* operator->() const { return m_pObject; }
};
struct CopyPtr {
 Ref59* ptr;
 CopyPtr();
 ~CopyPtr();
 CopyPtr& operator=(Ref59* p) {
  if(ptr!=p) { if(ptr) ptr->DecRefCount(); ptr=p; if(ptr) ptr->IncRefCount(); }
  return *this;
 }
 operator Ref59*() const { return ptr; }
};
struct Geometry59 {
 void FUN_00ba1c50();
 void FUN_00ba1dd0();
 Geometry59() { FUN_00ba1c50(); }
 ~Geometry59();
 int unk00;
 int unk04;
 unsigned short* pStripCount;
 unsigned short** ppStrips;
 unsigned short usVertexCount;
 unsigned short unk12;
 unsigned int* pColors;
 float* pNormals;
 float* pBinormals;
 float* pTangents;
 float* pCoords;
 float* pTexCoords;
 int unk2c;
 float* pLodFade;
 unsigned char* pWindIndices;
 int unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54;
 int unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74;
 int unk78,unk7c,unk80,unk84,unk88,unk8c,unk90,unk94;
 int unk98,unk9c,unka0,unka4,unka8,unkac,unkb0,unkb4;
 int unkb8,unkbc,unkc0,unkc4,unkc8,unkcc,unkd0,unkd4;
 int unkd8,unkdc,unke0,unke4,unke8,unkec,unkf0,unkf4;
 int unkf8,unkfc,unk100,unk104,unk108,unk10c,unk110,unk114;
 int unk118,unk11c,unk120,unk124,unk128,unk12c;
};
struct SpeedTree59 {
 unsigned short FUN_00ba1490();
 void FUN_00ba71d0(Geometry59&,unsigned int,short,short,short);
 void FUN_00ba34f0();
 void FUN_00ba3540();
};
template<class T> struct Malloc59 {
 static T* Allocate(unsigned int uiNumElements) { return (T*)FUN_0089e810(sizeof(T)*uiNumElements); }
 static void Deallocate(T* p) { FUN_0089e890(p); }
};
template<class T> struct A94360Array {
 virtual ~A94360Array() { Malloc59<T>::Deallocate(m_pBase); }
 T* m_pBase;
 unsigned short m_usMaxSize,m_usSize,m_usESize,m_usGrowBy;
 A94360Array(unsigned int uiMaxSize,unsigned int uiGrowBy) {
  m_usMaxSize=(unsigned short)uiMaxSize;
  m_usGrowBy=(unsigned short)uiGrowBy;
  m_usSize=0;
  m_usESize=0;
  if(m_usMaxSize>0) m_pBase=Malloc59<T>::Allocate(m_usMaxSize);
  else m_pBase=0;
 }
 unsigned int GetSize() const { return m_usSize; }
 T& GetAt(unsigned int i) const { return m_pBase[i]; }
 unsigned int SetAtGrow(unsigned int uiIndex,const T& element) { if(uiIndex>=m_usMaxSize) SetSize(uiIndex+m_usGrowBy); SetAt(uiIndex,element); return uiIndex; }
 void SetAt(unsigned int uiIndex,const T& element) {
  if(uiIndex>=m_usSize) { m_usSize=(unsigned short)(uiIndex+1); if(element!=T(0)) m_usESize++; }
  else if(element!=T(0)) { if(m_pBase[uiIndex]==T(0)) m_usESize++; }
  else if(m_pBase[uiIndex]!=T(0)) m_usESize--;
  m_pBase[uiIndex]=element;
 }
 void SetSize(unsigned int uiMaxSize) {
  if(uiMaxSize==m_usMaxSize) return;
  unsigned short i;
  if(uiMaxSize<m_usSize) {
   for(i=(unsigned short)uiMaxSize;i<m_usSize;i++) if(m_pBase[i]!=T(0)) { m_pBase[i]=T(0); m_usESize--; }
   m_usSize=(unsigned short)uiMaxSize;
  }
  T* pSaveBase=m_pBase;
  m_usMaxSize=(unsigned short)uiMaxSize;
  if(uiMaxSize>0) {
   m_pBase=Malloc59<T>::Allocate(m_usMaxSize);
   for(i=0;i<m_usSize;i++) m_pBase[i]=pSaveBase[i];
   for(i=m_usSize;i<m_usMaxSize;i++) m_pBase[i]=T(0);
  } else m_pBase=0;
  Malloc59<T>::Deallocate(pSaveBase);
 }
};
template<class T> struct A94360PrimitiveArray : A94360Array<T> {
 A94360PrimitiveArray(unsigned int uiMaxSize=0,unsigned int uiGrowBy=1):A94360Array<T>(uiMaxSize,uiGrowBy) {}
 unsigned int FUN_00ab9e10(const T& element) { return this->SetAtGrow(this->m_usSize,element); }
};
struct FUN_008403a0 : Ref59 {
 int unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
 int unk28,unk2c,unk30,unk34;
 unsigned char m_ucKeepFlags;
 unsigned char m_ucCompressFlags;
 unsigned short unk3a;
 int unk3c,unk40,unk44,unk48,unk4c;
 FUN_008403a0(unsigned short,Point59*,Point59*,void*,UV59*,unsigned short,unsigned,unsigned short,unsigned short,unsigned short*,unsigned short*);
 void FUN_00831380(unsigned);
 void SetKeepFlags(unsigned char uc) { m_ucKeepFlags=uc; }
 void SetCompressFlags(unsigned char uc) { m_ucCompressFlags=uc; }
};
struct FUN_00b35a80 : Ref59 {
 Color59* m_pData;
 unsigned short m_usCount;
 unsigned short unk0e;
 FUN_00b35a80();
 void SetData(Color59* p,unsigned int n) { m_pData=p; m_usCount=(unsigned short)n; }
};
struct FUN_00b35f80 : Ref59 {
 int unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
 int unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44;
 int unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64;
 int unk68,unk6c,unk70,unk74,unk78,unk7c,unk80,unk84;
 int unk88,unk8c,unk90,unk94,unk98,unk9c,unka0,unka4;
 int unka8,unkac,unkb0,unkb4,unkb8,unkbc,unkc0,unkc4;
 int unkc8,unkcc,unkd0,unkd4,unkd8,unkdc,unke0,unke4;
 int unke8,unkec,unkf0,unkf4,unkf8,unkfc,unk100,unk104;
 FUN_00b35f80(FUN_00b35a80*);
};
struct Owner59 {
 int unk00,unk04,m_iState;
 SpeedTree59* m_pTreeRuntime;
 int unk10;
 CopyPtr* m_pspLeafGeometry;
 int unk18,unk1c,unk20;
 CopyPtr* m_pspLeafShapes;
 bool IsFinished() { return m_iState==2; }
 unsigned short GetNumBranchLODLevels() { return m_pTreeRuntime ? m_pTreeRuntime->FUN_00ba1490() : 0; }
 void FUN_0059da90();
};
// pdb: BSTreeModel::CreateBranchGeometry | BSTreeModel.obj | fnv360_0822_retail, call_gap, low
void Owner59::FUN_0059da90()
{
 unsigned int uiI;
 unsigned short usLOD;
 unsigned short usV;
 Geometry59 kGeom;
 unsigned short usVerts;
 unsigned short usLODs;
 if(!m_pTreeRuntime || IsFinished()) return;
 if(m_pspLeafGeometry) { delete[] m_pspLeafGeometry; m_pspLeafGeometry=0; }
 if(m_pspLeafShapes) { delete[] m_pspLeafShapes; m_pspLeafShapes=0; }
 usLODs=GetNumBranchLODLevels();
 if(usLODs<=0) return;
 m_pTreeRuntime->FUN_00ba71d0(kGeom,1,-1,-1,-1);
 if(!kGeom.pCoords || !kGeom.pNormals || !kGeom.pTexCoords || !kGeom.pColors || !kGeom.pLodFade || !kGeom.pWindIndices) return;
 usVerts=kGeom.usVertexCount;
 if(usVerts<=0) return;
 m_pspLeafGeometry=new CopyPtr[usLODs];
 m_pspLeafShapes=new CopyPtr[usLODs];
 for(usLOD=0;usLOD<usLODs;usLOD++) { m_pspLeafGeometry[usLOD]=0; m_pspLeafShapes[usLOD]=0; }
 if(kGeom.pTangents && kGeom.pBinormals) {
  Point59* pNormals=(Point59*)kGeom.pNormals;
  for(int i=0;i<usVerts;i++) {
   Point59 kNormal=pNormals[i];
   if(FUN_00c018aa(kNormal.x)||FUN_00c018aa(kNormal.y)||FUN_00c018aa(kNormal.z)) pNormals[i]=DAT_00f725b0;
  }
 }
 for(usLOD=0;usLOD<usLODs;usLOD++) {
  m_pTreeRuntime->FUN_00ba71d0(kGeom,1,usLOD,-1,-1);
  usVerts=kGeom.usVertexCount;
  if(usVerts<=0 || !kGeom.pStripCount || !kGeom.ppStrips) continue;
  unsigned short* pusStripLengths=(unsigned short*)FUN_0089e810(2);
  *pusStripLengths=*kGeom.pStripCount;
  unsigned short* pusStripLists=(unsigned short*)FUN_0089e810(*pusStripLengths*2);
  Copy59(pusStripLists,*kGeom.ppStrips,*pusStripLengths*2);
  unsigned char* pucUsed=new unsigned char[kGeom.usVertexCount];
  Set59(pucUsed,0,kGeom.usVertexCount);
  for(uiI=0;uiI<*pusStripLengths;uiI++) pucUsed[pusStripLists[uiI]]=1;
  A94360PrimitiveArray<void*> kRemap(0,1);
  for(usV=0;usV<kGeom.usVertexCount;usV++) if(pucUsed[usV]) kRemap.FUN_00ab9e10((void*)usV);
  delete[] pucUsed;
  for(usV=0;usV<kRemap.GetSize();usV++) {
   unsigned int uiOld=(unsigned int)kRemap.GetAt(usV);
   for(uiI=0;uiI<*pusStripLengths;uiI++) if((*kGeom.ppStrips)[uiI]==uiOld) pusStripLists[uiI]=usV;
  }
  Point59* pkVerts=new Point59[kRemap.GetSize()];
  UV59* pkUVs=new UV59[kRemap.GetSize()];
  Point59* pkNormals=0;
  Point59* pkTangents=0;
  Point59* pkBinormals=0;
  bool bNBT;
  if(kGeom.pTangents && kGeom.pBinormals) {
   pkNormals=new Point59[kRemap.GetSize()*3];
   pkBinormals=pkNormals+kRemap.GetSize();
   pkTangents=pkNormals+kRemap.GetSize()*2;
   bNBT=true;
  } else {
   pkNormals=new Point59[kRemap.GetSize()];
   bNBT=false;
  }
  for(usV=0;usV<kRemap.GetSize();usV++) {
   unsigned int uiOld=(unsigned int)kRemap.GetAt(usV);
   int i0=uiOld*3;
   int i1=uiOld*3+1;
   int i2=uiOld*3+2;
   int t0=uiOld*2;
   int t1=uiOld*2+1;
   pkVerts[usV]=Point59(kGeom.pCoords[i0],kGeom.pCoords[i1],kGeom.pCoords[i2]);
   pkNormals[usV]=Point59(kGeom.pNormals[i0],kGeom.pNormals[i1],kGeom.pNormals[i2]);
   pkUVs[usV]=UV59(kGeom.pTexCoords[t0],kGeom.pTexCoords[t1]);
   if(bNBT) {
    pkTangents[usV]=Point59(kGeom.pTangents[i0],kGeom.pTangents[i1],kGeom.pTangents[i2]);
    pkBinormals[usV]=Point59(kGeom.pBinormals[i0],kGeom.pBinormals[i1],kGeom.pBinormals[i2]);
   }
  }
  Color59* pkColors=new Color59[kRemap.GetSize()];
  for(usV=0;usV<kRemap.GetSize();usV++) {
   unsigned int uiOld=(unsigned int)kRemap.GetAt(usV);
   float fAlpha=((kGeom.pColors[uiOld]&0xff00)>>8)/255.0;
   pkColors[usV]=Color59(kGeom.pLodFade[uiOld],(float)(kGeom.pWindIndices[uiOld]*4),fAlpha,0.0f);
  }
  Ptr59<FUN_00b35a80> spData(new FUN_00b35a80);
  spData->SetData(pkColors,kRemap.GetSize());
  m_pspLeafGeometry[usLOD]=new FUN_008403a0(kRemap.GetSize(),pkVerts,pkNormals,0,pkUVs,1,bNBT?0x1000:0,*kGeom.pStripCount-2,1,pusStripLengths,pusStripLists);
  ((FUN_008403a0*)(Ref59*)m_pspLeafGeometry[usLOD])->FUN_00831380(0x4000);
  ((FUN_008403a0*)(Ref59*)m_pspLeafGeometry[usLOD])->SetKeepFlags(0x11);
  ((FUN_008403a0*)(Ref59*)m_pspLeafGeometry[usLOD])->SetCompressFlags(1);
  m_pspLeafShapes[usLOD]=new FUN_00b35f80(spData);
 }
 m_pTreeRuntime->FUN_00ba34f0();
 kGeom.pColors=0;
 m_pTreeRuntime->FUN_00ba3540();
 kGeom.pLodFade=0;
 kGeom.pWindIndices=0;
}
