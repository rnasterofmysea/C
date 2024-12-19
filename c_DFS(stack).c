#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;            // 연결된 노드 번호
    struct Node* next;     // 다음 노드를 가리키는 포인터
} Node;

Node* adjList[MAX];        // 그래프의 인접 리스트
int visited[MAX];          // 방문 여부
int n;                     // 노드의 개수

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void DFS_Stack(int startNode) {
    Stack* stack = createStack();
    push(stack, startNode);

    while (!isEmpty(stack)) {
        int currentNode = pop(stack);

        if (!visited[currentNode]) {
            visited[currentNode] = 1;
            printf("%d ", currentNode);

            Node* temp = adjList[currentNode];
            while (temp != NULL) {
                int nextVertex = temp->vertex;
                if (!visited[nextVertex]) {
                    push(stack, nextVertex);
                }
                temp = temp->next;
            }
        }
    }

    free(stack);
}

int main() {
    int edges, src, dest;

    printf("노드 개수와 간선 개수를 입력하세요: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        printf("간선 (출발 노드, 도착 노드)을 입력하세요: ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
        addEdge(dest, src);  // 무방향 그래프
    }

    printf("DFS (스택) 탐색 결과: ");
    DFS_Stack(0);
    printf("\n");

    return 0;
}