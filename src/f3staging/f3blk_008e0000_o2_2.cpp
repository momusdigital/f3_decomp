#include <math.h>
#include <windows.h>
#include <math.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
#include <windows.h>
// src/f3staging/f3blk_008e0000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008e6210 (community match, verified in this file)
extern unsigned long DAT_010f3170;
extern float DAT_00f79460;
extern float DAT_00e35180[];
namespace f3m_008e6210 {

struct Allocator {
 virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10();
 virtual void* allocate(int); virtual void release(void*);
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 char* cursor; int unk24; void* end; char* limit;
 void* FUN_008f6d30(int,int); void FUN_008f6d90(void*,unsigned int,int);
};
inline Allocator* allocator() { return (Allocator*)TlsGetValue(DAT_010f3170); }
struct Vec4 {float x,y,z,w; Vec4& operator=(const Vec4& b) {x=b.x;y=b.y;z=b.z;w=b.w;return *this;} };
struct Transform48 { Vec4 translation,rotation,scale; Transform48& operator=(const Transform48& b) {translation=b.translation;rotation=b.rotation;scale=b.scale;return *this;} };
struct ScratchTransforms {
 Transform48* data; int unk04;
 __forceinline ScratchTransforms(int count) { Allocator* a=allocator(); int bytes=(count*48+16)&~15; char* p=a->cursor; char* next=p+bytes; Transform48* allocated; if(next<=a->limit) { a->cursor=next; allocated=(Transform48*)p; } else allocated=(Transform48*)a->allocate(bytes); data=allocated; }
 ~ScratchTransforms() { Allocator* a=allocator(); a->cursor=(char*)data; if(data==a->end) a->release(data); }
 Transform48* begin() {return data;}
 Transform48& operator[](int i) {return data[i];}
};
struct IntBuffer {
 int* data; int count; int capacity;
 IntBuffer(int n) { data=(int*)allocator()->FUN_008f6d30(n*4,23); count=n; capacity=n; }
 ~IntBuffer() { if((capacity&0x80000000)==0) { unsigned n=(unsigned)capacity&0x3fffffff; Allocator* a=allocator(); a->FUN_008f6d90(data,n*4,23); } }
 int* begin(){return data;}
};
struct SkeletonData {
 int unk00; void* parents; int unk08; int unk0c; int count; void* poses;
};
struct Body {
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
 unsigned char scaleIndex; unsigned char unk18d; short unk18e;
 int unk190;
 int unk194;
 int unk198;
 int unk19c;
 float vx,vy,vz;
};
struct Skeleton {
 int unk00; int unk04; Body** bodies; int unk0c; int unk10; int unk14; int unk18; int unk1c; int* indices; int unk24; int unk28; SkeletonData* data;
 void FUN_00961300(Transform48*,void*);
 Body* getBody(int index) {int k=indices[index]; return k<0 ? 0:bodies[k];}
 int getNumBones() {return data->count;}
};
struct Lookup {void** FUN_00956280();};
struct Processor {void FUN_0095b310(); void FUN_0095b610(float,Transform48*,void*,int*);};
struct BlendData {int unk00; int unk04; int unk08; int unk0c; void* data;};
extern "C" void __cdecl FUN_008dcae0(Skeleton*);
extern "C" void __cdecl FUN_008dca30(Skeleton*);
extern "C" void __cdecl FUN_008dcb80(Skeleton*,Transform48*);
extern "C" void __cdecl FUN_009584b0(int,void*,void*,Transform48*);
extern "C" void __cdecl hkaSkeletonMapper_mapPose(void*,void*,void*,Transform48*,int);
extern "C" void __cdecl FUN_009588d0(int,void*,Transform48*,Transform48*);
struct Controller {
 int unk00;
 bool needsInit; unsigned char unk05; short unk06;
 int unk08;
 int mode;
 int unk10;
 int unk14;
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
 bool forceMode; unsigned char unk45; short unk46;
 Skeleton* skeleton;
 Processor* processor;
 bool active; unsigned char unk51; short unk52;
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
 Lookup* lookup;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 int unka0;
 int unka4;
 int unka8;
 int unkac;
 int unkb0;
 int unkb4;
 int unkb8;
 int unkbc;
 int unkc0;
 int unkc4;
 int unkc8;
 int unkcc;
 int unkd0;
 int unkd4;
 int unkd8;
 int unkdc;
 int unke0;
 int unke4;
 int unke8;
 int unkec;
 int unkf0;
 int unkf4;
 int unkf8;
 int unkfc;
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
 BlendData* blend;
 void bhkRagdollController_UpdateRagdollRigidBodies(const Transform48* input);
};
inline void ApplyPose(Skeleton* const volatile& current, Transform48* pose, void* settings) { current->FUN_00961300(pose,settings); }
// pdb: bhkRagdollController::UpdateRagdollRigidBodies | bhkRagdollController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|call_gap), high
void Controller::bhkRagdollController_UpdateRagdollRigidBodies(const Transform48* input) {
 SkeletonData* data=skeleton->data;
 int count=data->count;
 ScratchTransforms outputStorage(count);
 Transform48* output=outputStorage.begin();
 ScratchTransforms poseStorage(count);
 Transform48* pose=poseStorage.begin();
 int oldMode=mode;
 if(forceMode) mode=1;
 if(needsInit) { FUN_008dcae0(skeleton); needsInit=false; }
 if(!input) {
  FUN_009584b0(count,data->parents,data->poses,pose);
  void* poseTrack=*lookup->FUN_00956280();
  BlendData* currentBlend=blend;
  hkaSkeletonMapper_mapPose(currentBlend->data,poseTrack,data->poses,pose,2);
  if(mode!=1) FUN_009588d0(count,data->parents,pose,output);
 } else {
  for(int i=0;i<count;++i) outputStorage[i]=input[i];
 }
 switch(mode) {
 case 3: FUN_008dca30(skeleton); FUN_008dcb80(skeleton,output); mode=0; break;
 case 2:
  if(active) { processor->FUN_0095b310(); active=false; }
  if(DAT_00f79460>0.0f) {
   IntBuffer results(count);
   processor->FUN_0095b610(DAT_00f79460,output,&unk10,results.begin());
   bool fast=false;
   for(int index=0;index<skeleton->getNumBones();++index) {
    if(fast) break;
    {
     Body* state=skeleton->getBody(index);
     if(state) {
      float magnitude=state->vx*state->vx+state->vy*state->vy+state->vz*state->vz;
      float limit=DAT_00e35180[state->scaleIndex];
      limit=limit*limit;
      fast=magnitude>limit;
     }
    }
   }
   if(fast) { skeleton->FUN_00961300(pose,&unk10); active=true; }
  }
  break;
 case 1: ApplyPose(skeleton,pose,&unk10); break;
 }
 if(forceMode) { mode=oldMode; forceMode=false; }
}
}   // namespace f3m_008e6210

