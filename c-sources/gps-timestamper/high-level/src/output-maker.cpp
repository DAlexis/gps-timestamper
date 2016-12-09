/*
 * output-maker.cpp
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#include "output-maker.hpp"
#include "stdio.h"

void OutputMaker::makeOutputSync(const OutputData& data)
{
	m_formatter.parse(data);
	printf("%s\n", m_formatter.result());
}
