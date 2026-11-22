// src/f3staging/f3blk_00a40000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00a45c90 (community match, verified in this file)
class hkStatisticsCollector {
public:
    virtual ~hkStatisticsCollector();
    virtual void beginObject(const char* name, int type, const void* object);
    virtual void addChunk(const char* name, int type, const void* chunk, int usedSize, int allocatedSize);
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void endObject();
};

extern const char DAT_00e80638[];
extern const char DAT_00e861a8[];

struct MeshSubpart_5c90 {
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
};

struct MeshShape_5c90 {
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
    MeshSubpart_5c90* m_subparts;
    int m_subpartsSize;
    int m_subpartsCapacityAndFlags;
    void hkpMeshShape_calcContentStatistics(hkStatisticsCollector* collector) const;
};

// pdb: hkpMeshShape::calcContentStatistics | hkpMeshShape.obj | fnv360_0822_retail, ustr + bridge(ustr|vtable) + skyrim(ustr), high
void MeshShape_5c90::hkpMeshShape_calcContentStatistics(hkStatisticsCollector* collector) const
{
    collector->beginObject(DAT_00e80638, 1, this);
    if (!(m_subpartsCapacityAndFlags & 0x80000000)) {
        collector->addChunk(DAT_00e861a8, 1, m_subparts,
            m_subpartsSize * sizeof(MeshSubpart_5c90),
            (m_subpartsCapacityAndFlags & 0x3fffffff) * sizeof(MeshSubpart_5c90));
    }
    collector->endObject();
}

// @f3 0x00a530e0 (community match, verified in this file)
struct FUN_00a530e0 {
    float first;
    float second;
    float third;
    float fourth;
    unsigned int fifth;
    float sixth;
    unsigned int seventh;
    unsigned int eighth;
    FUN_00a530e0(const FUN_00a530e0& other);
};
// pdb: hkpMoppLongRayVirtualMachine::QueryInt::operator= | hkpMoppLongRayVirtualMachine.obj | tesv_win, objopen_prop, low
FUN_00a530e0::FUN_00a530e0(const FUN_00a530e0& other) {
    first = other.first;
    second = other.second;
    third = other.third;
    fourth = other.fourth;
    fifth = other.fifth;
    sixth = other.sixth;
    seventh = other.seventh;
    eighth = other.eighth;
}

// @f3 0x00a46010 (community match, verified in this file)
struct Record399 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};
struct Count399 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    int count;
};
int __cdecl hkString_strCmp(const Record399* record, const void* key);
struct Search399 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Count399* context;
    Record399* records;
    int FUN_00a46010(const void* key);
};
int Search399::FUN_00a46010(const void* key) {
    for (int index = 0; index < context->count; ++index) {
        if (hkString_strCmp(&records[index], key) == 0)
            return index;
    }
    return -1;
}

// @f3 0x00a4def0 (community match, verified in this file)
struct EntryCollection {
    void FUN_00922cb0();
    void FUN_00922680();
    void FUN_00922f70(int count);
    void FUN_00922710(void* item, int flag);
};

extern void* DAT_00e86b14;

struct Cls_00a4def0 {
    virtual ~Cls_00a4def0();
    EntryCollection m_collection;

    Cls_00a4def0* FUN_00a4def0(void** items, int count);
};

// pdb: `anonymous namespace'::hkEntitySelectorListed::hkEntitySelectorListed | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, uvref, high
// pdb params: entities, numEntities
Cls_00a4def0* Cls_00a4def0::FUN_00a4def0(void** items, int count)
{
    *(void**)this = &DAT_00e86b14;
    m_collection.FUN_00922cb0();
    m_collection.FUN_00922680();
    m_collection.FUN_00922f70(count);
    for (int i = 0; i < count; ++i) {
        m_collection.FUN_00922710(items[i], 1);
    }
    return this;
}

// @f3 0x00a5f4b0 (community match, verified in this file)
struct Flag { char value; Flag(bool b):value(b) {} operator bool() const { return value!=0; } Flag& operator=(bool b) { value=b;return *this;} };
struct Point4 { float x,y,z,w; };
struct Edge { unsigned int a,b; };
extern void __cdecl FUN_00901f10(void*,int);
extern unsigned int DAT_010f3170;
struct Allocator { void FUN_008f6d90(void*,int,int); };
extern "C" __declspec(dllimport) Allocator* __stdcall TlsGetValue(unsigned int);
template<class T> struct Array {
 T* data; int size; int capacity;
 void append(const T& value) {
  if(size==(capacity&0x3fffffff)) FUN_00901f10(this,sizeof(T));
  data[size]=value; ++size;
 }
 void release() {
  if(!(capacity&0x80000000)) {
   int bytes=(capacity&0x3fffffff);
   Allocator* allocator=TlsGetValue(DAT_010f3170);
   allocator->FUN_008f6d90(data,bytes*sizeof(T),0x17);
  }
 }
 void FUN_00a601b0(Array<Edge>*);
};
struct SmallIndices : Array<int> { int storage[3]; SmallIndices() {data=storage;size=0;capacity=0x80000003;} };
struct Hull {
 Point4* points; Array<Edge> edges; Edge storage[128];
 void FUN_00a60840();
 void FUN_00a60250(int);
 void FUN_00a602b0(int,int);
 void FUN_00a60350(int,int,int);
};
extern void __cdecl FUN_00a5bbb0(Hull*,int,int,void*,Flag*);
extern void __cdecl FUN_00a5e880(void*,Hull*,Hull*,Hull*);
// pdb: hkGeomConvexHullBuilder::buildConvexSubHull | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a5f4b0(void* context,Hull* points,int first,int last,Hull* out) {
 int i=first;
 int end=last+1;
 int count=0;
 for(;i<end;++i) count += points->points[i].w==0.0f ? 1:0;
 if(count>3) {
  int middle=(first+last)/2;
  Hull left; left.FUN_00a60840(); left.points=points->points;
  Hull right; right.FUN_00a60840(); right.points=points->points;
  Flag again=true;
  while(again) {
   while(again) {
    left.edges.size=0;
    FUN_00a5f4b0(context,points,first,middle,&left);
    FUN_00a5bbb0(&left,first,middle,context,&again);
   }
   again=true;
   do {
    right.edges.size=0;
    FUN_00a5f4b0(context,points,middle+1,last,&right);
    FUN_00a5bbb0(&right,middle+1,last,context,&again);
   } while(again);
   again=true;
   FUN_00a5bbb0(&left,first,last,context,&again);
   Flag other=true;
   FUN_00a5bbb0(&right,first,last,context,&other);
   again=again||other;
  }
  if(left.edges.size==0) {
   for(int j=0;j<right.edges.size;++j) out->edges.append(right.edges.data[j]);
  } else if(right.edges.size==0) {
   for(int j=0;j<left.edges.size;++j) out->edges.append(left.edges.data[j]);
  } else FUN_00a5e880(context,&left,&right,out);
  if(out->edges.size==0) out->edges.FUN_00a601b0(&left.edges);
  right.edges.release();
  left.edges.release();
 } else {
  out->points=points->points;
  SmallIndices indices;
  for(int j=first;j<end;++j) if(points->points[j].w==0.0f) indices.append(j);
  switch(count) {
   case 0: break;
   case 1: out->FUN_00a60250(indices.data[0]);break;
   case 2: out->FUN_00a602b0(indices.data[0],indices.data[1]);break;
   default: out->FUN_00a60350(indices.data[0],indices.data[1],indices.data[2]);break;
  }
  indices.release();
 }
}

// @f3 0x00a4ae40 (community match, verified in this file)
extern int DAT_01065190;
namespace f3m_00a4ae40 {

struct HashTable_a4ae
{
    int FUN_009227d0(int key, int hint);
};

struct Class_a4ae40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    HashTable_a4ae hashTable;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    void FUN_00a4ac50(int a1, int a2, int a3, int a4, int extra);
    void hkPackfileWriter_setContentsWithRegistry(int a1, int a2, int a3, int a4);
};

// pdb: hkPackfileWriter::setContentsWithRegistry | hkPackfileWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
void Class_a4ae40::hkPackfileWriter_setContentsWithRegistry(int a1, int a2, int a3, int a4)
{
    FUN_00a4ac50(a1, a2, a3, a4, DAT_01065190);
    unk8c = hashTable.FUN_009227d0(a1, -1);
    unk90 = hashTable.FUN_009227d0(a2, -1);
}
}   // namespace f3m_00a4ae40

// @f3 0x00a59730 (community match, verified in this file)
namespace f3m_00a59730 {
inline void Swap1177(unsigned short*& first,unsigned short*& second) { unsigned short* temp=first;first=second;second=temp; }
struct Owner1177 {
 int unk00,unk04,unk08,unk0C;
 unsigned short* first10; unsigned short* middle14; unsigned short* last18;
 void FUN_00a59730();
};
// pdb: hkGeomConvexHullBuilder::PlaneAndPoints::sort | hkGeomConvexHullBuilder.obj | tesv_win, hash, low
void Owner1177::FUN_00a59730() {
 if(*first10>*middle14) Swap1177(first10,middle14);
 if(*middle14>*last18) Swap1177(middle14,last18);
 if(*first10>*middle14) Swap1177(first10,middle14);
}
}   // namespace f3m_00a59730

// @f3 0x00a56a80 (community match, verified in this file)
namespace f3m_00a56a80 {
struct V4a56 { float x, y, z, w; };
struct Src_a56 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int GetCount();
    virtual const V4a56* GetData(V4a56* out);
};
struct Obj_a56 {
    char pad0[0x18];
    Src_a56* m_pSrc;
    int pad1c;
    V4a56 m_offset;
    V4a56* FUN_00a56a80(V4a56* out);
};
V4a56* Obj_a56::FUN_00a56a80(V4a56* out) {
    const V4a56* src = m_pSrc->GetData(out);
    V4a56* dst = out;
    int n = m_pSrc->GetCount();
    for (int i = 0; i < n; i++) {
        dst->x = src->x + m_offset.x;
        dst->y = src->y + m_offset.y;
        dst->z = src->z + m_offset.z;
        dst->w = src->w + m_offset.w;
        ++src; ++dst;
    }
    return out;
}
}   // namespace f3m_00a56a80

// @f3 0x00a49950 (community match, verified in this file)
namespace f3m_00a49950 {
namespace f3m_00a49950 {
void __cdecl FUN_00923500(void* p, int v, int n);
int __cdecl FUN_009233f0(const char* s);
int __cdecl FUN_009232f0(const char* a, const char* b, int n);

struct QStream {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual int read(void* buf, int n);
    virtual void v14(); virtual void v18();
    virtual void setMark(int n);
    virtual void rewindToMark();
};

struct QHeader {
    int m_magic[2];
    int m_userTag;
    int m_fileVersion;
    int m_layoutRules;
    int m_numSections;
    int m_contentsSectionIndex;
    int m_contentsSectionOffset;
    int m_contentsClassNameSectionIndex;
    int m_contentsClassNameSectionOffset;
    int m_contentsVersion[4];
    int m_flags;
    int m_pad;
    QHeader() {}
    QHeader(int) {
        FUN_00923500(this, -1, sizeof(QHeader));
        m_magic[0] = 0x57e0e057;
        m_magic[1] = 0x10c0c010;
        *(char*)m_contentsVersion = 0;
    }
};

struct QFormat {
    int m_value;
    QFormat(int v) : m_value(v) {}
};

QFormat __cdecl FUN_00a49950(QStream* stream)
{
    QHeader buf;
    stream->setMark(sizeof(buf));
    if (stream->read(&buf, sizeof(buf)) != sizeof(buf))
        return QFormat(0);
    stream->rewindToMark();
    QHeader hdr(0);
    if (buf.m_magic[0] == hdr.m_magic[0] && buf.m_magic[1] == hdr.m_magic[1])
        return QFormat(2);
    const char* p = (const char*)&buf;
    const char* end = p + sizeof(buf);
    for (; p != end; ++p) {
        if (*p == '<') break;
    }
    if (p != end) {
        const char* tags[] = { "<?xml", "<hkpackfile", "<hksection", 0 };
        for (int i = 0; tags[i] != 0; ++i) {
            int len = FUN_009233f0(tags[i]);
            if (FUN_009232f0(p, tags[i], len < end - p ? len : end - p) == 0)
                return QFormat(3);
        }
    }
    return QFormat(1);
}
}
}   // namespace f3m_00a49950

// @f3 0x00a5de20 (community match, verified in this file)
namespace f3m_00a5de20 {
struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Sample {
    unsigned short* index;
    float param;
};

extern void __cdecl FUN_00901e90(void*, int, int);
extern void __cdecl FUN_00a59e30(Vec4* verts, Vec4* obj, float baseT, Vec4* vec, unsigned short* idx, Vec3* a, Vec3* b, Array<Sample>* collected);

struct Inplace64 : Array<Sample> {
    Sample storage[64];
};

// pdb: hkGeomConvexHullBuilder::removeCoPlanarNeighbours | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a5de20(Vec4* obj, Vec4** base, Vec4* vec, unsigned short* idx, Vec3* a, Vec3* b, Array<Sample>* samples)
{
    Vec4* verts = *base;
    float threshold = obj->w;
    if (samples->size <= 1)
        return;
    if (!((samples->data[1].param - samples->data[0].param) < threshold))
        return;

    Inplace64 collected;
    collected.data = collected.storage;
    collected.size = 0;
    collected.capacity = 0x80000040;
    float baseT = samples->data[0].param;
    for (int i = 0; i < samples->size; ++i) {
        Sample* elem = &samples->data[i];
        if ((elem->param - baseT) > threshold)
            break;
        collected.append(*elem);
    }
    FUN_00a59e30(verts, obj, baseT, vec, idx, a, b, &collected);
    samples->data[0] = collected.data[0];
    samples->data[0].param = baseT;
    int capacity = samples->capacity & 0x3fffffff;
    if (capacity < 1) {
        int cap2 = 2 * capacity;
        int newSize = (1 < cap2) ? cap2 : 1;
        FUN_00901e90(samples, newSize, sizeof(Sample));
    }
    samples->size = 1;
    collected.release();
}
}   // namespace f3m_00a5de20

// @f3 0x00a4ab20 (community match, verified in this file)
namespace Writer2110 {
extern unsigned long DAT_010f3170;
struct Heap {void FUN_008f6f90(void*) throw();void FUN_008f6d90(void*,unsigned int,int) throw();};
__forceinline Heap* GetHeap() throw(){return reinterpret_cast<Heap*>(::TlsGetValue(DAT_010f3170));}
struct Record24 {unsigned int unk00,unk04,unk08,unk0C,unk10,unk14;};
struct Record8 {unsigned int unk00,unk04;};
template<class T>struct Array {T* data;int size;unsigned int capacity;
 ~Array() throw(){if((capacity&0x80000000u)==0){int count=capacity&0x3fffffff;Heap* heap=GetHeap();heap->FUN_008f6d90(data,count*sizeof(T),23);}}
};
struct Array12 {unsigned int unk00,unk04,unk08;void FUN_00922cf0() throw();~Array12() throw(){FUN_00922cf0();}};
struct Map16 {unsigned int unk00,unk04,unk08,unk0C;void FUN_009b1160() throw();~Map16() throw(){FUN_009b1160();}};
struct Base {virtual ~Base() throw(){}};
struct FUN_00a4ab20:Base {
 unsigned int unk04;
 Array<Record24> records;
 Array12 first,second,third;
 Map16 firstMap,secondMap;
 Array12 fourth;
 Array<void*> pendingObjects;
 Map16 thirdMap;
 Array<Record8> pairs;
 unsigned int unk8C,unk90,unk94,unk98;
 Array12 fifth;
 Map16 fourthMap;
 virtual ~FUN_00a4ab20() throw();
};
// pdb: hkPackfileWriter::~hkPackfileWriter | hkPackfileWriter.obj | fnv360_0822_retail, objrun_prop, medium
FUN_00a4ab20::~FUN_00a4ab20() throw(){
 for(int i=0;i<pendingObjects.size;++i){void* object=pendingObjects.data[i];Heap* heap=GetHeap();heap->FUN_008f6f90(object);}
}
}

// @f3 0x00a5e110 (community match, verified in this file)
// FUN_00a5e110: flood-fill over 8-byte node records linked by word+4,
// marking word+6 with tag; collects unmarked word+2 references into an
// inline Array<Node*> of 128 slots; reports success/failure in *out.

struct Node {
    unsigned short unk00;
    unsigned short w02;
    unsigned short w04;
    unsigned short w06;
};

struct Ctx {
    unsigned int unk00;
    Node* nodes;
};

struct NodeList : Array<Node*> {
    Node* storage[128];
};

typedef Allocator* (__stdcall *TlsGet_x)(unsigned int);
extern TlsGet_x g_tls_get_value;

// pdb: hkGeomConvexHullBuilder::isValidEdgeCheck | hkGeomConvexHullBuilder.obj | tesv_win, call_dedup, low
bool* __cdecl FUN_00a5e110(bool* out, Ctx* ctx, Node* first, unsigned int tag)
{
    Node* nodes = ctx->nodes;
    NodeList list;
    list.data = list.storage;
    list.capacity = 0x80000080;
    list.storage[0] = first;
    list.size = 1;
    do {
        Node* start = list.data[list.size - 1];
        list.size--;
        Node* cur = start;
        do {
            cur = &nodes[cur->w04];
            unsigned int t = cur->w06;
            switch (t) {
            case 1:
            case 3:
                if (t != tag) goto fail;
                break;
            case 2:
                if (tag == 3) goto after_write;
                break;
            }
            cur->w06 = (unsigned short)tag;
after_write:
            ;
        } while (cur != start);
        Node* walker = start;
        do {
            walker = &nodes[walker->w04];
            Node* refNode = &nodes[walker->w02];
            if (refNode->w06 == 0)
                list.append(refNode);
        } while (walker != start);
    } while (list.size != 0);
    *out = true;
    if (!(list.capacity & 0x80000000)) {
        int bytes = list.capacity & 0x3fffffff;
        Allocator* allocator = g_tls_get_value(DAT_010f3170);
        allocator->FUN_008f6d90(list.data, bytes * 4, 0x17);
    }
    return out;
fail:
    *out = false;
    if (!(list.capacity & 0x80000000)) {
        int bytes = list.capacity & 0x3fffffff;
        Allocator* allocator = g_tls_get_value(DAT_010f3170);
        allocator->FUN_008f6d90(list.data, bytes * 4, 0x17);
    }
    return out;
}

// @f3 0x00a59d00 (community match, verified in this file)
namespace f3m_00a59d00 {
namespace f3m_00a59d00 {
struct Vec4 {
    float x, y, z, w;
    __forceinline Vec4& operator=(const Vec4& value) {
        x = value.x; y = value.y; z = value.z; w = value.w;
        return *this;
    }
};
struct Array {
    Vec4* data;
    int size;
    int capacityAndFlags;
};
void __cdecl FUN_00901e90(Array*, int capacity, int elementSize);
// pdb: hkGeomConvexHullBuilder::removeFlaggedVertices | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a59d00(Array* array)
{
    Vec4* read = array->data;
    Vec4* write = read;
    for (int left = array->size - 1; left >= 0; --left, ++read) {
        if (read->w == 0.0f)
            *write++ = *read;
    }
    int newSize = write - array->data;
    int capacity = array->capacityAndFlags & 0x3fffffff;
    if (capacity < newSize) {
        capacity *= 2;
        if (newSize >= capacity)
            capacity = newSize;
        FUN_00901e90(array, capacity, sizeof(Vec4));
    }
    array->size = newSize;
}
}
}   // namespace f3m_00a59d00

// @f3 0x00a4d550 (community match, verified in this file)
namespace f3m_00a4d550 {
extern "C" __declspec(dllimport) Allocator* __stdcall TlsGetValue(unsigned int) throw();

namespace f3m_00a4d550 {

struct ThreadMemory {
    void* FUN_008f6d30(int size, int memClass) throw();
};

struct CollisionEntry {
    void* m_agentEntry;
    void* m_partner;
};

struct EntryArray {
    CollisionEntry* m_data;
    int m_size;
    int m_capacityAndFlags;
};

struct Collidable {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    EntryArray m_collisionEntries;
};

struct World {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    void* m_collisionInput;
    void* getCollisionInput() const { return m_collisionInput; }
};

struct Entity {
    void* vtbl;
    unsigned short m_memSizeAndFlags;
    unsigned short m_referenceCount;
    World* m_world;
    int unk0c;
    Collidable m_collidable;
};

struct PointerMap {
    void** m_elem;
    int m_numElems;
    int m_hashMod;
    PointerMap(int numElems) throw();
    void FUN_00922cf0() throw();
    void FUN_00922710(void* key, int value) throw();
    int FUN_00922790(void* key) throw();
    bool isValid(int it) const { return it <= m_hashMod; }
};

struct ContactPoints {
    virtual ~ContactPoints() throw();
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    static void* operator new(unsigned int size) {
        ThreadMemory* mem = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        ContactPoints* p = (ContactPoints*)mem->FUN_008f6d30(size, 0xd);
        p->m_memSizeAndFlags = (unsigned short)size;
        return p;
    }
    ContactPoints() throw();
    void removeReference() {
        if (m_memSizeAndFlags != 0) {
            --m_referenceCount;
            if (m_referenceCount == 0)
                delete this;
        }
    }
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    int unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    int unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4;
    int unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104;
    int unk108, unk10c, unk110, unk114, unk118, unk11c;
};

struct System {
    void hkpPhysicsSystemWithContacts_addContact(ContactPoints* obj) throw();
};

int __cdecl FUN_00a4cdf0(void* input, void* agentEntry, void* collisionInput, ContactPoints* out) throw();

}

using namespace f3m_00a4d550;

// pdb: hkpSaveContactPointsUtil::saveContactPoints | hkpSaveContactPointsUtil.obj | fnv360_0822_retail, objrun + skyrim(objrun), high
void __cdecl hkpSaveContactPointsUtil_saveContactPoints(void* input, Entity** entities, int numEntities, System* out)
{
    World* world = entities[0]->m_world;
    PointerMap set(numEntities);
    for (int i = 0; i < numEntities; i++) {
        set.FUN_00922710(&entities[i]->m_collidable, 0);
        EntryArray& entries = entities[i]->m_collidable.m_collisionEntries;
        for (int j = 0; j < entries.m_size; j++) {
            CollisionEntry& entry = entries.m_data[j];
            if (!set.isValid(set.FUN_00922790(entry.m_partner))) {
                ContactPoints* obj = new ContactPoints();
                if (FUN_00a4cdf0(input, entry.m_agentEntry, world->getCollisionInput(), obj) == 0)
                    out->hkpPhysicsSystemWithContacts_addContact(obj);
                obj->removeReference();
            }
        }
    }
    set.FUN_00922cf0();
}
}   // namespace f3m_00a4d550

// @f3 0x00a47ca0 (community match, verified in this file)
extern const char DAT_00e86244[];
extern const char DAT_00e86238[];
namespace f3m_00a47ca0 {

namespace f3m_00a47ca0 {

void __cdecl FUN_00923500(void* p, int v, int n);
void __cdecl FUN_00901e90(void* array, int numElements, int elementSize);

struct PackfileHeader
{
    int m_magic[2];
    int m_userTag;
    int m_fileVersion;
    int m_layoutRules;
    int m_numSections;
    int m_contentsSectionIndex;
    int m_contentsSectionOffset;
    int m_contentsClassNameSectionIndex;
    int m_contentsClassNameSectionOffset;
    int m_contentsVersion[4];
    int m_flags;
    int m_pad;

    PackfileHeader()
    {
        FUN_00923500(this, -1, sizeof(*this));
        m_magic[0] = 0x57e0e057;
        m_magic[1] = 0x10c0c010;
        *(char*)m_contentsVersion = 0;
    }
};

struct PackfileSectionHeader
{
    int m_sectionTag[5];
    int m_absoluteDataStart;
    int m_localFixupsOffset;
    int m_globalFixupsOffset;
    int m_virtualFixupsOffset;
    int m_exportsOffset;
    int m_importsOffset;
    int m_endOffset;

    int getLocalSize() const { return m_globalFixupsOffset - m_localFixupsOffset; }
};

__declspec(noinline) const char* __cdecl FUN_00a45ef0(const PackfileHeader* header)
{
    const char* version = (const char*)header->m_contentsVersion;
    if (*version != (char)0xff)
        return version;
    if (header->m_fileVersion == 1)
        return DAT_00e86244;
    return header->m_fileVersion == 2 ? DAT_00e86238 : 0;
}

__declspec(noinline) void __cdecl FUN_00a45e90(PackfileSectionHeader* sections, int numSections);   // 0x00a45e90 is its own row

struct ClassN
{
    const char* m_name;
    const char* FUN_009b0490() const;
};

template <class T> struct ArrayN
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;

    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = n < cap2 ? cap2 : n;
            FUN_00901e90(this, newSize, sizeof(T));
        }
        m_size = n;
    }
    T& operator[](int i) { return m_data[i]; }
};

class Reader
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
    virtual void setContentsVersion(const char* version);
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual const ClassN* getClass(int sectionIndex, int offset);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    PackfileHeader* m_header;
    PackfileSectionHeader* m_sections;
    ArrayN<void*> m_sectionData;

    int FUN_00a476e0();
    int FUN_00a47ca0(void* data, int dataSize);
};

int Reader::FUN_00a47ca0(void* data, int dataSize)
{
    PackfileHeader magic;
    PackfileHeader* header = static_cast<PackfileHeader*>(data);
    if (header->m_magic[0] == magic.m_magic[0] && header->m_magic[1] == magic.m_magic[1])
    {
        m_header = header;
        setContentsVersion(FUN_00a45ef0(header));
        m_sections = m_header->m_numSections > 0 ? reinterpret_cast<PackfileSectionHeader*>(header + 1) : 0;
        if (m_header->m_fileVersion < 4)
        {
            FUN_00a45e90(m_sections, m_header->m_numSections);
        }
        m_sectionData.setSize(m_header->m_numSections);
        for (int sectionIndex = 0; sectionIndex < m_header->m_numSections; ++sectionIndex)
        {
            PackfileSectionHeader& section = m_sections[sectionIndex];
            char* dataBegin = static_cast<char*>(data) + section.m_absoluteDataStart;
            int* localFixups = reinterpret_cast<int*>(dataBegin + section.m_localFixupsOffset);
            for (int i = 0; i < section.getLocalSize() / (int)sizeof(int); i += 2)
            {
                int srcOff = localFixups[i];
                if (srcOff == -1)
                    continue;
                int dstOff = localFixups[i + 1];
                *reinterpret_cast<char**>(dataBegin + srcOff) = dataBegin + dstOff;
            }
            m_sectionData[sectionIndex] = dataBegin;
        }
        int nameIndex = m_header->m_contentsClassNameSectionIndex;
        int nameOffset = m_header->m_contentsClassNameSectionOffset;
        if (nameIndex >= 0 && nameOffset >= 0 && m_header->m_fileVersion < 3)
        {
            const char* name = getClass(nameIndex, nameOffset)->FUN_009b0490();
            m_header->m_contentsClassNameSectionOffset = name - static_cast<char*>(m_sectionData[nameIndex]);
        }
        return FUN_00a476e0();
    }
    return 1;
}

}
}   // namespace f3m_00a47ca0

// @f3 0x00a5e610 (community match, verified in this file)
extern float FUN_00dbe7bc;
namespace f3m_00a5e610 {
struct Vertex_cf { float x, y, z, w; };
struct EdgeRef_cf { unsigned short idx; unsigned short alt; unsigned short link; unsigned short unk6; };
struct Ent_cf { const EdgeRef_cf* edge; float d; };
struct EntArray_cf { Ent_cf* data; int size; int capacity; };
struct Src_cf { Vertex_cf* verts; EdgeRef_cf* edges; int unk08; };
struct Seed_cf { unsigned short unk0; unsigned short idx; };

float FUN_00a58460(void* a1, Vertex_cf* v, void* a3, void* a6, void* a7);
void FUN_00a5de20(void* a1, Src_cf* s, void* a3, Seed_cf* seed, void* a6, void* a7, EntArray_cf* out);
void FUN_00901e90(void* arr, int newcap, int elem);
void FUN_00a600a0(Ent_cf* data, int lo, int hi, void* cmp);
void FUN_00a58ad0();

// pdb: hkGeomConvexHullBuilder::findWeightedNeighbours | hkGeomConvexHullBuilder.obj | tesv_win, caller_sim, low
void FUN_00a5e610(void* a1, Src_cf* s, void* a3, unsigned short a4, Seed_cf* seed, void* a6, void* a7, EntArray_cf* out)
{
    if (s->unk08 == 1)
        return;
    EdgeRef_cf* edges = s->edges;
    Vertex_cf* verts = s->verts;
    EdgeRef_cf* first = edges + seed->idx;
    EdgeRef_cf* it = first;
    do {
        float d;
        if (it->idx == a4)
            d = FUN_00dbe7bc;
        else
            d = FUN_00a58460(a1, &verts[it->idx], a3, a6, a7);
        int size = out->size;
        int n = size + 1;
        int cap = out->capacity & 0x3fffffff;
        if (cap < n) {
            int nc = cap * 2;
            if (n >= nc)
                nc = n;
            FUN_00901e90(out, nc, 8);
        }
        Ent_cf* slot = &out->data[size];
        out->size = n;
        slot->d = d;
        slot->edge = it;
        it = edges + edges[it->link].alt;
    } while (it != first);
    if (out->size > 1)
        FUN_00a600a0(out->data, 0, out->size - 1, (void*)FUN_00a58ad0);
    FUN_00a5de20(a1, s, a3, seed, a6, a7, out);
}
}   // namespace f3m_00a5e610

// @f3 0x00a49730 (community match, verified in this file)
namespace f3m_00a49730 {
int __cdecl hkString_strCmp(const char* a, const char* b);

struct XmlElement_9730;
struct XmlNode_9730 {
    int unk00;
    int unk04;
    int type;
    const char* name;
    const char* cString() const { return name; }
    XmlElement_9730* asElement() { return type == 1 ? (XmlElement_9730*)this : 0; }
    XmlNode_9730* asEnd() { return type == 2 ? this : 0; }
};
struct XmlElement_9730 : XmlNode_9730 {
    const char* FUN_00a80eb0(const char* attribute, const char* defaultValue);
};

static __declspec(noinline) bool FUN_00a48420(const char* className)
{
    if (className && hkString_strCmp(className, "hkClass") && hkString_strCmp(className, "hkClassMember")
        && hkString_strCmp(className, "hkClassEnum") && hkString_strCmp(className, "hkClassEnumItem"))
        return true;
    return false;
}

struct XmlReader_9730 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_depth;
    int m_readObjects;
    int m_stop;
    int FUN_00a81960(XmlNode_9730** node, void* stream);
    int FUN_00a49670(XmlElement_9730* element, XmlNode_9730** node, void* stream);
    int FUN_00a49730(XmlNode_9730** node, void* stream);
};

// pdb: _newNode | hkStreamStatisticsCollector.obj | fnv360_0822_retail, caller_sim, low
int XmlReader_9730::FUN_00a49730(XmlNode_9730** node, void* stream)
{
    int result = FUN_00a81960(node, stream);
    if (result == 0 && m_stop == 0) {
        if (XmlElement_9730* element = (*node)->asElement()) {
            const char* className = element->FUN_00a80eb0("class", 0);
            if (!(m_depth > 0) && (hkString_strCmp(element->cString(), "hkobject") || FUN_00a48420(className))) {
                if (m_readObjects && !hkString_strCmp(element->cString(), "hkobject") && FUN_00a48420(className))
                    result = FUN_00a49670(element, node, stream);
            } else {
                m_depth++;
                if (!hkString_strCmp(element->cString(), "hkparam") && !hkString_strCmp("attributes", element->FUN_00a80eb0("name", 0))) {
                    m_depth--;
                    result = FUN_00a49670(element, node, stream);
                }
            }
        } else if ((*node)->asEnd()) {
            if (m_depth > 0)
                m_depth--;
        }
    }
    return result;
}
}   // namespace f3m_00a49730

// @f3 0x00a58b30 (community match, verified in this file)
namespace f3m_00a58b30 {
namespace f3m_00a58b30 {
struct Vec4 {
    float x,y,z,w;
    __forceinline Vec4& operator=(const Vec4& value) {
        x=value.x; y=value.y; z=value.z; w=value.w;
        return *this;
    }
};
struct Array { Vec4* data; int size; };
struct Bounds { Vec4 minimum, maximum; };
__forceinline float MinValue(float a, float b) { return a < b ? a : b; }
__forceinline float MaxValue(float a, float b) { return a > b ? a : b; }
// pdb: hkGeomConvexHullBuilder::getAabb | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a58b30(const Array* array, Bounds* bounds)
{
    if (array->size <= 0)
        return;
    bounds->minimum = array->data[0];
    bounds->maximum = array->data[0];
    for (int i=0; i<array->size; ++i) {
        bounds->minimum.x = MinValue(bounds->minimum.x, array->data[i].x);
        bounds->maximum.x = MaxValue(bounds->maximum.x, array->data[i].x);
        bounds->minimum.y = MinValue(bounds->minimum.y, array->data[i].y);
        bounds->maximum.y = MaxValue(bounds->maximum.y, array->data[i].y);
        bounds->minimum.z = MinValue(bounds->minimum.z, array->data[i].z);
        bounds->maximum.z = MaxValue(bounds->maximum.z, array->data[i].z);
    }
}
}
}   // namespace f3m_00a58b30

// @f3 0x00a4c480 (community match, verified in this file)
namespace f3m_00a4c480_w {
extern unsigned long DAT_010f3170;
extern const char DAT_00e40028[];
extern const char DAT_00e3be04[];
extern const char DAT_00e86404[];
struct Heap_a4c4 { void FUN_008f6d90(void* p, int size, int tag) throw(); };
__declspec(nothrow) void __cdecl FUN_00901e90(void* array, int capacity, int elementSize) throw();
__declspec(nothrow) void __cdecl FUN_009234e0(void* dst, const void* src, int bytes) throw();

struct Bool_a4c4
{
    char value;
    Bool_a4c4(bool b) : value(b) {}
};

template <class T> struct Array_a4c4
{
    T* data;
    int size;
    int capacity;
    Array_a4c4() : data(0), size(0), capacity(0x80000000) {}
    void release() throw()
    {
        if ((capacity & 0x80000000) == 0)
        {
            int count = capacity & 0x3fffffff;
            Writer2110::Heap* heap = Writer2110::GetHeap();
            heap->FUN_008f6d90(data, count * sizeof(T), 0x17);
        }
    }
    void reserve(int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    void pushBackUnchecked(const T& value)
    {
        data[size] = value;
        size++;
    }
    T* expandByUnchecked(int n)
    {
        int oldSize = size;
        size = oldSize + n;
        return data + oldSize;
    }
};

struct PlainArray_a4c4
{
    void* data;
    int size;
    int capacity;
    PlainArray_a4c4() : data(0), size(0), capacity(0x80000000) {}
};

struct Info_a4c4
{
    PlainArray_a4c4 a00;
    PlainArray_a4c4 a0C;
    PlainArray_a4c4 a18;
    PlainArray_a4c4 a24;
    int unk30;
    Info_a4c4() : unk30(0) {}
    __declspec(nothrow) void FUN_009b2fd0() throw();
};

struct Class_a4c4 { const char* FUN_009b0490() const throw(); };

struct Stream_a4c4
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    __declspec(nothrow) virtual Bool_a4c4 isOk() const throw();
};

struct Writer_a4c4
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    __declspec(nothrow) virtual void writeObject(Stream_a4c4* stream, const void* object, const Class_a4c4* klass, Info_a4c4* info) throw();
    __declspec(nothrow) void FUN_00a4b980(Stream_a4c4* stream, const char* name, const char** attributes, Bool_a4c4 newline) throw();
    __declspec(nothrow) void FUN_00a4ba40(Stream_a4c4* stream, const char* name, Bool_a4c4 newline) throw();
    int FUN_00a4c480(Stream_a4c4* stream, const void* object, const Class_a4c4* klass, const char* version, const char** extras);
};

