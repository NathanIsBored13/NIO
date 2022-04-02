#pragma once

#include "dispatcher.h"
#include "isendable.h"

#include <cassert>

namespace NIO::Common
{
	template <class T, class E, const E V>
	class FixedSizeMessage : public ISendable<E>
	{
	public:
		SerialMessage<E> serialise() override
		{
			return SerialMessage<E>
			{
				SerialMessage<E>::template MessageHeader
				{
					V,
					sizeof(T)
				},
				this
			};
		}

		static T deserialise(SerialMessage<E>& msg)
		{
			T ret{ 0 };
			assert(msg.header.size == sizeof(T));
			memcpy(&ret, msg.bufferptr, sizeof(T));
			return ret;
		}

		static void registerMsgType(std::function<void(T)> callback)
		{
			ISendable<E>::m_dispatchers.insert(std::make_pair(V, new Dispatcher<E, T>(deserialise, callback)));
		}
	};
}