#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

void test(char* str)
{
    int length = strlen(str);
    
}

// ���ڿ��� �Ųٷ� ������ �Լ�
void reverse_string(char* str) {
    int length = strlen(str);

    //���ڿ��� �׳� �����������.
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    /*// ���ڿ��� �ڿ������� ���
    for (int i = length - 1; i >= 0; --i) {
        printf("%c", str[i]);
    }
    printf("\n");
*/
}

// 3���ڸ��� @@�� �����ϴ� �Լ�
void insert_chars(char* str) {
    int length = strlen(str);
    int new_length = length + (length / 3) * 2;  // ���ο� ���ڿ��� ���� ����
    char* temp = (char*)malloc((new_length + 1) * sizeof(char));  // ���� �޸� �Ҵ�
    int new_len = 0;

    for (int i = 0; i < length; i++) {
        temp[new_len++] = str[i];

        if ((i + 1) % 3 == 0) {
            temp[new_len++] = '@';
            temp[new_len++] = '@';
        }
    }
    temp[new_len] = '\0';
    strcpy(str, temp);  // ���� ���ڿ��� �����
    free(temp);  // ���� �޸� ����
}



// ���ڿ��� �Ųٷ� ������ �Լ�
void reverse_voka(char* str) {
    int length = strlen(str);

    printf("���� �̱��� �� �Լ��Դϴ�.");
}

// ���ڿ��� �Ųٷ� ������ �Լ�
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
    printf("%d words\n", count);  // �ܾ� ���� ���
    //printf("\n");
}

  /*  // ���ڿ��� �� ���ھ� Ȯ���ϸ� ����(' ')�� ã��
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    printf("%d words\n", count);  // ���� ���� ���*/

void set_text_color_red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// �ܼ� �ؽ�Ʈ ������ �⺻������ �����ϴ� �Լ�
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}