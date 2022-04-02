#pragma once

#include "idispatcher.h"

#include <functional>

namespace NIO::Common
{
	template <class E, class T>
	class Dispatcher : public IDispatcher<E>
	{
	public:
		Dispatcher(std::function<T(SerialMessage<E>&)> creator, std::function<void(T)> callback) :
			m_creator(creator),
			m_callback(callback)
		{ }

		void dispatch(SerialMessage<E>& msg) override
		{
			m_callback(m_creator(msg));
		}
	private:
		std::function<T(SerialMessage<E>&)> m_creator;
		std::function<void(T)> m_callback;
	};
}