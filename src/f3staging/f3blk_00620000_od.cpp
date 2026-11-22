// src/f3staging/f3blk_00620000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0063c810 (community match, verified in this file)
int __cdecl FUN_00c047de(const char*);
extern const char DAT_00e04f58[];
extern const float DAT_00e04f54;
struct HeapCredits { void* FUN_0086b930(unsigned); void FUN_0086ba60(void*); };
extern HeapCredits DAT_01090a78;
void* __cdecl FUN_0089eb90(unsigned);
struct StreamCredits { virtual void Destroy(); virtual bool IsOpen(); };
struct FileCredits : StreamCredits {
 unsigned offset;
 unsigned (__cdecl *read)(FileCredits*,void*,unsigned,unsigned*,unsigned);
 void* write; unsigned bufferSize,unk14,unk18,unk1c; void* buffer; void* file;
 unsigned mode; unsigned char good; unsigned char unk2d; unsigned short unk2e;
 unsigned unk30,unk34,unk38,unk3c,unk40; char path[260]; unsigned unk148,unk14c,unk150,unk154;
 void FUN_00bcd300(const char*,unsigned,unsigned,unsigned);
 void FUN_00bcd9b0(); unsigned FUN_00bcd4a0();
 FileCredits(const char* p,unsigned m,unsigned n,unsigned a);
 ~FileCredits();
 unsigned Read(void* dst,unsigned n) { unsigned element=1; unsigned got=read(this,dst,n,&element,1);offset+=got;return got; }
};
struct VecCredits { float x,y,z; VecCredits(){} VecCredits(float a,float b,float c):x(a),y(b),z(c){} };
struct UpdateCredits {float time;bool a,b,c,d,e; UpdateCredits():time(0.0f),a(false),b(false),c(false),d(false),e(false){} };
struct NiNode;
struct NodeInterfaceCredits {
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
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual void v54();
 virtual void v58();
 virtual void v5c();
 virtual void v60();
 virtual void v64();
 virtual void v68();
 virtual void v6c();
 virtual void v70();
 virtual void v74();
 virtual void v78();
 virtual void v7c();
 virtual void v80();
 virtual void v84();
 virtual void v88();
 virtual void v8c();
 virtual void v90();
 virtual void v94();
 virtual void v98();
 virtual void v9c();
 virtual void va0();
 virtual void va4();
 virtual void va8();
 virtual void vac();
 virtual void vb0();
 virtual void vb4();
 virtual void vb8();
 virtual void vbc();
 virtual void vc0();
 virtual void vc4();
 virtual void vc8();
 virtual void vcc();
 virtual void vd0();
 virtual void vd4();
 virtual void vd8();
 virtual void Attach(NiNode*,bool);
};
struct NiNode : NodeInterfaceCredits {
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 VecCredits position;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 NiNode(unsigned short n);
 static void* operator new(unsigned n) {return FUN_0089eb90(n);}
 void SetPosition(const VecCredits& v){position=v;}
 void FUN_004236f0(void*);
 void FUN_008268a0();void FUN_00c24b70();void FUN_008264c0(const UpdateCredits&);
};
struct NiProperty {
 virtual ~NiProperty();
 unsigned unk04,unk08,unk0c,unk10,unk14;
 NiProperty();
};
struct NiAlphaProperty : NiProperty {
 static void* operator new(unsigned n){return FUN_0089eb90(n);}
 unsigned short flags; unsigned char unk1a;
 NiAlphaProperty():flags(0xec),unk1a(0) {}
 virtual ~NiAlphaProperty();
};
struct NodeRefCredits {NiNode* p;void FUN_008e9650(NiNode*);};
struct FontCredits {
 unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;float height;
 NiNode* FUN_00bf6260(float,float,float,BSStringT<char>*,unsigned*,unsigned,float*,unsigned,unsigned);
};
extern FontCredits** DAT_011796f8;
struct OwnerCredits {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28;NiNode* node;};
struct Credits {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 OwnerCredits* owner; NodeRefCredits root;unsigned cursor,size;char* text;int font;unsigned align;int x,y;float color[4];
 void FUN_0063c2c0(BSStringT<char>*);
 NiNode* FUN_0063c350(BSStringT<char>*,int,int,float);
 void FUN_0063c810();
};
template<> inline BSStringT<char>::BSStringT(){pString=0;sLen=0;sMaxLen=0;}
template<> inline BSStringT<char>::~BSStringT(){if(pString)DAT_01090a78.FUN_0086ba60(pString);pString=0;sMaxLen=0;sLen=0;}
inline void releaseCredits(char* p) { DAT_01090a78.FUN_0086ba60(p); }
// pdb: CreditsMenu::InitCreditsRoot | CreditsMenu.obj | fnv360_0822_retail, call_gap, low
void Credits::FUN_0063c810() {
 FileCredits file(DAT_00e04f58,0,0x2800,0);
 StreamCredits& stream=file;
 if (!stream.IsOpen()) return;
 {
  size=file.FUN_00bcd4a0()+1;
  text=(char*)DAT_01090a78.FUN_0086b930(size);
  text[size-1]=0;
  if(file.Read(text,size-1)!=size-1){releaseCredits(text);text=0;return;}
  {
   root.FUN_008e9650(new NiNode(0));
   root.p->SetPosition(VecCredits(0.0f,0.0f,DAT_00e04f54));
   NiNode* parent=owner->node;
   NiNode* child=root.p;
   parent->Attach(child,true);
   NiAlphaProperty* property=new NiAlphaProperty;
   property->flags|=1;
   root.p->FUN_004236f0(property);
   FontCredits* currentFont=DAT_011796f8[font];
   BSStringT<char> line;
   while(cursor<size){
    if(text[cursor]=='\r') {float lineHeight=currentFont->height;y-=(int)lineHeight;}
    while(text[cursor]!='\n') {
     if(cursor>=size)break;
     unsigned char c=text[cursor];
     switch(c) {
     default: if(c<' ') {++cursor;break;}
     {
      FUN_0063c2c0(&line);
      unsigned options=0x500;
      NiNode* node=currentFont->FUN_00bf6260(0.0f,0.0f,0.0f,&line,&options,align,color,1,1);
      node->SetPosition(VecCredits((float)x,0.0f,(float)y));
      root.p->Attach(node,true);
      float lineHeight=currentFont->height; y-=(int)lineHeight;
     } break;
     case '<': {
      ++cursor;
      switch(text[cursor]) {
       case 'X': {
        const char* value=text+cursor+2;
        if(*value=='+')x+=FUN_00c047de(text+cursor+3);else if(*value=='-')x-=FUN_00c047de(text+cursor+3);else x=FUN_00c047de(value);
        break;
       }
       case 'Y': {
        const char* value=text+cursor+2;
        if(*value=='+')y-=FUN_00c047de(text+cursor+3);else if(*value=='-')y+=FUN_00c047de(text+cursor+3);else y=FUN_00c047de(value);
        break;
       }
       case 'I': {
        int width=FUN_00c047de(text+cursor+2);
        int height=FUN_00c047de(text+cursor+7);
        float alpha=FUN_00c047de(text+cursor+12)/255.0;
        cursor+=16;
        FUN_0063c2c0(&line);
        NiNode* image=FUN_0063c350(&line,width,height,alpha);
        root.p->Attach(image,true);
        y-=height;break;
       }
       case 'J': {
        char a=text[cursor+2];if(a=='C')align=2;else align=a=='R'?4:1;break;
       }
       case 'F': font=text[cursor+2]-'1';currentFont=DAT_011796f8[font];break;
       case 'C':
        color[0]=FUN_00c047de(text+cursor+2)/255.0;
        color[1]=FUN_00c047de(text+cursor+6)/255.0;
        color[2]=FUN_00c047de(text+cursor+10)/255.0;
        color[3]=FUN_00c047de(text+cursor+14)/255.0;break;
      }
      while(text[cursor]!='>') { ++cursor;if(cursor>=size)goto nextCharacter; }
      ++cursor;
     } break;
     case '*':
      while(text[cursor]!='\n' && cursor<size) ++cursor;
      break;
     }
     nextCharacter:;
    }
    while(text[cursor]!='\n' && cursor<size)++cursor;
    ++cursor;
   }
   releaseCredits(text);text=0;
   root.p->FUN_008268a0();root.p->FUN_00c24b70();
   NiNode* current=root.p;UpdateCredits update;current->FUN_008264c0(update);
  }
 }
}

