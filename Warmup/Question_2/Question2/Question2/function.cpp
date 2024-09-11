#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

void test(char* str)
{
    int length = strlen(str);
    
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
    int new_length = length + (length / 3) * 2;  // 새로운 문자열의 길이 예측
    char* temp = (char*)malloc((new_length + 1) * sizeof(char));  // 동적 메모리 할당
    int new_len = 0;

    for (int i = 0; i < length; i++) {
        temp[new_len++] = str[i];

        if ((i + 1) % 3 == 0) {
            temp[new_len++] = '@';
            temp[new_len++] = '@';
        }
    }
    temp[new_len] = '\0';
    strcpy(str, temp);  // 원래 문자열에 덮어쓰기
    free(temp);  // 동적 메모리 해제
}



// 문자열을 거꾸로 뒤집는 함수
void reverse_voka(char* str) {
    int length = strlen(str);

    printf("아직 미구현 된 함수입니다.");
}

// 문자열을 거꾸로 뒤집는 함수
void checking_space(char* str) {
    int count = 0;
    int length = strlen(str);
    int in_word = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ' && !in_word) {
            count++;
            in_word = 1;
        }
        else if (str[i] == ' ') {
            in_word = 0;
        }
    }
    printf("%d words\n", count);  // 단어 개수 출력
    //printf("\n");
}

  /*  // 문자열을 한 글자씩 확인하며 공백(' ')을 찾음
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    printf("%d words\n", count);  // 공백 개수 출력*/

void set_text_color_red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// 콘솔 텍스트 색상을 기본값으로 복구하는 함수
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}