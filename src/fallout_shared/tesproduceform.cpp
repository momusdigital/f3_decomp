#include "f3_common.h"
// src/fallout_shared/tesproduceform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesproduceform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Copies 4 bytes from src into this object at offset 8 when src is non-null.
// @f3 0x00bb0380 (community match, verified in this file)
namespace f3m_00bb0380 {
struct Elem_00bb0380 {
    int unk00, unk04, unk08, unk0c;
    void FUN_00bafc60(int value);
};

void __cdecl FUN_00bb0380(Elem_00bb0380* first, Elem_00bb0380* last, int value) {
    for (; first != last; ++first)
        first->FUN_00bafc60(value);
}
}   // namespace f3m_00bb0380


struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};

struct ProduceFormData : BaseFormComponent
{
    void* pIngredient;
    unsigned char cProdChance[4];
    bool FUN_0048b6a0(BaseFormComponent* apOther);
};

struct TESFile;

struct FUN_00485b60_Cls
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    TESFile* GetFile(int aIndex);
    int HasNameForWarning();
    unsigned int Deallocate();
};

struct TESForm;

struct TESForm
{
    virtual ~TESForm();
};

struct FUN_0048b720_Cls : ProduceFormData
{
    void ResolveIngredient(FUN_00485b60_Cls* apArg);
};

// Resolves pIngredient's form ID through the file, re-looks it up as an IngredientItem, and warns if the lookup fails.
// @f3 0x00452510 (community match, verified in this file)
struct TESBoundObject {
    virtual ~TESBoundObject();
};

struct FUN_00485b60_Stub {
    void* vftable;
    int unk04;
    int unk08;
    unsigned int unk0C;

    TESFile* TESForm_GetFile(int aIndex);
    int TESForm_GetFormEditorIDLength();
};

struct FUN_0048b720_Stub {
    void* unk00;
    void* unk04;
    void* unk08;
};

struct FUN_00408ec0_Obj {
    void FUN_00408ec0(FUN_00485b60_Cls* apArg);
};

void TESForm_AddCompileIndex(unsigned int* apFormID, TESFile* apFile);
TESForm* TESForm_GetFormByNumericID(unsigned int aFormID);
void FUN_00887da0(const char* apMsg, ...);

extern const char DAT_00dbcb38[];
extern const char DAT_00dbcae8[];
extern const char DAT_00dbcaa0[];

// pdb: ContainerObject::InitItem | TESContainer.obj | fnv360_0822_retail, ustr, medium
// pdb params: apOwner
void FUN_0048b720_Cls::ResolveIngredient(FUN_00485b60_Cls* apArg)
{
    unsigned int formID = (unsigned int)pIngredient;
    TESForm_AddCompileIndex(&formID, apArg->GetFile(-1));

    pIngredient = dynamic_cast<TESBoundObject*>(TESForm_GetFormByNumericID(formID));

    if (pIngredient == 0) {
        if (apArg != 0) {
            FUN_00485b60_Stub* owner =
                reinterpret_cast<FUN_00485b60_Stub*>(apArg);

            if (owner->TESForm_GetFormEditorIDLength()) {
                FUN_00887da0(
                    DAT_00dbcb38,
                    formID,
                    apArg->v76());
            } else {
                FUN_00887da0(
                    DAT_00dbcae8,
                    formID,
                    owner->unk0C);
            }
        } else {
            FUN_00887da0(
                DAT_00dbcaa0,
                formID);
        }
    }

    FUN_0048b720_Stub* self =
        reinterpret_cast<FUN_0048b720_Stub*>(this);

    if (self->unk08 != 0) {
        reinterpret_cast<FUN_00408ec0_Obj*>(self->unk08)->FUN_00408ec0(apArg);
    }
}

