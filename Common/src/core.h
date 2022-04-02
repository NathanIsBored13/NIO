#pragma once

namespace NIO::Common
{
	#define NIO_COMMON_IMPLEXTERNS(T) template <> \
		std::unordered_map<T, NIO::Common::IDispatcher<T>*> NIO::Common::ISendable<T>::m_dispatchers = std::unordered_map<T, NIO::Common::IDispatcher<T>*>();
}