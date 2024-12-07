#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 리스트의 최대 크기

typedef struct LinearList {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int size;           // 현재 리스트에 저장된 데이터 개수
} LinearList;

// 함수 선언
void initializeList(LinearList *list);
void addData(LinearList *list, int value);
void insertData(LinearList *list, int index, int value);
void deleteData(LinearList *list, int index);
void printList(LinearList *list);

int main() {
    LinearList list;
    initializeList(&list);

    // 데이터 추가
    addData(&list, 10);
    addData(&list, 20);
    addData(&list, 30);

    // 리스트 출력
    printf("데이터 추가 후 리스트:\n");
    printList(&list);

    // 데이터 삽입
    insertData(&list, 1, 15); // 인덱스 1에 15 삽입
    printf("데이터 삽입 후 리스트:\n");
    printList(&list);

    // 데이터 삭제
    deleteData(&list, 2); // 인덱스 2의 데이터 삭제
    printf("데이터 삭제 후 리스트:\n");
    printList(&list);

    return 0;
}

// 리스트 초기화
void initializeList(LinearList *list) {
    list->size = 0; // 초기 데이터 개수는 0
}

// 데이터 추가
void addData(LinearList *list, int value) {
    if (list->size >= MAX_SIZE) {
        printf("리스트가 가득 찼습니다. 데이터를 추가할 수 없습니다.\n");
        return;
    }
    list->data[list->size++] = value; // 데이터를 추가하고 size 증가
}

// 데이터 삽입
void insertData(LinearList *list, int index, int value) {
    if (list->size >= MAX_SIZE) {
        printf("리스트가 가득 찼습니다. 데이터를 삽입할 수 없습니다.\n");
        return;
    }
    if (index < 0 || index > list->size) {
        printf("잘못된 인덱스입니다.\n");
        return;
    }

    // 데이터를 오른쪽으로 이동
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = value; // 새 데이터를 삽입
    list->size++;              // 데이터 개수 증가
}

// 데이터 삭제
void deleteData(LinearList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("잘못된 인덱스입니다.\n");
        return;
    }

    // 데이터를 왼쪽으로 이동
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--; // 데이터 개수 감소
}

// 리스트 출력
void printList(LinearList *list) {
    if (list->size == 0) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
