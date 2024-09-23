#include "function.h"

int main() {
    char filename[256];
    char command[256];
    char temp_filename[] = "tempfile.txt";
    FILE* file, * temp_file;

    // ���� �̸� �Է� �ޱ�
    printf("Input Filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // ���� ���� ����
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("%s ������ �� �� �����ϴ�.\n", filename);
        return 1;
    }

    // tempfile.txt�� ���� ������ ����
    temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        printf("�ӽ� ������ ������ �� �����ϴ�.\n");
        fclose(file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        fputs(line, temp_file);
    }
    fclose(file);
    fclose(temp_file);

    // ��ɾ� �Է� ����
    while (1) {
        printf("��ɾ �Է��ϼ��� (�����Ϸ��� 'q' �Է�): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // ���� ��ɾ� ó��
        if (strcmp(command, "q") == 0) {
            remove(temp_filename);
            return 0;
        }

        // ��ɾ ���� �Լ� ȣ��
        if (strncmp(command, "s ", 2) == 0) {
            // 's' ��ɾ� ó��: s search_word
            if (strlen(command) >= 3) {
                char search_word[MAX_LINE_LENGTH];
                strcpy(search_word, command + 2);
                search_word_in_file(temp_filename, search_word);
            }
            else {
                printf("����: s �ܾ�\n");
            }
        }
        else if (strcmp(command, "d") == 0) {
            reverse_content(temp_filename);
        }
        else if (strcmp(command, "e") == 0) {
            insert_at_every_3_chars(temp_filename);
        }
        else if (strcmp(command, "f") == 0) {
            reverse_words_in_file(temp_filename);
        }
        else if (strcmp(command, "h") == 0) {
            count_words_per_line(temp_filename);
        }
        else if (strncmp(command, "g ", 2) == 0) {
            // 'g' ��ɾ� ó��: g old_char new_char
            if (strlen(command) >= 4) {
                char old_char = command[2];
                char new_char = command[4];
                replace_char_in_file(temp_filename, old_char, new_char);
            }
            else {
                printf("����: g old_char new_char\n");
            }
        }
        else if (strcmp(command, "c") == 0) {
            find_capitalized_words(temp_filename);
        }
        else {
            printf("�� �� ���� ��ɾ��Դϴ�.\n");
        }
    }

    return 0;
}