// @f3 0x008fe050 (community match, verified in this file)
namespace f3m_008fe050 {


extern unsigned int DAT_010f3170;

class ThreadMemory
{
public:
    void* allocateChunk(int size, int allocationClass);

    static __forceinline ThreadMemory& getInstance()
    {
        return *(ThreadMemory*)TlsGetValue(DAT_010f3170);
    }
};

class FNV_ALIGN(16) HavokVector4
{
public:
    float x;
    float y;
    float z;
    float w;
};

class FNV_ALIGN(16) HavokTransform
{
public:
    HavokVector4 column0;
    HavokVector4 column1;
    HavokVector4 column2;
    HavokVector4 column3;
};

class SourceTransform
{
public:
    HavokTransform* convert(HavokTransform* temporary);
};

class SourceObject
{
public:
    unsigned int unk00;
    unsigned int value04;
    unsigned int unk08;
    unsigned int unk0C;
    SourceTransform transform10;
};

class HeldObject
{
public:
    virtual void release(int destroy);

    unsigned short memorySize;
    short referenceCount;
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

    HeldObject(unsigned int value, HavokTransform* converted);

    static void* operator new(unsigned int size)
    {
        HeldObject* memory = (HeldObject*)ThreadMemory::getInstance().allocateChunk(size, 0x27);
        memory->memorySize = (unsigned short)size;
        return memory;
    }

    static void operator delete(void* memory);
};

FNV_STATIC_ASSERT(sizeof(HeldObject) == 0x70);

class InnerNode
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int flags10;
};

class MiddleNode
{
public:
    unsigned int unk00;
    unsigned int unk04;
    InnerNode* inner08;
};

class TopNode
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    MiddleNode* middle14;
};

class TargetHolder
{
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void setHeldObject(HeldObject* object);
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void useSource(SourceObject* source);

    unsigned int unk04;
    TopNode* top08;
    unsigned int unk0C;
    unsigned int flags10;

    void FUN_008fe050(SourceObject* source);
};

// pdb: bhkTransformShape::Init | bhkTransformShape.obj | fnv360_0822_retail, caller_sim, low
// pdb params: arInfo
void TargetHolder::FUN_008fe050(SourceObject* source)
{
    if (source != 0)
    {
        HavokTransform temporary;
        HeldObject* object = new HeldObject(
            source->value04,
            source->transform10.convert(&temporary));

        setHeldObject(object);

        if (object->memorySize != 0)
        {
            --object->referenceCount;
            if (object->referenceCount == 0)
                object->release(1);
        }

        useSource(source);

        if (top08 != 0 && top08->middle14 != 0 && top08->middle14->inner08 != 0)
            flags10 = top08->middle14->inner08->flags10 & 0x1f;
    }
}
}   // namespace f3m_008fe050

// @f3 0x008f3ae0 (community match, verified in this file)
namespace f3m_008f3ae0 {

namespace BlendTransformDetail {
struct NiPoint3 {float x,y,z;};
struct __declspec(align(16)) VecLocal {float x,y,z,w;VecLocal& operator=(const VecLocal& b){x=b.x;y=b.y;z=b.z;w=b.w;return *this;}};
struct QuatLocal : VecLocal
{
    void FUN_00924360(const struct RotLocal&);
    void FUN_009243a0(const QuatLocal&, const QuatLocal&, float);
    void FUN_004e5c20();
};
struct RotLocal
{
    VecLocal c0,c1,c2;
    void hkRotation_set(const QuatLocal&);
};
struct TransLocal
{
    RotLocal rotation;
    VecLocal position;
};
struct MatrixLocal
{
    float m00,m01,m02,m10,m11,m12,m20,m21,m22;
};
struct SceneTransLocal
{
    MatrixLocal rotation;
    NiPoint3 position;
    float scale;
};
struct SceneLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    SceneTransLocal local, world;
    void FUN_008330a0();
};
struct BodyLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
        virtual void GetPosition(VecLocal&);
    virtual void GetRotation(QuatLocal&);

