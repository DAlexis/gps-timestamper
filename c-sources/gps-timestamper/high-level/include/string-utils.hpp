/*
 * string-utils.h
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_HPP_

#include <string>

int double2str(char* buffer, double value, unsigned int precision, unsigned int maxBufferLen);

std::string toString(double value, unsigned int precision = 6);
std::string toString(bool value);

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_HPP_ */
