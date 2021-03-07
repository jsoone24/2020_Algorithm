#include <iostream>
using namespace std;

class Knapsack
{
    int items;
    int *K;

public:
    Knapsack(int W, int n);
    int UnboundedKnapsack(int W, int n, int weights[], int values[]);
};

Knapsack::Knapsack(int W, int n)
{
    K = new int[W + 1];
}

int Knapsack::UnboundedKnapsack(int W, int n, int weights[], int values[]) //W: 가방 크기, n: 아이템 수, weights: 아이템 무게 배열, values: 아이템 가치 배열
{
    K[0] = 0;
    for (int x = 1; x < W + 1; x++)
    {
        K[x] = 0;
        for (int i = 1; i < n + 1; i++)
            if (weights[i - 1] <= x)
                K[x] = K[x] > (K[x - weights[i - 1]] + values[i - 1]) ? K[x] : (K[x - weights[i - 1]] + values[i - 1]);
    }

    for (int i = 0; i < W + 1; i++)
        printf("%d ", K[i]);

    return K[W];
}

int main()
{
    int weights[3] = {1, 2, 3};
    int values[3] = {1, 4, 6};
    Knapsack K = Knapsack(4, 3);
    printf("\n%d", K.UnboundedKnapsack(4, 3, weights, values));

    return 0;
}