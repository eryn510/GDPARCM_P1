#pragma once
#include "IETThread.h"

class DivisorThreads : public IETThread

{
public:
	DivisorThreads(int divisor, int dividend, int maxThreads);
	~DivisorThreads();

private:
	void run() override;

	int divisor = 0;
	int dividend = 0;
	int maxThreads = 0;
};