    void FUN_004e6280(const VecLocal&);
    void FUN_004e62c0(const VecLocal&);
    void FUN_008ff5a0(const VecLocal&, const QuatLocal&, float, float);
};
struct TargetLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14,unk18,unk1c;
    unsigned int count;
};
extern long (__stdcall* const DAT_00d9b06c)(volatile long*, long, long);
struct AtomicValues { long exchange, comparand; };
inline void AtomicClear(long* pointer, AtomicValues values)
{
    DAT_00d9b06c(pointer, values.exchange, values.comparand);
}
struct LockLocal
{
    long owner, count;
    void FUN_00409a80(char*);
    void Unlock()
    {
        if (--count == 0)
            {AtomicValues v={0,owner};AtomicClear(&owner,v);}
    }
};
extern LockLocal DAT_010f2c40;
extern float DAT_00f79460;
extern const double DAT_00dbe7c0;
extern VecLocal DAT_01092a50;

void FUN_004e5db0(RotLocal*, const MatrixLocal*);
extern "C" void __cdecl FUN_0056ad20(SceneTransLocal*, TransLocal*);
void FUN_00458620(NiPoint3*, VecLocal*);
struct BlendLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void Reset();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void Publish(SceneTransLocal*);

    int unk04;
    SceneLocal* scene;
    unsigned short flags, unk0e;
    BodyLocal* body;
    unsigned int unk14;
    float heirGain, velGain;
    unsigned int motion;
    TargetLocal* target;
    unsigned int unk28;
    void FUN_008d2350(unsigned int, BodyLocal*, bool);
    void FUN_008d20a0();
    void FUN_008f37b0();
    void FUN_008f3ae0();
};
extern "C" unsigned long __readfsdword(unsigned long);
struct TlsModeLocal
{
    int value;
};
struct TlsLocal
{
    unsigned unk000, unk004, unk008, unk00c;
    unsigned unk010, unk014, unk018, unk01c;
    unsigned unk020, unk024, unk028, unk02c;
    unsigned unk030, unk034, unk038, unk03c;
    unsigned unk040, unk044, unk048, unk04c;
    unsigned unk050, unk054, unk058, unk05c;
    unsigned unk060, unk064, unk068, unk06c;
    unsigned unk070, unk074, unk078, unk07c;
    unsigned unk080, unk084, unk088, unk08c;
    unsigned unk090, unk094, unk098, unk09c;
    unsigned unk0a0, unk0a4, unk0a8, unk0ac;
    unsigned unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned unk0c0, unk0c4, unk0c8, unk0cc;
    unsigned unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned unk0e0, unk0e4, unk0e8, unk0ec;
    unsigned unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned unk100, unk104, unk108, unk10c;
    unsigned unk110, unk114, unk118, unk11c;
    unsigned unk120, unk124, unk128, unk12c;
    unsigned unk130, unk134, unk138, unk13c;
    unsigned unk140, unk144, unk148, unk14c;
    unsigned unk150, unk154, unk158, unk15c;
    unsigned unk160, unk164, unk168, unk16c;
    unsigned unk170, unk174, unk178, unk17c;
    unsigned unk180, unk184, unk188, unk18c;
    unsigned unk190, unk194, unk198, unk19c;
    unsigned unk1a0, unk1a4, unk1a8, unk1ac;
    unsigned unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned unk1c0, unk1c4, unk1c8, unk1cc;
    unsigned unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned unk1e0, unk1e4, unk1e8, unk1ec;
    unsigned unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned unk200, unk204, unk208, unk20c;
    unsigned unk210, unk214, unk218, unk21c;
    unsigned unk220, unk224, unk228, unk22c;
    unsigned unk230, unk234, unk238, unk23c;
    unsigned unk240, unk244, unk248, unk24c;
    unsigned unk250, unk254, unk258, unk25c;
    unsigned unk260, unk264, unk268, unk26c;
    unsigned unk270, unk274, unk278, unk27c;
    unsigned unk280, unk284, unk288, unk28c;
    unsigned unk290, unk294, unk298, unk29c;
    TlsModeLocal mode;
};extern __declspec(thread) TlsLocal g_tls;
inline TlsModeLocal& GetBlendMode()
{
    return ((TlsLocal*)&g_tls)->mode;
}
// pdb: bhkBlendCollisionObject::hktoNiTransform | bhkBlendCollisionObject.obj | fnv360_0822_retail, objrun, medium
void BlendLocal::FUN_008f3ae0()
{
    SceneLocal* node = scene;
    BodyLocal* rigid = body;
    bool forced = (flags & 0x100) != 0;
    float timestep = DAT_00f79460;
    unsigned int desiredMotion = 1;
    int mode;
    TlsModeLocal* tls;
    if (heirGain == 0.0f)
    {
        int state = GetBlendMode().value;
        tls = &GetBlendMode();
        if (state == 1)
        {
            node->FUN_008330a0();
            return;
        }
        mode = velGain == 0.0f || forced ? 1 : 0;
    }
    else if (heirGain == 1.0f)
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 2;
        desiredMotion = 6;
    }
    else
    {
        tls = &GetBlendMode();
        mode = GetBlendMode().value == 2 ? 1 : 0;
    }
    bool changed = false;
    if (motion != desiredMotion)
    {
        if (motion == 6)
            Reset();
        else if (rigid)
        {
            rigid->FUN_004e6280(DAT_01092a50);
            rigid->FUN_004e62c0(DAT_01092a50);
        }
        DAT_010f2c40.FUN_00409a80(0);
        FUN_008d2350(desiredMotion, rigid, false);
        DAT_010f2c40.Unlock();
        motion = desiredMotion;
        changed = true;
    }
    switch (mode)
    {
    case 0: {
        node->FUN_008330a0();
        SceneTransLocal& world = node->world;
        NiPoint3& worldPosition = world.position;
        VecLocal position;
        position.x = worldPosition.x * DAT_00dbe7c0;
        position.y = worldPosition.y * DAT_00dbe7c0;
        position.z = worldPosition.z * DAT_00dbe7c0;

        RotLocal converted;
        FUN_004e5db0(&converted, &world.rotation);
        QuatLocal desiredRotation;
        desiredRotation.FUN_00924360(converted);
        VecLocal currentPosition;
        rigid->GetPosition(currentPosition);
        QuatLocal currentRotation;
        rigid->GetRotation(currentRotation);
        VecLocal blendedPosition;
        float blend = heirGain;
        float inverseBlend=1.0f-blend;
        blendedPosition.x=inverseBlend*currentPosition.x+blend*position.x;
        // Keep each product extended until the final lane rounding.
        double currentYProduct = (double)currentPosition.y*inverseBlend;
        blendedPosition.y = (float)(currentYProduct + blend*(*(const volatile float*)&position.y));
        double currentZProduct = (double)currentPosition.z*inverseBlend;
        blendedPosition.z = (float)(currentZProduct + blend*(*(const volatile float*)&position.z));
        blendedPosition.w=inverseBlend*currentPosition.w+blend*position.w;
        QuatLocal blendedRotation;
        blendedRotation.FUN_009243a0(currentRotation, desiredRotation, heirGain);
        blendedRotation.FUN_004e5c20();
        TransLocal output;
        output.position = forced ? blendedPosition : position;
        output.rotation.hkRotation_set(blendedRotation);
        FUN_0056ad20(&world, &output);

        if (tls->value == 0)
            Publish(&world);
        float inverseTimestep = timestep != 0.0f ? 1.0f / timestep : 1.0f;
        float gain = forced ? 1.0f : velGain;
        rigid->FUN_008ff5a0(blendedPosition, blendedRotation, inverseTimestep, gain);
        break;
    }
    case 1:
        FUN_008d20a0();
        break;
    case 2:
        Reset();
        break;
    }
    if (changed && target && target->count <= 0)
        FUN_008f37b0();
}
}

}   // namespace f3m_008f3ae0

