/*
1. 미션 제목
최단 시간에 다리건너기

 

 

2. 지시문
N명의 사람들로 구성된 한 그룹이 밤중에 다리를 건너려고 합니다. 한 번에 최대 두 명 까지만 다리를 건널 수 있으며 다리 위를 지나가는 사람들은 반드시 손전등을 가지고 가야 합니다. n명의 사람들한테는 손전등이 한 개밖에 없기 때문에 남아 있는 사람들이 다리를 건너려면 어떤 식으로든 손전등을 가지고 다시 다리를 건너지 않은 사람들이 있는 곳으로 돌아가는 일을 해야합니다. 사람마다 다리를 건너는 속도가 다른데, 그룹의 속도는 가장 느린 구성원의 속도에 따라 결정됩니다. 가장 짧은 시간 안에 n명이 모두 다리를 건널 수 있는 방법과 그 시간을 출력하는 프로그램을 작성해봅시다.


입력으로 첫 줄에는 n이 입력되며 그 다음 줄부터 n개의 줄에 걸쳐서 각 사람들이 다리를 건너는 시간이 입력됩니다. 입력은 100명을 넘기지 않습니다.


출력은 맨 첫 줄에는 n명의 사람들이 모두 다리를 건너는데 걸리는 총 시간을 출력하고, 그 다음줄부터는 그 과정을 출력하면 됩니다. 이 때 각 줄에는 정수가 하나 또는 두 개가 들어가는데, 이 정수는 어떤 사람들이 다리를 건너가는지를 나타냅니다. 각 사람은 그 사람이 건너가는데 걸리는 시간으로 표시하며, 건너가고 오는 순서대로 출력해야 합니다. 최소 시간을 달성하는 방법이 여러가지가 있을 경우 그 중 아무 방법이나 출력해도 괜찮습니다. 완전한 프로그램을 작성하기 어려운 경우에는 pseudo code를 작성해도 좋습니다. 다만 이 경우에는 최대한 자세히 적어야 합니다. 숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 내부에서 따로 선언하는 것으로 가정합니다.


예)
입력값:
4
1
2
5
10


출력값:
17
1 2
1
5 10
2
1 2



3. 핵심 개념
#정렬알고리즘

 

* 본 문제의 경우 문제를 푸는데 도움이 되는 힌트가 있습니다. 알고리즘의 경우 방법을 직접 고민해보고 찾는 것이 중요합니다. 때문에 고민을 하시다가 도저히 풀 수가 없을때 아래의 힌트를 참고해주시길 바랍니다.

 

-> '         ' 사이를 마우스로 블록을 하면 힌트가 나옵니다.

 '각 사람들이 다리를 건너는 시간에 따라서 예)에 있는 출력값과 같은 방법으로 다리를 건너는 것이 최선이 아닌 경우도 있습니다. 어떤 경우에 그렇게 되는지, 그리고 그 때는 어떤 방법으로 다리를 건너는 것이 최선인지 생각해봅시다'

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void insert_sort(int n, int arr[]);
void swap(int *a, int *b);
void queue_init(Queue *queue);
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
int max(int a, int b);

int main(void)
{
    int n = 0, arr[MAX];
    int res = 0;
    Queue *before = (Queue *)malloc(sizeof(Queue));
    Queue *after = (Queue *)malloc(sizeof(Queue));
    
    queue_init(before);
    queue_init(after);
 
    scanf("%d", &n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    insert_sort(n,arr);

    for (size_t i = 0; i < n; i++)
    {
        enqueue(before, arr[i]);
    }

    while (after->size < n)
    {
        int a = dequeue(before), b = dequeue(before);
        
        if (a > b) swap(&a, &b);
        
        res += b;
        printf("%d %d\n", a, b);

        enqueue(after, b);

        if (before->size > 0)
        {
            enqueue(before, a);
            printf("%d\n", a);
        }
        else break;
        
    }

    printf("%d\n", res);
}

void insert_sort(int n, int arr[])
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
} 

int dequeue(Queue *queue)
{
    if (queue->size == 0) return -1;
    
    Node *target_node = queue->front->next;
    Node *next_front_node = target_node->next;
    int val = target_node->val;

    queue->front->next = next_front_node;
    next_front_node->prev = queue->front;
    
    free(target_node);
    queue->size--;
    return val;   
}
