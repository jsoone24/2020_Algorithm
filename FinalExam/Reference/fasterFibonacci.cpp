#include <iostream>
using namespace std;

int fasterFibonacci(int n)
{
    int *F = new int[n];
    F[0] = F[1] = 1;

    for (int i = 2; i < n; i++)
        F[i] = F[i - 1] + F[i - 2];

    return F[n-1];
}

int main()
{
    printf("%d", fasterFibonacci(10));

    return 0;
}