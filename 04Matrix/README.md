# Matrix

Implement a C++ class to model the mathematical operations of a matrix. Your class should
include the following functions.

- **`add()`** which adds two matrices;
- **`power()`** which raises the first matrix to power n;
- **`==`** which returns true if both matrices are equal. You need to overload the C++
equality operator.

A sample run follows.
```
Enter the number of rows: 2
Enter the number of columns: 3
Enter the elements of matrix 1 row by row:
1 0 3
5 1 2
Enter the elements of matrix 2 row by row:
1 1 2
1 0 4
matrix 1 == matrix 2?
No
matrix 1 + matrix 2:
2 1 5
6 1 6
matrix 1 power n. Enter n: 2
1 0 9
25 1 4
```