// @f3 0x006242f0 (community match, verified in this file)
#include <stdarg.h>
#include <string.h>
extern int* DAT_0107a104;
extern int* DAT_00f47c7c[];
extern int DAT_01179794;
extern int DAT_0107a258;
extern int DAT_01075cdc;
extern const double DAT_00dcd110;
extern const float DAT_00dd90a8, DAT_00db38b8;
namespace f3m_006242f0 {
struct DebugLock;

struct DebugTeleport;

struct DebugMarker;

struct DebugFurniture;

struct DebugPlayer;

class TESObjectREFR;



class TESForm {

public:

    virtual void Slot000();

    virtual void Slot004();

    virtual void Slot008();

    virtual void Slot00c();

    virtual void Slot010();

    virtual void Slot014();

    virtual void Slot018();

    virtual void Slot01c();

    virtual void Slot020();

    virtual void Slot024();

    virtual void Slot028();

    virtual void Slot02c();

    virtual void Slot030();

    virtual void Slot034();

    virtual void Slot038();

    virtual void Slot03c();

    virtual void Slot040();

    virtual void Slot044();

    virtual void Slot048();

    virtual void Slot04c();

    virtual void Slot050();

    virtual void Slot054();

    virtual void Slot058();

    virtual void Slot05c();

    virtual void Slot060();

