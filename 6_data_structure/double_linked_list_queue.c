#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node *prev;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

void queue_init(Queue *queue);
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);

int main(void)
{
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    
    queue_init(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("%d dequeued from queue\n\n", dequeue(queue));
}

void queue_init(Queue *queue) 
{
    queue->front = (Node *)malloc(sizeof(Node));
    queue->rear = (Node *)malloc(sizeof(Node));

    queue->front->val = -1;
    queue->front->prev = NULL;
    queue->front->next = queue->rear;
    
    queue->rear->val = -1;
    queue->rear->prev = queue->front;
    queue->rear->next = NULL;
    
    queue->size = 0;
}

void enqueue(Queue *queue, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *last_node = queue->rear->prev;

    new_node->val = val;    
    new_node->prev = last_node;
    new_node->next = queue->rear;

    last_node->next = new_node;
    queue->rear->prev = new_node;

    queue->size++;
    printf("%d enqueued to queue\n", val);
} 

int dequeue(Queue *queue)
{
    if (queue->size == 0) return -9999;
    
    Node *target_node = queue->front->next;
    Node *next_front_node = target_node->next;
    int val = target_node->val;

    queue->front->next = next_front_node;
    next_front_node->prev = queue->front;
    
    free(target_node);
    queue->size--;
    return val;   
}