int Writer_a4c4::FUN_00a4c480(Stream_a4c4* stream, const void* object, const Class_a4c4* klass, const char* version, const char** extras)
{
    int numExtras = 0;
    if (extras)
    {
        while (extras[numExtras])
            ++numExtras;
    }
    Array_a4c4<const char*> attributes;
    attributes.reserve(numExtras + 5);
    if (version)
    {
        attributes.pushBackUnchecked(DAT_00e40028);
        attributes.pushBackUnchecked(version);
    }
    attributes.pushBackUnchecked(DAT_00e3be04);
    attributes.pushBackUnchecked(klass->FUN_009b0490());
    if (extras)
        FUN_009234e0(attributes.expandByUnchecked(numExtras), extras, numExtras * sizeof(const char*));
    attributes.pushBackUnchecked(0);
    FUN_00a4b980(stream, DAT_00e86404, attributes.data, true);
    Info_a4c4 info;
    writeObject(stream, object, klass, &info);
    FUN_00a4ba40(stream, DAT_00e86404, true);
    int result = stream->isOk().value == 0;
    info.FUN_009b2fd0();
    attributes.release();
    return result;
}
}

// @f3 0x00a5d5d0 (community match, verified in this file)
namespace f3m_00a5d5d0 {
namespace na5d5d0 {
struct hkThreadMemory {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* AllocateStackSlow(int nbytes) throw();
    virtual void PopStack(void* p) throw();
    int unk04[7];
    char* m_current;
    int unk24;
    char* m_previous;
    char* m_end;
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    void* AllocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* current = m_current;
        char* next = current + aligned;
        if (next <= m_end)
        {
            m_current = next;
            return current;
        }
        return AllocateStackSlow(aligned);
    }
    void DeallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_previous)
            PopStack(p);
    }
};
inline hkThreadMemory* GetThreadMemory() { return (hkThreadMemory*)TlsGetValue(DAT_010f3170); }
extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int stride);

struct LocalIntArray {
    int* m_data;
    int m_size;
    int m_capacityAndFlags;
    int m_initialCapacity;
    LocalIntArray(int n)
    {
        m_data = (int*)GetThreadMemory()->AllocateStack(n * sizeof(int));
        m_size = n;
        m_capacityAndFlags = n | 0x80000000;
        m_initialCapacity = n;
    }
    ~LocalIntArray()
    {
        GetThreadMemory()->DeallocateStack(m_data);
        if ((m_capacityAndFlags & 0x80000000) == 0)
            GetThreadMemory()->FUN_008f6d90(m_data, (m_capacityAndFlags & 0x3fffffff) * sizeof(int), 0x17);
    }
    int& operator[](int i) { return m_data[i]; }
};
struct Vec4 { float x, y, z, w; };
struct VertArray {
    Vec4* m_data;
    int m_size;
    int m_capacityAndFlags;
};
struct Triangle {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
};
struct TriList {
    int unk00;
    Triangle* m_data;
    int m_size;
};

// pdb: hkGeomConvexHullBuilder::removeUnusedVertices | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
void __cdecl FUN_00a5d5d0(TriList* tris, VertArray* verts)
{
    for (int i = 0; i < tris->m_size; i++)
        verts->m_data[tris->m_data[i].a].w = 2.0f;

    {
    LocalIntArray remap(verts->m_size);

    int count = 0;
    for (int j = 0; j < verts->m_size; j++) {
        Vec4* v = verts->m_data;
        if (v[j].w == 2.0f) {
            v[count].x = v[j].x;
            v[count].y = v[j].y;
            v[count].z = v[j].z;
            v[count].w = v[j].w;
            remap[j] = count;
            count++;
        } else {
            remap[j] = -1;
        }
    }

    int cap = verts->m_capacityAndFlags & 0x3fffffff;
    if (cap < count) {
        int c2 = cap * 2;
        FUN_00901e90(verts, count < c2 ? c2 : count, sizeof(Vec4));
    }
    verts->m_size = count;

    for (int k = 0; k < tris->m_size; k++) {
        Triangle* t = &tris->m_data[k];
        t->a = (unsigned short)remap[t->a];
    }

    }

    for (int m = 0; m < tris->m_size; m++)
        verts->m_data[tris->m_data[m].a].w = 0.0f;
}
}
}   // namespace f3m_00a5d5d0

// @f3 0x00a48380 (community match, verified in this file)
namespace f3m_00a48380 {
struct Heap48380 { void FUN_008f6d90(void*, unsigned int, int); };

struct Obj48380 {
    unsigned int unk00;
    unsigned short unk04;
    void FUN_00a473b0();
    Obj48380* FUN_00a48380(unsigned char flags);
};
Obj48380* Obj48380::FUN_00a48380(unsigned char flags)
{
    FUN_00a473b0();
    if (flags & 1) {
        Heap48380* heap = (Heap48380*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(this, unk04, 6);
    }
    return this;
}
}   // namespace f3m_00a48380

// @f3 0x00a46000 (community match, verified in this file)
namespace f3m_00a46000 {
struct Elem48 { int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C; };
struct Owner_00a46000 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Elem48* unk20;
    Elem48* FUN_00a46000(int index);
};
// pdb: hkbCharacter::setPoseLocalInternal | hkbCharacter.obj | tesv_win, objrun_open, low
Elem48* Owner_00a46000::FUN_00a46000(int index)
{
    return &unk20[index];
}
}   // namespace f3m_00a46000

// @f3 0x00a494d0 (community match, verified in this file)
namespace f3m_00a494d0 {
struct A494d0 {
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

    void FUN_00a81010(int arg1, int arg2, int arg3);
    void FUN_00a494d0(int arg1, int arg2, int arg3);
};

void A494d0::FUN_00a494d0(int arg1, int arg2, int arg3)
{
    unk28 += 1;
    FUN_00a81010(arg1, arg2, arg3);
    unk28 += -1;
}
}   // namespace f3m_00a494d0

// @f3 0x00a4b860 (community match, verified in this file)
namespace f3m_00a4b860 {
void __fastcall FUN_00a4b800(int value);
// pdb: hkArrayBase<hkPackfileWriter::PendingWrite>::hkArrayBase<hkPackfileWriter::PendingWrite> | hkPackfileWriter.obj | fnv360_0822_debug, objrun_open, low
void __cdecl FUN_00a4b860() {
    FUN_00a4b800(1);
}
}   // namespace f3m_00a4b860

// @f3 0x00a48530 (community match, verified in this file)
namespace f3m_00a48530 {
struct FUN_00a48530_owner {
    virtual int vfn00();
    virtual int vfn01();
    virtual int vfn02();
    virtual int vfn03();
    virtual int vfn04();
    virtual int vfn05();
    virtual int vfn06();
    virtual int vfn07();
    virtual int vfn08();
    virtual int vfn09();
    virtual int vfn10();
    virtual int vfn11();
    virtual int vfn12(int a, int b);
    int FUN_00a48530(int arg);
};

int FUN_00a48530_owner::FUN_00a48530(int arg)
{
    return vfn12(arg, 0);
}
}   // namespace f3m_00a48530

// @f3 0x00a45c30 (community match, verified in this file)
#include <string.h>
extern int DAT_01092a50;
namespace f3m_00a45c30 {

struct A45c30Element {
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
};

struct A45c30Array {
    A45c30Element* m_data;
    int m_size;
    int m_capacity;
};

struct A45c30Object {
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
    A45c30Array m_array;

    void __thiscall FUN_00a45c30(const A45c30Element* source);
};

extern void __cdecl FUN_00901f10(void*, int);

void __thiscall A45c30Object::FUN_00a45c30(const A45c30Element* source)
{
    A45c30Array* array = &m_array;

    if (array->m_size == (array->m_capacity & 0x3fffffff)) {
        FUN_00901f10(array, 0x38);
    }

    A45c30Element* destination = array->m_data + array->m_size;
    ++array->m_size;

    memcpy(destination, source, sizeof(A45c30Element));

    if (destination->unk20 == 0) {
        destination->unk30 = 1;
        destination->unk28 = (int)&DAT_01092a50;
        destination->unk20 = (int)&DAT_01092a50;
    }
}
}   // namespace f3m_00a45c30

// @f3 0x00a4e360 (community match, verified in this file)
extern double DAT_00e20408;
namespace f3m_00a4e360 {

// pdb: hkpVelocityAccumulator::hkpVelocityAccumulator | hkpBuildJacobianFromAtoms.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: hkInitHeader)
// pdb params: __that
void __cdecl FUN_00a4e360(float* param_1, float* param_2, unsigned int* param_3) {
    float* p = *(float**)param_3;

    p[0] = param_1[0];
    p[1] = param_1[1];
    p[2] = param_1[2];
    p[3] = param_1[3];
    p[4] = param_2[0];
    p[5] = param_2[1];
    p[6] = param_2[2];
    p[7] = param_2[3];

    p[0] = (float)((double)p[0] + DAT_00e20408);
    ((char*)&p[0])[0] = 0x17;

    *param_3 = (unsigned int)(p + 8);
}
}   // namespace f3m_00a4e360

// @f3 0x00a4cac0 (community match, verified in this file)
namespace f3m_00a4cac0 {
extern unsigned long DAT_010f3170;
struct Heap {
    void FUN_008f6f90(void* item) throw();
    void FUN_008f6d90(void* memory, unsigned int bytes, int tag) throw();
};
extern __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned int index);
struct Array {
    void* data;
    int size, capacity;
    void FUN_00922cf0() throw();
    ~Array() throw() { FUN_00922cf0(); }
};
struct PointerArray { void** data; int size, capacity; };
struct Owner {
    Array first, second;
    PointerArray items;
    ~Owner() throw();
};
// pdb: hkPlatformObjectWriter::Cache::~Cache | hkPlatformObjectWriter.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
Owner::~Owner() throw() {
    for (int i=0; i<items.size; ++i) {
        void* item = items.data[i];
        Heap* heap = FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6f90(item);
    }
    if (((unsigned int)items.capacity & 0x80000000u) == 0) {
        unsigned int capacity = (unsigned int)items.capacity & 0x3fffffff;
        Heap* heap = FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(items.data, capacity * sizeof(void*), 0x17);
    }
}
}

// @f3 0x00a49bb0 (community match, verified in this file)
namespace f3m_00a49bb0 {

struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;

struct Obj {
    int unk00;
    unsigned short size;

    void FUN_00a49b40() throw();
    Obj* FUN_00a49bb0(unsigned int flags);
};

Obj* Obj::FUN_00a49bb0(unsigned int flags)
{
    FUN_00a49b40();
    if (flags & 1) {
        Heap* heap = FUN_00d9b080(::f3m_00a49bb0::DAT_010f3170);
        heap->FUN_008f6d90(this, size, 6);
    }
    return this;
}

}

// @f3 0x00a559a0 (community match, verified in this file)
namespace f3m_00a559a0 {

struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;

struct Obj {
    int unk00;
    unsigned short size;

    void FUN_00a558b0() throw();
    Obj* FUN_00a559a0(unsigned int flags);
};

// pdb: hkpMoppCachedShapeMediator::`scalar deleting destructor' | hkpMoppCachedShapeMediator.obj | fnv360_0822_retail, vtable, high
Obj* Obj::FUN_00a559a0(unsigned int flags)
{
    FUN_00a558b0();
    if (flags & 1) {
        Heap* heap = FUN_00d9b080(::f3m_00a559a0::DAT_010f3170);
        heap->FUN_008f6d90(this, size, 0x28);
    }
    return this;
}

}

// @f3 0x00a460a0 (community match, verified in this file)
namespace f3m_00a460a0 {
namespace f3m_00a460a0 {

struct Cell { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c; int x, y; };

struct Grid {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34();
    virtual void* GetAt(int x, int y);
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    Cell* cell;
    void* FUN_00a460a0();
};

void* Grid::FUN_00a460a0()
{
    int x = cell->x;
    int y = cell->y;
    if (x >= 0 && y >= 0)
        return GetAt(x, y);
    return 0;
}

}
}   // namespace f3m_00a460a0

// @f3 0x00a484b0 (community match, verified in this file)
namespace f3m_00a484b0 {

int __cdecl hkString_atoi(const char* text);
const char* __cdecl FUN_00923640(const char* text);

struct XmlElement {
    const char* FUN_00a80eb0(const char* attribute, const char* defaultValue);
};

static __declspec(noinline) int FUN_00a484b0(int* classVersion, XmlElement* element, const char** contentsVersion)
{
    const char* text = element->FUN_00a80eb0("classversion", 0);
    if (text) {
        int version = hkString_atoi(text);
        *classVersion = version;
        if (version != 1) {
            if (version < 2 || version > 5)
                return 1;
            const char* contents = element->FUN_00a80eb0("contentsversion", 0);
            if (contents) {
                *contentsVersion = FUN_00923640(contents);
                return 0;
            }
            *contentsVersion = FUN_00923640("Havok-3.1.0");
            return 0;
        }
    }
    *contentsVersion = FUN_00923640("Havok-3.0.0");
    return 0;
}

extern int* volatile g_classVersion;
extern XmlElement* volatile g_element;
extern const char** volatile g_contents;
int caller_of_FUN_00a484b0() { return FUN_00a484b0(g_classVersion, g_element, g_contents); }

}

// @f3 0x00a4cb40 (community match, verified in this file)
namespace f3m_00a4cb40 {

struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);
extern unsigned long DAT_010f3170;

struct Obj {
    int unk00;
    unsigned short size;

    void FUN_00a4c9c0() throw();
    Obj* FUN_00a4cb40(unsigned int flags);
};

// pdb: hkPlatformObjectWriter::`scalar deleting destructor' | hkPlatformObjectWriter.obj | fnv360_0822_retail, vtable, high
Obj* Obj::FUN_00a4cb40(unsigned int flags)
{
    FUN_00a4c9c0();
    if (flags & 1) {
        Heap* heap = FUN_00d9b080(::f3m_00a4cb40::DAT_010f3170);
        heap->FUN_008f6d90(this, size, 6);
    }
    return this;
}

}

// @f3 0x00a47f80 (community match, verified in this file)
namespace f3m_00a47f80 {
namespace f3m_00a47f80 {
extern void __cdecl FUN_00901f10(void*, int);
template<class T> struct Array {
    T* data;
    int size;
    int capacity;
    void append(const T& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
};
struct Target { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18; Array<void*> items; };
struct Owner {
    void* vtable;
    int unk04;
    Target* target;
    void FUN_00a47f80(void* item);
};
void Owner::FUN_00a47f80(void* item)
{
    target->items.append(item);
}
}
}   // namespace f3m_00a47f80

// @f3 0x00a4ba40 (community match, verified in this file)
namespace f3m_00a4ba40 {
namespace f3m_00a4ba40 {
struct Bool { char value; };
int __cdecl FUN_009233f0(const char* text);
struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Bool isOk() const throw();
    virtual int write(const void* data, int size) throw();
};
struct Writer {
    void* vtable;
    int unk04;
    const char* indent;
    int indentLength;
    void FUN_00a4b900(int delta) throw();
    void FUN_00a4ba40(Stream* stream, const char* name, Bool newline) throw();
};
void Writer::FUN_00a4ba40(Stream* stream, const char* name, Bool newline) throw()
{
    FUN_00a4b900(-1);
    if (newline.value) {
        stream->write("\n", 1);
        stream->write(indent, indentLength);
    }
    stream->write("</", 2);
    stream->write(name, FUN_009233f0(name));
    stream->write(">", 1);
}
}
}   // namespace f3m_00a4ba40

// @f3 0x00a4b920 (community match, verified in this file)
extern void* const DAT_00e86754[];
namespace f3m_00a4b920 {
namespace f3m_00a4b920 {
extern void __cdecl FUN_00901f10(void*, int);
struct hkReferencedObject {
    void* const* vptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    hkReferencedObject() { referenceCount = 1; }
};
struct WriterBase : hkReferencedObject {
    WriterBase() { vptr = DAT_00e86754; }
};
struct CharBuffer {
    char* data;
    int size;
    int capacityAndFlags;
    char storage[16];
    CharBuffer() { data = storage; size = 0; capacityAndFlags = 0x80000010; }
    void pushBack(char c)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 1);
        data[size] = c;
        size++;
    }
    void popBack() { size--; }
};
struct Stream;
struct Writer : WriterBase {
    CharBuffer buffer;
    Stream* stream;
    Writer(Stream* s);
};
Writer::Writer(Stream* s) : stream(s)
{
    buffer.pushBack(0);
    buffer.popBack();
}
}
}   // namespace f3m_00a4b920

// @f3 0x00a45e40 (community match, verified in this file)
namespace f3m_00a45e40 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a45e40Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a45e40 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_009d6c00();
    D00a45e40* FUN_00a45e40(unsigned int flags);
};
// pdb: hkpMeshShape::`scalar deleting destructor' | hkpMeshShape.obj | fnv360_0822_retail, vtable_prefix, high
D00a45e40* D00a45e40::FUN_00a45e40(unsigned int flags)
{
    FUN_009d6c00();
    if (flags & 1) {
        D00a45e40Heap* heap = (D00a45e40Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x27);
    }
    return this;
}
}

// @f3 0x00a481d0 (community match, verified in this file)
namespace f3m_00a481d0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a481d0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a481d0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a48150();
    D00a481d0* FUN_00a481d0(unsigned int flags);
};
D00a481d0* D00a481d0::FUN_00a481d0(unsigned int flags)
{
    FUN_00a48150();
    if (flags & 1) {
        D00a481d0Heap* heap = (D00a481d0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}

// @f3 0x00a4a510 (community match, verified in this file)
namespace f3m_00a4a510 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a4a510Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a4a510 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a49be0();
    D00a4a510* FUN_00a4a510(unsigned int flags);
};
// pdb: hkIstream::`scalar deleting destructor' | hkIStream.obj | fnv360_0822_retail, vtable, high
D00a4a510* D00a4a510::FUN_00a4a510(unsigned int flags)
{
    FUN_00a49be0();
    if (flags & 1) {
        D00a4a510Heap* heap = (D00a4a510Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x1a);
    }
    return this;
}
}

// @f3 0x00a54f10 (community match, verified in this file)
namespace f3m_00a54f10 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a54f10Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a54f10 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a54b10();
    D00a54f10* FUN_00a54f10(unsigned int flags);
};
// pdb: hkpMoppShapeMediator::`scalar deleting destructor' | hkpMoppShapeMediator.obj | fnv360_0822_retail, vtable, high
D00a54f10* D00a54f10::FUN_00a54f10(unsigned int flags)
{
    FUN_00a54b10();
    if (flags & 1) {
        D00a54f10Heap* heap = (D00a54f10Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x28);
    }
    return this;
}
}

// @f3 0x00a49510 (community match, verified in this file)
namespace f3m_00a49510 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a49510Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a49510 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a813d0();
    D00a49510* FUN_00a49510(unsigned int flags);
};
D00a49510* D00a49510::FUN_00a49510(unsigned int flags)
{
    FUN_00a813d0();
    if (flags & 1) {
        D00a49510Heap* heap = (D00a49510Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 6);
    }
    return this;
}
}

// @f3 0x00a49870 (community match, verified in this file)
namespace f3m_00a49870 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a49870Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a49870 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a486d0();
    D00a49870* FUN_00a49870(unsigned int flags);
};
D00a49870* D00a49870::FUN_00a49870(unsigned int flags)
{
    FUN_00a486d0();
    if (flags & 1) {
        D00a49870Heap* heap = (D00a49870Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 6);
    }
    return this;
}
}

// @f3 0x00a54ad0 (community match, verified in this file)
namespace f3m_00a54ad0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a54ad0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
extern void* DAT_00dcc494[];
struct D00a54ad0 {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    D00a54ad0* FUN_00a54ad0(unsigned int flags);
};
// pdb: hkpMoppCostFunction::`scalar deleting destructor' | hkpMoppCostFunction.obj | fnv360_0721_beta, vtable, medium
D00a54ad0* D00a54ad0::FUN_00a54ad0(unsigned int flags)
{
    vtable = DAT_00dcc494;
    if (flags & 1) {
        D00a54ad0Heap* heap = (D00a54ad0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x28);
    }
    return this;
}
}

// @f3 0x00a486b0 (community match, verified in this file)
namespace f3m_00a486b0 {
namespace f3m_00a486b0 {
struct Inner { void FUN_009227d0(int value, int flag); };
struct Shared {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Inner inner;
    int unk2c, unk30;
    int value;
};
struct Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    Shared* shared;
    void FUN_00a486b0();
};
}

void f3m_00a486b0::Owner::FUN_00a486b0()
{
    shared->inner.FUN_009227d0(shared->value, 0);
}
}   // namespace f3m_00a486b0

// @f3 0x00a495e0 (community match, verified in this file)
namespace f3m_00a495e0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
struct D00a495e0Heap { void FUN_008f6d90(void* p, unsigned int size, unsigned int tag); };
struct D00a495e0 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    void FUN_00a49540();
    D00a495e0* FUN_00a495e0(unsigned int flags);
};
D00a495e0* D00a495e0::FUN_00a495e0(unsigned int flags)
{
    FUN_00a49540();
    if (flags & 1) {
        D00a495e0Heap* heap = (D00a495e0Heap*)DAT_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 5);
    }
    return this;
}
}

// @f3 0x00a45d00 (community match, verified in this file)
extern void* const DAT_00e861dc[];
extern void* const DAT_00e861b8[];
namespace f3m_00a45d00 {
namespace f3m_00a45d00 {
struct hkArray {
    void* data;
    int size;
    int capacityAndFlags;
    hkArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
};
struct __declspec(align(16)) Vec4 { float x, y, z, w; void set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
struct Base {
    void* const* vptr;
    int unk04, unk08, unk0c;
    void* const* vptr2;
    int unk14, unk18, unk1c;
    Base(int type);
};
struct Mid : Base {
    Mid() : Base(0x16) { vptr = DAT_00e861dc; vptr2 = DAT_00e861b8; }
};
struct Action : Mid {
    Vec4 scale;
    void* entity;
    hkArray first;
    hkArray second;
    unsigned char kind;
    float strength;
    Action(float strength, void* entity);
};
// pdb: hkpMeshShape::hkpMeshShape | hkpMeshShape.obj | fnv360_0822_retail, call_gap, high
// pdb params: radius, numBitsForSubpartIndex
Action::Action(float s, void* e)
{
    scale.set(1.0f, 1.0f, 1.0f, 1.0f);
    entity = e;
    kind = 6;
    strength = s;
}
}
}   // namespace f3m_00a45d00

// @f3 0x00a461c0 (community match, verified in this file)
namespace f3m_00a461c0 {
struct HashTable461 {
    int FUN_009227d0(int key, int hint);
};
struct Obj461 {
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
};
struct Sub461 {
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
    HashTable461 hashTable;
    int unk2c;
    int unk30;
    int unk34;
};
struct Cls461 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Obj461* unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    Sub461* unk78;
    int FUN_00a460a0();
    int FUN_00a461c0();
};
int Cls461::FUN_00a461c0() {
    Sub461* sub = unk78;
    if (sub != 0)
        return sub->hashTable.FUN_009227d0(sub->unk34, 0);
    return FUN_00a460a0();
}
}   // namespace f3m_00a461c0

// @f3 0x00a48200 (community match, verified in this file)
namespace f3m_00a48200 {
namespace f3m_00a48200 {
extern void __cdecl FUN_00901f10(void*, int);
struct Entry { const char* name; void* object; int type; };
struct EntryArray {
    Entry* data;
    int size;
    int capacity;
    void pushBack(const Entry& e)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(Entry));
        data[size] = e;
        size++;
    }
};
struct Registry { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24; EntryArray entries; };
struct Writer {
    void* vtable;
    int unk04;
    Registry* registry;
    const char* lastName;
    void* lastObject;
    void FUN_00a48200(const char* name, void* object, int type);
};
void Writer::FUN_00a48200(const char* name, void* object, int type)
{
    Entry e;
    e.name = name;
    e.object = object;
    e.type = type;
    registry->entries.pushBack(e);
    lastName = name;
    lastObject = object;
}
}
}   // namespace f3m_00a48200

// @f3 0x00a56770 (community match, verified in this file)
namespace f3m_00a56770 {
namespace f3m_00a56770 {
struct A5677Target {
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03(); virtual void V04();
    virtual void V05(); virtual void V06(); virtual void V07(); virtual void V08(); virtual void V09();
};
struct A5677Owner {
    int unk00[6];
    A5677Target* unk18;
    void FUN_00a56770();
};
// pdb: hkpConvexTranslateShape::getNumCollisionSpheresImpl | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, low
void A5677Owner::FUN_00a56770()
{
    unk18->V09();
}
}
}   // namespace f3m_00a56770

// @f3 0x00a483b0 (community match, verified in this file)
namespace f3m_00a483b0 {
namespace f3m_00a483b0 {
struct A483Obj { virtual ~A483Obj(); };
void FUN_00a483b0(A483Obj** holder)
{
    if (*holder)
        delete *holder;
}
}
}   // namespace f3m_00a483b0

// @f3 0x00a48890 (community match, verified in this file)
namespace f3m_00a48890 {
extern unsigned long DAT_010f3170;
extern char DAT_00e86280;   // the class entry appended first
struct ThreadMemory { void* FUN_008f6d30(int size, int tag) throw(); };
void __cdecl FUN_00901f10(void* array, int elementSize) throw();   // hkArray grow
struct Flag { char value; Flag(bool b) : value(b) {} };
template <class T> struct Array {
    T* data;
    int size;
    int capacity;
    Array() throw() : data(0), size(0), capacity((int)0x80000000) {}
    T& back() throw() { return data[size - 1]; }
    void append(const T& value) throw()
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
};
struct Pooled {
    static void* operator new(unsigned int size) throw()
    {
        ThreadMemory* memory = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        void* p = memory->FUN_008f6d30(size, 0x15);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void*) {}
};
class FUN_009b1110 {   // registry member, ctor 0x009b1110
public:
    FUN_009b1110(Flag flag) throw();
    void FUN_009b0e60(void* entry, int flags) throw();
    int unk00, unk04, unk08, unk0c;
};
class FUN_00a80240 : public Pooled {
public:
    FUN_00a80240() throw();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
};
class FUN_00a47ee0 : public Pooled {
public:
    FUN_00a47ee0(FUN_00a80240* owner) throw();
    virtual ~FUN_00a47ee0();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
};
class Listener : public FUN_00a47ee0 {
public:
    Listener(FUN_00a80240* owner) throw() : FUN_00a47ee0(owner) {}
    virtual ~Listener();
};
class FUN_00a498f0 {
public:
    FUN_00a498f0() throw();
    virtual ~FUN_00a498f0();
    int unk04, unk08, unk0c, unk10, unk14;
};
}
class FUN_00a48890 : public f3m_00a48890::FUN_00a498f0 {
public:
    FUN_00a48890();
    virtual ~FUN_00a48890();
    f3m_00a48890::FUN_00a80240* world;
    f3m_00a48890::Array<void*> classes;
    f3m_00a48890::FUN_009b1110 registry;
    f3m_00a48890::Array<void*> extra;
    f3m_00a48890::Listener* listener;
};

FUN_00a48890::FUN_00a48890() : registry(f3m_00a48890::Flag(false))
{
    classes.append(&f3m_00a48890::DAT_00e86280);
    registry.FUN_009b0e60(classes.back(), 0);
    world = new f3m_00a48890::FUN_00a80240;
    listener = new f3m_00a48890::Listener(world);
}

// @f3 0x00a45470 (community match, verified in this file)
#include <new>
namespace f3m_00a45470 {
namespace f3m_00a45470 {
struct A4547Obj {
    virtual ~A4547Obj();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A4547Obj() { referenceCount = 1; }
};
void FUN_00a45470(void* p)
{
    new (p) A4547Obj();
}
}
}   // namespace f3m_00a45470

// @f3 0x00a498a0 (community match, verified in this file)
namespace f3m_00a498a0 {
namespace f3m_00a498a0 {
int FUN_009b2df0(int a, int b, int c);
// pdb: hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::clear | hkMap.obj | fnv360_0822_retail via fnv_pc_unpacked, bridge_fnvpc, low
int FUN_00a498a0(int a, int b, int c, int d)
{
    return FUN_009b2df0(a, d, b);
}
}
}   // namespace f3m_00a498a0

// @f3 0x00a45930 (community match, verified in this file)
namespace f3m_00a45930 {
namespace f3m_00a45930 {
struct A4593Vec { float x, y, z, w; };
struct A4593Obj {
    int unk00[8];
    float unk20, unk24, unk28, unk2c;
    void FUN_00a45930(const A4593Vec* v);
};
// pdb: hkpMeshShape::setScaling | hkpMeshShape.obj | tesv_win, objrun_sim, low
void A4593Obj::FUN_00a45930(const A4593Vec* v)
{
    unk20 = v->x;
    unk24 = v->y;
    unk28 = v->z;
    unk2c = v->w;
}
}
}   // namespace f3m_00a45930

// @f3 0x00a498f0 (community match, verified in this file)
namespace f3m_00a498f0 {
namespace f3m_00a498f0 {
struct FUN_00922cb0 { int unk00, unk04, unk08; FUN_00922cb0() throw(); };
struct A498Base {
    virtual ~A498Base();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A498Base() { referenceCount = 1; }
};
struct FUN_00a498f0 : A498Base {
    FUN_00922cb0 unk08;
    int unk14;
    FUN_00a498f0() throw();
    virtual ~FUN_00a498f0();
};
FUN_00a498f0::FUN_00a498f0() throw()
{
    unk14 = 0;
}
}
}   // namespace f3m_00a498f0

// @f3 0x00a4a9c0 (community match, verified in this file)
namespace f3m_00a4a9c0 {
namespace f3m_00a4a9c0 {
struct A4a9Sub { int FUN_00922710(int a, int b); };
struct A4a9Obj {
    int unk00[39];
    A4a9Sub unk9c;
    int FUN_00a4a7b0(int b);
    int hkPackfileWriter_setSectionForPointer(int a, int b);
};
// pdb: hkPackfileWriter::setSectionForPointer | hkPackfileWriter.obj | fnv360_0822_retail, vtable + bridge(vtable|vtable) + skyrim(vtable), high
int A4a9Obj::hkPackfileWriter_setSectionForPointer(int a, int b)
{
    return unk9c.FUN_00922710(a, FUN_00a4a7b0(b));
}
}
}   // namespace f3m_00a4a9c0

// @f3 0x00a4a570 (community match, verified in this file)
namespace f3m_00a4a570 {
namespace f3m_00a4a570 {
int FUN_00923280(char* buf, int size, const char* fmt, int major, int minor, int patch, const char* tag);
// pdb: hkPackfileWriter::getCurrentVersion | hkPackfileWriter.obj | fnv360_0822_retail, ustr, medium
// pdb params: buf, bufLen
int FUN_00a4a570(char* buf, int size)
{
    return FUN_00923280(buf, size, "Havok-%i.%i.%i-%s", 5, 5, 0, "r1");
}
}
}   // namespace f3m_00a4a570

// @f3 0x00a49920 (community match, verified in this file)
namespace f3m_00a49920 {
struct A4992Svc {
    virtual void V00(); virtual void V01(); virtual void V02();
    virtual int V0c();
};
extern A4992Svc* DAT_010f3438;
struct A4992Obj {
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V10(int value, int extra);
    void FUN_00a49920(int value);
};
void A4992Obj::FUN_00a49920(int value)
{
    V10(value, DAT_010f3438->V0c());
}
}

// @f3 0x00a58b00 (community match, verified in this file)
namespace f3m_00a58b00 {
namespace f3m_00a58b00 {
struct A58bBool { char m_bool; A58bBool(bool b) { m_bool = b; } };
struct A58bItem { int unk00[4]; float unk10; };
// pdb: weightedLineLess | hkGeomConvexHullBuilder.obj | tesv_win, hash, low
A58bBool FUN_00a58b00(const A58bItem* a, const A58bItem* b)
{
    return a->unk10 < b->unk10;
}
}
}   // namespace f3m_00a58b00

// @f3 0x00a49be0 (community match, verified in this file)
extern void* DAT_00e86594[];
extern void* DAT_00dcc494[];
namespace f3m_00a49be0 {
namespace f3m_00a49be0 {
struct A49beRef {
    virtual void Del(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                Del(1);
        }
    }
};
struct A49beObj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A49beRef* unk08;
    void FUN_00a49be0();
};
// pdb: hkIstream::~hkIstream | hkIStream.obj | tesv_win, caller, medium
void A49beObj::FUN_00a49be0()
{
    vtable = DAT_00e86594;
    if (unk08)
        unk08->removeReference();
    vtable = DAT_00dcc494;
}
}
}   // namespace f3m_00a49be0

// @f3 0x00a4a110 (community match, verified in this file)
extern void* DAT_00e86594[];
namespace f3m_00a4a110 {
namespace f3m_00a4a110 {
struct A4a11Ref { void** vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct A4a11Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A4a11Ref* unk08;
    A4a11Obj* FUN_00a4a110(A4a11Ref* ref);
};
A4a11Obj* A4a11Obj::FUN_00a4a110(A4a11Ref* ref)
{
    referenceCount = 1;
    vtable = DAT_00e86594;
    unk08 = ref;
    if (ref->memSizeAndFlags != 0)
        ref->referenceCount += 1;
    return this;
}
}
}   // namespace f3m_00a4a110

// @f3 0x00a56a00 (community match, verified in this file)
namespace f3m_00a56a00 {
namespace f3m_00a56a00 {
struct V00a56a00 { float x, y, z, w; };
struct S00a56a00 {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0a();
    virtual void V0b();
    virtual void V0c();
    virtual void V0d();
    virtual void V0e();
    virtual void Vx(V00a56a00* v);
};
struct O00a56a00 {
    int unk00[6];
    S00a56a00* unk18;
    int unk1c;
    float unk20, unk24, unk28, unk2c;
    void FUN_00a56a00(V00a56a00* v);
};
// pdb: hkpConvexTranslateShape::getCentreImpl | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: centreOut
void O00a56a00::FUN_00a56a00(V00a56a00* v)
{
    unk18->Vx(v);
    v->x += unk20;
    v->y += unk24;
    v->z += unk28;
    v->w += unk2c;
}
}
}   // namespace f3m_00a56a00

// @f3 0x00a56a40 (community match, verified in this file)
namespace f3m_00a56a40 {
namespace f3m_00a56a40 {
struct V00a56a40 { float x, y, z, w; };
struct S00a56a40 {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0a();
    virtual void Vx(V00a56a40* v);
};
struct O00a56a40 {
    int unk00[6];
    S00a56a40* unk18;
    int unk1c;
    float unk20, unk24, unk28, unk2c;
    void FUN_00a56a40(V00a56a40* v);
};
// pdb: hkpConvexTranslateShape::getFirstVertex | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: v
void O00a56a40::FUN_00a56a40(V00a56a40* v)
{
    unk18->Vx(v);
    v->x += unk20;
    v->y += unk24;
    v->z += unk28;
    v->w += unk2c;
}
}
}   // namespace f3m_00a56a40

