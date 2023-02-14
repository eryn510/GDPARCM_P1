#include <iostream>
#include <stdio.h>
#include "DivisorThreads.h"
#include "IETThread.h"
#include <thread>
#include <cmath>


void createDivisorThreads(int testNumber, int maxThreads, int threadCount, bool* returnFlag)
{
	if (*returnFlag == true)
		return;


	for (int i = 0; i < maxThreads; i++)
	{
		if (*returnFlag == false)
		{
			DivisorThreads* thread = new DivisorThreads(testNumber, maxThreads, threadCount, returnFlag);
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
	int TEST_INT = 25; //2147483647;
	int curr_threadCount = 0;
	int maxThreads = pow(2, 2);
	bool returnFlag = false;

	createDivisorThreads(TEST_INT, maxThreads, curr_threadCount, &returnFlag);

	IETThread::sleep(2000);

	while (returnFlag == false) 
	{
		std::cout << "I am computing. Please wait..." << std::endl;
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