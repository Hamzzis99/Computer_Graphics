#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 1. List 구조체 정의
typedef struct {
    int x;
    int y;
    int z;
    int isOccupied; // 1: 사용 중, 0: 빈 자리
} List;

// 2. 스택 구조체 정의 (삭제를 위한 스택)
#define STACK_MAX 20

typedef struct {
    List data[STACK_MAX];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int isStackFull(Stack* s) {
    return s->top == STACK_MAX - 1;
}

// 스택에 데이터 추가 (Push)
int push(Stack* s, List coord) {
    if (isStackFull(s)) {
        printf("스택이 가득 찼습니다.\n");
        return -1;
    }
    s->data[++(s->top)] = coord;
    return 0;
}

// 스택에서 데이터 제거 (Pop)
int pop(Stack* s, List* coord) {
    if (isStackEmpty(s)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    *coord = s->data[(s->top)--];
    return 0;
}

// 3. 큐 구조체 정의 (미래 확장을 위한 도구)
#define QUEUE_MAX 20

typedef struct {
    List data[QUEUE_MAX];
    int front;
    int rear;
    int size;
} Queue;

// 큐 초기화
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// 큐가 비었는지 확인
int isQueueEmpty(Queue* q) {
    return q->size == 0;
}

// 큐가 가득 찼는지 확인
int isQueueFull(Queue* q) {
    return q->size == QUEUE_MAX;
}

// 큐에 데이터 추가 (Enqueue)
int enqueue(Queue* q, List coord) {
    if (isQueueFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return -1;
    }
    q->data[q->rear] = coord;
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->size++;
    return 0;
}

// 큐에서 데이터 제거 (Dequeue)
int dequeue(Queue* q, List* coord) {
    if (isQueueEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    *coord = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_MAX;
    q->size--;
    return 0;
}

// 4. 배열 기반 리스트 정의
#define ARRAY_MAX 20

typedef struct {
    List data[ARRAY_MAX];
    int size;
} ArrayList;

// 배열 리스트 초기화
void initArrayList(ArrayList* list) {
    list->size = 0;
    // 초기에는 모든 자리를 비워둡니다.
    for (int i = 0; i < ARRAY_MAX; i++) {
        list->data[i].x = 0;
        list->data[i].y = 0;
        list->data[i].z = 0;
        list->data[i].isOccupied = 0;
    }
}

// 배열 리스트에 데이터 추가 (빈 자리에 추가)
int addArrayList(ArrayList* list, List coord) {
    // 빈 자리를 찾아서 추가
    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 0) {
            list->data[i] = coord;
            list->data[i].isOccupied = 1;
            list->size++;
            return 0;
        }
    }
    printf("배열 리스트에 빈 자리가 없습니다.\n");
    return -1;
}

// 배열 리스트에서 데이터 삭제 (맨 끝에서 삭제)
int RemoveList(ArrayList* list, List* coord) {
    if (list->size == 0) {
        printf("배열 리스트가 비어있습니다.\n");
        return -1;
    }
    // 맨 끝에서부터 첫 번째 사용 중인 좌표를 찾아 삭제
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
    printf("삭제할 좌표가 없습니다.\n");
    return -1;
}

// 배열 리스트에서 맨 아래 데이터 삭제 (FirstDeleteList 명령어)
int FirstDeleteList(ArrayList* list, List* coord) {
    if (list->size == 0) {
        printf("배열 리스트가 비어있습니다.\n");
        return -1;
    }

    // 맨 아래(첫 번째 사용 중인 자리)를 찾아 삭제
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

    printf("삭제할 좌표가 없습니다.\n");
    return -1;
}

// 배열 리스트 완전 초기화 (clearList 명령어)
void clearList(ArrayList* list) {
    for (int i = 0; i < ARRAY_MAX; i++) {
        list->data[i].x = 0;
        list->data[i].y = 0;
        list->data[i].z = 0;
        list->data[i].isOccupied = 0;
    }
    list->size = 0;
}

// 배열 리스트의 길이 출력 (PirntList 명령어)
void PirntList(ArrayList* list) {
    printf("리스트의 길이: %d\n", list->size);
}

// 배열 리스트에서 원점에서 가장 먼 좌표 찾기 (FindMaximum 명령어)
int FindMaximum(ArrayList* list, List* furthestCoord) {
    if (list->size == 0) {
        printf("리스트가 비어있습니다.\n");
        return -1;
    }

    double maxDistance = -1.0;
    int found = 0;

    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 1) {
            // 사용자 제안: (x + y + z) / 3
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

    printf("원점에서 가장 먼 좌표를 찾을 수 없습니다.\n");
    return -1;
}

// 배열 리스트에서 원점에서 가장 가까운 좌표 찾기 (FindMinimum 명령어)
int FindMinimum(ArrayList* list, List* closestCoord) {
    if (list->size == 0) {
        printf("리스트가 비어있습니다.\n");
        return -1;
    }

    double minDistance = INFINITY;
    int found = 0;

    for (int i = 0; i < ARRAY_MAX; i++) {
        if (list->data[i].isOccupied == 1) {
            // 사용자 제안: (x + y + z) / 3
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

    printf("원점에서 가장 가까운 좌표를 찾을 수 없습니다.\n");
    return -1;
}

// 좌표 간 비교를 위한 함수 (오름차순, BubbleAscending)
int BubbleAscending(List a, List b) {
    double distanceA = (a.x + a.y + a.z) / 3.0;
    double distanceB = (b.x + b.y + b.z) / 3.0;
    if (distanceA > distanceB) return 1;
    if (distanceA < distanceB) return -1;
    return 0;
}

// 좌표 간 비교를 위한 함수 (내림차순, BubbleDescending)
int BubbleDescending(List a, List b) {
    double distanceA = (a.x + a.y + a.z) / 3.0;
    double distanceB = (b.x + b.y + b.z) / 3.0;
    if (distanceA < distanceB) return 1;
    if (distanceA > distanceB) return -1;
    return 0;
}

// 배열 리스트를 오름차순으로 정렬 (BubbleAscending)
void sortArrayListAscending(ArrayList* list) {
    if (list->size <= 1) {
        printf("정렬할 좌표가 충분하지 않습니다.\n");
        return;
    }

    // 버블 정렬 알고리즘
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            // j번째와 (j+1)번째 유효 좌표 찾기
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
                // 스왑할 인덱스 찾기
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

    printf("리스트가 오름차순으로 정렬되었습니다.\n");

    // 정렬된 리스트 출력
    printf("\n--- 오름차순으로 정렬된 데이터 (배열 리스트) ---\n");
    if (list->size == 0) {
        printf("  비어있습니다.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            if (list->data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", list->data[i].x, list->data[i].y, list->data[i].z);
            }
        }
    }
}

// 배열 리스트를 내림차순으로 정렬 (BubbleDescending)
void sortArrayListDescending(ArrayList* list) {
    if (list->size <= 1) {
        printf("정렬할 좌표가 충분하지 않습니다.\n");
        return;
    }

    // 버블 정렬 알고리즘
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            // j번째와 (j+1)번째 유효 좌표 찾기
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
                // 스왑할 인덱스 찾기
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

    printf("리스트가 내림차순으로 정렬되었습니다.\n");

    // 정렬된 리스트 출력
    printf("\n--- 내림차순으로 정렬된 데이터 (배열 리스트) ---\n");
    if (list->size == 0) {
        printf("  비어있습니다.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            if (list->data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", list->data[i].x, list->data[i].y, list->data[i].z);
            }
        }
    }
}

