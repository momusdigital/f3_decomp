// src/f3staging/f3blk_004e0000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x004fed60 (community match, verified in this file)
extern float FUN_00dbea4c;
#include <malloc.h>
#include <stdlib.h>
namespace f3m_004fed60 {
extern "C" void* __cdecl _alloca(unsigned int);
struct Input {
unsigned unk000;
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
unsigned unk05c;
unsigned unk060;
unsigned unk064;
unsigned unk068;
unsigned unk06c;
unsigned unk070;
unsigned unk074;
unsigned unk078;
unsigned unk07c;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;
unsigned unk090;
unsigned unk094;
unsigned unk098;
unsigned unk09c;
unsigned unk0a0;
unsigned unk0a4;
unsigned unk0a8;
unsigned unk0ac;
unsigned unk0b0;
unsigned unk0b4;
unsigned unk0b8;
unsigned unk0bc;
unsigned unk0c0;
unsigned unk0c4;
unsigned unk0c8;
unsigned unk0cc;
unsigned unk0d0;
unsigned unk0d4;
unsigned unk0d8;
unsigned unk0dc;
unsigned unk0e0;
unsigned unk0e4;
unsigned unk0e8;
unsigned unk0ec;
unsigned unk0f0;
unsigned unk0f4;
unsigned unk0f8;
unsigned unk0fc;
unsigned unk100;
unsigned unk104;
unsigned unk108;
unsigned unk10c;
unsigned unk110;
unsigned unk114;
unsigned unk118;
unsigned unk11c;
unsigned unk120;
unsigned unk124;
unsigned unk128;
unsigned unk12c;
unsigned unk130;
unsigned unk134;
unsigned unk138;
unsigned unk13c;
unsigned unk140;
unsigned unk144;
unsigned unk148;
unsigned unk14c;
unsigned unk150;
unsigned unk154;
unsigned unk158;
unsigned unk15c;
unsigned unk160;
unsigned unk164;
unsigned unk168;
unsigned unk16c;
unsigned unk170;
unsigned unk174;
unsigned unk178;
unsigned unk17c;
unsigned unk180;
unsigned unk184;
unsigned unk188;
unsigned unk18c;
unsigned unk190;
unsigned unk194;
unsigned unk198;
unsigned unk19c;
unsigned unk1a0;
unsigned unk1a4;
unsigned unk1a8;
unsigned unk1ac;
unsigned unk1b0;
unsigned unk1b4;
unsigned unk1b8;
unsigned unk1bc;
unsigned unk1c0;
unsigned unk1c4;
unsigned unk1c8;
unsigned unk1cc;
unsigned unk1d0;
unsigned unk1d4;
unsigned unk1d8;
unsigned unk1dc;
unsigned unk1e0;
unsigned unk1e4;
unsigned unk1e8;
unsigned unk1ec;
unsigned unk1f0;
unsigned unk1f4;
unsigned unk1f8;
unsigned unk1fc;
unsigned unk200;
unsigned unk204;
unsigned unk208;
unsigned unk20c;
unsigned unk210;
unsigned unk214;
unsigned unk218;
unsigned unk21c;
unsigned unk220;
unsigned unk224;
unsigned unk228;
unsigned unk22c;
unsigned unk230;
unsigned unk234;
unsigned unk238;
unsigned unk23c;
unsigned unk240;
unsigned unk244;
unsigned unk248;
unsigned unk24c;
unsigned unk250;
unsigned unk254;
unsigned unk258;
unsigned unk25c;
unsigned char unk260;
unsigned char unk261;
unsigned char unk262;
unsigned char unk263;
unsigned char unk264;
unsigned char unk265;
unsigned char unk266;
unsigned char unk267;
unsigned char unk268;
unsigned char unk269;
unsigned char unk26a;
unsigned char unk26b;
unsigned char unk26c;
unsigned char unk26d;
unsigned char unk26e;
unsigned char unk26f;
unsigned char unk270;
unsigned char unk271;
unsigned char unk272;
unsigned char unk273;
unsigned char unk274;
unsigned char unk275;
unsigned char unk276;
unsigned char unk277;
unsigned char unk278;
unsigned char unk279;
unsigned char unk27a;
unsigned char unk27b;
unsigned char unk27c;
unsigned char unk27d;
unsigned char unk27e;
unsigned char unk27f;
unsigned char unk280;
unsigned char unk281;
unsigned char unk282;
unsigned char unk283;
unsigned char unk284;
unsigned char unk285;
unsigned char unk286;
unsigned char unk287;
unsigned char unk288;
unsigned char unk289;
unsigned char unk28a;
unsigned char unk28b;
unsigned char unk28c;
unsigned char unk28d;
unsigned char unk28e;
unsigned char unk28f;
unsigned char unk290;
unsigned char unk291;
unsigned char unk292;
unsigned char unk293;
unsigned char unk294;
unsigned char unk295;
unsigned char unk296;
unsigned char unk297;
unsigned char unk298;
unsigned char unk299;
unsigned char TESFile_GetTESForm(); int TESFile_GetTESChunk(); void FUN_00447d60(void*,unsigned); void FUN_00448800(unsigned*); bool TESFile_NextChunk(); };
struct Data { void FUN_004fdf00(); };
struct Aux { void TESAttackDamageForm_SetAttackDamage(int); };
struct Str { void FUN_004019c0(const char*,unsigned); };
void __cdecl FUN_00456560(void*,Input*);
void __cdecl TESTexture_LoadTextureChunk(void*,Input*);
struct Obj {
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
virtual void v0cc();
virtual void v0d0();
virtual void v0d4();
virtual void v0d8();
virtual void v0dc();
virtual void readBound(Input*);
virtual void v0e4();
virtual void v0e8();
virtual void v0ec();
virtual void v0f0();
virtual void v0f4();
virtual void v0f8();
virtual void v0fc();
virtual void v100();
virtual void v104();
virtual void v108();
virtual void v10c();
virtual void v110();
virtual void v114();
virtual void v118();
virtual void v11c();
virtual void v120();
virtual void v124();
virtual void v128();
virtual void v12c();
virtual void v130();
virtual void setID(char*);
unsigned unk004;
unsigned unk008;
unsigned unk00c;
unsigned unk010;
unsigned unk014;
unsigned unk018;
unsigned unk01c;
unsigned unk020;
unsigned unk024;
unsigned unk028;
unsigned unk02c;
unsigned unk030;
unsigned unk034;
unsigned unk038;
unsigned unk03c;
unsigned unk040;
unsigned unk044;
unsigned unk048;
unsigned unk04c;
unsigned unk050;
unsigned unk054;
unsigned unk058;
unsigned unk05c;
unsigned unk060;
unsigned unk064;
unsigned unk068;
unsigned unk06c;
unsigned unk070;
unsigned unk074;
unsigned unk078;
unsigned unk07c;
unsigned unk080;
unsigned unk084;
unsigned unk088;
unsigned unk08c;
unsigned unk090;
unsigned unk094;
unsigned unk098;
unsigned unk09c;
unsigned unk0a0;
unsigned unk0a4;
unsigned unk0a8;
unsigned unk0ac;
unsigned unk0b0;
unsigned unk0b4;
unsigned unk0b8;
unsigned unk0bc;
unsigned unk0c0;
unsigned unk0c4;
unsigned unk0c8;
unsigned unk0cc;
unsigned unk0d0;
unsigned unk0d4;
unsigned unk0d8;
unsigned unk0dc;
unsigned unk0e0;
unsigned unk0e4;
unsigned unk0e8;
unsigned unk0ec;
unsigned unk0f0;
unsigned unk0f4;
unsigned unk0f8;
unsigned unk0fc;
unsigned unk100;
unsigned unk104;
unsigned unk108;
unsigned unk10c;
unsigned unk110;
unsigned unk114;
unsigned unk118;
unsigned unk11c;
unsigned unk120;
unsigned unk124;
unsigned unk128;
unsigned unk12c;
float unk130;
float unk134;
float unk138;
float unk13c;
float unk140;
float unk144;
unsigned unk148;
unsigned unk14c;
unsigned unk150;
unsigned unk154;
unsigned unk158;
unsigned unk15c;
unsigned unk160;
unsigned unk164;
unsigned unk168;
unsigned unk16c;
unsigned unk170;
unsigned unk174;
unsigned unk178;
void FUN_00454410(Input*); void TESForm_SetInitialized(int); unsigned FUN_00454fe0(); void TESForm_LoadData(Input*,void*,unsigned); bool FUN_004fed60(Input*); };
// pdb: TESWaterForm::Load | TESWaterForm.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
bool Obj::FUN_004fed60(Input* file) {
 if(file->TESFile_GetTESForm()!=0x4e) return false;
 FUN_00454410(file); TESForm_SetInitialized(0);
 int type=file->TESFile_GetTESChunk();
 while(type) {
 switch(type) {
 case 0x444e424f: readBound(file); break;
 case 0x44494445: { char* text=(char*)_alloca(file->unk25c); file->FUN_00447d60(text,0x200); setID(text); break; }
 case 0x41544144:
 { unsigned delta=file->unk25c; delta-=FUN_00454fe0(); if(delta==0) { TESForm_LoadData(file,(void*)delta,delta); if(file->unk299!=(unsigned char)delta) ((Data*)&unk084)->FUN_004fdf00(); }
 else { TESForm_LoadData(file,&unk084,0xc4); if(file->unk299) ((Data*)&unk084)->FUN_004fdf00();
 unk138=unk134=unk130=100.0f; unk13c=1.0f; unk140=0.5f; unk144=FUN_00dbea4c; ((Aux*)&unk024)->TESAttackDamageForm_SetAttackDamage(0); } } break;
 case 0x4c4c5546: FUN_00456560(this ? &unk018 : 0,file); break;
 case 0x4d414e44: file->FUN_00447d60(&unk084,0xc4); if(file->unk299) ((Data*)&unk084)->FUN_004fdf00(); break;
 case 0x4d414e41: file->FUN_00447d60(&unk070,1); break;
 case 0x4d414e46: file->FUN_00447d60((char*)&unk070+1,1); break;
 case 0x4d414e4e: TESTexture_LoadTextureChunk(&unk064,file); break;
 case 0x4d414e53: { unsigned id=0; file->FUN_00448800(&id); unk07c=id; break; }
 case 0x4d414e58: { unsigned id=0; file->FUN_00448800(&id); unk178=id; break; }
 case 0x4d414e4d: { char* text=(char*)_alloca(file->unk25c); file->FUN_00447d60(text,0); ((Str*)&unk074)->FUN_004019c0(text,0); break; }
 case 0x4d414e47: { file->FUN_00447d60(&unk148,12); if(file->unk299) { unsigned* p=&unk148; int n=3; do { *p=_byteswap_ulong(*p); ++p; } while(--n); } break; }
 }
 if(!file->TESFile_NextChunk()) break;
 type=file->TESFile_GetTESChunk();
 }
 return true;
}
}   // namespace f3m_004fed60