// @f3 0x00a56780 (community match, verified in this file)
namespace f3m_00a56780 {
namespace f3m_00a56780 {
struct S5678 {
    virtual void V00();
    virtual void V04(const char* name, int n, void* obj);
    virtual void V08();
    virtual void V0c(const char* name, int n, void* obj);
    virtual void V10(); virtual void V14();
    virtual void V18();
};
struct O5678 {
    int unk00[6];
    void* unk18;
    void FUN_00a56780(S5678* s);
};
// pdb: hkpConvexTranslateShape::calcContentStatistics | hkpConvexTranslateShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: collector, cls
void O5678::FUN_00a56780(S5678* s)
{
    s->V04("CvxTranslate", 1, this);
    s->V0c("Child", 1, unk18);
    s->V18();
}
}
}   // namespace f3m_00a56780

// @f3 0x00a47e60 (community match, verified in this file)
namespace f3m_00a47e60 {
extern unsigned long DAT_010f3170;
struct FreeNode { FreeNode* next; };
struct FreeList {
    FreeNode* head;
    int count;
    void Push(FreeNode* b) throw() { ++count; b->next = head; head = b; }
};
struct ThreadMemory {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int limit;
    int unk38, unk3c, unk40, unk44;
    FreeList row2;
    void FUN_008f6890(int row, void* p, int tag) throw();
    void FUN_008f6d90(void* p, int bytes, int tag) throw();
};
struct Pair { int a, b; };
struct PairArray {
    Pair* data;
    int size;
    int capacityAndFlags;
    PairArray* FUN_00a47e60(unsigned int flags);
};
}

f3m_00a47e60::PairArray* f3m_00a47e60::PairArray::FUN_00a47e60(unsigned int flags)
{
    if ((capacityAndFlags & 0x80000000) == 0) {
        int capacity = capacityAndFlags & 0x3fffffff;
        ThreadMemory* memory = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        memory->FUN_008f6d90(data, capacity * sizeof(Pair), 0x17);
    }
    if (flags & 1) {
        ThreadMemory* memory = (ThreadMemory*)TlsGetValue(DAT_010f3170);
        FreeList* bucket = &memory->row2;
        if (*(volatile int*)&bucket->count >= memory->limit)
            memory->FUN_008f6890(2, this, 0x17);
        else
            bucket->Push((FreeNode*)this);
    }
    return this;
}

// @f3 0x00a546b0 (community match, verified in this file)
namespace f3m_00a546b0 {
namespace f3m_00a546b0 {
struct C00a546b0Src { float x, y, z, w; float a0, a1, a2, a3; int i20; char b24; };
struct C00a546b0Obj {
    int unk00[16];
    float x, y, z, w;
    float a0, a1, a2, a3;
    int i60;
    char b64;
    void hkpMoppCompiler_setAssemblerParams(const C00a546b0Src* s);
};
// pdb: hkpMoppCompiler::setAssemblerParams | hkpMoppCompiler.obj | fnv360_0822_retail, call_gap + bridge(call_gap|call_seq) + skyrim(call_seq), high
void C00a546b0Obj::hkpMoppCompiler_setAssemblerParams(const C00a546b0Src* s)
{
    x = s->x;
    y = s->y;
    z = s->z;
    a0 = s->a0;
    a1 = s->a1;
    a2 = s->a2;
    a3 = s->a3;
    i60 = s->i20;
    b64 = s->b24;
}
}
}   // namespace f3m_00a546b0

// @f3 0x00a4e1f0 (community match, verified in this file)
namespace f3m_00a4e1f0 {
namespace f3m_00a4e1f0 {
struct A4e1Ref { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
void FUN_00901f10(void* array, int elemSize);
struct A4e1Array {
    A4e1Ref** data;
    int size;
    int capacityAndFlags;
    void pushBack(A4e1Ref* r)
    {
        if (size == (capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, sizeof(A4e1Ref*));
        data[size] = r;
        size++;
    }
};
struct A4e1Obj {
    int unk00[17];
    A4e1Array unk44;
    void hkpPhysicsSystemWithContacts_addContact(A4e1Ref* r);
};
// pdb: hkpPhysicsSystemWithContacts::addContact | hkpPhysicsSystemWithContacts.obj | fnv360_0822_retail, call_gap + skyrim(call_gap), high
void A4e1Obj::hkpPhysicsSystemWithContacts_addContact(A4e1Ref* r)
{
    if (r) {
        if (r->memSizeAndFlags != 0)
            r->referenceCount++;
        unk44.pushBack(r);
    }
}
}
}   // namespace f3m_00a4e1f0

// @f3 0x00a4a310 (community match, verified in this file)
namespace f3m_00a4a310 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e86594[];
struct A4a31Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct FUN_00a84f70 {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08[5];
    FUN_00a84f70(int a, int b, int c) throw();
    static void* operator new(unsigned int n)
    {
        A4a31Heap* heap = (A4a31Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x1a);
        ((FUN_00a84f70*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
struct A4a31Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    FUN_00a84f70* unk08;
    A4a31Obj* FUN_00a4a310(int a, int b);
};
// pdb: hkIstream::hkIstream | hkIStream.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: mem, memSize
A4a31Obj* A4a31Obj::FUN_00a4a310(int a, int b)
{
    referenceCount = 1;
    vtable = DAT_00e86594;
    unk08 = new FUN_00a84f70(a, b, 2);
    return this;
}
}

// @f3 0x00a558b0 (community match, verified in this file)
namespace f3m_00a558b0 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e86bc8[];
extern void* DAT_00dcc494[];
struct A558Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A558Elem { int unk[27]; };
struct A558Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    struct Arr {
        A558Elem* data;
        int size;
        int capacityAndFlags;
        void Free()
        {
            if (!(capacityAndFlags & 0x80000000)) {
                int capacity = capacityAndFlags & 0x3fffffff;
                A558Heap* heap = (A558Heap*)DAT_00d9b080(DAT_010f3170);
                heap->FUN_008f6d90(data, capacity * sizeof(A558Elem), 0x17);
            }
        }
    } arr;
    int unk14;
    void FUN_00a558b0();
};
// pdb: hkpMoppCachedShapeMediator::~hkpMoppCachedShapeMediator | hkpMoppCachedShapeMediator.obj | fnv360_0822_retail, call_seq, high
void A558Obj::FUN_00a558b0()
{
    vtable = DAT_00e86bc8;
    unk14 = 0;
    arr.Free();
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a47170 (community match, verified in this file)
namespace f3m_00a47170 {
namespace f3m_00a47170 {
struct A4717Src {
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual int V28(int offset, int flags);
};
struct A4717Elem { int unk00[5]; int unk14; int unk18[6]; };
struct A4717Obj {
    int unk00[8];
    A4717Elem* unk20;
    int unk24[19];
    int unk70;
    int FUN_00a46f50(A4717Src* src, int index, int c);
    int FUN_00a47170(A4717Src* src, int index, int c);
};
int A4717Obj::FUN_00a47170(A4717Src* src, int index, int c)
{
    if (!src->V28(unk20[index].unk14 + unk70, 0))
        return FUN_00a46f50(src, index, c);
    return 1;
}
}
}   // namespace f3m_00a47170

// @f3 0x00a45f70 (community match, verified in this file)
namespace f3m_00a45f70 {
namespace f3m_00a45f70 {
int hkString_strCmp(const char* a, const char* b);
struct A45f7Class {
    const char* FUN_009b0490();
    int FUN_00a45f70();
};
int A45f7Class::FUN_00a45f70()
{
    const char* name = FUN_009b0490();
    if (hkString_strCmp(name, "hkClass") && hkString_strCmp(name, "hkClassMember") &&
        hkString_strCmp(name, "hkClassEnum") && hkString_strCmp(name, "hkClassEnumItem"))
        return 1;
    return 0;
}
}
}   // namespace f3m_00a45f70

// @f3 0x00a4c6f0 (community match, verified in this file)
namespace f3m_00a4c6f0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
extern void* DAT_00dcc494[];
struct D00a4c6f0Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct D00a4c6f0Array {
    char* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            D00a4c6f0Heap* heap = (D00a4c6f0Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity, 0x17);
        }
    }
};
struct D00a4c6f0Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    
    D00a4c6f0Array arr;
    D00a4c6f0Obj* FUN_00a4c6f0(unsigned int flags);
};
D00a4c6f0Obj* D00a4c6f0Obj::FUN_00a4c6f0(unsigned int flags)
{
    arr.Free();
    vtable = DAT_00dcc494;
    if (flags & 1) {
        D00a4c6f0Heap* heap = (D00a4c6f0Heap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 6);
    }
    return this;
}
}

// @f3 0x00a47ee0 (community match, verified in this file)
extern void* DAT_00e862c8[];
namespace f3m_00a47ee0 {
namespace f3m_00a47ee0 {
struct A47eeRef { void* vtable; unsigned short memSizeAndFlags; unsigned short referenceCount; };
struct A47eeMap { int unk00, unk04, unk08; void FUN_00922cb0(); };
struct A47eeObj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A47eeRef* unk08;
    struct Arr { void* data; int size; int cap; void Init() { data = 0; size = 0; cap = 0x80000000; } } arr;
    A47eeMap unk18;
    int unk24;
    A47eeMap unk28;
    int unk34;
    A47eeObj* FUN_00a47ee0(A47eeRef* ref);
};
A47eeObj* A47eeObj::FUN_00a47ee0(A47eeRef* ref)
{
    referenceCount = 1;
    vtable = DAT_00e862c8;
    unk08 = ref;
    arr.Init();
    unk18.FUN_00922cb0();
    unk24 = -1;
    unk28.FUN_00922cb0();
    unk34 = 0;
    if (unk08->memSizeAndFlags != 0)
        unk08->referenceCount++;
    return this;
}
}
}   // namespace f3m_00a47ee0

// @f3 0x00a48310 (community match, verified in this file)
namespace f3m_00a48310 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long DAT_010f3170;
extern void* DAT_00dcc494[];
struct A4831Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A4831Pair { int a, b; };
struct A4831Array {
    A4831Pair* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A4831Heap* heap = (A4831Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(A4831Pair), 0x17);
        }
    }
};
struct A4831Map { int unk00[3]; void FUN_00922cf0(); };
struct A4831Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08[3];
    A4831Array arr;
    A4831Map map;
    A4831Obj* FUN_00a48310(unsigned int flags);
};
A4831Obj* A4831Obj::FUN_00a48310(unsigned int flags)
{
    map.FUN_00922cf0();
    arr.Free();
    vtable = DAT_00dcc494;
    if (flags & 1) {
        A4831Heap* heap = (A4831Heap*)TlsGetValue(DAT_010f3170);
        heap->FUN_008f6d90(this, memSizeAndFlags, 0x15);
    }
    return this;
}
}

// @f3 0x00a58a60 (community match, verified in this file)
namespace f3m_00a58a60 {
namespace f3m_00a58a60 {
struct A58a6Bool { char m_bool; A58a6Bool(bool b) { m_bool = b; } };
struct A58a6Vec { float x, y, z; };
// pdb: hkGeomConvexHullBuilder::vectorLessAndMergeCoordinates | hkGeomConvexHullBuilder.obj | tesv_win, hash, low
A58a6Bool FUN_00a58a60(const A58a6Vec* a, const A58a6Vec* b)
{
    if (a->x < b->x)
        return true;
    if (a->x == b->x && a->y < b->y)
        return true;
    if (a->x == b->x && a->y == b->y && a->z < b->z)
        return true;
    return false;
}
}
}   // namespace f3m_00a58a60

// @f3 0x00a48150 (community match, verified in this file)
namespace f3m_00a48150 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e862c8[];
extern void* DAT_00dcc494[];
struct A4815Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A4815Ref {
    virtual void Del(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                Del(1);
        }
    }
};
struct A4815Pair { int a, b; };
struct A4815Array {
    A4815Pair* data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A4815Heap* heap = (A4815Heap*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(A4815Pair), 0x17);
        }
    }
};
struct A4815Map { int unk00[3]; void FUN_00922cf0(); };
struct A4815Obj {
    void** vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    A4815Ref* unk08;
    A4815Array arr;
    A4815Map unk18;
    int unk24;
    A4815Map unk28;
    void FUN_00a48150();
};
void A4815Obj::FUN_00a48150()
{
    vtable = DAT_00e862c8;
    unk08->removeReference();
    unk28.FUN_00922cf0();
    unk18.FUN_00922cf0();
    arr.Free();
    vtable = DAT_00dcc494;
}
}

// @f3 0x00a47c20 (community match, verified in this file)
namespace f3m_00a47c20 {
namespace f3m_00a47c20 {
struct A47c2Info { int unk00[5]; int count; };
struct A47c2Obj {
    int unk00[7];
    A47c2Info* unk1c;
    int FUN_00a46420(int x, int f);
    int FUN_00a46520(int x, int f);
    int FUN_00a46f50(int x, int i, int f);
    int FUN_00a476e0();
    int FUN_00a47c20(int x);
};
int A47c2Obj::FUN_00a47c20(int x)
{
    if (FUN_00a46420(x, 0) || FUN_00a46520(x, 0))
        return 1;
    for (int i = 0; i < unk1c->count; ++i) {
        if (FUN_00a46f50(x, i, 0) == 1)
            return 1;
    }
    return FUN_00a476e0() == 1;
}
}
}   // namespace f3m_00a47c20

// @f3 0x00a4e240 (community match, verified in this file)
namespace f3m_00a4e240 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e8014c[];
struct A4e24Heap { void FUN_008f6d90(void* p, int size, int tag); };
struct A4e24Ref {
    virtual void Del(int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
    void removeReference()
    {
        if (memSizeAndFlags != 0) {
            --referenceCount;
            if ((unsigned short)referenceCount == 0)
                Del(1);
        }
    }
};
struct A4e24Array {
    A4e24Ref** data;
    int size;
    int capacityAndFlags;
    void Free()
    {
        if (!(capacityAndFlags & 0x80000000)) {
            int capacity = capacityAndFlags & 0x3fffffff;
            A4e24Heap* heap = (A4e24Heap*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(A4e24Ref*), 0x17);
        }
    }
};
struct A4e24Obj {
    void** vtable;
    int unk04[16];
    A4e24Array refs;
    void FUN_0098a0e0();
    void FUN_00a4e240();
};
// pdb: hkpPhysicsSystemWithContacts::~hkpPhysicsSystemWithContacts | hkpPhysicsSystemWithContacts.obj | fnv360_0822_retail, call_seq, high
void A4e24Obj::FUN_00a4e240()
{
    vtable = DAT_00e8014c;
    int n = refs.size;
    for (int i = 0; i < n; ++i)
        refs.data[i]->removeReference();
    refs.Free();
    FUN_0098a0e0();
}
}

// @f3 0x00a47330 (community match, verified in this file)
namespace f3m_00a47330 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern void* DAT_00e8631c[];
struct A4733Heap { void* FUN_008f6d30(unsigned int size, unsigned int tag) throw(); };
struct FUN_00a80240 {
    virtual ~FUN_00a80240();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    int unk08[17];
    FUN_00a80240() throw();
    static void* operator new(unsigned int n)
    {
        A4733Heap* heap = (A4733Heap*)DAT_00d9b080(DAT_010f3170);
        void* p = heap->FUN_008f6d30(n, 0x15);
        ((FUN_00a80240*)p)->memSizeAndFlags = (unsigned short)n;
        return p;
    }
};
struct A4733Child : FUN_00a80240 {
    A4733Child() throw() {}
    virtual ~A4733Child();
};
struct A4733Obj {
    void** vtable;
    int unk04[5];
    A4733Child* unk18;
    int unk1c;
    int unk20;
    struct Inplace {
        int* data;
        int size;
        int cap;
        int storage[16];
        void Init() { size = 0; cap = 0x80000010; data = storage; }
    } inplace;
    int unk70, unk74, unk78;
    int* arrData;
    int arrSize;
    int arrCap;
    void FUN_00a498f0();
    A4733Obj* FUN_00a47330();
};
A4733Obj* A4733Obj::FUN_00a47330()
{
    FUN_00a498f0();
    vtable = DAT_00e8631c;
    unk1c = 0;
    unk20 = 0;
    inplace.Init();
    unk70 = 0;
    unk74 = 0;
    unk78 = 0;
    arrData = 0;
    arrSize = 0;
    arrCap = 0x80000000;
    unk18 = new A4733Child();
    return this;
}
}

// @f3 0x00a45d60 (community match, verified in this file)
namespace f3m_00a45d60 {
struct MeshPart2385
{
    int unk00, unk04, unk08, unk0c;
    unsigned char stride, materialType;
    unsigned short unk12;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
};

struct Shape2385
{
    __forceinline Shape2385(int finishing)
    {
        references = 1;
    }
    virtual ~Shape2385();
    unsigned short allocationSize, references;
    int userData, type;
};
struct Container2385
{
    __forceinline Container2385() {}
    virtual ~Container2385();
};

struct Collection2385 : Shape2385, Container2385
{
    __forceinline Collection2385(int finishing) : Shape2385(finishing), Container2385()
    {
        type = 8;
    }
    virtual ~Collection2385();
};

struct FUN_00a45d60 : Collection2385
{
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    MeshPart2385* parts;
    int count, capacity;

    FUN_00a45d60(int finishing);
    virtual ~FUN_00a45d60();
};

// pdb: hkpMeshShape::hkpMeshShape | hkpMeshShape.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: flag
FUN_00a45d60::FUN_00a45d60(int finishing) : Collection2385(finishing)
{
    if (finishing)
    {
        for (int i = 0; i < count; ++i)
        {
            unsigned char& materialType = parts[i].materialType;
            if (materialType == 0)
                materialType = 1;
        }
    }
    type = 0x16;
}
}   // namespace f3m_00a45d60

// @f3 0x00a50a80 (community match, verified in this file)
namespace f3m_00a50a80 {
struct Vector { float f00,f04,f08,f0c,f10,f14; };
struct Scale { float unk00,f04,f08; };
struct Dest { float unk00,unk04,unk08,f0c; };
struct Record {
float f00;
float f04;
float f08;
float f0c;
float f10;
float f14;
float f18;
float f1c;
float f20;
float f24;
float f28;
float f2c;
float f30;
float f34;
float f38;
float f3c;
float f40;
float f44;
float f48;
float f4c;
};
struct Cursor { Record* record; };
// pdb: hk1dLinearVelocityMotorCommitJacobian | hkpMotorBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low
// pdb params: info, in, jac, out
void FUN_00a50a80(Vector* v, Scale* s, Dest* dest, Cursor* cursor) {
 dest->f0c=s->f08*v->f00;
 Record* r=cursor->record;
 r->f00=(float)((double)r->f00+DAT_00e20408);
 *((unsigned char*)&r->f00)=9;
 r=r+1; cursor->record=r;
 (r-1)->f30=v->f08*s->f04;
 (r-1)->f34=v->f0c*s->f04;
 (r-1)->f38=v->f04;
 (r-1)->f3c=v->f10;
 (r-1)->f40=v->f14;
}
}   // namespace f3m_00a50a80

// @f3 0x00a47e30 (community match, verified in this file)
namespace f3m_00a47e30 {
namespace task2396 {
extern void* DAT_00e86224;void __cdecl FUN_00401010(void*);
struct Member{void FUN_00922cf0();};
struct Object{void* table;int unk04,unk08;Member member;Object* FUN_00a47e30(unsigned char);};
Object* Object::FUN_00a47e30(unsigned char flags){member.FUN_00922cf0();table=&DAT_00e86224;if(flags&1)FUN_00401010(this);return this;}
}
}   // namespace f3m_00a47e30

// @f3 0x00a461a0 (community match, verified in this file)
namespace f3m_00a461a0 {
struct A461a0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char** unk24;

    char* __thiscall FUN_00a461a0(int index, int offset);
};

char* __thiscall A461a0::FUN_00a461a0(int index, int offset) {
    if (unk24[index])
        return unk24[index] + offset;
    return 0;
}
}   // namespace f3m_00a461a0

// @f3 0x00a49b40 (community match, verified in this file)
namespace f3m_00a49b40 {
extern "C" unsigned long (__stdcall* const DAT_00fdf044)(unsigned long);
extern unsigned long DAT_00dcc494;

struct Heap49b40 {
    void __thiscall FUN_008f6f90(void* memory);
};

struct Array49b40 {
    unsigned int unk00, unk04, unk08;
    void __thiscall FUN_00922cf0();
};

struct S49b40 {
    unsigned long vtbl;
    int unk04;
    Array49b40 sub;
    void* f14;
    void __thiscall FUN_00a49b40();
};

void __thiscall S49b40::FUN_00a49b40()
{
    void* memory = f14;
    vtbl = 0xe86494;
    Heap49b40* heap = (Heap49b40*)DAT_00fdf044(DAT_010f3170);
    heap->FUN_008f6f90(memory);
    sub.FUN_00922cf0();
    vtbl = (unsigned long)&DAT_00dcc494;
}
}   // namespace f3m_00a49b40

// @f3 0x00a45ec0 (community match, verified in this file)
namespace f3m_00a45ec0 {
static __declspec(noinline) int FUN_00a45ec0(int a, int b, int* table)
{
    if (a == 0)
        return a;
    int idx = a / 4;
    idx -= idx % b;
    while (table[idx] < 0)
        idx -= b;
    return idx + b;
}
volatile int g_a45ec0;
volatile int g_b45ec0;
volatile int* g_t45ec0;
volatile int g_o45ec0;
void caller_of_FUN_00a45ec0() { g_o45ec0 = FUN_00a45ec0(g_a45ec0, g_b45ec0, (int*)g_t45ec0); }
}   // namespace f3m_00a45ec0

// @f3 0x00a46670 (community match, verified in this file)
namespace f3m_00a46670 {
struct Elem46670 {
    int unk00;
    int unk04;
    void (__cdecl* callback)(int value);
};
struct Sub46670 {
    int* arrayBase;
    int unk04;
    int unk08;
    int FUN_00922790(int value);
    void FUN_00922860(int value);
};
struct Obj46670 {
    int unk00,unk04,unk08,unk0c;
    Sub46670 sub;
    void __thiscall FUN_00a46670(int param);
};
void __thiscall Obj46670::FUN_00a46670(int param)
{
    Sub46670* s = &sub;
    int n = s->FUN_00922790(param);
    int* arrayBase = s->arrayBase;
    int index = s->unk08 + n;
    int entryPtr = (int)arrayBase[index + 1];
    void (__cdecl* callback)(int) = *(void (__cdecl**)(int))((char*)entryPtr + 8);
    if (callback != 0)
        callback(param);
    s->FUN_00922860(n);
}
}   // namespace f3m_00a46670

// @f3 0x00a4e3c0 (community match, verified in this file)
extern double DAT_010c9300;
namespace f3m_00a4e3c0 {
// pdb: hkSetCenterOfMassBuildJacobian | hkp1dBilateralConstraintBuildJacobian.obj | fnv360_0822_retail, objrun_prop, low, conflict (skyrim: hkAddVelocityBuildJacobian)
// pdb params: angToLinVelA, angToLinVelB, out
void __cdecl FUN_00a4e3c0(float* src, int middle, int** out)
{
    float* dst = (float*)*out;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    ((int*)dst)[4] = middle;
    dst[0] = dst[0] + DAT_010c9300;
    ((unsigned char*)dst)[0] = 0x18;
    *out = (int*)((char*)dst + 0x20);
}
}   // namespace f3m_00a4e3c0

// @f3 0x00a4e1b0 (community match, verified in this file)
namespace f3m_00a4e1b0 {
struct Entry4e1b0 {
    virtual void release(int value);
    unsigned short unk04;
    short unk06;
};
struct Obj4e1b0 {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c,unk40;
    Entry4e1b0** array;
    int count;
    void __thiscall FUN_00a4e1b0(int index);
};
// pdb: hkArrayBase<hkpSerializedSubTrack1nInfo *>::_clearAndDeallocate | hkpSaveContactPointsUtil.obj | fnv360_0822_debug, objrun_open, low
// pdb params: alloc
void __thiscall Obj4e1b0::FUN_00a4e1b0(int index)
{
    Entry4e1b0* entry = array[index];
    if (entry->unk04 != 0) {
        entry->unk06 -= 1;
        if (entry->unk06 == 0)
            entry->release(1);
    }
    int last = --count;
    Entry4e1b0* swapped = array[last];
    array[index] = swapped;
}
}   // namespace f3m_00a4e1b0

// @f3 0x00a48260 (community match, verified in this file)
namespace f3m_00a48260 {
struct Item00a48260 { void* value; };
struct Node00a48260 { Item00a48260* item; int next; };
struct Table00a48260 {
    Node00a48260* entries;
    int FUN_00a47f40(void* value);
};
struct Observer00a48260 { void FUN_00922710(void* value, int index); };
struct State00a48260 {
    unsigned int unk00,unk04,unk08,unk0c,unk10;
    Table00a48260 table;
    unsigned int unk18,unk1c;
    Observer00a48260 observer;
    void FUN_00a48260(void* first, void* second, void* unused);
};
void State00a48260::FUN_00a48260(void* first, void* second, void* unused) {
    int index = table.FUN_00a47f40(first);
    if (second) observer.FUN_00922710(second, index);
    if (index == -1) return;
    Node00a48260* entries = table.entries;
    do {
        Node00a48260* entry = &entries[index];
        entry->item->value = second;
        entries = table.entries;
        index = entries[index].next;
    } while (index != -1);
}
}   // namespace f3m_00a48260

// @f3 0x00a49480 (community match, verified in this file)
namespace f3m_00a49480 {
struct InputA494 { int unk00, unk04; int kind; };
struct OwnerA494 {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; unsigned int count;
 void FUN_00a80fe0(InputA494*);
 void FUN_00a49480(InputA494* input);
};
void OwnerA494::FUN_00a49480(InputA494* input) {
 if (count > 0) {
  int kind = input->kind;
  InputA494* first = kind == 1 ? input : 0;
  if (first) --count;
  else {
   InputA494* second = kind == 2 ? input : 0;
   if (second) ++count;
  }
 }
 FUN_00a80fe0(input);
}

}   // namespace f3m_00a49480

// @f3 0x00a45f20 (community match, verified in this file)
extern const char* DAT_01064f80[];
namespace f3m_00a45f20 {

extern int __cdecl FUN_009233f0(const char* value);
extern int __cdecl FUN_009232f0(const char* a, const char* b, int n);

static __declspec(noinline) bool FUN_00a45f20(
    int unused1,
    int unused2,
    int unused3,
    int unused4,
    int unused5,
    int context)
{
    int index = 0;

    if (DAT_01064f80[0] != 0) {
        do {
            const char* value = DAT_01064f80[index];
            int length = FUN_009233f0(value);

            if (FUN_009232f0((const char*)context, value, length) == 0)
                return true;

            ++index;
        } while (DAT_01064f80[index] != 0);
    }

    return false;
}

volatile int FUN_00a45f20_arg1;
volatile int FUN_00a45f20_arg2;
volatile int FUN_00a45f20_arg3;
volatile int FUN_00a45f20_arg4;
volatile int FUN_00a45f20_arg5;
volatile int FUN_00a45f20_context;
volatile bool FUN_00a45f20_result;

void caller_of_FUN_00a45f20()
{
    FUN_00a45f20_result = FUN_00a45f20(
        FUN_00a45f20_arg1,
        FUN_00a45f20_arg2,
        FUN_00a45f20_arg3,
        FUN_00a45f20_arg4,
        FUN_00a45f20_arg5,
        FUN_00a45f20_context);
}
}   // namespace f3m_00a45f20

// @f3 0x00a45ff0 (community match, verified in this file)
namespace f3m_00a45ff0 {
struct Inner { int a,b,c,d,e,unk14; };
struct Outer {
    int unk00, unk04, unk08, unk0c, unk10, unk14p, unk18;
    Inner* unk1c;
    int FUN_00a45ff0();
};
int Outer::FUN_00a45ff0()
{
    return unk1c->unk14;
}
}   // namespace f3m_00a45ff0

// @f3 0x00a45950 (community match, verified in this file)
namespace f3m_00a45950 {
namespace f3m_00a45950 {
void __cdecl FUN_00901e90(void* arr, int numElements, int elementSize);
unsigned short __cdecl FUN_00a560b0(int key, int a1, bool b);

struct U16Array {
    unsigned short* data;
    int size;
    int capAndFlags;
    int getCapacity() const { return capAndFlags & 0x3fffffff; }
    unsigned short& operator[](int i) { return data[i]; }
    void reserve(int n) {
        if (getCapacity() < n)
            FUN_00901e90(this, n, sizeof(unsigned short));
    }
    void setSize(int n) {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(unsigned short));
        }
        size = n;
    }
};

struct Elem {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    int count;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    int start;
};

struct Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    bool built;
    char unk15; char unk16; char unk17;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    int shift;
    Elem* elems;
    int numElems;
    int unk3c;
    U16Array keys;
    volatile char mode;
    void FUN_00a45950(int a1, int a2);
};

void Owner::FUN_00a45950(int a1, int a2)
{
    int total = 0;
    for (int i = 0; i < numElems; i++) {
        elems[i].start = total;
        total += elems[i].count;
    }
    keys.reserve(total);
    keys.setSize(total);
    int k = 0;
    for (int j = 0; j < numElems; j++) {
        for (int m = 0; m < elems[j].count; m++) {
            int key = (j << (32 - shift)) | m;
            keys[k] = FUN_00a560b0(key, a1, a2 != 5);
            k++;
        }
    }
    built = true;
    mode = (char)a2;
}
}
}   // namespace f3m_00a45950

