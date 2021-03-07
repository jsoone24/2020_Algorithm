#include <iostream>
using namespace std;

void sort(int *A, int len)
{
    for (int i = 1, cur_value = A[i], j = i - 1; i < len; i++, cur_value = A[i], j = i - 1)
    {
        while (j >= 0 && A[j] > cur_value)
            A[j + 1] = A[j], j -= 1;
        A[j + 1] = cur_value;

        for (int i = 0; i < len; i++)
            cout << A[i] << " ";
        cout << endl;
    }
}

int main(void)
{
    int arr[8] = {4, 7, 1, 3, 2, 8, 6, 5};
    int len = 8;

    /* fill up with your code */
    sort(arr, len);
    return 0;
}