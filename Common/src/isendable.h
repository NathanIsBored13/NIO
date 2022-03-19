#pragma once

#include "serialmessage.h"

namespace NIO::Common
{
	template <class E>
	struct ISendable
	{
		virtual SerialMessage<E> serialise() = 0;
	};
}