// @f3 0x00a466b0 (community match, verified in this file)
namespace f3m_00a466b0 {
namespace na466b0 {
struct Visitor {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void* V10(void* key, void* val);
};
struct List { void FUN_00922710(void* key, void* v); };
struct Out {
    int unk00,unk04,unk08;
    int fc;
    List list;
    int FUN_00a80070();
};
struct Section { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; int begin; int end; int unk28,unk2c; };
struct Info { int unk00,unk04,unk08,unk0c,unk10; int count; };
struct Map {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
    int* keys;
    int unk2c;
    int cap;
    int Next(int it)
    {
        for (++it; it <= cap; ++it)
            if (keys[it] != -1)
                break;
        return it;
    }
    int First() { return Next(-1); }
    bool IsValid(int it) { return it <= cap; }
    void* Key(int it) { return (void*)keys[it]; }
    void* Value(int it) { return (void*)keys[cap + 1 + it]; }
};
struct Shape {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34();
    virtual void* V38(int a, int b);
    int unk04,unk08,unk0c,unk10,unk14;
    Out* f18;
    Info* f1c;
    Section* f20;
    char** f24;
    int unk28,unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c,unk70,unk74;
    Map* f78;
    int FUN_00a466b0(Visitor* v);
};
int Shape::FUN_00a466b0(Visitor* v)
{
    if (f18->FUN_00a80070())
        return 0;
    Map* map = f78;
    if (!map)
    {
        for (int i = 0; i < f1c->count; i++)
        {
            if (f24[i])
            {
                char* base = f24[i];
                Section* s = &f20[i];
                int* data = (int*)(base + s->begin);
                for (int j = 0; j < (s->end - s->begin) / 4; j += 3)
                {
                    int k = data[j];
                    if (k != -1)
                    {
                        int destinationSection=data[j+1];
                        int destinationOffset=data[j+2];
                        void* x=V38(destinationSection,destinationOffset);
                        void* object=base+k;
                        void* r = v->V10(object, x);
                        if (r)
                        {
                            Out* o = f18;
                            o->fc = 1;
                            o->list.FUN_00922710(object, r);
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int it = map->First(); map->IsValid(it); it = map->Next(it))
        {
            void* k = map->Key(it);
            void* r = v->V10(k, map->Value(it));
            if (r)
            {
                Out* o=f18;
                o->fc=1;
                o->list.FUN_00922710(k,r);
            }
        }
    }
    return 0;
}
}
}   // namespace f3m_00a466b0

// @f3 0x00a5dfc0 (community match, verified in this file)
extern "C" void _ReadWriteBarrier();
#include <math.h>


namespace Contacts462
{
extern unsigned long DAT_010f3170;
extern const double DAT_00db7de8;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
struct Heap { void FUN_008f6d90(void*, unsigned int, int); };
struct Contact { unsigned int key; union { float distance; unsigned int distanceBits; }; };
__forceinline void CopyStoredContact(Contact& destination,const Contact& source) {
    static_cast<volatile unsigned int&>(destination.key)=static_cast<const volatile unsigned int&>(source.key);
    static_cast<volatile unsigned int&>(destination.distanceBits)=static_cast<const volatile unsigned int&>(source.distanceBits);
}
struct Array { Contact* data; int count; unsigned int capacityFlags; };
struct InlineArray : Array
{
    Contact local[2];
    __forceinline InlineArray() throw()
    {
        static_cast<volatile int&>(count) = 0;
        capacityFlags = 0x80000002;
        _ReadWriteBarrier();
        data = local;
    }
    __forceinline ~InlineArray() throw()
    {
        if (!(capacityFlags & 0x80000000))
        {
            unsigned int capacity = capacityFlags & 0x3fffffff;
            Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
            heap->FUN_008f6d90(data, capacity * sizeof(Contact), 23);
        }
    }
};
struct Tag { unsigned short key; };
struct Selector { unsigned int unknown; Tag* tag; };
struct Options { void* primary; void* alternate; Selector* selector; };
struct Params { unsigned int unk00,unk04,unk08; float threshold; };
void __cdecl FUN_00a59e30(void*, Params*, float, void*, void*, void*, void*, Array*) throw();

// pdb: hkGeomConvexHullBuilder::validateNeighbours | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_00a5dfc0(Params* params, void* arg2, void* arg3, unsigned short key,
                          const Options* options, void* arg6, void* arg7, Array* first, Array* second)
{
    if (first->count != 1 || second->count != 1)
        return;
    void* selected = options->primary;
    if (options->selector && key != 0xffff && options->selector->tag->key == key)
        selected = options->alternate;
    Contact* a = first->data;
    Contact* b = second->data;
    float difference = a->distance - b->distance;
    difference = fabsf(difference);
    if (difference < params->threshold)
    {
        InlineArray pair;
        _ReadWriteBarrier();
        float distance = b->distance;
        CopyStoredContact(pair.local[0],*a);
        static_cast<volatile int&>(pair.count) = 1;
        CopyStoredContact(pair.local[1],*b);
        static_cast<volatile int&>(pair.count) = 2;
        FUN_00a59e30(arg2, params, distance, arg3, selected, arg6, arg7, &pair);
        Contact* original = first->data;
        if (pair.data[0].key != original->key)
            original = second->data;
        original->distance = (float)(original->distance * DAT_00db7de8);
    }
}
}

// @f3 0x00a461e0 (community match, verified in this file)
extern const char DAT_00e862a8[];
extern const char DAT_00e86298[];
extern const char DAT_00e44a74[];
namespace f3m_00a461e0 {
namespace f3m_00a461e0 {
int __cdecl hkString_strCmp(const char*,const char*) throw();
void __cdecl FUN_00901f10(void*,int) throw();
template<class T> struct Array {
    T* data;
    int size,capacityFlags;
    T& operator[](int index) { return data[index]; }
    __forceinline T& ExpandOne() {
        if(size==(capacityFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        T& result=data[size];
        ++size;
        return result;
    }
};
struct Item { void* object; int section,offset; };
struct Header {
    int magic0,magic1,userTag,fileVersion,layoutRules,numSections;
};
struct Section {
    char tag[20];
    int absoluteDataStart,localFixupsOffset,globalFixupsOffset;
    int virtualFixupsOffset,exportsOffset,importsOffset,endOffset;
    int VirtualSize() const { return exportsOffset-virtualFixupsOffset; }
};
struct Reader {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual const char* GetVersion() const throw();
    virtual void Slot28(); virtual void Slot2c(); virtual void Slot30();
    virtual int FindSection(const char*) const throw();
    virtual void* Resolve(int section,int offset) const throw();
    int unk04,unk08,unk0c,unk10,unk14,unk18;
    Header* header;
    Section* sections;
    Array<void*> sectionData;
    void FUN_00a461e0(Array<Item>& output);
};
void Reader::FUN_00a461e0(Array<Item>& output)
{
    if(header->fileVersion<4 && hkString_strCmp(GetVersion(),DAT_00e862a8)!=0) {
        int index=FindSection(DAT_00e86298);
        if(index<0) return;
        int bytes=sections[index].localFixupsOffset;
        if(!bytes || !sectionData[index]) return;
        int* words=(int*)sectionData[index];
        int count=bytes/(int)sizeof(int);
        for(int i=0;i<count;i+=2) {
            int section=words[i];
            if(section==-1) return;
            int offset=words[i+1];
            void* object=Resolve(section,offset);
            if(object) {
                Item& slot=output.ExpandOne();
                slot.object=object;
                slot.section=section;
                slot.offset=offset;
            }
        }
        return;
    }
    for(int index=0;index<header->numSections;++index) {
        if(sectionData[index]) {
            unsigned char* data=(unsigned char*)sectionData[index];
            Section& section=sections[index];
            int* fixups=(int*)(data+section.virtualFixupsOffset);
            for(int i=0;i<section.VirtualSize()/(int)sizeof(int);i+=3) {
                int sourceOffset=fixups[i];
                if(sourceOffset!=-1) {
                    int destinationSection=fixups[i+1];
                    int destinationOffset=fixups[i+2];
                    const char* name=(const char*)Resolve(destinationSection,destinationOffset);
                    if(hkString_strCmp(name,DAT_00e44a74)==0) {
                        void* object=data+sourceOffset;
                        Item& slot=output.ExpandOne();
                        slot.object=object;
                        slot.section=destinationSection;
                        slot.offset=destinationOffset;
                    }
                }
            }
        }
    }
}
}
}   // namespace f3m_00a461e0

// @f3 0x00a46f50 (community match, verified in this file)
namespace f3m_00a46f50 {
struct Memory {
    void* FUN_008f6f60(int bytes,int memoryClass) throw();
    void FUN_008f6d90(void*,int bytes,int memoryClass) throw();
};
extern unsigned long DAT_010f3170;
extern void* (__stdcall* DAT_00d9b080)(unsigned long);
void __cdecl FUN_00901f10(void*,int) throw();
template<class T> struct Array {
    T* data; int size,capacityFlags;
    __forceinline Array() throw():data(0),size(0),capacityFlags(0x80000000) {}
    __forceinline void Append(const T& value) {
        if(size==(capacityFlags&0x3fffffff)) FUN_00901f10(this,sizeof(T));
        data[size]=value;
        ++size;
    }
    __forceinline ~Array() throw() {
        if((capacityFlags&0x80000000u)==0) {
            int capacity=capacityFlags&0x3fffffff;
            Memory* memory=(Memory*)DAT_00d9b080(DAT_010f3170);
            memory->FUN_008f6d90(data,capacity*sizeof(T),0x17);
        }
    }
    T& operator[](int index) { return data[index]; }
};
struct Export { const char* name; void* data; };
struct Import { const char* name; void** location; };
struct Resource {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
    Array<void*> allocations;
    void FUN_00a801c0(const char*,void*) throw();
    void FUN_00a80200(const char*,void**) throw();
};
struct Section {
    char tag[20];
    int absoluteDataStart,localFixupsOffset,globalFixupsOffset,virtualFixupsOffset;
    int exportsOffset,importsOffset,endOffset;
    int LocalSize() const { return globalFixupsOffset-localFixupsOffset; }
    void FUN_00a80a20(void*,Array<Export>&) const throw();
    void FUN_00a80ad0(void*,Array<Import>&) const throw();
};
struct Header {
    int magic0,magic1,userTag,fileVersion,layoutRules,numSections;
    int contentsSectionIndex,contentsSectionOffset,contentsClassNameSectionIndex,contentsClassNameSectionOffset;
};
struct ClassInfo { const char* FUN_009b0490() const throw(); };
struct Stream {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual int Read(void*,int) throw();
};
struct Reader {
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0c();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1c();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2c();
    virtual void Slot30(); virtual void Slot34(); virtual void* Resolve(int,int) const throw();
    int unk04,unk08,unk0c,unk10,unk14;
    Resource* resource;
    Header* header;
    Section* sections;
    Array<void*> sectionData;
    int FUN_00a46f50(Stream* stream,int index,char* data);
};
int Reader::FUN_00a46f50(Stream* stream,int index,char* data)
{
    Section& section=sections[index];
    int bytes=section.endOffset;
    if(!data) {
        Memory* allocator=(Memory*)DAT_00d9b080(DAT_010f3170);
        data=(char*)allocator->FUN_008f6f60(bytes,5);
        resource->allocations.Append((void*)data);
    }
    if(stream->Read(data,bytes)==bytes) {
        int* fixups=(int*)(data+section.localFixupsOffset);
        for(int i=0;i<section.LocalSize()/(int)sizeof(int);i+=2) {
            int sourceOffset=fixups[i];
            if(sourceOffset!=-1) {
                *(char**)(data+sourceOffset)=data+fixups[i+1];
            }
        }
        {
            Array<Export> exports;
            section.FUN_00a80a20(data,exports);
            for(int i=0;i<exports.size;++i) {
                resource->FUN_00a801c0(exports[i].name,exports[i].data);
            }
        }
        {
            Array<Import> imports;
            section.FUN_00a80ad0(data,imports);
            for(int i=0;i<imports.size;++i) {
                resource->FUN_00a80200(imports[i].name,imports[i].location);
            }
        }
        sectionData[index]=data;
        int nameSection=header->contentsClassNameSectionIndex;
        int nameOffset=header->contentsClassNameSectionOffset;
        if(index==nameSection && nameOffset>=0 && header->fileVersion<3) {
            const char* name=((ClassInfo*)Resolve(nameSection,nameOffset))->FUN_009b0490();
            header->contentsClassNameSectionOffset=name-data;
        }
        return 0;
    }
    return 1;
}
}

// @f3 0x00a47f60 (community match, verified in this file)
namespace f3m_00a47f60 {
struct Other {
    int FUN_00922710();
};
struct This {
    int FUN_00a47f60();
};
int This::FUN_00a47f60()
{
    return reinterpret_cast<Other*>((char*)this + 0x28)->FUN_00922710();
}
}   // namespace f3m_00a47f60

// @f3 0x00a47f70 (community match, verified in this file)
namespace f3m_00a47f70 {
struct Other {
    int FUN_00922d30();
};
struct This {
    int FUN_00a47f70();
};
int This::FUN_00a47f70()
{
    return reinterpret_cast<Other*>((char*)this + 0x28)->FUN_00922d30();
}
}   // namespace f3m_00a47f70

// @f3 0x00a4a620 (community match, verified in this file)
namespace f3m_00a4a620 {
struct Other {
    int FUN_00922710();
};
struct This {
    int FUN_00a4a620();
};
// pdb: hkPackfileWriter::addExport | hkPackfileWriter.obj | tesv_win, vtable, medium
int This::FUN_00a4a620()
{
    return reinterpret_cast<Other*>((char*)this + 0x2c)->FUN_00922710();
}
}   // namespace f3m_00a4a620

// @f3 0x00a4b870 (community match, verified in this file)
namespace f3m_00a4b870 {
struct Other {
    int FUN_00a4b800();
};
struct This {
    int FUN_00a4b870();
};
// pdb: hkMemoryAllocator::_bufFree<char *> | hkPackfileWriter.obj | fnv360_0822_debug, objrun_open, low
// pdb params: p, numElem
int This::FUN_00a4b870()
{
    return reinterpret_cast<Other*>((void*)-1)->FUN_00a4b800();
}
}   // namespace f3m_00a4b870

// @f3 0x00a568d0 (community match, verified in this file)
namespace f3m_00a568d0 {
namespace f3m_a568d0
{
struct V4
{
    float x, y, z, w;

    __forceinline void add3clobberW(const V4* a)
    {
        x = *(volatile float*)&x + a->x;
        y += a->y;
        z += a->z;
    }
};

struct Sub
{
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
    virtual void Vx(float* a, V4* b);
};

struct Own
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Sub* m_sub;
    int unk1c;
    V4 m_trans;

    void __thiscall FUN_00a568d0(float* a, V4* b);
};

FNV_STATIC_ASSERT(offsetof(Own, m_sub) == 0x18);
FNV_STATIC_ASSERT(offsetof(Own, unk1c) == 0x1c);
FNV_STATIC_ASSERT(offsetof(Own, m_trans) == 0x20);

// pdb: hkpConvexTranslateShape::getSupportingVertexImpl | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: direction, supportingVertexOut
void __thiscall Own::FUN_00a568d0(float* a, V4* b)
{
    m_sub->Vx(a, b);
    b->add3clobberW(&m_trans);
}
}
}   // namespace f3m_00a568d0

// @f3 0x00a483d0 (community match, verified in this file)
extern const char* DAT_01065098[];
namespace f3m_00a483d0 {
static __declspec(noinline) bool __cdecl FUN_00a483d0(const char* input) {
    for (int i = 0; DAT_01065098[i] != 0; ++i) {
        const char* entry = DAT_01065098[i];
        int len = f3m_00a49950::f3m_00a49950::FUN_009233f0(entry);
        if (f3m_00a49950::f3m_00a49950::FUN_009232f0(input, entry, len) == 0) return true;
    }
    return false;
}


bool HasKnownPrefix35(const char* input) { return FUN_00a483d0(input); }
}   // namespace f3m_00a483d0

// @f3 0x00a46060 (community match, verified in this file)
struct ErrorTag_a46060 { unsigned char unused[8]; };
extern ErrorTag_a46060 DAT_00e86280;

struct RangeRecord_a46060 {
    int m_reserved[6];
    int m_iLow;
    int m_iHigh;
};

class Class_a46060;

typedef int (__thiscall *ReportErrorFn_a46060)(Class_a46060* pSelf, const ErrorTag_a46060* pTag, int iSeverity);
typedef int (__thiscall *SetBoundsFn_a46060)(Class_a46060* pSelf, int iLow, int iHigh);
typedef int (__thiscall *SetErrorCodeFn_a46060)(Class_a46060* pSelf, int iCode);

struct Vftable_a46060 {
    void* m_reserved[13];
    ReportErrorFn_a46060 m_fnReportError;
    SetBoundsFn_a46060 m_fnSetBounds;
};

class Class_a46060 {
public:
    Vftable_a46060* m_pVftable;
    unsigned char m_reserved04[0x18];
    RangeRecord_a46060* m_pRange;

    void FUN_00a46060();
};

void Class_a46060::FUN_00a46060() {
    int iLow = m_pRange->m_iLow;
    int iHigh = m_pRange->m_iHigh;

    if (iLow >= 0 && iHigh >= 0) {
        SetBoundsFn_a46060 pfnSetBounds = m_pVftable->m_fnSetBounds;
        pfnSetBounds(this, iLow, iHigh);
        return;
    }

    Vftable_a46060* pVftable = m_pVftable;

    int iCode = pVftable->m_fnReportError(this, &DAT_00e86280, 0);

    SetErrorCodeFn_a46060 pfnSetErrorCode = reinterpret_cast<SetErrorCodeFn_a46060>(pVftable->m_fnSetBounds);
    pfnSetErrorCode(this, iCode);
}

// @f3 0x00a4b800 (community match, verified in this file)
namespace f3m_00a4b800 {
struct Buf_a4b8 {
    char* m_data;
    int m_size;
    unsigned int m_capacity;
};

extern void __cdecl FUN_00901e90(void*, int, int);

static void __declspec(noinline) FUN_00a4b800(Buf_a4b8* buf, int count) {
    int s = buf->m_size + count + 1;
    int oldSize = buf->m_size;

    if (s > oldSize) {
        unsigned int cap = buf->m_capacity & 0x3fffffff;
        if ((int)cap < s) {
            cap += cap;
            if (s >= (int)cap)
                cap = s;
            FUN_00901e90(buf, cap, 1);
        }

        for (int i = oldSize; i < s; ++i)
            buf->m_data[i] = '\t';
    }

    buf->m_size = s;
    buf->m_data[buf->m_size - 1] = 0;
    --buf->m_size;
}

void __cdecl f3drv_a4b8(Buf_a4b8* buf, int count) {
    FUN_00a4b800(buf, count);
}
}   // namespace f3m_00a4b800

// @f3 0x00a4b900 (community match, verified in this file)
namespace f3m_00a4b900 {
struct Buf_a4b8 {
    char* m_data;
    int m_size;
    unsigned int m_capacity;
};

extern void __cdecl FUN_00901e90(void*, int, int);

static void __declspec(noinline) FUN_00a4b800(Buf_a4b8* buf, int count) {
    int s = buf->m_size + count + 1;
    int oldSize = buf->m_size;

    if (s > oldSize) {
        unsigned int cap = buf->m_capacity & 0x3fffffff;
        if ((int)cap < s) {
            cap += cap;
            if (s >= (int)cap)
                cap = s;
            FUN_00901e90(buf, cap, 1);
        }

        for (int i = oldSize; i < s; ++i)
            buf->m_data[i] = '\t';
    }

    buf->m_size = s;
    buf->m_data[buf->m_size - 1] = 0;
    --buf->m_size;
}

struct Cls_a4b900 {
    int m_reserved00[2];
    Buf_a4b8 m_sub;

    void FUN_00a4b900(int count);
};

void Cls_a4b900::FUN_00a4b900(int count) {
    FUN_00a4b800(&m_sub, count);
}
}   // namespace f3m_00a4b900

// @f3 0x00a482b0 (community match, verified in this file)
namespace f3m_00a482b0 {
struct A482Entry {
    int* value;
    int next;
};

struct A482Table {
    A482Entry* entries;
    int FUN_00a47f40(int value);
    void FUN_00a2a1d0(int value, int index);
    void FUN_00a480b0(int value, int** pslot);
};

struct A482Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    A482Table table;

    void FUN_00a482b0(int value, int* slot);
};

void A482Owner::FUN_00a482b0(int value, int* slot) {
    int* s = *(int* volatile*)&slot;
    int oldValue = *s;
    if (oldValue != 0) {
        A482Table* t = &table;
        int index = t->FUN_00a47f40(oldValue);
        if (index != -1) {
            A482Entry* e = t->entries;
            do {
                if (e[index].value == s) {
                    if (value == oldValue)
                        return;
                    t->FUN_00a2a1d0(oldValue, index);
                    break;
                }
                index = e[index].next;
            } while (index != -1);
        }
    }
add:
    if (value != 0)
        table.FUN_00a480b0(value, &slot);
    *s = value;
}
}   // namespace f3m_00a482b0

// @f3 0x00a46b50 (community match, verified in this file)
#include <new>
extern unsigned int DAT_010f3170;
extern const char DAT_00e86290;
extern const char DAT_00e86224;
extern const char DAT_00e862b8[];
namespace f3m_00a46b50 {

namespace ReaderA46B50 {
struct ClassInfo {bool FUN_00a45f70() const throw();};
struct Pair {void* object;ClassInfo* type;};
struct Array {
    Pair* data;int size;unsigned int capacityFlags;
    __forceinline void Init(){data=0;size=0;capacityFlags=0x80000000u;}
    __forceinline int Capacity() const {return capacityFlags&0x3fffffffu;}
};
union ArrayStorage {Array value;ArrayStorage* next;};
struct Memory {
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
    ArrayStorage* arrayFreeList;
    int arrayFreeCount;
    void* FUN_008f6800(int sizeClass,int memoryClass) throw();
};
void __cdecl FUN_00901e90(void* array,int capacity,int stride) throw();
__forceinline ArrayStorage* AllocateArrayStorage(Memory* memory)
{
    ArrayStorage* head=memory->arrayFreeList;
    if (head)
    {
        --memory->arrayFreeCount;
        memory->arrayFreeList=head->next;
        return head;
    }
    return static_cast<ArrayStorage*>(memory->FUN_008f6800(2,0x17));
}
__forceinline Array* AllocateArray()
{
    ArrayStorage* storage=AllocateArrayStorage(reinterpret_cast<Memory*>(::TlsGetValue(DAT_010f3170)));
    if (storage)
    {
        Array* array=new (&storage->value) Array;
        array->Init();
        return array;
    }
    return 0;
}
struct PointerMap {
    void** entries;
    int countFlags,hashMod;
    void FUN_00922cb0() throw();
    void FUN_00922cf0() throw();
    void FUN_00922710(void* key,ClassInfo* value) throw();
};
struct LoadingInfo {int fileVersion;const char* version;void* readerData;};
struct Collector {
    const void* listenerTable;
    Array* output;
    PointerMap* externalMap;
    PointerMap ownedMap;
    LoadingInfo loading;
};
void __cdecl FUN_00a808b0(void* root,ClassInfo* type,Collector* listener) throw();
struct Registry {
    virtual void DeleteThis(int flags) throw();
    virtual void v04();virtual void v08();virtual void v0c();
    virtual ClassInfo* GetClass(const char* name) const throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    __forceinline void RemoveReference()
    {
        if (memSizeAndFlags)
        {
            --referenceCount;
            if (referenceCount==0)
                DeleteThis(1);
        }
    }
};
struct Header {int magic0,magic1,userTag,fileVersion,layoutRules,numSections;};
struct Section {
    char tag[20];
    int absoluteDataStart,localFixupsOffset,globalFixupsOffset,virtualFixupsOffset;
    int exportsOffset,importsOffset,endOffset;
    __forceinline int VirtualBytes() const {return exportsOffset-virtualFixupsOffset;}
};
struct SectionArray {
    char** data;int size,capacityFlags;
    __forceinline char*& operator[](int index){return data[index];}
};
struct Reader {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
    virtual void v10();virtual void v14();virtual void v18();virtual void v1c();
    virtual void v20();virtual const char* GetVersion() const throw();
    virtual void v28();virtual void v2c();virtual void v30();
    virtual int FindSection(const char* name) const throw();
    virtual void* Resolve(int section,int offset) const throw();
    unsigned int unk04,unk08,unk0c,unk10,unk14;
    void* resource;
    Header* header;
    Section* sections;
    SectionArray sectionData;
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    Array* cached;
    Registry* FUN_00a46950() throw();
    const char* FUN_00a460a0() const throw();
    void* FUN_00a46060() const throw();
    Array* FUN_00a46b50();
};

Array* Reader::FUN_00a46b50()
{
    if (!cached)
    {
        Registry* registry=FUN_00a46950();
        int typesIndex=-1;
        const char* version=GetVersion();
        // The packet supplies this C++ helper for the private EBX convention.
        if (f3m_00a45f20::FUN_00a45f20(0,0,0,0,0,reinterpret_cast<int>(version)))
            typesIndex=FindSection(DAT_00e862b8);

        PointerMap classes;
        classes.FUN_00922cb0();
        for (int sectionIndex=0;sectionIndex<header->numSections;++sectionIndex)
        {
            if (sectionData[sectionIndex])
            {
                char* base=sectionData[sectionIndex];
                Section& section=sections[sectionIndex];
                int* fixups=reinterpret_cast<int*>(base+section.virtualFixupsOffset);
                for (int wordIndex=0;wordIndex<section.VirtualBytes()/4;wordIndex+=3)
                {
                    int sourceOffset=fixups[wordIndex];
                    if (sourceOffset!=-1)
                    {
                        int destinationSection=fixups[wordIndex+1];
                        int destinationOffset=fixups[wordIndex+2];
                        const char* name=static_cast<const char*>(Resolve(destinationSection,destinationOffset));
                        ClassInfo* type=registry->GetClass(name);
                        if (typesIndex!=wordIndex && type->FUN_00a45f70())
                            classes.FUN_00922710(base+sourceOffset,type);
                    }
                }
            }
        }

        cached=AllocateArray();
        const char* currentVersion=GetVersion();
        int fileVersion=header->fileVersion;
        Collector collector;
        collector.output=cached;
        collector.listenerTable=&DAT_00e86290;
        collector.externalMap=&classes;
        collector.ownedMap.FUN_00922cb0();
        collector.loading.readerData=&unk08;
        collector.loading.fileVersion=fileVersion;
        collector.loading.version=currentVersion;

        int needed=classes.countFlags&0x7fffffff;
        int capacity=cached->Capacity();
        if (capacity<needed)
        {
            int doubled=capacity*2;
            if (needed<doubled) needed=doubled;
            FUN_00901e90(cached,needed,sizeof(Pair));
        }
        ClassInfo* rootType=registry->GetClass(FUN_00a460a0());
        FUN_00a808b0(FUN_00a46060(),rootType,&collector);
        registry->RemoveReference();
        collector.ownedMap.FUN_00922cf0();
        collector.listenerTable=&DAT_00e86224;
        classes.FUN_00922cf0();
    }
    return cached;
}
}
}   // namespace f3m_00a46b50

// @f3 0x00a46520 (community match, verified in this file)
extern unsigned int DAT_010f3170;
namespace f3m_00a46520 {
extern void __cdecl FUN_00901f10(void*, int);
extern void __cdecl FUN_00901e90(void*, int, int);
extern void __cdecl FUN_00a45e90(void*, int);
struct B1Alloc { void* FUN_008f6f60(int size, int tag); };
struct B1Array {
    void** data; int size; int capacity;
};
struct B1Holder { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; B1Array arr; };
struct B1Info { int unk00; int unk04; int unk08; int unkc; int unk10; int count; };
struct B1Stream { virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual int v10(void* buf, int n); };
struct B1Obj {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    B1Holder* unk18;
    B1Info* unk1c;
    void* unk20;
    B1Array unk24;
    int FUN_00a46520(B1Stream* s, void* buf);
};
// pdb: hkxAttributeHolder::hkxAttributeHolder | hkxAttributeHolder.obj | fnv360_0822_retail, caller_sim, low
// pdb params: other
int B1Obj::FUN_00a46520(B1Stream* s, void* buf)
{
    if (buf == 0) {
        int k = unk1c->count;
        B1Alloc* a = (B1Alloc*)(void*)TlsGetValue(DAT_010f3170);
        buf = a->FUN_008f6f60(k * 48, 5);
        B1Array* arr = &unk18->arr;
        if (arr->size == (arr->capacity & 0x3fffffff))
            FUN_00901f10(arr, 4);
        arr->data[arr->size] = buf;
        arr->size += 1;
    }
    int n = unk1c->count * 48;
    if (s->v10(buf, n) == n) {
    unk20 = buf;
    int c = unk1c->count;
    B1Array* p = &unk24;
    int old = p->size;
    if (c > old) {
        int cap = p->capacity & 0x3fffffff;
        if (cap < c) {
            int cap2 = cap * 2;
            FUN_00901e90(p, c < cap2 ? cap2 : c, 4);
        }
        for (int i = old; i < c; i++)
            p->data[i] = 0;
    }
    p->size = c;
    if (unk1c->unkc < 4)
        FUN_00a45e90(unk20, unk1c->count);
    return 0;
    }
    return 1;
}
}   // namespace f3m_00a46520

// @f3 0x00a56ba0 (community match, verified in this file)
extern const int FUN_00e851bc;
extern const int FUN_00e36414;
namespace f3m_00a56ba0 {
struct SrcA56 { int unk00; unsigned short refFlag, refs; int unk08, unk0c; float scale; };
struct VecA56 { float x,y,z,w; };
struct FUN_00a56ba0 {
    const void* vtable;
    unsigned short unk04;
    unsigned short refs;
    int unk08;
    int stride;
    float scale;
    const void* table;
    SrcA56* src;
    int unk1c;
    VecA56 offset;
    FUN_00a56ba0(SrcA56*, const VecA56&);
};
FUN_00a56ba0::FUN_00a56ba0(SrcA56* input, const VecA56& position) {
    float tempScale = input->scale;
    int dx = 1;
    refs = (unsigned short)dx;
    unk08 = 0;
    scale = tempScale;
    stride = 0xc;
    vtable = &FUN_00e851bc;
    table = &FUN_00e36414;
    src = input;
    if (input->refFlag != 0) ++input->refs;
    offset.x = position.x;
    offset.y = position.y;
    offset.z = position.z;
    *(volatile float*)&offset.w = position.w;
    offset.w = 0.0f;
    *(volatile int*)&unk1c = 0;
}
}   // namespace f3m_00a56ba0

// @f3 0x00a4b160 (community match, verified in this file)
namespace f3m_00a4b160 {
// XML-escaping writer: appends each name to the buffer (passed in ebx: static private convention).
struct XmlBuffer {
    void FUN_009439c0(const char* text, int length);
    void FUN_00943710(const char* text);
};
int __cdecl FUN_00943960(XmlBuffer* buffer, const char* format, ...);
int __cdecl FUN_009233f0(const char* text);

static __declspec(noinline) int FUN_00a4b160(XmlBuffer* out, const char** names, int count)
{
    for (int i = 0; i < count; ++i) {
        const char* start = names[i];
        if (start != 0) {
        const char* p = start;
        while (*p) {
            char c = *p;
            if (c > 0x14 && *p < 0x7f) {
                switch (c) {
                case '"':
                case '&':
                case '\'':
                case '<':
                case '>': {
                    out->FUN_009439c0(start, p - start);
                    char ch = *p;
                    start = p + 1;
                    const char* table[6] = { "<&lt;", ">&gt;", "&&amp;", "\"&quot;", "'&apos;", 0 };
                    for (int k = 0; table[k] != 0; ++k) {
                        if (*table[k] == ch) {
                            const char* repl = table[k] + 1;
                            out->FUN_009439c0(repl, FUN_009233f0(repl));
                            break;
                        }
                    }
                    break;
                }
                }
            } else {
                out->FUN_009439c0(start, p - start);
                FUN_00943960(out, "&#%u;", (unsigned char)*p);
                start = p + 1;
            }
            ++p;
        }
        out->FUN_009439c0(start, p - start);
        } else {
            out->FUN_00943710("&#9216;");
        }
    }
    return 0;
}

XmlBuffer* volatile g_FUN_00a4b160_out;
const char** volatile g_FUN_00a4b160_names;
volatile int g_FUN_00a4b160_count;
volatile int g_FUN_00a4b160_result;

void caller_of_FUN_00a4b160()
{
    g_FUN_00a4b160_result = FUN_00a4b160(g_FUN_00a4b160_out, g_FUN_00a4b160_names, g_FUN_00a4b160_count);
}
}   // namespace f3m_00a4b160

// @f3 0x00a4aeb0 (community match, verified in this file)
extern const char DAT_00de1ee4[];
namespace f3m_00a4aeb0 {
namespace f3m_00a4aeb0 {
struct Flag {
    char value;
    Flag(bool state=false) throw():value(state) {}
    Flag(const Flag& other) throw():value(other.value) {}
    operator bool() const throw() { return value!=0; }
};
struct Context {
    virtual void Slot00() throw();
    virtual void Slot04() throw();
    virtual void Slot08() throw();
    virtual Flag IsOk() const throw();
    virtual int Write(const void*,int) throw();
    unsigned short memoryFlags,referenceCount;
};
struct Writer {
    void* vtable;
    unsigned short memoryFlags,referenceCount;
    Context* context;
    char ownReference;
    Writer* FUN_009ee7e0(Context*,Flag) throw();
    int FUN_009ee740(const void*,int) throw();
    void FUN_009ee850() throw();
};
void* __cdecl FUN_009234e0(void*,const void*,unsigned int) throw();
int __cdecl FUN_00a4aeb0(Context* context,const void* rawSource,int count)
{
    const unsigned char* source=(const unsigned char*)rawSource;
    struct Alphabet64 { char v00,v01,v02,v03,v04,v05,v06,v07,v08,v09,v10,v11,v12,v13,v14,v15,v16,v17,v18,v19,v20,v21,v22,v23,v24,v25,v26,v27,v28,v29,v30,v31,v32,v33,v34,v35,v36,v37,v38,v39,v40,v41,v42,v43,v44,v45,v46,v47,v48,v49,v50,v51,v52,v53,v54,v55,v56,v57,v58,v59,v60,v61,v62,v63; } alphabet={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
    Writer output;
    output.FUN_009ee7e0(context,Flag(false));
    int groupsRemaining=19;
    while(count>0) {
        unsigned char input[3]="";
        int amount=count>=3 ? 3 : count;
        FUN_009234e0(input,source,amount);
        char encoded[4];
        encoded[0]=((const char*)&alphabet)[input[0]>>2];
        encoded[1]=((const char*)&alphabet)[(input[1]>>4)|((input[0]&3)<<4)];
        encoded[2]=((const char*)&alphabet)[(input[2]>>6)|((input[1]&15)<<2)];
        encoded[3]=((const char*)&alphabet)[input[2]&63];
        source+=amount;
        count-=amount;
        if(amount>=3) {
        output.FUN_009ee740(encoded,4);
        if(--groupsRemaining==0) {
            output.FUN_009ee740(DAT_00de1ee4,1);
            groupsRemaining=19;
        }
        if(!context->IsOk()) { output.FUN_009ee850(); return 1; }
        if(count<=0) { output.FUN_009ee850(); return 0; }
        } else {
            switch(amount) {
            case 1:
                encoded[2]=encoded[3]='=';
                output.FUN_009ee740(encoded,4);
                break;
            case 2:
                encoded[3]='=';
                output.FUN_009ee740(encoded,4);
                break;
            }
            break;
        }
    }
    output.FUN_009ee850();
    return 0;
}
}
}   // namespace f3m_00a4aeb0

// @f3 0x00a47fc0 (community match, verified in this file)
namespace f3m_00a47fc0 {
struct Triple12 { const char* name; void* object; int type; };
struct Array12 { Triple12* data; int size; unsigned int capacity; };
struct Owner_a47fc0 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24;
    Array12 items;
};
extern void __cdecl FUN_00901f10(void*, int);
struct FUN_00a47fc0_Host {
    int unk00;
    int unk04;
    Owner_a47fc0* owner;
    void FUN_00a47fc0(const char* name, void* object, int type);
};
void FUN_00a47fc0_Host::FUN_00a47fc0(const char* name, void* object, int type)
{
    void* second = *(void* volatile*)&object;
    int third = *(volatile int*)&type;
    Array12* arr = &owner->items;
    const char* first;
    if (arr->size == (arr->capacity & 0x3fffffff)) {
        first = *(const char* volatile*)&name;
        FUN_00901f10(arr, sizeof(Triple12));
    } else {
        first = *(const char* volatile*)&name;
    }
    Triple12* t = arr->data + arr->size;
    Triple12 item = {first, second, third};
    *t = item;
    ++arr->size;
}
}   // namespace f3m_00a47fc0

// @f3 0x00a46620 (community match, verified in this file)
namespace a46620 {
struct Heap { void FUN_008f6f90(void*) throw(); };
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern unsigned long DAT_010f3170;
struct ReferencedObject {
 void* vtable; unsigned short memSizeAndFlags; short referenceCount;
};
struct PackfileSubobject {
 unsigned int field10; unsigned int field14; unsigned int field18;
};
struct Owner : ReferencedObject {
 unsigned int field08; unsigned int field0c; PackfileSubobject subobject;
 void** data; int size; int capacityAndFlags;
 void FUN_00a46620(void* value);
};
// pdb: hkbCharacter::setPoseLocalMemory | hkbCharacter.obj | tesv_win, caller_sim, low
void Owner::FUN_00a46620(void* value) {
 int count = size;
 int i = 0;
 if (i < count) {
  void** cursor = data;

  do {
   if (*cursor == value) {
    int* n = &size;
    --*n;
    int last = *n;
    void** a = *(void** volatile*)&data;
    a[i] = a[last];
    Heap* heap = (Heap*)DAT_00d9b080(DAT_010f3170);
    heap->FUN_008f6f90(value);
    return;
   }
   ++i; ++cursor;
  } while (i < count);
 }
}
}

// @f3 0x00a486d0 (community match, verified in this file)
namespace f3m_00a486d0 {
extern unsigned long DAT_010f3170;
struct Heap { void FUN_008f6d90(void* p, unsigned int size, int tag) throw(); };
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index) throw();

template<class T> struct Array {
    T* data;
    int size;
    unsigned int capacity;
    ~Array() throw()
    {
        if ((capacity & 0x80000000u) == 0) {
            int count = capacity & 0x3fffffff;
            Heap* heap = (Heap*)TlsGetValue(DAT_010f3170);
            heap->FUN_008f6d90(data, count * sizeof(T), 0x17);
        }
    }
};
struct Record8 { unsigned int unk00, unk04; };
struct Map16 {
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_009b1160() throw();
    ~Map16() throw() { FUN_009b1160(); }
};
struct Deletable { virtual void Destroy(unsigned int flags); };
struct RefObject {
    virtual void Destroy(unsigned int flags);
    unsigned short memSizeAndFlags;
    short referenceCount;
};
struct Base {
    unsigned int unk04, unk08, unk0C, unk10, unk14;
    virtual ~Base() throw();
    void FUN_00a49b40() throw();
};
struct Derived : Base {
    RefObject* ref;
    Array<int> ints;
    Map16 map;
    Array<Record8> pairs;
    Deletable* owned;
    virtual ~Derived() throw();
};
Derived::~Derived() throw()
{
    if (owned)
        owned->Destroy(1);
    RefObject* r = ref;
    if (r->memSizeAndFlags != 0) {
        --r->referenceCount;
        if (r->referenceCount == 0)
            r->Destroy(1);
    }
}
}

// @f3 0x00a48010 (community match, verified in this file)
namespace f3m_00a48010 {

struct F3Arg { unsigned int FUN_009b0490(); };
struct F3Entry { int unk00; int unk04; };
struct F3Node { void* unk00; int unk04; };
struct F3List {
    F3Node* unk00;
    int FUN_00a47f40(int a);
};
struct F3Sub { void FUN_00922710(int a, int b); };
struct F3Obj {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    F3Entry* unk34;
    int unk38;
};
struct F3Cls {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(int a, int b);
    virtual void v20(int a);
    int unk04;
    F3Obj* unk08;
    F3List unk0C;
    int unk10, unk14;
    F3Sub unk18;
    void FUN_00a48010(int a1, int a2, F3Arg* a3);
};

void F3Cls::FUN_00a48010(int a1, int a2, F3Arg* a3) {
    int i = unk0C.FUN_00a47f40(a1);
    if (a2 != 0)
        unk18.FUN_00922710(a2, i);
    while (i != -1) {
        *(int*)unk0C.unk00[i].unk00 = a2;
        i = unk0C.unk00[i].unk04;
    }
    for (int j = 0; j < unk08->unk38; j++) {
        int& r = unk08->unk34[j].unk04;
        if (r == a1)
            r = a2;
    }
    v20(a1);
    if (a3 != 0)
        v1C(a2, a3->FUN_009b0490());
}
}   // namespace f3m_00a48010

// @f3 0x00a4b7a0 (community match, verified in this file)
extern const char DAT_00e7ff98[];
namespace f3m_00a4b7a0 {
namespace f3m_00a4b7a0 {
extern int __cdecl FUN_00923280(char* buf, int size, const char* fmt, ...);

struct Map {
    void* m_elem;
    int m_numElems;
    int m_hashMod;
    int FUN_009227d0(int key, int def);
    int FUN_00922710(int key, int val);
    __forceinline int getSize() const { return m_numElems & 0x7fffffff; }
};

struct A4B7A0 {
    int unk00;
    Map m_map;
    void __thiscall FUN_00a4b7a0(int key, char* buf, int size);
};

void __thiscall A4B7A0::FUN_00a4b7a0(int key, char* buf, int size) {
    int result = m_map.FUN_009227d0(key, 0);
    if (result == 0) {
        int c = m_map.getSize();
        result = c;
        ++c;
        __assume(c > 0);
        m_map.FUN_00922710(key, c);
    }
    FUN_00923280(buf, size, DAT_00e7ff98, result);
}
}
}   // namespace f3m_00a4b7a0

// @f3 0x00a49540 (community match, verified in this file)
namespace f3m_00a49540 {
extern unsigned long DAT_010f3170;
extern void* const DAT_00dcc494;

struct Heap {
    void FUN_008f6f90(void* p);
};
extern __declspec(dllimport) Heap* __stdcall FUN_00d9b080(unsigned long index);

struct Map {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int FUN_009b0dc0();
    void* FUN_009b0de0(int it);
    int FUN_009b0e10(int it);
    char* FUN_009b0e40(char* out, int it);
    void FUN_009b1160();
};

struct Obj {
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    Map m_map;
    void FUN_00a49540();
};

void Obj::FUN_00a49540()
{
    vtable = (void*)0x00e863b8;
    int it = m_map.FUN_009b0dc0();
    char valid;
    m_map.FUN_009b0e40(&valid, it);
    if (valid != 0) {
        do {
            void* val = m_map.FUN_009b0de0(it);
            Heap* heap = FUN_00d9b080(DAT_010f3170);
            heap->FUN_008f6f90(val);
            it = m_map.FUN_009b0e10(it);
            m_map.FUN_009b0e40(&valid, it);
        } while (valid != 0);
    }
    m_map.FUN_009b1160();
    vtable = (void*)&DAT_00dcc494;
}
}

// @f3 0x00a473b0 (community match, verified in this file)
namespace f3m_00a473b0 {

namespace f3m_00a473b0 {

struct Ref_a473b0
{
    virtual void vf00(int value);
    unsigned short unk04;
    short unk06;
};

struct Virtual_a473b0
{
    virtual void vf00(int value);
};

struct Sub74_a473b0
{
    void FUN_00a47e60(int value);
};

struct Heap_a473b0
{
    void FUN_008f6d90(void* pointer, int size, int tag);
};

extern __declspec(dllimport) Heap_a473b0* __stdcall FUN_00d9b080(unsigned long index);

struct Base_a473b0
{
    void FUN_00a49b40();
};

struct Obj_a473b0 : Base_a473b0
{
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Ref_a473b0* unk18;
    unsigned int unk1C;
    unsigned int unk20;
    void* unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    Sub74_a473b0* unk74;
    Virtual_a473b0* unk78;
    void* unk7C;
    unsigned int unk80;
    unsigned int unk84;

