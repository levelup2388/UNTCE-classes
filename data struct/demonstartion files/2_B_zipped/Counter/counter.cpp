// S.W. Smith, 2022
// counter.cpp

#include "counter.h"

	counterType::counterType()
	{
		cnt=0;
	}

	void counterType::init()
	{
		cnt=0;
	}

	int counterType::increment()
	{
		++cnt;
		return cnt;
	}

	int counterType::show()
	{
		return cnt;
	}
