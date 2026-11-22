// include/havok/hkThreadLocalData.h - per-thread data through a Win32 TLS slot
// (Common/Base/Thread/Thread/Win32/hkWin32ThreadLocalData.h; the class layout is the New Vegas Xbox 360 PDB's and
// the Battlefield 3 PC PDB's, hkThreadLocalData<T> { unsigned long m_slotID; }).
#ifndef HAVOK_HKTHREADLOCALDATA_H
#define HAVOK_HKTHREADLOCALDATA_H

extern "C" __declspec(dllimport) unsigned long __stdcall TlsAlloc(void);
extern "C" __declspec(dllimport) int __stdcall TlsFree(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* lpTlsValue);

template <typename T>
class hkThreadLocalData
{
	public:

		hkThreadLocalData() { m_slotID = TlsAlloc(); }
		~hkThreadLocalData() { TlsFree(m_slotID); }

		__forceinline T getData() const
		{
			return (T)(unsigned long)TlsGetValue(m_slotID);
		}

		__forceinline void setData(T p)
		{
			unsigned long v = (unsigned long)(p);
			TlsSetValue(m_slotID, (void*)v);
		}

		unsigned long m_slotID;
};

#endif
