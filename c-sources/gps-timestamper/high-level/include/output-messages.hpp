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

class OutputRegisteredImpulse : public IOutputMessage
{
public:
	OutputRegisteredImpulse(
			const Position& pos,
			const DateTime& dt,
			uint32_t lastSecondPeriod,
			uint32_t signalDelay);
	std::string str() const override;

private:
	const Position m_pos;
	const DateTime m_dt;
	uint32_t m_lastSecondPeriod;
	uint32_t m_signalDelay;
};

class OutputPPS : public IOutputMessage
{
public:
	OutputPPS(const Position& pos, const DateTime& dt);

	std::string str() const override;
private:
	const Position m_pos;
	const DateTime m_dt;
};

class OutputDebug : public IOutputMessage
{
public:
	OutputDebug(const std::string& msg);

	std::string str() const override;
private:
	const std::string m_msg;
};

class OutputGPSDisconnect : public IOutputMessage
{
public:
	std::string str() const override;
private:
};

class OutputQueueOverflow : public IOutputMessage
{
public:
	std::string str() const override;
private:
};

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MESSAGES_HPP_ */
