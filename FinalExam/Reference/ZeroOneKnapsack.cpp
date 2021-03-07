#include <iostream>
using namespace std;

class Knapsack
{
    int **k;

public:
    int ZeroOneKnapsack(int W, int n, int weights[], int values[]);
    Knapsack(int W, int n);
};

Knapsack::Knapsack(int W, int n)
{
    k = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        k[i] = new int[W + 1];
}

int Knapsack::ZeroOneKnapsack(int W, int n, int weights[], int values[])
{
    for (int x = 0; x < W + 1; x++)
        k[0][x] = 0;

    for (int i = 0; i < n + 1; i++)
        k[i][0] = 0;

    for (int j = 1; j < n + 1; j++)
    {
        for (int x = 1; x < W + 1; x++)
        {
            k[j][x] = k[j-1][x];
            if (weights[j-1] <= x)
            {
                k[j][x] = k[j][x] > k[j - 1][x - weights[j-1]] + values[j-1] ? k[x][j] : k[j - 1][x - weights[j-1]] + values[j-1];
            }
        }
    }
    for (int j = 0; j < n + 1; j++){
        for (int x = 0; x < W + 1; x++)
            printf("%d ", k[j][x]);
        printf("\n");
    }
    return k[n][W];
}

int main()
{
    int weights[3] = {1, 2, 3};
    int values[3] = {1, 4, 6};
    Knapsack K = Knapsack(3, 3);
    printf("%d", K.ZeroOneKnapsack(3, 3, weights, values));

    return 0;
}