#pragma once

#include <string>
#include <sstream>

template <class T>
std::string toString(const T& obj)
{
	std::stringstream ss;
	ss << obj;
	return ss.str();
}