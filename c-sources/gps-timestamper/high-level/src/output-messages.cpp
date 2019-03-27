#include "output-messages.hpp"
#include "string-utils.hpp"

#include <sstream>

using namespace std;

OutputDebug::OutputDebug(const std::string& msg) :
		m_msg(msg)
{
}

std::string OutputDebug::str() const
{
	ostringstream oss;
	oss << "{event: \"debug\", msg: \""
			<< m_msg
			<< "\"}";
	return oss.str();
}

std::string OutputQueueOverflow::str() const
{
	return std::string("{event: \"queue-overflow\"}");
}

/// @todo add messages for debug and for GPS disconnect