    void FUN_00a473b0();
};

void Obj_a473b0::FUN_00a473b0()
{
    unk00 = 0xe8631c;

    if (unk78)
        unk78->vf00(1);

    if (unk74)
        unk74->FUN_00a47e60(1);

    Ref_a473b0* reference = unk18;
    if (reference->unk04 != 0)
    {
        reference->unk06--;
        if (reference->unk06 == 0)
            reference->vf00(1);
    }

    if ((unk84 & 0x80000000u) == 0)
    {
        int capacity = unk84 & 0x3fffffff;
        Heap_a473b0* heap = FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(unk7C, capacity * 4, 0x17);
    }

    if ((unk2C & 0x80000000u) == 0)
    {
        int capacity = unk2C & 0x3fffffff;
        Heap_a473b0* heap = FUN_00d9b080(DAT_010f3170);
        heap->FUN_008f6d90(unk24, capacity * 4, 0x17);
    }

    FUN_00a49b40();
}
}
}   // namespace f3m_00a473b0

// @f3 0x00a49670 (community match, verified in this file)
namespace f3m_00a49730 {

extern void FUN_00a483b0();

struct InnerScope_49670 {
    int a, b, c;
    void FUN_00a82680(int value);
    int FUN_00a82700();
    int FUN_00a82830(int item, void (*callback)());
    void FUN_00a826a0();
};

struct XmlScope_49670 {
    void (*callback)();
    InnerScope_49670 inner;

    __forceinline void cleanup() {
        for (int item = inner.FUN_00a82700(); item != 0; item = inner.FUN_00a82830(item, callback)) {
        }
        inner.FUN_00a826a0();
    }
};

struct XmlReaderVtbl_49670 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c(XmlNode_9730** node, void* stream);
    virtual void v10();
    virtual int v14(XmlElement_9730* element, XmlScope_49670* scope, void* stream);
};

int XmlReader_9730::FUN_00a49670(XmlElement_9730* element, XmlNode_9730** node, void* stream)
{
    XmlScope_49670 scope;
    scope.callback = FUN_00a483b0;
    scope.inner.FUN_00a82680(4);

    XmlReaderVtbl_49670* vtable = reinterpret_cast<XmlReaderVtbl_49670*>(this);

    int result = vtable->v14(element, &scope, stream);
    if (result == 0) {
        result = vtable->v0c(node, stream);
        scope.cleanup();
        return result;
    }
    scope.cleanup();
    return result;
}

}

// @f3 0x00a48550 (community match, verified in this file)
namespace f3m_00a48550 {
namespace f3m_00a48550 {

struct Flag48550 {
    unsigned char value;
    void FUN_009b2530();
    void FUN_009b2a50(int object, int value);
};

struct Target48550 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10(int data);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(int object, int zero);
};

struct Context48550 {
    int FUN_009b0f20(int data);
    char* FUN_009b0e40(char* flag, int handle);
    int FUN_009b0df0(int handle);
    void FUN_009b1000(int handle);
};

int __cdecl FUN_00a498a0(int object, int a, int b, void* map);

struct Owner48550 {
    int unk00;
    int unk04;
    int m_map;

    int FUN_00a48550(int data, Target48550* target, Context48550* context,
                     int c, int a, int b);
};

int Owner48550::FUN_00a48550(int data, Target48550* target, Context48550* context,
                             int c, int a, int b)
{

    int result = target->vf10(data);
    if (result == 0) {
        int handle = context->FUN_009b0f20(data);

        Flag48550 flag;
        context->FUN_009b0e40((char*)&flag, handle);

        if (flag.value != 0) {
            result = context->FUN_009b0df0(handle);
            context->FUN_009b1000(handle);

            FUN_00a498a0(result, a, b, &m_map);

            flag.FUN_009b2530();
            flag.FUN_009b2a50(result, c);

            target->vf1C(result, 0);
            return result;
        }
    }
    return result;

}

}
}   // namespace f3m_00a48550

// @f3 0x00a56fa0 (community match, verified in this file)
extern float FUN_00e7c758;
namespace f3m_00a56fa0 {

void __cdecl FUN_00a56fa0(int* param_1, int param_2, int param_3, int param_4, float* param_5)
{
    float* base = (float*)*param_1;
    int keep = param_2;
    float* p3 = (float*)((char*)base + (param_3 << 4));
    float* p2 = (float*)((char*)base + (keep << 4));

    float* q2 = (float*)((char*)base + (param_2 << 4));
    float f2 = q2[2] * p3[0] - p3[2] * q2[0];
    float f3 = p2[0] * p3[1] - p2[1] * p3[0];

    param_5[0] = p3[2] * p2[1] - p2[2] * p3[1];
    param_5[1] = f2;
    param_5[2] = f3;
    param_5[3] = 0.0f;

    float* p4 = (float*)((char*)base + (param_4 << 4));
    float dot = p4[1] * f2 + p4[0] * param_5[0] + p4[2] * f3;

    if (dot > 0.0f) {
        param_5[0] = -param_5[0];
        param_5[1] = -f2;
        param_5[2] = -f3;
        param_5[3] = FUN_00e7c758;
    }
}
}   // namespace f3m_00a56fa0

// @f3 0x00a567d0 (community match, verified in this file)
namespace f3m_00a567d0 {
struct Vector45 {
    float x, y, z;
    __forceinline float Dot(const Vector45& value) const {
        return x * value.x + y * value.y + z * value.z;
    }
};
struct Support45 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual float Support(Vector45* direction);
};
struct Translated45 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Support45* shape;
    int unk1c;
    Vector45 translation;
    float FUN_00a567d0(Vector45* direction) const;
};
// pdb: hkpConvexTranslateShape::getMaximumProjection | hkpConvexTranslateShape.obj | fnv360_0822_retail, objrun_open, low
// pdb params: direction
float Translated45::FUN_00a567d0(Vector45* direction) const {
    float support = shape->Support(direction);
    return translation.Dot(*direction) + support;
}
}   // namespace f3m_00a567d0

// @f3 0x00a5d870 (community match, verified in this file)
namespace f3m_00a5d870 {
// 0x00a5d870 - 200 bytes, __cdecl, two stack arguments.
struct ElemA5 {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
};
struct NodeA5 {
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
    unsigned short v3;
};
struct SrcA5 {
    int unk00;
    ElemA5* data;
    int size;
};
struct TriA5 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
extern void __cdecl FUN_00901e90(void*, int, int);
struct OutA5 {
    TriA5* data;
    int size;
    int capacity;
};
struct DstA5 {
    int unk00;
    int unk04;
    int unk08;
    OutA5 list;
};

void __cdecl FUN_00a5d870(SrcA5* src, DstA5* dst)
{
    NodeA5* nodes = (NodeA5*)src->data;
    for (int i = 0; i < src->size; ++i) {
        ElemA5 e = src->data[i];
        unsigned int d = e.unk04;
        if (i >= (int)d) continue;
        unsigned short ee = nodes[d].v2;
        if (i >= (int)ee) continue;
        TriA5 t;
        t.a = (unsigned short)e.unk00;
        t.c = nodes[d].v0;
        t.b = nodes[nodes[d].v2].v0;

        OutA5* out = &dst->list;
        int n = out->size;
        int m = n + 1;
        if ((out->capacity & 0x3fffffff) < m) {
            int cap = (out->capacity & 0x3fffffff) * 2;
            if (m >= cap) cap = m;
            FUN_00901e90(out, cap, sizeof(TriA5));
        }
        out->size = n + 1;
        out->data[n] = t;
    }
}
}   // namespace f3m_00a5d870

// @f3 0x00a5e720 (community match, verified in this file)
namespace f3m_00a5e720 {
namespace f3m_00a5e720 {

struct Key { int a; int b; };

struct Vertex { Key key; Vertex* next; int c; int d; };

struct OutPoint { Key key; int c; int d; };

struct VertexList { Vertex* data; int size; int capacity; };

struct PointList {

 OutPoint* data; int size; int capacity;

 void setSize(int n) {

  int cap = capacity & 0x3fffffff;

  if (cap < n) {

   int cap2 = cap * 2;

   FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(OutPoint));

  }

  size = n;

 }

 OutPoint& expandOne() {

  int k = size;

  setSize(k + 1);

  return data[k];

 }

 static void FUN_00901e90(void*, int, int);

};

struct Face { int a; int b; int count() const { return b; } };

Flag __cdecl FUN_00a5e290(Face* face, int other, Flag first, PointList* out);



// pdb: hkGeomConvexHullBuilder::findWrapping | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_00a5e720(Face* left, Face* right, VertexList* verts, PointList* out)

{

 for (int i = 0; i < verts->size; ++i) {

  out->size = 0;

  Vertex* kIter = &verts->data[i];

  out->expandOne().key = kIter->key;

  for (Vertex* n = kIter->next; n; n = n->next) {

   if (n->key.a == kIter->key.a && n->key.b == kIter->key.b && n->c == kIter->c) {


    Flag r1 = FUN_00a5e290(left, right->count(), true, out);


    Flag r2 = FUN_00a5e290(right, left->count(), false, out);

    if (r1 && r2) return;

   }

   OutPoint& p = out->expandOne();

   p.key.a = n->key.a;

   p.key.b = n->key.b;

  }

 }

 out->size = 0;

}

}

}   // namespace f3m_00a5e720

// @f3 0x00a471c0 (community match, verified in this file)
namespace f3m_00a471c0 {
namespace f3m_00a471c0 {
extern "C" __declspec(dllimport) ::Allocator* __stdcall FUN_00d9b080(unsigned long index);
__forceinline ::Allocator* S00a471c0_GetHeap() throw() { return FUN_00d9b080(::DAT_010f3170); }

struct S00a471c0_Pair { int unk00; int unk04; };
template<class T> struct S00a471c0_Array {
    T* data;
    int size;
    int capacity;
    S00a471c0_Array() throw() : data(0), size(0), capacity(0x80000000) {}
    void clearAndDeallocate() throw() {
        if ((capacity & 0x80000000) == 0) {
            int count = capacity & 0x3fffffff;
            S00a471c0_GetHeap()->FUN_008f6d90(data, count * sizeof(T), 0x17);
        }
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    ~S00a471c0_Array() throw() {
        if ((capacity & 0x80000000) == 0) {
            int count = capacity & 0x3fffffff;
            S00a471c0_GetHeap()->FUN_008f6d90(data, count * sizeof(T), 0x17);
        }
    }
};

struct S00a471c0_Section {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20;
    int unk24;
    int unk28, unk2c;
    void FUN_00a80ad0(char* base, S00a471c0_Array<S00a471c0_Pair>& out) throw();
    void FUN_00a80a20(char* base, S00a471c0_Array<S00a471c0_Pair>& out) throw();
};

struct S00a471c0_Listener {
    void FUN_00a800c0(int id) throw();
    void FUN_00a80080(int id) throw();
    void FUN_00a46670(char* p) throw();
    void FUN_00a46620(char* p) throw();
};

static __declspec(noinline) int FUN_00a45ec0(int bytes, int stride, int* data)
{
    if (bytes == 0)
        return 0;
    int n = bytes / 4;
    int i = n - n % stride;
    while (data[i] < 0)
        i -= stride;
    return i + stride;
}

struct S00a471c0_Owner {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    S00a471c0_Listener* unk18;
    int unk1c;
    S00a471c0_Section* unk20;
    char** unk24;
    int FUN_00a471c0(int index);
};

int S00a471c0_Owner::FUN_00a471c0(int index)
{
    S00a471c0_Section* section = &unk20[index];
    char* base = unk24[index];
    {
        S00a471c0_Array<S00a471c0_Pair> added;
        section->FUN_00a80ad0(base, added);
        for (int i = 0; i < added.size; i++)
            unk18->FUN_00a800c0(added.data[i].unk04);
    }
    {
        S00a471c0_Array<S00a471c0_Pair> removed;
        section->FUN_00a80a20(base, removed);
        for (int i = 0; i < removed.size; i++)
            unk18->FUN_00a80080(removed.data[i].unk04);
    }
    int* data = (int*)(base + section->unk20);
    int count = FUN_00a45ec0(section->unk24 - section->unk20, 3, data);
    for (int i = 0; i < count; i += 3)
        unk18->FUN_00a46670(base + data[i]);
    unk18->FUN_00a46620(unk24[index]);
    unk24[index] = 0;
    return 0;
}
}
}   // namespace f3m_00a471c0

// @f3 0x00a4b730 (community match, verified in this file)
namespace f3m_00a4b730 {
// Model of FUN_00a4b730 (98 bytes) - fresh claim, give_ups=0 ✓✓ thiscall with three stack parameters ('retn 0Ch'), returning a pointer.
//   sub esp,0Ch ; push ebx/esi/edi                                       - a 12-byte LOCAL object lives at var_C; no callee-saved value is used before the pushes ✓✓
//   mov edi,[esp+18h+arg_0] ; mov esi,ecx                                - parameter one to EDI and 'this' to ESI (ESI later becomes the result) ✓✓
//   push edi ; lea ecx,[var_C] ; call sub_943A00                         - a thiscall member on that LOCAL object taking parameter one: an init/attach step, so the
//                                                                          object is declared first and initialised through its own member rather than by a real ctor ✓✓
//   mov ebx,[esp+18h+arg_8] ; mov eax,[esi+8]                            - parameter three to EBX and this->+0x08 loaded for the write ✓✓
//   push ebx ; push eax ; push offset "\n%s<hkrawdata size=\"%i\"><![CDATA[\n" ; push ecx(&var_C) ; call sub_943960
//                                                                        - the writer's ADDRESS is pushed as the leftmost argument, so this helper is a FREE function taking
//                                                                          (writer*, format, ...) rather than a member call: no ECX is set up for it ✓✓
//   mov edx,[esp+28h+Src] ; push ebx ; push edx ; push edi ; call sub_A4AEB0
//                                                                        - three cdecl arguments (parameter one, parameter two 'Src', parameter three), result kept and later
//                                                                          returned: ESI is reused for it because 'this' was dead by then ✓✓
//   lea eax,[var_C] ; push offset "\n]]></hkrawdata>" ; push eax ; call sub_943960
//                                                                        - the same free helper with only two arguments, so its format parameter list is variadic ✓✓
//   add esp,24h                                                          - one merged cleanup over all nine pushed words from both writes and the helper call ✓✓ (watch: if my build splits this, the extent grows) 
//   lea ecx,[var_C] ; call sub_943A60                                    - a second member on the local object: the closing/flush step ✓✓
//   pop edi ; mov eax,esi ; pop esi ; pop ebx ; add esp,0Ch ; retn 0Ch    - returns what the helper produced ✓✓

namespace f3m_00a4b730 {

extern char DAT_00e8670c;        // "\n%s<hkrawdata size=\"%i\"><![CDATA[\n" at 0xe8670c ✓✓ (bound by address: the literal has embedded quotes and a newline) 
extern char DAT_00e866f8;        // "\n]]></hkrawdata>" at 0xe866f8 ✓✓

struct RawWriterB7 {                                    // the 12-byte local object at var_C ✓✓
    void* field0;                                       // v1 declared this struct EMPTY, so VC8 reserved no frame for it: their 'sub esp,0Ch' and matching
    void* field4;                                       // 'add esp,0Ch' were missing (92 vs 98) and every [esp+...] displacement shifted ✓✓ giving it three real
    void* field8;                                       // dwords makes the local occupy exactly var_C..var_4 ✓✓

    void FUN_00943a00(void* attached);                  // ORIG: push edi ; lea ecx,[var_C] ; call sub_943A00 - a member taking parameter one ✓✓
    void FUN_00943a60();                                // ORIG: lea ecx,[var_C] ; call sub_943A60 - the closing member at scope end ✓✓
};

void __cdecl FUN_00943960(RawWriterB7* writer, char const* format, ...);   // ORIG: the writer ADDRESS is an argument (no ECX setup), and it is called with both two and four pushed words ✓✓
void* __cdecl FUN_00a4aeb0(void* first, void* source, int third);          // ORIG: push ebx ; push edx ; push edi ; call sub_A4AEB0 ✓✓

struct OwnerB7 {                                        // 'this': only +0x08 is read here ✓✓
    void* pad0;
    void* pad4;
    int sizeField;                                      // +0x08: ORIG mov eax,[esi+8] - the '%i' argument of the first write ✓✓

    void* FUN_00a4b730(void* first, void* source, int third);   // thiscall with three stack parameters (retn 0Ch) ✓✓
};

void* OwnerB7::FUN_00a4b730(void* first, void* source, int third) {
    RawWriterB7 writer;                                 // ORIG: the local object exists before anything is written to it ✓✓

    writer.FUN_00943a00(first);                         // ORIG: push edi ; lea ecx,[var_C] ; call sub_943A00 ✓✓

    FUN_00943960(&writer, &DAT_00e8670c, this->sizeField, third);   // ORIG: push ebx ; push eax ; push offset aSHkrawdataSize ; push ecx ; call sub_943960 ✓✓

    void* result = FUN_00a4aeb0(first, source, third);  // ORIG: mov edx,[esp+28h+Src] ; push ebx ; push edx ; push edi ; call sub_A4AEB0 ✓✓

    FUN_00943960(&writer, &DAT_00e866f8);               // ORIG: lea eax,[var_C] ; push offset aHkrawdata ; push eax ; call sub_943960 - two arguments only ✓✓

    writer.FUN_00943a60();                              // ORIG: lea ecx,[var_C] ; call sub_943A60, after the merged 'add esp,24h' ✓✓

    return result;                                      // ORIG: pop edi ; mov eax,esi ; pop esi ; pop ebx ; add esp,0Ch ; retn 0Ch ✓✓
}

}
}   // namespace f3m_00a4b730

// @f3 0x00a46420 (community match, verified in this file)
namespace f3m_00a46420 {
extern unsigned long DAT_010f3170;
extern void* (__stdcall* const DAT_00d9b080)(unsigned long);
extern const char DAT_00e86238[];
extern const char DAT_00e86244[];
void __cdecl FUN_00901f10(void* array, int elemSize);
void __cdecl FUN_00923500(void* p, int v, int n);

struct hkBool {
    char m_bool;
};

struct StreamA46420 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int read(void* buf, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual hkBool isOk() const;
    virtual void v28();
    virtual int tell() const;
};

struct AllocA46420 {
    void* FUN_008f6f60(int bytes, int tag);
};

struct HeaderA46420 {
    int m_magic[2];
    int m_userTag;
    int m_fileVersion;
    int m_layoutRules;
    int m_numSections;
    int m_contentsSectionIndex;
    int m_contentsSectionOffset;
    int m_contentsClassNameSectionIndex;
    int m_contentsClassNameSectionOffset;
    int m_contentsVersion[4];
    int m_flags;
    int m_pad;

    HeaderA46420() {
        FUN_00923500(this, -1, sizeof(*this));
        m_magic[0] = 0x57e0e057;
        m_magic[1] = 0x10c0c010;
        *(char*)m_contentsVersion = 0;
    }
};

__declspec(noinline) const char* __cdecl FUN_00a45ef0(const HeaderA46420* header) {
    const char* version = (const char*)header->m_contentsVersion;
    if (*version != (char)0xff)
        return version;
    if (header->m_fileVersion == 1)
        return DAT_00e86244;
    return header->m_fileVersion == 2 ? DAT_00e86238 : 0;
}

struct ArrayA46420 {
    void** m_data;
    int m_size;
    int m_capacityAndFlags;
    void pushBack(void* p) {
        if (m_size == (m_capacityAndFlags & 0x3fffffff))
            FUN_00901f10(this, 4);
        m_data[m_size] = p;
        m_size += 1;
    }
};

struct MemTrackA46420 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    ArrayA46420 m_allocated;
};

struct ReaderA46420 {
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
    virtual void setContentsVersion(const char* version);

    int unk04, unk08, unk0c, unk10, unk14;
    MemTrackA46420* m_mem;
    HeaderA46420* m_header;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int m_streamOffset;

    int FUN_00a46420(StreamA46420* stream, HeaderA46420* header);
};

int ReaderA46420::FUN_00a46420(StreamA46420* stream, HeaderA46420* header) {
    m_streamOffset = stream->isOk().m_bool ? stream->tell() : 0;
    if (!header) {
        AllocA46420* alloc = (AllocA46420*)DAT_00d9b080(DAT_010f3170);
        header = (HeaderA46420*)alloc->FUN_008f6f60(0x40, 5);
        m_mem->m_allocated.pushBack(header);
    }
    if (stream->read(header, 0x40) == 0x40) {
        HeaderA46420 expected;
        if (header->m_magic[0] == expected.m_magic[0] && header->m_magic[1] == expected.m_magic[1]) {
            m_header = header;
            setContentsVersion(FUN_00a45ef0(header));
            return 0;
        }
    }
    m_header = 0;
    return 1;
}
}

// @f3 0x00a49aa0 (community match, verified in this file)
namespace f3m_00a49aa0 {
namespace Warn311 {
struct Stream {int unk00,unk04,unk08;void FUN_00923070(char*,int) throw();Stream* FUN_00943710(const char*) throw();void FUN_00943a60() throw();};
const char* FUN_0093e470();extern char DAT_00e86548[],DAT_00e86524[],DAT_00e86504[],DAT_00e864e4[];
struct Logger {virtual void v00();virtual void v04();virtual void v08();virtual void log(int,unsigned,const char*,const char*,int);};extern Logger* DAT_010f3364;
struct Object {int unk00,unk04,unk08,unk0c,unk10;const char* name;int FUN_00a498d0();void FUN_00a49aa0();};
void Object::FUN_00a49aa0(){if(!FUN_00a498d0()){unsigned int storage[128];char* buffer=(char*)storage;Stream stream;stream.FUN_00923070(buffer,512);stream.FUN_00943710(DAT_00e86504)->FUN_00943710(name)->FUN_00943710(DAT_00e86524)->FUN_00943710(FUN_0093e470())->FUN_00943710(DAT_00e86548);DAT_010f3364->log(1,0x7aef6c06,buffer,DAT_00e864e4,118);stream.FUN_00943a60();}}
}

}   // namespace f3m_00a49aa0

// @f3 0x00a49610 (community match, verified in this file)
namespace f3m_00a49610 {
// Model of FUN_00A49610 (52 bytes) - claim clm_6483c35cbf5a4ac7abbc ✓ Writes a value into every block of an intrusive free-list chain, then forwards both arguments to a routine on the EMBEDDED list header at +0x0C ✓
//   cmp edi,0FFFFFFFFh ; mov eax,edi ; jz short +2Bh   
//     - the index parameter is compared against MINUS ONE (a sentinel meaning "no block" ✓✗→✓ ) and copied to EAX as the walk cursor ✗ If it starts at the sentinel the whole loop is skipped ✗ 
//   mov edx,[ecx+0Ch] ; mov edx,[edx+eax*8] ; mov [edx],esi   
//     - the header pointer at +0x0C indexes an array of EIGHT-BYTE entries ✓✗→✓✓ 'edx + eax*8' fixes that stride ✗ The first dword of each entry is written with the value parameter (ESI ✓ ) 
//   mov edx,[ecx+0Ch] ; mov eax,[edx+eax*8+4] ; cmp eax,0FFFFFFFFh ; jnz short -12h   
//     - the header pointer is RE-LOADED on every iteration ✗✗→✓✓ a genuine re-fetch I must not hoist into one local (measured rule ✓ ) and the NEXT index comes from the entrys second dword at +0x04 ✓ compared against
//     MINUS ONE to end the walk ✗ so entries chain by INDEX, not by pointer - which is why the sentinel is a signed negative rather than null ✓ 
//   push edi ; push esi ; add ecx,0Ch ; call sub_A49500   
//     - afterwards a routine is invoked with ECX = this + 0x0C ✓✗→✓✓ i.e. on that EMBEDDED header itself (an adjustor-style address computation ✗ ) receiving the two original parameters in their pushed order: value first,
//     then the index ✗ 'retn 8' at the end shows the callee cleaning those two slots ✗ and nothing is returned ✓ 
struct HandleA49 { public: void* block00; long nextIndex04; };   // v4 CORRECTED READING: the eight-byte array holds a POINTER to each block at its +0x00, not an inline block ✓✗→✓✓ proof is their pair of instructions -
                                                     //     first they LOAD the entry pointer with mov edx,[edx+eax*8], and only then write through it with mov [edx],esi ✗ My earlier model treated the slot as the
                                                     //     block itself, which let this compiler fold the pair into one scaled store and made my function two bytes short ✓ (a handle table, not an inline array ✗ ) 
                                                     //     link prove both halves ✗ The link is an index compared against -1, not a pointer ✓ (that is why I keep it signed ✗ ) 
class HeaderA49 { public: struct HandleA49* handles00; void FUN_00a49500(void* value, int index); };   // v2 rule kept: the EMBEDDED header carries both its handle-array pointer (its own +0x00) and the
                                                     //     trailing routine ✓✗→✓✓ one address serves as load base AND call receiver, which is why splitting them into two types cannot compile ✗ 
                                                     //     trailing routine ✓✗→✓✓ that is why one address (this plus 0x0C) serves as both a load base and a call receiver ✗ My first draft split them into two types, which made the
                                                     //     load read through an object value instead of its address and would not compile ✓ 
                                                     //     outside my owner class so it does not become one of MY members (standing rule for ECX receivers ✓ ) - their build reaches it via 'add ecx,0Ch' ✗ 
class OwnerA49 {                                                      // this object is not polymorphic in this body: no vtable load or store appears ✓✗→✓✓ so offsets stay literal with nothing implicit at zero ✗ 
public:
    void FUN_00a49610(void* value, int index);                        // ORIG: 'retn 8' - a thiscall member with TWO callee-cleaned stack parameters; the second is compared against MINUS ONE so it is SIGNED ✓✗→✓✓ (an
                                                     //     unsigned compare would have used an above/below jump ✗ ) Nothing is returned ✓ 
protected:
    char padTo0C[0x0C];                                               // +0x00..+0x0B untouched here ✓✗→? bracket-wise filler so the header lands exactly on +0x0C (measured rule for non-adjacent live bytes ✓ ) 
    struct HeaderA49 header0C;                                        // +0x0C: EMBEDDED by value - 'add ecx,0Ch' supplies its ADDRESS as the receiver of the trailing call ✓✗→✓✓ nothing is loaded to obtain it ✗ Its block-
                                                     //     array POINTER field lives inside that header at its own +0x00 ('mov edx,[ecx+0Ch]' reads through it twice per iteration ✗ ) 
};                                                                    
                                                     //     member in this body (one type per hop keeps every offset literal ✓ ) 
void OwnerA49::FUN_00a49610(void* value, int index) {                  // their build keeps the two parameters in ESI and EDI for the whole routine ✓✗→? so neither is re-read from the stack later ✗ 
    int cursor = index;                                      // v5: the walk cursor is initialised BEFORE the sentinel test ✓✗→✓✓ their build copies it above the compare-and-branch (mov eax,edi then cmp/jje ✗ ) while my previous
                                                     //     form copied it inside the branch and so emitted the copy afterwards ✗ one instruction of pure source order - no scheduler guesswork needed ✓ 
    if (index != -1) {
                                                       //     cursor before the branch ✗ 
        while (cursor != -1) {                                           // ORIG: entered with the sentinel test above and re-tested at the bottom via 'cmp eax,0FFFFFFFFh ; jnz' ✓✗→✓✓ a do-while over indices ✗ 
            struct HandleA49* slot = &this->header0C.handles00[cursor];   // v4: the handle for this index ✓✗→? its first dword is the block pointer their build loads, and its second is the next index ✗ 
                                                       //     than caching it, so hoisting it would delete instructions they have ✗ (the opposite of my single-fetch cases ✓ ) 
                                                     //     accesses rather than caching one, exactly as their build does (mov edx,[ecx+0Ch] appears twice in the same iteration ✓ ) then indexes eight-byte entries ✗ 
                                                         //     rather than a hand-written shift (measured rule about expressing scaling as indexing ✓ ) 
            *(void**)slot->block00 = value;                          // v4: write THROUGH the loaded entry pointer ✓✗→✓✓ this cannot be folded into one instruction because the address comes from memory, which is
                                                     //     exactly why their build keeps a load and a store while my previous form collapsed them ✗ (the diff proved the difference: mov edx,[edx+eax*8] then mov [edx],esi ✓ ) 
            cursor = this->header0C.handles00[cursor].nextIndex04;   // v4: the link is the handles second dword at +0x04, an INDEX terminated by MINUS ONE ✓✗→✓✓ read through a SECOND load of the same header pointer ✗ 
                                                     //     The link at +0x04 is an INDEX chained by number and terminated by MINUS ONE, not a null pointer ✓✗→✓✓ which is what makes that signed sentinel meaningful ✗ 
                                                         //     (not a null pointer - which is what makes that sentinel meaningful ✓ ) 
        }                                                                    
    }                                                                    
    this->header0C.FUN_00a49500(value, index);                          // ORIG: 'push edi ; push esi ; add ecx,0Ch ; call sub_A49500' then 'retn 8' ✓✗→✓✓ the receiver is the EMBEDDED header reached by adding its offset to
                                                       //     `this' ✗ and both original parameters are forwarded in that order (value pushed last = first parameter ✓ ) with the callee cleaning two slots ✗ 
}                                                                      // closes the member - 'pop edi ; pop esi ; retn 8': two saved registers, two stack parameters cleaned by the callee ✓✗→✓✓ nothing returned ✗ 
}   // namespace f3m_00a49610

// @f3 0x00a460c0 (community match, verified in this file)
namespace f3m_00a460c0 {
namespace ns_00a460c0 {

struct hkBool {
    char m_bool;
    hkBool();
};

struct Klass {
    hkBool FUN_009b0780();
};

struct HashTable {
    int FUN_009227d0(int key, int hint);
};

struct SubObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int key, int* ptr);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    HashTable hashTable;
};

struct TargetObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Klass* v10(int key);
};

struct PairItem {
    int* ptr;
    Klass* klass;
};

struct PairArray {
    PairItem* data;
    int size;
};

int __cdecl FUN_00a498a0(Klass* klass, int a, int b, int c);

struct FUN_00a460c0 {
    int unk00;
    SubObj* m_sub;
    TargetObj* m_target;
    int m_f0c;
    int m_f10;
    int m_f14;

    int call_00a460c0(int a, int b, PairArray* arr);
};

int FUN_00a460c0::call_00a460c0(int a, int b, PairArray* arr)
{
    int i = 0;
    if (arr->size > 0) {
        do {
            PairItem* item = &arr->data[i];
            int* p = item->ptr;
            int key = *p;
            m_sub->v14(key, p);
            if (key != 0) {
                FUN_00a498a0(item->klass, m_f0c, m_f10, m_f14);
                if (item->klass->FUN_009b0780().m_bool) {
                    HashTable* ht = &m_sub->hashTable;
                    int k = ht->FUN_009227d0(key, 0);
                    Klass* newKlass = m_target->v10(k);
                    item->klass = newKlass;
                    FUN_00a498a0(newKlass, m_f0c, m_f10, m_f14);
                }
                ++i;
            } else {
                arr->size -= 1;
                for (int j = i; j < arr->size; ++j) {
                    arr->data[j] = arr->data[j + 1];
                }
            }
        } while (i < arr->size);
    }
    return 0;
}

}
}   // namespace f3m_00a460c0

