// include/havok/hkPadSpu.h - a value padded to 16 bytes on the SPU; on the PC a plain wrapper
// (Common/Base/Types/hkBaseTypes.h).
#ifndef HAVOK_HKPADSPU_H
#define HAVOK_HKPADSPU_H

template <typename TYPE>
class hkPadSpu
{
	public:

		__forceinline hkPadSpu() {}

		__forceinline hkPadSpu(TYPE e)
			: m_storage(e)
		{
		}

		__forceinline void operator=(TYPE e)
		{
			m_storage = e;
		}

		__forceinline TYPE val() const
		{
			return m_storage;
		}

		__forceinline TYPE operator->() const
		{
			return m_storage;
		}

		__forceinline operator TYPE() const
		{
			return val();
		}

	private:

		TYPE m_storage;
};

#endif
