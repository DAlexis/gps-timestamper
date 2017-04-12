#ifndef HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_
#define HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_

#include <time-location-types.hpp>
#include "gps-data.hpp"
#include <string>

class NMEAParser
{
public:
	static bool parse(const char* str, Position& p, DateTime& t);
	void parse(const char* str);
	const GPSData& result() const;

private:
	static bool parseTime(const std::string& str, uint8_t& h, uint8_t& m, uint8_t& s);
	static bool parseCoordinate(const std::string& str, float& coord);
	static bool parseDate(const std::string& str, uint16_t& year, uint16_t& month, uint16_t& day);
	GPSData m_result;
};


#endif /* HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_ */
