/*
1. 미션 제목
뒤에서 k번째 노드는 무엇일까요?

 

 

2. 지시문

이번에는 연결리스트의 응용 문제를 풀어보겠습니다. 연결리스트가 하나 주어졌을 때 해당 연결 리스트의 뒤에서 k번째 노드의 값은 무엇일지 알아낼 수 있을까요? 예를 들어, 9->8->4->14->5 라는 리스트가 주어질 때 뒤에서 2번째 노드를 출력하라고 하면 14가 출력이 되어야 합니다.
연결리스트가 이미 만들어져 있다고 가정하고, 아래와 같은 함수가 주어졌을 때 뒤에서 k번째 노드를 출력할 수 있을까요?


typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    // 이 부분을 작성해 주세요!
}

int getLastNode (Node* head, int k) {
    // 이 부분을 작성해 주세요!
}

void printList(Node* head) {
    // 이 부분을 작성해 주세요!
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}
 

main 함수에는 정렬된 연결 리스트 1개가 미리 만들어져 있다고 가정합니다. 여러분이 작성하신 함수 getLastNode 함수에 main 함수에서 작성된 연결 리스트와 k를 파라미터로 주었을 때 뒤에서 k 번쨰 노드의 값이 나올 수 있을까요?



입력값:

미리 작성된 연결리스트와 k번째를 지칭하는 파라미터, 예들 들어 9->8->4->14->5 라는 리스트가 main 함수에 작성되어 있고, main 함수에서 해당 리스트와 k=2로 getLastNode를 호출


출력값:
9 8 4 14 5
2th last node is 14


3. 핵심 개념
#연결리스트 #리스트 삽입 #Slow Pointer #Fast Pointer
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    Node* lastNode = head;
    Node* node = (Node*)malloc(sizeof(Node));
    
    while (lastNode->next != NULL) lastNode = lastNode->next;
    
    node->data = data;
    lastNode->next = node;
}

int getLastNode (Node* head, int k) {
    Node* temp = head->next;
    while (temp)
    {
        Node* temp2 = temp;
        for (size_t i = 0; i < k; i++)
        {
            if(temp2) temp2 = temp2->next;
            else return -9999;
        }
        if (!temp2) return temp->data;
        else temp = temp->next;
    }
    return -9999;
}

void printList(Node* head) {
    printf("[ ");
    Node* temp = head->next;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("]\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);
    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}