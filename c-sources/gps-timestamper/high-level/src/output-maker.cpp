/*
 * output-maker.cpp
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#include "output-maker.hpp"

OutputMaker::OutputMaker()
{
	m_outputTask.setStackSize(512);
}

void OutputMaker::run()
{
	m_outputTask.run();
}

bool OutputMaker::receive(const IOutputMessage* msg)
{
	if (m_queue.size() >= QueueMaxSize-1)
	{
		delete msg;

		if (m_queue.size() == QueueMaxSize-1)
			m_queue.pushBack(new OutputQueueOverflow());

		return false;
	}
	m_queue.pushBack(msg);
    return true;
}

bool OutputMaker::receiveFromISR(const IOutputMessage* msg)
{
	if (m_queue.sizeFromISR() >= QueueMaxSize-1)
	{
		delete msg;

		if (m_queue.sizeFromISR() == QueueMaxSize-1)
			m_queue.pushBackFromISR(new OutputQueueOverflow());

		return false;
	}
	m_queue.pushBackFromISR(msg);
    return true;
}

void OutputMaker::makeOutputLoop()
{
	const IOutputMessage* msg = nullptr;
	for (;;)
	{
		m_queue.popFront(msg);
		doOutput(msg);
		delete msg;
	}
}

void OutputMaker::doOutput(const IOutputMessage* msg)
{
	printf("%s\n", msg->str().c_str());
}