// @f3 0x008e3570 (community match, verified in this file)
namespace f3m_008e3570 {



extern double DAT_01020758;
extern const double DAT_00dcd110;

namespace R8e3570 {

extern char* DAT_00e207a8;
char* __cdecl FUN_008242a0(const char* apString);

struct NiFixedString
{
    char* m_kHandle;
    NiFixedString(const char* apString)
    {
        if (!apString)
            m_kHandle = DAT_00e207a8;
        else
            m_kHandle = FUN_008242a0(apString);
    }
    ~NiFixedString()
    {
        if (m_kHandle != DAT_00e207a8)
            ::InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
};

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    __forceinline void operator=(const Vec4& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    __forceinline void setSub4(const Vec4& a, const Vec4& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    __forceinline void sub4(const Vec4& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        w -= a.w;
    }
    __forceinline void setZero4() { x = y = z = w = 0.0f; }
    __forceinline float lengthSquared3() const { return x * x + y * y + z * z; }
    // Guess at the source: the named lane copies (y first) give the target's x,y,z load order for the displacement.
    __forceinline float length3() const
    {
        float fy = y;
        float fx = x;
        float fz = z;
        return (float)::sqrt(fx * fx + fy * fy + fz * fz);
    }
    // Guess at the source: scaling each lane through a by-reference helper gives the scale-first
    // (fld st(0); fmul [lane]) order in every lane of the normalize.
    static __forceinline void mulLane(float& v, float f) { v *= f; }
    __forceinline void mul4(float s)
    {
        float f = s;
        mulLane(x, f);
        mulLane(y, f);
        mulLane(z, f);
        mulLane(w, f);
    }
    static __forceinline float sqrtInverse(float r)
    {
        float root = (float)::sqrt(r);
        return 1.0f / root;
    }
    __forceinline float lengthInverse3() const
    {
        float l2 = lengthSquared3();
        return (l2 != 0.0f) ? sqrtInverse(l2) : 0.0f;
    }
    __forceinline void normalize3() { mul4(lengthInverse3()); }
};

struct Point
{
    float x, y, z, w;
    __declspec(noinline) Vec4 FUN_00475680() const
    {
        Vec4 r;
        r.x = x;
        r.y = y;
        r.z = z;
        r.w = w;
        return r;
    }
};

struct SceneObject
{
    unsigned int unk00, unk04, unk08, unk0c;
    Point origin;
    Point end;
};

struct NiAVObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiAVObject* IsNode();
};

struct ChildArray
{
    void* vtbl;
    NiAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetSize() const { return m_usSize; }
    NiAVObject* GetAt(unsigned int i) const { return m_pBase[i]; }
};

struct NiNode : NiAVObject
{
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90, unk94, unk98;
    ChildArray m_kChildren;
};

__forceinline NiAVObject* FirstChildA(NiAVObject* apNode)
{
    if (!apNode)
        return 0;
    return apNode->IsNode() && static_cast<NiNode*>(apNode)->m_kChildren.m_usSize > 0 ? static_cast<NiNode*>(apNode)->m_kChildren.m_pBase[0] : 0;
}

// Guess at the source: binding the child array before the null test keeps the root's zero block
// from being jump-threaded past the mid test (the target falls from xor esi,esi into the mid test).
__forceinline NiAVObject* FirstChildB(NiAVObject* apNode)
{
    ChildArray& kChildren = static_cast<NiNode*>(apNode)->m_kChildren;
    if (!apNode)
        return 0;
    return apNode->IsNode() && kChildren.m_usSize > 0 ? kChildren.m_pBase[0] : 0;
}

struct VfxSourceBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int Type();
};

struct VfxSource : VfxSourceBase
{
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4 m_kInitialDirection;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    Vec4 m_kFinalDirection;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    unsigned int unkc0;
    float m_fOriginAngle;
    float m_fFinalAngle;
};

struct SourceLink
{
    unsigned int unk00;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const { return m_pkSource; }
};

struct ShaderHolder
{
    unsigned int unk00, unk04, unk08;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const { return m_pkSource; }
};

struct ShaderLink
{
    unsigned int unk00;
    ShaderHolder* m_pkHolder;
    ShaderHolder* GetHolder() const { return m_pkHolder; }
};

struct ExtraProperty
{
    void* FUN_00541dd0();
};

struct FxObject;
struct CollisionBody
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    FxObject* m_pkProperties;
};

struct CollisionObject
{
    unsigned int unk00, unk04, unk08, unk0c;
    CollisionBody* m_pkBody;
};

CollisionObject* __cdecl FUN_00424fe0(NiAVObject* apNode);
ExtraProperty* __cdecl FUN_00424d50(int* apType, FxObject* apObject);
NiAVObject* __cdecl FUN_00aab440(void* apScene, const NiFixedString& arName, bool abRecurse);

extern int DAT_010f3344;
extern int DAT_010f3338;
extern int DAT_011691fc;

__forceinline FxObject** Properties(NiAVObject* apNode)
{
    CollisionObject* pkObject = FUN_00424fe0(apNode);
    return (pkObject && pkObject->m_pkBody) ? &pkObject->m_pkBody->m_pkProperties : 0;
}

__forceinline VfxSource* FindSource(FxObject** ppkProperties)
{
    FxObject* pkInitial = *ppkProperties;
    ExtraProperty* pkProp = FUN_00424d50(&DAT_010f3344, pkInitial);
    VfxSource* pkSource = pkProp ? ((SourceLink*)pkProp->FUN_00541dd0())->GetSource() : 0;
    if (!pkProp)
    {
        FxObject* pkFallback = *ppkProperties;
        ExtraProperty* pkShader = FUN_00424d50(&DAT_010f3338, pkFallback);
        if (pkShader)
        {
            ShaderLink* pkLink = (ShaderLink*)pkShader->FUN_00541dd0();
            if (pkLink)
            {
                ShaderHolder* pkHolder = pkLink->GetHolder();
                VfxSource* pkAlt = pkHolder ? pkHolder->GetSource() : 0;
                if (pkAlt && pkAlt->Type() == 2)
                    pkSource = pkAlt;
            }
        }
    }
    return pkSource;
}

struct Setting
{
    float* FUN_00401eb0();
};
extern Setting DAT_010f2dec;
extern Setting DAT_010f2e34;

struct EffectOutput
{
    unsigned int unk00, unk04, unk08, unk0c;
    Vec4 m_kLightVector;
    Vec4 m_kDisplacement;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    float m_fOriginX, m_fOriginY, m_fOriginZ, m_fAngleZ, m_fAngleX, m_fAngleY;
};

struct EffectName
{
    const char* m_pcText;
};

struct EffectRequest
{
    unsigned int unk00;
    EffectName* m_pkName;
};

__forceinline Vec4 DifferenceOf(const SceneObject* o)
{
    Vec4 a = o->origin.FUN_00475680();
    Vec4 b = o->end.FUN_00475680();
    a.sub4(b);
    return a;
}

struct Controller
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54;
    void* m_pkScene;
    SceneObject* FUN_008dfa70(NiAVObject* apNode);
    bool FUN_008e3570(EffectOutput* pkOutput, EffectRequest* pkRequest);
};

}  // namespace R8e3570

