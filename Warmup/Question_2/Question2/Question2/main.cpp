#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];

    printf("input data file name: ");
    scanf("%s", filename);

    // 파일 포인터 선언
    FILE* file = fopen(filename, "r");

    // 파일 열기 오류 확인
    if (file == NULL) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return 1;
    }

    char buffer[512];

    // 파일 내용을 끝까지 읽기
    while (fgets(buffer, sizeof(buffer), file)) {
        // 파일에서 읽은 내용을 출력
        printf("%s", buffer);
    }

    // 파일 닫기
    fclose(file);

    return 0;
}
