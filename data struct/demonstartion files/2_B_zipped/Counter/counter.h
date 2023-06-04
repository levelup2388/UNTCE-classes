// S.W. Smith, 2022

// counter.h
#ifndef COUNTERTYPE_FLAG
#define COUNTERTYPE_FLAG
class counterType
{
	private:

		int cnt;

	public:

		counterType();

		void init();

		int increment();

		int show();
};
#endif
