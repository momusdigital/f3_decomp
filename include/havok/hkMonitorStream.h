// include/havok/hkMonitorStream.h - the per-thread monitor stream and the timer macros that write to it
// (Common/Base/Monitor/hkMonitorStream.h). Layouts are the New Vegas Xbox 360 PDB's: hkMonitorStream { m_start,
// m_end, m_capacity, m_capacityMinus16 (hkPadSpu<char*>), m_isBufferAllocatedOnTheHeap }, Command
// { m_commandAndMonitor }, TimerCommand { m_time0, m_time1 }, AddValueCommand { m_value }, TimerBeginListCommand
// { m_nameOfFirstSplit }. The stream instance is the global hkMonitorStream__m_instance, a
// hkThreadLocalData<hkMonitorStream*> (Battlefield 3 PC PDB). The header needs no other Havok type, so units that still
// carry their own copies of the base types can include it: hkBool members and results are spelled as the byte they are.
#ifndef HAVOK_HKMONITORSTREAM_H
#define HAVOK_HKMONITORSTREAM_H

#include "havok/hkPadSpu.h"
#include "havok/hkThreadLocalData.h"

#ifndef HK_NULL
#define HK_NULL 0
#endif

class hkMonitorStream;
extern hkThreadLocalData<hkMonitorStream*> hkMonitorStream__m_instance;

class hkMonitorStream
{
	public:

		static hkMonitorStream& getInstance()
		{
			return *hkMonitorStream__m_instance.getData();
		}

		__forceinline char* getStart() { return m_start.val(); }
		__forceinline char* getEnd() { return m_end.val(); }
		__forceinline char* getCapacityMinus16() { return m_capacityMinus16.val(); }
		__forceinline char* getCapacity() { return m_capacity.val(); }

		__forceinline char memoryAvailable()
		{
			return getEnd() < getCapacityMinus16();
		}

		__forceinline void setEnd(char* ptr) { m_end = ptr; }

	public:

		hkPadSpu<char*> m_start;
		hkPadSpu<char*> m_end;
		hkPadSpu<char*> m_capacity;
		hkPadSpu<char*> m_capacityMinus16;
		char m_isBufferAllocatedOnTheHeap;  // hkBool

	public:

		struct Command
		{
			const char* m_commandAndMonitor;
		};

		struct AddValueCommand : public Command
		{
			float m_value;
		};

		struct TimerCommand : public Command
		{
			unsigned int m_time0;
			unsigned int m_time1;

			__forceinline void setTime();
		};

		struct TimerBeginListCommand : public TimerCommand
		{
			const char* m_nameOfFirstSplit;
		};
};

// RULE-EXCEPTION: R18, Havok's own setTime reads the time stamp counter in an __asm block: Battlefield 3's
// out-of-line copy (hkMonitorStream::TimerCommand::setTime, hkmonitorstream.inl line 52, PDB) is
// "rdtsc; mov [esp], eax; mov eax, [esp]; mov [ecx+4], eax", the store and reload through a local that
// __asm { mov ticks, eax } gives and __rdtsc() does not; every inlined copy in Fallout 3 has the same round trip.
void hkMonitorStream::TimerCommand::setTime()
{
	unsigned int ticks;
	__asm {
		rdtsc
		mov dword ptr[ticks], eax
	}
	m_time0 = ticks;
}

#define HK_MONITOR_TYPE_TIMER "t"
#define HK_MONITOR_TYPE_INT "i"
#define HK_MONITOR_TYPE_SINGLE "f"

#define HK_MONITOR_TIMER_COMMAND(COMMAND, NAME) \
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); \
	  if ( mStream.memoryAvailable() ) \
	  { hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); \
	    h->m_commandAndMonitor = COMMAND HK_MONITOR_TYPE_TIMER NAME; \
	    h->setTime(); \
	    mStream.setEnd( (char*)(h+1) ); } }

#define HK_TIMER_BEGIN(NAME, OBJECT) HK_MONITOR_TIMER_COMMAND("T", NAME)
#define HK_TIMER_END() HK_MONITOR_TIMER_COMMAND("E", "")
#define HK_TIMER_SPLIT_LIST(NAME) HK_MONITOR_TIMER_COMMAND("S", NAME)
#define HK_TIMER_END_LIST() HK_MONITOR_TIMER_COMMAND("l", "")

#define HK_TIMER_BEGIN_LIST(NAME, FIRST_SPLIT) \
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); \
	  if ( mStream.memoryAvailable() ) \
	  { hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); \
	    h->m_commandAndMonitor = "L" HK_MONITOR_TYPE_TIMER NAME; \
	    h->m_nameOfFirstSplit = "S" HK_MONITOR_TYPE_TIMER FIRST_SPLIT; \
	    h->setTime(); \
	    mStream.setEnd( (char*)(h+1) ); } }

#define HK_MONITOR_ADD_VALUE(NAME, VALUE, MONITOR_TYPE) \
	{ hkMonitorStream& mStream = hkMonitorStream::getInstance(); \
	  if ( mStream.memoryAvailable() ) \
	  { hkMonitorStream::AddValueCommand* h = reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd()); \
	    h->m_commandAndMonitor = "M" MONITOR_TYPE NAME; \
	    h->m_value = VALUE; \
	    mStream.setEnd( (char*)(h+1) ); } }

#endif
