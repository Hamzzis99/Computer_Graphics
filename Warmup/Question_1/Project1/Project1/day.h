#pragma once
#ifndef CALC_H
#define CALC_H

void MultiArrays(int array[4][4], int array2[4][4]); // ���� �Լ� ����
void AddArrays(int array[4][4], int array2[4][4]); // ���� �����Լ�.
void MinusArrays(int array[4][4], int array2[4][4]); //�E�� �����Լ�.
void Determine(int array[4][4], int array2[4][4], int* count); //�޴� e �Ǻ���
void NewArray(int array[4][4], int array2[4][4]); // �޴� s
void NumMultiple(int array[4][4], int array2[4][4], int nummenu); // 1~9�� �׽�Ʈ
void Determinant(int array[4][4], int array2[4][4]); // ��Ľ��� ��.
void Transposed(int array[4][4], int array2[4][4]); // ��ġ ���.
#endif