    virtual void Slot064();

    virtual void Slot068();

    virtual void Slot06c();

    virtual void Slot070();

    virtual void Slot074();

    virtual void Slot078();

    virtual void Slot07c();

    virtual void Slot080();

    virtual void Slot084();

    virtual void Slot088();

    virtual void Slot08c();

    virtual void Slot090();

    virtual void Slot094();

    virtual void Slot098();

    virtual void Slot09c();

    virtual void Slot0a0();

    virtual void Slot0a4();

    virtual void Slot0a8();

    virtual void Slot0ac();

    virtual void Slot0b0();

    virtual void Slot0b4();

    virtual void Slot0b8();

    virtual void Slot0bc();

    virtual void Slot0c0();

    virtual void Slot0c4();

    virtual void Slot0c8();

    virtual void Slot0cc();

    virtual void Slot0d0();

    virtual void Slot0d4();

    virtual void Slot0d8();

    virtual void Slot0dc();

    virtual void Slot0e0();

    virtual void Slot0e4();

    virtual void Slot0e8();

    virtual void Slot0ec();

    virtual void Slot0f0();

    virtual void Slot0f4();

    virtual void Slot0f8();

    virtual void Slot0fc();

    virtual bool IsActor();

    virtual void Slot104();

    virtual void Slot108();

    virtual void Slot10c();

    virtual void Slot110();

    virtual void Slot114();

    virtual void Slot118();

    virtual void Slot11c();

    virtual void Slot120();

    virtual void Slot124();

    virtual void Slot128();

    virtual void Slot12c();

    virtual const char* GetEditorName();

    unsigned int unk004, unk008, formId;
    __forceinline unsigned int GetFormID() const { return formId; }
};

struct DebugExtras {

    TESForm* FUN_0040ace0();

    short FUN_0040ac80();

    void* FUN_0040c2c0();

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

};

class TESObjectREFR : public TESForm {

public:

    unsigned int unk010, unk014, unk018;

    DebugFurniture* baseObject;

    unsigned int unk020, unk024;

    float rotationZ;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    DebugExtras extras;

    const char* FUN_004e9a10();

    TESForm* TESObjectREFR_GetOwner();

    bool FUN_004e7210();

    bool FUN_004ec140(int index, DebugMarker* data);

    bool FUN_004e6e30(int index, int checkOccupancy);

    DebugLock* TESObjectREFR_GetLock();

    DebugTeleport* TESObjectREFR_GetTeleport();

    unsigned int FUN_004e8030();
    __forceinline DebugFurniture* GetBaseObject() const { return baseObject; }
    __forceinline DebugExtras* GetExtraList() { return &extras; }
};

class BaseProcess {

public:

    virtual void Slot000();

    virtual void Slot004();

    virtual void Slot008();

    virtual void Slot00c();

    virtual void Slot010();

    virtual void Slot014();

    virtual void Slot018();

    virtual void Slot01c();

    virtual void Slot020();

    virtual void Slot024();

    virtual void Slot028();

    virtual void Slot02c();

    virtual void Slot030();

    virtual void Slot034();

    virtual void Slot038();

    virtual void Slot03c();

    virtual void Slot040();

    virtual void Slot044();

    virtual void Slot048();

    virtual void Slot04c();

    virtual void Slot050();

    virtual void Slot054();

    virtual void Slot058();

    virtual void Slot05c();

    virtual void Slot060();

    virtual void Slot064();

    virtual void Slot068();

    virtual void Slot06c();

    virtual void Slot070();

    virtual void Slot074();

    virtual void Slot078();

    virtual void Slot07c();

    virtual void Slot080();

