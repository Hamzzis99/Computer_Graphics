#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

// �ܼ� �ؽ�Ʈ ������ ���������� �����ϴ� �Լ�
void set_text_color_red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// �ܼ� �ؽ�Ʈ ������ �⺻������ �����ϴ� �Լ�
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
    char temp[1024];  // �ӽ� �迭, ����� ū ũ��� ����
    int new_len = 0;  // ���ο� ���ڿ� ���� ����

    // 3���ڸ��� @@�� ����
    for (int i = 0; i < length; i++) {
        temp[new_len++] = str[i];  // ���� ���� ����

        if ((i + 1) % 3 == 0) {  // 3���ڸ��� @@ ����
            temp[new_len++] = '@';
            temp[new_len++] = '@';
        }
    }
    temp[new_len] = '\0';  // NULL ���� �߰�
    strcpy(str, temp);  // ���� ���ڿ��� �����
}


// ���ڿ��� �Ųٷ� ������ �Լ�
void reverse_voka(char* str) {
    int length = strlen(str);

    printf("���� �̱��� �� �Լ��Դϴ�.");
}

// ���ڿ��� �Ųٷ� ������ �Լ�
void checking_space(char* str) {
    int count = 1;
    int length = strlen(str);

    // ���ڿ��� �� ���ھ� Ȯ���ϸ� ����(' ')�� ã��
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    printf("%d words\n", count);  // ���� ���� ���
}


int main() {
    char filename[100];
    char buffer[512];
    char command;

    printf("input data file name: ");
    scanf("%s", filename);

    // ���� ������ ���� (�б�/���� ���)
    FILE* file = fopen(filename, "r+");

    // ���� ���� ���� Ȯ��
    if (file == NULL) {
        printf("������ �� �� �����ϴ�: %s\n", filename);
        return 1;
    }

    // ���� ������ ������ �б�
    while (fgets(buffer, sizeof(buffer), file)) {
        // ���Ͽ��� ���� ������ ���
        printf("%s ", buffer);
    }

    // ��ɾ� ���� ����
    while (1) {
        printf("\n");
        printf("input the command : ");
        getchar(); // ���๮�ڸ� �����ϱ� ���� �߰� �ڵ�
        scanf("%c", &command);

        switch (command) {
        case 'd':  //d : ������ �Ųٷ� ���
            reverse_string(buffer);  // ���� ������ ������
            printf("%s\n", buffer);  // ������ ������ ���

            rewind(file);  // ���� �����͸� ������ ó������ �̵�
            fputs(buffer, file);
            break;

        case 'e':  //e : 3���� �ڿ� @ 2���� ������.
            insert_chars(buffer);  // Ư�� ���ڸ� ����
            printf("%s\n", buffer);  // ���Ե� ������ ���

            rewind(file);  // ���� �����͸� ������ ó������ �̵�
            fputs(buffer, file);  
            break;

        case 'f': //f : ���� �������� �ܾ���� �Ųٷ� ����ϱ�
            reverse_voka(buffer);
            break;

        case 'h': //h : �� ���� �ܾ��� ���� ���
            printf("%s\n", buffer);
            checking_space(buffer);
            break;

        case 'r': // r : �ܾ� ������ ���� ��������, �������� ������� ������ �ٲ� ���
            printf("�̱��� �� �Լ��Դϴ�.");
            break;

        //GPT
        case 'c':  // c: ������ ���������� ���
            set_text_color_red();  // �ܼ� �ؽ�Ʈ ���� ���������� ����
            printf("%s\n", buffer);  // ���� ������ ���������� ���
            reset_text_color();  // �ܼ� �ؽ�Ʈ ���� ����
            break;

        case 'q':  // 'q' ��ɾ�: ���α׷� ����
            printf("���α׷��� �����մϴ�.\n");
            fclose(file);  // ���� �ݱ�
            return 0;


        default:
            printf("��ȿ���� ���� ��ɾ��Դϴ�. 'r' �Ǵ� 'q'�� �Է��ϼ���.\n");
        }

        // ��ɾ� ���� �� ���Ͽ� ����� ������ ��� ����
        fflush(file);  // ��ɾ� ���� �� ���� ������ ���Ͽ� ���
    }

    return 0;
}