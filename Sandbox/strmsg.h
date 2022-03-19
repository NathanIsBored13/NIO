#pragma once

#include "Client/include.h"
#include "messagetypes.h"

class strMsg : public NIO::Common::FlexibleSizeMessage<MessageTypes, MessageTypes::SendString>
{
public:
	strMsg(std::string str);

	size_t calculateSize() override;
	void serialise(NIO::Common::BufferHelper&) override;
private:
	std::string m_str;
};
