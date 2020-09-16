#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

void arr_print(int n, int num[]);
void bubble_sort(int n, int num[]);
bool arr_cmp(int n, int arr1[], int arr2[]);

int main(void)
{
    int number[SIZE] = {1, 2, 3, 4, 5};
    int re_number[SIZE] = {5, 4, 3, 2, 1};

    arr_print(SIZE, number);
    arr_print(SIZE, re_number);

    bubble_sort(SIZE, number);
    bubble_sort(SIZE, re_number);
    
    if (arr_cmp(SIZE, number, re_number))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}

void arr_print(int n, int num[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", num[i]);
    }
    printf("\n");
}

void bubble_sort(int n, int num[])
{
    int temp, i, j;
    int index_min;

    for (i = 0; i < n - 1; i++)
    {
        index_min = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[index_min] > num[j])
                index_min = j;
        }
        if (i != index_min)
        {
            temp = num[i];
            num[i] = num[index_min];
            num[index_min] = temp;
        }
    }
}

bool arr_cmp(int n, int arr1[], int arr2[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
