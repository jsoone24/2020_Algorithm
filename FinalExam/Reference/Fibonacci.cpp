#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    printf("%d", Fibonacci(10));

    return 0;
}