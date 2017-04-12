#include "nmea-parser.hpp"
#include "macro.hpp"
#include <string.h>
#include <sstream>

using namespace std;

bool NMEAParser::parse(const char* str, Position& p, DateTime& t)
{
	stringstream ss(str);
	uint16_t year, month, day;
	uint8_t h,  m, s;
	float lat, lon;
	char latchar = 'x', lonchar = 'x';

	string substr;

	for (int i=0; ss.good(); i++)
	{

		getline(ss, substr, ',');
		switch (i)
		{
		case 0:
			if (substr != "$GPRMC")
				return false;
			break;
		case 1:
			if (!parseTime(substr, h, m, s))
				return false;
			break;
		case 3:
			if (!parseCoordinate(substr, lat))
				return false;
			break;
		case 4:
			latchar = substr[0];
			break;
		case 5:
			if (!parseCoordinate(substr, lon))
				return false;
			break;
		case 6:
			lonchar = substr[0];
			break;
		case 9:
			if (!parseDate(substr, year, month, day))
				return false;
			break;
		case 10:
			break;
		default:
			break;
		}
	}

	return p.set(lat, latchar, lon, lonchar)
			&& t.set(year, month, day, h, m, s);
}

void NMEAParser::parse(const char* str)
{
	// This function may be a bit optimized: removing shift in the end
	int len = strlen(str);
	if (len < 21) // String is obviously invalid
	{
		m_result.clear();
		return;
	}

	if (strncmp(str, "$GPGGA,", 7) != 0)
	{
		m_result.clear();
		return;
	}

	char latChar[GPSData::maxStrLen] = "", lonChar[GPSData::maxStrLen] = "";
	char* targets[] = {m_result.time, m_result.lat, latChar, m_result.lon, lonChar};

	unsigned int word = 0;
	unsigned int i = 7;

	while (str[i] != '\0' && word < ARRAY_SIZE(targets))
	{
		int j = 0;
		for (; str[i] != '\0' && str[i] != ','; i++, j++)
		{
			targets[word][j] = str[i];
			if (j == GPSData::maxStrLen - 2)
				break;
		}
		targets[word][j] = '\0';
		word++;
		i++;
	}
	if (word != ARRAY_SIZE(targets)
			|| m_result.time[0] == '\0'
			|| m_result.lat[0] == '\0'
			|| m_result.lon[0] == '\0'
			|| latChar[1] != '\0'
			|| lonChar[1] != '\0'
		)
	{
		m_result.clear();
		return;
	}

	// Now we should attach letters to GPS coordinates
	for (int i=GPSData::maxStrLen-1; i != 0; i--)
	{
		m_result.lat[i] = m_result.lat[i-1];
		m_result.lon[i] = m_result.lon[i-1];
	}
	m_result.lat[0] = latChar[0];
	m_result.lon[0] = lonChar[0];
}

const GPSData& NMEAParser::result() const
{
	return m_result;
}

bool NMEAParser::parseTime(const std::string& str, uint8_t& h, uint8_t& m, uint8_t& s)
{
	if (str.length() < 7 || str[6] != '.')
		return false;
	h = (str[0] - '0') * 10 + (str[1] - '0');
	m = (str[2] - '0') * 10 + (str[3] - '0');
	s = (str[4] - '0') * 10 + (str[5] - '0');
	if (h > 23 || m > 59 || s > 59)
		return false;
	return true;
}

bool NMEAParser::parseCoordinate(const std::string& str, float& coord)
{
	if (str.length()<7)
		return false;

	auto i = str.find('.');
	if (i == string::npos || i<3)
		return false;

	// Parsing degrees
	coord = 0;
	for (unsigned int j = 0; j<i-2; j++)
	{
		coord = coord*10.0 + (str[j] - '0');
	}

	// Parsing minutes
	float minutes = 0;
	minutes = (str[i-2] - '0') * 10 + (str[i-1] - '0');

	float minsFrac = 0;
	for (unsigned int j = str.length()-1; j>i; j--)
	{
		minsFrac = (minsFrac + (str[j] - '0')) / 10.0;
	}

	minutes += minsFrac;
	coord += minutes / 60.0;
	return true;
}

bool NMEAParser::parseDate(const std::string& str, uint16_t& year, uint16_t& month, uint16_t& day)
{
	if (str.length() != 6)
		return false;
	day   = (str[0] - '0') * 10 + (str[1] - '0');
	month = (str[2] - '0') * 10 + (str[3] - '0');
	year  = (str[4] - '0') * 10 + (str[5] - '0') + 2000;
	if (day > 31 || month > 12)
		return false;
	return true;
}
