#include "nmea-parser.hpp"
#include "macro.hpp"
#include <string.h>

PosTime::PosTime()
{
	clear();
}

void PosTime::clear()
{
	lat[0] = '\0';
	lon[0] = '\0';
	time[0] = '\0';
}

bool PosTime::hasData() const
{
	return (lat[0] != '\0');
}

PosTime::operator bool() const
{
	return hasData();
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

	char latChar[PosTime::maxStrLen] = "", lonChar[PosTime::maxStrLen] = "";
	char* targets[] = {m_result.time, m_result.lat, latChar, m_result.lon, lonChar};

	unsigned int word = 0;
	unsigned int i = 7;

	while (str[i] != '\0' && word < ARRAY_SIZE(targets))
	{
		int j = 0;
		for (; str[i] != '\0' && str[i] != ','; i++, j++)
		{
			targets[word][j] = str[i];
			if (j == PosTime::maxStrLen - 2)
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
	for (int i=PosTime::maxStrLen-1; i != 0; i--)
	{
		m_result.lat[i] = m_result.lat[i-1];
		m_result.lon[i] = m_result.lon[i-1];
	}
	m_result.lat[0] = latChar[0];
	m_result.lon[0] = lonChar[0];
}

const PosTime& NMEAParser::result() const
{
	return m_result;
}

