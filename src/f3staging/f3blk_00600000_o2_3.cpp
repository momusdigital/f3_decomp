#include <math.h>
// src/f3staging/f3blk_00600000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x0061c8c0 (community match, verified in this file)
namespace f3m_0061c8c0 {
namespace N61C8C0 {struct Tile{float FUN_00becf40(unsigned);};struct Manager{bool enabled;
 int unknown04;
 int unknown08;
 int unknown0c;
 int unknown10;
 int unknown14;
 int unknown18;
 int unknown1c;
 int unknown20;
 int unknown24;
 int unknown28;
 int unknown2c;
 int unknown30;
 int unknown34;
 int unknown38;
 int unknown3c;
 int unknown40;
 int unknown44;
 int unknown48;
 int unknown4c;
 int unknown50;
 int unknown54;
 int unknown58;
 int unknown5c;
 int unknown60;
 int unknown64;
 int unknown68;
 int unknown6c;
 int unknown70;
 int unknown74;
 int unknown78;
 int unknown7c;
 int unknown80;
 int unknown84;
 int unknown88;
 int unknown8c;
 int unknown90;
 int unknown94;
 int unknown98;
 Tile*tile;void FUN_006210c0();};extern Manager*DAT_01075b24;void Interface_SetMapMenuVisible(int,int);void FUN_0061b370(int,int,int);void Interface_SetStatsMenuVisible(int,int);}
// pdb: Interface::ShowMenus | Interface.obj | fnv360_0822_retail, objrun, medium
void FUN_0061c8c0(){using namespace N61C8C0;if(N61C8C0::DAT_01075b24&&N61C8C0::DAT_01075b24->enabled){int mode=(int)N61C8C0::DAT_01075b24->tile->FUN_00becf40(0x1771);if(!mode){N61C8C0::DAT_01075b24->FUN_006210c0();mode=1003;}switch(mode){case 1023:Interface_SetMapMenuVisible(1,0);break;case 1002:case 1035:FUN_0061b370(1,0,1);break;case 1003:Interface_SetStatsMenuVisible(1,0);break;}}}
}   // namespace f3m_0061c8c0
