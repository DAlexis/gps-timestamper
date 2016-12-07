/*
 * gps-data.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_GPS_DATA_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_GPS_DATA_HPP_

struct GPSData
{
	constexpr static int maxStrLen = 20;
	GPSData();
	char lat[maxStrLen];
	char lon[maxStrLen];
	char time[maxStrLen];
	void clear();
	bool hasData() const;
	operator bool() const;
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_GPS_DATA_HPP_ */
