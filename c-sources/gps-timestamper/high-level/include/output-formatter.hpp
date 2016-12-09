/*
 * output-formatter.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_FORMATTER_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_FORMATTER_HPP_

#include "output-data.hpp"

class OutputFormatter
{
public:
	void parse(const OutputData& data);
	const char* result() const;

private:
	constexpr static int maxResultSize = 100;
	constexpr static int bufferForDoubleSize = 20;
	char m_result[maxResultSize];
	char m_bufferForDouble[bufferForDoubleSize];
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_FORMATTER_HPP_ */
