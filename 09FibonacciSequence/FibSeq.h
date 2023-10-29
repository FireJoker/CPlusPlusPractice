#ifndef FEBSEQ_H
#define FEBSEQ_H

#include <iostream>
using namespace std;

//in this class we only need the public member functions
class FibSeq
{
public:
	int recurFib(unsigned int n);    //Recursive version
	int intraFib(unsigned int n);    //Iterative version

};

#endif

