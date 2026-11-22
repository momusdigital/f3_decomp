#include <new>
// src/f3staging/f3iso_008ea270_o2.cpp - Fallout 3 ISOLATED unit (20 Nov 2026) for 0x008ea270 alone: its verified match did not fit its
// original file. Make the match self-contained here (own types and helpers). Not a real source path.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x008ea270 (community match, verified in this file)
namespace f3m_008ea270 {
struct __declspec(align(16)) Vec { float x,y,z,w; void hkVector4_setRotatedDir(const void*,const void*); };
struct Proxy { void hkpCharacterProxy_setPosition(const Vec*); };
struct Body { char pad[8]; char* frame; };
struct Motion { char p0[8]; Proxy* proxy; char pC[0x400-12]; char direction[0x24]; Body* body;
    void FUN_0092ac40(); void bhkCharacterController_SetPosition(const Vec*);
};
// pdb: bhkCharacterController::SetPosition | bhkCharacterController.obj | fnv360_0822_retail, call_seq + bridge(call_gap|objrun), high
void Motion::bhkCharacterController_SetPosition(const Vec* value) {
    char* frame=body?body->frame:0;
    Vec rotated; rotated.hkVector4_setRotatedDir(frame+0xa0,direction);
    Vec sum; sum.x=value->x+rotated.x;sum.y=value->y+rotated.y;sum.z=value->z+rotated.z;sum.w=value->w+rotated.w;
    Proxy* p=proxy;
    if(p) FUN_0092ac40();
    p->hkpCharacterProxy_setPosition(&sum);
    FUN_0092ac40();
}
}   // namespace f3m_008ea270
