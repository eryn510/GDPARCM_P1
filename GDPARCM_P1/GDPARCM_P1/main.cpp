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

	//IETThread::sleep(1000);
}

int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	int TEST_INT = 25;
	int curr_threadCount = 0;
	int maxThreads = pow(2, 2);

	bool isAllThreadsDone = false;

	std::vector<DivisorThreads*> threadList;

	createDivisorThreads(TEST_INT, maxThreads, curr_threadCount, &threadList);

	//IETThread::sleep(5000);

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


	/*
	 *TO DO: print only once lang if number is prime or nah
	 *
	 */
	for(int i = 0; i < threadList.size(); i++)
	{
		if (threadList[i]->isNumberPrime == false)
		{
			std::cout << "\nNUMBER IS NOT PRIME\n" << std::endl;
			
		}
		else
		{
			std::cout << "\nNUMBER IS PRIME\n" << std::endl;
			
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = std::chrono::duration<double>(end_time - start_time).count();
	std::cout << "Elapsed time: " << elapsed_seconds << " seconds" << std::endl;


}