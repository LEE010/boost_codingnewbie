/*
✔︎ 문제 2. 누가 빠졌는지 찾아보자!

 

1. 미션 제목
누가 빠졌는지 찾아보자!

 

2. 지시문
1 부터 N 까지의 숫자 모음이 있다. 여기서 K 라는 숫자가 빠진 N – 1 개의 파일이 있다. K 라는 숫자를 찾아보자.
    - N 은 2 이상 500,000 이하의 값을 가짐
    - 정렬되지 않은 숫자들의 모음 파일이 주어짐 (ex, 10.txt 100.txt 1_000.txt 10_000.txt 100_000.txt, 500_000.txt)
    - 위 파일에서 빠진 숫자 K 를 찾아라
    - 파일의 값을 읽어 n 과 k 가 빠진 arr 이를 저장하는 참고 코드는 아래 참고 (파일은 제공된 파일 사용)
    - 파일 구조: 첫 줄에는 N 값이 주어지고, 그 아래 줄에는 공백으로 K 를 제외한 N – 1 개의 숫자들이 나열 됨

 

#include <stdio.h>
#define SIZE 500000

int main(int arge, char*argv[]) {
    int n;

    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(int i=0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }

    // TODO: n과 partArr를 이용하여, K를 구하라
    return 0;
}
 

정렬되지 않은 숫자들의 모음 파일 ZIP
 

Figure 1 - 실행 예시 및 정답



10.txt: k = 7
100.txt: k = 57
1_000.txt: k = 507
10_000.txt: k = 8072
100_000.txt: k = 96676
500_000.txt: k = 264936

 

3. 핵심 개념
#배열 #정수합 #합의공식 #반복문

 

4. 부가 설명
- 표준입출력: https://www.tutorialspoint.com/cprogramming/c_input_output.htm
- redirection 을 이용한 파일입력: https://www.cs.bu.edu/teaching/c/file-io/intro/
- https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 500000

void prtLostK(int n, int length, int nums[]);
int getTotalVal(int n);
int sumOfArr(int length, int nums[]);

int main(int argc, char *argv[])
{   
    int n;

    scanf("%d", &n);

    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(int i=0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }

    prtLostK(n, lengthOfPartArr, partArr);

    return 0;
}

void prtLostK(int n, int length, int nums[])
{
    int totalVal = getTotalVal(n),
        soa = sumOfArr(length, nums),
        res = totalVal - soa;
    
    printf("K = %d\n", res);
}

int getTotalVal(int n)
{
    int totalVal = n*(n+1)/2;
    return totalVal;
}

int sumOfArr(int length, int nums[])
{
    int total = 0;

    for (size_t i = 0; i < length; i++)
    {
       total += nums[i];
    }
    
    return total;
}