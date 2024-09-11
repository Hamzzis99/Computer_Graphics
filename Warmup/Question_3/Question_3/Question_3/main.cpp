#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �� ���۸� ������ ����ü
typedef struct {
    int values[3];  // ���� 3���� ������ �迭
} Buffer;

#define MAX_BUFFERS 20 // �ִ� ���� ����

Buffer list[MAX_BUFFERS]; // ����ü �迭
int count = 0;            // ���� ������ �����ϴ� ���� ����

// ���ο� ���۸� �迭�� �߰��ϴ� �Լ�
void add(Buffer buffer) {
    if (count < MAX_BUFFERS) {
        list[count] = buffer; // ����ü ��ü�� �迭�� ����
        count++;
    }
    else {
        printf("����Ʈ�� ���� á���ϴ�.\n");
    }
}

// ������ ���۸� �����ϴ� �Լ� (pop)
void pop() {
    if (count > 0) {
        count--;
        printf("�� �Ʒ� �����Ͱ� �����Ǿ����ϴ�.\n");
    }
    else {
        printf("������ �����Ͱ� �����ϴ�.\n");
    }
}

// �� �� ���۸� �����ϴ� �Լ� (dequeue)
void dequeue() {
    if (count > 0) {
        for (int i = 1; i < count; i++) {
            list[i - 1] = list[i]; // ���� ���۸� ������ �̵�
        }
        count--;
        printf("�� �� �����Ͱ� �����Ǿ����ϴ�.\n");
    }
    else {
        printf("������ �����Ͱ� �����ϴ�.\n");
    }
}

// ����Ʈ ���� �����ϴ� �Լ�
void clear() {
    count = 0;
    printf("����Ʈ�� ��� �����Ǿ����ϴ�. ó������ ���ư��ϴ�.\n");
}

// ���� ����Ʈ�� ����ϴ� �Լ�
void display() {
    if (count == 0) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
    }
    else {
        printf("���� ����Ʈ ����:\n");
        for (int i = 0; i < count; i++) {
            printf("���� %d: (%d, %d, %d)\n", i + 1, list[i].values[0], list[i].values[1], list[i].values[2]);
        }
    }
}

int main() {
    Buffer buffer;
    char command[10];

    // ��� �Է� �ޱ�
    while (1) {
        printf("��ɾ �Է��Ͻÿ�.: ");

        // ��ɾ� �Ǵ� +�� �����ϴ��� Ȯ��
        scanf("%s", command);

        // ��ɾ� ó��
        switch (command[0]) {
        case '+': // + ��ɾ�, 3���� ���� �Է� ����
            if (scanf("%d %d %d", &buffer.values[0], &buffer.values[1], &buffer.values[2]) == 3) {
                add(buffer);  // ���� �߰�
            }
            else {
                printf("������ �߸� �Է��߽��ϴ�. �ٽ� �õ��ϼ���.\n");
            }
            break;
        case 'd': // pop ��ɾ� (�� �Ʒ� ����)
            pop();
            break;
        case '-': // dequeue ��ɾ� (�� �� ����)
            dequeue();
            break;
        case 'c': // clear ��ɾ� (��ü ����)
            clear();
            break;
        case 'l': // ����Ʈ ��� ��ɾ�
            display();
            break;
        case 'q': // ���� ��ɾ�
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
            break;
        default:
            printf("�� �� ���� ��ɾ��Դϴ�.\n");
            break;
        }

        // ���� �Է� �� ���� ���� ����
        while (getchar() != '\n');
    }

    return 0;
}
