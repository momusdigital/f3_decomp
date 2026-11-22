#include <windows.h>
#include <math.h>
#include <stdlib.h>
// src/f3staging/f3blk_00680000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0068ec30 (community match, verified in this file)
namespace f3m_0068ec30 {
namespace Buildec30 { struct Tile { void FUN_00bee190(int,float,int); }; struct Record {int unk00;int unk04;int unk08;int unk0c;int unk10;int unk14;int unk18;int unk1c;int unk20;int unk24;int unk28;int unk2c; Tile* tile; }; struct Node { Record* value; Node* next; }; struct Container { int unk00; int unk04; Node head; Node* Head() { return &head; } }; struct Arg { Container* list; }; extern const float DAT_00e070e0; extern Tile* __cdecl Tile_GetMenuByClass(int); extern Tile* __cdecl FUN_00beb8c0(Tile*,const char*); extern const char DAT_00e08b08[], DAT_00e08af4[]; struct Menu { Tile* Menu_RenderTemplate(Tile*,const char*,int); }; extern Menu* DAT_01077448;
// pdb: VATSMenu::BuildMetersForTarget | VATSMenu.obj | fnv360_0822_retail, ustr, medium
// pdb params: apTarget
void __stdcall FUN_0068ec30(Arg* arg) { Tile* parent=FUN_00beb8c0(Tile_GetMenuByClass(0x420),DAT_00e08b08); for(Node* node=arg->list->Head();node;node=node->next) { if(!node->next && !node->value) break; node->value->tile=DAT_01077448->Menu_RenderTemplate(parent,DAT_00e08af4,0); Record* record=node->value; if(record->tile) { switch(record->unk20) { case 0: record->tile->FUN_00bee190(0xfb7,DAT_00e070e0,1); break; case -1: case 1: case 2: case 13: record->tile->FUN_00bee190(0xfb7,5.0f,1); break; case 3: case 4: case 7: case 8: case 9: case 14: record->tile->FUN_00bee190(0xfb7,1.0f,1); break; case 5: case 6: case 10: case 11: case 12: record->tile->FUN_00bee190(0xfb7,4.0f,1); break; default: continue; } } } } }
}   // namespace f3m_0068ec30