// @f3 0x00a4aa20 (community match, verified in this file)
namespace ns_00a4aa20 {

struct Flag {
  char value;
  Flag(bool b) : value(b) {}
};

struct Array {
  void* data;
  int size;
  int capacityAndFlags;
  Array() throw() : data(0), size(0), capacityAndFlags((int)0x80000000) {}
};

struct Array12 {
  int unk00, unk04, unk08;
  void FUN_00922cb0() throw();
  void FUN_00922710(void* item, int flag) throw();
  Array12() throw() {
    FUN_00922cb0();
  }
};

struct Map16 {
  int unk00, unk04, unk08, unk0C;
  Map16(Flag flag) throw();
};

class FUN_009b1110 {
 public:
  FUN_009b1110(Flag flag) throw();
  int unk00, unk04, unk08, unk0C;
};

struct Base {
  virtual ~Base();
  unsigned short memSizeAndFlags;
  unsigned short referenceCount;
  Base() throw() {
    referenceCount = 1;
  }
};

extern char DAT_0116a964;
extern char DAT_011693b0;
extern char DAT_0116a994;

} // namespace ns_00a4aa20

struct FUN_00a4aa20 : ns_00a4aa20::Base {
  virtual ~FUN_00a4aa20();
  ns_00a4aa20::Array records;
  ns_00a4aa20::Array12 first;
  ns_00a4aa20::Array12 second;
  ns_00a4aa20::Array12 third;
  ns_00a4aa20::FUN_009b1110 firstMap;
  ns_00a4aa20::FUN_009b1110 secondMap;
  ns_00a4aa20::Array12 fourth;
  ns_00a4aa20::Array pendingObjects;
  ns_00a4aa20::FUN_009b1110 thirdMap;
  ns_00a4aa20::Array pairs;
  int unk8C;
  int unk90;
  int unk94;
  int unk98;
  ns_00a4aa20::Array12 fifth;
  ns_00a4aa20::FUN_009b1110 fourthMap;

  FUN_00a4aa20() throw();
};

// pdb: hkPackfileWriter::hkPackfileWriter | hkPackfileWriter.obj | fnv360_0822_retail, call_seq, high
FUN_00a4aa20::FUN_00a4aa20() throw()
    : firstMap(ns_00a4aa20::Flag(false)),
      secondMap(ns_00a4aa20::Flag(false)),
      thirdMap(ns_00a4aa20::Flag(false)),
      unk8C(-1),
      unk90(-1),
      unk94(0),
      unk98(0),
      fourthMap(ns_00a4aa20::Flag(false)) {
  first.FUN_00922710(&ns_00a4aa20::DAT_0116a964, -1);
  first.FUN_00922710(&ns_00a4aa20::DAT_011693b0, -1);
  first.FUN_00922710(&ns_00a4aa20::DAT_0116a994, -1);
}

// @f3 0x00a4b980 (community match, verified in this file)
namespace f3m_00a4b980 {
extern char DAT_00de1ee4,DAT_00e86778,DAT_00e8676c,DAT_00dff2d4;
struct Stream {
    virtual void v0();virtual void v4();virtual void v8();virtual void vc();
    virtual int Write(const void*,int);
};
struct Buffer {
    void* first;void* second;void* third;
    void FUN_00943a00(Stream*);
    void FUN_00943a60();
};
void __cdecl FUN_00943960(Buffer*,const char*,...);
struct Writer {
    void* table;unsigned unk04;const char* indent;int length;
    void FUN_00a4b900(int);
    void FUN_00a4b980(Stream*,const char*,const char**,bool);
};
void Writer::FUN_00a4b980(Stream* stream,const char* name,const char** attributes,bool newline) {
    if(newline) {
        stream->Write(&DAT_00de1ee4,1);
        stream->Write(indent,length);
    }
    Buffer buffer;
    buffer.FUN_00943a00(stream);
    FUN_00943960(&buffer,&DAT_00e86778,name);
    if(attributes) {
        for(unsigned i=0;attributes[i];i+=2)
            FUN_00943960(&buffer,&DAT_00e8676c,attributes[i],attributes[i+1]);
    }
    FUN_00943960(&buffer,&DAT_00dff2d4);
    FUN_00a4b900(1);
    buffer.FUN_00943a60();
}
}

// @f3 0x00a4b880 (community match, verified in this file)
extern const char DAT_00e86740[];
extern const char DAT_00e86730[];
namespace f3m_00a4b880 {
namespace f3m_00a4b880 {
struct Buf_a4b8 {
    char* m_data;
    int m_size;
    unsigned int m_capacity;
};

struct Ostream_a4b8;
struct Member_a4b8;
struct Class_a4b8 {
    int FUN_009b0630() const;
    const Member_a4b8& FUN_009b0650(int index) const;
};

int __cdecl FUN_00943960(Ostream_a4b8* os, const char* format, ...);
extern void __cdecl FUN_00901e90(void*, int, int);

static void __declspec(noinline) FUN_00a4b800(Buf_a4b8* buf, int count) {
    int s = buf->m_size + count + 1;
    int oldSize = buf->m_size;

    if (s > oldSize) {
        unsigned int cap = buf->m_capacity & 0x3fffffff;
        if ((int)cap < s) {
            cap += cap;
            if (s >= (int)cap)
                cap = s;
            FUN_00901e90(buf, cap, 1);
        }

        for (int i = oldSize; i < s; ++i)
            buf->m_data[i] = '	';
    }

    buf->m_size = s;
    buf->m_data[buf->m_size - 1] = 0;
    --buf->m_size;
}
int __cdecl FUN_00a4bd40(Buf_a4b8* buf, const Member_a4b8& member, const void* object, Ostream_a4b8* os, void* context);

static int __declspec(noinline) FUN_00a4b880(Buf_a4b8* buf, const Class_a4b8& klass, const void* object, Ostream_a4b8* os, void* context)
{
    FUN_00943960(os, DAT_00e86740, buf->m_data);
    FUN_00a4b800(buf, 1);
    for (int i = 0; i < klass.FUN_009b0630(); i++)
        FUN_00a4bd40(buf, klass.FUN_009b0650(i), object, os, context);
    FUN_00a4b800(buf, -1);
    FUN_00943960(os, DAT_00e86730, buf->m_data);
    return 0;
}

volatile int g_in_a4b880;
volatile int g_out_a4b880;
void caller_of_FUN_00a4b880()
{
    g_out_a4b880 = FUN_00a4b880((Buf_a4b8*)g_in_a4b880, *(Class_a4b8*)g_in_a4b880, (void*)g_in_a4b880,
                                (Ostream_a4b8*)g_in_a4b880, (void*)g_in_a4b880);
}
}
}   // namespace f3m_00a4b880

// @f3 0x00a4c650 (community match, verified in this file)
namespace f3m_00a4c650 {
namespace match649 {
struct Bag {int FUN_009b0630();void* FUN_009b0650(int);};
struct Local {unsigned u00;unsigned short u04,count;void* storage;void FUN_00943a00(void*);unsigned char* FUN_00943650(void*);void FUN_00943a60();};
struct Row{};
struct Owner {unsigned u00,u04;Row row;int FUN_00a4c650(void*,void*,Bag*,unsigned);};
void __cdecl FUN_00a4bd40(Row*,void*,void*,Local*,Owner*);
int Owner::FUN_00a4c650(void* argument,void* context,Bag* bag,unsigned unused){
 Local local;
 local.FUN_00943a00(argument);
 for(int i=0;i<bag->FUN_009b0630();++i)
  FUN_00a4bd40(&row,bag->FUN_009b0650(i),context,&local,this);
 int result=*local.FUN_00943650(&argument)==0;
 local.FUN_00943a60();
 return result;
}
}
}   // namespace f3m_00a4c650

// @f3 0x00a48780 (community match, verified in this file)
namespace f3m_00a48780 {
struct Slot7Bool {
    bool value;
    Slot7Bool(bool b): value(b) {}
    operator bool() const { return value; }
};
struct Slot7Fixup { int offset; int id; };
struct Slot7Global { int offset; int value; };
struct Slot7Section
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Slot7Global* global;
    int hasGlobal;
    int unk20;
    Slot7Fixup* fixups;
    int fixupCount;
};
struct Slot7Tracker
{
    int FUN_009b0f20(int key);
    Slot7Bool FUN_009b0e40(int id);
    int FUN_009b0df0(int id);
    void FUN_009b1000(int id);
    int FUN_009b10f0(int id, int other);
    void FUN_009b0e60(int id, int value);
    int Get10f0(int id) { return FUN_009b10f0(id, -1); }
};
struct Slot7Resolver { int FUN_009b0fb0(int id, void** out); int Get(int id, void** out) { return FUN_009b0fb0(id, out); } };
struct Slot7FixupTable { int FUN_00a49650(char** location, int id); };
struct Slot7Sink
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void Patch(void* target, char* location);
    virtual void v18();
    int unk04;
    int unk08;
    Slot7FixupTable table;
    void FUN_00a49610(char* base, int size);
    virtual void PatchGlobal(char* location, int value);
};
struct Slot7Loader
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c; int unk40;
    Slot7Sink* sink;
    void FUN_00a48780(int key, char* base, Slot7Section* section, Slot7Resolver* resolver, Slot7Tracker* tracker);
};

void Slot7Loader::FUN_00a48780(int key, char* base, Slot7Section* section, Slot7Resolver* resolver, Slot7Tracker* tracker)
{
    {
    int id = tracker->FUN_009b0f20(key);
    Slot7Bool found = tracker->FUN_009b0e40(id);
    if (found)
    {
        sink->FUN_00a49610(base, tracker->FUN_009b0df0(id));
        tracker->FUN_009b1000(id);
    }
    }
    if (section->hasGlobal)
    {
        Slot7Global* g = section->global;
        sink->PatchGlobal(g->offset + base, g->value);
    }
    for (key = 0; key < section->fixupCount; key++)
    {
        Slot7Fixup* f = &section->fixups[key];
        void* target;
        if (!resolver->Get(f->id, &target))
        {
            sink->Patch(target, f->offset + base);
        }
        else
        {
            int v = tracker->Get10f0(f->id);
            char* location = f->offset + base;
            tracker->FUN_009b0e60(f->id, sink->table.FUN_00a49650(&location, v));
        }
    }
}
}   // namespace f3m_00a48780

// @f3 0x00a46950 (community match, verified in this file)
namespace f3m_00a46950 {

void __cdecl FUN_00901e90(void* array, int numElements, int elementSize);

struct Memory {
    void* FUN_008f6d30(int size, int cls);
    void FUN_008f6d90(void* p, int size, int cls);
};

struct ClassN {
    const char* m_name;
    const char* FUN_009b0490() const;
};

extern ClassN DAT_0116a994;
extern ClassN DAT_011693b0;
extern ClassN DAT_0116a964;
extern ClassN DAT_0116a934;
extern ClassN DAT_0116c25c;
extern ClassN DAT_0116c2bc;

struct RefObject {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void registerClass(const ClassN* c, const char* name);
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void addReference()
    {
        if (m_memSizeAndFlags != 0)
            ++m_referenceCount;
    }
};

struct Registry : RefObject {
    static void* operator new(unsigned int size)
    {
        Memory* m = (Memory*)::TlsGetValue(DAT_010f3170);
        RefObject* o = (RefObject*)m->FUN_008f6d30(size, 0x15);
        o->m_memSizeAndFlags = (unsigned short)size;
        return o;
    }
    static void operator delete(void* p);
    Registry(RefObject* parent) throw();
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
};

struct Factory {
    RefObject* FUN_009b20b0(int key);
};
extern Factory* DAT_011693ac;

template <class T> struct ArrayN {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    ArrayN() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    void release()
    {
        if (!(m_capacityAndFlags & 0x80000000)) {
            int n = m_capacityAndFlags & 0x3fffffff;
            Memory* m = ((Memory*)::TlsGetValue(DAT_010f3170));
            m->FUN_008f6d90(m_data, n * sizeof(T), 0x17);
        }
    }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    T* expandBy(int n)
    {
        int old = m_size;
        int ns = n + old;
        int cap = getCapacity();
        if (cap < ns) {
            int cap2 = 2 * cap;
            FUN_00901e90(this, ns < cap2 ? cap2 : ns, sizeof(T));
        }
        T* r = m_data + old;
        m_size = ns;
        return r;
    }
};

struct Entry {
    ClassN* klass;
    int unk04;
    int unk08;
};

struct Settings { int unk00, unk04, unk08, unk0C; };

void __cdecl FUN_00a498a0(ClassN* c, int mode, int key, void* out);

struct Builder {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual int getKey();
    int unk04;
    int unk08;
    int unk0C, unk10, unk14, unk18;
    Settings* unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78;
    ArrayN<ClassN*> m_classes;

    void FUN_00a461e0(ArrayN<Entry>* out);
    RefObject* FUN_00a46950();
};

RefObject* Builder::FUN_00a46950()
{
    if (m_classes.m_size == 0) {
        ArrayN<Entry> found;
        FUN_00a461e0(&found);
        ClassN** dst = m_classes.expandBy(found.m_size);
        for (int i = 0; i < found.m_size; i++)
            dst[i] = found.m_data[i].klass;
        found.release();
    }
    Factory* f = DAT_011693ac;
    RefObject* result = f->FUN_009b20b0(getKey());
    if (m_classes.m_size != 0) {
        result = new Registry(result);
        for (int i = 0; i < m_classes.m_size; i++) {
            ClassN* c = m_classes.m_data[i];
            FUN_00a498a0(c, unk1C->unk0C, getKey(), &unk08);
            result->registerClass(c, c->FUN_009b0490());
        }
        const ClassN* list[5];
        list[0] = &DAT_0116a994;
        list[1] = &DAT_011693b0;
        list[2] = &DAT_0116a964;
        list[3] = &DAT_0116a934;
        list[4] = 0;
        if (unk1C->unk0C == 1) {
            list[0] = &DAT_0116c25c;
            list[1] = &DAT_0116c2bc;
        }
        for (int j = 0; list[j]; j++)
            result->registerClass(list[j], list[j]->FUN_009b0490());
        return result;
    }
    result->addReference();
    return result;
}

}

// @f3 0x00a47470 (community match, verified in this file)
namespace f3m_00a47470 {

extern unsigned long DAT_010f3170;
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long);
extern const void* DAT_00e86230;

struct ThreadMemory {
    void* FUN_008f6d30(int nbytes, int memoryClass) throw();
};

struct PointerMap {
    void* entries;
    int countFlags;
    int hashMod;
    void FUN_00922710(void* key, const char* value) throw();
};

class Pooled {
public:
    virtual ~Pooled();
    unsigned short memSizeAndFlags;
    short referenceCount;
    static void* operator new(unsigned int size)
    {
        ThreadMemory* memory = (ThreadMemory*)FUN_00d9b080(DAT_010f3170);
        void* p = memory->FUN_008f6d30(size, 0x15);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    static void operator delete(void*) throw() {}
};

class FUN_00a47ee0 : public Pooled {
public:
    FUN_00a47ee0(void* owner) throw();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void AddReference(void* target, void* from) throw();
    virtual void v18();
    virtual void AddObject(void* obj, const char* className) throw();

    void* owner;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    PointerMap classes;
    void* topLevelObject;

    __forceinline void SetTopLevelObject(void* obj, const char* className)
    {
        topLevelObject = obj;
        classes.FUN_00922710(obj, className);
        AddReference(topLevelObject, &topLevelObject);
    }
};

struct ClassInfo;

struct Registry {
    virtual void DeleteThis(int flags) throw();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ClassInfo* GetClass(const char* name) const throw();
    unsigned short memSizeAndFlags;
    short referenceCount;
    __forceinline void RemoveReference()
    {
        if (memSizeAndFlags) {
            --referenceCount;
            if (referenceCount == 0)
                DeleteThis(1);
        }
    }
};

struct LoadingInfo {
    int fileVersion;
    const char* version;
    void* readerData;
};

struct Listener {
    const void* vtbl;
    FUN_00a47ee0* tracked;
    Registry* registry;
    LoadingInfo loading;
};

void __cdecl FUN_00a808b0(void* root, ClassInfo* type, Listener* listener) throw();

struct Header {
    int magic0;
    int magic1;
    int userTag;
    int fileVersion;
    int layoutRules;
    int numSections;
};

struct Section {
    char tag[20];
    int absoluteDataStart;
    int localFixupsOffset;
    int globalFixupsOffset;
    int virtualFixupsOffset;
    int exportsOffset;
    int importsOffset;
    int endOffset;
    __forceinline int GlobalBytes() const { return virtualFixupsOffset - globalFixupsOffset; }
    __forceinline int VirtualBytes() const { return exportsOffset - virtualFixupsOffset; }
};

struct SectionArray {
    char** data;
    int size;
    int capacityFlags;
    __forceinline char*& operator[](int index) { return data[index]; }
};

struct Reader {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual const char* GetVersion() const throw();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int FindSection(const char* name) const throw();
    virtual void* Resolve(int section, int offset) const throw();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* resource;
    Header* header;
    Section* sections;
    SectionArray sectionData;
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    FUN_00a47ee0* tracked;

    Registry* FUN_00a46950() throw();
    const char* FUN_00a460a0() const throw();
    void* FUN_00a46060() const throw();
    FUN_00a47ee0* FUN_00a47470();
};

FUN_00a47ee0* Reader::FUN_00a47470()
{
    if (!tracked) {
        tracked = new FUN_00a47ee0(resource);
        bool isOldVersion = (header->fileVersion == 1);
        for (int sectionIndex = 0; sectionIndex < header->numSections; ++sectionIndex) {
            if (sectionData[sectionIndex]) {
                Section& section = sections[sectionIndex];
                char* base = sectionData[sectionIndex];
                if (!isOldVersion) {
                    int* fixups = reinterpret_cast<int*>(base + section.globalFixupsOffset);
                    for (int wordIndex = 0; wordIndex < section.GlobalBytes() / 4; wordIndex += 3) {
                        int srcOffset = fixups[wordIndex];
                        if (srcOffset != -1) {
                            int dstSection = fixups[wordIndex + 1];
                            int dstOffset = fixups[wordIndex + 2];
                            void* target = Resolve(dstSection, dstOffset);
                            tracked->AddReference(target, base + srcOffset);
                        }
                    }
                }
                int* vfixups = reinterpret_cast<int*>(base + section.virtualFixupsOffset);
                for (int wordIndex = 0; wordIndex < section.VirtualBytes() / 4; wordIndex += 3) {
                    int srcOffset = vfixups[wordIndex];
                    if (srcOffset != -1) {
                        int dstSection = vfixups[wordIndex + 1];
                        int dstOffset = vfixups[wordIndex + 2];
                        void* obj = Resolve(sectionIndex, srcOffset);
                        const char* className = static_cast<const char*>(Resolve(dstSection, dstOffset));
                        tracked->AddObject(obj, className);
                    }
                }
            }
        }
        tracked->SetTopLevelObject(FUN_00a46060(), FUN_00a460a0());
        if (isOldVersion) {
            Registry* registry = FUN_00a46950();
            const char* ver = GetVersion();
            int fileVer = header->fileVersion;
            Listener listener;
            listener.vtbl = &DAT_00e86230;
            listener.tracked = tracked;
            listener.registry = registry;
            listener.loading.fileVersion = fileVer;
            listener.loading.version = ver;
            listener.loading.readerData = &unk08;
            ClassInfo* rootType = registry->GetClass(FUN_00a460a0());
            FUN_00a808b0(tracked->topLevelObject, rootType, &listener);
            registry->RemoveReference();
        }
    }
    return tracked;
}

}

// @f3 0x00a50bd0 (community match, verified in this file)
extern void* FUN_00e84bf8;
extern void* FUN_00e84ba4;
extern unsigned int DAT_010f3170;
namespace f3m_00a50bd0 {
struct Sub50;


struct Base97 {
    virtual void vfnBase();
    Base97(int flag);
};

struct Ref50 {
    int unk00;
    unsigned short cnt04;
    unsigned short cnt06;
};

struct Arr50 {
    void* data;
    int size;
    int capacity;
    Arr50() : data(0), size(0), capacity(0x80000000) {}
};

struct FUN_00a50bd0 : Base97 {
    int unk04;
    int unk08;
    Ref50* ref;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    Arr50 edges;
    Sub50* sub;
    FUN_00a50bd0(Ref50* r);
    virtual void vfnOwn();
};

struct Alloc50 {
    Sub50* FUN_008f6d30(unsigned int size, int tag);
};

struct Sub50 {
    int unk00;
    unsigned short a04;
    unsigned short a06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00a50bd0* owner;
};

extern void* (__stdcall* DAT_00d9b080)(unsigned long);

// pdb: hkpConstraintChainInstance::hkpConstraintChainInstance | hkpConstraintChainInstance.obj | fnv360_0822_retail, call_gap, high
// pdb params: data
FUN_00a50bd0::FUN_00a50bd0(Ref50* r) : Base97(1)
{
    ref = r;
    if (r->cnt04 != 0) {
        r->cnt06 = r->cnt06 + 1;
    }
    unk14 = 0;
    unk18 = 0;
    Alloc50* alloc = reinterpret_cast<Alloc50*>(DAT_00d9b080((unsigned long)DAT_010f3170));
    Sub50* s = alloc->FUN_008f6d30(0x1c, 0x29);
    s->unk08 = 0;
    s->unk0C = 0;
    s->unk10 = 0;
    s->unk14 = 0;
    s->owner = this;
    s->a04 = 0x1c;
    s->a06 = 1;
    *(void**)s = &FUN_00e84ba4;
    sub = s;
}
}   // namespace f3m_00a50bd0

// @f3 0x00a4a360 (community match, verified in this file)
namespace f3m_00a4a360 {
namespace f3m_00a4a360_cand {
struct TokThreadMemory;
extern TokThreadMemory* (__stdcall* const DAT_00d9b080)(unsigned int);


struct TokThreadMemory

{

    void deallocateChunk(void* p, int nbytes, int memoryClass);

};



template <class T> inline void TokDeallocateChunk(T* const& p, int numElements, int memoryClass)

{

    TokThreadMemory* mem = DAT_00d9b080(::DAT_010f3170);

    mem->deallocateChunk(p, numElements * sizeof(T), memoryClass);

}



void __cdecl TokArrayReserve(void* array, int numElements, int elementSize);

void __cdecl TokArrayReserveMore(void* array, int elementSize);

int __cdecl TokStrLen(const char* s);

void __cdecl TokMemCpy(void* dst, const void* src, int n);



struct TokCharArray

{

    char* m_data;

    int m_size;

    int m_capacityAndFlags;



    TokCharArray() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}

    int getCapacity() const

    {

        return m_capacityAndFlags & 0x3fffffff;

    }

    void reserve(int n)

    {

        if (getCapacity() < n)

            TokArrayReserve(this, n, sizeof(char));

    }

    void setSize(int n)

    {

        int cap = getCapacity();

        if (cap < n)

        {

            int grown = cap * 2;

            if (n >= grown)

                grown = n;

            TokArrayReserve(this, grown, sizeof(char));

        }

        m_size = n;

    }

    void pushBack(char c) {
        if (m_size == getCapacity())
            TokArrayReserveMore(this, sizeof(char));
        char* data = m_data;
        data[m_size] = c;
        m_size++;
    }

    void releaseMemory()

    {

        if ((m_capacityAndFlags & 0x80000000) == 0)

            TokDeallocateChunk(m_data, getCapacity(), 0x17);

    }

};



struct TokString

{

    TokCharArray m_string;

    __forceinline TokString& operator=(const char* s)

    {

        if (s && *s)

        {

            int len = TokStrLen(s);

            m_string.setSize(len + 1);

            TokMemCpy(m_string.m_data, s, len + 1);

        }

        else

        {

            m_string.setSize(1);

            m_string.m_data[0] = 0;

        }

        return *this;

    }

};



struct TokStreamReader

{

    virtual ~TokStreamReader();

    virtual bool isOk() const;

    virtual void v08();

    virtual void v0c();

    virtual int read(void* buf, int nbytes);

    virtual int skip(int nbytes);

    virtual void v18();

    virtual int setMark(int markLimit);

    virtual int rewindToMark();

    int ReadChar();

};



// pdb: eatWhiteSpace | hkIStream.obj | fnv360_0822_retail, call_seq, high (was: SkipWhitespace)
static __declspec(noinline) void eatWhiteSpace(TokStreamReader* reader)
{
    char buf[64];
    int n;
    do
    {
        reader->setMark(64);
        n = reader->read(buf, 64);
        for (int i = 0; i < n; i++)
        {
            char c = buf[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                reader->rewindToMark();
                reader->skip(i);
                return;
            }
        }
    } while (n);
}

struct TokIstream

{

    int unk00;

    int unk04;

    TokStreamReader* m_streamReader;

    TokIstream& FUN_00a4a360(TokString& str);

};



TokIstream& TokIstream::FUN_00a4a360(TokString& str)

{

    TokString bufStr;
    TokCharArray& buf = bufStr.m_string;

    buf.reserve(64);

    eatWhiteSpace(m_streamReader);

    m_streamReader->setMark(1);

    int c = m_streamReader->ReadChar();

    while (c != -1 && c != ' ' && c != '\t' && c != '\r' && c != '\n')

    {

        buf.pushBack((char)c);

        m_streamReader->setMark(1);

        c = m_streamReader->ReadChar();

    }

    m_streamReader->rewindToMark();

    buf.pushBack(0);

    str = buf.m_data;

    buf.releaseMemory();

    return *this;

}

}
}   // namespace f3m_00a4a360

// @f3 0x00a4bac0 (community match, verified in this file)
extern const char DAT_00e867a4[];
extern const char DAT_00e8678c[];
extern const char DAT_00e86780[];
extern const char DAT_00e86740[];
extern const char DAT_00e86730[];
extern const char DAT_00dc0cd8[];
extern const char DAT_00db3438[];
namespace f3m_00a4bac0 {
namespace f3m_00a4bac0_cand {

struct S4bac0_Indent {
    char* m_data;
    int m_size;
    unsigned int m_capacity;
};

struct S4bac0_Out {
    void FUN_009436f0(int c);
    void FUN_00943710(const char* text);
    void FUN_009439c0(const char* text, int length);
};

int __cdecl FUN_00943960(S4bac0_Out* out, const char* format, ...);
extern void __cdecl FUN_00901e90(void*, int, int);

struct S4bac0_Member;
struct S4bac0_List {
    int FUN_009b0630() const;
    const S4bac0_Member& FUN_009b0650(int index) const;
};

struct S4bac0_Type {
    const char* m_name;
    S4bac0_List* m_list;
    int FUN_0093dac0();
    int FUN_0093dab0();
    const S4bac0_List& FUN_0093d890();
};

struct S4bac0_Array {
    char* m_data;
    int m_count;
};

struct S4bac0_Conv {
    virtual void vfn00();
    virtual int FormatValue(int value, void* dst, int size);
};

struct S4bac0_Ctx {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    S4bac0_Conv* m_conv;
};

struct S4bac0_Pair {
    int m_first;
    int m_second;
};

S4bac0_Pair* __cdecl FUN_00a4c6e0(char* p);
int __cdecl FUN_00a4bd40(S4bac0_Indent* buf, const S4bac0_Member& member, const void* object, S4bac0_Out* os, void* context);

static void __declspec(noinline) FUN_00a4b800(S4bac0_Indent* buf, int count) {
    int s = buf->m_size + count + 1;
    int oldSize = buf->m_size;
    if (s > oldSize) {
        unsigned int cap = buf->m_capacity & 0x3fffffff;
        if ((int)cap < s) {
            cap += cap;
            if (s >= (int)cap)
                cap = s;
            FUN_00901e90(buf, cap, 1);
        }
        for (int i = oldSize; i < s; ++i)
            buf->m_data[i] = 9;
    }
    buf->m_size = s;
    buf->m_data[buf->m_size - 1] = 0;
    --buf->m_size;
}

static void __declspec(noinline) FUN_00a4b2c0(int kind, S4bac0_Out* out, char* p, S4bac0_Ctx* ctx) {
    if (kind == 1) {
        out->FUN_009439c0(p, (int)ctx);
    } else if (kind == 2) {
        out->FUN_00943710(p);
    }
}

static int __declspec(noinline) FUN_00a4b880(S4bac0_Indent* buf, const S4bac0_List& klass, const void* object, S4bac0_Out* os, void* context) {
    FUN_00943960(os, DAT_00e86740, buf->m_data);
    FUN_00a4b800(buf, 1);
    for (int i = 0; i < klass.FUN_009b0630(); i++)
        FUN_00a4bd40(buf, klass.FUN_009b0650(i), object, os, context);
    FUN_00a4b800(buf, -1);
    FUN_00943960(os, DAT_00e86730, buf->m_data);
    return 0;
}
}
void __cdecl FUN_00a4bac0(f3m_00a4bac0_cand::S4bac0_Indent* indent, f3m_00a4bac0_cand::S4bac0_Type* type, f3m_00a4bac0_cand::S4bac0_Array* arr, f3m_00a4bac0_cand::S4bac0_Out* out, f3m_00a4bac0_cand::S4bac0_Ctx* ctx)
{
    using namespace f3m_00a4bac0_cand;
    S4bac0_Array* a = *(S4bac0_Array* volatile*)&arr;
    int stride = type->FUN_0093dac0();
    char* p = a->m_data;
    int kind = type->FUN_0093dab0();
    if (a->m_count == 0)
        return;
    FUN_00a4b800(indent, 1);
    switch (kind) {
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 18:
    case 20: case 29: case 30: {
        int step = ((unsigned int)(kind - 12) > 6) ? 16 : 1;
        for (int i = 0; i < a->m_count; ++i) {
            if (i % step != 0 && kind != 29)
                out->FUN_009436f0(' ');
            else
                FUN_00943960(out, DAT_00e867a4, indent->m_data);
            FUN_00a4b2c0(kind, out, p, ctx);
            p += stride;
        }
        break;
    }
    case 19:
        FUN_00943960(out, DAT_00e8678c, type->m_name);
        break;
    case 25:
        for (int i = 0; i < a->m_count; ++i) {
            FUN_00a4b880(indent, type->FUN_0093d890(), p, out, ctx);
            p += stride;
        }
        break;
    case 28:
        for (int i = 0; i < a->m_count; ) {
            S4bac0_Pair* item = FUN_00a4c6e0(p);
            unsigned int first[0x40];
            unsigned int second[0x40];
            ctx->m_conv->FormatValue(item->m_first, first, 0x100);
            ctx->m_conv->FormatValue(item->m_second, second, 0x100);
            ++i;
            FUN_00943960(out, DAT_00e86780, first, second, (i < a->m_count) ? DAT_00dc0cd8 : DAT_00db3438);
            p += stride;
        }
        break;
    }
    FUN_00a4b800(indent, -1);
    FUN_00943960(out, DAT_00e867a4, indent->m_data);
}
}   // namespace f3m_00a4bac0

// @f3 0x00a5a1f0 (community match, verified in this file)
#pragma intrinsic(_ReadWriteBarrier)
namespace f3m_00a5a1f0 {
extern "C" void _ReadWriteBarrier();
namespace f3m_00a5a1f0 {
struct Node { unsigned short id; };
struct Candidate { Node* node; float score; };
struct PairInfo {
    Node* left;
    Node* right;
    unsigned int unk08,unk0c;
    float baseScore;
};
struct Result { Node* left; Node* right; PairInfo* owner; unsigned int tag; float score; };
__forceinline float MinValue(float a,float b) { return a<b ? a : b; }
__forceinline float Baseline(const Array<Candidate>* first,const Array<Candidate>* second)
{
    if (first->size==0) return second->data[0].score;
    if (second->size==0) return first->data[0].score;
    return MinValue(first->data[0].score,second->data[0].score);
}

// pdb: hkGeomConvexHullBuilder::addWrappingLines | hkGeomConvexHullBuilder.obj | tesv_win, call_gap_sim, low
void __cdecl FUN_00a5a1f0(const float& threshold,PairInfo* pair,Array<Candidate>* first,Array<Candidate>* second,Array<Result>* output)
{
    float base=Baseline(first,second);
    Node* right=pair->right;
    for (int i=0;i<first->size;++i) {
        float delta=first->data[i].score-base;
        if (delta>threshold) break;
        Result value={first->data[i].node,right,pair,pair->left->id,delta+pair->baseScore};
        {
            int j=0;
            for (;j<output->size;++j) {
                if (output->data[j].left->id==value.left->id &&
                    output->data[j].right->id==value.right->id &&
                    output->data[j].tag==value.tag) {
                    if (output->data[j].score<value.score)
                        output->data[j]=value;
                    goto done_merge;
                }
            }
            output->append(value);
            done_merge:;
        }
    }
    Node* left=pair->left;
    for (int i=0;i<second->size;++i) {
        float delta=second->data[i].score-base;
        if (delta>threshold) break;
        Result value={left,second->data[i].node,pair,pair->right->id,delta+pair->baseScore};
        {
            int j=0;
            if (output->size>0) {
                Node* vl=left; _ReadWriteBarrier(); Result* d=output->data; unsigned short lid=vl->id;
                do {
                    if (d->left->id==lid &&
                        d->right->id==value.right->id &&
                        d->tag==value.tag) {
                        if (output->data[j].score<value.score)
                            output->data[j]=value;
                        goto done_merge2;
                    }
                    ++j;
                    ++d;
                } while (j<output->size);
            }
            output->append(value);
            done_merge2:;
        }
    }
}
}



}   // namespace f3m_00a5a1f0

// @f3 0x00a46850 (community match, verified in this file)
namespace f3m_00a46850 {
namespace f3m_00a46850 {

void __cdecl FUN_00901f10(void* array, int elemSize) throw();
int __cdecl FUN_00a498a0(int object, int a, int b, void* map);

struct Pair46850 {
    void** first;
    int second;
    int getSecond() const { return second; }
};

struct PairArray46850 {
    Pair46850* m_data;
    int m_size;
    int m_capacityAndFlags;

    void pushBack(void** first, int second) {
        if (m_size == (m_capacityAndFlags & 0x3fffffff)) {
            FUN_00901f10(this, sizeof(Pair46850));
        }
        Pair46850& dst = m_data[m_size++];
        dst.second = second;
        dst.first = first;
    }

    void removeAtAndCopy(int index) {
        m_size--;
        for (int j = index; j < m_size; ++j) {
            m_data[j] = m_data[j + 1];
        }
    }
};

struct PointerMap46850 {
    void** m_elem;
    int m_numElems;
    int m_hashMod;

    void FUN_00922710(void* key, int value) throw();
    int FUN_00922790(void* key) throw();
    int FUN_009227d0(void* key, int def) throw();
    bool isValid(int it) const { return it <= m_hashMod; }
};

struct Owner46850 {
    int unk00;
    PairArray46850* m_pairs;
    PointerMap46850* m_srcMap;
    PointerMap46850 m_visited;
    int m_a;
    int m_b;
    void* m_c;

    int FUN_00a46850(void** first, int second, PairArray46850* list);
};

int Owner46850::FUN_00a46850(void** first, int second, PairArray46850* list)
{
    m_pairs->pushBack(first, second);
    m_visited.FUN_00922710(first, 2);

    for (int i = 0; i < list->m_size; ) {
        Pair46850& item = list->m_data[i];
        void* key = *item.first;
        if (key != 0 && !m_visited.isValid(m_visited.FUN_00922790(key))) {
            item.second = m_srcMap->FUN_009227d0(key, item.getSecond());
            m_visited.FUN_00922710(key, 1);
            FUN_00a498a0(item.second, m_a, m_b, m_c);
            ++i;
        } else {
            list->removeAtAndCopy(i);
        }
    }
    return 0;
}

}
}   // namespace f3m_00a46850