    virtual void Slot084();

    virtual void Slot088();

    virtual void Slot08c();

    virtual void Slot090();

    virtual void Slot094();

    virtual void Slot098();

    virtual void Slot09c();

    virtual void Slot0a0();

    virtual void Slot0a4();

    virtual void Slot0a8();

    virtual void Slot0ac();

    virtual void Slot0b0();

    virtual void Slot0b4();

    virtual void Slot0b8();

    virtual void Slot0bc();

    virtual void Slot0c0();

    virtual void Slot0c4();

    virtual void Slot0c8();

    virtual void Slot0cc();

    virtual void Slot0d0();

    virtual void Slot0d4();

    virtual void Slot0d8();

    virtual void Slot0dc();

    virtual void Slot0e0();

    virtual void Slot0e4();

    virtual void Slot0e8();

    virtual void Slot0ec();

    virtual void Slot0f0();

    virtual void Slot0f4();

    virtual void Slot0f8();

    virtual void Slot0fc();

    virtual void Slot100();

    virtual void Slot104();

    virtual void Slot108();

    virtual void Slot10c();

    virtual void Slot110();

    virtual void Slot114();

    virtual void Slot118();

    virtual void Slot11c();

    virtual void Slot120();

    virtual void Slot124();

    virtual void Slot128();

    virtual void Slot12c();

    virtual void Slot130();

    virtual void Slot134();

    virtual void Slot138();

    virtual void Slot13c();

    virtual void Slot140();

    virtual void Slot144();

    virtual void Slot148();

    virtual void Slot14c();

    virtual void Slot150();

    virtual void Slot154();

    virtual void Slot158();

    virtual void Slot15c();

    virtual void Slot160();

    virtual void Slot164();

    virtual void Slot168();

    virtual void Slot16c();

    virtual void Slot170();

    virtual void Slot174();

    virtual void Slot178();

    virtual void Slot17c();

    virtual void Slot180();

    virtual void Slot184();

    virtual void Slot188();

    virtual void Slot18c();

    virtual void Slot190();

    virtual void Slot194();

    virtual void Slot198();

    virtual void Slot19c();

    virtual void Slot1a0();

    virtual void Slot1a4();

    virtual void Slot1a8();

    virtual void Slot1ac();

    virtual void Slot1b0();

    virtual void Slot1b4();

    virtual void Slot1b8();

    virtual void Slot1bc();

    virtual void Slot1c0();

    virtual void Slot1c4();

    virtual void Slot1c8();

    virtual void Slot1cc();

    virtual void Slot1d0();

    virtual void Slot1d4();

    virtual void Slot1d8();

    virtual void Slot1dc();

    virtual void Slot1e0();

    virtual void Slot1e4();

    virtual void Slot1e8();

    virtual void Slot1ec();

    virtual void Slot1f0();

    virtual void Slot1f4();

    virtual void Slot1f8();

    virtual void Slot1fc();

    virtual void Slot200();

    virtual void Slot204();

    virtual void Slot208();

    virtual void Slot20c();

    virtual void Slot210();

    virtual void Slot214();

    virtual void Slot218();

    virtual void Slot21c();

    virtual void Slot220();

    virtual void Slot224();

    virtual void Slot228();

    virtual void Slot22c();

    virtual void Slot230();

    virtual void Slot234();

    virtual void Slot238();

    virtual void Slot23c();

    virtual void Slot240();

    virtual void Slot244();

    virtual void Slot248();

    virtual void Slot24c();

    virtual void Slot250();

    virtual void Slot254();

    virtual void Slot258();

    virtual void Slot25c();

    virtual void Slot260();

    virtual void Slot264();

    virtual void Slot268();

    virtual void Slot26c();

    virtual void Slot270();

    virtual void Slot274();

    virtual void Slot278();

    virtual void Slot27c();

    virtual void Slot280();

    virtual void Slot284();

    virtual void Slot288();

    virtual void Slot28c();

    virtual void Slot290();

    virtual void Slot294();

    virtual void Slot298();

    virtual void Slot29c();

    virtual void Slot2a0();

    virtual void Slot2a4();

    virtual void Slot2a8();

    virtual void Slot2ac();

    virtual void Slot2b0();

    virtual void Slot2b4();

    virtual void Slot2b8();

    virtual void Slot2bc();

    virtual void Slot2c0();

    virtual void Slot2c4();

    virtual void Slot2c8();

    virtual void Slot2cc();

    virtual void Slot2d0();

