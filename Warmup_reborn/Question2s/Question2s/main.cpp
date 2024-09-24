#include "function.h"

int main() {
    char filename[256];
    char command[256];
    char temp_filename[] = "tempfile.txt";
    FILE* file, * temp_file;

    // 파일 이름 입력 받기
    printf("Input Filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // 원본 파일 열기
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return 1;
    }

    // tempfile.txt에 원본 내용을 복사
    temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        printf("임시 파일을 생성할 수 없습니다.\n");
        fclose(file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        fputs(line, temp_file);
    }
    fclose(file);
    fclose(temp_file);

    // 명령어 입력 루프
    while (1) {
        printf("명령어를 입력하세요 (종료하려면 'q' 입력): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // 종료 명령어 처리
        if (strcmp(command, "q") == 0) {
            remove(temp_filename);
            return 0;
        }

        // 명령어에 따라 함수 호출
        if (strncmp(command, "s ", 2) == 0) {
            // 's' 명령어 처리: s search_word
            if (strlen(command) >= 3) {
                char search_word[MAX_LINE_LENGTH];
                strcpy(search_word, command + 2);
                search_word_in_file(temp_filename, search_word);
            }
            else {
                printf("사용법: s 단어\n");
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
            // 'g' 명령어 처리: g old_char new_char
            if (strlen(command) >= 4) {
                char old_char = command[2];
                char new_char = command[4];
                replace_char_in_file(temp_filename, old_char, new_char);
            }
            else {
                printf("사용법: g old_char new_char\n");
            }
        }
        else if (strcmp(command, "c") == 0) {
            find_capitalized_words(temp_filename);
        }
        else {
            printf("알 수 없는 명령어입니다.\n");
        }
    }

    return 0;
}