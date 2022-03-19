#pragma once

#include "isendable.h"

namespace NIO::Common
{
	template <class T, class E, const E V>
	struct FixedSizeMessage : public ISendable<E>
	{
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
	};
}