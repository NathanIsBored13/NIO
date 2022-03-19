#pragma once

#include "isendable.h"

#include <vector>

namespace NIO::Common
{
	template <class E, const E V>
	class MessageBuilder : ISendable<E>
	{
	public:
		MessageBuilder(size_t reserve = 0)
			: m_data(std::vector<uint8_t>(reserve))
		{

		}

		SerialMessage<E> serialise() override
		{
			SerialMessage<E> ret =
			{
				SerialMessage<E>::template MessageHeadder
				{
					V,
					m_data.size()
				},
				BufferPtr(m_data.size())
			};
			memcpy(ret.bufferptr, m_data.data(), m_data.size());
		}
	private:
		std::vector<uint8_t> m_data;
	};
}