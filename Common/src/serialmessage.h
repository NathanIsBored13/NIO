#pragma once

#include "bufferptr.h"

namespace NIO::Common
{
	template <class E>
	struct SerialMessage
	{
		static_assert(std::is_enum<E>::value, "Template parameter must be enum class");
		static_assert(!std::is_convertible<E, std::underlying_type<E>::type>::value, "Template parameter must be enum class");
		static_assert(std::is_same<std::underlying_type<E>::type, uint32_t>::value, "Template parameter underlying type must be uint32_t");

		struct MessageHeader
		{
			E id;
			uint32_t size;
		};

		MessageHeader header;
		BufferPtr bufferptr;
	};
}