#include <stdlib.h>
#include <string.h>
#include <windows.h>
// src/f3staging/f3blk_00400000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0040edd0 (community match, verified in this file)
namespace serializer40edd0 {
struct Form { unsigned int unk00,unk04,unk08,id; };
struct Node { Form* item; Node* next; unsigned int FUN_0049fa20(); };
struct Lock { volatile long owner; int count; void FUN_00409a80(int); };
extern Lock DAT_0106c980;
extern unsigned char DAT_0106dd0e;
struct Heap { void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*); };
extern Heap DAT_01090a78;
}
inline void* operator new[](size_t size){return serializer40edd0::DAT_01090a78.FUN_0086b930(size);}
inline void operator delete[](void* pointer){serializer40edd0::DAT_01090a78.FUN_0086ba60(pointer);}
namespace serializer40edd0 {
void __cdecl FUN_00454890(unsigned int,unsigned int);
void __cdecl TESForm___AddChunkData(unsigned int,const void*,unsigned int);
void __cdecl FUN_00455710(unsigned int,int);
void __cdecl FUN_00455710(unsigned int,float);
struct SoundSeed {unsigned char value;};
void __cdecl FUN_004556a0(unsigned int,unsigned int);
void __cdecl FUN_004556a0(unsigned int,SoundSeed);
void __cdecl FUN_004554f0(unsigned int);
void __cdecl FUN_00455b30(unsigned int,const unsigned int*,unsigned int);
struct Object {
 void FUN_00423e00(); void FUN_00422890(); void FUN_0048ed40(); void FUN_004236a0();
};
struct Text { void FUN_005abe80(unsigned int); };
inline unsigned int Swap(unsigned int value) { return _byteswap_ulong(value); }
inline unsigned short SwapShort(unsigned short value) {return _byteswap_ushort(value);}
inline void Copy(void* d,const void* s,size_t n){memcpy(d,s,n);}
struct Pair { unsigned int id,amount; void SwapFields(){id=Swap(id);amount=Swap(amount);} };
struct RefFloat { Form* form; float value; };
struct ActivationData {unsigned int id;float amount;void SwapFields(){id=Swap(id);*(unsigned int*)&amount=Swap(*(unsigned int*)&amount);}};
struct RefInt { Form* form; unsigned int value; };
struct LockData { unsigned char level; unsigned int key; unsigned char flags; unsigned int unk0c,unk10; LockData(){level=0;flags=0;key=0;unk10=0;unk0c=0;} };
struct RefByte { unsigned int id; unsigned char flags; };
struct RefShort { unsigned int id; unsigned short count; };
inline void StoreID(unsigned int& out,unsigned int id){out=id;}
struct Ragdoll { unsigned int id,a,b,c,d,e,f; void SwapFields(){id=Swap(id);a=Swap(a);b=Swap(b);c=Swap(c);d=Swap(d);e=Swap(e);f=Swap(f);} };
struct Pose16 {unsigned int id,a,b,c,d;void FUN_00409db0();};
struct Point {float x,y,z;};
struct Quat {float x,y,z,w;void Reset(){x=0.0f;y=0.0f;z=0.0f;w=0.0f;} };
struct Primitive {Point position;Quat rotation;unsigned int flags;void FUN_00409ea0();};
struct Matrix {float m00,m01,m02,m10,m11,m12,m20,m21,m22;void FUN_00822820(float*,float*,float*,float*) const;};
struct Oriented {unsigned int a,b;Point position;float axisx,axisy,axisz,angle;void FUN_00409df0();};
struct InputPrimitive {unsigned int unk00,flags;Quat rotation;Point position;};
struct InputOriented {unsigned int unk00,unk04;Point position;unsigned int a,b;Matrix matrix;};
struct InputRadio {unsigned int unk00,unk04;Node list;bool flag;};
struct InputPower {Node node;unsigned char depth;};
struct InputDoor {unsigned char level;Form* key;unsigned char flags;};
struct InputActivation {Form* form;float x,y,z;};
struct Extra {
 unsigned int unk00;unsigned char type;unsigned char unk05,unk06,unk07;Extra* next;
 union {Form* form;Object* object;void* pointer;int integer;float scalar;unsigned char byte;short shortValue;Node node;InputActivation activation;InputDoor* door;InputPrimitive* primitive;InputOriented* oriented;InputRadio* radio;InputPower power;};
};
struct Owner {unsigned int unk00;Extra* head;Extra* BaseExtraList_GetExtraData(unsigned int);void FUN_0040edd0();};
// pdb: ExtraDataList::Save | ExtraDataList.obj | fnv360_0822_retail, uconst, low
void Owner::FUN_0040edd0() {
 DAT_0106c980.FUN_00409a80(0);
 Extra* current=head;

 for(;current;current=current->next) {
  Pose16 linkedData; unsigned int lod[3]; RefByte enableParent; SoundSeed soundSeed; ActivationData activateData; Pair powerData; Ragdoll ragdoll; RefShort packageData; Primitive primitive; Oriented occlusion; Matrix occlusionMatrix; unsigned int ordering[4]; Oriented portal; Matrix portalMatrix; Pair podData;
 switch(current->type) {
 case 14:
 FUN_00454890(0x54434158,current->byte);
 break;
 case 42:
 { InputDoor* input=current->door; LockData lockData; lockData.flags=input->flags;lockData.level=input->level;lockData.key=input->key?input->key->id:0;if(DAT_0106dd0e)lockData.key=Swap(lockData.key);TESForm___AddChunkData(0x434f4c58,&lockData,20); }
 break;
 case 104:
 { Form* old=*(Form**)&current->activation.z; Pose16* value=(Pose16*)&current->activation; if(old)value->c=old->id;if(DAT_0106dd0e)value->FUN_00409db0();TESForm___AddChunkData(0x4f445258,value,16);if(DAT_0106dd0e)value->FUN_00409db0();*(Form**)&value->c=old; }
 break;
 case 43:
 current->object->FUN_00423e00();
 break;
 case 44:
 FUN_004554f0(0x4b524d58);current->object->FUN_00422890();
 break;
 case 33:
 FUN_00454890(0x4e574f58,current->form->id);
 break;
 case 34:
 FUN_00454890(0x424c4758,current->form->id);
 break;
 case 35:
 FUN_00455710(0x4b4e5258,current->integer);
 break;
 case 36:
 FUN_00455710(0x544e4358,current->shortValue);
 break;
 case 110:
 {Form* item=current->form;unsigned int count=*(unsigned int*)((char*)current+16);FUN_00454890(0x544d4158,item?item->id:0);FUN_00455710(0x434d4158,(int)count);}
 break;
 case 37:
 FUN_00455710(0x544c4858,(int)current->scalar);
 break;
 case 122:
 FUN_00455710(0x504c4858,current->scalar);
 break;
 case 38:
 FUN_00455710(0x45535558,(int)current->byte);
 break;
 case 39:
 FUN_00455710(0x4d495458,current->scalar);
 break;
 case 40:
 FUN_00455710(0x47484358,current->scalar);
 break;
 case 63:
 FUN_00454890(0x4e535058,current->form->id);
 break;
 case 49:
 {Extra* seed=BaseExtraList_GetExtraData(49);if(!seed)soundSeed.value=255;else soundSeed.value=seed->byte;FUN_004556a0(0x44455358,soundSeed);}
 break;
 case 4:
 { Node* node=current->pointer? (Node*)((char*)current->pointer+4):0;unsigned int count=node->FUN_0049fa20();if(count>0){unsigned int* ids=new unsigned int[count];unsigned int* output=ids;while(node){*output++=node->item->id;node=node->next;}FUN_00455b30(0x524c4358,ids,count);delete[] ids;} }
 break;
 case 8:
 FUN_00454890(0x4d434358,current->form->id);
 break;
 case 89:
 FUN_00454890(0x4d494358,current->form->id);
 break;
 case 3:
 FUN_00454890(0x54574358,current->form->id);
 break;
 case 7:
 FUN_00454890(0x4f4d4358,current->form->id);
 break;
 case 129:
 FUN_00454890(0x53414358,current->form->id);
 break;
 case 24:
 linkedData.id=current->form->id;linkedData.a=*(unsigned int*)((char*)current+16);linkedData.b=*(unsigned int*)((char*)current+20);linkedData.c=*(unsigned int*)((char*)current+24);if(DAT_0106dd0e)linkedData.FUN_00409db0();TESForm___AddChunkData(0x4c535058,&linkedData,20);if(DAT_0106dd0e)linkedData.FUN_00409db0();
 break;
 case 20:
 current->object->FUN_0048ed40();
 break;
 case 19:
 lod[0]=current->integer;lod[1]=*(unsigned int*)((char*)current+16);lod[2]=*(unsigned int*)((char*)current+20);FUN_00455b30(0x444f4c58,lod,3);
 break;
 case 55:
 if(current->form){enableParent.id=current->form->id;enableParent.flags=*(unsigned char*)((char*)current+16);if(DAT_0106dd0e)enableParent.id=Swap(enableParent.id);TESForm___AddChunkData(0x50534558,&enableParent,8);if(DAT_0106dd0e)enableParent.id=Swap(enableParent.id);}
 break;
 case 59:
 if(current->form) FUN_00454890(0x4d545258,current->form->id);
 break;
 case 81:
 if(current->form) FUN_00454890(0x524b4c58,current->form->id);
 break;
 case 83:
 { FUN_004556a0(0x44504158,current->power.depth);Node* node=&current->power.node;while(node && (node->next||node->item)){RefFloat* item=(RefFloat*)node->item;node=node->next;activateData.id=0;activateData.amount=0.0f;activateData=*(ActivationData*)item;activateData.id=((Form*)activateData.id)->id;if(DAT_0106dd0e)activateData.SwapFields();TESForm___AddChunkData(0x52504158,&activateData,8);if(DAT_0106dd0e)activateData.SwapFields();}}
 break;
 case 102:
 {Node* node=&current->node;while(node&&(node->next||node->item)){RefInt* item=(RefInt*)node->item;powerData.id=0;powerData.amount=0;powerData=*(Pair*)item;powerData.id=item->form->id;if(DAT_0106dd0e)powerData.SwapFields();TESForm___AddChunkData(0x52575058,&powerData,8);if(DAT_0106dd0e)powerData.SwapFields();node=node->next;}}
 break;
 case 133:
 {Node* node=&current->node;while(node&&(node->next||node->item)){FUN_00454890(0x57544c58,node->item->id);node=node->next;}}
 break;
 case 87:
 {Node* node=&current->node;while(node&&(node->next||node->item)){Ragdoll* item=(Ragdoll*)node->item;Copy(&ragdoll,item,28);ragdoll.id=((Form*)item->id)->id;if(DAT_0106dd0e)ragdoll.SwapFields();TESForm___AddChunkData(0x52434458,&ragdoll,28);if(DAT_0106dd0e)ragdoll.SwapFields();node=node->next;}}
 break;
 case 60:
 if(current->form) FUN_00454890(0x43524d58,current->form->id);
 break;
 case 68:
 if(current->form) FUN_00454890(0x47525458,current->form->id);
 break;
 case 116:
 if(current->form) FUN_00454890(0x4e5a4558,current->form->id);
 break;
 case 103:
 if(current->form) FUN_00454890(0x494d4558,current->form->id);
 break;
 case 99:
 if(current->form) FUN_00454890(0x52424d58,current->form->id);
 break;
 case 98:
 if(current->object)current->object->FUN_004236a0();
 break;
 case 30:
 FUN_00454890(0x4d434c58,current->integer);
 break;
 case 90:
 packageData.id=current->integer;packageData.count=*(unsigned short*)((char*)current+16);if(packageData.id){packageData.id=((Form*)packageData.id)->id;if(DAT_0106dd0e){packageData.id=Swap(packageData.id);packageData.count=SwapShort(packageData.count);}TESForm___AddChunkData(0x50444e58,&packageData,8);if(DAT_0106dd0e){packageData.id=Swap(packageData.id);packageData.count=SwapShort(packageData.count);}}
 break;
 case 92:
 FUN_00455710(0x53445258,current->scalar);
 break;
 case 93:
 FUN_00455710(0x44415258,current->scalar);
 break;
 case 107:
 {InputPrimitive* input=current->primitive;primitive.rotation.Reset();primitive.position=input->position;primitive.rotation=input->rotation;primitive.flags=input->flags;if(DAT_0106dd0e)primitive.FUN_00409ea0();TESForm___AddChunkData(0x4d525058,&primitive,32);if(DAT_0106dd0e)primitive.FUN_00409ea0();}
 break;
 case 111:
 {float radiation=*(float*)current->pointer;if(DAT_0106dd0e)*(unsigned int*)&radiation=Swap(*(unsigned int*)&radiation);TESForm___AddChunkData(0x44525058,&radiation,4);if(DAT_0106dd0e)*(unsigned int*)&radiation=Swap(*(unsigned int*)&radiation);((Text*)((char*)current->pointer+4))->FUN_005abe80(0x41505058);}
 break;
 case 113:
 {InputOriented* input=current->oriented;occlusion.a=input->a;occlusion.b=input->b;occlusion.position=input->position;occlusionMatrix=input->matrix;occlusionMatrix.FUN_00822820(&occlusion.angle,&occlusion.axisx,&occlusion.axisy,&occlusion.axisz);if(DAT_0106dd0e)occlusion.FUN_00409df0();TESForm___AddChunkData(0x50434f58,&occlusion,36);if(DAT_0106dd0e)occlusion.FUN_00409df0();}
 break;
 case 118:
{  memset(ordering,0,sizeof(ordering));StoreID(ordering[0],((Form**)current->pointer)[0]?((Form**)current->pointer)[0]->id:0);StoreID(ordering[1],((Form**)current->pointer)[1]?((Form**)current->pointer)[1]->id:0);StoreID(ordering[2],((Form**)current->pointer)[2]?((Form**)current->pointer)[2]->id:0);StoreID(ordering[3],((Form**)current->pointer)[3]?((Form**)current->pointer)[3]->id:0);if(DAT_0106dd0e)for(int j=0;j<4;j++)ordering[j]=Swap(ordering[j]);TESForm___AddChunkData(0x44524f58,ordering,16);if(DAT_0106dd0e)for(int j=0;j<4;j++)ordering[j]=Swap(ordering[j]); }
 break;
 case 120:
 {InputOriented* input=current->oriented;portal.a=input->a;portal.b=input->b;portal.position=input->position;portalMatrix=input->matrix;portalMatrix.FUN_00822820(&portal.angle,&portal.axisx,&portal.axisy,&portal.axisz);if(DAT_0106dd0e)portal.FUN_00409df0();TESForm___AddChunkData(0x4c545058,&portal,36);if(DAT_0106dd0e)portal.FUN_00409df0();}
 break;
 case 119:
 podData.amount=0;podData.id=0;StoreID(podData.id,((Form**)current->pointer)[0]?((Form**)current->pointer)[0]->id:0);StoreID(podData.amount,((Form**)current->pointer)[1]?((Form**)current->pointer)[1]->id:0);if(DAT_0106dd0e)podData.SwapFields();TESForm___AddChunkData(0x444f5058,&podData,8);if(DAT_0106dd0e)podData.SwapFields();
 break;
 case 123:
 {InputRadio* input=current->radio;unsigned int count=input->list.FUN_0049fa20();if(input->flag)count|=0x10000;FUN_00454890(0x524d5258,count);Node* node=&current->radio->list;while(node){if(!node->item)break;FUN_00454890(0x4d524c58,node->item->id);node=node->next;}}
 break;
 case 97:
 FUN_004554f0(0x50424d58);
 break;
 case 114:
 if(DAT_0106dd0e)*(unsigned int*)current->pointer=Swap(*(unsigned int*)current->pointer);TESForm___AddChunkData(0x49525458,current->pointer,4);if(DAT_0106dd0e)*(unsigned int*)current->pointer=Swap(*(unsigned int*)current->pointer);
 break;
 case 128:
 FUN_004554f0(0x53424958);
 break;
 }
 }
 if(--DAT_0106c980.count==0){long o=DAT_0106c980.owner;InterlockedCompareExchange(&DAT_0106c980.owner,0,o);}
}
}
