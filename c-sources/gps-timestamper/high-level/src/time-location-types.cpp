#include "time-location-types.hpp"
#include "string-utils.hpp"

#include <cstring>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

DateTime::DateTime()
{
	set(1900, 1, 1, 00, 00, 01);
}

std::string DateTime::str() const
{
	ostringstream oss;
	std::tm dateTime;
	localtime_r(&m_t, &dateTime);
	oss << dateTime.tm_year + 1900 << "-"
			<< setfill('0') << setw(2)
			<< dateTime.tm_mon << "-"
			<< setw(2)
			<< dateTime.tm_mday << " "
			<< setw(2)
			<< dateTime.tm_hour << ":"
			<< setw(2)
			<< dateTime.tm_min << ":"
			<< setw(2)
			<< dateTime.tm_sec;
	return oss.str();
}

bool DateTime::set(uint16_t year, uint16_t month, uint16_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
	std::tm dateTime;
	std::memset(&dateTime, 0, sizeof(dateTime));
	dateTime.tm_sec = sec;      // Seconds.	[0-60] (1 leap second)
	dateTime.tm_min = min;		// Minutes.	[0-59]
	dateTime.tm_hour = hour;	// Hours.	[0-23]
	dateTime.tm_mday = day;		// Day.		[1-31]
	dateTime.tm_mon = month;	// Month.	[0-11]
	dateTime.tm_year = year-1900;	// Year	- 1900.
	m_t = std::mktime(&dateTime);
	return true;
}

DateTime DateTime::operator+(double seconds)
{
	DateTime result;
	result.m_t = m_t + seconds;
	return result;
}

DateTime& DateTime::operator++(int)
{
	m_t++;
	return *this;
}

///////////////////////////////////////
// Position
bool Position::set(float lat, char NS, float lon, char WE)
{
	switch(NS)
	{
	case 'N': this->lat = lat; break;
	case 'S': this->lat = -lat; break;
	default: return false;
	}

	switch(WE)
	{
	case 'E': this->lon = lon; break;
	case 'W': this->lon = -lon; break;
	default: return false;
	}
	return true;
}

std::string Position::str() const
{
	ostringstream oss;
	oss << "{lat: " << toString(lat) << ", lon: " << toString(lon) << "}";
	return oss.str();
}


