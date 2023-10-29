///////////////////////////////////////////////
//File: Matrix.cpp
//Sub-functions of this program
//Model the mathematical operations of a matrix
//Student name: 
//Student number: 
//Date: November 20, 2017
////////////////////////////////////////////////

#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < R_SIZE; i++)
		for (int j = 0; j < C_SIZE; j++)
			matrix[i][j] = 0;
}


Matrix::Matrix(int row, int col)
{
	R_SIZE = row;
	C_SIZE = col;
	for (int i = 0; i < R_SIZE; i++)
		for (int j = 0; j < C_SIZE; j++)
			cin >> matrix[i][j];
}

//add two matrixes
Matrix Matrix::add(const Matrix & m)
{
	Matrix temp;
	temp.R_SIZE = R_SIZE;
	temp.C_SIZE = C_SIZE;
	for (int i = 0; i < R_SIZE; i++)
	{
		for (int j = 0; j < C_SIZE; j++)
			temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
	}
	return temp;
}

//raises the matrix to power n
Matrix Matrix::power(const int n)
{
	Matrix temp;
	temp.R_SIZE = R_SIZE;
	temp.C_SIZE = C_SIZE;
	for (int i = 0; i < R_SIZE; i++)
	{
		for (int j = 0; j < C_SIZE; j++)
			temp.matrix[i][j] = int (pow(matrix[i][j], n));
	}
	return temp;
}

//overload the operator == to compare two matrixes
bool Matrix::operator ==(const Matrix& m) const
{
	for (int i = 0; i < R_SIZE; i++)
	{
		for (int j = 0; j < C_SIZE; j++)
		{
			if (matrix[i][j] != m.matrix[i][j])
				return false;
		}
	}
	return true;
}

//print the matrix
void Matrix::printMatrix() const
{
	for (int i = 0; i < R_SIZE; i++)
	{
		for (int j = 0; j < C_SIZE; j++)
		{
			cout.width(5);
			cout << left << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
