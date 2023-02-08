#include <iostream>
#include <stdio.h>
#include "DivisorThreads.h"
#include "IETThread.h"
#include <thread>
#include <cmath>

int TEST_INT = 2147483647;
int maxThreads = pow(2,1);

void createDivisorThreads()
{
	for (int i = 2; i < maxThreads + 2; i++)
	{
		DivisorThreads* thread = new DivisorThreads(i, TEST_INT, maxThreads);
		thread->start();
	}

	//Sleep main thread to avoid premature halting. Wait for other threads to finish execution.
	IETThread::sleep(1000);
}

int main() {
	createDivisorThreads();

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