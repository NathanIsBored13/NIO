#pragma once

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif // _WIN32

#define ASIO_STANDALONE

#pragma warning(push, 0)
#include <asio.hpp>
#pragma warning(pop)