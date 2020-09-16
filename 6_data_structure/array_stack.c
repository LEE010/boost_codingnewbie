/*
1. 미션 제목
배열로 Stack 만들기

 

 

2. 지시문
EDWITH CS50 강좌에서 배운 Stack을 C 언어로 구현해 보겠습니다. Stack을 구현하는 방법은 정말 많은데요, 이번 문제에서는 Stack을 배열을 이용해서 구현하는 방법에 대해서 알아보겠습니다. 아래 표에 함수의 주석 처리된 부분들에 여러분의 코드를 채워 넣어주세요.

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    // 이곳을 채워주세요!
}

int peek(Stack* stack) {
    // 이곳을 채워주세요!
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}


Main 함수를 실행시키면 Stack 출력 결과가 정상적으로 나와야 합니다.
위의 문제라면
10 pushed to stack
20 pushed to stack
30 pushed to stack
40 pushed to stack
40 pop from stack
30 pop from stack
50 pushed to stack
50 pop from stack
20 pop from stack
10 pop from stack
-9999 pop from stack

위와 같은 결과가 나오도록 작성해 주세요. 다양한 숫자와 사례를 만들어서 실험해 보세요!



3. 핵심 개념
#Stack #배열 #Stack 구현
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -9999;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) return -9999;
    return stack->array[stack->top];
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}