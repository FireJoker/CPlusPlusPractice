///////////////////////////////////////////////
//File: Matrix.h
//Creat a class called Matrix
//Model the mathematical operations of a matrix
//Student name: 
//Student number: 
//Date: November 20, 2017
////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix add(const Matrix&);
	Matrix power(const int);
	bool operator==(const Matrix&) const;
	void printMatrix() const;

private:
	int R_SIZE;
	int C_SIZE;
	int matrix[100][100];
};

#endif
