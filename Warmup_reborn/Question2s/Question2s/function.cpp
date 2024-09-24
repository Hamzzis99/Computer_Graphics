#include "function.h"

#define MAX_FILE_SIZE 1048576 // �ִ� ���� ũ�� (1MB)
#define MAX_LINE_LENGTH 1024  // �� ���� �ִ� ����

// �ܼ� �ؽ�Ʈ ������ �����ϴ� �Լ�
void set_text_color(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// �ܼ� �ؽ�Ʈ ������ �⺻������ �缳���ϴ� �Լ�
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �⺻ ����
}

// �ܾ �˻��Ͽ� ������ ����ϴ� �Լ�
void search_word_in_file(const char* temp_filename, const char* search_word) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int total_count = 0;
    int search_word_len = strlen(search_word);

    while (fgets(line, sizeof(line), file) != NULL) {
        char* ptr = line;
        int i = 0;

        while (line[i] != '\0') {
            // �˻���� ��ġ�ϴ��� Ȯ��
            if (strncmp(&line[i], search_word, search_word_len) == 0) {
                // �ܾ��� �հ� �ڰ� �ܾ� ������� Ȯ��
                int is_word = 1;

                // �ܾ��� ���� ������ ������ �ƴϰ�, ���ĺ� �Ǵ� ���ڶ�� �ܾ �ƴ�
                if (i > 0 && isalnum((unsigned char)line[i - 1])) {
                    is_word = 0;
                }

                // �ܾ��� �ڰ� ���ĺ� �Ǵ� ���ڶ�� �ܾ �ƴ�
                if (isalnum((unsigned char)line[i + search_word_len])) {
                    is_word = 0;
                }

                if (is_word) {
                    // �ܾ ���������� ���
                    set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("%.*s", search_word_len, &line[i]);
                    reset_text_color();
                    total_count++;
                    i += search_word_len;
                    continue;
                }
            }
            // ��ġ���� ������ ���� ���� ���
            putchar(line[i]);
            i++;
        }
    }
    fclose(file);

    printf("Total : %d %s\n", total_count, search_word);
}

// ���� ���� ��ü�� �����ϴ� �Լ�
void reverse_content(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        return;
    }

    // ���� ������ �޸𸮿� �ε�
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.\n");
        fclose(file);
        return;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);

    // ���� ����
    for (long i = 0; i < file_size / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[file_size - 1 - i];
        buffer[file_size - 1 - i] = temp;
    }

    // tempfile.txt�� ����
    file = fopen(temp_filename, "w");
    if (file == NULL) {
        printf("�ӽ� ���Ͽ� ������ �� �����ϴ�.\n");
        free(buffer);
        return;
    }
    fputs(buffer, file);
    fclose(file);

    // ��� ���
    printf("%s\n", buffer);

    free(buffer);
}

// 3���ڸ��� '@@'�� �����ϴ� �Լ�
void insert_at_every_3_chars(const char* temp_filename) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        if (file_read) fclose(file_read);
        if (file_write) fclose(file_write);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file_read) != NULL) {
        int len = strlen(line);
        char new_line[MAX_LINE_LENGTH * 2] = "";
        int count = 0;
        int char_count = 0;
        for (int i = 0; i < len; i++) {
            new_line[count++] = line[i];
            if (line[i] != '\n' && line[i] != '\r') {
                char_count++;
                if (char_count % 3 == 0) {
                    new_line[count++] = '@';
                    new_line[count++] = '@';
                }
            }
        }
        new_line[count] = '\0';
        fputs(new_line, file_write);
        printf("%s", new_line);
    }
    fclose(file_read);
    fclose(file_write);

    // tempfile.txt�� ������Ʈ
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);
}

// �ܾ �Ųٷ� ��ȯ�ϴ� �Լ�
void reverse_words_in_file(const char* temp_filename) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        if (file_read) fclose(file_read);
        if (file_write) fclose(file_write);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file_read) != NULL) {
        char new_line[MAX_LINE_LENGTH] = "";
        int index = 0; // line������ ���� ��ġ
        int new_index = 0; // new_line������ ���� ��ġ

        while (line[index] != '\0' && line[index] != '\n') {
            // ���� �Ǵ� Ư������ ó��
            if (line[index] == ' ' || line[index] == '\t') {
                new_line[new_index++] = line[index++];
            }
            else {
                // �ܾ� ����
                int word_start = index;
                while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n' && line[index] != '\0') {
                    index++;
                }
                int word_end = index;

                // �ܾ� �Ųٷ� ����
                for (int i = word_end - 1; i >= word_start; i--) {
                    new_line[new_index++] = line[i];
                }
            }
        }
        if (line[index] == '\n') {
            new_line[new_index++] = '\n';
        }
        new_line[new_index] = '\0';

        fputs(new_line, file_write);
        printf("%s", new_line);
    }
    fclose(file_read);
    fclose(file_write);

    // tempfile.txt�� ������Ʈ
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);
}

// �� ���� �ܾ� ������ ����ϰ� ����ϴ� �Լ�
void count_words_per_line(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        int word_count = 0;
        int in_word = 0;
        int len = strlen(line);

        // �ܾ� ���� ���
        for (int i = 0; i < len; i++) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            }
            else {
                in_word = 1;
            }
        }
        if (in_word) {
            word_count++;
        }

        // ���� ���� ���� ���� ����
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // ��� ���
        printf("%s (%d words)\n", line, word_count);
    }
    fclose(file);
}

// Ư�� ���ڸ� �ٸ� ���ڷ� ġȯ�ϴ� �Լ�
void replace_char_in_file(const char* temp_filename, char old_char, char new_char) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        if (file_read) fclose(file_read);
        if (file_write) fclose(file_write);
        return;
    }

    char ch;
    while ((ch = fgetc(file_read)) != EOF) {
        if (ch == old_char) {
            fputc(new_char, file_write);
            putchar(new_char); // ȭ�鿡 ���
        }
        else {
            fputc(ch, file_write);
            putchar(ch); // ȭ�鿡 ���
        }
    }
    fclose(file_read);
    fclose(file_write);

    // tempfile.txt�� ������Ʈ
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);

    printf("\n");
}

// �빮�ڷ� �����ϴ� �ܾ ���������� ǥ���ϰ� ������ ����ϴ� �Լ�
void find_capitalized_words(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("�ӽ� ������ �� �� �����ϴ�.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        int capitalized_word_count = 0;
        int len = strlen(line);

        // ���� ���� ���� ���� ����
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        int i = 0;
        int in_word = 0;
        char word[MAX_LINE_LENGTH];
        int word_index = 0;

        while (i <= len) {
            if ((line[i] == ' ' || line[i] == '\t' || line[i] == '\0') && in_word) {
                word[word_index] = '\0';
                // �ܾ��� ù ���ڰ� �빮������ Ȯ��
                if (isupper((unsigned char)word[0])) {
                    set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY); // ������
                    printf("%s", word);
                    reset_text_color();
                    capitalized_word_count++;
                }
                else {
                    printf("%s", word);
                }
                in_word = 0;
                word_index = 0;
                if (line[i] != '\0') {
                    printf("%c", line[i]); // ���� �Ǵ� �� ���
                }
            }
            else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') {
                in_word = 1;
                word[word_index++] = line[i];
            }
            else {
                if (line[i] != '\0') {
                    printf("%c", line[i]); // ���� �Ǵ� �� ���
                }
            }
            i++;
        }
        printf(" (%d words)\n", capitalized_word_count);
    }
    fclose(file);
}
