#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 1. List ����ü ����
typedef struct {
    int x;
    int y;
    int z;
    int isOccupied; // 1: ��� ��, 0: �� �ڸ�
} List;

// 2. ���� ����ü ���� (������ ���� ����)
#define STACK_MAX 20

typedef struct {
    List data[STACK_MAX];
    int top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* s) {
    s->top = -1;
}

// ������ ������� Ȯ��
int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// ������ ���� á���� Ȯ��
int isStackFull(Stack* s) {
    return s->top == STACK_MAX - 1;
}

// ���ÿ� ������ �߰� (Push)
int push(Stack* s, List coord) {
    if (isStackFull(s)) {
        printf("������ ���� á���ϴ�.\n");
        return -1;
    }
    s->data[++(s->top)] = coord;
    return 0;
}

// ���ÿ��� ������ ���� (Pop)
int pop(Stack* s, List* coord) {
    if (isStackEmpty(s)) {
        printf("������ ����ֽ��ϴ�.\n");
        return -1;
    }
    *coord = s->data[(s->top)--];
    return 0;
}

// 3. ť ����ü ���� (�̷� Ȯ���� ���� ����)
#define QUEUE_MAX 20

typedef struct {
    List data[QUEUE_MAX];
    int front;
    int rear;
    int size;
} Queue;

// ť �ʱ�ȭ
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// ť�� ������� Ȯ��
int isQueueEmpty(Queue* q) {
    return q->size == 0;
}

// ť�� ���� á���� Ȯ��
int isQueueFull(Queue* q) {
    return q->size == QUEUE_MAX;
}

// ť�� ������ �߰� (Enqueue)
int enqueue(Queue* q, List coord) {
    if (isQueueFull(q)) {
        printf("ť�� ���� á���ϴ�.\n");
        return -1;
    }
    q->data[q->rear] = coord;
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->size++;
    return 0;
}

// ť���� ������ ���� (Dequeue)
int dequeue(Queue* q, List* coord) {
    if (isQueueEmpty(q)) {
        printf("ť�� ����ֽ��ϴ�.\n");
        return -1;
    }
    *coord = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_MAX;
    q->size--;
    return 0;
}

// 4. �迭 ��� ����Ʈ ����
#define ARRAY_MAX 20

typedef struct {
    List data[ARRAY_MAX];
    int size;
} ArrayList;

// �迭 ����Ʈ �ʱ�ȭ
void initArrayList(ArrayList* list) {
    list->size = 0;
    // �ʱ⿡�� ��� �ڸ��� ����Ӵϴ�.
    for (int i = 0; i < ARRAY_MAX; i++) {
        list->data[i].x = 0;
        list->data[i].y = 0;
        list->data[i].z = 0;
        list->data[i].isOccupied = 0;
    }
}

// �迭 ����Ʈ�� ������ �߰� (�� �ڸ��� �߰�)
int addArrayList(ArrayList* list, List coord) {
    // �� �ڸ��� ã�Ƽ� �߰�
    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 0) {
            list->data[i] = coord;
            list->data[i].isOccupied = 1;
            list->size++;
            return 0;
        }
    }
    printf("�迭 ����Ʈ�� �� �ڸ��� �����ϴ�.\n");
    return -1;
}

// �迭 ����Ʈ���� ������ ���� (�� ������ ����)
int RemoveList(ArrayList* list, List* coord) {
    if (list->size == 0) {
        printf("�迭 ����Ʈ�� ����ֽ��ϴ�.\n");
        return -1;
    }
    // �� ���������� ù ��° ��� ���� ��ǥ�� ã�� ����
    for (int i = ARRAY_MAX - 1; i >= 0; i--) {
        if (list->data[i].isOccupied == 1) {
            *coord = list->data[i];
            list->data[i].x = 0;
            list->data[i].y = 0;
            list->data[i].z = 0;
            list->data[i].isOccupied = 0;
            list->size--;
            return 0;
        }
    }
    printf("������ ��ǥ�� �����ϴ�.\n");
    return -1;
}

// �迭 ����Ʈ���� �� �Ʒ� ������ ���� (FirstDeleteList ��ɾ�)
int FirstDeleteList(ArrayList* list, List* coord) {
    if (list->size == 0) {
        printf("�迭 ����Ʈ�� ����ֽ��ϴ�.\n");
        return -1;
    }

    // �� �Ʒ�(ù ��° ��� ���� �ڸ�)�� ã�� ����
    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 1) {
            *coord = list->data[i];
            list->data[i].x = 0;
            list->data[i].y = 0;
            list->data[i].z = 0;
            list->data[i].isOccupied = 0;
            list->size--;
            return 0;
        }
    }

    printf("������ ��ǥ�� �����ϴ�.\n");
    return -1;
}

