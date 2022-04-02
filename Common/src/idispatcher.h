#pragma once

#include "serialmessage.h"

namespace NIO::Common
{
	template <class E>
	class IDispatcher
	{
	public:
		virtual void dispatch(SerialMessage<E>&) = 0;
	};
}