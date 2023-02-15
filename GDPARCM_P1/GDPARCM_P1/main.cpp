#include <iostream>
#include <stdio.h>
#include "DivisorThreads.h"
#include "IETThread.h"
#include <thread>
#include <cmath>
#include <vector>
#include <chrono>


void createDivisorThreads(int testNumber, int maxThreads, int threadCount, std::vector<DivisorThreads*>* threadList)
{
	
	for (int i = 0; i < maxThreads; i++)
	{
		DivisorThreads* thread = new DivisorThreads(testNumber, maxThreads, threadCount);
		thread->start();
		threadList->push_back(thread);
		threadCount += 1;
		
	}
}

int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	int TEST_INT = 2147483647;
	int curr_threadCount = 0;
	int maxThreads = pow(2, 10);
	int isNumberPrime = true;

	bool isAllThreadsDone = false;

	std::vector<DivisorThreads*> threadList;

	createDivisorThreads(TEST_INT, maxThreads, curr_threadCount, &threadList);


	while (isAllThreadsDone == false) 
	{
		isAllThreadsDone = true;
		for(int i = 0; i < threadList.size(); i++)
		{
			if(threadList[i]->returnFlag == false)
			{
				isAllThreadsDone = false;
			}
		}
	}

	for(int i = 0; i < threadList.size(); i++)
	{
		if (threadList[i]->isNumberPrime == false)
		{
			std::cout << "\nNUMBER IS NOT PRIME\n" << std::endl;
			isNumberPrime = false;
			break;
		}
	}

	if (isAllThreadsDone && isNumberPrime)
		std::cout << "\nNUMBER IS PRIME\n" << std::endl;

	auto end_time = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration<double>(end_time - start_time).count();
	std::cout << "Elapsed time: " << elapsed_seconds << " seconds" << std::endl;


}