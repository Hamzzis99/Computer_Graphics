#include "function.h"

#define MAX_FILE_SIZE 1048576 // 최대 파일 크기 (1MB)
#define MAX_LINE_LENGTH 1024  // 한 줄의 최대 길이

// 콘솔 텍스트 색상을 설정하는 함수
void set_text_color(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 콘솔 텍스트 색상을 기본값으로 재설정하는 함수
void reset_text_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 색상
}

// 단어를 검색하여 개수를 출력하는 함수
void search_word_in_file(const char* temp_filename, const char* search_word) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int total_count = 0;
    int search_word_len = strlen(search_word);

    while (fgets(line, sizeof(line), file) != NULL) {
        char* ptr = line;
        int i = 0;

        while (line[i] != '\0') {
            // 검색어와 일치하는지 확인
            if (strncmp(&line[i], search_word, search_word_len) == 0) {
                // 단어의 앞과 뒤가 단어 경계인지 확인
                int is_word = 1;

                // 단어의 앞이 라인의 시작이 아니고, 알파벳 또는 숫자라면 단어가 아님
                if (i > 0 && isalnum((unsigned char)line[i - 1])) {
                    is_word = 0;
                }

                // 단어의 뒤가 알파벳 또는 숫자라면 단어가 아님
                if (isalnum((unsigned char)line[i + search_word_len])) {
                    is_word = 0;
                }

                if (is_word) {
                    // 단어를 빨간색으로 출력
                    set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("%.*s", search_word_len, &line[i]);
                    reset_text_color();
                    total_count++;
                    i += search_word_len;
                    continue;
                }
            }
            // 일치하지 않으면 현재 문자 출력
            putchar(line[i]);
            i++;
        }
    }
    fclose(file);

    printf("Total : %d %s\n", total_count, search_word);
}

// 파일 내용 전체를 반전하는 함수
void reverse_content(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        return;
    }

    // 파일 내용을 메모리에 로드
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("메모리를 할당할 수 없습니다.\n");
        fclose(file);
        return;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);

    // 내용 반전
    for (long i = 0; i < file_size / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[file_size - 1 - i];
        buffer[file_size - 1 - i] = temp;
    }

    // tempfile.txt에 저장
    file = fopen(temp_filename, "w");
    if (file == NULL) {
        printf("임시 파일에 저장할 수 없습니다.\n");
        free(buffer);
        return;
    }
    fputs(buffer, file);
    fclose(file);

    // 결과 출력
    printf("%s\n", buffer);

    free(buffer);
}

// 3글자마다 '@@'를 삽입하는 함수
void insert_at_every_3_chars(const char* temp_filename) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
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

    // tempfile.txt를 업데이트
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);
}

// 단어를 거꾸로 변환하는 함수
void reverse_words_in_file(const char* temp_filename) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        if (file_read) fclose(file_read);
        if (file_write) fclose(file_write);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file_read) != NULL) {
        char new_line[MAX_LINE_LENGTH] = "";
        int index = 0; // line에서의 현재 위치
        int new_index = 0; // new_line에서의 현재 위치

        while (line[index] != '\0' && line[index] != '\n') {
            // 공백 또는 특수문자 처리
            if (line[index] == ' ' || line[index] == '\t') {
                new_line[new_index++] = line[index++];
            }
            else {
                // 단어 추출
                int word_start = index;
                while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n' && line[index] != '\0') {
                    index++;
                }
                int word_end = index;

                // 단어 거꾸로 복사
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

    // tempfile.txt를 업데이트
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);
}

// 각 줄의 단어 개수를 계산하고 출력하는 함수
void count_words_per_line(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        int word_count = 0;
        int in_word = 0;
        int len = strlen(line);

        // 단어 개수 계산
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

        // 줄의 끝에 개행 문자 제거
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // 결과 출력
        printf("%s (%d words)\n", line, word_count);
    }
    fclose(file);
}

// 특정 문자를 다른 문자로 치환하는 함수
void replace_char_in_file(const char* temp_filename, char old_char, char new_char) {
    FILE* file_read = fopen(temp_filename, "r");
    FILE* file_write = fopen("tempfile_tmp.txt", "w");
    if (file_read == NULL || file_write == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        if (file_read) fclose(file_read);
        if (file_write) fclose(file_write);
        return;
    }

    char ch;
    while ((ch = fgetc(file_read)) != EOF) {
        if (ch == old_char) {
            fputc(new_char, file_write);
            putchar(new_char); // 화면에 출력
        }
        else {
            fputc(ch, file_write);
            putchar(ch); // 화면에 출력
        }
    }
    fclose(file_read);
    fclose(file_write);

    // tempfile.txt를 업데이트
    remove(temp_filename);
    rename("tempfile_tmp.txt", temp_filename);

    printf("\n");
}

// 대문자로 시작하는 단어를 빨간색으로 표시하고 개수를 출력하는 함수
void find_capitalized_words(const char* temp_filename) {
    FILE* file = fopen(temp_filename, "r");
    if (file == NULL) {
        printf("임시 파일을 열 수 없습니다.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        int capitalized_word_count = 0;
        int len = strlen(line);

        // 줄의 끝에 개행 문자 제거
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
                // 단어의 첫 글자가 대문자인지 확인
                if (isupper((unsigned char)word[0])) {
                    set_text_color(FOREGROUND_RED | FOREGROUND_INTENSITY); // 빨간색
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
                    printf("%c", line[i]); // 공백 또는 탭 출력
                }
            }
            else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') {
                in_word = 1;
                word[word_index++] = line[i];
            }
            else {
                if (line[i] != '\0') {
                    printf("%c", line[i]); // 공백 또는 탭 출력
                }
            }
            i++;
        }
        printf(" (%d words)\n", capitalized_word_count);
    }
    fclose(file);
}
