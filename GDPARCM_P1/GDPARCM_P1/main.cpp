#include <iostream>
#include <stdio.h>
#include "DivisorThreads.h"
#include "IETThread.h"
#include <thread>
#include <cmath>


void createDivisorThreads(int testNumber, int maxThreads, int threadCount, bool* returnFlag, bool* isNumberPrime)
{
	if (*returnFlag == true)
		return;


	for (int i = 0; i < maxThreads; i++)
	{
		if (*returnFlag == false)
		{
			DivisorThreads* thread = new DivisorThreads(testNumber, maxThreads, threadCount, returnFlag, isNumberPrime);
			thread->start();
			threadCount += 1;
		}
		else
			break;
		
	}

	//IETThread::sleep(1000);
}

int main()
{
	int TEST_INT = 100; //2147483647;
	int curr_threadCount = 0;
	int maxThreads = pow(2, 2);
	bool returnFlag = false;
	bool isNumberPrime = false;

	createDivisorThreads(TEST_INT, maxThreads, curr_threadCount, &returnFlag, &isNumberPrime);

	IETThread::sleep(2000);

	while (returnFlag == false) 
	{
		std::cout << "I am computing. Please wait..." << std::endl;
	}

	if(isNumberPrime == false)
	{
		std::cout << "\nNUMBER IS NOT PRIME\n" << std::endl;
	}
	else
	{
		std::cout << "\nNUMBER IS PRIME\n" << std::endl;
	}

	/*
	for (int i = 2; i < (TEST_INT / 2); i++)
	{
		if (TEST_INT % i == 0)
		{
			std::cout << "Not a Prime" << std::endl;
			break;
		}
	}

	std::cout << "Prime" << std::endl;
	*/
}