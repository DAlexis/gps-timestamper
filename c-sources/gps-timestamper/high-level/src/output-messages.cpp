#include "output-messages.hpp"
#include "string-utils.hpp"

#include <sstream>

using namespace std;

OutputRegisteredImpulse::OutputRegisteredImpulse(
	const Position& pos,
	const DateTime& dt,
	uint32_t lastSecondPeriod,
	uint32_t signalDelay
) :
	m_pos(pos),
	m_dt(dt),
	m_lastSecondPeriod(lastSecondPeriod),
	m_signalDelay(signalDelay)
{

}

std::string OutputRegisteredImpulse::str() const
{
	ostringstream oss;
	oss << "{event: \"pulse\", "
			<< "pos: " << m_pos.str()
			<< ", time_round: " << m_dt.str()
			<< ", time_frac: " << toString(float(m_signalDelay) / m_lastSecondPeriod)
			<< "}";
	return oss.str();
}

OutputPPS::OutputPPS(const Position& pos, const DateTime& dt) :
		m_pos(pos), m_dt(dt)
{

}

std::string OutputPPS::str() const
{
	ostringstream oss;
	oss << "{event: \"PPS\", "
		<< "pos: " << m_pos.str()
		<< ", time_round: " << m_dt.str()
		<< "}";
	return oss.str();
}

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

std::string OutputGPSDisconnect::str() const
{
	return std::string("{event: \"GPS-disconnect\"}");
}

std::string OutputQueueOverflow::str() const
{
	return std::string("{event: \"queue-overflow\"}");
}

/// @todo add messages for debug and for GPS disconnect