// �迭 ����Ʈ ���� �ʱ�ȭ (clearList ��ɾ�)
void clearList(ArrayList* list) {
    for (int i = 0; i < ARRAY_MAX; i++) {
        list->data[i].x = 0;
        list->data[i].y = 0;
        list->data[i].z = 0;
        list->data[i].isOccupied = 0;
    }
    list->size = 0;
}

// �迭 ����Ʈ�� ���� ��� (PirntList ��ɾ�)
void PirntList(ArrayList* list) {
    printf("����Ʈ�� ����: %d\n", list->size);
}

// �迭 ����Ʈ���� �������� ���� �� ��ǥ ã�� (FindMaximum ��ɾ�)
int FindMaximum(ArrayList* list, List* furthestCoord) {
    if (list->size == 0) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return -1;
    }

    double maxDistance = -1.0;
    int found = 0;

    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 1) {
            // ����� ����: (x + y + z) / 3
            double distance = (list->data[i].x + list->data[i].y + list->data[i].z) / 3.0;
            if (distance > maxDistance) {
                maxDistance = distance;
                *furthestCoord = list->data[i];
                found = 1;
            }
        }
    }

    if (found) {
        return 0;
    }

    printf("�������� ���� �� ��ǥ�� ã�� �� �����ϴ�.\n");
    return -1;
}

// �迭 ����Ʈ���� �������� ���� ����� ��ǥ ã�� (FindMinimum ��ɾ�)
int FindMinimum(ArrayList* list, List* closestCoord) {
    if (list->size == 0) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return -1;
    }

    double minDistance = INFINITY;
    int found = 0;

    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 1) {
            // ����� ����: (x + y + z) / 3
            double distance = (list->data[i].x + list->data[i].y + list->data[i].z) / 3.0;
            if (distance < minDistance) {
                minDistance = distance;
                *closestCoord = list->data[i];
                found = 1;
            }
        }
    }

    if (found) {
        return 0;
    }

    printf("�������� ���� ����� ��ǥ�� ã�� �� �����ϴ�.\n");
    return -1;
}

// ��ǥ �� �񱳸� ���� �Լ� (��������, BubbleAscending)
int BubbleAscending(List a, List b) {
    double distanceA = (a.x + a.y + a.z) / 3.0;
    double distanceB = (b.x + b.y + b.z) / 3.0;
    if (distanceA > distanceB) return 1;
    if (distanceA < distanceB) return -1;
    return 0;
}

// ��ǥ �� �񱳸� ���� �Լ� (��������, BubbleDescending)
int BubbleDescending(List a, List b) {
    double distanceA = (a.x + a.y + a.z) / 3.0;
    double distanceB = (b.x + b.y + b.z) / 3.0;
    if (distanceA < distanceB) return 1;
    if (distanceA > distanceB) return -1;
    return 0;
}

// �迭 ����Ʈ�� ������������ ���� (BubbleAscending)
void sortArrayListAscending(ArrayList* list) {
    if (list->size <= 1) {
        printf("������ ��ǥ�� ������� �ʽ��ϴ�.\n");
        return;
    }

    // ���� ���� �˰���
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            // j��°�� (j+1)��° ��ȿ ��ǥ ã��
            List coord1, coord2;
            int count1 = 0, count2 = 0;
            for (int k = 0; k < ARRAY_MAX; k++) {
                if (list->data[k].isOccupied == 1) {
                    if (count1 == j) {
                        coord1 = list->data[k];
                        break;
                    }
                    count1++;
                }
            }
            for (int k = 0; k < ARRAY_MAX; k++) {
                if (list->data[k].isOccupied == 1) {
                    if (count2 == j + 1) {
                        coord2 = list->data[k];
                        break;
                    }
                    count2++;
                }
            }

            if (BubbleAscending(coord1, coord2) > 0) {
                // ������ �ε��� ã��
                int index1 = -1, index2 = -1;
                for (int k = 0; k < ARRAY_MAX; k++) {
                    if (list->data[k].isOccupied == 1) {
                        if (list->data[k].x == coord1.x && list->data[k].y == coord1.y && list->data[k].z == coord1.z) {
                            index1 = k;
                        }
                        if (list->data[k].x == coord2.x && list->data[k].y == coord2.y && list->data[k].z == coord2.z) {
                            index2 = k;
                        }
                    }
                }
                if (index1 != -1 && index2 != -1) {
                    List temp = list->data[index1];
                    list->data[index1] = list->data[index2];
                    list->data[index2] = temp;
                }
            }
        }
    }

    printf("����Ʈ�� ������������ ���ĵǾ����ϴ�.\n");

    // ���ĵ� ����Ʈ ���
    printf("\n--- ������������ ���ĵ� ������ (�迭 ����Ʈ) ---\n");
    if (list->size == 0) {
        printf("  ����ֽ��ϴ�.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            if (list->data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", list->data[i].x, list->data[i].y, list->data[i].z);
            }
        }
    }
}

