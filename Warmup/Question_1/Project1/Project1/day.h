#pragma once
#ifndef CALC_H
#define CALC_H

void MultiArrays(int array[4][4], int array2[4][4]); // 곱셈 함수 선언
void AddArrays(int array[4][4], int array2[4][4]); // 덧셈 선언함수.
void MinusArrays(int array[4][4], int array2[4][4]); //뺼셈 선언함수.
void Determine(int array[4][4], int array2[4][4], int* count); //메뉴 e 판별기
void NewArray(int array[4][4], int array2[4][4]); // 메뉴 s
void NumMultiple(int array[4][4], int array2[4][4], int nummenu); // 1~9곱 테스트
void Determinant(int array[4][4], int array2[4][4]); // 행렬식의 값.
void Transposed(int array[4][4], int array2[4][4]); // 전치 행렬.
#endif