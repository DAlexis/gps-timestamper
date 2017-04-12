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
	oss << "{pos: " << m_pos.str()
			<< ", time_round: " << m_dt.str()
			<< ", time_frac: " << toString(float(m_signalDelay) / m_lastSecondPeriod)
			<< "}";
	return oss.str();
}
