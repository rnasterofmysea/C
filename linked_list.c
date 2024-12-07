#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
struct Node {
    int data;
    struct Node *next;
};

// 함수 선언
void createNode(struct Node **head, int data);
void printList(struct Node *head);
void deleteNode(struct Node **head, int index);

int main() {
    struct Node *head = NULL;

    // 노드 추가
    createNode(&head, 10); // 첫 번째 노드
    createNode(&head, 20); // 두 번째 노드
    createNode(&head, 30); // 세 번째 노드

    // 연결 리스트 출력
    printf("연결 리스트 출력:\n");
    printList(head);

    // 노드 삭제 후 출력
    printf("1번째 노드 삭제 후:\n");
    deleteNode(&head, 1);
    printList(head);

    // 동적 메모리 해제
    while (head != NULL) {
        deleteNode(&head, 0);
    }

    return 0;
}

// 연결 리스트 끝에 노드 추가
void createNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    // 리스트가 비어 있는 경우, 새로운 노드를 첫 노드로 설정
    if (*head == NULL) {
        *head = newNode;
    } else {
        // 리스트 끝으로 이동하여 새로운 노드를 추가
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 연결 리스트 출력
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 특정 위치의 노드 삭제
void deleteNode(struct Node **head, int index) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;

    // 첫 번째 노드 삭제
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // 원하는 위치까지 이동
    struct Node *prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            printf("Index out of range.\n");
            return;
        }
    }

    // 노드 삭제
    prev->next = temp->next;
    free(temp);
}