// �迭 ����Ʈ�� ������������ ���� (BubbleDescending)
void sortArrayListDescending(ArrayList* list) {
    if (list->size <= 1) {
        printf("������ ��ǥ�� ������� �ʽ��ϴ�.\n");
        return;
    }

    // ���� ���� �˰���
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            // j��°�� (j+1)��° ��ȿ ��ǥ ã��
            List coord1, coord2;
            int count1 = 0, count2 = 0;
            for (int k = 0; k < ARRAY_MAX; k++) {
                if (list->data[k].isOccupied == 1) {
                    if (count1 == j) {
                        coord1 = list->data[k];
                        break;
                    }
                    count1++;
                }
            }
            for (int k = 0; k < ARRAY_MAX; k++) {
                if (list->data[k].isOccupied == 1) {
                    if (count2 == j + 1) {
                        coord2 = list->data[k];
                        break;
                    }
                    count2++;
                }
            }

            if (BubbleDescending(coord1, coord2) > 0) {
                // ������ �ε��� ã��
                int index1 = -1, index2 = -1;
                for (int k = 0; k < ARRAY_MAX; k++) {
                    if (list->data[k].isOccupied == 1) {
                        if (list->data[k].x == coord1.x && list->data[k].y == coord1.y && list->data[k].z == coord1.z) {
                            index1 = k;
                        }
                        if (list->data[k].x == coord2.x && list->data[k].y == coord2.y && list->data[k].z == coord2.z) {
                            index2 = k;
                        }
                    }
                }
                if (index1 != -1 && index2 != -1) {
                    List temp = list->data[index1];
                    list->data[index1] = list->data[index2];
                    list->data[index2] = temp;
                }
            }
        }
    }

    printf("����Ʈ�� ������������ ���ĵǾ����ϴ�.\n");

    // ���ĵ� ����Ʈ ���
    printf("\n--- ������������ ���ĵ� ������ (�迭 ����Ʈ) ---\n");
    if (list->size == 0) {
        printf("  ����ֽ��ϴ�.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            if (list->data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", list->data[i].x, list->data[i].y, list->data[i].z);
            }
        }
    }
}

