#include <iostream>
#include <stdio.h>
#include "DivisorThreads.h"
#include "IETThread.h"
#include <thread>
#include <cmath>

int TEST_INT = 2147483647;
int threadCount = 0;
int maxThreads = pow(2,2);
bool returnFlag = false;

void createDivisorThreads()
{
	if (returnFlag == true)
		return;

	for (int i = 2; i < maxThreads + 2; i++)
	{
		if (returnFlag == false)
		{
			DivisorThreads* thread = new DivisorThreads(TEST_INT, maxThreads, &threadCount, &returnFlag);
			thread->start();
			threadCount++;
		}
		else
			break;
		
	}

	//IETThread::sleep(1000);
}

int main() {

	createDivisorThreads();

	while (!returnFlag) 
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