// @f3 0x00a450c0 (community match, verified in this file)
namespace f3m_00a450c0 {
namespace f3m_00a450c0 {
struct SweepBounds
{
    unsigned int minX, minY, minZ, key;
    unsigned int maxX, maxY, maxZ, reserved;
};
struct SweepPair
{
    unsigned int first, second;
};

inline unsigned int separatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}

// Fake match: the same test as separatedYZ with the first box's third-axis minimum passed in as a value.
// It exists only so that the direct sweep below can hand a named copy of that minimum to its first two tests.
inline unsigned int separatedYZNamedMin(const SweepBounds& a, const SweepBounds& b, unsigned int minZ)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - minZ)) & 0x80000000u;
}

inline SweepPair* emitPair(const SweepBounds& a, const SweepBounds& b, SweepPair* out, SweepPair* end, int& skipped)
{
    if (out < end)
    {
        out->first = a.key;
        out->second = b.key;
        ++out;
    }
    else
        ++skipped;
    return out;
}

// Sweeps one box over the other list, four boxes at a time; the pair is always (list A key, list B key).
template <bool swapPairs>
__forceinline SweepPair* collideOneT(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                     int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0 = separatedYZ(*bounds, scan[0]);
        unsigned int d1 = separatedYZ(*bounds, scan[1]);
        unsigned int d2 = separatedYZ(*bounds, scan[2]);
        unsigned int d3 = separatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
                out = emitPair(scan[0], *bounds, out, end, skipped);
            if (!d1 && scan[1].minX <= maxX)
                out = emitPair(scan[1], *bounds, out, end, skipped);
            if (!d2 && scan[2].minX <= maxX)
                out = emitPair(scan[2], *bounds, out, end, skipped);
            if (!d3 && scan[3].minX <= maxX)
                out = emitPair(scan[3], *bounds, out, end, skipped);
        }
        scan += 4;
    }
    return out;
}

template <>
__forceinline SweepPair* collideOneT<false>(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out,
                                            SweepPair* end, int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        // Fake match: a named copy of the third-axis minimum, used by the first two tests only. It makes the
        // compiler combine the third-axis term before the second-axis term in those two tests and keep the
        // minimum in a register without a stack home, as the original does in this direction.
        const unsigned int minZ = bounds->minZ;
        unsigned int d0 = separatedYZNamedMin(*bounds, scan[0], minZ);
        unsigned int d1 = separatedYZNamedMin(*bounds, scan[1], minZ);
        unsigned int d2 = separatedYZ(*bounds, scan[2]);
        unsigned int d3 = separatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
                out = emitPair(*bounds, scan[0], out, end, skipped);
            if (!d1 && scan[1].minX <= maxX)
                out = emitPair(*bounds, scan[1], out, end, skipped);
            if (!d2 && scan[2].minX <= maxX)
                out = emitPair(*bounds, scan[2], out, end, skipped);
            if (!d3 && scan[3].minX <= maxX)
                out = emitPair(*bounds, scan[3], out, end, skipped);
        }
        scan += 4;
    }
    return out;
}

// Sweep-and-prune of two lists sorted on the first axis: writes the overlapping key pairs into the buffer, counts
// the pairs that did not fit, and returns the number written. The caller clears the skipped counter.
// pdb: hk1AxisSweep::collide | hk1AxisSweep.obj | fnv360_0822_retail, call_gap_sim + skyrim(call_gap_sim), high
int __cdecl hk1AxisSweep_collide(const SweepBounds* apBoundsA, int aiCountA, const SweepBounds* apBoundsB, int aiCountB,
                         SweepPair* __restrict pairs, int capacity, int& skipped)
{
    SweepPair* out = pairs;
    SweepPair* end = pairs + capacity;

    for (;;)
    {
        if (apBoundsA->minX > apBoundsB->minX)
        {
            out = collideOneT<true>(apBoundsB, apBoundsA, out, end, skipped);
            ++apBoundsB;
            if (--aiCountB <= 0)
                break;
        }
        else
        {
            out = collideOneT<false>(apBoundsA, apBoundsB, out, end, skipped);
            ++apBoundsA;
            if (--aiCountA <= 0)
                break;
        }
    }

    return (int)(out - pairs);
}
}
}   // namespace f3m_00a450c0

// @f3 0x00a523f0 (community match, verified in this file)
namespace f3m_00a523f0 {
// pdb: hkJacobianPoweredChainSchema_getLinearJacobians | hkpJacobianChainSchemas.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: schema
void* FUN_00a523f0(void* p)
{
    return (char*)p + 0x20;
}
}   // namespace f3m_00a523f0

// @f3 0x00a5e290 (community match, verified in this file)
namespace f3m_00a5e290 {
Flag __cdecl FUN_00a5e110(Ctx* ctx, Node* first, unsigned int tag);
namespace f3m_00a5e290 {
struct Context {
    unsigned int unk00;
    Node* nodes;
    int count;
};
struct Pair {
    Node* a;
    Node* b;
    int unk08, unk0c;
};
struct Pairs {
    Pair* data;
    int size;
    int capacity;
    Pair& operator[](int i) { return data[i]; }
};
}

// pdb: hkGeomConvexHullBuilder::isValidWrapping | hkGeomConvexHullBuilder.obj | tesv_win, call_seq, medium
Flag __cdecl FUN_00a5e290(f3m_00a5e290::Context* ctx, int otherCount, Flag forward, f3m_00a5e290::Pairs* pairs)
{
    Node* nodes = ctx->nodes;
    int marked = 0;
    for (int i = 0; i < ctx->count; ++i)
        ctx->nodes[i].w06 = 0;

    {
        Node* previous = forward ? pairs->data[0].a : pairs->data[0].b;
        for (int i = pairs->size - 1; i >= 0; --i) {
            Node* current = forward ? pairs->data[i].a : pairs->data[i].b;
            if (current == previous)
                continue;
            ++marked;
            previous = current;
            Node* entry = forward ? &nodes[current->w02] : current;
            if (entry->w06 == 3)
                return false;
            entry->w06 = 3;
        }
    }
    if (marked == 0)
        return true;

    {
        Node* previous = forward ? pairs->data[0].a : pairs->data[0].b;
        for (int i = pairs->size - 1; i >= 0; --i) {
            Node* current = forward ? pairs->data[i].a : pairs->data[i].b;
            if (current == previous)
                continue;
            previous = current;
            Node* entry = forward ? current : &nodes[current->w02];
            switch (entry->w06) {
            case 0:
                entry->w06 = 1;
                break;
            case 1:
                return false;
            case 3:
                entry->w06 = 2;
                break;
            }
        }
    }

    Flag valid = true;
    {
        Node* previous = forward ? pairs->data[0].a : pairs->data[0].b;
        for (int i = pairs->size - 1; i >= 0; --i) {
            Node* current = forward ? pairs->data[i].a : pairs->data[i].b;
            if (current == previous)
                continue;
            previous = current;
            Node* entry = forward ? current : &nodes[current->w02];
            if (entry->w06 == 1)
                valid = valid && FUN_00a5e110((Ctx*)ctx, entry, 1);
            Node* linked = &nodes[entry->w02];
            if (linked->w06 == 3)
                valid = valid && FUN_00a5e110((Ctx*)ctx, linked, 3);
        }
    }

    {
        Node* previous = forward ? pairs->data[0].a : pairs->data[0].b;
        for (int i = pairs->size - 1; i >= 0; --i) {
            Node* current = forward ? pairs->data[i].a : pairs->data[i].b;
            if (current == previous)
                continue;
            previous = current;
            Node* entry = forward ? current : &nodes[current->w02];
            if (entry->w06 != 2)
                continue;
            Flag allTwo = true;
            Node* scanPrevious = forward ? pairs->data[0].a : pairs->data[0].b;
            for (int j = pairs->size - 1; j >= 0; --j) {
                Node* scan = forward ? pairs->data[j].a : pairs->data[j].b;
                if (scan == scanPrevious)
                    continue;
                scanPrevious = scan;
                if (scan->w06 != 2) {
                    allTwo = false;
                    break;
                }
            }
            Flag anyUnmarked = false;
            for (int j = 0; j < ctx->count; ++j) {
                if (ctx->nodes[j].w06 == 0) {
                    anyUnmarked = true;
                    break;
                }
            }
            if (allTwo && anyUnmarked)
                valid = valid && FUN_00a5e110((Ctx*)ctx, entry, 3);
        }
    }

    const int count = ctx->count;
    for (int i = 0; i < count; ++i)
        valid = valid && ctx->nodes[i].w06 != 0;
    return valid;
}
}   // namespace f3m_00a5e290

// @f3 0x00a476e0 (community match, verified in this file)
// Resolves the global fixups of every loaded section, then, for files older than version 5, converts the
// loaded class descriptions into a new "__types__" section and repoints the fixups that referred to them.
struct Allocator;
extern "C" __declspec(dllimport) Allocator* __stdcall TlsGetValue(unsigned int);
namespace f3m_00a476e0 {
extern unsigned int DAT_010f3170;
struct Memory {
    void* FUN_008f6f60(int bytes, int memoryClass) throw();
    void FUN_008f6d90(void* data, int bytes, int memoryClass) throw();
};
inline Memory& GetMemory() throw() { return *(Memory*)::TlsGetValue(DAT_010f3170); }
template <class T> inline T* AllocateChunk(int count, int memoryClass) throw()
{
    return (T*)GetMemory().FUN_008f6f60(count * sizeof(T), memoryClass);
}
template <class T> inline void DeallocateChunk(T*& data, int count, int memoryClass) throw()
{
    GetMemory().FUN_008f6d90(data, count * sizeof(T), memoryClass);
}
void __cdecl FUN_00901e90(void*, int, int) throw();
void __cdecl FUN_00901f10(void*, int) throw();
void* __cdecl FUN_009234e0(void*, const void*, int) throw();
char* __cdecl FUN_009233b0(char*, const char*) throw();
struct ClassInfo {};
extern ClassInfo DAT_0116c25c;
struct Item { void* object; const ClassInfo* type; int unk08; };
struct Pair { void* object; const ClassInfo* type; };
template <class T> struct Array {
    T* data;
    int size;
    int capacity;
    Array() throw() : data(0), size(0), capacity(0x80000000) {}
    // Fake match: the release is an explicit member, not a destructor. With destructors /EHsc builds an
    // unwind frame around the virtual call in the second pass, which the original lacks.
    void Release() throw()
    {
        if ((capacity & 0x80000000) == 0)
            DeallocateChunk<T>(data, GetCapacity(), 0x17);
    }
    int GetCapacity() const { return capacity & 0x3fffffff; }
    int GetSize() const { return size; }
    T* Begin() { return data; }
    void Reserve(int count)
    {
        if (GetCapacity() < count) {
            int next = 2 * GetCapacity();
            int newSize = (count < next) ? next : count;
            FUN_00901e90(this, newSize, sizeof(T));
        }
    }
    void SetSize(int count)
    {
        Reserve(count);
        size = count;
    }
    void PushBack(const T& item)
    {
        if (size == GetCapacity())
            FUN_00901f10(this, sizeof(T));
        data[size] = item;
        size++;
    }
    T* ExpandBy(int count)
    {
        int previous = size;
        SetSize(previous + count);
        return data + previous;
    }
    T& operator[](int index) { return data[index]; }
};
struct Map {
    void* data;
    int count, mask;
    Map() throw() { FUN_00922cb0(); }
    void FUN_00922cb0() throw();
    void FUN_00922cf0() throw();
    void FUN_00922710(const void*, int) throw();
    int FUN_009227d0(const void*, int) throw();
};
extern int DAT_00e862f0, DAT_00dcc494;
struct Counted {
    void* vtable;
    unsigned short memoryFlags, referenceCount;
    Counted() throw() : referenceCount(1) {}
};
struct TrackerBase : Counted {
    TrackerBase() throw() { vtable = &DAT_00e862f0; }
};
struct Tracker : TrackerBase {
    void* owner;
    char* output;
    int byteCount;
    Array<Pair> pairs;
    Map map;
    int lastIndex;
    Tracker(void* resource) throw() : owner(resource), output(0), lastIndex(-1) {}
    void Release() throw()
    {
        map.FUN_00922cf0();
        pairs.Release();
        vtable = &DAT_00dcc494;
    }
};
struct TypeDescriptor {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void FUN_009b0cc0(void*, int, const char*) throw();
};
struct VersionDescriptor { int flags; int* version; TypeDescriptor* type; int unk0c; };
extern TypeDescriptor DAT_0116c400;
extern unsigned int DAT_0116c418;
extern int DAT_01065090, DAT_01065068;
extern const char DAT_00e86358[], DAT_00e862b8[];
extern VersionDescriptor DAT_0116c3f0;
void __cdecl FUN_00d98ff0() throw();
int __cdecl FUN_00c00d1f(void (__cdecl*)()) throw();
void __cdecl FUN_00940060(Array<Pair>*, Tracker*, VersionDescriptor*, TypeDescriptor*) throw();
struct Header {
    int magic0, magic1, userTag, fileVersion, layoutRules, numSections;
};
struct Section {
    char tag[20];
    int absoluteDataStart, localFixupsOffset, globalFixupsOffset, virtualFixupsOffset, exportsOffset, importsOffset, endOffset;
    int GlobalSize() const { return virtualFixupsOffset - globalFixupsOffset; }
};
struct Resource {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    Array<void*> allocations;
};
struct Reader {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual const ClassInfo* GetClass(int, int) throw();
    int unk04, unk08, unk0c, unk10, unk14;
    Resource* resource;
    Header* header;
    Section* sections;
    Array<char*> sectionData;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
    Array<void*> convertedClasses;
    void FUN_00a461e0(Array<Item>*) throw();
    int FUN_00a476e0();
};
int Reader::FUN_00a476e0()
{
    for (int sectionIndex = 0; sectionIndex < header->numSections; ++sectionIndex) {
        if (sectionData[sectionIndex]) {
            char* data = sectionData[sectionIndex];
            Section& section = sections[sectionIndex];
            int* fixups = (int*)(data + section.globalFixupsOffset);
            for (int i = 0; i < section.GlobalSize() / (int)sizeof(int); i += 3) {
                int sourceOffset = fixups[i];
                if (sourceOffset != -1) {
                    int targetSection = fixups[i + 1];
                    int targetOffset = fixups[i + 2];
                    const ClassInfo* value = GetClass(targetSection, targetOffset);
                    *(const ClassInfo**)(data + sourceOffset) = value;
                }
            }
        }
    }
    if (header->fileVersion < 5) {
        Array<Item> objects;
        FUN_00a461e0(&objects);
        if (objects.GetSize() > 0) {
            Array<Pair> converted;
            converted.SetSize(objects.GetSize());
            Pair* pair = converted.Begin();
            for (int i = 0; i < converted.GetSize(); ++i) {
                pair[i].object = objects.data[i].object;
                pair[i].type = &DAT_0116c25c;
            }
            Tracker tracker(resource);
            if (!(DAT_0116c418 & 1)) {
                DAT_0116c418 |= 1;
                DAT_0116c400.FUN_009b0cc0(&DAT_01065090, -1, DAT_00e86358);
                FUN_00c00d1f(FUN_00d98ff0);
            }
            int versions[5] = { 0, 0, 0x0ef90576, 0x0ef90576, 0x0ef90576 };
            if ((unsigned int)header->fileVersion < 5)
                DAT_01065068 = versions[header->fileVersion];
            if (!(DAT_0116c418 & 2)) {
                DAT_0116c418 |= 2;
                DAT_0116c3f0.flags = 0;
                DAT_0116c3f0.version = &DAT_01065068;
                DAT_0116c3f0.type = &DAT_0116c400;
                DAT_0116c3f0.unk0c = 0;
            }
            FUN_00940060(&converted, &tracker, &DAT_0116c3f0, &DAT_0116c400);
            int numSections = header->numSections;
            Section* replacement = AllocateChunk<Section>(numSections + 1, 5);
            resource->allocations.PushBack((void*)replacement);
            FUN_009234e0(replacement, sections, numSections * sizeof(Section));
            sections = replacement;
            header->numSections += 1;
            Section& extra = sections[numSections];
            FUN_009233b0(extra.tag, DAT_00e862b8);
            extra.tag[19] = 0;
            extra.absoluteDataStart = -1;
            extra.localFixupsOffset = tracker.byteCount;
            extra.globalFixupsOffset = tracker.byteCount;
            extra.virtualFixupsOffset = tracker.byteCount;
            extra.exportsOffset = tracker.byteCount;
            extra.importsOffset = tracker.byteCount;
            extra.endOffset = tracker.byteCount;
            int newSectionIndex = sectionData.GetSize();
            sectionData.PushBack(tracker.output);
            Map lookup;
            void** newClasses = convertedClasses.ExpandBy(objects.GetSize());
            for (int i = 0; i < converted.GetSize(); ++i) {
                lookup.FUN_00922710(objects.data[i].object, i);
                newClasses[i] = converted[i].object;
            }
            for (int sectionIndex = 0; sectionIndex < header->numSections; ++sectionIndex) {
                Section& section = sections[sectionIndex];
                char* data = sectionData[sectionIndex];
                int* fixups = (int*)(data + section.globalFixupsOffset);
                for (int i = 0; i < section.GlobalSize() / (int)sizeof(int); i += 3) {
                    int sourceOffset = fixups[i];
                    if (sourceOffset != -1) {
                        int targetSection = fixups[i + 1];
                        int targetOffset = fixups[i + 2];
                        const ClassInfo* type = GetClass(targetSection, targetOffset);
                        int index = lookup.FUN_009227d0(type, -1);
                        if (index != -1) {
                            fixups[i + 1] = newSectionIndex;
                            fixups[i + 2] = (char*)converted[index].object - tracker.output;
                            *(void**)(data + sourceOffset) = converted[index].object;
                        }
                    }
                }
            }
            lookup.FUN_00922cf0();
            tracker.Release();
            converted.Release();
        }
        objects.Release();
    }
    return 0;
}
}

// @f3 0x00a5d780 (community match, verified in this file)
namespace f3m_00a5d780 {
namespace f3m_00a5d780 {

void __cdecl FUN_00901e90(void* array, int capacity, int elemSize);
void __cdecl FUN_00901f10(void* array, int elemSize);

template <class T>
struct hkArray {
    T* data;
    int size;
    int capacityAndFlags;
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void setSize(int n)
    {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            FUN_00901e90(this, n < cap2 ? cap2 : n, sizeof(T));
        }
        size = n;
    }
    void pushBack(const T& e)
    {
        if (size == getCapacity())
            FUN_00901f10(this, sizeof(T));
        data[size] = e;
        size++;
    }
};

struct Entry {
    unsigned short u0;
    unsigned short u2;
    unsigned short u4;
    unsigned short type;
};

struct Obj {
    int unk00;
    hkArray<Entry> entries;
};

void __cdecl FUN_00a5d780(Obj* src, void* unused, Obj* dst, hkArray<unsigned short>* remap)
{
    remap->setSize(src->entries.size);
    int oldSize = dst->entries.size;
    for (int i = 0; i < src->entries.size; i++) {
        const Entry& e = src->entries.data[i];
        if (e.type == 1 || e.type == 2) {
            remap->data[i] = (unsigned short)dst->entries.size;
            dst->entries.pushBack(e);
        } else {
            remap->data[i] = 0xffff;
        }
    }
    for (int j = oldSize; j < dst->entries.size; j++) {
        Entry& e = dst->entries.data[j];
        e.u2 = remap->data[e.u2];
        e.u4 = remap->data[e.u4];
    }
}

}
}   // namespace f3m_00a5d780

// @f3 0x00a56910 (community match, verified in this file)
namespace f3m_00a56910 {
namespace ns_00a56910 {

struct Vec4 {
    float x;
    float y;
    float z;
    float w;

    __forceinline void add3clobberW(const Vec4& other) {
        x = x + other.x;
        y = other.y + y;
        z = z + other.z;
    }
};

struct ConvexShape {
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
    virtual void ConvertVertexIdsToVertices(const unsigned short* ids, int numIds, void* verticesOut);
};

struct ConvexTranslateShape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ConvexShape* childShape;
    int childShapeSize;
    Vec4 translation;

    void FUN_00a56910(const unsigned short* ids, int numIds, void* verticesOut);
};

// pdb: hkpConvexTranslateShape::convertVertexIdsToVerticesImpl | hkpConvexTranslateShape.obj | fnv360_0822_retail, objopen_prop, low
// pdb params: ids, numIds, verticesOut
void ConvexTranslateShape::FUN_00a56910(const unsigned short* ids, int numIds, void* verticesOut) {
    childShape->ConvertVertexIdsToVertices(ids, numIds, verticesOut);
    Vec4* base = (Vec4*)verticesOut;
    for (int i = 0; i < numIds; i++) {
        Vec4* ptr = &base[i];
        Vec4& vertex = *ptr;
        vertex.add3clobberW(translation);
    }
}

}
}   // namespace f3m_00a56910

// @f3 0x00a48490 (community match, verified in this file)
namespace f3m_00a48490 {
struct S_00a48490 {
    char pad[56];
    int m;
    void* FUN_00a48490();
};
void* S_00a48490::FUN_00a48490()
{
    return &m;
}
}   // namespace f3m_00a48490

// @f3 0x00a4c6e0 (community match, verified in this file)
namespace f3m_00a4c6e0 {
int __cdecl FUN_00a4c6e0(int p0)
{
    return p0;
}
}   // namespace f3m_00a4c6e0

// @f3 0x00a58840 (community match, verified in this file)
namespace f3m_00a58840 {
namespace ns_00a58840 {
typedef unsigned short hkUint16;
class hkBool
{
public:
    inline hkBool() {}
    inline hkBool(bool b) { m_bool = static_cast<char>(b); }
    inline operator bool() const { return m_bool != 0; }
    inline hkBool& operator=(bool e) { m_bool = static_cast<char>(e); return *this; }
private:
    char m_bool;
};
struct Edge
{
    hkUint16 m_vertex;
    hkUint16 m_next;
    hkUint16 m_mirror;
    hkUint16 m_info;
};
__forceinline bool SameStartDifferentEnd(const Edge* edges, const Edge* x, const Edge* y)
{
    return x != y && x->m_vertex == y->m_vertex && edges[x->m_next].m_vertex != edges[y->m_next].m_vertex;
}
__forceinline bool NotDuplicate(const Edge* edges, const Edge* x, const Edge* y)
{
    return (x != y && x->m_vertex == y->m_vertex) ? edges[x->m_next].m_vertex != edges[y->m_next].m_vertex : true;
}
__forceinline bool Compatible(const Edge* edges, const Edge* x, const Edge* y)
{
    const Edge* next = &edges[x->m_next];
    return (next->m_vertex == y->m_vertex && edges[y->m_next].m_vertex == x->m_vertex) ? next == y : true;
}
union GroupVerdict
{
    const Edge* next;
    int word;
    bool Accepted() const { return static_cast<unsigned char>(word) != 0; }
};
__forceinline void Evaluate(const Edge* edges, const Edge* a, const Edge* c, const Edge* other, GroupVerdict& result)
{
    if ((NotDuplicate(edges, a, other) && !NotDuplicate(edges, c, other)) || Compatible(edges, a, other)) {
        result.next = &edges[c->m_next];
        if (result.next->m_vertex == other->m_vertex && edges[other->m_next].m_vertex == c->m_vertex) {
            result.word = result.next == other;
            return;
        }
    }
    result.word = 1;
}
// pdb: hkGeomConvexHullBuilder::PlaneAndPoints::findPair | hkGeomConvexHullBuilder.obj | tesv_win, call_gap, low
hkBool __cdecl FUN_00a58840(const Edge* edges, const Edge* a, const Edge* b, const Edge* c, const Edge* d)
{
    bool first = SameStartDifferentEnd(edges, a, b);
    bool second = SameStartDifferentEnd(edges, c, d);
    hkBool result = first && second;
    if (result)
    {
        GroupVerdict groupD;
        Evaluate(edges, a, c, d, groupD);
        GroupVerdict groupB;
        Evaluate(edges, a, c, b, groupB);
        result = groupD.Accepted() && groupB.Accepted();
    }
    return result;
}
}
}   // namespace f3m_00a58840

// @f3 0x00a485f0 (community match, verified in this file)
namespace f3m_00a485f0 {
namespace xpr55 {

struct TypeInfo;
struct ClassRecord;

// Untyped pointer map with out-of-line members.
struct PointerMapBase
{
    void* entries;
    int count;
    int mask;
    unsigned long getWithDefault(unsigned long key, unsigned long def) const throw();
    void insert(unsigned long key, unsigned long value) throw();
};

// Typed front over the untyped map.
template <typename K, typename V>
struct PointerMap
{
    PointerMapBase m_map;
    V getWithDefault(K key, V def) const throw() { return (V)m_map.getWithDefault((unsigned long)key, (unsigned long)def); }
    void insert(K key, V value) throw() { m_map.insert((unsigned long)key, (unsigned long)value); }
};

struct Variant
{
    void* m_object;
    const ClassRecord* m_class;
};

template <typename T>
struct Array
{
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    int getSize() const throw() { return m_size; }
    T& operator[](int i) throw() { return m_data[i]; }
};

struct TypeInfoRegistry
{
    virtual ~TypeInfoRegistry() throw();
    virtual void registerTypeInfo(const TypeInfo* info) throw();
    virtual const TypeInfo* findTypeInfo(const char* name) const throw();
    virtual const TypeInfo* registerFinish(const char* name) const throw();
    virtual const TypeInfo* finishLoadedObject(void* obj, const char* className) const throw();
};

struct PackfileData
{
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    char* m_name;
    int m_hasEverTrackedObjects;
    PointerMap<void*, const TypeInfo*> m_trackedObjects;
    int hasEverTrackedObjects() const throw();
    void trackObject(void* o, const TypeInfo* t) throw() { m_hasEverTrackedObjects = 1; m_trackedObjects.insert(o, t); }
};

struct UpdateTracker
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PointerMap<void*, const char*> m_classNameFromObject;
    void* m_topLevelObject;
};

struct StringMapBase
{
    void* entries;
    int count;
    int mask;
    int spare;
};

struct XmlPackfileReader
{
    void* vtable;
    unsigned short memSizeAndFlags;
    short referenceCount;
    int unk08, unk0c, unk10, unk14;
    PackfileData* m_data;
    Array<char*> m_knownSections;
    StringMapBase m_sectionTagToIndex;
    Array<Variant> m_loadedObjects;
    UpdateTracker* m_tracker;

    void warnIfNotUpToDate() const throw();
    void* FUN_00a485f0(const char* expectedClassName, const TypeInfoRegistry* finishRegistry);
};

int strCmp(const char* a, const char* b) throw();

void* XmlPackfileReader::FUN_00a485f0(const char* expectedClassName, const TypeInfoRegistry* finishRegistry)
{
    warnIfNotUpToDate();
    if (m_data->hasEverTrackedObjects())
    {
        return m_tracker->m_topLevelObject;
    }
    if (finishRegistry)
    {
        for (int i = 0; i < m_loadedObjects.getSize(); ++i)
        {
            Variant& v = m_loadedObjects[i];
            if (const char* className = m_tracker->m_classNameFromObject.getWithDefault(v.m_object, 0))
            {
                const TypeInfo* info = finishRegistry->finishLoadedObject(v.m_object, className);
                if (info)
                {
                    m_data->trackObject(v.m_object, info);
                }
            }
        }
    }
    UpdateTracker* tracker = m_tracker;
    const char* topLevelClassName = tracker->m_classNameFromObject.getWithDefault(tracker->m_topLevelObject, 0);
    if (expectedClassName && strCmp(expectedClassName, topLevelClassName) != 0)
    {
        return 0;
    }
    return m_tracker->m_topLevelObject;
}

}
}   // namespace f3m_00a485f0

// @f3 0x00a5d9c0 (community match, verified in this file)
namespace f3m_00a5d9c0 {
namespace f3m_00a5d9c0 {
extern "C" __declspec(dllimport) void* __stdcall FUN_00d9b080(unsigned long) throw();

struct ThreadMemory_a5d9 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void* allocateStackSlow(int nbytes) throw();
    virtual void popStack(void* p) throw();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* m_current;
    int unk24;
    char* m_previous;
    char* m_end;
    void FUN_008f6d90(void* p, int nbytes, int cls) throw();
    static ThreadMemory_a5d9& getInstance() { return *(ThreadMemory_a5d9*)FUN_00d9b080(DAT_010f3170); }
    void* allocateStack(int nbytes)
    {
        int aligned = (nbytes + 16) & ~15;
        char* current = m_current;
        char* next = current + aligned;
        if (next <= m_end) {
            m_current = next;
            return current;
        }
        return allocateStackSlow(aligned);
    }
    void deallocateStack(void* p)
    {
        m_current = (char*)p;
        if (p == m_previous)
            popStack(p);
    }
};

template <typename T> inline void deallocateStack(T* p)
{
    ThreadMemory_a5d9::getInstance().deallocateStack(p);
}

extern "C" void __cdecl FUN_00901e90(void* arr, int capacity, int stride) throw();

struct Bool_a5d9 {
    Bool_a5d9(bool b) { m_bool = (char)b; }
    operator bool() const { return m_bool != 0; }
    char m_bool;
};

template <typename T> struct Array_a5d9 {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    __forceinline Array_a5d9() throw() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000) {}
    __forceinline ~Array_a5d9() throw()
    {
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory_a5d9::getInstance().FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
    int getSize() const { return m_size; }
    int getCapacity() const { return m_capacityAndFlags & 0x3fffffff; }
    void clear() { m_size = 0; }
    void reserveExactly(int n)
    {
        if (getCapacity() < n)
            FUN_00901e90(this, n, sizeof(T));
    }
    T& expandOne()
    {
        int old = m_size;
        m_size = old + 1;
        return m_data[old];
    }
};

template <typename T> struct LocalArray_a5d9 {
    T* m_data;
    int m_size;
    int m_capacityAndFlags;
    T* m_localMemory;
    __forceinline LocalArray_a5d9(int n) throw() : m_data(0), m_size(0), m_capacityAndFlags(0x80000000)
    {
        m_data = (T*)ThreadMemory_a5d9::getInstance().allocateStack(n * sizeof(T));
        m_capacityAndFlags = n | 0x80000000;
        m_localMemory = m_data;
    }
    __forceinline void destroy() throw()
    {
        deallocateStack<T>(m_localMemory);
        if ((m_capacityAndFlags & 0x80000000) == 0) {
            int cap = m_capacityAndFlags & 0x3fffffff;
            ThreadMemory_a5d9::getInstance().FUN_008f6d90(m_data, cap * sizeof(T), 0x17);
        }
    }
};

struct Edge_a5d9 {
    unsigned short vertex;
    unsigned short twin;
    unsigned short next;
    unsigned short flags;
    Bool_a5d9 hasTwin() const { return flags == 2; }
};

struct Mesh_a5d9 {
    int unk00;
    Edge_a5d9* data;
    int size;
};

struct Out_a5d9 {
    int unk00;
    Array_a5d9<Edge_a5d9> edges;
};

struct Rec_a5d9 {
    Edge_a5d9* e0;
    Edge_a5d9* e1;
    unsigned short s8;
    unsigned short sA;
    unsigned short sC;
    unsigned short sE;
};

struct Recs_a5d9 {
    Rec_a5d9* data;
    int size;
};

void __cdecl FUN_00a5d780(Mesh_a5d9* mesh, Bool_a5d9 first, Out_a5d9* out, LocalArray_a5d9<unsigned short>* map) throw();

inline Edge_a5d9* mapEdge(Array_a5d9<Edge_a5d9>& edges, int v)
{
    if (v == 0xffff)
        return 0;
    return &edges.m_data[v];
}
}
using namespace f3m_00a5d9c0;

void __cdecl FUN_00a5d9c0(Mesh_a5d9* meshA, Mesh_a5d9* meshB, Recs_a5d9* recs, Out_a5d9* out)
{
    out->edges.clear();
    LocalArray_a5d9<unsigned short> mapA(meshA->size);
    FUN_00a5d780(meshA, true, out, &mapA);
    LocalArray_a5d9<unsigned short> mapB(meshB->size);
    FUN_00a5d780(meshB, false, out, &mapB);

    out->edges.reserveExactly(recs->size * 3 + out->edges.getSize());

    for (int i = 0; i < recs->size; i++) {
        Rec_a5d9& r = recs->data[i];
        Edge_a5d9* e0 = r.e0;
        r.s8 = e0->vertex;
        r.sC = meshA->data[e0->next].vertex;
        r.sE = r.e1->vertex;
        int ia = e0 - meshA->data;
        int ib = &meshB->data[r.e1->twin] - meshB->data;
        r.e0 = mapEdge(out->edges, mapA.m_data[ia]);
        r.e1 = mapEdge(out->edges, mapB.m_data[ib]);
    }

    Edge_a5d9* base = out->edges.m_data;
    Rec_a5d9* prev = recs->data;
    Edge_a5d9* prevEdge = 0;
    int prevIdx = 0xffff;
    int firstIdx = out->edges.getSize();
    for (int j = recs->size - 1; j >= 0; j--) {
        Rec_a5d9* r = &recs->data[j];
        int curIdx = out->edges.getSize();
        Edge_a5d9* cur = &out->edges.expandOne();
        int nextIdx = out->edges.getSize();
        Edge_a5d9* next = &out->edges.expandOne();
        if (r->e0 == prev->e0) {
            Edge_a5d9* e = r->e1;
            Bool_a5d9 hasTwin = e->hasTwin();
            int thirdIdx = hasTwin ? e->twin : out->edges.getSize();
            Edge_a5d9* third = hasTwin ? &base[e->twin] : &out->edges.expandOne();
            cur->vertex = r->e1->vertex;
            cur->next = (unsigned short)nextIdx;
            cur->twin = (unsigned short)prevIdx;
            if (prevEdge)
                prevEdge->twin = (unsigned short)curIdx;
            third->vertex = r->sE;
            third->next = (unsigned short)curIdx;
            third->twin = (unsigned short)(r->e1 - base);
            r->e1->twin = (unsigned short)thirdIdx;
            next->vertex = r->s8;
            next->next = (unsigned short)thirdIdx;
        } else {
            Edge_a5d9* e = r->e0;
            Bool_a5d9 hasTwin = e->hasTwin();
            int thirdIdx = hasTwin ? e->twin : out->edges.getSize();
            Edge_a5d9* third = hasTwin ? &base[e->twin] : &out->edges.expandOne();
            cur->vertex = r->sE;
            cur->next = (unsigned short)thirdIdx;
            cur->twin = (unsigned short)prevIdx;
            if (prevEdge)
                prevEdge->twin = (unsigned short)curIdx;
            third->vertex = r->sC;
            third->next = (unsigned short)nextIdx;
            third->twin = (unsigned short)(r->e0 - base);
            r->e0->twin = (unsigned short)thirdIdx;
            next->vertex = r->e0->vertex;
            next->next = (unsigned short)curIdx;
        }
        prevIdx = nextIdx;
        prev = r;
        prevEdge = next;
    }
    prevEdge->twin = (unsigned short)firstIdx;
    base[firstIdx].twin = (unsigned short)prevIdx;
    mapB.destroy();
    mapA.destroy();
}
}   // namespace f3m_00a5d9c0

