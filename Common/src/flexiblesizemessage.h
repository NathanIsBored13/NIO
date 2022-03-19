#pragma once

#include "bufferhelper.h"
#include "isendable.h"

namespace NIO::Common
{
	template <class E, const E V>
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
	};
}