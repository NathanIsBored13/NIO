#include "strmsg.h"

strMsg::strMsg(std::string str) :
	m_str(str)
{ }

size_t strMsg::calculateSize()
{
	return m_str.size() + 1;
}

void strMsg::serialise(NIO::Common::BufferHelper& helper)
{
	helper.append(m_str.c_str(), m_str.size() + 1);
}

strMsg strMsg::deserialise(NIO::Common::SerialMessage<MessageTypes>& msg)
{
	return strMsg(std::string ((char*)msg.bufferptr));
}

std::string& strMsg::getValue()
{
	return m_str;
}