    virtual void Slot2d4();

    virtual void Slot2d8();

    virtual void Slot2dc();

    virtual void Slot2e0();

    virtual void Slot2e4();

    virtual void Slot2e8();

    virtual void Slot2ec();

    virtual void Slot2f0();

    virtual void Slot2f4();

    virtual void Slot2f8();

    virtual void Slot2fc();

    virtual void Slot300();

    virtual void Slot304();

    virtual void Slot308();

    virtual void Slot30c();

    virtual void Slot310();

    virtual void Slot314();

    virtual void Slot318();

    virtual void Slot31c();

    virtual void Slot320();

    virtual void Slot324();

    virtual void Slot328();

    virtual void Slot32c();

    virtual void Slot330();

    virtual void Slot334();

    virtual void Slot338();

    virtual void Slot33c();

    virtual void Slot340();

    virtual void Slot344();

    virtual void Slot348();

    virtual void Slot34c();

    virtual void Slot350();

    virtual void Slot354();

    virtual void Slot358();

    virtual void Slot35c();

    virtual void Slot360();

    virtual void Slot364();

    virtual void Slot368();

    virtual void Slot36c();

    virtual void Slot370();

    virtual void Slot374();

    virtual void Slot378();

    virtual void Slot37c();

    virtual void Slot380();

    virtual void Slot384();

    virtual void Slot388();

    virtual void Slot38c();

    virtual void Slot390();

    virtual void Slot394();

    virtual void Slot398();

    virtual void Slot39c();

    virtual void Slot3a0();

    virtual void Slot3a4();

    virtual void Slot3a8();

    virtual void Slot3ac();

    virtual void Slot3b0();

    virtual void Slot3b4();

    virtual void Slot3b8();

    virtual void Slot3bc();

    virtual void Slot3c0();

    virtual void Slot3c4();

    virtual void Slot3c8();

    virtual void Slot3cc();

    virtual void Slot3d0();

    virtual void Slot3d4();

    virtual void Slot3d8();

    virtual void Slot3dc();

    virtual void Slot3e0();

    virtual void Slot3e4();

    virtual void Slot3e8();

    virtual void Slot3ec();

    virtual void Slot3f0();

    virtual void Slot3f4();

    virtual void Slot3f8();

    virtual void Slot3fc();

    virtual void Slot400();

    virtual void Slot404();

    virtual void Slot408();

    virtual void Slot40c();

    virtual void Slot410();

    virtual void Slot414();

    virtual void Slot418();

    virtual void Slot41c();

    virtual void Slot420();

    virtual void Slot424();

    virtual void Slot428();

    virtual void Slot42c();

    virtual void Slot430();

    virtual void Slot434();

    virtual void Slot438();

    virtual void Slot43c();

    virtual void Slot440();

    virtual void Slot444();

    virtual void Slot448();

    virtual void Slot44c();

    virtual void Slot450();

    virtual void Slot454();

    virtual void Slot458();

    virtual void Slot45c();

    virtual void Slot460();

    virtual void Slot464();

    virtual void Slot468();

    virtual void Slot46c();

    virtual void Slot470();

    virtual void Slot474();

    virtual void Slot478();

    virtual void Slot47c();

    virtual void Slot480();

    virtual void Slot484();

    virtual void Slot488();

    virtual void Slot48c();

    virtual void Slot490();

    virtual void Slot494();

    virtual void Slot498();

    virtual void Slot49c();

    virtual void Slot4a0();

    virtual void Slot4a4();

    virtual void Slot4a8();

    virtual void Slot4ac();

    virtual void Slot4b0();

    virtual void Slot4b4();

    virtual void Slot4b8();

    virtual void Slot4bc();

    virtual void Slot4c0();

    virtual TESForm* GetFurniture();

    virtual int GetFurnitureIndex();

};

class Actor : public TESObjectREFR {

public:

    virtual void Slot134();

    virtual void Slot138();

    virtual void Slot13c();

    virtual void Slot140();

    virtual void Slot144();

    virtual void Slot148();

    virtual void Slot14c();

    virtual void Slot150();

    virtual void Slot154();

    virtual void Slot158();

    virtual void Slot15c();

    virtual void Slot160();

    virtual void Slot164();

    virtual void Slot168();

    virtual void Slot16c();

    virtual void Slot170();

    virtual void Slot174();

    virtual void Slot178();

    virtual void Slot17c();

    virtual void Slot180();

    virtual void Slot184();

    virtual void Slot188();

    virtual void Slot18c();

