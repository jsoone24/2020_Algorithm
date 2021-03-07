#include <iostream>
using namespace std;

int *F = new int[100]{1,1};

int FibonacciDynamicRecursion(int n)
{
    if (F[n] != 0)
        return F[n];
    else
        F[n] = FibonacciDynamicRecursion(n - 1) + FibonacciDynamicRecursion(n - 2);

    return F[n];
}

int main()
{
    printf("%d", FibonacciDynamicRecursion(10));

    return 0;
}