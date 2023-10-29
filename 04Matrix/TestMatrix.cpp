///////////////////////////////////////////////
//File: Matrix.cpp
//Main function of this program
//Model the mathematical operations of a matrix
//Student name: 
//Student number: 
//Date: November 20, 2017
////////////////////////////////////////////////

#include "Matrix.h"

int main()
{
	int row, col, n;

	//ask for row and col
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "Enter the number of columns: ";
	cin >> col;

	//user type in two matrixes
	cout << "Enter the elements of matrix 1 row by row:" << endl;
	Matrix m1(row, col);
	cout << "Enter the elements of matrix 2 row by row:" << endl;
	Matrix m2(row, col);

	//compare two matrixes
	cout << "matrix 1 == matrix 2?" << endl;
	if (m1 == (m2))
		cout << "Yes." << endl;
	else
		cout << "No." << endl;

	//calculate addition
	Matrix temp;
	temp = m1.add(m2);
	cout << "matrix 1 + matrix 2:" << endl;
	temp.printMatrix();

	//calculate power
	cout << "matrix 1 power n. Enter n: ";
	cin >> n;
	temp = m1.power(n);
	temp.printMatrix();

	return 0;
}
