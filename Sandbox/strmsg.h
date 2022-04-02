#pragma once

#include "Client/include.h"
#include "messagetypes.h"

#include <string>

class strMsg : public NIO::Common::FlexibleSizeMessage<strMsg, MessageTypes, MessageTypes::SendString>
{
public:
	strMsg(std::string str);
	size_t calculateSize() override;
	using NIO::Common::FlexibleSizeMessage<strMsg, MessageTypes, MessageTypes::SendString>::serialise;
	void serialise(NIO::Common::BufferHelper&) override;
	static strMsg deserialise(NIO::Common::SerialMessage<MessageTypes>&);
	std::string& getValue();
private:
	std::string m_str;
};