// @f3 0x004ec240 (community match, verified in this file)
#include <math.h>
extern float FUN_00dcdb90;
namespace f3m_004ec240 {
extern "C" void* __cdecl _alloca(unsigned int);
struct V { float x,y,z; };
struct Entry { V pos; unsigned short angle; unsigned char kind,flags; void FUN_00ab00a0(float); };
struct Base { int unk00; unsigned char type; bool TESFurniture_GetMarkerEnabled(unsigned); };
struct Data { int unk00,unk04,unk08,unk0c; Entry* entries; int unk14; unsigned short count; };
struct Extra { void FUN_0041dc60(int); };
struct List { Extra* BaseExtraList_GetExtraData(int); };
struct Mat { float m[9]; };
Data* __cdecl BSFurnitureMarker_Find(void*);
bool __cdecl FUN_004add90(unsigned);
bool __cdecl FUN_004add80(unsigned);
void __cdecl FUN_008225c0(Mat*,V*,unsigned,V*,V*);
struct Obj {
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
virtual void v51();
virtual void v52();
virtual void v53();
virtual void v54();
virtual void v55();
virtual void v56();
virtual void v57();
virtual void v58();
virtual void v59();
virtual void v60();
virtual void v61();
virtual void v62();
virtual void v63();
virtual void v64();
virtual void v65();
virtual void v66();
virtual void v67();
virtual void v68();
virtual void v69();
virtual void v70();
virtual void v71();
virtual void v72();
virtual void v73();
virtual void v74();
virtual void v75();
virtual void v76();
virtual void v77();
virtual void v78();
virtual void v79();
virtual void v80();
virtual void v81();
virtual void v82();
virtual void v83();
virtual void v84();
virtual void v85();
virtual void v86();
virtual void v87();
virtual void v88();
virtual void v89();
virtual void v90();
virtual void v91();
virtual void v92();
virtual void v93();
virtual void v94();
virtual void v95();
virtual void v96();
virtual void v97();
virtual void v98();
virtual void v99();
virtual void v100();
virtual void v101();
virtual void v102();
virtual void v103();
virtual void v104();
virtual void v105();
virtual void v106();
virtual void v107();
virtual void v108();
virtual void v109();
virtual void v110();
virtual void v111();
virtual void v112();
virtual void v113();
virtual void v114();
virtual void v115();
virtual void* getData();
virtual void v117();
virtual void v118();
virtual void v119();
virtual void v120();
virtual void v121();
virtual void v122();
virtual void v123();
virtual void v124();
virtual V* getPos();
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
Base* base;
int unk20;
int unk24;
float angle;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
List extra;
bool FUN_004e6e30(unsigned,bool);
Mat* FUN_004e7c10(Mat*);
bool FUN_004ec240(V*,bool,bool,Entry*,int*,bool);
};

// pdb: TESObjectREFR::GetClosestFreeMarker | TESObjectREFR.obj | fnv360_0822_debug, caller, medium
// pdb params: aLocation, abSitOK, abSleepOK, aOutMarker, aiOutMarkerIndex, abIgnoreReservations
bool Obj::FUN_004ec240(V* point,bool a,bool b,Entry* out,int* index,bool mode) {
 bool result=false;
 if(base->type==0x27) {
  if(getData()) {
   Base* form=base;
   if(form) {
    Data* data=BSFurnitureMarker_Find(getData());
    if(data) {
     unsigned n=data->count;
     if(n) {
      V* positions=(V*)_alloca(n*sizeof(V));
      unsigned* indices=(unsigned*)_alloca(n*sizeof(unsigned));
      unsigned used=0;
      for(unsigned i=0;i<n;++i) {
       if(form->TESFurniture_GetMarkerEnabled(i) && !FUN_004e6e30(i,mode)) {
        unsigned kind=data->entries[i].kind;
        if((FUN_004add90(kind)&&a)||(FUN_004add80(kind)&&b)||(!FUN_004add90(kind)&&!FUN_004add80(kind))) {
         positions[used]=data->entries[i].pos;
         indices[used++]=i;
        }
       }
      }
      if(used) {
       V* world=(V*)_alloca(n*sizeof(V));
       Mat mat;
       FUN_008225c0(FUN_004e7c10(&mat),getPos(),used,positions,world);
       float nearest=FUN_00dcdb90;
       unsigned char selected=0x7f;
       for(unsigned k=0;k<used;++k) {
        V delta;
        delta.x=point->x-world[k].x; delta.y=point->y-world[k].y; delta.z=point->z-world[k].z;
        float square=delta.x*delta.x+delta.y*delta.y+delta.z*delta.z;
        float distance=(float)sqrt(square);
        if(distance<nearest) {nearest=distance;selected=(unsigned char)k;}
       }
       if(selected!=0x7f) {
        *index=indices[selected];
        out->kind=data->entries[*index].kind;
        out->pos=world[selected];
        float rotation=(float)(data->entries[*index].angle/1000.0);
        rotation+=angle;
        out->FUN_00ab00a0(rotation);
        result=true;
       }
      }
     }
    }
   }
  } else {
   out->pos=*getPos(); out->kind=0; out->FUN_00ab00a0(0); *index=-1; result=false;
  }
 } else if(!mode) {
  Extra* e=extra.BaseExtraList_GetExtraData(0x82); if(e) e->FUN_0041dc60(0);
  out->pos=*getPos(); out->kind=0; out->FUN_00ab00a0(0); *index=-1; result=true;
 }
 return result;
}
}   // namespace f3m_004ec240

