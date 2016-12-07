/*
 * os-wrappers.cpp
 *
 *  Created on: 7 дек. 2016 г.
 *      Author: dalexies
 */

#include "os-wrappers.hpp"
#include "macro.hpp"

#include <stdio.h>

void TaskOnce::runTaskOnce(void const* pTask)
{
	TaskOnce *task = reinterpret_cast<TaskOnce*> (const_cast<void*>(pTask));
	osDelay(task->m_firstRunDelay);

	ADD_BITS(task->m_state, executingNow);
	task->m_task();

	if (task->m_state & needDeleteSelf)
	{
		delete task;
		vTaskDelete(NULL);
	} else {
		task->stopThread();
	}
}

void TaskCycled::runTaskInCycle(void const* pTask)
{
	TaskCycled *task = reinterpret_cast<TaskCycled*> (const_cast<void*>(pTask));
	osDelay(task->m_firstRunDelay);
	if (task->m_cyclesCount == 0)
	{
		for (;;)
		{
			ADD_BITS(task->m_state, executingNow);
			task->m_task();
			REMOVE_BITS(task->m_state, executingNow);
			if (task->m_state & needStop)
			{
				task->stopThread();
				return;
			}
			if (task->m_periodMin == 0)
			{
				taskYIELD();
			} else {
				osDelay(task->m_periodMin);
			}
		}
	} else {
		for (uint32_t i=0; i<task->m_cyclesCount;i++)
		{
			ADD_BITS(task->m_state, executingNow);
			task->m_task();
			REMOVE_BITS(task->m_state, executingNow);
			if (task->m_state & needStop)
			{
				task->stopThread();
				return;
			}
			if (task->m_periodMin == 0)
			{
				taskYIELD();
			} else {
				osDelay(task->m_periodMin);
			}
		}
		task->stopThread();
	}
}

bool TaskBase::safelyStop()
{
	if (!(m_state & runningNow))
		return true;

	if (m_state & executingNow)
	{
		ADD_BITS(m_state, needStop);
		return false;
	} else {
		vTaskDelete(m_taskId);
		m_taskId = nullptr;
		REMOVE_BITS(m_state, runningNow);
		REMOVE_BITS(m_state, needStop);
		return true;
	}
}

void TaskBase::stopUnsafe()
{
	if (m_taskId)
	{
		vTaskDelete(m_taskId);
		m_taskId = nullptr;
	}
}


void TaskBase::stopThread()
{
	REMOVE_BITS(m_state, runningNow);
	REMOVE_BITS(m_state, needStop);
	m_taskId = nullptr;
	vTaskDelete(NULL);
}

bool TaskOnce::run(STime delay, osPriority priority)
{
	ADD_BITS(m_state, runningNow);
	m_firstRunDelay = delay;
	//osThreadDef(newTask, runTaskOnce, priority, 0, m_stackSize);

	os_thread_def threadDef;
	threadDef.name = m_name;
	threadDef.pthread = runTaskOnce;
	threadDef.tpriority = priority;
	threadDef.instances = 0;
	threadDef.stacksize = m_stackSize;

	m_taskId = osThreadCreate(&threadDef, reinterpret_cast<void*>(this));
	if (m_taskId == NULL)
	{
		REMOVE_BITS(m_state, runningNow);
		printf("DBG: Running new task failed!\n");
		return false;
	}
	return true;
}

bool TaskCycled::run(STime firstRunDelay, STime periodMin, STime periodMax, uint32_t cyclesCount)
{
	ADD_BITS(m_state, runningNow);
	m_firstRunDelay = firstRunDelay;
	m_periodMin = periodMin;
	m_periodMax = periodMax;
	m_cyclesCount = cyclesCount;
	//osThreadDef(newTask, runTaskInCycle, osPriorityNormal, 0, m_stackSize);

	os_thread_def threadDef;
	threadDef.name = m_name;
	threadDef.pthread = runTaskInCycle;
	threadDef.tpriority = osPriorityNormal;
	threadDef.instances = 0;
	threadDef.stacksize = m_stackSize;

	m_taskId = osThreadCreate(&threadDef, reinterpret_cast<void*>(this));
	if (m_taskId == NULL)
	{
		REMOVE_BITS(m_state, runningNow);
		return false;
	}
	return true;
}
