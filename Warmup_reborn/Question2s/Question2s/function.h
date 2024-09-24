#pragma once

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define MAX_FILE_SIZE 1048576 // 최대 파일 크기 (1MB)
#define MAX_LINE_LENGTH 1024  // 한 줄의 최대 길이


void reverse_content(const char* temp_filename);
void show_content(const char* temp_filename);
void insert_at_every_3_chars(const char* temp_filename);
void reverse_words_in_file(const char* temp_filename);
void count_words_per_line(const char* temp_filename);
void replace_char_in_file(const char* temp_filename, char old_char, char new_char);
void find_capitalized_words(const char* temp_filename);
void set_text_color(WORD color);
void reset_text_color();
void search_word_in_file(const char* temp_filename, const char* search_word);

#endif