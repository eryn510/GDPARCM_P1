#include "DivisorThreads.h"
#include <iostream>
#include <string>

DivisorThreads::DivisorThreads(int dividend, int maxThreads, int threadCount) : dividend(dividend), maxThreads(maxThreads), threadCount(threadCount)
{
	
}

DivisorThreads::~DivisorThreads()
{

}

void DivisorThreads::run()
{
	int minDivisor = ((dividend / 2) / maxThreads) * (threadCount); 
	int maxDivisor = ((dividend / 2) / maxThreads) * (threadCount + 1);
	
	for (int i = minDivisor; i <= maxDivisor; i++)
	{
		if (i == 0)
			i = 2;


		if (dividend % i == 0)
		{
			this->isNumberPrime = false;
			this->returnFlag = true;
			break;
		}
	}

	this->returnFlag = true;
}
