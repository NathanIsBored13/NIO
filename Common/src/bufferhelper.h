#pragma once

#include "serialmessage.h"

namespace NIO::Common
{
	class BufferHelper
	{
	public:
		class Iterator
		{
		public:
			Iterator(uint8_t*);

			template <class T>
			T take()
			{
				T ret{ 0 };

				memcpy(&ret, m_ptr, sizeof(T));
				m_ptr += sizeof(T);

				return ret;
			}

			bool operator == (const Iterator&);
			bool operator != (const Iterator&);

			template <class T>
			operator T* ()
			{
				return (T*)m_ptr;
			}
		private:
			uint8_t* m_ptr;
		};

		BufferHelper(BufferPtr&, size_t);
		void append(const void*, size_t);
		Iterator begin();
		Iterator end();

		template <class T>
		BufferHelper& operator << (const T& r)
		{
			append(&r, sizeof(T));
			return *this;
		}
	private:
		BufferPtr& m_bufferptr;
		uint8_t* m_insertPtr;
		size_t m_size;
	};
}