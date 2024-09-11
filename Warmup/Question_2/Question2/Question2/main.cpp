#include <stdio.h>
#include <string.h>
#include "question2.h"

void set_text_color_red();
void reset_text_color();

int main() {
    char filename[100];
    char buffer[4096];
    char command;

    printf("input data file name: ");
    scanf("%s", filename);

    // 파일 포인터 선언 (읽기/쓰기 모드)
    FILE* file = fopen(filename, "r+");

    // 파일 열기 오류 확인
    if (file == NULL) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return 1;
    }

    // 명령어 루프 시작
    while (1) {
        printf("\n");
        printf("input the command : ");
        getchar(); // 개행문자를 제거하기 위한 추가 코드
        scanf("%c", &command);

        switch (command) {
        case 'd':  //d : 문장을 거꾸로 출력
            rewind(file);  // 파일의 처음으로 이동
            while (fgets(buffer, sizeof(buffer), file)) {
                reverse_string(buffer);  // 버퍼 내용을 뒤집음
                printf("%s\n", buffer);  // 뒤집은 내용을 출력
            }
            break;

        case 'e':  //e : 3글자 뒤에 @ 2개를 삽입함.
            rewind(file);  // 파일의 처음으로 이동
            while (fgets(buffer, sizeof(buffer), file)) {
                insert_chars(buffer);  // 특수 문자를 삽입
                printf("%s\n", buffer);  // 삽입된 내용을 출력
            }
            break;

        case 'f':  //f : 공백 기준으로 단어들을 거꾸로 출력하기
            rewind(file);  // 파일의 처음으로 이동
            while (fgets(buffer, sizeof(buffer), file)) {
                reverse_voka(buffer);  // 공백 기준으로 단어 뒤집기
                printf("%s\n", buffer);
            }
            break;

        case 'h':  //h : 각 줄의 단어 개수 출력
            rewind(file);  // 파일의 처음으로 이동
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s\n", buffer);  // 각 줄 출력
                checking_space(buffer);  // 단어 개수 확인
            }
            break;

        case 'r':  // r : 단어 개수에 따라 정렬
            printf("미구현 된 함수입니다.");
            break;

        case 'c':  // c: 문장을 빨간색으로 출력
            set_text_color_red();  // 콘솔 텍스트 색상 빨간색으로 변경
            rewind(file);  // 파일의 처음으로 이동
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s", buffer);  // 버퍼 내용을 빨간색으로 출력
            }
            reset_text_color();  // 콘솔 텍스트 색상 복구
            break;

        case 'q':  // 'q' 명령어: 프로그램 종료
            printf("프로그램을 종료합니다.\n");
            fclose(file);  // 파일 닫기
            return 0;

        default:
            printf("유효하지 않은 명령어입니다. 'r' 또는 'q'를 입력하세요.\n");
        }

        // 명령어 수행 후 파일에 변경된 내용을 즉시 저장
        fflush(file);
    }

    return 0;
}
