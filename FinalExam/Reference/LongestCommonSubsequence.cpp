#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

void LCS(char *X, char *Y)
{
    int sizeX = strlen(X), sizeY = strlen(Y);
    stack<char> s;

    int i = 0, j = 0;
    int **C = new int *[sizeX+1];
    for (i = 0; i < sizeX+1; i++)
        C[i] = new int[sizeY+1];

    for (i = 0; i < sizeX+1; i++)
        C[i][0] = 0;
    for (j = 0; j < sizeY+1; j++)
        C[0][j] = 0;

    for (i = 1; i < sizeX+1; i++)
        for (j = 1; j < sizeY+1; j++){
            if (X[i-1] == Y[j-1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = C[i][j - 1] > C[i - 1][j] ? C[i][j - 1] : C[i - 1][j];
        }

    for (i = 0; i < sizeX+1; i++){
        for (j = 0; j < sizeY+1; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    i = sizeX;
    j = sizeY;
    while (C[i][j] != 0)
    {
        printf("%d %d\n", i, j);
        if (X[i-1] == Y[j-1])
        {
            s.push(X[i-1]);
            i--;
            j--;
        }
        else
        {
            if (C[i][j] == C[i - 1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    while (!s.empty())
    {
        printf("%c ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    char *X = "AGGC";
    char *Y = "ATGC";
    LCS(X, Y);

    return 0;
}