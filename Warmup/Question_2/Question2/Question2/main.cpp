#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];

    printf("input data file name: ");
    scanf("%s", filename);

    // ���� ������ ����
    FILE* file = fopen(filename, "r");

    // ���� ���� ���� Ȯ��
    if (file == NULL) {
        printf("������ �� �� �����ϴ�: %s\n", filename);
        return 1;
    }

    char buffer[512];

    // ���� ������ ������ �б�
    while (fgets(buffer, sizeof(buffer), file)) {
        // ���Ͽ��� ���� ������ ���
        printf("%s", buffer);
    }

    // ���� �ݱ�
    fclose(file);

    return 0;
}
