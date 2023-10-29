#include"FibSeq.h"

int main()
{
	FibSeq test;    //creat an object

	//test the recursive versions with different numbers
	cout << "test the recursive versions of the function Fibonacci" << endl;
	cout << "Fib(5) = " << test.recurFib(5) << endl;
	cout << "Fib(10) = " << test.recurFib(10) << endl;
	cout << "Fib(15) = " << test.recurFib(15) << endl;
	cout << "Fib(20) = " << test.recurFib(20) << endl;
	cout << "Fib(30) = " << test.recurFib(30) << endl;
//	cout << "Fib(40) = " << test.recurFib(40) << endl;
//	cout << "Fib(50) = " << test.recurFib(50) << endl;    //cause too much time to find the solution
	cout << endl;

	//test the iterative versions with different numbers
	cout << "test the iterative versions of the function Fibonacci" << endl;
	cout << "Fib(5) = " << test.intraFib(5) << endl;
	cout << "Fib(10) = " << test.intraFib(10) << endl;
	cout << "Fib(15) = " << test.intraFib(15) << endl;
	cout << "Fib(20) = " << test.intraFib(20) << endl;
	cout << "Fib(30) = " << test.intraFib(30) << endl;
//	cout << "Fib(40) = " << test.intraFib(40) << endl;
//	cout << "Fib(50) = " << test.intraFib(50) << endl;

//	system("pause");
	return 0;
}
