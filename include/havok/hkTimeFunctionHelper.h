// include/havok/hkTimeFunctionHelper.h - HK_TIME_CODE_BLOCK: a timer that ends where its scope does
// (Common/Base/Monitor/hkMonitorStream.h in the SDK). Kept apart from hkMonitorStream.h because declaring the helper
// in a unit that does not use it moves an instruction in hkpSimulation (0x0097f810) under Visual C++ 2005.
#ifndef HAVOK_HKTIMEFUNCTIONHELPER_H
#define HAVOK_HKTIMEFUNCTIONHELPER_H

#include "havok/hkMonitorStream.h"

// Ends the timer its scope began with HK_TIME_CODE_BLOCK.
class hkTimeFunctionHelper
{
	public:

		__forceinline ~hkTimeFunctionHelper() { HK_TIMER_END(); }
};

#define HK_PREPROCESSOR_JOIN_TOKEN(A, B) HK_PREPROCESSOR_JOIN_TOKEN2(A, B)
#define HK_PREPROCESSOR_JOIN_TOKEN2(A, B) A##B
#define HK_TIME_CODE_BLOCK(NAME, OBJECT) HK_TIMER_BEGIN(NAME, OBJECT); hkTimeFunctionHelper HK_PREPROCESSOR_JOIN_TOKEN(timeblock, __LINE__)

#endif
