#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 각 버퍼를 정의할 구조체
typedef struct {
    int values[3];  // 정수 3개를 저장할 배열
} Buffer;

#define MAX_BUFFERS 10 // 최대 버퍼 개수

Buffer list[MAX_BUFFERS]; // 구조체 배열
int count = 0;            // 버퍼 개수를 저장하는 전역 변수

// 새로운 버퍼를 배열에 추가하는 함수
void add(Buffer buffer) {
    if (count < MAX_BUFFERS) {
        list[count] = buffer; // 구조체 전체를 배열에 저장
        count++;
    }
    else {
        printf("리스트가 가득 찼습니다.\n");
    }
}

// 마지막 버퍼를 삭제하는 함수 (pop)
void pop() {
    if (count > 0) {
        count--;
        printf("맨 아래 데이터가 삭제되었습니다.\n");
    }
    else {
        printf("삭제할 데이터가 없습니다.\n");
    }
}

// 맨 위 버퍼를 삭제하는 함수 (dequeue)
void dequeue() {
    if (count > 0) {
        for (int i = 1; i < count; i++) {
            list[i - 1] = list[i]; // 다음 버퍼를 앞으로 이동
        }
        count--;
        printf("맨 위 데이터가 삭제되었습니다.\n");
    }
    else {
        printf("삭제할 데이터가 없습니다.\n");
    }
}

// 리스트 전부 삭제하는 함수
void clear() {
    count = 0;
    printf("리스트가 모두 삭제되었습니다. 처음으로 돌아갑니다.\n");
}

// 현재 리스트를 출력하는 함수
void display() {
    if (count == 0) {
        printf("리스트가 비어 있습니다.\n");
    }
    else {
        printf("현재 리스트 상태:\n");
        for (int i = 0; i < count; i++) {
            printf("버퍼 %d: (%d, %d, %d)\n", i + 1, list[i].values[0], list[i].values[1], list[i].values[2]);
        }
    }
}

int main() {
    Buffer buffer;
    char command[10];

    // 계속 입력 받기
    while (1) {
        printf("3개의 정수를 입력하거나 명령어를 입력하세요: ");

        // 숫자 입력 시도
        int result = scanf("%d %d %d", &buffer.values[0], &buffer.values[1], &buffer.values[2]);

        if (result == 3) {
            // 3개의 숫자를 모두 정상적으로 입력받은 경우
            add(buffer);
        }
        else {
            // 입력이 숫자가 아닌 경우 명령어로 처리
            scanf("%s", command);  // 남은 입력을 문자열로 받음
            switch (command[0]) {
            case 'd': // pop 명령어 (맨 아래 삭제)
                pop();
                break;
            case '-': // dequeue 명령어 (맨 위 삭제)
                dequeue();
                break;
            case 'c': // clear 명령어 (전체 삭제)
                clear();
                break;
            case 'l': // 리스트 출력 명령어
                display();
                break;
            case 'q': // 종료 명령어
                printf("프로그램을 종료합니다.\n");
                exit(0);
                break;
            default:
                printf("알 수 없는 명령어입니다.\n");
                break;
            }
        }

        // 버퍼 입력 중 개행 문자 제거
        while (getchar() != '\n');
    }

    return 0;
}
