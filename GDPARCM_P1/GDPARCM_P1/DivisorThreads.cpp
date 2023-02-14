#include "DivisorThreads.h"
#include <iostream>
#include <string>

DivisorThreads::DivisorThreads(int dividend, int maxThreads, int threadCount, bool* returnFlag, bool* isNumberPrime) : dividend(dividend), maxThreads(maxThreads), threadCount(threadCount), returnFlag(returnFlag), isNumberPrime(isNumberPrime)
{
	
}

DivisorThreads::~DivisorThreads()
{

}

void DivisorThreads::run()
{
	int minDivisor = ((dividend / 2) / maxThreads) * (threadCount); 
	int maxDivisor = ((dividend / 2) / maxThreads) * (threadCount + 1);




	//std::cout << "maxdivisorcheck:" + std::to_string(maxDivisor) << std::endl;



	
	for (int i = minDivisor; i <= maxDivisor; i++)
	{
		if (i == 0)
			i = 2;

		//std::cout << "Checking: " << i << std::endl;

		if (dividend % i == 0)
		{
			//std::cout << "Not a Prime Number" << std::endl;
			//std::cout << "Divisor: " << i << std::endl;
			*isNumberPrime = false;
			*returnFlag = true;
			break;
		}
		
		//IETThread::sleep(1000);
		
	}
	
	
	*isNumberPrime = true;
	*returnFlag = true;
	
	
	
}
