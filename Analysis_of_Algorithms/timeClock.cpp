/*
* @Author: woshijpf
* @Date:   2017-01-09 15:52:25
* @Last Modified by:   woshijpf
* @Last Modified time: 2017-01-09 16:14:27
*/

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "timeClock.h"

//返回的时间是毫秒为单位
long TimeClock::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void TimeClock::startTimeClock()
{
	startTimeStamp = getCurrentTime();
}

long TimeClock::stopTimeClock()
{
	stopTimeStamp = getCurrentTime();
	elapsedTime = stopTimeStamp - startTimeStamp;
	return elapsedTime;
}

void test_TimeClock()
{
	TimeClock timer;
	timer.startTimeClock();
	int i, j;
	int sum = 0;
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 10000; j++)
		{
			sum += i;
			sum += j;
		}
	long elapsedTime = timer.stopTimeClock();
	std::cout << "elapsedTime = " << elapsedTime << std::endl;
}