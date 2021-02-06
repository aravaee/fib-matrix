# Fibonacci number

> In mathematics, the Fibonacci numbers, commonly denoted F<sub>n</sub>, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
> [More on Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_number)

## The sequence F<sub>n</sub> of Fibonacci numbers is defined by the recurrence relation:

F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-1</sub>, Where F<sub>0</sub> = 0 and F<sub>1</sub> = 1.

### This algorithm is based on:

<img src="https://latex.codecogs.com/gif.latex?\displaystyle {\begin{pmatrix}1&1\\1&0\end{pmatrix}}^{n}={\begin{pmatrix}F_{n+1}&F_{n}\\F_{n}&F_{n-1}\end{pmatrix}}"/>

### Time Complexity

The time taken by using power of the matrix is O(n)

## Compile and Run:

```
make
./main
```
