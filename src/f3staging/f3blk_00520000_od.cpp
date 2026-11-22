// src/f3staging/f3blk_00520000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0053a480 (community match, verified in this file)
#include <math.h>
class TESForm;
class TESObjectREFR;
class Actor;
struct LeveledResolver53 {TESForm* FUN_0047e910(TESForm*);};
struct InventoryResolver53 { int unk00; LeveledResolver53* FUN_0040ab00();};
struct Process53;
struct InventoryUpdate53 { int unk00; void FUN_006b71f0(TESForm*,int);};
class TESForm { public:
virtual void slot000();
virtual void slot004();
virtual void slot008();
virtual void slot00c();
virtual void slot010();
virtual void slot014();
virtual void slot018();
virtual void slot01c();
virtual void slot020();
virtual void slot024();
virtual void slot028();
virtual void slot02c();
virtual void slot030();
virtual void slot034();
virtual void slot038();
virtual void slot03c();
virtual void slot040();
virtual void slot044();
virtual void slot048();
virtual void slot04c();
virtual void slot050();
virtual void slot054();
virtual void slot058();
virtual void slot05c();
virtual void slot060();
virtual void slot064();
virtual void slot068();
virtual void slot06c();
virtual void slot070();
virtual void slot074();
virtual void slot078();
virtual void slot07c();
virtual void slot080();
virtual void slot084();
virtual void slot088();
virtual void slot08c();
virtual void slot090();
virtual void slot094();
virtual void slot098();
virtual void slot09c();
virtual void slot0a0();
virtual void slot0a4();
virtual void slot0a8();
virtual void slot0ac();
virtual void slot0b0();
virtual void slot0b4();
virtual void slot0b8();
virtual void slot0bc();
virtual void slot0c0();
virtual void slot0c4();
virtual void slot0c8();
virtual void slot0cc();
virtual void slot0d0();
virtual void slot0d4();
virtual void slot0d8();
virtual void slot0dc();
virtual void slot0e0();
virtual bool IsBoundObject();
unsigned char type; unsigned char unk05; unsigned short unk06; unsigned int unk08,unk0c,unk10,unk14;
};
class TESObjectREFR : public TESForm { public:
virtual void slot0e8();
virtual void slot0ec();
virtual void slot0f0();
virtual void slot0f4();
virtual void slot0f8();
virtual void slot0fc();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10c();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11c();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12c();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual void slot13c();
virtual void slot140();
virtual void slot144();
virtual void slot148();
virtual void slot14c();
virtual void slot150();
virtual void slot154();
virtual void slot158();
virtual void slot15c();
virtual void slot160();
virtual void slot164();
virtual void slot168();
virtual void slot16c();
virtual void slot170();
virtual void slot174();
virtual void slot178();
virtual void Remove(TESForm*, void*, int, int, int, int, int, int, int, int);
virtual void slot180();
virtual void slot184();
virtual void slot188();
virtual void slot18c();
virtual void slot190();
virtual void slot194();
virtual void slot198();
virtual void slot19c();
virtual void slot1a0();
virtual void slot1a4();
virtual void slot1a8();
virtual void slot1ac();
virtual void slot1b0();
virtual void slot1b4();
virtual void slot1b8();
virtual void slot1bc();
virtual void slot1c0();
virtual void slot1c4();
virtual void slot1c8();
virtual void slot1cc();
virtual int StateReady();
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
InventoryResolver53 resolver40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
int unk58;
int unk5c;
Process53* process60;
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
InventoryUpdate53 inventory8c;
};
class TESBoundObject : public TESForm {};
class Actor : public TESObjectREFR { public: bool FUN_004e84e0(TESForm*); const char* FUN_006f7c80(TESForm*,int,int); };

