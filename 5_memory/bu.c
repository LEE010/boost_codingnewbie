/*
1. 미션 제목
정렬을 해보자

 

 

2. 지시문

여러분은 데이터를 정리하기 위해서 엑셀을 많이 사용하실 것입니다. 게다가, 데이터들을 보기 좋게 하기 위해서 정렬 기능을 많이 사용하실 텐데 간단한 버블 정렬 코드를 배열이 아닌 포인터를 활용하여 완성해 보세요.


예) main code는 다음과 같습니다. sort function 을 완성해보세요

int main() 
{ 
    int n = 7; 
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 }; 
    sort(n, arr); 
return 0; 
}


출력값 : 0, 6, 9, 10, 12, 17, 25



3. 핵심 개념
#sort #bubblesort #버블정렬
*/
#include <stdio.h>

void sort(int n, int arr[]);

int main(void)
{
    int n = 7; 
    int arr[7] = { 0, 25, 10, 26, 1, 12, 9 }; 
    sort(n, arr); 
    return 0; 
}

void sort(int n, int *arr)
{
    int temp;
    for(int j = 0; j < n-1; j++){
        for(int i = 0; i < n-j-1; i++){
            if(*(arr+i) > *(arr+i+1)){
                temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
            }
        }
    }
    
    for(int i = 0; i < n-1; i++){
        printf("%d, ",*(arr+i));
    }
    printf("%d\n",*(arr+n-1));
}
