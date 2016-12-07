#ifndef HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_
#define HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_

#include "gps-data.hpp"

class NMEAParser
{
public:
	void parse(const char* str);
	const GPSData& result() const;

private:
	GPSData m_result;
};


#endif /* HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_ */
