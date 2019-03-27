/*
 * output-data.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MESSAGES_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MESSAGES_HPP_

#include "gps-data.hpp"
#include "time-location-types.hpp"
#include <stdint.h>

#include <string>

class IOutputMessage
{
public:
	virtual ~IOutputMessage() {}
	virtual std::string str() const = 0;
};

class IOutputMessagesReceiver
{
public:
	virtual ~IOutputMessagesReceiver() {}
	virtual bool receive(const IOutputMessage* msg) = 0;
	virtual bool receiveFromISR(const IOutputMessage* msg) = 0;
};

class OutputDebug : public IOutputMessage
{
public:
    OutputDebug(const std::string& msg);

    std::string str() const override;
private:
    const std::string m_msg;
};

class OutputQueueOverflow : public IOutputMessage
{
public:
	std::string str() const override;
private:
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MESSAGES_HPP_ */
