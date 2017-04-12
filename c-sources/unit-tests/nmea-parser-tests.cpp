#include "nmea-parser.hpp"

#include "gtest/gtest.h"
#include <string>

#include <iostream>

using namespace std;

TEST(NmeaParser, ValidDataNew)
{
	const char str[] = "$GPRMC,134709.000,A,5619.4071,N,04401.4063,E,1.41,96.08,110417,,,A*5E";
	DateTime t;
	Position p;
	ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
	ASSERT_TRUE(NMEAParser::parse(str, p, t));
	ASSERT_EQ(t.str(), string("2017-04-11 13:47:09"));
	ASSERT_NEAR(p.lat, 56 + 19.4071 / 60.0, 1e-6);
	ASSERT_NEAR(p.lon, 44 + 1.4063 / 60.0, 1e-6);
}

TEST(NmeaParser, InvalidData)
{
	DateTime t;
		Position p;
	{
		const char str[] = "$GPRMD,134709.000,A,5619.4071,N,04401.4063,E,1.41,96.08,110417,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t)) << "Invalid header test";
	}

	{
		const char str[] = "$GPRMC,A,5619.4071,N,04401.4063,E,1.41,96.08,110417,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t)) << "Time removed test";
	}

	{
		const char str[] = "$GPRMC,134709.000,A,5619.4071,N,04401.4063,E,1.41,96.08,1104179,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t));
	}

	{
		const char str[] = "$GPRMC,134709.000,A,5619.4071,W,04401.4063,E,1.41,96.08,110417,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t)) << "Invalid N/S test";
	}
	{
		const char str[] = "$GPRMC,134709.000,,A,5619.4071,N,04401.4063,E,1.41,96.08,110417,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t)) << "Comma added test";
	}
	{
		const char str[] = "$GPRMC,134709.000,A,5619.4071,N,04401.4063,E,1.41,96.08,990417,,,A*5E";
		ASSERT_NO_THROW(NMEAParser::parse(str, p, t));
		ASSERT_FALSE(NMEAParser::parse(str, p, t)) << "Invalid date test";
	}
}
