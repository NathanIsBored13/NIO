#include "pch.h"
#include "bufferptr.h"

#include <cassert>

namespace NIO::Common
{
	BufferPtr::BufferPtr(void* data) :
		m_data(data),
		m_hasLifetimeControl(false)
	{ }

	BufferPtr::BufferPtr(size_t size) :
		m_data(malloc(size)),
		m_hasLifetimeControl(true)
	{
		assert(m_data);
	}

	BufferPtr::BufferPtr(BufferPtr&& other) noexcept :
		m_data(other.m_data),
		m_hasLifetimeControl(other.m_hasLifetimeControl)
	{
		other.m_data = nullptr;
	}

	BufferPtr::~BufferPtr()
	{
		if (m_hasLifetimeControl)
		{
			free(m_data);
		}
	}
}