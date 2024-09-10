#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define MAX_SIZE 10
#define NULL_INDEX -1

struct Node {
    int data;
    int next;
};

struct ArrayList {
    struct Node nodes[MAX_SIZE];
    int head;
    int top;
    int rear;
    int size;
};

void init(struct ArrayList* list) {
    list->head = NULL_INDEX;
    list->top = NULL_INDEX;
    list->rear = NULL_INDEX;
    list->size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        list->nodes[i].next = NULL_INDEX;
    }
}

void push(struct ArrayList* list, int data) {
    if (list->size == MAX_SIZE) {
        printf("������ ���� á���ϴ�.\n");
        return;
    }

    list->nodes[list->size].data = data;

    if (list->top == NULL_INDEX) {
        list->top = list->size;
        list->head = list->size;
    }
    else {
        list->nodes[list->size].next = list->top;
        list->top = list->size;
    }

    list->size++;
}

int pop(struct ArrayList* list) {
    if (list->top == NULL_INDEX) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return -1;
    }

    int data = list->nodes[list->top].data;
    int next = list->nodes[list->top].next;
    list->top = next;
    list->size--;

    return data;
}

void enqueue(struct ArrayList* list, int data) {
    if (list->size == MAX_SIZE) {
        printf("ť�� ���� á���ϴ�.\n");
        return;
    }

    list->nodes[list->size].data = data;

    if (list->rear == NULL_INDEX) {
        list->rear = list->size;
        list->head = list->size;
    }
    else {
        list->nodes[list->rear].next = list->size;
        list->rear = list->size;
    }

    list->size++;
}

int dequeue(struct ArrayList* list) {
    if (list->head == NULL_INDEX) {
        printf("ť�� ��� �ֽ��ϴ�.\n");
        return -1;
    }

    int data = list->nodes[list->head].data;
    int next = list->nodes[list->head].next;
    list->head = next;
    list->size--;

    return data;
}

void printQueue(struct ArrayList* list) {
    if (list->head == NULL_INDEX) {
        printf("ť�� ��� �ֽ��ϴ�.\n");
        return;
    }

    int current = list->head;
    while (current != NULL_INDEX) {
        printf("%d ", list->nodes[current].data);
        current = list->nodes[current].next;
    }
    printf("\n");
}

void printStack(struct ArrayList* list) {
    if (list->top == NULL_INDEX) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return;
    }

    int current = list->top;
    while (current != NULL_INDEX) {
        printf("%d ", list->nodes[current].data);
        current = list->nodes[current].next;
    }
    printf("\n");
}

int main() {
    struct ArrayList list;
    init(&list);

    int arr[3];

    printf("3���� ������ �Է��ϼ���: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        push(&list, arr[i]);
        enqueue(&list, arr[i]);
    }

    printf("������ ����: ");
    printStack(&list);

    printf("ť�� ����: ");
    printQueue(&list);

    printf("���ÿ��� ���� ��: %d\n", pop(&list));
    printf("���ÿ��� ���� ��: %d\n", pop(&list));

    printf("ť���� ���� ��: %d\n", dequeue(&list));
    printf("ť���� ���� ��: %d\n", dequeue(&list));

    return 0;
}
