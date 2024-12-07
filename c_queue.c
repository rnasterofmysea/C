#include <stdio.h>
#include <stdlib.h>

// 함수 push , pop, size, emty, fornt, back
void push(int* head, int* queue, int value);
void pop(int head, int* rear, int* queue);
void size(int head, int rear);
void empty(int head, int rear);
void front(int head, int rear, int* queue);
void back(int head, int rear, int* queue );

int main() {

    // 주어지는 명령의 수 N
    int N = 0;
    scanf("%d", &N);

    // 큐 생성 (배열로 구현)
    int* queue = (int *)malloc(N * sizeof(int));
    int rear = 0;
    int head = 0;

    // 입력받기
    char input[7];
    int input_v = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%s", input);
        if(input[1] == 'u'){
            scanf("%d", &input_v);
            push(&head, queue, input_v);
        } else if(input[1] == 'o'){
            pop(head, &rear, queue);
        } else if(input[1] == 'i'){
            size(head, rear);
        }else if(input[1] == 'm'){
            empty(head, rear);
        } else if(input[1] == 'r'){
            front(head, rear, queue);
        } else if(input[1] == 'a'){
            back(head, rear, queue);
        }
    }
    
    free(queue);
    
    return 0;
}

void push(int* head, int* queue, int value){
    queue[*head] = value;
    (*head) ++;
    // printf("%d\n", value);
}

void pop(int head, int* rear, int* queue){

    if(head - *rear == 0){
        printf("-1\n");
    } else{
        int pop_result = queue[*rear];
        printf("%d\n", pop_result);
        queue[*rear] = '\0';
        (*rear) ++;
    }
}
void size(int head, int rear){
    printf("%d\n", head - rear);
}
void empty(int head, int rear){
    if(head - rear == 0){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
void front(int head, int rear, int* queue){
    if(head - rear ==0){
        printf("-1\n");
    } else{
        printf("%d\n", queue[rear]);
    }
}
void back(int head, int rear, int* queue ){
    if(head - rear ==0){
        printf("-1\n");
    } else{
        printf("%d\n", queue[head-1]);
    }
}