// 5. 메인 함수
int main() {
    // 자료구조 초기화
    Stack stack;
    initStack(&stack);

    Queue queue;
    initQueue(&queue);

    ArrayList arrayList;
    initArrayList(&arrayList);

    char command[10];
    int x, y, z;

    printf("좌표를 추가하려면 '+ x y z' 형식으로 입력하세요.\n");
    printf("좌표를 삭제하려면 '-' 또는 'd'를 입력하세요.\n");
    printf("리스트의 길이를 확인하려면 'l'을 입력하세요.\n");
    printf("리스트를 초기화하려면 'c'를 입력하세요.\n");
    printf("원점에서 가장 먼 좌표를 찾으려면 'm'을 입력하세요.\n");
    printf("원점에서 가장 가까운 좌표를 찾으려면 'n'을 입력하세요.\n");
    printf("좌표를 오름차순으로 정렬하려면 'a'를 입력하세요.\n");
    printf("좌표를 내림차순으로 정렬하려면 's'를 입력하세요.\n");
    printf("프로그램을 종료하려면 'exit'을 입력하세요.\n");

    while (1) {
        printf("명령 입력: ");
        if (scanf("%s", command) != 1) {
            printf("입력 오류.\n");
            // 입력 버퍼 비우기
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // 종료 명령 처리
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // '+' 명령어 처리
        if (strcmp(command, "+") == 0) {
            // 세 정수 입력 받기
            if (scanf("%d %d %d", &x, &y, &z) != 3) {
                printf("잘못된 입력 형식입니다. 예: + 1 2 3\n");
                // 입력 버퍼 비우기
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }

            List coord = { x, y, z, 1 };
            int result = 0;

            // 배열 리스트에 데이터 추가
            result = addArrayList(&arrayList, coord);

            // 성공적으로 추가되었으면 스택에 추가
            if (result == 0) {
                result = push(&stack, coord);
                if (result == 0) {
                    printf("좌표가 배열 리스트에 추가되었습니다.\n");
                }
            }
        }
        // '-' 명령어 처리 (스택을 이용한 삭제)
        else if (strcmp(command, "-") == 0) {
            List removedCoord;
            printf("좌표를 삭제 중...\n");
            // 스택에서 데이터 삭제
            if (pop(&stack, &removedCoord) == 0) {
                // 배열 리스트에서도 해당 데이터를 삭제 (맨 끝에서 삭제)
                if (RemoveList(&arrayList, &removedCoord) == 0) {
                    printf("삭제된 좌표: (%d, %d, %d)\n", removedCoord.x, removedCoord.y, removedCoord.z);
                }
            }
        }
        // 'd' 명령어 처리 (맨 아래 삭제)
        else if (strcmp(command, "d") == 0) {
            List removedCoord;
            printf("좌표를 삭제 중...\n");
            // 배열 리스트에서 맨 아래 데이터 삭제
            if (FirstDeleteList(&arrayList, &removedCoord) == 0) {
                printf("삭제된 좌표: (%d, %d, %d)\n", removedCoord.x, removedCoord.y, removedCoord.z);
                // 스택에서도 해당 좌표를 찾아 삭제
                int found = 0;
                for (int i = stack.top; i >= 0; i--) {
                    if (stack.data[i].x == removedCoord.x &&
                        stack.data[i].y == removedCoord.y &&
                        stack.data[i].z == removedCoord.z) {
                        // 해당 좌표를 스택에서 삭제 (마지막 요소로 대체)
                        stack.data[i] = stack.data[stack.top];
                        stack.top--;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("스택에서 해당 좌표를 찾지 못했습니다.\n");
                }
            }
        }
        // 'l' 명령어 처리 (리스트 길이 출력)
        else if (strcmp(command, "l") == 0) {
            PirntList(&arrayList);
        }
        // 'm' 명령어 처리 (원점에서 가장 먼 좌표 출력)
        else if (strcmp(command, "m") == 0) {
            List furthestCoord;
            if (FindMaximum(&arrayList, &furthestCoord) == 0) {
                printf("원점에서 가장 먼 좌표: (%d, %d, %d)\n", furthestCoord.x, furthestCoord.y, furthestCoord.z);
            }
        }
        // 'n' 명령어 처리 (원점에서 가장 가까운 좌표 출력)
        else if (strcmp(command, "n") == 0) {
            List closestCoord;
            if (FindMinimum(&arrayList, &closestCoord) == 0) {
                printf("원점에서 가장 가까운 좌표: (%d, %d, %d)\n", closestCoord.x, closestCoord.y, closestCoord.z);
            }
        }
        // 'a' 명령어 처리 (오름차순 정렬)
        else if (strcmp(command, "a") == 0) {
            sortArrayListAscending(&arrayList);
        }
        // 's' 명령어 처리 (내림차순 정렬)
        else if (strcmp(command, "s") == 0) {
            sortArrayListDescending(&arrayList);
        }
        // 'c' 명령어 처리 (리스트 초기화)
        else if (strcmp(command, "c") == 0) {
            clearList(&arrayList);
            // 스택도 초기화
            initStack(&stack);
            printf("리스트가 완전히 초기화되었습니다.\n");
        }
        else {
            printf("알 수 없는 명령입니다. '+', '-', 'd', 'l', 'm', 'n', 'a', 's', 'c', 또는 'exit'을 입력하세요.\n");
            // 입력 버퍼 비우기
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    // 추가된 데이터 출력
    printf("\n--- 추가된 데이터 (배열 리스트) ---\n");
    if (arrayList.size == 0) {
        printf("  비어있습니다.\n");
    }
    else {
        for (int i = 0; i < ARRAY_MAX; i++) {
            // 빈 자리는 출력하지 않음
            if (arrayList.data[i].isOccupied == 1) {
                printf("  (%d, %d, %d)\n", arrayList.data[i].x, arrayList.data[i].y, arrayList.data[i].z);
            }
        }
    }

    printf("프로그램을 종료합니다.\n");
    return 0;
}