// @f3 0x004ffdb0 (community match, verified in this file)
#include <string.h>
#include <intrin.h>

struct f3_004ffdb0_Pair;
struct f3_004ffdb0_PairList { void FUN_0061c430(f3_004ffdb0_Pair**); };
struct f3_004ffdb0_Pool { f3_004ffdb0_Pair* FUN_0086b930(int); };
extern f3_004ffdb0_Pool DAT_01090a78;
inline void f3_004ffdb0_Swap32(unsigned int* p) { *p = _byteswap_ulong(*p); }
struct f3_004ffdb0_Pair {
    unsigned a, b;
    f3_004ffdb0_Pair() { memset(this, 0, sizeof(*this)); }
    static void* operator new(size_t n) { return DAT_01090a78.FUN_0086b930((int)n); }
    void Endian() { f3_004ffdb0_Swap32(&a); f3_004ffdb0_Swap32(&b); }
};
struct f3_004ffdb0_Sub98 { void FUN_00b10fe0(); };
void FUN_00458210(void*,f3m_004fed60::Input*);
void TESForm_AddCompileIndex(f3_004ffdb0_Pair*,f3m_004fed60::Input*);
struct f3_004ffdb0_Rec : f3m_004fed60::Obj { __declspec(noinline) unsigned char FUN_004ffdb0(f3m_004fed60::Input*); };
// pdb: TESWeather::Load | TESWeather.obj | fnv360_0822_retail, vtable, medium
// pdb params: apFile
unsigned char f3_004ffdb0_Rec::FUN_004ffdb0(f3m_004fed60::Input* s)
{
    if (s->TESFile_GetTESForm() != 0x35)
        return 0;
    FUN_00454410(s);
    TESForm_SetInitialized(0);
    unsigned int tag;
    while ((tag = s->TESFile_GetTESChunk()) != 0) {
        char* t = (char*)this;
        switch (tag) {
        case 0x41544144: {
            unsigned int n = s->unk25c;
            if (n == 0xf) {
                s->FUN_00447d60(t + 0xb8, n);
            } else if (n == 0xc) {
                s->FUN_00447d60(t + 0xb8, n);
                memset(t + 0xc4, 0xff, 3);
            }
            break;
        }
        case 0x304d414e: {
            if (s->unk25c == 0xa0)
                s->FUN_00447d60(t + 0xe0, 0xa0);
            if (s->unk299) {
                for (int i = 0; i < 10; i++)
                    for (int j = 0; j < 4; j++)
                        f3_004ffdb0_Swap32(&((unsigned int (*)[4])(t + 0xe0))[i][j]);
            }
            break;
        }
        case 0x44414900: { unsigned int v = 0; s->FUN_00448800(&v); *(unsigned int*)(t + 0x1c) = v; break; }
        case 0x44414902: { unsigned int v = 0; s->FUN_00448800(&v); *(unsigned int*)(t + 0x24) = v; break; }
        case 0x44414903: { unsigned int v = 0; s->FUN_00448800(&v); *(unsigned int*)(t + 0x28) = v; break; }
        case 0x44414904: { unsigned int v = 0; s->FUN_00448800(&v); *(unsigned int*)(t + 0x2c) = v; break; }
        case 0x44494445: {
            char* buf = (char*)_alloca(s->unk25c);
            s->FUN_00447d60(buf, 0x200);
            setID(buf);
            break;
        }
        case 0x4c444f4d: FUN_00458210(t + 0xa0, s); break;
        case 0x444e424f: readBound(s); break;
        case 0x4d414e41: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x44), s); break;
        case 0x44414901: case 0x4d414e4d: { unsigned int v = 0; s->FUN_00448800(&v); *(unsigned int*)(t + 0x20) = v; break; }
        case 0x4d414e43: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x38), s); break;
        case 0x4d414e44: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x2c), s); break;
        case 0x4d414e42: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x50), s); break;
        case 0x4d414e45: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x5c), s); break;
        case 0x4d414e47: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x68), s); break;
        case 0x4d414e4a: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x74), s); break;
        case 0x4d414e4b: f3m_004fed60::TESTexture_LoadTextureChunk((void*)(t + 0x80), s); break;
        case 0x4d414e4f: s->FUN_00447d60(t + 0x5c, 4); break;
        case 0x4d414e50: {
            s->FUN_00447d60(t + 0x60, 0x40);
            if (s->unk299) {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        f3_004ffdb0_Swap32(&((unsigned int (*)[4])(t + 0x60))[i][j]);
            }
            break;
        }
        case 0x4d414e46: {
            int cnt = 6;
            if (s->unk25c != 0x18)
                cnt = 4;
            s->FUN_00447d60(t + 0xc8, 0x18);
            if (s->unk299) {
                for (int i = 0; i < cnt; i++)
                    f3_004ffdb0_Swap32(&((unsigned int*)(t + 0xc8))[i]);
            }
            break;
        }
        case 0x4d414e48: {
            s->FUN_00447d60(t + 0x188, 0x38);
            if (s->unk299) {
                for (int i = 0; i < 14; i++)
                    f3_004ffdb0_Swap32(&((unsigned int*)(t + 0x188))[i]);
            }
            break;
        }
        case 0x4d414e49: {
            s->FUN_00447d60(t + 0x1c0, 0x130);
            if (s->unk299) {
                for (int i = 0; i < 2; i++)
                    ((f3_004ffdb0_Sub98*)(t + 0x1c0 + i * 0x98))->FUN_00b10fe0();
            }
            break;
        }
        case 0x4d414e4c: {
            s->FUN_00447d60(t + 0x2f0, 4);
            if (s->unk299)
                f3_004ffdb0_Swap32((unsigned int*)(t + 0x2f0));
            break;
        }
        case 0x4d414e53: {
            f3_004ffdb0_Pair* e = new f3_004ffdb0_Pair;
            {
            // Fake match: a named copy in its own block. Its address goes to the list call, so the
            // copy is stored before the read call and shares the stack slot of the id temporaries.
            f3_004ffdb0_Pair* keep = e;
            s->FUN_00447d60(e, 8);
            if (s->unk299) {
                e->Endian();
            }
            TESForm_AddCompileIndex(e, s);
            ((f3_004ffdb0_PairList*)(t + 0x180))->FUN_0061c430(&keep);
            }
            break;
        }
        }
        if (!s->TESFile_NextChunk())
            break;
    }
    return 1;
}