    virtual void Slot190();

    virtual void Slot194();

    virtual void Slot198();

    virtual void Slot19c();

    virtual void Slot1a0();

    virtual void Slot1a4();

    virtual void Slot1a8();

    virtual void Slot1ac();

    virtual void Slot1b0();

    virtual void Slot1b4();

    virtual void Slot1b8();

    virtual void Slot1bc();

    virtual void Slot1c0();

    virtual void Slot1c4();

    virtual void Slot1c8();

    virtual void Slot1cc();

    virtual void Slot1d0();

    virtual void Slot1d4();

    virtual void Slot1d8();

    virtual void Slot1dc();

    virtual void Slot1e0();

    virtual void Slot1e4();

    virtual void Slot1e8();

    virtual void Slot1ec();

    virtual void Slot1f0();

    virtual void Slot1f4();

    virtual void Slot1f8();

    virtual void Slot1fc();

    virtual void Slot200();

    virtual void Slot204();

    virtual void Slot208();

    virtual void Slot20c();

    virtual void Slot210();

    virtual void* IsUsingFurniture();

    BaseProcess* process;
    __forceinline BaseProcess* GetProcess() const { return process; }
};

struct DebugMarker {
    unsigned int unk00, unk04, unk08;
    unsigned short state;
    unsigned char index, unk0f;
    __forceinline void Reset(unsigned char idx)
    {
        state = 0;
        index = idx;
    }
    __forceinline unsigned int GetIndex() const { return index; }
};
struct DebugDelta {
    float x, y, z;
};
struct DebugFurniture {
    bool TESFurniture_GetMarkerEnabled(int index);
    void FUN_004ae080(DebugDelta* delta, unsigned int marker, float playerContext);
    float TESFurniture_GetMarkerHeadingOffset(unsigned int marker);
};
struct DebugPlayer {
    float FUN_004e6d80();
};
bool __cdecl FUN_004add90(unsigned int marker);

struct DebugText {
    char* text;
    unsigned short length, capacity;
    DebugText() : text(0), length(0), capacity(0) {}
    __forceinline ~DebugText()
    {
        if (text)
            DAT_01090a78.FUN_0086ba60(text);
    }
    bool Set(const char* value, unsigned int minimum);
    int FormatV(const char* format, va_list args);
    __forceinline const char* GetText() const { return text; }
    __forceinline const char* GetString() const { return text ? text : ""; }
};
struct FullName {
    unsigned int vtable;
    DebugText name;
    __forceinline const char* GetName() const
    {
        if (name.GetText())
            return name.GetText();
        return "";
    }
};
struct DebugKey {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    FullName fullName;
    __forceinline const char* GetName() const { return fullName.GetName(); }
};
struct DebugLock {
    unsigned int unk00;
    DebugKey* key;
    unsigned char flags;
    int FUN_0041ece0(TESObjectREFR* reference);
};
struct LockLabel {
    unsigned int unk00;
    const char* name;
    __forceinline const char* GetName() const { return this ? name : 0; }
};
struct DebugCell {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    FullName fullName;
    __forceinline const char* GetName() const { return fullName.GetName(); }
};
struct DebugTeleport {
    DebugCell* FUN_00423840();
    TESObjectREFR* FUN_004237e0();
};
struct DebugFont {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    const float* height;
    __forceinline float GetHeight() const { return height ? *height : 0.0f; }
};
struct FontManager {