// 5. ���� �Լ�
int main() {
    // �ڷᱸ�� �ʱ�ȭ
    Stack stack;
    initStack(&stack);

    Queue queue;
    initQueue(&queue);

    ArrayList arrayList;
    initArrayList(&arrayList);

    char command[10];
    int x, y, z;

    printf("��ǥ�� �߰��Ϸ��� '+ x y z' �������� �Է��ϼ���.\n");
    printf("��ǥ�� �����Ϸ��� '-' �Ǵ� 'd'�� �Է��ϼ���.\n");
    printf("����Ʈ�� ���̸� Ȯ���Ϸ��� 'l'�� �Է��ϼ���.\n");
    printf("����Ʈ�� �ʱ�ȭ�Ϸ��� 'c'�� �Է��ϼ���.\n");
    printf("�������� ���� �� ��ǥ�� ã������ 'm'�� �Է��ϼ���.\n");
    printf("�������� ���� ����� ��ǥ�� ã������ 'n'�� �Է��ϼ���.\n");
    printf("��ǥ�� ������������ �����Ϸ��� 'a'�� �Է��ϼ���.\n");
    printf("��ǥ�� ������������ �����Ϸ��� 's'�� �Է��ϼ���.\n");
    printf("���α׷��� �����Ϸ��� 'exit'�� �Է��ϼ���.\n");

    while (1) {
        printf("��� �Է�: ");
        if (scanf("%s", command) != 1) {
            printf("�Է� ����.\n");
            // �Է� ���� ����
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // ���� ��� ó��
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // '+' ��ɾ� ó��
        if (strcmp(command, "+") == 0) {
            // �� ���� �Է� �ޱ�
            if (scanf("%d %d %d", &x, &y, &z) != 3) {
                printf("�߸��� �Է� �����Դϴ�. ��: + 1 2 3\n");
                // �Է� ���� ����
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }

            List coord = { x, y, z, 1 };
            int result = 0;

            // �迭 ����Ʈ�� ������ �߰�
            result = addArrayList(&arrayList, coord);

            // ���������� �߰��Ǿ����� ���ÿ� �߰�
            if (result == 0) {
                result = push(&stack, coord);
                if (result == 0) {
                    printf("��ǥ�� �迭 ����Ʈ�� �߰��Ǿ����ϴ�.\n");
                }
            }
        }
        // '-' ��ɾ� ó�� (������ �̿��� ����)
        else if (strcmp(command, "-") == 0) {
            List removedCoord;
            printf("��ǥ�� ���� ��...\n");
            // ���ÿ��� ������ ����
            if (pop(&stack, &removedCoord) == 0) {
                // �迭 ����Ʈ������ �ش� �����͸� ���� (�� ������ ����)
                if (RemoveList(&arrayList, &removedCoord) == 0) {
                    printf("������ ��ǥ: (%d, %d, %d)\n", removedCoord.x, removedCoord.y, removedCoord.z);
                }
            }
        }
        // 'd' ��ɾ� ó�� (�� �Ʒ� ����)
        else if (strcmp(command, "d") == 0) {
            List removedCoord;
            printf("��ǥ�� ���� ��...\n");
            // �迭 ����Ʈ���� �� �Ʒ� ������ ����
            if (FirstDeleteList(&arrayList, &removedCoord) == 0) {
                printf("������ ��ǥ: (%d, %d, %d)\n", removedCoord.x, removedCoord.y, removedCoord.z);
                // ���ÿ����� �ش� ��ǥ�� ã�� ����
                int found = 0;
                for (int i = stack.top; i >= 0; i--) {
                    if (stack.data[i].x == removedCoord.x &&
                        stack.data[i].y == removedCoord.y &&
                        stack.data[i].z == removedCoord.z) {
                        // �ش� ��ǥ�� ���ÿ��� ���� (������ ��ҷ� ��ü)
                        stack.data[i] = stack.data[stack.top];
                        stack.top--;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("���ÿ��� �ش� ��ǥ�� ã�� ���߽��ϴ�.\n");
                }
            }
        }
        // 'l' ��ɾ� ó�� (����Ʈ ���� ���)
        else if (strcmp(command, "l") == 0) {
            PirntList(&arrayList);
        }
        // 'm' ��ɾ� ó�� (�������� ���� �� ��ǥ ���)
        else if (strcmp(command, "m") == 0) {
            List furthestCoord;
            if (FindMaximum(&arrayList, &furthestCoord) == 0) {
                printf("�������� ���� �� ��ǥ: (%d, %d, %d)\n", furthestCoord.x, furthestCoord.y, furthestCoord.z);
            }
        }
        // 'n' ��ɾ� ó�� (�������� ���� ����� ��ǥ ���)
        else if (strcmp(command, "n") == 0) {
            List closestCoord;
            if (FindMinimum(&arrayList, &closestCoord) == 0) {
                printf("�������� ���� ����� ��ǥ: (%d, %d, %d)\n", closestCoord.x, closestCoord.y, closestCoord.z);
            }
        }
        // 'a' ��ɾ� ó�� (�������� ����)
        else if (strcmp(command, "a") == 0) {
            sortArrayListAscending(&arrayList);
        }
        // 's' ��ɾ� ó�� (�������� ����)
        else if (strcmp(command, "s") == 0) {
            sortArrayListDescending(&arrayList);
        }
        // 'c' ��ɾ� ó�� (����Ʈ �ʱ�ȭ)
        else if (strcmp(command, "c") == 0) {
            clearList(&arrayList);
            // ���õ� �ʱ�ȭ
            initStack(&stack);
            printf("����Ʈ�� ������ �ʱ�ȭ�Ǿ����ϴ�.\n");
        }
        else {
            printf("�� �� ���� ����Դϴ�. '+', '-', 'd', 'l', 'm', 'n', 'a', 's', 'c', �Ǵ� 'exit'�� �Է��ϼ���.\n");
            // �Է� ���� ����
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    // �߰��� ������ ���
    printf("\n--- �߰��� ������ (�迭 ����Ʈ) ---\n");
    if (arrayList.size == 0) {
        printf("  ����ֽ��ϴ�.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            // �� �ڸ��� ������� ����
            if (arrayList.data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", arrayList.data[i].x, arrayList.data[i].y, arrayList.data[i].z);
            }
        }
    }

    printf("���α׷��� �����մϴ�.\n");
    return 0;
}
