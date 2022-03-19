#pragma once

namespace NIO::Common
{
	class BufferPtr
	{
	public:
		BufferPtr(void*);
		BufferPtr(size_t);
		BufferPtr(const BufferPtr&) = delete;
		BufferPtr(BufferPtr&&) noexcept;
		~BufferPtr();
		template <class T>
		operator T* ()
		{
			return (T*)m_data;
		}
	private:
		void* m_data;
		bool m_hasLifetimeControl;
	};
}