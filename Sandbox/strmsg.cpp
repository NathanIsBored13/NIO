#include "strmsg.h"

strMsg::strMsg(std::string str) :
	m_str(str)
{ }

size_t strMsg::calculateSize()
{
	return sizeof(uint32_t) + m_str.size();
}

void strMsg::serialise(NIO::Common::BufferHelper& helper)
{
	helper << (uint32_t)m_str.size();
	helper.append((void*)m_str.c_str(), m_str.size());
}