// @f3 0x00a4bd40 (community match, verified in this file)
namespace S00a4bd40_xml {

struct Writer;
struct Enumeration;

struct Class {
    const char* FUN_009b0490() const throw();
    int FUN_009b0630() const throw();
    const struct Member* FUN_009b0650(int index) const throw();
    int FUN_009b0760() const throw();
};

struct Member {
    const char* name;
    const Class* classType;
    const Enumeration* enumeration;
    unsigned char type;
    unsigned char subtype;
    short cArraySize;
    unsigned short flags;
    unsigned short offset;
    int FUN_00a4aea0() const throw();
    const Class* FUN_0093d890() const throw();
    const Enumeration* FUN_0093d8d0() const throw();
    int FUN_0093d900() const throw();
    int FUN_0093db00(const void* value) const throw();
};

template <class T> struct Array {
    T* data;
    int size;
    int capacity;
};

struct Enumeration {
    int FUN_009b2320(int value, const char** name) const throw();
    int FUN_009b2470(int value, Array<const char*>* names, int* unknownBits) const throw();
};

struct StreamWriter;

struct Output {
    void* vtable;
    int unk04;
    StreamWriter* writer;
    StreamWriter* getStreamWriter() throw() { return writer; }
    Output* FUN_009436f0(char c) throw();
    Output* FUN_00943710(const char* text) throw();
    void FUN_009439c0(const char* text, int length) throw();
};
void __cdecl FUN_00943960(Output* output, const char* format, ...) throw();

struct ErrStream {
    void* vtable;
    int unk04;
    StreamWriter* writer;
    StreamWriter* getStreamWriter() throw() { return writer; }
    void FUN_00923070(char* buffer, int size) throw();
    Output* FUN_00943710(const char* text) throw();
    void FUN_00943a60() throw();
};

struct ErrorHandler {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* text, const char* file, int line) throw();
};

struct NameFromAddress {
    virtual void v00();
    virtual int getName(const void* address, char* buffer, int bufferSize) throw();
};

struct Flag {
    char value;
    Flag(bool b) : value(b) {}
};

struct Heap { void FUN_008f6d90(void* p, int size, int tag) throw(); };
extern void* (__stdcall* const DAT_00d9b080)(unsigned long index);
extern unsigned long DAT_010f3170;
extern void* DAT_010f3364;
extern int DAT_0116a994;

struct Writer {
    void* vtable;
    int unk04;
    Array<char> indent;
    char indentStorage[16];
    NameFromAddress* names;
    void FUN_00a4b980(StreamWriter* stream, const char* name, const char** attributes, Flag newline) throw();
    void FUN_00a4ba40(StreamWriter* stream, const char* name, Flag newline) throw();
};

void __cdecl FUN_00901e90(void* array, int capacity, int elementSize) throw();
const void* __cdecl FUN_00a4c6e0(const void* data) throw();
unsigned int __cdecl FUN_009233f0(const char* text) throw();

void __cdecl FUN_00a4bd40(Array<char>* indent, const Member* member, const void* object, Output* output, Writer* writer);
void __cdecl FUN_00a4bac0(Array<char>* indent, const Member* member, const void* data, Output* output, Writer* writer) throw();

static __declspec(noinline) int FUN_00a4b160(Output* output, const char* const* strings, int count)
{
    for (int i = 0; i < count; ++i) {
        const char* start = strings[i];
        if (start) {
            const char* p = start;
            for (; *p; ++p) {
                char c = *p;
                if (c > 0x14 && c < 0x7f) {
                    switch (c) {
                    case 0x22: case 0x26: case 0x27: case 0x3c: case 0x3e: {
                        output->FUN_009439c0(start, p - start);
                        start = p + 1;
                        const char* entities[6] = { "&&amp;", "<&lt;", ">&gt;", "\"&quot;", "'&apos;", 0 };
                        for (int j = 0; entities[j]; ++j) {
                            if (entities[j][0] == *p) {
                                const char* text = entities[j] + 1;
                                output->FUN_009439c0(text, FUN_009233f0(text));
                                break;
                            }
                        }
                        break;
                    }
                    }
                } else {
                    output->FUN_009439c0(start, p - start);
                    FUN_00943960(output, "&#%u;", (unsigned char)*p);
                    start = p + 1;
                }
            }
            output->FUN_009439c0(start, p - start);
        } else {
            output->FUN_00943710("&#9216;");
        }
    }
    return 0;
}

static __declspec(noinline) void FUN_00a4b2c0(int kind, const char* p, Output* out, Writer* ctx)
{
    if (kind == 1) {
        out->FUN_009439c0(p, reinterpret_cast<int>(ctx));
    } else if (kind == 2) {
        out->FUN_00943710(p);
    }
}

struct IndentArray {
    char* data;
    int size;
    int capacity;
    void reserve(int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n) {
            int doubled = cap * 2;
            FUN_00901e90(this, n < doubled ? doubled : n, 1);
        }
    }
    __forceinline void setSize(int n, char fill)
    {
        if (n > size) {
            reserve(n);
            for (int i = size; i < n; ++i)
                data[i] = fill;
        }
        size = n;
    }
};

static __declspec(noinline) void FUN_00a4b800(Array<char>* indent, int delta)
{
    IndentArray& text = *reinterpret_cast<IndentArray*>(indent);
    int newSize = delta + text.size + 1;
    text.setSize(newSize, '\t');
    text.data[newSize - 1] = 0;
    text.size--;
}

static __declspec(noinline) int FUN_00a4b880(Array<char>* indent, const Class* klass, const void* data, Output* output, Writer* writer)
{
    FUN_00943960(output, "\n%s<hkobject>", indent->data);
    FUN_00a4b800(indent, 1);
    for (int i = 0; i < klass->FUN_009b0630(); ++i)
        FUN_00a4bd40(indent, klass->FUN_009b0650(i), data, output, writer);
    FUN_00a4b800(indent, -1);
    FUN_00943960(output, "\n%s</hkobject>", indent->data);
    return 0;
}

struct Homogeneous {
    const Class* klass;
    const char* data;
    int size;
};

struct Variant {
    const void* object;
    const void* klass;
};

extern const char DAT_00db3438[];
extern const char DAT_00db97c0[];
extern const char DAT_00dbab78[];
extern const char DAT_00dc0cc8[];
extern const char DAT_00dc0cd8[];
extern const char DAT_00de1ee4[];
extern const char DAT_00dff2d4[];
extern const char DAT_00e03fdc[];
extern const char DAT_00e3be04[];
extern const char DAT_00e40028[];
extern const char DAT_00e7ff90[];
extern const char DAT_00e86404[];
extern const char DAT_00e866f4[];
extern const char DAT_00e86780[];
extern const char DAT_00e867a8[];
extern const char DAT_00e867b4[];
extern const char DAT_00e867dc[];
extern const char DAT_00e867fc[];
extern const char DAT_00e86818[];
extern const char DAT_00e86838[];
extern const char DAT_00e86858[];
extern const char DAT_00e8686c[];
extern const char DAT_00e86880[];
extern const char DAT_00e86894[];
extern const char DAT_00e868ac[];
extern const char DAT_00e868dc[];

void __cdecl FUN_00a4bd40(Array<char>* indent, const Member* member, const void* object, Output* output, Writer* writer)
{
    const char* value = static_cast<const char*>(object) + member->offset;
    if (member->flags & 0x400) {
        FUN_00943960(output, DAT_00e868dc, indent->data, member->name);
        return;
    }
    if (member->type == 20 && member->subtype == 2 && *reinterpret_cast<const void* const*>(value) == 0) {
        FUN_00943960(output, DAT_00e868ac, indent->data, member->name);
        return;
    }
    FUN_00943960(output, DAT_00e86894, indent->data, member->name);
    switch (member->type) {
    case 22: case 23: case 26:
        FUN_00943960(output, DAT_00e86880, reinterpret_cast<const Array<char>*>(value)->size);
        break;
    case 27:
        FUN_00943960(output, DAT_00e86880, reinterpret_cast<const Homogeneous*>(value)->size);
        break;
    }
    FUN_00943960(output, DAT_00dff2d4);

    switch (member->type) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 30: {
        int count = member->FUN_00a4aea0();
        int stride = member->FUN_0093d900() / count;
        const char* cursor = value;
        for (int i = 0; i < count; ++i) {
            if (member->type == 2) {
                FUN_00943960(output, DAT_00e866f4, *reinterpret_cast<const signed char*>(cursor));
            } else {
                if (i != 0)
                    FUN_00943960(output, static_cast<unsigned>(i) % 50 == 0 ? DAT_00de1ee4 : DAT_00dc0cd8);
                FUN_00a4b2c0(member->type, cursor, output, writer);
            }
            cursor += stride;
        }
        break;
    }
    case 19:
        FUN_00943960(output, DAT_00e8686c, member->name);
        break;
    case 29:
        FUN_00a4b160(output, reinterpret_cast<const char* const*>(value), member->FUN_00a4aea0());
        break;
    case 20: {
        int count = member->FUN_00a4aea0();
        if (member->subtype == 2) {
            FUN_00a4b160(output, reinterpret_cast<const char* const*>(value), count);
        } else {
            const void* const* pointers = reinterpret_cast<const void* const*>(value);
            for (int i = 0; i < count; ++i) {
                if (pointers[i]) {
                    unsigned int nameStorage[64];
                    char* name = reinterpret_cast<char*>(nameStorage);
                    writer->names->getName(pointers[i], name, 256);
                    FUN_00943960(output, DAT_00dbab78, name);
                } else {
                    output->FUN_00943710(DAT_00e7ff90);
                }
                if (i < count - 1)
                    output->FUN_00943710(DAT_00dc0cd8);
            }
        }
        break;
    }
    case 21: {
        int count = member->FUN_00a4aea0();
        for (int i = 0; i < count; ++i)
            output->FUN_00943710(DAT_00e7ff90);
        break;
    }
    case 22: case 23: case 26:
        FUN_00a4bac0(indent, member, value, output, writer);
        break;
    case 24: {
        const Enumeration* enumeration = member->FUN_0093d8d0();
        int number = member->FUN_0093db00(value);
        const char* name = 0;
        if (enumeration->FUN_009b2320(number, &name) == 0)
            FUN_00943960(output, name);
        else
            FUN_00943960(output, DAT_00e86858, number);
        break;
    }
    case 25: {
        FUN_00a4b800(indent, 1);
        const Class* klass = member->FUN_0093d890();
        int count = member->FUN_00a4aea0();
        int stride = klass->FUN_009b0760();
        const char* cursor = value;
        for (int i = 0; i < count; ++i) {
            FUN_00a4b880(indent, klass, cursor, output, writer);
            cursor += stride;
        }
        FUN_00a4b800(indent, -1);
        const char* text = indent->data;
        output->FUN_009436f0('\n')->FUN_00943710(text);
        break;
    }
    case 27: {
        const Homogeneous* array = reinterpret_cast<const Homogeneous*>(value);
        const Class* klass = array->klass;
        FUN_00a4b800(indent, 1);
        FUN_00943960(output, DAT_00e86838, indent->data);
        const char* attributes[5] = { 0 };
        attributes[0] = DAT_00e40028;
        attributes[1] = klass->FUN_009b0490();
        attributes[2] = DAT_00e3be04;
        attributes[3] = reinterpret_cast<Class*>(&DAT_0116a994)->FUN_009b0490();
        writer->FUN_00a4b980(output->getStreamWriter(), DAT_00e86404, attributes, true);
        for (int i = 0; i < reinterpret_cast<Class*>(&DAT_0116a994)->FUN_009b0630(); ++i)
            FUN_00a4bd40(indent, reinterpret_cast<Class*>(&DAT_0116a994)->FUN_009b0650(i), klass, output, writer);
        writer->FUN_00a4ba40(output->getStreamWriter(), DAT_00e86404, true);
        FUN_00943960(output, DAT_00e86818, indent->data);
        int stride = klass->FUN_009b0760();
        const char* data = array->data;
        for (int i = 0; i < array->size; ++i) {
            FUN_00a4b880(indent, klass, data, output, writer);
            data += stride;
        }
        FUN_00a4b800(indent, -1);
        break;
    }
    case 28: {
        int count = member->FUN_00a4aea0();
        const Variant* variants = reinterpret_cast<const Variant*>(value);
        for (int i = 0; i < count; ++i) {
            if (variants[i].object && variants[i].klass) {
                unsigned int objectNameStorage[64];
                char* objectName = reinterpret_cast<char*>(objectNameStorage);
                unsigned int classNameStorage[64];
                char* className = reinterpret_cast<char*>(classNameStorage);
                writer->names->getName(variants[i].object, objectName, 256);
                writer->names->getName(variants[i].klass, className, 256);
                FUN_00943960(output, DAT_00e86780, objectName, className, i + 1 < count ? DAT_00dc0cd8 : DAT_00db3438);
            }
        }
        break;
    }
    case 31: {
        const Enumeration* enumeration = member->FUN_0093d8d0();
        int number = member->FUN_0093db00(value);
        Array<const char*> names;
        names.data = 0;
        names.size = 0;
        names.capacity = 0x80000000;
        int unknownBits;
        enumeration->FUN_009b2470(number, &names, &unknownBits);
        for (int i = 0; i < names.size; ++i)
            FUN_00943960(output, DAT_00db97c0, i == 0 ? DAT_00db3438 : DAT_00e03fdc, names.data[i]);
        if (unknownBits)
            FUN_00943960(output, DAT_00e867fc, names.size == 0 ? DAT_00db3438 : DAT_00e03fdc, unknownBits);
        else if (names.size == 0)
            FUN_00943960(output, DAT_00dc0cc8);
        if ((names.capacity & 0x80000000) == 0) {
            int capacity = names.capacity & 0x3fffffff;
            Heap* heap = static_cast<Heap*>(DAT_00d9b080(DAT_010f3170));
            heap->FUN_008f6d90(names.data, capacity * sizeof(const char*), 0x17);
        }
        break;
    }
    default: {
        unsigned int bufferStorage[128];
        char* buffer = reinterpret_cast<char*>(bufferStorage);
        ErrStream stream;
        stream.FUN_00923070(buffer, 512);
        stream.FUN_00943710(DAT_00e867dc);
        static_cast<ErrorHandler*>(DAT_010f3364)->message(3, 0x40a18b57, buffer, DAT_00e867b4, 777);
        stream.FUN_00943a60();
        break;
    }
    }
    FUN_00943960(output, DAT_00e867a8);
}

}

// @f3 0x00a48970 (community match, verified in this file)
namespace Parse8970 {

extern __declspec(nothrow) void __cdecl FUN_00901f10(void*, int) throw();

template <class T>
struct Array {
    T* data;
    int size;
    int capacity;
    void append(const T& value)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        data[size] = value;
        ++size;
    }
    T& pushBack()
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00901f10(this, sizeof(T));
        return data[size++];
    }
    T& back()
    {
        return data[size - 1];
    }
};

extern int DAT_00e8637c, DAT_00e863b8;
extern const char DAT_00e86404[], DAT_00e86484[], DAT_00e86478[], DAT_00e86460[], DAT_00e86438[];
extern const char DAT_00e3be04[], DAT_00e40028[], DAT_00e7ffc4[], DAT_00e44a74[], DAT_00e44aac[], DAT_00e44a8c[], DAT_00e44a7c[], DAT_00e86280[], DAT_00e862b8[], DAT_00e863a4[], DAT_00e86394[];
extern const char DAT_00e7ff90[];
extern int DAT_0116cbc8, DAT_0116cc88, DAT_0116a994, DAT_0116a964, DAT_0116cbf8;
extern void* DAT_010f3364;
extern void* DAT_011693ac;
extern const char* DAT_01065098[];

extern __declspec(nothrow) int __cdecl hkString_strCmp(const char*, const char*) throw();
extern __declspec(nothrow) char* __cdecl FUN_00923640(const char*) throw();
extern __declspec(nothrow) int __cdecl hkString_atoi(const char*) throw();
extern __declspec(nothrow) void __cdecl FUN_009234e0(void*, const void*, int) throw();
extern __declspec(nothrow) int __cdecl FUN_009233f0(const char*) throw();
extern __declspec(nothrow) int __cdecl FUN_009232f0(const char*, const char*, int) throw();

struct Memory {
    virtual __declspec(nothrow) void v0() throw();
    virtual __declspec(nothrow) void v4() throw();
    virtual __declspec(nothrow) void v8() throw();
    virtual __declspec(nothrow) void vc() throw();
    virtual __declspec(nothrow) void v10() throw();
    virtual __declspec(nothrow) void* AllocateStack(int) throw();
    virtual __declspec(nothrow) void FreeStack(void*) throw();
    int f04, f08, f0c, f10, f14, f18, f1c;
    char* top20;
    char* end24;
    char* last28;
    char* limit2c;
    __declspec(nothrow) void* FUN_008f6f60(int, int) throw();
    __declspec(nothrow) void FUN_008f6f90(void*) throw();
    __declspec(nothrow) void FUN_008f6d90(void*, int, int) throw();
    __forceinline void* alloc(int n) throw()
    {
        char* p = top20;
        char* next = p + n;
        if (next <= limit2c) {
            top20 = next;
            return p;
        }
        return AllocateStack(n);
    }
    __forceinline void freeStack(char* p) throw()
    {
        top20 = p;
        if (p == last28)
            FreeStack(p);
    }
};

__forceinline Memory* memory() throw() { return reinterpret_cast<Memory*>(::TlsGetValue(DAT_010f3170)); }

__forceinline void* hkAllocateChunk(int bytes, int cls) throw()
{
    return memory()->FUN_008f6f60(bytes, cls);
}

__forceinline void hkDeallocateStack(char* p) throw()
{
    memory()->freeStack(p);
}

struct LocalBuffer {
    char* data;
    int size;
    int capacity;
    char* stack;
    __forceinline LocalBuffer() throw() : data(0), size(0), capacity(0x80000000)
    {
        data = (char*)memory()->alloc(0x4010);
        capacity = 0x80004000;
        stack = data;
    }
    __forceinline ~LocalBuffer() throw()
    {
        hkDeallocateStack(stack);
        if (!(capacity & 0x80000000)) {
            int bytes = capacity & 0x3fffffff;
            memory()->FUN_008f6d90(data, bytes, 0x17);
        }
    }
};

struct Map {
    int f00, f04, f08, f0c;
    Map(Flag flag = false) throw() { FUN_009b1110(flag); }
    ~Map() throw() { FUN_009b1160(); }
    __declspec(nothrow) void FUN_009b1110(Flag) throw();
    __declspec(nothrow) void FUN_009b1160() throw();
    __declspec(nothrow) void FUN_009b0e60(const void*, const void*) throw();
    __declspec(nothrow) int FUN_009b0fb0(const void*, void*) throw();
    __declspec(nothrow) int FUN_009b0dc0() throw();
    __declspec(nothrow) char* FUN_009b0e40(char*, int) throw();
    __declspec(nothrow) char* FUN_009b0de0(int) throw();
    __declspec(nothrow) int FUN_009b0df0(int) throw();
    __declspec(nothrow) int FUN_009b0e10(int) throw();
};

struct RefData {
    Array<int> a;
    Array<int> b;
    Array<int> c;
    Array<int> d;
    void* extra;
    RefData() throw()
    {
        a.data = 0; a.size = 0; a.capacity = 0x80000000;
        b.data = 0; b.size = 0; b.capacity = 0x80000000;
        c.data = 0; c.size = 0; c.capacity = 0x80000000;
        d.data = 0; d.size = 0; d.capacity = 0x80000000;
        extra = 0;
    }
    ~RefData() throw() { FUN_009b2fd0(); }
    __declspec(nothrow) void FUN_009b2fd0() throw();
    __declspec(nothrow) void FUN_009b2eb0(void*) throw();
    void clear() throw() { a.size = 0; b.size = 0; c.size = 0; d.size = 0; }
};

struct References {
    int f00, f04, f08;
    References() throw() { FUN_00922cb0(); }
    ~References() throw() { FUN_00922cf0(); }
    __declspec(nothrow) void FUN_00922cb0() throw();
    __declspec(nothrow) void FUN_00922cf0() throw();
    __declspec(nothrow) void FUN_00922710(void*, const char*) throw();
};

struct Input {
    void* f00;
    unsigned short f04, f06;
    int f08, f0c, f10;
    Input(void* p) throw() { FUN_00a82a60(p); }
    ~Input() throw() { FUN_00a82a90(); }
    __declspec(nothrow) void FUN_00a82a60(void*) throw();
    __declspec(nothrow) void FUN_00a82a90() throw();
};

struct ParserBase {
    void* f00;
    unsigned short f04, f06;
    int f08, f0c, f10, f14, f18, f1c;
    ParserBase() throw() { FUN_00a81370(); }
    ~ParserBase() throw() { FUN_00a813d0(); }
    __declspec(nothrow) void FUN_00a81370() throw();
    __declspec(nothrow) void FUN_00a813d0() throw();
};

struct Node {
    virtual ~Node() throw();
    int f04;
    int type;
    const char* name;
    int count;
    const char* cString() const throw() { return name; }
    __declspec(nothrow) const char* FUN_00a80eb0(const char*, const char*) throw();
    __declspec(nothrow) void FUN_00a81200(int) throw();
    Node* element() throw() { return type == 1 ? this : 0; }
    Node* end() throw() { return type == 2 ? this : 0; }
    Node* text() throw() { return type == 3 ? this : 0; }
};

struct Parser : ParserBase {
    unsigned int depth;
    int flag24, flag28;
    Parser() throw()
    {
        f00 = (void*)&DAT_00e8637c;
        depth = 0;
        flag24 = 0;
        flag28 = 1;
    }
    __declspec(nothrow) int FUN_00a49730(Node**, Input*) throw();
    __declspec(nothrow) void FUN_00a80fe0(Node*) throw();
};

struct Reader {
    void* f00;
    unsigned short f04, f06;
    Parser* parser;
    Reader(Parser* p) throw() { FUN_00a82e30(p); }
    ~Reader() throw() { FUN_00a82b10(); }
    __declspec(nothrow) void FUN_00a82e30(Parser*) throw();
    __declspec(nothrow) void FUN_00a82b10() throw();
    __declspec(nothrow) int FUN_00a84ab0(Input*, LocalBuffer*, void*, RefData*) throw();
};

struct TableBase {
    void* f00;
    unsigned short f04, f06;
    TableBase() throw() : f06(1) {}
};

struct RawNameMap {
    int f00, f04, f08, f0c;
    __declspec(nothrow) void FUN_009b1110(Flag) throw();
    __declspec(nothrow) void FUN_009b0e60(const void*, const void*) throw();
    __declspec(nothrow) int FUN_009b0fb0(const void*, void*) throw();
};

struct RefTable : TableBase {
    RawNameMap table;
    RefTable(Flag flag = false) throw()
    {
        f00 = (void*)&DAT_00e863b8;
        table.FUN_009b1110(flag);
    }
    ~RefTable() throw() { FUN_00a49540(); }
    __declspec(nothrow) void FUN_00a49540() throw();
    char* getAllocatedName(const char* name) throw()
    {
        char* found;
        if (table.FUN_009b0fb0(name, &found) == 0)
            return found;
        char* copy = FUN_00923640(name);
        table.FUN_009b0e60(copy, copy);
        return copy;
    }
};

struct String {
    const char* text;
    __declspec(nothrow) const char* FUN_009b0490() throw();
};

struct RawMap {
    int f00, f04, f08, f0c;
    __declspec(nothrow) void FUN_009b0e60(const void*, const void*) throw();
};

struct Output {
    void* f00;
    unsigned short f04, f06;
    int f08;
    RawMap map;
    void* f20;
    Output(void* p) throw() { FUN_00a7dfc0(p); }
    ~Output() throw() { FUN_00a7def0(); }
    __declspec(nothrow) void addClass(String& k) throw()
    {
        const char* n = k.FUN_009b0490();
        map.FUN_009b0e60(n, &k);
    }
    __declspec(nothrow) void FUN_00a7dfc0(void*) throw();
    __declspec(nothrow) void FUN_00a7def0() throw();
    __declspec(nothrow) void FUN_00a7df30(void*) throw();
};

struct ErrorStream {
    int f00, f04, f08;
    ErrorStream(char* b, int n) throw() { FUN_00923070(b, n); }
    ~ErrorStream() throw() { FUN_00943a60(); }
    __declspec(nothrow) void FUN_00923070(char*, int) throw();
    __declspec(nothrow) void FUN_00943710(const char*) throw();
    __declspec(nothrow) void FUN_00943a60() throw();
};

struct ErrorHandler {
    virtual __declspec(nothrow) void v0() throw();
    virtual __declspec(nothrow) void v4() throw();
    virtual __declspec(nothrow) void v8() throw();
    virtual __declspec(nothrow) void report(int, int, char*, const char*, int) throw();
};

struct Context {
    int f00, f04, f08, f0c, f10, f14, f18;
    Array<char*> strings;
    __declspec(nothrow) void FUN_00a801c0(const char*, void*) throw();
    __declspec(nothrow) void FUN_00a80200(char*, void*) throw();
};

struct Pair {
    void* object;
    String* type;
};

struct Root {
    virtual __declspec(nothrow) void v0() throw();
    virtual __declspec(nothrow) void v4() throw();
    virtual __declspec(nothrow) void v8() throw();
    virtual __declspec(nothrow) void vc() throw();
    virtual __declspec(nothrow) void v10() throw();
    virtual __declspec(nothrow) void setRoot(void*, void**) throw();
    int f04, f08;
    Pair* entries;
    int f10, f14, f18, f1c, f20, f24;
    References refs;
    void* root;
    __forceinline void setContentsWithName(void* obj, const char* typeName) throw()
    {
        root = obj;
        refs.FUN_00922710(obj, typeName);
        setRoot(root, &root);
    }
};

struct GlobalContext {
    __declspec(nothrow) void* FUN_009b20b0(void*) throw();
};

static __declspec(noinline) bool FUN_00a483d0(const char* s) throw()
{
    for (int i = 0; DAT_01065098[i]; ++i)
        if (FUN_009232f0(s, DAT_01065098[i], FUN_009233f0(DAT_01065098[i])) == 0)
            return true;
    return false;
}

static __declspec(noinline) bool FUN_00a48420(const char* className) throw()
{
    if (className && hkString_strCmp(className, "hkClass") && hkString_strCmp(className, "hkClassMember")
        && hkString_strCmp(className, "hkClassEnum") && hkString_strCmp(className, "hkClassEnumItem"))
        return true;
    return false;
}

static __declspec(noinline) int FUN_00a484b0(int* classVersion, Node* element, const char** contentsVersion) throw()
{
    const char* text = element->FUN_00a80eb0("classversion", 0);
    if (text) {
        int version = hkString_atoi(text);
        *classVersion = version;
        if (version != 1) {
            if (version < 2 || version > 5)
                return 1;
            const char* contents = element->FUN_00a80eb0("contentsversion", 0);
            if (contents) {
                *contentsVersion = FUN_00923640(contents);
                return 0;
            }
            *contentsVersion = FUN_00923640("Havok-3.1.0");
            return 0;
        }
    }
    *contentsVersion = FUN_00923640("Havok-3.0.0");
    return 0;
}

struct Owner {
    virtual __declspec(nothrow) void v0() throw();
    virtual __declspec(nothrow) void v4() throw();
    virtual __declspec(nothrow) void v8() throw();
    virtual __declspec(nothrow) void vc() throw();
    virtual __declspec(nothrow) void v10() throw();
    virtual __declspec(nothrow) void v14() throw();
    virtual __declspec(nothrow) void v18() throw();
    virtual __declspec(nothrow) void v1c() throw();
    virtual __declspec(nothrow) void v20() throw();
    virtual __declspec(nothrow) void* getType() throw();
    virtual __declspec(nothrow) void setVersion(void*) throw();
    int f04, f08, f0c, f10, f14;
    Context* context;
    Array<char*> strings;
    Map globalNames;
    Array<Pair> fixups;
    Root* root;
    __declspec(nothrow) void* FUN_00a48550(const char*, Output*, Map*, References*, int, void*) throw();
    __declspec(nothrow) void FUN_00a48780(char*, void*, RefData*, Map*, Map*) throw();
    __declspec(nothrow) int FUN_00a48970(void* input, void* out) throw();
};

int Owner::FUN_00a48970(void* input, void* out) throw()
{
    LocalBuffer buffer;
    int sectionIndex = 0;
    Input stream(input);
    Parser parser;
    Reader reader(&parser);
    RefData references;
    RefTable names;
    References globalRefs;
    Map classMap;
    Map futureMap;
    Map localNames;
    Output output(out);
    output.addClass(*(String*)&DAT_0116cbc8);
    output.addClass(*(String*)&DAT_0116cc88);
    localNames.FUN_009b0e60(DAT_00e7ff90, 0);
    Node* node;
    void* value;
    int version = 1;
    const char* exported;
    int result = parser.FUN_00a49730(&node, &stream);
    while (result == 0) {
        Node* element = node->element();
        if (element) {
            if (hkString_strCmp(element->cString(), DAT_00e86404) == 0) {
                const char* type = element->FUN_00a80eb0(DAT_00e3be04, 0);
                value = FUN_00a48550(type, &output, &classMap, &globalRefs, version, getType());
                const char* name = element->FUN_00a80eb0(DAT_00e40028, 0);
                char* objectName = names.getAllocatedName(name);
                exported = element->FUN_00a80eb0(DAT_00e7ffc4, 0);
                if (exported) {
                    exported = FUN_00923640(exported);
                    context->strings.append((char*)exported);
                }
                if (parser.depth > 0) {
                    if (node->element())
                        --parser.depth;
                    else if (node->end())
                        ++parser.depth;
                }
                parser.FUN_00a80fe0(node);
                node = 0;
                buffer.size = 0;
                if (reader.FUN_00a84ab0(&stream, &buffer, value, &references) != 0)
                    return 1;
                void* current;
                if (hkString_strCmp(((String*)value)->FUN_009b0490(), DAT_00e44a74) == 0) {
                    references.FUN_009b2eb0(buffer.data);
                    String* declaredClass = (String*)buffer.data;
                    void* declared = FUN_00a48550(declaredClass->FUN_009b0490(), &output, &classMap, &globalRefs, version, getType());
                    if (declared) {
                        current = declared;
                        references.clear();
                        goto process;
                    }
                }
                current = hkAllocateChunk(buffer.size, 5);
                FUN_009234e0(current, buffer.data, buffer.size);
                references.FUN_009b2eb0(current);
                context->strings.append((char*)current);
            process:
                if (exported)
                    context->FUN_00a801c0(exported, current);
                localNames.FUN_009b0e60(objectName, current);
                FUN_00a48780(objectName, current, &references, &localNames, &futureMap);
                if (hkString_strCmp(((String*)value)->FUN_009b0490(), DAT_00e44a74) == 0) {
                    const char* className = ((String*)current)->FUN_009b0490();
                    classMap.FUN_009b0e60(className, current);
                } else if (FUN_00a48420(((String*)value)->FUN_009b0490())) {
                    Pair& fix = fixups.pushBack();
                    fix.type = (String*)value;
                    fix.object = current;
                    if (sectionIndex == 0 && !root->root)
                        root->setContentsWithName(fix.object, ((String*)value)->FUN_009b0490());
                }
                references.clear();
            } else if (hkString_strCmp(element->cString(), DAT_00e86484) == 0) {
                const char* section = element->FUN_00a80eb0(DAT_00e40028, DAT_00e86280);
                void* cls = getType();
                if (FUN_00a483d0((const char*)cls)) {
                    parser.flag24 = hkString_strCmp(section, DAT_00e862b8) == 0;
                    parser.flag28 += parser.flag24 ? -1 : 1;
                }
                int foundSection;
                if (globalNames.FUN_009b0fb0(section, &foundSection) == 0) {
                    sectionIndex = foundSection;
                } else {
                    int idx = strings.size;
                    sectionIndex = idx;
                    char* copy = FUN_00923640(section);
                    context->strings.append(copy);
                    strings.append(copy);
                    globalNames.FUN_009b0e60(strings.back(), (void*)idx);
                }
            } else if (hkString_strCmp(element->cString(), DAT_00e86478) == 0) {
                void* text = 0;
                FUN_00a484b0(&version, element, (const char**)&text);
                setVersion(text);
                memory()->FUN_008f6f90(text);
                if (version >= 5) {
                    output.addClass(*(String*)&DAT_0116a994);
                    output.addClass(*(String*)&DAT_0116a964);
                } else if (version >= 2) {
                    output.addClass(*(String*)&DAT_0116cbf8);
                }
                if (!out) {
                    GlobalContext* reg = (GlobalContext*)DAT_011693ac;
                    output.FUN_00a7df30(reg->FUN_009b20b0(getType()));
                }
            } else {
                return 1;
            }
        } else if (!node->end()) {
            Node* text = node->text();
            if (text) {
                text->FUN_00a81200(0);
                if (text->count - 1 > 0)
                    return 1;
            } else {
                unsigned int errorBuffer[128];
                ErrorStream error((char*)errorBuffer, 512);
                error.FUN_00943710(DAT_00e86460);
                ((ErrorHandler*)DAT_010f3364)->report(3, 0x5ef4e5a3, (char*)errorBuffer, DAT_00e86438, 0x262);
            }
        }
        if (node)
            delete node;
        result = parser.FUN_00a49730(&node, &stream);
    }
    int index = futureMap.FUN_009b0dc0();
    char valid;
    futureMap.FUN_009b0e40(&valid, index);
    while (valid != 0) {
        char* s = futureMap.FUN_009b0de0(index);
        if (*s != '#' && *s == '@') {
            char* copy = FUN_00923640(s + 1);
            context->strings.append(copy);
            int entry = futureMap.FUN_009b0df0(index);
            while (entry != -1) {
                context->FUN_00a80200(copy, root->entries[entry].object);
                entry = (int)root->entries[entry].type;
            }
        }
        index = futureMap.FUN_009b0e10(index);
        futureMap.FUN_009b0e40(&valid, index);
    }
    return 0;
}

} // namespace Parse8970

// @f3 0x00a58130 (community match, verified in this file)
namespace f3m_00a58130 {
// claim clm_afd0a48ec0144141b4fe -- FUN_00a58130 at 0x00a58130, 64 bytes

// pdb: hkGeomConvexHullBuilder::getPseudoAngle | hkGeomConvexHullBuilder.obj | tesv_win, hash, low
float FUN_00a58130(float a, float b)
{
    float r;

    if (a < 0.0)
        r = 2.0 - b;
    else if (b > 0.0f)
        r = b;
    else
        r = 4.0 - b;

    return r;
}
}   // namespace f3m_00a58130

// @f3 0x00a58170 (community match, verified in this file)
namespace f3m_00a58170 {
// pdb: hkGeomConvexHullBuilder::drawPlane | hkGeomConvexHullBuilder.obj | tesv_win, objrun_open, low
void FUN_00a58170()
{
}
}   // namespace f3m_00a58170

// @f3 0x00a45e90 (community match, verified in this file)
namespace f3m_00a45e90 {
namespace opus_a45e90 {

struct SectionHeader
{
    char m_sectionTag[19];
    char m_nullByte;
    int m_absoluteDataStart;
    int m_localFixupsOffset;
    int m_globalFixupsOffset;
    int m_virtualFixupsOffset;
    int m_exportsOffset;
    int m_importsOffset;
    int m_endOffset;
};

}

void __cdecl FUN_00a45e90(opus_a45e90::SectionHeader* sections, int num)
{
    for (int i = 0; i < num; ++i)
    {
        opus_a45e90::SectionHeader& s = sections[i];
        s.m_endOffset = s.m_importsOffset;
        s.m_exportsOffset = s.m_endOffset;
    }
}
}   // namespace f3m_00a45e90
