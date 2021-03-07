#include <iostream>

void selection_sort(int arr[], int len){
    printf("\nselection_sort\n");
    for (int i = 0, temp = 0; i < len; i++, printf("\n")){
        for (int t = 0; t < len; t++)
            printf("%d", arr[t]);

        for (int j = i; j < len; j++)
            arr[i] = (arr[j] < arr[i]) ? (temp = arr[j], arr[j] = arr[i], temp) : arr[i];
    }
}

void bubble_sort(int arr[], int len){
    printf("\nbubble_sort\n");
    for (int i = 0, temp = 0; i < len; i++, printf("\n")){
        for (int t = 0; t < len; t++)
            printf("%d", arr[t]);

        for (int j = 0; j < len - i - 1; j++)
            arr[j] = (arr[j] > arr[j + 1]) ? (temp = arr[j + 1], arr[j + 1] = arr[j], temp) : arr[j];
    }
}

int main(void)
{
    int arr[8] = {4, 7, 1, 3, 2, 8, 6, 5};
    int arr2[8] = {4, 7, 1, 3, 2, 8, 6, 5};
    int len = 8;

    selection_sort(arr, len);
    bubble_sort(arr2, len);

    return 0;
}