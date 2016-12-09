#include "string-utils.h"

#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

TEST(Double2String, ValidPositive)
{
	double testValue = 3.1415;
	char buffer[20];
	ASSERT_NO_THROW(double2str(buffer, testValue, 5, 20));
	ASSERT_TRUE(
		string(buffer) == string("3.14150")
		|| string(buffer) == string("3.14151")
		|| string(buffer) == string("3.14149")
	);

	testValue = 123.987;
	ASSERT_NO_THROW(double2str(buffer, testValue, 5, 20));
	ASSERT_TRUE(
		string(buffer) == string("123.98700")
		|| string(buffer) == string("123.98699")
		|| string(buffer) == string("123.98701")
	);

	testValue = 123.987;
	ASSERT_NO_THROW(double2str(buffer, testValue, 2, 20));
	ASSERT_TRUE(
		string(buffer) == string("123.98")
		|| string(buffer) == string("123.99")
		|| string(buffer) == string("123.97")
	);

	testValue = 123;
	ASSERT_NO_THROW(double2str(buffer, testValue, 2, 20));
	ASSERT_TRUE(
		string(buffer) == string("123.01")
		|| string(buffer) == string("123.00")
		|| string(buffer) == string("122.99")
	);
}

TEST(Double2String, ValidNegative)
{
	double testValue = -42.275;
	char buffer[20];
	ASSERT_NO_THROW(double2str(buffer, testValue, 5, 20));
	ASSERT_TRUE(
		string(buffer) == string("-42.27500")
		|| string(buffer) == string("-42.27499")
		|| string(buffer) == string("-42.27501")
	);
}

TEST(Double2String, Invalid)
{
	char buffer[20];
	ASSERT_NO_THROW(double2str(buffer, 123456.986, 1, 6));
	ASSERT_EQ(string(buffer), string("#"));
}
