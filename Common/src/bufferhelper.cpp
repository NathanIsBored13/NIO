#include "pch.h"
#include "bufferhelper.h"

#include <cassert>

namespace NIO::Common
{
	BufferHelper::Iterator::Iterator(uint8_t* ptr) :
		m_ptr(ptr)
	{ }

	bool BufferHelper::Iterator::operator == (const Iterator& other)
	{
		return m_ptr == other.m_ptr;
	}

	bool BufferHelper::Iterator::operator != (const Iterator& other)
	{
		return m_ptr == other.m_ptr;
	}

	BufferHelper::BufferHelper(BufferPtr& buffer, size_t size) :
		m_bufferptr(buffer),
		m_insertPtr((uint8_t*)buffer),
		m_size(size)
	{ }

	void BufferHelper::append(const void* data, size_t size)
	{
		assert(m_insertPtr - (uint8_t*)m_bufferptr + size <= m_size);

		memcpy(m_insertPtr, data, size);
		m_insertPtr += size;
	}

	BufferHelper::Iterator BufferHelper::begin()
	{
		return Iterator((uint8_t*)m_bufferptr);
	}

	BufferHelper::Iterator BufferHelper::end()
	{
		return Iterator((uint8_t*)m_bufferptr + m_size);
	}
}