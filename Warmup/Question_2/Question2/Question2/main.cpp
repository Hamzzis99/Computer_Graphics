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

    // ���� ������ ���� (�б�/���� ���)
    FILE* file = fopen(filename, "r+");

    // ���� ���� ���� Ȯ��
    if (file == NULL) {
        printf("������ �� �� �����ϴ�: %s\n", filename);
        return 1;
    }

    // ��ɾ� ���� ����
    while (1) {
        printf("\n");
        printf("input the command : ");
        getchar(); // ���๮�ڸ� �����ϱ� ���� �߰� �ڵ�
        scanf("%c", &command);

        switch (command) {
        case 'd':  //d : ������ �Ųٷ� ���
            rewind(file);  // ������ ó������ �̵�
            while (fgets(buffer, sizeof(buffer), file)) {
                reverse_string(buffer);  // ���� ������ ������
                printf("%s\n", buffer);  // ������ ������ ���
            }
            break;

        case 'e':  //e : 3���� �ڿ� @ 2���� ������.
            rewind(file);  // ������ ó������ �̵�
            while (fgets(buffer, sizeof(buffer), file)) {
                insert_chars(buffer);  // Ư�� ���ڸ� ����
                printf("%s\n", buffer);  // ���Ե� ������ ���
            }
            break;

        case 'f':  //f : ���� �������� �ܾ���� �Ųٷ� ����ϱ�
            rewind(file);  // ������ ó������ �̵�
            while (fgets(buffer, sizeof(buffer), file)) {
                reverse_voka(buffer);  // ���� �������� �ܾ� ������
                printf("%s\n", buffer);
            }
            break;

        case 'h':  //h : �� ���� �ܾ� ���� ���
            rewind(file);  // ������ ó������ �̵�
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s\n", buffer);  // �� �� ���
                checking_space(buffer);  // �ܾ� ���� Ȯ��
            }
            break;

        case 'r':  // r : �ܾ� ������ ���� ����
            printf("�̱��� �� �Լ��Դϴ�.");
            break;

        case 'c':  // c: ������ ���������� ���
            set_text_color_red();  // �ܼ� �ؽ�Ʈ ���� ���������� ����
            rewind(file);  // ������ ó������ �̵�
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s", buffer);  // ���� ������ ���������� ���
            }
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
        fflush(file);
    }

    return 0;
}
