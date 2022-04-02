#pragma once

#include "serialmessage.h"
#include "idispatcher.h"

#include <functional>
#include <unordered_map>

namespace NIO::Common
{
	template <class E>
	class ISendable
	{
	public:
		virtual SerialMessage<E> serialise() = 0;

		static void deserialise(SerialMessage<E>& msg)
		{
			m_dispatchers.at(msg.header.id)->dispatch(msg);
		}
	protected:
		static std::unordered_map<E, IDispatcher<E>*> m_dispatchers;
	};
}