#include "DivisorThreads.h"
#include <iostream>

DivisorThreads::DivisorThreads(int divisor, int dividend, int maxThreads) : divisor(divisor), dividend(dividend), maxThreads(maxThreads)
{
	
}

DivisorThreads::~DivisorThreads()
{

}

void DivisorThreads::run()
{
	bool primeCheck = true;

	while (divisor <= dividend / 2) {

		if (primeCheck == false)
			break;

		if (dividend % divisor == 0)
		{
			std::cout << "Not a Prime Number" << std::endl;
			primeCheck = false;
		}

		std::cout << "Divisor: " << divisor << std::endl;
		divisor += maxThreads;
		//std::cout << "Thread Count: " << divisor - 1 << std::endl;
	}
	
}
