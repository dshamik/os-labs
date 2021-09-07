#include <stdio.h>

void bubble_sort(int arr[], int arr_len)
{
    int temp;
    for (int i = 0; i < arr_len; i++)
    {
        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }   
}

int main() {
    int n = 7;
    int arr[] = {3, 7, 4, 1, 2, 6, 5};
    bubble_sort(arr, n);
    print_array(arr, n);
}