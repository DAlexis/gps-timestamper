#include "nmea-parser.hpp"

#include "gtest/gtest.h"
#include <string>

#include <iostream>

using namespace std;


TEST(NmeaParser, ValidData)
{
	const char validSample[] = "$GPGGA,161229.487,3723.2475,N,12158.3416,W,1,07,1.0,9.0,M,,,,0000*18";
    NMEAParser parser;
    
    ASSERT_NO_THROW(parser.parse(validSample));
    ASSERT_TRUE(parser.result());
    ASSERT_EQ(string("161229.487"), string(parser.result().time));
    ASSERT_EQ(string("N3723.2475"), string(parser.result().lat));
    ASSERT_EQ(string("W12158.3416"), string(parser.result().lon));
}

TEST(NmeaParser, InvalidData1)
{
	const char invalidSample[] = "$GPWWWW,161229.487,3723.2475,N,12158.3416,W,1,07,1.0,9.0,M,,,,0000*18";
    NMEAParser parser;
    ASSERT_NO_THROW(parser.parse(invalidSample));
    ASSERT_FALSE(parser.result());
}

TEST(NmeaParser, InvalidData2)
{
	const char invalidSample[] = "$GPGGA,161229.487,3723.2475,,12158.3416,W,1,07,1.0,9.0,M,,,,0000*18";
    NMEAParser parser;
    ASSERT_NO_THROW(parser.parse(invalidSample));
    ASSERT_FALSE(parser.result());
}

TEST(NmeaParser, InvalidData3)
{
	const char invalidSample[] = "$GPGGA,161229.487,,N,12158.3416,W,1,07,1.0,9.0,M,,,,0000*18";
    NMEAParser parser;
    ASSERT_NO_THROW(parser.parse(invalidSample));
    ASSERT_FALSE(parser.result());
}

TEST(NmeaParser, InvalidData4)
{
	const char invalidSample[] = "$GPGGA,141132.000,,,,,0,1,,,M,,M,,*4D";
    NMEAParser parser;
    ASSERT_NO_THROW(parser.parse(invalidSample));
    ASSERT_FALSE(parser.result());
}

TEST(NmeaParser, InvalidData5)
{
	const char invalidSample[] = "";
    NMEAParser parser;
    ASSERT_NO_THROW(parser.parse(invalidSample));
    ASSERT_FALSE(parser.result());
}