// pdb: bhkRagdollController::ExtractBipedSetupData | bhkRagdollController.obj | fnv360_0822_retail, call_gap_sim, medium
// pdb params: arSetupData, arboneNameA
bool R8e3570::Controller::FUN_008e3570(EffectOutput* pkOutput, EffectRequest* pkRequest)
{
    SceneObject* pkMidObj;
    float fAngleY;
    float fAngleX;
    EffectName* pkName = pkRequest->m_pkName;
    NiAVObject* pkRoot = FUN_00aab440(m_pkScene, NiFixedString(pkName->m_pcText), true);
    NiAVObject* pkMid = FirstChildA(pkRoot);
    NiAVObject* pkEnd = FirstChildB(pkMid);
    if (!pkRoot || !pkMid || !pkEnd)
        return false;

    SceneObject* pkRootObj = FUN_008dfa70(pkRoot);
    pkMidObj = FUN_008dfa70(pkMid);
    SceneObject* pkEndObj = FUN_008dfa70(pkEnd);
    FxObject** ppkMidProps = Properties(pkMid);
    FxObject** ppkEndProps = Properties(pkEnd);
    if (!pkRootObj || !pkMidObj || !pkEndObj || !ppkMidProps || !ppkEndProps)
        return false;

    VfxSource* pkBase = FindSource(ppkMidProps);
    if (!pkBase)
        return false;

    // The explicit (float) here sets the x87 operand order of the later adds and multiplies.
    float fAngleDifference = (float)(90.0 - pkBase->m_fFinalAngle * DAT_00dcd110 - DAT_01020758);
    fAngleDifference = fAngleDifference * 0.01745329238474369;
    fAngleDifference = cos(fAngleDifference);
    fAngleX = -fAngleDifference;
    fAngleDifference = pkBase->m_fOriginAngle * DAT_00dcd110 + 90.0 - 20.0;
    fAngleDifference = fAngleDifference * 0.01745329238474369;
    fAngleDifference = cos(fAngleDifference);
    fAngleY = fAngleDifference;
    Vec4 kDirection;
    kDirection = pkBase->m_kInitialDirection;

    VfxSource* pkFinal = FindSource(ppkEndProps);
    VfxSource* pkSpecial = 0;
    if (!pkFinal)
    {
        FxObject* pkSpecialObject = *ppkEndProps;
        ExtraProperty* pkProp = FUN_00424d50(&DAT_011691fc, pkSpecialObject);
        pkSpecial = pkProp ? ((SourceLink*)pkProp->FUN_00541dd0())->GetSource() : 0;
        if (!pkSpecial)
            return false;
    }
    Vec4 kFinal;
    if (pkFinal)
        kFinal = pkFinal->m_kFinalDirection;
    else
        kFinal = pkSpecial->m_kInitialDirection;
    Vec4 kDisplacement;
    kDisplacement = DifferenceOf(pkEndObj);
    fAngleDifference = kFinal.x;
    fAngleDifference += *DAT_010f2dec.FUN_00401eb0();

    pkOutput->m_kLightVector = kDirection;
    pkOutput->m_kLightVector.normalize3();
    if (kDisplacement.length3() < 0.5f)
        kDisplacement.setZero4();
    pkOutput->m_kDisplacement = kDisplacement;
    pkOutput->m_fAngleZ = -*DAT_010f2e34.FUN_00401eb0();
    pkOutput->m_fOriginZ =
        (pkMidObj->origin.x - pkMidObj->end.x) + 2.0 * pkEndObj->origin.x + fAngleDifference;
    pkOutput->m_fOriginX = pkEndObj->origin.x;
    pkOutput->m_fOriginY = pkOutput->m_fOriginZ - 2.0 * fAngleDifference;
    pkOutput->m_fAngleX = fAngleX;
    pkOutput->m_fAngleY = fAngleY;
    return true;
}

}   // namespace f3m_008e3570

