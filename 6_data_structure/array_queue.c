/*
1. 미션 제목
배열로 Queue 만들어보기!

 

 

2. 지시문

이번 과제에서는 Queue를 구현해 봅시다! Stack 과 Queue의 구현은 얼핏 보면 비슷해 보이지만 막상 구현해 보면 많은 부분이 다르답니다. 어떻게 구현하면 좋을지 고민이 많이 필요할 수도 있습니다. 이미 구현된 부분들을 잘 살피고 어떤 식으로 구현해야 할 지 생각해서 채워주세요.

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; // 왜 이렇게 초기화 했는지 잘 생각해 보세요!
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
// 이 부분을 구현해 주세요!
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -9999;
    }
    Int item = 0;
    // 이 부분을 구현해 주세요!
    return item;
}


int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    return 0;
}
 

위의 Main 함수를 실행시키면 Queue 출력 결과가 아래와 같이 나와야 합니다.


10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
40 enqueued to queue
10 dequeued from queue

Front item is 20
Rear item is 40


Queue 도 연결리스트를 이용해서 구현할 수도 있습니다. 과제와 상관없이 Queue를 연결리스트로도 구현해 보면 어떨까요?


3. 핵심 개념
#Queue #연결리스트 #Queue 구현
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(sizeof(int) * queue->capacity);
    return queue;
}

int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        return;
    }
    queue->rear++; 
    queue->rear %= (queue->capacity);
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        return -9999;
    }
    int item = 0;
    item = queue->array[queue->front++];
    queue->front %= (queue->capacity);
    queue->size--;
    return item;
}

int main()
{
    Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    return 0;
}