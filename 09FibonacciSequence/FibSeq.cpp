#include "FibSeq.h"

//recursive version of the function Fibonacci
int FibSeq::recurFib(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return recurFib(n - 1) + recurFib(n - 2);
}

//iterative version of the function Fibonacci
int FibSeq::intraFib(unsigned int n)
{
	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int c = 0;

	for (int i = 0; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

