/*
 * os-wrappers.hpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OS_WRAPPERS_HPP_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OS_WRAPPERS_HPP_

#include "cmsis_os.h"

#include <functional>

using STask = std::function<void(void)>;
using STime = uint32_t;
using STaskId = osThreadId;

class TaskBase
{
public:
	TaskBase(const STask& task = nullptr, const char* name = "Unknown") :
		m_task(task),
		m_name(const_cast<char*>(name))
	{ }

	inline bool isRunning() const { return m_state & runningNow; }
	inline void deleteAfterRun(bool doDelete = true)
	{
		if (doDelete)
			m_state |= needDeleteSelf;
		else
			m_state &= ~(needDeleteSelf);
	}
	inline void setTask(const STask& _task) { m_task = _task; }
	inline void setStackSize(uint32_t stackSize) { m_stackSize = stackSize; }
	void setName(const char* name) { m_name = const_cast<char*>(name); }
	inline STaskId taskId() { return m_taskId; }

	/**
	 * Stop task safely, all destructors will be called
	 * @return is task executing after this call
	 */
	bool safelyStop();
	/**
	 * Call vTaskDelete. Attention! This operation immediately stop the task
	 * without calling any destructors
	 */
	void stopUnsafe();

protected:
	constexpr static uint8_t runningNow = 1;
	constexpr static uint8_t needDeleteSelf = 2;
	constexpr static uint8_t needStop = 4;
	constexpr static uint8_t executingNow = 8;

	void stopThread();

	STask m_task;
	uint32_t m_stackSize = 128;
	STaskId m_taskId = nullptr;
	uint8_t m_state = 0;
	char* m_name;
};

class TaskOnce : public TaskBase
{
public:
	TaskOnce(const STask& task = nullptr) :
		TaskBase(task)
	{ }
	bool run(STime delay = 0, osPriority priority = osPriorityNormal);

private:
	STime m_firstRunDelay = 0;
	static void runTaskOnce(void const* pTask);
};

class TaskCycled : public TaskBase
{
public:
	TaskCycled(const STask& task = nullptr) :
			TaskBase(task)
	{ }

	bool run(STime firstRunDelay = 0, STime periodMin = 1, STime periodMax = 1, uint32_t cyclesCount = 0);

private:
	STime m_firstRunDelay = 0;
	STime m_periodMin = 0;
	STime m_periodMax = 0;
	uint32_t m_cyclesCount = 0;
	static void runTaskInCycle(void const* pTask);
};

template<typename T>
class Queue
{
public:
	Queue(unsigned int size = 10)
	{
		m_handle = xQueueCreate(size, sizeof(T));
	}

	void pushBack(T&& obj, TickType_t timeToWait = portMAX_DELAY)
	{
		xQueueSendToBack(m_handle, &obj, timeToWait);
	}

	void pushFront(T&& obj, TickType_t timeToWait = portMAX_DELAY)
	{
		xQueueSendToFront(m_handle, &obj, timeToWait);
	}

	void popFront(T& target, TickType_t timeToWait = portMAX_DELAY)
	{
		xQueueReceive(m_handle, &target, timeToWait);
	}

	void pushBackFromISR(T& obj)
	{
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xQueueSendToBackFromISR(m_handle, &obj, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
	}

	void pushFrontFromISR(T& obj)
	{
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xQueueSendToFrontFromISR(m_handle, &obj, xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
	}

	void popFrontFromISR(T& target)
	{
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xQueueReceiveFromISR(m_handle, &target, xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
	}

	uint16_t size()
	{
		return uxQueueMessagesWaiting(m_handle);
	}

private:
	xQueueHandle m_handle;
};

class Mutex
{
public:
	Mutex()		{ handle = xSemaphoreCreateMutex(); }
	~Mutex() 	{ if (handle) vSemaphoreDelete(handle); }

	inline bool lock(uint32_t timeout = portMAX_DELAY)
		{ return (xSemaphoreTake( handle, timeout ) == pdTRUE); }

	inline void unlock()
		{ xSemaphoreGive( handle ); }

	inline bool isLocked()
	{
		bool wasNotLocked = lock(0);
		if (wasNotLocked) {
			unlock();
			return false;
		}
		return true;
	}
private:
	xSemaphoreHandle handle = nullptr;
};


#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_OS_WRAPPERS_HPP_ */
