#pragma once
#include "IETThread.h"

class DivisorThreads : public IETThread

{
public:
	DivisorThreads(int dividend, int maxThreads, int threadCount, bool* returnFlag, bool* isNumberPrime);
	~DivisorThreads();

private:
	void run() override;

	int dividend = 0;
	int maxThreads = 0;
	int threadCount;
	bool* returnFlag;
	bool* isNumberPrime;

public:
	bool isThreadDone = false;
};

