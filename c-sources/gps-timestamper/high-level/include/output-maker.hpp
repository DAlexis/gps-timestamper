/*
 * output-maker.hpp
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_

#include "output-formatter.hpp"

class OutputMaker
{
public:
	void makeOutputSync(const OutputData& data);

private:
	OutputFormatter m_formatter;
};







#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_ */
