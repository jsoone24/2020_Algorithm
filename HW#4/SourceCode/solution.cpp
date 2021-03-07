#include <iostream>
#include "solution.h"
using namespace std;

unsigned long long int arr[30][30] = {0};

unsigned long long int Solution::pathCases(int m, int n)
{
    /* Fill up here with your codes */
    int max = m > n ? m : n;

    for (int curIdx = 1; curIdx < max; curIdx++)
    {
        arr[curIdx][0] = arr[0][curIdx] = 1;
        for (int i = 1; i < curIdx; i++)
        {
            arr[curIdx][i] = arr[curIdx - 1][i] + arr[curIdx][i - 1];
            arr[i][curIdx] = arr[i][curIdx - 1] + arr[i - 1][curIdx];
        }
        arr[curIdx][curIdx] = arr[curIdx][curIdx - 1] + arr[curIdx - 1][curIdx];
    }

    return arr[m - 1][n - 1];
}