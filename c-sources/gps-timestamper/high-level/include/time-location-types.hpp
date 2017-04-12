/*
 * date-time.hpp
 *
 *  Created on: 11 апр. 2017 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_TYPES_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_TYPES_HPP_

#include <ctime>
#include <string>
#include <cstdint>

class DateTime
{
public:
	DateTime();

	std::string str() const;

	bool set(uint16_t year, uint16_t month, uint16_t day, uint8_t hour, uint8_t min, uint8_t sec);

	/**
	 * Add some seconds to date and time
	 */
	DateTime operator+(double seconds);

	/**
	 * Add one second to date and time
	 */
	DateTime& operator++(int);

private:
	std::time_t m_t = 0;
};

class Position
{
public:
	bool set(float lat, char NS, float lon, char WE);

	std::string str() const;

	float lat = 0.0;
	float lon = 0.0;
private:
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_TIME_LOCATION_TYPES_HPP_ */
