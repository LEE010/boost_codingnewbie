/*
✔︎ 미션 1.


1. 미션 제목
숫자 애너그램 찾기

 

 

2. 지시문
‘애너그램’이란 문자를 재배열하여 다른 뜻을 가진 단어로 바꾸는 것을 말합니다. 예를 들면 영어의 ‘tea’와 ‘eat’과 같이, 각 단어를 구성하는 알파벳의 구성은 같지만 뜻은 다른 두 단어를 말합니다. 우리말에는 ‘문전박대’와 ‘대박전문’과 같은 예를 들 수 있습니다. 우리는 문자 대신 숫자를 이용해서 애너그램을 찾는 프로그램을 만들어봅시다. 5자리의 숫자 1쌍이 입력으로 주어지며 애너그램일 경우에는 “True”를 아닐 경우에는 “False”를 출력하도록 합시다. 숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에 배열로 선언하는 것으로 가정하고, 숫자에는 중복이 있을 수 있습니다.


예)
입력값: 12345, 54321 -> 출력값: True
입력값: 14258, 25431 -> 출력값: False
입력값: 11132, 21131 -> 출력값: True


3. 핵심 개념
#애너그램 #정렬알고리즘
*/
#include <stdio.h>
#include <stdbool.h>

const int SIZE = 5;

void selection_sort(int n, int arr[]);
void swap(int *a, int *b);
bool arr_cmp(int n, int arr_a[], int arr_b[]);

int main()
{
    int arr_a[] = {1, 2, 3, 4, 5};
    int arr_b[] = {5, 4, 3, 2, 1};

    selection_sort(SIZE, arr_a);
    selection_sort(SIZE, arr_b);
       
    (arr_cmp(SIZE, arr_a, arr_b)) ? printf("True\n"): printf("False\n");
    return 0;
}

void selection_sort(int n, int arr[])
{
    int *temp = NULL;

    for (size_t i = 0; i < n; i++)
    {
        temp = &arr[i];

        for (size_t j = i+1; j < n; j++)
        {
            if(*temp > arr[j])
            {
                temp = &arr[j];
            }
        }
        swap(&arr[i], temp);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool arr_cmp(int n, int arr_a[], int arr_b[])
{
    bool res = true;

    for (size_t i = 0; i < n; i++)
    {
        if (arr_a[i] != arr_b[i])
        {
            res = false;
            break;
        }
    }
    return res;
}
