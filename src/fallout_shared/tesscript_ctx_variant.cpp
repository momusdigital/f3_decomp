#include "f3_common.h"
// tesscript_ctx_variant.cpp: context variant of src/fallout_shared/tesscript.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesscript_decls.h"

class ScriptLoader : public Script
{
  public:
    bool FUN_005ab9f0(TESFile* file);
};

// @f3 0x00519300 (community match, verified in this file)
#include <malloc.h>
#include <string.h>
namespace Task2037 {
extern const char DAT_00dd4034[];
struct Heap{void* FUN_0086b930(unsigned);void FUN_0086ba60(void*);};extern Heap DAT_01090a78;
struct File {int unk000;int unk004;int unk008;int unk00c;int unk010;int unk014;int unk018;int unk01c;char filename[0x23c];unsigned chunkSize;int unk260;int unk264;int unk268;int unk26c;int unk270;int unk274;int unk278;int unk27c;int unk280;int unk284;int unk288;int unk28c;int unk290;int unk294;char unk298;bool endian;
int TESFile_GetTESForm();int TESFile_GetTESChunk();bool TESFile_NextChunk();void FUN_00447d60(void*,unsigned);void FUN_00448800(void*);
unsigned GetChunkSize(){return chunkSize;}bool IsEndianConversionRequired(){return endian;}const char* GetFilename(){return filename;}
void Read(void* p,unsigned n){FUN_00447d60(p,n);}void Read(void* p){FUN_00448800(p);}
};
struct Name{char* text;unsigned short len,cap;void FUN_004019c0(const char*,unsigned);};
struct FUN_005413d0{int unk000;int unk004;int unk008;int unk00c;int unk010;int unk014;Name name;FUN_005413d0();void FUN_00541380(File*);static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}};
struct Reference{Name name;void* pForm;unsigned m_uiFormID;Reference(){name.text=0;name.len=0;name.cap=0;pForm=0;m_uiFormID=0;}static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}static void operator delete(void* p){DAT_01090a78.FUN_0086ba60(p);}};
template<class T>struct List{
 T item;List* next;
 List(const T& value):item(value),next(0){}
 static void* operator new(unsigned n){return DAT_01090a78.FUN_0086b930(n);}
 __declspec(noinline) void FUN_0061c430(T const& value){
  if(!value)return;
  List* tail=this;
  while(tail->next)tail=tail->next;
  if(tail->item)tail->next=new List(value);
  else tail->item=value;
 }
};
struct Header{int unk000;int unk004;int unk008;int unk00c;int unk010;void FUN_00409db0();};
struct Owner{
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
virtual void ReadBounds(File*);
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
virtual const char* GetName();
virtual bool SetID(const char*);
int unk004;int unk008;int unk00c;int unk010;int unk014;Header header;char* source;char* data;int unk034;int unk038;int unk03c;int unk040;List<Reference*> references;List<FUN_005413d0*> variables;void FUN_00454410(File*);
};
inline char* AllocateZeroed(unsigned count,unsigned size){unsigned bytes=count*size;char* p=(char*)DAT_01090a78.FUN_0086b930(bytes);memset(p,0,bytes);return p;}
void __cdecl FUN_00887da0(const char*,...);
}
// @fnv 0x005ab9f0
// pdb: Script::Load | TESScript.obj | fnv360_0822_retail, vtable, medium
// pdb params: pFile
bool ScriptLoader::FUN_005ab9f0(TESFile* originalFile)
{
    using namespace Task2037;
    File* file=(File*)originalFile;
    FUN_005413d0* chunk = 0;
    unsigned int reference;
    char* variable;
    int size;
    char* variableName;
    unsigned int unusedID;
    unsigned int editorID;

    Reference* referenceID;
    if (file->TESFile_GetTESForm() != 0x11)
        return false;
    ((Owner*)this)->FUN_00454410(file);
    while (size = file->TESFile_GetTESChunk())
    {
        switch (size)
        {
        case 0x44494445:
            variable = (char*)_alloca(file->GetChunkSize());
            file->Read(variable, 0x200);
            ((Owner*)this)->SetID(variable);
            break;
        case 0x444e424f:
            ((Owner*)this)->ReadBounds(file);
            break;
        case 0x52484353:
            file->Read(&((Owner*)this)->header, 0);
            if (file->IsEndianConversionRequired())
                ((Owner*)this)->header.FUN_00409db0();
            break;
        case 0x44534c53:
            chunk = new FUN_005413d0;
            chunk->FUN_00541380(file);
            ((Owner*)this)->variables.FUN_0061c430(chunk);
            break;
        case 0x52564353:
            if (chunk)
            {
                variableName = (char*)_alloca(file->GetChunkSize());
                file->Read(variableName, 0x200);
                chunk->name.FUN_004019c0(variableName, 0);
            }
            break;
        case 0x41444353:
            reference = file->GetChunkSize();
            ((Owner*)this)->data = Task2037::AllocateZeroed(1, reference);
            memset(((Owner*)this)->data, 0, reference);
            file->Read(((Owner*)this)->data, 0);
            break;
        case 0x4f524353:
        case 0x56524353:
        {
            Reference* value = new Reference;
            referenceID=value;
            file->Read(&unusedID);
            if (size == 0x4f524353)
                value->pForm = (void*)unusedID;
            else
                value->m_uiFormID = unusedID;
            ((Owner*)this)->references.FUN_0061c430(referenceID);
            break;
        }
        case 0x54584353:
            break;
        case 0x44484353:
            break;
        case 0x4d414e52:
            file->Read(&editorID);
        }
        if (!file->TESFile_NextChunk())
            break;
    }
    if (!((Owner*)this)->data)
        FUN_00887da0(DAT_00dd4034, ((Owner*)this)->GetName(), file->GetFilename());
    return true;
}

