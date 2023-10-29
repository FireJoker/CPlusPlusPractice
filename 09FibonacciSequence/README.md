# Fibonacci Sequence Calculation

The Fibonacci sequence is a series of integers where each number is the sum of the two preceding ones. The sequence starts with 0 and 1, and the subsequent numbers are calculated by adding the last two numbers in the sequence.

## Recursive Fibonacci Function (a)
The recursive formula for calculating the nth Fibonacci number is as follows:
```
Fib(N) = N, if N = 0 or 1
Fib(N) = Fib(N-2) + Fib(N-1), if N > 1
```

You can implement this recursive formula in a function to calculate the nth Fibonacci number.

## Iterative Fibonacci Function (b)
The iterative version of the Fibonacci function calculates the sequence using a loop, avoiding the recursive overhead. It iterates through the sequence and calculates each Fibonacci number iteratively.

## Testing Program (c)
You can write a program to test both the recursive and iterative versions of the Fibonacci function. Test the functions for different values of N, such as 5, 10, 30, 40, and 50, to observe their performance and accuracy.
