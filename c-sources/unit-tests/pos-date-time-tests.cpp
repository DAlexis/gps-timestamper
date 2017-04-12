#include <time-location-types.hpp>
#include "gtest/gtest.h"
#include <string>

#include <iostream>

using namespace std;

TEST(DateTime, Format)
{
	DateTime dt;
	dt.set(2017, 04, 11, 16, 37, 9);
	string s = dt.str();
	ASSERT_EQ(dt.str(), string("2017-04-11 16:37:09"));
}

TEST(DateTime, Increment)
{
	DateTime dt;

	dt.set(2016, 12, 31, 23, 59, 55);
	dt = dt + 15;
	ASSERT_EQ(dt.str(), string("2017-01-01 00:00:10"));

	dt.set(2016, 12, 31, 23, 59, 59);
	dt++;
	ASSERT_EQ(dt.str(), string("2017-01-01 00:00:00"));


}

TEST(Position, Format)
{
	Position p;
	p.set(12.345, 'S', 67.32, 'E');
	ASSERT_EQ(p.str(), string("{lat: -12.345000, lon: 67.319999}"));
}
