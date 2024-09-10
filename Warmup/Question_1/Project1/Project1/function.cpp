#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// 행렬 곱셈을 계산하고 출력해주는 함수
void MultiArrays(int array[4][4], int array2[4][4])
{
	int sum[4][4];

	// 곱셈 계산 (행렬의 각 행과 열을 곱한 후 합산)
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = 0; // 초기값 설정
			for (int k = 0; k < 4; k++)
			{
				sum[a][i] += array[a][k] * array2[k][i];
			}
		}
	}

	// 곱셈 배열 출력
	printf("곱셈 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);
		}
		printf("\n");
	}
	printf("\n");
}


//덧셈한 것을 계산하고 출력해주는 함수.
void AddArrays(int array[4][4], int array2[4][4]) //메뉴 a
{
	int sum[4][4];

	//덧셈한 것을 계산하는 함수.
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = array[a][i] + array2[a][i];
		}
	}

	//덧셈한 것을 출력하기.
	printf("덧셈 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);  // 숫자를 네 개 출력하고...
		}
		printf("\n");  // 한 행이 끝날 때 줄 바꿈
	}

	printf("\n"); // 마무리
}

void MinusArrays(int array[4][4], int array2[4][4]) //메뉴 d
{
	int sum[4][4];

	//덧셈한 것을 계산하는 함수.
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = array[a][i] - array2[a][i];
		}
	}

	//덧셈한 것을 출력하기.
	printf("뺄셈 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);  // 숫자를 네 개 출력하고...
		}
		printf("\n");  // 한 행이 끝날 때 줄 바꿈
	}

	printf("\n"); // 마무리
}

void Determine(int array[4][4], int array2[4][4], int* count) //메뉴 e 판별기
{
	if (*count == 0) // 홀수출력
	{
		printf("\n행렬의 짝수만 출력: \n");
		printf("\n");

		printf("첫번째 행렬의 짝수: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (array[i][j] % 2 == 0)
				{
					printf("%d ", array[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("두번째 행렬의 짝수: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (array2[i][j] % 2 == 0)
				{
					printf("%d ", array2[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
	}

	else if (*count == 1)
	{
		printf("\n행렬의 홀수만 출력: \n");
		printf("\n");

		printf("첫번째 행렬의 홀수: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (array[i][j] % 2 == 1)
				{
					printf("%d ", array[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("두번째 행렬의 홀수: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (array2[i][j] % 2 == 1)
				{
					printf("%d ", array2[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
	}
	else if (*count == 2) {
		printf("\n원래 행렬 출력:\n");
		printf("\n");

		printf("첫번째 원본 행렬 출력\n");
		for (int a = 0; a < 4; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", array[a][i]);
			}
			printf("\n");
		}

		printf("두번째 원본 행렬 출력\n");
		for (int a = 0; a < 4; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", array2[a][i]);
			}
			printf("\n");
		}
	}
	*count = (*count + 1) % 3;
}

void NewArray(int array[4][4], int array2[4][4]) // 메뉴 s
{
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			array[a][i] = rand() % 3;
			array2[a][i] = rand() % 3;
		}
	}

	// 첫 번째 2차원 배열 출력
	printf("첫번째 2차원 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array[a][i]);
		}
		printf("\n");
	}

	// 두 번째 2차원 배열 출력
	printf("\n두번째 2차원 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array2[a][i]);
		}
		printf("\n");
	}

	printf("\n"); // 마무리
}

void NumMultiple(int array[4][4], int array2[4][4], int nummenu) // 1~9곱 테스트
{
	int sum[4][4];
	int sum2[4][4];

	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			sum[a][i] = array[a][i] * nummenu;
		}
	}

	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			sum2[a][i] = array2[a][i] * nummenu;
		}
	}

	printf("\n");
	printf("첫 번째 행렬에 %d를 곱한 결과:\n", nummenu);
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);
		}
		printf("\n"); // 한 행이 끝날 때 줄바꿈
	}

	printf("\n");
	printf("두 번째 행렬에 %d를 곱한 결과:\n", nummenu);
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum2[a][i]);
		}
		printf("\n"); // 한 행이 끝날 때 줄바꿈
	}
}

void Determinant(int array[4][4], int array2[4][4])
{
	printf("행렬식의 값은 아직 구현하지 못한 함수기능입니다...\n");
}

void Transposed(int array[4][4], int array2[4][4])
{
	printf("전치 행렬은 아직 구현하지 못한 함수기능입니다...\n");
}