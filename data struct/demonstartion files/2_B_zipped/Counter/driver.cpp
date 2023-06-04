#include "counter.h"
#include <iostream>
using namespace std;

int main()
{
	counterType c;

	c.init();

	int i=c.show();
	while(i<10)
	{
		cout<<i<<'\n';
		i=c.increment();
	}

	return 0;
}

