/*
1. 미션 제목
중복 빼고 정렬하기

2. 지시문

    N개의 정수가 주어진다. 이때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한번만 출력한다.


    조건 및 질문
       - 구현체를 위 문제은행에 제출하여 성공하시오
       - 본인의 구현체의 시간복잡도를 구하시요
       - 해당 문제에서 본인의 구현체보다 빠른 답이 있을까요?


3. 핵심 개념
    #정렬 #중복 #빅오표기법 #big O notation

4. 부가 설명
    - 여러 정렬 방법: https://www.geeksforgeeks.org/sorting-algorithms/
    - Big O notation: https://en.wikipedia.org/wiki/Big_O_notation
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} Node;

Node *init_node(int val);
void insert_node(Node **node, int val);
void print(Node *root);
void inorder(Node *node);

int main(void)
{
    int N, temp;
    Node *root = NULL;

    scanf("%d", &N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        insert_node(&root, temp);
    }

    print(root);
}

Node *init_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_node(Node **node, int val)
{
    if (*node == NULL)
    {
        *node = init_node(val);
        return;
    }
    if ((*node)->val == val)
        return;
    else if ((*node)->val > val)
        insert_node(&((*node)->left), val);
    else
        insert_node(&((*node)->right), val);
}

void print(Node *root)
{
    printf("[");
    inorder(root);
    printf(" ]\n");
}

void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf(" %d", node->val);
    inorder(node->right);
}

/*
중복값 허용하지 않는 이진 탐색 트리를 이용하였고, 중위 순회를 하여 정렬된 값을 출력하도록 구현하였습니다.

1) 해당 구현체의 시간복잡도를 구하시오.

트리 최적화가 이루어 지지 않았기 때문에 노드 삽입 복잡도는 O(n),

중위 순회시 시간 복잡도 O(n) 입니다.

따라서 n개의 노드 삽입과 순회는

n*O(n) + O(n) 이며 구현체의 시간 복잡도는 O(n^2) 입니다.

2) 해당 문제에서 본인의 구현체보다 빠른 답이 있을까요?

현재 구현체는 기본적인 탐색 트리로 구현되어 있습니다.

이진 탐색 트리의 삽입 성능은 트리의 높이와 관련 있으므로, Red Black Tree 와 같은 자가 균형 이진 탐색 트리를 활용하여 높이에 대해 최적화를 해준다면 삽입 복잡도를 O(logn)으로 낮출 수 있어 최종 복잡도 O(nlogn)으로 구현할 수 있을 것 같습니다.
*/