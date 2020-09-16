/*
✔︎ 문제 3. Queue를 만들어보자!

 

1. 미션 제목
Queue 를 만들어 보자!

 

2. 지시문
배열을 이용하여 Queue 를 만들어 보자.
특정 업무를 할 때, 우리는 일을 들어온 순서대로 해야할 때가 있다. 은행 업무를 예를 들어보자. 은행업무를 보기 위한 고객들이 10명이 있다고 치고, 각자 대기표가 있다. 그럼 은행원들은 각자 업무가 끝나면 대기한 고객을 순서대로 뽑아야 할 것이다. 이때 필요한 것이 Queue 이다. (1) 대기표를 뽑는다 (Queue 에 데이터를 삽입). (2) 대기인원을 보여준다 (queue 에 쌓여있는 데이터 조회). (3) 순서대로 대기인원을 호출한다 (queue 를 하나씩 pop 한다).


- Queue 자료구조를 array를 이용해 구현
1. add (1), pop (2), display (3), quit (4) 기능 구현
2. 입력 한 옵션 (1, 2, 3, 4) 에 따라 switch 문을 사용하여 각각의 기능을 수행하도록 구현
3. 필요한 함수 목록: insert(), delete(), display()
    - 각 함수의 파라미터는 필요하면 정의하기
4. add() 함수의 정의
    - queue 가 꽉찼는지 확인 (Queue 의 max 크기는 10으로 정의), queue 가 꽉찼으면 “Queue가 꽉 찼습니다.” 를 출력
    - queue 에 삽입이 가능하면, 값을 입력 받아 queue 배열에 삽입 (hint: front, rear 변수를 사용하여 queue 의 현재 위치를 저장한다)
5. pop() 함수의 정의
    - queue 가 비었는지 확인, 비었으면 “Queue가 비었습니다.” 를 출력
    - queue 가 비어있지 않으면, 가장 먼저 들어온 순서로 값을 하나 가져와 출력 (hint: front 변수값 조정 필요)
6. display() 함수의 정의
    - 반복문을 사용하여 배열의 모든 요소를 출력 (hint: front, rear 변수 범위로 배열값을 출력)

 

TODO: 여기서 출력 예시 보여주기

 

3. 핵심 개념 (키워드 제시)
#배열 #Queue #switch문 #반복문 #표준입출력

 

4. 부가 설명 (만약 존재한다면)
- Queue: https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
- switch: https://docs.microsoft.com/ko-kr/cpp/c-language/switch-statement-c?view=vs-2019
- 표준입출력: https://www.tutorialspoint.com/cprogramming/c_input_output.htm
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10
#define ADD 0
#define POP 1
#define DISPLAY 2
#define QUIT 3

void insert(int queue[], int *front, int *rear);
void delete(int queue[], int *front, int *rear);
void display(int queue[], int *front, int *rear);
int input_val(void);
void relocQueue(int arr[], int *front, int *rear);

int main(void)
{
    int queue[MAX];
    int cmd,
        front = 0, 
        rear = 0;
    bool run = true;

    while(run)
    {
        printf("0: add, 1: pop, 2: display, 3: quit\n");
        scanf("%d", &cmd);

        switch (cmd)
        {
        case ADD:
            insert(queue, &front, &rear);
            break;
        
        case POP:
            delete(queue, &front, &rear);
            break;
        
        case DISPLAY:
            display(queue, &front, &rear);
            break;
        
        case QUIT:
            run = false;
            break;
        
        default:
            printf("잘못된 입력.\n");
            break;
        }
    }

    return 0;
}

void insert(int queue[], int *front, int *rear)
{   

    if (*front == 0 && *rear == MAX)
    {
        printf("Queue가 꽉 찼습니다.\n");
        return;
    } else if (*rear == MAX || *front == MAX)
    {
        relocQueue(queue, front, rear);
    }
    
    int val = input_val();

    queue[(*rear)++] = val; 

}

void delete(int queue[], int *front, int *rear)
{
    if (*front == *rear)
    {
        printf("Queue가 비었습니다.\n");
        return;
    } else {
        printf("%d pop!\n",queue[(*front)++]);
    }
}

void display(int queue[], int *front, int *rear)
{
    printf("%d %d\n",*front,*rear);
    printf("[");
    for (size_t i = *front; i < *rear; i++)
    {
        printf(" %d", queue[i]);
    }
    printf(" ]\n");
}

int input_val(void)
{
    int input;
    printf("값 입력 : ");
    scanf("%d", &input);
    return input;
}

void relocQueue(int arr[], int *front, int *rear)
{
    int queue[MAX],
        i = 0;

    for (size_t j = *front; j <= *rear; j++)
    {
        queue[i++] = arr[j];
    }

    arr = queue;
    *rear -= *front;
    *front = 0;
}
