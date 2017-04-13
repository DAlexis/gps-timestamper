/*
 * output-maker.hpp
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_

#include "output-messages.hpp"
#include "os-wrappers.hpp"

class OutputMaker : public IOutputMessagesReceiver
{
public:
	constexpr static unsigned int QueueMaxSize = 100;

	OutputMaker();

	void run();

	bool receive(const IOutputMessage* msg) override;
	bool receiveFromISR(const IOutputMessage* msg) override;

private:
	void makeOutputLoop();
	void doOutput(const IOutputMessage* msg);
	Queue<const IOutputMessage*> m_queue{QueueMaxSize};

	TaskOnce m_outputTask{[this] { makeOutputLoop(); }};

};


#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OUTPUT_MAKER_HPP_ */