struct Process53 {
virtual void slot000();
virtual void slot004();
virtual void slot008();
virtual void slot00c();
virtual void slot010();
virtual void slot014();
virtual void slot018();
virtual void slot01c();
virtual void slot020();
virtual void slot024();
virtual void slot028();
virtual void slot02c();
virtual void slot030();
virtual void slot034();
virtual void slot038();
virtual void slot03c();
virtual void slot040();
virtual void slot044();
virtual void slot048();
virtual void slot04c();
virtual void slot050();
virtual void slot054();
virtual void slot058();
virtual void slot05c();
virtual void slot060();
virtual void slot064();
virtual void slot068();
virtual void slot06c();
virtual void slot070();
virtual void slot074();
virtual void slot078();
virtual void slot07c();
virtual void slot080();
virtual void slot084();
virtual void slot088();
virtual void slot08c();
virtual void slot090();
virtual void slot094();
virtual void slot098();
virtual void slot09c();
virtual void slot0a0();
virtual void slot0a4();
virtual void slot0a8();
virtual void slot0ac();
virtual void slot0b0();
virtual void slot0b4();
virtual void slot0b8();
virtual void slot0bc();
virtual void slot0c0();
virtual void Update(Actor*,int);
};
struct Extra53 {void ExtraDataList_SetCanNotWear(int);};
struct Container53 {Extra53* InventoryChanges_WearingObject(TESForm*,int);};
Container53* __cdecl FUN_0047e090(TESObjectREFR*);
bool __cdecl FUN_00517950(void*,void*,void*,TESObjectREFR*,void*,void*,void*,TESForm**,int*,int*);
void __cdecl Script_GetItemCountConditionFunction(TESObjectREFR*,TESForm*,int,double*);
const char* __cdecl TESFullName_GetFullName(TESForm*);
void __cdecl FUN_0061b850(const char*,int,const char*,const char*,float);
void __cdecl Interface_UpdateInventory();
extern Actor* DAT_0107a104;
extern const char* DAT_00f62da8;
extern const char* DAT_00f62d78;
extern const char DAT_00dc0c78[];
struct Heap53 {void* FUN_0086b930(unsigned int); void FUN_0086ba60(void*);};
extern Heap53 DAT_01090a78;
struct FUN_006c8220 {
 TESForm* m_item; FUN_006c8220* m_pkNext;
 FUN_006c8220():m_item(0),m_pkNext(0){}
 FUN_006c8220(TESForm*const& item):m_item(item),m_pkNext(0){}
 static void* operator new(unsigned int size) { return DAT_01090a78.FUN_0086b930(size); }
 __declspec(noinline) ~FUN_006c8220() { RemoveAll(); }
 void RemoveAll() {
  while (m_pkNext) {
   FUN_006c8220* next = m_pkNext->m_pkNext;
   m_pkNext->m_pkNext = 0;
   delete m_pkNext;
   m_pkNext = next;
  }
  m_item = 0;
 }
 static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
 __declspec(noinline) void FUN_0049fac0(TESForm*const& item) {
  if (!item)
   return;
  if (m_item) {
   FUN_006c8220* node = new FUN_006c8220(m_item);
   node->m_pkNext = m_pkNext;
   m_pkNext = node;
   m_item = item;
  }
  else
   m_item = item;
 }
 void AddHead(TESForm*const& item) { FUN_0049fac0(item); }
 bool IsEmpty() { return !m_pkNext && !m_item; }
 TESForm*& GetItem() { return m_item; }
 FUN_006c8220* GetNext() { return m_pkNext; }
 void RemoveHead() {
  if (m_pkNext) {
   FUN_006c8220* node = m_pkNext;
   m_pkNext = node->m_pkNext;
   m_item = node->m_item;
   node->m_pkNext = 0;
   delete node;
  }
  else
   m_item = 0;
 }
};
struct ListForm53 { int unk00,unk04,unk08,unk0c,unk10,unk14; FUN_006c8220 list; FUN_006c8220* GetList() { return &list; } };
inline unsigned char GetFormType53(TESForm* form) { return form->type; }
template<> __forceinline BSStringT<char>::BSStringT():pString(0),sLen(0),sMaxLen(0) {}
// pdb: Script::RemoveItemFunction | TESScriptFunctions.obj | fnv360_0822_retail, caller_sim, low
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
bool __cdecl FUN_0053a480(void* p1,void* p2,TESObjectREFR* thisObj,void* p4,void* p5,void* p6,double* result,void* p8) {
 TESForm* pRemoveForm=0;
 TESBoundObject* pObject=0;
 int iCount=0;
 int iNoMessage=0;
 if(!FUN_00517950(p1,p2,p8,thisObj,p4,p5,p6,&pRemoveForm,&iCount,&iNoMessage))
  return false;
 if(thisObj && pRemoveForm) {
  FUN_006c8220 itemList;
  if(pRemoveForm->IsBoundObject())
   pObject=(TESBoundObject*)pRemoveForm;
  if(GetFormType53(pRemoveForm)==0x34) {
   TESForm* pLevItem=pRemoveForm;
   if(pLevItem) {
    LeveledResolver53* pChanges=thisObj->resolver40.FUN_0040ab00();
    if(pChanges)
     pObject=(TESBoundObject*)pChanges->FUN_0047e910(pLevItem);
   }
  }
  if(pObject) {
   itemList.AddHead((TESForm*)pObject);
  }
  else if(GetFormType53(pRemoveForm)==0x55) {
   FUN_006c8220* pNode=reinterpret_cast<ListForm53*>(pRemoveForm)->GetList();
   while(pNode && !pNode->IsEmpty()) {
    TESForm* pListItem=pNode->GetItem();
    pNode=pNode->GetNext();
    if(pListItem->IsBoundObject())
     itemList.AddHead(pListItem);
   }
  }
  while(!itemList.IsEmpty()) {
   pObject=(TESBoundObject*)itemList.GetItem();
   itemList.RemoveHead();
   int iRemove=iCount;
   Actor* pActor=dynamic_cast<Actor*>(thisObj);
   if(pActor) {
    {
     double dRemove=iRemove;
     double dCount=dRemove;
     Script_GetItemCountConditionFunction(thisObj,pObject,0,&dCount);
     if(dCount<dRemove)
      iRemove=(int)dCount;
    }
    Extra53* pExtra=0;
    if(pActor->FUN_004e84e0(pObject)) {
     Container53* pContainer=FUN_0047e090(thisObj);
     if(pContainer) {
      pExtra=pContainer->InventoryChanges_WearingObject(pObject,0);
      if(pExtra)
       pExtra->ExtraDataList_SetCanNotWear(0);
     }
    }
    if(iRemove>0) {
     bool bEquipped=pActor->FUN_004e84e0(pObject);
     if(bEquipped)
      pActor->inventory8c.FUN_006b71f0(pObject,1);
     pActor->Remove(pObject,pExtra,iRemove,0,0,0,0,0,1,0);
     if(pActor==DAT_0107a104) {
      if(!iNoMessage) {
       BSStringT<char> sMessage;
       if(iRemove>1)
        sMessage.PrintfString("%i %s%s %s",iRemove,TESFullName_GetFullName(pObject),DAT_00f62d78,DAT_00f62da8);
       else
        sMessage.PrintfString("%s %s",TESFullName_GetFullName(pObject),DAT_00f62da8);
       switch(GetFormType53(pObject)) {
       case 0x19:case 0x1e:case 0x1f:case 0x28:case 0x29:case 0x2e:case 0x2f:case 0x32:
        FUN_0061b850(sMessage.pString,0,DAT_00dc0c78,iNoMessage ? 0:DAT_0107a104->FUN_006f7c80(pObject,0,0),2.0f);
        break;
       case 0x18:
        FUN_0061b850(sMessage.pString,0,DAT_00dc0c78,iNoMessage ? 0:DAT_0107a104->FUN_006f7c80(pObject,0,0),2.0f);
        break;
       }
      }
      Interface_UpdateInventory();
     }
     else if(bEquipped && pActor->process60 && pActor->StateReady()) {
      pActor->process60->Update(pActor,0);
     }
    }
   }
   else {
    thisObj->Remove(pObject,0,iRemove,0,0,0,0,0,1,0);
   }
  }
 }
 return true;
}
