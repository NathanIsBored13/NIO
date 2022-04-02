#pragma once

#include "bufferhelper.h"
#include "isendable.h"

#include <stdint.h>
#include <type_traits>

namespace NIO::Common
{
	template <class T, class E, const E V>
	class FlexibleSizeMessage : public ISendable<E>
	{

	public:
		virtual size_t calculateSize() = 0;
		virtual void serialise(BufferHelper&) = 0;

		SerialMessage<E> serialise() override
		{
			uint32_t messageSize = (uint32_t)calculateSize();
			SerialMessage<E> ret =
			{
				SerialMessage<E>::template MessageHeader
				{
					V,
					messageSize
				},
				BufferPtr(messageSize)
			};
			BufferHelper helper(ret.bufferptr, messageSize);
			serialise(helper);
			return ret;
		}

		static void registerMsgType(std::function<void(T)> callback)
		{
			ISendable<E>::m_dispatchers.insert(std::make_pair(V, new Dispatcher<E, T>(T::deserialise, callback)));
		}
	};
}