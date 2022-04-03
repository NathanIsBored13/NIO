#pragma once

#include "messagetypes.h"

#include "Client/include.h"

struct intMsg : public NIO::Common::FixedSizeMessage<intMsg, MessageTypes, MessageTypes::SendInt>
{
	int value{ 0 };
	intMsg(int value) :
		value(value)
	{ }
};