    static __forceinline DebugFont* __stdcall GetFont(int idx);
};
__forceinline DebugFont* __stdcall FontManager::GetFont(int idx)
{
    return reinterpret_cast<DebugFont**>(::DAT_011796f8)[idx - 1];
}

int __cdecl FUN_00c010b9(char* buffer, const char* format, va_list args);

bool DebugText::Set(const char* value, unsigned int minimum)
{
    const unsigned int count = value ? strlen(value) : 0;
    const unsigned int required = count > minimum ? count : minimum;
    if (required <= capacity) {
        if (required) {
            if (value)
                memmove(text, value, count + 1);
            else
                text[0] = 0;
        } else {
            if (text)
                DAT_01090a78.FUN_0086ba60(text);
            text = 0;
            capacity = 0;
        }
    } else {
        char* previous = text;
        text = static_cast<char*>(DAT_01090a78.FUN_0086b930(required + 1));
        if (value)
            memmove(text, value, count + 1);
        else
            text[0] = 0;
        if (previous)
            DAT_01090a78.FUN_0086ba60(previous);
        capacity = (required <= 0xffff ? static_cast<unsigned short>(required) : static_cast<unsigned short>(0xffff));
    }
    length = (count <= 0xffff ? static_cast<unsigned short>(count) : static_cast<unsigned short>(0xffff));
    return count != 0;
}

int DebugText::FormatV(const char* format, va_list args)
{
    char buffer[1024];
    int result = FUN_00c010b9(buffer, format, args);
    Set(buffer, 0);
    return result;
}

int __cdecl FUN_00403a00(DebugText* target, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int result = target->FormatV(format, args);
    va_end(args);
    return result;
}
int __cdecl FUN_00c007fc(char* target, unsigned int size, const char* value);
int __cdecl FUN_00c00fcc(char* target, unsigned int size, const char* value);
struct DebugOverlay {
    int FUN_00bfb050(const char* text, float x, float y, int style, int channel = -1, float duration = -1.0f, int a = 0, const void* b = 0);
};
DebugOverlay* __cdecl FUN_00bfb7c0(bool create);

struct DebugReferenceNode {
    TESObjectREFR* reference;
    DebugReferenceNode* next;
};
struct DebugInterfaceManager {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    DebugReferenceNode debugReferences;
    int selectedIndex;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned char unkdc;
    bool showDetails;
    unsigned char unkde, unkdf;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    TESObjectREFR* selectedReference;
    void FUN_006242f0();
};
// pdb: InterfaceManager::DisplayCurrentPickRef | InterfaceManager.obj | fnv360_0721_beta, ustr, low, conflict (skyrim: Console::DisplayRef)
void DebugInterfaceManager::FUN_006242f0()
{
    int headingRow;
    int index;
    TESObjectREFR* picked;
    int row;
    int endRow;
    int lineHeight;
    DebugReferenceNode* node;
    picked = 0;
    lineHeight = (int)FontManager::GetFont(DAT_01179794)->GetHeight() + 3;
    headingRow = DAT_0107a258;
    row = headingRow + 30;
    index = 0;
    for (node = &debugReferences; node && node->reference && index <= selectedIndex; node = node->next) {
        picked = node->reference;
        index++;
    }

    if (picked) {
        Actor* aco;
        Actor* abo;
        unsigned int actions;
        DebugText message;
        selectedReference = picked;
        FUN_00403a00(&message, "\"%s\" (%08x)", selectedReference->FUN_004e9a10(), selectedReference->GetFormID());
        FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)headingRow, 2, -1, -1.0f, 0, 0);

