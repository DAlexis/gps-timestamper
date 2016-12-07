/*
 * gps-data.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "gps-data.hpp"

GPSData::GPSData()
{
	clear();
}

void GPSData::clear()
{
	lat[0] = '\0';
	lon[0] = '\0';
	time[0] = '\0';
}

bool GPSData::hasData() const
{
	return (lat[0] != '\0');
}

GPSData::operator bool() const
{
	return hasData();
}