// @f3 0x008ffac0 (community match, verified in this file)
namespace f3m_008ffac0 {
// 0x008ffac0 (1944 bytes), __thiscall, 2 stack arguments. Offline MATCH under /MT,/O2,/GS,/EHsc,/Gy (pack lists /Od: flag proof).
// Lineage: best_agent.cpp (this account, 4 off) plus one statement and one helper; that chain is a rewrite of stored draft
// best2.cpp (another contributor). Helpers: hk550 hkFpuVector4.inl / hkVector4.inl / hkQuaternion.inl x87 bodies (setRotatedDir,
// setCross through operator(), dot3/dot4, setAbs4, compareLessThanEqual4, equals4, setW), Havok 5.5.0 SDK (approved source).
// Tail follows hkpKeyFrameUtility::applyHardKeyFrame (hk550 hybrid record). Statement order cross-checked with fnv_decomp
// src\unmapped\bhkrigidbody_rtm_variant.cpp bhkRigidBody_ApplyHardKeyframe (New Vegas 0x00c8e160); nothing copied (SSE code).
// DEPENDS ON (disclose): xf.p.setW(xf.p) after the three lane writes, a store-free self-assignment of p.w that gives p.w a
// member definition (without: 4 off at +0x513); volatile lock owner read into a local before InterlockedCompareExchange;
// redundant parentheses on the y lane of setMul4; setMul4 scalar as const hkReal& (hk550 takes it by value);
// p and q lanes written through operator()(int); QT {q,p} pair and V old[2] buffer for the frame.


namespace Z8ffa {
extern const double DAT_00dbe7c0;extern const double DAT_00e01160=1000000.0;
extern const float DAT_00e34818,DAT_00db88e0,DAT_00db7df0;
extern float DAT_00f79460;
typedef float hkReal;typedef hkReal hkSimdReal;typedef hkReal hkSimdRealParameter;typedef int hkBool32;
namespace hkMath {inline hkReal fabs(hkReal r){return ::fabsf(r);}inline hkReal sqrt(hkReal r){return ::sqrtf(r);}}
class hkVector4Comparison{public:enum Mask{MASK_NONE=0,MASK_W=1,MASK_Z=2,MASK_Y=4,MASK_X=8,MASK_XYZ=14,MASK_XYZW=15};
hkBool32 allAreSet(Mask m)const{return (m_mask&m)==m;}
int m_mask;};
struct V;
struct Q4;
struct __declspec(align(16)) V {
float x,y,z,w;
__forceinline hkReal& operator()(int i){return (&x)[i];}
__forceinline const hkReal& operator()(int i)const{return (&x)[i];}
__forceinline void set(hkReal a,hkReal b,hkReal c,hkReal d){x=a;y=b;z=c;w=d;}__forceinline void setW(const V& v){w=v.w;}
__forceinline void setAll(hkReal a){x=a;y=a;z=a;w=a;}
__forceinline void setZero4(){x=y=z=w=0;}
__forceinline void add4(const V& v){x+=v.x;y+=v.y;z+=v.z;w+=v.w;}
__forceinline void setAdd4(const V& v0,const V& v1){x=v0.x+v1.x;y=v0.y+v1.y;z=v0.z+v1.z;w=v0.w+v1.w;}
__forceinline void setSub4(const V& v0,const V& v1){x=v0.x-v1.x;y=v0.y-v1.y;z=v0.z-v1.z;w=v0.w-v1.w;}
__forceinline void SetSub3(const V& a,const V& b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}
__forceinline void mul4(hkSimdRealParameter rs){hkReal s=hkReal(rs);x*=s;y*=s;z*=s;w*=s;}
__forceinline void setMul4(const hkReal& s,const V& a){x=s*a.x;y= (s*a.y);z=s*a.z;w=s*a.w;}
__forceinline void addMul4(hkSimdRealParameter rs,const V& a){hkReal s=hkReal(rs);x+=s*a.x;y+=s*a.y;z+=s*a.z;w+=s*a.w;}
__forceinline void setCross(const V& v1,const V& v2){const hkReal nx=v1(1)*v2(2)-v1(2)*v2(1);const hkReal ny=v1(2)*v2(0)-v1(0)*v2(2);const hkReal nz=v1(0)*v2(1)-v1(1)*v2(0);this->set(nx,ny,nz,0.0f);}
__forceinline hkVector4Comparison compareLessThanEqual4(const V& a)const{hkVector4Comparison ret;ret.m_mask=((x<=a.x)?hkVector4Comparison::MASK_X:0)|((y<=a.y)?hkVector4Comparison::MASK_Y:0)|((z<=a.z)?hkVector4Comparison::MASK_Z:0)|((w<=a.w)?hkVector4Comparison::MASK_W:0);return ret;}
__forceinline void setAbs4(const V& v){x=hkMath::fabs(v.x);y=hkMath::fabs(v.y);z=hkMath::fabs(v.z);w=hkMath::fabs(v.w);}
__forceinline hkSimdReal dot3(const V& a)const{return (x*a.x)+(y*a.y)+(z*a.z);}
__forceinline hkSimdReal dot4(const V& a)const{return (x*a.x)+(y*a.y)+(z*a.z)+(w*a.w);}
__forceinline hkSimdReal lengthSquared3()const{return this->dot3(*this);}
__forceinline hkSimdReal length3()const{return hkMath::sqrt((x*x)+(y*y)+(z*z));}
__forceinline hkBool32 equals4(const V& v,hkReal epsilon=1e-3f)const{V t;t.setSub4(*this,v);t.setAbs4(t);V epsilon_v;epsilon_v.setAll(epsilon);return t.compareLessThanEqual4(epsilon_v).allAreSet(hkVector4Comparison::MASK_XYZW);}
__forceinline void setRotatedDir(const Q4& quat,const V& direction);
};
struct Q4 {V m_vec;
inline const V& getImag()const{return m_vec;}
inline hkReal getReal()const{return m_vec(3);}
void setMulInverse(const Q4& q0,const Q4& q1);void normalize();hkReal getAngle()const;void getAxis(V& axis)const;};
__forceinline void V::setRotatedDir(const Q4& quat,const V& direction){
hkReal qreal=quat.m_vec(3);
hkReal q2minus1=qreal*qreal-0.5f;
V ret;
ret.setMul4(q2minus1,direction);
hkReal imagDotDir=quat.getImag().dot3(direction);
ret.addMul4(imagDotDir,quat.getImag());
V imagCrossDir;
imagCrossDir.setCross(quat.getImag(),direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);
}
extern const double DAT_00db7de8;
extern const double DAT_00db38b0;
extern V DAT_01092a50;
struct P {float x,y,z;};struct Q {float w,x,y,z;};
struct BhkWorld;
struct Body {
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
BhkWorld* userData;
};
struct Data {
int unk000;
int unk004;
Body* body;
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
V linear,angular;};
struct QT {Q4 q;V p;};
struct Lock {volatile long owner;long count;void FUN_00409a80(int);void Release(){if(--count==0){long o=owner;InterlockedCompareExchange(&owner,0,o);}}};extern Lock DAT_010f2c40;
struct Entity {
virtual void v000();
virtual void v004();
virtual void v008();
virtual void v00c();
virtual void v010();
virtual void v014();
virtual void v018();
virtual void v01c();
virtual void v020();
virtual void v024();
virtual void v028();
virtual void v02c();
virtual void v030();
virtual void v034();
virtual void v038();
virtual void v03c();
virtual void v040();
virtual void v044();
virtual void v048();
virtual void v04c();
virtual void v050();
virtual void v054();
virtual void v058();
virtual void v05c();
virtual void v060();
virtual void v064();
virtual void v068();
virtual void v06c();
virtual void v070();
virtual void v074();
virtual void v078();
virtual void v07c();
virtual void v080();
virtual void v084();
virtual void v088();
virtual void v08c();
virtual void v090();
virtual void v094();
virtual void v098();
virtual void v09c();
virtual void v0a0();
virtual void v0a4();
virtual void v0a8();
virtual void v0ac();
virtual void v0b0();
virtual void v0b4();
virtual void v0b8();
virtual void v0bc();
virtual void v0c0();
virtual void v0c4();
virtual void v0c8();
virtual V* Position(V*);
virtual V* Rotation(V*);
virtual void v0d4();
virtual void v0d8();
virtual void v0dc();
virtual void Teleport(const V*,const V*);
virtual const V* LocalCenter(V*);
virtual const V* WorldCenter(V*);
int unk04;Data* data;
Data* GetData(){return this?data:0;}
const V& Linear(){return data?data->linear:DAT_01092a50;}
const V& Angular(){return data?data->angular:DAT_01092a50;}
void FUN_004e6280(const V*);void FUN_004e62c0(const V*);void FUN_004e60b0(const P*);float FUN_004e6160();
void FUN_008ffac0(const P*,const Q*);
};
// pdb: bhkRigidBody::ApplyHardKeyframe | bhkRigidBody.obj | fnv360_0822_retail, call_gap, low
// pdb params: arPos, arRot, apSetPosLock
void Entity::FUN_008ffac0(const P* pos,const Q* quat){
Body* body=GetData()->body;
if(!body || !body->userData)return;
QT xf;V old[2];Q4 oldq;V teleportPosition;Q4 delta;
xf.p(0)=(float)(pos->x*DAT_00dbe7c0);xf.p(1)=(float)(pos->y*DAT_00dbe7c0);xf.p(2)=(float)(pos->z*DAT_00dbe7c0);xf.p.setW(xf.p);xf.q.m_vec(0)=quat->x;xf.q.m_vec(1)=quat->y;xf.q.m_vec(2)=quat->z;xf.q.m_vec(3)=quat->w;
Position(&old[0]);Rotation(&oldq.m_vec);
V difference;difference.SetSub3(xf.p,old[0]);
if(!(difference.lengthSquared3()>0.001f*0.001f) && !(hkMath::fabs(xf.q.m_vec.dot4(oldq.m_vec)-1.0f)>1e-6f)){
if(!Linear().equals4(DAT_01092a50))FUN_004e6280(&DAT_01092a50);
if(!Angular().equals4(DAT_01092a50))FUN_004e62c0(&DAT_01092a50);
return;
}
float inv=DAT_00f79460;
if(inv==0.0f)return;
inv=1.0f/inv;
{V newCenter;newCenter.setRotatedDir(xf.q,*LocalCenter(&old[1]));newCenter.add4(xf.p);
V velocity;velocity.setSub4(newCenter,*WorldCenter(&old[1]));velocity.setMul4(inv,velocity);
{V zero;Q4 qq;
float len2=velocity.lengthSquared3();float max=FUN_004e6160();
if(len2>max*max)
{teleportPosition.x=(float)(pos->x*DAT_00dbe7c0);teleportPosition.y=(float)(pos->y*DAT_00dbe7c0);teleportPosition.z=(float)(pos->z*DAT_00dbe7c0);
qq.m_vec.set(quat->x,quat->y,quat->z,quat->w);
DAT_010f2c40.FUN_00409a80(0);Teleport(&teleportPosition,&qq.m_vec);DAT_010f2c40.Release();return;}
float len=velocity.length3();
if(len>DAT_00e01160){zero.set(0,0,0,0);FUN_004e60b0(pos);FUN_004e6280(&zero);}else FUN_004e6280(&velocity);
}}{
delta.setMulInverse(xf.q,oldq);delta.normalize();float angle=delta.getAngle();
if(angle<1e-3f){difference.setZero4();}
else{delta.getAxis(difference);difference.setMul4(angle*inv,difference);}
FUN_004e62c0(&difference);}
}
}
}   // namespace f3m_008ffac0