        if (showDetails) {
            if (selectedReference->extras.FUN_0040ace0()) {
                FUN_00403a00(&message, "Script name '%s' (%08x)", selectedReference->extras.FUN_0040ace0()->GetEditorName(),
                             selectedReference->extras.FUN_0040ace0()->GetFormID());
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
            }

            if (selectedReference->IsActor()) {
                abo = static_cast<Actor*>(selectedReference);
                if (abo->GetProcess() != 0) {
                    if (abo->GetProcess()->GetFurniture() != 0) {
                        FUN_00403a00(&message, "current Furniture '%s' (%08x)", abo->GetProcess()->GetFurniture()->GetEditorName(),
                                     abo->GetProcess()->GetFurniture()->GetFormID());
                        FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                        row += lineHeight;
                    }
                }
            }

            if (selectedReference->TESObjectREFR_GetOwner()) {
                FUN_00403a00(&message, "Owner name '%s' (%08x)", selectedReference->TESObjectREFR_GetOwner()->GetEditorName(),
                             selectedReference->TESObjectREFR_GetOwner()->GetFormID());
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
            }

            if (selectedReference->extras.FUN_0040ac80() != 1) {
                FUN_00403a00(&message, "Count %d", (int)selectedReference->extras.FUN_0040ac80());
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
            }

            if (selectedReference->IsActor()) {
                aco = dynamic_cast<Actor*>(selectedReference);
                if (aco->IsUsingFurniture()) {
                    if (aco->GetProcess()->GetFurniture() == 0) {
                        FUN_00403a00(&message, "Furniture 'UNKNOWN' (UNKNOWN) index %d", aco->GetProcess()->GetFurnitureIndex());
                    } else {
                        FUN_00403a00(&message, "Furniture '%s' (%08x) index %d",
                                     aco->GetProcess()->GetFurniture()->GetEditorName(),
                                     aco->GetProcess()->GetFurniture()->GetFormID(),
                                     aco->GetProcess()->GetFurnitureIndex());
                    }
                    FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                    row += lineHeight;
                }
            }

            if (selectedReference->FUN_004e7210()) {
                FUN_00403a00(&message, "Orentation %d deg", (int)(selectedReference->rotationZ * DAT_00dcd110));
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
                DebugMarker marker;
                int markerNumber;
                marker.Reset(0xff);
                markerNumber = 0;
                while (selectedReference->FUN_004ec140(markerNumber, &marker)) {
                    DebugFurniture* furniture = selectedReference->GetBaseObject();
                    int markerId = (int)marker.GetIndex();
                    if (furniture->TESFurniture_GetMarkerEnabled(markerNumber)) {
                        DebugDelta delta;
                        furniture->FUN_004ae080(&delta, marker.GetIndex(), reinterpret_cast<DebugPlayer*>(DAT_0107a104)->FUN_004e6d80());
                        const char* used = selectedReference->FUN_004e6e30(markerNumber, 1) ? "USED" : "UNUSED";
                        bool sit = FUN_004add90(markerId);
                        FUN_00403a00(&message, "%s Marker %d Delta %0.2f,%0.2f,%0.2f (%d deg) %s",
                                     sit ? "Sit" : "Sleep", markerId,
                                     (double)delta.x, (double)delta.y, (double)delta.z,
                                     (int)(furniture->TESFurniture_GetMarkerHeadingOffset(markerId) * DAT_00dcd110),
                                     used);
                    } else {
                        bool sit = FUN_004add90(markerId);
                        FUN_00403a00(&message, "Disabled %s Marker %d", sit ? "Sit" : "Sleep", markerId);
                    }
                    FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                    row += lineHeight;
                    markerNumber++;
                }
            }

            if (selectedReference->TESObjectREFR_GetLock()) {
                DebugLock* lock = selectedReference->TESObjectREFR_GetLock();
                FUN_00403a00(&message, "Lock '%s' %s.",
                             reinterpret_cast<LockLabel**>(&DAT_00f47c7c)[lock->FUN_0041ece0(selectedReference)]->GetName(),
                             (lock->flags & 1) ? "Locked" : "Unlocked");
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
                if (lock->key) {
                    FUN_00403a00(&message, "Key '%s'.", lock->key->GetName());
                    FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                    row += lineHeight;
                }
            }

            if (selectedReference->TESObjectREFR_GetTeleport()) {
                DebugTeleport* teleport = selectedReference->TESObjectREFR_GetTeleport();
                DebugCell* cell = teleport->FUN_00423840();
                TESObjectREFR* door = teleport->FUN_004237e0();
                const char* cellName;
                const char* doorName;
                cellName = "Unknown";
                doorName = "Unknown";
                if (cell && cell->GetName()) {
                    cellName = cell->GetName();
                } else if (door && door->GetExtraList()->FUN_0040c2c0()) {
                    cellName = "Persistent";
                }
                if (door && door->FUN_004e9a10())
                    doorName = door->FUN_004e9a10();
                FUN_00403a00(&message, "Teleport Cell '%s' Door '%s'.", cellName, doorName);
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
            }

            actions = selectedReference->FUN_004e8030();
            if (actions) {
                char actionText[256];
                FUN_00c007fc(actionText, sizeof(actionText), "Action Flags: ");
                if (actions & 1) FUN_00c00fcc(actionText, sizeof(actionText), "USE_DEFAULT");
                if (actions & 2) FUN_00c00fcc(actionText, sizeof(actionText), ", ACTIVATE");
                if (actions & 4) FUN_00c00fcc(actionText, sizeof(actionText), ", OPEN");
                if (actions & 8) FUN_00c00fcc(actionText, sizeof(actionText), ", OPEN_BY_DEFAULT");
                FUN_00403a00(&message, actionText);
                FUN_00bfb7c0(true)->FUN_00bfb050(message.GetText(), DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
                row += lineHeight;
            }
        }
    } else {
        int elseLineH;
        selectedReference = 0;
        elseLineH = DAT_0107a258;
        FUN_00bfb7c0(true)->FUN_00bfb050("", DAT_00dd90a8, (float)elseLineH, 2, -1, -1.0f, 0, 0);
    }

    endRow = row;
    while (row < DAT_01075cdc) {
        FUN_00bfb7c0(true)->FUN_00bfb050("", DAT_00dd90a8, (float)row, 2, -1, -1.0f, 0, 0);
        row += lineHeight;
    }
    DAT_01075cdc = endRow;
}
}   // namespace f3m_006242f0
