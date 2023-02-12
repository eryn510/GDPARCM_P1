#include "DivisorThreads.h"
#include <iostream>

DivisorThreads::DivisorThreads(int dividend, int maxThreads, int* threadCount, bool* returnFlag) : dividend(dividend), maxThreads(maxThreads), threadCount(threadCount), returnFlag(returnFlag)
{
	
}

DivisorThreads::~DivisorThreads()
{

}

void DivisorThreads::run()
{
	for (int i = (1 + (((dividend / 2) / maxThreads) * (*threadCount))); i < ((dividend / 2) / maxThreads) * (*threadCount + 1); i++)
	{
		if (i == 1)
			i++;
		
		if (dividend % i == 0)
		{
			std::cout << "Not a Prime Number" << std::endl;
			std::cout << "Divisor: " << i << std::endl;
			*returnFlag = true;
			break;
		}

		std::cout << "Divisor: " << i << std::endl;
	}

	
}
