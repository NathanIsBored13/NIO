#pragma once

#include<cstdint>

enum class MessageTypes : uint32_t
{
    SendInt,
    SendString
};