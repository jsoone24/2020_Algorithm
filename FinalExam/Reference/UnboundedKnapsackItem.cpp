#include <iostream>
using namespace std;

class Knapsack
{
    int *K;

public:
    int *UnboundedKnapsack(int W, int n, int weights[], int values[]);
    Knapsack(int W, int n);
};

int *Knapsack::UnboundedKnapsack(int W, int n, int weights[], int values[]) //W: 가방 크기, n: 아이템 수, weights: 아이템 무게 배열, values: 아이템 가치 배열
{
    K[0] = 0;
    int **ITEMS = new int *[W + 1];
    for (int i = 0; i < W + 1; i++)
        ITEMS[i] = new int[n]{0};

    for (int x = 1; x < W + 1; x++)
    {
        K[x] = 0;
        for (int i = 1; i < n + 1; i++)
            if (weights[i - 1] <= x)
            {
                int temp = K[x];
                K[x] = K[x] > (K[x - weights[i - 1]] + values[i - 1]) ? K[x] : (K[x - weights[i - 1]] + values[i - 1]);
                if (temp != K[x])
                {
                    for (int j = 0; j < n; j++)
                    {
                        ITEMS[x][j] = ITEMS[x - weights[i - 1]][j];
                    }
                    ITEMS[x][i - 1] += 1;
                }
            }
    }

    for (int i = 0; i < W + 1; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", ITEMS[i][j]);
        printf("\n");
    }

    return ITEMS[W];
}

Knapsack::Knapsack(int W, int n)
{
    K = new int[W + 1];
}

int main()
{
    int * ptr;
    int weights[3] = {1, 2, 3};
    int values[3] = {1, 4, 6};
    Knapsack K = Knapsack(4, 3);
    ptr = K.UnboundedKnapsack(4, 3, weights, values);
    for(int i = 0;i<3;i++)
        printf("%d", ptr[i]);
        
    return 0;
}