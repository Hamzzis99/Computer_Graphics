#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

// 콘솔 텍스트 색상을 빨간색으로 변경하는 함수
void set_text_color_red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// 콘솔 텍스트 색상을 기본값으로 복구하는 함수
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// 문자열을 거꾸로 뒤집는 함수
void reverse_string(char* str) {
    int length = strlen(str);

    //문자열을 그냥 뒤집어버리자.
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    /*// 문자열을 뒤에서부터 출력
    for (int i = length - 1; i >= 0; --i) {
        printf("%c", str[i]); 
    }
    printf("\n"); 
*/
}

// 3글자마다 @@를 삽입하는 함수
void insert_chars(char* str) {
    int length = strlen(str);
    char temp[1024];  // 임시 배열, 충분히 큰 크기로 설정
    int new_len = 0;  // 새로운 문자열 길이 추적

    // 3글자마다 @@를 삽입
    for (int i = 0; i < length; i++) {
        temp[new_len++] = str[i];  // 원래 문자 삽입

        if ((i + 1) % 3 == 0) {  // 3글자마다 @@ 삽입
            temp[new_len++] = '@';
            temp[new_len++] = '@';
        }
    }
    temp[new_len] = '\0';  // NULL 종료 추가
    strcpy(str, temp);  // 원래 문자열에 덮어쓰기
}


// 문자열을 거꾸로 뒤집는 함수
void reverse_voka(char* str) {
    int length = strlen(str);

    printf("아직 미구현 된 함수입니다.");
}

// 문자열을 거꾸로 뒤집는 함수
void checking_space(char* str) {
    int count = 1;
    int length = strlen(str);

    // 문자열을 한 글자씩 확인하며 공백(' ')을 찾음
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    printf("%d words\n", count);  // 공백 개수 출력
}


int main() {
    char filename[100];
    char buffer[512];
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

    // 파일 내용을 끝까지 읽기
    while (fgets(buffer, sizeof(buffer), file)) {
        // 파일에서 읽은 내용을 출력
        printf("%s ", buffer);
    }

    // 명령어 루프 시작
    while (1) {
        printf("\n");
        printf("input the command : ");
        getchar(); // 개행문자를 제거하기 위한 추가 코드
        scanf("%c", &command);

        switch (command) {
        case 'd':  //d : 문장을 거꾸로 출력
            reverse_string(buffer);  // 버퍼 내용을 뒤집음
            printf("%s\n", buffer);  // 뒤집은 내용을 출력

            rewind(file);  // 파일 포인터를 파일의 처음으로 이동
            fputs(buffer, file);
            break;

        case 'e':  //e : 3글자 뒤에 @ 2개를 삽입함.
            insert_chars(buffer);  // 특수 문자를 삽입
            printf("%s\n", buffer);  // 삽입된 내용을 출력

            rewind(file);  // 파일 포인터를 파일의 처음으로 이동
            fputs(buffer, file);  
            break;

        case 'f': //f : 공백 기준으로 단어들을 거꾸로 출력하기
            reverse_voka(buffer);
            break;

        case 'h': //h : 각 줄의 단어의 개수 출력
            printf("%s\n", buffer);
            checking_space(buffer);
            break;

        case 'r': // r : 단어 개수에 따라 오름차순, 내림차순 원래대로 순서를 바꿔 출력
            printf("미구현 된 함수입니다.");
            break;

        //GPT
        case 'c':  // c: 문장을 빨간색으로 출력
            set_text_color_red();  // 콘솔 텍스트 색상 빨간색으로 변경
            printf("%s\n", buffer);  // 버퍼 내용을 빨간색으로 출력
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
        fflush(file);  // 명령어 수행 후 변경 사항을 파일에 기록
    }

    return 0;
}